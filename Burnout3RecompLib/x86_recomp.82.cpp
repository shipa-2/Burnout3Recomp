#include "x86_recomp_shared.h"

void sub_2C9620(X86Context& ctx, uint8_t* base) {
	// 0x2C9620: movss xmm0, dword ptr [0x0060E6CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E6CCu);
	// 0x2C9628: movss [0x0060E6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6D4u, ctx.xmm[0].u32[0]);
	// 0x2C9630: ret
	return;
}

void sub_2C9640(X86Context& ctx, uint8_t* base) {
	// 0x2C9640: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9648: movss [0x0060E658], xmm0
	X86_MEM_WRITE_u32(base, 0x60E658u, ctx.xmm[0].u32[0]);
	// 0x2C9650: ret
	return;
}

void sub_2C9660(X86Context& ctx, uint8_t* base) {
	// 0x2C9660: movss xmm0, dword ptr [0x0060E664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E664u);
	// 0x2C9668: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9670: movss [0x0060E6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6D0u, ctx.xmm[0].u32[0]);
	// 0x2C9678: ret
	return;
}

void sub_2C9680(X86Context& ctx, uint8_t* base) {
	// 0x2C9680: movss xmm0, dword ptr [0x0060E664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E664u);
	// 0x2C9688: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C9690: movss [0x0060E674], xmm0
	X86_MEM_WRITE_u32(base, 0x60E674u, ctx.xmm[0].u32[0]);
	// 0x2C9698: ret
	return;
}

void sub_2C96A0(X86Context& ctx, uint8_t* base) {
	// 0x2C96A0: movss xmm0, dword ptr [0x0060E664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E664u);
	// 0x2C96A8: subss xmm0, [0x0060E674]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E674u);
	// 0x2C96B0: movss [0x0060E66C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E66Cu, ctx.xmm[0].u32[0]);
	// 0x2C96B8: ret
	return;
}

void sub_2C96C0(X86Context& ctx, uint8_t* base) {
	// 0x2C96C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C96C8: movss [0x0060E6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6B8u, ctx.xmm[0].u32[0]);
	// 0x2C96D0: ret
	return;
}

void sub_2C96E0(X86Context& ctx, uint8_t* base) {
	// 0x2C96E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C96E8: movss [0x0060E668], xmm0
	X86_MEM_WRITE_u32(base, 0x60E668u, ctx.xmm[0].u32[0]);
	// 0x2C96F0: ret
	return;
}

void sub_2C9700(X86Context& ctx, uint8_t* base) {
	// 0x2C9700: movss xmm0, dword ptr [0x003B234C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B234Cu);
	// 0x2C9708: movss [0x0060E670], xmm0
	X86_MEM_WRITE_u32(base, 0x60E670u, ctx.xmm[0].u32[0]);
	// 0x2C9710: ret
	return;
}

void sub_2C9720(X86Context& ctx, uint8_t* base) {
	// 0x2C9720: movss xmm0, dword ptr [0x0039A858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39A858u);
	// 0x2C9728: movss [0x0060E6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6C4u, ctx.xmm[0].u32[0]);
	// 0x2C9730: ret
	return;
}

void sub_2C9740(X86Context& ctx, uint8_t* base) {
	// 0x2C9740: movss xmm0, dword ptr [0x003B1B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1B20u);
	// 0x2C9748: movss [0x0060E678], xmm0
	X86_MEM_WRITE_u32(base, 0x60E678u, ctx.xmm[0].u32[0]);
	// 0x2C9750: ret
	return;
}

void sub_2C9760(X86Context& ctx, uint8_t* base) {
	// 0x2C9760: movss xmm0, dword ptr [0x003B2350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2350u);
	// 0x2C9768: movss [0x0060E65C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E65Cu, ctx.xmm[0].u32[0]);
	// 0x2C9770: ret
	return;
}

void sub_2C9780(X86Context& ctx, uint8_t* base) {
	// 0x2C9780: movss xmm0, dword ptr [0x00395D58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395D58u);
	// 0x2C9788: movss [0x0060E660], xmm0
	X86_MEM_WRITE_u32(base, 0x60E660u, ctx.xmm[0].u32[0]);
	// 0x2C9790: ret
	return;
}

void sub_2C97A0(X86Context& ctx, uint8_t* base) {
	// 0x2C97A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C97A8: movss [0x0060E6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6E0u, ctx.xmm[0].u32[0]);
	// 0x2C97B0: ret
	return;
}

void sub_2C97C0(X86Context& ctx, uint8_t* base) {
	// 0x2C97C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C97C8: movss [0x0060E6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6E4u, ctx.xmm[0].u32[0]);
	// 0x2C97D0: ret
	return;
}

void sub_2C97E0(X86Context& ctx, uint8_t* base) {
	// 0x2C97E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C97E8: movss [0x0060E6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6DCu, ctx.xmm[0].u32[0]);
	// 0x2C97F0: ret
	return;
}

void sub_2C9800(X86Context& ctx, uint8_t* base) {
	// 0x2C9800: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C9808: movss [0x0060E704], xmm0
	X86_MEM_WRITE_u32(base, 0x60E704u, ctx.xmm[0].u32[0]);
	// 0x2C9810: ret
	return;
}

void sub_2C9820(X86Context& ctx, uint8_t* base) {
	// 0x2C9820: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9828: movss [0x0060E710], xmm0
	X86_MEM_WRITE_u32(base, 0x60E710u, ctx.xmm[0].u32[0]);
	// 0x2C9830: ret
	return;
}

void sub_2C9840(X86Context& ctx, uint8_t* base) {
	// 0x2C9840: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9848: movss [0x0060E700], xmm0
	X86_MEM_WRITE_u32(base, 0x60E700u, ctx.xmm[0].u32[0]);
	// 0x2C9850: ret
	return;
}

void sub_2C9860(X86Context& ctx, uint8_t* base) {
	// 0x2C9860: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9868: movss [0x0060E6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6E8u, ctx.xmm[0].u32[0]);
	// 0x2C9870: ret
	return;
}

void sub_2C9880(X86Context& ctx, uint8_t* base) {
	// 0x2C9880: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C9888: movss [0x0060E708], xmm0
	X86_MEM_WRITE_u32(base, 0x60E708u, ctx.xmm[0].u32[0]);
	// 0x2C9890: ret
	return;
}

void sub_2C98A0(X86Context& ctx, uint8_t* base) {
	// 0x2C98A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C98A8: movss [0x0060E6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6F0u, ctx.xmm[0].u32[0]);
	// 0x2C98B0: ret
	return;
}

void sub_2C98C0(X86Context& ctx, uint8_t* base) {
	// 0x2C98C0: movss xmm0, dword ptr [0x0060E708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E708u);
	// 0x2C98C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C98D0: movss [0x0060E718], xmm0
	X86_MEM_WRITE_u32(base, 0x60E718u, ctx.xmm[0].u32[0]);
	// 0x2C98D8: ret
	return;
}

void sub_2C98E0(X86Context& ctx, uint8_t* base) {
	// 0x2C98E0: movss xmm0, dword ptr [0x0060E6F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E6F0u);
	// 0x2C98E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C98F0: movss [0x0060E714], xmm0
	X86_MEM_WRITE_u32(base, 0x60E714u, ctx.xmm[0].u32[0]);
	// 0x2C98F8: ret
	return;
}

void sub_2C9900(X86Context& ctx, uint8_t* base) {
	// 0x2C9900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9908: movss [0x0060E728], xmm0
	X86_MEM_WRITE_u32(base, 0x60E728u, ctx.xmm[0].u32[0]);
	// 0x2C9910: ret
	return;
}

void sub_2C9920(X86Context& ctx, uint8_t* base) {
	// 0x2C9920: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C9928: movss [0x0060E71C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E71Cu, ctx.xmm[0].u32[0]);
	// 0x2C9930: ret
	return;
}

void sub_2C9940(X86Context& ctx, uint8_t* base) {
	// 0x2C9940: movss xmm0, dword ptr [0x0060E71C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E71Cu);
	// 0x2C9948: movss [0x0060E724], xmm0
	X86_MEM_WRITE_u32(base, 0x60E724u, ctx.xmm[0].u32[0]);
	// 0x2C9950: ret
	return;
}

void sub_2C9960(X86Context& ctx, uint8_t* base) {
	// 0x2C9960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9968: movss [0x0060E6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6ECu, ctx.xmm[0].u32[0]);
	// 0x2C9970: ret
	return;
}

void sub_2C9980(X86Context& ctx, uint8_t* base) {
	// 0x2C9980: movss xmm0, dword ptr [0x0060E6F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E6F0u);
	// 0x2C9988: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9990: movss [0x0060E720], xmm0
	X86_MEM_WRITE_u32(base, 0x60E720u, ctx.xmm[0].u32[0]);
	// 0x2C9998: ret
	return;
}

void sub_2C99A0(X86Context& ctx, uint8_t* base) {
	// 0x2C99A0: movss xmm0, dword ptr [0x0060E6F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E6F0u);
	// 0x2C99A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C99B0: movss [0x0060E6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6FCu, ctx.xmm[0].u32[0]);
	// 0x2C99B8: ret
	return;
}

void sub_2C99C0(X86Context& ctx, uint8_t* base) {
	// 0x2C99C0: movss xmm0, dword ptr [0x0060E6F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E6F0u);
	// 0x2C99C8: subss xmm0, [0x0060E6FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E6FCu);
	// 0x2C99D0: movss [0x0060E6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6F8u, ctx.xmm[0].u32[0]);
	// 0x2C99D8: ret
	return;
}

void sub_2C99E0(X86Context& ctx, uint8_t* base) {
	// 0x2C99E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C99E8: movss [0x0060E70C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E70Cu, ctx.xmm[0].u32[0]);
	// 0x2C99F0: ret
	return;
}

