#include "x86_recomp_shared.h"

void sub_2AA970(X86Context& ctx, uint8_t* base) {
	// 0x2AA970: movss xmm0, dword ptr [0x00570D7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D7Cu);
	// 0x2AA978: subss xmm0, [0x00570D54]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570D54u);
	// 0x2AA980: movss [0x00570D74], xmm0
	X86_MEM_WRITE_u32(base, 0x570D74u, ctx.xmm[0].u32[0]);
	// 0x2AA988: ret
	return;
}

void sub_2AA990(X86Context& ctx, uint8_t* base) {
	// 0x2AA990: movss xmm0, dword ptr [0x00570DA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DA4u);
	// 0x2AA998: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AA9A0: movss [0x00570D64], xmm0
	X86_MEM_WRITE_u32(base, 0x570D64u, ctx.xmm[0].u32[0]);
	// 0x2AA9A8: ret
	return;
}

void sub_2AA9B0(X86Context& ctx, uint8_t* base) {
	// 0x2AA9B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AA9B8: movss [0x00570D50], xmm0
	X86_MEM_WRITE_u32(base, 0x570D50u, ctx.xmm[0].u32[0]);
	// 0x2AA9C0: ret
	return;
}

void sub_2AA9D0(X86Context& ctx, uint8_t* base) {
	// 0x2AA9D0: movss xmm0, dword ptr [0x00570D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D64u);
	// 0x2AA9D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AA9E0: movss [0x00570D94], xmm0
	X86_MEM_WRITE_u32(base, 0x570D94u, ctx.xmm[0].u32[0]);
	// 0x2AA9E8: ret
	return;
}

void sub_2AA9F0(X86Context& ctx, uint8_t* base) {
	// 0x2AA9F0: movss xmm0, dword ptr [0x00570D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D48u);
	// 0x2AA9F8: mulss xmm0, [0x003B1730]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1730u);
	// 0x2AAA00: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AAA08: movss [0x00570D40], xmm0
	X86_MEM_WRITE_u32(base, 0x570D40u, ctx.xmm[0].u32[0]);
	// 0x2AAA10: movss xmm0, dword ptr [0x00570D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D9Cu);
	// 0x2AAA18: mulss xmm0, [0x003B1A74]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A74u);
	// 0x2AAA20: movss [0x00570D44], xmm0
	X86_MEM_WRITE_u32(base, 0x570D44u, ctx.xmm[0].u32[0]);
	// 0x2AAA28: ret
	return;
}

void sub_2AAA30(X86Context& ctx, uint8_t* base) {
	// 0x2AAA30: movss xmm0, dword ptr [0x00570D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D48u);
	// 0x2AAA38: mulss xmm0, [0x003A55F8]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3A55F8u);
	// 0x2AAA40: movss [0x00407888], xmm0
	X86_MEM_WRITE_u32(base, 0x407888u, ctx.xmm[0].u32[0]);
	// 0x2AAA48: ret
	return;
}

void sub_2AAA50(X86Context& ctx, uint8_t* base) {
	// 0x2AAA50: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AAA58: movss [0x00570E40], xmm0
	X86_MEM_WRITE_u32(base, 0x570E40u, ctx.xmm[0].u32[0]);
	// 0x2AAA60: ret
	return;
}

void sub_2AAA70(X86Context& ctx, uint8_t* base) {
	// 0x2AAA70: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AAA78: movss [0x00570E64], xmm0
	X86_MEM_WRITE_u32(base, 0x570E64u, ctx.xmm[0].u32[0]);
	// 0x2AAA80: ret
	return;
}

void sub_2AAA90(X86Context& ctx, uint8_t* base) {
	// 0x2AAA90: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AAA98: movss [0x00570E30], xmm0
	X86_MEM_WRITE_u32(base, 0x570E30u, ctx.xmm[0].u32[0]);
	// 0x2AAAA0: ret
	return;
}

void sub_2AAAB0(X86Context& ctx, uint8_t* base) {
	// 0x2AAAB0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AAAB8: movss [0x00570DC4], xmm0
	X86_MEM_WRITE_u32(base, 0x570DC4u, ctx.xmm[0].u32[0]);
	// 0x2AAAC0: ret
	return;
}

void sub_2AAAD0(X86Context& ctx, uint8_t* base) {
	// 0x2AAAD0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AAAD8: movss [0x00570E44], xmm0
	X86_MEM_WRITE_u32(base, 0x570E44u, ctx.xmm[0].u32[0]);
	// 0x2AAAE0: ret
	return;
}

void sub_2AAAF0(X86Context& ctx, uint8_t* base) {
	// 0x2AAAF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AAAF8: movss [0x00570DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x570DE0u, ctx.xmm[0].u32[0]);
	// 0x2AAB00: ret
	return;
}

void sub_2AAB10(X86Context& ctx, uint8_t* base) {
	// 0x2AAB10: movss xmm0, dword ptr [0x00570E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E44u);
	// 0x2AAB18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AAB20: movss [0x00570ECC], xmm0
	X86_MEM_WRITE_u32(base, 0x570ECCu, ctx.xmm[0].u32[0]);
	// 0x2AAB28: ret
	return;
}

void sub_2AAB30(X86Context& ctx, uint8_t* base) {
	// 0x2AAB30: movss xmm0, dword ptr [0x00570DE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DE0u);
	// 0x2AAB38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AAB40: movss [0x00570E70], xmm0
	X86_MEM_WRITE_u32(base, 0x570E70u, ctx.xmm[0].u32[0]);
	// 0x2AAB48: ret
	return;
}

void sub_2AAB50(X86Context& ctx, uint8_t* base) {
	// 0x2AAB50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AAB58: movss [0x00570EE4], xmm0
	X86_MEM_WRITE_u32(base, 0x570EE4u, ctx.xmm[0].u32[0]);
	// 0x2AAB60: ret
	return;
}

void sub_2AAB70(X86Context& ctx, uint8_t* base) {
	// 0x2AAB70: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AAB78: movss [0x00570ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x570ED0u, ctx.xmm[0].u32[0]);
	// 0x2AAB80: ret
	return;
}

void sub_2AAB90(X86Context& ctx, uint8_t* base) {
	// 0x2AAB90: movss xmm0, dword ptr [0x00570ED0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570ED0u);
	// 0x2AAB98: movss [0x00570EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x570EE0u, ctx.xmm[0].u32[0]);
	// 0x2AABA0: ret
	return;
}

void sub_2AABB0(X86Context& ctx, uint8_t* base) {
	// 0x2AABB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AABB8: movss [0x00570DCC], xmm0
	X86_MEM_WRITE_u32(base, 0x570DCCu, ctx.xmm[0].u32[0]);
	// 0x2AABC0: ret
	return;
}

void sub_2AABD0(X86Context& ctx, uint8_t* base) {
	// 0x2AABD0: movss xmm0, dword ptr [0x00570DE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DE0u);
	// 0x2AABD8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AABE0: movss [0x00570ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x570ED8u, ctx.xmm[0].u32[0]);
	// 0x2AABE8: ret
	return;
}

void sub_2AABF0(X86Context& ctx, uint8_t* base) {
	// 0x2AABF0: movss xmm0, dword ptr [0x00570DE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DE0u);
	// 0x2AABF8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AAC00: movss [0x00570E2C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E2Cu, ctx.xmm[0].u32[0]);
	// 0x2AAC08: ret
	return;
}

void sub_2AAC10(X86Context& ctx, uint8_t* base) {
	// 0x2AAC10: movss xmm0, dword ptr [0x00570DE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DE0u);
	// 0x2AAC18: subss xmm0, [0x00570E2C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570E2Cu);
	// 0x2AAC20: movss [0x00570DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x570DF0u, ctx.xmm[0].u32[0]);
	// 0x2AAC28: ret
	return;
}

void sub_2AAC30(X86Context& ctx, uint8_t* base) {
	// 0x2AAC30: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AAC38: movss [0x00570E60], xmm0
	X86_MEM_WRITE_u32(base, 0x570E60u, ctx.xmm[0].u32[0]);
	// 0x2AAC40: ret
	return;
}

void sub_2AAC50(X86Context& ctx, uint8_t* base) {
	// 0x2AAC50: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AAC58: movss [0x00570DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x570DE8u, ctx.xmm[0].u32[0]);
	// 0x2AAC60: ret
	return;
}

void sub_2AAC70(X86Context& ctx, uint8_t* base) {
	// 0x2AAC70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AAC78: movss [0x00570E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E0Cu, ctx.xmm[0].u32[0]);
	// 0x2AAC80: ret
	return;
}

void sub_2AAC90(X86Context& ctx, uint8_t* base) {
	// 0x2AAC90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AAC98: movss [0x00570EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x570EC0u, ctx.xmm[0].u32[0]);
	// 0x2AACA0: ret
	return;
}

void sub_2AACB0(X86Context& ctx, uint8_t* base) {
	// 0x2AACB0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AACB8: movss [0x00570E54], xmm0
	X86_MEM_WRITE_u32(base, 0x570E54u, ctx.xmm[0].u32[0]);
	// 0x2AACC0: ret
	return;
}

void sub_2AACD0(X86Context& ctx, uint8_t* base) {
	// 0x2AACD0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AACD8: movss [0x00570DDC], xmm0
	X86_MEM_WRITE_u32(base, 0x570DDCu, ctx.xmm[0].u32[0]);
	// 0x2AACE0: ret
	return;
}

void sub_2AACF0(X86Context& ctx, uint8_t* base) {
	// 0x2AACF0: movss xmm0, dword ptr [0x00570E0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E0Cu);
	// 0x2AACF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AAD00: movss [0x00570DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x570DD0u, ctx.xmm[0].u32[0]);
	// 0x2AAD08: ret
	return;
}

void sub_2AAD10(X86Context& ctx, uint8_t* base) {
	// 0x2AAD10: movss xmm0, dword ptr [0x00570EC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC0u);
	// 0x2AAD18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AAD20: movss [0x00570E38], xmm0
	X86_MEM_WRITE_u32(base, 0x570E38u, ctx.xmm[0].u32[0]);
	// 0x2AAD28: ret
	return;
}

void sub_2AAD30(X86Context& ctx, uint8_t* base) {
	// 0x2AAD30: movss xmm0, dword ptr [0x00570DD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DD0u);
	// 0x2AAD38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AAD40: movss [0x00570E4C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E4Cu, ctx.xmm[0].u32[0]);
	// 0x2AAD48: ret
	return;
}

void sub_2AAD50(X86Context& ctx, uint8_t* base) {
	// 0x2AAD50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AAD58: movss [0x00570DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x570DC8u, ctx.xmm[0].u32[0]);
	// 0x2AAD60: ret
	return;
}

