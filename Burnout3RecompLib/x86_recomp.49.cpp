#include "x86_recomp_shared.h"

void sub_283810(X86Context& ctx, uint8_t* base) {
	// 0x283810: movss xmm0, dword ptr [0x0056AA50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA50u);
	// 0x283818: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283820: movss [0x0056AA4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA4Cu, ctx.xmm[0].u32[0]);
	// 0x283828: ret
	return;
}

void sub_283830(X86Context& ctx, uint8_t* base) {
	// 0x283830: movss xmm0, dword ptr [0x0056AAAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAACu);
	// 0x283838: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283840: movss [0x0056AAB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAB4u, ctx.xmm[0].u32[0]);
	// 0x283848: ret
	return;
}

void sub_283850(X86Context& ctx, uint8_t* base) {
	// 0x283850: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x283858: movss [0x0056AA30], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA30u, ctx.xmm[0].u32[0]);
	// 0x283860: ret
	return;
}

void sub_283870(X86Context& ctx, uint8_t* base) {
	// 0x283870: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x283878: movss [0x0056AA5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA5Cu, ctx.xmm[0].u32[0]);
	// 0x283880: ret
	return;
}

void sub_283890(X86Context& ctx, uint8_t* base) {
	// 0x283890: movss xmm0, dword ptr [0x0056AA30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA30u);
	// 0x283898: movss [0x0056AAC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAC8u, ctx.xmm[0].u32[0]);
	// 0x2838A0: ret
	return;
}

void sub_2838B0(X86Context& ctx, uint8_t* base) {
	// 0x2838B0: movss xmm0, dword ptr [0x0056AAAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAACu);
	// 0x2838B8: subss xmm0, [0x0056AA30]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AA30u);
	// 0x2838C0: movss [0x0056AA8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA8Cu, ctx.xmm[0].u32[0]);
	// 0x2838C8: ret
	return;
}

void sub_2838D0(X86Context& ctx, uint8_t* base) {
	// 0x2838D0: movss xmm0, dword ptr [0x0056AA8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA8Cu);
	// 0x2838D8: subss xmm0, [0x0056AA5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AA5Cu);
	// 0x2838E0: movss [0x0056AA84], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA84u, ctx.xmm[0].u32[0]);
	// 0x2838E8: ret
	return;
}

void sub_2838F0(X86Context& ctx, uint8_t* base) {
	// 0x2838F0: movss xmm0, dword ptr [0x0056AAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAB4u);
	// 0x2838F8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x283900: movss [0x0056AA70], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA70u, ctx.xmm[0].u32[0]);
	// 0x283908: ret
	return;
}

void sub_283910(X86Context& ctx, uint8_t* base) {
	// 0x283910: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x283918: movss [0x0056AA58], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA58u, ctx.xmm[0].u32[0]);
	// 0x283920: ret
	return;
}

void sub_283930(X86Context& ctx, uint8_t* base) {
	// 0x283930: movss xmm0, dword ptr [0x0056AA70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA70u);
	// 0x283938: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x283940: movss [0x0056AAA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAA4u, ctx.xmm[0].u32[0]);
	// 0x283948: ret
	return;
}

void sub_283950(X86Context& ctx, uint8_t* base) {
	// 0x283950: movss xmm0, dword ptr [0x003B2088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2088u);
	// 0x283958: movss [0x0056AA74], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA74u, ctx.xmm[0].u32[0]);
	// 0x283960: ret
	return;
}

void sub_283970(X86Context& ctx, uint8_t* base) {
	// 0x283970: movss xmm0, dword ptr [0x003B226C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B226Cu);
	// 0x283978: movss [0x0056AA6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA6Cu, ctx.xmm[0].u32[0]);
	// 0x283980: ret
	return;
}

void sub_283990(X86Context& ctx, uint8_t* base) {
	// 0x283990: movss xmm0, dword ptr [0x0056AA50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA50u);
	// 0x283998: subss xmm0, [0x0056AA74]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AA74u);
	// 0x2839A0: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2839A8: movss [0x0056AA20], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA20u, ctx.xmm[0].u32[0]);
	// 0x2839B0: ret
	return;
}

void sub_2839C0(X86Context& ctx, uint8_t* base) {
	// 0x2839C0: movss xmm0, dword ptr [0x00397898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397898u);
	// 0x2839C8: movss [0x0056AA44], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA44u, ctx.xmm[0].u32[0]);
	// 0x2839D0: ret
	return;
}

void sub_2839E0(X86Context& ctx, uint8_t* base) {
	// 0x2839E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2839E8: movss [0x0056AB28], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB28u, ctx.xmm[0].u32[0]);
	// 0x2839F0: ret
	return;
}

void sub_283A00(X86Context& ctx, uint8_t* base) {
	// 0x283A00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x283A08: movss [0x0056AB44], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB44u, ctx.xmm[0].u32[0]);
	// 0x283A10: ret
	return;
}

void sub_283A20(X86Context& ctx, uint8_t* base) {
	// 0x283A20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x283A28: movss [0x0056AB1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB1Cu, ctx.xmm[0].u32[0]);
	// 0x283A30: ret
	return;
}

void sub_283A40(X86Context& ctx, uint8_t* base) {
	// 0x283A40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x283A48: movss [0x0056AAD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAD4u, ctx.xmm[0].u32[0]);
	// 0x283A50: ret
	return;
}

void sub_283A60(X86Context& ctx, uint8_t* base) {
	// 0x283A60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x283A68: movss [0x0056AB2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB2Cu, ctx.xmm[0].u32[0]);
	// 0x283A70: ret
	return;
}

void sub_283A80(X86Context& ctx, uint8_t* base) {
	// 0x283A80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x283A88: movss [0x0056AAF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAF0u, ctx.xmm[0].u32[0]);
	// 0x283A90: ret
	return;
}

void sub_283AA0(X86Context& ctx, uint8_t* base) {
	// 0x283AA0: movss xmm0, dword ptr [0x0056AB2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB2Cu);
	// 0x283AA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x283AB0: movss [0x0056AB64], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB64u, ctx.xmm[0].u32[0]);
	// 0x283AB8: ret
	return;
}

void sub_283AC0(X86Context& ctx, uint8_t* base) {
	// 0x283AC0: movss xmm0, dword ptr [0x0056AAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAF0u);
	// 0x283AC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x283AD0: movss [0x0056AB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB4Cu, ctx.xmm[0].u32[0]);
	// 0x283AD8: ret
	return;
}

void sub_283AE0(X86Context& ctx, uint8_t* base) {
	// 0x283AE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x283AE8: movss [0x0056AB7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB7Cu, ctx.xmm[0].u32[0]);
	// 0x283AF0: ret
	return;
}

void sub_283B00(X86Context& ctx, uint8_t* base) {
	// 0x283B00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x283B08: movss [0x0056AB68], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB68u, ctx.xmm[0].u32[0]);
	// 0x283B10: ret
	return;
}

void sub_283B20(X86Context& ctx, uint8_t* base) {
	// 0x283B20: movss xmm0, dword ptr [0x0056AB68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB68u);
	// 0x283B28: movss [0x0056AB78], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB78u, ctx.xmm[0].u32[0]);
	// 0x283B30: ret
	return;
}

void sub_283B40(X86Context& ctx, uint8_t* base) {
	// 0x283B40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x283B48: movss [0x0056AADC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AADCu, ctx.xmm[0].u32[0]);
	// 0x283B50: ret
	return;
}

void sub_283B60(X86Context& ctx, uint8_t* base) {
	// 0x283B60: movss xmm0, dword ptr [0x0056AAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAF0u);
	// 0x283B68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x283B70: movss [0x0056AB70], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB70u, ctx.xmm[0].u32[0]);
	// 0x283B78: ret
	return;
}

void sub_283B80(X86Context& ctx, uint8_t* base) {
	// 0x283B80: movss xmm0, dword ptr [0x0056AAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAF0u);
	// 0x283B88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x283B90: movss [0x0056AB18], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB18u, ctx.xmm[0].u32[0]);
	// 0x283B98: ret
	return;
}

void sub_283BA0(X86Context& ctx, uint8_t* base) {
	// 0x283BA0: movss xmm0, dword ptr [0x0056AAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAF0u);
	// 0x283BA8: subss xmm0, [0x0056AB18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AB18u);
	// 0x283BB0: movss [0x0056AAF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAF8u, ctx.xmm[0].u32[0]);
	// 0x283BB8: ret
	return;
}

void sub_283BC0(X86Context& ctx, uint8_t* base) {
	// 0x283BC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x283BC8: movss [0x0056AB40], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB40u, ctx.xmm[0].u32[0]);
	// 0x283BD0: ret
	return;
}

void sub_283BE0(X86Context& ctx, uint8_t* base) {
	// 0x283BE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x283BE8: movss [0x0056AAF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAF4u, ctx.xmm[0].u32[0]);
	// 0x283BF0: ret
	return;
}

