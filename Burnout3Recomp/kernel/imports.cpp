#include "imports.h"
#include "function.h"
#include "memory.h"
#include "heap.h"
#include "xdm.h"
#include "guest_thread.h"
#include "file_io.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <condition_variable>
#include <filesystem>
#include <mutex>
#include <thread>
#include <unordered_map>

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
// Timer & DPC subsystem
// ---------------------------------------------------------------------------
// Implements Xbox kernel timer/DPC functionality matching Cxbx-Reloaded.
// Timers are tracked in a host-side list. A background thread checks for
// expired timers and dispatches any associated DPCs by calling the guest
// deferred routine.

// Xbox KTIMER guest memory layout (0x28 bytes):
//   +0x00  DISPATCHER_HEADER Header  (Type, Absolute, Size, Inserted, SignalState, WaitListHead)
//   +0x10  ULARGE_INTEGER DueTime
//   +0x18  LIST_ENTRY TimerListEntry  (Flink, Blink)
//   +0x20  DWORD Dpc                  (guest pointer to KDPC)
//   +0x24  LONG  Period

// Xbox KDPC guest memory layout (0x1C bytes):
//   +0x00  SHORT  Type
//   +0x02  BYTE   Inserted
//   +0x03  BYTE   Importance
//   +0x04  LIST_ENTRY DpcListEntry    (Flink, Blink)
//   +0x0C  DWORD  DeferredRoutine     (guest function pointer)
//   +0x10  DWORD  DeferredContext     (guest pointer)
//   +0x14  DWORD  SystemArgument1
//   +0x18  DWORD  SystemArgument2

// Timer object type codes
static constexpr uint8_t TimerNotificationObject  = 8;
static constexpr uint8_t TimerSynchronizationObject = 9;
static constexpr uint8_t DpcObject = 19;

// A host-side record tracking a guest timer
struct HostTimer
{
    uint32_t guestTimerAddr;        // Guest address of KTIMER struct
    uint64_t dueTimeAbsolute;       // Absolute due time (100-ns ticks since boot)
    uint32_t guestDpcAddr;          // Guest address of KDPC (0 if none)
    int32_t  periodMs;              // Period in ms (0 = one-shot)
    bool     inserted;              // Is this timer active?
};

static std::mutex g_timerLock;
static std::condition_variable g_timerCv;
static std::vector<HostTimer> g_timers;
static std::thread g_timerThread;
static bool g_timerThreadRunning = false;

// Boot time â€” must be defined before everything that uses it.
// (Replaces the later static auto g_startTime so there's a single definition.)
static std::chrono::high_resolution_clock::time_point g_bootTime =
    std::chrono::high_resolution_clock::now();

// Get current time in 100-ns ticks since process start (matches KeQueryInterruptTime)
static uint64_t GetInterruptTimeTicks()
{
    auto now = std::chrono::high_resolution_clock::now();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now - g_bootTime).count();
    return static_cast<uint64_t>(ns / 100); // 100-ns ticks
}

// Forward declarations
static void TimerThreadFunc();
static void FireDpc(uint32_t guestDpcAddr, uint8_t* base);

static void StartTimerThread()
{
    if (g_timerThreadRunning)
        return;
    g_timerThreadRunning = true;
    g_timerThread = std::thread(TimerThreadFunc);
    g_timerThread.detach();
}

static void TimerThreadFunc()
{
    while (g_timerThreadRunning)
    {
        std::unique_lock<std::mutex> lock(g_timerLock);
        
        // Find earliest due time
        uint64_t earliest = UINT64_MAX;
        for (auto& t : g_timers)
        {
            if (t.inserted && t.dueTimeAbsolute < earliest)
                earliest = t.dueTimeAbsolute;
        }

        uint64_t now = GetInterruptTimeTicks();

        if (earliest > now)
        {
            // Wait until next timer or until woken
            auto waitDuration = std::chrono::microseconds((earliest - now) / 10);
            if (earliest == UINT64_MAX)
                g_timerCv.wait_for(lock, std::chrono::milliseconds(100));
            else
                g_timerCv.wait_for(lock, waitDuration);
            continue;
        }

        // Process expired timers
        uint8_t* base = g_memory.base;
        for (auto& t : g_timers)
        {
            if (!t.inserted)
                continue;
            if (t.dueTimeAbsolute > now)
                continue;
            
            // Timer has expired â€” signal it
            t.inserted = false;

            // Update guest KTIMER in memory
            X86_MEM_WRITE_u8(base, t.guestTimerAddr + 0x03, 0); // Header.Inserted = FALSE
            X86_MEM_WRITE_u32(base, t.guestTimerAddr + 0x04, 1); // Header.SignalState = TRUE

            uint32_t dpcAddr = t.guestDpcAddr;
            int32_t period = t.periodMs;

            // If periodic, reschedule
            if (period > 0)
            {
                t.dueTimeAbsolute = now + static_cast<uint64_t>(period) * 10000ULL;
                t.inserted = true;
                X86_MEM_WRITE_u8(base, t.guestTimerAddr + 0x03, 1); // Header.Inserted = TRUE
                X86_MEM_WRITE_u32(base, t.guestTimerAddr + 0x04, 0); // Header.SignalState = FALSE
            }

            // Fire the DPC if present (release lock during callback)
            if (dpcAddr)
            {
                lock.unlock();
                FireDpc(dpcAddr, base);
                lock.lock();
            }
        }
    }
}

// Dispatch a DPC: call the guest DeferredRoutine(Dpc, DeferredContext, SystemArg1, SystemArg2)
static void FireDpc(uint32_t guestDpcAddr, uint8_t* base)
{
    uint32_t routineAddr = X86_MEM_READ_u32(base, guestDpcAddr + 0x0C);
    if (!routineAddr)
        return;

    uint32_t deferredContext = X86_MEM_READ_u32(base, guestDpcAddr + 0x10);
    uint32_t sysArg1 = X86_MEM_READ_u32(base, guestDpcAddr + 0x14);
    uint32_t sysArg2 = X86_MEM_READ_u32(base, guestDpcAddr + 0x18);

    static int s_dpcLog = 0;
    if (s_dpcLog < 5) {
        fprintf(stderr, "[Kernel] Firing DPC: routine=0x%08X, context=0x%08X\n",
                routineAddr, deferredContext);
        s_dpcLog++;
    }

    // Call the guest deferred routine
    auto it = g_funcMap.find(routineAddr);
    if (it != g_funcMap.end())
    {
        X86Context dpcCtx{};
        dpcCtx.esp = 0x07FE0000; // Temporary stack for DPC
        dpcCtx.ebp = dpcCtx.esp;

        // Push arguments in stdcall order (right-to-left), then dummy return address
        // Push SystemArgument2
        dpcCtx.esp -= 4;
        X86_MEM_WRITE_u32(base, dpcCtx.esp, sysArg2);
        // Push SystemArgument1
        dpcCtx.esp -= 4;
        X86_MEM_WRITE_u32(base, dpcCtx.esp, sysArg1);
        // Push DeferredContext
        dpcCtx.esp -= 4;
        X86_MEM_WRITE_u32(base, dpcCtx.esp, deferredContext);
        // Push Dpc pointer
        dpcCtx.esp -= 4;
        X86_MEM_WRITE_u32(base, dpcCtx.esp, guestDpcAddr);
        // Push dummy return address (simulates what 'call' does)
        dpcCtx.esp -= 4;
        X86_MEM_WRITE_u32(base, dpcCtx.esp, 0);

        it->second(dpcCtx, base);

        // Restore IRQL to PASSIVE_LEVEL.  On real Xbox the kernel
        // lowers IRQL after the DPC returns; DPCs run on the timer
        // thread here so we must not leave DISPATCH_LEVEL visible
        // to the concurrent game thread.
        X86_MEM_WRITE_u8(base, 0x24, 0);
    }
    else
    {
        fprintf(stderr, "[Kernel] DPC routine 0x%08X not found in funcMap! (dpcAddr=0x%08X ctx=0x%08X)\n", routineAddr, guestDpcAddr, deferredContext);
    }
}

// Find or create a HostTimer for a guest KTIMER address
static HostTimer* FindOrCreateTimer(uint32_t guestAddr)
{
    for (auto& t : g_timers)
    {
        if (t.guestTimerAddr == guestAddr)
            return &t;
    }
    g_timers.push_back({guestAddr, 0, 0, 0, false});
    return &g_timers.back();
}

// ---------------------------------------------------------------------------
// Helper: register a stub for a thunk address and write self-reference
//         into guest memory so that X86_MEM_READ_u32(base, thunkAddr)
//         returns the thunkAddr itself, then insert into g_funcMap.
// ---------------------------------------------------------------------------
std::unordered_map<uint32_t, const char*> g_thunkNames;

static void HookThunk(uint32_t thunkAddr, X86RecompFunc stub, const char* name = nullptr)
{
    X86_MEM_WRITE_u32(g_memory.base, thunkAddr, thunkAddr);
    if (name)
        g_thunkNames[thunkAddr] = name;
    g_funcMap[thunkAddr] = stub;
}

