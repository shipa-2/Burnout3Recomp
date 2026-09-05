#include "x86_recomp_shared.h"

void sub_28BB00(X86Context& ctx, uint8_t* base) {
	// 0x28BB00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28BB08: movss [0x0056BACC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BACCu, ctx.xmm[0].u32[0]);
	// 0x28BB10: ret
	return;
}

void sub_28BB20(X86Context& ctx, uint8_t* base) {
	// 0x28BB20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28BB28: movss [0x0056BA80], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA80u, ctx.xmm[0].u32[0]);
	// 0x28BB30: ret
	return;
}

void sub_28BB40(X86Context& ctx, uint8_t* base) {
	// 0x28BB40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28BB48: movss [0x0056BA90], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA90u, ctx.xmm[0].u32[0]);
	// 0x28BB50: ret
	return;
}

void sub_28BB60(X86Context& ctx, uint8_t* base) {
	// 0x28BB60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28BB68: movss [0x0056BAE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAE4u, ctx.xmm[0].u32[0]);
	// 0x28BB70: ret
	return;
}

void sub_28BB80(X86Context& ctx, uint8_t* base) {
	// 0x28BB80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28BB88: movss [0x0056BAC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAC8u, ctx.xmm[0].u32[0]);
	// 0x28BB90: ret
	return;
}

void sub_28BBA0(X86Context& ctx, uint8_t* base) {
	// 0x28BBA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28BBA8: movss [0x0056BA78], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA78u, ctx.xmm[0].u32[0]);
	// 0x28BBB0: ret
	return;
}

void sub_28BBC0(X86Context& ctx, uint8_t* base) {
	// 0x28BBC0: movss xmm0, dword ptr [0x0056BA90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA90u);
	// 0x28BBC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28BBD0: movss [0x0056BA6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA6Cu, ctx.xmm[0].u32[0]);
	// 0x28BBD8: ret
	return;
}

void sub_28BBE0(X86Context& ctx, uint8_t* base) {
	// 0x28BBE0: movss xmm0, dword ptr [0x0056BAE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAE4u);
	// 0x28BBE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28BBF0: movss [0x0056BAB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAB0u, ctx.xmm[0].u32[0]);
	// 0x28BBF8: ret
	return;
}

void sub_28BC00(X86Context& ctx, uint8_t* base) {
	// 0x28BC00: movss xmm0, dword ptr [0x0056BA6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA6Cu);
	// 0x28BC08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28BC10: movss [0x0056BAC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAC0u, ctx.xmm[0].u32[0]);
	// 0x28BC18: ret
	return;
}

void sub_28BC20(X86Context& ctx, uint8_t* base) {
	// 0x28BC20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28BC28: movss [0x0056BA64], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA64u, ctx.xmm[0].u32[0]);
	// 0x28BC30: ret
	return;
}

void sub_28BC40(X86Context& ctx, uint8_t* base) {
	// 0x28BC40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28BC48: movss [0x0056BA94], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA94u, ctx.xmm[0].u32[0]);
	// 0x28BC50: ret
	return;
}

void sub_28BC60(X86Context& ctx, uint8_t* base) {
	// 0x28BC60: movss xmm0, dword ptr [0x0056BA90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA90u);
	// 0x28BC68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28BC70: movss [0x0056BAA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAA0u, ctx.xmm[0].u32[0]);
	// 0x28BC78: ret
	return;
}

void sub_28BC80(X86Context& ctx, uint8_t* base) {
	// 0x28BC80: movss xmm0, dword ptr [0x0056BAE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAE4u);
	// 0x28BC88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28BC90: movss [0x0056BAE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAE8u, ctx.xmm[0].u32[0]);
	// 0x28BC98: ret
	return;
}

void sub_28BCA0(X86Context& ctx, uint8_t* base) {
	// 0x28BCA0: movss xmm0, dword ptr [0x0056BAA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAA0u);
	// 0x28BCA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28BCB0: movss [0x0056BAD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAD4u, ctx.xmm[0].u32[0]);
	// 0x28BCB8: ret
	return;
}

void sub_28BCC0(X86Context& ctx, uint8_t* base) {
	// 0x28BCC0: movss xmm0, dword ptr [0x0056BAE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAE8u);
	// 0x28BCC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28BCD0: movss [0x0056BAF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAF8u, ctx.xmm[0].u32[0]);
	// 0x28BCD8: ret
	return;
}

void sub_28BCE0(X86Context& ctx, uint8_t* base) {
	// 0x28BCE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28BCE8: movss [0x0056BA70], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA70u, ctx.xmm[0].u32[0]);
	// 0x28BCF0: ret
	return;
}

void sub_28BD00(X86Context& ctx, uint8_t* base) {
	// 0x28BD00: movss xmm0, dword ptr [0x0056BA90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA90u);
	// 0x28BD08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28BD10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28BD18: movss [0x0056BAE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAE0u, ctx.xmm[0].u32[0]);
	// 0x28BD20: ret
	return;
}

void sub_28BD30(X86Context& ctx, uint8_t* base) {
	// 0x28BD30: movss xmm0, dword ptr [0x0056BAE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAE4u);
	// 0x28BD38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28BD40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28BD48: movss [0x0056BA88], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA88u, ctx.xmm[0].u32[0]);
	// 0x28BD50: ret
	return;
}

void sub_28BD60(X86Context& ctx, uint8_t* base) {
	// 0x28BD60: movss xmm0, dword ptr [0x0056BA90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA90u);
	// 0x28BD68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28BD70: movss [0x0056BA8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA8Cu, ctx.xmm[0].u32[0]);
	// 0x28BD78: ret
	return;
}

void sub_28BD80(X86Context& ctx, uint8_t* base) {
	// 0x28BD80: movss xmm0, dword ptr [0x0056BAE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAE4u);
	// 0x28BD88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28BD90: movss [0x0056BAEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAECu, ctx.xmm[0].u32[0]);
	// 0x28BD98: ret
	return;
}

void sub_28BDA0(X86Context& ctx, uint8_t* base) {
	// 0x28BDA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28BDA8: movss [0x0056BA74], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA74u, ctx.xmm[0].u32[0]);
	// 0x28BDB0: ret
	return;
}

void sub_28BDC0(X86Context& ctx, uint8_t* base) {
	// 0x28BDC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28BDC8: movss [0x0056BA9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA9Cu, ctx.xmm[0].u32[0]);
	// 0x28BDD0: ret
	return;
}

void sub_28BDE0(X86Context& ctx, uint8_t* base) {
	// 0x28BDE0: movss xmm0, dword ptr [0x0056BA74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA74u);
	// 0x28BDE8: movss [0x0056BB00], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB00u, ctx.xmm[0].u32[0]);
	// 0x28BDF0: ret
	return;
}

void sub_28BE00(X86Context& ctx, uint8_t* base) {
	// 0x28BE00: movss xmm0, dword ptr [0x0056BAE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAE4u);
	// 0x28BE08: subss xmm0, [0x0056BA74]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BA74u);
	// 0x28BE10: movss [0x0056BAC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAC4u, ctx.xmm[0].u32[0]);
	// 0x28BE18: ret
	return;
}

void sub_28BE20(X86Context& ctx, uint8_t* base) {
	// 0x28BE20: movss xmm0, dword ptr [0x0056BAC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAC4u);
	// 0x28BE28: subss xmm0, [0x0056BA9C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BA9Cu);
	// 0x28BE30: movss [0x0056BABC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BABCu, ctx.xmm[0].u32[0]);
	// 0x28BE38: ret
	return;
}

void sub_28BE40(X86Context& ctx, uint8_t* base) {
	// 0x28BE40: movss xmm0, dword ptr [0x0056BAEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAECu);
	// 0x28BE48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28BE50: movss [0x0056BAAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAACu, ctx.xmm[0].u32[0]);
	// 0x28BE58: ret
	return;
}

void sub_28BE60(X86Context& ctx, uint8_t* base) {
	// 0x28BE60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28BE68: movss [0x0056BA98], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA98u, ctx.xmm[0].u32[0]);
	// 0x28BE70: ret
	return;
}

void sub_28BE80(X86Context& ctx, uint8_t* base) {
	// 0x28BE80: movss xmm0, dword ptr [0x0056BAAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAACu);
	// 0x28BE88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28BE90: movss [0x0056BADC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BADCu, ctx.xmm[0].u32[0]);
	// 0x28BE98: ret
	return;
}

void sub_28BEA0(X86Context& ctx, uint8_t* base) {
	// 0x28BEA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28BEA8: movss [0x0056BB60], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB60u, ctx.xmm[0].u32[0]);
	// 0x28BEB0: ret
	return;
}

void sub_28BEC0(X86Context& ctx, uint8_t* base) {
	// 0x28BEC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28BEC8: movss [0x0056BB7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB7Cu, ctx.xmm[0].u32[0]);
	// 0x28BED0: ret
	return;
}

void sub_28BEE0(X86Context& ctx, uint8_t* base) {
	// 0x28BEE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28BEE8: movss [0x0056BB54], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB54u, ctx.xmm[0].u32[0]);
	// 0x28BEF0: ret
	return;
}

