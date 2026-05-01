#pragma once

#include "x86_config.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <chrono>
#ifdef _MSC_VER
#include <intrin.h>
#pragma intrinsic(_ReturnAddress)
#endif

#ifdef _WIN32
// Windows.h pulls in a lot; keep include-order minimal. DbgHelp is used by
// the watchpoint/tracer stack-dump helper below.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

// Print a symbolicated host-side stack trace to stderr. Skips the top
// `framesToSkip` frames (caller, etc.) and prints up to `maxFrames`.
inline void x86_print_host_stack(const char* tag, unsigned framesToSkip = 1, unsigned maxFrames = 32) {
    static bool s_symInit = false;
    if (!s_symInit) {
        SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_DEFERRED_LOADS | SYMOPT_UNDNAME);
        SymInitialize(GetCurrentProcess(), nullptr, TRUE);
        s_symInit = true;
    }
    void* frames[64];
    if (maxFrames > 64) maxFrames = 64;
    USHORT n = CaptureStackBackTrace(framesToSkip, maxFrames, frames, nullptr);

    HANDLE hProc = GetCurrentProcess();
    alignas(SYMBOL_INFO) char symBuf[sizeof(SYMBOL_INFO) + 256];
    SYMBOL_INFO* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf);
    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
    sym->MaxNameLen   = 255;
    IMAGEHLP_LINE64 line{};
    line.SizeOfStruct = sizeof(line);

    fprintf(stderr, "[STACK][%s] host backtrace (%u frames):\n", tag ? tag : "?", n);
    for (USHORT i = 0; i < n; ++i) {
        DWORD64 addr = reinterpret_cast<DWORD64>(frames[i]);
        DWORD64 disp = 0;
        const char* name = "<unknown>";
        if (SymFromAddr(hProc, addr, &disp, sym)) name = sym->Name;
        DWORD lineDisp = 0;
        if (SymGetLineFromAddr64(hProc, addr, &lineDisp, &line)) {
            fprintf(stderr, "  #%02u 0x%016llX  %s+0x%llX  (%s:%lu)\n",
                    i, (unsigned long long)addr, name, (unsigned long long)disp,
                    line.FileName, line.LineNumber);
        } else {
            fprintf(stderr, "  #%02u 0x%016llX  %s+0x%llX\n",
                    i, (unsigned long long)addr, name, (unsigned long long)disp);
        }
    }
    fflush(stderr);
}
#else
inline void x86_print_host_stack(const char*, unsigned = 1, unsigned = 32) {}
#endif

// ---- MSVC compatibility ----
#ifdef _MSC_VER
#define __builtin_unreachable() __assume(0)
#endif

// ---- Recompiler emits UNKNOWN_REG for switch-table dispatch. ----
// It is always the register loaded immediately before the switch (eax).
#define UNKNOWN_REG eax

// ---- Sub-register access macros ----
#define X86_REG16(r) (*(uint16_t*)&(r))
#define X86_REG8L(r) (*(uint8_t*)&(r))
#define X86_REG8H(r) (*((uint8_t*)&(r) + 1))

// ---- Original Xbox hardware MMIO regions (debug logging only) ----
#ifndef NDEBUG
// GPU (NV2A chip):  0xFD000000 - 0xFDFFFFFF
// APU (ACI/DSP56k): 0xFE800000 - 0xFE8FFFFF
#define X86_MMIO_GPU_BASE  0xFD000000u
#define X86_MMIO_GPU_END   0xFDFFFFFFu
#define X86_MMIO_APU_BASE  0xFE800000u
#define X86_MMIO_APU_END   0xFE8FFFFFu

inline const char* x86_mmio_region(uint32_t addr) {
    if (addr >= X86_MMIO_GPU_BASE && addr <= X86_MMIO_GPU_END) return "GPU";
    if (addr >= X86_MMIO_APU_BASE && addr <= X86_MMIO_APU_END) return "APU";
    return nullptr;
}

// Throttled MMIO access logger (capped at 200 messages to avoid log spam).
inline void x86_log_mmio(bool write, uint32_t addr, uint32_t sz, uint64_t val) {
    const char* region = x86_mmio_region(addr);
    if (!region) return;
    static int s_mmioLogCount = 0;
    if (s_mmioLogCount >= 200) return;
    fprintf(stderr, "[MMIO][%s] %s  addr=0x%08X  sz=%u  val=0x%llX\n",
            region, write ? "WRITE" : "READ ", addr, sz, (unsigned long long)val);
    if (++s_mmioLogCount == 200)
        fprintf(stderr, "[MMIO] log limit reached, suppressing further messages\n");
}
#else
inline void x86_log_mmio(bool, uint32_t, uint32_t, uint64_t) {}
#endif

// ---- Memory access helpers with bounds checking ----
// Xbox physical address translation: addresses >= X86_RAM_SIZE are
// contiguous/write-combined physical mappings (0x80000000+, 0xF0000000+, etc.).
// Mask to recover the guest virtual address within our flat allocation.
inline uint32_t x86_phys_translate(uint32_t a) {
    if (a >= X86_RAM_SIZE) a &= (X86_RAM_SIZE - 1);
    return a;
}

inline bool x86_mem_ok(uint32_t a, uint32_t sz) { return a <= X86_RAM_SIZE - sz; }

// Forward decl — defined further down alongside the D3D/DSound segment
// tracing helpers. Declared here so it's visible from the rd_* / wr_*
// helpers below.
inline void x86_seg_log(bool write, uint32_t addr, uint32_t sz, uint64_t val);

