#include "x86_recomp_shared.h"

void sub_2C1050(X86Context& ctx, uint8_t* base) {
	// 0x2C1050: movss xmm0, dword ptr [0x005A8BBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BBCu);
	// 0x2C1058: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2C1060: movss [0x005A8BEC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BECu, ctx.xmm[0].u32[0]);
	// 0x2C1068: ret
	return;
}

void sub_2C1070(X86Context& ctx, uint8_t* base) {
	// 0x2C1070: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C1078: movss [0x005A8C70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C70u, ctx.xmm[0].u32[0]);
	// 0x2C1080: ret
	return;
}

void sub_2C1090(X86Context& ctx, uint8_t* base) {
	// 0x2C1090: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C1098: movss [0x005A8C8C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C8Cu, ctx.xmm[0].u32[0]);
	// 0x2C10A0: ret
	return;
}

void sub_2C10B0(X86Context& ctx, uint8_t* base) {
	// 0x2C10B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C10B8: movss [0x005A8C64], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C64u, ctx.xmm[0].u32[0]);
	// 0x2C10C0: ret
	return;
}

void sub_2C10D0(X86Context& ctx, uint8_t* base) {
	// 0x2C10D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C10D8: movss [0x005A8C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C1Cu, ctx.xmm[0].u32[0]);
	// 0x2C10E0: ret
	return;
}

void sub_2C10F0(X86Context& ctx, uint8_t* base) {
	// 0x2C10F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C10F8: movss [0x005A8C74], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C74u, ctx.xmm[0].u32[0]);
	// 0x2C1100: ret
	return;
}

void sub_2C1110(X86Context& ctx, uint8_t* base) {
	// 0x2C1110: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C1118: movss [0x005A8C38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C38u, ctx.xmm[0].u32[0]);
	// 0x2C1120: ret
	return;
}

void sub_2C1130(X86Context& ctx, uint8_t* base) {
	// 0x2C1130: movss xmm0, dword ptr [0x005A8C74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C74u);
	// 0x2C1138: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C1140: movss [0x005A8CAC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CACu, ctx.xmm[0].u32[0]);
	// 0x2C1148: ret
	return;
}

void sub_2C1150(X86Context& ctx, uint8_t* base) {
	// 0x2C1150: movss xmm0, dword ptr [0x005A8C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C38u);
	// 0x2C1158: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C1160: movss [0x005A8C94], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C94u, ctx.xmm[0].u32[0]);
	// 0x2C1168: ret
	return;
}

void sub_2C1170(X86Context& ctx, uint8_t* base) {
	// 0x2C1170: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C1178: movss [0x005A8CC4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CC4u, ctx.xmm[0].u32[0]);
	// 0x2C1180: ret
	return;
}

void sub_2C1190(X86Context& ctx, uint8_t* base) {
	// 0x2C1190: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C1198: movss [0x005A8CB0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CB0u, ctx.xmm[0].u32[0]);
	// 0x2C11A0: ret
	return;
}

void sub_2C11B0(X86Context& ctx, uint8_t* base) {
	// 0x2C11B0: movss xmm0, dword ptr [0x005A8CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CB0u);
	// 0x2C11B8: movss [0x005A8CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CC0u, ctx.xmm[0].u32[0]);
	// 0x2C11C0: ret
	return;
}

void sub_2C11D0(X86Context& ctx, uint8_t* base) {
	// 0x2C11D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C11D8: movss [0x005A8C24], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C24u, ctx.xmm[0].u32[0]);
	// 0x2C11E0: ret
	return;
}

void sub_2C11F0(X86Context& ctx, uint8_t* base) {
	// 0x2C11F0: movss xmm0, dword ptr [0x005A8C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C38u);
	// 0x2C11F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C1200: movss [0x005A8CB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CB8u, ctx.xmm[0].u32[0]);
	// 0x2C1208: ret
	return;
}

void sub_2C1210(X86Context& ctx, uint8_t* base) {
	// 0x2C1210: movss xmm0, dword ptr [0x005A8C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C38u);
	// 0x2C1218: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C1220: movss [0x005A8C60], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C60u, ctx.xmm[0].u32[0]);
	// 0x2C1228: ret
	return;
}

void sub_2C1230(X86Context& ctx, uint8_t* base) {
	// 0x2C1230: movss xmm0, dword ptr [0x005A8C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C38u);
	// 0x2C1238: subss xmm0, [0x005A8C60]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8C60u);
	// 0x2C1240: movss [0x005A8C40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C40u, ctx.xmm[0].u32[0]);
	// 0x2C1248: ret
	return;
}

void sub_2C1250(X86Context& ctx, uint8_t* base) {
	// 0x2C1250: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C1258: movss [0x005A8C88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C88u, ctx.xmm[0].u32[0]);
	// 0x2C1260: ret
	return;
}

void sub_2C1270(X86Context& ctx, uint8_t* base) {
	// 0x2C1270: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C1278: movss [0x005A8C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C3Cu, ctx.xmm[0].u32[0]);
	// 0x2C1280: ret
	return;
}

void sub_2C1290(X86Context& ctx, uint8_t* base) {
	// 0x2C1290: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C1298: movss [0x005A8C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C4Cu, ctx.xmm[0].u32[0]);
	// 0x2C12A0: ret
	return;
}

void sub_2C12B0(X86Context& ctx, uint8_t* base) {
	// 0x2C12B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C12B8: movss [0x005A8CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CA0u, ctx.xmm[0].u32[0]);
	// 0x2C12C0: ret
	return;
}

void sub_2C12D0(X86Context& ctx, uint8_t* base) {
	// 0x2C12D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2C12D8: movss [0x005A8C84], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C84u, ctx.xmm[0].u32[0]);
	// 0x2C12E0: ret
	return;
}

void sub_2C12F0(X86Context& ctx, uint8_t* base) {
	// 0x2C12F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2C12F8: movss [0x005A8C34], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C34u, ctx.xmm[0].u32[0]);
	// 0x2C1300: ret
	return;
}

void sub_2C1310(X86Context& ctx, uint8_t* base) {
	// 0x2C1310: movss xmm0, dword ptr [0x005A8C4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C4Cu);
	// 0x2C1318: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C1320: movss [0x005A8C28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C28u, ctx.xmm[0].u32[0]);
	// 0x2C1328: ret
	return;
}

void sub_2C1330(X86Context& ctx, uint8_t* base) {
	// 0x2C1330: movss xmm0, dword ptr [0x005A8CA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA0u);
	// 0x2C1338: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C1340: movss [0x005A8C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C6Cu, ctx.xmm[0].u32[0]);
	// 0x2C1348: ret
	return;
}

void sub_2C1350(X86Context& ctx, uint8_t* base) {
	// 0x2C1350: movss xmm0, dword ptr [0x005A8C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C28u);
	// 0x2C1358: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C1360: movss [0x005A8C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C7Cu, ctx.xmm[0].u32[0]);
	// 0x2C1368: ret
	return;
}

void sub_2C1370(X86Context& ctx, uint8_t* base) {
	// 0x2C1370: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C1378: movss [0x005A8C20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C20u, ctx.xmm[0].u32[0]);
	// 0x2C1380: ret
	return;
}

void sub_2C1390(X86Context& ctx, uint8_t* base) {
	// 0x2C1390: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C1398: movss [0x005A8C50], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C50u, ctx.xmm[0].u32[0]);
	// 0x2C13A0: ret
	return;
}

void sub_2C13B0(X86Context& ctx, uint8_t* base) {
	// 0x2C13B0: movss xmm0, dword ptr [0x005A8C4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C4Cu);
	// 0x2C13B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C13C0: movss [0x005A8C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C5Cu, ctx.xmm[0].u32[0]);
	// 0x2C13C8: ret
	return;
}

void sub_2C13D0(X86Context& ctx, uint8_t* base) {
	// 0x2C13D0: movss xmm0, dword ptr [0x005A8CA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA0u);
	// 0x2C13D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C13E0: movss [0x005A8CA4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CA4u, ctx.xmm[0].u32[0]);
	// 0x2C13E8: ret
	return;
}

void sub_2C13F0(X86Context& ctx, uint8_t* base) {
	// 0x2C13F0: movss xmm0, dword ptr [0x005A8C5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C5Cu);
	// 0x2C13F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C1400: movss [0x005A8C90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C90u, ctx.xmm[0].u32[0]);
	// 0x2C1408: ret
	return;
}

void sub_2C1410(X86Context& ctx, uint8_t* base) {
	// 0x2C1410: movss xmm0, dword ptr [0x005A8CA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA4u);
	// 0x2C1418: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C1420: movss [0x005A8CB4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CB4u, ctx.xmm[0].u32[0]);
	// 0x2C1428: ret
	return;
}

void sub_2C1430(X86Context& ctx, uint8_t* base) {
	// 0x2C1430: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2C1438: movss [0x005A8C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C2Cu, ctx.xmm[0].u32[0]);
	// 0x2C1440: ret
	return;
}

void sub_2C1450(X86Context& ctx, uint8_t* base) {
	// 0x2C1450: movss xmm0, dword ptr [0x005A8C4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C4Cu);
	// 0x2C1458: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C1460: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2C1468: movss [0x005A8C9C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C9Cu, ctx.xmm[0].u32[0]);
	// 0x2C1470: ret
	return;
}

void sub_2C1480(X86Context& ctx, uint8_t* base) {
	// 0x2C1480: movss xmm0, dword ptr [0x005A8CA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA0u);
	// 0x2C1488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C1490: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2C1498: movss [0x005A8C44], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C44u, ctx.xmm[0].u32[0]);
	// 0x2C14A0: ret
	return;
}

void sub_2C14B0(X86Context& ctx, uint8_t* base) {
	// 0x2C14B0: movss xmm0, dword ptr [0x005A8C4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C4Cu);
	// 0x2C14B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C14C0: movss [0x005A8C48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C48u, ctx.xmm[0].u32[0]);
	// 0x2C14C8: ret
	return;
}

void sub_2C14D0(X86Context& ctx, uint8_t* base) {
	// 0x2C14D0: movss xmm0, dword ptr [0x005A8CA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA0u);
	// 0x2C14D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C14E0: movss [0x005A8CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CA8u, ctx.xmm[0].u32[0]);
	// 0x2C14E8: ret
	return;
}

