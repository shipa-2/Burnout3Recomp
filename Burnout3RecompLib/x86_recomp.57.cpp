#include "x86_recomp_shared.h"

void sub_293DE0(X86Context& ctx, uint8_t* base) {
	// 0x293DE0: movss xmm0, dword ptr [0x0056E120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E120u);
	// 0x293DE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293DF0: movss [0x0056E174], xmm0
	X86_MEM_WRITE_u32(base, 0x56E174u, ctx.xmm[0].u32[0]);
	// 0x293DF8: ret
	return;
}

void sub_293E00(X86Context& ctx, uint8_t* base) {
	// 0x293E00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x293E08: movss [0x0056E118], xmm0
	X86_MEM_WRITE_u32(base, 0x56E118u, ctx.xmm[0].u32[0]);
	// 0x293E10: ret
	return;
}

void sub_293E20(X86Context& ctx, uint8_t* base) {
	// 0x293E20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x293E28: movss [0x0056E148], xmm0
	X86_MEM_WRITE_u32(base, 0x56E148u, ctx.xmm[0].u32[0]);
	// 0x293E30: ret
	return;
}

void sub_293E40(X86Context& ctx, uint8_t* base) {
	// 0x293E40: movss xmm0, dword ptr [0x0056E144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E144u);
	// 0x293E48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x293E50: movss [0x0056E154], xmm0
	X86_MEM_WRITE_u32(base, 0x56E154u, ctx.xmm[0].u32[0]);
	// 0x293E58: ret
	return;
}

void sub_293E60(X86Context& ctx, uint8_t* base) {
	// 0x293E60: movss xmm0, dword ptr [0x0056E198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E198u);
	// 0x293E68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x293E70: movss [0x0056E19C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E19Cu, ctx.xmm[0].u32[0]);
	// 0x293E78: ret
	return;
}

void sub_293E80(X86Context& ctx, uint8_t* base) {
	// 0x293E80: movss xmm0, dword ptr [0x0056E154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E154u);
	// 0x293E88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293E90: movss [0x0056E188], xmm0
	X86_MEM_WRITE_u32(base, 0x56E188u, ctx.xmm[0].u32[0]);
	// 0x293E98: ret
	return;
}

void sub_293EA0(X86Context& ctx, uint8_t* base) {
	// 0x293EA0: movss xmm0, dword ptr [0x0056E19C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E19Cu);
	// 0x293EA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293EB0: movss [0x0056E1AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1ACu, ctx.xmm[0].u32[0]);
	// 0x293EB8: ret
	return;
}

void sub_293EC0(X86Context& ctx, uint8_t* base) {
	// 0x293EC0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x293EC8: movss [0x0056E124], xmm0
	X86_MEM_WRITE_u32(base, 0x56E124u, ctx.xmm[0].u32[0]);
	// 0x293ED0: ret
	return;
}

void sub_293EE0(X86Context& ctx, uint8_t* base) {
	// 0x293EE0: movss xmm0, dword ptr [0x0056E144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E144u);
	// 0x293EE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293EF0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x293EF8: movss [0x0056E194], xmm0
	X86_MEM_WRITE_u32(base, 0x56E194u, ctx.xmm[0].u32[0]);
	// 0x293F00: ret
	return;
}

void sub_293F10(X86Context& ctx, uint8_t* base) {
	// 0x293F10: movss xmm0, dword ptr [0x0056E198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E198u);
	// 0x293F18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293F20: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x293F28: movss [0x0056E13C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E13Cu, ctx.xmm[0].u32[0]);
	// 0x293F30: ret
	return;
}

void sub_293F40(X86Context& ctx, uint8_t* base) {
	// 0x293F40: movss xmm0, dword ptr [0x0056E144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E144u);
	// 0x293F48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293F50: movss [0x0056E140], xmm0
	X86_MEM_WRITE_u32(base, 0x56E140u, ctx.xmm[0].u32[0]);
	// 0x293F58: ret
	return;
}

void sub_293F60(X86Context& ctx, uint8_t* base) {
	// 0x293F60: movss xmm0, dword ptr [0x0056E198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E198u);
	// 0x293F68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293F70: movss [0x0056E1A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1A0u, ctx.xmm[0].u32[0]);
	// 0x293F78: ret
	return;
}

void sub_293F80(X86Context& ctx, uint8_t* base) {
	// 0x293F80: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x293F88: movss [0x0056E128], xmm0
	X86_MEM_WRITE_u32(base, 0x56E128u, ctx.xmm[0].u32[0]);
	// 0x293F90: ret
	return;
}

void sub_293FA0(X86Context& ctx, uint8_t* base) {
	// 0x293FA0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x293FA8: movss [0x0056E150], xmm0
	X86_MEM_WRITE_u32(base, 0x56E150u, ctx.xmm[0].u32[0]);
	// 0x293FB0: ret
	return;
}

void sub_293FC0(X86Context& ctx, uint8_t* base) {
	// 0x293FC0: movss xmm0, dword ptr [0x0056E128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E128u);
	// 0x293FC8: movss [0x0056E1B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1B4u, ctx.xmm[0].u32[0]);
	// 0x293FD0: ret
	return;
}

void sub_293FE0(X86Context& ctx, uint8_t* base) {
	// 0x293FE0: movss xmm0, dword ptr [0x0056E198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E198u);
	// 0x293FE8: subss xmm0, [0x0056E128]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E128u);
	// 0x293FF0: movss [0x0056E178], xmm0
	X86_MEM_WRITE_u32(base, 0x56E178u, ctx.xmm[0].u32[0]);
	// 0x293FF8: ret
	return;
}

void sub_294000(X86Context& ctx, uint8_t* base) {
	// 0x294000: movss xmm0, dword ptr [0x0056E178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E178u);
	// 0x294008: subss xmm0, [0x0056E150]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E150u);
	// 0x294010: movss [0x0056E170], xmm0
	X86_MEM_WRITE_u32(base, 0x56E170u, ctx.xmm[0].u32[0]);
	// 0x294018: ret
	return;
}

void sub_294020(X86Context& ctx, uint8_t* base) {
	// 0x294020: movss xmm0, dword ptr [0x0056E1A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1A0u);
	// 0x294028: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x294030: movss [0x0056E160], xmm0
	X86_MEM_WRITE_u32(base, 0x56E160u, ctx.xmm[0].u32[0]);
	// 0x294038: ret
	return;
}

void sub_294040(X86Context& ctx, uint8_t* base) {
	// 0x294040: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x294048: movss [0x0056E14C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E14Cu, ctx.xmm[0].u32[0]);
	// 0x294050: ret
	return;
}

void sub_294060(X86Context& ctx, uint8_t* base) {
	// 0x294060: movss xmm0, dword ptr [0x0056E160]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E160u);
	// 0x294068: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x294070: movss [0x0056E190], xmm0
	X86_MEM_WRITE_u32(base, 0x56E190u, ctx.xmm[0].u32[0]);
	// 0x294078: ret
	return;
}

void sub_294080(X86Context& ctx, uint8_t* base) {
	// 0x294080: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x294088: movss [0x0056E214], xmm0
	X86_MEM_WRITE_u32(base, 0x56E214u, ctx.xmm[0].u32[0]);
	// 0x294090: ret
	return;
}

void sub_2940A0(X86Context& ctx, uint8_t* base) {
	// 0x2940A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2940A8: movss [0x0056E230], xmm0
	X86_MEM_WRITE_u32(base, 0x56E230u, ctx.xmm[0].u32[0]);
	// 0x2940B0: ret
	return;
}

void sub_2940C0(X86Context& ctx, uint8_t* base) {
	// 0x2940C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2940C8: movss [0x0056E208], xmm0
	X86_MEM_WRITE_u32(base, 0x56E208u, ctx.xmm[0].u32[0]);
	// 0x2940D0: ret
	return;
}

void sub_2940E0(X86Context& ctx, uint8_t* base) {
	// 0x2940E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2940E8: movss [0x0056E1C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1C0u, ctx.xmm[0].u32[0]);
	// 0x2940F0: ret
	return;
}

void sub_294100(X86Context& ctx, uint8_t* base) {
	// 0x294100: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x294108: movss [0x0056E218], xmm0
	X86_MEM_WRITE_u32(base, 0x56E218u, ctx.xmm[0].u32[0]);
	// 0x294110: ret
	return;
}

void sub_294120(X86Context& ctx, uint8_t* base) {
	// 0x294120: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x294128: movss [0x0056E1DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1DCu, ctx.xmm[0].u32[0]);
	// 0x294130: ret
	return;
}

void sub_294140(X86Context& ctx, uint8_t* base) {
	// 0x294140: movss xmm0, dword ptr [0x0056E218]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E218u);
	// 0x294148: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x294150: movss [0x0056E250], xmm0
	X86_MEM_WRITE_u32(base, 0x56E250u, ctx.xmm[0].u32[0]);
	// 0x294158: ret
	return;
}

void sub_294160(X86Context& ctx, uint8_t* base) {
	// 0x294160: movss xmm0, dword ptr [0x0056E1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1DCu);
	// 0x294168: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x294170: movss [0x0056E238], xmm0
	X86_MEM_WRITE_u32(base, 0x56E238u, ctx.xmm[0].u32[0]);
	// 0x294178: ret
	return;
}

void sub_294180(X86Context& ctx, uint8_t* base) {
	// 0x294180: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x294188: movss [0x0056E268], xmm0
	X86_MEM_WRITE_u32(base, 0x56E268u, ctx.xmm[0].u32[0]);
	// 0x294190: ret
	return;
}

void sub_2941A0(X86Context& ctx, uint8_t* base) {
	// 0x2941A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2941A8: movss [0x0056E254], xmm0
	X86_MEM_WRITE_u32(base, 0x56E254u, ctx.xmm[0].u32[0]);
	// 0x2941B0: ret
	return;
}

