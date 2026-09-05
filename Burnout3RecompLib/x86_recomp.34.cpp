#include "x86_recomp_shared.h"

void sub_264710(X86Context& ctx, uint8_t* base) {
	// 0x264710: movss xmm0, dword ptr [0x003B1F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F88u);
	// 0x264718: movss [0x0054F374], xmm0
	X86_MEM_WRITE_u32(base, 0x54F374u, ctx.xmm[0].u32[0]);
	// 0x264720: ret
	return;
}

void sub_264730(X86Context& ctx, uint8_t* base) {
	// 0x264730: movss xmm0, dword ptr [0x003B219C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B219Cu);
	// 0x264738: movss [0x0054F39C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F39Cu, ctx.xmm[0].u32[0]);
	// 0x264740: ret
	return;
}

void sub_264750(X86Context& ctx, uint8_t* base) {
	// 0x264750: movss xmm0, dword ptr [0x003B21A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21A0u);
	// 0x264758: movss [0x0054F36C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F36Cu, ctx.xmm[0].u32[0]);
	// 0x264760: ret
	return;
}

void sub_264770(X86Context& ctx, uint8_t* base) {
	// 0x264770: movss xmm0, dword ptr [0x0054F39C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F39Cu);
	// 0x264778: movss [0x0054F380], xmm0
	X86_MEM_WRITE_u32(base, 0x54F380u, ctx.xmm[0].u32[0]);
	// 0x264780: ret
	return;
}

void sub_264790(X86Context& ctx, uint8_t* base) {
	// 0x264790: movss xmm0, dword ptr [0x0054F36C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F36Cu);
	// 0x264798: movss [0x0054F37C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F37Cu, ctx.xmm[0].u32[0]);
	// 0x2647A0: ret
	return;
}