void sub_283C00(X86Context& ctx, uint8_t* base) {
	// 0x283C00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x283C08: movss [0x0056AB04], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB04u, ctx.xmm[0].u32[0]);
	// 0x283C10: ret
	return;
}

void sub_283C20(X86Context& ctx, uint8_t* base) {
	// 0x283C20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x283C28: movss [0x0056AB58], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB58u, ctx.xmm[0].u32[0]);
	// 0x283C30: ret
	return;
}

void sub_283C40(X86Context& ctx, uint8_t* base) {
	// 0x283C40: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x283C48: movss [0x0056AB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB3Cu, ctx.xmm[0].u32[0]);
	// 0x283C50: ret
	return;
}

void sub_283C60(X86Context& ctx, uint8_t* base) {
	// 0x283C60: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x283C68: movss [0x0056AAEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAECu, ctx.xmm[0].u32[0]);
	// 0x283C70: ret
	return;
}

void sub_283C80(X86Context& ctx, uint8_t* base) {
	// 0x283C80: movss xmm0, dword ptr [0x0056AB04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB04u);
	// 0x283C88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x283C90: movss [0x0056AAE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAE0u, ctx.xmm[0].u32[0]);
	// 0x283C98: ret
	return;
}

void sub_283CA0(X86Context& ctx, uint8_t* base) {
	// 0x283CA0: movss xmm0, dword ptr [0x0056AB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB58u);
	// 0x283CA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x283CB0: movss [0x0056AB24], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB24u, ctx.xmm[0].u32[0]);
	// 0x283CB8: ret
	return;
}

void sub_283CC0(X86Context& ctx, uint8_t* base) {
	// 0x283CC0: movss xmm0, dword ptr [0x0056AAE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAE0u);
	// 0x283CC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x283CD0: movss [0x0056AB34], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB34u, ctx.xmm[0].u32[0]);
	// 0x283CD8: ret
	return;
}

void sub_283CE0(X86Context& ctx, uint8_t* base) {
	// 0x283CE0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x283CE8: movss [0x0056AAD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAD8u, ctx.xmm[0].u32[0]);
	// 0x283CF0: ret
	return;
}

void sub_283D00(X86Context& ctx, uint8_t* base) {
	// 0x283D00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x283D08: movss [0x0056AB08], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB08u, ctx.xmm[0].u32[0]);
	// 0x283D10: ret
	return;
}

void sub_283D20(X86Context& ctx, uint8_t* base) {
	// 0x283D20: movss xmm0, dword ptr [0x0056AB04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB04u);
	// 0x283D28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x283D30: movss [0x0056AB14], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB14u, ctx.xmm[0].u32[0]);
	// 0x283D38: ret
	return;
}

void sub_283D40(X86Context& ctx, uint8_t* base) {
	// 0x283D40: movss xmm0, dword ptr [0x0056AB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB58u);
	// 0x283D48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x283D50: movss [0x0056AB5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB5Cu, ctx.xmm[0].u32[0]);
	// 0x283D58: ret
	return;
}

void sub_283D60(X86Context& ctx, uint8_t* base) {
	// 0x283D60: movss xmm0, dword ptr [0x0056AB14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB14u);
	// 0x283D68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283D70: movss [0x0056AB48], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB48u, ctx.xmm[0].u32[0]);
	// 0x283D78: ret
	return;
}

void sub_283D80(X86Context& ctx, uint8_t* base) {
	// 0x283D80: movss xmm0, dword ptr [0x0056AB5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB5Cu);
	// 0x283D88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283D90: movss [0x0056AB6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB6Cu, ctx.xmm[0].u32[0]);
	// 0x283D98: ret
	return;
}

void sub_283DA0(X86Context& ctx, uint8_t* base) {
	// 0x283DA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x283DA8: movss [0x0056AAE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAE4u, ctx.xmm[0].u32[0]);
	// 0x283DB0: ret
	return;
}

void sub_283DC0(X86Context& ctx, uint8_t* base) {
	// 0x283DC0: movss xmm0, dword ptr [0x0056AB04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB04u);
	// 0x283DC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283DD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x283DD8: movss [0x0056AB54], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB54u, ctx.xmm[0].u32[0]);
	// 0x283DE0: ret
	return;
}

void sub_283DF0(X86Context& ctx, uint8_t* base) {
	// 0x283DF0: movss xmm0, dword ptr [0x0056AB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB58u);
	// 0x283DF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283E00: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x283E08: movss [0x0056AAFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAFCu, ctx.xmm[0].u32[0]);
	// 0x283E10: ret
	return;
}

void sub_283E20(X86Context& ctx, uint8_t* base) {
	// 0x283E20: movss xmm0, dword ptr [0x0056AB04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB04u);
	// 0x283E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283E30: movss [0x0056AB00], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB00u, ctx.xmm[0].u32[0]);
	// 0x283E38: ret
	return;
}

void sub_283E40(X86Context& ctx, uint8_t* base) {
	// 0x283E40: movss xmm0, dword ptr [0x0056AB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB58u);
	// 0x283E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283E50: movss [0x0056AB60], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB60u, ctx.xmm[0].u32[0]);
	// 0x283E58: ret
	return;
}

void sub_283E60(X86Context& ctx, uint8_t* base) {
	// 0x283E60: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x283E68: movss [0x0056AAE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAE8u, ctx.xmm[0].u32[0]);
	// 0x283E70: ret
	return;
}

void sub_283E80(X86Context& ctx, uint8_t* base) {
	// 0x283E80: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x283E88: movss [0x0056AB10], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB10u, ctx.xmm[0].u32[0]);
	// 0x283E90: ret
	return;
}

void sub_283EA0(X86Context& ctx, uint8_t* base) {
	// 0x283EA0: movss xmm0, dword ptr [0x0056AAE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAE8u);
	// 0x283EA8: movss [0x0056AB74], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB74u, ctx.xmm[0].u32[0]);
	// 0x283EB0: ret
	return;
}

void sub_283EC0(X86Context& ctx, uint8_t* base) {
	// 0x283EC0: movss xmm0, dword ptr [0x0056AB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB58u);
	// 0x283EC8: subss xmm0, [0x0056AAE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AAE8u);
	// 0x283ED0: movss [0x0056AB38], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB38u, ctx.xmm[0].u32[0]);
	// 0x283ED8: ret
	return;
}

void sub_283EE0(X86Context& ctx, uint8_t* base) {
	// 0x283EE0: movss xmm0, dword ptr [0x0056AB38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB38u);
	// 0x283EE8: subss xmm0, [0x0056AB10]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AB10u);
	// 0x283EF0: movss [0x0056AB30], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB30u, ctx.xmm[0].u32[0]);
	// 0x283EF8: ret
	return;
}

void sub_283F00(X86Context& ctx, uint8_t* base) {
	// 0x283F00: movss xmm0, dword ptr [0x0056AB60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB60u);
	// 0x283F08: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x283F10: movss [0x0056AB20], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB20u, ctx.xmm[0].u32[0]);
	// 0x283F18: ret
	return;
}

void sub_283F20(X86Context& ctx, uint8_t* base) {
	// 0x283F20: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x283F28: movss [0x0056AB0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB0Cu, ctx.xmm[0].u32[0]);
	// 0x283F30: ret
	return;
}

void sub_283F40(X86Context& ctx, uint8_t* base) {
	// 0x283F40: movss xmm0, dword ptr [0x0056AB20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB20u);
	// 0x283F48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x283F50: movss [0x0056AB50], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB50u, ctx.xmm[0].u32[0]);
	// 0x283F58: ret
	return;
}

void sub_283F60(X86Context& ctx, uint8_t* base) {
	// 0x283F60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x283F68: movss [0x0056ABDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABDCu, ctx.xmm[0].u32[0]);
	// 0x283F70: ret
	return;
}

void sub_283F80(X86Context& ctx, uint8_t* base) {
	// 0x283F80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x283F88: movss [0x0056ABF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABF8u, ctx.xmm[0].u32[0]);
	// 0x283F90: ret
	return;
}

void sub_283FA0(X86Context& ctx, uint8_t* base) {
	// 0x283FA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x283FA8: movss [0x0056ABCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABCCu, ctx.xmm[0].u32[0]);
	// 0x283FB0: ret
	return;
}

void sub_283FC0(X86Context& ctx, uint8_t* base) {
	// 0x283FC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x283FC8: movss [0x0056AB80], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB80u, ctx.xmm[0].u32[0]);
	// 0x283FD0: ret
	return;
}

void sub_283FE0(X86Context& ctx, uint8_t* base) {
	// 0x283FE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x283FE8: movss [0x0056ABE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABE0u, ctx.xmm[0].u32[0]);
	// 0x283FF0: ret
	return;
}

void sub_284000(X86Context& ctx, uint8_t* base) {
	// 0x284000: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x284008: movss [0x0056AB9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB9Cu, ctx.xmm[0].u32[0]);
	// 0x284010: ret
	return;
}