inline uint8_t  x86_rd_u8 (uint8_t* b, uint32_t a) { a = x86_phys_translate(a); if (!x86_mem_ok(a,1)) { x86_log_mmio(false,a,1,0); return 0; } uint8_t  v = *(uint8_t*) (b+a); x86_seg_log(false,a,1,v); return v; }
inline uint16_t x86_rd_u16(uint8_t* b, uint32_t a) { a = x86_phys_translate(a); if (!x86_mem_ok(a,2)) { x86_log_mmio(false,a,2,0); return 0; } uint16_t v = *(uint16_t*)(b+a); x86_seg_log(false,a,2,v); return v; }
inline uint32_t x86_rd_u32(uint8_t* b, uint32_t a) { a = x86_phys_translate(a); if (!x86_mem_ok(a,4)) { x86_log_mmio(false,a,4,0); return 0; } uint32_t v = *(uint32_t*)(b+a); x86_seg_log(false,a,4,v); return v; }
inline uint64_t x86_rd_u64(uint8_t* b, uint32_t a) { a = x86_phys_translate(a); if (!x86_mem_ok(a,8)) { x86_log_mmio(false,a,8,0); return 0; } uint64_t v = *(uint64_t*)(b+a); x86_seg_log(false,a,8,v); return v; }

// ---- D3D / DSound segment access tracing ----
//
// When the XBD3D8 / XBDSOUND static libraries are linked into the XBE, their
// internal globals end up in the main .data segment. Burnout 3 touches them
// both through the official SDK entry points (which we HLE) and through
// direct inlined reads/writes emitted by the compiler — most notably the
// MVP vertex-shader constants at 0x35FDF8, which are populated by inlined
// matrix pushes rather than D3DDevice_SetVertexShaderConstant* calls.
//
// Ranges derived from IDA: all D3D_* globals live in 0x35BE00..0x360A00,
// all DirectSound* globals live in 0x300000..0x300B40. After successive
// rounds of narrowing, only the deferred-texture-stage-state table is
// still worth watching: every other write we observed in the D3D segment
// turned out to be either a one-shot tuning global, an XBD3D8 internal
// readback shadow that mirrors a successful HLE Set* call, or a literal
// constant pool. Specifically dropped (with rationale):
//   * 0x35BE00..0x35D3FF — XBD3D8 .rdata-style literal pool (float consts
//     loaded by movss [imm32] in XDK math helpers; harmless).
//   * 0x35D6A0..0x35D6FF — push-buffer ptr pair + flag byte (XBD3D8
//     internal; HLE bypasses guest push buffer entirely).
//   * 0x35FB48 (D3D_pDevice push-buffer struct pointer).
//   * 0x35FB58..0x35FDF0 — D3D_g_RenderState marker, D3D_g_ComplexRenderState
//     and other XBD3D8 bookkeeping globals (HLE keeps render state in a
//     host array; guest copies are stale-but-harmless).
//   * 0x35FDF8..0x3607FF — VSH constant shadow. Inlined matrix pushes
//     copy into this shadow with `rep movsd` immediately before calling
//     D3DDevice_SetVertexShaderConstantNotInlineFast; our HLE captures
//     the constants from the setter's local-stack arg, so the shadow
//     write is redundant.
//   * 0x3609FC / 0x360A00 (D3D_CDevice_m_PushSegmentSize / CommandSize)
//     — one-shot tuning globals written by B3Main and never consulted by
//     HLE Direct3D_CreateDevice.
//
// Kept window:
//   [0x35D400..0x35D6A0)  covers D3D_g_DeferredTextureState @ 0x35D498
//                         (4 stages × 32 dwords = 512 B, ends at 0x35D698).
//
// DSound watch dropped: HLE DSound (hle_dsound.cpp) is functional, so the
// XBDSOUND static buffer pool at 0x300000..0x300B40 is populated with
// valid live state. The audio-emitter update loop in sub_1645A0 reads
// buffer state bytes / 3D-listener slots / position vec4s every frame;
// these are normal post-HLE reads, not symptoms of a missing handler.
#define X86_D3D_TSS_BASE       0x0035D400u
#define X86_D3D_TSS_END        0x0035D6A0u

// Runtime toggle: defaults to ON in debug builds, OFF in release.
// Override at runtime via the X86_TRACE_SEG env var ("0" to disable,
// any other non-empty value to enable).
//
// PERF NOTE: this used to be a function-local `static` initialized via a
// lambda. Every guest memory read/write goes through x86_seg_log(), which
// then called this accessor — and the magic-static guard (atomic load to
// check first-time initialization) was costing ~24% of total CPU on the
// guest hot path. Replacing it with an inline global initialized once at
// program startup (via a dummy static initializer) reduces the per-call
// cost to a single byte load that the compiler can hoist out of loops.
inline bool g_x86_seg_trace_enabled = []() {
    const char* e = std::getenv("X86_TRACE_SEG");
    if (e && *e) return *e != '0';
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
}();
inline bool& x86_seg_trace_enabled() { return g_x86_seg_trace_enabled; }

inline const char* x86_seg_region(uint32_t addr) {
    if (addr >= X86_D3D_TSS_BASE    && addr < X86_D3D_TSS_END)    return "D3D";
    return nullptr;
}

// Log at most 4k accesses, and de-duplicate consecutive hits to the same
// (addr, rw, size) key so repeated tight-loop reads don't flood the log.
//
// Split into a fast inline early-out and an out-of-line slow path. When
// tracing is disabled (the default in release) every memory access pays
// only a single byte-load + branch instead of a function call.
void x86_seg_log_slow(bool write, uint32_t addr, uint32_t sz, uint64_t val);
__forceinline void x86_seg_log(bool write, uint32_t addr, uint32_t sz, uint64_t val) {
    if (!g_x86_seg_trace_enabled) return;
    //x86_seg_log_slow(write, addr, sz, val);
}