void sub_28BF00(X86Context& ctx, uint8_t* base) {
	// 0x28BF00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28BF08: movss [0x0056BB0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB0Cu, ctx.xmm[0].u32[0]);
	// 0x28BF10: ret
	return;
}

void sub_28BF20(X86Context& ctx, uint8_t* base) {
	// 0x28BF20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28BF28: movss [0x0056BB64], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB64u, ctx.xmm[0].u32[0]);
	// 0x28BF30: ret
	return;
}

void sub_28BF40(X86Context& ctx, uint8_t* base) {
	// 0x28BF40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28BF48: movss [0x0056BB28], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB28u, ctx.xmm[0].u32[0]);
	// 0x28BF50: ret
	return;
}

void sub_28BF60(X86Context& ctx, uint8_t* base) {
	// 0x28BF60: movss xmm0, dword ptr [0x0056BB64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB64u);
	// 0x28BF68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28BF70: movss [0x0056BB9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB9Cu, ctx.xmm[0].u32[0]);
	// 0x28BF78: ret
	return;
}

void sub_28BF80(X86Context& ctx, uint8_t* base) {
	// 0x28BF80: movss xmm0, dword ptr [0x0056BB28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB28u);
	// 0x28BF88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28BF90: movss [0x0056BB84], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB84u, ctx.xmm[0].u32[0]);
	// 0x28BF98: ret
	return;
}

void sub_28BFA0(X86Context& ctx, uint8_t* base) {
	// 0x28BFA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28BFA8: movss [0x0056BBB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBB4u, ctx.xmm[0].u32[0]);
	// 0x28BFB0: ret
	return;
}

void sub_28BFC0(X86Context& ctx, uint8_t* base) {
	// 0x28BFC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28BFC8: movss [0x0056BBA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBA0u, ctx.xmm[0].u32[0]);
	// 0x28BFD0: ret
	return;
}

void sub_28BFE0(X86Context& ctx, uint8_t* base) {
	// 0x28BFE0: movss xmm0, dword ptr [0x0056BBA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBA0u);
	// 0x28BFE8: movss [0x0056BBB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBB0u, ctx.xmm[0].u32[0]);
	// 0x28BFF0: ret
	return;
}

void sub_28C000(X86Context& ctx, uint8_t* base) {
	// 0x28C000: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28C008: movss [0x0056BB14], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB14u, ctx.xmm[0].u32[0]);
	// 0x28C010: ret
	return;
}

void sub_28C020(X86Context& ctx, uint8_t* base) {
	// 0x28C020: movss xmm0, dword ptr [0x0056BB28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB28u);
	// 0x28C028: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28C030: movss [0x0056BBA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBA8u, ctx.xmm[0].u32[0]);
	// 0x28C038: ret
	return;
}

void sub_28C040(X86Context& ctx, uint8_t* base) {
	// 0x28C040: movss xmm0, dword ptr [0x0056BB28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB28u);
	// 0x28C048: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28C050: movss [0x0056BB50], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB50u, ctx.xmm[0].u32[0]);
	// 0x28C058: ret
	return;
}

void sub_28C060(X86Context& ctx, uint8_t* base) {
	// 0x28C060: movss xmm0, dword ptr [0x0056BB28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB28u);
	// 0x28C068: subss xmm0, [0x0056BB50]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BB50u);
	// 0x28C070: movss [0x0056BB30], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB30u, ctx.xmm[0].u32[0]);
	// 0x28C078: ret
	return;
}

void sub_28C080(X86Context& ctx, uint8_t* base) {
	// 0x28C080: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28C088: movss [0x0056BB78], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB78u, ctx.xmm[0].u32[0]);
	// 0x28C090: ret
	return;
}

void sub_28C0A0(X86Context& ctx, uint8_t* base) {
	// 0x28C0A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28C0A8: movss [0x0056BB2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB2Cu, ctx.xmm[0].u32[0]);
	// 0x28C0B0: ret
	return;
}

void sub_28C0C0(X86Context& ctx, uint8_t* base) {
	// 0x28C0C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28C0C8: movss [0x0056BB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB3Cu, ctx.xmm[0].u32[0]);
	// 0x28C0D0: ret
	return;
}

void sub_28C0E0(X86Context& ctx, uint8_t* base) {
	// 0x28C0E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28C0E8: movss [0x0056BB90], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB90u, ctx.xmm[0].u32[0]);
	// 0x28C0F0: ret
	return;
}

void sub_28C100(X86Context& ctx, uint8_t* base) {
	// 0x28C100: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28C108: movss [0x0056BB74], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB74u, ctx.xmm[0].u32[0]);
	// 0x28C110: ret
	return;
}

void sub_28C120(X86Context& ctx, uint8_t* base) {
	// 0x28C120: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28C128: movss [0x0056BB24], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB24u, ctx.xmm[0].u32[0]);
	// 0x28C130: ret
	return;
}

void sub_28C140(X86Context& ctx, uint8_t* base) {
	// 0x28C140: movss xmm0, dword ptr [0x0056BB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB3Cu);
	// 0x28C148: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28C150: movss [0x0056BB18], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB18u, ctx.xmm[0].u32[0]);
	// 0x28C158: ret
	return;
}

void sub_28C160(X86Context& ctx, uint8_t* base) {
	// 0x28C160: movss xmm0, dword ptr [0x0056BB90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB90u);
	// 0x28C168: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28C170: movss [0x0056BB5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB5Cu, ctx.xmm[0].u32[0]);
	// 0x28C178: ret
	return;
}

void sub_28C180(X86Context& ctx, uint8_t* base) {
	// 0x28C180: movss xmm0, dword ptr [0x0056BB18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB18u);
	// 0x28C188: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28C190: movss [0x0056BB6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB6Cu, ctx.xmm[0].u32[0]);
	// 0x28C198: ret
	return;
}

void sub_28C1A0(X86Context& ctx, uint8_t* base) {
	// 0x28C1A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28C1A8: movss [0x0056BB10], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB10u, ctx.xmm[0].u32[0]);
	// 0x28C1B0: ret
	return;
}

void sub_28C1C0(X86Context& ctx, uint8_t* base) {
	// 0x28C1C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28C1C8: movss [0x0056BB40], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB40u, ctx.xmm[0].u32[0]);
	// 0x28C1D0: ret
	return;
}

void sub_28C1E0(X86Context& ctx, uint8_t* base) {
	// 0x28C1E0: movss xmm0, dword ptr [0x0056BB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB3Cu);
	// 0x28C1E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28C1F0: movss [0x0056BB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB4Cu, ctx.xmm[0].u32[0]);
	// 0x28C1F8: ret
	return;
}

void sub_28C200(X86Context& ctx, uint8_t* base) {
	// 0x28C200: movss xmm0, dword ptr [0x0056BB90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB90u);
	// 0x28C208: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28C210: movss [0x0056BB94], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB94u, ctx.xmm[0].u32[0]);
	// 0x28C218: ret
	return;
}

void sub_28C220(X86Context& ctx, uint8_t* base) {
	// 0x28C220: movss xmm0, dword ptr [0x0056BB4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB4Cu);
	// 0x28C228: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C230: movss [0x0056BB80], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB80u, ctx.xmm[0].u32[0]);
	// 0x28C238: ret
	return;
}

void sub_28C240(X86Context& ctx, uint8_t* base) {
	// 0x28C240: movss xmm0, dword ptr [0x0056BB94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB94u);
	// 0x28C248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C250: movss [0x0056BBA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBA4u, ctx.xmm[0].u32[0]);
	// 0x28C258: ret
	return;
}

void sub_28C260(X86Context& ctx, uint8_t* base) {
	// 0x28C260: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28C268: movss [0x0056BB1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB1Cu, ctx.xmm[0].u32[0]);
	// 0x28C270: ret
	return;
}

void sub_28C280(X86Context& ctx, uint8_t* base) {
	// 0x28C280: movss xmm0, dword ptr [0x0056BB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB3Cu);
	// 0x28C288: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C290: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28C298: movss [0x0056BB8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB8Cu, ctx.xmm[0].u32[0]);
	// 0x28C2A0: ret
	return;
}

void sub_28C2B0(X86Context& ctx, uint8_t* base) {
	// 0x28C2B0: movss xmm0, dword ptr [0x0056BB90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB90u);
	// 0x28C2B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C2C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28C2C8: movss [0x0056BB34], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB34u, ctx.xmm[0].u32[0]);
	// 0x28C2D0: ret
	return;
}

void sub_28C2E0(X86Context& ctx, uint8_t* base) {
	// 0x28C2E0: movss xmm0, dword ptr [0x0056BB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB3Cu);
	// 0x28C2E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C2F0: movss [0x0056BB38], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB38u, ctx.xmm[0].u32[0]);
	// 0x28C2F8: ret
	return;
}

void sub_28C300(X86Context& ctx, uint8_t* base) {
	// 0x28C300: movss xmm0, dword ptr [0x0056BB90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB90u);
	// 0x28C308: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C310: movss [0x0056BB98], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB98u, ctx.xmm[0].u32[0]);
	// 0x28C318: ret
	return;
}

void sub_28C320(X86Context& ctx, uint8_t* base) {
	// 0x28C320: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28C328: movss [0x0056BB20], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB20u, ctx.xmm[0].u32[0]);
	// 0x28C330: ret
	return;
}