void sub_2AAD70(X86Context& ctx, uint8_t* base) {
	// 0x2AAD70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AAD78: movss [0x00570E10], xmm0
	X86_MEM_WRITE_u32(base, 0x570E10u, ctx.xmm[0].u32[0]);
	// 0x2AAD80: ret
	return;
}

void sub_2AAD90(X86Context& ctx, uint8_t* base) {
	// 0x2AAD90: movss xmm0, dword ptr [0x00570E0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E0Cu);
	// 0x2AAD98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AADA0: movss [0x00570E24], xmm0
	X86_MEM_WRITE_u32(base, 0x570E24u, ctx.xmm[0].u32[0]);
	// 0x2AADA8: ret
	return;
}

void sub_2AADB0(X86Context& ctx, uint8_t* base) {
	// 0x2AADB0: movss xmm0, dword ptr [0x00570EC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC0u);
	// 0x2AADB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AADC0: movss [0x00570EC4], xmm0
	X86_MEM_WRITE_u32(base, 0x570EC4u, ctx.xmm[0].u32[0]);
	// 0x2AADC8: ret
	return;
}

void sub_2AADD0(X86Context& ctx, uint8_t* base) {
	// 0x2AADD0: movss xmm0, dword ptr [0x00570E24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E24u);
	// 0x2AADD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AADE0: movss [0x00570E68], xmm0
	X86_MEM_WRITE_u32(base, 0x570E68u, ctx.xmm[0].u32[0]);
	// 0x2AADE8: ret
	return;
}

void sub_2AADF0(X86Context& ctx, uint8_t* base) {
	// 0x2AADF0: movss xmm0, dword ptr [0x00570EC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC4u);
	// 0x2AADF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AAE00: movss [0x00570ED4], xmm0
	X86_MEM_WRITE_u32(base, 0x570ED4u, ctx.xmm[0].u32[0]);
	// 0x2AAE08: ret
	return;
}

void sub_2AAE10(X86Context& ctx, uint8_t* base) {
	// 0x2AAE10: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AAE18: movss [0x00570DD4], xmm0
	X86_MEM_WRITE_u32(base, 0x570DD4u, ctx.xmm[0].u32[0]);
	// 0x2AAE20: ret
	return;
}

void sub_2AAE30(X86Context& ctx, uint8_t* base) {
	// 0x2AAE30: movss xmm0, dword ptr [0x00570E0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E0Cu);
	// 0x2AAE38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AAE40: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AAE48: movss [0x00570E78], xmm0
	X86_MEM_WRITE_u32(base, 0x570E78u, ctx.xmm[0].u32[0]);
	// 0x2AAE50: ret
	return;
}

void sub_2AAE60(X86Context& ctx, uint8_t* base) {
	// 0x2AAE60: movss xmm0, dword ptr [0x00570EC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC0u);
	// 0x2AAE68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AAE70: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AAE78: movss [0x00570DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x570DF4u, ctx.xmm[0].u32[0]);
	// 0x2AAE80: ret
	return;
}

void sub_2AAE90(X86Context& ctx, uint8_t* base) {
	// 0x2AAE90: movss xmm0, dword ptr [0x00570E0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E0Cu);
	// 0x2AAE98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AAEA0: movss [0x00570E00], xmm0
	X86_MEM_WRITE_u32(base, 0x570E00u, ctx.xmm[0].u32[0]);
	// 0x2AAEA8: ret
	return;
}

void sub_2AAEB0(X86Context& ctx, uint8_t* base) {
	// 0x2AAEB0: movss xmm0, dword ptr [0x00570EC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC0u);
	// 0x2AAEB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AAEC0: movss [0x00570EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x570EC8u, ctx.xmm[0].u32[0]);
	// 0x2AAEC8: ret
	return;
}

void sub_2AAED0(X86Context& ctx, uint8_t* base) {
	// 0x2AAED0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AAED8: movss [0x00570DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x570DD8u, ctx.xmm[0].u32[0]);
	// 0x2AAEE0: ret
	return;
}

void sub_2AAEF0(X86Context& ctx, uint8_t* base) {
	// 0x2AAEF0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AAEF8: movss [0x00570E20], xmm0
	X86_MEM_WRITE_u32(base, 0x570E20u, ctx.xmm[0].u32[0]);
	// 0x2AAF00: ret
	return;
}

void sub_2AAF10(X86Context& ctx, uint8_t* base) {
	// 0x2AAF10: movss xmm0, dword ptr [0x00570DD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DD8u);
	// 0x2AAF18: movss [0x00570EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x570EDCu, ctx.xmm[0].u32[0]);
	// 0x2AAF20: ret
	return;
}

void sub_2AAF30(X86Context& ctx, uint8_t* base) {
	// 0x2AAF30: movss xmm0, dword ptr [0x00570EC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC0u);
	// 0x2AAF38: subss xmm0, [0x00570DD8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570DD8u);
	// 0x2AAF40: movss [0x00570E50], xmm0
	X86_MEM_WRITE_u32(base, 0x570E50u, ctx.xmm[0].u32[0]);
	// 0x2AAF48: ret
	return;
}

void sub_2AAF50(X86Context& ctx, uint8_t* base) {
	// 0x2AAF50: movss xmm0, dword ptr [0x00570E50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E50u);
	// 0x2AAF58: subss xmm0, [0x00570E20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570E20u);
	// 0x2AAF60: movss [0x00570E48], xmm0
	X86_MEM_WRITE_u32(base, 0x570E48u, ctx.xmm[0].u32[0]);
	// 0x2AAF68: ret
	return;
}

void sub_2AAF70(X86Context& ctx, uint8_t* base) {
	// 0x2AAF70: movss xmm0, dword ptr [0x00570EC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EC8u);
	// 0x2AAF78: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AAF80: movss [0x00570E34], xmm0
	X86_MEM_WRITE_u32(base, 0x570E34u, ctx.xmm[0].u32[0]);
	// 0x2AAF88: ret
	return;
}

void sub_2AAF90(X86Context& ctx, uint8_t* base) {
	// 0x2AAF90: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AAF98: movss [0x00570E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E1Cu, ctx.xmm[0].u32[0]);
	// 0x2AAFA0: ret
	return;
}

void sub_2AAFB0(X86Context& ctx, uint8_t* base) {
	// 0x2AAFB0: movss xmm0, dword ptr [0x00570E34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E34u);
	// 0x2AAFB8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AAFC0: movss [0x00570E74], xmm0
	X86_MEM_WRITE_u32(base, 0x570E74u, ctx.xmm[0].u32[0]);
	// 0x2AAFC8: ret
	return;
}

void sub_2AAFD0(X86Context& ctx, uint8_t* base) {
	// 0x2AAFD0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2AAFD8: movss [0x00570E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E3Cu, ctx.xmm[0].u32[0]);
	// 0x2AAFE0: ret
	return;
}

void sub_2AAFF0(X86Context& ctx, uint8_t* base) {
	// 0x2AAFF0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2AAFF8: movss [0x00570E04], xmm0
	X86_MEM_WRITE_u32(base, 0x570E04u, ctx.xmm[0].u32[0]);
	// 0x2AB000: ret
	return;
}

void sub_2AB010(X86Context& ctx, uint8_t* base) {
	// 0x2AB010: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x2AB018: movss [0x00570E28], xmm0
	X86_MEM_WRITE_u32(base, 0x570E28u, ctx.xmm[0].u32[0]);
	// 0x2AB020: ret
	return;
}

void sub_2AB030(X86Context& ctx, uint8_t* base) {
	// 0x2AB030: movss xmm0, dword ptr [0x003A292C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A292Cu);
	// 0x2AB038: movss [0x00570E6C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E6Cu, ctx.xmm[0].u32[0]);
	// 0x2AB040: ret
	return;
}

void sub_2AB050(X86Context& ctx, uint8_t* base) {
	// 0x2AB050: movss xmm0, dword ptr [0x003B1C6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C6Cu);
	// 0x2AB058: movss [0x00570DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x570DE4u, ctx.xmm[0].u32[0]);
	// 0x2AB060: ret
	return;
}

void sub_2AB070(X86Context& ctx, uint8_t* base) {
	// 0x2AB070: movss xmm0, dword ptr [0x003B22B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B4u);
	// 0x2AB078: movss [0x00570DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x570DF8u, ctx.xmm[0].u32[0]);
	// 0x2AB080: ret
	return;
}

void sub_2AB090(X86Context& ctx, uint8_t* base) {
	// 0x2AB090: movss xmm0, dword ptr [0x003B22B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B8u);
	// 0x2AB098: movss [0x00570E5C], xmm0
	X86_MEM_WRITE_u32(base, 0x570E5Cu, ctx.xmm[0].u32[0]);
	// 0x2AB0A0: ret
	return;
}

void sub_2AB0B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB0B0: movss xmm0, dword ptr [0x00570E28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E28u);
	// 0x2AB0B8: addss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AB0C0: movss [0x00570E08], xmm0
	X86_MEM_WRITE_u32(base, 0x570E08u, ctx.xmm[0].u32[0]);
	// 0x2AB0C8: ret
	return;
}

void sub_2AB0D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB0D0: movss xmm0, dword ptr [0x00570E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570E6Cu);
	// 0x2AB0D8: addss xmm0, [0x003B1708]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1708u);
	// 0x2AB0E0: movss [0x00570DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x570DFCu, ctx.xmm[0].u32[0]);
	// 0x2AB0E8: ret
	return;
}

void sub_2AB0F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB0F0: movss xmm0, dword ptr [0x00570DE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DE4u);
	// 0x2AB0F8: addss xmm0, [0x003B1708]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1708u);
	// 0x2AB100: movss [0x00570E14], xmm0
	X86_MEM_WRITE_u32(base, 0x570E14u, ctx.xmm[0].u32[0]);
	// 0x2AB108: ret
	return;
}

void sub_2AB110(X86Context& ctx, uint8_t* base) {
	// 0x2AB110: movss xmm0, dword ptr [0x003B20E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B20E8u);
	// 0x2AB118: movss [0x00570DEC], xmm0
	X86_MEM_WRITE_u32(base, 0x570DECu, ctx.xmm[0].u32[0]);
	// 0x2AB120: ret
	return;
}

void sub_2AB130(X86Context& ctx, uint8_t* base) {
	// 0x2AB130: movss xmm0, dword ptr [0x003B16D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D8u);
	// 0x2AB138: movss [0x00570E58], xmm0
	X86_MEM_WRITE_u32(base, 0x570E58u, ctx.xmm[0].u32[0]);
	// 0x2AB140: ret
	return;
}

void sub_2AB150(X86Context& ctx, uint8_t* base) {
	// 0x2AB150: movss xmm0, dword ptr [0x00570DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DECu);
	// 0x2AB158: subss xmm0, [0x003A7F34]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7F34u);
	// 0x2AB160: movss [0x00570E18], xmm0
	X86_MEM_WRITE_u32(base, 0x570E18u, ctx.xmm[0].u32[0]);
	// 0x2AB168: ret
	return;
}

