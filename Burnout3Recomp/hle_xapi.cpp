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
void _malloc(X86Context& ctx, uint8_t* base) {
    uint32_t size = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
    ctx.eax = GuestMalloc(size, base);
}

// CRT free  (cdecl, 1 arg: ptr at [esp+4])
void _free(X86Context& ctx, uint8_t* base) {
    // No-op: GuestMalloc uses a bump allocator that doesn't recycle.
    (void)ctx; (void)base;
}

// CRT calloc  (cdecl, 2 args: count at [esp+4], size at [esp+8])
void _calloc(X86Context& ctx, uint8_t* base) {
    uint32_t count = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
    uint32_t size  = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
    uint64_t total = (uint64_t)count * size;
    if (total == 0) total = 1;
    if (total > 0xFFFFFFE0u) { ctx.eax = 0; return; }
    ctx.eax = GuestMalloc((uint32_t)total, base); // returns zeroed memory
}

// CRT realloc  (cdecl, 2 args: old_ptr at [esp+4], new_size at [esp+8])
void _realloc(X86Context& ctx, uint8_t* base) {
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
void _LocalAlloc(X86Context& ctx, uint8_t* base) {
    uint32_t uBytes = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
    ctx.eax = GuestMalloc(uBytes, base);
    ctx.esp += 8; // stdcall cleanup
}

// LocalFree  (stdcall, 1 arg: hMem at [esp+4])
void _LocalFree(X86Context& ctx, uint8_t* base) {
    ctx.eax = 0; // NULL = success
    ctx.esp += 4; // stdcall cleanup
}


void sub_40860(X86Context& ctx, uint8_t* base) {
	// 0x40860: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x40864: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40865: push 0x3AAFC8
	{ auto _pv = (uint32_t)(3846088); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4086A: lea ecx, [esp+0x68]
	ctx.ecx = ctx.esp + 0x68u;
	// 0x4086E: mov edi, 0x80
	ctx.edi = 128;
	// 0x40873: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40875: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40876: mov [esp+0x30], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.edi);
	// 0x4087A: mov [esp+0x34], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x34u, ctx.edi);
	// 0x4087E: call 0x00243816
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243816(ctx, base);
	ctx.esp += 4;
	// 0x40883: mov esi, [0x004AED9C]
	ctx.esi = X86_MEM_READ_u32(base, 0x4AED9Cu);
	// 0x40889: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	uint32_t _diag_esp_after_open; // DIAG
	// 0x4088C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4088E: lea edx, [esp+0x64]
	ctx.edx = ctx.esp + 0x64u;
	// 0x40892: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40893: call 0x001B33A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CGTFileSystem__Open(ctx, base);
	ctx.esp += 4;
	// 0x40898: mov [esp+0x18], eax
	_diag_esp_after_open = ctx.esp; // DIAG
	fprintf(stderr, "[DIAG-40860] CGTFileSystem__Open ret=0x%08X esp=0x%08X store_addr=0x%08X\n",
	        ctx.eax, ctx.esp, ctx.esp + 0x18u);
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.eax);
	// 0x4089C: lea eax, [esp+0x40]
	ctx.eax = ctx.esp + 0x40u;
	// 0x408A0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408A1: lea ecx, [esp+0x34]
	ctx.ecx = ctx.esp + 0x34u;
	// 0x408A5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408A6: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408A8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408AA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408AC: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408AE: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408B0: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408B2: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x408B4: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x408B6: call 0x00352560
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_EncodeFormat(ctx, base);
	ctx.esp += 4;
	// 0x408BB: push 0x64800000
	{ auto _pv = (uint32_t)(1686110208); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408C0: push 0x14
	{ auto _pv = (uint32_t)(20); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408C2: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x408C4: call 0x001D2879
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemAlloc(ctx, base);
	ctx.esp += 4;
	// 0x408C9: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x408CB: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x408CD: jz 0x00040910
	if (ctx.flags.zf) goto loc_40910;
	// 0x408CF: push 0xB7800000
	{ auto _pv = (uint32_t)(-1216348160); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408D4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408D5: call 0x001D2879
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemAlloc(ctx, base);
	ctx.esp += 4;
	// 0x408DA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x408DC: jnz 0x000408ED
	if (!ctx.flags.zf) goto loc_408ED;
	// 0x408DE: push 0x24800000
	{ auto _pv = (uint32_t)(612368384); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408E3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408E4: call 0x001D2919
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemFree(ctx, base);
	ctx.esp += 4;
	// 0x408E9: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x408EB: jmp 0x00040910
	goto loc_40910;
loc_408ED:
	// 0x408ED: mov edx, [esp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x408F1: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x408F6: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x408F9: mov eax, [esp+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	// 0x408FD: mov dword ptr [esi], 0x1040001
	X86_MEM_WRITE_u32(base, ctx.esi, 17039361);
	// 0x40903: mov [esi+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.edx);
	// 0x40906: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x40909: mov dword ptr [esi+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 0);
loc_40910:
	// 0x40910: mov [ebp], esi
	X86_MEM_WRITE_u32(base, ctx.ebp, ctx.esi);
	// 0x40913: mov edi, [ebp]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x40916: lea esi, [esp+0x44]
	ctx.esi = ctx.esp + 0x44u;
	// 0x4091A: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x4091C: call 0x003521F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_Get2DSurfaceDesc(ctx, base);
	ctx.esp += 4;
	// 0x40921: mov esi, [ebp]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x40924: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x40926: call 0x00351B50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_BlockOnResource(ctx, base);
	ctx.esp += 4;
	// 0x4092B: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x4092F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40930: lea edx, [esp+0x40]
	ctx.edx = ctx.esp + 0x40u;
	// 0x40934: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40935: lea eax, [esp+0x3C]
	ctx.eax = ctx.esp + 0x3Cu;
	// 0x40939: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4093A: lea ecx, [esp+0x44]
	ctx.ecx = ctx.esp + 0x44u;
	// 0x4093E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4093F: lea edx, [esp+0x38]
	ctx.edx = ctx.esp + 0x38u;
	// 0x40943: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40944: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40945: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40946: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40947: call 0x00352290
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_FindSurfaceWithinTexture(ctx, base);
	ctx.esp += 4;
	// 0x4094C: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x40950: mov edi, [esp+0x28]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// RECOMP FIX: skip vtable Read call when file handle (ecx) is NULL
	if (ctx.ecx != 0) {
	// 0x40954: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x40956: push 0x8000
	{ auto _pv = (uint32_t)(32768); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4095B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4095C: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	} // end null-guard for file handle vtable call
	// 0x4095F: mov eax, [esp+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x40963: call 0x003613E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGBytesPerPixelFromFormat(ctx, base);
	ctx.esp += 4;
	// 0x40968: mov esi, [esp+0x58]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x4096C: imul esi, [esp+0x5C]
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40971: imul esi, eax
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)ctx.eax;
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40974: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40975: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x40979: call 0x00243872
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243872(ctx, base);
	ctx.esp += 4;
	// 0x4097E: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x40980: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x40982: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x40984: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x40988: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x4098B: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x4098D: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x4098F: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x40991: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40994: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40995: mov eax, [esp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x40999: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x4099B: mov edx, [esp+0x5C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	// 0x4099F: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409A1: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x409A4: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x409A6: mov ecx, [esp+0x64]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x64u);
	// 0x409AA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AB: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AD: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AF: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409B1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409B2: call 0x00361454
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGSwizzleRect(ctx, base);
	ctx.esp += 4;
	// 0x409B7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409B8: call 0x0024386D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	j_free(ctx, base);
	ctx.esp += 4;
	// 0x409BD: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x409C0: mov ebx, 0x01
	ctx.ebx = 1;
	// 0x409C5: jmp 0x000409D0
	sub_409D0(ctx, base);
	return;
	// 0x409C7: mov ebp, [esp+0x14]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x409CB: jmp 0x000409D0
	sub_409D0(ctx, base);
	return;
}

void sub_409D0(X86Context& ctx, uint8_t* base) {
	// 0x409D0: mov ecx, [esp+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x409D4: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x409D8: mov edi, [ebp]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x409DB: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x409DD: sar eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x409DF: lea esi, [esp+0x44]
	ctx.esi = ctx.esp + 0x44u;
	// 0x409E3: mov [esp+0x24], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.ecx);
	// 0x409E7: mov [esp+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.eax);
	// 0x409EB: call 0x003521F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_Get2DSurfaceDesc(ctx, base);
	ctx.esp += 4;
	// 0x409F0: mov esi, [ebp]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x409F3: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x409F5: call 0x00351B50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_BlockOnResource(ctx, base);
	ctx.esp += 4;
	// 0x409FA: lea ecx, [esp+0x38]
	ctx.ecx = ctx.esp + 0x38u;
	// 0x409FE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409FF: lea edx, [esp+0x38]
	ctx.edx = ctx.esp + 0x38u;
	// 0x40A03: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A04: lea eax, [esp+0x44]
	ctx.eax = ctx.esp + 0x44u;
	// 0x40A08: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A09: lea ecx, [esp+0x1C]
	ctx.ecx = ctx.esp + 0x1Cu;
	// 0x40A0D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A0E: lea edx, [esp+0x3C]
	ctx.edx = ctx.esp + 0x3Cu;
	// 0x40A12: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A13: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A14: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A16: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A17: call 0x00352290
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_FindSurfaceWithinTexture(ctx, base);
	ctx.esp += 4;
	// 0x40A1C: mov edx, [esp+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x40A20: imul edx, [esp+0x20]
	{ int64_t _res = (int64_t)(int32_t)ctx.edx * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	  ctx.edx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40A25: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x40A29: mov edi, [esp+0x2C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// RECOMP FIX: skip vtable Read call when file handle (ecx) is NULL
	if (ctx.ecx != 0) {
	// 0x40A2D: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x40A2F: shl edx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x40A31: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A32: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A33: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	} // end null-guard for file handle vtable call
	// 0x40A36: mov eax, [esp+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x40A3A: call 0x003613E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGBytesPerPixelFromFormat(ctx, base);
	ctx.esp += 4;
	// 0x40A3F: mov esi, [esp+0x58]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x40A43: imul esi, eax
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)ctx.eax;
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40A46: imul esi, [esp+0x5C]
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40A4B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A4C: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x40A50: call 0x00243872
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243872(ctx, base);
	ctx.esp += 4;
	// 0x40A55: mov edx, [esp+0x60]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x60u);
	// 0x40A59: mov ebp, eax
	ctx.ebp = ctx.eax;
	// 0x40A5B: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x40A5D: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x40A5F: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x40A62: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x40A64: mov edi, ebp
	ctx.edi = ctx.ebp;
	// 0x40A66: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x40A68: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40A6B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x40A6D: mov eax, [esp+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x40A71: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x40A74: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x40A76: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x40A7A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A7B: mov ecx, [esp+0x30]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x40A7F: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A81: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A82: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A83: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A84: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A86: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A88: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A89: call 0x00361454
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGSwizzleRect(ctx, base);
	ctx.esp += 4;
	// 0x40A8E: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A8F: call 0x0024386D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	j_free(ctx, base);
	ctx.esp += 4;
	// FIX: chain to sub_40A94 to implement the x86 fall-through.
	// Without this, the loop control + epilogue at 0x40A94 is never reached,
	// leaking 0xA8 bytes of guest stack per call and exhausting the VM pool.
	sub_40A94(ctx, base);
}

void sub_40A94(X86Context& ctx, uint8_t* base) {
	// 0x40A94: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40A97: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x40A98: cmp ebx, 0x03
	{ uint32_t _d = ctx.ebx; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x40A9B: jl 0x000409C7
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_409C7;
	// 0x40AA1: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x40AA5: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x40AA7: call [edx+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x40AAA: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x40AAE: mov edx, [esp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x40AB2: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x40AB3: add edx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)4, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x40AB6: cmp eax, 0x11
	{ uint32_t _d = ctx.eax; uint32_t _s = 17;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x40AB9: mov [esp+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.eax);
	// 0x40ABD: mov [esp+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edx);
	// 0x40AC1: jl 0x00040855
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_40855;
	// 0x40AC7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40AC8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40AC9: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40ACA: mov al, 0x01
	X86_REG8L(ctx.eax) = (uint8_t)(1);
	// 0x40ACC: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40ACD: add esp, 0x90
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(144);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)144, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40AD3: ret 0x04
	ctx.esp += 4;
	return;
	// ---- chunk at 0x40855 (size 0x178) ----
loc_40855:
	// 0x40855: mov ebp, [esp+0x14]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x40859: lea esp, [esp]
	ctx.esp = ctx.esp;
	// 0x40860: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x40864: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40865: push 0x3AAFC8
	{ auto _pv = (uint32_t)(3846088); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4086A: lea ecx, [esp+0x68]
	ctx.ecx = ctx.esp + 0x68u;
	// 0x4086E: mov edi, 0x80
	ctx.edi = 128;
	// 0x40873: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40875: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40876: mov [esp+0x30], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.edi);
	// 0x4087A: mov [esp+0x34], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x34u, ctx.edi);
	// 0x4087E: call 0x00243816
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243816(ctx, base);
	ctx.esp += 4;
	// 0x40883: mov esi, [0x004AED9C]
	ctx.esi = X86_MEM_READ_u32(base, 0x4AED9Cu);
	// 0x40889: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x4088C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4088E: lea edx, [esp+0x64]
	ctx.edx = ctx.esp + 0x64u;
	// 0x40892: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40893: call 0x001B33A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CGTFileSystem__Open(ctx, base);
	ctx.esp += 4;
	// 0x40898: mov [esp+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.eax);
	// 0x4089C: lea eax, [esp+0x40]
	ctx.eax = ctx.esp + 0x40u;
	// 0x408A0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408A1: lea ecx, [esp+0x34]
	ctx.ecx = ctx.esp + 0x34u;
	// 0x408A5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408A6: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408A8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408AA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408AC: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408AE: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408B0: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408B2: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x408B4: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x408B6: call 0x00352560
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_EncodeFormat(ctx, base);
	ctx.esp += 4;
	// 0x408BB: push 0x64800000
	{ auto _pv = (uint32_t)(1686110208); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408C0: push 0x14
	{ auto _pv = (uint32_t)(20); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408C2: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x408C4: call 0x001D2879
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemAlloc(ctx, base);
	ctx.esp += 4;
	// 0x408C9: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x408CB: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x408CD: jz 0x00040910
	if (ctx.flags.zf) goto loc_40910;
	// 0x408CF: push 0xB7800000
	{ auto _pv = (uint32_t)(-1216348160); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408D4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408D5: call 0x001D2879
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemAlloc(ctx, base);
	ctx.esp += 4;
	// 0x408DA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x408DC: jnz 0x000408ED
	if (!ctx.flags.zf) goto loc_408ED;
	// 0x408DE: push 0x24800000
	{ auto _pv = (uint32_t)(612368384); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408E3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x408E4: call 0x001D2919
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemFree(ctx, base);
	ctx.esp += 4;
	// 0x408E9: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x408EB: jmp 0x00040910
	goto loc_40910;
loc_408ED:
	// 0x408ED: mov edx, [esp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x408F1: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x408F6: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x408F9: mov eax, [esp+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	// 0x408FD: mov dword ptr [esi], 0x1040001
	X86_MEM_WRITE_u32(base, ctx.esi, 17039361);
	// 0x40903: mov [esi+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.edx);
	// 0x40906: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x40909: mov dword ptr [esi+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 0);
loc_40910:
	// 0x40910: mov [ebp], esi
	X86_MEM_WRITE_u32(base, ctx.ebp, ctx.esi);
	// 0x40913: mov edi, [ebp]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x40916: lea esi, [esp+0x44]
	ctx.esi = ctx.esp + 0x44u;
	// 0x4091A: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x4091C: call 0x003521F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_Get2DSurfaceDesc(ctx, base);
	ctx.esp += 4;
	// 0x40921: mov esi, [ebp]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x40924: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x40926: call 0x00351B50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_BlockOnResource(ctx, base);
	ctx.esp += 4;
	// 0x4092B: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x4092F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40930: lea edx, [esp+0x40]
	ctx.edx = ctx.esp + 0x40u;
	// 0x40934: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40935: lea eax, [esp+0x3C]
	ctx.eax = ctx.esp + 0x3Cu;
	// 0x40939: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4093A: lea ecx, [esp+0x44]
	ctx.ecx = ctx.esp + 0x44u;
	// 0x4093E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4093F: lea edx, [esp+0x38]
	ctx.edx = ctx.esp + 0x38u;
	// 0x40943: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40944: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40945: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40946: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40947: call 0x00352290
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_FindSurfaceWithinTexture(ctx, base);
	ctx.esp += 4;
	// 0x4094C: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x40950: mov edi, [esp+0x28]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// RECOMP FIX: skip vtable Read call when file handle (ecx) is NULL
	if (ctx.ecx != 0) {
	// 0x40954: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x40956: push 0x8000
	{ auto _pv = (uint32_t)(32768); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4095B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4095C: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	} // end null-guard for file handle vtable call
	// 0x4095F: mov eax, [esp+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x40963: call 0x003613E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGBytesPerPixelFromFormat(ctx, base);
	ctx.esp += 4;
	// 0x40968: mov esi, [esp+0x58]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x4096C: imul esi, [esp+0x5C]
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40971: imul esi, eax
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)ctx.eax;
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40974: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40975: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x40979: call 0x00243872
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243872(ctx, base);
	ctx.esp += 4;
	// 0x4097E: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x40980: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x40982: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x40984: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x40988: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x4098B: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x4098D: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x4098F: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x40991: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40994: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40995: mov eax, [esp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x40999: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x4099B: mov edx, [esp+0x5C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	// 0x4099F: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409A1: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x409A4: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x409A6: mov ecx, [esp+0x64]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x64u);
	// 0x409AA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AB: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AD: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409AF: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409B1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409B2: call 0x00361454
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGSwizzleRect(ctx, base);
	ctx.esp += 4;
	// 0x409B7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409B8: call 0x0024386D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	j_free(ctx, base);
	ctx.esp += 4;
	// 0x409BD: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x409C0: mov ebx, 0x01
	ctx.ebx = 1;
	// 0x409C5: jmp 0x000409D0
	sub_409D0(ctx, base);
	return;
loc_409C7:
	// 0x409C7: mov ebp, [esp+0x14]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x409CB: jmp 0x000409D0
	sub_409D0(ctx, base);
	return;
	// ---- chunk at 0x409D0 (size 0xAB) ----
loc_409D0:
	// 0x409D0: mov ecx, [esp+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x409D4: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x409D8: mov edi, [ebp]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x409DB: sar ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)((int32_t)ctx.ecx >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x409DD: sar eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x409DF: lea esi, [esp+0x44]
	ctx.esi = ctx.esp + 0x44u;
	// 0x409E3: mov [esp+0x24], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.ecx);
	// 0x409E7: mov [esp+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.eax);
	// 0x409EB: call 0x003521F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_Get2DSurfaceDesc(ctx, base);
	ctx.esp += 4;
	// 0x409F0: mov esi, [ebp]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x409F3: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x409F5: call 0x00351B50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_BlockOnResource(ctx, base);
	ctx.esp += 4;
	// 0x409FA: lea ecx, [esp+0x38]
	ctx.ecx = ctx.esp + 0x38u;
	// 0x409FE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x409FF: lea edx, [esp+0x38]
	ctx.edx = ctx.esp + 0x38u;
	// 0x40A03: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A04: lea eax, [esp+0x44]
	ctx.eax = ctx.esp + 0x44u;
	// 0x40A08: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A09: lea ecx, [esp+0x1C]
	ctx.ecx = ctx.esp + 0x1Cu;
	// 0x40A0D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A0E: lea edx, [esp+0x3C]
	ctx.edx = ctx.esp + 0x3Cu;
	// 0x40A12: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A13: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A14: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A16: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A17: call 0x00352290
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	D3D_PixelJar_FindSurfaceWithinTexture(ctx, base);
	ctx.esp += 4;
	// 0x40A1C: mov edx, [esp+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x40A20: imul edx, [esp+0x20]
	{ int64_t _res = (int64_t)(int32_t)ctx.edx * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	  ctx.edx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40A25: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x40A29: mov edi, [esp+0x2C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// RECOMP FIX: skip vtable Read call when file handle (ecx) is NULL
	if (ctx.ecx != 0) {
	// 0x40A2D: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x40A2F: shl edx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x40A31: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A32: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A33: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	} // end null-guard for file handle vtable call
	// 0x40A36: mov eax, [esp+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x40A3A: call 0x003613E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGBytesPerPixelFromFormat(ctx, base);
	ctx.esp += 4;
	// 0x40A3F: mov esi, [esp+0x58]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x40A43: imul esi, eax
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)ctx.eax;
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40A46: imul esi, [esp+0x5C]
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x40A4B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40A4C: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x40A50: call 0x00243872
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243872(ctx, base);
	ctx.esp += 4;
	// 0x40A55: mov edx, [esp+0x60]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x60u);
	// 0x40A59: mov ebp, eax
	ctx.ebp = ctx.eax;
	// 0x40A5B: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x40A5D: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x40A5F: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x40A62: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x40A64: mov edi, ebp
	ctx.edi = ctx.ebp;
	// 0x40A66: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x40A68: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40A6B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x40A6D: mov eax, [esp+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x40A71: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x40A74: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x40A76: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x40A7A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
}

void sub_1CE6A0(X86Context& ctx, uint8_t* base) {
	//{ static int _cnt6A0 = 0; uint32_t _chst = X86_MEM_READ_u32(base, ctx.eax + 0x24u); if (_cnt6A0 < 80) { fprintf(stderr, "[DEBUG] sub_1CE6A0 channel=0x%X ch_state=%u\n", ctx.eax, _chst); _cnt6A0++; } }
	// 0x1CE6A0: sub esp, 0x28
	{ uint32_t _d = ctx.esp; uint32_t _s = 40;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1CE6A3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE6A4: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE6A5: mov ebp, [esp+0x3C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1CE6A9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE6AA: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1CE6AC: mov eax, [esi+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x1CE6AF: cmp eax, 0x10
	{ uint32_t _d = ctx.eax; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1CE6B2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE6B3: jnbe 0x001CE8DB
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_1CE8DB;
	// 0x1CE6B9: movzx eax, byte ptr [eax+0x1CE908]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x1CE908u));
	// 0x1CE6C0: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1CE6C2: jmp [eax*4+0x1CE8E8]
	switch (ctx.eax) {
	case 0: goto loc_1CE6C9;
	case 1: goto loc_1CE6DD;
	case 2: goto loc_1CE758;
	case 3: goto loc_1CE781;
	case 4: goto loc_1CE793;
	case 5: goto loc_1CE8BA;
	case 6: goto loc_1CE8CF;
	case 7: goto loc_1CE8DB;
	default: __builtin_unreachable();
	}
loc_1CE6C9:
	// 0x1CE6C9: mov ecx, [esp+0x3C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1CE6CD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE6CE: mov edi, esi
	ctx.edi = ctx.esi;
	// 0x1CE6D0: call 0x001CE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CE500(ctx, base);
	ctx.esp += 4;
	// 0x1CE6D5: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x1CE6D7: jz 0x001CE8DB
	if (ctx.flags.zf) goto loc_1CE8DB;
loc_1CE6DD:
	// 0x1CE6DD: mov edx, [esi+0x24C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x24Cu);
	// 0x1CE6E3: mov eax, [edx+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x18u);
	// 0x1CE6E6: imul eax, [esp+0x40]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x1CE6EB: mov ecx, [esi+0x254]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x254u);
	// 0x1CE6F1: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1CE6F3: mov [esi+0x258], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x258u, ctx.eax);
	// 0x1CE6F9: mov ecx, [eax+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1CE6FC: cmp ebp, ecx
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1CE6FE: jl 0x001CE706
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_1CE706;
	// 0x1CE700: lea ebp, [ecx-0x2800]
	ctx.ebp = ctx.ecx - 0x2800u;
loc_1CE706:
	// 0x1CE706: mov edx, [esi+0x250]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x250u);
	// 0x1CE70C: mov ecx, [edx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x20u);
	// 0x1CE70F: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1CE712: cmp ebp, ebx
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1CE714: cmovl ebp, ebx
	if ((ctx.flags.sf != ctx.flags.of)) ctx.ebp = ctx.ebx;
	// 0x1CE717: add ecx, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.edx, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1CE719: lea eax, [ebp+0x7FF]
	ctx.eax = ctx.ebp + 0x7FFu;
	// 0x1CE71F: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x1CE720: and edx, 0x7FF
	ctx.edx = ctx.edx & 2047;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x1CE726: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1CE728: sar eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1CE72B: shl eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1CE72E: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1CE730: mov [esi+0x22C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x22Cu, ctx.ecx);
	// 0x1CE736: mov ecx, [esi+0x244]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x244u);
	// 0x1CE73C: mov [esi+0x230], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x230u, ctx.eax);
	// 0x1CE742: mov eax, [esi+0x22C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x22Cu);
	// 0x1CE748: mov edi, [ecx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1CE74A: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x1CE74B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE74C: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE74D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE74E: call [edi+0x10]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1CE751: mov dword ptr [esi+0x24], 0x05
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, 5);
loc_1CE758:
	// 0x1CE758: mov ecx, [esi+0x244]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x244u);
	// 0x1CE75E: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1CE760: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1CE763: cmp eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1CE766: jz 0x001CE8DB
	if (ctx.flags.zf) goto loc_1CE8DB;
	// 0x1CE76C: mov dword ptr [esi+0x24], 0x06
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, 6);
	// 0x1CE773: mov [esi+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebx);
	// 0x1CE776: mov [esi+0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ebx);
	// 0x1CE779: mov [esi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.ebx);
	// 0x1CE77C: mov [esi], ebx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ebx);
	// 0x1CE77E: mov [esi+0x2D], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x2Du, X86_REG8L(ctx.ebx));
loc_1CE781:
	// 0x1CE781: call 0x001CEFC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CEFC0(ctx, base);
	ctx.esp += 4;
	// 0x1CE786: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x1CE788: jz 0x001CE8DB
	if (ctx.flags.zf) goto loc_1CE8DB;
	// 0x1CE78E: call 0x001CECE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CECE0(ctx, base);
	ctx.esp += 4;
loc_1CE793:
	// 0x1CE793: mov eax, [esi+0x260]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x260u);
	// 0x1CE799: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1CE79B: mov [esp+0x12], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x12u, ctx.ecx);
	// 0x1CE79F: mov [esp+0x16], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x16u, ctx.ecx);
	// 0x1CE7A3: mov [esp+0x1A], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Au, ctx.ecx);
	// 0x1CE7A7: mov [esp+0x10], bx
	X86_MEM_WRITE_u16(base, ctx.esp + 0x10u, X86_REG16(ctx.ebx));
	// 0x1CE7AC: mov [esp+0x1E], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Eu, ctx.ecx);
	// 0x1CE7B0: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1CE7B2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE7B3: call [edx+0x24]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edx + 0x24u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1CE7B6: mov eax, [esi+0x260]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x260u);
	// 0x1CE7BC: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1CE7BE: lea edx, [esp+0x44]
	ctx.edx = ctx.esp + 0x44u;
	// 0x1CE7C2: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE7C3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE7C4: call [ecx+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1CE7C7: test byte ptr [esp+0x44], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x44u) & 2, 8);
	// 0x1CE7CC: jz 0x001CE8DB
	if (ctx.flags.zf) goto loc_1CE8DB;
	// 0x1CE7D2: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1CE7D4: mov dword ptr [esi+0x24], 0x08
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, 8);
	// 0x1CE7DB: mov ecx, 0x20
	ctx.ecx = 32;
	// 0x1CE7E0: lea edi, [esi+0x9C]
	ctx.edi = ctx.esi + 0x9Cu;
	// 0x1CE7E6: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// HLE fix: pre-fill all 32 streaming buffer status slots with
	// XMP_STATUS_PENDING (0x8000000A) so that sub_1CEAD0 returns 0
	// immediately.  Without real audio playback the streaming state
	// machine (sub_1CE6A0 state 9) would otherwise block forever
	// waiting for all slots to become PENDING via Process calls.
	for (uint32_t _i = 0; _i < 32; _i++) {
		X86_MEM_WRITE_u32(base, ctx.esi + 0x9Cu + _i * 4, 0x8000000Au);
	}
	// 0x1CE7E8: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE7EA: mov [esi+0x20], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.ebx);
	// 0x1CE7ED: mov [esi+0x234], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x234u, ctx.ebx);
	// 0x1CE7F3: call 0x001CE980
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CE980(ctx, base);
	ctx.esp += 4;
	// 0x1CE7F8: mov eax, [esi+0x260]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x260u);
	// 0x1CE7FE: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1CE800: lea edx, [esp+0x24]
	ctx.edx = ctx.esp + 0x24u;
	// 0x1CE804: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE805: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE806: call [ecx+0x28]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ecx + 0x28u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1CE809: mov ecx, [esp+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1CE80D: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1CE80F: mov eax, 0x1F4000
	ctx.eax = 2048000;
	// 0x1CE814: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1CE816: mov [esp+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.ecx);
	// 0x1CE81A: mov word ptr [esp+0x10], 0x01
	X86_MEM_WRITE_u16(base, ctx.esp + 0x10u, 1);
	// 0x1CE821: mov word ptr [esp+0x1E], 0x10
	X86_MEM_WRITE_u16(base, ctx.esp + 0x1Eu, 16);
	// 0x1CE828: mov [esi+0x238], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x238u, ctx.eax);
	// 0x1CE82E: mov eax, [esp+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1CE832: mov [esi+0x23C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x23Cu, ctx.eax);
	// 0x1CE838: mov eax, [esp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x1CE83C: mov [esp+0x12], ax
	X86_MEM_WRITE_u16(base, ctx.esp + 0x12u, X86_REG16(ctx.eax));
	// 0x1CE841: movzx eax, ax
	ctx.eax = (uint32_t)(X86_REG16(ctx.eax));
	// 0x1CE844: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1CE847: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x1CE848: and edx, 0x07
	ctx.edx = ctx.edx & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x1CE84B: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1CE84D: sar eax, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1CE850: movzx edx, ax
	ctx.edx = (uint32_t)(X86_REG16(ctx.eax));
	// 0x1CE853: imul edx, ecx
	{ int64_t _res = (int64_t)(int32_t)ctx.edx * (int64_t)(int32_t)ctx.ecx;
	  ctx.edx = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x1CE856: mov ecx, [esi+0x248]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x248u);
	// 0x1CE85C: mov [esp+0x1C], ax
	X86_MEM_WRITE_u16(base, ctx.esp + 0x1Cu, X86_REG16(ctx.eax));
	// 0x1CE861: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x1CE865: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE866: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE867: mov [esp+0x20], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.edx);
	// 0x1CE86B: call 0x002F6770
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundStream_SetFormat(ctx, base);
	ctx.esp += 4;
	// 0x1CE870: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1CE872: call 0x001CEF70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CEF70(ctx, base);
	ctx.esp += 4;
	// 0x1CE877: push 0x3E000000
	{ auto _pv = (uint32_t)(1040187392); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE87C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE87D: push 0x3F353F7D
	{ auto _pv = (uint32_t)(1060454269); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE882: push 0x3F800000
	{ auto _pv = (uint32_t)(1065353216); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE887: call 0x001CEDB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CEDB0(ctx, base);
	ctx.esp += 4;
	// 0x1CE88C: mov edx, [esi+0x248]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x248u);
	// 0x1CE892: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE893: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1CE894: call 0x002F5751
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundStream_SetHeadroom(ctx, base);
	ctx.esp += 4;
	// 0x1CE899: test byte ptr [esi+0x28], 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x28u) & 8, 8);
	// 0x1CE89D: mov [esi+0x2C], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x2Cu, X86_REG8L(ctx.ebx));
	// 0x1CE8A0: jz 0x001CE8B3
	if (ctx.flags.zf) goto loc_1CE8B3;
	// 0x1CE8A2: call 0x001CEA80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CEA80(ctx, base);
	ctx.esp += 4;
	// 0x1CE8A7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8A8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8A9: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8AA: mov al, 0x01
	X86_REG8L(ctx.eax) = (uint8_t)(1);
	// 0x1CE8AC: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8AD: add esp, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)40, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1CE8B0: ret 0x0C
	ctx.esp += 12;
	return;
loc_1CE8B3:
	// 0x1CE8B3: mov dword ptr [esi+0x24], 0x09
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, 9);
loc_1CE8BA:
	// 0x1CE8BA: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1CE8BC: mov [esi+0x4C], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ebx);
loc_1CE8BF:
	// 0x1CE8BF: call 0x001CEB10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CEB10(ctx, base);
	ctx.esp += 4;
	// 0x1CE8C4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1CE8C6: jnz 0x001CE8DB
	if (!ctx.flags.zf) goto loc_1CE8DB;
	// 0x1CE8C8: mov dword ptr [esi+0x24], 0x0A
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, 10);
loc_1CE8CF:
	// 0x1CE8CF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8D0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8D1: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8D2: mov al, 0x01
	X86_REG8L(ctx.eax) = (uint8_t)(1);
	// 0x1CE8D4: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8D5: add esp, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)40, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1CE8D8: ret 0x0C
	ctx.esp += 12;
	return;
loc_1CE8DB:
	// 0x1CE8DB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8DC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8DD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8DE: xor al, al
	X86_REG8L(ctx.eax) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x1CE8E0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1CE8E1: add esp, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)40, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1CE8E4: ret 0x0C
	ctx.esp += 12;
	return;
}


// [HLE] sub_1B58E0 — Timer update function.
// Measures elapsed TSC time since last call, computes how many game ticks
// should have elapsed, and returns that count (clamped to [minTicks, maxTicks]).
//
// Timer struct layout (at esi):
//   +0x00: mode (int32)       — 0 = normal, 2 = uncapped
//   +0x08: lastQPC_lo (u32)   — low dword of last TSC snapshot
//   +0x0C: lastQPC_hi (u32)   — high dword of last TSC snapshot
//   +0x10: accum_lo (u32)     — accumulated remainder (TSC ticks beyond consumed)
//   +0x14: accum_hi (u32)
//   +0x18: maxPeriod_lo (u32) — TSC ticks for max-step threshold
//   +0x1C: maxPeriod_hi (u32)
//   +0x20: tickPeriod_lo (u32)— TSC ticks per game tick
//   +0x24: tickPeriod_hi (u32)
//   +0x28: lastReturned (i32) — ticks returned last call
//   +0x2C: counter (i32)      — accumulated counter (starts -1)
//   +0x30: carryover (i32)
//   +0x34: paused (u8)
//
// Called as: sub_1B58E0(esi=timerObj, stack: minTicks, maxTicks)
// Returns: eax = number of ticks to simulate
void sub_1B58E0(X86Context& ctx, uint8_t* base) {
	// Read args from guest stack (ret addr already on stack, args after it)
	uint32_t minTicks = X86_MEM_READ_u32(base, ctx.esp + 0x04u);
	uint32_t maxTicks = X86_MEM_READ_u32(base, ctx.esp + 0x08u);
	uint32_t timerAddr = ctx.esi;

	// On real Xbox, 60fps meant max=4 was plenty. On PC with software rendering,
	// FPS can drop below 15 where max=4 can't compensate. Raise cap to allow
	// the timer to return enough ticks to maintain real-time game speed.
	if (maxTicks > 0 && maxTicks < 16) maxTicks = 16;

	// Get current TSC
	uint64_t currentQPC = X86_RDTSC();

	// Read paused flag
	uint8_t paused = X86_MEM_READ_u8(base, timerAddr + 0x34u);

	// Read timer state
	int32_t counter   = (int32_t)X86_MEM_READ_u32(base, timerAddr + 0x2Cu);
	int32_t lastRet   = (int32_t)X86_MEM_READ_u32(base, timerAddr + 0x28u);
	uint64_t lastQPC  = ((uint64_t)X86_MEM_READ_u32(base, timerAddr + 0x0Cu) << 32)
	                   | X86_MEM_READ_u32(base, timerAddr + 0x08u);
	int64_t accum     = (int64_t)(((uint64_t)X86_MEM_READ_u32(base, timerAddr + 0x14u) << 32)
	                   | X86_MEM_READ_u32(base, timerAddr + 0x10u));
	int64_t tickPeriod= (int64_t)(((uint64_t)X86_MEM_READ_u32(base, timerAddr + 0x24u) << 32)
	                   | X86_MEM_READ_u32(base, timerAddr + 0x20u));

	// Override tickPeriod: the game re-inits this timer from 16.67ms to 33.33ms at 0x16ED1,
	// which breaks variable-framerate compensation. Derive correct period from the actual
	// deltaTime constant (dword_49C120 = 0.01667s) so 1 tick = 1 deltaTime of real TSC time.
	{
		float deltaTime;
		uint32_t dtBits = X86_MEM_READ_u32(base, 0x49C120u);
		memcpy(&deltaTime, &dtBits, sizeof(float));
		if (deltaTime > 0.0f) {
			tickPeriod = (int64_t)(733333333.0 * (double)deltaTime);
		}
	}

	// First-call init: counter starts at -1, adding lastRet (typically 1) makes it <=0
	counter += lastRet;
	X86_MEM_WRITE_u32(base, timerAddr + 0x2Cu, (uint32_t)counter);

	if (!paused && counter <= 0) {
		// First call — just record the current QPC and return minTicks
		X86_MEM_WRITE_u32(base, timerAddr + 0x08u, (uint32_t)(currentQPC));
		X86_MEM_WRITE_u32(base, timerAddr + 0x0Cu, (uint32_t)(currentQPC >> 32));
		X86_MEM_WRITE_u32(base, timerAddr + 0x28u, minTicks);
		ctx.eax = minTicks;
		// Clean up: ret 0x08 (pop 2 args)
		ctx.esp += 8;
		return;
	}

	int32_t resultTicks = (int32_t)minTicks;

	if (!paused) {
		// Normal path: compute elapsed ticks
		int64_t delta = (int64_t)(currentQPC - lastQPC);
		accum += delta;

		// How many TSC ticks we've "consumed" so far
		int64_t consumed = (int64_t)counter * tickPeriod;
		int64_t remainder = accum - consumed;

		// If remainder > 0, compute additional ticks beyond minTicks
		if (tickPeriod > 0 && remainder > 0) {
			int64_t additionalTicks = (remainder + tickPeriod - 1) / tickPeriod;
			resultTicks = (int32_t)minTicks + (int32_t)additionalTicks;
		}

		// Store updated accumulator
		X86_MEM_WRITE_u32(base, timerAddr + 0x10u, (uint32_t)((uint64_t)accum));
		X86_MEM_WRITE_u32(base, timerAddr + 0x14u, (uint32_t)((uint64_t)accum >> 32));
	} else {
		// Paused: no time passes, but still allow minTicks
		resultTicks = (int32_t)minTicks;
	}

	// Clamp to maxTicks (unless mode == 2 which is uncapped)
	int32_t mode = (int32_t)X86_MEM_READ_u32(base, timerAddr);
	if (resultTicks > (int32_t)maxTicks && mode != 2) {
		// Adjust accumulator to account for the clamped ticks
		int32_t excess = resultTicks - (int32_t)maxTicks;
		int64_t excessTSC = (int64_t)excess * tickPeriod;
		accum -= excessTSC;
		X86_MEM_WRITE_u32(base, timerAddr + 0x10u, (uint32_t)((uint64_t)accum));
		X86_MEM_WRITE_u32(base, timerAddr + 0x14u, (uint32_t)((uint64_t)accum >> 32));
		resultTicks = (int32_t)maxTicks;
	}

	// Store current QPC as last
	X86_MEM_WRITE_u32(base, timerAddr + 0x08u, (uint32_t)(currentQPC));
	X86_MEM_WRITE_u32(base, timerAddr + 0x0Cu, (uint32_t)(currentQPC >> 32));

	// Store last returned ticks (if not paused)
	if (!paused) {
		X86_MEM_WRITE_u32(base, timerAddr + 0x28u, (uint32_t)resultTicks);
	}

	// Clear carryover
	X86_MEM_WRITE_u32(base, timerAddr + 0x30u, 0);

	// Return
	ctx.eax = (uint32_t)resultTicks;

	// static int s_logCount = 0;
	// if (s_logCount < 500) {
	// 	fprintf(stderr, "[TIMER] esi=0x%08X delta=%lld tickPeriod=%lld result=%d min=%u max=%u counter=%d\n",
	// 		timerAddr, (long long)(currentQPC - lastQPC), (long long)tickPeriod,
	// 		resultTicks, minTicks, maxTicks, counter);
	// 	s_logCount++;
	// }

	// Clean up: ret 0x08 (pop 2 args)
	ctx.esp += 8;
}