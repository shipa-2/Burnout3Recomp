#include <cstdio>
#include <cstring>

#include <x86_config.h>
#include <x86_context.h>
#include <x86_recomp_shared.h>

#include "kernel/memory.h"
#include "kernel/heap.h"
#include "kernel/imports.h"
#include "kernel/xbe_loader.h"
#include "kernel/file_io.h"

// ---------------------------------------------------------------------------
// Guest heap layout within the 512 MB address space:
//
//   0x00000000 - 0x0000FFFF : Reserved (null guard + low memory)
//   0x00010000 - 0x0017A580 : XBE image (code + data sections)
//   0x00200000 - 0x18000000 : Xbox CRT virtual-memory pool (382 MB)
//                             Managed by GuestVMAlloc (bump allocator).
//                             Backing store for NtAllocateVirtualMemory:
//                             TiMidity GUS patches (~150 MB) + Doom zone heap.
//   0x18000000 - 0x18800000 : HLE o1heap (8 MB)
//                             Used only by HLE code (DSound objects, etc.).
//   0x19000000 - 0x1A800000 : D3D contiguous GPU memory (ContigAlloc, 24 MB)
//   0x1F000000 - 0x1FFFFFFF : Stack region (~16 MB)
//
// IMPORTANT: The two allocators must never overlap.
// ---------------------------------------------------------------------------

static constexpr uint32_t HEAP_BASE  = 0x18000000; // HLE o1heap starts here
static constexpr uint32_t HEAP_SIZE  = 0x00800000; // 8 MB — HLE allocations only
static constexpr uint32_t STACK_TOP  = 0x1FFF0000; // Stack grows downward
static constexpr uint32_t STACK_SIZE = 0x00100000; // 1 MB stack

