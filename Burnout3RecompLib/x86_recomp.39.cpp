#include "x86_recomp_shared.h"

void sub_26F150(X86Context& ctx, uint8_t* base) {
	// 0x26F150: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26F158: movss [0x00568258], xmm0
	X86_MEM_WRITE_u32(base, 0x568258u, ctx.xmm[0].u32[0]);
	// 0x26F160: ret
	return;
}

void sub_26F170(X86Context& ctx, uint8_t* base) {
	// 0x26F170: movss xmm0, dword ptr [0x0056822C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56822Cu);
	// 0x26F178: movss [0x005682C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5682C0u, ctx.xmm[0].u32[0]);
	// 0x26F180: ret
	return;
}

void sub_26F190(X86Context& ctx, uint8_t* base) {
	// 0x26F190: movss xmm0, dword ptr [0x005682A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682A4u);
	// 0x26F198: subss xmm0, [0x0056822C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56822Cu);
	// 0x26F1A0: movss [0x00568284], xmm0
	X86_MEM_WRITE_u32(base, 0x568284u, ctx.xmm[0].u32[0]);
	// 0x26F1A8: ret
	return;
}

void sub_26F1B0(X86Context& ctx, uint8_t* base) {
	// 0x26F1B0: movss xmm0, dword ptr [0x00568284]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568284u);
	// 0x26F1B8: subss xmm0, [0x00568258]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568258u);
	// 0x26F1C0: movss [0x0056827C], xmm0
	X86_MEM_WRITE_u32(base, 0x56827Cu, ctx.xmm[0].u32[0]);
	// 0x26F1C8: ret
	return;
}

void sub_26F1D0(X86Context& ctx, uint8_t* base) {
	// 0x26F1D0: movss xmm0, dword ptr [0x005682AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682ACu);
	// 0x26F1D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26F1E0: movss [0x00568268], xmm0
	X86_MEM_WRITE_u32(base, 0x568268u, ctx.xmm[0].u32[0]);
	// 0x26F1E8: ret
	return;
}

void sub_26F1F0(X86Context& ctx, uint8_t* base) {
	// 0x26F1F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26F1F8: movss [0x00568254], xmm0
	X86_MEM_WRITE_u32(base, 0x568254u, ctx.xmm[0].u32[0]);
	// 0x26F200: ret
	return;
}

void sub_26F210(X86Context& ctx, uint8_t* base) {
	// 0x26F210: movss xmm0, dword ptr [0x00568268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568268u);
	// 0x26F218: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26F220: movss [0x0056829C], xmm0
	X86_MEM_WRITE_u32(base, 0x56829Cu, ctx.xmm[0].u32[0]);
	// 0x26F228: ret
	return;
}

void sub_26F230(X86Context& ctx, uint8_t* base) {
	// 0x26F230: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26F238: movss [0x00568270], xmm0
	X86_MEM_WRITE_u32(base, 0x568270u, ctx.xmm[0].u32[0]);
	// 0x26F240: ret
	return;
}

void sub_26F250(X86Context& ctx, uint8_t* base) {
	// 0x26F250: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26F258: movss [0x00568248], xmm0
	X86_MEM_WRITE_u32(base, 0x568248u, ctx.xmm[0].u32[0]);
	// 0x26F260: ret
	return;
}

void sub_26F270(X86Context& ctx, uint8_t* base) {
	// 0x26F270: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26F278: movss [0x00568328], xmm0
	X86_MEM_WRITE_u32(base, 0x568328u, ctx.xmm[0].u32[0]);
	// 0x26F280: ret
	return;
}

void sub_26F290(X86Context& ctx, uint8_t* base) {
	// 0x26F290: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26F298: movss [0x00568344], xmm0
	X86_MEM_WRITE_u32(base, 0x568344u, ctx.xmm[0].u32[0]);
	// 0x26F2A0: ret
	return;
}

void sub_26F2B0(X86Context& ctx, uint8_t* base) {
	// 0x26F2B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26F2B8: movss [0x00568318], xmm0
	X86_MEM_WRITE_u32(base, 0x568318u, ctx.xmm[0].u32[0]);
	// 0x26F2C0: ret
	return;
}

void sub_26F2D0(X86Context& ctx, uint8_t* base) {
	// 0x26F2D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26F2D8: movss [0x005682CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5682CCu, ctx.xmm[0].u32[0]);
	// 0x26F2E0: ret
	return;
}

void sub_26F2F0(X86Context& ctx, uint8_t* base) {
	// 0x26F2F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26F2F8: movss [0x0056832C], xmm0
	X86_MEM_WRITE_u32(base, 0x56832Cu, ctx.xmm[0].u32[0]);
	// 0x26F300: ret
	return;
}

void sub_26F310(X86Context& ctx, uint8_t* base) {
	// 0x26F310: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26F318: movss [0x005682E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5682E8u, ctx.xmm[0].u32[0]);
	// 0x26F320: ret
	return;
}

void sub_26F330(X86Context& ctx, uint8_t* base) {
	// 0x26F330: movss xmm0, dword ptr [0x0056832C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56832Cu);
	// 0x26F338: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26F340: movss [0x00568364], xmm0
	X86_MEM_WRITE_u32(base, 0x568364u, ctx.xmm[0].u32[0]);
	// 0x26F348: ret
	return;
}

void sub_26F350(X86Context& ctx, uint8_t* base) {
	// 0x26F350: movss xmm0, dword ptr [0x005682E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682E8u);
	// 0x26F358: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26F360: movss [0x0056834C], xmm0
	X86_MEM_WRITE_u32(base, 0x56834Cu, ctx.xmm[0].u32[0]);
	// 0x26F368: ret
	return;
}

void sub_26F370(X86Context& ctx, uint8_t* base) {
	// 0x26F370: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26F378: movss [0x0056837C], xmm0
	X86_MEM_WRITE_u32(base, 0x56837Cu, ctx.xmm[0].u32[0]);
	// 0x26F380: ret
	return;
}

void sub_26F390(X86Context& ctx, uint8_t* base) {
	// 0x26F390: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26F398: movss [0x00568368], xmm0
	X86_MEM_WRITE_u32(base, 0x568368u, ctx.xmm[0].u32[0]);
	// 0x26F3A0: ret
	return;
}

void sub_26F3B0(X86Context& ctx, uint8_t* base) {
	// 0x26F3B0: movss xmm0, dword ptr [0x00568368]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568368u);
	// 0x26F3B8: movss [0x00568378], xmm0
	X86_MEM_WRITE_u32(base, 0x568378u, ctx.xmm[0].u32[0]);
	// 0x26F3C0: ret
	return;
}

void sub_26F3D0(X86Context& ctx, uint8_t* base) {
	// 0x26F3D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26F3D8: movss [0x005682D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5682D4u, ctx.xmm[0].u32[0]);
	// 0x26F3E0: ret
	return;
}

void sub_26F3F0(X86Context& ctx, uint8_t* base) {
	// 0x26F3F0: movss xmm0, dword ptr [0x005682E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682E8u);
	// 0x26F3F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26F400: movss [0x00568370], xmm0
	X86_MEM_WRITE_u32(base, 0x568370u, ctx.xmm[0].u32[0]);
	// 0x26F408: ret
	return;
}

void sub_26F410(X86Context& ctx, uint8_t* base) {
	// 0x26F410: movss xmm0, dword ptr [0x005682E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682E8u);
	// 0x26F418: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26F420: movss [0x00568314], xmm0
	X86_MEM_WRITE_u32(base, 0x568314u, ctx.xmm[0].u32[0]);
	// 0x26F428: ret
	return;
}

void sub_26F430(X86Context& ctx, uint8_t* base) {
	// 0x26F430: movss xmm0, dword ptr [0x005682E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682E8u);
	// 0x26F438: subss xmm0, [0x00568314]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568314u);
	// 0x26F440: movss [0x005682F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5682F0u, ctx.xmm[0].u32[0]);
	// 0x26F448: ret
	return;
}

void sub_26F450(X86Context& ctx, uint8_t* base) {
	// 0x26F450: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26F458: movss [0x00568340], xmm0
	X86_MEM_WRITE_u32(base, 0x568340u, ctx.xmm[0].u32[0]);
	// 0x26F460: ret
	return;
}

void sub_26F470(X86Context& ctx, uint8_t* base) {
	// 0x26F470: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26F478: movss [0x005682EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5682ECu, ctx.xmm[0].u32[0]);
	// 0x26F480: ret
	return;
}

void sub_26F490(X86Context& ctx, uint8_t* base) {
	// 0x26F490: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26F498: movss [0x00568300], xmm0
	X86_MEM_WRITE_u32(base, 0x568300u, ctx.xmm[0].u32[0]);
	// 0x26F4A0: ret
	return;
}

void sub_26F4B0(X86Context& ctx, uint8_t* base) {
	// 0x26F4B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26F4B8: movss [0x00568358], xmm0
	X86_MEM_WRITE_u32(base, 0x568358u, ctx.xmm[0].u32[0]);
	// 0x26F4C0: ret
	return;
}

void sub_26F4D0(X86Context& ctx, uint8_t* base) {
	// 0x26F4D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26F4D8: movss [0x0056833C], xmm0
	X86_MEM_WRITE_u32(base, 0x56833Cu, ctx.xmm[0].u32[0]);
	// 0x26F4E0: ret
	return;
}

void sub_26F4F0(X86Context& ctx, uint8_t* base) {
	// 0x26F4F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26F4F8: movss [0x005682E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5682E4u, ctx.xmm[0].u32[0]);
	// 0x26F500: ret
	return;
}

void sub_26F510(X86Context& ctx, uint8_t* base) {
	// 0x26F510: movss xmm0, dword ptr [0x00568300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568300u);
	// 0x26F518: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26F520: movss [0x005682D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5682D8u, ctx.xmm[0].u32[0]);
	// 0x26F528: ret
	return;
}

