#include "x86_recomp_shared.h"

void sub_29E260(X86Context& ctx, uint8_t* base) {
	// 0x29E260: movss xmm0, dword ptr [0x0056F5FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5FCu);
	// 0x29E268: movss [0x0056F60C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F60Cu, ctx.xmm[0].u32[0]);
	// 0x29E270: ret
	return;
}

void sub_29E280(X86Context& ctx, uint8_t* base) {
	// 0x29E280: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29E288: movss [0x0056F564], xmm0
	X86_MEM_WRITE_u32(base, 0x56F564u, ctx.xmm[0].u32[0]);
	// 0x29E290: ret
	return;
}

void sub_29E2A0(X86Context& ctx, uint8_t* base) {
	// 0x29E2A0: movss xmm0, dword ptr [0x0056F578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F578u);
	// 0x29E2A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29E2B0: movss [0x0056F604], xmm0
	X86_MEM_WRITE_u32(base, 0x56F604u, ctx.xmm[0].u32[0]);
	// 0x29E2B8: ret
	return;
}

void sub_29E2C0(X86Context& ctx, uint8_t* base) {
	// 0x29E2C0: movss xmm0, dword ptr [0x0056F578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F578u);
	// 0x29E2C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29E2D0: movss [0x0056F5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5A8u, ctx.xmm[0].u32[0]);
	// 0x29E2D8: ret
	return;
}

void sub_29E2E0(X86Context& ctx, uint8_t* base) {
	// 0x29E2E0: movss xmm0, dword ptr [0x0056F578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F578u);
	// 0x29E2E8: subss xmm0, [0x0056F5A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F5A8u);
	// 0x29E2F0: movss [0x0056F580], xmm0
	X86_MEM_WRITE_u32(base, 0x56F580u, ctx.xmm[0].u32[0]);
	// 0x29E2F8: ret
	return;
}

void sub_29E300(X86Context& ctx, uint8_t* base) {
	// 0x29E300: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29E308: movss [0x0056F5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5D4u, ctx.xmm[0].u32[0]);
	// 0x29E310: ret
	return;
}

void sub_29E320(X86Context& ctx, uint8_t* base) {
	// 0x29E320: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29E328: movss [0x0056F57C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F57Cu, ctx.xmm[0].u32[0]);
	// 0x29E330: ret
	return;
}

void sub_29E340(X86Context& ctx, uint8_t* base) {
	// 0x29E340: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29E348: movss [0x0056F590], xmm0
	X86_MEM_WRITE_u32(base, 0x56F590u, ctx.xmm[0].u32[0]);
	// 0x29E350: ret
	return;
}

void sub_29E360(X86Context& ctx, uint8_t* base) {
	// 0x29E360: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29E368: movss [0x0056F5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5ECu, ctx.xmm[0].u32[0]);
	// 0x29E370: ret
	return;
}

void sub_29E380(X86Context& ctx, uint8_t* base) {
	// 0x29E380: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29E388: movss [0x0056F5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5D0u, ctx.xmm[0].u32[0]);
	// 0x29E390: ret
	return;
}

void sub_29E3A0(X86Context& ctx, uint8_t* base) {
	// 0x29E3A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29E3A8: movss [0x0056F574], xmm0
	X86_MEM_WRITE_u32(base, 0x56F574u, ctx.xmm[0].u32[0]);
	// 0x29E3B0: ret
	return;
}

void sub_29E3C0(X86Context& ctx, uint8_t* base) {
	// 0x29E3C0: movss xmm0, dword ptr [0x0056F590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F590u);
	// 0x29E3C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29E3D0: movss [0x0056F568], xmm0
	X86_MEM_WRITE_u32(base, 0x56F568u, ctx.xmm[0].u32[0]);
	// 0x29E3D8: ret
	return;
}

void sub_29E3E0(X86Context& ctx, uint8_t* base) {
	// 0x29E3E0: movss xmm0, dword ptr [0x0056F5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5ECu);
	// 0x29E3E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29E3F0: movss [0x0056F5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5B4u, ctx.xmm[0].u32[0]);
	// 0x29E3F8: ret
	return;
}

void sub_29E400(X86Context& ctx, uint8_t* base) {
	// 0x29E400: movss xmm0, dword ptr [0x0056F568]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F568u);
	// 0x29E408: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29E410: movss [0x0056F5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5C8u, ctx.xmm[0].u32[0]);
	// 0x29E418: ret
	return;
}

void sub_29E420(X86Context& ctx, uint8_t* base) {
	// 0x29E420: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29E428: movss [0x0056F560], xmm0
	X86_MEM_WRITE_u32(base, 0x56F560u, ctx.xmm[0].u32[0]);
	// 0x29E430: ret
	return;
}

void sub_29E440(X86Context& ctx, uint8_t* base) {
	// 0x29E440: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29E448: movss [0x0056F594], xmm0
	X86_MEM_WRITE_u32(base, 0x56F594u, ctx.xmm[0].u32[0]);
	// 0x29E450: ret
	return;
}

void sub_29E460(X86Context& ctx, uint8_t* base) {
	// 0x29E460: movss xmm0, dword ptr [0x0056F590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F590u);
	// 0x29E468: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29E470: movss [0x0056F5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5A4u, ctx.xmm[0].u32[0]);
	// 0x29E478: ret
	return;
}

void sub_29E480(X86Context& ctx, uint8_t* base) {
	// 0x29E480: movss xmm0, dword ptr [0x0056F5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5ECu);
	// 0x29E488: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29E490: movss [0x0056F5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5F0u, ctx.xmm[0].u32[0]);
	// 0x29E498: ret
	return;
}

void sub_29E4A0(X86Context& ctx, uint8_t* base) {
	// 0x29E4A0: movss xmm0, dword ptr [0x0056F5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5A4u);
	// 0x29E4A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E4B0: movss [0x0056F5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5DCu, ctx.xmm[0].u32[0]);
	// 0x29E4B8: ret
	return;
}

void sub_29E4C0(X86Context& ctx, uint8_t* base) {
	// 0x29E4C0: movss xmm0, dword ptr [0x0056F5F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5F0u);
	// 0x29E4C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E4D0: movss [0x0056F600], xmm0
	X86_MEM_WRITE_u32(base, 0x56F600u, ctx.xmm[0].u32[0]);
	// 0x29E4D8: ret
	return;
}

void sub_29E4E0(X86Context& ctx, uint8_t* base) {
	// 0x29E4E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29E4E8: movss [0x0056F56C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F56Cu, ctx.xmm[0].u32[0]);
	// 0x29E4F0: ret
	return;
}

void sub_29E500(X86Context& ctx, uint8_t* base) {
	// 0x29E500: movss xmm0, dword ptr [0x0056F590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F590u);
	// 0x29E508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E510: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29E518: movss [0x0056F5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5E8u, ctx.xmm[0].u32[0]);
	// 0x29E520: ret
	return;
}

void sub_29E530(X86Context& ctx, uint8_t* base) {
	// 0x29E530: movss xmm0, dword ptr [0x0056F5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5ECu);
	// 0x29E538: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E540: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29E548: movss [0x0056F584], xmm0
	X86_MEM_WRITE_u32(base, 0x56F584u, ctx.xmm[0].u32[0]);
	// 0x29E550: ret
	return;
}

void sub_29E560(X86Context& ctx, uint8_t* base) {
	// 0x29E560: movss xmm0, dword ptr [0x0056F590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F590u);
	// 0x29E568: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E570: movss [0x0056F588], xmm0
	X86_MEM_WRITE_u32(base, 0x56F588u, ctx.xmm[0].u32[0]);
	// 0x29E578: ret
	return;
}

void sub_29E580(X86Context& ctx, uint8_t* base) {
	// 0x29E580: movss xmm0, dword ptr [0x0056F5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5ECu);
	// 0x29E588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29E590: movss [0x0056F5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5F4u, ctx.xmm[0].u32[0]);
	// 0x29E598: ret
	return;
}

void sub_29E5A0(X86Context& ctx, uint8_t* base) {
	// 0x29E5A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29E5A8: movss [0x0056F570], xmm0
	X86_MEM_WRITE_u32(base, 0x56F570u, ctx.xmm[0].u32[0]);
	// 0x29E5B0: ret
	return;
}

void sub_29E5C0(X86Context& ctx, uint8_t* base) {
	// 0x29E5C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29E5C8: movss [0x0056F5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5A0u, ctx.xmm[0].u32[0]);
	// 0x29E5D0: ret
	return;
}

void sub_29E5E0(X86Context& ctx, uint8_t* base) {
	// 0x29E5E0: movss xmm0, dword ptr [0x0056F570]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F570u);
	// 0x29E5E8: movss [0x0056F608], xmm0
	X86_MEM_WRITE_u32(base, 0x56F608u, ctx.xmm[0].u32[0]);
	// 0x29E5F0: ret
	return;
}

void sub_29E600(X86Context& ctx, uint8_t* base) {
	// 0x29E600: movss xmm0, dword ptr [0x0056F5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5ECu);
	// 0x29E608: subss xmm0, [0x0056F570]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F570u);
	// 0x29E610: movss [0x0056F5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5CCu, ctx.xmm[0].u32[0]);
	// 0x29E618: ret
	return;
}

void sub_29E620(X86Context& ctx, uint8_t* base) {
	// 0x29E620: movss xmm0, dword ptr [0x0056F5CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5CCu);
	// 0x29E628: subss xmm0, [0x0056F5A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F5A0u);
	// 0x29E630: movss [0x0056F5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5C4u, ctx.xmm[0].u32[0]);
	// 0x29E638: ret
	return;
}

void sub_29E640(X86Context& ctx, uint8_t* base) {
	// 0x29E640: movss xmm0, dword ptr [0x0056F5F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5F4u);
	// 0x29E648: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29E650: movss [0x0056F5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5B0u, ctx.xmm[0].u32[0]);
	// 0x29E658: ret
	return;
}

void sub_29E660(X86Context& ctx, uint8_t* base) {
	// 0x29E660: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29E668: movss [0x0056F59C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F59Cu, ctx.xmm[0].u32[0]);
	// 0x29E670: ret
	return;
}

