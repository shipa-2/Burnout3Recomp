#include "x86_recomp_shared.h"

void sub_2BB5D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB5D0: movss xmm0, dword ptr [0x005A840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A840Cu);
	// 0x2BB5D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BB5E0: movss [0x005A8400], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8400u, ctx.xmm[0].u32[0]);
	// 0x2BB5E8: ret
	return;
}

void sub_2BB5F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB5F0: movss xmm0, dword ptr [0x005A840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A840Cu);
	// 0x2BB5F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BB600: movss [0x005A8418], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8418u, ctx.xmm[0].u32[0]);
	// 0x2BB608: ret
	return;
}

void sub_2BB610(X86Context& ctx, uint8_t* base) {
	// 0x2BB610: movss xmm0, dword ptr [0x005A840C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A840Cu);
	// 0x2BB618: subss xmm0, [0x005A8418]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8418u);
	// 0x2BB620: movss [0x005A83F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A83F8u, ctx.xmm[0].u32[0]);
	// 0x2BB628: ret
	return;
}

void sub_2BB630(X86Context& ctx, uint8_t* base) {
	// 0x2BB630: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BB638: movss [0x005A8450], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8450u, ctx.xmm[0].u32[0]);
	// 0x2BB640: ret
	return;
}

void sub_2BB650(X86Context& ctx, uint8_t* base) {
	// 0x2BB650: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BB658: movss [0x005A845C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A845Cu, ctx.xmm[0].u32[0]);
	// 0x2BB660: ret
	return;
}

void sub_2BB670(X86Context& ctx, uint8_t* base) {
	// 0x2BB670: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BB678: movss [0x005A844C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A844Cu, ctx.xmm[0].u32[0]);
	// 0x2BB680: ret
	return;
}

void sub_2BB690(X86Context& ctx, uint8_t* base) {
	// 0x2BB690: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BB698: movss [0x005A8434], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8434u, ctx.xmm[0].u32[0]);
	// 0x2BB6A0: ret
	return;
}

void sub_2BB6B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB6B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BB6B8: movss [0x005A8454], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8454u, ctx.xmm[0].u32[0]);
	// 0x2BB6C0: ret
	return;
}

void sub_2BB6D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB6D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BB6D8: movss [0x005A843C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A843Cu, ctx.xmm[0].u32[0]);
	// 0x2BB6E0: ret
	return;
}

void sub_2BB6F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB6F0: movss xmm0, dword ptr [0x005A8454]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8454u);
	// 0x2BB6F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BB700: movss [0x005A8464], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8464u, ctx.xmm[0].u32[0]);
	// 0x2BB708: ret
	return;
}

void sub_2BB710(X86Context& ctx, uint8_t* base) {
	// 0x2BB710: movss xmm0, dword ptr [0x005A843C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A843Cu);
	// 0x2BB718: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BB720: movss [0x005A8460], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8460u, ctx.xmm[0].u32[0]);
	// 0x2BB728: ret
	return;
}

void sub_2BB730(X86Context& ctx, uint8_t* base) {
	// 0x2BB730: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB738: movss [0x005A8474], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8474u, ctx.xmm[0].u32[0]);
	// 0x2BB740: ret
	return;
}

void sub_2BB750(X86Context& ctx, uint8_t* base) {
	// 0x2BB750: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BB758: movss [0x005A8468], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8468u, ctx.xmm[0].u32[0]);
	// 0x2BB760: ret
	return;
}

void sub_2BB770(X86Context& ctx, uint8_t* base) {
	// 0x2BB770: movss xmm0, dword ptr [0x005A8468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8468u);
	// 0x2BB778: movss [0x005A8470], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8470u, ctx.xmm[0].u32[0]);
	// 0x2BB780: ret
	return;
}

void sub_2BB790(X86Context& ctx, uint8_t* base) {
	// 0x2BB790: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB798: movss [0x005A8438], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8438u, ctx.xmm[0].u32[0]);
	// 0x2BB7A0: ret
	return;
}

void sub_2BB7B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB7B0: movss xmm0, dword ptr [0x005A843C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A843Cu);
	// 0x2BB7B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BB7C0: movss [0x005A846C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A846Cu, ctx.xmm[0].u32[0]);
	// 0x2BB7C8: ret
	return;
}

void sub_2BB7D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB7D0: movss xmm0, dword ptr [0x005A843C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A843Cu);
	// 0x2BB7D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BB7E0: movss [0x005A8448], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8448u, ctx.xmm[0].u32[0]);
	// 0x2BB7E8: ret
	return;
}

void sub_2BB7F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB7F0: movss xmm0, dword ptr [0x005A843C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A843Cu);
	// 0x2BB7F8: subss xmm0, [0x005A8448]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8448u);
	// 0x2BB800: movss [0x005A8444], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8444u, ctx.xmm[0].u32[0]);
	// 0x2BB808: ret
	return;
}

void sub_2BB810(X86Context& ctx, uint8_t* base) {
	// 0x2BB810: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BB818: movss [0x005A8458], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8458u, ctx.xmm[0].u32[0]);
	// 0x2BB820: ret
	return;
}

void sub_2BB830(X86Context& ctx, uint8_t* base) {
	// 0x2BB830: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BB838: movss [0x005A8440], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8440u, ctx.xmm[0].u32[0]);
	// 0x2BB840: ret
	return;
}

void sub_2BB850(X86Context& ctx, uint8_t* base) {
	// 0x2BB850: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BB858: movss [0x005A8494], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8494u, ctx.xmm[0].u32[0]);
	// 0x2BB860: ret
	return;
}

void sub_2BB870(X86Context& ctx, uint8_t* base) {
	// 0x2BB870: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BB878: movss [0x005A84A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84A0u, ctx.xmm[0].u32[0]);
	// 0x2BB880: ret
	return;
}

void sub_2BB890(X86Context& ctx, uint8_t* base) {
	// 0x2BB890: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BB898: movss [0x005A8490], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8490u, ctx.xmm[0].u32[0]);
	// 0x2BB8A0: ret
	return;
}

void sub_2BB8B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB8B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BB8B8: movss [0x005A8478], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8478u, ctx.xmm[0].u32[0]);
	// 0x2BB8C0: ret
	return;
}

void sub_2BB8D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB8D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BB8D8: movss [0x005A8498], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8498u, ctx.xmm[0].u32[0]);
	// 0x2BB8E0: ret
	return;
}

void sub_2BB8F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB8F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BB8F8: movss [0x005A8480], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8480u, ctx.xmm[0].u32[0]);
	// 0x2BB900: ret
	return;
}

void sub_2BB910(X86Context& ctx, uint8_t* base) {
	// 0x2BB910: movss xmm0, dword ptr [0x005A8498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8498u);
	// 0x2BB918: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BB920: movss [0x005A84A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84A8u, ctx.xmm[0].u32[0]);
	// 0x2BB928: ret
	return;
}

void sub_2BB930(X86Context& ctx, uint8_t* base) {
	// 0x2BB930: movss xmm0, dword ptr [0x005A8480]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8480u);
	// 0x2BB938: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BB940: movss [0x005A84A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84A4u, ctx.xmm[0].u32[0]);
	// 0x2BB948: ret
	return;
}

void sub_2BB950(X86Context& ctx, uint8_t* base) {
	// 0x2BB950: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB958: movss [0x005A84B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84B8u, ctx.xmm[0].u32[0]);
	// 0x2BB960: ret
	return;
}

void sub_2BB970(X86Context& ctx, uint8_t* base) {
	// 0x2BB970: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BB978: movss [0x005A84AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84ACu, ctx.xmm[0].u32[0]);
	// 0x2BB980: ret
	return;
}

void sub_2BB990(X86Context& ctx, uint8_t* base) {
	// 0x2BB990: movss xmm0, dword ptr [0x005A84AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84ACu);
	// 0x2BB998: movss [0x005A84B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84B4u, ctx.xmm[0].u32[0]);
	// 0x2BB9A0: ret
	return;
}

void sub_2BB9B0(X86Context& ctx, uint8_t* base) {
	// 0x2BB9B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BB9B8: movss [0x005A847C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A847Cu, ctx.xmm[0].u32[0]);
	// 0x2BB9C0: ret
	return;
}

void sub_2BB9D0(X86Context& ctx, uint8_t* base) {
	// 0x2BB9D0: movss xmm0, dword ptr [0x005A8480]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8480u);
	// 0x2BB9D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BB9E0: movss [0x005A84B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84B0u, ctx.xmm[0].u32[0]);
	// 0x2BB9E8: ret
	return;
}

void sub_2BB9F0(X86Context& ctx, uint8_t* base) {
	// 0x2BB9F0: movss xmm0, dword ptr [0x005A8480]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8480u);
	// 0x2BB9F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BBA00: movss [0x005A848C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A848Cu, ctx.xmm[0].u32[0]);
	// 0x2BBA08: ret
	return;
}

void sub_2BBA10(X86Context& ctx, uint8_t* base) {
	// 0x2BBA10: movss xmm0, dword ptr [0x005A8480]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8480u);
	// 0x2BBA18: subss xmm0, [0x005A848C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A848Cu);
	// 0x2BBA20: movss [0x005A8488], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8488u, ctx.xmm[0].u32[0]);
	// 0x2BBA28: ret
	return;
}

void sub_2BBA30(X86Context& ctx, uint8_t* base) {
	// 0x2BBA30: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BBA38: movss [0x005A849C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A849Cu, ctx.xmm[0].u32[0]);
	// 0x2BBA40: ret
	return;
}

void sub_2BBA50(X86Context& ctx, uint8_t* base) {
	// 0x2BBA50: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BBA58: movss [0x005A8484], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8484u, ctx.xmm[0].u32[0]);
	// 0x2BBA60: ret
	return;
}

void sub_2BBA70(X86Context& ctx, uint8_t* base) {
	// 0x2BBA70: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BBA78: movss [0x005A84D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84D8u, ctx.xmm[0].u32[0]);
	// 0x2BBA80: ret
	return;
}

void sub_2BBA90(X86Context& ctx, uint8_t* base) {
	// 0x2BBA90: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BBA98: movss [0x005A84E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84E4u, ctx.xmm[0].u32[0]);
	// 0x2BBAA0: ret
	return;
}