void sub_2C9A00(X86Context& ctx, uint8_t* base) {
	// 0x2C9A00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C9A08: movss [0x0060E6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E6F4u, ctx.xmm[0].u32[0]);
	// 0x2C9A10: ret
	return;
}

void sub_2C9A20(X86Context& ctx, uint8_t* base) {
	// 0x2C9A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C9A28: movss [0x0060E730], xmm0
	X86_MEM_WRITE_u32(base, 0x60E730u, ctx.xmm[0].u32[0]);
	// 0x2C9A30: ret
	return;
}

void sub_2C9A40(X86Context& ctx, uint8_t* base) {
	// 0x2C9A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9A48: movss [0x0060E734], xmm0
	X86_MEM_WRITE_u32(base, 0x60E734u, ctx.xmm[0].u32[0]);
	// 0x2C9A50: ret
	return;
}

void sub_2C9A60(X86Context& ctx, uint8_t* base) {
	// 0x2C9A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9A68: movss [0x0060E72C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E72Cu, ctx.xmm[0].u32[0]);
	// 0x2C9A70: ret
	return;
}

void sub_2C9A80(X86Context& ctx, uint8_t* base) {
	// 0x2C9A80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C9A88: movss [0x0060E754], xmm0
	X86_MEM_WRITE_u32(base, 0x60E754u, ctx.xmm[0].u32[0]);
	// 0x2C9A90: ret
	return;
}

void sub_2C9AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C9AA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9AA8: movss [0x0060E760], xmm0
	X86_MEM_WRITE_u32(base, 0x60E760u, ctx.xmm[0].u32[0]);
	// 0x2C9AB0: ret
	return;
}

void sub_2C9AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C9AC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9AC8: movss [0x0060E750], xmm0
	X86_MEM_WRITE_u32(base, 0x60E750u, ctx.xmm[0].u32[0]);
	// 0x2C9AD0: ret
	return;
}

void sub_2C9AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C9AE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9AE8: movss [0x0060E738], xmm0
	X86_MEM_WRITE_u32(base, 0x60E738u, ctx.xmm[0].u32[0]);
	// 0x2C9AF0: ret
	return;
}

void sub_2C9B00(X86Context& ctx, uint8_t* base) {
	// 0x2C9B00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C9B08: movss [0x0060E758], xmm0
	X86_MEM_WRITE_u32(base, 0x60E758u, ctx.xmm[0].u32[0]);
	// 0x2C9B10: ret
	return;
}

void sub_2C9B20(X86Context& ctx, uint8_t* base) {
	// 0x2C9B20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C9B28: movss [0x0060E740], xmm0
	X86_MEM_WRITE_u32(base, 0x60E740u, ctx.xmm[0].u32[0]);
	// 0x2C9B30: ret
	return;
}

void sub_2C9B40(X86Context& ctx, uint8_t* base) {
	// 0x2C9B40: movss xmm0, dword ptr [0x0060E758]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E758u);
	// 0x2C9B48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C9B50: movss [0x0060E768], xmm0
	X86_MEM_WRITE_u32(base, 0x60E768u, ctx.xmm[0].u32[0]);
	// 0x2C9B58: ret
	return;
}

void sub_2C9B60(X86Context& ctx, uint8_t* base) {
	// 0x2C9B60: movss xmm0, dword ptr [0x0060E740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E740u);
	// 0x2C9B68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C9B70: movss [0x0060E764], xmm0
	X86_MEM_WRITE_u32(base, 0x60E764u, ctx.xmm[0].u32[0]);
	// 0x2C9B78: ret
	return;
}

void sub_2C9B80(X86Context& ctx, uint8_t* base) {
	// 0x2C9B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9B88: movss [0x0060E778], xmm0
	X86_MEM_WRITE_u32(base, 0x60E778u, ctx.xmm[0].u32[0]);
	// 0x2C9B90: ret
	return;
}

void sub_2C9BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C9BA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C9BA8: movss [0x0060E76C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E76Cu, ctx.xmm[0].u32[0]);
	// 0x2C9BB0: ret
	return;
}

void sub_2C9BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C9BC0: movss xmm0, dword ptr [0x0060E76C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E76Cu);
	// 0x2C9BC8: movss [0x0060E774], xmm0
	X86_MEM_WRITE_u32(base, 0x60E774u, ctx.xmm[0].u32[0]);
	// 0x2C9BD0: ret
	return;
}

void sub_2C9BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C9BE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9BE8: movss [0x0060E73C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E73Cu, ctx.xmm[0].u32[0]);
	// 0x2C9BF0: ret
	return;
}

void sub_2C9C00(X86Context& ctx, uint8_t* base) {
	// 0x2C9C00: movss xmm0, dword ptr [0x0060E740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E740u);
	// 0x2C9C08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9C10: movss [0x0060E770], xmm0
	X86_MEM_WRITE_u32(base, 0x60E770u, ctx.xmm[0].u32[0]);
	// 0x2C9C18: ret
	return;
}

void sub_2C9C20(X86Context& ctx, uint8_t* base) {
	// 0x2C9C20: movss xmm0, dword ptr [0x0060E740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E740u);
	// 0x2C9C28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C9C30: movss [0x0060E74C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E74Cu, ctx.xmm[0].u32[0]);
	// 0x2C9C38: ret
	return;
}

void sub_2C9C40(X86Context& ctx, uint8_t* base) {
	// 0x2C9C40: movss xmm0, dword ptr [0x0060E740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E740u);
	// 0x2C9C48: subss xmm0, [0x0060E74C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E74Cu);
	// 0x2C9C50: movss [0x0060E748], xmm0
	X86_MEM_WRITE_u32(base, 0x60E748u, ctx.xmm[0].u32[0]);
	// 0x2C9C58: ret
	return;
}

void sub_2C9C60(X86Context& ctx, uint8_t* base) {
	// 0x2C9C60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C9C68: movss [0x0060E75C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E75Cu, ctx.xmm[0].u32[0]);
	// 0x2C9C70: ret
	return;
}

void sub_2C9C80(X86Context& ctx, uint8_t* base) {
	// 0x2C9C80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C9C88: movss [0x0060E744], xmm0
	X86_MEM_WRITE_u32(base, 0x60E744u, ctx.xmm[0].u32[0]);
	// 0x2C9C90: ret
	return;
}

void sub_2C9CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C9CA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C9CA8: movss [0x0060E780], xmm0
	X86_MEM_WRITE_u32(base, 0x60E780u, ctx.xmm[0].u32[0]);
	// 0x2C9CB0: ret
	return;
}

void sub_2C9CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C9CC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9CC8: movss [0x0060E784], xmm0
	X86_MEM_WRITE_u32(base, 0x60E784u, ctx.xmm[0].u32[0]);
	// 0x2C9CD0: ret
	return;
}

void sub_2C9CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C9CE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9CE8: movss [0x0060E77C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E77Cu, ctx.xmm[0].u32[0]);
	// 0x2C9CF0: ret
	return;
}

void sub_2C9D00(X86Context& ctx, uint8_t* base) {
	// 0x2C9D00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C9D08: movss [0x0060E7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7A4u, ctx.xmm[0].u32[0]);
	// 0x2C9D10: ret
	return;
}

void sub_2C9D20(X86Context& ctx, uint8_t* base) {
	// 0x2C9D20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9D28: movss [0x0060E7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7B0u, ctx.xmm[0].u32[0]);
	// 0x2C9D30: ret
	return;
}

void sub_2C9D40(X86Context& ctx, uint8_t* base) {
	// 0x2C9D40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9D48: movss [0x0060E7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7A0u, ctx.xmm[0].u32[0]);
	// 0x2C9D50: ret
	return;
}

void sub_2C9D60(X86Context& ctx, uint8_t* base) {
	// 0x2C9D60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9D68: movss [0x0060E788], xmm0
	X86_MEM_WRITE_u32(base, 0x60E788u, ctx.xmm[0].u32[0]);
	// 0x2C9D70: ret
	return;
}

void sub_2C9D80(X86Context& ctx, uint8_t* base) {
	// 0x2C9D80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C9D88: movss [0x0060E7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7A8u, ctx.xmm[0].u32[0]);
	// 0x2C9D90: ret
	return;
}

void sub_2C9DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C9DA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C9DA8: movss [0x0060E790], xmm0
	X86_MEM_WRITE_u32(base, 0x60E790u, ctx.xmm[0].u32[0]);
	// 0x2C9DB0: ret
	return;
}

void sub_2C9DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C9DC0: movss xmm0, dword ptr [0x0060E7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E7A8u);
	// 0x2C9DC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C9DD0: movss [0x0060E7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7B8u, ctx.xmm[0].u32[0]);
	// 0x2C9DD8: ret
	return;
}

void sub_2C9DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C9DE0: movss xmm0, dword ptr [0x0060E790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E790u);
	// 0x2C9DE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C9DF0: movss [0x0060E7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7B4u, ctx.xmm[0].u32[0]);
	// 0x2C9DF8: ret
	return;
}

void sub_2C9E00(X86Context& ctx, uint8_t* base) {
	// 0x2C9E00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9E08: movss [0x0060E7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7C8u, ctx.xmm[0].u32[0]);
	// 0x2C9E10: ret
	return;
}

void sub_2C9E20(X86Context& ctx, uint8_t* base) {
	// 0x2C9E20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C9E28: movss [0x0060E7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7BCu, ctx.xmm[0].u32[0]);
	// 0x2C9E30: ret
	return;
}

void sub_2C9E40(X86Context& ctx, uint8_t* base) {
	// 0x2C9E40: movss xmm0, dword ptr [0x0060E7BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E7BCu);
	// 0x2C9E48: movss [0x0060E7C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7C4u, ctx.xmm[0].u32[0]);
	// 0x2C9E50: ret
	return;
}

