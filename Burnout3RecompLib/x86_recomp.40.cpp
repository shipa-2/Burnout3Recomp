#include "x86_recomp_shared.h"

void sub_2711F0(X86Context& ctx, uint8_t* base) {
	// 0x2711F0: movss xmm0, dword ptr [0x005686DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686DCu);
	// 0x2711F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
}

void sub_271200(X86Context& ctx, uint8_t* base) {
	// 0x271200: movss [0x005686A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5686A4u, ctx.xmm[0].u32[0]);
	// 0x271208: ret
	return;
}

void sub_271210(X86Context& ctx, uint8_t* base) {
	// 0x271210: movss xmm0, dword ptr [0x0056865C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56865Cu);
	// 0x271218: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x271220: movss [0x005686B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5686B8u, ctx.xmm[0].u32[0]);
	// 0x271228: ret
	return;
}

void sub_271230(X86Context& ctx, uint8_t* base) {
	// 0x271230: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x271238: movss [0x00568654], xmm0
	X86_MEM_WRITE_u32(base, 0x568654u, ctx.xmm[0].u32[0]);
	// 0x271240: ret
	return;
}

void sub_271250(X86Context& ctx, uint8_t* base) {
	// 0x271250: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x271258: movss [0x00568688], xmm0
	X86_MEM_WRITE_u32(base, 0x568688u, ctx.xmm[0].u32[0]);
	// 0x271260: ret
	return;
}

void sub_271270(X86Context& ctx, uint8_t* base) {
	// 0x271270: movss xmm0, dword ptr [0x00568684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568684u);
	// 0x271278: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x271280: movss [0x00568694], xmm0
	X86_MEM_WRITE_u32(base, 0x568694u, ctx.xmm[0].u32[0]);
	// 0x271288: ret
	return;
}

void sub_271290(X86Context& ctx, uint8_t* base) {
	// 0x271290: movss xmm0, dword ptr [0x005686DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686DCu);
	// 0x271298: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2712A0: movss [0x005686E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5686E0u, ctx.xmm[0].u32[0]);
	// 0x2712A8: ret
	return;
}

void sub_2712B0(X86Context& ctx, uint8_t* base) {
	// 0x2712B0: movss xmm0, dword ptr [0x00568694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568694u);
	// 0x2712B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2712C0: movss [0x005686CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5686CCu, ctx.xmm[0].u32[0]);
	// 0x2712C8: ret
	return;
}

void sub_2712D0(X86Context& ctx, uint8_t* base) {
	// 0x2712D0: movss xmm0, dword ptr [0x005686E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686E0u);
	// 0x2712D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2712E0: movss [0x005686F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5686F0u, ctx.xmm[0].u32[0]);
	// 0x2712E8: ret
	return;
}

void sub_2712F0(X86Context& ctx, uint8_t* base) {
	// 0x2712F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2712F8: movss [0x00568660], xmm0
	X86_MEM_WRITE_u32(base, 0x568660u, ctx.xmm[0].u32[0]);
	// 0x271300: ret
	return;
}

void sub_271310(X86Context& ctx, uint8_t* base) {
	// 0x271310: movss xmm0, dword ptr [0x00568684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568684u);
	// 0x271318: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271320: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x271328: movss [0x005686D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5686D8u, ctx.xmm[0].u32[0]);
	// 0x271330: ret
	return;
}

void sub_271340(X86Context& ctx, uint8_t* base) {
	// 0x271340: movss xmm0, dword ptr [0x005686DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686DCu);
	// 0x271348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271350: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x271358: movss [0x00568678], xmm0
	X86_MEM_WRITE_u32(base, 0x568678u, ctx.xmm[0].u32[0]);
	// 0x271360: ret
	return;
}

void sub_271370(X86Context& ctx, uint8_t* base) {
	// 0x271370: movss xmm0, dword ptr [0x00568684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568684u);
	// 0x271378: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271380: movss [0x0056867C], xmm0
	X86_MEM_WRITE_u32(base, 0x56867Cu, ctx.xmm[0].u32[0]);
	// 0x271388: ret
	return;
}

void sub_271390(X86Context& ctx, uint8_t* base) {
	// 0x271390: movss xmm0, dword ptr [0x005686DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686DCu);
	// 0x271398: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2713A0: movss [0x005686E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5686E4u, ctx.xmm[0].u32[0]);
	// 0x2713A8: ret
	return;
}

void sub_2713B0(X86Context& ctx, uint8_t* base) {
	// 0x2713B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2713B8: movss [0x00568664], xmm0
	X86_MEM_WRITE_u32(base, 0x568664u, ctx.xmm[0].u32[0]);
	// 0x2713C0: ret
	return;
}

void sub_2713D0(X86Context& ctx, uint8_t* base) {
	// 0x2713D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2713D8: movss [0x00568690], xmm0
	X86_MEM_WRITE_u32(base, 0x568690u, ctx.xmm[0].u32[0]);
	// 0x2713E0: ret
	return;
}

void sub_2713F0(X86Context& ctx, uint8_t* base) {
	// 0x2713F0: movss xmm0, dword ptr [0x00568664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568664u);
	// 0x2713F8: movss [0x005686F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5686F8u, ctx.xmm[0].u32[0]);
	// 0x271400: ret
	return;
}

void sub_271410(X86Context& ctx, uint8_t* base) {
	// 0x271410: movss xmm0, dword ptr [0x005686DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686DCu);
	// 0x271418: subss xmm0, [0x00568664]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568664u);
	// 0x271420: movss [0x005686BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5686BCu, ctx.xmm[0].u32[0]);
	// 0x271428: ret
	return;
}

void sub_271430(X86Context& ctx, uint8_t* base) {
	// 0x271430: movss xmm0, dword ptr [0x005686BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686BCu);
	// 0x271438: subss xmm0, [0x00568690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568690u);
	// 0x271440: movss [0x005686B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5686B4u, ctx.xmm[0].u32[0]);
	// 0x271448: ret
	return;
}

void sub_271450(X86Context& ctx, uint8_t* base) {
	// 0x271450: movss xmm0, dword ptr [0x005686E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686E4u);
	// 0x271458: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x271460: movss [0x005686A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5686A0u, ctx.xmm[0].u32[0]);
	// 0x271468: ret
	return;
}

void sub_271470(X86Context& ctx, uint8_t* base) {
	// 0x271470: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x271478: movss [0x0056868C], xmm0
	X86_MEM_WRITE_u32(base, 0x56868Cu, ctx.xmm[0].u32[0]);
	// 0x271480: ret
	return;
}

void sub_271490(X86Context& ctx, uint8_t* base) {
	// 0x271490: movss xmm0, dword ptr [0x005686A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686A0u);
	// 0x271498: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2714A0: movss [0x005686D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5686D4u, ctx.xmm[0].u32[0]);
	// 0x2714A8: ret
	return;
}

void sub_2714B0(X86Context& ctx, uint8_t* base) {
	// 0x2714B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2714B8: movss [0x005686A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5686A8u, ctx.xmm[0].u32[0]);
	// 0x2714C0: ret
	return;
}

void sub_2714D0(X86Context& ctx, uint8_t* base) {
	// 0x2714D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2714D8: movss [0x00568680], xmm0
	X86_MEM_WRITE_u32(base, 0x568680u, ctx.xmm[0].u32[0]);
	// 0x2714E0: ret
	return;
}

void sub_2714F0(X86Context& ctx, uint8_t* base) {
	// 0x2714F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2714F8: movss [0x00568760], xmm0
	X86_MEM_WRITE_u32(base, 0x568760u, ctx.xmm[0].u32[0]);
	// 0x271500: ret
	return;
}

void sub_271510(X86Context& ctx, uint8_t* base) {
	// 0x271510: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x271518: movss [0x0056877C], xmm0
	X86_MEM_WRITE_u32(base, 0x56877Cu, ctx.xmm[0].u32[0]);
	// 0x271520: ret
	return;
}

void sub_271530(X86Context& ctx, uint8_t* base) {
	// 0x271530: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x271538: movss [0x00568750], xmm0
	X86_MEM_WRITE_u32(base, 0x568750u, ctx.xmm[0].u32[0]);
	// 0x271540: ret
	return;
}

void sub_271550(X86Context& ctx, uint8_t* base) {
	// 0x271550: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x271558: movss [0x00568704], xmm0
	X86_MEM_WRITE_u32(base, 0x568704u, ctx.xmm[0].u32[0]);
	// 0x271560: ret
	return;
}

void sub_271570(X86Context& ctx, uint8_t* base) {
	// 0x271570: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x271578: movss [0x00568764], xmm0
	X86_MEM_WRITE_u32(base, 0x568764u, ctx.xmm[0].u32[0]);
	// 0x271580: ret
	return;
}

void sub_271590(X86Context& ctx, uint8_t* base) {
	// 0x271590: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x271598: movss [0x00568720], xmm0
	X86_MEM_WRITE_u32(base, 0x568720u, ctx.xmm[0].u32[0]);
	// 0x2715A0: ret
	return;
}

void sub_2715B0(X86Context& ctx, uint8_t* base) {
	// 0x2715B0: movss xmm0, dword ptr [0x00568764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568764u);
	// 0x2715B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2715C0: movss [0x0056879C], xmm0
	X86_MEM_WRITE_u32(base, 0x56879Cu, ctx.xmm[0].u32[0]);
	// 0x2715C8: ret
	return;
}

void sub_2715D0(X86Context& ctx, uint8_t* base) {
	// 0x2715D0: movss xmm0, dword ptr [0x00568720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568720u);
	// 0x2715D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2715E0: movss [0x00568784], xmm0
	X86_MEM_WRITE_u32(base, 0x568784u, ctx.xmm[0].u32[0]);
	// 0x2715E8: ret
	return;
}

void sub_2715F0(X86Context& ctx, uint8_t* base) {
	// 0x2715F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2715F8: movss [0x005687B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5687B4u, ctx.xmm[0].u32[0]);
	// 0x271600: ret
	return;
}

