#include "x86_recomp_shared.h"

void sub_268950(X86Context& ctx, uint8_t* base) {
	// 0x268950: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x268958: movss [0x0054FE20], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE20u, ctx.xmm[0].u32[0]);
	// 0x268960: movss xmm0, dword ptr [0x003895BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x268968: movss [0x0054FE24], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE24u, ctx.xmm[0].u32[0]);
	// 0x268970: movss xmm0, dword ptr [0x003B1870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x268978: movss [0x0054FE28], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE28u, ctx.xmm[0].u32[0]);
	// 0x268980: ret
	return;
}

void sub_268990(X86Context& ctx, uint8_t* base) {
	// 0x268990: movss xmm0, dword ptr [0x003B2224]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2224u);
	// 0x268998: movss [0x0054FE10], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE10u, ctx.xmm[0].u32[0]);
	// 0x2689A0: ret
	return;
}

void sub_2689B0(X86Context& ctx, uint8_t* base) {
	// 0x2689B0: movss xmm0, dword ptr [0x003B1688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2689B8: subss xmm0, [0x0054FE10]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FE10u);
	// 0x2689C0: movss [0x0054FE0C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE0Cu, ctx.xmm[0].u32[0]);
	// 0x2689C8: ret
	return;
}

void sub_2689D0(X86Context& ctx, uint8_t* base) {
	// 0x2689D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2689D8: movss [0x0054FE88], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE88u, ctx.xmm[0].u32[0]);
	// 0x2689E0: ret
	return;
}

void sub_2689F0(X86Context& ctx, uint8_t* base) {
	// 0x2689F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2689F8: movss [0x0054FEA4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEA4u, ctx.xmm[0].u32[0]);
	// 0x268A00: ret
	return;
}

void sub_268A10(X86Context& ctx, uint8_t* base) {
	// 0x268A10: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x268A18: movss [0x0054FE78], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE78u, ctx.xmm[0].u32[0]);
	// 0x268A20: ret
	return;
}

void sub_268A30(X86Context& ctx, uint8_t* base) {
	// 0x268A30: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x268A38: movss [0x0054FE2C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE2Cu, ctx.xmm[0].u32[0]);
	// 0x268A40: ret
	return;
}

void sub_268A50(X86Context& ctx, uint8_t* base) {
	// 0x268A50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x268A58: movss [0x0054FE8C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE8Cu, ctx.xmm[0].u32[0]);
	// 0x268A60: ret
	return;
}

void sub_268A70(X86Context& ctx, uint8_t* base) {
	// 0x268A70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x268A78: movss [0x0054FE48], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE48u, ctx.xmm[0].u32[0]);
	// 0x268A80: ret
	return;
}

void sub_268A90(X86Context& ctx, uint8_t* base) {
	// 0x268A90: movss xmm0, dword ptr [0x0054FE8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE8Cu);
	// 0x268A98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x268AA0: movss [0x0054FEC4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEC4u, ctx.xmm[0].u32[0]);
	// 0x268AA8: ret
	return;
}

void sub_268AB0(X86Context& ctx, uint8_t* base) {
	// 0x268AB0: movss xmm0, dword ptr [0x0054FE48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE48u);
	// 0x268AB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x268AC0: movss [0x0054FEAC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEACu, ctx.xmm[0].u32[0]);
	// 0x268AC8: ret
	return;
}

void sub_268AD0(X86Context& ctx, uint8_t* base) {
	// 0x268AD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268AD8: movss [0x0054FEDC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEDCu, ctx.xmm[0].u32[0]);
	// 0x268AE0: ret
	return;
}

void sub_268AF0(X86Context& ctx, uint8_t* base) {
	// 0x268AF0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x268AF8: movss [0x0054FEC8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEC8u, ctx.xmm[0].u32[0]);
	// 0x268B00: ret
	return;
}

void sub_268B10(X86Context& ctx, uint8_t* base) {
	// 0x268B10: movss xmm0, dword ptr [0x0054FEC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEC8u);
	// 0x268B18: movss [0x0054FED8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FED8u, ctx.xmm[0].u32[0]);
	// 0x268B20: ret
	return;
}

void sub_268B30(X86Context& ctx, uint8_t* base) {
	// 0x268B30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x268B38: movss [0x0054FE34], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE34u, ctx.xmm[0].u32[0]);
	// 0x268B40: ret
	return;
}

void sub_268B50(X86Context& ctx, uint8_t* base) {
	// 0x268B50: movss xmm0, dword ptr [0x0054FE48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE48u);
	// 0x268B58: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x268B60: movss [0x0054FED0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FED0u, ctx.xmm[0].u32[0]);
	// 0x268B68: ret
	return;
}

void sub_268B70(X86Context& ctx, uint8_t* base) {
	// 0x268B70: movss xmm0, dword ptr [0x0054FE48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE48u);
	// 0x268B78: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x268B80: movss [0x0054FE74], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE74u, ctx.xmm[0].u32[0]);
	// 0x268B88: ret
	return;
}

void sub_268B90(X86Context& ctx, uint8_t* base) {
	// 0x268B90: movss xmm0, dword ptr [0x0054FE48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE48u);
	// 0x268B98: subss xmm0, [0x0054FE74]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FE74u);
	// 0x268BA0: movss [0x0054FE50], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE50u, ctx.xmm[0].u32[0]);
	// 0x268BA8: ret
	return;
}

void sub_268BB0(X86Context& ctx, uint8_t* base) {
	// 0x268BB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x268BB8: movss [0x0054FEA0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEA0u, ctx.xmm[0].u32[0]);
	// 0x268BC0: ret
	return;
}

void sub_268BD0(X86Context& ctx, uint8_t* base) {
	// 0x268BD0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x268BD8: movss [0x0054FE4C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE4Cu, ctx.xmm[0].u32[0]);
	// 0x268BE0: ret
	return;
}

void sub_268BF0(X86Context& ctx, uint8_t* base) {
	// 0x268BF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x268BF8: movss [0x0054FE60], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE60u, ctx.xmm[0].u32[0]);
	// 0x268C00: ret
	return;
}

void sub_268C10(X86Context& ctx, uint8_t* base) {
	// 0x268C10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x268C18: movss [0x0054FEB8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEB8u, ctx.xmm[0].u32[0]);
	// 0x268C20: ret
	return;
}

void sub_268C30(X86Context& ctx, uint8_t* base) {
	// 0x268C30: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x268C38: movss [0x0054FE9C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE9Cu, ctx.xmm[0].u32[0]);
	// 0x268C40: ret
	return;
}

void sub_268C50(X86Context& ctx, uint8_t* base) {
	// 0x268C50: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x268C58: movss [0x0054FE44], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE44u, ctx.xmm[0].u32[0]);
	// 0x268C60: ret
	return;
}

void sub_268C70(X86Context& ctx, uint8_t* base) {
	// 0x268C70: movss xmm0, dword ptr [0x0054FE60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE60u);
	// 0x268C78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x268C80: movss [0x0054FE38], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE38u, ctx.xmm[0].u32[0]);
	// 0x268C88: ret
	return;
}

void sub_268C90(X86Context& ctx, uint8_t* base) {
	// 0x268C90: movss xmm0, dword ptr [0x0054FEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEB8u);
	// 0x268C98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x268CA0: movss [0x0054FE80], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE80u, ctx.xmm[0].u32[0]);
	// 0x268CA8: ret
	return;
}

void sub_268CB0(X86Context& ctx, uint8_t* base) {
	// 0x268CB0: movss xmm0, dword ptr [0x0054FE38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE38u);
	// 0x268CB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x268CC0: movss [0x0054FE94], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE94u, ctx.xmm[0].u32[0]);
	// 0x268CC8: ret
	return;
}

void sub_268CD0(X86Context& ctx, uint8_t* base) {
	// 0x268CD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x268CD8: movss [0x0054FE30], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE30u, ctx.xmm[0].u32[0]);
	// 0x268CE0: ret
	return;
}

void sub_268CF0(X86Context& ctx, uint8_t* base) {
	// 0x268CF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x268CF8: movss [0x0054FE64], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE64u, ctx.xmm[0].u32[0]);
	// 0x268D00: ret
	return;
}

void sub_268D10(X86Context& ctx, uint8_t* base) {
	// 0x268D10: movss xmm0, dword ptr [0x0054FE60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE60u);
	// 0x268D18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x268D20: movss [0x0054FE70], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE70u, ctx.xmm[0].u32[0]);
	// 0x268D28: ret
	return;
}

void sub_268D30(X86Context& ctx, uint8_t* base) {
	// 0x268D30: movss xmm0, dword ptr [0x0054FEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEB8u);
	// 0x268D38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x268D40: movss [0x0054FEBC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEBCu, ctx.xmm[0].u32[0]);
	// 0x268D48: ret
	return;
}

void sub_268D50(X86Context& ctx, uint8_t* base) {
	// 0x268D50: movss xmm0, dword ptr [0x0054FE70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE70u);
	// 0x268D58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x268D60: movss [0x0054FEA8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEA8u, ctx.xmm[0].u32[0]);
	// 0x268D68: ret
	return;
}

void sub_268D70(X86Context& ctx, uint8_t* base) {
	// 0x268D70: movss xmm0, dword ptr [0x0054FEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEBCu);
	// 0x268D78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x268D80: movss [0x0054FECC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FECCu, ctx.xmm[0].u32[0]);
	// 0x268D88: ret
	return;
}

void sub_268D90(X86Context& ctx, uint8_t* base) {
	// 0x268D90: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x268D98: movss [0x0054FE3C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE3Cu, ctx.xmm[0].u32[0]);
	// 0x268DA0: ret
	return;
}

void sub_268DB0(X86Context& ctx, uint8_t* base) {
	// 0x268DB0: movss xmm0, dword ptr [0x0054FE60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE60u);
	// 0x268DB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x268DC0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x268DC8: movss [0x0054FEB4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEB4u, ctx.xmm[0].u32[0]);
	// 0x268DD0: ret
	return;
}

void sub_268DE0(X86Context& ctx, uint8_t* base) {
	// 0x268DE0: movss xmm0, dword ptr [0x0054FEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEB8u);
	// 0x268DE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x268DF0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x268DF8: movss [0x0054FE54], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE54u, ctx.xmm[0].u32[0]);
	// 0x268E00: ret
	return;
}

void sub_268E10(X86Context& ctx, uint8_t* base) {
	// 0x268E10: movss xmm0, dword ptr [0x0054FE60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE60u);
	// 0x268E18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x268E20: movss [0x0054FE58], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE58u, ctx.xmm[0].u32[0]);
	// 0x268E28: ret
	return;
}

void sub_268E30(X86Context& ctx, uint8_t* base) {
	// 0x268E30: movss xmm0, dword ptr [0x0054FEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEB8u);
	// 0x268E38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x268E40: movss [0x0054FEC0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEC0u, ctx.xmm[0].u32[0]);
	// 0x268E48: ret
	return;
}

void sub_268E50(X86Context& ctx, uint8_t* base) {
	// 0x268E50: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x268E58: movss [0x0054FE40], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE40u, ctx.xmm[0].u32[0]);
	// 0x268E60: ret
	return;
}

void sub_268E70(X86Context& ctx, uint8_t* base) {
	// 0x268E70: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x268E78: movss [0x0054FE6C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE6Cu, ctx.xmm[0].u32[0]);
	// 0x268E80: ret
	return;
}

void sub_268E90(X86Context& ctx, uint8_t* base) {
	// 0x268E90: movss xmm0, dword ptr [0x0054FE40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE40u);
	// 0x268E98: movss [0x0054FED4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FED4u, ctx.xmm[0].u32[0]);
	// 0x268EA0: ret
	return;
}

void sub_268EB0(X86Context& ctx, uint8_t* base) {
	// 0x268EB0: movss xmm0, dword ptr [0x0054FEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEB8u);
	// 0x268EB8: subss xmm0, [0x0054FE40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FE40u);
	// 0x268EC0: movss [0x0054FE98], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE98u, ctx.xmm[0].u32[0]);
	// 0x268EC8: ret
	return;
}

void sub_268ED0(X86Context& ctx, uint8_t* base) {
	// 0x268ED0: movss xmm0, dword ptr [0x0054FE98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE98u);
	// 0x268ED8: subss xmm0, [0x0054FE6C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FE6Cu);
	// 0x268EE0: movss [0x0054FE90], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE90u, ctx.xmm[0].u32[0]);
	// 0x268EE8: ret
	return;
}

void sub_268EF0(X86Context& ctx, uint8_t* base) {
	// 0x268EF0: movss xmm0, dword ptr [0x0054FEC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEC0u);
	// 0x268EF8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x268F00: movss [0x0054FE7C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE7Cu, ctx.xmm[0].u32[0]);
	// 0x268F08: ret
	return;
}

void sub_268F10(X86Context& ctx, uint8_t* base) {
	// 0x268F10: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x268F18: movss [0x0054FE68], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE68u, ctx.xmm[0].u32[0]);
	// 0x268F20: ret
	return;
}

void sub_268F30(X86Context& ctx, uint8_t* base) {
	// 0x268F30: movss xmm0, dword ptr [0x0054FE7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FE7Cu);
	// 0x268F38: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x268F40: movss [0x0054FEB0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEB0u, ctx.xmm[0].u32[0]);
	// 0x268F48: ret
	return;
}

void sub_268F50(X86Context& ctx, uint8_t* base) {
	// 0x268F50: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x268F58: movss [0x0054FE84], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE84u, ctx.xmm[0].u32[0]);
	// 0x268F60: ret
	return;
}

void sub_268F70(X86Context& ctx, uint8_t* base) {
	// 0x268F70: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x268F78: movss [0x0054FE5C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FE5Cu, ctx.xmm[0].u32[0]);
	// 0x268F80: ret
	return;
}

void sub_268F90(X86Context& ctx, uint8_t* base) {
	// 0x268F90: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x268F98: movss [0x00557594], xmm0
	X86_MEM_WRITE_u32(base, 0x557594u, ctx.xmm[0].u32[0]);
	// 0x268FA0: ret
	return;
}

void sub_268FB0(X86Context& ctx, uint8_t* base) {
	// 0x268FB0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x268FB8: movss [0x005575B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5575B0u, ctx.xmm[0].u32[0]);
	// 0x268FC0: ret
	return;
}

void sub_268FD0(X86Context& ctx, uint8_t* base) {
	// 0x268FD0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x268FD8: movss [0x0054FF28], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF28u, ctx.xmm[0].u32[0]);
	// 0x268FE0: ret
	return;
}

