#include "x86_recomp_shared.h"

void sub_27F6B0(X86Context& ctx, uint8_t* base) {
	// 0x27F6B0: movss xmm0, dword ptr [0x0056A278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A278u);
	// 0x27F6B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27F6C0: movss [0x0056A2A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2A8u, ctx.xmm[0].u32[0]);
	// 0x27F6C8: ret
	return;
}

void sub_27F6D0(X86Context& ctx, uint8_t* base) {
	// 0x27F6D0: movss xmm0, dword ptr [0x0056A278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A278u);
	// 0x27F6D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27F6E0: movss [0x0056A284], xmm0
	X86_MEM_WRITE_u32(base, 0x56A284u, ctx.xmm[0].u32[0]);
	// 0x27F6E8: ret
	return;
}

void sub_27F6F0(X86Context& ctx, uint8_t* base) {
	// 0x27F6F0: movss xmm0, dword ptr [0x0056A278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A278u);
	// 0x27F6F8: subss xmm0, [0x0056A284]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A284u);
	// 0x27F700: movss [0x0056A280], xmm0
	X86_MEM_WRITE_u32(base, 0x56A280u, ctx.xmm[0].u32[0]);
	// 0x27F708: ret
	return;
}

void sub_27F710(X86Context& ctx, uint8_t* base) {
	// 0x27F710: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27F718: movss [0x0056A294], xmm0
	X86_MEM_WRITE_u32(base, 0x56A294u, ctx.xmm[0].u32[0]);
	// 0x27F720: ret
	return;
}

void sub_27F730(X86Context& ctx, uint8_t* base) {
	// 0x27F730: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27F738: movss [0x0056A27C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A27Cu, ctx.xmm[0].u32[0]);
	// 0x27F740: ret
	return;
}

void sub_27F750(X86Context& ctx, uint8_t* base) {
	// 0x27F750: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27F758: movss [0x0056A308], xmm0
	X86_MEM_WRITE_u32(base, 0x56A308u, ctx.xmm[0].u32[0]);
	// 0x27F760: ret
	return;
}

void sub_27F770(X86Context& ctx, uint8_t* base) {
	// 0x27F770: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27F778: movss [0x0056A324], xmm0
	X86_MEM_WRITE_u32(base, 0x56A324u, ctx.xmm[0].u32[0]);
	// 0x27F780: ret
	return;
}

void sub_27F790(X86Context& ctx, uint8_t* base) {
	// 0x27F790: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27F798: movss [0x0056A2FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2FCu, ctx.xmm[0].u32[0]);
	// 0x27F7A0: ret
	return;
}

void sub_27F7B0(X86Context& ctx, uint8_t* base) {
	// 0x27F7B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27F7B8: movss [0x0056A2B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2B4u, ctx.xmm[0].u32[0]);
	// 0x27F7C0: ret
	return;
}

void sub_27F7D0(X86Context& ctx, uint8_t* base) {
	// 0x27F7D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27F7D8: movss [0x0056A30C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A30Cu, ctx.xmm[0].u32[0]);
	// 0x27F7E0: ret
	return;
}

void sub_27F7F0(X86Context& ctx, uint8_t* base) {
	// 0x27F7F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27F7F8: movss [0x0056A2D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2D0u, ctx.xmm[0].u32[0]);
	// 0x27F800: ret
	return;
}

void sub_27F810(X86Context& ctx, uint8_t* base) {
	// 0x27F810: movss xmm0, dword ptr [0x0056A30C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A30Cu);
	// 0x27F818: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27F820: movss [0x0056A344], xmm0
	X86_MEM_WRITE_u32(base, 0x56A344u, ctx.xmm[0].u32[0]);
	// 0x27F828: ret
	return;
}

void sub_27F830(X86Context& ctx, uint8_t* base) {
	// 0x27F830: movss xmm0, dword ptr [0x0056A2D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2D0u);
	// 0x27F838: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27F840: movss [0x0056A32C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A32Cu, ctx.xmm[0].u32[0]);
	// 0x27F848: ret
	return;
}

void sub_27F850(X86Context& ctx, uint8_t* base) {
	// 0x27F850: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27F858: movss [0x0056A35C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A35Cu, ctx.xmm[0].u32[0]);
	// 0x27F860: ret
	return;
}

void sub_27F870(X86Context& ctx, uint8_t* base) {
	// 0x27F870: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27F878: movss [0x0056A348], xmm0
	X86_MEM_WRITE_u32(base, 0x56A348u, ctx.xmm[0].u32[0]);
	// 0x27F880: ret
	return;
}

void sub_27F890(X86Context& ctx, uint8_t* base) {
	// 0x27F890: movss xmm0, dword ptr [0x0056A348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A348u);
	// 0x27F898: movss [0x0056A358], xmm0
	X86_MEM_WRITE_u32(base, 0x56A358u, ctx.xmm[0].u32[0]);
	// 0x27F8A0: ret
	return;
}

void sub_27F8B0(X86Context& ctx, uint8_t* base) {
	// 0x27F8B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27F8B8: movss [0x0056A2BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2BCu, ctx.xmm[0].u32[0]);
	// 0x27F8C0: ret
	return;
}

void sub_27F8D0(X86Context& ctx, uint8_t* base) {
	// 0x27F8D0: movss xmm0, dword ptr [0x0056A2D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2D0u);
	// 0x27F8D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27F8E0: movss [0x0056A350], xmm0
	X86_MEM_WRITE_u32(base, 0x56A350u, ctx.xmm[0].u32[0]);
	// 0x27F8E8: ret
	return;
}

void sub_27F8F0(X86Context& ctx, uint8_t* base) {
	// 0x27F8F0: movss xmm0, dword ptr [0x0056A2D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2D0u);
	// 0x27F8F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27F900: movss [0x0056A2F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2F8u, ctx.xmm[0].u32[0]);
	// 0x27F908: ret
	return;
}

void sub_27F910(X86Context& ctx, uint8_t* base) {
	// 0x27F910: movss xmm0, dword ptr [0x0056A2D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2D0u);
	// 0x27F918: subss xmm0, [0x0056A2F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A2F8u);
	// 0x27F920: movss [0x0056A2D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2D8u, ctx.xmm[0].u32[0]);
	// 0x27F928: ret
	return;
}

void sub_27F930(X86Context& ctx, uint8_t* base) {
	// 0x27F930: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27F938: movss [0x0056A320], xmm0
	X86_MEM_WRITE_u32(base, 0x56A320u, ctx.xmm[0].u32[0]);
	// 0x27F940: ret
	return;
}

void sub_27F950(X86Context& ctx, uint8_t* base) {
	// 0x27F950: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27F958: movss [0x0056A2D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2D4u, ctx.xmm[0].u32[0]);
	// 0x27F960: ret
	return;
}

void sub_27F970(X86Context& ctx, uint8_t* base) {
	// 0x27F970: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27F978: movss [0x0056A2E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2E4u, ctx.xmm[0].u32[0]);
	// 0x27F980: ret
	return;
}

void sub_27F990(X86Context& ctx, uint8_t* base) {
	// 0x27F990: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27F998: movss [0x0056A338], xmm0
	X86_MEM_WRITE_u32(base, 0x56A338u, ctx.xmm[0].u32[0]);
	// 0x27F9A0: ret
	return;
}

void sub_27F9B0(X86Context& ctx, uint8_t* base) {
	// 0x27F9B0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27F9B8: movss [0x0056A31C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A31Cu, ctx.xmm[0].u32[0]);
	// 0x27F9C0: ret
	return;
}

void sub_27F9D0(X86Context& ctx, uint8_t* base) {
	// 0x27F9D0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27F9D8: movss [0x0056A2CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2CCu, ctx.xmm[0].u32[0]);
	// 0x27F9E0: ret
	return;
}

void sub_27F9F0(X86Context& ctx, uint8_t* base) {
	// 0x27F9F0: movss xmm0, dword ptr [0x0056A2E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2E4u);
	// 0x27F9F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27FA00: movss [0x0056A2C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2C0u, ctx.xmm[0].u32[0]);
	// 0x27FA08: ret
	return;
}

void sub_27FA10(X86Context& ctx, uint8_t* base) {
	// 0x27FA10: movss xmm0, dword ptr [0x0056A338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A338u);
	// 0x27FA18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27FA20: movss [0x0056A304], xmm0
	X86_MEM_WRITE_u32(base, 0x56A304u, ctx.xmm[0].u32[0]);
	// 0x27FA28: ret
	return;
}

void sub_27FA30(X86Context& ctx, uint8_t* base) {
	// 0x27FA30: movss xmm0, dword ptr [0x0056A2C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2C0u);
	// 0x27FA38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27FA40: movss [0x0056A314], xmm0
	X86_MEM_WRITE_u32(base, 0x56A314u, ctx.xmm[0].u32[0]);
	// 0x27FA48: ret
	return;
}

void sub_27FA50(X86Context& ctx, uint8_t* base) {
	// 0x27FA50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27FA58: movss [0x0056A2B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2B8u, ctx.xmm[0].u32[0]);
	// 0x27FA60: ret
	return;
}

void sub_27FA70(X86Context& ctx, uint8_t* base) {
	// 0x27FA70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27FA78: movss [0x0056A2E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2E8u, ctx.xmm[0].u32[0]);
	// 0x27FA80: ret
	return;
}

void sub_27FA90(X86Context& ctx, uint8_t* base) {
	// 0x27FA90: movss xmm0, dword ptr [0x0056A2E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2E4u);
	// 0x27FA98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27FAA0: movss [0x0056A2F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2F4u, ctx.xmm[0].u32[0]);
	// 0x27FAA8: ret
	return;
}

void sub_27FAB0(X86Context& ctx, uint8_t* base) {
	// 0x27FAB0: movss xmm0, dword ptr [0x0056A338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A338u);
	// 0x27FAB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27FAC0: movss [0x0056A33C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A33Cu, ctx.xmm[0].u32[0]);
	// 0x27FAC8: ret
	return;
}