void sub_2C9E60(X86Context& ctx, uint8_t* base) {
	// 0x2C9E60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C9E68: movss [0x0060E78C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E78Cu, ctx.xmm[0].u32[0]);
	// 0x2C9E70: ret
	return;
}

void sub_2C9E80(X86Context& ctx, uint8_t* base) {
	// 0x2C9E80: movss xmm0, dword ptr [0x0060E790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E790u);
	// 0x2C9E88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C9E90: movss [0x0060E7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7C0u, ctx.xmm[0].u32[0]);
	// 0x2C9E98: ret
	return;
}

void sub_2C9EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C9EA0: movss xmm0, dword ptr [0x0060E790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E790u);
	// 0x2C9EA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C9EB0: movss [0x0060E79C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E79Cu, ctx.xmm[0].u32[0]);
	// 0x2C9EB8: ret
	return;
}

void sub_2C9EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C9EC0: movss xmm0, dword ptr [0x0060E790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E790u);
	// 0x2C9EC8: subss xmm0, [0x0060E79C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E79Cu);
	// 0x2C9ED0: movss [0x0060E798], xmm0
	X86_MEM_WRITE_u32(base, 0x60E798u, ctx.xmm[0].u32[0]);
	// 0x2C9ED8: ret
	return;
}

void sub_2C9EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C9EE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C9EE8: movss [0x0060E7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7ACu, ctx.xmm[0].u32[0]);
	// 0x2C9EF0: ret
	return;
}

void sub_2C9F00(X86Context& ctx, uint8_t* base) {
	// 0x2C9F00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C9F08: movss [0x0060E794], xmm0
	X86_MEM_WRITE_u32(base, 0x60E794u, ctx.xmm[0].u32[0]);
	// 0x2C9F10: ret
	return;
}

void sub_2C9F20(X86Context& ctx, uint8_t* base) {
	// 0x2C9F20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C9F28: movss [0x0060E7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7CCu, ctx.xmm[0].u32[0]);
	// 0x2C9F30: ret
	return;
}

void sub_2C9F40(X86Context& ctx, uint8_t* base) {
	// 0x2C9F40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C9F48: movss [0x0060E7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7DCu, ctx.xmm[0].u32[0]);
	// 0x2C9F50: ret
	return;
}

void sub_2C9F60(X86Context& ctx, uint8_t* base) {
	// 0x2C9F60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C9F68: movss [0x0060E7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7E4u, ctx.xmm[0].u32[0]);
	// 0x2C9F70: ret
	return;
}

void sub_2C9F80(X86Context& ctx, uint8_t* base) {
	// 0x2C9F80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C9F88: movss [0x0060E7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7D8u, ctx.xmm[0].u32[0]);
	// 0x2C9F90: ret
	return;
}

void sub_2C9FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C9FA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C9FA8: movss [0x0060E7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7D0u, ctx.xmm[0].u32[0]);
	// 0x2C9FB0: ret
	return;
}

void sub_2C9FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C9FC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C9FC8: movss [0x0060E7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7E0u, ctx.xmm[0].u32[0]);
	// 0x2C9FD0: ret
	return;
}

void sub_2C9FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C9FE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C9FE8: movss [0x0060E7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7D4u, ctx.xmm[0].u32[0]);
	// 0x2C9FF0: ret
	return;
}

void sub_2CA000(X86Context& ctx, uint8_t* base) {
	// 0x2CA000: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA008: movss [0x0060E804], xmm0
	X86_MEM_WRITE_u32(base, 0x60E804u, ctx.xmm[0].u32[0]);
	// 0x2CA010: ret
	return;
}

void sub_2CA020(X86Context& ctx, uint8_t* base) {
	// 0x2CA020: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA028: movss [0x0060E810], xmm0
	X86_MEM_WRITE_u32(base, 0x60E810u, ctx.xmm[0].u32[0]);
	// 0x2CA030: ret
	return;
}

void sub_2CA040(X86Context& ctx, uint8_t* base) {
	// 0x2CA040: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA048: movss [0x0060E800], xmm0
	X86_MEM_WRITE_u32(base, 0x60E800u, ctx.xmm[0].u32[0]);
	// 0x2CA050: ret
	return;
}

void sub_2CA060(X86Context& ctx, uint8_t* base) {
	// 0x2CA060: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA068: movss [0x0060E7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7E8u, ctx.xmm[0].u32[0]);
	// 0x2CA070: ret
	return;
}

void sub_2CA080(X86Context& ctx, uint8_t* base) {
	// 0x2CA080: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CA088: movss [0x0060E808], xmm0
	X86_MEM_WRITE_u32(base, 0x60E808u, ctx.xmm[0].u32[0]);
	// 0x2CA090: ret
	return;
}

void sub_2CA0A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA0A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CA0A8: movss [0x0060E7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7F0u, ctx.xmm[0].u32[0]);
	// 0x2CA0B0: ret
	return;
}

void sub_2CA0C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA0C0: movss xmm0, dword ptr [0x0060E808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E808u);
	// 0x2CA0C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CA0D0: movss [0x0060E818], xmm0
	X86_MEM_WRITE_u32(base, 0x60E818u, ctx.xmm[0].u32[0]);
	// 0x2CA0D8: ret
	return;
}

void sub_2CA0E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA0E0: movss xmm0, dword ptr [0x0060E7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E7F0u);
	// 0x2CA0E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CA0F0: movss [0x0060E814], xmm0
	X86_MEM_WRITE_u32(base, 0x60E814u, ctx.xmm[0].u32[0]);
	// 0x2CA0F8: ret
	return;
}

void sub_2CA100(X86Context& ctx, uint8_t* base) {
	// 0x2CA100: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CA108: movss [0x0060E828], xmm0
	X86_MEM_WRITE_u32(base, 0x60E828u, ctx.xmm[0].u32[0]);
	// 0x2CA110: ret
	return;
}

void sub_2CA120(X86Context& ctx, uint8_t* base) {
	// 0x2CA120: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CA128: movss [0x0060E81C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E81Cu, ctx.xmm[0].u32[0]);
	// 0x2CA130: ret
	return;
}

void sub_2CA140(X86Context& ctx, uint8_t* base) {
	// 0x2CA140: movss xmm0, dword ptr [0x0060E81C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E81Cu);
	// 0x2CA148: movss [0x0060E824], xmm0
	X86_MEM_WRITE_u32(base, 0x60E824u, ctx.xmm[0].u32[0]);
	// 0x2CA150: ret
	return;
}

void sub_2CA160(X86Context& ctx, uint8_t* base) {
	// 0x2CA160: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CA168: movss [0x0060E7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7ECu, ctx.xmm[0].u32[0]);
	// 0x2CA170: ret
	return;
}

void sub_2CA180(X86Context& ctx, uint8_t* base) {
	// 0x2CA180: movss xmm0, dword ptr [0x0060E7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E7F0u);
	// 0x2CA188: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CA190: movss [0x0060E820], xmm0
	X86_MEM_WRITE_u32(base, 0x60E820u, ctx.xmm[0].u32[0]);
	// 0x2CA198: ret
	return;
}

void sub_2CA1A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA1A0: movss xmm0, dword ptr [0x0060E7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E7F0u);
	// 0x2CA1A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CA1B0: movss [0x0060E7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7FCu, ctx.xmm[0].u32[0]);
	// 0x2CA1B8: ret
	return;
}

void sub_2CA1C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA1C0: movss xmm0, dword ptr [0x0060E7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E7F0u);
	// 0x2CA1C8: subss xmm0, [0x0060E7FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E7FCu);
	// 0x2CA1D0: movss [0x0060E7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7F8u, ctx.xmm[0].u32[0]);
	// 0x2CA1D8: ret
	return;
}

void sub_2CA1E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA1E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA1E8: movss [0x0060E80C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E80Cu, ctx.xmm[0].u32[0]);
	// 0x2CA1F0: ret
	return;
}

void sub_2CA200(X86Context& ctx, uint8_t* base) {
	// 0x2CA200: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA208: movss [0x0060E7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E7F4u, ctx.xmm[0].u32[0]);
	// 0x2CA210: ret
	return;
}

void sub_2CA220(X86Context& ctx, uint8_t* base) {
	// 0x2CA220: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA228: movss [0x0060E82C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E82Cu, ctx.xmm[0].u32[0]);
	// 0x2CA230: ret
	return;
}

void sub_2CA240(X86Context& ctx, uint8_t* base) {
	// 0x2CA240: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA248: movss [0x0060E84C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E84Cu, ctx.xmm[0].u32[0]);
	// 0x2CA250: ret
	return;
}

void sub_2CA260(X86Context& ctx, uint8_t* base) {
	// 0x2CA260: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA268: movss [0x0060E858], xmm0
	X86_MEM_WRITE_u32(base, 0x60E858u, ctx.xmm[0].u32[0]);
	// 0x2CA270: ret
	return;
}

void sub_2CA280(X86Context& ctx, uint8_t* base) {
	// 0x2CA280: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA288: movss [0x0060E848], xmm0
	X86_MEM_WRITE_u32(base, 0x60E848u, ctx.xmm[0].u32[0]);
	// 0x2CA290: ret
	return;
}

void sub_2CA2A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA2A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA2A8: movss [0x0060E830], xmm0
	X86_MEM_WRITE_u32(base, 0x60E830u, ctx.xmm[0].u32[0]);
	// 0x2CA2B0: ret
	return;
}

void sub_2CA2C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA2C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CA2C8: movss [0x0060E850], xmm0
	X86_MEM_WRITE_u32(base, 0x60E850u, ctx.xmm[0].u32[0]);
	// 0x2CA2D0: ret
	return;
}

void sub_2CA2E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA2E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CA2E8: movss [0x0060E838], xmm0
	X86_MEM_WRITE_u32(base, 0x60E838u, ctx.xmm[0].u32[0]);
	// 0x2CA2F0: ret
	return;
}

