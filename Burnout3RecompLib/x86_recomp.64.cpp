#include "x86_recomp_shared.h"

void sub_2A23E0(X86Context& ctx, uint8_t* base) {
	// 0x2A23E0: movss xmm0, dword ptr [0x0056FDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A23E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A23F0: movss [0x0056FD8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD8Cu, ctx.xmm[0].u32[0]);
	// 0x2A23F8: ret
	return;
}

void sub_2A2400(X86Context& ctx, uint8_t* base) {
	// 0x2A2400: movss xmm0, dword ptr [0x0056FD18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD18u);
	// 0x2A2408: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A2410: movss [0x0056FDC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDC0u, ctx.xmm[0].u32[0]);
	// 0x2A2418: ret
	return;
}

void sub_2A2420(X86Context& ctx, uint8_t* base) {
	// 0x2A2420: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A2428: movss [0x0056FD10], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD10u, ctx.xmm[0].u32[0]);
	// 0x2A2430: ret
	return;
}

void sub_2A2440(X86Context& ctx, uint8_t* base) {
	// 0x2A2440: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A2448: movss [0x0056FD5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD5Cu, ctx.xmm[0].u32[0]);
	// 0x2A2450: ret
	return;
}

void sub_2A2460(X86Context& ctx, uint8_t* base) {
	// 0x2A2460: movss xmm0, dword ptr [0x0056FD58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD58u);
	// 0x2A2468: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A2470: movss [0x0056FD78], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD78u, ctx.xmm[0].u32[0]);
	// 0x2A2478: ret
	return;
}

void sub_2A2480(X86Context& ctx, uint8_t* base) {
	// 0x2A2480: movss xmm0, dword ptr [0x0056FDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A2488: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A2490: movss [0x0056FDEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDECu, ctx.xmm[0].u32[0]);
	// 0x2A2498: ret
	return;
}

void sub_2A24A0(X86Context& ctx, uint8_t* base) {
	// 0x2A24A0: movss xmm0, dword ptr [0x0056FD78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD78u);
	// 0x2A24A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A24B0: movss [0x0056FDD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDD8u, ctx.xmm[0].u32[0]);
	// 0x2A24B8: ret
	return;
}

void sub_2A24C0(X86Context& ctx, uint8_t* base) {
	// 0x2A24C0: movss xmm0, dword ptr [0x0056FDEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDECu);
	// 0x2A24C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A24D0: movss [0x0056FDFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDFCu, ctx.xmm[0].u32[0]);
	// 0x2A24D8: ret
	return;
}

void sub_2A24E0(X86Context& ctx, uint8_t* base) {
	// 0x2A24E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A24E8: movss [0x0056FD1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD1Cu, ctx.xmm[0].u32[0]);
	// 0x2A24F0: ret
	return;
}

void sub_2A2500(X86Context& ctx, uint8_t* base) {
	// 0x2A2500: movss xmm0, dword ptr [0x0056FD58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD58u);
	// 0x2A2508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2510: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A2518: movss [0x0056FDE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDE4u, ctx.xmm[0].u32[0]);
	// 0x2A2520: ret
	return;
}

void sub_2A2530(X86Context& ctx, uint8_t* base) {
	// 0x2A2530: movss xmm0, dword ptr [0x0056FDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A2538: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2540: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A2548: movss [0x0056FD48], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD48u, ctx.xmm[0].u32[0]);
	// 0x2A2550: ret
	return;
}

void sub_2A2560(X86Context& ctx, uint8_t* base) {
	// 0x2A2560: movss xmm0, dword ptr [0x0056FD58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD58u);
	// 0x2A2568: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2570: movss [0x0056FD4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD4Cu, ctx.xmm[0].u32[0]);
	// 0x2A2578: ret
	return;
}

void sub_2A2580(X86Context& ctx, uint8_t* base) {
	// 0x2A2580: movss xmm0, dword ptr [0x0056FDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A2588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2590: movss [0x0056FDF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDF0u, ctx.xmm[0].u32[0]);
	// 0x2A2598: ret
	return;
}

void sub_2A25A0(X86Context& ctx, uint8_t* base) {
	// 0x2A25A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A25A8: movss [0x0056FD20], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD20u, ctx.xmm[0].u32[0]);
	// 0x2A25B0: ret
	return;
}

void sub_2A25C0(X86Context& ctx, uint8_t* base) {
	// 0x2A25C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A25C8: movss [0x0056FD64], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD64u, ctx.xmm[0].u32[0]);
	// 0x2A25D0: ret
	return;
}

void sub_2A25E0(X86Context& ctx, uint8_t* base) {
	// 0x2A25E0: movss xmm0, dword ptr [0x0056FD20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD20u);
	// 0x2A25E8: movss [0x0056FE18], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE18u, ctx.xmm[0].u32[0]);
	// 0x2A25F0: ret
	return;
}

void sub_2A2600(X86Context& ctx, uint8_t* base) {
	// 0x2A2600: movss xmm0, dword ptr [0x0056FDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A2608: subss xmm0, [0x0056FD20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FD20u);
	// 0x2A2610: movss [0x0056FDC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDC4u, ctx.xmm[0].u32[0]);
	// 0x2A2618: ret
	return;
}

void sub_2A2620(X86Context& ctx, uint8_t* base) {
	// 0x2A2620: movss xmm0, dword ptr [0x0056FDC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDC4u);
	// 0x2A2628: subss xmm0, [0x0056FD64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FD64u);
	// 0x2A2630: movss [0x0056FDA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDA8u, ctx.xmm[0].u32[0]);
	// 0x2A2638: ret
	return;
}

void sub_2A2640(X86Context& ctx, uint8_t* base) {
	// 0x2A2640: movss xmm0, dword ptr [0x0056FDF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDF0u);
	// 0x2A2648: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A2650: movss [0x0056FD84], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD84u, ctx.xmm[0].u32[0]);
	// 0x2A2658: ret
	return;
}

void sub_2A2660(X86Context& ctx, uint8_t* base) {
	// 0x2A2660: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A2668: movss [0x0056FD60], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD60u, ctx.xmm[0].u32[0]);
	// 0x2A2670: ret
	return;
}

void sub_2A2680(X86Context& ctx, uint8_t* base) {
	// 0x2A2680: movss xmm0, dword ptr [0x0056FD84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD84u);
	// 0x2A2688: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A2690: movss [0x0056FDE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDE0u, ctx.xmm[0].u32[0]);
	// 0x2A2698: ret
	return;
}

void sub_2A26A0(X86Context& ctx, uint8_t* base) {
	// 0x2A26A0: movss xmm0, dword ptr [0x003B1824]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1824u);
	// 0x2A26A8: movss [0x0056FD88], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD88u, ctx.xmm[0].u32[0]);
	// 0x2A26B0: ret
	return;
}

void sub_2A26C0(X86Context& ctx, uint8_t* base) {
	// 0x2A26C0: movss xmm0, dword ptr [0x0056FD88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD88u);
	// 0x2A26C8: mulss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A26D0: movss xmm1, dword ptr [0x0056FDF0]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x56FDF0u);
	// 0x2A26D8: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x2A26DC: movss [0x0056FD50], xmm1
	X86_MEM_WRITE_u32(base, 0x56FD50u, ctx.xmm[1].u32[0]);
	// 0x2A26E4: ret
	return;
}

void sub_2A26F0(X86Context& ctx, uint8_t* base) {
	// 0x2A26F0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2A26F1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2A26F3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2A26F6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2A26F9: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2A26FC: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2A2701: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2A2704: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2A270A: movss xmm0, dword ptr [0x0056FD4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD4Cu);
	// 0x2A2712: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A271A: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2A271E: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2A2724: movss xmm0, dword ptr [0x003B1728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1728u);
	// 0x2A272C: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2A2730: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2A2736: mov [0x0056FD98], eax
	X86_MEM_WRITE_u32(base, 0x56FD98u, ctx.eax);
	// 0x2A273B: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2A273F: mov [0x0056FD9C], ecx
	X86_MEM_WRITE_u32(base, 0x56FD9Cu, ctx.ecx);
	// 0x2A2745: mov [0x0056FDA0], edx
	X86_MEM_WRITE_u32(base, 0x56FDA0u, ctx.edx);
	// 0x2A274B: mov [0x0056FDA4], eax
	X86_MEM_WRITE_u32(base, 0x56FDA4u, ctx.eax);
	// 0x2A2750: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2A2752: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2A2753: ret
	return;
}

void sub_2A2760(X86Context& ctx, uint8_t* base) {
	// 0x2A2760: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2A2761: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2A2763: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2A2766: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2A2769: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2A276C: movss xmm1, dword ptr [0x003B1C30]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2A2774: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2A2779: movss xmm0, dword ptr [0x0056FD84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD84u);
	// 0x2A2781: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2A2784: movaps xmm2, xmm0
	ctx.xmm[2] = ctx.xmm[0];
	// 0x2A2787: addss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A278F: mulss xmm2, xmm1
	ctx.xmm[2].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A2793: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x2A2799: movss xmm2, dword ptr [0x0056FD4C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x56FD4Cu);
	// 0x2A27A1: mulss xmm2, [0x003B1A90]
	ctx.xmm[2].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A27A9: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2A27AD: mulss xmm0, xmm1
	ctx.xmm[0].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A27B1: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x2A27B7: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2A27BB: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2A27C1: mov [0x0056FDB0], eax
	X86_MEM_WRITE_u32(base, 0x56FDB0u, ctx.eax);
	// 0x2A27C6: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2A27CA: mov [0x0056FDB4], ecx
	X86_MEM_WRITE_u32(base, 0x56FDB4u, ctx.ecx);
	// 0x2A27D0: mov [0x0056FDB8], edx
	X86_MEM_WRITE_u32(base, 0x56FDB8u, ctx.edx);
	// 0x2A27D6: mov [0x0056FDBC], eax
	X86_MEM_WRITE_u32(base, 0x56FDBCu, ctx.eax);
	// 0x2A27DB: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2A27DD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2A27DE: ret
	return;
}