void sub_28C340(X86Context& ctx, uint8_t* base) {
	// 0x28C340: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28C348: movss [0x0056BB48], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB48u, ctx.xmm[0].u32[0]);
	// 0x28C350: ret
	return;
}

void sub_28C360(X86Context& ctx, uint8_t* base) {
	// 0x28C360: movss xmm0, dword ptr [0x0056BB20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB20u);
	// 0x28C368: movss [0x0056BBAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBACu, ctx.xmm[0].u32[0]);
	// 0x28C370: ret
	return;
}

void sub_28C380(X86Context& ctx, uint8_t* base) {
	// 0x28C380: movss xmm0, dword ptr [0x0056BB90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB90u);
	// 0x28C388: subss xmm0, [0x0056BB20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BB20u);
	// 0x28C390: movss [0x0056BB70], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB70u, ctx.xmm[0].u32[0]);
	// 0x28C398: ret
	return;
}

void sub_28C3A0(X86Context& ctx, uint8_t* base) {
	// 0x28C3A0: movss xmm0, dword ptr [0x0056BB70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB70u);
	// 0x28C3A8: subss xmm0, [0x0056BB48]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BB48u);
	// 0x28C3B0: movss [0x0056BB68], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB68u, ctx.xmm[0].u32[0]);
	// 0x28C3B8: ret
	return;
}

void sub_28C3C0(X86Context& ctx, uint8_t* base) {
	// 0x28C3C0: movss xmm0, dword ptr [0x0056BB98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB98u);
	// 0x28C3C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28C3D0: movss [0x0056BB58], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB58u, ctx.xmm[0].u32[0]);
	// 0x28C3D8: ret
	return;
}

void sub_28C3E0(X86Context& ctx, uint8_t* base) {
	// 0x28C3E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28C3E8: movss [0x0056BB44], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB44u, ctx.xmm[0].u32[0]);
	// 0x28C3F0: ret
	return;
}

void sub_28C400(X86Context& ctx, uint8_t* base) {
	// 0x28C400: movss xmm0, dword ptr [0x0056BB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BB58u);
	// 0x28C408: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28C410: movss [0x0056BB88], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB88u, ctx.xmm[0].u32[0]);
	// 0x28C418: ret
	return;
}

void sub_28C420(X86Context& ctx, uint8_t* base) {
	// 0x28C420: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28C428: movss [0x0056BC0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC0Cu, ctx.xmm[0].u32[0]);
	// 0x28C430: ret
	return;
}

void sub_28C440(X86Context& ctx, uint8_t* base) {
	// 0x28C440: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28C448: movss [0x0056BC28], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC28u, ctx.xmm[0].u32[0]);
	// 0x28C450: ret
	return;
}

void sub_28C460(X86Context& ctx, uint8_t* base) {
	// 0x28C460: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28C468: movss [0x0056BC00], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC00u, ctx.xmm[0].u32[0]);
	// 0x28C470: ret
	return;
}

void sub_28C480(X86Context& ctx, uint8_t* base) {
	// 0x28C480: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28C488: movss [0x0056BBB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBB8u, ctx.xmm[0].u32[0]);
	// 0x28C490: ret
	return;
}

void sub_28C4A0(X86Context& ctx, uint8_t* base) {
	// 0x28C4A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28C4A8: movss [0x0056BC10], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC10u, ctx.xmm[0].u32[0]);
	// 0x28C4B0: ret
	return;
}

void sub_28C4C0(X86Context& ctx, uint8_t* base) {
	// 0x28C4C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28C4C8: movss [0x0056BBD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBD4u, ctx.xmm[0].u32[0]);
	// 0x28C4D0: ret
	return;
}

void sub_28C4E0(X86Context& ctx, uint8_t* base) {
	// 0x28C4E0: movss xmm0, dword ptr [0x0056BC10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC10u);
	// 0x28C4E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28C4F0: movss [0x0056BC48], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC48u, ctx.xmm[0].u32[0]);
	// 0x28C4F8: ret
	return;
}

void sub_28C500(X86Context& ctx, uint8_t* base) {
	// 0x28C500: movss xmm0, dword ptr [0x0056BBD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBD4u);
	// 0x28C508: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28C510: movss [0x0056BC30], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC30u, ctx.xmm[0].u32[0]);
	// 0x28C518: ret
	return;
}

void sub_28C520(X86Context& ctx, uint8_t* base) {
	// 0x28C520: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28C528: movss [0x0056BC60], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC60u, ctx.xmm[0].u32[0]);
	// 0x28C530: ret
	return;
}

void sub_28C540(X86Context& ctx, uint8_t* base) {
	// 0x28C540: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28C548: movss [0x0056BC4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC4Cu, ctx.xmm[0].u32[0]);
	// 0x28C550: ret
	return;
}

void sub_28C560(X86Context& ctx, uint8_t* base) {
	// 0x28C560: movss xmm0, dword ptr [0x0056BC4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC4Cu);
	// 0x28C568: movss [0x0056BC5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC5Cu, ctx.xmm[0].u32[0]);
	// 0x28C570: ret
	return;
}

void sub_28C580(X86Context& ctx, uint8_t* base) {
	// 0x28C580: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28C588: movss [0x0056BBC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBC0u, ctx.xmm[0].u32[0]);
	// 0x28C590: ret
	return;
}

void sub_28C5A0(X86Context& ctx, uint8_t* base) {
	// 0x28C5A0: movss xmm0, dword ptr [0x0056BBD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBD4u);
	// 0x28C5A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28C5B0: movss [0x0056BC54], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC54u, ctx.xmm[0].u32[0]);
	// 0x28C5B8: ret
	return;
}

void sub_28C5C0(X86Context& ctx, uint8_t* base) {
	// 0x28C5C0: movss xmm0, dword ptr [0x0056BBD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBD4u);
	// 0x28C5C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28C5D0: movss [0x0056BBFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBFCu, ctx.xmm[0].u32[0]);
	// 0x28C5D8: ret
	return;
}

void sub_28C5E0(X86Context& ctx, uint8_t* base) {
	// 0x28C5E0: movss xmm0, dword ptr [0x0056BBD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBD4u);
	// 0x28C5E8: subss xmm0, [0x0056BBFC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BBFCu);
	// 0x28C5F0: movss [0x0056BBDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBDCu, ctx.xmm[0].u32[0]);
	// 0x28C5F8: ret
	return;
}

void sub_28C600(X86Context& ctx, uint8_t* base) {
	// 0x28C600: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28C608: movss [0x0056BC24], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC24u, ctx.xmm[0].u32[0]);
	// 0x28C610: ret
	return;
}

void sub_28C620(X86Context& ctx, uint8_t* base) {
	// 0x28C620: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28C628: movss [0x0056BBD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBD8u, ctx.xmm[0].u32[0]);
	// 0x28C630: ret
	return;
}

void sub_28C640(X86Context& ctx, uint8_t* base) {
	// 0x28C640: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28C648: movss [0x0056BBE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBE8u, ctx.xmm[0].u32[0]);
	// 0x28C650: ret
	return;
}

void sub_28C660(X86Context& ctx, uint8_t* base) {
	// 0x28C660: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28C668: movss [0x0056BC3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC3Cu, ctx.xmm[0].u32[0]);
	// 0x28C670: ret
	return;
}

void sub_28C680(X86Context& ctx, uint8_t* base) {
	// 0x28C680: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28C688: movss [0x0056BC20], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC20u, ctx.xmm[0].u32[0]);
	// 0x28C690: ret
	return;
}

void sub_28C6A0(X86Context& ctx, uint8_t* base) {
	// 0x28C6A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28C6A8: movss [0x0056BBD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBD0u, ctx.xmm[0].u32[0]);
	// 0x28C6B0: ret
	return;
}

void sub_28C6C0(X86Context& ctx, uint8_t* base) {
	// 0x28C6C0: movss xmm0, dword ptr [0x0056BBE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBE8u);
	// 0x28C6C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28C6D0: movss [0x0056BBC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBC4u, ctx.xmm[0].u32[0]);
	// 0x28C6D8: ret
	return;
}

void sub_28C6E0(X86Context& ctx, uint8_t* base) {
	// 0x28C6E0: movss xmm0, dword ptr [0x0056BC3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC3Cu);
	// 0x28C6E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28C6F0: movss [0x0056BC08], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC08u, ctx.xmm[0].u32[0]);
	// 0x28C6F8: ret
	return;
}

void sub_28C700(X86Context& ctx, uint8_t* base) {
	// 0x28C700: movss xmm0, dword ptr [0x0056BBC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBC4u);
	// 0x28C708: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28C710: movss [0x0056BC18], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC18u, ctx.xmm[0].u32[0]);
	// 0x28C718: ret
	return;
}

void sub_28C720(X86Context& ctx, uint8_t* base) {
	// 0x28C720: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28C728: movss [0x0056BBBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBBCu, ctx.xmm[0].u32[0]);
	// 0x28C730: ret
	return;
}

void sub_28C740(X86Context& ctx, uint8_t* base) {
	// 0x28C740: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28C748: movss [0x0056BBEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBECu, ctx.xmm[0].u32[0]);
	// 0x28C750: ret
	return;
}