void sub_284020(X86Context& ctx, uint8_t* base) {
	// 0x284020: movss xmm0, dword ptr [0x0056ABE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABE0u);
	// 0x284028: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284030: movss [0x0056AC18], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC18u, ctx.xmm[0].u32[0]);
	// 0x284038: ret
	return;
}

void sub_284040(X86Context& ctx, uint8_t* base) {
	// 0x284040: movss xmm0, dword ptr [0x0056AB9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB9Cu);
	// 0x284048: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x284050: movss [0x0056AC00], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC00u, ctx.xmm[0].u32[0]);
	// 0x284058: ret
	return;
}

void sub_284060(X86Context& ctx, uint8_t* base) {
	// 0x284060: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x284068: movss [0x0056AC30], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC30u, ctx.xmm[0].u32[0]);
	// 0x284070: ret
	return;
}

void sub_284080(X86Context& ctx, uint8_t* base) {
	// 0x284080: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x284088: movss [0x0056AC1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC1Cu, ctx.xmm[0].u32[0]);
	// 0x284090: ret
	return;
}

void sub_2840A0(X86Context& ctx, uint8_t* base) {
	// 0x2840A0: movss xmm0, dword ptr [0x0056AC1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC1Cu);
	// 0x2840A8: movss [0x0056AC2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC2Cu, ctx.xmm[0].u32[0]);
	// 0x2840B0: ret
	return;
}

void sub_2840C0(X86Context& ctx, uint8_t* base) {
	// 0x2840C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2840C8: movss [0x0056AB88], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB88u, ctx.xmm[0].u32[0]);
	// 0x2840D0: ret
	return;
}

void sub_2840E0(X86Context& ctx, uint8_t* base) {
	// 0x2840E0: movss xmm0, dword ptr [0x0056AB9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB9Cu);
	// 0x2840E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2840F0: movss [0x0056AC24], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC24u, ctx.xmm[0].u32[0]);
	// 0x2840F8: ret
	return;
}

void sub_284100(X86Context& ctx, uint8_t* base) {
	// 0x284100: movss xmm0, dword ptr [0x0056AB9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB9Cu);
	// 0x284108: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x284110: movss [0x0056ABC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABC8u, ctx.xmm[0].u32[0]);
	// 0x284118: ret
	return;
}

void sub_284120(X86Context& ctx, uint8_t* base) {
	// 0x284120: movss xmm0, dword ptr [0x0056AB9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB9Cu);
	// 0x284128: subss xmm0, [0x0056ABC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ABC8u);
	// 0x284130: movss [0x0056ABA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABA4u, ctx.xmm[0].u32[0]);
	// 0x284138: ret
	return;
}

void sub_284140(X86Context& ctx, uint8_t* base) {
	// 0x284140: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x284148: movss [0x0056ABF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABF4u, ctx.xmm[0].u32[0]);
	// 0x284150: ret
	return;
}

void sub_284160(X86Context& ctx, uint8_t* base) {
	// 0x284160: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x284168: movss [0x0056ABA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABA0u, ctx.xmm[0].u32[0]);
	// 0x284170: ret
	return;
}

void sub_284180(X86Context& ctx, uint8_t* base) {
	// 0x284180: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x284188: movss [0x0056ABB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABB4u, ctx.xmm[0].u32[0]);
	// 0x284190: ret
	return;
}

void sub_2841A0(X86Context& ctx, uint8_t* base) {
	// 0x2841A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2841A8: movss [0x0056AC0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC0Cu, ctx.xmm[0].u32[0]);
	// 0x2841B0: ret
	return;
}

void sub_2841C0(X86Context& ctx, uint8_t* base) {
	// 0x2841C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2841C8: movss [0x0056ABF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABF0u, ctx.xmm[0].u32[0]);
	// 0x2841D0: ret
	return;
}

void sub_2841E0(X86Context& ctx, uint8_t* base) {
	// 0x2841E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2841E8: movss [0x0056AB98], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB98u, ctx.xmm[0].u32[0]);
	// 0x2841F0: ret
	return;
}

void sub_284200(X86Context& ctx, uint8_t* base) {
	// 0x284200: movss xmm0, dword ptr [0x0056ABB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABB4u);
	// 0x284208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284210: movss [0x0056AB8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB8Cu, ctx.xmm[0].u32[0]);
	// 0x284218: ret
	return;
}

void sub_284220(X86Context& ctx, uint8_t* base) {
	// 0x284220: movss xmm0, dword ptr [0x0056AC0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC0Cu);
	// 0x284228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x284230: movss [0x0056ABD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABD4u, ctx.xmm[0].u32[0]);
	// 0x284238: ret
	return;
}

void sub_284240(X86Context& ctx, uint8_t* base) {
	// 0x284240: movss xmm0, dword ptr [0x0056AB8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB8Cu);
	// 0x284248: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284250: movss [0x0056ABE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABE8u, ctx.xmm[0].u32[0]);
	// 0x284258: ret
	return;
}

void sub_284260(X86Context& ctx, uint8_t* base) {
	// 0x284260: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x284268: movss [0x0056AB84], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB84u, ctx.xmm[0].u32[0]);
	// 0x284270: ret
	return;
}

void sub_284280(X86Context& ctx, uint8_t* base) {
	// 0x284280: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x284288: movss [0x0056ABB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABB8u, ctx.xmm[0].u32[0]);
	// 0x284290: ret
	return;
}

void sub_2842A0(X86Context& ctx, uint8_t* base) {
	// 0x2842A0: movss xmm0, dword ptr [0x0056ABB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABB4u);
	// 0x2842A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2842B0: movss [0x0056ABC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABC4u, ctx.xmm[0].u32[0]);
	// 0x2842B8: ret
	return;
}

void sub_2842C0(X86Context& ctx, uint8_t* base) {
	// 0x2842C0: movss xmm0, dword ptr [0x0056AC0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC0Cu);
	// 0x2842C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2842D0: movss [0x0056AC10], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC10u, ctx.xmm[0].u32[0]);
	// 0x2842D8: ret
	return;
}

void sub_2842E0(X86Context& ctx, uint8_t* base) {
	// 0x2842E0: movss xmm0, dword ptr [0x0056ABC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABC4u);
	// 0x2842E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2842F0: movss [0x0056ABFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABFCu, ctx.xmm[0].u32[0]);
	// 0x2842F8: ret
	return;
}

void sub_284300(X86Context& ctx, uint8_t* base) {
	// 0x284300: movss xmm0, dword ptr [0x0056AC10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC10u);
	// 0x284308: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284310: movss [0x0056AC20], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC20u, ctx.xmm[0].u32[0]);
	// 0x284318: ret
	return;
}

void sub_284320(X86Context& ctx, uint8_t* base) {
	// 0x284320: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x284328: movss [0x0056AB90], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB90u, ctx.xmm[0].u32[0]);
	// 0x284330: ret
	return;
}

void sub_284340(X86Context& ctx, uint8_t* base) {
	// 0x284340: movss xmm0, dword ptr [0x0056ABB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABB4u);
	// 0x284348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284350: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x284358: movss [0x0056AC08], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC08u, ctx.xmm[0].u32[0]);
	// 0x284360: ret
	return;
}

void sub_284370(X86Context& ctx, uint8_t* base) {
	// 0x284370: movss xmm0, dword ptr [0x0056AC0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC0Cu);
	// 0x284378: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284380: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x284388: movss [0x0056ABA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABA8u, ctx.xmm[0].u32[0]);
	// 0x284390: ret
	return;
}

void sub_2843A0(X86Context& ctx, uint8_t* base) {
	// 0x2843A0: movss xmm0, dword ptr [0x0056ABB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABB4u);
	// 0x2843A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2843B0: movss [0x0056ABAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABACu, ctx.xmm[0].u32[0]);
	// 0x2843B8: ret
	return;
}

void sub_2843C0(X86Context& ctx, uint8_t* base) {
	// 0x2843C0: movss xmm0, dword ptr [0x0056AC0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC0Cu);
	// 0x2843C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2843D0: movss [0x0056AC14], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC14u, ctx.xmm[0].u32[0]);
	// 0x2843D8: ret
	return;
}

void sub_2843E0(X86Context& ctx, uint8_t* base) {
	// 0x2843E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2843E8: movss [0x0056AB94], xmm0
	X86_MEM_WRITE_u32(base, 0x56AB94u, ctx.xmm[0].u32[0]);
	// 0x2843F0: ret
	return;
}

void sub_284400(X86Context& ctx, uint8_t* base) {
	// 0x284400: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x284408: movss [0x0056ABC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABC0u, ctx.xmm[0].u32[0]);
	// 0x284410: ret
	return;
}

void sub_284420(X86Context& ctx, uint8_t* base) {
	// 0x284420: movss xmm0, dword ptr [0x0056AB94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AB94u);
	// 0x284428: movss [0x0056AC28], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC28u, ctx.xmm[0].u32[0]);
	// 0x284430: ret
	return;
}