void sub_2A27E0(X86Context& ctx, uint8_t* base) {
	// 0x2A27E0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2A27E1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2A27E3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2A27E6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2A27E9: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2A27EC: movss xmm1, dword ptr [0x003B1C30]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2A27F4: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2A27F9: movss xmm0, dword ptr [0x0056FD60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD60u);
	// 0x2A2801: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2A2804: movaps xmm2, xmm0
	ctx.xmm[2] = ctx.xmm[0];
	// 0x2A2807: addss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A280F: mulss xmm2, xmm1
	ctx.xmm[2].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A2813: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x2A2819: movss xmm2, dword ptr [0x0056FD4C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x56FD4Cu);
	// 0x2A2821: mulss xmm2, [0x003B1A90]
	ctx.xmm[2].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A2829: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2A282D: mulss xmm0, xmm1
	ctx.xmm[0].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A2831: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x2A2837: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2A283B: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2A2841: mov [0x0056FD30], eax
	X86_MEM_WRITE_u32(base, 0x56FD30u, ctx.eax);
	// 0x2A2846: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2A284A: mov [0x0056FD34], ecx
	X86_MEM_WRITE_u32(base, 0x56FD34u, ctx.ecx);
	// 0x2A2850: mov [0x0056FD38], edx
	X86_MEM_WRITE_u32(base, 0x56FD38u, ctx.edx);
	// 0x2A2856: mov [0x0056FD3C], eax
	X86_MEM_WRITE_u32(base, 0x56FD3Cu, ctx.eax);
	// 0x2A285B: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2A285D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2A285E: ret
	return;
}

void sub_2A2860(X86Context& ctx, uint8_t* base) {
	// 0x2A2860: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2A2861: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2A2863: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2A2866: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2A2869: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2A286C: movss xmm1, dword ptr [0x003B1C30]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2A2874: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2A2879: movss xmm0, dword ptr [0x0056FDE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDE0u);
	// 0x2A2881: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2A2884: movaps xmm2, xmm0
	ctx.xmm[2] = ctx.xmm[0];
	// 0x2A2887: addss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A288F: mulss xmm2, xmm1
	ctx.xmm[2].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A2893: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x2A2899: movss xmm2, dword ptr [0x0056FD4C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x56FD4Cu);
	// 0x2A28A1: mulss xmm2, [0x003B1A90]
	ctx.xmm[2].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A28A9: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2A28AD: mulss xmm0, xmm1
	ctx.xmm[0].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A28B1: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x2A28B7: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2A28BB: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2A28C1: mov [0x0056FE08], eax
	X86_MEM_WRITE_u32(base, 0x56FE08u, ctx.eax);
	// 0x2A28C6: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2A28CA: mov [0x0056FE0C], ecx
	X86_MEM_WRITE_u32(base, 0x56FE0Cu, ctx.ecx);
	// 0x2A28D0: mov [0x0056FE10], edx
	X86_MEM_WRITE_u32(base, 0x56FE10u, ctx.edx);
	// 0x2A28D6: mov [0x0056FE14], eax
	X86_MEM_WRITE_u32(base, 0x56FE14u, ctx.eax);
	// 0x2A28DB: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2A28DD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2A28DE: ret
	return;
}

void sub_2A28E0(X86Context& ctx, uint8_t* base) {
	// 0x2A28E0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2A28E1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2A28E3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2A28E6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2A28E9: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2A28EC: movss xmm1, dword ptr [0x003B1C30]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2A28F4: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2A28F9: movss xmm0, dword ptr [0x0056FD88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD88u);
	// 0x2A2901: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2A2904: movaps xmm2, xmm0
	ctx.xmm[2] = ctx.xmm[0];
	// 0x2A2907: addss xmm0, [0x0056FD50]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x56FD50u);
	// 0x2A290F: mulss xmm2, xmm1
	ctx.xmm[2].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A2913: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x2A2919: movss xmm2, dword ptr [0x0056FD4C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x56FD4Cu);
	// 0x2A2921: mulss xmm2, [0x003B1A90]
	ctx.xmm[2].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A2929: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2A292D: mulss xmm0, xmm1
	ctx.xmm[0].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2A2931: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x2A2937: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2A293B: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2A2941: mov [0x0056FD68], eax
	X86_MEM_WRITE_u32(base, 0x56FD68u, ctx.eax);
	// 0x2A2946: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2A294A: mov [0x0056FD6C], ecx
	X86_MEM_WRITE_u32(base, 0x56FD6Cu, ctx.ecx);
	// 0x2A2950: mov [0x0056FD70], edx
	X86_MEM_WRITE_u32(base, 0x56FD70u, ctx.edx);
	// 0x2A2956: mov [0x0056FD74], eax
	X86_MEM_WRITE_u32(base, 0x56FD74u, ctx.eax);
	// 0x2A295B: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2A295D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2A295E: ret
	return;
}

void sub_2A2960(X86Context& ctx, uint8_t* base) {
	// 0x2A2960: movss xmm0, dword ptr [0x0056FD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD64u);
	// 0x2A2968: addss xmm0, [0x0056FD20]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x56FD20u);
	// 0x2A2970: movss [0x0056FD0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD0Cu, ctx.xmm[0].u32[0]);
	// 0x2A2978: ret
	return;
}

void sub_2A2980(X86Context& ctx, uint8_t* base) {
	// 0x2A2980: movss xmm0, dword ptr [0x0056FD0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD0Cu);
	// 0x2A2988: mulss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A2990: movss xmm1, dword ptr [0x0056FDE8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A2998: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x2A299C: movss [0x0056FD54], xmm1
	X86_MEM_WRITE_u32(base, 0x56FD54u, ctx.xmm[1].u32[0]);
	// 0x2A29A4: ret
	return;
}

void sub_2A29B0(X86Context& ctx, uint8_t* base) {
	// 0x2A29B0: movss xmm0, dword ptr [0x0056FD20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD20u);
	// 0x2A29B8: mulss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A29C0: movss xmm1, dword ptr [0x0056FDE8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x56FDE8u);
	// 0x2A29C8: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x2A29CC: movss [0x0056FE04], xmm1
	X86_MEM_WRITE_u32(base, 0x56FE04u, ctx.xmm[1].u32[0]);
	// 0x2A29D4: ret
	return;
}

void sub_2A29E0(X86Context& ctx, uint8_t* base) {
	// 0x2A29E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A29E8: movss [0x0056FDCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDCCu, ctx.xmm[0].u32[0]);
	// 0x2A29F0: ret
	return;
}

void sub_2A2A00(X86Context& ctx, uint8_t* base) {
	// 0x2A2A00: movss xmm0, dword ptr [0x0056FD58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD58u);
	// 0x2A2A08: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A2A10: movss [0x004066B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4066B0u, ctx.xmm[0].u32[0]);
	// 0x2A2A18: ret
	return;
}

void sub_2A2A20(X86Context& ctx, uint8_t* base) {
	// 0x2A2A20: movss xmm0, dword ptr [0x0056FD58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD58u);
	// 0x2A2A28: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A2A30: movss [0x004066C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4066C0u, ctx.xmm[0].u32[0]);
	// 0x2A2A38: ret
	return;
}

void sub_2A2A40(X86Context& ctx, uint8_t* base) {
	// 0x2A2A40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A2A48: movss [0x0056FE78], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE78u, ctx.xmm[0].u32[0]);
	// 0x2A2A50: ret
	return;
}

void sub_2A2A60(X86Context& ctx, uint8_t* base) {
	// 0x2A2A60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A2A68: movss [0x0056FE94], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE94u, ctx.xmm[0].u32[0]);
	// 0x2A2A70: ret
	return;
}

void sub_2A2A80(X86Context& ctx, uint8_t* base) {
	// 0x2A2A80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A2A88: movss [0x0056FE6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE6Cu, ctx.xmm[0].u32[0]);
	// 0x2A2A90: ret
	return;
}

void sub_2A2AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A2AA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A2AA8: movss [0x0056FE24], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE24u, ctx.xmm[0].u32[0]);
	// 0x2A2AB0: ret
	return;
}

void sub_2A2AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A2AC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A2AC8: movss [0x0056FE7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE7Cu, ctx.xmm[0].u32[0]);
	// 0x2A2AD0: ret
	return;
}

void sub_2A2AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A2AE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A2AE8: movss [0x0056FE40], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE40u, ctx.xmm[0].u32[0]);
	// 0x2A2AF0: ret
	return;
}

void sub_2A2B00(X86Context& ctx, uint8_t* base) {
	// 0x2A2B00: movss xmm0, dword ptr [0x0056FE7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE7Cu);
	// 0x2A2B08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A2B10: movss [0x0056FEB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEB4u, ctx.xmm[0].u32[0]);
	// 0x2A2B18: ret
	return;
}

void sub_2A2B20(X86Context& ctx, uint8_t* base) {
	// 0x2A2B20: movss xmm0, dword ptr [0x0056FE40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE40u);
	// 0x2A2B28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A2B30: movss [0x0056FE9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE9Cu, ctx.xmm[0].u32[0]);
	// 0x2A2B38: ret
	return;
}

void sub_2A2B40(X86Context& ctx, uint8_t* base) {
	// 0x2A2B40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A2B48: movss [0x0056FECC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FECCu, ctx.xmm[0].u32[0]);
	// 0x2A2B50: ret
	return;
}

void sub_2A2B60(X86Context& ctx, uint8_t* base) {
	// 0x2A2B60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A2B68: movss [0x0056FEB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEB8u, ctx.xmm[0].u32[0]);
	// 0x2A2B70: ret
	return;
}

void sub_2A2B80(X86Context& ctx, uint8_t* base) {
	// 0x2A2B80: movss xmm0, dword ptr [0x0056FEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEB8u);
	// 0x2A2B88: movss [0x0056FEC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEC8u, ctx.xmm[0].u32[0]);
	// 0x2A2B90: ret
	return;
}

void sub_2A2BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A2BA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A2BA8: movss [0x0056FE2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE2Cu, ctx.xmm[0].u32[0]);
	// 0x2A2BB0: ret
	return;
}

void sub_2A2BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A2BC0: movss xmm0, dword ptr [0x0056FE40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE40u);
	// 0x2A2BC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A2BD0: movss [0x0056FEC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEC0u, ctx.xmm[0].u32[0]);
	// 0x2A2BD8: ret
	return;
}

void sub_2A2BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A2BE0: movss xmm0, dword ptr [0x0056FE40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE40u);
	// 0x2A2BE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A2BF0: movss [0x0056FE68], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE68u, ctx.xmm[0].u32[0]);
	// 0x2A2BF8: ret
	return;
}

void sub_2A2C00(X86Context& ctx, uint8_t* base) {
	// 0x2A2C00: movss xmm0, dword ptr [0x0056FE40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE40u);
	// 0x2A2C08: subss xmm0, [0x0056FE68]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FE68u);
	// 0x2A2C10: movss [0x0056FE48], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE48u, ctx.xmm[0].u32[0]);
	// 0x2A2C18: ret
	return;
}

