#include "x86_recomp_shared.h"

void sub_2668C0(X86Context& ctx, uint8_t* base) {
	// 0x2668C0: movss xmm0, dword ptr [0x0054F870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F870u);
	// 0x2668C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2668D0: movss [0x0054F880], xmm0
	X86_MEM_WRITE_u32(base, 0x54F880u, ctx.xmm[0].u32[0]);
	// 0x2668D8: ret
	return;
}

void sub_2668E0(X86Context& ctx, uint8_t* base) {
	// 0x2668E0: movss xmm0, dword ptr [0x0054F858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F858u);
	// 0x2668E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2668F0: movss [0x0054F87C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F87Cu, ctx.xmm[0].u32[0]);
	// 0x2668F8: ret
	return;
}

void sub_266900(X86Context& ctx, uint8_t* base) {
	// 0x266900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266908: movss [0x0054F890], xmm0
	X86_MEM_WRITE_u32(base, 0x54F890u, ctx.xmm[0].u32[0]);
	// 0x266910: ret
	return;
}

void sub_266920(X86Context& ctx, uint8_t* base) {
	// 0x266920: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266928: movss [0x0054F884], xmm0
	X86_MEM_WRITE_u32(base, 0x54F884u, ctx.xmm[0].u32[0]);
	// 0x266930: ret
	return;
}

void sub_266940(X86Context& ctx, uint8_t* base) {
	// 0x266940: movss xmm0, dword ptr [0x0054F884]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F884u);
	// 0x266948: movss [0x0054F88C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F88Cu, ctx.xmm[0].u32[0]);
	// 0x266950: ret
	return;
}

void sub_266960(X86Context& ctx, uint8_t* base) {
	// 0x266960: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266968: movss [0x0054F854], xmm0
	X86_MEM_WRITE_u32(base, 0x54F854u, ctx.xmm[0].u32[0]);
	// 0x266970: ret
	return;
}

void sub_266980(X86Context& ctx, uint8_t* base) {
	// 0x266980: movss xmm0, dword ptr [0x0054F858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F858u);
	// 0x266988: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x266990: movss [0x0054F888], xmm0
	X86_MEM_WRITE_u32(base, 0x54F888u, ctx.xmm[0].u32[0]);
	// 0x266998: ret
	return;
}

void sub_2669A0(X86Context& ctx, uint8_t* base) {
	// 0x2669A0: movss xmm0, dword ptr [0x0054F858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F858u);
	// 0x2669A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2669B0: movss [0x0054F864], xmm0
	X86_MEM_WRITE_u32(base, 0x54F864u, ctx.xmm[0].u32[0]);
	// 0x2669B8: ret
	return;
}

void sub_2669C0(X86Context& ctx, uint8_t* base) {
	// 0x2669C0: movss xmm0, dword ptr [0x0054F858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F858u);
	// 0x2669C8: subss xmm0, [0x0054F864]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F864u);
	// 0x2669D0: movss [0x0054F860], xmm0
	X86_MEM_WRITE_u32(base, 0x54F860u, ctx.xmm[0].u32[0]);
	// 0x2669D8: ret
	return;
}

void sub_2669E0(X86Context& ctx, uint8_t* base) {
	// 0x2669E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2669E8: movss [0x0054F874], xmm0
	X86_MEM_WRITE_u32(base, 0x54F874u, ctx.xmm[0].u32[0]);
	// 0x2669F0: ret
	return;
}

void sub_266A00(X86Context& ctx, uint8_t* base) {
	// 0x266A00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x266A08: movss [0x0054F85C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F85Cu, ctx.xmm[0].u32[0]);
	// 0x266A10: ret
	return;
}

void sub_266A20(X86Context& ctx, uint8_t* base) {
	// 0x266A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x266A28: movss [0x0054F8B8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8B8u, ctx.xmm[0].u32[0]);
	// 0x266A30: ret
	return;
}

void sub_266A40(X86Context& ctx, uint8_t* base) {
	// 0x266A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266A48: movss [0x0054F8C4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8C4u, ctx.xmm[0].u32[0]);
	// 0x266A50: ret
	return;
}

void sub_266A60(X86Context& ctx, uint8_t* base) {
	// 0x266A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266A68: movss [0x0054F8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8B0u, ctx.xmm[0].u32[0]);
	// 0x266A70: ret
	return;
}

void sub_266A80(X86Context& ctx, uint8_t* base) {
	// 0x266A80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x266A88: movss [0x0054F894], xmm0
	X86_MEM_WRITE_u32(base, 0x54F894u, ctx.xmm[0].u32[0]);
	// 0x266A90: ret
	return;
}

void sub_266AA0(X86Context& ctx, uint8_t* base) {
	// 0x266AA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x266AA8: movss [0x0054F8BC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8BCu, ctx.xmm[0].u32[0]);
	// 0x266AB0: ret
	return;
}

void sub_266AC0(X86Context& ctx, uint8_t* base) {
	// 0x266AC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x266AC8: movss [0x0054F89C], xmm0
	X86_MEM_WRITE_u32(base, 0x54F89Cu, ctx.xmm[0].u32[0]);
	// 0x266AD0: ret
	return;
}

void sub_266AE0(X86Context& ctx, uint8_t* base) {
	// 0x266AE0: movss xmm0, dword ptr [0x0054F8BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8BCu);
	// 0x266AE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x266AF0: movss [0x0054F8D4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8D4u, ctx.xmm[0].u32[0]);
	// 0x266AF8: ret
	return;
}

void sub_266B00(X86Context& ctx, uint8_t* base) {
	// 0x266B00: movss xmm0, dword ptr [0x0054F89C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F89Cu);
	// 0x266B08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x266B10: movss [0x0054F8C8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8C8u, ctx.xmm[0].u32[0]);
	// 0x266B18: ret
	return;
}

void sub_266B20(X86Context& ctx, uint8_t* base) {
	// 0x266B20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266B28: movss [0x0054F8E4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8E4u, ctx.xmm[0].u32[0]);
	// 0x266B30: ret
	return;
}

void sub_266B40(X86Context& ctx, uint8_t* base) {
	// 0x266B40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266B48: movss [0x0054F8D8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8D8u, ctx.xmm[0].u32[0]);
	// 0x266B50: ret
	return;
}

void sub_266B60(X86Context& ctx, uint8_t* base) {
	// 0x266B60: movss xmm0, dword ptr [0x0054F8D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8D8u);
	// 0x266B68: movss [0x0054F8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8E0u, ctx.xmm[0].u32[0]);
	// 0x266B70: ret
	return;
}

void sub_266B80(X86Context& ctx, uint8_t* base) {
	// 0x266B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266B88: movss [0x0054F898], xmm0
	X86_MEM_WRITE_u32(base, 0x54F898u, ctx.xmm[0].u32[0]);
	// 0x266B90: ret
	return;
}

void sub_266BA0(X86Context& ctx, uint8_t* base) {
	// 0x266BA0: movss xmm0, dword ptr [0x0054F89C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F89Cu);
	// 0x266BA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x266BB0: movss [0x0054F8DC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8DCu, ctx.xmm[0].u32[0]);
	// 0x266BB8: ret
	return;
}

void sub_266BC0(X86Context& ctx, uint8_t* base) {
	// 0x266BC0: movss xmm0, dword ptr [0x0054F89C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F89Cu);
	// 0x266BC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x266BD0: movss [0x0054F8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8ACu, ctx.xmm[0].u32[0]);
	// 0x266BD8: ret
	return;
}

void sub_266BE0(X86Context& ctx, uint8_t* base) {
	// 0x266BE0: movss xmm0, dword ptr [0x0054F89C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F89Cu);
	// 0x266BE8: subss xmm0, [0x0054F8AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F8ACu);
	// 0x266BF0: movss [0x0054F8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8A4u, ctx.xmm[0].u32[0]);
	// 0x266BF8: ret
	return;
}

void sub_266C00(X86Context& ctx, uint8_t* base) {
	// 0x266C00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x266C08: movss [0x0054F8C0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8C0u, ctx.xmm[0].u32[0]);
	// 0x266C10: ret
	return;
}

void sub_266C20(X86Context& ctx, uint8_t* base) {
	// 0x266C20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x266C28: movss [0x0054F8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8A0u, ctx.xmm[0].u32[0]);
	// 0x266C30: ret
	return;
}

void sub_266C40(X86Context& ctx, uint8_t* base) {
	// 0x266C40: movss xmm0, dword ptr [0x0054F8D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8D8u);
	// 0x266C48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x266C50: movss [0x0054F8D0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8D0u, ctx.xmm[0].u32[0]);
	// 0x266C58: ret
	return;
}

void sub_266C60(X86Context& ctx, uint8_t* base) {
	// 0x266C60: movss xmm0, dword ptr [0x003B1C08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C08u);
	// 0x266C68: movss [0x0054F8CC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8CCu, ctx.xmm[0].u32[0]);
	// 0x266C70: ret
	return;
}

void sub_266C80(X86Context& ctx, uint8_t* base) {
	// 0x266C80: movss xmm0, dword ptr [0x0054F8CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8CCu);
	// 0x266C88: addss xmm0, [0x003B16B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B4u);
	// 0x266C90: movss [0x0054F8B4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8B4u, ctx.xmm[0].u32[0]);
	// 0x266C98: ret
	return;
}