void sub_27FAD0(X86Context& ctx, uint8_t* base) {
	// 0x27FAD0: movss xmm0, dword ptr [0x0056A2F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2F4u);
	// 0x27FAD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27FAE0: movss [0x0056A328], xmm0
	X86_MEM_WRITE_u32(base, 0x56A328u, ctx.xmm[0].u32[0]);
	// 0x27FAE8: ret
	return;
}

void sub_27FAF0(X86Context& ctx, uint8_t* base) {
	// 0x27FAF0: movss xmm0, dword ptr [0x0056A33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A33Cu);
	// 0x27FAF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27FB00: movss [0x0056A34C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A34Cu, ctx.xmm[0].u32[0]);
	// 0x27FB08: ret
	return;
}

void sub_27FB10(X86Context& ctx, uint8_t* base) {
	// 0x27FB10: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27FB18: movss [0x0056A2C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2C4u, ctx.xmm[0].u32[0]);
	// 0x27FB20: ret
	return;
}

void sub_27FB30(X86Context& ctx, uint8_t* base) {
	// 0x27FB30: movss xmm0, dword ptr [0x0056A2E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2E4u);
	// 0x27FB38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27FB40: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27FB48: movss [0x0056A334], xmm0
	X86_MEM_WRITE_u32(base, 0x56A334u, ctx.xmm[0].u32[0]);
	// 0x27FB50: ret
	return;
}

void sub_27FB60(X86Context& ctx, uint8_t* base) {
	// 0x27FB60: movss xmm0, dword ptr [0x0056A338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A338u);
	// 0x27FB68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27FB70: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27FB78: movss [0x0056A2DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2DCu, ctx.xmm[0].u32[0]);
	// 0x27FB80: ret
	return;
}

void sub_27FB90(X86Context& ctx, uint8_t* base) {
	// 0x27FB90: movss xmm0, dword ptr [0x0056A2E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2E4u);
	// 0x27FB98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27FBA0: movss [0x0056A2E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2E0u, ctx.xmm[0].u32[0]);
	// 0x27FBA8: ret
	return;
}

void sub_27FBB0(X86Context& ctx, uint8_t* base) {
	// 0x27FBB0: movss xmm0, dword ptr [0x0056A338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A338u);
	// 0x27FBB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27FBC0: movss [0x0056A340], xmm0
	X86_MEM_WRITE_u32(base, 0x56A340u, ctx.xmm[0].u32[0]);
	// 0x27FBC8: ret
	return;
}

void sub_27FBD0(X86Context& ctx, uint8_t* base) {
	// 0x27FBD0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27FBD8: movss [0x0056A2C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2C8u, ctx.xmm[0].u32[0]);
	// 0x27FBE0: ret
	return;
}

void sub_27FBF0(X86Context& ctx, uint8_t* base) {
	// 0x27FBF0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27FBF8: movss [0x0056A2F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2F0u, ctx.xmm[0].u32[0]);
	// 0x27FC00: ret
	return;
}

void sub_27FC10(X86Context& ctx, uint8_t* base) {
	// 0x27FC10: movss xmm0, dword ptr [0x0056A2C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2C8u);
	// 0x27FC18: movss [0x0056A354], xmm0
	X86_MEM_WRITE_u32(base, 0x56A354u, ctx.xmm[0].u32[0]);
	// 0x27FC20: ret
	return;
}

void sub_27FC30(X86Context& ctx, uint8_t* base) {
	// 0x27FC30: movss xmm0, dword ptr [0x0056A338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A338u);
	// 0x27FC38: subss xmm0, [0x0056A2C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A2C8u);
	// 0x27FC40: movss [0x0056A318], xmm0
	X86_MEM_WRITE_u32(base, 0x56A318u, ctx.xmm[0].u32[0]);
	// 0x27FC48: ret
	return;
}

void sub_27FC50(X86Context& ctx, uint8_t* base) {
	// 0x27FC50: movss xmm0, dword ptr [0x0056A318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A318u);
	// 0x27FC58: subss xmm0, [0x0056A2F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A2F0u);
	// 0x27FC60: movss [0x0056A310], xmm0
	X86_MEM_WRITE_u32(base, 0x56A310u, ctx.xmm[0].u32[0]);
	// 0x27FC68: ret
	return;
}

void sub_27FC70(X86Context& ctx, uint8_t* base) {
	// 0x27FC70: movss xmm0, dword ptr [0x0056A340]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A340u);
	// 0x27FC78: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27FC80: movss [0x0056A300], xmm0
	X86_MEM_WRITE_u32(base, 0x56A300u, ctx.xmm[0].u32[0]);
	// 0x27FC88: ret
	return;
}

void sub_27FC90(X86Context& ctx, uint8_t* base) {
	// 0x27FC90: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27FC98: movss [0x0056A2EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2ECu, ctx.xmm[0].u32[0]);
	// 0x27FCA0: ret
	return;
}

void sub_27FCB0(X86Context& ctx, uint8_t* base) {
	// 0x27FCB0: movss xmm0, dword ptr [0x0056A300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A300u);
	// 0x27FCB8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27FCC0: movss [0x0056A330], xmm0
	X86_MEM_WRITE_u32(base, 0x56A330u, ctx.xmm[0].u32[0]);
	// 0x27FCC8: ret
	return;
}

void sub_27FCD0(X86Context& ctx, uint8_t* base) {
	// 0x27FCD0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27FCD8: movss [0x0056A3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3B4u, ctx.xmm[0].u32[0]);
	// 0x27FCE0: ret
	return;
}

void sub_27FCF0(X86Context& ctx, uint8_t* base) {
	// 0x27FCF0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27FCF8: movss [0x0056A3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3D0u, ctx.xmm[0].u32[0]);
	// 0x27FD00: ret
	return;
}

void sub_27FD10(X86Context& ctx, uint8_t* base) {
	// 0x27FD10: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27FD18: movss [0x0056A3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3A8u, ctx.xmm[0].u32[0]);
	// 0x27FD20: ret
	return;
}

void sub_27FD30(X86Context& ctx, uint8_t* base) {
	// 0x27FD30: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27FD38: movss [0x0056A360], xmm0
	X86_MEM_WRITE_u32(base, 0x56A360u, ctx.xmm[0].u32[0]);
	// 0x27FD40: ret
	return;
}

void sub_27FD50(X86Context& ctx, uint8_t* base) {
	// 0x27FD50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27FD58: movss [0x0056A3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3B8u, ctx.xmm[0].u32[0]);
	// 0x27FD60: ret
	return;
}

void sub_27FD70(X86Context& ctx, uint8_t* base) {
	// 0x27FD70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27FD78: movss [0x0056A37C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A37Cu, ctx.xmm[0].u32[0]);
	// 0x27FD80: ret
	return;
}

void sub_27FD90(X86Context& ctx, uint8_t* base) {
	// 0x27FD90: movss xmm0, dword ptr [0x0056A3B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3B8u);
	// 0x27FD98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27FDA0: movss [0x0056A3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3F0u, ctx.xmm[0].u32[0]);
	// 0x27FDA8: ret
	return;
}

void sub_27FDB0(X86Context& ctx, uint8_t* base) {
	// 0x27FDB0: movss xmm0, dword ptr [0x0056A37C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A37Cu);
	// 0x27FDB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27FDC0: movss [0x0056A3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3D8u, ctx.xmm[0].u32[0]);
	// 0x27FDC8: ret
	return;
}

void sub_27FDD0(X86Context& ctx, uint8_t* base) {
	// 0x27FDD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27FDD8: movss [0x0056A408], xmm0
	X86_MEM_WRITE_u32(base, 0x56A408u, ctx.xmm[0].u32[0]);
	// 0x27FDE0: ret
	return;
}

void sub_27FDF0(X86Context& ctx, uint8_t* base) {
	// 0x27FDF0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27FDF8: movss [0x0056A3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3F4u, ctx.xmm[0].u32[0]);
	// 0x27FE00: ret
	return;
}

void sub_27FE10(X86Context& ctx, uint8_t* base) {
	// 0x27FE10: movss xmm0, dword ptr [0x0056A3F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3F4u);
	// 0x27FE18: movss [0x0056A404], xmm0
	X86_MEM_WRITE_u32(base, 0x56A404u, ctx.xmm[0].u32[0]);
	// 0x27FE20: ret
	return;
}

void sub_27FE30(X86Context& ctx, uint8_t* base) {
	// 0x27FE30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27FE38: movss [0x0056A368], xmm0
	X86_MEM_WRITE_u32(base, 0x56A368u, ctx.xmm[0].u32[0]);
	// 0x27FE40: ret
	return;
}

void sub_27FE50(X86Context& ctx, uint8_t* base) {
	// 0x27FE50: movss xmm0, dword ptr [0x0056A37C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A37Cu);
	// 0x27FE58: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27FE60: movss [0x0056A3FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3FCu, ctx.xmm[0].u32[0]);
	// 0x27FE68: ret
	return;
}

void sub_27FE70(X86Context& ctx, uint8_t* base) {
	// 0x27FE70: movss xmm0, dword ptr [0x0056A37C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A37Cu);
	// 0x27FE78: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27FE80: movss [0x0056A3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3A4u, ctx.xmm[0].u32[0]);
	// 0x27FE88: ret
	return;
}

void sub_27FE90(X86Context& ctx, uint8_t* base) {
	// 0x27FE90: movss xmm0, dword ptr [0x0056A37C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A37Cu);
	// 0x27FE98: subss xmm0, [0x0056A3A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A3A4u);
	// 0x27FEA0: movss [0x0056A384], xmm0
	X86_MEM_WRITE_u32(base, 0x56A384u, ctx.xmm[0].u32[0]);
	// 0x27FEA8: ret
	return;
}