void sub_26F530(X86Context& ctx, uint8_t* base) {
	// 0x26F530: movss xmm0, dword ptr [0x00568358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568358u);
	// 0x26F538: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26F540: movss [0x00568320], xmm0
	X86_MEM_WRITE_u32(base, 0x568320u, ctx.xmm[0].u32[0]);
	// 0x26F548: ret
	return;
}

void sub_26F550(X86Context& ctx, uint8_t* base) {
	// 0x26F550: movss xmm0, dword ptr [0x005682D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682D8u);
	// 0x26F558: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26F560: movss [0x00568334], xmm0
	X86_MEM_WRITE_u32(base, 0x568334u, ctx.xmm[0].u32[0]);
	// 0x26F568: ret
	return;
}

void sub_26F570(X86Context& ctx, uint8_t* base) {
	// 0x26F570: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26F578: movss [0x005682D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5682D0u, ctx.xmm[0].u32[0]);
	// 0x26F580: ret
	return;
}

void sub_26F590(X86Context& ctx, uint8_t* base) {
	// 0x26F590: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26F598: movss [0x00568304], xmm0
	X86_MEM_WRITE_u32(base, 0x568304u, ctx.xmm[0].u32[0]);
	// 0x26F5A0: ret
	return;
}

void sub_26F5B0(X86Context& ctx, uint8_t* base) {
	// 0x26F5B0: movss xmm0, dword ptr [0x00568300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568300u);
	// 0x26F5B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26F5C0: movss [0x00568310], xmm0
	X86_MEM_WRITE_u32(base, 0x568310u, ctx.xmm[0].u32[0]);
	// 0x26F5C8: ret
	return;
}

void sub_26F5D0(X86Context& ctx, uint8_t* base) {
	// 0x26F5D0: movss xmm0, dword ptr [0x00568358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568358u);
	// 0x26F5D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26F5E0: movss [0x0056835C], xmm0
	X86_MEM_WRITE_u32(base, 0x56835Cu, ctx.xmm[0].u32[0]);
	// 0x26F5E8: ret
	return;
}

void sub_26F5F0(X86Context& ctx, uint8_t* base) {
	// 0x26F5F0: movss xmm0, dword ptr [0x00568310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568310u);
	// 0x26F5F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F600: movss [0x00568348], xmm0
	X86_MEM_WRITE_u32(base, 0x568348u, ctx.xmm[0].u32[0]);
	// 0x26F608: ret
	return;
}

void sub_26F610(X86Context& ctx, uint8_t* base) {
	// 0x26F610: movss xmm0, dword ptr [0x0056835C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56835Cu);
	// 0x26F618: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F620: movss [0x0056836C], xmm0
	X86_MEM_WRITE_u32(base, 0x56836Cu, ctx.xmm[0].u32[0]);
	// 0x26F628: ret
	return;
}

void sub_26F630(X86Context& ctx, uint8_t* base) {
	// 0x26F630: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26F638: movss [0x005682DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5682DCu, ctx.xmm[0].u32[0]);
	// 0x26F640: ret
	return;
}

void sub_26F650(X86Context& ctx, uint8_t* base) {
	// 0x26F650: movss xmm0, dword ptr [0x00568300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568300u);
	// 0x26F658: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F660: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26F668: movss [0x00568354], xmm0
	X86_MEM_WRITE_u32(base, 0x568354u, ctx.xmm[0].u32[0]);
	// 0x26F670: ret
	return;
}

void sub_26F680(X86Context& ctx, uint8_t* base) {
	// 0x26F680: movss xmm0, dword ptr [0x00568358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568358u);
	// 0x26F688: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F690: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26F698: movss [0x005682F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5682F4u, ctx.xmm[0].u32[0]);
	// 0x26F6A0: ret
	return;
}

void sub_26F6B0(X86Context& ctx, uint8_t* base) {
	// 0x26F6B0: movss xmm0, dword ptr [0x00568300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568300u);
	// 0x26F6B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F6C0: movss [0x005682F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5682F8u, ctx.xmm[0].u32[0]);
	// 0x26F6C8: ret
	return;
}

void sub_26F6D0(X86Context& ctx, uint8_t* base) {
	// 0x26F6D0: movss xmm0, dword ptr [0x00568358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568358u);
	// 0x26F6D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F6E0: movss [0x00568360], xmm0
	X86_MEM_WRITE_u32(base, 0x568360u, ctx.xmm[0].u32[0]);
	// 0x26F6E8: ret
	return;
}

void sub_26F6F0(X86Context& ctx, uint8_t* base) {
	// 0x26F6F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26F6F8: movss [0x005682E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5682E0u, ctx.xmm[0].u32[0]);
	// 0x26F700: ret
	return;
}

void sub_26F710(X86Context& ctx, uint8_t* base) {
	// 0x26F710: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26F718: movss [0x0056830C], xmm0
	X86_MEM_WRITE_u32(base, 0x56830Cu, ctx.xmm[0].u32[0]);
	// 0x26F720: ret
	return;
}

void sub_26F730(X86Context& ctx, uint8_t* base) {
	// 0x26F730: movss xmm0, dword ptr [0x005682E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682E0u);
	// 0x26F738: movss [0x00568374], xmm0
	X86_MEM_WRITE_u32(base, 0x568374u, ctx.xmm[0].u32[0]);
	// 0x26F740: ret
	return;
}

void sub_26F750(X86Context& ctx, uint8_t* base) {
	// 0x26F750: movss xmm0, dword ptr [0x00568358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568358u);
	// 0x26F758: subss xmm0, [0x005682E0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5682E0u);
	// 0x26F760: movss [0x00568338], xmm0
	X86_MEM_WRITE_u32(base, 0x568338u, ctx.xmm[0].u32[0]);
	// 0x26F768: ret
	return;
}

void sub_26F770(X86Context& ctx, uint8_t* base) {
	// 0x26F770: movss xmm0, dword ptr [0x00568338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568338u);
	// 0x26F778: subss xmm0, [0x0056830C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56830Cu);
	// 0x26F780: movss [0x00568330], xmm0
	X86_MEM_WRITE_u32(base, 0x568330u, ctx.xmm[0].u32[0]);
	// 0x26F788: ret
	return;
}

void sub_26F790(X86Context& ctx, uint8_t* base) {
	// 0x26F790: movss xmm0, dword ptr [0x00568360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568360u);
	// 0x26F798: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26F7A0: movss [0x0056831C], xmm0
	X86_MEM_WRITE_u32(base, 0x56831Cu, ctx.xmm[0].u32[0]);
	// 0x26F7A8: ret
	return;
}

void sub_26F7B0(X86Context& ctx, uint8_t* base) {
	// 0x26F7B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26F7B8: movss [0x00568308], xmm0
	X86_MEM_WRITE_u32(base, 0x568308u, ctx.xmm[0].u32[0]);
	// 0x26F7C0: ret
	return;
}

void sub_26F7D0(X86Context& ctx, uint8_t* base) {
	// 0x26F7D0: movss xmm0, dword ptr [0x0056831C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56831Cu);
	// 0x26F7D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26F7E0: movss [0x00568350], xmm0
	X86_MEM_WRITE_u32(base, 0x568350u, ctx.xmm[0].u32[0]);
	// 0x26F7E8: ret
	return;
}

void sub_26F7F0(X86Context& ctx, uint8_t* base) {
	// 0x26F7F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26F7F8: movss [0x00568324], xmm0
	X86_MEM_WRITE_u32(base, 0x568324u, ctx.xmm[0].u32[0]);
	// 0x26F800: ret
	return;
}

void sub_26F810(X86Context& ctx, uint8_t* base) {
	// 0x26F810: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26F818: movss [0x005682FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5682FCu, ctx.xmm[0].u32[0]);
	// 0x26F820: ret
	return;
}

void sub_26F830(X86Context& ctx, uint8_t* base) {
	// 0x26F830: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26F838: movss [0x005683DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5683DCu, ctx.xmm[0].u32[0]);
	// 0x26F840: ret
	return;
}

void sub_26F850(X86Context& ctx, uint8_t* base) {
	// 0x26F850: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26F858: movss [0x005683F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5683F8u, ctx.xmm[0].u32[0]);
	// 0x26F860: ret
	return;
}

void sub_26F870(X86Context& ctx, uint8_t* base) {
	// 0x26F870: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26F878: movss [0x005683CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5683CCu, ctx.xmm[0].u32[0]);
	// 0x26F880: ret
	return;
}

void sub_26F890(X86Context& ctx, uint8_t* base) {
	// 0x26F890: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26F898: movss [0x00568380], xmm0
	X86_MEM_WRITE_u32(base, 0x568380u, ctx.xmm[0].u32[0]);
	// 0x26F8A0: ret
	return;
}

void sub_26F8B0(X86Context& ctx, uint8_t* base) {
	// 0x26F8B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26F8B8: movss [0x005683E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5683E0u, ctx.xmm[0].u32[0]);
	// 0x26F8C0: ret
	return;
}

void sub_26F8D0(X86Context& ctx, uint8_t* base) {
	// 0x26F8D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26F8D8: movss [0x0056839C], xmm0
	X86_MEM_WRITE_u32(base, 0x56839Cu, ctx.xmm[0].u32[0]);
	// 0x26F8E0: ret
	return;
}

void sub_26F8F0(X86Context& ctx, uint8_t* base) {
	// 0x26F8F0: movss xmm0, dword ptr [0x005683E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683E0u);
	// 0x26F8F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26F900: movss [0x00568418], xmm0
	X86_MEM_WRITE_u32(base, 0x568418u, ctx.xmm[0].u32[0]);
	// 0x26F908: ret
	return;
}

void sub_26F910(X86Context& ctx, uint8_t* base) {
	// 0x26F910: movss xmm0, dword ptr [0x0056839C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56839Cu);
	// 0x26F918: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26F920: movss [0x00568400], xmm0
	X86_MEM_WRITE_u32(base, 0x568400u, ctx.xmm[0].u32[0]);
	// 0x26F928: ret
	return;
}