void sub_271610(X86Context& ctx, uint8_t* base) {
	// 0x271610: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x271618: movss [0x005687A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5687A0u, ctx.xmm[0].u32[0]);
	// 0x271620: ret
	return;
}

void sub_271630(X86Context& ctx, uint8_t* base) {
	// 0x271630: movss xmm0, dword ptr [0x005687A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687A0u);
	// 0x271638: movss [0x005687B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5687B0u, ctx.xmm[0].u32[0]);
	// 0x271640: ret
	return;
}

void sub_271650(X86Context& ctx, uint8_t* base) {
	// 0x271650: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x271658: movss [0x0056870C], xmm0
	X86_MEM_WRITE_u32(base, 0x56870Cu, ctx.xmm[0].u32[0]);
	// 0x271660: ret
	return;
}

void sub_271670(X86Context& ctx, uint8_t* base) {
	// 0x271670: movss xmm0, dword ptr [0x00568720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568720u);
	// 0x271678: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x271680: movss [0x005687A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5687A8u, ctx.xmm[0].u32[0]);
	// 0x271688: ret
	return;
}

void sub_271690(X86Context& ctx, uint8_t* base) {
	// 0x271690: movss xmm0, dword ptr [0x00568720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568720u);
	// 0x271698: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2716A0: movss [0x0056874C], xmm0
	X86_MEM_WRITE_u32(base, 0x56874Cu, ctx.xmm[0].u32[0]);
	// 0x2716A8: ret
	return;
}

void sub_2716B0(X86Context& ctx, uint8_t* base) {
	// 0x2716B0: movss xmm0, dword ptr [0x00568720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568720u);
	// 0x2716B8: subss xmm0, [0x0056874C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56874Cu);
	// 0x2716C0: movss [0x00568728], xmm0
	X86_MEM_WRITE_u32(base, 0x568728u, ctx.xmm[0].u32[0]);
	// 0x2716C8: ret
	return;
}

void sub_2716D0(X86Context& ctx, uint8_t* base) {
	// 0x2716D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2716D8: movss [0x00568778], xmm0
	X86_MEM_WRITE_u32(base, 0x568778u, ctx.xmm[0].u32[0]);
	// 0x2716E0: ret
	return;
}

void sub_2716F0(X86Context& ctx, uint8_t* base) {
	// 0x2716F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2716F8: movss [0x00568724], xmm0
	X86_MEM_WRITE_u32(base, 0x568724u, ctx.xmm[0].u32[0]);
	// 0x271700: ret
	return;
}

void sub_271710(X86Context& ctx, uint8_t* base) {
	// 0x271710: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x271718: movss [0x00568738], xmm0
	X86_MEM_WRITE_u32(base, 0x568738u, ctx.xmm[0].u32[0]);
	// 0x271720: ret
	return;
}

void sub_271730(X86Context& ctx, uint8_t* base) {
	// 0x271730: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x271738: movss [0x00568790], xmm0
	X86_MEM_WRITE_u32(base, 0x568790u, ctx.xmm[0].u32[0]);
	// 0x271740: ret
	return;
}

void sub_271750(X86Context& ctx, uint8_t* base) {
	// 0x271750: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x271758: movss [0x00568774], xmm0
	X86_MEM_WRITE_u32(base, 0x568774u, ctx.xmm[0].u32[0]);
	// 0x271760: ret
	return;
}

void sub_271770(X86Context& ctx, uint8_t* base) {
	// 0x271770: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x271778: movss [0x0056871C], xmm0
	X86_MEM_WRITE_u32(base, 0x56871Cu, ctx.xmm[0].u32[0]);
	// 0x271780: ret
	return;
}

void sub_271790(X86Context& ctx, uint8_t* base) {
	// 0x271790: movss xmm0, dword ptr [0x00568738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568738u);
	// 0x271798: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2717A0: movss [0x00568710], xmm0
	X86_MEM_WRITE_u32(base, 0x568710u, ctx.xmm[0].u32[0]);
	// 0x2717A8: ret
	return;
}

void sub_2717B0(X86Context& ctx, uint8_t* base) {
	// 0x2717B0: movss xmm0, dword ptr [0x00568790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568790u);
	// 0x2717B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2717C0: movss [0x00568758], xmm0
	X86_MEM_WRITE_u32(base, 0x568758u, ctx.xmm[0].u32[0]);
	// 0x2717C8: ret
	return;
}

void sub_2717D0(X86Context& ctx, uint8_t* base) {
	// 0x2717D0: movss xmm0, dword ptr [0x00568710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568710u);
	// 0x2717D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2717E0: movss [0x0056876C], xmm0
	X86_MEM_WRITE_u32(base, 0x56876Cu, ctx.xmm[0].u32[0]);
	// 0x2717E8: ret
	return;
}

void sub_2717F0(X86Context& ctx, uint8_t* base) {
	// 0x2717F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2717F8: movss [0x00568708], xmm0
	X86_MEM_WRITE_u32(base, 0x568708u, ctx.xmm[0].u32[0]);
	// 0x271800: ret
	return;
}

void sub_271810(X86Context& ctx, uint8_t* base) {
	// 0x271810: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x271818: movss [0x0056873C], xmm0
	X86_MEM_WRITE_u32(base, 0x56873Cu, ctx.xmm[0].u32[0]);
	// 0x271820: ret
	return;
}

void sub_271830(X86Context& ctx, uint8_t* base) {
	// 0x271830: movss xmm0, dword ptr [0x00568738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568738u);
	// 0x271838: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x271840: movss [0x00568748], xmm0
	X86_MEM_WRITE_u32(base, 0x568748u, ctx.xmm[0].u32[0]);
	// 0x271848: ret
	return;
}

void sub_271850(X86Context& ctx, uint8_t* base) {
	// 0x271850: movss xmm0, dword ptr [0x00568790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568790u);
	// 0x271858: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x271860: movss [0x00568794], xmm0
	X86_MEM_WRITE_u32(base, 0x568794u, ctx.xmm[0].u32[0]);
	// 0x271868: ret
	return;
}

void sub_271870(X86Context& ctx, uint8_t* base) {
	// 0x271870: movss xmm0, dword ptr [0x00568748]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568748u);
	// 0x271878: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271880: movss [0x00568780], xmm0
	X86_MEM_WRITE_u32(base, 0x568780u, ctx.xmm[0].u32[0]);
	// 0x271888: ret
	return;
}

void sub_271890(X86Context& ctx, uint8_t* base) {
	// 0x271890: movss xmm0, dword ptr [0x00568794]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568794u);
	// 0x271898: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2718A0: movss [0x005687A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5687A4u, ctx.xmm[0].u32[0]);
	// 0x2718A8: ret
	return;
}

void sub_2718B0(X86Context& ctx, uint8_t* base) {
	// 0x2718B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2718B8: movss [0x00568714], xmm0
	X86_MEM_WRITE_u32(base, 0x568714u, ctx.xmm[0].u32[0]);
	// 0x2718C0: ret
	return;
}

void sub_2718D0(X86Context& ctx, uint8_t* base) {
	// 0x2718D0: movss xmm0, dword ptr [0x00568738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568738u);
	// 0x2718D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2718E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2718E8: movss [0x0056878C], xmm0
	X86_MEM_WRITE_u32(base, 0x56878Cu, ctx.xmm[0].u32[0]);
	// 0x2718F0: ret
	return;
}

void sub_271900(X86Context& ctx, uint8_t* base) {
	// 0x271900: movss xmm0, dword ptr [0x00568790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568790u);
	// 0x271908: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271910: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x271918: movss [0x0056872C], xmm0
	X86_MEM_WRITE_u32(base, 0x56872Cu, ctx.xmm[0].u32[0]);
	// 0x271920: ret
	return;
}

void sub_271930(X86Context& ctx, uint8_t* base) {
	// 0x271930: movss xmm0, dword ptr [0x00568738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568738u);
	// 0x271938: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271940: movss [0x00568730], xmm0
	X86_MEM_WRITE_u32(base, 0x568730u, ctx.xmm[0].u32[0]);
	// 0x271948: ret
	return;
}

void sub_271950(X86Context& ctx, uint8_t* base) {
	// 0x271950: movss xmm0, dword ptr [0x00568790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568790u);
	// 0x271958: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271960: movss [0x00568798], xmm0
	X86_MEM_WRITE_u32(base, 0x568798u, ctx.xmm[0].u32[0]);
	// 0x271968: ret
	return;
}

void sub_271970(X86Context& ctx, uint8_t* base) {
	// 0x271970: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x271978: movss [0x00568718], xmm0
	X86_MEM_WRITE_u32(base, 0x568718u, ctx.xmm[0].u32[0]);
	// 0x271980: ret
	return;
}

void sub_271990(X86Context& ctx, uint8_t* base) {
	// 0x271990: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x271998: movss [0x00568744], xmm0
	X86_MEM_WRITE_u32(base, 0x568744u, ctx.xmm[0].u32[0]);
	// 0x2719A0: ret
	return;
}

void sub_2719B0(X86Context& ctx, uint8_t* base) {
	// 0x2719B0: movss xmm0, dword ptr [0x00568718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568718u);
	// 0x2719B8: movss [0x005687AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5687ACu, ctx.xmm[0].u32[0]);
	// 0x2719C0: ret
	return;
}

void sub_2719D0(X86Context& ctx, uint8_t* base) {
	// 0x2719D0: movss xmm0, dword ptr [0x00568790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568790u);
	// 0x2719D8: subss xmm0, [0x00568718]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568718u);
	// 0x2719E0: movss [0x00568770], xmm0
	X86_MEM_WRITE_u32(base, 0x568770u, ctx.xmm[0].u32[0]);
	// 0x2719E8: ret
	return;
}

