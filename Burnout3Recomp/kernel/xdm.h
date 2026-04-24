#pragma once

#include <cstdint>
#include <atomic>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>
#include "memory.h"
#include "heap.h"

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#endif

// ---------------------------------------------------------------------------
// OG Xbox dispatcher header types (little-endian, unlike Xbox 360).
// ---------------------------------------------------------------------------

// Object type codes matching the OG Xbox kernel.
enum : uint8_t
{
    XBOX_EVENT_NOTIFICATION = 0, // Manual-reset event
    XBOX_EVENT_SYNCHRONIZATION = 1, // Auto-reset event
    XBOX_MUTANT_OBJECT = 2,
    XBOX_SEMAPHORE_OBJECT = 5,
    XBOX_TIMER_OBJECT = 8,
    XBOX_THREAD_OBJECT = 6,
};

// Sentinel value written into the guest DISPATCHER_HEADER to mark that
// a host-side kernel object has already been lazily created for it.
static constexpr uint32_t OBJECT_SIGNATURE = 0x4F424A53; // 'OBJS'

// ---------------------------------------------------------------------------
// Kernel object base class
// ---------------------------------------------------------------------------

struct KernelObject
{
    virtual ~KernelObject() = default;
    virtual bool Wait(uint32_t timeoutMs) = 0;

#ifdef _WIN32
    // Return native HANDLE for WaitForMultipleObjects support.
    // Not all objects support this — default returns INVALID_HANDLE_VALUE.
    virtual HANDLE GetNativeHandle() { return INVALID_HANDLE_VALUE; }
#endif
};

// ---------------------------------------------------------------------------
// HostObject<T> bridge template
// ---------------------------------------------------------------------------
// Associates a host-side KernelObject derivative with a guest struct type.
// The guest_type typedef lets QueryKernelObject<T> know which guest layout
// to read the Type field from.

template <typename TGuest>
struct HostObject
{
    typedef TGuest guest_type;
};

// ---------------------------------------------------------------------------
// Guest dispatcher header (first 16 bytes of any waitable OG Xbox object).
// ---------------------------------------------------------------------------

struct XDISPATCHER_HEADER
{
    uint8_t Type;
    uint8_t Absolute;
    uint8_t Size;
    uint8_t Inserted;
    int32_t SignalState;
    // WaitListHead (LIST_ENTRY = 2 x uint32_t pointers)
    uint32_t WaitFlink; // reused as OBJECT_SIGNATURE when cached
    uint32_t WaitBlink; // reused as host object index
};

// Minimal guest struct wrappers (only Header matters for QueryKernelObject).
struct XKEVENT { XDISPATCHER_HEADER Header; };
struct XKSEMAPHORE { XDISPATCHER_HEADER Header; int32_t Limit; };
struct XKMUTANT { XDISPATCHER_HEADER Header; };

// ---------------------------------------------------------------------------
// Concrete kernel object types — backed by real OS primitives
// ---------------------------------------------------------------------------

#ifdef _WIN32

struct Event final : KernelObject, HostObject<XKEVENT>
{
    HANDLE hEvent;

    Event(bool manualReset, bool initialState)
    {
        hEvent = CreateEventW(nullptr, manualReset ? TRUE : FALSE,
                              initialState ? TRUE : FALSE, nullptr);
    }

    ~Event() override
    {
        if (hEvent) CloseHandle(hEvent);
    }

    void Set()   { SetEvent(hEvent); }
    void Reset() { ResetEvent(hEvent); }
    void Pulse() { PulseEvent(hEvent); }

    bool Wait(uint32_t timeoutMs) override
    {
        DWORD ms = (timeoutMs == UINT32_MAX) ? INFINITE : static_cast<DWORD>(timeoutMs);
        return WaitForSingleObject(hEvent, ms) == WAIT_OBJECT_0;
    }

    HANDLE GetNativeHandle() override { return hEvent; }
};

