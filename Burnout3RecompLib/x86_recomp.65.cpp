#include "x86_recomp_shared.h"

void sub_2A46A0(X86Context& ctx, uint8_t* base) {
	// 0x2A46A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A46A8: movss [0x0057015C], xmm0
	X86_MEM_WRITE_u32(base, 0x57015Cu, ctx.xmm[0].u32[0]);
	// 0x2A46B0: ret
	return;
}

void sub_2A46C0(X86Context& ctx, uint8_t* base) {
	// 0x2A46C0: movss xmm0, dword ptr [0x00570170]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570170u);
	// 0x2A46C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A46D0: movss [0x005701A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5701A0u, ctx.xmm[0].u32[0]);
	// 0x2A46D8: ret
	return;
}

void sub_2A46E0(X86Context& ctx, uint8_t* base) {
	// 0x2A46E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A46E8: movss [0x0057022C], xmm0
	X86_MEM_WRITE_u32(base, 0x57022Cu, ctx.xmm[0].u32[0]);
	// 0x2A46F0: ret
	return;
}

void sub_2A4700(X86Context& ctx, uint8_t* base) {
	// 0x2A4700: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A4708: movss [0x00570248], xmm0
	X86_MEM_WRITE_u32(base, 0x570248u, ctx.xmm[0].u32[0]);
	// 0x2A4710: ret
	return;
}

void sub_2A4720(X86Context& ctx, uint8_t* base) {
	// 0x2A4720: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A4728: movss [0x00570220], xmm0
	X86_MEM_WRITE_u32(base, 0x570220u, ctx.xmm[0].u32[0]);
	// 0x2A4730: ret
	return;
}

void sub_2A4740(X86Context& ctx, uint8_t* base) {
	// 0x2A4740: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A4748: movss [0x005701D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5701D0u, ctx.xmm[0].u32[0]);
	// 0x2A4750: ret
	return;
}

void sub_2A4760(X86Context& ctx, uint8_t* base) {
	// 0x2A4760: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A4768: movss [0x00570230], xmm0
	X86_MEM_WRITE_u32(base, 0x570230u, ctx.xmm[0].u32[0]);
	// 0x2A4770: ret
	return;
}

void sub_2A4780(X86Context& ctx, uint8_t* base) {
	// 0x2A4780: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A4788: movss [0x005701EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5701ECu, ctx.xmm[0].u32[0]);
	// 0x2A4790: ret
	return;
}

void sub_2A47A0(X86Context& ctx, uint8_t* base) {
	// 0x2A47A0: movss xmm0, dword ptr [0x00570230]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570230u);
	// 0x2A47A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A47B0: movss [0x00570268], xmm0
	X86_MEM_WRITE_u32(base, 0x570268u, ctx.xmm[0].u32[0]);
	// 0x2A47B8: ret
	return;
}

void sub_2A47C0(X86Context& ctx, uint8_t* base) {
	// 0x2A47C0: movss xmm0, dword ptr [0x005701EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701ECu);
	// 0x2A47C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A47D0: movss [0x00570250], xmm0
	X86_MEM_WRITE_u32(base, 0x570250u, ctx.xmm[0].u32[0]);
	// 0x2A47D8: ret
	return;
}

void sub_2A47E0(X86Context& ctx, uint8_t* base) {
	// 0x2A47E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A47E8: movss [0x00570280], xmm0
	X86_MEM_WRITE_u32(base, 0x570280u, ctx.xmm[0].u32[0]);
	// 0x2A47F0: ret
	return;
}

void sub_2A4800(X86Context& ctx, uint8_t* base) {
	// 0x2A4800: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A4808: movss [0x0057026C], xmm0
	X86_MEM_WRITE_u32(base, 0x57026Cu, ctx.xmm[0].u32[0]);
	// 0x2A4810: ret
	return;
}

void sub_2A4820(X86Context& ctx, uint8_t* base) {
	// 0x2A4820: movss xmm0, dword ptr [0x0057026C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57026Cu);
	// 0x2A4828: movss [0x0057027C], xmm0
	X86_MEM_WRITE_u32(base, 0x57027Cu, ctx.xmm[0].u32[0]);
	// 0x2A4830: ret
	return;
}

void sub_2A4840(X86Context& ctx, uint8_t* base) {
	// 0x2A4840: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A4848: movss [0x005701D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5701D8u, ctx.xmm[0].u32[0]);
	// 0x2A4850: ret
	return;
}

void sub_2A4860(X86Context& ctx, uint8_t* base) {
	// 0x2A4860: movss xmm0, dword ptr [0x005701EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701ECu);
	// 0x2A4868: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A4870: movss [0x00570274], xmm0
	X86_MEM_WRITE_u32(base, 0x570274u, ctx.xmm[0].u32[0]);
	// 0x2A4878: ret
	return;
}

void sub_2A4880(X86Context& ctx, uint8_t* base) {
	// 0x2A4880: movss xmm0, dword ptr [0x005701EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701ECu);
	// 0x2A4888: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A4890: movss [0x0057021C], xmm0
	X86_MEM_WRITE_u32(base, 0x57021Cu, ctx.xmm[0].u32[0]);
	// 0x2A4898: ret
	return;
}

void sub_2A48A0(X86Context& ctx, uint8_t* base) {
	// 0x2A48A0: movss xmm0, dword ptr [0x005701EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701ECu);
	// 0x2A48A8: subss xmm0, [0x0057021C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57021Cu);
	// 0x2A48B0: movss [0x005701F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5701F8u, ctx.xmm[0].u32[0]);
	// 0x2A48B8: ret
	return;
}

void sub_2A48C0(X86Context& ctx, uint8_t* base) {
	// 0x2A48C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A48C8: movss [0x00570244], xmm0
	X86_MEM_WRITE_u32(base, 0x570244u, ctx.xmm[0].u32[0]);
	// 0x2A48D0: ret
	return;
}

void sub_2A48E0(X86Context& ctx, uint8_t* base) {
	// 0x2A48E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A48E8: movss [0x005701F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5701F4u, ctx.xmm[0].u32[0]);
	// 0x2A48F0: ret
	return;
}

void sub_2A4900(X86Context& ctx, uint8_t* base) {
	// 0x2A4900: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A4908: movss [0x00570208], xmm0
	X86_MEM_WRITE_u32(base, 0x570208u, ctx.xmm[0].u32[0]);
	// 0x2A4910: ret
	return;
}

void sub_2A4920(X86Context& ctx, uint8_t* base) {
	// 0x2A4920: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A4928: movss [0x0057025C], xmm0
	X86_MEM_WRITE_u32(base, 0x57025Cu, ctx.xmm[0].u32[0]);
	// 0x2A4930: ret
	return;
}

void sub_2A4940(X86Context& ctx, uint8_t* base) {
	// 0x2A4940: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A4948: movss [0x00570240], xmm0
	X86_MEM_WRITE_u32(base, 0x570240u, ctx.xmm[0].u32[0]);
	// 0x2A4950: ret
	return;
}

void sub_2A4960(X86Context& ctx, uint8_t* base) {
	// 0x2A4960: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A4968: movss [0x005701E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5701E8u, ctx.xmm[0].u32[0]);
	// 0x2A4970: ret
	return;
}

void sub_2A4980(X86Context& ctx, uint8_t* base) {
	// 0x2A4980: movss xmm0, dword ptr [0x00570208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570208u);
	// 0x2A4988: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A4990: movss [0x005701DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5701DCu, ctx.xmm[0].u32[0]);
	// 0x2A4998: ret
	return;
}

void sub_2A49A0(X86Context& ctx, uint8_t* base) {
	// 0x2A49A0: movss xmm0, dword ptr [0x0057025C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57025Cu);
	// 0x2A49A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A49B0: movss [0x00570228], xmm0
	X86_MEM_WRITE_u32(base, 0x570228u, ctx.xmm[0].u32[0]);
	// 0x2A49B8: ret
	return;
}

void sub_2A49C0(X86Context& ctx, uint8_t* base) {
	// 0x2A49C0: movss xmm0, dword ptr [0x005701DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701DCu);
	// 0x2A49C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A49D0: movss [0x00570238], xmm0
	X86_MEM_WRITE_u32(base, 0x570238u, ctx.xmm[0].u32[0]);
	// 0x2A49D8: ret
	return;
}

void sub_2A49E0(X86Context& ctx, uint8_t* base) {
	// 0x2A49E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A49E8: movss [0x005701D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5701D4u, ctx.xmm[0].u32[0]);
	// 0x2A49F0: ret
	return;
}

void sub_2A4A00(X86Context& ctx, uint8_t* base) {
	// 0x2A4A00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A4A08: movss [0x0057020C], xmm0
	X86_MEM_WRITE_u32(base, 0x57020Cu, ctx.xmm[0].u32[0]);
	// 0x2A4A10: ret
	return;
}

void sub_2A4A20(X86Context& ctx, uint8_t* base) {
	// 0x2A4A20: movss xmm0, dword ptr [0x00570208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570208u);
	// 0x2A4A28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A4A30: movss [0x00570218], xmm0
	X86_MEM_WRITE_u32(base, 0x570218u, ctx.xmm[0].u32[0]);
	// 0x2A4A38: ret
	return;
}

void sub_2A4A40(X86Context& ctx, uint8_t* base) {
	// 0x2A4A40: movss xmm0, dword ptr [0x0057025C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57025Cu);
	// 0x2A4A48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A4A50: movss [0x00570260], xmm0
	X86_MEM_WRITE_u32(base, 0x570260u, ctx.xmm[0].u32[0]);
	// 0x2A4A58: ret
	return;
}

void sub_2A4A60(X86Context& ctx, uint8_t* base) {
	// 0x2A4A60: movss xmm0, dword ptr [0x00570218]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570218u);
	// 0x2A4A68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4A70: movss [0x0057024C], xmm0
	X86_MEM_WRITE_u32(base, 0x57024Cu, ctx.xmm[0].u32[0]);
	// 0x2A4A78: ret
	return;
}

void sub_2A4A80(X86Context& ctx, uint8_t* base) {
	// 0x2A4A80: movss xmm0, dword ptr [0x00570260]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570260u);
	// 0x2A4A88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4A90: movss [0x00570270], xmm0
	X86_MEM_WRITE_u32(base, 0x570270u, ctx.xmm[0].u32[0]);
	// 0x2A4A98: ret
	return;
}