// Convenience: log+stub for unimplemented kernel calls.
#define KERNEL_STUB(name)                                                     \
    static void Kern_##name(X86Context& ctx, uint8_t* base)                   \
    {                                                                         \
        fprintf(stderr, "[Kernel] STUB: " #name " called\n");                \
        ctx.eax = 0;                                                          \
    }

#define KERNEL_STUB_CLEANUP(name, argBytes)                                   \
    static void Kern_##name(X86Context& ctx, uint8_t* base)                   \
    {                                                                         \
        fprintf(stderr, "[Kernel] STUB: " #name " called\n");                \
        ctx.eax = 0;                                                          \
        GuestStackCleanup(ctx, argBytes);                                     \
    }

// ---------------------------------------------------------------------------
// Memory management
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// Guest Virtual Memory Pool  (backing for NtAllocateVirtualMemory)
// ---------------------------------------------------------------------------
// The Xbox CRT uses NtAllocateVirtualMemory as its backing store for malloc.
// It binary-probes for the largest available block and claims it all, so it
// must NOT share o1heap with HLE allocations or it starves them.
//
// This pool is a bump allocator starting after the XBE image and extending
// to 0x08000000.  The XBE image spans X86_IMAGE_BASE..X86_IMAGE_BASE+IMAGE_SIZE
// (0x10000..0x944BE0) so we must start beyond that to avoid overwriting
// function pointer tables and other data in the loaded image.
// Freed blocks are un-tracked but not recycled (the CRT heap slab is
// allocated once at startup and never freed in practice).
// ---------------------------------------------------------------------------
static constexpr uint32_t kGuestVMBase  = (X86_IMAGE_BASE + X86_IMAGE_SIZE + 0xFFFu) & ~0xFFFu; // page-aligned, after XBE
static constexpr uint32_t kGuestVMLimit = 0x08000000;

// ---------------------------------------------------------------------------
// Physical / Contiguous Memory Pool
// ---------------------------------------------------------------------------
// Xbox MmAllocateContiguousMemoryEx returns addresses that the game treats as
// physical RAM addresses.  The game typically masks them with & 0x0FFFFFFF to
// get a 28-bit NV2A physical address, then accesses them via | 0x80000000
// (write-combined) or | 0xF0000000 (uncached).  x86_phys_translate() converts
// those back via & (X86_RAM_SIZE - 1) = & 0x1FFFFFFF.
//
// For the roundtrip to work, the allocated address A must satisfy:
//   A == (A & 0x0FFFFFFF)          (the 28-bit mask preserves A)
//   A == ((A | 0x80000000) & 0x1FFFFFFF)   (phys_translate recovers A)
//
// Both conditions hold when A < 0x10000000.  We therefore place this pool
// above the GuestVM pool limit (0x08000000) and below 0x10000000.
// ---------------------------------------------------------------------------
static constexpr uint32_t kPhysMemBase  = 0x08000000;
static constexpr uint32_t kPhysMemLimit = 0x10000000; // 128 MB pool

static uint32_t  s_guestVMHead = kGuestVMBase;
static std::mutex s_guestVMMutex;
static std::unordered_map<uint32_t, uint32_t> s_guestVMMap; // addr -> size

static uint32_t  s_physMemHead = kPhysMemBase;
static std::mutex s_physMemMutex;

static uint32_t PhysMemAlloc(uint32_t size, uint32_t alignment, uint8_t* base)
{
    if (size == 0) return 0;
    std::lock_guard<std::mutex> lk(s_physMemMutex);
    uint32_t addr = (s_physMemHead + alignment - 1) & ~(alignment - 1);
    if (addr + size > kPhysMemLimit || addr + size < addr) {
        fprintf(stderr, "[PhysMem] OOM: requested %u bytes (used %u / %u MB)\n",
                size, s_physMemHead - kPhysMemBase,
                (kPhysMemLimit - kPhysMemBase) >> 20);
        return 0;
    }
    memset(base + addr, 0, size);
    s_physMemHead = addr + size;
    return addr;
}

static uint32_t GuestVMAlloc(uint32_t size, uint32_t alignment, uint8_t* base)
{
    if (size == 0) return 0;
    std::lock_guard<std::mutex> lk(s_guestVMMutex);
    uint32_t addr = (s_guestVMHead + alignment - 1) & ~(alignment - 1);
    if (addr + size > kGuestVMLimit || addr + size < addr) {
        fprintf(stderr, "[GuestVM] OOM: requested %u bytes, align=%u (used %u / %u MB)\n",
                size, alignment,
                s_guestVMHead - kGuestVMBase,
                (kGuestVMLimit - kGuestVMBase) >> 20);
        return 0;
    }
    memset(base + addr, 0, size);
    s_guestVMHead = addr + size;
    s_guestVMMap[addr] = size;
    return addr;
}

static void GuestVMFree(uint32_t addr)
{
    std::lock_guard<std::mutex> lk(s_guestVMMutex);
    s_guestVMMap.erase(addr); // un-track but don't recycle (bump allocator)
}

// Public entry point called by the HLE-replaced sub_8A92E (Xbox debug CRT
// internal alloc). Returns a zeroed block from the GuestVM pool, giving
// the game release-CRT semantics (no debug-fill patterns).
// For oversized requests (e.g. the 528 MB debug-CRT heap probe), GuestVMAlloc
// returns 0 (OOM) naturally. Returning 0 causes the probe chain (sub_8A955
// â†’ sub_8A981) to fail gracefully without corrupting guest memory.
uint32_t GuestMalloc(uint32_t size, uint8_t* base)
{
    if (size == 0) size = 1;
    if (size > (kGuestVMLimit - kGuestVMBase))
    {
        //fprintf(stderr, "[GuestVM] GuestMalloc: refusing %u bytes (exceeds pool)\n", size);
        return 0; // caller handles failure gracefully via probe loop
    }
    uint32_t addr = GuestVMAlloc(size, 4096, base); // page-aligned; returns 0 on OOM
    //fprintf(stderr, "[GuestVM] GuestMalloc: %u -> 0x%08X%s\n", size, addr, addr ? "" : " FAILED");
    return addr;
}

static void Kern_MmAllocateContiguousMemory(X86Context& ctx, uint8_t* base)
{
    uint32_t size = GuestArg32(ctx, base, 0);
    uint32_t addr = PhysMemAlloc(size, 4096, base);
    GuestReturn32(ctx, addr);
    GuestStackCleanup(ctx, 4);
}

// PVOID MmAllocateContiguousMemoryEx(SIZE_T NumberOfBytes, ULONG_PTR LowestAcceptable,
//       ULONG_PTR HighestAcceptable, ULONG_PTR BoundaryAddressMultiple, ULONG Protect)
static void Kern_MmAllocateContiguousMemoryEx(X86Context& ctx, uint8_t* base)
{
    uint32_t size = GuestArg32(ctx, base, 0);
    uint32_t addr = PhysMemAlloc(size, 4096, base);
    GuestReturn32(ctx, addr);
    GuestStackCleanup(ctx, 20);
}

// VOID MmFreeContiguousMemory(PVOID BaseAddress)
static void Kern_MmFreeContiguousMemory(X86Context& ctx, uint8_t* base)
{
    // Physical memory bump allocator does not support individual frees.
    GuestStackCleanup(ctx, 4);
}

// ULONG MmQueryAllocationSize(PVOID BaseAddress)
static void Kern_MmQueryAllocationSize(X86Context& ctx, uint8_t* base)
{
    // Stub: return 0 (unknown size).
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// VOID MmSetAddressProtect(PVOID BaseAddress, ULONG NumberOfBytes, ULONG NewProtect)
static void Kern_MmSetAddressProtect(X86Context& ctx, uint8_t* base)
{
    // No-op in recompiled environment.
    GuestStackCleanup(ctx, 12);
}

// PVOID MmMapIoSpace(PHYSICAL_ADDRESS PhysicalAddress, ULONG NumberOfBytes, ULONG Protect)
static void Kern_MmMapIoSpace(X86Context& ctx, uint8_t* base)
{
    uint32_t physAddr = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[Kernel] MmMapIoSpace(0x%08X) -> returning physAddr as-is\n", physAddr);
    GuestReturn32(ctx, physAddr);
    GuestStackCleanup(ctx, 12);
}

// VOID MmPersistContiguousMemory(PVOID BaseAddress, ULONG NumberOfBytes, BOOLEAN Persist)
static void Kern_MmPersistContiguousMemory(X86Context& ctx, uint8_t* base)
{
    // No-op.
    GuestStackCleanup(ctx, 12);
}

// PVOID ExAllocatePool(ULONG NumberOfBytes)
static void Kern_ExAllocatePool(X86Context& ctx, uint8_t* base)
{
    uint32_t size = GuestArg32(ctx, base, 0);
    uint32_t addr = g_heap.AllocGuest(size);
    if (addr)
        memset(g_memory.Translate(addr), 0, size);
    GuestReturn32(ctx, addr);
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// Timing
// ---------------------------------------------------------------------------

// (g_bootTime is defined earlier in the file)

// VOID KeQueryPerformanceCounter(PLARGE_INTEGER PerformanceCount)
// OG Xbox returns the value via pointer (unlike NT which returns it).
static void Kern_KeQueryPerformanceCounter(X86Context& ctx, uint8_t* base)
{
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - g_bootTime).count();
    // Return as microseconds tick count.
    GuestReturn64(ctx, static_cast<uint64_t>(elapsed));
}

// VOID KeQueryPerformanceFrequency(PLARGE_INTEGER Frequency)
static void Kern_KeQueryPerformanceFrequency(X86Context& ctx, uint8_t* base)
{
    // Microsecond-based frequency.
    GuestReturn64(ctx, 1000000ULL);
}

// ULONG KeTickCount -- this is a variable, not a function.
// The thunk points to the tick count variable.
static void Kern_KeTickCount(X86Context& ctx, uint8_t* base)
{
    auto now = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - g_bootTime).count();
    GuestReturn32(ctx, static_cast<uint32_t>(ms));
}

// VOID KeStallExecutionProcessor(ULONG MicroSeconds)
static void Kern_KeStallExecutionProcessor(X86Context& ctx, uint8_t* base)
{
    // No-op or sleep briefly.
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// Synchronization
// ---------------------------------------------------------------------------

// NTSTATUS NtCreateEvent(PHANDLE EventHandle, POBJECT_ATTRIBUTES ObjectAttributes,
//                        EVENT_TYPE EventType, BOOLEAN InitialState)
static void Kern_NtCreateEvent(X86Context& ctx, uint8_t* base)
{
    uint32_t handlePtr  = GuestArg32(ctx, base, 0);
    uint32_t eventType  = GuestArg32(ctx, base, 2); // 0 = notification, 1 = synchronization
    uint32_t initState  = GuestArg32(ctx, base, 3);
    bool manual  = (eventType == 0);
    bool initial = (initState != 0);
    uint32_t handle = CreateKernelHandle<Event>(manual, initial);
    if (handlePtr)
        X86_MEM_WRITE_u32(base, handlePtr, handle);
    GuestReturn32(ctx, 0); // STATUS_SUCCESS
    GuestStackCleanup(ctx, 16);
}

// NTSTATUS NtCreateMutant(PHANDLE MutantHandle, POBJECT_ATTRIBUTES ObjectAttributes,
//                         BOOLEAN InitialOwner)
static void Kern_NtCreateMutant(X86Context& ctx, uint8_t* base)
{
    uint32_t handlePtr    = GuestArg32(ctx, base, 0);
    uint32_t initialOwner = GuestArg32(ctx, base, 2);
    uint32_t handle = CreateKernelHandle<Mutex>();
    if (initialOwner)
    {
        auto* m = static_cast<Mutex*>(GetKernelObjectByHandle(handle));
        if (m) m->Lock();
    }
    if (handlePtr)
        X86_MEM_WRITE_u32(base, handlePtr, handle);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// NTSTATUS KeWaitForSingleObject(PVOID Object, KWAIT_REASON WaitReason,
//          KPROCESSOR_MODE WaitMode, BOOLEAN Alertable, PLARGE_INTEGER Timeout)
static void Kern_KeWaitForSingleObject(X86Context& ctx, uint8_t* base)
{
    uint32_t objAddr    = GuestArg32(ctx, base, 0);
    uint32_t timeoutPtr = GuestArg32(ctx, base, 4);
    uint8_t  objType    = objAddr ? X86_MEM_READ_u8(base, objAddr) : 0xFF;
    uint32_t sigState   = objAddr ? X86_MEM_READ_u32(base, objAddr + 0x04) : 0xDEAD;
    fprintf(stderr, "[KeWaitForSingleObject] obj=0x%08X type=0x%02X signalState=%d timeoutPtr=0x%08X esp=0x%08X\n",
            objAddr, objType, (int32_t)sigState, timeoutPtr, ctx.esp);

    uint32_t timeoutMs = UINT32_MAX; // INFINITE
    if (timeoutPtr)
    {
        // Sign-extend lo DWORD as int32 so that 0xFFFFD8F0 â†’ -10000 (relative 1ms),
        // not +4294957296 (looks positive, treated as absolute or infinite).
        int32_t t_lo = static_cast<int32_t>(X86_MEM_READ_u32(base, timeoutPtr));
        int32_t t_hi = static_cast<int32_t>(X86_MEM_READ_u32(base, timeoutPtr + 4));
        int64_t timeout100ns = static_cast<int64_t>(t_lo) | (static_cast<int64_t>(t_hi) << 32);
        if (timeout100ns < 0)
            timeoutMs = static_cast<uint32_t>((-timeout100ns) / 10000); // relative
        else if (timeout100ns == 0)
            timeoutMs = 0;
        else
            timeoutMs = UINT32_MAX;
    }

    KernelObject* obj = ResolveDispatcherObject(base, objAddr);
    if (obj)
        obj->Wait(timeoutMs);

    GuestReturn32(ctx, 0); // STATUS_SUCCESS
    GuestStackCleanup(ctx, 20);
}

// VOID RtlEnterCriticalSection(PRTL_CRITICAL_SECTION CriticalSection)
static void Kern_RtlEnterCriticalSection(X86Context& ctx, uint8_t* base)
{
    uint32_t csAddr = GuestArg32(ctx, base, 0);
    // Use WaitFlink at offset 8 for OBJECT_SIGNATURE caching, treat as mutex.
    auto* m = QueryKernelObject<Mutex>(base, csAddr);
    if (m) m->Lock();
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS NtResumeThread(HANDLE ThreadHandle, PULONG PreviousSuspendCount)
static void Kern_NtResumeThread(X86Context& ctx, uint8_t* base)
{
    uint32_t handle = GuestArg32(ctx, base, 0);
    if (auto* obj = dynamic_cast<GuestThread*>(GetKernelObjectByHandle(handle)))
        obj->Resume();
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// NTSTATUS KeResumeThread(PKTHREAD Thread)
// arg0 is the KTHREAD pointer (guest address), not a handle.
// We can't cheaply map guest KTHREAD back to our GuestThread, so just
// resume all suspended threads â€” Doom only ever has one at a time here.
static void Kern_KeResumeThread(X86Context& ctx, uint8_t* base)
{
    std::lock_guard<std::mutex> lk(g_kernelLock);
    for (auto* obj : g_kernelObjects)
        if (auto* gt = dynamic_cast<GuestThread*>(obj))
            gt->Resume();
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS KeAlertResumeThread(PKTHREAD Thread, PULONG PreviousSuspendCount)
static void Kern_KeAlertResumeThread(X86Context& ctx, uint8_t* base)
{
    std::lock_guard<std::mutex> lk(g_kernelLock);
    for (auto* obj : g_kernelObjects)
        if (auto* gt = dynamic_cast<GuestThread*>(obj))
            gt->Resume();
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// VOID KeInitializeDpc(PKDPC Dpc, PKDEFERRED_ROUTINE DeferredRoutine, PVOID DeferredContext)
static void Kern_KeInitializeDpc(X86Context& ctx, uint8_t* base)
{
    uint32_t dpcAddr    = GuestArg32(ctx, base, 0);
    uint32_t routineAddr = GuestArg32(ctx, base, 1);
    uint32_t contextAddr = GuestArg32(ctx, base, 2);

    // Initialise the guest KDPC structure (0x1C bytes)
    X86_MEM_WRITE_u16(base, dpcAddr + 0x00, DpcObject);         // Type
    X86_MEM_WRITE_u8 (base, dpcAddr + 0x02, 0);                 // Inserted = FALSE
    X86_MEM_WRITE_u8 (base, dpcAddr + 0x03, 0);                 // Importance = Medium
    // DpcListEntry â€” zero out Flink/Blink
    X86_MEM_WRITE_u32(base, dpcAddr + 0x04, 0);
    X86_MEM_WRITE_u32(base, dpcAddr + 0x08, 0);
    X86_MEM_WRITE_u32(base, dpcAddr + 0x0C, routineAddr);       // DeferredRoutine
    X86_MEM_WRITE_u32(base, dpcAddr + 0x10, contextAddr);       // DeferredContext
    X86_MEM_WRITE_u32(base, dpcAddr + 0x14, 0);                 // SystemArgument1
    X86_MEM_WRITE_u32(base, dpcAddr + 0x18, 0);                 // SystemArgument2

    GuestStackCleanup(ctx, 12);
}

// VOID KeInitializeTimerEx(PKTIMER Timer, TIMER_TYPE Type)
static void Kern_KeInitializeTimerEx(X86Context& ctx, uint8_t* base)
{
    uint32_t timerAddr = GuestArg32(ctx, base, 0);
    uint32_t type      = GuestArg32(ctx, base, 1);

    // Header â€” DISPATCHER_HEADER (0x10 bytes)
    uint8_t typeCode = static_cast<uint8_t>(type + TimerNotificationObject);
    X86_MEM_WRITE_u8 (base, timerAddr + 0x00, typeCode);        // Type
    X86_MEM_WRITE_u8 (base, timerAddr + 0x01, 0);               // Absolute
    X86_MEM_WRITE_u8 (base, timerAddr + 0x02, 10);              // Size = sizeof(KTIMER)/sizeof(ULONG)
    X86_MEM_WRITE_u8 (base, timerAddr + 0x03, 0);               // Inserted = FALSE
    X86_MEM_WRITE_u32(base, timerAddr + 0x04, 0);               // SignalState = 0
    // WaitListHead â€” self-referencing empty list
    X86_MEM_WRITE_u32(base, timerAddr + 0x08, timerAddr + 0x08);
    X86_MEM_WRITE_u32(base, timerAddr + 0x0C, timerAddr + 0x08);

    // DueTime (ULARGE_INTEGER) = 0
    X86_MEM_WRITE_u32(base, timerAddr + 0x10, 0);
    X86_MEM_WRITE_u32(base, timerAddr + 0x14, 0);
    // TimerListEntry = {0, 0}
    X86_MEM_WRITE_u32(base, timerAddr + 0x18, 0);
    X86_MEM_WRITE_u32(base, timerAddr + 0x1C, 0);
    // Dpc = NULL
    X86_MEM_WRITE_u32(base, timerAddr + 0x20, 0);
    // Period = 0
    X86_MEM_WRITE_u32(base, timerAddr + 0x24, 0);

    GuestStackCleanup(ctx, 8);
}

// ---------------------------------------------------------------------------
// File I/O â€” backed by std::fstream via FileHandle (kernel/file_io.h)
// ---------------------------------------------------------------------------

// Helper: open or create a file, returning a kernel handle.
static uint32_t OpenOrCreateFile(uint8_t* base, uint32_t objAttrAddr,
                                  uint32_t desiredAccess, uint32_t createDisposition,
                                  uint32_t createOptions)
{
    std::string xboxPath = ReadObjectName(base, objAttrAddr);
    if (xboxPath.empty())
    {
        // Dump OBJECT_ATTRIBUTES and ANSI_STRING for debugging
        if (objAttrAddr)
        {
            auto* oa = reinterpret_cast<const XBOX_OBJECT_ATTRIBUTES*>(base + objAttrAddr);
            fprintf(stderr, "[FileIO] Open FAILED (empty path): objAttrAddr=0x%08X "
                    "RootDir=0x%08X ObjectName=0x%08X Attr=0x%08X\n",
                    objAttrAddr, oa->RootDirectory, oa->ObjectName, oa->Attributes);
            if (oa->ObjectName)
            {
                auto* str = reinterpret_cast<const XBOX_ANSI_STRING*>(base + oa->ObjectName);
                // fprintf(stderr, "[FileIO]   ANSI_STRING: Len=%u MaxLen=%u Buffer=0x%08X\n",
                //         str->Length, str->MaximumLength, str->Buffer);
                // if (str->Buffer && str->Length > 0 && str->Length < 1024)
                // {
                //     const char* buf = reinterpret_cast<const char*>(base + str->Buffer);
                //     fprintf(stderr, "[FileIO]   Buffer contents: \"%.*s\"\n",
                //             (int)str->Length, buf);
                // }
            }
        }
        else
        {
            fprintf(stderr, "[FileIO] Open FAILED: objAttrAddr is NULL\n");
        }
        return 0;
    }

    std::filesystem::path hostPath = TranslateXboxPath(xboxPath);
    fprintf(stderr, "[FileIO] Open: \"%s\" -> \"%s\"\n",
            xboxPath.c_str(), hostPath.string().c_str());

    // Directory open
    if (createOptions & X_FILE_DIRECTORY_FILE)
    {
        std::error_code ec;
        if (!std::filesystem::is_directory(hostPath, ec))
        {
            fprintf(stderr, "[FileIO]   -> directory not found\n");
            return 0;
        }
        uint32_t handle = CreateKernelHandle<FileHandle>();
        auto* fh = static_cast<FileHandle*>(GetKernelObjectByHandle(handle));
        fh->hostPath = std::move(hostPath);
        fh->isDirectory = true;
        return handle;
    }

    // Determine fstream open mode
    std::ios::openmode mode = std::ios::binary;
    if (desiredAccess & (XBOX_GENERIC_READ | XBOX_FILE_READ_DATA))
        mode |= std::ios::in;
    if (desiredAccess & (XBOX_GENERIC_WRITE | XBOX_FILE_WRITE_DATA | XBOX_FILE_APPEND_DATA))
        mode |= std::ios::out;

    // Handle create dispositions
    switch (createDisposition)
    {
    case X_FILE_CREATE:
    {
        std::error_code ec;
        if (std::filesystem::exists(hostPath, ec))
            return 0; // file already exists
        // Ensure parent directory exists
        std::filesystem::create_directories(hostPath.parent_path(), ec);
        // Create the file by opening with trunc
        mode |= std::ios::trunc;
        break;
    }
    case X_FILE_OPEN:
    {
        std::error_code ec;
        if (!std::filesystem::exists(hostPath, ec))
            return 0;
        break;
    }
    case X_FILE_OPEN_IF:
    {
        std::error_code ec;
        if (!std::filesystem::exists(hostPath, ec))
        {
            std::filesystem::create_directories(hostPath.parent_path(), ec);
            mode |= std::ios::trunc;
        }
        break;
    }
    case X_FILE_OVERWRITE:
    case X_FILE_OVERWRITE_IF:
    case X_FILE_SUPERSEDE:
    {
        std::error_code ec;
        std::filesystem::create_directories(hostPath.parent_path(), ec);
        mode |= std::ios::trunc;
        break;
    }
    default:
        break;
    }

    std::fstream stream(hostPath, mode);
    if (!stream.is_open())
    {
        fprintf(stderr, "[FileIO]   -> failed to open\n");
        return 0;
    }

    uint32_t handle = CreateKernelHandle<FileHandle>();
    auto* fh = static_cast<FileHandle*>(GetKernelObjectByHandle(handle));
    fh->stream = std::move(stream);
    fh->hostPath = std::move(hostPath);
    fh->isDirectory = false;
    //fprintf(stderr, "[FileIO]   -> handle %u\n", handle);
    return handle;
}

// NTSTATUS NtCreateFile(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES,
//   PIO_STATUS_BLOCK, PLARGE_INTEGER, ULONG, ULONG, ULONG, ULONG)
// 9 params, 36 bytes
static void Kern_NtCreateFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handlePtr        = GuestArg32(ctx, base, 0);
    uint32_t desiredAccess    = GuestArg32(ctx, base, 1);
    uint32_t objAttrAddr      = GuestArg32(ctx, base, 2);
    uint32_t ioStatusAddr     = GuestArg32(ctx, base, 3);
    // arg 4 = AllocationSize (ignored)
    // arg 5 = FileAttributes (ignored)
    // arg 6 = ShareAccess (ignored â€” single-process)
    uint32_t createDisposition = GuestArg32(ctx, base, 7);
    uint32_t createOptions     = GuestArg32(ctx, base, 8);
    uint32_t handle = OpenOrCreateFile(base, objAttrAddr, desiredAccess,
                                       createDisposition, createOptions);
    if (handle)
    {
        if (handlePtr)
            X86_MEM_WRITE_u32(base, handlePtr, handle);
        if (ioStatusAddr)
        {
            auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
            io->Status = X_STATUS_SUCCESS;
            io->Information = 0;
        }
        GuestReturn32(ctx, X_STATUS_SUCCESS);
    }
    else
    {
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
    }
    GuestStackCleanup(ctx, 36);
}

// NTSTATUS NtOpenFile(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES,
//   PIO_STATUS_BLOCK, ULONG, ULONG)
// 6 params, 24 bytes
static void Kern_NtOpenFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handlePtr     = GuestArg32(ctx, base, 0);
    uint32_t desiredAccess = GuestArg32(ctx, base, 1);
    uint32_t objAttrAddr   = GuestArg32(ctx, base, 2);
    uint32_t ioStatusAddr  = GuestArg32(ctx, base, 3);
    // arg 4 = ShareAccess (ignored)
    uint32_t openOptions   = GuestArg32(ctx, base, 5);

    uint32_t handle = OpenOrCreateFile(base, objAttrAddr, desiredAccess,
                                       X_FILE_OPEN, openOptions);
    if (handle)
    {
        if (handlePtr)
            X86_MEM_WRITE_u32(base, handlePtr, handle);
        if (ioStatusAddr)
        {
            auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
            io->Status = X_STATUS_SUCCESS;
            io->Information = 0;
        }
        GuestReturn32(ctx, X_STATUS_SUCCESS);
    }
    else
    {
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
    }
    GuestStackCleanup(ctx, 24);
}

// NTSTATUS NtClose(HANDLE)
// 1 param, 4 bytes
static void Kern_NtClose(X86Context& ctx, uint8_t* base)
{
    uint32_t handle = GuestArg32(ctx, base, 0);

    auto* obj = GetKernelObjectByHandle(handle);
    if (obj)
    {
        // If it's a FileHandle, close the stream.
        auto* fh = dynamic_cast<FileHandle*>(obj);
        if (fh && fh->stream.is_open())
            fh->stream.close();
    }

    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS NtReadFile(HANDLE, HANDLE Event, PIO_APC_ROUTINE, PVOID,
//   PIO_STATUS_BLOCK, PVOID Buffer, ULONG Length, PLARGE_INTEGER ByteOffset)
// 8 params, 32 bytes
// Xbox physical address translation: addresses in 0x80000000+ are the
// contiguous/write-combined physical mapping.  Strip the upper bits to
// recover the guest virtual address within our flat allocation.
static inline uint32_t XboxPhysToGuest(uint32_t addr)
{
    if (addr >= X86_RAM_SIZE)
        return addr & (X86_RAM_SIZE - 1);
    return addr;
}

static void Kern_NtReadFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle       = GuestArg32(ctx, base, 0);
    // arg 1 = Event (ignored)
    // arg 2 = ApcRoutine (ignored)
    // arg 3 = ApcContext (ignored)
    uint32_t ioStatusAddr = GuestArg32(ctx, base, 4);
    uint32_t bufferAddr   = GuestArg32(ctx, base, 5);
    uint32_t length       = GuestArg32(ctx, base, 6);
    uint32_t offsetPtr    = GuestArg32(ctx, base, 7);

    // Translate Xbox contiguous/physical addresses to guest addresses.
    bufferAddr   = XboxPhysToGuest(bufferAddr);
    ioStatusAddr = XboxPhysToGuest(ioStatusAddr);
    if (offsetPtr) offsetPtr = XboxPhysToGuest(offsetPtr);

    auto* obj = GetKernelObjectByHandle(handle);
    auto* fh = obj ? dynamic_cast<FileHandle*>(obj) : nullptr;
    if (!fh || !fh->stream.is_open())
    {
        GuestReturn32(ctx, X_STATUS_INVALID_HANDLE);
        GuestStackCleanup(ctx, 32);
        return;
    }

    // Bounds check: ensure buffer fits within guest memory.
    if ((uint64_t)bufferAddr + length > X86_RAM_SIZE)
    {
        fprintf(stderr, "[FileIO] NtReadFile: buffer 0x%08X+0x%X overflows guest memory, failing\n",
                bufferAddr, length);
        GuestReturn32(ctx, 0xC000009A); // STATUS_INSUFFICIENT_RESOURCES
        GuestStackCleanup(ctx, 32);
        return;
    }

    // Seek to byte offset if provided.
    int64_t seekOffset = -1;
    if (offsetPtr)
    {
        seekOffset = *reinterpret_cast<int64_t*>(base + offsetPtr);
        fh->stream.clear();
        fh->stream.seekg(static_cast<std::streamoff>(seekOffset), std::ios::beg);
    }

    fh->stream.read(reinterpret_cast<char*>(base + bufferAddr), length);
    uint32_t bytesRead = static_cast<uint32_t>(fh->stream.gcount());
    //fprintf(stderr, "[FileIO] NtReadFile: handle=%u off=%lld len=%u read=%u buf=0x%08X\n",
    //        handle, (long long)seekOffset, length, bytesRead, bufferAddr);

    if (ioStatusAddr)
    {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = bytesRead;
    }

    GuestReturn32(ctx, (bytesRead > 0 || length == 0) ? X_STATUS_SUCCESS : X_STATUS_END_OF_FILE);
    GuestStackCleanup(ctx, 32);
}

// NTSTATUS NtWriteFile(HANDLE, HANDLE Event, PIO_APC_ROUTINE, PVOID,
//   PIO_STATUS_BLOCK, PVOID Buffer, ULONG Length, PLARGE_INTEGER ByteOffset)
// 8 params, 32 bytes
static void Kern_NtWriteFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle       = GuestArg32(ctx, base, 0);
    uint32_t ioStatusAddr = GuestArg32(ctx, base, 4);
    uint32_t bufferAddr   = GuestArg32(ctx, base, 5);
    uint32_t length       = GuestArg32(ctx, base, 6);
    uint32_t offsetPtr    = GuestArg32(ctx, base, 7);

    // Translate Xbox contiguous/physical addresses to guest addresses.
    bufferAddr   = XboxPhysToGuest(bufferAddr);
    ioStatusAddr = XboxPhysToGuest(ioStatusAddr);
    if (offsetPtr) offsetPtr = XboxPhysToGuest(offsetPtr);

    auto* obj = GetKernelObjectByHandle(handle);
    auto* fh = obj ? dynamic_cast<FileHandle*>(obj) : nullptr;
    if (!fh || !fh->stream.is_open())
    {
        GuestReturn32(ctx, X_STATUS_INVALID_HANDLE);
        GuestStackCleanup(ctx, 32);
        return;
    }

    // Bounds check: ensure buffer fits within guest memory.
    if ((uint64_t)bufferAddr + length > X86_RAM_SIZE)
    {
        fprintf(stderr, "[FileIO] NtWriteFile: buffer 0x%08X+0x%X overflows guest memory, failing\n",
                bufferAddr, length);
        GuestReturn32(ctx, 0xC000009A); // STATUS_INSUFFICIENT_RESOURCES
        GuestStackCleanup(ctx, 32);
        return;
    }

    if (offsetPtr)
    {
        int64_t offset = *reinterpret_cast<int64_t*>(base + offsetPtr);
        fh->stream.clear();
        fh->stream.seekp(static_cast<std::streamoff>(offset), std::ios::beg);
    }

    fh->stream.write(reinterpret_cast<const char*>(base + bufferAddr), length);

    if (ioStatusAddr)
    {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = fh->stream.bad() ? X_STATUS_INVALID_HANDLE : X_STATUS_SUCCESS;
        io->Information = fh->stream.bad() ? 0 : length;
    }

    GuestReturn32(ctx, fh->stream.bad() ? X_STATUS_INVALID_HANDLE : X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 32);
}

// NTSTATUS NtQueryInformationFile(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS)
// 5 params, 20 bytes
static void Kern_NtQueryInformationFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle       = GuestArg32(ctx, base, 0);
    uint32_t ioStatusAddr = GuestArg32(ctx, base, 1);
    uint32_t infoAddr     = GuestArg32(ctx, base, 2);
    // arg 3 = Length
    uint32_t infoClass    = GuestArg32(ctx, base, 4);

    auto* obj = GetKernelObjectByHandle(handle);
    auto* fh = obj ? dynamic_cast<FileHandle*>(obj) : nullptr;
    if (!fh)
    {
        GuestReturn32(ctx, X_STATUS_INVALID_HANDLE);
        GuestStackCleanup(ctx, 20);
        return;
    }

    std::error_code ec;
    switch (static_cast<XboxFileInformationClass>(infoClass))
    {
    case FileBasicInformation:
    {
        auto* info = reinterpret_cast<XBOX_FILE_BASIC_INFORMATION*>(base + infoAddr);
        memset(info, 0, sizeof(*info));
        info->FileAttributes = fh->isDirectory ? XBOX_FILE_ATTRIBUTE_DIRECTORY
                                                : XBOX_FILE_ATTRIBUTE_NORMAL;
        break;
    }
    case FileStandardInformation:
    {
        auto* info = reinterpret_cast<XBOX_FILE_STANDARD_INFORMATION*>(base + infoAddr);
        memset(info, 0, sizeof(*info));
        if (!fh->isDirectory)
        {
            auto sz = std::filesystem::file_size(fh->hostPath, ec);
            if (!ec)
            {
                info->EndOfFile = static_cast<int64_t>(sz);
                info->AllocationSize = static_cast<int64_t>(sz);
            }
        }
        info->NumberOfLinks = 1;
        info->Directory = fh->isDirectory ? 1 : 0;
        break;
    }
    case FilePositionInformation:
    {
        auto* info = reinterpret_cast<XBOX_FILE_POSITION_INFORMATION*>(base + infoAddr);
        if (fh->stream.is_open())
        {
            fh->stream.clear();
            info->CurrentByteOffset = static_cast<int64_t>(fh->stream.tellg());
        }
        else
        {
            info->CurrentByteOffset = 0;
        }
        break;
    }
    case FileNetworkOpenInformation:
    {
        auto* info = reinterpret_cast<XBOX_FILE_NETWORK_OPEN_INFORMATION*>(base + infoAddr);
        memset(info, 0, sizeof(*info));
        if (!fh->isDirectory)
        {
            auto sz = std::filesystem::file_size(fh->hostPath, ec);
            if (!ec)
            {
                info->EndOfFile = static_cast<int64_t>(sz);
                info->AllocationSize = static_cast<int64_t>(sz);
            }
        }
        info->FileAttributes = fh->isDirectory ? XBOX_FILE_ATTRIBUTE_DIRECTORY
                                                 : XBOX_FILE_ATTRIBUTE_NORMAL;
        break;
    }
    default:
        fprintf(stderr, "[FileIO] NtQueryInformationFile: unhandled class %u\n", infoClass);
        GuestReturn32(ctx, X_STATUS_NOT_IMPLEMENTED);
        GuestStackCleanup(ctx, 20);
        return;
    }

    if (ioStatusAddr)
    {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = 0;
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 20);
}

// NTSTATUS NtSetInformationFile(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS)
// 5 params, 20 bytes
static void Kern_NtSetInformationFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle       = GuestArg32(ctx, base, 0);
    uint32_t ioStatusAddr = GuestArg32(ctx, base, 1);
    uint32_t infoAddr     = GuestArg32(ctx, base, 2);
    // arg 3 = Length
    uint32_t infoClass    = GuestArg32(ctx, base, 4);

    auto* obj = GetKernelObjectByHandle(handle);
    auto* fh = obj ? dynamic_cast<FileHandle*>(obj) : nullptr;
    if (!fh)
    {
        GuestReturn32(ctx, X_STATUS_INVALID_HANDLE);
        GuestStackCleanup(ctx, 20);
        return;
    }

    switch (static_cast<XboxFileInformationClass>(infoClass))
    {
    case FilePositionInformation:
    {
        auto* info = reinterpret_cast<const XBOX_FILE_POSITION_INFORMATION*>(base + infoAddr);
        if (fh->stream.is_open())
        {
            //fprintf(stderr, "[FileIO] NtSetInformationFile: handle=%u seek=%lld\n",
            //        handle, (long long)info->CurrentByteOffset);
            fh->stream.clear();
            fh->stream.seekg(static_cast<std::streamoff>(info->CurrentByteOffset), std::ios::beg);
            fh->stream.seekp(static_cast<std::streamoff>(info->CurrentByteOffset), std::ios::beg);
        }
        break;
    }
    default:
        fprintf(stderr, "[FileIO] NtSetInformationFile: unhandled class %u\n", infoClass);
        break;
    }

    if (ioStatusAddr)
    {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = 0;
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 20);
}

// Xbox NtQueryDirectoryFile (no ReturnSingleEntry param):
//   HANDLE, HANDLE Event, PIO_APC, PVOID, PIO_STATUS_BLOCK,
//   PVOID, ULONG, FILE_INFORMATION_CLASS, PANSI_STRING FileName, BOOLEAN RestartScan
// 10 params, 40 bytes
static void Kern_NtQueryDirectoryFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle        = GuestArg32(ctx, base, 0);
    uint32_t ioStatusAddr  = GuestArg32(ctx, base, 4);
    uint32_t infoAddr      = GuestArg32(ctx, base, 5);
    uint32_t infoLength    = GuestArg32(ctx, base, 6);
    uint32_t infoClass     = GuestArg32(ctx, base, 7);
    // arg 8 = FileName filter (ignored for now)
    uint32_t restartScan   = GuestArg32(ctx, base, 9);

    auto* obj = GetKernelObjectByHandle(handle);
    auto* fh = obj ? dynamic_cast<FileHandle*>(obj) : nullptr;
    if (!fh || !fh->isDirectory)
    {
        GuestReturn32(ctx, X_STATUS_INVALID_HANDLE);
        GuestStackCleanup(ctx, 40);
        return;
    }

    // Build directory listing on first call or restart.
    if (fh->dirEntries.empty() || restartScan)
    {
        fh->dirEntries.clear();
        fh->dirEnumIndex = 0;
        fh->dirEnumDone = false;
        std::error_code ec;
        for (auto& entry : std::filesystem::directory_iterator(fh->hostPath, ec))
            fh->dirEntries.push_back(entry);
    }

    if (fh->dirEnumIndex >= fh->dirEntries.size())
    {
        GuestReturn32(ctx, X_STATUS_NO_MORE_FILES);
        GuestStackCleanup(ctx, 40);
        return;
    }

    // Fill entries into the output buffer.
    uint32_t offset = 0;
    uint32_t lastEntryOffset = 0;

    while (fh->dirEnumIndex < fh->dirEntries.size())
    {
        auto& entry = fh->dirEntries[fh->dirEnumIndex];
        std::string name = entry.path().filename().string();

        uint32_t entrySize = static_cast<uint32_t>(sizeof(XBOX_FILE_DIRECTORY_INFORMATION) + name.size());
        // Align to 8 bytes
        uint32_t alignedSize = (entrySize + 7) & ~7u;

        if (offset + alignedSize > infoLength)
            break;

        auto* dirInfo = reinterpret_cast<XBOX_FILE_DIRECTORY_INFORMATION*>(base + infoAddr + offset);
        memset(dirInfo, 0, alignedSize);

        std::error_code ec;
        dirInfo->FileIndex = static_cast<uint32_t>(fh->dirEnumIndex);
        dirInfo->FileAttributes = entry.is_directory(ec)
            ? XBOX_FILE_ATTRIBUTE_DIRECTORY
            : XBOX_FILE_ATTRIBUTE_NORMAL;
        if (!entry.is_directory(ec))
        {
            auto sz = entry.file_size(ec);
            dirInfo->EndOfFile = static_cast<int64_t>(ec ? 0 : sz);
            dirInfo->AllocationSize = dirInfo->EndOfFile;
        }
        dirInfo->FileNameLength = static_cast<uint32_t>(name.size());
        memcpy(reinterpret_cast<char*>(dirInfo) + sizeof(XBOX_FILE_DIRECTORY_INFORMATION),
               name.c_str(), name.size());

        lastEntryOffset = offset;
        dirInfo->NextEntryOffset = alignedSize;
        offset += alignedSize;
        ++fh->dirEnumIndex;
    }

    // Zero out NextEntryOffset on the last entry written.
    if (offset > 0)
    {
        auto* lastEntry = reinterpret_cast<XBOX_FILE_DIRECTORY_INFORMATION*>(base + infoAddr + lastEntryOffset);
        lastEntry->NextEntryOffset = 0;
    }

    if (ioStatusAddr)
    {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = offset;
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 40);
}

// NTSTATUS NtFlushBuffersFile(HANDLE, PIO_STATUS_BLOCK)
// 2 params, 8 bytes
static void Kern_NtFlushBuffersFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle = GuestArg32(ctx, base, 0);
    auto* obj = GetKernelObjectByHandle(handle);
    auto* fh = obj ? dynamic_cast<FileHandle*>(obj) : nullptr;
    if (fh && fh->stream.is_open())
        fh->stream.flush();
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 8);
}

// NTSTATUS NtQueryFullAttributesFile(POBJECT_ATTRIBUTES, PFILE_NETWORK_OPEN_INFORMATION)
// 2 params, 8 bytes
static void Kern_NtQueryFullAttributesFile(X86Context& ctx, uint8_t* base)
{
    uint32_t objAttrAddr = GuestArg32(ctx, base, 0);
    uint32_t infoAddr    = GuestArg32(ctx, base, 1);

    std::string xboxPath = ReadObjectName(base, objAttrAddr);
    std::filesystem::path hostPath = TranslateXboxPath(xboxPath);

    std::error_code ec;
    bool exists = std::filesystem::exists(hostPath, ec);
    if (!exists)
    {
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
        GuestStackCleanup(ctx, 8);
        return;
    }

    auto* info = reinterpret_cast<XBOX_FILE_NETWORK_OPEN_INFORMATION*>(base + infoAddr);
    memset(info, 0, sizeof(*info));
    if (std::filesystem::is_directory(hostPath, ec))
    {
        info->FileAttributes = XBOX_FILE_ATTRIBUTE_DIRECTORY;
    }
    else
    {
        info->FileAttributes = XBOX_FILE_ATTRIBUTE_NORMAL;
        auto sz = std::filesystem::file_size(hostPath, ec);
        if (!ec)
        {
            info->EndOfFile = static_cast<int64_t>(sz);
            info->AllocationSize = static_cast<int64_t>(sz);
        }
    }

    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 8);
}