void sub_27FEB0(X86Context& ctx, uint8_t* base) {
	// 0x27FEB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27FEB8: movss [0x0056A3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3CCu, ctx.xmm[0].u32[0]);
	// 0x27FEC0: ret
	return;
}

void sub_27FED0(X86Context& ctx, uint8_t* base) {
	// 0x27FED0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27FED8: movss [0x0056A380], xmm0
	X86_MEM_WRITE_u32(base, 0x56A380u, ctx.xmm[0].u32[0]);
	// 0x27FEE0: ret
	return;
}

void sub_27FEF0(X86Context& ctx, uint8_t* base) {
	// 0x27FEF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27FEF8: movss [0x0056A390], xmm0
	X86_MEM_WRITE_u32(base, 0x56A390u, ctx.xmm[0].u32[0]);
	// 0x27FF00: ret
	return;
}

void sub_27FF10(X86Context& ctx, uint8_t* base) {
	// 0x27FF10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27FF18: movss [0x0056A3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3E4u, ctx.xmm[0].u32[0]);
	// 0x27FF20: ret
	return;
}

void sub_27FF30(X86Context& ctx, uint8_t* base) {
	// 0x27FF30: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27FF38: movss [0x0056A3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3C8u, ctx.xmm[0].u32[0]);
	// 0x27FF40: ret
	return;
}

void sub_27FF50(X86Context& ctx, uint8_t* base) {
	// 0x27FF50: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27FF58: movss [0x0056A378], xmm0
	X86_MEM_WRITE_u32(base, 0x56A378u, ctx.xmm[0].u32[0]);
	// 0x27FF60: ret
	return;
}

void sub_27FF70(X86Context& ctx, uint8_t* base) {
	// 0x27FF70: movss xmm0, dword ptr [0x0056A390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A390u);
	// 0x27FF78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27FF80: movss [0x0056A36C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A36Cu, ctx.xmm[0].u32[0]);
	// 0x27FF88: ret
	return;
}

void sub_27FF90(X86Context& ctx, uint8_t* base) {
	// 0x27FF90: movss xmm0, dword ptr [0x0056A3E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3E4u);
	// 0x27FF98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27FFA0: movss [0x0056A3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3B0u, ctx.xmm[0].u32[0]);
	// 0x27FFA8: ret
	return;
}

void sub_27FFB0(X86Context& ctx, uint8_t* base) {
	// 0x27FFB0: movss xmm0, dword ptr [0x0056A36C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A36Cu);
	// 0x27FFB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27FFC0: movss [0x0056A3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3C0u, ctx.xmm[0].u32[0]);
	// 0x27FFC8: ret
	return;
}

void sub_27FFD0(X86Context& ctx, uint8_t* base) {
	// 0x27FFD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27FFD8: movss [0x0056A364], xmm0
	X86_MEM_WRITE_u32(base, 0x56A364u, ctx.xmm[0].u32[0]);
	// 0x27FFE0: ret
	return;
}

void sub_27FFF0(X86Context& ctx, uint8_t* base) {
	// 0x27FFF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27FFF8: movss [0x0056A394], xmm0
	X86_MEM_WRITE_u32(base, 0x56A394u, ctx.xmm[0].u32[0]);
}

void sub_280000(X86Context& ctx, uint8_t* base) {
	// 0x280000: ret
	return;
}

void sub_280010(X86Context& ctx, uint8_t* base) {
	// 0x280010: movss xmm0, dword ptr [0x0056A390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A390u);
	// 0x280018: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x280020: movss [0x0056A3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3A0u, ctx.xmm[0].u32[0]);
	// 0x280028: ret
	return;
}

void sub_280030(X86Context& ctx, uint8_t* base) {
	// 0x280030: movss xmm0, dword ptr [0x0056A3E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3E4u);
	// 0x280038: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x280040: movss [0x0056A3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3E8u, ctx.xmm[0].u32[0]);
	// 0x280048: ret
	return;
}

void sub_280050(X86Context& ctx, uint8_t* base) {
	// 0x280050: movss xmm0, dword ptr [0x0056A3A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3A0u);
	// 0x280058: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280060: movss [0x0056A3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3D4u, ctx.xmm[0].u32[0]);
	// 0x280068: ret
	return;
}

void sub_280070(X86Context& ctx, uint8_t* base) {
	// 0x280070: movss xmm0, dword ptr [0x0056A3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3E8u);
	// 0x280078: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280080: movss [0x0056A3F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3F8u, ctx.xmm[0].u32[0]);
	// 0x280088: ret
	return;
}

void sub_280090(X86Context& ctx, uint8_t* base) {
	// 0x280090: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x280098: movss [0x0056A370], xmm0
	X86_MEM_WRITE_u32(base, 0x56A370u, ctx.xmm[0].u32[0]);
	// 0x2800A0: ret
	return;
}

void sub_2800B0(X86Context& ctx, uint8_t* base) {
	// 0x2800B0: movss xmm0, dword ptr [0x0056A390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A390u);
	// 0x2800B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2800C0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2800C8: movss [0x0056A3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3E0u, ctx.xmm[0].u32[0]);
	// 0x2800D0: ret
	return;
}

void sub_2800E0(X86Context& ctx, uint8_t* base) {
	// 0x2800E0: movss xmm0, dword ptr [0x0056A3E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3E4u);
	// 0x2800E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2800F0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2800F8: movss [0x0056A388], xmm0
	X86_MEM_WRITE_u32(base, 0x56A388u, ctx.xmm[0].u32[0]);
	// 0x280100: ret
	return;
}

void sub_280110(X86Context& ctx, uint8_t* base) {
	// 0x280110: movss xmm0, dword ptr [0x0056A390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A390u);
	// 0x280118: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280120: movss [0x0056A38C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A38Cu, ctx.xmm[0].u32[0]);
	// 0x280128: ret
	return;
}

void sub_280130(X86Context& ctx, uint8_t* base) {
	// 0x280130: movss xmm0, dword ptr [0x0056A3E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3E4u);
	// 0x280138: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280140: movss [0x0056A3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3ECu, ctx.xmm[0].u32[0]);
	// 0x280148: ret
	return;
}

void sub_280150(X86Context& ctx, uint8_t* base) {
	// 0x280150: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x280158: movss [0x0056A374], xmm0
	X86_MEM_WRITE_u32(base, 0x56A374u, ctx.xmm[0].u32[0]);
	// 0x280160: ret
	return;
}

void sub_280170(X86Context& ctx, uint8_t* base) {
	// 0x280170: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x280178: movss [0x0056A39C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A39Cu, ctx.xmm[0].u32[0]);
	// 0x280180: ret
	return;
}

void sub_280190(X86Context& ctx, uint8_t* base) {
	// 0x280190: movss xmm0, dword ptr [0x0056A374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A374u);
	// 0x280198: movss [0x0056A400], xmm0
	X86_MEM_WRITE_u32(base, 0x56A400u, ctx.xmm[0].u32[0]);
	// 0x2801A0: ret
	return;
}

void sub_2801B0(X86Context& ctx, uint8_t* base) {
	// 0x2801B0: movss xmm0, dword ptr [0x0056A3E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3E4u);
	// 0x2801B8: subss xmm0, [0x0056A374]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A374u);
	// 0x2801C0: movss [0x0056A3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3C4u, ctx.xmm[0].u32[0]);
	// 0x2801C8: ret
	return;
}

void sub_2801D0(X86Context& ctx, uint8_t* base) {
	// 0x2801D0: movss xmm0, dword ptr [0x0056A3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3C4u);
	// 0x2801D8: subss xmm0, [0x0056A39C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A39Cu);
	// 0x2801E0: movss [0x0056A3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3BCu, ctx.xmm[0].u32[0]);
	// 0x2801E8: ret
	return;
}

void sub_2801F0(X86Context& ctx, uint8_t* base) {
	// 0x2801F0: movss xmm0, dword ptr [0x0056A3EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3ECu);
	// 0x2801F8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x280200: movss [0x0056A3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3ACu, ctx.xmm[0].u32[0]);
	// 0x280208: ret
	return;
}

void sub_280210(X86Context& ctx, uint8_t* base) {
	// 0x280210: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x280218: movss [0x0056A398], xmm0
	X86_MEM_WRITE_u32(base, 0x56A398u, ctx.xmm[0].u32[0]);
	// 0x280220: ret
	return;
}

void sub_280230(X86Context& ctx, uint8_t* base) {
	// 0x280230: movss xmm0, dword ptr [0x0056A3AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A3ACu);
	// 0x280238: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x280240: movss [0x0056A3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A3DCu, ctx.xmm[0].u32[0]);
	// 0x280248: ret
	return;
}

void sub_280250(X86Context& ctx, uint8_t* base) {
	// 0x280250: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x280258: movss [0x0056A460], xmm0
	X86_MEM_WRITE_u32(base, 0x56A460u, ctx.xmm[0].u32[0]);
	// 0x280260: ret
	return;
}

void sub_280270(X86Context& ctx, uint8_t* base) {
	// 0x280270: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x280278: movss [0x0056A47C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A47Cu, ctx.xmm[0].u32[0]);
	// 0x280280: ret
	return;
}

void sub_280290(X86Context& ctx, uint8_t* base) {
	// 0x280290: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x280298: movss [0x0056A454], xmm0
	X86_MEM_WRITE_u32(base, 0x56A454u, ctx.xmm[0].u32[0]);
	// 0x2802A0: ret
	return;
}

void sub_2802B0(X86Context& ctx, uint8_t* base) {
	// 0x2802B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2802B8: movss [0x0056A40C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A40Cu, ctx.xmm[0].u32[0]);
	// 0x2802C0: ret
	return;
}