void sub_2A4AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A4AA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A4AA8: movss [0x005701E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5701E0u, ctx.xmm[0].u32[0]);
	// 0x2A4AB0: ret
	return;
}

void sub_2A4AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A4AC0: movss xmm0, dword ptr [0x00570208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570208u);
	// 0x2A4AC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4AD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A4AD8: movss [0x00570258], xmm0
	X86_MEM_WRITE_u32(base, 0x570258u, ctx.xmm[0].u32[0]);
	// 0x2A4AE0: ret
	return;
}

void sub_2A4AF0(X86Context& ctx, uint8_t* base) {
	// 0x2A4AF0: movss xmm0, dword ptr [0x0057025C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57025Cu);
	// 0x2A4AF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4B00: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A4B08: movss [0x00570200], xmm0
	X86_MEM_WRITE_u32(base, 0x570200u, ctx.xmm[0].u32[0]);
	// 0x2A4B10: ret
	return;
}

void sub_2A4B20(X86Context& ctx, uint8_t* base) {
	// 0x2A4B20: movss xmm0, dword ptr [0x00570208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570208u);
	// 0x2A4B28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4B30: movss [0x00570204], xmm0
	X86_MEM_WRITE_u32(base, 0x570204u, ctx.xmm[0].u32[0]);
	// 0x2A4B38: ret
	return;
}

void sub_2A4B40(X86Context& ctx, uint8_t* base) {
	// 0x2A4B40: movss xmm0, dword ptr [0x0057025C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57025Cu);
	// 0x2A4B48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A4B50: movss [0x00570264], xmm0
	X86_MEM_WRITE_u32(base, 0x570264u, ctx.xmm[0].u32[0]);
	// 0x2A4B58: ret
	return;
}

void sub_2A4B60(X86Context& ctx, uint8_t* base) {
	// 0x2A4B60: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A4B68: movss [0x005701E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5701E4u, ctx.xmm[0].u32[0]);
	// 0x2A4B70: ret
	return;
}

void sub_2A4B80(X86Context& ctx, uint8_t* base) {
	// 0x2A4B80: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A4B88: movss [0x00570214], xmm0
	X86_MEM_WRITE_u32(base, 0x570214u, ctx.xmm[0].u32[0]);
	// 0x2A4B90: ret
	return;
}

void sub_2A4BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A4BA0: movss xmm0, dword ptr [0x005701E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701E4u);
	// 0x2A4BA8: movss [0x00570278], xmm0
	X86_MEM_WRITE_u32(base, 0x570278u, ctx.xmm[0].u32[0]);
	// 0x2A4BB0: ret
	return;
}

void sub_2A4BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A4BC0: movss xmm0, dword ptr [0x0057025C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57025Cu);
	// 0x2A4BC8: subss xmm0, [0x005701E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5701E4u);
	// 0x2A4BD0: movss [0x0057023C], xmm0
	X86_MEM_WRITE_u32(base, 0x57023Cu, ctx.xmm[0].u32[0]);
	// 0x2A4BD8: ret
	return;
}

void sub_2A4BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A4BE0: movss xmm0, dword ptr [0x0057023C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57023Cu);
	// 0x2A4BE8: subss xmm0, [0x00570214]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570214u);
	// 0x2A4BF0: movss [0x00570234], xmm0
	X86_MEM_WRITE_u32(base, 0x570234u, ctx.xmm[0].u32[0]);
	// 0x2A4BF8: ret
	return;
}

void sub_2A4C00(X86Context& ctx, uint8_t* base) {
	// 0x2A4C00: movss xmm0, dword ptr [0x00570264]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570264u);
	// 0x2A4C08: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A4C10: movss [0x00570224], xmm0
	X86_MEM_WRITE_u32(base, 0x570224u, ctx.xmm[0].u32[0]);
	// 0x2A4C18: ret
	return;
}

void sub_2A4C20(X86Context& ctx, uint8_t* base) {
	// 0x2A4C20: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A4C28: movss [0x00570210], xmm0
	X86_MEM_WRITE_u32(base, 0x570210u, ctx.xmm[0].u32[0]);
	// 0x2A4C30: ret
	return;
}

void sub_2A4C40(X86Context& ctx, uint8_t* base) {
	// 0x2A4C40: movss xmm0, dword ptr [0x00570224]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570224u);
	// 0x2A4C48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A4C50: movss [0x00570254], xmm0
	X86_MEM_WRITE_u32(base, 0x570254u, ctx.xmm[0].u32[0]);
	// 0x2A4C58: ret
	return;
}

void sub_2A4C60(X86Context& ctx, uint8_t* base) {
	// 0x2A4C60: movss xmm0, dword ptr [0x00570208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570208u);
	// 0x2A4C68: movss [0x00406CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x406CA0u, ctx.xmm[0].u32[0]);
	// 0x2A4C70: ret
	return;
}

void sub_2A4C80(X86Context& ctx, uint8_t* base) {
	// 0x2A4C80: movss xmm0, dword ptr [0x003B17E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x2A4C88: movss [0x005701F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5701F0u, ctx.xmm[0].u32[0]);
	// 0x2A4C90: ret
	return;
}

void sub_2A4CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A4CA0: movss xmm0, dword ptr [0x005701F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701F0u);
	// 0x2A4CA8: addss xmm0, [0x003B1C3C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1C3Cu);
	// 0x2A4CB0: movss [0x00406CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x406CA8u, ctx.xmm[0].u32[0]);
	// 0x2A4CB8: ret
	return;
}

void sub_2A4CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A4CC0: movss xmm0, dword ptr [0x00570208]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570208u);
	// 0x2A4CC8: movss [0x00406CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x406CC0u, ctx.xmm[0].u32[0]);
	// 0x2A4CD0: ret
	return;
}

void sub_2A4CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A4CE0: movss xmm0, dword ptr [0x003B17E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x2A4CE8: movss [0x005701FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5701FCu, ctx.xmm[0].u32[0]);
	// 0x2A4CF0: ret
	return;
}

void sub_2A4D00(X86Context& ctx, uint8_t* base) {
	// 0x2A4D00: movss xmm0, dword ptr [0x005701FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5701FCu);
	// 0x2A4D08: addss xmm0, [0x003B1C3C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1C3Cu);
	// 0x2A4D10: movss [0x00406CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x406CC8u, ctx.xmm[0].u32[0]);
	// 0x2A4D18: ret
	return;
}

void sub_2A4D20(X86Context& ctx, uint8_t* base) {
	// 0x2A4D20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A4D28: movss [0x005702DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5702DCu, ctx.xmm[0].u32[0]);
	// 0x2A4D30: ret
	return;
}

void sub_2A4D40(X86Context& ctx, uint8_t* base) {
	// 0x2A4D40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A4D48: movss [0x005702F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5702F8u, ctx.xmm[0].u32[0]);
	// 0x2A4D50: ret
	return;
}

void sub_2A4D60(X86Context& ctx, uint8_t* base) {
	// 0x2A4D60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A4D68: movss [0x005702CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5702CCu, ctx.xmm[0].u32[0]);
	// 0x2A4D70: ret
	return;
}

void sub_2A4D80(X86Context& ctx, uint8_t* base) {
	// 0x2A4D80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A4D88: movss [0x00570284], xmm0
	X86_MEM_WRITE_u32(base, 0x570284u, ctx.xmm[0].u32[0]);
	// 0x2A4D90: ret
	return;
}

void sub_2A4DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A4DA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A4DA8: movss [0x005702E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5702E0u, ctx.xmm[0].u32[0]);
	// 0x2A4DB0: ret
	return;
}

void sub_2A4DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A4DC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A4DC8: movss [0x005702A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5702A0u, ctx.xmm[0].u32[0]);
	// 0x2A4DD0: ret
	return;
}

void sub_2A4DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A4DE0: movss xmm0, dword ptr [0x005702E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702E0u);
	// 0x2A4DE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A4DF0: movss [0x00570318], xmm0
	X86_MEM_WRITE_u32(base, 0x570318u, ctx.xmm[0].u32[0]);
	// 0x2A4DF8: ret
	return;
}

void sub_2A4E00(X86Context& ctx, uint8_t* base) {
	// 0x2A4E00: movss xmm0, dword ptr [0x005702A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702A0u);
	// 0x2A4E08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A4E10: movss [0x00570300], xmm0
	X86_MEM_WRITE_u32(base, 0x570300u, ctx.xmm[0].u32[0]);
	// 0x2A4E18: ret
	return;
}

void sub_2A4E20(X86Context& ctx, uint8_t* base) {
	// 0x2A4E20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A4E28: movss [0x00570330], xmm0
	X86_MEM_WRITE_u32(base, 0x570330u, ctx.xmm[0].u32[0]);
	// 0x2A4E30: ret
	return;
}

void sub_2A4E40(X86Context& ctx, uint8_t* base) {
	// 0x2A4E40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A4E48: movss [0x0057031C], xmm0
	X86_MEM_WRITE_u32(base, 0x57031Cu, ctx.xmm[0].u32[0]);
	// 0x2A4E50: ret
	return;
}

void sub_2A4E60(X86Context& ctx, uint8_t* base) {
	// 0x2A4E60: movss xmm0, dword ptr [0x0057031C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57031Cu);
	// 0x2A4E68: movss [0x0057032C], xmm0
	X86_MEM_WRITE_u32(base, 0x57032Cu, ctx.xmm[0].u32[0]);
	// 0x2A4E70: ret
	return;
}

void sub_2A4E80(X86Context& ctx, uint8_t* base) {
	// 0x2A4E80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A4E88: movss [0x0057028C], xmm0
	X86_MEM_WRITE_u32(base, 0x57028Cu, ctx.xmm[0].u32[0]);
	// 0x2A4E90: ret
	return;
}

void sub_2A4EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A4EA0: movss xmm0, dword ptr [0x005702A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702A0u);
	// 0x2A4EA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A4EB0: movss [0x00570324], xmm0
	X86_MEM_WRITE_u32(base, 0x570324u, ctx.xmm[0].u32[0]);
	// 0x2A4EB8: ret
	return;
}

