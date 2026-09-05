#include "x86_recomp_shared.h"

void sub_2626E0(X86Context& ctx, uint8_t* base) {
	// 0x2626E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2626E8: movss [0x0054EB40], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB40u, ctx.xmm[0].u32[0]);
	// 0x2626F0: ret
	return;
}

void sub_262700(X86Context& ctx, uint8_t* base) {
	// 0x262700: movss xmm0, dword ptr [0x0054EB40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB40u);
	// 0x262708: movss [0x0054EB48], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB48u, ctx.xmm[0].u32[0]);
	// 0x262710: ret
	return;
}

void sub_262720(X86Context& ctx, uint8_t* base) {
	// 0x262720: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262728: movss [0x0054EB10], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB10u, ctx.xmm[0].u32[0]);
	// 0x262730: ret
	return;
}

void sub_262740(X86Context& ctx, uint8_t* base) {
	// 0x262740: movss xmm0, dword ptr [0x0054EB14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB14u);
	// 0x262748: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x262750: movss [0x0054EB44], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB44u, ctx.xmm[0].u32[0]);
	// 0x262758: ret
	return;
}

void sub_262760(X86Context& ctx, uint8_t* base) {
	// 0x262760: movss xmm0, dword ptr [0x0054EB14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB14u);
	// 0x262768: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x262770: movss [0x0054EB20], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB20u, ctx.xmm[0].u32[0]);
	// 0x262778: ret
	return;
}

void sub_262780(X86Context& ctx, uint8_t* base) {
	// 0x262780: movss xmm0, dword ptr [0x0054EB14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB14u);
	// 0x262788: subss xmm0, [0x0054EB20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54EB20u);
	// 0x262790: movss [0x0054EB1C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB1Cu, ctx.xmm[0].u32[0]);
	// 0x262798: ret
	return;
}

void sub_2627A0(X86Context& ctx, uint8_t* base) {
	// 0x2627A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2627A8: movss [0x0054EB30], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB30u, ctx.xmm[0].u32[0]);
	// 0x2627B0: ret
	return;
}

void sub_2627C0(X86Context& ctx, uint8_t* base) {
	// 0x2627C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2627C8: movss [0x0054EB18], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB18u, ctx.xmm[0].u32[0]);
	// 0x2627D0: ret
	return;
}

void sub_2627E0(X86Context& ctx, uint8_t* base) {
	// 0x2627E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2627E8: movss [0x0054EB6C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB6Cu, ctx.xmm[0].u32[0]);
	// 0x2627F0: ret
	return;
}

void sub_262800(X86Context& ctx, uint8_t* base) {
	// 0x262800: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262808: movss [0x0054EB78], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB78u, ctx.xmm[0].u32[0]);
	// 0x262810: ret
	return;
}

void sub_262820(X86Context& ctx, uint8_t* base) {
	// 0x262820: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262828: movss [0x0054EB68], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB68u, ctx.xmm[0].u32[0]);
	// 0x262830: ret
	return;
}

void sub_262840(X86Context& ctx, uint8_t* base) {
	// 0x262840: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262848: movss [0x0054EB50], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB50u, ctx.xmm[0].u32[0]);
	// 0x262850: ret
	return;
}

void sub_262860(X86Context& ctx, uint8_t* base) {
	// 0x262860: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x262868: movss [0x0054EB70], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB70u, ctx.xmm[0].u32[0]);
	// 0x262870: ret
	return;
}

void sub_262880(X86Context& ctx, uint8_t* base) {
	// 0x262880: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x262888: movss [0x0054EB58], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB58u, ctx.xmm[0].u32[0]);
	// 0x262890: ret
	return;
}

void sub_2628A0(X86Context& ctx, uint8_t* base) {
	// 0x2628A0: movss xmm0, dword ptr [0x0054EB70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB70u);
	// 0x2628A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2628B0: movss [0x0054EB80], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB80u, ctx.xmm[0].u32[0]);
	// 0x2628B8: ret
	return;
}

void sub_2628C0(X86Context& ctx, uint8_t* base) {
	// 0x2628C0: movss xmm0, dword ptr [0x0054EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB58u);
	// 0x2628C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2628D0: movss [0x0054EB7C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB7Cu, ctx.xmm[0].u32[0]);
	// 0x2628D8: ret
	return;
}

void sub_2628E0(X86Context& ctx, uint8_t* base) {
	// 0x2628E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2628E8: movss [0x0054EB90], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB90u, ctx.xmm[0].u32[0]);
	// 0x2628F0: ret
	return;
}

void sub_262900(X86Context& ctx, uint8_t* base) {
	// 0x262900: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x262908: movss [0x0054EB84], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB84u, ctx.xmm[0].u32[0]);
	// 0x262910: ret
	return;
}

void sub_262920(X86Context& ctx, uint8_t* base) {
	// 0x262920: movss xmm0, dword ptr [0x0054EB84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB84u);
	// 0x262928: movss [0x0054EB8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB8Cu, ctx.xmm[0].u32[0]);
	// 0x262930: ret
	return;
}

void sub_262940(X86Context& ctx, uint8_t* base) {
	// 0x262940: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262948: movss [0x0054EB54], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB54u, ctx.xmm[0].u32[0]);
	// 0x262950: ret
	return;
}

void sub_262960(X86Context& ctx, uint8_t* base) {
	// 0x262960: movss xmm0, dword ptr [0x0054EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB58u);
	// 0x262968: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x262970: movss [0x0054EB88], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB88u, ctx.xmm[0].u32[0]);
	// 0x262978: ret
	return;
}

void sub_262980(X86Context& ctx, uint8_t* base) {
	// 0x262980: movss xmm0, dword ptr [0x0054EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB58u);
	// 0x262988: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x262990: movss [0x0054EB64], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB64u, ctx.xmm[0].u32[0]);
	// 0x262998: ret
	return;
}

void sub_2629A0(X86Context& ctx, uint8_t* base) {
	// 0x2629A0: movss xmm0, dword ptr [0x0054EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB58u);
	// 0x2629A8: subss xmm0, [0x0054EB64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54EB64u);
	// 0x2629B0: movss [0x0054EB60], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB60u, ctx.xmm[0].u32[0]);
	// 0x2629B8: ret
	return;
}

void sub_2629C0(X86Context& ctx, uint8_t* base) {
	// 0x2629C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2629C8: movss [0x0054EB74], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB74u, ctx.xmm[0].u32[0]);
	// 0x2629D0: ret
	return;
}

void sub_2629E0(X86Context& ctx, uint8_t* base) {
	// 0x2629E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2629E8: movss [0x0054EB5C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB5Cu, ctx.xmm[0].u32[0]);
	// 0x2629F0: ret
	return;
}

void sub_262A00(X86Context& ctx, uint8_t* base) {
	// 0x262A00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x262A08: movss [0x0054EB98], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB98u, ctx.xmm[0].u32[0]);
	// 0x262A10: ret
	return;
}

void sub_262A20(X86Context& ctx, uint8_t* base) {
	// 0x262A20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262A28: movss [0x0054EB9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB9Cu, ctx.xmm[0].u32[0]);
	// 0x262A30: ret
	return;
}

void sub_262A40(X86Context& ctx, uint8_t* base) {
	// 0x262A40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262A48: movss [0x0054EB94], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB94u, ctx.xmm[0].u32[0]);
	// 0x262A50: ret
	return;
}

void sub_262A60(X86Context& ctx, uint8_t* base) {
	// 0x262A60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x262A68: movss [0x0054EBBC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBBCu, ctx.xmm[0].u32[0]);
	// 0x262A70: ret
	return;
}

void sub_262A80(X86Context& ctx, uint8_t* base) {
	// 0x262A80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262A88: movss [0x0054EBC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBC8u, ctx.xmm[0].u32[0]);
	// 0x262A90: ret
	return;
}

void sub_262AA0(X86Context& ctx, uint8_t* base) {
	// 0x262AA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262AA8: movss [0x0054EBB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBB8u, ctx.xmm[0].u32[0]);
	// 0x262AB0: ret
	return;
}

void sub_262AC0(X86Context& ctx, uint8_t* base) {
	// 0x262AC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262AC8: movss [0x0054EBA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBA0u, ctx.xmm[0].u32[0]);
	// 0x262AD0: ret
	return;
}

void sub_262AE0(X86Context& ctx, uint8_t* base) {
	// 0x262AE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x262AE8: movss [0x0054EBC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBC0u, ctx.xmm[0].u32[0]);
	// 0x262AF0: ret
	return;
}

void sub_262B00(X86Context& ctx, uint8_t* base) {
	// 0x262B00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x262B08: movss [0x0054EBA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBA8u, ctx.xmm[0].u32[0]);
	// 0x262B10: ret
	return;
}

void sub_262B20(X86Context& ctx, uint8_t* base) {
	// 0x262B20: movss xmm0, dword ptr [0x0054EBC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBC0u);
	// 0x262B28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x262B30: movss [0x0054EBD0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBD0u, ctx.xmm[0].u32[0]);
	// 0x262B38: ret
	return;
}

