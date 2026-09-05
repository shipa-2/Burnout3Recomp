#include "x86_recomp_shared.h"

void sub_2B7590(X86Context& ctx, uint8_t* base) {
	// 0x2B7590: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7598: movss [0x005728A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5728A0u, ctx.xmm[0].u32[0]);
	// 0x2B75A0: ret
	return;
}

void sub_2B75B0(X86Context& ctx, uint8_t* base) {
	// 0x2B75B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B75B8: movss [0x005728B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5728B4u, ctx.xmm[0].u32[0]);
	// 0x2B75C0: ret
	return;
}

void sub_2B75D0(X86Context& ctx, uint8_t* base) {
	// 0x2B75D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B75D8: movss [0x005728B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5728B8u, ctx.xmm[0].u32[0]);
	// 0x2B75E0: ret
	return;
}

void sub_2B75F0(X86Context& ctx, uint8_t* base) {
	// 0x2B75F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B75F8: movss [0x005728B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5728B0u, ctx.xmm[0].u32[0]);
	// 0x2B7600: ret
	return;
}

void sub_2B7610(X86Context& ctx, uint8_t* base) {
	// 0x2B7610: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7618: movss [0x005728C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5728C4u, ctx.xmm[0].u32[0]);
	// 0x2B7620: ret
	return;
}

void sub_2B7630(X86Context& ctx, uint8_t* base) {
	// 0x2B7630: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7638: movss [0x005728C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5728C8u, ctx.xmm[0].u32[0]);
	// 0x2B7640: ret
	return;
}

void sub_2B7650(X86Context& ctx, uint8_t* base) {
	// 0x2B7650: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7658: movss [0x005728C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5728C0u, ctx.xmm[0].u32[0]);
	// 0x2B7660: ret
	return;
}

void sub_2B7670(X86Context& ctx, uint8_t* base) {
	// 0x2B7670: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7678: movss [0x005728BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5728BCu, ctx.xmm[0].u32[0]);
	// 0x2B7680: ret
	return;
}

void sub_2B7690(X86Context& ctx, uint8_t* base) {
	// 0x2B7690: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7698: movss [0x005728D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5728D4u, ctx.xmm[0].u32[0]);
	// 0x2B76A0: ret
	return;
}

void sub_2B76B0(X86Context& ctx, uint8_t* base) {
	// 0x2B76B0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B76B8: movss [0x005728D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5728D8u, ctx.xmm[0].u32[0]);
	// 0x2B76C0: ret
	return;
}

void sub_2B76D0(X86Context& ctx, uint8_t* base) {
	// 0x2B76D0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B76D8: movss [0x005728D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5728D0u, ctx.xmm[0].u32[0]);
	// 0x2B76E0: ret
	return;
}

void sub_2B76F0(X86Context& ctx, uint8_t* base) {
	// 0x2B76F0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B76F8: movss [0x005728CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5728CCu, ctx.xmm[0].u32[0]);
	// 0x2B7700: ret
	return;
}

void sub_2B7710(X86Context& ctx, uint8_t* base) {
	// 0x2B7710: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7718: movss [0x00572938], xmm0
	X86_MEM_WRITE_u32(base, 0x572938u, ctx.xmm[0].u32[0]);
	// 0x2B7720: ret
	return;
}

void sub_2B7730(X86Context& ctx, uint8_t* base) {
	// 0x2B7730: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7738: movss [0x00572954], xmm0
	X86_MEM_WRITE_u32(base, 0x572954u, ctx.xmm[0].u32[0]);
	// 0x2B7740: ret
	return;
}

void sub_2B7750(X86Context& ctx, uint8_t* base) {
	// 0x2B7750: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7758: movss [0x00572928], xmm0
	X86_MEM_WRITE_u32(base, 0x572928u, ctx.xmm[0].u32[0]);
	// 0x2B7760: ret
	return;
}

void sub_2B7770(X86Context& ctx, uint8_t* base) {
	// 0x2B7770: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7778: movss [0x005728DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5728DCu, ctx.xmm[0].u32[0]);
	// 0x2B7780: ret
	return;
}

void sub_2B7790(X86Context& ctx, uint8_t* base) {
	// 0x2B7790: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B7798: movss [0x0057293C], xmm0
	X86_MEM_WRITE_u32(base, 0x57293Cu, ctx.xmm[0].u32[0]);
	// 0x2B77A0: ret
	return;
}

void sub_2B77B0(X86Context& ctx, uint8_t* base) {
	// 0x2B77B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B77B8: movss [0x005728F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5728F8u, ctx.xmm[0].u32[0]);
	// 0x2B77C0: ret
	return;
}

void sub_2B77D0(X86Context& ctx, uint8_t* base) {
	// 0x2B77D0: movss xmm0, dword ptr [0x0057293C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57293Cu);
	// 0x2B77D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B77E0: movss [0x00572974], xmm0
	X86_MEM_WRITE_u32(base, 0x572974u, ctx.xmm[0].u32[0]);
	// 0x2B77E8: ret
	return;
}

void sub_2B77F0(X86Context& ctx, uint8_t* base) {
	// 0x2B77F0: movss xmm0, dword ptr [0x005728F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5728F8u);
	// 0x2B77F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B7800: movss [0x0057295C], xmm0
	X86_MEM_WRITE_u32(base, 0x57295Cu, ctx.xmm[0].u32[0]);
	// 0x2B7808: ret
	return;
}

void sub_2B7810(X86Context& ctx, uint8_t* base) {
	// 0x2B7810: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B7818: movss [0x005A37C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37C0u, ctx.xmm[0].u32[0]);
	// 0x2B7820: ret
	return;
}

void sub_2B7830(X86Context& ctx, uint8_t* base) {
	// 0x2B7830: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B7838: movss [0x00572978], xmm0
	X86_MEM_WRITE_u32(base, 0x572978u, ctx.xmm[0].u32[0]);
	// 0x2B7840: ret
	return;
}

void sub_2B7850(X86Context& ctx, uint8_t* base) {
	// 0x2B7850: movss xmm0, dword ptr [0x00572978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572978u);
	// 0x2B7858: movss [0x005A37BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37BCu, ctx.xmm[0].u32[0]);
	// 0x2B7860: ret
	return;
}

void sub_2B7870(X86Context& ctx, uint8_t* base) {
	// 0x2B7870: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B7878: movss [0x005728E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5728E4u, ctx.xmm[0].u32[0]);
	// 0x2B7880: ret
	return;
}

void sub_2B7890(X86Context& ctx, uint8_t* base) {
	// 0x2B7890: movss xmm0, dword ptr [0x005728F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5728F8u);
	// 0x2B7898: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B78A0: movss [0x005A37B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37B4u, ctx.xmm[0].u32[0]);
	// 0x2B78A8: ret
	return;
}

void sub_2B78B0(X86Context& ctx, uint8_t* base) {
	// 0x2B78B0: movss xmm0, dword ptr [0x005728F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5728F8u);
	// 0x2B78B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B78C0: movss [0x00572924], xmm0
	X86_MEM_WRITE_u32(base, 0x572924u, ctx.xmm[0].u32[0]);
	// 0x2B78C8: ret
	return;
}

void sub_2B78D0(X86Context& ctx, uint8_t* base) {
	// 0x2B78D0: movss xmm0, dword ptr [0x005728F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5728F8u);
	// 0x2B78D8: subss xmm0, [0x00572924]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572924u);
	// 0x2B78E0: movss [0x00572900], xmm0
	X86_MEM_WRITE_u32(base, 0x572900u, ctx.xmm[0].u32[0]);
	// 0x2B78E8: ret
	return;
}

void sub_2B78F0(X86Context& ctx, uint8_t* base) {
	// 0x2B78F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B78F8: movss [0x00572950], xmm0
	X86_MEM_WRITE_u32(base, 0x572950u, ctx.xmm[0].u32[0]);
	// 0x2B7900: ret
	return;
}

void sub_2B7910(X86Context& ctx, uint8_t* base) {
	// 0x2B7910: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B7918: movss [0x005728FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5728FCu, ctx.xmm[0].u32[0]);
	// 0x2B7920: ret
	return;
}

void sub_2B7930(X86Context& ctx, uint8_t* base) {
	// 0x2B7930: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B7938: movss [0x00572910], xmm0
	X86_MEM_WRITE_u32(base, 0x572910u, ctx.xmm[0].u32[0]);
	// 0x2B7940: ret
	return;
}

void sub_2B7950(X86Context& ctx, uint8_t* base) {
	// 0x2B7950: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B7958: movss [0x00572968], xmm0
	X86_MEM_WRITE_u32(base, 0x572968u, ctx.xmm[0].u32[0]);
	// 0x2B7960: ret
	return;
}

