#include "x86_recomp_shared.h"

void sub_2C7600(X86Context& ctx, uint8_t* base) {
	// 0x2C7600: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C7608: movss [0x0060E19C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E19Cu, ctx.xmm[0].u32[0]);
	// 0x2C7610: ret
	return;
}

void sub_2C7620(X86Context& ctx, uint8_t* base) {
	// 0x2C7620: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C7628: movss [0x0060E1A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1A8u, ctx.xmm[0].u32[0]);
	// 0x2C7630: ret
	return;
}

void sub_2C7640(X86Context& ctx, uint8_t* base) {
	// 0x2C7640: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C7648: movss [0x0060E198], xmm0
	X86_MEM_WRITE_u32(base, 0x60E198u, ctx.xmm[0].u32[0]);
	// 0x2C7650: ret
	return;
}

void sub_2C7660(X86Context& ctx, uint8_t* base) {
	// 0x2C7660: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C7668: movss [0x0060E020], xmm0
	X86_MEM_WRITE_u32(base, 0x60E020u, ctx.xmm[0].u32[0]);
	// 0x2C7670: ret
	return;
}

void sub_2C7680(X86Context& ctx, uint8_t* base) {
	// 0x2C7680: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C7688: movss [0x0060E1A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1A0u, ctx.xmm[0].u32[0]);
	// 0x2C7690: ret
	return;
}

void sub_2C76A0(X86Context& ctx, uint8_t* base) {
	// 0x2C76A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C76A8: movss [0x0060E028], xmm0
	X86_MEM_WRITE_u32(base, 0x60E028u, ctx.xmm[0].u32[0]);
	// 0x2C76B0: ret
	return;
}

void sub_2C76C0(X86Context& ctx, uint8_t* base) {
	// 0x2C76C0: movss xmm0, dword ptr [0x0060E1A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1A0u);
	// 0x2C76C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C76D0: movss [0x0060E1B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1B4u, ctx.xmm[0].u32[0]);
	// 0x2C76D8: ret
	return;
}

void sub_2C76E0(X86Context& ctx, uint8_t* base) {
	// 0x2C76E0: movss xmm0, dword ptr [0x0060E028]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E028u);
	// 0x2C76E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C76F0: movss [0x0060E1AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1ACu, ctx.xmm[0].u32[0]);
	// 0x2C76F8: ret
	return;
}

void sub_2C7700(X86Context& ctx, uint8_t* base) {
	// 0x2C7700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7708: movss [0x0060E1CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1CCu, ctx.xmm[0].u32[0]);
	// 0x2C7710: ret
	return;
}

void sub_2C7720(X86Context& ctx, uint8_t* base) {
	// 0x2C7720: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C7728: movss [0x0060E1B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1B8u, ctx.xmm[0].u32[0]);
	// 0x2C7730: ret
	return;
}

void sub_2C7740(X86Context& ctx, uint8_t* base) {
	// 0x2C7740: movss xmm0, dword ptr [0x0060E1B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1B8u);
	// 0x2C7748: movss [0x0060E1C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1C8u, ctx.xmm[0].u32[0]);
	// 0x2C7750: ret
	return;
}

void sub_2C7760(X86Context& ctx, uint8_t* base) {
	// 0x2C7760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7768: movss [0x0060E024], xmm0
	X86_MEM_WRITE_u32(base, 0x60E024u, ctx.xmm[0].u32[0]);
	// 0x2C7770: ret
	return;
}

void sub_2C7780(X86Context& ctx, uint8_t* base) {
	// 0x2C7780: movss xmm0, dword ptr [0x0060E028]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E028u);
	// 0x2C7788: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C7790: movss [0x0060E1BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1BCu, ctx.xmm[0].u32[0]);
	// 0x2C7798: ret
	return;
}

void sub_2C77A0(X86Context& ctx, uint8_t* base) {
	// 0x2C77A0: movss xmm0, dword ptr [0x0060E028]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E028u);
	// 0x2C77A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C77B0: movss [0x0060E190], xmm0
	X86_MEM_WRITE_u32(base, 0x60E190u, ctx.xmm[0].u32[0]);
	// 0x2C77B8: ret
	return;
}

void sub_2C77C0(X86Context& ctx, uint8_t* base) {
	// 0x2C77C0: movss xmm0, dword ptr [0x0060E028]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E028u);
	// 0x2C77C8: subss xmm0, [0x0060E190]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E190u);
	// 0x2C77D0: movss [0x0060E030], xmm0
	X86_MEM_WRITE_u32(base, 0x60E030u, ctx.xmm[0].u32[0]);
	// 0x2C77D8: ret
	return;
}

void sub_2C77E0(X86Context& ctx, uint8_t* base) {
	// 0x2C77E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C77E8: movss [0x0060E1A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1A4u, ctx.xmm[0].u32[0]);
	// 0x2C77F0: ret
	return;
}

void sub_2C7800(X86Context& ctx, uint8_t* base) {
	// 0x2C7800: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C7808: movss [0x0060E02C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E02Cu, ctx.xmm[0].u32[0]);
	// 0x2C7810: ret
	return;
}

void sub_2C7820(X86Context& ctx, uint8_t* base) {
	// 0x2C7820: movss xmm0, dword ptr [0x003B2140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2140u);
	// 0x2C7828: movss [0x0060E194], xmm0
	X86_MEM_WRITE_u32(base, 0x60E194u, ctx.xmm[0].u32[0]);
	// 0x2C7830: ret
	return;
}

void sub_2C7840(X86Context& ctx, uint8_t* base) {
	// 0x2C7840: movss xmm0, dword ptr [0x003B1A90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A90u);
	// 0x2C7848: movss [0x0060E1B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1B0u, ctx.xmm[0].u32[0]);
	// 0x2C7850: ret
	return;
}

void sub_2C7860(X86Context& ctx, uint8_t* base) {
	// 0x2C7860: movss xmm0, dword ptr [0x003B2140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2140u);
	// 0x2C7868: movss [0x0060E1C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1C0u, ctx.xmm[0].u32[0]);
	// 0x2C7870: ret
	return;
}

void sub_2C7880(X86Context& ctx, uint8_t* base) {
	// 0x2C7880: movss xmm0, dword ptr [0x003B1F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F50u);
	// 0x2C7888: movss [0x0060E1C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1C4u, ctx.xmm[0].u32[0]);
	// 0x2C7890: ret
	return;
}

void sub_2C78A0(X86Context& ctx, uint8_t* base) {
	// 0x2C78A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C78A8: movss [0x0060E1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1ECu, ctx.xmm[0].u32[0]);
	// 0x2C78B0: ret
	return;
}

void sub_2C78C0(X86Context& ctx, uint8_t* base) {
	// 0x2C78C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C78C8: movss [0x0060E1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1F4u, ctx.xmm[0].u32[0]);
	// 0x2C78D0: ret
	return;
}

void sub_2C78E0(X86Context& ctx, uint8_t* base) {
	// 0x2C78E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C78E8: movss [0x0060E1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1E8u, ctx.xmm[0].u32[0]);
	// 0x2C78F0: ret
	return;
}

void sub_2C7900(X86Context& ctx, uint8_t* base) {
	// 0x2C7900: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C7908: movss [0x0060E1D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1D0u, ctx.xmm[0].u32[0]);
	// 0x2C7910: ret
	return;
}

void sub_2C7920(X86Context& ctx, uint8_t* base) {
	// 0x2C7920: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C7928: movss [0x0060E1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1F0u, ctx.xmm[0].u32[0]);
	// 0x2C7930: ret
	return;
}

void sub_2C7940(X86Context& ctx, uint8_t* base) {
	// 0x2C7940: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C7948: movss [0x0060E1D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1D8u, ctx.xmm[0].u32[0]);
	// 0x2C7950: ret
	return;
}

void sub_2C7960(X86Context& ctx, uint8_t* base) {
	// 0x2C7960: movss xmm0, dword ptr [0x0060E1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1F0u);
	// 0x2C7968: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C7970: movss [0x0060E300], xmm0
	X86_MEM_WRITE_u32(base, 0x60E300u, ctx.xmm[0].u32[0]);
	// 0x2C7978: ret
	return;
}

void sub_2C7980(X86Context& ctx, uint8_t* base) {
	// 0x2C7980: movss xmm0, dword ptr [0x0060E1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1D8u);
	// 0x2C7988: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C7990: movss [0x0060E1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1FCu, ctx.xmm[0].u32[0]);
	// 0x2C7998: ret
	return;
}

void sub_2C79A0(X86Context& ctx, uint8_t* base) {
	// 0x2C79A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C79A8: movss [0x0060E310], xmm0
	X86_MEM_WRITE_u32(base, 0x60E310u, ctx.xmm[0].u32[0]);
	// 0x2C79B0: ret
	return;
}

void sub_2C79C0(X86Context& ctx, uint8_t* base) {
	// 0x2C79C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C79C8: movss [0x0060E304], xmm0
	X86_MEM_WRITE_u32(base, 0x60E304u, ctx.xmm[0].u32[0]);
	// 0x2C79D0: ret
	return;
}

void sub_2C79E0(X86Context& ctx, uint8_t* base) {
	// 0x2C79E0: movss xmm0, dword ptr [0x0060E304]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E304u);
	// 0x2C79E8: movss [0x0060E30C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E30Cu, ctx.xmm[0].u32[0]);
	// 0x2C79F0: ret
	return;
}

