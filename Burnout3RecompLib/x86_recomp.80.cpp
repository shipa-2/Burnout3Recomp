#include "x86_recomp_shared.h"

void sub_2C54E0(X86Context& ctx, uint8_t* base) {
	// 0x2C54E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C54E8: movss [0x005A9654], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9654u, ctx.xmm[0].u32[0]);
	// 0x2C54F0: ret
	return;
}

void sub_2C5500(X86Context& ctx, uint8_t* base) {
	// 0x2C5500: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5508: movss [0x005A9640], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9640u, ctx.xmm[0].u32[0]);
	// 0x2C5510: ret
	return;
}

void sub_2C5520(X86Context& ctx, uint8_t* base) {
	// 0x2C5520: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5528: movss [0x005A9628], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9628u, ctx.xmm[0].u32[0]);
	// 0x2C5530: ret
	return;
}

void sub_2C5540(X86Context& ctx, uint8_t* base) {
	// 0x2C5540: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5548: movss [0x005A964C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A964Cu, ctx.xmm[0].u32[0]);
	// 0x2C5550: ret
	return;
}

void sub_2C5560(X86Context& ctx, uint8_t* base) {
	// 0x2C5560: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5568: movss [0x005A962C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A962Cu, ctx.xmm[0].u32[0]);
	// 0x2C5570: ret
	return;
}

void sub_2C5580(X86Context& ctx, uint8_t* base) {
	// 0x2C5580: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C5588: movss [0x005A965C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A965Cu, ctx.xmm[0].u32[0]);
	// 0x2C5590: ret
	return;
}

void sub_2C55A0(X86Context& ctx, uint8_t* base) {
	// 0x2C55A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C55A8: movss [0x005A9644], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9644u, ctx.xmm[0].u32[0]);
	// 0x2C55B0: ret
	return;
}

void sub_2C55C0(X86Context& ctx, uint8_t* base) {
	// 0x2C55C0: movss xmm0, dword ptr [0x005A965C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A965Cu);
	// 0x2C55C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C55D0: movss [0x005A9634], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9634u, ctx.xmm[0].u32[0]);
	// 0x2C55D8: ret
	return;
}

void sub_2C55E0(X86Context& ctx, uint8_t* base) {
	// 0x2C55E0: movss xmm0, dword ptr [0x005A9644]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9644u);
	// 0x2C55E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C55F0: movss [0x005A9658], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9658u, ctx.xmm[0].u32[0]);
	// 0x2C55F8: ret
	return;
}

void sub_2C5600(X86Context& ctx, uint8_t* base) {
	// 0x2C5600: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5608: movss [0x005A9668], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9668u, ctx.xmm[0].u32[0]);
	// 0x2C5610: ret
	return;
}

void sub_2C5620(X86Context& ctx, uint8_t* base) {
	// 0x2C5620: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C5628: movss [0x005A9660], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9660u, ctx.xmm[0].u32[0]);
	// 0x2C5630: ret
	return;
}

void sub_2C5640(X86Context& ctx, uint8_t* base) {
	// 0x2C5640: movss xmm0, dword ptr [0x005A9660]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9660u);
	// 0x2C5648: movss [0x005A9664], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9664u, ctx.xmm[0].u32[0]);
	// 0x2C5650: ret
	return;
}

void sub_2C5660(X86Context& ctx, uint8_t* base) {
	// 0x2C5660: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5668: movss [0x005A963C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A963Cu, ctx.xmm[0].u32[0]);
	// 0x2C5670: ret
	return;
}

void sub_2C5680(X86Context& ctx, uint8_t* base) {
	// 0x2C5680: movss xmm0, dword ptr [0x005A9644]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9644u);
	// 0x2C5688: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5690: movss [0x005A9638], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9638u, ctx.xmm[0].u32[0]);
	// 0x2C5698: ret
	return;
}

void sub_2C56A0(X86Context& ctx, uint8_t* base) {
	// 0x2C56A0: movss xmm0, dword ptr [0x005A9644]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9644u);
	// 0x2C56A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C56B0: movss [0x005A9650], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9650u, ctx.xmm[0].u32[0]);
	// 0x2C56B8: ret
	return;
}

void sub_2C56C0(X86Context& ctx, uint8_t* base) {
	// 0x2C56C0: movss xmm0, dword ptr [0x005A9644]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9644u);
	// 0x2C56C8: subss xmm0, [0x005A9650]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9650u);
	// 0x2C56D0: movss [0x005A9630], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9630u, ctx.xmm[0].u32[0]);
	// 0x2C56D8: ret
	return;
}

void sub_2C56E0(X86Context& ctx, uint8_t* base) {
	// 0x2C56E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C56E8: movss [0x005A9688], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9688u, ctx.xmm[0].u32[0]);
	// 0x2C56F0: ret
	return;
}

void sub_2C5700(X86Context& ctx, uint8_t* base) {
	// 0x2C5700: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C5708: movss [0x005A9694], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9694u, ctx.xmm[0].u32[0]);
	// 0x2C5710: ret
	return;
}

void sub_2C5720(X86Context& ctx, uint8_t* base) {
	// 0x2C5720: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5728: movss [0x005A9684], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9684u, ctx.xmm[0].u32[0]);
	// 0x2C5730: ret
	return;
}

void sub_2C5740(X86Context& ctx, uint8_t* base) {
	// 0x2C5740: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5748: movss [0x005A966C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A966Cu, ctx.xmm[0].u32[0]);
	// 0x2C5750: ret
	return;
}

void sub_2C5760(X86Context& ctx, uint8_t* base) {
	// 0x2C5760: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C5768: movss [0x005A968C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A968Cu, ctx.xmm[0].u32[0]);
	// 0x2C5770: ret
	return;
}

void sub_2C5780(X86Context& ctx, uint8_t* base) {
	// 0x2C5780: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C5788: movss [0x005A9674], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9674u, ctx.xmm[0].u32[0]);
	// 0x2C5790: ret
	return;
}

void sub_2C57A0(X86Context& ctx, uint8_t* base) {
	// 0x2C57A0: movss xmm0, dword ptr [0x005A968C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A968Cu);
	// 0x2C57A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C57B0: movss [0x005A969C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A969Cu, ctx.xmm[0].u32[0]);
	// 0x2C57B8: ret
	return;
}

void sub_2C57C0(X86Context& ctx, uint8_t* base) {
	// 0x2C57C0: movss xmm0, dword ptr [0x005A9674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9674u);
	// 0x2C57C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C57D0: movss [0x005A9698], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9698u, ctx.xmm[0].u32[0]);
	// 0x2C57D8: ret
	return;
}

void sub_2C57E0(X86Context& ctx, uint8_t* base) {
	// 0x2C57E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C57E8: movss [0x005A96AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96ACu, ctx.xmm[0].u32[0]);
	// 0x2C57F0: ret
	return;
}

void sub_2C5800(X86Context& ctx, uint8_t* base) {
	// 0x2C5800: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C5808: movss [0x005A96A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96A0u, ctx.xmm[0].u32[0]);
	// 0x2C5810: ret
	return;
}

void sub_2C5820(X86Context& ctx, uint8_t* base) {
	// 0x2C5820: movss xmm0, dword ptr [0x005A96A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A96A0u);
	// 0x2C5828: movss [0x005A96A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96A8u, ctx.xmm[0].u32[0]);
	// 0x2C5830: ret
	return;
}

void sub_2C5840(X86Context& ctx, uint8_t* base) {
	// 0x2C5840: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5848: movss [0x005A9670], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9670u, ctx.xmm[0].u32[0]);
	// 0x2C5850: ret
	return;
}

void sub_2C5860(X86Context& ctx, uint8_t* base) {
	// 0x2C5860: movss xmm0, dword ptr [0x005A9674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9674u);
	// 0x2C5868: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5870: movss [0x005A96A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96A4u, ctx.xmm[0].u32[0]);
	// 0x2C5878: ret
	return;
}

void sub_2C5880(X86Context& ctx, uint8_t* base) {
	// 0x2C5880: movss xmm0, dword ptr [0x005A9674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9674u);
	// 0x2C5888: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C5890: movss [0x005A9680], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9680u, ctx.xmm[0].u32[0]);
	// 0x2C5898: ret
	return;
}

void sub_2C58A0(X86Context& ctx, uint8_t* base) {
	// 0x2C58A0: movss xmm0, dword ptr [0x005A9674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9674u);
	// 0x2C58A8: subss xmm0, [0x005A9680]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9680u);
	// 0x2C58B0: movss [0x005A967C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A967Cu, ctx.xmm[0].u32[0]);
	// 0x2C58B8: ret
	return;
}

void sub_2C58C0(X86Context& ctx, uint8_t* base) {
	// 0x2C58C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C58C8: movss [0x005A9690], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9690u, ctx.xmm[0].u32[0]);
	// 0x2C58D0: ret
	return;
}