// NTSTATUS NtQueryVolumeInformationFile(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FS_INFORMATION_CLASS)
// 5 params, 20 bytes
// NTSTATUS NtQueryVolumeInformationFile(HANDLE FileHandle, PIO_STATUS_BLOCK IoStatusBlock,
//   PVOID FsInformation, ULONG Length, FS_INFORMATION_CLASS FsInformationClass)
static void Kern_NtQueryVolumeInformationFile(X86Context& ctx, uint8_t* base)
{
    uint32_t handle         = GuestArg32(ctx, base, 0);
    uint32_t ioStatusAddr   = GuestArg32(ctx, base, 1);
    uint32_t infoAddr       = GuestArg32(ctx, base, 2);
    uint32_t infoLength     = GuestArg32(ctx, base, 3);
    uint32_t infoClass      = GuestArg32(ctx, base, 4);

    // FS_INFORMATION_CLASS values
    constexpr uint32_t FileFsSizeInformation   = 3;
    constexpr uint32_t FileFsDeviceInformation = 4;
    constexpr uint32_t FileFsVolumeInformation = 1;

    fprintf(stderr, "[Kernel] NtQueryVolumeInformationFile: handle=%u class=%u\n",
            handle, infoClass);

    if (infoClass == FileFsSizeInformation && infoAddr && infoLength >= 24) {
        // FILE_FS_SIZE_INFORMATION:
        //   LARGE_INTEGER TotalAllocationUnits;    +0
        //   LARGE_INTEGER AvailableAllocationUnits; +8
        //   ULONG SectorsPerAllocationUnit;        +16
        //   ULONG BytesPerSector;                  +20
        // Emulate a 4GB partition with plenty of free space
        uint64_t totalUnits = 1024 * 1024; // ~4GB with 4K clusters
        uint64_t freeUnits  = 512 * 1024;  // ~2GB free
        memcpy(base + infoAddr + 0,  &totalUnits, 8);
        memcpy(base + infoAddr + 8,  &freeUnits, 8);
        X86_MEM_WRITE_u32(base, infoAddr + 16, 8);    // SectorsPerAllocationUnit
        X86_MEM_WRITE_u32(base, infoAddr + 20, 512);  // BytesPerSector
    } else if (infoAddr && infoLength > 0) {
        // Zero-fill other info classes
        memset(base + infoAddr, 0, infoLength);
    }

    if (ioStatusAddr) {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = 0;
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 20);
}

// LONG FscSetCacheSize(ULONG NumberOfCachePages)
// Sets the file system cache size. Returns the previous cache size.
// No real file system cache in recompiled environment.
static uint32_t g_fscCachePages = 64; // default cache pages
static void Kern_FscSetCacheSize(X86Context& ctx, uint8_t* base)
{
    uint32_t newPages = GuestArg32(ctx, base, 0);
    uint32_t oldPages = g_fscCachePages;
    g_fscCachePages = newPages;
    fprintf(stderr, "[Kernel] FscSetCacheSize(%u) -> old=%u\n", newPages, oldPages);
    GuestReturn32(ctx, oldPages);
    GuestStackCleanup(ctx, 4);
}
// NTSTATUS NtFsControlFile(HANDLE FileHandle, HANDLE Event, PIO_APC_ROUTINE ApcRoutine,
//   PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG FsControlCode,
//   PVOID InputBuffer, ULONG InputBufferLength, PVOID OutputBuffer, ULONG OutputBufferLength)
static void Kern_NtFsControlFile(X86Context& ctx, uint8_t* base)
{
    uint32_t ioStatusAddr = GuestArg32(ctx, base, 4);
    uint32_t fsControlCode = GuestArg32(ctx, base, 5);
    fprintf(stderr, "[Kernel] NtFsControlFile: code=0x%08X\n", fsControlCode);

    if (ioStatusAddr) {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = 0;
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 40);
}

// NTSTATUS NtDeviceIoControlFile(HANDLE FileHandle, HANDLE Event, PIO_APC_ROUTINE ApcRoutine,
//   PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG IoControlCode,
//   PVOID InputBuffer, ULONG InputBufferLength, PVOID OutputBuffer, ULONG OutputBufferLength)
static void Kern_NtDeviceIoControlFile(X86Context& ctx, uint8_t* base)
{
    uint32_t ioStatusAddr = GuestArg32(ctx, base, 4);
    uint32_t ioControlCode = GuestArg32(ctx, base, 5);
    fprintf(stderr, "[Kernel] NtDeviceIoControlFile: code=0x%08X\n", ioControlCode);

    if (ioStatusAddr) {
        auto* io = reinterpret_cast<XBOX_IO_STATUS_BLOCK*>(base + ioStatusAddr);
        io->Status = X_STATUS_SUCCESS;
        io->Information = 0;
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 40);
}

// ---------------------------------------------------------------------------
// String / Rtl functions
// ---------------------------------------------------------------------------

static void Kern_RtlInitUnicodeString(X86Context& ctx, uint8_t* base)
{
    uint32_t destAddr = GuestArg32(ctx, base, 0);
    uint32_t srcAddr  = GuestArg32(ctx, base, 1);
    if (destAddr)
    {
        if (srcAddr)
        {
            uint16_t len = 0;
            while (X86_MEM_READ_u16(base, srcAddr + len * 2) != 0)
                len++;
            uint16_t byteLen = len * 2;
            X86_MEM_WRITE_u16(base, destAddr + 0, byteLen);
            X86_MEM_WRITE_u16(base, destAddr + 2, byteLen + 2);
            X86_MEM_WRITE_u32(base, destAddr + 4, srcAddr);
        }
        else
        {
            X86_MEM_WRITE_u16(base, destAddr + 0, 0);
            X86_MEM_WRITE_u16(base, destAddr + 2, 0);
            X86_MEM_WRITE_u32(base, destAddr + 4, 0);
        }
    }
    GuestStackCleanup(ctx, 8);
}

static void Kern_RtlInitAnsiString(X86Context& ctx, uint8_t* base)
{
    uint32_t destAddr = GuestArg32(ctx, base, 0);
    uint32_t srcAddr  = GuestArg32(ctx, base, 1);
    //fprintf(stderr, "[RtlInitAnsiString] destAddr=0x%08X srcAddr=0x%08X esp=0x%08X\n",
    //        destAddr, srcAddr, ctx.esp);
    if (srcAddr && srcAddr < 0x10000000) {
        const char* s = reinterpret_cast<const char*>(base + srcAddr);
        //fprintf(stderr, "[RtlInitAnsiString]   src=\"%.128s\"\n", s);
    }
    if (destAddr)
    {
        if (srcAddr)
        {
            uint16_t len = 0;
            while (X86_MEM_READ_u8(base, srcAddr + len) != 0)
                len++;
            X86_MEM_WRITE_u16(base, destAddr + 0, len);
            X86_MEM_WRITE_u16(base, destAddr + 2, len + 1);
            X86_MEM_WRITE_u32(base, destAddr + 4, srcAddr);
            //fprintf(stderr, "[RtlInitAnsiString]   -> Len=%u MaxLen=%u Buf=0x%08X\n",
            //        len, len + 1, srcAddr);
        }
        else
        {
            X86_MEM_WRITE_u16(base, destAddr + 0, 0);
            X86_MEM_WRITE_u16(base, destAddr + 2, 0);
            X86_MEM_WRITE_u32(base, destAddr + 4, 0);
            //fprintf(stderr, "[RtlInitAnsiString]   -> zeroed (NULL source)\n");
        }
    }
    GuestStackCleanup(ctx, 8);
}