void sub_2C7A00(X86Context& ctx, uint8_t* base) {
	// 0x2C7A00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7A08: movss [0x0060E1D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1D4u, ctx.xmm[0].u32[0]);
	// 0x2C7A10: ret
	return;
}

void sub_2C7A20(X86Context& ctx, uint8_t* base) {
	// 0x2C7A20: movss xmm0, dword ptr [0x0060E1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1D8u);
	// 0x2C7A28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C7A30: movss [0x0060E308], xmm0
	X86_MEM_WRITE_u32(base, 0x60E308u, ctx.xmm[0].u32[0]);
	// 0x2C7A38: ret
	return;
}

void sub_2C7A40(X86Context& ctx, uint8_t* base) {
	// 0x2C7A40: movss xmm0, dword ptr [0x0060E1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1D8u);
	// 0x2C7A48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C7A50: movss [0x0060E1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1E4u, ctx.xmm[0].u32[0]);
	// 0x2C7A58: ret
	return;
}

void sub_2C7A60(X86Context& ctx, uint8_t* base) {
	// 0x2C7A60: movss xmm0, dword ptr [0x0060E1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E1D8u);
	// 0x2C7A68: subss xmm0, [0x0060E1E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E1E4u);
	// 0x2C7A70: movss [0x0060E1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1E0u, ctx.xmm[0].u32[0]);
	// 0x2C7A78: ret
	return;
}

void sub_2C7A80(X86Context& ctx, uint8_t* base) {
	// 0x2C7A80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C7A88: movss [0x0060E1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1F8u, ctx.xmm[0].u32[0]);
	// 0x2C7A90: ret
	return;
}

void sub_2C7AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C7AA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C7AA8: movss [0x0060E1DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E1DCu, ctx.xmm[0].u32[0]);
	// 0x2C7AB0: ret
	return;
}

void sub_2C7AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C7AC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C7AC8: movss [0x0060E330], xmm0
	X86_MEM_WRITE_u32(base, 0x60E330u, ctx.xmm[0].u32[0]);
	// 0x2C7AD0: ret
	return;
}

void sub_2C7AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C7AE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C7AE8: movss [0x0060E33C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E33Cu, ctx.xmm[0].u32[0]);
	// 0x2C7AF0: ret
	return;
}

void sub_2C7B00(X86Context& ctx, uint8_t* base) {
	// 0x2C7B00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C7B08: movss [0x0060E32C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E32Cu, ctx.xmm[0].u32[0]);
	// 0x2C7B10: ret
	return;
}

void sub_2C7B20(X86Context& ctx, uint8_t* base) {
	// 0x2C7B20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C7B28: movss [0x0060E314], xmm0
	X86_MEM_WRITE_u32(base, 0x60E314u, ctx.xmm[0].u32[0]);
	// 0x2C7B30: ret
	return;
}

void sub_2C7B40(X86Context& ctx, uint8_t* base) {
	// 0x2C7B40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C7B48: movss [0x0060E334], xmm0
	X86_MEM_WRITE_u32(base, 0x60E334u, ctx.xmm[0].u32[0]);
	// 0x2C7B50: ret
	return;
}

void sub_2C7B60(X86Context& ctx, uint8_t* base) {
	// 0x2C7B60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C7B68: movss [0x0060E31C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E31Cu, ctx.xmm[0].u32[0]);
	// 0x2C7B70: ret
	return;
}

void sub_2C7B80(X86Context& ctx, uint8_t* base) {
	// 0x2C7B80: movss xmm0, dword ptr [0x0060E334]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E334u);
	// 0x2C7B88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C7B90: movss [0x0060E344], xmm0
	X86_MEM_WRITE_u32(base, 0x60E344u, ctx.xmm[0].u32[0]);
	// 0x2C7B98: ret
	return;
}

void sub_2C7BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C7BA0: movss xmm0, dword ptr [0x0060E31C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E31Cu);
	// 0x2C7BA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C7BB0: movss [0x0060E340], xmm0
	X86_MEM_WRITE_u32(base, 0x60E340u, ctx.xmm[0].u32[0]);
	// 0x2C7BB8: ret
	return;
}

void sub_2C7BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C7BC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7BC8: movss [0x0060E354], xmm0
	X86_MEM_WRITE_u32(base, 0x60E354u, ctx.xmm[0].u32[0]);
	// 0x2C7BD0: ret
	return;
}

void sub_2C7BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C7BE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C7BE8: movss [0x0060E348], xmm0
	X86_MEM_WRITE_u32(base, 0x60E348u, ctx.xmm[0].u32[0]);
	// 0x2C7BF0: ret
	return;
}

void sub_2C7C00(X86Context& ctx, uint8_t* base) {
	// 0x2C7C00: movss xmm0, dword ptr [0x0060E348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E348u);
	// 0x2C7C08: movss [0x0060E350], xmm0
	X86_MEM_WRITE_u32(base, 0x60E350u, ctx.xmm[0].u32[0]);
	// 0x2C7C10: ret
	return;
}

void sub_2C7C20(X86Context& ctx, uint8_t* base) {
	// 0x2C7C20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7C28: movss [0x0060E318], xmm0
	X86_MEM_WRITE_u32(base, 0x60E318u, ctx.xmm[0].u32[0]);
	// 0x2C7C30: ret
	return;
}

void sub_2C7C40(X86Context& ctx, uint8_t* base) {
	// 0x2C7C40: movss xmm0, dword ptr [0x0060E31C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E31Cu);
	// 0x2C7C48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C7C50: movss [0x0060E34C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E34Cu, ctx.xmm[0].u32[0]);
	// 0x2C7C58: ret
	return;
}

void sub_2C7C60(X86Context& ctx, uint8_t* base) {
	// 0x2C7C60: movss xmm0, dword ptr [0x0060E31C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E31Cu);
	// 0x2C7C68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C7C70: movss [0x0060E328], xmm0
	X86_MEM_WRITE_u32(base, 0x60E328u, ctx.xmm[0].u32[0]);
	// 0x2C7C78: ret
	return;
}

void sub_2C7C80(X86Context& ctx, uint8_t* base) {
	// 0x2C7C80: movss xmm0, dword ptr [0x0060E31C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E31Cu);
	// 0x2C7C88: subss xmm0, [0x0060E328]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E328u);
	// 0x2C7C90: movss [0x0060E324], xmm0
	X86_MEM_WRITE_u32(base, 0x60E324u, ctx.xmm[0].u32[0]);
	// 0x2C7C98: ret
	return;
}

void sub_2C7CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C7CA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C7CA8: movss [0x0060E338], xmm0
	X86_MEM_WRITE_u32(base, 0x60E338u, ctx.xmm[0].u32[0]);
	// 0x2C7CB0: ret
	return;
}

void sub_2C7CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C7CC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C7CC8: movss [0x0060E320], xmm0
	X86_MEM_WRITE_u32(base, 0x60E320u, ctx.xmm[0].u32[0]);
	// 0x2C7CD0: ret
	return;
}

void sub_2C7CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C7CE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C7CE8: movss [0x0060E374], xmm0
	X86_MEM_WRITE_u32(base, 0x60E374u, ctx.xmm[0].u32[0]);
	// 0x2C7CF0: ret
	return;
}

void sub_2C7D00(X86Context& ctx, uint8_t* base) {
	// 0x2C7D00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C7D08: movss [0x0060E380], xmm0
	X86_MEM_WRITE_u32(base, 0x60E380u, ctx.xmm[0].u32[0]);
	// 0x2C7D10: ret
	return;
}

void sub_2C7D20(X86Context& ctx, uint8_t* base) {
	// 0x2C7D20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C7D28: movss [0x0060E370], xmm0
	X86_MEM_WRITE_u32(base, 0x60E370u, ctx.xmm[0].u32[0]);
	// 0x2C7D30: ret
	return;
}

void sub_2C7D40(X86Context& ctx, uint8_t* base) {
	// 0x2C7D40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C7D48: movss [0x0060E358], xmm0
	X86_MEM_WRITE_u32(base, 0x60E358u, ctx.xmm[0].u32[0]);
	// 0x2C7D50: ret
	return;
}

void sub_2C7D60(X86Context& ctx, uint8_t* base) {
	// 0x2C7D60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C7D68: movss [0x0060E378], xmm0
	X86_MEM_WRITE_u32(base, 0x60E378u, ctx.xmm[0].u32[0]);
	// 0x2C7D70: ret
	return;
}

void sub_2C7D80(X86Context& ctx, uint8_t* base) {
	// 0x2C7D80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C7D88: movss [0x0060E360], xmm0
	X86_MEM_WRITE_u32(base, 0x60E360u, ctx.xmm[0].u32[0]);
	// 0x2C7D90: ret
	return;
}

void sub_2C7DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C7DA0: movss xmm0, dword ptr [0x0060E378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E378u);
	// 0x2C7DA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C7DB0: movss [0x0060E388], xmm0
	X86_MEM_WRITE_u32(base, 0x60E388u, ctx.xmm[0].u32[0]);
	// 0x2C7DB8: ret
	return;
}

void sub_2C7DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C7DC0: movss xmm0, dword ptr [0x0060E360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E360u);
	// 0x2C7DC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C7DD0: movss [0x0060E384], xmm0
	X86_MEM_WRITE_u32(base, 0x60E384u, ctx.xmm[0].u32[0]);
	// 0x2C7DD8: ret
	return;
}

void sub_2C7DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C7DE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7DE8: movss [0x0060E398], xmm0
	X86_MEM_WRITE_u32(base, 0x60E398u, ctx.xmm[0].u32[0]);
	// 0x2C7DF0: ret
	return;
}