void sub_2BBAB0(X86Context& ctx, uint8_t* base) {
	// 0x2BBAB0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BBAB8: movss [0x005A84D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84D4u, ctx.xmm[0].u32[0]);
	// 0x2BBAC0: ret
	return;
}

void sub_2BBAD0(X86Context& ctx, uint8_t* base) {
	// 0x2BBAD0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BBAD8: movss [0x005A84BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84BCu, ctx.xmm[0].u32[0]);
	// 0x2BBAE0: ret
	return;
}

void sub_2BBAF0(X86Context& ctx, uint8_t* base) {
	// 0x2BBAF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BBAF8: movss [0x005A84DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84DCu, ctx.xmm[0].u32[0]);
	// 0x2BBB00: ret
	return;
}

void sub_2BBB10(X86Context& ctx, uint8_t* base) {
	// 0x2BBB10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BBB18: movss [0x005A84C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84C4u, ctx.xmm[0].u32[0]);
	// 0x2BBB20: ret
	return;
}

void sub_2BBB30(X86Context& ctx, uint8_t* base) {
	// 0x2BBB30: movss xmm0, dword ptr [0x005A84DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84DCu);
	// 0x2BBB38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BBB40: movss [0x005A84EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84ECu, ctx.xmm[0].u32[0]);
	// 0x2BBB48: ret
	return;
}

void sub_2BBB50(X86Context& ctx, uint8_t* base) {
	// 0x2BBB50: movss xmm0, dword ptr [0x005A84C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84C4u);
	// 0x2BBB58: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BBB60: movss [0x005A84E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84E8u, ctx.xmm[0].u32[0]);
	// 0x2BBB68: ret
	return;
}

void sub_2BBB70(X86Context& ctx, uint8_t* base) {
	// 0x2BBB70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BBB78: movss [0x005A84FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84FCu, ctx.xmm[0].u32[0]);
	// 0x2BBB80: ret
	return;
}

void sub_2BBB90(X86Context& ctx, uint8_t* base) {
	// 0x2BBB90: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BBB98: movss [0x005A84F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84F0u, ctx.xmm[0].u32[0]);
	// 0x2BBBA0: ret
	return;
}

void sub_2BBBB0(X86Context& ctx, uint8_t* base) {
	// 0x2BBBB0: movss xmm0, dword ptr [0x005A84F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84F0u);
	// 0x2BBBB8: movss [0x005A84F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84F8u, ctx.xmm[0].u32[0]);
	// 0x2BBBC0: ret
	return;
}

void sub_2BBBD0(X86Context& ctx, uint8_t* base) {
	// 0x2BBBD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BBBD8: movss [0x005A84C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84C0u, ctx.xmm[0].u32[0]);
	// 0x2BBBE0: ret
	return;
}

void sub_2BBBF0(X86Context& ctx, uint8_t* base) {
	// 0x2BBBF0: movss xmm0, dword ptr [0x005A84C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84C4u);
	// 0x2BBBF8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BBC00: movss [0x005A84F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84F4u, ctx.xmm[0].u32[0]);
	// 0x2BBC08: ret
	return;
}

void sub_2BBC10(X86Context& ctx, uint8_t* base) {
	// 0x2BBC10: movss xmm0, dword ptr [0x005A84C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84C4u);
	// 0x2BBC18: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BBC20: movss [0x005A84D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84D0u, ctx.xmm[0].u32[0]);
	// 0x2BBC28: ret
	return;
}

void sub_2BBC30(X86Context& ctx, uint8_t* base) {
	// 0x2BBC30: movss xmm0, dword ptr [0x005A84C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A84C4u);
	// 0x2BBC38: subss xmm0, [0x005A84D0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A84D0u);
	// 0x2BBC40: movss [0x005A84CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84CCu, ctx.xmm[0].u32[0]);
	// 0x2BBC48: ret
	return;
}

void sub_2BBC50(X86Context& ctx, uint8_t* base) {
	// 0x2BBC50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BBC58: movss [0x005A84E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84E0u, ctx.xmm[0].u32[0]);
	// 0x2BBC60: ret
	return;
}

void sub_2BBC70(X86Context& ctx, uint8_t* base) {
	// 0x2BBC70: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BBC78: movss [0x005A84C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A84C8u, ctx.xmm[0].u32[0]);
	// 0x2BBC80: ret
	return;
}

void sub_2BBC90(X86Context& ctx, uint8_t* base) {
	// 0x2BBC90: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BBC98: movss [0x005A851C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A851Cu, ctx.xmm[0].u32[0]);
	// 0x2BBCA0: ret
	return;
}

void sub_2BBCB0(X86Context& ctx, uint8_t* base) {
	// 0x2BBCB0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BBCB8: movss [0x005A8528], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8528u, ctx.xmm[0].u32[0]);
	// 0x2BBCC0: ret
	return;
}

void sub_2BBCD0(X86Context& ctx, uint8_t* base) {
	// 0x2BBCD0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BBCD8: movss [0x005A8518], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8518u, ctx.xmm[0].u32[0]);
	// 0x2BBCE0: ret
	return;
}

void sub_2BBCF0(X86Context& ctx, uint8_t* base) {
	// 0x2BBCF0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BBCF8: movss [0x005A8500], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8500u, ctx.xmm[0].u32[0]);
	// 0x2BBD00: ret
	return;
}

void sub_2BBD10(X86Context& ctx, uint8_t* base) {
	// 0x2BBD10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BBD18: movss [0x005A8520], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8520u, ctx.xmm[0].u32[0]);
	// 0x2BBD20: ret
	return;
}

void sub_2BBD30(X86Context& ctx, uint8_t* base) {
	// 0x2BBD30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BBD38: movss [0x005A8508], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8508u, ctx.xmm[0].u32[0]);
	// 0x2BBD40: ret
	return;
}

void sub_2BBD50(X86Context& ctx, uint8_t* base) {
	// 0x2BBD50: movss xmm0, dword ptr [0x005A8520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8520u);
	// 0x2BBD58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BBD60: movss [0x005A8530], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8530u, ctx.xmm[0].u32[0]);
	// 0x2BBD68: ret
	return;
}

void sub_2BBD70(X86Context& ctx, uint8_t* base) {
	// 0x2BBD70: movss xmm0, dword ptr [0x005A8508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8508u);
	// 0x2BBD78: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BBD80: movss [0x005A852C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A852Cu, ctx.xmm[0].u32[0]);
	// 0x2BBD88: ret
	return;
}

void sub_2BBD90(X86Context& ctx, uint8_t* base) {
	// 0x2BBD90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BBD98: movss [0x005A8540], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8540u, ctx.xmm[0].u32[0]);
	// 0x2BBDA0: ret
	return;
}

void sub_2BBDB0(X86Context& ctx, uint8_t* base) {
	// 0x2BBDB0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BBDB8: movss [0x005A8534], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8534u, ctx.xmm[0].u32[0]);
	// 0x2BBDC0: ret
	return;
}

void sub_2BBDD0(X86Context& ctx, uint8_t* base) {
	// 0x2BBDD0: movss xmm0, dword ptr [0x005A8534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8534u);
	// 0x2BBDD8: movss [0x005A853C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A853Cu, ctx.xmm[0].u32[0]);
	// 0x2BBDE0: ret
	return;
}

void sub_2BBDF0(X86Context& ctx, uint8_t* base) {
	// 0x2BBDF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BBDF8: movss [0x005A8504], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8504u, ctx.xmm[0].u32[0]);
	// 0x2BBE00: ret
	return;
}

void sub_2BBE10(X86Context& ctx, uint8_t* base) {
	// 0x2BBE10: movss xmm0, dword ptr [0x005A8508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8508u);
	// 0x2BBE18: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BBE20: movss [0x005A8538], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8538u, ctx.xmm[0].u32[0]);
	// 0x2BBE28: ret
	return;
}

void sub_2BBE30(X86Context& ctx, uint8_t* base) {
	// 0x2BBE30: movss xmm0, dword ptr [0x005A8508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8508u);
	// 0x2BBE38: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BBE40: movss [0x005A8514], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8514u, ctx.xmm[0].u32[0]);
	// 0x2BBE48: ret
	return;
}

void sub_2BBE50(X86Context& ctx, uint8_t* base) {
	// 0x2BBE50: movss xmm0, dword ptr [0x005A8508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8508u);
	// 0x2BBE58: subss xmm0, [0x005A8514]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8514u);
	// 0x2BBE60: movss [0x005A8510], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8510u, ctx.xmm[0].u32[0]);
	// 0x2BBE68: ret
	return;
}

void sub_2BBE70(X86Context& ctx, uint8_t* base) {
	// 0x2BBE70: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BBE78: movss [0x005A8524], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8524u, ctx.xmm[0].u32[0]);
	// 0x2BBE80: ret
	return;
}

void sub_2BBE90(X86Context& ctx, uint8_t* base) {
	// 0x2BBE90: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BBE98: movss [0x005A850C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A850Cu, ctx.xmm[0].u32[0]);
	// 0x2BBEA0: ret
	return;
}

void sub_2BBEB0(X86Context& ctx, uint8_t* base) {
	// 0x2BBEB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BBEB8: movss [0x005A8564], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8564u, ctx.xmm[0].u32[0]);
	// 0x2BBEC0: ret
	return;
}

void sub_2BBED0(X86Context& ctx, uint8_t* base) {
	// 0x2BBED0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BBED8: movss [0x005A8570], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8570u, ctx.xmm[0].u32[0]);
	// 0x2BBEE0: ret
	return;
}

void sub_2BBEF0(X86Context& ctx, uint8_t* base) {
	// 0x2BBEF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BBEF8: movss [0x005A8560], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8560u, ctx.xmm[0].u32[0]);
	// 0x2BBF00: ret
	return;
}

void sub_2BBF10(X86Context& ctx, uint8_t* base) {
	// 0x2BBF10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BBF18: movss [0x005A8544], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8544u, ctx.xmm[0].u32[0]);
	// 0x2BBF20: ret
	return;
}

void sub_2BBF30(X86Context& ctx, uint8_t* base) {
	// 0x2BBF30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BBF38: movss [0x005A8568], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8568u, ctx.xmm[0].u32[0]);
	// 0x2BBF40: ret
	return;
}