void sub_2941C0(X86Context& ctx, uint8_t* base) {
	// 0x2941C0: movss xmm0, dword ptr [0x0056E254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E254u);
	// 0x2941C8: movss [0x0056E264], xmm0
	X86_MEM_WRITE_u32(base, 0x56E264u, ctx.xmm[0].u32[0]);
	// 0x2941D0: ret
	return;
}

void sub_2941E0(X86Context& ctx, uint8_t* base) {
	// 0x2941E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2941E8: movss [0x0056E1C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1C8u, ctx.xmm[0].u32[0]);
	// 0x2941F0: ret
	return;
}

void sub_294200(X86Context& ctx, uint8_t* base) {
	// 0x294200: movss xmm0, dword ptr [0x0056E1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1DCu);
	// 0x294208: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x294210: movss [0x0056E25C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E25Cu, ctx.xmm[0].u32[0]);
	// 0x294218: ret
	return;
}

void sub_294220(X86Context& ctx, uint8_t* base) {
	// 0x294220: movss xmm0, dword ptr [0x0056E1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1DCu);
	// 0x294228: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x294230: movss [0x0056E204], xmm0
	X86_MEM_WRITE_u32(base, 0x56E204u, ctx.xmm[0].u32[0]);
	// 0x294238: ret
	return;
}

void sub_294240(X86Context& ctx, uint8_t* base) {
	// 0x294240: movss xmm0, dword ptr [0x0056E1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1DCu);
	// 0x294248: subss xmm0, [0x0056E204]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E204u);
	// 0x294250: movss [0x0056E1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1E4u, ctx.xmm[0].u32[0]);
	// 0x294258: ret
	return;
}

void sub_294260(X86Context& ctx, uint8_t* base) {
	// 0x294260: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x294268: movss [0x0056E22C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E22Cu, ctx.xmm[0].u32[0]);
	// 0x294270: ret
	return;
}

void sub_294280(X86Context& ctx, uint8_t* base) {
	// 0x294280: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x294288: movss [0x0056E1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1E0u, ctx.xmm[0].u32[0]);
	// 0x294290: ret
	return;
}

void sub_2942A0(X86Context& ctx, uint8_t* base) {
	// 0x2942A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2942A8: movss [0x0056E1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1F0u, ctx.xmm[0].u32[0]);
	// 0x2942B0: ret
	return;
}

void sub_2942C0(X86Context& ctx, uint8_t* base) {
	// 0x2942C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2942C8: movss [0x0056E244], xmm0
	X86_MEM_WRITE_u32(base, 0x56E244u, ctx.xmm[0].u32[0]);
	// 0x2942D0: ret
	return;
}

void sub_2942E0(X86Context& ctx, uint8_t* base) {
	// 0x2942E0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2942E8: movss [0x0056E228], xmm0
	X86_MEM_WRITE_u32(base, 0x56E228u, ctx.xmm[0].u32[0]);
	// 0x2942F0: ret
	return;
}

void sub_294300(X86Context& ctx, uint8_t* base) {
	// 0x294300: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x294308: movss [0x0056E1D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1D8u, ctx.xmm[0].u32[0]);
	// 0x294310: ret
	return;
}

void sub_294320(X86Context& ctx, uint8_t* base) {
	// 0x294320: movss xmm0, dword ptr [0x0056E1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1F0u);
	// 0x294328: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x294330: movss [0x0056E1CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1CCu, ctx.xmm[0].u32[0]);
	// 0x294338: ret
	return;
}

void sub_294340(X86Context& ctx, uint8_t* base) {
	// 0x294340: movss xmm0, dword ptr [0x0056E244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E244u);
	// 0x294348: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x294350: movss [0x0056E210], xmm0
	X86_MEM_WRITE_u32(base, 0x56E210u, ctx.xmm[0].u32[0]);
	// 0x294358: ret
	return;
}

void sub_294360(X86Context& ctx, uint8_t* base) {
	// 0x294360: movss xmm0, dword ptr [0x0056E1CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1CCu);
	// 0x294368: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x294370: movss [0x0056E220], xmm0
	X86_MEM_WRITE_u32(base, 0x56E220u, ctx.xmm[0].u32[0]);
	// 0x294378: ret
	return;
}

void sub_294380(X86Context& ctx, uint8_t* base) {
	// 0x294380: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x294388: movss [0x0056E1C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1C4u, ctx.xmm[0].u32[0]);
	// 0x294390: ret
	return;
}

void sub_2943A0(X86Context& ctx, uint8_t* base) {
	// 0x2943A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2943A8: movss [0x0056E1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1F4u, ctx.xmm[0].u32[0]);
	// 0x2943B0: ret
	return;
}

void sub_2943C0(X86Context& ctx, uint8_t* base) {
	// 0x2943C0: movss xmm0, dword ptr [0x0056E1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1F0u);
	// 0x2943C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2943D0: movss [0x0056E200], xmm0
	X86_MEM_WRITE_u32(base, 0x56E200u, ctx.xmm[0].u32[0]);
	// 0x2943D8: ret
	return;
}

void sub_2943E0(X86Context& ctx, uint8_t* base) {
	// 0x2943E0: movss xmm0, dword ptr [0x0056E244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E244u);
	// 0x2943E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2943F0: movss [0x0056E248], xmm0
	X86_MEM_WRITE_u32(base, 0x56E248u, ctx.xmm[0].u32[0]);
	// 0x2943F8: ret
	return;
}

void sub_294400(X86Context& ctx, uint8_t* base) {
	// 0x294400: movss xmm0, dword ptr [0x0056E200]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E200u);
	// 0x294408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294410: movss [0x0056E234], xmm0
	X86_MEM_WRITE_u32(base, 0x56E234u, ctx.xmm[0].u32[0]);
	// 0x294418: ret
	return;
}

void sub_294420(X86Context& ctx, uint8_t* base) {
	// 0x294420: movss xmm0, dword ptr [0x0056E248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E248u);
	// 0x294428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294430: movss [0x0056E258], xmm0
	X86_MEM_WRITE_u32(base, 0x56E258u, ctx.xmm[0].u32[0]);
	// 0x294438: ret
	return;
}

void sub_294440(X86Context& ctx, uint8_t* base) {
	// 0x294440: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x294448: movss [0x0056E1D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1D0u, ctx.xmm[0].u32[0]);
	// 0x294450: ret
	return;
}

void sub_294460(X86Context& ctx, uint8_t* base) {
	// 0x294460: movss xmm0, dword ptr [0x0056E1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1F0u);
	// 0x294468: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294470: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x294478: movss [0x0056E240], xmm0
	X86_MEM_WRITE_u32(base, 0x56E240u, ctx.xmm[0].u32[0]);
	// 0x294480: ret
	return;
}

void sub_294490(X86Context& ctx, uint8_t* base) {
	// 0x294490: movss xmm0, dword ptr [0x0056E244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E244u);
	// 0x294498: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2944A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2944A8: movss [0x0056E1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1E8u, ctx.xmm[0].u32[0]);
	// 0x2944B0: ret
	return;
}

void sub_2944C0(X86Context& ctx, uint8_t* base) {
	// 0x2944C0: movss xmm0, dword ptr [0x0056E1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1F0u);
	// 0x2944C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2944D0: movss [0x0056E1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1ECu, ctx.xmm[0].u32[0]);
	// 0x2944D8: ret
	return;
}

void sub_2944E0(X86Context& ctx, uint8_t* base) {
	// 0x2944E0: movss xmm0, dword ptr [0x0056E244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E244u);
	// 0x2944E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2944F0: movss [0x0056E24C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E24Cu, ctx.xmm[0].u32[0]);
	// 0x2944F8: ret
	return;
}

void sub_294500(X86Context& ctx, uint8_t* base) {
	// 0x294500: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x294508: movss [0x0056E1D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1D4u, ctx.xmm[0].u32[0]);
	// 0x294510: ret
	return;
}

void sub_294520(X86Context& ctx, uint8_t* base) {
	// 0x294520: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x294528: movss [0x0056E1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1FCu, ctx.xmm[0].u32[0]);
	// 0x294530: ret
	return;
}

void sub_294540(X86Context& ctx, uint8_t* base) {
	// 0x294540: movss xmm0, dword ptr [0x0056E1D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1D4u);
	// 0x294548: movss [0x0056E260], xmm0
	X86_MEM_WRITE_u32(base, 0x56E260u, ctx.xmm[0].u32[0]);
	// 0x294550: ret
	return;
}

void sub_294560(X86Context& ctx, uint8_t* base) {
	// 0x294560: movss xmm0, dword ptr [0x0056E244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E244u);
	// 0x294568: subss xmm0, [0x0056E1D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E1D4u);
	// 0x294570: movss [0x0056E224], xmm0
	X86_MEM_WRITE_u32(base, 0x56E224u, ctx.xmm[0].u32[0]);
	// 0x294578: ret
	return;
}

void sub_294580(X86Context& ctx, uint8_t* base) {
	// 0x294580: movss xmm0, dword ptr [0x0056E224]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E224u);
	// 0x294588: subss xmm0, [0x0056E1FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E1FCu);
	// 0x294590: movss [0x0056E21C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E21Cu, ctx.xmm[0].u32[0]);
	// 0x294598: ret
	return;
}

void sub_2945A0(X86Context& ctx, uint8_t* base) {
	// 0x2945A0: movss xmm0, dword ptr [0x0056E24C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E24Cu);
	// 0x2945A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2945B0: movss [0x0056E20C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E20Cu, ctx.xmm[0].u32[0]);
	// 0x2945B8: ret
	return;
}

void sub_2945C0(X86Context& ctx, uint8_t* base) {
	// 0x2945C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2945C8: movss [0x0056E1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1F8u, ctx.xmm[0].u32[0]);
	// 0x2945D0: ret
	return;
}