inline void x86_wr_u8 (uint8_t* b, uint32_t a, uint8_t  v) { a = x86_phys_translate(a); x86_seg_log(true,a,1,v); if (!x86_mem_ok(a,1)) { x86_log_mmio(true,a,1,v); return; }
    *(uint8_t*) (b+a)=v; }
inline void x86_wr_u16(uint8_t* b, uint32_t a, uint16_t v) { a = x86_phys_translate(a); x86_seg_log(true,a,2,v); if (!x86_mem_ok(a,2)) { x86_log_mmio(true,a,2,v); return; }
    *(uint16_t*)(b+a)=v; }
inline void x86_wr_u32(uint8_t* b, uint32_t a, uint32_t v) { a = x86_phys_translate(a); x86_seg_log(true,a,4,v); if (!x86_mem_ok(a,4)) { x86_log_mmio(true,a,4,v); return; }
    *(uint32_t*)(b+a)=v; }
inline void x86_wr_u64(uint8_t* b, uint32_t a, uint64_t v) { a = x86_phys_translate(a); x86_seg_log(true,a,8,v); if (!x86_mem_ok(a,8)) { x86_log_mmio(true,a,8,v); return; }
    *(uint64_t*)(b+a)=v; }

#define X86_MEM_READ_u8(base, addr)   x86_rd_u8 ((base), (uint32_t)(addr))
#define X86_MEM_READ_u16(base, addr)  x86_rd_u16((base), (uint32_t)(addr))
#define X86_MEM_READ_u32(base, addr)  x86_rd_u32((base), (uint32_t)(addr))
#define X86_MEM_READ_u64(base, addr)  x86_rd_u64((base), (uint32_t)(addr))
#define X86_MEM_WRITE_u8(base, addr, v)  x86_wr_u8 ((base), (uint32_t)(addr), (uint8_t)(v))
#define X86_MEM_WRITE_u16(base, addr, v) x86_wr_u16((base), (uint32_t)(addr), (uint16_t)(v))
#define X86_MEM_WRITE_u32(base, addr, v) x86_wr_u32((base), (uint32_t)(addr), (uint32_t)(v))
#define X86_MEM_WRITE_u64(base, addr, v) x86_wr_u64((base), (uint32_t)(addr), (uint64_t)(v))

// ---- Floating-point memory access ----
inline float  x86_rd_f32(uint8_t* b, uint32_t a) { a = x86_phys_translate(a); if (!x86_mem_ok(a,4)) { x86_log_mmio(false,a,4,0); return 0.0f; } return *(float*) (b+a); }
inline double x86_rd_f64(uint8_t* b, uint32_t a) { a = x86_phys_translate(a); if (!x86_mem_ok(a,8)) { x86_log_mmio(false,a,8,0); return 0.0;  } return *(double*)(b+a); }
inline void x86_wr_f32(uint8_t* b, uint32_t a, float  v) { a = x86_phys_translate(a); if (!x86_mem_ok(a,4)) { x86_log_mmio(true,a,4,(uint32_t&)v); return; }
    *(float*) (b+a)=v; }
inline void x86_wr_f64(uint8_t* b, uint32_t a, double v) { a = x86_phys_translate(a); uint64_t bits; memcpy(&bits,&v,8); if (!x86_mem_ok(a,8)) { x86_log_mmio(true,a,8,(uint64_t&)v); return; }
    *(double*)(b+a)=v; }

#define X86_MEM_READ_F32(base, addr)  x86_rd_f32((base), (uint32_t)(addr))
#define X86_MEM_READ_F64(base, addr)  x86_rd_f64((base), (uint32_t)(addr))
#define X86_MEM_WRITE_F32(base, addr, v) x86_wr_f32((base), (uint32_t)(addr), (float)(v))
#define X86_MEM_WRITE_F64(base, addr, v) x86_wr_f64((base), (uint32_t)(addr), (double)(v))

// ---- 80-bit extended precision FPU memory access ----
inline double X86_MEM_READ_F80(uint8_t* base, uint32_t addr) {
    addr = x86_phys_translate(addr);
    if (addr + 10 > X86_RAM_SIZE) { x86_log_mmio(false, addr, 10, 0); return 0.0; }
    uint8_t* p = base + addr;
    uint64_t mantissa = *(uint64_t*)p;
    uint16_t expsign = *(uint16_t*)(p + 8);
    int sign = (expsign >> 15) & 1;
    int exponent = expsign & 0x7FFF;
    if (exponent == 0 && mantissa == 0) return sign ? -0.0 : 0.0;
    if (exponent == 0x7FFF) {
        if (mantissa & 0x7FFFFFFFFFFFFFFFull) return std::numeric_limits<double>::quiet_NaN();
        return sign ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
    }
    double val = (double)mantissa / (double)(1ull << 63);
    val = std::ldexp(val, exponent - 16383);
    return sign ? -val : val;
}
inline void X86_MEM_WRITE_F80(uint8_t* base, uint32_t addr, double v) {
    addr = x86_phys_translate(addr);
    if (addr + 10 > X86_RAM_SIZE) { x86_log_mmio(true, addr, 10, 0); return; }
    uint8_t* p = base + addr;
    uint16_t expsign = 0;
    uint64_t mantissa = 0;
    if (v == 0.0) {
        if (std::signbit(v)) expsign = 0x8000;
    } else if (std::isinf(v)) {
        expsign = std::signbit(v) ? 0xFFFF : 0x7FFF;
        mantissa = 0x8000000000000000ull;
    } else if (std::isnan(v)) {
        expsign = 0x7FFF;
        mantissa = 0xC000000000000000ull;
    } else {
        if (v < 0) { expsign = 0x8000; v = -v; }
        int exp;
        double frac = std::frexp(v, &exp);
        expsign |= (uint16_t)(exp + 16382);
        mantissa = (uint64_t)(frac * (double)(1ull << 63)) | 0x8000000000000000ull;
    }
    *(uint64_t*)p = mantissa;
    *(uint16_t*)(p + 8) = expsign;
}

