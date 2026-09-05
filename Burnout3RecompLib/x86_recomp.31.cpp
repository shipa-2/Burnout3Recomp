#include "x86_recomp_shared.h"

void sub_25BC30(X86Context& ctx, uint8_t* base) {
	// 0x25BC30: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25BC38: movss [0x004D5C94], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C94u, ctx.xmm[0].u32[0]);
	// 0x25BC40: ret
	return;
}

void sub_25BC50(X86Context& ctx, uint8_t* base) {
	// 0x25BC50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25BC58: movss [0x004D5CF4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CF4u, ctx.xmm[0].u32[0]);
	// 0x25BC60: ret
	return;
}

void sub_25BC70(X86Context& ctx, uint8_t* base) {
	// 0x25BC70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25BC78: movss [0x004D5CB0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CB0u, ctx.xmm[0].u32[0]);
	// 0x25BC80: ret
	return;
}

void sub_25BC90(X86Context& ctx, uint8_t* base) {
	// 0x25BC90: movss xmm0, dword ptr [0x004D5CF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CF4u);
	// 0x25BC98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25BCA0: movss [0x004D5D2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D2Cu, ctx.xmm[0].u32[0]);
	// 0x25BCA8: ret
	return;
}

void sub_25BCB0(X86Context& ctx, uint8_t* base) {
	// 0x25BCB0: movss xmm0, dword ptr [0x004D5CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CB0u);
	// 0x25BCB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25BCC0: movss [0x004D5D14], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D14u, ctx.xmm[0].u32[0]);
	// 0x25BCC8: ret
	return;
}

void sub_25BCD0(X86Context& ctx, uint8_t* base) {
	// 0x25BCD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25BCD8: movss [0x004D5D44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D44u, ctx.xmm[0].u32[0]);
	// 0x25BCE0: ret
	return;
}

void sub_25BCF0(X86Context& ctx, uint8_t* base) {
	// 0x25BCF0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25BCF8: movss [0x004D5D30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D30u, ctx.xmm[0].u32[0]);
	// 0x25BD00: ret
	return;
}

void sub_25BD10(X86Context& ctx, uint8_t* base) {
	// 0x25BD10: movss xmm0, dword ptr [0x004D5D30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D30u);
	// 0x25BD18: movss [0x004D5D40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D40u, ctx.xmm[0].u32[0]);
	// 0x25BD20: ret
	return;
}

void sub_25BD30(X86Context& ctx, uint8_t* base) {
	// 0x25BD30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25BD38: movss [0x004D5C9C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C9Cu, ctx.xmm[0].u32[0]);
	// 0x25BD40: ret
	return;
}

void sub_25BD50(X86Context& ctx, uint8_t* base) {
	// 0x25BD50: movss xmm0, dword ptr [0x004D5CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CB0u);
	// 0x25BD58: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25BD60: movss [0x004D5D38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D38u, ctx.xmm[0].u32[0]);
	// 0x25BD68: ret
	return;
}

void sub_25BD70(X86Context& ctx, uint8_t* base) {
	// 0x25BD70: movss xmm0, dword ptr [0x004D5CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CB0u);
	// 0x25BD78: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25BD80: movss [0x004D5CDC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CDCu, ctx.xmm[0].u32[0]);
	// 0x25BD88: ret
	return;
}

void sub_25BD90(X86Context& ctx, uint8_t* base) {
	// 0x25BD90: movss xmm0, dword ptr [0x004D5CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CB0u);
	// 0x25BD98: subss xmm0, [0x004D5CDC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5CDCu);
	// 0x25BDA0: movss [0x004D5CB8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CB8u, ctx.xmm[0].u32[0]);
	// 0x25BDA8: ret
	return;
}

void sub_25BDB0(X86Context& ctx, uint8_t* base) {
	// 0x25BDB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25BDB8: movss [0x004D5D08], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D08u, ctx.xmm[0].u32[0]);
	// 0x25BDC0: ret
	return;
}

void sub_25BDD0(X86Context& ctx, uint8_t* base) {
	// 0x25BDD0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25BDD8: movss [0x004D5CB4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CB4u, ctx.xmm[0].u32[0]);
	// 0x25BDE0: ret
	return;
}

void sub_25BDF0(X86Context& ctx, uint8_t* base) {
	// 0x25BDF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25BDF8: movss [0x004D5CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CC8u, ctx.xmm[0].u32[0]);
	// 0x25BE00: ret
	return;
}

void sub_25BE10(X86Context& ctx, uint8_t* base) {
	// 0x25BE10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25BE18: movss [0x004D5D20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D20u, ctx.xmm[0].u32[0]);
	// 0x25BE20: ret
	return;
}

void sub_25BE30(X86Context& ctx, uint8_t* base) {
	// 0x25BE30: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x25BE38: movss [0x004D5D04], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D04u, ctx.xmm[0].u32[0]);
	// 0x25BE40: ret
	return;
}

void sub_25BE50(X86Context& ctx, uint8_t* base) {
	// 0x25BE50: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x25BE58: movss [0x004D5CAC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CACu, ctx.xmm[0].u32[0]);
	// 0x25BE60: ret
	return;
}

void sub_25BE70(X86Context& ctx, uint8_t* base) {
	// 0x25BE70: movss xmm0, dword ptr [0x004D5CC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CC8u);
	// 0x25BE78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25BE80: movss [0x004D5CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CA0u, ctx.xmm[0].u32[0]);
	// 0x25BE88: ret
	return;
}

void sub_25BE90(X86Context& ctx, uint8_t* base) {
	// 0x25BE90: movss xmm0, dword ptr [0x004D5D20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D20u);
	// 0x25BE98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25BEA0: movss [0x004D5CE8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CE8u, ctx.xmm[0].u32[0]);
	// 0x25BEA8: ret
	return;
}

void sub_25BEB0(X86Context& ctx, uint8_t* base) {
	// 0x25BEB0: movss xmm0, dword ptr [0x004D5CA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CA0u);
	// 0x25BEB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25BEC0: movss [0x004D5CFC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CFCu, ctx.xmm[0].u32[0]);
	// 0x25BEC8: ret
	return;
}

void sub_25BED0(X86Context& ctx, uint8_t* base) {
	// 0x25BED0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25BED8: movss [0x004D5C98], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C98u, ctx.xmm[0].u32[0]);
	// 0x25BEE0: ret
	return;
}

void sub_25BEF0(X86Context& ctx, uint8_t* base) {
	// 0x25BEF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25BEF8: movss [0x004D5CCC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CCCu, ctx.xmm[0].u32[0]);
	// 0x25BF00: ret
	return;
}

void sub_25BF10(X86Context& ctx, uint8_t* base) {
	// 0x25BF10: movss xmm0, dword ptr [0x004D5CC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CC8u);
	// 0x25BF18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25BF20: movss [0x004D5CD8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CD8u, ctx.xmm[0].u32[0]);
	// 0x25BF28: ret
	return;
}

void sub_25BF30(X86Context& ctx, uint8_t* base) {
	// 0x25BF30: movss xmm0, dword ptr [0x004D5D20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D20u);
	// 0x25BF38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25BF40: movss [0x004D5D24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D24u, ctx.xmm[0].u32[0]);
	// 0x25BF48: ret
	return;
}

void sub_25BF50(X86Context& ctx, uint8_t* base) {
	// 0x25BF50: movss xmm0, dword ptr [0x004D5CD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CD8u);
	// 0x25BF58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25BF60: movss [0x004D5D10], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D10u, ctx.xmm[0].u32[0]);
	// 0x25BF68: ret
	return;
}

void sub_25BF70(X86Context& ctx, uint8_t* base) {
	// 0x25BF70: movss xmm0, dword ptr [0x004D5D24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D24u);
	// 0x25BF78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25BF80: movss [0x004D5D34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D34u, ctx.xmm[0].u32[0]);
	// 0x25BF88: ret
	return;
}

void sub_25BF90(X86Context& ctx, uint8_t* base) {
	// 0x25BF90: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x25BF98: movss [0x004D5CA4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CA4u, ctx.xmm[0].u32[0]);
	// 0x25BFA0: ret
	return;
}

void sub_25BFB0(X86Context& ctx, uint8_t* base) {
	// 0x25BFB0: movss xmm0, dword ptr [0x004D5CC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CC8u);
	// 0x25BFB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25BFC0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x25BFC8: movss [0x004D5D1C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D1Cu, ctx.xmm[0].u32[0]);
	// 0x25BFD0: ret
	return;
}

void sub_25BFE0(X86Context& ctx, uint8_t* base) {
	// 0x25BFE0: movss xmm0, dword ptr [0x004D5D20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D20u);
	// 0x25BFE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25BFF0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x25BFF8: movss [0x004D5CBC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CBCu, ctx.xmm[0].u32[0]);
	// 0x25C000: ret
	return;
}

