#include "x86_recomp_shared.h"

void sub_29C1A0(X86Context& ctx, uint8_t* base) {
	// 0x29C1A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29C1A8: movss [0x0056F158], xmm0
	X86_MEM_WRITE_u32(base, 0x56F158u, ctx.xmm[0].u32[0]);
	// 0x29C1B0: ret
	return;
}

void sub_29C1C0(X86Context& ctx, uint8_t* base) {
	// 0x29C1C0: movss xmm0, dword ptr [0x0056F154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F154u);
	// 0x29C1C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29C1D0: movss [0x0056F164], xmm0
	X86_MEM_WRITE_u32(base, 0x56F164u, ctx.xmm[0].u32[0]);
	// 0x29C1D8: ret
	return;
}

void sub_29C1E0(X86Context& ctx, uint8_t* base) {
	// 0x29C1E0: movss xmm0, dword ptr [0x0056F1A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1A8u);
	// 0x29C1E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29C1F0: movss [0x0056F1B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1B0u, ctx.xmm[0].u32[0]);
	// 0x29C1F8: ret
	return;
}

void sub_29C200(X86Context& ctx, uint8_t* base) {
	// 0x29C200: movss xmm0, dword ptr [0x0056F164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F164u);
	// 0x29C208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C210: movss [0x0056F198], xmm0
	X86_MEM_WRITE_u32(base, 0x56F198u, ctx.xmm[0].u32[0]);
	// 0x29C218: ret
	return;
}

void sub_29C220(X86Context& ctx, uint8_t* base) {
	// 0x29C220: movss xmm0, dword ptr [0x0056F1B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1B0u);
	// 0x29C228: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C230: movss [0x0056F1C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1C0u, ctx.xmm[0].u32[0]);
	// 0x29C238: ret
	return;
}

void sub_29C240(X86Context& ctx, uint8_t* base) {
	// 0x29C240: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29C248: movss [0x0056F130], xmm0
	X86_MEM_WRITE_u32(base, 0x56F130u, ctx.xmm[0].u32[0]);
	// 0x29C250: ret
	return;
}

void sub_29C260(X86Context& ctx, uint8_t* base) {
	// 0x29C260: movss xmm0, dword ptr [0x0056F154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F154u);
	// 0x29C268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C270: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29C278: movss [0x0056F1A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1A4u, ctx.xmm[0].u32[0]);
	// 0x29C280: ret
	return;
}

void sub_29C290(X86Context& ctx, uint8_t* base) {
	// 0x29C290: movss xmm0, dword ptr [0x0056F1A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1A8u);
	// 0x29C298: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C2A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29C2A8: movss [0x0056F14C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F14Cu, ctx.xmm[0].u32[0]);
	// 0x29C2B0: ret
	return;
}

void sub_29C2C0(X86Context& ctx, uint8_t* base) {
	// 0x29C2C0: movss xmm0, dword ptr [0x0056F154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F154u);
	// 0x29C2C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C2D0: movss [0x0056F150], xmm0
	X86_MEM_WRITE_u32(base, 0x56F150u, ctx.xmm[0].u32[0]);
	// 0x29C2D8: ret
	return;
}

void sub_29C2E0(X86Context& ctx, uint8_t* base) {
	// 0x29C2E0: movss xmm0, dword ptr [0x0056F1A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1A8u);
	// 0x29C2E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C2F0: movss [0x0056F1B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1B4u, ctx.xmm[0].u32[0]);
	// 0x29C2F8: ret
	return;
}

void sub_29C300(X86Context& ctx, uint8_t* base) {
	// 0x29C300: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29C308: movss [0x0056F134], xmm0
	X86_MEM_WRITE_u32(base, 0x56F134u, ctx.xmm[0].u32[0]);
	// 0x29C310: ret
	return;
}

void sub_29C320(X86Context& ctx, uint8_t* base) {
	// 0x29C320: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29C328: movss [0x0056F160], xmm0
	X86_MEM_WRITE_u32(base, 0x56F160u, ctx.xmm[0].u32[0]);
	// 0x29C330: ret
	return;
}

void sub_29C340(X86Context& ctx, uint8_t* base) {
	// 0x29C340: movss xmm0, dword ptr [0x0056F134]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F134u);
	// 0x29C348: movss [0x0056F1C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1C8u, ctx.xmm[0].u32[0]);
	// 0x29C350: ret
	return;
}

void sub_29C360(X86Context& ctx, uint8_t* base) {
	// 0x29C360: movss xmm0, dword ptr [0x0056F1A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1A8u);
	// 0x29C368: subss xmm0, [0x0056F134]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F134u);
	// 0x29C370: movss [0x0056F188], xmm0
	X86_MEM_WRITE_u32(base, 0x56F188u, ctx.xmm[0].u32[0]);
	// 0x29C378: ret
	return;
}

void sub_29C380(X86Context& ctx, uint8_t* base) {
	// 0x29C380: movss xmm0, dword ptr [0x0056F188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F188u);
	// 0x29C388: subss xmm0, [0x0056F160]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F160u);
	// 0x29C390: movss [0x0056F180], xmm0
	X86_MEM_WRITE_u32(base, 0x56F180u, ctx.xmm[0].u32[0]);
	// 0x29C398: ret
	return;
}

void sub_29C3A0(X86Context& ctx, uint8_t* base) {
	// 0x29C3A0: movss xmm0, dword ptr [0x0056F1B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1B4u);
	// 0x29C3A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29C3B0: movss [0x0056F170], xmm0
	X86_MEM_WRITE_u32(base, 0x56F170u, ctx.xmm[0].u32[0]);
	// 0x29C3B8: ret
	return;
}

void sub_29C3C0(X86Context& ctx, uint8_t* base) {
	// 0x29C3C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29C3C8: movss [0x0056F15C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F15Cu, ctx.xmm[0].u32[0]);
	// 0x29C3D0: ret
	return;
}

void sub_29C3E0(X86Context& ctx, uint8_t* base) {
	// 0x29C3E0: movss xmm0, dword ptr [0x0056F170]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F170u);
	// 0x29C3E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29C3F0: movss [0x0056F1A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1A0u, ctx.xmm[0].u32[0]);
	// 0x29C3F8: ret
	return;
}

void sub_29C400(X86Context& ctx, uint8_t* base) {
	// 0x29C400: movss xmm0, dword ptr [0x0056F18C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F18Cu);
	// 0x29C408: movss [0x0056F1AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1ACu, ctx.xmm[0].u32[0]);
	// 0x29C410: ret
	return;
}

void sub_29C420(X86Context& ctx, uint8_t* base) {
	// 0x29C420: movss xmm0, dword ptr [0x003B1904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1904u);
	// 0x29C428: movss [0x0056F140], xmm0
	X86_MEM_WRITE_u32(base, 0x56F140u, ctx.xmm[0].u32[0]);
	// 0x29C430: ret
	return;
}

void sub_29C440(X86Context& ctx, uint8_t* base) {
	// 0x29C440: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29C448: movss [0x0056F238], xmm0
	X86_MEM_WRITE_u32(base, 0x56F238u, ctx.xmm[0].u32[0]);
	// 0x29C450: ret
	return;
}

void sub_29C460(X86Context& ctx, uint8_t* base) {
	// 0x29C460: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29C468: movss [0x0056F254], xmm0
	X86_MEM_WRITE_u32(base, 0x56F254u, ctx.xmm[0].u32[0]);
	// 0x29C470: ret
	return;
}

void sub_29C480(X86Context& ctx, uint8_t* base) {
	// 0x29C480: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29C488: movss [0x0056F224], xmm0
	X86_MEM_WRITE_u32(base, 0x56F224u, ctx.xmm[0].u32[0]);
	// 0x29C490: ret
	return;
}

void sub_29C4A0(X86Context& ctx, uint8_t* base) {
	// 0x29C4A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29C4A8: movss [0x0056F1D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1D4u, ctx.xmm[0].u32[0]);
	// 0x29C4B0: ret
	return;
}

void sub_29C4C0(X86Context& ctx, uint8_t* base) {
	// 0x29C4C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29C4C8: movss [0x0056F23C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F23Cu, ctx.xmm[0].u32[0]);
	// 0x29C4D0: ret
	return;
}

void sub_29C4E0(X86Context& ctx, uint8_t* base) {
	// 0x29C4E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29C4E8: movss [0x0056F1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1F0u, ctx.xmm[0].u32[0]);
	// 0x29C4F0: ret
	return;
}

void sub_29C500(X86Context& ctx, uint8_t* base) {
	// 0x29C500: movss xmm0, dword ptr [0x0056F23C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F23Cu);
	// 0x29C508: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29C510: movss [0x0056F274], xmm0
	X86_MEM_WRITE_u32(base, 0x56F274u, ctx.xmm[0].u32[0]);
	// 0x29C518: ret
	return;
}

void sub_29C520(X86Context& ctx, uint8_t* base) {
	// 0x29C520: movss xmm0, dword ptr [0x0056F1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1F0u);
	// 0x29C528: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29C530: movss [0x0056F25C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F25Cu, ctx.xmm[0].u32[0]);
	// 0x29C538: ret
	return;
}

void sub_29C540(X86Context& ctx, uint8_t* base) {
	// 0x29C540: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29C548: movss [0x0056F28C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F28Cu, ctx.xmm[0].u32[0]);
	// 0x29C550: ret
	return;
}

void sub_29C560(X86Context& ctx, uint8_t* base) {
	// 0x29C560: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29C568: movss [0x0056F278], xmm0
	X86_MEM_WRITE_u32(base, 0x56F278u, ctx.xmm[0].u32[0]);
	// 0x29C570: ret
	return;
}

void sub_29C580(X86Context& ctx, uint8_t* base) {
	// 0x29C580: movss xmm0, dword ptr [0x0056F278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F278u);
	// 0x29C588: movss [0x0056F288], xmm0
	X86_MEM_WRITE_u32(base, 0x56F288u, ctx.xmm[0].u32[0]);
	// 0x29C590: ret
	return;
}

