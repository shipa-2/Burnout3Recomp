#include "x86_recomp_shared.h"

void sub_28FC80(X86Context& ctx, uint8_t* base) {
	// 0x28FC80: movss xmm0, dword ptr [0x0056C290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C290u);
	// 0x28FC88: subss xmm0, [0x0056C218]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C218u);
	// 0x28FC90: movss [0x0056C270], xmm0
	X86_MEM_WRITE_u32(base, 0x56C270u, ctx.xmm[0].u32[0]);
	// 0x28FC98: ret
	return;
}

void sub_28FCA0(X86Context& ctx, uint8_t* base) {
	// 0x28FCA0: movss xmm0, dword ptr [0x0056C270]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C270u);
	// 0x28FCA8: subss xmm0, [0x0056C244]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C244u);
	// 0x28FCB0: movss [0x0056C268], xmm0
	X86_MEM_WRITE_u32(base, 0x56C268u, ctx.xmm[0].u32[0]);
	// 0x28FCB8: ret
	return;
}

void sub_28FCC0(X86Context& ctx, uint8_t* base) {
	// 0x28FCC0: movss xmm0, dword ptr [0x0056C298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C298u);
	// 0x28FCC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28FCD0: movss [0x0056C254], xmm0
	X86_MEM_WRITE_u32(base, 0x56C254u, ctx.xmm[0].u32[0]);
	// 0x28FCD8: ret
	return;
}

void sub_28FCE0(X86Context& ctx, uint8_t* base) {
	// 0x28FCE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28FCE8: movss [0x0056C240], xmm0
	X86_MEM_WRITE_u32(base, 0x56C240u, ctx.xmm[0].u32[0]);
	// 0x28FCF0: ret
	return;
}

void sub_28FD00(X86Context& ctx, uint8_t* base) {
	// 0x28FD00: movss xmm0, dword ptr [0x0056C254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C254u);
	// 0x28FD08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28FD10: movss [0x0056C288], xmm0
	X86_MEM_WRITE_u32(base, 0x56C288u, ctx.xmm[0].u32[0]);
	// 0x28FD18: ret
	return;
}

void sub_28FD20(X86Context& ctx, uint8_t* base) {
	// 0x28FD20: movss xmm0, dword ptr [0x00388E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x28FD28: movss [0x0056C258], xmm0
	X86_MEM_WRITE_u32(base, 0x56C258u, ctx.xmm[0].u32[0]);
	// 0x28FD30: ret
	return;
}

void sub_28FD40(X86Context& ctx, uint8_t* base) {
	// 0x28FD40: movss xmm0, dword ptr [0x0056C258]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C258u);
	// 0x28FD48: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x28FD50: movss [0x0056C234], xmm0
	X86_MEM_WRITE_u32(base, 0x56C234u, ctx.xmm[0].u32[0]);
	// 0x28FD58: ret
	return;
}

void sub_28FD60(X86Context& ctx, uint8_t* base) {
	// 0x28FD60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28FD68: movss [0x0056C30C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C30Cu, ctx.xmm[0].u32[0]);
	// 0x28FD70: ret
	return;
}

void sub_28FD80(X86Context& ctx, uint8_t* base) {
	// 0x28FD80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28FD88: movss [0x0056C328], xmm0
	X86_MEM_WRITE_u32(base, 0x56C328u, ctx.xmm[0].u32[0]);
	// 0x28FD90: ret
	return;
}

void sub_28FDA0(X86Context& ctx, uint8_t* base) {
	// 0x28FDA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28FDA8: movss [0x0056C300], xmm0
	X86_MEM_WRITE_u32(base, 0x56C300u, ctx.xmm[0].u32[0]);
	// 0x28FDB0: ret
	return;
}

void sub_28FDC0(X86Context& ctx, uint8_t* base) {
	// 0x28FDC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28FDC8: movss [0x0056C2B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2B8u, ctx.xmm[0].u32[0]);
	// 0x28FDD0: ret
	return;
}

void sub_28FDE0(X86Context& ctx, uint8_t* base) {
	// 0x28FDE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28FDE8: movss [0x0056C310], xmm0
	X86_MEM_WRITE_u32(base, 0x56C310u, ctx.xmm[0].u32[0]);
	// 0x28FDF0: ret
	return;
}

void sub_28FE00(X86Context& ctx, uint8_t* base) {
	// 0x28FE00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28FE08: movss [0x0056C2D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2D4u, ctx.xmm[0].u32[0]);
	// 0x28FE10: ret
	return;
}

void sub_28FE20(X86Context& ctx, uint8_t* base) {
	// 0x28FE20: movss xmm0, dword ptr [0x0056C310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C310u);
	// 0x28FE28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28FE30: movss [0x0056C348], xmm0
	X86_MEM_WRITE_u32(base, 0x56C348u, ctx.xmm[0].u32[0]);
	// 0x28FE38: ret
	return;
}

void sub_28FE40(X86Context& ctx, uint8_t* base) {
	// 0x28FE40: movss xmm0, dword ptr [0x0056C2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2D4u);
	// 0x28FE48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28FE50: movss [0x0056C330], xmm0
	X86_MEM_WRITE_u32(base, 0x56C330u, ctx.xmm[0].u32[0]);
	// 0x28FE58: ret
	return;
}

void sub_28FE60(X86Context& ctx, uint8_t* base) {
	// 0x28FE60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28FE68: movss [0x0056C360], xmm0
	X86_MEM_WRITE_u32(base, 0x56C360u, ctx.xmm[0].u32[0]);
	// 0x28FE70: ret
	return;
}

void sub_28FE80(X86Context& ctx, uint8_t* base) {
	// 0x28FE80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28FE88: movss [0x0056C34C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C34Cu, ctx.xmm[0].u32[0]);
	// 0x28FE90: ret
	return;
}

void sub_28FEA0(X86Context& ctx, uint8_t* base) {
	// 0x28FEA0: movss xmm0, dword ptr [0x0056C34C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C34Cu);
	// 0x28FEA8: movss [0x0056C35C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C35Cu, ctx.xmm[0].u32[0]);
	// 0x28FEB0: ret
	return;
}

void sub_28FEC0(X86Context& ctx, uint8_t* base) {
	// 0x28FEC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28FEC8: movss [0x0056C2C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2C0u, ctx.xmm[0].u32[0]);
	// 0x28FED0: ret
	return;
}

void sub_28FEE0(X86Context& ctx, uint8_t* base) {
	// 0x28FEE0: movss xmm0, dword ptr [0x0056C2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2D4u);
	// 0x28FEE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28FEF0: movss [0x0056C354], xmm0
	X86_MEM_WRITE_u32(base, 0x56C354u, ctx.xmm[0].u32[0]);
	// 0x28FEF8: ret
	return;
}

void sub_28FF00(X86Context& ctx, uint8_t* base) {
	// 0x28FF00: movss xmm0, dword ptr [0x0056C2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2D4u);
	// 0x28FF08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28FF10: movss [0x0056C2FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2FCu, ctx.xmm[0].u32[0]);
	// 0x28FF18: ret
	return;
}

void sub_28FF20(X86Context& ctx, uint8_t* base) {
	// 0x28FF20: movss xmm0, dword ptr [0x0056C2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2D4u);
	// 0x28FF28: subss xmm0, [0x0056C2FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C2FCu);
	// 0x28FF30: movss [0x0056C2DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2DCu, ctx.xmm[0].u32[0]);
	// 0x28FF38: ret
	return;
}

void sub_28FF40(X86Context& ctx, uint8_t* base) {
	// 0x28FF40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28FF48: movss [0x0056C324], xmm0
	X86_MEM_WRITE_u32(base, 0x56C324u, ctx.xmm[0].u32[0]);
	// 0x28FF50: ret
	return;
}

void sub_28FF60(X86Context& ctx, uint8_t* base) {
	// 0x28FF60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28FF68: movss [0x0056C2D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2D8u, ctx.xmm[0].u32[0]);
	// 0x28FF70: ret
	return;
}

void sub_28FF80(X86Context& ctx, uint8_t* base) {
	// 0x28FF80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28FF88: movss [0x0056C2E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2E8u, ctx.xmm[0].u32[0]);
	// 0x28FF90: ret
	return;
}

void sub_28FFA0(X86Context& ctx, uint8_t* base) {
	// 0x28FFA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28FFA8: movss [0x0056C33C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C33Cu, ctx.xmm[0].u32[0]);
	// 0x28FFB0: ret
	return;
}

void sub_28FFC0(X86Context& ctx, uint8_t* base) {
	// 0x28FFC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28FFC8: movss [0x0056C320], xmm0
	X86_MEM_WRITE_u32(base, 0x56C320u, ctx.xmm[0].u32[0]);
	// 0x28FFD0: ret
	return;
}

void sub_28FFE0(X86Context& ctx, uint8_t* base) {
	// 0x28FFE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28FFE8: movss [0x0056C2D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2D0u, ctx.xmm[0].u32[0]);
	// 0x28FFF0: ret
	return;
}

void sub_290000(X86Context& ctx, uint8_t* base) {
	// 0x290000: movss xmm0, dword ptr [0x0056C2E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2E8u);
	// 0x290008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290010: movss [0x0056C2C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2C4u, ctx.xmm[0].u32[0]);
	// 0x290018: ret
	return;
}

void sub_290020(X86Context& ctx, uint8_t* base) {
	// 0x290020: movss xmm0, dword ptr [0x0056C33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C33Cu);
	// 0x290028: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x290030: movss [0x0056C308], xmm0
	X86_MEM_WRITE_u32(base, 0x56C308u, ctx.xmm[0].u32[0]);
	// 0x290038: ret
	return;
}