void sub_2A4EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A4EC0: movss xmm0, dword ptr [0x005702A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702A0u);
	// 0x2A4EC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A4ED0: movss [0x005702C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5702C8u, ctx.xmm[0].u32[0]);
	// 0x2A4ED8: ret
	return;
}

void sub_2A4EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A4EE0: movss xmm0, dword ptr [0x005702A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702A0u);
	// 0x2A4EE8: subss xmm0, [0x005702C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5702C8u);
	// 0x2A4EF0: movss [0x005702A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5702A8u, ctx.xmm[0].u32[0]);
	// 0x2A4EF8: ret
	return;
}

void sub_2A4F00(X86Context& ctx, uint8_t* base) {
	// 0x2A4F00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A4F08: movss [0x005702F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5702F4u, ctx.xmm[0].u32[0]);
	// 0x2A4F10: ret
	return;
}

void sub_2A4F20(X86Context& ctx, uint8_t* base) {
	// 0x2A4F20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A4F28: movss [0x005702A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5702A4u, ctx.xmm[0].u32[0]);
	// 0x2A4F30: ret
	return;
}

void sub_2A4F40(X86Context& ctx, uint8_t* base) {
	// 0x2A4F40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A4F48: movss [0x005702B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5702B4u, ctx.xmm[0].u32[0]);
	// 0x2A4F50: ret
	return;
}

void sub_2A4F60(X86Context& ctx, uint8_t* base) {
	// 0x2A4F60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A4F68: movss [0x0057030C], xmm0
	X86_MEM_WRITE_u32(base, 0x57030Cu, ctx.xmm[0].u32[0]);
	// 0x2A4F70: ret
	return;
}

void sub_2A4F80(X86Context& ctx, uint8_t* base) {
	// 0x2A4F80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A4F88: movss [0x005702F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5702F0u, ctx.xmm[0].u32[0]);
	// 0x2A4F90: ret
	return;
}

void sub_2A4FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A4FA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A4FA8: movss [0x0057029C], xmm0
	X86_MEM_WRITE_u32(base, 0x57029Cu, ctx.xmm[0].u32[0]);
	// 0x2A4FB0: ret
	return;
}

void sub_2A4FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A4FC0: movss xmm0, dword ptr [0x005702B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702B4u);
	// 0x2A4FC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A4FD0: movss [0x00570290], xmm0
	X86_MEM_WRITE_u32(base, 0x570290u, ctx.xmm[0].u32[0]);
	// 0x2A4FD8: ret
	return;
}

void sub_2A4FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A4FE0: movss xmm0, dword ptr [0x0057030C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57030Cu);
	// 0x2A4FE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A4FF0: movss [0x005702D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5702D8u, ctx.xmm[0].u32[0]);
	// 0x2A4FF8: ret
	return;
}

void sub_2A5000(X86Context& ctx, uint8_t* base) {
	// 0x2A5000: movss xmm0, dword ptr [0x00570290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570290u);
	// 0x2A5008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5010: movss [0x005702E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5702E8u, ctx.xmm[0].u32[0]);
	// 0x2A5018: ret
	return;
}

void sub_2A5020(X86Context& ctx, uint8_t* base) {
	// 0x2A5020: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A5028: movss [0x00570288], xmm0
	X86_MEM_WRITE_u32(base, 0x570288u, ctx.xmm[0].u32[0]);
	// 0x2A5030: ret
	return;
}

void sub_2A5040(X86Context& ctx, uint8_t* base) {
	// 0x2A5040: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A5048: movss [0x005702B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5702B8u, ctx.xmm[0].u32[0]);
	// 0x2A5050: ret
	return;
}

void sub_2A5060(X86Context& ctx, uint8_t* base) {
	// 0x2A5060: movss xmm0, dword ptr [0x005702B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702B4u);
	// 0x2A5068: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A5070: movss [0x005702C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5702C4u, ctx.xmm[0].u32[0]);
	// 0x2A5078: ret
	return;
}

void sub_2A5080(X86Context& ctx, uint8_t* base) {
	// 0x2A5080: movss xmm0, dword ptr [0x0057030C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57030Cu);
	// 0x2A5088: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A5090: movss [0x00570310], xmm0
	X86_MEM_WRITE_u32(base, 0x570310u, ctx.xmm[0].u32[0]);
	// 0x2A5098: ret
	return;
}

void sub_2A50A0(X86Context& ctx, uint8_t* base) {
	// 0x2A50A0: movss xmm0, dword ptr [0x005702C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702C4u);
	// 0x2A50A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A50B0: movss [0x005702FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5702FCu, ctx.xmm[0].u32[0]);
	// 0x2A50B8: ret
	return;
}

void sub_2A50C0(X86Context& ctx, uint8_t* base) {
	// 0x2A50C0: movss xmm0, dword ptr [0x00570310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570310u);
	// 0x2A50C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A50D0: movss [0x00570320], xmm0
	X86_MEM_WRITE_u32(base, 0x570320u, ctx.xmm[0].u32[0]);
	// 0x2A50D8: ret
	return;
}

void sub_2A50E0(X86Context& ctx, uint8_t* base) {
	// 0x2A50E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A50E8: movss [0x00570294], xmm0
	X86_MEM_WRITE_u32(base, 0x570294u, ctx.xmm[0].u32[0]);
	// 0x2A50F0: ret
	return;
}

void sub_2A5100(X86Context& ctx, uint8_t* base) {
	// 0x2A5100: movss xmm0, dword ptr [0x005702B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702B4u);
	// 0x2A5108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5110: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A5118: movss [0x00570308], xmm0
	X86_MEM_WRITE_u32(base, 0x570308u, ctx.xmm[0].u32[0]);
	// 0x2A5120: ret
	return;
}

void sub_2A5130(X86Context& ctx, uint8_t* base) {
	// 0x2A5130: movss xmm0, dword ptr [0x0057030C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57030Cu);
	// 0x2A5138: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5140: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A5148: movss [0x005702AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5702ACu, ctx.xmm[0].u32[0]);
	// 0x2A5150: ret
	return;
}

void sub_2A5160(X86Context& ctx, uint8_t* base) {
	// 0x2A5160: movss xmm0, dword ptr [0x005702B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702B4u);
	// 0x2A5168: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5170: movss [0x005702B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5702B0u, ctx.xmm[0].u32[0]);
	// 0x2A5178: ret
	return;
}

void sub_2A5180(X86Context& ctx, uint8_t* base) {
	// 0x2A5180: movss xmm0, dword ptr [0x0057030C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57030Cu);
	// 0x2A5188: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5190: movss [0x00570314], xmm0
	X86_MEM_WRITE_u32(base, 0x570314u, ctx.xmm[0].u32[0]);
	// 0x2A5198: ret
	return;
}

void sub_2A51A0(X86Context& ctx, uint8_t* base) {
	// 0x2A51A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A51A8: movss [0x00570298], xmm0
	X86_MEM_WRITE_u32(base, 0x570298u, ctx.xmm[0].u32[0]);
	// 0x2A51B0: ret
	return;
}

void sub_2A51C0(X86Context& ctx, uint8_t* base) {
	// 0x2A51C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A51C8: movss [0x005702C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5702C0u, ctx.xmm[0].u32[0]);
	// 0x2A51D0: ret
	return;
}

void sub_2A51E0(X86Context& ctx, uint8_t* base) {
	// 0x2A51E0: movss xmm0, dword ptr [0x00570298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570298u);
	// 0x2A51E8: movss [0x00570328], xmm0
	X86_MEM_WRITE_u32(base, 0x570328u, ctx.xmm[0].u32[0]);
	// 0x2A51F0: ret
	return;
}

void sub_2A5200(X86Context& ctx, uint8_t* base) {
	// 0x2A5200: movss xmm0, dword ptr [0x0057030C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57030Cu);
	// 0x2A5208: subss xmm0, [0x00570298]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570298u);
	// 0x2A5210: movss [0x005702EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5702ECu, ctx.xmm[0].u32[0]);
	// 0x2A5218: ret
	return;
}

void sub_2A5220(X86Context& ctx, uint8_t* base) {
	// 0x2A5220: movss xmm0, dword ptr [0x005702EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702ECu);
	// 0x2A5228: subss xmm0, [0x005702C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5702C0u);
	// 0x2A5230: movss [0x005702E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5702E4u, ctx.xmm[0].u32[0]);
	// 0x2A5238: ret
	return;
}

void sub_2A5240(X86Context& ctx, uint8_t* base) {
	// 0x2A5240: movss xmm0, dword ptr [0x00570314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570314u);
	// 0x2A5248: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A5250: movss [0x005702D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5702D0u, ctx.xmm[0].u32[0]);
	// 0x2A5258: ret
	return;
}

void sub_2A5260(X86Context& ctx, uint8_t* base) {
	// 0x2A5260: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A5268: movss [0x005702BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5702BCu, ctx.xmm[0].u32[0]);
	// 0x2A5270: ret
	return;
}

void sub_2A5280(X86Context& ctx, uint8_t* base) {
	// 0x2A5280: movss xmm0, dword ptr [0x005702D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5702D0u);
	// 0x2A5288: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A5290: movss [0x00570304], xmm0
	X86_MEM_WRITE_u32(base, 0x570304u, ctx.xmm[0].u32[0]);
	// 0x2A5298: ret
	return;
}

void sub_2A52A0(X86Context& ctx, uint8_t* base) {
	// 0x2A52A0: movss xmm0, dword ptr [0x003B1C5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C5Cu);
	// 0x2A52A8: movss [0x005702D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5702D4u, ctx.xmm[0].u32[0]);
	// 0x2A52B0: ret
	return;
}

void sub_2A52C0(X86Context& ctx, uint8_t* base) {
	// 0x2A52C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A52C8: movss [0x00570388], xmm0
	X86_MEM_WRITE_u32(base, 0x570388u, ctx.xmm[0].u32[0]);
	// 0x2A52D0: ret
	return;
}

void sub_2A52E0(X86Context& ctx, uint8_t* base) {
	// 0x2A52E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A52E8: movss [0x005703A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5703A4u, ctx.xmm[0].u32[0]);
	// 0x2A52F0: ret
	return;
}

void sub_2A5300(X86Context& ctx, uint8_t* base) {
	// 0x2A5300: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A5308: movss [0x0057037C], xmm0
	X86_MEM_WRITE_u32(base, 0x57037Cu, ctx.xmm[0].u32[0]);
	// 0x2A5310: ret
	return;
}