void sub_2AB170(X86Context& ctx, uint8_t* base) {
	// 0x2AB170: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AB178: movss [0x00570F58], xmm0
	X86_MEM_WRITE_u32(base, 0x570F58u, ctx.xmm[0].u32[0]);
	// 0x2AB180: ret
	return;
}

void sub_2AB190(X86Context& ctx, uint8_t* base) {
	// 0x2AB190: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AB198: movss [0x00570F74], xmm0
	X86_MEM_WRITE_u32(base, 0x570F74u, ctx.xmm[0].u32[0]);
	// 0x2AB1A0: ret
	return;
}

void sub_2AB1B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB1B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AB1B8: movss [0x00570F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F4Cu, ctx.xmm[0].u32[0]);
	// 0x2AB1C0: ret
	return;
}

void sub_2AB1D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB1D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AB1D8: movss [0x00570EE8], xmm0
	X86_MEM_WRITE_u32(base, 0x570EE8u, ctx.xmm[0].u32[0]);
	// 0x2AB1E0: ret
	return;
}

void sub_2AB1F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB1F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AB1F8: movss [0x00570F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F5Cu, ctx.xmm[0].u32[0]);
	// 0x2AB200: ret
	return;
}

void sub_2AB210(X86Context& ctx, uint8_t* base) {
	// 0x2AB210: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AB218: movss [0x00570F04], xmm0
	X86_MEM_WRITE_u32(base, 0x570F04u, ctx.xmm[0].u32[0]);
	// 0x2AB220: ret
	return;
}

void sub_2AB230(X86Context& ctx, uint8_t* base) {
	// 0x2AB230: movss xmm0, dword ptr [0x00570F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F5Cu);
	// 0x2AB238: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AB240: movss [0x00570F94], xmm0
	X86_MEM_WRITE_u32(base, 0x570F94u, ctx.xmm[0].u32[0]);
	// 0x2AB248: ret
	return;
}

void sub_2AB250(X86Context& ctx, uint8_t* base) {
	// 0x2AB250: movss xmm0, dword ptr [0x00570F04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F04u);
	// 0x2AB258: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AB260: movss [0x00570F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F7Cu, ctx.xmm[0].u32[0]);
	// 0x2AB268: ret
	return;
}

void sub_2AB270(X86Context& ctx, uint8_t* base) {
	// 0x2AB270: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AB278: movss [0x00570FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x570FB0u, ctx.xmm[0].u32[0]);
	// 0x2AB280: ret
	return;
}

void sub_2AB290(X86Context& ctx, uint8_t* base) {
	// 0x2AB290: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AB298: movss [0x00570F98], xmm0
	X86_MEM_WRITE_u32(base, 0x570F98u, ctx.xmm[0].u32[0]);
	// 0x2AB2A0: ret
	return;
}

void sub_2AB2B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB2B0: movss xmm0, dword ptr [0x00570F98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F98u);
	// 0x2AB2B8: movss [0x00570FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x570FACu, ctx.xmm[0].u32[0]);
	// 0x2AB2C0: ret
	return;
}

void sub_2AB2D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB2D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AB2D8: movss [0x00570EF0], xmm0
	X86_MEM_WRITE_u32(base, 0x570EF0u, ctx.xmm[0].u32[0]);
	// 0x2AB2E0: ret
	return;
}

void sub_2AB2F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB2F0: movss xmm0, dword ptr [0x00570F04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F04u);
	// 0x2AB2F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AB300: movss [0x00570FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x570FA4u, ctx.xmm[0].u32[0]);
	// 0x2AB308: ret
	return;
}

void sub_2AB310(X86Context& ctx, uint8_t* base) {
	// 0x2AB310: movss xmm0, dword ptr [0x00570F04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F04u);
	// 0x2AB318: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AB320: movss [0x00570F48], xmm0
	X86_MEM_WRITE_u32(base, 0x570F48u, ctx.xmm[0].u32[0]);
	// 0x2AB328: ret
	return;
}

void sub_2AB330(X86Context& ctx, uint8_t* base) {
	// 0x2AB330: movss xmm0, dword ptr [0x00570F04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F04u);
	// 0x2AB338: subss xmm0, [0x00570F48]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570F48u);
	// 0x2AB340: movss [0x00570F28], xmm0
	X86_MEM_WRITE_u32(base, 0x570F28u, ctx.xmm[0].u32[0]);
	// 0x2AB348: ret
	return;
}

void sub_2AB350(X86Context& ctx, uint8_t* base) {
	// 0x2AB350: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AB358: movss [0x00570F70], xmm0
	X86_MEM_WRITE_u32(base, 0x570F70u, ctx.xmm[0].u32[0]);
	// 0x2AB360: ret
	return;
}

void sub_2AB370(X86Context& ctx, uint8_t* base) {
	// 0x2AB370: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AB378: movss [0x00570F08], xmm0
	X86_MEM_WRITE_u32(base, 0x570F08u, ctx.xmm[0].u32[0]);
	// 0x2AB380: ret
	return;
}

void sub_2AB390(X86Context& ctx, uint8_t* base) {
	// 0x2AB390: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AB398: movss [0x00570F34], xmm0
	X86_MEM_WRITE_u32(base, 0x570F34u, ctx.xmm[0].u32[0]);
	// 0x2AB3A0: ret
	return;
}

void sub_2AB3B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB3B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AB3B8: movss [0x00570F88], xmm0
	X86_MEM_WRITE_u32(base, 0x570F88u, ctx.xmm[0].u32[0]);
	// 0x2AB3C0: ret
	return;
}

void sub_2AB3D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB3D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AB3D8: movss [0x00570F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F6Cu, ctx.xmm[0].u32[0]);
	// 0x2AB3E0: ret
	return;
}

void sub_2AB3F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB3F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AB3F8: movss [0x00570F00], xmm0
	X86_MEM_WRITE_u32(base, 0x570F00u, ctx.xmm[0].u32[0]);
	// 0x2AB400: ret
	return;
}

void sub_2AB410(X86Context& ctx, uint8_t* base) {
	// 0x2AB410: movss xmm0, dword ptr [0x00570F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F34u);
	// 0x2AB418: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AB420: movss [0x00570EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x570EF4u, ctx.xmm[0].u32[0]);
	// 0x2AB428: ret
	return;
}

void sub_2AB430(X86Context& ctx, uint8_t* base) {
	// 0x2AB430: movss xmm0, dword ptr [0x00570F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F88u);
	// 0x2AB438: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AB440: movss [0x00570F54], xmm0
	X86_MEM_WRITE_u32(base, 0x570F54u, ctx.xmm[0].u32[0]);
	// 0x2AB448: ret
	return;
}

void sub_2AB450(X86Context& ctx, uint8_t* base) {
	// 0x2AB450: movss xmm0, dword ptr [0x00570EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EF4u);
	// 0x2AB458: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AB460: movss [0x00570F64], xmm0
	X86_MEM_WRITE_u32(base, 0x570F64u, ctx.xmm[0].u32[0]);
	// 0x2AB468: ret
	return;
}

void sub_2AB470(X86Context& ctx, uint8_t* base) {
	// 0x2AB470: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AB478: movss [0x00570EEC], xmm0
	X86_MEM_WRITE_u32(base, 0x570EECu, ctx.xmm[0].u32[0]);
	// 0x2AB480: ret
	return;
}

void sub_2AB490(X86Context& ctx, uint8_t* base) {
	// 0x2AB490: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AB498: movss [0x00570F38], xmm0
	X86_MEM_WRITE_u32(base, 0x570F38u, ctx.xmm[0].u32[0]);
	// 0x2AB4A0: ret
	return;
}

void sub_2AB4B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB4B0: movss xmm0, dword ptr [0x00570F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F34u);
	// 0x2AB4B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AB4C0: movss [0x00570F44], xmm0
	X86_MEM_WRITE_u32(base, 0x570F44u, ctx.xmm[0].u32[0]);
	// 0x2AB4C8: ret
	return;
}

void sub_2AB4D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB4D0: movss xmm0, dword ptr [0x00570F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F88u);
	// 0x2AB4D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AB4E0: movss [0x00570F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F8Cu, ctx.xmm[0].u32[0]);
	// 0x2AB4E8: ret
	return;
}

void sub_2AB4F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB4F0: movss xmm0, dword ptr [0x00570F44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F44u);
	// 0x2AB4F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AB500: movss [0x00570F78], xmm0
	X86_MEM_WRITE_u32(base, 0x570F78u, ctx.xmm[0].u32[0]);
	// 0x2AB508: ret
	return;
}

void sub_2AB510(X86Context& ctx, uint8_t* base) {
	// 0x2AB510: movss xmm0, dword ptr [0x00570F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F8Cu);
	// 0x2AB518: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AB520: movss [0x00570F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F9Cu, ctx.xmm[0].u32[0]);
	// 0x2AB528: ret
	return;
}

void sub_2AB530(X86Context& ctx, uint8_t* base) {
	// 0x2AB530: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AB538: movss [0x00570EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x570EF8u, ctx.xmm[0].u32[0]);
	// 0x2AB540: ret
	return;
}

void sub_2AB550(X86Context& ctx, uint8_t* base) {
	// 0x2AB550: movss xmm0, dword ptr [0x00570F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F34u);
	// 0x2AB558: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AB560: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AB568: movss [0x00570F84], xmm0
	X86_MEM_WRITE_u32(base, 0x570F84u, ctx.xmm[0].u32[0]);
	// 0x2AB570: ret
	return;
}

void sub_2AB580(X86Context& ctx, uint8_t* base) {
	// 0x2AB580: movss xmm0, dword ptr [0x00570F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F88u);
	// 0x2AB588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AB590: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AB598: movss [0x00570F2C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F2Cu, ctx.xmm[0].u32[0]);
	// 0x2AB5A0: ret
	return;
}

void sub_2AB5B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB5B0: movss xmm0, dword ptr [0x00570F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F34u);
	// 0x2AB5B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AB5C0: movss [0x00570F30], xmm0
	X86_MEM_WRITE_u32(base, 0x570F30u, ctx.xmm[0].u32[0]);
	// 0x2AB5C8: ret
	return;
}

void sub_2AB5D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB5D0: movss xmm0, dword ptr [0x00570F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F88u);
	// 0x2AB5D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AB5E0: movss [0x00570F90], xmm0
	X86_MEM_WRITE_u32(base, 0x570F90u, ctx.xmm[0].u32[0]);
	// 0x2AB5E8: ret
	return;
}

void sub_2AB5F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB5F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AB5F8: movss [0x00570EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x570EFCu, ctx.xmm[0].u32[0]);
	// 0x2AB600: ret
	return;
}