void sub_290040(X86Context& ctx, uint8_t* base) {
	// 0x290040: movss xmm0, dword ptr [0x0056C2C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2C4u);
	// 0x290048: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290050: movss [0x0056C318], xmm0
	X86_MEM_WRITE_u32(base, 0x56C318u, ctx.xmm[0].u32[0]);
	// 0x290058: ret
	return;
}

void sub_290060(X86Context& ctx, uint8_t* base) {
	// 0x290060: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x290068: movss [0x0056C2BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2BCu, ctx.xmm[0].u32[0]);
	// 0x290070: ret
	return;
}

void sub_290080(X86Context& ctx, uint8_t* base) {
	// 0x290080: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x290088: movss [0x0056C2EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2ECu, ctx.xmm[0].u32[0]);
	// 0x290090: ret
	return;
}

void sub_2900A0(X86Context& ctx, uint8_t* base) {
	// 0x2900A0: movss xmm0, dword ptr [0x0056C2E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2E8u);
	// 0x2900A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2900B0: movss [0x0056C2F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2F8u, ctx.xmm[0].u32[0]);
	// 0x2900B8: ret
	return;
}

void sub_2900C0(X86Context& ctx, uint8_t* base) {
	// 0x2900C0: movss xmm0, dword ptr [0x0056C33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C33Cu);
	// 0x2900C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2900D0: movss [0x0056C340], xmm0
	X86_MEM_WRITE_u32(base, 0x56C340u, ctx.xmm[0].u32[0]);
	// 0x2900D8: ret
	return;
}

void sub_2900E0(X86Context& ctx, uint8_t* base) {
	// 0x2900E0: movss xmm0, dword ptr [0x0056C2F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2F8u);
	// 0x2900E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2900F0: movss [0x0056C32C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C32Cu, ctx.xmm[0].u32[0]);
	// 0x2900F8: ret
	return;
}

void sub_290100(X86Context& ctx, uint8_t* base) {
	// 0x290100: movss xmm0, dword ptr [0x0056C340]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C340u);
	// 0x290108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290110: movss [0x0056C350], xmm0
	X86_MEM_WRITE_u32(base, 0x56C350u, ctx.xmm[0].u32[0]);
	// 0x290118: ret
	return;
}

void sub_290120(X86Context& ctx, uint8_t* base) {
	// 0x290120: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x290128: movss [0x0056C2C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2C8u, ctx.xmm[0].u32[0]);
	// 0x290130: ret
	return;
}

void sub_290140(X86Context& ctx, uint8_t* base) {
	// 0x290140: movss xmm0, dword ptr [0x0056C2E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2E8u);
	// 0x290148: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290150: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x290158: movss [0x0056C338], xmm0
	X86_MEM_WRITE_u32(base, 0x56C338u, ctx.xmm[0].u32[0]);
	// 0x290160: ret
	return;
}

void sub_290170(X86Context& ctx, uint8_t* base) {
	// 0x290170: movss xmm0, dword ptr [0x0056C33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C33Cu);
	// 0x290178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290180: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x290188: movss [0x0056C2E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2E0u, ctx.xmm[0].u32[0]);
	// 0x290190: ret
	return;
}

void sub_2901A0(X86Context& ctx, uint8_t* base) {
	// 0x2901A0: movss xmm0, dword ptr [0x0056C2E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2E8u);
	// 0x2901A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2901B0: movss [0x0056C2E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2E4u, ctx.xmm[0].u32[0]);
	// 0x2901B8: ret
	return;
}

void sub_2901C0(X86Context& ctx, uint8_t* base) {
	// 0x2901C0: movss xmm0, dword ptr [0x0056C33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C33Cu);
	// 0x2901C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2901D0: movss [0x0056C344], xmm0
	X86_MEM_WRITE_u32(base, 0x56C344u, ctx.xmm[0].u32[0]);
	// 0x2901D8: ret
	return;
}

void sub_2901E0(X86Context& ctx, uint8_t* base) {
	// 0x2901E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2901E8: movss [0x0056C2CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2CCu, ctx.xmm[0].u32[0]);
	// 0x2901F0: ret
	return;
}

void sub_290200(X86Context& ctx, uint8_t* base) {
	// 0x290200: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x290208: movss [0x0056C2F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2F4u, ctx.xmm[0].u32[0]);
	// 0x290210: ret
	return;
}

void sub_290220(X86Context& ctx, uint8_t* base) {
	// 0x290220: movss xmm0, dword ptr [0x0056C2CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2CCu);
	// 0x290228: movss [0x0056C358], xmm0
	X86_MEM_WRITE_u32(base, 0x56C358u, ctx.xmm[0].u32[0]);
	// 0x290230: ret
	return;
}

void sub_290240(X86Context& ctx, uint8_t* base) {
	// 0x290240: movss xmm0, dword ptr [0x0056C33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C33Cu);
	// 0x290248: subss xmm0, [0x0056C2CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C2CCu);
	// 0x290250: movss [0x0056C31C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C31Cu, ctx.xmm[0].u32[0]);
	// 0x290258: ret
	return;
}

void sub_290260(X86Context& ctx, uint8_t* base) {
	// 0x290260: movss xmm0, dword ptr [0x0056C31C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C31Cu);
	// 0x290268: subss xmm0, [0x0056C2F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C2F4u);
	// 0x290270: movss [0x0056C314], xmm0
	X86_MEM_WRITE_u32(base, 0x56C314u, ctx.xmm[0].u32[0]);
	// 0x290278: ret
	return;
}

void sub_290280(X86Context& ctx, uint8_t* base) {
	// 0x290280: movss xmm0, dword ptr [0x0056C344]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C344u);
	// 0x290288: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x290290: movss [0x0056C304], xmm0
	X86_MEM_WRITE_u32(base, 0x56C304u, ctx.xmm[0].u32[0]);
	// 0x290298: ret
	return;
}

void sub_2902A0(X86Context& ctx, uint8_t* base) {
	// 0x2902A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2902A8: movss [0x0056C2F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2F0u, ctx.xmm[0].u32[0]);
	// 0x2902B0: ret
	return;
}

void sub_2902C0(X86Context& ctx, uint8_t* base) {
	// 0x2902C0: movss xmm0, dword ptr [0x0056C304]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C304u);
	// 0x2902C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2902D0: movss [0x0056C334], xmm0
	X86_MEM_WRITE_u32(base, 0x56C334u, ctx.xmm[0].u32[0]);
	// 0x2902D8: ret
	return;
}

void sub_2902E0(X86Context& ctx, uint8_t* base) {
	// 0x2902E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2902E8: movss [0x0056C3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3B8u, ctx.xmm[0].u32[0]);
	// 0x2902F0: ret
	return;
}

void sub_290300(X86Context& ctx, uint8_t* base) {
	// 0x290300: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x290308: movss [0x0056C3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3D4u, ctx.xmm[0].u32[0]);
	// 0x290310: ret
	return;
}

void sub_290320(X86Context& ctx, uint8_t* base) {
	// 0x290320: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x290328: movss [0x0056C3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3ACu, ctx.xmm[0].u32[0]);
	// 0x290330: ret
	return;
}

void sub_290340(X86Context& ctx, uint8_t* base) {
	// 0x290340: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x290348: movss [0x0056C364], xmm0
	X86_MEM_WRITE_u32(base, 0x56C364u, ctx.xmm[0].u32[0]);
	// 0x290350: ret
	return;
}

void sub_290360(X86Context& ctx, uint8_t* base) {
	// 0x290360: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x290368: movss [0x0056C3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3BCu, ctx.xmm[0].u32[0]);
	// 0x290370: ret
	return;
}

void sub_290380(X86Context& ctx, uint8_t* base) {
	// 0x290380: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x290388: movss [0x0056C380], xmm0
	X86_MEM_WRITE_u32(base, 0x56C380u, ctx.xmm[0].u32[0]);
	// 0x290390: ret
	return;
}

void sub_2903A0(X86Context& ctx, uint8_t* base) {
	// 0x2903A0: movss xmm0, dword ptr [0x0056C3BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3BCu);
	// 0x2903A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2903B0: movss [0x0056C3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3F4u, ctx.xmm[0].u32[0]);
	// 0x2903B8: ret
	return;
}

void sub_2903C0(X86Context& ctx, uint8_t* base) {
	// 0x2903C0: movss xmm0, dword ptr [0x0056C380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C380u);
	// 0x2903C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2903D0: movss [0x0056C3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3DCu, ctx.xmm[0].u32[0]);
	// 0x2903D8: ret
	return;
}

void sub_2903E0(X86Context& ctx, uint8_t* base) {
	// 0x2903E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2903E8: movss [0x0056C40C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C40Cu, ctx.xmm[0].u32[0]);
	// 0x2903F0: ret
	return;
}

void sub_290400(X86Context& ctx, uint8_t* base) {
	// 0x290400: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x290408: movss [0x0056C3F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3F8u, ctx.xmm[0].u32[0]);
	// 0x290410: ret
	return;
}

void sub_290420(X86Context& ctx, uint8_t* base) {
	// 0x290420: movss xmm0, dword ptr [0x0056C3F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3F8u);
	// 0x290428: movss [0x0056C408], xmm0
	X86_MEM_WRITE_u32(base, 0x56C408u, ctx.xmm[0].u32[0]);
	// 0x290430: ret
	return;
}

void sub_290440(X86Context& ctx, uint8_t* base) {
	// 0x290440: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x290448: movss [0x0056C36C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C36Cu, ctx.xmm[0].u32[0]);
	// 0x290450: ret
	return;
}

void sub_290460(X86Context& ctx, uint8_t* base) {
	// 0x290460: movss xmm0, dword ptr [0x0056C380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C380u);
	// 0x290468: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x290470: movss [0x0056C400], xmm0
	X86_MEM_WRITE_u32(base, 0x56C400u, ctx.xmm[0].u32[0]);
	// 0x290478: ret
	return;
}