void sub_268FF0(X86Context& ctx, uint8_t* base) {
	// 0x268FF0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x268FF8: movss [0x0054FEE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEE0u, ctx.xmm[0].u32[0]);
	// 0x269000: ret
	return;
}

void sub_269010(X86Context& ctx, uint8_t* base) {
	// 0x269010: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x269018: movss [0x00557598], xmm0
	X86_MEM_WRITE_u32(base, 0x557598u, ctx.xmm[0].u32[0]);
	// 0x269020: ret
	return;
}

void sub_269030(X86Context& ctx, uint8_t* base) {
	// 0x269030: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x269038: movss [0x0054FEFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEFCu, ctx.xmm[0].u32[0]);
	// 0x269040: ret
	return;
}

void sub_269050(X86Context& ctx, uint8_t* base) {
	// 0x269050: movss xmm0, dword ptr [0x00557598]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557598u);
	// 0x269058: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x269060: movss [0x005575D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5575D0u, ctx.xmm[0].u32[0]);
	// 0x269068: ret
	return;
}

void sub_269070(X86Context& ctx, uint8_t* base) {
	// 0x269070: movss xmm0, dword ptr [0x0054FEFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEFCu);
	// 0x269078: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x269080: movss [0x005575B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5575B8u, ctx.xmm[0].u32[0]);
	// 0x269088: ret
	return;
}

void sub_269090(X86Context& ctx, uint8_t* base) {
	// 0x269090: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x269098: movss [0x005575E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5575E8u, ctx.xmm[0].u32[0]);
	// 0x2690A0: ret
	return;
}

void sub_2690B0(X86Context& ctx, uint8_t* base) {
	// 0x2690B0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2690B8: movss [0x005575D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5575D4u, ctx.xmm[0].u32[0]);
	// 0x2690C0: ret
	return;
}

void sub_2690D0(X86Context& ctx, uint8_t* base) {
	// 0x2690D0: movss xmm0, dword ptr [0x005575D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575D4u);
	// 0x2690D8: movss [0x005575E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5575E4u, ctx.xmm[0].u32[0]);
	// 0x2690E0: ret
	return;
}

void sub_2690F0(X86Context& ctx, uint8_t* base) {
	// 0x2690F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2690F8: movss [0x0054FEE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEE8u, ctx.xmm[0].u32[0]);
	// 0x269100: ret
	return;
}

void sub_269110(X86Context& ctx, uint8_t* base) {
	// 0x269110: movss xmm0, dword ptr [0x0054FEFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEFCu);
	// 0x269118: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x269120: movss [0x005575DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5575DCu, ctx.xmm[0].u32[0]);
	// 0x269128: ret
	return;
}

void sub_269130(X86Context& ctx, uint8_t* base) {
	// 0x269130: movss xmm0, dword ptr [0x0054FEFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEFCu);
	// 0x269138: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x269140: movss [0x0054FF24], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF24u, ctx.xmm[0].u32[0]);
	// 0x269148: ret
	return;
}

void sub_269150(X86Context& ctx, uint8_t* base) {
	// 0x269150: movss xmm0, dword ptr [0x0054FEFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEFCu);
	// 0x269158: subss xmm0, [0x0054FF24]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FF24u);
	// 0x269160: movss [0x0054FF04], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF04u, ctx.xmm[0].u32[0]);
	// 0x269168: ret
	return;
}

void sub_269170(X86Context& ctx, uint8_t* base) {
	// 0x269170: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x269178: movss [0x005575AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5575ACu, ctx.xmm[0].u32[0]);
	// 0x269180: ret
	return;
}

void sub_269190(X86Context& ctx, uint8_t* base) {
	// 0x269190: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x269198: movss [0x0054FF00], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF00u, ctx.xmm[0].u32[0]);
	// 0x2691A0: ret
	return;
}

void sub_2691B0(X86Context& ctx, uint8_t* base) {
	// 0x2691B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2691B8: movss [0x0054FF10], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF10u, ctx.xmm[0].u32[0]);
	// 0x2691C0: ret
	return;
}

void sub_2691D0(X86Context& ctx, uint8_t* base) {
	// 0x2691D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2691D8: movss [0x005575C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5575C4u, ctx.xmm[0].u32[0]);
	// 0x2691E0: ret
	return;
}

void sub_2691F0(X86Context& ctx, uint8_t* base) {
	// 0x2691F0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2691F8: movss [0x005575A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5575A8u, ctx.xmm[0].u32[0]);
	// 0x269200: ret
	return;
}

void sub_269210(X86Context& ctx, uint8_t* base) {
	// 0x269210: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x269218: movss [0x0054FEF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEF8u, ctx.xmm[0].u32[0]);
	// 0x269220: ret
	return;
}

void sub_269230(X86Context& ctx, uint8_t* base) {
	// 0x269230: movss xmm0, dword ptr [0x0054FF10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FF10u);
	// 0x269238: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x269240: movss [0x0054FEEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEECu, ctx.xmm[0].u32[0]);
	// 0x269248: ret
	return;
}

void sub_269250(X86Context& ctx, uint8_t* base) {
	// 0x269250: movss xmm0, dword ptr [0x005575C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575C4u);
	// 0x269258: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x269260: movss [0x00557590], xmm0
	X86_MEM_WRITE_u32(base, 0x557590u, ctx.xmm[0].u32[0]);
	// 0x269268: ret
	return;
}

void sub_269270(X86Context& ctx, uint8_t* base) {
	// 0x269270: movss xmm0, dword ptr [0x0054FEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEECu);
	// 0x269278: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x269280: movss [0x005575A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5575A0u, ctx.xmm[0].u32[0]);
	// 0x269288: ret
	return;
}

void sub_269290(X86Context& ctx, uint8_t* base) {
	// 0x269290: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x269298: movss [0x0054FEE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEE4u, ctx.xmm[0].u32[0]);
	// 0x2692A0: ret
	return;
}

void sub_2692B0(X86Context& ctx, uint8_t* base) {
	// 0x2692B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2692B8: movss [0x0054FF14], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF14u, ctx.xmm[0].u32[0]);
	// 0x2692C0: ret
	return;
}

void sub_2692D0(X86Context& ctx, uint8_t* base) {
	// 0x2692D0: movss xmm0, dword ptr [0x0054FF10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FF10u);
	// 0x2692D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2692E0: movss [0x0054FF20], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF20u, ctx.xmm[0].u32[0]);
	// 0x2692E8: ret
	return;
}

void sub_2692F0(X86Context& ctx, uint8_t* base) {
	// 0x2692F0: movss xmm0, dword ptr [0x005575C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575C4u);
	// 0x2692F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x269300: movss [0x005575C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5575C8u, ctx.xmm[0].u32[0]);
	// 0x269308: ret
	return;
}

void sub_269310(X86Context& ctx, uint8_t* base) {
	// 0x269310: movss xmm0, dword ptr [0x0054FF20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FF20u);
	// 0x269318: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269320: movss [0x005575B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5575B4u, ctx.xmm[0].u32[0]);
	// 0x269328: ret
	return;
}

void sub_269330(X86Context& ctx, uint8_t* base) {
	// 0x269330: movss xmm0, dword ptr [0x005575C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575C8u);
	// 0x269338: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269340: movss [0x005575D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5575D8u, ctx.xmm[0].u32[0]);
	// 0x269348: ret
	return;
}

void sub_269350(X86Context& ctx, uint8_t* base) {
	// 0x269350: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x269358: movss [0x0054FEF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEF0u, ctx.xmm[0].u32[0]);
	// 0x269360: ret
	return;
}

void sub_269370(X86Context& ctx, uint8_t* base) {
	// 0x269370: movss xmm0, dword ptr [0x0054FF10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FF10u);
	// 0x269378: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269380: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x269388: movss [0x005575C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5575C0u, ctx.xmm[0].u32[0]);
	// 0x269390: ret
	return;
}

void sub_2693A0(X86Context& ctx, uint8_t* base) {
	// 0x2693A0: movss xmm0, dword ptr [0x005575C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575C4u);
	// 0x2693A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2693B0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2693B8: movss [0x0054FF08], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF08u, ctx.xmm[0].u32[0]);
	// 0x2693C0: ret
	return;
}

void sub_2693D0(X86Context& ctx, uint8_t* base) {
	// 0x2693D0: movss xmm0, dword ptr [0x0054FF10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FF10u);
	// 0x2693D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2693E0: movss [0x0054FF0C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF0Cu, ctx.xmm[0].u32[0]);
	// 0x2693E8: ret
	return;
}

void sub_2693F0(X86Context& ctx, uint8_t* base) {
	// 0x2693F0: movss xmm0, dword ptr [0x005575C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575C4u);
	// 0x2693F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269400: movss [0x005575CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5575CCu, ctx.xmm[0].u32[0]);
	// 0x269408: ret
	return;
}

void sub_269410(X86Context& ctx, uint8_t* base) {
	// 0x269410: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x269418: movss [0x0054FEF4], xmm0
	X86_MEM_WRITE_u32(base, 0x54FEF4u, ctx.xmm[0].u32[0]);
	// 0x269420: ret
	return;
}

void sub_269430(X86Context& ctx, uint8_t* base) {
	// 0x269430: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x269438: movss [0x0054FF1C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF1Cu, ctx.xmm[0].u32[0]);
	// 0x269440: ret
	return;
}

void sub_269450(X86Context& ctx, uint8_t* base) {
	// 0x269450: movss xmm0, dword ptr [0x0054FEF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FEF4u);
	// 0x269458: movss [0x005575E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5575E0u, ctx.xmm[0].u32[0]);
	// 0x269460: ret
	return;
}

void sub_269470(X86Context& ctx, uint8_t* base) {
	// 0x269470: movss xmm0, dword ptr [0x005575C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575C4u);
	// 0x269478: subss xmm0, [0x0054FEF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FEF4u);
	// 0x269480: movss [0x005575A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5575A4u, ctx.xmm[0].u32[0]);
	// 0x269488: ret
	return;
}

void sub_269490(X86Context& ctx, uint8_t* base) {
	// 0x269490: movss xmm0, dword ptr [0x005575A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575A4u);
	// 0x269498: subss xmm0, [0x0054FF1C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x54FF1Cu);
	// 0x2694A0: movss [0x0055759C], xmm0
	X86_MEM_WRITE_u32(base, 0x55759Cu, ctx.xmm[0].u32[0]);
	// 0x2694A8: ret
	return;
}

void sub_2694B0(X86Context& ctx, uint8_t* base) {
	// 0x2694B0: movss xmm0, dword ptr [0x005575CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575CCu);
	// 0x2694B8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2694C0: movss [0x0054FF2C], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF2Cu, ctx.xmm[0].u32[0]);
	// 0x2694C8: ret
	return;
}

void sub_2694D0(X86Context& ctx, uint8_t* base) {
	// 0x2694D0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2694D8: movss [0x0054FF18], xmm0
	X86_MEM_WRITE_u32(base, 0x54FF18u, ctx.xmm[0].u32[0]);
	// 0x2694E0: ret
	return;
}

void sub_2694F0(X86Context& ctx, uint8_t* base) {
	// 0x2694F0: movss xmm0, dword ptr [0x0054FF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54FF2Cu);
	// 0x2694F8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x269500: movss [0x005575BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5575BCu, ctx.xmm[0].u32[0]);
	// 0x269508: ret
	return;
}

void sub_269510(X86Context& ctx, uint8_t* base) {
	// 0x269510: mov eax, 0x54FF30
	ctx.eax = 5570352;
	// 0x269515: jmp 0x000603A0
	goto loc_603A0;
	// ---- chunk at 0x603A0 (size 0x1C6) ----
loc_603A0:
	// 0x603A0: mov dword ptr [eax], 0x3AB4F0
	X86_MEM_WRITE_u32(base, ctx.eax, 3847408);
	// 0x603A6: mov dword ptr [eax+0x70], 0x3AB4D0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, 3847376);
	// 0x603AD: mov dword ptr [eax+0xA60], 0x3AB4B0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xA60u, 3847344);
	// 0x603B7: mov dword ptr [eax+0xA7C], 0x3AB4A0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xA7Cu, 3847328);
	// 0x603C1: mov dword ptr [eax+0xA98], 0x3AB490
	X86_MEM_WRITE_u32(base, ctx.eax + 0xA98u, 3847312);
	// 0x603CB: mov dword ptr [eax+0xAC4], 0x3AB558
	X86_MEM_WRITE_u32(base, ctx.eax + 0xAC4u, 3847512);
	// 0x603D5: mov dword ptr [eax+0xB9C], 0x3AB4C8
	X86_MEM_WRITE_u32(base, ctx.eax + 0xB9Cu, 3847368);
	// 0x603DF: mov dword ptr [eax+0xC8C], 0x3AB588
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC8Cu, 3847560);
	// 0x603E9: mov dword ptr [eax+0xCE8], 0x3AB4F8
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCE8u, 3847416);
	// 0x603F3: mov dword ptr [eax+0xD08], 0x3AB4C0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD08u, 3847360);
	// 0x603FD: mov dword ptr [eax+0xD80], 0x3AB5D0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD80u, 3847632);
	// 0x60407: mov dword ptr [eax+0xE38], 0x3AB528
	X86_MEM_WRITE_u32(base, ctx.eax + 0xE38u, 3847464);
	// 0x60411: mov dword ptr [eax+0xE70], 0x3AB5A0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xE70u, 3847584);
	// 0x6041B: mov dword ptr [eax+0xF08], 0x3AB5C0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xF08u, 3847616);
	// 0x60425: mov dword ptr [eax+0xF40], 0x3AB5A8
	X86_MEM_WRITE_u32(base, ctx.eax + 0xF40u, 3847592);
	// 0x6042F: mov dword ptr [eax+0x4160], 0x3AB540
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4160u, 3847488);
	// 0x60439: mov dword ptr [eax+0x49D0], 0x3AB4A8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x49D0u, 3847336);
	// 0x60443: mov dword ptr [eax+0x4A10], 0x3AB590
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4A10u, 3847568);
	// 0x6044D: mov dword ptr [eax+0x4A30], 0x3AB550
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4A30u, 3847504);
	// 0x60457: mov dword ptr [eax+0x4A70], 0x3AB498
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4A70u, 3847320);
	// 0x60461: mov dword ptr [eax+0x4AA0], 0x3AB548
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4AA0u, 3847496);
	// 0x6046B: mov dword ptr [eax+0x4AD0], 0x3AB510
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4AD0u, 3847440);
	// 0x60475: mov dword ptr [eax+0x4B00], 0x3AB5B8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4B00u, 3847608);
	// 0x6047F: mov dword ptr [eax+0x4BF0], 0x3AB560
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4BF0u, 3847520);
	// 0x60489: mov dword ptr [eax+0x5A80], 0x3AB508
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5A80u, 3847432);
	// 0x60493: mov dword ptr [eax+0x5AD0], 0x3AB480
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5AD0u, 3847296);
	// 0x6049D: mov dword ptr [eax+0x5B3C], 0x3AB598
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5B3Cu, 3847576);
	// 0x604A7: mov dword ptr [eax+0x5B58], 0x3AB520
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5B58u, 3847456);
	// 0x604B1: mov dword ptr [eax+0x5D20], 0x3AB570
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5D20u, 3847536);
	// 0x604BB: mov dword ptr [eax+0x5D60], 0x3AB530
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5D60u, 3847472);
	// 0x604C5: mov dword ptr [eax+0x5E20], 0x3AB4B8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5E20u, 3847352);
	// 0x604CF: mov dword ptr [eax+0x6078], 0x3AB5D8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6078u, 3847640);
	// 0x604D9: mov dword ptr [eax+0x60C0], 0x3AB4E8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x60C0u, 3847400);
	// 0x604E3: mov dword ptr [eax+0x60E0], 0x3A9AEC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x60E0u, 3840748);
	// 0x604ED: mov dword ptr [eax+0x61C0], 0x3AB4E0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x61C0u, 3847392);
	// 0x604F7: mov dword ptr [eax+0x6428], 0x3AB578
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6428u, 3847544);
	// 0x60501: mov dword ptr [eax+0x6468], 0x3AB488
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6468u, 3847304);
	// 0x6050B: mov dword ptr [eax+0x6548], 0x3AB5C8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6548u, 3847624);
	// 0x60515: mov dword ptr [eax+0x6620], 0x3AB500
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6620u, 3847424);
	// 0x6051F: mov dword ptr [eax+0x6828], 0x3AB580
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6828u, 3847552);
	// 0x60529: mov dword ptr [eax+0x6868], 0x3AB478
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6868u, 3847288);
	// 0x60533: mov dword ptr [eax+0x68F0], 0x3AB538
	X86_MEM_WRITE_u32(base, ctx.eax + 0x68F0u, 3847480);
	// 0x6053D: mov dword ptr [eax+0x6ED0], 0x3AB5B0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6ED0u, 3847600);
	// 0x60547: mov dword ptr [eax+0x6EF0], 0x3AB568
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6EF0u, 3847528);
	// 0x60551: mov dword ptr [eax+0x7580], 0x3AB518
	X86_MEM_WRITE_u32(base, ctx.eax + 0x7580u, 3847448);
	// 0x6055B: mov dword ptr [eax+0x7634], 0x3AB4D8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x7634u, 3847384);
	// 0x60565: ret
	return;
}

