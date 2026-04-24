#pragma once

#include "x86_config.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <limits>

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
inline bool x86_mem_ok(uint32_t a, uint32_t sz) { return a <= X86_RAM_SIZE - sz; }

inline uint8_t  x86_rd_u8 (uint8_t* b, uint32_t a) { if (!x86_mem_ok(a,1)) { x86_log_mmio(false,a,1,0); return 0; } return *(uint8_t*) (b+a); }
inline uint16_t x86_rd_u16(uint8_t* b, uint32_t a) { if (!x86_mem_ok(a,2)) { x86_log_mmio(false,a,2,0); return 0; } return *(uint16_t*)(b+a); }
inline uint32_t x86_rd_u32(uint8_t* b, uint32_t a) { if (!x86_mem_ok(a,4)) { x86_log_mmio(false,a,4,0); return 0; } return *(uint32_t*)(b+a); }
inline uint64_t x86_rd_u64(uint8_t* b, uint32_t a) { if (!x86_mem_ok(a,8)) { x86_log_mmio(false,a,8,0); return 0; } return *(uint64_t*)(b+a); }

inline void x86_wr_u8 (uint8_t* b, uint32_t a, uint8_t  v) { if (!x86_mem_ok(a,1)) { x86_log_mmio(true,a,1,v); return; } *(uint8_t*) (b+a)=v; }
inline void x86_wr_u16(uint8_t* b, uint32_t a, uint16_t v) { if (!x86_mem_ok(a,2)) { x86_log_mmio(true,a,2,v); return; } *(uint16_t*)(b+a)=v; }
inline void x86_wr_u32(uint8_t* b, uint32_t a, uint32_t v) { if (!x86_mem_ok(a,4)) { x86_log_mmio(true,a,4,v); return; } *(uint32_t*)(b+a)=v; }
inline void x86_wr_u64(uint8_t* b, uint32_t a, uint64_t v) { if (!x86_mem_ok(a,8)) { x86_log_mmio(true,a,8,v); return; } *(uint64_t*)(b+a)=v; }

#define X86_MEM_READ_u8(base, addr)   x86_rd_u8 ((base), (uint32_t)(addr))
#define X86_MEM_READ_u16(base, addr)  x86_rd_u16((base), (uint32_t)(addr))
#define X86_MEM_READ_u32(base, addr)  x86_rd_u32((base), (uint32_t)(addr))
#define X86_MEM_READ_u64(base, addr)  x86_rd_u64((base), (uint32_t)(addr))
#define X86_MEM_WRITE_u8(base, addr, v)  x86_wr_u8 ((base), (uint32_t)(addr), (uint8_t)(v))
#define X86_MEM_WRITE_u16(base, addr, v) x86_wr_u16((base), (uint32_t)(addr), (uint16_t)(v))
#define X86_MEM_WRITE_u32(base, addr, v) x86_wr_u32((base), (uint32_t)(addr), (uint32_t)(v))
#define X86_MEM_WRITE_u64(base, addr, v) x86_wr_u64((base), (uint32_t)(addr), (uint64_t)(v))

// ---- Floating-point memory access ----
inline float  x86_rd_f32(uint8_t* b, uint32_t a) { if (!x86_mem_ok(a,4)) { x86_log_mmio(false,a,4,0); return 0.0f; } return *(float*) (b+a); }
inline double x86_rd_f64(uint8_t* b, uint32_t a) { if (!x86_mem_ok(a,8)) { x86_log_mmio(false,a,8,0); return 0.0;  } return *(double*)(b+a); }
inline void x86_wr_f32(uint8_t* b, uint32_t a, float  v) { if (!x86_mem_ok(a,4)) { x86_log_mmio(true,a,4,(uint32_t&)v); return; } *(float*) (b+a)=v; }
inline void x86_wr_f64(uint8_t* b, uint32_t a, double v) { if (!x86_mem_ok(a,8)) { x86_log_mmio(true,a,8,(uint64_t&)v); return; } *(double*)(b+a)=v; }