void sub_290480(X86Context& ctx, uint8_t* base) {
	// 0x290480: movss xmm0, dword ptr [0x0056C380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C380u);
	// 0x290488: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x290490: movss [0x0056C3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3A8u, ctx.xmm[0].u32[0]);
	// 0x290498: ret
	return;
}

void sub_2904A0(X86Context& ctx, uint8_t* base) {
	// 0x2904A0: movss xmm0, dword ptr [0x0056C380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C380u);
	// 0x2904A8: subss xmm0, [0x0056C3A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C3A8u);
	// 0x2904B0: movss [0x0056C388], xmm0
	X86_MEM_WRITE_u32(base, 0x56C388u, ctx.xmm[0].u32[0]);
	// 0x2904B8: ret
	return;
}

void sub_2904C0(X86Context& ctx, uint8_t* base) {
	// 0x2904C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2904C8: movss [0x0056C3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3D0u, ctx.xmm[0].u32[0]);
	// 0x2904D0: ret
	return;
}

void sub_2904E0(X86Context& ctx, uint8_t* base) {
	// 0x2904E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2904E8: movss [0x0056C384], xmm0
	X86_MEM_WRITE_u32(base, 0x56C384u, ctx.xmm[0].u32[0]);
	// 0x2904F0: ret
	return;
}

void sub_290500(X86Context& ctx, uint8_t* base) {
	// 0x290500: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x290508: movss [0x0056C394], xmm0
	X86_MEM_WRITE_u32(base, 0x56C394u, ctx.xmm[0].u32[0]);
	// 0x290510: ret
	return;
}

void sub_290520(X86Context& ctx, uint8_t* base) {
	// 0x290520: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x290528: movss [0x0056C3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3E8u, ctx.xmm[0].u32[0]);
	// 0x290530: ret
	return;
}

void sub_290540(X86Context& ctx, uint8_t* base) {
	// 0x290540: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x290548: movss [0x0056C3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3CCu, ctx.xmm[0].u32[0]);
	// 0x290550: ret
	return;
}

void sub_290560(X86Context& ctx, uint8_t* base) {
	// 0x290560: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x290568: movss [0x0056C37C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C37Cu, ctx.xmm[0].u32[0]);
	// 0x290570: ret
	return;
}

void sub_290580(X86Context& ctx, uint8_t* base) {
	// 0x290580: movss xmm0, dword ptr [0x0056C394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C394u);
	// 0x290588: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290590: movss [0x0056C370], xmm0
	X86_MEM_WRITE_u32(base, 0x56C370u, ctx.xmm[0].u32[0]);
	// 0x290598: ret
	return;
}

void sub_2905A0(X86Context& ctx, uint8_t* base) {
	// 0x2905A0: movss xmm0, dword ptr [0x0056C3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3E8u);
	// 0x2905A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2905B0: movss [0x0056C3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3B4u, ctx.xmm[0].u32[0]);
	// 0x2905B8: ret
	return;
}

void sub_2905C0(X86Context& ctx, uint8_t* base) {
	// 0x2905C0: movss xmm0, dword ptr [0x0056C370]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C370u);
	// 0x2905C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2905D0: movss [0x0056C3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3C4u, ctx.xmm[0].u32[0]);
	// 0x2905D8: ret
	return;
}

void sub_2905E0(X86Context& ctx, uint8_t* base) {
	// 0x2905E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2905E8: movss [0x0056C368], xmm0
	X86_MEM_WRITE_u32(base, 0x56C368u, ctx.xmm[0].u32[0]);
	// 0x2905F0: ret
	return;
}

void sub_290600(X86Context& ctx, uint8_t* base) {
	// 0x290600: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x290608: movss [0x0056C398], xmm0
	X86_MEM_WRITE_u32(base, 0x56C398u, ctx.xmm[0].u32[0]);
	// 0x290610: ret
	return;
}

void sub_290620(X86Context& ctx, uint8_t* base) {
	// 0x290620: movss xmm0, dword ptr [0x0056C394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C394u);
	// 0x290628: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x290630: movss [0x0056C3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3A4u, ctx.xmm[0].u32[0]);
	// 0x290638: ret
	return;
}

void sub_290640(X86Context& ctx, uint8_t* base) {
	// 0x290640: movss xmm0, dword ptr [0x0056C3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3E8u);
	// 0x290648: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x290650: movss [0x0056C3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3ECu, ctx.xmm[0].u32[0]);
	// 0x290658: ret
	return;
}

void sub_290660(X86Context& ctx, uint8_t* base) {
	// 0x290660: movss xmm0, dword ptr [0x0056C3A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3A4u);
	// 0x290668: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290670: movss [0x0056C3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3D8u, ctx.xmm[0].u32[0]);
	// 0x290678: ret
	return;
}

void sub_290680(X86Context& ctx, uint8_t* base) {
	// 0x290680: movss xmm0, dword ptr [0x0056C3EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3ECu);
	// 0x290688: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290690: movss [0x0056C3FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3FCu, ctx.xmm[0].u32[0]);
	// 0x290698: ret
	return;
}

void sub_2906A0(X86Context& ctx, uint8_t* base) {
	// 0x2906A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2906A8: movss [0x0056C374], xmm0
	X86_MEM_WRITE_u32(base, 0x56C374u, ctx.xmm[0].u32[0]);
	// 0x2906B0: ret
	return;
}

void sub_2906C0(X86Context& ctx, uint8_t* base) {
	// 0x2906C0: movss xmm0, dword ptr [0x0056C394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C394u);
	// 0x2906C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2906D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2906D8: movss [0x0056C3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3E4u, ctx.xmm[0].u32[0]);
	// 0x2906E0: ret
	return;
}

void sub_2906F0(X86Context& ctx, uint8_t* base) {
	// 0x2906F0: movss xmm0, dword ptr [0x0056C3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3E8u);
	// 0x2906F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290700: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x290708: movss [0x0056C38C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C38Cu, ctx.xmm[0].u32[0]);
	// 0x290710: ret
	return;
}

void sub_290720(X86Context& ctx, uint8_t* base) {
	// 0x290720: movss xmm0, dword ptr [0x0056C394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C394u);
	// 0x290728: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290730: movss [0x0056C390], xmm0
	X86_MEM_WRITE_u32(base, 0x56C390u, ctx.xmm[0].u32[0]);
	// 0x290738: ret
	return;
}

void sub_290740(X86Context& ctx, uint8_t* base) {
	// 0x290740: movss xmm0, dword ptr [0x0056C3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3E8u);
	// 0x290748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290750: movss [0x0056C3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3F0u, ctx.xmm[0].u32[0]);
	// 0x290758: ret
	return;
}

void sub_290760(X86Context& ctx, uint8_t* base) {
	// 0x290760: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x290768: movss [0x0056C378], xmm0
	X86_MEM_WRITE_u32(base, 0x56C378u, ctx.xmm[0].u32[0]);
	// 0x290770: ret
	return;
}

void sub_290780(X86Context& ctx, uint8_t* base) {
	// 0x290780: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x290788: movss [0x0056C3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3A0u, ctx.xmm[0].u32[0]);
	// 0x290790: ret
	return;
}

void sub_2907A0(X86Context& ctx, uint8_t* base) {
	// 0x2907A0: movss xmm0, dword ptr [0x0056C378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C378u);
	// 0x2907A8: movss [0x0056C404], xmm0
	X86_MEM_WRITE_u32(base, 0x56C404u, ctx.xmm[0].u32[0]);
	// 0x2907B0: ret
	return;
}

void sub_2907C0(X86Context& ctx, uint8_t* base) {
	// 0x2907C0: movss xmm0, dword ptr [0x0056C3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3E8u);
	// 0x2907C8: subss xmm0, [0x0056C378]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C378u);
	// 0x2907D0: movss [0x0056C3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3C8u, ctx.xmm[0].u32[0]);
	// 0x2907D8: ret
	return;
}

void sub_2907E0(X86Context& ctx, uint8_t* base) {
	// 0x2907E0: movss xmm0, dword ptr [0x0056C3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3C8u);
	// 0x2907E8: subss xmm0, [0x0056C3A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C3A0u);
	// 0x2907F0: movss [0x0056C3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3C0u, ctx.xmm[0].u32[0]);
	// 0x2907F8: ret
	return;
}

void sub_290800(X86Context& ctx, uint8_t* base) {
	// 0x290800: movss xmm0, dword ptr [0x0056C3F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3F0u);
	// 0x290808: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x290810: movss [0x0056C3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3B0u, ctx.xmm[0].u32[0]);
	// 0x290818: ret
	return;
}

void sub_290820(X86Context& ctx, uint8_t* base) {
	// 0x290820: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x290828: movss [0x0056C39C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C39Cu, ctx.xmm[0].u32[0]);
	// 0x290830: ret
	return;
}

void sub_290840(X86Context& ctx, uint8_t* base) {
	// 0x290840: movss xmm0, dword ptr [0x0056C3B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C3B0u);
	// 0x290848: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x290850: movss [0x0056C3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C3E0u, ctx.xmm[0].u32[0]);
	// 0x290858: ret
	return;
}

void sub_290860(X86Context& ctx, uint8_t* base) {
	// 0x290860: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x290868: movss [0x0056C464], xmm0
	X86_MEM_WRITE_u32(base, 0x56C464u, ctx.xmm[0].u32[0]);
	// 0x290870: ret
	return;
}

void sub_290880(X86Context& ctx, uint8_t* base) {
	// 0x290880: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x290888: movss [0x0056C480], xmm0
	X86_MEM_WRITE_u32(base, 0x56C480u, ctx.xmm[0].u32[0]);
	// 0x290890: ret
	return;
}

