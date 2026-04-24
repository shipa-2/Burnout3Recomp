#include "x86_recomp_shared.h"
#include "kernel/function.h"
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

void _xstart(X86Context& ctx, uint8_t* base) {
	// 0x4B34B: mov ecx, [0x00010118]
	ctx.ecx = X86_MEM_READ_u32(base, 0x10118u);
	// 0x4B351: mov eax, [0x00010108]
	ctx.eax = X86_MEM_READ_u32(base, 0x10108u);
	// 0x4B356: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x4B358: add eax, 0x10000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(65536);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)65536, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x4B35D: cmp eax, [ecx]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x4B35F: jnb 0x0004B363
	if (!ctx.flags.cf) goto loc_4B363;
	// 0x4B361: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
loc_4B363:
	// 0x4B363: mov eax, [0x000EDF44]
	ctx.eax = X86_MEM_READ_u32(base, 0xEDF44u);
	// 0x4B368: sub eax, [0x000EDF34]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0xEDF34u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x4B36E: mov ecx, [0x000EDF38]
	ctx.ecx = X86_MEM_READ_u32(base, 0xEDF38u);
	// 0x4B374: push esi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.esi);
	// 0x4B375: lea eax, [eax+ecx*1+0x0F]
	ctx.eax = ctx.eax + ctx.ecx + 0xFu;
	// 0x4B379: push edi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.edi);
	// 0x4B37A: and eax, 0xFFFFFFF0
	ctx.eax = ctx.eax & -16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x4B37D: push 0xFFFFFFFC
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, -4);
	// 0x4B37F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x4B380: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x4B383: mov [0x0016C7BC], eax
	X86_MEM_WRITE_u32(base, 0x16C7BCu, ctx.eax);
	// 0x4B388: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x4B389: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x4B38B: mov ecx, [0x000EDF3C]
	ctx.ecx = X86_MEM_READ_u32(base, 0xEDF3Cu);
	// 0x4B391: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x4B393: push esi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.esi);
	// 0x4B394: push esi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.esi);
	// 0x4B395: push esi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.esi);
	// 0x4B396: push 0x4B2D7
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 307927);
	// 0x4B39B: push esi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.esi);
	// 0x4B39C: push esi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.esi);
	// 0x4B39D: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);

	// --- HLE: Replace CreateThread + CloseHandle with a real host thread ---
	// The original code calls CreateThread(mainXapiStartup, ...) which spawns
	// a kernel thread running mainXapiStartup, then immediately closes the
	// handle and returns. Instead, we run mainXapiStartup on a std::thread
	// and wait for it to finish.

	// Clean up the 6 dwords pushed as CreateThread args (it does `ret 0x18`).
	ctx.esp += 24;

	fprintf(stdout, "[HLE] _xstart: spawning game thread (mainXapiStartup)\n");

	std::thread gameThread([base]()
	{
		X86Context threadCtx{};
		memset(&threadCtx, 0, sizeof(threadCtx));

		// Give the thread its own guest stack (separate from the main stack).
		threadCtx.esp = 0x07E00000;
		threadCtx.ebp = 0x07E00000;

		// Default x87 FPU control word.
		threadCtx.fp_control = 0x037F;

		// mainXapiStartup expects a thread parameter on the stack
		// (pushed by the kernel before the thread starts) and ends
		// with `ret 4`. Push a dummy param + dummy return address.
		threadCtx.esp -= 4;
		X86_MEM_WRITE_u32(base, threadCtx.esp, 0); // thread parameter
		threadCtx.esp -= 4;
		X86_MEM_WRITE_u32(base, threadCtx.esp, 0); // dummy return address

		mainXapiStartup(threadCtx, base);
	});

	gameThread.join();
	fprintf(stdout, "[HLE] _xstart: game thread finished\n");

	// 0x4B3BA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x4B3BB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x4B3BC: ret
	return;
}