void sub_29E680(X86Context& ctx, uint8_t* base) {
	// 0x29E680: movss xmm0, dword ptr [0x0056F5B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F5B0u);
	// 0x29E688: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29E690: movss [0x0056F5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5E4u, ctx.xmm[0].u32[0]);
	// 0x29E698: ret
	return;
}

void sub_29E6A0(X86Context& ctx, uint8_t* base) {
	// 0x29E6A0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x29E6A8: movss [0x0056F5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F5B8u, ctx.xmm[0].u32[0]);
	// 0x29E6B0: ret
	return;
}

void sub_29E6C0(X86Context& ctx, uint8_t* base) {
	// 0x29E6C0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29E6C8: movss [0x0056F58C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F58Cu, ctx.xmm[0].u32[0]);
	// 0x29E6D0: ret
	return;
}

void sub_29E6E0(X86Context& ctx, uint8_t* base) {
	// 0x29E6E0: movss xmm0, dword ptr [0x0056F590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F590u);
	// 0x29E6E8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29E6F0: movss [0x00405E90], xmm0
	X86_MEM_WRITE_u32(base, 0x405E90u, ctx.xmm[0].u32[0]);
	// 0x29E6F8: ret
	return;
}

void sub_29E700(X86Context& ctx, uint8_t* base) {
	// 0x29E700: movss xmm0, dword ptr [0x0056F590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F590u);
	// 0x29E708: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29E710: movss [0x00405EB0], xmm0
	X86_MEM_WRITE_u32(base, 0x405EB0u, ctx.xmm[0].u32[0]);
	// 0x29E718: ret
	return;
}

void sub_29E720(X86Context& ctx, uint8_t* base) {
	// 0x29E720: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x29E728: movss [0x0056F598], xmm0
	X86_MEM_WRITE_u32(base, 0x56F598u, ctx.xmm[0].u32[0]);
	// 0x29E730: ret
	return;
}

void sub_29E740(X86Context& ctx, uint8_t* base) {
	// 0x29E740: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29E748: movss [0x0056F670], xmm0
	X86_MEM_WRITE_u32(base, 0x56F670u, ctx.xmm[0].u32[0]);
	// 0x29E750: ret
	return;
}

void sub_29E760(X86Context& ctx, uint8_t* base) {
	// 0x29E760: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29E768: movss [0x0056F68C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F68Cu, ctx.xmm[0].u32[0]);
	// 0x29E770: ret
	return;
}

void sub_29E780(X86Context& ctx, uint8_t* base) {
	// 0x29E780: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29E788: movss [0x0056F660], xmm0
	X86_MEM_WRITE_u32(base, 0x56F660u, ctx.xmm[0].u32[0]);
	// 0x29E790: ret
	return;
}

void sub_29E7A0(X86Context& ctx, uint8_t* base) {
	// 0x29E7A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29E7A8: movss [0x0056F614], xmm0
	X86_MEM_WRITE_u32(base, 0x56F614u, ctx.xmm[0].u32[0]);
	// 0x29E7B0: ret
	return;
}

void sub_29E7C0(X86Context& ctx, uint8_t* base) {
	// 0x29E7C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29E7C8: movss [0x0056F674], xmm0
	X86_MEM_WRITE_u32(base, 0x56F674u, ctx.xmm[0].u32[0]);
	// 0x29E7D0: ret
	return;
}

void sub_29E7E0(X86Context& ctx, uint8_t* base) {
	// 0x29E7E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29E7E8: movss [0x0056F630], xmm0
	X86_MEM_WRITE_u32(base, 0x56F630u, ctx.xmm[0].u32[0]);
	// 0x29E7F0: ret
	return;
}

void sub_29E800(X86Context& ctx, uint8_t* base) {
	// 0x29E800: movss xmm0, dword ptr [0x0056F674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F674u);
	// 0x29E808: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29E810: movss [0x0056F6AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6ACu, ctx.xmm[0].u32[0]);
	// 0x29E818: ret
	return;
}

void sub_29E820(X86Context& ctx, uint8_t* base) {
	// 0x29E820: movss xmm0, dword ptr [0x0056F630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F630u);
	// 0x29E828: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29E830: movss [0x0056F694], xmm0
	X86_MEM_WRITE_u32(base, 0x56F694u, ctx.xmm[0].u32[0]);
	// 0x29E838: ret
	return;
}

void sub_29E840(X86Context& ctx, uint8_t* base) {
	// 0x29E840: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29E848: movss [0x0056F6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6C8u, ctx.xmm[0].u32[0]);
	// 0x29E850: ret
	return;
}

void sub_29E860(X86Context& ctx, uint8_t* base) {
	// 0x29E860: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29E868: movss [0x0056F6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6B0u, ctx.xmm[0].u32[0]);
	// 0x29E870: ret
	return;
}

void sub_29E880(X86Context& ctx, uint8_t* base) {
	// 0x29E880: movss xmm0, dword ptr [0x0056F6B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6B0u);
	// 0x29E888: movss [0x0056F6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6C0u, ctx.xmm[0].u32[0]);
	// 0x29E890: ret
	return;
}

void sub_29E8A0(X86Context& ctx, uint8_t* base) {
	// 0x29E8A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29E8A8: movss [0x0056F61C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F61Cu, ctx.xmm[0].u32[0]);
	// 0x29E8B0: ret
	return;
}

void sub_29E8C0(X86Context& ctx, uint8_t* base) {
	// 0x29E8C0: movss xmm0, dword ptr [0x0056F630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F630u);
	// 0x29E8C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29E8D0: movss [0x0056F6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6B8u, ctx.xmm[0].u32[0]);
	// 0x29E8D8: ret
	return;
}

void sub_29E8E0(X86Context& ctx, uint8_t* base) {
	// 0x29E8E0: movss xmm0, dword ptr [0x0056F630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F630u);
	// 0x29E8E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29E8F0: movss [0x0056F65C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F65Cu, ctx.xmm[0].u32[0]);
	// 0x29E8F8: ret
	return;
}

void sub_29E900(X86Context& ctx, uint8_t* base) {
	// 0x29E900: movss xmm0, dword ptr [0x0056F630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F630u);
	// 0x29E908: subss xmm0, [0x0056F65C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F65Cu);
	// 0x29E910: movss [0x0056F638], xmm0
	X86_MEM_WRITE_u32(base, 0x56F638u, ctx.xmm[0].u32[0]);
	// 0x29E918: ret
	return;
}

void sub_29E920(X86Context& ctx, uint8_t* base) {
	// 0x29E920: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29E928: movss [0x0056F688], xmm0
	X86_MEM_WRITE_u32(base, 0x56F688u, ctx.xmm[0].u32[0]);
	// 0x29E930: ret
	return;
}

void sub_29E940(X86Context& ctx, uint8_t* base) {
	// 0x29E940: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29E948: movss [0x0056F634], xmm0
	X86_MEM_WRITE_u32(base, 0x56F634u, ctx.xmm[0].u32[0]);
	// 0x29E950: ret
	return;
}

void sub_29E960(X86Context& ctx, uint8_t* base) {
	// 0x29E960: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29E968: movss [0x0056F648], xmm0
	X86_MEM_WRITE_u32(base, 0x56F648u, ctx.xmm[0].u32[0]);
	// 0x29E970: ret
	return;
}

void sub_29E980(X86Context& ctx, uint8_t* base) {
	// 0x29E980: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29E988: movss [0x0056F6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6A0u, ctx.xmm[0].u32[0]);
	// 0x29E990: ret
	return;
}

void sub_29E9A0(X86Context& ctx, uint8_t* base) {
	// 0x29E9A0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29E9A8: movss [0x0056F684], xmm0
	X86_MEM_WRITE_u32(base, 0x56F684u, ctx.xmm[0].u32[0]);
	// 0x29E9B0: ret
	return;
}

void sub_29E9C0(X86Context& ctx, uint8_t* base) {
	// 0x29E9C0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29E9C8: movss [0x0056F62C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F62Cu, ctx.xmm[0].u32[0]);
	// 0x29E9D0: ret
	return;
}

void sub_29E9E0(X86Context& ctx, uint8_t* base) {
	// 0x29E9E0: movss xmm0, dword ptr [0x0056F648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F648u);
	// 0x29E9E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29E9F0: movss [0x0056F620], xmm0
	X86_MEM_WRITE_u32(base, 0x56F620u, ctx.xmm[0].u32[0]);
	// 0x29E9F8: ret
	return;
}

void sub_29EA00(X86Context& ctx, uint8_t* base) {
	// 0x29EA00: movss xmm0, dword ptr [0x0056F6A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A0u);
	// 0x29EA08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29EA10: movss [0x0056F668], xmm0
	X86_MEM_WRITE_u32(base, 0x56F668u, ctx.xmm[0].u32[0]);
	// 0x29EA18: ret
	return;
}

void sub_29EA20(X86Context& ctx, uint8_t* base) {
	// 0x29EA20: movss xmm0, dword ptr [0x0056F620]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F620u);
	// 0x29EA28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29EA30: movss [0x0056F67C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F67Cu, ctx.xmm[0].u32[0]);
	// 0x29EA38: ret
	return;
}

void sub_29EA40(X86Context& ctx, uint8_t* base) {
	// 0x29EA40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29EA48: movss [0x0056F618], xmm0
	X86_MEM_WRITE_u32(base, 0x56F618u, ctx.xmm[0].u32[0]);
	// 0x29EA50: ret
	return;
}

void sub_29EA60(X86Context& ctx, uint8_t* base) {
	// 0x29EA60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29EA68: movss [0x0056F64C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F64Cu, ctx.xmm[0].u32[0]);
	// 0x29EA70: ret
	return;
}

void sub_29EA80(X86Context& ctx, uint8_t* base) {
	// 0x29EA80: movss xmm0, dword ptr [0x0056F648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F648u);
	// 0x29EA88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29EA90: movss [0x0056F658], xmm0
	X86_MEM_WRITE_u32(base, 0x56F658u, ctx.xmm[0].u32[0]);
	// 0x29EA98: ret
	return;
}