void sub_2C58E0(X86Context& ctx, uint8_t* base) {
	// 0x2C58E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C58E8: movss [0x005A9678], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9678u, ctx.xmm[0].u32[0]);
	// 0x2C58F0: ret
	return;
}

void sub_2C5900(X86Context& ctx, uint8_t* base) {
	// 0x2C5900: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C5908: movss [0x005A96BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96BCu, ctx.xmm[0].u32[0]);
	// 0x2C5910: ret
	return;
}

void sub_2C5920(X86Context& ctx, uint8_t* base) {
	// 0x2C5920: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C5928: movss [0x005A96C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96C4u, ctx.xmm[0].u32[0]);
	// 0x2C5930: ret
	return;
}

void sub_2C5940(X86Context& ctx, uint8_t* base) {
	// 0x2C5940: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5948: movss [0x005A96B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96B8u, ctx.xmm[0].u32[0]);
	// 0x2C5950: ret
	return;
}

void sub_2C5960(X86Context& ctx, uint8_t* base) {
	// 0x2C5960: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5968: movss [0x005A96B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96B0u, ctx.xmm[0].u32[0]);
	// 0x2C5970: ret
	return;
}

void sub_2C5980(X86Context& ctx, uint8_t* base) {
	// 0x2C5980: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5988: movss [0x005A96C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96C0u, ctx.xmm[0].u32[0]);
	// 0x2C5990: ret
	return;
}

void sub_2C59A0(X86Context& ctx, uint8_t* base) {
	// 0x2C59A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C59A8: movss [0x005A96B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96B4u, ctx.xmm[0].u32[0]);
	// 0x2C59B0: ret
	return;
}

void sub_2C59C0(X86Context& ctx, uint8_t* base) {
	// 0x2C59C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C59C8: movss [0x005A96D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96D0u, ctx.xmm[0].u32[0]);
	// 0x2C59D0: ret
	return;
}

void sub_2C59E0(X86Context& ctx, uint8_t* base) {
	// 0x2C59E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C59E8: movss [0x005A96D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96D8u, ctx.xmm[0].u32[0]);
	// 0x2C59F0: ret
	return;
}

void sub_2C5A00(X86Context& ctx, uint8_t* base) {
	// 0x2C5A00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5A08: movss [0x005A96CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96CCu, ctx.xmm[0].u32[0]);
	// 0x2C5A10: ret
	return;
}

void sub_2C5A20(X86Context& ctx, uint8_t* base) {
	// 0x2C5A20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5A28: movss [0x005A96C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96C8u, ctx.xmm[0].u32[0]);
	// 0x2C5A30: ret
	return;
}

void sub_2C5A40(X86Context& ctx, uint8_t* base) {
	// 0x2C5A40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5A48: movss [0x005A96D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96D4u, ctx.xmm[0].u32[0]);
	// 0x2C5A50: ret
	return;
}

void sub_2C5A60(X86Context& ctx, uint8_t* base) {
	// 0x2C5A60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C5A68: movss [0x005A96E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96E4u, ctx.xmm[0].u32[0]);
	// 0x2C5A70: ret
	return;
}

void sub_2C5A80(X86Context& ctx, uint8_t* base) {
	// 0x2C5A80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C5A88: movss [0x005A96F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96F0u, ctx.xmm[0].u32[0]);
	// 0x2C5A90: ret
	return;
}

void sub_2C5AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C5AA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5AA8: movss [0x005A96E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96E0u, ctx.xmm[0].u32[0]);
	// 0x2C5AB0: ret
	return;
}

void sub_2C5AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C5AC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5AC8: movss [0x005A96EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96ECu, ctx.xmm[0].u32[0]);
	// 0x2C5AD0: ret
	return;
}

void sub_2C5AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C5AE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5AE8: movss [0x005A96E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96E8u, ctx.xmm[0].u32[0]);
	// 0x2C5AF0: ret
	return;
}

void sub_2C5B00(X86Context& ctx, uint8_t* base) {
	// 0x2C5B00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5B08: movss [0x005A96DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96DCu, ctx.xmm[0].u32[0]);
	// 0x2C5B10: ret
	return;
}

void sub_2C5B20(X86Context& ctx, uint8_t* base) {
	// 0x2C5B20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C5B28: movss [0x005A9710], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9710u, ctx.xmm[0].u32[0]);
	// 0x2C5B30: ret
	return;
}

void sub_2C5B40(X86Context& ctx, uint8_t* base) {
	// 0x2C5B40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C5B48: movss [0x005A971C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A971Cu, ctx.xmm[0].u32[0]);
	// 0x2C5B50: ret
	return;
}

void sub_2C5B60(X86Context& ctx, uint8_t* base) {
	// 0x2C5B60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5B68: movss [0x005A970C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A970Cu, ctx.xmm[0].u32[0]);
	// 0x2C5B70: ret
	return;
}

void sub_2C5B80(X86Context& ctx, uint8_t* base) {
	// 0x2C5B80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5B88: movss [0x005A96F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96F4u, ctx.xmm[0].u32[0]);
	// 0x2C5B90: ret
	return;
}

void sub_2C5BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C5BA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C5BA8: movss [0x005A9714], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9714u, ctx.xmm[0].u32[0]);
	// 0x2C5BB0: ret
	return;
}

void sub_2C5BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C5BC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C5BC8: movss [0x005A96FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96FCu, ctx.xmm[0].u32[0]);
	// 0x2C5BD0: ret
	return;
}

void sub_2C5BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C5BE0: movss xmm0, dword ptr [0x005A9714]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9714u);
	// 0x2C5BE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C5BF0: movss [0x005A9724], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9724u, ctx.xmm[0].u32[0]);
	// 0x2C5BF8: ret
	return;
}

void sub_2C5C00(X86Context& ctx, uint8_t* base) {
	// 0x2C5C00: movss xmm0, dword ptr [0x005A96FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A96FCu);
	// 0x2C5C08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C5C10: movss [0x005A9720], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9720u, ctx.xmm[0].u32[0]);
	// 0x2C5C18: ret
	return;
}

void sub_2C5C20(X86Context& ctx, uint8_t* base) {
	// 0x2C5C20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5C28: movss [0x005A9734], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9734u, ctx.xmm[0].u32[0]);
	// 0x2C5C30: ret
	return;
}

void sub_2C5C40(X86Context& ctx, uint8_t* base) {
	// 0x2C5C40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C5C48: movss [0x005A9728], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9728u, ctx.xmm[0].u32[0]);
	// 0x2C5C50: ret
	return;
}

void sub_2C5C60(X86Context& ctx, uint8_t* base) {
	// 0x2C5C60: movss xmm0, dword ptr [0x005A9728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9728u);
	// 0x2C5C68: movss [0x005A9730], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9730u, ctx.xmm[0].u32[0]);
	// 0x2C5C70: ret
	return;
}

void sub_2C5C80(X86Context& ctx, uint8_t* base) {
	// 0x2C5C80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5C88: movss [0x005A96F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A96F8u, ctx.xmm[0].u32[0]);
	// 0x2C5C90: ret
	return;
}

void sub_2C5CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C5CA0: movss xmm0, dword ptr [0x005A96FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A96FCu);
	// 0x2C5CA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5CB0: movss [0x005A972C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A972Cu, ctx.xmm[0].u32[0]);
	// 0x2C5CB8: ret
	return;
}

void sub_2C5CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C5CC0: movss xmm0, dword ptr [0x005A96FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A96FCu);
	// 0x2C5CC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C5CD0: movss [0x005A9708], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9708u, ctx.xmm[0].u32[0]);
	// 0x2C5CD8: ret
	return;
}

void sub_2C5CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C5CE0: movss xmm0, dword ptr [0x005A96FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A96FCu);
	// 0x2C5CE8: subss xmm0, [0x005A9708]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9708u);
	// 0x2C5CF0: movss [0x005A9704], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9704u, ctx.xmm[0].u32[0]);
	// 0x2C5CF8: ret
	return;
}

void sub_2C5D00(X86Context& ctx, uint8_t* base) {
	// 0x2C5D00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5D08: movss [0x005A9718], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9718u, ctx.xmm[0].u32[0]);
	// 0x2C5D10: ret
	return;
}

void sub_2C5D20(X86Context& ctx, uint8_t* base) {
	// 0x2C5D20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5D28: movss [0x005A9700], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9700u, ctx.xmm[0].u32[0]);
	// 0x2C5D30: ret
	return;
}

void sub_2C5D40(X86Context& ctx, uint8_t* base) {
	// 0x2C5D40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C5D48: movss [0x005A9744], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9744u, ctx.xmm[0].u32[0]);
	// 0x2C5D50: ret
	return;
}

void sub_2C5D60(X86Context& ctx, uint8_t* base) {
	// 0x2C5D60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C5D68: movss [0x005A974C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A974Cu, ctx.xmm[0].u32[0]);
	// 0x2C5D70: ret
	return;
}