void sub_262B40(X86Context& ctx, uint8_t* base) {
	// 0x262B40: movss xmm0, dword ptr [0x0054EBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBA8u);
	// 0x262B48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x262B50: movss [0x0054EBCC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBCCu, ctx.xmm[0].u32[0]);
	// 0x262B58: ret
	return;
}

void sub_262B60(X86Context& ctx, uint8_t* base) {
	// 0x262B60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262B68: movss [0x0054EBE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBE0u, ctx.xmm[0].u32[0]);
	// 0x262B70: ret
	return;
}

void sub_262B80(X86Context& ctx, uint8_t* base) {
	// 0x262B80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x262B88: movss [0x0054EBD4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBD4u, ctx.xmm[0].u32[0]);
	// 0x262B90: ret
	return;
}

void sub_262BA0(X86Context& ctx, uint8_t* base) {
	// 0x262BA0: movss xmm0, dword ptr [0x0054EBD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBD4u);
	// 0x262BA8: movss [0x0054EBDC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBDCu, ctx.xmm[0].u32[0]);
	// 0x262BB0: ret
	return;
}

void sub_262BC0(X86Context& ctx, uint8_t* base) {
	// 0x262BC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262BC8: movss [0x0054EBA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBA4u, ctx.xmm[0].u32[0]);
	// 0x262BD0: ret
	return;
}

void sub_262BE0(X86Context& ctx, uint8_t* base) {
	// 0x262BE0: movss xmm0, dword ptr [0x0054EBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBA8u);
	// 0x262BE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x262BF0: movss [0x0054EBD8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBD8u, ctx.xmm[0].u32[0]);
	// 0x262BF8: ret
	return;
}

void sub_262C00(X86Context& ctx, uint8_t* base) {
	// 0x262C00: movss xmm0, dword ptr [0x0054EBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBA8u);
	// 0x262C08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x262C10: movss [0x0054EBB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBB4u, ctx.xmm[0].u32[0]);
	// 0x262C18: ret
	return;
}

void sub_262C20(X86Context& ctx, uint8_t* base) {
	// 0x262C20: movss xmm0, dword ptr [0x0054EBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBA8u);
	// 0x262C28: subss xmm0, [0x0054EBB4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54EBB4u);
	// 0x262C30: movss [0x0054EBB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBB0u, ctx.xmm[0].u32[0]);
	// 0x262C38: ret
	return;
}

void sub_262C40(X86Context& ctx, uint8_t* base) {
	// 0x262C40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x262C48: movss [0x0054EBC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBC4u, ctx.xmm[0].u32[0]);
	// 0x262C50: ret
	return;
}

void sub_262C60(X86Context& ctx, uint8_t* base) {
	// 0x262C60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x262C68: movss [0x0054EBAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBACu, ctx.xmm[0].u32[0]);
	// 0x262C70: ret
	return;
}

void sub_262C80(X86Context& ctx, uint8_t* base) {
	// 0x262C80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x262C88: movss [0x0054EC00], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC00u, ctx.xmm[0].u32[0]);
	// 0x262C90: ret
	return;
}

void sub_262CA0(X86Context& ctx, uint8_t* base) {
	// 0x262CA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262CA8: movss [0x0054EC0C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC0Cu, ctx.xmm[0].u32[0]);
	// 0x262CB0: ret
	return;
}

void sub_262CC0(X86Context& ctx, uint8_t* base) {
	// 0x262CC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262CC8: movss [0x0054EBFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBFCu, ctx.xmm[0].u32[0]);
	// 0x262CD0: ret
	return;
}

void sub_262CE0(X86Context& ctx, uint8_t* base) {
	// 0x262CE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262CE8: movss [0x0054EBE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBE4u, ctx.xmm[0].u32[0]);
	// 0x262CF0: ret
	return;
}

void sub_262D00(X86Context& ctx, uint8_t* base) {
	// 0x262D00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x262D08: movss [0x0054EC04], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC04u, ctx.xmm[0].u32[0]);
	// 0x262D10: ret
	return;
}

void sub_262D20(X86Context& ctx, uint8_t* base) {
	// 0x262D20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x262D28: movss [0x0054EBEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBECu, ctx.xmm[0].u32[0]);
	// 0x262D30: ret
	return;
}

void sub_262D40(X86Context& ctx, uint8_t* base) {
	// 0x262D40: movss xmm0, dword ptr [0x0054EC04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC04u);
	// 0x262D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x262D50: movss [0x0054EC14], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC14u, ctx.xmm[0].u32[0]);
	// 0x262D58: ret
	return;
}

void sub_262D60(X86Context& ctx, uint8_t* base) {
	// 0x262D60: movss xmm0, dword ptr [0x0054EBEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBECu);
	// 0x262D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x262D70: movss [0x0054EC10], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC10u, ctx.xmm[0].u32[0]);
	// 0x262D78: ret
	return;
}

void sub_262D80(X86Context& ctx, uint8_t* base) {
	// 0x262D80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262D88: movss [0x0054EC24], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC24u, ctx.xmm[0].u32[0]);
	// 0x262D90: ret
	return;
}

void sub_262DA0(X86Context& ctx, uint8_t* base) {
	// 0x262DA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x262DA8: movss [0x0054EC18], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC18u, ctx.xmm[0].u32[0]);
	// 0x262DB0: ret
	return;
}

void sub_262DC0(X86Context& ctx, uint8_t* base) {
	// 0x262DC0: movss xmm0, dword ptr [0x0054EC18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC18u);
	// 0x262DC8: movss [0x0054EC20], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC20u, ctx.xmm[0].u32[0]);
	// 0x262DD0: ret
	return;
}

void sub_262DE0(X86Context& ctx, uint8_t* base) {
	// 0x262DE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262DE8: movss [0x0054EBE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBE8u, ctx.xmm[0].u32[0]);
	// 0x262DF0: ret
	return;
}

void sub_262E00(X86Context& ctx, uint8_t* base) {
	// 0x262E00: movss xmm0, dword ptr [0x0054EBEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBECu);
	// 0x262E08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x262E10: movss [0x0054EC1C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC1Cu, ctx.xmm[0].u32[0]);
	// 0x262E18: ret
	return;
}

void sub_262E20(X86Context& ctx, uint8_t* base) {
	// 0x262E20: movss xmm0, dword ptr [0x0054EBEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBECu);
	// 0x262E28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x262E30: movss [0x0054EBF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBF8u, ctx.xmm[0].u32[0]);
	// 0x262E38: ret
	return;
}

void sub_262E40(X86Context& ctx, uint8_t* base) {
	// 0x262E40: movss xmm0, dword ptr [0x0054EBEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EBECu);
	// 0x262E48: subss xmm0, [0x0054EBF8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54EBF8u);
	// 0x262E50: movss [0x0054EBF4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBF4u, ctx.xmm[0].u32[0]);
	// 0x262E58: ret
	return;
}

void sub_262E60(X86Context& ctx, uint8_t* base) {
	// 0x262E60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x262E68: movss [0x0054EC08], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC08u, ctx.xmm[0].u32[0]);
	// 0x262E70: ret
	return;
}

void sub_262E80(X86Context& ctx, uint8_t* base) {
	// 0x262E80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x262E88: movss [0x0054EBF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EBF0u, ctx.xmm[0].u32[0]);
	// 0x262E90: ret
	return;
}

void sub_262EA0(X86Context& ctx, uint8_t* base) {
	// 0x262EA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x262EA8: movss [0x0054EC44], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC44u, ctx.xmm[0].u32[0]);
	// 0x262EB0: ret
	return;
}

void sub_262EC0(X86Context& ctx, uint8_t* base) {
	// 0x262EC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262EC8: movss [0x0054EC50], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC50u, ctx.xmm[0].u32[0]);
	// 0x262ED0: ret
	return;
}

void sub_262EE0(X86Context& ctx, uint8_t* base) {
	// 0x262EE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262EE8: movss [0x0054EC40], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC40u, ctx.xmm[0].u32[0]);
	// 0x262EF0: ret
	return;
}

void sub_262F00(X86Context& ctx, uint8_t* base) {
	// 0x262F00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262F08: movss [0x0054EC28], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC28u, ctx.xmm[0].u32[0]);
	// 0x262F10: ret
	return;
}

void sub_262F20(X86Context& ctx, uint8_t* base) {
	// 0x262F20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x262F28: movss [0x0054EC48], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC48u, ctx.xmm[0].u32[0]);
	// 0x262F30: ret
	return;
}

void sub_262F40(X86Context& ctx, uint8_t* base) {
	// 0x262F40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x262F48: movss [0x0054EC30], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC30u, ctx.xmm[0].u32[0]);
	// 0x262F50: ret
	return;
}

void sub_262F60(X86Context& ctx, uint8_t* base) {
	// 0x262F60: movss xmm0, dword ptr [0x0054EC48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC48u);
	// 0x262F68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x262F70: movss [0x0054EC58], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC58u, ctx.xmm[0].u32[0]);
	// 0x262F78: ret
	return;
}

void sub_262F80(X86Context& ctx, uint8_t* base) {
	// 0x262F80: movss xmm0, dword ptr [0x0054EC30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC30u);
	// 0x262F88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x262F90: movss [0x0054EC54], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC54u, ctx.xmm[0].u32[0]);
	// 0x262F98: ret
	return;
}