void sub_2945E0(X86Context& ctx, uint8_t* base) {
	// 0x2945E0: movss xmm0, dword ptr [0x0056E20C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E20Cu);
	// 0x2945E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2945F0: movss [0x0056E23C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E23Cu, ctx.xmm[0].u32[0]);
	// 0x2945F8: ret
	return;
}

void sub_294600(X86Context& ctx, uint8_t* base) {
	// 0x294600: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x294608: movss [0x0056E2C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2C0u, ctx.xmm[0].u32[0]);
	// 0x294610: ret
	return;
}

void sub_294620(X86Context& ctx, uint8_t* base) {
	// 0x294620: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x294628: movss [0x0056E2DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2DCu, ctx.xmm[0].u32[0]);
	// 0x294630: ret
	return;
}

void sub_294640(X86Context& ctx, uint8_t* base) {
	// 0x294640: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x294648: movss [0x0056E2B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2B4u, ctx.xmm[0].u32[0]);
	// 0x294650: ret
	return;
}

void sub_294660(X86Context& ctx, uint8_t* base) {
	// 0x294660: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x294668: movss [0x0056E26C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E26Cu, ctx.xmm[0].u32[0]);
	// 0x294670: ret
	return;
}

void sub_294680(X86Context& ctx, uint8_t* base) {
	// 0x294680: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x294688: movss [0x0056E2C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2C4u, ctx.xmm[0].u32[0]);
	// 0x294690: ret
	return;
}

void sub_2946A0(X86Context& ctx, uint8_t* base) {
	// 0x2946A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2946A8: movss [0x0056E288], xmm0
	X86_MEM_WRITE_u32(base, 0x56E288u, ctx.xmm[0].u32[0]);
	// 0x2946B0: ret
	return;
}

void sub_2946C0(X86Context& ctx, uint8_t* base) {
	// 0x2946C0: movss xmm0, dword ptr [0x0056E2C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2C4u);
	// 0x2946C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2946D0: movss [0x0056E2FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2FCu, ctx.xmm[0].u32[0]);
	// 0x2946D8: ret
	return;
}

void sub_2946E0(X86Context& ctx, uint8_t* base) {
	// 0x2946E0: movss xmm0, dword ptr [0x0056E288]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E288u);
	// 0x2946E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2946F0: movss [0x0056E2E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2E4u, ctx.xmm[0].u32[0]);
	// 0x2946F8: ret
	return;
}

void sub_294700(X86Context& ctx, uint8_t* base) {
	// 0x294700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x294708: movss [0x0056E314], xmm0
	X86_MEM_WRITE_u32(base, 0x56E314u, ctx.xmm[0].u32[0]);
	// 0x294710: ret
	return;
}

void sub_294720(X86Context& ctx, uint8_t* base) {
	// 0x294720: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x294728: movss [0x0056E300], xmm0
	X86_MEM_WRITE_u32(base, 0x56E300u, ctx.xmm[0].u32[0]);
	// 0x294730: ret
	return;
}

void sub_294740(X86Context& ctx, uint8_t* base) {
	// 0x294740: movss xmm0, dword ptr [0x0056E300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E300u);
	// 0x294748: movss [0x0056E310], xmm0
	X86_MEM_WRITE_u32(base, 0x56E310u, ctx.xmm[0].u32[0]);
	// 0x294750: ret
	return;
}

void sub_294760(X86Context& ctx, uint8_t* base) {
	// 0x294760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x294768: movss [0x0056E274], xmm0
	X86_MEM_WRITE_u32(base, 0x56E274u, ctx.xmm[0].u32[0]);
	// 0x294770: ret
	return;
}

void sub_294780(X86Context& ctx, uint8_t* base) {
	// 0x294780: movss xmm0, dword ptr [0x0056E288]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E288u);
	// 0x294788: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x294790: movss [0x0056E308], xmm0
	X86_MEM_WRITE_u32(base, 0x56E308u, ctx.xmm[0].u32[0]);
	// 0x294798: ret
	return;
}

void sub_2947A0(X86Context& ctx, uint8_t* base) {
	// 0x2947A0: movss xmm0, dword ptr [0x0056E288]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E288u);
	// 0x2947A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2947B0: movss [0x0056E2B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2B0u, ctx.xmm[0].u32[0]);
	// 0x2947B8: ret
	return;
}

void sub_2947C0(X86Context& ctx, uint8_t* base) {
	// 0x2947C0: movss xmm0, dword ptr [0x0056E288]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E288u);
	// 0x2947C8: subss xmm0, [0x0056E2B0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E2B0u);
	// 0x2947D0: movss [0x0056E290], xmm0
	X86_MEM_WRITE_u32(base, 0x56E290u, ctx.xmm[0].u32[0]);
	// 0x2947D8: ret
	return;
}

void sub_2947E0(X86Context& ctx, uint8_t* base) {
	// 0x2947E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2947E8: movss [0x0056E2D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2D8u, ctx.xmm[0].u32[0]);
	// 0x2947F0: ret
	return;
}

void sub_294800(X86Context& ctx, uint8_t* base) {
	// 0x294800: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x294808: movss [0x0056E28C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E28Cu, ctx.xmm[0].u32[0]);
	// 0x294810: ret
	return;
}

void sub_294820(X86Context& ctx, uint8_t* base) {
	// 0x294820: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x294828: movss [0x0056E29C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E29Cu, ctx.xmm[0].u32[0]);
	// 0x294830: ret
	return;
}

void sub_294840(X86Context& ctx, uint8_t* base) {
	// 0x294840: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x294848: movss [0x0056E2F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2F0u, ctx.xmm[0].u32[0]);
	// 0x294850: ret
	return;
}

void sub_294860(X86Context& ctx, uint8_t* base) {
	// 0x294860: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x294868: movss [0x0056E2D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2D4u, ctx.xmm[0].u32[0]);
	// 0x294870: ret
	return;
}

void sub_294880(X86Context& ctx, uint8_t* base) {
	// 0x294880: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x294888: movss [0x0056E284], xmm0
	X86_MEM_WRITE_u32(base, 0x56E284u, ctx.xmm[0].u32[0]);
	// 0x294890: ret
	return;
}

void sub_2948A0(X86Context& ctx, uint8_t* base) {
	// 0x2948A0: movss xmm0, dword ptr [0x0056E29C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E29Cu);
	// 0x2948A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2948B0: movss [0x0056E278], xmm0
	X86_MEM_WRITE_u32(base, 0x56E278u, ctx.xmm[0].u32[0]);
	// 0x2948B8: ret
	return;
}

void sub_2948C0(X86Context& ctx, uint8_t* base) {
	// 0x2948C0: movss xmm0, dword ptr [0x0056E2F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F0u);
	// 0x2948C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2948D0: movss [0x0056E2BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2BCu, ctx.xmm[0].u32[0]);
	// 0x2948D8: ret
	return;
}

void sub_2948E0(X86Context& ctx, uint8_t* base) {
	// 0x2948E0: movss xmm0, dword ptr [0x0056E278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E278u);
	// 0x2948E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2948F0: movss [0x0056E2CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2CCu, ctx.xmm[0].u32[0]);
	// 0x2948F8: ret
	return;
}

void sub_294900(X86Context& ctx, uint8_t* base) {
	// 0x294900: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x294908: movss [0x0056E270], xmm0
	X86_MEM_WRITE_u32(base, 0x56E270u, ctx.xmm[0].u32[0]);
	// 0x294910: ret
	return;
}

void sub_294920(X86Context& ctx, uint8_t* base) {
	// 0x294920: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x294928: movss [0x0056E2A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2A0u, ctx.xmm[0].u32[0]);
	// 0x294930: ret
	return;
}

void sub_294940(X86Context& ctx, uint8_t* base) {
	// 0x294940: movss xmm0, dword ptr [0x0056E29C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E29Cu);
	// 0x294948: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x294950: movss [0x0056E2AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2ACu, ctx.xmm[0].u32[0]);
	// 0x294958: ret
	return;
}

void sub_294960(X86Context& ctx, uint8_t* base) {
	// 0x294960: movss xmm0, dword ptr [0x0056E2F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F0u);
	// 0x294968: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x294970: movss [0x0056E2F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2F4u, ctx.xmm[0].u32[0]);
	// 0x294978: ret
	return;
}

void sub_294980(X86Context& ctx, uint8_t* base) {
	// 0x294980: movss xmm0, dword ptr [0x0056E2AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2ACu);
	// 0x294988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294990: movss [0x0056E2E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2E0u, ctx.xmm[0].u32[0]);
	// 0x294998: ret
	return;
}

void sub_2949A0(X86Context& ctx, uint8_t* base) {
	// 0x2949A0: movss xmm0, dword ptr [0x0056E2F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F4u);
	// 0x2949A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2949B0: movss [0x0056E304], xmm0
	X86_MEM_WRITE_u32(base, 0x56E304u, ctx.xmm[0].u32[0]);
	// 0x2949B8: ret
	return;
}

void sub_2949C0(X86Context& ctx, uint8_t* base) {
	// 0x2949C0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2949C8: movss [0x0056E27C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E27Cu, ctx.xmm[0].u32[0]);
	// 0x2949D0: ret
	return;
}

void sub_2949E0(X86Context& ctx, uint8_t* base) {
	// 0x2949E0: movss xmm0, dword ptr [0x0056E29C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E29Cu);
	// 0x2949E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2949F0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2949F8: movss [0x0056E2EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2ECu, ctx.xmm[0].u32[0]);
	// 0x294A00: ret
	return;
}

void sub_294A10(X86Context& ctx, uint8_t* base) {
	// 0x294A10: movss xmm0, dword ptr [0x0056E2F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F0u);
	// 0x294A18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294A20: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x294A28: movss [0x0056E294], xmm0
	X86_MEM_WRITE_u32(base, 0x56E294u, ctx.xmm[0].u32[0]);
	// 0x294A30: ret
	return;
}