void sub_2719F0(X86Context& ctx, uint8_t* base) {
	// 0x2719F0: movss xmm0, dword ptr [0x00568770]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568770u);
	// 0x2719F8: subss xmm0, [0x00568744]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568744u);
	// 0x271A00: movss [0x00568768], xmm0
	X86_MEM_WRITE_u32(base, 0x568768u, ctx.xmm[0].u32[0]);
	// 0x271A08: ret
	return;
}

void sub_271A10(X86Context& ctx, uint8_t* base) {
	// 0x271A10: movss xmm0, dword ptr [0x00568798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568798u);
	// 0x271A18: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x271A20: movss [0x00568754], xmm0
	X86_MEM_WRITE_u32(base, 0x568754u, ctx.xmm[0].u32[0]);
	// 0x271A28: ret
	return;
}

void sub_271A30(X86Context& ctx, uint8_t* base) {
	// 0x271A30: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x271A38: movss [0x00568740], xmm0
	X86_MEM_WRITE_u32(base, 0x568740u, ctx.xmm[0].u32[0]);
	// 0x271A40: ret
	return;
}

void sub_271A50(X86Context& ctx, uint8_t* base) {
	// 0x271A50: movss xmm0, dword ptr [0x00568754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568754u);
	// 0x271A58: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x271A60: movss [0x00568788], xmm0
	X86_MEM_WRITE_u32(base, 0x568788u, ctx.xmm[0].u32[0]);
	// 0x271A68: ret
	return;
}

void sub_271A70(X86Context& ctx, uint8_t* base) {
	// 0x271A70: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x271A78: movss [0x0056875C], xmm0
	X86_MEM_WRITE_u32(base, 0x56875Cu, ctx.xmm[0].u32[0]);
	// 0x271A80: ret
	return;
}

void sub_271A90(X86Context& ctx, uint8_t* base) {
	// 0x271A90: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x271A98: movss [0x00568734], xmm0
	X86_MEM_WRITE_u32(base, 0x568734u, ctx.xmm[0].u32[0]);
	// 0x271AA0: ret
	return;
}

void sub_271AB0(X86Context& ctx, uint8_t* base) {
	// 0x271AB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x271AB8: movss [0x00568814], xmm0
	X86_MEM_WRITE_u32(base, 0x568814u, ctx.xmm[0].u32[0]);
	// 0x271AC0: ret
	return;
}

void sub_271AD0(X86Context& ctx, uint8_t* base) {
	// 0x271AD0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x271AD8: movss [0x00568830], xmm0
	X86_MEM_WRITE_u32(base, 0x568830u, ctx.xmm[0].u32[0]);
	// 0x271AE0: ret
	return;
}

void sub_271AF0(X86Context& ctx, uint8_t* base) {
	// 0x271AF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x271AF8: movss [0x00568804], xmm0
	X86_MEM_WRITE_u32(base, 0x568804u, ctx.xmm[0].u32[0]);
	// 0x271B00: ret
	return;
}

void sub_271B10(X86Context& ctx, uint8_t* base) {
	// 0x271B10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x271B18: movss [0x005687B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5687B8u, ctx.xmm[0].u32[0]);
	// 0x271B20: ret
	return;
}

void sub_271B30(X86Context& ctx, uint8_t* base) {
	// 0x271B30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x271B38: movss [0x00568818], xmm0
	X86_MEM_WRITE_u32(base, 0x568818u, ctx.xmm[0].u32[0]);
	// 0x271B40: ret
	return;
}

void sub_271B50(X86Context& ctx, uint8_t* base) {
	// 0x271B50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x271B58: movss [0x005687D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5687D4u, ctx.xmm[0].u32[0]);
	// 0x271B60: ret
	return;
}

void sub_271B70(X86Context& ctx, uint8_t* base) {
	// 0x271B70: movss xmm0, dword ptr [0x00568818]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568818u);
	// 0x271B78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x271B80: movss [0x00568850], xmm0
	X86_MEM_WRITE_u32(base, 0x568850u, ctx.xmm[0].u32[0]);
	// 0x271B88: ret
	return;
}

void sub_271B90(X86Context& ctx, uint8_t* base) {
	// 0x271B90: movss xmm0, dword ptr [0x005687D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687D4u);
	// 0x271B98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x271BA0: movss [0x00568838], xmm0
	X86_MEM_WRITE_u32(base, 0x568838u, ctx.xmm[0].u32[0]);
	// 0x271BA8: ret
	return;
}

void sub_271BB0(X86Context& ctx, uint8_t* base) {
	// 0x271BB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x271BB8: movss [0x00568868], xmm0
	X86_MEM_WRITE_u32(base, 0x568868u, ctx.xmm[0].u32[0]);
	// 0x271BC0: ret
	return;
}

void sub_271BD0(X86Context& ctx, uint8_t* base) {
	// 0x271BD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x271BD8: movss [0x00568854], xmm0
	X86_MEM_WRITE_u32(base, 0x568854u, ctx.xmm[0].u32[0]);
	// 0x271BE0: ret
	return;
}

void sub_271BF0(X86Context& ctx, uint8_t* base) {
	// 0x271BF0: movss xmm0, dword ptr [0x00568854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568854u);
	// 0x271BF8: movss [0x00568864], xmm0
	X86_MEM_WRITE_u32(base, 0x568864u, ctx.xmm[0].u32[0]);
	// 0x271C00: ret
	return;
}

void sub_271C10(X86Context& ctx, uint8_t* base) {
	// 0x271C10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x271C18: movss [0x005687C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5687C0u, ctx.xmm[0].u32[0]);
	// 0x271C20: ret
	return;
}

void sub_271C30(X86Context& ctx, uint8_t* base) {
	// 0x271C30: movss xmm0, dword ptr [0x005687D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687D4u);
	// 0x271C38: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x271C40: movss [0x0056885C], xmm0
	X86_MEM_WRITE_u32(base, 0x56885Cu, ctx.xmm[0].u32[0]);
	// 0x271C48: ret
	return;
}

void sub_271C50(X86Context& ctx, uint8_t* base) {
	// 0x271C50: movss xmm0, dword ptr [0x005687D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687D4u);
	// 0x271C58: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x271C60: movss [0x00568800], xmm0
	X86_MEM_WRITE_u32(base, 0x568800u, ctx.xmm[0].u32[0]);
	// 0x271C68: ret
	return;
}

void sub_271C70(X86Context& ctx, uint8_t* base) {
	// 0x271C70: movss xmm0, dword ptr [0x005687D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687D4u);
	// 0x271C78: subss xmm0, [0x00568800]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568800u);
	// 0x271C80: movss [0x005687DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5687DCu, ctx.xmm[0].u32[0]);
	// 0x271C88: ret
	return;
}

void sub_271C90(X86Context& ctx, uint8_t* base) {
	// 0x271C90: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x271C98: movss [0x0056882C], xmm0
	X86_MEM_WRITE_u32(base, 0x56882Cu, ctx.xmm[0].u32[0]);
	// 0x271CA0: ret
	return;
}

void sub_271CB0(X86Context& ctx, uint8_t* base) {
	// 0x271CB0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x271CB8: movss [0x005687D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5687D8u, ctx.xmm[0].u32[0]);
	// 0x271CC0: ret
	return;
}

void sub_271CD0(X86Context& ctx, uint8_t* base) {
	// 0x271CD0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x271CD8: movss [0x005687EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5687ECu, ctx.xmm[0].u32[0]);
	// 0x271CE0: ret
	return;
}

void sub_271CF0(X86Context& ctx, uint8_t* base) {
	// 0x271CF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x271CF8: movss [0x00568844], xmm0
	X86_MEM_WRITE_u32(base, 0x568844u, ctx.xmm[0].u32[0]);
	// 0x271D00: ret
	return;
}

void sub_271D10(X86Context& ctx, uint8_t* base) {
	// 0x271D10: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x271D18: movss [0x00568828], xmm0
	X86_MEM_WRITE_u32(base, 0x568828u, ctx.xmm[0].u32[0]);
	// 0x271D20: ret
	return;
}

void sub_271D30(X86Context& ctx, uint8_t* base) {
	// 0x271D30: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x271D38: movss [0x005687D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5687D0u, ctx.xmm[0].u32[0]);
	// 0x271D40: ret
	return;
}

void sub_271D50(X86Context& ctx, uint8_t* base) {
	// 0x271D50: movss xmm0, dword ptr [0x005687EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687ECu);
	// 0x271D58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x271D60: movss [0x005687C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5687C4u, ctx.xmm[0].u32[0]);
	// 0x271D68: ret
	return;
}

void sub_271D70(X86Context& ctx, uint8_t* base) {
	// 0x271D70: movss xmm0, dword ptr [0x00568844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568844u);
	// 0x271D78: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x271D80: movss [0x0056880C], xmm0
	X86_MEM_WRITE_u32(base, 0x56880Cu, ctx.xmm[0].u32[0]);
	// 0x271D88: ret
	return;
}

void sub_271D90(X86Context& ctx, uint8_t* base) {
	// 0x271D90: movss xmm0, dword ptr [0x005687C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687C4u);
	// 0x271D98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x271DA0: movss [0x00568820], xmm0
	X86_MEM_WRITE_u32(base, 0x568820u, ctx.xmm[0].u32[0]);
	// 0x271DA8: ret
	return;
}

void sub_271DB0(X86Context& ctx, uint8_t* base) {
	// 0x271DB0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x271DB8: movss [0x005687BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5687BCu, ctx.xmm[0].u32[0]);
	// 0x271DC0: ret
	return;
}

void sub_271DD0(X86Context& ctx, uint8_t* base) {
	// 0x271DD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x271DD8: movss [0x005687F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5687F0u, ctx.xmm[0].u32[0]);
	// 0x271DE0: ret
	return;
}