void sub_2908A0(X86Context& ctx, uint8_t* base) {
	// 0x2908A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2908A8: movss [0x0056C458], xmm0
	X86_MEM_WRITE_u32(base, 0x56C458u, ctx.xmm[0].u32[0]);
	// 0x2908B0: ret
	return;
}

void sub_2908C0(X86Context& ctx, uint8_t* base) {
	// 0x2908C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2908C8: movss [0x0056C410], xmm0
	X86_MEM_WRITE_u32(base, 0x56C410u, ctx.xmm[0].u32[0]);
	// 0x2908D0: ret
	return;
}

void sub_2908E0(X86Context& ctx, uint8_t* base) {
	// 0x2908E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2908E8: movss [0x0056C468], xmm0
	X86_MEM_WRITE_u32(base, 0x56C468u, ctx.xmm[0].u32[0]);
	// 0x2908F0: ret
	return;
}

void sub_290900(X86Context& ctx, uint8_t* base) {
	// 0x290900: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x290908: movss [0x0056C42C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C42Cu, ctx.xmm[0].u32[0]);
	// 0x290910: ret
	return;
}

void sub_290920(X86Context& ctx, uint8_t* base) {
	// 0x290920: movss xmm0, dword ptr [0x0056C468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C468u);
	// 0x290928: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290930: movss [0x0056C4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4A0u, ctx.xmm[0].u32[0]);
	// 0x290938: ret
	return;
}

void sub_290940(X86Context& ctx, uint8_t* base) {
	// 0x290940: movss xmm0, dword ptr [0x0056C42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C42Cu);
	// 0x290948: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x290950: movss [0x0056C488], xmm0
	X86_MEM_WRITE_u32(base, 0x56C488u, ctx.xmm[0].u32[0]);
	// 0x290958: ret
	return;
}

void sub_290960(X86Context& ctx, uint8_t* base) {
	// 0x290960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x290968: movss [0x0056C4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4B8u, ctx.xmm[0].u32[0]);
	// 0x290970: ret
	return;
}

void sub_290980(X86Context& ctx, uint8_t* base) {
	// 0x290980: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x290988: movss [0x0056C4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4A4u, ctx.xmm[0].u32[0]);
	// 0x290990: ret
	return;
}

void sub_2909A0(X86Context& ctx, uint8_t* base) {
	// 0x2909A0: movss xmm0, dword ptr [0x0056C4A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4A4u);
	// 0x2909A8: movss [0x0056C4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4B4u, ctx.xmm[0].u32[0]);
	// 0x2909B0: ret
	return;
}

void sub_2909C0(X86Context& ctx, uint8_t* base) {
	// 0x2909C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2909C8: movss [0x0056C418], xmm0
	X86_MEM_WRITE_u32(base, 0x56C418u, ctx.xmm[0].u32[0]);
	// 0x2909D0: ret
	return;
}

void sub_2909E0(X86Context& ctx, uint8_t* base) {
	// 0x2909E0: movss xmm0, dword ptr [0x0056C42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C42Cu);
	// 0x2909E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2909F0: movss [0x0056C4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4ACu, ctx.xmm[0].u32[0]);
	// 0x2909F8: ret
	return;
}

void sub_290A00(X86Context& ctx, uint8_t* base) {
	// 0x290A00: movss xmm0, dword ptr [0x0056C42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C42Cu);
	// 0x290A08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x290A10: movss [0x0056C454], xmm0
	X86_MEM_WRITE_u32(base, 0x56C454u, ctx.xmm[0].u32[0]);
	// 0x290A18: ret
	return;
}

void sub_290A20(X86Context& ctx, uint8_t* base) {
	// 0x290A20: movss xmm0, dword ptr [0x0056C42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C42Cu);
	// 0x290A28: subss xmm0, [0x0056C454]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C454u);
	// 0x290A30: movss [0x0056C434], xmm0
	X86_MEM_WRITE_u32(base, 0x56C434u, ctx.xmm[0].u32[0]);
	// 0x290A38: ret
	return;
}

void sub_290A40(X86Context& ctx, uint8_t* base) {
	// 0x290A40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x290A48: movss [0x0056C47C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C47Cu, ctx.xmm[0].u32[0]);
	// 0x290A50: ret
	return;
}

void sub_290A60(X86Context& ctx, uint8_t* base) {
	// 0x290A60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x290A68: movss [0x0056C430], xmm0
	X86_MEM_WRITE_u32(base, 0x56C430u, ctx.xmm[0].u32[0]);
	// 0x290A70: ret
	return;
}

void sub_290A80(X86Context& ctx, uint8_t* base) {
	// 0x290A80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x290A88: movss [0x0056C440], xmm0
	X86_MEM_WRITE_u32(base, 0x56C440u, ctx.xmm[0].u32[0]);
	// 0x290A90: ret
	return;
}

void sub_290AA0(X86Context& ctx, uint8_t* base) {
	// 0x290AA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x290AA8: movss [0x0056C494], xmm0
	X86_MEM_WRITE_u32(base, 0x56C494u, ctx.xmm[0].u32[0]);
	// 0x290AB0: ret
	return;
}

void sub_290AC0(X86Context& ctx, uint8_t* base) {
	// 0x290AC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x290AC8: movss [0x0056C478], xmm0
	X86_MEM_WRITE_u32(base, 0x56C478u, ctx.xmm[0].u32[0]);
	// 0x290AD0: ret
	return;
}

void sub_290AE0(X86Context& ctx, uint8_t* base) {
	// 0x290AE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x290AE8: movss [0x0056C428], xmm0
	X86_MEM_WRITE_u32(base, 0x56C428u, ctx.xmm[0].u32[0]);
	// 0x290AF0: ret
	return;
}

void sub_290B00(X86Context& ctx, uint8_t* base) {
	// 0x290B00: movss xmm0, dword ptr [0x0056C440]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C440u);
	// 0x290B08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290B10: movss [0x0056C41C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C41Cu, ctx.xmm[0].u32[0]);
	// 0x290B18: ret
	return;
}

void sub_290B20(X86Context& ctx, uint8_t* base) {
	// 0x290B20: movss xmm0, dword ptr [0x0056C494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C494u);
	// 0x290B28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x290B30: movss [0x0056C460], xmm0
	X86_MEM_WRITE_u32(base, 0x56C460u, ctx.xmm[0].u32[0]);
	// 0x290B38: ret
	return;
}

void sub_290B40(X86Context& ctx, uint8_t* base) {
	// 0x290B40: movss xmm0, dword ptr [0x0056C41C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C41Cu);
	// 0x290B48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290B50: movss [0x0056C470], xmm0
	X86_MEM_WRITE_u32(base, 0x56C470u, ctx.xmm[0].u32[0]);
	// 0x290B58: ret
	return;
}

void sub_290B60(X86Context& ctx, uint8_t* base) {
	// 0x290B60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x290B68: movss [0x0056C414], xmm0
	X86_MEM_WRITE_u32(base, 0x56C414u, ctx.xmm[0].u32[0]);
	// 0x290B70: ret
	return;
}

void sub_290B80(X86Context& ctx, uint8_t* base) {
	// 0x290B80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x290B88: movss [0x0056C444], xmm0
	X86_MEM_WRITE_u32(base, 0x56C444u, ctx.xmm[0].u32[0]);
	// 0x290B90: ret
	return;
}

void sub_290BA0(X86Context& ctx, uint8_t* base) {
	// 0x290BA0: movss xmm0, dword ptr [0x0056C440]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C440u);
	// 0x290BA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x290BB0: movss [0x0056C450], xmm0
	X86_MEM_WRITE_u32(base, 0x56C450u, ctx.xmm[0].u32[0]);
	// 0x290BB8: ret
	return;
}

void sub_290BC0(X86Context& ctx, uint8_t* base) {
	// 0x290BC0: movss xmm0, dword ptr [0x0056C494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C494u);
	// 0x290BC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x290BD0: movss [0x0056C498], xmm0
	X86_MEM_WRITE_u32(base, 0x56C498u, ctx.xmm[0].u32[0]);
	// 0x290BD8: ret
	return;
}

void sub_290BE0(X86Context& ctx, uint8_t* base) {
	// 0x290BE0: movss xmm0, dword ptr [0x0056C450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C450u);
	// 0x290BE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290BF0: movss [0x0056C484], xmm0
	X86_MEM_WRITE_u32(base, 0x56C484u, ctx.xmm[0].u32[0]);
	// 0x290BF8: ret
	return;
}

void sub_290C00(X86Context& ctx, uint8_t* base) {
	// 0x290C00: movss xmm0, dword ptr [0x0056C498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C498u);
	// 0x290C08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290C10: movss [0x0056C4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4A8u, ctx.xmm[0].u32[0]);
	// 0x290C18: ret
	return;
}

void sub_290C20(X86Context& ctx, uint8_t* base) {
	// 0x290C20: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x290C28: movss [0x0056C420], xmm0
	X86_MEM_WRITE_u32(base, 0x56C420u, ctx.xmm[0].u32[0]);
	// 0x290C30: ret
	return;
}

void sub_290C40(X86Context& ctx, uint8_t* base) {
	// 0x290C40: movss xmm0, dword ptr [0x0056C440]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C440u);
	// 0x290C48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290C50: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x290C58: movss [0x0056C490], xmm0
	X86_MEM_WRITE_u32(base, 0x56C490u, ctx.xmm[0].u32[0]);
	// 0x290C60: ret
	return;
}

void sub_290C70(X86Context& ctx, uint8_t* base) {
	// 0x290C70: movss xmm0, dword ptr [0x0056C494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C494u);
	// 0x290C78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290C80: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x290C88: movss [0x0056C438], xmm0
	X86_MEM_WRITE_u32(base, 0x56C438u, ctx.xmm[0].u32[0]);
	// 0x290C90: ret
	return;
}

