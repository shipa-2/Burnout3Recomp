#include "x86_recomp_shared.h"

void sub_2A8800(X86Context& ctx, uint8_t* base) {
	// 0x2A8800: movss xmm0, dword ptr [0x005709A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709A0u);
	// 0x2A8808: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A8810: movss [0x005709C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5709C8u, ctx.xmm[0].u32[0]);
	// 0x2A8818: ret
	return;
}

void sub_2A8820(X86Context& ctx, uint8_t* base) {
	// 0x2A8820: movss xmm0, dword ptr [0x005709A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709A0u);
	// 0x2A8828: subss xmm0, [0x005709C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5709C8u);
	// 0x2A8830: movss [0x005709A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5709A8u, ctx.xmm[0].u32[0]);
	// 0x2A8838: ret
	return;
}

void sub_2A8840(X86Context& ctx, uint8_t* base) {
	// 0x2A8840: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A8848: movss [0x005709F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5709F4u, ctx.xmm[0].u32[0]);
	// 0x2A8850: ret
	return;
}

void sub_2A8860(X86Context& ctx, uint8_t* base) {
	// 0x2A8860: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A8868: movss [0x005709A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5709A4u, ctx.xmm[0].u32[0]);
	// 0x2A8870: ret
	return;
}

void sub_2A8880(X86Context& ctx, uint8_t* base) {
	// 0x2A8880: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A8888: movss [0x005709B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5709B4u, ctx.xmm[0].u32[0]);
	// 0x2A8890: ret
	return;
}

void sub_2A88A0(X86Context& ctx, uint8_t* base) {
	// 0x2A88A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A88A8: movss [0x00570A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A0Cu, ctx.xmm[0].u32[0]);
	// 0x2A88B0: ret
	return;
}

void sub_2A88C0(X86Context& ctx, uint8_t* base) {
	// 0x2A88C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A88C8: movss [0x005709F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5709F0u, ctx.xmm[0].u32[0]);
	// 0x2A88D0: ret
	return;
}

void sub_2A88E0(X86Context& ctx, uint8_t* base) {
	// 0x2A88E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A88E8: movss [0x0057099C], xmm0
	X86_MEM_WRITE_u32(base, 0x57099Cu, ctx.xmm[0].u32[0]);
	// 0x2A88F0: ret
	return;
}

void sub_2A8900(X86Context& ctx, uint8_t* base) {
	// 0x2A8900: movss xmm0, dword ptr [0x005709B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709B4u);
	// 0x2A8908: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8910: movss [0x00570990], xmm0
	X86_MEM_WRITE_u32(base, 0x570990u, ctx.xmm[0].u32[0]);
	// 0x2A8918: ret
	return;
}

void sub_2A8920(X86Context& ctx, uint8_t* base) {
	// 0x2A8920: movss xmm0, dword ptr [0x00570A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A0Cu);
	// 0x2A8928: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A8930: movss [0x005709D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5709D8u, ctx.xmm[0].u32[0]);
	// 0x2A8938: ret
	return;
}

void sub_2A8940(X86Context& ctx, uint8_t* base) {
	// 0x2A8940: movss xmm0, dword ptr [0x00570990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570990u);
	// 0x2A8948: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8950: movss [0x005709E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5709E8u, ctx.xmm[0].u32[0]);
	// 0x2A8958: ret
	return;
}

void sub_2A8960(X86Context& ctx, uint8_t* base) {
	// 0x2A8960: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A8968: movss [0x00570988], xmm0
	X86_MEM_WRITE_u32(base, 0x570988u, ctx.xmm[0].u32[0]);
	// 0x2A8970: ret
	return;
}

void sub_2A8980(X86Context& ctx, uint8_t* base) {
	// 0x2A8980: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A8988: movss [0x005709B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5709B8u, ctx.xmm[0].u32[0]);
	// 0x2A8990: ret
	return;
}

void sub_2A89A0(X86Context& ctx, uint8_t* base) {
	// 0x2A89A0: movss xmm0, dword ptr [0x005709B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709B4u);
	// 0x2A89A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A89B0: movss [0x005709C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5709C4u, ctx.xmm[0].u32[0]);
	// 0x2A89B8: ret
	return;
}

void sub_2A89C0(X86Context& ctx, uint8_t* base) {
	// 0x2A89C0: movss xmm0, dword ptr [0x00570A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A0Cu);
	// 0x2A89C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A89D0: movss [0x00570A10], xmm0
	X86_MEM_WRITE_u32(base, 0x570A10u, ctx.xmm[0].u32[0]);
	// 0x2A89D8: ret
	return;
}

void sub_2A89E0(X86Context& ctx, uint8_t* base) {
	// 0x2A89E0: movss xmm0, dword ptr [0x005709C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709C4u);
	// 0x2A89E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A89F0: movss [0x005709FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5709FCu, ctx.xmm[0].u32[0]);
	// 0x2A89F8: ret
	return;
}

void sub_2A8A00(X86Context& ctx, uint8_t* base) {
	// 0x2A8A00: movss xmm0, dword ptr [0x00570A10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A10u);
	// 0x2A8A08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8A10: movss [0x00570A20], xmm0
	X86_MEM_WRITE_u32(base, 0x570A20u, ctx.xmm[0].u32[0]);
	// 0x2A8A18: ret
	return;
}

void sub_2A8A20(X86Context& ctx, uint8_t* base) {
	// 0x2A8A20: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A8A28: movss [0x00570994], xmm0
	X86_MEM_WRITE_u32(base, 0x570994u, ctx.xmm[0].u32[0]);
	// 0x2A8A30: ret
	return;
}

void sub_2A8A40(X86Context& ctx, uint8_t* base) {
	// 0x2A8A40: movss xmm0, dword ptr [0x005709B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709B4u);
	// 0x2A8A48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8A50: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A8A58: movss [0x00570A08], xmm0
	X86_MEM_WRITE_u32(base, 0x570A08u, ctx.xmm[0].u32[0]);
	// 0x2A8A60: ret
	return;
}

void sub_2A8A70(X86Context& ctx, uint8_t* base) {
	// 0x2A8A70: movss xmm0, dword ptr [0x00570A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A0Cu);
	// 0x2A8A78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8A80: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A8A88: movss [0x005709AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5709ACu, ctx.xmm[0].u32[0]);
	// 0x2A8A90: ret
	return;
}

void sub_2A8AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A8AA0: movss xmm0, dword ptr [0x005709B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709B4u);
	// 0x2A8AA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8AB0: movss [0x005709B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5709B0u, ctx.xmm[0].u32[0]);
	// 0x2A8AB8: ret
	return;
}

void sub_2A8AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A8AC0: movss xmm0, dword ptr [0x00570A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A0Cu);
	// 0x2A8AC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8AD0: movss [0x00570A14], xmm0
	X86_MEM_WRITE_u32(base, 0x570A14u, ctx.xmm[0].u32[0]);
	// 0x2A8AD8: ret
	return;
}

void sub_2A8AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A8AE0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A8AE8: movss [0x00570998], xmm0
	X86_MEM_WRITE_u32(base, 0x570998u, ctx.xmm[0].u32[0]);
	// 0x2A8AF0: ret
	return;
}

void sub_2A8B00(X86Context& ctx, uint8_t* base) {
	// 0x2A8B00: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A8B08: movss [0x005709C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5709C0u, ctx.xmm[0].u32[0]);
	// 0x2A8B10: ret
	return;
}

void sub_2A8B20(X86Context& ctx, uint8_t* base) {
	// 0x2A8B20: movss xmm0, dword ptr [0x00570998]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570998u);
	// 0x2A8B28: movss [0x00570A28], xmm0
	X86_MEM_WRITE_u32(base, 0x570A28u, ctx.xmm[0].u32[0]);
	// 0x2A8B30: ret
	return;
}

void sub_2A8B40(X86Context& ctx, uint8_t* base) {
	// 0x2A8B40: movss xmm0, dword ptr [0x00570A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A0Cu);
	// 0x2A8B48: subss xmm0, [0x00570998]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570998u);
	// 0x2A8B50: movss [0x005709EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5709ECu, ctx.xmm[0].u32[0]);
	// 0x2A8B58: ret
	return;
}

void sub_2A8B60(X86Context& ctx, uint8_t* base) {
	// 0x2A8B60: movss xmm0, dword ptr [0x005709EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709ECu);
	// 0x2A8B68: subss xmm0, [0x005709C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5709C0u);
	// 0x2A8B70: movss [0x005709E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5709E4u, ctx.xmm[0].u32[0]);
	// 0x2A8B78: ret
	return;
}

void sub_2A8B80(X86Context& ctx, uint8_t* base) {
	// 0x2A8B80: movss xmm0, dword ptr [0x00570A14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A14u);
	// 0x2A8B88: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A8B90: movss [0x005709D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5709D0u, ctx.xmm[0].u32[0]);
	// 0x2A8B98: ret
	return;
}

void sub_2A8BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A8BA0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A8BA8: movss [0x005709BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5709BCu, ctx.xmm[0].u32[0]);
	// 0x2A8BB0: ret
	return;
}

void sub_2A8BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A8BC0: movss xmm0, dword ptr [0x005709D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709D0u);
	// 0x2A8BC8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A8BD0: movss [0x00570A04], xmm0
	X86_MEM_WRITE_u32(base, 0x570A04u, ctx.xmm[0].u32[0]);
	// 0x2A8BD8: ret
	return;
}

void sub_2A8BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A8BE0: movss xmm0, dword ptr [0x005709B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709B4u);
	// 0x2A8BE8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A8BF0: movss [0x005709D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5709D4u, ctx.xmm[0].u32[0]);
	// 0x2A8BF8: ret
	return;
}

void sub_2A8C00(X86Context& ctx, uint8_t* base) {
	// 0x2A8C00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A8C08: movss [0x00570A88], xmm0
	X86_MEM_WRITE_u32(base, 0x570A88u, ctx.xmm[0].u32[0]);
	// 0x2A8C10: ret
	return;
}

void sub_2A8C20(X86Context& ctx, uint8_t* base) {
	// 0x2A8C20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A8C28: movss [0x00570AA4], xmm0
	X86_MEM_WRITE_u32(base, 0x570AA4u, ctx.xmm[0].u32[0]);
	// 0x2A8C30: ret
	return;
}

void sub_2A8C40(X86Context& ctx, uint8_t* base) {
	// 0x2A8C40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A8C48: movss [0x00570A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A7Cu, ctx.xmm[0].u32[0]);
	// 0x2A8C50: ret
	return;
}

void sub_2A8C60(X86Context& ctx, uint8_t* base) {
	// 0x2A8C60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A8C68: movss [0x00570A34], xmm0
	X86_MEM_WRITE_u32(base, 0x570A34u, ctx.xmm[0].u32[0]);
	// 0x2A8C70: ret
	return;
}

void sub_2A8C80(X86Context& ctx, uint8_t* base) {
	// 0x2A8C80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A8C88: movss [0x00570A8C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A8Cu, ctx.xmm[0].u32[0]);
	// 0x2A8C90: ret
	return;
}

void sub_2A8CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A8CA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A8CA8: movss [0x00570A50], xmm0
	X86_MEM_WRITE_u32(base, 0x570A50u, ctx.xmm[0].u32[0]);
	// 0x2A8CB0: ret
	return;
}

