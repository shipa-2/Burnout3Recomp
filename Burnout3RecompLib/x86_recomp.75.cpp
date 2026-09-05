#include "x86_recomp_shared.h"

void sub_2B95C0(X86Context& ctx, uint8_t* base) {
	// 0x2B95C0: movss xmm0, dword ptr [0x005A7694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7694u);
	// 0x2B95C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B95D0: movss [0x005A76B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76B8u, ctx.xmm[0].u32[0]);
	// 0x2B95D8: ret
	return;
}

void sub_2B95E0(X86Context& ctx, uint8_t* base) {
	// 0x2B95E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B95E8: movss [0x005A76CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76CCu, ctx.xmm[0].u32[0]);
	// 0x2B95F0: ret
	return;
}

void sub_2B9600(X86Context& ctx, uint8_t* base) {
	// 0x2B9600: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B9608: movss [0x005A76C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76C0u, ctx.xmm[0].u32[0]);
	// 0x2B9610: ret
	return;
}

void sub_2B9620(X86Context& ctx, uint8_t* base) {
	// 0x2B9620: movss xmm0, dword ptr [0x005A76C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76C0u);
	// 0x2B9628: movss [0x005A76C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76C8u, ctx.xmm[0].u32[0]);
	// 0x2B9630: ret
	return;
}

void sub_2B9640(X86Context& ctx, uint8_t* base) {
	// 0x2B9640: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9648: movss [0x005A7690], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7690u, ctx.xmm[0].u32[0]);
	// 0x2B9650: ret
	return;
}

void sub_2B9660(X86Context& ctx, uint8_t* base) {
	// 0x2B9660: movss xmm0, dword ptr [0x005A7694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7694u);
	// 0x2B9668: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9670: movss [0x005A76C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76C4u, ctx.xmm[0].u32[0]);
	// 0x2B9678: ret
	return;
}

void sub_2B9680(X86Context& ctx, uint8_t* base) {
	// 0x2B9680: movss xmm0, dword ptr [0x005A7694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7694u);
	// 0x2B9688: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B9690: movss [0x005A76A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76A0u, ctx.xmm[0].u32[0]);
	// 0x2B9698: ret
	return;
}

void sub_2B96A0(X86Context& ctx, uint8_t* base) {
	// 0x2B96A0: movss xmm0, dword ptr [0x005A7694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7694u);
	// 0x2B96A8: subss xmm0, [0x005A76A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A76A0u);
	// 0x2B96B0: movss [0x005A769C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A769Cu, ctx.xmm[0].u32[0]);
	// 0x2B96B8: ret
	return;
}

void sub_2B96C0(X86Context& ctx, uint8_t* base) {
	// 0x2B96C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B96C8: movss [0x005A76B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76B0u, ctx.xmm[0].u32[0]);
	// 0x2B96D0: ret
	return;
}

void sub_2B96E0(X86Context& ctx, uint8_t* base) {
	// 0x2B96E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B96E8: movss [0x005A7698], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7698u, ctx.xmm[0].u32[0]);
	// 0x2B96F0: ret
	return;
}

void sub_2B9700(X86Context& ctx, uint8_t* base) {
	// 0x2B9700: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9708: movss [0x005A76EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76ECu, ctx.xmm[0].u32[0]);
	// 0x2B9710: ret
	return;
}

void sub_2B9720(X86Context& ctx, uint8_t* base) {
	// 0x2B9720: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9728: movss [0x005A76F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76F8u, ctx.xmm[0].u32[0]);
	// 0x2B9730: ret
	return;
}

void sub_2B9740(X86Context& ctx, uint8_t* base) {
	// 0x2B9740: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9748: movss [0x005A76E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76E8u, ctx.xmm[0].u32[0]);
	// 0x2B9750: ret
	return;
}

void sub_2B9760(X86Context& ctx, uint8_t* base) {
	// 0x2B9760: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9768: movss [0x005A76D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76D0u, ctx.xmm[0].u32[0]);
	// 0x2B9770: ret
	return;
}

void sub_2B9780(X86Context& ctx, uint8_t* base) {
	// 0x2B9780: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B9788: movss [0x005A76F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76F0u, ctx.xmm[0].u32[0]);
	// 0x2B9790: ret
	return;
}

void sub_2B97A0(X86Context& ctx, uint8_t* base) {
	// 0x2B97A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B97A8: movss [0x005A76D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76D8u, ctx.xmm[0].u32[0]);
	// 0x2B97B0: ret
	return;
}

void sub_2B97C0(X86Context& ctx, uint8_t* base) {
	// 0x2B97C0: movss xmm0, dword ptr [0x005A76F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76F0u);
	// 0x2B97C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B97D0: movss [0x005A7700], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7700u, ctx.xmm[0].u32[0]);
	// 0x2B97D8: ret
	return;
}

void sub_2B97E0(X86Context& ctx, uint8_t* base) {
	// 0x2B97E0: movss xmm0, dword ptr [0x005A76D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76D8u);
	// 0x2B97E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B97F0: movss [0x005A76FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76FCu, ctx.xmm[0].u32[0]);
	// 0x2B97F8: ret
	return;
}

void sub_2B9800(X86Context& ctx, uint8_t* base) {
	// 0x2B9800: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9808: movss [0x005A7710], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7710u, ctx.xmm[0].u32[0]);
	// 0x2B9810: ret
	return;
}

void sub_2B9820(X86Context& ctx, uint8_t* base) {
	// 0x2B9820: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B9828: movss [0x005A7704], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7704u, ctx.xmm[0].u32[0]);
	// 0x2B9830: ret
	return;
}

void sub_2B9840(X86Context& ctx, uint8_t* base) {
	// 0x2B9840: movss xmm0, dword ptr [0x005A7704]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7704u);
	// 0x2B9848: movss [0x005A770C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A770Cu, ctx.xmm[0].u32[0]);
	// 0x2B9850: ret
	return;
}

void sub_2B9860(X86Context& ctx, uint8_t* base) {
	// 0x2B9860: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9868: movss [0x005A76D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76D4u, ctx.xmm[0].u32[0]);
	// 0x2B9870: ret
	return;
}

void sub_2B9880(X86Context& ctx, uint8_t* base) {
	// 0x2B9880: movss xmm0, dword ptr [0x005A76D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76D8u);
	// 0x2B9888: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9890: movss [0x005A7708], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7708u, ctx.xmm[0].u32[0]);
	// 0x2B9898: ret
	return;
}

void sub_2B98A0(X86Context& ctx, uint8_t* base) {
	// 0x2B98A0: movss xmm0, dword ptr [0x005A76D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76D8u);
	// 0x2B98A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B98B0: movss [0x005A76E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76E4u, ctx.xmm[0].u32[0]);
	// 0x2B98B8: ret
	return;
}

void sub_2B98C0(X86Context& ctx, uint8_t* base) {
	// 0x2B98C0: movss xmm0, dword ptr [0x005A76D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76D8u);
	// 0x2B98C8: subss xmm0, [0x005A76E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A76E4u);
	// 0x2B98D0: movss [0x005A76E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76E0u, ctx.xmm[0].u32[0]);
	// 0x2B98D8: ret
	return;
}

void sub_2B98E0(X86Context& ctx, uint8_t* base) {
	// 0x2B98E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B98E8: movss [0x005A76F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76F4u, ctx.xmm[0].u32[0]);
	// 0x2B98F0: ret
	return;
}

void sub_2B9900(X86Context& ctx, uint8_t* base) {
	// 0x2B9900: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B9908: movss [0x005A76DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76DCu, ctx.xmm[0].u32[0]);
	// 0x2B9910: ret
	return;
}

void sub_2B9920(X86Context& ctx, uint8_t* base) {
	// 0x2B9920: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9928: movss [0x005A7730], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7730u, ctx.xmm[0].u32[0]);
	// 0x2B9930: ret
	return;
}

void sub_2B9940(X86Context& ctx, uint8_t* base) {
	// 0x2B9940: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9948: movss [0x005A773C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A773Cu, ctx.xmm[0].u32[0]);
	// 0x2B9950: ret
	return;
}

void sub_2B9960(X86Context& ctx, uint8_t* base) {
	// 0x2B9960: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9968: movss [0x005A772C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A772Cu, ctx.xmm[0].u32[0]);
	// 0x2B9970: ret
	return;
}