void sub_262FA0(X86Context& ctx, uint8_t* base) {
	// 0x262FA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262FA8: movss [0x0054EC68], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC68u, ctx.xmm[0].u32[0]);
	// 0x262FB0: ret
	return;
}

void sub_262FC0(X86Context& ctx, uint8_t* base) {
	// 0x262FC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x262FC8: movss [0x0054EC5C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC5Cu, ctx.xmm[0].u32[0]);
	// 0x262FD0: ret
	return;
}

void sub_262FE0(X86Context& ctx, uint8_t* base) {
	// 0x262FE0: movss xmm0, dword ptr [0x0054EC5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC5Cu);
	// 0x262FE8: movss [0x0054EC64], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC64u, ctx.xmm[0].u32[0]);
	// 0x262FF0: ret
	return;
}

void sub_263000(X86Context& ctx, uint8_t* base) {
	// 0x263000: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263008: movss [0x0054EC2C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC2Cu, ctx.xmm[0].u32[0]);
	// 0x263010: ret
	return;
}

void sub_263020(X86Context& ctx, uint8_t* base) {
	// 0x263020: movss xmm0, dword ptr [0x0054EC30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC30u);
	// 0x263028: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x263030: movss [0x0054EC60], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC60u, ctx.xmm[0].u32[0]);
	// 0x263038: ret
	return;
}

void sub_263040(X86Context& ctx, uint8_t* base) {
	// 0x263040: movss xmm0, dword ptr [0x0054EC30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC30u);
	// 0x263048: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x263050: movss [0x0054EC3C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC3Cu, ctx.xmm[0].u32[0]);
	// 0x263058: ret
	return;
}

void sub_263060(X86Context& ctx, uint8_t* base) {
	// 0x263060: movss xmm0, dword ptr [0x0054EC30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC30u);
	// 0x263068: subss xmm0, [0x0054EC3C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54EC3Cu);
	// 0x263070: movss [0x0054EC38], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC38u, ctx.xmm[0].u32[0]);
	// 0x263078: ret
	return;
}

void sub_263080(X86Context& ctx, uint8_t* base) {
	// 0x263080: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x263088: movss [0x0054EC4C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC4Cu, ctx.xmm[0].u32[0]);
	// 0x263090: ret
	return;
}

void sub_2630A0(X86Context& ctx, uint8_t* base) {
	// 0x2630A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2630A8: movss [0x0054EC34], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC34u, ctx.xmm[0].u32[0]);
	// 0x2630B0: ret
	return;
}

void sub_2630C0(X86Context& ctx, uint8_t* base) {
	// 0x2630C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2630C8: movss [0x0054EC74], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC74u, ctx.xmm[0].u32[0]);
	// 0x2630D0: ret
	return;
}

void sub_2630E0(X86Context& ctx, uint8_t* base) {
	// 0x2630E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2630E8: movss [0x0054EC78], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC78u, ctx.xmm[0].u32[0]);
	// 0x2630F0: ret
	return;
}

void sub_263100(X86Context& ctx, uint8_t* base) {
	// 0x263100: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263108: movss [0x0054EC70], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC70u, ctx.xmm[0].u32[0]);
	// 0x263110: ret
	return;
}

void sub_263120(X86Context& ctx, uint8_t* base) {
	// 0x263120: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x263128: movss [0x0054EC6C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC6Cu, ctx.xmm[0].u32[0]);
	// 0x263130: ret
	return;
}

void sub_263140(X86Context& ctx, uint8_t* base) {
	// 0x263140: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263148: movss [0x0054EC98], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC98u, ctx.xmm[0].u32[0]);
	// 0x263150: ret
	return;
}

void sub_263160(X86Context& ctx, uint8_t* base) {
	// 0x263160: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263168: movss [0x0054ECA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECA4u, ctx.xmm[0].u32[0]);
	// 0x263170: ret
	return;
}

void sub_263180(X86Context& ctx, uint8_t* base) {
	// 0x263180: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263188: movss [0x0054EC94], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC94u, ctx.xmm[0].u32[0]);
	// 0x263190: ret
	return;
}

void sub_2631A0(X86Context& ctx, uint8_t* base) {
	// 0x2631A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2631A8: movss [0x0054EC7C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC7Cu, ctx.xmm[0].u32[0]);
	// 0x2631B0: ret
	return;
}

void sub_2631C0(X86Context& ctx, uint8_t* base) {
	// 0x2631C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2631C8: movss [0x0054EC9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC9Cu, ctx.xmm[0].u32[0]);
	// 0x2631D0: ret
	return;
}

void sub_2631E0(X86Context& ctx, uint8_t* base) {
	// 0x2631E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2631E8: movss [0x0054EC84], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC84u, ctx.xmm[0].u32[0]);
	// 0x2631F0: ret
	return;
}

void sub_263200(X86Context& ctx, uint8_t* base) {
	// 0x263200: movss xmm0, dword ptr [0x0054EC9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC9Cu);
	// 0x263208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x263210: movss [0x0054ECAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECACu, ctx.xmm[0].u32[0]);
	// 0x263218: ret
	return;
}

void sub_263220(X86Context& ctx, uint8_t* base) {
	// 0x263220: movss xmm0, dword ptr [0x0054EC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC84u);
	// 0x263228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x263230: movss [0x0054ECA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECA8u, ctx.xmm[0].u32[0]);
	// 0x263238: ret
	return;
}

void sub_263240(X86Context& ctx, uint8_t* base) {
	// 0x263240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263248: movss [0x0054ECBC], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECBCu, ctx.xmm[0].u32[0]);
	// 0x263250: ret
	return;
}

void sub_263260(X86Context& ctx, uint8_t* base) {
	// 0x263260: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x263268: movss [0x0054ECB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECB0u, ctx.xmm[0].u32[0]);
	// 0x263270: ret
	return;
}

void sub_263280(X86Context& ctx, uint8_t* base) {
	// 0x263280: movss xmm0, dword ptr [0x0054ECB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54ECB0u);
	// 0x263288: movss [0x0054ECB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECB8u, ctx.xmm[0].u32[0]);
	// 0x263290: ret
	return;
}

void sub_2632A0(X86Context& ctx, uint8_t* base) {
	// 0x2632A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2632A8: movss [0x0054EC80], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC80u, ctx.xmm[0].u32[0]);
	// 0x2632B0: ret
	return;
}

void sub_2632C0(X86Context& ctx, uint8_t* base) {
	// 0x2632C0: movss xmm0, dword ptr [0x0054EC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC84u);
	// 0x2632C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2632D0: movss [0x0054ECB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECB4u, ctx.xmm[0].u32[0]);
	// 0x2632D8: ret
	return;
}

void sub_2632E0(X86Context& ctx, uint8_t* base) {
	// 0x2632E0: movss xmm0, dword ptr [0x0054EC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC84u);
	// 0x2632E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2632F0: movss [0x0054EC90], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC90u, ctx.xmm[0].u32[0]);
	// 0x2632F8: ret
	return;
}

void sub_263300(X86Context& ctx, uint8_t* base) {
	// 0x263300: movss xmm0, dword ptr [0x0054EC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EC84u);
	// 0x263308: subss xmm0, [0x0054EC90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54EC90u);
	// 0x263310: movss [0x0054EC8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC8Cu, ctx.xmm[0].u32[0]);
	// 0x263318: ret
	return;
}

void sub_263320(X86Context& ctx, uint8_t* base) {
	// 0x263320: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x263328: movss [0x0054ECA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECA0u, ctx.xmm[0].u32[0]);
	// 0x263330: ret
	return;
}

void sub_263340(X86Context& ctx, uint8_t* base) {
	// 0x263340: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x263348: movss [0x0054EC88], xmm0
	X86_MEM_WRITE_u32(base, 0x54EC88u, ctx.xmm[0].u32[0]);
	// 0x263350: ret
	return;
}

void sub_263360(X86Context& ctx, uint8_t* base) {
	// 0x263360: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263368: movss [0x0054ECDC], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECDCu, ctx.xmm[0].u32[0]);
	// 0x263370: ret
	return;
}

void sub_263380(X86Context& ctx, uint8_t* base) {
	// 0x263380: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263388: movss [0x0054F04C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F04Cu, ctx.xmm[0].u32[0]);
	// 0x263390: ret
	return;
}

void sub_2633A0(X86Context& ctx, uint8_t* base) {
	// 0x2633A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2633A8: movss [0x0054ECD8], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECD8u, ctx.xmm[0].u32[0]);
	// 0x2633B0: ret
	return;
}

void sub_2633C0(X86Context& ctx, uint8_t* base) {
	// 0x2633C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2633C8: movss [0x0054ECC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECC0u, ctx.xmm[0].u32[0]);
	// 0x2633D0: ret
	return;
}

void sub_2633E0(X86Context& ctx, uint8_t* base) {
	// 0x2633E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2633E8: movss [0x0054ECE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECE0u, ctx.xmm[0].u32[0]);
	// 0x2633F0: ret
	return;
}

void sub_263400(X86Context& ctx, uint8_t* base) {
	// 0x263400: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x263408: movss [0x0054ECC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECC8u, ctx.xmm[0].u32[0]);
	// 0x263410: ret
	return;
}