void sub_271DF0(X86Context& ctx, uint8_t* base) {
	// 0x271DF0: movss xmm0, dword ptr [0x005687EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687ECu);
	// 0x271DF8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x271E00: movss [0x005687FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5687FCu, ctx.xmm[0].u32[0]);
	// 0x271E08: ret
	return;
}

void sub_271E10(X86Context& ctx, uint8_t* base) {
	// 0x271E10: movss xmm0, dword ptr [0x00568844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568844u);
	// 0x271E18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x271E20: movss [0x00568848], xmm0
	X86_MEM_WRITE_u32(base, 0x568848u, ctx.xmm[0].u32[0]);
	// 0x271E28: ret
	return;
}

void sub_271E30(X86Context& ctx, uint8_t* base) {
	// 0x271E30: movss xmm0, dword ptr [0x005687FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687FCu);
	// 0x271E38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271E40: movss [0x00568834], xmm0
	X86_MEM_WRITE_u32(base, 0x568834u, ctx.xmm[0].u32[0]);
	// 0x271E48: ret
	return;
}

void sub_271E50(X86Context& ctx, uint8_t* base) {
	// 0x271E50: movss xmm0, dword ptr [0x00568848]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568848u);
	// 0x271E58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271E60: movss [0x00568858], xmm0
	X86_MEM_WRITE_u32(base, 0x568858u, ctx.xmm[0].u32[0]);
	// 0x271E68: ret
	return;
}

void sub_271E70(X86Context& ctx, uint8_t* base) {
	// 0x271E70: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x271E78: movss [0x005687C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5687C8u, ctx.xmm[0].u32[0]);
	// 0x271E80: ret
	return;
}

void sub_271E90(X86Context& ctx, uint8_t* base) {
	// 0x271E90: movss xmm0, dword ptr [0x005687EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687ECu);
	// 0x271E98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271EA0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x271EA8: movss [0x00568840], xmm0
	X86_MEM_WRITE_u32(base, 0x568840u, ctx.xmm[0].u32[0]);
	// 0x271EB0: ret
	return;
}

void sub_271EC0(X86Context& ctx, uint8_t* base) {
	// 0x271EC0: movss xmm0, dword ptr [0x00568844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568844u);
	// 0x271EC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271ED0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x271ED8: movss [0x005687E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5687E0u, ctx.xmm[0].u32[0]);
	// 0x271EE0: ret
	return;
}

void sub_271EF0(X86Context& ctx, uint8_t* base) {
	// 0x271EF0: movss xmm0, dword ptr [0x005687EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687ECu);
	// 0x271EF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271F00: movss [0x005687E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5687E4u, ctx.xmm[0].u32[0]);
	// 0x271F08: ret
	return;
}

void sub_271F10(X86Context& ctx, uint8_t* base) {
	// 0x271F10: movss xmm0, dword ptr [0x00568844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568844u);
	// 0x271F18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x271F20: movss [0x0056884C], xmm0
	X86_MEM_WRITE_u32(base, 0x56884Cu, ctx.xmm[0].u32[0]);
	// 0x271F28: ret
	return;
}

void sub_271F30(X86Context& ctx, uint8_t* base) {
	// 0x271F30: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x271F38: movss [0x005687CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5687CCu, ctx.xmm[0].u32[0]);
	// 0x271F40: ret
	return;
}

void sub_271F50(X86Context& ctx, uint8_t* base) {
	// 0x271F50: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x271F58: movss [0x005687F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5687F8u, ctx.xmm[0].u32[0]);
	// 0x271F60: ret
	return;
}

void sub_271F70(X86Context& ctx, uint8_t* base) {
	// 0x271F70: movss xmm0, dword ptr [0x005687CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5687CCu);
	// 0x271F78: movss [0x00568860], xmm0
	X86_MEM_WRITE_u32(base, 0x568860u, ctx.xmm[0].u32[0]);
	// 0x271F80: ret
	return;
}

void sub_271F90(X86Context& ctx, uint8_t* base) {
	// 0x271F90: movss xmm0, dword ptr [0x00568844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568844u);
	// 0x271F98: subss xmm0, [0x005687CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5687CCu);
	// 0x271FA0: movss [0x00568824], xmm0
	X86_MEM_WRITE_u32(base, 0x568824u, ctx.xmm[0].u32[0]);
	// 0x271FA8: ret
	return;
}

void sub_271FB0(X86Context& ctx, uint8_t* base) {
	// 0x271FB0: movss xmm0, dword ptr [0x00568824]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568824u);
	// 0x271FB8: subss xmm0, [0x005687F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5687F8u);
	// 0x271FC0: movss [0x0056881C], xmm0
	X86_MEM_WRITE_u32(base, 0x56881Cu, ctx.xmm[0].u32[0]);
	// 0x271FC8: ret
	return;
}

void sub_271FD0(X86Context& ctx, uint8_t* base) {
	// 0x271FD0: movss xmm0, dword ptr [0x0056884C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56884Cu);
	// 0x271FD8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x271FE0: movss [0x00568808], xmm0
	X86_MEM_WRITE_u32(base, 0x568808u, ctx.xmm[0].u32[0]);
	// 0x271FE8: ret
	return;
}

void sub_271FF0(X86Context& ctx, uint8_t* base) {
	// 0x271FF0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x271FF8: movss [0x005687F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5687F4u, ctx.xmm[0].u32[0]);
	// 0x272000: ret
	return;
}

void sub_272010(X86Context& ctx, uint8_t* base) {
	// 0x272010: movss xmm0, dword ptr [0x00568808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568808u);
	// 0x272018: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x272020: movss [0x0056883C], xmm0
	X86_MEM_WRITE_u32(base, 0x56883Cu, ctx.xmm[0].u32[0]);
	// 0x272028: ret
	return;
}

void sub_272030(X86Context& ctx, uint8_t* base) {
	// 0x272030: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x272038: movss [0x00568810], xmm0
	X86_MEM_WRITE_u32(base, 0x568810u, ctx.xmm[0].u32[0]);
	// 0x272040: ret
	return;
}

void sub_272050(X86Context& ctx, uint8_t* base) {
	// 0x272050: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x272058: movss [0x005687E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5687E8u, ctx.xmm[0].u32[0]);
	// 0x272060: ret
	return;
}

void sub_272070(X86Context& ctx, uint8_t* base) {
	// 0x272070: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x272078: movss [0x005688C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5688C8u, ctx.xmm[0].u32[0]);
	// 0x272080: ret
	return;
}

void sub_272090(X86Context& ctx, uint8_t* base) {
	// 0x272090: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x272098: movss [0x005688E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5688E4u, ctx.xmm[0].u32[0]);
	// 0x2720A0: ret
	return;
}

void sub_2720B0(X86Context& ctx, uint8_t* base) {
	// 0x2720B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2720B8: movss [0x005688B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5688B8u, ctx.xmm[0].u32[0]);
	// 0x2720C0: ret
	return;
}

void sub_2720D0(X86Context& ctx, uint8_t* base) {
	// 0x2720D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2720D8: movss [0x0056886C], xmm0
	X86_MEM_WRITE_u32(base, 0x56886Cu, ctx.xmm[0].u32[0]);
	// 0x2720E0: ret
	return;
}

void sub_2720F0(X86Context& ctx, uint8_t* base) {
	// 0x2720F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2720F8: movss [0x005688CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5688CCu, ctx.xmm[0].u32[0]);
	// 0x272100: ret
	return;
}

void sub_272110(X86Context& ctx, uint8_t* base) {
	// 0x272110: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x272118: movss [0x00568888], xmm0
	X86_MEM_WRITE_u32(base, 0x568888u, ctx.xmm[0].u32[0]);
	// 0x272120: ret
	return;
}

void sub_272130(X86Context& ctx, uint8_t* base) {
	// 0x272130: movss xmm0, dword ptr [0x005688CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688CCu);
	// 0x272138: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272140: movss [0x00568904], xmm0
	X86_MEM_WRITE_u32(base, 0x568904u, ctx.xmm[0].u32[0]);
	// 0x272148: ret
	return;
}

void sub_272150(X86Context& ctx, uint8_t* base) {
	// 0x272150: movss xmm0, dword ptr [0x00568888]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568888u);
	// 0x272158: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x272160: movss [0x005688EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5688ECu, ctx.xmm[0].u32[0]);
	// 0x272168: ret
	return;
}

void sub_272170(X86Context& ctx, uint8_t* base) {
	// 0x272170: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x272178: movss [0x0056891C], xmm0
	X86_MEM_WRITE_u32(base, 0x56891Cu, ctx.xmm[0].u32[0]);
	// 0x272180: ret
	return;
}

void sub_272190(X86Context& ctx, uint8_t* base) {
	// 0x272190: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x272198: movss [0x00568908], xmm0
	X86_MEM_WRITE_u32(base, 0x568908u, ctx.xmm[0].u32[0]);
	// 0x2721A0: ret
	return;
}

void sub_2721B0(X86Context& ctx, uint8_t* base) {
	// 0x2721B0: movss xmm0, dword ptr [0x00568908]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568908u);
	// 0x2721B8: movss [0x00568918], xmm0
	X86_MEM_WRITE_u32(base, 0x568918u, ctx.xmm[0].u32[0]);
	// 0x2721C0: ret
	return;
}

void sub_2721D0(X86Context& ctx, uint8_t* base) {
	// 0x2721D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2721D8: movss [0x00568874], xmm0
	X86_MEM_WRITE_u32(base, 0x568874u, ctx.xmm[0].u32[0]);
	// 0x2721E0: ret
	return;
}

void sub_2721F0(X86Context& ctx, uint8_t* base) {
	// 0x2721F0: movss xmm0, dword ptr [0x00568888]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568888u);
	// 0x2721F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x272200: movss [0x00568910], xmm0
	X86_MEM_WRITE_u32(base, 0x568910u, ctx.xmm[0].u32[0]);
	// 0x272208: ret
	return;
}