void sub_29C5A0(X86Context& ctx, uint8_t* base) {
	// 0x29C5A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29C5A8: movss [0x0056F1DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1DCu, ctx.xmm[0].u32[0]);
	// 0x29C5B0: ret
	return;
}

void sub_29C5C0(X86Context& ctx, uint8_t* base) {
	// 0x29C5C0: movss xmm0, dword ptr [0x0056F1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1F0u);
	// 0x29C5C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29C5D0: movss [0x0056F280], xmm0
	X86_MEM_WRITE_u32(base, 0x56F280u, ctx.xmm[0].u32[0]);
	// 0x29C5D8: ret
	return;
}

void sub_29C5E0(X86Context& ctx, uint8_t* base) {
	// 0x29C5E0: movss xmm0, dword ptr [0x0056F1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1F0u);
	// 0x29C5E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29C5F0: movss [0x0056F220], xmm0
	X86_MEM_WRITE_u32(base, 0x56F220u, ctx.xmm[0].u32[0]);
	// 0x29C5F8: ret
	return;
}

void sub_29C600(X86Context& ctx, uint8_t* base) {
	// 0x29C600: movss xmm0, dword ptr [0x0056F1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1F0u);
	// 0x29C608: subss xmm0, [0x0056F220]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F220u);
	// 0x29C610: movss [0x0056F1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1FCu, ctx.xmm[0].u32[0]);
	// 0x29C618: ret
	return;
}

void sub_29C620(X86Context& ctx, uint8_t* base) {
	// 0x29C620: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29C628: movss [0x0056F250], xmm0
	X86_MEM_WRITE_u32(base, 0x56F250u, ctx.xmm[0].u32[0]);
	// 0x29C630: ret
	return;
}

void sub_29C640(X86Context& ctx, uint8_t* base) {
	// 0x29C640: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29C648: movss [0x0056F1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1F8u, ctx.xmm[0].u32[0]);
	// 0x29C650: ret
	return;
}

void sub_29C660(X86Context& ctx, uint8_t* base) {
	// 0x29C660: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29C668: movss [0x0056F20C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F20Cu, ctx.xmm[0].u32[0]);
	// 0x29C670: ret
	return;
}

void sub_29C680(X86Context& ctx, uint8_t* base) {
	// 0x29C680: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29C688: movss [0x0056F268], xmm0
	X86_MEM_WRITE_u32(base, 0x56F268u, ctx.xmm[0].u32[0]);
	// 0x29C690: ret
	return;
}

void sub_29C6A0(X86Context& ctx, uint8_t* base) {
	// 0x29C6A0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29C6A8: movss [0x0056F24C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F24Cu, ctx.xmm[0].u32[0]);
	// 0x29C6B0: ret
	return;
}

void sub_29C6C0(X86Context& ctx, uint8_t* base) {
	// 0x29C6C0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29C6C8: movss [0x0056F1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1ECu, ctx.xmm[0].u32[0]);
	// 0x29C6D0: ret
	return;
}

void sub_29C6E0(X86Context& ctx, uint8_t* base) {
	// 0x29C6E0: movss xmm0, dword ptr [0x0056F20C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F20Cu);
	// 0x29C6E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29C6F0: movss [0x0056F1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1E0u, ctx.xmm[0].u32[0]);
	// 0x29C6F8: ret
	return;
}

void sub_29C700(X86Context& ctx, uint8_t* base) {
	// 0x29C700: movss xmm0, dword ptr [0x0056F268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F268u);
	// 0x29C708: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29C710: movss [0x0056F234], xmm0
	X86_MEM_WRITE_u32(base, 0x56F234u, ctx.xmm[0].u32[0]);
	// 0x29C718: ret
	return;
}

void sub_29C720(X86Context& ctx, uint8_t* base) {
	// 0x29C720: movss xmm0, dword ptr [0x0056F1E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1E0u);
	// 0x29C728: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29C730: movss [0x0056F244], xmm0
	X86_MEM_WRITE_u32(base, 0x56F244u, ctx.xmm[0].u32[0]);
	// 0x29C738: ret
	return;
}

void sub_29C740(X86Context& ctx, uint8_t* base) {
	// 0x29C740: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29C748: movss [0x0056F1D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1D8u, ctx.xmm[0].u32[0]);
	// 0x29C750: ret
	return;
}

void sub_29C760(X86Context& ctx, uint8_t* base) {
	// 0x29C760: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29C768: movss [0x0056F210], xmm0
	X86_MEM_WRITE_u32(base, 0x56F210u, ctx.xmm[0].u32[0]);
	// 0x29C770: ret
	return;
}

void sub_29C780(X86Context& ctx, uint8_t* base) {
	// 0x29C780: movss xmm0, dword ptr [0x0056F20C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F20Cu);
	// 0x29C788: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29C790: movss [0x0056F21C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F21Cu, ctx.xmm[0].u32[0]);
	// 0x29C798: ret
	return;
}

void sub_29C7A0(X86Context& ctx, uint8_t* base) {
	// 0x29C7A0: movss xmm0, dword ptr [0x0056F268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F268u);
	// 0x29C7A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29C7B0: movss [0x0056F26C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F26Cu, ctx.xmm[0].u32[0]);
	// 0x29C7B8: ret
	return;
}

void sub_29C7C0(X86Context& ctx, uint8_t* base) {
	// 0x29C7C0: movss xmm0, dword ptr [0x0056F21C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F21Cu);
	// 0x29C7C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C7D0: movss [0x0056F258], xmm0
	X86_MEM_WRITE_u32(base, 0x56F258u, ctx.xmm[0].u32[0]);
	// 0x29C7D8: ret
	return;
}

void sub_29C7E0(X86Context& ctx, uint8_t* base) {
	// 0x29C7E0: movss xmm0, dword ptr [0x0056F26C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F26Cu);
	// 0x29C7E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C7F0: movss [0x0056F27C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F27Cu, ctx.xmm[0].u32[0]);
	// 0x29C7F8: ret
	return;
}

void sub_29C800(X86Context& ctx, uint8_t* base) {
	// 0x29C800: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29C808: movss [0x0056F1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1E4u, ctx.xmm[0].u32[0]);
	// 0x29C810: ret
	return;
}

void sub_29C820(X86Context& ctx, uint8_t* base) {
	// 0x29C820: movss xmm0, dword ptr [0x0056F20C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F20Cu);
	// 0x29C828: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C830: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29C838: movss [0x0056F264], xmm0
	X86_MEM_WRITE_u32(base, 0x56F264u, ctx.xmm[0].u32[0]);
	// 0x29C840: ret
	return;
}

void sub_29C850(X86Context& ctx, uint8_t* base) {
	// 0x29C850: movss xmm0, dword ptr [0x0056F268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F268u);
	// 0x29C858: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C860: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29C868: movss [0x0056F200], xmm0
	X86_MEM_WRITE_u32(base, 0x56F200u, ctx.xmm[0].u32[0]);
	// 0x29C870: ret
	return;
}

void sub_29C880(X86Context& ctx, uint8_t* base) {
	// 0x29C880: movss xmm0, dword ptr [0x0056F20C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F20Cu);
	// 0x29C888: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C890: movss [0x0056F204], xmm0
	X86_MEM_WRITE_u32(base, 0x56F204u, ctx.xmm[0].u32[0]);
	// 0x29C898: ret
	return;
}

void sub_29C8A0(X86Context& ctx, uint8_t* base) {
	// 0x29C8A0: movss xmm0, dword ptr [0x0056F268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F268u);
	// 0x29C8A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29C8B0: movss [0x0056F270], xmm0
	X86_MEM_WRITE_u32(base, 0x56F270u, ctx.xmm[0].u32[0]);
	// 0x29C8B8: ret
	return;
}

void sub_29C8C0(X86Context& ctx, uint8_t* base) {
	// 0x29C8C0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29C8C8: movss [0x0056F1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1E8u, ctx.xmm[0].u32[0]);
	// 0x29C8D0: ret
	return;
}

void sub_29C8E0(X86Context& ctx, uint8_t* base) {
	// 0x29C8E0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29C8E8: movss [0x0056F218], xmm0
	X86_MEM_WRITE_u32(base, 0x56F218u, ctx.xmm[0].u32[0]);
	// 0x29C8F0: ret
	return;
}

void sub_29C900(X86Context& ctx, uint8_t* base) {
	// 0x29C900: movss xmm0, dword ptr [0x0056F1E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1E8u);
	// 0x29C908: movss [0x0056F284], xmm0
	X86_MEM_WRITE_u32(base, 0x56F284u, ctx.xmm[0].u32[0]);
	// 0x29C910: ret
	return;
}

void sub_29C920(X86Context& ctx, uint8_t* base) {
	// 0x29C920: movss xmm0, dword ptr [0x0056F268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F268u);
	// 0x29C928: subss xmm0, [0x0056F1E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F1E8u);
	// 0x29C930: movss [0x0056F248], xmm0
	X86_MEM_WRITE_u32(base, 0x56F248u, ctx.xmm[0].u32[0]);
	// 0x29C938: ret
	return;
}

void sub_29C940(X86Context& ctx, uint8_t* base) {
	// 0x29C940: movss xmm0, dword ptr [0x0056F248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F248u);
	// 0x29C948: subss xmm0, [0x0056F218]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F218u);
	// 0x29C950: movss [0x0056F240], xmm0
	X86_MEM_WRITE_u32(base, 0x56F240u, ctx.xmm[0].u32[0]);
	// 0x29C958: ret
	return;
}

void sub_29C960(X86Context& ctx, uint8_t* base) {
	// 0x29C960: movss xmm0, dword ptr [0x0056F270]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F270u);
	// 0x29C968: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29C970: movss [0x0056F22C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F22Cu, ctx.xmm[0].u32[0]);
	// 0x29C978: ret
	return;
}

void sub_29C980(X86Context& ctx, uint8_t* base) {
	// 0x29C980: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29C988: movss [0x0056F214], xmm0
	X86_MEM_WRITE_u32(base, 0x56F214u, ctx.xmm[0].u32[0]);
	// 0x29C990: ret
	return;
}