void sub_294A40(X86Context& ctx, uint8_t* base) {
	// 0x294A40: movss xmm0, dword ptr [0x0056E29C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E29Cu);
	// 0x294A48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294A50: movss [0x0056E298], xmm0
	X86_MEM_WRITE_u32(base, 0x56E298u, ctx.xmm[0].u32[0]);
	// 0x294A58: ret
	return;
}

void sub_294A60(X86Context& ctx, uint8_t* base) {
	// 0x294A60: movss xmm0, dword ptr [0x0056E2F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F0u);
	// 0x294A68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294A70: movss [0x0056E2F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2F8u, ctx.xmm[0].u32[0]);
	// 0x294A78: ret
	return;
}

void sub_294A80(X86Context& ctx, uint8_t* base) {
	// 0x294A80: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x294A88: movss [0x0056E280], xmm0
	X86_MEM_WRITE_u32(base, 0x56E280u, ctx.xmm[0].u32[0]);
	// 0x294A90: ret
	return;
}

void sub_294AA0(X86Context& ctx, uint8_t* base) {
	// 0x294AA0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x294AA8: movss [0x0056E2A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2A8u, ctx.xmm[0].u32[0]);
	// 0x294AB0: ret
	return;
}

void sub_294AC0(X86Context& ctx, uint8_t* base) {
	// 0x294AC0: movss xmm0, dword ptr [0x0056E280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E280u);
	// 0x294AC8: movss [0x0056E30C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E30Cu, ctx.xmm[0].u32[0]);
	// 0x294AD0: ret
	return;
}

void sub_294AE0(X86Context& ctx, uint8_t* base) {
	// 0x294AE0: movss xmm0, dword ptr [0x0056E2F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F0u);
	// 0x294AE8: subss xmm0, [0x0056E280]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E280u);
	// 0x294AF0: movss [0x0056E2D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2D0u, ctx.xmm[0].u32[0]);
	// 0x294AF8: ret
	return;
}

void sub_294B00(X86Context& ctx, uint8_t* base) {
	// 0x294B00: movss xmm0, dword ptr [0x0056E2D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2D0u);
	// 0x294B08: subss xmm0, [0x0056E2A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E2A8u);
	// 0x294B10: movss [0x0056E2C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2C8u, ctx.xmm[0].u32[0]);
	// 0x294B18: ret
	return;
}

void sub_294B20(X86Context& ctx, uint8_t* base) {
	// 0x294B20: movss xmm0, dword ptr [0x0056E2F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2F8u);
	// 0x294B28: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x294B30: movss [0x0056E2B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2B8u, ctx.xmm[0].u32[0]);
	// 0x294B38: ret
	return;
}

void sub_294B40(X86Context& ctx, uint8_t* base) {
	// 0x294B40: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x294B48: movss [0x0056E2A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2A4u, ctx.xmm[0].u32[0]);
	// 0x294B50: ret
	return;
}

void sub_294B60(X86Context& ctx, uint8_t* base) {
	// 0x294B60: movss xmm0, dword ptr [0x0056E2B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E2B8u);
	// 0x294B68: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x294B70: movss [0x0056E2E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E2E8u, ctx.xmm[0].u32[0]);
	// 0x294B78: ret
	return;
}

void sub_294B80(X86Context& ctx, uint8_t* base) {
	// 0x294B80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x294B88: movss [0x0056E380], xmm0
	X86_MEM_WRITE_u32(base, 0x56E380u, ctx.xmm[0].u32[0]);
	// 0x294B90: ret
	return;
}

void sub_294BA0(X86Context& ctx, uint8_t* base) {
	// 0x294BA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x294BA8: movss [0x0056E3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3A0u, ctx.xmm[0].u32[0]);
	// 0x294BB0: ret
	return;
}

void sub_294BC0(X86Context& ctx, uint8_t* base) {
	// 0x294BC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x294BC8: movss [0x0056E368], xmm0
	X86_MEM_WRITE_u32(base, 0x56E368u, ctx.xmm[0].u32[0]);
	// 0x294BD0: ret
	return;
}

void sub_294BE0(X86Context& ctx, uint8_t* base) {
	// 0x294BE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x294BE8: movss [0x0056E31C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E31Cu, ctx.xmm[0].u32[0]);
	// 0x294BF0: ret
	return;
}

void sub_294C00(X86Context& ctx, uint8_t* base) {
	// 0x294C00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x294C08: movss [0x0056E384], xmm0
	X86_MEM_WRITE_u32(base, 0x56E384u, ctx.xmm[0].u32[0]);
	// 0x294C10: ret
	return;
}

void sub_294C20(X86Context& ctx, uint8_t* base) {
	// 0x294C20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x294C28: movss [0x0056E338], xmm0
	X86_MEM_WRITE_u32(base, 0x56E338u, ctx.xmm[0].u32[0]);
	// 0x294C30: ret
	return;
}

void sub_294C40(X86Context& ctx, uint8_t* base) {
	// 0x294C40: movss xmm0, dword ptr [0x0056E384]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E384u);
	// 0x294C48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x294C50: movss [0x0056E3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3C0u, ctx.xmm[0].u32[0]);
	// 0x294C58: ret
	return;
}

void sub_294C60(X86Context& ctx, uint8_t* base) {
	// 0x294C60: movss xmm0, dword ptr [0x0056E338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E338u);
	// 0x294C68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x294C70: movss [0x0056E3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3A8u, ctx.xmm[0].u32[0]);
	// 0x294C78: ret
	return;
}

void sub_294C80(X86Context& ctx, uint8_t* base) {
	// 0x294C80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x294C88: movss [0x0056E3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3D8u, ctx.xmm[0].u32[0]);
	// 0x294C90: ret
	return;
}

void sub_294CA0(X86Context& ctx, uint8_t* base) {
	// 0x294CA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x294CA8: movss [0x0056E3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3C4u, ctx.xmm[0].u32[0]);
	// 0x294CB0: ret
	return;
}

void sub_294CC0(X86Context& ctx, uint8_t* base) {
	// 0x294CC0: movss xmm0, dword ptr [0x0056E3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3C4u);
	// 0x294CC8: movss [0x0056E3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3D4u, ctx.xmm[0].u32[0]);
	// 0x294CD0: ret
	return;
}

void sub_294CE0(X86Context& ctx, uint8_t* base) {
	// 0x294CE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x294CE8: movss [0x0056E324], xmm0
	X86_MEM_WRITE_u32(base, 0x56E324u, ctx.xmm[0].u32[0]);
	// 0x294CF0: ret
	return;
}

void sub_294D00(X86Context& ctx, uint8_t* base) {
	// 0x294D00: movss xmm0, dword ptr [0x0056E338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E338u);
	// 0x294D08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x294D10: movss [0x0056E3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3CCu, ctx.xmm[0].u32[0]);
	// 0x294D18: ret
	return;
}

void sub_294D20(X86Context& ctx, uint8_t* base) {
	// 0x294D20: movss xmm0, dword ptr [0x0056E338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E338u);
	// 0x294D28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x294D30: movss [0x0056E364], xmm0
	X86_MEM_WRITE_u32(base, 0x56E364u, ctx.xmm[0].u32[0]);
	// 0x294D38: ret
	return;
}

void sub_294D40(X86Context& ctx, uint8_t* base) {
	// 0x294D40: movss xmm0, dword ptr [0x0056E338]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E338u);
	// 0x294D48: subss xmm0, [0x0056E364]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E364u);
	// 0x294D50: movss [0x0056E344], xmm0
	X86_MEM_WRITE_u32(base, 0x56E344u, ctx.xmm[0].u32[0]);
	// 0x294D58: ret
	return;
}

void sub_294D60(X86Context& ctx, uint8_t* base) {
	// 0x294D60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x294D68: movss [0x0056E39C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E39Cu, ctx.xmm[0].u32[0]);
	// 0x294D70: ret
	return;
}

void sub_294D80(X86Context& ctx, uint8_t* base) {
	// 0x294D80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x294D88: movss [0x0056E33C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E33Cu, ctx.xmm[0].u32[0]);
	// 0x294D90: ret
	return;
}

void sub_294DA0(X86Context& ctx, uint8_t* base) {
	// 0x294DA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x294DA8: movss [0x0056E350], xmm0
	X86_MEM_WRITE_u32(base, 0x56E350u, ctx.xmm[0].u32[0]);
	// 0x294DB0: ret
	return;
}

void sub_294DC0(X86Context& ctx, uint8_t* base) {
	// 0x294DC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x294DC8: movss [0x0056E3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3B4u, ctx.xmm[0].u32[0]);
	// 0x294DD0: ret
	return;
}

void sub_294DE0(X86Context& ctx, uint8_t* base) {
	// 0x294DE0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x294DE8: movss [0x0056E394], xmm0
	X86_MEM_WRITE_u32(base, 0x56E394u, ctx.xmm[0].u32[0]);
	// 0x294DF0: ret
	return;
}

void sub_294E00(X86Context& ctx, uint8_t* base) {
	// 0x294E00: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x294E08: movss [0x0056E334], xmm0
	X86_MEM_WRITE_u32(base, 0x56E334u, ctx.xmm[0].u32[0]);
	// 0x294E10: ret
	return;
}

void sub_294E20(X86Context& ctx, uint8_t* base) {
	// 0x294E20: movss xmm0, dword ptr [0x0056E350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E350u);
	// 0x294E28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x294E30: movss [0x0056E328], xmm0
	X86_MEM_WRITE_u32(base, 0x56E328u, ctx.xmm[0].u32[0]);
	// 0x294E38: ret
	return;
}

void sub_294E40(X86Context& ctx, uint8_t* base) {
	// 0x294E40: movss xmm0, dword ptr [0x0056E3B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3B4u);
	// 0x294E48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x294E50: movss [0x0056E37C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E37Cu, ctx.xmm[0].u32[0]);
	// 0x294E58: ret
	return;
}