void sub_26F930(X86Context& ctx, uint8_t* base) {
	// 0x26F930: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26F938: movss [0x00568430], xmm0
	X86_MEM_WRITE_u32(base, 0x568430u, ctx.xmm[0].u32[0]);
	// 0x26F940: ret
	return;
}

void sub_26F950(X86Context& ctx, uint8_t* base) {
	// 0x26F950: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26F958: movss [0x0056841C], xmm0
	X86_MEM_WRITE_u32(base, 0x56841Cu, ctx.xmm[0].u32[0]);
	// 0x26F960: ret
	return;
}

void sub_26F970(X86Context& ctx, uint8_t* base) {
	// 0x26F970: movss xmm0, dword ptr [0x0056841C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56841Cu);
	// 0x26F978: movss [0x0056842C], xmm0
	X86_MEM_WRITE_u32(base, 0x56842Cu, ctx.xmm[0].u32[0]);
	// 0x26F980: ret
	return;
}

void sub_26F990(X86Context& ctx, uint8_t* base) {
	// 0x26F990: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26F998: movss [0x00568388], xmm0
	X86_MEM_WRITE_u32(base, 0x568388u, ctx.xmm[0].u32[0]);
	// 0x26F9A0: ret
	return;
}

void sub_26F9B0(X86Context& ctx, uint8_t* base) {
	// 0x26F9B0: movss xmm0, dword ptr [0x0056839C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56839Cu);
	// 0x26F9B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26F9C0: movss [0x00568424], xmm0
	X86_MEM_WRITE_u32(base, 0x568424u, ctx.xmm[0].u32[0]);
	// 0x26F9C8: ret
	return;
}

void sub_26F9D0(X86Context& ctx, uint8_t* base) {
	// 0x26F9D0: movss xmm0, dword ptr [0x0056839C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56839Cu);
	// 0x26F9D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26F9E0: movss [0x005683C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5683C8u, ctx.xmm[0].u32[0]);
	// 0x26F9E8: ret
	return;
}

void sub_26F9F0(X86Context& ctx, uint8_t* base) {
	// 0x26F9F0: movss xmm0, dword ptr [0x0056839C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56839Cu);
	// 0x26F9F8: subss xmm0, [0x005683C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5683C8u);
	// 0x26FA00: movss [0x005683A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5683A4u, ctx.xmm[0].u32[0]);
	// 0x26FA08: ret
	return;
}

void sub_26FA10(X86Context& ctx, uint8_t* base) {
	// 0x26FA10: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26FA18: movss [0x005683F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5683F4u, ctx.xmm[0].u32[0]);
	// 0x26FA20: ret
	return;
}

void sub_26FA30(X86Context& ctx, uint8_t* base) {
	// 0x26FA30: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26FA38: movss [0x005683A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5683A0u, ctx.xmm[0].u32[0]);
	// 0x26FA40: ret
	return;
}

void sub_26FA50(X86Context& ctx, uint8_t* base) {
	// 0x26FA50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26FA58: movss [0x005683B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5683B4u, ctx.xmm[0].u32[0]);
	// 0x26FA60: ret
	return;
}

void sub_26FA70(X86Context& ctx, uint8_t* base) {
	// 0x26FA70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26FA78: movss [0x0056840C], xmm0
	X86_MEM_WRITE_u32(base, 0x56840Cu, ctx.xmm[0].u32[0]);
	// 0x26FA80: ret
	return;
}

void sub_26FA90(X86Context& ctx, uint8_t* base) {
	// 0x26FA90: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26FA98: movss [0x005683F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5683F0u, ctx.xmm[0].u32[0]);
	// 0x26FAA0: ret
	return;
}

void sub_26FAB0(X86Context& ctx, uint8_t* base) {
	// 0x26FAB0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26FAB8: movss [0x00568398], xmm0
	X86_MEM_WRITE_u32(base, 0x568398u, ctx.xmm[0].u32[0]);
	// 0x26FAC0: ret
	return;
}

void sub_26FAD0(X86Context& ctx, uint8_t* base) {
	// 0x26FAD0: movss xmm0, dword ptr [0x005683B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683B4u);
	// 0x26FAD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26FAE0: movss [0x0056838C], xmm0
	X86_MEM_WRITE_u32(base, 0x56838Cu, ctx.xmm[0].u32[0]);
	// 0x26FAE8: ret
	return;
}

void sub_26FAF0(X86Context& ctx, uint8_t* base) {
	// 0x26FAF0: movss xmm0, dword ptr [0x0056840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56840Cu);
	// 0x26FAF8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26FB00: movss [0x005683D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5683D4u, ctx.xmm[0].u32[0]);
	// 0x26FB08: ret
	return;
}

void sub_26FB10(X86Context& ctx, uint8_t* base) {
	// 0x26FB10: movss xmm0, dword ptr [0x0056838C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56838Cu);
	// 0x26FB18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26FB20: movss [0x005683E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5683E8u, ctx.xmm[0].u32[0]);
	// 0x26FB28: ret
	return;
}

void sub_26FB30(X86Context& ctx, uint8_t* base) {
	// 0x26FB30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26FB38: movss [0x00568384], xmm0
	X86_MEM_WRITE_u32(base, 0x568384u, ctx.xmm[0].u32[0]);
	// 0x26FB40: ret
	return;
}

void sub_26FB50(X86Context& ctx, uint8_t* base) {
	// 0x26FB50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26FB58: movss [0x005683B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5683B8u, ctx.xmm[0].u32[0]);
	// 0x26FB60: ret
	return;
}

void sub_26FB70(X86Context& ctx, uint8_t* base) {
	// 0x26FB70: movss xmm0, dword ptr [0x005683B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683B4u);
	// 0x26FB78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26FB80: movss [0x005683C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5683C4u, ctx.xmm[0].u32[0]);
	// 0x26FB88: ret
	return;
}

void sub_26FB90(X86Context& ctx, uint8_t* base) {
	// 0x26FB90: movss xmm0, dword ptr [0x0056840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56840Cu);
	// 0x26FB98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26FBA0: movss [0x00568410], xmm0
	X86_MEM_WRITE_u32(base, 0x568410u, ctx.xmm[0].u32[0]);
	// 0x26FBA8: ret
	return;
}

void sub_26FBB0(X86Context& ctx, uint8_t* base) {
	// 0x26FBB0: movss xmm0, dword ptr [0x005683C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683C4u);
	// 0x26FBB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26FBC0: movss [0x005683FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5683FCu, ctx.xmm[0].u32[0]);
	// 0x26FBC8: ret
	return;
}

void sub_26FBD0(X86Context& ctx, uint8_t* base) {
	// 0x26FBD0: movss xmm0, dword ptr [0x00568410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568410u);
	// 0x26FBD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26FBE0: movss [0x00568420], xmm0
	X86_MEM_WRITE_u32(base, 0x568420u, ctx.xmm[0].u32[0]);
	// 0x26FBE8: ret
	return;
}

void sub_26FBF0(X86Context& ctx, uint8_t* base) {
	// 0x26FBF0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26FBF8: movss [0x00568390], xmm0
	X86_MEM_WRITE_u32(base, 0x568390u, ctx.xmm[0].u32[0]);
	// 0x26FC00: ret
	return;
}

void sub_26FC10(X86Context& ctx, uint8_t* base) {
	// 0x26FC10: movss xmm0, dword ptr [0x005683B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683B4u);
	// 0x26FC18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26FC20: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26FC28: movss [0x00568408], xmm0
	X86_MEM_WRITE_u32(base, 0x568408u, ctx.xmm[0].u32[0]);
	// 0x26FC30: ret
	return;
}

void sub_26FC40(X86Context& ctx, uint8_t* base) {
	// 0x26FC40: movss xmm0, dword ptr [0x0056840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56840Cu);
	// 0x26FC48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26FC50: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26FC58: movss [0x005683A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5683A8u, ctx.xmm[0].u32[0]);
	// 0x26FC60: ret
	return;
}

void sub_26FC70(X86Context& ctx, uint8_t* base) {
	// 0x26FC70: movss xmm0, dword ptr [0x005683B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683B4u);
	// 0x26FC78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26FC80: movss [0x005683AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5683ACu, ctx.xmm[0].u32[0]);
	// 0x26FC88: ret
	return;
}

void sub_26FC90(X86Context& ctx, uint8_t* base) {
	// 0x26FC90: movss xmm0, dword ptr [0x0056840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56840Cu);
	// 0x26FC98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26FCA0: movss [0x00568414], xmm0
	X86_MEM_WRITE_u32(base, 0x568414u, ctx.xmm[0].u32[0]);
	// 0x26FCA8: ret
	return;
}

void sub_26FCB0(X86Context& ctx, uint8_t* base) {
	// 0x26FCB0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26FCB8: movss [0x00568394], xmm0
	X86_MEM_WRITE_u32(base, 0x568394u, ctx.xmm[0].u32[0]);
	// 0x26FCC0: ret
	return;
}

void sub_26FCD0(X86Context& ctx, uint8_t* base) {
	// 0x26FCD0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26FCD8: movss [0x005683C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5683C0u, ctx.xmm[0].u32[0]);
	// 0x26FCE0: ret
	return;
}

void sub_26FCF0(X86Context& ctx, uint8_t* base) {
	// 0x26FCF0: movss xmm0, dword ptr [0x00568394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568394u);
	// 0x26FCF8: movss [0x00568428], xmm0
	X86_MEM_WRITE_u32(base, 0x568428u, ctx.xmm[0].u32[0]);
	// 0x26FD00: ret
	return;
}

void sub_26FD10(X86Context& ctx, uint8_t* base) {
	// 0x26FD10: movss xmm0, dword ptr [0x0056840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56840Cu);
	// 0x26FD18: subss xmm0, [0x00568394]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568394u);
	// 0x26FD20: movss [0x005683EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5683ECu, ctx.xmm[0].u32[0]);
	// 0x26FD28: ret
	return;
}