void sub_2A5320(X86Context& ctx, uint8_t* base) {
	// 0x2A5320: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A5328: movss [0x00570334], xmm0
	X86_MEM_WRITE_u32(base, 0x570334u, ctx.xmm[0].u32[0]);
	// 0x2A5330: ret
	return;
}

void sub_2A5340(X86Context& ctx, uint8_t* base) {
	// 0x2A5340: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A5348: movss [0x0057038C], xmm0
	X86_MEM_WRITE_u32(base, 0x57038Cu, ctx.xmm[0].u32[0]);
	// 0x2A5350: ret
	return;
}

void sub_2A5360(X86Context& ctx, uint8_t* base) {
	// 0x2A5360: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A5368: movss [0x00570350], xmm0
	X86_MEM_WRITE_u32(base, 0x570350u, ctx.xmm[0].u32[0]);
	// 0x2A5370: ret
	return;
}

void sub_2A5380(X86Context& ctx, uint8_t* base) {
	// 0x2A5380: movss xmm0, dword ptr [0x0057038C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57038Cu);
	// 0x2A5388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5390: movss [0x005703C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5703C4u, ctx.xmm[0].u32[0]);
	// 0x2A5398: ret
	return;
}

void sub_2A53A0(X86Context& ctx, uint8_t* base) {
	// 0x2A53A0: movss xmm0, dword ptr [0x00570350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570350u);
	// 0x2A53A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A53B0: movss [0x005703AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5703ACu, ctx.xmm[0].u32[0]);
	// 0x2A53B8: ret
	return;
}

void sub_2A53C0(X86Context& ctx, uint8_t* base) {
	// 0x2A53C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A53C8: movss [0x005703DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5703DCu, ctx.xmm[0].u32[0]);
	// 0x2A53D0: ret
	return;
}

void sub_2A53E0(X86Context& ctx, uint8_t* base) {
	// 0x2A53E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A53E8: movss [0x005703C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5703C8u, ctx.xmm[0].u32[0]);
	// 0x2A53F0: ret
	return;
}

void sub_2A5400(X86Context& ctx, uint8_t* base) {
	// 0x2A5400: movss xmm0, dword ptr [0x005703C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703C8u);
	// 0x2A5408: movss [0x005703D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5703D8u, ctx.xmm[0].u32[0]);
	// 0x2A5410: ret
	return;
}

void sub_2A5420(X86Context& ctx, uint8_t* base) {
	// 0x2A5420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A5428: movss [0x0057033C], xmm0
	X86_MEM_WRITE_u32(base, 0x57033Cu, ctx.xmm[0].u32[0]);
	// 0x2A5430: ret
	return;
}

void sub_2A5440(X86Context& ctx, uint8_t* base) {
	// 0x2A5440: movss xmm0, dword ptr [0x00570350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570350u);
	// 0x2A5448: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A5450: movss [0x005703D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5703D0u, ctx.xmm[0].u32[0]);
	// 0x2A5458: ret
	return;
}

void sub_2A5460(X86Context& ctx, uint8_t* base) {
	// 0x2A5460: movss xmm0, dword ptr [0x00570350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570350u);
	// 0x2A5468: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A5470: movss [0x00570378], xmm0
	X86_MEM_WRITE_u32(base, 0x570378u, ctx.xmm[0].u32[0]);
	// 0x2A5478: ret
	return;
}

void sub_2A5480(X86Context& ctx, uint8_t* base) {
	// 0x2A5480: movss xmm0, dword ptr [0x00570350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570350u);
	// 0x2A5488: subss xmm0, [0x00570378]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570378u);
	// 0x2A5490: movss [0x00570358], xmm0
	X86_MEM_WRITE_u32(base, 0x570358u, ctx.xmm[0].u32[0]);
	// 0x2A5498: ret
	return;
}

void sub_2A54A0(X86Context& ctx, uint8_t* base) {
	// 0x2A54A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A54A8: movss [0x005703A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5703A0u, ctx.xmm[0].u32[0]);
	// 0x2A54B0: ret
	return;
}

void sub_2A54C0(X86Context& ctx, uint8_t* base) {
	// 0x2A54C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A54C8: movss [0x00570354], xmm0
	X86_MEM_WRITE_u32(base, 0x570354u, ctx.xmm[0].u32[0]);
	// 0x2A54D0: ret
	return;
}

void sub_2A54E0(X86Context& ctx, uint8_t* base) {
	// 0x2A54E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A54E8: movss [0x00570364], xmm0
	X86_MEM_WRITE_u32(base, 0x570364u, ctx.xmm[0].u32[0]);
	// 0x2A54F0: ret
	return;
}

void sub_2A5500(X86Context& ctx, uint8_t* base) {
	// 0x2A5500: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A5508: movss [0x005703B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5703B8u, ctx.xmm[0].u32[0]);
	// 0x2A5510: ret
	return;
}

void sub_2A5520(X86Context& ctx, uint8_t* base) {
	// 0x2A5520: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A5528: movss [0x0057039C], xmm0
	X86_MEM_WRITE_u32(base, 0x57039Cu, ctx.xmm[0].u32[0]);
	// 0x2A5530: ret
	return;
}

void sub_2A5540(X86Context& ctx, uint8_t* base) {
	// 0x2A5540: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A5548: movss [0x0057034C], xmm0
	X86_MEM_WRITE_u32(base, 0x57034Cu, ctx.xmm[0].u32[0]);
	// 0x2A5550: ret
	return;
}

void sub_2A5560(X86Context& ctx, uint8_t* base) {
	// 0x2A5560: movss xmm0, dword ptr [0x00570364]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570364u);
	// 0x2A5568: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5570: movss [0x00570340], xmm0
	X86_MEM_WRITE_u32(base, 0x570340u, ctx.xmm[0].u32[0]);
	// 0x2A5578: ret
	return;
}

void sub_2A5580(X86Context& ctx, uint8_t* base) {
	// 0x2A5580: movss xmm0, dword ptr [0x005703B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703B8u);
	// 0x2A5588: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A5590: movss [0x00570384], xmm0
	X86_MEM_WRITE_u32(base, 0x570384u, ctx.xmm[0].u32[0]);
	// 0x2A5598: ret
	return;
}

void sub_2A55A0(X86Context& ctx, uint8_t* base) {
	// 0x2A55A0: movss xmm0, dword ptr [0x00570340]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570340u);
	// 0x2A55A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A55B0: movss [0x00570394], xmm0
	X86_MEM_WRITE_u32(base, 0x570394u, ctx.xmm[0].u32[0]);
	// 0x2A55B8: ret
	return;
}

void sub_2A55C0(X86Context& ctx, uint8_t* base) {
	// 0x2A55C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A55C8: movss [0x00570338], xmm0
	X86_MEM_WRITE_u32(base, 0x570338u, ctx.xmm[0].u32[0]);
	// 0x2A55D0: ret
	return;
}

void sub_2A55E0(X86Context& ctx, uint8_t* base) {
	// 0x2A55E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A55E8: movss [0x00570368], xmm0
	X86_MEM_WRITE_u32(base, 0x570368u, ctx.xmm[0].u32[0]);
	// 0x2A55F0: ret
	return;
}

void sub_2A5600(X86Context& ctx, uint8_t* base) {
	// 0x2A5600: movss xmm0, dword ptr [0x00570364]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570364u);
	// 0x2A5608: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A5610: movss [0x00570374], xmm0
	X86_MEM_WRITE_u32(base, 0x570374u, ctx.xmm[0].u32[0]);
	// 0x2A5618: ret
	return;
}

void sub_2A5620(X86Context& ctx, uint8_t* base) {
	// 0x2A5620: movss xmm0, dword ptr [0x005703B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703B8u);
	// 0x2A5628: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A5630: movss [0x005703BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5703BCu, ctx.xmm[0].u32[0]);
	// 0x2A5638: ret
	return;
}

void sub_2A5640(X86Context& ctx, uint8_t* base) {
	// 0x2A5640: movss xmm0, dword ptr [0x00570374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570374u);
	// 0x2A5648: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5650: movss [0x005703A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5703A8u, ctx.xmm[0].u32[0]);
	// 0x2A5658: ret
	return;
}

void sub_2A5660(X86Context& ctx, uint8_t* base) {
	// 0x2A5660: movss xmm0, dword ptr [0x005703BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703BCu);
	// 0x2A5668: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5670: movss [0x005703CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5703CCu, ctx.xmm[0].u32[0]);
	// 0x2A5678: ret
	return;
}

void sub_2A5680(X86Context& ctx, uint8_t* base) {
	// 0x2A5680: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A5688: movss [0x00570344], xmm0
	X86_MEM_WRITE_u32(base, 0x570344u, ctx.xmm[0].u32[0]);
	// 0x2A5690: ret
	return;
}

void sub_2A56A0(X86Context& ctx, uint8_t* base) {
	// 0x2A56A0: movss xmm0, dword ptr [0x00570364]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570364u);
	// 0x2A56A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A56B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A56B8: movss [0x005703B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5703B4u, ctx.xmm[0].u32[0]);
	// 0x2A56C0: ret
	return;
}

void sub_2A56D0(X86Context& ctx, uint8_t* base) {
	// 0x2A56D0: movss xmm0, dword ptr [0x005703B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703B8u);
	// 0x2A56D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A56E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A56E8: movss [0x0057035C], xmm0
	X86_MEM_WRITE_u32(base, 0x57035Cu, ctx.xmm[0].u32[0]);
	// 0x2A56F0: ret
	return;
}

void sub_2A5700(X86Context& ctx, uint8_t* base) {
	// 0x2A5700: movss xmm0, dword ptr [0x00570364]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570364u);
	// 0x2A5708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5710: movss [0x00570360], xmm0
	X86_MEM_WRITE_u32(base, 0x570360u, ctx.xmm[0].u32[0]);
	// 0x2A5718: ret
	return;
}

void sub_2A5720(X86Context& ctx, uint8_t* base) {
	// 0x2A5720: movss xmm0, dword ptr [0x005703B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703B8u);
	// 0x2A5728: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5730: movss [0x005703C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5703C0u, ctx.xmm[0].u32[0]);
	// 0x2A5738: ret
	return;
}