void sub_2BBF50(X86Context& ctx, uint8_t* base) {
	// 0x2BBF50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BBF58: movss [0x005A854C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A854Cu, ctx.xmm[0].u32[0]);
	// 0x2BBF60: ret
	return;
}

void sub_2BBF70(X86Context& ctx, uint8_t* base) {
	// 0x2BBF70: movss xmm0, dword ptr [0x005A8568]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8568u);
	// 0x2BBF78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BBF80: movss [0x005A8578], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8578u, ctx.xmm[0].u32[0]);
	// 0x2BBF88: ret
	return;
}

void sub_2BBF90(X86Context& ctx, uint8_t* base) {
	// 0x2BBF90: movss xmm0, dword ptr [0x005A854C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A854Cu);
	// 0x2BBF98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BBFA0: movss [0x005A8574], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8574u, ctx.xmm[0].u32[0]);
	// 0x2BBFA8: ret
	return;
}

void sub_2BBFB0(X86Context& ctx, uint8_t* base) {
	// 0x2BBFB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BBFB8: movss [0x005A8588], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8588u, ctx.xmm[0].u32[0]);
	// 0x2BBFC0: ret
	return;
}

void sub_2BBFD0(X86Context& ctx, uint8_t* base) {
	// 0x2BBFD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BBFD8: movss [0x005A857C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A857Cu, ctx.xmm[0].u32[0]);
	// 0x2BBFE0: ret
	return;
}

void sub_2BBFF0(X86Context& ctx, uint8_t* base) {
	// 0x2BBFF0: movss xmm0, dword ptr [0x005A857C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A857Cu);
	// 0x2BBFF8: movss [0x005A8584], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8584u, ctx.xmm[0].u32[0]);
	// 0x2BC000: ret
	return;
}

void sub_2BC010(X86Context& ctx, uint8_t* base) {
	// 0x2BC010: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC018: movss [0x005A8548], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8548u, ctx.xmm[0].u32[0]);
	// 0x2BC020: ret
	return;
}

void sub_2BC030(X86Context& ctx, uint8_t* base) {
	// 0x2BC030: movss xmm0, dword ptr [0x005A854C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A854Cu);
	// 0x2BC038: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BC040: movss [0x005A8580], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8580u, ctx.xmm[0].u32[0]);
	// 0x2BC048: ret
	return;
}

void sub_2BC050(X86Context& ctx, uint8_t* base) {
	// 0x2BC050: movss xmm0, dword ptr [0x005A854C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A854Cu);
	// 0x2BC058: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BC060: movss [0x005A855C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A855Cu, ctx.xmm[0].u32[0]);
	// 0x2BC068: ret
	return;
}

void sub_2BC070(X86Context& ctx, uint8_t* base) {
	// 0x2BC070: movss xmm0, dword ptr [0x005A854C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A854Cu);
	// 0x2BC078: subss xmm0, [0x005A855C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A855Cu);
	// 0x2BC080: movss [0x005A8554], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8554u, ctx.xmm[0].u32[0]);
	// 0x2BC088: ret
	return;
}

void sub_2BC090(X86Context& ctx, uint8_t* base) {
	// 0x2BC090: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BC098: movss [0x005A856C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A856Cu, ctx.xmm[0].u32[0]);
	// 0x2BC0A0: ret
	return;
}

void sub_2BC0B0(X86Context& ctx, uint8_t* base) {
	// 0x2BC0B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BC0B8: movss [0x005A8550], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8550u, ctx.xmm[0].u32[0]);
	// 0x2BC0C0: ret
	return;
}

void sub_2BC0D0(X86Context& ctx, uint8_t* base) {
	// 0x2BC0D0: movss xmm0, dword ptr [0x003B1698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x2BC0D8: subss xmm0, [0x003EC22C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3EC22Cu);
	// 0x2BC0E0: movss [0x005A8558], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8558u, ctx.xmm[0].u32[0]);
	// 0x2BC0E8: ret
	return;
}