void sub_2CA300(X86Context& ctx, uint8_t* base) {
	// 0x2CA300: movss xmm0, dword ptr [0x0060E850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E850u);
	// 0x2CA308: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CA310: movss [0x0060E860], xmm0
	X86_MEM_WRITE_u32(base, 0x60E860u, ctx.xmm[0].u32[0]);
	// 0x2CA318: ret
	return;
}

void sub_2CA320(X86Context& ctx, uint8_t* base) {
	// 0x2CA320: movss xmm0, dword ptr [0x0060E838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E838u);
	// 0x2CA328: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CA330: movss [0x0060E85C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E85Cu, ctx.xmm[0].u32[0]);
	// 0x2CA338: ret
	return;
}

void sub_2CA340(X86Context& ctx, uint8_t* base) {
	// 0x2CA340: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CA348: movss [0x0060E870], xmm0
	X86_MEM_WRITE_u32(base, 0x60E870u, ctx.xmm[0].u32[0]);
	// 0x2CA350: ret
	return;
}

void sub_2CA360(X86Context& ctx, uint8_t* base) {
	// 0x2CA360: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CA368: movss [0x0060E864], xmm0
	X86_MEM_WRITE_u32(base, 0x60E864u, ctx.xmm[0].u32[0]);
	// 0x2CA370: ret
	return;
}

void sub_2CA380(X86Context& ctx, uint8_t* base) {
	// 0x2CA380: movss xmm0, dword ptr [0x0060E864]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E864u);
	// 0x2CA388: movss [0x0060E86C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E86Cu, ctx.xmm[0].u32[0]);
	// 0x2CA390: ret
	return;
}

void sub_2CA3A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA3A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CA3A8: movss [0x0060E834], xmm0
	X86_MEM_WRITE_u32(base, 0x60E834u, ctx.xmm[0].u32[0]);
	// 0x2CA3B0: ret
	return;
}

void sub_2CA3C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA3C0: movss xmm0, dword ptr [0x0060E838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E838u);
	// 0x2CA3C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CA3D0: movss [0x0060E868], xmm0
	X86_MEM_WRITE_u32(base, 0x60E868u, ctx.xmm[0].u32[0]);
	// 0x2CA3D8: ret
	return;
}

void sub_2CA3E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA3E0: movss xmm0, dword ptr [0x0060E838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E838u);
	// 0x2CA3E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CA3F0: movss [0x0060E844], xmm0
	X86_MEM_WRITE_u32(base, 0x60E844u, ctx.xmm[0].u32[0]);
	// 0x2CA3F8: ret
	return;
}

void sub_2CA400(X86Context& ctx, uint8_t* base) {
	// 0x2CA400: movss xmm0, dword ptr [0x0060E838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E838u);
	// 0x2CA408: subss xmm0, [0x0060E844]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E844u);
	// 0x2CA410: movss [0x0060E840], xmm0
	X86_MEM_WRITE_u32(base, 0x60E840u, ctx.xmm[0].u32[0]);
	// 0x2CA418: ret
	return;
}

void sub_2CA420(X86Context& ctx, uint8_t* base) {
	// 0x2CA420: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA428: movss [0x0060E854], xmm0
	X86_MEM_WRITE_u32(base, 0x60E854u, ctx.xmm[0].u32[0]);
	// 0x2CA430: ret
	return;
}

void sub_2CA440(X86Context& ctx, uint8_t* base) {
	// 0x2CA440: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA448: movss [0x0060E83C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E83Cu, ctx.xmm[0].u32[0]);
	// 0x2CA450: ret
	return;
}

void sub_2CA460(X86Context& ctx, uint8_t* base) {
	// 0x2CA460: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA468: movss [0x0060E880], xmm0
	X86_MEM_WRITE_u32(base, 0x60E880u, ctx.xmm[0].u32[0]);
	// 0x2CA470: ret
	return;
}

void sub_2CA480(X86Context& ctx, uint8_t* base) {
	// 0x2CA480: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA488: movss [0x0060E888], xmm0
	X86_MEM_WRITE_u32(base, 0x60E888u, ctx.xmm[0].u32[0]);
	// 0x2CA490: ret
	return;
}

void sub_2CA4A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA4A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA4A8: movss [0x0060E87C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E87Cu, ctx.xmm[0].u32[0]);
	// 0x2CA4B0: ret
	return;
}

void sub_2CA4C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA4C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA4C8: movss [0x0060E874], xmm0
	X86_MEM_WRITE_u32(base, 0x60E874u, ctx.xmm[0].u32[0]);
	// 0x2CA4D0: ret
	return;
}

void sub_2CA4E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA4E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA4E8: movss [0x0060E884], xmm0
	X86_MEM_WRITE_u32(base, 0x60E884u, ctx.xmm[0].u32[0]);
	// 0x2CA4F0: ret
	return;
}

void sub_2CA500(X86Context& ctx, uint8_t* base) {
	// 0x2CA500: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA508: movss [0x0060E878], xmm0
	X86_MEM_WRITE_u32(base, 0x60E878u, ctx.xmm[0].u32[0]);
	// 0x2CA510: ret
	return;
}

void sub_2CA520(X86Context& ctx, uint8_t* base) {
	// 0x2CA520: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA528: movss [0x0060E898], xmm0
	X86_MEM_WRITE_u32(base, 0x60E898u, ctx.xmm[0].u32[0]);
	// 0x2CA530: ret
	return;
}

void sub_2CA540(X86Context& ctx, uint8_t* base) {
	// 0x2CA540: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA548: movss [0x0060E8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8A0u, ctx.xmm[0].u32[0]);
	// 0x2CA550: ret
	return;
}

void sub_2CA560(X86Context& ctx, uint8_t* base) {
	// 0x2CA560: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA568: movss [0x0060E894], xmm0
	X86_MEM_WRITE_u32(base, 0x60E894u, ctx.xmm[0].u32[0]);
	// 0x2CA570: ret
	return;
}

void sub_2CA580(X86Context& ctx, uint8_t* base) {
	// 0x2CA580: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA588: movss [0x0060E88C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E88Cu, ctx.xmm[0].u32[0]);
	// 0x2CA590: ret
	return;
}

void sub_2CA5A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA5A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA5A8: movss [0x0060E89C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E89Cu, ctx.xmm[0].u32[0]);
	// 0x2CA5B0: ret
	return;
}

void sub_2CA5C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA5C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA5C8: movss [0x0060E890], xmm0
	X86_MEM_WRITE_u32(base, 0x60E890u, ctx.xmm[0].u32[0]);
	// 0x2CA5D0: ret
	return;
}

void sub_2CA5E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA5E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA5E8: movss [0x0060E8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8B0u, ctx.xmm[0].u32[0]);
	// 0x2CA5F0: ret
	return;
}

void sub_2CA600(X86Context& ctx, uint8_t* base) {
	// 0x2CA600: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA608: movss [0x0060E8B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8B8u, ctx.xmm[0].u32[0]);
	// 0x2CA610: ret
	return;
}

void sub_2CA620(X86Context& ctx, uint8_t* base) {
	// 0x2CA620: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA628: movss [0x0060E8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8ACu, ctx.xmm[0].u32[0]);
	// 0x2CA630: ret
	return;
}

void sub_2CA640(X86Context& ctx, uint8_t* base) {
	// 0x2CA640: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA648: movss [0x0060E8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8A4u, ctx.xmm[0].u32[0]);
	// 0x2CA650: ret
	return;
}

void sub_2CA660(X86Context& ctx, uint8_t* base) {
	// 0x2CA660: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA668: movss [0x0060E8B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8B4u, ctx.xmm[0].u32[0]);
	// 0x2CA670: ret
	return;
}

void sub_2CA680(X86Context& ctx, uint8_t* base) {
	// 0x2CA680: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA688: movss [0x0060E8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8A8u, ctx.xmm[0].u32[0]);
	// 0x2CA690: ret
	return;
}

void sub_2CA6A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA6A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA6A8: movss [0x0060E8C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8C8u, ctx.xmm[0].u32[0]);
	// 0x2CA6B0: ret
	return;
}

void sub_2CA6C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA6C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA6C8: movss [0x0060E8D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8D0u, ctx.xmm[0].u32[0]);
	// 0x2CA6D0: ret
	return;
}

void sub_2CA6E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA6E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA6E8: movss [0x0060E8C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8C4u, ctx.xmm[0].u32[0]);
	// 0x2CA6F0: ret
	return;
}

void sub_2CA700(X86Context& ctx, uint8_t* base) {
	// 0x2CA700: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA708: movss [0x0060E8BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8BCu, ctx.xmm[0].u32[0]);
	// 0x2CA710: ret
	return;
}

void sub_2CA720(X86Context& ctx, uint8_t* base) {
	// 0x2CA720: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA728: movss [0x0060E8CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8CCu, ctx.xmm[0].u32[0]);
	// 0x2CA730: ret
	return;
}

void sub_2CA740(X86Context& ctx, uint8_t* base) {
	// 0x2CA740: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA748: movss [0x0060E8C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8C0u, ctx.xmm[0].u32[0]);
	// 0x2CA750: ret
	return;
}

void sub_2CA760(X86Context& ctx, uint8_t* base) {
	// 0x2CA760: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA768: movss [0x0060E8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8E0u, ctx.xmm[0].u32[0]);
	// 0x2CA770: ret
	return;
}

void sub_2CA780(X86Context& ctx, uint8_t* base) {
	// 0x2CA780: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA788: movss [0x0060E8E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8E8u, ctx.xmm[0].u32[0]);
	// 0x2CA790: ret
	return;
}

void sub_2CA7A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA7A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA7A8: movss [0x0060E8DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8DCu, ctx.xmm[0].u32[0]);
	// 0x2CA7B0: ret
	return;
}