void sub_284440(X86Context& ctx, uint8_t* base) {
	// 0x284440: movss xmm0, dword ptr [0x0056AC0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC0Cu);
	// 0x284448: subss xmm0, [0x0056AB94]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AB94u);
	// 0x284450: movss [0x0056ABEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABECu, ctx.xmm[0].u32[0]);
	// 0x284458: ret
	return;
}

void sub_284460(X86Context& ctx, uint8_t* base) {
	// 0x284460: movss xmm0, dword ptr [0x0056ABEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABECu);
	// 0x284468: subss xmm0, [0x0056ABC0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ABC0u);
	// 0x284470: movss [0x0056ABE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABE4u, ctx.xmm[0].u32[0]);
	// 0x284478: ret
	return;
}

void sub_284480(X86Context& ctx, uint8_t* base) {
	// 0x284480: movss xmm0, dword ptr [0x0056AC14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC14u);
	// 0x284488: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x284490: movss [0x0056ABD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABD0u, ctx.xmm[0].u32[0]);
	// 0x284498: ret
	return;
}

void sub_2844A0(X86Context& ctx, uint8_t* base) {
	// 0x2844A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2844A8: movss [0x0056ABBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABBCu, ctx.xmm[0].u32[0]);
	// 0x2844B0: ret
	return;
}

void sub_2844C0(X86Context& ctx, uint8_t* base) {
	// 0x2844C0: movss xmm0, dword ptr [0x0056ABD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ABD0u);
	// 0x2844C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2844D0: movss [0x0056AC04], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC04u, ctx.xmm[0].u32[0]);
	// 0x2844D8: ret
	return;
}

void sub_2844E0(X86Context& ctx, uint8_t* base) {
	// 0x2844E0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2844E8: movss [0x0056ABD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABD8u, ctx.xmm[0].u32[0]);
	// 0x2844F0: ret
	return;
}

void sub_284500(X86Context& ctx, uint8_t* base) {
	// 0x284500: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x284508: movss [0x0056ABB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ABB0u, ctx.xmm[0].u32[0]);
	// 0x284510: ret
	return;
}

void sub_284520(X86Context& ctx, uint8_t* base) {
	// 0x284520: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x284528: movss [0x0056AC88], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC88u, ctx.xmm[0].u32[0]);
	// 0x284530: ret
	return;
}

void sub_284540(X86Context& ctx, uint8_t* base) {
	// 0x284540: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x284548: movss [0x0056ACA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACA4u, ctx.xmm[0].u32[0]);
	// 0x284550: ret
	return;
}

void sub_284560(X86Context& ctx, uint8_t* base) {
	// 0x284560: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x284568: movss [0x0056AC7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC7Cu, ctx.xmm[0].u32[0]);
	// 0x284570: ret
	return;
}

void sub_284580(X86Context& ctx, uint8_t* base) {
	// 0x284580: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x284588: movss [0x0056AC34], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC34u, ctx.xmm[0].u32[0]);
	// 0x284590: ret
	return;
}

void sub_2845A0(X86Context& ctx, uint8_t* base) {
	// 0x2845A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2845A8: movss [0x0056AC8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC8Cu, ctx.xmm[0].u32[0]);
	// 0x2845B0: ret
	return;
}

void sub_2845C0(X86Context& ctx, uint8_t* base) {
	// 0x2845C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2845C8: movss [0x0056AC50], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC50u, ctx.xmm[0].u32[0]);
	// 0x2845D0: ret
	return;
}

void sub_2845E0(X86Context& ctx, uint8_t* base) {
	// 0x2845E0: movss xmm0, dword ptr [0x0056AC8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC8Cu);
	// 0x2845E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2845F0: movss [0x0056ACC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACC4u, ctx.xmm[0].u32[0]);
	// 0x2845F8: ret
	return;
}

void sub_284600(X86Context& ctx, uint8_t* base) {
	// 0x284600: movss xmm0, dword ptr [0x0056AC50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC50u);
	// 0x284608: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x284610: movss [0x0056ACAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACACu, ctx.xmm[0].u32[0]);
	// 0x284618: ret
	return;
}

void sub_284620(X86Context& ctx, uint8_t* base) {
	// 0x284620: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x284628: movss [0x0056ACDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACDCu, ctx.xmm[0].u32[0]);
	// 0x284630: ret
	return;
}

void sub_284640(X86Context& ctx, uint8_t* base) {
	// 0x284640: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x284648: movss [0x0056ACC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACC8u, ctx.xmm[0].u32[0]);
	// 0x284650: ret
	return;
}

void sub_284660(X86Context& ctx, uint8_t* base) {
	// 0x284660: movss xmm0, dword ptr [0x0056ACC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACC8u);
	// 0x284668: movss [0x0056ACD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACD8u, ctx.xmm[0].u32[0]);
	// 0x284670: ret
	return;
}

void sub_284680(X86Context& ctx, uint8_t* base) {
	// 0x284680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x284688: movss [0x0056AC3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC3Cu, ctx.xmm[0].u32[0]);
	// 0x284690: ret
	return;
}

void sub_2846A0(X86Context& ctx, uint8_t* base) {
	// 0x2846A0: movss xmm0, dword ptr [0x0056AC50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC50u);
	// 0x2846A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2846B0: movss [0x0056ACD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACD0u, ctx.xmm[0].u32[0]);
	// 0x2846B8: ret
	return;
}

void sub_2846C0(X86Context& ctx, uint8_t* base) {
	// 0x2846C0: movss xmm0, dword ptr [0x0056AC50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC50u);
	// 0x2846C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2846D0: movss [0x0056AC78], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC78u, ctx.xmm[0].u32[0]);
	// 0x2846D8: ret
	return;
}

void sub_2846E0(X86Context& ctx, uint8_t* base) {
	// 0x2846E0: movss xmm0, dword ptr [0x0056AC50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC50u);
	// 0x2846E8: subss xmm0, [0x0056AC78]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AC78u);
	// 0x2846F0: movss [0x0056AC58], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC58u, ctx.xmm[0].u32[0]);
	// 0x2846F8: ret
	return;
}

void sub_284700(X86Context& ctx, uint8_t* base) {
	// 0x284700: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x284708: movss [0x0056ACA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACA0u, ctx.xmm[0].u32[0]);
	// 0x284710: ret
	return;
}

void sub_284720(X86Context& ctx, uint8_t* base) {
	// 0x284720: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x284728: movss [0x0056AC54], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC54u, ctx.xmm[0].u32[0]);
	// 0x284730: ret
	return;
}

void sub_284740(X86Context& ctx, uint8_t* base) {
	// 0x284740: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x284748: movss [0x0056AC64], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC64u, ctx.xmm[0].u32[0]);
	// 0x284750: ret
	return;
}

void sub_284760(X86Context& ctx, uint8_t* base) {
	// 0x284760: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x284768: movss [0x0056ACB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACB8u, ctx.xmm[0].u32[0]);
	// 0x284770: ret
	return;
}

void sub_284780(X86Context& ctx, uint8_t* base) {
	// 0x284780: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x284788: movss [0x0056AC9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC9Cu, ctx.xmm[0].u32[0]);
	// 0x284790: ret
	return;
}

void sub_2847A0(X86Context& ctx, uint8_t* base) {
	// 0x2847A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2847A8: movss [0x0056AC4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC4Cu, ctx.xmm[0].u32[0]);
	// 0x2847B0: ret
	return;
}

void sub_2847C0(X86Context& ctx, uint8_t* base) {
	// 0x2847C0: movss xmm0, dword ptr [0x0056AC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC64u);
	// 0x2847C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2847D0: movss [0x0056AC40], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC40u, ctx.xmm[0].u32[0]);
	// 0x2847D8: ret
	return;
}

void sub_2847E0(X86Context& ctx, uint8_t* base) {
	// 0x2847E0: movss xmm0, dword ptr [0x0056ACB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACB8u);
	// 0x2847E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2847F0: movss [0x0056AC84], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC84u, ctx.xmm[0].u32[0]);
	// 0x2847F8: ret
	return;
}

void sub_284800(X86Context& ctx, uint8_t* base) {
	// 0x284800: movss xmm0, dword ptr [0x0056AC40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC40u);
	// 0x284808: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284810: movss [0x0056AC94], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC94u, ctx.xmm[0].u32[0]);
	// 0x284818: ret
	return;
}

void sub_284820(X86Context& ctx, uint8_t* base) {
	// 0x284820: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x284828: movss [0x0056AC38], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC38u, ctx.xmm[0].u32[0]);
	// 0x284830: ret
	return;
}

void sub_284840(X86Context& ctx, uint8_t* base) {
	// 0x284840: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x284848: movss [0x0056AC68], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC68u, ctx.xmm[0].u32[0]);
	// 0x284850: ret
	return;
}

