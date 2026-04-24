#pragma once

#include <x86_context.h>

// Helpers for reading stdcall arguments from the guest stack.
// A return address sits at [esp+0] (pushed by the caller / X86_CALL_INDIRECT).
// Arguments start at [esp+4].

inline uint32_t GuestArg32(X86Context& ctx, uint8_t* base, int index)
{
    return X86_MEM_READ_u32(base, ctx.esp + 4 + index * 4);
}

inline void* GuestArgPtr(X86Context& ctx, uint8_t* base, int index)
{
    uint32_t addr = GuestArg32(ctx, base, index);
    return addr ? (base + addr) : nullptr;
}

// Clean up N bytes of arguments (stdcall callee-cleanup).
// The return address is handled by the caller's push/pop pattern.
inline void GuestStackCleanup(X86Context& ctx, int numBytes)
{
    ctx.esp += numBytes;
}

// Set return value (in eax for 32-bit, edx:eax for 64-bit).
inline void GuestReturn32(X86Context& ctx, uint32_t value)
{
    ctx.eax = value;
}

inline void GuestReturn64(X86Context& ctx, uint64_t value)
{
    ctx.eax = static_cast<uint32_t>(value);
    ctx.edx = static_cast<uint32_t>(value >> 32);
}
