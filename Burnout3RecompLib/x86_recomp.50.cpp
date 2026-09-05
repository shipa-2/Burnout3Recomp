#include "x86_recomp_shared.h"

void sub_2858C0(X86Context& ctx, uint8_t* base) {
	// 0x2858C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2858C8: movss [0x0056AE6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE6Cu, ctx.xmm[0].u32[0]);
	// 0x2858D0: ret
	return;
}

void sub_2858E0(X86Context& ctx, uint8_t* base) {
	// 0x2858E0: movss xmm0, dword ptr [0x0056AE68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE68u);
	// 0x2858E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2858F0: movss [0x0056AE78], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE78u, ctx.xmm[0].u32[0]);
	// 0x2858F8: ret
	return;
}

void sub_285900(X86Context& ctx, uint8_t* base) {
	// 0x285900: movss xmm0, dword ptr [0x0056AEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEBCu);
	// 0x285908: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x285910: movss [0x0056AEC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEC0u, ctx.xmm[0].u32[0]);
	// 0x285918: ret
	return;
}

void sub_285920(X86Context& ctx, uint8_t* base) {
	// 0x285920: movss xmm0, dword ptr [0x0056AE78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE78u);
	// 0x285928: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285930: movss [0x0056AEAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEACu, ctx.xmm[0].u32[0]);
	// 0x285938: ret
	return;
}

void sub_285940(X86Context& ctx, uint8_t* base) {
	// 0x285940: movss xmm0, dword ptr [0x0056AEC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEC0u);
	// 0x285948: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285950: movss [0x0056AED0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AED0u, ctx.xmm[0].u32[0]);
	// 0x285958: ret
	return;
}

void sub_285960(X86Context& ctx, uint8_t* base) {
	// 0x285960: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x285968: movss [0x0056AE48], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE48u, ctx.xmm[0].u32[0]);
	// 0x285970: ret
	return;
}

void sub_285980(X86Context& ctx, uint8_t* base) {
	// 0x285980: movss xmm0, dword ptr [0x0056AE68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE68u);
	// 0x285988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285990: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x285998: movss [0x0056AEB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEB8u, ctx.xmm[0].u32[0]);
	// 0x2859A0: ret
	return;
}

void sub_2859B0(X86Context& ctx, uint8_t* base) {
	// 0x2859B0: movss xmm0, dword ptr [0x0056AEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEBCu);
	// 0x2859B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2859C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2859C8: movss [0x0056AE60], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE60u, ctx.xmm[0].u32[0]);
	// 0x2859D0: ret
	return;
}

void sub_2859E0(X86Context& ctx, uint8_t* base) {
	// 0x2859E0: movss xmm0, dword ptr [0x0056AE68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE68u);
	// 0x2859E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2859F0: movss [0x0056AE64], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE64u, ctx.xmm[0].u32[0]);
	// 0x2859F8: ret
	return;
}

void sub_285A00(X86Context& ctx, uint8_t* base) {
	// 0x285A00: movss xmm0, dword ptr [0x0056AEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEBCu);
	// 0x285A08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285A10: movss [0x0056AEC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEC4u, ctx.xmm[0].u32[0]);
	// 0x285A18: ret
	return;
}

void sub_285A20(X86Context& ctx, uint8_t* base) {
	// 0x285A20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x285A28: movss [0x0056AE4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE4Cu, ctx.xmm[0].u32[0]);
	// 0x285A30: ret
	return;
}

void sub_285A40(X86Context& ctx, uint8_t* base) {
	// 0x285A40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x285A48: movss [0x0056AE74], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE74u, ctx.xmm[0].u32[0]);
	// 0x285A50: ret
	return;
}

void sub_285A60(X86Context& ctx, uint8_t* base) {
	// 0x285A60: movss xmm0, dword ptr [0x0056AE4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE4Cu);
	// 0x285A68: movss [0x0056AED8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AED8u, ctx.xmm[0].u32[0]);
	// 0x285A70: ret
	return;
}

void sub_285A80(X86Context& ctx, uint8_t* base) {
	// 0x285A80: movss xmm0, dword ptr [0x0056AEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEBCu);
	// 0x285A88: subss xmm0, [0x0056AE4C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AE4Cu);
	// 0x285A90: movss [0x0056AE9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE9Cu, ctx.xmm[0].u32[0]);
	// 0x285A98: ret
	return;
}

void sub_285AA0(X86Context& ctx, uint8_t* base) {
	// 0x285AA0: movss xmm0, dword ptr [0x0056AE9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE9Cu);
	// 0x285AA8: subss xmm0, [0x0056AE74]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AE74u);
	// 0x285AB0: movss [0x0056AE94], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE94u, ctx.xmm[0].u32[0]);
	// 0x285AB8: ret
	return;
}

void sub_285AC0(X86Context& ctx, uint8_t* base) {
	// 0x285AC0: movss xmm0, dword ptr [0x0056AEC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEC4u);
	// 0x285AC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x285AD0: movss [0x0056AE84], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE84u, ctx.xmm[0].u32[0]);
	// 0x285AD8: ret
	return;
}

void sub_285AE0(X86Context& ctx, uint8_t* base) {
	// 0x285AE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x285AE8: movss [0x0056AE70], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE70u, ctx.xmm[0].u32[0]);
	// 0x285AF0: ret
	return;
}

void sub_285B00(X86Context& ctx, uint8_t* base) {
	// 0x285B00: movss xmm0, dword ptr [0x0056AE84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE84u);
	// 0x285B08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x285B10: movss [0x0056AEB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEB4u, ctx.xmm[0].u32[0]);
	// 0x285B18: ret
	return;
}

void sub_285B20(X86Context& ctx, uint8_t* base) {
	// 0x285B20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x285B28: movss [0x0056AF38], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF38u, ctx.xmm[0].u32[0]);
	// 0x285B30: ret
	return;
}

void sub_285B40(X86Context& ctx, uint8_t* base) {
	// 0x285B40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x285B48: movss [0x0056AF54], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF54u, ctx.xmm[0].u32[0]);
	// 0x285B50: ret
	return;
}

void sub_285B60(X86Context& ctx, uint8_t* base) {
	// 0x285B60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x285B68: movss [0x0056AF2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF2Cu, ctx.xmm[0].u32[0]);
	// 0x285B70: ret
	return;
}

void sub_285B80(X86Context& ctx, uint8_t* base) {
	// 0x285B80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x285B88: movss [0x0056AEE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEE4u, ctx.xmm[0].u32[0]);
	// 0x285B90: ret
	return;
}

void sub_285BA0(X86Context& ctx, uint8_t* base) {
	// 0x285BA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x285BA8: movss [0x0056AF3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF3Cu, ctx.xmm[0].u32[0]);
	// 0x285BB0: ret
	return;
}

void sub_285BC0(X86Context& ctx, uint8_t* base) {
	// 0x285BC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x285BC8: movss [0x0056AF00], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF00u, ctx.xmm[0].u32[0]);
	// 0x285BD0: ret
	return;
}

void sub_285BE0(X86Context& ctx, uint8_t* base) {
	// 0x285BE0: movss xmm0, dword ptr [0x0056AF3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF3Cu);
	// 0x285BE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285BF0: movss [0x0056AF74], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF74u, ctx.xmm[0].u32[0]);
	// 0x285BF8: ret
	return;
}

void sub_285C00(X86Context& ctx, uint8_t* base) {
	// 0x285C00: movss xmm0, dword ptr [0x0056AF00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF00u);
	// 0x285C08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x285C10: movss [0x0056AF5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF5Cu, ctx.xmm[0].u32[0]);
	// 0x285C18: ret
	return;
}

void sub_285C20(X86Context& ctx, uint8_t* base) {
	// 0x285C20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x285C28: movss [0x0056AF8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF8Cu, ctx.xmm[0].u32[0]);
	// 0x285C30: ret
	return;
}

void sub_285C40(X86Context& ctx, uint8_t* base) {
	// 0x285C40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x285C48: movss [0x0056AF78], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF78u, ctx.xmm[0].u32[0]);
	// 0x285C50: ret
	return;
}

void sub_285C60(X86Context& ctx, uint8_t* base) {
	// 0x285C60: movss xmm0, dword ptr [0x0056AF78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF78u);
	// 0x285C68: movss [0x0056AF88], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF88u, ctx.xmm[0].u32[0]);
	// 0x285C70: ret
	return;
}

void sub_285C80(X86Context& ctx, uint8_t* base) {
	// 0x285C80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x285C88: movss [0x0056AEEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEECu, ctx.xmm[0].u32[0]);
	// 0x285C90: ret
	return;
}

void sub_285CA0(X86Context& ctx, uint8_t* base) {
	// 0x285CA0: movss xmm0, dword ptr [0x0056AF00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF00u);
	// 0x285CA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x285CB0: movss [0x0056AF80], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF80u, ctx.xmm[0].u32[0]);
	// 0x285CB8: ret
	return;
}

void sub_285CC0(X86Context& ctx, uint8_t* base) {
	// 0x285CC0: movss xmm0, dword ptr [0x0056AF00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF00u);
	// 0x285CC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x285CD0: movss [0x0056AF28], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF28u, ctx.xmm[0].u32[0]);
	// 0x285CD8: ret
	return;
}

void sub_285CE0(X86Context& ctx, uint8_t* base) {
	// 0x285CE0: movss xmm0, dword ptr [0x0056AF00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF00u);
	// 0x285CE8: subss xmm0, [0x0056AF28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AF28u);
	// 0x285CF0: movss [0x0056AF08], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF08u, ctx.xmm[0].u32[0]);
	// 0x285CF8: ret
	return;
}