void sub_269520(X86Context& ctx, uint8_t* base) {
	// 0x269520: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x269528: movss [0x00557640], xmm0
	X86_MEM_WRITE_u32(base, 0x557640u, ctx.xmm[0].u32[0]);
	// 0x269530: ret
	return;
}

void sub_269540(X86Context& ctx, uint8_t* base) {
	// 0x269540: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x269548: movss [0x0055765C], xmm0
	X86_MEM_WRITE_u32(base, 0x55765Cu, ctx.xmm[0].u32[0]);
	// 0x269550: ret
	return;
}

void sub_269560(X86Context& ctx, uint8_t* base) {
	// 0x269560: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x269568: movss [0x00557634], xmm0
	X86_MEM_WRITE_u32(base, 0x557634u, ctx.xmm[0].u32[0]);
	// 0x269570: ret
	return;
}

void sub_269580(X86Context& ctx, uint8_t* base) {
	// 0x269580: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x269588: movss [0x005575EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5575ECu, ctx.xmm[0].u32[0]);
	// 0x269590: ret
	return;
}

void sub_2695A0(X86Context& ctx, uint8_t* base) {
	// 0x2695A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2695A8: movss [0x00557644], xmm0
	X86_MEM_WRITE_u32(base, 0x557644u, ctx.xmm[0].u32[0]);
	// 0x2695B0: ret
	return;
}

void sub_2695C0(X86Context& ctx, uint8_t* base) {
	// 0x2695C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2695C8: movss [0x00557608], xmm0
	X86_MEM_WRITE_u32(base, 0x557608u, ctx.xmm[0].u32[0]);
	// 0x2695D0: ret
	return;
}

void sub_2695E0(X86Context& ctx, uint8_t* base) {
	// 0x2695E0: movss xmm0, dword ptr [0x00557644]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557644u);
	// 0x2695E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2695F0: movss [0x0055767C], xmm0
	X86_MEM_WRITE_u32(base, 0x55767Cu, ctx.xmm[0].u32[0]);
	// 0x2695F8: ret
	return;
}

void sub_269600(X86Context& ctx, uint8_t* base) {
	// 0x269600: movss xmm0, dword ptr [0x00557608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557608u);
	// 0x269608: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x269610: movss [0x00557664], xmm0
	X86_MEM_WRITE_u32(base, 0x557664u, ctx.xmm[0].u32[0]);
	// 0x269618: ret
	return;
}

void sub_269620(X86Context& ctx, uint8_t* base) {
	// 0x269620: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x269628: movss [0x00557694], xmm0
	X86_MEM_WRITE_u32(base, 0x557694u, ctx.xmm[0].u32[0]);
	// 0x269630: ret
	return;
}

void sub_269640(X86Context& ctx, uint8_t* base) {
	// 0x269640: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x269648: movss [0x00557680], xmm0
	X86_MEM_WRITE_u32(base, 0x557680u, ctx.xmm[0].u32[0]);
	// 0x269650: ret
	return;
}

void sub_269660(X86Context& ctx, uint8_t* base) {
	// 0x269660: movss xmm0, dword ptr [0x00557680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557680u);
	// 0x269668: movss [0x00557690], xmm0
	X86_MEM_WRITE_u32(base, 0x557690u, ctx.xmm[0].u32[0]);
	// 0x269670: ret
	return;
}

void sub_269680(X86Context& ctx, uint8_t* base) {
	// 0x269680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x269688: movss [0x005575F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5575F4u, ctx.xmm[0].u32[0]);
	// 0x269690: ret
	return;
}

void sub_2696A0(X86Context& ctx, uint8_t* base) {
	// 0x2696A0: movss xmm0, dword ptr [0x00557608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557608u);
	// 0x2696A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2696B0: movss [0x00557688], xmm0
	X86_MEM_WRITE_u32(base, 0x557688u, ctx.xmm[0].u32[0]);
	// 0x2696B8: ret
	return;
}

void sub_2696C0(X86Context& ctx, uint8_t* base) {
	// 0x2696C0: movss xmm0, dword ptr [0x00557608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557608u);
	// 0x2696C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2696D0: movss [0x00557630], xmm0
	X86_MEM_WRITE_u32(base, 0x557630u, ctx.xmm[0].u32[0]);
	// 0x2696D8: ret
	return;
}

void sub_2696E0(X86Context& ctx, uint8_t* base) {
	// 0x2696E0: movss xmm0, dword ptr [0x00557608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557608u);
	// 0x2696E8: subss xmm0, [0x00557630]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x557630u);
	// 0x2696F0: movss [0x00557610], xmm0
	X86_MEM_WRITE_u32(base, 0x557610u, ctx.xmm[0].u32[0]);
	// 0x2696F8: ret
	return;
}

void sub_269700(X86Context& ctx, uint8_t* base) {
	// 0x269700: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x269708: movss [0x00557658], xmm0
	X86_MEM_WRITE_u32(base, 0x557658u, ctx.xmm[0].u32[0]);
	// 0x269710: ret
	return;
}

void sub_269720(X86Context& ctx, uint8_t* base) {
	// 0x269720: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x269728: movss [0x0055760C], xmm0
	X86_MEM_WRITE_u32(base, 0x55760Cu, ctx.xmm[0].u32[0]);
	// 0x269730: ret
	return;
}

void sub_269740(X86Context& ctx, uint8_t* base) {
	// 0x269740: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x269748: movss [0x0055761C], xmm0
	X86_MEM_WRITE_u32(base, 0x55761Cu, ctx.xmm[0].u32[0]);
	// 0x269750: ret
	return;
}

void sub_269760(X86Context& ctx, uint8_t* base) {
	// 0x269760: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x269768: movss [0x00557670], xmm0
	X86_MEM_WRITE_u32(base, 0x557670u, ctx.xmm[0].u32[0]);
	// 0x269770: ret
	return;
}

void sub_269780(X86Context& ctx, uint8_t* base) {
	// 0x269780: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x269788: movss [0x00557654], xmm0
	X86_MEM_WRITE_u32(base, 0x557654u, ctx.xmm[0].u32[0]);
	// 0x269790: ret
	return;
}

void sub_2697A0(X86Context& ctx, uint8_t* base) {
	// 0x2697A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2697A8: movss [0x00557604], xmm0
	X86_MEM_WRITE_u32(base, 0x557604u, ctx.xmm[0].u32[0]);
	// 0x2697B0: ret
	return;
}

void sub_2697C0(X86Context& ctx, uint8_t* base) {
	// 0x2697C0: movss xmm0, dword ptr [0x0055761C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55761Cu);
	// 0x2697C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2697D0: movss [0x005575F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5575F8u, ctx.xmm[0].u32[0]);
	// 0x2697D8: ret
	return;
}

void sub_2697E0(X86Context& ctx, uint8_t* base) {
	// 0x2697E0: movss xmm0, dword ptr [0x00557670]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557670u);
	// 0x2697E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2697F0: movss [0x0055763C], xmm0
	X86_MEM_WRITE_u32(base, 0x55763Cu, ctx.xmm[0].u32[0]);
	// 0x2697F8: ret
	return;
}

void sub_269800(X86Context& ctx, uint8_t* base) {
	// 0x269800: movss xmm0, dword ptr [0x005575F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5575F8u);
	// 0x269808: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x269810: movss [0x0055764C], xmm0
	X86_MEM_WRITE_u32(base, 0x55764Cu, ctx.xmm[0].u32[0]);
	// 0x269818: ret
	return;
}

void sub_269820(X86Context& ctx, uint8_t* base) {
	// 0x269820: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x269828: movss [0x005575F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5575F0u, ctx.xmm[0].u32[0]);
	// 0x269830: ret
	return;
}

void sub_269840(X86Context& ctx, uint8_t* base) {
	// 0x269840: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x269848: movss [0x00557620], xmm0
	X86_MEM_WRITE_u32(base, 0x557620u, ctx.xmm[0].u32[0]);
	// 0x269850: ret
	return;
}

void sub_269860(X86Context& ctx, uint8_t* base) {
	// 0x269860: movss xmm0, dword ptr [0x0055761C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55761Cu);
	// 0x269868: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x269870: movss [0x0055762C], xmm0
	X86_MEM_WRITE_u32(base, 0x55762Cu, ctx.xmm[0].u32[0]);
	// 0x269878: ret
	return;
}

void sub_269880(X86Context& ctx, uint8_t* base) {
	// 0x269880: movss xmm0, dword ptr [0x00557670]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557670u);
	// 0x269888: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x269890: movss [0x00557674], xmm0
	X86_MEM_WRITE_u32(base, 0x557674u, ctx.xmm[0].u32[0]);
	// 0x269898: ret
	return;
}

void sub_2698A0(X86Context& ctx, uint8_t* base) {
	// 0x2698A0: movss xmm0, dword ptr [0x0055762C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55762Cu);
	// 0x2698A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2698B0: movss [0x00557660], xmm0
	X86_MEM_WRITE_u32(base, 0x557660u, ctx.xmm[0].u32[0]);
	// 0x2698B8: ret
	return;
}

void sub_2698C0(X86Context& ctx, uint8_t* base) {
	// 0x2698C0: movss xmm0, dword ptr [0x00557674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557674u);
	// 0x2698C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2698D0: movss [0x00557684], xmm0
	X86_MEM_WRITE_u32(base, 0x557684u, ctx.xmm[0].u32[0]);
	// 0x2698D8: ret
	return;
}

void sub_2698E0(X86Context& ctx, uint8_t* base) {
	// 0x2698E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2698E8: movss [0x005575FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5575FCu, ctx.xmm[0].u32[0]);
	// 0x2698F0: ret
	return;
}

void sub_269900(X86Context& ctx, uint8_t* base) {
	// 0x269900: movss xmm0, dword ptr [0x0055761C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55761Cu);
	// 0x269908: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269910: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x269918: movss [0x0055766C], xmm0
	X86_MEM_WRITE_u32(base, 0x55766Cu, ctx.xmm[0].u32[0]);
	// 0x269920: ret
	return;
}

void sub_269930(X86Context& ctx, uint8_t* base) {
	// 0x269930: movss xmm0, dword ptr [0x00557670]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557670u);
	// 0x269938: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269940: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x269948: movss [0x00557614], xmm0
	X86_MEM_WRITE_u32(base, 0x557614u, ctx.xmm[0].u32[0]);
	// 0x269950: ret
	return;
}

void sub_269960(X86Context& ctx, uint8_t* base) {
	// 0x269960: movss xmm0, dword ptr [0x0055761C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55761Cu);
	// 0x269968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269970: movss [0x00557618], xmm0
	X86_MEM_WRITE_u32(base, 0x557618u, ctx.xmm[0].u32[0]);
	// 0x269978: ret
	return;
}

void sub_269980(X86Context& ctx, uint8_t* base) {
	// 0x269980: movss xmm0, dword ptr [0x00557670]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557670u);
	// 0x269988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x269990: movss [0x00557678], xmm0
	X86_MEM_WRITE_u32(base, 0x557678u, ctx.xmm[0].u32[0]);
	// 0x269998: ret
	return;
}

void sub_2699A0(X86Context& ctx, uint8_t* base) {
	// 0x2699A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2699A8: movss [0x00557600], xmm0
	X86_MEM_WRITE_u32(base, 0x557600u, ctx.xmm[0].u32[0]);
	// 0x2699B0: ret
	return;
}

void sub_2699C0(X86Context& ctx, uint8_t* base) {
	// 0x2699C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2699C8: movss [0x00557628], xmm0
	X86_MEM_WRITE_u32(base, 0x557628u, ctx.xmm[0].u32[0]);
	// 0x2699D0: ret
	return;
}