void sub_26FD30(X86Context& ctx, uint8_t* base) {
	// 0x26FD30: movss xmm0, dword ptr [0x005683EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683ECu);
	// 0x26FD38: subss xmm0, [0x005683C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5683C0u);
	// 0x26FD40: movss [0x005683E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5683E4u, ctx.xmm[0].u32[0]);
	// 0x26FD48: ret
	return;
}

void sub_26FD50(X86Context& ctx, uint8_t* base) {
	// 0x26FD50: movss xmm0, dword ptr [0x00568414]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568414u);
	// 0x26FD58: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26FD60: movss [0x005683D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5683D0u, ctx.xmm[0].u32[0]);
	// 0x26FD68: ret
	return;
}

void sub_26FD70(X86Context& ctx, uint8_t* base) {
	// 0x26FD70: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26FD78: movss [0x005683BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5683BCu, ctx.xmm[0].u32[0]);
	// 0x26FD80: ret
	return;
}

void sub_26FD90(X86Context& ctx, uint8_t* base) {
	// 0x26FD90: movss xmm0, dword ptr [0x005683D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5683D0u);
	// 0x26FD98: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26FDA0: movss [0x00568404], xmm0
	X86_MEM_WRITE_u32(base, 0x568404u, ctx.xmm[0].u32[0]);
	// 0x26FDA8: ret
	return;
}

void sub_26FDB0(X86Context& ctx, uint8_t* base) {
	// 0x26FDB0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26FDB8: movss [0x005683D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5683D8u, ctx.xmm[0].u32[0]);
	// 0x26FDC0: ret
	return;
}

void sub_26FDD0(X86Context& ctx, uint8_t* base) {
	// 0x26FDD0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26FDD8: movss [0x005683B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5683B0u, ctx.xmm[0].u32[0]);
	// 0x26FDE0: ret
	return;
}

void sub_26FDF0(X86Context& ctx, uint8_t* base) {
	// 0x26FDF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26FDF8: movss [0x00568490], xmm0
	X86_MEM_WRITE_u32(base, 0x568490u, ctx.xmm[0].u32[0]);
	// 0x26FE00: ret
	return;
}

void sub_26FE10(X86Context& ctx, uint8_t* base) {
	// 0x26FE10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26FE18: movss [0x005684AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5684ACu, ctx.xmm[0].u32[0]);
	// 0x26FE20: ret
	return;
}

void sub_26FE30(X86Context& ctx, uint8_t* base) {
	// 0x26FE30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26FE38: movss [0x00568480], xmm0
	X86_MEM_WRITE_u32(base, 0x568480u, ctx.xmm[0].u32[0]);
	// 0x26FE40: ret
	return;
}

void sub_26FE50(X86Context& ctx, uint8_t* base) {
	// 0x26FE50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26FE58: movss [0x00568434], xmm0
	X86_MEM_WRITE_u32(base, 0x568434u, ctx.xmm[0].u32[0]);
	// 0x26FE60: ret
	return;
}

void sub_26FE70(X86Context& ctx, uint8_t* base) {
	// 0x26FE70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26FE78: movss [0x00568494], xmm0
	X86_MEM_WRITE_u32(base, 0x568494u, ctx.xmm[0].u32[0]);
	// 0x26FE80: ret
	return;
}

void sub_26FE90(X86Context& ctx, uint8_t* base) {
	// 0x26FE90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26FE98: movss [0x00568450], xmm0
	X86_MEM_WRITE_u32(base, 0x568450u, ctx.xmm[0].u32[0]);
	// 0x26FEA0: ret
	return;
}

void sub_26FEB0(X86Context& ctx, uint8_t* base) {
	// 0x26FEB0: movss xmm0, dword ptr [0x00568494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568494u);
	// 0x26FEB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26FEC0: movss [0x005684CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5684CCu, ctx.xmm[0].u32[0]);
	// 0x26FEC8: ret
	return;
}

void sub_26FED0(X86Context& ctx, uint8_t* base) {
	// 0x26FED0: movss xmm0, dword ptr [0x00568450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568450u);
	// 0x26FED8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26FEE0: movss [0x005684B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5684B4u, ctx.xmm[0].u32[0]);
	// 0x26FEE8: ret
	return;
}

void sub_26FEF0(X86Context& ctx, uint8_t* base) {
	// 0x26FEF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26FEF8: movss [0x005684E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5684E4u, ctx.xmm[0].u32[0]);
	// 0x26FF00: ret
	return;
}

void sub_26FF10(X86Context& ctx, uint8_t* base) {
	// 0x26FF10: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26FF18: movss [0x005684D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5684D0u, ctx.xmm[0].u32[0]);
	// 0x26FF20: ret
	return;
}

void sub_26FF30(X86Context& ctx, uint8_t* base) {
	// 0x26FF30: movss xmm0, dword ptr [0x005684D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684D0u);
	// 0x26FF38: movss [0x005684E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5684E0u, ctx.xmm[0].u32[0]);
	// 0x26FF40: ret
	return;
}

void sub_26FF50(X86Context& ctx, uint8_t* base) {
	// 0x26FF50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26FF58: movss [0x0056843C], xmm0
	X86_MEM_WRITE_u32(base, 0x56843Cu, ctx.xmm[0].u32[0]);
	// 0x26FF60: ret
	return;
}

void sub_26FF70(X86Context& ctx, uint8_t* base) {
	// 0x26FF70: movss xmm0, dword ptr [0x00568450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568450u);
	// 0x26FF78: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26FF80: movss [0x005684D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5684D8u, ctx.xmm[0].u32[0]);
	// 0x26FF88: ret
	return;
}

void sub_26FF90(X86Context& ctx, uint8_t* base) {
	// 0x26FF90: movss xmm0, dword ptr [0x00568450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568450u);
	// 0x26FF98: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26FFA0: movss [0x0056847C], xmm0
	X86_MEM_WRITE_u32(base, 0x56847Cu, ctx.xmm[0].u32[0]);
	// 0x26FFA8: ret
	return;
}

void sub_26FFB0(X86Context& ctx, uint8_t* base) {
	// 0x26FFB0: movss xmm0, dword ptr [0x00568450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568450u);
	// 0x26FFB8: subss xmm0, [0x0056847C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56847Cu);
	// 0x26FFC0: movss [0x00568458], xmm0
	X86_MEM_WRITE_u32(base, 0x568458u, ctx.xmm[0].u32[0]);
	// 0x26FFC8: ret
	return;
}

void sub_26FFD0(X86Context& ctx, uint8_t* base) {
	// 0x26FFD0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26FFD8: movss [0x005684A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5684A8u, ctx.xmm[0].u32[0]);
	// 0x26FFE0: ret
	return;
}

void sub_26FFF0(X86Context& ctx, uint8_t* base) {
	// 0x26FFF0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26FFF8: movss [0x00568454], xmm0
	X86_MEM_WRITE_u32(base, 0x568454u, ctx.xmm[0].u32[0]);
	// 0x270000: ret
	return;
}

void sub_270010(X86Context& ctx, uint8_t* base) {
	// 0x270010: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x270018: movss [0x00568468], xmm0
	X86_MEM_WRITE_u32(base, 0x568468u, ctx.xmm[0].u32[0]);
	// 0x270020: ret
	return;
}

void sub_270030(X86Context& ctx, uint8_t* base) {
	// 0x270030: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x270038: movss [0x005684C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5684C0u, ctx.xmm[0].u32[0]);
	// 0x270040: ret
	return;
}

void sub_270050(X86Context& ctx, uint8_t* base) {
	// 0x270050: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x270058: movss [0x005684A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5684A4u, ctx.xmm[0].u32[0]);
	// 0x270060: ret
	return;
}

void sub_270070(X86Context& ctx, uint8_t* base) {
	// 0x270070: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x270078: movss [0x0056844C], xmm0
	X86_MEM_WRITE_u32(base, 0x56844Cu, ctx.xmm[0].u32[0]);
	// 0x270080: ret
	return;
}

void sub_270090(X86Context& ctx, uint8_t* base) {
	// 0x270090: movss xmm0, dword ptr [0x00568468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568468u);
	// 0x270098: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2700A0: movss [0x00568440], xmm0
	X86_MEM_WRITE_u32(base, 0x568440u, ctx.xmm[0].u32[0]);
	// 0x2700A8: ret
	return;
}

void sub_2700B0(X86Context& ctx, uint8_t* base) {
	// 0x2700B0: movss xmm0, dword ptr [0x005684C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C0u);
	// 0x2700B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2700C0: movss [0x00568488], xmm0
	X86_MEM_WRITE_u32(base, 0x568488u, ctx.xmm[0].u32[0]);
	// 0x2700C8: ret
	return;
}

void sub_2700D0(X86Context& ctx, uint8_t* base) {
	// 0x2700D0: movss xmm0, dword ptr [0x00568440]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568440u);
	// 0x2700D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2700E0: movss [0x0056849C], xmm0
	X86_MEM_WRITE_u32(base, 0x56849Cu, ctx.xmm[0].u32[0]);
	// 0x2700E8: ret
	return;
}

void sub_2700F0(X86Context& ctx, uint8_t* base) {
	// 0x2700F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2700F8: movss [0x00568438], xmm0
	X86_MEM_WRITE_u32(base, 0x568438u, ctx.xmm[0].u32[0]);
	// 0x270100: ret
	return;
}

void sub_270110(X86Context& ctx, uint8_t* base) {
	// 0x270110: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x270118: movss [0x0056846C], xmm0
	X86_MEM_WRITE_u32(base, 0x56846Cu, ctx.xmm[0].u32[0]);
	// 0x270120: ret
	return;
}

void sub_270130(X86Context& ctx, uint8_t* base) {
	// 0x270130: movss xmm0, dword ptr [0x00568468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568468u);
	// 0x270138: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x270140: movss [0x00568478], xmm0
	X86_MEM_WRITE_u32(base, 0x568478u, ctx.xmm[0].u32[0]);
	// 0x270148: ret
	return;
}