void sub_294E60(X86Context& ctx, uint8_t* base) {
	// 0x294E60: movss xmm0, dword ptr [0x0056E328]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E328u);
	// 0x294E68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x294E70: movss [0x0056E38C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E38Cu, ctx.xmm[0].u32[0]);
	// 0x294E78: ret
	return;
}

void sub_294E80(X86Context& ctx, uint8_t* base) {
	// 0x294E80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x294E88: movss [0x0056E320], xmm0
	X86_MEM_WRITE_u32(base, 0x56E320u, ctx.xmm[0].u32[0]);
	// 0x294E90: ret
	return;
}

void sub_294EA0(X86Context& ctx, uint8_t* base) {
	// 0x294EA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x294EA8: movss [0x0056E354], xmm0
	X86_MEM_WRITE_u32(base, 0x56E354u, ctx.xmm[0].u32[0]);
	// 0x294EB0: ret
	return;
}

void sub_294EC0(X86Context& ctx, uint8_t* base) {
	// 0x294EC0: movss xmm0, dword ptr [0x0056E350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E350u);
	// 0x294EC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x294ED0: movss [0x0056E360], xmm0
	X86_MEM_WRITE_u32(base, 0x56E360u, ctx.xmm[0].u32[0]);
	// 0x294ED8: ret
	return;
}

void sub_294EE0(X86Context& ctx, uint8_t* base) {
	// 0x294EE0: movss xmm0, dword ptr [0x0056E3B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3B4u);
	// 0x294EE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x294EF0: movss [0x0056E3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3B8u, ctx.xmm[0].u32[0]);
	// 0x294EF8: ret
	return;
}

void sub_294F00(X86Context& ctx, uint8_t* base) {
	// 0x294F00: movss xmm0, dword ptr [0x0056E360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E360u);
	// 0x294F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294F10: movss [0x0056E3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3A4u, ctx.xmm[0].u32[0]);
	// 0x294F18: ret
	return;
}

void sub_294F20(X86Context& ctx, uint8_t* base) {
	// 0x294F20: movss xmm0, dword ptr [0x0056E3B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3B8u);
	// 0x294F28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294F30: movss [0x0056E3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3C8u, ctx.xmm[0].u32[0]);
	// 0x294F38: ret
	return;
}

void sub_294F40(X86Context& ctx, uint8_t* base) {
	// 0x294F40: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x294F48: movss [0x0056E32C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E32Cu, ctx.xmm[0].u32[0]);
	// 0x294F50: ret
	return;
}

void sub_294F60(X86Context& ctx, uint8_t* base) {
	// 0x294F60: movss xmm0, dword ptr [0x0056E350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E350u);
	// 0x294F68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294F70: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x294F78: movss [0x0056E3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3B0u, ctx.xmm[0].u32[0]);
	// 0x294F80: ret
	return;
}

void sub_294F90(X86Context& ctx, uint8_t* base) {
	// 0x294F90: movss xmm0, dword ptr [0x0056E3B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3B4u);
	// 0x294F98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294FA0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x294FA8: movss [0x0056E348], xmm0
	X86_MEM_WRITE_u32(base, 0x56E348u, ctx.xmm[0].u32[0]);
	// 0x294FB0: ret
	return;
}

void sub_294FC0(X86Context& ctx, uint8_t* base) {
	// 0x294FC0: movss xmm0, dword ptr [0x0056E350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E350u);
	// 0x294FC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294FD0: movss [0x0056E34C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E34Cu, ctx.xmm[0].u32[0]);
	// 0x294FD8: ret
	return;
}

void sub_294FE0(X86Context& ctx, uint8_t* base) {
	// 0x294FE0: movss xmm0, dword ptr [0x0056E3B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3B4u);
	// 0x294FE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x294FF0: movss [0x0056E3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3BCu, ctx.xmm[0].u32[0]);
	// 0x294FF8: ret
	return;
}

void sub_295000(X86Context& ctx, uint8_t* base) {
	// 0x295000: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x295008: movss [0x0056E330], xmm0
	X86_MEM_WRITE_u32(base, 0x56E330u, ctx.xmm[0].u32[0]);
	// 0x295010: ret
	return;
}

void sub_295020(X86Context& ctx, uint8_t* base) {
	// 0x295020: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x295028: movss [0x0056E35C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E35Cu, ctx.xmm[0].u32[0]);
	// 0x295030: ret
	return;
}

void sub_295040(X86Context& ctx, uint8_t* base) {
	// 0x295040: movss xmm0, dword ptr [0x0056E330]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E330u);
	// 0x295048: movss [0x0056E3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3D0u, ctx.xmm[0].u32[0]);
	// 0x295050: ret
	return;
}

void sub_295060(X86Context& ctx, uint8_t* base) {
	// 0x295060: movss xmm0, dword ptr [0x0056E3B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3B4u);
	// 0x295068: subss xmm0, [0x0056E330]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E330u);
	// 0x295070: movss [0x0056E390], xmm0
	X86_MEM_WRITE_u32(base, 0x56E390u, ctx.xmm[0].u32[0]);
	// 0x295078: ret
	return;
}

void sub_295080(X86Context& ctx, uint8_t* base) {
	// 0x295080: movss xmm0, dword ptr [0x0056E390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E390u);
	// 0x295088: subss xmm0, [0x0056E35C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E35Cu);
	// 0x295090: movss [0x0056E388], xmm0
	X86_MEM_WRITE_u32(base, 0x56E388u, ctx.xmm[0].u32[0]);
	// 0x295098: ret
	return;
}

void sub_2950A0(X86Context& ctx, uint8_t* base) {
	// 0x2950A0: movss xmm0, dword ptr [0x0056E3BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3BCu);
	// 0x2950A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2950B0: movss [0x0056E378], xmm0
	X86_MEM_WRITE_u32(base, 0x56E378u, ctx.xmm[0].u32[0]);
	// 0x2950B8: ret
	return;
}

void sub_2950C0(X86Context& ctx, uint8_t* base) {
	// 0x2950C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2950C8: movss [0x0056E358], xmm0
	X86_MEM_WRITE_u32(base, 0x56E358u, ctx.xmm[0].u32[0]);
	// 0x2950D0: ret
	return;
}

void sub_2950E0(X86Context& ctx, uint8_t* base) {
	// 0x2950E0: movss xmm0, dword ptr [0x0056E378]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E378u);
	// 0x2950E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2950F0: movss [0x0056E3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3ACu, ctx.xmm[0].u32[0]);
	// 0x2950F8: ret
	return;
}

void sub_295100(X86Context& ctx, uint8_t* base) {
	// 0x295100: movss xmm0, dword ptr [0x0056E350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E350u);
	// 0x295108: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x295110: movss [0x00404C50], xmm0
	X86_MEM_WRITE_u32(base, 0x404C50u, ctx.xmm[0].u32[0]);
	// 0x295118: ret
	return;
}

void sub_295120(X86Context& ctx, uint8_t* base) {
	// 0x295120: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x295128: movss [0x0056E318], xmm0
	X86_MEM_WRITE_u32(base, 0x56E318u, ctx.xmm[0].u32[0]);
	// 0x295130: ret
	return;
}

void sub_295140(X86Context& ctx, uint8_t* base) {
	// 0x295140: movss xmm0, dword ptr [0x003B207C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B207Cu);
	// 0x295148: movss [0x0056E340], xmm0
	X86_MEM_WRITE_u32(base, 0x56E340u, ctx.xmm[0].u32[0]);
	// 0x295150: ret
	return;
}

void sub_295160(X86Context& ctx, uint8_t* base) {
	// 0x295160: movss xmm0, dword ptr [0x00404C78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x404C78u);
	// 0x295168: addss xmm0, [0x00404C70]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x404C70u);
	// 0x295170: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x295178: movss [0x0056E370], xmm0
	X86_MEM_WRITE_u32(base, 0x56E370u, ctx.xmm[0].u32[0]);
	// 0x295180: movss xmm0, dword ptr [0x00404C74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x404C74u);
	// 0x295188: movss [0x0056E374], xmm0
	X86_MEM_WRITE_u32(base, 0x56E374u, ctx.xmm[0].u32[0]);
	// 0x295190: ret
	return;
}

void sub_2951A0(X86Context& ctx, uint8_t* base) {
	// 0x2951A0: movss xmm0, dword ptr [0x00404C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x404C7Cu);
	// 0x2951A8: movss [0x0056E398], xmm0
	X86_MEM_WRITE_u32(base, 0x56E398u, ctx.xmm[0].u32[0]);
	// 0x2951B0: ret
	return;
}

void sub_2951C0(X86Context& ctx, uint8_t* base) {
	// 0x2951C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2951C8: movss [0x0056E438], xmm0
	X86_MEM_WRITE_u32(base, 0x56E438u, ctx.xmm[0].u32[0]);
	// 0x2951D0: ret
	return;
}

void sub_2951E0(X86Context& ctx, uint8_t* base) {
	// 0x2951E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2951E8: movss [0x0056E454], xmm0
	X86_MEM_WRITE_u32(base, 0x56E454u, ctx.xmm[0].u32[0]);
	// 0x2951F0: ret
	return;
}

void sub_295200(X86Context& ctx, uint8_t* base) {
	// 0x295200: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x295208: movss [0x0056E428], xmm0
	X86_MEM_WRITE_u32(base, 0x56E428u, ctx.xmm[0].u32[0]);
	// 0x295210: ret
	return;
}

void sub_295220(X86Context& ctx, uint8_t* base) {
	// 0x295220: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x295228: movss [0x0056E3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3DCu, ctx.xmm[0].u32[0]);
	// 0x295230: ret
	return;
}