void sub_2A5740(X86Context& ctx, uint8_t* base) {
	// 0x2A5740: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A5748: movss [0x00570348], xmm0
	X86_MEM_WRITE_u32(base, 0x570348u, ctx.xmm[0].u32[0]);
	// 0x2A5750: ret
	return;
}

void sub_2A5760(X86Context& ctx, uint8_t* base) {
	// 0x2A5760: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A5768: movss [0x00570370], xmm0
	X86_MEM_WRITE_u32(base, 0x570370u, ctx.xmm[0].u32[0]);
	// 0x2A5770: ret
	return;
}

void sub_2A5780(X86Context& ctx, uint8_t* base) {
	// 0x2A5780: movss xmm0, dword ptr [0x00570348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570348u);
	// 0x2A5788: movss [0x005703D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5703D4u, ctx.xmm[0].u32[0]);
	// 0x2A5790: ret
	return;
}

void sub_2A57A0(X86Context& ctx, uint8_t* base) {
	// 0x2A57A0: movss xmm0, dword ptr [0x005703B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703B8u);
	// 0x2A57A8: subss xmm0, [0x00570348]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570348u);
	// 0x2A57B0: movss [0x00570398], xmm0
	X86_MEM_WRITE_u32(base, 0x570398u, ctx.xmm[0].u32[0]);
	// 0x2A57B8: ret
	return;
}

void sub_2A57C0(X86Context& ctx, uint8_t* base) {
	// 0x2A57C0: movss xmm0, dword ptr [0x00570398]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570398u);
	// 0x2A57C8: subss xmm0, [0x00570370]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570370u);
	// 0x2A57D0: movss [0x00570390], xmm0
	X86_MEM_WRITE_u32(base, 0x570390u, ctx.xmm[0].u32[0]);
	// 0x2A57D8: ret
	return;
}

void sub_2A57E0(X86Context& ctx, uint8_t* base) {
	// 0x2A57E0: movss xmm0, dword ptr [0x005703C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703C0u);
	// 0x2A57E8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A57F0: movss [0x00570380], xmm0
	X86_MEM_WRITE_u32(base, 0x570380u, ctx.xmm[0].u32[0]);
	// 0x2A57F8: ret
	return;
}

void sub_2A5800(X86Context& ctx, uint8_t* base) {
	// 0x2A5800: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A5808: movss [0x0057036C], xmm0
	X86_MEM_WRITE_u32(base, 0x57036Cu, ctx.xmm[0].u32[0]);
	// 0x2A5810: ret
	return;
}

void sub_2A5820(X86Context& ctx, uint8_t* base) {
	// 0x2A5820: movss xmm0, dword ptr [0x00570380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570380u);
	// 0x2A5828: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A5830: movss [0x005703B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5703B0u, ctx.xmm[0].u32[0]);
	// 0x2A5838: ret
	return;
}

void sub_2A5840(X86Context& ctx, uint8_t* base) {
	// 0x2A5840: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A5848: movss [0x0057043C], xmm0
	X86_MEM_WRITE_u32(base, 0x57043Cu, ctx.xmm[0].u32[0]);
	// 0x2A5850: ret
	return;
}

void sub_2A5860(X86Context& ctx, uint8_t* base) {
	// 0x2A5860: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A5868: movss [0x00570458], xmm0
	X86_MEM_WRITE_u32(base, 0x570458u, ctx.xmm[0].u32[0]);
	// 0x2A5870: ret
	return;
}

void sub_2A5880(X86Context& ctx, uint8_t* base) {
	// 0x2A5880: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A5888: movss [0x00570430], xmm0
	X86_MEM_WRITE_u32(base, 0x570430u, ctx.xmm[0].u32[0]);
	// 0x2A5890: ret
	return;
}

void sub_2A58A0(X86Context& ctx, uint8_t* base) {
	// 0x2A58A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A58A8: movss [0x005703E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5703E0u, ctx.xmm[0].u32[0]);
	// 0x2A58B0: ret
	return;
}

void sub_2A58C0(X86Context& ctx, uint8_t* base) {
	// 0x2A58C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A58C8: movss [0x00570440], xmm0
	X86_MEM_WRITE_u32(base, 0x570440u, ctx.xmm[0].u32[0]);
	// 0x2A58D0: ret
	return;
}

void sub_2A58E0(X86Context& ctx, uint8_t* base) {
	// 0x2A58E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A58E8: movss [0x005703FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5703FCu, ctx.xmm[0].u32[0]);
	// 0x2A58F0: ret
	return;
}

void sub_2A5900(X86Context& ctx, uint8_t* base) {
	// 0x2A5900: movss xmm0, dword ptr [0x00570440]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570440u);
	// 0x2A5908: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5910: movss [0x00570478], xmm0
	X86_MEM_WRITE_u32(base, 0x570478u, ctx.xmm[0].u32[0]);
	// 0x2A5918: ret
	return;
}

void sub_2A5920(X86Context& ctx, uint8_t* base) {
	// 0x2A5920: movss xmm0, dword ptr [0x005703FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703FCu);
	// 0x2A5928: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A5930: movss [0x00570460], xmm0
	X86_MEM_WRITE_u32(base, 0x570460u, ctx.xmm[0].u32[0]);
	// 0x2A5938: ret
	return;
}

void sub_2A5940(X86Context& ctx, uint8_t* base) {
	// 0x2A5940: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A5948: movss [0x00570490], xmm0
	X86_MEM_WRITE_u32(base, 0x570490u, ctx.xmm[0].u32[0]);
	// 0x2A5950: ret
	return;
}

void sub_2A5960(X86Context& ctx, uint8_t* base) {
	// 0x2A5960: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A5968: movss [0x0057047C], xmm0
	X86_MEM_WRITE_u32(base, 0x57047Cu, ctx.xmm[0].u32[0]);
	// 0x2A5970: ret
	return;
}

void sub_2A5980(X86Context& ctx, uint8_t* base) {
	// 0x2A5980: movss xmm0, dword ptr [0x0057047C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57047Cu);
	// 0x2A5988: movss [0x0057048C], xmm0
	X86_MEM_WRITE_u32(base, 0x57048Cu, ctx.xmm[0].u32[0]);
	// 0x2A5990: ret
	return;
}

void sub_2A59A0(X86Context& ctx, uint8_t* base) {
	// 0x2A59A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A59A8: movss [0x005703E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5703E8u, ctx.xmm[0].u32[0]);
	// 0x2A59B0: ret
	return;
}

void sub_2A59C0(X86Context& ctx, uint8_t* base) {
	// 0x2A59C0: movss xmm0, dword ptr [0x005703FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703FCu);
	// 0x2A59C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A59D0: movss [0x00570484], xmm0
	X86_MEM_WRITE_u32(base, 0x570484u, ctx.xmm[0].u32[0]);
	// 0x2A59D8: ret
	return;
}

void sub_2A59E0(X86Context& ctx, uint8_t* base) {
	// 0x2A59E0: movss xmm0, dword ptr [0x005703FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703FCu);
	// 0x2A59E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A59F0: movss [0x0057042C], xmm0
	X86_MEM_WRITE_u32(base, 0x57042Cu, ctx.xmm[0].u32[0]);
	// 0x2A59F8: ret
	return;
}

void sub_2A5A00(X86Context& ctx, uint8_t* base) {
	// 0x2A5A00: movss xmm0, dword ptr [0x005703FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703FCu);
	// 0x2A5A08: subss xmm0, [0x0057042C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57042Cu);
	// 0x2A5A10: movss [0x00570404], xmm0
	X86_MEM_WRITE_u32(base, 0x570404u, ctx.xmm[0].u32[0]);
	// 0x2A5A18: ret
	return;
}

void sub_2A5A20(X86Context& ctx, uint8_t* base) {
	// 0x2A5A20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A5A28: movss [0x00570454], xmm0
	X86_MEM_WRITE_u32(base, 0x570454u, ctx.xmm[0].u32[0]);
	// 0x2A5A30: ret
	return;
}

void sub_2A5A40(X86Context& ctx, uint8_t* base) {
	// 0x2A5A40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A5A48: movss [0x00570400], xmm0
	X86_MEM_WRITE_u32(base, 0x570400u, ctx.xmm[0].u32[0]);
	// 0x2A5A50: ret
	return;
}

void sub_2A5A60(X86Context& ctx, uint8_t* base) {
	// 0x2A5A60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A5A68: movss [0x00570418], xmm0
	X86_MEM_WRITE_u32(base, 0x570418u, ctx.xmm[0].u32[0]);
	// 0x2A5A70: ret
	return;
}

void sub_2A5A80(X86Context& ctx, uint8_t* base) {
	// 0x2A5A80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A5A88: movss [0x0057046C], xmm0
	X86_MEM_WRITE_u32(base, 0x57046Cu, ctx.xmm[0].u32[0]);
	// 0x2A5A90: ret
	return;
}

void sub_2A5AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A5AA0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A5AA8: movss [0x00570450], xmm0
	X86_MEM_WRITE_u32(base, 0x570450u, ctx.xmm[0].u32[0]);
	// 0x2A5AB0: ret
	return;
}

void sub_2A5AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A5AC0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A5AC8: movss [0x005703F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5703F8u, ctx.xmm[0].u32[0]);
	// 0x2A5AD0: ret
	return;
}

void sub_2A5AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A5AE0: movss xmm0, dword ptr [0x00570418]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570418u);
	// 0x2A5AE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5AF0: movss [0x005703EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5703ECu, ctx.xmm[0].u32[0]);
	// 0x2A5AF8: ret
	return;
}

void sub_2A5B00(X86Context& ctx, uint8_t* base) {
	// 0x2A5B00: movss xmm0, dword ptr [0x0057046C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57046Cu);
	// 0x2A5B08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A5B10: movss [0x00570438], xmm0
	X86_MEM_WRITE_u32(base, 0x570438u, ctx.xmm[0].u32[0]);
	// 0x2A5B18: ret
	return;
}

void sub_2A5B20(X86Context& ctx, uint8_t* base) {
	// 0x2A5B20: movss xmm0, dword ptr [0x005703EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703ECu);
	// 0x2A5B28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5B30: movss [0x00570448], xmm0
	X86_MEM_WRITE_u32(base, 0x570448u, ctx.xmm[0].u32[0]);
	// 0x2A5B38: ret
	return;
}