void sub_2C5D80(X86Context& ctx, uint8_t* base) {
	// 0x2C5D80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5D88: movss [0x005A9740], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9740u, ctx.xmm[0].u32[0]);
	// 0x2C5D90: ret
	return;
}

void sub_2C5DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C5DA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5DA8: movss [0x005A9738], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9738u, ctx.xmm[0].u32[0]);
	// 0x2C5DB0: ret
	return;
}

void sub_2C5DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C5DC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5DC8: movss [0x005A9748], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9748u, ctx.xmm[0].u32[0]);
	// 0x2C5DD0: ret
	return;
}

void sub_2C5DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C5DE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5DE8: movss [0x005A973C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A973Cu, ctx.xmm[0].u32[0]);
	// 0x2C5DF0: ret
	return;
}

void sub_2C5E00(X86Context& ctx, uint8_t* base) {
	// 0x2C5E00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C5E08: movss [0x005A976C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A976Cu, ctx.xmm[0].u32[0]);
	// 0x2C5E10: ret
	return;
}

void sub_2C5E20(X86Context& ctx, uint8_t* base) {
	// 0x2C5E20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C5E28: movss [0x005A977C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A977Cu, ctx.xmm[0].u32[0]);
	// 0x2C5E30: ret
	return;
}

void sub_2C5E40(X86Context& ctx, uint8_t* base) {
	// 0x2C5E40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C5E48: movss [0x005A9764], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9764u, ctx.xmm[0].u32[0]);
	// 0x2C5E50: ret
	return;
}

void sub_2C5E60(X86Context& ctx, uint8_t* base) {
	// 0x2C5E60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5E68: movss [0x005A9774], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9774u, ctx.xmm[0].u32[0]);
	// 0x2C5E70: ret
	return;
}

void sub_2C5E80(X86Context& ctx, uint8_t* base) {
	// 0x2C5E80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5E88: movss [0x005A9770], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9770u, ctx.xmm[0].u32[0]);
	// 0x2C5E90: ret
	return;
}

void sub_2C5EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C5EA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5EA8: movss [0x005A9750], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9750u, ctx.xmm[0].u32[0]);
	// 0x2C5EB0: ret
	return;
}

void sub_2C5EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C5EC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C5EC8: movss [0x005A9784], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9784u, ctx.xmm[0].u32[0]);
	// 0x2C5ED0: ret
	return;
}

void sub_2C5EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C5EE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C5EE8: movss [0x005A9768], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9768u, ctx.xmm[0].u32[0]);
	// 0x2C5EF0: ret
	return;
}

void sub_2C5F00(X86Context& ctx, uint8_t* base) {
	// 0x2C5F00: movss xmm0, dword ptr [0x005A9784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9784u);
	// 0x2C5F08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C5F10: movss [0x005A9758], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9758u, ctx.xmm[0].u32[0]);
	// 0x2C5F18: ret
	return;
}

void sub_2C5F20(X86Context& ctx, uint8_t* base) {
	// 0x2C5F20: movss xmm0, dword ptr [0x005A9768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9768u);
	// 0x2C5F28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C5F30: movss [0x005A9780], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9780u, ctx.xmm[0].u32[0]);
	// 0x2C5F38: ret
	return;
}

void sub_2C5F40(X86Context& ctx, uint8_t* base) {
	// 0x2C5F40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5F48: movss [0x005A9790], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9790u, ctx.xmm[0].u32[0]);
	// 0x2C5F50: ret
	return;
}

void sub_2C5F60(X86Context& ctx, uint8_t* base) {
	// 0x2C5F60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C5F68: movss [0x005A9788], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9788u, ctx.xmm[0].u32[0]);
	// 0x2C5F70: ret
	return;
}

void sub_2C5F80(X86Context& ctx, uint8_t* base) {
	// 0x2C5F80: movss xmm0, dword ptr [0x005A9788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9788u);
	// 0x2C5F88: movss [0x005A978C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A978Cu, ctx.xmm[0].u32[0]);
	// 0x2C5F90: ret
	return;
}

void sub_2C5FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C5FA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5FA8: movss [0x005A9760], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9760u, ctx.xmm[0].u32[0]);
	// 0x2C5FB0: ret
	return;
}

void sub_2C5FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C5FC0: movss xmm0, dword ptr [0x005A9768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9768u);
	// 0x2C5FC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5FD0: movss [0x005A975C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A975Cu, ctx.xmm[0].u32[0]);
	// 0x2C5FD8: ret
	return;
}

void sub_2C5FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C5FE0: movss xmm0, dword ptr [0x005A9768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9768u);
	// 0x2C5FE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C5FF0: movss [0x005A9778], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9778u, ctx.xmm[0].u32[0]);
	// 0x2C5FF8: ret
	return;
}

void sub_2C6000(X86Context& ctx, uint8_t* base) {
	// 0x2C6000: movss xmm0, dword ptr [0x005A9768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9768u);
	// 0x2C6008: subss xmm0, [0x005A9778]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9778u);
	// 0x2C6010: movss [0x005A9754], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9754u, ctx.xmm[0].u32[0]);
	// 0x2C6018: ret
	return;
}

void sub_2C6020(X86Context& ctx, uint8_t* base) {
	// 0x2C6020: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C6028: movss [0x005A97A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97A0u, ctx.xmm[0].u32[0]);
	// 0x2C6030: ret
	return;
}

void sub_2C6040(X86Context& ctx, uint8_t* base) {
	// 0x2C6040: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6048: movss [0x005A97A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97A8u, ctx.xmm[0].u32[0]);
	// 0x2C6050: ret
	return;
}

void sub_2C6060(X86Context& ctx, uint8_t* base) {
	// 0x2C6060: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6068: movss [0x005A979C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A979Cu, ctx.xmm[0].u32[0]);
	// 0x2C6070: ret
	return;
}

void sub_2C6080(X86Context& ctx, uint8_t* base) {
	// 0x2C6080: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6088: movss [0x005A9794], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9794u, ctx.xmm[0].u32[0]);
	// 0x2C6090: ret
	return;
}

void sub_2C60A0(X86Context& ctx, uint8_t* base) {
	// 0x2C60A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C60A8: movss [0x005A97A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97A4u, ctx.xmm[0].u32[0]);
	// 0x2C60B0: ret
	return;
}

void sub_2C60C0(X86Context& ctx, uint8_t* base) {
	// 0x2C60C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C60C8: movss [0x005A9798], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9798u, ctx.xmm[0].u32[0]);
	// 0x2C60D0: ret
	return;
}

void sub_2C60E0(X86Context& ctx, uint8_t* base) {
	// 0x2C60E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C60E8: movss [0x005A97B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97B4u, ctx.xmm[0].u32[0]);
	// 0x2C60F0: ret
	return;
}

void sub_2C6100(X86Context& ctx, uint8_t* base) {
	// 0x2C6100: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6108: movss [0x005A97C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97C0u, ctx.xmm[0].u32[0]);
	// 0x2C6110: ret
	return;
}

void sub_2C6120(X86Context& ctx, uint8_t* base) {
	// 0x2C6120: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6128: movss [0x005A97B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97B0u, ctx.xmm[0].u32[0]);
	// 0x2C6130: ret
	return;
}

void sub_2C6140(X86Context& ctx, uint8_t* base) {
	// 0x2C6140: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C6148: movss [0x005A97BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97BCu, ctx.xmm[0].u32[0]);
	// 0x2C6150: ret
	return;
}

void sub_2C6160(X86Context& ctx, uint8_t* base) {
	// 0x2C6160: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6168: movss [0x005A97B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97B8u, ctx.xmm[0].u32[0]);
	// 0x2C6170: ret
	return;
}

void sub_2C6180(X86Context& ctx, uint8_t* base) {
	// 0x2C6180: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C6188: movss [0x005A97AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97ACu, ctx.xmm[0].u32[0]);
	// 0x2C6190: ret
	return;
}

void sub_2C61A0(X86Context& ctx, uint8_t* base) {
	// 0x2C61A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C61A8: movss [0x005A97E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97E0u, ctx.xmm[0].u32[0]);
	// 0x2C61B0: ret
	return;
}

void sub_2C61C0(X86Context& ctx, uint8_t* base) {
	// 0x2C61C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C61C8: movss [0x005A97EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97ECu, ctx.xmm[0].u32[0]);
	// 0x2C61D0: ret
	return;
}

void sub_2C61E0(X86Context& ctx, uint8_t* base) {
	// 0x2C61E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C61E8: movss [0x005A97DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97DCu, ctx.xmm[0].u32[0]);
	// 0x2C61F0: ret
	return;
}

void sub_2C6200(X86Context& ctx, uint8_t* base) {
	// 0x2C6200: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6208: movss [0x005A97C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97C4u, ctx.xmm[0].u32[0]);
	// 0x2C6210: ret
	return;
}