void sub_29EAA0(X86Context& ctx, uint8_t* base) {
	// 0x29EAA0: movss xmm0, dword ptr [0x0056F6A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A0u);
	// 0x29EAA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29EAB0: movss [0x0056F6A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6A4u, ctx.xmm[0].u32[0]);
	// 0x29EAB8: ret
	return;
}

void sub_29EAC0(X86Context& ctx, uint8_t* base) {
	// 0x29EAC0: movss xmm0, dword ptr [0x0056F658]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F658u);
	// 0x29EAC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29EAD0: movss [0x0056F690], xmm0
	X86_MEM_WRITE_u32(base, 0x56F690u, ctx.xmm[0].u32[0]);
	// 0x29EAD8: ret
	return;
}

void sub_29EAE0(X86Context& ctx, uint8_t* base) {
	// 0x29EAE0: movss xmm0, dword ptr [0x0056F6A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A4u);
	// 0x29EAE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29EAF0: movss [0x0056F6B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6B4u, ctx.xmm[0].u32[0]);
	// 0x29EAF8: ret
	return;
}

void sub_29EB00(X86Context& ctx, uint8_t* base) {
	// 0x29EB00: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29EB08: movss [0x0056F624], xmm0
	X86_MEM_WRITE_u32(base, 0x56F624u, ctx.xmm[0].u32[0]);
	// 0x29EB10: ret
	return;
}

void sub_29EB20(X86Context& ctx, uint8_t* base) {
	// 0x29EB20: movss xmm0, dword ptr [0x0056F648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F648u);
	// 0x29EB28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29EB30: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29EB38: movss [0x0056F69C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F69Cu, ctx.xmm[0].u32[0]);
	// 0x29EB40: ret
	return;
}

void sub_29EB50(X86Context& ctx, uint8_t* base) {
	// 0x29EB50: movss xmm0, dword ptr [0x0056F6A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A0u);
	// 0x29EB58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29EB60: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29EB68: movss [0x0056F63C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F63Cu, ctx.xmm[0].u32[0]);
	// 0x29EB70: ret
	return;
}

void sub_29EB80(X86Context& ctx, uint8_t* base) {
	// 0x29EB80: movss xmm0, dword ptr [0x0056F648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F648u);
	// 0x29EB88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29EB90: movss [0x0056F640], xmm0
	X86_MEM_WRITE_u32(base, 0x56F640u, ctx.xmm[0].u32[0]);
	// 0x29EB98: ret
	return;
}

void sub_29EBA0(X86Context& ctx, uint8_t* base) {
	// 0x29EBA0: movss xmm0, dword ptr [0x0056F6A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A0u);
	// 0x29EBA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29EBB0: movss [0x0056F6A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6A8u, ctx.xmm[0].u32[0]);
	// 0x29EBB8: ret
	return;
}

void sub_29EBC0(X86Context& ctx, uint8_t* base) {
	// 0x29EBC0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29EBC8: movss [0x0056F628], xmm0
	X86_MEM_WRITE_u32(base, 0x56F628u, ctx.xmm[0].u32[0]);
	// 0x29EBD0: ret
	return;
}

void sub_29EBE0(X86Context& ctx, uint8_t* base) {
	// 0x29EBE0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29EBE8: movss [0x0056F654], xmm0
	X86_MEM_WRITE_u32(base, 0x56F654u, ctx.xmm[0].u32[0]);
	// 0x29EBF0: ret
	return;
}

void sub_29EC00(X86Context& ctx, uint8_t* base) {
	// 0x29EC00: movss xmm0, dword ptr [0x0056F628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F628u);
	// 0x29EC08: movss [0x0056F6BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6BCu, ctx.xmm[0].u32[0]);
	// 0x29EC10: ret
	return;
}

void sub_29EC20(X86Context& ctx, uint8_t* base) {
	// 0x29EC20: movss xmm0, dword ptr [0x0056F6A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A0u);
	// 0x29EC28: subss xmm0, [0x0056F628]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F628u);
	// 0x29EC30: movss [0x0056F680], xmm0
	X86_MEM_WRITE_u32(base, 0x56F680u, ctx.xmm[0].u32[0]);
	// 0x29EC38: ret
	return;
}

void sub_29EC40(X86Context& ctx, uint8_t* base) {
	// 0x29EC40: movss xmm0, dword ptr [0x0056F680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F680u);
	// 0x29EC48: subss xmm0, [0x0056F654]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F654u);
	// 0x29EC50: movss [0x0056F678], xmm0
	X86_MEM_WRITE_u32(base, 0x56F678u, ctx.xmm[0].u32[0]);
	// 0x29EC58: ret
	return;
}

void sub_29EC60(X86Context& ctx, uint8_t* base) {
	// 0x29EC60: movss xmm0, dword ptr [0x0056F6A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6A8u);
	// 0x29EC68: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29EC70: movss [0x0056F664], xmm0
	X86_MEM_WRITE_u32(base, 0x56F664u, ctx.xmm[0].u32[0]);
	// 0x29EC78: ret
	return;
}

void sub_29EC80(X86Context& ctx, uint8_t* base) {
	// 0x29EC80: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29EC88: movss [0x0056F650], xmm0
	X86_MEM_WRITE_u32(base, 0x56F650u, ctx.xmm[0].u32[0]);
	// 0x29EC90: ret
	return;
}

void sub_29ECA0(X86Context& ctx, uint8_t* base) {
	// 0x29ECA0: movss xmm0, dword ptr [0x0056F664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F664u);
	// 0x29ECA8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29ECB0: movss [0x0056F698], xmm0
	X86_MEM_WRITE_u32(base, 0x56F698u, ctx.xmm[0].u32[0]);
	// 0x29ECB8: ret
	return;
}

void sub_29ECC0(X86Context& ctx, uint8_t* base) {
	// 0x29ECC0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x29ECC8: movss [0x0056F66C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F66Cu, ctx.xmm[0].u32[0]);
	// 0x29ECD0: ret
	return;
}

void sub_29ECE0(X86Context& ctx, uint8_t* base) {
	// 0x29ECE0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29ECE8: movss [0x0056F644], xmm0
	X86_MEM_WRITE_u32(base, 0x56F644u, ctx.xmm[0].u32[0]);
	// 0x29ECF0: ret
	return;
}

void sub_29ED00(X86Context& ctx, uint8_t* base) {
	// 0x29ED00: movss xmm0, dword ptr [0x003B1FAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1FACu);
	// 0x29ED08: movss [0x0056F6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6C4u, ctx.xmm[0].u32[0]);
	// 0x29ED10: ret
	return;
}

void sub_29ED20(X86Context& ctx, uint8_t* base) {
	// 0x29ED20: movss xmm0, dword ptr [0x0056F648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F648u);
	// 0x29ED28: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29ED30: movss [0x00405F70], xmm0
	X86_MEM_WRITE_u32(base, 0x405F70u, ctx.xmm[0].u32[0]);
	// 0x29ED38: ret
	return;
}

void sub_29ED40(X86Context& ctx, uint8_t* base) {
	// 0x29ED40: movss xmm0, dword ptr [0x0056F648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F648u);
	// 0x29ED48: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29ED50: movss [0x00405F90], xmm0
	X86_MEM_WRITE_u32(base, 0x405F90u, ctx.xmm[0].u32[0]);
	// 0x29ED58: ret
	return;
}

void sub_29ED60(X86Context& ctx, uint8_t* base) {
	// 0x29ED60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29ED68: movss [0x0056F720], xmm0
	X86_MEM_WRITE_u32(base, 0x56F720u, ctx.xmm[0].u32[0]);
	// 0x29ED70: ret
	return;
}

void sub_29ED80(X86Context& ctx, uint8_t* base) {
	// 0x29ED80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29ED88: movss [0x0056F73C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F73Cu, ctx.xmm[0].u32[0]);
	// 0x29ED90: ret
	return;
}

void sub_29EDA0(X86Context& ctx, uint8_t* base) {
	// 0x29EDA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29EDA8: movss [0x0056F714], xmm0
	X86_MEM_WRITE_u32(base, 0x56F714u, ctx.xmm[0].u32[0]);
	// 0x29EDB0: ret
	return;
}

void sub_29EDC0(X86Context& ctx, uint8_t* base) {
	// 0x29EDC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29EDC8: movss [0x0056F6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6CCu, ctx.xmm[0].u32[0]);
	// 0x29EDD0: ret
	return;
}

void sub_29EDE0(X86Context& ctx, uint8_t* base) {
	// 0x29EDE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29EDE8: movss [0x0056F724], xmm0
	X86_MEM_WRITE_u32(base, 0x56F724u, ctx.xmm[0].u32[0]);
	// 0x29EDF0: ret
	return;
}

void sub_29EE00(X86Context& ctx, uint8_t* base) {
	// 0x29EE00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29EE08: movss [0x0056F6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6E8u, ctx.xmm[0].u32[0]);
	// 0x29EE10: ret
	return;
}

void sub_29EE20(X86Context& ctx, uint8_t* base) {
	// 0x29EE20: movss xmm0, dword ptr [0x0056F724]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F724u);
	// 0x29EE28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29EE30: movss [0x0056F75C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F75Cu, ctx.xmm[0].u32[0]);
	// 0x29EE38: ret
	return;
}

void sub_29EE40(X86Context& ctx, uint8_t* base) {
	// 0x29EE40: movss xmm0, dword ptr [0x0056F6E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6E8u);
	// 0x29EE48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29EE50: movss [0x0056F744], xmm0
	X86_MEM_WRITE_u32(base, 0x56F744u, ctx.xmm[0].u32[0]);
	// 0x29EE58: ret
	return;
}

void sub_29EE60(X86Context& ctx, uint8_t* base) {
	// 0x29EE60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29EE68: movss [0x0056F774], xmm0
	X86_MEM_WRITE_u32(base, 0x56F774u, ctx.xmm[0].u32[0]);
	// 0x29EE70: ret
	return;
}

void sub_29EE80(X86Context& ctx, uint8_t* base) {
	// 0x29EE80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29EE88: movss [0x0056F760], xmm0
	X86_MEM_WRITE_u32(base, 0x56F760u, ctx.xmm[0].u32[0]);
	// 0x29EE90: ret
	return;
}