void sub_263420(X86Context& ctx, uint8_t* base) {
	// 0x263420: movss xmm0, dword ptr [0x0054ECE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54ECE0u);
	// 0x263428: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x263430: movss [0x0054F0F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F0F8u, ctx.xmm[0].u32[0]);
	// 0x263438: ret
	return;
}

void sub_263440(X86Context& ctx, uint8_t* base) {
	// 0x263440: movss xmm0, dword ptr [0x0054ECC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54ECC8u);
	// 0x263448: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x263450: movss [0x0054F050], xmm0
	X86_MEM_WRITE_u32(base, 0x54F050u, ctx.xmm[0].u32[0]);
	// 0x263458: ret
	return;
}

void sub_263460(X86Context& ctx, uint8_t* base) {
	// 0x263460: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263468: movss [0x0054F108], xmm0
	X86_MEM_WRITE_u32(base, 0x54F108u, ctx.xmm[0].u32[0]);
	// 0x263470: ret
	return;
}

void sub_263480(X86Context& ctx, uint8_t* base) {
	// 0x263480: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x263488: movss [0x0054F0FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F0FCu, ctx.xmm[0].u32[0]);
	// 0x263490: ret
	return;
}

void sub_2634A0(X86Context& ctx, uint8_t* base) {
	// 0x2634A0: movss xmm0, dword ptr [0x0054F0FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F0FCu);
	// 0x2634A8: movss [0x0054F104], xmm0
	X86_MEM_WRITE_u32(base, 0x54F104u, ctx.xmm[0].u32[0]);
	// 0x2634B0: ret
	return;
}

void sub_2634C0(X86Context& ctx, uint8_t* base) {
	// 0x2634C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2634C8: movss [0x0054ECC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECC4u, ctx.xmm[0].u32[0]);
	// 0x2634D0: ret
	return;
}

void sub_2634E0(X86Context& ctx, uint8_t* base) {
	// 0x2634E0: movss xmm0, dword ptr [0x0054ECC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54ECC8u);
	// 0x2634E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2634F0: movss [0x0054F100], xmm0
	X86_MEM_WRITE_u32(base, 0x54F100u, ctx.xmm[0].u32[0]);
	// 0x2634F8: ret
	return;
}

void sub_263500(X86Context& ctx, uint8_t* base) {
	// 0x263500: movss xmm0, dword ptr [0x0054ECC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54ECC8u);
	// 0x263508: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x263510: movss [0x0054ECD4], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECD4u, ctx.xmm[0].u32[0]);
	// 0x263518: ret
	return;
}

void sub_263520(X86Context& ctx, uint8_t* base) {
	// 0x263520: movss xmm0, dword ptr [0x0054ECC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54ECC8u);
	// 0x263528: subss xmm0, [0x0054ECD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54ECD4u);
	// 0x263530: movss [0x0054ECD0], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECD0u, ctx.xmm[0].u32[0]);
	// 0x263538: ret
	return;
}

void sub_263540(X86Context& ctx, uint8_t* base) {
	// 0x263540: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x263548: movss [0x0054F048], xmm0
	X86_MEM_WRITE_u32(base, 0x54F048u, ctx.xmm[0].u32[0]);
	// 0x263550: ret
	return;
}

void sub_263560(X86Context& ctx, uint8_t* base) {
	// 0x263560: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x263568: movss [0x0054ECCC], xmm0
	X86_MEM_WRITE_u32(base, 0x54ECCCu, ctx.xmm[0].u32[0]);
	// 0x263570: ret
	return;
}

void sub_263580(X86Context& ctx, uint8_t* base) {
	// 0x263580: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263588: movss [0x0054F110], xmm0
	X86_MEM_WRITE_u32(base, 0x54F110u, ctx.xmm[0].u32[0]);
	// 0x263590: ret
	return;
}

void sub_2635A0(X86Context& ctx, uint8_t* base) {
	// 0x2635A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2635A8: movss [0x0054F114], xmm0
	X86_MEM_WRITE_u32(base, 0x54F114u, ctx.xmm[0].u32[0]);
	// 0x2635B0: ret
	return;
}

void sub_2635C0(X86Context& ctx, uint8_t* base) {
	// 0x2635C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2635C8: movss [0x0054F10C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F10Cu, ctx.xmm[0].u32[0]);
	// 0x2635D0: ret
	return;
}

void sub_2635E0(X86Context& ctx, uint8_t* base) {
	// 0x2635E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2635E8: movss [0x0054F134], xmm0
	X86_MEM_WRITE_u32(base, 0x54F134u, ctx.xmm[0].u32[0]);
	// 0x2635F0: ret
	return;
}

void sub_263600(X86Context& ctx, uint8_t* base) {
	// 0x263600: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263608: movss [0x0054F140], xmm0
	X86_MEM_WRITE_u32(base, 0x54F140u, ctx.xmm[0].u32[0]);
	// 0x263610: ret
	return;
}

void sub_263620(X86Context& ctx, uint8_t* base) {
	// 0x263620: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263628: movss [0x0054F130], xmm0
	X86_MEM_WRITE_u32(base, 0x54F130u, ctx.xmm[0].u32[0]);
	// 0x263630: ret
	return;
}

void sub_263640(X86Context& ctx, uint8_t* base) {
	// 0x263640: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x263648: movss [0x0054F118], xmm0
	X86_MEM_WRITE_u32(base, 0x54F118u, ctx.xmm[0].u32[0]);
	// 0x263650: ret
	return;
}

void sub_263660(X86Context& ctx, uint8_t* base) {
	// 0x263660: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x263668: movss [0x0054F138], xmm0
	X86_MEM_WRITE_u32(base, 0x54F138u, ctx.xmm[0].u32[0]);
	// 0x263670: ret
	return;
}

void sub_263680(X86Context& ctx, uint8_t* base) {
	// 0x263680: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x263688: movss [0x0054F120], xmm0
	X86_MEM_WRITE_u32(base, 0x54F120u, ctx.xmm[0].u32[0]);
	// 0x263690: ret
	return;
}

void sub_2636A0(X86Context& ctx, uint8_t* base) {
	// 0x2636A0: movss xmm0, dword ptr [0x0054F138]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F138u);
	// 0x2636A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2636B0: movss [0x0054F148], xmm0
	X86_MEM_WRITE_u32(base, 0x54F148u, ctx.xmm[0].u32[0]);
	// 0x2636B8: ret
	return;
}

void sub_2636C0(X86Context& ctx, uint8_t* base) {
	// 0x2636C0: movss xmm0, dword ptr [0x0054F120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F120u);
	// 0x2636C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2636D0: movss [0x0054F144], xmm0
	X86_MEM_WRITE_u32(base, 0x54F144u, ctx.xmm[0].u32[0]);
	// 0x2636D8: ret
	return;
}

void sub_2636E0(X86Context& ctx, uint8_t* base) {
	// 0x2636E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2636E8: movss [0x0054F158], xmm0
	X86_MEM_WRITE_u32(base, 0x54F158u, ctx.xmm[0].u32[0]);
	// 0x2636F0: ret
	return;
}

void sub_263700(X86Context& ctx, uint8_t* base) {
	// 0x263700: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x263708: movss [0x0054F14C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F14Cu, ctx.xmm[0].u32[0]);
	// 0x263710: ret
	return;
}

void sub_263720(X86Context& ctx, uint8_t* base) {
	// 0x263720: movss xmm0, dword ptr [0x0054F14C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F14Cu);
	// 0x263728: movss [0x0054F154], xmm0
	X86_MEM_WRITE_u32(base, 0x54F154u, ctx.xmm[0].u32[0]);
	// 0x263730: ret
	return;
}

void sub_263740(X86Context& ctx, uint8_t* base) {
	// 0x263740: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263748: movss [0x0054F11C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F11Cu, ctx.xmm[0].u32[0]);
	// 0x263750: ret
	return;
}

void sub_263760(X86Context& ctx, uint8_t* base) {
	// 0x263760: movss xmm0, dword ptr [0x0054F120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F120u);
	// 0x263768: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x263770: movss [0x0054F150], xmm0
	X86_MEM_WRITE_u32(base, 0x54F150u, ctx.xmm[0].u32[0]);
	// 0x263778: ret
	return;
}

void sub_263780(X86Context& ctx, uint8_t* base) {
	// 0x263780: movss xmm0, dword ptr [0x0054F120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F120u);
	// 0x263788: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x263790: movss [0x0054F12C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F12Cu, ctx.xmm[0].u32[0]);
	// 0x263798: ret
	return;
}

void sub_2637A0(X86Context& ctx, uint8_t* base) {
	// 0x2637A0: movss xmm0, dword ptr [0x0054F120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F120u);
	// 0x2637A8: subss xmm0, [0x0054F12C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F12Cu);
	// 0x2637B0: movss [0x0054F128], xmm0
	X86_MEM_WRITE_u32(base, 0x54F128u, ctx.xmm[0].u32[0]);
	// 0x2637B8: ret
	return;
}