void sub_295240(X86Context& ctx, uint8_t* base) {
	// 0x295240: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x295248: movss [0x0056E43C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E43Cu, ctx.xmm[0].u32[0]);
	// 0x295250: ret
	return;
}

void sub_295260(X86Context& ctx, uint8_t* base) {
	// 0x295260: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x295268: movss [0x0056E3F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3F8u, ctx.xmm[0].u32[0]);
	// 0x295270: ret
	return;
}

void sub_295280(X86Context& ctx, uint8_t* base) {
	// 0x295280: movss xmm0, dword ptr [0x0056E43C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E43Cu);
	// 0x295288: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x295290: movss [0x0056E474], xmm0
	X86_MEM_WRITE_u32(base, 0x56E474u, ctx.xmm[0].u32[0]);
	// 0x295298: ret
	return;
}

void sub_2952A0(X86Context& ctx, uint8_t* base) {
	// 0x2952A0: movss xmm0, dword ptr [0x0056E3F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3F8u);
	// 0x2952A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2952B0: movss [0x0056E45C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E45Cu, ctx.xmm[0].u32[0]);
	// 0x2952B8: ret
	return;
}

void sub_2952C0(X86Context& ctx, uint8_t* base) {
	// 0x2952C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2952C8: movss [0x0056E48C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E48Cu, ctx.xmm[0].u32[0]);
	// 0x2952D0: ret
	return;
}

void sub_2952E0(X86Context& ctx, uint8_t* base) {
	// 0x2952E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2952E8: movss [0x0056E478], xmm0
	X86_MEM_WRITE_u32(base, 0x56E478u, ctx.xmm[0].u32[0]);
	// 0x2952F0: ret
	return;
}

void sub_295300(X86Context& ctx, uint8_t* base) {
	// 0x295300: movss xmm0, dword ptr [0x0056E478]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E478u);
	// 0x295308: movss [0x0056E488], xmm0
	X86_MEM_WRITE_u32(base, 0x56E488u, ctx.xmm[0].u32[0]);
	// 0x295310: ret
	return;
}

void sub_295320(X86Context& ctx, uint8_t* base) {
	// 0x295320: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x295328: movss [0x0056E3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3E4u, ctx.xmm[0].u32[0]);
	// 0x295330: ret
	return;
}

void sub_295340(X86Context& ctx, uint8_t* base) {
	// 0x295340: movss xmm0, dword ptr [0x0056E3F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3F8u);
	// 0x295348: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x295350: movss [0x0056E480], xmm0
	X86_MEM_WRITE_u32(base, 0x56E480u, ctx.xmm[0].u32[0]);
	// 0x295358: ret
	return;
}

void sub_295360(X86Context& ctx, uint8_t* base) {
	// 0x295360: movss xmm0, dword ptr [0x0056E3F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3F8u);
	// 0x295368: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x295370: movss [0x0056E424], xmm0
	X86_MEM_WRITE_u32(base, 0x56E424u, ctx.xmm[0].u32[0]);
	// 0x295378: ret
	return;
}

void sub_295380(X86Context& ctx, uint8_t* base) {
	// 0x295380: movss xmm0, dword ptr [0x0056E3F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3F8u);
	// 0x295388: subss xmm0, [0x0056E424]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E424u);
	// 0x295390: movss [0x0056E400], xmm0
	X86_MEM_WRITE_u32(base, 0x56E400u, ctx.xmm[0].u32[0]);
	// 0x295398: ret
	return;
}

void sub_2953A0(X86Context& ctx, uint8_t* base) {
	// 0x2953A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2953A8: movss [0x0056E450], xmm0
	X86_MEM_WRITE_u32(base, 0x56E450u, ctx.xmm[0].u32[0]);
	// 0x2953B0: ret
	return;
}

void sub_2953C0(X86Context& ctx, uint8_t* base) {
	// 0x2953C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2953C8: movss [0x0056E3FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3FCu, ctx.xmm[0].u32[0]);
	// 0x2953D0: ret
	return;
}

void sub_2953E0(X86Context& ctx, uint8_t* base) {
	// 0x2953E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2953E8: movss [0x0056E410], xmm0
	X86_MEM_WRITE_u32(base, 0x56E410u, ctx.xmm[0].u32[0]);
	// 0x2953F0: ret
	return;
}

void sub_295400(X86Context& ctx, uint8_t* base) {
	// 0x295400: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x295408: movss [0x0056E468], xmm0
	X86_MEM_WRITE_u32(base, 0x56E468u, ctx.xmm[0].u32[0]);
	// 0x295410: ret
	return;
}

void sub_295420(X86Context& ctx, uint8_t* base) {
	// 0x295420: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x295428: movss [0x0056E44C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E44Cu, ctx.xmm[0].u32[0]);
	// 0x295430: ret
	return;
}

void sub_295440(X86Context& ctx, uint8_t* base) {
	// 0x295440: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x295448: movss [0x0056E3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3F4u, ctx.xmm[0].u32[0]);
	// 0x295450: ret
	return;
}

void sub_295460(X86Context& ctx, uint8_t* base) {
	// 0x295460: movss xmm0, dword ptr [0x0056E410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E410u);
	// 0x295468: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x295470: movss [0x0056E3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3E8u, ctx.xmm[0].u32[0]);
	// 0x295478: ret
	return;
}

void sub_295480(X86Context& ctx, uint8_t* base) {
	// 0x295480: movss xmm0, dword ptr [0x0056E468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E468u);
	// 0x295488: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x295490: movss [0x0056E430], xmm0
	X86_MEM_WRITE_u32(base, 0x56E430u, ctx.xmm[0].u32[0]);
	// 0x295498: ret
	return;
}

void sub_2954A0(X86Context& ctx, uint8_t* base) {
	// 0x2954A0: movss xmm0, dword ptr [0x0056E3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3E8u);
	// 0x2954A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2954B0: movss [0x0056E444], xmm0
	X86_MEM_WRITE_u32(base, 0x56E444u, ctx.xmm[0].u32[0]);
	// 0x2954B8: ret
	return;
}

void sub_2954C0(X86Context& ctx, uint8_t* base) {
	// 0x2954C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2954C8: movss [0x0056E3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3E0u, ctx.xmm[0].u32[0]);
	// 0x2954D0: ret
	return;
}

void sub_2954E0(X86Context& ctx, uint8_t* base) {
	// 0x2954E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2954E8: movss [0x0056E414], xmm0
	X86_MEM_WRITE_u32(base, 0x56E414u, ctx.xmm[0].u32[0]);
	// 0x2954F0: ret
	return;
}

void sub_295500(X86Context& ctx, uint8_t* base) {
	// 0x295500: movss xmm0, dword ptr [0x0056E410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E410u);
	// 0x295508: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x295510: movss [0x0056E420], xmm0
	X86_MEM_WRITE_u32(base, 0x56E420u, ctx.xmm[0].u32[0]);
	// 0x295518: ret
	return;
}

void sub_295520(X86Context& ctx, uint8_t* base) {
	// 0x295520: movss xmm0, dword ptr [0x0056E468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E468u);
	// 0x295528: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x295530: movss [0x0056E46C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E46Cu, ctx.xmm[0].u32[0]);
	// 0x295538: ret
	return;
}

void sub_295540(X86Context& ctx, uint8_t* base) {
	// 0x295540: movss xmm0, dword ptr [0x0056E420]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E420u);
	// 0x295548: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295550: movss [0x0056E458], xmm0
	X86_MEM_WRITE_u32(base, 0x56E458u, ctx.xmm[0].u32[0]);
	// 0x295558: ret
	return;
}

void sub_295560(X86Context& ctx, uint8_t* base) {
	// 0x295560: movss xmm0, dword ptr [0x0056E46C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E46Cu);
	// 0x295568: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295570: movss [0x0056E47C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E47Cu, ctx.xmm[0].u32[0]);
	// 0x295578: ret
	return;
}

void sub_295580(X86Context& ctx, uint8_t* base) {
	// 0x295580: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x295588: movss [0x0056E3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3ECu, ctx.xmm[0].u32[0]);
	// 0x295590: ret
	return;
}

void sub_2955A0(X86Context& ctx, uint8_t* base) {
	// 0x2955A0: movss xmm0, dword ptr [0x0056E410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E410u);
	// 0x2955A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2955B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2955B8: movss [0x0056E464], xmm0
	X86_MEM_WRITE_u32(base, 0x56E464u, ctx.xmm[0].u32[0]);
	// 0x2955C0: ret
	return;
}

void sub_2955D0(X86Context& ctx, uint8_t* base) {
	// 0x2955D0: movss xmm0, dword ptr [0x0056E468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E468u);
	// 0x2955D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2955E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2955E8: movss [0x0056E404], xmm0
	X86_MEM_WRITE_u32(base, 0x56E404u, ctx.xmm[0].u32[0]);
	// 0x2955F0: ret
	return;
}

void sub_295600(X86Context& ctx, uint8_t* base) {
	// 0x295600: movss xmm0, dword ptr [0x0056E410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E410u);
	// 0x295608: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295610: movss [0x0056E408], xmm0
	X86_MEM_WRITE_u32(base, 0x56E408u, ctx.xmm[0].u32[0]);
	// 0x295618: ret
	return;
}

void sub_295620(X86Context& ctx, uint8_t* base) {
	// 0x295620: movss xmm0, dword ptr [0x0056E468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E468u);
	// 0x295628: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295630: movss [0x0056E470], xmm0
	X86_MEM_WRITE_u32(base, 0x56E470u, ctx.xmm[0].u32[0]);
	// 0x295638: ret
	return;
}

void sub_295640(X86Context& ctx, uint8_t* base) {
	// 0x295640: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x295648: movss [0x0056E3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E3F0u, ctx.xmm[0].u32[0]);
	// 0x295650: ret
	return;
}