void sub_2A2C20(X86Context& ctx, uint8_t* base) {
	// 0x2A2C20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A2C28: movss [0x0056FE90], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE90u, ctx.xmm[0].u32[0]);
	// 0x2A2C30: ret
	return;
}

void sub_2A2C40(X86Context& ctx, uint8_t* base) {
	// 0x2A2C40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A2C48: movss [0x0056FE44], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE44u, ctx.xmm[0].u32[0]);
	// 0x2A2C50: ret
	return;
}

void sub_2A2C60(X86Context& ctx, uint8_t* base) {
	// 0x2A2C60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A2C68: movss [0x0056FE54], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE54u, ctx.xmm[0].u32[0]);
	// 0x2A2C70: ret
	return;
}

void sub_2A2C80(X86Context& ctx, uint8_t* base) {
	// 0x2A2C80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A2C88: movss [0x0056FEA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEA8u, ctx.xmm[0].u32[0]);
	// 0x2A2C90: ret
	return;
}

void sub_2A2CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A2CA0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A2CA8: movss [0x0056FE8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE8Cu, ctx.xmm[0].u32[0]);
	// 0x2A2CB0: ret
	return;
}

void sub_2A2CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A2CC0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A2CC8: movss [0x0056FE3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE3Cu, ctx.xmm[0].u32[0]);
	// 0x2A2CD0: ret
	return;
}

void sub_2A2CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A2CE0: movss xmm0, dword ptr [0x0056FE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE54u);
	// 0x2A2CE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A2CF0: movss [0x0056FE30], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE30u, ctx.xmm[0].u32[0]);
	// 0x2A2CF8: ret
	return;
}

void sub_2A2D00(X86Context& ctx, uint8_t* base) {
	// 0x2A2D00: movss xmm0, dword ptr [0x0056FEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEA8u);
	// 0x2A2D08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A2D10: movss [0x0056FE74], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE74u, ctx.xmm[0].u32[0]);
	// 0x2A2D18: ret
	return;
}

void sub_2A2D20(X86Context& ctx, uint8_t* base) {
	// 0x2A2D20: movss xmm0, dword ptr [0x0056FE30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE30u);
	// 0x2A2D28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A2D30: movss [0x0056FE84], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE84u, ctx.xmm[0].u32[0]);
	// 0x2A2D38: ret
	return;
}

void sub_2A2D40(X86Context& ctx, uint8_t* base) {
	// 0x2A2D40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A2D48: movss [0x0056FE28], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE28u, ctx.xmm[0].u32[0]);
	// 0x2A2D50: ret
	return;
}

void sub_2A2D60(X86Context& ctx, uint8_t* base) {
	// 0x2A2D60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A2D68: movss [0x0056FE58], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE58u, ctx.xmm[0].u32[0]);
	// 0x2A2D70: ret
	return;
}

void sub_2A2D80(X86Context& ctx, uint8_t* base) {
	// 0x2A2D80: movss xmm0, dword ptr [0x0056FE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE54u);
	// 0x2A2D88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A2D90: movss [0x0056FE64], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE64u, ctx.xmm[0].u32[0]);
	// 0x2A2D98: ret
	return;
}

void sub_2A2DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A2DA0: movss xmm0, dword ptr [0x0056FEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEA8u);
	// 0x2A2DA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A2DB0: movss [0x0056FEAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEACu, ctx.xmm[0].u32[0]);
	// 0x2A2DB8: ret
	return;
}

void sub_2A2DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A2DC0: movss xmm0, dword ptr [0x0056FE64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE64u);
	// 0x2A2DC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2DD0: movss [0x0056FE98], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE98u, ctx.xmm[0].u32[0]);
	// 0x2A2DD8: ret
	return;
}

void sub_2A2DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A2DE0: movss xmm0, dword ptr [0x0056FEAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEACu);
	// 0x2A2DE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2DF0: movss [0x0056FEBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEBCu, ctx.xmm[0].u32[0]);
	// 0x2A2DF8: ret
	return;
}

void sub_2A2E00(X86Context& ctx, uint8_t* base) {
	// 0x2A2E00: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A2E08: movss [0x0056FE34], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE34u, ctx.xmm[0].u32[0]);
	// 0x2A2E10: ret
	return;
}

void sub_2A2E20(X86Context& ctx, uint8_t* base) {
	// 0x2A2E20: movss xmm0, dword ptr [0x0056FE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE54u);
	// 0x2A2E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2E30: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A2E38: movss [0x0056FEA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEA4u, ctx.xmm[0].u32[0]);
	// 0x2A2E40: ret
	return;
}

void sub_2A2E50(X86Context& ctx, uint8_t* base) {
	// 0x2A2E50: movss xmm0, dword ptr [0x0056FEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEA8u);
	// 0x2A2E58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2E60: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A2E68: movss [0x0056FE4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE4Cu, ctx.xmm[0].u32[0]);
	// 0x2A2E70: ret
	return;
}

void sub_2A2E80(X86Context& ctx, uint8_t* base) {
	// 0x2A2E80: movss xmm0, dword ptr [0x0056FE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE54u);
	// 0x2A2E88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2E90: movss [0x0056FE50], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE50u, ctx.xmm[0].u32[0]);
	// 0x2A2E98: ret
	return;
}

void sub_2A2EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A2EA0: movss xmm0, dword ptr [0x0056FEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEA8u);
	// 0x2A2EA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A2EB0: movss [0x0056FEB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEB0u, ctx.xmm[0].u32[0]);
	// 0x2A2EB8: ret
	return;
}

void sub_2A2EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A2EC0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A2EC8: movss [0x0056FE38], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE38u, ctx.xmm[0].u32[0]);
	// 0x2A2ED0: ret
	return;
}

void sub_2A2EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A2EE0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A2EE8: movss [0x0056FE60], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE60u, ctx.xmm[0].u32[0]);
	// 0x2A2EF0: ret
	return;
}

void sub_2A2F00(X86Context& ctx, uint8_t* base) {
	// 0x2A2F00: movss xmm0, dword ptr [0x0056FE38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE38u);
	// 0x2A2F08: movss [0x0056FEC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEC4u, ctx.xmm[0].u32[0]);
	// 0x2A2F10: ret
	return;
}

void sub_2A2F20(X86Context& ctx, uint8_t* base) {
	// 0x2A2F20: movss xmm0, dword ptr [0x0056FEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEA8u);
	// 0x2A2F28: subss xmm0, [0x0056FE38]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FE38u);
	// 0x2A2F30: movss [0x0056FE88], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE88u, ctx.xmm[0].u32[0]);
	// 0x2A2F38: ret
	return;
}

void sub_2A2F40(X86Context& ctx, uint8_t* base) {
	// 0x2A2F40: movss xmm0, dword ptr [0x0056FE88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE88u);
	// 0x2A2F48: subss xmm0, [0x0056FE60]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FE60u);
	// 0x2A2F50: movss [0x0056FE80], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE80u, ctx.xmm[0].u32[0]);
	// 0x2A2F58: ret
	return;
}

void sub_2A2F60(X86Context& ctx, uint8_t* base) {
	// 0x2A2F60: movss xmm0, dword ptr [0x0056FEB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEB0u);
	// 0x2A2F68: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A2F70: movss [0x0056FE70], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE70u, ctx.xmm[0].u32[0]);
	// 0x2A2F78: ret
	return;
}

void sub_2A2F80(X86Context& ctx, uint8_t* base) {
	// 0x2A2F80: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A2F88: movss [0x0056FE5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE5Cu, ctx.xmm[0].u32[0]);
	// 0x2A2F90: ret
	return;
}

void sub_2A2FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A2FA0: movss xmm0, dword ptr [0x0056FE70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FE70u);
	// 0x2A2FA8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A2FB0: movss [0x0056FEA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEA0u, ctx.xmm[0].u32[0]);
	// 0x2A2FB8: ret
	return;
}

void sub_2A2FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A2FC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A2FC8: movss [0x0056FF28], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF28u, ctx.xmm[0].u32[0]);
	// 0x2A2FD0: ret
	return;
}

void sub_2A2FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A2FE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A2FE8: movss [0x0056FF44], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF44u, ctx.xmm[0].u32[0]);
	// 0x2A2FF0: ret
	return;
}

void sub_2A3000(X86Context& ctx, uint8_t* base) {
	// 0x2A3000: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A3008: movss [0x0056FF1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF1Cu, ctx.xmm[0].u32[0]);
	// 0x2A3010: ret
	return;
}

void sub_2A3020(X86Context& ctx, uint8_t* base) {
	// 0x2A3020: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A3028: movss [0x0056FED0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FED0u, ctx.xmm[0].u32[0]);
	// 0x2A3030: ret
	return;
}

void sub_2A3040(X86Context& ctx, uint8_t* base) {
	// 0x2A3040: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A3048: movss [0x0056FF2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF2Cu, ctx.xmm[0].u32[0]);
	// 0x2A3050: ret
	return;
}

void sub_2A3060(X86Context& ctx, uint8_t* base) {
	// 0x2A3060: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A3068: movss [0x0056FEEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEECu, ctx.xmm[0].u32[0]);
	// 0x2A3070: ret
	return;
}

void sub_2A3080(X86Context& ctx, uint8_t* base) {
	// 0x2A3080: movss xmm0, dword ptr [0x0056FF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF2Cu);
	// 0x2A3088: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3090: movss [0x0056FF84], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF84u, ctx.xmm[0].u32[0]);
	// 0x2A3098: ret
	return;
}

void sub_2A30A0(X86Context& ctx, uint8_t* base) {
	// 0x2A30A0: movss xmm0, dword ptr [0x0056FEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEECu);
	// 0x2A30A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A30B0: movss [0x0056FF4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF4Cu, ctx.xmm[0].u32[0]);
	// 0x2A30B8: ret
	return;
}

void sub_2A30C0(X86Context& ctx, uint8_t* base) {
	// 0x2A30C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A30C8: movss [0x0056FF9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF9Cu, ctx.xmm[0].u32[0]);
	// 0x2A30D0: ret
	return;
}

void sub_2A30E0(X86Context& ctx, uint8_t* base) {
	// 0x2A30E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A30E8: movss [0x0056FF88], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF88u, ctx.xmm[0].u32[0]);
	// 0x2A30F0: ret
	return;
}