void sub_29EEA0(X86Context& ctx, uint8_t* base) {
	// 0x29EEA0: movss xmm0, dword ptr [0x0056F760]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F760u);
	// 0x29EEA8: movss [0x0056F770], xmm0
	X86_MEM_WRITE_u32(base, 0x56F770u, ctx.xmm[0].u32[0]);
	// 0x29EEB0: ret
	return;
}

void sub_29EEC0(X86Context& ctx, uint8_t* base) {
	// 0x29EEC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29EEC8: movss [0x0056F6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6D4u, ctx.xmm[0].u32[0]);
	// 0x29EED0: ret
	return;
}

void sub_29EEE0(X86Context& ctx, uint8_t* base) {
	// 0x29EEE0: movss xmm0, dword ptr [0x0056F6E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6E8u);
	// 0x29EEE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29EEF0: movss [0x0056F768], xmm0
	X86_MEM_WRITE_u32(base, 0x56F768u, ctx.xmm[0].u32[0]);
	// 0x29EEF8: ret
	return;
}

void sub_29EF00(X86Context& ctx, uint8_t* base) {
	// 0x29EF00: movss xmm0, dword ptr [0x0056F6E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6E8u);
	// 0x29EF08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29EF10: movss [0x0056F710], xmm0
	X86_MEM_WRITE_u32(base, 0x56F710u, ctx.xmm[0].u32[0]);
	// 0x29EF18: ret
	return;
}

void sub_29EF20(X86Context& ctx, uint8_t* base) {
	// 0x29EF20: movss xmm0, dword ptr [0x0056F6E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6E8u);
	// 0x29EF28: subss xmm0, [0x0056F710]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F710u);
	// 0x29EF30: movss [0x0056F6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6F0u, ctx.xmm[0].u32[0]);
	// 0x29EF38: ret
	return;
}

void sub_29EF40(X86Context& ctx, uint8_t* base) {
	// 0x29EF40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29EF48: movss [0x0056F738], xmm0
	X86_MEM_WRITE_u32(base, 0x56F738u, ctx.xmm[0].u32[0]);
	// 0x29EF50: ret
	return;
}

void sub_29EF60(X86Context& ctx, uint8_t* base) {
	// 0x29EF60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29EF68: movss [0x0056F6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6ECu, ctx.xmm[0].u32[0]);
	// 0x29EF70: ret
	return;
}

void sub_29EF80(X86Context& ctx, uint8_t* base) {
	// 0x29EF80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29EF88: movss [0x0056F6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6FCu, ctx.xmm[0].u32[0]);
	// 0x29EF90: ret
	return;
}

void sub_29EFA0(X86Context& ctx, uint8_t* base) {
	// 0x29EFA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29EFA8: movss [0x0056F750], xmm0
	X86_MEM_WRITE_u32(base, 0x56F750u, ctx.xmm[0].u32[0]);
	// 0x29EFB0: ret
	return;
}

void sub_29EFC0(X86Context& ctx, uint8_t* base) {
	// 0x29EFC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29EFC8: movss [0x0056F734], xmm0
	X86_MEM_WRITE_u32(base, 0x56F734u, ctx.xmm[0].u32[0]);
	// 0x29EFD0: ret
	return;
}

void sub_29EFE0(X86Context& ctx, uint8_t* base) {
	// 0x29EFE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29EFE8: movss [0x0056F6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6E4u, ctx.xmm[0].u32[0]);
	// 0x29EFF0: ret
	return;
}

void sub_29F000(X86Context& ctx, uint8_t* base) {
	// 0x29F000: movss xmm0, dword ptr [0x0056F6FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6FCu);
	// 0x29F008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29F010: movss [0x0056F6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6D8u, ctx.xmm[0].u32[0]);
	// 0x29F018: ret
	return;
}

void sub_29F020(X86Context& ctx, uint8_t* base) {
	// 0x29F020: movss xmm0, dword ptr [0x0056F750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F750u);
	// 0x29F028: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29F030: movss [0x0056F71C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F71Cu, ctx.xmm[0].u32[0]);
	// 0x29F038: ret
	return;
}

void sub_29F040(X86Context& ctx, uint8_t* base) {
	// 0x29F040: movss xmm0, dword ptr [0x0056F6D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6D8u);
	// 0x29F048: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29F050: movss [0x0056F72C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F72Cu, ctx.xmm[0].u32[0]);
	// 0x29F058: ret
	return;
}

void sub_29F060(X86Context& ctx, uint8_t* base) {
	// 0x29F060: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29F068: movss [0x0056F6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6D0u, ctx.xmm[0].u32[0]);
	// 0x29F070: ret
	return;
}

void sub_29F080(X86Context& ctx, uint8_t* base) {
	// 0x29F080: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29F088: movss [0x0056F700], xmm0
	X86_MEM_WRITE_u32(base, 0x56F700u, ctx.xmm[0].u32[0]);
	// 0x29F090: ret
	return;
}

void sub_29F0A0(X86Context& ctx, uint8_t* base) {
	// 0x29F0A0: movss xmm0, dword ptr [0x0056F6FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6FCu);
	// 0x29F0A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29F0B0: movss [0x0056F70C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F70Cu, ctx.xmm[0].u32[0]);
	// 0x29F0B8: ret
	return;
}

void sub_29F0C0(X86Context& ctx, uint8_t* base) {
	// 0x29F0C0: movss xmm0, dword ptr [0x0056F750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F750u);
	// 0x29F0C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29F0D0: movss [0x0056F754], xmm0
	X86_MEM_WRITE_u32(base, 0x56F754u, ctx.xmm[0].u32[0]);
	// 0x29F0D8: ret
	return;
}

void sub_29F0E0(X86Context& ctx, uint8_t* base) {
	// 0x29F0E0: movss xmm0, dword ptr [0x0056F70C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F70Cu);
	// 0x29F0E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F0F0: movss [0x0056F740], xmm0
	X86_MEM_WRITE_u32(base, 0x56F740u, ctx.xmm[0].u32[0]);
	// 0x29F0F8: ret
	return;
}

void sub_29F100(X86Context& ctx, uint8_t* base) {
	// 0x29F100: movss xmm0, dword ptr [0x0056F754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F754u);
	// 0x29F108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F110: movss [0x0056F764], xmm0
	X86_MEM_WRITE_u32(base, 0x56F764u, ctx.xmm[0].u32[0]);
	// 0x29F118: ret
	return;
}

void sub_29F120(X86Context& ctx, uint8_t* base) {
	// 0x29F120: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29F128: movss [0x0056F6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6DCu, ctx.xmm[0].u32[0]);
	// 0x29F130: ret
	return;
}

void sub_29F140(X86Context& ctx, uint8_t* base) {
	// 0x29F140: movss xmm0, dword ptr [0x0056F6FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6FCu);
	// 0x29F148: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F150: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29F158: movss [0x0056F74C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F74Cu, ctx.xmm[0].u32[0]);
	// 0x29F160: ret
	return;
}

void sub_29F170(X86Context& ctx, uint8_t* base) {
	// 0x29F170: movss xmm0, dword ptr [0x0056F750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F750u);
	// 0x29F178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F180: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29F188: movss [0x0056F6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6F4u, ctx.xmm[0].u32[0]);
	// 0x29F190: ret
	return;
}

void sub_29F1A0(X86Context& ctx, uint8_t* base) {
	// 0x29F1A0: movss xmm0, dword ptr [0x0056F6FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6FCu);
	// 0x29F1A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F1B0: movss [0x0056F6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6F8u, ctx.xmm[0].u32[0]);
	// 0x29F1B8: ret
	return;
}

void sub_29F1C0(X86Context& ctx, uint8_t* base) {
	// 0x29F1C0: movss xmm0, dword ptr [0x0056F750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F750u);
	// 0x29F1C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F1D0: movss [0x0056F758], xmm0
	X86_MEM_WRITE_u32(base, 0x56F758u, ctx.xmm[0].u32[0]);
	// 0x29F1D8: ret
	return;
}

void sub_29F1E0(X86Context& ctx, uint8_t* base) {
	// 0x29F1E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29F1E8: movss [0x0056F6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F6E0u, ctx.xmm[0].u32[0]);
	// 0x29F1F0: ret
	return;
}

void sub_29F200(X86Context& ctx, uint8_t* base) {
	// 0x29F200: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29F208: movss [0x0056F708], xmm0
	X86_MEM_WRITE_u32(base, 0x56F708u, ctx.xmm[0].u32[0]);
	// 0x29F210: ret
	return;
}

void sub_29F220(X86Context& ctx, uint8_t* base) {
	// 0x29F220: movss xmm0, dword ptr [0x0056F6E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F6E0u);
	// 0x29F228: movss [0x0056F76C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F76Cu, ctx.xmm[0].u32[0]);
	// 0x29F230: ret
	return;
}

void sub_29F240(X86Context& ctx, uint8_t* base) {
	// 0x29F240: movss xmm0, dword ptr [0x0056F750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F750u);
	// 0x29F248: subss xmm0, [0x0056F6E0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F6E0u);
	// 0x29F250: movss [0x0056F730], xmm0
	X86_MEM_WRITE_u32(base, 0x56F730u, ctx.xmm[0].u32[0]);
	// 0x29F258: ret
	return;
}

void sub_29F260(X86Context& ctx, uint8_t* base) {
	// 0x29F260: movss xmm0, dword ptr [0x0056F730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F730u);
	// 0x29F268: subss xmm0, [0x0056F708]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F708u);
	// 0x29F270: movss [0x0056F728], xmm0
	X86_MEM_WRITE_u32(base, 0x56F728u, ctx.xmm[0].u32[0]);
	// 0x29F278: ret
	return;
}

void sub_29F280(X86Context& ctx, uint8_t* base) {
	// 0x29F280: movss xmm0, dword ptr [0x0056F758]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F758u);
	// 0x29F288: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29F290: movss [0x0056F718], xmm0
	X86_MEM_WRITE_u32(base, 0x56F718u, ctx.xmm[0].u32[0]);
	// 0x29F298: ret
	return;
}