void sub_2B9980(X86Context& ctx, uint8_t* base) {
	// 0x2B9980: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9988: movss [0x005A7714], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7714u, ctx.xmm[0].u32[0]);
	// 0x2B9990: ret
	return;
}

void sub_2B99A0(X86Context& ctx, uint8_t* base) {
	// 0x2B99A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B99A8: movss [0x005A7734], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7734u, ctx.xmm[0].u32[0]);
	// 0x2B99B0: ret
	return;
}

void sub_2B99C0(X86Context& ctx, uint8_t* base) {
	// 0x2B99C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B99C8: movss [0x005A771C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A771Cu, ctx.xmm[0].u32[0]);
	// 0x2B99D0: ret
	return;
}

void sub_2B99E0(X86Context& ctx, uint8_t* base) {
	// 0x2B99E0: movss xmm0, dword ptr [0x005A7734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7734u);
	// 0x2B99E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B99F0: movss [0x005A7744], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7744u, ctx.xmm[0].u32[0]);
	// 0x2B99F8: ret
	return;
}

void sub_2B9A00(X86Context& ctx, uint8_t* base) {
	// 0x2B9A00: movss xmm0, dword ptr [0x005A771C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A771Cu);
	// 0x2B9A08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B9A10: movss [0x005A7740], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7740u, ctx.xmm[0].u32[0]);
	// 0x2B9A18: ret
	return;
}

void sub_2B9A20(X86Context& ctx, uint8_t* base) {
	// 0x2B9A20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9A28: movss [0x005A7754], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7754u, ctx.xmm[0].u32[0]);
	// 0x2B9A30: ret
	return;
}

void sub_2B9A40(X86Context& ctx, uint8_t* base) {
	// 0x2B9A40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B9A48: movss [0x005A7748], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7748u, ctx.xmm[0].u32[0]);
	// 0x2B9A50: ret
	return;
}

void sub_2B9A60(X86Context& ctx, uint8_t* base) {
	// 0x2B9A60: movss xmm0, dword ptr [0x005A7748]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7748u);
	// 0x2B9A68: movss [0x005A7750], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7750u, ctx.xmm[0].u32[0]);
	// 0x2B9A70: ret
	return;
}

void sub_2B9A80(X86Context& ctx, uint8_t* base) {
	// 0x2B9A80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9A88: movss [0x005A7718], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7718u, ctx.xmm[0].u32[0]);
	// 0x2B9A90: ret
	return;
}

void sub_2B9AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B9AA0: movss xmm0, dword ptr [0x005A771C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A771Cu);
	// 0x2B9AA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9AB0: movss [0x005A774C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A774Cu, ctx.xmm[0].u32[0]);
	// 0x2B9AB8: ret
	return;
}

void sub_2B9AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B9AC0: movss xmm0, dword ptr [0x005A771C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A771Cu);
	// 0x2B9AC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B9AD0: movss [0x005A7728], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7728u, ctx.xmm[0].u32[0]);
	// 0x2B9AD8: ret
	return;
}

void sub_2B9AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B9AE0: movss xmm0, dword ptr [0x005A771C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A771Cu);
	// 0x2B9AE8: subss xmm0, [0x005A7728]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A7728u);
	// 0x2B9AF0: movss [0x005A7724], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7724u, ctx.xmm[0].u32[0]);
	// 0x2B9AF8: ret
	return;
}

void sub_2B9B00(X86Context& ctx, uint8_t* base) {
	// 0x2B9B00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B9B08: movss [0x005A7738], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7738u, ctx.xmm[0].u32[0]);
	// 0x2B9B10: ret
	return;
}

void sub_2B9B20(X86Context& ctx, uint8_t* base) {
	// 0x2B9B20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B9B28: movss [0x005A7720], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7720u, ctx.xmm[0].u32[0]);
	// 0x2B9B30: ret
	return;
}

void sub_2B9B40(X86Context& ctx, uint8_t* base) {
	// 0x2B9B40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9B48: movss [0x005A7F78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F78u, ctx.xmm[0].u32[0]);
	// 0x2B9B50: ret
	return;
}

void sub_2B9B60(X86Context& ctx, uint8_t* base) {
	// 0x2B9B60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9B68: movss [0x005A7F84], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F84u, ctx.xmm[0].u32[0]);
	// 0x2B9B70: ret
	return;
}

void sub_2B9B80(X86Context& ctx, uint8_t* base) {
	// 0x2B9B80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9B88: movss [0x005A7F74], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F74u, ctx.xmm[0].u32[0]);
	// 0x2B9B90: ret
	return;
}

void sub_2B9BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B9BA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9BA8: movss [0x005A7758], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7758u, ctx.xmm[0].u32[0]);
	// 0x2B9BB0: ret
	return;
}

void sub_2B9BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B9BC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B9BC8: movss [0x005A7F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F7Cu, ctx.xmm[0].u32[0]);
	// 0x2B9BD0: ret
	return;
}

void sub_2B9BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B9BE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B9BE8: movss [0x005A7760], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7760u, ctx.xmm[0].u32[0]);
	// 0x2B9BF0: ret
	return;
}

void sub_2B9C00(X86Context& ctx, uint8_t* base) {
	// 0x2B9C00: movss xmm0, dword ptr [0x005A7F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7F7Cu);
	// 0x2B9C08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B9C10: movss [0x005A7FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FA0u, ctx.xmm[0].u32[0]);
	// 0x2B9C18: ret
	return;
}

void sub_2B9C20(X86Context& ctx, uint8_t* base) {
	// 0x2B9C20: movss xmm0, dword ptr [0x005A7760]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7760u);
	// 0x2B9C28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B9C30: movss [0x005A7F88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F88u, ctx.xmm[0].u32[0]);
	// 0x2B9C38: ret
	return;
}

void sub_2B9C40(X86Context& ctx, uint8_t* base) {
	// 0x2B9C40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9C48: movss [0x005A7FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FB0u, ctx.xmm[0].u32[0]);
	// 0x2B9C50: ret
	return;
}

void sub_2B9C60(X86Context& ctx, uint8_t* base) {
	// 0x2B9C60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B9C68: movss [0x005A7FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FA4u, ctx.xmm[0].u32[0]);
	// 0x2B9C70: ret
	return;
}

void sub_2B9C80(X86Context& ctx, uint8_t* base) {
	// 0x2B9C80: movss xmm0, dword ptr [0x005A7FA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FA4u);
	// 0x2B9C88: movss [0x005A7FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FACu, ctx.xmm[0].u32[0]);
	// 0x2B9C90: ret
	return;
}

void sub_2B9CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B9CA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9CA8: movss [0x005A775C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A775Cu, ctx.xmm[0].u32[0]);
	// 0x2B9CB0: ret
	return;
}

void sub_2B9CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B9CC0: movss xmm0, dword ptr [0x005A7760]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7760u);
	// 0x2B9CC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9CD0: movss [0x005A7FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FA8u, ctx.xmm[0].u32[0]);
	// 0x2B9CD8: ret
	return;
}

void sub_2B9CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B9CE0: movss xmm0, dword ptr [0x005A7760]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7760u);
	// 0x2B9CE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B9CF0: movss [0x005A7F70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F70u, ctx.xmm[0].u32[0]);
	// 0x2B9CF8: ret
	return;
}

void sub_2B9D00(X86Context& ctx, uint8_t* base) {
	// 0x2B9D00: movss xmm0, dword ptr [0x005A7760]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7760u);
	// 0x2B9D08: subss xmm0, [0x005A7F70]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A7F70u);
	// 0x2B9D10: movss [0x005A7768], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7768u, ctx.xmm[0].u32[0]);
	// 0x2B9D18: ret
	return;
}

void sub_2B9D20(X86Context& ctx, uint8_t* base) {
	// 0x2B9D20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B9D28: movss [0x005A7F80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7F80u, ctx.xmm[0].u32[0]);
	// 0x2B9D30: ret
	return;
}

void sub_2B9D40(X86Context& ctx, uint8_t* base) {
	// 0x2B9D40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B9D48: movss [0x005A7764], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7764u, ctx.xmm[0].u32[0]);
	// 0x2B9D50: ret
	return;
}

void sub_2B9D60(X86Context& ctx, uint8_t* base) {
	// 0x2B9D60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9D68: movss [0x005A7FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FD0u, ctx.xmm[0].u32[0]);
	// 0x2B9D70: ret
	return;
}