void sub_2637C0(X86Context& ctx, uint8_t* base) {
	// 0x2637C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2637C8: movss [0x0054F13C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F13Cu, ctx.xmm[0].u32[0]);
	// 0x2637D0: ret
	return;
}

void sub_2637E0(X86Context& ctx, uint8_t* base) {
	// 0x2637E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2637E8: movss [0x0054F124], xmm0
	X86_MEM_WRITE_u32(base, 0x54F124u, ctx.xmm[0].u32[0]);
	// 0x2637F0: ret
	return;
}

void sub_263800(X86Context& ctx, uint8_t* base) {
	// 0x263800: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263808: movss [0x0054F178], xmm0
	X86_MEM_WRITE_u32(base, 0x54F178u, ctx.xmm[0].u32[0]);
	// 0x263810: ret
	return;
}

void sub_263820(X86Context& ctx, uint8_t* base) {
	// 0x263820: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263828: movss [0x0054F184], xmm0
	X86_MEM_WRITE_u32(base, 0x54F184u, ctx.xmm[0].u32[0]);
	// 0x263830: ret
	return;
}

void sub_263840(X86Context& ctx, uint8_t* base) {
	// 0x263840: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263848: movss [0x0054F174], xmm0
	X86_MEM_WRITE_u32(base, 0x54F174u, ctx.xmm[0].u32[0]);
	// 0x263850: ret
	return;
}

void sub_263860(X86Context& ctx, uint8_t* base) {
	// 0x263860: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x263868: movss [0x0054F15C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F15Cu, ctx.xmm[0].u32[0]);
	// 0x263870: ret
	return;
}

void sub_263880(X86Context& ctx, uint8_t* base) {
	// 0x263880: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x263888: movss [0x0054F17C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F17Cu, ctx.xmm[0].u32[0]);
	// 0x263890: ret
	return;
}

void sub_2638A0(X86Context& ctx, uint8_t* base) {
	// 0x2638A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2638A8: movss [0x0054F164], xmm0
	X86_MEM_WRITE_u32(base, 0x54F164u, ctx.xmm[0].u32[0]);
	// 0x2638B0: ret
	return;
}

void sub_2638C0(X86Context& ctx, uint8_t* base) {
	// 0x2638C0: movss xmm0, dword ptr [0x0054F17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F17Cu);
	// 0x2638C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2638D0: movss [0x0054F18C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F18Cu, ctx.xmm[0].u32[0]);
	// 0x2638D8: ret
	return;
}

void sub_2638E0(X86Context& ctx, uint8_t* base) {
	// 0x2638E0: movss xmm0, dword ptr [0x0054F164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F164u);
	// 0x2638E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2638F0: movss [0x0054F188], xmm0
	X86_MEM_WRITE_u32(base, 0x54F188u, ctx.xmm[0].u32[0]);
	// 0x2638F8: ret
	return;
}

void sub_263900(X86Context& ctx, uint8_t* base) {
	// 0x263900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263908: movss [0x0054F1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1E0u, ctx.xmm[0].u32[0]);
	// 0x263910: ret
	return;
}

void sub_263920(X86Context& ctx, uint8_t* base) {
	// 0x263920: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x263928: movss [0x0054F190], xmm0
	X86_MEM_WRITE_u32(base, 0x54F190u, ctx.xmm[0].u32[0]);
	// 0x263930: ret
	return;
}

void sub_263940(X86Context& ctx, uint8_t* base) {
	// 0x263940: movss xmm0, dword ptr [0x0054F190]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F190u);
	// 0x263948: movss [0x0054F198], xmm0
	X86_MEM_WRITE_u32(base, 0x54F198u, ctx.xmm[0].u32[0]);
	// 0x263950: ret
	return;
}

void sub_263960(X86Context& ctx, uint8_t* base) {
	// 0x263960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263968: movss [0x0054F160], xmm0
	X86_MEM_WRITE_u32(base, 0x54F160u, ctx.xmm[0].u32[0]);
	// 0x263970: ret
	return;
}

void sub_263980(X86Context& ctx, uint8_t* base) {
	// 0x263980: movss xmm0, dword ptr [0x0054F164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F164u);
	// 0x263988: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x263990: movss [0x0054F194], xmm0
	X86_MEM_WRITE_u32(base, 0x54F194u, ctx.xmm[0].u32[0]);
	// 0x263998: ret
	return;
}

void sub_2639A0(X86Context& ctx, uint8_t* base) {
	// 0x2639A0: movss xmm0, dword ptr [0x0054F164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F164u);
	// 0x2639A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2639B0: movss [0x0054F170], xmm0
	X86_MEM_WRITE_u32(base, 0x54F170u, ctx.xmm[0].u32[0]);
	// 0x2639B8: ret
	return;
}

void sub_2639C0(X86Context& ctx, uint8_t* base) {
	// 0x2639C0: movss xmm0, dword ptr [0x0054F164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F164u);
	// 0x2639C8: subss xmm0, [0x0054F170]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F170u);
	// 0x2639D0: movss [0x0054F16C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F16Cu, ctx.xmm[0].u32[0]);
	// 0x2639D8: ret
	return;
}

void sub_2639E0(X86Context& ctx, uint8_t* base) {
	// 0x2639E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2639E8: movss [0x0054F180], xmm0
	X86_MEM_WRITE_u32(base, 0x54F180u, ctx.xmm[0].u32[0]);
	// 0x2639F0: ret
	return;
}

void sub_263A00(X86Context& ctx, uint8_t* base) {
	// 0x263A00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x263A08: movss [0x0054F168], xmm0
	X86_MEM_WRITE_u32(base, 0x54F168u, ctx.xmm[0].u32[0]);
	// 0x263A10: ret
	return;
}

void sub_263A20(X86Context& ctx, uint8_t* base) {
	// 0x263A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263A28: movss [0x0054F200], xmm0
	X86_MEM_WRITE_u32(base, 0x54F200u, ctx.xmm[0].u32[0]);
	// 0x263A30: ret
	return;
}

void sub_263A40(X86Context& ctx, uint8_t* base) {
	// 0x263A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263A48: movss [0x0054F20C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F20Cu, ctx.xmm[0].u32[0]);
	// 0x263A50: ret
	return;
}

void sub_263A60(X86Context& ctx, uint8_t* base) {
	// 0x263A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263A68: movss [0x0054F1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1FCu, ctx.xmm[0].u32[0]);
	// 0x263A70: ret
	return;
}

void sub_263A80(X86Context& ctx, uint8_t* base) {
	// 0x263A80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x263A88: movss [0x0054F1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1E4u, ctx.xmm[0].u32[0]);
	// 0x263A90: ret
	return;
}

void sub_263AA0(X86Context& ctx, uint8_t* base) {
	// 0x263AA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x263AA8: movss [0x0054F204], xmm0
	X86_MEM_WRITE_u32(base, 0x54F204u, ctx.xmm[0].u32[0]);
	// 0x263AB0: ret
	return;
}

void sub_263AC0(X86Context& ctx, uint8_t* base) {
	// 0x263AC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x263AC8: movss [0x0054F1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1ECu, ctx.xmm[0].u32[0]);
	// 0x263AD0: ret
	return;
}

void sub_263AE0(X86Context& ctx, uint8_t* base) {
	// 0x263AE0: movss xmm0, dword ptr [0x0054F204]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F204u);
	// 0x263AE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x263AF0: movss [0x0054F214], xmm0
	X86_MEM_WRITE_u32(base, 0x54F214u, ctx.xmm[0].u32[0]);
	// 0x263AF8: ret
	return;
}

void sub_263B00(X86Context& ctx, uint8_t* base) {
	// 0x263B00: movss xmm0, dword ptr [0x0054F1EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F1ECu);
	// 0x263B08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x263B10: movss [0x0054F210], xmm0
	X86_MEM_WRITE_u32(base, 0x54F210u, ctx.xmm[0].u32[0]);
	// 0x263B18: ret
	return;
}

void sub_263B20(X86Context& ctx, uint8_t* base) {
	// 0x263B20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263B28: movss [0x0054F224], xmm0
	X86_MEM_WRITE_u32(base, 0x54F224u, ctx.xmm[0].u32[0]);
	// 0x263B30: ret
	return;
}

void sub_263B40(X86Context& ctx, uint8_t* base) {
	// 0x263B40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x263B48: movss [0x0054F218], xmm0
	X86_MEM_WRITE_u32(base, 0x54F218u, ctx.xmm[0].u32[0]);
	// 0x263B50: ret
	return;
}

void sub_263B60(X86Context& ctx, uint8_t* base) {
	// 0x263B60: movss xmm0, dword ptr [0x0054F218]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F218u);
	// 0x263B68: movss [0x0054F220], xmm0
	X86_MEM_WRITE_u32(base, 0x54F220u, ctx.xmm[0].u32[0]);
	// 0x263B70: ret
	return;
}

void sub_263B80(X86Context& ctx, uint8_t* base) {
	// 0x263B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263B88: movss [0x0054F1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1E8u, ctx.xmm[0].u32[0]);
	// 0x263B90: ret
	return;
}

void sub_263BA0(X86Context& ctx, uint8_t* base) {
	// 0x263BA0: movss xmm0, dword ptr [0x0054F1EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F1ECu);
	// 0x263BA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x263BB0: movss [0x0054F21C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F21Cu, ctx.xmm[0].u32[0]);
	// 0x263BB8: ret
	return;
}