void sub_270150(X86Context& ctx, uint8_t* base) {
	// 0x270150: movss xmm0, dword ptr [0x005684C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C0u);
	// 0x270158: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x270160: movss [0x005684C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5684C4u, ctx.xmm[0].u32[0]);
	// 0x270168: ret
	return;
}

void sub_270170(X86Context& ctx, uint8_t* base) {
	// 0x270170: movss xmm0, dword ptr [0x00568478]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568478u);
	// 0x270178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270180: movss [0x005684B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5684B0u, ctx.xmm[0].u32[0]);
	// 0x270188: ret
	return;
}

void sub_270190(X86Context& ctx, uint8_t* base) {
	// 0x270190: movss xmm0, dword ptr [0x005684C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C4u);
	// 0x270198: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2701A0: movss [0x005684D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5684D4u, ctx.xmm[0].u32[0]);
	// 0x2701A8: ret
	return;
}

void sub_2701B0(X86Context& ctx, uint8_t* base) {
	// 0x2701B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2701B8: movss [0x00568444], xmm0
	X86_MEM_WRITE_u32(base, 0x568444u, ctx.xmm[0].u32[0]);
	// 0x2701C0: ret
	return;
}

void sub_2701D0(X86Context& ctx, uint8_t* base) {
	// 0x2701D0: movss xmm0, dword ptr [0x00568468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568468u);
	// 0x2701D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2701E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2701E8: movss [0x005684BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5684BCu, ctx.xmm[0].u32[0]);
	// 0x2701F0: ret
	return;
}

void sub_270200(X86Context& ctx, uint8_t* base) {
	// 0x270200: movss xmm0, dword ptr [0x005684C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C0u);
	// 0x270208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270210: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x270218: movss [0x0056845C], xmm0
	X86_MEM_WRITE_u32(base, 0x56845Cu, ctx.xmm[0].u32[0]);
	// 0x270220: ret
	return;
}

void sub_270230(X86Context& ctx, uint8_t* base) {
	// 0x270230: movss xmm0, dword ptr [0x00568468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568468u);
	// 0x270238: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270240: movss [0x00568460], xmm0
	X86_MEM_WRITE_u32(base, 0x568460u, ctx.xmm[0].u32[0]);
	// 0x270248: ret
	return;
}

void sub_270250(X86Context& ctx, uint8_t* base) {
	// 0x270250: movss xmm0, dword ptr [0x005684C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C0u);
	// 0x270258: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270260: movss [0x005684C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5684C8u, ctx.xmm[0].u32[0]);
	// 0x270268: ret
	return;
}

void sub_270270(X86Context& ctx, uint8_t* base) {
	// 0x270270: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x270278: movss [0x00568448], xmm0
	X86_MEM_WRITE_u32(base, 0x568448u, ctx.xmm[0].u32[0]);
	// 0x270280: ret
	return;
}

void sub_270290(X86Context& ctx, uint8_t* base) {
	// 0x270290: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x270298: movss [0x00568474], xmm0
	X86_MEM_WRITE_u32(base, 0x568474u, ctx.xmm[0].u32[0]);
	// 0x2702A0: ret
	return;
}

void sub_2702B0(X86Context& ctx, uint8_t* base) {
	// 0x2702B0: movss xmm0, dword ptr [0x00568448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568448u);
	// 0x2702B8: movss [0x005684DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5684DCu, ctx.xmm[0].u32[0]);
	// 0x2702C0: ret
	return;
}

void sub_2702D0(X86Context& ctx, uint8_t* base) {
	// 0x2702D0: movss xmm0, dword ptr [0x005684C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C0u);
	// 0x2702D8: subss xmm0, [0x00568448]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568448u);
	// 0x2702E0: movss [0x005684A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5684A0u, ctx.xmm[0].u32[0]);
	// 0x2702E8: ret
	return;
}

void sub_2702F0(X86Context& ctx, uint8_t* base) {
	// 0x2702F0: movss xmm0, dword ptr [0x005684A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684A0u);
	// 0x2702F8: subss xmm0, [0x00568474]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568474u);
	// 0x270300: movss [0x00568498], xmm0
	X86_MEM_WRITE_u32(base, 0x568498u, ctx.xmm[0].u32[0]);
	// 0x270308: ret
	return;
}

void sub_270310(X86Context& ctx, uint8_t* base) {
	// 0x270310: movss xmm0, dword ptr [0x005684C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684C8u);
	// 0x270318: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x270320: movss [0x00568484], xmm0
	X86_MEM_WRITE_u32(base, 0x568484u, ctx.xmm[0].u32[0]);
	// 0x270328: ret
	return;
}

void sub_270330(X86Context& ctx, uint8_t* base) {
	// 0x270330: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x270338: movss [0x00568470], xmm0
	X86_MEM_WRITE_u32(base, 0x568470u, ctx.xmm[0].u32[0]);
	// 0x270340: ret
	return;
}

void sub_270350(X86Context& ctx, uint8_t* base) {
	// 0x270350: movss xmm0, dword ptr [0x00568484]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568484u);
	// 0x270358: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x270360: movss [0x005684B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5684B8u, ctx.xmm[0].u32[0]);
	// 0x270368: ret
	return;
}

void sub_270370(X86Context& ctx, uint8_t* base) {
	// 0x270370: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x270378: movss [0x0056848C], xmm0
	X86_MEM_WRITE_u32(base, 0x56848Cu, ctx.xmm[0].u32[0]);
	// 0x270380: ret
	return;
}

void sub_270390(X86Context& ctx, uint8_t* base) {
	// 0x270390: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x270398: movss [0x00568464], xmm0
	X86_MEM_WRITE_u32(base, 0x568464u, ctx.xmm[0].u32[0]);
	// 0x2703A0: ret
	return;
}

void sub_2703B0(X86Context& ctx, uint8_t* base) {
	// 0x2703B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2703B8: movss [0x00568544], xmm0
	X86_MEM_WRITE_u32(base, 0x568544u, ctx.xmm[0].u32[0]);
	// 0x2703C0: ret
	return;
}

void sub_2703D0(X86Context& ctx, uint8_t* base) {
	// 0x2703D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2703D8: movss [0x00568560], xmm0
	X86_MEM_WRITE_u32(base, 0x568560u, ctx.xmm[0].u32[0]);
	// 0x2703E0: ret
	return;
}

void sub_2703F0(X86Context& ctx, uint8_t* base) {
	// 0x2703F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2703F8: movss [0x00568534], xmm0
	X86_MEM_WRITE_u32(base, 0x568534u, ctx.xmm[0].u32[0]);
	// 0x270400: ret
	return;
}

void sub_270410(X86Context& ctx, uint8_t* base) {
	// 0x270410: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x270418: movss [0x005684E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5684E8u, ctx.xmm[0].u32[0]);
	// 0x270420: ret
	return;
}

void sub_270430(X86Context& ctx, uint8_t* base) {
	// 0x270430: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x270438: movss [0x00568548], xmm0
	X86_MEM_WRITE_u32(base, 0x568548u, ctx.xmm[0].u32[0]);
	// 0x270440: ret
	return;
}

void sub_270450(X86Context& ctx, uint8_t* base) {
	// 0x270450: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x270458: movss [0x00568504], xmm0
	X86_MEM_WRITE_u32(base, 0x568504u, ctx.xmm[0].u32[0]);
	// 0x270460: ret
	return;
}

void sub_270470(X86Context& ctx, uint8_t* base) {
	// 0x270470: movss xmm0, dword ptr [0x00568548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568548u);
	// 0x270478: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x270480: movss [0x00568580], xmm0
	X86_MEM_WRITE_u32(base, 0x568580u, ctx.xmm[0].u32[0]);
	// 0x270488: ret
	return;
}

void sub_270490(X86Context& ctx, uint8_t* base) {
	// 0x270490: movss xmm0, dword ptr [0x00568504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568504u);
	// 0x270498: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2704A0: movss [0x00568568], xmm0
	X86_MEM_WRITE_u32(base, 0x568568u, ctx.xmm[0].u32[0]);
	// 0x2704A8: ret
	return;
}

void sub_2704B0(X86Context& ctx, uint8_t* base) {
	// 0x2704B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2704B8: movss [0x00568598], xmm0
	X86_MEM_WRITE_u32(base, 0x568598u, ctx.xmm[0].u32[0]);
	// 0x2704C0: ret
	return;
}

void sub_2704D0(X86Context& ctx, uint8_t* base) {
	// 0x2704D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2704D8: movss [0x00568584], xmm0
	X86_MEM_WRITE_u32(base, 0x568584u, ctx.xmm[0].u32[0]);
	// 0x2704E0: ret
	return;
}

void sub_2704F0(X86Context& ctx, uint8_t* base) {
	// 0x2704F0: movss xmm0, dword ptr [0x00568584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568584u);
	// 0x2704F8: movss [0x00568594], xmm0
	X86_MEM_WRITE_u32(base, 0x568594u, ctx.xmm[0].u32[0]);
	// 0x270500: ret
	return;
}

void sub_270510(X86Context& ctx, uint8_t* base) {
	// 0x270510: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x270518: movss [0x005684F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5684F0u, ctx.xmm[0].u32[0]);
	// 0x270520: ret
	return;
}

void sub_270530(X86Context& ctx, uint8_t* base) {
	// 0x270530: movss xmm0, dword ptr [0x00568504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568504u);
	// 0x270538: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x270540: movss [0x0056858C], xmm0
	X86_MEM_WRITE_u32(base, 0x56858Cu, ctx.xmm[0].u32[0]);
	// 0x270548: ret
	return;
}

void sub_270550(X86Context& ctx, uint8_t* base) {
	// 0x270550: movss xmm0, dword ptr [0x00568504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568504u);
	// 0x270558: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x270560: movss [0x00568530], xmm0
	X86_MEM_WRITE_u32(base, 0x568530u, ctx.xmm[0].u32[0]);
	// 0x270568: ret
	return;
}