void sub_28C760(X86Context& ctx, uint8_t* base) {
	// 0x28C760: movss xmm0, dword ptr [0x0056BBE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBE8u);
	// 0x28C768: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28C770: movss [0x0056BBF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBF8u, ctx.xmm[0].u32[0]);
	// 0x28C778: ret
	return;
}

void sub_28C780(X86Context& ctx, uint8_t* base) {
	// 0x28C780: movss xmm0, dword ptr [0x0056BC3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC3Cu);
	// 0x28C788: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28C790: movss [0x0056BC40], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC40u, ctx.xmm[0].u32[0]);
	// 0x28C798: ret
	return;
}

void sub_28C7A0(X86Context& ctx, uint8_t* base) {
	// 0x28C7A0: movss xmm0, dword ptr [0x0056BBF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBF8u);
	// 0x28C7A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C7B0: movss [0x0056BC2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC2Cu, ctx.xmm[0].u32[0]);
	// 0x28C7B8: ret
	return;
}

void sub_28C7C0(X86Context& ctx, uint8_t* base) {
	// 0x28C7C0: movss xmm0, dword ptr [0x0056BC40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC40u);
	// 0x28C7C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C7D0: movss [0x0056BC50], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC50u, ctx.xmm[0].u32[0]);
	// 0x28C7D8: ret
	return;
}

void sub_28C7E0(X86Context& ctx, uint8_t* base) {
	// 0x28C7E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28C7E8: movss [0x0056BBC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBC8u, ctx.xmm[0].u32[0]);
	// 0x28C7F0: ret
	return;
}

void sub_28C800(X86Context& ctx, uint8_t* base) {
	// 0x28C800: movss xmm0, dword ptr [0x0056BBE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBE8u);
	// 0x28C808: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C810: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28C818: movss [0x0056BC38], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC38u, ctx.xmm[0].u32[0]);
	// 0x28C820: ret
	return;
}

void sub_28C830(X86Context& ctx, uint8_t* base) {
	// 0x28C830: movss xmm0, dword ptr [0x0056BC3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC3Cu);
	// 0x28C838: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C840: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28C848: movss [0x0056BBE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBE0u, ctx.xmm[0].u32[0]);
	// 0x28C850: ret
	return;
}

void sub_28C860(X86Context& ctx, uint8_t* base) {
	// 0x28C860: movss xmm0, dword ptr [0x0056BBE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBE8u);
	// 0x28C868: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C870: movss [0x0056BBE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBE4u, ctx.xmm[0].u32[0]);
	// 0x28C878: ret
	return;
}

void sub_28C880(X86Context& ctx, uint8_t* base) {
	// 0x28C880: movss xmm0, dword ptr [0x0056BC3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC3Cu);
	// 0x28C888: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28C890: movss [0x0056BC44], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC44u, ctx.xmm[0].u32[0]);
	// 0x28C898: ret
	return;
}

void sub_28C8A0(X86Context& ctx, uint8_t* base) {
	// 0x28C8A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28C8A8: movss [0x0056BBCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBCCu, ctx.xmm[0].u32[0]);
	// 0x28C8B0: ret
	return;
}

void sub_28C8C0(X86Context& ctx, uint8_t* base) {
	// 0x28C8C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28C8C8: movss [0x0056BBF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBF4u, ctx.xmm[0].u32[0]);
	// 0x28C8D0: ret
	return;
}

void sub_28C8E0(X86Context& ctx, uint8_t* base) {
	// 0x28C8E0: movss xmm0, dword ptr [0x0056BBCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BBCCu);
	// 0x28C8E8: movss [0x0056BC58], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC58u, ctx.xmm[0].u32[0]);
	// 0x28C8F0: ret
	return;
}

void sub_28C900(X86Context& ctx, uint8_t* base) {
	// 0x28C900: movss xmm0, dword ptr [0x0056BC3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC3Cu);
	// 0x28C908: subss xmm0, [0x0056BBCC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BBCCu);
	// 0x28C910: movss [0x0056BC1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC1Cu, ctx.xmm[0].u32[0]);
	// 0x28C918: ret
	return;
}

void sub_28C920(X86Context& ctx, uint8_t* base) {
	// 0x28C920: movss xmm0, dword ptr [0x0056BC1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC1Cu);
	// 0x28C928: subss xmm0, [0x0056BBF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BBF4u);
	// 0x28C930: movss [0x0056BC14], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC14u, ctx.xmm[0].u32[0]);
	// 0x28C938: ret
	return;
}

void sub_28C940(X86Context& ctx, uint8_t* base) {
	// 0x28C940: movss xmm0, dword ptr [0x0056BC44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC44u);
	// 0x28C948: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28C950: movss [0x0056BC04], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC04u, ctx.xmm[0].u32[0]);
	// 0x28C958: ret
	return;
}

void sub_28C960(X86Context& ctx, uint8_t* base) {
	// 0x28C960: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28C968: movss [0x0056BBF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BBF0u, ctx.xmm[0].u32[0]);
	// 0x28C970: ret
	return;
}

void sub_28C980(X86Context& ctx, uint8_t* base) {
	// 0x28C980: movss xmm0, dword ptr [0x0056BC04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC04u);
	// 0x28C988: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28C990: movss [0x0056BC34], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC34u, ctx.xmm[0].u32[0]);
	// 0x28C998: ret
	return;
}

void sub_28C9A0(X86Context& ctx, uint8_t* base) {
	// 0x28C9A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28C9A8: movss [0x0056BCDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCDCu, ctx.xmm[0].u32[0]);
	// 0x28C9B0: ret
	return;
}

void sub_28C9C0(X86Context& ctx, uint8_t* base) {
	// 0x28C9C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28C9C8: movss [0x0056BCFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCFCu, ctx.xmm[0].u32[0]);
	// 0x28C9D0: ret
	return;
}

void sub_28C9E0(X86Context& ctx, uint8_t* base) {
	// 0x28C9E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28C9E8: movss [0x0056BCCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCCCu, ctx.xmm[0].u32[0]);
	// 0x28C9F0: ret
	return;
}

void sub_28CA00(X86Context& ctx, uint8_t* base) {
	// 0x28CA00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28CA08: movss [0x0056BC64], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC64u, ctx.xmm[0].u32[0]);
	// 0x28CA10: ret
	return;
}

void sub_28CA20(X86Context& ctx, uint8_t* base) {
	// 0x28CA20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28CA28: movss [0x0056BCE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCE0u, ctx.xmm[0].u32[0]);
	// 0x28CA30: ret
	return;
}

void sub_28CA40(X86Context& ctx, uint8_t* base) {
	// 0x28CA40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28CA48: movss [0x0056BC84], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC84u, ctx.xmm[0].u32[0]);
	// 0x28CA50: ret
	return;
}

void sub_28CA60(X86Context& ctx, uint8_t* base) {
	// 0x28CA60: movss xmm0, dword ptr [0x0056BCE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCE0u);
	// 0x28CA68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28CA70: movss [0x0056BD20], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD20u, ctx.xmm[0].u32[0]);
	// 0x28CA78: ret
	return;
}

void sub_28CA80(X86Context& ctx, uint8_t* base) {
	// 0x28CA80: movss xmm0, dword ptr [0x0056BC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC84u);
	// 0x28CA88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28CA90: movss [0x0056BD04], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD04u, ctx.xmm[0].u32[0]);
	// 0x28CA98: ret
	return;
}

void sub_28CAA0(X86Context& ctx, uint8_t* base) {
	// 0x28CAA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28CAA8: movss [0x0056BD40], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD40u, ctx.xmm[0].u32[0]);
	// 0x28CAB0: ret
	return;
}

void sub_28CAC0(X86Context& ctx, uint8_t* base) {
	// 0x28CAC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28CAC8: movss [0x0056BD24], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD24u, ctx.xmm[0].u32[0]);
	// 0x28CAD0: ret
	return;
}

void sub_28CAE0(X86Context& ctx, uint8_t* base) {
	// 0x28CAE0: movss xmm0, dword ptr [0x0056BD24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD24u);
	// 0x28CAE8: movss [0x0056BD3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD3Cu, ctx.xmm[0].u32[0]);
	// 0x28CAF0: ret
	return;
}

void sub_28CB00(X86Context& ctx, uint8_t* base) {
	// 0x28CB00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28CB08: movss [0x0056BC70], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC70u, ctx.xmm[0].u32[0]);
	// 0x28CB10: ret
	return;
}

void sub_28CB20(X86Context& ctx, uint8_t* base) {
	// 0x28CB20: movss xmm0, dword ptr [0x0056BC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC84u);
	// 0x28CB28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28CB30: movss [0x0056BD30], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD30u, ctx.xmm[0].u32[0]);
	// 0x28CB38: ret
	return;
}

void sub_28CB40(X86Context& ctx, uint8_t* base) {
	// 0x28CB40: movss xmm0, dword ptr [0x0056BC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC84u);
	// 0x28CB48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28CB50: movss [0x0056BCC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCC8u, ctx.xmm[0].u32[0]);
	// 0x28CB58: ret
	return;
}