void sub_2B7970(X86Context& ctx, uint8_t* base) {
	// 0x2B7970: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B7978: movss [0x0057294C], xmm0
	X86_MEM_WRITE_u32(base, 0x57294Cu, ctx.xmm[0].u32[0]);
	// 0x2B7980: ret
	return;
}

void sub_2B7990(X86Context& ctx, uint8_t* base) {
	// 0x2B7990: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B7998: movss [0x005728F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5728F4u, ctx.xmm[0].u32[0]);
	// 0x2B79A0: ret
	return;
}

void sub_2B79B0(X86Context& ctx, uint8_t* base) {
	// 0x2B79B0: movss xmm0, dword ptr [0x00572910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572910u);
	// 0x2B79B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B79C0: movss [0x005728E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5728E8u, ctx.xmm[0].u32[0]);
	// 0x2B79C8: ret
	return;
}

void sub_2B79D0(X86Context& ctx, uint8_t* base) {
	// 0x2B79D0: movss xmm0, dword ptr [0x00572968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572968u);
	// 0x2B79D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B79E0: movss [0x00572930], xmm0
	X86_MEM_WRITE_u32(base, 0x572930u, ctx.xmm[0].u32[0]);
	// 0x2B79E8: ret
	return;
}

void sub_2B79F0(X86Context& ctx, uint8_t* base) {
	// 0x2B79F0: movss xmm0, dword ptr [0x005728E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5728E8u);
	// 0x2B79F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B7A00: movss [0x00572944], xmm0
	X86_MEM_WRITE_u32(base, 0x572944u, ctx.xmm[0].u32[0]);
	// 0x2B7A08: ret
	return;
}

void sub_2B7A10(X86Context& ctx, uint8_t* base) {
	// 0x2B7A10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B7A18: movss [0x005728E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5728E0u, ctx.xmm[0].u32[0]);
	// 0x2B7A20: ret
	return;
}

void sub_2B7A30(X86Context& ctx, uint8_t* base) {
	// 0x2B7A30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B7A38: movss [0x00572914], xmm0
	X86_MEM_WRITE_u32(base, 0x572914u, ctx.xmm[0].u32[0]);
	// 0x2B7A40: ret
	return;
}

void sub_2B7A50(X86Context& ctx, uint8_t* base) {
	// 0x2B7A50: movss xmm0, dword ptr [0x00572910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572910u);
	// 0x2B7A58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B7A60: movss [0x00572920], xmm0
	X86_MEM_WRITE_u32(base, 0x572920u, ctx.xmm[0].u32[0]);
	// 0x2B7A68: ret
	return;
}

void sub_2B7A70(X86Context& ctx, uint8_t* base) {
	// 0x2B7A70: movss xmm0, dword ptr [0x00572968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572968u);
	// 0x2B7A78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B7A80: movss [0x0057296C], xmm0
	X86_MEM_WRITE_u32(base, 0x57296Cu, ctx.xmm[0].u32[0]);
	// 0x2B7A88: ret
	return;
}

void sub_2B7A90(X86Context& ctx, uint8_t* base) {
	// 0x2B7A90: movss xmm0, dword ptr [0x00572920]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572920u);
	// 0x2B7A98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B7AA0: movss [0x00572958], xmm0
	X86_MEM_WRITE_u32(base, 0x572958u, ctx.xmm[0].u32[0]);
	// 0x2B7AA8: ret
	return;
}

void sub_2B7AB0(X86Context& ctx, uint8_t* base) {
	// 0x2B7AB0: movss xmm0, dword ptr [0x0057296C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57296Cu);
	// 0x2B7AB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B7AC0: movss [0x005A37B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37B0u, ctx.xmm[0].u32[0]);
	// 0x2B7AC8: ret
	return;
}

void sub_2B7AD0(X86Context& ctx, uint8_t* base) {
	// 0x2B7AD0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B7AD8: movss [0x005728EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5728ECu, ctx.xmm[0].u32[0]);
	// 0x2B7AE0: ret
	return;
}

void sub_2B7AF0(X86Context& ctx, uint8_t* base) {
	// 0x2B7AF0: movss xmm0, dword ptr [0x00572910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572910u);
	// 0x2B7AF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B7B00: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B7B08: movss [0x00572964], xmm0
	X86_MEM_WRITE_u32(base, 0x572964u, ctx.xmm[0].u32[0]);
	// 0x2B7B10: ret
	return;
}

void sub_2B7B20(X86Context& ctx, uint8_t* base) {
	// 0x2B7B20: movss xmm0, dword ptr [0x00572968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572968u);
	// 0x2B7B28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B7B30: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B7B38: movss [0x00572904], xmm0
	X86_MEM_WRITE_u32(base, 0x572904u, ctx.xmm[0].u32[0]);
	// 0x2B7B40: ret
	return;
}

void sub_2B7B50(X86Context& ctx, uint8_t* base) {
	// 0x2B7B50: movss xmm0, dword ptr [0x00572910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572910u);
	// 0x2B7B58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B7B60: movss [0x00572908], xmm0
	X86_MEM_WRITE_u32(base, 0x572908u, ctx.xmm[0].u32[0]);
	// 0x2B7B68: ret
	return;
}

void sub_2B7B70(X86Context& ctx, uint8_t* base) {
	// 0x2B7B70: movss xmm0, dword ptr [0x00572968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572968u);
	// 0x2B7B78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B7B80: movss [0x00572970], xmm0
	X86_MEM_WRITE_u32(base, 0x572970u, ctx.xmm[0].u32[0]);
	// 0x2B7B88: ret
	return;
}

void sub_2B7B90(X86Context& ctx, uint8_t* base) {
	// 0x2B7B90: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B7B98: movss [0x005728F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5728F0u, ctx.xmm[0].u32[0]);
	// 0x2B7BA0: ret
	return;
}

void sub_2B7BB0(X86Context& ctx, uint8_t* base) {
	// 0x2B7BB0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B7BB8: movss [0x0057291C], xmm0
	X86_MEM_WRITE_u32(base, 0x57291Cu, ctx.xmm[0].u32[0]);
	// 0x2B7BC0: ret
	return;
}

void sub_2B7BD0(X86Context& ctx, uint8_t* base) {
	// 0x2B7BD0: movss xmm0, dword ptr [0x005728F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5728F0u);
	// 0x2B7BD8: movss [0x005A37B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37B8u, ctx.xmm[0].u32[0]);
	// 0x2B7BE0: ret
	return;
}

void sub_2B7BF0(X86Context& ctx, uint8_t* base) {
	// 0x2B7BF0: movss xmm0, dword ptr [0x00572968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572968u);
	// 0x2B7BF8: subss xmm0, [0x005728F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5728F0u);
	// 0x2B7C00: movss [0x00572948], xmm0
	X86_MEM_WRITE_u32(base, 0x572948u, ctx.xmm[0].u32[0]);
	// 0x2B7C08: ret
	return;
}

void sub_2B7C10(X86Context& ctx, uint8_t* base) {
	// 0x2B7C10: movss xmm0, dword ptr [0x00572948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572948u);
	// 0x2B7C18: subss xmm0, [0x0057291C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57291Cu);
	// 0x2B7C20: movss [0x00572940], xmm0
	X86_MEM_WRITE_u32(base, 0x572940u, ctx.xmm[0].u32[0]);
	// 0x2B7C28: ret
	return;
}

void sub_2B7C30(X86Context& ctx, uint8_t* base) {
	// 0x2B7C30: movss xmm0, dword ptr [0x00572970]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572970u);
	// 0x2B7C38: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B7C40: movss [0x0057292C], xmm0
	X86_MEM_WRITE_u32(base, 0x57292Cu, ctx.xmm[0].u32[0]);
	// 0x2B7C48: ret
	return;
}

void sub_2B7C50(X86Context& ctx, uint8_t* base) {
	// 0x2B7C50: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B7C58: movss [0x00572918], xmm0
	X86_MEM_WRITE_u32(base, 0x572918u, ctx.xmm[0].u32[0]);
	// 0x2B7C60: ret
	return;
}

void sub_2B7C70(X86Context& ctx, uint8_t* base) {
	// 0x2B7C70: movss xmm0, dword ptr [0x0057292C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57292Cu);
	// 0x2B7C78: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B7C80: movss [0x00572960], xmm0
	X86_MEM_WRITE_u32(base, 0x572960u, ctx.xmm[0].u32[0]);
	// 0x2B7C88: ret
	return;
}

void sub_2B7C90(X86Context& ctx, uint8_t* base) {
	// 0x2B7C90: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2B7C98: movss [0x00572934], xmm0
	X86_MEM_WRITE_u32(base, 0x572934u, ctx.xmm[0].u32[0]);
	// 0x2B7CA0: ret
	return;
}