void sub_2CA7C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA7C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA7C8: movss [0x0060E8D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8D4u, ctx.xmm[0].u32[0]);
	// 0x2CA7D0: ret
	return;
}

void sub_2CA7E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA7E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA7E8: movss [0x0060E8E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8E4u, ctx.xmm[0].u32[0]);
	// 0x2CA7F0: ret
	return;
}

void sub_2CA800(X86Context& ctx, uint8_t* base) {
	// 0x2CA800: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA808: movss [0x0060E8D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8D8u, ctx.xmm[0].u32[0]);
	// 0x2CA810: ret
	return;
}

void sub_2CA820(X86Context& ctx, uint8_t* base) {
	// 0x2CA820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CA828: movss [0x0060E90C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E90Cu, ctx.xmm[0].u32[0]);
	// 0x2CA830: ret
	return;
}

void sub_2CA840(X86Context& ctx, uint8_t* base) {
	// 0x2CA840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CA848: movss [0x0060E918], xmm0
	X86_MEM_WRITE_u32(base, 0x60E918u, ctx.xmm[0].u32[0]);
	// 0x2CA850: ret
	return;
}

void sub_2CA860(X86Context& ctx, uint8_t* base) {
	// 0x2CA860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CA868: movss [0x0060E904], xmm0
	X86_MEM_WRITE_u32(base, 0x60E904u, ctx.xmm[0].u32[0]);
	// 0x2CA870: ret
	return;
}

void sub_2CA880(X86Context& ctx, uint8_t* base) {
	// 0x2CA880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CA888: movss [0x0060E8EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8ECu, ctx.xmm[0].u32[0]);
	// 0x2CA890: ret
	return;
}

void sub_2CA8A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA8A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CA8A8: movss [0x0060E910], xmm0
	X86_MEM_WRITE_u32(base, 0x60E910u, ctx.xmm[0].u32[0]);
	// 0x2CA8B0: ret
	return;
}

void sub_2CA8C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA8C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CA8C8: movss [0x0060E8F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8F0u, ctx.xmm[0].u32[0]);
	// 0x2CA8D0: ret
	return;
}

void sub_2CA8E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA8E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CA8E8: movss [0x0060E920], xmm0
	X86_MEM_WRITE_u32(base, 0x60E920u, ctx.xmm[0].u32[0]);
	// 0x2CA8F0: ret
	return;
}

void sub_2CA900(X86Context& ctx, uint8_t* base) {
	// 0x2CA900: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CA908: movss [0x0060E908], xmm0
	X86_MEM_WRITE_u32(base, 0x60E908u, ctx.xmm[0].u32[0]);
	// 0x2CA910: ret
	return;
}

void sub_2CA920(X86Context& ctx, uint8_t* base) {
	// 0x2CA920: movss xmm0, dword ptr [0x0060E920]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E920u);
	// 0x2CA928: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CA930: movss [0x0060E8F8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8F8u, ctx.xmm[0].u32[0]);
	// 0x2CA938: ret
	return;
}

void sub_2CA940(X86Context& ctx, uint8_t* base) {
	// 0x2CA940: movss xmm0, dword ptr [0x0060E908]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E908u);
	// 0x2CA948: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CA950: movss [0x0060E91C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E91Cu, ctx.xmm[0].u32[0]);
	// 0x2CA958: ret
	return;
}

void sub_2CA960(X86Context& ctx, uint8_t* base) {
	// 0x2CA960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CA968: movss [0x0060E92C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E92Cu, ctx.xmm[0].u32[0]);
	// 0x2CA970: ret
	return;
}

void sub_2CA980(X86Context& ctx, uint8_t* base) {
	// 0x2CA980: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CA988: movss [0x0060E924], xmm0
	X86_MEM_WRITE_u32(base, 0x60E924u, ctx.xmm[0].u32[0]);
	// 0x2CA990: ret
	return;
}

void sub_2CA9A0(X86Context& ctx, uint8_t* base) {
	// 0x2CA9A0: movss xmm0, dword ptr [0x0060E924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E924u);
	// 0x2CA9A8: movss [0x0060E928], xmm0
	X86_MEM_WRITE_u32(base, 0x60E928u, ctx.xmm[0].u32[0]);
	// 0x2CA9B0: ret
	return;
}

void sub_2CA9C0(X86Context& ctx, uint8_t* base) {
	// 0x2CA9C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CA9C8: movss [0x0060E900], xmm0
	X86_MEM_WRITE_u32(base, 0x60E900u, ctx.xmm[0].u32[0]);
	// 0x2CA9D0: ret
	return;
}

void sub_2CA9E0(X86Context& ctx, uint8_t* base) {
	// 0x2CA9E0: movss xmm0, dword ptr [0x0060E908]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E908u);
	// 0x2CA9E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CA9F0: movss [0x0060E8FC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8FCu, ctx.xmm[0].u32[0]);
	// 0x2CA9F8: ret
	return;
}

void sub_2CAA00(X86Context& ctx, uint8_t* base) {
	// 0x2CAA00: movss xmm0, dword ptr [0x0060E908]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E908u);
	// 0x2CAA08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CAA10: movss [0x0060E914], xmm0
	X86_MEM_WRITE_u32(base, 0x60E914u, ctx.xmm[0].u32[0]);
	// 0x2CAA18: ret
	return;
}

void sub_2CAA20(X86Context& ctx, uint8_t* base) {
	// 0x2CAA20: movss xmm0, dword ptr [0x0060E908]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E908u);
	// 0x2CAA28: subss xmm0, [0x0060E914]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E914u);
	// 0x2CAA30: movss [0x0060E8F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E8F4u, ctx.xmm[0].u32[0]);
	// 0x2CAA38: ret
	return;
}

void sub_2CAA40(X86Context& ctx, uint8_t* base) {
	// 0x2CAA40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CAA48: movss [0x0060E950], xmm0
	X86_MEM_WRITE_u32(base, 0x60E950u, ctx.xmm[0].u32[0]);
	// 0x2CAA50: ret
	return;
}

void sub_2CAA60(X86Context& ctx, uint8_t* base) {
	// 0x2CAA60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CAA68: movss [0x0060E95C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E95Cu, ctx.xmm[0].u32[0]);
	// 0x2CAA70: ret
	return;
}

void sub_2CAA80(X86Context& ctx, uint8_t* base) {
	// 0x2CAA80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CAA88: movss [0x0060E94C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E94Cu, ctx.xmm[0].u32[0]);
	// 0x2CAA90: ret
	return;
}

void sub_2CAAA0(X86Context& ctx, uint8_t* base) {
	// 0x2CAAA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CAAA8: movss [0x0060E930], xmm0
	X86_MEM_WRITE_u32(base, 0x60E930u, ctx.xmm[0].u32[0]);
	// 0x2CAAB0: ret
	return;
}

void sub_2CAAC0(X86Context& ctx, uint8_t* base) {
	// 0x2CAAC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CAAC8: movss [0x0060E954], xmm0
	X86_MEM_WRITE_u32(base, 0x60E954u, ctx.xmm[0].u32[0]);
	// 0x2CAAD0: ret
	return;
}

void sub_2CAAE0(X86Context& ctx, uint8_t* base) {
	// 0x2CAAE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CAAE8: movss [0x0060E938], xmm0
	X86_MEM_WRITE_u32(base, 0x60E938u, ctx.xmm[0].u32[0]);
	// 0x2CAAF0: ret
	return;
}

void sub_2CAB00(X86Context& ctx, uint8_t* base) {
	// 0x2CAB00: movss xmm0, dword ptr [0x0060E954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E954u);
	// 0x2CAB08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CAB10: movss [0x0060E964], xmm0
	X86_MEM_WRITE_u32(base, 0x60E964u, ctx.xmm[0].u32[0]);
	// 0x2CAB18: ret
	return;
}

void sub_2CAB20(X86Context& ctx, uint8_t* base) {
	// 0x2CAB20: movss xmm0, dword ptr [0x0060E938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E938u);
	// 0x2CAB28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CAB30: movss [0x0060E960], xmm0
	X86_MEM_WRITE_u32(base, 0x60E960u, ctx.xmm[0].u32[0]);
	// 0x2CAB38: ret
	return;
}

void sub_2CAB40(X86Context& ctx, uint8_t* base) {
	// 0x2CAB40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CAB48: movss [0x0060E974], xmm0
	X86_MEM_WRITE_u32(base, 0x60E974u, ctx.xmm[0].u32[0]);
	// 0x2CAB50: ret
	return;
}

void sub_2CAB60(X86Context& ctx, uint8_t* base) {
	// 0x2CAB60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CAB68: movss [0x0060E968], xmm0
	X86_MEM_WRITE_u32(base, 0x60E968u, ctx.xmm[0].u32[0]);
	// 0x2CAB70: ret
	return;
}

void sub_2CAB80(X86Context& ctx, uint8_t* base) {
	// 0x2CAB80: movss xmm0, dword ptr [0x0060E968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E968u);
	// 0x2CAB88: movss [0x0060E970], xmm0
	X86_MEM_WRITE_u32(base, 0x60E970u, ctx.xmm[0].u32[0]);
	// 0x2CAB90: ret
	return;
}

void sub_2CABA0(X86Context& ctx, uint8_t* base) {
	// 0x2CABA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CABA8: movss [0x0060E934], xmm0
	X86_MEM_WRITE_u32(base, 0x60E934u, ctx.xmm[0].u32[0]);
	// 0x2CABB0: ret
	return;
}

void sub_2CABC0(X86Context& ctx, uint8_t* base) {
	// 0x2CABC0: movss xmm0, dword ptr [0x0060E938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E938u);
	// 0x2CABC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CABD0: movss [0x0060E96C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E96Cu, ctx.xmm[0].u32[0]);
	// 0x2CABD8: ret
	return;
}