void sub_29F2A0(X86Context& ctx, uint8_t* base) {
	// 0x29F2A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29F2A8: movss [0x0056F704], xmm0
	X86_MEM_WRITE_u32(base, 0x56F704u, ctx.xmm[0].u32[0]);
	// 0x29F2B0: ret
	return;
}

void sub_29F2C0(X86Context& ctx, uint8_t* base) {
	// 0x29F2C0: movss xmm0, dword ptr [0x0056F718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F718u);
	// 0x29F2C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29F2D0: movss [0x0056F748], xmm0
	X86_MEM_WRITE_u32(base, 0x56F748u, ctx.xmm[0].u32[0]);
	// 0x29F2D8: ret
	return;
}

void sub_29F2E0(X86Context& ctx, uint8_t* base) {
	// 0x29F2E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29F2E8: movss [0x0056F7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7CCu, ctx.xmm[0].u32[0]);
	// 0x29F2F0: ret
	return;
}

void sub_29F300(X86Context& ctx, uint8_t* base) {
	// 0x29F300: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29F308: movss [0x0056F7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7E8u, ctx.xmm[0].u32[0]);
	// 0x29F310: ret
	return;
}

void sub_29F320(X86Context& ctx, uint8_t* base) {
	// 0x29F320: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29F328: movss [0x0056F7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7C0u, ctx.xmm[0].u32[0]);
	// 0x29F330: ret
	return;
}

void sub_29F340(X86Context& ctx, uint8_t* base) {
	// 0x29F340: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29F348: movss [0x0056F778], xmm0
	X86_MEM_WRITE_u32(base, 0x56F778u, ctx.xmm[0].u32[0]);
	// 0x29F350: ret
	return;
}

void sub_29F360(X86Context& ctx, uint8_t* base) {
	// 0x29F360: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29F368: movss [0x0056F7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7D0u, ctx.xmm[0].u32[0]);
	// 0x29F370: ret
	return;
}

void sub_29F380(X86Context& ctx, uint8_t* base) {
	// 0x29F380: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29F388: movss [0x0056F794], xmm0
	X86_MEM_WRITE_u32(base, 0x56F794u, ctx.xmm[0].u32[0]);
	// 0x29F390: ret
	return;
}

void sub_29F3A0(X86Context& ctx, uint8_t* base) {
	// 0x29F3A0: movss xmm0, dword ptr [0x0056F7D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7D0u);
	// 0x29F3A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29F3B0: movss [0x0056F808], xmm0
	X86_MEM_WRITE_u32(base, 0x56F808u, ctx.xmm[0].u32[0]);
	// 0x29F3B8: ret
	return;
}

void sub_29F3C0(X86Context& ctx, uint8_t* base) {
	// 0x29F3C0: movss xmm0, dword ptr [0x0056F794]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F794u);
	// 0x29F3C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29F3D0: movss [0x0056F7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7F0u, ctx.xmm[0].u32[0]);
	// 0x29F3D8: ret
	return;
}

void sub_29F3E0(X86Context& ctx, uint8_t* base) {
	// 0x29F3E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29F3E8: movss [0x0056F820], xmm0
	X86_MEM_WRITE_u32(base, 0x56F820u, ctx.xmm[0].u32[0]);
	// 0x29F3F0: ret
	return;
}

void sub_29F400(X86Context& ctx, uint8_t* base) {
	// 0x29F400: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29F408: movss [0x0056F80C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F80Cu, ctx.xmm[0].u32[0]);
	// 0x29F410: ret
	return;
}

void sub_29F420(X86Context& ctx, uint8_t* base) {
	// 0x29F420: movss xmm0, dword ptr [0x0056F80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F80Cu);
	// 0x29F428: movss [0x0056F81C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F81Cu, ctx.xmm[0].u32[0]);
	// 0x29F430: ret
	return;
}

void sub_29F440(X86Context& ctx, uint8_t* base) {
	// 0x29F440: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29F448: movss [0x0056F780], xmm0
	X86_MEM_WRITE_u32(base, 0x56F780u, ctx.xmm[0].u32[0]);
	// 0x29F450: ret
	return;
}

void sub_29F460(X86Context& ctx, uint8_t* base) {
	// 0x29F460: movss xmm0, dword ptr [0x0056F794]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F794u);
	// 0x29F468: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29F470: movss [0x0056F814], xmm0
	X86_MEM_WRITE_u32(base, 0x56F814u, ctx.xmm[0].u32[0]);
	// 0x29F478: ret
	return;
}

void sub_29F480(X86Context& ctx, uint8_t* base) {
	// 0x29F480: movss xmm0, dword ptr [0x0056F794]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F794u);
	// 0x29F488: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29F490: movss [0x0056F7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7BCu, ctx.xmm[0].u32[0]);
	// 0x29F498: ret
	return;
}

void sub_29F4A0(X86Context& ctx, uint8_t* base) {
	// 0x29F4A0: movss xmm0, dword ptr [0x0056F794]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F794u);
	// 0x29F4A8: subss xmm0, [0x0056F7BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F7BCu);
	// 0x29F4B0: movss [0x0056F79C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F79Cu, ctx.xmm[0].u32[0]);
	// 0x29F4B8: ret
	return;
}

void sub_29F4C0(X86Context& ctx, uint8_t* base) {
	// 0x29F4C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29F4C8: movss [0x0056F7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7E4u, ctx.xmm[0].u32[0]);
	// 0x29F4D0: ret
	return;
}

void sub_29F4E0(X86Context& ctx, uint8_t* base) {
	// 0x29F4E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29F4E8: movss [0x0056F798], xmm0
	X86_MEM_WRITE_u32(base, 0x56F798u, ctx.xmm[0].u32[0]);
	// 0x29F4F0: ret
	return;
}

void sub_29F500(X86Context& ctx, uint8_t* base) {
	// 0x29F500: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29F508: movss [0x0056F7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7A8u, ctx.xmm[0].u32[0]);
	// 0x29F510: ret
	return;
}

void sub_29F520(X86Context& ctx, uint8_t* base) {
	// 0x29F520: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29F528: movss [0x0056F7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7FCu, ctx.xmm[0].u32[0]);
	// 0x29F530: ret
	return;
}

void sub_29F540(X86Context& ctx, uint8_t* base) {
	// 0x29F540: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29F548: movss [0x0056F7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7E0u, ctx.xmm[0].u32[0]);
	// 0x29F550: ret
	return;
}

void sub_29F560(X86Context& ctx, uint8_t* base) {
	// 0x29F560: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29F568: movss [0x0056F790], xmm0
	X86_MEM_WRITE_u32(base, 0x56F790u, ctx.xmm[0].u32[0]);
	// 0x29F570: ret
	return;
}

void sub_29F580(X86Context& ctx, uint8_t* base) {
	// 0x29F580: movss xmm0, dword ptr [0x0056F7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7A8u);
	// 0x29F588: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29F590: movss [0x0056F784], xmm0
	X86_MEM_WRITE_u32(base, 0x56F784u, ctx.xmm[0].u32[0]);
	// 0x29F598: ret
	return;
}

void sub_29F5A0(X86Context& ctx, uint8_t* base) {
	// 0x29F5A0: movss xmm0, dword ptr [0x0056F7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7FCu);
	// 0x29F5A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29F5B0: movss [0x0056F7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7C8u, ctx.xmm[0].u32[0]);
	// 0x29F5B8: ret
	return;
}

void sub_29F5C0(X86Context& ctx, uint8_t* base) {
	// 0x29F5C0: movss xmm0, dword ptr [0x0056F784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F784u);
	// 0x29F5C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29F5D0: movss [0x0056F7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7D8u, ctx.xmm[0].u32[0]);
	// 0x29F5D8: ret
	return;
}

void sub_29F5E0(X86Context& ctx, uint8_t* base) {
	// 0x29F5E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29F5E8: movss [0x0056F77C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F77Cu, ctx.xmm[0].u32[0]);
	// 0x29F5F0: ret
	return;
}

void sub_29F600(X86Context& ctx, uint8_t* base) {
	// 0x29F600: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29F608: movss [0x0056F7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7ACu, ctx.xmm[0].u32[0]);
	// 0x29F610: ret
	return;
}

void sub_29F620(X86Context& ctx, uint8_t* base) {
	// 0x29F620: movss xmm0, dword ptr [0x0056F7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7A8u);
	// 0x29F628: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29F630: movss [0x0056F7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7B8u, ctx.xmm[0].u32[0]);
	// 0x29F638: ret
	return;
}

void sub_29F640(X86Context& ctx, uint8_t* base) {
	// 0x29F640: movss xmm0, dword ptr [0x0056F7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7FCu);
	// 0x29F648: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29F650: movss [0x0056F800], xmm0
	X86_MEM_WRITE_u32(base, 0x56F800u, ctx.xmm[0].u32[0]);
	// 0x29F658: ret
	return;
}

void sub_29F660(X86Context& ctx, uint8_t* base) {
	// 0x29F660: movss xmm0, dword ptr [0x0056F7B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7B8u);
	// 0x29F668: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F670: movss [0x0056F7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7ECu, ctx.xmm[0].u32[0]);
	// 0x29F678: ret
	return;
}

void sub_29F680(X86Context& ctx, uint8_t* base) {
	// 0x29F680: movss xmm0, dword ptr [0x0056F800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F800u);
	// 0x29F688: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F690: movss [0x0056F810], xmm0
	X86_MEM_WRITE_u32(base, 0x56F810u, ctx.xmm[0].u32[0]);
	// 0x29F698: ret
	return;
}

void sub_29F6A0(X86Context& ctx, uint8_t* base) {
	// 0x29F6A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29F6A8: movss [0x0056F788], xmm0
	X86_MEM_WRITE_u32(base, 0x56F788u, ctx.xmm[0].u32[0]);
	// 0x29F6B0: ret
	return;
}

void sub_29F6C0(X86Context& ctx, uint8_t* base) {
	// 0x29F6C0: movss xmm0, dword ptr [0x0056F7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7A8u);
	// 0x29F6C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F6D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29F6D8: movss [0x0056F7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7F8u, ctx.xmm[0].u32[0]);
	// 0x29F6E0: ret
	return;
}