void sub_285D00(X86Context& ctx, uint8_t* base) {
	// 0x285D00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x285D08: movss [0x0056AF50], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF50u, ctx.xmm[0].u32[0]);
	// 0x285D10: ret
	return;
}

void sub_285D20(X86Context& ctx, uint8_t* base) {
	// 0x285D20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x285D28: movss [0x0056AF04], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF04u, ctx.xmm[0].u32[0]);
	// 0x285D30: ret
	return;
}

void sub_285D40(X86Context& ctx, uint8_t* base) {
	// 0x285D40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x285D48: movss [0x0056AF14], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF14u, ctx.xmm[0].u32[0]);
	// 0x285D50: ret
	return;
}

void sub_285D60(X86Context& ctx, uint8_t* base) {
	// 0x285D60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x285D68: movss [0x0056AF68], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF68u, ctx.xmm[0].u32[0]);
	// 0x285D70: ret
	return;
}

void sub_285D80(X86Context& ctx, uint8_t* base) {
	// 0x285D80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x285D88: movss [0x0056AF4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF4Cu, ctx.xmm[0].u32[0]);
	// 0x285D90: ret
	return;
}

void sub_285DA0(X86Context& ctx, uint8_t* base) {
	// 0x285DA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x285DA8: movss [0x0056AEFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEFCu, ctx.xmm[0].u32[0]);
	// 0x285DB0: ret
	return;
}

void sub_285DC0(X86Context& ctx, uint8_t* base) {
	// 0x285DC0: movss xmm0, dword ptr [0x0056AF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF14u);
	// 0x285DC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285DD0: movss [0x0056AEF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEF0u, ctx.xmm[0].u32[0]);
	// 0x285DD8: ret
	return;
}

void sub_285DE0(X86Context& ctx, uint8_t* base) {
	// 0x285DE0: movss xmm0, dword ptr [0x0056AF68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF68u);
	// 0x285DE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x285DF0: movss [0x0056AF34], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF34u, ctx.xmm[0].u32[0]);
	// 0x285DF8: ret
	return;
}

void sub_285E00(X86Context& ctx, uint8_t* base) {
	// 0x285E00: movss xmm0, dword ptr [0x0056AEF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEF0u);
	// 0x285E08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285E10: movss [0x0056AF44], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF44u, ctx.xmm[0].u32[0]);
	// 0x285E18: ret
	return;
}

void sub_285E20(X86Context& ctx, uint8_t* base) {
	// 0x285E20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x285E28: movss [0x0056AEE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEE8u, ctx.xmm[0].u32[0]);
	// 0x285E30: ret
	return;
}

void sub_285E40(X86Context& ctx, uint8_t* base) {
	// 0x285E40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x285E48: movss [0x0056AF18], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF18u, ctx.xmm[0].u32[0]);
	// 0x285E50: ret
	return;
}

void sub_285E60(X86Context& ctx, uint8_t* base) {
	// 0x285E60: movss xmm0, dword ptr [0x0056AF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF14u);
	// 0x285E68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x285E70: movss [0x0056AF24], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF24u, ctx.xmm[0].u32[0]);
	// 0x285E78: ret
	return;
}

void sub_285E80(X86Context& ctx, uint8_t* base) {
	// 0x285E80: movss xmm0, dword ptr [0x0056AF68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF68u);
	// 0x285E88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x285E90: movss [0x0056AF6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF6Cu, ctx.xmm[0].u32[0]);
	// 0x285E98: ret
	return;
}

void sub_285EA0(X86Context& ctx, uint8_t* base) {
	// 0x285EA0: movss xmm0, dword ptr [0x0056AF24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF24u);
	// 0x285EA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285EB0: movss [0x0056AF58], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF58u, ctx.xmm[0].u32[0]);
	// 0x285EB8: ret
	return;
}

void sub_285EC0(X86Context& ctx, uint8_t* base) {
	// 0x285EC0: movss xmm0, dword ptr [0x0056AF6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF6Cu);
	// 0x285EC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285ED0: movss [0x0056AF7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF7Cu, ctx.xmm[0].u32[0]);
	// 0x285ED8: ret
	return;
}

void sub_285EE0(X86Context& ctx, uint8_t* base) {
	// 0x285EE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x285EE8: movss [0x0056AEF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEF4u, ctx.xmm[0].u32[0]);
	// 0x285EF0: ret
	return;
}

void sub_285F00(X86Context& ctx, uint8_t* base) {
	// 0x285F00: movss xmm0, dword ptr [0x0056AF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF14u);
	// 0x285F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285F10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x285F18: movss [0x0056AF64], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF64u, ctx.xmm[0].u32[0]);
	// 0x285F20: ret
	return;
}

void sub_285F30(X86Context& ctx, uint8_t* base) {
	// 0x285F30: movss xmm0, dword ptr [0x0056AF68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF68u);
	// 0x285F38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285F40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x285F48: movss [0x0056AF0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF0Cu, ctx.xmm[0].u32[0]);
	// 0x285F50: ret
	return;
}

void sub_285F60(X86Context& ctx, uint8_t* base) {
	// 0x285F60: movss xmm0, dword ptr [0x0056AF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF14u);
	// 0x285F68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285F70: movss [0x0056AF10], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF10u, ctx.xmm[0].u32[0]);
	// 0x285F78: ret
	return;
}

void sub_285F80(X86Context& ctx, uint8_t* base) {
	// 0x285F80: movss xmm0, dword ptr [0x0056AF68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF68u);
	// 0x285F88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285F90: movss [0x0056AF70], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF70u, ctx.xmm[0].u32[0]);
	// 0x285F98: ret
	return;
}

void sub_285FA0(X86Context& ctx, uint8_t* base) {
	// 0x285FA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x285FA8: movss [0x0056AEF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEF8u, ctx.xmm[0].u32[0]);
	// 0x285FB0: ret
	return;
}

void sub_285FC0(X86Context& ctx, uint8_t* base) {
	// 0x285FC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x285FC8: movss [0x0056AF20], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF20u, ctx.xmm[0].u32[0]);
	// 0x285FD0: ret
	return;
}

void sub_285FE0(X86Context& ctx, uint8_t* base) {
	// 0x285FE0: movss xmm0, dword ptr [0x0056AEF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEF8u);
	// 0x285FE8: movss [0x0056AF84], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF84u, ctx.xmm[0].u32[0]);
	// 0x285FF0: ret
	return;
}

void sub_286000(X86Context& ctx, uint8_t* base) {
	// 0x286000: movss xmm0, dword ptr [0x0056AF68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF68u);
	// 0x286008: subss xmm0, [0x0056AEF8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AEF8u);
	// 0x286010: movss [0x0056AF48], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF48u, ctx.xmm[0].u32[0]);
	// 0x286018: ret
	return;
}

void sub_286020(X86Context& ctx, uint8_t* base) {
	// 0x286020: movss xmm0, dword ptr [0x0056AF48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF48u);
	// 0x286028: subss xmm0, [0x0056AF20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AF20u);
	// 0x286030: movss [0x0056AF40], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF40u, ctx.xmm[0].u32[0]);
	// 0x286038: ret
	return;
}

void sub_286040(X86Context& ctx, uint8_t* base) {
	// 0x286040: movss xmm0, dword ptr [0x0056AF70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF70u);
	// 0x286048: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x286050: movss [0x0056AF30], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF30u, ctx.xmm[0].u32[0]);
	// 0x286058: ret
	return;
}

void sub_286060(X86Context& ctx, uint8_t* base) {
	// 0x286060: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x286068: movss [0x0056AF1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF1Cu, ctx.xmm[0].u32[0]);
	// 0x286070: ret
	return;
}

void sub_286080(X86Context& ctx, uint8_t* base) {
	// 0x286080: movss xmm0, dword ptr [0x0056AF30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF30u);
	// 0x286088: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x286090: movss [0x0056AF60], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF60u, ctx.xmm[0].u32[0]);
	// 0x286098: ret
	return;
}

void sub_2860A0(X86Context& ctx, uint8_t* base) {
	// 0x2860A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2860A8: movss [0x0056AFE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFE4u, ctx.xmm[0].u32[0]);
	// 0x2860B0: ret
	return;
}

void sub_2860C0(X86Context& ctx, uint8_t* base) {
	// 0x2860C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2860C8: movss [0x0056B000], xmm0
	X86_MEM_WRITE_u32(base, 0x56B000u, ctx.xmm[0].u32[0]);
	// 0x2860D0: ret
	return;
}

void sub_2860E0(X86Context& ctx, uint8_t* base) {
	// 0x2860E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2860E8: movss [0x0056AFD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFD8u, ctx.xmm[0].u32[0]);
	// 0x2860F0: ret
	return;
}

void sub_286100(X86Context& ctx, uint8_t* base) {
	// 0x286100: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x286108: movss [0x0056AF90], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF90u, ctx.xmm[0].u32[0]);
	// 0x286110: ret
	return;
}

void sub_286120(X86Context& ctx, uint8_t* base) {
	// 0x286120: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x286128: movss [0x0056AFE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFE8u, ctx.xmm[0].u32[0]);
	// 0x286130: ret
	return;
}

void sub_286140(X86Context& ctx, uint8_t* base) {
	// 0x286140: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x286148: movss [0x0056AFAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFACu, ctx.xmm[0].u32[0]);
	// 0x286150: ret
	return;
}