void sub_2BC0F0(X86Context& ctx, uint8_t* base) {
	// 0x2BC0F0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BC0F8: movss xmm1, dword ptr [0x003EC244]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3EC244u);
	// 0x2BC100: xor al, al
	X86_REG8L(ctx.eax) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x2BC102: movss [0x004198BC], xmm1
	X86_MEM_WRITE_u32(base, 0x4198BCu, ctx.xmm[1].u32[0]);
	// 0x2BC10A: movss [0x004198C8], xmm1
	X86_MEM_WRITE_u32(base, 0x4198C8u, ctx.xmm[1].u32[0]);
	// 0x2BC112: movss [0x004198D4], xmm1
	X86_MEM_WRITE_u32(base, 0x4198D4u, ctx.xmm[1].u32[0]);
	// 0x2BC11A: movss [0x004198E0], xmm1
	X86_MEM_WRITE_u32(base, 0x4198E0u, ctx.xmm[1].u32[0]);
	// 0x2BC122: movss [0x004198EC], xmm1
	X86_MEM_WRITE_u32(base, 0x4198ECu, ctx.xmm[1].u32[0]);
	// 0x2BC12A: movss [0x004198F8], xmm1
	X86_MEM_WRITE_u32(base, 0x4198F8u, ctx.xmm[1].u32[0]);
	// 0x2BC132: movss [0x00419904], xmm1
	X86_MEM_WRITE_u32(base, 0x419904u, ctx.xmm[1].u32[0]);
	// 0x2BC13A: movss [0x00419910], xmm1
	X86_MEM_WRITE_u32(base, 0x419910u, ctx.xmm[1].u32[0]);
	// 0x2BC142: movss [0x0041991C], xmm1
	X86_MEM_WRITE_u32(base, 0x41991Cu, ctx.xmm[1].u32[0]);
	// 0x2BC14A: movss [0x00419928], xmm1
	X86_MEM_WRITE_u32(base, 0x419928u, ctx.xmm[1].u32[0]);
	// 0x2BC152: movss [0x00419934], xmm1
	X86_MEM_WRITE_u32(base, 0x419934u, ctx.xmm[1].u32[0]);
	// 0x2BC15A: movss [0x00419940], xmm1
	X86_MEM_WRITE_u32(base, 0x419940u, ctx.xmm[1].u32[0]);
	// 0x2BC162: movss [0x0041994C], xmm1
	X86_MEM_WRITE_u32(base, 0x41994Cu, ctx.xmm[1].u32[0]);
	// 0x2BC16A: movss xmm1, dword ptr [0x003EC248]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3EC248u);
	// 0x2BC172: mov cl, 0x01
	X86_REG8L(ctx.ecx) = (uint8_t)(1);
	// 0x2BC174: movss [0x00419958], xmm1
	X86_MEM_WRITE_u32(base, 0x419958u, ctx.xmm[1].u32[0]);
	// 0x2BC17C: xorps xmm1, xmm1
	memset(&ctx.xmm[1], 0, sizeof(ctx.xmm[1]));
	// 0x2BC17F: mov [0x004198C0], al
	X86_MEM_WRITE_u8(base, 0x4198C0u, X86_REG8L(ctx.eax));
	// 0x2BC184: movss [0x004198C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4198C4u, ctx.xmm[0].u32[0]);
	// 0x2BC18C: mov [0x004198CC], al
	X86_MEM_WRITE_u8(base, 0x4198CCu, X86_REG8L(ctx.eax));
	// 0x2BC191: movss [0x004198D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4198D0u, ctx.xmm[0].u32[0]);
	// 0x2BC199: mov [0x004198D8], al
	X86_MEM_WRITE_u8(base, 0x4198D8u, X86_REG8L(ctx.eax));
	// 0x2BC19E: movss [0x004198DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4198DCu, ctx.xmm[0].u32[0]);
	// 0x2BC1A6: mov [0x004198E4], al
	X86_MEM_WRITE_u8(base, 0x4198E4u, X86_REG8L(ctx.eax));
	// 0x2BC1AB: movss [0x004198E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4198E8u, ctx.xmm[0].u32[0]);
	// 0x2BC1B3: mov [0x004198F0], al
	X86_MEM_WRITE_u8(base, 0x4198F0u, X86_REG8L(ctx.eax));
	// 0x2BC1B8: movss [0x004198F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4198F4u, ctx.xmm[0].u32[0]);
	// 0x2BC1C0: mov [0x004198FC], al
	X86_MEM_WRITE_u8(base, 0x4198FCu, X86_REG8L(ctx.eax));
	// 0x2BC1C5: movss [0x00419900], xmm0
	X86_MEM_WRITE_u32(base, 0x419900u, ctx.xmm[0].u32[0]);
	// 0x2BC1CD: mov [0x00419908], al
	X86_MEM_WRITE_u8(base, 0x419908u, X86_REG8L(ctx.eax));
	// 0x2BC1D2: movss [0x0041990C], xmm0
	X86_MEM_WRITE_u32(base, 0x41990Cu, ctx.xmm[0].u32[0]);
	// 0x2BC1DA: mov [0x00419914], al
	X86_MEM_WRITE_u8(base, 0x419914u, X86_REG8L(ctx.eax));
	// 0x2BC1DF: movss [0x00419918], xmm0
	X86_MEM_WRITE_u32(base, 0x419918u, ctx.xmm[0].u32[0]);
	// 0x2BC1E7: mov [0x00419920], al
	X86_MEM_WRITE_u8(base, 0x419920u, X86_REG8L(ctx.eax));
	// 0x2BC1EC: movss [0x00419924], xmm0
	X86_MEM_WRITE_u32(base, 0x419924u, ctx.xmm[0].u32[0]);
	// 0x2BC1F4: mov [0x0041992C], al
	X86_MEM_WRITE_u8(base, 0x41992Cu, X86_REG8L(ctx.eax));
	// 0x2BC1F9: movss [0x00419930], xmm0
	X86_MEM_WRITE_u32(base, 0x419930u, ctx.xmm[0].u32[0]);
	// 0x2BC201: mov [0x00419938], al
	X86_MEM_WRITE_u8(base, 0x419938u, X86_REG8L(ctx.eax));
	// 0x2BC206: movss [0x0041993C], xmm0
	X86_MEM_WRITE_u32(base, 0x41993Cu, ctx.xmm[0].u32[0]);
	// 0x2BC20E: mov [0x00419944], al
	X86_MEM_WRITE_u8(base, 0x419944u, X86_REG8L(ctx.eax));
	// 0x2BC213: movss [0x00419948], xmm0
	X86_MEM_WRITE_u32(base, 0x419948u, ctx.xmm[0].u32[0]);
	// 0x2BC21B: mov [0x00419950], al
	X86_MEM_WRITE_u8(base, 0x419950u, X86_REG8L(ctx.eax));
	// 0x2BC220: movss [0x00419954], xmm0
	X86_MEM_WRITE_u32(base, 0x419954u, ctx.xmm[0].u32[0]);
	// 0x2BC228: mov [0x0041995C], al
	X86_MEM_WRITE_u8(base, 0x41995Cu, X86_REG8L(ctx.eax));
	// 0x2BC22D: movss [0x00419960], xmm0
	X86_MEM_WRITE_u32(base, 0x419960u, ctx.xmm[0].u32[0]);
	// 0x2BC235: movss [0x00419964], xmm0
	X86_MEM_WRITE_u32(base, 0x419964u, ctx.xmm[0].u32[0]);
	// 0x2BC23D: mov [0x00419968], cl
	X86_MEM_WRITE_u8(base, 0x419968u, X86_REG8L(ctx.ecx));
	// 0x2BC243: movss [0x0041996C], xmm0
	X86_MEM_WRITE_u32(base, 0x41996Cu, ctx.xmm[0].u32[0]);
	// 0x2BC24B: movss [0x00419970], xmm1
	X86_MEM_WRITE_u32(base, 0x419970u, ctx.xmm[1].u32[0]);
	// 0x2BC253: mov [0x00419974], al
	X86_MEM_WRITE_u8(base, 0x419974u, X86_REG8L(ctx.eax));
	// 0x2BC258: movss [0x00419978], xmm0
	X86_MEM_WRITE_u32(base, 0x419978u, ctx.xmm[0].u32[0]);
	// 0x2BC260: movss [0x0041997C], xmm0
	X86_MEM_WRITE_u32(base, 0x41997Cu, ctx.xmm[0].u32[0]);
	// 0x2BC268: mov [0x00419980], cl
	X86_MEM_WRITE_u8(base, 0x419980u, X86_REG8L(ctx.ecx));
	// 0x2BC26E: movss [0x00419984], xmm0
	X86_MEM_WRITE_u32(base, 0x419984u, ctx.xmm[0].u32[0]);
	// 0x2BC276: movss [0x00419988], xmm1
	X86_MEM_WRITE_u32(base, 0x419988u, ctx.xmm[1].u32[0]);
	// 0x2BC27E: mov [0x0041998C], al
	X86_MEM_WRITE_u8(base, 0x41998Cu, X86_REG8L(ctx.eax));
	// 0x2BC283: movss [0x00419990], xmm0
	X86_MEM_WRITE_u32(base, 0x419990u, ctx.xmm[0].u32[0]);
	// 0x2BC28B: movss [0x00419994], xmm1
	X86_MEM_WRITE_u32(base, 0x419994u, ctx.xmm[1].u32[0]);
	// 0x2BC293: mov [0x00419998], al
	X86_MEM_WRITE_u8(base, 0x419998u, X86_REG8L(ctx.eax));
	// 0x2BC298: movss [0x0041999C], xmm0
	X86_MEM_WRITE_u32(base, 0x41999Cu, ctx.xmm[0].u32[0]);
	// 0x2BC2A0: movss [0x004199A0], xmm1
	X86_MEM_WRITE_u32(base, 0x4199A0u, ctx.xmm[1].u32[0]);
	// 0x2BC2A8: mov [0x004199A4], al
	X86_MEM_WRITE_u8(base, 0x4199A4u, X86_REG8L(ctx.eax));
	// 0x2BC2AD: movss [0x004199A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4199A8u, ctx.xmm[0].u32[0]);
	// 0x2BC2B5: movss [0x004199AC], xmm1
	X86_MEM_WRITE_u32(base, 0x4199ACu, ctx.xmm[1].u32[0]);
	// 0x2BC2BD: mov [0x004199B0], al
	X86_MEM_WRITE_u8(base, 0x4199B0u, X86_REG8L(ctx.eax));
	// 0x2BC2C2: movss [0x004199B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4199B4u, ctx.xmm[0].u32[0]);
	// 0x2BC2CA: movss [0x004199B8], xmm1
	X86_MEM_WRITE_u32(base, 0x4199B8u, ctx.xmm[1].u32[0]);
	// 0x2BC2D2: mov [0x004199BC], al
	X86_MEM_WRITE_u8(base, 0x4199BCu, X86_REG8L(ctx.eax));
	// 0x2BC2D7: movss [0x004199C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4199C0u, ctx.xmm[0].u32[0]);
	// 0x2BC2DF: movss [0x004199C4], xmm1
	X86_MEM_WRITE_u32(base, 0x4199C4u, ctx.xmm[1].u32[0]);
	// 0x2BC2E7: mov [0x004199C8], al
	X86_MEM_WRITE_u8(base, 0x4199C8u, X86_REG8L(ctx.eax));
	// 0x2BC2EC: movss [0x004199CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4199CCu, ctx.xmm[0].u32[0]);
	// 0x2BC2F4: movss [0x004199D0], xmm1
	X86_MEM_WRITE_u32(base, 0x4199D0u, ctx.xmm[1].u32[0]);
	// 0x2BC2FC: mov [0x004199D4], al
	X86_MEM_WRITE_u8(base, 0x4199D4u, X86_REG8L(ctx.eax));
	// 0x2BC301: movss [0x004199D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4199D8u, ctx.xmm[0].u32[0]);
	// 0x2BC309: movss [0x004199DC], xmm1
	X86_MEM_WRITE_u32(base, 0x4199DCu, ctx.xmm[1].u32[0]);
	// 0x2BC311: mov [0x004199E0], al
	X86_MEM_WRITE_u8(base, 0x4199E0u, X86_REG8L(ctx.eax));
	// 0x2BC316: movss [0x004199E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4199E4u, ctx.xmm[0].u32[0]);
	// 0x2BC31E: movss [0x004199E8], xmm1
	X86_MEM_WRITE_u32(base, 0x4199E8u, ctx.xmm[1].u32[0]);
	// 0x2BC326: mov [0x004199EC], al
	X86_MEM_WRITE_u8(base, 0x4199ECu, X86_REG8L(ctx.eax));
	// 0x2BC32B: movss [0x004199F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4199F0u, ctx.xmm[0].u32[0]);
	// 0x2BC333: movss [0x004199F4], xmm1
	X86_MEM_WRITE_u32(base, 0x4199F4u, ctx.xmm[1].u32[0]);
	// 0x2BC33B: mov [0x004199F8], al
	X86_MEM_WRITE_u8(base, 0x4199F8u, X86_REG8L(ctx.eax));
	// 0x2BC340: movss [0x004199FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4199FCu, ctx.xmm[0].u32[0]);
	// 0x2BC348: movss [0x00419A00], xmm1
	X86_MEM_WRITE_u32(base, 0x419A00u, ctx.xmm[1].u32[0]);
	// 0x2BC350: mov [0x00419A04], al
	X86_MEM_WRITE_u8(base, 0x419A04u, X86_REG8L(ctx.eax));
	// 0x2BC355: movss [0x00419A08], xmm0
	X86_MEM_WRITE_u32(base, 0x419A08u, ctx.xmm[0].u32[0]);
	// 0x2BC35D: movss [0x00419A0C], xmm1
	X86_MEM_WRITE_u32(base, 0x419A0Cu, ctx.xmm[1].u32[0]);
	// 0x2BC365: mov [0x00419A10], al
	X86_MEM_WRITE_u8(base, 0x419A10u, X86_REG8L(ctx.eax));
	// 0x2BC36A: movss [0x00419A14], xmm0
	X86_MEM_WRITE_u32(base, 0x419A14u, ctx.xmm[0].u32[0]);
	// 0x2BC372: movss [0x00419A18], xmm1
	X86_MEM_WRITE_u32(base, 0x419A18u, ctx.xmm[1].u32[0]);
	// 0x2BC37A: mov [0x00419A1C], al
	X86_MEM_WRITE_u8(base, 0x419A1Cu, X86_REG8L(ctx.eax));
	// 0x2BC37F: ret
	return;
}

void sub_2BC380(X86Context& ctx, uint8_t* base) {
	// 0x2BC380: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BC388: movss [0x005A85A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85A8u, ctx.xmm[0].u32[0]);
	// 0x2BC390: ret
	return;
}

void sub_2BC3A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC3A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BC3A8: movss [0x005A85B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85B4u, ctx.xmm[0].u32[0]);
	// 0x2BC3B0: ret
	return;
}

void sub_2BC3C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC3C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BC3C8: movss [0x005A85A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85A4u, ctx.xmm[0].u32[0]);
	// 0x2BC3D0: ret
	return;
}

void sub_2BC3E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC3E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BC3E8: movss [0x005A858C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A858Cu, ctx.xmm[0].u32[0]);
	// 0x2BC3F0: ret
	return;
}

void sub_2BC400(X86Context& ctx, uint8_t* base) {
	// 0x2BC400: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BC408: movss [0x005A85AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85ACu, ctx.xmm[0].u32[0]);
	// 0x2BC410: ret
	return;
}

void sub_2BC420(X86Context& ctx, uint8_t* base) {
	// 0x2BC420: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BC428: movss [0x005A8594], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8594u, ctx.xmm[0].u32[0]);
	// 0x2BC430: ret
	return;
}

void sub_2BC440(X86Context& ctx, uint8_t* base) {
	// 0x2BC440: movss xmm0, dword ptr [0x005A85AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85ACu);
	// 0x2BC448: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BC450: movss [0x005A85BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85BCu, ctx.xmm[0].u32[0]);
	// 0x2BC458: ret
	return;
}