void sub_2A8CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A8CC0: movss xmm0, dword ptr [0x00570A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A8Cu);
	// 0x2A8CC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8CD0: movss [0x00570AC4], xmm0
	X86_MEM_WRITE_u32(base, 0x570AC4u, ctx.xmm[0].u32[0]);
	// 0x2A8CD8: ret
	return;
}

void sub_2A8CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A8CE0: movss xmm0, dword ptr [0x00570A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A50u);
	// 0x2A8CE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A8CF0: movss [0x00570AAC], xmm0
	X86_MEM_WRITE_u32(base, 0x570AACu, ctx.xmm[0].u32[0]);
	// 0x2A8CF8: ret
	return;
}

void sub_2A8D00(X86Context& ctx, uint8_t* base) {
	// 0x2A8D00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A8D08: movss [0x00570ADC], xmm0
	X86_MEM_WRITE_u32(base, 0x570ADCu, ctx.xmm[0].u32[0]);
	// 0x2A8D10: ret
	return;
}

void sub_2A8D20(X86Context& ctx, uint8_t* base) {
	// 0x2A8D20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A8D28: movss [0x00570AC8], xmm0
	X86_MEM_WRITE_u32(base, 0x570AC8u, ctx.xmm[0].u32[0]);
	// 0x2A8D30: ret
	return;
}

void sub_2A8D40(X86Context& ctx, uint8_t* base) {
	// 0x2A8D40: movss xmm0, dword ptr [0x00570AC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AC8u);
	// 0x2A8D48: movss [0x00570AD8], xmm0
	X86_MEM_WRITE_u32(base, 0x570AD8u, ctx.xmm[0].u32[0]);
	// 0x2A8D50: ret
	return;
}

void sub_2A8D60(X86Context& ctx, uint8_t* base) {
	// 0x2A8D60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A8D68: movss [0x00570A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A3Cu, ctx.xmm[0].u32[0]);
	// 0x2A8D70: ret
	return;
}

void sub_2A8D80(X86Context& ctx, uint8_t* base) {
	// 0x2A8D80: movss xmm0, dword ptr [0x00570A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A50u);
	// 0x2A8D88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A8D90: movss [0x00570AD0], xmm0
	X86_MEM_WRITE_u32(base, 0x570AD0u, ctx.xmm[0].u32[0]);
	// 0x2A8D98: ret
	return;
}

void sub_2A8DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A8DA0: movss xmm0, dword ptr [0x00570A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A50u);
	// 0x2A8DA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A8DB0: movss [0x00570A78], xmm0
	X86_MEM_WRITE_u32(base, 0x570A78u, ctx.xmm[0].u32[0]);
	// 0x2A8DB8: ret
	return;
}

void sub_2A8DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A8DC0: movss xmm0, dword ptr [0x00570A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A50u);
	// 0x2A8DC8: subss xmm0, [0x00570A78]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570A78u);
	// 0x2A8DD0: movss [0x00570A58], xmm0
	X86_MEM_WRITE_u32(base, 0x570A58u, ctx.xmm[0].u32[0]);
	// 0x2A8DD8: ret
	return;
}

void sub_2A8DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A8DE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A8DE8: movss [0x00570AA0], xmm0
	X86_MEM_WRITE_u32(base, 0x570AA0u, ctx.xmm[0].u32[0]);
	// 0x2A8DF0: ret
	return;
}

void sub_2A8E00(X86Context& ctx, uint8_t* base) {
	// 0x2A8E00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A8E08: movss [0x00570A54], xmm0
	X86_MEM_WRITE_u32(base, 0x570A54u, ctx.xmm[0].u32[0]);
	// 0x2A8E10: ret
	return;
}

void sub_2A8E20(X86Context& ctx, uint8_t* base) {
	// 0x2A8E20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A8E28: movss [0x00570A64], xmm0
	X86_MEM_WRITE_u32(base, 0x570A64u, ctx.xmm[0].u32[0]);
	// 0x2A8E30: ret
	return;
}

void sub_2A8E40(X86Context& ctx, uint8_t* base) {
	// 0x2A8E40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A8E48: movss [0x00570AB8], xmm0
	X86_MEM_WRITE_u32(base, 0x570AB8u, ctx.xmm[0].u32[0]);
	// 0x2A8E50: ret
	return;
}

void sub_2A8E60(X86Context& ctx, uint8_t* base) {
	// 0x2A8E60: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A8E68: movss [0x00570A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A9Cu, ctx.xmm[0].u32[0]);
	// 0x2A8E70: ret
	return;
}

void sub_2A8E80(X86Context& ctx, uint8_t* base) {
	// 0x2A8E80: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A8E88: movss [0x00570A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A4Cu, ctx.xmm[0].u32[0]);
	// 0x2A8E90: ret
	return;
}

void sub_2A8EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A8EA0: movss xmm0, dword ptr [0x00570A64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A64u);
	// 0x2A8EA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8EB0: movss [0x00570A40], xmm0
	X86_MEM_WRITE_u32(base, 0x570A40u, ctx.xmm[0].u32[0]);
	// 0x2A8EB8: ret
	return;
}

void sub_2A8EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A8EC0: movss xmm0, dword ptr [0x00570AB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AB8u);
	// 0x2A8EC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A8ED0: movss [0x00570A84], xmm0
	X86_MEM_WRITE_u32(base, 0x570A84u, ctx.xmm[0].u32[0]);
	// 0x2A8ED8: ret
	return;
}

void sub_2A8EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A8EE0: movss xmm0, dword ptr [0x00570A40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A40u);
	// 0x2A8EE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8EF0: movss [0x00570A94], xmm0
	X86_MEM_WRITE_u32(base, 0x570A94u, ctx.xmm[0].u32[0]);
	// 0x2A8EF8: ret
	return;
}

void sub_2A8F00(X86Context& ctx, uint8_t* base) {
	// 0x2A8F00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A8F08: movss [0x00570A38], xmm0
	X86_MEM_WRITE_u32(base, 0x570A38u, ctx.xmm[0].u32[0]);
	// 0x2A8F10: ret
	return;
}

void sub_2A8F20(X86Context& ctx, uint8_t* base) {
	// 0x2A8F20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A8F28: movss [0x00570A68], xmm0
	X86_MEM_WRITE_u32(base, 0x570A68u, ctx.xmm[0].u32[0]);
	// 0x2A8F30: ret
	return;
}

void sub_2A8F40(X86Context& ctx, uint8_t* base) {
	// 0x2A8F40: movss xmm0, dword ptr [0x00570A64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A64u);
	// 0x2A8F48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A8F50: movss [0x00570A74], xmm0
	X86_MEM_WRITE_u32(base, 0x570A74u, ctx.xmm[0].u32[0]);
	// 0x2A8F58: ret
	return;
}

void sub_2A8F60(X86Context& ctx, uint8_t* base) {
	// 0x2A8F60: movss xmm0, dword ptr [0x00570AB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AB8u);
	// 0x2A8F68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A8F70: movss [0x00570ABC], xmm0
	X86_MEM_WRITE_u32(base, 0x570ABCu, ctx.xmm[0].u32[0]);
	// 0x2A8F78: ret
	return;
}

void sub_2A8F80(X86Context& ctx, uint8_t* base) {
	// 0x2A8F80: movss xmm0, dword ptr [0x00570A74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A74u);
	// 0x2A8F88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8F90: movss [0x00570AA8], xmm0
	X86_MEM_WRITE_u32(base, 0x570AA8u, ctx.xmm[0].u32[0]);
	// 0x2A8F98: ret
	return;
}

void sub_2A8FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A8FA0: movss xmm0, dword ptr [0x00570ABC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570ABCu);
	// 0x2A8FA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8FB0: movss [0x00570ACC], xmm0
	X86_MEM_WRITE_u32(base, 0x570ACCu, ctx.xmm[0].u32[0]);
	// 0x2A8FB8: ret
	return;
}

void sub_2A8FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A8FC0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A8FC8: movss [0x00570A44], xmm0
	X86_MEM_WRITE_u32(base, 0x570A44u, ctx.xmm[0].u32[0]);
	// 0x2A8FD0: ret
	return;
}

void sub_2A8FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A8FE0: movss xmm0, dword ptr [0x00570A64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A64u);
	// 0x2A8FE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8FF0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A8FF8: movss [0x00570AB4], xmm0
	X86_MEM_WRITE_u32(base, 0x570AB4u, ctx.xmm[0].u32[0]);
	// 0x2A9000: ret
	return;
}

void sub_2A9010(X86Context& ctx, uint8_t* base) {
	// 0x2A9010: movss xmm0, dword ptr [0x00570AB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AB8u);
	// 0x2A9018: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9020: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A9028: movss [0x00570A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A5Cu, ctx.xmm[0].u32[0]);
	// 0x2A9030: ret
	return;
}

void sub_2A9040(X86Context& ctx, uint8_t* base) {
	// 0x2A9040: movss xmm0, dword ptr [0x00570A64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A64u);
	// 0x2A9048: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9050: movss [0x00570A60], xmm0
	X86_MEM_WRITE_u32(base, 0x570A60u, ctx.xmm[0].u32[0]);
	// 0x2A9058: ret
	return;
}

void sub_2A9060(X86Context& ctx, uint8_t* base) {
	// 0x2A9060: movss xmm0, dword ptr [0x00570AB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AB8u);
	// 0x2A9068: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9070: movss [0x00570AC0], xmm0
	X86_MEM_WRITE_u32(base, 0x570AC0u, ctx.xmm[0].u32[0]);
	// 0x2A9078: ret
	return;
}

void sub_2A9080(X86Context& ctx, uint8_t* base) {
	// 0x2A9080: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A9088: movss [0x00570A48], xmm0
	X86_MEM_WRITE_u32(base, 0x570A48u, ctx.xmm[0].u32[0]);
	// 0x2A9090: ret
	return;
}

void sub_2A90A0(X86Context& ctx, uint8_t* base) {
	// 0x2A90A0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A90A8: movss [0x00570A70], xmm0
	X86_MEM_WRITE_u32(base, 0x570A70u, ctx.xmm[0].u32[0]);
	// 0x2A90B0: ret
	return;
}

void sub_2A90C0(X86Context& ctx, uint8_t* base) {
	// 0x2A90C0: movss xmm0, dword ptr [0x00570A48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A48u);
	// 0x2A90C8: movss [0x00570AD4], xmm0
	X86_MEM_WRITE_u32(base, 0x570AD4u, ctx.xmm[0].u32[0]);
	// 0x2A90D0: ret
	return;
}

void sub_2A90E0(X86Context& ctx, uint8_t* base) {
	// 0x2A90E0: movss xmm0, dword ptr [0x00570AB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AB8u);
	// 0x2A90E8: subss xmm0, [0x00570A48]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570A48u);
	// 0x2A90F0: movss [0x00570A98], xmm0
	X86_MEM_WRITE_u32(base, 0x570A98u, ctx.xmm[0].u32[0]);
	// 0x2A90F8: ret
	return;
}

void sub_2A9100(X86Context& ctx, uint8_t* base) {
	// 0x2A9100: movss xmm0, dword ptr [0x00570A98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A98u);
	// 0x2A9108: subss xmm0, [0x00570A70]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570A70u);
	// 0x2A9110: movss [0x00570A90], xmm0
	X86_MEM_WRITE_u32(base, 0x570A90u, ctx.xmm[0].u32[0]);
	// 0x2A9118: ret
	return;
}