void sub_2699E0(X86Context& ctx, uint8_t* base) {
	// 0x2699E0: movss xmm0, dword ptr [0x00557600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557600u);
	// 0x2699E8: movss [0x0055768C], xmm0
	X86_MEM_WRITE_u32(base, 0x55768Cu, ctx.xmm[0].u32[0]);
	// 0x2699F0: ret
	return;
}

void sub_269A00(X86Context& ctx, uint8_t* base) {
	// 0x269A00: movss xmm0, dword ptr [0x00557670]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557670u);
	// 0x269A08: subss xmm0, [0x00557600]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x557600u);
	// 0x269A10: movss [0x00557650], xmm0
	X86_MEM_WRITE_u32(base, 0x557650u, ctx.xmm[0].u32[0]);
	// 0x269A18: ret
	return;
}

void sub_269A20(X86Context& ctx, uint8_t* base) {
	// 0x269A20: movss xmm0, dword ptr [0x00557650]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557650u);
	// 0x269A28: subss xmm0, [0x00557628]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x557628u);
	// 0x269A30: movss [0x00557648], xmm0
	X86_MEM_WRITE_u32(base, 0x557648u, ctx.xmm[0].u32[0]);
	// 0x269A38: ret
	return;
}

void sub_269A40(X86Context& ctx, uint8_t* base) {
	// 0x269A40: movss xmm0, dword ptr [0x00557678]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557678u);
	// 0x269A48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x269A50: movss [0x00557638], xmm0
	X86_MEM_WRITE_u32(base, 0x557638u, ctx.xmm[0].u32[0]);
	// 0x269A58: ret
	return;
}

void sub_269A60(X86Context& ctx, uint8_t* base) {
	// 0x269A60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x269A68: movss [0x00557624], xmm0
	X86_MEM_WRITE_u32(base, 0x557624u, ctx.xmm[0].u32[0]);
	// 0x269A70: ret
	return;
}

void sub_269A80(X86Context& ctx, uint8_t* base) {
	// 0x269A80: movss xmm0, dword ptr [0x00557638]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557638u);
	// 0x269A88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x269A90: movss [0x00557668], xmm0
	X86_MEM_WRITE_u32(base, 0x557668u, ctx.xmm[0].u32[0]);
	// 0x269A98: ret
	return;
}

void sub_269AA0(X86Context& ctx, uint8_t* base) {
	// 0x269AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x269AA8: movss [0x00557808], xmm0
	X86_MEM_WRITE_u32(base, 0x557808u, ctx.xmm[0].u32[0]);
	// 0x269AB0: ret
	return;
}

void sub_269AC0(X86Context& ctx, uint8_t* base) {
	// 0x269AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x269AC8: movss [0x00557814], xmm0
	X86_MEM_WRITE_u32(base, 0x557814u, ctx.xmm[0].u32[0]);
	// 0x269AD0: ret
	return;
}

void sub_269AE0(X86Context& ctx, uint8_t* base) {
	// 0x269AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x269AE8: movss [0x00557804], xmm0
	X86_MEM_WRITE_u32(base, 0x557804u, ctx.xmm[0].u32[0]);
	// 0x269AF0: ret
	return;
}

void sub_269B00(X86Context& ctx, uint8_t* base) {
	// 0x269B00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x269B08: movss [0x00557698], xmm0
	X86_MEM_WRITE_u32(base, 0x557698u, ctx.xmm[0].u32[0]);
	// 0x269B10: ret
	return;
}

void sub_269B20(X86Context& ctx, uint8_t* base) {
	// 0x269B20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x269B28: movss [0x0055780C], xmm0
	X86_MEM_WRITE_u32(base, 0x55780Cu, ctx.xmm[0].u32[0]);
	// 0x269B30: ret
	return;
}

void sub_269B40(X86Context& ctx, uint8_t* base) {
	// 0x269B40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x269B48: movss [0x005576A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5576A0u, ctx.xmm[0].u32[0]);
	// 0x269B50: ret
	return;
}

void sub_269B60(X86Context& ctx, uint8_t* base) {
	// 0x269B60: movss xmm0, dword ptr [0x0055780C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55780Cu);
	// 0x269B68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x269B70: movss [0x0055781C], xmm0
	X86_MEM_WRITE_u32(base, 0x55781Cu, ctx.xmm[0].u32[0]);
	// 0x269B78: ret
	return;
}

void sub_269B80(X86Context& ctx, uint8_t* base) {
	// 0x269B80: movss xmm0, dword ptr [0x005576A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5576A0u);
	// 0x269B88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x269B90: movss [0x00557818], xmm0
	X86_MEM_WRITE_u32(base, 0x557818u, ctx.xmm[0].u32[0]);
	// 0x269B98: ret
	return;
}

void sub_269BA0(X86Context& ctx, uint8_t* base) {
	// 0x269BA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x269BA8: movss [0x0055782C], xmm0
	X86_MEM_WRITE_u32(base, 0x55782Cu, ctx.xmm[0].u32[0]);
	// 0x269BB0: ret
	return;
}

void sub_269BC0(X86Context& ctx, uint8_t* base) {
	// 0x269BC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x269BC8: movss [0x00557820], xmm0
	X86_MEM_WRITE_u32(base, 0x557820u, ctx.xmm[0].u32[0]);
	// 0x269BD0: ret
	return;
}

void sub_269BE0(X86Context& ctx, uint8_t* base) {
	// 0x269BE0: movss xmm0, dword ptr [0x00557820]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557820u);
	// 0x269BE8: movss [0x00557828], xmm0
	X86_MEM_WRITE_u32(base, 0x557828u, ctx.xmm[0].u32[0]);
	// 0x269BF0: ret
	return;
}

void sub_269C00(X86Context& ctx, uint8_t* base) {
	// 0x269C00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x269C08: movss [0x0055769C], xmm0
	X86_MEM_WRITE_u32(base, 0x55769Cu, ctx.xmm[0].u32[0]);
	// 0x269C10: ret
	return;
}

void sub_269C20(X86Context& ctx, uint8_t* base) {
	// 0x269C20: movss xmm0, dword ptr [0x005576A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5576A0u);
	// 0x269C28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x269C30: movss [0x00557824], xmm0
	X86_MEM_WRITE_u32(base, 0x557824u, ctx.xmm[0].u32[0]);
	// 0x269C38: ret
	return;
}

void sub_269C40(X86Context& ctx, uint8_t* base) {
	// 0x269C40: movss xmm0, dword ptr [0x005576A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5576A0u);
	// 0x269C48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x269C50: movss [0x00557800], xmm0
	X86_MEM_WRITE_u32(base, 0x557800u, ctx.xmm[0].u32[0]);
	// 0x269C58: ret
	return;
}

void sub_269C60(X86Context& ctx, uint8_t* base) {
	// 0x269C60: movss xmm0, dword ptr [0x005576A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5576A0u);
	// 0x269C68: subss xmm0, [0x00557800]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x557800u);
	// 0x269C70: movss [0x005576A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5576A8u, ctx.xmm[0].u32[0]);
	// 0x269C78: ret
	return;
}

void sub_269C80(X86Context& ctx, uint8_t* base) {
	// 0x269C80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x269C88: movss [0x00557810], xmm0
	X86_MEM_WRITE_u32(base, 0x557810u, ctx.xmm[0].u32[0]);
	// 0x269C90: ret
	return;
}

void sub_269CA0(X86Context& ctx, uint8_t* base) {
	// 0x269CA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x269CA8: movss [0x005576A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5576A4u, ctx.xmm[0].u32[0]);
	// 0x269CB0: ret
	return;
}