void sub_25C010(X86Context& ctx, uint8_t* base) {
	// 0x25C010: movss xmm0, dword ptr [0x004D5CC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CC8u);
	// 0x25C018: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C020: movss [0x004D5CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CC0u, ctx.xmm[0].u32[0]);
	// 0x25C028: ret
	return;
}

void sub_25C030(X86Context& ctx, uint8_t* base) {
	// 0x25C030: movss xmm0, dword ptr [0x004D5D20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D20u);
	// 0x25C038: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C040: movss [0x004D5D28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D28u, ctx.xmm[0].u32[0]);
	// 0x25C048: ret
	return;
}

void sub_25C050(X86Context& ctx, uint8_t* base) {
	// 0x25C050: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x25C058: movss [0x004D5CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CA8u, ctx.xmm[0].u32[0]);
	// 0x25C060: ret
	return;
}

void sub_25C070(X86Context& ctx, uint8_t* base) {
	// 0x25C070: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x25C078: movss [0x004D5CD4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CD4u, ctx.xmm[0].u32[0]);
	// 0x25C080: ret
	return;
}

void sub_25C090(X86Context& ctx, uint8_t* base) {
	// 0x25C090: movss xmm0, dword ptr [0x004D5CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CA8u);
	// 0x25C098: movss [0x004D5D3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D3Cu, ctx.xmm[0].u32[0]);
	// 0x25C0A0: ret
	return;
}

void sub_25C0B0(X86Context& ctx, uint8_t* base) {
	// 0x25C0B0: movss xmm0, dword ptr [0x004D5D20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D20u);
	// 0x25C0B8: subss xmm0, [0x004D5CA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5CA8u);
	// 0x25C0C0: movss [0x004D5D00], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D00u, ctx.xmm[0].u32[0]);
	// 0x25C0C8: ret
	return;
}

void sub_25C0D0(X86Context& ctx, uint8_t* base) {
	// 0x25C0D0: movss xmm0, dword ptr [0x004D5D00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D00u);
	// 0x25C0D8: subss xmm0, [0x004D5CD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5CD4u);
	// 0x25C0E0: movss [0x004D5CF8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CF8u, ctx.xmm[0].u32[0]);
	// 0x25C0E8: ret
	return;
}

void sub_25C0F0(X86Context& ctx, uint8_t* base) {
	// 0x25C0F0: movss xmm0, dword ptr [0x004D5D28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D28u);
	// 0x25C0F8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x25C100: movss [0x004D5CE4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CE4u, ctx.xmm[0].u32[0]);
	// 0x25C108: ret
	return;
}

void sub_25C110(X86Context& ctx, uint8_t* base) {
	// 0x25C110: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x25C118: movss [0x004D5CD0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CD0u, ctx.xmm[0].u32[0]);
	// 0x25C120: ret
	return;
}

void sub_25C130(X86Context& ctx, uint8_t* base) {
	// 0x25C130: movss xmm0, dword ptr [0x004D5CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5CE4u);
	// 0x25C138: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x25C140: movss [0x004D5D18], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D18u, ctx.xmm[0].u32[0]);
	// 0x25C148: ret
	return;
}

void sub_25C150(X86Context& ctx, uint8_t* base) {
	// 0x25C150: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25C158: movss [0x004D5CEC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CECu, ctx.xmm[0].u32[0]);
	// 0x25C160: ret
	return;
}

void sub_25C170(X86Context& ctx, uint8_t* base) {
	// 0x25C170: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x25C178: movss [0x004D5CC4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CC4u, ctx.xmm[0].u32[0]);
	// 0x25C180: ret
	return;
}

void sub_25C190(X86Context& ctx, uint8_t* base) {
	// 0x25C190: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25C198: movss [0x004D5DA4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DA4u, ctx.xmm[0].u32[0]);
	// 0x25C1A0: ret
	return;
}

void sub_25C1B0(X86Context& ctx, uint8_t* base) {
	// 0x25C1B0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25C1B8: movss [0x004D5DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DC0u, ctx.xmm[0].u32[0]);
	// 0x25C1C0: ret
	return;
}

void sub_25C1D0(X86Context& ctx, uint8_t* base) {
	// 0x25C1D0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25C1D8: movss [0x004D5D94], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D94u, ctx.xmm[0].u32[0]);
	// 0x25C1E0: ret
	return;
}

void sub_25C1F0(X86Context& ctx, uint8_t* base) {
	// 0x25C1F0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25C1F8: movss [0x004D5D48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D48u, ctx.xmm[0].u32[0]);
	// 0x25C200: ret
	return;
}

void sub_25C210(X86Context& ctx, uint8_t* base) {
	// 0x25C210: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25C218: movss [0x004D5DA8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DA8u, ctx.xmm[0].u32[0]);
	// 0x25C220: ret
	return;
}

void sub_25C230(X86Context& ctx, uint8_t* base) {
	// 0x25C230: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25C238: movss [0x004D5D64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D64u, ctx.xmm[0].u32[0]);
	// 0x25C240: ret
	return;
}

void sub_25C250(X86Context& ctx, uint8_t* base) {
	// 0x25C250: movss xmm0, dword ptr [0x004D5DA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DA8u);
	// 0x25C258: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25C260: movss [0x004D5DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DE0u, ctx.xmm[0].u32[0]);
	// 0x25C268: ret
	return;
}

void sub_25C270(X86Context& ctx, uint8_t* base) {
	// 0x25C270: movss xmm0, dword ptr [0x004D5D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D64u);
	// 0x25C278: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25C280: movss [0x004D5DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DC8u, ctx.xmm[0].u32[0]);
	// 0x25C288: ret
	return;
}

void sub_25C290(X86Context& ctx, uint8_t* base) {
	// 0x25C290: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25C298: movss [0x004D5DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DF8u, ctx.xmm[0].u32[0]);
	// 0x25C2A0: ret
	return;
}

void sub_25C2B0(X86Context& ctx, uint8_t* base) {
	// 0x25C2B0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25C2B8: movss [0x004D5DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DE4u, ctx.xmm[0].u32[0]);
	// 0x25C2C0: ret
	return;
}

void sub_25C2D0(X86Context& ctx, uint8_t* base) {
	// 0x25C2D0: movss xmm0, dword ptr [0x004D5DE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DE4u);
	// 0x25C2D8: movss [0x004D5DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DF4u, ctx.xmm[0].u32[0]);
	// 0x25C2E0: ret
	return;
}

void sub_25C2F0(X86Context& ctx, uint8_t* base) {
	// 0x25C2F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25C2F8: movss [0x004D5D50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D50u, ctx.xmm[0].u32[0]);
	// 0x25C300: ret
	return;
}

void sub_25C310(X86Context& ctx, uint8_t* base) {
	// 0x25C310: movss xmm0, dword ptr [0x004D5D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D64u);
	// 0x25C318: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25C320: movss [0x004D5DEC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DECu, ctx.xmm[0].u32[0]);
	// 0x25C328: ret
	return;
}

void sub_25C330(X86Context& ctx, uint8_t* base) {
	// 0x25C330: movss xmm0, dword ptr [0x004D5D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D64u);
	// 0x25C338: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25C340: movss [0x004D5D90], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D90u, ctx.xmm[0].u32[0]);
	// 0x25C348: ret
	return;
}

void sub_25C350(X86Context& ctx, uint8_t* base) {
	// 0x25C350: movss xmm0, dword ptr [0x004D5D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D64u);
	// 0x25C358: subss xmm0, [0x004D5D90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5D90u);
	// 0x25C360: movss [0x004D5D6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D6Cu, ctx.xmm[0].u32[0]);
	// 0x25C368: ret
	return;
}

void sub_25C370(X86Context& ctx, uint8_t* base) {
	// 0x25C370: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25C378: movss [0x004D5DBC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DBCu, ctx.xmm[0].u32[0]);
	// 0x25C380: ret
	return;
}

void sub_25C390(X86Context& ctx, uint8_t* base) {
	// 0x25C390: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25C398: movss [0x004D5D68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D68u, ctx.xmm[0].u32[0]);
	// 0x25C3A0: ret
	return;
}

void sub_25C3B0(X86Context& ctx, uint8_t* base) {
	// 0x25C3B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25C3B8: movss [0x004D5D7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D7Cu, ctx.xmm[0].u32[0]);
	// 0x25C3C0: ret
	return;
}

void sub_25C3D0(X86Context& ctx, uint8_t* base) {
	// 0x25C3D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25C3D8: movss [0x004D5DD4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DD4u, ctx.xmm[0].u32[0]);
	// 0x25C3E0: ret
	return;
}

void sub_25C3F0(X86Context& ctx, uint8_t* base) {
	// 0x25C3F0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x25C3F8: movss [0x004D5DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DB8u, ctx.xmm[0].u32[0]);
	// 0x25C400: ret
	return;
}

void sub_25C410(X86Context& ctx, uint8_t* base) {
	// 0x25C410: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x25C418: movss [0x004D5D60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D60u, ctx.xmm[0].u32[0]);
	// 0x25C420: ret
	return;
}