void sub_29F6F0(X86Context& ctx, uint8_t* base) {
	// 0x29F6F0: movss xmm0, dword ptr [0x0056F7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7FCu);
	// 0x29F6F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F700: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29F708: movss [0x0056F7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7A0u, ctx.xmm[0].u32[0]);
	// 0x29F710: ret
	return;
}

void sub_29F720(X86Context& ctx, uint8_t* base) {
	// 0x29F720: movss xmm0, dword ptr [0x0056F7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7A8u);
	// 0x29F728: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F730: movss [0x0056F7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7A4u, ctx.xmm[0].u32[0]);
	// 0x29F738: ret
	return;
}

void sub_29F740(X86Context& ctx, uint8_t* base) {
	// 0x29F740: movss xmm0, dword ptr [0x0056F7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7FCu);
	// 0x29F748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29F750: movss [0x0056F804], xmm0
	X86_MEM_WRITE_u32(base, 0x56F804u, ctx.xmm[0].u32[0]);
	// 0x29F758: ret
	return;
}

void sub_29F760(X86Context& ctx, uint8_t* base) {
	// 0x29F760: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29F768: movss [0x0056F78C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F78Cu, ctx.xmm[0].u32[0]);
	// 0x29F770: ret
	return;
}

void sub_29F780(X86Context& ctx, uint8_t* base) {
	// 0x29F780: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29F788: movss [0x0056F7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7B4u, ctx.xmm[0].u32[0]);
	// 0x29F790: ret
	return;
}

void sub_29F7A0(X86Context& ctx, uint8_t* base) {
	// 0x29F7A0: movss xmm0, dword ptr [0x0056F78C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F78Cu);
	// 0x29F7A8: movss [0x0056F818], xmm0
	X86_MEM_WRITE_u32(base, 0x56F818u, ctx.xmm[0].u32[0]);
	// 0x29F7B0: ret
	return;
}

void sub_29F7C0(X86Context& ctx, uint8_t* base) {
	// 0x29F7C0: movss xmm0, dword ptr [0x0056F7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7FCu);
	// 0x29F7C8: subss xmm0, [0x0056F78C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F78Cu);
	// 0x29F7D0: movss [0x0056F7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7DCu, ctx.xmm[0].u32[0]);
	// 0x29F7D8: ret
	return;
}

void sub_29F7E0(X86Context& ctx, uint8_t* base) {
	// 0x29F7E0: movss xmm0, dword ptr [0x0056F7DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7DCu);
	// 0x29F7E8: subss xmm0, [0x0056F7B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F7B4u);
	// 0x29F7F0: movss [0x0056F7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7D4u, ctx.xmm[0].u32[0]);
	// 0x29F7F8: ret
	return;
}

void sub_29F800(X86Context& ctx, uint8_t* base) {
	// 0x29F800: movss xmm0, dword ptr [0x0056F804]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F804u);
	// 0x29F808: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29F810: movss [0x0056F7C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7C4u, ctx.xmm[0].u32[0]);
	// 0x29F818: ret
	return;
}

void sub_29F820(X86Context& ctx, uint8_t* base) {
	// 0x29F820: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29F828: movss [0x0056F7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7B0u, ctx.xmm[0].u32[0]);
	// 0x29F830: ret
	return;
}

void sub_29F840(X86Context& ctx, uint8_t* base) {
	// 0x29F840: movss xmm0, dword ptr [0x0056F7C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7C4u);
	// 0x29F848: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29F850: movss [0x0056F7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F7F4u, ctx.xmm[0].u32[0]);
	// 0x29F858: ret
	return;
}

void sub_29F860(X86Context& ctx, uint8_t* base) {
	// 0x29F860: movss xmm0, dword ptr [0x0056F7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F7A8u);
	// 0x29F868: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29F870: movss [0x004060F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4060F0u, ctx.xmm[0].u32[0]);
	// 0x29F878: ret
	return;
}

void sub_29F880(X86Context& ctx, uint8_t* base) {
	// 0x29F880: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29F888: movss [0x0056F878], xmm0
	X86_MEM_WRITE_u32(base, 0x56F878u, ctx.xmm[0].u32[0]);
	// 0x29F890: ret
	return;
}

void sub_29F8A0(X86Context& ctx, uint8_t* base) {
	// 0x29F8A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29F8A8: movss [0x0056F894], xmm0
	X86_MEM_WRITE_u32(base, 0x56F894u, ctx.xmm[0].u32[0]);
	// 0x29F8B0: ret
	return;
}

void sub_29F8C0(X86Context& ctx, uint8_t* base) {
	// 0x29F8C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29F8C8: movss [0x0056F86C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F86Cu, ctx.xmm[0].u32[0]);
	// 0x29F8D0: ret
	return;
}

void sub_29F8E0(X86Context& ctx, uint8_t* base) {
	// 0x29F8E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29F8E8: movss [0x0056F824], xmm0
	X86_MEM_WRITE_u32(base, 0x56F824u, ctx.xmm[0].u32[0]);
	// 0x29F8F0: ret
	return;
}

void sub_29F900(X86Context& ctx, uint8_t* base) {
	// 0x29F900: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29F908: movss [0x0056F87C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F87Cu, ctx.xmm[0].u32[0]);
	// 0x29F910: ret
	return;
}

void sub_29F920(X86Context& ctx, uint8_t* base) {
	// 0x29F920: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29F928: movss [0x0056F840], xmm0
	X86_MEM_WRITE_u32(base, 0x56F840u, ctx.xmm[0].u32[0]);
	// 0x29F930: ret
	return;
}

void sub_29F940(X86Context& ctx, uint8_t* base) {
	// 0x29F940: movss xmm0, dword ptr [0x0056F87C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F87Cu);
	// 0x29F948: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29F950: movss [0x0056F8B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8B4u, ctx.xmm[0].u32[0]);
	// 0x29F958: ret
	return;
}

void sub_29F960(X86Context& ctx, uint8_t* base) {
	// 0x29F960: movss xmm0, dword ptr [0x0056F840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F840u);
	// 0x29F968: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29F970: movss [0x0056F89C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F89Cu, ctx.xmm[0].u32[0]);
	// 0x29F978: ret
	return;
}

void sub_29F980(X86Context& ctx, uint8_t* base) {
	// 0x29F980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29F988: movss [0x0056F8CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8CCu, ctx.xmm[0].u32[0]);
	// 0x29F990: ret
	return;
}

void sub_29F9A0(X86Context& ctx, uint8_t* base) {
	// 0x29F9A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29F9A8: movss [0x0056F8B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8B8u, ctx.xmm[0].u32[0]);
	// 0x29F9B0: ret
	return;
}

void sub_29F9C0(X86Context& ctx, uint8_t* base) {
	// 0x29F9C0: movss xmm0, dword ptr [0x0056F8B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8B8u);
	// 0x29F9C8: movss [0x0056F8C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8C8u, ctx.xmm[0].u32[0]);
	// 0x29F9D0: ret
	return;
}

void sub_29F9E0(X86Context& ctx, uint8_t* base) {
	// 0x29F9E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29F9E8: movss [0x0056F82C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F82Cu, ctx.xmm[0].u32[0]);
	// 0x29F9F0: ret
	return;
}

void sub_29FA00(X86Context& ctx, uint8_t* base) {
	// 0x29FA00: movss xmm0, dword ptr [0x0056F840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F840u);
	// 0x29FA08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29FA10: movss [0x0056F8C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8C0u, ctx.xmm[0].u32[0]);
	// 0x29FA18: ret
	return;
}

void sub_29FA20(X86Context& ctx, uint8_t* base) {
	// 0x29FA20: movss xmm0, dword ptr [0x0056F840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F840u);
	// 0x29FA28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29FA30: movss [0x0056F868], xmm0
	X86_MEM_WRITE_u32(base, 0x56F868u, ctx.xmm[0].u32[0]);
	// 0x29FA38: ret
	return;
}

void sub_29FA40(X86Context& ctx, uint8_t* base) {
	// 0x29FA40: movss xmm0, dword ptr [0x0056F840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F840u);
	// 0x29FA48: subss xmm0, [0x0056F868]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F868u);
	// 0x29FA50: movss [0x0056F848], xmm0
	X86_MEM_WRITE_u32(base, 0x56F848u, ctx.xmm[0].u32[0]);
	// 0x29FA58: ret
	return;
}

void sub_29FA60(X86Context& ctx, uint8_t* base) {
	// 0x29FA60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29FA68: movss [0x0056F890], xmm0
	X86_MEM_WRITE_u32(base, 0x56F890u, ctx.xmm[0].u32[0]);
	// 0x29FA70: ret
	return;
}

void sub_29FA80(X86Context& ctx, uint8_t* base) {
	// 0x29FA80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29FA88: movss [0x0056F844], xmm0
	X86_MEM_WRITE_u32(base, 0x56F844u, ctx.xmm[0].u32[0]);
	// 0x29FA90: ret
	return;
}

void sub_29FAA0(X86Context& ctx, uint8_t* base) {
	// 0x29FAA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29FAA8: movss [0x0056F854], xmm0
	X86_MEM_WRITE_u32(base, 0x56F854u, ctx.xmm[0].u32[0]);
	// 0x29FAB0: ret
	return;
}

void sub_29FAC0(X86Context& ctx, uint8_t* base) {
	// 0x29FAC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29FAC8: movss [0x0056F8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8A8u, ctx.xmm[0].u32[0]);
	// 0x29FAD0: ret
	return;
}

void sub_29FAE0(X86Context& ctx, uint8_t* base) {
	// 0x29FAE0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29FAE8: movss [0x0056F88C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F88Cu, ctx.xmm[0].u32[0]);
	// 0x29FAF0: ret
	return;
}

void sub_29FB00(X86Context& ctx, uint8_t* base) {
	// 0x29FB00: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29FB08: movss [0x0056F83C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F83Cu, ctx.xmm[0].u32[0]);
	// 0x29FB10: ret
	return;
}

void sub_29FB20(X86Context& ctx, uint8_t* base) {
	// 0x29FB20: movss xmm0, dword ptr [0x0056F854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F854u);
	// 0x29FB28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29FB30: movss [0x0056F830], xmm0
	X86_MEM_WRITE_u32(base, 0x56F830u, ctx.xmm[0].u32[0]);
	// 0x29FB38: ret
	return;
}