static void Kern_RtlUnicodeStringToAnsiString(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

static void Kern_RtlAnsiStringToUnicodeString(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// VOID RtlTimeToTimeFields(PLARGE_INTEGER Time, PTIME_FIELDS TimeFields)
// Based on Cxbx-Reloaded / ReactOS implementation.
//
// Converts a 64-bit time value (100-ns ticks since 1 Jan 1601) into
// broken-down fields: Year, Month, Day, Hour, Minute, Second, Millisecond,
// Weekday.
//
// Guest TIME_FIELDS layout (16 bytes):
//   +0x00  USHORT Year
//   +0x02  USHORT Month       (1..12)
//   +0x04  USHORT Day         (1..31)
//   +0x06  USHORT Hour        (0..23)
//   +0x08  USHORT Minute      (0..59)
//   +0x0A  USHORT Second      (0..59)
//   +0x0C  USHORT Millisecond (0..999)
//   +0x0E  USHORT Weekday     (0=Sunday)
static void Kern_RtlTimeToTimeFields(X86Context& ctx, uint8_t* base)
{
    uint32_t pTime       = GuestArg32(ctx, base, 0);
    uint32_t pTimeFields = GuestArg32(ctx, base, 1);

    if (!pTime || !pTimeFields) {
        GuestStackCleanup(ctx, 8);
        return;
    }

    // Read the 64-bit time (100-ns intervals since 1 Jan 1601)
    uint64_t time100ns = (uint64_t)X86_MEM_READ_u32(base, pTime)
                       | ((uint64_t)X86_MEM_READ_u32(base, pTime + 4) << 32);

    // Convert to milliseconds
    int64_t totalMs = (int64_t)(time100ns / 10000ULL);

    static constexpr int64_t MSPERDAY    = 86400000LL;
    static constexpr int     SECSPERMIN  = 60;
    static constexpr int     MINSPERHOUR = 60;
    static constexpr int     MSECSPERSEC = 1000;
    static constexpr int     DAYSPERWEEK = 7;
    // Epoch weekday: 1 Jan 1601 was a Monday (1)
    static constexpr int     EPOCHWEEKDAY = 1;
    static constexpr int     DAYSPERNORMALQUADRENNIUM = 1461;
    static constexpr int     DAYSPERQUADRICENTENNIUM  = 146097;

    int64_t days = totalMs / MSPERDAY;
    int64_t msInDay = totalMs - days * MSPERDAY;
    if (msInDay < 0) { msInDay += MSPERDAY; days--; }

    // Time of day
    uint16_t millisecond = (uint16_t)(msInDay % MSECSPERSEC);
    uint32_t remSec = (uint32_t)(msInDay / MSECSPERSEC);
    uint16_t second = (uint16_t)(remSec % SECSPERMIN);
    remSec /= SECSPERMIN;
    uint16_t minute = (uint16_t)(remSec % MINSPERHOUR);
    uint16_t hour   = (uint16_t)(remSec / MINSPERHOUR);

    // Day of week
    uint16_t weekday = (uint16_t)(((int64_t)EPOCHWEEKDAY + days) % DAYSPERWEEK);
    if (weekday < 0) weekday += DAYSPERWEEK;

    // Year, month, day (algorithm from ReactOS / Cxbx)
    int64_t cleaps = (3 * ((4 * days + 1227) / DAYSPERQUADRICENTENNIUM) + 3) / 4;
    days += 28188 + cleaps;
    int64_t years = (20 * days - 2442) / (5 * DAYSPERNORMALQUADRENNIUM);
    int64_t yearday = days - (years * DAYSPERNORMALQUADRENNIUM) / 4;
    int64_t months = (64 * yearday) / 1959;

    uint16_t year, month, day;
    if (months < 14) {
        month = (uint16_t)(months - 1);
        year  = (uint16_t)(years + 1524);
    } else {
        month = (uint16_t)(months - 13);
        year  = (uint16_t)(years + 1525);
    }
    day = (uint16_t)(yearday - (1959 * months) / 64);

    // Write TIME_FIELDS
    X86_MEM_WRITE_u16(base, pTimeFields + 0x00, year);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x02, month);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x04, day);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x06, hour);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x08, minute);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x0A, second);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x0C, millisecond);
    X86_MEM_WRITE_u16(base, pTimeFields + 0x0E, weekday);

    GuestStackCleanup(ctx, 8);
}

KERNEL_STUB_CLEANUP(RtlTimeFieldsToTime, 8)
// ULONG RtlNtStatusToDosError(NTSTATUS Status)
static void Kern_RtlNtStatusToDosError(X86Context& ctx, uint8_t* base)
{
    uint32_t status = GuestArg32(ctx, base, 0);
    uint32_t dosError = 0;
    // Map common NTSTATUS codes to Win32 error codes
    switch (status) {
    case 0x00000000: dosError = 0; break;    // STATUS_SUCCESS -> ERROR_SUCCESS
    case 0xC0000002: dosError = 1; break;    // STATUS_NOT_IMPLEMENTED -> ERROR_INVALID_FUNCTION
    case 0xC0000005: dosError = 998; break;  // STATUS_ACCESS_VIOLATION -> ERROR_NOACCESS
    case 0xC0000008: dosError = 6; break;    // STATUS_INVALID_HANDLE -> ERROR_INVALID_HANDLE
    case 0xC000000D: dosError = 87; break;   // STATUS_INVALID_PARAMETER -> ERROR_INVALID_PARAMETER
    case 0xC000000F: dosError = 2; break;    // STATUS_NO_SUCH_FILE -> ERROR_FILE_NOT_FOUND
    case 0xC0000011: dosError = 38; break;   // STATUS_END_OF_FILE -> ERROR_HANDLE_EOF
    case 0xC0000017: dosError = 8; break;    // STATUS_NO_MEMORY -> ERROR_NOT_ENOUGH_MEMORY
    case 0xC0000034: dosError = 2; break;    // STATUS_OBJECT_NAME_NOT_FOUND -> ERROR_FILE_NOT_FOUND
    case 0xC0000035: dosError = 183; break;  // STATUS_OBJECT_NAME_COLLISION -> ERROR_ALREADY_EXISTS
    case 0xC000003A: dosError = 3; break;    // STATUS_OBJECT_PATH_NOT_FOUND -> ERROR_PATH_NOT_FOUND
    case 0xC000007F: dosError = 112; break;  // STATUS_DISK_FULL -> ERROR_DISK_FULL
    case 0x80000005: dosError = 234; break;  // STATUS_BUFFER_OVERFLOW -> ERROR_MORE_DATA
    case 0x80000006: dosError = 18; break;   // STATUS_NO_MORE_FILES -> ERROR_NO_MORE_FILES
    default: dosError = (status & 0xFFFF); break; // Fallback: use low 16 bits
    }
    GuestReturn32(ctx, dosError);
    GuestStackCleanup(ctx, 4);
}

// BOOLEAN RtlEqualString(PSTRING String1, PSTRING String2, BOOLEAN CaseInSensitive)
static void Kern_RtlEqualString(X86Context& ctx, uint8_t* base)
{
    uint32_t str1Addr = GuestArg32(ctx, base, 0);
    uint32_t str2Addr = GuestArg32(ctx, base, 1);
    uint32_t caseInsensitive = GuestArg32(ctx, base, 2);

    auto* s1 = reinterpret_cast<const XBOX_ANSI_STRING*>(base + str1Addr);
    auto* s2 = reinterpret_cast<const XBOX_ANSI_STRING*>(base + str2Addr);

    uint32_t result = 0; // FALSE
    if (s1->Length == s2->Length) {
        const char* p1 = reinterpret_cast<const char*>(base + s1->Buffer);
        const char* p2 = reinterpret_cast<const char*>(base + s2->Buffer);
        if (caseInsensitive) {
            result = (_strnicmp(p1, p2, s1->Length) == 0) ? 1 : 0;
        } else {
            result = (memcmp(p1, p2, s1->Length) == 0) ? 1 : 0;
        }
    }
    GuestReturn32(ctx, result);
    GuestStackCleanup(ctx, 12);
}

// ULONG RtlCompareMemoryUlong(PVOID Source, ULONG Length, ULONG Pattern)
// Returns the number of bytes (rounded to ULONG granularity) that matched
// the given pattern, stopping at the first mismatch.
static void Kern_RtlCompareMemoryUlong(X86Context& ctx, uint8_t* base)
{
    uint32_t srcAddr = GuestArg32(ctx, base, 0);
    uint32_t length  = GuestArg32(ctx, base, 1);
    uint32_t pattern = GuestArg32(ctx, base, 2);

    uint32_t matched = 0;
    uint32_t count = length / 4; // compare in ULONG units
    for (uint32_t i = 0; i < count; i++)
    {
        uint32_t val = X86_MEM_READ_u32(base, srcAddr + i * 4);
        if (val != pattern)
            break;
        matched += 4;
    }

    GuestReturn32(ctx, matched);
    GuestStackCleanup(ctx, 12);
}

KERNEL_STUB_CLEANUP(RtlRaiseException, 4)
KERNEL_STUB_CLEANUP(RtlUnwind, 16)

static void Kern_RtlInitializeCriticalSection(X86Context& ctx, uint8_t* base)
{
    uint32_t csAddr = GuestArg32(ctx, base, 0);
    if (csAddr)
    {
        // RTL_CRITICAL_SECTION layout (0x1C = 28 bytes):
        //   +0x00 DISPATCHER_HEADER Event (16 bytes)
        //   +0x10 LockCount       (LONG, -1 = unlocked)
        //   +0x14 RecursionCount   (LONG, 0)
        //   +0x18 OwningThread     (HANDLE, 0)
        memset(g_memory.Translate(csAddr), 0, 28);

        // Initialize DISPATCHER_HEADER as a synchronization event
        X86_MEM_WRITE_u8(base, csAddr + 0x00, 1);  // Type = EventSynchronizationObject
        X86_MEM_WRITE_u8(base, csAddr + 0x02, 4);  // Size = sizeof(DISPATCHER_HEADER)/sizeof(ULONG)
        X86_MEM_WRITE_u32(base, csAddr + 0x04, 0);  // SignalState = 0
        // WaitListHead â€” self-referencing empty list
        X86_MEM_WRITE_u32(base, csAddr + 0x08, csAddr + 0x08);
        X86_MEM_WRITE_u32(base, csAddr + 0x0C, csAddr + 0x08);

        // LockCount = -1 (unlocked)
        X86_MEM_WRITE_u32(base, csAddr + 0x10, 0xFFFFFFFF);

        // Pre-create the mutex so subsequent Enter/Leave use a real lock.
        QueryKernelObject<Mutex>(base, csAddr);
    }
    GuestStackCleanup(ctx, 4);
}