void sub_2C14F0(X86Context& ctx, uint8_t* base) {
	// 0x2C14F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2C14F8: movss [0x005A8C30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C30u, ctx.xmm[0].u32[0]);
	// 0x2C1500: ret
	return;
}

void sub_2C1510(X86Context& ctx, uint8_t* base) {
	// 0x2C1510: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2C1518: movss [0x005A8C58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C58u, ctx.xmm[0].u32[0]);
	// 0x2C1520: ret
	return;
}

void sub_2C1530(X86Context& ctx, uint8_t* base) {
	// 0x2C1530: movss xmm0, dword ptr [0x005A8C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C30u);
	// 0x2C1538: movss [0x005A8CBC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CBCu, ctx.xmm[0].u32[0]);
	// 0x2C1540: ret
	return;
}

void sub_2C1550(X86Context& ctx, uint8_t* base) {
	// 0x2C1550: movss xmm0, dword ptr [0x005A8CA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA0u);
	// 0x2C1558: subss xmm0, [0x005A8C30]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8C30u);
	// 0x2C1560: movss [0x005A8C80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C80u, ctx.xmm[0].u32[0]);
	// 0x2C1568: ret
	return;
}

void sub_2C1570(X86Context& ctx, uint8_t* base) {
	// 0x2C1570: movss xmm0, dword ptr [0x005A8C80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C80u);
	// 0x2C1578: subss xmm0, [0x005A8C58]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8C58u);
	// 0x2C1580: movss [0x005A8C78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C78u, ctx.xmm[0].u32[0]);
	// 0x2C1588: ret
	return;
}

void sub_2C1590(X86Context& ctx, uint8_t* base) {
	// 0x2C1590: movss xmm0, dword ptr [0x005A8CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CA8u);
	// 0x2C1598: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2C15A0: movss [0x005A8C68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C68u, ctx.xmm[0].u32[0]);
	// 0x2C15A8: ret
	return;
}

void sub_2C15B0(X86Context& ctx, uint8_t* base) {
	// 0x2C15B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2C15B8: movss [0x005A8C54], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C54u, ctx.xmm[0].u32[0]);
	// 0x2C15C0: ret
	return;
}

void sub_2C15D0(X86Context& ctx, uint8_t* base) {
	// 0x2C15D0: movss xmm0, dword ptr [0x005A8C68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C68u);
	// 0x2C15D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2C15E0: movss [0x005A8C98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C98u, ctx.xmm[0].u32[0]);
	// 0x2C15E8: ret
	return;
}

void sub_2C15F0(X86Context& ctx, uint8_t* base) {
	// 0x2C15F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C15F8: movss [0x005A8CE4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CE4u, ctx.xmm[0].u32[0]);
	// 0x2C1600: ret
	return;
}

void sub_2C1610(X86Context& ctx, uint8_t* base) {
	// 0x2C1610: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C1618: movss [0x005A8CF0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CF0u, ctx.xmm[0].u32[0]);
	// 0x2C1620: ret
	return;
}

void sub_2C1630(X86Context& ctx, uint8_t* base) {
	// 0x2C1630: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C1638: movss [0x005A8CE0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CE0u, ctx.xmm[0].u32[0]);
	// 0x2C1640: ret
	return;
}

void sub_2C1650(X86Context& ctx, uint8_t* base) {
	// 0x2C1650: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C1658: movss [0x005A8CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CC8u, ctx.xmm[0].u32[0]);
	// 0x2C1660: ret
	return;
}

void sub_2C1670(X86Context& ctx, uint8_t* base) {
	// 0x2C1670: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C1678: movss [0x005A8CE8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CE8u, ctx.xmm[0].u32[0]);
	// 0x2C1680: ret
	return;
}

void sub_2C1690(X86Context& ctx, uint8_t* base) {
	// 0x2C1690: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C1698: movss [0x005A8CD0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CD0u, ctx.xmm[0].u32[0]);
	// 0x2C16A0: ret
	return;
}

void sub_2C16B0(X86Context& ctx, uint8_t* base) {
	// 0x2C16B0: movss xmm0, dword ptr [0x005A8CE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CE8u);
	// 0x2C16B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C16C0: movss [0x005A8CF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CF8u, ctx.xmm[0].u32[0]);
	// 0x2C16C8: ret
	return;
}

void sub_2C16D0(X86Context& ctx, uint8_t* base) {
	// 0x2C16D0: movss xmm0, dword ptr [0x005A8CD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CD0u);
	// 0x2C16D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C16E0: movss [0x005A8CF4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CF4u, ctx.xmm[0].u32[0]);
	// 0x2C16E8: ret
	return;
}

void sub_2C16F0(X86Context& ctx, uint8_t* base) {
	// 0x2C16F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C16F8: movss [0x005A8D08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D08u, ctx.xmm[0].u32[0]);
	// 0x2C1700: ret
	return;
}

void sub_2C1710(X86Context& ctx, uint8_t* base) {
	// 0x2C1710: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C1718: movss [0x005A8CFC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CFCu, ctx.xmm[0].u32[0]);
	// 0x2C1720: ret
	return;
}

void sub_2C1730(X86Context& ctx, uint8_t* base) {
	// 0x2C1730: movss xmm0, dword ptr [0x005A8CFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CFCu);
	// 0x2C1738: movss [0x005A8D04], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D04u, ctx.xmm[0].u32[0]);
	// 0x2C1740: ret
	return;
}

void sub_2C1750(X86Context& ctx, uint8_t* base) {
	// 0x2C1750: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C1758: movss [0x005A8CCC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CCCu, ctx.xmm[0].u32[0]);
	// 0x2C1760: ret
	return;
}

void sub_2C1770(X86Context& ctx, uint8_t* base) {
	// 0x2C1770: movss xmm0, dword ptr [0x005A8CD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CD0u);
	// 0x2C1778: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C1780: movss [0x005A8D00], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D00u, ctx.xmm[0].u32[0]);
	// 0x2C1788: ret
	return;
}

void sub_2C1790(X86Context& ctx, uint8_t* base) {
	// 0x2C1790: movss xmm0, dword ptr [0x005A8CD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CD0u);
	// 0x2C1798: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C17A0: movss [0x005A8CDC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CDCu, ctx.xmm[0].u32[0]);
	// 0x2C17A8: ret
	return;
}

void sub_2C17B0(X86Context& ctx, uint8_t* base) {
	// 0x2C17B0: movss xmm0, dword ptr [0x005A8CD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8CD0u);
	// 0x2C17B8: subss xmm0, [0x005A8CDC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8CDCu);
	// 0x2C17C0: movss [0x005A8CD8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CD8u, ctx.xmm[0].u32[0]);
	// 0x2C17C8: ret
	return;
}

void sub_2C17D0(X86Context& ctx, uint8_t* base) {
	// 0x2C17D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C17D8: movss [0x005A8CEC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CECu, ctx.xmm[0].u32[0]);
	// 0x2C17E0: ret
	return;
}

void sub_2C17F0(X86Context& ctx, uint8_t* base) {
	// 0x2C17F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C17F8: movss [0x005A8CD4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8CD4u, ctx.xmm[0].u32[0]);
	// 0x2C1800: ret
	return;
}

void sub_2C1810(X86Context& ctx, uint8_t* base) {
	// 0x2C1810: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C1818: movss [0x005A8D10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D10u, ctx.xmm[0].u32[0]);
	// 0x2C1820: ret
	return;
}

void sub_2C1830(X86Context& ctx, uint8_t* base) {
	// 0x2C1830: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C1838: movss [0x005A8D14], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D14u, ctx.xmm[0].u32[0]);
	// 0x2C1840: ret
	return;
}

void sub_2C1850(X86Context& ctx, uint8_t* base) {
	// 0x2C1850: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C1858: movss [0x005A8D0C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D0Cu, ctx.xmm[0].u32[0]);
	// 0x2C1860: ret
	return;
}