void sub_2B7CB0(X86Context& ctx, uint8_t* base) {
	// 0x2B7CB0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2B7CB8: movss [0x0057290C], xmm0
	X86_MEM_WRITE_u32(base, 0x57290Cu, ctx.xmm[0].u32[0]);
	// 0x2B7CC0: ret
	return;
}

void sub_2B7CD0(X86Context& ctx, uint8_t* base) {
	// 0x2B7CD0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B7CD1: mov ebx, 0x572980
	ctx.ebx = 5712256;
	// 0x2B7CD6: call 0x000FC3D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_FC3D0(ctx, base);
	ctx.esp += 4;
	// 0x2B7CDB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B7CDC: ret
	return;
}

void sub_2B7CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B7CE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7CE8: movss [0x005A37CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37CCu, ctx.xmm[0].u32[0]);
	// 0x2B7CF0: ret
	return;
}

void sub_2B7D00(X86Context& ctx, uint8_t* base) {
	// 0x2B7D00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7D08: movss [0x005A37D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37D0u, ctx.xmm[0].u32[0]);
	// 0x2B7D10: ret
	return;
}

void sub_2B7D20(X86Context& ctx, uint8_t* base) {
	// 0x2B7D20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7D28: movss [0x005A37C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37C8u, ctx.xmm[0].u32[0]);
	// 0x2B7D30: ret
	return;
}

void sub_2B7D40(X86Context& ctx, uint8_t* base) {
	// 0x2B7D40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7D48: movss [0x005A37C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37C4u, ctx.xmm[0].u32[0]);
	// 0x2B7D50: ret
	return;
}

void sub_2B7D60(X86Context& ctx, uint8_t* base) {
	// 0x2B7D60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7D68: movss [0x005A37DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37DCu, ctx.xmm[0].u32[0]);
	// 0x2B7D70: ret
	return;
}

void sub_2B7D80(X86Context& ctx, uint8_t* base) {
	// 0x2B7D80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7D88: movss [0x005A37E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37E0u, ctx.xmm[0].u32[0]);
	// 0x2B7D90: ret
	return;
}

void sub_2B7DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B7DA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7DA8: movss [0x005A37D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37D8u, ctx.xmm[0].u32[0]);
	// 0x2B7DB0: ret
	return;
}

void sub_2B7DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B7DC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7DC8: movss [0x005A37D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37D4u, ctx.xmm[0].u32[0]);
	// 0x2B7DD0: ret
	return;
}

void sub_2B7DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B7DE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7DE8: movss [0x005A37EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37ECu, ctx.xmm[0].u32[0]);
	// 0x2B7DF0: ret
	return;
}

void sub_2B7E00(X86Context& ctx, uint8_t* base) {
	// 0x2B7E00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7E08: movss [0x005A37F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37F0u, ctx.xmm[0].u32[0]);
	// 0x2B7E10: ret
	return;
}

void sub_2B7E20(X86Context& ctx, uint8_t* base) {
	// 0x2B7E20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7E28: movss [0x005A37E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37E8u, ctx.xmm[0].u32[0]);
	// 0x2B7E30: ret
	return;
}

void sub_2B7E40(X86Context& ctx, uint8_t* base) {
	// 0x2B7E40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7E48: movss [0x005A37E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37E4u, ctx.xmm[0].u32[0]);
	// 0x2B7E50: ret
	return;
}

void sub_2B7E60(X86Context& ctx, uint8_t* base) {
	// 0x2B7E60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7E68: movss [0x005A3850], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3850u, ctx.xmm[0].u32[0]);
	// 0x2B7E70: ret
	return;
}

void sub_2B7E80(X86Context& ctx, uint8_t* base) {
	// 0x2B7E80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7E88: movss [0x005A386C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A386Cu, ctx.xmm[0].u32[0]);
	// 0x2B7E90: ret
	return;
}

void sub_2B7EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B7EA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7EA8: movss [0x005A3840], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3840u, ctx.xmm[0].u32[0]);
	// 0x2B7EB0: ret
	return;
}

void sub_2B7EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B7EC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7EC8: movss [0x005A37F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37F4u, ctx.xmm[0].u32[0]);
	// 0x2B7ED0: ret
	return;
}

void sub_2B7EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B7EE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B7EE8: movss [0x005A3854], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3854u, ctx.xmm[0].u32[0]);
	// 0x2B7EF0: ret
	return;
}

void sub_2B7F00(X86Context& ctx, uint8_t* base) {
	// 0x2B7F00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B7F08: movss [0x005A3810], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3810u, ctx.xmm[0].u32[0]);
	// 0x2B7F10: ret
	return;
}

void sub_2B7F20(X86Context& ctx, uint8_t* base) {
	// 0x2B7F20: movss xmm0, dword ptr [0x005A3854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3854u);
	// 0x2B7F28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B7F30: movss [0x005A388C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A388Cu, ctx.xmm[0].u32[0]);
	// 0x2B7F38: ret
	return;
}

void sub_2B7F40(X86Context& ctx, uint8_t* base) {
	// 0x2B7F40: movss xmm0, dword ptr [0x005A3810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3810u);
	// 0x2B7F48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B7F50: movss [0x005A3874], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3874u, ctx.xmm[0].u32[0]);
	// 0x2B7F58: ret
	return;
}

void sub_2B7F60(X86Context& ctx, uint8_t* base) {
	// 0x2B7F60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B7F68: movss [0x005A38A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38A4u, ctx.xmm[0].u32[0]);
	// 0x2B7F70: ret
	return;
}

void sub_2B7F80(X86Context& ctx, uint8_t* base) {
	// 0x2B7F80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B7F88: movss [0x005A3890], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3890u, ctx.xmm[0].u32[0]);
	// 0x2B7F90: ret
	return;
}

void sub_2B7FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B7FA0: movss xmm0, dword ptr [0x005A3890]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3890u);
	// 0x2B7FA8: movss [0x005A38A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38A0u, ctx.xmm[0].u32[0]);
	// 0x2B7FB0: ret
	return;
}

void sub_2B7FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B7FC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B7FC8: movss [0x005A37FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37FCu, ctx.xmm[0].u32[0]);
	// 0x2B7FD0: ret
	return;
}

void sub_2B7FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B7FE0: movss xmm0, dword ptr [0x005A3810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3810u);
	// 0x2B7FE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B7FF0: movss [0x005A3898], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3898u, ctx.xmm[0].u32[0]);
	// 0x2B7FF8: ret
	return;
}

void sub_2B8000(X86Context& ctx, uint8_t* base) {
	// 0x2B8000: movss xmm0, dword ptr [0x005A3810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3810u);
	// 0x2B8008: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B8010: movss [0x005A383C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A383Cu, ctx.xmm[0].u32[0]);
	// 0x2B8018: ret
	return;
}

void sub_2B8020(X86Context& ctx, uint8_t* base) {
	// 0x2B8020: movss xmm0, dword ptr [0x005A3810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3810u);
	// 0x2B8028: subss xmm0, [0x005A383C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A383Cu);
	// 0x2B8030: movss [0x005A3818], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3818u, ctx.xmm[0].u32[0]);
	// 0x2B8038: ret
	return;
}

void sub_2B8040(X86Context& ctx, uint8_t* base) {
	// 0x2B8040: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B8048: movss [0x005A3868], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3868u, ctx.xmm[0].u32[0]);
	// 0x2B8050: ret
	return;
}

void sub_2B8060(X86Context& ctx, uint8_t* base) {
	// 0x2B8060: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B8068: movss [0x005A3814], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3814u, ctx.xmm[0].u32[0]);
	// 0x2B8070: ret
	return;
}

void sub_2B8080(X86Context& ctx, uint8_t* base) {
	// 0x2B8080: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B8088: movss [0x005A3828], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3828u, ctx.xmm[0].u32[0]);
	// 0x2B8090: ret
	return;
}

void sub_2B80A0(X86Context& ctx, uint8_t* base) {
	// 0x2B80A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B80A8: movss [0x005A3880], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3880u, ctx.xmm[0].u32[0]);
	// 0x2B80B0: ret
	return;
}

void sub_2B80C0(X86Context& ctx, uint8_t* base) {
	// 0x2B80C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B80C8: movss [0x005A3864], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3864u, ctx.xmm[0].u32[0]);
	// 0x2B80D0: ret
	return;
}

void sub_2B80E0(X86Context& ctx, uint8_t* base) {
	// 0x2B80E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B80E8: movss [0x005A380C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A380Cu, ctx.xmm[0].u32[0]);
	// 0x2B80F0: ret
	return;
}

void sub_2B8100(X86Context& ctx, uint8_t* base) {
	// 0x2B8100: movss xmm0, dword ptr [0x005A3828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3828u);
	// 0x2B8108: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B8110: movss [0x005A3800], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3800u, ctx.xmm[0].u32[0]);
	// 0x2B8118: ret
	return;
}