void mainXapiStartup(X86Context& ctx, uint8_t* base) {
	// 0x4B2D7: call 0x0004C68E
	// sub_4C68E does kernel version detection and CRT .INIT section setup.
	// It reads kernel PE header at 0x80010000 (not mapped) and accesses
	// fs:[0x20] (KPCR) which is zero, leading to sub_4C62A crash.
	// Skip entirely — not needed in recompiled environment.
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	// sub_4C68E(ctx, base);  // DISABLED — reads unmapped Xbox kernel memory
	ctx.esp += 4; // balance the dummy return address push
	// 0x4B2DC: call 0x0004C43A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XapiInitProcess(ctx, base);
	// 0x4B2E1: mov eax, fs:[0x00000020]
	ctx.eax = X86_MEM_READ_u32(base, 0x20u);
	// 0x4B2E7: mov eax, [eax+0x250]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x250u);
	// 0x4B2ED: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x4B2EF: jz 0x0004B2F6
	if (ctx.flags.zf) goto loc_4B2F6;
	// 0x4B2F1: mov ecx, [eax+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x24u);
	// 0x4B2F4: jmp 0x0004B2F8
	goto loc_4B2F8;
loc_4B2F6:
	// 0x4B2F6: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_4B2F8:
	// 0x4B2F8: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x4B2FA: jz 0x0004B323
	if (ctx.flags.zf) goto loc_4B323;
	// 0x4B2FC: push edi
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.edi);
	// 0x4B2FD: mov eax, fs:[0x00000028]
	ctx.eax = X86_MEM_READ_u32(base, 0x28u);
	// 0x4B303: mov edi, fs:[0x00000004]
	ctx.edi = X86_MEM_READ_u32(base, 0x4u);
	// 0x4B30A: mov edx, [0x0012F864]
	ctx.edx = X86_MEM_READ_u32(base, 0x12F864u);
	// 0x4B310: mov edx, [edi+edx*4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + ctx.edx * 4);
	// 0x4B313: sub edx, [eax+0x28]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x4B316: mov byte ptr [ecx], 0x01
	X86_MEM_WRITE_u8(base, ctx.ecx, 1);
	// 0x4B319: add edx, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)8, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x4B31F: mov [ecx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.edx);
	// 0x4B322: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_4B323:
	// 0x4B323: call 0x0004C601 — _rtinit
	// HLE: safely iterate CRT .INIT tables, only calling entries that
	// have handlers in g_funcMap (skips corrupt / unrecompiled pointers).
	{
		auto safeCrtTableCall = [&](const char* label, uint32_t tableStart, uint32_t tableEnd) {
			fprintf(stderr, "[HLE] %s: iterating CRT table [0x%06X..0x%06X)\n",
					label, tableStart, tableEnd);
			for (uint32_t addr = tableStart; addr < tableEnd; addr += 4) {
				uint32_t fptr = X86_MEM_READ_u32(base, addr);
				if (fptr == 0 || fptr == 0xFFFFFFFF) continue;
				auto it = g_funcMap.find(fptr);
				if (it != g_funcMap.end()) {
					fprintf(stderr, "[HLE]   [0x%06X] = 0x%08X — calling\n", addr, fptr);
					ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
					it->second(ctx, base);
				} else {
					fprintf(stderr, "[HLE]   [0x%06X] = 0x%08X — skipped (no handler)\n", addr, fptr);
				}
			}
		};

		// _rtinit: .CRT$XRA → .CRT$XRZ (runtime init)
		safeCrtTableCall("_rtinit", 0xF5680, 0xF568C);

		// _cinit: first check optional pre-init callback at [0x1294FC]
		{
			uint32_t preInit = X86_MEM_READ_u32(base, 0x1294FCu);
			if (preInit != 0) {
				auto it = g_funcMap.find(preInit);
				if (it != g_funcMap.end()) {
					fprintf(stderr, "[HLE] _cinit pre-init [0x1294FC] = 0x%08X — calling\n", preInit);
					ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
					it->second(ctx, base);
				} else {
					fprintf(stderr, "[HLE] _cinit pre-init [0x1294FC] = 0x%08X — skipped\n", preInit);
				}
			}
		}

		// _cinit: .CRT$XCA → .CRT$XCZ (C++ constructors)
		safeCrtTableCall("_cinit/XC", 0xF56C0, 0xF56D4);

		// _cinit: .CRT$XIA → .CRT$XIZ (C initializers)
		safeCrtTableCall("_cinit/XI", 0xF5690, 0xF56BC);
	}
	// 0x4B32D: push 0x00
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 0);
	// 0x4B32F: push 0x00
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 0);
	// 0x4B331: push 0x00
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 0);
	// 0x4B333: call 0x0001A760
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1A760(ctx, base);
	// 0x4B338: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x4B33B: push 0x00
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 0);
	// 0x4B33D: push 0x01
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 1);
	// 0x4B33F: push 0x01
	ctx.esp -= 4;
	X86_MEM_WRITE_u32(base, ctx.esp, 1);
	// 0x4B341: call 0x0004C3C4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XapiBootToDash(ctx, base);
	// 0x4B346: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x4B348: ret 0x04
	ctx.esp += 4 + 4;
	return;
}