void sub_2C6220(X86Context& ctx, uint8_t* base) {
	// 0x2C6220: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C6228: movss [0x005A97E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97E4u, ctx.xmm[0].u32[0]);
	// 0x2C6230: ret
	return;
}

void sub_2C6240(X86Context& ctx, uint8_t* base) {
	// 0x2C6240: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C6248: movss [0x005A97CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97CCu, ctx.xmm[0].u32[0]);
	// 0x2C6250: ret
	return;
}

void sub_2C6260(X86Context& ctx, uint8_t* base) {
	// 0x2C6260: movss xmm0, dword ptr [0x005A97E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A97E4u);
	// 0x2C6268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6270: movss [0x005A97F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97F4u, ctx.xmm[0].u32[0]);
	// 0x2C6278: ret
	return;
}

void sub_2C6280(X86Context& ctx, uint8_t* base) {
	// 0x2C6280: movss xmm0, dword ptr [0x005A97CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A97CCu);
	// 0x2C6288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C6290: movss [0x005A97F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97F0u, ctx.xmm[0].u32[0]);
	// 0x2C6298: ret
	return;
}

void sub_2C62A0(X86Context& ctx, uint8_t* base) {
	// 0x2C62A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C62A8: movss [0x005A9804], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9804u, ctx.xmm[0].u32[0]);
	// 0x2C62B0: ret
	return;
}

void sub_2C62C0(X86Context& ctx, uint8_t* base) {
	// 0x2C62C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C62C8: movss [0x005A97F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97F8u, ctx.xmm[0].u32[0]);
	// 0x2C62D0: ret
	return;
}

void sub_2C62E0(X86Context& ctx, uint8_t* base) {
	// 0x2C62E0: movss xmm0, dword ptr [0x005A97F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A97F8u);
	// 0x2C62E8: movss [0x005A9800], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9800u, ctx.xmm[0].u32[0]);
	// 0x2C62F0: ret
	return;
}

void sub_2C6300(X86Context& ctx, uint8_t* base) {
	// 0x2C6300: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6308: movss [0x005A97C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97C8u, ctx.xmm[0].u32[0]);
	// 0x2C6310: ret
	return;
}

void sub_2C6320(X86Context& ctx, uint8_t* base) {
	// 0x2C6320: movss xmm0, dword ptr [0x005A97CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A97CCu);
	// 0x2C6328: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C6330: movss [0x005A97FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97FCu, ctx.xmm[0].u32[0]);
	// 0x2C6338: ret
	return;
}

void sub_2C6340(X86Context& ctx, uint8_t* base) {
	// 0x2C6340: movss xmm0, dword ptr [0x005A97CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A97CCu);
	// 0x2C6348: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C6350: movss [0x005A97D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97D8u, ctx.xmm[0].u32[0]);
	// 0x2C6358: ret
	return;
}

void sub_2C6360(X86Context& ctx, uint8_t* base) {
	// 0x2C6360: movss xmm0, dword ptr [0x005A97CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A97CCu);
	// 0x2C6368: subss xmm0, [0x005A97D8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A97D8u);
	// 0x2C6370: movss [0x005A97D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97D4u, ctx.xmm[0].u32[0]);
	// 0x2C6378: ret
	return;
}

void sub_2C6380(X86Context& ctx, uint8_t* base) {
	// 0x2C6380: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C6388: movss [0x005A97E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97E8u, ctx.xmm[0].u32[0]);
	// 0x2C6390: ret
	return;
}

void sub_2C63A0(X86Context& ctx, uint8_t* base) {
	// 0x2C63A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C63A8: movss [0x005A97D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A97D0u, ctx.xmm[0].u32[0]);
	// 0x2C63B0: ret
	return;
}

void sub_2C63C0(X86Context& ctx, uint8_t* base) {
	// 0x2C63C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C63C8: movss [0x005A9824], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9824u, ctx.xmm[0].u32[0]);
	// 0x2C63D0: ret
	return;
}

void sub_2C63E0(X86Context& ctx, uint8_t* base) {
	// 0x2C63E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C63E8: movss [0x005A9830], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9830u, ctx.xmm[0].u32[0]);
	// 0x2C63F0: ret
	return;
}

void sub_2C6400(X86Context& ctx, uint8_t* base) {
	// 0x2C6400: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6408: movss [0x005A9820], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9820u, ctx.xmm[0].u32[0]);
	// 0x2C6410: ret
	return;
}

void sub_2C6420(X86Context& ctx, uint8_t* base) {
	// 0x2C6420: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6428: movss [0x005A9808], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9808u, ctx.xmm[0].u32[0]);
	// 0x2C6430: ret
	return;
}

void sub_2C6440(X86Context& ctx, uint8_t* base) {
	// 0x2C6440: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C6448: movss [0x005A9828], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9828u, ctx.xmm[0].u32[0]);
	// 0x2C6450: ret
	return;
}

void sub_2C6460(X86Context& ctx, uint8_t* base) {
	// 0x2C6460: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C6468: movss [0x005A9810], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9810u, ctx.xmm[0].u32[0]);
	// 0x2C6470: ret
	return;
}

void sub_2C6480(X86Context& ctx, uint8_t* base) {
	// 0x2C6480: movss xmm0, dword ptr [0x005A9828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9828u);
	// 0x2C6488: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6490: movss [0x005A9838], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9838u, ctx.xmm[0].u32[0]);
	// 0x2C6498: ret
	return;
}

void sub_2C64A0(X86Context& ctx, uint8_t* base) {
	// 0x2C64A0: movss xmm0, dword ptr [0x005A9810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9810u);
	// 0x2C64A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C64B0: movss [0x005A9834], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9834u, ctx.xmm[0].u32[0]);
	// 0x2C64B8: ret
	return;
}

void sub_2C64C0(X86Context& ctx, uint8_t* base) {
	// 0x2C64C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C64C8: movss [0x005A9848], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9848u, ctx.xmm[0].u32[0]);
	// 0x2C64D0: ret
	return;
}

void sub_2C64E0(X86Context& ctx, uint8_t* base) {
	// 0x2C64E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C64E8: movss [0x005A983C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A983Cu, ctx.xmm[0].u32[0]);
	// 0x2C64F0: ret
	return;
}

void sub_2C6500(X86Context& ctx, uint8_t* base) {
	// 0x2C6500: movss xmm0, dword ptr [0x005A983C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A983Cu);
	// 0x2C6508: movss [0x005A9844], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9844u, ctx.xmm[0].u32[0]);
	// 0x2C6510: ret
	return;
}

void sub_2C6520(X86Context& ctx, uint8_t* base) {
	// 0x2C6520: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6528: movss [0x005A980C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A980Cu, ctx.xmm[0].u32[0]);
	// 0x2C6530: ret
	return;
}

void sub_2C6540(X86Context& ctx, uint8_t* base) {
	// 0x2C6540: movss xmm0, dword ptr [0x005A9810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9810u);
	// 0x2C6548: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C6550: movss [0x005A9840], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9840u, ctx.xmm[0].u32[0]);
	// 0x2C6558: ret
	return;
}

void sub_2C6560(X86Context& ctx, uint8_t* base) {
	// 0x2C6560: movss xmm0, dword ptr [0x005A9810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9810u);
	// 0x2C6568: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C6570: movss [0x005A981C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A981Cu, ctx.xmm[0].u32[0]);
	// 0x2C6578: ret
	return;
}

void sub_2C6580(X86Context& ctx, uint8_t* base) {
	// 0x2C6580: movss xmm0, dword ptr [0x005A9810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9810u);
	// 0x2C6588: subss xmm0, [0x005A981C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A981Cu);
	// 0x2C6590: movss [0x005A9818], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9818u, ctx.xmm[0].u32[0]);
	// 0x2C6598: ret
	return;
}

void sub_2C65A0(X86Context& ctx, uint8_t* base) {
	// 0x2C65A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C65A8: movss [0x005A982C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A982Cu, ctx.xmm[0].u32[0]);
	// 0x2C65B0: ret
	return;
}

void sub_2C65C0(X86Context& ctx, uint8_t* base) {
	// 0x2C65C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C65C8: movss [0x005A9814], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9814u, ctx.xmm[0].u32[0]);
	// 0x2C65D0: ret
	return;
}

void sub_2C65E0(X86Context& ctx, uint8_t* base) {
	// 0x2C65E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C65E8: movss [0x005A9868], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9868u, ctx.xmm[0].u32[0]);
	// 0x2C65F0: ret
	return;
}

void sub_2C6600(X86Context& ctx, uint8_t* base) {
	// 0x2C6600: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6608: movss [0x005A9874], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9874u, ctx.xmm[0].u32[0]);
	// 0x2C6610: ret
	return;
}

void sub_2C6620(X86Context& ctx, uint8_t* base) {
	// 0x2C6620: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6628: movss [0x005A9864], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9864u, ctx.xmm[0].u32[0]);
	// 0x2C6630: ret
	return;
}

