#include "x86_recomp_shared.h"
#include "kernel/function.h"
#include "kernel/xdm.h"
#include "kernel/guest_thread.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>


// ---------------------------------------------------------------------------
// HLE: XapiBootToDash — on real Xbox this reboots to dashboard.
// In emulation, just log and return so XapiInitProcess falls through
// and execution continues to _cinit / main game code.
// Args: (DWORD reason, DWORD type, DWORD errorCode)  — 12 bytes, ret 0x0C
// ---------------------------------------------------------------------------
void XapiBootToDash(X86Context& ctx, uint8_t* base)
{
    uint32_t reason    = GuestArg32(ctx, base, 0);
    uint32_t type      = GuestArg32(ctx, base, 1);
    uint32_t errorCode = GuestArg32(ctx, base, 2);
    fprintf(stderr, "[HLE] XapiBootToDash(reason=%u, type=%u, error=0x%08X) — "
                    "suppressed, continuing execution\n",
            reason, type, errorCode);
    GuestStackCleanup(ctx, 12);
}

extern void Kern_NtWaitForSingleObject(X86Context& ctx, uint8_t* base);

void _xstart(X86Context& ctx, uint8_t* base) {
	// 0x94060: mov ecx, [0x00010118]
	ctx.ecx = X86_MEM_READ_u32(base, 0x10118u);
	// 0x94066: mov eax, [0x00010108]
	ctx.eax = X86_MEM_READ_u32(base, 0x10108u);
	// 0x9406B: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x9406D: add eax, 0x10000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(65536);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)65536, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x94072: cmp eax, [ecx]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x94074: jnb 0x00094078
	if (!ctx.flags.cf) goto loc_94078;
	// 0x94076: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
loc_94078:
	// 0x94078: mov eax, [0x000EDCA0]
	ctx.eax = X86_MEM_READ_u32(base, 0xEDCA0u);
	// 0x9407D: sub eax, [0x000EDC90]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0xEDC90u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x94083: mov ecx, [0x000EDC94]
	ctx.ecx = X86_MEM_READ_u32(base, 0xEDC94u);
	// 0x94089: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x9408A: lea eax, [eax+ecx*1+0x0F]
	ctx.eax = ctx.eax + ctx.ecx + 0xFu;
	// 0x9408E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x9408F: and eax, 0xFFFFFFF0
	ctx.eax = ctx.eax & -16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x94092: push 0xFFFFFFFC
	{ auto _pv = (uint32_t)(-4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x94094: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x94095: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x94098: mov [0x00152DBC], eax
	X86_MEM_WRITE_u32(base, 0x152DBCu, ctx.eax);
	// 0x9409D: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x9409E: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x940A0: mov ecx, [0x000EDC98]
	ctx.ecx = X86_MEM_READ_u32(base, 0xEDC98u);
	// 0x940A6: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x940A8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940A9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940AA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940AB: push 0x93FEC
	{ auto _pv = (uint32_t)(606188); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940B0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940B1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940B2: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x940B4: call 0x00095767
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CreateThread(ctx, base);
	ctx.esp += 4;

	// The original Xbox CRT _xstart creates the game thread, closes the
	// handle, and returns.  The process stays alive as long as any thread
	// exists.  In our recompiled environment, returning from _xstart means
	// main() returns and the process exits.  Wait for the game thread to
	// finish before falling through to CloseHandle / ret.
	{
		uint32_t threadHandle = ctx.eax;   // CreateThread returns handle in eax
		auto* obj = GetKernelObjectByHandle(threadHandle);
		if (obj) {
			fprintf(stderr, "[HLE] _xstart: waiting for game thread (handle %u) to finish...\n", threadHandle);
			obj->Wait(UINT32_MAX);
			fprintf(stderr, "[HLE] _xstart: game thread finished.\n");
		} else {
			fprintf(stderr, "[HLE] _xstart: WARNING — could not find game thread by handle %u\n", threadHandle);
		}
	}

	// 0x940B9: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x940BB: cmp edi, esi
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x940BD: jnz 0x000940C9
	if (!ctx.flags.zf) goto loc_940C9;
	// 0x940BF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940C0: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940C2: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940C4: call 0x00094F2E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XapiBootToDash(ctx, base);
	ctx.esp += 4;
loc_940C9:
	// 0x940C9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x940CA: call 0x0009554C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x940CF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x940D0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x940D1: ret
	return;
}

void XnInit(X86Context& ctx, uint8_t* base) {
	// HLE stub: Xbox network stack init not needed in recompiled environment.
	// Original code allocates network pools, reads EEPROM config, and initialises
	// the Xbox NIC driver — all of which fail without real hardware.
	// Return 0 (success) so WSAStartup/XNetStartup callers continue normally.
	fprintf(stderr, "[HLE] XnInit: stubbed — returning success\n");
	ctx.eax = 0;   // success
	ctx.esp += 24;  // ret 0x18 (6 args × 4 bytes)
	return;
}

// ---------------------------------------------------------------------------
// HLE: CRT malloc / free / LocalAlloc / LocalFree
// ---------------------------------------------------------------------------
// The Xbox CRT's NT heap (RtlCreateHeap / RtlAllocateHeap) has an
// uninitialized free-list bug in the recompiled environment — the circular
// doubly-linked list heads at heap+0x180 are left null instead of
// self-pointing, causing an infinite loop in the large-block allocator
// (sub_96C6F).
//
// Fix: bypass the NT heap entirely by routing CRT malloc/free and
// LocalAlloc/LocalFree through GuestMalloc (the GuestVM bump allocator
// backed by NtAllocateVirtualMemory's page pool).
// ---------------------------------------------------------------------------
extern uint32_t GuestMalloc(uint32_t size, uint8_t* base);

// CRT malloc  (cdecl, 1 arg: size at [esp+4])
void sub_B3CE3(X86Context& ctx, uint8_t* base) {
    uint32_t size = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
    ctx.eax = GuestMalloc(size, base);
}

// CRT free  (cdecl, 1 arg: ptr at [esp+4])
void sub_B3C38(X86Context& ctx, uint8_t* base) {
    // No-op: GuestMalloc uses a bump allocator that doesn't recycle.
    (void)ctx; (void)base;
}

// CRT calloc  (cdecl, 2 args: count at [esp+4], size at [esp+8])
void sub_B9A71(X86Context& ctx, uint8_t* base) {
    uint32_t count = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
    uint32_t size  = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
    uint64_t total = (uint64_t)count * size;
    if (total == 0) total = 1;
    if (total > 0xFFFFFFE0u) { ctx.eax = 0; return; }
    ctx.eax = GuestMalloc((uint32_t)total, base); // returns zeroed memory
}

// CRT realloc  (cdecl, 2 args: old_ptr at [esp+4], new_size at [esp+8])
void sub_B6415(X86Context& ctx, uint8_t* base) {
    uint32_t old_ptr  = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
    uint32_t new_size = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
    if (old_ptr == 0) {
        ctx.eax = GuestMalloc(new_size, base);
        return;
    }
    if (new_size == 0) {
        ctx.eax = 0;
        return;
    }
    uint32_t new_ptr = GuestMalloc(new_size, base);
    if (new_ptr) {
        // Safe: all guest memory is accessible; GuestMalloc returns zeroed
        // pages so bytes beyond old allocation's actual size are just zeros.
        memcpy(base + new_ptr, base + old_ptr, new_size);
    }
    ctx.eax = new_ptr;
}

// LocalAlloc  (stdcall, 2 args: uFlags at [esp+4], uBytes at [esp+8])
void LocalAlloc(X86Context& ctx, uint8_t* base) {
    uint32_t uBytes = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
    ctx.eax = GuestMalloc(uBytes, base);
    ctx.esp += 8; // stdcall cleanup
}

// LocalFree  (stdcall, 1 arg: hMem at [esp+4])
void LocalFree(X86Context& ctx, uint8_t* base) {
    ctx.eax = 0; // NULL = success
    ctx.esp += 4; // stdcall cleanup
}