void sub_2CABE0(X86Context& ctx, uint8_t* base) {
	// 0x2CABE0: movss xmm0, dword ptr [0x0060E938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E938u);
	// 0x2CABE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CABF0: movss [0x0060E948], xmm0
	X86_MEM_WRITE_u32(base, 0x60E948u, ctx.xmm[0].u32[0]);
	// 0x2CABF8: ret
	return;
}

void sub_2CAC00(X86Context& ctx, uint8_t* base) {
	// 0x2CAC00: movss xmm0, dword ptr [0x0060E938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E938u);
	// 0x2CAC08: subss xmm0, [0x0060E948]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E948u);
	// 0x2CAC10: movss [0x0060E940], xmm0
	X86_MEM_WRITE_u32(base, 0x60E940u, ctx.xmm[0].u32[0]);
	// 0x2CAC18: ret
	return;
}

void sub_2CAC20(X86Context& ctx, uint8_t* base) {
	// 0x2CAC20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CAC28: movss [0x0060E958], xmm0
	X86_MEM_WRITE_u32(base, 0x60E958u, ctx.xmm[0].u32[0]);
	// 0x2CAC30: ret
	return;
}

void sub_2CAC40(X86Context& ctx, uint8_t* base) {
	// 0x2CAC40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CAC48: movss [0x0060E93C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E93Cu, ctx.xmm[0].u32[0]);
	// 0x2CAC50: ret
	return;
}

void sub_2CAC60(X86Context& ctx, uint8_t* base) {
	// 0x2CAC60: movss xmm0, dword ptr [0x003A5E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A5E44u);
	// 0x2CAC68: movss [0x0060E944], xmm0
	X86_MEM_WRITE_u32(base, 0x60E944u, ctx.xmm[0].u32[0]);
	// 0x2CAC70: ret
	return;
}

void sub_2CAC80(X86Context& ctx, uint8_t* base) {
	// 0x2CAC80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CAC88: movss [0x0060E984], xmm0
	X86_MEM_WRITE_u32(base, 0x60E984u, ctx.xmm[0].u32[0]);
	// 0x2CAC90: ret
	return;
}

void sub_2CACA0(X86Context& ctx, uint8_t* base) {
	// 0x2CACA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CACA8: movss [0x0060E98C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E98Cu, ctx.xmm[0].u32[0]);
	// 0x2CACB0: ret
	return;
}

void sub_2CACC0(X86Context& ctx, uint8_t* base) {
	// 0x2CACC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CACC8: movss [0x0060E980], xmm0
	X86_MEM_WRITE_u32(base, 0x60E980u, ctx.xmm[0].u32[0]);
	// 0x2CACD0: ret
	return;
}

void sub_2CACE0(X86Context& ctx, uint8_t* base) {
	// 0x2CACE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CACE8: movss [0x0060E978], xmm0
	X86_MEM_WRITE_u32(base, 0x60E978u, ctx.xmm[0].u32[0]);
	// 0x2CACF0: ret
	return;
}

void sub_2CAD00(X86Context& ctx, uint8_t* base) {
	// 0x2CAD00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CAD08: movss [0x0060E988], xmm0
	X86_MEM_WRITE_u32(base, 0x60E988u, ctx.xmm[0].u32[0]);
	// 0x2CAD10: ret
	return;
}

void sub_2CAD20(X86Context& ctx, uint8_t* base) {
	// 0x2CAD20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CAD28: movss [0x0060E97C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E97Cu, ctx.xmm[0].u32[0]);
	// 0x2CAD30: ret
	return;
}

void sub_2CAD40(X86Context& ctx, uint8_t* base) {
	// 0x2CAD40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CAD48: movss [0x0060E9B0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9B0u, ctx.xmm[0].u32[0]);
	// 0x2CAD50: ret
	return;
}

void sub_2CAD60(X86Context& ctx, uint8_t* base) {
	// 0x2CAD60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CAD68: movss [0x0060E9BC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9BCu, ctx.xmm[0].u32[0]);
	// 0x2CAD70: ret
	return;
}

void sub_2CAD80(X86Context& ctx, uint8_t* base) {
	// 0x2CAD80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CAD88: movss [0x0060E9A8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9A8u, ctx.xmm[0].u32[0]);
	// 0x2CAD90: ret
	return;
}

void sub_2CADA0(X86Context& ctx, uint8_t* base) {
	// 0x2CADA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CADA8: movss [0x0060E990], xmm0
	X86_MEM_WRITE_u32(base, 0x60E990u, ctx.xmm[0].u32[0]);
	// 0x2CADB0: ret
	return;
}

void sub_2CADC0(X86Context& ctx, uint8_t* base) {
	// 0x2CADC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CADC8: movss [0x0060E9B4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9B4u, ctx.xmm[0].u32[0]);
	// 0x2CADD0: ret
	return;
}

void sub_2CADE0(X86Context& ctx, uint8_t* base) {
	// 0x2CADE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CADE8: movss [0x0060E994], xmm0
	X86_MEM_WRITE_u32(base, 0x60E994u, ctx.xmm[0].u32[0]);
	// 0x2CADF0: ret
	return;
}

void sub_2CAE00(X86Context& ctx, uint8_t* base) {
	// 0x2CAE00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CAE08: movss [0x0060E9C4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9C4u, ctx.xmm[0].u32[0]);
	// 0x2CAE10: ret
	return;
}

void sub_2CAE20(X86Context& ctx, uint8_t* base) {
	// 0x2CAE20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CAE28: movss [0x0060E9AC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9ACu, ctx.xmm[0].u32[0]);
	// 0x2CAE30: ret
	return;
}

void sub_2CAE40(X86Context& ctx, uint8_t* base) {
	// 0x2CAE40: movss xmm0, dword ptr [0x0060E9C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9C4u);
	// 0x2CAE48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CAE50: movss [0x0060E99C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E99Cu, ctx.xmm[0].u32[0]);
	// 0x2CAE58: ret
	return;
}

void sub_2CAE60(X86Context& ctx, uint8_t* base) {
	// 0x2CAE60: movss xmm0, dword ptr [0x0060E9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9ACu);
	// 0x2CAE68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CAE70: movss [0x0060E9C0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9C0u, ctx.xmm[0].u32[0]);
	// 0x2CAE78: ret
	return;
}

void sub_2CAE80(X86Context& ctx, uint8_t* base) {
	// 0x2CAE80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CAE88: movss [0x0060E9D0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9D0u, ctx.xmm[0].u32[0]);
	// 0x2CAE90: ret
	return;
}

void sub_2CAEA0(X86Context& ctx, uint8_t* base) {
	// 0x2CAEA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CAEA8: movss [0x0060E9C8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9C8u, ctx.xmm[0].u32[0]);
	// 0x2CAEB0: ret
	return;
}

void sub_2CAEC0(X86Context& ctx, uint8_t* base) {
	// 0x2CAEC0: movss xmm0, dword ptr [0x0060E9C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9C8u);
	// 0x2CAEC8: movss [0x0060E9CC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9CCu, ctx.xmm[0].u32[0]);
	// 0x2CAED0: ret
	return;
}

void sub_2CAEE0(X86Context& ctx, uint8_t* base) {
	// 0x2CAEE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CAEE8: movss [0x0060E9A4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9A4u, ctx.xmm[0].u32[0]);
	// 0x2CAEF0: ret
	return;
}

void sub_2CAF00(X86Context& ctx, uint8_t* base) {
	// 0x2CAF00: movss xmm0, dword ptr [0x0060E9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9ACu);
	// 0x2CAF08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CAF10: movss [0x0060E9A0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9A0u, ctx.xmm[0].u32[0]);
	// 0x2CAF18: ret
	return;
}

void sub_2CAF20(X86Context& ctx, uint8_t* base) {
	// 0x2CAF20: movss xmm0, dword ptr [0x0060E9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9ACu);
	// 0x2CAF28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CAF30: movss [0x0060E9B8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9B8u, ctx.xmm[0].u32[0]);
	// 0x2CAF38: ret
	return;
}

void sub_2CAF40(X86Context& ctx, uint8_t* base) {
	// 0x2CAF40: movss xmm0, dword ptr [0x0060E9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9ACu);
	// 0x2CAF48: subss xmm0, [0x0060E9B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E9B8u);
	// 0x2CAF50: movss [0x0060E998], xmm0
	X86_MEM_WRITE_u32(base, 0x60E998u, ctx.xmm[0].u32[0]);
	// 0x2CAF58: ret
	return;
}