void sub_266CA0(X86Context& ctx, uint8_t* base) {
	// 0x266CA0: movss xmm0, dword ptr [0x0054F8CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8CCu);
	// 0x266CA8: addss xmm0, [0x00389CB8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x389CB8u);
	// 0x266CB0: movss [0x0054F8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8A8u, ctx.xmm[0].u32[0]);
	// 0x266CB8: ret
	return;
}

void sub_266CC0(X86Context& ctx, uint8_t* base) {
	// 0x266CC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x266CC8: movss [0x0054FA84], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA84u, ctx.xmm[0].u32[0]);
	// 0x266CD0: ret
	return;
}

void sub_266CE0(X86Context& ctx, uint8_t* base) {
	// 0x266CE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266CE8: movss [0x0054FA90], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA90u, ctx.xmm[0].u32[0]);
	// 0x266CF0: ret
	return;
}

void sub_266D00(X86Context& ctx, uint8_t* base) {
	// 0x266D00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266D08: movss [0x0054FA80], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA80u, ctx.xmm[0].u32[0]);
	// 0x266D10: ret
	return;
}

void sub_266D20(X86Context& ctx, uint8_t* base) {
	// 0x266D20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x266D28: movss [0x0054F8E8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8E8u, ctx.xmm[0].u32[0]);
	// 0x266D30: ret
	return;
}

void sub_266D40(X86Context& ctx, uint8_t* base) {
	// 0x266D40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x266D48: movss [0x0054FA88], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA88u, ctx.xmm[0].u32[0]);
	// 0x266D50: ret
	return;
}

void sub_266D60(X86Context& ctx, uint8_t* base) {
	// 0x266D60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x266D68: movss [0x0054F8F0], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8F0u, ctx.xmm[0].u32[0]);
	// 0x266D70: ret
	return;
}

void sub_266D80(X86Context& ctx, uint8_t* base) {
	// 0x266D80: movss xmm0, dword ptr [0x0054FA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FA88u);
	// 0x266D88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x266D90: movss [0x0054FA98], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA98u, ctx.xmm[0].u32[0]);
	// 0x266D98: ret
	return;
}

void sub_266DA0(X86Context& ctx, uint8_t* base) {
	// 0x266DA0: movss xmm0, dword ptr [0x0054F8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8F0u);
	// 0x266DA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x266DB0: movss [0x0054FA94], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA94u, ctx.xmm[0].u32[0]);
	// 0x266DB8: ret
	return;
}

void sub_266DC0(X86Context& ctx, uint8_t* base) {
	// 0x266DC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266DC8: movss [0x0054FAA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAA8u, ctx.xmm[0].u32[0]);
	// 0x266DD0: ret
	return;
}

void sub_266DE0(X86Context& ctx, uint8_t* base) {
	// 0x266DE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x266DE8: movss [0x0054FA9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA9Cu, ctx.xmm[0].u32[0]);
	// 0x266DF0: ret
	return;
}

void sub_266E00(X86Context& ctx, uint8_t* base) {
	// 0x266E00: movss xmm0, dword ptr [0x0054FA9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FA9Cu);
	// 0x266E08: movss [0x0054FAA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAA4u, ctx.xmm[0].u32[0]);
	// 0x266E10: ret
	return;
}

void sub_266E20(X86Context& ctx, uint8_t* base) {
	// 0x266E20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266E28: movss [0x0054F8EC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8ECu, ctx.xmm[0].u32[0]);
	// 0x266E30: ret
	return;
}

void sub_266E40(X86Context& ctx, uint8_t* base) {
	// 0x266E40: movss xmm0, dword ptr [0x0054F8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8F0u);
	// 0x266E48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x266E50: movss [0x0054FAA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAA0u, ctx.xmm[0].u32[0]);
	// 0x266E58: ret
	return;
}

void sub_266E60(X86Context& ctx, uint8_t* base) {
	// 0x266E60: movss xmm0, dword ptr [0x0054F8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8F0u);
	// 0x266E68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x266E70: movss [0x0054F8FC], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8FCu, ctx.xmm[0].u32[0]);
	// 0x266E78: ret
	return;
}

void sub_266E80(X86Context& ctx, uint8_t* base) {
	// 0x266E80: movss xmm0, dword ptr [0x0054F8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54F8F0u);
	// 0x266E88: subss xmm0, [0x0054F8FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54F8FCu);
	// 0x266E90: movss [0x0054F8F8], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8F8u, ctx.xmm[0].u32[0]);
	// 0x266E98: ret
	return;
}

void sub_266EA0(X86Context& ctx, uint8_t* base) {
	// 0x266EA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x266EA8: movss [0x0054FA8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FA8Cu, ctx.xmm[0].u32[0]);
	// 0x266EB0: ret
	return;
}

void sub_266EC0(X86Context& ctx, uint8_t* base) {
	// 0x266EC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x266EC8: movss [0x0054F8F4], xmm0
	X86_MEM_WRITE_u32(base, 0x54F8F4u, ctx.xmm[0].u32[0]);
	// 0x266ED0: ret
	return;
}

void sub_266EE0(X86Context& ctx, uint8_t* base) {
	// 0x266EE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x266EE8: movss [0x0054FAC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAC8u, ctx.xmm[0].u32[0]);
	// 0x266EF0: ret
	return;
}

void sub_266F00(X86Context& ctx, uint8_t* base) {
	// 0x266F00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x266F08: movss [0x0054FAD4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAD4u, ctx.xmm[0].u32[0]);
	// 0x266F10: ret
	return;
}

void sub_266F20(X86Context& ctx, uint8_t* base) {
	// 0x266F20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x266F28: movss [0x0054FAC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAC4u, ctx.xmm[0].u32[0]);
	// 0x266F30: ret
	return;
}

void sub_266F40(X86Context& ctx, uint8_t* base) {
	// 0x266F40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x266F48: movss [0x0054FAAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAACu, ctx.xmm[0].u32[0]);
	// 0x266F50: ret
	return;
}

void sub_266F60(X86Context& ctx, uint8_t* base) {
	// 0x266F60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x266F68: movss [0x0054FACC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FACCu, ctx.xmm[0].u32[0]);
	// 0x266F70: ret
	return;
}

void sub_266F80(X86Context& ctx, uint8_t* base) {
	// 0x266F80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x266F88: movss [0x0054FAB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAB4u, ctx.xmm[0].u32[0]);
	// 0x266F90: ret
	return;
}

void sub_266FA0(X86Context& ctx, uint8_t* base) {
	// 0x266FA0: movss xmm0, dword ptr [0x0054FACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FACCu);
	// 0x266FA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x266FB0: movss [0x0054FADC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FADCu, ctx.xmm[0].u32[0]);
	// 0x266FB8: ret
	return;
}

void sub_266FC0(X86Context& ctx, uint8_t* base) {
	// 0x266FC0: movss xmm0, dword ptr [0x0054FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAB4u);
	// 0x266FC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x266FD0: movss [0x0054FAD8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAD8u, ctx.xmm[0].u32[0]);
	// 0x266FD8: ret
	return;
}

void sub_266FE0(X86Context& ctx, uint8_t* base) {
	// 0x266FE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x266FE8: movss [0x0054FAEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAECu, ctx.xmm[0].u32[0]);
	// 0x266FF0: ret
	return;
}

void sub_267000(X86Context& ctx, uint8_t* base) {
	// 0x267000: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x267008: movss [0x0054FAE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAE0u, ctx.xmm[0].u32[0]);
	// 0x267010: ret
	return;
}

void sub_267020(X86Context& ctx, uint8_t* base) {
	// 0x267020: movss xmm0, dword ptr [0x0054FAE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAE0u);
	// 0x267028: movss [0x0054FAE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAE8u, ctx.xmm[0].u32[0]);
	// 0x267030: ret
	return;
}

void sub_267040(X86Context& ctx, uint8_t* base) {
	// 0x267040: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267048: movss [0x0054FAB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAB0u, ctx.xmm[0].u32[0]);
	// 0x267050: ret
	return;
}

void sub_267060(X86Context& ctx, uint8_t* base) {
	// 0x267060: movss xmm0, dword ptr [0x0054FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAB4u);
	// 0x267068: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x267070: movss [0x0054FAE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAE4u, ctx.xmm[0].u32[0]);
	// 0x267078: ret
	return;
}

void sub_267080(X86Context& ctx, uint8_t* base) {
	// 0x267080: movss xmm0, dword ptr [0x0054FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAB4u);
	// 0x267088: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x267090: movss [0x0054FAC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAC0u, ctx.xmm[0].u32[0]);
	// 0x267098: ret
	return;
}

void sub_2670A0(X86Context& ctx, uint8_t* base) {
	// 0x2670A0: movss xmm0, dword ptr [0x0054FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAB4u);
	// 0x2670A8: subss xmm0, [0x0054FAC0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FAC0u);
	// 0x2670B0: movss [0x0054FABC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FABCu, ctx.xmm[0].u32[0]);
	// 0x2670B8: ret
	return;
}

void sub_2670C0(X86Context& ctx, uint8_t* base) {
	// 0x2670C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2670C8: movss [0x0054FAD0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAD0u, ctx.xmm[0].u32[0]);
	// 0x2670D0: ret
	return;
}