struct Semaphore final : KernelObject, HostObject<XKSEMAPHORE>
{
    HANDLE   hSemaphore;
    // Recursive-mutex support for single-threaded recompiler:
    // On the original Xbox, the RWA audio stream cache used a semaphore
    // as a mutex between the EE and IOP (separate processors). In our
    // single-threaded emulator these contexts share one host thread, so
    // an INFINITE wait re-entered by the same thread would deadlock.
    // Allow same-thread re-acquisition of INFINITE waits to mirror the
    // hardware's cross-processor semantics.
    DWORD    ownerThreadId_{0};
    uint32_t recursiveDepth_{0};

    Semaphore(uint32_t initialCount, uint32_t maximumCount)
    {
        hSemaphore = CreateSemaphoreW(nullptr,
                                      static_cast<LONG>(initialCount),
                                      static_cast<LONG>(maximumCount),
                                      nullptr);
        ownerThreadId_ = 0;
        recursiveDepth_ = 0;
    }

    ~Semaphore() override
    {
        if (hSemaphore) CloseHandle(hSemaphore);
    }

    int32_t Release(uint32_t releaseCount)
    {
        DWORD tid = GetCurrentThreadId();
        if (ownerThreadId_ == tid && recursiveDepth_ > 0)
        {
            // Recursive release from the same thread: decrement depth.
            // Only release to the OS when depth reaches zero.
            int32_t prev = static_cast<int32_t>(recursiveDepth_) - 1;
            if (recursiveDepth_ > releaseCount)
            {
                recursiveDepth_ -= releaseCount;
            }
            else
            {
                recursiveDepth_ = 0;
                ownerThreadId_  = 0;
                LONG prevOS = 0;
                ReleaseSemaphore(hSemaphore, 1, &prevOS);
            }
            return prev;
        }
        LONG prev = 0;
        ReleaseSemaphore(hSemaphore, static_cast<LONG>(releaseCount), &prev);
        return static_cast<int32_t>(prev);
    }

    bool Wait(uint32_t timeoutMs) override
    {
        DWORD tid = GetCurrentThreadId();
        // Only apply recursive fast-path for INFINITE waits: a timed (or
        // zero-timeout) wait is a true poll and must hit the OS counter.
        if (timeoutMs == UINT32_MAX && ownerThreadId_ == tid && recursiveDepth_ > 0)
        {
            ++recursiveDepth_;
            return true;
        }
        DWORD ms = (timeoutMs == UINT32_MAX) ? INFINITE : static_cast<DWORD>(timeoutMs);
        bool ok = WaitForSingleObject(hSemaphore, ms) == WAIT_OBJECT_0;
        if (ok)
        {
            ownerThreadId_  = tid;
            recursiveDepth_ = 1;
        }
        return ok;
    }

    HANDLE GetNativeHandle() override { return hSemaphore; }
};

struct Mutex final : KernelObject, HostObject<XKMUTANT>
{
    // Lightweight recursive lock — no kernel syscall.
    // The guest critical sections are uncontended (single game thread),
    // so a simple counter is sufficient and avoids ~184 Win32 mutex
    // syscalls per frame.
    std::thread::id owner{};
    uint32_t recursionCount = 0;

    Mutex() = default;
    ~Mutex() override = default;

    void Lock()
    {
        auto self = std::this_thread::get_id();
        if (owner == self) {
            ++recursionCount;
            return;
        }
        // No contention expected — just take ownership.
        owner = self;
        recursionCount = 1;
    }

    void Unlock()
    {
        if (--recursionCount == 0)
            owner = std::thread::id{};
    }

    bool Wait(uint32_t timeoutMs) override
    {
        Lock();
        return true;
    }

    HANDLE GetNativeHandle() override { return nullptr; }
};

#else
// POSIX fallback using std primitives (kept for cross-platform builds).

struct Event final : KernelObject, HostObject<XKEVENT>
{
    std::mutex mtx;
    std::condition_variable cv;
    bool signaled;
    bool manualReset;

    Event(bool manual, bool initial)
        : signaled(initial), manualReset(manual) {}

    void Set()
    {
        {
            std::lock_guard<std::mutex> lk(mtx);
            signaled = true;
        }
        if (manualReset)
            cv.notify_all();
        else
            cv.notify_one();
    }