void sub_272210(X86Context& ctx, uint8_t* base) {
	// 0x272210: movss xmm0, dword ptr [0x00568888]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568888u);
	// 0x272218: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x272220: movss [0x005688B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5688B4u, ctx.xmm[0].u32[0]);
	// 0x272228: ret
	return;
}

void sub_272230(X86Context& ctx, uint8_t* base) {
	// 0x272230: movss xmm0, dword ptr [0x00568888]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568888u);
	// 0x272238: subss xmm0, [0x005688B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5688B4u);
	// 0x272240: movss [0x00568890], xmm0
	X86_MEM_WRITE_u32(base, 0x568890u, ctx.xmm[0].u32[0]);
	// 0x272248: ret
	return;
}

void sub_272250(X86Context& ctx, uint8_t* base) {
	// 0x272250: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x272258: movss [0x005688E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5688E0u, ctx.xmm[0].u32[0]);
	// 0x272260: ret
	return;
}

void sub_272270(X86Context& ctx, uint8_t* base) {
	// 0x272270: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x272278: movss [0x0056888C], xmm0
	X86_MEM_WRITE_u32(base, 0x56888Cu, ctx.xmm[0].u32[0]);
	// 0x272280: ret
	return;
}

void sub_272290(X86Context& ctx, uint8_t* base) {
	// 0x272290: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x272298: movss [0x005688A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5688A0u, ctx.xmm[0].u32[0]);
	// 0x2722A0: ret
	return;
}

void sub_2722B0(X86Context& ctx, uint8_t* base) {
	// 0x2722B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2722B8: movss [0x005688F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5688F8u, ctx.xmm[0].u32[0]);
	// 0x2722C0: ret
	return;
}

void sub_2722D0(X86Context& ctx, uint8_t* base) {
	// 0x2722D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2722D8: movss [0x005688DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5688DCu, ctx.xmm[0].u32[0]);
	// 0x2722E0: ret
	return;
}

void sub_2722F0(X86Context& ctx, uint8_t* base) {
	// 0x2722F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2722F8: movss [0x00568884], xmm0
	X86_MEM_WRITE_u32(base, 0x568884u, ctx.xmm[0].u32[0]);
	// 0x272300: ret
	return;
}

void sub_272310(X86Context& ctx, uint8_t* base) {
	// 0x272310: movss xmm0, dword ptr [0x005688A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688A0u);
	// 0x272318: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272320: movss [0x00568878], xmm0
	X86_MEM_WRITE_u32(base, 0x568878u, ctx.xmm[0].u32[0]);
	// 0x272328: ret
	return;
}

void sub_272330(X86Context& ctx, uint8_t* base) {
	// 0x272330: movss xmm0, dword ptr [0x005688F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688F8u);
	// 0x272338: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x272340: movss [0x005688C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5688C0u, ctx.xmm[0].u32[0]);
	// 0x272348: ret
	return;
}

void sub_272350(X86Context& ctx, uint8_t* base) {
	// 0x272350: movss xmm0, dword ptr [0x00568878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568878u);
	// 0x272358: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272360: movss [0x005688D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5688D4u, ctx.xmm[0].u32[0]);
	// 0x272368: ret
	return;
}

void sub_272370(X86Context& ctx, uint8_t* base) {
	// 0x272370: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x272378: movss [0x00568870], xmm0
	X86_MEM_WRITE_u32(base, 0x568870u, ctx.xmm[0].u32[0]);
	// 0x272380: ret
	return;
}

void sub_272390(X86Context& ctx, uint8_t* base) {
	// 0x272390: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x272398: movss [0x005688A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5688A4u, ctx.xmm[0].u32[0]);
	// 0x2723A0: ret
	return;
}

void sub_2723B0(X86Context& ctx, uint8_t* base) {
	// 0x2723B0: movss xmm0, dword ptr [0x005688A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688A0u);
	// 0x2723B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2723C0: movss [0x005688B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5688B0u, ctx.xmm[0].u32[0]);
	// 0x2723C8: ret
	return;
}

void sub_2723D0(X86Context& ctx, uint8_t* base) {
	// 0x2723D0: movss xmm0, dword ptr [0x005688F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688F8u);
	// 0x2723D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2723E0: movss [0x005688FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5688FCu, ctx.xmm[0].u32[0]);
	// 0x2723E8: ret
	return;
}

void sub_2723F0(X86Context& ctx, uint8_t* base) {
	// 0x2723F0: movss xmm0, dword ptr [0x005688B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688B0u);
	// 0x2723F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272400: movss [0x005688E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5688E8u, ctx.xmm[0].u32[0]);
	// 0x272408: ret
	return;
}

void sub_272410(X86Context& ctx, uint8_t* base) {
	// 0x272410: movss xmm0, dword ptr [0x005688FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688FCu);
	// 0x272418: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272420: movss [0x0056890C], xmm0
	X86_MEM_WRITE_u32(base, 0x56890Cu, ctx.xmm[0].u32[0]);
	// 0x272428: ret
	return;
}

void sub_272430(X86Context& ctx, uint8_t* base) {
	// 0x272430: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x272438: movss [0x0056887C], xmm0
	X86_MEM_WRITE_u32(base, 0x56887Cu, ctx.xmm[0].u32[0]);
	// 0x272440: ret
	return;
}

void sub_272450(X86Context& ctx, uint8_t* base) {
	// 0x272450: movss xmm0, dword ptr [0x005688A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688A0u);
	// 0x272458: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272460: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x272468: movss [0x005688F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5688F4u, ctx.xmm[0].u32[0]);
	// 0x272470: ret
	return;
}

void sub_272480(X86Context& ctx, uint8_t* base) {
	// 0x272480: movss xmm0, dword ptr [0x005688F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688F8u);
	// 0x272488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272490: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x272498: movss [0x00568894], xmm0
	X86_MEM_WRITE_u32(base, 0x568894u, ctx.xmm[0].u32[0]);
	// 0x2724A0: ret
	return;
}

void sub_2724B0(X86Context& ctx, uint8_t* base) {
	// 0x2724B0: movss xmm0, dword ptr [0x005688A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688A0u);
	// 0x2724B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2724C0: movss [0x00568898], xmm0
	X86_MEM_WRITE_u32(base, 0x568898u, ctx.xmm[0].u32[0]);
	// 0x2724C8: ret
	return;
}

void sub_2724D0(X86Context& ctx, uint8_t* base) {
	// 0x2724D0: movss xmm0, dword ptr [0x005688F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688F8u);
	// 0x2724D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2724E0: movss [0x00568900], xmm0
	X86_MEM_WRITE_u32(base, 0x568900u, ctx.xmm[0].u32[0]);
	// 0x2724E8: ret
	return;
}

void sub_2724F0(X86Context& ctx, uint8_t* base) {
	// 0x2724F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2724F8: movss [0x00568880], xmm0
	X86_MEM_WRITE_u32(base, 0x568880u, ctx.xmm[0].u32[0]);
	// 0x272500: ret
	return;
}

void sub_272510(X86Context& ctx, uint8_t* base) {
	// 0x272510: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x272518: movss [0x005688AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5688ACu, ctx.xmm[0].u32[0]);
	// 0x272520: ret
	return;
}

void sub_272530(X86Context& ctx, uint8_t* base) {
	// 0x272530: movss xmm0, dword ptr [0x00568880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568880u);
	// 0x272538: movss [0x00568914], xmm0
	X86_MEM_WRITE_u32(base, 0x568914u, ctx.xmm[0].u32[0]);
	// 0x272540: ret
	return;
}

void sub_272550(X86Context& ctx, uint8_t* base) {
	// 0x272550: movss xmm0, dword ptr [0x005688F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688F8u);
	// 0x272558: subss xmm0, [0x00568880]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568880u);
	// 0x272560: movss [0x005688D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5688D8u, ctx.xmm[0].u32[0]);
	// 0x272568: ret
	return;
}

void sub_272570(X86Context& ctx, uint8_t* base) {
	// 0x272570: movss xmm0, dword ptr [0x005688D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688D8u);
	// 0x272578: subss xmm0, [0x005688AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5688ACu);
	// 0x272580: movss [0x005688D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5688D0u, ctx.xmm[0].u32[0]);
	// 0x272588: ret
	return;
}

void sub_272590(X86Context& ctx, uint8_t* base) {
	// 0x272590: movss xmm0, dword ptr [0x00568900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568900u);
	// 0x272598: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2725A0: movss [0x005688BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5688BCu, ctx.xmm[0].u32[0]);
	// 0x2725A8: ret
	return;
}

void sub_2725B0(X86Context& ctx, uint8_t* base) {
	// 0x2725B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2725B8: movss [0x005688A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5688A8u, ctx.xmm[0].u32[0]);
	// 0x2725C0: ret
	return;
}

void sub_2725D0(X86Context& ctx, uint8_t* base) {
	// 0x2725D0: movss xmm0, dword ptr [0x005688BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5688BCu);
	// 0x2725D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2725E0: movss [0x005688F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5688F0u, ctx.xmm[0].u32[0]);
	// 0x2725E8: ret
	return;
}

void sub_2725F0(X86Context& ctx, uint8_t* base) {
	// 0x2725F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2725F8: movss [0x005688C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5688C4u, ctx.xmm[0].u32[0]);
	// 0x272600: ret
	return;
}

void sub_272610(X86Context& ctx, uint8_t* base) {
	// 0x272610: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x272618: movss [0x0056889C], xmm0
	X86_MEM_WRITE_u32(base, 0x56889Cu, ctx.xmm[0].u32[0]);
	// 0x272620: ret
	return;
}

void sub_272630(X86Context& ctx, uint8_t* base) {
	// 0x272630: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x272638: movss [0x0056897C], xmm0
	X86_MEM_WRITE_u32(base, 0x56897Cu, ctx.xmm[0].u32[0]);
	// 0x272640: ret
	return;
}