void sub_2A9120(X86Context& ctx, uint8_t* base) {
	// 0x2A9120: movss xmm0, dword ptr [0x00570AC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AC0u);
	// 0x2A9128: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A9130: movss [0x00570A80], xmm0
	X86_MEM_WRITE_u32(base, 0x570A80u, ctx.xmm[0].u32[0]);
	// 0x2A9138: ret
	return;
}

void sub_2A9140(X86Context& ctx, uint8_t* base) {
	// 0x2A9140: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A9148: movss [0x00570A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A6Cu, ctx.xmm[0].u32[0]);
	// 0x2A9150: ret
	return;
}

void sub_2A9160(X86Context& ctx, uint8_t* base) {
	// 0x2A9160: movss xmm0, dword ptr [0x00570A80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A80u);
	// 0x2A9168: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A9170: movss [0x00570AB0], xmm0
	X86_MEM_WRITE_u32(base, 0x570AB0u, ctx.xmm[0].u32[0]);
	// 0x2A9178: ret
	return;
}

void sub_2A9180(X86Context& ctx, uint8_t* base) {
	// 0x2A9180: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A9188: movss [0x00570B4C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B4Cu, ctx.xmm[0].u32[0]);
	// 0x2A9190: ret
	return;
}

void sub_2A91A0(X86Context& ctx, uint8_t* base) {
	// 0x2A91A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A91A8: movss [0x00570B68], xmm0
	X86_MEM_WRITE_u32(base, 0x570B68u, ctx.xmm[0].u32[0]);
	// 0x2A91B0: ret
	return;
}

void sub_2A91C0(X86Context& ctx, uint8_t* base) {
	// 0x2A91C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A91C8: movss [0x00570B38], xmm0
	X86_MEM_WRITE_u32(base, 0x570B38u, ctx.xmm[0].u32[0]);
	// 0x2A91D0: ret
	return;
}

void sub_2A91E0(X86Context& ctx, uint8_t* base) {
	// 0x2A91E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A91E8: movss [0x00570AE0], xmm0
	X86_MEM_WRITE_u32(base, 0x570AE0u, ctx.xmm[0].u32[0]);
	// 0x2A91F0: ret
	return;
}

void sub_2A9200(X86Context& ctx, uint8_t* base) {
	// 0x2A9200: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A9208: movss [0x00570B50], xmm0
	X86_MEM_WRITE_u32(base, 0x570B50u, ctx.xmm[0].u32[0]);
	// 0x2A9210: ret
	return;
}

void sub_2A9220(X86Context& ctx, uint8_t* base) {
	// 0x2A9220: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A9228: movss [0x00570B00], xmm0
	X86_MEM_WRITE_u32(base, 0x570B00u, ctx.xmm[0].u32[0]);
	// 0x2A9230: ret
	return;
}

void sub_2A9240(X86Context& ctx, uint8_t* base) {
	// 0x2A9240: movss xmm0, dword ptr [0x00570B50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B50u);
	// 0x2A9248: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A9250: movss [0x00570B88], xmm0
	X86_MEM_WRITE_u32(base, 0x570B88u, ctx.xmm[0].u32[0]);
	// 0x2A9258: ret
	return;
}

void sub_2A9260(X86Context& ctx, uint8_t* base) {
	// 0x2A9260: movss xmm0, dword ptr [0x00570B00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B00u);
	// 0x2A9268: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A9270: movss [0x00570B70], xmm0
	X86_MEM_WRITE_u32(base, 0x570B70u, ctx.xmm[0].u32[0]);
	// 0x2A9278: ret
	return;
}

void sub_2A9280(X86Context& ctx, uint8_t* base) {
	// 0x2A9280: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A9288: movss [0x00570BA0], xmm0
	X86_MEM_WRITE_u32(base, 0x570BA0u, ctx.xmm[0].u32[0]);
	// 0x2A9290: ret
	return;
}

void sub_2A92A0(X86Context& ctx, uint8_t* base) {
	// 0x2A92A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A92A8: movss [0x00570B8C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B8Cu, ctx.xmm[0].u32[0]);
	// 0x2A92B0: ret
	return;
}

void sub_2A92C0(X86Context& ctx, uint8_t* base) {
	// 0x2A92C0: movss xmm0, dword ptr [0x00570B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B8Cu);
	// 0x2A92C8: movss [0x00570B9C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B9Cu, ctx.xmm[0].u32[0]);
	// 0x2A92D0: ret
	return;
}

void sub_2A92E0(X86Context& ctx, uint8_t* base) {
	// 0x2A92E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A92E8: movss [0x00570AEC], xmm0
	X86_MEM_WRITE_u32(base, 0x570AECu, ctx.xmm[0].u32[0]);
	// 0x2A92F0: ret
	return;
}

void sub_2A9300(X86Context& ctx, uint8_t* base) {
	// 0x2A9300: movss xmm0, dword ptr [0x00570B00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B00u);
	// 0x2A9308: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A9310: movss [0x00570B94], xmm0
	X86_MEM_WRITE_u32(base, 0x570B94u, ctx.xmm[0].u32[0]);
	// 0x2A9318: ret
	return;
}

void sub_2A9320(X86Context& ctx, uint8_t* base) {
	// 0x2A9320: movss xmm0, dword ptr [0x00570B00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B00u);
	// 0x2A9328: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A9330: movss [0x00570B34], xmm0
	X86_MEM_WRITE_u32(base, 0x570B34u, ctx.xmm[0].u32[0]);
	// 0x2A9338: ret
	return;
}

void sub_2A9340(X86Context& ctx, uint8_t* base) {
	// 0x2A9340: movss xmm0, dword ptr [0x00570B00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B00u);
	// 0x2A9348: subss xmm0, [0x00570B34]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570B34u);
	// 0x2A9350: movss [0x00570B08], xmm0
	X86_MEM_WRITE_u32(base, 0x570B08u, ctx.xmm[0].u32[0]);
	// 0x2A9358: ret
	return;
}

void sub_2A9360(X86Context& ctx, uint8_t* base) {
	// 0x2A9360: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A9368: movss [0x00570B64], xmm0
	X86_MEM_WRITE_u32(base, 0x570B64u, ctx.xmm[0].u32[0]);
	// 0x2A9370: ret
	return;
}

void sub_2A9380(X86Context& ctx, uint8_t* base) {
	// 0x2A9380: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A9388: movss [0x00570B04], xmm0
	X86_MEM_WRITE_u32(base, 0x570B04u, ctx.xmm[0].u32[0]);
	// 0x2A9390: ret
	return;
}

void sub_2A93A0(X86Context& ctx, uint8_t* base) {
	// 0x2A93A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A93A8: movss [0x00570B20], xmm0
	X86_MEM_WRITE_u32(base, 0x570B20u, ctx.xmm[0].u32[0]);
	// 0x2A93B0: ret
	return;
}

void sub_2A93C0(X86Context& ctx, uint8_t* base) {
	// 0x2A93C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A93C8: movss [0x00570B7C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B7Cu, ctx.xmm[0].u32[0]);
	// 0x2A93D0: ret
	return;
}

void sub_2A93E0(X86Context& ctx, uint8_t* base) {
	// 0x2A93E0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A93E8: movss [0x00570B60], xmm0
	X86_MEM_WRITE_u32(base, 0x570B60u, ctx.xmm[0].u32[0]);
	// 0x2A93F0: ret
	return;
}

void sub_2A9400(X86Context& ctx, uint8_t* base) {
	// 0x2A9400: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A9408: movss [0x00570AFC], xmm0
	X86_MEM_WRITE_u32(base, 0x570AFCu, ctx.xmm[0].u32[0]);
	// 0x2A9410: ret
	return;
}

void sub_2A9420(X86Context& ctx, uint8_t* base) {
	// 0x2A9420: movss xmm0, dword ptr [0x00570B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B20u);
	// 0x2A9428: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A9430: movss [0x00570AF0], xmm0
	X86_MEM_WRITE_u32(base, 0x570AF0u, ctx.xmm[0].u32[0]);
	// 0x2A9438: ret
	return;
}

void sub_2A9440(X86Context& ctx, uint8_t* base) {
	// 0x2A9440: movss xmm0, dword ptr [0x00570B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B7Cu);
	// 0x2A9448: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A9450: movss [0x00570B48], xmm0
	X86_MEM_WRITE_u32(base, 0x570B48u, ctx.xmm[0].u32[0]);
	// 0x2A9458: ret
	return;
}

void sub_2A9460(X86Context& ctx, uint8_t* base) {
	// 0x2A9460: movss xmm0, dword ptr [0x00570AF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AF0u);
	// 0x2A9468: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A9470: movss [0x00570B58], xmm0
	X86_MEM_WRITE_u32(base, 0x570B58u, ctx.xmm[0].u32[0]);
	// 0x2A9478: ret
	return;
}

void sub_2A9480(X86Context& ctx, uint8_t* base) {
	// 0x2A9480: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A9488: movss [0x00570AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x570AE4u, ctx.xmm[0].u32[0]);
	// 0x2A9490: ret
	return;
}

void sub_2A94A0(X86Context& ctx, uint8_t* base) {
	// 0x2A94A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A94A8: movss [0x00570B24], xmm0
	X86_MEM_WRITE_u32(base, 0x570B24u, ctx.xmm[0].u32[0]);
	// 0x2A94B0: ret
	return;
}

void sub_2A94C0(X86Context& ctx, uint8_t* base) {
	// 0x2A94C0: movss xmm0, dword ptr [0x00570B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B20u);
	// 0x2A94C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A94D0: movss [0x00570B30], xmm0
	X86_MEM_WRITE_u32(base, 0x570B30u, ctx.xmm[0].u32[0]);
	// 0x2A94D8: ret
	return;
}

void sub_2A94E0(X86Context& ctx, uint8_t* base) {
	// 0x2A94E0: movss xmm0, dword ptr [0x00570B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B7Cu);
	// 0x2A94E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A94F0: movss [0x00570B80], xmm0
	X86_MEM_WRITE_u32(base, 0x570B80u, ctx.xmm[0].u32[0]);
	// 0x2A94F8: ret
	return;
}

void sub_2A9500(X86Context& ctx, uint8_t* base) {
	// 0x2A9500: movss xmm0, dword ptr [0x00570B30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B30u);
	// 0x2A9508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9510: movss [0x00570B6C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B6Cu, ctx.xmm[0].u32[0]);
	// 0x2A9518: ret
	return;
}

void sub_2A9520(X86Context& ctx, uint8_t* base) {
	// 0x2A9520: movss xmm0, dword ptr [0x00570B80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B80u);
	// 0x2A9528: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9530: movss [0x00570B90], xmm0
	X86_MEM_WRITE_u32(base, 0x570B90u, ctx.xmm[0].u32[0]);
	// 0x2A9538: ret
	return;
}

void sub_2A9540(X86Context& ctx, uint8_t* base) {
	// 0x2A9540: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A9548: movss [0x00570AF4], xmm0
	X86_MEM_WRITE_u32(base, 0x570AF4u, ctx.xmm[0].u32[0]);
	// 0x2A9550: ret
	return;
}