void sub_2C1870(X86Context& ctx, uint8_t* base) {
	// 0x2C1870: movss xmm0, dword ptr [0x003B1688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2C1878: movss xmm1, dword ptr [0x003B16B4]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B16B4u);
	// 0x2C1880: movss xmm2, dword ptr [0x003A2D50]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C1888: movss xmm3, dword ptr [0x003A795C]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A795Cu);
	// 0x2C1890: movss [0x005A8D18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D18u, ctx.xmm[0].u32[0]);
	// 0x2C1898: movss [0x005A8D1C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D1Cu, ctx.xmm[1].u32[0]);
	// 0x2C18A0: movss [0x005A8D20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D20u, ctx.xmm[0].u32[0]);
	// 0x2C18A8: movss [0x005A8D24], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D24u, ctx.xmm[1].u32[0]);
	// 0x2C18B0: movss [0x005A8D28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D28u, ctx.xmm[0].u32[0]);
	// 0x2C18B8: movss [0x005A8D2C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D2Cu, ctx.xmm[1].u32[0]);
	// 0x2C18C0: movss [0x005A8D30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D30u, ctx.xmm[0].u32[0]);
	// 0x2C18C8: movss [0x005A8D34], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D34u, ctx.xmm[1].u32[0]);
	// 0x2C18D0: movss [0x005A8D38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D38u, ctx.xmm[0].u32[0]);
	// 0x2C18D8: movss [0x005A8D3C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D3Cu, ctx.xmm[1].u32[0]);
	// 0x2C18E0: movss [0x005A8D40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D40u, ctx.xmm[0].u32[0]);
	// 0x2C18E8: movss [0x005A8D44], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D44u, ctx.xmm[1].u32[0]);
	// 0x2C18F0: movss [0x005A8D48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D48u, ctx.xmm[0].u32[0]);
	// 0x2C18F8: movss [0x005A8D4C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D4Cu, ctx.xmm[1].u32[0]);
	// 0x2C1900: movss [0x005A8D50], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D50u, ctx.xmm[0].u32[0]);
	// 0x2C1908: movss [0x005A8D54], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D54u, ctx.xmm[1].u32[0]);
	// 0x2C1910: movss [0x005A8D58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D58u, ctx.xmm[0].u32[0]);
	// 0x2C1918: movss [0x005A8D5C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D5Cu, ctx.xmm[1].u32[0]);
	// 0x2C1920: movss [0x005A8D60], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8D60u, ctx.xmm[2].u32[0]);
	// 0x2C1928: movss [0x005A8D64], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8D64u, ctx.xmm[3].u32[0]);
	// 0x2C1930: movss [0x005A8D68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D68u, ctx.xmm[0].u32[0]);
	// 0x2C1938: movss [0x005A8D6C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D6Cu, ctx.xmm[1].u32[0]);
	// 0x2C1940: movss [0x005A8D70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D70u, ctx.xmm[0].u32[0]);
	// 0x2C1948: movss [0x005A8D74], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D74u, ctx.xmm[1].u32[0]);
	// 0x2C1950: movss [0x005A8D78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D78u, ctx.xmm[0].u32[0]);
	// 0x2C1958: movss [0x005A8D7C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D7Cu, ctx.xmm[1].u32[0]);
	// 0x2C1960: movss [0x005A8D80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D80u, ctx.xmm[0].u32[0]);
	// 0x2C1968: movss [0x005A8D84], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D84u, ctx.xmm[1].u32[0]);
	// 0x2C1970: movss [0x005A8D88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D88u, ctx.xmm[0].u32[0]);
	// 0x2C1978: movss [0x005A8D8C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D8Cu, ctx.xmm[1].u32[0]);
	// 0x2C1980: movss [0x005A8D90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D90u, ctx.xmm[0].u32[0]);
	// 0x2C1988: movss [0x005A8D94], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D94u, ctx.xmm[1].u32[0]);
	// 0x2C1990: movss [0x005A8D98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8D98u, ctx.xmm[0].u32[0]);
	// 0x2C1998: movss [0x005A8D9C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8D9Cu, ctx.xmm[1].u32[0]);
	// 0x2C19A0: movss [0x005A8DA0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DA0u, ctx.xmm[0].u32[0]);
	// 0x2C19A8: movss [0x005A8DA4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DA4u, ctx.xmm[1].u32[0]);
	// 0x2C19B0: movss [0x005A8DA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DA8u, ctx.xmm[0].u32[0]);
	// 0x2C19B8: movss [0x005A8DAC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DACu, ctx.xmm[1].u32[0]);
	// 0x2C19C0: movss [0x005A8DB0], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8DB0u, ctx.xmm[2].u32[0]);
	// 0x2C19C8: movss [0x005A8DB4], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8DB4u, ctx.xmm[3].u32[0]);
	// 0x2C19D0: movss [0x005A8DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DB8u, ctx.xmm[0].u32[0]);
	// 0x2C19D8: movss [0x005A8DBC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DBCu, ctx.xmm[1].u32[0]);
	// 0x2C19E0: movss [0x005A8DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DC0u, ctx.xmm[0].u32[0]);
	// 0x2C19E8: movss [0x005A8DC4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DC4u, ctx.xmm[1].u32[0]);
	// 0x2C19F0: movss [0x005A8DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DC8u, ctx.xmm[0].u32[0]);
	// 0x2C19F8: movss [0x005A8DCC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DCCu, ctx.xmm[1].u32[0]);
	// 0x2C1A00: movss [0x005A8DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DD0u, ctx.xmm[0].u32[0]);
	// 0x2C1A08: movss [0x005A8DD4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DD4u, ctx.xmm[1].u32[0]);
	// 0x2C1A10: movss [0x005A8DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DD8u, ctx.xmm[0].u32[0]);
	// 0x2C1A18: movss [0x005A8DDC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DDCu, ctx.xmm[1].u32[0]);
	// 0x2C1A20: movss [0x005A8DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DE0u, ctx.xmm[0].u32[0]);
	// 0x2C1A28: movss [0x005A8DE4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DE4u, ctx.xmm[1].u32[0]);
	// 0x2C1A30: movss [0x005A8DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DE8u, ctx.xmm[0].u32[0]);
	// 0x2C1A38: movss [0x005A8DEC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DECu, ctx.xmm[1].u32[0]);
	// 0x2C1A40: movss [0x005A8DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DF0u, ctx.xmm[0].u32[0]);
	// 0x2C1A48: movss [0x005A8DF4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DF4u, ctx.xmm[1].u32[0]);
	// 0x2C1A50: movss [0x005A8DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8DF8u, ctx.xmm[0].u32[0]);
	// 0x2C1A58: movss [0x005A8DFC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8DFCu, ctx.xmm[1].u32[0]);
	// 0x2C1A60: movss [0x005A8E00], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8E00u, ctx.xmm[2].u32[0]);
	// 0x2C1A68: movss [0x005A8E04], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8E04u, ctx.xmm[3].u32[0]);
	// 0x2C1A70: movss [0x005A8E08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E08u, ctx.xmm[0].u32[0]);
	// 0x2C1A78: movss [0x005A8E0C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E0Cu, ctx.xmm[1].u32[0]);
	// 0x2C1A80: movss [0x005A8E10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E10u, ctx.xmm[0].u32[0]);
	// 0x2C1A88: movss [0x005A8E14], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E14u, ctx.xmm[1].u32[0]);
	// 0x2C1A90: movss [0x005A8E18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E18u, ctx.xmm[0].u32[0]);
	// 0x2C1A98: movss [0x005A8E1C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E1Cu, ctx.xmm[1].u32[0]);
	// 0x2C1AA0: movss [0x005A8E20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E20u, ctx.xmm[0].u32[0]);
	// 0x2C1AA8: movss [0x005A8E24], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E24u, ctx.xmm[1].u32[0]);
	// 0x2C1AB0: movss [0x005A8E28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E28u, ctx.xmm[0].u32[0]);
	// 0x2C1AB8: movss [0x005A8E2C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E2Cu, ctx.xmm[1].u32[0]);
	// 0x2C1AC0: movss [0x005A8E30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E30u, ctx.xmm[0].u32[0]);
	// 0x2C1AC8: movss [0x005A8E34], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E34u, ctx.xmm[1].u32[0]);
	// 0x2C1AD0: movss [0x005A8E38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E38u, ctx.xmm[0].u32[0]);
	// 0x2C1AD8: movss [0x005A8E3C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E3Cu, ctx.xmm[1].u32[0]);
	// 0x2C1AE0: movss [0x005A8E40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E40u, ctx.xmm[0].u32[0]);
	// 0x2C1AE8: movss [0x005A8E44], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E44u, ctx.xmm[1].u32[0]);
	// 0x2C1AF0: movss [0x005A8E48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E48u, ctx.xmm[0].u32[0]);
	// 0x2C1AF8: movss xmm4, dword ptr [0x003B1AB4]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3B1AB4u);
	// 0x2C1B00: movss [0x005A8E4C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E4Cu, ctx.xmm[1].u32[0]);
	// 0x2C1B08: movss [0x005A8E58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E58u, ctx.xmm[0].u32[0]);
	// 0x2C1B10: movss [0x005A8E5C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E5Cu, ctx.xmm[1].u32[0]);
	// 0x2C1B18: movss [0x005A8E60], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E60u, ctx.xmm[0].u32[0]);
	// 0x2C1B20: movss [0x005A8E64], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E64u, ctx.xmm[1].u32[0]);
	// 0x2C1B28: movss [0x005A8E68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E68u, ctx.xmm[0].u32[0]);
	// 0x2C1B30: movss [0x005A8E6C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E6Cu, ctx.xmm[1].u32[0]);
	// 0x2C1B38: movss [0x005A8E70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E70u, ctx.xmm[0].u32[0]);
	// 0x2C1B40: movss [0x005A8E74], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E74u, ctx.xmm[1].u32[0]);
	// 0x2C1B48: movss [0x005A8E78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E78u, ctx.xmm[0].u32[0]);
	// 0x2C1B50: movss [0x005A8E7C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E7Cu, ctx.xmm[1].u32[0]);
	// 0x2C1B58: movss [0x005A8E80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E80u, ctx.xmm[0].u32[0]);
	// 0x2C1B60: movss [0x005A8E84], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E84u, ctx.xmm[1].u32[0]);
	// 0x2C1B68: movss [0x005A8E88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E88u, ctx.xmm[0].u32[0]);
	// 0x2C1B70: movss [0x005A8E8C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E8Cu, ctx.xmm[1].u32[0]);
	// 0x2C1B78: movss [0x005A8E90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E90u, ctx.xmm[0].u32[0]);
	// 0x2C1B80: movss [0x005A8E94], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E94u, ctx.xmm[1].u32[0]);
	// 0x2C1B88: movss [0x005A8E98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8E98u, ctx.xmm[0].u32[0]);
	// 0x2C1B90: movss [0x005A8E9C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8E9Cu, ctx.xmm[1].u32[0]);
	// 0x2C1B98: movss [0x005A8EA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8EA8u, ctx.xmm[0].u32[0]);
	// 0x2C1BA0: movss [0x005A8EAC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8EACu, ctx.xmm[1].u32[0]);
	// 0x2C1BA8: movss [0x005A8EB0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8EB0u, ctx.xmm[0].u32[0]);
	// 0x2C1BB0: movss [0x005A8EB4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8EB4u, ctx.xmm[1].u32[0]);
	// 0x2C1BB8: movss [0x005A8EB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8EB8u, ctx.xmm[0].u32[0]);
	// 0x2C1BC0: movss [0x005A8EBC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8EBCu, ctx.xmm[1].u32[0]);
	// 0x2C1BC8: movss [0x005A8EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8EC0u, ctx.xmm[0].u32[0]);
	// 0x2C1BD0: movss [0x005A8EC4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8EC4u, ctx.xmm[1].u32[0]);
	// 0x2C1BD8: movss [0x005A8ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8ED0u, ctx.xmm[0].u32[0]);
	// 0x2C1BE0: movss [0x005A8ED4], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8ED4u, ctx.xmm[1].u32[0]);
	// 0x2C1BE8: movss [0x005A8ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8ED8u, ctx.xmm[0].u32[0]);
	// 0x2C1BF0: movss xmm0, dword ptr [0x003B1698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x2C1BF8: movss [0x005A8EDC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8EDCu, ctx.xmm[1].u32[0]);
	// 0x2C1C00: movss xmm1, dword ptr [0x003B175C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B175Cu);
	// 0x2C1C08: movss [0x005A8EC8], xmm4
	X86_MEM_WRITE_u32(base, 0x5A8EC8u, ctx.xmm[4].u32[0]);
	// 0x2C1C10: movss xmm4, dword ptr [0x003B1760]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3B1760u);
	// 0x2C1C18: movss [0x005A8EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8EF8u, ctx.xmm[0].u32[0]);
	// 0x2C1C20: movss [0x005A8EFC], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8EFCu, ctx.xmm[1].u32[0]);
	// 0x2C1C28: movss [0x005A8F00], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F00u, ctx.xmm[0].u32[0]);
	// 0x2C1C30: movss [0x005A8F04], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8F04u, ctx.xmm[1].u32[0]);
	// 0x2C1C38: movss [0x005A8F08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F08u, ctx.xmm[0].u32[0]);
	// 0x2C1C40: movss xmm0, dword ptr [0x003A5A48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x2C1C48: movss [0x005A8F0C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8F0Cu, ctx.xmm[1].u32[0]);
	// 0x2C1C50: movss xmm1, dword ptr [0x003B1770]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1770u);
	// 0x2C1C58: movss [0x005A8E50], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8E50u, ctx.xmm[2].u32[0]);
	// 0x2C1C60: movss [0x005A8E54], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8E54u, ctx.xmm[3].u32[0]);
	// 0x2C1C68: movss [0x005A8EA0], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8EA0u, ctx.xmm[2].u32[0]);
	// 0x2C1C70: movss [0x005A8EA4], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8EA4u, ctx.xmm[3].u32[0]);
	// 0x2C1C78: movss [0x005A8ECC], xmm4
	X86_MEM_WRITE_u32(base, 0x5A8ECCu, ctx.xmm[4].u32[0]);
	// 0x2C1C80: movss [0x005A8EE0], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8EE0u, ctx.xmm[2].u32[0]);
	// 0x2C1C88: movss [0x005A8EE4], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8EE4u, ctx.xmm[3].u32[0]);
	// 0x2C1C90: movss [0x005A8EE8], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8EE8u, ctx.xmm[2].u32[0]);
	// 0x2C1C98: movss [0x005A8EEC], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8EECu, ctx.xmm[3].u32[0]);
	// 0x2C1CA0: movss [0x005A8EF0], xmm2
	X86_MEM_WRITE_u32(base, 0x5A8EF0u, ctx.xmm[2].u32[0]);
	// 0x2C1CA8: movss [0x005A8EF4], xmm3
	X86_MEM_WRITE_u32(base, 0x5A8EF4u, ctx.xmm[3].u32[0]);
	// 0x2C1CB0: movss [0x005A8F10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F10u, ctx.xmm[0].u32[0]);
	// 0x2C1CB8: movss [0x005A8F14], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8F14u, ctx.xmm[1].u32[0]);
	// 0x2C1CC0: movss [0x005A8F18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F18u, ctx.xmm[0].u32[0]);
	// 0x2C1CC8: movss [0x005A8F1C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8F1Cu, ctx.xmm[1].u32[0]);
	// 0x2C1CD0: movss [0x005A8F20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F20u, ctx.xmm[0].u32[0]);
	// 0x2C1CD8: movss [0x005A8F24], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8F24u, ctx.xmm[1].u32[0]);
	// 0x2C1CE0: movss [0x005A8F28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F28u, ctx.xmm[0].u32[0]);
	// 0x2C1CE8: movss [0x005A8F2C], xmm1
	X86_MEM_WRITE_u32(base, 0x5A8F2Cu, ctx.xmm[1].u32[0]);
	// 0x2C1CF0: ret
	return;
}