void sub_2C7E00(X86Context& ctx, uint8_t* base) {
	// 0x2C7E00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C7E08: movss [0x0060E38C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E38Cu, ctx.xmm[0].u32[0]);
	// 0x2C7E10: ret
	return;
}

void sub_2C7E20(X86Context& ctx, uint8_t* base) {
	// 0x2C7E20: movss xmm0, dword ptr [0x0060E38C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E38Cu);
	// 0x2C7E28: movss [0x0060E394], xmm0
	X86_MEM_WRITE_u32(base, 0x60E394u, ctx.xmm[0].u32[0]);
	// 0x2C7E30: ret
	return;
}

void sub_2C7E40(X86Context& ctx, uint8_t* base) {
	// 0x2C7E40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7E48: movss [0x0060E35C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E35Cu, ctx.xmm[0].u32[0]);
	// 0x2C7E50: ret
	return;
}

void sub_2C7E60(X86Context& ctx, uint8_t* base) {
	// 0x2C7E60: movss xmm0, dword ptr [0x0060E360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E360u);
	// 0x2C7E68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C7E70: movss [0x0060E390], xmm0
	X86_MEM_WRITE_u32(base, 0x60E390u, ctx.xmm[0].u32[0]);
	// 0x2C7E78: ret
	return;
}

void sub_2C7E80(X86Context& ctx, uint8_t* base) {
	// 0x2C7E80: movss xmm0, dword ptr [0x0060E360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E360u);
	// 0x2C7E88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C7E90: movss [0x0060E36C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E36Cu, ctx.xmm[0].u32[0]);
	// 0x2C7E98: ret
	return;
}

void sub_2C7EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C7EA0: movss xmm0, dword ptr [0x0060E360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E360u);
	// 0x2C7EA8: subss xmm0, [0x0060E36C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E36Cu);
	// 0x2C7EB0: movss [0x0060E368], xmm0
	X86_MEM_WRITE_u32(base, 0x60E368u, ctx.xmm[0].u32[0]);
	// 0x2C7EB8: ret
	return;
}

void sub_2C7EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C7EC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C7EC8: movss [0x0060E37C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E37Cu, ctx.xmm[0].u32[0]);
	// 0x2C7ED0: ret
	return;
}

void sub_2C7EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C7EE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C7EE8: movss [0x0060E364], xmm0
	X86_MEM_WRITE_u32(base, 0x60E364u, ctx.xmm[0].u32[0]);
	// 0x2C7EF0: ret
	return;
}

void sub_2C7F00(X86Context& ctx, uint8_t* base) {
	// 0x2C7F00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C7F08: movss [0x0060E3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3A0u, ctx.xmm[0].u32[0]);
	// 0x2C7F10: ret
	return;
}

void sub_2C7F20(X86Context& ctx, uint8_t* base) {
	// 0x2C7F20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C7F28: movss [0x0060E3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3A4u, ctx.xmm[0].u32[0]);
	// 0x2C7F30: ret
	return;
}

void sub_2C7F40(X86Context& ctx, uint8_t* base) {
	// 0x2C7F40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C7F48: movss [0x0060E39C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E39Cu, ctx.xmm[0].u32[0]);
	// 0x2C7F50: ret
	return;
}

void sub_2C7F60(X86Context& ctx, uint8_t* base) {
	// 0x2C7F60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C7F68: movss [0x0060E3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3C4u, ctx.xmm[0].u32[0]);
	// 0x2C7F70: ret
	return;
}

void sub_2C7F80(X86Context& ctx, uint8_t* base) {
	// 0x2C7F80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C7F88: movss [0x0060E3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3D0u, ctx.xmm[0].u32[0]);
	// 0x2C7F90: ret
	return;
}

void sub_2C7FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C7FA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C7FA8: movss [0x0060E3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3C0u, ctx.xmm[0].u32[0]);
	// 0x2C7FB0: ret
	return;
}

void sub_2C7FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C7FC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C7FC8: movss [0x0060E3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3A8u, ctx.xmm[0].u32[0]);
	// 0x2C7FD0: ret
	return;
}

void sub_2C7FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C7FE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C7FE8: movss [0x0060E3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3C8u, ctx.xmm[0].u32[0]);
	// 0x2C7FF0: ret
	return;
}

void sub_2C8000(X86Context& ctx, uint8_t* base) {
	// 0x2C8000: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8008: movss [0x0060E3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3B0u, ctx.xmm[0].u32[0]);
	// 0x2C8010: ret
	return;
}

void sub_2C8020(X86Context& ctx, uint8_t* base) {
	// 0x2C8020: movss xmm0, dword ptr [0x0060E3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3C8u);
	// 0x2C8028: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8030: movss [0x0060E3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3D8u, ctx.xmm[0].u32[0]);
	// 0x2C8038: ret
	return;
}

void sub_2C8040(X86Context& ctx, uint8_t* base) {
	// 0x2C8040: movss xmm0, dword ptr [0x0060E3B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3B0u);
	// 0x2C8048: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C8050: movss [0x0060E3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3D4u, ctx.xmm[0].u32[0]);
	// 0x2C8058: ret
	return;
}

void sub_2C8060(X86Context& ctx, uint8_t* base) {
	// 0x2C8060: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8068: movss [0x0060E3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3E8u, ctx.xmm[0].u32[0]);
	// 0x2C8070: ret
	return;
}

void sub_2C8080(X86Context& ctx, uint8_t* base) {
	// 0x2C8080: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C8088: movss [0x0060E3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3DCu, ctx.xmm[0].u32[0]);
	// 0x2C8090: ret
	return;
}

void sub_2C80A0(X86Context& ctx, uint8_t* base) {
	// 0x2C80A0: movss xmm0, dword ptr [0x0060E3DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3DCu);
	// 0x2C80A8: movss [0x0060E3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3E4u, ctx.xmm[0].u32[0]);
	// 0x2C80B0: ret
	return;
}

void sub_2C80C0(X86Context& ctx, uint8_t* base) {
	// 0x2C80C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C80C8: movss [0x0060E3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3ACu, ctx.xmm[0].u32[0]);
	// 0x2C80D0: ret
	return;
}

void sub_2C80E0(X86Context& ctx, uint8_t* base) {
	// 0x2C80E0: movss xmm0, dword ptr [0x0060E3B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3B0u);
	// 0x2C80E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C80F0: movss [0x0060E3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3E0u, ctx.xmm[0].u32[0]);
	// 0x2C80F8: ret
	return;
}

void sub_2C8100(X86Context& ctx, uint8_t* base) {
	// 0x2C8100: movss xmm0, dword ptr [0x0060E3B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3B0u);
	// 0x2C8108: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C8110: movss [0x0060E3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3BCu, ctx.xmm[0].u32[0]);
	// 0x2C8118: ret
	return;
}

void sub_2C8120(X86Context& ctx, uint8_t* base) {
	// 0x2C8120: movss xmm0, dword ptr [0x0060E3B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3B0u);
	// 0x2C8128: subss xmm0, [0x0060E3BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E3BCu);
	// 0x2C8130: movss [0x0060E3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3B8u, ctx.xmm[0].u32[0]);
	// 0x2C8138: ret
	return;
}

void sub_2C8140(X86Context& ctx, uint8_t* base) {
	// 0x2C8140: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C8148: movss [0x0060E3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3CCu, ctx.xmm[0].u32[0]);
	// 0x2C8150: ret
	return;
}

void sub_2C8160(X86Context& ctx, uint8_t* base) {
	// 0x2C8160: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C8168: movss [0x0060E3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3B4u, ctx.xmm[0].u32[0]);
	// 0x2C8170: ret
	return;
}

void sub_2C8180(X86Context& ctx, uint8_t* base) {
	// 0x2C8180: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C8188: movss [0x0060E408], xmm0
	X86_MEM_WRITE_u32(base, 0x60E408u, ctx.xmm[0].u32[0]);
	// 0x2C8190: ret
	return;
}

void sub_2C81A0(X86Context& ctx, uint8_t* base) {
	// 0x2C81A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C81A8: movss [0x0060E414], xmm0
	X86_MEM_WRITE_u32(base, 0x60E414u, ctx.xmm[0].u32[0]);
	// 0x2C81B0: ret
	return;
}

void sub_2C81C0(X86Context& ctx, uint8_t* base) {
	// 0x2C81C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C81C8: movss [0x0060E400], xmm0
	X86_MEM_WRITE_u32(base, 0x60E400u, ctx.xmm[0].u32[0]);
	// 0x2C81D0: ret
	return;
}

void sub_2C81E0(X86Context& ctx, uint8_t* base) {
	// 0x2C81E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C81E8: movss [0x0060E3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3ECu, ctx.xmm[0].u32[0]);
	// 0x2C81F0: ret
	return;
}

void sub_2C8200(X86Context& ctx, uint8_t* base) {
	// 0x2C8200: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C8208: movss [0x0060E40C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E40Cu, ctx.xmm[0].u32[0]);
	// 0x2C8210: ret
	return;
}

void sub_2C8220(X86Context& ctx, uint8_t* base) {
	// 0x2C8220: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C8228: movss [0x0060E3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3F0u, ctx.xmm[0].u32[0]);
	// 0x2C8230: ret
	return;
}

void sub_2C8240(X86Context& ctx, uint8_t* base) {
	// 0x2C8240: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8248: movss [0x0060E41C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E41Cu, ctx.xmm[0].u32[0]);
	// 0x2C8250: ret
	return;
}