void sub_2AB610(X86Context& ctx, uint8_t* base) {
	// 0x2AB610: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AB618: movss [0x00570F40], xmm0
	X86_MEM_WRITE_u32(base, 0x570F40u, ctx.xmm[0].u32[0]);
	// 0x2AB620: ret
	return;
}

void sub_2AB630(X86Context& ctx, uint8_t* base) {
	// 0x2AB630: movss xmm0, dword ptr [0x00570EFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570EFCu);
	// 0x2AB638: movss [0x00570FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x570FA8u, ctx.xmm[0].u32[0]);
	// 0x2AB640: ret
	return;
}

void sub_2AB650(X86Context& ctx, uint8_t* base) {
	// 0x2AB650: movss xmm0, dword ptr [0x00570F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F88u);
	// 0x2AB658: subss xmm0, [0x00570EFC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570EFCu);
	// 0x2AB660: movss [0x00570F68], xmm0
	X86_MEM_WRITE_u32(base, 0x570F68u, ctx.xmm[0].u32[0]);
	// 0x2AB668: ret
	return;
}

void sub_2AB670(X86Context& ctx, uint8_t* base) {
	// 0x2AB670: movss xmm0, dword ptr [0x00570F68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F68u);
	// 0x2AB678: subss xmm0, [0x00570F40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570F40u);
	// 0x2AB680: movss [0x00570F60], xmm0
	X86_MEM_WRITE_u32(base, 0x570F60u, ctx.xmm[0].u32[0]);
	// 0x2AB688: ret
	return;
}

void sub_2AB690(X86Context& ctx, uint8_t* base) {
	// 0x2AB690: movss xmm0, dword ptr [0x00570F90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F90u);
	// 0x2AB698: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AB6A0: movss [0x00570F50], xmm0
	X86_MEM_WRITE_u32(base, 0x570F50u, ctx.xmm[0].u32[0]);
	// 0x2AB6A8: ret
	return;
}

void sub_2AB6B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB6B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AB6B8: movss [0x00570F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x570F3Cu, ctx.xmm[0].u32[0]);
	// 0x2AB6C0: ret
	return;
}

void sub_2AB6D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB6D0: movss xmm0, dword ptr [0x00570F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570F50u);
	// 0x2AB6D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AB6E0: movss [0x00570F80], xmm0
	X86_MEM_WRITE_u32(base, 0x570F80u, ctx.xmm[0].u32[0]);
	// 0x2AB6E8: ret
	return;
}

void sub_2AB6F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB6F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AB6F8: movss [0x00570FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x570FA0u, ctx.xmm[0].u32[0]);
	// 0x2AB700: ret
	return;
}

void sub_2AB710(X86Context& ctx, uint8_t* base) {
	// 0x2AB710: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AB718: movss [0x00571008], xmm0
	X86_MEM_WRITE_u32(base, 0x571008u, ctx.xmm[0].u32[0]);
	// 0x2AB720: ret
	return;
}

void sub_2AB730(X86Context& ctx, uint8_t* base) {
	// 0x2AB730: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AB738: movss [0x00571024], xmm0
	X86_MEM_WRITE_u32(base, 0x571024u, ctx.xmm[0].u32[0]);
	// 0x2AB740: ret
	return;
}

void sub_2AB750(X86Context& ctx, uint8_t* base) {
	// 0x2AB750: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AB758: movss [0x00570FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x570FFCu, ctx.xmm[0].u32[0]);
	// 0x2AB760: ret
	return;
}

void sub_2AB770(X86Context& ctx, uint8_t* base) {
	// 0x2AB770: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AB778: movss [0x00570FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x570FB4u, ctx.xmm[0].u32[0]);
	// 0x2AB780: ret
	return;
}

void sub_2AB790(X86Context& ctx, uint8_t* base) {
	// 0x2AB790: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AB798: movss [0x0057100C], xmm0
	X86_MEM_WRITE_u32(base, 0x57100Cu, ctx.xmm[0].u32[0]);
	// 0x2AB7A0: ret
	return;
}

void sub_2AB7B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB7B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AB7B8: movss [0x00570FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x570FD0u, ctx.xmm[0].u32[0]);
	// 0x2AB7C0: ret
	return;
}

void sub_2AB7D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB7D0: movss xmm0, dword ptr [0x0057100C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57100Cu);
	// 0x2AB7D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AB7E0: movss [0x00571044], xmm0
	X86_MEM_WRITE_u32(base, 0x571044u, ctx.xmm[0].u32[0]);
	// 0x2AB7E8: ret
	return;
}

void sub_2AB7F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB7F0: movss xmm0, dword ptr [0x00570FD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FD0u);
	// 0x2AB7F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AB800: movss [0x0057102C], xmm0
	X86_MEM_WRITE_u32(base, 0x57102Cu, ctx.xmm[0].u32[0]);
	// 0x2AB808: ret
	return;
}

void sub_2AB810(X86Context& ctx, uint8_t* base) {
	// 0x2AB810: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AB818: movss [0x0057105C], xmm0
	X86_MEM_WRITE_u32(base, 0x57105Cu, ctx.xmm[0].u32[0]);
	// 0x2AB820: ret
	return;
}

void sub_2AB830(X86Context& ctx, uint8_t* base) {
	// 0x2AB830: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AB838: movss [0x00571048], xmm0
	X86_MEM_WRITE_u32(base, 0x571048u, ctx.xmm[0].u32[0]);
	// 0x2AB840: ret
	return;
}

void sub_2AB850(X86Context& ctx, uint8_t* base) {
	// 0x2AB850: movss xmm0, dword ptr [0x00571048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571048u);
	// 0x2AB858: movss [0x00571058], xmm0
	X86_MEM_WRITE_u32(base, 0x571058u, ctx.xmm[0].u32[0]);
	// 0x2AB860: ret
	return;
}

void sub_2AB870(X86Context& ctx, uint8_t* base) {
	// 0x2AB870: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AB878: movss [0x00570FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x570FBCu, ctx.xmm[0].u32[0]);
	// 0x2AB880: ret
	return;
}

void sub_2AB890(X86Context& ctx, uint8_t* base) {
	// 0x2AB890: movss xmm0, dword ptr [0x00570FD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FD0u);
	// 0x2AB898: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AB8A0: movss [0x00571050], xmm0
	X86_MEM_WRITE_u32(base, 0x571050u, ctx.xmm[0].u32[0]);
	// 0x2AB8A8: ret
	return;
}

void sub_2AB8B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB8B0: movss xmm0, dword ptr [0x00570FD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FD0u);
	// 0x2AB8B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AB8C0: movss [0x00570FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x570FF8u, ctx.xmm[0].u32[0]);
	// 0x2AB8C8: ret
	return;
}

void sub_2AB8D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB8D0: movss xmm0, dword ptr [0x00570FD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FD0u);
	// 0x2AB8D8: subss xmm0, [0x00570FF8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570FF8u);
	// 0x2AB8E0: movss [0x00570FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x570FD8u, ctx.xmm[0].u32[0]);
	// 0x2AB8E8: ret
	return;
}

void sub_2AB8F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB8F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AB8F8: movss [0x00571020], xmm0
	X86_MEM_WRITE_u32(base, 0x571020u, ctx.xmm[0].u32[0]);
	// 0x2AB900: ret
	return;
}

void sub_2AB910(X86Context& ctx, uint8_t* base) {
	// 0x2AB910: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AB918: movss [0x00570FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x570FD4u, ctx.xmm[0].u32[0]);
	// 0x2AB920: ret
	return;
}

void sub_2AB930(X86Context& ctx, uint8_t* base) {
	// 0x2AB930: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AB938: movss [0x00570FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x570FE4u, ctx.xmm[0].u32[0]);
	// 0x2AB940: ret
	return;
}

void sub_2AB950(X86Context& ctx, uint8_t* base) {
	// 0x2AB950: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AB958: movss [0x00571038], xmm0
	X86_MEM_WRITE_u32(base, 0x571038u, ctx.xmm[0].u32[0]);
	// 0x2AB960: ret
	return;
}

void sub_2AB970(X86Context& ctx, uint8_t* base) {
	// 0x2AB970: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AB978: movss [0x0057101C], xmm0
	X86_MEM_WRITE_u32(base, 0x57101Cu, ctx.xmm[0].u32[0]);
	// 0x2AB980: ret
	return;
}

void sub_2AB990(X86Context& ctx, uint8_t* base) {
	// 0x2AB990: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AB998: movss [0x00570FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x570FCCu, ctx.xmm[0].u32[0]);
	// 0x2AB9A0: ret
	return;
}

void sub_2AB9B0(X86Context& ctx, uint8_t* base) {
	// 0x2AB9B0: movss xmm0, dword ptr [0x00570FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FE4u);
	// 0x2AB9B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AB9C0: movss [0x00570FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x570FC0u, ctx.xmm[0].u32[0]);
	// 0x2AB9C8: ret
	return;
}

void sub_2AB9D0(X86Context& ctx, uint8_t* base) {
	// 0x2AB9D0: movss xmm0, dword ptr [0x00571038]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571038u);
	// 0x2AB9D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AB9E0: movss [0x00571004], xmm0
	X86_MEM_WRITE_u32(base, 0x571004u, ctx.xmm[0].u32[0]);
	// 0x2AB9E8: ret
	return;
}

void sub_2AB9F0(X86Context& ctx, uint8_t* base) {
	// 0x2AB9F0: movss xmm0, dword ptr [0x00570FC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FC0u);
	// 0x2AB9F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ABA00: movss [0x00571014], xmm0
	X86_MEM_WRITE_u32(base, 0x571014u, ctx.xmm[0].u32[0]);
	// 0x2ABA08: ret
	return;
}

void sub_2ABA10(X86Context& ctx, uint8_t* base) {
	// 0x2ABA10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ABA18: movss [0x00570FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x570FB8u, ctx.xmm[0].u32[0]);
	// 0x2ABA20: ret
	return;
}

void sub_2ABA30(X86Context& ctx, uint8_t* base) {
	// 0x2ABA30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ABA38: movss [0x00570FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x570FE8u, ctx.xmm[0].u32[0]);
	// 0x2ABA40: ret
	return;
}

void sub_2ABA50(X86Context& ctx, uint8_t* base) {
	// 0x2ABA50: movss xmm0, dword ptr [0x00570FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FE4u);
	// 0x2ABA58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ABA60: movss [0x00570FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x570FF4u, ctx.xmm[0].u32[0]);
	// 0x2ABA68: ret
	return;
}

void sub_2ABA70(X86Context& ctx, uint8_t* base) {
	// 0x2ABA70: movss xmm0, dword ptr [0x00571038]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571038u);
	// 0x2ABA78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ABA80: movss [0x0057103C], xmm0
	X86_MEM_WRITE_u32(base, 0x57103Cu, ctx.xmm[0].u32[0]);
	// 0x2ABA88: ret
	return;
}