void sub_2C1D00(X86Context& ctx, uint8_t* base) {
	// 0x2C1D00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C1D08: movss [0x005A8F34], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F34u, ctx.xmm[0].u32[0]);
	// 0x2C1D10: ret
	return;
}

void sub_2C1D20(X86Context& ctx, uint8_t* base) {
	// 0x2C1D20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C1D28: movss [0x005A8F38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F38u, ctx.xmm[0].u32[0]);
	// 0x2C1D30: ret
	return;
}

void sub_2C1D40(X86Context& ctx, uint8_t* base) {
	// 0x2C1D40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C1D48: movss [0x005A8F30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F30u, ctx.xmm[0].u32[0]);
	// 0x2C1D50: ret
	return;
}

void sub_2C1D60(X86Context& ctx, uint8_t* base) {
	// 0x2C1D60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C1D68: movss [0x005A8F40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F40u, ctx.xmm[0].u32[0]);
	// 0x2C1D70: ret
	return;
}

void sub_2C1D80(X86Context& ctx, uint8_t* base) {
	// 0x2C1D80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C1D88: movss [0x005A8F44], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F44u, ctx.xmm[0].u32[0]);
	// 0x2C1D90: ret
	return;
}

void sub_2C1DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C1DA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C1DA8: movss [0x005A8F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F3Cu, ctx.xmm[0].u32[0]);
	// 0x2C1DB0: ret
	return;
}

void sub_2C1DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C1DC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C1DC8: movss [0x005A8F64], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F64u, ctx.xmm[0].u32[0]);
	// 0x2C1DD0: ret
	return;
}

void sub_2C1DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C1DE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C1DE8: movss [0x005A8F70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F70u, ctx.xmm[0].u32[0]);
	// 0x2C1DF0: ret
	return;
}

void sub_2C1E00(X86Context& ctx, uint8_t* base) {
	// 0x2C1E00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C1E08: movss [0x005A8F60], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F60u, ctx.xmm[0].u32[0]);
	// 0x2C1E10: ret
	return;
}

void sub_2C1E20(X86Context& ctx, uint8_t* base) {
	// 0x2C1E20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C1E28: movss [0x005A8F48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F48u, ctx.xmm[0].u32[0]);
	// 0x2C1E30: ret
	return;
}

void sub_2C1E40(X86Context& ctx, uint8_t* base) {
	// 0x2C1E40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C1E48: movss [0x005A8F68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F68u, ctx.xmm[0].u32[0]);
	// 0x2C1E50: ret
	return;
}

void sub_2C1E60(X86Context& ctx, uint8_t* base) {
	// 0x2C1E60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C1E68: movss [0x005A8F50], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F50u, ctx.xmm[0].u32[0]);
	// 0x2C1E70: ret
	return;
}

void sub_2C1E80(X86Context& ctx, uint8_t* base) {
	// 0x2C1E80: movss xmm0, dword ptr [0x005A8F68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8F68u);
	// 0x2C1E88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C1E90: movss [0x005A8F78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F78u, ctx.xmm[0].u32[0]);
	// 0x2C1E98: ret
	return;
}

void sub_2C1EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C1EA0: movss xmm0, dword ptr [0x005A8F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8F50u);
	// 0x2C1EA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C1EB0: movss [0x005A8F74], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F74u, ctx.xmm[0].u32[0]);
	// 0x2C1EB8: ret
	return;
}

void sub_2C1EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C1EC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C1EC8: movss [0x005A8F88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F88u, ctx.xmm[0].u32[0]);
	// 0x2C1ED0: ret
	return;
}

void sub_2C1EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C1EE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C1EE8: movss [0x005A8F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F7Cu, ctx.xmm[0].u32[0]);
	// 0x2C1EF0: ret
	return;
}

void sub_2C1F00(X86Context& ctx, uint8_t* base) {
	// 0x2C1F00: movss xmm0, dword ptr [0x005A8F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8F7Cu);
	// 0x2C1F08: movss [0x005A8F84], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F84u, ctx.xmm[0].u32[0]);
	// 0x2C1F10: ret
	return;
}

void sub_2C1F20(X86Context& ctx, uint8_t* base) {
	// 0x2C1F20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C1F28: movss [0x005A8F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F4Cu, ctx.xmm[0].u32[0]);
	// 0x2C1F30: ret
	return;
}

void sub_2C1F40(X86Context& ctx, uint8_t* base) {
	// 0x2C1F40: movss xmm0, dword ptr [0x005A8F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8F50u);
	// 0x2C1F48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C1F50: movss [0x005A8F80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F80u, ctx.xmm[0].u32[0]);
	// 0x2C1F58: ret
	return;
}

void sub_2C1F60(X86Context& ctx, uint8_t* base) {
	// 0x2C1F60: movss xmm0, dword ptr [0x005A8F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8F50u);
	// 0x2C1F68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C1F70: movss [0x005A8F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F5Cu, ctx.xmm[0].u32[0]);
	// 0x2C1F78: ret
	return;
}

void sub_2C1F80(X86Context& ctx, uint8_t* base) {
	// 0x2C1F80: movss xmm0, dword ptr [0x005A8F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8F50u);
	// 0x2C1F88: subss xmm0, [0x005A8F5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8F5Cu);
	// 0x2C1F90: movss [0x005A8F58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F58u, ctx.xmm[0].u32[0]);
	// 0x2C1F98: ret
	return;
}

void sub_2C1FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C1FA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C1FA8: movss [0x005A8F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F6Cu, ctx.xmm[0].u32[0]);
	// 0x2C1FB0: ret
	return;
}

void sub_2C1FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C1FC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C1FC8: movss [0x005A8F54], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F54u, ctx.xmm[0].u32[0]);
	// 0x2C1FD0: ret
	return;
}

void sub_2C1FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C1FE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C1FE8: movss [0x005A8F90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F90u, ctx.xmm[0].u32[0]);
	// 0x2C1FF0: ret
	return;
}

void sub_2C2000(X86Context& ctx, uint8_t* base) {
	// 0x2C2000: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2008: movss [0x005A8F94], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F94u, ctx.xmm[0].u32[0]);
	// 0x2C2010: ret
	return;
}

void sub_2C2020(X86Context& ctx, uint8_t* base) {
	// 0x2C2020: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2028: movss [0x005A8F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F8Cu, ctx.xmm[0].u32[0]);
	// 0x2C2030: ret
	return;
}

void sub_2C2040(X86Context& ctx, uint8_t* base) {
	// 0x2C2040: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2048: movss [0x005A8FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FA4u, ctx.xmm[0].u32[0]);
	// 0x2C2050: ret
	return;
}

void sub_2C2060(X86Context& ctx, uint8_t* base) {
	// 0x2C2060: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2068: movss [0x005A8FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FACu, ctx.xmm[0].u32[0]);
	// 0x2C2070: ret
	return;
}

void sub_2C2080(X86Context& ctx, uint8_t* base) {
	// 0x2C2080: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2088: movss [0x005A8FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FA0u, ctx.xmm[0].u32[0]);
	// 0x2C2090: ret
	return;
}