void sub_2B9D80(X86Context& ctx, uint8_t* base) {
	// 0x2B9D80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9D88: movss [0x005A7FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FDCu, ctx.xmm[0].u32[0]);
	// 0x2B9D90: ret
	return;
}

void sub_2B9DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B9DA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9DA8: movss [0x005A7FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FCCu, ctx.xmm[0].u32[0]);
	// 0x2B9DB0: ret
	return;
}

void sub_2B9DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B9DC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9DC8: movss [0x005A7FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FB4u, ctx.xmm[0].u32[0]);
	// 0x2B9DD0: ret
	return;
}

void sub_2B9DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B9DE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B9DE8: movss [0x005A7FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FD4u, ctx.xmm[0].u32[0]);
	// 0x2B9DF0: ret
	return;
}

void sub_2B9E00(X86Context& ctx, uint8_t* base) {
	// 0x2B9E00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B9E08: movss [0x005A7FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FBCu, ctx.xmm[0].u32[0]);
	// 0x2B9E10: ret
	return;
}

void sub_2B9E20(X86Context& ctx, uint8_t* base) {
	// 0x2B9E20: movss xmm0, dword ptr [0x005A7FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FD4u);
	// 0x2B9E28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B9E30: movss [0x005A7FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FE4u, ctx.xmm[0].u32[0]);
	// 0x2B9E38: ret
	return;
}

void sub_2B9E40(X86Context& ctx, uint8_t* base) {
	// 0x2B9E40: movss xmm0, dword ptr [0x005A7FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FBCu);
	// 0x2B9E48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B9E50: movss [0x005A7FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FE0u, ctx.xmm[0].u32[0]);
	// 0x2B9E58: ret
	return;
}

void sub_2B9E60(X86Context& ctx, uint8_t* base) {
	// 0x2B9E60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9E68: movss [0x005A7FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FF4u, ctx.xmm[0].u32[0]);
	// 0x2B9E70: ret
	return;
}

void sub_2B9E80(X86Context& ctx, uint8_t* base) {
	// 0x2B9E80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B9E88: movss [0x005A7FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FE8u, ctx.xmm[0].u32[0]);
	// 0x2B9E90: ret
	return;
}

void sub_2B9EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B9EA0: movss xmm0, dword ptr [0x005A7FE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FE8u);
	// 0x2B9EA8: movss [0x005A7FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FF0u, ctx.xmm[0].u32[0]);
	// 0x2B9EB0: ret
	return;
}

void sub_2B9EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B9EC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9EC8: movss [0x005A7FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FB8u, ctx.xmm[0].u32[0]);
	// 0x2B9ED0: ret
	return;
}

void sub_2B9EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B9EE0: movss xmm0, dword ptr [0x005A7FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FBCu);
	// 0x2B9EE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9EF0: movss [0x005A7FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FECu, ctx.xmm[0].u32[0]);
	// 0x2B9EF8: ret
	return;
}

void sub_2B9F00(X86Context& ctx, uint8_t* base) {
	// 0x2B9F00: movss xmm0, dword ptr [0x005A7FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FBCu);
	// 0x2B9F08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B9F10: movss [0x005A7FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FC8u, ctx.xmm[0].u32[0]);
	// 0x2B9F18: ret
	return;
}

void sub_2B9F20(X86Context& ctx, uint8_t* base) {
	// 0x2B9F20: movss xmm0, dword ptr [0x005A7FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7FBCu);
	// 0x2B9F28: subss xmm0, [0x005A7FC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A7FC8u);
	// 0x2B9F30: movss [0x005A7FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FC4u, ctx.xmm[0].u32[0]);
	// 0x2B9F38: ret
	return;
}

void sub_2B9F40(X86Context& ctx, uint8_t* base) {
	// 0x2B9F40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B9F48: movss [0x005A7FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FD8u, ctx.xmm[0].u32[0]);
	// 0x2B9F50: ret
	return;
}

void sub_2B9F60(X86Context& ctx, uint8_t* base) {
	// 0x2B9F60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B9F68: movss [0x005A7FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FC0u, ctx.xmm[0].u32[0]);
	// 0x2B9F70: ret
	return;
}

void sub_2B9F80(X86Context& ctx, uint8_t* base) {
	// 0x2B9F80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9F88: movss [0x005A8014], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8014u, ctx.xmm[0].u32[0]);
	// 0x2B9F90: ret
	return;
}

void sub_2B9FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B9FA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9FA8: movss [0x005A8020], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8020u, ctx.xmm[0].u32[0]);
	// 0x2B9FB0: ret
	return;
}

void sub_2B9FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B9FC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9FC8: movss [0x005A8010], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8010u, ctx.xmm[0].u32[0]);
	// 0x2B9FD0: ret
	return;
}

void sub_2B9FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B9FE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9FE8: movss [0x005A7FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FF8u, ctx.xmm[0].u32[0]);
	// 0x2B9FF0: ret
	return;
}

void sub_2BA000(X86Context& ctx, uint8_t* base) {
	// 0x2BA000: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BA008: movss [0x005A8018], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8018u, ctx.xmm[0].u32[0]);
	// 0x2BA010: ret
	return;
}

void sub_2BA020(X86Context& ctx, uint8_t* base) {
	// 0x2BA020: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BA028: movss [0x005A8000], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8000u, ctx.xmm[0].u32[0]);
	// 0x2BA030: ret
	return;
}

void sub_2BA040(X86Context& ctx, uint8_t* base) {
	// 0x2BA040: movss xmm0, dword ptr [0x005A8018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8018u);
	// 0x2BA048: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BA050: movss [0x005A8028], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8028u, ctx.xmm[0].u32[0]);
	// 0x2BA058: ret
	return;
}

void sub_2BA060(X86Context& ctx, uint8_t* base) {
	// 0x2BA060: movss xmm0, dword ptr [0x005A8000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8000u);
	// 0x2BA068: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BA070: movss [0x005A8024], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8024u, ctx.xmm[0].u32[0]);
	// 0x2BA078: ret
	return;
}

void sub_2BA080(X86Context& ctx, uint8_t* base) {
	// 0x2BA080: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA088: movss [0x005A8038], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8038u, ctx.xmm[0].u32[0]);
	// 0x2BA090: ret
	return;
}

void sub_2BA0A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA0A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BA0A8: movss [0x005A802C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A802Cu, ctx.xmm[0].u32[0]);
	// 0x2BA0B0: ret
	return;
}

void sub_2BA0C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA0C0: movss xmm0, dword ptr [0x005A802C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A802Cu);
	// 0x2BA0C8: movss [0x005A8034], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8034u, ctx.xmm[0].u32[0]);
	// 0x2BA0D0: ret
	return;
}

void sub_2BA0E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA0E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA0E8: movss [0x005A7FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7FFCu, ctx.xmm[0].u32[0]);
	// 0x2BA0F0: ret
	return;
}

void sub_2BA100(X86Context& ctx, uint8_t* base) {
	// 0x2BA100: movss xmm0, dword ptr [0x005A8000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8000u);
	// 0x2BA108: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BA110: movss [0x005A8030], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8030u, ctx.xmm[0].u32[0]);
	// 0x2BA118: ret
	return;
}

void sub_2BA120(X86Context& ctx, uint8_t* base) {
	// 0x2BA120: movss xmm0, dword ptr [0x005A8000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8000u);
	// 0x2BA128: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BA130: movss [0x005A800C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A800Cu, ctx.xmm[0].u32[0]);
	// 0x2BA138: ret
	return;
}

void sub_2BA140(X86Context& ctx, uint8_t* base) {
	// 0x2BA140: movss xmm0, dword ptr [0x005A8000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8000u);
	// 0x2BA148: subss xmm0, [0x005A800C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A800Cu);
	// 0x2BA150: movss [0x005A8008], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8008u, ctx.xmm[0].u32[0]);
	// 0x2BA158: ret
	return;
}

void sub_2BA160(X86Context& ctx, uint8_t* base) {
	// 0x2BA160: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BA168: movss [0x005A801C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A801Cu, ctx.xmm[0].u32[0]);
	// 0x2BA170: ret
	return;
}

void sub_2BA180(X86Context& ctx, uint8_t* base) {
	// 0x2BA180: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BA188: movss [0x005A8004], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8004u, ctx.xmm[0].u32[0]);
	// 0x2BA190: ret
	return;
}