void sub_2670E0(X86Context& ctx, uint8_t* base) {
	// 0x2670E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2670E8: movss [0x0054FAB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAB8u, ctx.xmm[0].u32[0]);
	// 0x2670F0: ret
	return;
}

void sub_267100(X86Context& ctx, uint8_t* base) {
	// 0x267100: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x267108: movss [0x0054FB0C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB0Cu, ctx.xmm[0].u32[0]);
	// 0x267110: ret
	return;
}

void sub_267120(X86Context& ctx, uint8_t* base) {
	// 0x267120: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x267128: movss [0x0054FB18], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB18u, ctx.xmm[0].u32[0]);
	// 0x267130: ret
	return;
}

void sub_267140(X86Context& ctx, uint8_t* base) {
	// 0x267140: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x267148: movss [0x0054FB08], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB08u, ctx.xmm[0].u32[0]);
	// 0x267150: ret
	return;
}

void sub_267160(X86Context& ctx, uint8_t* base) {
	// 0x267160: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x267168: movss [0x0054FAF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAF0u, ctx.xmm[0].u32[0]);
	// 0x267170: ret
	return;
}

void sub_267180(X86Context& ctx, uint8_t* base) {
	// 0x267180: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x267188: movss [0x0054FB10], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB10u, ctx.xmm[0].u32[0]);
	// 0x267190: ret
	return;
}

void sub_2671A0(X86Context& ctx, uint8_t* base) {
	// 0x2671A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2671A8: movss [0x0054FAF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAF8u, ctx.xmm[0].u32[0]);
	// 0x2671B0: ret
	return;
}

void sub_2671C0(X86Context& ctx, uint8_t* base) {
	// 0x2671C0: movss xmm0, dword ptr [0x0054FB10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB10u);
	// 0x2671C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2671D0: movss [0x0054FB20], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB20u, ctx.xmm[0].u32[0]);
	// 0x2671D8: ret
	return;
}

void sub_2671E0(X86Context& ctx, uint8_t* base) {
	// 0x2671E0: movss xmm0, dword ptr [0x0054FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAF8u);
	// 0x2671E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2671F0: movss [0x0054FB1C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB1Cu, ctx.xmm[0].u32[0]);
	// 0x2671F8: ret
	return;
}

void sub_267200(X86Context& ctx, uint8_t* base) {
	// 0x267200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267208: movss [0x0054FB30], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB30u, ctx.xmm[0].u32[0]);
	// 0x267210: ret
	return;
}

void sub_267220(X86Context& ctx, uint8_t* base) {
	// 0x267220: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x267228: movss [0x0054FB24], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB24u, ctx.xmm[0].u32[0]);
	// 0x267230: ret
	return;
}

void sub_267240(X86Context& ctx, uint8_t* base) {
	// 0x267240: movss xmm0, dword ptr [0x0054FB24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB24u);
	// 0x267248: movss [0x0054FB2C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB2Cu, ctx.xmm[0].u32[0]);
	// 0x267250: ret
	return;
}

void sub_267260(X86Context& ctx, uint8_t* base) {
	// 0x267260: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267268: movss [0x0054FAF4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAF4u, ctx.xmm[0].u32[0]);
	// 0x267270: ret
	return;
}

void sub_267280(X86Context& ctx, uint8_t* base) {
	// 0x267280: movss xmm0, dword ptr [0x0054FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAF8u);
	// 0x267288: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x267290: movss [0x0054FB28], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB28u, ctx.xmm[0].u32[0]);
	// 0x267298: ret
	return;
}

void sub_2672A0(X86Context& ctx, uint8_t* base) {
	// 0x2672A0: movss xmm0, dword ptr [0x0054FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAF8u);
	// 0x2672A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2672B0: movss [0x0054FB04], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB04u, ctx.xmm[0].u32[0]);
	// 0x2672B8: ret
	return;
}

void sub_2672C0(X86Context& ctx, uint8_t* base) {
	// 0x2672C0: movss xmm0, dword ptr [0x0054FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FAF8u);
	// 0x2672C8: subss xmm0, [0x0054FB04]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FB04u);
	// 0x2672D0: movss [0x0054FB00], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB00u, ctx.xmm[0].u32[0]);
	// 0x2672D8: ret
	return;
}

void sub_2672E0(X86Context& ctx, uint8_t* base) {
	// 0x2672E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2672E8: movss [0x0054FB14], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB14u, ctx.xmm[0].u32[0]);
	// 0x2672F0: ret
	return;
}

void sub_267300(X86Context& ctx, uint8_t* base) {
	// 0x267300: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x267308: movss [0x0054FAFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FAFCu, ctx.xmm[0].u32[0]);
	// 0x267310: ret
	return;
}

void sub_267320(X86Context& ctx, uint8_t* base) {
	// 0x267320: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x267328: movss [0x0054FB5C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB5Cu, ctx.xmm[0].u32[0]);
	// 0x267330: ret
	return;
}

void sub_267340(X86Context& ctx, uint8_t* base) {
	// 0x267340: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x267348: movss [0x0054FB6C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB6Cu, ctx.xmm[0].u32[0]);
	// 0x267350: ret
	return;
}

void sub_267360(X86Context& ctx, uint8_t* base) {
	// 0x267360: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x267368: movss [0x0054FB58], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB58u, ctx.xmm[0].u32[0]);
	// 0x267370: ret
	return;
}

void sub_267380(X86Context& ctx, uint8_t* base) {
	// 0x267380: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x267388: movss [0x0054FB34], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB34u, ctx.xmm[0].u32[0]);
	// 0x267390: ret
	return;
}

void sub_2673A0(X86Context& ctx, uint8_t* base) {
	// 0x2673A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2673A8: movss [0x0054FB60], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB60u, ctx.xmm[0].u32[0]);
	// 0x2673B0: ret
	return;
}

void sub_2673C0(X86Context& ctx, uint8_t* base) {
	// 0x2673C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2673C8: movss [0x0054FB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB3Cu, ctx.xmm[0].u32[0]);
	// 0x2673D0: ret
	return;
}

void sub_2673E0(X86Context& ctx, uint8_t* base) {
	// 0x2673E0: movss xmm0, dword ptr [0x0054FB60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB60u);
	// 0x2673E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2673F0: movss [0x0054FB78], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB78u, ctx.xmm[0].u32[0]);
	// 0x2673F8: ret
	return;
}

void sub_267400(X86Context& ctx, uint8_t* base) {
	// 0x267400: movss xmm0, dword ptr [0x0054FB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB3Cu);
	// 0x267408: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x267410: movss [0x0054FB70], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB70u, ctx.xmm[0].u32[0]);
	// 0x267418: ret
	return;
}

void sub_267420(X86Context& ctx, uint8_t* base) {
	// 0x267420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267428: movss [0x0054FB98], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB98u, ctx.xmm[0].u32[0]);
	// 0x267430: ret
	return;
}

void sub_267440(X86Context& ctx, uint8_t* base) {
	// 0x267440: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x267448: movss [0x0054FB7C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB7Cu, ctx.xmm[0].u32[0]);
	// 0x267450: ret
	return;
}

void sub_267460(X86Context& ctx, uint8_t* base) {
	// 0x267460: movss xmm0, dword ptr [0x0054FB7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB7Cu);
	// 0x267468: movss [0x0054FB94], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB94u, ctx.xmm[0].u32[0]);
	// 0x267470: ret
	return;
}

void sub_267480(X86Context& ctx, uint8_t* base) {
	// 0x267480: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267488: movss [0x0054FB38], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB38u, ctx.xmm[0].u32[0]);
	// 0x267490: ret
	return;
}

void sub_2674A0(X86Context& ctx, uint8_t* base) {
	// 0x2674A0: movss xmm0, dword ptr [0x0054FB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB3Cu);
	// 0x2674A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2674B0: movss [0x0054FB88], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB88u, ctx.xmm[0].u32[0]);
	// 0x2674B8: ret
	return;
}

void sub_2674C0(X86Context& ctx, uint8_t* base) {
	// 0x2674C0: movss xmm0, dword ptr [0x0054FB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB3Cu);
	// 0x2674C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2674D0: movss [0x0054FB54], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB54u, ctx.xmm[0].u32[0]);
	// 0x2674D8: ret
	return;
}

void sub_2674E0(X86Context& ctx, uint8_t* base) {
	// 0x2674E0: movss xmm0, dword ptr [0x0054FB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB3Cu);
	// 0x2674E8: subss xmm0, [0x0054FB54]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FB54u);
	// 0x2674F0: movss [0x0054FB44], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB44u, ctx.xmm[0].u32[0]);
	// 0x2674F8: ret
	return;
}

void sub_267500(X86Context& ctx, uint8_t* base) {
	// 0x267500: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x267508: movss [0x0054FB68], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB68u, ctx.xmm[0].u32[0]);
	// 0x267510: ret
	return;
}

void sub_267520(X86Context& ctx, uint8_t* base) {
	// 0x267520: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x267528: movss [0x0054FB40], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB40u, ctx.xmm[0].u32[0]);
	// 0x267530: ret
	return;
}

void sub_267540(X86Context& ctx, uint8_t* base) {
	// 0x267540: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x267548: movss [0x0054FB64], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB64u, ctx.xmm[0].u32[0]);
	// 0x267550: ret
	return;
}