#define X86_MEM_READ_F32(base, addr)  x86_rd_f32((base), (uint32_t)(addr))
#define X86_MEM_READ_F64(base, addr)  x86_rd_f64((base), (uint32_t)(addr))
#define X86_MEM_WRITE_F32(base, addr, v) x86_wr_f32((base), (uint32_t)(addr), (float)(v))
#define X86_MEM_WRITE_F64(base, addr, v) x86_wr_f64((base), (uint32_t)(addr), (double)(v))

// ---- 80-bit extended precision FPU memory access ----
inline double X86_MEM_READ_F80(uint8_t* base, uint32_t addr) {
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

inline X86MmReg X86_MEM_READ_MMX(uint8_t* base, uint32_t addr) { X86MmReg r; r.u64 = *(uint64_t*)(base + addr); return r; }

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

#define X86_MEM_READ_XMM(base, addr, dst)  memcpy(&(dst), (base) + (uint32_t)(addr), 16)
#define X86_MEM_WRITE_XMM(base, addr, src) memcpy((base) + (uint32_t)(addr), &(src), 16)
inline X86XmmReg X86_MEM_READ_XMM_VAL(uint8_t* base, uint32_t addr) { X86XmmReg r; memcpy(&r, base + addr, 16); return r; }

// ---- SSE packed operations ----
#define X86_SSE_ADDPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] += (s).f32[_i]; } while(0)
#define X86_SSE_SUBPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] -= (s).f32[_i]; } while(0)
#define X86_SSE_MULPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] *= (s).f32[_i]; } while(0)
#define X86_SSE_DIVPS(d, s) do { for (int _i=0;_i<4;_i++) (d).f32[_i] /= (s).f32[_i]; } while(0)
#define X86_SSE_XORPS(d, s) do { for (int _i=0;_i<4;_i++) (d).u32[_i] ^= (s).u32[_i]; } while(0)
#define X86_SSE_ANDPS(d, s) do { for (int _i=0;_i<4;_i++) (d).u32[_i] &= (s).u32[_i]; } while(0)
#define X86_SSE_ORPS(d, s)  do { for (int _i=0;_i<4;_i++) (d).u32[_i] |= (s).u32[_i]; } while(0)

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
#ifdef _MSC_VER
#include <intrin.h>
inline uint64_t X86_RDTSC() { return __rdtsc(); }
#else
inline uint64_t X86_RDTSC() { uint32_t lo, hi; __asm__ volatile("rdtsc" : "=a"(lo), "=d"(hi)); return ((uint64_t)hi << 32) | lo; }
#endif

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
#include <vector>
#include <algorithm>
inline std::unordered_map<uint32_t, X86RecompFunc> g_funcMap;

// ---- Dispatch call counting (profiling) ----
inline std::unordered_map<uint32_t, uint64_t> g_callCounts;

inline void DumpHotFunctions(int topN = 30) {
    std::vector<std::pair<uint32_t, uint64_t>> sorted(g_callCounts.begin(), g_callCounts.end());
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b){ return a.second > b.second; });
    fprintf(stderr, "\n=== Top %d hottest dispatched functions ===\n", topN);
    for (int i = 0; i < topN && i < (int)sorted.size(); i++)
        fprintf(stderr, "  sub_%X : %llu calls\n", sorted[i].first, (unsigned long long)sorted[i].second);
    fprintf(stderr, "==========================================\n\n");
}

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
        g_callCounts[addr]++;
        it->second(ctx, base);
    } else if (addr >= X86_RAM_SIZE) {
        // Address is outside guest RAM — this is an uninitialized/debug-fill
        // pointer (e.g. 0xB7B7B7B7 from the Xbox debug CRT heap, or a
        // hardware I/O address).  On a real Xbox with a release CRT the
        // caller's field would have been zero (= "no callback").  Treat as
        // a no-op returning 0 so the check-and-call pattern in guest code
        // (test eax, eax; jz skip; call eax) behaves correctly.
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
        g_callCounts[addr]++;
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