void sub_2BA1A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA1A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BA1A8: movss [0x005A805C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A805Cu, ctx.xmm[0].u32[0]);
	// 0x2BA1B0: ret
	return;
}

void sub_2BA1C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA1C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BA1C8: movss [0x005A8068], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8068u, ctx.xmm[0].u32[0]);
	// 0x2BA1D0: ret
	return;
}

void sub_2BA1E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA1E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BA1E8: movss [0x005A8058], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8058u, ctx.xmm[0].u32[0]);
	// 0x2BA1F0: ret
	return;
}

void sub_2BA200(X86Context& ctx, uint8_t* base) {
	// 0x2BA200: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BA208: movss [0x005A803C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A803Cu, ctx.xmm[0].u32[0]);
	// 0x2BA210: ret
	return;
}

void sub_2BA220(X86Context& ctx, uint8_t* base) {
	// 0x2BA220: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BA228: movss [0x005A8060], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8060u, ctx.xmm[0].u32[0]);
	// 0x2BA230: ret
	return;
}

void sub_2BA240(X86Context& ctx, uint8_t* base) {
	// 0x2BA240: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BA248: movss [0x005A8044], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8044u, ctx.xmm[0].u32[0]);
	// 0x2BA250: ret
	return;
}

void sub_2BA260(X86Context& ctx, uint8_t* base) {
	// 0x2BA260: movss xmm0, dword ptr [0x005A8060]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8060u);
	// 0x2BA268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BA270: movss [0x005A8074], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8074u, ctx.xmm[0].u32[0]);
	// 0x2BA278: ret
	return;
}

void sub_2BA280(X86Context& ctx, uint8_t* base) {
	// 0x2BA280: movss xmm0, dword ptr [0x005A8044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8044u);
	// 0x2BA288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BA290: movss [0x005A806C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A806Cu, ctx.xmm[0].u32[0]);
	// 0x2BA298: ret
	return;
}

void sub_2BA2A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA2A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA2A8: movss [0x005A8084], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8084u, ctx.xmm[0].u32[0]);
	// 0x2BA2B0: ret
	return;
}

void sub_2BA2C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA2C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BA2C8: movss [0x005A8078], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8078u, ctx.xmm[0].u32[0]);
	// 0x2BA2D0: ret
	return;
}

void sub_2BA2E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA2E0: movss xmm0, dword ptr [0x005A8078]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8078u);
	// 0x2BA2E8: movss [0x005A8080], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8080u, ctx.xmm[0].u32[0]);
	// 0x2BA2F0: ret
	return;
}

void sub_2BA300(X86Context& ctx, uint8_t* base) {
	// 0x2BA300: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA308: movss [0x005A8040], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8040u, ctx.xmm[0].u32[0]);
	// 0x2BA310: ret
	return;
}

void sub_2BA320(X86Context& ctx, uint8_t* base) {
	// 0x2BA320: movss xmm0, dword ptr [0x005A8044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8044u);
	// 0x2BA328: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BA330: movss [0x005A807C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A807Cu, ctx.xmm[0].u32[0]);
	// 0x2BA338: ret
	return;
}

void sub_2BA340(X86Context& ctx, uint8_t* base) {
	// 0x2BA340: movss xmm0, dword ptr [0x005A8044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8044u);
	// 0x2BA348: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BA350: movss [0x005A8050], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8050u, ctx.xmm[0].u32[0]);
	// 0x2BA358: ret
	return;
}

void sub_2BA360(X86Context& ctx, uint8_t* base) {
	// 0x2BA360: movss xmm0, dword ptr [0x005A8044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8044u);
	// 0x2BA368: subss xmm0, [0x005A8050]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8050u);
	// 0x2BA370: movss [0x005A804C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A804Cu, ctx.xmm[0].u32[0]);
	// 0x2BA378: ret
	return;
}

void sub_2BA380(X86Context& ctx, uint8_t* base) {
	// 0x2BA380: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BA388: movss [0x005A8064], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8064u, ctx.xmm[0].u32[0]);
	// 0x2BA390: ret
	return;
}

void sub_2BA3A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA3A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BA3A8: movss [0x005A8048], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8048u, ctx.xmm[0].u32[0]);
	// 0x2BA3B0: ret
	return;
}

void sub_2BA3C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA3C0: movss xmm0, dword ptr [0x003B2338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2338u);
	// 0x2BA3C8: movss [0x005A8054], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8054u, ctx.xmm[0].u32[0]);
	// 0x2BA3D0: ret
	return;
}

void sub_2BA3E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA3E0: movss xmm0, dword ptr [0x003B1E3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1E3Cu);
	// 0x2BA3E8: movss [0x005A8070], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8070u, ctx.xmm[0].u32[0]);
	// 0x2BA3F0: ret
	return;
}

void sub_2BA400(X86Context& ctx, uint8_t* base) {
	// 0x2BA400: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BA408: movss [0x005A8090], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8090u, ctx.xmm[0].u32[0]);
	// 0x2BA410: ret
	return;
}

void sub_2BA420(X86Context& ctx, uint8_t* base) {
	// 0x2BA420: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BA428: movss [0x005A8098], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8098u, ctx.xmm[0].u32[0]);
	// 0x2BA430: ret
	return;
}

void sub_2BA440(X86Context& ctx, uint8_t* base) {
	// 0x2BA440: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BA448: movss [0x005A808C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A808Cu, ctx.xmm[0].u32[0]);
	// 0x2BA450: ret
	return;
}

void sub_2BA460(X86Context& ctx, uint8_t* base) {
	// 0x2BA460: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BA468: movss [0x005A8088], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8088u, ctx.xmm[0].u32[0]);
	// 0x2BA470: ret
	return;
}

void sub_2BA480(X86Context& ctx, uint8_t* base) {
	// 0x2BA480: movss xmm0, dword ptr [0x003B233C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B233Cu);
	// 0x2BA488: movss [0x005A8094], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8094u, ctx.xmm[0].u32[0]);
	// 0x2BA490: ret
	return;
}

void sub_2BA4A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA4A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BA4A8: movss [0x005A80A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80A8u, ctx.xmm[0].u32[0]);
	// 0x2BA4B0: ret
	return;
}

void sub_2BA4C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA4C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BA4C8: movss [0x005A80B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80B0u, ctx.xmm[0].u32[0]);
	// 0x2BA4D0: ret
	return;
}

void sub_2BA4E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA4E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BA4E8: movss [0x005A80A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80A4u, ctx.xmm[0].u32[0]);
	// 0x2BA4F0: ret
	return;
}

void sub_2BA500(X86Context& ctx, uint8_t* base) {
	// 0x2BA500: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BA508: movss [0x005A809C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A809Cu, ctx.xmm[0].u32[0]);
	// 0x2BA510: ret
	return;
}

void sub_2BA520(X86Context& ctx, uint8_t* base) {
	// 0x2BA520: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BA528: movss [0x005A80AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80ACu, ctx.xmm[0].u32[0]);
	// 0x2BA530: ret
	return;
}

void sub_2BA540(X86Context& ctx, uint8_t* base) {
	// 0x2BA540: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BA548: movss [0x005A80A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80A0u, ctx.xmm[0].u32[0]);
	// 0x2BA550: ret
	return;
}

void sub_2BA560(X86Context& ctx, uint8_t* base) {
	// 0x2BA560: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BA568: movss [0x005A80DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80DCu, ctx.xmm[0].u32[0]);
	// 0x2BA570: ret
	return;
}

void sub_2BA580(X86Context& ctx, uint8_t* base) {
	// 0x2BA580: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BA588: movss [0x005A80E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80E8u, ctx.xmm[0].u32[0]);
	// 0x2BA590: ret
	return;
}

void sub_2BA5A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA5A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BA5A8: movss [0x005A80D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80D4u, ctx.xmm[0].u32[0]);
	// 0x2BA5B0: ret
	return;
}

void sub_2BA5C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA5C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BA5C8: movss [0x005A80B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80B4u, ctx.xmm[0].u32[0]);
	// 0x2BA5D0: ret
	return;
}

void sub_2BA5E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA5E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BA5E8: movss [0x005A80E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80E0u, ctx.xmm[0].u32[0]);
	// 0x2BA5F0: ret
	return;
}

void sub_2BA600(X86Context& ctx, uint8_t* base) {
	// 0x2BA600: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BA608: movss [0x005A80BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80BCu, ctx.xmm[0].u32[0]);
	// 0x2BA610: ret
	return;
}