void sub_2802D0(X86Context& ctx, uint8_t* base) {
	// 0x2802D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2802D8: movss [0x0056A464], xmm0
	X86_MEM_WRITE_u32(base, 0x56A464u, ctx.xmm[0].u32[0]);
	// 0x2802E0: ret
	return;
}

void sub_2802F0(X86Context& ctx, uint8_t* base) {
	// 0x2802F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2802F8: movss [0x0056A428], xmm0
	X86_MEM_WRITE_u32(base, 0x56A428u, ctx.xmm[0].u32[0]);
	// 0x280300: ret
	return;
}

void sub_280310(X86Context& ctx, uint8_t* base) {
	// 0x280310: movss xmm0, dword ptr [0x0056A464]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A464u);
	// 0x280318: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x280320: movss [0x0056A49C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A49Cu, ctx.xmm[0].u32[0]);
	// 0x280328: ret
	return;
}

void sub_280330(X86Context& ctx, uint8_t* base) {
	// 0x280330: movss xmm0, dword ptr [0x0056A428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A428u);
	// 0x280338: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x280340: movss [0x0056A484], xmm0
	X86_MEM_WRITE_u32(base, 0x56A484u, ctx.xmm[0].u32[0]);
	// 0x280348: ret
	return;
}

void sub_280350(X86Context& ctx, uint8_t* base) {
	// 0x280350: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x280358: movss [0x0056A4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4B4u, ctx.xmm[0].u32[0]);
	// 0x280360: ret
	return;
}

void sub_280370(X86Context& ctx, uint8_t* base) {
	// 0x280370: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x280378: movss [0x0056A4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4A0u, ctx.xmm[0].u32[0]);
	// 0x280380: ret
	return;
}

void sub_280390(X86Context& ctx, uint8_t* base) {
	// 0x280390: movss xmm0, dword ptr [0x0056A4A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4A0u);
	// 0x280398: movss [0x0056A4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4B0u, ctx.xmm[0].u32[0]);
	// 0x2803A0: ret
	return;
}

void sub_2803B0(X86Context& ctx, uint8_t* base) {
	// 0x2803B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2803B8: movss [0x0056A414], xmm0
	X86_MEM_WRITE_u32(base, 0x56A414u, ctx.xmm[0].u32[0]);
	// 0x2803C0: ret
	return;
}

void sub_2803D0(X86Context& ctx, uint8_t* base) {
	// 0x2803D0: movss xmm0, dword ptr [0x0056A428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A428u);
	// 0x2803D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2803E0: movss [0x0056A4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4A8u, ctx.xmm[0].u32[0]);
	// 0x2803E8: ret
	return;
}

void sub_2803F0(X86Context& ctx, uint8_t* base) {
	// 0x2803F0: movss xmm0, dword ptr [0x0056A428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A428u);
	// 0x2803F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x280400: movss [0x0056A450], xmm0
	X86_MEM_WRITE_u32(base, 0x56A450u, ctx.xmm[0].u32[0]);
	// 0x280408: ret
	return;
}

void sub_280410(X86Context& ctx, uint8_t* base) {
	// 0x280410: movss xmm0, dword ptr [0x0056A428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A428u);
	// 0x280418: subss xmm0, [0x0056A450]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A450u);
	// 0x280420: movss [0x0056A430], xmm0
	X86_MEM_WRITE_u32(base, 0x56A430u, ctx.xmm[0].u32[0]);
	// 0x280428: ret
	return;
}

void sub_280430(X86Context& ctx, uint8_t* base) {
	// 0x280430: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x280438: movss [0x0056A478], xmm0
	X86_MEM_WRITE_u32(base, 0x56A478u, ctx.xmm[0].u32[0]);
	// 0x280440: ret
	return;
}

void sub_280450(X86Context& ctx, uint8_t* base) {
	// 0x280450: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x280458: movss [0x0056A42C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A42Cu, ctx.xmm[0].u32[0]);
	// 0x280460: ret
	return;
}

void sub_280470(X86Context& ctx, uint8_t* base) {
	// 0x280470: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x280478: movss [0x0056A43C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A43Cu, ctx.xmm[0].u32[0]);
	// 0x280480: ret
	return;
}

void sub_280490(X86Context& ctx, uint8_t* base) {
	// 0x280490: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x280498: movss [0x0056A490], xmm0
	X86_MEM_WRITE_u32(base, 0x56A490u, ctx.xmm[0].u32[0]);
	// 0x2804A0: ret
	return;
}

void sub_2804B0(X86Context& ctx, uint8_t* base) {
	// 0x2804B0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2804B8: movss [0x0056A474], xmm0
	X86_MEM_WRITE_u32(base, 0x56A474u, ctx.xmm[0].u32[0]);
	// 0x2804C0: ret
	return;
}

void sub_2804D0(X86Context& ctx, uint8_t* base) {
	// 0x2804D0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2804D8: movss [0x0056A424], xmm0
	X86_MEM_WRITE_u32(base, 0x56A424u, ctx.xmm[0].u32[0]);
	// 0x2804E0: ret
	return;
}

void sub_2804F0(X86Context& ctx, uint8_t* base) {
	// 0x2804F0: movss xmm0, dword ptr [0x0056A43C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A43Cu);
	// 0x2804F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x280500: movss [0x0056A418], xmm0
	X86_MEM_WRITE_u32(base, 0x56A418u, ctx.xmm[0].u32[0]);
	// 0x280508: ret
	return;
}

void sub_280510(X86Context& ctx, uint8_t* base) {
	// 0x280510: movss xmm0, dword ptr [0x0056A490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A490u);
	// 0x280518: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x280520: movss [0x0056A45C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A45Cu, ctx.xmm[0].u32[0]);
	// 0x280528: ret
	return;
}

void sub_280530(X86Context& ctx, uint8_t* base) {
	// 0x280530: movss xmm0, dword ptr [0x0056A418]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A418u);
	// 0x280538: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x280540: movss [0x0056A46C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A46Cu, ctx.xmm[0].u32[0]);
	// 0x280548: ret
	return;
}

void sub_280550(X86Context& ctx, uint8_t* base) {
	// 0x280550: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x280558: movss [0x0056A410], xmm0
	X86_MEM_WRITE_u32(base, 0x56A410u, ctx.xmm[0].u32[0]);
	// 0x280560: ret
	return;
}

void sub_280570(X86Context& ctx, uint8_t* base) {
	// 0x280570: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x280578: movss [0x0056A440], xmm0
	X86_MEM_WRITE_u32(base, 0x56A440u, ctx.xmm[0].u32[0]);
	// 0x280580: ret
	return;
}

void sub_280590(X86Context& ctx, uint8_t* base) {
	// 0x280590: movss xmm0, dword ptr [0x0056A43C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A43Cu);
	// 0x280598: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2805A0: movss [0x0056A44C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A44Cu, ctx.xmm[0].u32[0]);
	// 0x2805A8: ret
	return;
}

void sub_2805B0(X86Context& ctx, uint8_t* base) {
	// 0x2805B0: movss xmm0, dword ptr [0x0056A490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A490u);
	// 0x2805B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2805C0: movss [0x0056A494], xmm0
	X86_MEM_WRITE_u32(base, 0x56A494u, ctx.xmm[0].u32[0]);
	// 0x2805C8: ret
	return;
}

void sub_2805D0(X86Context& ctx, uint8_t* base) {
	// 0x2805D0: movss xmm0, dword ptr [0x0056A44C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A44Cu);
	// 0x2805D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2805E0: movss [0x0056A480], xmm0
	X86_MEM_WRITE_u32(base, 0x56A480u, ctx.xmm[0].u32[0]);
	// 0x2805E8: ret
	return;
}

void sub_2805F0(X86Context& ctx, uint8_t* base) {
	// 0x2805F0: movss xmm0, dword ptr [0x0056A494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A494u);
	// 0x2805F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280600: movss [0x0056A4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4A4u, ctx.xmm[0].u32[0]);
	// 0x280608: ret
	return;
}

void sub_280610(X86Context& ctx, uint8_t* base) {
	// 0x280610: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x280618: movss [0x0056A41C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A41Cu, ctx.xmm[0].u32[0]);
	// 0x280620: ret
	return;
}

void sub_280630(X86Context& ctx, uint8_t* base) {
	// 0x280630: movss xmm0, dword ptr [0x0056A43C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A43Cu);
	// 0x280638: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280640: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x280648: movss [0x0056A48C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A48Cu, ctx.xmm[0].u32[0]);
	// 0x280650: ret
	return;
}

void sub_280660(X86Context& ctx, uint8_t* base) {
	// 0x280660: movss xmm0, dword ptr [0x0056A490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A490u);
	// 0x280668: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280670: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x280678: movss [0x0056A434], xmm0
	X86_MEM_WRITE_u32(base, 0x56A434u, ctx.xmm[0].u32[0]);
	// 0x280680: ret
	return;
}

void sub_280690(X86Context& ctx, uint8_t* base) {
	// 0x280690: movss xmm0, dword ptr [0x0056A43C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A43Cu);
	// 0x280698: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2806A0: movss [0x0056A438], xmm0
	X86_MEM_WRITE_u32(base, 0x56A438u, ctx.xmm[0].u32[0]);
	// 0x2806A8: ret
	return;
}

void sub_2806B0(X86Context& ctx, uint8_t* base) {
	// 0x2806B0: movss xmm0, dword ptr [0x0056A490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A490u);
	// 0x2806B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2806C0: movss [0x0056A498], xmm0
	X86_MEM_WRITE_u32(base, 0x56A498u, ctx.xmm[0].u32[0]);
	// 0x2806C8: ret
	return;
}

void sub_2806D0(X86Context& ctx, uint8_t* base) {
	// 0x2806D0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2806D8: movss [0x0056A420], xmm0
	X86_MEM_WRITE_u32(base, 0x56A420u, ctx.xmm[0].u32[0]);
	// 0x2806E0: ret
	return;
}