void sub_272650(X86Context& ctx, uint8_t* base) {
	// 0x272650: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x272658: movss [0x00568998], xmm0
	X86_MEM_WRITE_u32(base, 0x568998u, ctx.xmm[0].u32[0]);
	// 0x272660: ret
	return;
}

void sub_272670(X86Context& ctx, uint8_t* base) {
	// 0x272670: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x272678: movss [0x0056896C], xmm0
	X86_MEM_WRITE_u32(base, 0x56896Cu, ctx.xmm[0].u32[0]);
	// 0x272680: ret
	return;
}

void sub_272690(X86Context& ctx, uint8_t* base) {
	// 0x272690: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x272698: movss [0x00568920], xmm0
	X86_MEM_WRITE_u32(base, 0x568920u, ctx.xmm[0].u32[0]);
	// 0x2726A0: ret
	return;
}

void sub_2726B0(X86Context& ctx, uint8_t* base) {
	// 0x2726B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2726B8: movss [0x00568980], xmm0
	X86_MEM_WRITE_u32(base, 0x568980u, ctx.xmm[0].u32[0]);
	// 0x2726C0: ret
	return;
}

void sub_2726D0(X86Context& ctx, uint8_t* base) {
	// 0x2726D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2726D8: movss [0x0056893C], xmm0
	X86_MEM_WRITE_u32(base, 0x56893Cu, ctx.xmm[0].u32[0]);
	// 0x2726E0: ret
	return;
}

void sub_2726F0(X86Context& ctx, uint8_t* base) {
	// 0x2726F0: movss xmm0, dword ptr [0x00568980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568980u);
	// 0x2726F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272700: movss [0x005689B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5689B8u, ctx.xmm[0].u32[0]);
	// 0x272708: ret
	return;
}

void sub_272710(X86Context& ctx, uint8_t* base) {
	// 0x272710: movss xmm0, dword ptr [0x0056893C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56893Cu);
	// 0x272718: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x272720: movss [0x005689A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5689A0u, ctx.xmm[0].u32[0]);
	// 0x272728: ret
	return;
}

void sub_272730(X86Context& ctx, uint8_t* base) {
	// 0x272730: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x272738: movss [0x005689D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5689D0u, ctx.xmm[0].u32[0]);
	// 0x272740: ret
	return;
}

void sub_272750(X86Context& ctx, uint8_t* base) {
	// 0x272750: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x272758: movss [0x005689BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5689BCu, ctx.xmm[0].u32[0]);
	// 0x272760: ret
	return;
}

void sub_272770(X86Context& ctx, uint8_t* base) {
	// 0x272770: movss xmm0, dword ptr [0x005689BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689BCu);
	// 0x272778: movss [0x005689CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5689CCu, ctx.xmm[0].u32[0]);
	// 0x272780: ret
	return;
}

void sub_272790(X86Context& ctx, uint8_t* base) {
	// 0x272790: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x272798: movss [0x00568928], xmm0
	X86_MEM_WRITE_u32(base, 0x568928u, ctx.xmm[0].u32[0]);
	// 0x2727A0: ret
	return;
}

void sub_2727B0(X86Context& ctx, uint8_t* base) {
	// 0x2727B0: movss xmm0, dword ptr [0x0056893C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56893Cu);
	// 0x2727B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2727C0: movss [0x005689C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5689C4u, ctx.xmm[0].u32[0]);
	// 0x2727C8: ret
	return;
}

void sub_2727D0(X86Context& ctx, uint8_t* base) {
	// 0x2727D0: movss xmm0, dword ptr [0x0056893C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56893Cu);
	// 0x2727D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2727E0: movss [0x00568968], xmm0
	X86_MEM_WRITE_u32(base, 0x568968u, ctx.xmm[0].u32[0]);
	// 0x2727E8: ret
	return;
}

void sub_2727F0(X86Context& ctx, uint8_t* base) {
	// 0x2727F0: movss xmm0, dword ptr [0x0056893C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56893Cu);
	// 0x2727F8: subss xmm0, [0x00568968]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568968u);
	// 0x272800: movss [0x00568944], xmm0
	X86_MEM_WRITE_u32(base, 0x568944u, ctx.xmm[0].u32[0]);
	// 0x272808: ret
	return;
}

void sub_272810(X86Context& ctx, uint8_t* base) {
	// 0x272810: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x272818: movss [0x00568994], xmm0
	X86_MEM_WRITE_u32(base, 0x568994u, ctx.xmm[0].u32[0]);
	// 0x272820: ret
	return;
}

void sub_272830(X86Context& ctx, uint8_t* base) {
	// 0x272830: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x272838: movss [0x00568940], xmm0
	X86_MEM_WRITE_u32(base, 0x568940u, ctx.xmm[0].u32[0]);
	// 0x272840: ret
	return;
}

void sub_272850(X86Context& ctx, uint8_t* base) {
	// 0x272850: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x272858: movss [0x00568954], xmm0
	X86_MEM_WRITE_u32(base, 0x568954u, ctx.xmm[0].u32[0]);
	// 0x272860: ret
	return;
}

void sub_272870(X86Context& ctx, uint8_t* base) {
	// 0x272870: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x272878: movss [0x005689AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5689ACu, ctx.xmm[0].u32[0]);
	// 0x272880: ret
	return;
}

void sub_272890(X86Context& ctx, uint8_t* base) {
	// 0x272890: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x272898: movss [0x00568990], xmm0
	X86_MEM_WRITE_u32(base, 0x568990u, ctx.xmm[0].u32[0]);
	// 0x2728A0: ret
	return;
}

void sub_2728B0(X86Context& ctx, uint8_t* base) {
	// 0x2728B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2728B8: movss [0x00568938], xmm0
	X86_MEM_WRITE_u32(base, 0x568938u, ctx.xmm[0].u32[0]);
	// 0x2728C0: ret
	return;
}

void sub_2728D0(X86Context& ctx, uint8_t* base) {
	// 0x2728D0: movss xmm0, dword ptr [0x00568954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568954u);
	// 0x2728D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2728E0: movss [0x0056892C], xmm0
	X86_MEM_WRITE_u32(base, 0x56892Cu, ctx.xmm[0].u32[0]);
	// 0x2728E8: ret
	return;
}

void sub_2728F0(X86Context& ctx, uint8_t* base) {
	// 0x2728F0: movss xmm0, dword ptr [0x005689AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689ACu);
	// 0x2728F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x272900: movss [0x00568974], xmm0
	X86_MEM_WRITE_u32(base, 0x568974u, ctx.xmm[0].u32[0]);
	// 0x272908: ret
	return;
}

void sub_272910(X86Context& ctx, uint8_t* base) {
	// 0x272910: movss xmm0, dword ptr [0x0056892C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56892Cu);
	// 0x272918: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272920: movss [0x00568988], xmm0
	X86_MEM_WRITE_u32(base, 0x568988u, ctx.xmm[0].u32[0]);
	// 0x272928: ret
	return;
}

void sub_272930(X86Context& ctx, uint8_t* base) {
	// 0x272930: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x272938: movss [0x00568924], xmm0
	X86_MEM_WRITE_u32(base, 0x568924u, ctx.xmm[0].u32[0]);
	// 0x272940: ret
	return;
}

void sub_272950(X86Context& ctx, uint8_t* base) {
	// 0x272950: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x272958: movss [0x00568958], xmm0
	X86_MEM_WRITE_u32(base, 0x568958u, ctx.xmm[0].u32[0]);
	// 0x272960: ret
	return;
}

void sub_272970(X86Context& ctx, uint8_t* base) {
	// 0x272970: movss xmm0, dword ptr [0x00568954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568954u);
	// 0x272978: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x272980: movss [0x00568964], xmm0
	X86_MEM_WRITE_u32(base, 0x568964u, ctx.xmm[0].u32[0]);
	// 0x272988: ret
	return;
}

void sub_272990(X86Context& ctx, uint8_t* base) {
	// 0x272990: movss xmm0, dword ptr [0x005689AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689ACu);
	// 0x272998: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2729A0: movss [0x005689B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5689B0u, ctx.xmm[0].u32[0]);
	// 0x2729A8: ret
	return;
}

void sub_2729B0(X86Context& ctx, uint8_t* base) {
	// 0x2729B0: movss xmm0, dword ptr [0x00568964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568964u);
	// 0x2729B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2729C0: movss [0x0056899C], xmm0
	X86_MEM_WRITE_u32(base, 0x56899Cu, ctx.xmm[0].u32[0]);
	// 0x2729C8: ret
	return;
}

void sub_2729D0(X86Context& ctx, uint8_t* base) {
	// 0x2729D0: movss xmm0, dword ptr [0x005689B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689B0u);
	// 0x2729D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2729E0: movss [0x005689C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5689C0u, ctx.xmm[0].u32[0]);
	// 0x2729E8: ret
	return;
}

void sub_2729F0(X86Context& ctx, uint8_t* base) {
	// 0x2729F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2729F8: movss [0x00568930], xmm0
	X86_MEM_WRITE_u32(base, 0x568930u, ctx.xmm[0].u32[0]);
	// 0x272A00: ret
	return;
}

void sub_272A10(X86Context& ctx, uint8_t* base) {
	// 0x272A10: movss xmm0, dword ptr [0x00568954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568954u);
	// 0x272A18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272A20: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x272A28: movss [0x005689A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5689A8u, ctx.xmm[0].u32[0]);
	// 0x272A30: ret
	return;
}

void sub_272A40(X86Context& ctx, uint8_t* base) {
	// 0x272A40: movss xmm0, dword ptr [0x005689AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689ACu);
	// 0x272A48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272A50: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x272A58: movss [0x00568948], xmm0
	X86_MEM_WRITE_u32(base, 0x568948u, ctx.xmm[0].u32[0]);
	// 0x272A60: ret
	return;
}

