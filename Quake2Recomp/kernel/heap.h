#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <unordered_map>

struct O1HeapInstance;

// Guest heap allocator backed by o1heap.
// Manages allocations within the guest memory address space.
// Thread-safe: all public methods are mutex-protected.

struct Heap
{
    void Init(uint32_t guestBase, uint32_t guestSize);

    void* Alloc(size_t size);
    void* AllocAligned(size_t size, size_t alignment);
    void  Free(void* ptr);

    uint32_t AllocGuest(size_t size);
    uint32_t AllocGuestAligned(size_t size, size_t alignment);
    void     FreeGuest(uint32_t guestAddr);
    size_t   QuerySize(uint32_t guestAddr);

private:
    std::mutex m_mutex;
    O1HeapInstance* m_heap = nullptr;
    uint32_t m_guestBase = 0;
    uint32_t m_guestEnd  = 0;
    std::unordered_map<uint32_t, size_t> m_sizeMap;
};

extern Heap g_heap;