void sub_286160(X86Context& ctx, uint8_t* base) {
	// 0x286160: movss xmm0, dword ptr [0x0056AFE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFE8u);
	// 0x286168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286170: movss [0x0056B020], xmm0
	X86_MEM_WRITE_u32(base, 0x56B020u, ctx.xmm[0].u32[0]);
	// 0x286178: ret
	return;
}

void sub_286180(X86Context& ctx, uint8_t* base) {
	// 0x286180: movss xmm0, dword ptr [0x0056AFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFACu);
	// 0x286188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x286190: movss [0x0056B008], xmm0
	X86_MEM_WRITE_u32(base, 0x56B008u, ctx.xmm[0].u32[0]);
	// 0x286198: ret
	return;
}

void sub_2861A0(X86Context& ctx, uint8_t* base) {
	// 0x2861A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2861A8: movss [0x0056B038], xmm0
	X86_MEM_WRITE_u32(base, 0x56B038u, ctx.xmm[0].u32[0]);
	// 0x2861B0: ret
	return;
}

void sub_2861C0(X86Context& ctx, uint8_t* base) {
	// 0x2861C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2861C8: movss [0x0056B024], xmm0
	X86_MEM_WRITE_u32(base, 0x56B024u, ctx.xmm[0].u32[0]);
	// 0x2861D0: ret
	return;
}

void sub_2861E0(X86Context& ctx, uint8_t* base) {
	// 0x2861E0: movss xmm0, dword ptr [0x0056B024]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B024u);
	// 0x2861E8: movss [0x0056B034], xmm0
	X86_MEM_WRITE_u32(base, 0x56B034u, ctx.xmm[0].u32[0]);
	// 0x2861F0: ret
	return;
}

void sub_286200(X86Context& ctx, uint8_t* base) {
	// 0x286200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x286208: movss [0x0056AF98], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF98u, ctx.xmm[0].u32[0]);
	// 0x286210: ret
	return;
}

void sub_286220(X86Context& ctx, uint8_t* base) {
	// 0x286220: movss xmm0, dword ptr [0x0056AFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFACu);
	// 0x286228: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x286230: movss [0x0056B02C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B02Cu, ctx.xmm[0].u32[0]);
	// 0x286238: ret
	return;
}

void sub_286240(X86Context& ctx, uint8_t* base) {
	// 0x286240: movss xmm0, dword ptr [0x0056AFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFACu);
	// 0x286248: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x286250: movss [0x0056AFD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFD4u, ctx.xmm[0].u32[0]);
	// 0x286258: ret
	return;
}

void sub_286260(X86Context& ctx, uint8_t* base) {
	// 0x286260: movss xmm0, dword ptr [0x0056AFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFACu);
	// 0x286268: subss xmm0, [0x0056AFD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AFD4u);
	// 0x286270: movss [0x0056AFB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFB4u, ctx.xmm[0].u32[0]);
	// 0x286278: ret
	return;
}

void sub_286280(X86Context& ctx, uint8_t* base) {
	// 0x286280: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x286288: movss [0x0056AFFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFFCu, ctx.xmm[0].u32[0]);
	// 0x286290: ret
	return;
}

void sub_2862A0(X86Context& ctx, uint8_t* base) {
	// 0x2862A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2862A8: movss [0x0056AFB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFB0u, ctx.xmm[0].u32[0]);
	// 0x2862B0: ret
	return;
}

void sub_2862C0(X86Context& ctx, uint8_t* base) {
	// 0x2862C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2862C8: movss [0x0056AFC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFC0u, ctx.xmm[0].u32[0]);
	// 0x2862D0: ret
	return;
}

void sub_2862E0(X86Context& ctx, uint8_t* base) {
	// 0x2862E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2862E8: movss [0x0056B014], xmm0
	X86_MEM_WRITE_u32(base, 0x56B014u, ctx.xmm[0].u32[0]);
	// 0x2862F0: ret
	return;
}

void sub_286300(X86Context& ctx, uint8_t* base) {
	// 0x286300: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x286308: movss [0x0056AFF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFF8u, ctx.xmm[0].u32[0]);
	// 0x286310: ret
	return;
}

void sub_286320(X86Context& ctx, uint8_t* base) {
	// 0x286320: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x286328: movss [0x0056AFA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFA8u, ctx.xmm[0].u32[0]);
	// 0x286330: ret
	return;
}

void sub_286340(X86Context& ctx, uint8_t* base) {
	// 0x286340: movss xmm0, dword ptr [0x0056AFC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFC0u);
	// 0x286348: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286350: movss [0x0056AF9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF9Cu, ctx.xmm[0].u32[0]);
	// 0x286358: ret
	return;
}

void sub_286360(X86Context& ctx, uint8_t* base) {
	// 0x286360: movss xmm0, dword ptr [0x0056B014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B014u);
	// 0x286368: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x286370: movss [0x0056AFE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFE0u, ctx.xmm[0].u32[0]);
	// 0x286378: ret
	return;
}

void sub_286380(X86Context& ctx, uint8_t* base) {
	// 0x286380: movss xmm0, dword ptr [0x0056AF9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AF9Cu);
	// 0x286388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286390: movss [0x0056AFF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFF0u, ctx.xmm[0].u32[0]);
	// 0x286398: ret
	return;
}

void sub_2863A0(X86Context& ctx, uint8_t* base) {
	// 0x2863A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2863A8: movss [0x0056AF94], xmm0
	X86_MEM_WRITE_u32(base, 0x56AF94u, ctx.xmm[0].u32[0]);
	// 0x2863B0: ret
	return;
}

void sub_2863C0(X86Context& ctx, uint8_t* base) {
	// 0x2863C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2863C8: movss [0x0056AFC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFC4u, ctx.xmm[0].u32[0]);
	// 0x2863D0: ret
	return;
}

void sub_2863E0(X86Context& ctx, uint8_t* base) {
	// 0x2863E0: movss xmm0, dword ptr [0x0056AFC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFC0u);
	// 0x2863E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2863F0: movss [0x0056AFD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFD0u, ctx.xmm[0].u32[0]);
	// 0x2863F8: ret
	return;
}

void sub_286400(X86Context& ctx, uint8_t* base) {
	// 0x286400: movss xmm0, dword ptr [0x0056B014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B014u);
	// 0x286408: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x286410: movss [0x0056B018], xmm0
	X86_MEM_WRITE_u32(base, 0x56B018u, ctx.xmm[0].u32[0]);
	// 0x286418: ret
	return;
}

void sub_286420(X86Context& ctx, uint8_t* base) {
	// 0x286420: movss xmm0, dword ptr [0x0056AFD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFD0u);
	// 0x286428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286430: movss [0x0056B004], xmm0
	X86_MEM_WRITE_u32(base, 0x56B004u, ctx.xmm[0].u32[0]);
	// 0x286438: ret
	return;
}

void sub_286440(X86Context& ctx, uint8_t* base) {
	// 0x286440: movss xmm0, dword ptr [0x0056B018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B018u);
	// 0x286448: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286450: movss [0x0056B028], xmm0
	X86_MEM_WRITE_u32(base, 0x56B028u, ctx.xmm[0].u32[0]);
	// 0x286458: ret
	return;
}

void sub_286460(X86Context& ctx, uint8_t* base) {
	// 0x286460: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x286468: movss [0x0056AFA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFA0u, ctx.xmm[0].u32[0]);
	// 0x286470: ret
	return;
}

void sub_286480(X86Context& ctx, uint8_t* base) {
	// 0x286480: movss xmm0, dword ptr [0x0056AFC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFC0u);
	// 0x286488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286490: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x286498: movss [0x0056B010], xmm0
	X86_MEM_WRITE_u32(base, 0x56B010u, ctx.xmm[0].u32[0]);
	// 0x2864A0: ret
	return;
}

void sub_2864B0(X86Context& ctx, uint8_t* base) {
	// 0x2864B0: movss xmm0, dword ptr [0x0056B014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B014u);
	// 0x2864B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2864C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2864C8: movss [0x0056AFB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFB8u, ctx.xmm[0].u32[0]);
	// 0x2864D0: ret
	return;
}

void sub_2864E0(X86Context& ctx, uint8_t* base) {
	// 0x2864E0: movss xmm0, dword ptr [0x0056AFC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFC0u);
	// 0x2864E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2864F0: movss [0x0056AFBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFBCu, ctx.xmm[0].u32[0]);
	// 0x2864F8: ret
	return;
}

void sub_286500(X86Context& ctx, uint8_t* base) {
	// 0x286500: movss xmm0, dword ptr [0x0056B014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B014u);
	// 0x286508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286510: movss [0x0056B01C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B01Cu, ctx.xmm[0].u32[0]);
	// 0x286518: ret
	return;
}

void sub_286520(X86Context& ctx, uint8_t* base) {
	// 0x286520: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x286528: movss [0x0056AFA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFA4u, ctx.xmm[0].u32[0]);
	// 0x286530: ret
	return;
}

void sub_286540(X86Context& ctx, uint8_t* base) {
	// 0x286540: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x286548: movss [0x0056AFCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFCCu, ctx.xmm[0].u32[0]);
	// 0x286550: ret
	return;
}

void sub_286560(X86Context& ctx, uint8_t* base) {
	// 0x286560: movss xmm0, dword ptr [0x0056AFA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFA4u);
	// 0x286568: movss [0x0056B030], xmm0
	X86_MEM_WRITE_u32(base, 0x56B030u, ctx.xmm[0].u32[0]);
	// 0x286570: ret
	return;
}