void sub_2BA620(X86Context& ctx, uint8_t* base) {
	// 0x2BA620: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BA628: movss [0x005A80F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80F0u, ctx.xmm[0].u32[0]);
	// 0x2BA630: ret
	return;
}

void sub_2BA640(X86Context& ctx, uint8_t* base) {
	// 0x2BA640: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BA648: movss [0x005A80D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80D8u, ctx.xmm[0].u32[0]);
	// 0x2BA650: ret
	return;
}

void sub_2BA660(X86Context& ctx, uint8_t* base) {
	// 0x2BA660: movss xmm0, dword ptr [0x005A80F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A80F0u);
	// 0x2BA668: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BA670: movss [0x005A80C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80C4u, ctx.xmm[0].u32[0]);
	// 0x2BA678: ret
	return;
}

void sub_2BA680(X86Context& ctx, uint8_t* base) {
	// 0x2BA680: movss xmm0, dword ptr [0x005A80D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A80D8u);
	// 0x2BA688: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BA690: movss [0x005A80EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80ECu, ctx.xmm[0].u32[0]);
	// 0x2BA698: ret
	return;
}

void sub_2BA6A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA6A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA6A8: movss [0x005A80FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80FCu, ctx.xmm[0].u32[0]);
	// 0x2BA6B0: ret
	return;
}

void sub_2BA6C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA6C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BA6C8: movss [0x005A80F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80F4u, ctx.xmm[0].u32[0]);
	// 0x2BA6D0: ret
	return;
}

void sub_2BA6E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA6E0: movss xmm0, dword ptr [0x005A80F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A80F4u);
	// 0x2BA6E8: movss [0x005A80F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80F8u, ctx.xmm[0].u32[0]);
	// 0x2BA6F0: ret
	return;
}

void sub_2BA700(X86Context& ctx, uint8_t* base) {
	// 0x2BA700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA708: movss [0x005A80D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80D0u, ctx.xmm[0].u32[0]);
	// 0x2BA710: ret
	return;
}

void sub_2BA720(X86Context& ctx, uint8_t* base) {
	// 0x2BA720: movss xmm0, dword ptr [0x005A80D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A80D8u);
	// 0x2BA728: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BA730: movss [0x005A80CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80CCu, ctx.xmm[0].u32[0]);
	// 0x2BA738: ret
	return;
}

void sub_2BA740(X86Context& ctx, uint8_t* base) {
	// 0x2BA740: movss xmm0, dword ptr [0x005A80D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A80D8u);
	// 0x2BA748: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BA750: movss [0x005A80E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80E4u, ctx.xmm[0].u32[0]);
	// 0x2BA758: ret
	return;
}

void sub_2BA760(X86Context& ctx, uint8_t* base) {
	// 0x2BA760: movss xmm0, dword ptr [0x005A80D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A80D8u);
	// 0x2BA768: subss xmm0, [0x005A80E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A80E4u);
	// 0x2BA770: movss [0x005A80C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80C0u, ctx.xmm[0].u32[0]);
	// 0x2BA778: ret
	return;
}

void sub_2BA780(X86Context& ctx, uint8_t* base) {
	// 0x2BA780: movss xmm0, dword ptr [0x003B1A24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A24u);
	// 0x2BA788: movss [0x005A80C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80C8u, ctx.xmm[0].u32[0]);
	// 0x2BA790: ret
	return;
}

void sub_2BA7A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA7A0: movss xmm0, dword ptr [0x003B1730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2BA7A8: movss [0x005A80B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A80B8u, ctx.xmm[0].u32[0]);
	// 0x2BA7B0: ret
	return;
}

void sub_2BA7C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA7C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BA7C8: movss [0x005A8100], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8100u, ctx.xmm[0].u32[0]);
	// 0x2BA7D0: ret
	return;
}

void sub_2BA7E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA7E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BA7E8: movss [0x005A8290], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8290u, ctx.xmm[0].u32[0]);
	// 0x2BA7F0: ret
	return;
}

void sub_2BA800(X86Context& ctx, uint8_t* base) {
	// 0x2BA800: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BA808: movss [0x005A829C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A829Cu, ctx.xmm[0].u32[0]);
	// 0x2BA810: ret
	return;
}

void sub_2BA820(X86Context& ctx, uint8_t* base) {
	// 0x2BA820: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BA828: movss [0x005A828C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A828Cu, ctx.xmm[0].u32[0]);
	// 0x2BA830: ret
	return;
}

void sub_2BA840(X86Context& ctx, uint8_t* base) {
	// 0x2BA840: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BA848: movss [0x005A8104], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8104u, ctx.xmm[0].u32[0]);
	// 0x2BA850: ret
	return;
}

void sub_2BA860(X86Context& ctx, uint8_t* base) {
	// 0x2BA860: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BA868: movss [0x005A8294], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8294u, ctx.xmm[0].u32[0]);
	// 0x2BA870: ret
	return;
}

void sub_2BA880(X86Context& ctx, uint8_t* base) {
	// 0x2BA880: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BA888: movss [0x005A810C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A810Cu, ctx.xmm[0].u32[0]);
	// 0x2BA890: ret
	return;
}

void sub_2BA8A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA8A0: movss xmm0, dword ptr [0x005A8294]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8294u);
	// 0x2BA8A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BA8B0: movss [0x005A82A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82A8u, ctx.xmm[0].u32[0]);
	// 0x2BA8B8: ret
	return;
}

void sub_2BA8C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA8C0: movss xmm0, dword ptr [0x005A810C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A810Cu);
	// 0x2BA8C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BA8D0: movss [0x005A82A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82A0u, ctx.xmm[0].u32[0]);
	// 0x2BA8D8: ret
	return;
}

void sub_2BA8E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA8E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA8E8: movss [0x005A82B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82B8u, ctx.xmm[0].u32[0]);
	// 0x2BA8F0: ret
	return;
}

void sub_2BA900(X86Context& ctx, uint8_t* base) {
	// 0x2BA900: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BA908: movss [0x005A82AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82ACu, ctx.xmm[0].u32[0]);
	// 0x2BA910: ret
	return;
}

void sub_2BA920(X86Context& ctx, uint8_t* base) {
	// 0x2BA920: movss xmm0, dword ptr [0x005A82AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A82ACu);
	// 0x2BA928: movss [0x005A82B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82B4u, ctx.xmm[0].u32[0]);
	// 0x2BA930: ret
	return;
}

void sub_2BA940(X86Context& ctx, uint8_t* base) {
	// 0x2BA940: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BA948: movss [0x005A8108], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8108u, ctx.xmm[0].u32[0]);
	// 0x2BA950: ret
	return;
}

void sub_2BA960(X86Context& ctx, uint8_t* base) {
	// 0x2BA960: movss xmm0, dword ptr [0x005A810C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A810Cu);
	// 0x2BA968: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BA970: movss [0x005A82B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82B0u, ctx.xmm[0].u32[0]);
	// 0x2BA978: ret
	return;
}

void sub_2BA980(X86Context& ctx, uint8_t* base) {
	// 0x2BA980: movss xmm0, dword ptr [0x005A810C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A810Cu);
	// 0x2BA988: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BA990: movss [0x005A8288], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8288u, ctx.xmm[0].u32[0]);
	// 0x2BA998: ret
	return;
}

void sub_2BA9A0(X86Context& ctx, uint8_t* base) {
	// 0x2BA9A0: movss xmm0, dword ptr [0x005A810C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A810Cu);
	// 0x2BA9A8: subss xmm0, [0x005A8288]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8288u);
	// 0x2BA9B0: movss [0x005A8280], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8280u, ctx.xmm[0].u32[0]);
	// 0x2BA9B8: ret
	return;
}

void sub_2BA9C0(X86Context& ctx, uint8_t* base) {
	// 0x2BA9C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BA9C8: movss [0x005A8298], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8298u, ctx.xmm[0].u32[0]);
	// 0x2BA9D0: ret
	return;
}

void sub_2BA9E0(X86Context& ctx, uint8_t* base) {
	// 0x2BA9E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BA9E8: movss [0x005A8110], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8110u, ctx.xmm[0].u32[0]);
	// 0x2BA9F0: ret
	return;
}