void sub_25C430(X86Context& ctx, uint8_t* base) {
	// 0x25C430: movss xmm0, dword ptr [0x004D5D7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D7Cu);
	// 0x25C438: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25C440: movss [0x004D5D54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D54u, ctx.xmm[0].u32[0]);
	// 0x25C448: ret
	return;
}

void sub_25C450(X86Context& ctx, uint8_t* base) {
	// 0x25C450: movss xmm0, dword ptr [0x004D5DD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DD4u);
	// 0x25C458: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25C460: movss [0x004D5D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D9Cu, ctx.xmm[0].u32[0]);
	// 0x25C468: ret
	return;
}

void sub_25C470(X86Context& ctx, uint8_t* base) {
	// 0x25C470: movss xmm0, dword ptr [0x004D5D54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D54u);
	// 0x25C478: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25C480: movss [0x004D5DB0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DB0u, ctx.xmm[0].u32[0]);
	// 0x25C488: ret
	return;
}

void sub_25C490(X86Context& ctx, uint8_t* base) {
	// 0x25C490: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25C498: movss [0x004D5D4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D4Cu, ctx.xmm[0].u32[0]);
	// 0x25C4A0: ret
	return;
}

void sub_25C4B0(X86Context& ctx, uint8_t* base) {
	// 0x25C4B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25C4B8: movss [0x004D5D80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D80u, ctx.xmm[0].u32[0]);
	// 0x25C4C0: ret
	return;
}

void sub_25C4D0(X86Context& ctx, uint8_t* base) {
	// 0x25C4D0: movss xmm0, dword ptr [0x004D5D7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D7Cu);
	// 0x25C4D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25C4E0: movss [0x004D5D8C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D8Cu, ctx.xmm[0].u32[0]);
	// 0x25C4E8: ret
	return;
}

void sub_25C4F0(X86Context& ctx, uint8_t* base) {
	// 0x25C4F0: movss xmm0, dword ptr [0x004D5DD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DD4u);
	// 0x25C4F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25C500: movss [0x004D5DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DD8u, ctx.xmm[0].u32[0]);
	// 0x25C508: ret
	return;
}

void sub_25C510(X86Context& ctx, uint8_t* base) {
	// 0x25C510: movss xmm0, dword ptr [0x004D5D8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D8Cu);
	// 0x25C518: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C520: movss [0x004D5DC4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DC4u, ctx.xmm[0].u32[0]);
	// 0x25C528: ret
	return;
}

void sub_25C530(X86Context& ctx, uint8_t* base) {
	// 0x25C530: movss xmm0, dword ptr [0x004D5DD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DD8u);
	// 0x25C538: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C540: movss [0x004D5DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DE8u, ctx.xmm[0].u32[0]);
	// 0x25C548: ret
	return;
}

void sub_25C550(X86Context& ctx, uint8_t* base) {
	// 0x25C550: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x25C558: movss [0x004D5D58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D58u, ctx.xmm[0].u32[0]);
	// 0x25C560: ret
	return;
}

void sub_25C570(X86Context& ctx, uint8_t* base) {
	// 0x25C570: movss xmm0, dword ptr [0x004D5D7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D7Cu);
	// 0x25C578: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C580: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x25C588: movss [0x004D5DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DD0u, ctx.xmm[0].u32[0]);
	// 0x25C590: ret
	return;
}

void sub_25C5A0(X86Context& ctx, uint8_t* base) {
	// 0x25C5A0: movss xmm0, dword ptr [0x004D5DD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DD4u);
	// 0x25C5A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C5B0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x25C5B8: movss [0x004D5D70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D70u, ctx.xmm[0].u32[0]);
	// 0x25C5C0: ret
	return;
}

void sub_25C5D0(X86Context& ctx, uint8_t* base) {
	// 0x25C5D0: movss xmm0, dword ptr [0x004D5D7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D7Cu);
	// 0x25C5D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C5E0: movss [0x004D5D74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D74u, ctx.xmm[0].u32[0]);
	// 0x25C5E8: ret
	return;
}

void sub_25C5F0(X86Context& ctx, uint8_t* base) {
	// 0x25C5F0: movss xmm0, dword ptr [0x004D5DD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DD4u);
	// 0x25C5F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25C600: movss [0x004D5DDC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DDCu, ctx.xmm[0].u32[0]);
	// 0x25C608: ret
	return;
}

void sub_25C610(X86Context& ctx, uint8_t* base) {
	// 0x25C610: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x25C618: movss [0x004D5D5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D5Cu, ctx.xmm[0].u32[0]);
	// 0x25C620: ret
	return;
}

void sub_25C630(X86Context& ctx, uint8_t* base) {
	// 0x25C630: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x25C638: movss [0x004D5D88], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D88u, ctx.xmm[0].u32[0]);
	// 0x25C640: ret
	return;
}

void sub_25C650(X86Context& ctx, uint8_t* base) {
	// 0x25C650: movss xmm0, dword ptr [0x004D5D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D5Cu);
	// 0x25C658: movss [0x004D5DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DF0u, ctx.xmm[0].u32[0]);
	// 0x25C660: ret
	return;
}

void sub_25C670(X86Context& ctx, uint8_t* base) {
	// 0x25C670: movss xmm0, dword ptr [0x004D5DD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DD4u);
	// 0x25C678: subss xmm0, [0x004D5D5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5D5Cu);
	// 0x25C680: movss [0x004D5DB4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DB4u, ctx.xmm[0].u32[0]);
	// 0x25C688: ret
	return;
}

void sub_25C690(X86Context& ctx, uint8_t* base) {
	// 0x25C690: movss xmm0, dword ptr [0x004D5DB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DB4u);
	// 0x25C698: subss xmm0, [0x004D5D88]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5D88u);
	// 0x25C6A0: movss [0x004D5DAC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DACu, ctx.xmm[0].u32[0]);
	// 0x25C6A8: ret
	return;
}

void sub_25C6B0(X86Context& ctx, uint8_t* base) {
	// 0x25C6B0: movss xmm0, dword ptr [0x004D5DDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5DDCu);
	// 0x25C6B8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x25C6C0: movss [0x004D5D98], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D98u, ctx.xmm[0].u32[0]);
	// 0x25C6C8: ret
	return;
}

void sub_25C6D0(X86Context& ctx, uint8_t* base) {
	// 0x25C6D0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x25C6D8: movss [0x004D5D84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D84u, ctx.xmm[0].u32[0]);
	// 0x25C6E0: ret
	return;
}

void sub_25C6F0(X86Context& ctx, uint8_t* base) {
	// 0x25C6F0: movss xmm0, dword ptr [0x004D5D98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5D98u);
	// 0x25C6F8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x25C700: movss [0x004D5DCC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DCCu, ctx.xmm[0].u32[0]);
	// 0x25C708: ret
	return;
}

void sub_25C710(X86Context& ctx, uint8_t* base) {
	// 0x25C710: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25C718: movss [0x004D5DA0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DA0u, ctx.xmm[0].u32[0]);
	// 0x25C720: ret
	return;
}

void sub_25C730(X86Context& ctx, uint8_t* base) {
	// 0x25C730: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x25C738: movss [0x004D5D78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D78u, ctx.xmm[0].u32[0]);
	// 0x25C740: ret
	return;
}

void sub_25C750(X86Context& ctx, uint8_t* base) {
	// 0x25C750: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25C758: movss [0x004D5E58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E58u, ctx.xmm[0].u32[0]);
	// 0x25C760: ret
	return;
}

void sub_25C770(X86Context& ctx, uint8_t* base) {
	// 0x25C770: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25C778: movss [0x004D5E74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E74u, ctx.xmm[0].u32[0]);
	// 0x25C780: ret
	return;
}

void sub_25C790(X86Context& ctx, uint8_t* base) {
	// 0x25C790: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25C798: movss [0x004D5E48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E48u, ctx.xmm[0].u32[0]);
	// 0x25C7A0: ret
	return;
}

void sub_25C7B0(X86Context& ctx, uint8_t* base) {
	// 0x25C7B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25C7B8: movss [0x004D5DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5DFCu, ctx.xmm[0].u32[0]);
	// 0x25C7C0: ret
	return;
}

void sub_25C7D0(X86Context& ctx, uint8_t* base) {
	// 0x25C7D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25C7D8: movss [0x004D5E5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E5Cu, ctx.xmm[0].u32[0]);
	// 0x25C7E0: ret
	return;
}

void sub_25C7F0(X86Context& ctx, uint8_t* base) {
	// 0x25C7F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25C7F8: movss [0x004D5E18], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E18u, ctx.xmm[0].u32[0]);
	// 0x25C800: ret
	return;
}

void sub_25C810(X86Context& ctx, uint8_t* base) {
	// 0x25C810: movss xmm0, dword ptr [0x004D5E5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E5Cu);
	// 0x25C818: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25C820: movss [0x004D5E94], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E94u, ctx.xmm[0].u32[0]);
	// 0x25C828: ret
	return;
}