void sub_269CC0(X86Context& ctx, uint8_t* base) {
	// 0x269CC0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x269CC1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x269CC3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x269CC6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x269CC9: xorps xmm1, xmm1
	memset(&ctx.xmm[1], 0, sizeof(ctx.xmm[1]));
	// 0x269CCC: movss xmm4, dword ptr [0x003B168C]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x269CD4: movss xmm0, dword ptr [0x003B1A90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A90u);
	// 0x269CDC: movss xmm3, dword ptr [0x003B219C]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B219Cu);
	// 0x269CE4: movss xmm2, dword ptr [0x003B208C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B208Cu);
	// 0x269CEC: movss xmm5, dword ptr [0x0035BEE0]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x35BEE0u);
	// 0x269CF4: movss xmm6, dword ptr [0x003B1F54]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B1F54u);
	// 0x269CFC: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x269D01: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269D04: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x269D09: movss xmm0, dword ptr [0x003B2130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2130u);
	// 0x269D11: mov [0x005576B0], eax
	X86_MEM_WRITE_u32(base, 0x5576B0u, ctx.eax);
	// 0x269D16: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x269D1C: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269D20: mov [0x005576B4], ecx
	X86_MEM_WRITE_u32(base, 0x5576B4u, ctx.ecx);
	// 0x269D26: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269D29: movss [esp+0x08], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[4].u32[0]);
	// 0x269D2F: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269D33: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x269D39: movss xmm0, dword ptr [0x003B1F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F88u);
	// 0x269D41: mov [0x005576B8], edx
	X86_MEM_WRITE_u32(base, 0x5576B8u, ctx.edx);
	// 0x269D47: movss [esp+0x0C], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[4].u32[0]);
	// 0x269D4D: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269D51: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x269D57: mov [0x005576BC], eax
	X86_MEM_WRITE_u32(base, 0x5576BCu, ctx.eax);
	// 0x269D5C: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269D60: movss [esp+0x04], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[3].u32[0]);
	// 0x269D66: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269D6A: mov [0x005576C0], ecx
	X86_MEM_WRITE_u32(base, 0x5576C0u, ctx.ecx);
	// 0x269D70: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269D74: mov [0x005576C4], edx
	X86_MEM_WRITE_u32(base, 0x5576C4u, ctx.edx);
	// 0x269D7A: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x269D80: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x269D85: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269D88: mov [0x005576C8], eax
	X86_MEM_WRITE_u32(base, 0x5576C8u, ctx.eax);
	// 0x269D8D: mov [0x005576CC], ecx
	X86_MEM_WRITE_u32(base, 0x5576CCu, ctx.ecx);
	// 0x269D93: mov [0x005576D0], edx
	X86_MEM_WRITE_u32(base, 0x5576D0u, ctx.edx);
	// 0x269D99: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269D9D: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x269DA3: movss xmm0, dword ptr [0x003B2268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2268u);
	// 0x269DAB: movss [esp+0x04], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[3].u32[0]);
	// 0x269DB1: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269DB5: movss [esp+0x08], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[5].u32[0]);
	// 0x269DBB: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269DBF: mov [0x005576D4], eax
	X86_MEM_WRITE_u32(base, 0x5576D4u, ctx.eax);
	// 0x269DC4: mov [0x005576D8], ecx
	X86_MEM_WRITE_u32(base, 0x5576D8u, ctx.ecx);
	// 0x269DCA: movss [esp], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[5].u32[0]);
	// 0x269DCF: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269DD2: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x269DD7: movss xmm0, dword ptr [0x003B2264]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2264u);
	// 0x269DDF: mov [0x005576DC], edx
	X86_MEM_WRITE_u32(base, 0x5576DCu, ctx.edx);
	// 0x269DE5: movss [esp+0x04], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[3].u32[0]);
	// 0x269DEB: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269DEF: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x269DF5: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269DF9: movss xmm2, dword ptr [0x003B1C30]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x269E01: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x269E07: movss xmm0, dword ptr [0x003B2260]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2260u);
	// 0x269E0F: mov [0x005576E4], ecx
	X86_MEM_WRITE_u32(base, 0x5576E4u, ctx.ecx);
	// 0x269E15: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269E18: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x269E1D: movss xmm0, dword ptr [0x003B213C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B213Cu);
	// 0x269E25: mov [0x005576E0], eax
	X86_MEM_WRITE_u32(base, 0x5576E0u, ctx.eax);
	// 0x269E2A: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269E2E: mov [0x005576E8], edx
	X86_MEM_WRITE_u32(base, 0x5576E8u, ctx.edx);
	// 0x269E34: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x269E3A: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269E3E: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x269E44: movss xmm0, dword ptr [0x00386600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x386600u);
	// 0x269E4C: mov [0x005576EC], eax
	X86_MEM_WRITE_u32(base, 0x5576ECu, ctx.eax);
	// 0x269E51: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269E55: movss [esp+0x0C], xmm6
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[6].u32[0]);
	// 0x269E5B: mov [0x005576F0], ecx
	X86_MEM_WRITE_u32(base, 0x5576F0u, ctx.ecx);
	// 0x269E61: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269E65: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x269E6B: movss xmm0, dword ptr [0x003B225C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B225Cu);
	// 0x269E73: mov [0x005576F4], edx
	X86_MEM_WRITE_u32(base, 0x5576F4u, ctx.edx);
	// 0x269E79: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269E7C: mov [0x005576F8], eax
	X86_MEM_WRITE_u32(base, 0x5576F8u, ctx.eax);
	// 0x269E81: mov [0x005576FC], ecx
	X86_MEM_WRITE_u32(base, 0x5576FCu, ctx.ecx);
	// 0x269E87: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x269E8D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269E91: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269E95: movss xmm7, dword ptr [0x003B1ABC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1ABCu);
	// 0x269E9D: mov [0x00557700], edx
	X86_MEM_WRITE_u32(base, 0x557700u, ctx.edx);
	// 0x269EA3: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269EA7: movss [esp], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[7].u32[0]);
	// 0x269EAC: movss xmm7, dword ptr [0x003A3230]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A3230u);
	// 0x269EB4: mov [0x00557704], eax
	X86_MEM_WRITE_u32(base, 0x557704u, ctx.eax);
	// 0x269EB9: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269EBC: mov [0x00557708], ecx
	X86_MEM_WRITE_u32(base, 0x557708u, ctx.ecx);
	// 0x269EC2: mov [0x0055770C], edx
	X86_MEM_WRITE_u32(base, 0x55770Cu, ctx.edx);
	// 0x269EC8: movss [esp+0x04], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[5].u32[0]);
	// 0x269ECE: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269ED2: movss xmm5, dword ptr [0x003B1C34]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x269EDA: mov [0x00557710], eax
	X86_MEM_WRITE_u32(base, 0x557710u, ctx.eax);
	// 0x269EDF: mov [0x00557714], ecx
	X86_MEM_WRITE_u32(base, 0x557714u, ctx.ecx);
	// 0x269EE5: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x269EEA: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269EED: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x269EF3: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269EF7: movss [esp+0x08], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[7].u32[0]);
	// 0x269EFD: movss xmm7, dword ptr [0x003B2258]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2258u);
	// 0x269F05: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x269F0B: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269F0F: movss [esp+0x0C], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[7].u32[0]);
	// 0x269F15: movss xmm7, dword ptr [0x003B2254]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2254u);
	// 0x269F1D: mov [0x00557718], edx
	X86_MEM_WRITE_u32(base, 0x557718u, ctx.edx);
	// 0x269F23: mov [0x0055771C], eax
	X86_MEM_WRITE_u32(base, 0x55771Cu, ctx.eax);
	// 0x269F28: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269F2C: mov [0x00557720], ecx
	X86_MEM_WRITE_u32(base, 0x557720u, ctx.ecx);
	// 0x269F32: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269F36: movss [esp], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[7].u32[0]);
	// 0x269F3B: movss xmm7, dword ptr [0x003B2250]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2250u);
	// 0x269F43: movss [esp+0x04], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[5].u32[0]);
	// 0x269F49: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269F4D: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x269F53: mov [0x00557724], edx
	X86_MEM_WRITE_u32(base, 0x557724u, ctx.edx);
	// 0x269F59: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269F5C: mov [0x00557728], eax
	X86_MEM_WRITE_u32(base, 0x557728u, ctx.eax);
	// 0x269F61: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269F65: mov [0x0055772C], ecx
	X86_MEM_WRITE_u32(base, 0x55772Cu, ctx.ecx);
	// 0x269F6B: movss [esp+0x08], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[7].u32[0]);
	// 0x269F71: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269F75: movss xmm7, dword ptr [0x00386600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x386600u);
	// 0x269F7D: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x269F83: mov [0x00557730], edx
	X86_MEM_WRITE_u32(base, 0x557730u, ctx.edx);
	// 0x269F89: mov [0x00557734], eax
	X86_MEM_WRITE_u32(base, 0x557734u, ctx.eax);
	// 0x269F8E: mov [0x00557738], ecx
	X86_MEM_WRITE_u32(base, 0x557738u, ctx.ecx);
	// 0x269F94: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x269F98: movss [esp], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[7].u32[0]);
	// 0x269F9D: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269FA0: movss xmm7, dword ptr [0x003B224C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B224Cu);
	// 0x269FA8: movss [esp+0x0C], xmm6
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[6].u32[0]);
	// 0x269FAE: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269FB2: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x269FB7: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x269FBD: movss xmm2, dword ptr [0x003B2248]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2248u);
	// 0x269FC5: mov [0x0055773C], edx
	X86_MEM_WRITE_u32(base, 0x55773Cu, ctx.edx);
	// 0x269FCB: movss [esp+0x08], xmm7
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[7].u32[0]);
	// 0x269FD1: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x269FD5: movss [esp+0x0C], xmm6
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[6].u32[0]);
	// 0x269FDB: mov [0x00557740], eax
	X86_MEM_WRITE_u32(base, 0x557740u, ctx.eax);
	// 0x269FE0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x269FE4: mov [0x00557744], ecx
	X86_MEM_WRITE_u32(base, 0x557744u, ctx.ecx);
	// 0x269FEA: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x269FED: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x269FF3: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x269FF8: movss xmm2, dword ptr [0x003B2244]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2244u);
	// 0x26A000: mov [0x00557748], edx
	X86_MEM_WRITE_u32(base, 0x557748u, ctx.edx);
	// 0x26A006: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A00A: mov [0x0055774C], eax
	X86_MEM_WRITE_u32(base, 0x55774Cu, ctx.eax);
	// 0x26A00F: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A013: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x26A019: mov [0x00557750], ecx
	X86_MEM_WRITE_u32(base, 0x557750u, ctx.ecx);
	// 0x26A01F: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A023: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x26A029: movss xmm2, dword ptr [0x003B2240]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2240u);
	// 0x26A031: mov [0x00557754], edx
	X86_MEM_WRITE_u32(base, 0x557754u, ctx.edx);
	// 0x26A037: mov [0x00557758], eax
	X86_MEM_WRITE_u32(base, 0x557758u, ctx.eax);
	// 0x26A03C: mov [0x0055775C], ecx
	X86_MEM_WRITE_u32(base, 0x55775Cu, ctx.ecx);
	// 0x26A042: movss [esp+0x08], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[4].u32[0]);
	// 0x26A048: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A04B: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A04F: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A053: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x26A059: movss xmm2, dword ptr [0x003B223C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B223Cu);
	// 0x26A061: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x26A066: movss xmm2, dword ptr [0x003B2238]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2238u);
	// 0x26A06E: mov [0x00557760], edx
	X86_MEM_WRITE_u32(base, 0x557760u, ctx.edx);
	// 0x26A074: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A078: mov [0x00557764], eax
	X86_MEM_WRITE_u32(base, 0x557764u, ctx.eax);
	// 0x26A07D: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A080: mov [0x00557768], ecx
	X86_MEM_WRITE_u32(base, 0x557768u, ctx.ecx);
	// 0x26A086: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x26A08C: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A090: movss xmm2, dword ptr [0x003B2234]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2234u);
	// 0x26A098: mov [0x0055776C], edx
	X86_MEM_WRITE_u32(base, 0x55776Cu, ctx.edx);
	// 0x26A09E: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x26A0A4: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A0A8: movss xmm2, dword ptr [0x003B2230]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2230u);
	// 0x26A0B0: mov [0x00557770], eax
	X86_MEM_WRITE_u32(base, 0x557770u, ctx.eax);
	// 0x26A0B5: mov [0x00557774], ecx
	X86_MEM_WRITE_u32(base, 0x557774u, ctx.ecx);
	// 0x26A0BB: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x26A0C1: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A0C5: movss xmm2, dword ptr [0x003B222C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B222Cu);
	// 0x26A0CD: mov [0x00557778], edx
	X86_MEM_WRITE_u32(base, 0x557778u, ctx.edx);
	// 0x26A0D3: mov [0x0055777C], eax
	X86_MEM_WRITE_u32(base, 0x55777Cu, ctx.eax);
	// 0x26A0D8: movss [esp], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[5].u32[0]);
	// 0x26A0DD: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A0E0: mov [0x00557780], ecx
	X86_MEM_WRITE_u32(base, 0x557780u, ctx.ecx);
	// 0x26A0E6: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x26A0EC: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A0F0: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x26A0F6: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A0FA: mov [0x00557784], edx
	X86_MEM_WRITE_u32(base, 0x557784u, ctx.edx);
	// 0x26A100: movss [esp+0x08], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[3].u32[0]);
	// 0x26A106: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A10A: mov [0x00557788], eax
	X86_MEM_WRITE_u32(base, 0x557788u, ctx.eax);
	// 0x26A10F: mov [0x0055778C], ecx
	X86_MEM_WRITE_u32(base, 0x55778Cu, ctx.ecx);
	// 0x26A115: movss [esp], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[5].u32[0]);
	// 0x26A11A: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A11D: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x26A123: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A127: movss [esp+0x08], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[3].u32[0]);
	// 0x26A12D: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A131: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x26A137: movss xmm2, dword ptr [0x003B2228]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2228u);
	// 0x26A13F: mov [0x00557790], edx
	X86_MEM_WRITE_u32(base, 0x557790u, ctx.edx);
	// 0x26A145: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A149: mov [0x00557794], eax
	X86_MEM_WRITE_u32(base, 0x557794u, ctx.eax);
	// 0x26A14E: mov [0x00557798], ecx
	X86_MEM_WRITE_u32(base, 0x557798u, ctx.ecx);
	// 0x26A154: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x26A159: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A15C: movss [esp+0x04], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[2].u32[0]);
	// 0x26A162: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A166: mov [0x0055779C], edx
	X86_MEM_WRITE_u32(base, 0x55779Cu, ctx.edx);
	// 0x26A16C: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x26A172: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A176: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x26A17C: mov [0x005577A0], eax
	X86_MEM_WRITE_u32(base, 0x5577A0u, ctx.eax);
	// 0x26A181: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A185: mov [0x005577A4], ecx
	X86_MEM_WRITE_u32(base, 0x5577A4u, ctx.ecx);
	// 0x26A18B: movss [esp], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[2].u32[0]);
	// 0x26A190: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A193: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x26A199: mov [0x005577A8], edx
	X86_MEM_WRITE_u32(base, 0x5577A8u, ctx.edx);
	// 0x26A19F: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A1A3: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x26A1A9: movss xmm0, dword ptr [0x003A7F38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7F38u);
	// 0x26A1B1: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x26A1B7: mov [0x005577AC], eax
	X86_MEM_WRITE_u32(base, 0x5577ACu, ctx.eax);
	// 0x26A1BC: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A1C0: mov [0x005577B0], ecx
	X86_MEM_WRITE_u32(base, 0x5577B0u, ctx.ecx);
	// 0x26A1C6: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A1CA: mov [0x005577B4], edx
	X86_MEM_WRITE_u32(base, 0x5577B4u, ctx.edx);
	// 0x26A1D0: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x26A1D5: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A1D8: mov [0x005577B8], eax
	X86_MEM_WRITE_u32(base, 0x5577B8u, ctx.eax);
	// 0x26A1DD: mov [0x005577BC], ecx
	X86_MEM_WRITE_u32(base, 0x5577BCu, ctx.ecx);
	// 0x26A1E3: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x26A1E9: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x26A1EF: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x26A1F5: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A1F9: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A1FD: movss xmm3, dword ptr [0x003B1684]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x26A205: mov [0x005577C0], edx
	X86_MEM_WRITE_u32(base, 0x5577C0u, ctx.edx);
	// 0x26A20B: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A20F: mov [0x005577C4], eax
	X86_MEM_WRITE_u32(base, 0x5577C4u, ctx.eax);
	// 0x26A214: mov [0x005577C8], ecx
	X86_MEM_WRITE_u32(base, 0x5577C8u, ctx.ecx);
	// 0x26A21A: mov [0x005577CC], edx
	X86_MEM_WRITE_u32(base, 0x5577CCu, ctx.edx);
	// 0x26A220: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x26A226: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A22A: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x26A230: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A234: movss xmm0, dword ptr [0x003B1900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1900u);
	// 0x26A23C: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x26A241: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A244: mov [0x005577D0], eax
	X86_MEM_WRITE_u32(base, 0x5577D0u, ctx.eax);
	// 0x26A249: mov [0x005577D4], ecx
	X86_MEM_WRITE_u32(base, 0x5577D4u, ctx.ecx);
	// 0x26A24F: mov [0x005577D8], edx
	X86_MEM_WRITE_u32(base, 0x5577D8u, ctx.edx);
	// 0x26A255: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x26A25B: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A25F: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x26A264: mov ecx, [esp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A267: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x26A26D: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A271: mov [0x005577DC], eax
	X86_MEM_WRITE_u32(base, 0x5577DCu, ctx.eax);
	// 0x26A276: movss [esp+0x08], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[3].u32[0]);
	// 0x26A27C: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A280: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x26A286: mov [0x005577E0], ecx
	X86_MEM_WRITE_u32(base, 0x5577E0u, ctx.ecx);
	// 0x26A28C: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A290: mov [0x005577E4], edx
	X86_MEM_WRITE_u32(base, 0x5577E4u, ctx.edx);
	// 0x26A296: movss [esp], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[3].u32[0]);
	// 0x26A29B: mov edx, [esp]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	// 0x26A29E: mov [0x005577E8], eax
	X86_MEM_WRITE_u32(base, 0x5577E8u, ctx.eax);
	// 0x26A2A3: mov [0x005577EC], ecx
	X86_MEM_WRITE_u32(base, 0x5577ECu, ctx.ecx);
	// 0x26A2A9: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x26A2AF: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x26A2B3: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x26A2B9: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x26A2BD: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x26A2C3: mov [0x005577F0], edx
	X86_MEM_WRITE_u32(base, 0x5577F0u, ctx.edx);
	// 0x26A2C9: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x26A2CD: mov [0x005577F4], eax
	X86_MEM_WRITE_u32(base, 0x5577F4u, ctx.eax);
	// 0x26A2D2: mov [0x005577F8], ecx
	X86_MEM_WRITE_u32(base, 0x5577F8u, ctx.ecx);
	// 0x26A2D8: mov [0x005577FC], edx
	X86_MEM_WRITE_u32(base, 0x5577FCu, ctx.edx);
	// 0x26A2DE: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x26A2E0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x26A2E1: ret
	return;
}

void sub_26A2F0(X86Context& ctx, uint8_t* base) {
	// 0x26A2F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26A2F8: movss [0x00559298], xmm0
	X86_MEM_WRITE_u32(base, 0x559298u, ctx.xmm[0].u32[0]);
	// 0x26A300: ret
	return;
}

void sub_26A310(X86Context& ctx, uint8_t* base) {
	// 0x26A310: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26A318: movss [0x005592B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5592B4u, ctx.xmm[0].u32[0]);
	// 0x26A320: ret
	return;
}

void sub_26A330(X86Context& ctx, uint8_t* base) {
	// 0x26A330: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26A338: movss [0x00559288], xmm0
	X86_MEM_WRITE_u32(base, 0x559288u, ctx.xmm[0].u32[0]);
	// 0x26A340: ret
	return;
}

void sub_26A350(X86Context& ctx, uint8_t* base) {
	// 0x26A350: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26A358: movss [0x00557830], xmm0
	X86_MEM_WRITE_u32(base, 0x557830u, ctx.xmm[0].u32[0]);
	// 0x26A360: ret
	return;
}

void sub_26A370(X86Context& ctx, uint8_t* base) {
	// 0x26A370: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26A378: movss [0x0055929C], xmm0
	X86_MEM_WRITE_u32(base, 0x55929Cu, ctx.xmm[0].u32[0]);
	// 0x26A380: ret
	return;
}

void sub_26A390(X86Context& ctx, uint8_t* base) {
	// 0x26A390: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26A398: movss [0x00557850], xmm0
	X86_MEM_WRITE_u32(base, 0x557850u, ctx.xmm[0].u32[0]);
	// 0x26A3A0: ret
	return;
}

void sub_26A3B0(X86Context& ctx, uint8_t* base) {
	// 0x26A3B0: movss xmm0, dword ptr [0x0055929C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55929Cu);
	// 0x26A3B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26A3C0: movss [0x005592D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5592D4u, ctx.xmm[0].u32[0]);
	// 0x26A3C8: ret
	return;
}

void sub_26A3D0(X86Context& ctx, uint8_t* base) {
	// 0x26A3D0: movss xmm0, dword ptr [0x00557850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557850u);
	// 0x26A3D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26A3E0: movss [0x005592BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5592BCu, ctx.xmm[0].u32[0]);
	// 0x26A3E8: ret
	return;
}