void sub_29C9A0(X86Context& ctx, uint8_t* base) {
	// 0x29C9A0: movss xmm0, dword ptr [0x0056F22C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F22Cu);
	// 0x29C9A8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29C9B0: movss [0x0056F260], xmm0
	X86_MEM_WRITE_u32(base, 0x56F260u, ctx.xmm[0].u32[0]);
	// 0x29C9B8: ret
	return;
}

void sub_29C9C0(X86Context& ctx, uint8_t* base) {
	// 0x29C9C0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29C9C8: movss [0x0056F230], xmm0
	X86_MEM_WRITE_u32(base, 0x56F230u, ctx.xmm[0].u32[0]);
	// 0x29C9D0: ret
	return;
}

void sub_29C9E0(X86Context& ctx, uint8_t* base) {
	// 0x29C9E0: movss xmm0, dword ptr [0x00388E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x29C9E8: movss [0x0056F208], xmm0
	X86_MEM_WRITE_u32(base, 0x56F208u, ctx.xmm[0].u32[0]);
	// 0x29C9F0: ret
	return;
}

void sub_29CA00(X86Context& ctx, uint8_t* base) {
	// 0x29CA00: movss xmm0, dword ptr [0x0056F208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F208u);
	// 0x29CA08: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29CA10: movss [0x0056F1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1F4u, ctx.xmm[0].u32[0]);
	// 0x29CA18: ret
	return;
}

void sub_29CA20(X86Context& ctx, uint8_t* base) {
	// 0x29CA20: movss xmm0, dword ptr [0x003A35C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A35C4u);
	// 0x29CA28: movss [0x0056F228], xmm0
	X86_MEM_WRITE_u32(base, 0x56F228u, ctx.xmm[0].u32[0]);
	// 0x29CA30: ret
	return;
}

void sub_29CA40(X86Context& ctx, uint8_t* base) {
	// 0x29CA40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29CA48: movss [0x0056F2E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2E4u, ctx.xmm[0].u32[0]);
	// 0x29CA50: ret
	return;
}

void sub_29CA60(X86Context& ctx, uint8_t* base) {
	// 0x29CA60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29CA68: movss [0x0056F300], xmm0
	X86_MEM_WRITE_u32(base, 0x56F300u, ctx.xmm[0].u32[0]);
	// 0x29CA70: ret
	return;
}

void sub_29CA80(X86Context& ctx, uint8_t* base) {
	// 0x29CA80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29CA88: movss [0x0056F2D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2D8u, ctx.xmm[0].u32[0]);
	// 0x29CA90: ret
	return;
}

void sub_29CAA0(X86Context& ctx, uint8_t* base) {
	// 0x29CAA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29CAA8: movss [0x0056F290], xmm0
	X86_MEM_WRITE_u32(base, 0x56F290u, ctx.xmm[0].u32[0]);
	// 0x29CAB0: ret
	return;
}

void sub_29CAC0(X86Context& ctx, uint8_t* base) {
	// 0x29CAC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29CAC8: movss [0x0056F2E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2E8u, ctx.xmm[0].u32[0]);
	// 0x29CAD0: ret
	return;
}

void sub_29CAE0(X86Context& ctx, uint8_t* base) {
	// 0x29CAE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29CAE8: movss [0x0056F2AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2ACu, ctx.xmm[0].u32[0]);
	// 0x29CAF0: ret
	return;
}

void sub_29CB00(X86Context& ctx, uint8_t* base) {
	// 0x29CB00: movss xmm0, dword ptr [0x0056F2E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2E8u);
	// 0x29CB08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29CB10: movss [0x0056F320], xmm0
	X86_MEM_WRITE_u32(base, 0x56F320u, ctx.xmm[0].u32[0]);
	// 0x29CB18: ret
	return;
}

void sub_29CB20(X86Context& ctx, uint8_t* base) {
	// 0x29CB20: movss xmm0, dword ptr [0x0056F2AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2ACu);
	// 0x29CB28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29CB30: movss [0x0056F308], xmm0
	X86_MEM_WRITE_u32(base, 0x56F308u, ctx.xmm[0].u32[0]);
	// 0x29CB38: ret
	return;
}

void sub_29CB40(X86Context& ctx, uint8_t* base) {
	// 0x29CB40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29CB48: movss [0x0056F338], xmm0
	X86_MEM_WRITE_u32(base, 0x56F338u, ctx.xmm[0].u32[0]);
	// 0x29CB50: ret
	return;
}

void sub_29CB60(X86Context& ctx, uint8_t* base) {
	// 0x29CB60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29CB68: movss [0x0056F324], xmm0
	X86_MEM_WRITE_u32(base, 0x56F324u, ctx.xmm[0].u32[0]);
	// 0x29CB70: ret
	return;
}

void sub_29CB80(X86Context& ctx, uint8_t* base) {
	// 0x29CB80: movss xmm0, dword ptr [0x0056F324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F324u);
	// 0x29CB88: movss [0x0056F334], xmm0
	X86_MEM_WRITE_u32(base, 0x56F334u, ctx.xmm[0].u32[0]);
	// 0x29CB90: ret
	return;
}

void sub_29CBA0(X86Context& ctx, uint8_t* base) {
	// 0x29CBA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29CBA8: movss [0x0056F298], xmm0
	X86_MEM_WRITE_u32(base, 0x56F298u, ctx.xmm[0].u32[0]);
	// 0x29CBB0: ret
	return;
}

void sub_29CBC0(X86Context& ctx, uint8_t* base) {
	// 0x29CBC0: movss xmm0, dword ptr [0x0056F2AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2ACu);
	// 0x29CBC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29CBD0: movss [0x0056F32C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F32Cu, ctx.xmm[0].u32[0]);
	// 0x29CBD8: ret
	return;
}

void sub_29CBE0(X86Context& ctx, uint8_t* base) {
	// 0x29CBE0: movss xmm0, dword ptr [0x0056F2AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2ACu);
	// 0x29CBE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29CBF0: movss [0x0056F2D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2D4u, ctx.xmm[0].u32[0]);
	// 0x29CBF8: ret
	return;
}

void sub_29CC00(X86Context& ctx, uint8_t* base) {
	// 0x29CC00: movss xmm0, dword ptr [0x0056F2AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2ACu);
	// 0x29CC08: subss xmm0, [0x0056F2D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F2D4u);
	// 0x29CC10: movss [0x0056F2B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2B4u, ctx.xmm[0].u32[0]);
	// 0x29CC18: ret
	return;
}

void sub_29CC20(X86Context& ctx, uint8_t* base) {
	// 0x29CC20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29CC28: movss [0x0056F2FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2FCu, ctx.xmm[0].u32[0]);
	// 0x29CC30: ret
	return;
}

void sub_29CC40(X86Context& ctx, uint8_t* base) {
	// 0x29CC40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29CC48: movss [0x0056F2B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2B0u, ctx.xmm[0].u32[0]);
	// 0x29CC50: ret
	return;
}

void sub_29CC60(X86Context& ctx, uint8_t* base) {
	// 0x29CC60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29CC68: movss [0x0056F2C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2C0u, ctx.xmm[0].u32[0]);
	// 0x29CC70: ret
	return;
}

void sub_29CC80(X86Context& ctx, uint8_t* base) {
	// 0x29CC80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29CC88: movss [0x0056F314], xmm0
	X86_MEM_WRITE_u32(base, 0x56F314u, ctx.xmm[0].u32[0]);
	// 0x29CC90: ret
	return;
}

void sub_29CCA0(X86Context& ctx, uint8_t* base) {
	// 0x29CCA0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29CCA8: movss [0x0056F2F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2F8u, ctx.xmm[0].u32[0]);
	// 0x29CCB0: ret
	return;
}

void sub_29CCC0(X86Context& ctx, uint8_t* base) {
	// 0x29CCC0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29CCC8: movss [0x0056F2A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2A8u, ctx.xmm[0].u32[0]);
	// 0x29CCD0: ret
	return;
}

void sub_29CCE0(X86Context& ctx, uint8_t* base) {
	// 0x29CCE0: movss xmm0, dword ptr [0x0056F2C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2C0u);
	// 0x29CCE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29CCF0: movss [0x0056F29C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F29Cu, ctx.xmm[0].u32[0]);
	// 0x29CCF8: ret
	return;
}

void sub_29CD00(X86Context& ctx, uint8_t* base) {
	// 0x29CD00: movss xmm0, dword ptr [0x0056F314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F314u);
	// 0x29CD08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29CD10: movss [0x0056F2E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2E0u, ctx.xmm[0].u32[0]);
	// 0x29CD18: ret
	return;
}

void sub_29CD20(X86Context& ctx, uint8_t* base) {
	// 0x29CD20: movss xmm0, dword ptr [0x0056F29C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F29Cu);
	// 0x29CD28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29CD30: movss [0x0056F2F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2F0u, ctx.xmm[0].u32[0]);
	// 0x29CD38: ret
	return;
}

void sub_29CD40(X86Context& ctx, uint8_t* base) {
	// 0x29CD40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29CD48: movss [0x0056F294], xmm0
	X86_MEM_WRITE_u32(base, 0x56F294u, ctx.xmm[0].u32[0]);
	// 0x29CD50: ret
	return;
}

void sub_29CD60(X86Context& ctx, uint8_t* base) {
	// 0x29CD60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29CD68: movss [0x0056F2C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2C4u, ctx.xmm[0].u32[0]);
	// 0x29CD70: ret
	return;
}

void sub_29CD80(X86Context& ctx, uint8_t* base) {
	// 0x29CD80: movss xmm0, dword ptr [0x0056F2C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2C0u);
	// 0x29CD88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29CD90: movss [0x0056F2D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2D0u, ctx.xmm[0].u32[0]);
	// 0x29CD98: ret
	return;
}

void sub_29CDA0(X86Context& ctx, uint8_t* base) {
	// 0x29CDA0: movss xmm0, dword ptr [0x0056F314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F314u);
	// 0x29CDA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29CDB0: movss [0x0056F318], xmm0
	X86_MEM_WRITE_u32(base, 0x56F318u, ctx.xmm[0].u32[0]);
	// 0x29CDB8: ret
	return;
}