void sub_8A92E(X86Context& ctx, uint8_t* base) {
	// HLE: Xbox debug CRT internal alloc (essentially a VirtualAlloc wrapper).
	// The debug build fills returned blocks with 0xB7B7B7B7, breaking code
	// that relies on zeroed memory. GuestMalloc returns zeroed, page-aligned
	// memory instead. For oversized probe requests (e.g. the 528 MB debug CRT
	// heap probe), GuestMalloc returns 0; the probe chain (sub_8A955/sub_8A981)
	// handles the failure gracefully without corrupting guest memory.
	uint32_t size = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	ctx.eax = GuestMalloc(size, base); // 0 on OOM or oversized probe
}

void sub_8B0C9(X86Context& ctx, uint8_t* base) {
	// HLE: no-op free. We use a bump allocator (GuestVMAlloc) so blocks are
	// never recycled — this is safe for a process-lifetime heap.
	// The original debug CRT heap validation is intentionally skipped.
	(void)ctx; (void)base;
}

void sub_8BE69(X86Context& ctx, uint8_t* base) {
	// HLE: realloc(old_ptr, new_size) via GuestMalloc.
	// The original routes through the Xbox debug CRT aligned-realloc (sub_8BF10 →
	// sub_8E7DE → opaque function-pointer heap), which cannot handle pointers that
	// originated from GuestMalloc. This caused the lumpinfo realloc to silently
	// mis-behave and leave [0x1354E0] pointing at the stale 1-byte initial block,
	// so W_CheckNumForName always scanned zeroed memory and returned -1.
	// Fix: provide a clean bump-allocator realloc (malloc new, memcpy old, return new).
	// Caller convention: push new_size first, then old_ptr → [esp+4]=old_ptr, [esp+8]=new_size.
	{
		uint32_t old_ptr  = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
		uint32_t new_size = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
		if (new_size == 0) {
			ctx.eax = 0; // realloc(ptr,0) → free + NULL
			return;
		}
		uint32_t new_ptr = GuestMalloc(new_size, base);
		if (new_ptr && old_ptr) {
			// Copy old contents. We don't track old alloc size; copying new_size bytes is
			// safe because GuestVM memory is zeroed beyond allocated extents.
			memcpy(base + new_ptr, base + old_ptr, new_size);
		}
		ctx.eax = new_ptr; // old_ptr "freed" — bump allocator, no-op
		return;
	}
}

void sub_8A744(X86Context& ctx, uint8_t* base) {
	// HLE: strtok - original uses fs:-based TLS via __getptd (sub_8E4A6)
	// which is not initialised in the recompiled environment, causing
	// strtok to always return NULL and breaking TiMidity config parsing.
	uint32_t strArg = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	uint32_t delimArg = X86_MEM_READ_u32(base, ctx.esp + 0x8u);

	char* str = strArg ? (char*)(base + strArg) : nullptr;
	const char* delim = (const char*)(base + delimArg);

	char* result = strtok(str, delim);

	ctx.eax = result ? (uint32_t)(result - (char*)base) : 0;
	return;
}