void sub_2C8260(X86Context& ctx, uint8_t* base) {
	// 0x2C8260: movss xmm0, dword ptr [0x0060E3F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E3F0u);
	// 0x2C8268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8270: movss [0x0060E404], xmm0
	X86_MEM_WRITE_u32(base, 0x60E404u, ctx.xmm[0].u32[0]);
	// 0x2C8278: ret
	return;
}

void sub_2C8280(X86Context& ctx, uint8_t* base) {
	// 0x2C8280: movss xmm0, dword ptr [0x0060E41C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E41Cu);
	// 0x2C8288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C8290: movss [0x0060E418], xmm0
	X86_MEM_WRITE_u32(base, 0x60E418u, ctx.xmm[0].u32[0]);
	// 0x2C8298: ret
	return;
}

void sub_2C82A0(X86Context& ctx, uint8_t* base) {
	// 0x2C82A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C82A8: movss [0x0060E42C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E42Cu, ctx.xmm[0].u32[0]);
	// 0x2C82B0: ret
	return;
}

void sub_2C82C0(X86Context& ctx, uint8_t* base) {
	// 0x2C82C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C82C8: movss [0x0060E420], xmm0
	X86_MEM_WRITE_u32(base, 0x60E420u, ctx.xmm[0].u32[0]);
	// 0x2C82D0: ret
	return;
}

void sub_2C82E0(X86Context& ctx, uint8_t* base) {
	// 0x2C82E0: movss xmm0, dword ptr [0x0060E420]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E420u);
	// 0x2C82E8: movss [0x0060E428], xmm0
	X86_MEM_WRITE_u32(base, 0x60E428u, ctx.xmm[0].u32[0]);
	// 0x2C82F0: ret
	return;
}

void sub_2C8300(X86Context& ctx, uint8_t* base) {
	// 0x2C8300: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8308: movss [0x0060E424], xmm0
	X86_MEM_WRITE_u32(base, 0x60E424u, ctx.xmm[0].u32[0]);
	// 0x2C8310: ret
	return;
}

void sub_2C8320(X86Context& ctx, uint8_t* base) {
	// 0x2C8320: movss xmm0, dword ptr [0x0060E41C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E41Cu);
	// 0x2C8328: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C8330: movss [0x0060E3FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3FCu, ctx.xmm[0].u32[0]);
	// 0x2C8338: ret
	return;
}

void sub_2C8340(X86Context& ctx, uint8_t* base) {
	// 0x2C8340: movss xmm0, dword ptr [0x0060E41C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E41Cu);
	// 0x2C8348: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C8350: movss [0x0060E3F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3F8u, ctx.xmm[0].u32[0]);
	// 0x2C8358: ret
	return;
}

void sub_2C8360(X86Context& ctx, uint8_t* base) {
	// 0x2C8360: movss xmm0, dword ptr [0x0060E41C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E41Cu);
	// 0x2C8368: subss xmm0, [0x0060E3F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E3F8u);
	// 0x2C8370: movss [0x0060E410], xmm0
	X86_MEM_WRITE_u32(base, 0x60E410u, ctx.xmm[0].u32[0]);
	// 0x2C8378: ret
	return;
}

void sub_2C8380(X86Context& ctx, uint8_t* base) {
	// 0x2C8380: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C8388: movss [0x0060E3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E3F4u, ctx.xmm[0].u32[0]);
	// 0x2C8390: ret
	return;
}

void sub_2C83A0(X86Context& ctx, uint8_t* base) {
	// 0x2C83A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C83A8: movss [0x0060E450], xmm0
	X86_MEM_WRITE_u32(base, 0x60E450u, ctx.xmm[0].u32[0]);
	// 0x2C83B0: ret
	return;
}

void sub_2C83C0(X86Context& ctx, uint8_t* base) {
	// 0x2C83C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C83C8: movss [0x0060E448], xmm0
	X86_MEM_WRITE_u32(base, 0x60E448u, ctx.xmm[0].u32[0]);
	// 0x2C83D0: ret
	return;
}

void sub_2C83E0(X86Context& ctx, uint8_t* base) {
	// 0x2C83E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C83E8: movss [0x0060E470], xmm0
	X86_MEM_WRITE_u32(base, 0x60E470u, ctx.xmm[0].u32[0]);
	// 0x2C83F0: ret
	return;
}

void sub_2C8400(X86Context& ctx, uint8_t* base) {
	// 0x2C8400: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C8408: movss [0x0060E430], xmm0
	X86_MEM_WRITE_u32(base, 0x60E430u, ctx.xmm[0].u32[0]);
	// 0x2C8410: ret
	return;
}

void sub_2C8420(X86Context& ctx, uint8_t* base) {
	// 0x2C8420: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C8428: movss [0x0060E44C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E44Cu, ctx.xmm[0].u32[0]);
	// 0x2C8430: ret
	return;
}

void sub_2C8440(X86Context& ctx, uint8_t* base) {
	// 0x2C8440: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8448: movss [0x0060E438], xmm0
	X86_MEM_WRITE_u32(base, 0x60E438u, ctx.xmm[0].u32[0]);
	// 0x2C8450: ret
	return;
}

void sub_2C8460(X86Context& ctx, uint8_t* base) {
	// 0x2C8460: movss xmm0, dword ptr [0x0060E44C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E44Cu);
	// 0x2C8468: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8470: movss [0x0060E45C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E45Cu, ctx.xmm[0].u32[0]);
	// 0x2C8478: ret
	return;
}

void sub_2C8480(X86Context& ctx, uint8_t* base) {
	// 0x2C8480: movss xmm0, dword ptr [0x0060E438]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E438u);
	// 0x2C8488: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C8490: movss [0x0060E458], xmm0
	X86_MEM_WRITE_u32(base, 0x60E458u, ctx.xmm[0].u32[0]);
	// 0x2C8498: ret
	return;
}

void sub_2C84A0(X86Context& ctx, uint8_t* base) {
	// 0x2C84A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C84A8: movss [0x0060E46C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E46Cu, ctx.xmm[0].u32[0]);
	// 0x2C84B0: ret
	return;
}

void sub_2C84C0(X86Context& ctx, uint8_t* base) {
	// 0x2C84C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C84C8: movss [0x0060E460], xmm0
	X86_MEM_WRITE_u32(base, 0x60E460u, ctx.xmm[0].u32[0]);
	// 0x2C84D0: ret
	return;
}

void sub_2C84E0(X86Context& ctx, uint8_t* base) {
	// 0x2C84E0: movss xmm0, dword ptr [0x0060E460]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E460u);
	// 0x2C84E8: movss [0x0060E468], xmm0
	X86_MEM_WRITE_u32(base, 0x60E468u, ctx.xmm[0].u32[0]);
	// 0x2C84F0: ret
	return;
}

void sub_2C8500(X86Context& ctx, uint8_t* base) {
	// 0x2C8500: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8508: movss [0x0060E434], xmm0
	X86_MEM_WRITE_u32(base, 0x60E434u, ctx.xmm[0].u32[0]);
	// 0x2C8510: ret
	return;
}

void sub_2C8520(X86Context& ctx, uint8_t* base) {
	// 0x2C8520: movss xmm0, dword ptr [0x0060E438]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E438u);
	// 0x2C8528: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C8530: movss [0x0060E464], xmm0
	X86_MEM_WRITE_u32(base, 0x60E464u, ctx.xmm[0].u32[0]);
	// 0x2C8538: ret
	return;
}

void sub_2C8540(X86Context& ctx, uint8_t* base) {
	// 0x2C8540: movss xmm0, dword ptr [0x0060E438]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E438u);
	// 0x2C8548: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C8550: movss [0x0060E444], xmm0
	X86_MEM_WRITE_u32(base, 0x60E444u, ctx.xmm[0].u32[0]);
	// 0x2C8558: ret
	return;
}

void sub_2C8560(X86Context& ctx, uint8_t* base) {
	// 0x2C8560: movss xmm0, dword ptr [0x0060E438]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E438u);
	// 0x2C8568: subss xmm0, [0x0060E444]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E444u);
	// 0x2C8570: movss [0x0060E440], xmm0
	X86_MEM_WRITE_u32(base, 0x60E440u, ctx.xmm[0].u32[0]);
	// 0x2C8578: ret
	return;
}

void sub_2C8580(X86Context& ctx, uint8_t* base) {
	// 0x2C8580: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C8588: movss [0x0060E454], xmm0
	X86_MEM_WRITE_u32(base, 0x60E454u, ctx.xmm[0].u32[0]);
	// 0x2C8590: ret
	return;
}

void sub_2C85A0(X86Context& ctx, uint8_t* base) {
	// 0x2C85A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C85A8: movss [0x0060E43C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E43Cu, ctx.xmm[0].u32[0]);
	// 0x2C85B0: ret
	return;
}

void sub_2C85C0(X86Context& ctx, uint8_t* base) {
	// 0x2C85C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C85C8: movss [0x0060E4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4D0u, ctx.xmm[0].u32[0]);
	// 0x2C85D0: ret
	return;
}

void sub_2C85E0(X86Context& ctx, uint8_t* base) {
	// 0x2C85E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C85E8: movss [0x0060E4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4ECu, ctx.xmm[0].u32[0]);
	// 0x2C85F0: ret
	return;
}