void sub_29FB40(X86Context& ctx, uint8_t* base) {
	// 0x29FB40: movss xmm0, dword ptr [0x0056F8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8A8u);
	// 0x29FB48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29FB50: movss [0x0056F874], xmm0
	X86_MEM_WRITE_u32(base, 0x56F874u, ctx.xmm[0].u32[0]);
	// 0x29FB58: ret
	return;
}

void sub_29FB60(X86Context& ctx, uint8_t* base) {
	// 0x29FB60: movss xmm0, dword ptr [0x0056F830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F830u);
	// 0x29FB68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29FB70: movss [0x0056F884], xmm0
	X86_MEM_WRITE_u32(base, 0x56F884u, ctx.xmm[0].u32[0]);
	// 0x29FB78: ret
	return;
}

void sub_29FB80(X86Context& ctx, uint8_t* base) {
	// 0x29FB80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29FB88: movss [0x0056F828], xmm0
	X86_MEM_WRITE_u32(base, 0x56F828u, ctx.xmm[0].u32[0]);
	// 0x29FB90: ret
	return;
}

void sub_29FBA0(X86Context& ctx, uint8_t* base) {
	// 0x29FBA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29FBA8: movss [0x0056F858], xmm0
	X86_MEM_WRITE_u32(base, 0x56F858u, ctx.xmm[0].u32[0]);
	// 0x29FBB0: ret
	return;
}

void sub_29FBC0(X86Context& ctx, uint8_t* base) {
	// 0x29FBC0: movss xmm0, dword ptr [0x0056F854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F854u);
	// 0x29FBC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29FBD0: movss [0x0056F864], xmm0
	X86_MEM_WRITE_u32(base, 0x56F864u, ctx.xmm[0].u32[0]);
	// 0x29FBD8: ret
	return;
}

void sub_29FBE0(X86Context& ctx, uint8_t* base) {
	// 0x29FBE0: movss xmm0, dword ptr [0x0056F8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8A8u);
	// 0x29FBE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29FBF0: movss [0x0056F8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8ACu, ctx.xmm[0].u32[0]);
	// 0x29FBF8: ret
	return;
}

void sub_29FC00(X86Context& ctx, uint8_t* base) {
	// 0x29FC00: movss xmm0, dword ptr [0x0056F864]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F864u);
	// 0x29FC08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29FC10: movss [0x0056F898], xmm0
	X86_MEM_WRITE_u32(base, 0x56F898u, ctx.xmm[0].u32[0]);
	// 0x29FC18: ret
	return;
}

void sub_29FC20(X86Context& ctx, uint8_t* base) {
	// 0x29FC20: movss xmm0, dword ptr [0x0056F8AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8ACu);
	// 0x29FC28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29FC30: movss [0x0056F8BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8BCu, ctx.xmm[0].u32[0]);
	// 0x29FC38: ret
	return;
}

void sub_29FC40(X86Context& ctx, uint8_t* base) {
	// 0x29FC40: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29FC48: movss [0x0056F834], xmm0
	X86_MEM_WRITE_u32(base, 0x56F834u, ctx.xmm[0].u32[0]);
	// 0x29FC50: ret
	return;
}

void sub_29FC60(X86Context& ctx, uint8_t* base) {
	// 0x29FC60: movss xmm0, dword ptr [0x0056F854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F854u);
	// 0x29FC68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29FC70: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29FC78: movss [0x0056F8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8A4u, ctx.xmm[0].u32[0]);
	// 0x29FC80: ret
	return;
}

void sub_29FC90(X86Context& ctx, uint8_t* base) {
	// 0x29FC90: movss xmm0, dword ptr [0x0056F8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8A8u);
	// 0x29FC98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29FCA0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29FCA8: movss [0x0056F84C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F84Cu, ctx.xmm[0].u32[0]);
	// 0x29FCB0: ret
	return;
}

void sub_29FCC0(X86Context& ctx, uint8_t* base) {
	// 0x29FCC0: movss xmm0, dword ptr [0x0056F854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F854u);
	// 0x29FCC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29FCD0: movss [0x0056F850], xmm0
	X86_MEM_WRITE_u32(base, 0x56F850u, ctx.xmm[0].u32[0]);
	// 0x29FCD8: ret
	return;
}

void sub_29FCE0(X86Context& ctx, uint8_t* base) {
	// 0x29FCE0: movss xmm0, dword ptr [0x0056F8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8A8u);
	// 0x29FCE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29FCF0: movss [0x0056F8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8B0u, ctx.xmm[0].u32[0]);
	// 0x29FCF8: ret
	return;
}

void sub_29FD00(X86Context& ctx, uint8_t* base) {
	// 0x29FD00: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29FD08: movss [0x0056F838], xmm0
	X86_MEM_WRITE_u32(base, 0x56F838u, ctx.xmm[0].u32[0]);
	// 0x29FD10: ret
	return;
}

void sub_29FD20(X86Context& ctx, uint8_t* base) {
	// 0x29FD20: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29FD28: movss [0x0056F860], xmm0
	X86_MEM_WRITE_u32(base, 0x56F860u, ctx.xmm[0].u32[0]);
	// 0x29FD30: ret
	return;
}

void sub_29FD40(X86Context& ctx, uint8_t* base) {
	// 0x29FD40: movss xmm0, dword ptr [0x0056F838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F838u);
	// 0x29FD48: movss [0x0056F8C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8C4u, ctx.xmm[0].u32[0]);
	// 0x29FD50: ret
	return;
}

void sub_29FD60(X86Context& ctx, uint8_t* base) {
	// 0x29FD60: movss xmm0, dword ptr [0x0056F8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8A8u);
	// 0x29FD68: subss xmm0, [0x0056F838]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F838u);
	// 0x29FD70: movss [0x0056F888], xmm0
	X86_MEM_WRITE_u32(base, 0x56F888u, ctx.xmm[0].u32[0]);
	// 0x29FD78: ret
	return;
}

void sub_29FD80(X86Context& ctx, uint8_t* base) {
	// 0x29FD80: movss xmm0, dword ptr [0x0056F888]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F888u);
	// 0x29FD88: subss xmm0, [0x0056F860]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F860u);
	// 0x29FD90: movss [0x0056F880], xmm0
	X86_MEM_WRITE_u32(base, 0x56F880u, ctx.xmm[0].u32[0]);
	// 0x29FD98: ret
	return;
}

void sub_29FDA0(X86Context& ctx, uint8_t* base) {
	// 0x29FDA0: movss xmm0, dword ptr [0x0056F8B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8B0u);
	// 0x29FDA8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29FDB0: movss [0x0056F870], xmm0
	X86_MEM_WRITE_u32(base, 0x56F870u, ctx.xmm[0].u32[0]);
	// 0x29FDB8: ret
	return;
}

void sub_29FDC0(X86Context& ctx, uint8_t* base) {
	// 0x29FDC0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29FDC8: movss [0x0056F85C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F85Cu, ctx.xmm[0].u32[0]);
	// 0x29FDD0: ret
	return;
}

void sub_29FDE0(X86Context& ctx, uint8_t* base) {
	// 0x29FDE0: movss xmm0, dword ptr [0x0056F870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F870u);
	// 0x29FDE8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29FDF0: movss [0x0056F8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8A0u, ctx.xmm[0].u32[0]);
	// 0x29FDF8: ret
	return;
}

void sub_29FE00(X86Context& ctx, uint8_t* base) {
	// 0x29FE00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29FE08: movss [0x0056F924], xmm0
	X86_MEM_WRITE_u32(base, 0x56F924u, ctx.xmm[0].u32[0]);
	// 0x29FE10: ret
	return;
}

void sub_29FE20(X86Context& ctx, uint8_t* base) {
	// 0x29FE20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29FE28: movss [0x0056F940], xmm0
	X86_MEM_WRITE_u32(base, 0x56F940u, ctx.xmm[0].u32[0]);
	// 0x29FE30: ret
	return;
}

void sub_29FE40(X86Context& ctx, uint8_t* base) {
	// 0x29FE40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29FE48: movss [0x0056F918], xmm0
	X86_MEM_WRITE_u32(base, 0x56F918u, ctx.xmm[0].u32[0]);
	// 0x29FE50: ret
	return;
}

void sub_29FE60(X86Context& ctx, uint8_t* base) {
	// 0x29FE60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29FE68: movss [0x0056F8D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8D0u, ctx.xmm[0].u32[0]);
	// 0x29FE70: ret
	return;
}

void sub_29FE80(X86Context& ctx, uint8_t* base) {
	// 0x29FE80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29FE88: movss [0x0056F928], xmm0
	X86_MEM_WRITE_u32(base, 0x56F928u, ctx.xmm[0].u32[0]);
	// 0x29FE90: ret
	return;
}

void sub_29FEA0(X86Context& ctx, uint8_t* base) {
	// 0x29FEA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29FEA8: movss [0x0056F8EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8ECu, ctx.xmm[0].u32[0]);
	// 0x29FEB0: ret
	return;
}

void sub_29FEC0(X86Context& ctx, uint8_t* base) {
	// 0x29FEC0: movss xmm0, dword ptr [0x0056F928]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F928u);
	// 0x29FEC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29FED0: movss [0x0056F960], xmm0
	X86_MEM_WRITE_u32(base, 0x56F960u, ctx.xmm[0].u32[0]);
	// 0x29FED8: ret
	return;
}

void sub_29FEE0(X86Context& ctx, uint8_t* base) {
	// 0x29FEE0: movss xmm0, dword ptr [0x0056F8EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8ECu);
	// 0x29FEE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29FEF0: movss [0x0056F948], xmm0
	X86_MEM_WRITE_u32(base, 0x56F948u, ctx.xmm[0].u32[0]);
	// 0x29FEF8: ret
	return;
}

void sub_29FF00(X86Context& ctx, uint8_t* base) {
	// 0x29FF00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29FF08: movss [0x0056F978], xmm0
	X86_MEM_WRITE_u32(base, 0x56F978u, ctx.xmm[0].u32[0]);
	// 0x29FF10: ret
	return;
}