void sub_2B8120(X86Context& ctx, uint8_t* base) {
	// 0x2B8120: movss xmm0, dword ptr [0x005A3880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3880u);
	// 0x2B8128: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B8130: movss [0x005A3848], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3848u, ctx.xmm[0].u32[0]);
	// 0x2B8138: ret
	return;
}

void sub_2B8140(X86Context& ctx, uint8_t* base) {
	// 0x2B8140: movss xmm0, dword ptr [0x005A3800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3800u);
	// 0x2B8148: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B8150: movss [0x005A385C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A385Cu, ctx.xmm[0].u32[0]);
	// 0x2B8158: ret
	return;
}

void sub_2B8160(X86Context& ctx, uint8_t* base) {
	// 0x2B8160: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B8168: movss [0x005A37F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A37F8u, ctx.xmm[0].u32[0]);
	// 0x2B8170: ret
	return;
}

void sub_2B8180(X86Context& ctx, uint8_t* base) {
	// 0x2B8180: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B8188: movss [0x005A382C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A382Cu, ctx.xmm[0].u32[0]);
	// 0x2B8190: ret
	return;
}

void sub_2B81A0(X86Context& ctx, uint8_t* base) {
	// 0x2B81A0: movss xmm0, dword ptr [0x005A3828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3828u);
	// 0x2B81A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B81B0: movss [0x005A3838], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3838u, ctx.xmm[0].u32[0]);
	// 0x2B81B8: ret
	return;
}

void sub_2B81C0(X86Context& ctx, uint8_t* base) {
	// 0x2B81C0: movss xmm0, dword ptr [0x005A3880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3880u);
	// 0x2B81C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B81D0: movss [0x005A3884], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3884u, ctx.xmm[0].u32[0]);
	// 0x2B81D8: ret
	return;
}

void sub_2B81E0(X86Context& ctx, uint8_t* base) {
	// 0x2B81E0: movss xmm0, dword ptr [0x005A3838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3838u);
	// 0x2B81E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B81F0: movss [0x005A3870], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3870u, ctx.xmm[0].u32[0]);
	// 0x2B81F8: ret
	return;
}

void sub_2B8200(X86Context& ctx, uint8_t* base) {
	// 0x2B8200: movss xmm0, dword ptr [0x005A3884]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3884u);
	// 0x2B8208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B8210: movss [0x005A3894], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3894u, ctx.xmm[0].u32[0]);
	// 0x2B8218: ret
	return;
}

void sub_2B8220(X86Context& ctx, uint8_t* base) {
	// 0x2B8220: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B8228: movss [0x005A3804], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3804u, ctx.xmm[0].u32[0]);
	// 0x2B8230: ret
	return;
}

void sub_2B8240(X86Context& ctx, uint8_t* base) {
	// 0x2B8240: movss xmm0, dword ptr [0x005A3828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3828u);
	// 0x2B8248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B8250: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B8258: movss [0x005A387C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A387Cu, ctx.xmm[0].u32[0]);
	// 0x2B8260: ret
	return;
}

void sub_2B8270(X86Context& ctx, uint8_t* base) {
	// 0x2B8270: movss xmm0, dword ptr [0x005A3880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3880u);
	// 0x2B8278: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B8280: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B8288: movss [0x005A381C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A381Cu, ctx.xmm[0].u32[0]);
	// 0x2B8290: ret
	return;
}

void sub_2B82A0(X86Context& ctx, uint8_t* base) {
	// 0x2B82A0: movss xmm0, dword ptr [0x005A3828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3828u);
	// 0x2B82A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B82B0: movss [0x005A3820], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3820u, ctx.xmm[0].u32[0]);
	// 0x2B82B8: ret
	return;
}

void sub_2B82C0(X86Context& ctx, uint8_t* base) {
	// 0x2B82C0: movss xmm0, dword ptr [0x005A3880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3880u);
	// 0x2B82C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B82D0: movss [0x005A3888], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3888u, ctx.xmm[0].u32[0]);
	// 0x2B82D8: ret
	return;
}

void sub_2B82E0(X86Context& ctx, uint8_t* base) {
	// 0x2B82E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B82E8: movss [0x005A3808], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3808u, ctx.xmm[0].u32[0]);
	// 0x2B82F0: ret
	return;
}

void sub_2B8300(X86Context& ctx, uint8_t* base) {
	// 0x2B8300: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B8308: movss [0x005A3834], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3834u, ctx.xmm[0].u32[0]);
	// 0x2B8310: ret
	return;
}

void sub_2B8320(X86Context& ctx, uint8_t* base) {
	// 0x2B8320: movss xmm0, dword ptr [0x005A3808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3808u);
	// 0x2B8328: movss [0x005A389C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A389Cu, ctx.xmm[0].u32[0]);
	// 0x2B8330: ret
	return;
}

void sub_2B8340(X86Context& ctx, uint8_t* base) {
	// 0x2B8340: movss xmm0, dword ptr [0x005A3880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3880u);
	// 0x2B8348: subss xmm0, [0x005A3808]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A3808u);
	// 0x2B8350: movss [0x005A3860], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3860u, ctx.xmm[0].u32[0]);
	// 0x2B8358: ret
	return;
}

void sub_2B8360(X86Context& ctx, uint8_t* base) {
	// 0x2B8360: movss xmm0, dword ptr [0x005A3860]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3860u);
	// 0x2B8368: subss xmm0, [0x005A3834]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A3834u);
	// 0x2B8370: movss [0x005A3858], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3858u, ctx.xmm[0].u32[0]);
	// 0x2B8378: ret
	return;
}

void sub_2B8380(X86Context& ctx, uint8_t* base) {
	// 0x2B8380: movss xmm0, dword ptr [0x005A3888]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3888u);
	// 0x2B8388: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B8390: movss [0x005A3844], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3844u, ctx.xmm[0].u32[0]);
	// 0x2B8398: ret
	return;
}

void sub_2B83A0(X86Context& ctx, uint8_t* base) {
	// 0x2B83A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B83A8: movss [0x005A3830], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3830u, ctx.xmm[0].u32[0]);
	// 0x2B83B0: ret
	return;
}

void sub_2B83C0(X86Context& ctx, uint8_t* base) {
	// 0x2B83C0: movss xmm0, dword ptr [0x005A3844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3844u);
	// 0x2B83C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B83D0: movss [0x005A3878], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3878u, ctx.xmm[0].u32[0]);
	// 0x2B83D8: ret
	return;
}

void sub_2B83E0(X86Context& ctx, uint8_t* base) {
	// 0x2B83E0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2B83E8: movss [0x005A384C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A384Cu, ctx.xmm[0].u32[0]);
	// 0x2B83F0: ret
	return;
}

void sub_2B8400(X86Context& ctx, uint8_t* base) {
	// 0x2B8400: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2B8408: movss [0x005A3824], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3824u, ctx.xmm[0].u32[0]);
	// 0x2B8410: ret
	return;
}

void sub_2B8420(X86Context& ctx, uint8_t* base) {
	// 0x2B8420: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8428: movss [0x005A38B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38B0u, ctx.xmm[0].u32[0]);
	// 0x2B8430: ret
	return;
}

void sub_2B8440(X86Context& ctx, uint8_t* base) {
	// 0x2B8440: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B8448: movss [0x005A38B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38B4u, ctx.xmm[0].u32[0]);
	// 0x2B8450: ret
	return;
}

void sub_2B8460(X86Context& ctx, uint8_t* base) {
	// 0x2B8460: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B8468: movss [0x005A38AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38ACu, ctx.xmm[0].u32[0]);
	// 0x2B8470: ret
	return;
}

void sub_2B8480(X86Context& ctx, uint8_t* base) {
	// 0x2B8480: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8488: movss [0x005A38A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38A8u, ctx.xmm[0].u32[0]);
	// 0x2B8490: ret
	return;
}

void sub_2B84A0(X86Context& ctx, uint8_t* base) {
	// 0x2B84A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B84A8: movss [0x005A38C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38C0u, ctx.xmm[0].u32[0]);
	// 0x2B84B0: ret
	return;
}

void sub_2B84C0(X86Context& ctx, uint8_t* base) {
	// 0x2B84C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B84C8: movss [0x005A38C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38C4u, ctx.xmm[0].u32[0]);
	// 0x2B84D0: ret
	return;
}

void sub_2B84E0(X86Context& ctx, uint8_t* base) {
	// 0x2B84E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B84E8: movss [0x005A38BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38BCu, ctx.xmm[0].u32[0]);
	// 0x2B84F0: ret
	return;
}

void sub_2B8500(X86Context& ctx, uint8_t* base) {
	// 0x2B8500: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8508: movss [0x005A38B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38B8u, ctx.xmm[0].u32[0]);
	// 0x2B8510: ret
	return;
}