void sub_267560(X86Context& ctx, uint8_t* base) {
	// 0x267560: movss xmm0, dword ptr [0x003B2214]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2214u);
	// 0x267568: movss [0x0054FB74], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB74u, ctx.xmm[0].u32[0]);
	// 0x267570: ret
	return;
}

void sub_267580(X86Context& ctx, uint8_t* base) {
	// 0x267580: movss xmm0, dword ptr [0x003B2218]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2218u);
	// 0x267588: movss [0x0054FB8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB8Cu, ctx.xmm[0].u32[0]);
	// 0x267590: ret
	return;
}

void sub_2675A0(X86Context& ctx, uint8_t* base) {
	// 0x2675A0: movss xmm0, dword ptr [0x003B1870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x2675A8: movss [0x0054FB90], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB90u, ctx.xmm[0].u32[0]);
	// 0x2675B0: ret
	return;
}

void sub_2675C0(X86Context& ctx, uint8_t* base) {
	// 0x2675C0: movss xmm0, dword ptr [0x003B1730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2675C8: movss [0x0054FB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB4Cu, ctx.xmm[0].u32[0]);
	// 0x2675D0: ret
	return;
}

void sub_2675E0(X86Context& ctx, uint8_t* base) {
	// 0x2675E0: movss xmm0, dword ptr [0x003B1684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2675E8: movss [0x0054FB80], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB80u, ctx.xmm[0].u32[0]);
	// 0x2675F0: ret
	return;
}

void sub_267600(X86Context& ctx, uint8_t* base) {
	// 0x267600: movss xmm0, dword ptr [0x0054FB80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FB80u);
	// 0x267608: addss xmm0, [0x003B1730]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1730u);
	// 0x267610: movss [0x0054FB84], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB84u, ctx.xmm[0].u32[0]);
	// 0x267618: ret
	return;
}

void sub_267620(X86Context& ctx, uint8_t* base) {
	// 0x267620: movss xmm0, dword ptr [0x003B221C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B221Cu);
	// 0x267628: movss [0x0054FB48], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB48u, ctx.xmm[0].u32[0]);
	// 0x267630: ret
	return;
}

void sub_267640(X86Context& ctx, uint8_t* base) {
	// 0x267640: movss xmm0, dword ptr [0x003A55F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x267648: movss [0x0054FB50], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB50u, ctx.xmm[0].u32[0]);
	// 0x267650: ret
	return;
}

void sub_267660(X86Context& ctx, uint8_t* base) {
	// 0x267660: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x267668: movss [0x0054FBFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBFCu, ctx.xmm[0].u32[0]);
	// 0x267670: ret
	return;
}

void sub_267680(X86Context& ctx, uint8_t* base) {
	// 0x267680: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x267688: movss [0x0054FC1C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC1Cu, ctx.xmm[0].u32[0]);
	// 0x267690: ret
	return;
}

void sub_2676A0(X86Context& ctx, uint8_t* base) {
	// 0x2676A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2676A8: movss [0x0054FBE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBE8u, ctx.xmm[0].u32[0]);
	// 0x2676B0: ret
	return;
}

void sub_2676C0(X86Context& ctx, uint8_t* base) {
	// 0x2676C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2676C8: movss [0x0054FB9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FB9Cu, ctx.xmm[0].u32[0]);
	// 0x2676D0: ret
	return;
}

void sub_2676E0(X86Context& ctx, uint8_t* base) {
	// 0x2676E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2676E8: movss [0x0054FC00], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC00u, ctx.xmm[0].u32[0]);
	// 0x2676F0: ret
	return;
}

void sub_267700(X86Context& ctx, uint8_t* base) {
	// 0x267700: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x267708: movss [0x0054FBA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBA8u, ctx.xmm[0].u32[0]);
	// 0x267710: ret
	return;
}

void sub_267720(X86Context& ctx, uint8_t* base) {
	// 0x267720: movss xmm0, dword ptr [0x0054FC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC00u);
	// 0x267728: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x267730: movss [0x0054FC40], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC40u, ctx.xmm[0].u32[0]);
	// 0x267738: ret
	return;
}

void sub_267740(X86Context& ctx, uint8_t* base) {
	// 0x267740: movss xmm0, dword ptr [0x0054FBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBA8u);
	// 0x267748: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x267750: movss [0x0054FC2C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC2Cu, ctx.xmm[0].u32[0]);
	// 0x267758: ret
	return;
}

void sub_267760(X86Context& ctx, uint8_t* base) {
	// 0x267760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267768: movss [0x0054FC58], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC58u, ctx.xmm[0].u32[0]);
	// 0x267770: ret
	return;
}

void sub_267780(X86Context& ctx, uint8_t* base) {
	// 0x267780: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x267788: movss [0x0054FC48], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC48u, ctx.xmm[0].u32[0]);
	// 0x267790: ret
	return;
}

void sub_2677A0(X86Context& ctx, uint8_t* base) {
	// 0x2677A0: movss xmm0, dword ptr [0x0054FC48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC48u);
	// 0x2677A8: movss [0x0054FC54], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC54u, ctx.xmm[0].u32[0]);
	// 0x2677B0: ret
	return;
}

void sub_2677C0(X86Context& ctx, uint8_t* base) {
	// 0x2677C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2677C8: movss [0x0054FBA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBA4u, ctx.xmm[0].u32[0]);
	// 0x2677D0: ret
	return;
}

void sub_2677E0(X86Context& ctx, uint8_t* base) {
	// 0x2677E0: movss xmm0, dword ptr [0x0054FBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBA8u);
	// 0x2677E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2677F0: movss [0x0054FC4C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC4Cu, ctx.xmm[0].u32[0]);
	// 0x2677F8: ret
	return;
}

void sub_267800(X86Context& ctx, uint8_t* base) {
	// 0x267800: movss xmm0, dword ptr [0x0054FBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBA8u);
	// 0x267808: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x267810: movss [0x0054FBE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBE0u, ctx.xmm[0].u32[0]);
	// 0x267818: ret
	return;
}

void sub_267820(X86Context& ctx, uint8_t* base) {
	// 0x267820: movss xmm0, dword ptr [0x0054FBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBA8u);
	// 0x267828: subss xmm0, [0x0054FBE0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FBE0u);
	// 0x267830: movss [0x0054FBB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBB4u, ctx.xmm[0].u32[0]);
	// 0x267838: ret
	return;
}

void sub_267840(X86Context& ctx, uint8_t* base) {
	// 0x267840: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x267848: movss [0x0054FC18], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC18u, ctx.xmm[0].u32[0]);
	// 0x267850: ret
	return;
}

void sub_267860(X86Context& ctx, uint8_t* base) {
	// 0x267860: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x267868: movss [0x0054FBAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBACu, ctx.xmm[0].u32[0]);
	// 0x267870: ret
	return;
}

void sub_267880(X86Context& ctx, uint8_t* base) {
	// 0x267880: movss xmm0, dword ptr [0x00398B94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398B94u);
	// 0x267888: movss [0x0054FBC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBC4u, ctx.xmm[0].u32[0]);
	// 0x267890: ret
	return;
}

void sub_2678A0(X86Context& ctx, uint8_t* base) {
	// 0x2678A0: movss xmm0, dword ptr [0x0054FBA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBA4u);
	// 0x2678A8: movss [0x0054FC38], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC38u, ctx.xmm[0].u32[0]);
	// 0x2678B0: ret
	return;
}

void sub_2678C0(X86Context& ctx, uint8_t* base) {
	// 0x2678C0: movss xmm0, dword ptr [0x003B1750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2678C8: movss [0x0054FBE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBE4u, ctx.xmm[0].u32[0]);
	// 0x2678D0: ret
	return;
}

void sub_2678E0(X86Context& ctx, uint8_t* base) {
	// 0x2678E0: movss xmm0, dword ptr [0x003B2180]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2180u);
	// 0x2678E8: movss [0x0054FBC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBC0u, ctx.xmm[0].u32[0]);
	// 0x2678F0: ret
	return;
}

void sub_267900(X86Context& ctx, uint8_t* base) {
	// 0x267900: movss xmm0, dword ptr [0x0054FBC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBC0u);
	// 0x267908: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x267910: movss [0x0054FBC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBC8u, ctx.xmm[0].u32[0]);
	// 0x267918: ret
	return;
}

void sub_267920(X86Context& ctx, uint8_t* base) {
	// 0x267920: movss xmm0, dword ptr [0x0054FBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBC8u);
	// 0x267928: addss xmm0, [0x003A69B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69B4u);
	// 0x267930: movss [0x0054FBF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBF8u, ctx.xmm[0].u32[0]);
	// 0x267938: ret
	return;
}

void sub_267940(X86Context& ctx, uint8_t* base) {
	// 0x267940: movss xmm0, dword ptr [0x0054FBF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBF8u);
	// 0x267948: addss xmm0, [0x003B168C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B168Cu);
	// 0x267950: movss [0x0054FBF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBF0u, ctx.xmm[0].u32[0]);
	// 0x267958: ret
	return;
}

void sub_267960(X86Context& ctx, uint8_t* base) {
	// 0x267960: movss xmm0, dword ptr [0x0054FBF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBF0u);
	// 0x267968: addss xmm0, [0x003B1750]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1750u);
	// 0x267970: movss [0x0054FC3C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC3Cu, ctx.xmm[0].u32[0]);
	// 0x267978: ret
	return;
}