void sub_2A9560(X86Context& ctx, uint8_t* base) {
	// 0x2A9560: movss xmm0, dword ptr [0x00570B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B20u);
	// 0x2A9568: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9570: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A9578: movss [0x00570B78], xmm0
	X86_MEM_WRITE_u32(base, 0x570B78u, ctx.xmm[0].u32[0]);
	// 0x2A9580: ret
	return;
}

void sub_2A9590(X86Context& ctx, uint8_t* base) {
	// 0x2A9590: movss xmm0, dword ptr [0x00570B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B7Cu);
	// 0x2A9598: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A95A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A95A8: movss [0x00570B0C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B0Cu, ctx.xmm[0].u32[0]);
	// 0x2A95B0: ret
	return;
}

void sub_2A95C0(X86Context& ctx, uint8_t* base) {
	// 0x2A95C0: movss xmm0, dword ptr [0x00570B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B20u);
	// 0x2A95C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A95D0: movss [0x00570B14], xmm0
	X86_MEM_WRITE_u32(base, 0x570B14u, ctx.xmm[0].u32[0]);
	// 0x2A95D8: ret
	return;
}

void sub_2A95E0(X86Context& ctx, uint8_t* base) {
	// 0x2A95E0: movss xmm0, dword ptr [0x00570B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B7Cu);
	// 0x2A95E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A95F0: movss [0x00570B84], xmm0
	X86_MEM_WRITE_u32(base, 0x570B84u, ctx.xmm[0].u32[0]);
	// 0x2A95F8: ret
	return;
}

void sub_2A9600(X86Context& ctx, uint8_t* base) {
	// 0x2A9600: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A9608: movss [0x00570AF8], xmm0
	X86_MEM_WRITE_u32(base, 0x570AF8u, ctx.xmm[0].u32[0]);
	// 0x2A9610: ret
	return;
}

void sub_2A9620(X86Context& ctx, uint8_t* base) {
	// 0x2A9620: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A9628: movss [0x00570B2C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B2Cu, ctx.xmm[0].u32[0]);
	// 0x2A9630: ret
	return;
}

void sub_2A9640(X86Context& ctx, uint8_t* base) {
	// 0x2A9640: movss xmm0, dword ptr [0x00570AF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570AF8u);
	// 0x2A9648: movss [0x00570B98], xmm0
	X86_MEM_WRITE_u32(base, 0x570B98u, ctx.xmm[0].u32[0]);
	// 0x2A9650: ret
	return;
}

void sub_2A9660(X86Context& ctx, uint8_t* base) {
	// 0x2A9660: movss xmm0, dword ptr [0x00570B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B7Cu);
	// 0x2A9668: subss xmm0, [0x00570AF8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570AF8u);
	// 0x2A9670: movss [0x00570B5C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B5Cu, ctx.xmm[0].u32[0]);
	// 0x2A9678: ret
	return;
}

void sub_2A9680(X86Context& ctx, uint8_t* base) {
	// 0x2A9680: movss xmm0, dword ptr [0x00570B5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B5Cu);
	// 0x2A9688: subss xmm0, [0x00570B2C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570B2Cu);
	// 0x2A9690: movss [0x00570B54], xmm0
	X86_MEM_WRITE_u32(base, 0x570B54u, ctx.xmm[0].u32[0]);
	// 0x2A9698: ret
	return;
}

void sub_2A96A0(X86Context& ctx, uint8_t* base) {
	// 0x2A96A0: movss xmm0, dword ptr [0x00570B84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B84u);
	// 0x2A96A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A96B0: movss [0x00570B40], xmm0
	X86_MEM_WRITE_u32(base, 0x570B40u, ctx.xmm[0].u32[0]);
	// 0x2A96B8: ret
	return;
}

void sub_2A96C0(X86Context& ctx, uint8_t* base) {
	// 0x2A96C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A96C8: movss [0x00570B28], xmm0
	X86_MEM_WRITE_u32(base, 0x570B28u, ctx.xmm[0].u32[0]);
	// 0x2A96D0: ret
	return;
}

void sub_2A96E0(X86Context& ctx, uint8_t* base) {
	// 0x2A96E0: movss xmm0, dword ptr [0x00570B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B40u);
	// 0x2A96E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A96F0: movss [0x00570B74], xmm0
	X86_MEM_WRITE_u32(base, 0x570B74u, ctx.xmm[0].u32[0]);
	// 0x2A96F8: ret
	return;
}

void sub_2A9700(X86Context& ctx, uint8_t* base) {
	// 0x2A9700: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A9708: movss [0x00570B44], xmm0
	X86_MEM_WRITE_u32(base, 0x570B44u, ctx.xmm[0].u32[0]);
	// 0x2A9710: ret
	return;
}

void sub_2A9720(X86Context& ctx, uint8_t* base) {
	// 0x2A9720: movss xmm0, dword ptr [0x00570B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B48u);
	// 0x2A9728: subss xmm0, [0x003A7950]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7950u);
	// 0x2A9730: movss [0x00570B18], xmm0
	X86_MEM_WRITE_u32(base, 0x570B18u, ctx.xmm[0].u32[0]);
	// 0x2A9738: ret
	return;
}

void sub_2A9740(X86Context& ctx, uint8_t* base) {
	// 0x2A9740: movss xmm0, dword ptr [0x003B1850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1850u);
	// 0x2A9748: movss [0x00570AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x570AE8u, ctx.xmm[0].u32[0]);
	// 0x2A9750: ret
	return;
}

void sub_2A9760(X86Context& ctx, uint8_t* base) {
	// 0x2A9760: movss xmm0, dword ptr [0x003B1CE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CE0u);
	// 0x2A9768: movss [0x00570B10], xmm0
	X86_MEM_WRITE_u32(base, 0x570B10u, ctx.xmm[0].u32[0]);
	// 0x2A9770: ret
	return;
}

void sub_2A9780(X86Context& ctx, uint8_t* base) {
	// 0x2A9780: movss xmm0, dword ptr [0x00570B10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B10u);
	// 0x2A9788: subss xmm0, [0x00570AE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570AE8u);
	// 0x2A9790: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A9798: movss [0x00570B1C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B1Cu, ctx.xmm[0].u32[0]);
	// 0x2A97A0: ret
	return;
}

void sub_2A97B0(X86Context& ctx, uint8_t* base) {
	// 0x2A97B0: movss xmm0, dword ptr [0x00570B18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570B18u);
	// 0x2A97B8: subss xmm0, [0x003A795C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A795Cu);
	// 0x2A97C0: movss [0x00570B3C], xmm0
	X86_MEM_WRITE_u32(base, 0x570B3Cu, ctx.xmm[0].u32[0]);
	// 0x2A97C8: ret
	return;
}

void sub_2A97D0(X86Context& ctx, uint8_t* base) {
	// 0x2A97D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A97D8: movss [0x00570BF8], xmm0
	X86_MEM_WRITE_u32(base, 0x570BF8u, ctx.xmm[0].u32[0]);
	// 0x2A97E0: ret
	return;
}

void sub_2A97F0(X86Context& ctx, uint8_t* base) {
	// 0x2A97F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A97F8: movss [0x00570C14], xmm0
	X86_MEM_WRITE_u32(base, 0x570C14u, ctx.xmm[0].u32[0]);
	// 0x2A9800: ret
	return;
}

void sub_2A9810(X86Context& ctx, uint8_t* base) {
	// 0x2A9810: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A9818: movss [0x00570BEC], xmm0
	X86_MEM_WRITE_u32(base, 0x570BECu, ctx.xmm[0].u32[0]);
	// 0x2A9820: ret
	return;
}

void sub_2A9830(X86Context& ctx, uint8_t* base) {
	// 0x2A9830: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A9838: movss [0x00570BA4], xmm0
	X86_MEM_WRITE_u32(base, 0x570BA4u, ctx.xmm[0].u32[0]);
	// 0x2A9840: ret
	return;
}

void sub_2A9850(X86Context& ctx, uint8_t* base) {
	// 0x2A9850: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A9858: movss [0x00570BFC], xmm0
	X86_MEM_WRITE_u32(base, 0x570BFCu, ctx.xmm[0].u32[0]);
	// 0x2A9860: ret
	return;
}

void sub_2A9870(X86Context& ctx, uint8_t* base) {
	// 0x2A9870: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A9878: movss [0x00570BC0], xmm0
	X86_MEM_WRITE_u32(base, 0x570BC0u, ctx.xmm[0].u32[0]);
	// 0x2A9880: ret
	return;
}

void sub_2A9890(X86Context& ctx, uint8_t* base) {
	// 0x2A9890: movss xmm0, dword ptr [0x00570BFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BFCu);
	// 0x2A9898: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A98A0: movss [0x00570C34], xmm0
	X86_MEM_WRITE_u32(base, 0x570C34u, ctx.xmm[0].u32[0]);
	// 0x2A98A8: ret
	return;
}

void sub_2A98B0(X86Context& ctx, uint8_t* base) {
	// 0x2A98B0: movss xmm0, dword ptr [0x00570BC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BC0u);
	// 0x2A98B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A98C0: movss [0x00570C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C1Cu, ctx.xmm[0].u32[0]);
	// 0x2A98C8: ret
	return;
}

void sub_2A98D0(X86Context& ctx, uint8_t* base) {
	// 0x2A98D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A98D8: movss [0x00570C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C4Cu, ctx.xmm[0].u32[0]);
	// 0x2A98E0: ret
	return;
}

void sub_2A98F0(X86Context& ctx, uint8_t* base) {
	// 0x2A98F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A98F8: movss [0x00570C38], xmm0
	X86_MEM_WRITE_u32(base, 0x570C38u, ctx.xmm[0].u32[0]);
	// 0x2A9900: ret
	return;
}

void sub_2A9910(X86Context& ctx, uint8_t* base) {
	// 0x2A9910: movss xmm0, dword ptr [0x00570C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C38u);
	// 0x2A9918: movss [0x00570C48], xmm0
	X86_MEM_WRITE_u32(base, 0x570C48u, ctx.xmm[0].u32[0]);
	// 0x2A9920: ret
	return;
}

void sub_2A9930(X86Context& ctx, uint8_t* base) {
	// 0x2A9930: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A9938: movss [0x00570BAC], xmm0
	X86_MEM_WRITE_u32(base, 0x570BACu, ctx.xmm[0].u32[0]);
	// 0x2A9940: ret
	return;
}

void sub_2A9950(X86Context& ctx, uint8_t* base) {
	// 0x2A9950: movss xmm0, dword ptr [0x00570BC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BC0u);
	// 0x2A9958: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A9960: movss [0x00570C40], xmm0
	X86_MEM_WRITE_u32(base, 0x570C40u, ctx.xmm[0].u32[0]);
	// 0x2A9968: ret
	return;
}

void sub_2A9970(X86Context& ctx, uint8_t* base) {
	// 0x2A9970: movss xmm0, dword ptr [0x00570BC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BC0u);
	// 0x2A9978: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A9980: movss [0x00570BE8], xmm0
	X86_MEM_WRITE_u32(base, 0x570BE8u, ctx.xmm[0].u32[0]);
	// 0x2A9988: ret
	return;
}