void sub_263BC0(X86Context& ctx, uint8_t* base) {
	// 0x263BC0: movss xmm0, dword ptr [0x0054F1EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F1ECu);
	// 0x263BC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x263BD0: movss [0x0054F1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1F8u, ctx.xmm[0].u32[0]);
	// 0x263BD8: ret
	return;
}

void sub_263BE0(X86Context& ctx, uint8_t* base) {
	// 0x263BE0: movss xmm0, dword ptr [0x0054F1EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F1ECu);
	// 0x263BE8: subss xmm0, [0x0054F1F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F1F8u);
	// 0x263BF0: movss [0x0054F1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1F4u, ctx.xmm[0].u32[0]);
	// 0x263BF8: ret
	return;
}

void sub_263C00(X86Context& ctx, uint8_t* base) {
	// 0x263C00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x263C08: movss [0x0054F208], xmm0
	X86_MEM_WRITE_u32(base, 0x54F208u, ctx.xmm[0].u32[0]);
	// 0x263C10: ret
	return;
}

void sub_263C20(X86Context& ctx, uint8_t* base) {
	// 0x263C20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x263C28: movss [0x0054F1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F1F0u, ctx.xmm[0].u32[0]);
	// 0x263C30: ret
	return;
}

void sub_263C40(X86Context& ctx, uint8_t* base) {
	// 0x263C40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263C48: movss [0x0054F264], xmm0
	X86_MEM_WRITE_u32(base, 0x54F264u, ctx.xmm[0].u32[0]);
	// 0x263C50: ret
	return;
}

void sub_263C60(X86Context& ctx, uint8_t* base) {
	// 0x263C60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263C68: movss [0x0054F270], xmm0
	X86_MEM_WRITE_u32(base, 0x54F270u, ctx.xmm[0].u32[0]);
	// 0x263C70: ret
	return;
}

void sub_263C80(X86Context& ctx, uint8_t* base) {
	// 0x263C80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263C88: movss [0x0054F260], xmm0
	X86_MEM_WRITE_u32(base, 0x54F260u, ctx.xmm[0].u32[0]);
	// 0x263C90: ret
	return;
}

void sub_263CA0(X86Context& ctx, uint8_t* base) {
	// 0x263CA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x263CA8: movss [0x0054F228], xmm0
	X86_MEM_WRITE_u32(base, 0x54F228u, ctx.xmm[0].u32[0]);
	// 0x263CB0: ret
	return;
}

void sub_263CC0(X86Context& ctx, uint8_t* base) {
	// 0x263CC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x263CC8: movss [0x0054F268], xmm0
	X86_MEM_WRITE_u32(base, 0x54F268u, ctx.xmm[0].u32[0]);
	// 0x263CD0: ret
	return;
}

void sub_263CE0(X86Context& ctx, uint8_t* base) {
	// 0x263CE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x263CE8: movss [0x0054F248], xmm0
	X86_MEM_WRITE_u32(base, 0x54F248u, ctx.xmm[0].u32[0]);
	// 0x263CF0: ret
	return;
}

void sub_263D00(X86Context& ctx, uint8_t* base) {
	// 0x263D00: movss xmm0, dword ptr [0x0054F268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F268u);
	// 0x263D08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x263D10: movss [0x0054F27C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F27Cu, ctx.xmm[0].u32[0]);
	// 0x263D18: ret
	return;
}

void sub_263D20(X86Context& ctx, uint8_t* base) {
	// 0x263D20: movss xmm0, dword ptr [0x0054F248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F248u);
	// 0x263D28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x263D30: movss [0x0054F274], xmm0
	X86_MEM_WRITE_u32(base, 0x54F274u, ctx.xmm[0].u32[0]);
	// 0x263D38: ret
	return;
}

void sub_263D40(X86Context& ctx, uint8_t* base) {
	// 0x263D40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263D48: movss [0x0054F28C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F28Cu, ctx.xmm[0].u32[0]);
	// 0x263D50: ret
	return;
}

void sub_263D60(X86Context& ctx, uint8_t* base) {
	// 0x263D60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x263D68: movss [0x0054F280], xmm0
	X86_MEM_WRITE_u32(base, 0x54F280u, ctx.xmm[0].u32[0]);
	// 0x263D70: ret
	return;
}

void sub_263D80(X86Context& ctx, uint8_t* base) {
	// 0x263D80: movss xmm0, dword ptr [0x0054F280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F280u);
	// 0x263D88: movss [0x0054F288], xmm0
	X86_MEM_WRITE_u32(base, 0x54F288u, ctx.xmm[0].u32[0]);
	// 0x263D90: ret
	return;
}

void sub_263DA0(X86Context& ctx, uint8_t* base) {
	// 0x263DA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x263DA8: movss [0x0054F240], xmm0
	X86_MEM_WRITE_u32(base, 0x54F240u, ctx.xmm[0].u32[0]);
	// 0x263DB0: ret
	return;
}

void sub_263DC0(X86Context& ctx, uint8_t* base) {
	// 0x263DC0: movss xmm0, dword ptr [0x0054F248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F248u);
	// 0x263DC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x263DD0: movss [0x0054F284], xmm0
	X86_MEM_WRITE_u32(base, 0x54F284u, ctx.xmm[0].u32[0]);
	// 0x263DD8: ret
	return;
}

void sub_263DE0(X86Context& ctx, uint8_t* base) {
	// 0x263DE0: movss xmm0, dword ptr [0x0054F248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F248u);
	// 0x263DE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x263DF0: movss [0x0054F258], xmm0
	X86_MEM_WRITE_u32(base, 0x54F258u, ctx.xmm[0].u32[0]);
	// 0x263DF8: ret
	return;
}

void sub_263E00(X86Context& ctx, uint8_t* base) {
	// 0x263E00: movss xmm0, dword ptr [0x0054F248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F248u);
	// 0x263E08: subss xmm0, [0x0054F258]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F258u);
	// 0x263E10: movss [0x0054F250], xmm0
	X86_MEM_WRITE_u32(base, 0x54F250u, ctx.xmm[0].u32[0]);
	// 0x263E18: ret
	return;
}

void sub_263E20(X86Context& ctx, uint8_t* base) {
	// 0x263E20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x263E28: movss [0x0054F26C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F26Cu, ctx.xmm[0].u32[0]);
	// 0x263E30: ret
	return;
}

void sub_263E40(X86Context& ctx, uint8_t* base) {
	// 0x263E40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x263E48: movss [0x0054F24C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F24Cu, ctx.xmm[0].u32[0]);
	// 0x263E50: ret
	return;
}

void sub_263E60(X86Context& ctx, uint8_t* base) {
	// 0x263E60: movss xmm0, dword ptr [0x003B218C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B218Cu);
	// 0x263E68: movss [0x0054F254], xmm0
	X86_MEM_WRITE_u32(base, 0x54F254u, ctx.xmm[0].u32[0]);
	// 0x263E70: ret
	return;
}

void sub_263E80(X86Context& ctx, uint8_t* base) {
	// 0x263E80: movss xmm0, dword ptr [0x003B2190]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2190u);
	// 0x263E88: movss [0x0054F278], xmm0
	X86_MEM_WRITE_u32(base, 0x54F278u, ctx.xmm[0].u32[0]);
	// 0x263E90: ret
	return;
}

void sub_263EA0(X86Context& ctx, uint8_t* base) {
	// 0x263EA0: movss xmm0, dword ptr [0x003B2194]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2194u);
	// 0x263EA8: movss [0x0054F25C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F25Cu, ctx.xmm[0].u32[0]);
	// 0x263EB0: ret
	return;
}

void sub_263EC0(X86Context& ctx, uint8_t* base) {
	// 0x263EC0: movss xmm0, dword ptr [0x003B2198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2198u);
	// 0x263EC8: movss [0x0054F244], xmm0
	X86_MEM_WRITE_u32(base, 0x54F244u, ctx.xmm[0].u32[0]);
	// 0x263ED0: ret
	return;
}

void sub_263EE0(X86Context& ctx, uint8_t* base) {
	// 0x263EE0: movss xmm0, dword ptr [0x0054F254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F254u);
	// 0x263EE8: movss [0x0054F230], xmm0
	X86_MEM_WRITE_u32(base, 0x54F230u, ctx.xmm[0].u32[0]);
	// 0x263EF0: movss xmm0, dword ptr [0x0054F278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F278u);
	// 0x263EF8: movss [0x0054F234], xmm0
	X86_MEM_WRITE_u32(base, 0x54F234u, ctx.xmm[0].u32[0]);
	// 0x263F00: movss xmm0, dword ptr [0x0054F25C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F25Cu);
	// 0x263F08: movss [0x0054F238], xmm0
	X86_MEM_WRITE_u32(base, 0x54F238u, ctx.xmm[0].u32[0]);
	// 0x263F10: movss xmm0, dword ptr [0x0054F244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F244u);
	// 0x263F18: movss [0x0054F23C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F23Cu, ctx.xmm[0].u32[0]);
	// 0x263F20: ret
	return;
}