void sub_2C6640(X86Context& ctx, uint8_t* base) {
	// 0x2C6640: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6648: movss [0x005A984C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A984Cu, ctx.xmm[0].u32[0]);
	// 0x2C6650: ret
	return;
}

void sub_2C6660(X86Context& ctx, uint8_t* base) {
	// 0x2C6660: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C6668: movss [0x005A986C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A986Cu, ctx.xmm[0].u32[0]);
	// 0x2C6670: ret
	return;
}

void sub_2C6680(X86Context& ctx, uint8_t* base) {
	// 0x2C6680: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C6688: movss [0x005A9854], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9854u, ctx.xmm[0].u32[0]);
	// 0x2C6690: ret
	return;
}

void sub_2C66A0(X86Context& ctx, uint8_t* base) {
	// 0x2C66A0: movss xmm0, dword ptr [0x005A986C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A986Cu);
	// 0x2C66A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C66B0: movss [0x005A987C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A987Cu, ctx.xmm[0].u32[0]);
	// 0x2C66B8: ret
	return;
}

void sub_2C66C0(X86Context& ctx, uint8_t* base) {
	// 0x2C66C0: movss xmm0, dword ptr [0x005A9854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9854u);
	// 0x2C66C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C66D0: movss [0x005A9878], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9878u, ctx.xmm[0].u32[0]);
	// 0x2C66D8: ret
	return;
}

void sub_2C66E0(X86Context& ctx, uint8_t* base) {
	// 0x2C66E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C66E8: movss [0x005A988C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A988Cu, ctx.xmm[0].u32[0]);
	// 0x2C66F0: ret
	return;
}

void sub_2C6700(X86Context& ctx, uint8_t* base) {
	// 0x2C6700: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C6708: movss [0x005A9880], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9880u, ctx.xmm[0].u32[0]);
	// 0x2C6710: ret
	return;
}

void sub_2C6720(X86Context& ctx, uint8_t* base) {
	// 0x2C6720: movss xmm0, dword ptr [0x005A9880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9880u);
	// 0x2C6728: movss [0x005A9888], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9888u, ctx.xmm[0].u32[0]);
	// 0x2C6730: ret
	return;
}

void sub_2C6740(X86Context& ctx, uint8_t* base) {
	// 0x2C6740: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6748: movss [0x005A9850], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9850u, ctx.xmm[0].u32[0]);
	// 0x2C6750: ret
	return;
}

void sub_2C6760(X86Context& ctx, uint8_t* base) {
	// 0x2C6760: movss xmm0, dword ptr [0x005A9854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9854u);
	// 0x2C6768: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C6770: movss [0x005A9884], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9884u, ctx.xmm[0].u32[0]);
	// 0x2C6778: ret
	return;
}

void sub_2C6780(X86Context& ctx, uint8_t* base) {
	// 0x2C6780: movss xmm0, dword ptr [0x005A9854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9854u);
	// 0x2C6788: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C6790: movss [0x005A9860], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9860u, ctx.xmm[0].u32[0]);
	// 0x2C6798: ret
	return;
}

void sub_2C67A0(X86Context& ctx, uint8_t* base) {
	// 0x2C67A0: movss xmm0, dword ptr [0x005A9854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9854u);
	// 0x2C67A8: subss xmm0, [0x005A9860]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9860u);
	// 0x2C67B0: movss [0x005A985C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A985Cu, ctx.xmm[0].u32[0]);
	// 0x2C67B8: ret
	return;
}

void sub_2C67C0(X86Context& ctx, uint8_t* base) {
	// 0x2C67C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C67C8: movss [0x005A9870], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9870u, ctx.xmm[0].u32[0]);
	// 0x2C67D0: ret
	return;
}

void sub_2C67E0(X86Context& ctx, uint8_t* base) {
	// 0x2C67E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C67E8: movss [0x005A9858], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9858u, ctx.xmm[0].u32[0]);
	// 0x2C67F0: ret
	return;
}

void sub_2C6800(X86Context& ctx, uint8_t* base) {
	// 0x2C6800: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C6808: movss [0x005A98B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98B0u, ctx.xmm[0].u32[0]);
	// 0x2C6810: ret
	return;
}

void sub_2C6820(X86Context& ctx, uint8_t* base) {
	// 0x2C6820: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6828: movss [0x005A98BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98BCu, ctx.xmm[0].u32[0]);
	// 0x2C6830: ret
	return;
}

void sub_2C6840(X86Context& ctx, uint8_t* base) {
	// 0x2C6840: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6848: movss [0x005A98A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98A8u, ctx.xmm[0].u32[0]);
	// 0x2C6850: ret
	return;
}

void sub_2C6860(X86Context& ctx, uint8_t* base) {
	// 0x2C6860: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6868: movss [0x005A9890], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9890u, ctx.xmm[0].u32[0]);
	// 0x2C6870: ret
	return;
}

void sub_2C6880(X86Context& ctx, uint8_t* base) {
	// 0x2C6880: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C6888: movss [0x005A98B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98B4u, ctx.xmm[0].u32[0]);
	// 0x2C6890: ret
	return;
}

void sub_2C68A0(X86Context& ctx, uint8_t* base) {
	// 0x2C68A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C68A8: movss [0x005A9894], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9894u, ctx.xmm[0].u32[0]);
	// 0x2C68B0: ret
	return;
}

void sub_2C68C0(X86Context& ctx, uint8_t* base) {
	// 0x2C68C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C68C8: movss [0x005A98C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98C4u, ctx.xmm[0].u32[0]);
	// 0x2C68D0: ret
	return;
}

void sub_2C68E0(X86Context& ctx, uint8_t* base) {
	// 0x2C68E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C68E8: movss [0x005A98AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98ACu, ctx.xmm[0].u32[0]);
	// 0x2C68F0: ret
	return;
}

void sub_2C6900(X86Context& ctx, uint8_t* base) {
	// 0x2C6900: movss xmm0, dword ptr [0x005A98C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98C4u);
	// 0x2C6908: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6910: movss [0x005A989C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A989Cu, ctx.xmm[0].u32[0]);
	// 0x2C6918: ret
	return;
}

void sub_2C6920(X86Context& ctx, uint8_t* base) {
	// 0x2C6920: movss xmm0, dword ptr [0x005A98AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98ACu);
	// 0x2C6928: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C6930: movss [0x005A98C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98C0u, ctx.xmm[0].u32[0]);
	// 0x2C6938: ret
	return;
}

void sub_2C6940(X86Context& ctx, uint8_t* base) {
	// 0x2C6940: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6948: movss [0x005A98D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98D0u, ctx.xmm[0].u32[0]);
	// 0x2C6950: ret
	return;
}

void sub_2C6960(X86Context& ctx, uint8_t* base) {
	// 0x2C6960: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C6968: movss [0x005A98C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98C8u, ctx.xmm[0].u32[0]);
	// 0x2C6970: ret
	return;
}

void sub_2C6980(X86Context& ctx, uint8_t* base) {
	// 0x2C6980: movss xmm0, dword ptr [0x005A98C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98C8u);
	// 0x2C6988: movss [0x005A98CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98CCu, ctx.xmm[0].u32[0]);
	// 0x2C6990: ret
	return;
}

void sub_2C69A0(X86Context& ctx, uint8_t* base) {
	// 0x2C69A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C69A8: movss [0x005A98A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98A4u, ctx.xmm[0].u32[0]);
	// 0x2C69B0: ret
	return;
}

void sub_2C69C0(X86Context& ctx, uint8_t* base) {
	// 0x2C69C0: movss xmm0, dword ptr [0x005A98AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98ACu);
	// 0x2C69C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C69D0: movss [0x005A98A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98A0u, ctx.xmm[0].u32[0]);
	// 0x2C69D8: ret
	return;
}

void sub_2C69E0(X86Context& ctx, uint8_t* base) {
	// 0x2C69E0: movss xmm0, dword ptr [0x005A98AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98ACu);
	// 0x2C69E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C69F0: movss [0x005A98B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98B8u, ctx.xmm[0].u32[0]);
	// 0x2C69F8: ret
	return;
}

void sub_2C6A00(X86Context& ctx, uint8_t* base) {
	// 0x2C6A00: movss xmm0, dword ptr [0x005A98AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98ACu);
	// 0x2C6A08: subss xmm0, [0x005A98B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A98B8u);
	// 0x2C6A10: movss [0x005A9898], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9898u, ctx.xmm[0].u32[0]);
	// 0x2C6A18: ret
	return;
}

void sub_2C6A20(X86Context& ctx, uint8_t* base) {
	// 0x2C6A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C6A28: movss [0x005A98D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98D8u, ctx.xmm[0].u32[0]);
	// 0x2C6A30: ret
	return;
}

void sub_2C6A40(X86Context& ctx, uint8_t* base) {
	// 0x2C6A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6A48: movss [0x005A98DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98DCu, ctx.xmm[0].u32[0]);
	// 0x2C6A50: ret
	return;
}