void sub_2B8520(X86Context& ctx, uint8_t* base) {
	// 0x2B8520: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8528: movss [0x005A38D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38D0u, ctx.xmm[0].u32[0]);
	// 0x2B8530: ret
	return;
}

void sub_2B8540(X86Context& ctx, uint8_t* base) {
	// 0x2B8540: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B8548: movss [0x005A38D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38D4u, ctx.xmm[0].u32[0]);
	// 0x2B8550: ret
	return;
}

void sub_2B8560(X86Context& ctx, uint8_t* base) {
	// 0x2B8560: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B8568: movss [0x005A38CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38CCu, ctx.xmm[0].u32[0]);
	// 0x2B8570: ret
	return;
}

void sub_2B8580(X86Context& ctx, uint8_t* base) {
	// 0x2B8580: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8588: movss [0x005A38C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38C8u, ctx.xmm[0].u32[0]);
	// 0x2B8590: ret
	return;
}

void sub_2B85A0(X86Context& ctx, uint8_t* base) {
	// 0x2B85A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B85A8: movss [0x005A3950], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3950u, ctx.xmm[0].u32[0]);
	// 0x2B85B0: ret
	return;
}

void sub_2B85C0(X86Context& ctx, uint8_t* base) {
	// 0x2B85C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B85C8: movss [0x005A395C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A395Cu, ctx.xmm[0].u32[0]);
	// 0x2B85D0: ret
	return;
}

void sub_2B85E0(X86Context& ctx, uint8_t* base) {
	// 0x2B85E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B85E8: movss [0x005A3908], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3908u, ctx.xmm[0].u32[0]);
	// 0x2B85F0: ret
	return;
}

void sub_2B8600(X86Context& ctx, uint8_t* base) {
	// 0x2B8600: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8608: movss [0x005A38D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38D8u, ctx.xmm[0].u32[0]);
	// 0x2B8610: ret
	return;
}

void sub_2B8620(X86Context& ctx, uint8_t* base) {
	// 0x2B8620: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B8628: movss [0x005A3954], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3954u, ctx.xmm[0].u32[0]);
	// 0x2B8630: ret
	return;
}

void sub_2B8640(X86Context& ctx, uint8_t* base) {
	// 0x2B8640: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B8648: movss [0x005A38F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38F0u, ctx.xmm[0].u32[0]);
	// 0x2B8650: ret
	return;
}

void sub_2B8660(X86Context& ctx, uint8_t* base) {
	// 0x2B8660: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B8668: movss [0x005A3968], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3968u, ctx.xmm[0].u32[0]);
	// 0x2B8670: ret
	return;
}

void sub_2B8680(X86Context& ctx, uint8_t* base) {
	// 0x2B8680: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B8688: movss [0x005A3930], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3930u, ctx.xmm[0].u32[0]);
	// 0x2B8690: ret
	return;
}

void sub_2B86A0(X86Context& ctx, uint8_t* base) {
	// 0x2B86A0: movss xmm0, dword ptr [0x005A3968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3968u);
	// 0x2B86A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B86B0: movss [0x005A38F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38F8u, ctx.xmm[0].u32[0]);
	// 0x2B86B8: ret
	return;
}

void sub_2B86C0(X86Context& ctx, uint8_t* base) {
	// 0x2B86C0: movss xmm0, dword ptr [0x005A3930]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3930u);
	// 0x2B86C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B86D0: movss [0x005A3960], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3960u, ctx.xmm[0].u32[0]);
	// 0x2B86D8: ret
	return;
}

void sub_2B86E0(X86Context& ctx, uint8_t* base) {
	// 0x2B86E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B86E8: movss [0x005A3974], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3974u, ctx.xmm[0].u32[0]);
	// 0x2B86F0: ret
	return;
}

void sub_2B8700(X86Context& ctx, uint8_t* base) {
	// 0x2B8700: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B8708: movss [0x005A396C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A396Cu, ctx.xmm[0].u32[0]);
	// 0x2B8710: ret
	return;
}

void sub_2B8720(X86Context& ctx, uint8_t* base) {
	// 0x2B8720: movss xmm0, dword ptr [0x005A396C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A396Cu);
	// 0x2B8728: movss [0x005A3970], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3970u, ctx.xmm[0].u32[0]);
	// 0x2B8730: ret
	return;
}

void sub_2B8740(X86Context& ctx, uint8_t* base) {
	// 0x2B8740: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B8748: movss [0x005A3904], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3904u, ctx.xmm[0].u32[0]);
	// 0x2B8750: ret
	return;
}

void sub_2B8760(X86Context& ctx, uint8_t* base) {
	// 0x2B8760: movss xmm0, dword ptr [0x005A3930]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3930u);
	// 0x2B8768: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B8770: movss [0x005A38FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38FCu, ctx.xmm[0].u32[0]);
	// 0x2B8778: ret
	return;
}

void sub_2B8780(X86Context& ctx, uint8_t* base) {
	// 0x2B8780: movss xmm0, dword ptr [0x005A3930]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3930u);
	// 0x2B8788: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B8790: movss [0x005A3958], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3958u, ctx.xmm[0].u32[0]);
	// 0x2B8798: ret
	return;
}

void sub_2B87A0(X86Context& ctx, uint8_t* base) {
	// 0x2B87A0: movss xmm0, dword ptr [0x005A3930]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3930u);
	// 0x2B87A8: subss xmm0, [0x005A3958]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A3958u);
	// 0x2B87B0: movss [0x005A38F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A38F4u, ctx.xmm[0].u32[0]);
	// 0x2B87B8: ret
	return;
}

void sub_2B87C0(X86Context& ctx, uint8_t* base) {
	// 0x2B87C0: movss xmm0, dword ptr [0x003B232C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B232Cu);
	// 0x2B87C8: movss [0x005A3900], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3900u, ctx.xmm[0].u32[0]);
	// 0x2B87D0: ret
	return;
}

void sub_2B87E0(X86Context& ctx, uint8_t* base) {
	// 0x2B87E0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B87E8: divss xmm0, [0x005A3900]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x5A3900u);
	// 0x2B87F0: movss [0x005A3964], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3964u, ctx.xmm[0].u32[0]);
	// 0x2B87F8: ret
	return;
}

void sub_2B8800(X86Context& ctx, uint8_t* base) {
	// 0x2B8800: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8808: movss [0x005A3980], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3980u, ctx.xmm[0].u32[0]);
	// 0x2B8810: ret
	return;
}

void sub_2B8820(X86Context& ctx, uint8_t* base) {
	// 0x2B8820: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B8828: movss [0x005A3984], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3984u, ctx.xmm[0].u32[0]);
	// 0x2B8830: ret
	return;
}

void sub_2B8840(X86Context& ctx, uint8_t* base) {
	// 0x2B8840: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B8848: movss [0x005A397C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A397Cu, ctx.xmm[0].u32[0]);
	// 0x2B8850: ret
	return;
}

void sub_2B8860(X86Context& ctx, uint8_t* base) {
	// 0x2B8860: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8868: movss [0x005A3978], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3978u, ctx.xmm[0].u32[0]);
	// 0x2B8870: ret
	return;
}

void sub_2B8880(X86Context& ctx, uint8_t* base) {
	// 0x2B8880: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8888: movss [0x005A39A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39A4u, ctx.xmm[0].u32[0]);
	// 0x2B8890: ret
	return;
}

void sub_2B88A0(X86Context& ctx, uint8_t* base) {
	// 0x2B88A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B88A8: movss [0x005A39B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39B0u, ctx.xmm[0].u32[0]);
	// 0x2B88B0: ret
	return;
}

void sub_2B88C0(X86Context& ctx, uint8_t* base) {
	// 0x2B88C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B88C8: movss [0x005A39A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39A0u, ctx.xmm[0].u32[0]);
	// 0x2B88D0: ret
	return;
}

void sub_2B88E0(X86Context& ctx, uint8_t* base) {
	// 0x2B88E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B88E8: movss [0x005A3988], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3988u, ctx.xmm[0].u32[0]);
	// 0x2B88F0: ret
	return;
}

void sub_2B8900(X86Context& ctx, uint8_t* base) {
	// 0x2B8900: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B8908: movss [0x005A39A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39A8u, ctx.xmm[0].u32[0]);
	// 0x2B8910: ret
	return;
}

void sub_2B8920(X86Context& ctx, uint8_t* base) {
	// 0x2B8920: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B8928: movss [0x005A3990], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3990u, ctx.xmm[0].u32[0]);
	// 0x2B8930: ret
	return;
}

void sub_2B8940(X86Context& ctx, uint8_t* base) {
	// 0x2B8940: movss xmm0, dword ptr [0x005A39A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A39A8u);
	// 0x2B8948: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B8950: movss [0x005A39B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39B8u, ctx.xmm[0].u32[0]);
	// 0x2B8958: ret
	return;
}