void sub_2C20A0(X86Context& ctx, uint8_t* base) {
	// 0x2C20A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C20A8: movss [0x005A8F98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F98u, ctx.xmm[0].u32[0]);
	// 0x2C20B0: ret
	return;
}

void sub_2C20C0(X86Context& ctx, uint8_t* base) {
	// 0x2C20C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C20C8: movss [0x005A8FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FA8u, ctx.xmm[0].u32[0]);
	// 0x2C20D0: ret
	return;
}

void sub_2C20E0(X86Context& ctx, uint8_t* base) {
	// 0x2C20E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C20E8: movss [0x005A8F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8F9Cu, ctx.xmm[0].u32[0]);
	// 0x2C20F0: ret
	return;
}

void sub_2C2100(X86Context& ctx, uint8_t* base) {
	// 0x2C2100: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2108: movss [0x005A8FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FD0u, ctx.xmm[0].u32[0]);
	// 0x2C2110: ret
	return;
}

void sub_2C2120(X86Context& ctx, uint8_t* base) {
	// 0x2C2120: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2128: movss [0x005A8FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FDCu, ctx.xmm[0].u32[0]);
	// 0x2C2130: ret
	return;
}

void sub_2C2140(X86Context& ctx, uint8_t* base) {
	// 0x2C2140: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2148: movss [0x005A8FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FC8u, ctx.xmm[0].u32[0]);
	// 0x2C2150: ret
	return;
}

void sub_2C2160(X86Context& ctx, uint8_t* base) {
	// 0x2C2160: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2168: movss [0x005A8FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FB0u, ctx.xmm[0].u32[0]);
	// 0x2C2170: ret
	return;
}

void sub_2C2180(X86Context& ctx, uint8_t* base) {
	// 0x2C2180: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2188: movss [0x005A8FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FD4u, ctx.xmm[0].u32[0]);
	// 0x2C2190: ret
	return;
}

void sub_2C21A0(X86Context& ctx, uint8_t* base) {
	// 0x2C21A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C21A8: movss [0x005A8FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FB4u, ctx.xmm[0].u32[0]);
	// 0x2C21B0: ret
	return;
}

void sub_2C21C0(X86Context& ctx, uint8_t* base) {
	// 0x2C21C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C21C8: movss [0x005A8FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FE4u, ctx.xmm[0].u32[0]);
	// 0x2C21D0: ret
	return;
}

void sub_2C21E0(X86Context& ctx, uint8_t* base) {
	// 0x2C21E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C21E8: movss [0x005A8FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FCCu, ctx.xmm[0].u32[0]);
	// 0x2C21F0: ret
	return;
}

void sub_2C2200(X86Context& ctx, uint8_t* base) {
	// 0x2C2200: movss xmm0, dword ptr [0x005A8FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FE4u);
	// 0x2C2208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C2210: movss [0x005A8FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FBCu, ctx.xmm[0].u32[0]);
	// 0x2C2218: ret
	return;
}

void sub_2C2220(X86Context& ctx, uint8_t* base) {
	// 0x2C2220: movss xmm0, dword ptr [0x005A8FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FCCu);
	// 0x2C2228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C2230: movss [0x005A8FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FE0u, ctx.xmm[0].u32[0]);
	// 0x2C2238: ret
	return;
}

void sub_2C2240(X86Context& ctx, uint8_t* base) {
	// 0x2C2240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2248: movss [0x005A8FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FF0u, ctx.xmm[0].u32[0]);
	// 0x2C2250: ret
	return;
}

void sub_2C2260(X86Context& ctx, uint8_t* base) {
	// 0x2C2260: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C2268: movss [0x005A8FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FE8u, ctx.xmm[0].u32[0]);
	// 0x2C2270: ret
	return;
}

void sub_2C2280(X86Context& ctx, uint8_t* base) {
	// 0x2C2280: movss xmm0, dword ptr [0x005A8FE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FE8u);
	// 0x2C2288: movss [0x005A8FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FECu, ctx.xmm[0].u32[0]);
	// 0x2C2290: ret
	return;
}

void sub_2C22A0(X86Context& ctx, uint8_t* base) {
	// 0x2C22A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C22A8: movss [0x005A8FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FC4u, ctx.xmm[0].u32[0]);
	// 0x2C22B0: ret
	return;
}

void sub_2C22C0(X86Context& ctx, uint8_t* base) {
	// 0x2C22C0: movss xmm0, dword ptr [0x005A8FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FCCu);
	// 0x2C22C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C22D0: movss [0x005A8FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FC0u, ctx.xmm[0].u32[0]);
	// 0x2C22D8: ret
	return;
}

void sub_2C22E0(X86Context& ctx, uint8_t* base) {
	// 0x2C22E0: movss xmm0, dword ptr [0x005A8FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FCCu);
	// 0x2C22E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C22F0: movss [0x005A8FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FD8u, ctx.xmm[0].u32[0]);
	// 0x2C22F8: ret
	return;
}

void sub_2C2300(X86Context& ctx, uint8_t* base) {
	// 0x2C2300: movss xmm0, dword ptr [0x005A8FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FCCu);
	// 0x2C2308: subss xmm0, [0x005A8FD8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8FD8u);
	// 0x2C2310: movss [0x005A8FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FB8u, ctx.xmm[0].u32[0]);
	// 0x2C2318: ret
	return;
}

void sub_2C2320(X86Context& ctx, uint8_t* base) {
	// 0x2C2320: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2328: movss [0x005A9010], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9010u, ctx.xmm[0].u32[0]);
	// 0x2C2330: ret
	return;
}

void sub_2C2340(X86Context& ctx, uint8_t* base) {
	// 0x2C2340: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2348: movss [0x005A901C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A901Cu, ctx.xmm[0].u32[0]);
	// 0x2C2350: ret
	return;
}

void sub_2C2360(X86Context& ctx, uint8_t* base) {
	// 0x2C2360: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2368: movss [0x005A900C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A900Cu, ctx.xmm[0].u32[0]);
	// 0x2C2370: ret
	return;
}

void sub_2C2380(X86Context& ctx, uint8_t* base) {
	// 0x2C2380: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2388: movss [0x005A8FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FF4u, ctx.xmm[0].u32[0]);
	// 0x2C2390: ret
	return;
}

void sub_2C23A0(X86Context& ctx, uint8_t* base) {
	// 0x2C23A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C23A8: movss [0x005A9014], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9014u, ctx.xmm[0].u32[0]);
	// 0x2C23B0: ret
	return;
}

void sub_2C23C0(X86Context& ctx, uint8_t* base) {
	// 0x2C23C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C23C8: movss [0x005A8FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FFCu, ctx.xmm[0].u32[0]);
	// 0x2C23D0: ret
	return;
}

void sub_2C23E0(X86Context& ctx, uint8_t* base) {
	// 0x2C23E0: movss xmm0, dword ptr [0x005A9014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9014u);
	// 0x2C23E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C23F0: movss [0x005A9024], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9024u, ctx.xmm[0].u32[0]);
	// 0x2C23F8: ret
	return;
}

void sub_2C2400(X86Context& ctx, uint8_t* base) {
	// 0x2C2400: movss xmm0, dword ptr [0x005A8FFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FFCu);
	// 0x2C2408: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C2410: movss [0x005A9020], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9020u, ctx.xmm[0].u32[0]);
	// 0x2C2418: ret
	return;
}

void sub_2C2420(X86Context& ctx, uint8_t* base) {
	// 0x2C2420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2428: movss [0x005A9034], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9034u, ctx.xmm[0].u32[0]);
	// 0x2C2430: ret
	return;
}

void sub_2C2440(X86Context& ctx, uint8_t* base) {
	// 0x2C2440: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C2448: movss [0x005A9028], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9028u, ctx.xmm[0].u32[0]);
	// 0x2C2450: ret
	return;
}

void sub_2C2460(X86Context& ctx, uint8_t* base) {
	// 0x2C2460: movss xmm0, dword ptr [0x005A9028]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9028u);
	// 0x2C2468: movss [0x005A9030], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9030u, ctx.xmm[0].u32[0]);
	// 0x2C2470: ret
	return;
}

void sub_2C2480(X86Context& ctx, uint8_t* base) {
	// 0x2C2480: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2488: movss [0x005A8FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8FF8u, ctx.xmm[0].u32[0]);
	// 0x2C2490: ret
	return;
}

void sub_2C24A0(X86Context& ctx, uint8_t* base) {
	// 0x2C24A0: movss xmm0, dword ptr [0x005A8FFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FFCu);
	// 0x2C24A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C24B0: movss [0x005A902C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A902Cu, ctx.xmm[0].u32[0]);
	// 0x2C24B8: ret
	return;
}

void sub_2C24C0(X86Context& ctx, uint8_t* base) {
	// 0x2C24C0: movss xmm0, dword ptr [0x005A8FFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FFCu);
	// 0x2C24C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C24D0: movss [0x005A9008], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9008u, ctx.xmm[0].u32[0]);
	// 0x2C24D8: ret
	return;
}

void sub_2C24E0(X86Context& ctx, uint8_t* base) {
	// 0x2C24E0: movss xmm0, dword ptr [0x005A8FFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8FFCu);
	// 0x2C24E8: subss xmm0, [0x005A9008]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9008u);
	// 0x2C24F0: movss [0x005A9004], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9004u, ctx.xmm[0].u32[0]);
	// 0x2C24F8: ret
	return;
}

void sub_2C2500(X86Context& ctx, uint8_t* base) {
	// 0x2C2500: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2508: movss [0x005A9018], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9018u, ctx.xmm[0].u32[0]);
	// 0x2C2510: ret
	return;
}

void sub_2C2520(X86Context& ctx, uint8_t* base) {
	// 0x2C2520: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2528: movss [0x005A9000], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9000u, ctx.xmm[0].u32[0]);
	// 0x2C2530: ret
	return;
}

void sub_2C2540(X86Context& ctx, uint8_t* base) {
	// 0x2C2540: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2548: movss [0x005A9054], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9054u, ctx.xmm[0].u32[0]);
	// 0x2C2550: ret
	return;
}

void sub_2C2560(X86Context& ctx, uint8_t* base) {
	// 0x2C2560: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2568: movss [0x005A9060], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9060u, ctx.xmm[0].u32[0]);
	// 0x2C2570: ret
	return;
}