void sub_290CA0(X86Context& ctx, uint8_t* base) {
	// 0x290CA0: movss xmm0, dword ptr [0x0056C440]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C440u);
	// 0x290CA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290CB0: movss [0x0056C43C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C43Cu, ctx.xmm[0].u32[0]);
	// 0x290CB8: ret
	return;
}

void sub_290CC0(X86Context& ctx, uint8_t* base) {
	// 0x290CC0: movss xmm0, dword ptr [0x0056C494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C494u);
	// 0x290CC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x290CD0: movss [0x0056C49C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C49Cu, ctx.xmm[0].u32[0]);
	// 0x290CD8: ret
	return;
}

void sub_290CE0(X86Context& ctx, uint8_t* base) {
	// 0x290CE0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x290CE8: movss [0x0056C424], xmm0
	X86_MEM_WRITE_u32(base, 0x56C424u, ctx.xmm[0].u32[0]);
	// 0x290CF0: ret
	return;
}

void sub_290D00(X86Context& ctx, uint8_t* base) {
	// 0x290D00: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x290D08: movss [0x0056C44C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C44Cu, ctx.xmm[0].u32[0]);
	// 0x290D10: ret
	return;
}

void sub_290D20(X86Context& ctx, uint8_t* base) {
	// 0x290D20: movss xmm0, dword ptr [0x0056C424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C424u);
	// 0x290D28: movss [0x0056C4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4B0u, ctx.xmm[0].u32[0]);
	// 0x290D30: ret
	return;
}

void sub_290D40(X86Context& ctx, uint8_t* base) {
	// 0x290D40: movss xmm0, dword ptr [0x0056C494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C494u);
	// 0x290D48: subss xmm0, [0x0056C424]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C424u);
	// 0x290D50: movss [0x0056C474], xmm0
	X86_MEM_WRITE_u32(base, 0x56C474u, ctx.xmm[0].u32[0]);
	// 0x290D58: ret
	return;
}

void sub_290D60(X86Context& ctx, uint8_t* base) {
	// 0x290D60: movss xmm0, dword ptr [0x0056C474]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C474u);
	// 0x290D68: subss xmm0, [0x0056C44C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C44Cu);
	// 0x290D70: movss [0x0056C46C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C46Cu, ctx.xmm[0].u32[0]);
	// 0x290D78: ret
	return;
}

void sub_290D80(X86Context& ctx, uint8_t* base) {
	// 0x290D80: movss xmm0, dword ptr [0x0056C49C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C49Cu);
	// 0x290D88: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x290D90: movss [0x0056C45C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C45Cu, ctx.xmm[0].u32[0]);
	// 0x290D98: ret
	return;
}

void sub_290DA0(X86Context& ctx, uint8_t* base) {
	// 0x290DA0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x290DA8: movss [0x0056C448], xmm0
	X86_MEM_WRITE_u32(base, 0x56C448u, ctx.xmm[0].u32[0]);
	// 0x290DB0: ret
	return;
}

void sub_290DC0(X86Context& ctx, uint8_t* base) {
	// 0x290DC0: movss xmm0, dword ptr [0x0056C45C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C45Cu);
	// 0x290DC8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x290DD0: movss [0x0056C48C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C48Cu, ctx.xmm[0].u32[0]);
	// 0x290DD8: ret
	return;
}

void sub_290DE0(X86Context& ctx, uint8_t* base) {
	// 0x290DE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x290DE8: movss [0x0056C510], xmm0
	X86_MEM_WRITE_u32(base, 0x56C510u, ctx.xmm[0].u32[0]);
	// 0x290DF0: ret
	return;
}

void sub_290E00(X86Context& ctx, uint8_t* base) {
	// 0x290E00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x290E08: movss [0x0056C52C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C52Cu, ctx.xmm[0].u32[0]);
	// 0x290E10: ret
	return;
}

void sub_290E20(X86Context& ctx, uint8_t* base) {
	// 0x290E20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x290E28: movss [0x0056C504], xmm0
	X86_MEM_WRITE_u32(base, 0x56C504u, ctx.xmm[0].u32[0]);
	// 0x290E30: ret
	return;
}

void sub_290E40(X86Context& ctx, uint8_t* base) {
	// 0x290E40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x290E48: movss [0x0056C4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4BCu, ctx.xmm[0].u32[0]);
	// 0x290E50: ret
	return;
}

void sub_290E60(X86Context& ctx, uint8_t* base) {
	// 0x290E60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x290E68: movss [0x0056C514], xmm0
	X86_MEM_WRITE_u32(base, 0x56C514u, ctx.xmm[0].u32[0]);
	// 0x290E70: ret
	return;
}

void sub_290E80(X86Context& ctx, uint8_t* base) {
	// 0x290E80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x290E88: movss [0x0056C4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4D8u, ctx.xmm[0].u32[0]);
	// 0x290E90: ret
	return;
}

void sub_290EA0(X86Context& ctx, uint8_t* base) {
	// 0x290EA0: movss xmm0, dword ptr [0x0056C514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C514u);
	// 0x290EA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x290EB0: movss [0x0056C54C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C54Cu, ctx.xmm[0].u32[0]);
	// 0x290EB8: ret
	return;
}

void sub_290EC0(X86Context& ctx, uint8_t* base) {
	// 0x290EC0: movss xmm0, dword ptr [0x0056C4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4D8u);
	// 0x290EC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x290ED0: movss [0x0056C534], xmm0
	X86_MEM_WRITE_u32(base, 0x56C534u, ctx.xmm[0].u32[0]);
	// 0x290ED8: ret
	return;
}

void sub_290EE0(X86Context& ctx, uint8_t* base) {
	// 0x290EE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x290EE8: movss [0x0056C564], xmm0
	X86_MEM_WRITE_u32(base, 0x56C564u, ctx.xmm[0].u32[0]);
	// 0x290EF0: ret
	return;
}

void sub_290F00(X86Context& ctx, uint8_t* base) {
	// 0x290F00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x290F08: movss [0x0056C550], xmm0
	X86_MEM_WRITE_u32(base, 0x56C550u, ctx.xmm[0].u32[0]);
	// 0x290F10: ret
	return;
}

void sub_290F20(X86Context& ctx, uint8_t* base) {
	// 0x290F20: movss xmm0, dword ptr [0x0056C550]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C550u);
	// 0x290F28: movss [0x0056C560], xmm0
	X86_MEM_WRITE_u32(base, 0x56C560u, ctx.xmm[0].u32[0]);
	// 0x290F30: ret
	return;
}

void sub_290F40(X86Context& ctx, uint8_t* base) {
	// 0x290F40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x290F48: movss [0x0056C4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4C4u, ctx.xmm[0].u32[0]);
	// 0x290F50: ret
	return;
}

void sub_290F60(X86Context& ctx, uint8_t* base) {
	// 0x290F60: movss xmm0, dword ptr [0x0056C4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4D8u);
	// 0x290F68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x290F70: movss [0x0056C558], xmm0
	X86_MEM_WRITE_u32(base, 0x56C558u, ctx.xmm[0].u32[0]);
	// 0x290F78: ret
	return;
}

void sub_290F80(X86Context& ctx, uint8_t* base) {
	// 0x290F80: movss xmm0, dword ptr [0x0056C4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4D8u);
	// 0x290F88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x290F90: movss [0x0056C500], xmm0
	X86_MEM_WRITE_u32(base, 0x56C500u, ctx.xmm[0].u32[0]);
	// 0x290F98: ret
	return;
}

void sub_290FA0(X86Context& ctx, uint8_t* base) {
	// 0x290FA0: movss xmm0, dword ptr [0x0056C4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4D8u);
	// 0x290FA8: subss xmm0, [0x0056C500]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C500u);
	// 0x290FB0: movss [0x0056C4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4E0u, ctx.xmm[0].u32[0]);
	// 0x290FB8: ret
	return;
}

void sub_290FC0(X86Context& ctx, uint8_t* base) {
	// 0x290FC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x290FC8: movss [0x0056C528], xmm0
	X86_MEM_WRITE_u32(base, 0x56C528u, ctx.xmm[0].u32[0]);
	// 0x290FD0: ret
	return;
}

void sub_290FE0(X86Context& ctx, uint8_t* base) {
	// 0x290FE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x290FE8: movss [0x0056C4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4DCu, ctx.xmm[0].u32[0]);
	// 0x290FF0: ret
	return;
}

void sub_291000(X86Context& ctx, uint8_t* base) {
	// 0x291000: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x291008: movss [0x0056C4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4ECu, ctx.xmm[0].u32[0]);
	// 0x291010: ret
	return;
}

void sub_291020(X86Context& ctx, uint8_t* base) {
	// 0x291020: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x291028: movss [0x0056C540], xmm0
	X86_MEM_WRITE_u32(base, 0x56C540u, ctx.xmm[0].u32[0]);
	// 0x291030: ret
	return;
}

void sub_291040(X86Context& ctx, uint8_t* base) {
	// 0x291040: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x291048: movss [0x0056C524], xmm0
	X86_MEM_WRITE_u32(base, 0x56C524u, ctx.xmm[0].u32[0]);
	// 0x291050: ret
	return;
}

void sub_291060(X86Context& ctx, uint8_t* base) {
	// 0x291060: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x291068: movss [0x0056C4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4D4u, ctx.xmm[0].u32[0]);
	// 0x291070: ret
	return;
}

void sub_291080(X86Context& ctx, uint8_t* base) {
	// 0x291080: movss xmm0, dword ptr [0x0056C4EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4ECu);
	// 0x291088: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291090: movss [0x0056C4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4C8u, ctx.xmm[0].u32[0]);
	// 0x291098: ret
	return;
}

void sub_2910A0(X86Context& ctx, uint8_t* base) {
	// 0x2910A0: movss xmm0, dword ptr [0x0056C540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C540u);
	// 0x2910A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2910B0: movss [0x0056C50C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C50Cu, ctx.xmm[0].u32[0]);
	// 0x2910B8: ret
	return;
}