void sub_2C6A60(X86Context& ctx, uint8_t* base) {
	// 0x2C6A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6A68: movss [0x005A98D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98D4u, ctx.xmm[0].u32[0]);
	// 0x2C6A70: ret
	return;
}

void sub_2C6A80(X86Context& ctx, uint8_t* base) {
	// 0x2C6A80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C6A88: movss [0x005A9900], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9900u, ctx.xmm[0].u32[0]);
	// 0x2C6A90: ret
	return;
}

void sub_2C6AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C6AA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6AA8: movss [0x005A990C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A990Cu, ctx.xmm[0].u32[0]);
	// 0x2C6AB0: ret
	return;
}

void sub_2C6AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C6AC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6AC8: movss [0x005A98F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98F8u, ctx.xmm[0].u32[0]);
	// 0x2C6AD0: ret
	return;
}

void sub_2C6AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C6AE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6AE8: movss [0x005A98E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98E0u, ctx.xmm[0].u32[0]);
	// 0x2C6AF0: ret
	return;
}

void sub_2C6B00(X86Context& ctx, uint8_t* base) {
	// 0x2C6B00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C6B08: movss [0x005A9904], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9904u, ctx.xmm[0].u32[0]);
	// 0x2C6B10: ret
	return;
}

void sub_2C6B20(X86Context& ctx, uint8_t* base) {
	// 0x2C6B20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C6B28: movss [0x005A98E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98E4u, ctx.xmm[0].u32[0]);
	// 0x2C6B30: ret
	return;
}

void sub_2C6B40(X86Context& ctx, uint8_t* base) {
	// 0x2C6B40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C6B48: movss [0x005A9914], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9914u, ctx.xmm[0].u32[0]);
	// 0x2C6B50: ret
	return;
}

void sub_2C6B60(X86Context& ctx, uint8_t* base) {
	// 0x2C6B60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C6B68: movss [0x005A98FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98FCu, ctx.xmm[0].u32[0]);
	// 0x2C6B70: ret
	return;
}

void sub_2C6B80(X86Context& ctx, uint8_t* base) {
	// 0x2C6B80: movss xmm0, dword ptr [0x005A9914]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9914u);
	// 0x2C6B88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6B90: movss [0x005A98EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98ECu, ctx.xmm[0].u32[0]);
	// 0x2C6B98: ret
	return;
}

void sub_2C6BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C6BA0: movss xmm0, dword ptr [0x005A98FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98FCu);
	// 0x2C6BA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C6BB0: movss [0x005A9910], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9910u, ctx.xmm[0].u32[0]);
	// 0x2C6BB8: ret
	return;
}

void sub_2C6BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C6BC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6BC8: movss [0x005A9920], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9920u, ctx.xmm[0].u32[0]);
	// 0x2C6BD0: ret
	return;
}

void sub_2C6BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C6BE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C6BE8: movss [0x005A9918], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9918u, ctx.xmm[0].u32[0]);
	// 0x2C6BF0: ret
	return;
}

void sub_2C6C00(X86Context& ctx, uint8_t* base) {
	// 0x2C6C00: movss xmm0, dword ptr [0x005A9918]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9918u);
	// 0x2C6C08: movss [0x005A991C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A991Cu, ctx.xmm[0].u32[0]);
	// 0x2C6C10: ret
	return;
}

void sub_2C6C20(X86Context& ctx, uint8_t* base) {
	// 0x2C6C20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6C28: movss [0x005A98F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98F4u, ctx.xmm[0].u32[0]);
	// 0x2C6C30: ret
	return;
}

void sub_2C6C40(X86Context& ctx, uint8_t* base) {
	// 0x2C6C40: movss xmm0, dword ptr [0x005A98FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98FCu);
	// 0x2C6C48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C6C50: movss [0x005A98F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98F0u, ctx.xmm[0].u32[0]);
	// 0x2C6C58: ret
	return;
}

void sub_2C6C60(X86Context& ctx, uint8_t* base) {
	// 0x2C6C60: movss xmm0, dword ptr [0x005A98FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98FCu);
	// 0x2C6C68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C6C70: movss [0x005A9908], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9908u, ctx.xmm[0].u32[0]);
	// 0x2C6C78: ret
	return;
}

void sub_2C6C80(X86Context& ctx, uint8_t* base) {
	// 0x2C6C80: movss xmm0, dword ptr [0x005A98FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A98FCu);
	// 0x2C6C88: subss xmm0, [0x005A9908]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9908u);
	// 0x2C6C90: movss [0x005A98E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A98E8u, ctx.xmm[0].u32[0]);
	// 0x2C6C98: ret
	return;
}

void sub_2C6CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C6CA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C6CA8: movss [0x005A9980], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9980u, ctx.xmm[0].u32[0]);
	// 0x2C6CB0: ret
	return;
}

void sub_2C6CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C6CC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C6CC8: movss [0x005A999C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A999Cu, ctx.xmm[0].u32[0]);
	// 0x2C6CD0: ret
	return;
}

void sub_2C6CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C6CE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C6CE8: movss [0x005A9970], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9970u, ctx.xmm[0].u32[0]);
	// 0x2C6CF0: ret
	return;
}

void sub_2C6D00(X86Context& ctx, uint8_t* base) {
	// 0x2C6D00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C6D08: movss [0x005A9924], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9924u, ctx.xmm[0].u32[0]);
	// 0x2C6D10: ret
	return;
}

void sub_2C6D20(X86Context& ctx, uint8_t* base) {
	// 0x2C6D20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C6D28: movss [0x005A9984], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9984u, ctx.xmm[0].u32[0]);
	// 0x2C6D30: ret
	return;
}

void sub_2C6D40(X86Context& ctx, uint8_t* base) {
	// 0x2C6D40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C6D48: movss [0x005A9940], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9940u, ctx.xmm[0].u32[0]);
	// 0x2C6D50: ret
	return;
}

void sub_2C6D60(X86Context& ctx, uint8_t* base) {
	// 0x2C6D60: movss xmm0, dword ptr [0x005A9984]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9984u);
	// 0x2C6D68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6D70: movss [0x005A99BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99BCu, ctx.xmm[0].u32[0]);
	// 0x2C6D78: ret
	return;
}

void sub_2C6D80(X86Context& ctx, uint8_t* base) {
	// 0x2C6D80: movss xmm0, dword ptr [0x005A9940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9940u);
	// 0x2C6D88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C6D90: movss [0x005A99A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99A4u, ctx.xmm[0].u32[0]);
	// 0x2C6D98: ret
	return;
}

void sub_2C6DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C6DA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6DA8: movss [0x005A99D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99D4u, ctx.xmm[0].u32[0]);
	// 0x2C6DB0: ret
	return;
}

void sub_2C6DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C6DC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C6DC8: movss [0x005A99C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99C0u, ctx.xmm[0].u32[0]);
	// 0x2C6DD0: ret
	return;
}

void sub_2C6DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C6DE0: movss xmm0, dword ptr [0x005A99C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99C0u);
	// 0x2C6DE8: movss [0x005A99D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99D0u, ctx.xmm[0].u32[0]);
	// 0x2C6DF0: ret
	return;
}

void sub_2C6E00(X86Context& ctx, uint8_t* base) {
	// 0x2C6E00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C6E08: movss [0x005A992C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A992Cu, ctx.xmm[0].u32[0]);
	// 0x2C6E10: ret
	return;
}

void sub_2C6E20(X86Context& ctx, uint8_t* base) {
	// 0x2C6E20: movss xmm0, dword ptr [0x005A9940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9940u);
	// 0x2C6E28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C6E30: movss [0x005A99C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99C8u, ctx.xmm[0].u32[0]);
	// 0x2C6E38: ret
	return;
}

void sub_2C6E40(X86Context& ctx, uint8_t* base) {
	// 0x2C6E40: movss xmm0, dword ptr [0x005A9940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9940u);
	// 0x2C6E48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C6E50: movss [0x005A996C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A996Cu, ctx.xmm[0].u32[0]);
	// 0x2C6E58: ret
	return;
}

void sub_2C6E60(X86Context& ctx, uint8_t* base) {
	// 0x2C6E60: movss xmm0, dword ptr [0x005A9940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9940u);
	// 0x2C6E68: subss xmm0, [0x005A996C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A996Cu);
	// 0x2C6E70: movss [0x005A9948], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9948u, ctx.xmm[0].u32[0]);
	// 0x2C6E78: ret
	return;
}

void sub_2C6E80(X86Context& ctx, uint8_t* base) {
	// 0x2C6E80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C6E88: movss [0x005A9998], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9998u, ctx.xmm[0].u32[0]);
	// 0x2C6E90: ret
	return;
}

void sub_2C6EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C6EA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C6EA8: movss [0x005A9944], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9944u, ctx.xmm[0].u32[0]);
	// 0x2C6EB0: ret
	return;
}

void sub_2C6EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C6EC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C6EC8: movss [0x005A9958], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9958u, ctx.xmm[0].u32[0]);
	// 0x2C6ED0: ret
	return;
}