void sub_2C2580(X86Context& ctx, uint8_t* base) {
	// 0x2C2580: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2588: movss [0x005A9050], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9050u, ctx.xmm[0].u32[0]);
	// 0x2C2590: ret
	return;
}

void sub_2C25A0(X86Context& ctx, uint8_t* base) {
	// 0x2C25A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C25A8: movss [0x005A9038], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9038u, ctx.xmm[0].u32[0]);
	// 0x2C25B0: ret
	return;
}

void sub_2C25C0(X86Context& ctx, uint8_t* base) {
	// 0x2C25C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C25C8: movss [0x005A9058], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9058u, ctx.xmm[0].u32[0]);
	// 0x2C25D0: ret
	return;
}

void sub_2C25E0(X86Context& ctx, uint8_t* base) {
	// 0x2C25E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C25E8: movss [0x005A9040], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9040u, ctx.xmm[0].u32[0]);
	// 0x2C25F0: ret
	return;
}

void sub_2C2600(X86Context& ctx, uint8_t* base) {
	// 0x2C2600: movss xmm0, dword ptr [0x005A9058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9058u);
	// 0x2C2608: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C2610: movss [0x005A9068], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9068u, ctx.xmm[0].u32[0]);
	// 0x2C2618: ret
	return;
}

void sub_2C2620(X86Context& ctx, uint8_t* base) {
	// 0x2C2620: movss xmm0, dword ptr [0x005A9040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9040u);
	// 0x2C2628: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C2630: movss [0x005A9064], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9064u, ctx.xmm[0].u32[0]);
	// 0x2C2638: ret
	return;
}

void sub_2C2640(X86Context& ctx, uint8_t* base) {
	// 0x2C2640: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2648: movss [0x005A9078], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9078u, ctx.xmm[0].u32[0]);
	// 0x2C2650: ret
	return;
}

void sub_2C2660(X86Context& ctx, uint8_t* base) {
	// 0x2C2660: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C2668: movss [0x005A906C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A906Cu, ctx.xmm[0].u32[0]);
	// 0x2C2670: ret
	return;
}

void sub_2C2680(X86Context& ctx, uint8_t* base) {
	// 0x2C2680: movss xmm0, dword ptr [0x005A906C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A906Cu);
	// 0x2C2688: movss [0x005A9074], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9074u, ctx.xmm[0].u32[0]);
	// 0x2C2690: ret
	return;
}

void sub_2C26A0(X86Context& ctx, uint8_t* base) {
	// 0x2C26A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C26A8: movss [0x005A903C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A903Cu, ctx.xmm[0].u32[0]);
	// 0x2C26B0: ret
	return;
}

void sub_2C26C0(X86Context& ctx, uint8_t* base) {
	// 0x2C26C0: movss xmm0, dword ptr [0x005A9040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9040u);
	// 0x2C26C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C26D0: movss [0x005A9070], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9070u, ctx.xmm[0].u32[0]);
	// 0x2C26D8: ret
	return;
}

void sub_2C26E0(X86Context& ctx, uint8_t* base) {
	// 0x2C26E0: movss xmm0, dword ptr [0x005A9040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9040u);
	// 0x2C26E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C26F0: movss [0x005A904C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A904Cu, ctx.xmm[0].u32[0]);
	// 0x2C26F8: ret
	return;
}

void sub_2C2700(X86Context& ctx, uint8_t* base) {
	// 0x2C2700: movss xmm0, dword ptr [0x005A9040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9040u);
	// 0x2C2708: subss xmm0, [0x005A904C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A904Cu);
	// 0x2C2710: movss [0x005A9048], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9048u, ctx.xmm[0].u32[0]);
	// 0x2C2718: ret
	return;
}

void sub_2C2720(X86Context& ctx, uint8_t* base) {
	// 0x2C2720: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2728: movss [0x005A905C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A905Cu, ctx.xmm[0].u32[0]);
	// 0x2C2730: ret
	return;
}

void sub_2C2740(X86Context& ctx, uint8_t* base) {
	// 0x2C2740: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2748: movss [0x005A9044], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9044u, ctx.xmm[0].u32[0]);
	// 0x2C2750: ret
	return;
}

void sub_2C2760(X86Context& ctx, uint8_t* base) {
	// 0x2C2760: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2768: movss [0x005A909C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A909Cu, ctx.xmm[0].u32[0]);
	// 0x2C2770: ret
	return;
}

void sub_2C2780(X86Context& ctx, uint8_t* base) {
	// 0x2C2780: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2788: movss [0x005A90A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90A8u, ctx.xmm[0].u32[0]);
	// 0x2C2790: ret
	return;
}

void sub_2C27A0(X86Context& ctx, uint8_t* base) {
	// 0x2C27A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C27A8: movss [0x005A9094], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9094u, ctx.xmm[0].u32[0]);
	// 0x2C27B0: ret
	return;
}

void sub_2C27C0(X86Context& ctx, uint8_t* base) {
	// 0x2C27C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C27C8: movss [0x005A907C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A907Cu, ctx.xmm[0].u32[0]);
	// 0x2C27D0: ret
	return;
}

void sub_2C27E0(X86Context& ctx, uint8_t* base) {
	// 0x2C27E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C27E8: movss [0x005A90A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90A0u, ctx.xmm[0].u32[0]);
	// 0x2C27F0: ret
	return;
}

void sub_2C2800(X86Context& ctx, uint8_t* base) {
	// 0x2C2800: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2808: movss [0x005A9080], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9080u, ctx.xmm[0].u32[0]);
	// 0x2C2810: ret
	return;
}

void sub_2C2820(X86Context& ctx, uint8_t* base) {
	// 0x2C2820: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C2828: movss [0x005A90B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90B0u, ctx.xmm[0].u32[0]);
	// 0x2C2830: ret
	return;
}

void sub_2C2840(X86Context& ctx, uint8_t* base) {
	// 0x2C2840: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C2848: movss [0x005A9098], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9098u, ctx.xmm[0].u32[0]);
	// 0x2C2850: ret
	return;
}

void sub_2C2860(X86Context& ctx, uint8_t* base) {
	// 0x2C2860: movss xmm0, dword ptr [0x005A90B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A90B0u);
	// 0x2C2868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C2870: movss [0x005A9088], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9088u, ctx.xmm[0].u32[0]);
	// 0x2C2878: ret
	return;
}

void sub_2C2880(X86Context& ctx, uint8_t* base) {
	// 0x2C2880: movss xmm0, dword ptr [0x005A9098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9098u);
	// 0x2C2888: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C2890: movss [0x005A90AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90ACu, ctx.xmm[0].u32[0]);
	// 0x2C2898: ret
	return;
}

void sub_2C28A0(X86Context& ctx, uint8_t* base) {
	// 0x2C28A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C28A8: movss [0x005A90BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90BCu, ctx.xmm[0].u32[0]);
	// 0x2C28B0: ret
	return;
}

void sub_2C28C0(X86Context& ctx, uint8_t* base) {
	// 0x2C28C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C28C8: movss [0x005A90B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90B4u, ctx.xmm[0].u32[0]);
	// 0x2C28D0: ret
	return;
}

void sub_2C28E0(X86Context& ctx, uint8_t* base) {
	// 0x2C28E0: movss xmm0, dword ptr [0x005A90B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A90B4u);
	// 0x2C28E8: movss [0x005A90B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90B8u, ctx.xmm[0].u32[0]);
	// 0x2C28F0: ret
	return;
}

void sub_2C2900(X86Context& ctx, uint8_t* base) {
	// 0x2C2900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2908: movss [0x005A9090], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9090u, ctx.xmm[0].u32[0]);
	// 0x2C2910: ret
	return;
}

void sub_2C2920(X86Context& ctx, uint8_t* base) {
	// 0x2C2920: movss xmm0, dword ptr [0x005A9098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9098u);
	// 0x2C2928: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C2930: movss [0x005A908C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A908Cu, ctx.xmm[0].u32[0]);
	// 0x2C2938: ret
	return;
}

void sub_2C2940(X86Context& ctx, uint8_t* base) {
	// 0x2C2940: movss xmm0, dword ptr [0x005A9098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9098u);
	// 0x2C2948: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C2950: movss [0x005A90A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90A4u, ctx.xmm[0].u32[0]);
	// 0x2C2958: ret
	return;
}

void sub_2C2960(X86Context& ctx, uint8_t* base) {
	// 0x2C2960: movss xmm0, dword ptr [0x005A9098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9098u);
	// 0x2C2968: subss xmm0, [0x005A90A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A90A4u);
	// 0x2C2970: movss [0x005A9084], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9084u, ctx.xmm[0].u32[0]);
	// 0x2C2978: ret
	return;
}

void sub_2C2980(X86Context& ctx, uint8_t* base) {
	// 0x2C2980: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2988: movss [0x005A90CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90CCu, ctx.xmm[0].u32[0]);
	// 0x2C2990: ret
	return;
}

void sub_2C29A0(X86Context& ctx, uint8_t* base) {
	// 0x2C29A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C29A8: movss [0x005A90D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90D4u, ctx.xmm[0].u32[0]);
	// 0x2C29B0: ret
	return;
}

void sub_2C29C0(X86Context& ctx, uint8_t* base) {
	// 0x2C29C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C29C8: movss [0x005A90C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90C8u, ctx.xmm[0].u32[0]);
	// 0x2C29D0: ret
	return;
}

void sub_2C29E0(X86Context& ctx, uint8_t* base) {
	// 0x2C29E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C29E8: movss [0x005A90C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90C0u, ctx.xmm[0].u32[0]);
	// 0x2C29F0: ret
	return;
}

void sub_2C2A00(X86Context& ctx, uint8_t* base) {
	// 0x2C2A00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2A08: movss [0x005A90D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90D0u, ctx.xmm[0].u32[0]);
	// 0x2C2A10: ret
	return;
}

void sub_2C2A20(X86Context& ctx, uint8_t* base) {
	// 0x2C2A20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2A28: movss [0x005A90C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90C4u, ctx.xmm[0].u32[0]);
	// 0x2C2A30: ret
	return;
}

void sub_2C2A40(X86Context& ctx, uint8_t* base) {
	// 0x2C2A40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2A48: movss [0x005A90E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90E4u, ctx.xmm[0].u32[0]);
	// 0x2C2A50: ret
	return;
}

void sub_2C2A60(X86Context& ctx, uint8_t* base) {
	// 0x2C2A60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2A68: movss [0x005A90EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90ECu, ctx.xmm[0].u32[0]);
	// 0x2C2A70: ret
	return;
}