void sub_29CDC0(X86Context& ctx, uint8_t* base) {
	// 0x29CDC0: movss xmm0, dword ptr [0x0056F2D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2D0u);
	// 0x29CDC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29CDD0: movss [0x0056F304], xmm0
	X86_MEM_WRITE_u32(base, 0x56F304u, ctx.xmm[0].u32[0]);
	// 0x29CDD8: ret
	return;
}

void sub_29CDE0(X86Context& ctx, uint8_t* base) {
	// 0x29CDE0: movss xmm0, dword ptr [0x0056F318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F318u);
	// 0x29CDE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29CDF0: movss [0x0056F328], xmm0
	X86_MEM_WRITE_u32(base, 0x56F328u, ctx.xmm[0].u32[0]);
	// 0x29CDF8: ret
	return;
}

void sub_29CE00(X86Context& ctx, uint8_t* base) {
	// 0x29CE00: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29CE08: movss [0x0056F2A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2A0u, ctx.xmm[0].u32[0]);
	// 0x29CE10: ret
	return;
}

void sub_29CE20(X86Context& ctx, uint8_t* base) {
	// 0x29CE20: movss xmm0, dword ptr [0x0056F2C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2C0u);
	// 0x29CE28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29CE30: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29CE38: movss [0x0056F310], xmm0
	X86_MEM_WRITE_u32(base, 0x56F310u, ctx.xmm[0].u32[0]);
	// 0x29CE40: ret
	return;
}

void sub_29CE50(X86Context& ctx, uint8_t* base) {
	// 0x29CE50: movss xmm0, dword ptr [0x0056F314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F314u);
	// 0x29CE58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29CE60: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29CE68: movss [0x0056F2B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2B8u, ctx.xmm[0].u32[0]);
	// 0x29CE70: ret
	return;
}

void sub_29CE80(X86Context& ctx, uint8_t* base) {
	// 0x29CE80: movss xmm0, dword ptr [0x0056F2C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2C0u);
	// 0x29CE88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29CE90: movss [0x0056F2BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2BCu, ctx.xmm[0].u32[0]);
	// 0x29CE98: ret
	return;
}

void sub_29CEA0(X86Context& ctx, uint8_t* base) {
	// 0x29CEA0: movss xmm0, dword ptr [0x0056F314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F314u);
	// 0x29CEA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29CEB0: movss [0x0056F31C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F31Cu, ctx.xmm[0].u32[0]);
	// 0x29CEB8: ret
	return;
}

void sub_29CEC0(X86Context& ctx, uint8_t* base) {
	// 0x29CEC0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29CEC8: movss [0x0056F2A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2A4u, ctx.xmm[0].u32[0]);
	// 0x29CED0: ret
	return;
}

void sub_29CEE0(X86Context& ctx, uint8_t* base) {
	// 0x29CEE0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29CEE8: movss [0x0056F2CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2CCu, ctx.xmm[0].u32[0]);
	// 0x29CEF0: ret
	return;
}

void sub_29CF00(X86Context& ctx, uint8_t* base) {
	// 0x29CF00: movss xmm0, dword ptr [0x0056F2A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2A4u);
	// 0x29CF08: movss [0x0056F330], xmm0
	X86_MEM_WRITE_u32(base, 0x56F330u, ctx.xmm[0].u32[0]);
	// 0x29CF10: ret
	return;
}

void sub_29CF20(X86Context& ctx, uint8_t* base) {
	// 0x29CF20: movss xmm0, dword ptr [0x0056F314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F314u);
	// 0x29CF28: subss xmm0, [0x0056F2A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F2A4u);
	// 0x29CF30: movss [0x0056F2F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2F4u, ctx.xmm[0].u32[0]);
	// 0x29CF38: ret
	return;
}

void sub_29CF40(X86Context& ctx, uint8_t* base) {
	// 0x29CF40: movss xmm0, dword ptr [0x0056F2F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2F4u);
	// 0x29CF48: subss xmm0, [0x0056F2CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F2CCu);
	// 0x29CF50: movss [0x0056F2EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2ECu, ctx.xmm[0].u32[0]);
	// 0x29CF58: ret
	return;
}

void sub_29CF60(X86Context& ctx, uint8_t* base) {
	// 0x29CF60: movss xmm0, dword ptr [0x0056F31C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F31Cu);
	// 0x29CF68: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29CF70: movss [0x0056F2DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2DCu, ctx.xmm[0].u32[0]);
	// 0x29CF78: ret
	return;
}

void sub_29CF80(X86Context& ctx, uint8_t* base) {
	// 0x29CF80: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29CF88: movss [0x0056F2C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F2C8u, ctx.xmm[0].u32[0]);
	// 0x29CF90: ret
	return;
}

void sub_29CFA0(X86Context& ctx, uint8_t* base) {
	// 0x29CFA0: movss xmm0, dword ptr [0x0056F2DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F2DCu);
	// 0x29CFA8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29CFB0: movss [0x0056F30C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F30Cu, ctx.xmm[0].u32[0]);
	// 0x29CFB8: ret
	return;
}

void sub_29CFC0(X86Context& ctx, uint8_t* base) {
	// 0x29CFC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29CFC8: movss [0x0056F390], xmm0
	X86_MEM_WRITE_u32(base, 0x56F390u, ctx.xmm[0].u32[0]);
	// 0x29CFD0: ret
	return;
}

void sub_29CFE0(X86Context& ctx, uint8_t* base) {
	// 0x29CFE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29CFE8: movss [0x0056F3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3ACu, ctx.xmm[0].u32[0]);
	// 0x29CFF0: ret
	return;
}

void sub_29D000(X86Context& ctx, uint8_t* base) {
	// 0x29D000: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29D008: movss [0x0056F384], xmm0
	X86_MEM_WRITE_u32(base, 0x56F384u, ctx.xmm[0].u32[0]);
	// 0x29D010: ret
	return;
}

void sub_29D020(X86Context& ctx, uint8_t* base) {
	// 0x29D020: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29D028: movss [0x0056F33C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F33Cu, ctx.xmm[0].u32[0]);
	// 0x29D030: ret
	return;
}

void sub_29D040(X86Context& ctx, uint8_t* base) {
	// 0x29D040: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29D048: movss [0x0056F394], xmm0
	X86_MEM_WRITE_u32(base, 0x56F394u, ctx.xmm[0].u32[0]);
	// 0x29D050: ret
	return;
}

void sub_29D060(X86Context& ctx, uint8_t* base) {
	// 0x29D060: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29D068: movss [0x0056F358], xmm0
	X86_MEM_WRITE_u32(base, 0x56F358u, ctx.xmm[0].u32[0]);
	// 0x29D070: ret
	return;
}

void sub_29D080(X86Context& ctx, uint8_t* base) {
	// 0x29D080: movss xmm0, dword ptr [0x0056F394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F394u);
	// 0x29D088: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29D090: movss [0x0056F3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3CCu, ctx.xmm[0].u32[0]);
	// 0x29D098: ret
	return;
}

void sub_29D0A0(X86Context& ctx, uint8_t* base) {
	// 0x29D0A0: movss xmm0, dword ptr [0x0056F358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F358u);
	// 0x29D0A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29D0B0: movss [0x0056F3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3B4u, ctx.xmm[0].u32[0]);
	// 0x29D0B8: ret
	return;
}

void sub_29D0C0(X86Context& ctx, uint8_t* base) {
	// 0x29D0C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29D0C8: movss [0x0056F3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3E4u, ctx.xmm[0].u32[0]);
	// 0x29D0D0: ret
	return;
}

void sub_29D0E0(X86Context& ctx, uint8_t* base) {
	// 0x29D0E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29D0E8: movss [0x0056F3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3D0u, ctx.xmm[0].u32[0]);
	// 0x29D0F0: ret
	return;
}

void sub_29D100(X86Context& ctx, uint8_t* base) {
	// 0x29D100: movss xmm0, dword ptr [0x0056F3D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3D0u);
	// 0x29D108: movss [0x0056F3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3E0u, ctx.xmm[0].u32[0]);
	// 0x29D110: ret
	return;
}

void sub_29D120(X86Context& ctx, uint8_t* base) {
	// 0x29D120: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29D128: movss [0x0056F344], xmm0
	X86_MEM_WRITE_u32(base, 0x56F344u, ctx.xmm[0].u32[0]);
	// 0x29D130: ret
	return;
}

void sub_29D140(X86Context& ctx, uint8_t* base) {
	// 0x29D140: movss xmm0, dword ptr [0x0056F358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F358u);
	// 0x29D148: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29D150: movss [0x0056F3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3D8u, ctx.xmm[0].u32[0]);
	// 0x29D158: ret
	return;
}

void sub_29D160(X86Context& ctx, uint8_t* base) {
	// 0x29D160: movss xmm0, dword ptr [0x0056F358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F358u);
	// 0x29D168: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29D170: movss [0x0056F380], xmm0
	X86_MEM_WRITE_u32(base, 0x56F380u, ctx.xmm[0].u32[0]);
	// 0x29D178: ret
	return;
}

void sub_29D180(X86Context& ctx, uint8_t* base) {
	// 0x29D180: movss xmm0, dword ptr [0x0056F358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F358u);
	// 0x29D188: subss xmm0, [0x0056F380]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F380u);
	// 0x29D190: movss [0x0056F360], xmm0
	X86_MEM_WRITE_u32(base, 0x56F360u, ctx.xmm[0].u32[0]);
	// 0x29D198: ret
	return;
}

void sub_29D1A0(X86Context& ctx, uint8_t* base) {
	// 0x29D1A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29D1A8: movss [0x0056F3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3A8u, ctx.xmm[0].u32[0]);
	// 0x29D1B0: ret
	return;
}

void sub_29D1C0(X86Context& ctx, uint8_t* base) {
	// 0x29D1C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29D1C8: movss [0x0056F35C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F35Cu, ctx.xmm[0].u32[0]);
	// 0x29D1D0: ret
	return;
}