void sub_2BC460(X86Context& ctx, uint8_t* base) {
	// 0x2BC460: movss xmm0, dword ptr [0x005A8594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8594u);
	// 0x2BC468: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BC470: movss [0x005A85B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85B8u, ctx.xmm[0].u32[0]);
	// 0x2BC478: ret
	return;
}

void sub_2BC480(X86Context& ctx, uint8_t* base) {
	// 0x2BC480: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC488: movss [0x005A85CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85CCu, ctx.xmm[0].u32[0]);
	// 0x2BC490: ret
	return;
}

void sub_2BC4A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC4A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BC4A8: movss [0x005A85C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85C0u, ctx.xmm[0].u32[0]);
	// 0x2BC4B0: ret
	return;
}

void sub_2BC4C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC4C0: movss xmm0, dword ptr [0x005A85C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85C0u);
	// 0x2BC4C8: movss [0x005A85C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85C8u, ctx.xmm[0].u32[0]);
	// 0x2BC4D0: ret
	return;
}

void sub_2BC4E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC4E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC4E8: movss [0x005A8590], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8590u, ctx.xmm[0].u32[0]);
	// 0x2BC4F0: ret
	return;
}

void sub_2BC500(X86Context& ctx, uint8_t* base) {
	// 0x2BC500: movss xmm0, dword ptr [0x005A8594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8594u);
	// 0x2BC508: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BC510: movss [0x005A85C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85C4u, ctx.xmm[0].u32[0]);
	// 0x2BC518: ret
	return;
}

void sub_2BC520(X86Context& ctx, uint8_t* base) {
	// 0x2BC520: movss xmm0, dword ptr [0x005A8594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8594u);
	// 0x2BC528: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BC530: movss [0x005A85A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85A0u, ctx.xmm[0].u32[0]);
	// 0x2BC538: ret
	return;
}

void sub_2BC540(X86Context& ctx, uint8_t* base) {
	// 0x2BC540: movss xmm0, dword ptr [0x005A8594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8594u);
	// 0x2BC548: subss xmm0, [0x005A85A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A85A0u);
	// 0x2BC550: movss [0x005A859C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A859Cu, ctx.xmm[0].u32[0]);
	// 0x2BC558: ret
	return;
}

void sub_2BC560(X86Context& ctx, uint8_t* base) {
	// 0x2BC560: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BC568: movss [0x005A85B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85B0u, ctx.xmm[0].u32[0]);
	// 0x2BC570: ret
	return;
}

void sub_2BC580(X86Context& ctx, uint8_t* base) {
	// 0x2BC580: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BC588: movss [0x005A8598], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8598u, ctx.xmm[0].u32[0]);
	// 0x2BC590: ret
	return;
}

void sub_2BC5A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC5A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BC5A8: movss [0x005A85EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85ECu, ctx.xmm[0].u32[0]);
	// 0x2BC5B0: ret
	return;
}

void sub_2BC5C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC5C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BC5C8: movss [0x005A85F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85F8u, ctx.xmm[0].u32[0]);
	// 0x2BC5D0: ret
	return;
}

void sub_2BC5E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC5E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BC5E8: movss [0x005A85E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85E8u, ctx.xmm[0].u32[0]);
	// 0x2BC5F0: ret
	return;
}

void sub_2BC600(X86Context& ctx, uint8_t* base) {
	// 0x2BC600: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BC608: movss [0x005A85D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85D0u, ctx.xmm[0].u32[0]);
	// 0x2BC610: ret
	return;
}

void sub_2BC620(X86Context& ctx, uint8_t* base) {
	// 0x2BC620: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BC628: movss [0x005A85F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85F0u, ctx.xmm[0].u32[0]);
	// 0x2BC630: ret
	return;
}

void sub_2BC640(X86Context& ctx, uint8_t* base) {
	// 0x2BC640: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BC648: movss [0x005A85D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85D8u, ctx.xmm[0].u32[0]);
	// 0x2BC650: ret
	return;
}

void sub_2BC660(X86Context& ctx, uint8_t* base) {
	// 0x2BC660: movss xmm0, dword ptr [0x005A85F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85F0u);
	// 0x2BC668: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BC670: movss [0x005A8600], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8600u, ctx.xmm[0].u32[0]);
	// 0x2BC678: ret
	return;
}

void sub_2BC680(X86Context& ctx, uint8_t* base) {
	// 0x2BC680: movss xmm0, dword ptr [0x005A85D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85D8u);
	// 0x2BC688: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BC690: movss [0x005A85FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85FCu, ctx.xmm[0].u32[0]);
	// 0x2BC698: ret
	return;
}

void sub_2BC6A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC6A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC6A8: movss [0x005A8610], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8610u, ctx.xmm[0].u32[0]);
	// 0x2BC6B0: ret
	return;
}

void sub_2BC6C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC6C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BC6C8: movss [0x005A8604], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8604u, ctx.xmm[0].u32[0]);
	// 0x2BC6D0: ret
	return;
}

void sub_2BC6E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC6E0: movss xmm0, dword ptr [0x005A8604]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8604u);
	// 0x2BC6E8: movss [0x005A860C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A860Cu, ctx.xmm[0].u32[0]);
	// 0x2BC6F0: ret
	return;
}

void sub_2BC700(X86Context& ctx, uint8_t* base) {
	// 0x2BC700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC708: movss [0x005A85D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85D4u, ctx.xmm[0].u32[0]);
	// 0x2BC710: ret
	return;
}

void sub_2BC720(X86Context& ctx, uint8_t* base) {
	// 0x2BC720: movss xmm0, dword ptr [0x005A85D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85D8u);
	// 0x2BC728: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BC730: movss [0x005A8608], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8608u, ctx.xmm[0].u32[0]);
	// 0x2BC738: ret
	return;
}

void sub_2BC740(X86Context& ctx, uint8_t* base) {
	// 0x2BC740: movss xmm0, dword ptr [0x005A85D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85D8u);
	// 0x2BC748: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BC750: movss [0x005A85E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85E4u, ctx.xmm[0].u32[0]);
	// 0x2BC758: ret
	return;
}

void sub_2BC760(X86Context& ctx, uint8_t* base) {
	// 0x2BC760: movss xmm0, dword ptr [0x005A85D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A85D8u);
	// 0x2BC768: subss xmm0, [0x005A85E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A85E4u);
	// 0x2BC770: movss [0x005A85E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85E0u, ctx.xmm[0].u32[0]);
	// 0x2BC778: ret
	return;
}

void sub_2BC780(X86Context& ctx, uint8_t* base) {
	// 0x2BC780: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BC788: movss [0x005A85F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85F4u, ctx.xmm[0].u32[0]);
	// 0x2BC790: ret
	return;
}

void sub_2BC7A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC7A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BC7A8: movss [0x005A85DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A85DCu, ctx.xmm[0].u32[0]);
	// 0x2BC7B0: ret
	return;
}

void sub_2BC7C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC7C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BC7C8: movss [0x005A8618], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8618u, ctx.xmm[0].u32[0]);
	// 0x2BC7D0: ret
	return;
}

void sub_2BC7E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC7E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BC7E8: movss [0x005A861C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A861Cu, ctx.xmm[0].u32[0]);
	// 0x2BC7F0: ret
	return;
}

void sub_2BC800(X86Context& ctx, uint8_t* base) {
	// 0x2BC800: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BC808: movss [0x005A8614], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8614u, ctx.xmm[0].u32[0]);
	// 0x2BC810: ret
	return;
}

void sub_2BC820(X86Context& ctx, uint8_t* base) {
	// 0x2BC820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BC828: movss [0x005A8640], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8640u, ctx.xmm[0].u32[0]);
	// 0x2BC830: ret
	return;
}

void sub_2BC840(X86Context& ctx, uint8_t* base) {
	// 0x2BC840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BC848: movss [0x005A864C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A864Cu, ctx.xmm[0].u32[0]);
	// 0x2BC850: ret
	return;
}

void sub_2BC860(X86Context& ctx, uint8_t* base) {
	// 0x2BC860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BC868: movss [0x005A8638], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8638u, ctx.xmm[0].u32[0]);
	// 0x2BC870: ret
	return;
}

void sub_2BC880(X86Context& ctx, uint8_t* base) {
	// 0x2BC880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BC888: movss [0x005A8620], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8620u, ctx.xmm[0].u32[0]);
	// 0x2BC890: ret
	return;
}

void sub_2BC8A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC8A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BC8A8: movss [0x005A8644], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8644u, ctx.xmm[0].u32[0]);
	// 0x2BC8B0: ret
	return;
}

void sub_2BC8C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC8C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BC8C8: movss [0x005A8624], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8624u, ctx.xmm[0].u32[0]);
	// 0x2BC8D0: ret
	return;
}

void sub_2BC8E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC8E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BC8E8: movss [0x005A8654], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8654u, ctx.xmm[0].u32[0]);
	// 0x2BC8F0: ret
	return;
}

void sub_2BC900(X86Context& ctx, uint8_t* base) {
	// 0x2BC900: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BC908: movss [0x005A863C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A863Cu, ctx.xmm[0].u32[0]);
	// 0x2BC910: ret
	return;
}

void sub_2BC920(X86Context& ctx, uint8_t* base) {
	// 0x2BC920: movss xmm0, dword ptr [0x005A8654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8654u);
	// 0x2BC928: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BC930: movss [0x005A862C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A862Cu, ctx.xmm[0].u32[0]);
	// 0x2BC938: ret
	return;
}

void sub_2BC940(X86Context& ctx, uint8_t* base) {
	// 0x2BC940: movss xmm0, dword ptr [0x005A863C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A863Cu);
	// 0x2BC948: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BC950: movss [0x005A8650], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8650u, ctx.xmm[0].u32[0]);
	// 0x2BC958: ret
	return;
}

void sub_2BC960(X86Context& ctx, uint8_t* base) {
	// 0x2BC960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC968: movss [0x005A8660], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8660u, ctx.xmm[0].u32[0]);
	// 0x2BC970: ret
	return;
}

void sub_2BC980(X86Context& ctx, uint8_t* base) {
	// 0x2BC980: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BC988: movss [0x005A8658], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8658u, ctx.xmm[0].u32[0]);
	// 0x2BC990: ret
	return;
}