void sub_25C830(X86Context& ctx, uint8_t* base) {
	// 0x25C830: movss xmm0, dword ptr [0x004D5E18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E18u);
	// 0x25C838: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25C840: movss [0x004D5E7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E7Cu, ctx.xmm[0].u32[0]);
	// 0x25C848: ret
	return;
}

void sub_25C850(X86Context& ctx, uint8_t* base) {
	// 0x25C850: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25C858: movss [0x004D5EAC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EACu, ctx.xmm[0].u32[0]);
	// 0x25C860: ret
	return;
}

void sub_25C870(X86Context& ctx, uint8_t* base) {
	// 0x25C870: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25C878: movss [0x004D5E98], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E98u, ctx.xmm[0].u32[0]);
	// 0x25C880: ret
	return;
}

void sub_25C890(X86Context& ctx, uint8_t* base) {
	// 0x25C890: movss xmm0, dword ptr [0x004D5E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E98u);
	// 0x25C898: movss [0x004D5EA8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EA8u, ctx.xmm[0].u32[0]);
	// 0x25C8A0: ret
	return;
}

void sub_25C8B0(X86Context& ctx, uint8_t* base) {
	// 0x25C8B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25C8B8: movss [0x004D5E04], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E04u, ctx.xmm[0].u32[0]);
	// 0x25C8C0: ret
	return;
}

void sub_25C8D0(X86Context& ctx, uint8_t* base) {
	// 0x25C8D0: movss xmm0, dword ptr [0x004D5E18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E18u);
	// 0x25C8D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25C8E0: movss [0x004D5EA0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EA0u, ctx.xmm[0].u32[0]);
	// 0x25C8E8: ret
	return;
}

void sub_25C8F0(X86Context& ctx, uint8_t* base) {
	// 0x25C8F0: movss xmm0, dword ptr [0x004D5E18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E18u);
	// 0x25C8F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25C900: movss [0x004D5E44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E44u, ctx.xmm[0].u32[0]);
	// 0x25C908: ret
	return;
}

void sub_25C910(X86Context& ctx, uint8_t* base) {
	// 0x25C910: movss xmm0, dword ptr [0x004D5E18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E18u);
	// 0x25C918: subss xmm0, [0x004D5E44]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5E44u);
	// 0x25C920: movss [0x004D5E20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E20u, ctx.xmm[0].u32[0]);
	// 0x25C928: ret
	return;
}

void sub_25C930(X86Context& ctx, uint8_t* base) {
	// 0x25C930: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25C938: movss [0x004D5E70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E70u, ctx.xmm[0].u32[0]);
	// 0x25C940: ret
	return;
}

void sub_25C950(X86Context& ctx, uint8_t* base) {
	// 0x25C950: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25C958: movss [0x004D5E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E1Cu, ctx.xmm[0].u32[0]);
	// 0x25C960: ret
	return;
}

void sub_25C970(X86Context& ctx, uint8_t* base) {
	// 0x25C970: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25C978: movss [0x004D5E30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E30u, ctx.xmm[0].u32[0]);
	// 0x25C980: ret
	return;
}

void sub_25C990(X86Context& ctx, uint8_t* base) {
	// 0x25C990: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25C998: movss [0x004D5E88], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E88u, ctx.xmm[0].u32[0]);
	// 0x25C9A0: ret
	return;
}

void sub_25C9B0(X86Context& ctx, uint8_t* base) {
	// 0x25C9B0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x25C9B8: movss [0x004D5E6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E6Cu, ctx.xmm[0].u32[0]);
	// 0x25C9C0: ret
	return;
}

void sub_25C9D0(X86Context& ctx, uint8_t* base) {
	// 0x25C9D0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x25C9D8: movss [0x004D5E14], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E14u, ctx.xmm[0].u32[0]);
	// 0x25C9E0: ret
	return;
}

void sub_25C9F0(X86Context& ctx, uint8_t* base) {
	// 0x25C9F0: movss xmm0, dword ptr [0x004D5E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E30u);
	// 0x25C9F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25CA00: movss [0x004D5E08], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E08u, ctx.xmm[0].u32[0]);
	// 0x25CA08: ret
	return;
}

void sub_25CA10(X86Context& ctx, uint8_t* base) {
	// 0x25CA10: movss xmm0, dword ptr [0x004D5E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E88u);
	// 0x25CA18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25CA20: movss [0x004D5E50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E50u, ctx.xmm[0].u32[0]);
	// 0x25CA28: ret
	return;
}

void sub_25CA30(X86Context& ctx, uint8_t* base) {
	// 0x25CA30: movss xmm0, dword ptr [0x004D5E08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E08u);
	// 0x25CA38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25CA40: movss [0x004D5E64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E64u, ctx.xmm[0].u32[0]);
	// 0x25CA48: ret
	return;
}

void sub_25CA50(X86Context& ctx, uint8_t* base) {
	// 0x25CA50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25CA58: movss [0x004D5E00], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E00u, ctx.xmm[0].u32[0]);
	// 0x25CA60: ret
	return;
}

void sub_25CA70(X86Context& ctx, uint8_t* base) {
	// 0x25CA70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25CA78: movss [0x004D5E34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E34u, ctx.xmm[0].u32[0]);
	// 0x25CA80: ret
	return;
}

void sub_25CA90(X86Context& ctx, uint8_t* base) {
	// 0x25CA90: movss xmm0, dword ptr [0x004D5E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E30u);
	// 0x25CA98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25CAA0: movss [0x004D5E40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E40u, ctx.xmm[0].u32[0]);
	// 0x25CAA8: ret
	return;
}

void sub_25CAB0(X86Context& ctx, uint8_t* base) {
	// 0x25CAB0: movss xmm0, dword ptr [0x004D5E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E88u);
	// 0x25CAB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25CAC0: movss [0x004D5E8C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E8Cu, ctx.xmm[0].u32[0]);
	// 0x25CAC8: ret
	return;
}

void sub_25CAD0(X86Context& ctx, uint8_t* base) {
	// 0x25CAD0: movss xmm0, dword ptr [0x004D5E40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E40u);
	// 0x25CAD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25CAE0: movss [0x004D5E78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E78u, ctx.xmm[0].u32[0]);
	// 0x25CAE8: ret
	return;
}

void sub_25CAF0(X86Context& ctx, uint8_t* base) {
	// 0x25CAF0: movss xmm0, dword ptr [0x004D5E8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E8Cu);
	// 0x25CAF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25CB00: movss [0x004D5E9C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E9Cu, ctx.xmm[0].u32[0]);
	// 0x25CB08: ret
	return;
}

void sub_25CB10(X86Context& ctx, uint8_t* base) {
	// 0x25CB10: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x25CB18: movss [0x004D5E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E0Cu, ctx.xmm[0].u32[0]);
	// 0x25CB20: ret
	return;
}

void sub_25CB30(X86Context& ctx, uint8_t* base) {
	// 0x25CB30: movss xmm0, dword ptr [0x004D5E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E30u);
	// 0x25CB38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25CB40: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x25CB48: movss [0x004D5E84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E84u, ctx.xmm[0].u32[0]);
	// 0x25CB50: ret
	return;
}

void sub_25CB60(X86Context& ctx, uint8_t* base) {
	// 0x25CB60: movss xmm0, dword ptr [0x004D5E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E88u);
	// 0x25CB68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25CB70: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x25CB78: movss [0x004D5E24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E24u, ctx.xmm[0].u32[0]);
	// 0x25CB80: ret
	return;
}

void sub_25CB90(X86Context& ctx, uint8_t* base) {
	// 0x25CB90: movss xmm0, dword ptr [0x004D5E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E30u);
	// 0x25CB98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25CBA0: movss [0x004D5E28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E28u, ctx.xmm[0].u32[0]);
	// 0x25CBA8: ret
	return;
}

void sub_25CBB0(X86Context& ctx, uint8_t* base) {
	// 0x25CBB0: movss xmm0, dword ptr [0x004D5E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E88u);
	// 0x25CBB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25CBC0: movss [0x004D5E90], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E90u, ctx.xmm[0].u32[0]);
	// 0x25CBC8: ret
	return;
}

void sub_25CBD0(X86Context& ctx, uint8_t* base) {
	// 0x25CBD0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x25CBD8: movss [0x004D5E10], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E10u, ctx.xmm[0].u32[0]);
	// 0x25CBE0: ret
	return;
}

void sub_25CBF0(X86Context& ctx, uint8_t* base) {
	// 0x25CBF0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x25CBF8: movss [0x004D5E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E3Cu, ctx.xmm[0].u32[0]);
	// 0x25CC00: ret
	return;
}

void sub_25CC10(X86Context& ctx, uint8_t* base) {
	// 0x25CC10: movss xmm0, dword ptr [0x004D5E10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E10u);
	// 0x25CC18: movss [0x004D5EA4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EA4u, ctx.xmm[0].u32[0]);
	// 0x25CC20: ret
	return;
}