void sub_286580(X86Context& ctx, uint8_t* base) {
	// 0x286580: movss xmm0, dword ptr [0x0056B014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B014u);
	// 0x286588: subss xmm0, [0x0056AFA4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AFA4u);
	// 0x286590: movss [0x0056AFF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFF4u, ctx.xmm[0].u32[0]);
	// 0x286598: ret
	return;
}

void sub_2865A0(X86Context& ctx, uint8_t* base) {
	// 0x2865A0: movss xmm0, dword ptr [0x0056AFF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFF4u);
	// 0x2865A8: subss xmm0, [0x0056AFCC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AFCCu);
	// 0x2865B0: movss [0x0056AFEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFECu, ctx.xmm[0].u32[0]);
	// 0x2865B8: ret
	return;
}

void sub_2865C0(X86Context& ctx, uint8_t* base) {
	// 0x2865C0: movss xmm0, dword ptr [0x0056B01C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B01Cu);
	// 0x2865C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2865D0: movss [0x0056AFDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFDCu, ctx.xmm[0].u32[0]);
	// 0x2865D8: ret
	return;
}

void sub_2865E0(X86Context& ctx, uint8_t* base) {
	// 0x2865E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2865E8: movss [0x0056AFC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AFC8u, ctx.xmm[0].u32[0]);
	// 0x2865F0: ret
	return;
}

void sub_286600(X86Context& ctx, uint8_t* base) {
	// 0x286600: movss xmm0, dword ptr [0x0056AFDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AFDCu);
	// 0x286608: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x286610: movss [0x0056B00C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B00Cu, ctx.xmm[0].u32[0]);
	// 0x286618: ret
	return;
}

void sub_286620(X86Context& ctx, uint8_t* base) {
	// 0x286620: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x286628: movss [0x0056B090], xmm0
	X86_MEM_WRITE_u32(base, 0x56B090u, ctx.xmm[0].u32[0]);
	// 0x286630: ret
	return;
}

void sub_286640(X86Context& ctx, uint8_t* base) {
	// 0x286640: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x286648: movss [0x0056B0B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0B0u, ctx.xmm[0].u32[0]);
	// 0x286650: ret
	return;
}

void sub_286660(X86Context& ctx, uint8_t* base) {
	// 0x286660: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x286668: movss [0x0056B084], xmm0
	X86_MEM_WRITE_u32(base, 0x56B084u, ctx.xmm[0].u32[0]);
	// 0x286670: ret
	return;
}

void sub_286680(X86Context& ctx, uint8_t* base) {
	// 0x286680: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x286688: movss [0x0056B03C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B03Cu, ctx.xmm[0].u32[0]);
	// 0x286690: ret
	return;
}

void sub_2866A0(X86Context& ctx, uint8_t* base) {
	// 0x2866A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2866A8: movss [0x0056B094], xmm0
	X86_MEM_WRITE_u32(base, 0x56B094u, ctx.xmm[0].u32[0]);
	// 0x2866B0: ret
	return;
}

void sub_2866C0(X86Context& ctx, uint8_t* base) {
	// 0x2866C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2866C8: movss [0x0056B058], xmm0
	X86_MEM_WRITE_u32(base, 0x56B058u, ctx.xmm[0].u32[0]);
	// 0x2866D0: ret
	return;
}

void sub_2866E0(X86Context& ctx, uint8_t* base) {
	// 0x2866E0: movss xmm0, dword ptr [0x0056B094]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B094u);
	// 0x2866E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2866F0: movss [0x0056B0D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0D0u, ctx.xmm[0].u32[0]);
	// 0x2866F8: ret
	return;
}

void sub_286700(X86Context& ctx, uint8_t* base) {
	// 0x286700: movss xmm0, dword ptr [0x0056B058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B058u);
	// 0x286708: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x286710: movss [0x0056B0B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0B8u, ctx.xmm[0].u32[0]);
	// 0x286718: ret
	return;
}

void sub_286720(X86Context& ctx, uint8_t* base) {
	// 0x286720: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x286728: movss [0x0056B0F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0F0u, ctx.xmm[0].u32[0]);
	// 0x286730: ret
	return;
}

void sub_286740(X86Context& ctx, uint8_t* base) {
	// 0x286740: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x286748: movss [0x0056B0D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0D4u, ctx.xmm[0].u32[0]);
	// 0x286750: ret
	return;
}

void sub_286760(X86Context& ctx, uint8_t* base) {
	// 0x286760: movss xmm0, dword ptr [0x0056B0D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0D4u);
	// 0x286768: movss [0x0056B0EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0ECu, ctx.xmm[0].u32[0]);
	// 0x286770: ret
	return;
}

void sub_286780(X86Context& ctx, uint8_t* base) {
	// 0x286780: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x286788: movss [0x0056B044], xmm0
	X86_MEM_WRITE_u32(base, 0x56B044u, ctx.xmm[0].u32[0]);
	// 0x286790: ret
	return;
}

void sub_2867A0(X86Context& ctx, uint8_t* base) {
	// 0x2867A0: movss xmm0, dword ptr [0x0056B058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B058u);
	// 0x2867A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2867B0: movss [0x0056B0DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0DCu, ctx.xmm[0].u32[0]);
	// 0x2867B8: ret
	return;
}

void sub_2867C0(X86Context& ctx, uint8_t* base) {
	// 0x2867C0: movss xmm0, dword ptr [0x0056B058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B058u);
	// 0x2867C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2867D0: movss [0x0056B080], xmm0
	X86_MEM_WRITE_u32(base, 0x56B080u, ctx.xmm[0].u32[0]);
	// 0x2867D8: ret
	return;
}

void sub_2867E0(X86Context& ctx, uint8_t* base) {
	// 0x2867E0: movss xmm0, dword ptr [0x0056B058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B058u);
	// 0x2867E8: subss xmm0, [0x0056B080]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B080u);
	// 0x2867F0: movss [0x0056B060], xmm0
	X86_MEM_WRITE_u32(base, 0x56B060u, ctx.xmm[0].u32[0]);
	// 0x2867F8: ret
	return;
}

void sub_286800(X86Context& ctx, uint8_t* base) {
	// 0x286800: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x286808: movss [0x0056B0AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0ACu, ctx.xmm[0].u32[0]);
	// 0x286810: ret
	return;
}

void sub_286820(X86Context& ctx, uint8_t* base) {
	// 0x286820: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x286828: movss [0x0056B05C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B05Cu, ctx.xmm[0].u32[0]);
	// 0x286830: ret
	return;
}

void sub_286840(X86Context& ctx, uint8_t* base) {
	// 0x286840: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x286848: movss [0x0056B06C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B06Cu, ctx.xmm[0].u32[0]);
	// 0x286850: ret
	return;
}

void sub_286860(X86Context& ctx, uint8_t* base) {
	// 0x286860: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x286868: movss [0x0056B0C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0C4u, ctx.xmm[0].u32[0]);
	// 0x286870: ret
	return;
}

void sub_286880(X86Context& ctx, uint8_t* base) {
	// 0x286880: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x286888: movss [0x0056B0A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0A4u, ctx.xmm[0].u32[0]);
	// 0x286890: ret
	return;
}

void sub_2868A0(X86Context& ctx, uint8_t* base) {
	// 0x2868A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2868A8: movss [0x0056B054], xmm0
	X86_MEM_WRITE_u32(base, 0x56B054u, ctx.xmm[0].u32[0]);
	// 0x2868B0: ret
	return;
}

void sub_2868C0(X86Context& ctx, uint8_t* base) {
	// 0x2868C0: movss xmm0, dword ptr [0x0056B06C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B06Cu);
	// 0x2868C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2868D0: movss [0x0056B048], xmm0
	X86_MEM_WRITE_u32(base, 0x56B048u, ctx.xmm[0].u32[0]);
	// 0x2868D8: ret
	return;
}

void sub_2868E0(X86Context& ctx, uint8_t* base) {
	// 0x2868E0: movss xmm0, dword ptr [0x0056B0C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0C4u);
	// 0x2868E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2868F0: movss [0x0056B08C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B08Cu, ctx.xmm[0].u32[0]);
	// 0x2868F8: ret
	return;
}

void sub_286900(X86Context& ctx, uint8_t* base) {
	// 0x286900: movss xmm0, dword ptr [0x0056B048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B048u);
	// 0x286908: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286910: movss [0x0056B09C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B09Cu, ctx.xmm[0].u32[0]);
	// 0x286918: ret
	return;
}

void sub_286920(X86Context& ctx, uint8_t* base) {
	// 0x286920: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x286928: movss [0x0056B040], xmm0
	X86_MEM_WRITE_u32(base, 0x56B040u, ctx.xmm[0].u32[0]);
	// 0x286930: ret
	return;
}

void sub_286940(X86Context& ctx, uint8_t* base) {
	// 0x286940: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x286948: movss [0x0056B070], xmm0
	X86_MEM_WRITE_u32(base, 0x56B070u, ctx.xmm[0].u32[0]);
	// 0x286950: ret
	return;
}

void sub_286960(X86Context& ctx, uint8_t* base) {
	// 0x286960: movss xmm0, dword ptr [0x0056B06C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B06Cu);
	// 0x286968: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x286970: movss [0x0056B07C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B07Cu, ctx.xmm[0].u32[0]);
	// 0x286978: ret
	return;
}

void sub_286980(X86Context& ctx, uint8_t* base) {
	// 0x286980: movss xmm0, dword ptr [0x0056B0C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0C4u);
	// 0x286988: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x286990: movss [0x0056B0C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0C8u, ctx.xmm[0].u32[0]);
	// 0x286998: ret
	return;
}