void sub_267980(X86Context& ctx, uint8_t* base) {
	// 0x267980: movss xmm0, dword ptr [0x0054FC3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC3Cu);
	// 0x267988: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x267990: movss [0x0054FC24], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC24u, ctx.xmm[0].u32[0]);
	// 0x267998: ret
	return;
}

void sub_2679A0(X86Context& ctx, uint8_t* base) {
	// 0x2679A0: movss xmm0, dword ptr [0x0054FC24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC24u);
	// 0x2679A8: movss [0x0054FBD4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBD4u, ctx.xmm[0].u32[0]);
	// 0x2679B0: ret
	return;
}

void sub_2679C0(X86Context& ctx, uint8_t* base) {
	// 0x2679C0: movss xmm0, dword ptr [0x003A69B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A69B4u);
	// 0x2679C8: movss [0x0054FC10], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC10u, ctx.xmm[0].u32[0]);
	// 0x2679D0: ret
	return;
}

void sub_2679E0(X86Context& ctx, uint8_t* base) {
	// 0x2679E0: movss xmm0, dword ptr [0x0054FC10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC10u);
	// 0x2679E8: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x2679F0: movss [0x0054FC20], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC20u, ctx.xmm[0].u32[0]);
	// 0x2679F8: ret
	return;
}

void sub_267A00(X86Context& ctx, uint8_t* base) {
	// 0x267A00: movss xmm0, dword ptr [0x0054FC20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC20u);
	// 0x267A08: addss xmm0, [0x003B1AB4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1AB4u);
	// 0x267A10: movss [0x0054FBD0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBD0u, ctx.xmm[0].u32[0]);
	// 0x267A18: ret
	return;
}

void sub_267A20(X86Context& ctx, uint8_t* base) {
	// 0x267A20: movss xmm0, dword ptr [0x0054FBD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBD0u);
	// 0x267A28: addss xmm0, [0x003A69B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69B4u);
	// 0x267A30: movss [0x0054FBA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBA0u, ctx.xmm[0].u32[0]);
	// 0x267A38: ret
	return;
}

void sub_267A40(X86Context& ctx, uint8_t* base) {
	// 0x267A40: movss xmm0, dword ptr [0x0054FBA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBA0u);
	// 0x267A48: movss [0x0054FBEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBECu, ctx.xmm[0].u32[0]);
	// 0x267A50: ret
	return;
}

void sub_267A60(X86Context& ctx, uint8_t* base) {
	// 0x267A60: movss xmm0, dword ptr [0x0054FC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC00u);
	// 0x267A68: movss [0x0054FC34], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC34u, ctx.xmm[0].u32[0]);
	// 0x267A70: ret
	return;
}

void sub_267A80(X86Context& ctx, uint8_t* base) {
	// 0x267A80: movss xmm0, dword ptr [0x0054FC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC00u);
	// 0x267A88: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x267A90: movss [0x0054FBD8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBD8u, ctx.xmm[0].u32[0]);
	// 0x267A98: ret
	return;
}

void sub_267AA0(X86Context& ctx, uint8_t* base) {
	// 0x267AA0: movss xmm0, dword ptr [0x0054FC34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC34u);
	// 0x267AA8: subss xmm0, [0x0054FBD8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FBD8u);
	// 0x267AB0: movss [0x0054FC50], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC50u, ctx.xmm[0].u32[0]);
	// 0x267AB8: ret
	return;
}

void sub_267AC0(X86Context& ctx, uint8_t* base) {
	// 0x267AC0: movss xmm0, dword ptr [0x0054FBD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBD8u);
	// 0x267AC8: addss xmm0, [0x003B16B8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B8u);
	// 0x267AD0: movss [0x0054FBB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBB0u, ctx.xmm[0].u32[0]);
	// 0x267AD8: ret
	return;
}

void sub_267AE0(X86Context& ctx, uint8_t* base) {
	// 0x267AE0: movss xmm0, dword ptr [0x0054FBD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBD8u);
	// 0x267AE8: movss [0x0054FBCC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBCCu, ctx.xmm[0].u32[0]);
	// 0x267AF0: ret
	return;
}

void sub_267B00(X86Context& ctx, uint8_t* base) {
	// 0x267B00: movss xmm0, dword ptr [0x0054FBB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBB0u);
	// 0x267B08: subss xmm0, [0x0054FBCC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FBCCu);
	// 0x267B10: movss [0x0054FC28], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC28u, ctx.xmm[0].u32[0]);
	// 0x267B18: ret
	return;
}

void sub_267B20(X86Context& ctx, uint8_t* base) {
	// 0x267B20: movss xmm0, dword ptr [0x0054FBB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBB0u);
	// 0x267B28: movss [0x0054FBBC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBBCu, ctx.xmm[0].u32[0]);
	// 0x267B30: ret
	return;
}

void sub_267B40(X86Context& ctx, uint8_t* base) {
	// 0x267B40: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x267B43: subss xmm0, [0x0054FBBC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FBBCu);
	// 0x267B4B: movss [0x0054FC08], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC08u, ctx.xmm[0].u32[0]);
	// 0x267B53: ret
	return;
}

void sub_267B60(X86Context& ctx, uint8_t* base) {
	// 0x267B60: movss xmm0, dword ptr [0x0054FBC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBC4u);
	// 0x267B68: addss xmm0, [0x003B16B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B4u);
	// 0x267B70: movss xmm1, dword ptr [0x00395BE0]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x395BE0u);
	// 0x267B78: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x267B7C: movss [0x0054FBF4], xmm1
	X86_MEM_WRITE_u32(base, 0x54FBF4u, ctx.xmm[1].u32[0]);
	// 0x267B84: ret
	return;
}

void sub_267B90(X86Context& ctx, uint8_t* base) {
	// 0x267B90: movss xmm0, dword ptr [0x0054FBC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBC4u);
	// 0x267B98: addss xmm0, [0x003B16B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B4u);
	// 0x267BA0: movss xmm1, dword ptr [0x003B2220]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B2220u);
	// 0x267BA8: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x267BAC: movss [0x0054FBDC], xmm1
	X86_MEM_WRITE_u32(base, 0x54FBDCu, ctx.xmm[1].u32[0]);
	// 0x267BB4: ret
	return;
}

void sub_267BC0(X86Context& ctx, uint8_t* base) {
	// 0x267BC0: movss xmm0, dword ptr [0x0054FBD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FBD4u);
	// 0x267BC8: addss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x267BD0: movss [0x0054FC44], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC44u, ctx.xmm[0].u32[0]);
	// 0x267BD8: ret
	return;
}

void sub_267BE0(X86Context& ctx, uint8_t* base) {
	// 0x267BE0: movss xmm0, dword ptr [0x003A69C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A69C4u);
	// 0x267BE8: movss [0x0054FC0C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC0Cu, ctx.xmm[0].u32[0]);
	// 0x267BF0: ret
	return;
}

void sub_267C00(X86Context& ctx, uint8_t* base) {
	// 0x267C00: movss xmm0, dword ptr [0x0054FC44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC44u);
	// 0x267C08: addss xmm0, [0x0054FC0C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x54FC0Cu);
	// 0x267C10: movss [0x0054FC30], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC30u, ctx.xmm[0].u32[0]);
	// 0x267C18: ret
	return;
}

void sub_267C20(X86Context& ctx, uint8_t* base) {
	// 0x267C20: movss xmm0, dword ptr [0x0054FC30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC30u);
	// 0x267C28: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x267C30: movss [0x0054FC04], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC04u, ctx.xmm[0].u32[0]);
	// 0x267C38: ret
	return;
}

void sub_267C40(X86Context& ctx, uint8_t* base) {
	// 0x267C40: movss xmm0, dword ptr [0x0054FC04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC04u);
	// 0x267C48: movss [0x0054FC14], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC14u, ctx.xmm[0].u32[0]);
	// 0x267C50: ret
	return;
}

void sub_267C60(X86Context& ctx, uint8_t* base) {
	// 0x267C60: movss xmm0, dword ptr [0x0054FC40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC40u);
	// 0x267C68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x267C70: movss [0x0054FBB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FBB8u, ctx.xmm[0].u32[0]);
	// 0x267C78: ret
	return;
}

void sub_267C80(X86Context& ctx, uint8_t* base) {
	// 0x267C80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x267C88: movss [0x0054FC78], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC78u, ctx.xmm[0].u32[0]);
	// 0x267C90: ret
	return;
}

void sub_267CA0(X86Context& ctx, uint8_t* base) {
	// 0x267CA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x267CA8: movss [0x0054FC84], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC84u, ctx.xmm[0].u32[0]);
	// 0x267CB0: ret
	return;
}

void sub_267CC0(X86Context& ctx, uint8_t* base) {
	// 0x267CC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x267CC8: movss [0x0054FC74], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC74u, ctx.xmm[0].u32[0]);
	// 0x267CD0: ret
	return;
}

void sub_267CE0(X86Context& ctx, uint8_t* base) {
	// 0x267CE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x267CE8: movss [0x0054FC5C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC5Cu, ctx.xmm[0].u32[0]);
	// 0x267CF0: ret
	return;
}