void sub_2BC9A0(X86Context& ctx, uint8_t* base) {
	// 0x2BC9A0: movss xmm0, dword ptr [0x005A8658]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8658u);
	// 0x2BC9A8: movss [0x005A865C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A865Cu, ctx.xmm[0].u32[0]);
	// 0x2BC9B0: ret
	return;
}

void sub_2BC9C0(X86Context& ctx, uint8_t* base) {
	// 0x2BC9C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BC9C8: movss [0x005A8634], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8634u, ctx.xmm[0].u32[0]);
	// 0x2BC9D0: ret
	return;
}

void sub_2BC9E0(X86Context& ctx, uint8_t* base) {
	// 0x2BC9E0: movss xmm0, dword ptr [0x005A863C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A863Cu);
	// 0x2BC9E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BC9F0: movss [0x005A8630], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8630u, ctx.xmm[0].u32[0]);
	// 0x2BC9F8: ret
	return;
}

void sub_2BCA00(X86Context& ctx, uint8_t* base) {
	// 0x2BCA00: movss xmm0, dword ptr [0x005A863C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A863Cu);
	// 0x2BCA08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BCA10: movss [0x005A8648], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8648u, ctx.xmm[0].u32[0]);
	// 0x2BCA18: ret
	return;
}

void sub_2BCA20(X86Context& ctx, uint8_t* base) {
	// 0x2BCA20: movss xmm0, dword ptr [0x005A863C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A863Cu);
	// 0x2BCA28: subss xmm0, [0x005A8648]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8648u);
	// 0x2BCA30: movss [0x005A8628], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8628u, ctx.xmm[0].u32[0]);
	// 0x2BCA38: ret
	return;
}

void sub_2BCA40(X86Context& ctx, uint8_t* base) {
	// 0x2BCA40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BCA48: movss [0x005A8670], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8670u, ctx.xmm[0].u32[0]);
	// 0x2BCA50: ret
	return;
}

void sub_2BCA60(X86Context& ctx, uint8_t* base) {
	// 0x2BCA60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BCA68: movss [0x005A8678], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8678u, ctx.xmm[0].u32[0]);
	// 0x2BCA70: ret
	return;
}

void sub_2BCA80(X86Context& ctx, uint8_t* base) {
	// 0x2BCA80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BCA88: movss [0x005A866C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A866Cu, ctx.xmm[0].u32[0]);
	// 0x2BCA90: ret
	return;
}

void sub_2BCAA0(X86Context& ctx, uint8_t* base) {
	// 0x2BCAA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BCAA8: movss [0x005A8664], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8664u, ctx.xmm[0].u32[0]);
	// 0x2BCAB0: ret
	return;
}

void sub_2BCAC0(X86Context& ctx, uint8_t* base) {
	// 0x2BCAC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BCAC8: movss [0x005A8674], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8674u, ctx.xmm[0].u32[0]);
	// 0x2BCAD0: ret
	return;
}

void sub_2BCAE0(X86Context& ctx, uint8_t* base) {
	// 0x2BCAE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BCAE8: movss [0x005A8668], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8668u, ctx.xmm[0].u32[0]);
	// 0x2BCAF0: ret
	return;
}

void sub_2BCB00(X86Context& ctx, uint8_t* base) {
	// 0x2BCB00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BCB08: movss [0x005A869C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A869Cu, ctx.xmm[0].u32[0]);
	// 0x2BCB10: ret
	return;
}

void sub_2BCB20(X86Context& ctx, uint8_t* base) {
	// 0x2BCB20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BCB28: movss [0x005A86A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86A8u, ctx.xmm[0].u32[0]);
	// 0x2BCB30: ret
	return;
}

void sub_2BCB40(X86Context& ctx, uint8_t* base) {
	// 0x2BCB40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BCB48: movss [0x005A8694], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8694u, ctx.xmm[0].u32[0]);
	// 0x2BCB50: ret
	return;
}

void sub_2BCB60(X86Context& ctx, uint8_t* base) {
	// 0x2BCB60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BCB68: movss [0x005A867C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A867Cu, ctx.xmm[0].u32[0]);
	// 0x2BCB70: ret
	return;
}

void sub_2BCB80(X86Context& ctx, uint8_t* base) {
	// 0x2BCB80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BCB88: movss [0x005A86A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86A0u, ctx.xmm[0].u32[0]);
	// 0x2BCB90: ret
	return;
}

void sub_2BCBA0(X86Context& ctx, uint8_t* base) {
	// 0x2BCBA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BCBA8: movss [0x005A8680], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8680u, ctx.xmm[0].u32[0]);
	// 0x2BCBB0: ret
	return;
}

void sub_2BCBC0(X86Context& ctx, uint8_t* base) {
	// 0x2BCBC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BCBC8: movss [0x005A86B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86B0u, ctx.xmm[0].u32[0]);
	// 0x2BCBD0: ret
	return;
}

void sub_2BCBE0(X86Context& ctx, uint8_t* base) {
	// 0x2BCBE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BCBE8: movss [0x005A8698], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8698u, ctx.xmm[0].u32[0]);
	// 0x2BCBF0: ret
	return;
}

void sub_2BCC00(X86Context& ctx, uint8_t* base) {
	// 0x2BCC00: movss xmm0, dword ptr [0x005A86B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86B0u);
	// 0x2BCC08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BCC10: movss [0x005A8688], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8688u, ctx.xmm[0].u32[0]);
	// 0x2BCC18: ret
	return;
}

void sub_2BCC20(X86Context& ctx, uint8_t* base) {
	// 0x2BCC20: movss xmm0, dword ptr [0x005A8698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8698u);
	// 0x2BCC28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BCC30: movss [0x005A86AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86ACu, ctx.xmm[0].u32[0]);
	// 0x2BCC38: ret
	return;
}

void sub_2BCC40(X86Context& ctx, uint8_t* base) {
	// 0x2BCC40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BCC48: movss [0x005A86BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86BCu, ctx.xmm[0].u32[0]);
	// 0x2BCC50: ret
	return;
}

void sub_2BCC60(X86Context& ctx, uint8_t* base) {
	// 0x2BCC60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BCC68: movss [0x005A86B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86B4u, ctx.xmm[0].u32[0]);
	// 0x2BCC70: ret
	return;
}

void sub_2BCC80(X86Context& ctx, uint8_t* base) {
	// 0x2BCC80: movss xmm0, dword ptr [0x005A86B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86B4u);
	// 0x2BCC88: movss [0x005A86B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86B8u, ctx.xmm[0].u32[0]);
	// 0x2BCC90: ret
	return;
}

void sub_2BCCA0(X86Context& ctx, uint8_t* base) {
	// 0x2BCCA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BCCA8: movss [0x005A8690], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8690u, ctx.xmm[0].u32[0]);
	// 0x2BCCB0: ret
	return;
}

void sub_2BCCC0(X86Context& ctx, uint8_t* base) {
	// 0x2BCCC0: movss xmm0, dword ptr [0x005A8698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8698u);
	// 0x2BCCC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BCCD0: movss [0x005A868C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A868Cu, ctx.xmm[0].u32[0]);
	// 0x2BCCD8: ret
	return;
}

void sub_2BCCE0(X86Context& ctx, uint8_t* base) {
	// 0x2BCCE0: movss xmm0, dword ptr [0x005A8698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8698u);
	// 0x2BCCE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BCCF0: movss [0x005A86A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86A4u, ctx.xmm[0].u32[0]);
	// 0x2BCCF8: ret
	return;
}

void sub_2BCD00(X86Context& ctx, uint8_t* base) {
	// 0x2BCD00: movss xmm0, dword ptr [0x005A8698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8698u);
	// 0x2BCD08: subss xmm0, [0x005A86A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A86A4u);
	// 0x2BCD10: movss [0x005A8684], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8684u, ctx.xmm[0].u32[0]);
	// 0x2BCD18: ret
	return;
}

void sub_2BCD20(X86Context& ctx, uint8_t* base) {
	// 0x2BCD20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BCD28: movss [0x005A86DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86DCu, ctx.xmm[0].u32[0]);
	// 0x2BCD30: ret
	return;
}

void sub_2BCD40(X86Context& ctx, uint8_t* base) {
	// 0x2BCD40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BCD48: movss [0x005A86E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86E8u, ctx.xmm[0].u32[0]);
	// 0x2BCD50: ret
	return;
}

void sub_2BCD60(X86Context& ctx, uint8_t* base) {
	// 0x2BCD60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BCD68: movss [0x005A86D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86D8u, ctx.xmm[0].u32[0]);
	// 0x2BCD70: ret
	return;
}

void sub_2BCD80(X86Context& ctx, uint8_t* base) {
	// 0x2BCD80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BCD88: movss [0x005A86C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86C0u, ctx.xmm[0].u32[0]);
	// 0x2BCD90: ret
	return;
}

void sub_2BCDA0(X86Context& ctx, uint8_t* base) {
	// 0x2BCDA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BCDA8: movss [0x005A86E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86E0u, ctx.xmm[0].u32[0]);
	// 0x2BCDB0: ret
	return;
}

void sub_2BCDC0(X86Context& ctx, uint8_t* base) {
	// 0x2BCDC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BCDC8: movss [0x005A86C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86C8u, ctx.xmm[0].u32[0]);
	// 0x2BCDD0: ret
	return;
}

void sub_2BCDE0(X86Context& ctx, uint8_t* base) {
	// 0x2BCDE0: movss xmm0, dword ptr [0x005A86E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86E0u);
	// 0x2BCDE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BCDF0: movss [0x005A86F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86F0u, ctx.xmm[0].u32[0]);
	// 0x2BCDF8: ret
	return;
}

void sub_2BCE00(X86Context& ctx, uint8_t* base) {
	// 0x2BCE00: movss xmm0, dword ptr [0x005A86C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86C8u);
	// 0x2BCE08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BCE10: movss [0x005A86EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86ECu, ctx.xmm[0].u32[0]);
	// 0x2BCE18: ret
	return;
}

void sub_2BCE20(X86Context& ctx, uint8_t* base) {
	// 0x2BCE20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BCE28: movss [0x005A8700], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8700u, ctx.xmm[0].u32[0]);
	// 0x2BCE30: ret
	return;
}