// ---- MMX register type ----
struct X86MmReg {
    union {
        uint64_t u64;
        int64_t s64;
        uint32_t u32[2];
        int32_t s32[2];
        uint16_t u16[4];
        int16_t s16[4];
        uint8_t u8[8];
        int8_t s8[8];
    };
};

inline X86MmReg X86_MEM_READ_MMX(uint8_t* base, uint32_t addr) { addr = x86_phys_translate(addr); X86MmReg r; if (addr + 8 > X86_RAM_SIZE) { r.u64 = 0; return r; } r.u64 = *(uint64_t*)(base + addr); return r; }

// ---- MMX packed operations ----
inline void X86_MMX_PADDW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) d.u16[i] += s.u16[i]; }
inline void X86_MMX_PADDD(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<2;i++) d.u32[i] += s.u32[i]; }
inline void X86_MMX_PSUBW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) d.u16[i] -= s.u16[i]; }
inline void X86_MMX_PSUBD(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<2;i++) d.u32[i] -= s.u32[i]; }
inline void X86_MMX_PSUBSW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) { int32_t r = (int32_t)d.s16[i] - (int32_t)s.s16[i]; d.s16[i] = r < -32768 ? -32768 : (r > 32767 ? 32767 : (int16_t)r); } }
inline void X86_MMX_PMULLW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) d.s16[i] = (int16_t)((int32_t)d.s16[i] * (int32_t)s.s16[i]); }
inline void X86_MMX_PMADDWD(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<2;i++) d.s32[i] = (int32_t)d.s16[i*2] * (int32_t)s.s16[i*2] + (int32_t)d.s16[i*2+1] * (int32_t)s.s16[i*2+1]; }
inline void X86_MMX_PXOR(X86MmReg& d, const X86MmReg& s) { d.u64 ^= s.u64; }
inline void X86_MMX_PAND(X86MmReg& d, const X86MmReg& s) { d.u64 &= s.u64; }
inline void X86_MMX_POR(X86MmReg& d, const X86MmReg& s) { d.u64 |= s.u64; }
inline void X86_MMX_PSLLW(X86MmReg& d, int cnt) { if(cnt>=16) d.u64=0; else for(int i=0;i<4;i++) d.u16[i] <<= cnt; }
inline void X86_MMX_PSLLD(X86MmReg& d, int cnt) { if(cnt>=32) d.u64=0; else for(int i=0;i<2;i++) d.u32[i] <<= cnt; }
inline void X86_MMX_PSRLW(X86MmReg& d, int cnt) { if(cnt>=16) d.u64=0; else for(int i=0;i<4;i++) d.u16[i] >>= cnt; }
inline void X86_MMX_PSRLQ(X86MmReg& d, int cnt) { d.u64 = cnt >= 64 ? 0 : d.u64 >> cnt; }
inline void X86_MMX_PSRAD(X86MmReg& d, int cnt) { for(int i=0;i<2;i++) d.s32[i] = cnt >= 32 ? (d.s32[i] >> 31) : d.s32[i] >> cnt; }
inline void X86_MMX_PUNPCKLBW(X86MmReg& d, const X86MmReg& s) { X86MmReg t; for(int i=0;i<4;i++) { t.u8[i*2]=d.u8[i]; t.u8[i*2+1]=s.u8[i]; } d=t; }
inline void X86_MMX_PUNPCKHBW(X86MmReg& d, const X86MmReg& s) { X86MmReg t; for(int i=0;i<4;i++) { t.u8[i*2]=d.u8[i+4]; t.u8[i*2+1]=s.u8[i+4]; } d=t; }
inline void X86_MMX_PUNPCKLWD(X86MmReg& d, const X86MmReg& s) { X86MmReg t; for(int i=0;i<2;i++) { t.u16[i*2]=d.u16[i]; t.u16[i*2+1]=s.u16[i]; } d=t; }
inline void X86_MMX_PUNPCKHWD(X86MmReg& d, const X86MmReg& s) { X86MmReg t; for(int i=0;i<2;i++) { t.u16[i*2]=d.u16[i+2]; t.u16[i*2+1]=s.u16[i+2]; } d=t; }
inline void X86_MMX_PUNPCKLDQ(X86MmReg& d, const X86MmReg& s) { d.u32[1]=s.u32[0]; }
inline void X86_MMX_PUNPCKHDQ(X86MmReg& d, const X86MmReg& s) { X86MmReg t; t.u32[0]=d.u32[1]; t.u32[1]=s.u32[1]; d=t; }
inline void X86_MMX_PACKSSDW(X86MmReg& d, const X86MmReg& s) { X86MmReg t; t.s16[0]=d.s32[0]<-32768?-32768:(d.s32[0]>32767?32767:(int16_t)d.s32[0]); t.s16[1]=d.s32[1]<-32768?-32768:(d.s32[1]>32767?32767:(int16_t)d.s32[1]); t.s16[2]=s.s32[0]<-32768?-32768:(s.s32[0]>32767?32767:(int16_t)s.s32[0]); t.s16[3]=s.s32[1]<-32768?-32768:(s.s32[1]>32767?32767:(int16_t)s.s32[1]); d=t; }
inline void X86_MMX_PACKUSWB(X86MmReg& d, const X86MmReg& s) { X86MmReg t; for(int i=0;i<4;i++) t.u8[i]=(uint8_t)(d.s16[i]<0?0:(d.s16[i]>255?255:d.s16[i])); for(int i=0;i<4;i++) t.u8[i+4]=(uint8_t)(s.s16[i]<0?0:(s.s16[i]>255?255:s.s16[i])); d=t; }
inline void X86_MMX_PACKSSWB(X86MmReg& d, const X86MmReg& s) { X86MmReg t; for(int i=0;i<4;i++) t.s8[i]=(int8_t)(d.s16[i]<-128?-128:(d.s16[i]>127?127:d.s16[i])); for(int i=0;i<4;i++) t.s8[i+4]=(int8_t)(s.s16[i]<-128?-128:(s.s16[i]>127?127:s.s16[i])); d=t; }
inline void X86_MMX_PSHUFW(X86MmReg& d, const X86MmReg& s, uint8_t imm) { X86MmReg t; t.u16[0]=s.u16[imm&3]; t.u16[1]=s.u16[(imm>>2)&3]; t.u16[2]=s.u16[(imm>>4)&3]; t.u16[3]=s.u16[(imm>>6)&3]; d=t; }
inline void X86_MMX_PANDN(X86MmReg& d, const X86MmReg& s) { d.u64 = ~d.u64 & s.u64; }
inline void X86_MMX_PCMPEQB(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<8;i++) d.u8[i] = (d.u8[i]==s.u8[i]) ? 0xFF : 0; }
inline void X86_MMX_PCMPEQW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) d.u16[i] = (d.u16[i]==s.u16[i]) ? 0xFFFF : 0; }
inline void X86_MMX_PCMPEQD(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<2;i++) d.u32[i] = (d.u32[i]==s.u32[i]) ? 0xFFFFFFFFu : 0; }
inline void X86_MMX_PCMPGTB(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<8;i++) d.u8[i] = (d.s8[i]>s.s8[i]) ? 0xFF : 0; }
inline void X86_MMX_PCMPGTW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) d.u16[i] = (d.s16[i]>s.s16[i]) ? 0xFFFF : 0; }
inline void X86_MMX_PCMPGTD(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<2;i++) d.u32[i] = (d.s32[i]>s.s32[i]) ? 0xFFFFFFFFu : 0; }
inline void X86_MMX_PADDB(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<8;i++) d.u8[i] += s.u8[i]; }
inline void X86_MMX_PSUBB(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<8;i++) d.u8[i] -= s.u8[i]; }
inline void X86_MMX_PSRAW(X86MmReg& d, int cnt) { for(int i=0;i<4;i++) d.s16[i] = cnt >= 16 ? (d.s16[i] >> 15) : d.s16[i] >> cnt; }
inline void X86_MMX_PSRLD(X86MmReg& d, int cnt) { if(cnt>=32) d.u64=0; else for(int i=0;i<2;i++) d.u32[i] >>= cnt; }
inline void X86_MMX_PSLLQ(X86MmReg& d, int cnt) { d.u64 = cnt >= 64 ? 0 : d.u64 << cnt; }
inline void X86_MMX_PMAXSW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) if(s.s16[i]>d.s16[i]) d.s16[i]=s.s16[i]; }
inline void X86_MMX_PMINSW(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<4;i++) if(s.s16[i]<d.s16[i]) d.s16[i]=s.s16[i]; }
inline void X86_MMX_PAVGB(X86MmReg& d, const X86MmReg& s) { for(int i=0;i<8;i++) d.u8[i] = (uint8_t)(((uint16_t)d.u8[i] + (uint16_t)s.u8[i] + 1) >> 1); }
inline uint32_t X86_MMX_PMOVMSKB(const X86MmReg& s) { uint32_t r=0; for(int i=0;i<8;i++) r |= ((s.u8[i]>>7)<<i); return r; }