void sub_267D00(X86Context& ctx, uint8_t* base) {
	// 0x267D00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x267D08: movss [0x0054FC7C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC7Cu, ctx.xmm[0].u32[0]);
	// 0x267D10: ret
	return;
}

void sub_267D20(X86Context& ctx, uint8_t* base) {
	// 0x267D20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x267D28: movss [0x0054FC64], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC64u, ctx.xmm[0].u32[0]);
	// 0x267D30: ret
	return;
}

void sub_267D40(X86Context& ctx, uint8_t* base) {
	// 0x267D40: movss xmm0, dword ptr [0x0054FC7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC7Cu);
	// 0x267D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x267D50: movss [0x0054FC94], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC94u, ctx.xmm[0].u32[0]);
	// 0x267D58: ret
	return;
}

void sub_267D60(X86Context& ctx, uint8_t* base) {
	// 0x267D60: movss xmm0, dword ptr [0x0054FC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC64u);
	// 0x267D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x267D70: movss [0x0054FC88], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC88u, ctx.xmm[0].u32[0]);
	// 0x267D78: ret
	return;
}

void sub_267D80(X86Context& ctx, uint8_t* base) {
	// 0x267D80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267D88: movss [0x0054FCA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCA4u, ctx.xmm[0].u32[0]);
	// 0x267D90: ret
	return;
}

void sub_267DA0(X86Context& ctx, uint8_t* base) {
	// 0x267DA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x267DA8: movss [0x0054FC98], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC98u, ctx.xmm[0].u32[0]);
	// 0x267DB0: ret
	return;
}

void sub_267DC0(X86Context& ctx, uint8_t* base) {
	// 0x267DC0: movss xmm0, dword ptr [0x0054FC98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC98u);
	// 0x267DC8: movss [0x0054FCA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCA0u, ctx.xmm[0].u32[0]);
	// 0x267DD0: ret
	return;
}

void sub_267DE0(X86Context& ctx, uint8_t* base) {
	// 0x267DE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267DE8: movss [0x0054FC60], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC60u, ctx.xmm[0].u32[0]);
	// 0x267DF0: ret
	return;
}

void sub_267E00(X86Context& ctx, uint8_t* base) {
	// 0x267E00: movss xmm0, dword ptr [0x0054FC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC64u);
	// 0x267E08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x267E10: movss [0x0054FC9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC9Cu, ctx.xmm[0].u32[0]);
	// 0x267E18: ret
	return;
}

void sub_267E20(X86Context& ctx, uint8_t* base) {
	// 0x267E20: movss xmm0, dword ptr [0x0054FC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC64u);
	// 0x267E28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x267E30: movss [0x0054FC70], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC70u, ctx.xmm[0].u32[0]);
	// 0x267E38: ret
	return;
}

void sub_267E40(X86Context& ctx, uint8_t* base) {
	// 0x267E40: movss xmm0, dword ptr [0x0054FC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FC64u);
	// 0x267E48: subss xmm0, [0x0054FC70]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FC70u);
	// 0x267E50: movss [0x0054FC6C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC6Cu, ctx.xmm[0].u32[0]);
	// 0x267E58: ret
	return;
}

void sub_267E60(X86Context& ctx, uint8_t* base) {
	// 0x267E60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x267E68: movss [0x0054FC80], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC80u, ctx.xmm[0].u32[0]);
	// 0x267E70: ret
	return;
}

void sub_267E80(X86Context& ctx, uint8_t* base) {
	// 0x267E80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x267E88: movss [0x0054FC68], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC68u, ctx.xmm[0].u32[0]);
	// 0x267E90: ret
	return;
}

void sub_267EA0(X86Context& ctx, uint8_t* base) {
	// 0x267EA0: movss xmm0, dword ptr [0x00389A24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x389A24u);
	// 0x267EA8: movss [0x0054FC8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC8Cu, ctx.xmm[0].u32[0]);
	// 0x267EB0: ret
	return;
}

void sub_267EC0(X86Context& ctx, uint8_t* base) {
	// 0x267EC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x267EC8: movss [0x0054FC90], xmm0
	X86_MEM_WRITE_u32(base, 0x54FC90u, ctx.xmm[0].u32[0]);
	// 0x267ED0: ret
	return;
}

void sub_267EE0(X86Context& ctx, uint8_t* base) {
	// 0x267EE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x267EE8: movss [0x0054FCC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCC4u, ctx.xmm[0].u32[0]);
	// 0x267EF0: ret
	return;
}

void sub_267F00(X86Context& ctx, uint8_t* base) {
	// 0x267F00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x267F08: movss [0x0054FCD4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCD4u, ctx.xmm[0].u32[0]);
	// 0x267F10: ret
	return;
}

void sub_267F20(X86Context& ctx, uint8_t* base) {
	// 0x267F20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x267F28: movss [0x0054FCC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCC0u, ctx.xmm[0].u32[0]);
	// 0x267F30: ret
	return;
}

void sub_267F40(X86Context& ctx, uint8_t* base) {
	// 0x267F40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x267F48: movss [0x0054FCA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCA8u, ctx.xmm[0].u32[0]);
	// 0x267F50: ret
	return;
}

void sub_267F60(X86Context& ctx, uint8_t* base) {
	// 0x267F60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x267F68: movss [0x0054FCC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCC8u, ctx.xmm[0].u32[0]);
	// 0x267F70: ret
	return;
}

void sub_267F80(X86Context& ctx, uint8_t* base) {
	// 0x267F80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x267F88: movss [0x0054FCB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCB0u, ctx.xmm[0].u32[0]);
	// 0x267F90: ret
	return;
}

void sub_267FA0(X86Context& ctx, uint8_t* base) {
	// 0x267FA0: movss xmm0, dword ptr [0x0054FCC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCC8u);
	// 0x267FA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x267FB0: movss [0x0054FCE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCE0u, ctx.xmm[0].u32[0]);
	// 0x267FB8: ret
	return;
}

void sub_267FC0(X86Context& ctx, uint8_t* base) {
	// 0x267FC0: movss xmm0, dword ptr [0x0054FCB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCB0u);
	// 0x267FC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x267FD0: movss [0x0054FCD8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCD8u, ctx.xmm[0].u32[0]);
	// 0x267FD8: ret
	return;
}

void sub_267FE0(X86Context& ctx, uint8_t* base) {
	// 0x267FE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x267FE8: movss [0x0054FCF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCF0u, ctx.xmm[0].u32[0]);
	// 0x267FF0: ret
	return;
}

void sub_268000(X86Context& ctx, uint8_t* base) {
	// 0x268000: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268008: movss [0x0054FCE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCE4u, ctx.xmm[0].u32[0]);
	// 0x268010: ret
	return;
}

void sub_268020(X86Context& ctx, uint8_t* base) {
	// 0x268020: movss xmm0, dword ptr [0x0054FCE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCE4u);
	// 0x268028: movss [0x0054FCEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCECu, ctx.xmm[0].u32[0]);
	// 0x268030: ret
	return;
}

void sub_268040(X86Context& ctx, uint8_t* base) {
	// 0x268040: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268048: movss [0x0054FCAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCACu, ctx.xmm[0].u32[0]);
	// 0x268050: ret
	return;
}

void sub_268060(X86Context& ctx, uint8_t* base) {
	// 0x268060: movss xmm0, dword ptr [0x0054FCB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCB0u);
	// 0x268068: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x268070: movss [0x0054FCE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCE8u, ctx.xmm[0].u32[0]);
	// 0x268078: ret
	return;
}

void sub_268080(X86Context& ctx, uint8_t* base) {
	// 0x268080: movss xmm0, dword ptr [0x0054FCB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCB0u);
	// 0x268088: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x268090: movss [0x0054FCBC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCBCu, ctx.xmm[0].u32[0]);
	// 0x268098: ret
	return;
}

void sub_2680A0(X86Context& ctx, uint8_t* base) {
	// 0x2680A0: movss xmm0, dword ptr [0x0054FCB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCB0u);
	// 0x2680A8: subss xmm0, [0x0054FCBC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FCBCu);
	// 0x2680B0: movss [0x0054FCB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCB8u, ctx.xmm[0].u32[0]);
	// 0x2680B8: ret
	return;
}

void sub_2680C0(X86Context& ctx, uint8_t* base) {
	// 0x2680C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2680C8: movss [0x0054FCD0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCD0u, ctx.xmm[0].u32[0]);
	// 0x2680D0: ret
	return;
}

void sub_2680E0(X86Context& ctx, uint8_t* base) {
	// 0x2680E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2680E8: movss [0x0054FCB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCB4u, ctx.xmm[0].u32[0]);
	// 0x2680F0: ret
	return;
}

void sub_268100(X86Context& ctx, uint8_t* base) {
	// 0x268100: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268108: movss [0x0054FCCC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCCCu, ctx.xmm[0].u32[0]);
	// 0x268110: ret
	return;
}

void sub_268120(X86Context& ctx, uint8_t* base) {
	// 0x268120: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268128: movss [0x0054FCDC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCDCu, ctx.xmm[0].u32[0]);
	// 0x268130: ret
	return;
}

void sub_268140(X86Context& ctx, uint8_t* base) {
	// 0x268140: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x268148: movss [0x0054FD48], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD48u, ctx.xmm[0].u32[0]);
	// 0x268150: ret
	return;
}