void sub_25CC30(X86Context& ctx, uint8_t* base) {
	// 0x25CC30: movss xmm0, dword ptr [0x004D5E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E88u);
	// 0x25CC38: subss xmm0, [0x004D5E10]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5E10u);
	// 0x25CC40: movss [0x004D5E68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E68u, ctx.xmm[0].u32[0]);
	// 0x25CC48: ret
	return;
}

void sub_25CC50(X86Context& ctx, uint8_t* base) {
	// 0x25CC50: movss xmm0, dword ptr [0x004D5E68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E68u);
	// 0x25CC58: subss xmm0, [0x004D5E3C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5E3Cu);
	// 0x25CC60: movss [0x004D5E60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E60u, ctx.xmm[0].u32[0]);
	// 0x25CC68: ret
	return;
}

void sub_25CC70(X86Context& ctx, uint8_t* base) {
	// 0x25CC70: movss xmm0, dword ptr [0x004D5E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E90u);
	// 0x25CC78: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x25CC80: movss [0x004D5E4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E4Cu, ctx.xmm[0].u32[0]);
	// 0x25CC88: ret
	return;
}

void sub_25CC90(X86Context& ctx, uint8_t* base) {
	// 0x25CC90: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x25CC98: movss [0x004D5E38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E38u, ctx.xmm[0].u32[0]);
	// 0x25CCA0: ret
	return;
}

void sub_25CCB0(X86Context& ctx, uint8_t* base) {
	// 0x25CCB0: movss xmm0, dword ptr [0x004D5E4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5E4Cu);
	// 0x25CCB8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x25CCC0: movss [0x004D5E80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E80u, ctx.xmm[0].u32[0]);
	// 0x25CCC8: ret
	return;
}

void sub_25CCD0(X86Context& ctx, uint8_t* base) {
	// 0x25CCD0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25CCD8: movss [0x004D5E54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E54u, ctx.xmm[0].u32[0]);
	// 0x25CCE0: ret
	return;
}

void sub_25CCF0(X86Context& ctx, uint8_t* base) {
	// 0x25CCF0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x25CCF8: movss [0x004D5E2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5E2Cu, ctx.xmm[0].u32[0]);
	// 0x25CD00: ret
	return;
}

void sub_25CD10(X86Context& ctx, uint8_t* base) {
	// 0x25CD10: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25CD18: movss [0x004D5ECC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ECCu, ctx.xmm[0].u32[0]);
	// 0x25CD20: ret
	return;
}

void sub_25CD30(X86Context& ctx, uint8_t* base) {
	// 0x25CD30: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25CD38: movss [0x004D5ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ED8u, ctx.xmm[0].u32[0]);
	// 0x25CD40: ret
	return;
}

void sub_25CD50(X86Context& ctx, uint8_t* base) {
	// 0x25CD50: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25CD58: movss [0x004D5EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EC8u, ctx.xmm[0].u32[0]);
	// 0x25CD60: ret
	return;
}

void sub_25CD70(X86Context& ctx, uint8_t* base) {
	// 0x25CD70: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25CD78: movss [0x004D5EB0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EB0u, ctx.xmm[0].u32[0]);
	// 0x25CD80: ret
	return;
}

void sub_25CD90(X86Context& ctx, uint8_t* base) {
	// 0x25CD90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25CD98: movss [0x004D5ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ED0u, ctx.xmm[0].u32[0]);
	// 0x25CDA0: ret
	return;
}

void sub_25CDB0(X86Context& ctx, uint8_t* base) {
	// 0x25CDB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25CDB8: movss [0x004D5EB8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EB8u, ctx.xmm[0].u32[0]);
	// 0x25CDC0: ret
	return;
}

void sub_25CDD0(X86Context& ctx, uint8_t* base) {
	// 0x25CDD0: movss xmm0, dword ptr [0x004D5ED0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5ED0u);
	// 0x25CDD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25CDE0: movss [0x004D5EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EE0u, ctx.xmm[0].u32[0]);
	// 0x25CDE8: ret
	return;
}

void sub_25CDF0(X86Context& ctx, uint8_t* base) {
	// 0x25CDF0: movss xmm0, dword ptr [0x004D5EB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5EB8u);
	// 0x25CDF8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25CE00: movss [0x004D5EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EDCu, ctx.xmm[0].u32[0]);
	// 0x25CE08: ret
	return;
}

void sub_25CE10(X86Context& ctx, uint8_t* base) {
	// 0x25CE10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25CE18: movss [0x004D5EF0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EF0u, ctx.xmm[0].u32[0]);
	// 0x25CE20: ret
	return;
}

void sub_25CE30(X86Context& ctx, uint8_t* base) {
	// 0x25CE30: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25CE38: movss [0x004D5EE4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EE4u, ctx.xmm[0].u32[0]);
	// 0x25CE40: ret
	return;
}

void sub_25CE50(X86Context& ctx, uint8_t* base) {
	// 0x25CE50: movss xmm0, dword ptr [0x004D5EE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5EE4u);
	// 0x25CE58: movss [0x004D5EEC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EECu, ctx.xmm[0].u32[0]);
	// 0x25CE60: ret
	return;
}

void sub_25CE70(X86Context& ctx, uint8_t* base) {
	// 0x25CE70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25CE78: movss [0x004D5EB4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EB4u, ctx.xmm[0].u32[0]);
	// 0x25CE80: ret
	return;
}

void sub_25CE90(X86Context& ctx, uint8_t* base) {
	// 0x25CE90: movss xmm0, dword ptr [0x004D5EB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5EB8u);
	// 0x25CE98: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25CEA0: movss [0x004D5EE8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EE8u, ctx.xmm[0].u32[0]);
	// 0x25CEA8: ret
	return;
}

void sub_25CEB0(X86Context& ctx, uint8_t* base) {
	// 0x25CEB0: movss xmm0, dword ptr [0x004D5EB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5EB8u);
	// 0x25CEB8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25CEC0: movss [0x004D5EC4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EC4u, ctx.xmm[0].u32[0]);
	// 0x25CEC8: ret
	return;
}

void sub_25CED0(X86Context& ctx, uint8_t* base) {
	// 0x25CED0: movss xmm0, dword ptr [0x004D5EB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5EB8u);
	// 0x25CED8: subss xmm0, [0x004D5EC4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5EC4u);
	// 0x25CEE0: movss [0x004D5EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EC0u, ctx.xmm[0].u32[0]);
	// 0x25CEE8: ret
	return;
}

void sub_25CEF0(X86Context& ctx, uint8_t* base) {
	// 0x25CEF0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25CEF8: movss [0x004D5ED4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ED4u, ctx.xmm[0].u32[0]);
	// 0x25CF00: ret
	return;
}

void sub_25CF10(X86Context& ctx, uint8_t* base) {
	// 0x25CF10: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25CF18: movss [0x004D5EBC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EBCu, ctx.xmm[0].u32[0]);
	// 0x25CF20: ret
	return;
}

void sub_25CF30(X86Context& ctx, uint8_t* base) {
	// 0x25CF30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25CF38: movss [0x004D5F14], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F14u, ctx.xmm[0].u32[0]);
	// 0x25CF40: ret
	return;
}

void sub_25CF50(X86Context& ctx, uint8_t* base) {
	// 0x25CF50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25CF58: movss [0x004D5F20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F20u, ctx.xmm[0].u32[0]);
	// 0x25CF60: ret
	return;
}

void sub_25CF70(X86Context& ctx, uint8_t* base) {
	// 0x25CF70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25CF78: movss [0x004D5F0C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F0Cu, ctx.xmm[0].u32[0]);
	// 0x25CF80: ret
	return;
}

void sub_25CF90(X86Context& ctx, uint8_t* base) {
	// 0x25CF90: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25CF98: movss [0x004D5EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EF4u, ctx.xmm[0].u32[0]);
	// 0x25CFA0: ret
	return;
}

void sub_25CFB0(X86Context& ctx, uint8_t* base) {
	// 0x25CFB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25CFB8: movss [0x004D5F18], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F18u, ctx.xmm[0].u32[0]);
	// 0x25CFC0: ret
	return;
}

void sub_25CFD0(X86Context& ctx, uint8_t* base) {
	// 0x25CFD0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25CFD8: movss [0x004D5EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EF8u, ctx.xmm[0].u32[0]);
	// 0x25CFE0: ret
	return;
}

void sub_25CFF0(X86Context& ctx, uint8_t* base) {
	// 0x25CFF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25CFF8: movss [0x004D5F28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F28u, ctx.xmm[0].u32[0]);
	// 0x25D000: ret
	return;
}

void sub_25D010(X86Context& ctx, uint8_t* base) {
	// 0x25D010: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25D018: movss [0x004D5F10], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F10u, ctx.xmm[0].u32[0]);
	// 0x25D020: ret
	return;
}

void sub_25D030(X86Context& ctx, uint8_t* base) {
	// 0x25D030: movss xmm0, dword ptr [0x004D5F28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F28u);
	// 0x25D038: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25D040: movss [0x004D5F00], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F00u, ctx.xmm[0].u32[0]);
	// 0x25D048: ret
	return;
}