void sub_26A3F0(X86Context& ctx, uint8_t* base) {
	// 0x26A3F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26A3F8: movss [0x005592EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5592ECu, ctx.xmm[0].u32[0]);
	// 0x26A400: ret
	return;
}

void sub_26A410(X86Context& ctx, uint8_t* base) {
	// 0x26A410: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26A418: movss [0x005592D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5592D8u, ctx.xmm[0].u32[0]);
	// 0x26A420: ret
	return;
}

void sub_26A430(X86Context& ctx, uint8_t* base) {
	// 0x26A430: movss xmm0, dword ptr [0x005592D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592D8u);
	// 0x26A438: movss [0x005592E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5592E8u, ctx.xmm[0].u32[0]);
	// 0x26A440: ret
	return;
}

void sub_26A450(X86Context& ctx, uint8_t* base) {
	// 0x26A450: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26A458: movss [0x0055783C], xmm0
	X86_MEM_WRITE_u32(base, 0x55783Cu, ctx.xmm[0].u32[0]);
	// 0x26A460: ret
	return;
}

void sub_26A470(X86Context& ctx, uint8_t* base) {
	// 0x26A470: movss xmm0, dword ptr [0x00557850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557850u);
	// 0x26A478: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26A480: movss [0x005592E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5592E0u, ctx.xmm[0].u32[0]);
	// 0x26A488: ret
	return;
}

void sub_26A490(X86Context& ctx, uint8_t* base) {
	// 0x26A490: movss xmm0, dword ptr [0x00557850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557850u);
	// 0x26A498: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26A4A0: movss [0x00559284], xmm0
	X86_MEM_WRITE_u32(base, 0x559284u, ctx.xmm[0].u32[0]);
	// 0x26A4A8: ret
	return;
}

void sub_26A4B0(X86Context& ctx, uint8_t* base) {
	// 0x26A4B0: movss xmm0, dword ptr [0x00557850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557850u);
	// 0x26A4B8: subss xmm0, [0x00559284]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x559284u);
	// 0x26A4C0: movss [0x0055785C], xmm0
	X86_MEM_WRITE_u32(base, 0x55785Cu, ctx.xmm[0].u32[0]);
	// 0x26A4C8: ret
	return;
}

void sub_26A4D0(X86Context& ctx, uint8_t* base) {
	// 0x26A4D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26A4D8: movss [0x005592B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5592B0u, ctx.xmm[0].u32[0]);
	// 0x26A4E0: ret
	return;
}

void sub_26A4F0(X86Context& ctx, uint8_t* base) {
	// 0x26A4F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26A4F8: movss [0x00557858], xmm0
	X86_MEM_WRITE_u32(base, 0x557858u, ctx.xmm[0].u32[0]);
	// 0x26A500: ret
	return;
}

void sub_26A510(X86Context& ctx, uint8_t* base) {
	// 0x26A510: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26A518: movss [0x00557870], xmm0
	X86_MEM_WRITE_u32(base, 0x557870u, ctx.xmm[0].u32[0]);
	// 0x26A520: ret
	return;
}

void sub_26A530(X86Context& ctx, uint8_t* base) {
	// 0x26A530: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26A538: movss [0x005592C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5592C8u, ctx.xmm[0].u32[0]);
	// 0x26A540: ret
	return;
}

void sub_26A550(X86Context& ctx, uint8_t* base) {
	// 0x26A550: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26A558: movss [0x005592AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5592ACu, ctx.xmm[0].u32[0]);
	// 0x26A560: ret
	return;
}

void sub_26A570(X86Context& ctx, uint8_t* base) {
	// 0x26A570: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26A578: movss [0x0055784C], xmm0
	X86_MEM_WRITE_u32(base, 0x55784Cu, ctx.xmm[0].u32[0]);
	// 0x26A580: ret
	return;
}

void sub_26A590(X86Context& ctx, uint8_t* base) {
	// 0x26A590: movss xmm0, dword ptr [0x00557870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557870u);
	// 0x26A598: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26A5A0: movss [0x00557840], xmm0
	X86_MEM_WRITE_u32(base, 0x557840u, ctx.xmm[0].u32[0]);
	// 0x26A5A8: ret
	return;
}

void sub_26A5B0(X86Context& ctx, uint8_t* base) {
	// 0x26A5B0: movss xmm0, dword ptr [0x005592C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592C8u);
	// 0x26A5B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26A5C0: movss [0x00559290], xmm0
	X86_MEM_WRITE_u32(base, 0x559290u, ctx.xmm[0].u32[0]);
	// 0x26A5C8: ret
	return;
}

void sub_26A5D0(X86Context& ctx, uint8_t* base) {
	// 0x26A5D0: movss xmm0, dword ptr [0x00557840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557840u);
	// 0x26A5D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26A5E0: movss [0x005592A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5592A4u, ctx.xmm[0].u32[0]);
	// 0x26A5E8: ret
	return;
}

void sub_26A5F0(X86Context& ctx, uint8_t* base) {
	// 0x26A5F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26A5F8: movss [0x00557834], xmm0
	X86_MEM_WRITE_u32(base, 0x557834u, ctx.xmm[0].u32[0]);
	// 0x26A600: ret
	return;
}

void sub_26A610(X86Context& ctx, uint8_t* base) {
	// 0x26A610: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26A618: movss [0x00557874], xmm0
	X86_MEM_WRITE_u32(base, 0x557874u, ctx.xmm[0].u32[0]);
	// 0x26A620: ret
	return;
}

void sub_26A630(X86Context& ctx, uint8_t* base) {
	// 0x26A630: movss xmm0, dword ptr [0x00557870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557870u);
	// 0x26A638: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26A640: movss [0x00559280], xmm0
	X86_MEM_WRITE_u32(base, 0x559280u, ctx.xmm[0].u32[0]);
	// 0x26A648: ret
	return;
}

void sub_26A650(X86Context& ctx, uint8_t* base) {
	// 0x26A650: movss xmm0, dword ptr [0x005592C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592C8u);
	// 0x26A658: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26A660: movss [0x005592CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5592CCu, ctx.xmm[0].u32[0]);
	// 0x26A668: ret
	return;
}

void sub_26A670(X86Context& ctx, uint8_t* base) {
	// 0x26A670: movss xmm0, dword ptr [0x00559280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559280u);
	// 0x26A678: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26A680: movss [0x005592B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5592B8u, ctx.xmm[0].u32[0]);
	// 0x26A688: ret
	return;
}

void sub_26A690(X86Context& ctx, uint8_t* base) {
	// 0x26A690: movss xmm0, dword ptr [0x005592CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592CCu);
	// 0x26A698: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26A6A0: movss [0x005592DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5592DCu, ctx.xmm[0].u32[0]);
	// 0x26A6A8: ret
	return;
}

void sub_26A6B0(X86Context& ctx, uint8_t* base) {
	// 0x26A6B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26A6B8: movss [0x00557844], xmm0
	X86_MEM_WRITE_u32(base, 0x557844u, ctx.xmm[0].u32[0]);
	// 0x26A6C0: ret
	return;
}

void sub_26A6D0(X86Context& ctx, uint8_t* base) {
	// 0x26A6D0: movss xmm0, dword ptr [0x00557870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557870u);
	// 0x26A6D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26A6E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26A6E8: movss [0x005592C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5592C4u, ctx.xmm[0].u32[0]);
	// 0x26A6F0: ret
	return;
}

void sub_26A700(X86Context& ctx, uint8_t* base) {
	// 0x26A700: movss xmm0, dword ptr [0x005592C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592C8u);
	// 0x26A708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26A710: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26A718: movss [0x00557860], xmm0
	X86_MEM_WRITE_u32(base, 0x557860u, ctx.xmm[0].u32[0]);
	// 0x26A720: ret
	return;
}

void sub_26A730(X86Context& ctx, uint8_t* base) {
	// 0x26A730: movss xmm0, dword ptr [0x00557870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557870u);
	// 0x26A738: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26A740: movss [0x00557864], xmm0
	X86_MEM_WRITE_u32(base, 0x557864u, ctx.xmm[0].u32[0]);
	// 0x26A748: ret
	return;
}

void sub_26A750(X86Context& ctx, uint8_t* base) {
	// 0x26A750: movss xmm0, dword ptr [0x005592C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592C8u);
	// 0x26A758: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26A760: movss [0x005592D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5592D0u, ctx.xmm[0].u32[0]);
	// 0x26A768: ret
	return;
}

void sub_26A770(X86Context& ctx, uint8_t* base) {
	// 0x26A770: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26A778: movss [0x00557848], xmm0
	X86_MEM_WRITE_u32(base, 0x557848u, ctx.xmm[0].u32[0]);
	// 0x26A780: ret
	return;
}

void sub_26A790(X86Context& ctx, uint8_t* base) {
	// 0x26A790: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26A798: movss [0x0055787C], xmm0
	X86_MEM_WRITE_u32(base, 0x55787Cu, ctx.xmm[0].u32[0]);
	// 0x26A7A0: ret
	return;
}

void sub_26A7B0(X86Context& ctx, uint8_t* base) {
	// 0x26A7B0: movss xmm0, dword ptr [0x00557848]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x557848u);
	// 0x26A7B8: movss [0x005592E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5592E4u, ctx.xmm[0].u32[0]);
	// 0x26A7C0: ret
	return;
}

void sub_26A7D0(X86Context& ctx, uint8_t* base) {
	// 0x26A7D0: movss xmm0, dword ptr [0x005592C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592C8u);
	// 0x26A7D8: subss xmm0, [0x00557848]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x557848u);
	// 0x26A7E0: movss [0x005592A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5592A8u, ctx.xmm[0].u32[0]);
	// 0x26A7E8: ret
	return;
}

void sub_26A7F0(X86Context& ctx, uint8_t* base) {
	// 0x26A7F0: movss xmm0, dword ptr [0x005592A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592A8u);
	// 0x26A7F8: subss xmm0, [0x0055787C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x55787Cu);
	// 0x26A800: movss [0x005592A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5592A0u, ctx.xmm[0].u32[0]);
	// 0x26A808: ret
	return;
}

void sub_26A810(X86Context& ctx, uint8_t* base) {
	// 0x26A810: movss xmm0, dword ptr [0x005592D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592D0u);
	// 0x26A818: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26A820: movss [0x0055928C], xmm0
	X86_MEM_WRITE_u32(base, 0x55928Cu, ctx.xmm[0].u32[0]);
	// 0x26A828: ret
	return;
}

void sub_26A830(X86Context& ctx, uint8_t* base) {
	// 0x26A830: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26A838: movss [0x00557878], xmm0
	X86_MEM_WRITE_u32(base, 0x557878u, ctx.xmm[0].u32[0]);
	// 0x26A840: ret
	return;
}

void sub_26A850(X86Context& ctx, uint8_t* base) {
	// 0x26A850: movss xmm0, dword ptr [0x0055928C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55928Cu);
	// 0x26A858: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26A860: movss [0x005592C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5592C0u, ctx.xmm[0].u32[0]);
	// 0x26A868: ret
	return;
}

void sub_26A870(X86Context& ctx, uint8_t* base) {
	// 0x26A870: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26A878: movss [0x00559294], xmm0
	X86_MEM_WRITE_u32(base, 0x559294u, ctx.xmm[0].u32[0]);
	// 0x26A880: ret
	return;
}

void sub_26A890(X86Context& ctx, uint8_t* base) {
	// 0x26A890: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26A898: movss [0x0055786C], xmm0
	X86_MEM_WRITE_u32(base, 0x55786Cu, ctx.xmm[0].u32[0]);
	// 0x26A8A0: ret
	return;
}

void sub_26A8B0(X86Context& ctx, uint8_t* base) {
	// 0x26A8B0: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x26A8B8: movss [0x00557838], xmm0
	X86_MEM_WRITE_u32(base, 0x557838u, ctx.xmm[0].u32[0]);
	// 0x26A8C0: ret
	return;
}

void sub_26A8D0(X86Context& ctx, uint8_t* base) {
	// 0x26A8D0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x26A8D8: divss xmm0, [0x00557838]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x557838u);
	// 0x26A8E0: movss [0x00557868], xmm0
	X86_MEM_WRITE_u32(base, 0x557868u, ctx.xmm[0].u32[0]);
	// 0x26A8E8: ret
	return;
}

void sub_26A8F0(X86Context& ctx, uint8_t* base) {
	// 0x26A8F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26A8F8: movss [0x00557854], xmm0
	X86_MEM_WRITE_u32(base, 0x557854u, ctx.xmm[0].u32[0]);
	// 0x26A900: ret
	return;
}

void sub_26A910(X86Context& ctx, uint8_t* base) {
	// 0x26A910: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26A918: movss [0x0055934C], xmm0
	X86_MEM_WRITE_u32(base, 0x55934Cu, ctx.xmm[0].u32[0]);
	// 0x26A920: ret
	return;
}

void sub_26A930(X86Context& ctx, uint8_t* base) {
	// 0x26A930: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26A938: movss [0x00559368], xmm0
	X86_MEM_WRITE_u32(base, 0x559368u, ctx.xmm[0].u32[0]);
	// 0x26A940: ret
	return;
}

void sub_26A950(X86Context& ctx, uint8_t* base) {
	// 0x26A950: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26A958: movss [0x0055933C], xmm0
	X86_MEM_WRITE_u32(base, 0x55933Cu, ctx.xmm[0].u32[0]);
	// 0x26A960: ret
	return;
}

void sub_26A970(X86Context& ctx, uint8_t* base) {
	// 0x26A970: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26A978: movss [0x005592F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5592F0u, ctx.xmm[0].u32[0]);
	// 0x26A980: ret
	return;
}

void sub_26A990(X86Context& ctx, uint8_t* base) {
	// 0x26A990: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26A998: movss [0x00559350], xmm0
	X86_MEM_WRITE_u32(base, 0x559350u, ctx.xmm[0].u32[0]);
	// 0x26A9A0: ret
	return;
}

void sub_26A9B0(X86Context& ctx, uint8_t* base) {
	// 0x26A9B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26A9B8: movss [0x0055930C], xmm0
	X86_MEM_WRITE_u32(base, 0x55930Cu, ctx.xmm[0].u32[0]);
	// 0x26A9C0: ret
	return;
}

void sub_26A9D0(X86Context& ctx, uint8_t* base) {
	// 0x26A9D0: movss xmm0, dword ptr [0x00559350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559350u);
	// 0x26A9D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26A9E0: movss [0x00559388], xmm0
	X86_MEM_WRITE_u32(base, 0x559388u, ctx.xmm[0].u32[0]);
	// 0x26A9E8: ret
	return;
}