void sub_29D1E0(X86Context& ctx, uint8_t* base) {
	// 0x29D1E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29D1E8: movss [0x0056F36C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F36Cu, ctx.xmm[0].u32[0]);
	// 0x29D1F0: ret
	return;
}

void sub_29D200(X86Context& ctx, uint8_t* base) {
	// 0x29D200: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29D208: movss [0x0056F3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3C0u, ctx.xmm[0].u32[0]);
	// 0x29D210: ret
	return;
}

void sub_29D220(X86Context& ctx, uint8_t* base) {
	// 0x29D220: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29D228: movss [0x0056F3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3A4u, ctx.xmm[0].u32[0]);
	// 0x29D230: ret
	return;
}

void sub_29D240(X86Context& ctx, uint8_t* base) {
	// 0x29D240: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29D248: movss [0x0056F354], xmm0
	X86_MEM_WRITE_u32(base, 0x56F354u, ctx.xmm[0].u32[0]);
	// 0x29D250: ret
	return;
}

void sub_29D260(X86Context& ctx, uint8_t* base) {
	// 0x29D260: movss xmm0, dword ptr [0x0056F36C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F36Cu);
	// 0x29D268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29D270: movss [0x0056F348], xmm0
	X86_MEM_WRITE_u32(base, 0x56F348u, ctx.xmm[0].u32[0]);
	// 0x29D278: ret
	return;
}

void sub_29D280(X86Context& ctx, uint8_t* base) {
	// 0x29D280: movss xmm0, dword ptr [0x0056F3C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C0u);
	// 0x29D288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29D290: movss [0x0056F38C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F38Cu, ctx.xmm[0].u32[0]);
	// 0x29D298: ret
	return;
}

void sub_29D2A0(X86Context& ctx, uint8_t* base) {
	// 0x29D2A0: movss xmm0, dword ptr [0x0056F348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F348u);
	// 0x29D2A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29D2B0: movss [0x0056F39C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F39Cu, ctx.xmm[0].u32[0]);
	// 0x29D2B8: ret
	return;
}

void sub_29D2C0(X86Context& ctx, uint8_t* base) {
	// 0x29D2C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29D2C8: movss [0x0056F340], xmm0
	X86_MEM_WRITE_u32(base, 0x56F340u, ctx.xmm[0].u32[0]);
	// 0x29D2D0: ret
	return;
}

void sub_29D2E0(X86Context& ctx, uint8_t* base) {
	// 0x29D2E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29D2E8: movss [0x0056F370], xmm0
	X86_MEM_WRITE_u32(base, 0x56F370u, ctx.xmm[0].u32[0]);
	// 0x29D2F0: ret
	return;
}

void sub_29D300(X86Context& ctx, uint8_t* base) {
	// 0x29D300: movss xmm0, dword ptr [0x0056F36C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F36Cu);
	// 0x29D308: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29D310: movss [0x0056F37C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F37Cu, ctx.xmm[0].u32[0]);
	// 0x29D318: ret
	return;
}

void sub_29D320(X86Context& ctx, uint8_t* base) {
	// 0x29D320: movss xmm0, dword ptr [0x0056F3C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C0u);
	// 0x29D328: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29D330: movss [0x0056F3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3C4u, ctx.xmm[0].u32[0]);
	// 0x29D338: ret
	return;
}

void sub_29D340(X86Context& ctx, uint8_t* base) {
	// 0x29D340: movss xmm0, dword ptr [0x0056F37C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F37Cu);
	// 0x29D348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D350: movss [0x0056F3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3B0u, ctx.xmm[0].u32[0]);
	// 0x29D358: ret
	return;
}

void sub_29D360(X86Context& ctx, uint8_t* base) {
	// 0x29D360: movss xmm0, dword ptr [0x0056F3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C4u);
	// 0x29D368: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D370: movss [0x0056F3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3D4u, ctx.xmm[0].u32[0]);
	// 0x29D378: ret
	return;
}

void sub_29D380(X86Context& ctx, uint8_t* base) {
	// 0x29D380: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29D388: movss [0x0056F34C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F34Cu, ctx.xmm[0].u32[0]);
	// 0x29D390: ret
	return;
}

void sub_29D3A0(X86Context& ctx, uint8_t* base) {
	// 0x29D3A0: movss xmm0, dword ptr [0x0056F36C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F36Cu);
	// 0x29D3A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D3B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29D3B8: movss [0x0056F3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3BCu, ctx.xmm[0].u32[0]);
	// 0x29D3C0: ret
	return;
}

void sub_29D3D0(X86Context& ctx, uint8_t* base) {
	// 0x29D3D0: movss xmm0, dword ptr [0x0056F3C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C0u);
	// 0x29D3D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D3E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29D3E8: movss [0x0056F364], xmm0
	X86_MEM_WRITE_u32(base, 0x56F364u, ctx.xmm[0].u32[0]);
	// 0x29D3F0: ret
	return;
}

void sub_29D400(X86Context& ctx, uint8_t* base) {
	// 0x29D400: movss xmm0, dword ptr [0x0056F36C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F36Cu);
	// 0x29D408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D410: movss [0x0056F368], xmm0
	X86_MEM_WRITE_u32(base, 0x56F368u, ctx.xmm[0].u32[0]);
	// 0x29D418: ret
	return;
}

void sub_29D420(X86Context& ctx, uint8_t* base) {
	// 0x29D420: movss xmm0, dword ptr [0x0056F3C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C0u);
	// 0x29D428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D430: movss [0x0056F3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3C8u, ctx.xmm[0].u32[0]);
	// 0x29D438: ret
	return;
}

void sub_29D440(X86Context& ctx, uint8_t* base) {
	// 0x29D440: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29D448: movss [0x0056F350], xmm0
	X86_MEM_WRITE_u32(base, 0x56F350u, ctx.xmm[0].u32[0]);
	// 0x29D450: ret
	return;
}

void sub_29D460(X86Context& ctx, uint8_t* base) {
	// 0x29D460: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29D468: movss [0x0056F378], xmm0
	X86_MEM_WRITE_u32(base, 0x56F378u, ctx.xmm[0].u32[0]);
	// 0x29D470: ret
	return;
}

void sub_29D480(X86Context& ctx, uint8_t* base) {
	// 0x29D480: movss xmm0, dword ptr [0x0056F350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F350u);
	// 0x29D488: movss [0x0056F3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3DCu, ctx.xmm[0].u32[0]);
	// 0x29D490: ret
	return;
}

void sub_29D4A0(X86Context& ctx, uint8_t* base) {
	// 0x29D4A0: movss xmm0, dword ptr [0x0056F3C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C0u);
	// 0x29D4A8: subss xmm0, [0x0056F350]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F350u);
	// 0x29D4B0: movss [0x0056F3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3A0u, ctx.xmm[0].u32[0]);
	// 0x29D4B8: ret
	return;
}

void sub_29D4C0(X86Context& ctx, uint8_t* base) {
	// 0x29D4C0: movss xmm0, dword ptr [0x0056F3A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3A0u);
	// 0x29D4C8: subss xmm0, [0x0056F378]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F378u);
	// 0x29D4D0: movss [0x0056F398], xmm0
	X86_MEM_WRITE_u32(base, 0x56F398u, ctx.xmm[0].u32[0]);
	// 0x29D4D8: ret
	return;
}

void sub_29D4E0(X86Context& ctx, uint8_t* base) {
	// 0x29D4E0: movss xmm0, dword ptr [0x0056F3C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3C8u);
	// 0x29D4E8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29D4F0: movss [0x0056F388], xmm0
	X86_MEM_WRITE_u32(base, 0x56F388u, ctx.xmm[0].u32[0]);
	// 0x29D4F8: ret
	return;
}

void sub_29D500(X86Context& ctx, uint8_t* base) {
	// 0x29D500: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29D508: movss [0x0056F374], xmm0
	X86_MEM_WRITE_u32(base, 0x56F374u, ctx.xmm[0].u32[0]);
	// 0x29D510: ret
	return;
}

void sub_29D520(X86Context& ctx, uint8_t* base) {
	// 0x29D520: movss xmm0, dword ptr [0x0056F388]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F388u);
	// 0x29D528: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29D530: movss [0x0056F3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3B8u, ctx.xmm[0].u32[0]);
	// 0x29D538: ret
	return;
}

void sub_29D540(X86Context& ctx, uint8_t* base) {
	// 0x29D540: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29D548: movss [0x0056F450], xmm0
	X86_MEM_WRITE_u32(base, 0x56F450u, ctx.xmm[0].u32[0]);
	// 0x29D550: ret
	return;
}

void sub_29D560(X86Context& ctx, uint8_t* base) {
	// 0x29D560: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29D568: movss [0x0056F46C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F46Cu, ctx.xmm[0].u32[0]);
	// 0x29D570: ret
	return;
}

void sub_29D580(X86Context& ctx, uint8_t* base) {
	// 0x29D580: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29D588: movss [0x0056F440], xmm0
	X86_MEM_WRITE_u32(base, 0x56F440u, ctx.xmm[0].u32[0]);
	// 0x29D590: ret
	return;
}

void sub_29D5A0(X86Context& ctx, uint8_t* base) {
	// 0x29D5A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29D5A8: movss [0x0056F3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3E8u, ctx.xmm[0].u32[0]);
	// 0x29D5B0: ret
	return;
}

void sub_29D5C0(X86Context& ctx, uint8_t* base) {
	// 0x29D5C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29D5C8: movss [0x0056F454], xmm0
	X86_MEM_WRITE_u32(base, 0x56F454u, ctx.xmm[0].u32[0]);
	// 0x29D5D0: ret
	return;
}

void sub_29D5E0(X86Context& ctx, uint8_t* base) {
	// 0x29D5E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29D5E8: movss [0x0056F408], xmm0
	X86_MEM_WRITE_u32(base, 0x56F408u, ctx.xmm[0].u32[0]);
	// 0x29D5F0: ret
	return;
}

void sub_29D600(X86Context& ctx, uint8_t* base) {
	// 0x29D600: movss xmm0, dword ptr [0x0056F454]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F454u);
	// 0x29D608: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29D610: movss [0x0056F494], xmm0
	X86_MEM_WRITE_u32(base, 0x56F494u, ctx.xmm[0].u32[0]);
	// 0x29D618: ret
	return;
}