void sub_284860(X86Context& ctx, uint8_t* base) {
	// 0x284860: movss xmm0, dword ptr [0x0056AC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC64u);
	// 0x284868: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x284870: movss [0x0056AC74], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC74u, ctx.xmm[0].u32[0]);
	// 0x284878: ret
	return;
}

void sub_284880(X86Context& ctx, uint8_t* base) {
	// 0x284880: movss xmm0, dword ptr [0x0056ACB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACB8u);
	// 0x284888: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x284890: movss [0x0056ACBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACBCu, ctx.xmm[0].u32[0]);
	// 0x284898: ret
	return;
}

void sub_2848A0(X86Context& ctx, uint8_t* base) {
	// 0x2848A0: movss xmm0, dword ptr [0x0056AC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC74u);
	// 0x2848A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2848B0: movss [0x0056ACA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACA8u, ctx.xmm[0].u32[0]);
	// 0x2848B8: ret
	return;
}

void sub_2848C0(X86Context& ctx, uint8_t* base) {
	// 0x2848C0: movss xmm0, dword ptr [0x0056ACBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACBCu);
	// 0x2848C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2848D0: movss [0x0056ACCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACCCu, ctx.xmm[0].u32[0]);
	// 0x2848D8: ret
	return;
}

void sub_2848E0(X86Context& ctx, uint8_t* base) {
	// 0x2848E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2848E8: movss [0x0056AC44], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC44u, ctx.xmm[0].u32[0]);
	// 0x2848F0: ret
	return;
}

void sub_284900(X86Context& ctx, uint8_t* base) {
	// 0x284900: movss xmm0, dword ptr [0x0056AC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC64u);
	// 0x284908: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284910: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x284918: movss [0x0056ACB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACB4u, ctx.xmm[0].u32[0]);
	// 0x284920: ret
	return;
}

void sub_284930(X86Context& ctx, uint8_t* base) {
	// 0x284930: movss xmm0, dword ptr [0x0056ACB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACB8u);
	// 0x284938: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284940: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x284948: movss [0x0056AC5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC5Cu, ctx.xmm[0].u32[0]);
	// 0x284950: ret
	return;
}

void sub_284960(X86Context& ctx, uint8_t* base) {
	// 0x284960: movss xmm0, dword ptr [0x0056AC64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC64u);
	// 0x284968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284970: movss [0x0056AC60], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC60u, ctx.xmm[0].u32[0]);
	// 0x284978: ret
	return;
}

void sub_284980(X86Context& ctx, uint8_t* base) {
	// 0x284980: movss xmm0, dword ptr [0x0056ACB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACB8u);
	// 0x284988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284990: movss [0x0056ACC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACC0u, ctx.xmm[0].u32[0]);
	// 0x284998: ret
	return;
}

void sub_2849A0(X86Context& ctx, uint8_t* base) {
	// 0x2849A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2849A8: movss [0x0056AC48], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC48u, ctx.xmm[0].u32[0]);
	// 0x2849B0: ret
	return;
}

void sub_2849C0(X86Context& ctx, uint8_t* base) {
	// 0x2849C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2849C8: movss [0x0056AC70], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC70u, ctx.xmm[0].u32[0]);
	// 0x2849D0: ret
	return;
}

void sub_2849E0(X86Context& ctx, uint8_t* base) {
	// 0x2849E0: movss xmm0, dword ptr [0x0056AC48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC48u);
	// 0x2849E8: movss [0x0056ACD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACD4u, ctx.xmm[0].u32[0]);
	// 0x2849F0: ret
	return;
}

void sub_284A00(X86Context& ctx, uint8_t* base) {
	// 0x284A00: movss xmm0, dword ptr [0x0056ACB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACB8u);
	// 0x284A08: subss xmm0, [0x0056AC48]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AC48u);
	// 0x284A10: movss [0x0056AC98], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC98u, ctx.xmm[0].u32[0]);
	// 0x284A18: ret
	return;
}

void sub_284A20(X86Context& ctx, uint8_t* base) {
	// 0x284A20: movss xmm0, dword ptr [0x0056AC98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC98u);
	// 0x284A28: subss xmm0, [0x0056AC70]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AC70u);
	// 0x284A30: movss [0x0056AC90], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC90u, ctx.xmm[0].u32[0]);
	// 0x284A38: ret
	return;
}

void sub_284A40(X86Context& ctx, uint8_t* base) {
	// 0x284A40: movss xmm0, dword ptr [0x0056ACC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACC0u);
	// 0x284A48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x284A50: movss [0x0056AC80], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC80u, ctx.xmm[0].u32[0]);
	// 0x284A58: ret
	return;
}

void sub_284A60(X86Context& ctx, uint8_t* base) {
	// 0x284A60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x284A68: movss [0x0056AC6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AC6Cu, ctx.xmm[0].u32[0]);
	// 0x284A70: ret
	return;
}

void sub_284A80(X86Context& ctx, uint8_t* base) {
	// 0x284A80: movss xmm0, dword ptr [0x0056AC80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AC80u);
	// 0x284A88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x284A90: movss [0x0056ACB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACB0u, ctx.xmm[0].u32[0]);
	// 0x284A98: ret
	return;
}

void sub_284AA0(X86Context& ctx, uint8_t* base) {
	// 0x284AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x284AA8: movss [0x0056AD34], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD34u, ctx.xmm[0].u32[0]);
	// 0x284AB0: ret
	return;
}

void sub_284AC0(X86Context& ctx, uint8_t* base) {
	// 0x284AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x284AC8: movss [0x0056AD50], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD50u, ctx.xmm[0].u32[0]);
	// 0x284AD0: ret
	return;
}

void sub_284AE0(X86Context& ctx, uint8_t* base) {
	// 0x284AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x284AE8: movss [0x0056AD28], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD28u, ctx.xmm[0].u32[0]);
	// 0x284AF0: ret
	return;
}

void sub_284B00(X86Context& ctx, uint8_t* base) {
	// 0x284B00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x284B08: movss [0x0056ACE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACE0u, ctx.xmm[0].u32[0]);
	// 0x284B10: ret
	return;
}

void sub_284B20(X86Context& ctx, uint8_t* base) {
	// 0x284B20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x284B28: movss [0x0056AD38], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD38u, ctx.xmm[0].u32[0]);
	// 0x284B30: ret
	return;
}

void sub_284B40(X86Context& ctx, uint8_t* base) {
	// 0x284B40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x284B48: movss [0x0056ACFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACFCu, ctx.xmm[0].u32[0]);
	// 0x284B50: ret
	return;
}

void sub_284B60(X86Context& ctx, uint8_t* base) {
	// 0x284B60: movss xmm0, dword ptr [0x0056AD38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD38u);
	// 0x284B68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284B70: movss [0x0056AD70], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD70u, ctx.xmm[0].u32[0]);
	// 0x284B78: ret
	return;
}

void sub_284B80(X86Context& ctx, uint8_t* base) {
	// 0x284B80: movss xmm0, dword ptr [0x0056ACFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACFCu);
	// 0x284B88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x284B90: movss [0x0056AD58], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD58u, ctx.xmm[0].u32[0]);
	// 0x284B98: ret
	return;
}

void sub_284BA0(X86Context& ctx, uint8_t* base) {
	// 0x284BA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x284BA8: movss [0x0056AD88], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD88u, ctx.xmm[0].u32[0]);
	// 0x284BB0: ret
	return;
}

void sub_284BC0(X86Context& ctx, uint8_t* base) {
	// 0x284BC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x284BC8: movss [0x0056AD74], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD74u, ctx.xmm[0].u32[0]);
	// 0x284BD0: ret
	return;
}

void sub_284BE0(X86Context& ctx, uint8_t* base) {
	// 0x284BE0: movss xmm0, dword ptr [0x0056AD74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD74u);
	// 0x284BE8: movss [0x0056AD84], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD84u, ctx.xmm[0].u32[0]);
	// 0x284BF0: ret
	return;
}

void sub_284C00(X86Context& ctx, uint8_t* base) {
	// 0x284C00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x284C08: movss [0x0056ACE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACE8u, ctx.xmm[0].u32[0]);
	// 0x284C10: ret
	return;
}

void sub_284C20(X86Context& ctx, uint8_t* base) {
	// 0x284C20: movss xmm0, dword ptr [0x0056ACFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACFCu);
	// 0x284C28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x284C30: movss [0x0056AD7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD7Cu, ctx.xmm[0].u32[0]);
	// 0x284C38: ret
	return;
}

void sub_284C40(X86Context& ctx, uint8_t* base) {
	// 0x284C40: movss xmm0, dword ptr [0x0056ACFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACFCu);
	// 0x284C48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x284C50: movss [0x0056AD24], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD24u, ctx.xmm[0].u32[0]);
	// 0x284C58: ret
	return;
}