void sub_25D050(X86Context& ctx, uint8_t* base) {
	// 0x25D050: movss xmm0, dword ptr [0x004D5F10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F10u);
	// 0x25D058: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25D060: movss [0x004D5F24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F24u, ctx.xmm[0].u32[0]);
	// 0x25D068: ret
	return;
}

void sub_25D070(X86Context& ctx, uint8_t* base) {
	// 0x25D070: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D078: movss [0x004D5F34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F34u, ctx.xmm[0].u32[0]);
	// 0x25D080: ret
	return;
}

void sub_25D090(X86Context& ctx, uint8_t* base) {
	// 0x25D090: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25D098: movss [0x004D5F2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F2Cu, ctx.xmm[0].u32[0]);
	// 0x25D0A0: ret
	return;
}

void sub_25D0B0(X86Context& ctx, uint8_t* base) {
	// 0x25D0B0: movss xmm0, dword ptr [0x004D5F2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F2Cu);
	// 0x25D0B8: movss [0x004D5F30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F30u, ctx.xmm[0].u32[0]);
	// 0x25D0C0: ret
	return;
}

void sub_25D0D0(X86Context& ctx, uint8_t* base) {
	// 0x25D0D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D0D8: movss [0x004D5F08], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F08u, ctx.xmm[0].u32[0]);
	// 0x25D0E0: ret
	return;
}

void sub_25D0F0(X86Context& ctx, uint8_t* base) {
	// 0x25D0F0: movss xmm0, dword ptr [0x004D5F10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F10u);
	// 0x25D0F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25D100: movss [0x004D5F04], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F04u, ctx.xmm[0].u32[0]);
	// 0x25D108: ret
	return;
}

void sub_25D110(X86Context& ctx, uint8_t* base) {
	// 0x25D110: movss xmm0, dword ptr [0x004D5F10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F10u);
	// 0x25D118: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25D120: movss [0x004D5F1C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F1Cu, ctx.xmm[0].u32[0]);
	// 0x25D128: ret
	return;
}

void sub_25D130(X86Context& ctx, uint8_t* base) {
	// 0x25D130: movss xmm0, dword ptr [0x004D5F10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F10u);
	// 0x25D138: subss xmm0, [0x004D5F1C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5F1Cu);
	// 0x25D140: movss [0x004D5EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5EFCu, ctx.xmm[0].u32[0]);
	// 0x25D148: ret
	return;
}

void sub_25D150(X86Context& ctx, uint8_t* base) {
	// 0x25D150: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25D158: movss [0x004D5F54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F54u, ctx.xmm[0].u32[0]);
	// 0x25D160: ret
	return;
}

void sub_25D170(X86Context& ctx, uint8_t* base) {
	// 0x25D170: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25D178: movss [0x004D5F60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F60u, ctx.xmm[0].u32[0]);
	// 0x25D180: ret
	return;
}

void sub_25D190(X86Context& ctx, uint8_t* base) {
	// 0x25D190: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25D198: movss [0x004D5F50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F50u, ctx.xmm[0].u32[0]);
	// 0x25D1A0: ret
	return;
}

void sub_25D1B0(X86Context& ctx, uint8_t* base) {
	// 0x25D1B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25D1B8: movss [0x004D5F38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F38u, ctx.xmm[0].u32[0]);
	// 0x25D1C0: ret
	return;
}

void sub_25D1D0(X86Context& ctx, uint8_t* base) {
	// 0x25D1D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25D1D8: movss [0x004D5F58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F58u, ctx.xmm[0].u32[0]);
	// 0x25D1E0: ret
	return;
}

void sub_25D1F0(X86Context& ctx, uint8_t* base) {
	// 0x25D1F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25D1F8: movss [0x004D5F40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F40u, ctx.xmm[0].u32[0]);
	// 0x25D200: ret
	return;
}

void sub_25D210(X86Context& ctx, uint8_t* base) {
	// 0x25D210: movss xmm0, dword ptr [0x004D5F58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F58u);
	// 0x25D218: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25D220: movss [0x004D5F68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F68u, ctx.xmm[0].u32[0]);
	// 0x25D228: ret
	return;
}

void sub_25D230(X86Context& ctx, uint8_t* base) {
	// 0x25D230: movss xmm0, dword ptr [0x004D5F40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F40u);
	// 0x25D238: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25D240: movss [0x004D5F64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F64u, ctx.xmm[0].u32[0]);
	// 0x25D248: ret
	return;
}

void sub_25D250(X86Context& ctx, uint8_t* base) {
	// 0x25D250: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D258: movss [0x004D5F78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F78u, ctx.xmm[0].u32[0]);
	// 0x25D260: ret
	return;
}

void sub_25D270(X86Context& ctx, uint8_t* base) {
	// 0x25D270: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25D278: movss [0x004D5F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F6Cu, ctx.xmm[0].u32[0]);
	// 0x25D280: ret
	return;
}

void sub_25D290(X86Context& ctx, uint8_t* base) {
	// 0x25D290: movss xmm0, dword ptr [0x004D5F6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F6Cu);
	// 0x25D298: movss [0x004D5F74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F74u, ctx.xmm[0].u32[0]);
	// 0x25D2A0: ret
	return;
}

void sub_25D2B0(X86Context& ctx, uint8_t* base) {
	// 0x25D2B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D2B8: movss [0x004D5F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F3Cu, ctx.xmm[0].u32[0]);
	// 0x25D2C0: ret
	return;
}

void sub_25D2D0(X86Context& ctx, uint8_t* base) {
	// 0x25D2D0: movss xmm0, dword ptr [0x004D5F40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F40u);
	// 0x25D2D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25D2E0: movss [0x004D5F70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F70u, ctx.xmm[0].u32[0]);
	// 0x25D2E8: ret
	return;
}

void sub_25D2F0(X86Context& ctx, uint8_t* base) {
	// 0x25D2F0: movss xmm0, dword ptr [0x004D5F40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F40u);
	// 0x25D2F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25D300: movss [0x004D5F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F4Cu, ctx.xmm[0].u32[0]);
	// 0x25D308: ret
	return;
}

void sub_25D310(X86Context& ctx, uint8_t* base) {
	// 0x25D310: movss xmm0, dword ptr [0x004D5F40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F40u);
	// 0x25D318: subss xmm0, [0x004D5F4C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5F4Cu);
	// 0x25D320: movss [0x004D5F48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F48u, ctx.xmm[0].u32[0]);
	// 0x25D328: ret
	return;
}

void sub_25D330(X86Context& ctx, uint8_t* base) {
	// 0x25D330: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25D338: movss [0x004D5F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F5Cu, ctx.xmm[0].u32[0]);
	// 0x25D340: ret
	return;
}

void sub_25D350(X86Context& ctx, uint8_t* base) {
	// 0x25D350: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25D358: movss [0x004D5F44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F44u, ctx.xmm[0].u32[0]);
	// 0x25D360: ret
	return;
}

void sub_25D370(X86Context& ctx, uint8_t* base) {
	// 0x25D370: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25D378: movss [0x004D5F98], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F98u, ctx.xmm[0].u32[0]);
	// 0x25D380: ret
	return;
}

void sub_25D390(X86Context& ctx, uint8_t* base) {
	// 0x25D390: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25D398: movss [0x004D5FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FA4u, ctx.xmm[0].u32[0]);
	// 0x25D3A0: ret
	return;
}

void sub_25D3B0(X86Context& ctx, uint8_t* base) {
	// 0x25D3B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25D3B8: movss [0x004D5F94], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F94u, ctx.xmm[0].u32[0]);
	// 0x25D3C0: ret
	return;
}

void sub_25D3D0(X86Context& ctx, uint8_t* base) {
	// 0x25D3D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25D3D8: movss [0x004D5F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F7Cu, ctx.xmm[0].u32[0]);
	// 0x25D3E0: ret
	return;
}

void sub_25D3F0(X86Context& ctx, uint8_t* base) {
	// 0x25D3F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25D3F8: movss [0x004D5F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F9Cu, ctx.xmm[0].u32[0]);
	// 0x25D400: ret
	return;
}

void sub_25D410(X86Context& ctx, uint8_t* base) {
	// 0x25D410: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25D418: movss [0x004D5F84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F84u, ctx.xmm[0].u32[0]);
	// 0x25D420: ret
	return;
}

void sub_25D430(X86Context& ctx, uint8_t* base) {
	// 0x25D430: movss xmm0, dword ptr [0x004D5F9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F9Cu);
	// 0x25D438: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25D440: movss [0x004D5FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FACu, ctx.xmm[0].u32[0]);
	// 0x25D448: ret
	return;
}

void sub_25D450(X86Context& ctx, uint8_t* base) {
	// 0x25D450: movss xmm0, dword ptr [0x004D5F84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F84u);
	// 0x25D458: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25D460: movss [0x004D5FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FA8u, ctx.xmm[0].u32[0]);
	// 0x25D468: ret
	return;
}