void sub_2910C0(X86Context& ctx, uint8_t* base) {
	// 0x2910C0: movss xmm0, dword ptr [0x0056C4C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4C8u);
	// 0x2910C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2910D0: movss [0x0056C51C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C51Cu, ctx.xmm[0].u32[0]);
	// 0x2910D8: ret
	return;
}

void sub_2910E0(X86Context& ctx, uint8_t* base) {
	// 0x2910E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2910E8: movss [0x0056C4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4C0u, ctx.xmm[0].u32[0]);
	// 0x2910F0: ret
	return;
}

void sub_291100(X86Context& ctx, uint8_t* base) {
	// 0x291100: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x291108: movss [0x0056C4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4F0u, ctx.xmm[0].u32[0]);
	// 0x291110: ret
	return;
}

void sub_291120(X86Context& ctx, uint8_t* base) {
	// 0x291120: movss xmm0, dword ptr [0x0056C4EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4ECu);
	// 0x291128: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x291130: movss [0x0056C4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4FCu, ctx.xmm[0].u32[0]);
	// 0x291138: ret
	return;
}

void sub_291140(X86Context& ctx, uint8_t* base) {
	// 0x291140: movss xmm0, dword ptr [0x0056C540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C540u);
	// 0x291148: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x291150: movss [0x0056C544], xmm0
	X86_MEM_WRITE_u32(base, 0x56C544u, ctx.xmm[0].u32[0]);
	// 0x291158: ret
	return;
}

void sub_291160(X86Context& ctx, uint8_t* base) {
	// 0x291160: movss xmm0, dword ptr [0x0056C4FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4FCu);
	// 0x291168: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291170: movss [0x0056C530], xmm0
	X86_MEM_WRITE_u32(base, 0x56C530u, ctx.xmm[0].u32[0]);
	// 0x291178: ret
	return;
}

void sub_291180(X86Context& ctx, uint8_t* base) {
	// 0x291180: movss xmm0, dword ptr [0x0056C544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C544u);
	// 0x291188: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291190: movss [0x0056C554], xmm0
	X86_MEM_WRITE_u32(base, 0x56C554u, ctx.xmm[0].u32[0]);
	// 0x291198: ret
	return;
}

void sub_2911A0(X86Context& ctx, uint8_t* base) {
	// 0x2911A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2911A8: movss [0x0056C4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4CCu, ctx.xmm[0].u32[0]);
	// 0x2911B0: ret
	return;
}

void sub_2911C0(X86Context& ctx, uint8_t* base) {
	// 0x2911C0: movss xmm0, dword ptr [0x0056C4EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4ECu);
	// 0x2911C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2911D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2911D8: movss [0x0056C53C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C53Cu, ctx.xmm[0].u32[0]);
	// 0x2911E0: ret
	return;
}

void sub_2911F0(X86Context& ctx, uint8_t* base) {
	// 0x2911F0: movss xmm0, dword ptr [0x0056C540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C540u);
	// 0x2911F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291200: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x291208: movss [0x0056C4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4E4u, ctx.xmm[0].u32[0]);
	// 0x291210: ret
	return;
}

void sub_291220(X86Context& ctx, uint8_t* base) {
	// 0x291220: movss xmm0, dword ptr [0x0056C4EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4ECu);
	// 0x291228: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291230: movss [0x0056C4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4E8u, ctx.xmm[0].u32[0]);
	// 0x291238: ret
	return;
}

void sub_291240(X86Context& ctx, uint8_t* base) {
	// 0x291240: movss xmm0, dword ptr [0x0056C540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C540u);
	// 0x291248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291250: movss [0x0056C548], xmm0
	X86_MEM_WRITE_u32(base, 0x56C548u, ctx.xmm[0].u32[0]);
	// 0x291258: ret
	return;
}

void sub_291260(X86Context& ctx, uint8_t* base) {
	// 0x291260: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x291268: movss [0x0056C4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4D0u, ctx.xmm[0].u32[0]);
	// 0x291270: ret
	return;
}

void sub_291280(X86Context& ctx, uint8_t* base) {
	// 0x291280: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x291288: movss [0x0056C4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4F8u, ctx.xmm[0].u32[0]);
	// 0x291290: ret
	return;
}

void sub_2912A0(X86Context& ctx, uint8_t* base) {
	// 0x2912A0: movss xmm0, dword ptr [0x0056C4D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C4D0u);
	// 0x2912A8: movss [0x0056C55C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C55Cu, ctx.xmm[0].u32[0]);
	// 0x2912B0: ret
	return;
}

void sub_2912C0(X86Context& ctx, uint8_t* base) {
	// 0x2912C0: movss xmm0, dword ptr [0x0056C540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C540u);
	// 0x2912C8: subss xmm0, [0x0056C4D0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C4D0u);
	// 0x2912D0: movss [0x0056C520], xmm0
	X86_MEM_WRITE_u32(base, 0x56C520u, ctx.xmm[0].u32[0]);
	// 0x2912D8: ret
	return;
}

void sub_2912E0(X86Context& ctx, uint8_t* base) {
	// 0x2912E0: movss xmm0, dword ptr [0x0056C520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C520u);
	// 0x2912E8: subss xmm0, [0x0056C4F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C4F8u);
	// 0x2912F0: movss [0x0056C518], xmm0
	X86_MEM_WRITE_u32(base, 0x56C518u, ctx.xmm[0].u32[0]);
	// 0x2912F8: ret
	return;
}

void sub_291300(X86Context& ctx, uint8_t* base) {
	// 0x291300: movss xmm0, dword ptr [0x0056C548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C548u);
	// 0x291308: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x291310: movss [0x0056C508], xmm0
	X86_MEM_WRITE_u32(base, 0x56C508u, ctx.xmm[0].u32[0]);
	// 0x291318: ret
	return;
}

void sub_291320(X86Context& ctx, uint8_t* base) {
	// 0x291320: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x291328: movss [0x0056C4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C4F4u, ctx.xmm[0].u32[0]);
	// 0x291330: ret
	return;
}

void sub_291340(X86Context& ctx, uint8_t* base) {
	// 0x291340: movss xmm0, dword ptr [0x0056C508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C508u);
	// 0x291348: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x291350: movss [0x0056C538], xmm0
	X86_MEM_WRITE_u32(base, 0x56C538u, ctx.xmm[0].u32[0]);
	// 0x291358: ret
	return;
}

void sub_291360(X86Context& ctx, uint8_t* base) {
	// 0x291360: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x291368: movss [0x0056C5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5CCu, ctx.xmm[0].u32[0]);
	// 0x291370: ret
	return;
}

void sub_291380(X86Context& ctx, uint8_t* base) {
	// 0x291380: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x291388: movss [0x0056C5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5E8u, ctx.xmm[0].u32[0]);
	// 0x291390: ret
	return;
}

void sub_2913A0(X86Context& ctx, uint8_t* base) {
	// 0x2913A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2913A8: movss [0x0056C5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5B8u, ctx.xmm[0].u32[0]);
	// 0x2913B0: ret
	return;
}

void sub_2913C0(X86Context& ctx, uint8_t* base) {
	// 0x2913C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2913C8: movss [0x0056C568], xmm0
	X86_MEM_WRITE_u32(base, 0x56C568u, ctx.xmm[0].u32[0]);
	// 0x2913D0: ret
	return;
}

void sub_2913E0(X86Context& ctx, uint8_t* base) {
	// 0x2913E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2913E8: movss [0x0056C5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5D0u, ctx.xmm[0].u32[0]);
	// 0x2913F0: ret
	return;
}

void sub_291400(X86Context& ctx, uint8_t* base) {
	// 0x291400: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x291408: movss [0x0056C588], xmm0
	X86_MEM_WRITE_u32(base, 0x56C588u, ctx.xmm[0].u32[0]);
	// 0x291410: ret
	return;
}

void sub_291420(X86Context& ctx, uint8_t* base) {
	// 0x291420: movss xmm0, dword ptr [0x0056C5D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5D0u);
	// 0x291428: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291430: movss [0x0056C608], xmm0
	X86_MEM_WRITE_u32(base, 0x56C608u, ctx.xmm[0].u32[0]);
	// 0x291438: ret
	return;
}

void sub_291440(X86Context& ctx, uint8_t* base) {
	// 0x291440: movss xmm0, dword ptr [0x0056C588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C588u);
	// 0x291448: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x291450: movss [0x0056C5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5F0u, ctx.xmm[0].u32[0]);
	// 0x291458: ret
	return;
}

void sub_291460(X86Context& ctx, uint8_t* base) {
	// 0x291460: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x291468: movss [0x0056C620], xmm0
	X86_MEM_WRITE_u32(base, 0x56C620u, ctx.xmm[0].u32[0]);
	// 0x291470: ret
	return;
}

void sub_291480(X86Context& ctx, uint8_t* base) {
	// 0x291480: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x291488: movss [0x0056C60C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C60Cu, ctx.xmm[0].u32[0]);
	// 0x291490: ret
	return;
}

void sub_2914A0(X86Context& ctx, uint8_t* base) {
	// 0x2914A0: movss xmm0, dword ptr [0x0056C60C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C60Cu);
	// 0x2914A8: movss [0x0056C61C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C61Cu, ctx.xmm[0].u32[0]);
	// 0x2914B0: ret
	return;
}

void sub_2914C0(X86Context& ctx, uint8_t* base) {
	// 0x2914C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2914C8: movss [0x0056C574], xmm0
	X86_MEM_WRITE_u32(base, 0x56C574u, ctx.xmm[0].u32[0]);
	// 0x2914D0: ret
	return;
}