void sub_284C60(X86Context& ctx, uint8_t* base) {
	// 0x284C60: movss xmm0, dword ptr [0x0056ACFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACFCu);
	// 0x284C68: subss xmm0, [0x0056AD24]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AD24u);
	// 0x284C70: movss [0x0056AD04], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD04u, ctx.xmm[0].u32[0]);
	// 0x284C78: ret
	return;
}

void sub_284C80(X86Context& ctx, uint8_t* base) {
	// 0x284C80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x284C88: movss [0x0056AD4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD4Cu, ctx.xmm[0].u32[0]);
	// 0x284C90: ret
	return;
}

void sub_284CA0(X86Context& ctx, uint8_t* base) {
	// 0x284CA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x284CA8: movss [0x0056AD00], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD00u, ctx.xmm[0].u32[0]);
	// 0x284CB0: ret
	return;
}

void sub_284CC0(X86Context& ctx, uint8_t* base) {
	// 0x284CC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x284CC8: movss [0x0056AD10], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD10u, ctx.xmm[0].u32[0]);
	// 0x284CD0: ret
	return;
}

void sub_284CE0(X86Context& ctx, uint8_t* base) {
	// 0x284CE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x284CE8: movss [0x0056AD64], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD64u, ctx.xmm[0].u32[0]);
	// 0x284CF0: ret
	return;
}

void sub_284D00(X86Context& ctx, uint8_t* base) {
	// 0x284D00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x284D08: movss [0x0056AD48], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD48u, ctx.xmm[0].u32[0]);
	// 0x284D10: ret
	return;
}

void sub_284D20(X86Context& ctx, uint8_t* base) {
	// 0x284D20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x284D28: movss [0x0056ACF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACF8u, ctx.xmm[0].u32[0]);
	// 0x284D30: ret
	return;
}

void sub_284D40(X86Context& ctx, uint8_t* base) {
	// 0x284D40: movss xmm0, dword ptr [0x0056AD10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD10u);
	// 0x284D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284D50: movss [0x0056ACEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACECu, ctx.xmm[0].u32[0]);
	// 0x284D58: ret
	return;
}

void sub_284D60(X86Context& ctx, uint8_t* base) {
	// 0x284D60: movss xmm0, dword ptr [0x0056AD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD64u);
	// 0x284D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x284D70: movss [0x0056AD30], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD30u, ctx.xmm[0].u32[0]);
	// 0x284D78: ret
	return;
}

void sub_284D80(X86Context& ctx, uint8_t* base) {
	// 0x284D80: movss xmm0, dword ptr [0x0056ACEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACECu);
	// 0x284D88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x284D90: movss [0x0056AD40], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD40u, ctx.xmm[0].u32[0]);
	// 0x284D98: ret
	return;
}

void sub_284DA0(X86Context& ctx, uint8_t* base) {
	// 0x284DA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x284DA8: movss [0x0056ACE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACE4u, ctx.xmm[0].u32[0]);
	// 0x284DB0: ret
	return;
}

void sub_284DC0(X86Context& ctx, uint8_t* base) {
	// 0x284DC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x284DC8: movss [0x0056AD14], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD14u, ctx.xmm[0].u32[0]);
	// 0x284DD0: ret
	return;
}

void sub_284DE0(X86Context& ctx, uint8_t* base) {
	// 0x284DE0: movss xmm0, dword ptr [0x0056AD10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD10u);
	// 0x284DE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x284DF0: movss [0x0056AD20], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD20u, ctx.xmm[0].u32[0]);
	// 0x284DF8: ret
	return;
}

void sub_284E00(X86Context& ctx, uint8_t* base) {
	// 0x284E00: movss xmm0, dword ptr [0x0056AD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD64u);
	// 0x284E08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x284E10: movss [0x0056AD68], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD68u, ctx.xmm[0].u32[0]);
	// 0x284E18: ret
	return;
}

void sub_284E20(X86Context& ctx, uint8_t* base) {
	// 0x284E20: movss xmm0, dword ptr [0x0056AD20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD20u);
	// 0x284E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284E30: movss [0x0056AD54], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD54u, ctx.xmm[0].u32[0]);
	// 0x284E38: ret
	return;
}

void sub_284E40(X86Context& ctx, uint8_t* base) {
	// 0x284E40: movss xmm0, dword ptr [0x0056AD68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD68u);
	// 0x284E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284E50: movss [0x0056AD78], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD78u, ctx.xmm[0].u32[0]);
	// 0x284E58: ret
	return;
}

void sub_284E60(X86Context& ctx, uint8_t* base) {
	// 0x284E60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x284E68: movss [0x0056ACF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACF0u, ctx.xmm[0].u32[0]);
	// 0x284E70: ret
	return;
}

void sub_284E80(X86Context& ctx, uint8_t* base) {
	// 0x284E80: movss xmm0, dword ptr [0x0056AD10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD10u);
	// 0x284E88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284E90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x284E98: movss [0x0056AD60], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD60u, ctx.xmm[0].u32[0]);
	// 0x284EA0: ret
	return;
}

void sub_284EB0(X86Context& ctx, uint8_t* base) {
	// 0x284EB0: movss xmm0, dword ptr [0x0056AD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD64u);
	// 0x284EB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284EC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x284EC8: movss [0x0056AD08], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD08u, ctx.xmm[0].u32[0]);
	// 0x284ED0: ret
	return;
}

void sub_284EE0(X86Context& ctx, uint8_t* base) {
	// 0x284EE0: movss xmm0, dword ptr [0x0056AD10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD10u);
	// 0x284EE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284EF0: movss [0x0056AD0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD0Cu, ctx.xmm[0].u32[0]);
	// 0x284EF8: ret
	return;
}

void sub_284F00(X86Context& ctx, uint8_t* base) {
	// 0x284F00: movss xmm0, dword ptr [0x0056AD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD64u);
	// 0x284F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x284F10: movss [0x0056AD6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD6Cu, ctx.xmm[0].u32[0]);
	// 0x284F18: ret
	return;
}

void sub_284F20(X86Context& ctx, uint8_t* base) {
	// 0x284F20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x284F28: movss [0x0056ACF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ACF4u, ctx.xmm[0].u32[0]);
	// 0x284F30: ret
	return;
}

void sub_284F40(X86Context& ctx, uint8_t* base) {
	// 0x284F40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x284F48: movss [0x0056AD1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD1Cu, ctx.xmm[0].u32[0]);
	// 0x284F50: ret
	return;
}

void sub_284F60(X86Context& ctx, uint8_t* base) {
	// 0x284F60: movss xmm0, dword ptr [0x0056ACF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ACF4u);
	// 0x284F68: movss [0x0056AD80], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD80u, ctx.xmm[0].u32[0]);
	// 0x284F70: ret
	return;
}

void sub_284F80(X86Context& ctx, uint8_t* base) {
	// 0x284F80: movss xmm0, dword ptr [0x0056AD64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD64u);
	// 0x284F88: subss xmm0, [0x0056ACF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ACF4u);
	// 0x284F90: movss [0x0056AD44], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD44u, ctx.xmm[0].u32[0]);
	// 0x284F98: ret
	return;
}

void sub_284FA0(X86Context& ctx, uint8_t* base) {
	// 0x284FA0: movss xmm0, dword ptr [0x0056AD44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD44u);
	// 0x284FA8: subss xmm0, [0x0056AD1C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AD1Cu);
	// 0x284FB0: movss [0x0056AD3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD3Cu, ctx.xmm[0].u32[0]);
	// 0x284FB8: ret
	return;
}

void sub_284FC0(X86Context& ctx, uint8_t* base) {
	// 0x284FC0: movss xmm0, dword ptr [0x0056AD6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD6Cu);
	// 0x284FC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x284FD0: movss [0x0056AD2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD2Cu, ctx.xmm[0].u32[0]);
	// 0x284FD8: ret
	return;
}

void sub_284FE0(X86Context& ctx, uint8_t* base) {
	// 0x284FE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x284FE8: movss [0x0056AD18], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD18u, ctx.xmm[0].u32[0]);
	// 0x284FF0: ret
	return;
}

void sub_285000(X86Context& ctx, uint8_t* base) {
	// 0x285000: movss xmm0, dword ptr [0x0056AD2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD2Cu);
	// 0x285008: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x285010: movss [0x0056AD5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD5Cu, ctx.xmm[0].u32[0]);
	// 0x285018: ret
	return;
}

void sub_285020(X86Context& ctx, uint8_t* base) {
	// 0x285020: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x285028: movss [0x0056ADE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADE0u, ctx.xmm[0].u32[0]);
	// 0x285030: ret
	return;
}

void sub_285040(X86Context& ctx, uint8_t* base) {
	// 0x285040: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x285048: movss [0x0056ADFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADFCu, ctx.xmm[0].u32[0]);
	// 0x285050: ret
	return;
}