void sub_2A9990(X86Context& ctx, uint8_t* base) {
	// 0x2A9990: movss xmm0, dword ptr [0x00570BC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BC0u);
	// 0x2A9998: subss xmm0, [0x00570BE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570BE8u);
	// 0x2A99A0: movss [0x00570BC8], xmm0
	X86_MEM_WRITE_u32(base, 0x570BC8u, ctx.xmm[0].u32[0]);
	// 0x2A99A8: ret
	return;
}

void sub_2A99B0(X86Context& ctx, uint8_t* base) {
	// 0x2A99B0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A99B8: movss [0x00570C10], xmm0
	X86_MEM_WRITE_u32(base, 0x570C10u, ctx.xmm[0].u32[0]);
	// 0x2A99C0: ret
	return;
}

void sub_2A99D0(X86Context& ctx, uint8_t* base) {
	// 0x2A99D0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A99D8: movss [0x00570BC4], xmm0
	X86_MEM_WRITE_u32(base, 0x570BC4u, ctx.xmm[0].u32[0]);
	// 0x2A99E0: ret
	return;
}

void sub_2A99F0(X86Context& ctx, uint8_t* base) {
	// 0x2A99F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A99F8: movss [0x00570BD4], xmm0
	X86_MEM_WRITE_u32(base, 0x570BD4u, ctx.xmm[0].u32[0]);
	// 0x2A9A00: ret
	return;
}

void sub_2A9A10(X86Context& ctx, uint8_t* base) {
	// 0x2A9A10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A9A18: movss [0x00570C28], xmm0
	X86_MEM_WRITE_u32(base, 0x570C28u, ctx.xmm[0].u32[0]);
	// 0x2A9A20: ret
	return;
}

void sub_2A9A30(X86Context& ctx, uint8_t* base) {
	// 0x2A9A30: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A9A38: movss [0x00570C0C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C0Cu, ctx.xmm[0].u32[0]);
	// 0x2A9A40: ret
	return;
}

void sub_2A9A50(X86Context& ctx, uint8_t* base) {
	// 0x2A9A50: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A9A58: movss [0x00570BBC], xmm0
	X86_MEM_WRITE_u32(base, 0x570BBCu, ctx.xmm[0].u32[0]);
	// 0x2A9A60: ret
	return;
}

void sub_2A9A70(X86Context& ctx, uint8_t* base) {
	// 0x2A9A70: movss xmm0, dword ptr [0x00570BD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BD4u);
	// 0x2A9A78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A9A80: movss [0x00570BB0], xmm0
	X86_MEM_WRITE_u32(base, 0x570BB0u, ctx.xmm[0].u32[0]);
	// 0x2A9A88: ret
	return;
}

void sub_2A9A90(X86Context& ctx, uint8_t* base) {
	// 0x2A9A90: movss xmm0, dword ptr [0x00570C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C28u);
	// 0x2A9A98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A9AA0: movss [0x00570BF4], xmm0
	X86_MEM_WRITE_u32(base, 0x570BF4u, ctx.xmm[0].u32[0]);
	// 0x2A9AA8: ret
	return;
}

void sub_2A9AB0(X86Context& ctx, uint8_t* base) {
	// 0x2A9AB0: movss xmm0, dword ptr [0x00570BB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BB0u);
	// 0x2A9AB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A9AC0: movss [0x00570C04], xmm0
	X86_MEM_WRITE_u32(base, 0x570C04u, ctx.xmm[0].u32[0]);
	// 0x2A9AC8: ret
	return;
}

void sub_2A9AD0(X86Context& ctx, uint8_t* base) {
	// 0x2A9AD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A9AD8: movss [0x00570BA8], xmm0
	X86_MEM_WRITE_u32(base, 0x570BA8u, ctx.xmm[0].u32[0]);
	// 0x2A9AE0: ret
	return;
}

void sub_2A9AF0(X86Context& ctx, uint8_t* base) {
	// 0x2A9AF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A9AF8: movss [0x00570BD8], xmm0
	X86_MEM_WRITE_u32(base, 0x570BD8u, ctx.xmm[0].u32[0]);
	// 0x2A9B00: ret
	return;
}

void sub_2A9B10(X86Context& ctx, uint8_t* base) {
	// 0x2A9B10: movss xmm0, dword ptr [0x00570BD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BD4u);
	// 0x2A9B18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A9B20: movss [0x00570BE4], xmm0
	X86_MEM_WRITE_u32(base, 0x570BE4u, ctx.xmm[0].u32[0]);
	// 0x2A9B28: ret
	return;
}

void sub_2A9B30(X86Context& ctx, uint8_t* base) {
	// 0x2A9B30: movss xmm0, dword ptr [0x00570C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C28u);
	// 0x2A9B38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A9B40: movss [0x00570C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C2Cu, ctx.xmm[0].u32[0]);
	// 0x2A9B48: ret
	return;
}

void sub_2A9B50(X86Context& ctx, uint8_t* base) {
	// 0x2A9B50: movss xmm0, dword ptr [0x00570BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BE4u);
	// 0x2A9B58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9B60: movss [0x00570C18], xmm0
	X86_MEM_WRITE_u32(base, 0x570C18u, ctx.xmm[0].u32[0]);
	// 0x2A9B68: ret
	return;
}

void sub_2A9B70(X86Context& ctx, uint8_t* base) {
	// 0x2A9B70: movss xmm0, dword ptr [0x00570C2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C2Cu);
	// 0x2A9B78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9B80: movss [0x00570C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C3Cu, ctx.xmm[0].u32[0]);
	// 0x2A9B88: ret
	return;
}

void sub_2A9B90(X86Context& ctx, uint8_t* base) {
	// 0x2A9B90: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A9B98: movss [0x00570BB4], xmm0
	X86_MEM_WRITE_u32(base, 0x570BB4u, ctx.xmm[0].u32[0]);
	// 0x2A9BA0: ret
	return;
}

void sub_2A9BB0(X86Context& ctx, uint8_t* base) {
	// 0x2A9BB0: movss xmm0, dword ptr [0x00570BD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BD4u);
	// 0x2A9BB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9BC0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A9BC8: movss [0x00570C24], xmm0
	X86_MEM_WRITE_u32(base, 0x570C24u, ctx.xmm[0].u32[0]);
	// 0x2A9BD0: ret
	return;
}

void sub_2A9BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A9BE0: movss xmm0, dword ptr [0x00570C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C28u);
	// 0x2A9BE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9BF0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A9BF8: movss [0x00570BCC], xmm0
	X86_MEM_WRITE_u32(base, 0x570BCCu, ctx.xmm[0].u32[0]);
	// 0x2A9C00: ret
	return;
}

void sub_2A9C10(X86Context& ctx, uint8_t* base) {
	// 0x2A9C10: movss xmm0, dword ptr [0x00570BD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BD4u);
	// 0x2A9C18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9C20: movss [0x00570BD0], xmm0
	X86_MEM_WRITE_u32(base, 0x570BD0u, ctx.xmm[0].u32[0]);
	// 0x2A9C28: ret
	return;
}

void sub_2A9C30(X86Context& ctx, uint8_t* base) {
	// 0x2A9C30: movss xmm0, dword ptr [0x00570C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C28u);
	// 0x2A9C38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A9C40: movss [0x00570C30], xmm0
	X86_MEM_WRITE_u32(base, 0x570C30u, ctx.xmm[0].u32[0]);
	// 0x2A9C48: ret
	return;
}

void sub_2A9C50(X86Context& ctx, uint8_t* base) {
	// 0x2A9C50: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A9C58: movss [0x00570BB8], xmm0
	X86_MEM_WRITE_u32(base, 0x570BB8u, ctx.xmm[0].u32[0]);
	// 0x2A9C60: ret
	return;
}

void sub_2A9C70(X86Context& ctx, uint8_t* base) {
	// 0x2A9C70: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A9C78: movss [0x00570BE0], xmm0
	X86_MEM_WRITE_u32(base, 0x570BE0u, ctx.xmm[0].u32[0]);
	// 0x2A9C80: ret
	return;
}

void sub_2A9C90(X86Context& ctx, uint8_t* base) {
	// 0x2A9C90: movss xmm0, dword ptr [0x00570BB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BB8u);
	// 0x2A9C98: movss [0x00570C44], xmm0
	X86_MEM_WRITE_u32(base, 0x570C44u, ctx.xmm[0].u32[0]);
	// 0x2A9CA0: ret
	return;
}

void sub_2A9CB0(X86Context& ctx, uint8_t* base) {
	// 0x2A9CB0: movss xmm0, dword ptr [0x00570C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C28u);
	// 0x2A9CB8: subss xmm0, [0x00570BB8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570BB8u);
	// 0x2A9CC0: movss [0x00570C08], xmm0
	X86_MEM_WRITE_u32(base, 0x570C08u, ctx.xmm[0].u32[0]);
	// 0x2A9CC8: ret
	return;
}

void sub_2A9CD0(X86Context& ctx, uint8_t* base) {
	// 0x2A9CD0: movss xmm0, dword ptr [0x00570C08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C08u);
	// 0x2A9CD8: subss xmm0, [0x00570BE0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570BE0u);
	// 0x2A9CE0: movss [0x00570C00], xmm0
	X86_MEM_WRITE_u32(base, 0x570C00u, ctx.xmm[0].u32[0]);
	// 0x2A9CE8: ret
	return;
}

void sub_2A9CF0(X86Context& ctx, uint8_t* base) {
	// 0x2A9CF0: movss xmm0, dword ptr [0x00570C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C30u);
	// 0x2A9CF8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A9D00: movss [0x00570BF0], xmm0
	X86_MEM_WRITE_u32(base, 0x570BF0u, ctx.xmm[0].u32[0]);
	// 0x2A9D08: ret
	return;
}

void sub_2A9D10(X86Context& ctx, uint8_t* base) {
	// 0x2A9D10: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A9D18: movss [0x00570BDC], xmm0
	X86_MEM_WRITE_u32(base, 0x570BDCu, ctx.xmm[0].u32[0]);
	// 0x2A9D20: ret
	return;
}

void sub_2A9D30(X86Context& ctx, uint8_t* base) {
	// 0x2A9D30: movss xmm0, dword ptr [0x00570BF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570BF0u);
	// 0x2A9D38: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A9D40: movss [0x00570C20], xmm0
	X86_MEM_WRITE_u32(base, 0x570C20u, ctx.xmm[0].u32[0]);
	// 0x2A9D48: ret
	return;
}

void sub_2A9D50(X86Context& ctx, uint8_t* base) {
	// 0x2A9D50: mov eax, [0x00407680]
	ctx.eax = X86_MEM_READ_u32(base, 0x407680u);
	// 0x2A9D55: mov ecx, [0x00407684]
	ctx.ecx = X86_MEM_READ_u32(base, 0x407684u);
	// 0x2A9D5B: mov edx, [0x00407688]
	ctx.edx = X86_MEM_READ_u32(base, 0x407688u);
	// 0x2A9D61: mov [0x004076A0], eax
	X86_MEM_WRITE_u32(base, 0x4076A0u, ctx.eax);
	// 0x2A9D66: mov eax, [0x0040768C]
	ctx.eax = X86_MEM_READ_u32(base, 0x40768Cu);
	// 0x2A9D6B: mov [0x004076A4], ecx
	X86_MEM_WRITE_u32(base, 0x4076A4u, ctx.ecx);
	// 0x2A9D71: mov ecx, [0x00407690]
	ctx.ecx = X86_MEM_READ_u32(base, 0x407690u);
	// 0x2A9D77: mov [0x004076A8], edx
	X86_MEM_WRITE_u32(base, 0x4076A8u, ctx.edx);
	// 0x2A9D7D: mov edx, [0x00407694]
	ctx.edx = X86_MEM_READ_u32(base, 0x407694u);
	// 0x2A9D83: mov [0x004076AC], eax
	X86_MEM_WRITE_u32(base, 0x4076ACu, ctx.eax);
	// 0x2A9D88: mov [0x004076B8], ecx
	X86_MEM_WRITE_u32(base, 0x4076B8u, ctx.ecx);
	// 0x2A9D8E: mov [0x004076BC], edx
	X86_MEM_WRITE_u32(base, 0x4076BCu, ctx.edx);
	// 0x2A9D94: ret
	return;
}