void sub_2869A0(X86Context& ctx, uint8_t* base) {
	// 0x2869A0: movss xmm0, dword ptr [0x0056B07C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B07Cu);
	// 0x2869A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2869B0: movss [0x0056B0B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0B4u, ctx.xmm[0].u32[0]);
	// 0x2869B8: ret
	return;
}

void sub_2869C0(X86Context& ctx, uint8_t* base) {
	// 0x2869C0: movss xmm0, dword ptr [0x0056B0C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0C8u);
	// 0x2869C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2869D0: movss [0x0056B0D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0D8u, ctx.xmm[0].u32[0]);
	// 0x2869D8: ret
	return;
}

void sub_2869E0(X86Context& ctx, uint8_t* base) {
	// 0x2869E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2869E8: movss [0x0056B04C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B04Cu, ctx.xmm[0].u32[0]);
	// 0x2869F0: ret
	return;
}

void sub_286A00(X86Context& ctx, uint8_t* base) {
	// 0x286A00: movss xmm0, dword ptr [0x0056B06C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B06Cu);
	// 0x286A08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286A10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x286A18: movss [0x0056B0C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0C0u, ctx.xmm[0].u32[0]);
	// 0x286A20: ret
	return;
}

void sub_286A30(X86Context& ctx, uint8_t* base) {
	// 0x286A30: movss xmm0, dword ptr [0x0056B0C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0C4u);
	// 0x286A38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286A40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x286A48: movss [0x0056B064], xmm0
	X86_MEM_WRITE_u32(base, 0x56B064u, ctx.xmm[0].u32[0]);
	// 0x286A50: ret
	return;
}

void sub_286A60(X86Context& ctx, uint8_t* base) {
	// 0x286A60: movss xmm0, dword ptr [0x0056B06C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B06Cu);
	// 0x286A68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286A70: movss [0x0056B068], xmm0
	X86_MEM_WRITE_u32(base, 0x56B068u, ctx.xmm[0].u32[0]);
	// 0x286A78: ret
	return;
}

void sub_286A80(X86Context& ctx, uint8_t* base) {
	// 0x286A80: movss xmm0, dword ptr [0x0056B0C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0C4u);
	// 0x286A88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286A90: movss [0x0056B0CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0CCu, ctx.xmm[0].u32[0]);
	// 0x286A98: ret
	return;
}

void sub_286AA0(X86Context& ctx, uint8_t* base) {
	// 0x286AA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x286AA8: movss [0x0056B050], xmm0
	X86_MEM_WRITE_u32(base, 0x56B050u, ctx.xmm[0].u32[0]);
	// 0x286AB0: ret
	return;
}

void sub_286AC0(X86Context& ctx, uint8_t* base) {
	// 0x286AC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x286AC8: movss [0x0056B078], xmm0
	X86_MEM_WRITE_u32(base, 0x56B078u, ctx.xmm[0].u32[0]);
	// 0x286AD0: ret
	return;
}

void sub_286AE0(X86Context& ctx, uint8_t* base) {
	// 0x286AE0: movss xmm0, dword ptr [0x0056B050]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B050u);
	// 0x286AE8: movss [0x0056B0E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0E4u, ctx.xmm[0].u32[0]);
	// 0x286AF0: ret
	return;
}

void sub_286B00(X86Context& ctx, uint8_t* base) {
	// 0x286B00: movss xmm0, dword ptr [0x0056B0C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0C4u);
	// 0x286B08: subss xmm0, [0x0056B050]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B050u);
	// 0x286B10: movss [0x0056B0A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0A0u, ctx.xmm[0].u32[0]);
	// 0x286B18: ret
	return;
}

void sub_286B20(X86Context& ctx, uint8_t* base) {
	// 0x286B20: movss xmm0, dword ptr [0x0056B0A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0A0u);
	// 0x286B28: subss xmm0, [0x0056B078]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B078u);
	// 0x286B30: movss [0x0056B098], xmm0
	X86_MEM_WRITE_u32(base, 0x56B098u, ctx.xmm[0].u32[0]);
	// 0x286B38: ret
	return;
}

void sub_286B40(X86Context& ctx, uint8_t* base) {
	// 0x286B40: movss xmm0, dword ptr [0x0056B0CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B0CCu);
	// 0x286B48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x286B50: movss [0x0056B088], xmm0
	X86_MEM_WRITE_u32(base, 0x56B088u, ctx.xmm[0].u32[0]);
	// 0x286B58: ret
	return;
}

void sub_286B60(X86Context& ctx, uint8_t* base) {
	// 0x286B60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x286B68: movss [0x0056B074], xmm0
	X86_MEM_WRITE_u32(base, 0x56B074u, ctx.xmm[0].u32[0]);
	// 0x286B70: ret
	return;
}

void sub_286B80(X86Context& ctx, uint8_t* base) {
	// 0x286B80: movss xmm0, dword ptr [0x0056B088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B088u);
	// 0x286B88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x286B90: movss [0x0056B0BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0BCu, ctx.xmm[0].u32[0]);
	// 0x286B98: ret
	return;
}

void sub_286BA0(X86Context& ctx, uint8_t* base) {
	// 0x286BA0: movss xmm0, dword ptr [0x003B2270]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2270u);
	// 0x286BA8: movss [0x0056B0A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0A8u, ctx.xmm[0].u32[0]);
	// 0x286BB0: ret
	return;
}

void sub_286BC0(X86Context& ctx, uint8_t* base) {
	// 0x286BC0: movss xmm0, dword ptr [0x003B2274]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2274u);
	// 0x286BC8: movss [0x0056B0E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0E8u, ctx.xmm[0].u32[0]);
	// 0x286BD0: ret
	return;
}

void sub_286BE0(X86Context& ctx, uint8_t* base) {
	// 0x286BE0: movss xmm0, dword ptr [0x003B2278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2278u);
	// 0x286BE8: movss [0x0056B0E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0E0u, ctx.xmm[0].u32[0]);
	// 0x286BF0: ret
	return;
}

void sub_286C00(X86Context& ctx, uint8_t* base) {
	// 0x286C00: movss xmm0, dword ptr [0x003B227C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B227Cu);
	// 0x286C08: movss [0x0056B0F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0F4u, ctx.xmm[0].u32[0]);
	// 0x286C10: ret
	return;
}

void sub_286C20(X86Context& ctx, uint8_t* base) {
	// 0x286C20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x286C28: movss [0x0056B14C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B14Cu, ctx.xmm[0].u32[0]);
	// 0x286C30: ret
	return;
}

void sub_286C40(X86Context& ctx, uint8_t* base) {
	// 0x286C40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x286C48: movss [0x0056B168], xmm0
	X86_MEM_WRITE_u32(base, 0x56B168u, ctx.xmm[0].u32[0]);
	// 0x286C50: ret
	return;
}

void sub_286C60(X86Context& ctx, uint8_t* base) {
	// 0x286C60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x286C68: movss [0x0056B140], xmm0
	X86_MEM_WRITE_u32(base, 0x56B140u, ctx.xmm[0].u32[0]);
	// 0x286C70: ret
	return;
}

void sub_286C80(X86Context& ctx, uint8_t* base) {
	// 0x286C80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x286C88: movss [0x0056B0F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0F8u, ctx.xmm[0].u32[0]);
	// 0x286C90: ret
	return;
}

void sub_286CA0(X86Context& ctx, uint8_t* base) {
	// 0x286CA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x286CA8: movss [0x0056B150], xmm0
	X86_MEM_WRITE_u32(base, 0x56B150u, ctx.xmm[0].u32[0]);
	// 0x286CB0: ret
	return;
}

void sub_286CC0(X86Context& ctx, uint8_t* base) {
	// 0x286CC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x286CC8: movss [0x0056B114], xmm0
	X86_MEM_WRITE_u32(base, 0x56B114u, ctx.xmm[0].u32[0]);
	// 0x286CD0: ret
	return;
}

void sub_286CE0(X86Context& ctx, uint8_t* base) {
	// 0x286CE0: movss xmm0, dword ptr [0x0056B150]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B150u);
	// 0x286CE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286CF0: movss [0x0056B188], xmm0
	X86_MEM_WRITE_u32(base, 0x56B188u, ctx.xmm[0].u32[0]);
	// 0x286CF8: ret
	return;
}

void sub_286D00(X86Context& ctx, uint8_t* base) {
	// 0x286D00: movss xmm0, dword ptr [0x0056B114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B114u);
	// 0x286D08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x286D10: movss [0x0056B170], xmm0
	X86_MEM_WRITE_u32(base, 0x56B170u, ctx.xmm[0].u32[0]);
	// 0x286D18: ret
	return;
}

void sub_286D20(X86Context& ctx, uint8_t* base) {
	// 0x286D20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x286D28: movss [0x0056B1A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1A0u, ctx.xmm[0].u32[0]);
	// 0x286D30: ret
	return;
}

void sub_286D40(X86Context& ctx, uint8_t* base) {
	// 0x286D40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x286D48: movss [0x0056B18C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B18Cu, ctx.xmm[0].u32[0]);
	// 0x286D50: ret
	return;
}

void sub_286D60(X86Context& ctx, uint8_t* base) {
	// 0x286D60: movss xmm0, dword ptr [0x0056B18C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B18Cu);
	// 0x286D68: movss [0x0056B19C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B19Cu, ctx.xmm[0].u32[0]);
	// 0x286D70: ret
	return;
}