void sub_2A5B40(X86Context& ctx, uint8_t* base) {
	// 0x2A5B40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A5B48: movss [0x005703E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5703E4u, ctx.xmm[0].u32[0]);
	// 0x2A5B50: ret
	return;
}

void sub_2A5B60(X86Context& ctx, uint8_t* base) {
	// 0x2A5B60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A5B68: movss [0x0057041C], xmm0
	X86_MEM_WRITE_u32(base, 0x57041Cu, ctx.xmm[0].u32[0]);
	// 0x2A5B70: ret
	return;
}

void sub_2A5B80(X86Context& ctx, uint8_t* base) {
	// 0x2A5B80: movss xmm0, dword ptr [0x00570418]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570418u);
	// 0x2A5B88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A5B90: movss [0x00570428], xmm0
	X86_MEM_WRITE_u32(base, 0x570428u, ctx.xmm[0].u32[0]);
	// 0x2A5B98: ret
	return;
}

void sub_2A5BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A5BA0: movss xmm0, dword ptr [0x0057046C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57046Cu);
	// 0x2A5BA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A5BB0: movss [0x00570470], xmm0
	X86_MEM_WRITE_u32(base, 0x570470u, ctx.xmm[0].u32[0]);
	// 0x2A5BB8: ret
	return;
}

void sub_2A5BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A5BC0: movss xmm0, dword ptr [0x00570428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570428u);
	// 0x2A5BC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5BD0: movss [0x0057045C], xmm0
	X86_MEM_WRITE_u32(base, 0x57045Cu, ctx.xmm[0].u32[0]);
	// 0x2A5BD8: ret
	return;
}

void sub_2A5BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A5BE0: movss xmm0, dword ptr [0x00570470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570470u);
	// 0x2A5BE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5BF0: movss [0x00570480], xmm0
	X86_MEM_WRITE_u32(base, 0x570480u, ctx.xmm[0].u32[0]);
	// 0x2A5BF8: ret
	return;
}

void sub_2A5C00(X86Context& ctx, uint8_t* base) {
	// 0x2A5C00: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A5C08: movss [0x005703F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5703F0u, ctx.xmm[0].u32[0]);
	// 0x2A5C10: ret
	return;
}

void sub_2A5C20(X86Context& ctx, uint8_t* base) {
	// 0x2A5C20: movss xmm0, dword ptr [0x00570418]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570418u);
	// 0x2A5C28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5C30: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A5C38: movss [0x00570468], xmm0
	X86_MEM_WRITE_u32(base, 0x570468u, ctx.xmm[0].u32[0]);
	// 0x2A5C40: ret
	return;
}

void sub_2A5C50(X86Context& ctx, uint8_t* base) {
	// 0x2A5C50: movss xmm0, dword ptr [0x0057046C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57046Cu);
	// 0x2A5C58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5C60: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A5C68: movss [0x00570408], xmm0
	X86_MEM_WRITE_u32(base, 0x570408u, ctx.xmm[0].u32[0]);
	// 0x2A5C70: ret
	return;
}

void sub_2A5C80(X86Context& ctx, uint8_t* base) {
	// 0x2A5C80: movss xmm0, dword ptr [0x00570418]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570418u);
	// 0x2A5C88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5C90: movss [0x0057040C], xmm0
	X86_MEM_WRITE_u32(base, 0x57040Cu, ctx.xmm[0].u32[0]);
	// 0x2A5C98: ret
	return;
}

void sub_2A5CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A5CA0: movss xmm0, dword ptr [0x0057046C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57046Cu);
	// 0x2A5CA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A5CB0: movss [0x00570474], xmm0
	X86_MEM_WRITE_u32(base, 0x570474u, ctx.xmm[0].u32[0]);
	// 0x2A5CB8: ret
	return;
}

void sub_2A5CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A5CC0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A5CC8: movss [0x005703F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5703F4u, ctx.xmm[0].u32[0]);
	// 0x2A5CD0: ret
	return;
}

void sub_2A5CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A5CE0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A5CE8: movss [0x00570424], xmm0
	X86_MEM_WRITE_u32(base, 0x570424u, ctx.xmm[0].u32[0]);
	// 0x2A5CF0: ret
	return;
}

void sub_2A5D00(X86Context& ctx, uint8_t* base) {
	// 0x2A5D00: movss xmm0, dword ptr [0x005703F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5703F4u);
	// 0x2A5D08: movss [0x00570488], xmm0
	X86_MEM_WRITE_u32(base, 0x570488u, ctx.xmm[0].u32[0]);
	// 0x2A5D10: ret
	return;
}

void sub_2A5D20(X86Context& ctx, uint8_t* base) {
	// 0x2A5D20: movss xmm0, dword ptr [0x0057046C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57046Cu);
	// 0x2A5D28: subss xmm0, [0x005703F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5703F4u);
	// 0x2A5D30: movss [0x0057044C], xmm0
	X86_MEM_WRITE_u32(base, 0x57044Cu, ctx.xmm[0].u32[0]);
	// 0x2A5D38: ret
	return;
}

void sub_2A5D40(X86Context& ctx, uint8_t* base) {
	// 0x2A5D40: movss xmm0, dword ptr [0x0057044C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57044Cu);
	// 0x2A5D48: subss xmm0, [0x00570424]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570424u);
	// 0x2A5D50: movss [0x00570444], xmm0
	X86_MEM_WRITE_u32(base, 0x570444u, ctx.xmm[0].u32[0]);
	// 0x2A5D58: ret
	return;
}

void sub_2A5D60(X86Context& ctx, uint8_t* base) {
	// 0x2A5D60: movss xmm0, dword ptr [0x00570474]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570474u);
	// 0x2A5D68: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A5D70: movss [0x00570434], xmm0
	X86_MEM_WRITE_u32(base, 0x570434u, ctx.xmm[0].u32[0]);
	// 0x2A5D78: ret
	return;
}

void sub_2A5D80(X86Context& ctx, uint8_t* base) {
	// 0x2A5D80: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A5D88: movss [0x00570420], xmm0
	X86_MEM_WRITE_u32(base, 0x570420u, ctx.xmm[0].u32[0]);
	// 0x2A5D90: ret
	return;
}

void sub_2A5DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A5DA0: movss xmm0, dword ptr [0x00570434]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570434u);
	// 0x2A5DA8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A5DB0: movss [0x00570464], xmm0
	X86_MEM_WRITE_u32(base, 0x570464u, ctx.xmm[0].u32[0]);
	// 0x2A5DB8: ret
	return;
}

void sub_2A5DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A5DC0: movss xmm0, dword ptr [0x00570418]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570418u);
	// 0x2A5DC8: movss [0x00570410], xmm0
	X86_MEM_WRITE_u32(base, 0x570410u, ctx.xmm[0].u32[0]);
	// 0x2A5DD0: movss xmm0, dword ptr [0x0057046C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57046Cu);
	// 0x2A5DD8: subss xmm0, [0x0035BF1C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x35BF1Cu);
	// 0x2A5DE0: movss [0x00570414], xmm0
	X86_MEM_WRITE_u32(base, 0x570414u, ctx.xmm[0].u32[0]);
	// 0x2A5DE8: ret
	return;
}

void sub_2A5DF0(X86Context& ctx, uint8_t* base) {
	// 0x2A5DF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A5DF8: movss [0x00570508], xmm0
	X86_MEM_WRITE_u32(base, 0x570508u, ctx.xmm[0].u32[0]);
	// 0x2A5E00: ret
	return;
}

void sub_2A5E10(X86Context& ctx, uint8_t* base) {
	// 0x2A5E10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A5E18: movss [0x0057052C], xmm0
	X86_MEM_WRITE_u32(base, 0x57052Cu, ctx.xmm[0].u32[0]);
	// 0x2A5E20: ret
	return;
}

void sub_2A5E30(X86Context& ctx, uint8_t* base) {
	// 0x2A5E30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A5E38: movss [0x005704F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5704F8u, ctx.xmm[0].u32[0]);
	// 0x2A5E40: ret
	return;
}

void sub_2A5E50(X86Context& ctx, uint8_t* base) {
	// 0x2A5E50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A5E58: movss [0x00570494], xmm0
	X86_MEM_WRITE_u32(base, 0x570494u, ctx.xmm[0].u32[0]);
	// 0x2A5E60: ret
	return;
}

void sub_2A5E70(X86Context& ctx, uint8_t* base) {
	// 0x2A5E70: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A5E78: movss [0x0057050C], xmm0
	X86_MEM_WRITE_u32(base, 0x57050Cu, ctx.xmm[0].u32[0]);
	// 0x2A5E80: ret
	return;
}

void sub_2A5E90(X86Context& ctx, uint8_t* base) {
	// 0x2A5E90: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A5E98: movss [0x005704B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5704B0u, ctx.xmm[0].u32[0]);
	// 0x2A5EA0: ret
	return;
}

void sub_2A5EB0(X86Context& ctx, uint8_t* base) {
	// 0x2A5EB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A5EB8: movss [0x00570550], xmm0
	X86_MEM_WRITE_u32(base, 0x570550u, ctx.xmm[0].u32[0]);
	// 0x2A5EC0: ret
	return;
}

void sub_2A5ED0(X86Context& ctx, uint8_t* base) {
	// 0x2A5ED0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A5ED8: movss [0x00570500], xmm0
	X86_MEM_WRITE_u32(base, 0x570500u, ctx.xmm[0].u32[0]);
	// 0x2A5EE0: ret
	return;
}

void sub_2A5EF0(X86Context& ctx, uint8_t* base) {
	// 0x2A5EF0: movss xmm0, dword ptr [0x00570550]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570550u);
	// 0x2A5EF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A5F00: movss [0x005704C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5704C4u, ctx.xmm[0].u32[0]);
	// 0x2A5F08: ret
	return;
}

void sub_2A5F10(X86Context& ctx, uint8_t* base) {
	// 0x2A5F10: movss xmm0, dword ptr [0x00570500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570500u);
	// 0x2A5F18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A5F20: movss [0x0057053C], xmm0
	X86_MEM_WRITE_u32(base, 0x57053Cu, ctx.xmm[0].u32[0]);
	// 0x2A5F28: ret
	return;
}