void sub_263F30(X86Context& ctx, uint8_t* base) {
	// 0x263F30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x263F38: movss [0x0054F2AC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2ACu, ctx.xmm[0].u32[0]);
	// 0x263F40: ret
	return;
}

void sub_263F50(X86Context& ctx, uint8_t* base) {
	// 0x263F50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x263F58: movss [0x0054F2B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2B8u, ctx.xmm[0].u32[0]);
	// 0x263F60: ret
	return;
}

void sub_263F70(X86Context& ctx, uint8_t* base) {
	// 0x263F70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x263F78: movss [0x0054F2A8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2A8u, ctx.xmm[0].u32[0]);
	// 0x263F80: ret
	return;
}

void sub_263F90(X86Context& ctx, uint8_t* base) {
	// 0x263F90: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x263F98: movss [0x0054F290], xmm0
	X86_MEM_WRITE_u32(base, 0x54F290u, ctx.xmm[0].u32[0]);
	// 0x263FA0: ret
	return;
}

void sub_263FB0(X86Context& ctx, uint8_t* base) {
	// 0x263FB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x263FB8: movss [0x0054F2B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2B0u, ctx.xmm[0].u32[0]);
	// 0x263FC0: ret
	return;
}

void sub_263FD0(X86Context& ctx, uint8_t* base) {
	// 0x263FD0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x263FD8: movss [0x0054F298], xmm0
	X86_MEM_WRITE_u32(base, 0x54F298u, ctx.xmm[0].u32[0]);
	// 0x263FE0: ret
	return;
}

void sub_263FF0(X86Context& ctx, uint8_t* base) {
	// 0x263FF0: movss xmm0, dword ptr [0x0054F2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2B0u);
	// 0x263FF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x264000: movss [0x0054F2C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2C0u, ctx.xmm[0].u32[0]);
	// 0x264008: ret
	return;
}

void sub_264010(X86Context& ctx, uint8_t* base) {
	// 0x264010: movss xmm0, dword ptr [0x0054F298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F298u);
	// 0x264018: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x264020: movss [0x0054F2BC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2BCu, ctx.xmm[0].u32[0]);
	// 0x264028: ret
	return;
}

void sub_264030(X86Context& ctx, uint8_t* base) {
	// 0x264030: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264038: movss [0x0054F2D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2D0u, ctx.xmm[0].u32[0]);
	// 0x264040: ret
	return;
}

void sub_264050(X86Context& ctx, uint8_t* base) {
	// 0x264050: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x264058: movss [0x0054F2C4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2C4u, ctx.xmm[0].u32[0]);
	// 0x264060: ret
	return;
}

void sub_264070(X86Context& ctx, uint8_t* base) {
	// 0x264070: movss xmm0, dword ptr [0x0054F2C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2C4u);
	// 0x264078: movss [0x0054F2CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2CCu, ctx.xmm[0].u32[0]);
	// 0x264080: ret
	return;
}

void sub_264090(X86Context& ctx, uint8_t* base) {
	// 0x264090: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264098: movss [0x0054F294], xmm0
	X86_MEM_WRITE_u32(base, 0x54F294u, ctx.xmm[0].u32[0]);
	// 0x2640A0: ret
	return;
}

void sub_2640B0(X86Context& ctx, uint8_t* base) {
	// 0x2640B0: movss xmm0, dword ptr [0x0054F298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F298u);
	// 0x2640B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2640C0: movss [0x0054F2C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2C8u, ctx.xmm[0].u32[0]);
	// 0x2640C8: ret
	return;
}

void sub_2640D0(X86Context& ctx, uint8_t* base) {
	// 0x2640D0: movss xmm0, dword ptr [0x0054F298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F298u);
	// 0x2640D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2640E0: movss [0x0054F2A4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2A4u, ctx.xmm[0].u32[0]);
	// 0x2640E8: ret
	return;
}

void sub_2640F0(X86Context& ctx, uint8_t* base) {
	// 0x2640F0: movss xmm0, dword ptr [0x0054F298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F298u);
	// 0x2640F8: subss xmm0, [0x0054F2A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F2A4u);
	// 0x264100: movss [0x0054F2A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2A0u, ctx.xmm[0].u32[0]);
	// 0x264108: ret
	return;
}

void sub_264110(X86Context& ctx, uint8_t* base) {
	// 0x264110: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x264118: movss [0x0054F2B4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2B4u, ctx.xmm[0].u32[0]);
	// 0x264120: ret
	return;
}

void sub_264130(X86Context& ctx, uint8_t* base) {
	// 0x264130: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x264138: movss [0x0054F29C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F29Cu, ctx.xmm[0].u32[0]);
	// 0x264140: ret
	return;
}

void sub_264150(X86Context& ctx, uint8_t* base) {
	// 0x264150: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x264158: movss [0x0054F2EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2ECu, ctx.xmm[0].u32[0]);
	// 0x264160: ret
	return;
}

void sub_264170(X86Context& ctx, uint8_t* base) {
	// 0x264170: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x264178: movss [0x0054F2F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2F4u, ctx.xmm[0].u32[0]);
	// 0x264180: ret
	return;
}

void sub_264190(X86Context& ctx, uint8_t* base) {
	// 0x264190: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x264198: movss [0x0054F2E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2E8u, ctx.xmm[0].u32[0]);
	// 0x2641A0: ret
	return;
}

void sub_2641B0(X86Context& ctx, uint8_t* base) {
	// 0x2641B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2641B8: movss [0x0054F2D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2D4u, ctx.xmm[0].u32[0]);
	// 0x2641C0: ret
	return;
}

void sub_2641D0(X86Context& ctx, uint8_t* base) {
	// 0x2641D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2641D8: movss [0x0054F2F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2F0u, ctx.xmm[0].u32[0]);
	// 0x2641E0: ret
	return;
}

void sub_2641F0(X86Context& ctx, uint8_t* base) {
	// 0x2641F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2641F8: movss [0x0054F2DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2DCu, ctx.xmm[0].u32[0]);
	// 0x264200: ret
	return;
}

void sub_264210(X86Context& ctx, uint8_t* base) {
	// 0x264210: movss xmm0, dword ptr [0x0054F2F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2F0u);
	// 0x264218: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x264220: movss [0x0054F2FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2FCu, ctx.xmm[0].u32[0]);
	// 0x264228: ret
	return;
}

void sub_264230(X86Context& ctx, uint8_t* base) {
	// 0x264230: movss xmm0, dword ptr [0x0054F2DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2DCu);
	// 0x264238: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x264240: movss [0x0054F2F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2F8u, ctx.xmm[0].u32[0]);
	// 0x264248: ret
	return;
}

void sub_264250(X86Context& ctx, uint8_t* base) {
	// 0x264250: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264258: movss [0x0054F30C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F30Cu, ctx.xmm[0].u32[0]);
	// 0x264260: ret
	return;
}

void sub_264270(X86Context& ctx, uint8_t* base) {
	// 0x264270: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x264278: movss [0x0054F300], xmm0
	X86_MEM_WRITE_u32(base, 0x54F300u, ctx.xmm[0].u32[0]);
	// 0x264280: ret
	return;
}

void sub_264290(X86Context& ctx, uint8_t* base) {
	// 0x264290: movss xmm0, dword ptr [0x0054F300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F300u);
	// 0x264298: movss [0x0054F308], xmm0
	X86_MEM_WRITE_u32(base, 0x54F308u, ctx.xmm[0].u32[0]);
	// 0x2642A0: ret
	return;
}

void sub_2642B0(X86Context& ctx, uint8_t* base) {
	// 0x2642B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2642B8: movss [0x0054F2D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2D8u, ctx.xmm[0].u32[0]);
	// 0x2642C0: ret
	return;
}

void sub_2642D0(X86Context& ctx, uint8_t* base) {
	// 0x2642D0: movss xmm0, dword ptr [0x0054F2DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2DCu);
	// 0x2642D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2642E0: movss [0x0054F304], xmm0
	X86_MEM_WRITE_u32(base, 0x54F304u, ctx.xmm[0].u32[0]);
	// 0x2642E8: ret
	return;
}

void sub_2642F0(X86Context& ctx, uint8_t* base) {
	// 0x2642F0: movss xmm0, dword ptr [0x0054F2DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2DCu);
	// 0x2642F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x264300: movss [0x0054F2E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2E4u, ctx.xmm[0].u32[0]);
	// 0x264308: ret
	return;
}

void sub_264310(X86Context& ctx, uint8_t* base) {
	// 0x264310: movss xmm0, dword ptr [0x0054F2DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F2DCu);
	// 0x264318: subss xmm0, [0x0054F2E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F2E4u);
	// 0x264320: movss [0x0054F2E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F2E0u, ctx.xmm[0].u32[0]);
	// 0x264328: ret
	return;
}

void sub_264330(X86Context& ctx, uint8_t* base) {
	// 0x264330: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x264338: movss [0x0054F328], xmm0
	X86_MEM_WRITE_u32(base, 0x54F328u, ctx.xmm[0].u32[0]);
	// 0x264340: ret
	return;
}