void sub_268160(X86Context& ctx, uint8_t* base) {
	// 0x268160: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x268168: movss [0x0054FD54], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD54u, ctx.xmm[0].u32[0]);
	// 0x268170: ret
	return;
}

void sub_268180(X86Context& ctx, uint8_t* base) {
	// 0x268180: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x268188: movss [0x0054FD44], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD44u, ctx.xmm[0].u32[0]);
	// 0x268190: ret
	return;
}

void sub_2681A0(X86Context& ctx, uint8_t* base) {
	// 0x2681A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2681A8: movss [0x0054FCF4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCF4u, ctx.xmm[0].u32[0]);
	// 0x2681B0: ret
	return;
}

void sub_2681C0(X86Context& ctx, uint8_t* base) {
	// 0x2681C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2681C8: movss [0x0054FD4C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD4Cu, ctx.xmm[0].u32[0]);
	// 0x2681D0: ret
	return;
}

void sub_2681E0(X86Context& ctx, uint8_t* base) {
	// 0x2681E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2681E8: movss [0x0054FCFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCFCu, ctx.xmm[0].u32[0]);
	// 0x2681F0: ret
	return;
}

void sub_268200(X86Context& ctx, uint8_t* base) {
	// 0x268200: movss xmm0, dword ptr [0x0054FD4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD4Cu);
	// 0x268208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x268210: movss [0x0054FD5C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD5Cu, ctx.xmm[0].u32[0]);
	// 0x268218: ret
	return;
}

void sub_268220(X86Context& ctx, uint8_t* base) {
	// 0x268220: movss xmm0, dword ptr [0x0054FCFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCFCu);
	// 0x268228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x268230: movss [0x0054FD58], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD58u, ctx.xmm[0].u32[0]);
	// 0x268238: ret
	return;
}

void sub_268240(X86Context& ctx, uint8_t* base) {
	// 0x268240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268248: movss [0x0054FD6C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD6Cu, ctx.xmm[0].u32[0]);
	// 0x268250: ret
	return;
}

void sub_268260(X86Context& ctx, uint8_t* base) {
	// 0x268260: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268268: movss [0x0054FD60], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD60u, ctx.xmm[0].u32[0]);
	// 0x268270: ret
	return;
}

void sub_268280(X86Context& ctx, uint8_t* base) {
	// 0x268280: movss xmm0, dword ptr [0x0054FD60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD60u);
	// 0x268288: movss [0x0054FD68], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD68u, ctx.xmm[0].u32[0]);
	// 0x268290: ret
	return;
}

void sub_2682A0(X86Context& ctx, uint8_t* base) {
	// 0x2682A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2682A8: movss [0x0054FCF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FCF8u, ctx.xmm[0].u32[0]);
	// 0x2682B0: ret
	return;
}

void sub_2682C0(X86Context& ctx, uint8_t* base) {
	// 0x2682C0: movss xmm0, dword ptr [0x0054FCFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCFCu);
	// 0x2682C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2682D0: movss [0x0054FD64], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD64u, ctx.xmm[0].u32[0]);
	// 0x2682D8: ret
	return;
}

void sub_2682E0(X86Context& ctx, uint8_t* base) {
	// 0x2682E0: movss xmm0, dword ptr [0x0054FCFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCFCu);
	// 0x2682E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2682F0: movss [0x0054FD40], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD40u, ctx.xmm[0].u32[0]);
	// 0x2682F8: ret
	return;
}

void sub_268300(X86Context& ctx, uint8_t* base) {
	// 0x268300: movss xmm0, dword ptr [0x0054FCFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FCFCu);
	// 0x268308: subss xmm0, [0x0054FD40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FD40u);
	// 0x268310: movss [0x0054FD04], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD04u, ctx.xmm[0].u32[0]);
	// 0x268318: ret
	return;
}

void sub_268320(X86Context& ctx, uint8_t* base) {
	// 0x268320: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x268328: movss [0x0054FD50], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD50u, ctx.xmm[0].u32[0]);
	// 0x268330: ret
	return;
}

void sub_268340(X86Context& ctx, uint8_t* base) {
	// 0x268340: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x268348: movss [0x0054FD00], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD00u, ctx.xmm[0].u32[0]);
	// 0x268350: ret
	return;
}

void sub_268360(X86Context& ctx, uint8_t* base) {
	// 0x268360: movss xmm0, dword ptr [0x00389CB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x389CB4u);
	// 0x268368: movss [0x0054FD08], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD08u, ctx.xmm[0].u32[0]);
	// 0x268370: ret
	return;
}

void sub_268380(X86Context& ctx, uint8_t* base) {
	// 0x268380: mov eax, [0x003FF7D0]
	ctx.eax = X86_MEM_READ_u32(base, 0x3FF7D0u);
	// 0x268385: mov ecx, [0x003FF7D4]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3FF7D4u);
	// 0x26838B: mov edx, [0x003FF7D8]
	ctx.edx = X86_MEM_READ_u32(base, 0x3FF7D8u);
	// 0x268391: mov [0x0054FD10], eax
	X86_MEM_WRITE_u32(base, 0x54FD10u, ctx.eax);
	// 0x268396: mov eax, [0x003FF7DC]
	ctx.eax = X86_MEM_READ_u32(base, 0x3FF7DCu);
	// 0x26839B: mov [0x0054FD14], ecx
	X86_MEM_WRITE_u32(base, 0x54FD14u, ctx.ecx);
	// 0x2683A1: mov ecx, [0x003FF7E0]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3FF7E0u);
	// 0x2683A7: mov [0x0054FD18], edx
	X86_MEM_WRITE_u32(base, 0x54FD18u, ctx.edx);
	// 0x2683AD: mov edx, [0x003FF7E4]
	ctx.edx = X86_MEM_READ_u32(base, 0x3FF7E4u);
	// 0x2683B3: mov [0x0054FD1C], eax
	X86_MEM_WRITE_u32(base, 0x54FD1Cu, ctx.eax);
	// 0x2683B8: mov eax, [0x003FF7E8]
	ctx.eax = X86_MEM_READ_u32(base, 0x3FF7E8u);
	// 0x2683BD: mov [0x0054FD20], ecx
	X86_MEM_WRITE_u32(base, 0x54FD20u, ctx.ecx);
	// 0x2683C3: mov ecx, [0x003FF7EC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3FF7ECu);
	// 0x2683C9: mov [0x0054FD24], edx
	X86_MEM_WRITE_u32(base, 0x54FD24u, ctx.edx);
	// 0x2683CF: mov edx, [0x003FF7F0]
	ctx.edx = X86_MEM_READ_u32(base, 0x3FF7F0u);
	// 0x2683D5: mov [0x0054FD28], eax
	X86_MEM_WRITE_u32(base, 0x54FD28u, ctx.eax);
	// 0x2683DA: mov eax, [0x003FF7F4]
	ctx.eax = X86_MEM_READ_u32(base, 0x3FF7F4u);
	// 0x2683DF: mov [0x0054FD2C], ecx
	X86_MEM_WRITE_u32(base, 0x54FD2Cu, ctx.ecx);
	// 0x2683E5: mov ecx, [0x003FF7F8]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3FF7F8u);
	// 0x2683EB: mov [0x0054FD30], edx
	X86_MEM_WRITE_u32(base, 0x54FD30u, ctx.edx);
	// 0x2683F1: mov edx, [0x003FF7FC]
	ctx.edx = X86_MEM_READ_u32(base, 0x3FF7FCu);
	// 0x2683F7: mov [0x0054FD34], eax
	X86_MEM_WRITE_u32(base, 0x54FD34u, ctx.eax);
	// 0x2683FC: mov [0x0054FD38], ecx
	X86_MEM_WRITE_u32(base, 0x54FD38u, ctx.ecx);
	// 0x268402: mov [0x0054FD3C], edx
	X86_MEM_WRITE_u32(base, 0x54FD3Cu, ctx.edx);
	// 0x268408: ret
	return;
}

void sub_268410(X86Context& ctx, uint8_t* base) {
	// 0x268410: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x268418: movss [0x0054FD8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD8Cu, ctx.xmm[0].u32[0]);
	// 0x268420: ret
	return;
}

void sub_268430(X86Context& ctx, uint8_t* base) {
	// 0x268430: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x268438: movss [0x0054FD98], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD98u, ctx.xmm[0].u32[0]);
	// 0x268440: ret
	return;
}

void sub_268450(X86Context& ctx, uint8_t* base) {
	// 0x268450: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x268458: movss [0x0054FD88], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD88u, ctx.xmm[0].u32[0]);
	// 0x268460: ret
	return;
}

void sub_268470(X86Context& ctx, uint8_t* base) {
	// 0x268470: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x268478: movss [0x0054FD70], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD70u, ctx.xmm[0].u32[0]);
	// 0x268480: ret
	return;
}

void sub_268490(X86Context& ctx, uint8_t* base) {
	// 0x268490: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x268498: movss [0x0054FD90], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD90u, ctx.xmm[0].u32[0]);
	// 0x2684A0: ret
	return;
}

void sub_2684B0(X86Context& ctx, uint8_t* base) {
	// 0x2684B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2684B8: movss [0x0054FD78], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD78u, ctx.xmm[0].u32[0]);
	// 0x2684C0: ret
	return;
}