void sub_26A9F0(X86Context& ctx, uint8_t* base) {
	// 0x26A9F0: movss xmm0, dword ptr [0x0055930C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55930Cu);
	// 0x26A9F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26AA00: movss [0x00559370], xmm0
	X86_MEM_WRITE_u32(base, 0x559370u, ctx.xmm[0].u32[0]);
	// 0x26AA08: ret
	return;
}

void sub_26AA10(X86Context& ctx, uint8_t* base) {
	// 0x26AA10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26AA18: movss [0x00567114], xmm0
	X86_MEM_WRITE_u32(base, 0x567114u, ctx.xmm[0].u32[0]);
	// 0x26AA20: ret
	return;
}

void sub_26AA30(X86Context& ctx, uint8_t* base) {
	// 0x26AA30: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26AA38: movss [0x00567100], xmm0
	X86_MEM_WRITE_u32(base, 0x567100u, ctx.xmm[0].u32[0]);
	// 0x26AA40: ret
	return;
}

void sub_26AA50(X86Context& ctx, uint8_t* base) {
	// 0x26AA50: movss xmm0, dword ptr [0x00567100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567100u);
	// 0x26AA58: movss [0x00567110], xmm0
	X86_MEM_WRITE_u32(base, 0x567110u, ctx.xmm[0].u32[0]);
	// 0x26AA60: ret
	return;
}

void sub_26AA70(X86Context& ctx, uint8_t* base) {
	// 0x26AA70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26AA78: movss [0x005592F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5592F8u, ctx.xmm[0].u32[0]);
	// 0x26AA80: ret
	return;
}

void sub_26AA90(X86Context& ctx, uint8_t* base) {
	// 0x26AA90: movss xmm0, dword ptr [0x0055930C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55930Cu);
	// 0x26AA98: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26AAA0: movss [0x00567108], xmm0
	X86_MEM_WRITE_u32(base, 0x567108u, ctx.xmm[0].u32[0]);
	// 0x26AAA8: ret
	return;
}

void sub_26AAB0(X86Context& ctx, uint8_t* base) {
	// 0x26AAB0: movss xmm0, dword ptr [0x0055930C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55930Cu);
	// 0x26AAB8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26AAC0: movss [0x00559338], xmm0
	X86_MEM_WRITE_u32(base, 0x559338u, ctx.xmm[0].u32[0]);
	// 0x26AAC8: ret
	return;
}

void sub_26AAD0(X86Context& ctx, uint8_t* base) {
	// 0x26AAD0: movss xmm0, dword ptr [0x0055930C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55930Cu);
	// 0x26AAD8: subss xmm0, [0x00559338]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x559338u);
	// 0x26AAE0: movss [0x00559314], xmm0
	X86_MEM_WRITE_u32(base, 0x559314u, ctx.xmm[0].u32[0]);
	// 0x26AAE8: ret
	return;
}

void sub_26AAF0(X86Context& ctx, uint8_t* base) {
	// 0x26AAF0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26AAF8: movss [0x00559364], xmm0
	X86_MEM_WRITE_u32(base, 0x559364u, ctx.xmm[0].u32[0]);
	// 0x26AB00: ret
	return;
}

void sub_26AB10(X86Context& ctx, uint8_t* base) {
	// 0x26AB10: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26AB18: movss [0x00559310], xmm0
	X86_MEM_WRITE_u32(base, 0x559310u, ctx.xmm[0].u32[0]);
	// 0x26AB20: ret
	return;
}

void sub_26AB30(X86Context& ctx, uint8_t* base) {
	// 0x26AB30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26AB38: movss [0x00559324], xmm0
	X86_MEM_WRITE_u32(base, 0x559324u, ctx.xmm[0].u32[0]);
	// 0x26AB40: ret
	return;
}

void sub_26AB50(X86Context& ctx, uint8_t* base) {
	// 0x26AB50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26AB58: movss [0x0055937C], xmm0
	X86_MEM_WRITE_u32(base, 0x55937Cu, ctx.xmm[0].u32[0]);
	// 0x26AB60: ret
	return;
}

void sub_26AB70(X86Context& ctx, uint8_t* base) {
	// 0x26AB70: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26AB78: movss [0x00559360], xmm0
	X86_MEM_WRITE_u32(base, 0x559360u, ctx.xmm[0].u32[0]);
	// 0x26AB80: ret
	return;
}

void sub_26AB90(X86Context& ctx, uint8_t* base) {
	// 0x26AB90: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26AB98: movss [0x00559308], xmm0
	X86_MEM_WRITE_u32(base, 0x559308u, ctx.xmm[0].u32[0]);
	// 0x26ABA0: ret
	return;
}

void sub_26ABB0(X86Context& ctx, uint8_t* base) {
	// 0x26ABB0: movss xmm0, dword ptr [0x00559324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559324u);
	// 0x26ABB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26ABC0: movss [0x005592FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5592FCu, ctx.xmm[0].u32[0]);
	// 0x26ABC8: ret
	return;
}

void sub_26ABD0(X86Context& ctx, uint8_t* base) {
	// 0x26ABD0: movss xmm0, dword ptr [0x0055937C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55937Cu);
	// 0x26ABD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26ABE0: movss [0x00559344], xmm0
	X86_MEM_WRITE_u32(base, 0x559344u, ctx.xmm[0].u32[0]);
	// 0x26ABE8: ret
	return;
}

void sub_26ABF0(X86Context& ctx, uint8_t* base) {
	// 0x26ABF0: movss xmm0, dword ptr [0x005592FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5592FCu);
	// 0x26ABF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26AC00: movss [0x00559358], xmm0
	X86_MEM_WRITE_u32(base, 0x559358u, ctx.xmm[0].u32[0]);
	// 0x26AC08: ret
	return;
}

void sub_26AC10(X86Context& ctx, uint8_t* base) {
	// 0x26AC10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26AC18: movss [0x005592F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5592F4u, ctx.xmm[0].u32[0]);
	// 0x26AC20: ret
	return;
}

void sub_26AC30(X86Context& ctx, uint8_t* base) {
	// 0x26AC30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26AC38: movss [0x00559328], xmm0
	X86_MEM_WRITE_u32(base, 0x559328u, ctx.xmm[0].u32[0]);
	// 0x26AC40: ret
	return;
}

void sub_26AC50(X86Context& ctx, uint8_t* base) {
	// 0x26AC50: movss xmm0, dword ptr [0x00559324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559324u);
	// 0x26AC58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26AC60: movss [0x00559334], xmm0
	X86_MEM_WRITE_u32(base, 0x559334u, ctx.xmm[0].u32[0]);
	// 0x26AC68: ret
	return;
}

void sub_26AC70(X86Context& ctx, uint8_t* base) {
	// 0x26AC70: movss xmm0, dword ptr [0x0055937C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55937Cu);
	// 0x26AC78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26AC80: movss [0x00559380], xmm0
	X86_MEM_WRITE_u32(base, 0x559380u, ctx.xmm[0].u32[0]);
	// 0x26AC88: ret
	return;
}

void sub_26AC90(X86Context& ctx, uint8_t* base) {
	// 0x26AC90: movss xmm0, dword ptr [0x00559334]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559334u);
	// 0x26AC98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26ACA0: movss [0x0055936C], xmm0
	X86_MEM_WRITE_u32(base, 0x55936Cu, ctx.xmm[0].u32[0]);
	// 0x26ACA8: ret
	return;
}

void sub_26ACB0(X86Context& ctx, uint8_t* base) {
	// 0x26ACB0: movss xmm0, dword ptr [0x00559380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559380u);
	// 0x26ACB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26ACC0: movss [0x00567104], xmm0
	X86_MEM_WRITE_u32(base, 0x567104u, ctx.xmm[0].u32[0]);
	// 0x26ACC8: ret
	return;
}

void sub_26ACD0(X86Context& ctx, uint8_t* base) {
	// 0x26ACD0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26ACD8: movss [0x00559300], xmm0
	X86_MEM_WRITE_u32(base, 0x559300u, ctx.xmm[0].u32[0]);
	// 0x26ACE0: ret
	return;
}

void sub_26ACF0(X86Context& ctx, uint8_t* base) {
	// 0x26ACF0: movss xmm0, dword ptr [0x00559324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559324u);
	// 0x26ACF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26AD00: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26AD08: movss [0x00559378], xmm0
	X86_MEM_WRITE_u32(base, 0x559378u, ctx.xmm[0].u32[0]);
	// 0x26AD10: ret
	return;
}

void sub_26AD20(X86Context& ctx, uint8_t* base) {
	// 0x26AD20: movss xmm0, dword ptr [0x0055937C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55937Cu);
	// 0x26AD28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26AD30: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26AD38: movss [0x00559318], xmm0
	X86_MEM_WRITE_u32(base, 0x559318u, ctx.xmm[0].u32[0]);
	// 0x26AD40: ret
	return;
}

void sub_26AD50(X86Context& ctx, uint8_t* base) {
	// 0x26AD50: movss xmm0, dword ptr [0x00559324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559324u);
	// 0x26AD58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26AD60: movss [0x0055931C], xmm0
	X86_MEM_WRITE_u32(base, 0x55931Cu, ctx.xmm[0].u32[0]);
	// 0x26AD68: ret
	return;
}

void sub_26AD70(X86Context& ctx, uint8_t* base) {
	// 0x26AD70: movss xmm0, dword ptr [0x0055937C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55937Cu);
	// 0x26AD78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26AD80: movss [0x00559384], xmm0
	X86_MEM_WRITE_u32(base, 0x559384u, ctx.xmm[0].u32[0]);
	// 0x26AD88: ret
	return;
}

void sub_26AD90(X86Context& ctx, uint8_t* base) {
	// 0x26AD90: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26AD98: movss [0x00559304], xmm0
	X86_MEM_WRITE_u32(base, 0x559304u, ctx.xmm[0].u32[0]);
	// 0x26ADA0: ret
	return;
}

void sub_26ADB0(X86Context& ctx, uint8_t* base) {
	// 0x26ADB0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26ADB8: movss [0x00559330], xmm0
	X86_MEM_WRITE_u32(base, 0x559330u, ctx.xmm[0].u32[0]);
	// 0x26ADC0: ret
	return;
}

void sub_26ADD0(X86Context& ctx, uint8_t* base) {
	// 0x26ADD0: movss xmm0, dword ptr [0x00559304]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559304u);
	// 0x26ADD8: movss [0x0056710C], xmm0
	X86_MEM_WRITE_u32(base, 0x56710Cu, ctx.xmm[0].u32[0]);
	// 0x26ADE0: ret
	return;
}

void sub_26ADF0(X86Context& ctx, uint8_t* base) {
	// 0x26ADF0: movss xmm0, dword ptr [0x0055937C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55937Cu);
	// 0x26ADF8: subss xmm0, [0x00559304]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x559304u);
	// 0x26AE00: movss [0x0055935C], xmm0
	X86_MEM_WRITE_u32(base, 0x55935Cu, ctx.xmm[0].u32[0]);
	// 0x26AE08: ret
	return;
}

void sub_26AE10(X86Context& ctx, uint8_t* base) {
	// 0x26AE10: movss xmm0, dword ptr [0x0055935C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x55935Cu);
	// 0x26AE18: subss xmm0, [0x00559330]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x559330u);
	// 0x26AE20: movss [0x00559354], xmm0
	X86_MEM_WRITE_u32(base, 0x559354u, ctx.xmm[0].u32[0]);
	// 0x26AE28: ret
	return;
}

void sub_26AE30(X86Context& ctx, uint8_t* base) {
	// 0x26AE30: movss xmm0, dword ptr [0x00559384]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559384u);
	// 0x26AE38: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26AE40: movss [0x00559340], xmm0
	X86_MEM_WRITE_u32(base, 0x559340u, ctx.xmm[0].u32[0]);
	// 0x26AE48: ret
	return;
}

void sub_26AE50(X86Context& ctx, uint8_t* base) {
	// 0x26AE50: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26AE58: movss [0x0055932C], xmm0
	X86_MEM_WRITE_u32(base, 0x55932Cu, ctx.xmm[0].u32[0]);
	// 0x26AE60: ret
	return;
}

void sub_26AE70(X86Context& ctx, uint8_t* base) {
	// 0x26AE70: movss xmm0, dword ptr [0x00559340]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x559340u);
	// 0x26AE78: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26AE80: movss [0x00559374], xmm0
	X86_MEM_WRITE_u32(base, 0x559374u, ctx.xmm[0].u32[0]);
	// 0x26AE88: ret
	return;
}

void sub_26AE90(X86Context& ctx, uint8_t* base) {
	// 0x26AE90: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26AE98: movss [0x00559348], xmm0
	X86_MEM_WRITE_u32(base, 0x559348u, ctx.xmm[0].u32[0]);
	// 0x26AEA0: ret
	return;
}

void sub_26AEB0(X86Context& ctx, uint8_t* base) {
	// 0x26AEB0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26AEB8: movss [0x00559320], xmm0
	X86_MEM_WRITE_u32(base, 0x559320u, ctx.xmm[0].u32[0]);
	// 0x26AEC0: ret
	return;
}