void sub_2B8960(X86Context& ctx, uint8_t* base) {
	// 0x2B8960: movss xmm0, dword ptr [0x005A3990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3990u);
	// 0x2B8968: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B8970: movss [0x005A39B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39B4u, ctx.xmm[0].u32[0]);
	// 0x2B8978: ret
	return;
}

void sub_2B8980(X86Context& ctx, uint8_t* base) {
	// 0x2B8980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B8988: movss [0x005A39C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39C8u, ctx.xmm[0].u32[0]);
	// 0x2B8990: ret
	return;
}

void sub_2B89A0(X86Context& ctx, uint8_t* base) {
	// 0x2B89A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B89A8: movss [0x005A39BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39BCu, ctx.xmm[0].u32[0]);
	// 0x2B89B0: ret
	return;
}

void sub_2B89C0(X86Context& ctx, uint8_t* base) {
	// 0x2B89C0: movss xmm0, dword ptr [0x005A39BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A39BCu);
	// 0x2B89C8: movss [0x005A39C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39C4u, ctx.xmm[0].u32[0]);
	// 0x2B89D0: ret
	return;
}

void sub_2B89E0(X86Context& ctx, uint8_t* base) {
	// 0x2B89E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B89E8: movss [0x005A398C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A398Cu, ctx.xmm[0].u32[0]);
	// 0x2B89F0: ret
	return;
}

void sub_2B8A00(X86Context& ctx, uint8_t* base) {
	// 0x2B8A00: movss xmm0, dword ptr [0x005A3990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3990u);
	// 0x2B8A08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B8A10: movss [0x005A39C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39C0u, ctx.xmm[0].u32[0]);
	// 0x2B8A18: ret
	return;
}

void sub_2B8A20(X86Context& ctx, uint8_t* base) {
	// 0x2B8A20: movss xmm0, dword ptr [0x005A3990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3990u);
	// 0x2B8A28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B8A30: movss [0x005A399C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A399Cu, ctx.xmm[0].u32[0]);
	// 0x2B8A38: ret
	return;
}

void sub_2B8A40(X86Context& ctx, uint8_t* base) {
	// 0x2B8A40: movss xmm0, dword ptr [0x005A3990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3990u);
	// 0x2B8A48: subss xmm0, [0x005A399C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A399Cu);
	// 0x2B8A50: movss [0x005A3998], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3998u, ctx.xmm[0].u32[0]);
	// 0x2B8A58: ret
	return;
}

void sub_2B8A60(X86Context& ctx, uint8_t* base) {
	// 0x2B8A60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B8A68: movss [0x005A39AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39ACu, ctx.xmm[0].u32[0]);
	// 0x2B8A70: ret
	return;
}

void sub_2B8A80(X86Context& ctx, uint8_t* base) {
	// 0x2B8A80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B8A88: movss [0x005A3994], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3994u, ctx.xmm[0].u32[0]);
	// 0x2B8A90: ret
	return;
}

void sub_2B8AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B8AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8AA8: movss [0x005A39D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39D0u, ctx.xmm[0].u32[0]);
	// 0x2B8AB0: ret
	return;
}

void sub_2B8AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B8AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B8AC8: movss [0x005A39D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39D4u, ctx.xmm[0].u32[0]);
	// 0x2B8AD0: ret
	return;
}

void sub_2B8AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B8AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B8AE8: movss [0x005A39CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39CCu, ctx.xmm[0].u32[0]);
	// 0x2B8AF0: ret
	return;
}

void sub_2B8B00(X86Context& ctx, uint8_t* base) {
	// 0x2B8B00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8B08: movss [0x005A3A08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A08u, ctx.xmm[0].u32[0]);
	// 0x2B8B10: ret
	return;
}

void sub_2B8B20(X86Context& ctx, uint8_t* base) {
	// 0x2B8B20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B8B28: movss [0x005A3A18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A18u, ctx.xmm[0].u32[0]);
	// 0x2B8B30: ret
	return;
}

void sub_2B8B40(X86Context& ctx, uint8_t* base) {
	// 0x2B8B40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B8B48: movss [0x005A39F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39F8u, ctx.xmm[0].u32[0]);
	// 0x2B8B50: ret
	return;
}

void sub_2B8B60(X86Context& ctx, uint8_t* base) {
	// 0x2B8B60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8B68: movss [0x005A39D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39D8u, ctx.xmm[0].u32[0]);
	// 0x2B8B70: ret
	return;
}

void sub_2B8B80(X86Context& ctx, uint8_t* base) {
	// 0x2B8B80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B8B88: movss [0x005A3A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A0Cu, ctx.xmm[0].u32[0]);
	// 0x2B8B90: ret
	return;
}

void sub_2B8BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B8BA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B8BA8: movss [0x005A39DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39DCu, ctx.xmm[0].u32[0]);
	// 0x2B8BB0: ret
	return;
}

void sub_2B8BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B8BC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B8BC8: movss [0x005A3A24], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A24u, ctx.xmm[0].u32[0]);
	// 0x2B8BD0: ret
	return;
}

void sub_2B8BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B8BE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B8BE8: movss [0x005A3A00], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A00u, ctx.xmm[0].u32[0]);
	// 0x2B8BF0: ret
	return;
}

void sub_2B8C00(X86Context& ctx, uint8_t* base) {
	// 0x2B8C00: movss xmm0, dword ptr [0x005A3A24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A24u);
	// 0x2B8C08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B8C10: movss [0x005A39E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39E8u, ctx.xmm[0].u32[0]);
	// 0x2B8C18: ret
	return;
}

void sub_2B8C20(X86Context& ctx, uint8_t* base) {
	// 0x2B8C20: movss xmm0, dword ptr [0x005A3A00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A00u);
	// 0x2B8C28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B8C30: movss [0x005A3A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A1Cu, ctx.xmm[0].u32[0]);
	// 0x2B8C38: ret
	return;
}

void sub_2B8C40(X86Context& ctx, uint8_t* base) {
	// 0x2B8C40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B8C48: movss [0x005A3A30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A30u, ctx.xmm[0].u32[0]);
	// 0x2B8C50: ret
	return;
}

void sub_2B8C60(X86Context& ctx, uint8_t* base) {
	// 0x2B8C60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B8C68: movss [0x005A3A28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A28u, ctx.xmm[0].u32[0]);
	// 0x2B8C70: ret
	return;
}

void sub_2B8C80(X86Context& ctx, uint8_t* base) {
	// 0x2B8C80: movss xmm0, dword ptr [0x005A3A28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A28u);
	// 0x2B8C88: movss [0x005A3A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A2Cu, ctx.xmm[0].u32[0]);
	// 0x2B8C90: ret
	return;
}

void sub_2B8CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B8CA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B8CA8: movss [0x005A39F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39F4u, ctx.xmm[0].u32[0]);
	// 0x2B8CB0: ret
	return;
}

void sub_2B8CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B8CC0: movss xmm0, dword ptr [0x005A3A00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A00u);
	// 0x2B8CC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B8CD0: movss [0x005A39F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39F0u, ctx.xmm[0].u32[0]);
	// 0x2B8CD8: ret
	return;
}

void sub_2B8CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B8CE0: movss xmm0, dword ptr [0x005A3A00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A00u);
	// 0x2B8CE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B8CF0: movss [0x005A3A14], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A14u, ctx.xmm[0].u32[0]);
	// 0x2B8CF8: ret
	return;
}

void sub_2B8D00(X86Context& ctx, uint8_t* base) {
	// 0x2B8D00: movss xmm0, dword ptr [0x005A3A00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A00u);
	// 0x2B8D08: subss xmm0, [0x005A3A14]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A3A14u);
	// 0x2B8D10: movss [0x005A39E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39E4u, ctx.xmm[0].u32[0]);
	// 0x2B8D18: ret
	return;
}

void sub_2B8D20(X86Context& ctx, uint8_t* base) {
	// 0x2B8D20: movss xmm0, dword ptr [0x003B1A5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A5Cu);
	// 0x2B8D28: movss [0x005A39EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39ECu, ctx.xmm[0].u32[0]);
	// 0x2B8D30: ret
	return;
}

void sub_2B8D40(X86Context& ctx, uint8_t* base) {
	// 0x2B8D40: movss xmm0, dword ptr [0x003B2330]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2330u);
	// 0x2B8D48: movss [0x005A3A20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A20u, ctx.xmm[0].u32[0]);
	// 0x2B8D50: ret
	return;
}

void sub_2B8D60(X86Context& ctx, uint8_t* base) {
	// 0x2B8D60: movss xmm0, dword ptr [0x003B1A5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A5Cu);
	// 0x2B8D68: movss [0x005A3A10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A10u, ctx.xmm[0].u32[0]);
	// 0x2B8D70: ret
	return;
}