void sub_2647B0(X86Context& ctx, uint8_t* base) {
	// 0x2647B0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2647B1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2647B3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2647B6: sub esp, 0x24
	{ uint32_t _d = ctx.esp; uint32_t _s = 36;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2647B9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2647BA: movss xmm1, dword ptr [0x003B168C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2647C2: movaps xmm0, xmm1
	ctx.xmm[0] = ctx.xmm[1];
	// 0x2647C5: divss xmm0, [0x003FC9E8]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x3FC9E8u);
	// 0x2647CD: divss xmm1, [0x003FC9EC]
	ctx.xmm[1].f32[0] /= X86_MEM_READ_F32(base, 0x3FC9ECu);
	// 0x2647D5: movaps xmm2, xmm0
	ctx.xmm[2] = ctx.xmm[0];
	// 0x2647D8: mulss xmm2, [0x003FC9E0]
	ctx.xmm[2].f32[0] *= X86_MEM_READ_F32(base, 0x3FC9E0u);
	// 0x2647E0: mulss xmm0, [0x003FC9F0]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3FC9F0u);
	// 0x2647E8: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x2647EE: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2647F2: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2647F8: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2647FC: movaps xmm2, xmm1
	ctx.xmm[2] = ctx.xmm[1];
	// 0x2647FF: mulss xmm2, [0x003FC9E4]
	ctx.xmm[2].f32[0] *= X86_MEM_READ_F32(base, 0x3FC9E4u);
	// 0x264807: mulss xmm1, [0x003FC9F4]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3FC9F4u);
	// 0x26480F: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x264815: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x264819: mov [esp+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.edx);
	// 0x26481D: movss xmm0, dword ptr [esp+0x10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x264823: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x264829: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26482D: mov [esp+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.eax);
	// 0x264831: addss xmm0, [esp+0x18]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, ctx.esp + 0x18u);
	// 0x264837: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x26483D: mov [esp+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edx);
	// 0x264841: movss xmm0, dword ptr [esp+0x14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x264847: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26484B: mov [esp+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.ecx);
	// 0x26484F: addss xmm0, [esp+0x1C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, ctx.esp + 0x1Cu);
	// 0x264855: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x26485B: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26485F: mov [0x0054F364], esi
	X86_MEM_WRITE_u32(base, 0x54F364u, ctx.esi);
	// 0x264865: mov [0x0054F358], eax
	X86_MEM_WRITE_u32(base, 0x54F358u, ctx.eax);
	// 0x26486A: mov [0x0054F35C], ecx
	X86_MEM_WRITE_u32(base, 0x54F35Cu, ctx.ecx);
	// 0x264870: mov [0x0054F360], edx
	X86_MEM_WRITE_u32(base, 0x54F360u, ctx.edx);
	// 0x264876: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x264877: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x264879: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x26487A: ret
	return;
}

void sub_264880(X86Context& ctx, uint8_t* base) {
	// 0x264880: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x264888: movss [0x0054F46C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F46Cu, ctx.xmm[0].u32[0]);
	// 0x264890: ret
	return;
}

void sub_2648A0(X86Context& ctx, uint8_t* base) {
	// 0x2648A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2648A8: movss [0x0054F490], xmm0
	X86_MEM_WRITE_u32(base, 0x54F490u, ctx.xmm[0].u32[0]);
	// 0x2648B0: ret
	return;
}

void sub_2648C0(X86Context& ctx, uint8_t* base) {
	// 0x2648C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2648C8: movss [0x0054F434], xmm0
	X86_MEM_WRITE_u32(base, 0x54F434u, ctx.xmm[0].u32[0]);
	// 0x2648D0: ret
	return;
}

void sub_2648E0(X86Context& ctx, uint8_t* base) {
	// 0x2648E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2648E8: movss [0x0054F3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3B4u, ctx.xmm[0].u32[0]);
	// 0x2648F0: ret
	return;
}

void sub_264900(X86Context& ctx, uint8_t* base) {
	// 0x264900: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x264908: movss [0x0054F474], xmm0
	X86_MEM_WRITE_u32(base, 0x54F474u, ctx.xmm[0].u32[0]);
	// 0x264910: ret
	return;
}

void sub_264920(X86Context& ctx, uint8_t* base) {
	// 0x264920: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x264928: movss [0x0054F3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3C8u, ctx.xmm[0].u32[0]);
	// 0x264930: ret
	return;
}

void sub_264940(X86Context& ctx, uint8_t* base) {
	// 0x264940: movss xmm0, dword ptr [0x0054F474]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F474u);
	// 0x264948: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x264950: movss [0x0054F4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4A4u, ctx.xmm[0].u32[0]);
	// 0x264958: ret
	return;
}

void sub_264960(X86Context& ctx, uint8_t* base) {
	// 0x264960: movss xmm0, dword ptr [0x0054F3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F3C8u);
	// 0x264968: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x264970: movss [0x0054F498], xmm0
	X86_MEM_WRITE_u32(base, 0x54F498u, ctx.xmm[0].u32[0]);
	// 0x264978: ret
	return;
}

void sub_264980(X86Context& ctx, uint8_t* base) {
	// 0x264980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264988: movss [0x0054F4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4C8u, ctx.xmm[0].u32[0]);
	// 0x264990: ret
	return;
}

void sub_2649A0(X86Context& ctx, uint8_t* base) {
	// 0x2649A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2649A8: movss [0x0054F4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4A8u, ctx.xmm[0].u32[0]);
	// 0x2649B0: ret
	return;
}

void sub_2649C0(X86Context& ctx, uint8_t* base) {
	// 0x2649C0: movss xmm0, dword ptr [0x0054F4A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F4A8u);
	// 0x2649C8: movss [0x0054F4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4C4u, ctx.xmm[0].u32[0]);
	// 0x2649D0: ret
	return;
}

void sub_2649E0(X86Context& ctx, uint8_t* base) {
	// 0x2649E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2649E8: movss [0x0054F3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3C0u, ctx.xmm[0].u32[0]);
	// 0x2649F0: ret
	return;
}

void sub_264A00(X86Context& ctx, uint8_t* base) {
	// 0x264A00: movss xmm0, dword ptr [0x0054F3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F3C8u);
	// 0x264A08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x264A10: movss [0x0054F4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4BCu, ctx.xmm[0].u32[0]);
	// 0x264A18: ret
	return;
}

void sub_264A20(X86Context& ctx, uint8_t* base) {
	// 0x264A20: movss xmm0, dword ptr [0x0054F3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F3C8u);
	// 0x264A28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x264A30: movss [0x0054F42C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F42Cu, ctx.xmm[0].u32[0]);
	// 0x264A38: ret
	return;
}

void sub_264A40(X86Context& ctx, uint8_t* base) {
	// 0x264A40: movss xmm0, dword ptr [0x0054F3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F3C8u);
	// 0x264A48: subss xmm0, [0x0054F42C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F42Cu);
	// 0x264A50: movss [0x0054F3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3D4u, ctx.xmm[0].u32[0]);
	// 0x264A58: ret
	return;
}

void sub_264A60(X86Context& ctx, uint8_t* base) {
	// 0x264A60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x264A68: movss [0x0054F48C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F48Cu, ctx.xmm[0].u32[0]);
	// 0x264A70: ret
	return;
}

void sub_264A80(X86Context& ctx, uint8_t* base) {
	// 0x264A80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x264A88: movss [0x0054F3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3CCu, ctx.xmm[0].u32[0]);
	// 0x264A90: ret
	return;
}

void sub_264AA0(X86Context& ctx, uint8_t* base) {
	// 0x264AA0: movss xmm0, dword ptr [0x003B18BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B18BCu);
	// 0x264AA8: movss [0x0054F4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4A0u, ctx.xmm[0].u32[0]);
	// 0x264AB0: ret
	return;
}

void sub_264AC0(X86Context& ctx, uint8_t* base) {
	// 0x264AC0: movss xmm0, dword ptr [0x003B19F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B19F4u);
	// 0x264AC8: movss [0x0054F47C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F47Cu, ctx.xmm[0].u32[0]);
	// 0x264AD0: ret
	return;
}

void sub_264AE0(X86Context& ctx, uint8_t* base) {
	// 0x264AE0: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264AE3: movss [0x0054F3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3C4u, ctx.xmm[0].u32[0]);
	// 0x264AEB: ret
	return;
}

void sub_264AF0(X86Context& ctx, uint8_t* base) {
	// 0x264AF0: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264AF3: movss [0x0054F404], xmm0
	X86_MEM_WRITE_u32(base, 0x54F404u, ctx.xmm[0].u32[0]);
	// 0x264AFB: ret
	return;
}

void sub_264B00(X86Context& ctx, uint8_t* base) {
	// 0x264B00: movss xmm0, dword ptr [0x003B21A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21A4u);
	// 0x264B08: movss [0x0054F464], xmm0
	X86_MEM_WRITE_u32(base, 0x54F464u, ctx.xmm[0].u32[0]);
	// 0x264B10: ret
	return;
}

void sub_264B20(X86Context& ctx, uint8_t* base) {
	// 0x264B20: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x264B28: movss [0x0054F448], xmm0
	X86_MEM_WRITE_u32(base, 0x54F448u, ctx.xmm[0].u32[0]);
	// 0x264B30: ret
	return;
}

void sub_264B40(X86Context& ctx, uint8_t* base) {
	// 0x264B40: movss xmm0, dword ptr [0x003B21A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21A8u);
	// 0x264B48: movss [0x0054F408], xmm0
	X86_MEM_WRITE_u32(base, 0x54F408u, ctx.xmm[0].u32[0]);
	// 0x264B50: ret
	return;
}

void sub_264B60(X86Context& ctx, uint8_t* base) {
	// 0x264B60: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264B63: movss [0x0054F414], xmm0
	X86_MEM_WRITE_u32(base, 0x54F414u, ctx.xmm[0].u32[0]);
	// 0x264B6B: ret
	return;
}

void sub_264B70(X86Context& ctx, uint8_t* base) {
	// 0x264B70: movss xmm0, dword ptr [0x003B21AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21ACu);
	// 0x264B78: movss [0x0054F4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4B0u, ctx.xmm[0].u32[0]);
	// 0x264B80: ret
	return;
}

void sub_264B90(X86Context& ctx, uint8_t* base) {
	// 0x264B90: movss xmm0, dword ptr [0x003B21B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21B0u);
	// 0x264B98: movss [0x0054F494], xmm0
	X86_MEM_WRITE_u32(base, 0x54F494u, ctx.xmm[0].u32[0]);
	// 0x264BA0: ret
	return;
}

void sub_264BB0(X86Context& ctx, uint8_t* base) {
	// 0x264BB0: movss xmm0, dword ptr [0x003B21B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21B4u);
	// 0x264BB8: movss [0x0054F41C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F41Cu, ctx.xmm[0].u32[0]);
	// 0x264BC0: ret
	return;
}

void sub_264BD0(X86Context& ctx, uint8_t* base) {
	// 0x264BD0: movss xmm0, dword ptr [0x003B21B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21B8u);
	// 0x264BD8: movss [0x0054F410], xmm0
	X86_MEM_WRITE_u32(base, 0x54F410u, ctx.xmm[0].u32[0]);
	// 0x264BE0: ret
	return;
}

void sub_264BF0(X86Context& ctx, uint8_t* base) {
	// 0x264BF0: movss xmm0, dword ptr [0x003B187C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B187Cu);
	// 0x264BF8: movss [0x0054F424], xmm0
	X86_MEM_WRITE_u32(base, 0x54F424u, ctx.xmm[0].u32[0]);
	// 0x264C00: ret
	return;
}

void sub_264C10(X86Context& ctx, uint8_t* base) {
	// 0x264C10: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x264C18: movss [0x0054F460], xmm0
	X86_MEM_WRITE_u32(base, 0x54F460u, ctx.xmm[0].u32[0]);
	// 0x264C20: ret
	return;
}

void sub_264C30(X86Context& ctx, uint8_t* base) {
	// 0x264C30: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264C33: movss [0x0054F3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3B0u, ctx.xmm[0].u32[0]);
	// 0x264C3B: ret
	return;
}

void sub_264C40(X86Context& ctx, uint8_t* base) {
	// 0x264C40: movss xmm0, dword ptr [0x003B21BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21BCu);
	// 0x264C48: movss [0x0054F444], xmm0
	X86_MEM_WRITE_u32(base, 0x54F444u, ctx.xmm[0].u32[0]);
	// 0x264C50: ret
	return;
}

void sub_264C60(X86Context& ctx, uint8_t* base) {
	// 0x264C60: movss xmm0, dword ptr [0x003B21C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21C0u);
	// 0x264C68: movss [0x0054F45C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F45Cu, ctx.xmm[0].u32[0]);
	// 0x264C70: ret
	return;
}

void sub_264C80(X86Context& ctx, uint8_t* base) {
	// 0x264C80: movss xmm0, dword ptr [0x003B21C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21C4u);
	// 0x264C88: movss [0x0054F3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3D8u, ctx.xmm[0].u32[0]);
	// 0x264C90: ret
	return;
}

void sub_264CA0(X86Context& ctx, uint8_t* base) {
	// 0x264CA0: movss xmm0, dword ptr [0x003B1EB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EB4u);
	// 0x264CA8: movss [0x0054F44C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F44Cu, ctx.xmm[0].u32[0]);
	// 0x264CB0: ret
	return;
}

void sub_264CC0(X86Context& ctx, uint8_t* base) {
	// 0x264CC0: movss xmm0, dword ptr [0x003B21C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21C8u);
	// 0x264CC8: movss [0x0054F418], xmm0
	X86_MEM_WRITE_u32(base, 0x54F418u, ctx.xmm[0].u32[0]);
	// 0x264CD0: ret
	return;
}

void sub_264CE0(X86Context& ctx, uint8_t* base) {
	// 0x264CE0: movss xmm0, dword ptr [0x003B21CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21CCu);
	// 0x264CE8: movss [0x0054F3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3F0u, ctx.xmm[0].u32[0]);
	// 0x264CF0: ret
	return;
}

void sub_264D00(X86Context& ctx, uint8_t* base) {
	// 0x264D00: movss xmm0, dword ptr [0x003B21D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21D0u);
	// 0x264D08: movss [0x0054F450], xmm0
	X86_MEM_WRITE_u32(base, 0x54F450u, ctx.xmm[0].u32[0]);
	// 0x264D10: ret
	return;
}

void sub_264D20(X86Context& ctx, uint8_t* base) {
	// 0x264D20: movss xmm0, dword ptr [0x003B1EAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EACu);
	// 0x264D28: movss [0x0054F4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4B4u, ctx.xmm[0].u32[0]);
	// 0x264D30: ret
	return;
}

void sub_264D40(X86Context& ctx, uint8_t* base) {
	// 0x264D40: movss xmm0, dword ptr [0x003B1EAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EACu);
	// 0x264D48: movss [0x0054F43C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F43Cu, ctx.xmm[0].u32[0]);
	// 0x264D50: ret
	return;
}

void sub_264D60(X86Context& ctx, uint8_t* base) {
	// 0x264D60: movss xmm0, dword ptr [0x003B21D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21D4u);
	// 0x264D68: movss [0x0054F3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3E4u, ctx.xmm[0].u32[0]);
	// 0x264D70: ret
	return;
}

void sub_264D80(X86Context& ctx, uint8_t* base) {
	// 0x264D80: movss xmm0, dword ptr [0x003B21D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21D8u);
	// 0x264D88: movss [0x0054F4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4CCu, ctx.xmm[0].u32[0]);
	// 0x264D90: ret
	return;
}

void sub_264DA0(X86Context& ctx, uint8_t* base) {
	// 0x264DA0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x264DA8: movss [0x0054F4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4C0u, ctx.xmm[0].u32[0]);
	// 0x264DB0: ret
	return;
}

void sub_264DC0(X86Context& ctx, uint8_t* base) {
	// 0x264DC0: movss xmm0, dword ptr [0x003B21DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21DCu);
	// 0x264DC8: movss [0x0054F468], xmm0
	X86_MEM_WRITE_u32(base, 0x54F468u, ctx.xmm[0].u32[0]);
	// 0x264DD0: ret
	return;
}

void sub_264DE0(X86Context& ctx, uint8_t* base) {
	// 0x264DE0: movss xmm0, dword ptr [0x003B21E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21E0u);
	// 0x264DE8: movss [0x0054F3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3DCu, ctx.xmm[0].u32[0]);
	// 0x264DF0: ret
	return;
}

void sub_264E00(X86Context& ctx, uint8_t* base) {
	// 0x264E00: movss xmm0, dword ptr [0x003B21E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21E4u);
	// 0x264E08: movss [0x0054F478], xmm0
	X86_MEM_WRITE_u32(base, 0x54F478u, ctx.xmm[0].u32[0]);
	// 0x264E10: ret
	return;
}

void sub_264E20(X86Context& ctx, uint8_t* base) {
	// 0x264E20: movss xmm0, dword ptr [0x003B21E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21E8u);
	// 0x264E28: movss [0x0054F3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3E0u, ctx.xmm[0].u32[0]);
	// 0x264E30: ret
	return;
}

void sub_264E40(X86Context& ctx, uint8_t* base) {
	// 0x264E40: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264E43: movss [0x0054F488], xmm0
	X86_MEM_WRITE_u32(base, 0x54F488u, ctx.xmm[0].u32[0]);
	// 0x264E4B: ret
	return;
}

void sub_264E50(X86Context& ctx, uint8_t* base) {
	// 0x264E50: movss xmm0, dword ptr [0x003B21EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21ECu);
	// 0x264E58: movss [0x0054F40C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F40Cu, ctx.xmm[0].u32[0]);
	// 0x264E60: ret
	return;
}

void sub_264E70(X86Context& ctx, uint8_t* base) {
	// 0x264E70: movss xmm0, dword ptr [0x003B21F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21F0u);
	// 0x264E78: movss [0x0054F4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4B8u, ctx.xmm[0].u32[0]);
	// 0x264E80: ret
	return;
}

void sub_264E90(X86Context& ctx, uint8_t* base) {
	// 0x264E90: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264E93: movss [0x0054F430], xmm0
	X86_MEM_WRITE_u32(base, 0x54F430u, ctx.xmm[0].u32[0]);
	// 0x264E9B: ret
	return;
}

void sub_264EA0(X86Context& ctx, uint8_t* base) {
	// 0x264EA0: movss xmm0, dword ptr [0x003B19E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B19E8u);
	// 0x264EA8: movss [0x0054F458], xmm0
	X86_MEM_WRITE_u32(base, 0x54F458u, ctx.xmm[0].u32[0]);
	// 0x264EB0: ret
	return;
}

void sub_264EC0(X86Context& ctx, uint8_t* base) {
	// 0x264EC0: movss xmm0, dword ptr [0x003B1838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1838u);
	// 0x264EC8: movss [0x0054F470], xmm0
	X86_MEM_WRITE_u32(base, 0x54F470u, ctx.xmm[0].u32[0]);
	// 0x264ED0: ret
	return;
}

void sub_264EE0(X86Context& ctx, uint8_t* base) {
	// 0x264EE0: movss xmm0, dword ptr [0x003B1BEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1BECu);
	// 0x264EE8: movss [0x0054F4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4ACu, ctx.xmm[0].u32[0]);
	// 0x264EF0: ret
	return;
}

void sub_264F00(X86Context& ctx, uint8_t* base) {
	// 0x264F00: movss xmm0, dword ptr [0x003B21F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21F4u);
	// 0x264F08: movss [0x0054F480], xmm0
	X86_MEM_WRITE_u32(base, 0x54F480u, ctx.xmm[0].u32[0]);
	// 0x264F10: ret
	return;
}

void sub_264F20(X86Context& ctx, uint8_t* base) {
	// 0x264F20: movss xmm0, dword ptr [0x003B21F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21F8u);
	// 0x264F28: movss [0x0054F3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3F4u, ctx.xmm[0].u32[0]);
	// 0x264F30: ret
	return;
}

void sub_264F40(X86Context& ctx, uint8_t* base) {
	// 0x264F40: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x264F43: movss [0x0054F420], xmm0
	X86_MEM_WRITE_u32(base, 0x54F420u, ctx.xmm[0].u32[0]);
	// 0x264F4B: ret
	return;
}

void sub_264F50(X86Context& ctx, uint8_t* base) {
	// 0x264F50: movss xmm0, dword ptr [0x003B21FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B21FCu);
	// 0x264F58: movss [0x0054F440], xmm0
	X86_MEM_WRITE_u32(base, 0x54F440u, ctx.xmm[0].u32[0]);
	// 0x264F60: ret
	return;
}

void sub_264F70(X86Context& ctx, uint8_t* base) {
	// 0x264F70: movss xmm0, dword ptr [0x003B1E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1E88u);
	// 0x264F78: movss [0x0054F3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3ECu, ctx.xmm[0].u32[0]);
	// 0x264F80: ret
	return;
}

void sub_264F90(X86Context& ctx, uint8_t* base) {
	// 0x264F90: movss xmm0, dword ptr [0x003B1EB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EB4u);
	// 0x264F98: movss [0x0054F438], xmm0
	X86_MEM_WRITE_u32(base, 0x54F438u, ctx.xmm[0].u32[0]);
	// 0x264FA0: ret
	return;
}

void sub_264FB0(X86Context& ctx, uint8_t* base) {
	// 0x264FB0: movss xmm0, dword ptr [0x003B2200]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2200u);
	// 0x264FB8: movss [0x0054F484], xmm0
	X86_MEM_WRITE_u32(base, 0x54F484u, ctx.xmm[0].u32[0]);
	// 0x264FC0: ret
	return;
}

void sub_264FD0(X86Context& ctx, uint8_t* base) {
	// 0x264FD0: movss xmm0, dword ptr [0x003FCBC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3FCBC4u);
	// 0x264FD8: addss xmm0, [0x003B1698]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1698u);
	// 0x264FE0: movss [0x0054F3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3E8u, ctx.xmm[0].u32[0]);
	// 0x264FE8: ret
	return;
}

void sub_264FF0(X86Context& ctx, uint8_t* base) {
	// 0x264FF0: movss xmm0, dword ptr [0x003FCBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3FCBC8u);
	// 0x264FF8: movss [0x0054F3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3D0u, ctx.xmm[0].u32[0]);
	// 0x265000: ret
	return;
}

void sub_265010(X86Context& ctx, uint8_t* base) {
	// 0x265010: movss xmm0, dword ptr [0x00397540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397540u);
	// 0x265018: movss [0x0054F49C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F49Cu, ctx.xmm[0].u32[0]);
	// 0x265020: ret
	return;
}

void sub_265030(X86Context& ctx, uint8_t* base) {
	// 0x265030: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x265031: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x265033: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x265036: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x265039: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x265041: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x265044: divss xmm1, [0x003FCBE0]
	ctx.xmm[1].f32[0] /= X86_MEM_READ_F32(base, 0x3FCBE0u);
	// 0x26504C: divss xmm0, [0x003FCBE4]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x3FCBE4u);
	// 0x265054: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x265059: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26505C: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x265062: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x265066: mov [0x0054F3F8], eax
	X86_MEM_WRITE_u32(base, 0x54F3F8u, ctx.eax);
	// 0x26506B: mov [0x0054F3FC], ecx
	X86_MEM_WRITE_u32(base, 0x54F3FCu, ctx.ecx);
	// 0x265071: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x265073: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x265074: ret
	return;
}

void sub_265080(X86Context& ctx, uint8_t* base) {
	// 0x265080: movss xmm0, dword ptr [0x003B2204]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2204u);
	// 0x265088: movss [0x0054F3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3B8u, ctx.xmm[0].u32[0]);
	// 0x265090: ret
	return;
}

void sub_2650A0(X86Context& ctx, uint8_t* base) {
	// 0x2650A0: movss xmm0, dword ptr [0x003B2208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2208u);
	// 0x2650A8: movss [0x0054F428], xmm0
	X86_MEM_WRITE_u32(base, 0x54F428u, ctx.xmm[0].u32[0]);
	// 0x2650B0: ret
	return;
}

void sub_2650C0(X86Context& ctx, uint8_t* base) {
	// 0x2650C0: movss xmm0, dword ptr [0x003B220C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B220Cu);
	// 0x2650C8: movss [0x0054F400], xmm0
	X86_MEM_WRITE_u32(base, 0x54F400u, ctx.xmm[0].u32[0]);
	// 0x2650D0: ret
	return;
}

void sub_2650E0(X86Context& ctx, uint8_t* base) {
	// 0x2650E0: movss xmm0, dword ptr [0x003B2210]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2210u);
	// 0x2650E8: movss [0x0054F3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3BCu, ctx.xmm[0].u32[0]);
	// 0x2650F0: ret
	return;
}

void sub_265100(X86Context& ctx, uint8_t* base) {
	// 0x265100: movss xmm0, dword ptr [0x0054F3BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F3BCu);
	// 0x265108: movss [0x0054F454], xmm0
	X86_MEM_WRITE_u32(base, 0x54F454u, ctx.xmm[0].u32[0]);
	// 0x265110: ret
	return;
}

void sub_265120(X86Context& ctx, uint8_t* base) {
	// 0x265120: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x265128: movss [0x0054F4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4F0u, ctx.xmm[0].u32[0]);
	// 0x265130: ret
	return;
}

void sub_265140(X86Context& ctx, uint8_t* base) {
	// 0x265140: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x265148: movss [0x0054F4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4FCu, ctx.xmm[0].u32[0]);
	// 0x265150: ret
	return;
}

void sub_265160(X86Context& ctx, uint8_t* base) {
	// 0x265160: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x265168: movss [0x0054F4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4ECu, ctx.xmm[0].u32[0]);
	// 0x265170: ret
	return;
}

void sub_265180(X86Context& ctx, uint8_t* base) {
	// 0x265180: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x265188: movss [0x0054F4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4D0u, ctx.xmm[0].u32[0]);
	// 0x265190: ret
	return;
}

void sub_2651A0(X86Context& ctx, uint8_t* base) {
	// 0x2651A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2651A8: movss [0x0054F4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4F4u, ctx.xmm[0].u32[0]);
	// 0x2651B0: ret
	return;
}

void sub_2651C0(X86Context& ctx, uint8_t* base) {
	// 0x2651C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2651C8: movss [0x0054F4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4D8u, ctx.xmm[0].u32[0]);
	// 0x2651D0: ret
	return;
}

void sub_2651E0(X86Context& ctx, uint8_t* base) {
	// 0x2651E0: movss xmm0, dword ptr [0x0054F4F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F4F4u);
	// 0x2651E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2651F0: movss [0x0054F570], xmm0
	X86_MEM_WRITE_u32(base, 0x54F570u, ctx.xmm[0].u32[0]);
	// 0x2651F8: ret
	return;
}

void sub_265200(X86Context& ctx, uint8_t* base) {
	// 0x265200: movss xmm0, dword ptr [0x0054F4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F4D8u);
	// 0x265208: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x265210: movss [0x0054F500], xmm0
	X86_MEM_WRITE_u32(base, 0x54F500u, ctx.xmm[0].u32[0]);
	// 0x265218: ret
	return;
}

void sub_265220(X86Context& ctx, uint8_t* base) {
	// 0x265220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265228: movss [0x0054F580], xmm0
	X86_MEM_WRITE_u32(base, 0x54F580u, ctx.xmm[0].u32[0]);
	// 0x265230: ret
	return;
}

void sub_265240(X86Context& ctx, uint8_t* base) {
	// 0x265240: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x265248: movss [0x0054F574], xmm0
	X86_MEM_WRITE_u32(base, 0x54F574u, ctx.xmm[0].u32[0]);
	// 0x265250: ret
	return;
}

void sub_265260(X86Context& ctx, uint8_t* base) {
	// 0x265260: movss xmm0, dword ptr [0x0054F574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F574u);
	// 0x265268: movss [0x0054F57C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F57Cu, ctx.xmm[0].u32[0]);
	// 0x265270: ret
	return;
}

void sub_265280(X86Context& ctx, uint8_t* base) {
	// 0x265280: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265288: movss [0x0054F4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4D4u, ctx.xmm[0].u32[0]);
	// 0x265290: ret
	return;
}

void sub_2652A0(X86Context& ctx, uint8_t* base) {
	// 0x2652A0: movss xmm0, dword ptr [0x0054F4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F4D8u);
	// 0x2652A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2652B0: movss [0x0054F578], xmm0
	X86_MEM_WRITE_u32(base, 0x54F578u, ctx.xmm[0].u32[0]);
	// 0x2652B8: ret
	return;
}

void sub_2652C0(X86Context& ctx, uint8_t* base) {
	// 0x2652C0: movss xmm0, dword ptr [0x0054F4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F4D8u);
	// 0x2652C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2652D0: movss [0x0054F4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4E8u, ctx.xmm[0].u32[0]);
	// 0x2652D8: ret
	return;
}

void sub_2652E0(X86Context& ctx, uint8_t* base) {
	// 0x2652E0: movss xmm0, dword ptr [0x0054F4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F4D8u);
	// 0x2652E8: subss xmm0, [0x0054F4E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F4E8u);
	// 0x2652F0: movss [0x0054F4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4E0u, ctx.xmm[0].u32[0]);
	// 0x2652F8: ret
	return;
}

void sub_265300(X86Context& ctx, uint8_t* base) {
	// 0x265300: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x265308: movss [0x0054F4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4F8u, ctx.xmm[0].u32[0]);
	// 0x265310: ret
	return;
}

void sub_265320(X86Context& ctx, uint8_t* base) {
	// 0x265320: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x265328: movss [0x0054F4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4DCu, ctx.xmm[0].u32[0]);
	// 0x265330: ret
	return;
}

void sub_265340(X86Context& ctx, uint8_t* base) {
	// 0x265340: movss xmm0, dword ptr [0x003B17E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x265348: movss [0x0054F4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F4E4u, ctx.xmm[0].u32[0]);
	// 0x265350: ret
	return;
}

void sub_265360(X86Context& ctx, uint8_t* base) {
	// 0x265360: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x265368: movss [0x0054F5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5A4u, ctx.xmm[0].u32[0]);
	// 0x265370: ret
	return;
}

void sub_265380(X86Context& ctx, uint8_t* base) {
	// 0x265380: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x265388: movss [0x0054F5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5B8u, ctx.xmm[0].u32[0]);
	// 0x265390: ret
	return;
}

void sub_2653A0(X86Context& ctx, uint8_t* base) {
	// 0x2653A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2653A8: movss [0x0054F59C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F59Cu, ctx.xmm[0].u32[0]);
	// 0x2653B0: ret
	return;
}

void sub_2653C0(X86Context& ctx, uint8_t* base) {
	// 0x2653C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2653C8: movss [0x0054F584], xmm0
	X86_MEM_WRITE_u32(base, 0x54F584u, ctx.xmm[0].u32[0]);
	// 0x2653D0: ret
	return;
}

void sub_2653E0(X86Context& ctx, uint8_t* base) {
	// 0x2653E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2653E8: movss [0x0054F5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5A8u, ctx.xmm[0].u32[0]);
	// 0x2653F0: ret
	return;
}

void sub_265400(X86Context& ctx, uint8_t* base) {
	// 0x265400: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x265408: movss [0x0054F588], xmm0
	X86_MEM_WRITE_u32(base, 0x54F588u, ctx.xmm[0].u32[0]);
	// 0x265410: ret
	return;
}

void sub_265420(X86Context& ctx, uint8_t* base) {
	// 0x265420: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x265428: movss [0x0054F5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5C0u, ctx.xmm[0].u32[0]);
	// 0x265430: ret
	return;
}

void sub_265440(X86Context& ctx, uint8_t* base) {
	// 0x265440: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x265448: movss [0x0054F5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5A0u, ctx.xmm[0].u32[0]);
	// 0x265450: ret
	return;
}

void sub_265460(X86Context& ctx, uint8_t* base) {
	// 0x265460: movss xmm0, dword ptr [0x0054F5C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5C0u);
	// 0x265468: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x265470: movss [0x0054F590], xmm0
	X86_MEM_WRITE_u32(base, 0x54F590u, ctx.xmm[0].u32[0]);
	// 0x265478: ret
	return;
}

void sub_265480(X86Context& ctx, uint8_t* base) {
	// 0x265480: movss xmm0, dword ptr [0x0054F5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5A0u);
	// 0x265488: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x265490: movss [0x0054F5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5BCu, ctx.xmm[0].u32[0]);
	// 0x265498: ret
	return;
}

void sub_2654A0(X86Context& ctx, uint8_t* base) {
	// 0x2654A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2654A8: movss [0x0054F5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5CCu, ctx.xmm[0].u32[0]);
	// 0x2654B0: ret
	return;
}

void sub_2654C0(X86Context& ctx, uint8_t* base) {
	// 0x2654C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2654C8: movss [0x0054F5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5C4u, ctx.xmm[0].u32[0]);
	// 0x2654D0: ret
	return;
}

void sub_2654E0(X86Context& ctx, uint8_t* base) {
	// 0x2654E0: movss xmm0, dword ptr [0x0054F5C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5C4u);
	// 0x2654E8: movss [0x0054F5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5C8u, ctx.xmm[0].u32[0]);
	// 0x2654F0: ret
	return;
}

void sub_265500(X86Context& ctx, uint8_t* base) {
	// 0x265500: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265508: movss [0x0054F598], xmm0
	X86_MEM_WRITE_u32(base, 0x54F598u, ctx.xmm[0].u32[0]);
	// 0x265510: ret
	return;
}

void sub_265520(X86Context& ctx, uint8_t* base) {
	// 0x265520: movss xmm0, dword ptr [0x0054F5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5A0u);
	// 0x265528: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x265530: movss [0x0054F594], xmm0
	X86_MEM_WRITE_u32(base, 0x54F594u, ctx.xmm[0].u32[0]);
	// 0x265538: ret
	return;
}

void sub_265540(X86Context& ctx, uint8_t* base) {
	// 0x265540: movss xmm0, dword ptr [0x0054F5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5A0u);
	// 0x265548: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x265550: movss [0x0054F5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5B4u, ctx.xmm[0].u32[0]);
	// 0x265558: ret
	return;
}

void sub_265560(X86Context& ctx, uint8_t* base) {
	// 0x265560: movss xmm0, dword ptr [0x0054F5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5A0u);
	// 0x265568: subss xmm0, [0x0054F5B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F5B4u);
	// 0x265570: movss [0x0054F58C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F58Cu, ctx.xmm[0].u32[0]);
	// 0x265578: ret
	return;
}

void sub_265580(X86Context& ctx, uint8_t* base) {
	// 0x265580: movss xmm0, dword ptr [0x0054F5C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5C0u);
	// 0x265588: movss [0x0054F5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5B0u, ctx.xmm[0].u32[0]);
	// 0x265590: ret
	return;
}

void sub_2655A0(X86Context& ctx, uint8_t* base) {
	// 0x2655A0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2655A8: divss xmm0, [0x0054F5B0]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x54F5B0u);
	// 0x2655B0: movss [0x003FCD30], xmm0
	X86_MEM_WRITE_u32(base, 0x3FCD30u, ctx.xmm[0].u32[0]);
	// 0x2655B8: ret
	return;
}

void sub_2655C0(X86Context& ctx, uint8_t* base) {
	// 0x2655C0: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2655C8: movss [0x0054F5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5ACu, ctx.xmm[0].u32[0]);
	// 0x2655D0: ret
	return;
}

void sub_2655E0(X86Context& ctx, uint8_t* base) {
	// 0x2655E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2655E8: movss [0x0054F5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5F0u, ctx.xmm[0].u32[0]);
	// 0x2655F0: ret
	return;
}

void sub_265600(X86Context& ctx, uint8_t* base) {
	// 0x265600: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x265608: movss [0x0054F5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5FCu, ctx.xmm[0].u32[0]);
	// 0x265610: ret
	return;
}

void sub_265620(X86Context& ctx, uint8_t* base) {
	// 0x265620: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x265628: movss [0x0054F5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5ECu, ctx.xmm[0].u32[0]);
	// 0x265630: ret
	return;
}

void sub_265640(X86Context& ctx, uint8_t* base) {
	// 0x265640: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x265648: movss [0x0054F5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5D0u, ctx.xmm[0].u32[0]);
	// 0x265650: ret
	return;
}

void sub_265660(X86Context& ctx, uint8_t* base) {
	// 0x265660: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x265668: movss [0x0054F5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5F4u, ctx.xmm[0].u32[0]);
	// 0x265670: ret
	return;
}

void sub_265680(X86Context& ctx, uint8_t* base) {
	// 0x265680: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x265688: movss [0x0054F5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5D8u, ctx.xmm[0].u32[0]);
	// 0x265690: ret
	return;
}

void sub_2656A0(X86Context& ctx, uint8_t* base) {
	// 0x2656A0: movss xmm0, dword ptr [0x0054F5F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5F4u);
	// 0x2656A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2656B0: movss [0x0054F604], xmm0
	X86_MEM_WRITE_u32(base, 0x54F604u, ctx.xmm[0].u32[0]);
	// 0x2656B8: ret
	return;
}

void sub_2656C0(X86Context& ctx, uint8_t* base) {
	// 0x2656C0: movss xmm0, dword ptr [0x0054F5D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5D8u);
	// 0x2656C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2656D0: movss [0x0054F600], xmm0
	X86_MEM_WRITE_u32(base, 0x54F600u, ctx.xmm[0].u32[0]);
	// 0x2656D8: ret
	return;
}

void sub_2656E0(X86Context& ctx, uint8_t* base) {
	// 0x2656E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2656E8: movss [0x0054F614], xmm0
	X86_MEM_WRITE_u32(base, 0x54F614u, ctx.xmm[0].u32[0]);
	// 0x2656F0: ret
	return;
}

void sub_265700(X86Context& ctx, uint8_t* base) {
	// 0x265700: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x265708: movss [0x0054F608], xmm0
	X86_MEM_WRITE_u32(base, 0x54F608u, ctx.xmm[0].u32[0]);
	// 0x265710: ret
	return;
}

void sub_265720(X86Context& ctx, uint8_t* base) {
	// 0x265720: movss xmm0, dword ptr [0x0054F608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F608u);
	// 0x265728: movss [0x0054F610], xmm0
	X86_MEM_WRITE_u32(base, 0x54F610u, ctx.xmm[0].u32[0]);
	// 0x265730: ret
	return;
}

void sub_265740(X86Context& ctx, uint8_t* base) {
	// 0x265740: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265748: movss [0x0054F5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5D4u, ctx.xmm[0].u32[0]);
	// 0x265750: ret
	return;
}

void sub_265760(X86Context& ctx, uint8_t* base) {
	// 0x265760: movss xmm0, dword ptr [0x0054F5D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5D8u);
	// 0x265768: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x265770: movss [0x0054F60C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F60Cu, ctx.xmm[0].u32[0]);
	// 0x265778: ret
	return;
}

void sub_265780(X86Context& ctx, uint8_t* base) {
	// 0x265780: movss xmm0, dword ptr [0x0054F5D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5D8u);
	// 0x265788: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x265790: movss [0x0054F5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5E8u, ctx.xmm[0].u32[0]);
	// 0x265798: ret
	return;
}

void sub_2657A0(X86Context& ctx, uint8_t* base) {
	// 0x2657A0: movss xmm0, dword ptr [0x0054F5D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F5D8u);
	// 0x2657A8: subss xmm0, [0x0054F5E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F5E8u);
	// 0x2657B0: movss [0x0054F5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5E0u, ctx.xmm[0].u32[0]);
	// 0x2657B8: ret
	return;
}

void sub_2657C0(X86Context& ctx, uint8_t* base) {
	// 0x2657C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2657C8: movss [0x0054F5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5F8u, ctx.xmm[0].u32[0]);
	// 0x2657D0: ret
	return;
}

void sub_2657E0(X86Context& ctx, uint8_t* base) {
	// 0x2657E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2657E8: movss [0x0054F5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5DCu, ctx.xmm[0].u32[0]);
	// 0x2657F0: ret
	return;
}

void sub_265800(X86Context& ctx, uint8_t* base) {
	// 0x265800: movss xmm0, dword ptr [0x003B1A68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A68u);
	// 0x265808: movss [0x0054F5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F5E4u, ctx.xmm[0].u32[0]);
	// 0x265810: ret
	return;
}

void sub_265820(X86Context& ctx, uint8_t* base) {
	// 0x265820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x265828: movss [0x0054F638], xmm0
	X86_MEM_WRITE_u32(base, 0x54F638u, ctx.xmm[0].u32[0]);
	// 0x265830: ret
	return;
}

void sub_265840(X86Context& ctx, uint8_t* base) {
	// 0x265840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x265848: movss [0x0054F644], xmm0
	X86_MEM_WRITE_u32(base, 0x54F644u, ctx.xmm[0].u32[0]);
	// 0x265850: ret
	return;
}

void sub_265860(X86Context& ctx, uint8_t* base) {
	// 0x265860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x265868: movss [0x0054F630], xmm0
	X86_MEM_WRITE_u32(base, 0x54F630u, ctx.xmm[0].u32[0]);
	// 0x265870: ret
	return;
}

void sub_265880(X86Context& ctx, uint8_t* base) {
	// 0x265880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x265888: movss [0x0054F618], xmm0
	X86_MEM_WRITE_u32(base, 0x54F618u, ctx.xmm[0].u32[0]);
	// 0x265890: ret
	return;
}

void sub_2658A0(X86Context& ctx, uint8_t* base) {
	// 0x2658A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2658A8: movss [0x0054F63C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F63Cu, ctx.xmm[0].u32[0]);
	// 0x2658B0: ret
	return;
}

void sub_2658C0(X86Context& ctx, uint8_t* base) {
	// 0x2658C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2658C8: movss [0x0054F61C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F61Cu, ctx.xmm[0].u32[0]);
	// 0x2658D0: ret
	return;
}

void sub_2658E0(X86Context& ctx, uint8_t* base) {
	// 0x2658E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2658E8: movss [0x0054F64C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F64Cu, ctx.xmm[0].u32[0]);
	// 0x2658F0: ret
	return;
}

void sub_265900(X86Context& ctx, uint8_t* base) {
	// 0x265900: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x265908: movss [0x0054F634], xmm0
	X86_MEM_WRITE_u32(base, 0x54F634u, ctx.xmm[0].u32[0]);
	// 0x265910: ret
	return;
}

void sub_265920(X86Context& ctx, uint8_t* base) {
	// 0x265920: movss xmm0, dword ptr [0x0054F64C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F64Cu);
	// 0x265928: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x265930: movss [0x0054F624], xmm0
	X86_MEM_WRITE_u32(base, 0x54F624u, ctx.xmm[0].u32[0]);
	// 0x265938: ret
	return;
}

void sub_265940(X86Context& ctx, uint8_t* base) {
	// 0x265940: movss xmm0, dword ptr [0x0054F634]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F634u);
	// 0x265948: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x265950: movss [0x0054F648], xmm0
	X86_MEM_WRITE_u32(base, 0x54F648u, ctx.xmm[0].u32[0]);
	// 0x265958: ret
	return;
}

void sub_265960(X86Context& ctx, uint8_t* base) {
	// 0x265960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265968: movss [0x0054F658], xmm0
	X86_MEM_WRITE_u32(base, 0x54F658u, ctx.xmm[0].u32[0]);
	// 0x265970: ret
	return;
}

void sub_265980(X86Context& ctx, uint8_t* base) {
	// 0x265980: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x265988: movss [0x0054F650], xmm0
	X86_MEM_WRITE_u32(base, 0x54F650u, ctx.xmm[0].u32[0]);
	// 0x265990: ret
	return;
}

void sub_2659A0(X86Context& ctx, uint8_t* base) {
	// 0x2659A0: movss xmm0, dword ptr [0x0054F650]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F650u);
	// 0x2659A8: movss [0x0054F654], xmm0
	X86_MEM_WRITE_u32(base, 0x54F654u, ctx.xmm[0].u32[0]);
	// 0x2659B0: ret
	return;
}

void sub_2659C0(X86Context& ctx, uint8_t* base) {
	// 0x2659C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2659C8: movss [0x0054F62C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F62Cu, ctx.xmm[0].u32[0]);
	// 0x2659D0: ret
	return;
}

void sub_2659E0(X86Context& ctx, uint8_t* base) {
	// 0x2659E0: movss xmm0, dword ptr [0x0054F634]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F634u);
	// 0x2659E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2659F0: movss [0x0054F628], xmm0
	X86_MEM_WRITE_u32(base, 0x54F628u, ctx.xmm[0].u32[0]);
	// 0x2659F8: ret
	return;
}

void sub_265A00(X86Context& ctx, uint8_t* base) {
	// 0x265A00: movss xmm0, dword ptr [0x0054F634]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F634u);
	// 0x265A08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x265A10: movss [0x0054F640], xmm0
	X86_MEM_WRITE_u32(base, 0x54F640u, ctx.xmm[0].u32[0]);
	// 0x265A18: ret
	return;
}

void sub_265A20(X86Context& ctx, uint8_t* base) {
	// 0x265A20: movss xmm0, dword ptr [0x0054F634]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F634u);
	// 0x265A28: subss xmm0, [0x0054F640]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F640u);
	// 0x265A30: movss [0x0054F620], xmm0
	X86_MEM_WRITE_u32(base, 0x54F620u, ctx.xmm[0].u32[0]);
	// 0x265A38: ret
	return;
}

void sub_265A40(X86Context& ctx, uint8_t* base) {
	// 0x265A40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x265A48: movss [0x0054F6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6C0u, ctx.xmm[0].u32[0]);
	// 0x265A50: ret
	return;
}

void sub_265A60(X86Context& ctx, uint8_t* base) {
	// 0x265A60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x265A68: movss [0x0054F6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6CCu, ctx.xmm[0].u32[0]);
	// 0x265A70: ret
	return;
}

void sub_265A80(X86Context& ctx, uint8_t* base) {
	// 0x265A80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x265A88: movss [0x0054F67C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F67Cu, ctx.xmm[0].u32[0]);
	// 0x265A90: ret
	return;
}

void sub_265AA0(X86Context& ctx, uint8_t* base) {
	// 0x265AA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x265AA8: movss [0x0054F65C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F65Cu, ctx.xmm[0].u32[0]);
	// 0x265AB0: ret
	return;
}

void sub_265AC0(X86Context& ctx, uint8_t* base) {
	// 0x265AC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x265AC8: movss [0x0054F6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6C4u, ctx.xmm[0].u32[0]);
	// 0x265AD0: ret
	return;
}

void sub_265AE0(X86Context& ctx, uint8_t* base) {
	// 0x265AE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x265AE8: movss [0x0054F660], xmm0
	X86_MEM_WRITE_u32(base, 0x54F660u, ctx.xmm[0].u32[0]);
	// 0x265AF0: ret
	return;
}

void sub_265B00(X86Context& ctx, uint8_t* base) {
	// 0x265B00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x265B08: movss [0x0054F6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6D8u, ctx.xmm[0].u32[0]);
	// 0x265B10: ret
	return;
}

void sub_265B20(X86Context& ctx, uint8_t* base) {
	// 0x265B20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x265B28: movss [0x0054F6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6B8u, ctx.xmm[0].u32[0]);
	// 0x265B30: ret
	return;
}

void sub_265B40(X86Context& ctx, uint8_t* base) {
	// 0x265B40: movss xmm0, dword ptr [0x0054F6D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6D8u);
	// 0x265B48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x265B50: movss [0x0054F66C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F66Cu, ctx.xmm[0].u32[0]);
	// 0x265B58: ret
	return;
}

void sub_265B60(X86Context& ctx, uint8_t* base) {
	// 0x265B60: movss xmm0, dword ptr [0x0054F6B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6B8u);
	// 0x265B68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x265B70: movss [0x0054F6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6D0u, ctx.xmm[0].u32[0]);
	// 0x265B78: ret
	return;
}

void sub_265B80(X86Context& ctx, uint8_t* base) {
	// 0x265B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265B88: movss [0x0054F6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6E8u, ctx.xmm[0].u32[0]);
	// 0x265B90: ret
	return;
}

void sub_265BA0(X86Context& ctx, uint8_t* base) {
	// 0x265BA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x265BA8: movss [0x0054F6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6DCu, ctx.xmm[0].u32[0]);
	// 0x265BB0: ret
	return;
}

void sub_265BC0(X86Context& ctx, uint8_t* base) {
	// 0x265BC0: movss xmm0, dword ptr [0x0054F6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6DCu);
	// 0x265BC8: movss [0x0054F6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6E4u, ctx.xmm[0].u32[0]);
	// 0x265BD0: ret
	return;
}

void sub_265BE0(X86Context& ctx, uint8_t* base) {
	// 0x265BE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265BE8: movss [0x0054F674], xmm0
	X86_MEM_WRITE_u32(base, 0x54F674u, ctx.xmm[0].u32[0]);
	// 0x265BF0: ret
	return;
}

void sub_265C00(X86Context& ctx, uint8_t* base) {
	// 0x265C00: movss xmm0, dword ptr [0x0054F6B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6B8u);
	// 0x265C08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x265C10: movss [0x0054F670], xmm0
	X86_MEM_WRITE_u32(base, 0x54F670u, ctx.xmm[0].u32[0]);
	// 0x265C18: ret
	return;
}

void sub_265C20(X86Context& ctx, uint8_t* base) {
	// 0x265C20: movss xmm0, dword ptr [0x0054F6B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6B8u);
	// 0x265C28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x265C30: movss [0x0054F6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6C8u, ctx.xmm[0].u32[0]);
	// 0x265C38: ret
	return;
}

void sub_265C40(X86Context& ctx, uint8_t* base) {
	// 0x265C40: movss xmm0, dword ptr [0x0054F6B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6B8u);
	// 0x265C48: subss xmm0, [0x0054F6C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F6C8u);
	// 0x265C50: movss [0x0054F668], xmm0
	X86_MEM_WRITE_u32(base, 0x54F668u, ctx.xmm[0].u32[0]);
	// 0x265C58: ret
	return;
}

void sub_265C60(X86Context& ctx, uint8_t* base) {
	// 0x265C60: movss xmm0, dword ptr [0x003B1FF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1FF4u);
	// 0x265C68: movss [0x0054F6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6D4u, ctx.xmm[0].u32[0]);
	// 0x265C70: ret
	return;
}

void sub_265C80(X86Context& ctx, uint8_t* base) {
	// 0x265C80: movss xmm0, dword ptr [0x003B1FF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1FF0u);
	// 0x265C88: movss [0x0054F678], xmm0
	X86_MEM_WRITE_u32(base, 0x54F678u, ctx.xmm[0].u32[0]);
	// 0x265C90: ret
	return;
}

void sub_265CA0(X86Context& ctx, uint8_t* base) {
	// 0x265CA0: movss xmm0, dword ptr [0x003B16F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16F4u);
	// 0x265CA8: movss [0x0054F664], xmm0
	X86_MEM_WRITE_u32(base, 0x54F664u, ctx.xmm[0].u32[0]);
	// 0x265CB0: ret
	return;
}

void sub_265CC0(X86Context& ctx, uint8_t* base) {
	// 0x265CC0: movss xmm0, dword ptr [0x003B1FF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1FF0u);
	// 0x265CC8: movss [0x0054F6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6E0u, ctx.xmm[0].u32[0]);
	// 0x265CD0: ret
	return;
}

void sub_265CE0(X86Context& ctx, uint8_t* base) {
	// 0x265CE0: movss xmm0, dword ptr [0x0054F664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F664u);
	// 0x265CE8: movss xmm1, dword ptr [0x0054F6E0]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x54F6E0u);
	// 0x265CF0: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x265CF4: mulss xmm1, [0x003A2D1C]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3A2D1Cu);
	// 0x265CFC: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x265D00: movss [0x0054F6BC], xmm1
	X86_MEM_WRITE_u32(base, 0x54F6BCu, ctx.xmm[1].u32[0]);
	// 0x265D08: ret
	return;
}

void sub_265D10(X86Context& ctx, uint8_t* base) {
	// 0x265D10: movss xmm1, dword ptr [0x0054F664]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x54F664u);
	// 0x265D18: movss xmm0, dword ptr [0x0054F678]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F678u);
	// 0x265D20: movss xmm2, dword ptr [0x0054F6D4]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x54F6D4u);
	// 0x265D28: movss [0x0054F684], xmm1
	X86_MEM_WRITE_u32(base, 0x54F684u, ctx.xmm[1].u32[0]);
	// 0x265D30: movss [0x0054F68C], xmm1
	X86_MEM_WRITE_u32(base, 0x54F68Cu, ctx.xmm[1].u32[0]);
	// 0x265D38: movss [0x0054F694], xmm1
	X86_MEM_WRITE_u32(base, 0x54F694u, ctx.xmm[1].u32[0]);
	// 0x265D40: movss xmm1, dword ptr [0x0054F6BC]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x54F6BCu);
	// 0x265D48: movss [0x0054F69C], xmm1
	X86_MEM_WRITE_u32(base, 0x54F69Cu, ctx.xmm[1].u32[0]);
	// 0x265D50: movss xmm1, dword ptr [0x0054F6E0]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x54F6E0u);
	// 0x265D58: movss [0x0054F680], xmm0
	X86_MEM_WRITE_u32(base, 0x54F680u, ctx.xmm[0].u32[0]);
	// 0x265D60: movss [0x0054F688], xmm2
	X86_MEM_WRITE_u32(base, 0x54F688u, ctx.xmm[2].u32[0]);
	// 0x265D68: movss [0x0054F690], xmm0
	X86_MEM_WRITE_u32(base, 0x54F690u, ctx.xmm[0].u32[0]);
	// 0x265D70: movss [0x0054F698], xmm2
	X86_MEM_WRITE_u32(base, 0x54F698u, ctx.xmm[2].u32[0]);
	// 0x265D78: movss [0x0054F6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6A0u, ctx.xmm[0].u32[0]);
	// 0x265D80: movss [0x0054F6A4], xmm1
	X86_MEM_WRITE_u32(base, 0x54F6A4u, ctx.xmm[1].u32[0]);
	// 0x265D88: movss [0x0054F6A8], xmm2
	X86_MEM_WRITE_u32(base, 0x54F6A8u, ctx.xmm[2].u32[0]);
	// 0x265D90: movss [0x0054F6AC], xmm1
	X86_MEM_WRITE_u32(base, 0x54F6ACu, ctx.xmm[1].u32[0]);
	// 0x265D98: movss [0x0054F6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6B0u, ctx.xmm[0].u32[0]);
	// 0x265DA0: movss [0x0054F6B4], xmm1
	X86_MEM_WRITE_u32(base, 0x54F6B4u, ctx.xmm[1].u32[0]);
	// 0x265DA8: ret
	return;
}

void sub_265DB0(X86Context& ctx, uint8_t* base) {
	// 0x265DB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x265DB8: movss [0x0054F70C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F70Cu, ctx.xmm[0].u32[0]);
	// 0x265DC0: ret
	return;
}

void sub_265DD0(X86Context& ctx, uint8_t* base) {
	// 0x265DD0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x265DD8: movss [0x0054F718], xmm0
	X86_MEM_WRITE_u32(base, 0x54F718u, ctx.xmm[0].u32[0]);
	// 0x265DE0: ret
	return;
}

void sub_265DF0(X86Context& ctx, uint8_t* base) {
	// 0x265DF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x265DF8: movss [0x0054F704], xmm0
	X86_MEM_WRITE_u32(base, 0x54F704u, ctx.xmm[0].u32[0]);
	// 0x265E00: ret
	return;
}

void sub_265E10(X86Context& ctx, uint8_t* base) {
	// 0x265E10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x265E18: movss [0x0054F6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6ECu, ctx.xmm[0].u32[0]);
	// 0x265E20: ret
	return;
}

void sub_265E30(X86Context& ctx, uint8_t* base) {
	// 0x265E30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x265E38: movss [0x0054F710], xmm0
	X86_MEM_WRITE_u32(base, 0x54F710u, ctx.xmm[0].u32[0]);
	// 0x265E40: ret
	return;
}

void sub_265E50(X86Context& ctx, uint8_t* base) {
	// 0x265E50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x265E58: movss [0x0054F6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6F4u, ctx.xmm[0].u32[0]);
	// 0x265E60: ret
	return;
}

void sub_265E70(X86Context& ctx, uint8_t* base) {
	// 0x265E70: movss xmm0, dword ptr [0x0054F710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F710u);
	// 0x265E78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x265E80: movss [0x0054F720], xmm0
	X86_MEM_WRITE_u32(base, 0x54F720u, ctx.xmm[0].u32[0]);
	// 0x265E88: ret
	return;
}

void sub_265E90(X86Context& ctx, uint8_t* base) {
	// 0x265E90: movss xmm0, dword ptr [0x0054F6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6F4u);
	// 0x265E98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x265EA0: movss [0x0054F71C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F71Cu, ctx.xmm[0].u32[0]);
	// 0x265EA8: ret
	return;
}

void sub_265EB0(X86Context& ctx, uint8_t* base) {
	// 0x265EB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265EB8: movss [0x0054F730], xmm0
	X86_MEM_WRITE_u32(base, 0x54F730u, ctx.xmm[0].u32[0]);
	// 0x265EC0: ret
	return;
}

void sub_265ED0(X86Context& ctx, uint8_t* base) {
	// 0x265ED0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x265ED8: movss [0x0054F724], xmm0
	X86_MEM_WRITE_u32(base, 0x54F724u, ctx.xmm[0].u32[0]);
	// 0x265EE0: ret
	return;
}

void sub_265EF0(X86Context& ctx, uint8_t* base) {
	// 0x265EF0: movss xmm0, dword ptr [0x0054F724]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F724u);
	// 0x265EF8: movss [0x0054F72C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F72Cu, ctx.xmm[0].u32[0]);
	// 0x265F00: ret
	return;
}

void sub_265F10(X86Context& ctx, uint8_t* base) {
	// 0x265F10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x265F18: movss [0x0054F6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6F0u, ctx.xmm[0].u32[0]);
	// 0x265F20: ret
	return;
}

void sub_265F30(X86Context& ctx, uint8_t* base) {
	// 0x265F30: movss xmm0, dword ptr [0x0054F6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6F4u);
	// 0x265F38: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x265F40: movss [0x0054F728], xmm0
	X86_MEM_WRITE_u32(base, 0x54F728u, ctx.xmm[0].u32[0]);
	// 0x265F48: ret
	return;
}

void sub_265F50(X86Context& ctx, uint8_t* base) {
	// 0x265F50: movss xmm0, dword ptr [0x0054F6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6F4u);
	// 0x265F58: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x265F60: movss [0x0054F700], xmm0
	X86_MEM_WRITE_u32(base, 0x54F700u, ctx.xmm[0].u32[0]);
	// 0x265F68: ret
	return;
}

void sub_265F70(X86Context& ctx, uint8_t* base) {
	// 0x265F70: movss xmm0, dword ptr [0x0054F6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F6F4u);
	// 0x265F78: subss xmm0, [0x0054F700]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F700u);
	// 0x265F80: movss [0x0054F6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6FCu, ctx.xmm[0].u32[0]);
	// 0x265F88: ret
	return;
}

void sub_265F90(X86Context& ctx, uint8_t* base) {
	// 0x265F90: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x265F98: movss [0x0054F714], xmm0
	X86_MEM_WRITE_u32(base, 0x54F714u, ctx.xmm[0].u32[0]);
	// 0x265FA0: ret
	return;
}

void sub_265FB0(X86Context& ctx, uint8_t* base) {
	// 0x265FB0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x265FB8: movss [0x0054F6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F6F8u, ctx.xmm[0].u32[0]);
	// 0x265FC0: ret
	return;
}

void sub_265FD0(X86Context& ctx, uint8_t* base) {
	// 0x265FD0: movss xmm0, dword ptr [0x003A795C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A795Cu);
	// 0x265FD8: movss [0x0054F708], xmm0
	X86_MEM_WRITE_u32(base, 0x54F708u, ctx.xmm[0].u32[0]);
	// 0x265FE0: ret
	return;
}

void sub_265FF0(X86Context& ctx, uint8_t* base) {
	// 0x265FF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x265FF8: movss [0x0054F750], xmm0
	X86_MEM_WRITE_u32(base, 0x54F750u, ctx.xmm[0].u32[0]);
	// 0x266000: ret
	return;
}

void sub_266010(X86Context& ctx, uint8_t* base) {
	// 0x266010: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266018: movss [0x0054F75C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F75Cu, ctx.xmm[0].u32[0]);
	// 0x266020: ret
	return;
}

void sub_266030(X86Context& ctx, uint8_t* base) {
	// 0x266030: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266038: movss [0x0054F74C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F74Cu, ctx.xmm[0].u32[0]);
	// 0x266040: ret
	return;
}

void sub_266050(X86Context& ctx, uint8_t* base) {
	// 0x266050: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x266058: movss [0x0054F734], xmm0
	X86_MEM_WRITE_u32(base, 0x54F734u, ctx.xmm[0].u32[0]);
	// 0x266060: ret
	return;
}

void sub_266070(X86Context& ctx, uint8_t* base) {
	// 0x266070: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x266078: movss [0x0054F754], xmm0
	X86_MEM_WRITE_u32(base, 0x54F754u, ctx.xmm[0].u32[0]);
	// 0x266080: ret
	return;
}

void sub_266090(X86Context& ctx, uint8_t* base) {
	// 0x266090: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x266098: movss [0x0054F73C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F73Cu, ctx.xmm[0].u32[0]);
	// 0x2660A0: ret
	return;
}

void sub_2660B0(X86Context& ctx, uint8_t* base) {
	// 0x2660B0: movss xmm0, dword ptr [0x0054F754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F754u);
	// 0x2660B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2660C0: movss [0x0054F764], xmm0
	X86_MEM_WRITE_u32(base, 0x54F764u, ctx.xmm[0].u32[0]);
	// 0x2660C8: ret
	return;
}

void sub_2660D0(X86Context& ctx, uint8_t* base) {
	// 0x2660D0: movss xmm0, dword ptr [0x0054F73C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F73Cu);
	// 0x2660D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2660E0: movss [0x0054F760], xmm0
	X86_MEM_WRITE_u32(base, 0x54F760u, ctx.xmm[0].u32[0]);
	// 0x2660E8: ret
	return;
}

void sub_2660F0(X86Context& ctx, uint8_t* base) {
	// 0x2660F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2660F8: movss [0x0054F774], xmm0
	X86_MEM_WRITE_u32(base, 0x54F774u, ctx.xmm[0].u32[0]);
	// 0x266100: ret
	return;
}

void sub_266110(X86Context& ctx, uint8_t* base) {
	// 0x266110: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266118: movss [0x0054F768], xmm0
	X86_MEM_WRITE_u32(base, 0x54F768u, ctx.xmm[0].u32[0]);
	// 0x266120: ret
	return;
}

void sub_266130(X86Context& ctx, uint8_t* base) {
	// 0x266130: movss xmm0, dword ptr [0x0054F768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F768u);
	// 0x266138: movss [0x0054F770], xmm0
	X86_MEM_WRITE_u32(base, 0x54F770u, ctx.xmm[0].u32[0]);
	// 0x266140: ret
	return;
}

void sub_266150(X86Context& ctx, uint8_t* base) {
	// 0x266150: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266158: movss [0x0054F738], xmm0
	X86_MEM_WRITE_u32(base, 0x54F738u, ctx.xmm[0].u32[0]);
	// 0x266160: ret
	return;
}

void sub_266170(X86Context& ctx, uint8_t* base) {
	// 0x266170: movss xmm0, dword ptr [0x0054F73C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F73Cu);
	// 0x266178: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x266180: movss [0x0054F76C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F76Cu, ctx.xmm[0].u32[0]);
	// 0x266188: ret
	return;
}

void sub_266190(X86Context& ctx, uint8_t* base) {
	// 0x266190: movss xmm0, dword ptr [0x0054F73C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F73Cu);
	// 0x266198: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2661A0: movss [0x0054F748], xmm0
	X86_MEM_WRITE_u32(base, 0x54F748u, ctx.xmm[0].u32[0]);
	// 0x2661A8: ret
	return;
}

void sub_2661B0(X86Context& ctx, uint8_t* base) {
	// 0x2661B0: movss xmm0, dword ptr [0x0054F73C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F73Cu);
	// 0x2661B8: subss xmm0, [0x0054F748]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F748u);
	// 0x2661C0: movss [0x0054F744], xmm0
	X86_MEM_WRITE_u32(base, 0x54F744u, ctx.xmm[0].u32[0]);
	// 0x2661C8: ret
	return;
}

void sub_2661D0(X86Context& ctx, uint8_t* base) {
	// 0x2661D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2661D8: movss [0x0054F758], xmm0
	X86_MEM_WRITE_u32(base, 0x54F758u, ctx.xmm[0].u32[0]);
	// 0x2661E0: ret
	return;
}

void sub_2661F0(X86Context& ctx, uint8_t* base) {
	// 0x2661F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2661F8: movss [0x0054F740], xmm0
	X86_MEM_WRITE_u32(base, 0x54F740u, ctx.xmm[0].u32[0]);
	// 0x266200: ret
	return;
}

void sub_266210(X86Context& ctx, uint8_t* base) {
	// 0x266210: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x266218: movss [0x0054F7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7A8u, ctx.xmm[0].u32[0]);
	// 0x266220: ret
	return;
}

void sub_266230(X86Context& ctx, uint8_t* base) {
	// 0x266230: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266238: movss [0x0054F7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7BCu, ctx.xmm[0].u32[0]);
	// 0x266240: ret
	return;
}

void sub_266250(X86Context& ctx, uint8_t* base) {
	// 0x266250: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266258: movss [0x0054F790], xmm0
	X86_MEM_WRITE_u32(base, 0x54F790u, ctx.xmm[0].u32[0]);
	// 0x266260: ret
	return;
}

void sub_266270(X86Context& ctx, uint8_t* base) {
	// 0x266270: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x266278: movss [0x0054F778], xmm0
	X86_MEM_WRITE_u32(base, 0x54F778u, ctx.xmm[0].u32[0]);
	// 0x266280: ret
	return;
}

void sub_266290(X86Context& ctx, uint8_t* base) {
	// 0x266290: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x266298: movss [0x0054F7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7ACu, ctx.xmm[0].u32[0]);
	// 0x2662A0: ret
	return;
}

void sub_2662B0(X86Context& ctx, uint8_t* base) {
	// 0x2662B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2662B8: movss [0x0054F780], xmm0
	X86_MEM_WRITE_u32(base, 0x54F780u, ctx.xmm[0].u32[0]);
	// 0x2662C0: ret
	return;
}

void sub_2662D0(X86Context& ctx, uint8_t* base) {
	// 0x2662D0: movss xmm0, dword ptr [0x0054F7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ACu);
	// 0x2662D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2662E0: movss [0x0054F7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7D0u, ctx.xmm[0].u32[0]);
	// 0x2662E8: ret
	return;
}

void sub_2662F0(X86Context& ctx, uint8_t* base) {
	// 0x2662F0: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x2662F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x266300: movss [0x0054F7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7C0u, ctx.xmm[0].u32[0]);
	// 0x266308: ret
	return;
}

void sub_266310(X86Context& ctx, uint8_t* base) {
	// 0x266310: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266318: movss [0x0054F7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7E0u, ctx.xmm[0].u32[0]);
	// 0x266320: ret
	return;
}

void sub_266330(X86Context& ctx, uint8_t* base) {
	// 0x266330: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266338: movss [0x0054F7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7D4u, ctx.xmm[0].u32[0]);
	// 0x266340: ret
	return;
}

void sub_266350(X86Context& ctx, uint8_t* base) {
	// 0x266350: movss xmm0, dword ptr [0x0054F7D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7D4u);
	// 0x266358: movss [0x0054F7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7DCu, ctx.xmm[0].u32[0]);
	// 0x266360: ret
	return;
}

void sub_266370(X86Context& ctx, uint8_t* base) {
	// 0x266370: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266378: movss [0x0054F77C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F77Cu, ctx.xmm[0].u32[0]);
	// 0x266380: ret
	return;
}

void sub_266390(X86Context& ctx, uint8_t* base) {
	// 0x266390: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x266398: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2663A0: movss [0x0054F7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7D8u, ctx.xmm[0].u32[0]);
	// 0x2663A8: ret
	return;
}

void sub_2663B0(X86Context& ctx, uint8_t* base) {
	// 0x2663B0: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x2663B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2663C0: movss [0x0054F78C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F78Cu, ctx.xmm[0].u32[0]);
	// 0x2663C8: ret
	return;
}

void sub_2663D0(X86Context& ctx, uint8_t* base) {
	// 0x2663D0: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x2663D8: subss xmm0, [0x0054F78C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F78Cu);
	// 0x2663E0: movss [0x0054F788], xmm0
	X86_MEM_WRITE_u32(base, 0x54F788u, ctx.xmm[0].u32[0]);
	// 0x2663E8: ret
	return;
}

void sub_2663F0(X86Context& ctx, uint8_t* base) {
	// 0x2663F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2663F8: movss [0x0054F7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7B8u, ctx.xmm[0].u32[0]);
	// 0x266400: ret
	return;
}

void sub_266410(X86Context& ctx, uint8_t* base) {
	// 0x266410: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x266418: movss [0x0054F784], xmm0
	X86_MEM_WRITE_u32(base, 0x54F784u, ctx.xmm[0].u32[0]);
	// 0x266420: ret
	return;
}

void sub_266430(X86Context& ctx, uint8_t* base) {
	// 0x266430: movss xmm0, dword ptr [0x0054F7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ACu);
	// 0x266438: movss [0x0054F7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7C8u, ctx.xmm[0].u32[0]);
	// 0x266440: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x266448: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x266450: movss [0x0054F7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7CCu, ctx.xmm[0].u32[0]);
	// 0x266458: ret
	return;
}

void sub_266460(X86Context& ctx, uint8_t* base) {
	// 0x266460: movss xmm0, dword ptr [0x0054F7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ACu);
	// 0x266468: movss [0x003FD170], xmm0
	X86_MEM_WRITE_u32(base, 0x3FD170u, ctx.xmm[0].u32[0]);
	// 0x266470: ret
	return;
}

void sub_266480(X86Context& ctx, uint8_t* base) {
	// 0x266480: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x266488: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x266490: movss [0x004A2584], xmm0
	X86_MEM_WRITE_u32(base, 0x4A2584u, ctx.xmm[0].u32[0]);
	// 0x266498: ret
	return;
}

void sub_2664A0(X86Context& ctx, uint8_t* base) {
	// 0x2664A0: movss xmm0, dword ptr [0x0054F7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ACu);
	// 0x2664A8: movss [0x0054F7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7B0u, ctx.xmm[0].u32[0]);
	// 0x2664B0: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x2664B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2664C0: movss [0x0054F7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7B4u, ctx.xmm[0].u32[0]);
	// 0x2664C8: ret
	return;
}

void sub_2664D0(X86Context& ctx, uint8_t* base) {
	// 0x2664D0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2664D8: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2664DB: divss xmm1, [0x0054F7AC]
	ctx.xmm[1].f32[0] /= X86_MEM_READ_F32(base, 0x54F7ACu);
	// 0x2664E3: movss [0x0054F798], xmm1
	X86_MEM_WRITE_u32(base, 0x54F798u, ctx.xmm[1].u32[0]);
	// 0x2664EB: movss xmm1, dword ptr [0x0054F780]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x2664F3: mulss xmm1, [0x003B1728]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2664FB: divss xmm0, xmm1
	ctx.xmm[0].f32[0] /= ctx.xmm[1].f32[0];
	// 0x2664FF: movss [0x0054F79C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F79Cu, ctx.xmm[0].u32[0]);
	// 0x266507: ret
	return;
}

void sub_266510(X86Context& ctx, uint8_t* base) {
	// 0x266510: movss xmm0, dword ptr [0x0054F7D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7D0u);
	// 0x266518: movss [0x0054F7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7A0u, ctx.xmm[0].u32[0]);
	// 0x266520: movss xmm0, dword ptr [0x0054F780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F780u);
	// 0x266528: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x266530: subss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x266538: movss [0x0054F7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7A4u, ctx.xmm[0].u32[0]);
	// 0x266540: ret
	return;
}

void sub_266550(X86Context& ctx, uint8_t* base) {
	// 0x266550: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x266558: movss [0x0054F824], xmm0
	X86_MEM_WRITE_u32(base, 0x54F824u, ctx.xmm[0].u32[0]);
	// 0x266560: ret
	return;
}

void sub_266570(X86Context& ctx, uint8_t* base) {
	// 0x266570: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266578: movss [0x0054F830], xmm0
	X86_MEM_WRITE_u32(base, 0x54F830u, ctx.xmm[0].u32[0]);
	// 0x266580: ret
	return;
}

void sub_266590(X86Context& ctx, uint8_t* base) {
	// 0x266590: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266598: movss [0x0054F820], xmm0
	X86_MEM_WRITE_u32(base, 0x54F820u, ctx.xmm[0].u32[0]);
	// 0x2665A0: ret
	return;
}

void sub_2665B0(X86Context& ctx, uint8_t* base) {
	// 0x2665B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2665B8: movss [0x0054F7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7E4u, ctx.xmm[0].u32[0]);
	// 0x2665C0: ret
	return;
}

void sub_2665D0(X86Context& ctx, uint8_t* base) {
	// 0x2665D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2665D8: movss [0x0054F828], xmm0
	X86_MEM_WRITE_u32(base, 0x54F828u, ctx.xmm[0].u32[0]);
	// 0x2665E0: ret
	return;
}

void sub_2665F0(X86Context& ctx, uint8_t* base) {
	// 0x2665F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2665F8: movss [0x0054F7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7ECu, ctx.xmm[0].u32[0]);
	// 0x266600: ret
	return;
}

void sub_266610(X86Context& ctx, uint8_t* base) {
	// 0x266610: movss xmm0, dword ptr [0x0054F828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F828u);
	// 0x266618: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x266620: movss [0x0054F83C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F83Cu, ctx.xmm[0].u32[0]);
	// 0x266628: ret
	return;
}

void sub_266630(X86Context& ctx, uint8_t* base) {
	// 0x266630: movss xmm0, dword ptr [0x0054F7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ECu);
	// 0x266638: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x266640: movss [0x0054F834], xmm0
	X86_MEM_WRITE_u32(base, 0x54F834u, ctx.xmm[0].u32[0]);
	// 0x266648: ret
	return;
}

void sub_266650(X86Context& ctx, uint8_t* base) {
	// 0x266650: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266658: movss [0x0054F84C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F84Cu, ctx.xmm[0].u32[0]);
	// 0x266660: ret
	return;
}

void sub_266670(X86Context& ctx, uint8_t* base) {
	// 0x266670: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266678: movss [0x0054F840], xmm0
	X86_MEM_WRITE_u32(base, 0x54F840u, ctx.xmm[0].u32[0]);
	// 0x266680: ret
	return;
}

void sub_266690(X86Context& ctx, uint8_t* base) {
	// 0x266690: movss xmm0, dword ptr [0x0054F840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F840u);
	// 0x266698: movss [0x0054F848], xmm0
	X86_MEM_WRITE_u32(base, 0x54F848u, ctx.xmm[0].u32[0]);
	// 0x2666A0: ret
	return;
}

void sub_2666B0(X86Context& ctx, uint8_t* base) {
	// 0x2666B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2666B8: movss [0x0054F7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7E8u, ctx.xmm[0].u32[0]);
	// 0x2666C0: ret
	return;
}

void sub_2666D0(X86Context& ctx, uint8_t* base) {
	// 0x2666D0: movss xmm0, dword ptr [0x0054F7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ECu);
	// 0x2666D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2666E0: movss [0x0054F844], xmm0
	X86_MEM_WRITE_u32(base, 0x54F844u, ctx.xmm[0].u32[0]);
	// 0x2666E8: ret
	return;
}

void sub_2666F0(X86Context& ctx, uint8_t* base) {
	// 0x2666F0: movss xmm0, dword ptr [0x0054F7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ECu);
	// 0x2666F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x266700: movss [0x0054F7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7F8u, ctx.xmm[0].u32[0]);
	// 0x266708: ret
	return;
}

void sub_266710(X86Context& ctx, uint8_t* base) {
	// 0x266710: movss xmm0, dword ptr [0x0054F7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F7ECu);
	// 0x266718: subss xmm0, [0x0054F7F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F7F8u);
	// 0x266720: movss [0x0054F7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7F4u, ctx.xmm[0].u32[0]);
	// 0x266728: ret
	return;
}

void sub_266730(X86Context& ctx, uint8_t* base) {
	// 0x266730: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x266738: movss [0x0054F82C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F82Cu, ctx.xmm[0].u32[0]);
	// 0x266740: ret
	return;
}

void sub_266750(X86Context& ctx, uint8_t* base) {
	// 0x266750: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x266758: movss [0x0054F7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F7F0u, ctx.xmm[0].u32[0]);
	// 0x266760: ret
	return;
}

void sub_266770(X86Context& ctx, uint8_t* base) {
	// 0x266770: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266778: movss [0x0054F838], xmm0
	X86_MEM_WRITE_u32(base, 0x54F838u, ctx.xmm[0].u32[0]);
	// 0x266780: ret
	return;
}

void sub_266790(X86Context& ctx, uint8_t* base) {
	// 0x266790: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x266791: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x266793: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x266796: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x266799: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2667A1: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2667A7: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2667AD: movss xmm0, dword ptr [0x003B1E24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1E24u);
	// 0x2667B5: lea eax, [esp]
	ctx.eax = ctx.esp;
	// 0x2667B8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2667B9: movss [esp+0x14], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.xmm[0].u32[0]);
	// 0x2667BF: movss [esp+0x18], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.xmm[0].u32[0]);
	// 0x2667C5: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2667CD: push 0x54F800
	{ auto _pv = (uint32_t)(5568512); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2667D2: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x2667D6: lea edx, [esp+0x18]
	ctx.edx = ctx.esp + 0x18u;
	// 0x2667DA: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2667E0: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2667E6: call 0x0004D990
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_4D990(ctx, base);
	ctx.esp += 4;
	// 0x2667EB: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2667EE: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2667F0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2667F1: ret
	return;
}

void sub_266800(X86Context& ctx, uint8_t* base) {
	// 0x266800: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x266808: movss [0x0054F86C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F86Cu, ctx.xmm[0].u32[0]);
	// 0x266810: ret
	return;
}

void sub_266820(X86Context& ctx, uint8_t* base) {
	// 0x266820: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266828: movss [0x0054F878], xmm0
	X86_MEM_WRITE_u32(base, 0x54F878u, ctx.xmm[0].u32[0]);
	// 0x266830: ret
	return;
}

void sub_266840(X86Context& ctx, uint8_t* base) {
	// 0x266840: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266848: movss [0x0054F868], xmm0
	X86_MEM_WRITE_u32(base, 0x54F868u, ctx.xmm[0].u32[0]);
	// 0x266850: ret
	return;
}

void sub_266860(X86Context& ctx, uint8_t* base) {
	// 0x266860: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x266868: movss [0x0054F850], xmm0
	X86_MEM_WRITE_u32(base, 0x54F850u, ctx.xmm[0].u32[0]);
	// 0x266870: ret
	return;
}

void sub_266880(X86Context& ctx, uint8_t* base) {
	// 0x266880: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x266888: movss [0x0054F870], xmm0
	X86_MEM_WRITE_u32(base, 0x54F870u, ctx.xmm[0].u32[0]);
	// 0x266890: ret
	return;
}

void sub_2668A0(X86Context& ctx, uint8_t* base) {
	// 0x2668A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2668A8: movss [0x0054F858], xmm0
	X86_MEM_WRITE_u32(base, 0x54F858u, ctx.xmm[0].u32[0]);
	// 0x2668B0: ret
	return;
}