void sub_2BAA00(X86Context& ctx, uint8_t* base) {
	// 0x2BAA00: movss xmm0, dword ptr [0x003A69BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A69BCu);
	// 0x2BAA08: movss [0x005A8284], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8284u, ctx.xmm[0].u32[0]);
	// 0x2BAA10: ret
	return;
}

void sub_2BAA20(X86Context& ctx, uint8_t* base) {
	// 0x2BAA20: movss xmm0, dword ptr [0x003B2340]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2340u);
	// 0x2BAA28: movss [0x005A82A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82A4u, ctx.xmm[0].u32[0]);
	// 0x2BAA30: ret
	return;
}

void sub_2BAA40(X86Context& ctx, uint8_t* base) {
	// 0x2BAA40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BAA48: movss [0x005A82C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82C0u, ctx.xmm[0].u32[0]);
	// 0x2BAA50: ret
	return;
}

void sub_2BAA60(X86Context& ctx, uint8_t* base) {
	// 0x2BAA60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BAA68: movss [0x005A82C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82C4u, ctx.xmm[0].u32[0]);
	// 0x2BAA70: ret
	return;
}

void sub_2BAA80(X86Context& ctx, uint8_t* base) {
	// 0x2BAA80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BAA88: movss [0x005A82BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82BCu, ctx.xmm[0].u32[0]);
	// 0x2BAA90: ret
	return;
}

void sub_2BAAA0(X86Context& ctx, uint8_t* base) {
	// 0x2BAAA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BAAA8: movss [0x005A82D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82D0u, ctx.xmm[0].u32[0]);
	// 0x2BAAB0: ret
	return;
}

void sub_2BAAC0(X86Context& ctx, uint8_t* base) {
	// 0x2BAAC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BAAC8: movss [0x005A82D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82D4u, ctx.xmm[0].u32[0]);
	// 0x2BAAD0: ret
	return;
}

void sub_2BAAE0(X86Context& ctx, uint8_t* base) {
	// 0x2BAAE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BAAE8: movss [0x005A82CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82CCu, ctx.xmm[0].u32[0]);
	// 0x2BAAF0: ret
	return;
}

void sub_2BAB00(X86Context& ctx, uint8_t* base) {
	// 0x2BAB00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BAB08: movss [0x005A82C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82C8u, ctx.xmm[0].u32[0]);
	// 0x2BAB10: ret
	return;
}

void sub_2BAB20(X86Context& ctx, uint8_t* base) {
	// 0x2BAB20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BAB28: movss [0x005A82E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82E0u, ctx.xmm[0].u32[0]);
	// 0x2BAB30: ret
	return;
}

void sub_2BAB40(X86Context& ctx, uint8_t* base) {
	// 0x2BAB40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BAB48: movss [0x005A82E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82E4u, ctx.xmm[0].u32[0]);
	// 0x2BAB50: ret
	return;
}

void sub_2BAB60(X86Context& ctx, uint8_t* base) {
	// 0x2BAB60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BAB68: movss [0x005A82DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82DCu, ctx.xmm[0].u32[0]);
	// 0x2BAB70: ret
	return;
}

void sub_2BAB80(X86Context& ctx, uint8_t* base) {
	// 0x2BAB80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BAB88: movss [0x005A82D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82D8u, ctx.xmm[0].u32[0]);
	// 0x2BAB90: ret
	return;
}

void sub_2BABA0(X86Context& ctx, uint8_t* base) {
	// 0x2BABA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BABA8: movss [0x005A82EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82ECu, ctx.xmm[0].u32[0]);
	// 0x2BABB0: ret
	return;
}

void sub_2BABC0(X86Context& ctx, uint8_t* base) {
	// 0x2BABC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BABC8: movss [0x005A82F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82F0u, ctx.xmm[0].u32[0]);
	// 0x2BABD0: ret
	return;
}

void sub_2BABE0(X86Context& ctx, uint8_t* base) {
	// 0x2BABE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BABE8: movss [0x005A82E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82E8u, ctx.xmm[0].u32[0]);
	// 0x2BABF0: ret
	return;
}

void sub_2BAC00(X86Context& ctx, uint8_t* base) {
	// 0x2BAC00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BAC08: movss [0x005A8348], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8348u, ctx.xmm[0].u32[0]);
	// 0x2BAC10: ret
	return;
}

void sub_2BAC20(X86Context& ctx, uint8_t* base) {
	// 0x2BAC20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BAC28: movss [0x005A8364], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8364u, ctx.xmm[0].u32[0]);
	// 0x2BAC30: ret
	return;
}

void sub_2BAC40(X86Context& ctx, uint8_t* base) {
	// 0x2BAC40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BAC48: movss [0x005A833C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A833Cu, ctx.xmm[0].u32[0]);
	// 0x2BAC50: ret
	return;
}

void sub_2BAC60(X86Context& ctx, uint8_t* base) {
	// 0x2BAC60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BAC68: movss [0x005A82F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82F4u, ctx.xmm[0].u32[0]);
	// 0x2BAC70: ret
	return;
}

void sub_2BAC80(X86Context& ctx, uint8_t* base) {
	// 0x2BAC80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BAC88: movss [0x005A834C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A834Cu, ctx.xmm[0].u32[0]);
	// 0x2BAC90: ret
	return;
}

void sub_2BACA0(X86Context& ctx, uint8_t* base) {
	// 0x2BACA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BACA8: movss [0x005A8310], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8310u, ctx.xmm[0].u32[0]);
	// 0x2BACB0: ret
	return;
}

void sub_2BACC0(X86Context& ctx, uint8_t* base) {
	// 0x2BACC0: movss xmm0, dword ptr [0x005A834C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A834Cu);
	// 0x2BACC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BACD0: movss [0x005A8384], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8384u, ctx.xmm[0].u32[0]);
	// 0x2BACD8: ret
	return;
}

void sub_2BACE0(X86Context& ctx, uint8_t* base) {
	// 0x2BACE0: movss xmm0, dword ptr [0x005A8310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8310u);
	// 0x2BACE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BACF0: movss [0x005A836C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A836Cu, ctx.xmm[0].u32[0]);
	// 0x2BACF8: ret
	return;
}

void sub_2BAD00(X86Context& ctx, uint8_t* base) {
	// 0x2BAD00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BAD08: movss [0x005A839C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A839Cu, ctx.xmm[0].u32[0]);
	// 0x2BAD10: ret
	return;
}

void sub_2BAD20(X86Context& ctx, uint8_t* base) {
	// 0x2BAD20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BAD28: movss [0x005A8388], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8388u, ctx.xmm[0].u32[0]);
	// 0x2BAD30: ret
	return;
}

void sub_2BAD40(X86Context& ctx, uint8_t* base) {
	// 0x2BAD40: movss xmm0, dword ptr [0x005A8388]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8388u);
	// 0x2BAD48: movss [0x005A8398], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8398u, ctx.xmm[0].u32[0]);
	// 0x2BAD50: ret
	return;
}

void sub_2BAD60(X86Context& ctx, uint8_t* base) {
	// 0x2BAD60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BAD68: movss [0x005A82FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82FCu, ctx.xmm[0].u32[0]);
	// 0x2BAD70: ret
	return;
}

void sub_2BAD80(X86Context& ctx, uint8_t* base) {
	// 0x2BAD80: movss xmm0, dword ptr [0x005A8310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8310u);
	// 0x2BAD88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BAD90: movss [0x005A8390], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8390u, ctx.xmm[0].u32[0]);
	// 0x2BAD98: ret
	return;
}

void sub_2BADA0(X86Context& ctx, uint8_t* base) {
	// 0x2BADA0: movss xmm0, dword ptr [0x005A8310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8310u);
	// 0x2BADA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BADB0: movss [0x005A8338], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8338u, ctx.xmm[0].u32[0]);
	// 0x2BADB8: ret
	return;
}

void sub_2BADC0(X86Context& ctx, uint8_t* base) {
	// 0x2BADC0: movss xmm0, dword ptr [0x005A8310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8310u);
	// 0x2BADC8: subss xmm0, [0x005A8338]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8338u);
	// 0x2BADD0: movss [0x005A8318], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8318u, ctx.xmm[0].u32[0]);
	// 0x2BADD8: ret
	return;
}

void sub_2BADE0(X86Context& ctx, uint8_t* base) {
	// 0x2BADE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BADE8: movss [0x005A8360], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8360u, ctx.xmm[0].u32[0]);
	// 0x2BADF0: ret
	return;
}