void sub_2BCE40(X86Context& ctx, uint8_t* base) {
	// 0x2BCE40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BCE48: movss [0x005A86F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86F4u, ctx.xmm[0].u32[0]);
	// 0x2BCE50: ret
	return;
}

void sub_2BCE60(X86Context& ctx, uint8_t* base) {
	// 0x2BCE60: movss xmm0, dword ptr [0x005A86F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86F4u);
	// 0x2BCE68: movss [0x005A86FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86FCu, ctx.xmm[0].u32[0]);
	// 0x2BCE70: ret
	return;
}

void sub_2BCE80(X86Context& ctx, uint8_t* base) {
	// 0x2BCE80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BCE88: movss [0x005A86C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86C4u, ctx.xmm[0].u32[0]);
	// 0x2BCE90: ret
	return;
}

void sub_2BCEA0(X86Context& ctx, uint8_t* base) {
	// 0x2BCEA0: movss xmm0, dword ptr [0x005A86C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86C8u);
	// 0x2BCEA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BCEB0: movss [0x005A86F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86F8u, ctx.xmm[0].u32[0]);
	// 0x2BCEB8: ret
	return;
}

void sub_2BCEC0(X86Context& ctx, uint8_t* base) {
	// 0x2BCEC0: movss xmm0, dword ptr [0x005A86C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86C8u);
	// 0x2BCEC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BCED0: movss [0x005A86D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86D4u, ctx.xmm[0].u32[0]);
	// 0x2BCED8: ret
	return;
}

void sub_2BCEE0(X86Context& ctx, uint8_t* base) {
	// 0x2BCEE0: movss xmm0, dword ptr [0x005A86C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A86C8u);
	// 0x2BCEE8: subss xmm0, [0x005A86D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A86D4u);
	// 0x2BCEF0: movss [0x005A86D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86D0u, ctx.xmm[0].u32[0]);
	// 0x2BCEF8: ret
	return;
}

void sub_2BCF00(X86Context& ctx, uint8_t* base) {
	// 0x2BCF00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BCF08: movss [0x005A86E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86E4u, ctx.xmm[0].u32[0]);
	// 0x2BCF10: ret
	return;
}

void sub_2BCF20(X86Context& ctx, uint8_t* base) {
	// 0x2BCF20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BCF28: movss [0x005A86CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A86CCu, ctx.xmm[0].u32[0]);
	// 0x2BCF30: ret
	return;
}

void sub_2BCF40(X86Context& ctx, uint8_t* base) {
	// 0x2BCF40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BCF48: movss [0x005A8720], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8720u, ctx.xmm[0].u32[0]);
	// 0x2BCF50: ret
	return;
}

void sub_2BCF60(X86Context& ctx, uint8_t* base) {
	// 0x2BCF60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BCF68: movss [0x005A872C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A872Cu, ctx.xmm[0].u32[0]);
	// 0x2BCF70: ret
	return;
}

void sub_2BCF80(X86Context& ctx, uint8_t* base) {
	// 0x2BCF80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BCF88: movss [0x005A871C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A871Cu, ctx.xmm[0].u32[0]);
	// 0x2BCF90: ret
	return;
}

void sub_2BCFA0(X86Context& ctx, uint8_t* base) {
	// 0x2BCFA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BCFA8: movss [0x005A8704], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8704u, ctx.xmm[0].u32[0]);
	// 0x2BCFB0: ret
	return;
}

void sub_2BCFC0(X86Context& ctx, uint8_t* base) {
	// 0x2BCFC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BCFC8: movss [0x005A8724], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8724u, ctx.xmm[0].u32[0]);
	// 0x2BCFD0: ret
	return;
}

void sub_2BCFE0(X86Context& ctx, uint8_t* base) {
	// 0x2BCFE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BCFE8: movss [0x005A870C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A870Cu, ctx.xmm[0].u32[0]);
	// 0x2BCFF0: ret
	return;
}

void sub_2BD000(X86Context& ctx, uint8_t* base) {
	// 0x2BD000: movss xmm0, dword ptr [0x005A8724]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8724u);
	// 0x2BD008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BD010: movss [0x005A8734], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8734u, ctx.xmm[0].u32[0]);
	// 0x2BD018: ret
	return;
}

void sub_2BD020(X86Context& ctx, uint8_t* base) {
	// 0x2BD020: movss xmm0, dword ptr [0x005A870C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A870Cu);
	// 0x2BD028: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BD030: movss [0x005A8730], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8730u, ctx.xmm[0].u32[0]);
	// 0x2BD038: ret
	return;
}

void sub_2BD040(X86Context& ctx, uint8_t* base) {
	// 0x2BD040: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD048: movss [0x005A8744], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8744u, ctx.xmm[0].u32[0]);
	// 0x2BD050: ret
	return;
}

void sub_2BD060(X86Context& ctx, uint8_t* base) {
	// 0x2BD060: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BD068: movss [0x005A8738], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8738u, ctx.xmm[0].u32[0]);
	// 0x2BD070: ret
	return;
}

void sub_2BD080(X86Context& ctx, uint8_t* base) {
	// 0x2BD080: movss xmm0, dword ptr [0x005A8738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8738u);
	// 0x2BD088: movss [0x005A8740], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8740u, ctx.xmm[0].u32[0]);
	// 0x2BD090: ret
	return;
}

void sub_2BD0A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD0A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD0A8: movss [0x005A8708], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8708u, ctx.xmm[0].u32[0]);
	// 0x2BD0B0: ret
	return;
}

void sub_2BD0C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD0C0: movss xmm0, dword ptr [0x005A870C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A870Cu);
	// 0x2BD0C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BD0D0: movss [0x005A873C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A873Cu, ctx.xmm[0].u32[0]);
	// 0x2BD0D8: ret
	return;
}

void sub_2BD0E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD0E0: movss xmm0, dword ptr [0x005A870C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A870Cu);
	// 0x2BD0E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BD0F0: movss [0x005A8718], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8718u, ctx.xmm[0].u32[0]);
	// 0x2BD0F8: ret
	return;
}

void sub_2BD100(X86Context& ctx, uint8_t* base) {
	// 0x2BD100: movss xmm0, dword ptr [0x005A870C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A870Cu);
	// 0x2BD108: subss xmm0, [0x005A8718]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8718u);
	// 0x2BD110: movss [0x005A8714], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8714u, ctx.xmm[0].u32[0]);
	// 0x2BD118: ret
	return;
}

void sub_2BD120(X86Context& ctx, uint8_t* base) {
	// 0x2BD120: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BD128: movss [0x005A8728], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8728u, ctx.xmm[0].u32[0]);
	// 0x2BD130: ret
	return;
}

void sub_2BD140(X86Context& ctx, uint8_t* base) {
	// 0x2BD140: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BD148: movss [0x005A8710], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8710u, ctx.xmm[0].u32[0]);
	// 0x2BD150: ret
	return;
}

void sub_2BD160(X86Context& ctx, uint8_t* base) {
	// 0x2BD160: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BD168: movss [0x005A8764], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8764u, ctx.xmm[0].u32[0]);
	// 0x2BD170: ret
	return;
}

void sub_2BD180(X86Context& ctx, uint8_t* base) {
	// 0x2BD180: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BD188: movss [0x005A8770], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8770u, ctx.xmm[0].u32[0]);
	// 0x2BD190: ret
	return;
}

void sub_2BD1A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD1A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BD1A8: movss [0x005A8760], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8760u, ctx.xmm[0].u32[0]);
	// 0x2BD1B0: ret
	return;
}

void sub_2BD1C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD1C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BD1C8: movss [0x005A8748], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8748u, ctx.xmm[0].u32[0]);
	// 0x2BD1D0: ret
	return;
}

void sub_2BD1E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD1E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BD1E8: movss [0x005A8768], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8768u, ctx.xmm[0].u32[0]);
	// 0x2BD1F0: ret
	return;
}

void sub_2BD200(X86Context& ctx, uint8_t* base) {
	// 0x2BD200: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BD208: movss [0x005A8750], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8750u, ctx.xmm[0].u32[0]);
	// 0x2BD210: ret
	return;
}

void sub_2BD220(X86Context& ctx, uint8_t* base) {
	// 0x2BD220: movss xmm0, dword ptr [0x005A8768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8768u);
	// 0x2BD228: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BD230: movss [0x005A8778], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8778u, ctx.xmm[0].u32[0]);
	// 0x2BD238: ret
	return;
}

void sub_2BD240(X86Context& ctx, uint8_t* base) {
	// 0x2BD240: movss xmm0, dword ptr [0x005A8750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8750u);
	// 0x2BD248: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BD250: movss [0x005A8774], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8774u, ctx.xmm[0].u32[0]);
	// 0x2BD258: ret
	return;
}

void sub_2BD260(X86Context& ctx, uint8_t* base) {
	// 0x2BD260: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD268: movss [0x005A8788], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8788u, ctx.xmm[0].u32[0]);
	// 0x2BD270: ret
	return;
}

void sub_2BD280(X86Context& ctx, uint8_t* base) {
	// 0x2BD280: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BD288: movss [0x005A877C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A877Cu, ctx.xmm[0].u32[0]);
	// 0x2BD290: ret
	return;
}

void sub_2BD2A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD2A0: movss xmm0, dword ptr [0x005A877C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A877Cu);
	// 0x2BD2A8: movss [0x005A8784], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8784u, ctx.xmm[0].u32[0]);
	// 0x2BD2B0: ret
	return;
}

void sub_2BD2C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD2C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD2C8: movss [0x005A874C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A874Cu, ctx.xmm[0].u32[0]);
	// 0x2BD2D0: ret
	return;
}

void sub_2BD2E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD2E0: movss xmm0, dword ptr [0x005A8750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8750u);
	// 0x2BD2E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BD2F0: movss [0x005A8780], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8780u, ctx.xmm[0].u32[0]);
	// 0x2BD2F8: ret
	return;
}

void sub_2BD300(X86Context& ctx, uint8_t* base) {
	// 0x2BD300: movss xmm0, dword ptr [0x005A8750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8750u);
	// 0x2BD308: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BD310: movss [0x005A875C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A875Cu, ctx.xmm[0].u32[0]);
	// 0x2BD318: ret
	return;
}