void sub_2A9DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A9DA0: mov eax, [0x00407680]
	ctx.eax = X86_MEM_READ_u32(base, 0x407680u);
	// 0x2A9DA5: mov ecx, [0x00407684]
	ctx.ecx = X86_MEM_READ_u32(base, 0x407684u);
	// 0x2A9DAB: mov edx, [0x00407688]
	ctx.edx = X86_MEM_READ_u32(base, 0x407688u);
	// 0x2A9DB1: mov [0x004076C0], eax
	X86_MEM_WRITE_u32(base, 0x4076C0u, ctx.eax);
	// 0x2A9DB6: mov eax, [0x0040768C]
	ctx.eax = X86_MEM_READ_u32(base, 0x40768Cu);
	// 0x2A9DBB: mov [0x004076C4], ecx
	X86_MEM_WRITE_u32(base, 0x4076C4u, ctx.ecx);
	// 0x2A9DC1: mov ecx, [0x00407690]
	ctx.ecx = X86_MEM_READ_u32(base, 0x407690u);
	// 0x2A9DC7: mov [0x004076C8], edx
	X86_MEM_WRITE_u32(base, 0x4076C8u, ctx.edx);
	// 0x2A9DCD: mov edx, [0x00407694]
	ctx.edx = X86_MEM_READ_u32(base, 0x407694u);
	// 0x2A9DD3: mov [0x004076CC], eax
	X86_MEM_WRITE_u32(base, 0x4076CCu, ctx.eax);
	// 0x2A9DD8: mov [0x004076D8], ecx
	X86_MEM_WRITE_u32(base, 0x4076D8u, ctx.ecx);
	// 0x2A9DDE: mov [0x004076DC], edx
	X86_MEM_WRITE_u32(base, 0x4076DCu, ctx.edx);
	// 0x2A9DE4: ret
	return;
}

void sub_2A9DF0(X86Context& ctx, uint8_t* base) {
	// 0x2A9DF0: mov eax, [0x00407680]
	ctx.eax = X86_MEM_READ_u32(base, 0x407680u);
	// 0x2A9DF5: mov ecx, [0x00407684]
	ctx.ecx = X86_MEM_READ_u32(base, 0x407684u);
	// 0x2A9DFB: mov edx, [0x00407688]
	ctx.edx = X86_MEM_READ_u32(base, 0x407688u);
	// 0x2A9E01: mov [0x004076E0], eax
	X86_MEM_WRITE_u32(base, 0x4076E0u, ctx.eax);
	// 0x2A9E06: mov eax, [0x0040768C]
	ctx.eax = X86_MEM_READ_u32(base, 0x40768Cu);
	// 0x2A9E0B: mov [0x004076E4], ecx
	X86_MEM_WRITE_u32(base, 0x4076E4u, ctx.ecx);
	// 0x2A9E11: mov ecx, [0x00407690]
	ctx.ecx = X86_MEM_READ_u32(base, 0x407690u);
	// 0x2A9E17: mov [0x004076E8], edx
	X86_MEM_WRITE_u32(base, 0x4076E8u, ctx.edx);
	// 0x2A9E1D: mov edx, [0x00407694]
	ctx.edx = X86_MEM_READ_u32(base, 0x407694u);
	// 0x2A9E23: mov [0x004076EC], eax
	X86_MEM_WRITE_u32(base, 0x4076ECu, ctx.eax);
	// 0x2A9E28: mov [0x004076F8], ecx
	X86_MEM_WRITE_u32(base, 0x4076F8u, ctx.ecx);
	// 0x2A9E2E: mov [0x004076FC], edx
	X86_MEM_WRITE_u32(base, 0x4076FCu, ctx.edx);
	// 0x2A9E34: ret
	return;
}

void sub_2A9E40(X86Context& ctx, uint8_t* base) {
	// 0x2A9E40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A9E48: movss [0x00570CAC], xmm0
	X86_MEM_WRITE_u32(base, 0x570CACu, ctx.xmm[0].u32[0]);
	// 0x2A9E50: ret
	return;
}

void sub_2A9E60(X86Context& ctx, uint8_t* base) {
	// 0x2A9E60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A9E68: movss [0x00570CCC], xmm0
	X86_MEM_WRITE_u32(base, 0x570CCCu, ctx.xmm[0].u32[0]);
	// 0x2A9E70: ret
	return;
}

void sub_2A9E80(X86Context& ctx, uint8_t* base) {
	// 0x2A9E80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A9E88: movss [0x00570CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x570CA0u, ctx.xmm[0].u32[0]);
	// 0x2A9E90: ret
	return;
}

void sub_2A9EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A9EA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A9EA8: movss [0x00570C50], xmm0
	X86_MEM_WRITE_u32(base, 0x570C50u, ctx.xmm[0].u32[0]);
	// 0x2A9EB0: ret
	return;
}

void sub_2A9EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A9EC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A9EC8: movss [0x00570CB0], xmm0
	X86_MEM_WRITE_u32(base, 0x570CB0u, ctx.xmm[0].u32[0]);
	// 0x2A9ED0: ret
	return;
}

void sub_2A9EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A9EE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A9EE8: movss [0x00570C70], xmm0
	X86_MEM_WRITE_u32(base, 0x570C70u, ctx.xmm[0].u32[0]);
	// 0x2A9EF0: ret
	return;
}

void sub_2A9F00(X86Context& ctx, uint8_t* base) {
	// 0x2A9F00: movss xmm0, dword ptr [0x00570CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CB0u);
	// 0x2A9F08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A9F10: movss [0x00570CF0], xmm0
	X86_MEM_WRITE_u32(base, 0x570CF0u, ctx.xmm[0].u32[0]);
	// 0x2A9F18: ret
	return;
}

void sub_2A9F20(X86Context& ctx, uint8_t* base) {
	// 0x2A9F20: movss xmm0, dword ptr [0x00570C70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C70u);
	// 0x2A9F28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A9F30: movss [0x00570CD8], xmm0
	X86_MEM_WRITE_u32(base, 0x570CD8u, ctx.xmm[0].u32[0]);
	// 0x2A9F38: ret
	return;
}

void sub_2A9F40(X86Context& ctx, uint8_t* base) {
	// 0x2A9F40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A9F48: movss [0x00570D0C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D0Cu, ctx.xmm[0].u32[0]);
	// 0x2A9F50: ret
	return;
}

void sub_2A9F60(X86Context& ctx, uint8_t* base) {
	// 0x2A9F60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A9F68: movss [0x00570CF4], xmm0
	X86_MEM_WRITE_u32(base, 0x570CF4u, ctx.xmm[0].u32[0]);
	// 0x2A9F70: ret
	return;
}

void sub_2A9F80(X86Context& ctx, uint8_t* base) {
	// 0x2A9F80: movss xmm0, dword ptr [0x00570CF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CF4u);
	// 0x2A9F88: movss [0x00570D08], xmm0
	X86_MEM_WRITE_u32(base, 0x570D08u, ctx.xmm[0].u32[0]);
	// 0x2A9F90: ret
	return;
}

void sub_2A9FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A9FA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A9FA8: movss [0x00570C58], xmm0
	X86_MEM_WRITE_u32(base, 0x570C58u, ctx.xmm[0].u32[0]);
	// 0x2A9FB0: ret
	return;
}

void sub_2A9FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A9FC0: movss xmm0, dword ptr [0x00570C70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C70u);
	// 0x2A9FC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A9FD0: movss [0x00570CFC], xmm0
	X86_MEM_WRITE_u32(base, 0x570CFCu, ctx.xmm[0].u32[0]);
	// 0x2A9FD8: ret
	return;
}

void sub_2A9FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A9FE0: movss xmm0, dword ptr [0x00570C70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C70u);
	// 0x2A9FE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A9FF0: movss [0x00570C9C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C9Cu, ctx.xmm[0].u32[0]);
	// 0x2A9FF8: ret
	return;
}

void sub_2AA000(X86Context& ctx, uint8_t* base) {
	// 0x2AA000: movss xmm0, dword ptr [0x00570C70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C70u);
	// 0x2AA008: subss xmm0, [0x00570C9C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570C9Cu);
	// 0x2AA010: movss [0x00570C78], xmm0
	X86_MEM_WRITE_u32(base, 0x570C78u, ctx.xmm[0].u32[0]);
	// 0x2AA018: ret
	return;
}

void sub_2AA020(X86Context& ctx, uint8_t* base) {
	// 0x2AA020: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AA028: movss [0x00570CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x570CC8u, ctx.xmm[0].u32[0]);
	// 0x2AA030: ret
	return;
}

void sub_2AA040(X86Context& ctx, uint8_t* base) {
	// 0x2AA040: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AA048: movss [0x00570C74], xmm0
	X86_MEM_WRITE_u32(base, 0x570C74u, ctx.xmm[0].u32[0]);
	// 0x2AA050: ret
	return;
}

void sub_2AA060(X86Context& ctx, uint8_t* base) {
	// 0x2AA060: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AA068: movss [0x00570C84], xmm0
	X86_MEM_WRITE_u32(base, 0x570C84u, ctx.xmm[0].u32[0]);
	// 0x2AA070: ret
	return;
}

void sub_2AA080(X86Context& ctx, uint8_t* base) {
	// 0x2AA080: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AA088: movss [0x00570CE4], xmm0
	X86_MEM_WRITE_u32(base, 0x570CE4u, ctx.xmm[0].u32[0]);
	// 0x2AA090: ret
	return;
}

void sub_2AA0A0(X86Context& ctx, uint8_t* base) {
	// 0x2AA0A0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AA0A8: movss [0x00570CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x570CC0u, ctx.xmm[0].u32[0]);
	// 0x2AA0B0: ret
	return;
}

void sub_2AA0C0(X86Context& ctx, uint8_t* base) {
	// 0x2AA0C0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AA0C8: movss [0x00570C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C6Cu, ctx.xmm[0].u32[0]);
	// 0x2AA0D0: ret
	return;
}

void sub_2AA0E0(X86Context& ctx, uint8_t* base) {
	// 0x2AA0E0: movss xmm0, dword ptr [0x00570C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C84u);
	// 0x2AA0E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AA0F0: movss [0x00570C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C5Cu, ctx.xmm[0].u32[0]);
	// 0x2AA0F8: ret
	return;
}

void sub_2AA100(X86Context& ctx, uint8_t* base) {
	// 0x2AA100: movss xmm0, dword ptr [0x00570CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CE4u);
	// 0x2AA108: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AA110: movss [0x00570CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x570CA8u, ctx.xmm[0].u32[0]);
	// 0x2AA118: ret
	return;
}