void sub_2806F0(X86Context& ctx, uint8_t* base) {
	// 0x2806F0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2806F8: movss [0x0056A448], xmm0
	X86_MEM_WRITE_u32(base, 0x56A448u, ctx.xmm[0].u32[0]);
	// 0x280700: ret
	return;
}

void sub_280710(X86Context& ctx, uint8_t* base) {
	// 0x280710: movss xmm0, dword ptr [0x0056A420]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A420u);
	// 0x280718: movss [0x0056A4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4ACu, ctx.xmm[0].u32[0]);
	// 0x280720: ret
	return;
}

void sub_280730(X86Context& ctx, uint8_t* base) {
	// 0x280730: movss xmm0, dword ptr [0x0056A490]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A490u);
	// 0x280738: subss xmm0, [0x0056A420]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A420u);
	// 0x280740: movss [0x0056A470], xmm0
	X86_MEM_WRITE_u32(base, 0x56A470u, ctx.xmm[0].u32[0]);
	// 0x280748: ret
	return;
}

void sub_280750(X86Context& ctx, uint8_t* base) {
	// 0x280750: movss xmm0, dword ptr [0x0056A470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A470u);
	// 0x280758: subss xmm0, [0x0056A448]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A448u);
	// 0x280760: movss [0x0056A468], xmm0
	X86_MEM_WRITE_u32(base, 0x56A468u, ctx.xmm[0].u32[0]);
	// 0x280768: ret
	return;
}

void sub_280770(X86Context& ctx, uint8_t* base) {
	// 0x280770: movss xmm0, dword ptr [0x0056A498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A498u);
	// 0x280778: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x280780: movss [0x0056A458], xmm0
	X86_MEM_WRITE_u32(base, 0x56A458u, ctx.xmm[0].u32[0]);
	// 0x280788: ret
	return;
}

void sub_280790(X86Context& ctx, uint8_t* base) {
	// 0x280790: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x280798: movss [0x0056A444], xmm0
	X86_MEM_WRITE_u32(base, 0x56A444u, ctx.xmm[0].u32[0]);
	// 0x2807A0: ret
	return;
}

void sub_2807B0(X86Context& ctx, uint8_t* base) {
	// 0x2807B0: movss xmm0, dword ptr [0x0056A458]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A458u);
	// 0x2807B8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2807C0: movss [0x0056A488], xmm0
	X86_MEM_WRITE_u32(base, 0x56A488u, ctx.xmm[0].u32[0]);
	// 0x2807C8: ret
	return;
}

void sub_2807D0(X86Context& ctx, uint8_t* base) {
	// 0x2807D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2807D8: movss [0x0056A50C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A50Cu, ctx.xmm[0].u32[0]);
	// 0x2807E0: ret
	return;
}

void sub_2807F0(X86Context& ctx, uint8_t* base) {
	// 0x2807F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2807F8: movss [0x0056A528], xmm0
	X86_MEM_WRITE_u32(base, 0x56A528u, ctx.xmm[0].u32[0]);
	// 0x280800: ret
	return;
}

void sub_280810(X86Context& ctx, uint8_t* base) {
	// 0x280810: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x280818: movss [0x0056A500], xmm0
	X86_MEM_WRITE_u32(base, 0x56A500u, ctx.xmm[0].u32[0]);
	// 0x280820: ret
	return;
}

void sub_280830(X86Context& ctx, uint8_t* base) {
	// 0x280830: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x280838: movss [0x0056A4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4B8u, ctx.xmm[0].u32[0]);
	// 0x280840: ret
	return;
}

void sub_280850(X86Context& ctx, uint8_t* base) {
	// 0x280850: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x280858: movss [0x0056A510], xmm0
	X86_MEM_WRITE_u32(base, 0x56A510u, ctx.xmm[0].u32[0]);
	// 0x280860: ret
	return;
}

void sub_280870(X86Context& ctx, uint8_t* base) {
	// 0x280870: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x280878: movss [0x0056A4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4D4u, ctx.xmm[0].u32[0]);
	// 0x280880: ret
	return;
}

void sub_280890(X86Context& ctx, uint8_t* base) {
	// 0x280890: movss xmm0, dword ptr [0x0056A510]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A510u);
	// 0x280898: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2808A0: movss [0x0056A548], xmm0
	X86_MEM_WRITE_u32(base, 0x56A548u, ctx.xmm[0].u32[0]);
	// 0x2808A8: ret
	return;
}

void sub_2808B0(X86Context& ctx, uint8_t* base) {
	// 0x2808B0: movss xmm0, dword ptr [0x0056A4D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4D4u);
	// 0x2808B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2808C0: movss [0x0056A530], xmm0
	X86_MEM_WRITE_u32(base, 0x56A530u, ctx.xmm[0].u32[0]);
	// 0x2808C8: ret
	return;
}

void sub_2808D0(X86Context& ctx, uint8_t* base) {
	// 0x2808D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2808D8: movss [0x0056A560], xmm0
	X86_MEM_WRITE_u32(base, 0x56A560u, ctx.xmm[0].u32[0]);
	// 0x2808E0: ret
	return;
}

void sub_2808F0(X86Context& ctx, uint8_t* base) {
	// 0x2808F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2808F8: movss [0x0056A54C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A54Cu, ctx.xmm[0].u32[0]);
	// 0x280900: ret
	return;
}

void sub_280910(X86Context& ctx, uint8_t* base) {
	// 0x280910: movss xmm0, dword ptr [0x0056A54C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A54Cu);
	// 0x280918: movss [0x0056A55C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A55Cu, ctx.xmm[0].u32[0]);
	// 0x280920: ret
	return;
}

void sub_280930(X86Context& ctx, uint8_t* base) {
	// 0x280930: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x280938: movss [0x0056A4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4C0u, ctx.xmm[0].u32[0]);
	// 0x280940: ret
	return;
}

void sub_280950(X86Context& ctx, uint8_t* base) {
	// 0x280950: movss xmm0, dword ptr [0x0056A4D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4D4u);
	// 0x280958: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x280960: movss [0x0056A554], xmm0
	X86_MEM_WRITE_u32(base, 0x56A554u, ctx.xmm[0].u32[0]);
	// 0x280968: ret
	return;
}

void sub_280970(X86Context& ctx, uint8_t* base) {
	// 0x280970: movss xmm0, dword ptr [0x0056A4D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4D4u);
	// 0x280978: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x280980: movss [0x0056A4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4FCu, ctx.xmm[0].u32[0]);
	// 0x280988: ret
	return;
}

void sub_280990(X86Context& ctx, uint8_t* base) {
	// 0x280990: movss xmm0, dword ptr [0x0056A4D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4D4u);
	// 0x280998: subss xmm0, [0x0056A4FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A4FCu);
	// 0x2809A0: movss [0x0056A4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4DCu, ctx.xmm[0].u32[0]);
	// 0x2809A8: ret
	return;
}

void sub_2809B0(X86Context& ctx, uint8_t* base) {
	// 0x2809B0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2809B8: movss [0x0056A524], xmm0
	X86_MEM_WRITE_u32(base, 0x56A524u, ctx.xmm[0].u32[0]);
	// 0x2809C0: ret
	return;
}

void sub_2809D0(X86Context& ctx, uint8_t* base) {
	// 0x2809D0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2809D8: movss [0x0056A4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4D8u, ctx.xmm[0].u32[0]);
	// 0x2809E0: ret
	return;
}

void sub_2809F0(X86Context& ctx, uint8_t* base) {
	// 0x2809F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2809F8: movss [0x0056A4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4E8u, ctx.xmm[0].u32[0]);
	// 0x280A00: ret
	return;
}

void sub_280A10(X86Context& ctx, uint8_t* base) {
	// 0x280A10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x280A18: movss [0x0056A53C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A53Cu, ctx.xmm[0].u32[0]);
	// 0x280A20: ret
	return;
}

void sub_280A30(X86Context& ctx, uint8_t* base) {
	// 0x280A30: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x280A38: movss [0x0056A520], xmm0
	X86_MEM_WRITE_u32(base, 0x56A520u, ctx.xmm[0].u32[0]);
	// 0x280A40: ret
	return;
}

void sub_280A50(X86Context& ctx, uint8_t* base) {
	// 0x280A50: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x280A58: movss [0x0056A4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4D0u, ctx.xmm[0].u32[0]);
	// 0x280A60: ret
	return;
}

void sub_280A70(X86Context& ctx, uint8_t* base) {
	// 0x280A70: movss xmm0, dword ptr [0x0056A4E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4E8u);
	// 0x280A78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x280A80: movss [0x0056A4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4C4u, ctx.xmm[0].u32[0]);
	// 0x280A88: ret
	return;
}

void sub_280A90(X86Context& ctx, uint8_t* base) {
	// 0x280A90: movss xmm0, dword ptr [0x0056A53C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A53Cu);
	// 0x280A98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x280AA0: movss [0x0056A508], xmm0
	X86_MEM_WRITE_u32(base, 0x56A508u, ctx.xmm[0].u32[0]);
	// 0x280AA8: ret
	return;
}

void sub_280AB0(X86Context& ctx, uint8_t* base) {
	// 0x280AB0: movss xmm0, dword ptr [0x0056A4C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4C4u);
	// 0x280AB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x280AC0: movss [0x0056A518], xmm0
	X86_MEM_WRITE_u32(base, 0x56A518u, ctx.xmm[0].u32[0]);
	// 0x280AC8: ret
	return;
}

void sub_280AD0(X86Context& ctx, uint8_t* base) {
	// 0x280AD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x280AD8: movss [0x0056A4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4BCu, ctx.xmm[0].u32[0]);
	// 0x280AE0: ret
	return;
}