int main(int argc, char* argv[])
{
    // Make all output unbuffered so log entries survive crashes.
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);

    fprintf(stdout, "=== DoomX Recompiled ===\n");
    fprintf(stdout, "Image base: 0x%08X  Size: 0x%08X\n",
            (uint32_t)X86_IMAGE_BASE, (uint32_t)X86_IMAGE_SIZE);
    fprintf(stdout, "Entry point: 0x%08X\n", (uint32_t)X86_ENTRY_POINT);
    fprintf(stdout, "RAM size: %llu MB\n\n",
            static_cast<unsigned long long>(X86_RAM_SIZE / (1024 * 1024)));

    // 1. Allocate guest memory.
    if (!g_memory.base)
    {
        fprintf(stderr, "FATAL: Could not allocate guest memory.\n");
        return 1;
    }

    // 2. Load XBE image data sections into guest memory.
    const char* xbePath = (argc > 1) ? argv[1] : "default.xbe";
    if (!LoadXbeImage(xbePath, g_memory.base))
    {
        fprintf(stderr, "FATAL: Could not load XBE image: %s\n", xbePath);
        fprintf(stderr, "  Pass path to default.xbe as first argument, or place it next to the exe.\n");
        return 1;
    }

    // 2b. Set game directory for file I/O path translation.
    SetGameDirectory(xbePath);

    // DEBUG: Dump the switch table at 0x8DB97 (8 entries) from loaded XBE
    {
        uint8_t* b = g_memory.base;
        fprintf(stderr, "[DEBUG] Switch table at 0x8DB97 (8 entries):\n");
        for (int i = 0; i < 8; i++) {
            uint32_t entry = *(uint32_t*)(b + 0x8DB97 + i * 4);
            fprintf(stderr, "  [%d] = 0x%08X\n", i, entry);
        }
    }

    // 3. Initialize guest heap.
    g_heap.Init(HEAP_BASE, HEAP_SIZE);

    // 4. Build unified function dispatch map from recompiled functions,
    //    then add kernel import stubs (populates IAT thunks in guest memory).
    X86_INIT_FUNC_MAP();
    KernelDispatch::Init();

    // 4b. Set up KPCR and TLS for the main thread.
    //     The recompiler maps fs:[N] to guest address N (first page).
    //     The Xbox KPCR at fs: contains NT_TIB fields, KPRCB, and the
    //     CRT accesses fs:[4] as the ThreadLocalStoragePointer.
    {
        uint8_t* b = g_memory.base;

        // --- KTHREAD structure (at guest address 0x200) ---
        constexpr uint32_t KTHREAD_ADDR = 0x200;
        memset(b + KTHREAD_ADDR, 0, 0x200);
        // KTHREAD+0x12C = UniqueThread (thread ID)
        *(uint32_t*)(b + KTHREAD_ADDR + 0x12C) = 1;

        // --- KPCR fields (mapped to fs:) ---
        // fs:[0x04] = ThreadLocalStoragePointer (set below)
        // fs:[0x08] = StackLimit
        *(uint32_t*)(b + 0x08) = STACK_TOP - STACK_SIZE;
        // fs:[0x18] = NT_TIB.Self
        *(uint32_t*)(b + 0x18) = 0;
        // fs:[0x28] = KPRCB.CurrentThread (inline KPRCB starts at +0x28)
        *(uint32_t*)(b + 0x28) = KTHREAD_ADDR;

        // --- TLS initialization from XBE TLS directory ---
        // XBE header offset 0x012C = dwTlsAddr (virtual addr of TLS directory)
        uint32_t tlsDirAddr = *(uint32_t*)(b + X86_IMAGE_BASE + 0x012C);

        // Allocate TLS pointer array (64 entries, zero-filled)
        uint32_t tlsArrayAddr = g_heap.AllocGuest(64 * 4);
        memset(b + tlsArrayAddr, 0, 64 * 4);

        if (tlsDirAddr && tlsDirAddr < X86_RAM_SIZE - 24) {
            // XBE_TLS_DIRECTORY: StartAddr(4) EndAddr(4) IndexAddr(4)
            //                    CallbackAddr(4) ZeroFill(4) Characteristics(4)
            uint32_t dataStart = *(uint32_t*)(b + tlsDirAddr + 0);
            uint32_t dataEnd   = *(uint32_t*)(b + tlsDirAddr + 4);
            uint32_t indexAddr = *(uint32_t*)(b + tlsDirAddr + 8);
            uint32_t zeroFill  = *(uint32_t*)(b + tlsDirAddr + 16);

            uint32_t templateSize = (dataEnd > dataStart) ? (dataEnd - dataStart) : 0;
            uint32_t totalSize    = templateSize + zeroFill;
            if (totalSize < 256) totalSize = 256; // minimum for CRT per-thread data

            // Allocate and populate TLS data block
            uint32_t tlsDataAddr = g_heap.AllocGuest(totalSize);
            memset(b + tlsDataAddr, 0, totalSize);
            if (templateSize > 0 && dataStart < X86_RAM_SIZE)
                memcpy(b + tlsDataAddr, b + dataStart, templateSize);

            // Set _tls_index = 0 (main executable is always TLS module 0)
            if (indexAddr && indexAddr < X86_RAM_SIZE)
                *(uint32_t*)(b + indexAddr) = 0;

            // TLS pointer array slot 0 = TLS data block
            *(uint32_t*)(b + tlsArrayAddr) = tlsDataAddr;

            fprintf(stderr, "[TLS] Dir @ 0x%06X: data=[0x%06X..0x%06X) zeroFill=%u indexAddr=0x%06X\n",
                    tlsDirAddr, dataStart, dataEnd, zeroFill, indexAddr);
            fprintf(stderr, "[TLS] Data block @ 0x%06X (%u bytes), Array @ 0x%06X\n",
                    tlsDataAddr, totalSize, tlsArrayAddr);
        } else {
            fprintf(stderr, "[TLS] No TLS directory in XBE (tlsAddr=0x%08X)\n", tlsDirAddr);
            // Still provide a minimal zeroed TLS data block
            uint32_t tlsDataAddr = g_heap.AllocGuest(256);
            memset(b + tlsDataAddr, 0, 256);
            *(uint32_t*)(b + tlsArrayAddr) = tlsDataAddr;
        }

        // fs:[4] = pointer to TLS array
        *(uint32_t*)(b + 0x04) = tlsArrayAddr;
        fprintf(stderr, "[KPCR] KTHREAD @ 0x%06X, TLS array @ fs:[4] = 0x%06X\n",
                KTHREAD_ADDR, tlsArrayAddr);
    }

    // 5. Initialize CPU context.
    X86Context ctx{};
    memset(&ctx, 0, sizeof(ctx));

    //    Stack pointer: top of stack region (grows downward).
    ctx.esp = STACK_TOP;
    ctx.ebp = STACK_TOP;

    //    FPU: default control word (round-to-nearest, all exceptions masked).
    ctx.fp_control = 0x037F;
    ctx.fp_status  = 0;
    ctx.fp_top     = 0;

    fprintf(stdout, "[Main] Starting execution at 0x%08X (esp=0x%08X)\n\n",
            (uint32_t)X86_ENTRY_POINT, ctx.esp);

    // 6. Call the entry point (_xstart).
    //    The override in hle_xapi.cpp replaces the recompiled version,
    //    performing CRT init and waiting for the game thread to finish.
    _xstart(ctx, g_memory.base);

    fprintf(stdout, "\n[Main] Guest execution returned (eax=0x%08X).\n", ctx.eax);
    return 0;
}