void sub_2A3100(X86Context& ctx, uint8_t* base) {
	// 0x2A3100: movss xmm0, dword ptr [0x0056FF88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF88u);
	// 0x2A3108: movss [0x0056FF98], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF98u, ctx.xmm[0].u32[0]);
	// 0x2A3110: ret
	return;
}

void sub_2A3120(X86Context& ctx, uint8_t* base) {
	// 0x2A3120: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A3128: movss [0x0056FED8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FED8u, ctx.xmm[0].u32[0]);
	// 0x2A3130: ret
	return;
}

void sub_2A3140(X86Context& ctx, uint8_t* base) {
	// 0x2A3140: movss xmm0, dword ptr [0x0056FEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEECu);
	// 0x2A3148: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A3150: movss [0x0056FF90], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF90u, ctx.xmm[0].u32[0]);
	// 0x2A3158: ret
	return;
}

void sub_2A3160(X86Context& ctx, uint8_t* base) {
	// 0x2A3160: movss xmm0, dword ptr [0x0056FEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEECu);
	// 0x2A3168: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A3170: movss [0x0056FF18], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF18u, ctx.xmm[0].u32[0]);
	// 0x2A3178: ret
	return;
}

void sub_2A3180(X86Context& ctx, uint8_t* base) {
	// 0x2A3180: movss xmm0, dword ptr [0x0056FEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEECu);
	// 0x2A3188: subss xmm0, [0x0056FF18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FF18u);
	// 0x2A3190: movss [0x0056FEF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEF4u, ctx.xmm[0].u32[0]);
	// 0x2A3198: ret
	return;
}

void sub_2A31A0(X86Context& ctx, uint8_t* base) {
	// 0x2A31A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A31A8: movss [0x0056FF40], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF40u, ctx.xmm[0].u32[0]);
	// 0x2A31B0: ret
	return;
}

void sub_2A31C0(X86Context& ctx, uint8_t* base) {
	// 0x2A31C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A31C8: movss [0x0056FEF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEF0u, ctx.xmm[0].u32[0]);
	// 0x2A31D0: ret
	return;
}

void sub_2A31E0(X86Context& ctx, uint8_t* base) {
	// 0x2A31E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A31E8: movss [0x0056FF04], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF04u, ctx.xmm[0].u32[0]);
	// 0x2A31F0: ret
	return;
}

void sub_2A3200(X86Context& ctx, uint8_t* base) {
	// 0x2A3200: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A3208: movss [0x0056FF74], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF74u, ctx.xmm[0].u32[0]);
	// 0x2A3210: ret
	return;
}

void sub_2A3220(X86Context& ctx, uint8_t* base) {
	// 0x2A3220: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A3228: movss [0x0056FF3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF3Cu, ctx.xmm[0].u32[0]);
	// 0x2A3230: ret
	return;
}

void sub_2A3240(X86Context& ctx, uint8_t* base) {
	// 0x2A3240: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A3248: movss [0x0056FEE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEE8u, ctx.xmm[0].u32[0]);
	// 0x2A3250: ret
	return;
}

void sub_2A3260(X86Context& ctx, uint8_t* base) {
	// 0x2A3260: movss xmm0, dword ptr [0x0056FF04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF04u);
	// 0x2A3268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3270: movss [0x0056FEDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEDCu, ctx.xmm[0].u32[0]);
	// 0x2A3278: ret
	return;
}

void sub_2A3280(X86Context& ctx, uint8_t* base) {
	// 0x2A3280: movss xmm0, dword ptr [0x0056FF74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF74u);
	// 0x2A3288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A3290: movss [0x0056FF24], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF24u, ctx.xmm[0].u32[0]);
	// 0x2A3298: ret
	return;
}

void sub_2A32A0(X86Context& ctx, uint8_t* base) {
	// 0x2A32A0: movss xmm0, dword ptr [0x0056FEDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEDCu);
	// 0x2A32A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A32B0: movss [0x0056FF34], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF34u, ctx.xmm[0].u32[0]);
	// 0x2A32B8: ret
	return;
}

void sub_2A32C0(X86Context& ctx, uint8_t* base) {
	// 0x2A32C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A32C8: movss [0x0056FED4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FED4u, ctx.xmm[0].u32[0]);
	// 0x2A32D0: ret
	return;
}

void sub_2A32E0(X86Context& ctx, uint8_t* base) {
	// 0x2A32E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A32E8: movss [0x0056FF08], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF08u, ctx.xmm[0].u32[0]);
	// 0x2A32F0: ret
	return;
}

void sub_2A3300(X86Context& ctx, uint8_t* base) {
	// 0x2A3300: movss xmm0, dword ptr [0x0056FF04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF04u);
	// 0x2A3308: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A3310: movss [0x0056FF14], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF14u, ctx.xmm[0].u32[0]);
	// 0x2A3318: ret
	return;
}

void sub_2A3320(X86Context& ctx, uint8_t* base) {
	// 0x2A3320: movss xmm0, dword ptr [0x0056FF74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF74u);
	// 0x2A3328: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A3330: movss [0x0056FF7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF7Cu, ctx.xmm[0].u32[0]);
	// 0x2A3338: ret
	return;
}

void sub_2A3340(X86Context& ctx, uint8_t* base) {
	// 0x2A3340: movss xmm0, dword ptr [0x0056FF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF14u);
	// 0x2A3348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3350: movss [0x0056FF48], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF48u, ctx.xmm[0].u32[0]);
	// 0x2A3358: ret
	return;
}

void sub_2A3360(X86Context& ctx, uint8_t* base) {
	// 0x2A3360: movss xmm0, dword ptr [0x0056FF7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF7Cu);
	// 0x2A3368: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3370: movss [0x0056FF8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF8Cu, ctx.xmm[0].u32[0]);
	// 0x2A3378: ret
	return;
}

void sub_2A3380(X86Context& ctx, uint8_t* base) {
	// 0x2A3380: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A3388: movss [0x0056FEE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEE0u, ctx.xmm[0].u32[0]);
	// 0x2A3390: ret
	return;
}

void sub_2A33A0(X86Context& ctx, uint8_t* base) {
	// 0x2A33A0: movss xmm0, dword ptr [0x0056FF04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF04u);
	// 0x2A33A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A33B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A33B8: movss [0x0056FF70], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF70u, ctx.xmm[0].u32[0]);
	// 0x2A33C0: ret
	return;
}

void sub_2A33D0(X86Context& ctx, uint8_t* base) {
	// 0x2A33D0: movss xmm0, dword ptr [0x0056FF74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF74u);
	// 0x2A33D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A33E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A33E8: movss [0x0056FEF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEF8u, ctx.xmm[0].u32[0]);
	// 0x2A33F0: ret
	return;
}

void sub_2A3400(X86Context& ctx, uint8_t* base) {
	// 0x2A3400: movss xmm0, dword ptr [0x0056FF04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF04u);
	// 0x2A3408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3410: movss [0x0056FEFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEFCu, ctx.xmm[0].u32[0]);
	// 0x2A3418: ret
	return;
}

void sub_2A3420(X86Context& ctx, uint8_t* base) {
	// 0x2A3420: movss xmm0, dword ptr [0x0056FF74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF74u);
	// 0x2A3428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3430: movss [0x0056FF80], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF80u, ctx.xmm[0].u32[0]);
	// 0x2A3438: ret
	return;
}

void sub_2A3440(X86Context& ctx, uint8_t* base) {
	// 0x2A3440: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A3448: movss [0x0056FEE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FEE4u, ctx.xmm[0].u32[0]);
	// 0x2A3450: ret
	return;
}

void sub_2A3460(X86Context& ctx, uint8_t* base) {
	// 0x2A3460: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A3468: movss [0x0056FF10], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF10u, ctx.xmm[0].u32[0]);
	// 0x2A3470: ret
	return;
}

void sub_2A3480(X86Context& ctx, uint8_t* base) {
	// 0x2A3480: movss xmm0, dword ptr [0x0056FEE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FEE4u);
	// 0x2A3488: movss [0x0056FF94], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF94u, ctx.xmm[0].u32[0]);
	// 0x2A3490: ret
	return;
}

void sub_2A34A0(X86Context& ctx, uint8_t* base) {
	// 0x2A34A0: movss xmm0, dword ptr [0x0056FF74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF74u);
	// 0x2A34A8: subss xmm0, [0x0056FEE4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FEE4u);
	// 0x2A34B0: movss [0x0056FF38], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF38u, ctx.xmm[0].u32[0]);
	// 0x2A34B8: ret
	return;
}

void sub_2A34C0(X86Context& ctx, uint8_t* base) {
	// 0x2A34C0: movss xmm0, dword ptr [0x0056FF38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF38u);
	// 0x2A34C8: subss xmm0, [0x0056FF10]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FF10u);
	// 0x2A34D0: movss [0x0056FF30], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF30u, ctx.xmm[0].u32[0]);
	// 0x2A34D8: ret
	return;
}

void sub_2A34E0(X86Context& ctx, uint8_t* base) {
	// 0x2A34E0: movss xmm0, dword ptr [0x0056FF80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF80u);
	// 0x2A34E8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A34F0: movss [0x0056FF20], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF20u, ctx.xmm[0].u32[0]);
	// 0x2A34F8: ret
	return;
}

void sub_2A3500(X86Context& ctx, uint8_t* base) {
	// 0x2A3500: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A3508: movss [0x0056FF0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF0Cu, ctx.xmm[0].u32[0]);
	// 0x2A3510: ret
	return;
}

void sub_2A3520(X86Context& ctx, uint8_t* base) {
	// 0x2A3520: movss xmm0, dword ptr [0x0056FF20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FF20u);
	// 0x2A3528: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A3530: movss [0x0056FF50], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF50u, ctx.xmm[0].u32[0]);
	// 0x2A3538: ret
	return;
}

void sub_2A3540(X86Context& ctx, uint8_t* base) {
	// 0x2A3540: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A3548: movss [0x0056FF78], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF78u, ctx.xmm[0].u32[0]);
	// 0x2A3550: ret
	return;
}

void sub_2A3560(X86Context& ctx, uint8_t* base) {
	// 0x2A3560: movss xmm0, dword ptr [0x003B2070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2070u);
	// 0x2A3568: movss [0x0056FF00], xmm0
	X86_MEM_WRITE_u32(base, 0x56FF00u, ctx.xmm[0].u32[0]);
	// 0x2A3570: ret
	return;
}

void sub_2A3580(X86Context& ctx, uint8_t* base) {
	// 0x2A3580: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A3588: movss [0x00570000], xmm0
	X86_MEM_WRITE_u32(base, 0x570000u, ctx.xmm[0].u32[0]);
	// 0x2A3590: ret
	return;
}