void sub_28CB60(X86Context& ctx, uint8_t* base) {
	// 0x28CB60: movss xmm0, dword ptr [0x0056BC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC84u);
	// 0x28CB68: subss xmm0, [0x0056BCC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BCC8u);
	// 0x28CB70: movss [0x0056BC8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC8Cu, ctx.xmm[0].u32[0]);
	// 0x28CB78: ret
	return;
}

void sub_28CB80(X86Context& ctx, uint8_t* base) {
	// 0x28CB80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28CB88: movss [0x0056BCF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCF8u, ctx.xmm[0].u32[0]);
	// 0x28CB90: ret
	return;
}

void sub_28CBA0(X86Context& ctx, uint8_t* base) {
	// 0x28CBA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28CBA8: movss [0x0056BC88], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC88u, ctx.xmm[0].u32[0]);
	// 0x28CBB0: ret
	return;
}

void sub_28CBC0(X86Context& ctx, uint8_t* base) {
	// 0x28CBC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28CBC8: movss [0x0056BCAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCACu, ctx.xmm[0].u32[0]);
	// 0x28CBD0: ret
	return;
}

void sub_28CBE0(X86Context& ctx, uint8_t* base) {
	// 0x28CBE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28CBE8: movss [0x0056BD14], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD14u, ctx.xmm[0].u32[0]);
	// 0x28CBF0: ret
	return;
}

void sub_28CC00(X86Context& ctx, uint8_t* base) {
	// 0x28CC00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28CC08: movss [0x0056BCF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCF0u, ctx.xmm[0].u32[0]);
	// 0x28CC10: ret
	return;
}

void sub_28CC20(X86Context& ctx, uint8_t* base) {
	// 0x28CC20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28CC28: movss [0x0056BC80], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC80u, ctx.xmm[0].u32[0]);
	// 0x28CC30: ret
	return;
}

void sub_28CC40(X86Context& ctx, uint8_t* base) {
	// 0x28CC40: movss xmm0, dword ptr [0x0056BCAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCACu);
	// 0x28CC48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28CC50: movss [0x0056BC74], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC74u, ctx.xmm[0].u32[0]);
	// 0x28CC58: ret
	return;
}

void sub_28CC60(X86Context& ctx, uint8_t* base) {
	// 0x28CC60: movss xmm0, dword ptr [0x0056BD14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD14u);
	// 0x28CC68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28CC70: movss [0x0056BCD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCD8u, ctx.xmm[0].u32[0]);
	// 0x28CC78: ret
	return;
}

void sub_28CC80(X86Context& ctx, uint8_t* base) {
	// 0x28CC80: movss xmm0, dword ptr [0x0056BC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC74u);
	// 0x28CC88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28CC90: movss [0x0056BCE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCE8u, ctx.xmm[0].u32[0]);
	// 0x28CC98: ret
	return;
}

void sub_28CCA0(X86Context& ctx, uint8_t* base) {
	// 0x28CCA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28CCA8: movss [0x0056BC68], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC68u, ctx.xmm[0].u32[0]);
	// 0x28CCB0: ret
	return;
}

void sub_28CCC0(X86Context& ctx, uint8_t* base) {
	// 0x28CCC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28CCC8: movss [0x0056BCB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCB4u, ctx.xmm[0].u32[0]);
	// 0x28CCD0: ret
	return;
}

void sub_28CCE0(X86Context& ctx, uint8_t* base) {
	// 0x28CCE0: movss xmm0, dword ptr [0x0056BCAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCACu);
	// 0x28CCE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28CCF0: movss [0x0056BCC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCC4u, ctx.xmm[0].u32[0]);
	// 0x28CCF8: ret
	return;
}

void sub_28CD00(X86Context& ctx, uint8_t* base) {
	// 0x28CD00: movss xmm0, dword ptr [0x0056BD14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD14u);
	// 0x28CD08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28CD10: movss [0x0056BD18], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD18u, ctx.xmm[0].u32[0]);
	// 0x28CD18: ret
	return;
}

void sub_28CD20(X86Context& ctx, uint8_t* base) {
	// 0x28CD20: movss xmm0, dword ptr [0x0056BCC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCC4u);
	// 0x28CD28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28CD30: movss [0x0056BD00], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD00u, ctx.xmm[0].u32[0]);
	// 0x28CD38: ret
	return;
}

void sub_28CD40(X86Context& ctx, uint8_t* base) {
	// 0x28CD40: movss xmm0, dword ptr [0x0056BD18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD18u);
	// 0x28CD48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28CD50: movss [0x0056BD28], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD28u, ctx.xmm[0].u32[0]);
	// 0x28CD58: ret
	return;
}

void sub_28CD60(X86Context& ctx, uint8_t* base) {
	// 0x28CD60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28CD68: movss [0x0056BC78], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC78u, ctx.xmm[0].u32[0]);
	// 0x28CD70: ret
	return;
}

void sub_28CD80(X86Context& ctx, uint8_t* base) {
	// 0x28CD80: movss xmm0, dword ptr [0x0056BCAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCACu);
	// 0x28CD88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28CD90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28CD98: movss [0x0056BD0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD0Cu, ctx.xmm[0].u32[0]);
	// 0x28CDA0: ret
	return;
}

void sub_28CDB0(X86Context& ctx, uint8_t* base) {
	// 0x28CDB0: movss xmm0, dword ptr [0x0056BD14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD14u);
	// 0x28CDB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28CDC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28CDC8: movss [0x0056BC94], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC94u, ctx.xmm[0].u32[0]);
	// 0x28CDD0: ret
	return;
}

void sub_28CDE0(X86Context& ctx, uint8_t* base) {
	// 0x28CDE0: movss xmm0, dword ptr [0x0056BCAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCACu);
	// 0x28CDE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28CDF0: movss [0x0056BCA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCA0u, ctx.xmm[0].u32[0]);
	// 0x28CDF8: ret
	return;
}

void sub_28CE00(X86Context& ctx, uint8_t* base) {
	// 0x28CE00: movss xmm0, dword ptr [0x0056BD14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD14u);
	// 0x28CE08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28CE10: movss [0x0056BD1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD1Cu, ctx.xmm[0].u32[0]);
	// 0x28CE18: ret
	return;
}

void sub_28CE20(X86Context& ctx, uint8_t* base) {
	// 0x28CE20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28CE28: movss [0x0056BC7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC7Cu, ctx.xmm[0].u32[0]);
	// 0x28CE30: ret
	return;
}

void sub_28CE40(X86Context& ctx, uint8_t* base) {
	// 0x28CE40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28CE48: movss [0x0056BCC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCC0u, ctx.xmm[0].u32[0]);
	// 0x28CE50: ret
	return;
}

void sub_28CE60(X86Context& ctx, uint8_t* base) {
	// 0x28CE60: movss xmm0, dword ptr [0x0056BC7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC7Cu);
	// 0x28CE68: movss [0x0056BD34], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD34u, ctx.xmm[0].u32[0]);
	// 0x28CE70: ret
	return;
}

void sub_28CE80(X86Context& ctx, uint8_t* base) {
	// 0x28CE80: movss xmm0, dword ptr [0x0056BD14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD14u);
	// 0x28CE88: subss xmm0, [0x0056BC7C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BC7Cu);
	// 0x28CE90: movss [0x0056BCEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCECu, ctx.xmm[0].u32[0]);
	// 0x28CE98: ret
	return;
}

void sub_28CEA0(X86Context& ctx, uint8_t* base) {
	// 0x28CEA0: movss xmm0, dword ptr [0x0056BCEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCECu);
	// 0x28CEA8: subss xmm0, [0x0056BCC0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BCC0u);
	// 0x28CEB0: movss [0x0056BCE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCE4u, ctx.xmm[0].u32[0]);
	// 0x28CEB8: ret
	return;
}

void sub_28CEC0(X86Context& ctx, uint8_t* base) {
	// 0x28CEC0: movss xmm0, dword ptr [0x0056BD1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD1Cu);
	// 0x28CEC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28CED0: movss [0x0056BCD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCD0u, ctx.xmm[0].u32[0]);
	// 0x28CED8: ret
	return;
}

void sub_28CEE0(X86Context& ctx, uint8_t* base) {
	// 0x28CEE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28CEE8: movss [0x0056BCBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCBCu, ctx.xmm[0].u32[0]);
	// 0x28CEF0: ret
	return;
}

void sub_28CF00(X86Context& ctx, uint8_t* base) {
	// 0x28CF00: movss xmm0, dword ptr [0x0056BCD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCD0u);
	// 0x28CF08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28CF10: movss [0x0056BD08], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD08u, ctx.xmm[0].u32[0]);
	// 0x28CF18: ret
	return;
}

void sub_28CF20(X86Context& ctx, uint8_t* base) {
	// 0x28CF20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28CF28: movss [0x0056BCD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCD4u, ctx.xmm[0].u32[0]);
	// 0x28CF30: ret
	return;
}

void sub_28CF40(X86Context& ctx, uint8_t* base) {
	// 0x28CF40: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28CF48: movss [0x0056BCB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCB0u, ctx.xmm[0].u32[0]);
	// 0x28CF50: ret
	return;
}