void sub_2C2A80(X86Context& ctx, uint8_t* base) {
	// 0x2C2A80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2A88: movss [0x005A90E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90E0u, ctx.xmm[0].u32[0]);
	// 0x2C2A90: ret
	return;
}

void sub_2C2AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C2AA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2AA8: movss [0x005A90D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90D8u, ctx.xmm[0].u32[0]);
	// 0x2C2AB0: ret
	return;
}

void sub_2C2AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C2AC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2AC8: movss [0x005A90E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90E8u, ctx.xmm[0].u32[0]);
	// 0x2C2AD0: ret
	return;
}

void sub_2C2AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C2AE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2AE8: movss [0x005A90DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90DCu, ctx.xmm[0].u32[0]);
	// 0x2C2AF0: ret
	return;
}

void sub_2C2B00(X86Context& ctx, uint8_t* base) {
	// 0x2C2B00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2B08: movss [0x005A9110], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9110u, ctx.xmm[0].u32[0]);
	// 0x2C2B10: ret
	return;
}

void sub_2C2B20(X86Context& ctx, uint8_t* base) {
	// 0x2C2B20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2B28: movss [0x005A911C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A911Cu, ctx.xmm[0].u32[0]);
	// 0x2C2B30: ret
	return;
}

void sub_2C2B40(X86Context& ctx, uint8_t* base) {
	// 0x2C2B40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2B48: movss [0x005A9108], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9108u, ctx.xmm[0].u32[0]);
	// 0x2C2B50: ret
	return;
}

void sub_2C2B60(X86Context& ctx, uint8_t* base) {
	// 0x2C2B60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2B68: movss [0x005A90F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90F0u, ctx.xmm[0].u32[0]);
	// 0x2C2B70: ret
	return;
}

void sub_2C2B80(X86Context& ctx, uint8_t* base) {
	// 0x2C2B80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2B88: movss [0x005A9114], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9114u, ctx.xmm[0].u32[0]);
	// 0x2C2B90: ret
	return;
}

void sub_2C2BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C2BA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2BA8: movss [0x005A90F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90F4u, ctx.xmm[0].u32[0]);
	// 0x2C2BB0: ret
	return;
}

void sub_2C2BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C2BC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C2BC8: movss [0x005A9124], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9124u, ctx.xmm[0].u32[0]);
	// 0x2C2BD0: ret
	return;
}

void sub_2C2BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C2BE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C2BE8: movss [0x005A910C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A910Cu, ctx.xmm[0].u32[0]);
	// 0x2C2BF0: ret
	return;
}

void sub_2C2C00(X86Context& ctx, uint8_t* base) {
	// 0x2C2C00: movss xmm0, dword ptr [0x005A9124]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9124u);
	// 0x2C2C08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C2C10: movss [0x005A90FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90FCu, ctx.xmm[0].u32[0]);
	// 0x2C2C18: ret
	return;
}

void sub_2C2C20(X86Context& ctx, uint8_t* base) {
	// 0x2C2C20: movss xmm0, dword ptr [0x005A910C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A910Cu);
	// 0x2C2C28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C2C30: movss [0x005A9120], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9120u, ctx.xmm[0].u32[0]);
	// 0x2C2C38: ret
	return;
}

void sub_2C2C40(X86Context& ctx, uint8_t* base) {
	// 0x2C2C40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2C48: movss [0x005A9130], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9130u, ctx.xmm[0].u32[0]);
	// 0x2C2C50: ret
	return;
}

void sub_2C2C60(X86Context& ctx, uint8_t* base) {
	// 0x2C2C60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C2C68: movss [0x005A9128], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9128u, ctx.xmm[0].u32[0]);
	// 0x2C2C70: ret
	return;
}

void sub_2C2C80(X86Context& ctx, uint8_t* base) {
	// 0x2C2C80: movss xmm0, dword ptr [0x005A9128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9128u);
	// 0x2C2C88: movss [0x005A912C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A912Cu, ctx.xmm[0].u32[0]);
	// 0x2C2C90: ret
	return;
}

void sub_2C2CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C2CA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C2CA8: movss [0x005A9104], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9104u, ctx.xmm[0].u32[0]);
	// 0x2C2CB0: ret
	return;
}

void sub_2C2CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C2CC0: movss xmm0, dword ptr [0x005A910C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A910Cu);
	// 0x2C2CC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C2CD0: movss [0x005A9100], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9100u, ctx.xmm[0].u32[0]);
	// 0x2C2CD8: ret
	return;
}

void sub_2C2CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C2CE0: movss xmm0, dword ptr [0x005A910C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A910Cu);
	// 0x2C2CE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C2CF0: movss [0x005A9118], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9118u, ctx.xmm[0].u32[0]);
	// 0x2C2CF8: ret
	return;
}

void sub_2C2D00(X86Context& ctx, uint8_t* base) {
	// 0x2C2D00: movss xmm0, dword ptr [0x005A910C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A910Cu);
	// 0x2C2D08: subss xmm0, [0x005A9118]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9118u);
	// 0x2C2D10: movss [0x005A90F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A90F8u, ctx.xmm[0].u32[0]);
	// 0x2C2D18: ret
	return;
}

void sub_2C2D20(X86Context& ctx, uint8_t* base) {
	// 0x2C2D20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2D28: movss [0x005A9140], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9140u, ctx.xmm[0].u32[0]);
	// 0x2C2D30: ret
	return;
}

void sub_2C2D40(X86Context& ctx, uint8_t* base) {
	// 0x2C2D40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2D48: movss [0x005A9148], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9148u, ctx.xmm[0].u32[0]);
	// 0x2C2D50: ret
	return;
}

void sub_2C2D60(X86Context& ctx, uint8_t* base) {
	// 0x2C2D60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2D68: movss [0x005A913C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A913Cu, ctx.xmm[0].u32[0]);
	// 0x2C2D70: ret
	return;
}

void sub_2C2D80(X86Context& ctx, uint8_t* base) {
	// 0x2C2D80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2D88: movss [0x005A9134], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9134u, ctx.xmm[0].u32[0]);
	// 0x2C2D90: ret
	return;
}

void sub_2C2DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C2DA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2DA8: movss [0x005A9144], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9144u, ctx.xmm[0].u32[0]);
	// 0x2C2DB0: ret
	return;
}

void sub_2C2DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C2DC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2DC8: movss [0x005A9138], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9138u, ctx.xmm[0].u32[0]);
	// 0x2C2DD0: ret
	return;
}

void sub_2C2DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C2DE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2DE8: movss [0x005A9158], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9158u, ctx.xmm[0].u32[0]);
	// 0x2C2DF0: ret
	return;
}

void sub_2C2E00(X86Context& ctx, uint8_t* base) {
	// 0x2C2E00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2E08: movss [0x005A9160], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9160u, ctx.xmm[0].u32[0]);
	// 0x2C2E10: ret
	return;
}

void sub_2C2E20(X86Context& ctx, uint8_t* base) {
	// 0x2C2E20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2E28: movss [0x005A9154], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9154u, ctx.xmm[0].u32[0]);
	// 0x2C2E30: ret
	return;
}

void sub_2C2E40(X86Context& ctx, uint8_t* base) {
	// 0x2C2E40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2E48: movss [0x005A914C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A914Cu, ctx.xmm[0].u32[0]);
	// 0x2C2E50: ret
	return;
}

void sub_2C2E60(X86Context& ctx, uint8_t* base) {
	// 0x2C2E60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2E68: movss [0x005A915C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A915Cu, ctx.xmm[0].u32[0]);
	// 0x2C2E70: ret
	return;
}

void sub_2C2E80(X86Context& ctx, uint8_t* base) {
	// 0x2C2E80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2E88: movss [0x005A9150], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9150u, ctx.xmm[0].u32[0]);
	// 0x2C2E90: ret
	return;
}

void sub_2C2EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C2EA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2EA8: movss [0x005A9170], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9170u, ctx.xmm[0].u32[0]);
	// 0x2C2EB0: ret
	return;
}

void sub_2C2EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C2EC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2EC8: movss [0x005A9178], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9178u, ctx.xmm[0].u32[0]);
	// 0x2C2ED0: ret
	return;
}

void sub_2C2EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C2EE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2EE8: movss [0x005A916C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A916Cu, ctx.xmm[0].u32[0]);
	// 0x2C2EF0: ret
	return;
}

void sub_2C2F00(X86Context& ctx, uint8_t* base) {
	// 0x2C2F00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2F08: movss [0x005A9164], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9164u, ctx.xmm[0].u32[0]);
	// 0x2C2F10: ret
	return;
}

void sub_2C2F20(X86Context& ctx, uint8_t* base) {
	// 0x2C2F20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C2F28: movss [0x005A9174], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9174u, ctx.xmm[0].u32[0]);
	// 0x2C2F30: ret
	return;
}

void sub_2C2F40(X86Context& ctx, uint8_t* base) {
	// 0x2C2F40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C2F48: movss [0x005A9168], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9168u, ctx.xmm[0].u32[0]);
	// 0x2C2F50: ret
	return;
}

void sub_2C2F60(X86Context& ctx, uint8_t* base) {
	// 0x2C2F60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C2F68: movss [0x005A9198], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9198u, ctx.xmm[0].u32[0]);
	// 0x2C2F70: ret
	return;
}

void sub_2C2F80(X86Context& ctx, uint8_t* base) {
	// 0x2C2F80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C2F88: movss [0x005A91A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91A4u, ctx.xmm[0].u32[0]);
	// 0x2C2F90: ret
	return;
}

void sub_2C2FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C2FA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C2FA8: movss [0x005A9194], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9194u, ctx.xmm[0].u32[0]);
	// 0x2C2FB0: ret
	return;
}

void sub_2C2FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C2FC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C2FC8: movss [0x005A917C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A917Cu, ctx.xmm[0].u32[0]);
	// 0x2C2FD0: ret
	return;
}

void sub_2C2FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C2FE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C2FE8: movss [0x005A919C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A919Cu, ctx.xmm[0].u32[0]);
	// 0x2C2FF0: ret
	return;
}

void sub_2C3000(X86Context& ctx, uint8_t* base) {
	// 0x2C3000: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3008: movss [0x005A9184], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9184u, ctx.xmm[0].u32[0]);
	// 0x2C3010: ret
	return;
}