void sub_295660(X86Context& ctx, uint8_t* base) {
	// 0x295660: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x295668: movss [0x0056E41C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E41Cu, ctx.xmm[0].u32[0]);
	// 0x295670: ret
	return;
}

void sub_295680(X86Context& ctx, uint8_t* base) {
	// 0x295680: movss xmm0, dword ptr [0x0056E3F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E3F0u);
	// 0x295688: movss [0x0056E484], xmm0
	X86_MEM_WRITE_u32(base, 0x56E484u, ctx.xmm[0].u32[0]);
	// 0x295690: ret
	return;
}

void sub_2956A0(X86Context& ctx, uint8_t* base) {
	// 0x2956A0: movss xmm0, dword ptr [0x0056E468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E468u);
	// 0x2956A8: subss xmm0, [0x0056E3F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E3F0u);
	// 0x2956B0: movss [0x0056E448], xmm0
	X86_MEM_WRITE_u32(base, 0x56E448u, ctx.xmm[0].u32[0]);
	// 0x2956B8: ret
	return;
}

void sub_2956C0(X86Context& ctx, uint8_t* base) {
	// 0x2956C0: movss xmm0, dword ptr [0x0056E448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E448u);
	// 0x2956C8: subss xmm0, [0x0056E41C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E41Cu);
	// 0x2956D0: movss [0x0056E440], xmm0
	X86_MEM_WRITE_u32(base, 0x56E440u, ctx.xmm[0].u32[0]);
	// 0x2956D8: ret
	return;
}

void sub_2956E0(X86Context& ctx, uint8_t* base) {
	// 0x2956E0: movss xmm0, dword ptr [0x0056E470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E470u);
	// 0x2956E8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2956F0: movss [0x0056E42C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E42Cu, ctx.xmm[0].u32[0]);
	// 0x2956F8: ret
	return;
}

void sub_295700(X86Context& ctx, uint8_t* base) {
	// 0x295700: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x295708: movss [0x0056E418], xmm0
	X86_MEM_WRITE_u32(base, 0x56E418u, ctx.xmm[0].u32[0]);
	// 0x295710: ret
	return;
}

void sub_295720(X86Context& ctx, uint8_t* base) {
	// 0x295720: movss xmm0, dword ptr [0x0056E42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E42Cu);
	// 0x295728: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x295730: movss [0x0056E460], xmm0
	X86_MEM_WRITE_u32(base, 0x56E460u, ctx.xmm[0].u32[0]);
	// 0x295738: ret
	return;
}

void sub_295740(X86Context& ctx, uint8_t* base) {
	// 0x295740: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x295748: movss [0x0056E434], xmm0
	X86_MEM_WRITE_u32(base, 0x56E434u, ctx.xmm[0].u32[0]);
	// 0x295750: ret
	return;
}

void sub_295760(X86Context& ctx, uint8_t* base) {
	// 0x295760: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x295768: movss [0x0056E40C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E40Cu, ctx.xmm[0].u32[0]);
	// 0x295770: ret
	return;
}

void sub_295780(X86Context& ctx, uint8_t* base) {
	// 0x295780: movss xmm0, dword ptr [0x0056E410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E410u);
	// 0x295788: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x295790: movss [0x00404D30], xmm0
	X86_MEM_WRITE_u32(base, 0x404D30u, ctx.xmm[0].u32[0]);
	// 0x295798: ret
	return;
}

void sub_2957A0(X86Context& ctx, uint8_t* base) {
	// 0x2957A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2957A8: movss [0x0056E4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4F0u, ctx.xmm[0].u32[0]);
	// 0x2957B0: ret
	return;
}

void sub_2957C0(X86Context& ctx, uint8_t* base) {
	// 0x2957C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2957C8: movss [0x0056E50C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E50Cu, ctx.xmm[0].u32[0]);
	// 0x2957D0: ret
	return;
}

void sub_2957E0(X86Context& ctx, uint8_t* base) {
	// 0x2957E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2957E8: movss [0x0056E4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4E0u, ctx.xmm[0].u32[0]);
	// 0x2957F0: ret
	return;
}

void sub_295800(X86Context& ctx, uint8_t* base) {
	// 0x295800: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x295808: movss [0x0056E490], xmm0
	X86_MEM_WRITE_u32(base, 0x56E490u, ctx.xmm[0].u32[0]);
	// 0x295810: ret
	return;
}

void sub_295820(X86Context& ctx, uint8_t* base) {
	// 0x295820: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x295828: movss [0x0056E4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4F4u, ctx.xmm[0].u32[0]);
	// 0x295830: ret
	return;
}

void sub_295840(X86Context& ctx, uint8_t* base) {
	// 0x295840: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x295848: movss [0x0056E4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4ACu, ctx.xmm[0].u32[0]);
	// 0x295850: ret
	return;
}

void sub_295860(X86Context& ctx, uint8_t* base) {
	// 0x295860: movss xmm0, dword ptr [0x0056E4F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4F4u);
	// 0x295868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x295870: movss [0x0056E52C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E52Cu, ctx.xmm[0].u32[0]);
	// 0x295878: ret
	return;
}

void sub_295880(X86Context& ctx, uint8_t* base) {
	// 0x295880: movss xmm0, dword ptr [0x0056E4AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4ACu);
	// 0x295888: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x295890: movss [0x0056E514], xmm0
	X86_MEM_WRITE_u32(base, 0x56E514u, ctx.xmm[0].u32[0]);
	// 0x295898: ret
	return;
}

void sub_2958A0(X86Context& ctx, uint8_t* base) {
	// 0x2958A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2958A8: movss [0x0056E544], xmm0
	X86_MEM_WRITE_u32(base, 0x56E544u, ctx.xmm[0].u32[0]);
	// 0x2958B0: ret
	return;
}

void sub_2958C0(X86Context& ctx, uint8_t* base) {
	// 0x2958C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2958C8: movss [0x0056E530], xmm0
	X86_MEM_WRITE_u32(base, 0x56E530u, ctx.xmm[0].u32[0]);
	// 0x2958D0: ret
	return;
}

void sub_2958E0(X86Context& ctx, uint8_t* base) {
	// 0x2958E0: movss xmm0, dword ptr [0x0056E530]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E530u);
	// 0x2958E8: movss [0x0056E540], xmm0
	X86_MEM_WRITE_u32(base, 0x56E540u, ctx.xmm[0].u32[0]);
	// 0x2958F0: ret
	return;
}

void sub_295900(X86Context& ctx, uint8_t* base) {
	// 0x295900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x295908: movss [0x0056E498], xmm0
	X86_MEM_WRITE_u32(base, 0x56E498u, ctx.xmm[0].u32[0]);
	// 0x295910: ret
	return;
}

void sub_295920(X86Context& ctx, uint8_t* base) {
	// 0x295920: movss xmm0, dword ptr [0x0056E4AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4ACu);
	// 0x295928: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x295930: movss [0x0056E538], xmm0
	X86_MEM_WRITE_u32(base, 0x56E538u, ctx.xmm[0].u32[0]);
	// 0x295938: ret
	return;
}

void sub_295940(X86Context& ctx, uint8_t* base) {
	// 0x295940: movss xmm0, dword ptr [0x0056E4AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4ACu);
	// 0x295948: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x295950: movss [0x0056E4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4DCu, ctx.xmm[0].u32[0]);
	// 0x295958: ret
	return;
}

void sub_295960(X86Context& ctx, uint8_t* base) {
	// 0x295960: movss xmm0, dword ptr [0x0056E4AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4ACu);
	// 0x295968: subss xmm0, [0x0056E4DC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E4DCu);
	// 0x295970: movss [0x0056E4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4B4u, ctx.xmm[0].u32[0]);
	// 0x295978: ret
	return;
}

void sub_295980(X86Context& ctx, uint8_t* base) {
	// 0x295980: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x295988: movss [0x0056E508], xmm0
	X86_MEM_WRITE_u32(base, 0x56E508u, ctx.xmm[0].u32[0]);
	// 0x295990: ret
	return;
}

void sub_2959A0(X86Context& ctx, uint8_t* base) {
	// 0x2959A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2959A8: movss [0x0056E4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4B0u, ctx.xmm[0].u32[0]);
	// 0x2959B0: ret
	return;
}

void sub_2959C0(X86Context& ctx, uint8_t* base) {
	// 0x2959C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2959C8: movss [0x0056E4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4C8u, ctx.xmm[0].u32[0]);
	// 0x2959D0: ret
	return;
}

void sub_2959E0(X86Context& ctx, uint8_t* base) {
	// 0x2959E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2959E8: movss [0x0056E520], xmm0
	X86_MEM_WRITE_u32(base, 0x56E520u, ctx.xmm[0].u32[0]);
	// 0x2959F0: ret
	return;
}

void sub_295A00(X86Context& ctx, uint8_t* base) {
	// 0x295A00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x295A08: movss [0x0056E504], xmm0
	X86_MEM_WRITE_u32(base, 0x56E504u, ctx.xmm[0].u32[0]);
	// 0x295A10: ret
	return;
}

void sub_295A20(X86Context& ctx, uint8_t* base) {
	// 0x295A20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x295A28: movss [0x0056E4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4A8u, ctx.xmm[0].u32[0]);
	// 0x295A30: ret
	return;
}

void sub_295A40(X86Context& ctx, uint8_t* base) {
	// 0x295A40: movss xmm0, dword ptr [0x0056E4C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4C8u);
	// 0x295A48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x295A50: movss [0x0056E49C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E49Cu, ctx.xmm[0].u32[0]);
	// 0x295A58: ret
	return;
}

void sub_295A60(X86Context& ctx, uint8_t* base) {
	// 0x295A60: movss xmm0, dword ptr [0x0056E520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E520u);
	// 0x295A68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x295A70: movss [0x0056E4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4E8u, ctx.xmm[0].u32[0]);
	// 0x295A78: ret
	return;
}