void sub_2A5F30(X86Context& ctx, uint8_t* base) {
	// 0x2A5F30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A5F38: movss [0x00570564], xmm0
	X86_MEM_WRITE_u32(base, 0x570564u, ctx.xmm[0].u32[0]);
	// 0x2A5F40: ret
	return;
}

void sub_2A5F50(X86Context& ctx, uint8_t* base) {
	// 0x2A5F50: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A5F58: movss [0x00570554], xmm0
	X86_MEM_WRITE_u32(base, 0x570554u, ctx.xmm[0].u32[0]);
	// 0x2A5F60: ret
	return;
}

void sub_2A5F70(X86Context& ctx, uint8_t* base) {
	// 0x2A5F70: movss xmm0, dword ptr [0x00570554]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570554u);
	// 0x2A5F78: movss [0x00570560], xmm0
	X86_MEM_WRITE_u32(base, 0x570560u, ctx.xmm[0].u32[0]);
	// 0x2A5F80: ret
	return;
}

void sub_2A5F90(X86Context& ctx, uint8_t* base) {
	// 0x2A5F90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A5F98: movss [0x005704F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5704F4u, ctx.xmm[0].u32[0]);
	// 0x2A5FA0: ret
	return;
}

void sub_2A5FB0(X86Context& ctx, uint8_t* base) {
	// 0x2A5FB0: movss xmm0, dword ptr [0x00570500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570500u);
	// 0x2A5FB8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A5FC0: movss [0x005704D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5704D0u, ctx.xmm[0].u32[0]);
	// 0x2A5FC8: ret
	return;
}

void sub_2A5FD0(X86Context& ctx, uint8_t* base) {
	// 0x2A5FD0: movss xmm0, dword ptr [0x00570500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570500u);
	// 0x2A5FD8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A5FE0: movss [0x00570528], xmm0
	X86_MEM_WRITE_u32(base, 0x570528u, ctx.xmm[0].u32[0]);
	// 0x2A5FE8: ret
	return;
}

void sub_2A5FF0(X86Context& ctx, uint8_t* base) {
	// 0x2A5FF0: movss xmm0, dword ptr [0x00570500]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570500u);
	// 0x2A5FF8: subss xmm0, [0x00570528]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570528u);
	// 0x2A6000: movss [0x005704BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5704BCu, ctx.xmm[0].u32[0]);
	// 0x2A6008: ret
	return;
}

void sub_2A6010(X86Context& ctx, uint8_t* base) {
	// 0x2A6010: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A6018: movss [0x005704DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5704DCu, ctx.xmm[0].u32[0]);
	// 0x2A6020: ret
	return;
}

void sub_2A6030(X86Context& ctx, uint8_t* base) {
	// 0x2A6030: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A6038: movss [0x00570544], xmm0
	X86_MEM_WRITE_u32(base, 0x570544u, ctx.xmm[0].u32[0]);
	// 0x2A6040: ret
	return;
}

void sub_2A6050(X86Context& ctx, uint8_t* base) {
	// 0x2A6050: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A6058: movss [0x00570520], xmm0
	X86_MEM_WRITE_u32(base, 0x570520u, ctx.xmm[0].u32[0]);
	// 0x2A6060: ret
	return;
}

void sub_2A6070(X86Context& ctx, uint8_t* base) {
	// 0x2A6070: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A6078: movss [0x005704B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5704B4u, ctx.xmm[0].u32[0]);
	// 0x2A6080: ret
	return;
}

void sub_2A6090(X86Context& ctx, uint8_t* base) {
	// 0x2A6090: movss xmm0, dword ptr [0x005704DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704DCu);
	// 0x2A6098: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A60A0: movss [0x005704A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5704A4u, ctx.xmm[0].u32[0]);
	// 0x2A60A8: ret
	return;
}

void sub_2A60B0(X86Context& ctx, uint8_t* base) {
	// 0x2A60B0: movss xmm0, dword ptr [0x00570544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570544u);
	// 0x2A60B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A60C0: movss [0x00570504], xmm0
	X86_MEM_WRITE_u32(base, 0x570504u, ctx.xmm[0].u32[0]);
	// 0x2A60C8: ret
	return;
}

void sub_2A60D0(X86Context& ctx, uint8_t* base) {
	// 0x2A60D0: movss xmm0, dword ptr [0x005704A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704A4u);
	// 0x2A60D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A60E0: movss [0x00570518], xmm0
	X86_MEM_WRITE_u32(base, 0x570518u, ctx.xmm[0].u32[0]);
	// 0x2A60E8: ret
	return;
}

void sub_2A60F0(X86Context& ctx, uint8_t* base) {
	// 0x2A60F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A60F8: movss [0x005704A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5704A0u, ctx.xmm[0].u32[0]);
	// 0x2A6100: ret
	return;
}

void sub_2A6110(X86Context& ctx, uint8_t* base) {
	// 0x2A6110: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A6118: movss [0x005704E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5704E0u, ctx.xmm[0].u32[0]);
	// 0x2A6120: ret
	return;
}

void sub_2A6130(X86Context& ctx, uint8_t* base) {
	// 0x2A6130: movss xmm0, dword ptr [0x005704DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704DCu);
	// 0x2A6138: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A6140: movss [0x005704F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5704F0u, ctx.xmm[0].u32[0]);
	// 0x2A6148: ret
	return;
}

void sub_2A6150(X86Context& ctx, uint8_t* base) {
	// 0x2A6150: movss xmm0, dword ptr [0x00570544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570544u);
	// 0x2A6158: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A6160: movss [0x00570548], xmm0
	X86_MEM_WRITE_u32(base, 0x570548u, ctx.xmm[0].u32[0]);
	// 0x2A6168: ret
	return;
}

void sub_2A6170(X86Context& ctx, uint8_t* base) {
	// 0x2A6170: movss xmm0, dword ptr [0x005704F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704F0u);
	// 0x2A6178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6180: movss [0x00570530], xmm0
	X86_MEM_WRITE_u32(base, 0x570530u, ctx.xmm[0].u32[0]);
	// 0x2A6188: ret
	return;
}

void sub_2A6190(X86Context& ctx, uint8_t* base) {
	// 0x2A6190: movss xmm0, dword ptr [0x00570548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570548u);
	// 0x2A6198: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A61A0: movss [0x00570558], xmm0
	X86_MEM_WRITE_u32(base, 0x570558u, ctx.xmm[0].u32[0]);
	// 0x2A61A8: ret
	return;
}

void sub_2A61B0(X86Context& ctx, uint8_t* base) {
	// 0x2A61B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A61B8: movss [0x005704A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5704A8u, ctx.xmm[0].u32[0]);
	// 0x2A61C0: ret
	return;
}

void sub_2A61D0(X86Context& ctx, uint8_t* base) {
	// 0x2A61D0: movss xmm0, dword ptr [0x005704DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704DCu);
	// 0x2A61D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A61E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A61E8: movss [0x00570538], xmm0
	X86_MEM_WRITE_u32(base, 0x570538u, ctx.xmm[0].u32[0]);
	// 0x2A61F0: ret
	return;
}

void sub_2A6200(X86Context& ctx, uint8_t* base) {
	// 0x2A6200: movss xmm0, dword ptr [0x00570544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570544u);
	// 0x2A6208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6210: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A6218: movss [0x005704C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5704C8u, ctx.xmm[0].u32[0]);
	// 0x2A6220: ret
	return;
}

void sub_2A6230(X86Context& ctx, uint8_t* base) {
	// 0x2A6230: movss xmm0, dword ptr [0x005704DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704DCu);
	// 0x2A6238: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6240: movss [0x005704CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5704CCu, ctx.xmm[0].u32[0]);
	// 0x2A6248: ret
	return;
}

void sub_2A6250(X86Context& ctx, uint8_t* base) {
	// 0x2A6250: movss xmm0, dword ptr [0x00570544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570544u);
	// 0x2A6258: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6260: movss [0x0057054C], xmm0
	X86_MEM_WRITE_u32(base, 0x57054Cu, ctx.xmm[0].u32[0]);
	// 0x2A6268: ret
	return;
}

void sub_2A6270(X86Context& ctx, uint8_t* base) {
	// 0x2A6270: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A6278: movss [0x005704AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5704ACu, ctx.xmm[0].u32[0]);
	// 0x2A6280: ret
	return;
}

void sub_2A6290(X86Context& ctx, uint8_t* base) {
	// 0x2A6290: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A6298: movss [0x005704EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5704ECu, ctx.xmm[0].u32[0]);
	// 0x2A62A0: ret
	return;
}

void sub_2A62B0(X86Context& ctx, uint8_t* base) {
	// 0x2A62B0: movss xmm0, dword ptr [0x005704AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704ACu);
	// 0x2A62B8: movss [0x0057055C], xmm0
	X86_MEM_WRITE_u32(base, 0x57055Cu, ctx.xmm[0].u32[0]);
	// 0x2A62C0: ret
	return;
}

void sub_2A62D0(X86Context& ctx, uint8_t* base) {
	// 0x2A62D0: movss xmm0, dword ptr [0x00570544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570544u);
	// 0x2A62D8: subss xmm0, [0x005704AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5704ACu);
	// 0x2A62E0: movss [0x0057051C], xmm0
	X86_MEM_WRITE_u32(base, 0x57051Cu, ctx.xmm[0].u32[0]);
	// 0x2A62E8: ret
	return;
}

void sub_2A62F0(X86Context& ctx, uint8_t* base) {
	// 0x2A62F0: movss xmm0, dword ptr [0x0057051C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57051Cu);
	// 0x2A62F8: subss xmm0, [0x005704EC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5704ECu);
	// 0x2A6300: movss [0x00570514], xmm0
	X86_MEM_WRITE_u32(base, 0x570514u, ctx.xmm[0].u32[0]);
	// 0x2A6308: ret
	return;
}

void sub_2A6310(X86Context& ctx, uint8_t* base) {
	// 0x2A6310: movss xmm0, dword ptr [0x0057054C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57054Cu);
	// 0x2A6318: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A6320: movss [0x005704FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5704FCu, ctx.xmm[0].u32[0]);
	// 0x2A6328: ret
	return;
}

void sub_2A6330(X86Context& ctx, uint8_t* base) {
	// 0x2A6330: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A6338: movss [0x005704E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5704E8u, ctx.xmm[0].u32[0]);
	// 0x2A6340: ret
	return;
}