void sub_286D80(X86Context& ctx, uint8_t* base) {
	// 0x286D80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x286D88: movss [0x0056B100], xmm0
	X86_MEM_WRITE_u32(base, 0x56B100u, ctx.xmm[0].u32[0]);
	// 0x286D90: ret
	return;
}

void sub_286DA0(X86Context& ctx, uint8_t* base) {
	// 0x286DA0: movss xmm0, dword ptr [0x0056B114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B114u);
	// 0x286DA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x286DB0: movss [0x0056B194], xmm0
	X86_MEM_WRITE_u32(base, 0x56B194u, ctx.xmm[0].u32[0]);
	// 0x286DB8: ret
	return;
}

void sub_286DC0(X86Context& ctx, uint8_t* base) {
	// 0x286DC0: movss xmm0, dword ptr [0x0056B114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B114u);
	// 0x286DC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x286DD0: movss [0x0056B13C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B13Cu, ctx.xmm[0].u32[0]);
	// 0x286DD8: ret
	return;
}

void sub_286DE0(X86Context& ctx, uint8_t* base) {
	// 0x286DE0: movss xmm0, dword ptr [0x0056B114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B114u);
	// 0x286DE8: subss xmm0, [0x0056B13C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B13Cu);
	// 0x286DF0: movss [0x0056B11C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B11Cu, ctx.xmm[0].u32[0]);
	// 0x286DF8: ret
	return;
}

void sub_286E00(X86Context& ctx, uint8_t* base) {
	// 0x286E00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x286E08: movss [0x0056B164], xmm0
	X86_MEM_WRITE_u32(base, 0x56B164u, ctx.xmm[0].u32[0]);
	// 0x286E10: ret
	return;
}

void sub_286E20(X86Context& ctx, uint8_t* base) {
	// 0x286E20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x286E28: movss [0x0056B118], xmm0
	X86_MEM_WRITE_u32(base, 0x56B118u, ctx.xmm[0].u32[0]);
	// 0x286E30: ret
	return;
}

void sub_286E40(X86Context& ctx, uint8_t* base) {
	// 0x286E40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x286E48: movss [0x0056B128], xmm0
	X86_MEM_WRITE_u32(base, 0x56B128u, ctx.xmm[0].u32[0]);
	// 0x286E50: ret
	return;
}

void sub_286E60(X86Context& ctx, uint8_t* base) {
	// 0x286E60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x286E68: movss [0x0056B17C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B17Cu, ctx.xmm[0].u32[0]);
	// 0x286E70: ret
	return;
}

void sub_286E80(X86Context& ctx, uint8_t* base) {
	// 0x286E80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x286E88: movss [0x0056B160], xmm0
	X86_MEM_WRITE_u32(base, 0x56B160u, ctx.xmm[0].u32[0]);
	// 0x286E90: ret
	return;
}

void sub_286EA0(X86Context& ctx, uint8_t* base) {
	// 0x286EA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x286EA8: movss [0x0056B110], xmm0
	X86_MEM_WRITE_u32(base, 0x56B110u, ctx.xmm[0].u32[0]);
	// 0x286EB0: ret
	return;
}

void sub_286EC0(X86Context& ctx, uint8_t* base) {
	// 0x286EC0: movss xmm0, dword ptr [0x0056B128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B128u);
	// 0x286EC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286ED0: movss [0x0056B104], xmm0
	X86_MEM_WRITE_u32(base, 0x56B104u, ctx.xmm[0].u32[0]);
	// 0x286ED8: ret
	return;
}

void sub_286EE0(X86Context& ctx, uint8_t* base) {
	// 0x286EE0: movss xmm0, dword ptr [0x0056B17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B17Cu);
	// 0x286EE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x286EF0: movss [0x0056B148], xmm0
	X86_MEM_WRITE_u32(base, 0x56B148u, ctx.xmm[0].u32[0]);
	// 0x286EF8: ret
	return;
}

void sub_286F00(X86Context& ctx, uint8_t* base) {
	// 0x286F00: movss xmm0, dword ptr [0x0056B104]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B104u);
	// 0x286F08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x286F10: movss [0x0056B158], xmm0
	X86_MEM_WRITE_u32(base, 0x56B158u, ctx.xmm[0].u32[0]);
	// 0x286F18: ret
	return;
}

void sub_286F20(X86Context& ctx, uint8_t* base) {
	// 0x286F20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x286F28: movss [0x0056B0FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B0FCu, ctx.xmm[0].u32[0]);
	// 0x286F30: ret
	return;
}

void sub_286F40(X86Context& ctx, uint8_t* base) {
	// 0x286F40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x286F48: movss [0x0056B12C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B12Cu, ctx.xmm[0].u32[0]);
	// 0x286F50: ret
	return;
}

void sub_286F60(X86Context& ctx, uint8_t* base) {
	// 0x286F60: movss xmm0, dword ptr [0x0056B128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B128u);
	// 0x286F68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x286F70: movss [0x0056B138], xmm0
	X86_MEM_WRITE_u32(base, 0x56B138u, ctx.xmm[0].u32[0]);
	// 0x286F78: ret
	return;
}

void sub_286F80(X86Context& ctx, uint8_t* base) {
	// 0x286F80: movss xmm0, dword ptr [0x0056B17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B17Cu);
	// 0x286F88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x286F90: movss [0x0056B180], xmm0
	X86_MEM_WRITE_u32(base, 0x56B180u, ctx.xmm[0].u32[0]);
	// 0x286F98: ret
	return;
}

void sub_286FA0(X86Context& ctx, uint8_t* base) {
	// 0x286FA0: movss xmm0, dword ptr [0x0056B138]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B138u);
	// 0x286FA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286FB0: movss [0x0056B16C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B16Cu, ctx.xmm[0].u32[0]);
	// 0x286FB8: ret
	return;
}

void sub_286FC0(X86Context& ctx, uint8_t* base) {
	// 0x286FC0: movss xmm0, dword ptr [0x0056B180]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B180u);
	// 0x286FC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x286FD0: movss [0x0056B190], xmm0
	X86_MEM_WRITE_u32(base, 0x56B190u, ctx.xmm[0].u32[0]);
	// 0x286FD8: ret
	return;
}

void sub_286FE0(X86Context& ctx, uint8_t* base) {
	// 0x286FE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x286FE8: movss [0x0056B108], xmm0
	X86_MEM_WRITE_u32(base, 0x56B108u, ctx.xmm[0].u32[0]);
	// 0x286FF0: ret
	return;
}

void sub_287000(X86Context& ctx, uint8_t* base) {
	// 0x287000: movss xmm0, dword ptr [0x0056B128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B128u);
	// 0x287008: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287010: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x287018: movss [0x0056B178], xmm0
	X86_MEM_WRITE_u32(base, 0x56B178u, ctx.xmm[0].u32[0]);
	// 0x287020: ret
	return;
}

void sub_287030(X86Context& ctx, uint8_t* base) {
	// 0x287030: movss xmm0, dword ptr [0x0056B17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B17Cu);
	// 0x287038: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287040: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x287048: movss [0x0056B120], xmm0
	X86_MEM_WRITE_u32(base, 0x56B120u, ctx.xmm[0].u32[0]);
	// 0x287050: ret
	return;
}

void sub_287060(X86Context& ctx, uint8_t* base) {
	// 0x287060: movss xmm0, dword ptr [0x0056B128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B128u);
	// 0x287068: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287070: movss [0x0056B124], xmm0
	X86_MEM_WRITE_u32(base, 0x56B124u, ctx.xmm[0].u32[0]);
	// 0x287078: ret
	return;
}

void sub_287080(X86Context& ctx, uint8_t* base) {
	// 0x287080: movss xmm0, dword ptr [0x0056B17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B17Cu);
	// 0x287088: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287090: movss [0x0056B184], xmm0
	X86_MEM_WRITE_u32(base, 0x56B184u, ctx.xmm[0].u32[0]);
	// 0x287098: ret
	return;
}

void sub_2870A0(X86Context& ctx, uint8_t* base) {
	// 0x2870A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2870A8: movss [0x0056B10C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B10Cu, ctx.xmm[0].u32[0]);
	// 0x2870B0: ret
	return;
}

void sub_2870C0(X86Context& ctx, uint8_t* base) {
	// 0x2870C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2870C8: movss [0x0056B134], xmm0
	X86_MEM_WRITE_u32(base, 0x56B134u, ctx.xmm[0].u32[0]);
	// 0x2870D0: ret
	return;
}

void sub_2870E0(X86Context& ctx, uint8_t* base) {
	// 0x2870E0: movss xmm0, dword ptr [0x0056B10C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B10Cu);
	// 0x2870E8: movss [0x0056B198], xmm0
	X86_MEM_WRITE_u32(base, 0x56B198u, ctx.xmm[0].u32[0]);
	// 0x2870F0: ret
	return;
}

void sub_287100(X86Context& ctx, uint8_t* base) {
	// 0x287100: movss xmm0, dword ptr [0x0056B17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B17Cu);
	// 0x287108: subss xmm0, [0x0056B10C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B10Cu);
	// 0x287110: movss [0x0056B15C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B15Cu, ctx.xmm[0].u32[0]);
	// 0x287118: ret
	return;
}

void sub_287120(X86Context& ctx, uint8_t* base) {
	// 0x287120: movss xmm0, dword ptr [0x0056B15C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B15Cu);
	// 0x287128: subss xmm0, [0x0056B134]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B134u);
	// 0x287130: movss [0x0056B154], xmm0
	X86_MEM_WRITE_u32(base, 0x56B154u, ctx.xmm[0].u32[0]);
	// 0x287138: ret
	return;
}