void sub_280AF0(X86Context& ctx, uint8_t* base) {
	// 0x280AF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x280AF8: movss [0x0056A4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4ECu, ctx.xmm[0].u32[0]);
	// 0x280B00: ret
	return;
}

void sub_280B10(X86Context& ctx, uint8_t* base) {
	// 0x280B10: movss xmm0, dword ptr [0x0056A4E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4E8u);
	// 0x280B18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x280B20: movss [0x0056A4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4F8u, ctx.xmm[0].u32[0]);
	// 0x280B28: ret
	return;
}

void sub_280B30(X86Context& ctx, uint8_t* base) {
	// 0x280B30: movss xmm0, dword ptr [0x0056A53C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A53Cu);
	// 0x280B38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x280B40: movss [0x0056A540], xmm0
	X86_MEM_WRITE_u32(base, 0x56A540u, ctx.xmm[0].u32[0]);
	// 0x280B48: ret
	return;
}

void sub_280B50(X86Context& ctx, uint8_t* base) {
	// 0x280B50: movss xmm0, dword ptr [0x0056A4F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4F8u);
	// 0x280B58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280B60: movss [0x0056A52C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A52Cu, ctx.xmm[0].u32[0]);
	// 0x280B68: ret
	return;
}

void sub_280B70(X86Context& ctx, uint8_t* base) {
	// 0x280B70: movss xmm0, dword ptr [0x0056A540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A540u);
	// 0x280B78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280B80: movss [0x0056A550], xmm0
	X86_MEM_WRITE_u32(base, 0x56A550u, ctx.xmm[0].u32[0]);
	// 0x280B88: ret
	return;
}

void sub_280B90(X86Context& ctx, uint8_t* base) {
	// 0x280B90: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x280B98: movss [0x0056A4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4C8u, ctx.xmm[0].u32[0]);
	// 0x280BA0: ret
	return;
}

void sub_280BB0(X86Context& ctx, uint8_t* base) {
	// 0x280BB0: movss xmm0, dword ptr [0x0056A4E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4E8u);
	// 0x280BB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280BC0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x280BC8: movss [0x0056A538], xmm0
	X86_MEM_WRITE_u32(base, 0x56A538u, ctx.xmm[0].u32[0]);
	// 0x280BD0: ret
	return;
}

void sub_280BE0(X86Context& ctx, uint8_t* base) {
	// 0x280BE0: movss xmm0, dword ptr [0x0056A53C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A53Cu);
	// 0x280BE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280BF0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x280BF8: movss [0x0056A4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4E0u, ctx.xmm[0].u32[0]);
	// 0x280C00: ret
	return;
}

void sub_280C10(X86Context& ctx, uint8_t* base) {
	// 0x280C10: movss xmm0, dword ptr [0x0056A4E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4E8u);
	// 0x280C18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280C20: movss [0x0056A4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4E4u, ctx.xmm[0].u32[0]);
	// 0x280C28: ret
	return;
}

void sub_280C30(X86Context& ctx, uint8_t* base) {
	// 0x280C30: movss xmm0, dword ptr [0x0056A53C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A53Cu);
	// 0x280C38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x280C40: movss [0x0056A544], xmm0
	X86_MEM_WRITE_u32(base, 0x56A544u, ctx.xmm[0].u32[0]);
	// 0x280C48: ret
	return;
}

void sub_280C50(X86Context& ctx, uint8_t* base) {
	// 0x280C50: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x280C58: movss [0x0056A4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4CCu, ctx.xmm[0].u32[0]);
	// 0x280C60: ret
	return;
}

void sub_280C70(X86Context& ctx, uint8_t* base) {
	// 0x280C70: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x280C78: movss [0x0056A4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4F4u, ctx.xmm[0].u32[0]);
	// 0x280C80: ret
	return;
}

void sub_280C90(X86Context& ctx, uint8_t* base) {
	// 0x280C90: movss xmm0, dword ptr [0x0056A4CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A4CCu);
	// 0x280C98: movss [0x0056A558], xmm0
	X86_MEM_WRITE_u32(base, 0x56A558u, ctx.xmm[0].u32[0]);
	// 0x280CA0: ret
	return;
}

void sub_280CB0(X86Context& ctx, uint8_t* base) {
	// 0x280CB0: movss xmm0, dword ptr [0x0056A53C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A53Cu);
	// 0x280CB8: subss xmm0, [0x0056A4CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A4CCu);
	// 0x280CC0: movss [0x0056A51C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A51Cu, ctx.xmm[0].u32[0]);
	// 0x280CC8: ret
	return;
}

void sub_280CD0(X86Context& ctx, uint8_t* base) {
	// 0x280CD0: movss xmm0, dword ptr [0x0056A51C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A51Cu);
	// 0x280CD8: subss xmm0, [0x0056A4F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A4F4u);
	// 0x280CE0: movss [0x0056A514], xmm0
	X86_MEM_WRITE_u32(base, 0x56A514u, ctx.xmm[0].u32[0]);
	// 0x280CE8: ret
	return;
}

void sub_280CF0(X86Context& ctx, uint8_t* base) {
	// 0x280CF0: movss xmm0, dword ptr [0x0056A544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A544u);
	// 0x280CF8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x280D00: movss [0x0056A504], xmm0
	X86_MEM_WRITE_u32(base, 0x56A504u, ctx.xmm[0].u32[0]);
	// 0x280D08: ret
	return;
}

void sub_280D10(X86Context& ctx, uint8_t* base) {
	// 0x280D10: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x280D18: movss [0x0056A4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A4F0u, ctx.xmm[0].u32[0]);
	// 0x280D20: ret
	return;
}

void sub_280D30(X86Context& ctx, uint8_t* base) {
	// 0x280D30: movss xmm0, dword ptr [0x0056A504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A504u);
	// 0x280D38: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x280D40: movss [0x0056A534], xmm0
	X86_MEM_WRITE_u32(base, 0x56A534u, ctx.xmm[0].u32[0]);
	// 0x280D48: ret
	return;
}

void sub_280D50(X86Context& ctx, uint8_t* base) {
	// 0x280D50: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x280D58: movss [0x0056A5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5B8u, ctx.xmm[0].u32[0]);
	// 0x280D60: ret
	return;
}

void sub_280D70(X86Context& ctx, uint8_t* base) {
	// 0x280D70: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x280D78: movss [0x0056A5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5D4u, ctx.xmm[0].u32[0]);
	// 0x280D80: ret
	return;
}

void sub_280D90(X86Context& ctx, uint8_t* base) {
	// 0x280D90: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x280D98: movss [0x0056A5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5ACu, ctx.xmm[0].u32[0]);
	// 0x280DA0: ret
	return;
}

void sub_280DB0(X86Context& ctx, uint8_t* base) {
	// 0x280DB0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x280DB8: movss [0x0056A564], xmm0
	X86_MEM_WRITE_u32(base, 0x56A564u, ctx.xmm[0].u32[0]);
	// 0x280DC0: ret
	return;
}

void sub_280DD0(X86Context& ctx, uint8_t* base) {
	// 0x280DD0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x280DD8: movss [0x0056A5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5BCu, ctx.xmm[0].u32[0]);
	// 0x280DE0: ret
	return;
}

void sub_280DF0(X86Context& ctx, uint8_t* base) {
	// 0x280DF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x280DF8: movss [0x0056A580], xmm0
	X86_MEM_WRITE_u32(base, 0x56A580u, ctx.xmm[0].u32[0]);
	// 0x280E00: ret
	return;
}

void sub_280E10(X86Context& ctx, uint8_t* base) {
	// 0x280E10: movss xmm0, dword ptr [0x0056A5BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5BCu);
	// 0x280E18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x280E20: movss [0x0056A5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5F4u, ctx.xmm[0].u32[0]);
	// 0x280E28: ret
	return;
}

void sub_280E30(X86Context& ctx, uint8_t* base) {
	// 0x280E30: movss xmm0, dword ptr [0x0056A580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A580u);
	// 0x280E38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x280E40: movss [0x0056A5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5DCu, ctx.xmm[0].u32[0]);
	// 0x280E48: ret
	return;
}

void sub_280E50(X86Context& ctx, uint8_t* base) {
	// 0x280E50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x280E58: movss [0x0056A60C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A60Cu, ctx.xmm[0].u32[0]);
	// 0x280E60: ret
	return;
}

void sub_280E70(X86Context& ctx, uint8_t* base) {
	// 0x280E70: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x280E78: movss [0x0056A5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5F8u, ctx.xmm[0].u32[0]);
	// 0x280E80: ret
	return;
}

void sub_280E90(X86Context& ctx, uint8_t* base) {
	// 0x280E90: movss xmm0, dword ptr [0x0056A5F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5F8u);
	// 0x280E98: movss [0x0056A608], xmm0
	X86_MEM_WRITE_u32(base, 0x56A608u, ctx.xmm[0].u32[0]);
	// 0x280EA0: ret
	return;
}

void sub_280EB0(X86Context& ctx, uint8_t* base) {
	// 0x280EB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x280EB8: movss [0x0056A56C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A56Cu, ctx.xmm[0].u32[0]);
	// 0x280EC0: ret
	return;
}

void sub_280ED0(X86Context& ctx, uint8_t* base) {
	// 0x280ED0: movss xmm0, dword ptr [0x0056A580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A580u);
	// 0x280ED8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x280EE0: movss [0x0056A600], xmm0
	X86_MEM_WRITE_u32(base, 0x56A600u, ctx.xmm[0].u32[0]);
	// 0x280EE8: ret
	return;
}

void sub_280EF0(X86Context& ctx, uint8_t* base) {
	// 0x280EF0: movss xmm0, dword ptr [0x0056A580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A580u);
	// 0x280EF8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x280F00: movss [0x0056A5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5A8u, ctx.xmm[0].u32[0]);
	// 0x280F08: ret
	return;
}