void sub_2BAE00(X86Context& ctx, uint8_t* base) {
	// 0x2BAE00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BAE08: movss [0x005A8314], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8314u, ctx.xmm[0].u32[0]);
	// 0x2BAE10: ret
	return;
}

void sub_2BAE20(X86Context& ctx, uint8_t* base) {
	// 0x2BAE20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BAE28: movss [0x005A8324], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8324u, ctx.xmm[0].u32[0]);
	// 0x2BAE30: ret
	return;
}

void sub_2BAE40(X86Context& ctx, uint8_t* base) {
	// 0x2BAE40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BAE48: movss [0x005A8378], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8378u, ctx.xmm[0].u32[0]);
	// 0x2BAE50: ret
	return;
}

void sub_2BAE60(X86Context& ctx, uint8_t* base) {
	// 0x2BAE60: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2BAE68: movss [0x005A835C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A835Cu, ctx.xmm[0].u32[0]);
	// 0x2BAE70: ret
	return;
}

void sub_2BAE80(X86Context& ctx, uint8_t* base) {
	// 0x2BAE80: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2BAE88: movss [0x005A830C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A830Cu, ctx.xmm[0].u32[0]);
	// 0x2BAE90: ret
	return;
}

void sub_2BAEA0(X86Context& ctx, uint8_t* base) {
	// 0x2BAEA0: movss xmm0, dword ptr [0x005A8324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8324u);
	// 0x2BAEA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BAEB0: movss [0x005A8300], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8300u, ctx.xmm[0].u32[0]);
	// 0x2BAEB8: ret
	return;
}

void sub_2BAEC0(X86Context& ctx, uint8_t* base) {
	// 0x2BAEC0: movss xmm0, dword ptr [0x005A8378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8378u);
	// 0x2BAEC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BAED0: movss [0x005A8344], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8344u, ctx.xmm[0].u32[0]);
	// 0x2BAED8: ret
	return;
}

void sub_2BAEE0(X86Context& ctx, uint8_t* base) {
	// 0x2BAEE0: movss xmm0, dword ptr [0x005A8300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8300u);
	// 0x2BAEE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BAEF0: movss [0x005A8354], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8354u, ctx.xmm[0].u32[0]);
	// 0x2BAEF8: ret
	return;
}

void sub_2BAF00(X86Context& ctx, uint8_t* base) {
	// 0x2BAF00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2BAF08: movss [0x005A82F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A82F8u, ctx.xmm[0].u32[0]);
	// 0x2BAF10: ret
	return;
}

void sub_2BAF20(X86Context& ctx, uint8_t* base) {
	// 0x2BAF20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2BAF28: movss [0x005A8328], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8328u, ctx.xmm[0].u32[0]);
	// 0x2BAF30: ret
	return;
}

void sub_2BAF40(X86Context& ctx, uint8_t* base) {
	// 0x2BAF40: movss xmm0, dword ptr [0x005A8324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8324u);
	// 0x2BAF48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2BAF50: movss [0x005A8334], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8334u, ctx.xmm[0].u32[0]);
	// 0x2BAF58: ret
	return;
}

void sub_2BAF60(X86Context& ctx, uint8_t* base) {
	// 0x2BAF60: movss xmm0, dword ptr [0x005A8378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8378u);
	// 0x2BAF68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2BAF70: movss [0x005A837C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A837Cu, ctx.xmm[0].u32[0]);
	// 0x2BAF78: ret
	return;
}

void sub_2BAF80(X86Context& ctx, uint8_t* base) {
	// 0x2BAF80: movss xmm0, dword ptr [0x005A8334]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8334u);
	// 0x2BAF88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BAF90: movss [0x005A8368], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8368u, ctx.xmm[0].u32[0]);
	// 0x2BAF98: ret
	return;
}

void sub_2BAFA0(X86Context& ctx, uint8_t* base) {
	// 0x2BAFA0: movss xmm0, dword ptr [0x005A837C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A837Cu);
	// 0x2BAFA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BAFB0: movss [0x005A838C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A838Cu, ctx.xmm[0].u32[0]);
	// 0x2BAFB8: ret
	return;
}

void sub_2BAFC0(X86Context& ctx, uint8_t* base) {
	// 0x2BAFC0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2BAFC8: movss [0x005A8304], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8304u, ctx.xmm[0].u32[0]);
	// 0x2BAFD0: ret
	return;
}

void sub_2BAFE0(X86Context& ctx, uint8_t* base) {
	// 0x2BAFE0: movss xmm0, dword ptr [0x005A8324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8324u);
	// 0x2BAFE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BAFF0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2BAFF8: movss [0x005A8374], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8374u, ctx.xmm[0].u32[0]);
	// 0x2BB000: ret
	return;
}

void sub_2BB010(X86Context& ctx, uint8_t* base) {
	// 0x2BB010: movss xmm0, dword ptr [0x005A8378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8378u);
	// 0x2BB018: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BB020: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2BB028: movss [0x005A831C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A831Cu, ctx.xmm[0].u32[0]);
	// 0x2BB030: ret
	return;
}

void sub_2BB040(X86Context& ctx, uint8_t* base) {
	// 0x2BB040: movss xmm0, dword ptr [0x005A8324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8324u);
	// 0x2BB048: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BB050: movss [0x005A8320], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8320u, ctx.xmm[0].u32[0]);
	// 0x2BB058: ret
	return;
}

void sub_2BB060(X86Context& ctx, uint8_t* base) {
	// 0x2BB060: movss xmm0, dword ptr [0x005A8378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8378u);
	// 0x2BB068: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BB070: movss [0x005A8380], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8380u, ctx.xmm[0].u32[0]);
	// 0x2BB078: ret
	return;
}

void sub_2BB080(X86Context& ctx, uint8_t* base) {
	// 0x2BB080: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2BB088: movss [0x005A8308], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8308u, ctx.xmm[0].u32[0]);
	// 0x2BB090: ret
	return;
}

void sub_2BB0A0(X86Context& ctx, uint8_t* base) {
	// 0x2BB0A0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2BB0A8: movss [0x005A8330], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8330u, ctx.xmm[0].u32[0]);
	// 0x2BB0B0: ret
	return;
}

void sub_2BB0C0(X86Context& ctx, uint8_t* base) {
	// 0x2BB0C0: movss xmm0, dword ptr [0x005A8308]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8308u);
	// 0x2BB0C8: movss [0x005A8394], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8394u, ctx.xmm[0].u32[0]);
	// 0x2BB0D0: ret
	return;
}

void sub_2BB0E0(X86Context& ctx, uint8_t* base) {
	// 0x2BB0E0: movss xmm0, dword ptr [0x005A8378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8378u);
	// 0x2BB0E8: subss xmm0, [0x005A8308]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8308u);
	// 0x2BB0F0: movss [0x005A8358], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8358u, ctx.xmm[0].u32[0]);
	// 0x2BB0F8: ret
	return;
}

void sub_2BB100(X86Context& ctx, uint8_t* base) {
	// 0x2BB100: movss xmm0, dword ptr [0x005A8358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8358u);
	// 0x2BB108: subss xmm0, [0x005A8330]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8330u);
	// 0x2BB110: movss [0x005A8350], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8350u, ctx.xmm[0].u32[0]);
	// 0x2BB118: ret
	return;
}

void sub_2BB120(X86Context& ctx, uint8_t* base) {
	// 0x2BB120: movss xmm0, dword ptr [0x005A8380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8380u);
	// 0x2BB128: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2BB130: movss [0x005A8340], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8340u, ctx.xmm[0].u32[0]);
	// 0x2BB138: ret
	return;
}

void sub_2BB140(X86Context& ctx, uint8_t* base) {
	// 0x2BB140: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2BB148: movss [0x005A832C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A832Cu, ctx.xmm[0].u32[0]);
	// 0x2BB150: ret
	return;
}

void sub_2BB160(X86Context& ctx, uint8_t* base) {
	// 0x2BB160: movss xmm0, dword ptr [0x005A8340]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8340u);
	// 0x2BB168: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2BB170: movss [0x005A8370], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8370u, ctx.xmm[0].u32[0]);
	// 0x2BB178: ret
	return;
}

