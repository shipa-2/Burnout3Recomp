#pragma once

#include <cstdint>
#include <cstring>
#include <atomic>
#include <thread>
#include <functional>
#include "xdm.h"
#include "memory.h"
#include "heap.h"
#include <x86_context.h>

// ---------------------------------------------------------------------------
// Guest thread parameters (mirrors OG Xbox PsCreateSystemThreadEx args)
// ---------------------------------------------------------------------------

struct GuestThreadParams
{
    uint32_t startAddress;  // Guest function address
    uint32_t startContext;  // Argument passed to the thread function (via stack)
    uint32_t stackSize;     // Requested stack size (0 = default)
    bool     suspended;     // Start in suspended state (wait for Resume())
};

// ---------------------------------------------------------------------------
// GuestThread: a real host thread running recompiled guest code.
// Inherits KernelObject so NtWaitForSingleObject can join on it.
// ---------------------------------------------------------------------------

struct GuestThread final : KernelObject
{
    GuestThreadParams params;
    std::atomic<bool> finished{false};
    std::thread thread;
    uint32_t exitCode = 0;

    // Suspend / resume gate.
    std::mutex              suspendMutex;
    std::condition_variable suspendCv;
    bool                    isSuspended = false; // protected by suspendMutex

#ifdef _WIN32
    HANDLE hFinishedEvent = nullptr; // Signaled when thread completes.
#endif

    // Per-thread stack allocation in guest memory.
    uint32_t stackBase = 0;  // Guest address of allocated stack
    uint32_t stackSize = 0;

    static constexpr uint32_t DEFAULT_STACK_SIZE = 0x10000; // 64 KB

    GuestThread(const GuestThreadParams& p)
        : params(p)
        , isSuspended(p.suspended)
    {
#ifdef _WIN32
        hFinishedEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
#endif
        stackSize = (p.stackSize > 0) ? p.stackSize : DEFAULT_STACK_SIZE;
        // Align stack size to 4K.
        stackSize = (stackSize + 0xFFF) & ~0xFFFu;

        // Allocate stack from guest heap.
        stackBase = g_heap.AllocGuestAligned(stackSize, 4096);
        fprintf(stderr, "[GuestThread] alloc stack: base=0x%08X size=0x%X top=0x%08X start=0x%08X\n",
                stackBase, stackSize, stackBase + stackSize - 16, p.startAddress);

        // Launch the host thread.
        thread = std::thread(&GuestThread::ThreadEntry, this);
    }

    ~GuestThread() override
    {
        if (thread.joinable())
            thread.join();

#ifdef _WIN32
        if (hFinishedEvent) CloseHandle(hFinishedEvent);
#endif

        // Free the guest stack.
        if (stackBase)
            g_heap.FreeGuest(stackBase);
    }

    bool Wait(uint32_t timeoutMs) override
    {
#ifdef _WIN32
        DWORD ms = (timeoutMs == UINT32_MAX) ? INFINITE : static_cast<DWORD>(timeoutMs);
        return WaitForSingleObject(hFinishedEvent, ms) == WAIT_OBJECT_0;
#else
        if (finished.load(std::memory_order_acquire))
            return true;

        if (timeoutMs == 0)
            return finished.load(std::memory_order_acquire);

        // Block until the thread finishes.
        if (thread.joinable())
            thread.join();

        return true;
#endif
    }

#ifdef _WIN32
    HANDLE GetNativeHandle() override { return hFinishedEvent; }
#endif

    uint32_t GetThreadId() const
    {
        auto id = thread.get_id();
        // Simple hash of the thread ID.
        return static_cast<uint32_t>(std::hash<std::thread::id>{}(id));
    }

    static uint32_t GetCurrentThreadId()
    {
        return static_cast<uint32_t>(
            std::hash<std::thread::id>{}(std::this_thread::get_id()));
    }

    // Resume a previously-suspended thread.
    void Resume()
    {
        std::lock_guard<std::mutex> lk(suspendMutex);
        if (isSuspended)
        {
            isSuspended = false;
            suspendCv.notify_one();
        }
    }

private:
    void ThreadEntry()
    {
        // If created suspended, wait here until Resume() is called.
        {
            std::unique_lock<std::mutex> lk(suspendMutex);
            suspendCv.wait(lk, [this]{ return !isSuspended; });
        }
        // Each guest thread gets its own X86Context.
        X86Context ctx{};
        memset(&ctx, 0, sizeof(ctx));

        // Set up the stack pointer (stack grows downward).
        uint32_t stackTop = stackBase + stackSize - 16; // 16-byte align
        ctx.esp = stackTop;
        ctx.ebp = stackTop;

        // FPU defaults.
        ctx.fp_control = 0x037F;
        ctx.fp_status  = 0;
        ctx.fp_top     = 0;

        // Push the start context (thread parameter) onto the stack as
        // the first argument for the stdcall thread start routine.
        ctx.esp -= 4;
        X86_MEM_WRITE_u32(g_memory.base, ctx.esp, params.startContext);
        // Simulate the x86 'call' instruction: push a dummy return address so that
        // the start routine sees [esp+0]=retaddr, [esp+4]=startContext, matching
        // the stdcall convention used in all recompiled functions.
        ctx.esp -= 4;
        X86_MEM_WRITE_u32(g_memory.base, ctx.esp, 0);

        // Look up and call the guest start routine.
        auto it = g_funcMap.find(params.startAddress);
        if (it != g_funcMap.end())
        {
            fprintf(stderr, "[GuestThread] Thread started at 0x%08X (ctx=0x%08X)\n",
                    params.startAddress, params.startContext);
            it->second(ctx, g_memory.base);
            ctx.esp += 4; // pop dummy return address
            fprintf(stderr, "[GuestThread] Thread at 0x%08X returned (eax=0x%08X)\n",
                    params.startAddress, ctx.eax);
        }
        else
        {
            fprintf(stderr, "[GuestThread] ERROR: No recompiled function at 0x%08X\n",
                    params.startAddress);
        }

        exitCode = ctx.eax;
        finished.store(true, std::memory_order_release);
#ifdef _WIN32
        SetEvent(hFinishedEvent);
#endif
        finished.notify_all();
    }
};