void sub_2A35A0(X86Context& ctx, uint8_t* base) {
	// 0x2A35A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A35A8: movss [0x00570020], xmm0
	X86_MEM_WRITE_u32(base, 0x570020u, ctx.xmm[0].u32[0]);
	// 0x2A35B0: ret
	return;
}

void sub_2A35C0(X86Context& ctx, uint8_t* base) {
	// 0x2A35C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A35C8: movss [0x0056FFF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFF4u, ctx.xmm[0].u32[0]);
	// 0x2A35D0: ret
	return;
}

void sub_2A35E0(X86Context& ctx, uint8_t* base) {
	// 0x2A35E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A35E8: movss [0x0056FFA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFA0u, ctx.xmm[0].u32[0]);
	// 0x2A35F0: ret
	return;
}

void sub_2A3600(X86Context& ctx, uint8_t* base) {
	// 0x2A3600: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A3608: movss [0x00570004], xmm0
	X86_MEM_WRITE_u32(base, 0x570004u, ctx.xmm[0].u32[0]);
	// 0x2A3610: ret
	return;
}

void sub_2A3620(X86Context& ctx, uint8_t* base) {
	// 0x2A3620: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A3628: movss [0x0056FFBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFBCu, ctx.xmm[0].u32[0]);
	// 0x2A3630: ret
	return;
}

void sub_2A3640(X86Context& ctx, uint8_t* base) {
	// 0x2A3640: movss xmm0, dword ptr [0x00570004]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570004u);
	// 0x2A3648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3650: movss [0x00570040], xmm0
	X86_MEM_WRITE_u32(base, 0x570040u, ctx.xmm[0].u32[0]);
	// 0x2A3658: ret
	return;
}

void sub_2A3660(X86Context& ctx, uint8_t* base) {
	// 0x2A3660: movss xmm0, dword ptr [0x0056FFBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFBCu);
	// 0x2A3668: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A3670: movss [0x00570028], xmm0
	X86_MEM_WRITE_u32(base, 0x570028u, ctx.xmm[0].u32[0]);
	// 0x2A3678: ret
	return;
}

void sub_2A3680(X86Context& ctx, uint8_t* base) {
	// 0x2A3680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A3688: movss [0x00570060], xmm0
	X86_MEM_WRITE_u32(base, 0x570060u, ctx.xmm[0].u32[0]);
	// 0x2A3690: ret
	return;
}

void sub_2A36A0(X86Context& ctx, uint8_t* base) {
	// 0x2A36A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A36A8: movss [0x00570044], xmm0
	X86_MEM_WRITE_u32(base, 0x570044u, ctx.xmm[0].u32[0]);
	// 0x2A36B0: ret
	return;
}

void sub_2A36C0(X86Context& ctx, uint8_t* base) {
	// 0x2A36C0: movss xmm0, dword ptr [0x00570044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570044u);
	// 0x2A36C8: movss [0x00570058], xmm0
	X86_MEM_WRITE_u32(base, 0x570058u, ctx.xmm[0].u32[0]);
	// 0x2A36D0: ret
	return;
}

void sub_2A36E0(X86Context& ctx, uint8_t* base) {
	// 0x2A36E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A36E8: movss [0x0056FFA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFA8u, ctx.xmm[0].u32[0]);
	// 0x2A36F0: ret
	return;
}

void sub_2A3700(X86Context& ctx, uint8_t* base) {
	// 0x2A3700: movss xmm0, dword ptr [0x0056FFBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFBCu);
	// 0x2A3708: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A3710: movss [0x00570050], xmm0
	X86_MEM_WRITE_u32(base, 0x570050u, ctx.xmm[0].u32[0]);
	// 0x2A3718: ret
	return;
}

void sub_2A3720(X86Context& ctx, uint8_t* base) {
	// 0x2A3720: movss xmm0, dword ptr [0x0056FFBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFBCu);
	// 0x2A3728: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A3730: movss [0x0056FFF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFF0u, ctx.xmm[0].u32[0]);
	// 0x2A3738: ret
	return;
}

void sub_2A3740(X86Context& ctx, uint8_t* base) {
	// 0x2A3740: movss xmm0, dword ptr [0x0056FFBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFBCu);
	// 0x2A3748: subss xmm0, [0x0056FFF0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FFF0u);
	// 0x2A3750: movss [0x0056FFC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFC8u, ctx.xmm[0].u32[0]);
	// 0x2A3758: ret
	return;
}

void sub_2A3760(X86Context& ctx, uint8_t* base) {
	// 0x2A3760: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A3768: movss [0x0057001C], xmm0
	X86_MEM_WRITE_u32(base, 0x57001Cu, ctx.xmm[0].u32[0]);
	// 0x2A3770: ret
	return;
}

void sub_2A3780(X86Context& ctx, uint8_t* base) {
	// 0x2A3780: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A3788: movss [0x0056FFC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFC0u, ctx.xmm[0].u32[0]);
	// 0x2A3790: ret
	return;
}

void sub_2A37A0(X86Context& ctx, uint8_t* base) {
	// 0x2A37A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A37A8: movss [0x0056FFDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFDCu, ctx.xmm[0].u32[0]);
	// 0x2A37B0: ret
	return;
}

void sub_2A37C0(X86Context& ctx, uint8_t* base) {
	// 0x2A37C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A37C8: movss [0x00570034], xmm0
	X86_MEM_WRITE_u32(base, 0x570034u, ctx.xmm[0].u32[0]);
	// 0x2A37D0: ret
	return;
}

void sub_2A37E0(X86Context& ctx, uint8_t* base) {
	// 0x2A37E0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A37E8: movss [0x00570018], xmm0
	X86_MEM_WRITE_u32(base, 0x570018u, ctx.xmm[0].u32[0]);
	// 0x2A37F0: ret
	return;
}

void sub_2A3800(X86Context& ctx, uint8_t* base) {
	// 0x2A3800: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A3808: movss [0x0056FFB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFB8u, ctx.xmm[0].u32[0]);
	// 0x2A3810: ret
	return;
}

void sub_2A3820(X86Context& ctx, uint8_t* base) {
	// 0x2A3820: movss xmm0, dword ptr [0x0056FFDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFDCu);
	// 0x2A3828: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3830: movss [0x0056FFAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFACu, ctx.xmm[0].u32[0]);
	// 0x2A3838: ret
	return;
}

void sub_2A3840(X86Context& ctx, uint8_t* base) {
	// 0x2A3840: movss xmm0, dword ptr [0x00570034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570034u);
	// 0x2A3848: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A3850: movss [0x0056FFFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFFCu, ctx.xmm[0].u32[0]);
	// 0x2A3858: ret
	return;
}

void sub_2A3860(X86Context& ctx, uint8_t* base) {
	// 0x2A3860: movss xmm0, dword ptr [0x0056FFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFACu);
	// 0x2A3868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3870: movss [0x0057000C], xmm0
	X86_MEM_WRITE_u32(base, 0x57000Cu, ctx.xmm[0].u32[0]);
	// 0x2A3878: ret
	return;
}

void sub_2A3880(X86Context& ctx, uint8_t* base) {
	// 0x2A3880: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A3888: movss [0x0056FFA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFA4u, ctx.xmm[0].u32[0]);
	// 0x2A3890: ret
	return;
}

void sub_2A38A0(X86Context& ctx, uint8_t* base) {
	// 0x2A38A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A38A8: movss [0x0056FFE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFE0u, ctx.xmm[0].u32[0]);
	// 0x2A38B0: ret
	return;
}

void sub_2A38C0(X86Context& ctx, uint8_t* base) {
	// 0x2A38C0: movss xmm0, dword ptr [0x0056FFDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFDCu);
	// 0x2A38C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A38D0: movss [0x0056FFEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFECu, ctx.xmm[0].u32[0]);
	// 0x2A38D8: ret
	return;
}

void sub_2A38E0(X86Context& ctx, uint8_t* base) {
	// 0x2A38E0: movss xmm0, dword ptr [0x00570034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570034u);
	// 0x2A38E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A38F0: movss [0x00570038], xmm0
	X86_MEM_WRITE_u32(base, 0x570038u, ctx.xmm[0].u32[0]);
	// 0x2A38F8: ret
	return;
}

void sub_2A3900(X86Context& ctx, uint8_t* base) {
	// 0x2A3900: movss xmm0, dword ptr [0x0056FFEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFECu);
	// 0x2A3908: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3910: movss [0x00570024], xmm0
	X86_MEM_WRITE_u32(base, 0x570024u, ctx.xmm[0].u32[0]);
	// 0x2A3918: ret
	return;
}

void sub_2A3920(X86Context& ctx, uint8_t* base) {
	// 0x2A3920: movss xmm0, dword ptr [0x00570038]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570038u);
	// 0x2A3928: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3930: movss [0x00570048], xmm0
	X86_MEM_WRITE_u32(base, 0x570048u, ctx.xmm[0].u32[0]);
	// 0x2A3938: ret
	return;
}

void sub_2A3940(X86Context& ctx, uint8_t* base) {
	// 0x2A3940: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A3948: movss [0x0056FFB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFB0u, ctx.xmm[0].u32[0]);
	// 0x2A3950: ret
	return;
}

void sub_2A3960(X86Context& ctx, uint8_t* base) {
	// 0x2A3960: movss xmm0, dword ptr [0x0056FFDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFDCu);
	// 0x2A3968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3970: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A3978: movss [0x00570030], xmm0
	X86_MEM_WRITE_u32(base, 0x570030u, ctx.xmm[0].u32[0]);
	// 0x2A3980: ret
	return;
}

void sub_2A3990(X86Context& ctx, uint8_t* base) {
	// 0x2A3990: movss xmm0, dword ptr [0x00570034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570034u);
	// 0x2A3998: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A39A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A39A8: movss [0x0056FFD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFD0u, ctx.xmm[0].u32[0]);
	// 0x2A39B0: ret
	return;
}

void sub_2A39C0(X86Context& ctx, uint8_t* base) {
	// 0x2A39C0: movss xmm0, dword ptr [0x0056FFDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFDCu);
	// 0x2A39C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A39D0: movss [0x0056FFD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFD4u, ctx.xmm[0].u32[0]);
	// 0x2A39D8: ret
	return;
}

void sub_2A39E0(X86Context& ctx, uint8_t* base) {
	// 0x2A39E0: movss xmm0, dword ptr [0x00570034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570034u);
	// 0x2A39E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A39F0: movss [0x0057003C], xmm0
	X86_MEM_WRITE_u32(base, 0x57003Cu, ctx.xmm[0].u32[0]);
	// 0x2A39F8: ret
	return;
}