void sub_272A70(X86Context& ctx, uint8_t* base) {
	// 0x272A70: movss xmm0, dword ptr [0x00568954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568954u);
	// 0x272A78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272A80: movss [0x0056894C], xmm0
	X86_MEM_WRITE_u32(base, 0x56894Cu, ctx.xmm[0].u32[0]);
	// 0x272A88: ret
	return;
}

void sub_272A90(X86Context& ctx, uint8_t* base) {
	// 0x272A90: movss xmm0, dword ptr [0x005689AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689ACu);
	// 0x272A98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272AA0: movss [0x005689B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5689B4u, ctx.xmm[0].u32[0]);
	// 0x272AA8: ret
	return;
}

void sub_272AB0(X86Context& ctx, uint8_t* base) {
	// 0x272AB0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x272AB8: movss [0x00568934], xmm0
	X86_MEM_WRITE_u32(base, 0x568934u, ctx.xmm[0].u32[0]);
	// 0x272AC0: ret
	return;
}

void sub_272AD0(X86Context& ctx, uint8_t* base) {
	// 0x272AD0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x272AD8: movss [0x00568960], xmm0
	X86_MEM_WRITE_u32(base, 0x568960u, ctx.xmm[0].u32[0]);
	// 0x272AE0: ret
	return;
}

void sub_272AF0(X86Context& ctx, uint8_t* base) {
	// 0x272AF0: movss xmm0, dword ptr [0x00568934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568934u);
	// 0x272AF8: movss [0x005689C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5689C8u, ctx.xmm[0].u32[0]);
	// 0x272B00: ret
	return;
}

void sub_272B10(X86Context& ctx, uint8_t* base) {
	// 0x272B10: movss xmm0, dword ptr [0x005689AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689ACu);
	// 0x272B18: subss xmm0, [0x00568934]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568934u);
	// 0x272B20: movss [0x0056898C], xmm0
	X86_MEM_WRITE_u32(base, 0x56898Cu, ctx.xmm[0].u32[0]);
	// 0x272B28: ret
	return;
}

void sub_272B30(X86Context& ctx, uint8_t* base) {
	// 0x272B30: movss xmm0, dword ptr [0x0056898C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56898Cu);
	// 0x272B38: subss xmm0, [0x00568960]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568960u);
	// 0x272B40: movss [0x00568984], xmm0
	X86_MEM_WRITE_u32(base, 0x568984u, ctx.xmm[0].u32[0]);
	// 0x272B48: ret
	return;
}

void sub_272B50(X86Context& ctx, uint8_t* base) {
	// 0x272B50: movss xmm0, dword ptr [0x005689B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689B4u);
	// 0x272B58: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x272B60: movss [0x00568970], xmm0
	X86_MEM_WRITE_u32(base, 0x568970u, ctx.xmm[0].u32[0]);
	// 0x272B68: ret
	return;
}

void sub_272B70(X86Context& ctx, uint8_t* base) {
	// 0x272B70: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x272B78: movss [0x0056895C], xmm0
	X86_MEM_WRITE_u32(base, 0x56895Cu, ctx.xmm[0].u32[0]);
	// 0x272B80: ret
	return;
}

void sub_272B90(X86Context& ctx, uint8_t* base) {
	// 0x272B90: movss xmm0, dword ptr [0x00568970]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568970u);
	// 0x272B98: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x272BA0: movss [0x005689A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5689A4u, ctx.xmm[0].u32[0]);
	// 0x272BA8: ret
	return;
}

void sub_272BB0(X86Context& ctx, uint8_t* base) {
	// 0x272BB0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x272BB8: movss [0x00568978], xmm0
	X86_MEM_WRITE_u32(base, 0x568978u, ctx.xmm[0].u32[0]);
	// 0x272BC0: ret
	return;
}

void sub_272BD0(X86Context& ctx, uint8_t* base) {
	// 0x272BD0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x272BD8: movss [0x00568950], xmm0
	X86_MEM_WRITE_u32(base, 0x568950u, ctx.xmm[0].u32[0]);
	// 0x272BE0: ret
	return;
}

void sub_272BF0(X86Context& ctx, uint8_t* base) {
	// 0x272BF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x272BF8: movss [0x00568A30], xmm0
	X86_MEM_WRITE_u32(base, 0x568A30u, ctx.xmm[0].u32[0]);
	// 0x272C00: ret
	return;
}

void sub_272C10(X86Context& ctx, uint8_t* base) {
	// 0x272C10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x272C18: movss [0x00568A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A4Cu, ctx.xmm[0].u32[0]);
	// 0x272C20: ret
	return;
}

void sub_272C30(X86Context& ctx, uint8_t* base) {
	// 0x272C30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x272C38: movss [0x00568A20], xmm0
	X86_MEM_WRITE_u32(base, 0x568A20u, ctx.xmm[0].u32[0]);
	// 0x272C40: ret
	return;
}

void sub_272C50(X86Context& ctx, uint8_t* base) {
	// 0x272C50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x272C58: movss [0x005689D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5689D4u, ctx.xmm[0].u32[0]);
	// 0x272C60: ret
	return;
}

void sub_272C70(X86Context& ctx, uint8_t* base) {
	// 0x272C70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x272C78: movss [0x00568A34], xmm0
	X86_MEM_WRITE_u32(base, 0x568A34u, ctx.xmm[0].u32[0]);
	// 0x272C80: ret
	return;
}

void sub_272C90(X86Context& ctx, uint8_t* base) {
	// 0x272C90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x272C98: movss [0x005689F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5689F0u, ctx.xmm[0].u32[0]);
	// 0x272CA0: ret
	return;
}

void sub_272CB0(X86Context& ctx, uint8_t* base) {
	// 0x272CB0: movss xmm0, dword ptr [0x00568A34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A34u);
	// 0x272CB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272CC0: movss [0x00568A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A6Cu, ctx.xmm[0].u32[0]);
	// 0x272CC8: ret
	return;
}

void sub_272CD0(X86Context& ctx, uint8_t* base) {
	// 0x272CD0: movss xmm0, dword ptr [0x005689F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689F0u);
	// 0x272CD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x272CE0: movss [0x00568A54], xmm0
	X86_MEM_WRITE_u32(base, 0x568A54u, ctx.xmm[0].u32[0]);
	// 0x272CE8: ret
	return;
}

void sub_272CF0(X86Context& ctx, uint8_t* base) {
	// 0x272CF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x272CF8: movss [0x00568A84], xmm0
	X86_MEM_WRITE_u32(base, 0x568A84u, ctx.xmm[0].u32[0]);
	// 0x272D00: ret
	return;
}

void sub_272D10(X86Context& ctx, uint8_t* base) {
	// 0x272D10: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x272D18: movss [0x00568A70], xmm0
	X86_MEM_WRITE_u32(base, 0x568A70u, ctx.xmm[0].u32[0]);
	// 0x272D20: ret
	return;
}

void sub_272D30(X86Context& ctx, uint8_t* base) {
	// 0x272D30: movss xmm0, dword ptr [0x00568A70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A70u);
	// 0x272D38: movss [0x00568A80], xmm0
	X86_MEM_WRITE_u32(base, 0x568A80u, ctx.xmm[0].u32[0]);
	// 0x272D40: ret
	return;
}

void sub_272D50(X86Context& ctx, uint8_t* base) {
	// 0x272D50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x272D58: movss [0x005689DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5689DCu, ctx.xmm[0].u32[0]);
	// 0x272D60: ret
	return;
}

void sub_272D70(X86Context& ctx, uint8_t* base) {
	// 0x272D70: movss xmm0, dword ptr [0x005689F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689F0u);
	// 0x272D78: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x272D80: movss [0x00568A78], xmm0
	X86_MEM_WRITE_u32(base, 0x568A78u, ctx.xmm[0].u32[0]);
	// 0x272D88: ret
	return;
}

void sub_272D90(X86Context& ctx, uint8_t* base) {
	// 0x272D90: movss xmm0, dword ptr [0x005689F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689F0u);
	// 0x272D98: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x272DA0: movss [0x00568A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A1Cu, ctx.xmm[0].u32[0]);
	// 0x272DA8: ret
	return;
}

void sub_272DB0(X86Context& ctx, uint8_t* base) {
	// 0x272DB0: movss xmm0, dword ptr [0x005689F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689F0u);
	// 0x272DB8: subss xmm0, [0x00568A1C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568A1Cu);
	// 0x272DC0: movss [0x005689F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5689F8u, ctx.xmm[0].u32[0]);
	// 0x272DC8: ret
	return;
}

void sub_272DD0(X86Context& ctx, uint8_t* base) {
	// 0x272DD0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x272DD8: movss [0x00568A48], xmm0
	X86_MEM_WRITE_u32(base, 0x568A48u, ctx.xmm[0].u32[0]);
	// 0x272DE0: ret
	return;
}

void sub_272DF0(X86Context& ctx, uint8_t* base) {
	// 0x272DF0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x272DF8: movss [0x005689F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5689F4u, ctx.xmm[0].u32[0]);
	// 0x272E00: ret
	return;
}

void sub_272E10(X86Context& ctx, uint8_t* base) {
	// 0x272E10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x272E18: movss [0x00568A08], xmm0
	X86_MEM_WRITE_u32(base, 0x568A08u, ctx.xmm[0].u32[0]);
	// 0x272E20: ret
	return;
}

void sub_272E30(X86Context& ctx, uint8_t* base) {
	// 0x272E30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x272E38: movss [0x00568A60], xmm0
	X86_MEM_WRITE_u32(base, 0x568A60u, ctx.xmm[0].u32[0]);
	// 0x272E40: ret
	return;
}

void sub_272E50(X86Context& ctx, uint8_t* base) {
	// 0x272E50: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x272E58: movss [0x00568A44], xmm0
	X86_MEM_WRITE_u32(base, 0x568A44u, ctx.xmm[0].u32[0]);
	// 0x272E60: ret
	return;
}

void sub_272E70(X86Context& ctx, uint8_t* base) {
	// 0x272E70: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x272E78: movss [0x005689EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5689ECu, ctx.xmm[0].u32[0]);
	// 0x272E80: ret
	return;
}