void sub_28CF60(X86Context& ctx, uint8_t* base) {
	// 0x28CF60: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28CF68: movss [0x0056BC6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC6Cu, ctx.xmm[0].u32[0]);
	// 0x28CF70: ret
	return;
}

void sub_28CF80(X86Context& ctx, uint8_t* base) {
	// 0x28CF80: movss xmm0, dword ptr [0x003B2280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2280u);
	// 0x28CF88: movss [0x0056BC98], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC98u, ctx.xmm[0].u32[0]);
	// 0x28CF90: ret
	return;
}

void sub_28CFA0(X86Context& ctx, uint8_t* base) {
	// 0x28CFA0: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x28CFA8: movss [0x0056BD44], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD44u, ctx.xmm[0].u32[0]);
	// 0x28CFB0: ret
	return;
}

void sub_28CFC0(X86Context& ctx, uint8_t* base) {
	// 0x28CFC0: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x28CFC8: movss [0x0056BD10], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD10u, ctx.xmm[0].u32[0]);
	// 0x28CFD0: ret
	return;
}

void sub_28CFE0(X86Context& ctx, uint8_t* base) {
	// 0x28CFE0: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x28CFE8: movss [0x0056BD38], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD38u, ctx.xmm[0].u32[0]);
	// 0x28CFF0: ret
	return;
}

void sub_28D000(X86Context& ctx, uint8_t* base) {
	// 0x28D000: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x28D008: movss [0x0056BCA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCA8u, ctx.xmm[0].u32[0]);
	// 0x28D010: ret
	return;
}

void sub_28D020(X86Context& ctx, uint8_t* base) {
	// 0x28D020: movss xmm0, dword ptr [0x00395BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x28D028: movss [0x0056BC90], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC90u, ctx.xmm[0].u32[0]);
	// 0x28D030: ret
	return;
}

void sub_28D040(X86Context& ctx, uint8_t* base) {
	// 0x28D040: movss xmm0, dword ptr [0x0056BC90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BC90u);
	// 0x28D048: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x28D050: movss [0x0056BCA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCA4u, ctx.xmm[0].u32[0]);
	// 0x28D058: ret
	return;
}

void sub_28D060(X86Context& ctx, uint8_t* base) {
	// 0x28D060: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x28D068: movss [0x0056BC9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BC9Cu, ctx.xmm[0].u32[0]);
	// 0x28D070: ret
	return;
}

void sub_28D080(X86Context& ctx, uint8_t* base) {
	// 0x28D080: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x28D088: movss [0x0056BCF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCF4u, ctx.xmm[0].u32[0]);
	// 0x28D090: ret
	return;
}

void sub_28D0A0(X86Context& ctx, uint8_t* base) {
	// 0x28D0A0: movss xmm0, dword ptr [0x003B17E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x28D0A8: movss [0x0056BCB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BCB8u, ctx.xmm[0].u32[0]);
	// 0x28D0B0: ret
	return;
}

void sub_28D0C0(X86Context& ctx, uint8_t* base) {
	// 0x28D0C0: movss xmm0, dword ptr [0x0056BCB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BCB8u);
	// 0x28D0C8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x28D0D0: movss [0x0056BD2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD2Cu, ctx.xmm[0].u32[0]);
	// 0x28D0D8: ret
	return;
}

void sub_28D0E0(X86Context& ctx, uint8_t* base) {
	// 0x28D0E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28D0E8: movss [0x0056BDA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDA4u, ctx.xmm[0].u32[0]);
	// 0x28D0F0: ret
	return;
}

void sub_28D100(X86Context& ctx, uint8_t* base) {
	// 0x28D100: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28D108: movss [0x0056BDC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDC0u, ctx.xmm[0].u32[0]);
	// 0x28D110: ret
	return;
}

void sub_28D120(X86Context& ctx, uint8_t* base) {
	// 0x28D120: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28D128: movss [0x0056BD94], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD94u, ctx.xmm[0].u32[0]);
	// 0x28D130: ret
	return;
}

void sub_28D140(X86Context& ctx, uint8_t* base) {
	// 0x28D140: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28D148: movss [0x0056BD48], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD48u, ctx.xmm[0].u32[0]);
	// 0x28D150: ret
	return;
}

void sub_28D160(X86Context& ctx, uint8_t* base) {
	// 0x28D160: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28D168: movss [0x0056BDA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDA8u, ctx.xmm[0].u32[0]);
	// 0x28D170: ret
	return;
}

void sub_28D180(X86Context& ctx, uint8_t* base) {
	// 0x28D180: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28D188: movss [0x0056BD64], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD64u, ctx.xmm[0].u32[0]);
	// 0x28D190: ret
	return;
}

void sub_28D1A0(X86Context& ctx, uint8_t* base) {
	// 0x28D1A0: movss xmm0, dword ptr [0x0056BDA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDA8u);
	// 0x28D1A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28D1B0: movss [0x0056BDE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDE0u, ctx.xmm[0].u32[0]);
	// 0x28D1B8: ret
	return;
}

void sub_28D1C0(X86Context& ctx, uint8_t* base) {
	// 0x28D1C0: movss xmm0, dword ptr [0x0056BD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD64u);
	// 0x28D1C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28D1D0: movss [0x0056BDC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDC8u, ctx.xmm[0].u32[0]);
	// 0x28D1D8: ret
	return;
}

void sub_28D1E0(X86Context& ctx, uint8_t* base) {
	// 0x28D1E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28D1E8: movss [0x0056BDF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDF8u, ctx.xmm[0].u32[0]);
	// 0x28D1F0: ret
	return;
}

void sub_28D200(X86Context& ctx, uint8_t* base) {
	// 0x28D200: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28D208: movss [0x0056BDE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDE4u, ctx.xmm[0].u32[0]);
	// 0x28D210: ret
	return;
}

void sub_28D220(X86Context& ctx, uint8_t* base) {
	// 0x28D220: movss xmm0, dword ptr [0x0056BDE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDE4u);
	// 0x28D228: movss [0x0056BDF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDF4u, ctx.xmm[0].u32[0]);
	// 0x28D230: ret
	return;
}

void sub_28D240(X86Context& ctx, uint8_t* base) {
	// 0x28D240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28D248: movss [0x0056BD50], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD50u, ctx.xmm[0].u32[0]);
	// 0x28D250: ret
	return;
}

void sub_28D260(X86Context& ctx, uint8_t* base) {
	// 0x28D260: movss xmm0, dword ptr [0x0056BD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD64u);
	// 0x28D268: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28D270: movss [0x0056BDEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDECu, ctx.xmm[0].u32[0]);
	// 0x28D278: ret
	return;
}

void sub_28D280(X86Context& ctx, uint8_t* base) {
	// 0x28D280: movss xmm0, dword ptr [0x0056BD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD64u);
	// 0x28D288: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28D290: movss [0x0056BD90], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD90u, ctx.xmm[0].u32[0]);
	// 0x28D298: ret
	return;
}

void sub_28D2A0(X86Context& ctx, uint8_t* base) {
	// 0x28D2A0: movss xmm0, dword ptr [0x0056BD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD64u);
	// 0x28D2A8: subss xmm0, [0x0056BD90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BD90u);
	// 0x28D2B0: movss [0x0056BD6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD6Cu, ctx.xmm[0].u32[0]);
	// 0x28D2B8: ret
	return;
}

void sub_28D2C0(X86Context& ctx, uint8_t* base) {
	// 0x28D2C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28D2C8: movss [0x0056BDBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDBCu, ctx.xmm[0].u32[0]);
	// 0x28D2D0: ret
	return;
}

void sub_28D2E0(X86Context& ctx, uint8_t* base) {
	// 0x28D2E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28D2E8: movss [0x0056BD68], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD68u, ctx.xmm[0].u32[0]);
	// 0x28D2F0: ret
	return;
}

void sub_28D300(X86Context& ctx, uint8_t* base) {
	// 0x28D300: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28D308: movss [0x0056BD7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD7Cu, ctx.xmm[0].u32[0]);
	// 0x28D310: ret
	return;
}

void sub_28D320(X86Context& ctx, uint8_t* base) {
	// 0x28D320: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28D328: movss [0x0056BDD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDD4u, ctx.xmm[0].u32[0]);
	// 0x28D330: ret
	return;
}

void sub_28D340(X86Context& ctx, uint8_t* base) {
	// 0x28D340: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28D348: movss [0x0056BDB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDB8u, ctx.xmm[0].u32[0]);
	// 0x28D350: ret
	return;
}

void sub_28D360(X86Context& ctx, uint8_t* base) {
	// 0x28D360: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28D368: movss [0x0056BD60], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD60u, ctx.xmm[0].u32[0]);
	// 0x28D370: ret
	return;
}

void sub_28D380(X86Context& ctx, uint8_t* base) {
	// 0x28D380: movss xmm0, dword ptr [0x0056BD7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD7Cu);
	// 0x28D388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28D390: movss [0x0056BD54], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD54u, ctx.xmm[0].u32[0]);
	// 0x28D398: ret
	return;
}