void sub_264350(X86Context& ctx, uint8_t* base) {
	// 0x264350: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x264358: movss [0x0054F330], xmm0
	X86_MEM_WRITE_u32(base, 0x54F330u, ctx.xmm[0].u32[0]);
	// 0x264360: ret
	return;
}

void sub_264370(X86Context& ctx, uint8_t* base) {
	// 0x264370: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x264378: movss [0x0054F324], xmm0
	X86_MEM_WRITE_u32(base, 0x54F324u, ctx.xmm[0].u32[0]);
	// 0x264380: ret
	return;
}

void sub_264390(X86Context& ctx, uint8_t* base) {
	// 0x264390: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x264398: movss [0x0054F310], xmm0
	X86_MEM_WRITE_u32(base, 0x54F310u, ctx.xmm[0].u32[0]);
	// 0x2643A0: ret
	return;
}

void sub_2643B0(X86Context& ctx, uint8_t* base) {
	// 0x2643B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2643B8: movss [0x0054F32C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F32Cu, ctx.xmm[0].u32[0]);
	// 0x2643C0: ret
	return;
}

void sub_2643D0(X86Context& ctx, uint8_t* base) {
	// 0x2643D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2643D8: movss [0x0054F318], xmm0
	X86_MEM_WRITE_u32(base, 0x54F318u, ctx.xmm[0].u32[0]);
	// 0x2643E0: ret
	return;
}

void sub_2643F0(X86Context& ctx, uint8_t* base) {
	// 0x2643F0: movss xmm0, dword ptr [0x0054F32C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F32Cu);
	// 0x2643F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x264400: movss [0x0054F338], xmm0
	X86_MEM_WRITE_u32(base, 0x54F338u, ctx.xmm[0].u32[0]);
	// 0x264408: ret
	return;
}

void sub_264410(X86Context& ctx, uint8_t* base) {
	// 0x264410: movss xmm0, dword ptr [0x0054F318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F318u);
	// 0x264418: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x264420: movss [0x0054F334], xmm0
	X86_MEM_WRITE_u32(base, 0x54F334u, ctx.xmm[0].u32[0]);
	// 0x264428: ret
	return;
}

void sub_264430(X86Context& ctx, uint8_t* base) {
	// 0x264430: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264438: movss [0x0054F348], xmm0
	X86_MEM_WRITE_u32(base, 0x54F348u, ctx.xmm[0].u32[0]);
	// 0x264440: ret
	return;
}

void sub_264450(X86Context& ctx, uint8_t* base) {
	// 0x264450: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x264458: movss [0x0054F33C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F33Cu, ctx.xmm[0].u32[0]);
	// 0x264460: ret
	return;
}

void sub_264470(X86Context& ctx, uint8_t* base) {
	// 0x264470: movss xmm0, dword ptr [0x0054F33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F33Cu);
	// 0x264478: movss [0x0054F344], xmm0
	X86_MEM_WRITE_u32(base, 0x54F344u, ctx.xmm[0].u32[0]);
	// 0x264480: ret
	return;
}

void sub_264490(X86Context& ctx, uint8_t* base) {
	// 0x264490: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264498: movss [0x0054F314], xmm0
	X86_MEM_WRITE_u32(base, 0x54F314u, ctx.xmm[0].u32[0]);
	// 0x2644A0: ret
	return;
}

void sub_2644B0(X86Context& ctx, uint8_t* base) {
	// 0x2644B0: movss xmm0, dword ptr [0x0054F318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F318u);
	// 0x2644B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2644C0: movss [0x0054F340], xmm0
	X86_MEM_WRITE_u32(base, 0x54F340u, ctx.xmm[0].u32[0]);
	// 0x2644C8: ret
	return;
}

void sub_2644D0(X86Context& ctx, uint8_t* base) {
	// 0x2644D0: movss xmm0, dword ptr [0x0054F318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F318u);
	// 0x2644D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2644E0: movss [0x0054F320], xmm0
	X86_MEM_WRITE_u32(base, 0x54F320u, ctx.xmm[0].u32[0]);
	// 0x2644E8: ret
	return;
}

void sub_2644F0(X86Context& ctx, uint8_t* base) {
	// 0x2644F0: movss xmm0, dword ptr [0x0054F318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F318u);
	// 0x2644F8: subss xmm0, [0x0054F320]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F320u);
	// 0x264500: movss [0x0054F31C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F31Cu, ctx.xmm[0].u32[0]);
	// 0x264508: ret
	return;
}

void sub_264510(X86Context& ctx, uint8_t* base) {
	// 0x264510: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x264518: movss [0x0054F384], xmm0
	X86_MEM_WRITE_u32(base, 0x54F384u, ctx.xmm[0].u32[0]);
	// 0x264520: ret
	return;
}

void sub_264530(X86Context& ctx, uint8_t* base) {
	// 0x264530: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x264538: movss [0x0054F38C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F38Cu, ctx.xmm[0].u32[0]);
	// 0x264540: ret
	return;
}

void sub_264550(X86Context& ctx, uint8_t* base) {
	// 0x264550: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x264558: movss [0x0054F378], xmm0
	X86_MEM_WRITE_u32(base, 0x54F378u, ctx.xmm[0].u32[0]);
	// 0x264560: ret
	return;
}

void sub_264570(X86Context& ctx, uint8_t* base) {
	// 0x264570: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x264578: movss [0x0054F34C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F34Cu, ctx.xmm[0].u32[0]);
	// 0x264580: ret
	return;
}

void sub_264590(X86Context& ctx, uint8_t* base) {
	// 0x264590: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x264598: movss [0x0054F388], xmm0
	X86_MEM_WRITE_u32(base, 0x54F388u, ctx.xmm[0].u32[0]);
	// 0x2645A0: ret
	return;
}

void sub_2645B0(X86Context& ctx, uint8_t* base) {
	// 0x2645B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2645B8: movss [0x0054F354], xmm0
	X86_MEM_WRITE_u32(base, 0x54F354u, ctx.xmm[0].u32[0]);
	// 0x2645C0: ret
	return;
}

void sub_2645D0(X86Context& ctx, uint8_t* base) {
	// 0x2645D0: movss xmm0, dword ptr [0x0054F388]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F388u);
	// 0x2645D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2645E0: movss [0x0054F398], xmm0
	X86_MEM_WRITE_u32(base, 0x54F398u, ctx.xmm[0].u32[0]);
	// 0x2645E8: ret
	return;
}

void sub_2645F0(X86Context& ctx, uint8_t* base) {
	// 0x2645F0: movss xmm0, dword ptr [0x0054F354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F354u);
	// 0x2645F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x264600: movss [0x0054F390], xmm0
	X86_MEM_WRITE_u32(base, 0x54F390u, ctx.xmm[0].u32[0]);
	// 0x264608: ret
	return;
}

void sub_264610(X86Context& ctx, uint8_t* base) {
	// 0x264610: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264618: movss [0x0054F3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3ACu, ctx.xmm[0].u32[0]);
	// 0x264620: ret
	return;
}

void sub_264630(X86Context& ctx, uint8_t* base) {
	// 0x264630: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x264638: movss [0x0054F3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3A0u, ctx.xmm[0].u32[0]);
	// 0x264640: ret
	return;
}

void sub_264650(X86Context& ctx, uint8_t* base) {
	// 0x264650: movss xmm0, dword ptr [0x0054F3A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F3A0u);
	// 0x264658: movss [0x0054F3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3A8u, ctx.xmm[0].u32[0]);
	// 0x264660: ret
	return;
}

void sub_264670(X86Context& ctx, uint8_t* base) {
	// 0x264670: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x264678: movss [0x0054F350], xmm0
	X86_MEM_WRITE_u32(base, 0x54F350u, ctx.xmm[0].u32[0]);
	// 0x264680: ret
	return;
}

void sub_264690(X86Context& ctx, uint8_t* base) {
	// 0x264690: movss xmm0, dword ptr [0x0054F354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F354u);
	// 0x264698: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2646A0: movss [0x0054F3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F3A4u, ctx.xmm[0].u32[0]);
	// 0x2646A8: ret
	return;
}

void sub_2646B0(X86Context& ctx, uint8_t* base) {
	// 0x2646B0: movss xmm0, dword ptr [0x0054F354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F354u);
	// 0x2646B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2646C0: movss [0x0054F370], xmm0
	X86_MEM_WRITE_u32(base, 0x54F370u, ctx.xmm[0].u32[0]);
	// 0x2646C8: ret
	return;
}

void sub_2646D0(X86Context& ctx, uint8_t* base) {
	// 0x2646D0: movss xmm0, dword ptr [0x0054F354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F354u);
	// 0x2646D8: subss xmm0, [0x0054F370]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F370u);
	// 0x2646E0: movss [0x0054F368], xmm0
	X86_MEM_WRITE_u32(base, 0x54F368u, ctx.xmm[0].u32[0]);
	// 0x2646E8: ret
	return;
}

void sub_2646F0(X86Context& ctx, uint8_t* base) {
	// 0x2646F0: movss xmm0, dword ptr [0x003B1C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2646F8: movss [0x0054F394], xmm0
	X86_MEM_WRITE_u32(base, 0x54F394u, ctx.xmm[0].u32[0]);
	// 0x264700: ret
	return;
}