void sub_2C6EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C6EE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C6EE8: movss [0x005A99B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99B0u, ctx.xmm[0].u32[0]);
	// 0x2C6EF0: ret
	return;
}

void sub_2C6F00(X86Context& ctx, uint8_t* base) {
	// 0x2C6F00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2C6F08: movss [0x005A9994], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9994u, ctx.xmm[0].u32[0]);
	// 0x2C6F10: ret
	return;
}

void sub_2C6F20(X86Context& ctx, uint8_t* base) {
	// 0x2C6F20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2C6F28: movss [0x005A993C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A993Cu, ctx.xmm[0].u32[0]);
	// 0x2C6F30: ret
	return;
}

void sub_2C6F40(X86Context& ctx, uint8_t* base) {
	// 0x2C6F40: movss xmm0, dword ptr [0x005A9958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9958u);
	// 0x2C6F48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6F50: movss [0x005A9930], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9930u, ctx.xmm[0].u32[0]);
	// 0x2C6F58: ret
	return;
}

void sub_2C6F60(X86Context& ctx, uint8_t* base) {
	// 0x2C6F60: movss xmm0, dword ptr [0x005A99B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B0u);
	// 0x2C6F68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C6F70: movss [0x005A9978], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9978u, ctx.xmm[0].u32[0]);
	// 0x2C6F78: ret
	return;
}

void sub_2C6F80(X86Context& ctx, uint8_t* base) {
	// 0x2C6F80: movss xmm0, dword ptr [0x005A9930]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9930u);
	// 0x2C6F88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C6F90: movss [0x005A998C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A998Cu, ctx.xmm[0].u32[0]);
	// 0x2C6F98: ret
	return;
}

void sub_2C6FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C6FA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C6FA8: movss [0x005A9928], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9928u, ctx.xmm[0].u32[0]);
	// 0x2C6FB0: ret
	return;
}

void sub_2C6FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C6FC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C6FC8: movss [0x005A995C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A995Cu, ctx.xmm[0].u32[0]);
	// 0x2C6FD0: ret
	return;
}

void sub_2C6FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C6FE0: movss xmm0, dword ptr [0x005A9958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9958u);
	// 0x2C6FE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C6FF0: movss [0x005A9968], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9968u, ctx.xmm[0].u32[0]);
	// 0x2C6FF8: ret
	return;
}

void sub_2C7000(X86Context& ctx, uint8_t* base) {
	// 0x2C7000: movss xmm0, dword ptr [0x005A99B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B0u);
	// 0x2C7008: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C7010: movss [0x005A99B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99B4u, ctx.xmm[0].u32[0]);
	// 0x2C7018: ret
	return;
}

void sub_2C7020(X86Context& ctx, uint8_t* base) {
	// 0x2C7020: movss xmm0, dword ptr [0x005A9968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9968u);
	// 0x2C7028: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C7030: movss [0x005A99A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99A0u, ctx.xmm[0].u32[0]);
	// 0x2C7038: ret
	return;
}

void sub_2C7040(X86Context& ctx, uint8_t* base) {
	// 0x2C7040: movss xmm0, dword ptr [0x005A99B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B4u);
	// 0x2C7048: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C7050: movss [0x005A99C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99C4u, ctx.xmm[0].u32[0]);
	// 0x2C7058: ret
	return;
}

void sub_2C7060(X86Context& ctx, uint8_t* base) {
	// 0x2C7060: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2C7068: movss [0x005A9934], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9934u, ctx.xmm[0].u32[0]);
	// 0x2C7070: ret
	return;
}

void sub_2C7080(X86Context& ctx, uint8_t* base) {
	// 0x2C7080: movss xmm0, dword ptr [0x005A9958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9958u);
	// 0x2C7088: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C7090: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2C7098: movss [0x005A99AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99ACu, ctx.xmm[0].u32[0]);
	// 0x2C70A0: ret
	return;
}

void sub_2C70B0(X86Context& ctx, uint8_t* base) {
	// 0x2C70B0: movss xmm0, dword ptr [0x005A99B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B0u);
	// 0x2C70B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C70C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2C70C8: movss [0x005A994C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A994Cu, ctx.xmm[0].u32[0]);
	// 0x2C70D0: ret
	return;
}

void sub_2C70E0(X86Context& ctx, uint8_t* base) {
	// 0x2C70E0: movss xmm0, dword ptr [0x005A9958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9958u);
	// 0x2C70E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C70F0: movss [0x005A9950], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9950u, ctx.xmm[0].u32[0]);
	// 0x2C70F8: ret
	return;
}

void sub_2C7100(X86Context& ctx, uint8_t* base) {
	// 0x2C7100: movss xmm0, dword ptr [0x005A99B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B0u);
	// 0x2C7108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C7110: movss [0x005A99B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99B8u, ctx.xmm[0].u32[0]);
	// 0x2C7118: ret
	return;
}

void sub_2C7120(X86Context& ctx, uint8_t* base) {
	// 0x2C7120: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2C7128: movss [0x005A9938], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9938u, ctx.xmm[0].u32[0]);
	// 0x2C7130: ret
	return;
}

void sub_2C7140(X86Context& ctx, uint8_t* base) {
	// 0x2C7140: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2C7148: movss [0x005A9964], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9964u, ctx.xmm[0].u32[0]);
	// 0x2C7150: ret
	return;
}

void sub_2C7160(X86Context& ctx, uint8_t* base) {
	// 0x2C7160: movss xmm0, dword ptr [0x005A9938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9938u);
	// 0x2C7168: movss [0x005A99CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99CCu, ctx.xmm[0].u32[0]);
	// 0x2C7170: ret
	return;
}

void sub_2C7180(X86Context& ctx, uint8_t* base) {
	// 0x2C7180: movss xmm0, dword ptr [0x005A99B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B0u);
	// 0x2C7188: subss xmm0, [0x005A9938]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9938u);
	// 0x2C7190: movss [0x005A9990], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9990u, ctx.xmm[0].u32[0]);
	// 0x2C7198: ret
	return;
}

void sub_2C71A0(X86Context& ctx, uint8_t* base) {
	// 0x2C71A0: movss xmm0, dword ptr [0x005A9990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9990u);
	// 0x2C71A8: subss xmm0, [0x005A9964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9964u);
	// 0x2C71B0: movss [0x005A9988], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9988u, ctx.xmm[0].u32[0]);
	// 0x2C71B8: ret
	return;
}

void sub_2C71C0(X86Context& ctx, uint8_t* base) {
	// 0x2C71C0: movss xmm0, dword ptr [0x005A99B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99B8u);
	// 0x2C71C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2C71D0: movss [0x005A9974], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9974u, ctx.xmm[0].u32[0]);
	// 0x2C71D8: ret
	return;
}

void sub_2C71E0(X86Context& ctx, uint8_t* base) {
	// 0x2C71E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2C71E8: movss [0x005A9960], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9960u, ctx.xmm[0].u32[0]);
	// 0x2C71F0: ret
	return;
}

void sub_2C7200(X86Context& ctx, uint8_t* base) {
	// 0x2C7200: movss xmm0, dword ptr [0x005A9974]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9974u);
	// 0x2C7208: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2C7210: movss [0x005A99A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99A8u, ctx.xmm[0].u32[0]);
	// 0x2C7218: ret
	return;
}

void sub_2C7220(X86Context& ctx, uint8_t* base) {
	// 0x2C7220: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2C7228: movss [0x005A997C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A997Cu, ctx.xmm[0].u32[0]);
	// 0x2C7230: ret
	return;
}

void sub_2C7240(X86Context& ctx, uint8_t* base) {
	// 0x2C7240: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2C7248: movss [0x005A9954], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9954u, ctx.xmm[0].u32[0]);
	// 0x2C7250: ret
	return;
}

void sub_2C7260(X86Context& ctx, uint8_t* base) {
	// 0x2C7260: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C7268: movss [0x005A99F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99F4u, ctx.xmm[0].u32[0]);
	// 0x2C7270: ret
	return;
}

void sub_2C7280(X86Context& ctx, uint8_t* base) {
	// 0x2C7280: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C7288: movss [0x0060DFA4], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFA4u, ctx.xmm[0].u32[0]);
	// 0x2C7290: ret
	return;
}

void sub_2C72A0(X86Context& ctx, uint8_t* base) {
	// 0x2C72A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C72A8: movss [0x005A99F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99F0u, ctx.xmm[0].u32[0]);
	// 0x2C72B0: ret
	return;
}

void sub_2C72C0(X86Context& ctx, uint8_t* base) {
	// 0x2C72C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C72C8: movss [0x005A99D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99D8u, ctx.xmm[0].u32[0]);
	// 0x2C72D0: ret
	return;
}

void sub_2C72E0(X86Context& ctx, uint8_t* base) {
	// 0x2C72E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C72E8: movss [0x005A99F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99F8u, ctx.xmm[0].u32[0]);
	// 0x2C72F0: ret
	return;
}