// ---- XMM memory access ----
struct X86XmmReg {
    union {
        float f32[4];
        double f64[2];
        uint32_t u32[4];
        int32_t s32[4];
        uint64_t u64[2];
        uint8_t u8[16];
    };
};

#define X86_MEM_READ_XMM(base, addr, dst) do { \
    uint32_t _ra = x86_phys_translate((uint32_t)(addr)); \
    if (_ra + 16 <= X86_RAM_SIZE) { \
        memcpy(&(dst), (base) + _ra, 16); \
    } else { \
        memset(&(dst), 0, 16); \
        x86_log_mmio(false, _ra, 16, 0); \
    } \
} while(0)
#define X86_MEM_WRITE_XMM(base, addr, src) do { \
    uint32_t _wa = x86_phys_translate((uint32_t)(addr)); \
    if (_wa + 16 <= X86_RAM_SIZE) { \
        memcpy((base) + _wa, &(src), 16); \
    } else { \
        x86_log_mmio(true, _wa, 16, 0); \
    } \
} while(0)
inline X86XmmReg X86_MEM_READ_XMM_VAL(uint8_t* base, uint32_t addr) {
    X86XmmReg r;
    uint32_t a = x86_phys_translate(addr);
    if (a + 16 <= X86_RAM_SIZE) { memcpy(&r, base + a, 16); }
    else { memset(&r, 0, 16); x86_log_mmio(false, a, 16, 0); }
    return r;
}