void sub_28D3A0(X86Context& ctx, uint8_t* base) {
	// 0x28D3A0: movss xmm0, dword ptr [0x0056BDD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDD4u);
	// 0x28D3A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28D3B0: movss [0x0056BD9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD9Cu, ctx.xmm[0].u32[0]);
	// 0x28D3B8: ret
	return;
}

void sub_28D3C0(X86Context& ctx, uint8_t* base) {
	// 0x28D3C0: movss xmm0, dword ptr [0x0056BD54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD54u);
	// 0x28D3C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28D3D0: movss [0x0056BDB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDB0u, ctx.xmm[0].u32[0]);
	// 0x28D3D8: ret
	return;
}

void sub_28D3E0(X86Context& ctx, uint8_t* base) {
	// 0x28D3E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28D3E8: movss [0x0056BD4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD4Cu, ctx.xmm[0].u32[0]);
	// 0x28D3F0: ret
	return;
}

void sub_28D400(X86Context& ctx, uint8_t* base) {
	// 0x28D400: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28D408: movss [0x0056BD80], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD80u, ctx.xmm[0].u32[0]);
	// 0x28D410: ret
	return;
}

void sub_28D420(X86Context& ctx, uint8_t* base) {
	// 0x28D420: movss xmm0, dword ptr [0x0056BD7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD7Cu);
	// 0x28D428: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28D430: movss [0x0056BD8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD8Cu, ctx.xmm[0].u32[0]);
	// 0x28D438: ret
	return;
}

void sub_28D440(X86Context& ctx, uint8_t* base) {
	// 0x28D440: movss xmm0, dword ptr [0x0056BDD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDD4u);
	// 0x28D448: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28D450: movss [0x0056BDD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDD8u, ctx.xmm[0].u32[0]);
	// 0x28D458: ret
	return;
}

void sub_28D460(X86Context& ctx, uint8_t* base) {
	// 0x28D460: movss xmm0, dword ptr [0x0056BD8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD8Cu);
	// 0x28D468: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28D470: movss [0x0056BDC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDC4u, ctx.xmm[0].u32[0]);
	// 0x28D478: ret
	return;
}

void sub_28D480(X86Context& ctx, uint8_t* base) {
	// 0x28D480: movss xmm0, dword ptr [0x0056BDD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDD8u);
	// 0x28D488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28D490: movss [0x0056BDE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDE8u, ctx.xmm[0].u32[0]);
	// 0x28D498: ret
	return;
}

void sub_28D4A0(X86Context& ctx, uint8_t* base) {
	// 0x28D4A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28D4A8: movss [0x0056BD58], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD58u, ctx.xmm[0].u32[0]);
	// 0x28D4B0: ret
	return;
}

void sub_28D4C0(X86Context& ctx, uint8_t* base) {
	// 0x28D4C0: movss xmm0, dword ptr [0x0056BD7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD7Cu);
	// 0x28D4C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28D4D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28D4D8: movss [0x0056BDD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDD0u, ctx.xmm[0].u32[0]);
	// 0x28D4E0: ret
	return;
}

void sub_28D4F0(X86Context& ctx, uint8_t* base) {
	// 0x28D4F0: movss xmm0, dword ptr [0x0056BDD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDD4u);
	// 0x28D4F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28D500: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28D508: movss [0x0056BD70], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD70u, ctx.xmm[0].u32[0]);
	// 0x28D510: ret
	return;
}

void sub_28D520(X86Context& ctx, uint8_t* base) {
	// 0x28D520: movss xmm0, dword ptr [0x0056BD7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD7Cu);
	// 0x28D528: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28D530: movss [0x0056BD74], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD74u, ctx.xmm[0].u32[0]);
	// 0x28D538: ret
	return;
}

void sub_28D540(X86Context& ctx, uint8_t* base) {
	// 0x28D540: movss xmm0, dword ptr [0x0056BDD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDD4u);
	// 0x28D548: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28D550: movss [0x0056BDDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDDCu, ctx.xmm[0].u32[0]);
	// 0x28D558: ret
	return;
}

void sub_28D560(X86Context& ctx, uint8_t* base) {
	// 0x28D560: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28D568: movss [0x0056BD5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD5Cu, ctx.xmm[0].u32[0]);
	// 0x28D570: ret
	return;
}

void sub_28D580(X86Context& ctx, uint8_t* base) {
	// 0x28D580: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28D588: movss [0x0056BD88], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD88u, ctx.xmm[0].u32[0]);
	// 0x28D590: ret
	return;
}

void sub_28D5A0(X86Context& ctx, uint8_t* base) {
	// 0x28D5A0: movss xmm0, dword ptr [0x0056BD5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD5Cu);
	// 0x28D5A8: movss [0x0056BDF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDF0u, ctx.xmm[0].u32[0]);
	// 0x28D5B0: ret
	return;
}

void sub_28D5C0(X86Context& ctx, uint8_t* base) {
	// 0x28D5C0: movss xmm0, dword ptr [0x0056BDD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDD4u);
	// 0x28D5C8: subss xmm0, [0x0056BD5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BD5Cu);
	// 0x28D5D0: movss [0x0056BDB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDB4u, ctx.xmm[0].u32[0]);
	// 0x28D5D8: ret
	return;
}

void sub_28D5E0(X86Context& ctx, uint8_t* base) {
	// 0x28D5E0: movss xmm0, dword ptr [0x0056BDB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDB4u);
	// 0x28D5E8: subss xmm0, [0x0056BD88]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BD88u);
	// 0x28D5F0: movss [0x0056BDAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDACu, ctx.xmm[0].u32[0]);
	// 0x28D5F8: ret
	return;
}

void sub_28D600(X86Context& ctx, uint8_t* base) {
	// 0x28D600: movss xmm0, dword ptr [0x0056BDDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BDDCu);
	// 0x28D608: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28D610: movss [0x0056BD98], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD98u, ctx.xmm[0].u32[0]);
	// 0x28D618: ret
	return;
}

void sub_28D620(X86Context& ctx, uint8_t* base) {
	// 0x28D620: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28D628: movss [0x0056BD84], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD84u, ctx.xmm[0].u32[0]);
	// 0x28D630: ret
	return;
}

void sub_28D640(X86Context& ctx, uint8_t* base) {
	// 0x28D640: movss xmm0, dword ptr [0x0056BD98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BD98u);
	// 0x28D648: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28D650: movss [0x0056BDCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDCCu, ctx.xmm[0].u32[0]);
	// 0x28D658: ret
	return;
}

void sub_28D660(X86Context& ctx, uint8_t* base) {
	// 0x28D660: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x28D668: movss [0x0056BDA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDA0u, ctx.xmm[0].u32[0]);
	// 0x28D670: ret
	return;
}

void sub_28D680(X86Context& ctx, uint8_t* base) {
	// 0x28D680: movss xmm0, dword ptr [0x003A35C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A35C4u);
	// 0x28D688: movss [0x0056BD78], xmm0
	X86_MEM_WRITE_u32(base, 0x56BD78u, ctx.xmm[0].u32[0]);
	// 0x28D690: ret
	return;
}

void sub_28D6A0(X86Context& ctx, uint8_t* base) {
	// 0x28D6A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28D6A8: movss [0x0056BE50], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE50u, ctx.xmm[0].u32[0]);
	// 0x28D6B0: ret
	return;
}

void sub_28D6C0(X86Context& ctx, uint8_t* base) {
	// 0x28D6C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28D6C8: movss [0x0056BE6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE6Cu, ctx.xmm[0].u32[0]);
	// 0x28D6D0: ret
	return;
}

void sub_28D6E0(X86Context& ctx, uint8_t* base) {
	// 0x28D6E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28D6E8: movss [0x0056BE44], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE44u, ctx.xmm[0].u32[0]);
	// 0x28D6F0: ret
	return;
}

void sub_28D700(X86Context& ctx, uint8_t* base) {
	// 0x28D700: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28D708: movss [0x0056BDFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BDFCu, ctx.xmm[0].u32[0]);
	// 0x28D710: ret
	return;
}

void sub_28D720(X86Context& ctx, uint8_t* base) {
	// 0x28D720: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28D728: movss [0x0056BE54], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE54u, ctx.xmm[0].u32[0]);
	// 0x28D730: ret
	return;
}

void sub_28D740(X86Context& ctx, uint8_t* base) {
	// 0x28D740: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28D748: movss [0x0056BE18], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE18u, ctx.xmm[0].u32[0]);
	// 0x28D750: ret
	return;
}

void sub_28D760(X86Context& ctx, uint8_t* base) {
	// 0x28D760: movss xmm0, dword ptr [0x0056BE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE54u);
	// 0x28D768: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28D770: movss [0x0056BE8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE8Cu, ctx.xmm[0].u32[0]);
	// 0x28D778: ret
	return;
}

void sub_28D780(X86Context& ctx, uint8_t* base) {
	// 0x28D780: movss xmm0, dword ptr [0x0056BE18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE18u);
	// 0x28D788: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28D790: movss [0x0056BE74], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE74u, ctx.xmm[0].u32[0]);
	// 0x28D798: ret
	return;
}

void sub_28D7A0(X86Context& ctx, uint8_t* base) {
	// 0x28D7A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28D7A8: movss [0x0056BEA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEA4u, ctx.xmm[0].u32[0]);
	// 0x28D7B0: ret
	return;
}