void sub_2914E0(X86Context& ctx, uint8_t* base) {
	// 0x2914E0: movss xmm0, dword ptr [0x0056C588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C588u);
	// 0x2914E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2914F0: movss [0x0056C614], xmm0
	X86_MEM_WRITE_u32(base, 0x56C614u, ctx.xmm[0].u32[0]);
	// 0x2914F8: ret
	return;
}

void sub_291500(X86Context& ctx, uint8_t* base) {
	// 0x291500: movss xmm0, dword ptr [0x0056C588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C588u);
	// 0x291508: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x291510: movss [0x0056C5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5B4u, ctx.xmm[0].u32[0]);
	// 0x291518: ret
	return;
}

void sub_291520(X86Context& ctx, uint8_t* base) {
	// 0x291520: movss xmm0, dword ptr [0x0056C588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C588u);
	// 0x291528: subss xmm0, [0x0056C5B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C5B4u);
	// 0x291530: movss [0x0056C590], xmm0
	X86_MEM_WRITE_u32(base, 0x56C590u, ctx.xmm[0].u32[0]);
	// 0x291538: ret
	return;
}

void sub_291540(X86Context& ctx, uint8_t* base) {
	// 0x291540: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x291548: movss [0x0056C5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5E4u, ctx.xmm[0].u32[0]);
	// 0x291550: ret
	return;
}

void sub_291560(X86Context& ctx, uint8_t* base) {
	// 0x291560: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x291568: movss [0x0056C58C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C58Cu, ctx.xmm[0].u32[0]);
	// 0x291570: ret
	return;
}

void sub_291580(X86Context& ctx, uint8_t* base) {
	// 0x291580: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x291588: movss [0x0056C5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5A0u, ctx.xmm[0].u32[0]);
	// 0x291590: ret
	return;
}

void sub_2915A0(X86Context& ctx, uint8_t* base) {
	// 0x2915A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2915A8: movss [0x0056C5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5FCu, ctx.xmm[0].u32[0]);
	// 0x2915B0: ret
	return;
}

void sub_2915C0(X86Context& ctx, uint8_t* base) {
	// 0x2915C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2915C8: movss [0x0056C5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5E0u, ctx.xmm[0].u32[0]);
	// 0x2915D0: ret
	return;
}

void sub_2915E0(X86Context& ctx, uint8_t* base) {
	// 0x2915E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2915E8: movss [0x0056C584], xmm0
	X86_MEM_WRITE_u32(base, 0x56C584u, ctx.xmm[0].u32[0]);
	// 0x2915F0: ret
	return;
}

void sub_291600(X86Context& ctx, uint8_t* base) {
	// 0x291600: movss xmm0, dword ptr [0x0056C5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5A0u);
	// 0x291608: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291610: movss [0x0056C578], xmm0
	X86_MEM_WRITE_u32(base, 0x56C578u, ctx.xmm[0].u32[0]);
	// 0x291618: ret
	return;
}

void sub_291620(X86Context& ctx, uint8_t* base) {
	// 0x291620: movss xmm0, dword ptr [0x0056C5FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5FCu);
	// 0x291628: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x291630: movss [0x0056C5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5C8u, ctx.xmm[0].u32[0]);
	// 0x291638: ret
	return;
}

void sub_291640(X86Context& ctx, uint8_t* base) {
	// 0x291640: movss xmm0, dword ptr [0x0056C578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C578u);
	// 0x291648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291650: movss [0x0056C5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5D8u, ctx.xmm[0].u32[0]);
	// 0x291658: ret
	return;
}

void sub_291660(X86Context& ctx, uint8_t* base) {
	// 0x291660: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x291668: movss [0x0056C56C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C56Cu, ctx.xmm[0].u32[0]);
	// 0x291670: ret
	return;
}

void sub_291680(X86Context& ctx, uint8_t* base) {
	// 0x291680: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x291688: movss [0x0056C5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5A4u, ctx.xmm[0].u32[0]);
	// 0x291690: ret
	return;
}

void sub_2916A0(X86Context& ctx, uint8_t* base) {
	// 0x2916A0: movss xmm0, dword ptr [0x0056C5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5A0u);
	// 0x2916A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2916B0: movss [0x0056C5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5B0u, ctx.xmm[0].u32[0]);
	// 0x2916B8: ret
	return;
}

void sub_2916C0(X86Context& ctx, uint8_t* base) {
	// 0x2916C0: movss xmm0, dword ptr [0x0056C5FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5FCu);
	// 0x2916C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2916D0: movss [0x0056C600], xmm0
	X86_MEM_WRITE_u32(base, 0x56C600u, ctx.xmm[0].u32[0]);
	// 0x2916D8: ret
	return;
}

void sub_2916E0(X86Context& ctx, uint8_t* base) {
	// 0x2916E0: movss xmm0, dword ptr [0x0056C5B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5B0u);
	// 0x2916E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2916F0: movss [0x0056C5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5ECu, ctx.xmm[0].u32[0]);
	// 0x2916F8: ret
	return;
}

void sub_291700(X86Context& ctx, uint8_t* base) {
	// 0x291700: movss xmm0, dword ptr [0x0056C600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C600u);
	// 0x291708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291710: movss [0x0056C610], xmm0
	X86_MEM_WRITE_u32(base, 0x56C610u, ctx.xmm[0].u32[0]);
	// 0x291718: ret
	return;
}

void sub_291720(X86Context& ctx, uint8_t* base) {
	// 0x291720: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x291728: movss [0x0056C57C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C57Cu, ctx.xmm[0].u32[0]);
	// 0x291730: ret
	return;
}

void sub_291740(X86Context& ctx, uint8_t* base) {
	// 0x291740: movss xmm0, dword ptr [0x0056C5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5A0u);
	// 0x291748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291750: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x291758: movss [0x0056C5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5F8u, ctx.xmm[0].u32[0]);
	// 0x291760: ret
	return;
}

void sub_291770(X86Context& ctx, uint8_t* base) {
	// 0x291770: movss xmm0, dword ptr [0x0056C5FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5FCu);
	// 0x291778: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291780: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x291788: movss [0x0056C594], xmm0
	X86_MEM_WRITE_u32(base, 0x56C594u, ctx.xmm[0].u32[0]);
	// 0x291790: ret
	return;
}

void sub_2917A0(X86Context& ctx, uint8_t* base) {
	// 0x2917A0: movss xmm0, dword ptr [0x0056C5A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5A0u);
	// 0x2917A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2917B0: movss [0x0056C598], xmm0
	X86_MEM_WRITE_u32(base, 0x56C598u, ctx.xmm[0].u32[0]);
	// 0x2917B8: ret
	return;
}

void sub_2917C0(X86Context& ctx, uint8_t* base) {
	// 0x2917C0: movss xmm0, dword ptr [0x0056C5FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5FCu);
	// 0x2917C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2917D0: movss [0x0056C604], xmm0
	X86_MEM_WRITE_u32(base, 0x56C604u, ctx.xmm[0].u32[0]);
	// 0x2917D8: ret
	return;
}

void sub_2917E0(X86Context& ctx, uint8_t* base) {
	// 0x2917E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2917E8: movss [0x0056C580], xmm0
	X86_MEM_WRITE_u32(base, 0x56C580u, ctx.xmm[0].u32[0]);
	// 0x2917F0: ret
	return;
}

void sub_291800(X86Context& ctx, uint8_t* base) {
	// 0x291800: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x291808: movss [0x0056C5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5ACu, ctx.xmm[0].u32[0]);
	// 0x291810: ret
	return;
}

void sub_291820(X86Context& ctx, uint8_t* base) {
	// 0x291820: movss xmm0, dword ptr [0x0056C580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C580u);
	// 0x291828: movss [0x0056C618], xmm0
	X86_MEM_WRITE_u32(base, 0x56C618u, ctx.xmm[0].u32[0]);
	// 0x291830: ret
	return;
}

void sub_291840(X86Context& ctx, uint8_t* base) {
	// 0x291840: movss xmm0, dword ptr [0x0056C5FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5FCu);
	// 0x291848: subss xmm0, [0x0056C580]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C580u);
	// 0x291850: movss [0x0056C5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5DCu, ctx.xmm[0].u32[0]);
	// 0x291858: ret
	return;
}

void sub_291860(X86Context& ctx, uint8_t* base) {
	// 0x291860: movss xmm0, dword ptr [0x0056C5DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5DCu);
	// 0x291868: subss xmm0, [0x0056C5AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C5ACu);
	// 0x291870: movss [0x0056C5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5D4u, ctx.xmm[0].u32[0]);
	// 0x291878: ret
	return;
}

void sub_291880(X86Context& ctx, uint8_t* base) {
	// 0x291880: movss xmm0, dword ptr [0x0056C604]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C604u);
	// 0x291888: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x291890: movss [0x0056C5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5C0u, ctx.xmm[0].u32[0]);
	// 0x291898: ret
	return;
}

void sub_2918A0(X86Context& ctx, uint8_t* base) {
	// 0x2918A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2918A8: movss [0x0056C5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5A8u, ctx.xmm[0].u32[0]);
	// 0x2918B0: ret
	return;
}

void sub_2918C0(X86Context& ctx, uint8_t* base) {
	// 0x2918C0: movss xmm0, dword ptr [0x0056C5C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C5C0u);
	// 0x2918C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2918D0: movss [0x0056C5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5F4u, ctx.xmm[0].u32[0]);
	// 0x2918D8: ret
	return;
}

void sub_2918E0(X86Context& ctx, uint8_t* base) {
	// 0x2918E0: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2918E8: movss [0x0056C5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5C4u, ctx.xmm[0].u32[0]);
	// 0x2918F0: ret
	return;
}

void sub_291900(X86Context& ctx, uint8_t* base) {
	// 0x291900: movss xmm0, dword ptr [0x00397898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397898u);
	// 0x291908: movss [0x0056C59C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C59Cu, ctx.xmm[0].u32[0]);
	// 0x291910: ret
	return;
}