void sub_2AA120(X86Context& ctx, uint8_t* base) {
	// 0x2AA120: movss xmm0, dword ptr [0x00570C5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C5Cu);
	// 0x2AA128: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AA130: movss [0x00570CB8], xmm0
	X86_MEM_WRITE_u32(base, 0x570CB8u, ctx.xmm[0].u32[0]);
	// 0x2AA138: ret
	return;
}

void sub_2AA140(X86Context& ctx, uint8_t* base) {
	// 0x2AA140: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AA148: movss [0x00570C54], xmm0
	X86_MEM_WRITE_u32(base, 0x570C54u, ctx.xmm[0].u32[0]);
	// 0x2AA150: ret
	return;
}

void sub_2AA160(X86Context& ctx, uint8_t* base) {
	// 0x2AA160: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AA168: movss [0x00570C88], xmm0
	X86_MEM_WRITE_u32(base, 0x570C88u, ctx.xmm[0].u32[0]);
	// 0x2AA170: ret
	return;
}

void sub_2AA180(X86Context& ctx, uint8_t* base) {
	// 0x2AA180: movss xmm0, dword ptr [0x00570C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C84u);
	// 0x2AA188: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AA190: movss [0x00570C98], xmm0
	X86_MEM_WRITE_u32(base, 0x570C98u, ctx.xmm[0].u32[0]);
	// 0x2AA198: ret
	return;
}

void sub_2AA1A0(X86Context& ctx, uint8_t* base) {
	// 0x2AA1A0: movss xmm0, dword ptr [0x00570CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CE4u);
	// 0x2AA1A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AA1B0: movss [0x00570CE8], xmm0
	X86_MEM_WRITE_u32(base, 0x570CE8u, ctx.xmm[0].u32[0]);
	// 0x2AA1B8: ret
	return;
}

void sub_2AA1C0(X86Context& ctx, uint8_t* base) {
	// 0x2AA1C0: movss xmm0, dword ptr [0x00570C98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C98u);
	// 0x2AA1C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA1D0: movss [0x00570CD0], xmm0
	X86_MEM_WRITE_u32(base, 0x570CD0u, ctx.xmm[0].u32[0]);
	// 0x2AA1D8: ret
	return;
}

void sub_2AA1E0(X86Context& ctx, uint8_t* base) {
	// 0x2AA1E0: movss xmm0, dword ptr [0x00570CE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CE8u);
	// 0x2AA1E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA1F0: movss [0x00570CF8], xmm0
	X86_MEM_WRITE_u32(base, 0x570CF8u, ctx.xmm[0].u32[0]);
	// 0x2AA1F8: ret
	return;
}

void sub_2AA200(X86Context& ctx, uint8_t* base) {
	// 0x2AA200: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AA208: movss [0x00570C60], xmm0
	X86_MEM_WRITE_u32(base, 0x570C60u, ctx.xmm[0].u32[0]);
	// 0x2AA210: ret
	return;
}

void sub_2AA220(X86Context& ctx, uint8_t* base) {
	// 0x2AA220: movss xmm0, dword ptr [0x00570C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C84u);
	// 0x2AA228: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA230: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AA238: movss [0x00570CE0], xmm0
	X86_MEM_WRITE_u32(base, 0x570CE0u, ctx.xmm[0].u32[0]);
	// 0x2AA240: ret
	return;
}

void sub_2AA250(X86Context& ctx, uint8_t* base) {
	// 0x2AA250: movss xmm0, dword ptr [0x00570CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CE4u);
	// 0x2AA258: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA260: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AA268: movss [0x00570C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C7Cu, ctx.xmm[0].u32[0]);
	// 0x2AA270: ret
	return;
}

void sub_2AA280(X86Context& ctx, uint8_t* base) {
	// 0x2AA280: movss xmm0, dword ptr [0x00570C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C84u);
	// 0x2AA288: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA290: movss [0x00570C80], xmm0
	X86_MEM_WRITE_u32(base, 0x570C80u, ctx.xmm[0].u32[0]);
	// 0x2AA298: ret
	return;
}

void sub_2AA2A0(X86Context& ctx, uint8_t* base) {
	// 0x2AA2A0: movss xmm0, dword ptr [0x00570CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CE4u);
	// 0x2AA2A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA2B0: movss [0x00570CEC], xmm0
	X86_MEM_WRITE_u32(base, 0x570CECu, ctx.xmm[0].u32[0]);
	// 0x2AA2B8: ret
	return;
}

void sub_2AA2C0(X86Context& ctx, uint8_t* base) {
	// 0x2AA2C0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AA2C8: movss [0x00570C68], xmm0
	X86_MEM_WRITE_u32(base, 0x570C68u, ctx.xmm[0].u32[0]);
	// 0x2AA2D0: ret
	return;
}

void sub_2AA2E0(X86Context& ctx, uint8_t* base) {
	// 0x2AA2E0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AA2E8: movss [0x00570C94], xmm0
	X86_MEM_WRITE_u32(base, 0x570C94u, ctx.xmm[0].u32[0]);
	// 0x2AA2F0: ret
	return;
}

void sub_2AA300(X86Context& ctx, uint8_t* base) {
	// 0x2AA300: movss xmm0, dword ptr [0x00570C68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570C68u);
	// 0x2AA308: movss [0x00570D00], xmm0
	X86_MEM_WRITE_u32(base, 0x570D00u, ctx.xmm[0].u32[0]);
	// 0x2AA310: ret
	return;
}

void sub_2AA320(X86Context& ctx, uint8_t* base) {
	// 0x2AA320: movss xmm0, dword ptr [0x00570CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CE4u);
	// 0x2AA328: subss xmm0, [0x00570C68]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570C68u);
	// 0x2AA330: movss [0x00570CBC], xmm0
	X86_MEM_WRITE_u32(base, 0x570CBCu, ctx.xmm[0].u32[0]);
	// 0x2AA338: ret
	return;
}

void sub_2AA340(X86Context& ctx, uint8_t* base) {
	// 0x2AA340: movss xmm0, dword ptr [0x00570CBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CBCu);
	// 0x2AA348: subss xmm0, [0x00570C94]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570C94u);
	// 0x2AA350: movss [0x00570CB4], xmm0
	X86_MEM_WRITE_u32(base, 0x570CB4u, ctx.xmm[0].u32[0]);
	// 0x2AA358: ret
	return;
}

void sub_2AA360(X86Context& ctx, uint8_t* base) {
	// 0x2AA360: movss xmm0, dword ptr [0x00570CEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CECu);
	// 0x2AA368: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AA370: movss [0x00570CA4], xmm0
	X86_MEM_WRITE_u32(base, 0x570CA4u, ctx.xmm[0].u32[0]);
	// 0x2AA378: ret
	return;
}

void sub_2AA380(X86Context& ctx, uint8_t* base) {
	// 0x2AA380: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AA388: movss [0x00570C90], xmm0
	X86_MEM_WRITE_u32(base, 0x570C90u, ctx.xmm[0].u32[0]);
	// 0x2AA390: ret
	return;
}

void sub_2AA3A0(X86Context& ctx, uint8_t* base) {
	// 0x2AA3A0: movss xmm0, dword ptr [0x00570CA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CA4u);
	// 0x2AA3A8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AA3B0: movss [0x00570CDC], xmm0
	X86_MEM_WRITE_u32(base, 0x570CDCu, ctx.xmm[0].u32[0]);
	// 0x2AA3B8: ret
	return;
}

void sub_2AA3C0(X86Context& ctx, uint8_t* base) {
	// 0x2AA3C0: movss xmm0, dword ptr [0x004077A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4077A8u);
	// 0x2AA3C8: subss xmm0, [0x003B17C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B17C8u);
	// 0x2AA3D0: movss [0x00570C64], xmm0
	X86_MEM_WRITE_u32(base, 0x570C64u, ctx.xmm[0].u32[0]);
	// 0x2AA3D8: ret
	return;
}

void sub_2AA3E0(X86Context& ctx, uint8_t* base) {
	// 0x2AA3E0: movss xmm0, dword ptr [0x003B22B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B0u);
	// 0x2AA3E8: movss [0x00570D04], xmm0
	X86_MEM_WRITE_u32(base, 0x570D04u, ctx.xmm[0].u32[0]);
	// 0x2AA3F0: ret
	return;
}

void sub_2AA400(X86Context& ctx, uint8_t* base) {
	// 0x2AA400: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2AA408: divss xmm0, [0x00570D04]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x570D04u);
	// 0x2AA410: movss [0x00570CD4], xmm0
	X86_MEM_WRITE_u32(base, 0x570CD4u, ctx.xmm[0].u32[0]);
	// 0x2AA418: ret
	return;
}

void sub_2AA420(X86Context& ctx, uint8_t* base) {
	// 0x2AA420: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2AA428: movss [0x00570CC4], xmm0
	X86_MEM_WRITE_u32(base, 0x570CC4u, ctx.xmm[0].u32[0]);
	// 0x2AA430: ret
	return;
}

void sub_2AA440(X86Context& ctx, uint8_t* base) {
	// 0x2AA440: movss xmm0, dword ptr [0x00570CC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570CC4u);
	// 0x2AA448: mulss xmm0, [0x003B1884]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1884u);
	// 0x2AA450: addss xmm0, [0x004077D0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x4077D0u);
	// 0x2AA458: movss [0x00570C8C], xmm0
	X86_MEM_WRITE_u32(base, 0x570C8Cu, ctx.xmm[0].u32[0]);
	// 0x2AA460: ret
	return;
}

void sub_2AA470(X86Context& ctx, uint8_t* base) {
	// 0x2AA470: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AA478: movss [0x00570D6C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D6Cu, ctx.xmm[0].u32[0]);
	// 0x2AA480: ret
	return;
}

void sub_2AA490(X86Context& ctx, uint8_t* base) {
	// 0x2AA490: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AA498: movss [0x00570D88], xmm0
	X86_MEM_WRITE_u32(base, 0x570D88u, ctx.xmm[0].u32[0]);
	// 0x2AA4A0: ret
	return;
}

void sub_2AA4B0(X86Context& ctx, uint8_t* base) {
	// 0x2AA4B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AA4B8: movss [0x00570D60], xmm0
	X86_MEM_WRITE_u32(base, 0x570D60u, ctx.xmm[0].u32[0]);
	// 0x2AA4C0: ret
	return;
}

void sub_2AA4D0(X86Context& ctx, uint8_t* base) {
	// 0x2AA4D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AA4D8: movss [0x00570D10], xmm0
	X86_MEM_WRITE_u32(base, 0x570D10u, ctx.xmm[0].u32[0]);
	// 0x2AA4E0: ret
	return;
}

void sub_2AA4F0(X86Context& ctx, uint8_t* base) {
	// 0x2AA4F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AA4F8: movss [0x00570D70], xmm0
	X86_MEM_WRITE_u32(base, 0x570D70u, ctx.xmm[0].u32[0]);
	// 0x2AA500: ret
	return;
}

void sub_2AA510(X86Context& ctx, uint8_t* base) {
	// 0x2AA510: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AA518: movss [0x00570D2C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D2Cu, ctx.xmm[0].u32[0]);
	// 0x2AA520: ret
	return;
}