void sub_2B8D80(X86Context& ctx, uint8_t* base) {
	// 0x2B8D80: movss xmm0, dword ptr [0x0039A850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39A850u);
	// 0x2B8D88: movss [0x005A39E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39E0u, ctx.xmm[0].u32[0]);
	// 0x2B8D90: ret
	return;
}

void sub_2B8DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B8DA0: movss xmm0, dword ptr [0x0039A854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39A854u);
	// 0x2B8DA8: movss [0x005A39FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A39FCu, ctx.xmm[0].u32[0]);
	// 0x2B8DB0: ret
	return;
}

void sub_2B8DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B8DC0: movss xmm0, dword ptr [0x0039A858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39A858u);
	// 0x2B8DC8: movss [0x005A3A04], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A04u, ctx.xmm[0].u32[0]);
	// 0x2B8DD0: ret
	return;
}

void sub_2B8DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B8DE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B8DE8: movss [0x005A3A54], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A54u, ctx.xmm[0].u32[0]);
	// 0x2B8DF0: ret
	return;
}

void sub_2B8E00(X86Context& ctx, uint8_t* base) {
	// 0x2B8E00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B8E08: movss [0x005A3A60], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A60u, ctx.xmm[0].u32[0]);
	// 0x2B8E10: ret
	return;
}

void sub_2B8E20(X86Context& ctx, uint8_t* base) {
	// 0x2B8E20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B8E28: movss [0x005A3A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A4Cu, ctx.xmm[0].u32[0]);
	// 0x2B8E30: ret
	return;
}

void sub_2B8E40(X86Context& ctx, uint8_t* base) {
	// 0x2B8E40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B8E48: movss [0x005A3A34], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A34u, ctx.xmm[0].u32[0]);
	// 0x2B8E50: ret
	return;
}

void sub_2B8E60(X86Context& ctx, uint8_t* base) {
	// 0x2B8E60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B8E68: movss [0x005A3A58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A58u, ctx.xmm[0].u32[0]);
	// 0x2B8E70: ret
	return;
}

void sub_2B8E80(X86Context& ctx, uint8_t* base) {
	// 0x2B8E80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B8E88: movss [0x005A3A38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A38u, ctx.xmm[0].u32[0]);
	// 0x2B8E90: ret
	return;
}

void sub_2B8EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B8EA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B8EA8: movss [0x005A3A68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A68u, ctx.xmm[0].u32[0]);
	// 0x2B8EB0: ret
	return;
}

void sub_2B8EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B8EC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B8EC8: movss [0x005A3A50], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A50u, ctx.xmm[0].u32[0]);
	// 0x2B8ED0: ret
	return;
}

void sub_2B8EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B8EE0: movss xmm0, dword ptr [0x005A3A68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A68u);
	// 0x2B8EE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B8EF0: movss [0x005A3A40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A40u, ctx.xmm[0].u32[0]);
	// 0x2B8EF8: ret
	return;
}

void sub_2B8F00(X86Context& ctx, uint8_t* base) {
	// 0x2B8F00: movss xmm0, dword ptr [0x005A3A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A50u);
	// 0x2B8F08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B8F10: movss [0x005A3A64], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A64u, ctx.xmm[0].u32[0]);
	// 0x2B8F18: ret
	return;
}

void sub_2B8F20(X86Context& ctx, uint8_t* base) {
	// 0x2B8F20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B8F28: movss [0x005A3A74], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A74u, ctx.xmm[0].u32[0]);
	// 0x2B8F30: ret
	return;
}

void sub_2B8F40(X86Context& ctx, uint8_t* base) {
	// 0x2B8F40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B8F48: movss [0x005A3A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A6Cu, ctx.xmm[0].u32[0]);
	// 0x2B8F50: ret
	return;
}

void sub_2B8F60(X86Context& ctx, uint8_t* base) {
	// 0x2B8F60: movss xmm0, dword ptr [0x005A3A6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A6Cu);
	// 0x2B8F68: movss [0x005A3A70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A70u, ctx.xmm[0].u32[0]);
	// 0x2B8F70: ret
	return;
}

void sub_2B8F80(X86Context& ctx, uint8_t* base) {
	// 0x2B8F80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B8F88: movss [0x005A3A48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A48u, ctx.xmm[0].u32[0]);
	// 0x2B8F90: ret
	return;
}

void sub_2B8FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B8FA0: movss xmm0, dword ptr [0x005A3A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A50u);
	// 0x2B8FA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B8FB0: movss [0x005A3A44], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A44u, ctx.xmm[0].u32[0]);
	// 0x2B8FB8: ret
	return;
}

void sub_2B8FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B8FC0: movss xmm0, dword ptr [0x005A3A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A50u);
	// 0x2B8FC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B8FD0: movss [0x005A3A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A5Cu, ctx.xmm[0].u32[0]);
	// 0x2B8FD8: ret
	return;
}

void sub_2B8FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B8FE0: movss xmm0, dword ptr [0x005A3A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A3A50u);
	// 0x2B8FE8: subss xmm0, [0x005A3A5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A3A5Cu);
	// 0x2B8FF0: movss [0x005A3A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A3Cu, ctx.xmm[0].u32[0]);
	// 0x2B8FF8: ret
	return;
}

void sub_2B9000(X86Context& ctx, uint8_t* base) {
	// 0x2B9000: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9008: movss [0x005A3A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A7Cu, ctx.xmm[0].u32[0]);
	// 0x2B9010: ret
	return;
}

void sub_2B9020(X86Context& ctx, uint8_t* base) {
	// 0x2B9020: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9028: movss [0x005A3A80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A80u, ctx.xmm[0].u32[0]);
	// 0x2B9030: ret
	return;
}

void sub_2B9040(X86Context& ctx, uint8_t* base) {
	// 0x2B9040: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9048: movss [0x005A3A78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A78u, ctx.xmm[0].u32[0]);
	// 0x2B9050: ret
	return;
}

void sub_2B9060(X86Context& ctx, uint8_t* base) {
	// 0x2B9060: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B9068: movss [0x005A5378], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5378u, ctx.xmm[0].u32[0]);
	// 0x2B9070: ret
	return;
}

void sub_2B9080(X86Context& ctx, uint8_t* base) {
	// 0x2B9080: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9088: movss [0x005A5384], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5384u, ctx.xmm[0].u32[0]);
	// 0x2B9090: ret
	return;
}

void sub_2B90A0(X86Context& ctx, uint8_t* base) {
	// 0x2B90A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B90A8: movss [0x005A5370], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5370u, ctx.xmm[0].u32[0]);
	// 0x2B90B0: ret
	return;
}

void sub_2B90C0(X86Context& ctx, uint8_t* base) {
	// 0x2B90C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B90C8: movss [0x005A3A84], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A84u, ctx.xmm[0].u32[0]);
	// 0x2B90D0: ret
	return;
}

void sub_2B90E0(X86Context& ctx, uint8_t* base) {
	// 0x2B90E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B90E8: movss [0x005A537C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A537Cu, ctx.xmm[0].u32[0]);
	// 0x2B90F0: ret
	return;
}

void sub_2B9100(X86Context& ctx, uint8_t* base) {
	// 0x2B9100: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B9108: movss [0x005A3A88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A88u, ctx.xmm[0].u32[0]);
	// 0x2B9110: ret
	return;
}

void sub_2B9120(X86Context& ctx, uint8_t* base) {
	// 0x2B9120: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B9128: movss [0x005A5390], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5390u, ctx.xmm[0].u32[0]);
	// 0x2B9130: ret
	return;
}

void sub_2B9140(X86Context& ctx, uint8_t* base) {
	// 0x2B9140: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B9148: movss [0x005A5374], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5374u, ctx.xmm[0].u32[0]);
	// 0x2B9150: ret
	return;
}

void sub_2B9160(X86Context& ctx, uint8_t* base) {
	// 0x2B9160: movss xmm0, dword ptr [0x005A5390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A5390u);
	// 0x2B9168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B9170: movss [0x005A3A90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A90u, ctx.xmm[0].u32[0]);
	// 0x2B9178: ret
	return;
}

void sub_2B9180(X86Context& ctx, uint8_t* base) {
	// 0x2B9180: movss xmm0, dword ptr [0x005A5374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A5374u);
	// 0x2B9188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B9190: movss [0x005A5388], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5388u, ctx.xmm[0].u32[0]);
	// 0x2B9198: ret
	return;
}

void sub_2B91A0(X86Context& ctx, uint8_t* base) {
	// 0x2B91A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B91A8: movss [0x005A539C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A539Cu, ctx.xmm[0].u32[0]);
	// 0x2B91B0: ret
	return;
}

void sub_2B91C0(X86Context& ctx, uint8_t* base) {
	// 0x2B91C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B91C8: movss [0x005A5394], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5394u, ctx.xmm[0].u32[0]);
	// 0x2B91D0: ret
	return;
}