void sub_2A3A00(X86Context& ctx, uint8_t* base) {
	// 0x2A3A00: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A3A08: movss [0x0056FFB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFB4u, ctx.xmm[0].u32[0]);
	// 0x2A3A10: ret
	return;
}

void sub_2A3A20(X86Context& ctx, uint8_t* base) {
	// 0x2A3A20: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A3A28: movss [0x0056FFE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFE8u, ctx.xmm[0].u32[0]);
	// 0x2A3A30: ret
	return;
}

void sub_2A3A40(X86Context& ctx, uint8_t* base) {
	// 0x2A3A40: movss xmm0, dword ptr [0x0056FFB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFB4u);
	// 0x2A3A48: movss [0x00570054], xmm0
	X86_MEM_WRITE_u32(base, 0x570054u, ctx.xmm[0].u32[0]);
	// 0x2A3A50: ret
	return;
}

void sub_2A3A60(X86Context& ctx, uint8_t* base) {
	// 0x2A3A60: movss xmm0, dword ptr [0x00570034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570034u);
	// 0x2A3A68: subss xmm0, [0x0056FFB4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FFB4u);
	// 0x2A3A70: movss [0x00570010], xmm0
	X86_MEM_WRITE_u32(base, 0x570010u, ctx.xmm[0].u32[0]);
	// 0x2A3A78: ret
	return;
}

void sub_2A3A80(X86Context& ctx, uint8_t* base) {
	// 0x2A3A80: movss xmm0, dword ptr [0x00570010]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570010u);
	// 0x2A3A88: subss xmm0, [0x0056FFE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FFE8u);
	// 0x2A3A90: movss [0x00570008], xmm0
	X86_MEM_WRITE_u32(base, 0x570008u, ctx.xmm[0].u32[0]);
	// 0x2A3A98: ret
	return;
}

void sub_2A3AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A3AA0: movss xmm0, dword ptr [0x0057003C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57003Cu);
	// 0x2A3AA8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A3AB0: movss [0x0056FFF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFF8u, ctx.xmm[0].u32[0]);
	// 0x2A3AB8: ret
	return;
}

void sub_2A3AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A3AC0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A3AC8: movss [0x0056FFE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFE4u, ctx.xmm[0].u32[0]);
	// 0x2A3AD0: ret
	return;
}

void sub_2A3AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A3AE0: movss xmm0, dword ptr [0x0056FFF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFF8u);
	// 0x2A3AE8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A3AF0: movss [0x0057002C], xmm0
	X86_MEM_WRITE_u32(base, 0x57002Cu, ctx.xmm[0].u32[0]);
	// 0x2A3AF8: ret
	return;
}

void sub_2A3B00(X86Context& ctx, uint8_t* base) {
	// 0x2A3B00: movss xmm0, dword ptr [0x003B203C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B203Cu);
	// 0x2A3B08: movss [0x00570064], xmm0
	X86_MEM_WRITE_u32(base, 0x570064u, ctx.xmm[0].u32[0]);
	// 0x2A3B10: ret
	return;
}

void sub_2A3B20(X86Context& ctx, uint8_t* base) {
	// 0x2A3B20: movss xmm0, dword ptr [0x00395BE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE0u);
	// 0x2A3B28: movss [0x0056FFD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFD8u, ctx.xmm[0].u32[0]);
	// 0x2A3B30: ret
	return;
}

void sub_2A3B40(X86Context& ctx, uint8_t* base) {
	// 0x2A3B40: movss xmm0, dword ptr [0x00395BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2A3B48: movss [0x0056FFCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFCCu, ctx.xmm[0].u32[0]);
	// 0x2A3B50: ret
	return;
}

void sub_2A3B60(X86Context& ctx, uint8_t* base) {
	// 0x2A3B60: movss xmm0, dword ptr [0x0056FFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFACu);
	// 0x2A3B68: subss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A3B70: movss [0x0056FFC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FFC4u, ctx.xmm[0].u32[0]);
	// 0x2A3B78: ret
	return;
}

void sub_2A3B80(X86Context& ctx, uint8_t* base) {
	// 0x2A3B80: movss xmm0, dword ptr [0x003B1C54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C54u);
	// 0x2A3B88: movss [0x0057004C], xmm0
	X86_MEM_WRITE_u32(base, 0x57004Cu, ctx.xmm[0].u32[0]);
	// 0x2A3B90: ret
	return;
}

void sub_2A3BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A3BA0: movss xmm0, dword ptr [0x0056FFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FFACu);
	// 0x2A3BA8: subss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A3BB0: movss [0x0057005C], xmm0
	X86_MEM_WRITE_u32(base, 0x57005Cu, ctx.xmm[0].u32[0]);
	// 0x2A3BB8: ret
	return;
}

void sub_2A3BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A3BC0: movss xmm0, dword ptr [0x00397540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397540u);
	// 0x2A3BC8: movss [0x00570014], xmm0
	X86_MEM_WRITE_u32(base, 0x570014u, ctx.xmm[0].u32[0]);
	// 0x2A3BD0: ret
	return;
}

void sub_2A3BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A3BE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A3BE8: movss [0x005700CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5700CCu, ctx.xmm[0].u32[0]);
	// 0x2A3BF0: ret
	return;
}

void sub_2A3C00(X86Context& ctx, uint8_t* base) {
	// 0x2A3C00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A3C08: movss [0x005700E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5700E8u, ctx.xmm[0].u32[0]);
	// 0x2A3C10: ret
	return;
}

void sub_2A3C20(X86Context& ctx, uint8_t* base) {
	// 0x2A3C20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A3C28: movss [0x005700C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5700C0u, ctx.xmm[0].u32[0]);
	// 0x2A3C30: ret
	return;
}

void sub_2A3C40(X86Context& ctx, uint8_t* base) {
	// 0x2A3C40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A3C48: movss [0x00570068], xmm0
	X86_MEM_WRITE_u32(base, 0x570068u, ctx.xmm[0].u32[0]);
	// 0x2A3C50: ret
	return;
}

void sub_2A3C60(X86Context& ctx, uint8_t* base) {
	// 0x2A3C60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A3C68: movss [0x005700D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5700D0u, ctx.xmm[0].u32[0]);
	// 0x2A3C70: ret
	return;
}

void sub_2A3C80(X86Context& ctx, uint8_t* base) {
	// 0x2A3C80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A3C88: movss [0x00570084], xmm0
	X86_MEM_WRITE_u32(base, 0x570084u, ctx.xmm[0].u32[0]);
	// 0x2A3C90: ret
	return;
}

void sub_2A3CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A3CA0: movss xmm0, dword ptr [0x005700D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700D0u);
	// 0x2A3CA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3CB0: movss [0x00570108], xmm0
	X86_MEM_WRITE_u32(base, 0x570108u, ctx.xmm[0].u32[0]);
	// 0x2A3CB8: ret
	return;
}

void sub_2A3CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A3CC0: movss xmm0, dword ptr [0x00570084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570084u);
	// 0x2A3CC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A3CD0: movss [0x005700F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5700F0u, ctx.xmm[0].u32[0]);
	// 0x2A3CD8: ret
	return;
}

void sub_2A3CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A3CE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A3CE8: movss [0x00570120], xmm0
	X86_MEM_WRITE_u32(base, 0x570120u, ctx.xmm[0].u32[0]);
	// 0x2A3CF0: ret
	return;
}

void sub_2A3D00(X86Context& ctx, uint8_t* base) {
	// 0x2A3D00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A3D08: movss [0x0057010C], xmm0
	X86_MEM_WRITE_u32(base, 0x57010Cu, ctx.xmm[0].u32[0]);
	// 0x2A3D10: ret
	return;
}

void sub_2A3D20(X86Context& ctx, uint8_t* base) {
	// 0x2A3D20: movss xmm0, dword ptr [0x0057010C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57010Cu);
	// 0x2A3D28: movss [0x0057011C], xmm0
	X86_MEM_WRITE_u32(base, 0x57011Cu, ctx.xmm[0].u32[0]);
	// 0x2A3D30: ret
	return;
}

void sub_2A3D40(X86Context& ctx, uint8_t* base) {
	// 0x2A3D40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A3D48: movss [0x00570070], xmm0
	X86_MEM_WRITE_u32(base, 0x570070u, ctx.xmm[0].u32[0]);
	// 0x2A3D50: ret
	return;
}

void sub_2A3D60(X86Context& ctx, uint8_t* base) {
	// 0x2A3D60: movss xmm0, dword ptr [0x00570084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570084u);
	// 0x2A3D68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A3D70: movss [0x00570114], xmm0
	X86_MEM_WRITE_u32(base, 0x570114u, ctx.xmm[0].u32[0]);
	// 0x2A3D78: ret
	return;
}

void sub_2A3D80(X86Context& ctx, uint8_t* base) {
	// 0x2A3D80: movss xmm0, dword ptr [0x00570084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570084u);
	// 0x2A3D88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A3D90: movss [0x005700BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5700BCu, ctx.xmm[0].u32[0]);
	// 0x2A3D98: ret
	return;
}

void sub_2A3DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A3DA0: movss xmm0, dword ptr [0x00570084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570084u);
	// 0x2A3DA8: subss xmm0, [0x005700BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5700BCu);
	// 0x2A3DB0: movss [0x0057009C], xmm0
	X86_MEM_WRITE_u32(base, 0x57009Cu, ctx.xmm[0].u32[0]);
	// 0x2A3DB8: ret
	return;
}

void sub_2A3DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A3DC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A3DC8: movss [0x005700E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5700E4u, ctx.xmm[0].u32[0]);
	// 0x2A3DD0: ret
	return;
}

void sub_2A3DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A3DE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A3DE8: movss [0x00570098], xmm0
	X86_MEM_WRITE_u32(base, 0x570098u, ctx.xmm[0].u32[0]);
	// 0x2A3DF0: ret
	return;
}

void sub_2A3E00(X86Context& ctx, uint8_t* base) {
	// 0x2A3E00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A3E08: movss [0x005700A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5700A8u, ctx.xmm[0].u32[0]);
	// 0x2A3E10: ret
	return;
}

void sub_2A3E20(X86Context& ctx, uint8_t* base) {
	// 0x2A3E20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A3E28: movss [0x005700FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5700FCu, ctx.xmm[0].u32[0]);
	// 0x2A3E30: ret
	return;
}