void sub_29D620(X86Context& ctx, uint8_t* base) {
	// 0x29D620: movss xmm0, dword ptr [0x0056F408]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F408u);
	// 0x29D628: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29D630: movss [0x0056F478], xmm0
	X86_MEM_WRITE_u32(base, 0x56F478u, ctx.xmm[0].u32[0]);
	// 0x29D638: ret
	return;
}

void sub_29D640(X86Context& ctx, uint8_t* base) {
	// 0x29D640: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29D648: movss [0x0056F4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4ACu, ctx.xmm[0].u32[0]);
	// 0x29D650: ret
	return;
}

void sub_29D660(X86Context& ctx, uint8_t* base) {
	// 0x29D660: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29D668: movss [0x0056F498], xmm0
	X86_MEM_WRITE_u32(base, 0x56F498u, ctx.xmm[0].u32[0]);
	// 0x29D670: ret
	return;
}

void sub_29D680(X86Context& ctx, uint8_t* base) {
	// 0x29D680: movss xmm0, dword ptr [0x0056F498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F498u);
	// 0x29D688: movss [0x0056F4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4A8u, ctx.xmm[0].u32[0]);
	// 0x29D690: ret
	return;
}

void sub_29D6A0(X86Context& ctx, uint8_t* base) {
	// 0x29D6A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29D6A8: movss [0x0056F3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3F0u, ctx.xmm[0].u32[0]);
	// 0x29D6B0: ret
	return;
}

void sub_29D6C0(X86Context& ctx, uint8_t* base) {
	// 0x29D6C0: movss xmm0, dword ptr [0x0056F408]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F408u);
	// 0x29D6C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29D6D0: movss [0x0056F4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4A0u, ctx.xmm[0].u32[0]);
	// 0x29D6D8: ret
	return;
}

void sub_29D6E0(X86Context& ctx, uint8_t* base) {
	// 0x29D6E0: movss xmm0, dword ptr [0x0056F408]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F408u);
	// 0x29D6E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29D6F0: movss [0x0056F43C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F43Cu, ctx.xmm[0].u32[0]);
	// 0x29D6F8: ret
	return;
}

void sub_29D700(X86Context& ctx, uint8_t* base) {
	// 0x29D700: movss xmm0, dword ptr [0x0056F408]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F408u);
	// 0x29D708: subss xmm0, [0x0056F43C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F43Cu);
	// 0x29D710: movss [0x0056F410], xmm0
	X86_MEM_WRITE_u32(base, 0x56F410u, ctx.xmm[0].u32[0]);
	// 0x29D718: ret
	return;
}

void sub_29D720(X86Context& ctx, uint8_t* base) {
	// 0x29D720: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29D728: movss [0x0056F468], xmm0
	X86_MEM_WRITE_u32(base, 0x56F468u, ctx.xmm[0].u32[0]);
	// 0x29D730: ret
	return;
}

void sub_29D740(X86Context& ctx, uint8_t* base) {
	// 0x29D740: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29D748: movss [0x0056F40C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F40Cu, ctx.xmm[0].u32[0]);
	// 0x29D750: ret
	return;
}

void sub_29D760(X86Context& ctx, uint8_t* base) {
	// 0x29D760: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29D768: movss [0x0056F424], xmm0
	X86_MEM_WRITE_u32(base, 0x56F424u, ctx.xmm[0].u32[0]);
	// 0x29D770: ret
	return;
}

void sub_29D780(X86Context& ctx, uint8_t* base) {
	// 0x29D780: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29D788: movss [0x0056F488], xmm0
	X86_MEM_WRITE_u32(base, 0x56F488u, ctx.xmm[0].u32[0]);
	// 0x29D790: ret
	return;
}

void sub_29D7A0(X86Context& ctx, uint8_t* base) {
	// 0x29D7A0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29D7A8: movss [0x0056F464], xmm0
	X86_MEM_WRITE_u32(base, 0x56F464u, ctx.xmm[0].u32[0]);
	// 0x29D7B0: ret
	return;
}

void sub_29D7C0(X86Context& ctx, uint8_t* base) {
	// 0x29D7C0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29D7C8: movss [0x0056F400], xmm0
	X86_MEM_WRITE_u32(base, 0x56F400u, ctx.xmm[0].u32[0]);
	// 0x29D7D0: ret
	return;
}

void sub_29D7E0(X86Context& ctx, uint8_t* base) {
	// 0x29D7E0: movss xmm0, dword ptr [0x0056F424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F424u);
	// 0x29D7E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29D7F0: movss [0x0056F3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3F4u, ctx.xmm[0].u32[0]);
	// 0x29D7F8: ret
	return;
}

void sub_29D800(X86Context& ctx, uint8_t* base) {
	// 0x29D800: movss xmm0, dword ptr [0x0056F488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F488u);
	// 0x29D808: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29D810: movss [0x0056F448], xmm0
	X86_MEM_WRITE_u32(base, 0x56F448u, ctx.xmm[0].u32[0]);
	// 0x29D818: ret
	return;
}

void sub_29D820(X86Context& ctx, uint8_t* base) {
	// 0x29D820: movss xmm0, dword ptr [0x0056F3F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3F4u);
	// 0x29D828: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29D830: movss [0x0056F45C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F45Cu, ctx.xmm[0].u32[0]);
	// 0x29D838: ret
	return;
}

void sub_29D840(X86Context& ctx, uint8_t* base) {
	// 0x29D840: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29D848: movss [0x0056F3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3ECu, ctx.xmm[0].u32[0]);
	// 0x29D850: ret
	return;
}

void sub_29D860(X86Context& ctx, uint8_t* base) {
	// 0x29D860: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29D868: movss [0x0056F428], xmm0
	X86_MEM_WRITE_u32(base, 0x56F428u, ctx.xmm[0].u32[0]);
	// 0x29D870: ret
	return;
}

void sub_29D880(X86Context& ctx, uint8_t* base) {
	// 0x29D880: movss xmm0, dword ptr [0x0056F424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F424u);
	// 0x29D888: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29D890: movss [0x0056F438], xmm0
	X86_MEM_WRITE_u32(base, 0x56F438u, ctx.xmm[0].u32[0]);
	// 0x29D898: ret
	return;
}

void sub_29D8A0(X86Context& ctx, uint8_t* base) {
	// 0x29D8A0: movss xmm0, dword ptr [0x0056F488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F488u);
	// 0x29D8A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29D8B0: movss [0x0056F48C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F48Cu, ctx.xmm[0].u32[0]);
	// 0x29D8B8: ret
	return;
}

void sub_29D8C0(X86Context& ctx, uint8_t* base) {
	// 0x29D8C0: movss xmm0, dword ptr [0x0056F438]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F438u);
	// 0x29D8C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D8D0: movss [0x0056F470], xmm0
	X86_MEM_WRITE_u32(base, 0x56F470u, ctx.xmm[0].u32[0]);
	// 0x29D8D8: ret
	return;
}

void sub_29D8E0(X86Context& ctx, uint8_t* base) {
	// 0x29D8E0: movss xmm0, dword ptr [0x0056F48C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F48Cu);
	// 0x29D8E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D8F0: movss [0x0056F49C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F49Cu, ctx.xmm[0].u32[0]);
	// 0x29D8F8: ret
	return;
}

void sub_29D900(X86Context& ctx, uint8_t* base) {
	// 0x29D900: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29D908: movss [0x0056F3F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3F8u, ctx.xmm[0].u32[0]);
	// 0x29D910: ret
	return;
}

void sub_29D920(X86Context& ctx, uint8_t* base) {
	// 0x29D920: movss xmm0, dword ptr [0x0056F424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F424u);
	// 0x29D928: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D930: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29D938: movss [0x0056F480], xmm0
	X86_MEM_WRITE_u32(base, 0x56F480u, ctx.xmm[0].u32[0]);
	// 0x29D940: ret
	return;
}

void sub_29D950(X86Context& ctx, uint8_t* base) {
	// 0x29D950: movss xmm0, dword ptr [0x0056F488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F488u);
	// 0x29D958: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D960: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29D968: movss [0x0056F414], xmm0
	X86_MEM_WRITE_u32(base, 0x56F414u, ctx.xmm[0].u32[0]);
	// 0x29D970: ret
	return;
}

void sub_29D980(X86Context& ctx, uint8_t* base) {
	// 0x29D980: movss xmm0, dword ptr [0x0056F424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F424u);
	// 0x29D988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D990: movss [0x0056F418], xmm0
	X86_MEM_WRITE_u32(base, 0x56F418u, ctx.xmm[0].u32[0]);
	// 0x29D998: ret
	return;
}

void sub_29D9A0(X86Context& ctx, uint8_t* base) {
	// 0x29D9A0: movss xmm0, dword ptr [0x0056F488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F488u);
	// 0x29D9A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29D9B0: movss [0x0056F490], xmm0
	X86_MEM_WRITE_u32(base, 0x56F490u, ctx.xmm[0].u32[0]);
	// 0x29D9B8: ret
	return;
}

void sub_29D9C0(X86Context& ctx, uint8_t* base) {
	// 0x29D9C0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29D9C8: movss [0x0056F3FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F3FCu, ctx.xmm[0].u32[0]);
	// 0x29D9D0: ret
	return;
}

void sub_29D9E0(X86Context& ctx, uint8_t* base) {
	// 0x29D9E0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29D9E8: movss [0x0056F434], xmm0
	X86_MEM_WRITE_u32(base, 0x56F434u, ctx.xmm[0].u32[0]);
	// 0x29D9F0: ret
	return;
}

void sub_29DA00(X86Context& ctx, uint8_t* base) {
	// 0x29DA00: movss xmm0, dword ptr [0x0056F3FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F3FCu);
	// 0x29DA08: movss [0x0056F4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4A4u, ctx.xmm[0].u32[0]);
	// 0x29DA10: ret
	return;
}