void sub_2B91E0(X86Context& ctx, uint8_t* base) {
	// 0x2B91E0: movss xmm0, dword ptr [0x005A5394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A5394u);
	// 0x2B91E8: movss [0x005A5398], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5398u, ctx.xmm[0].u32[0]);
	// 0x2B91F0: ret
	return;
}

void sub_2B9200(X86Context& ctx, uint8_t* base) {
	// 0x2B9200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9208: movss [0x005A3A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A9Cu, ctx.xmm[0].u32[0]);
	// 0x2B9210: ret
	return;
}

void sub_2B9220(X86Context& ctx, uint8_t* base) {
	// 0x2B9220: movss xmm0, dword ptr [0x005A5374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A5374u);
	// 0x2B9228: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9230: movss [0x005A3A98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A98u, ctx.xmm[0].u32[0]);
	// 0x2B9238: ret
	return;
}

void sub_2B9240(X86Context& ctx, uint8_t* base) {
	// 0x2B9240: movss xmm0, dword ptr [0x005A5374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A5374u);
	// 0x2B9248: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B9250: movss [0x005A5380], xmm0
	X86_MEM_WRITE_u32(base, 0x5A5380u, ctx.xmm[0].u32[0]);
	// 0x2B9258: ret
	return;
}

void sub_2B9260(X86Context& ctx, uint8_t* base) {
	// 0x2B9260: movss xmm0, dword ptr [0x005A5374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A5374u);
	// 0x2B9268: subss xmm0, [0x005A5380]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A5380u);
	// 0x2B9270: movss [0x005A3A8C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A8Cu, ctx.xmm[0].u32[0]);
	// 0x2B9278: ret
	return;
}

void sub_2B9280(X86Context& ctx, uint8_t* base) {
	// 0x2B9280: movss xmm0, dword ptr [0x003B1D38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1D38u);
	// 0x2B9288: movss [0x005A3A94], xmm0
	X86_MEM_WRITE_u32(base, 0x5A3A94u, ctx.xmm[0].u32[0]);
	// 0x2B9290: ret
	return;
}

void sub_2B92A0(X86Context& ctx, uint8_t* base) {
	// 0x2B92A0: movss xmm0, dword ptr [0x003B2334]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2334u);
	// 0x2B92A8: movss [0x005A538C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A538Cu, ctx.xmm[0].u32[0]);
	// 0x2B92B0: ret
	return;
}

void sub_2B92C0(X86Context& ctx, uint8_t* base) {
	// 0x2B92C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B92C8: movss [0x005A7664], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7664u, ctx.xmm[0].u32[0]);
	// 0x2B92D0: ret
	return;
}

void sub_2B92E0(X86Context& ctx, uint8_t* base) {
	// 0x2B92E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B92E8: movss [0x005A7670], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7670u, ctx.xmm[0].u32[0]);
	// 0x2B92F0: ret
	return;
}

void sub_2B9300(X86Context& ctx, uint8_t* base) {
	// 0x2B9300: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9308: movss [0x005A7660], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7660u, ctx.xmm[0].u32[0]);
	// 0x2B9310: ret
	return;
}

void sub_2B9320(X86Context& ctx, uint8_t* base) {
	// 0x2B9320: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9328: movss [0x005A53A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A53A0u, ctx.xmm[0].u32[0]);
	// 0x2B9330: ret
	return;
}

void sub_2B9340(X86Context& ctx, uint8_t* base) {
	// 0x2B9340: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B9348: movss [0x005A7668], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7668u, ctx.xmm[0].u32[0]);
	// 0x2B9350: ret
	return;
}

void sub_2B9360(X86Context& ctx, uint8_t* base) {
	// 0x2B9360: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B9368: movss [0x005A53A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A53A8u, ctx.xmm[0].u32[0]);
	// 0x2B9370: ret
	return;
}

void sub_2B9380(X86Context& ctx, uint8_t* base) {
	// 0x2B9380: movss xmm0, dword ptr [0x005A7668]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A7668u);
	// 0x2B9388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B9390: movss [0x005A7678], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7678u, ctx.xmm[0].u32[0]);
	// 0x2B9398: ret
	return;
}

void sub_2B93A0(X86Context& ctx, uint8_t* base) {
	// 0x2B93A0: movss xmm0, dword ptr [0x005A53A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A53A8u);
	// 0x2B93A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B93B0: movss [0x005A7674], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7674u, ctx.xmm[0].u32[0]);
	// 0x2B93B8: ret
	return;
}

void sub_2B93C0(X86Context& ctx, uint8_t* base) {
	// 0x2B93C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B93C8: movss [0x005A7688], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7688u, ctx.xmm[0].u32[0]);
	// 0x2B93D0: ret
	return;
}

void sub_2B93E0(X86Context& ctx, uint8_t* base) {
	// 0x2B93E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B93E8: movss [0x005A767C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A767Cu, ctx.xmm[0].u32[0]);
	// 0x2B93F0: ret
	return;
}

void sub_2B9400(X86Context& ctx, uint8_t* base) {
	// 0x2B9400: movss xmm0, dword ptr [0x005A767C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A767Cu);
	// 0x2B9408: movss [0x005A7684], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7684u, ctx.xmm[0].u32[0]);
	// 0x2B9410: ret
	return;
}

void sub_2B9420(X86Context& ctx, uint8_t* base) {
	// 0x2B9420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B9428: movss [0x005A53A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A53A4u, ctx.xmm[0].u32[0]);
	// 0x2B9430: ret
	return;
}

void sub_2B9440(X86Context& ctx, uint8_t* base) {
	// 0x2B9440: movss xmm0, dword ptr [0x005A53A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A53A8u);
	// 0x2B9448: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B9450: movss [0x005A7680], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7680u, ctx.xmm[0].u32[0]);
	// 0x2B9458: ret
	return;
}

void sub_2B9460(X86Context& ctx, uint8_t* base) {
	// 0x2B9460: movss xmm0, dword ptr [0x005A53A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A53A8u);
	// 0x2B9468: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B9470: movss [0x005A62C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A62C0u, ctx.xmm[0].u32[0]);
	// 0x2B9478: ret
	return;
}

void sub_2B9480(X86Context& ctx, uint8_t* base) {
	// 0x2B9480: movss xmm0, dword ptr [0x005A53A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A53A8u);
	// 0x2B9488: subss xmm0, [0x005A62C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A62C0u);
	// 0x2B9490: movss [0x005A53B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A53B0u, ctx.xmm[0].u32[0]);
	// 0x2B9498: ret
	return;
}

void sub_2B94A0(X86Context& ctx, uint8_t* base) {
	// 0x2B94A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B94A8: movss [0x005A766C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A766Cu, ctx.xmm[0].u32[0]);
	// 0x2B94B0: ret
	return;
}

void sub_2B94C0(X86Context& ctx, uint8_t* base) {
	// 0x2B94C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B94C8: movss [0x005A53AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A53ACu, ctx.xmm[0].u32[0]);
	// 0x2B94D0: ret
	return;
}

void sub_2B94E0(X86Context& ctx, uint8_t* base) {
	// 0x2B94E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B94E8: movss [0x005A76A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76A8u, ctx.xmm[0].u32[0]);
	// 0x2B94F0: ret
	return;
}

void sub_2B9500(X86Context& ctx, uint8_t* base) {
	// 0x2B9500: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B9508: movss [0x005A76B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76B4u, ctx.xmm[0].u32[0]);
	// 0x2B9510: ret
	return;
}

void sub_2B9520(X86Context& ctx, uint8_t* base) {
	// 0x2B9520: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B9528: movss [0x005A76A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76A4u, ctx.xmm[0].u32[0]);
	// 0x2B9530: ret
	return;
}

void sub_2B9540(X86Context& ctx, uint8_t* base) {
	// 0x2B9540: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B9548: movss [0x005A768C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A768Cu, ctx.xmm[0].u32[0]);
	// 0x2B9550: ret
	return;
}

void sub_2B9560(X86Context& ctx, uint8_t* base) {
	// 0x2B9560: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B9568: movss [0x005A76AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76ACu, ctx.xmm[0].u32[0]);
	// 0x2B9570: ret
	return;
}

void sub_2B9580(X86Context& ctx, uint8_t* base) {
	// 0x2B9580: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B9588: movss [0x005A7694], xmm0
	X86_MEM_WRITE_u32(base, 0x5A7694u, ctx.xmm[0].u32[0]);
	// 0x2B9590: ret
	return;
}

void sub_2B95A0(X86Context& ctx, uint8_t* base) {
	// 0x2B95A0: movss xmm0, dword ptr [0x005A76AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A76ACu);
	// 0x2B95A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B95B0: movss [0x005A76BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A76BCu, ctx.xmm[0].u32[0]);
	// 0x2B95B8: ret
	return;
}