void sub_285060(X86Context& ctx, uint8_t* base) {
	// 0x285060: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x285068: movss [0x0056ADD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADD4u, ctx.xmm[0].u32[0]);
	// 0x285070: ret
	return;
}

void sub_285080(X86Context& ctx, uint8_t* base) {
	// 0x285080: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x285088: movss [0x0056AD8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD8Cu, ctx.xmm[0].u32[0]);
	// 0x285090: ret
	return;
}

void sub_2850A0(X86Context& ctx, uint8_t* base) {
	// 0x2850A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2850A8: movss [0x0056ADE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADE4u, ctx.xmm[0].u32[0]);
	// 0x2850B0: ret
	return;
}

void sub_2850C0(X86Context& ctx, uint8_t* base) {
	// 0x2850C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2850C8: movss [0x0056ADA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADA8u, ctx.xmm[0].u32[0]);
	// 0x2850D0: ret
	return;
}

void sub_2850E0(X86Context& ctx, uint8_t* base) {
	// 0x2850E0: movss xmm0, dword ptr [0x0056ADE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADE4u);
	// 0x2850E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2850F0: movss [0x0056AE1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE1Cu, ctx.xmm[0].u32[0]);
	// 0x2850F8: ret
	return;
}

void sub_285100(X86Context& ctx, uint8_t* base) {
	// 0x285100: movss xmm0, dword ptr [0x0056ADA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADA8u);
	// 0x285108: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x285110: movss [0x0056AE04], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE04u, ctx.xmm[0].u32[0]);
	// 0x285118: ret
	return;
}

void sub_285120(X86Context& ctx, uint8_t* base) {
	// 0x285120: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x285128: movss [0x0056AE34], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE34u, ctx.xmm[0].u32[0]);
	// 0x285130: ret
	return;
}

void sub_285140(X86Context& ctx, uint8_t* base) {
	// 0x285140: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x285148: movss [0x0056AE20], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE20u, ctx.xmm[0].u32[0]);
	// 0x285150: ret
	return;
}

void sub_285160(X86Context& ctx, uint8_t* base) {
	// 0x285160: movss xmm0, dword ptr [0x0056AE20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE20u);
	// 0x285168: movss [0x0056AE30], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE30u, ctx.xmm[0].u32[0]);
	// 0x285170: ret
	return;
}

void sub_285180(X86Context& ctx, uint8_t* base) {
	// 0x285180: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x285188: movss [0x0056AD94], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD94u, ctx.xmm[0].u32[0]);
	// 0x285190: ret
	return;
}

void sub_2851A0(X86Context& ctx, uint8_t* base) {
	// 0x2851A0: movss xmm0, dword ptr [0x0056ADA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADA8u);
	// 0x2851A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2851B0: movss [0x0056AE28], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE28u, ctx.xmm[0].u32[0]);
	// 0x2851B8: ret
	return;
}

void sub_2851C0(X86Context& ctx, uint8_t* base) {
	// 0x2851C0: movss xmm0, dword ptr [0x0056ADA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADA8u);
	// 0x2851C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2851D0: movss [0x0056ADD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADD0u, ctx.xmm[0].u32[0]);
	// 0x2851D8: ret
	return;
}

void sub_2851E0(X86Context& ctx, uint8_t* base) {
	// 0x2851E0: movss xmm0, dword ptr [0x0056ADA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADA8u);
	// 0x2851E8: subss xmm0, [0x0056ADD0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ADD0u);
	// 0x2851F0: movss [0x0056ADB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADB0u, ctx.xmm[0].u32[0]);
	// 0x2851F8: ret
	return;
}

void sub_285200(X86Context& ctx, uint8_t* base) {
	// 0x285200: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x285208: movss [0x0056ADF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADF8u, ctx.xmm[0].u32[0]);
	// 0x285210: ret
	return;
}

void sub_285220(X86Context& ctx, uint8_t* base) {
	// 0x285220: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x285228: movss [0x0056ADAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADACu, ctx.xmm[0].u32[0]);
	// 0x285230: ret
	return;
}

void sub_285240(X86Context& ctx, uint8_t* base) {
	// 0x285240: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x285248: movss [0x0056ADBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADBCu, ctx.xmm[0].u32[0]);
	// 0x285250: ret
	return;
}

void sub_285260(X86Context& ctx, uint8_t* base) {
	// 0x285260: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x285268: movss [0x0056AE10], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE10u, ctx.xmm[0].u32[0]);
	// 0x285270: ret
	return;
}

void sub_285280(X86Context& ctx, uint8_t* base) {
	// 0x285280: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x285288: movss [0x0056ADF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADF4u, ctx.xmm[0].u32[0]);
	// 0x285290: ret
	return;
}

void sub_2852A0(X86Context& ctx, uint8_t* base) {
	// 0x2852A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2852A8: movss [0x0056ADA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADA4u, ctx.xmm[0].u32[0]);
	// 0x2852B0: ret
	return;
}

void sub_2852C0(X86Context& ctx, uint8_t* base) {
	// 0x2852C0: movss xmm0, dword ptr [0x0056ADBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADBCu);
	// 0x2852C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2852D0: movss [0x0056AD98], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD98u, ctx.xmm[0].u32[0]);
	// 0x2852D8: ret
	return;
}

void sub_2852E0(X86Context& ctx, uint8_t* base) {
	// 0x2852E0: movss xmm0, dword ptr [0x0056AE10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE10u);
	// 0x2852E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2852F0: movss [0x0056ADDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADDCu, ctx.xmm[0].u32[0]);
	// 0x2852F8: ret
	return;
}

void sub_285300(X86Context& ctx, uint8_t* base) {
	// 0x285300: movss xmm0, dword ptr [0x0056AD98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AD98u);
	// 0x285308: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285310: movss [0x0056ADEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADECu, ctx.xmm[0].u32[0]);
	// 0x285318: ret
	return;
}

void sub_285320(X86Context& ctx, uint8_t* base) {
	// 0x285320: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x285328: movss [0x0056AD90], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD90u, ctx.xmm[0].u32[0]);
	// 0x285330: ret
	return;
}

void sub_285340(X86Context& ctx, uint8_t* base) {
	// 0x285340: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x285348: movss [0x0056ADC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADC0u, ctx.xmm[0].u32[0]);
	// 0x285350: ret
	return;
}

void sub_285360(X86Context& ctx, uint8_t* base) {
	// 0x285360: movss xmm0, dword ptr [0x0056ADBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADBCu);
	// 0x285368: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x285370: movss [0x0056ADCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADCCu, ctx.xmm[0].u32[0]);
	// 0x285378: ret
	return;
}

void sub_285380(X86Context& ctx, uint8_t* base) {
	// 0x285380: movss xmm0, dword ptr [0x0056AE10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE10u);
	// 0x285388: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x285390: movss [0x0056AE14], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE14u, ctx.xmm[0].u32[0]);
	// 0x285398: ret
	return;
}

void sub_2853A0(X86Context& ctx, uint8_t* base) {
	// 0x2853A0: movss xmm0, dword ptr [0x0056ADCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADCCu);
	// 0x2853A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2853B0: movss [0x0056AE00], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE00u, ctx.xmm[0].u32[0]);
	// 0x2853B8: ret
	return;
}

void sub_2853C0(X86Context& ctx, uint8_t* base) {
	// 0x2853C0: movss xmm0, dword ptr [0x0056AE14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE14u);
	// 0x2853C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2853D0: movss [0x0056AE24], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE24u, ctx.xmm[0].u32[0]);
	// 0x2853D8: ret
	return;
}

void sub_2853E0(X86Context& ctx, uint8_t* base) {
	// 0x2853E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2853E8: movss [0x0056AD9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AD9Cu, ctx.xmm[0].u32[0]);
	// 0x2853F0: ret
	return;
}

void sub_285400(X86Context& ctx, uint8_t* base) {
	// 0x285400: movss xmm0, dword ptr [0x0056ADBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADBCu);
	// 0x285408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285410: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x285418: movss [0x0056AE0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE0Cu, ctx.xmm[0].u32[0]);
	// 0x285420: ret
	return;
}

void sub_285430(X86Context& ctx, uint8_t* base) {
	// 0x285430: movss xmm0, dword ptr [0x0056AE10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE10u);
	// 0x285438: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285440: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x285448: movss [0x0056ADB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADB4u, ctx.xmm[0].u32[0]);
	// 0x285450: ret
	return;
}

void sub_285460(X86Context& ctx, uint8_t* base) {
	// 0x285460: movss xmm0, dword ptr [0x0056ADBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADBCu);
	// 0x285468: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285470: movss [0x0056ADB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADB8u, ctx.xmm[0].u32[0]);
	// 0x285478: ret
	return;
}

void sub_285480(X86Context& ctx, uint8_t* base) {
	// 0x285480: movss xmm0, dword ptr [0x0056AE10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE10u);
	// 0x285488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x285490: movss [0x0056AE18], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE18u, ctx.xmm[0].u32[0]);
	// 0x285498: ret
	return;
}