// ---- SSE packed operations ----
#define X86_SSE_ADDPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] += (s).f32[_i]; } while(0)
#define X86_SSE_SUBPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] -= (s).f32[_i]; } while(0)
#define X86_SSE_MULPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] *= (s).f32[_i]; } while(0)
#define X86_SSE_DIVPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] /= (s).f32[_i]; } while(0)
#define X86_SSE_XORPS(d, s) do { for (int _i=0;_i<4;_i++) (d).u32[_i] ^= (s).u32[_i]; } while(0)
#define X86_SSE_ANDPS(d, s) do { for (int _i=0;_i<4;_i++) (d).u32[_i] &= (s).u32[_i]; } while(0)
#define X86_SSE_ORPS(d, s)  do { for (int _i=0;_i<4;_i++) (d).u32[_i] |= (s).u32[_i]; } while(0)
#define X86_SSE_ANDNPS(d, s) do { for (int _i=0;_i<4;_i++) (d).u32[_i] = ~(d).u32[_i] & (s).u32[_i]; } while(0)
#define X86_SSE_MINPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] = fminf((d).f32[_i], (s).f32[_i]); } while(0)
#define X86_SSE_MAXPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] = fmaxf((d).f32[_i], (s).f32[_i]); } while(0)
#define X86_SSE_CMPPS(d, s, imm) do { for (int _i=0;_i<4;_i++) { \
    bool _r; float _a = (d).f32[_i], _b = (s).f32[_i]; \
    switch ((imm)&7) { case 0:_r=_a==_b;break; case 1:_r=_a<_b;break; case 2:_r=_a<=_b;break; case 3:_r=_a!=_b;break; \
    case 4:_r=_a!=_b;break; case 5:_r=_a>=_b;break; case 6:_r=_a>_b;break; default:_r=_a==_b;break; } \
    (d).u32[_i] = _r ? 0xFFFFFFFFu : 0u; } } while(0)

// ---- SSE scalar compare -> EFLAGS ----
inline void X86_SSE_COMPARE_EFLAGS(struct X86Context& ctx, float a, float b);

// ---- Flags ----
struct X86Flags {
    uint8_t cf; // carry
    uint8_t pf; // parity
    uint8_t af; // adjust
    uint8_t zf; // zero
    uint8_t sf; // sign
    uint8_t of; // overflow
    uint8_t df; // direction
};

// ---- FPU state ----
#define X86_FPU_STACK_SIZE 8

// ---- Context ----
struct X86Context {
    // General-purpose registers
    uint32_t eax, ecx, edx, ebx;
    uint32_t esp, ebp, esi, edi;
    // Flags
    X86Flags flags;
    // FPU
    double fp_stack[X86_FPU_STACK_SIZE];
    int fp_top;
    uint16_t fp_control;
    uint16_t fp_status;
    // SSE
    X86XmmReg xmm[8];
    // MMX
    X86MmReg mm[8];
};

// ---- Flags helpers ----
inline uint8_t x86_parity(uint8_t v) {
    v ^= v >> 4; v ^= v >> 2; v ^= v >> 1; return (~v) & 1;
}

#define X86_UPDATE_FLAGS_ARITH(ctx, result, bits) do { \
    (ctx).flags.zf = ((result) & ((1ull << (bits)) - 1)) == 0; \
    (ctx).flags.sf = ((result) >> ((bits) - 1)) & 1; \
    (ctx).flags.pf = x86_parity((uint8_t)(result)); \
} while(0)

#define X86_UPDATE_FLAGS_LOGIC(ctx, result, bits) do { \
    (ctx).flags.cf = 0; \
    (ctx).flags.of = 0; \
    (ctx).flags.zf = ((result) & ((1ull << (bits)) - 1)) == 0; \
    (ctx).flags.sf = ((result) >> ((bits) - 1)) & 1; \
    (ctx).flags.pf = x86_parity((uint8_t)(result)); \
} while(0)

#define X86_UPDATE_FLAGS_ADD(ctx, result64, sd, ss, bits) do { \
    auto _mask = (uint64_t)((1ull << (bits)) - 1); \
    (ctx).flags.cf = ((result64) >> (bits)) & 1; \
    (ctx).flags.zf = ((result64) & _mask) == 0; \
    (ctx).flags.sf = ((result64) >> ((bits) - 1)) & 1; \
    (ctx).flags.of = ((~((sd) ^ (ss))) & ((sd) ^ (result64))) >> ((bits) - 1) & 1; \
    (ctx).flags.pf = x86_parity((uint8_t)(result64)); \
} while(0)

#define X86_UPDATE_FLAGS_SUB(ctx, result64, sd, ss, bits) do { \
    auto _mask = (uint64_t)((1ull << (bits)) - 1); \
    (ctx).flags.cf = ((result64) >> (bits)) & 1; \
    (ctx).flags.zf = ((result64) & _mask) == 0; \
    (ctx).flags.sf = ((result64) >> ((bits) - 1)) & 1; \
    (ctx).flags.of = (((sd) ^ (ss)) & ((sd) ^ (result64))) >> ((bits) - 1) & 1; \
    (ctx).flags.pf = x86_parity((uint8_t)(result64)); \
} while(0)

#define X86_UPDATE_FLAGS_INC(ctx, result64, sd, bits) do { \
    (ctx).flags.zf = ((result64) & ((1ull << (bits)) - 1)) == 0; \
    (ctx).flags.sf = ((result64) >> ((bits) - 1)) & 1; \
    (ctx).flags.of = (((sd) ^ (result64)) & ~(sd)) >> ((bits) - 1) & 1; \
    (ctx).flags.pf = x86_parity((uint8_t)(result64)); \
} while(0)

#define X86_UPDATE_FLAGS_DEC(ctx, result64, sd, bits) do { \
    (ctx).flags.zf = ((result64) & ((1ull << (bits)) - 1)) == 0; \
    (ctx).flags.sf = ((result64) >> ((bits) - 1)) & 1; \
    (ctx).flags.of = ((sd) & ~(result64)) >> ((bits) - 1) & 1; \
    (ctx).flags.pf = x86_parity((uint8_t)(result64)); \
} while(0)