void sub_2CAF60(X86Context& ctx, uint8_t* base) {
	// 0x2CAF60: movss xmm3, dword ptr [0x003A55F8]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x2CAF68: movss xmm4, dword ptr [0x003895BC]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x2CAF70: movss xmm0, dword ptr [0x003B1698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x2CAF78: xorps xmm2, xmm2
	memset(&ctx.xmm[2], 0, sizeof(ctx.xmm[2]));
	// 0x2CAF7B: movss xmm1, dword ptr [0x003B1688]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2CAF83: movss xmm5, dword ptr [0x003B1684]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2CAF8B: movss [0x0041A458], xmm3
	X86_MEM_WRITE_u32(base, 0x41A458u, ctx.xmm[3].u32[0]);
	// 0x2CAF93: movss [0x0041A45C], xmm4
	X86_MEM_WRITE_u32(base, 0x41A45Cu, ctx.xmm[4].u32[0]);
	// 0x2CAF9B: movss [0x0041A46C], xmm4
	X86_MEM_WRITE_u32(base, 0x41A46Cu, ctx.xmm[4].u32[0]);
	// 0x2CAFA3: movss xmm4, dword ptr [0x003B18B8]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3B18B8u);
	// 0x2CAFAB: movss [0x0041A47C], xmm3
	X86_MEM_WRITE_u32(base, 0x41A47Cu, ctx.xmm[3].u32[0]);
	// 0x2CAFB3: movss xmm3, dword ptr [0x003B1870]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x2CAFBB: movss [0x0041A454], xmm2
	X86_MEM_WRITE_u32(base, 0x41A454u, ctx.xmm[2].u32[0]);
	// 0x2CAFC3: movss [0x0041A470], xmm4
	X86_MEM_WRITE_u32(base, 0x41A470u, ctx.xmm[4].u32[0]);
	// 0x2CAFCB: movss xmm4, dword ptr [0x003B1F34]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3B1F34u);
	// 0x2CAFD3: movss [0x0041A480], xmm3
	X86_MEM_WRITE_u32(base, 0x41A480u, ctx.xmm[3].u32[0]);
	// 0x2CAFDB: movss xmm3, dword ptr [0x003B1864]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1864u);
	// 0x2CAFE3: movss [0x0041A490], xmm2
	X86_MEM_WRITE_u32(base, 0x41A490u, ctx.xmm[2].u32[0]);
	// 0x2CAFEB: movss xmm2, dword ptr [0x003B168C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2CAFF3: movss [0x0041A450], xmm0
	X86_MEM_WRITE_u32(base, 0x41A450u, ctx.xmm[0].u32[0]);
	// 0x2CAFFB: movss [0x0041A460], xmm1
	X86_MEM_WRITE_u32(base, 0x41A460u, ctx.xmm[1].u32[0]);
	// 0x2CB003: movss [0x0041A464], xmm0
	X86_MEM_WRITE_u32(base, 0x41A464u, ctx.xmm[0].u32[0]);
	// 0x2CB00B: movss [0x0041A468], xmm5
	X86_MEM_WRITE_u32(base, 0x41A468u, ctx.xmm[5].u32[0]);
	// 0x2CB013: movss [0x0041A474], xmm4
	X86_MEM_WRITE_u32(base, 0x41A474u, ctx.xmm[4].u32[0]);
	// 0x2CB01B: movss [0x0041A478], xmm0
	X86_MEM_WRITE_u32(base, 0x41A478u, ctx.xmm[0].u32[0]);
	// 0x2CB023: movss [0x0041A484], xmm1
	X86_MEM_WRITE_u32(base, 0x41A484u, ctx.xmm[1].u32[0]);
	// 0x2CB02B: movss [0x0041A488], xmm3
	X86_MEM_WRITE_u32(base, 0x41A488u, ctx.xmm[3].u32[0]);
	// 0x2CB033: movss [0x0041A48C], xmm0
	X86_MEM_WRITE_u32(base, 0x41A48Cu, ctx.xmm[0].u32[0]);
	// 0x2CB03B: movss [0x0041A494], xmm2
	X86_MEM_WRITE_u32(base, 0x41A494u, ctx.xmm[2].u32[0]);
	// 0x2CB043: movss [0x0041A498], xmm1
	X86_MEM_WRITE_u32(base, 0x41A498u, ctx.xmm[1].u32[0]);
	// 0x2CB04B: movss [0x0041A49C], xmm3
	X86_MEM_WRITE_u32(base, 0x41A49Cu, ctx.xmm[3].u32[0]);
	// 0x2CB053: movss [0x0041A4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x41A4A0u, ctx.xmm[0].u32[0]);
	// 0x2CB05B: ret
	return;
}

void sub_2CB060(X86Context& ctx, uint8_t* base) {
	// 0x2CB060: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CB068: movss [0x0060E9D8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9D8u, ctx.xmm[0].u32[0]);
	// 0x2CB070: ret
	return;
}

void sub_2CB080(X86Context& ctx, uint8_t* base) {
	// 0x2CB080: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CB088: movss [0x0060E9DC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9DCu, ctx.xmm[0].u32[0]);
	// 0x2CB090: ret
	return;
}

void sub_2CB0A0(X86Context& ctx, uint8_t* base) {
	// 0x2CB0A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CB0A8: movss [0x0060E9D4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9D4u, ctx.xmm[0].u32[0]);
	// 0x2CB0B0: ret
	return;
}

void sub_2CB0C0(X86Context& ctx, uint8_t* base) {
	// 0x2CB0C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CB0C8: movss [0x00752D94], xmm0
	X86_MEM_WRITE_u32(base, 0x752D94u, ctx.xmm[0].u32[0]);
	// 0x2CB0D0: ret
	return;
}

void sub_2CB0E0(X86Context& ctx, uint8_t* base) {
	// 0x2CB0E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CB0E8: movss [0x00752DA0], xmm0
	X86_MEM_WRITE_u32(base, 0x752DA0u, ctx.xmm[0].u32[0]);
	// 0x2CB0F0: ret
	return;
}

void sub_2CB100(X86Context& ctx, uint8_t* base) {
	// 0x2CB100: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CB108: movss [0x00752D90], xmm0
	X86_MEM_WRITE_u32(base, 0x752D90u, ctx.xmm[0].u32[0]);
	// 0x2CB110: ret
	return;
}

void sub_2CB120(X86Context& ctx, uint8_t* base) {
	// 0x2CB120: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CB128: movss [0x0060E9E0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9E0u, ctx.xmm[0].u32[0]);
	// 0x2CB130: ret
	return;
}

void sub_2CB140(X86Context& ctx, uint8_t* base) {
	// 0x2CB140: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CB148: movss [0x00752D98], xmm0
	X86_MEM_WRITE_u32(base, 0x752D98u, ctx.xmm[0].u32[0]);
	// 0x2CB150: ret
	return;
}

void sub_2CB160(X86Context& ctx, uint8_t* base) {
	// 0x2CB160: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CB168: movss [0x0060E9E8], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9E8u, ctx.xmm[0].u32[0]);
	// 0x2CB170: ret
	return;
}

void sub_2CB180(X86Context& ctx, uint8_t* base) {
	// 0x2CB180: movss xmm0, dword ptr [0x00752D98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752D98u);
	// 0x2CB188: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CB190: movss [0x00752DA8], xmm0
	X86_MEM_WRITE_u32(base, 0x752DA8u, ctx.xmm[0].u32[0]);
	// 0x2CB198: ret
	return;
}

void sub_2CB1A0(X86Context& ctx, uint8_t* base) {
	// 0x2CB1A0: movss xmm0, dword ptr [0x0060E9E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9E8u);
	// 0x2CB1A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CB1B0: movss [0x00752DA4], xmm0
	X86_MEM_WRITE_u32(base, 0x752DA4u, ctx.xmm[0].u32[0]);
	// 0x2CB1B8: ret
	return;
}

void sub_2CB1C0(X86Context& ctx, uint8_t* base) {
	// 0x2CB1C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CB1C8: movss [0x00752DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x752DB8u, ctx.xmm[0].u32[0]);
	// 0x2CB1D0: ret
	return;
}

void sub_2CB1E0(X86Context& ctx, uint8_t* base) {
	// 0x2CB1E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CB1E8: movss [0x00752DAC], xmm0
	X86_MEM_WRITE_u32(base, 0x752DACu, ctx.xmm[0].u32[0]);
	// 0x2CB1F0: ret
	return;
}

void sub_2CB200(X86Context& ctx, uint8_t* base) {
	// 0x2CB200: movss xmm0, dword ptr [0x00752DAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752DACu);
	// 0x2CB208: movss [0x00752DB4], xmm0
	X86_MEM_WRITE_u32(base, 0x752DB4u, ctx.xmm[0].u32[0]);
	// 0x2CB210: ret
	return;
}

void sub_2CB220(X86Context& ctx, uint8_t* base) {
	// 0x2CB220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CB228: movss [0x0060E9E4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9E4u, ctx.xmm[0].u32[0]);
	// 0x2CB230: ret
	return;
}

void sub_2CB240(X86Context& ctx, uint8_t* base) {
	// 0x2CB240: movss xmm0, dword ptr [0x0060E9E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9E8u);
	// 0x2CB248: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CB250: movss [0x00752DB0], xmm0
	X86_MEM_WRITE_u32(base, 0x752DB0u, ctx.xmm[0].u32[0]);
	// 0x2CB258: ret
	return;
}

void sub_2CB260(X86Context& ctx, uint8_t* base) {
	// 0x2CB260: movss xmm0, dword ptr [0x0060E9E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9E8u);
	// 0x2CB268: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CB270: movss [0x0060E9F4], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9F4u, ctx.xmm[0].u32[0]);
	// 0x2CB278: ret
	return;
}

void sub_2CB280(X86Context& ctx, uint8_t* base) {
	// 0x2CB280: movss xmm0, dword ptr [0x0060E9E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60E9E8u);
	// 0x2CB288: subss xmm0, [0x0060E9F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x60E9F4u);
	// 0x2CB290: movss [0x0060E9F0], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9F0u, ctx.xmm[0].u32[0]);
	// 0x2CB298: ret
	return;
}

void sub_2CB2A0(X86Context& ctx, uint8_t* base) {
	// 0x2CB2A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CB2A8: movss [0x00752D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x752D9Cu, ctx.xmm[0].u32[0]);
	// 0x2CB2B0: ret
	return;
}

void sub_2CB2C0(X86Context& ctx, uint8_t* base) {
	// 0x2CB2C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CB2C8: movss [0x0060E9EC], xmm0
	X86_MEM_WRITE_u32(base, 0x60E9ECu, ctx.xmm[0].u32[0]);
	// 0x2CB2D0: ret
	return;
}

void sub_2CB2E0(X86Context& ctx, uint8_t* base) {
	// 0x2CB2E0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2CB2E1: mov esi, 0x60EA00
	ctx.esi = 6351360;
	// 0x2CB2E6: call 0x001A9930
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1A9930(ctx, base);
	ctx.esp += 4;
	// 0x2CB2EB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2CB2EC: ret
	return;
}