static void Kern_RtlLeaveCriticalSection(X86Context& ctx, uint8_t* base)
{
    uint32_t csAddr = GuestArg32(ctx, base, 0);
    auto* m = QueryKernelObject<Mutex>(base, csAddr);
    if (m) m->Unlock();
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// Synchronization (additional)
// ---------------------------------------------------------------------------

static void Kern_NtCreateSemaphore(X86Context& ctx, uint8_t* base)
{
    uint32_t handlePtr    = GuestArg32(ctx, base, 0);
    uint32_t initialCount = GuestArg32(ctx, base, 2);
    uint32_t maximumCount = GuestArg32(ctx, base, 3);
    uint32_t handle = CreateKernelHandle<Semaphore>(initialCount, maximumCount);
    if (handlePtr)
        X86_MEM_WRITE_u32(base, handlePtr, handle);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

static void Kern_NtSetEvent(X86Context& ctx, uint8_t* base)
{
    uint32_t handle      = GuestArg32(ctx, base, 0);
    uint32_t prevStatePtr = GuestArg32(ctx, base, 1);
    auto* evt = static_cast<Event*>(GetKernelObjectByHandle(handle));
    if (evt) evt->Set();
    if (prevStatePtr)
        X86_MEM_WRITE_u32(base, prevStatePtr, 0);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

KERNEL_STUB_CLEANUP(NtPulseEvent, 8)

// KeResetEvent
static void Kern_KeResetEvent(X86Context& ctx, uint8_t* base)
{
    uint32_t objAddr = GuestArg32(ctx, base, 0);
    auto* evt = QueryKernelObject<Event>(base, objAddr, /*manual=*/true, /*initial=*/false);
    if (evt) evt->Reset();
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

static void Kern_NtReleaseSemaphore(X86Context& ctx, uint8_t* base)
{
    uint32_t handle       = GuestArg32(ctx, base, 0);
    uint32_t releaseCount = GuestArg32(ctx, base, 1);
    uint32_t prevCountPtr = GuestArg32(ctx, base, 2);
    auto* sem = static_cast<Semaphore*>(GetKernelObjectByHandle(handle));
    int32_t prev = 0;
    if (sem) prev = sem->Release(releaseCount);
    if (prevCountPtr)
        X86_MEM_WRITE_u32(base, prevCountPtr, static_cast<uint32_t>(prev));
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

static void Kern_NtReleaseMutant(X86Context& ctx, uint8_t* base)
{
    uint32_t handle      = GuestArg32(ctx, base, 0);
    uint32_t prevCountPtr = GuestArg32(ctx, base, 1);
    auto* m = static_cast<Mutex*>(GetKernelObjectByHandle(handle));
    if (m) m->Unlock();
    if (prevCountPtr)
        X86_MEM_WRITE_u32(base, prevCountPtr, 1);
    GuestReturn32(ctx, 1);
    GuestStackCleanup(ctx, 8);
}

static void Kern_NtWaitForSingleObject(X86Context& ctx, uint8_t* base)
{
    uint32_t handle     = GuestArg32(ctx, base, 0);
    uint32_t timeoutPtr = GuestArg32(ctx, base, 2);
    uint32_t timeoutMs  = UINT32_MAX;
    if (timeoutPtr)
    {
        int64_t t = static_cast<int64_t>(X86_MEM_READ_u32(base, timeoutPtr)) |
                    (static_cast<int64_t>(X86_MEM_READ_u32(base, timeoutPtr + 4)) << 32);
        if (t < 0) timeoutMs = static_cast<uint32_t>((-t) / 10000);
        else if (t == 0) timeoutMs = 0;
    }
    auto* obj = GetKernelObjectByHandle(handle);
    if (obj) obj->Wait(timeoutMs);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

static void Kern_NtWaitForSingleObjectEx(X86Context& ctx, uint8_t* base)
{
    uint32_t handle     = GuestArg32(ctx, base, 0);
    uint32_t timeoutPtr = GuestArg32(ctx, base, 3);
    uint32_t timeoutMs  = UINT32_MAX;
    if (timeoutPtr)
    {
        int64_t t = static_cast<int64_t>(X86_MEM_READ_u32(base, timeoutPtr)) |
                    (static_cast<int64_t>(X86_MEM_READ_u32(base, timeoutPtr + 4)) << 32);
        if (t < 0) timeoutMs = static_cast<uint32_t>((-t) / 10000);
        else if (t == 0) timeoutMs = 0;
    }
    auto* obj = GetKernelObjectByHandle(handle);
    if (obj) obj->Wait(timeoutMs);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

static void Kern_KeSetEvent(X86Context& ctx, uint8_t* base)
{
    uint32_t objAddr = GuestArg32(ctx, base, 0);
    auto* evt = QueryKernelObject<Event>(base, objAddr, /*manual=*/true, /*initial=*/false);
    // Previous state: we return 0 (not previously signaled) for simplicity.
    if (evt) evt->Set();
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

static void Kern_KeWaitForMultipleObjects(X86Context& ctx, uint8_t* base)
{
    uint32_t count     = GuestArg32(ctx, base, 0);
    uint32_t objsPtr   = GuestArg32(ctx, base, 1);
    uint32_t waitType  = GuestArg32(ctx, base, 2); // 0=WaitAll, 1=WaitAny
    uint32_t timeoutPtr = GuestArg32(ctx, base, 7);
    //fprintf(stderr, "[KeWaitForMultipleObjects] count=%u objsPtr=0x%08X waitType=%u timeoutPtr=0x%08X esp=0x%08X\n",
    //        count, objsPtr, waitType, timeoutPtr, ctx.esp);

    uint32_t timeoutMs = UINT32_MAX;
    if (timeoutPtr)
    {
        int64_t t = static_cast<int64_t>(X86_MEM_READ_u32(base, timeoutPtr)) |
                    (static_cast<int64_t>(X86_MEM_READ_u32(base, timeoutPtr + 4)) << 32);
        if (t < 0) timeoutMs = static_cast<uint32_t>((-t) / 10000);
        else if (t == 0) timeoutMs = 0;
    }

    if (count > 64) count = 64;

#ifdef _WIN32
    // Collect native HANDLEs for real WaitForMultipleObjects.
    HANDLE handles[64];
    bool allNative = true;
    for (uint32_t i = 0; i < count; i++)
    {
        uint32_t objAddr = X86_MEM_READ_u32(base, objsPtr + i * 4);
        KernelObject* obj = ResolveDispatcherObject(base, objAddr);
        HANDLE h = obj ? obj->GetNativeHandle() : INVALID_HANDLE_VALUE;
        if (h == INVALID_HANDLE_VALUE)
        {
            allNative = false;
            break;
        }
        handles[i] = h;
    }

    if (allNative && count > 0)
    {
        DWORD ms = (timeoutMs == UINT32_MAX) ? INFINITE : static_cast<DWORD>(timeoutMs);
        BOOL waitAll = (waitType == 0) ? TRUE : FALSE;
        DWORD result = WaitForMultipleObjects(count, handles, waitAll, ms);

        if (result >= WAIT_OBJECT_0 && result < WAIT_OBJECT_0 + count)
            GuestReturn32(ctx, result - WAIT_OBJECT_0);
        else if (result == WAIT_TIMEOUT)
            GuestReturn32(ctx, 0x00000102); // STATUS_TIMEOUT
        else
            GuestReturn32(ctx, 0);

        GuestStackCleanup(ctx, 32);
        return;
    }
#endif

    // Fallback: sequential wait.
    if (waitType == 1) // WaitAny
    {
        for (uint32_t i = 0; i < count; i++)
        {
            uint32_t objAddr = X86_MEM_READ_u32(base, objsPtr + i * 4);
            KernelObject* obj = ResolveDispatcherObject(base, objAddr);
            if (obj && obj->Wait(0))
            {
                GuestReturn32(ctx, i);
                GuestStackCleanup(ctx, 32);
                return;
            }
        }
        std::this_thread::yield();
        GuestReturn32(ctx, 0);
    }
    else // WaitAll
    {
        for (uint32_t i = 0; i < count; i++)
        {
            uint32_t objAddr = X86_MEM_READ_u32(base, objsPtr + i * 4);
            KernelObject* obj = ResolveDispatcherObject(base, objAddr);
            if (obj) obj->Wait(timeoutMs);
        }
        GuestReturn32(ctx, 0);
    }
    GuestStackCleanup(ctx, 32);
}

static void Kern_KeDelayExecutionThread(X86Context& ctx, uint8_t* base)
{
    uint32_t intervalPtr = GuestArg32(ctx, base, 2);
    //fprintf(stderr, "[KeDelayExecutionThread] intervalPtr=0x%08X esp=0x%08X\n", intervalPtr, ctx.esp);
    if (intervalPtr)
    {
        // Sign-extend lo DWORD as int32 so 0xFFFFCBE0 â†’ -13344 (negative = relative wait)
        // rather than +4294867296 (positive = no sleep, causing 100% CPU spin).
        int32_t i_lo = static_cast<int32_t>(X86_MEM_READ_u32(base, intervalPtr));
        int32_t i_hi = static_cast<int32_t>(X86_MEM_READ_u32(base, intervalPtr + 4));
        int64_t interval = static_cast<int64_t>(i_lo) | (static_cast<int64_t>(i_hi) << 32);
        if (interval < 0)
        {
            uint32_t ms = static_cast<uint32_t>((-interval) / 10000);
            // Cap short polling sleeps (≤50ms) to 1ms to avoid audio/video thread
            // stalls. The RWA audio service thread calls Sleep(50) in its poll loop,
            // causing ~25ms overhead per frame and dropping fps to ~31.
            if (ms <= 50)
                ms = 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
    }
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// BOOLEAN KeCancelTimer(PKTIMER Timer)
static void Kern_KeCancelTimer(X86Context& ctx, uint8_t* base)
{
    uint32_t timerAddr = GuestArg32(ctx, base, 0);

    std::lock_guard<std::mutex> lock(g_timerLock);
    bool wasInserted = false;

    for (auto& t : g_timers)
    {
        if (t.guestTimerAddr == timerAddr && t.inserted)
        {
            t.inserted = false;
            wasInserted = true;
            break;
        }
    }

    // Update guest memory
    X86_MEM_WRITE_u8(base, timerAddr + 0x03, 0);  // Header.Inserted = FALSE

    GuestReturn32(ctx, wasInserted ? 1 : 0);
    GuestStackCleanup(ctx, 4);
}

// Shared implementation for KeSetTimer / KeSetTimerEx.
static bool Kern_KeSetTimerImpl(X86Context& ctx, uint8_t* base,
                                uint32_t timerAddr, int64_t dueTime,
                                int32_t period, uint32_t dpcAddr)
{
    if (timerAddr >= X86_RAM_SIZE - 0x28)
    {
        fprintf(stderr, "[KERN] KeSetTimer: timerAddr 0x%08X out of range, ignoring\n", timerAddr);
        return false;
    }

    StartTimerThread();

    std::lock_guard<std::mutex> lock(g_timerLock);

    // Cancel if already inserted
    bool wasInserted = false;
    HostTimer* ht = nullptr;
    for (auto& t : g_timers)
    {
        if (t.guestTimerAddr == timerAddr)
        {
            if (t.inserted)
                wasInserted = true;
            ht = &t;
            break;
        }
    }
    if (!ht)
    {
        g_timers.push_back({timerAddr, 0, 0, 0, false});
        ht = &g_timers.back();
    }

    // Compute absolute due time in 100-ns ticks since boot
    uint64_t now = GetInterruptTimeTicks();
    uint64_t absDueTime;
    if (dueTime >= 0)
    {
        // Absolute time â€” use directly (relative to system boot)
        absDueTime = static_cast<uint64_t>(dueTime);
    }
    else
    {
        // Relative time (negative = offset from now)
        absDueTime = now + static_cast<uint64_t>(-dueTime);
    }

    // Update guest KTIMER fields
    X86_MEM_WRITE_u32(base, timerAddr + 0x10, static_cast<uint32_t>(absDueTime));
    X86_MEM_WRITE_u32(base, timerAddr + 0x14, static_cast<uint32_t>(absDueTime >> 32));
    X86_MEM_WRITE_u32(base, timerAddr + 0x20, dpcAddr);
    X86_MEM_WRITE_u32(base, timerAddr + 0x24, static_cast<uint32_t>(period));

    // If already expired, signal immediately
    if (absDueTime <= now)
    {
        X86_MEM_WRITE_u8 (base, timerAddr + 0x03, 0); // Inserted = FALSE
        X86_MEM_WRITE_u32(base, timerAddr + 0x04, 1); // SignalState = TRUE

        ht->inserted = false;
        ht->dueTimeAbsolute = absDueTime;
        ht->guestDpcAddr = dpcAddr;
        ht->periodMs = period;

        // If periodic, reschedule
        if (period > 0)
        {
            ht->dueTimeAbsolute = now + static_cast<uint64_t>(period) * 10000ULL;
            ht->inserted = true;
            X86_MEM_WRITE_u8(base, timerAddr + 0x03, 1);  // Inserted = TRUE
            X86_MEM_WRITE_u32(base, timerAddr + 0x04, 0); // SignalState = FALSE
        }
    }
    else
    {
        // Not yet expired â€” insert into timer tracking
        X86_MEM_WRITE_u8 (base, timerAddr + 0x03, 1); // Inserted = TRUE
        X86_MEM_WRITE_u32(base, timerAddr + 0x04, 0); // SignalState = FALSE

        ht->dueTimeAbsolute = absDueTime;
        ht->guestDpcAddr = dpcAddr;
        ht->periodMs = period;
        ht->inserted = true;
    }

    g_timerCv.notify_one();
    return wasInserted;
}

// BOOLEAN KeSetTimerEx(PKTIMER Timer, LARGE_INTEGER DueTime, LONG Period, PKDPC Dpc)
static void Kern_KeSetTimerEx(X86Context& ctx, uint8_t* base)
{
    uint32_t timerAddr = GuestArg32(ctx, base, 0);
    uint32_t dueTimeLo = GuestArg32(ctx, base, 1);
    uint32_t dueTimeHi = GuestArg32(ctx, base, 2);
    int32_t  period    = static_cast<int32_t>(GuestArg32(ctx, base, 3));
    uint32_t dpcAddr   = GuestArg32(ctx, base, 4);

    int64_t dueTime = static_cast<int64_t>((static_cast<uint64_t>(dueTimeHi) << 32) | dueTimeLo);

    bool wasInserted = Kern_KeSetTimerImpl(ctx, base, timerAddr, dueTime, period, dpcAddr);

    GuestReturn32(ctx, wasInserted ? 1 : 0);
    GuestStackCleanup(ctx, 20);
}

// BOOLEAN KeSetTimer(PKTIMER Timer, LARGE_INTEGER DueTime, PKDPC Dpc)
static void Kern_KeSetTimer(X86Context& ctx, uint8_t* base)
{
    uint32_t timerAddr = GuestArg32(ctx, base, 0);
    uint32_t dueTimeLo = GuestArg32(ctx, base, 1);
    uint32_t dueTimeHi = GuestArg32(ctx, base, 2);
    uint32_t dpcAddr   = GuestArg32(ctx, base, 3);

    int64_t dueTime = static_cast<int64_t>((static_cast<uint64_t>(dueTimeHi) << 32) | dueTimeLo);

    bool wasInserted = Kern_KeSetTimerImpl(ctx, base, timerAddr, dueTime, 0, dpcAddr);

    GuestReturn32(ctx, wasInserted ? 1 : 0);
    GuestStackCleanup(ctx, 16);  // KeSetTimer has 4 args = 16 bytes
}

// LONG KeSetBasePriorityThread(PKTHREAD Thread, LONG Increment)
// Thread is an opaque handle value written by ObReferenceObjectByHandle.
static void Kern_KeSetBasePriorityThread(X86Context& ctx, uint8_t* base)
{
    uint32_t threadHandle = GuestArg32(ctx, base, 0);
    int32_t  increment    = static_cast<int32_t>(GuestArg32(ctx, base, 1));

    auto* obj = GetKernelObjectByHandle(threadHandle);
    if (auto* gt = dynamic_cast<GuestThread*>(obj))
    {
#ifdef _WIN32
        int winPriority;
        if      (increment >= 2)  winPriority = THREAD_PRIORITY_HIGHEST;
        else if (increment == 1)  winPriority = THREAD_PRIORITY_ABOVE_NORMAL;
        else if (increment == 0)  winPriority = THREAD_PRIORITY_NORMAL;
        else if (increment == -1) winPriority = THREAD_PRIORITY_BELOW_NORMAL;
        else                      winPriority = THREAD_PRIORITY_LOWEST;
        SetThreadPriority(gt->thread.native_handle(), winPriority);
#endif
    }

    GuestReturn32(ctx, 0); // return previous base priority
    GuestStackCleanup(ctx, 8);
}

// ---------------------------------------------------------------------------
// IRQL
// ---------------------------------------------------------------------------

static void Kern_KfLowerIrql(X86Context& ctx, uint8_t* base)
{
    // Fastcall: new IRQL in cl.  Write to KPCR.Irql (fs:[0x24]).
    X86_MEM_WRITE_u8(base, 0x24, static_cast<uint8_t>(ctx.ecx & 0xFF));
}

static void Kern_KeRaiseIrqlToDpcLevel(X86Context& ctx, uint8_t* base)
{
    ctx.eax = X86_MEM_READ_u8(base, 0x24); // return old IRQL
    X86_MEM_WRITE_u8(base, 0x24, 2);        // DISPATCH_LEVEL
}

static void Kern_KfRaiseIrql(X86Context& ctx, uint8_t* base)
{
    ctx.eax = X86_MEM_READ_u8(base, 0x24); // return old IRQL
    X86_MEM_WRITE_u8(base, 0x24, static_cast<uint8_t>(ctx.ecx & 0xFF));
}

// ---------------------------------------------------------------------------
// Timing (additional)
// ---------------------------------------------------------------------------

static void Kern_KeQuerySystemTime(X86Context& ctx, uint8_t* base)
{
    uint32_t outPtr = GuestArg32(ctx, base, 0);
    auto now = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(now - g_bootTime).count();
    uint64_t winTime = 116444736000000000ULL + static_cast<uint64_t>(us) * 10;
    if (outPtr)
    {
        X86_MEM_WRITE_u32(base, outPtr + 0, static_cast<uint32_t>(winTime));
        X86_MEM_WRITE_u32(base, outPtr + 4, static_cast<uint32_t>(winTime >> 32));
    }
    GuestStackCleanup(ctx, 4);
}

static void Kern_KeQueryInterruptTime(X86Context& ctx, uint8_t* base)
{
    auto now = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(now - g_bootTime).count();
    uint64_t val = static_cast<uint64_t>(us) * 10; // 100ns units
    ctx.eax = static_cast<uint32_t>(val);
    ctx.edx = static_cast<uint32_t>(val >> 32);
}

// ---------------------------------------------------------------------------
// Object manager
// ---------------------------------------------------------------------------

static void Kern_ObfDereferenceObject(X86Context& ctx, uint8_t* base)
{
    // Fastcall: object in ecx â€” no stack cleanup needed.
}

// NTSTATUS ObReferenceObjectByHandle(HANDLE Handle, POBJECT_TYPE ObjectType, PVOID *Object)
// Writes the handle value into *Object as an opaque kernel-object token.  The
// caller (e.g. KeSetBasePriorityThread) passes it back to us, and we treat it
// as a handle again.  This works because our handles (small integers) never
// overlap valid guest memory addresses.
static void Kern_ObReferenceObjectByHandle(X86Context& ctx, uint8_t* base)
{
    uint32_t handle    = GuestArg32(ctx, base, 0);
    // arg1 = ObjectType (ignored -- no type checking needed)
    uint32_t objectPtr = GuestArg32(ctx, base, 2); // PVOID* output

    KernelObject* obj = GetKernelObjectByHandle(handle);
    if (obj && objectPtr)
    {
        X86_MEM_WRITE_u32(base, objectPtr, handle);
        GuestReturn32(ctx, 0); // STATUS_SUCCESS
    }
    else
    {
        GuestReturn32(ctx, 0xC0000008UL); // STATUS_INVALID_HANDLE
    }
    GuestStackCleanup(ctx, 12);
}

// ---------------------------------------------------------------------------
// Memory management (additional)
// ---------------------------------------------------------------------------

static void Kern_ExAllocatePoolWithTag(X86Context& ctx, uint8_t* base)
{
    uint32_t size = GuestArg32(ctx, base, 0);
    uint32_t addr = g_heap.AllocGuest(size);
    if (addr)
        memset(g_memory.Translate(addr), 0, size);
    GuestReturn32(ctx, addr);
    GuestStackCleanup(ctx, 8);
}

static void Kern_ExFreePool(X86Context& ctx, uint8_t* base)
{
    uint32_t addr = GuestArg32(ctx, base, 0);
    g_heap.FreeGuest(addr);
    GuestStackCleanup(ctx, 4);
}

static void Kern_MmAllocateSystemMemory(X86Context& ctx, uint8_t* base)
{
    uint32_t size = GuestArg32(ctx, base, 0);
    uint32_t addr = g_heap.AllocGuestAligned(size, 4096);
    if (addr)
        memset(g_memory.Translate(addr), 0, size);
    GuestReturn32(ctx, addr);
    GuestStackCleanup(ctx, 8);
}

static void Kern_MmFreeSystemMemory(X86Context& ctx, uint8_t* base)
{
    uint32_t addr = GuestArg32(ctx, base, 0);
    g_heap.FreeGuest(addr);
    GuestStackCleanup(ctx, 8);
}

static void Kern_NtAllocateVirtualMemory(X86Context& ctx, uint8_t* base)
{
    uint32_t baseAddrPtr = GuestArg32(ctx, base, 0);
    uint32_t sizePtr     = GuestArg32(ctx, base, 2);
    uint32_t allocType   = GuestArg32(ctx, base, 3);
    uint32_t reqSize     = sizePtr ? X86_MEM_READ_u32(base, sizePtr) : 4096;

    if (reqSize == 0) reqSize = 4096;

    // Check if the caller already supplies a base address (MEM_COMMIT on
    // previously MEM_RESERVE'd region).
    uint32_t existingBase = baseAddrPtr ? X86_MEM_READ_u32(base, baseAddrPtr) : 0;

    // MEM_COMMIT (0x1000) without MEM_RESERVE (0x2000) on an existing address:
    // the memory is already backed by real RAM in our bump allocator, so just
    // succeed without allocating again.
    if ((allocType & 0x3000) == 0x1000 && existingBase != 0)
    {
        //fprintf(stderr, "[GuestVM] NtAllocateVirtualMemory: MEM_COMMIT on existing 0x%08X (size=%u) — no-op\n",
        //        existingBase, reqSize);
        GuestReturn32(ctx, 0); // STATUS_SUCCESS
        GuestStackCleanup(ctx, 20);
        return;
    }

    uint32_t addr = GuestVMAlloc(reqSize, 4096, base);
    fprintf(stderr, "[GuestVM] NtAllocateVirtualMemory: size=%u type=0x%04X -> addr=0x%08X%s\n",
            reqSize, allocType, addr, addr ? "" : " FAILED");
    if (addr)
    {
        if (baseAddrPtr)
            X86_MEM_WRITE_u32(base, baseAddrPtr, addr);
        if (sizePtr)
            X86_MEM_WRITE_u32(base, sizePtr, reqSize);
    }
    GuestReturn32(ctx, addr ? 0 : 0xC0000017); // STATUS_NO_MEMORY
    GuestStackCleanup(ctx, 20); // Xbox: 5 args (no ProcessHandle)
}

static void Kern_NtFreeVirtualMemory(X86Context& ctx, uint8_t* base)
{
    uint32_t baseAddrPtr = GuestArg32(ctx, base, 0);
    if (baseAddrPtr)
    {
        uint32_t addr = X86_MEM_READ_u32(base, baseAddrPtr);
        GuestVMFree(addr);
    }
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12); // Xbox: 3 args (no ProcessHandle)
}

KERNEL_STUB_CLEANUP(MmQueryAddressProtect, 4)
// PHYSICAL_ADDRESS MmGetPhysicalAddress(PVOID BaseAddress)
// On OG Xbox virtual == physical for most allocations; return address as-is.
static void Kern_MmGetPhysicalAddress(X86Context& ctx, uint8_t* base)
{
    uint32_t addr = GuestArg32(ctx, base, 0);
    GuestReturn32(ctx, addr); // identity mapping
    GuestStackCleanup(ctx, 4);
}

KERNEL_STUB_CLEANUP(MmLockUnlockBufferPages, 12)
KERNEL_STUB_CLEANUP(MmLockUnlockPhysicalPage, 8)
KERNEL_STUB_CLEANUP(MmClaimGpuInstanceMemory, 8)

// NTSTATUS MmQueryStatistics(PMM_STATISTICS MemoryStatistics)
// MM_STATISTICS layout (9 DWORDs = 36 bytes):
//   +0x00 Length
//   +0x04 TotalPhysicalPages
//   +0x08 AvailablePages
//   +0x0C VirtualMemoryBytesCommitted
//   +0x10 VirtualMemoryBytesReserved
//   +0x14 CachePagesCommitted
//   +0x18 PoolPagesCommitted
//   +0x1C StackPagesCommitted
//   +0x20 ImagePagesCommitted
static void Kern_MmQueryStatistics(X86Context& ctx, uint8_t* base)
{
    uint32_t statsAddr = GuestArg32(ctx, base, 0);
    if (!statsAddr)
    {
        GuestReturn32(ctx, 0xC000000D); // STATUS_INVALID_PARAMETER
        GuestStackCleanup(ctx, 4);
        return;
    }

    uint32_t length = X86_MEM_READ_u32(base, statsAddr + 0x00);
    if (length != 36) // sizeof(MM_STATISTICS)
    {
        GuestReturn32(ctx, 0xC000000D); // STATUS_INVALID_PARAMETER
        GuestStackCleanup(ctx, 4);
        return;
    }

    // Xbox has 64 MB RAM = 16384 pages (4 KB each)
    constexpr uint32_t kPageSize         = 4096;
    constexpr uint32_t kTotalPages       = 64 * 1024 * 1024 / kPageSize; // 16384
    constexpr uint32_t kAvailablePages   = kTotalPages / 2;              // report ~50% free

    X86_MEM_WRITE_u32(base, statsAddr + 0x00, 36);                        // Length
    X86_MEM_WRITE_u32(base, statsAddr + 0x04, kTotalPages);               // TotalPhysicalPages
    X86_MEM_WRITE_u32(base, statsAddr + 0x08, kAvailablePages);           // AvailablePages
    X86_MEM_WRITE_u32(base, statsAddr + 0x0C, 0);                         // VirtualMemoryBytesCommitted
    X86_MEM_WRITE_u32(base, statsAddr + 0x10, 0);                         // VirtualMemoryBytesReserved
    X86_MEM_WRITE_u32(base, statsAddr + 0x14, 0);                         // CachePagesCommitted
    X86_MEM_WRITE_u32(base, statsAddr + 0x18, 0);                         // PoolPagesCommitted
    X86_MEM_WRITE_u32(base, statsAddr + 0x1C, 0);                         // StackPagesCommitted
    X86_MEM_WRITE_u32(base, statsAddr + 0x20, 0);                         // ImagePagesCommitted

    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 4);
}
KERNEL_STUB_CLEANUP(NtQueryVirtualMemory, 24)
// ULONG ExQueryPoolBlockSize(PVOID PoolBlock, PBOOLEAN QuotaCharged)
// Returns the size of the pool block. QuotaCharged is always FALSE on Xbox.
static void Kern_ExQueryPoolBlockSize(X86Context& ctx, uint8_t* base)
{
    uint32_t poolBlock    = GuestArg32(ctx, base, 0);
    uint32_t quotaChargedAddr = GuestArg32(ctx, base, 1);

    size_t blockSize = g_heap.QuerySize(poolBlock);
    fprintf(stderr, "[Kernel] ExQueryPoolBlockSize(0x%08X) -> %zu\n", poolBlock, blockSize);

    if (quotaChargedAddr)
        X86_MEM_WRITE_u8(base, quotaChargedAddr, 0); // QuotaCharged = FALSE

    GuestReturn32(ctx, static_cast<uint32_t>(blockSize));
    GuestStackCleanup(ctx, 8);
}
// NTSTATUS ExQueryNonVolatileSetting(DWORD ValueIndex, DWORD *Type,
//          PVOID Value, SIZE_T ValueLength, PSIZE_T ResultLength)
// EEPROM emulation: return safe defaults for common settings.
static void Kern_ExQueryNonVolatileSetting(X86Context& ctx, uint8_t* base)
{
    uint32_t valueIndex     = GuestArg32(ctx, base, 0);
    uint32_t typeAddr       = GuestArg32(ctx, base, 1);
    uint32_t valueAddr      = GuestArg32(ctx, base, 2);
    uint32_t valueLength    = GuestArg32(ctx, base, 3);
    uint32_t resultLenAddr  = GuestArg32(ctx, base, 4);

    // Xbox EEPROM value indices (from XDK)
    constexpr uint32_t XC_TIMEZONE_BIAS           = 0x0001;
    constexpr uint32_t XC_TZ_STD_NAME             = 0x0002;
    constexpr uint32_t XC_TZ_STD_DATE             = 0x0003;
    constexpr uint32_t XC_TZ_STD_BIAS             = 0x0004;
    constexpr uint32_t XC_TZ_DLT_NAME             = 0x0005;
    constexpr uint32_t XC_TZ_DLT_DATE             = 0x0006;
    constexpr uint32_t XC_TZ_DLT_BIAS             = 0x0007;
    constexpr uint32_t XC_LANGUAGE                = 0x0009;
    constexpr uint32_t XC_VIDEO                   = 0x000A;
    constexpr uint32_t XC_AUDIO                   = 0x000B;
    constexpr uint32_t XC_PARENTAL_CONTROL_GAMES  = 0x000C;
    constexpr uint32_t XC_PARENTAL_CONTROL_MOVIES = 0x000E;
    constexpr uint32_t XC_MISC                    = 0x0010;
    constexpr uint32_t XC_FACTORY_GAME_REGION     = 0x0104;
    constexpr uint32_t XC_FACTORY_AV_REGION       = 0x0103;
    constexpr uint32_t XC_MAX_OS                  = 0x00FF;

    fprintf(stderr, "[Kernel] ExQueryNonVolatileSetting: index=0x%04X, bufLen=%u\n",
            valueIndex, valueLength);

    // Set the type to X_REG_DWORD by default
    constexpr uint32_t X_REG_DWORD = 4;
    constexpr uint32_t X_REG_BINARY = 3;

    uint32_t resultSize = 4;
    uint32_t type = X_REG_DWORD;
    uint32_t dwordValue = 0;
    bool handled = true;

    switch (valueIndex) {
    case XC_LANGUAGE:               dwordValue = 1; break;      // English
    case XC_VIDEO:                  dwordValue = 0x00040800; break; // NTSC, normal, 480p
    case XC_AUDIO:                  dwordValue = 0; break;      // Stereo
    case XC_PARENTAL_CONTROL_GAMES: dwordValue = 0; break;      // No restrictions
    case XC_PARENTAL_CONTROL_MOVIES: dwordValue = 0; break;     // No restrictions
    case XC_MISC:                   dwordValue = 0; break;      // No auto power-down etc.
    case XC_FACTORY_GAME_REGION:    dwordValue = 1; break;      // North America
    case XC_FACTORY_AV_REGION:      dwordValue = 1; break;      // NTSC-M
    case XC_TIMEZONE_BIAS:          dwordValue = 0; type = X_REG_DWORD; break;
    case XC_TZ_STD_BIAS:            dwordValue = 0; break;
    case XC_TZ_DLT_BIAS:            dwordValue = 0; break;
    default:
        if (valueIndex <= XC_MAX_OS) {
            // Unknown EEPROM setting â€” zero-fill
            if (valueAddr && valueLength > 0)
                memset(base + valueAddr, 0, valueLength);
            resultSize = valueLength;
            type = X_REG_BINARY;
        } else {
            handled = false;
        }
        break;
    }

    if (!handled) {
        fprintf(stderr, "[Kernel]   -> unknown index, returning NOT_FOUND\n");
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
        GuestStackCleanup(ctx, 20);
        return;
    }

    // Write results
    if (typeAddr)
        X86_MEM_WRITE_u32(base, typeAddr, type);
    if (resultLenAddr)
        X86_MEM_WRITE_u32(base, resultLenAddr, resultSize);

    if (type == X_REG_DWORD && valueAddr && valueLength >= 4)
        X86_MEM_WRITE_u32(base, valueAddr, dwordValue);

    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 20);
}

// ---------------------------------------------------------------------------
// Threading
// ---------------------------------------------------------------------------

static void Kern_PsCreateSystemThreadEx(X86Context& ctx, uint8_t* base)
{
    // OG Xbox PsCreateSystemThreadEx (stdcall, 40 bytes = 10 args):
    //   arg0  = PHANDLE ThreadHandle          (output)
    //   arg1  = ULONG  ThreadExtensionSize    (typically 0)
    //   arg2  = ULONG  KernelStackSize
    //   arg3  = ULONG  TlsDataSize
    //   arg4  = PULONG pThreadId              (output, may be NULL)
    //   arg5  = PKSTART_ROUTINE StartRoutine
    //   arg6  = PVOID  StartContext
    //   arg7  = BOOLEAN CreateSuspended
    //   arg8  = BOOLEAN DebugStack
    //   arg9  = PKSYSTEM_ROUTINE SystemRoutine (e.g. XapiThreadStartup)

    uint32_t handlePtr     = GuestArg32(ctx, base, 0);
    uint32_t stackSize     = GuestArg32(ctx, base, 2);
    uint32_t threadIdPtr   = GuestArg32(ctx, base, 4);
    uint32_t startRoutine  = GuestArg32(ctx, base, 5);
    uint32_t startContext  = GuestArg32(ctx, base, 6);
    uint32_t createSusp    = GuestArg32(ctx, base, 7);

    GuestThreadParams params{};
    params.startAddress = startRoutine;
    params.startContext = startContext;
    params.stackSize    = (stackSize > 0) ? stackSize : 0;
    params.suspended    = (createSusp != 0);

    uint32_t handle = CreateKernelHandle<GuestThread>(params);
    if (handlePtr)
        X86_MEM_WRITE_u32(base, handlePtr, handle);
    if (threadIdPtr)
        X86_MEM_WRITE_u32(base, threadIdPtr, handle); // use handle as thread ID

    fprintf(stderr, "[Kernel] PsCreateSystemThreadEx -> handle %u, start=0x%08X ctx=0x%08X stack=0x%X suspended=%u\n",
            handle, startRoutine, startContext, stackSize, createSusp);
    GuestReturn32(ctx, 0); // STATUS_SUCCESS
    GuestStackCleanup(ctx, 40);
}

static void Kern_PsTerminateSystemThread(X86Context& ctx, uint8_t* base)
{
    uint32_t exitStatus = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[Kernel] PsTerminateSystemThread(0x%08X)\n", exitStatus);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
    // The thread will naturally return from its start routine after this stub.
}

// ---------------------------------------------------------------------------
// Symbolic links
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// Symbolic link management â€” in-memory table mapping link names to targets.
// On OG Xbox, IoCreateSymbolicLink maps drive letters like "\??\D:" to
// device paths like "\Device\CdRom0". We track these in a simple map.
// ---------------------------------------------------------------------------
static std::unordered_map<std::string, std::string> g_symbolicLinks;
static uint32_t g_nextSymlinkHandle = 0x5000;

struct SymlinkHandle final : KernelObject
{
    std::string linkName;
    bool Wait(uint32_t) override { return true; }
#ifdef _WIN32
    HANDLE GetNativeHandle() override { return INVALID_HANDLE_VALUE; }
#endif
};

// NTSTATUS IoCreateSymbolicLink(PSTRING SymbolicLinkName, PSTRING DeviceName)
static void Kern_IoCreateSymbolicLink(X86Context& ctx, uint8_t* base)
{
    uint32_t linkAddr   = GuestArg32(ctx, base, 0);
    uint32_t targetAddr = GuestArg32(ctx, base, 1);

    std::string linkName   = ReadGuestAnsiString(base, linkAddr);
    std::string targetName = ReadGuestAnsiString(base, targetAddr);

    fprintf(stderr, "[Kernel] IoCreateSymbolicLink: \"%s\" -> \"%s\"\n",
            linkName.c_str(), targetName.c_str());

    uint32_t status = X_STATUS_SUCCESS;
    if (g_symbolicLinks.count(linkName))
        status = 0xC0000035; // STATUS_OBJECT_NAME_COLLISION
    else
        g_symbolicLinks[linkName] = targetName;

    GuestReturn32(ctx, status);
    GuestStackCleanup(ctx, 8);
}

// NTSTATUS IoDeleteSymbolicLink(PSTRING SymbolicLinkName)
static void Kern_IoDeleteSymbolicLink(X86Context& ctx, uint8_t* base)
{
    uint32_t linkAddr = GuestArg32(ctx, base, 0);
    std::string linkName = ReadGuestAnsiString(base, linkAddr);

    fprintf(stderr, "[Kernel] IoDeleteSymbolicLink: \"%s\"\n", linkName.c_str());

    auto it = g_symbolicLinks.find(linkName);
    if (it != g_symbolicLinks.end()) {
        g_symbolicLinks.erase(it);
        GuestReturn32(ctx, X_STATUS_SUCCESS);
    } else {
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
    }
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS NtOpenSymbolicLinkObject(PHANDLE LinkHandle, POBJECT_ATTRIBUTES ObjectAttributes)
static void Kern_NtOpenSymbolicLinkObject(X86Context& ctx, uint8_t* base)
{
    uint32_t handleOutAddr = GuestArg32(ctx, base, 0);
    uint32_t objAttrAddr   = GuestArg32(ctx, base, 1);

    std::string linkName = ReadObjectName(base, objAttrAddr);
    fprintf(stderr, "[Kernel] NtOpenSymbolicLinkObject: \"%s\"\n", linkName.c_str());

    if (g_symbolicLinks.count(linkName)) {
        uint32_t handle = CreateKernelHandle<SymlinkHandle>();
        auto* sh = static_cast<SymlinkHandle*>(GetKernelObjectByHandle(handle));
        sh->linkName = linkName;
        X86_MEM_WRITE_u32(base, handleOutAddr, handle);
        GuestReturn32(ctx, X_STATUS_SUCCESS);
    } else {
        X86_MEM_WRITE_u32(base, handleOutAddr, 0);
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
    }
    GuestStackCleanup(ctx, 8);
}

// NTSTATUS NtQuerySymbolicLinkObject(HANDLE LinkHandle, PSTRING LinkTarget, PULONG ReturnedLength)
static void Kern_NtQuerySymbolicLinkObject(X86Context& ctx, uint8_t* base)
{
    uint32_t handle           = GuestArg32(ctx, base, 0);
    uint32_t linkTargetAddr   = GuestArg32(ctx, base, 1);
    uint32_t returnedLenAddr  = GuestArg32(ctx, base, 2);

    auto* obj = GetKernelObjectByHandle(handle);
    auto* sh = dynamic_cast<SymlinkHandle*>(obj);
    if (!sh) {
        GuestReturn32(ctx, X_STATUS_INVALID_HANDLE);
        GuestStackCleanup(ctx, 12);
        return;
    }

    auto it = g_symbolicLinks.find(sh->linkName);
    if (it == g_symbolicLinks.end()) {
        GuestReturn32(ctx, X_STATUS_OBJECT_NAME_NOT_FOUND);
        GuestStackCleanup(ctx, 12);
        return;
    }

    const std::string& target = it->second;
    auto* outStr = reinterpret_cast<XBOX_ANSI_STRING*>(base + linkTargetAddr);

    if (returnedLenAddr)
        X86_MEM_WRITE_u32(base, returnedLenAddr, static_cast<uint32_t>(target.size()));

    if (target.size() <= outStr->MaximumLength) {
        memcpy(base + outStr->Buffer, target.c_str(), target.size());
        outStr->Length = static_cast<uint16_t>(target.size());
        GuestReturn32(ctx, X_STATUS_SUCCESS);
    } else {
        GuestReturn32(ctx, 0xC0000023); // STATUS_BUFFER_TOO_SMALL
    }
    GuestStackCleanup(ctx, 12);
}

// ---------------------------------------------------------------------------
// XE section loading
// ---------------------------------------------------------------------------

// NTSTATUS XeLoadSection(PXBEIMAGE_SECTION Section)
// In our recomp, all XBE sections are loaded at startup, so this just
// increments the reference count field in the section header.
static void Kern_XeLoadSection(X86Context& ctx, uint8_t* base)
{
    uint32_t sectionAddr = GuestArg32(ctx, base, 0);
    if (sectionAddr) {
        // XBEIMAGE_SECTION.SectionReferenceCount is at offset 0x0C (DWORD)
        uint32_t refCount = X86_MEM_READ_u32(base, sectionAddr + 0x0C);
        X86_MEM_WRITE_u32(base, sectionAddr + 0x0C, refCount + 1);
        fprintf(stderr, "[Kernel] XeLoadSection: addr=0x%08X, refCount=%u->%u\n",
                sectionAddr, refCount, refCount + 1);
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS XeUnloadSection(PXBEIMAGE_SECTION Section)
static void Kern_XeUnloadSection(X86Context& ctx, uint8_t* base)
{
    uint32_t sectionAddr = GuestArg32(ctx, base, 0);
    if (sectionAddr) {
        uint32_t refCount = X86_MEM_READ_u32(base, sectionAddr + 0x0C);
        if (refCount > 0)
            X86_MEM_WRITE_u32(base, sectionAddr + 0x0C, refCount - 1);
        fprintf(stderr, "[Kernel] XeUnloadSection: addr=0x%08X, refCount=%u->%u\n",
                sectionAddr, refCount, (refCount > 0) ? refCount - 1 : 0);
    }
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// HAL
// ---------------------------------------------------------------------------

static void Kern_HalReturnToFirmware(X86Context& ctx, uint8_t* base)
{
    uint32_t reason = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[Kernel] HalReturnToFirmware called (reason=%u) -- exiting\n", reason);
    exit(0);
}

KERNEL_STUB(HalInitiateShutdown)

// ULONG HalGetInterruptVector(ULONG BusInterruptLevel, PKIRQL Irql)
// Converts an IRQ number to an interrupt vector.
static void Kern_HalGetInterruptVector(X86Context& ctx, uint8_t* base)
{
    uint32_t busLevel = GuestArg32(ctx, base, 0);
    uint32_t irqlAddr = GuestArg32(ctx, base, 1);

    // Xbox: vector = IRQ + 0x30 (IDT base for device IRQs)
    uint32_t vector = busLevel + 0x30;
    // IRQL = VECTOR2IRQL = HIGH_LEVEL - (vector - 0x30) = 31 - busLevel
    uint8_t irql = static_cast<uint8_t>(31 - (busLevel & 0x1F));

    if (irqlAddr)
        X86_MEM_WRITE_u8(base, irqlAddr, irql);

    fprintf(stderr, "[Kernel] HalGetInterruptVector(IRQ=%u) -> vector=0x%X, IRQL=%u\n",
            busLevel, vector, irql);
    GuestReturn32(ctx, vector);
    GuestStackCleanup(ctx, 8);
}

// VOID HalRegisterShutdownNotification(PHAL_SHUTDOWN_REGISTRATION ShutdownRegistration, BOOLEAN Register)
static void Kern_HalRegisterShutdownNotification(X86Context& ctx, uint8_t* base)
{
    // No-op: we don't need shutdown callbacks in recomp.
    GuestStackCleanup(ctx, 8);
}

KERNEL_STUB_CLEANUP(HalReadWritePCISpace, 24)
KERNEL_STUB_CLEANUP(HalWriteSMBusValue, 12)

// ---------------------------------------------------------------------------
// Interrupts / DPC
// ---------------------------------------------------------------------------

// BOOLEAN KeConnectInterrupt(PKINTERRUPT Interrupt)
// Marks the interrupt object as connected. No real HW to wire up.
static void Kern_KeConnectInterrupt(X86Context& ctx, uint8_t* base)
{
    uint32_t intAddr = GuestArg32(ctx, base, 0);
    if (intAddr)
    {
        // KINTERRUPT.Connected is at offset 0x10 (boolean)
        X86_MEM_WRITE_u8(base, intAddr + 0x10, 1); // Connected = TRUE
        fprintf(stderr, "[Kernel] KeConnectInterrupt(0x%08X) -> TRUE\n", intAddr);
    }
    GuestReturn32(ctx, 1); // TRUE = success
    GuestStackCleanup(ctx, 4);
}

// VOID KeInitializeInterrupt(PKINTERRUPT Interrupt, PKSERVICE_ROUTINE ServiceRoutine,
//      PVOID ServiceContext, ULONG Vector, KIRQL Irql,
//      KINTERRUPT_MODE InterruptMode, BOOLEAN ShareVector)
// KINTERRUPT layout:
//   +0x00 ServiceRoutine     (4 bytes)
//   +0x04 ServiceContext     (4 bytes)
//   +0x08 BusInterruptLevel  (4 bytes)
//   +0x0C Irql               (4 bytes)
//   +0x10 Connected          (1 byte)
//   +0x11 ShareVector         (1 byte)
//   +0x12 Mode               (2 bytes / padded to 4)
//   +0x14 ServiceCount       (4 bytes)
//   +0x18 DispatchCode[]     (88 bytes)
static void Kern_KeInitializeInterrupt(X86Context& ctx, uint8_t* base)
{
    uint32_t intAddr      = GuestArg32(ctx, base, 0);
    uint32_t routine      = GuestArg32(ctx, base, 1);
    uint32_t context      = GuestArg32(ctx, base, 2);
    uint32_t vector       = GuestArg32(ctx, base, 3);
    uint32_t irql         = GuestArg32(ctx, base, 4);
    uint32_t mode         = GuestArg32(ctx, base, 5);
    uint32_t shareVector  = GuestArg32(ctx, base, 6);

    if (intAddr)
    {
        // Zero the whole KINTERRUPT (112 bytes)
        memset(base + intAddr, 0, 112);

        X86_MEM_WRITE_u32(base, intAddr + 0x00, routine);
        X86_MEM_WRITE_u32(base, intAddr + 0x04, context);
        // BusInterruptLevel = VECTOR2IRQ(vector) = vector - 0x30
        uint32_t busLevel = (vector >= 0x30) ? (vector - 0x30) : vector;
        X86_MEM_WRITE_u32(base, intAddr + 0x08, busLevel);
        X86_MEM_WRITE_u32(base, intAddr + 0x0C, irql);
        X86_MEM_WRITE_u8 (base, intAddr + 0x10, 0);                        // Connected = FALSE
        X86_MEM_WRITE_u8 (base, intAddr + 0x11, shareVector ? 1 : 0);
        X86_MEM_WRITE_u16(base, intAddr + 0x12, static_cast<uint16_t>(mode));
        X86_MEM_WRITE_u32(base, intAddr + 0x14, 0);                        // ServiceCount = 0

        fprintf(stderr, "[Kernel] KeInitializeInterrupt(0x%08X): routine=0x%08X vec=0x%X irql=%u\n",
                intAddr, routine, vector, irql);
    }
    GuestStackCleanup(ctx, 28);
}

KERNEL_STUB_CLEANUP(KeDisconnectInterrupt, 4)
// BOOLEAN KeInsertQueueDpc(PKDPC Dpc, PVOID SystemArgument1, PVOID SystemArgument2)
static void Kern_KeInsertQueueDpc(X86Context& ctx, uint8_t* base)
{
    uint32_t dpcAddr  = GuestArg32(ctx, base, 0);
    uint32_t sysArg1  = GuestArg32(ctx, base, 1);
    uint32_t sysArg2  = GuestArg32(ctx, base, 2);

    uint8_t inserted = X86_MEM_READ_u8(base, dpcAddr + 0x02);
    if (!inserted)
    {
        X86_MEM_WRITE_u8 (base, dpcAddr + 0x02, 1);      // Inserted = TRUE
        X86_MEM_WRITE_u32(base, dpcAddr + 0x14, sysArg1); // SystemArgument1
        X86_MEM_WRITE_u32(base, dpcAddr + 0x18, sysArg2); // SystemArgument2

        // Fire the DPC immediately (we don't have a real DPC queue/IRQL model)
        FireDpc(dpcAddr, base);

        X86_MEM_WRITE_u8(base, dpcAddr + 0x02, 0); // Inserted = FALSE after execution
        GuestReturn32(ctx, 1); // TRUE â€” was not already queued
    }
    else
    {
        GuestReturn32(ctx, 0); // FALSE â€” was already queued
    }
    GuestStackCleanup(ctx, 12);
}

// BOOLEAN KeRemoveQueueDpc(PKDPC Dpc)
static void Kern_KeRemoveQueueDpc(X86Context& ctx, uint8_t* base)
{
    uint32_t dpcAddr = GuestArg32(ctx, base, 0);

    uint8_t inserted = X86_MEM_READ_u8(base, dpcAddr + 0x02);
    if (inserted)
    {
        X86_MEM_WRITE_u8(base, dpcAddr + 0x02, 0); // Inserted = FALSE
        GuestReturn32(ctx, 1); // TRUE â€” was removed
    }
    else
    {
        GuestReturn32(ctx, 0); // FALSE â€” was not queued
    }
    GuestStackCleanup(ctx, 4);
}
KERNEL_STUB_CLEANUP(KeSynchronizeExecution, 12)
KERNEL_STUB_CLEANUP(KeSaveFloatingPointState, 4)
KERNEL_STUB_CLEANUP(KeRestoreFloatingPointState, 4)

// ---------------------------------------------------------------------------
// Crypto
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// SHA-1 implementation (matching Xbox kernel XcSHA* exports)
// ---------------------------------------------------------------------------
// Xbox SHA context layout (offset +0 is 24 bytes of Xbox padding, then SHA1_CTX).
// We store our own host-side state directly in the guest buffer:
//   Bytes 0..3   = state[0..4]  (20 bytes)
//   Bytes 20..27 = count[0..1]  (8 bytes)
//   Bytes 28..91 = buffer[64]   (64 bytes)
// Total 92 bytes. Xbox allocates at least 84 bytes for the context but we
// use the full buffer from offset 0 (no Xbox padding in homebrew titles).

struct SHA1_CTX {
    uint32_t state[5];
    uint32_t count[2];
    uint8_t  buffer[64];
};

static void SHA1Transform(uint32_t state[5], const uint8_t block[64]);

static void SHA1Init(SHA1_CTX* ctx)
{
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xC3D2E1F0;
    ctx->count[0] = ctx->count[1] = 0;
}

static inline uint32_t SHA1_ROL(uint32_t v, int n) { return (v << n) | (v >> (32 - n)); }

static void SHA1Transform(uint32_t state[5], const uint8_t block[64])
{
    uint32_t w[80];
    for (int i = 0; i < 16; i++)
        w[i] = (uint32_t(block[i*4]) << 24) | (uint32_t(block[i*4+1]) << 16)
             | (uint32_t(block[i*4+2]) << 8) | uint32_t(block[i*4+3]);
    for (int i = 16; i < 80; i++)
        w[i] = SHA1_ROL(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);

    uint32_t a = state[0], b = state[1], c = state[2], d = state[3], e = state[4];
    for (int i = 0; i < 80; i++) {
        uint32_t f, k;
        if      (i < 20) { f = (b & c) | ((~b) & d);           k = 0x5A827999; }
        else if (i < 40) { f = b ^ c ^ d;                      k = 0x6ED9EBA1; }
        else if (i < 60) { f = (b & c) | (b & d) | (c & d);    k = 0x8F1BBCDC; }
        else              { f = b ^ c ^ d;                      k = 0xCA62C1D6; }
        uint32_t temp = SHA1_ROL(a, 5) + f + e + k + w[i];
        e = d; d = c; c = SHA1_ROL(b, 30); b = a; a = temp;
    }
    state[0] += a; state[1] += b; state[2] += c; state[3] += d; state[4] += e;
}

static void SHA1Update(SHA1_CTX* ctx, const uint8_t* data, uint32_t len)
{
    uint32_t index = (ctx->count[0] >> 3) & 0x3F;
    ctx->count[0] += len << 3;
    if (ctx->count[0] < (len << 3)) ctx->count[1]++;
    ctx->count[1] += (len >> 29);

    uint32_t partLen = 64 - index;
    uint32_t i = 0;
    if (len >= partLen) {
        memcpy(&ctx->buffer[index], data, partLen);
        SHA1Transform(ctx->state, ctx->buffer);
        for (i = partLen; i + 63 < len; i += 64)
            SHA1Transform(ctx->state, &data[i]);
        index = 0;
    }
    memcpy(&ctx->buffer[index], &data[i], len - i);
}

static void SHA1Final(uint8_t digest[20], SHA1_CTX* ctx)
{
    uint8_t finalcount[8];
    for (int i = 0; i < 4; i++) {
        finalcount[i]   = (uint8_t)((ctx->count[1] >> ((3 - i) * 8)) & 0xFF);
        finalcount[i+4] = (uint8_t)((ctx->count[0] >> ((3 - i) * 8)) & 0xFF);
    }
    uint8_t pad = 0x80;
    SHA1Update(ctx, &pad, 1);
    while ((ctx->count[0] & 504) != 448) {
        pad = 0x00;
        SHA1Update(ctx, &pad, 1);
    }
    SHA1Update(ctx, finalcount, 8);
    for (int i = 0; i < 20; i++)
        digest[i] = (uint8_t)((ctx->state[i >> 2] >> ((3 - (i & 3)) * 8)) & 0xFF);
    memset(ctx, 0, sizeof(*ctx));
}

// VOID XcSHAInit(PUCHAR pbSHAContext)
static void Kern_XcSHAInit(X86Context& ctx, uint8_t* base)
{
    uint32_t ctxAddr = GuestArg32(ctx, base, 0);
    if (ctxAddr)
    {
        SHA1_CTX sha;
        SHA1Init(&sha);
        memcpy(base + ctxAddr, &sha, sizeof(sha));
    }
    GuestStackCleanup(ctx, 4);
}

// VOID XcSHAUpdate(PUCHAR pbSHAContext, PUCHAR pbInput, ULONG dwInputLength)
static void Kern_XcSHAUpdate(X86Context& ctx, uint8_t* base)
{
    uint32_t ctxAddr  = GuestArg32(ctx, base, 0);
    uint32_t dataAddr = GuestArg32(ctx, base, 1);
    uint32_t dataLen  = GuestArg32(ctx, base, 2);
    if (ctxAddr && dataAddr && dataLen > 0)
    {
        SHA1_CTX sha;
        memcpy(&sha, base + ctxAddr, sizeof(sha));
        SHA1Update(&sha, base + dataAddr, dataLen);
        memcpy(base + ctxAddr, &sha, sizeof(sha));
    }
    GuestStackCleanup(ctx, 12);
}

// VOID XcSHAFinal(PUCHAR pbSHAContext, PUCHAR pbDigest)
static void Kern_XcSHAFinal(X86Context& ctx, uint8_t* base)
{
    uint32_t ctxAddr    = GuestArg32(ctx, base, 0);
    uint32_t digestAddr = GuestArg32(ctx, base, 1);
    if (ctxAddr && digestAddr)
    {
        SHA1_CTX sha;
        memcpy(&sha, base + ctxAddr, sizeof(sha));
        uint8_t digest[20];
        SHA1Final(digest, &sha);
        memcpy(base + digestAddr, digest, 20);
        // Clear guest context
        memset(base + ctxAddr, 0, sizeof(SHA1_CTX));
    }
    GuestStackCleanup(ctx, 8);
}

// VOID XcHMAC(PBYTE pbKeyMaterial, ULONG cbKeyMaterial,
//             PBYTE pbData, ULONG cbData,
//             PBYTE pbData2, ULONG cbData2,
//             PBYTE HmacData)
// HMAC-SHA1 per RFC 2104.
static void Kern_XcHMAC(X86Context& ctx, uint8_t* base)
{
    uint32_t keyAddr     = GuestArg32(ctx, base, 0);
    uint32_t keyLen      = GuestArg32(ctx, base, 1);
    uint32_t data1Addr   = GuestArg32(ctx, base, 2);
    uint32_t data1Len    = GuestArg32(ctx, base, 3);
    uint32_t data2Addr   = GuestArg32(ctx, base, 4);
    uint32_t data2Len    = GuestArg32(ctx, base, 5);
    uint32_t hmacOutAddr = GuestArg32(ctx, base, 6);

    // Clamp key length to 64 (SHA1 block size)
    if (keyLen > 64) keyLen = 64;

    uint8_t ipad[64], opad[64];
    memset(ipad, 0x36, 64);
    memset(opad, 0x5C, 64);

    // XOR key into pads
    if (keyAddr && keyLen > 0) {
        const uint8_t* key = base + keyAddr;
        for (uint32_t i = 0; i < keyLen; i++) {
            ipad[i] ^= key[i];
            opad[i] ^= key[i];
        }
    }

    // Inner hash: SHA1(ipad || data1 || data2)
    SHA1_CTX sha;
    SHA1Init(&sha);
    SHA1Update(&sha, ipad, 64);
    if (data1Addr && data1Len > 0)
        SHA1Update(&sha, base + data1Addr, data1Len);
    if (data2Addr && data2Len > 0)
        SHA1Update(&sha, base + data2Addr, data2Len);
    uint8_t innerDigest[20];
    SHA1Final(innerDigest, &sha);

    // Outer hash: SHA1(opad || innerDigest)
    SHA1Init(&sha);
    SHA1Update(&sha, opad, 64);
    SHA1Update(&sha, innerDigest, 20);
    uint8_t hmac[20];
    SHA1Final(hmac, &sha);

    if (hmacOutAddr)
        memcpy(base + hmacOutAddr, hmac, 20);

    GuestStackCleanup(ctx, 28);
}

// VOID XcDESKeyParity(PUCHAR pbKey, ULONG dwKeyLength)
// Sets the parity bit (bit 0) of each byte in a DES key so that each byte
// has odd parity, matching the DES key schedule requirement.
static void Kern_XcDESKeyParity(X86Context& ctx, uint8_t* base)
{
    uint32_t keyAddr = GuestArg32(ctx, base, 0);
    uint32_t keyLen  = GuestArg32(ctx, base, 1);

    if (keyAddr && keyLen > 0)
    {
        uint8_t* key = base + keyAddr;
        for (uint32_t i = 0; i < keyLen; i++)
        {
            uint8_t b = key[i] & 0xFE; // clear parity bit
            // Count set bits in upper 7 bits
            uint8_t t = b;
            t ^= t >> 4;
            t ^= t >> 2;
            t ^= t >> 1;
            // Set parity bit so total number of 1-bits is odd
            key[i] = b | (~t & 1);
        }
    }
    GuestStackCleanup(ctx, 8);
}

KERNEL_STUB_CLEANUP(XcBlockCryptCBC, 28)
KERNEL_STUB_CLEANUP(XcKeyTable, 12)
KERNEL_STUB_CLEANUP(XcModExp, 20)

// ---------------------------------------------------------------------------
// RC4 implementation (matching Xbox kernel XcRC4* exports)
// ---------------------------------------------------------------------------
// RC4 context: 256-byte S-box + two uint32_t counters = 264 bytes.

struct Rc4Context {
    uint8_t  S[256];
    uint32_t i;
    uint32_t j;
};

// VOID XcRC4Key(PUCHAR pbKeyStruct, ULONG dwKeyLength, PUCHAR pbKey)
static void Kern_XcRC4Key(X86Context& ctx, uint8_t* base)
{
    uint32_t ksAddr  = GuestArg32(ctx, base, 0);
    uint32_t keyLen  = GuestArg32(ctx, base, 1);
    uint32_t keyAddr = GuestArg32(ctx, base, 2);

    if (ksAddr && keyAddr && keyLen > 0)
    {
        Rc4Context rc4;
        for (int n = 0; n < 256; n++)
            rc4.S[n] = static_cast<uint8_t>(n);
        rc4.i = 0;
        rc4.j = 0;

        const uint8_t* key = base + keyAddr;
        uint32_t j = 0;
        for (int n = 0; n < 256; n++) {
            j = (j + rc4.S[n] + key[n % keyLen]) & 0xFF;
            uint8_t tmp = rc4.S[n];
            rc4.S[n] = rc4.S[j];
            rc4.S[j] = tmp;
        }

        memcpy(base + ksAddr, &rc4, sizeof(rc4));
    }
    GuestStackCleanup(ctx, 12);
}

// VOID XcRC4Crypt(PUCHAR pbKeyStruct, ULONG dwInputLength, PUCHAR pbInput)
static void Kern_XcRC4Crypt(X86Context& ctx, uint8_t* base)
{
    uint32_t ksAddr   = GuestArg32(ctx, base, 0);
    uint32_t dataLen  = GuestArg32(ctx, base, 1);
    uint32_t dataAddr = GuestArg32(ctx, base, 2);

    if (ksAddr && dataAddr && dataLen > 0)
    {
        Rc4Context rc4;
        memcpy(&rc4, base + ksAddr, sizeof(rc4));

        uint8_t* data = base + dataAddr;
        uint32_t si = rc4.i, sj = rc4.j;
        for (uint32_t n = 0; n < dataLen; n++) {
            si = (si + 1) & 0xFF;
            sj = (sj + rc4.S[si]) & 0xFF;
            uint8_t tmp = rc4.S[si];
            rc4.S[si] = rc4.S[sj];
            rc4.S[sj] = tmp;
            data[n] ^= rc4.S[(rc4.S[si] + rc4.S[sj]) & 0xFF];
        }
        rc4.i = si;
        rc4.j = sj;

        memcpy(base + ksAddr, &rc4, sizeof(rc4));
    }
    GuestStackCleanup(ctx, 12);
}

// ---------------------------------------------------------------------------
// Network
// ---------------------------------------------------------------------------

// DWORD PhyGetLinkState(ULONG Mode)
// Returns ethernet link state flags.  No physical NIC in recomp â†’ report "no link".
static void Kern_PhyGetLinkState(X86Context& ctx, uint8_t* base)
{
    uint32_t mode = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[Kernel] PhyGetLinkState(mode=%u) -> 0 (no link)\n", mode);
    GuestReturn32(ctx, 0);        // 0 = no link active
    GuestStackCleanup(ctx, 4);    // stdcall, 1 arg
}

// NTSTATUS PhyInitialize(ULONG forceReset, PVOID param2)
// Initialises the PHY layer.  Stub succeeds immediately â€” no real NIC.
static void Kern_PhyInitialize(X86Context& ctx, uint8_t* base)
{
    uint32_t forceReset = GuestArg32(ctx, base, 0);
    uint32_t param2     = GuestArg32(ctx, base, 1);
    fprintf(stderr, "[Kernel] PhyInitialize(forceReset=%u, param2=0x%08X) -> STATUS_SUCCESS\n",
            forceReset, param2);
    GuestReturn32(ctx, 0);        // STATUS_SUCCESS
    GuestStackCleanup(ctx, 8);    // stdcall, 2 args
}

// ---------------------------------------------------------------------------
// AV (video output)
// ---------------------------------------------------------------------------

static void Kern_AvSetSavedDataAddress(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

static void Kern_AvGetSavedDataAddress(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
}

static void Kern_AvSendTVEncoderOption(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

static void Kern_AvSetDisplayMode(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[Kernel] AvSetDisplayMode called\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 24);
}

// ---------------------------------------------------------------------------
// Debug
// ---------------------------------------------------------------------------

static void Kern_DbgPrint(X86Context& ctx, uint8_t* base)
{
    uint32_t fmtAddr = GuestArg32(ctx, base, 0);
    if (fmtAddr)
    {
        const char* str = reinterpret_cast<const char*>(g_memory.Translate(fmtAddr));
        fprintf(stderr, "[DbgPrint] %s", str);
    }
    ctx.eax = 0;
}

static void Kern_KeBugCheck(X86Context& ctx, uint8_t* base)
{
    uint32_t code = GuestArg32(ctx, base, 0);
    uint8_t irql = X86_MEM_READ_u8(base, 0x24);
    fprintf(stderr, "[Kernel] KeBugCheck(0x%08X) -- IRQL=%u (resetting to 0)\n", code, irql);
    // Reset IRQL so the caller can continue (bugcheck is non-fatal here).
    X86_MEM_WRITE_u8(base, 0x24, 0);
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// Additional stubs for Burnout 3 kernel imports
// ---------------------------------------------------------------------------

// NTSTATUS NtYieldExecution(VOID)
static void Kern_NtYieldExecution(X86Context& ctx, uint8_t* base)
{
    std::this_thread::yield();
    GuestReturn32(ctx, 0); // STATUS_SUCCESS
}

// LONG KeQueryBasePriorityThread(PKTHREAD Thread)
static void Kern_KeQueryBasePriorityThread(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0); // default base priority
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS NtDeleteFile(POBJECT_ATTRIBUTES ObjectAttributes)
static void Kern_NtDeleteFile(X86Context& ctx, uint8_t* base)
{
    uint32_t objAttrAddr = GuestArg32(ctx, base, 0);
    std::string path = ReadObjectName(base, objAttrAddr);
    fprintf(stderr, "[Kernel] NtDeleteFile: \"%s\" (stub)\n", path.c_str());
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 4);
}

// NTSTATUS NtDuplicateObject(HANDLE SourceHandle, PHANDLE TargetHandle, DWORD Options)
static void Kern_NtDuplicateObject(X86Context& ctx, uint8_t* base)
{
    uint32_t srcHandle  = GuestArg32(ctx, base, 0);
    uint32_t tgtHandleAddr = GuestArg32(ctx, base, 1);
    uint32_t options    = GuestArg32(ctx, base, 2);
    fprintf(stderr, "[Kernel] NtDuplicateObject(src=%u, options=0x%X) -> stub\n", srcHandle, options);
    if (tgtHandleAddr)
        X86_MEM_WRITE_u32(base, tgtHandleAddr, srcHandle); // duplicate = same handle
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 12);
}

// NTSTATUS NtSetSystemTime(PLARGE_INTEGER NewTime, PLARGE_INTEGER OldTime)
static void Kern_NtSetSystemTime(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[Kernel] NtSetSystemTime (stub)\n");
    GuestReturn32(ctx, X_STATUS_SUCCESS);
    GuestStackCleanup(ctx, 8);
}

// NTSTATUS ObReferenceObjectByName(POBJECT_STRING ObjectName, ...)
static void Kern_ObReferenceObjectByName(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[Kernel] ObReferenceObjectByName (stub)\n");
    GuestReturn32(ctx, 0xC0000034); // STATUS_OBJECT_NAME_NOT_FOUND
    GuestStackCleanup(ctx, 16);
}

// BOOLEAN HalIsResetOrShutdownPending(VOID)
static void Kern_HalIsResetOrShutdownPending(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0); // FALSE
}

// ---------------------------------------------------------------------------
// I/O manager stubs (used by DSOUND / XMV XDK sections)
// ---------------------------------------------------------------------------

KERNEL_STUB_CLEANUP(IofCallDriver, 8)
KERNEL_STUB_CLEANUP(IoBuildSynchronousFsdRequest, 28)
KERNEL_STUB_CLEANUP(IofCompleteRequest, 8)
KERNEL_STUB_CLEANUP(IoSynchronousFsdRequest, 16)
KERNEL_STUB_CLEANUP(IoSynchronousDeviceIoControlRequest, 40)
KERNEL_STUB_CLEANUP(IoCreateDevice, 28)
KERNEL_STUB(IoInvalidDeviceRequest)
KERNEL_STUB_CLEANUP(IoStartPacket, 16)
KERNEL_STUB_CLEANUP(IoStartNextPacket, 8)
KERNEL_STUB_CLEANUP(IoMarkIrpMustComplete, 4)

// ---------------------------------------------------------------------------
// Kernel stacks (used by threading code in XDK sections)
// ---------------------------------------------------------------------------

// PVOID MmCreateKernelStack(ULONG NumberOfBytes, BOOLEAN DebuggerThread)
static void Kern_MmCreateKernelStack(X86Context& ctx, uint8_t* base)
{
    uint32_t numBytes = GuestArg32(ctx, base, 0);
    if (numBytes == 0) numBytes = 0x10000; // default 64KB
    uint32_t addr = g_heap.AllocGuest(numBytes);
    fprintf(stderr, "[Kernel] MmCreateKernelStack(%u) -> 0x%08X\n", numBytes, addr + numBytes);
    GuestReturn32(ctx, addr + numBytes); // return top of stack (stack grows down)
    GuestStackCleanup(ctx, 8);
}

// VOID MmDeleteKernelStack(PVOID StackBase, PVOID StackLimit)
static void Kern_MmDeleteKernelStack(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[Kernel] MmDeleteKernelStack (stub - leak)\n");
    GuestStackCleanup(ctx, 8);
}

// ---------------------------------------------------------------------------
// Misc / fallback
// ---------------------------------------------------------------------------

static void Kern_Unknown(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[Kernel] Unknown kernel export called!\n");
    ctx.eax = 0;
}

// ---------------------------------------------------------------------------
// Data export helper: allocates guest memory, initializes it, and writes
// the guest pointer into the IAT slot.
// ---------------------------------------------------------------------------
static void Kern_DataExportNotCallable(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[Kernel] ERROR: data export address called as function!\n");
    ctx.eax = 0;
}

static uint32_t InitDataExport(uint32_t iatAddr, uint32_t size)
{
    uint32_t dataAddr = g_heap.AllocGuest(size);
    if (dataAddr)
    {
        memset(g_memory.Translate(dataAddr), 0, size);
        X86_MEM_WRITE_u32(g_memory.base, iatAddr, dataAddr);
        // Mark in g_funcMap so the catch-all HookThunk loop does not
        // overwrite our heap pointer with the self-referencing thunkAddr.
        g_funcMap[iatAddr] = Kern_DataExportNotCallable;
    }
    return dataAddr;
}

// ---------------------------------------------------------------------------
// Init: wire up all thunks (addresses from IDA Pro)
// ---------------------------------------------------------------------------

void KernelDispatch::Init()
{
    // Pre-reserve the kernel object vector so that push_back never
    // reallocates once the hot path is running.  This makes lock-free
    // GetKernelObject reads safe (no concurrent realloc).
    g_kernelObjects.reserve(512);

    struct ThunkEntry
    {
        uint32_t addr;
        const char* name;
        X86RecompFunc func;
    };

    ThunkEntry thunks[] = {
        // Timing
        { 0x36B7DC, "KeQuerySystemTime",              Kern_KeQuerySystemTime },
        { 0x36B8BC, "RtlTimeToTimeFields",            Kern_RtlTimeToTimeFields },
        // 0x36B8C0 = KeTickCount (DATA)
        { 0x36B8C4, "RtlTimeFieldsToTime",            Kern_RtlTimeFieldsToTime },
        // 0x36B864 = ExEventObjectType (DATA)
        { 0x36B7EC, "RtlInitAnsiString",              Kern_RtlInitAnsiString },

        // Synchronization
        { 0x36B860, "NtCreateEvent",                  Kern_NtCreateEvent },
        { 0x36B868, "NtSetEvent",                     Kern_NtSetEvent },
        { 0x36B86C, "NtCreateSemaphore",              Kern_NtCreateSemaphore },
        { 0x36B870, "NtReleaseSemaphore",             Kern_NtReleaseSemaphore },
        { 0x36B874, "NtWaitForSingleObjectEx",        Kern_NtWaitForSingleObjectEx },
        { 0x36B878, "KeDelayExecutionThread",         Kern_KeDelayExecutionThread },
        { 0x36B8B4, "KfLowerIrql",                    Kern_KfLowerIrql },
        { 0x36B8B8, "KeRaiseIrqlToDpcLevel",          Kern_KeRaiseIrqlToDpcLevel },
        { 0x36B9BC, "KeSetTimerEx",                   Kern_KeSetTimerEx },
        { 0x36B87C, "RtlLeaveCriticalSection",        Kern_RtlLeaveCriticalSection },
        { 0x36B880, "RtlEnterCriticalSection",        Kern_RtlEnterCriticalSection },
        { 0x36B984, "KeWaitForMultipleObjects",       Kern_KeWaitForMultipleObjects },
        { 0x36B8E8, "KeSetEvent",                     Kern_KeSetEvent },
        { 0x36B8DC, "KeInitializeTimerEx",            Kern_KeInitializeTimerEx },
        { 0x36B8EC, "KeWaitForSingleObject",          Kern_KeWaitForSingleObject },
        { 0x36B8E4, "KeCancelTimer",                  Kern_KeCancelTimer },
        { 0x36B894, "NtYieldExecution",               Kern_NtYieldExecution },

        // Memory
        { 0x36B82C, "MmPersistContiguousMemory",      Kern_MmPersistContiguousMemory },
        { 0x36B830, "MmAllocateContiguousMemory",     Kern_MmAllocateContiguousMemory },
        // 0x36B834 = LaunchDataPage (DATA)
        { 0x36B820, "MmFreeContiguousMemory",         Kern_MmFreeContiguousMemory },

        // Rtl / HAL
        { 0x36B80C, "RtlNtStatusToDosError",          Kern_RtlNtStatusToDosError },
        { 0x36B838, "HalReturnToFirmware",            Kern_HalReturnToFirmware },
        { 0x36B7D8, "ExQueryNonVolatileSetting",      Kern_ExQueryNonVolatileSetting },

        // File I/O
        { 0x36B7E0, "NtClose",                        Kern_NtClose },
        { 0x36B83C, "NtCreateFile",                   Kern_NtCreateFile },
        { 0x36B840, "NtSetInformationFile",           Kern_NtSetInformationFile },
        { 0x36B7E8, "NtOpenFile",                     Kern_NtOpenFile },
        { 0x36B8A8, "NtQueryDirectoryFile",           Kern_NtQueryDirectoryFile },
        { 0x36B7F0, "NtWriteFile",                    Kern_NtWriteFile },
        { 0x36B7F8, "NtReadFile",                     Kern_NtReadFile },
        { 0x36B844, "NtQueryInformationFile",         Kern_NtQueryInformationFile },
        { 0x36B848, "NtWaitForSingleObject",          Kern_NtWaitForSingleObject },
        { 0x36B7E4, "NtQueryVolumeInformationFile",   Kern_NtQueryVolumeInformationFile },
        { 0x36B84C, "NtFlushBuffersFile",             Kern_NtFlushBuffersFile },
        { 0x36B810, "NtFsControlFile",                Kern_NtFsControlFile },
        { 0x36B850, "NtDeviceIoControlFile",          Kern_NtDeviceIoControlFile },
        { 0x36B8A4, "NtQueryFullAttributesFile",      Kern_NtQueryFullAttributesFile },
        { 0x36B9A4, "NtDeleteFile",                   Kern_NtDeleteFile },
        { 0x36B8A0, "NtDuplicateObject",              Kern_NtDuplicateObject },

        // Object manager
        { 0x36B854, "ObfDereferenceObject",           Kern_ObfDereferenceObject },
        { 0x36B858, "ObReferenceObjectByHandle",      Kern_ObReferenceObjectByHandle },
        { 0x36B9B8, "ObReferenceObjectByName",        Kern_ObReferenceObjectByName },

        // String
        { 0x36B8AC, "RtlAnsiStringToUnicodeString",   Kern_RtlAnsiStringToUnicodeString },
        { 0x36B8B0, "RtlUnicodeStringToAnsiString",   Kern_RtlUnicodeStringToAnsiString },

        // Timers / threads
        { 0x36B8E0, "KeSetTimer",                     Kern_KeSetTimer },
        { 0x36B8F0, "KeInitializeDpc",                Kern_KeInitializeDpc },
        // 0x36B8D0 = XboxHardwareInfo (DATA)
        { 0x36B884, "KeSetBasePriorityThread",        Kern_KeSetBasePriorityThread },
        { 0x36B88C, "KeQueryBasePriorityThread",      Kern_KeQueryBasePriorityThread },
        // 0x36B888 = PsThreadObjectType (DATA)
        { 0x36B890, "RtlRaiseException",              Kern_RtlRaiseException },
        { 0x36B898, "PsTerminateSystemThread",        Kern_PsTerminateSystemThread },
        { 0x36B89C, "PsCreateSystemThreadEx",         Kern_PsCreateSystemThreadEx },

        // Symbolic links
        { 0x36B7FC, "IoCreateSymbolicLink",           Kern_IoCreateSymbolicLink },
        { 0x36B808, "IoDeleteSymbolicLink",           Kern_IoDeleteSymbolicLink },
        { 0x36B800, "NtQuerySymbolicLinkObject",      Kern_NtQuerySymbolicLinkObject },
        { 0x36B804, "NtOpenSymbolicLinkObject",       Kern_NtOpenSymbolicLinkObject },

        // Crypto
        { 0x36B7C8, "XcSHAFinal",                    Kern_XcSHAFinal },
        { 0x36B7C0, "XcSHAUpdate",                   Kern_XcSHAUpdate },
        { 0x36B7C4, "XcSHAInit",                     Kern_XcSHAInit },
        { 0x36B9A0, "XcVerifyPKCS1Signature",         Kern_Unknown },
        // 0x36B8D8 = XeImageFileName (DATA)
        // 0x36B9A8 = XePublicKeyData (DATA)
        // 0x36B828 = HalBootSMCVideoMode (DATA)
        { 0x36B8D4, "HalRegisterShutdownNotification", Kern_HalRegisterShutdownNotification },
        { 0x36B81C, "MmSetAddressProtect",            Kern_MmSetAddressProtect },
        { 0x36B824, "MmQueryAddressProtect",          Kern_MmQueryAddressProtect },
        // 0x36B8F4 = XboxKrnlVersion (DATA)
        { 0x36B924, "ExAllocatePoolWithTag",          Kern_ExAllocatePoolWithTag },
        { 0x36B928, "ExFreePool",                     Kern_ExFreePool },
        { 0x36B918, "HalInitiateShutdown",            Kern_HalInitiateShutdown },
        { 0x36B92C, "HalGetInterruptVector",          Kern_HalGetInterruptVector },
        { 0x36B930, "KfRaiseIrql",                    Kern_KfRaiseIrql },
        { 0x36B934, "KeConnectInterrupt",             Kern_KeConnectInterrupt },
        { 0x36B938, "KeInitializeInterrupt",          Kern_KeInitializeInterrupt },
        { 0x36B93C, "KeStallExecutionProcessor",      Kern_KeStallExecutionProcessor },
        { 0x36B920, "XcHMAC",                         Kern_XcHMAC },
        // 0x36B7CC = XboxHDKey (DATA)
        { 0x36B814, "MmAllocateContiguousMemoryEx",   Kern_MmAllocateContiguousMemoryEx },
        { 0x36B818, "MmQueryAllocationSize",          Kern_MmQueryAllocationSize },
        { 0x36B8F8, "RtlEqualString",                 Kern_RtlEqualString },
        { 0x36B8FC, "XeLoadSection",                  Kern_XeLoadSection },
        { 0x36B900, "XeUnloadSection",                Kern_XeUnloadSection },
        // 0x36B7F4 = HalDiskCachePartitionCount (DATA)
        { 0x36B904, "NtFreeVirtualMemory",            Kern_NtFreeVirtualMemory },
        { 0x36B908, "NtAllocateVirtualMemory",        Kern_NtAllocateVirtualMemory },
        { 0x36B90C, "RtlCompareMemoryUlong",          Kern_RtlCompareMemoryUlong },
        { 0x36B910, "RtlInitializeCriticalSection",   Kern_RtlInitializeCriticalSection },
        { 0x36B914, "NtQueryVirtualMemory",           Kern_NtQueryVirtualMemory },
        // 0x36B91C = IdexChannelObject (DATA)
        { 0x36B940, "MmGetPhysicalAddress",           Kern_MmGetPhysicalAddress },
        { 0x36B944, "MmLockUnlockBufferPages",        Kern_MmLockUnlockBufferPages },
        { 0x36B948, "KeInsertQueueDpc",               Kern_KeInsertQueueDpc },
        { 0x36B94C, "MmLockUnlockPhysicalPage",       Kern_MmLockUnlockPhysicalPage },

        // AV
        { 0x36B958, "AvSetSavedDataAddress",          Kern_AvSetSavedDataAddress },
        { 0x36B950, "AvGetSavedDataAddress",          Kern_AvGetSavedDataAddress },
        { 0x36B954, "AvSendTVEncoderOption",          Kern_AvSendTVEncoderOption },
        { 0x36B95C, "AvSetDisplayMode",               Kern_AvSetDisplayMode },

        // HAL / PCI
        { 0x36B964, "HalReadWritePCISpace",           Kern_HalReadWritePCISpace },
        { 0x36B960, "KeDisconnectInterrupt",          Kern_KeDisconnectInterrupt },
        { 0x36B96C, "DbgPrint",                       Kern_DbgPrint },
        { 0x36B968, "MmClaimGpuInstanceMemory",       Kern_MmClaimGpuInstanceMemory },
        { 0x36B8C8, "KeSaveFloatingPointState",       Kern_KeSaveFloatingPointState },
        { 0x36B8CC, "KeRestoreFloatingPointState",    Kern_KeRestoreFloatingPointState },
        { 0x36B970, "ExQueryPoolBlockSize",           Kern_ExQueryPoolBlockSize },
        { 0x36B974, "KeRemoveQueueDpc",               Kern_KeRemoveQueueDpc },
        { 0x36B978, "KeSynchronizeExecution",         Kern_KeSynchronizeExecution },

        // Network
        { 0x36B97C, "PhyGetLinkState",                Kern_PhyGetLinkState },
        { 0x36B980, "PhyInitialize",                  Kern_PhyInitialize },

        // Crypto
        { 0x36B990, "XcDESKeyParity",                Kern_XcDESKeyParity },
        { 0x36B988, "XcBlockCryptCBC",               Kern_XcBlockCryptCBC },
        { 0x36B98C, "XcKeyTable",                    Kern_XcKeyTable },
        { 0x36B99C, "XcModExp",                      Kern_XcModExp },
        // 0x36B9AC = XboxLANKey (DATA)
        { 0x36B994, "XcRC4Crypt",                    Kern_XcRC4Crypt },
        { 0x36B998, "XcRC4Key",                      Kern_XcRC4Key },

        // Performance counters
        { 0x36B9C0, "KeQueryPerformanceCounter",      Kern_KeQueryPerformanceCounter },
        { 0x36B9C4, "KeQueryPerformanceFrequency",    Kern_KeQueryPerformanceFrequency },
        // 0x36B9C8 = HalDiskSerialNumber (DATA)
        // 0x36B9CC = HalDiskModelNumber (DATA)
        { 0x36B9D0, "MmQueryStatistics",              Kern_MmQueryStatistics },
        { 0x36B9D4, "NtSetSystemTime",                Kern_NtSetSystemTime },
        { 0x36B9E0, "RtlUnwind",                     Kern_RtlUnwind },
        { 0x36B9E4, "KeBugCheck",                     Kern_KeBugCheck },
        { 0x36BA08, "HalIsResetOrShutdownPending",    Kern_HalIsResetOrShutdownPending },

        // I/O manager (low-level - stubbed)
        { 0x36B9B0, "IofCallDriver",                  Kern_IofCallDriver },
        { 0x36B9B4, "IoBuildSynchronousFsdRequest",   Kern_IoBuildSynchronousFsdRequest },
        { 0x36B9E8, "IofCompleteRequest",             Kern_IofCompleteRequest },
        { 0x36B9EC, "IoSynchronousFsdRequest",        Kern_IoSynchronousFsdRequest },
        { 0x36B9F0, "IoSynchronousDeviceIoControlRequest", Kern_IoSynchronousDeviceIoControlRequest },
        { 0x36B9F4, "IoCreateDevice",                 Kern_IoCreateDevice },
        { 0x36B9F8, "IoInvalidDeviceRequest",         Kern_IoInvalidDeviceRequest },
        { 0x36B9FC, "IoStartPacket",                  Kern_IoStartPacket },
        { 0x36BA00, "IoStartNextPacket",              Kern_IoStartNextPacket },
        { 0x36BA04, "IoMarkIrpMustComplete",          Kern_IoMarkIrpMustComplete },

        // Kernel stacks
        { 0x36B9D8, "MmDeleteKernelStack",            Kern_MmDeleteKernelStack },
        { 0x36B9DC, "MmCreateKernelStack",            Kern_MmCreateKernelStack },

        // Xbox signature / data exports handled as DATA below
        // 0x36B7D0 = XboxSignatureKey (DATA)
        // 0x36B7D4 = XboxAlternateSignatureKeys (DATA)
        // 0x36B85C = IoFileObjectType (DATA)
    };

    int hooked = 0;
    for (auto& t : thunks)
    {
        HookThunk(t.addr, t.func, t.name);
        hooked++;
    }

    // -----------------------------------------------------------------------
    // Data exports: allocate guest memory and write pointer into IAT slot.
    // -----------------------------------------------------------------------

    // KeTickCount (4 bytes)
    // The guest GetTickCount() stub reads [[KeTickCount IAT]], so the pointed-to
    // value must be updated continuously.
    {
        uint32_t addr = InitDataExport(0x36B8C0, 4);
        // Write the initial value.
        {
            auto now = std::chrono::high_resolution_clock::now();
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - g_bootTime).count();
            X86_MEM_WRITE_u32(g_memory.base, addr, static_cast<uint32_t>(ms));
        }
        // Background thread: keep KeTickCount ticking every 1 ms.
        std::thread([addr]() {
            while (true) {
                auto now = std::chrono::high_resolution_clock::now();
                auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - g_bootTime).count();
                X86_MEM_WRITE_u32(g_memory.base, addr, static_cast<uint32_t>(ms));
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }).detach();
    }

    // ExEventObjectType (4 bytes)
    InitDataExport(0x36B864, 4);

    // LaunchDataPage (4096 bytes)
    InitDataExport(0x36B834, 4096);

    // XboxHardwareInfo (16 bytes)
    {
        uint32_t addr = InitDataExport(0x36B8D0, 16);
        X86_MEM_WRITE_u32(g_memory.base, addr + 0, 0x00000004); // Flags
    }

    // PsThreadObjectType (4 bytes)
    InitDataExport(0x36B888, 4);

    // XeImageFileName (ANSI_STRING = 8 bytes)
    InitDataExport(0x36B8D8, 64);

    // XePublicKeyData (Xbox RSA-1024 public key, 284 bytes)
    InitDataExport(0x36B9A8, 284);

    // HalBootSMCVideoMode (4 bytes)
    {
        uint32_t addr = InitDataExport(0x36B828, 4);
        X86_MEM_WRITE_u32(g_memory.base, addr, 0x01);
    }

    // XboxKrnlVersion (8 bytes)
    {
        uint32_t addr = InitDataExport(0x36B8F4, 8);
        X86_MEM_WRITE_u16(g_memory.base, addr + 0, 1);
        X86_MEM_WRITE_u16(g_memory.base, addr + 2, 0);
        X86_MEM_WRITE_u16(g_memory.base, addr + 4, 5838);
        X86_MEM_WRITE_u16(g_memory.base, addr + 6, 1);
    }

    // XboxHDKey (16 bytes)
    {
        uint32_t addr = InitDataExport(0x36B7CC, 16);
        memset(g_memory.Translate(addr), 0xAB, 16);
    }

    // HalDiskCachePartitionCount (4 bytes)
    {
        uint32_t addr = InitDataExport(0x36B7F4, 4);
        X86_MEM_WRITE_u32(g_memory.base, addr, 3);
    }

    // IdexChannelObject (32 bytes)
    InitDataExport(0x36B91C, 32);

    // XboxLANKey (16 bytes)
    {
        uint32_t addr = InitDataExport(0x36B9AC, 16);
        memset(g_memory.Translate(addr), 0xCD, 16);
    }

    // HalDiskSerialNumber (ANSI_STRING + buffer)
    InitDataExport(0x36B9C8, 32);

    // HalDiskModelNumber (ANSI_STRING + buffer)
    InitDataExport(0x36B9CC, 48);

    // XboxSignatureKey (16 bytes)
    InitDataExport(0x36B7D0, 16);

    // XboxAlternateSignatureKeys (16 * 16 bytes)
    InitDataExport(0x36B7D4, 256);

    // IoFileObjectType (4 bytes)
    InitDataExport(0x36B85C, 4);

    // Hook remaining addresses with Kern_Unknown fallback.
    for (int i = 0; g_kernelImports[i].name != nullptr; i++)
    {
        uint32_t addr = g_kernelImports[i].thunkAddr;
        if (g_funcMap.find(addr) == g_funcMap.end())
        {
            HookThunk(addr, Kern_Unknown);
        }
    }

    fprintf(stdout, "[Kernel] Registered %d named kernel stubs + data exports.\n", hooked);
}