// ---- Bit operations ----
#ifdef _MSC_VER
#include <intrin.h>
inline uint32_t X86_BSF(int bits, uint32_t val) { unsigned long idx; _BitScanForward(&idx, val); return idx; }
inline uint32_t X86_BSR(int bits, uint32_t val) { unsigned long idx; _BitScanReverse(&idx, val); return idx; }
#else
inline uint32_t X86_BSF(int bits, uint32_t val) { return __builtin_ctz(val); }
inline uint32_t X86_BSR(int bits, uint32_t val) { return 31 - __builtin_clz(val); }
#endif

// ---- LAHF/SAHF ----
inline uint8_t X86_PACK_FLAGS_AH(X86Context& ctx) {
    return (ctx.flags.sf << 7) | (ctx.flags.zf << 6) | (ctx.flags.af << 4) | (ctx.flags.pf << 2) | (1 << 1) | ctx.flags.cf;
}
inline void X86_UNPACK_FLAGS_AH(X86Context& ctx, uint8_t ah) {
    ctx.flags.sf = (ah >> 7) & 1; ctx.flags.zf = (ah >> 6) & 1;
    ctx.flags.af = (ah >> 4) & 1; ctx.flags.pf = (ah >> 2) & 1; ctx.flags.cf = ah & 1;
}

// ---- FPU helpers ----
inline double X86_FPU_ROUND(const X86Context& ctx, double v) {
    switch ((ctx.fp_control >> 8) & 3) {
        case 0:  return (double)(float)v;  // PC=00, single
        case 2:  return v;                 // PC=10, double
        default: return v;                 // PC=11 / PC=01, extended or reserved
    }
}

// #define X86_FPU_PUSH(ctx, val) do { \
//     double _v = X86_FPU_ROUND((ctx), (val)); \
//     (ctx).fp_top = ((ctx).fp_top - 1) & 7; \
//     (ctx).fp_stack[(ctx).fp_top] = _v; \
// } while(0)
// #define X86_FPU_POP(ctx) do { (ctx).fp_top = ((ctx).fp_top + 1) & 7; } while(0)

// Shift-based model: fp_stack[0] is always ST(0), fp_stack[n] is ST(n).
// fp_top is kept at 0 so fp_stack[fp_top] == fp_stack[0] == ST(0).
#define X86_FPU_PUSH(ctx, val) do { \
    double _fpu_push_val = (val); \
    for (int _i = 7; _i > 0; _i--) (ctx).fp_stack[_i] = (ctx).fp_stack[_i-1]; \
    (ctx).fp_stack[0] = _fpu_push_val; (ctx).fp_top = 0; \
} while(0)
#define X86_FPU_POP(ctx) do { \
    for (int _i = 0; _i < 7; _i++) (ctx).fp_stack[_i] = (ctx).fp_stack[_i+1]; \
    (ctx).fp_top = 0; \
} while(0)

inline void X86_FPU_COMPARE(X86Context& ctx, double a, double b) {
    ctx.fp_status &= ~0x4500;
    if (a > b) { }
    else if (a < b) { ctx.fp_status |= 0x0100; }
    else if (a == b) { ctx.fp_status |= 0x4000; }
    else { ctx.fp_status |= 0x4500; }
}

inline void X86_FPU_COMPARE_EFLAGS(X86Context& ctx, double a, double b) {
    ctx.flags.cf = 0; ctx.flags.zf = 0; ctx.flags.pf = 0;
    if (a > b) { }
    else if (a < b) { ctx.flags.cf = 1; }
    else if (a == b) { ctx.flags.zf = 1; }
    else { ctx.flags.cf = 1; ctx.flags.zf = 1; ctx.flags.pf = 1; }
}

inline void X86_SSE_COMPARE_EFLAGS(X86Context& ctx, float a, float b) {
    ctx.flags.cf = 0; ctx.flags.zf = 0; ctx.flags.pf = 0;
    if (a > b) { }
    else if (a < b) { ctx.flags.cf = 1; }
    else if (a == b) { ctx.flags.zf = 1; }
    else { ctx.flags.cf = 1; ctx.flags.zf = 1; ctx.flags.pf = 1; }
}

inline uint16_t X86_FPU_STATUS(X86Context& ctx) { return ctx.fp_status; }

// ---- EFLAGS pack/unpack for PUSHFD/POPFD ----
inline uint32_t X86_PACK_EFLAGS(X86Context& ctx) {
    return (uint32_t)ctx.flags.cf | (1u << 1) | ((uint32_t)ctx.flags.pf << 2) | ((uint32_t)ctx.flags.af << 4) |
           ((uint32_t)ctx.flags.zf << 6) | ((uint32_t)ctx.flags.sf << 7) | ((uint32_t)ctx.flags.df << 10) | ((uint32_t)ctx.flags.of << 11);
}
inline void X86_UNPACK_EFLAGS(X86Context& ctx, uint32_t fl) {
    ctx.flags.cf = fl & 1; ctx.flags.pf = (fl >> 2) & 1; ctx.flags.af = (fl >> 4) & 1;
    ctx.flags.zf = (fl >> 6) & 1; ctx.flags.sf = (fl >> 7) & 1; ctx.flags.df = (fl >> 10) & 1; ctx.flags.of = (fl >> 11) & 1;
}

// ---- CPUID stub ----
inline void X86_CPUID(X86Context& ctx) {
    switch (ctx.eax) {
    case 0: ctx.eax = 1; ctx.ebx = 0x756E6547; ctx.edx = 0x49656E69; ctx.ecx = 0x6C65746E; break;
    case 1: ctx.eax = 0x00000686; ctx.ebx = 0; ctx.ecx = 0; ctx.edx = 0x0383FBFF; break;
    default: ctx.eax = 0; ctx.ebx = 0; ctx.ecx = 0; ctx.edx = 0; break;
    }
}