void sub_2BB180(X86Context& ctx, uint8_t* base) {
	// 0x2BB180: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2BB181: mov esi, 0x40E120
	ctx.esi = 4251936;
	// 0x2BB186: call 0x00134F80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_134F80(ctx, base);
	ctx.esp += 4;
	// 0x2BB18B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2BB18C: ret
	return;
}

void sub_2BB190(X86Context& ctx, uint8_t* base) {
	// 0x2BB190: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BB198: movss [0x005A83A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83A4u, ctx.xmm[0].u32[0]);
	// 0x2BB1A0: ret
	return;
}

void sub_2BB1B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB1B0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BB1B8: movss [0x005A83A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83A8u, ctx.xmm[0].u32[0]);
	// 0x2BB1C0: ret
	return;
}

void sub_2BB1D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB1D0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BB1D8: movss [0x005A83A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83A0u, ctx.xmm[0].u32[0]);
	// 0x2BB1E0: ret
	return;
}

void sub_2BB1F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB1F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BB1F8: movss [0x005A83C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83C8u, ctx.xmm[0].u32[0]);
	// 0x2BB200: ret
	return;
}

void sub_2BB210(X86Context& ctx, uint8_t* base) {
	// 0x2BB210: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BB218: movss [0x005A83D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83D4u, ctx.xmm[0].u32[0]);
	// 0x2BB220: ret
	return;
}

void sub_2BB230(X86Context& ctx, uint8_t* base) {
	// 0x2BB230: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BB238: movss [0x005A83C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83C4u, ctx.xmm[0].u32[0]);
	// 0x2BB240: ret
	return;
}

void sub_2BB250(X86Context& ctx, uint8_t* base) {
	// 0x2BB250: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BB258: movss [0x005A83AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83ACu, ctx.xmm[0].u32[0]);
	// 0x2BB260: ret
	return;
}

void sub_2BB270(X86Context& ctx, uint8_t* base) {
	// 0x2BB270: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BB278: movss [0x005A83CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83CCu, ctx.xmm[0].u32[0]);
	// 0x2BB280: ret
	return;
}

void sub_2BB290(X86Context& ctx, uint8_t* base) {
	// 0x2BB290: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BB298: movss [0x005A83B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83B4u, ctx.xmm[0].u32[0]);
	// 0x2BB2A0: ret
	return;
}

void sub_2BB2B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB2B0: movss xmm0, dword ptr [0x005A83CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A83CCu);
	// 0x2BB2B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BB2C0: movss [0x005A83DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83DCu, ctx.xmm[0].u32[0]);
	// 0x2BB2C8: ret
	return;
}

void sub_2BB2D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB2D0: movss xmm0, dword ptr [0x005A83B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A83B4u);
	// 0x2BB2D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BB2E0: movss [0x005A83D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83D8u, ctx.xmm[0].u32[0]);
	// 0x2BB2E8: ret
	return;
}

void sub_2BB2F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB2F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB2F8: movss [0x005A83EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83ECu, ctx.xmm[0].u32[0]);
	// 0x2BB300: ret
	return;
}

void sub_2BB310(X86Context& ctx, uint8_t* base) {
	// 0x2BB310: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BB318: movss [0x005A83E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83E0u, ctx.xmm[0].u32[0]);
	// 0x2BB320: ret
	return;
}

void sub_2BB330(X86Context& ctx, uint8_t* base) {
	// 0x2BB330: movss xmm0, dword ptr [0x005A83E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A83E0u);
	// 0x2BB338: movss [0x005A83E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83E8u, ctx.xmm[0].u32[0]);
	// 0x2BB340: ret
	return;
}

void sub_2BB350(X86Context& ctx, uint8_t* base) {
	// 0x2BB350: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB358: movss [0x005A83B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83B0u, ctx.xmm[0].u32[0]);
	// 0x2BB360: ret
	return;
}

void sub_2BB370(X86Context& ctx, uint8_t* base) {
	// 0x2BB370: movss xmm0, dword ptr [0x005A83B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A83B4u);
	// 0x2BB378: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BB380: movss [0x005A83E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83E4u, ctx.xmm[0].u32[0]);
	// 0x2BB388: ret
	return;
}

void sub_2BB390(X86Context& ctx, uint8_t* base) {
	// 0x2BB390: movss xmm0, dword ptr [0x005A83B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A83B4u);
	// 0x2BB398: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BB3A0: movss [0x005A83C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83C0u, ctx.xmm[0].u32[0]);
	// 0x2BB3A8: ret
	return;
}

void sub_2BB3B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB3B0: movss xmm0, dword ptr [0x005A83B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A83B4u);
	// 0x2BB3B8: subss xmm0, [0x005A83C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A83C0u);
	// 0x2BB3C0: movss [0x005A83BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83BCu, ctx.xmm[0].u32[0]);
	// 0x2BB3C8: ret
	return;
}

void sub_2BB3D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB3D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BB3D8: movss [0x005A83D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83D0u, ctx.xmm[0].u32[0]);
	// 0x2BB3E0: ret
	return;
}

void sub_2BB3F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB3F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BB3F8: movss [0x005A83B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83B8u, ctx.xmm[0].u32[0]);
	// 0x2BB400: ret
	return;
}

void sub_2BB410(X86Context& ctx, uint8_t* base) {
	// 0x2BB410: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BB418: movss [0x005A8410], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8410u, ctx.xmm[0].u32[0]);
	// 0x2BB420: ret
	return;
}

void sub_2BB430(X86Context& ctx, uint8_t* base) {
	// 0x2BB430: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BB438: movss [0x005A841C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A841Cu, ctx.xmm[0].u32[0]);
	// 0x2BB440: ret
	return;
}

void sub_2BB450(X86Context& ctx, uint8_t* base) {
	// 0x2BB450: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BB458: movss [0x005A8408], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8408u, ctx.xmm[0].u32[0]);
	// 0x2BB460: ret
	return;
}

void sub_2BB470(X86Context& ctx, uint8_t* base) {
	// 0x2BB470: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BB478: movss [0x005A83F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83F0u, ctx.xmm[0].u32[0]);
	// 0x2BB480: ret
	return;
}

void sub_2BB490(X86Context& ctx, uint8_t* base) {
	// 0x2BB490: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BB498: movss [0x005A8414], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8414u, ctx.xmm[0].u32[0]);
	// 0x2BB4A0: ret
	return;
}

void sub_2BB4B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB4B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BB4B8: movss [0x005A83F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83F4u, ctx.xmm[0].u32[0]);
	// 0x2BB4C0: ret
	return;
}

void sub_2BB4D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB4D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BB4D8: movss [0x005A8424], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8424u, ctx.xmm[0].u32[0]);
	// 0x2BB4E0: ret
	return;
}

void sub_2BB4F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB4F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BB4F8: movss [0x005A840C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A840Cu, ctx.xmm[0].u32[0]);
	// 0x2BB500: ret
	return;
}

void sub_2BB510(X86Context& ctx, uint8_t* base) {
	// 0x2BB510: movss xmm0, dword ptr [0x005A8424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8424u);
	// 0x2BB518: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BB520: movss [0x005A83FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83FCu, ctx.xmm[0].u32[0]);
	// 0x2BB528: ret
	return;
}

void sub_2BB530(X86Context& ctx, uint8_t* base) {
	// 0x2BB530: movss xmm0, dword ptr [0x005A840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A840Cu);
	// 0x2BB538: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BB540: movss [0x005A8420], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8420u, ctx.xmm[0].u32[0]);
	// 0x2BB548: ret
	return;
}

void sub_2BB550(X86Context& ctx, uint8_t* base) {
	// 0x2BB550: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB558: movss [0x005A8430], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8430u, ctx.xmm[0].u32[0]);
	// 0x2BB560: ret
	return;
}

void sub_2BB570(X86Context& ctx, uint8_t* base) {
	// 0x2BB570: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BB578: movss [0x005A8428], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8428u, ctx.xmm[0].u32[0]);
	// 0x2BB580: ret
	return;
}

void sub_2BB590(X86Context& ctx, uint8_t* base) {
	// 0x2BB590: movss xmm0, dword ptr [0x005A8428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8428u);
	// 0x2BB598: movss [0x005A842C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A842Cu, ctx.xmm[0].u32[0]);
	// 0x2BB5A0: ret
	return;
}

void sub_2BB5B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB5B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB5B8: movss [0x005A8404], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8404u, ctx.xmm[0].u32[0]);
	// 0x2BB5C0: ret
	return;
}