void sub_29DA20(X86Context& ctx, uint8_t* base) {
	// 0x29DA20: movss xmm0, dword ptr [0x0056F488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F488u);
	// 0x29DA28: subss xmm0, [0x0056F3FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F3FCu);
	// 0x29DA30: movss [0x0056F460], xmm0
	X86_MEM_WRITE_u32(base, 0x56F460u, ctx.xmm[0].u32[0]);
	// 0x29DA38: ret
	return;
}

void sub_29DA40(X86Context& ctx, uint8_t* base) {
	// 0x29DA40: movss xmm0, dword ptr [0x0056F460]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F460u);
	// 0x29DA48: subss xmm0, [0x0056F434]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F434u);
	// 0x29DA50: movss [0x0056F458], xmm0
	X86_MEM_WRITE_u32(base, 0x56F458u, ctx.xmm[0].u32[0]);
	// 0x29DA58: ret
	return;
}

void sub_29DA60(X86Context& ctx, uint8_t* base) {
	// 0x29DA60: movss xmm0, dword ptr [0x0056F490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F490u);
	// 0x29DA68: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29DA70: movss [0x0056F444], xmm0
	X86_MEM_WRITE_u32(base, 0x56F444u, ctx.xmm[0].u32[0]);
	// 0x29DA78: ret
	return;
}

void sub_29DA80(X86Context& ctx, uint8_t* base) {
	// 0x29DA80: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29DA88: movss [0x0056F430], xmm0
	X86_MEM_WRITE_u32(base, 0x56F430u, ctx.xmm[0].u32[0]);
	// 0x29DA90: ret
	return;
}

void sub_29DAA0(X86Context& ctx, uint8_t* base) {
	// 0x29DAA0: movss xmm0, dword ptr [0x0056F444]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F444u);
	// 0x29DAA8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29DAB0: movss [0x0056F47C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F47Cu, ctx.xmm[0].u32[0]);
	// 0x29DAB8: ret
	return;
}

void sub_29DAC0(X86Context& ctx, uint8_t* base) {
	// 0x29DAC0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x29DAC8: movss [0x0056F44C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F44Cu, ctx.xmm[0].u32[0]);
	// 0x29DAD0: ret
	return;
}

void sub_29DAE0(X86Context& ctx, uint8_t* base) {
	// 0x29DAE0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29DAE8: movss [0x0056F420], xmm0
	X86_MEM_WRITE_u32(base, 0x56F420u, ctx.xmm[0].u32[0]);
	// 0x29DAF0: ret
	return;
}

void sub_29DB00(X86Context& ctx, uint8_t* base) {
	// 0x29DB00: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x29DB08: movss [0x0056F41C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F41Cu, ctx.xmm[0].u32[0]);
	// 0x29DB10: ret
	return;
}

void sub_29DB20(X86Context& ctx, uint8_t* base) {
	// 0x29DB20: movss xmm0, dword ptr [0x00388E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x29DB28: movss [0x0056F404], xmm0
	X86_MEM_WRITE_u32(base, 0x56F404u, ctx.xmm[0].u32[0]);
	// 0x29DB30: ret
	return;
}

void sub_29DB40(X86Context& ctx, uint8_t* base) {
	// 0x29DB40: movss xmm0, dword ptr [0x003B2290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2290u);
	// 0x29DB48: movss [0x0056F484], xmm0
	X86_MEM_WRITE_u32(base, 0x56F484u, ctx.xmm[0].u32[0]);
	// 0x29DB50: ret
	return;
}

void sub_29DB60(X86Context& ctx, uint8_t* base) {
	// 0x29DB60: movss xmm0, dword ptr [0x003B2070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2070u);
	// 0x29DB68: movss [0x0056F42C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F42Cu, ctx.xmm[0].u32[0]);
	// 0x29DB70: ret
	return;
}

void sub_29DB80(X86Context& ctx, uint8_t* base) {
	// 0x29DB80: movss xmm0, dword ptr [0x00395BFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BFCu);
	// 0x29DB88: movss [0x0056F474], xmm0
	X86_MEM_WRITE_u32(base, 0x56F474u, ctx.xmm[0].u32[0]);
	// 0x29DB90: ret
	return;
}

void sub_29DBA0(X86Context& ctx, uint8_t* base) {
	// 0x29DBA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29DBA8: movss [0x0056F504], xmm0
	X86_MEM_WRITE_u32(base, 0x56F504u, ctx.xmm[0].u32[0]);
	// 0x29DBB0: ret
	return;
}

void sub_29DBC0(X86Context& ctx, uint8_t* base) {
	// 0x29DBC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29DBC8: movss [0x0056F520], xmm0
	X86_MEM_WRITE_u32(base, 0x56F520u, ctx.xmm[0].u32[0]);
	// 0x29DBD0: ret
	return;
}

void sub_29DBE0(X86Context& ctx, uint8_t* base) {
	// 0x29DBE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29DBE8: movss [0x0056F4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4F8u, ctx.xmm[0].u32[0]);
	// 0x29DBF0: ret
	return;
}

void sub_29DC00(X86Context& ctx, uint8_t* base) {
	// 0x29DC00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29DC08: movss [0x0056F4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4B0u, ctx.xmm[0].u32[0]);
	// 0x29DC10: ret
	return;
}

void sub_29DC20(X86Context& ctx, uint8_t* base) {
	// 0x29DC20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29DC28: movss [0x0056F508], xmm0
	X86_MEM_WRITE_u32(base, 0x56F508u, ctx.xmm[0].u32[0]);
	// 0x29DC30: ret
	return;
}

void sub_29DC40(X86Context& ctx, uint8_t* base) {
	// 0x29DC40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29DC48: movss [0x0056F4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4CCu, ctx.xmm[0].u32[0]);
	// 0x29DC50: ret
	return;
}

void sub_29DC60(X86Context& ctx, uint8_t* base) {
	// 0x29DC60: movss xmm0, dword ptr [0x0056F508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F508u);
	// 0x29DC68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29DC70: movss [0x0056F540], xmm0
	X86_MEM_WRITE_u32(base, 0x56F540u, ctx.xmm[0].u32[0]);
	// 0x29DC78: ret
	return;
}

void sub_29DC80(X86Context& ctx, uint8_t* base) {
	// 0x29DC80: movss xmm0, dword ptr [0x0056F4CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4CCu);
	// 0x29DC88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29DC90: movss [0x0056F528], xmm0
	X86_MEM_WRITE_u32(base, 0x56F528u, ctx.xmm[0].u32[0]);
	// 0x29DC98: ret
	return;
}

void sub_29DCA0(X86Context& ctx, uint8_t* base) {
	// 0x29DCA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29DCA8: movss [0x0056F558], xmm0
	X86_MEM_WRITE_u32(base, 0x56F558u, ctx.xmm[0].u32[0]);
	// 0x29DCB0: ret
	return;
}

void sub_29DCC0(X86Context& ctx, uint8_t* base) {
	// 0x29DCC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29DCC8: movss [0x0056F544], xmm0
	X86_MEM_WRITE_u32(base, 0x56F544u, ctx.xmm[0].u32[0]);
	// 0x29DCD0: ret
	return;
}

void sub_29DCE0(X86Context& ctx, uint8_t* base) {
	// 0x29DCE0: movss xmm0, dword ptr [0x0056F544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F544u);
	// 0x29DCE8: movss [0x0056F554], xmm0
	X86_MEM_WRITE_u32(base, 0x56F554u, ctx.xmm[0].u32[0]);
	// 0x29DCF0: ret
	return;
}

void sub_29DD00(X86Context& ctx, uint8_t* base) {
	// 0x29DD00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29DD08: movss [0x0056F4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4B8u, ctx.xmm[0].u32[0]);
	// 0x29DD10: ret
	return;
}

void sub_29DD20(X86Context& ctx, uint8_t* base) {
	// 0x29DD20: movss xmm0, dword ptr [0x0056F4CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4CCu);
	// 0x29DD28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29DD30: movss [0x0056F54C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F54Cu, ctx.xmm[0].u32[0]);
	// 0x29DD38: ret
	return;
}

void sub_29DD40(X86Context& ctx, uint8_t* base) {
	// 0x29DD40: movss xmm0, dword ptr [0x0056F4CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4CCu);
	// 0x29DD48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29DD50: movss [0x0056F4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4F4u, ctx.xmm[0].u32[0]);
	// 0x29DD58: ret
	return;
}

void sub_29DD60(X86Context& ctx, uint8_t* base) {
	// 0x29DD60: movss xmm0, dword ptr [0x0056F4CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4CCu);
	// 0x29DD68: subss xmm0, [0x0056F4F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F4F4u);
	// 0x29DD70: movss [0x0056F4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4D4u, ctx.xmm[0].u32[0]);
	// 0x29DD78: ret
	return;
}

void sub_29DD80(X86Context& ctx, uint8_t* base) {
	// 0x29DD80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29DD88: movss [0x0056F51C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F51Cu, ctx.xmm[0].u32[0]);
	// 0x29DD90: ret
	return;
}

void sub_29DDA0(X86Context& ctx, uint8_t* base) {
	// 0x29DDA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29DDA8: movss [0x0056F4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4D0u, ctx.xmm[0].u32[0]);
	// 0x29DDB0: ret
	return;
}

void sub_29DDC0(X86Context& ctx, uint8_t* base) {
	// 0x29DDC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29DDC8: movss [0x0056F4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4E0u, ctx.xmm[0].u32[0]);
	// 0x29DDD0: ret
	return;
}

void sub_29DDE0(X86Context& ctx, uint8_t* base) {
	// 0x29DDE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29DDE8: movss [0x0056F534], xmm0
	X86_MEM_WRITE_u32(base, 0x56F534u, ctx.xmm[0].u32[0]);
	// 0x29DDF0: ret
	return;
}

void sub_29DE00(X86Context& ctx, uint8_t* base) {
	// 0x29DE00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29DE08: movss [0x0056F518], xmm0
	X86_MEM_WRITE_u32(base, 0x56F518u, ctx.xmm[0].u32[0]);
	// 0x29DE10: ret
	return;
}