void sub_29FF20(X86Context& ctx, uint8_t* base) {
	// 0x29FF20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29FF28: movss [0x0056F964], xmm0
	X86_MEM_WRITE_u32(base, 0x56F964u, ctx.xmm[0].u32[0]);
	// 0x29FF30: ret
	return;
}

void sub_29FF40(X86Context& ctx, uint8_t* base) {
	// 0x29FF40: movss xmm0, dword ptr [0x0056F964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F964u);
	// 0x29FF48: movss [0x0056F974], xmm0
	X86_MEM_WRITE_u32(base, 0x56F974u, ctx.xmm[0].u32[0]);
	// 0x29FF50: ret
	return;
}

void sub_29FF60(X86Context& ctx, uint8_t* base) {
	// 0x29FF60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29FF68: movss [0x0056F8D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8D8u, ctx.xmm[0].u32[0]);
	// 0x29FF70: ret
	return;
}

void sub_29FF80(X86Context& ctx, uint8_t* base) {
	// 0x29FF80: movss xmm0, dword ptr [0x0056F8EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8ECu);
	// 0x29FF88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29FF90: movss [0x0056F96C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F96Cu, ctx.xmm[0].u32[0]);
	// 0x29FF98: ret
	return;
}

void sub_29FFA0(X86Context& ctx, uint8_t* base) {
	// 0x29FFA0: movss xmm0, dword ptr [0x0056F8EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8ECu);
	// 0x29FFA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29FFB0: movss [0x0056F914], xmm0
	X86_MEM_WRITE_u32(base, 0x56F914u, ctx.xmm[0].u32[0]);
	// 0x29FFB8: ret
	return;
}

void sub_29FFC0(X86Context& ctx, uint8_t* base) {
	// 0x29FFC0: movss xmm0, dword ptr [0x0056F8EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8ECu);
	// 0x29FFC8: subss xmm0, [0x0056F914]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F914u);
	// 0x29FFD0: movss [0x0056F8F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8F4u, ctx.xmm[0].u32[0]);
	// 0x29FFD8: ret
	return;
}

void sub_29FFE0(X86Context& ctx, uint8_t* base) {
	// 0x29FFE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29FFE8: movss [0x0056F93C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F93Cu, ctx.xmm[0].u32[0]);
	// 0x29FFF0: ret
	return;
}

void sub_2A0000(X86Context& ctx, uint8_t* base) {
	// 0x2A0000: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A0008: movss [0x0056F8F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8F0u, ctx.xmm[0].u32[0]);
	// 0x2A0010: ret
	return;
}

void sub_2A0020(X86Context& ctx, uint8_t* base) {
	// 0x2A0020: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A0028: movss [0x0056F900], xmm0
	X86_MEM_WRITE_u32(base, 0x56F900u, ctx.xmm[0].u32[0]);
	// 0x2A0030: ret
	return;
}

void sub_2A0040(X86Context& ctx, uint8_t* base) {
	// 0x2A0040: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A0048: movss [0x0056F954], xmm0
	X86_MEM_WRITE_u32(base, 0x56F954u, ctx.xmm[0].u32[0]);
	// 0x2A0050: ret
	return;
}

void sub_2A0060(X86Context& ctx, uint8_t* base) {
	// 0x2A0060: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A0068: movss [0x0056F938], xmm0
	X86_MEM_WRITE_u32(base, 0x56F938u, ctx.xmm[0].u32[0]);
	// 0x2A0070: ret
	return;
}

void sub_2A0080(X86Context& ctx, uint8_t* base) {
	// 0x2A0080: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A0088: movss [0x0056F8E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8E8u, ctx.xmm[0].u32[0]);
	// 0x2A0090: ret
	return;
}

void sub_2A00A0(X86Context& ctx, uint8_t* base) {
	// 0x2A00A0: movss xmm0, dword ptr [0x0056F900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F900u);
	// 0x2A00A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A00B0: movss [0x0056F8DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8DCu, ctx.xmm[0].u32[0]);
	// 0x2A00B8: ret
	return;
}

void sub_2A00C0(X86Context& ctx, uint8_t* base) {
	// 0x2A00C0: movss xmm0, dword ptr [0x0056F954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F954u);
	// 0x2A00C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A00D0: movss [0x0056F920], xmm0
	X86_MEM_WRITE_u32(base, 0x56F920u, ctx.xmm[0].u32[0]);
	// 0x2A00D8: ret
	return;
}

void sub_2A00E0(X86Context& ctx, uint8_t* base) {
	// 0x2A00E0: movss xmm0, dword ptr [0x0056F8DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8DCu);
	// 0x2A00E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A00F0: movss [0x0056F930], xmm0
	X86_MEM_WRITE_u32(base, 0x56F930u, ctx.xmm[0].u32[0]);
	// 0x2A00F8: ret
	return;
}

void sub_2A0100(X86Context& ctx, uint8_t* base) {
	// 0x2A0100: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A0108: movss [0x0056F8D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8D4u, ctx.xmm[0].u32[0]);
	// 0x2A0110: ret
	return;
}

void sub_2A0120(X86Context& ctx, uint8_t* base) {
	// 0x2A0120: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A0128: movss [0x0056F904], xmm0
	X86_MEM_WRITE_u32(base, 0x56F904u, ctx.xmm[0].u32[0]);
	// 0x2A0130: ret
	return;
}

void sub_2A0140(X86Context& ctx, uint8_t* base) {
	// 0x2A0140: movss xmm0, dword ptr [0x0056F900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F900u);
	// 0x2A0148: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A0150: movss [0x0056F910], xmm0
	X86_MEM_WRITE_u32(base, 0x56F910u, ctx.xmm[0].u32[0]);
	// 0x2A0158: ret
	return;
}

void sub_2A0160(X86Context& ctx, uint8_t* base) {
	// 0x2A0160: movss xmm0, dword ptr [0x0056F954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F954u);
	// 0x2A0168: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A0170: movss [0x0056F958], xmm0
	X86_MEM_WRITE_u32(base, 0x56F958u, ctx.xmm[0].u32[0]);
	// 0x2A0178: ret
	return;
}

void sub_2A0180(X86Context& ctx, uint8_t* base) {
	// 0x2A0180: movss xmm0, dword ptr [0x0056F910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F910u);
	// 0x2A0188: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0190: movss [0x0056F944], xmm0
	X86_MEM_WRITE_u32(base, 0x56F944u, ctx.xmm[0].u32[0]);
	// 0x2A0198: ret
	return;
}

void sub_2A01A0(X86Context& ctx, uint8_t* base) {
	// 0x2A01A0: movss xmm0, dword ptr [0x0056F958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F958u);
	// 0x2A01A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A01B0: movss [0x0056F968], xmm0
	X86_MEM_WRITE_u32(base, 0x56F968u, ctx.xmm[0].u32[0]);
	// 0x2A01B8: ret
	return;
}

void sub_2A01C0(X86Context& ctx, uint8_t* base) {
	// 0x2A01C0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A01C8: movss [0x0056F8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8E0u, ctx.xmm[0].u32[0]);
	// 0x2A01D0: ret
	return;
}

void sub_2A01E0(X86Context& ctx, uint8_t* base) {
	// 0x2A01E0: movss xmm0, dword ptr [0x0056F900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F900u);
	// 0x2A01E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A01F0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A01F8: movss [0x0056F950], xmm0
	X86_MEM_WRITE_u32(base, 0x56F950u, ctx.xmm[0].u32[0]);
	// 0x2A0200: ret
	return;
}

void sub_2A0210(X86Context& ctx, uint8_t* base) {
	// 0x2A0210: movss xmm0, dword ptr [0x0056F954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F954u);
	// 0x2A0218: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0220: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A0228: movss [0x0056F8F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8F8u, ctx.xmm[0].u32[0]);
	// 0x2A0230: ret
	return;
}

void sub_2A0240(X86Context& ctx, uint8_t* base) {
	// 0x2A0240: movss xmm0, dword ptr [0x0056F900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F900u);
	// 0x2A0248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0250: movss [0x0056F8FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8FCu, ctx.xmm[0].u32[0]);
	// 0x2A0258: ret
	return;
}

void sub_2A0260(X86Context& ctx, uint8_t* base) {
	// 0x2A0260: movss xmm0, dword ptr [0x0056F954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F954u);
	// 0x2A0268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0270: movss [0x0056F95C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F95Cu, ctx.xmm[0].u32[0]);
	// 0x2A0278: ret
	return;
}

void sub_2A0280(X86Context& ctx, uint8_t* base) {
	// 0x2A0280: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A0288: movss [0x0056F8E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F8E4u, ctx.xmm[0].u32[0]);
	// 0x2A0290: ret
	return;
}

void sub_2A02A0(X86Context& ctx, uint8_t* base) {
	// 0x2A02A0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A02A8: movss [0x0056F90C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F90Cu, ctx.xmm[0].u32[0]);
	// 0x2A02B0: ret
	return;
}

void sub_2A02C0(X86Context& ctx, uint8_t* base) {
	// 0x2A02C0: movss xmm0, dword ptr [0x0056F8E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F8E4u);
	// 0x2A02C8: movss [0x0056F970], xmm0
	X86_MEM_WRITE_u32(base, 0x56F970u, ctx.xmm[0].u32[0]);
	// 0x2A02D0: ret
	return;
}

void sub_2A02E0(X86Context& ctx, uint8_t* base) {
	// 0x2A02E0: movss xmm0, dword ptr [0x0056F954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F954u);
	// 0x2A02E8: subss xmm0, [0x0056F8E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F8E4u);
	// 0x2A02F0: movss [0x0056F934], xmm0
	X86_MEM_WRITE_u32(base, 0x56F934u, ctx.xmm[0].u32[0]);
	// 0x2A02F8: ret
	return;
}

void sub_2A0300(X86Context& ctx, uint8_t* base) {
	// 0x2A0300: movss xmm0, dword ptr [0x0056F934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F934u);
	// 0x2A0308: subss xmm0, [0x0056F90C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F90Cu);
	// 0x2A0310: movss [0x0056F92C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F92Cu, ctx.xmm[0].u32[0]);
	// 0x2A0318: ret
	return;
}