void sub_2C8600(X86Context& ctx, uint8_t* base) {
	// 0x2C8600: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C8608: movss [0x0060E4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4C0u, ctx.xmm[0].u32[0]);
	// 0x2C8610: ret
	return;
}

void sub_2C8620(X86Context& ctx, uint8_t* base) {
	// 0x2C8620: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C8628: movss [0x0060E474], xmm0
	X86_MEM_WRITE_u32(base, 0x60E474u, ctx.xmm[0].u32[0]);
	// 0x2C8630: ret
	return;
}

void sub_2C8640(X86Context& ctx, uint8_t* base) {
	// 0x2C8640: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C8648: movss [0x0060E4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4D4u, ctx.xmm[0].u32[0]);
	// 0x2C8650: ret
	return;
}

void sub_2C8660(X86Context& ctx, uint8_t* base) {
	// 0x2C8660: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8668: movss [0x0060E490], xmm0
	X86_MEM_WRITE_u32(base, 0x60E490u, ctx.xmm[0].u32[0]);
	// 0x2C8670: ret
	return;
}

void sub_2C8680(X86Context& ctx, uint8_t* base) {
	// 0x2C8680: movss xmm0, dword ptr [0x0060E4D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4D4u);
	// 0x2C8688: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8690: movss [0x0060E50C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E50Cu, ctx.xmm[0].u32[0]);
	// 0x2C8698: ret
	return;
}

void sub_2C86A0(X86Context& ctx, uint8_t* base) {
	// 0x2C86A0: movss xmm0, dword ptr [0x0060E490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E490u);
	// 0x2C86A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C86B0: movss [0x0060E4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4F4u, ctx.xmm[0].u32[0]);
	// 0x2C86B8: ret
	return;
}

void sub_2C86C0(X86Context& ctx, uint8_t* base) {
	// 0x2C86C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C86C8: movss [0x0060E524], xmm0
	X86_MEM_WRITE_u32(base, 0x60E524u, ctx.xmm[0].u32[0]);
	// 0x2C86D0: ret
	return;
}

void sub_2C86E0(X86Context& ctx, uint8_t* base) {
	// 0x2C86E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C86E8: movss [0x0060E510], xmm0
	X86_MEM_WRITE_u32(base, 0x60E510u, ctx.xmm[0].u32[0]);
	// 0x2C86F0: ret
	return;
}

void sub_2C8700(X86Context& ctx, uint8_t* base) {
	// 0x2C8700: movss xmm0, dword ptr [0x0060E510]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E510u);
	// 0x2C8708: movss [0x0060E520], xmm0
	X86_MEM_WRITE_u32(base, 0x60E520u, ctx.xmm[0].u32[0]);
	// 0x2C8710: ret
	return;
}

void sub_2C8720(X86Context& ctx, uint8_t* base) {
	// 0x2C8720: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8728: movss [0x0060E47C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E47Cu, ctx.xmm[0].u32[0]);
	// 0x2C8730: ret
	return;
}

void sub_2C8740(X86Context& ctx, uint8_t* base) {
	// 0x2C8740: movss xmm0, dword ptr [0x0060E490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E490u);
	// 0x2C8748: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C8750: movss [0x0060E518], xmm0
	X86_MEM_WRITE_u32(base, 0x60E518u, ctx.xmm[0].u32[0]);
	// 0x2C8758: ret
	return;
}

void sub_2C8760(X86Context& ctx, uint8_t* base) {
	// 0x2C8760: movss xmm0, dword ptr [0x0060E490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E490u);
	// 0x2C8768: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C8770: movss [0x0060E4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4BCu, ctx.xmm[0].u32[0]);
	// 0x2C8778: ret
	return;
}

void sub_2C8780(X86Context& ctx, uint8_t* base) {
	// 0x2C8780: movss xmm0, dword ptr [0x0060E490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E490u);
	// 0x2C8788: subss xmm0, [0x0060E4BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E4BCu);
	// 0x2C8790: movss [0x0060E498], xmm0
	X86_MEM_WRITE_u32(base, 0x60E498u, ctx.xmm[0].u32[0]);
	// 0x2C8798: ret
	return;
}

void sub_2C87A0(X86Context& ctx, uint8_t* base) {
	// 0x2C87A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C87A8: movss [0x0060E4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4E8u, ctx.xmm[0].u32[0]);
	// 0x2C87B0: ret
	return;
}

void sub_2C87C0(X86Context& ctx, uint8_t* base) {
	// 0x2C87C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C87C8: movss [0x0060E494], xmm0
	X86_MEM_WRITE_u32(base, 0x60E494u, ctx.xmm[0].u32[0]);
	// 0x2C87D0: ret
	return;
}

void sub_2C87E0(X86Context& ctx, uint8_t* base) {
	// 0x2C87E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C87E8: movss [0x0060E4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4A8u, ctx.xmm[0].u32[0]);
	// 0x2C87F0: ret
	return;
}

void sub_2C8800(X86Context& ctx, uint8_t* base) {
	// 0x2C8800: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8808: movss [0x0060E500], xmm0
	X86_MEM_WRITE_u32(base, 0x60E500u, ctx.xmm[0].u32[0]);
	// 0x2C8810: ret
	return;
}

void sub_2C8820(X86Context& ctx, uint8_t* base) {
	// 0x2C8820: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2C8828: movss [0x0060E4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4E4u, ctx.xmm[0].u32[0]);
	// 0x2C8830: ret
	return;
}

void sub_2C8840(X86Context& ctx, uint8_t* base) {
	// 0x2C8840: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2C8848: movss [0x0060E48C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E48Cu, ctx.xmm[0].u32[0]);
	// 0x2C8850: ret
	return;
}

void sub_2C8860(X86Context& ctx, uint8_t* base) {
	// 0x2C8860: movss xmm0, dword ptr [0x0060E4A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4A8u);
	// 0x2C8868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8870: movss [0x0060E480], xmm0
	X86_MEM_WRITE_u32(base, 0x60E480u, ctx.xmm[0].u32[0]);
	// 0x2C8878: ret
	return;
}

void sub_2C8880(X86Context& ctx, uint8_t* base) {
	// 0x2C8880: movss xmm0, dword ptr [0x0060E500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E500u);
	// 0x2C8888: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C8890: movss [0x0060E4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4C8u, ctx.xmm[0].u32[0]);
	// 0x2C8898: ret
	return;
}

void sub_2C88A0(X86Context& ctx, uint8_t* base) {
	// 0x2C88A0: movss xmm0, dword ptr [0x0060E480]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E480u);
	// 0x2C88A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C88B0: movss [0x0060E4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4DCu, ctx.xmm[0].u32[0]);
	// 0x2C88B8: ret
	return;
}

void sub_2C88C0(X86Context& ctx, uint8_t* base) {
	// 0x2C88C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C88C8: movss [0x0060E478], xmm0
	X86_MEM_WRITE_u32(base, 0x60E478u, ctx.xmm[0].u32[0]);
	// 0x2C88D0: ret
	return;
}

void sub_2C88E0(X86Context& ctx, uint8_t* base) {
	// 0x2C88E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C88E8: movss [0x0060E4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4ACu, ctx.xmm[0].u32[0]);
	// 0x2C88F0: ret
	return;
}

void sub_2C8900(X86Context& ctx, uint8_t* base) {
	// 0x2C8900: movss xmm0, dword ptr [0x0060E4A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4A8u);
	// 0x2C8908: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C8910: movss [0x0060E4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4B8u, ctx.xmm[0].u32[0]);
	// 0x2C8918: ret
	return;
}

void sub_2C8920(X86Context& ctx, uint8_t* base) {
	// 0x2C8920: movss xmm0, dword ptr [0x0060E500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E500u);
	// 0x2C8928: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C8930: movss [0x0060E504], xmm0
	X86_MEM_WRITE_u32(base, 0x60E504u, ctx.xmm[0].u32[0]);
	// 0x2C8938: ret
	return;
}

void sub_2C8940(X86Context& ctx, uint8_t* base) {
	// 0x2C8940: movss xmm0, dword ptr [0x0060E4B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4B8u);
	// 0x2C8948: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C8950: movss [0x0060E4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4F0u, ctx.xmm[0].u32[0]);
	// 0x2C8958: ret
	return;
}

void sub_2C8960(X86Context& ctx, uint8_t* base) {
	// 0x2C8960: movss xmm0, dword ptr [0x0060E504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E504u);
	// 0x2C8968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C8970: movss [0x0060E514], xmm0
	X86_MEM_WRITE_u32(base, 0x60E514u, ctx.xmm[0].u32[0]);
	// 0x2C8978: ret
	return;
}

void sub_2C8980(X86Context& ctx, uint8_t* base) {
	// 0x2C8980: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2C8988: movss [0x0060E484], xmm0
	X86_MEM_WRITE_u32(base, 0x60E484u, ctx.xmm[0].u32[0]);
	// 0x2C8990: ret
	return;
}

void sub_2C89A0(X86Context& ctx, uint8_t* base) {
	// 0x2C89A0: movss xmm0, dword ptr [0x0060E4A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4A8u);
	// 0x2C89A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C89B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2C89B8: movss [0x0060E4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4FCu, ctx.xmm[0].u32[0]);
	// 0x2C89C0: ret
	return;
}

void sub_2C89D0(X86Context& ctx, uint8_t* base) {
	// 0x2C89D0: movss xmm0, dword ptr [0x0060E500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E500u);
	// 0x2C89D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C89E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2C89E8: movss [0x0060E49C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E49Cu, ctx.xmm[0].u32[0]);
	// 0x2C89F0: ret
	return;
}