void sub_270570(X86Context& ctx, uint8_t* base) {
	// 0x270570: movss xmm0, dword ptr [0x00568504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568504u);
	// 0x270578: subss xmm0, [0x00568530]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568530u);
	// 0x270580: movss [0x0056850C], xmm0
	X86_MEM_WRITE_u32(base, 0x56850Cu, ctx.xmm[0].u32[0]);
	// 0x270588: ret
	return;
}

void sub_270590(X86Context& ctx, uint8_t* base) {
	// 0x270590: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x270598: movss [0x0056855C], xmm0
	X86_MEM_WRITE_u32(base, 0x56855Cu, ctx.xmm[0].u32[0]);
	// 0x2705A0: ret
	return;
}

void sub_2705B0(X86Context& ctx, uint8_t* base) {
	// 0x2705B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2705B8: movss [0x00568508], xmm0
	X86_MEM_WRITE_u32(base, 0x568508u, ctx.xmm[0].u32[0]);
	// 0x2705C0: ret
	return;
}

void sub_2705D0(X86Context& ctx, uint8_t* base) {
	// 0x2705D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2705D8: movss [0x0056851C], xmm0
	X86_MEM_WRITE_u32(base, 0x56851Cu, ctx.xmm[0].u32[0]);
	// 0x2705E0: ret
	return;
}

void sub_2705F0(X86Context& ctx, uint8_t* base) {
	// 0x2705F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2705F8: movss [0x00568574], xmm0
	X86_MEM_WRITE_u32(base, 0x568574u, ctx.xmm[0].u32[0]);
	// 0x270600: ret
	return;
}

void sub_270610(X86Context& ctx, uint8_t* base) {
	// 0x270610: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x270618: movss [0x00568558], xmm0
	X86_MEM_WRITE_u32(base, 0x568558u, ctx.xmm[0].u32[0]);
	// 0x270620: ret
	return;
}

void sub_270630(X86Context& ctx, uint8_t* base) {
	// 0x270630: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x270638: movss [0x00568500], xmm0
	X86_MEM_WRITE_u32(base, 0x568500u, ctx.xmm[0].u32[0]);
	// 0x270640: ret
	return;
}

void sub_270650(X86Context& ctx, uint8_t* base) {
	// 0x270650: movss xmm0, dword ptr [0x0056851C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56851Cu);
	// 0x270658: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x270660: movss [0x005684F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5684F4u, ctx.xmm[0].u32[0]);
	// 0x270668: ret
	return;
}

void sub_270670(X86Context& ctx, uint8_t* base) {
	// 0x270670: movss xmm0, dword ptr [0x00568574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568574u);
	// 0x270678: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x270680: movss [0x0056853C], xmm0
	X86_MEM_WRITE_u32(base, 0x56853Cu, ctx.xmm[0].u32[0]);
	// 0x270688: ret
	return;
}

void sub_270690(X86Context& ctx, uint8_t* base) {
	// 0x270690: movss xmm0, dword ptr [0x005684F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684F4u);
	// 0x270698: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2706A0: movss [0x00568550], xmm0
	X86_MEM_WRITE_u32(base, 0x568550u, ctx.xmm[0].u32[0]);
	// 0x2706A8: ret
	return;
}

void sub_2706B0(X86Context& ctx, uint8_t* base) {
	// 0x2706B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2706B8: movss [0x005684EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5684ECu, ctx.xmm[0].u32[0]);
	// 0x2706C0: ret
	return;
}

void sub_2706D0(X86Context& ctx, uint8_t* base) {
	// 0x2706D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2706D8: movss [0x00568520], xmm0
	X86_MEM_WRITE_u32(base, 0x568520u, ctx.xmm[0].u32[0]);
	// 0x2706E0: ret
	return;
}

void sub_2706F0(X86Context& ctx, uint8_t* base) {
	// 0x2706F0: movss xmm0, dword ptr [0x0056851C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56851Cu);
	// 0x2706F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x270700: movss [0x0056852C], xmm0
	X86_MEM_WRITE_u32(base, 0x56852Cu, ctx.xmm[0].u32[0]);
	// 0x270708: ret
	return;
}

void sub_270710(X86Context& ctx, uint8_t* base) {
	// 0x270710: movss xmm0, dword ptr [0x00568574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568574u);
	// 0x270718: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x270720: movss [0x00568578], xmm0
	X86_MEM_WRITE_u32(base, 0x568578u, ctx.xmm[0].u32[0]);
	// 0x270728: ret
	return;
}

void sub_270730(X86Context& ctx, uint8_t* base) {
	// 0x270730: movss xmm0, dword ptr [0x0056852C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56852Cu);
	// 0x270738: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270740: movss [0x00568564], xmm0
	X86_MEM_WRITE_u32(base, 0x568564u, ctx.xmm[0].u32[0]);
	// 0x270748: ret
	return;
}

void sub_270750(X86Context& ctx, uint8_t* base) {
	// 0x270750: movss xmm0, dword ptr [0x00568578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568578u);
	// 0x270758: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270760: movss [0x00568588], xmm0
	X86_MEM_WRITE_u32(base, 0x568588u, ctx.xmm[0].u32[0]);
	// 0x270768: ret
	return;
}

void sub_270770(X86Context& ctx, uint8_t* base) {
	// 0x270770: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x270778: movss [0x005684F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5684F8u, ctx.xmm[0].u32[0]);
	// 0x270780: ret
	return;
}

void sub_270790(X86Context& ctx, uint8_t* base) {
	// 0x270790: movss xmm0, dword ptr [0x0056851C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56851Cu);
	// 0x270798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2707A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2707A8: movss [0x00568570], xmm0
	X86_MEM_WRITE_u32(base, 0x568570u, ctx.xmm[0].u32[0]);
	// 0x2707B0: ret
	return;
}

void sub_2707C0(X86Context& ctx, uint8_t* base) {
	// 0x2707C0: movss xmm0, dword ptr [0x00568574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568574u);
	// 0x2707C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2707D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2707D8: movss [0x00568510], xmm0
	X86_MEM_WRITE_u32(base, 0x568510u, ctx.xmm[0].u32[0]);
	// 0x2707E0: ret
	return;
}

void sub_2707F0(X86Context& ctx, uint8_t* base) {
	// 0x2707F0: movss xmm0, dword ptr [0x0056851C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56851Cu);
	// 0x2707F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270800: movss [0x00568514], xmm0
	X86_MEM_WRITE_u32(base, 0x568514u, ctx.xmm[0].u32[0]);
	// 0x270808: ret
	return;
}

void sub_270810(X86Context& ctx, uint8_t* base) {
	// 0x270810: movss xmm0, dword ptr [0x00568574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568574u);
	// 0x270818: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270820: movss [0x0056857C], xmm0
	X86_MEM_WRITE_u32(base, 0x56857Cu, ctx.xmm[0].u32[0]);
	// 0x270828: ret
	return;
}

void sub_270830(X86Context& ctx, uint8_t* base) {
	// 0x270830: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x270838: movss [0x005684FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5684FCu, ctx.xmm[0].u32[0]);
	// 0x270840: ret
	return;
}

void sub_270850(X86Context& ctx, uint8_t* base) {
	// 0x270850: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x270858: movss [0x00568528], xmm0
	X86_MEM_WRITE_u32(base, 0x568528u, ctx.xmm[0].u32[0]);
	// 0x270860: ret
	return;
}

void sub_270870(X86Context& ctx, uint8_t* base) {
	// 0x270870: movss xmm0, dword ptr [0x005684FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5684FCu);
	// 0x270878: movss [0x00568590], xmm0
	X86_MEM_WRITE_u32(base, 0x568590u, ctx.xmm[0].u32[0]);
	// 0x270880: ret
	return;
}

void sub_270890(X86Context& ctx, uint8_t* base) {
	// 0x270890: movss xmm0, dword ptr [0x00568574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568574u);
	// 0x270898: subss xmm0, [0x005684FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5684FCu);
	// 0x2708A0: movss [0x00568554], xmm0
	X86_MEM_WRITE_u32(base, 0x568554u, ctx.xmm[0].u32[0]);
	// 0x2708A8: ret
	return;
}

void sub_2708B0(X86Context& ctx, uint8_t* base) {
	// 0x2708B0: movss xmm0, dword ptr [0x00568554]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568554u);
	// 0x2708B8: subss xmm0, [0x00568528]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568528u);
	// 0x2708C0: movss [0x0056854C], xmm0
	X86_MEM_WRITE_u32(base, 0x56854Cu, ctx.xmm[0].u32[0]);
	// 0x2708C8: ret
	return;
}

void sub_2708D0(X86Context& ctx, uint8_t* base) {
	// 0x2708D0: movss xmm0, dword ptr [0x0056857C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56857Cu);
	// 0x2708D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2708E0: movss [0x00568538], xmm0
	X86_MEM_WRITE_u32(base, 0x568538u, ctx.xmm[0].u32[0]);
	// 0x2708E8: ret
	return;
}

void sub_2708F0(X86Context& ctx, uint8_t* base) {
	// 0x2708F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2708F8: movss [0x00568524], xmm0
	X86_MEM_WRITE_u32(base, 0x568524u, ctx.xmm[0].u32[0]);
	// 0x270900: ret
	return;
}

void sub_270910(X86Context& ctx, uint8_t* base) {
	// 0x270910: movss xmm0, dword ptr [0x00568538]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568538u);
	// 0x270918: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x270920: movss [0x0056856C], xmm0
	X86_MEM_WRITE_u32(base, 0x56856Cu, ctx.xmm[0].u32[0]);
	// 0x270928: ret
	return;
}

void sub_270930(X86Context& ctx, uint8_t* base) {
	// 0x270930: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x270938: movss [0x00568540], xmm0
	X86_MEM_WRITE_u32(base, 0x568540u, ctx.xmm[0].u32[0]);
	// 0x270940: ret
	return;
}

void sub_270950(X86Context& ctx, uint8_t* base) {
	// 0x270950: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x270958: movss [0x00568518], xmm0
	X86_MEM_WRITE_u32(base, 0x568518u, ctx.xmm[0].u32[0]);
	// 0x270960: ret
	return;
}