void sub_291920(X86Context& ctx, uint8_t* base) {
	// 0x291920: movss xmm0, dword ptr [0x0056C578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C578u);
	// 0x291928: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291930: movss [0x0056C570], xmm0
	X86_MEM_WRITE_u32(base, 0x56C570u, ctx.xmm[0].u32[0]);
	// 0x291938: ret
	return;
}

void sub_291940(X86Context& ctx, uint8_t* base) {
	// 0x291940: movss xmm0, dword ptr [0x003B226C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B226Cu);
	// 0x291948: movss [0x0056C5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C5BCu, ctx.xmm[0].u32[0]);
	// 0x291950: ret
	return;
}

void sub_291960(X86Context& ctx, uint8_t* base) {
	// 0x291960: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x291968: movss [0x0056C678], xmm0
	X86_MEM_WRITE_u32(base, 0x56C678u, ctx.xmm[0].u32[0]);
	// 0x291970: ret
	return;
}

void sub_291980(X86Context& ctx, uint8_t* base) {
	// 0x291980: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x291988: movss [0x0056C694], xmm0
	X86_MEM_WRITE_u32(base, 0x56C694u, ctx.xmm[0].u32[0]);
	// 0x291990: ret
	return;
}

void sub_2919A0(X86Context& ctx, uint8_t* base) {
	// 0x2919A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2919A8: movss [0x0056C66C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C66Cu, ctx.xmm[0].u32[0]);
	// 0x2919B0: ret
	return;
}

void sub_2919C0(X86Context& ctx, uint8_t* base) {
	// 0x2919C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2919C8: movss [0x0056C624], xmm0
	X86_MEM_WRITE_u32(base, 0x56C624u, ctx.xmm[0].u32[0]);
	// 0x2919D0: ret
	return;
}

void sub_2919E0(X86Context& ctx, uint8_t* base) {
	// 0x2919E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2919E8: movss [0x0056C67C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C67Cu, ctx.xmm[0].u32[0]);
	// 0x2919F0: ret
	return;
}

void sub_291A00(X86Context& ctx, uint8_t* base) {
	// 0x291A00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x291A08: movss [0x0056C640], xmm0
	X86_MEM_WRITE_u32(base, 0x56C640u, ctx.xmm[0].u32[0]);
	// 0x291A10: ret
	return;
}

void sub_291A20(X86Context& ctx, uint8_t* base) {
	// 0x291A20: movss xmm0, dword ptr [0x0056C67C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C67Cu);
	// 0x291A28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291A30: movss [0x0056C6B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6B4u, ctx.xmm[0].u32[0]);
	// 0x291A38: ret
	return;
}

void sub_291A40(X86Context& ctx, uint8_t* base) {
	// 0x291A40: movss xmm0, dword ptr [0x0056C640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C640u);
	// 0x291A48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x291A50: movss [0x0056C69C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C69Cu, ctx.xmm[0].u32[0]);
	// 0x291A58: ret
	return;
}

void sub_291A60(X86Context& ctx, uint8_t* base) {
	// 0x291A60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x291A68: movss [0x0056C6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6CCu, ctx.xmm[0].u32[0]);
	// 0x291A70: ret
	return;
}

void sub_291A80(X86Context& ctx, uint8_t* base) {
	// 0x291A80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x291A88: movss [0x0056C6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6B8u, ctx.xmm[0].u32[0]);
	// 0x291A90: ret
	return;
}

void sub_291AA0(X86Context& ctx, uint8_t* base) {
	// 0x291AA0: movss xmm0, dword ptr [0x0056C6B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6B8u);
	// 0x291AA8: movss [0x0056C6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6C8u, ctx.xmm[0].u32[0]);
	// 0x291AB0: ret
	return;
}

void sub_291AC0(X86Context& ctx, uint8_t* base) {
	// 0x291AC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x291AC8: movss [0x0056C62C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C62Cu, ctx.xmm[0].u32[0]);
	// 0x291AD0: ret
	return;
}

void sub_291AE0(X86Context& ctx, uint8_t* base) {
	// 0x291AE0: movss xmm0, dword ptr [0x0056C640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C640u);
	// 0x291AE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x291AF0: movss [0x0056C6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6C0u, ctx.xmm[0].u32[0]);
	// 0x291AF8: ret
	return;
}

void sub_291B00(X86Context& ctx, uint8_t* base) {
	// 0x291B00: movss xmm0, dword ptr [0x0056C640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C640u);
	// 0x291B08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x291B10: movss [0x0056C668], xmm0
	X86_MEM_WRITE_u32(base, 0x56C668u, ctx.xmm[0].u32[0]);
	// 0x291B18: ret
	return;
}

void sub_291B20(X86Context& ctx, uint8_t* base) {
	// 0x291B20: movss xmm0, dword ptr [0x0056C640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C640u);
	// 0x291B28: subss xmm0, [0x0056C668]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C668u);
	// 0x291B30: movss [0x0056C648], xmm0
	X86_MEM_WRITE_u32(base, 0x56C648u, ctx.xmm[0].u32[0]);
	// 0x291B38: ret
	return;
}

void sub_291B40(X86Context& ctx, uint8_t* base) {
	// 0x291B40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x291B48: movss [0x0056C690], xmm0
	X86_MEM_WRITE_u32(base, 0x56C690u, ctx.xmm[0].u32[0]);
	// 0x291B50: ret
	return;
}

void sub_291B60(X86Context& ctx, uint8_t* base) {
	// 0x291B60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x291B68: movss [0x0056C644], xmm0
	X86_MEM_WRITE_u32(base, 0x56C644u, ctx.xmm[0].u32[0]);
	// 0x291B70: ret
	return;
}

void sub_291B80(X86Context& ctx, uint8_t* base) {
	// 0x291B80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x291B88: movss [0x0056C654], xmm0
	X86_MEM_WRITE_u32(base, 0x56C654u, ctx.xmm[0].u32[0]);
	// 0x291B90: ret
	return;
}

void sub_291BA0(X86Context& ctx, uint8_t* base) {
	// 0x291BA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x291BA8: movss [0x0056C6A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6A8u, ctx.xmm[0].u32[0]);
	// 0x291BB0: ret
	return;
}

void sub_291BC0(X86Context& ctx, uint8_t* base) {
	// 0x291BC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x291BC8: movss [0x0056C68C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C68Cu, ctx.xmm[0].u32[0]);
	// 0x291BD0: ret
	return;
}

void sub_291BE0(X86Context& ctx, uint8_t* base) {
	// 0x291BE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x291BE8: movss [0x0056C63C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C63Cu, ctx.xmm[0].u32[0]);
	// 0x291BF0: ret
	return;
}

void sub_291C00(X86Context& ctx, uint8_t* base) {
	// 0x291C00: movss xmm0, dword ptr [0x0056C654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C654u);
	// 0x291C08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291C10: movss [0x0056C630], xmm0
	X86_MEM_WRITE_u32(base, 0x56C630u, ctx.xmm[0].u32[0]);
	// 0x291C18: ret
	return;
}

void sub_291C20(X86Context& ctx, uint8_t* base) {
	// 0x291C20: movss xmm0, dword ptr [0x0056C6A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6A8u);
	// 0x291C28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x291C30: movss [0x0056C674], xmm0
	X86_MEM_WRITE_u32(base, 0x56C674u, ctx.xmm[0].u32[0]);
	// 0x291C38: ret
	return;
}

void sub_291C40(X86Context& ctx, uint8_t* base) {
	// 0x291C40: movss xmm0, dword ptr [0x0056C630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C630u);
	// 0x291C48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291C50: movss [0x0056C684], xmm0
	X86_MEM_WRITE_u32(base, 0x56C684u, ctx.xmm[0].u32[0]);
	// 0x291C58: ret
	return;
}

void sub_291C60(X86Context& ctx, uint8_t* base) {
	// 0x291C60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x291C68: movss [0x0056C628], xmm0
	X86_MEM_WRITE_u32(base, 0x56C628u, ctx.xmm[0].u32[0]);
	// 0x291C70: ret
	return;
}

void sub_291C80(X86Context& ctx, uint8_t* base) {
	// 0x291C80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x291C88: movss [0x0056C658], xmm0
	X86_MEM_WRITE_u32(base, 0x56C658u, ctx.xmm[0].u32[0]);
	// 0x291C90: ret
	return;
}

void sub_291CA0(X86Context& ctx, uint8_t* base) {
	// 0x291CA0: movss xmm0, dword ptr [0x0056C654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C654u);
	// 0x291CA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x291CB0: movss [0x0056C664], xmm0
	X86_MEM_WRITE_u32(base, 0x56C664u, ctx.xmm[0].u32[0]);
	// 0x291CB8: ret
	return;
}

void sub_291CC0(X86Context& ctx, uint8_t* base) {
	// 0x291CC0: movss xmm0, dword ptr [0x0056C6A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6A8u);
	// 0x291CC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x291CD0: movss [0x0056C6AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6ACu, ctx.xmm[0].u32[0]);
	// 0x291CD8: ret
	return;
}

void sub_291CE0(X86Context& ctx, uint8_t* base) {
	// 0x291CE0: movss xmm0, dword ptr [0x0056C664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C664u);
	// 0x291CE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291CF0: movss [0x0056C698], xmm0
	X86_MEM_WRITE_u32(base, 0x56C698u, ctx.xmm[0].u32[0]);
	// 0x291CF8: ret
	return;
}

void sub_291D00(X86Context& ctx, uint8_t* base) {
	// 0x291D00: movss xmm0, dword ptr [0x0056C6AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6ACu);
	// 0x291D08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291D10: movss [0x0056C6BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6BCu, ctx.xmm[0].u32[0]);
	// 0x291D18: ret
	return;
}