// ---- RDTSC ----
// The Xbox CPU (733 MHz Pentium III) had TSC running at 733,333,333 Hz.
// The game's QueryPerformanceFrequency stub hardcodes this value, so rdtsc
// must return ticks at the same rate.  Map host wall-clock time to Xbox TSC.
inline uint64_t X86_RDTSC() {
    static const auto s_epoch = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - s_epoch).count();
    // 733,333,333 ticks/sec  =  733 + 1/3 ticks/us
    return static_cast<uint64_t>(us) * 733ULL
         + static_cast<uint64_t>(us) / 3ULL;
}

// ---- Recompiled function signature ----
typedef void (*X86RecompFunc)(X86Context& ctx, uint8_t* base);

struct X86FuncMapping {
    uint32_t guestAddr;
    X86RecompFunc hostFunc;
};

// ---- Indirect call (dispatch through function table) ----
extern X86FuncMapping X86FuncMappings[];

// ---- Unified function dispatch map (recompiled funcs + kernel stubs) ----
#include <unordered_map>
inline std::unordered_map<uint32_t, X86RecompFunc> g_funcMap;

// ---- HLE last-error storage (replaces fs:-based TLS in SetLastError/GetLastError) ----
inline uint32_t g_lastError = 0;

// ---- Kernel thunk name lookup (populated by KernelDispatch::Init) ----
extern std::unordered_map<uint32_t, const char*> g_thunkNames;

// ---- Guest CRT heap replacement (implemented in imports.cpp) ----
// Allocates zeroed memory from the GuestVM bump pool.
// Used by the HLE override of the Xbox debug CRT malloc (sub_8A92E).
uint32_t GuestMalloc(uint32_t size, uint8_t* base);

void X86_INIT_FUNC_MAP() {
    for (int i = 0; X86FuncMappings[i].hostFunc; i++) {
        g_funcMap[X86FuncMappings[i].guestAddr] = X86FuncMappings[i].hostFunc;
    }
}

void X86_CALL_INDIRECT(X86Context& ctx, uint8_t* base, uint32_t addr) {
    if (addr == 0) {
        // Null function pointer — no callback installed, treat as no-op.
        return;
    }
    auto it = g_funcMap.find(addr);
    if (it != g_funcMap.end()) {
        // DEBUG: check callee-saved register preservation
        uint32_t _saved_ebp = ctx.ebp;
        uint32_t _saved_ebx = ctx.ebx;
        uint32_t _saved_esi = ctx.esi;
        uint32_t _saved_edi = ctx.edi;
        it->second(ctx, base);
        if (ctx.ebp != _saved_ebp)
            fprintf(stderr, "[CALLEE-SAVE] ebp changed 0x%08X -> 0x%08X after call to 0x%08X\n", _saved_ebp, ctx.ebp, addr);
        if (ctx.ebx != _saved_ebx)
            fprintf(stderr, "[CALLEE-SAVE] ebx changed 0x%08X -> 0x%08X after call to 0x%08X\n", _saved_ebx, ctx.ebx, addr);
        if (ctx.esi != _saved_esi)
            fprintf(stderr, "[CALLEE-SAVE] esi changed 0x%08X -> 0x%08X after call to 0x%08X\n", _saved_esi, ctx.esi, addr);
        if (ctx.edi != _saved_edi)
            fprintf(stderr, "[CALLEE-SAVE] edi changed 0x%08X -> 0x%08X after call to 0x%08X\n", _saved_edi, ctx.edi, addr);
    } else if (addr >= X86_RAM_SIZE) {
        static int s_oobLog = 0;
        if (s_oobLog < 20) {
            fprintf(stderr, "[X86_CALL_INDIRECT] SKIP out-of-range: 0x%08X (debug-fill or hw addr)\n", addr);
            s_oobLog++;
        }
        ctx.eax = 0;
    } else {
        static int s_missLog = 0;
        if (s_missLog < 50) {
            fprintf(stderr, "[X86_CALL_INDIRECT] MISS: target 0x%08X not in g_funcMap!\n", addr);
            fprintf(stderr, "  regs: eax=0x%08X ecx=0x%08X edx=0x%08X ebx=0x%08X\n",
                    ctx.eax, ctx.ecx, ctx.edx, ctx.ebx);
            fprintf(stderr, "  regs: esp=0x%08X ebp=0x%08X esi=0x%08X edi=0x%08X\n",
                    ctx.esp, ctx.ebp, ctx.esi, ctx.edi);
            fprintf(stderr, "  stack dump:");
            for (int i = 0; i < 24; i++)
                fprintf(stderr, " [+%02X]=0x%08X", i*4,
                        X86_MEM_READ_u32(base, ctx.esp + i*4));
            fprintf(stderr, "\n");
            x86_print_host_stack("X86_CALL_INDIRECT-MISS", 1, 24);
            s_missLog++;
        }
    }
}

void X86_JMP_INDIRECT(X86Context& ctx, uint8_t* base, uint32_t addr) {
    if (addr == 0) {
        return;
    }
    auto it = g_funcMap.find(addr);
    if (it != g_funcMap.end()) {
        it->second(ctx, base);
    } else if (addr >= X86_RAM_SIZE) {
        static int s_oobLog = 0;
        if (s_oobLog < 20) {
            fprintf(stderr, "[X86_JMP_INDIRECT] SKIP out-of-range: 0x%08X\n", addr);
            s_oobLog++;
        }
        ctx.eax = 0;
    } else {
        fprintf(stderr, "[X86_JMP_INDIRECT] target 0x%08X not found in g_funcMap!\n", addr);
    }
}