void sub_25D470(X86Context& ctx, uint8_t* base) {
	// 0x25D470: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D478: movss [0x004D5FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FBCu, ctx.xmm[0].u32[0]);
	// 0x25D480: ret
	return;
}

void sub_25D490(X86Context& ctx, uint8_t* base) {
	// 0x25D490: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25D498: movss [0x004D5FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FB0u, ctx.xmm[0].u32[0]);
	// 0x25D4A0: ret
	return;
}

void sub_25D4B0(X86Context& ctx, uint8_t* base) {
	// 0x25D4B0: movss xmm0, dword ptr [0x004D5FB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FB0u);
	// 0x25D4B8: movss [0x004D5FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FB8u, ctx.xmm[0].u32[0]);
	// 0x25D4C0: ret
	return;
}

void sub_25D4D0(X86Context& ctx, uint8_t* base) {
	// 0x25D4D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D4D8: movss [0x004D5F80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F80u, ctx.xmm[0].u32[0]);
	// 0x25D4E0: ret
	return;
}

void sub_25D4F0(X86Context& ctx, uint8_t* base) {
	// 0x25D4F0: movss xmm0, dword ptr [0x004D5F84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F84u);
	// 0x25D4F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25D500: movss [0x004D5FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FB4u, ctx.xmm[0].u32[0]);
	// 0x25D508: ret
	return;
}

void sub_25D510(X86Context& ctx, uint8_t* base) {
	// 0x25D510: movss xmm0, dword ptr [0x004D5F84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F84u);
	// 0x25D518: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25D520: movss [0x004D5F90], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F90u, ctx.xmm[0].u32[0]);
	// 0x25D528: ret
	return;
}

void sub_25D530(X86Context& ctx, uint8_t* base) {
	// 0x25D530: movss xmm0, dword ptr [0x004D5F84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5F84u);
	// 0x25D538: subss xmm0, [0x004D5F90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5F90u);
	// 0x25D540: movss [0x004D5F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F8Cu, ctx.xmm[0].u32[0]);
	// 0x25D548: ret
	return;
}

void sub_25D550(X86Context& ctx, uint8_t* base) {
	// 0x25D550: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25D558: movss [0x004D5FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FA0u, ctx.xmm[0].u32[0]);
	// 0x25D560: ret
	return;
}

void sub_25D570(X86Context& ctx, uint8_t* base) {
	// 0x25D570: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25D578: movss [0x004D5F88], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5F88u, ctx.xmm[0].u32[0]);
	// 0x25D580: ret
	return;
}

void sub_25D590(X86Context& ctx, uint8_t* base) {
	// 0x25D590: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25D598: movss [0x004D5FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FDCu, ctx.xmm[0].u32[0]);
	// 0x25D5A0: ret
	return;
}

void sub_25D5B0(X86Context& ctx, uint8_t* base) {
	// 0x25D5B0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25D5B8: movss [0x004D5FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FE8u, ctx.xmm[0].u32[0]);
	// 0x25D5C0: ret
	return;
}

void sub_25D5D0(X86Context& ctx, uint8_t* base) {
	// 0x25D5D0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25D5D8: movss [0x004D5FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FD8u, ctx.xmm[0].u32[0]);
	// 0x25D5E0: ret
	return;
}

void sub_25D5F0(X86Context& ctx, uint8_t* base) {
	// 0x25D5F0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25D5F8: movss [0x004D5FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FC0u, ctx.xmm[0].u32[0]);
	// 0x25D600: ret
	return;
}

void sub_25D610(X86Context& ctx, uint8_t* base) {
	// 0x25D610: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25D618: movss [0x004D5FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FE0u, ctx.xmm[0].u32[0]);
	// 0x25D620: ret
	return;
}

void sub_25D630(X86Context& ctx, uint8_t* base) {
	// 0x25D630: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25D638: movss [0x004D5FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FC8u, ctx.xmm[0].u32[0]);
	// 0x25D640: ret
	return;
}

void sub_25D650(X86Context& ctx, uint8_t* base) {
	// 0x25D650: movss xmm0, dword ptr [0x004D5FE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FE0u);
	// 0x25D658: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25D660: movss [0x004D5FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FF0u, ctx.xmm[0].u32[0]);
	// 0x25D668: ret
	return;
}

void sub_25D670(X86Context& ctx, uint8_t* base) {
	// 0x25D670: movss xmm0, dword ptr [0x004D5FC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FC8u);
	// 0x25D678: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25D680: movss [0x004D5FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FECu, ctx.xmm[0].u32[0]);
	// 0x25D688: ret
	return;
}

void sub_25D690(X86Context& ctx, uint8_t* base) {
	// 0x25D690: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D698: movss [0x004D6000], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6000u, ctx.xmm[0].u32[0]);
	// 0x25D6A0: ret
	return;
}

void sub_25D6B0(X86Context& ctx, uint8_t* base) {
	// 0x25D6B0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25D6B8: movss [0x004D5FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FF4u, ctx.xmm[0].u32[0]);
	// 0x25D6C0: ret
	return;
}

void sub_25D6D0(X86Context& ctx, uint8_t* base) {
	// 0x25D6D0: movss xmm0, dword ptr [0x004D5FF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FF4u);
	// 0x25D6D8: movss [0x004D5FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FFCu, ctx.xmm[0].u32[0]);
	// 0x25D6E0: ret
	return;
}

void sub_25D6F0(X86Context& ctx, uint8_t* base) {
	// 0x25D6F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D6F8: movss [0x004D5FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FC4u, ctx.xmm[0].u32[0]);
	// 0x25D700: ret
	return;
}

void sub_25D710(X86Context& ctx, uint8_t* base) {
	// 0x25D710: movss xmm0, dword ptr [0x004D5FC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FC8u);
	// 0x25D718: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25D720: movss [0x004D5FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FF8u, ctx.xmm[0].u32[0]);
	// 0x25D728: ret
	return;
}

void sub_25D730(X86Context& ctx, uint8_t* base) {
	// 0x25D730: movss xmm0, dword ptr [0x004D5FC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FC8u);
	// 0x25D738: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25D740: movss [0x004D5FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FD4u, ctx.xmm[0].u32[0]);
	// 0x25D748: ret
	return;
}

void sub_25D750(X86Context& ctx, uint8_t* base) {
	// 0x25D750: movss xmm0, dword ptr [0x004D5FC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5FC8u);
	// 0x25D758: subss xmm0, [0x004D5FD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5FD4u);
	// 0x25D760: movss [0x004D5FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FD0u, ctx.xmm[0].u32[0]);
	// 0x25D768: ret
	return;
}

void sub_25D770(X86Context& ctx, uint8_t* base) {
	// 0x25D770: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25D778: movss [0x004D5FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FE4u, ctx.xmm[0].u32[0]);
	// 0x25D780: ret
	return;
}

void sub_25D790(X86Context& ctx, uint8_t* base) {
	// 0x25D790: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25D798: movss [0x004D5FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5FCCu, ctx.xmm[0].u32[0]);
	// 0x25D7A0: ret
	return;
}

void sub_25D7B0(X86Context& ctx, uint8_t* base) {
	// 0x25D7B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25D7B8: movss [0x004D6008], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6008u, ctx.xmm[0].u32[0]);
	// 0x25D7C0: ret
	return;
}

void sub_25D7D0(X86Context& ctx, uint8_t* base) {
	// 0x25D7D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25D7D8: movss [0x004D600C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D600Cu, ctx.xmm[0].u32[0]);
	// 0x25D7E0: ret
	return;
}

void sub_25D7F0(X86Context& ctx, uint8_t* base) {
	// 0x25D7F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25D7F8: movss [0x004D6004], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6004u, ctx.xmm[0].u32[0]);
	// 0x25D800: ret
	return;
}

void sub_25D810(X86Context& ctx, uint8_t* base) {
	// 0x25D810: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25D818: movss [0x004D606C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D606Cu, ctx.xmm[0].u32[0]);
	// 0x25D820: ret
	return;
}

void sub_25D830(X86Context& ctx, uint8_t* base) {
	// 0x25D830: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25D838: movss [0x004D6088], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6088u, ctx.xmm[0].u32[0]);
	// 0x25D840: ret
	return;
}

void sub_25D850(X86Context& ctx, uint8_t* base) {
	// 0x25D850: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25D858: movss [0x004D605C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D605Cu, ctx.xmm[0].u32[0]);
	// 0x25D860: ret
	return;
}

void sub_25D870(X86Context& ctx, uint8_t* base) {
	// 0x25D870: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25D878: movss [0x004D6010], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6010u, ctx.xmm[0].u32[0]);
	// 0x25D880: ret
	return;
}

void sub_25D890(X86Context& ctx, uint8_t* base) {
	// 0x25D890: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25D898: movss [0x004D6070], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6070u, ctx.xmm[0].u32[0]);
	// 0x25D8A0: ret
	return;
}

