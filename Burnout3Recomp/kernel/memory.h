#pragma once

#include <cstdint>
#include <cstdio>
#include <x86_config.h>
#include <x86_context.h>

// Global guest memory block (X86_RAM_SIZE bytes).
// All recompiled code accesses memory through base + offset.
struct Memory
{
    uint8_t* base = nullptr;

    Memory();
    ~Memory();

    // Guest address -> host pointer
    void* Translate(uint32_t offset) const { return base + offset; }

    // Host pointer -> guest address
    uint32_t MapVirtual(const void* host) const
    {
        return static_cast<uint32_t>(reinterpret_cast<const uint8_t*>(host) - base);
    }

    bool IsInRange(const void* host) const
    {
        auto* p = reinterpret_cast<const uint8_t*>(host);
        return p >= base && p < base + X86_RAM_SIZE;
    }
};

extern Memory g_memory;