void sub_2C7300(X86Context& ctx, uint8_t* base) {
	// 0x2C7300: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C7308: movss [0x005A99E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99E0u, ctx.xmm[0].u32[0]);
	// 0x2C7310: ret
	return;
}

void sub_2C7320(X86Context& ctx, uint8_t* base) {
	// 0x2C7320: movss xmm0, dword ptr [0x005A99F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99F8u);
	// 0x2C7328: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C7330: movss [0x0060DFAC], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFACu, ctx.xmm[0].u32[0]);
	// 0x2C7338: ret
	return;
}

void sub_2C7340(X86Context& ctx, uint8_t* base) {
	// 0x2C7340: movss xmm0, dword ptr [0x005A99E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99E0u);
	// 0x2C7348: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C7350: movss [0x0060DFA8], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFA8u, ctx.xmm[0].u32[0]);
	// 0x2C7358: ret
	return;
}

void sub_2C7360(X86Context& ctx, uint8_t* base) {
	// 0x2C7360: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C7368: movss [0x0060DFBC], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFBCu, ctx.xmm[0].u32[0]);
	// 0x2C7370: ret
	return;
}

void sub_2C7380(X86Context& ctx, uint8_t* base) {
	// 0x2C7380: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C7388: movss [0x0060DFB0], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFB0u, ctx.xmm[0].u32[0]);
	// 0x2C7390: ret
	return;
}

void sub_2C73A0(X86Context& ctx, uint8_t* base) {
	// 0x2C73A0: movss xmm0, dword ptr [0x0060DFB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x60DFB0u);
	// 0x2C73A8: movss [0x0060DFB8], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFB8u, ctx.xmm[0].u32[0]);
	// 0x2C73B0: ret
	return;
}

void sub_2C73C0(X86Context& ctx, uint8_t* base) {
	// 0x2C73C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C73C8: movss [0x005A99DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99DCu, ctx.xmm[0].u32[0]);
	// 0x2C73D0: ret
	return;
}

void sub_2C73E0(X86Context& ctx, uint8_t* base) {
	// 0x2C73E0: movss xmm0, dword ptr [0x005A99E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99E0u);
	// 0x2C73E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C73F0: movss [0x0060DFB4], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFB4u, ctx.xmm[0].u32[0]);
	// 0x2C73F8: ret
	return;
}

void sub_2C7400(X86Context& ctx, uint8_t* base) {
	// 0x2C7400: movss xmm0, dword ptr [0x005A99E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99E0u);
	// 0x2C7408: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C7410: movss [0x005A99EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99ECu, ctx.xmm[0].u32[0]);
	// 0x2C7418: ret
	return;
}

void sub_2C7420(X86Context& ctx, uint8_t* base) {
	// 0x2C7420: movss xmm0, dword ptr [0x005A99E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A99E0u);
	// 0x2C7428: subss xmm0, [0x005A99EC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A99ECu);
	// 0x2C7430: movss [0x005A99E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99E8u, ctx.xmm[0].u32[0]);
	// 0x2C7438: ret
	return;
}

void sub_2C7440(X86Context& ctx, uint8_t* base) {
	// 0x2C7440: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C7448: movss [0x0060DFA0], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFA0u, ctx.xmm[0].u32[0]);
	// 0x2C7450: ret
	return;
}

void sub_2C7460(X86Context& ctx, uint8_t* base) {
	// 0x2C7460: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C7468: movss [0x005A99E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A99E4u, ctx.xmm[0].u32[0]);
	// 0x2C7470: ret
	return;
}

void sub_2C7480(X86Context& ctx, uint8_t* base) {
	// 0x2C7480: movss xmm1, dword ptr [0x003980F8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3980F8u);
	// 0x2C7488: movss xmm0, dword ptr [0x003B16B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x2C7490: movss [0x0060DFF0], xmm1
	X86_MEM_WRITE_u32(base, 0x60DFF0u, ctx.xmm[1].u32[0]);
	// 0x2C7498: movss xmm1, dword ptr [0x003B1880]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1880u);
	// 0x2C74A0: movss [0x0060DFF4], xmm1
	X86_MEM_WRITE_u32(base, 0x60DFF4u, ctx.xmm[1].u32[0]);
	// 0x2C74A8: movss xmm1, dword ptr [0x003B1698]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x2C74B0: movss [0x0060DFFC], xmm1
	X86_MEM_WRITE_u32(base, 0x60DFFCu, ctx.xmm[1].u32[0]);
	// 0x2C74B8: movss xmm1, dword ptr [0x003A7950]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A7950u);
	// 0x2C74C0: movss [0x0060DFE4], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFE4u, ctx.xmm[0].u32[0]);
	// 0x2C74C8: movss [0x0060DFE8], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFE8u, ctx.xmm[0].u32[0]);
	// 0x2C74D0: mov dword ptr [0x0060DFEC], 0x01
	X86_MEM_WRITE_u32(base, 0x60DFECu, 1);
	// 0x2C74DA: mov dword ptr [0x0060DFF8], 0x02
	X86_MEM_WRITE_u32(base, 0x60DFF8u, 2);
	// 0x2C74E4: movss [0x0060E000], xmm1
	X86_MEM_WRITE_u32(base, 0x60E000u, ctx.xmm[1].u32[0]);
	// 0x2C74EC: mov dword ptr [0x0060E004], 0x03
	X86_MEM_WRITE_u32(base, 0x60E004u, 3);
	// 0x2C74F6: movss [0x0060E008], xmm0
	X86_MEM_WRITE_u32(base, 0x60E008u, ctx.xmm[0].u32[0]);
	// 0x2C74FE: movss [0x0060E00C], xmm1
	X86_MEM_WRITE_u32(base, 0x60E00Cu, ctx.xmm[1].u32[0]);
	// 0x2C7506: ret
	return;
}

void sub_2C7510(X86Context& ctx, uint8_t* base) {
	// 0x2C7510: movss xmm0, dword ptr [0x003A356C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A356Cu);
	// 0x2C7518: movss [0x0060E010], xmm0
	X86_MEM_WRITE_u32(base, 0x60E010u, ctx.xmm[0].u32[0]);
	// 0x2C7520: movss xmm0, dword ptr [0x003A3570]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A3570u);
	// 0x2C7528: movss [0x0060E014], xmm0
	X86_MEM_WRITE_u32(base, 0x60E014u, ctx.xmm[0].u32[0]);
	// 0x2C7530: movss xmm0, dword ptr [0x003B1850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1850u);
	// 0x2C7538: movss [0x0060E018], xmm0
	X86_MEM_WRITE_u32(base, 0x60E018u, ctx.xmm[0].u32[0]);
	// 0x2C7540: movss xmm0, dword ptr [0x003B1D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1D04u);
	// 0x2C7548: movss [0x0060E01C], xmm0
	X86_MEM_WRITE_u32(base, 0x60E01Cu, ctx.xmm[0].u32[0]);
	// 0x2C7550: ret
	return;
}

void sub_2C7560(X86Context& ctx, uint8_t* base) {
	// 0x2C7560: movss xmm0, dword ptr [0x003A356C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A356Cu);
	// 0x2C7568: movss [0x0060DFC0], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFC0u, ctx.xmm[0].u32[0]);
	// 0x2C7570: movss xmm0, dword ptr [0x003A3570]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A3570u);
	// 0x2C7578: movss [0x0060DFC4], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFC4u, ctx.xmm[0].u32[0]);
	// 0x2C7580: movss xmm0, dword ptr [0x003B1850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1850u);
	// 0x2C7588: movss [0x0060DFC8], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFC8u, ctx.xmm[0].u32[0]);
	// 0x2C7590: movss xmm0, dword ptr [0x003B1C1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C1Cu);
	// 0x2C7598: movss [0x0060DFCC], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFCCu, ctx.xmm[0].u32[0]);
	// 0x2C75A0: ret
	return;
}

void sub_2C75B0(X86Context& ctx, uint8_t* base) {
	// 0x2C75B0: movss xmm0, dword ptr [0x003A358C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A358Cu);
	// 0x2C75B8: movss [0x0060DFD0], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFD0u, ctx.xmm[0].u32[0]);
	// 0x2C75C0: movss xmm0, dword ptr [0x003B0408]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B0408u);
	// 0x2C75C8: movss [0x0060DFD4], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFD4u, ctx.xmm[0].u32[0]);
	// 0x2C75D0: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2C75D8: movss [0x0060DFD8], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFD8u, ctx.xmm[0].u32[0]);
	// 0x2C75E0: movss xmm0, dword ptr [0x003B16D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D8u);
	// 0x2C75E8: movss [0x0060DFDC], xmm0
	X86_MEM_WRITE_u32(base, 0x60DFDCu, ctx.xmm[0].u32[0]);
	// 0x2C75F0: ret
	return;
}