void sub_270970(X86Context& ctx, uint8_t* base) {
	// 0x270970: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x270978: movss [0x005685F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5685F8u, ctx.xmm[0].u32[0]);
	// 0x270980: ret
	return;
}

void sub_270990(X86Context& ctx, uint8_t* base) {
	// 0x270990: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x270998: movss [0x00568614], xmm0
	X86_MEM_WRITE_u32(base, 0x568614u, ctx.xmm[0].u32[0]);
	// 0x2709A0: ret
	return;
}

void sub_2709B0(X86Context& ctx, uint8_t* base) {
	// 0x2709B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2709B8: movss [0x005685E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5685E8u, ctx.xmm[0].u32[0]);
	// 0x2709C0: ret
	return;
}

void sub_2709D0(X86Context& ctx, uint8_t* base) {
	// 0x2709D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2709D8: movss [0x0056859C], xmm0
	X86_MEM_WRITE_u32(base, 0x56859Cu, ctx.xmm[0].u32[0]);
	// 0x2709E0: ret
	return;
}

void sub_2709F0(X86Context& ctx, uint8_t* base) {
	// 0x2709F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2709F8: movss [0x005685FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5685FCu, ctx.xmm[0].u32[0]);
	// 0x270A00: ret
	return;
}

void sub_270A10(X86Context& ctx, uint8_t* base) {
	// 0x270A10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x270A18: movss [0x005685B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5685B8u, ctx.xmm[0].u32[0]);
	// 0x270A20: ret
	return;
}

void sub_270A30(X86Context& ctx, uint8_t* base) {
	// 0x270A30: movss xmm0, dword ptr [0x005685FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685FCu);
	// 0x270A38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x270A40: movss [0x00568634], xmm0
	X86_MEM_WRITE_u32(base, 0x568634u, ctx.xmm[0].u32[0]);
	// 0x270A48: ret
	return;
}

void sub_270A50(X86Context& ctx, uint8_t* base) {
	// 0x270A50: movss xmm0, dword ptr [0x005685B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685B8u);
	// 0x270A58: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x270A60: movss [0x0056861C], xmm0
	X86_MEM_WRITE_u32(base, 0x56861Cu, ctx.xmm[0].u32[0]);
	// 0x270A68: ret
	return;
}

void sub_270A70(X86Context& ctx, uint8_t* base) {
	// 0x270A70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x270A78: movss [0x0056864C], xmm0
	X86_MEM_WRITE_u32(base, 0x56864Cu, ctx.xmm[0].u32[0]);
	// 0x270A80: ret
	return;
}

void sub_270A90(X86Context& ctx, uint8_t* base) {
	// 0x270A90: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x270A98: movss [0x00568638], xmm0
	X86_MEM_WRITE_u32(base, 0x568638u, ctx.xmm[0].u32[0]);
	// 0x270AA0: ret
	return;
}

void sub_270AB0(X86Context& ctx, uint8_t* base) {
	// 0x270AB0: movss xmm0, dword ptr [0x00568638]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568638u);
	// 0x270AB8: movss [0x00568648], xmm0
	X86_MEM_WRITE_u32(base, 0x568648u, ctx.xmm[0].u32[0]);
	// 0x270AC0: ret
	return;
}

void sub_270AD0(X86Context& ctx, uint8_t* base) {
	// 0x270AD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x270AD8: movss [0x005685A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5685A4u, ctx.xmm[0].u32[0]);
	// 0x270AE0: ret
	return;
}

void sub_270AF0(X86Context& ctx, uint8_t* base) {
	// 0x270AF0: movss xmm0, dword ptr [0x005685B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685B8u);
	// 0x270AF8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x270B00: movss [0x00568640], xmm0
	X86_MEM_WRITE_u32(base, 0x568640u, ctx.xmm[0].u32[0]);
	// 0x270B08: ret
	return;
}

void sub_270B10(X86Context& ctx, uint8_t* base) {
	// 0x270B10: movss xmm0, dword ptr [0x005685B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685B8u);
	// 0x270B18: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x270B20: movss [0x005685E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5685E4u, ctx.xmm[0].u32[0]);
	// 0x270B28: ret
	return;
}

void sub_270B30(X86Context& ctx, uint8_t* base) {
	// 0x270B30: movss xmm0, dword ptr [0x005685B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685B8u);
	// 0x270B38: subss xmm0, [0x005685E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5685E4u);
	// 0x270B40: movss [0x005685C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5685C0u, ctx.xmm[0].u32[0]);
	// 0x270B48: ret
	return;
}

void sub_270B50(X86Context& ctx, uint8_t* base) {
	// 0x270B50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x270B58: movss [0x00568610], xmm0
	X86_MEM_WRITE_u32(base, 0x568610u, ctx.xmm[0].u32[0]);
	// 0x270B60: ret
	return;
}

void sub_270B70(X86Context& ctx, uint8_t* base) {
	// 0x270B70: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x270B78: movss [0x005685BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5685BCu, ctx.xmm[0].u32[0]);
	// 0x270B80: ret
	return;
}

void sub_270B90(X86Context& ctx, uint8_t* base) {
	// 0x270B90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x270B98: movss [0x005685D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5685D0u, ctx.xmm[0].u32[0]);
	// 0x270BA0: ret
	return;
}

void sub_270BB0(X86Context& ctx, uint8_t* base) {
	// 0x270BB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x270BB8: movss [0x00568628], xmm0
	X86_MEM_WRITE_u32(base, 0x568628u, ctx.xmm[0].u32[0]);
	// 0x270BC0: ret
	return;
}

void sub_270BD0(X86Context& ctx, uint8_t* base) {
	// 0x270BD0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x270BD8: movss [0x0056860C], xmm0
	X86_MEM_WRITE_u32(base, 0x56860Cu, ctx.xmm[0].u32[0]);
	// 0x270BE0: ret
	return;
}

void sub_270BF0(X86Context& ctx, uint8_t* base) {
	// 0x270BF0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x270BF8: movss [0x005685B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5685B4u, ctx.xmm[0].u32[0]);
	// 0x270C00: ret
	return;
}

void sub_270C10(X86Context& ctx, uint8_t* base) {
	// 0x270C10: movss xmm0, dword ptr [0x005685D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685D0u);
	// 0x270C18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x270C20: movss [0x005685A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5685A8u, ctx.xmm[0].u32[0]);
	// 0x270C28: ret
	return;
}

void sub_270C30(X86Context& ctx, uint8_t* base) {
	// 0x270C30: movss xmm0, dword ptr [0x00568628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568628u);
	// 0x270C38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x270C40: movss [0x005685F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5685F0u, ctx.xmm[0].u32[0]);
	// 0x270C48: ret
	return;
}

void sub_270C50(X86Context& ctx, uint8_t* base) {
	// 0x270C50: movss xmm0, dword ptr [0x005685A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685A8u);
	// 0x270C58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x270C60: movss [0x00568604], xmm0
	X86_MEM_WRITE_u32(base, 0x568604u, ctx.xmm[0].u32[0]);
	// 0x270C68: ret
	return;
}

void sub_270C70(X86Context& ctx, uint8_t* base) {
	// 0x270C70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x270C78: movss [0x005685A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5685A0u, ctx.xmm[0].u32[0]);
	// 0x270C80: ret
	return;
}

void sub_270C90(X86Context& ctx, uint8_t* base) {
	// 0x270C90: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x270C98: movss [0x005685D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5685D4u, ctx.xmm[0].u32[0]);
	// 0x270CA0: ret
	return;
}

void sub_270CB0(X86Context& ctx, uint8_t* base) {
	// 0x270CB0: movss xmm0, dword ptr [0x005685D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685D0u);
	// 0x270CB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x270CC0: movss [0x005685E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5685E0u, ctx.xmm[0].u32[0]);
	// 0x270CC8: ret
	return;
}

void sub_270CD0(X86Context& ctx, uint8_t* base) {
	// 0x270CD0: movss xmm0, dword ptr [0x00568628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568628u);
	// 0x270CD8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x270CE0: movss [0x0056862C], xmm0
	X86_MEM_WRITE_u32(base, 0x56862Cu, ctx.xmm[0].u32[0]);
	// 0x270CE8: ret
	return;
}

void sub_270CF0(X86Context& ctx, uint8_t* base) {
	// 0x270CF0: movss xmm0, dword ptr [0x005685E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685E0u);
	// 0x270CF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270D00: movss [0x00568618], xmm0
	X86_MEM_WRITE_u32(base, 0x568618u, ctx.xmm[0].u32[0]);
	// 0x270D08: ret
	return;
}

void sub_270D10(X86Context& ctx, uint8_t* base) {
	// 0x270D10: movss xmm0, dword ptr [0x0056862C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56862Cu);
	// 0x270D18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270D20: movss [0x0056863C], xmm0
	X86_MEM_WRITE_u32(base, 0x56863Cu, ctx.xmm[0].u32[0]);
	// 0x270D28: ret
	return;
}

void sub_270D30(X86Context& ctx, uint8_t* base) {
	// 0x270D30: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x270D38: movss [0x005685AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5685ACu, ctx.xmm[0].u32[0]);
	// 0x270D40: ret
	return;
}

void sub_270D50(X86Context& ctx, uint8_t* base) {
	// 0x270D50: movss xmm0, dword ptr [0x005685D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685D0u);
	// 0x270D58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270D60: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x270D68: movss [0x00568624], xmm0
	X86_MEM_WRITE_u32(base, 0x568624u, ctx.xmm[0].u32[0]);
	// 0x270D70: ret
	return;
}

void sub_270D80(X86Context& ctx, uint8_t* base) {
	// 0x270D80: movss xmm0, dword ptr [0x00568628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568628u);
	// 0x270D88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270D90: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x270D98: movss [0x005685C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5685C4u, ctx.xmm[0].u32[0]);
	// 0x270DA0: ret
	return;
}