void sub_29DE20(X86Context& ctx, uint8_t* base) {
	// 0x29DE20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29DE28: movss [0x0056F4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4C8u, ctx.xmm[0].u32[0]);
	// 0x29DE30: ret
	return;
}

void sub_29DE40(X86Context& ctx, uint8_t* base) {
	// 0x29DE40: movss xmm0, dword ptr [0x0056F4E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4E0u);
	// 0x29DE48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29DE50: movss [0x0056F4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4BCu, ctx.xmm[0].u32[0]);
	// 0x29DE58: ret
	return;
}

void sub_29DE60(X86Context& ctx, uint8_t* base) {
	// 0x29DE60: movss xmm0, dword ptr [0x0056F534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F534u);
	// 0x29DE68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29DE70: movss [0x0056F500], xmm0
	X86_MEM_WRITE_u32(base, 0x56F500u, ctx.xmm[0].u32[0]);
	// 0x29DE78: ret
	return;
}

void sub_29DE80(X86Context& ctx, uint8_t* base) {
	// 0x29DE80: movss xmm0, dword ptr [0x0056F4BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4BCu);
	// 0x29DE88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29DE90: movss [0x0056F510], xmm0
	X86_MEM_WRITE_u32(base, 0x56F510u, ctx.xmm[0].u32[0]);
	// 0x29DE98: ret
	return;
}

void sub_29DEA0(X86Context& ctx, uint8_t* base) {
	// 0x29DEA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29DEA8: movss [0x0056F4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4B4u, ctx.xmm[0].u32[0]);
	// 0x29DEB0: ret
	return;
}

void sub_29DEC0(X86Context& ctx, uint8_t* base) {
	// 0x29DEC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29DEC8: movss [0x0056F4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4E4u, ctx.xmm[0].u32[0]);
	// 0x29DED0: ret
	return;
}

void sub_29DEE0(X86Context& ctx, uint8_t* base) {
	// 0x29DEE0: movss xmm0, dword ptr [0x0056F4E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4E0u);
	// 0x29DEE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29DEF0: movss [0x0056F4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4F0u, ctx.xmm[0].u32[0]);
	// 0x29DEF8: ret
	return;
}

void sub_29DF00(X86Context& ctx, uint8_t* base) {
	// 0x29DF00: movss xmm0, dword ptr [0x0056F534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F534u);
	// 0x29DF08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29DF10: movss [0x0056F538], xmm0
	X86_MEM_WRITE_u32(base, 0x56F538u, ctx.xmm[0].u32[0]);
	// 0x29DF18: ret
	return;
}

void sub_29DF20(X86Context& ctx, uint8_t* base) {
	// 0x29DF20: movss xmm0, dword ptr [0x0056F4F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4F0u);
	// 0x29DF28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29DF30: movss [0x0056F524], xmm0
	X86_MEM_WRITE_u32(base, 0x56F524u, ctx.xmm[0].u32[0]);
	// 0x29DF38: ret
	return;
}

void sub_29DF40(X86Context& ctx, uint8_t* base) {
	// 0x29DF40: movss xmm0, dword ptr [0x0056F538]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F538u);
	// 0x29DF48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29DF50: movss [0x0056F548], xmm0
	X86_MEM_WRITE_u32(base, 0x56F548u, ctx.xmm[0].u32[0]);
	// 0x29DF58: ret
	return;
}

void sub_29DF60(X86Context& ctx, uint8_t* base) {
	// 0x29DF60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29DF68: movss [0x0056F4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4C0u, ctx.xmm[0].u32[0]);
	// 0x29DF70: ret
	return;
}

void sub_29DF80(X86Context& ctx, uint8_t* base) {
	// 0x29DF80: movss xmm0, dword ptr [0x0056F4E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4E0u);
	// 0x29DF88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29DF90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29DF98: movss [0x0056F530], xmm0
	X86_MEM_WRITE_u32(base, 0x56F530u, ctx.xmm[0].u32[0]);
	// 0x29DFA0: ret
	return;
}

void sub_29DFB0(X86Context& ctx, uint8_t* base) {
	// 0x29DFB0: movss xmm0, dword ptr [0x0056F534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F534u);
	// 0x29DFB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29DFC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29DFC8: movss [0x0056F4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4D8u, ctx.xmm[0].u32[0]);
	// 0x29DFD0: ret
	return;
}

void sub_29DFE0(X86Context& ctx, uint8_t* base) {
	// 0x29DFE0: movss xmm0, dword ptr [0x0056F4E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4E0u);
	// 0x29DFE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29DFF0: movss [0x0056F4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4DCu, ctx.xmm[0].u32[0]);
	// 0x29DFF8: ret
	return;
}

void sub_29E000(X86Context& ctx, uint8_t* base) {
	// 0x29E000: movss xmm0, dword ptr [0x0056F534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F534u);
	// 0x29E008: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E010: movss [0x0056F53C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F53Cu, ctx.xmm[0].u32[0]);
	// 0x29E018: ret
	return;
}

void sub_29E020(X86Context& ctx, uint8_t* base) {
	// 0x29E020: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29E028: movss [0x0056F4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4C4u, ctx.xmm[0].u32[0]);
	// 0x29E030: ret
	return;
}

void sub_29E040(X86Context& ctx, uint8_t* base) {
	// 0x29E040: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29E048: movss [0x0056F4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4ECu, ctx.xmm[0].u32[0]);
	// 0x29E050: ret
	return;
}

void sub_29E060(X86Context& ctx, uint8_t* base) {
	// 0x29E060: movss xmm0, dword ptr [0x0056F4C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4C4u);
	// 0x29E068: movss [0x0056F550], xmm0
	X86_MEM_WRITE_u32(base, 0x56F550u, ctx.xmm[0].u32[0]);
	// 0x29E070: ret
	return;
}

void sub_29E080(X86Context& ctx, uint8_t* base) {
	// 0x29E080: movss xmm0, dword ptr [0x0056F534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F534u);
	// 0x29E088: subss xmm0, [0x0056F4C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F4C4u);
	// 0x29E090: movss [0x0056F514], xmm0
	X86_MEM_WRITE_u32(base, 0x56F514u, ctx.xmm[0].u32[0]);
	// 0x29E098: ret
	return;
}

void sub_29E0A0(X86Context& ctx, uint8_t* base) {
	// 0x29E0A0: movss xmm0, dword ptr [0x0056F514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F514u);
	// 0x29E0A8: subss xmm0, [0x0056F4EC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F4ECu);
	// 0x29E0B0: movss [0x0056F50C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F50Cu, ctx.xmm[0].u32[0]);
	// 0x29E0B8: ret
	return;
}

void sub_29E0C0(X86Context& ctx, uint8_t* base) {
	// 0x29E0C0: movss xmm0, dword ptr [0x0056F53C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F53Cu);
	// 0x29E0C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29E0D0: movss [0x0056F4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4FCu, ctx.xmm[0].u32[0]);
	// 0x29E0D8: ret
	return;
}

void sub_29E0E0(X86Context& ctx, uint8_t* base) {
	// 0x29E0E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29E0E8: movss [0x0056F4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F4E8u, ctx.xmm[0].u32[0]);
	// 0x29E0F0: ret
	return;
}

void sub_29E100(X86Context& ctx, uint8_t* base) {
	// 0x29E100: movss xmm0, dword ptr [0x0056F4FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F4FCu);
	// 0x29E108: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29E110: movss [0x0056F52C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F52Cu, ctx.xmm[0].u32[0]);
	// 0x29E118: ret
	return;
}

void sub_29E120(X86Context& ctx, uint8_t* base) {
	// 0x29E120: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29E128: movss [0x0056F5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5BCu, ctx.xmm[0].u32[0]);
	// 0x29E130: ret
	return;
}

void sub_29E140(X86Context& ctx, uint8_t* base) {
	// 0x29E140: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29E148: movss [0x0056F5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5D8u, ctx.xmm[0].u32[0]);
	// 0x29E150: ret
	return;
}

void sub_29E160(X86Context& ctx, uint8_t* base) {
	// 0x29E160: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29E168: movss [0x0056F5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5ACu, ctx.xmm[0].u32[0]);
	// 0x29E170: ret
	return;
}

void sub_29E180(X86Context& ctx, uint8_t* base) {
	// 0x29E180: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29E188: movss [0x0056F55C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F55Cu, ctx.xmm[0].u32[0]);
	// 0x29E190: ret
	return;
}

void sub_29E1A0(X86Context& ctx, uint8_t* base) {
	// 0x29E1A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29E1A8: movss [0x0056F5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5C0u, ctx.xmm[0].u32[0]);
	// 0x29E1B0: ret
	return;
}

void sub_29E1C0(X86Context& ctx, uint8_t* base) {
	// 0x29E1C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29E1C8: movss [0x0056F578], xmm0
	X86_MEM_WRITE_u32(base, 0x56F578u, ctx.xmm[0].u32[0]);
	// 0x29E1D0: ret
	return;
}

void sub_29E1E0(X86Context& ctx, uint8_t* base) {
	// 0x29E1E0: movss xmm0, dword ptr [0x0056F5C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5C0u);
	// 0x29E1E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29E1F0: movss [0x0056F5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5F8u, ctx.xmm[0].u32[0]);
	// 0x29E1F8: ret
	return;
}

void sub_29E200(X86Context& ctx, uint8_t* base) {
	// 0x29E200: movss xmm0, dword ptr [0x0056F578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F578u);
	// 0x29E208: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29E210: movss [0x0056F5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5E0u, ctx.xmm[0].u32[0]);
	// 0x29E218: ret
	return;
}

void sub_29E220(X86Context& ctx, uint8_t* base) {
	// 0x29E220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29E228: movss [0x0056F610], xmm0
	X86_MEM_WRITE_u32(base, 0x56F610u, ctx.xmm[0].u32[0]);
	// 0x29E230: ret
	return;
}

void sub_29E240(X86Context& ctx, uint8_t* base) {
	// 0x29E240: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29E248: movss [0x0056F5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5FCu, ctx.xmm[0].u32[0]);
	// 0x29E250: ret
	return;
}