void sub_2854A0(X86Context& ctx, uint8_t* base) {
	// 0x2854A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2854A8: movss [0x0056ADA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADA0u, ctx.xmm[0].u32[0]);
	// 0x2854B0: ret
	return;
}

void sub_2854C0(X86Context& ctx, uint8_t* base) {
	// 0x2854C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2854C8: movss [0x0056ADC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADC8u, ctx.xmm[0].u32[0]);
	// 0x2854D0: ret
	return;
}

void sub_2854E0(X86Context& ctx, uint8_t* base) {
	// 0x2854E0: movss xmm0, dword ptr [0x0056ADA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADA0u);
	// 0x2854E8: movss [0x0056AE2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE2Cu, ctx.xmm[0].u32[0]);
	// 0x2854F0: ret
	return;
}

void sub_285500(X86Context& ctx, uint8_t* base) {
	// 0x285500: movss xmm0, dword ptr [0x0056AE10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE10u);
	// 0x285508: subss xmm0, [0x0056ADA0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ADA0u);
	// 0x285510: movss [0x0056ADF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADF0u, ctx.xmm[0].u32[0]);
	// 0x285518: ret
	return;
}

void sub_285520(X86Context& ctx, uint8_t* base) {
	// 0x285520: movss xmm0, dword ptr [0x0056ADF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADF0u);
	// 0x285528: subss xmm0, [0x0056ADC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ADC8u);
	// 0x285530: movss [0x0056ADE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADE8u, ctx.xmm[0].u32[0]);
	// 0x285538: ret
	return;
}

void sub_285540(X86Context& ctx, uint8_t* base) {
	// 0x285540: movss xmm0, dword ptr [0x0056AE18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE18u);
	// 0x285548: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x285550: movss [0x0056ADD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADD8u, ctx.xmm[0].u32[0]);
	// 0x285558: ret
	return;
}

void sub_285560(X86Context& ctx, uint8_t* base) {
	// 0x285560: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x285568: movss [0x0056ADC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ADC4u, ctx.xmm[0].u32[0]);
	// 0x285570: ret
	return;
}

void sub_285580(X86Context& ctx, uint8_t* base) {
	// 0x285580: movss xmm0, dword ptr [0x0056ADD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ADD8u);
	// 0x285588: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x285590: movss [0x0056AE08], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE08u, ctx.xmm[0].u32[0]);
	// 0x285598: ret
	return;
}

void sub_2855A0(X86Context& ctx, uint8_t* base) {
	// 0x2855A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2855A8: movss [0x0056AE8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE8Cu, ctx.xmm[0].u32[0]);
	// 0x2855B0: ret
	return;
}

void sub_2855C0(X86Context& ctx, uint8_t* base) {
	// 0x2855C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2855C8: movss [0x0056AEA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEA8u, ctx.xmm[0].u32[0]);
	// 0x2855D0: ret
	return;
}

void sub_2855E0(X86Context& ctx, uint8_t* base) {
	// 0x2855E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2855E8: movss [0x0056AE80], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE80u, ctx.xmm[0].u32[0]);
	// 0x2855F0: ret
	return;
}

void sub_285600(X86Context& ctx, uint8_t* base) {
	// 0x285600: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x285608: movss [0x0056AE38], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE38u, ctx.xmm[0].u32[0]);
	// 0x285610: ret
	return;
}

void sub_285620(X86Context& ctx, uint8_t* base) {
	// 0x285620: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x285628: movss [0x0056AE90], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE90u, ctx.xmm[0].u32[0]);
	// 0x285630: ret
	return;
}

void sub_285640(X86Context& ctx, uint8_t* base) {
	// 0x285640: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x285648: movss [0x0056AE54], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE54u, ctx.xmm[0].u32[0]);
	// 0x285650: ret
	return;
}

void sub_285660(X86Context& ctx, uint8_t* base) {
	// 0x285660: movss xmm0, dword ptr [0x0056AE90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE90u);
	// 0x285668: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285670: movss [0x0056AEC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEC8u, ctx.xmm[0].u32[0]);
	// 0x285678: ret
	return;
}

void sub_285680(X86Context& ctx, uint8_t* base) {
	// 0x285680: movss xmm0, dword ptr [0x0056AE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE54u);
	// 0x285688: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x285690: movss [0x0056AEB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEB0u, ctx.xmm[0].u32[0]);
	// 0x285698: ret
	return;
}

void sub_2856A0(X86Context& ctx, uint8_t* base) {
	// 0x2856A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2856A8: movss [0x0056AEE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEE0u, ctx.xmm[0].u32[0]);
	// 0x2856B0: ret
	return;
}

void sub_2856C0(X86Context& ctx, uint8_t* base) {
	// 0x2856C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2856C8: movss [0x0056AECC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AECCu, ctx.xmm[0].u32[0]);
	// 0x2856D0: ret
	return;
}

void sub_2856E0(X86Context& ctx, uint8_t* base) {
	// 0x2856E0: movss xmm0, dword ptr [0x0056AECC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AECCu);
	// 0x2856E8: movss [0x0056AEDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEDCu, ctx.xmm[0].u32[0]);
	// 0x2856F0: ret
	return;
}

void sub_285700(X86Context& ctx, uint8_t* base) {
	// 0x285700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x285708: movss [0x0056AE40], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE40u, ctx.xmm[0].u32[0]);
	// 0x285710: ret
	return;
}

void sub_285720(X86Context& ctx, uint8_t* base) {
	// 0x285720: movss xmm0, dword ptr [0x0056AE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE54u);
	// 0x285728: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x285730: movss [0x0056AED4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AED4u, ctx.xmm[0].u32[0]);
	// 0x285738: ret
	return;
}

void sub_285740(X86Context& ctx, uint8_t* base) {
	// 0x285740: movss xmm0, dword ptr [0x0056AE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE54u);
	// 0x285748: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x285750: movss [0x0056AE7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE7Cu, ctx.xmm[0].u32[0]);
	// 0x285758: ret
	return;
}

void sub_285760(X86Context& ctx, uint8_t* base) {
	// 0x285760: movss xmm0, dword ptr [0x0056AE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE54u);
	// 0x285768: subss xmm0, [0x0056AE7C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AE7Cu);
	// 0x285770: movss [0x0056AE5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE5Cu, ctx.xmm[0].u32[0]);
	// 0x285778: ret
	return;
}

void sub_285780(X86Context& ctx, uint8_t* base) {
	// 0x285780: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x285788: movss [0x0056AEA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEA4u, ctx.xmm[0].u32[0]);
	// 0x285790: ret
	return;
}

void sub_2857A0(X86Context& ctx, uint8_t* base) {
	// 0x2857A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2857A8: movss [0x0056AE58], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE58u, ctx.xmm[0].u32[0]);
	// 0x2857B0: ret
	return;
}

void sub_2857C0(X86Context& ctx, uint8_t* base) {
	// 0x2857C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2857C8: movss [0x0056AE68], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE68u, ctx.xmm[0].u32[0]);
	// 0x2857D0: ret
	return;
}

void sub_2857E0(X86Context& ctx, uint8_t* base) {
	// 0x2857E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2857E8: movss [0x0056AEBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEBCu, ctx.xmm[0].u32[0]);
	// 0x2857F0: ret
	return;
}

void sub_285800(X86Context& ctx, uint8_t* base) {
	// 0x285800: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x285808: movss [0x0056AEA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AEA0u, ctx.xmm[0].u32[0]);
	// 0x285810: ret
	return;
}

void sub_285820(X86Context& ctx, uint8_t* base) {
	// 0x285820: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x285828: movss [0x0056AE50], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE50u, ctx.xmm[0].u32[0]);
	// 0x285830: ret
	return;
}

void sub_285840(X86Context& ctx, uint8_t* base) {
	// 0x285840: movss xmm0, dword ptr [0x0056AE68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE68u);
	// 0x285848: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285850: movss [0x0056AE44], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE44u, ctx.xmm[0].u32[0]);
	// 0x285858: ret
	return;
}

void sub_285860(X86Context& ctx, uint8_t* base) {
	// 0x285860: movss xmm0, dword ptr [0x0056AEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AEBCu);
	// 0x285868: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x285870: movss [0x0056AE88], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE88u, ctx.xmm[0].u32[0]);
	// 0x285878: ret
	return;
}

void sub_285880(X86Context& ctx, uint8_t* base) {
	// 0x285880: movss xmm0, dword ptr [0x0056AE44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AE44u);
	// 0x285888: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x285890: movss [0x0056AE98], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE98u, ctx.xmm[0].u32[0]);
	// 0x285898: ret
	return;
}

void sub_2858A0(X86Context& ctx, uint8_t* base) {
	// 0x2858A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2858A8: movss [0x0056AE3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AE3Cu, ctx.xmm[0].u32[0]);
	// 0x2858B0: ret
	return;
}