void sub_280F10(X86Context& ctx, uint8_t* base) {
	// 0x280F10: movss xmm0, dword ptr [0x0056A580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A580u);
	// 0x280F18: subss xmm0, [0x0056A5A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A5A8u);
	// 0x280F20: movss [0x0056A588], xmm0
	X86_MEM_WRITE_u32(base, 0x56A588u, ctx.xmm[0].u32[0]);
	// 0x280F28: ret
	return;
}

void sub_280F30(X86Context& ctx, uint8_t* base) {
	// 0x280F30: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x280F38: movss [0x0056A5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5D0u, ctx.xmm[0].u32[0]);
	// 0x280F40: ret
	return;
}

void sub_280F50(X86Context& ctx, uint8_t* base) {
	// 0x280F50: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x280F58: movss [0x0056A584], xmm0
	X86_MEM_WRITE_u32(base, 0x56A584u, ctx.xmm[0].u32[0]);
	// 0x280F60: ret
	return;
}

void sub_280F70(X86Context& ctx, uint8_t* base) {
	// 0x280F70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x280F78: movss [0x0056A594], xmm0
	X86_MEM_WRITE_u32(base, 0x56A594u, ctx.xmm[0].u32[0]);
	// 0x280F80: ret
	return;
}

void sub_280F90(X86Context& ctx, uint8_t* base) {
	// 0x280F90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x280F98: movss [0x0056A5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5E8u, ctx.xmm[0].u32[0]);
	// 0x280FA0: ret
	return;
}

void sub_280FB0(X86Context& ctx, uint8_t* base) {
	// 0x280FB0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x280FB8: movss [0x0056A5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5CCu, ctx.xmm[0].u32[0]);
	// 0x280FC0: ret
	return;
}

void sub_280FD0(X86Context& ctx, uint8_t* base) {
	// 0x280FD0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x280FD8: movss [0x0056A57C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A57Cu, ctx.xmm[0].u32[0]);
	// 0x280FE0: ret
	return;
}

void sub_280FF0(X86Context& ctx, uint8_t* base) {
	// 0x280FF0: movss xmm0, dword ptr [0x0056A594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A594u);
	// 0x280FF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281000: movss [0x0056A570], xmm0
	X86_MEM_WRITE_u32(base, 0x56A570u, ctx.xmm[0].u32[0]);
	// 0x281008: ret
	return;
}

void sub_281010(X86Context& ctx, uint8_t* base) {
	// 0x281010: movss xmm0, dword ptr [0x0056A5E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5E8u);
	// 0x281018: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x281020: movss [0x0056A5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5B4u, ctx.xmm[0].u32[0]);
	// 0x281028: ret
	return;
}

void sub_281030(X86Context& ctx, uint8_t* base) {
	// 0x281030: movss xmm0, dword ptr [0x0056A570]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A570u);
	// 0x281038: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281040: movss [0x0056A5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5C4u, ctx.xmm[0].u32[0]);
	// 0x281048: ret
	return;
}

void sub_281050(X86Context& ctx, uint8_t* base) {
	// 0x281050: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x281058: movss [0x0056A568], xmm0
	X86_MEM_WRITE_u32(base, 0x56A568u, ctx.xmm[0].u32[0]);
	// 0x281060: ret
	return;
}

void sub_281070(X86Context& ctx, uint8_t* base) {
	// 0x281070: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x281078: movss [0x0056A598], xmm0
	X86_MEM_WRITE_u32(base, 0x56A598u, ctx.xmm[0].u32[0]);
	// 0x281080: ret
	return;
}

void sub_281090(X86Context& ctx, uint8_t* base) {
	// 0x281090: movss xmm0, dword ptr [0x0056A594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A594u);
	// 0x281098: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2810A0: movss [0x0056A5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5A4u, ctx.xmm[0].u32[0]);
	// 0x2810A8: ret
	return;
}

void sub_2810B0(X86Context& ctx, uint8_t* base) {
	// 0x2810B0: movss xmm0, dword ptr [0x0056A5E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5E8u);
	// 0x2810B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2810C0: movss [0x0056A5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5ECu, ctx.xmm[0].u32[0]);
	// 0x2810C8: ret
	return;
}

void sub_2810D0(X86Context& ctx, uint8_t* base) {
	// 0x2810D0: movss xmm0, dword ptr [0x0056A5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5A4u);
	// 0x2810D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2810E0: movss [0x0056A5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5D8u, ctx.xmm[0].u32[0]);
	// 0x2810E8: ret
	return;
}

void sub_2810F0(X86Context& ctx, uint8_t* base) {
	// 0x2810F0: movss xmm0, dword ptr [0x0056A5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5ECu);
	// 0x2810F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281100: movss [0x0056A5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5FCu, ctx.xmm[0].u32[0]);
	// 0x281108: ret
	return;
}

void sub_281110(X86Context& ctx, uint8_t* base) {
	// 0x281110: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x281118: movss [0x0056A574], xmm0
	X86_MEM_WRITE_u32(base, 0x56A574u, ctx.xmm[0].u32[0]);
	// 0x281120: ret
	return;
}

void sub_281130(X86Context& ctx, uint8_t* base) {
	// 0x281130: movss xmm0, dword ptr [0x0056A594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A594u);
	// 0x281138: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281140: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x281148: movss [0x0056A5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5E4u, ctx.xmm[0].u32[0]);
	// 0x281150: ret
	return;
}

void sub_281160(X86Context& ctx, uint8_t* base) {
	// 0x281160: movss xmm0, dword ptr [0x0056A5E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5E8u);
	// 0x281168: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281170: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x281178: movss [0x0056A58C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A58Cu, ctx.xmm[0].u32[0]);
	// 0x281180: ret
	return;
}

void sub_281190(X86Context& ctx, uint8_t* base) {
	// 0x281190: movss xmm0, dword ptr [0x0056A594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A594u);
	// 0x281198: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2811A0: movss [0x0056A590], xmm0
	X86_MEM_WRITE_u32(base, 0x56A590u, ctx.xmm[0].u32[0]);
	// 0x2811A8: ret
	return;
}

void sub_2811B0(X86Context& ctx, uint8_t* base) {
	// 0x2811B0: movss xmm0, dword ptr [0x0056A5E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5E8u);
	// 0x2811B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2811C0: movss [0x0056A5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5F0u, ctx.xmm[0].u32[0]);
	// 0x2811C8: ret
	return;
}

void sub_2811D0(X86Context& ctx, uint8_t* base) {
	// 0x2811D0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2811D8: movss [0x0056A578], xmm0
	X86_MEM_WRITE_u32(base, 0x56A578u, ctx.xmm[0].u32[0]);
	// 0x2811E0: ret
	return;
}

void sub_2811F0(X86Context& ctx, uint8_t* base) {
	// 0x2811F0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2811F8: movss [0x0056A5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5A0u, ctx.xmm[0].u32[0]);
	// 0x281200: ret
	return;
}

void sub_281210(X86Context& ctx, uint8_t* base) {
	// 0x281210: movss xmm0, dword ptr [0x0056A578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A578u);
	// 0x281218: movss [0x0056A604], xmm0
	X86_MEM_WRITE_u32(base, 0x56A604u, ctx.xmm[0].u32[0]);
	// 0x281220: ret
	return;
}

void sub_281230(X86Context& ctx, uint8_t* base) {
	// 0x281230: movss xmm0, dword ptr [0x0056A5E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5E8u);
	// 0x281238: subss xmm0, [0x0056A578]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A578u);
	// 0x281240: movss [0x0056A5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5C8u, ctx.xmm[0].u32[0]);
	// 0x281248: ret
	return;
}

void sub_281250(X86Context& ctx, uint8_t* base) {
	// 0x281250: movss xmm0, dword ptr [0x0056A5C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5C8u);
	// 0x281258: subss xmm0, [0x0056A5A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A5A0u);
	// 0x281260: movss [0x0056A5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5C0u, ctx.xmm[0].u32[0]);
	// 0x281268: ret
	return;
}

void sub_281270(X86Context& ctx, uint8_t* base) {
	// 0x281270: movss xmm0, dword ptr [0x0056A5F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5F0u);
	// 0x281278: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x281280: movss [0x0056A5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5B0u, ctx.xmm[0].u32[0]);
	// 0x281288: ret
	return;
}

void sub_281290(X86Context& ctx, uint8_t* base) {
	// 0x281290: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x281298: movss [0x0056A59C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A59Cu, ctx.xmm[0].u32[0]);
	// 0x2812A0: ret
	return;
}

void sub_2812B0(X86Context& ctx, uint8_t* base) {
	// 0x2812B0: movss xmm0, dword ptr [0x0056A5B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A5B0u);
	// 0x2812B8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2812C0: movss [0x0056A5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A5E0u, ctx.xmm[0].u32[0]);
	// 0x2812C8: ret
	return;
}

void sub_2812D0(X86Context& ctx, uint8_t* base) {
	// 0x2812D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2812D8: movss [0x0056A664], xmm0
	X86_MEM_WRITE_u32(base, 0x56A664u, ctx.xmm[0].u32[0]);
	// 0x2812E0: ret
	return;
}

void sub_2812F0(X86Context& ctx, uint8_t* base) {
	// 0x2812F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2812F8: movss [0x0056A680], xmm0
	X86_MEM_WRITE_u32(base, 0x56A680u, ctx.xmm[0].u32[0]);
	// 0x281300: ret
	return;
}

void sub_281310(X86Context& ctx, uint8_t* base) {
	// 0x281310: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x281318: movss [0x0056A658], xmm0
	X86_MEM_WRITE_u32(base, 0x56A658u, ctx.xmm[0].u32[0]);
	// 0x281320: ret
	return;
}

void sub_281330(X86Context& ctx, uint8_t* base) {
	// 0x281330: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x281338: movss [0x0056A610], xmm0
	X86_MEM_WRITE_u32(base, 0x56A610u, ctx.xmm[0].u32[0]);
	// 0x281340: ret
	return;
}

