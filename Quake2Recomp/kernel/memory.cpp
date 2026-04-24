#include "memory.h"
#include <cstring>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#else
#include <sys/mman.h>
#endif

Memory g_memory;

Memory::Memory()
{
#ifdef _WIN32
    base = static_cast<uint8_t*>(
        VirtualAlloc(nullptr, X86_RAM_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));

    if (base)
    {
        // First page is left read/write: the recompiler maps fs: segment
        // accesses (TIB / SEH chain) to guest address 0, so it must be
        // accessible.  Zero the page so flat null-pointer reads return 0
        // (matching the Xbox null page).  __SEH_prolog will overwrite
        // fs:[0] with a real frame pointer before any exception code runs.
        memset(base, 0, 4096);
    }
#else
    base = static_cast<uint8_t*>(
        mmap(nullptr, X86_RAM_SIZE, PROT_READ | PROT_WRITE,
             MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));

    if (base == reinterpret_cast<uint8_t*>(MAP_FAILED))
        base = nullptr;
    else
    {
        // First page left read/write for TIB / SEH chain emulation.
        // Zero the page so flat null-pointer reads return 0 (matching Xbox).
        memset(base, 0, 4096);
    }
#endif

    if (!base)
    {
        fprintf(stderr, "[Memory] Failed to allocate %llu bytes of guest memory.\n",
                static_cast<unsigned long long>(X86_RAM_SIZE));
    }
    else
    {
        fprintf(stdout, "[Memory] Allocated %llu MB guest memory at %p\n",
                static_cast<unsigned long long>(X86_RAM_SIZE / (1024 * 1024)), base);
    }
}

Memory::~Memory()
{
    if (!base)
        return;

#ifdef _WIN32
    VirtualFree(base, 0, MEM_RELEASE);
#else
    munmap(base, X86_RAM_SIZE);
#endif

    base = nullptr;
}