void sub_2ABA90(X86Context& ctx, uint8_t* base) {
	// 0x2ABA90: movss xmm0, dword ptr [0x00570FF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FF4u);
	// 0x2ABA98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ABAA0: movss [0x00571028], xmm0
	X86_MEM_WRITE_u32(base, 0x571028u, ctx.xmm[0].u32[0]);
	// 0x2ABAA8: ret
	return;
}

void sub_2ABAB0(X86Context& ctx, uint8_t* base) {
	// 0x2ABAB0: movss xmm0, dword ptr [0x0057103C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57103Cu);
	// 0x2ABAB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ABAC0: movss [0x0057104C], xmm0
	X86_MEM_WRITE_u32(base, 0x57104Cu, ctx.xmm[0].u32[0]);
	// 0x2ABAC8: ret
	return;
}

void sub_2ABAD0(X86Context& ctx, uint8_t* base) {
	// 0x2ABAD0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2ABAD8: movss [0x00570FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x570FC4u, ctx.xmm[0].u32[0]);
	// 0x2ABAE0: ret
	return;
}

void sub_2ABAF0(X86Context& ctx, uint8_t* base) {
	// 0x2ABAF0: movss xmm0, dword ptr [0x00570FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FE4u);
	// 0x2ABAF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ABB00: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2ABB08: movss [0x00571034], xmm0
	X86_MEM_WRITE_u32(base, 0x571034u, ctx.xmm[0].u32[0]);
	// 0x2ABB10: ret
	return;
}

void sub_2ABB20(X86Context& ctx, uint8_t* base) {
	// 0x2ABB20: movss xmm0, dword ptr [0x00571038]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571038u);
	// 0x2ABB28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ABB30: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2ABB38: movss [0x00570FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x570FDCu, ctx.xmm[0].u32[0]);
	// 0x2ABB40: ret
	return;
}

void sub_2ABB50(X86Context& ctx, uint8_t* base) {
	// 0x2ABB50: movss xmm0, dword ptr [0x00570FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FE4u);
	// 0x2ABB58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ABB60: movss [0x00570FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x570FE0u, ctx.xmm[0].u32[0]);
	// 0x2ABB68: ret
	return;
}

void sub_2ABB70(X86Context& ctx, uint8_t* base) {
	// 0x2ABB70: movss xmm0, dword ptr [0x00571038]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571038u);
	// 0x2ABB78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ABB80: movss [0x00571040], xmm0
	X86_MEM_WRITE_u32(base, 0x571040u, ctx.xmm[0].u32[0]);
	// 0x2ABB88: ret
	return;
}

void sub_2ABB90(X86Context& ctx, uint8_t* base) {
	// 0x2ABB90: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2ABB98: movss [0x00570FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x570FC8u, ctx.xmm[0].u32[0]);
	// 0x2ABBA0: ret
	return;
}

void sub_2ABBB0(X86Context& ctx, uint8_t* base) {
	// 0x2ABBB0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2ABBB8: movss [0x00570FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x570FF0u, ctx.xmm[0].u32[0]);
	// 0x2ABBC0: ret
	return;
}

void sub_2ABBD0(X86Context& ctx, uint8_t* base) {
	// 0x2ABBD0: movss xmm0, dword ptr [0x00570FC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570FC8u);
	// 0x2ABBD8: movss [0x00571054], xmm0
	X86_MEM_WRITE_u32(base, 0x571054u, ctx.xmm[0].u32[0]);
	// 0x2ABBE0: ret
	return;
}

void sub_2ABBF0(X86Context& ctx, uint8_t* base) {
	// 0x2ABBF0: movss xmm0, dword ptr [0x00571038]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571038u);
	// 0x2ABBF8: subss xmm0, [0x00570FC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570FC8u);
	// 0x2ABC00: movss [0x00571018], xmm0
	X86_MEM_WRITE_u32(base, 0x571018u, ctx.xmm[0].u32[0]);
	// 0x2ABC08: ret
	return;
}

void sub_2ABC10(X86Context& ctx, uint8_t* base) {
	// 0x2ABC10: movss xmm0, dword ptr [0x00571018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571018u);
	// 0x2ABC18: subss xmm0, [0x00570FF0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570FF0u);
	// 0x2ABC20: movss [0x00571010], xmm0
	X86_MEM_WRITE_u32(base, 0x571010u, ctx.xmm[0].u32[0]);
	// 0x2ABC28: ret
	return;
}

void sub_2ABC30(X86Context& ctx, uint8_t* base) {
	// 0x2ABC30: movss xmm0, dword ptr [0x00571040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571040u);
	// 0x2ABC38: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2ABC40: movss [0x00571000], xmm0
	X86_MEM_WRITE_u32(base, 0x571000u, ctx.xmm[0].u32[0]);
	// 0x2ABC48: ret
	return;
}

void sub_2ABC50(X86Context& ctx, uint8_t* base) {
	// 0x2ABC50: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2ABC58: movss [0x00570FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x570FECu, ctx.xmm[0].u32[0]);
	// 0x2ABC60: ret
	return;
}

void sub_2ABC70(X86Context& ctx, uint8_t* base) {
	// 0x2ABC70: movss xmm0, dword ptr [0x00571000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571000u);
	// 0x2ABC78: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2ABC80: movss [0x00571030], xmm0
	X86_MEM_WRITE_u32(base, 0x571030u, ctx.xmm[0].u32[0]);
	// 0x2ABC88: ret
	return;
}

void sub_2ABC90(X86Context& ctx, uint8_t* base) {
	// 0x2ABC90: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2ABC98: movss [0x005710CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5710CCu, ctx.xmm[0].u32[0]);
	// 0x2ABCA0: ret
	return;
}

void sub_2ABCB0(X86Context& ctx, uint8_t* base) {
	// 0x2ABCB0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2ABCB8: movss [0x005710E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5710E8u, ctx.xmm[0].u32[0]);
	// 0x2ABCC0: ret
	return;
}

void sub_2ABCD0(X86Context& ctx, uint8_t* base) {
	// 0x2ABCD0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2ABCD8: movss [0x005710B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5710B4u, ctx.xmm[0].u32[0]);
	// 0x2ABCE0: ret
	return;
}

void sub_2ABCF0(X86Context& ctx, uint8_t* base) {
	// 0x2ABCF0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2ABCF8: movss [0x00571060], xmm0
	X86_MEM_WRITE_u32(base, 0x571060u, ctx.xmm[0].u32[0]);
	// 0x2ABD00: ret
	return;
}

void sub_2ABD10(X86Context& ctx, uint8_t* base) {
	// 0x2ABD10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2ABD18: movss [0x005710D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5710D0u, ctx.xmm[0].u32[0]);
	// 0x2ABD20: ret
	return;
}

void sub_2ABD30(X86Context& ctx, uint8_t* base) {
	// 0x2ABD30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2ABD38: movss [0x00571080], xmm0
	X86_MEM_WRITE_u32(base, 0x571080u, ctx.xmm[0].u32[0]);
	// 0x2ABD40: ret
	return;
}

void sub_2ABD50(X86Context& ctx, uint8_t* base) {
	// 0x2ABD50: movss xmm0, dword ptr [0x005710D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5710D0u);
	// 0x2ABD58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ABD60: movss [0x0057110C], xmm0
	X86_MEM_WRITE_u32(base, 0x57110Cu, ctx.xmm[0].u32[0]);
	// 0x2ABD68: ret
	return;
}

void sub_2ABD70(X86Context& ctx, uint8_t* base) {
	// 0x2ABD70: movss xmm0, dword ptr [0x00571080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571080u);
	// 0x2ABD78: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ABD80: movss [0x005710F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5710F4u, ctx.xmm[0].u32[0]);
	// 0x2ABD88: ret
	return;
}

void sub_2ABD90(X86Context& ctx, uint8_t* base) {
	// 0x2ABD90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ABD98: movss [0x0057112C], xmm0
	X86_MEM_WRITE_u32(base, 0x57112Cu, ctx.xmm[0].u32[0]);
	// 0x2ABDA0: ret
	return;
}

void sub_2ABDB0(X86Context& ctx, uint8_t* base) {
	// 0x2ABDB0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2ABDB8: movss [0x00571110], xmm0
	X86_MEM_WRITE_u32(base, 0x571110u, ctx.xmm[0].u32[0]);
	// 0x2ABDC0: ret
	return;
}

void sub_2ABDD0(X86Context& ctx, uint8_t* base) {
	// 0x2ABDD0: movss xmm0, dword ptr [0x00571110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571110u);
	// 0x2ABDD8: movss [0x00571128], xmm0
	X86_MEM_WRITE_u32(base, 0x571128u, ctx.xmm[0].u32[0]);
	// 0x2ABDE0: ret
	return;
}

void sub_2ABDF0(X86Context& ctx, uint8_t* base) {
	// 0x2ABDF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ABDF8: movss [0x00571068], xmm0
	X86_MEM_WRITE_u32(base, 0x571068u, ctx.xmm[0].u32[0]);
	// 0x2ABE00: ret
	return;
}

void sub_2ABE10(X86Context& ctx, uint8_t* base) {
	// 0x2ABE10: movss xmm0, dword ptr [0x00571080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571080u);
	// 0x2ABE18: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2ABE20: movss [0x0057111C], xmm0
	X86_MEM_WRITE_u32(base, 0x57111Cu, ctx.xmm[0].u32[0]);
	// 0x2ABE28: ret
	return;
}

void sub_2ABE30(X86Context& ctx, uint8_t* base) {
	// 0x2ABE30: movss xmm0, dword ptr [0x00571080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571080u);
	// 0x2ABE38: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2ABE40: movss [0x005710AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5710ACu, ctx.xmm[0].u32[0]);
	// 0x2ABE48: ret
	return;
}

void sub_2ABE50(X86Context& ctx, uint8_t* base) {
	// 0x2ABE50: movss xmm0, dword ptr [0x00571080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571080u);
	// 0x2ABE58: subss xmm0, [0x005710AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5710ACu);
	// 0x2ABE60: movss [0x00571088], xmm0
	X86_MEM_WRITE_u32(base, 0x571088u, ctx.xmm[0].u32[0]);
	// 0x2ABE68: ret
	return;
}

void sub_2ABE70(X86Context& ctx, uint8_t* base) {
	// 0x2ABE70: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2ABE78: movss [0x005710E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5710E4u, ctx.xmm[0].u32[0]);
	// 0x2ABE80: ret
	return;
}

void sub_2ABE90(X86Context& ctx, uint8_t* base) {
	// 0x2ABE90: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2ABE98: movss [0x00571084], xmm0
	X86_MEM_WRITE_u32(base, 0x571084u, ctx.xmm[0].u32[0]);
	// 0x2ABEA0: ret
	return;
}