void sub_281350(X86Context& ctx, uint8_t* base) {
	// 0x281350: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x281358: movss [0x0056A668], xmm0
	X86_MEM_WRITE_u32(base, 0x56A668u, ctx.xmm[0].u32[0]);
	// 0x281360: ret
	return;
}

void sub_281370(X86Context& ctx, uint8_t* base) {
	// 0x281370: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x281378: movss [0x0056A62C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A62Cu, ctx.xmm[0].u32[0]);
	// 0x281380: ret
	return;
}

void sub_281390(X86Context& ctx, uint8_t* base) {
	// 0x281390: movss xmm0, dword ptr [0x0056A668]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A668u);
	// 0x281398: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2813A0: movss [0x0056A6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6A0u, ctx.xmm[0].u32[0]);
	// 0x2813A8: ret
	return;
}

void sub_2813B0(X86Context& ctx, uint8_t* base) {
	// 0x2813B0: movss xmm0, dword ptr [0x0056A62C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A62Cu);
	// 0x2813B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2813C0: movss [0x0056A688], xmm0
	X86_MEM_WRITE_u32(base, 0x56A688u, ctx.xmm[0].u32[0]);
	// 0x2813C8: ret
	return;
}

void sub_2813D0(X86Context& ctx, uint8_t* base) {
	// 0x2813D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2813D8: movss [0x0056A6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6B8u, ctx.xmm[0].u32[0]);
	// 0x2813E0: ret
	return;
}

void sub_2813F0(X86Context& ctx, uint8_t* base) {
	// 0x2813F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2813F8: movss [0x0056A6A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6A4u, ctx.xmm[0].u32[0]);
	// 0x281400: ret
	return;
}

void sub_281410(X86Context& ctx, uint8_t* base) {
	// 0x281410: movss xmm0, dword ptr [0x0056A6A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6A4u);
	// 0x281418: movss [0x0056A6B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6B4u, ctx.xmm[0].u32[0]);
	// 0x281420: ret
	return;
}

void sub_281430(X86Context& ctx, uint8_t* base) {
	// 0x281430: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x281438: movss [0x0056A618], xmm0
	X86_MEM_WRITE_u32(base, 0x56A618u, ctx.xmm[0].u32[0]);
	// 0x281440: ret
	return;
}

void sub_281450(X86Context& ctx, uint8_t* base) {
	// 0x281450: movss xmm0, dword ptr [0x0056A62C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A62Cu);
	// 0x281458: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x281460: movss [0x0056A6AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6ACu, ctx.xmm[0].u32[0]);
	// 0x281468: ret
	return;
}

void sub_281470(X86Context& ctx, uint8_t* base) {
	// 0x281470: movss xmm0, dword ptr [0x0056A62C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A62Cu);
	// 0x281478: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x281480: movss [0x0056A654], xmm0
	X86_MEM_WRITE_u32(base, 0x56A654u, ctx.xmm[0].u32[0]);
	// 0x281488: ret
	return;
}

void sub_281490(X86Context& ctx, uint8_t* base) {
	// 0x281490: movss xmm0, dword ptr [0x0056A62C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A62Cu);
	// 0x281498: subss xmm0, [0x0056A654]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A654u);
	// 0x2814A0: movss [0x0056A634], xmm0
	X86_MEM_WRITE_u32(base, 0x56A634u, ctx.xmm[0].u32[0]);
	// 0x2814A8: ret
	return;
}

void sub_2814B0(X86Context& ctx, uint8_t* base) {
	// 0x2814B0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2814B8: movss [0x0056A67C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A67Cu, ctx.xmm[0].u32[0]);
	// 0x2814C0: ret
	return;
}

void sub_2814D0(X86Context& ctx, uint8_t* base) {
	// 0x2814D0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2814D8: movss [0x0056A630], xmm0
	X86_MEM_WRITE_u32(base, 0x56A630u, ctx.xmm[0].u32[0]);
	// 0x2814E0: ret
	return;
}

void sub_2814F0(X86Context& ctx, uint8_t* base) {
	// 0x2814F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2814F8: movss [0x0056A640], xmm0
	X86_MEM_WRITE_u32(base, 0x56A640u, ctx.xmm[0].u32[0]);
	// 0x281500: ret
	return;
}

void sub_281510(X86Context& ctx, uint8_t* base) {
	// 0x281510: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x281518: movss [0x0056A694], xmm0
	X86_MEM_WRITE_u32(base, 0x56A694u, ctx.xmm[0].u32[0]);
	// 0x281520: ret
	return;
}

void sub_281530(X86Context& ctx, uint8_t* base) {
	// 0x281530: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x281538: movss [0x0056A678], xmm0
	X86_MEM_WRITE_u32(base, 0x56A678u, ctx.xmm[0].u32[0]);
	// 0x281540: ret
	return;
}

void sub_281550(X86Context& ctx, uint8_t* base) {
	// 0x281550: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x281558: movss [0x0056A628], xmm0
	X86_MEM_WRITE_u32(base, 0x56A628u, ctx.xmm[0].u32[0]);
	// 0x281560: ret
	return;
}

void sub_281570(X86Context& ctx, uint8_t* base) {
	// 0x281570: movss xmm0, dword ptr [0x0056A640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A640u);
	// 0x281578: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281580: movss [0x0056A61C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A61Cu, ctx.xmm[0].u32[0]);
	// 0x281588: ret
	return;
}

void sub_281590(X86Context& ctx, uint8_t* base) {
	// 0x281590: movss xmm0, dword ptr [0x0056A694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A694u);
	// 0x281598: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2815A0: movss [0x0056A660], xmm0
	X86_MEM_WRITE_u32(base, 0x56A660u, ctx.xmm[0].u32[0]);
	// 0x2815A8: ret
	return;
}

void sub_2815B0(X86Context& ctx, uint8_t* base) {
	// 0x2815B0: movss xmm0, dword ptr [0x0056A61C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A61Cu);
	// 0x2815B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2815C0: movss [0x0056A670], xmm0
	X86_MEM_WRITE_u32(base, 0x56A670u, ctx.xmm[0].u32[0]);
	// 0x2815C8: ret
	return;
}

void sub_2815D0(X86Context& ctx, uint8_t* base) {
	// 0x2815D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2815D8: movss [0x0056A614], xmm0
	X86_MEM_WRITE_u32(base, 0x56A614u, ctx.xmm[0].u32[0]);
	// 0x2815E0: ret
	return;
}

void sub_2815F0(X86Context& ctx, uint8_t* base) {
	// 0x2815F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2815F8: movss [0x0056A644], xmm0
	X86_MEM_WRITE_u32(base, 0x56A644u, ctx.xmm[0].u32[0]);
	// 0x281600: ret
	return;
}

void sub_281610(X86Context& ctx, uint8_t* base) {
	// 0x281610: movss xmm0, dword ptr [0x0056A640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A640u);
	// 0x281618: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x281620: movss [0x0056A650], xmm0
	X86_MEM_WRITE_u32(base, 0x56A650u, ctx.xmm[0].u32[0]);
	// 0x281628: ret
	return;
}

void sub_281630(X86Context& ctx, uint8_t* base) {
	// 0x281630: movss xmm0, dword ptr [0x0056A694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A694u);
	// 0x281638: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x281640: movss [0x0056A698], xmm0
	X86_MEM_WRITE_u32(base, 0x56A698u, ctx.xmm[0].u32[0]);
	// 0x281648: ret
	return;
}

void sub_281650(X86Context& ctx, uint8_t* base) {
	// 0x281650: movss xmm0, dword ptr [0x0056A650]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A650u);
	// 0x281658: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281660: movss [0x0056A684], xmm0
	X86_MEM_WRITE_u32(base, 0x56A684u, ctx.xmm[0].u32[0]);
	// 0x281668: ret
	return;
}

void sub_281670(X86Context& ctx, uint8_t* base) {
	// 0x281670: movss xmm0, dword ptr [0x0056A698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A698u);
	// 0x281678: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281680: movss [0x0056A6A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6A8u, ctx.xmm[0].u32[0]);
	// 0x281688: ret
	return;
}

void sub_281690(X86Context& ctx, uint8_t* base) {
	// 0x281690: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x281698: movss [0x0056A620], xmm0
	X86_MEM_WRITE_u32(base, 0x56A620u, ctx.xmm[0].u32[0]);
	// 0x2816A0: ret
	return;
}

void sub_2816B0(X86Context& ctx, uint8_t* base) {
	// 0x2816B0: movss xmm0, dword ptr [0x0056A640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A640u);
	// 0x2816B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2816C0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2816C8: movss [0x0056A690], xmm0
	X86_MEM_WRITE_u32(base, 0x56A690u, ctx.xmm[0].u32[0]);
	// 0x2816D0: ret
	return;
}

void sub_2816E0(X86Context& ctx, uint8_t* base) {
	// 0x2816E0: movss xmm0, dword ptr [0x0056A694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A694u);
	// 0x2816E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2816F0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2816F8: movss [0x0056A638], xmm0
	X86_MEM_WRITE_u32(base, 0x56A638u, ctx.xmm[0].u32[0]);
	// 0x281700: ret
	return;
}

void sub_281710(X86Context& ctx, uint8_t* base) {
	// 0x281710: movss xmm0, dword ptr [0x0056A640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A640u);
	// 0x281718: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281720: movss [0x0056A63C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A63Cu, ctx.xmm[0].u32[0]);
	// 0x281728: ret
	return;
}

void sub_281730(X86Context& ctx, uint8_t* base) {
	// 0x281730: movss xmm0, dword ptr [0x0056A694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A694u);
	// 0x281738: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281740: movss [0x0056A69C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A69Cu, ctx.xmm[0].u32[0]);
	// 0x281748: ret
	return;
}