void sub_2C8A00(X86Context& ctx, uint8_t* base) {
	// 0x2C8A00: movss xmm0, dword ptr [0x0060E4A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4A8u);
	// 0x2C8A08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C8A10: movss [0x0060E4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4A0u, ctx.xmm[0].u32[0]);
	// 0x2C8A18: ret
	return;
}

void sub_2C8A20(X86Context& ctx, uint8_t* base) {
	// 0x2C8A20: movss xmm0, dword ptr [0x0060E500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E500u);
	// 0x2C8A28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C8A30: movss [0x0060E508], xmm0
	X86_MEM_WRITE_u32(base, 0x60E508u, ctx.xmm[0].u32[0]);
	// 0x2C8A38: ret
	return;
}

void sub_2C8A40(X86Context& ctx, uint8_t* base) {
	// 0x2C8A40: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2C8A48: movss [0x0060E488], xmm0
	X86_MEM_WRITE_u32(base, 0x60E488u, ctx.xmm[0].u32[0]);
	// 0x2C8A50: ret
	return;
}

void sub_2C8A60(X86Context& ctx, uint8_t* base) {
	// 0x2C8A60: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2C8A68: movss [0x0060E4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4B4u, ctx.xmm[0].u32[0]);
	// 0x2C8A70: ret
	return;
}

void sub_2C8A80(X86Context& ctx, uint8_t* base) {
	// 0x2C8A80: movss xmm0, dword ptr [0x0060E488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E488u);
	// 0x2C8A88: movss [0x0060E51C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E51Cu, ctx.xmm[0].u32[0]);
	// 0x2C8A90: ret
	return;
}

void sub_2C8AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C8AA0: movss xmm0, dword ptr [0x0060E500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E500u);
	// 0x2C8AA8: subss xmm0, [0x0060E488]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E488u);
	// 0x2C8AB0: movss [0x0060E4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4E0u, ctx.xmm[0].u32[0]);
	// 0x2C8AB8: ret
	return;
}

void sub_2C8AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C8AC0: movss xmm0, dword ptr [0x0060E4E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4E0u);
	// 0x2C8AC8: subss xmm0, [0x0060E4B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E4B4u);
	// 0x2C8AD0: movss [0x0060E4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4D8u, ctx.xmm[0].u32[0]);
	// 0x2C8AD8: ret
	return;
}

void sub_2C8AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C8AE0: movss xmm0, dword ptr [0x0060E508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E508u);
	// 0x2C8AE8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2C8AF0: movss [0x0060E4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4C4u, ctx.xmm[0].u32[0]);
	// 0x2C8AF8: ret
	return;
}

void sub_2C8B00(X86Context& ctx, uint8_t* base) {
	// 0x2C8B00: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2C8B08: movss [0x0060E4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4B0u, ctx.xmm[0].u32[0]);
	// 0x2C8B10: ret
	return;
}

void sub_2C8B20(X86Context& ctx, uint8_t* base) {
	// 0x2C8B20: movss xmm0, dword ptr [0x0060E4C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E4C4u);
	// 0x2C8B28: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2C8B30: movss [0x0060E4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4F8u, ctx.xmm[0].u32[0]);
	// 0x2C8B38: ret
	return;
}

void sub_2C8B40(X86Context& ctx, uint8_t* base) {
	// 0x2C8B40: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2C8B48: movss [0x0060E4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4CCu, ctx.xmm[0].u32[0]);
	// 0x2C8B50: ret
	return;
}

void sub_2C8B60(X86Context& ctx, uint8_t* base) {
	// 0x2C8B60: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2C8B68: movss [0x0060E4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E4A4u, ctx.xmm[0].u32[0]);
	// 0x2C8B70: ret
	return;
}

void sub_2C8B80(X86Context& ctx, uint8_t* base) {
	// 0x2C8B80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C8B88: movss [0x0060E54C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E54Cu, ctx.xmm[0].u32[0]);
	// 0x2C8B90: ret
	return;
}

void sub_2C8BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C8BA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C8BA8: movss [0x0060E558], xmm0
	X86_MEM_WRITE_u32(base, 0x60E558u, ctx.xmm[0].u32[0]);
	// 0x2C8BB0: ret
	return;
}

void sub_2C8BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C8BC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C8BC8: movss [0x0060E544], xmm0
	X86_MEM_WRITE_u32(base, 0x60E544u, ctx.xmm[0].u32[0]);
	// 0x2C8BD0: ret
	return;
}

void sub_2C8BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C8BE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C8BE8: movss [0x0060E528], xmm0
	X86_MEM_WRITE_u32(base, 0x60E528u, ctx.xmm[0].u32[0]);
	// 0x2C8BF0: ret
	return;
}

void sub_2C8C00(X86Context& ctx, uint8_t* base) {
	// 0x2C8C00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C8C08: movss [0x0060E550], xmm0
	X86_MEM_WRITE_u32(base, 0x60E550u, ctx.xmm[0].u32[0]);
	// 0x2C8C10: ret
	return;
}

void sub_2C8C20(X86Context& ctx, uint8_t* base) {
	// 0x2C8C20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C8C28: movss [0x0060E52C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E52Cu, ctx.xmm[0].u32[0]);
	// 0x2C8C30: ret
	return;
}

void sub_2C8C40(X86Context& ctx, uint8_t* base) {
	// 0x2C8C40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C8C48: movss [0x0060E564], xmm0
	X86_MEM_WRITE_u32(base, 0x60E564u, ctx.xmm[0].u32[0]);
	// 0x2C8C50: ret
	return;
}

void sub_2C8C60(X86Context& ctx, uint8_t* base) {
	// 0x2C8C60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8C68: movss [0x0060E548], xmm0
	X86_MEM_WRITE_u32(base, 0x60E548u, ctx.xmm[0].u32[0]);
	// 0x2C8C70: ret
	return;
}

void sub_2C8C80(X86Context& ctx, uint8_t* base) {
	// 0x2C8C80: movss xmm0, dword ptr [0x0060E564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E564u);
	// 0x2C8C88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8C90: movss [0x0060E534], xmm0
	X86_MEM_WRITE_u32(base, 0x60E534u, ctx.xmm[0].u32[0]);
	// 0x2C8C98: ret
	return;
}

void sub_2C8CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C8CA0: movss xmm0, dword ptr [0x0060E548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E548u);
	// 0x2C8CA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C8CB0: movss [0x0060E55C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E55Cu, ctx.xmm[0].u32[0]);
	// 0x2C8CB8: ret
	return;
}

void sub_2C8CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C8CC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8CC8: movss [0x0060E574], xmm0
	X86_MEM_WRITE_u32(base, 0x60E574u, ctx.xmm[0].u32[0]);
	// 0x2C8CD0: ret
	return;
}

void sub_2C8CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C8CE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C8CE8: movss [0x0060E568], xmm0
	X86_MEM_WRITE_u32(base, 0x60E568u, ctx.xmm[0].u32[0]);
	// 0x2C8CF0: ret
	return;
}

void sub_2C8D00(X86Context& ctx, uint8_t* base) {
	// 0x2C8D00: movss xmm0, dword ptr [0x0060E568]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E568u);
	// 0x2C8D08: movss [0x0060E56C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E56Cu, ctx.xmm[0].u32[0]);
	// 0x2C8D10: ret
	return;
}

void sub_2C8D20(X86Context& ctx, uint8_t* base) {
	// 0x2C8D20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8D28: movss [0x0060E53C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E53Cu, ctx.xmm[0].u32[0]);
	// 0x2C8D30: ret
	return;
}

void sub_2C8D40(X86Context& ctx, uint8_t* base) {
	// 0x2C8D40: movss xmm0, dword ptr [0x0060E548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E548u);
	// 0x2C8D48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C8D50: movss [0x0060E538], xmm0
	X86_MEM_WRITE_u32(base, 0x60E538u, ctx.xmm[0].u32[0]);
	// 0x2C8D58: ret
	return;
}

void sub_2C8D60(X86Context& ctx, uint8_t* base) {
	// 0x2C8D60: movss xmm0, dword ptr [0x0060E548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E548u);
	// 0x2C8D68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C8D70: movss [0x0060E554], xmm0
	X86_MEM_WRITE_u32(base, 0x60E554u, ctx.xmm[0].u32[0]);
	// 0x2C8D78: ret
	return;
}

void sub_2C8D80(X86Context& ctx, uint8_t* base) {
	// 0x2C8D80: movss xmm0, dword ptr [0x0060E548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E548u);
	// 0x2C8D88: subss xmm0, [0x0060E554]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E554u);
	// 0x2C8D90: movss [0x0060E530], xmm0
	X86_MEM_WRITE_u32(base, 0x60E530u, ctx.xmm[0].u32[0]);
	// 0x2C8D98: ret
	return;
}

void sub_2C8DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C8DA0: movss xmm0, dword ptr [0x003A795C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A795Cu);
	// 0x2C8DA8: movss [0x0060E570], xmm0
	X86_MEM_WRITE_u32(base, 0x60E570u, ctx.xmm[0].u32[0]);
	// 0x2C8DB0: ret
	return;
}

void sub_2C8DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C8DC0: movss xmm0, dword ptr [0x003A292C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A292Cu);
	// 0x2C8DC8: movss [0x0060E560], xmm0
	X86_MEM_WRITE_u32(base, 0x60E560u, ctx.xmm[0].u32[0]);
	// 0x2C8DD0: ret
	return;
}