void sub_2684D0(X86Context& ctx, uint8_t* base) {
	// 0x2684D0: movss xmm0, dword ptr [0x0054FD90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD90u);
	// 0x2684D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2684E0: movss [0x0054FDA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDA0u, ctx.xmm[0].u32[0]);
	// 0x2684E8: ret
	return;
}

void sub_2684F0(X86Context& ctx, uint8_t* base) {
	// 0x2684F0: movss xmm0, dword ptr [0x0054FD78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD78u);
	// 0x2684F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x268500: movss [0x0054FD9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD9Cu, ctx.xmm[0].u32[0]);
	// 0x268508: ret
	return;
}

void sub_268510(X86Context& ctx, uint8_t* base) {
	// 0x268510: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268518: movss [0x0054FDB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDB0u, ctx.xmm[0].u32[0]);
	// 0x268520: ret
	return;
}

void sub_268530(X86Context& ctx, uint8_t* base) {
	// 0x268530: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268538: movss [0x0054FDA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDA4u, ctx.xmm[0].u32[0]);
	// 0x268540: ret
	return;
}

void sub_268550(X86Context& ctx, uint8_t* base) {
	// 0x268550: movss xmm0, dword ptr [0x0054FDA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDA4u);
	// 0x268558: movss [0x0054FDAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDACu, ctx.xmm[0].u32[0]);
	// 0x268560: ret
	return;
}

void sub_268570(X86Context& ctx, uint8_t* base) {
	// 0x268570: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268578: movss [0x0054FD74], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD74u, ctx.xmm[0].u32[0]);
	// 0x268580: ret
	return;
}

void sub_268590(X86Context& ctx, uint8_t* base) {
	// 0x268590: movss xmm0, dword ptr [0x0054FD78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD78u);
	// 0x268598: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2685A0: movss [0x0054FDA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDA8u, ctx.xmm[0].u32[0]);
	// 0x2685A8: ret
	return;
}

void sub_2685B0(X86Context& ctx, uint8_t* base) {
	// 0x2685B0: movss xmm0, dword ptr [0x0054FD78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD78u);
	// 0x2685B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2685C0: movss [0x0054FD84], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD84u, ctx.xmm[0].u32[0]);
	// 0x2685C8: ret
	return;
}

void sub_2685D0(X86Context& ctx, uint8_t* base) {
	// 0x2685D0: movss xmm0, dword ptr [0x0054FD78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FD78u);
	// 0x2685D8: subss xmm0, [0x0054FD84]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FD84u);
	// 0x2685E0: movss [0x0054FD80], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD80u, ctx.xmm[0].u32[0]);
	// 0x2685E8: ret
	return;
}

void sub_2685F0(X86Context& ctx, uint8_t* base) {
	// 0x2685F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2685F8: movss [0x0054FD94], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD94u, ctx.xmm[0].u32[0]);
	// 0x268600: ret
	return;
}

void sub_268610(X86Context& ctx, uint8_t* base) {
	// 0x268610: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x268618: movss [0x0054FD7C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FD7Cu, ctx.xmm[0].u32[0]);
	// 0x268620: ret
	return;
}

void sub_268630(X86Context& ctx, uint8_t* base) {
	// 0x268630: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x268638: movss [0x0054FDD4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDD4u, ctx.xmm[0].u32[0]);
	// 0x268640: ret
	return;
}

void sub_268650(X86Context& ctx, uint8_t* base) {
	// 0x268650: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x268658: movss [0x0054FDE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDE0u, ctx.xmm[0].u32[0]);
	// 0x268660: ret
	return;
}

void sub_268670(X86Context& ctx, uint8_t* base) {
	// 0x268670: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x268678: movss [0x0054FDD0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDD0u, ctx.xmm[0].u32[0]);
	// 0x268680: ret
	return;
}

void sub_268690(X86Context& ctx, uint8_t* base) {
	// 0x268690: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x268698: movss [0x0054FDB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDB4u, ctx.xmm[0].u32[0]);
	// 0x2686A0: ret
	return;
}

void sub_2686B0(X86Context& ctx, uint8_t* base) {
	// 0x2686B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2686B8: movss [0x0054FDD8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDD8u, ctx.xmm[0].u32[0]);
	// 0x2686C0: ret
	return;
}

void sub_2686D0(X86Context& ctx, uint8_t* base) {
	// 0x2686D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2686D8: movss [0x0054FDBC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDBCu, ctx.xmm[0].u32[0]);
	// 0x2686E0: ret
	return;
}

void sub_2686F0(X86Context& ctx, uint8_t* base) {
	// 0x2686F0: movss xmm0, dword ptr [0x0054FDD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDD8u);
	// 0x2686F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x268700: movss [0x0054FDE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDE8u, ctx.xmm[0].u32[0]);
	// 0x268708: ret
	return;
}

void sub_268710(X86Context& ctx, uint8_t* base) {
	// 0x268710: movss xmm0, dword ptr [0x0054FDBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDBCu);
	// 0x268718: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x268720: movss [0x0054FDE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDE4u, ctx.xmm[0].u32[0]);
	// 0x268728: ret
	return;
}

void sub_268730(X86Context& ctx, uint8_t* base) {
	// 0x268730: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268738: movss [0x0054FDF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDF8u, ctx.xmm[0].u32[0]);
	// 0x268740: ret
	return;
}

void sub_268750(X86Context& ctx, uint8_t* base) {
	// 0x268750: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268758: movss [0x0054FDEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDECu, ctx.xmm[0].u32[0]);
	// 0x268760: ret
	return;
}

void sub_268770(X86Context& ctx, uint8_t* base) {
	// 0x268770: movss xmm0, dword ptr [0x0054FDEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDECu);
	// 0x268778: movss [0x0054FDF4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDF4u, ctx.xmm[0].u32[0]);
	// 0x268780: ret
	return;
}

void sub_268790(X86Context& ctx, uint8_t* base) {
	// 0x268790: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268798: movss [0x0054FDB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDB8u, ctx.xmm[0].u32[0]);
	// 0x2687A0: ret
	return;
}

void sub_2687B0(X86Context& ctx, uint8_t* base) {
	// 0x2687B0: movss xmm0, dword ptr [0x0054FDBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDBCu);
	// 0x2687B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2687C0: movss [0x0054FDF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDF0u, ctx.xmm[0].u32[0]);
	// 0x2687C8: ret
	return;
}

void sub_2687D0(X86Context& ctx, uint8_t* base) {
	// 0x2687D0: movss xmm0, dword ptr [0x0054FDBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDBCu);
	// 0x2687D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2687E0: movss [0x0054FDCC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDCCu, ctx.xmm[0].u32[0]);
	// 0x2687E8: ret
	return;
}

void sub_2687F0(X86Context& ctx, uint8_t* base) {
	// 0x2687F0: movss xmm0, dword ptr [0x0054FDBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FDBCu);
	// 0x2687F8: subss xmm0, [0x0054FDCC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FDCCu);
	// 0x268800: movss [0x0054FDC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDC4u, ctx.xmm[0].u32[0]);
	// 0x268808: ret
	return;
}

void sub_268810(X86Context& ctx, uint8_t* base) {
	// 0x268810: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x268818: movss [0x0054FDDC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDDCu, ctx.xmm[0].u32[0]);
	// 0x268820: ret
	return;
}

void sub_268830(X86Context& ctx, uint8_t* base) {
	// 0x268830: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x268838: movss [0x0054FDC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDC0u, ctx.xmm[0].u32[0]);
	// 0x268840: ret
	return;
}

void sub_268850(X86Context& ctx, uint8_t* base) {
	// 0x268850: movss xmm0, dword ptr [0x00389CB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x389CB4u);
	// 0x268858: movss [0x0054FDC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDC8u, ctx.xmm[0].u32[0]);
	// 0x268860: ret
	return;
}

void sub_268870(X86Context& ctx, uint8_t* base) {
	// 0x268870: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x268878: movss [0x0054FE00], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE00u, ctx.xmm[0].u32[0]);
	// 0x268880: ret
	return;
}

void sub_268890(X86Context& ctx, uint8_t* base) {
	// 0x268890: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x268898: movss [0x0054FE04], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE04u, ctx.xmm[0].u32[0]);
	// 0x2688A0: ret
	return;
}

void sub_2688B0(X86Context& ctx, uint8_t* base) {
	// 0x2688B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2688B8: movss [0x0054FDFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FDFCu, ctx.xmm[0].u32[0]);
	// 0x2688C0: ret
	return;
}

void sub_2688D0(X86Context& ctx, uint8_t* base) {
	// 0x2688D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2688D8: movss [0x0054FE18], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE18u, ctx.xmm[0].u32[0]);
	// 0x2688E0: ret
	return;
}

void sub_2688F0(X86Context& ctx, uint8_t* base) {
	// 0x2688F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2688F8: movss [0x0054FE1C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE1Cu, ctx.xmm[0].u32[0]);
	// 0x268900: ret
	return;
}

void sub_268910(X86Context& ctx, uint8_t* base) {
	// 0x268910: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x268918: movss [0x0054FE14], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE14u, ctx.xmm[0].u32[0]);
	// 0x268920: ret
	return;
}

void sub_268930(X86Context& ctx, uint8_t* base) {
	// 0x268930: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x268938: movss [0x0054FE08], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE08u, ctx.xmm[0].u32[0]);
	// 0x268940: ret
	return;
}