void sub_2ABEB0(X86Context& ctx, uint8_t* base) {
	// 0x2ABEB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2ABEB8: movss [0x00571098], xmm0
	X86_MEM_WRITE_u32(base, 0x571098u, ctx.xmm[0].u32[0]);
	// 0x2ABEC0: ret
	return;
}

void sub_2ABED0(X86Context& ctx, uint8_t* base) {
	// 0x2ABED0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2ABED8: movss [0x00571100], xmm0
	X86_MEM_WRITE_u32(base, 0x571100u, ctx.xmm[0].u32[0]);
	// 0x2ABEE0: ret
	return;
}

void sub_2ABEF0(X86Context& ctx, uint8_t* base) {
	// 0x2ABEF0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2ABEF8: movss [0x005710E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5710E0u, ctx.xmm[0].u32[0]);
	// 0x2ABF00: ret
	return;
}

void sub_2ABF10(X86Context& ctx, uint8_t* base) {
	// 0x2ABF10: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2ABF18: movss [0x0057107C], xmm0
	X86_MEM_WRITE_u32(base, 0x57107Cu, ctx.xmm[0].u32[0]);
	// 0x2ABF20: ret
	return;
}

void sub_2ABF30(X86Context& ctx, uint8_t* base) {
	// 0x2ABF30: movss xmm0, dword ptr [0x00571098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571098u);
	// 0x2ABF38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ABF40: movss [0x0057106C], xmm0
	X86_MEM_WRITE_u32(base, 0x57106Cu, ctx.xmm[0].u32[0]);
	// 0x2ABF48: ret
	return;
}

void sub_2ABF50(X86Context& ctx, uint8_t* base) {
	// 0x2ABF50: movss xmm0, dword ptr [0x00571100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571100u);
	// 0x2ABF58: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ABF60: movss [0x005710C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5710C4u, ctx.xmm[0].u32[0]);
	// 0x2ABF68: ret
	return;
}

void sub_2ABF70(X86Context& ctx, uint8_t* base) {
	// 0x2ABF70: movss xmm0, dword ptr [0x0057106C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57106Cu);
	// 0x2ABF78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ABF80: movss [0x005710D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5710D8u, ctx.xmm[0].u32[0]);
	// 0x2ABF88: ret
	return;
}

void sub_2ABF90(X86Context& ctx, uint8_t* base) {
	// 0x2ABF90: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ABF98: movss [0x00571064], xmm0
	X86_MEM_WRITE_u32(base, 0x571064u, ctx.xmm[0].u32[0]);
	// 0x2ABFA0: ret
	return;
}

void sub_2ABFB0(X86Context& ctx, uint8_t* base) {
	// 0x2ABFB0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ABFB8: movss [0x0057109C], xmm0
	X86_MEM_WRITE_u32(base, 0x57109Cu, ctx.xmm[0].u32[0]);
	// 0x2ABFC0: ret
	return;
}

void sub_2ABFD0(X86Context& ctx, uint8_t* base) {
	// 0x2ABFD0: movss xmm0, dword ptr [0x00571098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571098u);
	// 0x2ABFD8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ABFE0: movss [0x005710A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5710A8u, ctx.xmm[0].u32[0]);
	// 0x2ABFE8: ret
	return;
}

void sub_2ABFF0(X86Context& ctx, uint8_t* base) {
	// 0x2ABFF0: movss xmm0, dword ptr [0x00571100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571100u);
	// 0x2ABFF8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AC000: movss [0x00571104], xmm0
	X86_MEM_WRITE_u32(base, 0x571104u, ctx.xmm[0].u32[0]);
	// 0x2AC008: ret
	return;
}

void sub_2AC010(X86Context& ctx, uint8_t* base) {
	// 0x2AC010: movss xmm0, dword ptr [0x005710A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5710A8u);
	// 0x2AC018: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC020: movss [0x005710EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5710ECu, ctx.xmm[0].u32[0]);
	// 0x2AC028: ret
	return;
}

void sub_2AC030(X86Context& ctx, uint8_t* base) {
	// 0x2AC030: movss xmm0, dword ptr [0x00571104]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571104u);
	// 0x2AC038: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC040: movss [0x00571114], xmm0
	X86_MEM_WRITE_u32(base, 0x571114u, ctx.xmm[0].u32[0]);
	// 0x2AC048: ret
	return;
}

void sub_2AC050(X86Context& ctx, uint8_t* base) {
	// 0x2AC050: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AC058: movss [0x00571070], xmm0
	X86_MEM_WRITE_u32(base, 0x571070u, ctx.xmm[0].u32[0]);
	// 0x2AC060: ret
	return;
}

void sub_2AC070(X86Context& ctx, uint8_t* base) {
	// 0x2AC070: movss xmm0, dword ptr [0x00571098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571098u);
	// 0x2AC078: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC080: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AC088: movss [0x005710FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5710FCu, ctx.xmm[0].u32[0]);
	// 0x2AC090: ret
	return;
}

void sub_2AC0A0(X86Context& ctx, uint8_t* base) {
	// 0x2AC0A0: movss xmm0, dword ptr [0x00571100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571100u);
	// 0x2AC0A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC0B0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AC0B8: movss [0x0057108C], xmm0
	X86_MEM_WRITE_u32(base, 0x57108Cu, ctx.xmm[0].u32[0]);
	// 0x2AC0C0: ret
	return;
}

void sub_2AC0D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC0D0: movss xmm0, dword ptr [0x00571098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571098u);
	// 0x2AC0D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC0E0: movss [0x00571090], xmm0
	X86_MEM_WRITE_u32(base, 0x571090u, ctx.xmm[0].u32[0]);
	// 0x2AC0E8: ret
	return;
}

void sub_2AC0F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC0F0: movss xmm0, dword ptr [0x00571100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571100u);
	// 0x2AC0F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC100: movss [0x00571108], xmm0
	X86_MEM_WRITE_u32(base, 0x571108u, ctx.xmm[0].u32[0]);
	// 0x2AC108: ret
	return;
}

void sub_2AC110(X86Context& ctx, uint8_t* base) {
	// 0x2AC110: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AC118: movss [0x00571078], xmm0
	X86_MEM_WRITE_u32(base, 0x571078u, ctx.xmm[0].u32[0]);
	// 0x2AC120: ret
	return;
}

void sub_2AC130(X86Context& ctx, uint8_t* base) {
	// 0x2AC130: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AC138: movss [0x005710A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5710A4u, ctx.xmm[0].u32[0]);
	// 0x2AC140: ret
	return;
}

void sub_2AC150(X86Context& ctx, uint8_t* base) {
	// 0x2AC150: movss xmm0, dword ptr [0x00571078]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571078u);
	// 0x2AC158: movss [0x00571120], xmm0
	X86_MEM_WRITE_u32(base, 0x571120u, ctx.xmm[0].u32[0]);
	// 0x2AC160: ret
	return;
}

void sub_2AC170(X86Context& ctx, uint8_t* base) {
	// 0x2AC170: movss xmm0, dword ptr [0x00571100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571100u);
	// 0x2AC178: subss xmm0, [0x00571078]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571078u);
	// 0x2AC180: movss [0x005710DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5710DCu, ctx.xmm[0].u32[0]);
	// 0x2AC188: ret
	return;
}

void sub_2AC190(X86Context& ctx, uint8_t* base) {
	// 0x2AC190: movss xmm0, dword ptr [0x005710DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5710DCu);
	// 0x2AC198: subss xmm0, [0x005710A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5710A4u);
	// 0x2AC1A0: movss [0x005710D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5710D4u, ctx.xmm[0].u32[0]);
	// 0x2AC1A8: ret
	return;
}

void sub_2AC1B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC1B0: movss xmm0, dword ptr [0x00571108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571108u);
	// 0x2AC1B8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AC1C0: movss [0x005710BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5710BCu, ctx.xmm[0].u32[0]);
	// 0x2AC1C8: ret
	return;
}

void sub_2AC1D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC1D0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AC1D8: movss [0x005710A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5710A0u, ctx.xmm[0].u32[0]);
	// 0x2AC1E0: ret
	return;
}

void sub_2AC1F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC1F0: movss xmm0, dword ptr [0x005710BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5710BCu);
	// 0x2AC1F8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AC200: movss [0x005710F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5710F8u, ctx.xmm[0].u32[0]);
	// 0x2AC208: ret
	return;
}

void sub_2AC210(X86Context& ctx, uint8_t* base) {
	// 0x2AC210: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2AC218: movss [0x005710C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5710C8u, ctx.xmm[0].u32[0]);
	// 0x2AC220: ret
	return;
}

void sub_2AC230(X86Context& ctx, uint8_t* base) {
	// 0x2AC230: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2AC238: movss [0x00571094], xmm0
	X86_MEM_WRITE_u32(base, 0x571094u, ctx.xmm[0].u32[0]);
	// 0x2AC240: ret
	return;
}

void sub_2AC250(X86Context& ctx, uint8_t* base) {
	// 0x2AC250: movss xmm0, dword ptr [0x00407C58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x407C58u);
	// 0x2AC258: subss xmm0, [0x003B17C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B17C8u);
	// 0x2AC260: movss [0x00571074], xmm0
	X86_MEM_WRITE_u32(base, 0x571074u, ctx.xmm[0].u32[0]);
	// 0x2AC268: ret
	return;
}

void sub_2AC270(X86Context& ctx, uint8_t* base) {
	// 0x2AC270: movss xmm0, dword ptr [0x003980F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3980F8u);
	// 0x2AC278: movss [0x005710B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5710B8u, ctx.xmm[0].u32[0]);
	// 0x2AC280: ret
	return;
}

void sub_2AC290(X86Context& ctx, uint8_t* base) {
	// 0x2AC290: movss xmm0, dword ptr [0x003B1844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1844u);
	// 0x2AC298: movss [0x00571124], xmm0
	X86_MEM_WRITE_u32(base, 0x571124u, ctx.xmm[0].u32[0]);
	// 0x2AC2A0: ret
	return;
}

void sub_2AC2B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC2B0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2AC2B8: divss xmm0, [0x00571124]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571124u);
	// 0x2AC2C0: movss [0x005710F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5710F0u, ctx.xmm[0].u32[0]);
	// 0x2AC2C8: ret
	return;
}

void sub_2AC2D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC2D0: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2AC2D8: movss [0x005710C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5710C0u, ctx.xmm[0].u32[0]);
	// 0x2AC2E0: ret
	return;
}

void sub_2AC2F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC2F0: movss xmm0, dword ptr [0x005710C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5710C0u);
	// 0x2AC2F8: mulss xmm0, [0x003B1884]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1884u);
	// 0x2AC300: addss xmm0, [0x00407C70]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x407C70u);
	// 0x2AC308: movss [0x00571118], xmm0
	X86_MEM_WRITE_u32(base, 0x571118u, ctx.xmm[0].u32[0]);
	// 0x2AC310: ret
	return;
}