void sub_2C8DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C8DE0: movss xmm0, dword ptr [0x003B03F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B03F4u);
	// 0x2C8DE8: movss [0x0060E540], xmm0
	X86_MEM_WRITE_u32(base, 0x60E540u, ctx.xmm[0].u32[0]);
	// 0x2C8DF0: ret
	return;
}

void sub_2C8E00(X86Context& ctx, uint8_t* base) {
	// 0x2C8E00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C8E08: movss [0x0060E580], xmm0
	X86_MEM_WRITE_u32(base, 0x60E580u, ctx.xmm[0].u32[0]);
	// 0x2C8E10: ret
	return;
}

void sub_2C8E20(X86Context& ctx, uint8_t* base) {
	// 0x2C8E20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C8E28: movss [0x0060E584], xmm0
	X86_MEM_WRITE_u32(base, 0x60E584u, ctx.xmm[0].u32[0]);
	// 0x2C8E30: ret
	return;
}

void sub_2C8E40(X86Context& ctx, uint8_t* base) {
	// 0x2C8E40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C8E48: movss [0x0060E57C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E57Cu, ctx.xmm[0].u32[0]);
	// 0x2C8E50: ret
	return;
}

void sub_2C8E60(X86Context& ctx, uint8_t* base) {
	// 0x2C8E60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C8E68: movss [0x0060E578], xmm0
	X86_MEM_WRITE_u32(base, 0x60E578u, ctx.xmm[0].u32[0]);
	// 0x2C8E70: ret
	return;
}

void sub_2C8E80(X86Context& ctx, uint8_t* base) {
	// 0x2C8E80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C8E88: movss [0x0060E5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5A8u, ctx.xmm[0].u32[0]);
	// 0x2C8E90: ret
	return;
}

void sub_2C8EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C8EA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C8EA8: movss [0x0060E5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5B4u, ctx.xmm[0].u32[0]);
	// 0x2C8EB0: ret
	return;
}

void sub_2C8EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C8EC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C8EC8: movss [0x0060E5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5A0u, ctx.xmm[0].u32[0]);
	// 0x2C8ED0: ret
	return;
}

void sub_2C8EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C8EE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C8EE8: movss [0x0060E588], xmm0
	X86_MEM_WRITE_u32(base, 0x60E588u, ctx.xmm[0].u32[0]);
	// 0x2C8EF0: ret
	return;
}

void sub_2C8F00(X86Context& ctx, uint8_t* base) {
	// 0x2C8F00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C8F08: movss [0x0060E5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5ACu, ctx.xmm[0].u32[0]);
	// 0x2C8F10: ret
	return;
}

void sub_2C8F20(X86Context& ctx, uint8_t* base) {
	// 0x2C8F20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C8F28: movss [0x0060E58C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E58Cu, ctx.xmm[0].u32[0]);
	// 0x2C8F30: ret
	return;
}

void sub_2C8F40(X86Context& ctx, uint8_t* base) {
	// 0x2C8F40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C8F48: movss [0x0060E5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5BCu, ctx.xmm[0].u32[0]);
	// 0x2C8F50: ret
	return;
}

void sub_2C8F60(X86Context& ctx, uint8_t* base) {
	// 0x2C8F60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C8F68: movss [0x0060E5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5A4u, ctx.xmm[0].u32[0]);
	// 0x2C8F70: ret
	return;
}

void sub_2C8F80(X86Context& ctx, uint8_t* base) {
	// 0x2C8F80: movss xmm0, dword ptr [0x0060E5BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5BCu);
	// 0x2C8F88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C8F90: movss [0x0060E594], xmm0
	X86_MEM_WRITE_u32(base, 0x60E594u, ctx.xmm[0].u32[0]);
	// 0x2C8F98: ret
	return;
}

void sub_2C8FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C8FA0: movss xmm0, dword ptr [0x0060E5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5A4u);
	// 0x2C8FA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C8FB0: movss [0x0060E5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5B8u, ctx.xmm[0].u32[0]);
	// 0x2C8FB8: ret
	return;
}

void sub_2C8FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C8FC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C8FC8: movss [0x0060E5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5C8u, ctx.xmm[0].u32[0]);
	// 0x2C8FD0: ret
	return;
}

void sub_2C8FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C8FE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C8FE8: movss [0x0060E5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5C0u, ctx.xmm[0].u32[0]);
	// 0x2C8FF0: ret
	return;
}

void sub_2C9000(X86Context& ctx, uint8_t* base) {
	// 0x2C9000: movss xmm0, dword ptr [0x0060E5C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5C0u);
	// 0x2C9008: movss [0x0060E5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5C4u, ctx.xmm[0].u32[0]);
	// 0x2C9010: ret
	return;
}

void sub_2C9020(X86Context& ctx, uint8_t* base) {
	// 0x2C9020: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9028: movss [0x0060E59C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E59Cu, ctx.xmm[0].u32[0]);
	// 0x2C9030: ret
	return;
}

void sub_2C9040(X86Context& ctx, uint8_t* base) {
	// 0x2C9040: movss xmm0, dword ptr [0x0060E5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5A4u);
	// 0x2C9048: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9050: movss [0x0060E598], xmm0
	X86_MEM_WRITE_u32(base, 0x60E598u, ctx.xmm[0].u32[0]);
	// 0x2C9058: ret
	return;
}

void sub_2C9060(X86Context& ctx, uint8_t* base) {
	// 0x2C9060: movss xmm0, dword ptr [0x0060E5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5A4u);
	// 0x2C9068: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C9070: movss [0x0060E5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5B0u, ctx.xmm[0].u32[0]);
	// 0x2C9078: ret
	return;
}

void sub_2C9080(X86Context& ctx, uint8_t* base) {
	// 0x2C9080: movss xmm0, dword ptr [0x0060E5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5A4u);
	// 0x2C9088: subss xmm0, [0x0060E5B0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E5B0u);
	// 0x2C9090: movss [0x0060E590], xmm0
	X86_MEM_WRITE_u32(base, 0x60E590u, ctx.xmm[0].u32[0]);
	// 0x2C9098: ret
	return;
}

void sub_2C90A0(X86Context& ctx, uint8_t* base) {
	// 0x2C90A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C90A8: movss [0x0060E5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5E8u, ctx.xmm[0].u32[0]);
	// 0x2C90B0: ret
	return;
}

void sub_2C90C0(X86Context& ctx, uint8_t* base) {
	// 0x2C90C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C90C8: movss [0x0060E5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5F4u, ctx.xmm[0].u32[0]);
	// 0x2C90D0: ret
	return;
}

void sub_2C90E0(X86Context& ctx, uint8_t* base) {
	// 0x2C90E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C90E8: movss [0x0060E5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5E4u, ctx.xmm[0].u32[0]);
	// 0x2C90F0: ret
	return;
}

void sub_2C9100(X86Context& ctx, uint8_t* base) {
	// 0x2C9100: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9108: movss [0x0060E5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5CCu, ctx.xmm[0].u32[0]);
	// 0x2C9110: ret
	return;
}

void sub_2C9120(X86Context& ctx, uint8_t* base) {
	// 0x2C9120: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C9128: movss [0x0060E5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5ECu, ctx.xmm[0].u32[0]);
	// 0x2C9130: ret
	return;
}

void sub_2C9140(X86Context& ctx, uint8_t* base) {
	// 0x2C9140: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C9148: movss [0x0060E5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5D4u, ctx.xmm[0].u32[0]);
	// 0x2C9150: ret
	return;
}

void sub_2C9160(X86Context& ctx, uint8_t* base) {
	// 0x2C9160: movss xmm0, dword ptr [0x0060E5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5ECu);
	// 0x2C9168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C9170: movss [0x0060E5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5FCu, ctx.xmm[0].u32[0]);
	// 0x2C9178: ret
	return;
}

void sub_2C9180(X86Context& ctx, uint8_t* base) {
	// 0x2C9180: movss xmm0, dword ptr [0x0060E5D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5D4u);
	// 0x2C9188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C9190: movss [0x0060E5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5F8u, ctx.xmm[0].u32[0]);
	// 0x2C9198: ret
	return;
}

void sub_2C91A0(X86Context& ctx, uint8_t* base) {
	// 0x2C91A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C91A8: movss [0x0060E60C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E60Cu, ctx.xmm[0].u32[0]);
	// 0x2C91B0: ret
	return;
}

void sub_2C91C0(X86Context& ctx, uint8_t* base) {
	// 0x2C91C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C91C8: movss [0x0060E600], xmm0
	X86_MEM_WRITE_u32(base, 0x60E600u, ctx.xmm[0].u32[0]);
	// 0x2C91D0: ret
	return;
}

void sub_2C91E0(X86Context& ctx, uint8_t* base) {
	// 0x2C91E0: movss xmm0, dword ptr [0x0060E600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E600u);
	// 0x2C91E8: movss [0x0060E608], xmm0
	X86_MEM_WRITE_u32(base, 0x60E608u, ctx.xmm[0].u32[0]);
	// 0x2C91F0: ret
	return;
}

void sub_2C9200(X86Context& ctx, uint8_t* base) {
	// 0x2C9200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9208: movss [0x0060E5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5D0u, ctx.xmm[0].u32[0]);
	// 0x2C9210: ret
	return;
}