void sub_28D7C0(X86Context& ctx, uint8_t* base) {
	// 0x28D7C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28D7C8: movss [0x0056BE90], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE90u, ctx.xmm[0].u32[0]);
	// 0x28D7D0: ret
	return;
}

void sub_28D7E0(X86Context& ctx, uint8_t* base) {
	// 0x28D7E0: movss xmm0, dword ptr [0x0056BE90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE90u);
	// 0x28D7E8: movss [0x0056BEA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEA0u, ctx.xmm[0].u32[0]);
	// 0x28D7F0: ret
	return;
}

void sub_28D800(X86Context& ctx, uint8_t* base) {
	// 0x28D800: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28D808: movss [0x0056BE04], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE04u, ctx.xmm[0].u32[0]);
	// 0x28D810: ret
	return;
}

void sub_28D820(X86Context& ctx, uint8_t* base) {
	// 0x28D820: movss xmm0, dword ptr [0x0056BE18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE18u);
	// 0x28D828: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28D830: movss [0x0056BE98], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE98u, ctx.xmm[0].u32[0]);
	// 0x28D838: ret
	return;
}

void sub_28D840(X86Context& ctx, uint8_t* base) {
	// 0x28D840: movss xmm0, dword ptr [0x0056BE18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE18u);
	// 0x28D848: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28D850: movss [0x0056BE40], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE40u, ctx.xmm[0].u32[0]);
	// 0x28D858: ret
	return;
}

void sub_28D860(X86Context& ctx, uint8_t* base) {
	// 0x28D860: movss xmm0, dword ptr [0x0056BE18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE18u);
	// 0x28D868: subss xmm0, [0x0056BE40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BE40u);
	// 0x28D870: movss [0x0056BE20], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE20u, ctx.xmm[0].u32[0]);
	// 0x28D878: ret
	return;
}

void sub_28D880(X86Context& ctx, uint8_t* base) {
	// 0x28D880: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28D888: movss [0x0056BE68], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE68u, ctx.xmm[0].u32[0]);
	// 0x28D890: ret
	return;
}

void sub_28D8A0(X86Context& ctx, uint8_t* base) {
	// 0x28D8A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28D8A8: movss [0x0056BE1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE1Cu, ctx.xmm[0].u32[0]);
	// 0x28D8B0: ret
	return;
}

void sub_28D8C0(X86Context& ctx, uint8_t* base) {
	// 0x28D8C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28D8C8: movss [0x0056BE2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE2Cu, ctx.xmm[0].u32[0]);
	// 0x28D8D0: ret
	return;
}

void sub_28D8E0(X86Context& ctx, uint8_t* base) {
	// 0x28D8E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28D8E8: movss [0x0056BE80], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE80u, ctx.xmm[0].u32[0]);
	// 0x28D8F0: ret
	return;
}

void sub_28D900(X86Context& ctx, uint8_t* base) {
	// 0x28D900: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28D908: movss [0x0056BE64], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE64u, ctx.xmm[0].u32[0]);
	// 0x28D910: ret
	return;
}

void sub_28D920(X86Context& ctx, uint8_t* base) {
	// 0x28D920: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28D928: movss [0x0056BE14], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE14u, ctx.xmm[0].u32[0]);
	// 0x28D930: ret
	return;
}

void sub_28D940(X86Context& ctx, uint8_t* base) {
	// 0x28D940: movss xmm0, dword ptr [0x0056BE2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE2Cu);
	// 0x28D948: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28D950: movss [0x0056BE08], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE08u, ctx.xmm[0].u32[0]);
	// 0x28D958: ret
	return;
}

void sub_28D960(X86Context& ctx, uint8_t* base) {
	// 0x28D960: movss xmm0, dword ptr [0x0056BE80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE80u);
	// 0x28D968: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28D970: movss [0x0056BE4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE4Cu, ctx.xmm[0].u32[0]);
	// 0x28D978: ret
	return;
}

void sub_28D980(X86Context& ctx, uint8_t* base) {
	// 0x28D980: movss xmm0, dword ptr [0x0056BE08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE08u);
	// 0x28D988: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28D990: movss [0x0056BE5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE5Cu, ctx.xmm[0].u32[0]);
	// 0x28D998: ret
	return;
}

void sub_28D9A0(X86Context& ctx, uint8_t* base) {
	// 0x28D9A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28D9A8: movss [0x0056BE00], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE00u, ctx.xmm[0].u32[0]);
	// 0x28D9B0: ret
	return;
}

void sub_28D9C0(X86Context& ctx, uint8_t* base) {
	// 0x28D9C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28D9C8: movss [0x0056BE30], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE30u, ctx.xmm[0].u32[0]);
	// 0x28D9D0: ret
	return;
}

void sub_28D9E0(X86Context& ctx, uint8_t* base) {
	// 0x28D9E0: movss xmm0, dword ptr [0x0056BE2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE2Cu);
	// 0x28D9E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28D9F0: movss [0x0056BE3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE3Cu, ctx.xmm[0].u32[0]);
	// 0x28D9F8: ret
	return;
}

void sub_28DA00(X86Context& ctx, uint8_t* base) {
	// 0x28DA00: movss xmm0, dword ptr [0x0056BE80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE80u);
	// 0x28DA08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28DA10: movss [0x0056BE84], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE84u, ctx.xmm[0].u32[0]);
	// 0x28DA18: ret
	return;
}

void sub_28DA20(X86Context& ctx, uint8_t* base) {
	// 0x28DA20: movss xmm0, dword ptr [0x0056BE3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE3Cu);
	// 0x28DA28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DA30: movss [0x0056BE70], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE70u, ctx.xmm[0].u32[0]);
	// 0x28DA38: ret
	return;
}

void sub_28DA40(X86Context& ctx, uint8_t* base) {
	// 0x28DA40: movss xmm0, dword ptr [0x0056BE84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE84u);
	// 0x28DA48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DA50: movss [0x0056BE94], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE94u, ctx.xmm[0].u32[0]);
	// 0x28DA58: ret
	return;
}

void sub_28DA60(X86Context& ctx, uint8_t* base) {
	// 0x28DA60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28DA68: movss [0x0056BE0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE0Cu, ctx.xmm[0].u32[0]);
	// 0x28DA70: ret
	return;
}

void sub_28DA80(X86Context& ctx, uint8_t* base) {
	// 0x28DA80: movss xmm0, dword ptr [0x0056BE2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE2Cu);
	// 0x28DA88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DA90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28DA98: movss [0x0056BE7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE7Cu, ctx.xmm[0].u32[0]);
	// 0x28DAA0: ret
	return;
}

void sub_28DAB0(X86Context& ctx, uint8_t* base) {
	// 0x28DAB0: movss xmm0, dword ptr [0x0056BE80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE80u);
	// 0x28DAB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DAC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28DAC8: movss [0x0056BE24], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE24u, ctx.xmm[0].u32[0]);
	// 0x28DAD0: ret
	return;
}

void sub_28DAE0(X86Context& ctx, uint8_t* base) {
	// 0x28DAE0: movss xmm0, dword ptr [0x0056BE2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE2Cu);
	// 0x28DAE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DAF0: movss [0x0056BE28], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE28u, ctx.xmm[0].u32[0]);
	// 0x28DAF8: ret
	return;
}

void sub_28DB00(X86Context& ctx, uint8_t* base) {
	// 0x28DB00: movss xmm0, dword ptr [0x0056BE80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE80u);
	// 0x28DB08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DB10: movss [0x0056BE88], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE88u, ctx.xmm[0].u32[0]);
	// 0x28DB18: ret
	return;
}

void sub_28DB20(X86Context& ctx, uint8_t* base) {
	// 0x28DB20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28DB28: movss [0x0056BE10], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE10u, ctx.xmm[0].u32[0]);
	// 0x28DB30: ret
	return;
}

void sub_28DB40(X86Context& ctx, uint8_t* base) {
	// 0x28DB40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28DB48: movss [0x0056BE38], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE38u, ctx.xmm[0].u32[0]);
	// 0x28DB50: ret
	return;
}

void sub_28DB60(X86Context& ctx, uint8_t* base) {
	// 0x28DB60: movss xmm0, dword ptr [0x0056BE10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE10u);
	// 0x28DB68: movss [0x0056BE9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE9Cu, ctx.xmm[0].u32[0]);
	// 0x28DB70: ret
	return;
}

void sub_28DB80(X86Context& ctx, uint8_t* base) {
	// 0x28DB80: movss xmm0, dword ptr [0x0056BE80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE80u);
	// 0x28DB88: subss xmm0, [0x0056BE10]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BE10u);
	// 0x28DB90: movss [0x0056BE60], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE60u, ctx.xmm[0].u32[0]);
	// 0x28DB98: ret
	return;
}

void sub_28DBA0(X86Context& ctx, uint8_t* base) {
	// 0x28DBA0: movss xmm0, dword ptr [0x0056BE60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE60u);
	// 0x28DBA8: subss xmm0, [0x0056BE38]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BE38u);
	// 0x28DBB0: movss [0x0056BE58], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE58u, ctx.xmm[0].u32[0]);
	// 0x28DBB8: ret
	return;
}

