#include "heap.h"
#include "memory.h"
#include <o1heap.h>
#include <cstdio>

Heap g_heap;

void Heap::Init(uint32_t guestBase, uint32_t guestSize)
{
    m_guestBase = guestBase;
    m_guestEnd  = guestBase + guestSize;

    // o1heap operates directly on the guest memory arena.
    void* arenaPtr = g_memory.Translate(guestBase);
    m_heap = o1heapInit(arenaPtr, guestSize);

    if (!m_heap)
    {
        fprintf(stderr, "[Heap] FATAL: o1heapInit failed!\n");
        return;
    }

    O1HeapDiagnostics diag = o1heapGetDiagnostics(m_heap);
    fprintf(stdout, "[Heap] Initialized (o1heap): 0x%08X - 0x%08X (%u KB, capacity %zu KB)\n",
            m_guestBase, m_guestEnd, guestSize / 1024,
            diag.capacity / 1024);
}

uint32_t Heap::AllocGuest(size_t size)
{
    return AllocGuestAligned(size, O1HEAP_ALIGNMENT);
}

uint32_t Heap::AllocGuestAligned(size_t size, size_t alignment)
{
    std::lock_guard lock(m_mutex);

    if (!m_heap || size == 0)
        return 0;

    // o1heap guarantees O1HEAP_ALIGNMENT (32 bytes on 64-bit).
    // For larger alignments, over-allocate and adjust.
    if (alignment <= O1HEAP_ALIGNMENT)
    {
        void* ptr = o1heapAllocate(m_heap, size);
        if (!ptr)
        {
            O1HeapDiagnostics diag = o1heapGetDiagnostics(m_heap);
            fprintf(stderr, "[Heap] OOM: requested %zu bytes (allocated %zu / %zu)\n",
                    size, diag.allocated, diag.capacity);
            return 0;
        }
        uint32_t guestAddr = g_memory.MapVirtual(ptr);
        m_sizeMap[guestAddr] = size;
        return guestAddr;
    }

    // Over-allocate for large alignment.
    size_t extra = size + alignment;
    void* raw = o1heapAllocate(m_heap, extra);
    if (!raw)
    {
        O1HeapDiagnostics diag = o1heapGetDiagnostics(m_heap);
        fprintf(stderr, "[Heap] OOM (aligned): requested %zu+%zu bytes (allocated %zu / %zu)\n",
                size, alignment, diag.allocated, diag.capacity);
        return 0;
    }

    // Align within the over-allocated block.
    uintptr_t addr = reinterpret_cast<uintptr_t>(raw);
    uintptr_t aligned = (addr + alignment - 1) & ~(alignment - 1);
    if (aligned == addr)
        aligned += alignment; // ensure room for header

    // Store the real pointer just before the aligned address so Free can find it.
    reinterpret_cast<void**>(aligned)[-1] = raw;

    uint32_t guestAddr = g_memory.MapVirtual(reinterpret_cast<void*>(aligned));
    m_sizeMap[guestAddr] = size;
    return guestAddr;
}

void Heap::FreeGuest(uint32_t guestAddr)
{
    std::lock_guard lock(m_mutex);

    if (!m_heap || guestAddr == 0)
        return;
    if (guestAddr < m_guestBase || guestAddr >= m_guestEnd)
        return;

    // Only free addresses that were originally returned by AllocGuest.
    // The Xbox CRT passes sub-block offsets (inside a larger o1heap allocation)
    // to NtFreeVirtualMemory when it coalesces pages internally.  Those are
    // not root o1heap pointers, so attempting o1heapFree on them triggers the
    // "size >= minimum fragment" assertion.  Skip untracked addresses.
    auto it = m_sizeMap.find(guestAddr);
    if (it == m_sizeMap.end())
        return;
    m_sizeMap.erase(it);

    void* ptr = g_memory.Translate(guestAddr);
    o1heapFree(m_heap, ptr);
}

size_t Heap::QuerySize(uint32_t guestAddr)
{
    std::lock_guard lock(m_mutex);
    auto it = m_sizeMap.find(guestAddr);
    if (it != m_sizeMap.end())
        return it->second;
    return 0;
}

void* Heap::Alloc(size_t size)
{
    uint32_t guest = AllocGuest(size);
    return guest ? g_memory.Translate(guest) : nullptr;
}

void* Heap::AllocAligned(size_t size, size_t alignment)
{
    uint32_t guest = AllocGuestAligned(size, alignment);
    return guest ? g_memory.Translate(guest) : nullptr;
}

void Heap::Free(void* ptr)
{
    if (ptr && g_memory.IsInRange(ptr))
        FreeGuest(g_memory.MapVirtual(ptr));
}