void sub_2A3E40(X86Context& ctx, uint8_t* base) {
	// 0x2A3E40: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A3E48: movss [0x005700E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5700E0u, ctx.xmm[0].u32[0]);
	// 0x2A3E50: ret
	return;
}

void sub_2A3E60(X86Context& ctx, uint8_t* base) {
	// 0x2A3E60: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A3E68: movss [0x00570080], xmm0
	X86_MEM_WRITE_u32(base, 0x570080u, ctx.xmm[0].u32[0]);
	// 0x2A3E70: ret
	return;
}

void sub_2A3E80(X86Context& ctx, uint8_t* base) {
	// 0x2A3E80: movss xmm0, dword ptr [0x005700A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700A8u);
	// 0x2A3E88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3E90: movss [0x00570074], xmm0
	X86_MEM_WRITE_u32(base, 0x570074u, ctx.xmm[0].u32[0]);
	// 0x2A3E98: ret
	return;
}

void sub_2A3EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A3EA0: movss xmm0, dword ptr [0x005700FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700FCu);
	// 0x2A3EA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A3EB0: movss [0x005700C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5700C8u, ctx.xmm[0].u32[0]);
	// 0x2A3EB8: ret
	return;
}

void sub_2A3EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A3EC0: movss xmm0, dword ptr [0x00570074]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570074u);
	// 0x2A3EC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A3ED0: movss [0x005700D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5700D8u, ctx.xmm[0].u32[0]);
	// 0x2A3ED8: ret
	return;
}

void sub_2A3EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A3EE0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A3EE8: movss [0x0057006C], xmm0
	X86_MEM_WRITE_u32(base, 0x57006Cu, ctx.xmm[0].u32[0]);
	// 0x2A3EF0: ret
	return;
}

void sub_2A3F00(X86Context& ctx, uint8_t* base) {
	// 0x2A3F00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A3F08: movss [0x005700AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5700ACu, ctx.xmm[0].u32[0]);
	// 0x2A3F10: ret
	return;
}

void sub_2A3F20(X86Context& ctx, uint8_t* base) {
	// 0x2A3F20: movss xmm0, dword ptr [0x005700A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700A8u);
	// 0x2A3F28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A3F30: movss [0x005700B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5700B8u, ctx.xmm[0].u32[0]);
	// 0x2A3F38: ret
	return;
}

void sub_2A3F40(X86Context& ctx, uint8_t* base) {
	// 0x2A3F40: movss xmm0, dword ptr [0x005700FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700FCu);
	// 0x2A3F48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A3F50: movss [0x00570100], xmm0
	X86_MEM_WRITE_u32(base, 0x570100u, ctx.xmm[0].u32[0]);
	// 0x2A3F58: ret
	return;
}

void sub_2A3F60(X86Context& ctx, uint8_t* base) {
	// 0x2A3F60: movss xmm0, dword ptr [0x005700B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700B8u);
	// 0x2A3F68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3F70: movss [0x005700EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5700ECu, ctx.xmm[0].u32[0]);
	// 0x2A3F78: ret
	return;
}

void sub_2A3F80(X86Context& ctx, uint8_t* base) {
	// 0x2A3F80: movss xmm0, dword ptr [0x00570100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570100u);
	// 0x2A3F88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3F90: movss [0x00570110], xmm0
	X86_MEM_WRITE_u32(base, 0x570110u, ctx.xmm[0].u32[0]);
	// 0x2A3F98: ret
	return;
}

void sub_2A3FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A3FA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A3FA8: movss [0x00570078], xmm0
	X86_MEM_WRITE_u32(base, 0x570078u, ctx.xmm[0].u32[0]);
	// 0x2A3FB0: ret
	return;
}

void sub_2A3FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A3FC0: movss xmm0, dword ptr [0x005700A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700A8u);
	// 0x2A3FC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A3FD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A3FD8: movss [0x005700F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5700F8u, ctx.xmm[0].u32[0]);
	// 0x2A3FE0: ret
	return;
}

void sub_2A3FF0(X86Context& ctx, uint8_t* base) {
	// 0x2A3FF0: movss xmm0, dword ptr [0x005700FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700FCu);
	// 0x2A3FF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4000: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A4008: movss [0x005700A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5700A0u, ctx.xmm[0].u32[0]);
	// 0x2A4010: ret
	return;
}

void sub_2A4020(X86Context& ctx, uint8_t* base) {
	// 0x2A4020: movss xmm0, dword ptr [0x005700A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700A8u);
	// 0x2A4028: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4030: movss [0x005700A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5700A4u, ctx.xmm[0].u32[0]);
	// 0x2A4038: ret
	return;
}

void sub_2A4040(X86Context& ctx, uint8_t* base) {
	// 0x2A4040: movss xmm0, dword ptr [0x005700FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700FCu);
	// 0x2A4048: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4050: movss [0x00570104], xmm0
	X86_MEM_WRITE_u32(base, 0x570104u, ctx.xmm[0].u32[0]);
	// 0x2A4058: ret
	return;
}

void sub_2A4060(X86Context& ctx, uint8_t* base) {
	// 0x2A4060: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A4068: movss [0x0057007C], xmm0
	X86_MEM_WRITE_u32(base, 0x57007Cu, ctx.xmm[0].u32[0]);
	// 0x2A4070: ret
	return;
}

void sub_2A4080(X86Context& ctx, uint8_t* base) {
	// 0x2A4080: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A4088: movss [0x005700B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5700B4u, ctx.xmm[0].u32[0]);
	// 0x2A4090: ret
	return;
}

void sub_2A40A0(X86Context& ctx, uint8_t* base) {
	// 0x2A40A0: movss xmm0, dword ptr [0x0057007C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57007Cu);
	// 0x2A40A8: movss [0x00570118], xmm0
	X86_MEM_WRITE_u32(base, 0x570118u, ctx.xmm[0].u32[0]);
	// 0x2A40B0: ret
	return;
}

void sub_2A40C0(X86Context& ctx, uint8_t* base) {
	// 0x2A40C0: movss xmm0, dword ptr [0x005700FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700FCu);
	// 0x2A40C8: subss xmm0, [0x0057007C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57007Cu);
	// 0x2A40D0: movss [0x005700DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5700DCu, ctx.xmm[0].u32[0]);
	// 0x2A40D8: ret
	return;
}

void sub_2A40E0(X86Context& ctx, uint8_t* base) {
	// 0x2A40E0: movss xmm0, dword ptr [0x005700DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700DCu);
	// 0x2A40E8: subss xmm0, [0x005700B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5700B4u);
	// 0x2A40F0: movss [0x005700D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5700D4u, ctx.xmm[0].u32[0]);
	// 0x2A40F8: ret
	return;
}

void sub_2A4100(X86Context& ctx, uint8_t* base) {
	// 0x2A4100: movss xmm0, dword ptr [0x00570104]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570104u);
	// 0x2A4108: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A4110: movss [0x005700C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5700C4u, ctx.xmm[0].u32[0]);
	// 0x2A4118: ret
	return;
}

void sub_2A4120(X86Context& ctx, uint8_t* base) {
	// 0x2A4120: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A4128: movss [0x005700B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5700B0u, ctx.xmm[0].u32[0]);
	// 0x2A4130: ret
	return;
}

void sub_2A4140(X86Context& ctx, uint8_t* base) {
	// 0x2A4140: movss xmm0, dword ptr [0x005700C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5700C4u);
	// 0x2A4148: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A4150: movss [0x005700F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5700F4u, ctx.xmm[0].u32[0]);
	// 0x2A4158: ret
	return;
}

void sub_2A4160(X86Context& ctx, uint8_t* base) {
	// 0x2A4160: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A4168: movss [0x00570178], xmm0
	X86_MEM_WRITE_u32(base, 0x570178u, ctx.xmm[0].u32[0]);
	// 0x2A4170: ret
	return;
}

void sub_2A4180(X86Context& ctx, uint8_t* base) {
	// 0x2A4180: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A4188: movss [0x00570194], xmm0
	X86_MEM_WRITE_u32(base, 0x570194u, ctx.xmm[0].u32[0]);
	// 0x2A4190: ret
	return;
}

void sub_2A41A0(X86Context& ctx, uint8_t* base) {
	// 0x2A41A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A41A8: movss [0x0057016C], xmm0
	X86_MEM_WRITE_u32(base, 0x57016Cu, ctx.xmm[0].u32[0]);
	// 0x2A41B0: ret
	return;
}

void sub_2A41C0(X86Context& ctx, uint8_t* base) {
	// 0x2A41C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A41C8: movss [0x00570124], xmm0
	X86_MEM_WRITE_u32(base, 0x570124u, ctx.xmm[0].u32[0]);
	// 0x2A41D0: ret
	return;
}

void sub_2A41E0(X86Context& ctx, uint8_t* base) {
	// 0x2A41E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A41E8: movss [0x0057017C], xmm0
	X86_MEM_WRITE_u32(base, 0x57017Cu, ctx.xmm[0].u32[0]);
	// 0x2A41F0: ret
	return;
}

void sub_2A4200(X86Context& ctx, uint8_t* base) {
	// 0x2A4200: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A4208: movss [0x00570140], xmm0
	X86_MEM_WRITE_u32(base, 0x570140u, ctx.xmm[0].u32[0]);
	// 0x2A4210: ret
	return;
}

void sub_2A4220(X86Context& ctx, uint8_t* base) {
	// 0x2A4220: movss xmm0, dword ptr [0x0057017C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57017Cu);
	// 0x2A4228: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A4230: movss [0x005701B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5701B4u, ctx.xmm[0].u32[0]);
	// 0x2A4238: ret
	return;
}

void sub_2A4240(X86Context& ctx, uint8_t* base) {
	// 0x2A4240: movss xmm0, dword ptr [0x00570140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570140u);
	// 0x2A4248: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A4250: movss [0x0057019C], xmm0
	X86_MEM_WRITE_u32(base, 0x57019Cu, ctx.xmm[0].u32[0]);
	// 0x2A4258: ret
	return;
}

void sub_2A4260(X86Context& ctx, uint8_t* base) {
	// 0x2A4260: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A4268: movss [0x005701CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5701CCu, ctx.xmm[0].u32[0]);
	// 0x2A4270: ret
	return;
}

void sub_2A4280(X86Context& ctx, uint8_t* base) {
	// 0x2A4280: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A4288: movss [0x005701B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5701B8u, ctx.xmm[0].u32[0]);
	// 0x2A4290: ret
	return;
}