void sub_2A6350(X86Context& ctx, uint8_t* base) {
	// 0x2A6350: movss xmm0, dword ptr [0x005704FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704FCu);
	// 0x2A6358: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A6360: movss [0x00570534], xmm0
	X86_MEM_WRITE_u32(base, 0x570534u, ctx.xmm[0].u32[0]);
	// 0x2A6368: ret
	return;
}

void sub_2A6370(X86Context& ctx, uint8_t* base) {
	// 0x2A6370: movss xmm0, dword ptr [0x005704DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704DCu);
	// 0x2A6378: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A6380: movss [0x00570510], xmm0
	X86_MEM_WRITE_u32(base, 0x570510u, ctx.xmm[0].u32[0]);
	// 0x2A6388: ret
	return;
}

void sub_2A6390(X86Context& ctx, uint8_t* base) {
	// 0x2A6390: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A6398: movss [0x005704D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5704D8u, ctx.xmm[0].u32[0]);
	// 0x2A63A0: ret
	return;
}

void sub_2A63B0(X86Context& ctx, uint8_t* base) {
	// 0x2A63B0: movss xmm0, dword ptr [0x003B1688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2A63B8: movss [0x005704E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5704E4u, ctx.xmm[0].u32[0]);
	// 0x2A63C0: ret
	return;
}

void sub_2A63D0(X86Context& ctx, uint8_t* base) {
	// 0x2A63D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A63D8: movss [0x00570498], xmm0
	X86_MEM_WRITE_u32(base, 0x570498u, ctx.xmm[0].u32[0]);
	// 0x2A63E0: ret
	return;
}

void sub_2A63F0(X86Context& ctx, uint8_t* base) {
	// 0x2A63F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A63F8: movss [0x005704B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5704B8u, ctx.xmm[0].u32[0]);
	// 0x2A6400: ret
	return;
}

void sub_2A6410(X86Context& ctx, uint8_t* base) {
	// 0x2A6410: movss xmm0, dword ptr [0x003A69B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A69B4u);
	// 0x2A6418: movss [0x0057049C], xmm0
	X86_MEM_WRITE_u32(base, 0x57049Cu, ctx.xmm[0].u32[0]);
	// 0x2A6420: ret
	return;
}

void sub_2A6430(X86Context& ctx, uint8_t* base) {
	// 0x2A6430: movss xmm0, dword ptr [0x0057049C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57049Cu);
	// 0x2A6438: addss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A6440: movss [0x00570540], xmm0
	X86_MEM_WRITE_u32(base, 0x570540u, ctx.xmm[0].u32[0]);
	// 0x2A6448: ret
	return;
}

void sub_2A6450(X86Context& ctx, uint8_t* base) {
	// 0x2A6450: movss xmm0, dword ptr [0x00570540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570540u);
	// 0x2A6458: addss xmm0, [0x003A69B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69B4u);
	// 0x2A6460: movss [0x00570524], xmm0
	X86_MEM_WRITE_u32(base, 0x570524u, ctx.xmm[0].u32[0]);
	// 0x2A6468: ret
	return;
}

void sub_2A6470(X86Context& ctx, uint8_t* base) {
	// 0x2A6470: movss xmm0, dword ptr [0x00570524]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570524u);
	// 0x2A6478: addss xmm0, [0x003A69B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69B4u);
	// 0x2A6480: movss [0x005704C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5704C0u, ctx.xmm[0].u32[0]);
	// 0x2A6488: ret
	return;
}

void sub_2A6490(X86Context& ctx, uint8_t* base) {
	// 0x2A6490: movss xmm0, dword ptr [0x005704C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5704C0u);
	// 0x2A6498: movss [0x005704D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5704D4u, ctx.xmm[0].u32[0]);
	// 0x2A64A0: ret
	return;
}

void sub_2A64B0(X86Context& ctx, uint8_t* base) {
	// 0x2A64B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A64B8: movss [0x005705E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5705E0u, ctx.xmm[0].u32[0]);
	// 0x2A64C0: ret
	return;
}

void sub_2A64D0(X86Context& ctx, uint8_t* base) {
	// 0x2A64D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A64D8: movss [0x0057060C], xmm0
	X86_MEM_WRITE_u32(base, 0x57060Cu, ctx.xmm[0].u32[0]);
	// 0x2A64E0: ret
	return;
}

void sub_2A64F0(X86Context& ctx, uint8_t* base) {
	// 0x2A64F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A64F8: movss [0x005705D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5705D0u, ctx.xmm[0].u32[0]);
	// 0x2A6500: ret
	return;
}

void sub_2A6510(X86Context& ctx, uint8_t* base) {
	// 0x2A6510: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A6518: movss [0x0057056C], xmm0
	X86_MEM_WRITE_u32(base, 0x57056Cu, ctx.xmm[0].u32[0]);
	// 0x2A6520: ret
	return;
}

void sub_2A6530(X86Context& ctx, uint8_t* base) {
	// 0x2A6530: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A6538: movss [0x005705E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5705E4u, ctx.xmm[0].u32[0]);
	// 0x2A6540: ret
	return;
}

void sub_2A6550(X86Context& ctx, uint8_t* base) {
	// 0x2A6550: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A6558: movss [0x00570590], xmm0
	X86_MEM_WRITE_u32(base, 0x570590u, ctx.xmm[0].u32[0]);
	// 0x2A6560: ret
	return;
}

void sub_2A6570(X86Context& ctx, uint8_t* base) {
	// 0x2A6570: movss xmm0, dword ptr [0x005705E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705E4u);
	// 0x2A6578: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A6580: movss [0x0057062C], xmm0
	X86_MEM_WRITE_u32(base, 0x57062Cu, ctx.xmm[0].u32[0]);
	// 0x2A6588: ret
	return;
}

void sub_2A6590(X86Context& ctx, uint8_t* base) {
	// 0x2A6590: movss xmm0, dword ptr [0x00570590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570590u);
	// 0x2A6598: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A65A0: movss [0x00570614], xmm0
	X86_MEM_WRITE_u32(base, 0x570614u, ctx.xmm[0].u32[0]);
	// 0x2A65A8: ret
	return;
}

void sub_2A65B0(X86Context& ctx, uint8_t* base) {
	// 0x2A65B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A65B8: movss [0x0057064C], xmm0
	X86_MEM_WRITE_u32(base, 0x57064Cu, ctx.xmm[0].u32[0]);
	// 0x2A65C0: ret
	return;
}

void sub_2A65D0(X86Context& ctx, uint8_t* base) {
	// 0x2A65D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A65D8: movss [0x00570630], xmm0
	X86_MEM_WRITE_u32(base, 0x570630u, ctx.xmm[0].u32[0]);
	// 0x2A65E0: ret
	return;
}

void sub_2A65F0(X86Context& ctx, uint8_t* base) {
	// 0x2A65F0: movss xmm0, dword ptr [0x00570630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570630u);
	// 0x2A65F8: movss [0x00570648], xmm0
	X86_MEM_WRITE_u32(base, 0x570648u, ctx.xmm[0].u32[0]);
	// 0x2A6600: ret
	return;
}

void sub_2A6610(X86Context& ctx, uint8_t* base) {
	// 0x2A6610: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A6618: movss [0x0057057C], xmm0
	X86_MEM_WRITE_u32(base, 0x57057Cu, ctx.xmm[0].u32[0]);
	// 0x2A6620: ret
	return;
}

void sub_2A6630(X86Context& ctx, uint8_t* base) {
	// 0x2A6630: movss xmm0, dword ptr [0x00570590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570590u);
	// 0x2A6638: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A6640: movss [0x0057063C], xmm0
	X86_MEM_WRITE_u32(base, 0x57063Cu, ctx.xmm[0].u32[0]);
	// 0x2A6648: ret
	return;
}

void sub_2A6650(X86Context& ctx, uint8_t* base) {
	// 0x2A6650: movss xmm0, dword ptr [0x00570590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570590u);
	// 0x2A6658: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A6660: movss [0x005705C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5705C8u, ctx.xmm[0].u32[0]);
	// 0x2A6668: ret
	return;
}

void sub_2A6670(X86Context& ctx, uint8_t* base) {
	// 0x2A6670: movss xmm0, dword ptr [0x00570590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570590u);
	// 0x2A6678: subss xmm0, [0x005705C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5705C8u);
	// 0x2A6680: movss [0x0057059C], xmm0
	X86_MEM_WRITE_u32(base, 0x57059Cu, ctx.xmm[0].u32[0]);
	// 0x2A6688: ret
	return;
}

void sub_2A6690(X86Context& ctx, uint8_t* base) {
	// 0x2A6690: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A6698: movss [0x00570608], xmm0
	X86_MEM_WRITE_u32(base, 0x570608u, ctx.xmm[0].u32[0]);
	// 0x2A66A0: ret
	return;
}

void sub_2A66B0(X86Context& ctx, uint8_t* base) {
	// 0x2A66B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A66B8: movss [0x00570594], xmm0
	X86_MEM_WRITE_u32(base, 0x570594u, ctx.xmm[0].u32[0]);
	// 0x2A66C0: ret
	return;
}

void sub_2A66D0(X86Context& ctx, uint8_t* base) {
	// 0x2A66D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A66D8: movss [0x005705B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5705B0u, ctx.xmm[0].u32[0]);
	// 0x2A66E0: ret
	return;
}

void sub_2A66F0(X86Context& ctx, uint8_t* base) {
	// 0x2A66F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A66F8: movss [0x00570620], xmm0
	X86_MEM_WRITE_u32(base, 0x570620u, ctx.xmm[0].u32[0]);
	// 0x2A6700: ret
	return;
}

void sub_2A6710(X86Context& ctx, uint8_t* base) {
	// 0x2A6710: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A6718: movss [0x005705FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5705FCu, ctx.xmm[0].u32[0]);
	// 0x2A6720: ret
	return;
}

void sub_2A6730(X86Context& ctx, uint8_t* base) {
	// 0x2A6730: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A6738: movss [0x0057058C], xmm0
	X86_MEM_WRITE_u32(base, 0x57058Cu, ctx.xmm[0].u32[0]);
	// 0x2A6740: ret
	return;
}