void sub_272E90(X86Context& ctx, uint8_t* base) {
	// 0x272E90: movss xmm0, dword ptr [0x00568A08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A08u);
	// 0x272E98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272EA0: movss [0x005689E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5689E0u, ctx.xmm[0].u32[0]);
	// 0x272EA8: ret
	return;
}

void sub_272EB0(X86Context& ctx, uint8_t* base) {
	// 0x272EB0: movss xmm0, dword ptr [0x00568A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A60u);
	// 0x272EB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x272EC0: movss [0x00568A28], xmm0
	X86_MEM_WRITE_u32(base, 0x568A28u, ctx.xmm[0].u32[0]);
	// 0x272EC8: ret
	return;
}

void sub_272ED0(X86Context& ctx, uint8_t* base) {
	// 0x272ED0: movss xmm0, dword ptr [0x005689E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689E0u);
	// 0x272ED8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x272EE0: movss [0x00568A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A3Cu, ctx.xmm[0].u32[0]);
	// 0x272EE8: ret
	return;
}

void sub_272EF0(X86Context& ctx, uint8_t* base) {
	// 0x272EF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x272EF8: movss [0x005689D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5689D8u, ctx.xmm[0].u32[0]);
	// 0x272F00: ret
	return;
}

void sub_272F10(X86Context& ctx, uint8_t* base) {
	// 0x272F10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x272F18: movss [0x00568A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A0Cu, ctx.xmm[0].u32[0]);
	// 0x272F20: ret
	return;
}

void sub_272F30(X86Context& ctx, uint8_t* base) {
	// 0x272F30: movss xmm0, dword ptr [0x00568A08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A08u);
	// 0x272F38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x272F40: movss [0x00568A18], xmm0
	X86_MEM_WRITE_u32(base, 0x568A18u, ctx.xmm[0].u32[0]);
	// 0x272F48: ret
	return;
}

void sub_272F50(X86Context& ctx, uint8_t* base) {
	// 0x272F50: movss xmm0, dword ptr [0x00568A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A60u);
	// 0x272F58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x272F60: movss [0x00568A64], xmm0
	X86_MEM_WRITE_u32(base, 0x568A64u, ctx.xmm[0].u32[0]);
	// 0x272F68: ret
	return;
}

void sub_272F70(X86Context& ctx, uint8_t* base) {
	// 0x272F70: movss xmm0, dword ptr [0x00568A18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A18u);
	// 0x272F78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272F80: movss [0x00568A50], xmm0
	X86_MEM_WRITE_u32(base, 0x568A50u, ctx.xmm[0].u32[0]);
	// 0x272F88: ret
	return;
}

void sub_272F90(X86Context& ctx, uint8_t* base) {
	// 0x272F90: movss xmm0, dword ptr [0x00568A64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A64u);
	// 0x272F98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272FA0: movss [0x00568A74], xmm0
	X86_MEM_WRITE_u32(base, 0x568A74u, ctx.xmm[0].u32[0]);
	// 0x272FA8: ret
	return;
}

void sub_272FB0(X86Context& ctx, uint8_t* base) {
	// 0x272FB0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x272FB8: movss [0x005689E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5689E4u, ctx.xmm[0].u32[0]);
	// 0x272FC0: ret
	return;
}

void sub_272FD0(X86Context& ctx, uint8_t* base) {
	// 0x272FD0: movss xmm0, dword ptr [0x00568A08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A08u);
	// 0x272FD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x272FE0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x272FE8: movss [0x00568A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A5Cu, ctx.xmm[0].u32[0]);
	// 0x272FF0: ret
	return;
}

void sub_273000(X86Context& ctx, uint8_t* base) {
	// 0x273000: movss xmm0, dword ptr [0x00568A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A60u);
	// 0x273008: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x273010: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x273018: movss [0x005689FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5689FCu, ctx.xmm[0].u32[0]);
	// 0x273020: ret
	return;
}

void sub_273030(X86Context& ctx, uint8_t* base) {
	// 0x273030: movss xmm0, dword ptr [0x00568A08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A08u);
	// 0x273038: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x273040: movss [0x00568A00], xmm0
	X86_MEM_WRITE_u32(base, 0x568A00u, ctx.xmm[0].u32[0]);
	// 0x273048: ret
	return;
}

void sub_273050(X86Context& ctx, uint8_t* base) {
	// 0x273050: movss xmm0, dword ptr [0x00568A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A60u);
	// 0x273058: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x273060: movss [0x00568A68], xmm0
	X86_MEM_WRITE_u32(base, 0x568A68u, ctx.xmm[0].u32[0]);
	// 0x273068: ret
	return;
}

void sub_273070(X86Context& ctx, uint8_t* base) {
	// 0x273070: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x273078: movss [0x005689E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5689E8u, ctx.xmm[0].u32[0]);
	// 0x273080: ret
	return;
}

void sub_273090(X86Context& ctx, uint8_t* base) {
	// 0x273090: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x273098: movss [0x00568A14], xmm0
	X86_MEM_WRITE_u32(base, 0x568A14u, ctx.xmm[0].u32[0]);
	// 0x2730A0: ret
	return;
}

void sub_2730B0(X86Context& ctx, uint8_t* base) {
	// 0x2730B0: movss xmm0, dword ptr [0x005689E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5689E8u);
	// 0x2730B8: movss [0x00568A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A7Cu, ctx.xmm[0].u32[0]);
	// 0x2730C0: ret
	return;
}

void sub_2730D0(X86Context& ctx, uint8_t* base) {
	// 0x2730D0: movss xmm0, dword ptr [0x00568A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A60u);
	// 0x2730D8: subss xmm0, [0x005689E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5689E8u);
	// 0x2730E0: movss [0x00568A40], xmm0
	X86_MEM_WRITE_u32(base, 0x568A40u, ctx.xmm[0].u32[0]);
	// 0x2730E8: ret
	return;
}

void sub_2730F0(X86Context& ctx, uint8_t* base) {
	// 0x2730F0: movss xmm0, dword ptr [0x00568A40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A40u);
	// 0x2730F8: subss xmm0, [0x00568A14]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568A14u);
	// 0x273100: movss [0x00568A38], xmm0
	X86_MEM_WRITE_u32(base, 0x568A38u, ctx.xmm[0].u32[0]);
	// 0x273108: ret
	return;
}

void sub_273110(X86Context& ctx, uint8_t* base) {
	// 0x273110: movss xmm0, dword ptr [0x00568A68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A68u);
	// 0x273118: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x273120: movss [0x00568A24], xmm0
	X86_MEM_WRITE_u32(base, 0x568A24u, ctx.xmm[0].u32[0]);
	// 0x273128: ret
	return;
}

void sub_273130(X86Context& ctx, uint8_t* base) {
	// 0x273130: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x273138: movss [0x00568A10], xmm0
	X86_MEM_WRITE_u32(base, 0x568A10u, ctx.xmm[0].u32[0]);
	// 0x273140: ret
	return;
}

void sub_273150(X86Context& ctx, uint8_t* base) {
	// 0x273150: movss xmm0, dword ptr [0x00568A24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568A24u);
	// 0x273158: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x273160: movss [0x00568A58], xmm0
	X86_MEM_WRITE_u32(base, 0x568A58u, ctx.xmm[0].u32[0]);
	// 0x273168: ret
	return;
}

void sub_273170(X86Context& ctx, uint8_t* base) {
	// 0x273170: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x273178: movss [0x00568A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x568A2Cu, ctx.xmm[0].u32[0]);
	// 0x273180: ret
	return;
}

void sub_273190(X86Context& ctx, uint8_t* base) {
	// 0x273190: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x273198: movss [0x00568A04], xmm0
	X86_MEM_WRITE_u32(base, 0x568A04u, ctx.xmm[0].u32[0]);
	// 0x2731A0: ret
	return;
}

void sub_2731B0(X86Context& ctx, uint8_t* base) {
	// 0x2731B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2731B8: movss [0x00568AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x568AE4u, ctx.xmm[0].u32[0]);
	// 0x2731C0: ret
	return;
}

void sub_2731D0(X86Context& ctx, uint8_t* base) {
	// 0x2731D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2731D8: movss [0x00568B00], xmm0
	X86_MEM_WRITE_u32(base, 0x568B00u, ctx.xmm[0].u32[0]);
	// 0x2731E0: ret
	return;
}

void sub_2731F0(X86Context& ctx, uint8_t* base) {
	// 0x2731F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2731F8: movss [0x00568AD4], xmm0
	X86_MEM_WRITE_u32(base, 0x568AD4u, ctx.xmm[0].u32[0]);
	// 0x273200: ret
	return;
}

void sub_273210(X86Context& ctx, uint8_t* base) {
	// 0x273210: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x273218: movss [0x00568A88], xmm0
	X86_MEM_WRITE_u32(base, 0x568A88u, ctx.xmm[0].u32[0]);
	// 0x273220: ret
	return;
}

void sub_273230(X86Context& ctx, uint8_t* base) {
	// 0x273230: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x273238: movss [0x00568AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x568AE8u, ctx.xmm[0].u32[0]);
	// 0x273240: ret
	return;
}

void sub_273250(X86Context& ctx, uint8_t* base) {
	// 0x273250: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x273258: movss [0x00568AA4], xmm0
	X86_MEM_WRITE_u32(base, 0x568AA4u, ctx.xmm[0].u32[0]);
	// 0x273260: ret
	return;
}

void sub_273270(X86Context& ctx, uint8_t* base) {
	// 0x273270: movss xmm0, dword ptr [0x00568AE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568AE8u);
	// 0x273278: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x273280: movss [0x00568B20], xmm0
	X86_MEM_WRITE_u32(base, 0x568B20u, ctx.xmm[0].u32[0]);
	// 0x273288: ret
	return;
}