void sub_287140(X86Context& ctx, uint8_t* base) {
	// 0x287140: movss xmm0, dword ptr [0x0056B184]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B184u);
	// 0x287148: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x287150: movss [0x0056B144], xmm0
	X86_MEM_WRITE_u32(base, 0x56B144u, ctx.xmm[0].u32[0]);
	// 0x287158: ret
	return;
}

void sub_287160(X86Context& ctx, uint8_t* base) {
	// 0x287160: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x287168: movss [0x0056B130], xmm0
	X86_MEM_WRITE_u32(base, 0x56B130u, ctx.xmm[0].u32[0]);
	// 0x287170: ret
	return;
}

void sub_287180(X86Context& ctx, uint8_t* base) {
	// 0x287180: movss xmm0, dword ptr [0x0056B144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B144u);
	// 0x287188: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x287190: movss [0x0056B174], xmm0
	X86_MEM_WRITE_u32(base, 0x56B174u, ctx.xmm[0].u32[0]);
	// 0x287198: ret
	return;
}

void sub_2871A0(X86Context& ctx, uint8_t* base) {
	// 0x2871A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2871A8: movss [0x0056B1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1F8u, ctx.xmm[0].u32[0]);
	// 0x2871B0: ret
	return;
}

void sub_2871C0(X86Context& ctx, uint8_t* base) {
	// 0x2871C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2871C8: movss [0x0056B214], xmm0
	X86_MEM_WRITE_u32(base, 0x56B214u, ctx.xmm[0].u32[0]);
	// 0x2871D0: ret
	return;
}

void sub_2871E0(X86Context& ctx, uint8_t* base) {
	// 0x2871E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2871E8: movss [0x0056B1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1ECu, ctx.xmm[0].u32[0]);
	// 0x2871F0: ret
	return;
}

void sub_287200(X86Context& ctx, uint8_t* base) {
	// 0x287200: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x287208: movss [0x0056B1A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1A4u, ctx.xmm[0].u32[0]);
	// 0x287210: ret
	return;
}

void sub_287220(X86Context& ctx, uint8_t* base) {
	// 0x287220: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x287228: movss [0x0056B1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1FCu, ctx.xmm[0].u32[0]);
	// 0x287230: ret
	return;
}

void sub_287240(X86Context& ctx, uint8_t* base) {
	// 0x287240: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x287248: movss [0x0056B1C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1C0u, ctx.xmm[0].u32[0]);
	// 0x287250: ret
	return;
}

void sub_287260(X86Context& ctx, uint8_t* base) {
	// 0x287260: movss xmm0, dword ptr [0x0056B1FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1FCu);
	// 0x287268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287270: movss [0x0056B234], xmm0
	X86_MEM_WRITE_u32(base, 0x56B234u, ctx.xmm[0].u32[0]);
	// 0x287278: ret
	return;
}

void sub_287280(X86Context& ctx, uint8_t* base) {
	// 0x287280: movss xmm0, dword ptr [0x0056B1C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1C0u);
	// 0x287288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x287290: movss [0x0056B21C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B21Cu, ctx.xmm[0].u32[0]);
	// 0x287298: ret
	return;
}

void sub_2872A0(X86Context& ctx, uint8_t* base) {
	// 0x2872A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2872A8: movss [0x0056B24C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B24Cu, ctx.xmm[0].u32[0]);
	// 0x2872B0: ret
	return;
}

void sub_2872C0(X86Context& ctx, uint8_t* base) {
	// 0x2872C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2872C8: movss [0x0056B238], xmm0
	X86_MEM_WRITE_u32(base, 0x56B238u, ctx.xmm[0].u32[0]);
	// 0x2872D0: ret
	return;
}

void sub_2872E0(X86Context& ctx, uint8_t* base) {
	// 0x2872E0: movss xmm0, dword ptr [0x0056B238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B238u);
	// 0x2872E8: movss [0x0056B248], xmm0
	X86_MEM_WRITE_u32(base, 0x56B248u, ctx.xmm[0].u32[0]);
	// 0x2872F0: ret
	return;
}

void sub_287300(X86Context& ctx, uint8_t* base) {
	// 0x287300: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x287308: movss [0x0056B1AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1ACu, ctx.xmm[0].u32[0]);
	// 0x287310: ret
	return;
}

void sub_287320(X86Context& ctx, uint8_t* base) {
	// 0x287320: movss xmm0, dword ptr [0x0056B1C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1C0u);
	// 0x287328: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x287330: movss [0x0056B240], xmm0
	X86_MEM_WRITE_u32(base, 0x56B240u, ctx.xmm[0].u32[0]);
	// 0x287338: ret
	return;
}

void sub_287340(X86Context& ctx, uint8_t* base) {
	// 0x287340: movss xmm0, dword ptr [0x0056B1C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1C0u);
	// 0x287348: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x287350: movss [0x0056B1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1E8u, ctx.xmm[0].u32[0]);
	// 0x287358: ret
	return;
}

void sub_287360(X86Context& ctx, uint8_t* base) {
	// 0x287360: movss xmm0, dword ptr [0x0056B1C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1C0u);
	// 0x287368: subss xmm0, [0x0056B1E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B1E8u);
	// 0x287370: movss [0x0056B1C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1C8u, ctx.xmm[0].u32[0]);
	// 0x287378: ret
	return;
}

void sub_287380(X86Context& ctx, uint8_t* base) {
	// 0x287380: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x287388: movss [0x0056B210], xmm0
	X86_MEM_WRITE_u32(base, 0x56B210u, ctx.xmm[0].u32[0]);
	// 0x287390: ret
	return;
}

void sub_2873A0(X86Context& ctx, uint8_t* base) {
	// 0x2873A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2873A8: movss [0x0056B1C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1C4u, ctx.xmm[0].u32[0]);
	// 0x2873B0: ret
	return;
}

void sub_2873C0(X86Context& ctx, uint8_t* base) {
	// 0x2873C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2873C8: movss [0x0056B1D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1D4u, ctx.xmm[0].u32[0]);
	// 0x2873D0: ret
	return;
}

void sub_2873E0(X86Context& ctx, uint8_t* base) {
	// 0x2873E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2873E8: movss [0x0056B228], xmm0
	X86_MEM_WRITE_u32(base, 0x56B228u, ctx.xmm[0].u32[0]);
	// 0x2873F0: ret
	return;
}

void sub_287400(X86Context& ctx, uint8_t* base) {
	// 0x287400: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x287408: movss [0x0056B20C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B20Cu, ctx.xmm[0].u32[0]);
	// 0x287410: ret
	return;
}

void sub_287420(X86Context& ctx, uint8_t* base) {
	// 0x287420: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x287428: movss [0x0056B1BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1BCu, ctx.xmm[0].u32[0]);
	// 0x287430: ret
	return;
}

void sub_287440(X86Context& ctx, uint8_t* base) {
	// 0x287440: movss xmm0, dword ptr [0x0056B1D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1D4u);
	// 0x287448: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287450: movss [0x0056B1B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1B0u, ctx.xmm[0].u32[0]);
	// 0x287458: ret
	return;
}

void sub_287460(X86Context& ctx, uint8_t* base) {
	// 0x287460: movss xmm0, dword ptr [0x0056B228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B228u);
	// 0x287468: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x287470: movss [0x0056B1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1F4u, ctx.xmm[0].u32[0]);
	// 0x287478: ret
	return;
}

void sub_287480(X86Context& ctx, uint8_t* base) {
	// 0x287480: movss xmm0, dword ptr [0x0056B1B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1B0u);
	// 0x287488: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287490: movss [0x0056B204], xmm0
	X86_MEM_WRITE_u32(base, 0x56B204u, ctx.xmm[0].u32[0]);
	// 0x287498: ret
	return;
}

void sub_2874A0(X86Context& ctx, uint8_t* base) {
	// 0x2874A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2874A8: movss [0x0056B1A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1A8u, ctx.xmm[0].u32[0]);
	// 0x2874B0: ret
	return;
}

void sub_2874C0(X86Context& ctx, uint8_t* base) {
	// 0x2874C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2874C8: movss [0x0056B1D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1D8u, ctx.xmm[0].u32[0]);
	// 0x2874D0: ret
	return;
}

void sub_2874E0(X86Context& ctx, uint8_t* base) {
	// 0x2874E0: movss xmm0, dword ptr [0x0056B1D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1D4u);
	// 0x2874E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2874F0: movss [0x0056B1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1E4u, ctx.xmm[0].u32[0]);
	// 0x2874F8: ret
	return;
}

void sub_287500(X86Context& ctx, uint8_t* base) {
	// 0x287500: movss xmm0, dword ptr [0x0056B228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B228u);
	// 0x287508: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x287510: movss [0x0056B22C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B22Cu, ctx.xmm[0].u32[0]);
	// 0x287518: ret
	return;
}

void sub_287520(X86Context& ctx, uint8_t* base) {
	// 0x287520: movss xmm0, dword ptr [0x0056B1E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1E4u);
	// 0x287528: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287530: movss [0x0056B218], xmm0
	X86_MEM_WRITE_u32(base, 0x56B218u, ctx.xmm[0].u32[0]);
	// 0x287538: ret
	return;
}

void sub_287540(X86Context& ctx, uint8_t* base) {
	// 0x287540: movss xmm0, dword ptr [0x0056B22C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B22Cu);
	// 0x287548: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287550: movss [0x0056B23C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B23Cu, ctx.xmm[0].u32[0]);
	// 0x287558: ret
	return;
}