void sub_295A80(X86Context& ctx, uint8_t* base) {
	// 0x295A80: movss xmm0, dword ptr [0x0056E49C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E49Cu);
	// 0x295A88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x295A90: movss [0x0056E4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4FCu, ctx.xmm[0].u32[0]);
	// 0x295A98: ret
	return;
}

void sub_295AA0(X86Context& ctx, uint8_t* base) {
	// 0x295AA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x295AA8: movss [0x0056E494], xmm0
	X86_MEM_WRITE_u32(base, 0x56E494u, ctx.xmm[0].u32[0]);
	// 0x295AB0: ret
	return;
}

void sub_295AC0(X86Context& ctx, uint8_t* base) {
	// 0x295AC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x295AC8: movss [0x0056E4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4CCu, ctx.xmm[0].u32[0]);
	// 0x295AD0: ret
	return;
}

void sub_295AE0(X86Context& ctx, uint8_t* base) {
	// 0x295AE0: movss xmm0, dword ptr [0x0056E4C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4C8u);
	// 0x295AE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x295AF0: movss [0x0056E4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4D8u, ctx.xmm[0].u32[0]);
	// 0x295AF8: ret
	return;
}

void sub_295B00(X86Context& ctx, uint8_t* base) {
	// 0x295B00: movss xmm0, dword ptr [0x0056E520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E520u);
	// 0x295B08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x295B10: movss [0x0056E524], xmm0
	X86_MEM_WRITE_u32(base, 0x56E524u, ctx.xmm[0].u32[0]);
	// 0x295B18: ret
	return;
}

void sub_295B20(X86Context& ctx, uint8_t* base) {
	// 0x295B20: movss xmm0, dword ptr [0x0056E4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4D8u);
	// 0x295B28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295B30: movss [0x0056E510], xmm0
	X86_MEM_WRITE_u32(base, 0x56E510u, ctx.xmm[0].u32[0]);
	// 0x295B38: ret
	return;
}

void sub_295B40(X86Context& ctx, uint8_t* base) {
	// 0x295B40: movss xmm0, dword ptr [0x0056E524]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E524u);
	// 0x295B48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295B50: movss [0x0056E534], xmm0
	X86_MEM_WRITE_u32(base, 0x56E534u, ctx.xmm[0].u32[0]);
	// 0x295B58: ret
	return;
}

void sub_295B60(X86Context& ctx, uint8_t* base) {
	// 0x295B60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x295B68: movss [0x0056E4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4A0u, ctx.xmm[0].u32[0]);
	// 0x295B70: ret
	return;
}

void sub_295B80(X86Context& ctx, uint8_t* base) {
	// 0x295B80: movss xmm0, dword ptr [0x0056E4C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4C8u);
	// 0x295B88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295B90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x295B98: movss [0x0056E51C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E51Cu, ctx.xmm[0].u32[0]);
	// 0x295BA0: ret
	return;
}

void sub_295BB0(X86Context& ctx, uint8_t* base) {
	// 0x295BB0: movss xmm0, dword ptr [0x0056E520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E520u);
	// 0x295BB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295BC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x295BC8: movss [0x0056E4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4B8u, ctx.xmm[0].u32[0]);
	// 0x295BD0: ret
	return;
}

void sub_295BE0(X86Context& ctx, uint8_t* base) {
	// 0x295BE0: movss xmm0, dword ptr [0x0056E4C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4C8u);
	// 0x295BE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295BF0: movss [0x0056E4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4BCu, ctx.xmm[0].u32[0]);
	// 0x295BF8: ret
	return;
}

void sub_295C00(X86Context& ctx, uint8_t* base) {
	// 0x295C00: movss xmm0, dword ptr [0x0056E520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E520u);
	// 0x295C08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x295C10: movss [0x0056E528], xmm0
	X86_MEM_WRITE_u32(base, 0x56E528u, ctx.xmm[0].u32[0]);
	// 0x295C18: ret
	return;
}

void sub_295C20(X86Context& ctx, uint8_t* base) {
	// 0x295C20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x295C28: movss [0x0056E4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4A4u, ctx.xmm[0].u32[0]);
	// 0x295C30: ret
	return;
}

void sub_295C40(X86Context& ctx, uint8_t* base) {
	// 0x295C40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x295C48: movss [0x0056E4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4D4u, ctx.xmm[0].u32[0]);
	// 0x295C50: ret
	return;
}

void sub_295C60(X86Context& ctx, uint8_t* base) {
	// 0x295C60: movss xmm0, dword ptr [0x0056E4A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4A4u);
	// 0x295C68: movss [0x0056E53C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E53Cu, ctx.xmm[0].u32[0]);
	// 0x295C70: ret
	return;
}

void sub_295C80(X86Context& ctx, uint8_t* base) {
	// 0x295C80: movss xmm0, dword ptr [0x0056E520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E520u);
	// 0x295C88: subss xmm0, [0x0056E4A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E4A4u);
	// 0x295C90: movss [0x0056E500], xmm0
	X86_MEM_WRITE_u32(base, 0x56E500u, ctx.xmm[0].u32[0]);
	// 0x295C98: ret
	return;
}

void sub_295CA0(X86Context& ctx, uint8_t* base) {
	// 0x295CA0: movss xmm0, dword ptr [0x0056E500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E500u);
	// 0x295CA8: subss xmm0, [0x0056E4D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E4D4u);
	// 0x295CB0: movss [0x0056E4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4F8u, ctx.xmm[0].u32[0]);
	// 0x295CB8: ret
	return;
}

void sub_295CC0(X86Context& ctx, uint8_t* base) {
	// 0x295CC0: movss xmm0, dword ptr [0x0056E528]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E528u);
	// 0x295CC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x295CD0: movss [0x0056E4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4E4u, ctx.xmm[0].u32[0]);
	// 0x295CD8: ret
	return;
}

void sub_295CE0(X86Context& ctx, uint8_t* base) {
	// 0x295CE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x295CE8: movss [0x0056E4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4D0u, ctx.xmm[0].u32[0]);
	// 0x295CF0: ret
	return;
}

void sub_295D00(X86Context& ctx, uint8_t* base) {
	// 0x295D00: movss xmm0, dword ptr [0x0056E4E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E4E4u);
	// 0x295D08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x295D10: movss [0x0056E518], xmm0
	X86_MEM_WRITE_u32(base, 0x56E518u, ctx.xmm[0].u32[0]);
	// 0x295D18: ret
	return;
}

void sub_295D20(X86Context& ctx, uint8_t* base) {
	// 0x295D20: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x295D28: movss [0x0056E4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4ECu, ctx.xmm[0].u32[0]);
	// 0x295D30: ret
	return;
}

void sub_295D40(X86Context& ctx, uint8_t* base) {
	// 0x295D40: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x295D48: movss [0x0056E4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4C4u, ctx.xmm[0].u32[0]);
	// 0x295D50: ret
	return;
}

void sub_295D60(X86Context& ctx, uint8_t* base) {
	// 0x295D60: movss xmm0, dword ptr [0x003B2070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2070u);
	// 0x295D68: movss [0x0056E4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E4C0u, ctx.xmm[0].u32[0]);
	// 0x295D70: ret
	return;
}

void sub_295D80(X86Context& ctx, uint8_t* base) {
	// 0x295D80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x295D88: movss [0x0056E5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5A0u, ctx.xmm[0].u32[0]);
	// 0x295D90: ret
	return;
}

void sub_295DA0(X86Context& ctx, uint8_t* base) {
	// 0x295DA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x295DA8: movss [0x0056E5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5BCu, ctx.xmm[0].u32[0]);
	// 0x295DB0: ret
	return;
}

void sub_295DC0(X86Context& ctx, uint8_t* base) {
	// 0x295DC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x295DC8: movss [0x0056E594], xmm0
	X86_MEM_WRITE_u32(base, 0x56E594u, ctx.xmm[0].u32[0]);
	// 0x295DD0: ret
	return;
}

void sub_295DE0(X86Context& ctx, uint8_t* base) {
	// 0x295DE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x295DE8: movss [0x0056E548], xmm0
	X86_MEM_WRITE_u32(base, 0x56E548u, ctx.xmm[0].u32[0]);
	// 0x295DF0: ret
	return;
}

void sub_295E00(X86Context& ctx, uint8_t* base) {
	// 0x295E00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x295E08: movss [0x0056E5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5A4u, ctx.xmm[0].u32[0]);
	// 0x295E10: ret
	return;
}

void sub_295E20(X86Context& ctx, uint8_t* base) {
	// 0x295E20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x295E28: movss [0x0056E564], xmm0
	X86_MEM_WRITE_u32(base, 0x56E564u, ctx.xmm[0].u32[0]);
	// 0x295E30: ret
	return;
}

void sub_295E40(X86Context& ctx, uint8_t* base) {
	// 0x295E40: movss xmm0, dword ptr [0x0056E5A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5A4u);
	// 0x295E48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x295E50: movss [0x0056E5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5DCu, ctx.xmm[0].u32[0]);
	// 0x295E58: ret
	return;
}

void sub_295E60(X86Context& ctx, uint8_t* base) {
	// 0x295E60: movss xmm0, dword ptr [0x0056E564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E564u);
	// 0x295E68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x295E70: movss [0x0056E5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5C4u, ctx.xmm[0].u32[0]);
	// 0x295E78: ret
	return;
}

void sub_295E80(X86Context& ctx, uint8_t* base) {
	// 0x295E80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x295E88: movss [0x0056E5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5F8u, ctx.xmm[0].u32[0]);
	// 0x295E90: ret
	return;
}

void sub_295EA0(X86Context& ctx, uint8_t* base) {
	// 0x295EA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x295EA8: movss [0x0056E5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5E0u, ctx.xmm[0].u32[0]);
	// 0x295EB0: ret
	return;
}