    void Reset()
    {
        std::lock_guard<std::mutex> lk(mtx);
        signaled = false;
    }

    void Pulse()
    {
        {
            std::lock_guard<std::mutex> lk(mtx);
            signaled = true;
        }
        cv.notify_all();
        {
            std::lock_guard<std::mutex> lk(mtx);
            signaled = false;
        }
    }

    bool Wait(uint32_t timeoutMs) override
    {
        std::unique_lock<std::mutex> lk(mtx);
        if (timeoutMs == UINT32_MAX)
        {
            cv.wait(lk, [&] { return signaled; });
        }
        else
        {
            if (!cv.wait_for(lk, std::chrono::milliseconds(timeoutMs),
                             [&] { return signaled; }))
                return false;
        }
        if (!manualReset)
            signaled = false;
        return true;
    }
};

struct Semaphore final : KernelObject, HostObject<XKSEMAPHORE>
{
    std::mutex mtx;
    std::condition_variable cv;
    uint32_t count;
    uint32_t maximumCount;
    // Recursive-mutex support (mirrors Win32 path behaviour).
    std::thread::id ownerThreadId_{};
    uint32_t        recursiveDepth_{0};

    Semaphore(uint32_t initial, uint32_t maximum)
        : count(initial), maximumCount(maximum) {}

    int32_t Release(uint32_t releaseCount)
    {
        auto tid = std::this_thread::get_id();
        if (ownerThreadId_ == tid && recursiveDepth_ > 0)
        {
            int32_t prev = static_cast<int32_t>(recursiveDepth_) - 1;
            if (recursiveDepth_ > releaseCount)
            {
                recursiveDepth_ -= releaseCount;
            }
            else
            {
                recursiveDepth_ = 0;
                ownerThreadId_  = std::thread::id{};
                std::lock_guard<std::mutex> lk(mtx);
                if (count < maximumCount) { ++count; cv.notify_one(); }
            }
            return prev;
        }
        std::lock_guard<std::mutex> lk(mtx);
        int32_t prev = static_cast<int32_t>(count);
        count += releaseCount;
        if (count > maximumCount) count = maximumCount;
        cv.notify_all();
        return prev;
    }

    bool Wait(uint32_t timeoutMs) override
    {
        auto tid = std::this_thread::get_id();
        if (timeoutMs == UINT32_MAX && ownerThreadId_ == tid && recursiveDepth_ > 0)
        {
            ++recursiveDepth_;
            return true;
        }
        std::unique_lock<std::mutex> lk(mtx);
        if (timeoutMs == UINT32_MAX)
        {
            cv.wait(lk, [&] { return count > 0; });
        }
        else
        {
            if (!cv.wait_for(lk, std::chrono::milliseconds(timeoutMs),
                             [&] { return count > 0; }))
                return false;
        }
        --count;
        ownerThreadId_  = tid;
        recursiveDepth_ = 1;
        return true;
    }
};

struct Mutex final : KernelObject, HostObject<XKMUTANT>
{
    std::recursive_mutex mtx;

    void Lock() { mtx.lock(); }
    void Unlock() { mtx.unlock(); }

    bool Wait(uint32_t timeoutMs) override
    {
        if (timeoutMs == 0)
            return mtx.try_lock();
        mtx.lock();
        return true;
    }
};

#endif // _WIN32

// ---------------------------------------------------------------------------
// Global kernel object registry
// ---------------------------------------------------------------------------
// Objects are allocated on the host heap and tracked by a global index.
// The guest DISPATCHER_HEADER's WaitFlink/WaitBlink are used to cache the
// mapping (OBJECT_SIGNATURE marks a cached entry, WaitBlink = object index).
//
// Handle-based objects (NtCreate*) get a guest address as the handle value.
// Inline objects (KeWaitForSingleObject on a stack/global KEVENT) use
// QueryKernelObject for lazy init via OBJECT_SIGNATURE.

inline std::mutex g_kernelLock;
inline std::vector<KernelObject*> g_kernelObjects;