void sub_25D8B0(X86Context& ctx, uint8_t* base) {
	// 0x25D8B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25D8B8: movss [0x004D602C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D602Cu, ctx.xmm[0].u32[0]);
	// 0x25D8C0: ret
	return;
}

void sub_25D8D0(X86Context& ctx, uint8_t* base) {
	// 0x25D8D0: movss xmm0, dword ptr [0x004D6070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6070u);
	// 0x25D8D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25D8E0: movss [0x004D60A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60A8u, ctx.xmm[0].u32[0]);
	// 0x25D8E8: ret
	return;
}

void sub_25D8F0(X86Context& ctx, uint8_t* base) {
	// 0x25D8F0: movss xmm0, dword ptr [0x004D602C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D602Cu);
	// 0x25D8F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25D900: movss [0x004D6090], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6090u, ctx.xmm[0].u32[0]);
	// 0x25D908: ret
	return;
}

void sub_25D910(X86Context& ctx, uint8_t* base) {
	// 0x25D910: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D918: movss [0x004D60C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60C0u, ctx.xmm[0].u32[0]);
	// 0x25D920: ret
	return;
}

void sub_25D930(X86Context& ctx, uint8_t* base) {
	// 0x25D930: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25D938: movss [0x004D60AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60ACu, ctx.xmm[0].u32[0]);
	// 0x25D940: ret
	return;
}

void sub_25D950(X86Context& ctx, uint8_t* base) {
	// 0x25D950: movss xmm0, dword ptr [0x004D60AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60ACu);
	// 0x25D958: movss [0x004D60BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60BCu, ctx.xmm[0].u32[0]);
	// 0x25D960: ret
	return;
}

void sub_25D970(X86Context& ctx, uint8_t* base) {
	// 0x25D970: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25D978: movss [0x004D6018], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6018u, ctx.xmm[0].u32[0]);
	// 0x25D980: ret
	return;
}

void sub_25D990(X86Context& ctx, uint8_t* base) {
	// 0x25D990: movss xmm0, dword ptr [0x004D602C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D602Cu);
	// 0x25D998: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25D9A0: movss [0x004D60B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60B4u, ctx.xmm[0].u32[0]);
	// 0x25D9A8: ret
	return;
}

void sub_25D9B0(X86Context& ctx, uint8_t* base) {
	// 0x25D9B0: movss xmm0, dword ptr [0x004D602C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D602Cu);
	// 0x25D9B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25D9C0: movss [0x004D6058], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6058u, ctx.xmm[0].u32[0]);
	// 0x25D9C8: ret
	return;
}

void sub_25D9D0(X86Context& ctx, uint8_t* base) {
	// 0x25D9D0: movss xmm0, dword ptr [0x004D602C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D602Cu);
	// 0x25D9D8: subss xmm0, [0x004D6058]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D6058u);
	// 0x25D9E0: movss [0x004D6034], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6034u, ctx.xmm[0].u32[0]);
	// 0x25D9E8: ret
	return;
}

void sub_25D9F0(X86Context& ctx, uint8_t* base) {
	// 0x25D9F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25D9F8: movss [0x004D6084], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6084u, ctx.xmm[0].u32[0]);
	// 0x25DA00: ret
	return;
}

void sub_25DA10(X86Context& ctx, uint8_t* base) {
	// 0x25DA10: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25DA18: movss [0x004D6030], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6030u, ctx.xmm[0].u32[0]);
	// 0x25DA20: ret
	return;
}

void sub_25DA30(X86Context& ctx, uint8_t* base) {
	// 0x25DA30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25DA38: movss [0x004D6044], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6044u, ctx.xmm[0].u32[0]);
	// 0x25DA40: ret
	return;
}

void sub_25DA50(X86Context& ctx, uint8_t* base) {
	// 0x25DA50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25DA58: movss [0x004D609C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D609Cu, ctx.xmm[0].u32[0]);
	// 0x25DA60: ret
	return;
}

void sub_25DA70(X86Context& ctx, uint8_t* base) {
	// 0x25DA70: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x25DA78: movss [0x004D6080], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6080u, ctx.xmm[0].u32[0]);
	// 0x25DA80: ret
	return;
}

void sub_25DA90(X86Context& ctx, uint8_t* base) {
	// 0x25DA90: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x25DA98: movss [0x004D6028], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6028u, ctx.xmm[0].u32[0]);
	// 0x25DAA0: ret
	return;
}

void sub_25DAB0(X86Context& ctx, uint8_t* base) {
	// 0x25DAB0: movss xmm0, dword ptr [0x004D6044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6044u);
	// 0x25DAB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25DAC0: movss [0x004D601C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D601Cu, ctx.xmm[0].u32[0]);
	// 0x25DAC8: ret
	return;
}

void sub_25DAD0(X86Context& ctx, uint8_t* base) {
	// 0x25DAD0: movss xmm0, dword ptr [0x004D609C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D609Cu);
	// 0x25DAD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25DAE0: movss [0x004D6064], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6064u, ctx.xmm[0].u32[0]);
	// 0x25DAE8: ret
	return;
}

void sub_25DAF0(X86Context& ctx, uint8_t* base) {
	// 0x25DAF0: movss xmm0, dword ptr [0x004D601C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D601Cu);
	// 0x25DAF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25DB00: movss [0x004D6078], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6078u, ctx.xmm[0].u32[0]);
	// 0x25DB08: ret
	return;
}

void sub_25DB10(X86Context& ctx, uint8_t* base) {
	// 0x25DB10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25DB18: movss [0x004D6014], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6014u, ctx.xmm[0].u32[0]);
	// 0x25DB20: ret
	return;
}

void sub_25DB30(X86Context& ctx, uint8_t* base) {
	// 0x25DB30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25DB38: movss [0x004D6048], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6048u, ctx.xmm[0].u32[0]);
	// 0x25DB40: ret
	return;
}

void sub_25DB50(X86Context& ctx, uint8_t* base) {
	// 0x25DB50: movss xmm0, dword ptr [0x004D6044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6044u);
	// 0x25DB58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25DB60: movss [0x004D6054], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6054u, ctx.xmm[0].u32[0]);
	// 0x25DB68: ret
	return;
}

void sub_25DB70(X86Context& ctx, uint8_t* base) {
	// 0x25DB70: movss xmm0, dword ptr [0x004D609C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D609Cu);
	// 0x25DB78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25DB80: movss [0x004D60A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60A0u, ctx.xmm[0].u32[0]);
	// 0x25DB88: ret
	return;
}

void sub_25DB90(X86Context& ctx, uint8_t* base) {
	// 0x25DB90: movss xmm0, dword ptr [0x004D6054]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6054u);
	// 0x25DB98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25DBA0: movss [0x004D608C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D608Cu, ctx.xmm[0].u32[0]);
	// 0x25DBA8: ret
	return;
}

void sub_25DBB0(X86Context& ctx, uint8_t* base) {
	// 0x25DBB0: movss xmm0, dword ptr [0x004D60A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60A0u);
	// 0x25DBB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25DBC0: movss [0x004D60B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60B0u, ctx.xmm[0].u32[0]);
	// 0x25DBC8: ret
	return;
}

void sub_25DBD0(X86Context& ctx, uint8_t* base) {
	// 0x25DBD0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x25DBD8: movss [0x004D6020], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6020u, ctx.xmm[0].u32[0]);
	// 0x25DBE0: ret
	return;
}

void sub_25DBF0(X86Context& ctx, uint8_t* base) {
	// 0x25DBF0: movss xmm0, dword ptr [0x004D6044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6044u);
	// 0x25DBF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25DC00: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x25DC08: movss [0x004D6098], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6098u, ctx.xmm[0].u32[0]);
	// 0x25DC10: ret
	return;
}

void sub_25DC20(X86Context& ctx, uint8_t* base) {
	// 0x25DC20: movss xmm0, dword ptr [0x004D609C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D609Cu);
	// 0x25DC28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25DC30: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x25DC38: movss [0x004D6038], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6038u, ctx.xmm[0].u32[0]);
	// 0x25DC40: ret
	return;
}

void sub_25DC50(X86Context& ctx, uint8_t* base) {
	// 0x25DC50: movss xmm0, dword ptr [0x004D6044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6044u);
	// 0x25DC58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25DC60: movss [0x004D603C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D603Cu, ctx.xmm[0].u32[0]);
	// 0x25DC68: ret
	return;
}

void sub_25DC70(X86Context& ctx, uint8_t* base) {
	// 0x25DC70: movss xmm0, dword ptr [0x004D609C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D609Cu);
	// 0x25DC78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25DC80: movss [0x004D60A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60A4u, ctx.xmm[0].u32[0]);
	// 0x25DC88: ret
	return;
}

void sub_25DC90(X86Context& ctx, uint8_t* base) {
	// 0x25DC90: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x25DC98: movss [0x004D6024], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6024u, ctx.xmm[0].u32[0]);
	// 0x25DCA0: ret
	return;
}