void sub_2C9220(X86Context& ctx, uint8_t* base) {
	// 0x2C9220: movss xmm0, dword ptr [0x0060E5D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5D4u);
	// 0x2C9228: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9230: movss [0x0060E604], xmm0
	X86_MEM_WRITE_u32(base, 0x60E604u, ctx.xmm[0].u32[0]);
	// 0x2C9238: ret
	return;
}

void sub_2C9240(X86Context& ctx, uint8_t* base) {
	// 0x2C9240: movss xmm0, dword ptr [0x0060E5D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5D4u);
	// 0x2C9248: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C9250: movss [0x0060E5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5E0u, ctx.xmm[0].u32[0]);
	// 0x2C9258: ret
	return;
}

void sub_2C9260(X86Context& ctx, uint8_t* base) {
	// 0x2C9260: movss xmm0, dword ptr [0x0060E5D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E5D4u);
	// 0x2C9268: subss xmm0, [0x0060E5E0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E5E0u);
	// 0x2C9270: movss [0x0060E5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5DCu, ctx.xmm[0].u32[0]);
	// 0x2C9278: ret
	return;
}

void sub_2C9280(X86Context& ctx, uint8_t* base) {
	// 0x2C9280: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C9288: movss [0x0060E5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5F0u, ctx.xmm[0].u32[0]);
	// 0x2C9290: ret
	return;
}

void sub_2C92A0(X86Context& ctx, uint8_t* base) {
	// 0x2C92A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C92A8: movss [0x0060E5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E5D8u, ctx.xmm[0].u32[0]);
	// 0x2C92B0: ret
	return;
}

void sub_2C92C0(X86Context& ctx, uint8_t* base) {
	// 0x2C92C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C92C8: movss [0x0060E62C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E62Cu, ctx.xmm[0].u32[0]);
	// 0x2C92D0: ret
	return;
}

void sub_2C92E0(X86Context& ctx, uint8_t* base) {
	// 0x2C92E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C92E8: movss [0x0060E638], xmm0
	X86_MEM_WRITE_u32(base, 0x60E638u, ctx.xmm[0].u32[0]);
	// 0x2C92F0: ret
	return;
}

void sub_2C9300(X86Context& ctx, uint8_t* base) {
	// 0x2C9300: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9308: movss [0x0060E628], xmm0
	X86_MEM_WRITE_u32(base, 0x60E628u, ctx.xmm[0].u32[0]);
	// 0x2C9310: ret
	return;
}

void sub_2C9320(X86Context& ctx, uint8_t* base) {
	// 0x2C9320: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9328: movss [0x0060E610], xmm0
	X86_MEM_WRITE_u32(base, 0x60E610u, ctx.xmm[0].u32[0]);
	// 0x2C9330: ret
	return;
}

void sub_2C9340(X86Context& ctx, uint8_t* base) {
	// 0x2C9340: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C9348: movss [0x0060E630], xmm0
	X86_MEM_WRITE_u32(base, 0x60E630u, ctx.xmm[0].u32[0]);
	// 0x2C9350: ret
	return;
}

void sub_2C9360(X86Context& ctx, uint8_t* base) {
	// 0x2C9360: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C9368: movss [0x0060E618], xmm0
	X86_MEM_WRITE_u32(base, 0x60E618u, ctx.xmm[0].u32[0]);
	// 0x2C9370: ret
	return;
}

void sub_2C9380(X86Context& ctx, uint8_t* base) {
	// 0x2C9380: movss xmm0, dword ptr [0x0060E630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E630u);
	// 0x2C9388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C9390: movss [0x0060E640], xmm0
	X86_MEM_WRITE_u32(base, 0x60E640u, ctx.xmm[0].u32[0]);
	// 0x2C9398: ret
	return;
}

void sub_2C93A0(X86Context& ctx, uint8_t* base) {
	// 0x2C93A0: movss xmm0, dword ptr [0x0060E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E618u);
	// 0x2C93A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C93B0: movss [0x0060E63C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E63Cu, ctx.xmm[0].u32[0]);
	// 0x2C93B8: ret
	return;
}

void sub_2C93C0(X86Context& ctx, uint8_t* base) {
	// 0x2C93C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C93C8: movss [0x0060E650], xmm0
	X86_MEM_WRITE_u32(base, 0x60E650u, ctx.xmm[0].u32[0]);
	// 0x2C93D0: ret
	return;
}

void sub_2C93E0(X86Context& ctx, uint8_t* base) {
	// 0x2C93E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C93E8: movss [0x0060E644], xmm0
	X86_MEM_WRITE_u32(base, 0x60E644u, ctx.xmm[0].u32[0]);
	// 0x2C93F0: ret
	return;
}

void sub_2C9400(X86Context& ctx, uint8_t* base) {
	// 0x2C9400: movss xmm0, dword ptr [0x0060E644]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E644u);
	// 0x2C9408: movss [0x0060E64C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E64Cu, ctx.xmm[0].u32[0]);
	// 0x2C9410: ret
	return;
}

void sub_2C9420(X86Context& ctx, uint8_t* base) {
	// 0x2C9420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9428: movss [0x0060E614], xmm0
	X86_MEM_WRITE_u32(base, 0x60E614u, ctx.xmm[0].u32[0]);
	// 0x2C9430: ret
	return;
}

void sub_2C9440(X86Context& ctx, uint8_t* base) {
	// 0x2C9440: movss xmm0, dword ptr [0x0060E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E618u);
	// 0x2C9448: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9450: movss [0x0060E648], xmm0
	X86_MEM_WRITE_u32(base, 0x60E648u, ctx.xmm[0].u32[0]);
	// 0x2C9458: ret
	return;
}

void sub_2C9460(X86Context& ctx, uint8_t* base) {
	// 0x2C9460: movss xmm0, dword ptr [0x0060E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E618u);
	// 0x2C9468: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C9470: movss [0x0060E624], xmm0
	X86_MEM_WRITE_u32(base, 0x60E624u, ctx.xmm[0].u32[0]);
	// 0x2C9478: ret
	return;
}

void sub_2C9480(X86Context& ctx, uint8_t* base) {
	// 0x2C9480: movss xmm0, dword ptr [0x0060E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E618u);
	// 0x2C9488: subss xmm0, [0x0060E624]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E624u);
	// 0x2C9490: movss [0x0060E620], xmm0
	X86_MEM_WRITE_u32(base, 0x60E620u, ctx.xmm[0].u32[0]);
	// 0x2C9498: ret
	return;
}

void sub_2C94A0(X86Context& ctx, uint8_t* base) {
	// 0x2C94A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C94A8: movss [0x0060E634], xmm0
	X86_MEM_WRITE_u32(base, 0x60E634u, ctx.xmm[0].u32[0]);
	// 0x2C94B0: ret
	return;
}

void sub_2C94C0(X86Context& ctx, uint8_t* base) {
	// 0x2C94C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C94C8: movss [0x0060E61C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E61Cu, ctx.xmm[0].u32[0]);
	// 0x2C94D0: ret
	return;
}

void sub_2C94E0(X86Context& ctx, uint8_t* base) {
	// 0x2C94E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C94E8: movss [0x0060E6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6B0u, ctx.xmm[0].u32[0]);
	// 0x2C94F0: ret
	return;
}

void sub_2C9500(X86Context& ctx, uint8_t* base) {
	// 0x2C9500: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9508: movss [0x0060E6BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6BCu, ctx.xmm[0].u32[0]);
	// 0x2C9510: ret
	return;
}

void sub_2C9520(X86Context& ctx, uint8_t* base) {
	// 0x2C9520: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9528: movss [0x0060E67C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E67Cu, ctx.xmm[0].u32[0]);
	// 0x2C9530: ret
	return;
}

void sub_2C9540(X86Context& ctx, uint8_t* base) {
	// 0x2C9540: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9548: movss [0x0060E654], xmm0
	X86_MEM_WRITE_u32(base, 0x60E654u, ctx.xmm[0].u32[0]);
	// 0x2C9550: ret
	return;
}

void sub_2C9560(X86Context& ctx, uint8_t* base) {
	// 0x2C9560: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C9568: movss [0x0060E6B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6B4u, ctx.xmm[0].u32[0]);
	// 0x2C9570: ret
	return;
}

void sub_2C9580(X86Context& ctx, uint8_t* base) {
	// 0x2C9580: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C9588: movss [0x0060E664], xmm0
	X86_MEM_WRITE_u32(base, 0x60E664u, ctx.xmm[0].u32[0]);
	// 0x2C9590: ret
	return;
}

void sub_2C95A0(X86Context& ctx, uint8_t* base) {
	// 0x2C95A0: movss xmm0, dword ptr [0x0060E6B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E6B4u);
	// 0x2C95A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C95B0: movss [0x0060E6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6C8u, ctx.xmm[0].u32[0]);
	// 0x2C95B8: ret
	return;
}

void sub_2C95C0(X86Context& ctx, uint8_t* base) {
	// 0x2C95C0: movss xmm0, dword ptr [0x0060E664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E664u);
	// 0x2C95C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C95D0: movss [0x0060E6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6C0u, ctx.xmm[0].u32[0]);
	// 0x2C95D8: ret
	return;
}

void sub_2C95E0(X86Context& ctx, uint8_t* base) {
	// 0x2C95E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C95E8: movss [0x0060E6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6D8u, ctx.xmm[0].u32[0]);
	// 0x2C95F0: ret
	return;
}

void sub_2C9600(X86Context& ctx, uint8_t* base) {
	// 0x2C9600: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C9608: movss [0x0060E6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6CCu, ctx.xmm[0].u32[0]);
	// 0x2C9610: ret
	return;
}