void sub_2C3020(X86Context& ctx, uint8_t* base) {
	// 0x2C3020: movss xmm0, dword ptr [0x005A919C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A919Cu);
	// 0x2C3028: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C3030: movss [0x005A91AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91ACu, ctx.xmm[0].u32[0]);
	// 0x2C3038: ret
	return;
}

void sub_2C3040(X86Context& ctx, uint8_t* base) {
	// 0x2C3040: movss xmm0, dword ptr [0x005A9184]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9184u);
	// 0x2C3048: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C3050: movss [0x005A91A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91A8u, ctx.xmm[0].u32[0]);
	// 0x2C3058: ret
	return;
}

void sub_2C3060(X86Context& ctx, uint8_t* base) {
	// 0x2C3060: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3068: movss [0x005A91BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91BCu, ctx.xmm[0].u32[0]);
	// 0x2C3070: ret
	return;
}

void sub_2C3080(X86Context& ctx, uint8_t* base) {
	// 0x2C3080: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C3088: movss [0x005A91B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91B0u, ctx.xmm[0].u32[0]);
	// 0x2C3090: ret
	return;
}

void sub_2C30A0(X86Context& ctx, uint8_t* base) {
	// 0x2C30A0: movss xmm0, dword ptr [0x005A91B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91B0u);
	// 0x2C30A8: movss [0x005A91B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91B8u, ctx.xmm[0].u32[0]);
	// 0x2C30B0: ret
	return;
}

void sub_2C30C0(X86Context& ctx, uint8_t* base) {
	// 0x2C30C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C30C8: movss [0x005A9180], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9180u, ctx.xmm[0].u32[0]);
	// 0x2C30D0: ret
	return;
}

void sub_2C30E0(X86Context& ctx, uint8_t* base) {
	// 0x2C30E0: movss xmm0, dword ptr [0x005A9184]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9184u);
	// 0x2C30E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C30F0: movss [0x005A91B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91B4u, ctx.xmm[0].u32[0]);
	// 0x2C30F8: ret
	return;
}

void sub_2C3100(X86Context& ctx, uint8_t* base) {
	// 0x2C3100: movss xmm0, dword ptr [0x005A9184]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9184u);
	// 0x2C3108: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C3110: movss [0x005A9190], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9190u, ctx.xmm[0].u32[0]);
	// 0x2C3118: ret
	return;
}

void sub_2C3120(X86Context& ctx, uint8_t* base) {
	// 0x2C3120: movss xmm0, dword ptr [0x005A9184]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9184u);
	// 0x2C3128: subss xmm0, [0x005A9190]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9190u);
	// 0x2C3130: movss [0x005A918C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A918Cu, ctx.xmm[0].u32[0]);
	// 0x2C3138: ret
	return;
}

void sub_2C3140(X86Context& ctx, uint8_t* base) {
	// 0x2C3140: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C3148: movss [0x005A91A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91A0u, ctx.xmm[0].u32[0]);
	// 0x2C3150: ret
	return;
}

void sub_2C3160(X86Context& ctx, uint8_t* base) {
	// 0x2C3160: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C3168: movss [0x005A9188], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9188u, ctx.xmm[0].u32[0]);
	// 0x2C3170: ret
	return;
}

void sub_2C3180(X86Context& ctx, uint8_t* base) {
	// 0x2C3180: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C3188: movss [0x005A91DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91DCu, ctx.xmm[0].u32[0]);
	// 0x2C3190: ret
	return;
}

void sub_2C31A0(X86Context& ctx, uint8_t* base) {
	// 0x2C31A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C31A8: movss [0x005A91E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91E8u, ctx.xmm[0].u32[0]);
	// 0x2C31B0: ret
	return;
}

void sub_2C31C0(X86Context& ctx, uint8_t* base) {
	// 0x2C31C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C31C8: movss [0x005A91D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91D8u, ctx.xmm[0].u32[0]);
	// 0x2C31D0: ret
	return;
}

void sub_2C31E0(X86Context& ctx, uint8_t* base) {
	// 0x2C31E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C31E8: movss [0x005A91C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91C0u, ctx.xmm[0].u32[0]);
	// 0x2C31F0: ret
	return;
}

void sub_2C3200(X86Context& ctx, uint8_t* base) {
	// 0x2C3200: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C3208: movss [0x005A91E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91E0u, ctx.xmm[0].u32[0]);
	// 0x2C3210: ret
	return;
}

void sub_2C3220(X86Context& ctx, uint8_t* base) {
	// 0x2C3220: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3228: movss [0x005A91C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91C8u, ctx.xmm[0].u32[0]);
	// 0x2C3230: ret
	return;
}

void sub_2C3240(X86Context& ctx, uint8_t* base) {
	// 0x2C3240: movss xmm0, dword ptr [0x005A91E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91E0u);
	// 0x2C3248: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C3250: movss [0x005A91F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91F0u, ctx.xmm[0].u32[0]);
	// 0x2C3258: ret
	return;
}

void sub_2C3260(X86Context& ctx, uint8_t* base) {
	// 0x2C3260: movss xmm0, dword ptr [0x005A91C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91C8u);
	// 0x2C3268: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C3270: movss [0x005A91EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91ECu, ctx.xmm[0].u32[0]);
	// 0x2C3278: ret
	return;
}

void sub_2C3280(X86Context& ctx, uint8_t* base) {
	// 0x2C3280: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3288: movss [0x005A9200], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9200u, ctx.xmm[0].u32[0]);
	// 0x2C3290: ret
	return;
}

void sub_2C32A0(X86Context& ctx, uint8_t* base) {
	// 0x2C32A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C32A8: movss [0x005A91F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91F4u, ctx.xmm[0].u32[0]);
	// 0x2C32B0: ret
	return;
}

void sub_2C32C0(X86Context& ctx, uint8_t* base) {
	// 0x2C32C0: movss xmm0, dword ptr [0x005A91F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91F4u);
	// 0x2C32C8: movss [0x005A91FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91FCu, ctx.xmm[0].u32[0]);
	// 0x2C32D0: ret
	return;
}

void sub_2C32E0(X86Context& ctx, uint8_t* base) {
	// 0x2C32E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C32E8: movss [0x005A91C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91C4u, ctx.xmm[0].u32[0]);
	// 0x2C32F0: ret
	return;
}

void sub_2C3300(X86Context& ctx, uint8_t* base) {
	// 0x2C3300: movss xmm0, dword ptr [0x005A91C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91C8u);
	// 0x2C3308: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C3310: movss [0x005A91F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91F8u, ctx.xmm[0].u32[0]);
	// 0x2C3318: ret
	return;
}

void sub_2C3320(X86Context& ctx, uint8_t* base) {
	// 0x2C3320: movss xmm0, dword ptr [0x005A91C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91C8u);
	// 0x2C3328: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C3330: movss [0x005A91D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91D4u, ctx.xmm[0].u32[0]);
	// 0x2C3338: ret
	return;
}

void sub_2C3340(X86Context& ctx, uint8_t* base) {
	// 0x2C3340: movss xmm0, dword ptr [0x005A91C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A91C8u);
	// 0x2C3348: subss xmm0, [0x005A91D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A91D4u);
	// 0x2C3350: movss [0x005A91D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91D0u, ctx.xmm[0].u32[0]);
	// 0x2C3358: ret
	return;
}

void sub_2C3360(X86Context& ctx, uint8_t* base) {
	// 0x2C3360: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C3368: movss [0x005A91E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91E4u, ctx.xmm[0].u32[0]);
	// 0x2C3370: ret
	return;
}

void sub_2C3380(X86Context& ctx, uint8_t* base) {
	// 0x2C3380: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C3388: movss [0x005A91CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A91CCu, ctx.xmm[0].u32[0]);
	// 0x2C3390: ret
	return;
}

void sub_2C33A0(X86Context& ctx, uint8_t* base) {
	// 0x2C33A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C33A8: movss [0x005A9224], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9224u, ctx.xmm[0].u32[0]);
	// 0x2C33B0: ret
	return;
}

void sub_2C33C0(X86Context& ctx, uint8_t* base) {
	// 0x2C33C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C33C8: movss [0x005A9230], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9230u, ctx.xmm[0].u32[0]);
	// 0x2C33D0: ret
	return;
}

void sub_2C33E0(X86Context& ctx, uint8_t* base) {
	// 0x2C33E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C33E8: movss [0x005A921C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A921Cu, ctx.xmm[0].u32[0]);
	// 0x2C33F0: ret
	return;
}

void sub_2C3400(X86Context& ctx, uint8_t* base) {
	// 0x2C3400: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C3408: movss [0x005A9204], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9204u, ctx.xmm[0].u32[0]);
	// 0x2C3410: ret
	return;
}

void sub_2C3420(X86Context& ctx, uint8_t* base) {
	// 0x2C3420: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C3428: movss [0x005A9228], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9228u, ctx.xmm[0].u32[0]);
	// 0x2C3430: ret
	return;
}

void sub_2C3440(X86Context& ctx, uint8_t* base) {
	// 0x2C3440: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C3448: movss [0x005A9208], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9208u, ctx.xmm[0].u32[0]);
	// 0x2C3450: ret
	return;
}

void sub_2C3460(X86Context& ctx, uint8_t* base) {
	// 0x2C3460: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C3468: movss [0x005A9238], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9238u, ctx.xmm[0].u32[0]);
	// 0x2C3470: ret
	return;
}

void sub_2C3480(X86Context& ctx, uint8_t* base) {
	// 0x2C3480: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3488: movss [0x005A9220], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9220u, ctx.xmm[0].u32[0]);
	// 0x2C3490: ret
	return;
}

void sub_2C34A0(X86Context& ctx, uint8_t* base) {
	// 0x2C34A0: movss xmm0, dword ptr [0x005A9238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9238u);
	// 0x2C34A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C34B0: movss [0x005A9210], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9210u, ctx.xmm[0].u32[0]);
	// 0x2C34B8: ret
	return;
}

void sub_2C34C0(X86Context& ctx, uint8_t* base) {
	// 0x2C34C0: movss xmm0, dword ptr [0x005A9220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9220u);
	// 0x2C34C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C34D0: movss [0x005A9234], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9234u, ctx.xmm[0].u32[0]);
	// 0x2C34D8: ret
	return;
}