void sub_287560(X86Context& ctx, uint8_t* base) {
	// 0x287560: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x287568: movss [0x0056B1B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1B4u, ctx.xmm[0].u32[0]);
	// 0x287570: ret
	return;
}

void sub_287580(X86Context& ctx, uint8_t* base) {
	// 0x287580: movss xmm0, dword ptr [0x0056B1D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1D4u);
	// 0x287588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287590: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x287598: movss [0x0056B224], xmm0
	X86_MEM_WRITE_u32(base, 0x56B224u, ctx.xmm[0].u32[0]);
	// 0x2875A0: ret
	return;
}

void sub_2875B0(X86Context& ctx, uint8_t* base) {
	// 0x2875B0: movss xmm0, dword ptr [0x0056B228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B228u);
	// 0x2875B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2875C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2875C8: movss [0x0056B1CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1CCu, ctx.xmm[0].u32[0]);
	// 0x2875D0: ret
	return;
}

void sub_2875E0(X86Context& ctx, uint8_t* base) {
	// 0x2875E0: movss xmm0, dword ptr [0x0056B1D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1D4u);
	// 0x2875E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2875F0: movss [0x0056B1D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1D0u, ctx.xmm[0].u32[0]);
	// 0x2875F8: ret
	return;
}

void sub_287600(X86Context& ctx, uint8_t* base) {
	// 0x287600: movss xmm0, dword ptr [0x0056B228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B228u);
	// 0x287608: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287610: movss [0x0056B230], xmm0
	X86_MEM_WRITE_u32(base, 0x56B230u, ctx.xmm[0].u32[0]);
	// 0x287618: ret
	return;
}

void sub_287620(X86Context& ctx, uint8_t* base) {
	// 0x287620: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x287628: movss [0x0056B1B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1B8u, ctx.xmm[0].u32[0]);
	// 0x287630: ret
	return;
}

void sub_287640(X86Context& ctx, uint8_t* base) {
	// 0x287640: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x287648: movss [0x0056B1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1E0u, ctx.xmm[0].u32[0]);
	// 0x287650: ret
	return;
}

void sub_287660(X86Context& ctx, uint8_t* base) {
	// 0x287660: movss xmm0, dword ptr [0x0056B1B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1B8u);
	// 0x287668: movss [0x0056B244], xmm0
	X86_MEM_WRITE_u32(base, 0x56B244u, ctx.xmm[0].u32[0]);
	// 0x287670: ret
	return;
}

void sub_287680(X86Context& ctx, uint8_t* base) {
	// 0x287680: movss xmm0, dword ptr [0x0056B228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B228u);
	// 0x287688: subss xmm0, [0x0056B1B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B1B8u);
	// 0x287690: movss [0x0056B208], xmm0
	X86_MEM_WRITE_u32(base, 0x56B208u, ctx.xmm[0].u32[0]);
	// 0x287698: ret
	return;
}

void sub_2876A0(X86Context& ctx, uint8_t* base) {
	// 0x2876A0: movss xmm0, dword ptr [0x0056B208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B208u);
	// 0x2876A8: subss xmm0, [0x0056B1E0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B1E0u);
	// 0x2876B0: movss [0x0056B200], xmm0
	X86_MEM_WRITE_u32(base, 0x56B200u, ctx.xmm[0].u32[0]);
	// 0x2876B8: ret
	return;
}

void sub_2876C0(X86Context& ctx, uint8_t* base) {
	// 0x2876C0: movss xmm0, dword ptr [0x0056B230]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B230u);
	// 0x2876C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2876D0: movss [0x0056B1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1F0u, ctx.xmm[0].u32[0]);
	// 0x2876D8: ret
	return;
}

void sub_2876E0(X86Context& ctx, uint8_t* base) {
	// 0x2876E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2876E8: movss [0x0056B1DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B1DCu, ctx.xmm[0].u32[0]);
	// 0x2876F0: ret
	return;
}

void sub_287700(X86Context& ctx, uint8_t* base) {
	// 0x287700: movss xmm0, dword ptr [0x0056B1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B1F0u);
	// 0x287708: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x287710: movss [0x0056B220], xmm0
	X86_MEM_WRITE_u32(base, 0x56B220u, ctx.xmm[0].u32[0]);
	// 0x287718: ret
	return;
}

void sub_287720(X86Context& ctx, uint8_t* base) {
	// 0x287720: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x287728: movss [0x0056B2A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2A4u, ctx.xmm[0].u32[0]);
	// 0x287730: ret
	return;
}

void sub_287740(X86Context& ctx, uint8_t* base) {
	// 0x287740: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x287748: movss [0x0056B2C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2C0u, ctx.xmm[0].u32[0]);
	// 0x287750: ret
	return;
}

void sub_287760(X86Context& ctx, uint8_t* base) {
	// 0x287760: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x287768: movss [0x0056B298], xmm0
	X86_MEM_WRITE_u32(base, 0x56B298u, ctx.xmm[0].u32[0]);
	// 0x287770: ret
	return;
}

void sub_287780(X86Context& ctx, uint8_t* base) {
	// 0x287780: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x287788: movss [0x0056B250], xmm0
	X86_MEM_WRITE_u32(base, 0x56B250u, ctx.xmm[0].u32[0]);
	// 0x287790: ret
	return;
}

void sub_2877A0(X86Context& ctx, uint8_t* base) {
	// 0x2877A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2877A8: movss [0x0056B2A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2A8u, ctx.xmm[0].u32[0]);
	// 0x2877B0: ret
	return;
}

void sub_2877C0(X86Context& ctx, uint8_t* base) {
	// 0x2877C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2877C8: movss [0x0056B26C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B26Cu, ctx.xmm[0].u32[0]);
	// 0x2877D0: ret
	return;
}

void sub_2877E0(X86Context& ctx, uint8_t* base) {
	// 0x2877E0: movss xmm0, dword ptr [0x0056B2A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2A8u);
	// 0x2877E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2877F0: movss [0x0056B2E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2E0u, ctx.xmm[0].u32[0]);
	// 0x2877F8: ret
	return;
}

void sub_287800(X86Context& ctx, uint8_t* base) {
	// 0x287800: movss xmm0, dword ptr [0x0056B26C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B26Cu);
	// 0x287808: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x287810: movss [0x0056B2C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2C8u, ctx.xmm[0].u32[0]);
	// 0x287818: ret
	return;
}

void sub_287820(X86Context& ctx, uint8_t* base) {
	// 0x287820: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x287828: movss [0x0056B2F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2F8u, ctx.xmm[0].u32[0]);
	// 0x287830: ret
	return;
}

void sub_287840(X86Context& ctx, uint8_t* base) {
	// 0x287840: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x287848: movss [0x0056B2E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2E4u, ctx.xmm[0].u32[0]);
	// 0x287850: ret
	return;
}

void sub_287860(X86Context& ctx, uint8_t* base) {
	// 0x287860: movss xmm0, dword ptr [0x0056B2E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2E4u);
	// 0x287868: movss [0x0056B2F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2F4u, ctx.xmm[0].u32[0]);
	// 0x287870: ret
	return;
}

void sub_287880(X86Context& ctx, uint8_t* base) {
	// 0x287880: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x287888: movss [0x0056B258], xmm0
	X86_MEM_WRITE_u32(base, 0x56B258u, ctx.xmm[0].u32[0]);
	// 0x287890: ret
	return;
}

void sub_2878A0(X86Context& ctx, uint8_t* base) {
	// 0x2878A0: movss xmm0, dword ptr [0x0056B26C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B26Cu);
	// 0x2878A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2878B0: movss [0x0056B2EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2ECu, ctx.xmm[0].u32[0]);
	// 0x2878B8: ret
	return;
}

void sub_2878C0(X86Context& ctx, uint8_t* base) {
	// 0x2878C0: movss xmm0, dword ptr [0x0056B26C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B26Cu);
	// 0x2878C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2878D0: movss [0x0056B294], xmm0
	X86_MEM_WRITE_u32(base, 0x56B294u, ctx.xmm[0].u32[0]);
	// 0x2878D8: ret
	return;
}

void sub_2878E0(X86Context& ctx, uint8_t* base) {
	// 0x2878E0: movss xmm0, dword ptr [0x0056B26C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B26Cu);
	// 0x2878E8: subss xmm0, [0x0056B294]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B294u);
	// 0x2878F0: movss [0x0056B274], xmm0
	X86_MEM_WRITE_u32(base, 0x56B274u, ctx.xmm[0].u32[0]);
	// 0x2878F8: ret
	return;
}

void sub_287900(X86Context& ctx, uint8_t* base) {
	// 0x287900: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x287908: movss [0x0056B2BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2BCu, ctx.xmm[0].u32[0]);
	// 0x287910: ret
	return;
}

void sub_287920(X86Context& ctx, uint8_t* base) {
	// 0x287920: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x287928: movss [0x0056B270], xmm0
	X86_MEM_WRITE_u32(base, 0x56B270u, ctx.xmm[0].u32[0]);
	// 0x287930: ret
	return;
}

void sub_287940(X86Context& ctx, uint8_t* base) {
	// 0x287940: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x287948: movss [0x0056B280], xmm0
	X86_MEM_WRITE_u32(base, 0x56B280u, ctx.xmm[0].u32[0]);
	// 0x287950: ret
	return;
}

void sub_287960(X86Context& ctx, uint8_t* base) {
	// 0x287960: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x287968: movss [0x0056B2D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2D4u, ctx.xmm[0].u32[0]);
	// 0x287970: ret
	return;
}