void sub_2AC320(X86Context& ctx, uint8_t* base) {
	// 0x2AC320: mov dword ptr [0x005710B0], 0x1A
	X86_MEM_WRITE_u32(base, 0x5710B0u, 26);
	// 0x2AC32A: ret
	return;
}

void sub_2AC330(X86Context& ctx, uint8_t* base) {
	// 0x2AC330: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AC338: movss [0x005711A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5711A4u, ctx.xmm[0].u32[0]);
	// 0x2AC340: ret
	return;
}

void sub_2AC350(X86Context& ctx, uint8_t* base) {
	// 0x2AC350: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AC358: movss [0x005711C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5711C0u, ctx.xmm[0].u32[0]);
	// 0x2AC360: ret
	return;
}

void sub_2AC370(X86Context& ctx, uint8_t* base) {
	// 0x2AC370: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AC378: movss [0x00571190], xmm0
	X86_MEM_WRITE_u32(base, 0x571190u, ctx.xmm[0].u32[0]);
	// 0x2AC380: ret
	return;
}

void sub_2AC390(X86Context& ctx, uint8_t* base) {
	// 0x2AC390: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AC398: movss [0x00571134], xmm0
	X86_MEM_WRITE_u32(base, 0x571134u, ctx.xmm[0].u32[0]);
	// 0x2AC3A0: ret
	return;
}

void sub_2AC3B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC3B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AC3B8: movss [0x005711A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5711A8u, ctx.xmm[0].u32[0]);
	// 0x2AC3C0: ret
	return;
}

void sub_2AC3D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC3D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AC3D8: movss [0x00571150], xmm0
	X86_MEM_WRITE_u32(base, 0x571150u, ctx.xmm[0].u32[0]);
	// 0x2AC3E0: ret
	return;
}

void sub_2AC3F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC3F0: movss xmm0, dword ptr [0x005711A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711A8u);
	// 0x2AC3F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AC400: movss [0x005711E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5711E0u, ctx.xmm[0].u32[0]);
	// 0x2AC408: ret
	return;
}

void sub_2AC410(X86Context& ctx, uint8_t* base) {
	// 0x2AC410: movss xmm0, dword ptr [0x00571150]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571150u);
	// 0x2AC418: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AC420: movss [0x005711C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5711C8u, ctx.xmm[0].u32[0]);
	// 0x2AC428: ret
	return;
}

void sub_2AC430(X86Context& ctx, uint8_t* base) {
	// 0x2AC430: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AC438: movss [0x005711F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5711F8u, ctx.xmm[0].u32[0]);
	// 0x2AC440: ret
	return;
}

void sub_2AC450(X86Context& ctx, uint8_t* base) {
	// 0x2AC450: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AC458: movss [0x005711E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5711E4u, ctx.xmm[0].u32[0]);
	// 0x2AC460: ret
	return;
}

void sub_2AC470(X86Context& ctx, uint8_t* base) {
	// 0x2AC470: movss xmm0, dword ptr [0x005711E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711E4u);
	// 0x2AC478: movss [0x005711F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5711F4u, ctx.xmm[0].u32[0]);
	// 0x2AC480: ret
	return;
}

void sub_2AC490(X86Context& ctx, uint8_t* base) {
	// 0x2AC490: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AC498: movss [0x0057113C], xmm0
	X86_MEM_WRITE_u32(base, 0x57113Cu, ctx.xmm[0].u32[0]);
	// 0x2AC4A0: ret
	return;
}

void sub_2AC4B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC4B0: movss xmm0, dword ptr [0x00571150]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571150u);
	// 0x2AC4B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AC4C0: movss [0x005711EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5711ECu, ctx.xmm[0].u32[0]);
	// 0x2AC4C8: ret
	return;
}

void sub_2AC4D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC4D0: movss xmm0, dword ptr [0x00571150]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571150u);
	// 0x2AC4D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AC4E0: movss [0x0057118C], xmm0
	X86_MEM_WRITE_u32(base, 0x57118Cu, ctx.xmm[0].u32[0]);
	// 0x2AC4E8: ret
	return;
}

void sub_2AC4F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC4F0: movss xmm0, dword ptr [0x00571150]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571150u);
	// 0x2AC4F8: subss xmm0, [0x0057118C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57118Cu);
	// 0x2AC500: movss [0x0057115C], xmm0
	X86_MEM_WRITE_u32(base, 0x57115Cu, ctx.xmm[0].u32[0]);
	// 0x2AC508: ret
	return;
}

void sub_2AC510(X86Context& ctx, uint8_t* base) {
	// 0x2AC510: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AC518: movss [0x005711BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5711BCu, ctx.xmm[0].u32[0]);
	// 0x2AC520: ret
	return;
}

void sub_2AC530(X86Context& ctx, uint8_t* base) {
	// 0x2AC530: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AC538: movss [0x00571158], xmm0
	X86_MEM_WRITE_u32(base, 0x571158u, ctx.xmm[0].u32[0]);
	// 0x2AC540: ret
	return;
}

void sub_2AC550(X86Context& ctx, uint8_t* base) {
	// 0x2AC550: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AC558: movss [0x00571178], xmm0
	X86_MEM_WRITE_u32(base, 0x571178u, ctx.xmm[0].u32[0]);
	// 0x2AC560: ret
	return;
}

void sub_2AC570(X86Context& ctx, uint8_t* base) {
	// 0x2AC570: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AC578: movss [0x005711D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5711D4u, ctx.xmm[0].u32[0]);
	// 0x2AC580: ret
	return;
}

void sub_2AC590(X86Context& ctx, uint8_t* base) {
	// 0x2AC590: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AC598: movss [0x005711B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5711B8u, ctx.xmm[0].u32[0]);
	// 0x2AC5A0: ret
	return;
}

void sub_2AC5B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC5B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AC5B8: movss [0x0057114C], xmm0
	X86_MEM_WRITE_u32(base, 0x57114Cu, ctx.xmm[0].u32[0]);
	// 0x2AC5C0: ret
	return;
}

void sub_2AC5D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC5D0: movss xmm0, dword ptr [0x00571178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571178u);
	// 0x2AC5D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AC5E0: movss [0x00571140], xmm0
	X86_MEM_WRITE_u32(base, 0x571140u, ctx.xmm[0].u32[0]);
	// 0x2AC5E8: ret
	return;
}

void sub_2AC5F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC5F0: movss xmm0, dword ptr [0x005711D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711D4u);
	// 0x2AC5F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AC600: movss [0x005711A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5711A0u, ctx.xmm[0].u32[0]);
	// 0x2AC608: ret
	return;
}

void sub_2AC610(X86Context& ctx, uint8_t* base) {
	// 0x2AC610: movss xmm0, dword ptr [0x00571140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571140u);
	// 0x2AC618: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AC620: movss [0x005711B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5711B0u, ctx.xmm[0].u32[0]);
	// 0x2AC628: ret
	return;
}

void sub_2AC630(X86Context& ctx, uint8_t* base) {
	// 0x2AC630: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AC638: movss [0x00571138], xmm0
	X86_MEM_WRITE_u32(base, 0x571138u, ctx.xmm[0].u32[0]);
	// 0x2AC640: ret
	return;
}

void sub_2AC650(X86Context& ctx, uint8_t* base) {
	// 0x2AC650: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AC658: movss [0x0057117C], xmm0
	X86_MEM_WRITE_u32(base, 0x57117Cu, ctx.xmm[0].u32[0]);
	// 0x2AC660: ret
	return;
}

void sub_2AC670(X86Context& ctx, uint8_t* base) {
	// 0x2AC670: movss xmm0, dword ptr [0x00571178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571178u);
	// 0x2AC678: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AC680: movss [0x00571188], xmm0
	X86_MEM_WRITE_u32(base, 0x571188u, ctx.xmm[0].u32[0]);
	// 0x2AC688: ret
	return;
}

void sub_2AC690(X86Context& ctx, uint8_t* base) {
	// 0x2AC690: movss xmm0, dword ptr [0x005711D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711D4u);
	// 0x2AC698: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AC6A0: movss [0x005711D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5711D8u, ctx.xmm[0].u32[0]);
	// 0x2AC6A8: ret
	return;
}

void sub_2AC6B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC6B0: movss xmm0, dword ptr [0x00571188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571188u);
	// 0x2AC6B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC6C0: movss [0x005711C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5711C4u, ctx.xmm[0].u32[0]);
	// 0x2AC6C8: ret
	return;
}

void sub_2AC6D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC6D0: movss xmm0, dword ptr [0x005711D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711D8u);
	// 0x2AC6D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC6E0: movss [0x005711E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5711E8u, ctx.xmm[0].u32[0]);
	// 0x2AC6E8: ret
	return;
}

void sub_2AC6F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC6F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AC6F8: movss [0x00571144], xmm0
	X86_MEM_WRITE_u32(base, 0x571144u, ctx.xmm[0].u32[0]);
	// 0x2AC700: ret
	return;
}

void sub_2AC710(X86Context& ctx, uint8_t* base) {
	// 0x2AC710: movss xmm0, dword ptr [0x00571178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571178u);
	// 0x2AC718: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC720: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AC728: movss [0x005711D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5711D0u, ctx.xmm[0].u32[0]);
	// 0x2AC730: ret
	return;
}

void sub_2AC740(X86Context& ctx, uint8_t* base) {
	// 0x2AC740: movss xmm0, dword ptr [0x005711D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711D4u);
	// 0x2AC748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC750: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AC758: movss [0x00571168], xmm0
	X86_MEM_WRITE_u32(base, 0x571168u, ctx.xmm[0].u32[0]);
	// 0x2AC760: ret
	return;
}

void sub_2AC770(X86Context& ctx, uint8_t* base) {
	// 0x2AC770: movss xmm0, dword ptr [0x00571178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571178u);
	// 0x2AC778: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC780: movss [0x0057116C], xmm0
	X86_MEM_WRITE_u32(base, 0x57116Cu, ctx.xmm[0].u32[0]);
	// 0x2AC788: ret
	return;
}

void sub_2AC790(X86Context& ctx, uint8_t* base) {
	// 0x2AC790: movss xmm0, dword ptr [0x005711D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711D4u);
	// 0x2AC798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AC7A0: movss [0x005711DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5711DCu, ctx.xmm[0].u32[0]);
	// 0x2AC7A8: ret
	return;
}

void sub_2AC7B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC7B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AC7B8: movss [0x00571148], xmm0
	X86_MEM_WRITE_u32(base, 0x571148u, ctx.xmm[0].u32[0]);
	// 0x2AC7C0: ret
	return;
}