void sub_26AED0(X86Context& ctx, uint8_t* base) {
	// 0x26AED0: mov eax, 0x559390
	ctx.eax = 5608336;
	// 0x26AED5: jmp 0x00063B80
	goto loc_63B80;
	// ---- chunk at 0x63B80 (size 0x3C2) ----
loc_63B80:
	// 0x63B80: mov dword ptr [eax], 0x3ABFEC
	X86_MEM_WRITE_u32(base, ctx.eax, 3850220);
	// 0x63B86: mov dword ptr [eax+0x54], 0x3ABEEC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, 3849964);
	// 0x63B8D: mov dword ptr [eax+0xC0], 0x3ABF74
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC0u, 3850100);
	// 0x63B97: mov dword ptr [eax+0xC4], 0x3ABF24
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC4u, 3850020);
	// 0x63BA1: mov ecx, 0x3AC074
	ctx.ecx = 3850356;
	// 0x63BA6: mov [eax+0xD4], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD4u, ctx.ecx);
	// 0x63BAC: mov [eax+0xEC], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xECu, ctx.ecx);
	// 0x63BB2: mov [eax+0x104], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x104u, ctx.ecx);
	// 0x63BB8: mov [eax+0x11C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x11Cu, ctx.ecx);
	// 0x63BBE: mov dword ptr [eax+0x134], 0x3ABF64
	X86_MEM_WRITE_u32(base, ctx.eax + 0x134u, 3850084);
	// 0x63BC8: mov ecx, 0x3AC01C
	ctx.ecx = 3850268;
	// 0x63BCD: mov [eax+0x14C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14Cu, ctx.ecx);
	// 0x63BD3: mov [eax+0x158], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x158u, ctx.ecx);
	// 0x63BD9: mov [eax+0x164], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x164u, ctx.ecx);
	// 0x63BDF: mov [eax+0x170], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x170u, ctx.ecx);
	// 0x63BE5: mov dword ptr [eax+0x214], 0x3ABE1C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x214u, 3849756);
	// 0x63BEF: mov dword ptr [eax+0x2B8], 0x3AC044
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2B8u, 3850308);
	// 0x63BF9: mov dword ptr [eax+0x2F0], 0x3ABEE4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2F0u, 3849956);
	// 0x63C03: mov dword ptr [eax+0xB40], 0x3AC0E0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xB40u, 3850464);
	// 0x63C0D: mov dword ptr [eax+0xBFC], 0x3AC014
	X86_MEM_WRITE_u32(base, ctx.eax + 0xBFCu, 3850260);
	// 0x63C17: mov dword ptr [eax+0xC0C], 0x3AC054
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC0Cu, 3850324);
	// 0x63C21: mov dword ptr [eax+0xC14], 0x3AC00C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC14u, 3850252);
	// 0x63C2B: mov dword ptr [eax+0xC18], 0x3ABEA4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC18u, 3849892);
	// 0x63C35: mov dword ptr [eax+0xC58], 0x3ABFC4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC58u, 3850180);
	// 0x63C3F: mov dword ptr [eax+0xCA0], 0x3ABF04
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCA0u, 3849988);
	// 0x63C49: mov dword ptr [eax+0xCE0], 0x3AC0D8
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCE0u, 3850456);
	// 0x63C53: mov dword ptr [eax+0xD10], 0x3ABE6C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD10u, 3849836);
	// 0x63C5D: mov dword ptr [eax+0xD1C], 0x3ABE0C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD1Cu, 3849740);
	// 0x63C67: mov dword ptr [eax+0xD28], 0x3ABE3C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD28u, 3849788);
	// 0x63C71: mov dword ptr [eax+0xD78], 0x3ABEDC
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD78u, 3849948);
	// 0x63C7B: mov dword ptr [eax+0xD88], 0x3AC064
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD88u, 3850340);
	// 0x63C85: mov dword ptr [eax+0xD90], 0x3AC0A4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD90u, 3850404);
	// 0x63C8F: mov dword ptr [eax+0xF0C], 0x3ABDE4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xF0Cu, 3849700);
	// 0x63C99: mov dword ptr [eax+0xF14], 0x3ABFBC
	X86_MEM_WRITE_u32(base, ctx.eax + 0xF14u, 3850172);
	// 0x63CA3: mov dword ptr [eax+0xF98], 0x3ABEC4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xF98u, 3849924);
	// 0x63CAD: mov dword ptr [eax+0xFF0], 0x3ABE24
	X86_MEM_WRITE_u32(base, ctx.eax + 0xFF0u, 3849764);
	// 0x63CB7: mov dword ptr [eax+0xFF8], 0x3ABFB4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xFF8u, 3850164);
	// 0x63CC1: mov dword ptr [eax+0x1004], 0x3ABF44
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1004u, 3850052);
	// 0x63CCB: mov dword ptr [eax+0x1030], 0x3ABE9C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1030u, 3849884);
	// 0x63CD5: mov dword ptr [eax+0x1068], 0x3AC004
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1068u, 3850244);
	// 0x63CDF: mov dword ptr [eax+0x1078], 0x3ABF5C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1078u, 3850076);
	// 0x63CE9: mov dword ptr [eax+0x1090], 0x3AC03C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1090u, 3850300);
	// 0x63CF3: mov dword ptr [eax+0x10A0], 0x3ABEB4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10A0u, 3849908);
	// 0x63CFD: mov dword ptr [eax+0x17D0], 0x3ABE5C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x17D0u, 3849820);
	// 0x63D07: mov dword ptr [eax+0x17D8], 0x3AC0B0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x17D8u, 3850416);
	// 0x63D11: mov dword ptr [eax+0x17E4], 0x3ABF54
	X86_MEM_WRITE_u32(base, ctx.eax + 0x17E4u, 3850068);
	// 0x63D1B: mov dword ptr [eax+0x180C], 0x3AC09C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x180Cu, 3850396);
	// 0x63D25: mov dword ptr [eax+0x1810], 0x3ABEF4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1810u, 3849972);
	// 0x63D2F: mov dword ptr [eax+0x1834], 0x3AC0C8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1834u, 3850440);
	// 0x63D39: mov dword ptr [eax+0x185C], 0x3ABFD4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x185Cu, 3850196);
	// 0x63D43: mov dword ptr [eax+0x18B4], 0x3AC04C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x18B4u, 3850316);
	// 0x63D4D: mov dword ptr [eax+0x18F0], 0x3ABED4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x18F0u, 3849940);
	// 0x63D57: mov dword ptr [eax+0x22C0], 0x3AC0D0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x22C0u, 3850448);
	// 0x63D61: mov dword ptr [eax+0x2320], 0x3AC05C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2320u, 3850332);
	// 0x63D6B: mov dword ptr [eax+0x2324], 0x3ABFE4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2324u, 3850212);
	// 0x63D75: mov dword ptr [eax+0x2340], 0x3ABF1C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2340u, 3850012);
	// 0x63D7F: mov dword ptr [eax+0x2A08], 0x3AC0F8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2A08u, 3850488);
	// 0x63D89: mov dword ptr [eax+0x30D0], 0x3ABE2C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30D0u, 3849772);
	// 0x63D93: mov dword ptr [eax+0x3174], 0x3ABE4C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3174u, 3849804);
	// 0x63D9D: mov dword ptr [eax+0x3184], 0x3AC0E8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3184u, 3850472);
	// 0x63DA7: mov dword ptr [eax+0x3194], 0x3ABFDC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3194u, 3850204);
	// 0x63DB1: mov dword ptr [eax+0x31E4], 0x3ABF14
	X86_MEM_WRITE_u32(base, ctx.eax + 0x31E4u, 3850004);
	// 0x63DBB: mov dword ptr [eax+0x3200], 0x3AC034
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3200u, 3850292);
	// 0x63DC5: mov dword ptr [eax+0x3294], 0x3ABF7C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3294u, 3850108);
	// 0x63DCF: mov dword ptr [eax+0x3304], 0x3ABEBC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3304u, 3849916);
	// 0x63DD9: mov dword ptr [eax+0x37D0], 0x3ABFF4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x37D0u, 3850228);
	// 0x63DE3: mov dword ptr [eax+0x37E0], 0x3ABF4C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x37E0u, 3850060);
	// 0x63DED: mov dword ptr [eax+0x37E4], 0x3ABEFC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x37E4u, 3849980);
	// 0x63DF7: mov dword ptr [eax+0x37F4], 0x3ABE94
	X86_MEM_WRITE_u32(base, ctx.eax + 0x37F4u, 3849876);
	// 0x63E01: mov dword ptr [eax+0x37F8], 0x3AC06C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x37F8u, 3850348);
	// 0x63E0B: mov dword ptr [eax+0x3810], 0x3ABF34
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3810u, 3850036);
	// 0x63E15: mov dword ptr [eax+0x4BC0], 0x3ABDFC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4BC0u, 3849724);
	// 0x63E1F: mov dword ptr [eax+0x4BFC], 0x3ABE54
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4BFCu, 3849812);
	// 0x63E29: mov dword ptr [eax+0x4CEC], 0x3ABE8C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4CECu, 3849868);
	// 0x63E33: mov dword ptr [eax+0x4D20], 0x3ABE7C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4D20u, 3849852);
	// 0x63E3D: mov dword ptr [eax+0x6840], 0x3ABE44
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6840u, 3849796);
	// 0x63E47: mov dword ptr [eax+0x684C], 0x3ABE34
	X86_MEM_WRITE_u32(base, ctx.eax + 0x684Cu, 3849780);
	// 0x63E51: mov dword ptr [eax+0x6BE0], 0x3ABE04
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6BE0u, 3849732);
	// 0x63E5B: mov dword ptr [eax+0x6C3C], 0x3AC0C0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6C3Cu, 3850432);
	// 0x63E65: mov dword ptr [eax+0x6C5C], 0x3ABF94
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6C5Cu, 3850132);
	// 0x63E6F: mov dword ptr [eax+0x6DBC], 0x3ABDEC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6DBCu, 3849708);
	// 0x63E79: mov dword ptr [eax+0x6DF4], 0x3ABE14
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6DF4u, 3849748);
	// 0x63E83: mov dword ptr [eax+0x6E20], 0x3AC084
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6E20u, 3850372);
	// 0x63E8D: mov dword ptr [eax+0x6E40], 0x3ABF9C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6E40u, 3850140);
	// 0x63E97: mov dword ptr [eax+0x7D70], 0x3AC08C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x7D70u, 3850380);
	// 0x63EA1: mov dword ptr [eax+0x9500], 0x3AC084
	X86_MEM_WRITE_u32(base, ctx.eax + 0x9500u, 3850372);
	// 0x63EAB: mov dword ptr [eax+0x9518], 0x3ABFA4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x9518u, 3850148);
	// 0x63EB5: mov dword ptr [eax+0x9550], 0x3ABE74
	X86_MEM_WRITE_u32(base, ctx.eax + 0x9550u, 3849844);
	// 0x63EBF: mov dword ptr [eax+0xAEA0], 0x3AC0B8
	X86_MEM_WRITE_u32(base, ctx.eax + 0xAEA0u, 3850424);
	// 0x63EC9: mov dword ptr [eax+0xAEF4], 0x3AC02C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xAEF4u, 3850284);
	// 0x63ED3: mov dword ptr [eax+0xAFC0], 0x3ABF3C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xAFC0u, 3850044);
	// 0x63EDD: mov dword ptr [eax+0xB0A8], 0x3ABFAC
	X86_MEM_WRITE_u32(base, ctx.eax + 0xB0A8u, 3850156);
	// 0x63EE7: mov dword ptr [eax+0xB100], 0x3ABDF4
	X86_MEM_WRITE_u32(base, ctx.eax + 0xB100u, 3849716);
	// 0x63EF1: mov dword ptr [eax+0xB570], 0x3ABECC
	X86_MEM_WRITE_u32(base, ctx.eax + 0xB570u, 3849932);
	// 0x63EFB: mov dword ptr [eax+0xBC78], 0x3ABFFC
	X86_MEM_WRITE_u32(base, ctx.eax + 0xBC78u, 3850236);
	// 0x63F05: mov dword ptr [eax+0xBC7C], 0x3ABFFC
	X86_MEM_WRITE_u32(base, ctx.eax + 0xBC7Cu, 3850236);
	// 0x63F0F: mov dword ptr [eax+0xBC80], 0x3ABF84
	X86_MEM_WRITE_u32(base, ctx.eax + 0xBC80u, 3850116);
	// 0x63F19: mov dword ptr [eax+0xBCD0], 0x3ABE64
	X86_MEM_WRITE_u32(base, ctx.eax + 0xBCD0u, 3849828);
	// 0x63F23: mov dword ptr [eax+0xBDA0], 0x3AC094
	X86_MEM_WRITE_u32(base, ctx.eax + 0xBDA0u, 3850388);
	// 0x63F2D: mov dword ptr [eax+0xC9C0], 0x3ABE84
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC9C0u, 3849860);
	// 0x63F37: mov dword ptr [eax+0xD020], 0x3AC0F0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xD020u, 3850480);
	// 0x63F41: ret
	return;
}

void sub_26AEE0(X86Context& ctx, uint8_t* base) {
	// 0x26AEE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26AEE8: movss [0x00567134], xmm0
	X86_MEM_WRITE_u32(base, 0x567134u, ctx.xmm[0].u32[0]);
	// 0x26AEF0: ret
	return;
}

void sub_26AF00(X86Context& ctx, uint8_t* base) {
	// 0x26AF00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26AF08: movss [0x00567140], xmm0
	X86_MEM_WRITE_u32(base, 0x567140u, ctx.xmm[0].u32[0]);
	// 0x26AF10: ret
	return;
}

void sub_26AF20(X86Context& ctx, uint8_t* base) {
	// 0x26AF20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26AF28: movss [0x00567130], xmm0
	X86_MEM_WRITE_u32(base, 0x567130u, ctx.xmm[0].u32[0]);
	// 0x26AF30: ret
	return;
}

void sub_26AF40(X86Context& ctx, uint8_t* base) {
	// 0x26AF40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26AF48: movss [0x00567118], xmm0
	X86_MEM_WRITE_u32(base, 0x567118u, ctx.xmm[0].u32[0]);
	// 0x26AF50: ret
	return;
}

void sub_26AF60(X86Context& ctx, uint8_t* base) {
	// 0x26AF60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26AF68: movss [0x00567138], xmm0
	X86_MEM_WRITE_u32(base, 0x567138u, ctx.xmm[0].u32[0]);
	// 0x26AF70: ret
	return;
}

void sub_26AF80(X86Context& ctx, uint8_t* base) {
	// 0x26AF80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26AF88: movss [0x00567120], xmm0
	X86_MEM_WRITE_u32(base, 0x567120u, ctx.xmm[0].u32[0]);
	// 0x26AF90: ret
	return;
}

void sub_26AFA0(X86Context& ctx, uint8_t* base) {
	// 0x26AFA0: movss xmm0, dword ptr [0x00567138]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567138u);
	// 0x26AFA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26AFB0: movss [0x00567148], xmm0
	X86_MEM_WRITE_u32(base, 0x567148u, ctx.xmm[0].u32[0]);
	// 0x26AFB8: ret
	return;
}

void sub_26AFC0(X86Context& ctx, uint8_t* base) {
	// 0x26AFC0: movss xmm0, dword ptr [0x00567120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567120u);
	// 0x26AFC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26AFD0: movss [0x00567144], xmm0
	X86_MEM_WRITE_u32(base, 0x567144u, ctx.xmm[0].u32[0]);
	// 0x26AFD8: ret
	return;
}

void sub_26AFE0(X86Context& ctx, uint8_t* base) {
	// 0x26AFE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26AFE8: movss [0x00567158], xmm0
	X86_MEM_WRITE_u32(base, 0x567158u, ctx.xmm[0].u32[0]);
	// 0x26AFF0: ret
	return;
}