// Allocate a new host object and return its index.
template <typename T, typename... Args>
uint32_t CreateKernelObject(Args&&... args)
{
    std::lock_guard<std::mutex> lock(g_kernelLock);
    uint32_t idx = static_cast<uint32_t>(g_kernelObjects.size());
    g_kernelObjects.push_back(new T(std::forward<Args>(args)...));
    return idx;
}

// Retrieve host object by index.
// Objects are append-only (never removed or reordered), so an index that
// was valid at creation time stays valid forever.  Skip the mutex on the
// fast path to avoid a kernel syscall on every critical-section call.
inline KernelObject* GetKernelObject(uint32_t idx)
{
    // Fast path: the vector only grows, so a previously-valid index is
    // safe to read without the lock (no realloc races on existing slots
    // because push_back doesn't invalidate element addresses once we
    // reserve enough capacity, and we only read here).
    auto& vec = g_kernelObjects;
    if (idx < vec.size())
        return vec[idx];
    return nullptr;
}

// Handle-based: NtCreate* returns a "handle" which is the object index + 1
// (reserve 0 as invalid).
template <typename T, typename... Args>
uint32_t CreateKernelHandle(Args&&... args)
{
    return CreateKernelObject<T>(std::forward<Args>(args)...) + 1;
}

inline KernelObject* GetKernelObjectByHandle(uint32_t handle)
{
    if (handle == 0) return nullptr;
    return GetKernelObject(handle - 1);
}

// ---------------------------------------------------------------------------
// QueryKernelObject: lazy-init for inline dispatcher objects (KEVENT etc.)
// living inside guest memory. Uses the OBJECT_SIGNATURE caching pattern.
// ---------------------------------------------------------------------------

template <typename T, typename... Args>
T* QueryKernelObject(uint8_t* base, uint32_t guestAddr, Args&&... args)
{
    // Read the dispatcher header from guest memory.
    uint32_t sigWord = X86_MEM_READ_u32(base, guestAddr + offsetof(XDISPATCHER_HEADER, WaitFlink));

    if (sigWord == OBJECT_SIGNATURE)
    {
        // Already cached -- read index from WaitBlink.
        uint32_t idx = X86_MEM_READ_u32(base, guestAddr + offsetof(XDISPATCHER_HEADER, WaitBlink));
        return static_cast<T*>(GetKernelObject(idx));
    }

    // First time: create the host object and cache the index.
    uint32_t idx = CreateKernelObject<T>(std::forward<Args>(args)...);
    X86_MEM_WRITE_u32(base, guestAddr + offsetof(XDISPATCHER_HEADER, WaitFlink), OBJECT_SIGNATURE);
    X86_MEM_WRITE_u32(base, guestAddr + offsetof(XDISPATCHER_HEADER, WaitBlink), idx);

    return static_cast<T*>(GetKernelObject(idx));
}

// ---------------------------------------------------------------------------
// WaitForObject: dispatch wait on a guest dispatcher object by reading its
// Type byte and delegating to the appropriate host object.
// ---------------------------------------------------------------------------

inline KernelObject* ResolveDispatcherObject(uint8_t* base, uint32_t objAddr)
{
    uint8_t type = X86_MEM_READ_u8(base, objAddr);
    int32_t signalState = static_cast<int32_t>(X86_MEM_READ_u32(base, objAddr + 4));

    switch (type)
    {
    case XBOX_EVENT_NOTIFICATION:
        return QueryKernelObject<Event>(base, objAddr, /*manual=*/true, /*initial=*/signalState > 0);
    case XBOX_EVENT_SYNCHRONIZATION:
        return QueryKernelObject<Event>(base, objAddr, /*manual=*/false, /*initial=*/signalState > 0);
    case XBOX_SEMAPHORE_OBJECT:
        return QueryKernelObject<Semaphore>(base, objAddr, /*initial=*/static_cast<uint32_t>(signalState > 0 ? signalState : 0), /*max=*/1000u);
    case XBOX_MUTANT_OBJECT:
        return QueryKernelObject<Mutex>(base, objAddr);
    default:
        // For unknown types, create a dummy event that's always signaled.
        return QueryKernelObject<Event>(base, objAddr, /*manual=*/true, /*initial=*/true);
    }
}