void sub_2AC7D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC7D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AC7D8: movss [0x00571184], xmm0
	X86_MEM_WRITE_u32(base, 0x571184u, ctx.xmm[0].u32[0]);
	// 0x2AC7E0: ret
	return;
}

void sub_2AC7F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC7F0: movss xmm0, dword ptr [0x00571148]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571148u);
	// 0x2AC7F8: movss [0x005711F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5711F0u, ctx.xmm[0].u32[0]);
	// 0x2AC800: ret
	return;
}

void sub_2AC810(X86Context& ctx, uint8_t* base) {
	// 0x2AC810: movss xmm0, dword ptr [0x005711D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711D4u);
	// 0x2AC818: subss xmm0, [0x00571148]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571148u);
	// 0x2AC820: movss [0x005711B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5711B4u, ctx.xmm[0].u32[0]);
	// 0x2AC828: ret
	return;
}

void sub_2AC830(X86Context& ctx, uint8_t* base) {
	// 0x2AC830: movss xmm0, dword ptr [0x005711B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711B4u);
	// 0x2AC838: subss xmm0, [0x00571184]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571184u);
	// 0x2AC840: movss [0x005711AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5711ACu, ctx.xmm[0].u32[0]);
	// 0x2AC848: ret
	return;
}

void sub_2AC850(X86Context& ctx, uint8_t* base) {
	// 0x2AC850: movss xmm0, dword ptr [0x005711DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5711DCu);
	// 0x2AC858: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AC860: movss [0x00571198], xmm0
	X86_MEM_WRITE_u32(base, 0x571198u, ctx.xmm[0].u32[0]);
	// 0x2AC868: ret
	return;
}

void sub_2AC870(X86Context& ctx, uint8_t* base) {
	// 0x2AC870: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AC878: movss [0x00571180], xmm0
	X86_MEM_WRITE_u32(base, 0x571180u, ctx.xmm[0].u32[0]);
	// 0x2AC880: ret
	return;
}

void sub_2AC890(X86Context& ctx, uint8_t* base) {
	// 0x2AC890: movss xmm0, dword ptr [0x00571198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571198u);
	// 0x2AC898: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AC8A0: movss [0x005711CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5711CCu, ctx.xmm[0].u32[0]);
	// 0x2AC8A8: ret
	return;
}

void sub_2AC8B0(X86Context& ctx, uint8_t* base) {
	// 0x2AC8B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AC8B8: movss [0x0057119C], xmm0
	X86_MEM_WRITE_u32(base, 0x57119Cu, ctx.xmm[0].u32[0]);
	// 0x2AC8C0: ret
	return;
}

void sub_2AC8D0(X86Context& ctx, uint8_t* base) {
	// 0x2AC8D0: movss xmm0, dword ptr [0x00395BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2AC8D8: movss [0x00571170], xmm0
	X86_MEM_WRITE_u32(base, 0x571170u, ctx.xmm[0].u32[0]);
	// 0x2AC8E0: ret
	return;
}

void sub_2AC8F0(X86Context& ctx, uint8_t* base) {
	// 0x2AC8F0: movss xmm0, dword ptr [0x003B2298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2298u);
	// 0x2AC8F8: movss [0x00571154], xmm0
	X86_MEM_WRITE_u32(base, 0x571154u, ctx.xmm[0].u32[0]);
	// 0x2AC900: ret
	return;
}

void sub_2AC910(X86Context& ctx, uint8_t* base) {
	// 0x2AC910: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AC918: movss [0x00571130], xmm0
	X86_MEM_WRITE_u32(base, 0x571130u, ctx.xmm[0].u32[0]);
	// 0x2AC920: ret
	return;
}

void sub_2AC930(X86Context& ctx, uint8_t* base) {
	// 0x2AC930: movss xmm0, dword ptr [0x003B22BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22BCu);
	// 0x2AC938: movss [0x00571174], xmm0
	X86_MEM_WRITE_u32(base, 0x571174u, ctx.xmm[0].u32[0]);
	// 0x2AC940: ret
	return;
}

void sub_2AC950(X86Context& ctx, uint8_t* base) {
	// 0x2AC950: movss xmm0, dword ptr [0x00571154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571154u);
	// 0x2AC958: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AC960: addss xmm0, [0x0057119C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x57119Cu);
	// 0x2AC968: movss [0x00571194], xmm0
	X86_MEM_WRITE_u32(base, 0x571194u, ctx.xmm[0].u32[0]);
	// 0x2AC970: ret
	return;
}

void sub_2AC980(X86Context& ctx, uint8_t* base) {
	// 0x2AC980: movss xmm0, dword ptr [0x00571130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571130u);
	// 0x2AC988: addss xmm0, [0x00571170]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571170u);
	// 0x2AC990: movss [0x00571160], xmm0
	X86_MEM_WRITE_u32(base, 0x571160u, ctx.xmm[0].u32[0]);
	// 0x2AC998: ret
	return;
}

void sub_2AC9A0(X86Context& ctx, uint8_t* base) {
	// 0x2AC9A0: movss xmm0, dword ptr [0x0057119C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57119Cu);
	// 0x2AC9A8: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2AC9AB: addss xmm1, [0x003B1884]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x3B1884u);
	// 0x2AC9B3: movss [0x00571214], xmm1
	X86_MEM_WRITE_u32(base, 0x571214u, ctx.xmm[1].u32[0]);
	// 0x2AC9BB: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2AC9BE: addss xmm1, [0x00397EE0]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x397EE0u);
	// 0x2AC9C6: addss xmm0, [0x003B1904]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1904u);
	// 0x2AC9CE: movss [0x00571218], xmm1
	X86_MEM_WRITE_u32(base, 0x571218u, ctx.xmm[1].u32[0]);
	// 0x2AC9D6: movss [0x0057121C], xmm0
	X86_MEM_WRITE_u32(base, 0x57121Cu, ctx.xmm[0].u32[0]);
	// 0x2AC9DE: ret
	return;
}

void sub_2AC9E0(X86Context& ctx, uint8_t* base) {
	// 0x2AC9E0: movss xmm0, dword ptr [0x00571170]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571170u);
	// 0x2AC9E8: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2AC9EB: addss xmm1, [0x0035BF1C]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x35BF1Cu);
	// 0x2AC9F3: movss [0x00571220], xmm1
	X86_MEM_WRITE_u32(base, 0x571220u, ctx.xmm[1].u32[0]);
	// 0x2AC9FB: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2AC9FE: addss xmm1, [0x003B1F8C]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x3B1F8Cu);
	// 0x2ACA06: addss xmm0, [0x003B22C0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B22C0u);
	// 0x2ACA0E: movss [0x00571224], xmm1
	X86_MEM_WRITE_u32(base, 0x571224u, ctx.xmm[1].u32[0]);
	// 0x2ACA16: movss [0x00571228], xmm0
	X86_MEM_WRITE_u32(base, 0x571228u, ctx.xmm[0].u32[0]);
	// 0x2ACA1E: ret
	return;
}

void sub_2ACA20(X86Context& ctx, uint8_t* base) {
	// 0x2ACA20: movss xmm0, dword ptr [0x003B17E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x2ACA28: movss xmm1, dword ptr [0x00571220]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571220u);
	// 0x2ACA30: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACA34: movss [0x0057122C], xmm1
	X86_MEM_WRITE_u32(base, 0x57122Cu, ctx.xmm[1].u32[0]);
	// 0x2ACA3C: movss xmm1, dword ptr [0x00571224]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571224u);
	// 0x2ACA44: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACA48: movss [0x00571230], xmm1
	X86_MEM_WRITE_u32(base, 0x571230u, ctx.xmm[1].u32[0]);
	// 0x2ACA50: movss xmm1, dword ptr [0x00571228]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571228u);
	// 0x2ACA58: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACA5C: movss [0x00571234], xmm1
	X86_MEM_WRITE_u32(base, 0x571234u, ctx.xmm[1].u32[0]);
	// 0x2ACA64: ret
	return;
}

void sub_2ACA70(X86Context& ctx, uint8_t* base) {
	// 0x2ACA70: movss xmm0, dword ptr [0x00571174]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571174u);
	// 0x2ACA78: movss xmm1, dword ptr [0x003B195C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B195Cu);
	// 0x2ACA80: movaps xmm2, xmm0
	ctx.xmm[2] = ctx.xmm[0];
	// 0x2ACA83: addss xmm2, [0x00571214]
	ctx.xmm[2].f32[0] += X86_MEM_READ_F32(base, 0x571214u);
	// 0x2ACA8B: subss xmm2, xmm1
	ctx.xmm[2].f32[0] -= ctx.xmm[1].f32[0];
	// 0x2ACA8F: movss [0x00571208], xmm2
	X86_MEM_WRITE_u32(base, 0x571208u, ctx.xmm[2].u32[0]);
	// 0x2ACA97: movss xmm2, dword ptr [0x00571218]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x571218u);
	// 0x2ACA9F: addss xmm2, xmm0
	ctx.xmm[2].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACAA3: subss xmm2, xmm1
	ctx.xmm[2].f32[0] -= ctx.xmm[1].f32[0];
	// 0x2ACAA7: movss [0x0057120C], xmm2
	X86_MEM_WRITE_u32(base, 0x57120Cu, ctx.xmm[2].u32[0]);
	// 0x2ACAAF: movss xmm2, dword ptr [0x0057121C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x57121Cu);
	// 0x2ACAB7: addss xmm2, xmm0
	ctx.xmm[2].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACABB: subss xmm2, xmm1
	ctx.xmm[2].f32[0] -= ctx.xmm[1].f32[0];
	// 0x2ACABF: movss [0x00571210], xmm2
	X86_MEM_WRITE_u32(base, 0x571210u, ctx.xmm[2].u32[0]);
	// 0x2ACAC7: ret
	return;
}

void sub_2ACAD0(X86Context& ctx, uint8_t* base) {
	// 0x2ACAD0: movss xmm0, dword ptr [0x003B16B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x2ACAD8: movss xmm1, dword ptr [0x00571220]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571220u);
	// 0x2ACAE0: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACAE4: movss [0x005711FC], xmm1
	X86_MEM_WRITE_u32(base, 0x5711FCu, ctx.xmm[1].u32[0]);
	// 0x2ACAEC: movss xmm1, dword ptr [0x00571224]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571224u);
	// 0x2ACAF4: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACAF8: movss [0x00571200], xmm1
	X86_MEM_WRITE_u32(base, 0x571200u, ctx.xmm[1].u32[0]);
	// 0x2ACB00: movss xmm1, dword ptr [0x00571228]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571228u);
	// 0x2ACB08: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2ACB0C: movss [0x00571204], xmm1
	X86_MEM_WRITE_u32(base, 0x571204u, ctx.xmm[1].u32[0]);
	// 0x2ACB14: ret
	return;
}