void sub_270DB0(X86Context& ctx, uint8_t* base) {
	// 0x270DB0: movss xmm0, dword ptr [0x005685D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685D0u);
	// 0x270DB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270DC0: movss [0x005685C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5685C8u, ctx.xmm[0].u32[0]);
	// 0x270DC8: ret
	return;
}

void sub_270DD0(X86Context& ctx, uint8_t* base) {
	// 0x270DD0: movss xmm0, dword ptr [0x00568628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568628u);
	// 0x270DD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x270DE0: movss [0x00568630], xmm0
	X86_MEM_WRITE_u32(base, 0x568630u, ctx.xmm[0].u32[0]);
	// 0x270DE8: ret
	return;
}

void sub_270DF0(X86Context& ctx, uint8_t* base) {
	// 0x270DF0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x270DF8: movss [0x005685B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5685B0u, ctx.xmm[0].u32[0]);
	// 0x270E00: ret
	return;
}

void sub_270E10(X86Context& ctx, uint8_t* base) {
	// 0x270E10: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x270E18: movss [0x005685DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5685DCu, ctx.xmm[0].u32[0]);
	// 0x270E20: ret
	return;
}

void sub_270E30(X86Context& ctx, uint8_t* base) {
	// 0x270E30: movss xmm0, dword ptr [0x005685B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685B0u);
	// 0x270E38: movss [0x00568644], xmm0
	X86_MEM_WRITE_u32(base, 0x568644u, ctx.xmm[0].u32[0]);
	// 0x270E40: ret
	return;
}

void sub_270E50(X86Context& ctx, uint8_t* base) {
	// 0x270E50: movss xmm0, dword ptr [0x00568628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568628u);
	// 0x270E58: subss xmm0, [0x005685B0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5685B0u);
	// 0x270E60: movss [0x00568608], xmm0
	X86_MEM_WRITE_u32(base, 0x568608u, ctx.xmm[0].u32[0]);
	// 0x270E68: ret
	return;
}

void sub_270E70(X86Context& ctx, uint8_t* base) {
	// 0x270E70: movss xmm0, dword ptr [0x00568608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568608u);
	// 0x270E78: subss xmm0, [0x005685DC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5685DCu);
	// 0x270E80: movss [0x00568600], xmm0
	X86_MEM_WRITE_u32(base, 0x568600u, ctx.xmm[0].u32[0]);
	// 0x270E88: ret
	return;
}

void sub_270E90(X86Context& ctx, uint8_t* base) {
	// 0x270E90: movss xmm0, dword ptr [0x00568630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568630u);
	// 0x270E98: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x270EA0: movss [0x005685EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5685ECu, ctx.xmm[0].u32[0]);
	// 0x270EA8: ret
	return;
}

void sub_270EB0(X86Context& ctx, uint8_t* base) {
	// 0x270EB0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x270EB8: movss [0x005685D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5685D8u, ctx.xmm[0].u32[0]);
	// 0x270EC0: ret
	return;
}

void sub_270ED0(X86Context& ctx, uint8_t* base) {
	// 0x270ED0: movss xmm0, dword ptr [0x005685EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5685ECu);
	// 0x270ED8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x270EE0: movss [0x00568620], xmm0
	X86_MEM_WRITE_u32(base, 0x568620u, ctx.xmm[0].u32[0]);
	// 0x270EE8: ret
	return;
}

void sub_270EF0(X86Context& ctx, uint8_t* base) {
	// 0x270EF0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x270EF8: movss [0x005685F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5685F4u, ctx.xmm[0].u32[0]);
	// 0x270F00: ret
	return;
}

void sub_270F10(X86Context& ctx, uint8_t* base) {
	// 0x270F10: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x270F18: movss [0x005685CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5685CCu, ctx.xmm[0].u32[0]);
	// 0x270F20: ret
	return;
}

void sub_270F30(X86Context& ctx, uint8_t* base) {
	// 0x270F30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x270F38: movss [0x005686AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5686ACu, ctx.xmm[0].u32[0]);
	// 0x270F40: ret
	return;
}

void sub_270F50(X86Context& ctx, uint8_t* base) {
	// 0x270F50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x270F58: movss [0x005686C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5686C8u, ctx.xmm[0].u32[0]);
	// 0x270F60: ret
	return;
}

void sub_270F70(X86Context& ctx, uint8_t* base) {
	// 0x270F70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x270F78: movss [0x0056869C], xmm0
	X86_MEM_WRITE_u32(base, 0x56869Cu, ctx.xmm[0].u32[0]);
	// 0x270F80: ret
	return;
}

void sub_270F90(X86Context& ctx, uint8_t* base) {
	// 0x270F90: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x270F98: movss [0x00568650], xmm0
	X86_MEM_WRITE_u32(base, 0x568650u, ctx.xmm[0].u32[0]);
	// 0x270FA0: ret
	return;
}

void sub_270FB0(X86Context& ctx, uint8_t* base) {
	// 0x270FB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x270FB8: movss [0x005686B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5686B0u, ctx.xmm[0].u32[0]);
	// 0x270FC0: ret
	return;
}

void sub_270FD0(X86Context& ctx, uint8_t* base) {
	// 0x270FD0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x270FD8: movss [0x0056866C], xmm0
	X86_MEM_WRITE_u32(base, 0x56866Cu, ctx.xmm[0].u32[0]);
	// 0x270FE0: ret
	return;
}

void sub_270FF0(X86Context& ctx, uint8_t* base) {
	// 0x270FF0: movss xmm0, dword ptr [0x005686B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686B0u);
	// 0x270FF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x271000: movss [0x005686E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5686E8u, ctx.xmm[0].u32[0]);
	// 0x271008: ret
	return;
}

void sub_271010(X86Context& ctx, uint8_t* base) {
	// 0x271010: movss xmm0, dword ptr [0x0056866C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56866Cu);
	// 0x271018: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x271020: movss [0x005686D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5686D0u, ctx.xmm[0].u32[0]);
	// 0x271028: ret
	return;
}

void sub_271030(X86Context& ctx, uint8_t* base) {
	// 0x271030: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x271038: movss [0x00568700], xmm0
	X86_MEM_WRITE_u32(base, 0x568700u, ctx.xmm[0].u32[0]);
	// 0x271040: ret
	return;
}

void sub_271050(X86Context& ctx, uint8_t* base) {
	// 0x271050: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x271058: movss [0x005686EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5686ECu, ctx.xmm[0].u32[0]);
	// 0x271060: ret
	return;
}

void sub_271070(X86Context& ctx, uint8_t* base) {
	// 0x271070: movss xmm0, dword ptr [0x005686EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5686ECu);
	// 0x271078: movss [0x005686FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5686FCu, ctx.xmm[0].u32[0]);
	// 0x271080: ret
	return;
}

void sub_271090(X86Context& ctx, uint8_t* base) {
	// 0x271090: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x271098: movss [0x00568658], xmm0
	X86_MEM_WRITE_u32(base, 0x568658u, ctx.xmm[0].u32[0]);
	// 0x2710A0: ret
	return;
}

void sub_2710B0(X86Context& ctx, uint8_t* base) {
	// 0x2710B0: movss xmm0, dword ptr [0x0056866C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56866Cu);
	// 0x2710B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2710C0: movss [0x005686F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5686F4u, ctx.xmm[0].u32[0]);
	// 0x2710C8: ret
	return;
}

void sub_2710D0(X86Context& ctx, uint8_t* base) {
	// 0x2710D0: movss xmm0, dword ptr [0x0056866C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56866Cu);
	// 0x2710D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2710E0: movss [0x00568698], xmm0
	X86_MEM_WRITE_u32(base, 0x568698u, ctx.xmm[0].u32[0]);
	// 0x2710E8: ret
	return;
}

void sub_2710F0(X86Context& ctx, uint8_t* base) {
	// 0x2710F0: movss xmm0, dword ptr [0x0056866C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56866Cu);
	// 0x2710F8: subss xmm0, [0x00568698]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568698u);
	// 0x271100: movss [0x00568674], xmm0
	X86_MEM_WRITE_u32(base, 0x568674u, ctx.xmm[0].u32[0]);
	// 0x271108: ret
	return;
}

void sub_271110(X86Context& ctx, uint8_t* base) {
	// 0x271110: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x271118: movss [0x005686C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5686C4u, ctx.xmm[0].u32[0]);
	// 0x271120: ret
	return;
}

void sub_271130(X86Context& ctx, uint8_t* base) {
	// 0x271130: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x271138: movss [0x00568670], xmm0
	X86_MEM_WRITE_u32(base, 0x568670u, ctx.xmm[0].u32[0]);
	// 0x271140: ret
	return;
}

void sub_271150(X86Context& ctx, uint8_t* base) {
	// 0x271150: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x271158: movss [0x00568684], xmm0
	X86_MEM_WRITE_u32(base, 0x568684u, ctx.xmm[0].u32[0]);
	// 0x271160: ret
	return;
}

void sub_271170(X86Context& ctx, uint8_t* base) {
	// 0x271170: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x271178: movss [0x005686DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5686DCu, ctx.xmm[0].u32[0]);
	// 0x271180: ret
	return;
}

void sub_271190(X86Context& ctx, uint8_t* base) {
	// 0x271190: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x271198: movss [0x005686C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5686C0u, ctx.xmm[0].u32[0]);
	// 0x2711A0: ret
	return;
}

void sub_2711B0(X86Context& ctx, uint8_t* base) {
	// 0x2711B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2711B8: movss [0x00568668], xmm0
	X86_MEM_WRITE_u32(base, 0x568668u, ctx.xmm[0].u32[0]);
	// 0x2711C0: ret
	return;
}

void sub_2711D0(X86Context& ctx, uint8_t* base) {
	// 0x2711D0: movss xmm0, dword ptr [0x00568684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568684u);
	// 0x2711D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2711E0: movss [0x0056865C], xmm0
	X86_MEM_WRITE_u32(base, 0x56865Cu, ctx.xmm[0].u32[0]);
	// 0x2711E8: ret
	return;
}