void sub_2CB2F0(X86Context& ctx, uint8_t* base) {
	// 0x2CB2F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CB2F8: movss [0x00752DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x752DC8u, ctx.xmm[0].u32[0]);
	// 0x2CB300: ret
	return;
}

void sub_2CB310(X86Context& ctx, uint8_t* base) {
	// 0x2CB310: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CB318: movss [0x00752DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x752DD0u, ctx.xmm[0].u32[0]);
	// 0x2CB320: ret
	return;
}

void sub_2CB330(X86Context& ctx, uint8_t* base) {
	// 0x2CB330: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CB338: movss [0x00752DC4], xmm0
	X86_MEM_WRITE_u32(base, 0x752DC4u, ctx.xmm[0].u32[0]);
	// 0x2CB340: ret
	return;
}

void sub_2CB350(X86Context& ctx, uint8_t* base) {
	// 0x2CB350: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CB358: movss [0x00752DBC], xmm0
	X86_MEM_WRITE_u32(base, 0x752DBCu, ctx.xmm[0].u32[0]);
	// 0x2CB360: ret
	return;
}

void sub_2CB370(X86Context& ctx, uint8_t* base) {
	// 0x2CB370: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CB378: movss [0x00752DCC], xmm0
	X86_MEM_WRITE_u32(base, 0x752DCCu, ctx.xmm[0].u32[0]);
	// 0x2CB380: ret
	return;
}

void sub_2CB390(X86Context& ctx, uint8_t* base) {
	// 0x2CB390: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CB398: movss [0x00752DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x752DC0u, ctx.xmm[0].u32[0]);
	// 0x2CB3A0: ret
	return;
}

void sub_2CB3B0(X86Context& ctx, uint8_t* base) {
	// 0x2CB3B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CB3B8: movss [0x00752DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x752DF0u, ctx.xmm[0].u32[0]);
	// 0x2CB3C0: ret
	return;
}

void sub_2CB3D0(X86Context& ctx, uint8_t* base) {
	// 0x2CB3D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CB3D8: movss [0x00752DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x752DFCu, ctx.xmm[0].u32[0]);
	// 0x2CB3E0: ret
	return;
}

void sub_2CB3F0(X86Context& ctx, uint8_t* base) {
	// 0x2CB3F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CB3F8: movss [0x00752DEC], xmm0
	X86_MEM_WRITE_u32(base, 0x752DECu, ctx.xmm[0].u32[0]);
	// 0x2CB400: ret
	return;
}

void sub_2CB410(X86Context& ctx, uint8_t* base) {
	// 0x2CB410: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CB418: movss [0x00752DD4], xmm0
	X86_MEM_WRITE_u32(base, 0x752DD4u, ctx.xmm[0].u32[0]);
	// 0x2CB420: ret
	return;
}

void sub_2CB430(X86Context& ctx, uint8_t* base) {
	// 0x2CB430: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CB438: movss [0x00752DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x752DF4u, ctx.xmm[0].u32[0]);
	// 0x2CB440: ret
	return;
}

void sub_2CB450(X86Context& ctx, uint8_t* base) {
	// 0x2CB450: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CB458: movss [0x00752DDC], xmm0
	X86_MEM_WRITE_u32(base, 0x752DDCu, ctx.xmm[0].u32[0]);
	// 0x2CB460: ret
	return;
}

void sub_2CB470(X86Context& ctx, uint8_t* base) {
	// 0x2CB470: movss xmm0, dword ptr [0x00752DF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752DF4u);
	// 0x2CB478: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CB480: movss [0x00752E04], xmm0
	X86_MEM_WRITE_u32(base, 0x752E04u, ctx.xmm[0].u32[0]);
	// 0x2CB488: ret
	return;
}

void sub_2CB490(X86Context& ctx, uint8_t* base) {
	// 0x2CB490: movss xmm0, dword ptr [0x00752DDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752DDCu);
	// 0x2CB498: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CB4A0: movss [0x00752E00], xmm0
	X86_MEM_WRITE_u32(base, 0x752E00u, ctx.xmm[0].u32[0]);
	// 0x2CB4A8: ret
	return;
}

void sub_2CB4B0(X86Context& ctx, uint8_t* base) {
	// 0x2CB4B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CB4B8: movss [0x00752E14], xmm0
	X86_MEM_WRITE_u32(base, 0x752E14u, ctx.xmm[0].u32[0]);
	// 0x2CB4C0: ret
	return;
}

void sub_2CB4D0(X86Context& ctx, uint8_t* base) {
	// 0x2CB4D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2CB4D8: movss [0x00752E08], xmm0
	X86_MEM_WRITE_u32(base, 0x752E08u, ctx.xmm[0].u32[0]);
	// 0x2CB4E0: ret
	return;
}

void sub_2CB4F0(X86Context& ctx, uint8_t* base) {
	// 0x2CB4F0: movss xmm0, dword ptr [0x00752E08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752E08u);
	// 0x2CB4F8: movss [0x00752E10], xmm0
	X86_MEM_WRITE_u32(base, 0x752E10u, ctx.xmm[0].u32[0]);
	// 0x2CB500: ret
	return;
}

void sub_2CB510(X86Context& ctx, uint8_t* base) {
	// 0x2CB510: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CB518: movss [0x00752DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x752DD8u, ctx.xmm[0].u32[0]);
	// 0x2CB520: ret
	return;
}

void sub_2CB530(X86Context& ctx, uint8_t* base) {
	// 0x2CB530: movss xmm0, dword ptr [0x00752DDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752DDCu);
	// 0x2CB538: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2CB540: movss [0x00752E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x752E0Cu, ctx.xmm[0].u32[0]);
	// 0x2CB548: ret
	return;
}

void sub_2CB550(X86Context& ctx, uint8_t* base) {
	// 0x2CB550: movss xmm0, dword ptr [0x00752DDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752DDCu);
	// 0x2CB558: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2CB560: movss [0x00752DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x752DE8u, ctx.xmm[0].u32[0]);
	// 0x2CB568: ret
	return;
}

void sub_2CB570(X86Context& ctx, uint8_t* base) {
	// 0x2CB570: movss xmm0, dword ptr [0x00752DDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752DDCu);
	// 0x2CB578: subss xmm0, [0x00752DE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x752DE8u);
	// 0x2CB580: movss [0x00752DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x752DE4u, ctx.xmm[0].u32[0]);
	// 0x2CB588: ret
	return;
}

void sub_2CB590(X86Context& ctx, uint8_t* base) {
	// 0x2CB590: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2CB598: movss [0x00752DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x752DF8u, ctx.xmm[0].u32[0]);
	// 0x2CB5A0: ret
	return;
}

void sub_2CB5B0(X86Context& ctx, uint8_t* base) {
	// 0x2CB5B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2CB5B8: movss [0x00752DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x752DE0u, ctx.xmm[0].u32[0]);
	// 0x2CB5C0: ret
	return;
}

void sub_2CB5D0(X86Context& ctx, uint8_t* base) {
	// 0x2CB5D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2CB5D8: movss [0x00752E34], xmm0
	X86_MEM_WRITE_u32(base, 0x752E34u, ctx.xmm[0].u32[0]);
	// 0x2CB5E0: ret
	return;
}

void sub_2CB5F0(X86Context& ctx, uint8_t* base) {
	// 0x2CB5F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2CB5F8: movss [0x00752E40], xmm0
	X86_MEM_WRITE_u32(base, 0x752E40u, ctx.xmm[0].u32[0]);
	// 0x2CB600: ret
	return;
}

void sub_2CB610(X86Context& ctx, uint8_t* base) {
	// 0x2CB610: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2CB618: movss [0x00752E30], xmm0
	X86_MEM_WRITE_u32(base, 0x752E30u, ctx.xmm[0].u32[0]);
	// 0x2CB620: ret
	return;
}

void sub_2CB630(X86Context& ctx, uint8_t* base) {
	// 0x2CB630: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2CB638: movss [0x00752E18], xmm0
	X86_MEM_WRITE_u32(base, 0x752E18u, ctx.xmm[0].u32[0]);
	// 0x2CB640: ret
	return;
}

void sub_2CB650(X86Context& ctx, uint8_t* base) {
	// 0x2CB650: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2CB658: movss [0x00752E38], xmm0
	X86_MEM_WRITE_u32(base, 0x752E38u, ctx.xmm[0].u32[0]);
	// 0x2CB660: ret
	return;
}

void sub_2CB670(X86Context& ctx, uint8_t* base) {
	// 0x2CB670: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2CB678: movss [0x00752E20], xmm0
	X86_MEM_WRITE_u32(base, 0x752E20u, ctx.xmm[0].u32[0]);
	// 0x2CB680: ret
	return;
}

void sub_2CB690(X86Context& ctx, uint8_t* base) {
	// 0x2CB690: movss xmm0, dword ptr [0x00752E38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752E38u);
	// 0x2CB698: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2CB6A0: movss [0x00752E48], xmm0
	X86_MEM_WRITE_u32(base, 0x752E48u, ctx.xmm[0].u32[0]);
	// 0x2CB6A8: ret
	return;
}

void sub_2CB6B0(X86Context& ctx, uint8_t* base) {
	// 0x2CB6B0: movss xmm0, dword ptr [0x00752E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x752E20u);
	// 0x2CB6B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2CB6C0: movss [0x00752E44], xmm0
	X86_MEM_WRITE_u32(base, 0x752E44u, ctx.xmm[0].u32[0]);
	// 0x2CB6C8: ret
	return;
}

void sub_2CB6D0(X86Context& ctx, uint8_t* base) {
	// 0x2CB6D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2CB6D8: movss [0x00752E58], xmm0
	X86_MEM_WRITE_u32(base, 0x752E58u, ctx.xmm[0].u32[0]);
	// 0x2CB6E0: ret
	return;
}