void sub_2A42A0(X86Context& ctx, uint8_t* base) {
	// 0x2A42A0: movss xmm0, dword ptr [0x005701B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701B8u);
	// 0x2A42A8: movss [0x005701C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5701C8u, ctx.xmm[0].u32[0]);
	// 0x2A42B0: ret
	return;
}

void sub_2A42C0(X86Context& ctx, uint8_t* base) {
	// 0x2A42C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A42C8: movss [0x0057012C], xmm0
	X86_MEM_WRITE_u32(base, 0x57012Cu, ctx.xmm[0].u32[0]);
	// 0x2A42D0: ret
	return;
}

void sub_2A42E0(X86Context& ctx, uint8_t* base) {
	// 0x2A42E0: movss xmm0, dword ptr [0x00570140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570140u);
	// 0x2A42E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A42F0: movss [0x005701C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5701C0u, ctx.xmm[0].u32[0]);
	// 0x2A42F8: ret
	return;
}

void sub_2A4300(X86Context& ctx, uint8_t* base) {
	// 0x2A4300: movss xmm0, dword ptr [0x00570140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570140u);
	// 0x2A4308: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A4310: movss [0x00570168], xmm0
	X86_MEM_WRITE_u32(base, 0x570168u, ctx.xmm[0].u32[0]);
	// 0x2A4318: ret
	return;
}

void sub_2A4320(X86Context& ctx, uint8_t* base) {
	// 0x2A4320: movss xmm0, dword ptr [0x00570140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570140u);
	// 0x2A4328: subss xmm0, [0x00570168]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570168u);
	// 0x2A4330: movss [0x00570148], xmm0
	X86_MEM_WRITE_u32(base, 0x570148u, ctx.xmm[0].u32[0]);
	// 0x2A4338: ret
	return;
}

void sub_2A4340(X86Context& ctx, uint8_t* base) {
	// 0x2A4340: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A4348: movss [0x00570190], xmm0
	X86_MEM_WRITE_u32(base, 0x570190u, ctx.xmm[0].u32[0]);
	// 0x2A4350: ret
	return;
}

void sub_2A4360(X86Context& ctx, uint8_t* base) {
	// 0x2A4360: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A4368: movss [0x00570144], xmm0
	X86_MEM_WRITE_u32(base, 0x570144u, ctx.xmm[0].u32[0]);
	// 0x2A4370: ret
	return;
}

void sub_2A4380(X86Context& ctx, uint8_t* base) {
	// 0x2A4380: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A4388: movss [0x00570154], xmm0
	X86_MEM_WRITE_u32(base, 0x570154u, ctx.xmm[0].u32[0]);
	// 0x2A4390: ret
	return;
}

void sub_2A43A0(X86Context& ctx, uint8_t* base) {
	// 0x2A43A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A43A8: movss [0x005701A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5701A8u, ctx.xmm[0].u32[0]);
	// 0x2A43B0: ret
	return;
}

void sub_2A43C0(X86Context& ctx, uint8_t* base) {
	// 0x2A43C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A43C8: movss [0x0057018C], xmm0
	X86_MEM_WRITE_u32(base, 0x57018Cu, ctx.xmm[0].u32[0]);
	// 0x2A43D0: ret
	return;
}

void sub_2A43E0(X86Context& ctx, uint8_t* base) {
	// 0x2A43E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A43E8: movss [0x0057013C], xmm0
	X86_MEM_WRITE_u32(base, 0x57013Cu, ctx.xmm[0].u32[0]);
	// 0x2A43F0: ret
	return;
}

void sub_2A4400(X86Context& ctx, uint8_t* base) {
	// 0x2A4400: movss xmm0, dword ptr [0x00570154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570154u);
	// 0x2A4408: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A4410: movss [0x00570130], xmm0
	X86_MEM_WRITE_u32(base, 0x570130u, ctx.xmm[0].u32[0]);
	// 0x2A4418: ret
	return;
}

void sub_2A4420(X86Context& ctx, uint8_t* base) {
	// 0x2A4420: movss xmm0, dword ptr [0x005701A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701A8u);
	// 0x2A4428: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A4430: movss [0x00570174], xmm0
	X86_MEM_WRITE_u32(base, 0x570174u, ctx.xmm[0].u32[0]);
	// 0x2A4438: ret
	return;
}

void sub_2A4440(X86Context& ctx, uint8_t* base) {
	// 0x2A4440: movss xmm0, dword ptr [0x00570130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570130u);
	// 0x2A4448: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A4450: movss [0x00570184], xmm0
	X86_MEM_WRITE_u32(base, 0x570184u, ctx.xmm[0].u32[0]);
	// 0x2A4458: ret
	return;
}

void sub_2A4460(X86Context& ctx, uint8_t* base) {
	// 0x2A4460: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A4468: movss [0x00570128], xmm0
	X86_MEM_WRITE_u32(base, 0x570128u, ctx.xmm[0].u32[0]);
	// 0x2A4470: ret
	return;
}

void sub_2A4480(X86Context& ctx, uint8_t* base) {
	// 0x2A4480: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A4488: movss [0x00570158], xmm0
	X86_MEM_WRITE_u32(base, 0x570158u, ctx.xmm[0].u32[0]);
	// 0x2A4490: ret
	return;
}

void sub_2A44A0(X86Context& ctx, uint8_t* base) {
	// 0x2A44A0: movss xmm0, dword ptr [0x00570154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570154u);
	// 0x2A44A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A44B0: movss [0x00570164], xmm0
	X86_MEM_WRITE_u32(base, 0x570164u, ctx.xmm[0].u32[0]);
	// 0x2A44B8: ret
	return;
}

void sub_2A44C0(X86Context& ctx, uint8_t* base) {
	// 0x2A44C0: movss xmm0, dword ptr [0x005701A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701A8u);
	// 0x2A44C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A44D0: movss [0x005701AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5701ACu, ctx.xmm[0].u32[0]);
	// 0x2A44D8: ret
	return;
}

void sub_2A44E0(X86Context& ctx, uint8_t* base) {
	// 0x2A44E0: movss xmm0, dword ptr [0x00570164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570164u);
	// 0x2A44E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A44F0: movss [0x00570198], xmm0
	X86_MEM_WRITE_u32(base, 0x570198u, ctx.xmm[0].u32[0]);
	// 0x2A44F8: ret
	return;
}

void sub_2A4500(X86Context& ctx, uint8_t* base) {
	// 0x2A4500: movss xmm0, dword ptr [0x005701AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701ACu);
	// 0x2A4508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4510: movss [0x005701BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5701BCu, ctx.xmm[0].u32[0]);
	// 0x2A4518: ret
	return;
}

void sub_2A4520(X86Context& ctx, uint8_t* base) {
	// 0x2A4520: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A4528: movss [0x00570134], xmm0
	X86_MEM_WRITE_u32(base, 0x570134u, ctx.xmm[0].u32[0]);
	// 0x2A4530: ret
	return;
}

void sub_2A4540(X86Context& ctx, uint8_t* base) {
	// 0x2A4540: movss xmm0, dword ptr [0x00570154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570154u);
	// 0x2A4548: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4550: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A4558: movss [0x005701A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5701A4u, ctx.xmm[0].u32[0]);
	// 0x2A4560: ret
	return;
}

void sub_2A4570(X86Context& ctx, uint8_t* base) {
	// 0x2A4570: movss xmm0, dword ptr [0x005701A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701A8u);
	// 0x2A4578: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4580: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A4588: movss [0x0057014C], xmm0
	X86_MEM_WRITE_u32(base, 0x57014Cu, ctx.xmm[0].u32[0]);
	// 0x2A4590: ret
	return;
}

void sub_2A45A0(X86Context& ctx, uint8_t* base) {
	// 0x2A45A0: movss xmm0, dword ptr [0x00570154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570154u);
	// 0x2A45A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A45B0: movss [0x00570150], xmm0
	X86_MEM_WRITE_u32(base, 0x570150u, ctx.xmm[0].u32[0]);
	// 0x2A45B8: ret
	return;
}

void sub_2A45C0(X86Context& ctx, uint8_t* base) {
	// 0x2A45C0: movss xmm0, dword ptr [0x005701A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701A8u);
	// 0x2A45C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A45D0: movss [0x005701B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5701B0u, ctx.xmm[0].u32[0]);
	// 0x2A45D8: ret
	return;
}

void sub_2A45E0(X86Context& ctx, uint8_t* base) {
	// 0x2A45E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A45E8: movss [0x00570138], xmm0
	X86_MEM_WRITE_u32(base, 0x570138u, ctx.xmm[0].u32[0]);
	// 0x2A45F0: ret
	return;
}

void sub_2A4600(X86Context& ctx, uint8_t* base) {
	// 0x2A4600: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A4608: movss [0x00570160], xmm0
	X86_MEM_WRITE_u32(base, 0x570160u, ctx.xmm[0].u32[0]);
	// 0x2A4610: ret
	return;
}

void sub_2A4620(X86Context& ctx, uint8_t* base) {
	// 0x2A4620: movss xmm0, dword ptr [0x00570138]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570138u);
	// 0x2A4628: movss [0x005701C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5701C4u, ctx.xmm[0].u32[0]);
	// 0x2A4630: ret
	return;
}

void sub_2A4640(X86Context& ctx, uint8_t* base) {
	// 0x2A4640: movss xmm0, dword ptr [0x005701A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701A8u);
	// 0x2A4648: subss xmm0, [0x00570138]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570138u);
	// 0x2A4650: movss [0x00570188], xmm0
	X86_MEM_WRITE_u32(base, 0x570188u, ctx.xmm[0].u32[0]);
	// 0x2A4658: ret
	return;
}

void sub_2A4660(X86Context& ctx, uint8_t* base) {
	// 0x2A4660: movss xmm0, dword ptr [0x00570188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570188u);
	// 0x2A4668: subss xmm0, [0x00570160]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570160u);
	// 0x2A4670: movss [0x00570180], xmm0
	X86_MEM_WRITE_u32(base, 0x570180u, ctx.xmm[0].u32[0]);
	// 0x2A4678: ret
	return;
}

void sub_2A4680(X86Context& ctx, uint8_t* base) {
	// 0x2A4680: movss xmm0, dword ptr [0x005701B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701B0u);
	// 0x2A4688: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A4690: movss [0x00570170], xmm0
	X86_MEM_WRITE_u32(base, 0x570170u, ctx.xmm[0].u32[0]);
	// 0x2A4698: ret
	return;
}

