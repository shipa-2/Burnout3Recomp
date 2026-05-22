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
#include "kernel/xdm.h"
#include "kernel/guest_thread.h"

// ---------------------------------------------------------------------------
// Guest heap layout within the 512 MB address space:
//
//   0x00000000 - 0x0000FFFF : Reserved (null guard + low memory)
//   0x00010000 - 0x00944BE0 : XBE image (code + data sections)
//   0x00945000 - 0x18000000 : Xbox CRT virtual-memory pool (~375 MB)
//                             Managed by GuestVMAlloc (bump allocator).
//                             Backing store for NtAllocateVirtualMemory:
//                             TiMidity GUS patches (~150 MB) + Doom zone heap.
//   0x18000000 - 0x1C000000 : HLE o1heap (64 MB, HEAP_SIZE)
//                             Used only by HLE code (DSound buffers, thread
//                             stacks, kernel objects, etc.).
//   0x1C000000 - 0x1FEF0000 : D3D contiguous GPU memory (ContigAlloc, ~63 MB)
//                             Bump allocator for VBs, textures, surfaces, RTs.
//                             Must stay below STACK_TOP-STACK_SIZE = 0x1FEF0000.
//   0x1FEF0000 - 0x1FFFFFFF : Stack region (1 MB, STACK_SIZE)
//
// IMPORTANT: g_heap (0x18000000–0x1C000000) and ContigAlloc (0x1C000000+)
// must never overlap.  ContigAlloc was previously at 0x19000000 which fell
// inside the g_heap arena, causing guest thread stacks / DSound buffers
// allocated from g_heap to corrupt D3D VB headers allocated by ContigAlloc.
// ---------------------------------------------------------------------------

static constexpr uint32_t HEAP_BASE  = 0x18000000; // HLE o1heap starts here
static constexpr uint32_t HEAP_SIZE  = 0x04000000; // 64 MB — Xbox had 64 MB unified RAM
static constexpr uint32_t STACK_TOP  = 0x1FFF0000; // Stack grows downward
static constexpr uint32_t STACK_SIZE = 0x00100000; // 1 MB stack

int main(int argc, char* argv[])
{
    // Make all output unbuffered so log entries survive crashes.
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);

    fprintf(stdout, "=== Burnout 3 Recompiled ===\n");
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

        // --- KPRCB (allocated from HLE o1heap at 0x18000000+) ---
        // The Xbox KPRCB is ~0x254 bytes.  RtlAllocateHeap reads
        // [Prcb+0x250] for a heap-tracing callback table; it must
        // stay NULL (retail Xbox never sets it).  We allocate the
        // KPRCB from the HLE heap so it sits at 0x18xxxxxx — far
        // from the first page, the XBE image, and the guest VM pool,
        // so no recompiled code can accidentally overwrite it.
        uint32_t kprcbAddr = g_heap.AllocGuestAligned(0x280, 64);
        memset(b + kprcbAddr, 0, 0x280);
        // KPRCB.CurrentThread (offset 0x00)
        *(uint32_t*)(b + kprcbAddr) = KTHREAD_ADDR;
        fprintf(stderr, "[KPCR] KPRCB allocated at guest 0x%08X\n", kprcbAddr);

        // --- KPCR fields (mapped to fs:) ---
        // fs:[0x04] = ThreadLocalStoragePointer (set below)
        // fs:[0x08] = StackLimit
        *(uint32_t*)(b + 0x08) = STACK_TOP - STACK_SIZE;
        // fs:[0x18] = NT_TIB.Self
        *(uint32_t*)(b + 0x18) = 0;
        // fs:[0x1C] = SelfPcr (pointer to this KPCR; KPCR base is addr 0)
        *(uint32_t*)(b + 0x1C) = 0;
        // fs:[0x20] = Prcb (pointer to KPRCB in HLE heap)
        *(uint32_t*)(b + 0x20) = kprcbAddr;
        // fs:[0x28] = PrcbData.CurrentThread (kept for code that reads
        //             the inline KPRCB directly via fs:[0x28])
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

    // On real Xbox the process stays alive as long as any thread exists.
    // _xstart creates the game thread and returns immediately, so we must
    // wait for all guest threads here to prevent the CRT from tearing
    // down g_memory while they (and the KeTickCount thread) are still running.
    for (auto* obj : g_kernelObjects)
    {
        if (auto* gt = dynamic_cast<GuestThread*>(obj))
            gt->Wait(UINT32_MAX);
    }

    fprintf(stdout, "\n[Main] Guest execution returned (eax=0x%08X).\n", ctx.eax);
    return 0;
}