void sub_2BD320(X86Context& ctx, uint8_t* base) {
	// 0x2BD320: movss xmm0, dword ptr [0x005A8750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8750u);
	// 0x2BD328: subss xmm0, [0x005A875C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A875Cu);
	// 0x2BD330: movss [0x005A8758], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8758u, ctx.xmm[0].u32[0]);
	// 0x2BD338: ret
	return;
}

void sub_2BD340(X86Context& ctx, uint8_t* base) {
	// 0x2BD340: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BD348: movss [0x005A876C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A876Cu, ctx.xmm[0].u32[0]);
	// 0x2BD350: ret
	return;
}

void sub_2BD360(X86Context& ctx, uint8_t* base) {
	// 0x2BD360: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BD368: movss [0x005A8754], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8754u, ctx.xmm[0].u32[0]);
	// 0x2BD370: ret
	return;
}

void sub_2BD380(X86Context& ctx, uint8_t* base) {
	// 0x2BD380: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BD388: movss [0x005A8794], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8794u, ctx.xmm[0].u32[0]);
	// 0x2BD390: ret
	return;
}

void sub_2BD3A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD3A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BD3A8: movss [0x005A8798], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8798u, ctx.xmm[0].u32[0]);
	// 0x2BD3B0: ret
	return;
}

void sub_2BD3C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD3C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BD3C8: movss [0x005A8790], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8790u, ctx.xmm[0].u32[0]);
	// 0x2BD3D0: ret
	return;
}

void sub_2BD3E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD3E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BD3E8: movss [0x005A878C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A878Cu, ctx.xmm[0].u32[0]);
	// 0x2BD3F0: ret
	return;
}

void sub_2BD400(X86Context& ctx, uint8_t* base) {
	// 0x2BD400: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BD408: movss [0x005A87B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87B8u, ctx.xmm[0].u32[0]);
	// 0x2BD410: ret
	return;
}

void sub_2BD420(X86Context& ctx, uint8_t* base) {
	// 0x2BD420: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BD428: movss [0x005A87C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87C4u, ctx.xmm[0].u32[0]);
	// 0x2BD430: ret
	return;
}

void sub_2BD440(X86Context& ctx, uint8_t* base) {
	// 0x2BD440: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BD448: movss [0x005A87B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87B4u, ctx.xmm[0].u32[0]);
	// 0x2BD450: ret
	return;
}

void sub_2BD460(X86Context& ctx, uint8_t* base) {
	// 0x2BD460: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BD468: movss [0x005A879C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A879Cu, ctx.xmm[0].u32[0]);
	// 0x2BD470: ret
	return;
}

void sub_2BD480(X86Context& ctx, uint8_t* base) {
	// 0x2BD480: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BD488: movss [0x005A87BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87BCu, ctx.xmm[0].u32[0]);
	// 0x2BD490: ret
	return;
}

void sub_2BD4A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD4A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BD4A8: movss [0x005A87A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87A4u, ctx.xmm[0].u32[0]);
	// 0x2BD4B0: ret
	return;
}

void sub_2BD4C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD4C0: movss xmm0, dword ptr [0x005A87BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A87BCu);
	// 0x2BD4C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BD4D0: movss [0x005A87CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87CCu, ctx.xmm[0].u32[0]);
	// 0x2BD4D8: ret
	return;
}

void sub_2BD4E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD4E0: movss xmm0, dword ptr [0x005A87A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A87A4u);
	// 0x2BD4E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BD4F0: movss [0x005A87C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87C8u, ctx.xmm[0].u32[0]);
	// 0x2BD4F8: ret
	return;
}

void sub_2BD500(X86Context& ctx, uint8_t* base) {
	// 0x2BD500: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD508: movss [0x005A87DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87DCu, ctx.xmm[0].u32[0]);
	// 0x2BD510: ret
	return;
}

void sub_2BD520(X86Context& ctx, uint8_t* base) {
	// 0x2BD520: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BD528: movss [0x005A87D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87D0u, ctx.xmm[0].u32[0]);
	// 0x2BD530: ret
	return;
}

void sub_2BD540(X86Context& ctx, uint8_t* base) {
	// 0x2BD540: movss xmm0, dword ptr [0x005A87D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A87D0u);
	// 0x2BD548: movss [0x005A87D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87D8u, ctx.xmm[0].u32[0]);
	// 0x2BD550: ret
	return;
}

void sub_2BD560(X86Context& ctx, uint8_t* base) {
	// 0x2BD560: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD568: movss [0x005A87A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87A0u, ctx.xmm[0].u32[0]);
	// 0x2BD570: ret
	return;
}

void sub_2BD580(X86Context& ctx, uint8_t* base) {
	// 0x2BD580: movss xmm0, dword ptr [0x005A87A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A87A4u);
	// 0x2BD588: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BD590: movss [0x005A87D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87D4u, ctx.xmm[0].u32[0]);
	// 0x2BD598: ret
	return;
}

void sub_2BD5A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD5A0: movss xmm0, dword ptr [0x005A87A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A87A4u);
	// 0x2BD5A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BD5B0: movss [0x005A87B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87B0u, ctx.xmm[0].u32[0]);
	// 0x2BD5B8: ret
	return;
}

void sub_2BD5C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD5C0: movss xmm0, dword ptr [0x005A87A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A87A4u);
	// 0x2BD5C8: subss xmm0, [0x005A87B0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A87B0u);
	// 0x2BD5D0: movss [0x005A87AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87ACu, ctx.xmm[0].u32[0]);
	// 0x2BD5D8: ret
	return;
}

void sub_2BD5E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD5E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BD5E8: movss [0x005A87C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87C0u, ctx.xmm[0].u32[0]);
	// 0x2BD5F0: ret
	return;
}

void sub_2BD600(X86Context& ctx, uint8_t* base) {
	// 0x2BD600: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BD608: movss [0x005A87A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87A8u, ctx.xmm[0].u32[0]);
	// 0x2BD610: ret
	return;
}

void sub_2BD620(X86Context& ctx, uint8_t* base) {
	// 0x2BD620: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BD628: movss [0x005A8814], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8814u, ctx.xmm[0].u32[0]);
	// 0x2BD630: ret
	return;
}

void sub_2BD640(X86Context& ctx, uint8_t* base) {
	// 0x2BD640: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BD648: movss [0x005A8820], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8820u, ctx.xmm[0].u32[0]);
	// 0x2BD650: ret
	return;
}

void sub_2BD660(X86Context& ctx, uint8_t* base) {
	// 0x2BD660: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BD668: movss [0x005A8804], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8804u, ctx.xmm[0].u32[0]);
	// 0x2BD670: ret
	return;
}

void sub_2BD680(X86Context& ctx, uint8_t* base) {
	// 0x2BD680: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BD688: movss [0x005A87E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87E0u, ctx.xmm[0].u32[0]);
	// 0x2BD690: ret
	return;
}

void sub_2BD6A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD6A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BD6A8: movss [0x005A8818], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8818u, ctx.xmm[0].u32[0]);
	// 0x2BD6B0: ret
	return;
}

void sub_2BD6C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD6C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BD6C8: movss [0x005A87E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87E8u, ctx.xmm[0].u32[0]);
	// 0x2BD6D0: ret
	return;
}

void sub_2BD6E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD6E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BD6E8: movss [0x005A882C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A882Cu, ctx.xmm[0].u32[0]);
	// 0x2BD6F0: ret
	return;
}

void sub_2BD700(X86Context& ctx, uint8_t* base) {
	// 0x2BD700: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BD708: movss [0x005A8808], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8808u, ctx.xmm[0].u32[0]);
	// 0x2BD710: ret
	return;
}

void sub_2BD720(X86Context& ctx, uint8_t* base) {
	// 0x2BD720: movss xmm0, dword ptr [0x005A882C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A882Cu);
	// 0x2BD728: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BD730: movss [0x005A87F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87F4u, ctx.xmm[0].u32[0]);
	// 0x2BD738: ret
	return;
}

void sub_2BD740(X86Context& ctx, uint8_t* base) {
	// 0x2BD740: movss xmm0, dword ptr [0x005A8808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8808u);
	// 0x2BD748: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BD750: movss [0x005A8824], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8824u, ctx.xmm[0].u32[0]);
	// 0x2BD758: ret
	return;
}

void sub_2BD760(X86Context& ctx, uint8_t* base) {
	// 0x2BD760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD768: movss [0x005A8838], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8838u, ctx.xmm[0].u32[0]);
	// 0x2BD770: ret
	return;
}

void sub_2BD780(X86Context& ctx, uint8_t* base) {
	// 0x2BD780: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BD788: movss [0x005A8830], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8830u, ctx.xmm[0].u32[0]);
	// 0x2BD790: ret
	return;
}

void sub_2BD7A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD7A0: movss xmm0, dword ptr [0x005A8830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8830u);
	// 0x2BD7A8: movss [0x005A8834], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8834u, ctx.xmm[0].u32[0]);
	// 0x2BD7B0: ret
	return;
}

void sub_2BD7C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD7C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BD7C8: movss [0x005A8800], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8800u, ctx.xmm[0].u32[0]);
	// 0x2BD7D0: ret
	return;
}

void sub_2BD7E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD7E0: movss xmm0, dword ptr [0x005A8808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8808u);
	// 0x2BD7E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BD7F0: movss [0x005A87FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87FCu, ctx.xmm[0].u32[0]);
	// 0x2BD7F8: ret
	return;
}

void sub_2BD800(X86Context& ctx, uint8_t* base) {
	// 0x2BD800: movss xmm0, dword ptr [0x005A8808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8808u);
	// 0x2BD808: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BD810: movss [0x005A881C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A881Cu, ctx.xmm[0].u32[0]);
	// 0x2BD818: ret
	return;
}

void sub_2BD820(X86Context& ctx, uint8_t* base) {
	// 0x2BD820: movss xmm0, dword ptr [0x005A8808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8808u);
	// 0x2BD828: subss xmm0, [0x005A881C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A881Cu);
	// 0x2BD830: movss [0x005A87F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87F0u, ctx.xmm[0].u32[0]);
	// 0x2BD838: ret
	return;
}