void sub_2AA530(X86Context& ctx, uint8_t* base) {
	// 0x2AA530: movss xmm0, dword ptr [0x00570D70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D70u);
	// 0x2AA538: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AA540: movss [0x00570DA8], xmm0
	X86_MEM_WRITE_u32(base, 0x570DA8u, ctx.xmm[0].u32[0]);
	// 0x2AA548: ret
	return;
}

void sub_2AA550(X86Context& ctx, uint8_t* base) {
	// 0x2AA550: movss xmm0, dword ptr [0x00570D2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D2Cu);
	// 0x2AA558: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AA560: movss [0x00570D90], xmm0
	X86_MEM_WRITE_u32(base, 0x570D90u, ctx.xmm[0].u32[0]);
	// 0x2AA568: ret
	return;
}

void sub_2AA570(X86Context& ctx, uint8_t* base) {
	// 0x2AA570: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AA578: movss [0x00570DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x570DC0u, ctx.xmm[0].u32[0]);
	// 0x2AA580: ret
	return;
}

void sub_2AA590(X86Context& ctx, uint8_t* base) {
	// 0x2AA590: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AA598: movss [0x00570DAC], xmm0
	X86_MEM_WRITE_u32(base, 0x570DACu, ctx.xmm[0].u32[0]);
	// 0x2AA5A0: ret
	return;
}

void sub_2AA5B0(X86Context& ctx, uint8_t* base) {
	// 0x2AA5B0: movss xmm0, dword ptr [0x00570DAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DACu);
	// 0x2AA5B8: movss [0x00570DBC], xmm0
	X86_MEM_WRITE_u32(base, 0x570DBCu, ctx.xmm[0].u32[0]);
	// 0x2AA5C0: ret
	return;
}

void sub_2AA5D0(X86Context& ctx, uint8_t* base) {
	// 0x2AA5D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AA5D8: movss [0x00570D18], xmm0
	X86_MEM_WRITE_u32(base, 0x570D18u, ctx.xmm[0].u32[0]);
	// 0x2AA5E0: ret
	return;
}

void sub_2AA5F0(X86Context& ctx, uint8_t* base) {
	// 0x2AA5F0: movss xmm0, dword ptr [0x00570D2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D2Cu);
	// 0x2AA5F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AA600: movss [0x00570DB4], xmm0
	X86_MEM_WRITE_u32(base, 0x570DB4u, ctx.xmm[0].u32[0]);
	// 0x2AA608: ret
	return;
}

void sub_2AA610(X86Context& ctx, uint8_t* base) {
	// 0x2AA610: movss xmm0, dword ptr [0x00570D2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D2Cu);
	// 0x2AA618: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AA620: movss [0x00570D5C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D5Cu, ctx.xmm[0].u32[0]);
	// 0x2AA628: ret
	return;
}

void sub_2AA630(X86Context& ctx, uint8_t* base) {
	// 0x2AA630: movss xmm0, dword ptr [0x00570D2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D2Cu);
	// 0x2AA638: subss xmm0, [0x00570D5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570D5Cu);
	// 0x2AA640: movss [0x00570D34], xmm0
	X86_MEM_WRITE_u32(base, 0x570D34u, ctx.xmm[0].u32[0]);
	// 0x2AA648: ret
	return;
}

void sub_2AA650(X86Context& ctx, uint8_t* base) {
	// 0x2AA650: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AA658: movss [0x00570D84], xmm0
	X86_MEM_WRITE_u32(base, 0x570D84u, ctx.xmm[0].u32[0]);
	// 0x2AA660: ret
	return;
}

void sub_2AA670(X86Context& ctx, uint8_t* base) {
	// 0x2AA670: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AA678: movss [0x00570D30], xmm0
	X86_MEM_WRITE_u32(base, 0x570D30u, ctx.xmm[0].u32[0]);
	// 0x2AA680: ret
	return;
}

void sub_2AA690(X86Context& ctx, uint8_t* base) {
	// 0x2AA690: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AA698: movss [0x00570D48], xmm0
	X86_MEM_WRITE_u32(base, 0x570D48u, ctx.xmm[0].u32[0]);
	// 0x2AA6A0: ret
	return;
}

void sub_2AA6B0(X86Context& ctx, uint8_t* base) {
	// 0x2AA6B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AA6B8: movss [0x00570D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D9Cu, ctx.xmm[0].u32[0]);
	// 0x2AA6C0: ret
	return;
}

void sub_2AA6D0(X86Context& ctx, uint8_t* base) {
	// 0x2AA6D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AA6D8: movss [0x00570D80], xmm0
	X86_MEM_WRITE_u32(base, 0x570D80u, ctx.xmm[0].u32[0]);
	// 0x2AA6E0: ret
	return;
}

void sub_2AA6F0(X86Context& ctx, uint8_t* base) {
	// 0x2AA6F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AA6F8: movss [0x00570D28], xmm0
	X86_MEM_WRITE_u32(base, 0x570D28u, ctx.xmm[0].u32[0]);
	// 0x2AA700: ret
	return;
}

void sub_2AA710(X86Context& ctx, uint8_t* base) {
	// 0x2AA710: movss xmm0, dword ptr [0x00570D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D48u);
	// 0x2AA718: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AA720: movss [0x00570D1C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D1Cu, ctx.xmm[0].u32[0]);
	// 0x2AA728: ret
	return;
}

void sub_2AA730(X86Context& ctx, uint8_t* base) {
	// 0x2AA730: movss xmm0, dword ptr [0x00570D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D9Cu);
	// 0x2AA738: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AA740: movss [0x00570D68], xmm0
	X86_MEM_WRITE_u32(base, 0x570D68u, ctx.xmm[0].u32[0]);
	// 0x2AA748: ret
	return;
}

void sub_2AA750(X86Context& ctx, uint8_t* base) {
	// 0x2AA750: movss xmm0, dword ptr [0x00570D1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D1Cu);
	// 0x2AA758: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AA760: movss [0x00570D78], xmm0
	X86_MEM_WRITE_u32(base, 0x570D78u, ctx.xmm[0].u32[0]);
	// 0x2AA768: ret
	return;
}

void sub_2AA770(X86Context& ctx, uint8_t* base) {
	// 0x2AA770: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AA778: movss [0x00570D14], xmm0
	X86_MEM_WRITE_u32(base, 0x570D14u, ctx.xmm[0].u32[0]);
	// 0x2AA780: ret
	return;
}

void sub_2AA790(X86Context& ctx, uint8_t* base) {
	// 0x2AA790: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AA798: movss [0x00570D4C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D4Cu, ctx.xmm[0].u32[0]);
	// 0x2AA7A0: ret
	return;
}

void sub_2AA7B0(X86Context& ctx, uint8_t* base) {
	// 0x2AA7B0: movss xmm0, dword ptr [0x00570D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D48u);
	// 0x2AA7B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AA7C0: movss [0x00570D58], xmm0
	X86_MEM_WRITE_u32(base, 0x570D58u, ctx.xmm[0].u32[0]);
	// 0x2AA7C8: ret
	return;
}

void sub_2AA7D0(X86Context& ctx, uint8_t* base) {
	// 0x2AA7D0: movss xmm0, dword ptr [0x00570D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D9Cu);
	// 0x2AA7D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AA7E0: movss [0x00570DA0], xmm0
	X86_MEM_WRITE_u32(base, 0x570DA0u, ctx.xmm[0].u32[0]);
	// 0x2AA7E8: ret
	return;
}

void sub_2AA7F0(X86Context& ctx, uint8_t* base) {
	// 0x2AA7F0: movss xmm0, dword ptr [0x00570D58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D58u);
	// 0x2AA7F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA800: movss [0x00570D8C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D8Cu, ctx.xmm[0].u32[0]);
	// 0x2AA808: ret
	return;
}

void sub_2AA810(X86Context& ctx, uint8_t* base) {
	// 0x2AA810: movss xmm0, dword ptr [0x00570DA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570DA0u);
	// 0x2AA818: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA820: movss [0x00570DB0], xmm0
	X86_MEM_WRITE_u32(base, 0x570DB0u, ctx.xmm[0].u32[0]);
	// 0x2AA828: ret
	return;
}

void sub_2AA830(X86Context& ctx, uint8_t* base) {
	// 0x2AA830: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AA838: movss [0x00570D20], xmm0
	X86_MEM_WRITE_u32(base, 0x570D20u, ctx.xmm[0].u32[0]);
	// 0x2AA840: ret
	return;
}

void sub_2AA850(X86Context& ctx, uint8_t* base) {
	// 0x2AA850: movss xmm0, dword ptr [0x00570D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D48u);
	// 0x2AA858: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA860: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AA868: movss [0x00570D98], xmm0
	X86_MEM_WRITE_u32(base, 0x570D98u, ctx.xmm[0].u32[0]);
	// 0x2AA870: ret
	return;
}

void sub_2AA880(X86Context& ctx, uint8_t* base) {
	// 0x2AA880: movss xmm0, dword ptr [0x00570D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D9Cu);
	// 0x2AA888: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA890: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AA898: movss [0x00570D38], xmm0
	X86_MEM_WRITE_u32(base, 0x570D38u, ctx.xmm[0].u32[0]);
	// 0x2AA8A0: ret
	return;
}

void sub_2AA8B0(X86Context& ctx, uint8_t* base) {
	// 0x2AA8B0: movss xmm0, dword ptr [0x00570D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D48u);
	// 0x2AA8B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA8C0: movss [0x00570D3C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D3Cu, ctx.xmm[0].u32[0]);
	// 0x2AA8C8: ret
	return;
}

void sub_2AA8D0(X86Context& ctx, uint8_t* base) {
	// 0x2AA8D0: movss xmm0, dword ptr [0x00570D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D9Cu);
	// 0x2AA8D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AA8E0: movss [0x00570DA4], xmm0
	X86_MEM_WRITE_u32(base, 0x570DA4u, ctx.xmm[0].u32[0]);
	// 0x2AA8E8: ret
	return;
}

void sub_2AA8F0(X86Context& ctx, uint8_t* base) {
	// 0x2AA8F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AA8F8: movss [0x00570D24], xmm0
	X86_MEM_WRITE_u32(base, 0x570D24u, ctx.xmm[0].u32[0]);
	// 0x2AA900: ret
	return;
}

void sub_2AA910(X86Context& ctx, uint8_t* base) {
	// 0x2AA910: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AA918: movss [0x00570D54], xmm0
	X86_MEM_WRITE_u32(base, 0x570D54u, ctx.xmm[0].u32[0]);
	// 0x2AA920: ret
	return;
}

void sub_2AA930(X86Context& ctx, uint8_t* base) {
	// 0x2AA930: movss xmm0, dword ptr [0x00570D24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D24u);
	// 0x2AA938: movss [0x00570DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x570DB8u, ctx.xmm[0].u32[0]);
	// 0x2AA940: ret
	return;
}

void sub_2AA950(X86Context& ctx, uint8_t* base) {
	// 0x2AA950: movss xmm0, dword ptr [0x00570D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570D9Cu);
	// 0x2AA958: subss xmm0, [0x00570D24]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570D24u);
	// 0x2AA960: movss [0x00570D7C], xmm0
	X86_MEM_WRITE_u32(base, 0x570D7Cu, ctx.xmm[0].u32[0]);
	// 0x2AA968: ret
	return;
}

