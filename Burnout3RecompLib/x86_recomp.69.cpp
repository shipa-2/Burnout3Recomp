#include "x86_recomp_shared.h"

void sub_2ACB20(X86Context& ctx, uint8_t* base) {
	// 0x2ACB20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ACB28: movss [0x00571164], xmm0
	X86_MEM_WRITE_u32(base, 0x571164u, ctx.xmm[0].u32[0]);
	// 0x2ACB30: ret
	return;
}

void sub_2ACB40(X86Context& ctx, uint8_t* base) {
	// 0x2ACB40: movss xmm0, dword ptr [0x00571140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571140u);
	// 0x2ACB48: movss [0x00407D60], xmm0
	X86_MEM_WRITE_u32(base, 0x407D60u, ctx.xmm[0].u32[0]);
	// 0x2ACB50: ret
	return;
}

void sub_2ACB60(X86Context& ctx, uint8_t* base) {
	// 0x2ACB60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2ACB68: movss [0x00571290], xmm0
	X86_MEM_WRITE_u32(base, 0x571290u, ctx.xmm[0].u32[0]);
	// 0x2ACB70: ret
	return;
}

void sub_2ACB80(X86Context& ctx, uint8_t* base) {
	// 0x2ACB80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2ACB88: movss [0x005712B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5712B0u, ctx.xmm[0].u32[0]);
	// 0x2ACB90: ret
	return;
}

void sub_2ACBA0(X86Context& ctx, uint8_t* base) {
	// 0x2ACBA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2ACBA8: movss [0x00571280], xmm0
	X86_MEM_WRITE_u32(base, 0x571280u, ctx.xmm[0].u32[0]);
	// 0x2ACBB0: ret
	return;
}

void sub_2ACBC0(X86Context& ctx, uint8_t* base) {
	// 0x2ACBC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2ACBC8: movss [0x00571238], xmm0
	X86_MEM_WRITE_u32(base, 0x571238u, ctx.xmm[0].u32[0]);
	// 0x2ACBD0: ret
	return;
}

void sub_2ACBE0(X86Context& ctx, uint8_t* base) {
	// 0x2ACBE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2ACBE8: movss [0x00571294], xmm0
	X86_MEM_WRITE_u32(base, 0x571294u, ctx.xmm[0].u32[0]);
	// 0x2ACBF0: ret
	return;
}

void sub_2ACC00(X86Context& ctx, uint8_t* base) {
	// 0x2ACC00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2ACC08: movss [0x00571254], xmm0
	X86_MEM_WRITE_u32(base, 0x571254u, ctx.xmm[0].u32[0]);
	// 0x2ACC10: ret
	return;
}

void sub_2ACC20(X86Context& ctx, uint8_t* base) {
	// 0x2ACC20: movss xmm0, dword ptr [0x00571294]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571294u);
	// 0x2ACC28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ACC30: movss [0x005712D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5712D0u, ctx.xmm[0].u32[0]);
	// 0x2ACC38: ret
	return;
}

void sub_2ACC40(X86Context& ctx, uint8_t* base) {
	// 0x2ACC40: movss xmm0, dword ptr [0x00571254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571254u);
	// 0x2ACC48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ACC50: movss [0x005712B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5712B8u, ctx.xmm[0].u32[0]);
	// 0x2ACC58: ret
	return;
}

void sub_2ACC60(X86Context& ctx, uint8_t* base) {
	// 0x2ACC60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ACC68: movss [0x005712EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5712ECu, ctx.xmm[0].u32[0]);
	// 0x2ACC70: ret
	return;
}

void sub_2ACC80(X86Context& ctx, uint8_t* base) {
	// 0x2ACC80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2ACC88: movss [0x005712D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5712D4u, ctx.xmm[0].u32[0]);
	// 0x2ACC90: ret
	return;
}

void sub_2ACCA0(X86Context& ctx, uint8_t* base) {
	// 0x2ACCA0: movss xmm0, dword ptr [0x005712D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712D4u);
	// 0x2ACCA8: movss [0x005712E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5712E8u, ctx.xmm[0].u32[0]);
	// 0x2ACCB0: ret
	return;
}

void sub_2ACCC0(X86Context& ctx, uint8_t* base) {
	// 0x2ACCC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ACCC8: movss [0x00571240], xmm0
	X86_MEM_WRITE_u32(base, 0x571240u, ctx.xmm[0].u32[0]);
	// 0x2ACCD0: ret
	return;
}

void sub_2ACCE0(X86Context& ctx, uint8_t* base) {
	// 0x2ACCE0: movss xmm0, dword ptr [0x00571254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571254u);
	// 0x2ACCE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2ACCF0: movss [0x005712E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5712E0u, ctx.xmm[0].u32[0]);
	// 0x2ACCF8: ret
	return;
}

void sub_2ACD00(X86Context& ctx, uint8_t* base) {
	// 0x2ACD00: movss xmm0, dword ptr [0x00571254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571254u);
	// 0x2ACD08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2ACD10: movss [0x0057127C], xmm0
	X86_MEM_WRITE_u32(base, 0x57127Cu, ctx.xmm[0].u32[0]);
	// 0x2ACD18: ret
	return;
}

void sub_2ACD20(X86Context& ctx, uint8_t* base) {
	// 0x2ACD20: movss xmm0, dword ptr [0x00571254]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571254u);
	// 0x2ACD28: subss xmm0, [0x0057127C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57127Cu);
	// 0x2ACD30: movss [0x0057125C], xmm0
	X86_MEM_WRITE_u32(base, 0x57125Cu, ctx.xmm[0].u32[0]);
	// 0x2ACD38: ret
	return;
}

void sub_2ACD40(X86Context& ctx, uint8_t* base) {
	// 0x2ACD40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2ACD48: movss [0x005712AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5712ACu, ctx.xmm[0].u32[0]);
	// 0x2ACD50: ret
	return;
}

void sub_2ACD60(X86Context& ctx, uint8_t* base) {
	// 0x2ACD60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2ACD68: movss [0x00571258], xmm0
	X86_MEM_WRITE_u32(base, 0x571258u, ctx.xmm[0].u32[0]);
	// 0x2ACD70: ret
	return;
}

void sub_2ACD80(X86Context& ctx, uint8_t* base) {
	// 0x2ACD80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2ACD88: movss [0x00571268], xmm0
	X86_MEM_WRITE_u32(base, 0x571268u, ctx.xmm[0].u32[0]);
	// 0x2ACD90: ret
	return;
}

void sub_2ACDA0(X86Context& ctx, uint8_t* base) {
	// 0x2ACDA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2ACDA8: movss [0x005712C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5712C4u, ctx.xmm[0].u32[0]);
	// 0x2ACDB0: ret
	return;
}

void sub_2ACDC0(X86Context& ctx, uint8_t* base) {
	// 0x2ACDC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2ACDC8: movss [0x005712A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5712A8u, ctx.xmm[0].u32[0]);
	// 0x2ACDD0: ret
	return;
}

void sub_2ACDE0(X86Context& ctx, uint8_t* base) {
	// 0x2ACDE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2ACDE8: movss [0x00571250], xmm0
	X86_MEM_WRITE_u32(base, 0x571250u, ctx.xmm[0].u32[0]);
	// 0x2ACDF0: ret
	return;
}

void sub_2ACE00(X86Context& ctx, uint8_t* base) {
	// 0x2ACE00: movss xmm0, dword ptr [0x00571268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571268u);
	// 0x2ACE08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ACE10: movss [0x00571244], xmm0
	X86_MEM_WRITE_u32(base, 0x571244u, ctx.xmm[0].u32[0]);
	// 0x2ACE18: ret
	return;
}

void sub_2ACE20(X86Context& ctx, uint8_t* base) {
	// 0x2ACE20: movss xmm0, dword ptr [0x005712C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C4u);
	// 0x2ACE28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ACE30: movss [0x0057128C], xmm0
	X86_MEM_WRITE_u32(base, 0x57128Cu, ctx.xmm[0].u32[0]);
	// 0x2ACE38: ret
	return;
}

void sub_2ACE40(X86Context& ctx, uint8_t* base) {
	// 0x2ACE40: movss xmm0, dword ptr [0x00571244]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571244u);
	// 0x2ACE48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ACE50: movss [0x0057129C], xmm0
	X86_MEM_WRITE_u32(base, 0x57129Cu, ctx.xmm[0].u32[0]);
	// 0x2ACE58: ret
	return;
}

void sub_2ACE60(X86Context& ctx, uint8_t* base) {
	// 0x2ACE60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ACE68: movss [0x0057123C], xmm0
	X86_MEM_WRITE_u32(base, 0x57123Cu, ctx.xmm[0].u32[0]);
	// 0x2ACE70: ret
	return;
}

void sub_2ACE80(X86Context& ctx, uint8_t* base) {
	// 0x2ACE80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ACE88: movss [0x0057126C], xmm0
	X86_MEM_WRITE_u32(base, 0x57126Cu, ctx.xmm[0].u32[0]);
	// 0x2ACE90: ret
	return;
}

void sub_2ACEA0(X86Context& ctx, uint8_t* base) {
	// 0x2ACEA0: movss xmm0, dword ptr [0x00571268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571268u);
	// 0x2ACEA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ACEB0: movss [0x00571278], xmm0
	X86_MEM_WRITE_u32(base, 0x571278u, ctx.xmm[0].u32[0]);
	// 0x2ACEB8: ret
	return;
}

void sub_2ACEC0(X86Context& ctx, uint8_t* base) {
	// 0x2ACEC0: movss xmm0, dword ptr [0x005712C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C4u);
	// 0x2ACEC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ACED0: movss [0x005712C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5712C8u, ctx.xmm[0].u32[0]);
	// 0x2ACED8: ret
	return;
}

void sub_2ACEE0(X86Context& ctx, uint8_t* base) {
	// 0x2ACEE0: movss xmm0, dword ptr [0x00571278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571278u);
	// 0x2ACEE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ACEF0: movss [0x005712B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5712B4u, ctx.xmm[0].u32[0]);
	// 0x2ACEF8: ret
	return;
}

void sub_2ACF00(X86Context& ctx, uint8_t* base) {
	// 0x2ACF00: movss xmm0, dword ptr [0x005712C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C8u);
	// 0x2ACF08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ACF10: movss [0x005712D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5712D8u, ctx.xmm[0].u32[0]);
	// 0x2ACF18: ret
	return;
}

void sub_2ACF20(X86Context& ctx, uint8_t* base) {
	// 0x2ACF20: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2ACF28: movss [0x00571248], xmm0
	X86_MEM_WRITE_u32(base, 0x571248u, ctx.xmm[0].u32[0]);
	// 0x2ACF30: ret
	return;
}

void sub_2ACF40(X86Context& ctx, uint8_t* base) {
	// 0x2ACF40: movss xmm0, dword ptr [0x00571268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571268u);
	// 0x2ACF48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ACF50: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2ACF58: movss [0x005712C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5712C0u, ctx.xmm[0].u32[0]);
	// 0x2ACF60: ret
	return;
}

void sub_2ACF70(X86Context& ctx, uint8_t* base) {
	// 0x2ACF70: movss xmm0, dword ptr [0x005712C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C4u);
	// 0x2ACF78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ACF80: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2ACF88: movss [0x00571260], xmm0
	X86_MEM_WRITE_u32(base, 0x571260u, ctx.xmm[0].u32[0]);
	// 0x2ACF90: ret
	return;
}

void sub_2ACFA0(X86Context& ctx, uint8_t* base) {
	// 0x2ACFA0: movss xmm0, dword ptr [0x00571268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571268u);
	// 0x2ACFA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ACFB0: movss [0x00571264], xmm0
	X86_MEM_WRITE_u32(base, 0x571264u, ctx.xmm[0].u32[0]);
	// 0x2ACFB8: ret
	return;
}

void sub_2ACFC0(X86Context& ctx, uint8_t* base) {
	// 0x2ACFC0: movss xmm0, dword ptr [0x005712C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C4u);
	// 0x2ACFC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ACFD0: movss [0x005712CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5712CCu, ctx.xmm[0].u32[0]);
	// 0x2ACFD8: ret
	return;
}

void sub_2ACFE0(X86Context& ctx, uint8_t* base) {
	// 0x2ACFE0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2ACFE8: movss [0x0057124C], xmm0
	X86_MEM_WRITE_u32(base, 0x57124Cu, ctx.xmm[0].u32[0]);
	// 0x2ACFF0: ret
	return;
}

void sub_2AD000(X86Context& ctx, uint8_t* base) {
	// 0x2AD000: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AD008: movss [0x00571274], xmm0
	X86_MEM_WRITE_u32(base, 0x571274u, ctx.xmm[0].u32[0]);
	// 0x2AD010: ret
	return;
}

void sub_2AD020(X86Context& ctx, uint8_t* base) {
	// 0x2AD020: movss xmm0, dword ptr [0x0057124C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57124Cu);
	// 0x2AD028: movss [0x005712E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5712E4u, ctx.xmm[0].u32[0]);
	// 0x2AD030: ret
	return;
}

void sub_2AD040(X86Context& ctx, uint8_t* base) {
	// 0x2AD040: movss xmm0, dword ptr [0x005712C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C4u);
	// 0x2AD048: subss xmm0, [0x0057124C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57124Cu);
	// 0x2AD050: movss [0x005712A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5712A4u, ctx.xmm[0].u32[0]);
	// 0x2AD058: ret
	return;
}

void sub_2AD060(X86Context& ctx, uint8_t* base) {
	// 0x2AD060: movss xmm0, dword ptr [0x005712A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712A4u);
	// 0x2AD068: subss xmm0, [0x00571274]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571274u);
	// 0x2AD070: movss [0x00571298], xmm0
	X86_MEM_WRITE_u32(base, 0x571298u, ctx.xmm[0].u32[0]);
	// 0x2AD078: ret
	return;
}

void sub_2AD080(X86Context& ctx, uint8_t* base) {
	// 0x2AD080: movss xmm0, dword ptr [0x005712CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712CCu);
	// 0x2AD088: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AD090: movss [0x00571284], xmm0
	X86_MEM_WRITE_u32(base, 0x571284u, ctx.xmm[0].u32[0]);
	// 0x2AD098: ret
	return;
}

void sub_2AD0A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD0A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AD0A8: movss [0x00571270], xmm0
	X86_MEM_WRITE_u32(base, 0x571270u, ctx.xmm[0].u32[0]);
	// 0x2AD0B0: ret
	return;
}

void sub_2AD0C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD0C0: movss xmm0, dword ptr [0x00571284]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571284u);
	// 0x2AD0C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AD0D0: movss [0x005712BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5712BCu, ctx.xmm[0].u32[0]);
	// 0x2AD0D8: ret
	return;
}

void sub_2AD0E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD0E0: movss xmm0, dword ptr [0x005712C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712C4u);
	// 0x2AD0E8: addss xmm0, [0x003B17C8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B17C8u);
	// 0x2AD0F0: movss [0x00571288], xmm0
	X86_MEM_WRITE_u32(base, 0x571288u, ctx.xmm[0].u32[0]);
	// 0x2AD0F8: ret
	return;
}

void sub_2AD100(X86Context& ctx, uint8_t* base) {
	// 0x2AD100: movss xmm0, dword ptr [0x00395BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2AD108: movss [0x005712A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5712A0u, ctx.xmm[0].u32[0]);
	// 0x2AD110: ret
	return;
}

void sub_2AD120(X86Context& ctx, uint8_t* base) {
	// 0x2AD120: movss xmm0, dword ptr [0x00395BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2AD128: movss [0x005712DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5712DCu, ctx.xmm[0].u32[0]);
	// 0x2AD130: ret
	return;
}

void sub_2AD140(X86Context& ctx, uint8_t* base) {
	// 0x2AD140: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AD148: movss [0x0057135C], xmm0
	X86_MEM_WRITE_u32(base, 0x57135Cu, ctx.xmm[0].u32[0]);
	// 0x2AD150: ret
	return;
}

void sub_2AD160(X86Context& ctx, uint8_t* base) {
	// 0x2AD160: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AD168: movss [0x00571380], xmm0
	X86_MEM_WRITE_u32(base, 0x571380u, ctx.xmm[0].u32[0]);
	// 0x2AD170: ret
	return;
}

void sub_2AD180(X86Context& ctx, uint8_t* base) {
	// 0x2AD180: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AD188: movss [0x00571344], xmm0
	X86_MEM_WRITE_u32(base, 0x571344u, ctx.xmm[0].u32[0]);
	// 0x2AD190: ret
	return;
}

void sub_2AD1A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD1A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AD1A8: movss [0x005712F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5712F0u, ctx.xmm[0].u32[0]);
	// 0x2AD1B0: ret
	return;
}

void sub_2AD1C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD1C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AD1C8: movss [0x00571360], xmm0
	X86_MEM_WRITE_u32(base, 0x571360u, ctx.xmm[0].u32[0]);
	// 0x2AD1D0: ret
	return;
}

void sub_2AD1E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD1E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AD1E8: movss [0x0057130C], xmm0
	X86_MEM_WRITE_u32(base, 0x57130Cu, ctx.xmm[0].u32[0]);
	// 0x2AD1F0: ret
	return;
}

void sub_2AD200(X86Context& ctx, uint8_t* base) {
	// 0x2AD200: movss xmm0, dword ptr [0x00571360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571360u);
	// 0x2AD208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AD210: movss [0x005713A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5713A4u, ctx.xmm[0].u32[0]);
	// 0x2AD218: ret
	return;
}

void sub_2AD220(X86Context& ctx, uint8_t* base) {
	// 0x2AD220: movss xmm0, dword ptr [0x0057130C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57130Cu);
	// 0x2AD228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AD230: movss [0x00571388], xmm0
	X86_MEM_WRITE_u32(base, 0x571388u, ctx.xmm[0].u32[0]);
	// 0x2AD238: ret
	return;
}

void sub_2AD240(X86Context& ctx, uint8_t* base) {
	// 0x2AD240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AD248: movss [0x005713BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5713BCu, ctx.xmm[0].u32[0]);
	// 0x2AD250: ret
	return;
}

void sub_2AD260(X86Context& ctx, uint8_t* base) {
	// 0x2AD260: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AD268: movss [0x005713A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5713A8u, ctx.xmm[0].u32[0]);
	// 0x2AD270: ret
	return;
}

void sub_2AD280(X86Context& ctx, uint8_t* base) {
	// 0x2AD280: movss xmm0, dword ptr [0x005713A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713A8u);
	// 0x2AD288: movss [0x005713B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5713B8u, ctx.xmm[0].u32[0]);
	// 0x2AD290: ret
	return;
}

void sub_2AD2A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD2A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AD2A8: movss [0x005712F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5712F8u, ctx.xmm[0].u32[0]);
	// 0x2AD2B0: ret
	return;
}

void sub_2AD2C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD2C0: movss xmm0, dword ptr [0x0057130C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57130Cu);
	// 0x2AD2C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AD2D0: movss [0x005713B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5713B0u, ctx.xmm[0].u32[0]);
	// 0x2AD2D8: ret
	return;
}

void sub_2AD2E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD2E0: movss xmm0, dword ptr [0x0057130C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57130Cu);
	// 0x2AD2E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AD2F0: movss [0x00571340], xmm0
	X86_MEM_WRITE_u32(base, 0x571340u, ctx.xmm[0].u32[0]);
	// 0x2AD2F8: ret
	return;
}

void sub_2AD300(X86Context& ctx, uint8_t* base) {
	// 0x2AD300: movss xmm0, dword ptr [0x0057130C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57130Cu);
	// 0x2AD308: subss xmm0, [0x00571340]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571340u);
	// 0x2AD310: movss [0x00571314], xmm0
	X86_MEM_WRITE_u32(base, 0x571314u, ctx.xmm[0].u32[0]);
	// 0x2AD318: ret
	return;
}

void sub_2AD320(X86Context& ctx, uint8_t* base) {
	// 0x2AD320: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AD328: movss [0x0057137C], xmm0
	X86_MEM_WRITE_u32(base, 0x57137Cu, ctx.xmm[0].u32[0]);
	// 0x2AD330: ret
	return;
}

void sub_2AD340(X86Context& ctx, uint8_t* base) {
	// 0x2AD340: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AD348: movss [0x00571310], xmm0
	X86_MEM_WRITE_u32(base, 0x571310u, ctx.xmm[0].u32[0]);
	// 0x2AD350: ret
	return;
}

void sub_2AD360(X86Context& ctx, uint8_t* base) {
	// 0x2AD360: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AD368: movss [0x0057132C], xmm0
	X86_MEM_WRITE_u32(base, 0x57132Cu, ctx.xmm[0].u32[0]);
	// 0x2AD370: ret
	return;
}

void sub_2AD380(X86Context& ctx, uint8_t* base) {
	// 0x2AD380: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AD388: movss [0x00571398], xmm0
	X86_MEM_WRITE_u32(base, 0x571398u, ctx.xmm[0].u32[0]);
	// 0x2AD390: ret
	return;
}

void sub_2AD3A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD3A0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AD3A8: movss [0x00571378], xmm0
	X86_MEM_WRITE_u32(base, 0x571378u, ctx.xmm[0].u32[0]);
	// 0x2AD3B0: ret
	return;
}

void sub_2AD3C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD3C0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AD3C8: movss [0x00571308], xmm0
	X86_MEM_WRITE_u32(base, 0x571308u, ctx.xmm[0].u32[0]);
	// 0x2AD3D0: ret
	return;
}

void sub_2AD3E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD3E0: movss xmm0, dword ptr [0x0057132C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57132Cu);
	// 0x2AD3E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AD3F0: movss [0x005712FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5712FCu, ctx.xmm[0].u32[0]);
	// 0x2AD3F8: ret
	return;
}

void sub_2AD400(X86Context& ctx, uint8_t* base) {
	// 0x2AD400: movss xmm0, dword ptr [0x00571398]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571398u);
	// 0x2AD408: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AD410: movss [0x00571358], xmm0
	X86_MEM_WRITE_u32(base, 0x571358u, ctx.xmm[0].u32[0]);
	// 0x2AD418: ret
	return;
}

void sub_2AD420(X86Context& ctx, uint8_t* base) {
	// 0x2AD420: movss xmm0, dword ptr [0x005712FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5712FCu);
	// 0x2AD428: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AD430: movss [0x00571370], xmm0
	X86_MEM_WRITE_u32(base, 0x571370u, ctx.xmm[0].u32[0]);
	// 0x2AD438: ret
	return;
}

void sub_2AD440(X86Context& ctx, uint8_t* base) {
	// 0x2AD440: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AD448: movss [0x005712F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5712F4u, ctx.xmm[0].u32[0]);
	// 0x2AD450: ret
	return;
}

void sub_2AD460(X86Context& ctx, uint8_t* base) {
	// 0x2AD460: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AD468: movss [0x00571330], xmm0
	X86_MEM_WRITE_u32(base, 0x571330u, ctx.xmm[0].u32[0]);
	// 0x2AD470: ret
	return;
}

void sub_2AD480(X86Context& ctx, uint8_t* base) {
	// 0x2AD480: movss xmm0, dword ptr [0x0057132C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57132Cu);
	// 0x2AD488: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AD490: movss [0x0057133C], xmm0
	X86_MEM_WRITE_u32(base, 0x57133Cu, ctx.xmm[0].u32[0]);
	// 0x2AD498: ret
	return;
}

void sub_2AD4A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD4A0: movss xmm0, dword ptr [0x00571398]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571398u);
	// 0x2AD4A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AD4B0: movss [0x0057139C], xmm0
	X86_MEM_WRITE_u32(base, 0x57139Cu, ctx.xmm[0].u32[0]);
	// 0x2AD4B8: ret
	return;
}

void sub_2AD4C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD4C0: movss xmm0, dword ptr [0x0057133C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57133Cu);
	// 0x2AD4C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AD4D0: movss [0x00571384], xmm0
	X86_MEM_WRITE_u32(base, 0x571384u, ctx.xmm[0].u32[0]);
	// 0x2AD4D8: ret
	return;
}

void sub_2AD4E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD4E0: movss xmm0, dword ptr [0x0057139C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57139Cu);
	// 0x2AD4E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AD4F0: movss [0x005713AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5713ACu, ctx.xmm[0].u32[0]);
	// 0x2AD4F8: ret
	return;
}

void sub_2AD500(X86Context& ctx, uint8_t* base) {
	// 0x2AD500: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AD508: movss [0x00571300], xmm0
	X86_MEM_WRITE_u32(base, 0x571300u, ctx.xmm[0].u32[0]);
	// 0x2AD510: ret
	return;
}

void sub_2AD520(X86Context& ctx, uint8_t* base) {
	// 0x2AD520: movss xmm0, dword ptr [0x0057132C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57132Cu);
	// 0x2AD528: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AD530: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AD538: movss [0x00571390], xmm0
	X86_MEM_WRITE_u32(base, 0x571390u, ctx.xmm[0].u32[0]);
	// 0x2AD540: ret
	return;
}

void sub_2AD550(X86Context& ctx, uint8_t* base) {
	// 0x2AD550: movss xmm0, dword ptr [0x00571398]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571398u);
	// 0x2AD558: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AD560: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AD568: movss [0x00571320], xmm0
	X86_MEM_WRITE_u32(base, 0x571320u, ctx.xmm[0].u32[0]);
	// 0x2AD570: ret
	return;
}

void sub_2AD580(X86Context& ctx, uint8_t* base) {
	// 0x2AD580: movss xmm0, dword ptr [0x0057132C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57132Cu);
	// 0x2AD588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AD590: movss [0x00571324], xmm0
	X86_MEM_WRITE_u32(base, 0x571324u, ctx.xmm[0].u32[0]);
	// 0x2AD598: ret
	return;
}

void sub_2AD5A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD5A0: movss xmm0, dword ptr [0x00571398]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571398u);
	// 0x2AD5A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AD5B0: movss [0x005713A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5713A0u, ctx.xmm[0].u32[0]);
	// 0x2AD5B8: ret
	return;
}

void sub_2AD5C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD5C0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AD5C8: movss [0x00571304], xmm0
	X86_MEM_WRITE_u32(base, 0x571304u, ctx.xmm[0].u32[0]);
	// 0x2AD5D0: ret
	return;
}

void sub_2AD5E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD5E0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AD5E8: movss [0x00571338], xmm0
	X86_MEM_WRITE_u32(base, 0x571338u, ctx.xmm[0].u32[0]);
	// 0x2AD5F0: ret
	return;
}

void sub_2AD600(X86Context& ctx, uint8_t* base) {
	// 0x2AD600: movss xmm0, dword ptr [0x00571304]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571304u);
	// 0x2AD608: movss [0x005713B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5713B4u, ctx.xmm[0].u32[0]);
	// 0x2AD610: ret
	return;
}

void sub_2AD620(X86Context& ctx, uint8_t* base) {
	// 0x2AD620: movss xmm0, dword ptr [0x00571398]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571398u);
	// 0x2AD628: subss xmm0, [0x00571304]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571304u);
	// 0x2AD630: movss [0x00571374], xmm0
	X86_MEM_WRITE_u32(base, 0x571374u, ctx.xmm[0].u32[0]);
	// 0x2AD638: ret
	return;
}

void sub_2AD640(X86Context& ctx, uint8_t* base) {
	// 0x2AD640: movss xmm0, dword ptr [0x00571374]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571374u);
	// 0x2AD648: subss xmm0, [0x00571338]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571338u);
	// 0x2AD650: movss [0x0057136C], xmm0
	X86_MEM_WRITE_u32(base, 0x57136Cu, ctx.xmm[0].u32[0]);
	// 0x2AD658: ret
	return;
}

void sub_2AD660(X86Context& ctx, uint8_t* base) {
	// 0x2AD660: movss xmm0, dword ptr [0x005713A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713A0u);
	// 0x2AD668: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AD670: movss [0x00571350], xmm0
	X86_MEM_WRITE_u32(base, 0x571350u, ctx.xmm[0].u32[0]);
	// 0x2AD678: ret
	return;
}

void sub_2AD680(X86Context& ctx, uint8_t* base) {
	// 0x2AD680: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AD688: movss [0x00571334], xmm0
	X86_MEM_WRITE_u32(base, 0x571334u, ctx.xmm[0].u32[0]);
	// 0x2AD690: ret
	return;
}

void sub_2AD6A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD6A0: movss xmm0, dword ptr [0x00571350]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571350u);
	// 0x2AD6A8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AD6B0: movss [0x0057138C], xmm0
	X86_MEM_WRITE_u32(base, 0x57138Cu, ctx.xmm[0].u32[0]);
	// 0x2AD6B8: ret
	return;
}

void sub_2AD6C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD6C0: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2AD6C8: movss [0x00571354], xmm0
	X86_MEM_WRITE_u32(base, 0x571354u, ctx.xmm[0].u32[0]);
	// 0x2AD6D0: ret
	return;
}

void sub_2AD6E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD6E0: movss xmm0, dword ptr [0x003B1E24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1E24u);
	// 0x2AD6E8: movss [0x00571328], xmm0
	X86_MEM_WRITE_u32(base, 0x571328u, ctx.xmm[0].u32[0]);
	// 0x2AD6F0: ret
	return;
}

void sub_2AD700(X86Context& ctx, uint8_t* base) {
	// 0x2AD700: movss xmm0, dword ptr [0x00571328]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571328u);
	// 0x2AD708: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AD710: movss xmm1, dword ptr [0x00571358]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571358u);
	// 0x2AD718: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x2AD71C: movss [0x00571364], xmm1
	X86_MEM_WRITE_u32(base, 0x571364u, ctx.xmm[1].u32[0]);
	// 0x2AD724: ret
	return;
}

void sub_2AD730(X86Context& ctx, uint8_t* base) {
	// 0x2AD730: movss xmm0, dword ptr [0x00571354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571354u);
	// 0x2AD738: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AD740: addss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AD748: movss [0x00571348], xmm0
	X86_MEM_WRITE_u32(base, 0x571348u, ctx.xmm[0].u32[0]);
	// 0x2AD750: ret
	return;
}

void sub_2AD760(X86Context& ctx, uint8_t* base) {
	// 0x2AD760: movss xmm0, dword ptr [0x00571354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571354u);
	// 0x2AD768: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AD770: movss xmm1, dword ptr [0x005712FC]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x5712FCu);
	// 0x2AD778: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x2AD77C: movss [0x00571368], xmm1
	X86_MEM_WRITE_u32(base, 0x571368u, ctx.xmm[1].u32[0]);
	// 0x2AD784: ret
	return;
}

void sub_2AD790(X86Context& ctx, uint8_t* base) {
	// 0x2AD790: movss xmm0, dword ptr [0x00571348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571348u);
	// 0x2AD798: movss xmm1, dword ptr [0x00571368]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x571368u);
	// 0x2AD7A0: subss xmm1, xmm0
	ctx.xmm[1].f32[0] -= ctx.xmm[0].f32[0];
	// 0x2AD7A4: mulss xmm1, [0x003B1684]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AD7AC: addss xmm1, xmm0
	ctx.xmm[1].f32[0] += ctx.xmm[0].f32[0];
	// 0x2AD7B0: movss [0x0057134C], xmm1
	X86_MEM_WRITE_u32(base, 0x57134Cu, ctx.xmm[1].u32[0]);
	// 0x2AD7B8: ret
	return;
}

void sub_2AD7C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD7C0: movss xmm0, dword ptr [0x00571368]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571368u);
	// 0x2AD7C8: mulss xmm0, [0x003A2D54]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3A2D54u);
	// 0x2AD7D0: movss [0x00571318], xmm0
	X86_MEM_WRITE_u32(base, 0x571318u, ctx.xmm[0].u32[0]);
	// 0x2AD7D8: ret
	return;
}

void sub_2AD7E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD7E0: movss xmm0, dword ptr [0x003B22C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22C4u);
	// 0x2AD7E8: movss [0x0057131C], xmm0
	X86_MEM_WRITE_u32(base, 0x57131Cu, ctx.xmm[0].u32[0]);
	// 0x2AD7F0: ret
	return;
}

void sub_2AD800(X86Context& ctx, uint8_t* base) {
	// 0x2AD800: movss xmm0, dword ptr [0x00571364]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571364u);
	// 0x2AD808: subss xmm0, [0x0057131C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57131Cu);
	// 0x2AD810: movss [0x00571394], xmm0
	X86_MEM_WRITE_u32(base, 0x571394u, ctx.xmm[0].u32[0]);
	// 0x2AD818: ret
	return;
}

void sub_2AD820(X86Context& ctx, uint8_t* base) {
	// 0x2AD820: movss xmm0, dword ptr [0x00571368]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571368u);
	// 0x2AD828: subss xmm0, [0x003B1708]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1708u);
	// 0x2AD830: movss [0x00407EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x407EC8u, ctx.xmm[0].u32[0]);
	// 0x2AD838: ret
	return;
}

void sub_2AD840(X86Context& ctx, uint8_t* base) {
	// 0x2AD840: movss xmm0, dword ptr [0x00571368]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571368u);
	// 0x2AD848: subss xmm0, [0x003B1708]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1708u);
	// 0x2AD850: movss [0x00407ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x407ED0u, ctx.xmm[0].u32[0]);
	// 0x2AD858: ret
	return;
}

void sub_2AD860(X86Context& ctx, uint8_t* base) {
	// 0x2AD860: movss xmm0, dword ptr [0x00571394]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571394u);
	// 0x2AD868: addss xmm0, [0x0057131C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x57131Cu);
	// 0x2AD870: movss [0x00407EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x407EDCu, ctx.xmm[0].u32[0]);
	// 0x2AD878: ret
	return;
}

void sub_2AD880(X86Context& ctx, uint8_t* base) {
	// 0x2AD880: movss xmm0, dword ptr [0x00571368]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571368u);
	// 0x2AD888: movss [0x00407EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x407EE0u, ctx.xmm[0].u32[0]);
	// 0x2AD890: ret
	return;
}

void sub_2AD8A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD8A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AD8A8: movss [0x0057141C], xmm0
	X86_MEM_WRITE_u32(base, 0x57141Cu, ctx.xmm[0].u32[0]);
	// 0x2AD8B0: ret
	return;
}

void sub_2AD8C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD8C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AD8C8: movss [0x00571438], xmm0
	X86_MEM_WRITE_u32(base, 0x571438u, ctx.xmm[0].u32[0]);
	// 0x2AD8D0: ret
	return;
}

void sub_2AD8E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD8E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AD8E8: movss [0x0057140C], xmm0
	X86_MEM_WRITE_u32(base, 0x57140Cu, ctx.xmm[0].u32[0]);
	// 0x2AD8F0: ret
	return;
}

void sub_2AD900(X86Context& ctx, uint8_t* base) {
	// 0x2AD900: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AD908: movss [0x005713C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5713C0u, ctx.xmm[0].u32[0]);
	// 0x2AD910: ret
	return;
}

void sub_2AD920(X86Context& ctx, uint8_t* base) {
	// 0x2AD920: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AD928: movss [0x00571420], xmm0
	X86_MEM_WRITE_u32(base, 0x571420u, ctx.xmm[0].u32[0]);
	// 0x2AD930: ret
	return;
}

void sub_2AD940(X86Context& ctx, uint8_t* base) {
	// 0x2AD940: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AD948: movss [0x005713DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5713DCu, ctx.xmm[0].u32[0]);
	// 0x2AD950: ret
	return;
}

void sub_2AD960(X86Context& ctx, uint8_t* base) {
	// 0x2AD960: movss xmm0, dword ptr [0x00571420]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571420u);
	// 0x2AD968: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AD970: movss [0x0057145C], xmm0
	X86_MEM_WRITE_u32(base, 0x57145Cu, ctx.xmm[0].u32[0]);
	// 0x2AD978: ret
	return;
}

void sub_2AD980(X86Context& ctx, uint8_t* base) {
	// 0x2AD980: movss xmm0, dword ptr [0x005713DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713DCu);
	// 0x2AD988: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AD990: movss [0x00571440], xmm0
	X86_MEM_WRITE_u32(base, 0x571440u, ctx.xmm[0].u32[0]);
	// 0x2AD998: ret
	return;
}

void sub_2AD9A0(X86Context& ctx, uint8_t* base) {
	// 0x2AD9A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AD9A8: movss [0x0057147C], xmm0
	X86_MEM_WRITE_u32(base, 0x57147Cu, ctx.xmm[0].u32[0]);
	// 0x2AD9B0: ret
	return;
}

void sub_2AD9C0(X86Context& ctx, uint8_t* base) {
	// 0x2AD9C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AD9C8: movss [0x00571460], xmm0
	X86_MEM_WRITE_u32(base, 0x571460u, ctx.xmm[0].u32[0]);
	// 0x2AD9D0: ret
	return;
}

void sub_2AD9E0(X86Context& ctx, uint8_t* base) {
	// 0x2AD9E0: movss xmm0, dword ptr [0x00571460]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571460u);
	// 0x2AD9E8: movss [0x00571478], xmm0
	X86_MEM_WRITE_u32(base, 0x571478u, ctx.xmm[0].u32[0]);
	// 0x2AD9F0: ret
	return;
}

void sub_2ADA00(X86Context& ctx, uint8_t* base) {
	// 0x2ADA00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ADA08: movss [0x005713C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5713C8u, ctx.xmm[0].u32[0]);
	// 0x2ADA10: ret
	return;
}

void sub_2ADA20(X86Context& ctx, uint8_t* base) {
	// 0x2ADA20: movss xmm0, dword ptr [0x005713DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713DCu);
	// 0x2ADA28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2ADA30: movss [0x0057146C], xmm0
	X86_MEM_WRITE_u32(base, 0x57146Cu, ctx.xmm[0].u32[0]);
	// 0x2ADA38: ret
	return;
}

void sub_2ADA40(X86Context& ctx, uint8_t* base) {
	// 0x2ADA40: movss xmm0, dword ptr [0x005713DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713DCu);
	// 0x2ADA48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2ADA50: movss [0x00571404], xmm0
	X86_MEM_WRITE_u32(base, 0x571404u, ctx.xmm[0].u32[0]);
	// 0x2ADA58: ret
	return;
}

void sub_2ADA60(X86Context& ctx, uint8_t* base) {
	// 0x2ADA60: movss xmm0, dword ptr [0x005713DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713DCu);
	// 0x2ADA68: subss xmm0, [0x00571404]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571404u);
	// 0x2ADA70: movss [0x005713E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5713E4u, ctx.xmm[0].u32[0]);
	// 0x2ADA78: ret
	return;
}

void sub_2ADA80(X86Context& ctx, uint8_t* base) {
	// 0x2ADA80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2ADA88: movss [0x00571434], xmm0
	X86_MEM_WRITE_u32(base, 0x571434u, ctx.xmm[0].u32[0]);
	// 0x2ADA90: ret
	return;
}

void sub_2ADAA0(X86Context& ctx, uint8_t* base) {
	// 0x2ADAA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2ADAA8: movss [0x005713E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5713E0u, ctx.xmm[0].u32[0]);
	// 0x2ADAB0: ret
	return;
}

void sub_2ADAC0(X86Context& ctx, uint8_t* base) {
	// 0x2ADAC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2ADAC8: movss [0x005713F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5713F0u, ctx.xmm[0].u32[0]);
	// 0x2ADAD0: ret
	return;
}

void sub_2ADAE0(X86Context& ctx, uint8_t* base) {
	// 0x2ADAE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2ADAE8: movss [0x00571450], xmm0
	X86_MEM_WRITE_u32(base, 0x571450u, ctx.xmm[0].u32[0]);
	// 0x2ADAF0: ret
	return;
}

void sub_2ADB00(X86Context& ctx, uint8_t* base) {
	// 0x2ADB00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2ADB08: movss [0x00571430], xmm0
	X86_MEM_WRITE_u32(base, 0x571430u, ctx.xmm[0].u32[0]);
	// 0x2ADB10: ret
	return;
}

void sub_2ADB20(X86Context& ctx, uint8_t* base) {
	// 0x2ADB20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2ADB28: movss [0x005713D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5713D8u, ctx.xmm[0].u32[0]);
	// 0x2ADB30: ret
	return;
}

void sub_2ADB40(X86Context& ctx, uint8_t* base) {
	// 0x2ADB40: movss xmm0, dword ptr [0x005713F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713F0u);
	// 0x2ADB48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ADB50: movss [0x005713CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5713CCu, ctx.xmm[0].u32[0]);
	// 0x2ADB58: ret
	return;
}

void sub_2ADB60(X86Context& ctx, uint8_t* base) {
	// 0x2ADB60: movss xmm0, dword ptr [0x00571450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571450u);
	// 0x2ADB68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ADB70: movss [0x00571418], xmm0
	X86_MEM_WRITE_u32(base, 0x571418u, ctx.xmm[0].u32[0]);
	// 0x2ADB78: ret
	return;
}

void sub_2ADB80(X86Context& ctx, uint8_t* base) {
	// 0x2ADB80: movss xmm0, dword ptr [0x005713CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713CCu);
	// 0x2ADB88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ADB90: movss [0x00571428], xmm0
	X86_MEM_WRITE_u32(base, 0x571428u, ctx.xmm[0].u32[0]);
	// 0x2ADB98: ret
	return;
}

void sub_2ADBA0(X86Context& ctx, uint8_t* base) {
	// 0x2ADBA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ADBA8: movss [0x005713C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5713C4u, ctx.xmm[0].u32[0]);
	// 0x2ADBB0: ret
	return;
}

void sub_2ADBC0(X86Context& ctx, uint8_t* base) {
	// 0x2ADBC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2ADBC8: movss [0x005713F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5713F4u, ctx.xmm[0].u32[0]);
	// 0x2ADBD0: ret
	return;
}

void sub_2ADBE0(X86Context& ctx, uint8_t* base) {
	// 0x2ADBE0: movss xmm0, dword ptr [0x005713F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713F0u);
	// 0x2ADBE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ADBF0: movss [0x00571400], xmm0
	X86_MEM_WRITE_u32(base, 0x571400u, ctx.xmm[0].u32[0]);
	// 0x2ADBF8: ret
	return;
}

void sub_2ADC00(X86Context& ctx, uint8_t* base) {
	// 0x2ADC00: movss xmm0, dword ptr [0x00571450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571450u);
	// 0x2ADC08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2ADC10: movss [0x00571454], xmm0
	X86_MEM_WRITE_u32(base, 0x571454u, ctx.xmm[0].u32[0]);
	// 0x2ADC18: ret
	return;
}

void sub_2ADC20(X86Context& ctx, uint8_t* base) {
	// 0x2ADC20: movss xmm0, dword ptr [0x00571400]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571400u);
	// 0x2ADC28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ADC30: movss [0x0057143C], xmm0
	X86_MEM_WRITE_u32(base, 0x57143Cu, ctx.xmm[0].u32[0]);
	// 0x2ADC38: ret
	return;
}

void sub_2ADC40(X86Context& ctx, uint8_t* base) {
	// 0x2ADC40: movss xmm0, dword ptr [0x00571454]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571454u);
	// 0x2ADC48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ADC50: movss [0x00571468], xmm0
	X86_MEM_WRITE_u32(base, 0x571468u, ctx.xmm[0].u32[0]);
	// 0x2ADC58: ret
	return;
}

void sub_2ADC60(X86Context& ctx, uint8_t* base) {
	// 0x2ADC60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2ADC68: movss [0x005713D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5713D0u, ctx.xmm[0].u32[0]);
	// 0x2ADC70: ret
	return;
}

void sub_2ADC80(X86Context& ctx, uint8_t* base) {
	// 0x2ADC80: movss xmm0, dword ptr [0x005713F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713F0u);
	// 0x2ADC88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ADC90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2ADC98: movss [0x0057144C], xmm0
	X86_MEM_WRITE_u32(base, 0x57144Cu, ctx.xmm[0].u32[0]);
	// 0x2ADCA0: ret
	return;
}

void sub_2ADCB0(X86Context& ctx, uint8_t* base) {
	// 0x2ADCB0: movss xmm0, dword ptr [0x00571450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571450u);
	// 0x2ADCB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ADCC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2ADCC8: movss [0x005713E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5713E8u, ctx.xmm[0].u32[0]);
	// 0x2ADCD0: ret
	return;
}

void sub_2ADCE0(X86Context& ctx, uint8_t* base) {
	// 0x2ADCE0: movss xmm0, dword ptr [0x005713F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713F0u);
	// 0x2ADCE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ADCF0: movss [0x005713EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5713ECu, ctx.xmm[0].u32[0]);
	// 0x2ADCF8: ret
	return;
}

void sub_2ADD00(X86Context& ctx, uint8_t* base) {
	// 0x2ADD00: movss xmm0, dword ptr [0x00571450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571450u);
	// 0x2ADD08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2ADD10: movss [0x00571458], xmm0
	X86_MEM_WRITE_u32(base, 0x571458u, ctx.xmm[0].u32[0]);
	// 0x2ADD18: ret
	return;
}

void sub_2ADD20(X86Context& ctx, uint8_t* base) {
	// 0x2ADD20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2ADD28: movss [0x005713D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5713D4u, ctx.xmm[0].u32[0]);
	// 0x2ADD30: ret
	return;
}

void sub_2ADD40(X86Context& ctx, uint8_t* base) {
	// 0x2ADD40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2ADD48: movss [0x005713FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5713FCu, ctx.xmm[0].u32[0]);
	// 0x2ADD50: ret
	return;
}

void sub_2ADD60(X86Context& ctx, uint8_t* base) {
	// 0x2ADD60: movss xmm0, dword ptr [0x005713D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713D4u);
	// 0x2ADD68: movss [0x00571470], xmm0
	X86_MEM_WRITE_u32(base, 0x571470u, ctx.xmm[0].u32[0]);
	// 0x2ADD70: ret
	return;
}

void sub_2ADD80(X86Context& ctx, uint8_t* base) {
	// 0x2ADD80: movss xmm0, dword ptr [0x00571450]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571450u);
	// 0x2ADD88: subss xmm0, [0x005713D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5713D4u);
	// 0x2ADD90: movss [0x0057142C], xmm0
	X86_MEM_WRITE_u32(base, 0x57142Cu, ctx.xmm[0].u32[0]);
	// 0x2ADD98: ret
	return;
}

void sub_2ADDA0(X86Context& ctx, uint8_t* base) {
	// 0x2ADDA0: movss xmm0, dword ptr [0x0057142C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57142Cu);
	// 0x2ADDA8: subss xmm0, [0x005713FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5713FCu);
	// 0x2ADDB0: movss [0x00571424], xmm0
	X86_MEM_WRITE_u32(base, 0x571424u, ctx.xmm[0].u32[0]);
	// 0x2ADDB8: ret
	return;
}

void sub_2ADDC0(X86Context& ctx, uint8_t* base) {
	// 0x2ADDC0: movss xmm0, dword ptr [0x00571458]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571458u);
	// 0x2ADDC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2ADDD0: movss [0x00571410], xmm0
	X86_MEM_WRITE_u32(base, 0x571410u, ctx.xmm[0].u32[0]);
	// 0x2ADDD8: ret
	return;
}

void sub_2ADDE0(X86Context& ctx, uint8_t* base) {
	// 0x2ADDE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2ADDE8: movss [0x005713F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5713F8u, ctx.xmm[0].u32[0]);
	// 0x2ADDF0: ret
	return;
}

void sub_2ADE00(X86Context& ctx, uint8_t* base) {
	// 0x2ADE00: movss xmm0, dword ptr [0x00571410]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571410u);
	// 0x2ADE08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2ADE10: movss [0x00571444], xmm0
	X86_MEM_WRITE_u32(base, 0x571444u, ctx.xmm[0].u32[0]);
	// 0x2ADE18: ret
	return;
}

void sub_2ADE20(X86Context& ctx, uint8_t* base) {
	// 0x2ADE20: movss xmm0, dword ptr [0x003B22C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22C8u);
	// 0x2ADE28: movss [0x00571414], xmm0
	X86_MEM_WRITE_u32(base, 0x571414u, ctx.xmm[0].u32[0]);
	// 0x2ADE30: ret
	return;
}

void sub_2ADE40(X86Context& ctx, uint8_t* base) {
	// 0x2ADE40: movss xmm0, dword ptr [0x003980F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3980F8u);
	// 0x2ADE48: movss [0x00571448], xmm0
	X86_MEM_WRITE_u32(base, 0x571448u, ctx.xmm[0].u32[0]);
	// 0x2ADE50: ret
	return;
}

void sub_2ADE60(X86Context& ctx, uint8_t* base) {
	// 0x2ADE60: movss xmm0, dword ptr [0x00571448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571448u);
	// 0x2ADE68: addss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ADE70: movss [0x00571408], xmm0
	X86_MEM_WRITE_u32(base, 0x571408u, ctx.xmm[0].u32[0]);
	// 0x2ADE78: ret
	return;
}

void sub_2ADE80(X86Context& ctx, uint8_t* base) {
	// 0x2ADE80: movss xmm0, dword ptr [0x00571448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571448u);
	// 0x2ADE88: addss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ADE90: movss [0x00571464], xmm0
	X86_MEM_WRITE_u32(base, 0x571464u, ctx.xmm[0].u32[0]);
	// 0x2ADE98: ret
	return;
}

void sub_2ADEA0(X86Context& ctx, uint8_t* base) {
	// 0x2ADEA0: movss xmm0, dword ptr [0x005713F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5713F0u);
	// 0x2ADEA8: movss [0x00571474], xmm0
	X86_MEM_WRITE_u32(base, 0x571474u, ctx.xmm[0].u32[0]);
	// 0x2ADEB0: ret
	return;
}

void sub_2ADEC0(X86Context& ctx, uint8_t* base) {
	// 0x2ADEC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2ADEC8: movss [0x005714E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5714E4u, ctx.xmm[0].u32[0]);
	// 0x2ADED0: ret
	return;
}

void sub_2ADEE0(X86Context& ctx, uint8_t* base) {
	// 0x2ADEE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2ADEE8: movss [0x00571500], xmm0
	X86_MEM_WRITE_u32(base, 0x571500u, ctx.xmm[0].u32[0]);
	// 0x2ADEF0: ret
	return;
}

void sub_2ADF00(X86Context& ctx, uint8_t* base) {
	// 0x2ADF00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2ADF08: movss [0x005714D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5714D4u, ctx.xmm[0].u32[0]);
	// 0x2ADF10: ret
	return;
}

void sub_2ADF20(X86Context& ctx, uint8_t* base) {
	// 0x2ADF20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2ADF28: movss [0x00571480], xmm0
	X86_MEM_WRITE_u32(base, 0x571480u, ctx.xmm[0].u32[0]);
	// 0x2ADF30: ret
	return;
}

void sub_2ADF40(X86Context& ctx, uint8_t* base) {
	// 0x2ADF40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2ADF48: movss [0x005714E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5714E8u, ctx.xmm[0].u32[0]);
	// 0x2ADF50: ret
	return;
}

void sub_2ADF60(X86Context& ctx, uint8_t* base) {
	// 0x2ADF60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2ADF68: movss [0x0057149C], xmm0
	X86_MEM_WRITE_u32(base, 0x57149Cu, ctx.xmm[0].u32[0]);
	// 0x2ADF70: ret
	return;
}

void sub_2ADF80(X86Context& ctx, uint8_t* base) {
	// 0x2ADF80: movss xmm0, dword ptr [0x005714E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714E8u);
	// 0x2ADF88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2ADF90: movss [0x00571524], xmm0
	X86_MEM_WRITE_u32(base, 0x571524u, ctx.xmm[0].u32[0]);
	// 0x2ADF98: ret
	return;
}

void sub_2ADFA0(X86Context& ctx, uint8_t* base) {
	// 0x2ADFA0: movss xmm0, dword ptr [0x0057149C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57149Cu);
	// 0x2ADFA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2ADFB0: movss [0x00571508], xmm0
	X86_MEM_WRITE_u32(base, 0x571508u, ctx.xmm[0].u32[0]);
	// 0x2ADFB8: ret
	return;
}

void sub_2ADFC0(X86Context& ctx, uint8_t* base) {
	// 0x2ADFC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2ADFC8: movss [0x00571540], xmm0
	X86_MEM_WRITE_u32(base, 0x571540u, ctx.xmm[0].u32[0]);
	// 0x2ADFD0: ret
	return;
}

void sub_2ADFE0(X86Context& ctx, uint8_t* base) {
	// 0x2ADFE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2ADFE8: movss [0x00571528], xmm0
	X86_MEM_WRITE_u32(base, 0x571528u, ctx.xmm[0].u32[0]);
	// 0x2ADFF0: ret
	return;
}

void sub_2AE000(X86Context& ctx, uint8_t* base) {
	// 0x2AE000: movss xmm0, dword ptr [0x00571528]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571528u);
	// 0x2AE008: movss [0x0057153C], xmm0
	X86_MEM_WRITE_u32(base, 0x57153Cu, ctx.xmm[0].u32[0]);
	// 0x2AE010: ret
	return;
}

void sub_2AE020(X86Context& ctx, uint8_t* base) {
	// 0x2AE020: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AE028: movss [0x00571488], xmm0
	X86_MEM_WRITE_u32(base, 0x571488u, ctx.xmm[0].u32[0]);
	// 0x2AE030: ret
	return;
}

void sub_2AE040(X86Context& ctx, uint8_t* base) {
	// 0x2AE040: movss xmm0, dword ptr [0x0057149C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57149Cu);
	// 0x2AE048: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AE050: movss [0x00571530], xmm0
	X86_MEM_WRITE_u32(base, 0x571530u, ctx.xmm[0].u32[0]);
	// 0x2AE058: ret
	return;
}

void sub_2AE060(X86Context& ctx, uint8_t* base) {
	// 0x2AE060: movss xmm0, dword ptr [0x0057149C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57149Cu);
	// 0x2AE068: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AE070: movss [0x005714D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5714D0u, ctx.xmm[0].u32[0]);
	// 0x2AE078: ret
	return;
}

void sub_2AE080(X86Context& ctx, uint8_t* base) {
	// 0x2AE080: movss xmm0, dword ptr [0x0057149C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57149Cu);
	// 0x2AE088: subss xmm0, [0x005714D0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5714D0u);
	// 0x2AE090: movss [0x005714A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5714A8u, ctx.xmm[0].u32[0]);
	// 0x2AE098: ret
	return;
}

void sub_2AE0A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE0A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AE0A8: movss [0x005714FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5714FCu, ctx.xmm[0].u32[0]);
	// 0x2AE0B0: ret
	return;
}

void sub_2AE0C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE0C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AE0C8: movss [0x005714A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5714A4u, ctx.xmm[0].u32[0]);
	// 0x2AE0D0: ret
	return;
}

void sub_2AE0E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE0E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AE0E8: movss [0x005714B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5714B8u, ctx.xmm[0].u32[0]);
	// 0x2AE0F0: ret
	return;
}

void sub_2AE100(X86Context& ctx, uint8_t* base) {
	// 0x2AE100: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AE108: movss [0x00571514], xmm0
	X86_MEM_WRITE_u32(base, 0x571514u, ctx.xmm[0].u32[0]);
	// 0x2AE110: ret
	return;
}

void sub_2AE120(X86Context& ctx, uint8_t* base) {
	// 0x2AE120: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AE128: movss [0x005714F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5714F8u, ctx.xmm[0].u32[0]);
	// 0x2AE130: ret
	return;
}

void sub_2AE140(X86Context& ctx, uint8_t* base) {
	// 0x2AE140: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AE148: movss [0x00571498], xmm0
	X86_MEM_WRITE_u32(base, 0x571498u, ctx.xmm[0].u32[0]);
	// 0x2AE150: ret
	return;
}

void sub_2AE160(X86Context& ctx, uint8_t* base) {
	// 0x2AE160: movss xmm0, dword ptr [0x005714B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714B8u);
	// 0x2AE168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AE170: movss [0x0057148C], xmm0
	X86_MEM_WRITE_u32(base, 0x57148Cu, ctx.xmm[0].u32[0]);
	// 0x2AE178: ret
	return;
}

void sub_2AE180(X86Context& ctx, uint8_t* base) {
	// 0x2AE180: movss xmm0, dword ptr [0x00571514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571514u);
	// 0x2AE188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AE190: movss [0x005714E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5714E0u, ctx.xmm[0].u32[0]);
	// 0x2AE198: ret
	return;
}

void sub_2AE1A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE1A0: movss xmm0, dword ptr [0x0057148C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57148Cu);
	// 0x2AE1A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AE1B0: movss [0x005714F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5714F0u, ctx.xmm[0].u32[0]);
	// 0x2AE1B8: ret
	return;
}

void sub_2AE1C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE1C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AE1C8: movss [0x00571484], xmm0
	X86_MEM_WRITE_u32(base, 0x571484u, ctx.xmm[0].u32[0]);
	// 0x2AE1D0: ret
	return;
}

void sub_2AE1E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE1E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AE1E8: movss [0x005714BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5714BCu, ctx.xmm[0].u32[0]);
	// 0x2AE1F0: ret
	return;
}

void sub_2AE200(X86Context& ctx, uint8_t* base) {
	// 0x2AE200: movss xmm0, dword ptr [0x005714B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714B8u);
	// 0x2AE208: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AE210: movss [0x005714CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5714CCu, ctx.xmm[0].u32[0]);
	// 0x2AE218: ret
	return;
}

void sub_2AE220(X86Context& ctx, uint8_t* base) {
	// 0x2AE220: movss xmm0, dword ptr [0x00571514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571514u);
	// 0x2AE228: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AE230: movss [0x0057151C], xmm0
	X86_MEM_WRITE_u32(base, 0x57151Cu, ctx.xmm[0].u32[0]);
	// 0x2AE238: ret
	return;
}

void sub_2AE240(X86Context& ctx, uint8_t* base) {
	// 0x2AE240: movss xmm0, dword ptr [0x005714CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714CCu);
	// 0x2AE248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE250: movss [0x00571504], xmm0
	X86_MEM_WRITE_u32(base, 0x571504u, ctx.xmm[0].u32[0]);
	// 0x2AE258: ret
	return;
}

void sub_2AE260(X86Context& ctx, uint8_t* base) {
	// 0x2AE260: movss xmm0, dword ptr [0x0057151C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57151Cu);
	// 0x2AE268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE270: movss [0x0057152C], xmm0
	X86_MEM_WRITE_u32(base, 0x57152Cu, ctx.xmm[0].u32[0]);
	// 0x2AE278: ret
	return;
}

void sub_2AE280(X86Context& ctx, uint8_t* base) {
	// 0x2AE280: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AE288: movss [0x00571490], xmm0
	X86_MEM_WRITE_u32(base, 0x571490u, ctx.xmm[0].u32[0]);
	// 0x2AE290: ret
	return;
}

void sub_2AE2A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE2A0: movss xmm0, dword ptr [0x005714B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714B8u);
	// 0x2AE2A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE2B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AE2B8: movss [0x00571510], xmm0
	X86_MEM_WRITE_u32(base, 0x571510u, ctx.xmm[0].u32[0]);
	// 0x2AE2C0: ret
	return;
}

void sub_2AE2D0(X86Context& ctx, uint8_t* base) {
	// 0x2AE2D0: movss xmm0, dword ptr [0x00571514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571514u);
	// 0x2AE2D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE2E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AE2E8: movss [0x005714AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5714ACu, ctx.xmm[0].u32[0]);
	// 0x2AE2F0: ret
	return;
}

void sub_2AE300(X86Context& ctx, uint8_t* base) {
	// 0x2AE300: movss xmm0, dword ptr [0x005714B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714B8u);
	// 0x2AE308: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE310: movss [0x005714B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5714B0u, ctx.xmm[0].u32[0]);
	// 0x2AE318: ret
	return;
}

void sub_2AE320(X86Context& ctx, uint8_t* base) {
	// 0x2AE320: movss xmm0, dword ptr [0x00571514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571514u);
	// 0x2AE328: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE330: movss [0x00571520], xmm0
	X86_MEM_WRITE_u32(base, 0x571520u, ctx.xmm[0].u32[0]);
	// 0x2AE338: ret
	return;
}

void sub_2AE340(X86Context& ctx, uint8_t* base) {
	// 0x2AE340: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AE348: movss [0x00571494], xmm0
	X86_MEM_WRITE_u32(base, 0x571494u, ctx.xmm[0].u32[0]);
	// 0x2AE350: ret
	return;
}

void sub_2AE360(X86Context& ctx, uint8_t* base) {
	// 0x2AE360: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AE368: movss [0x005714C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5714C8u, ctx.xmm[0].u32[0]);
	// 0x2AE370: ret
	return;
}

void sub_2AE380(X86Context& ctx, uint8_t* base) {
	// 0x2AE380: movss xmm0, dword ptr [0x00571494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571494u);
	// 0x2AE388: movss [0x00571534], xmm0
	X86_MEM_WRITE_u32(base, 0x571534u, ctx.xmm[0].u32[0]);
	// 0x2AE390: ret
	return;
}

void sub_2AE3A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE3A0: movss xmm0, dword ptr [0x00571514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571514u);
	// 0x2AE3A8: subss xmm0, [0x00571494]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571494u);
	// 0x2AE3B0: movss [0x005714F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5714F4u, ctx.xmm[0].u32[0]);
	// 0x2AE3B8: ret
	return;
}

void sub_2AE3C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE3C0: movss xmm0, dword ptr [0x005714F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714F4u);
	// 0x2AE3C8: subss xmm0, [0x005714C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5714C8u);
	// 0x2AE3D0: movss [0x005714EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5714ECu, ctx.xmm[0].u32[0]);
	// 0x2AE3D8: ret
	return;
}

void sub_2AE3E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE3E0: movss xmm0, dword ptr [0x00571520]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571520u);
	// 0x2AE3E8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AE3F0: movss [0x005714D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5714D8u, ctx.xmm[0].u32[0]);
	// 0x2AE3F8: ret
	return;
}

void sub_2AE400(X86Context& ctx, uint8_t* base) {
	// 0x2AE400: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AE408: movss [0x005714C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5714C4u, ctx.xmm[0].u32[0]);
	// 0x2AE410: ret
	return;
}

void sub_2AE420(X86Context& ctx, uint8_t* base) {
	// 0x2AE420: movss xmm0, dword ptr [0x005714D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714D8u);
	// 0x2AE428: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AE430: movss [0x0057150C], xmm0
	X86_MEM_WRITE_u32(base, 0x57150Cu, ctx.xmm[0].u32[0]);
	// 0x2AE438: ret
	return;
}

void sub_2AE440(X86Context& ctx, uint8_t* base) {
	// 0x2AE440: movss xmm0, dword ptr [0x005714F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714F8u);
	// 0x2AE448: movss [0x005714DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5714DCu, ctx.xmm[0].u32[0]);
	// 0x2AE450: ret
	return;
}

void sub_2AE460(X86Context& ctx, uint8_t* base) {
	// 0x2AE460: movss xmm0, dword ptr [0x00571498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571498u);
	// 0x2AE468: subss xmm0, [0x003B16B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B16B4u);
	// 0x2AE470: movss [0x005714B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5714B4u, ctx.xmm[0].u32[0]);
	// 0x2AE478: ret
	return;
}

void sub_2AE480(X86Context& ctx, uint8_t* base) {
	// 0x2AE480: movss xmm0, dword ptr [0x005714F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714F8u);
	// 0x2AE488: addss xmm0, [0x00395BE4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x395BE4u);
	// 0x2AE490: movss [0x00571538], xmm0
	X86_MEM_WRITE_u32(base, 0x571538u, ctx.xmm[0].u32[0]);
	// 0x2AE498: ret
	return;
}

void sub_2AE4A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE4A0: movss xmm0, dword ptr [0x00571498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571498u);
	// 0x2AE4A8: subss xmm0, [0x003B1694]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1694u);
	// 0x2AE4B0: movss [0x00571518], xmm0
	X86_MEM_WRITE_u32(base, 0x571518u, ctx.xmm[0].u32[0]);
	// 0x2AE4B8: ret
	return;
}

void sub_2AE4C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE4C0: movss xmm0, dword ptr [0x005714F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5714F8u);
	// 0x2AE4C8: addss xmm0, [0x003B1D78]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1D78u);
	// 0x2AE4D0: movss [0x005714A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5714A0u, ctx.xmm[0].u32[0]);
	// 0x2AE4D8: ret
	return;
}

void sub_2AE4E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE4E0: movss xmm0, dword ptr [0x00571498]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571498u);
	// 0x2AE4E8: addss xmm0, [0x003B1C88]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1C88u);
	// 0x2AE4F0: movss [0x005714C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5714C0u, ctx.xmm[0].u32[0]);
	// 0x2AE4F8: ret
	return;
}

void sub_2AE500(X86Context& ctx, uint8_t* base) {
	// 0x2AE500: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AE508: movss [0x0057167C], xmm0
	X86_MEM_WRITE_u32(base, 0x57167Cu, ctx.xmm[0].u32[0]);
	// 0x2AE510: ret
	return;
}

void sub_2AE520(X86Context& ctx, uint8_t* base) {
	// 0x2AE520: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AE528: movss [0x005716F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5716F8u, ctx.xmm[0].u32[0]);
	// 0x2AE530: ret
	return;
}

void sub_2AE540(X86Context& ctx, uint8_t* base) {
	// 0x2AE540: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AE548: movss [0x00571648], xmm0
	X86_MEM_WRITE_u32(base, 0x571648u, ctx.xmm[0].u32[0]);
	// 0x2AE550: ret
	return;
}

void sub_2AE560(X86Context& ctx, uint8_t* base) {
	// 0x2AE560: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AE568: movss [0x00571544], xmm0
	X86_MEM_WRITE_u32(base, 0x571544u, ctx.xmm[0].u32[0]);
	// 0x2AE570: ret
	return;
}

void sub_2AE580(X86Context& ctx, uint8_t* base) {
	// 0x2AE580: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AE588: movss [0x00571680], xmm0
	X86_MEM_WRITE_u32(base, 0x571680u, ctx.xmm[0].u32[0]);
	// 0x2AE590: ret
	return;
}

void sub_2AE5A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE5A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AE5A8: movss [0x00571594], xmm0
	X86_MEM_WRITE_u32(base, 0x571594u, ctx.xmm[0].u32[0]);
	// 0x2AE5B0: ret
	return;
}

void sub_2AE5C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE5C0: movss xmm0, dword ptr [0x00571680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571680u);
	// 0x2AE5C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AE5D0: movss [0x00571764], xmm0
	X86_MEM_WRITE_u32(base, 0x571764u, ctx.xmm[0].u32[0]);
	// 0x2AE5D8: ret
	return;
}

void sub_2AE5E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE5E0: movss xmm0, dword ptr [0x00571594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571594u);
	// 0x2AE5E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AE5F0: movss [0x00571708], xmm0
	X86_MEM_WRITE_u32(base, 0x571708u, ctx.xmm[0].u32[0]);
	// 0x2AE5F8: ret
	return;
}

void sub_2AE600(X86Context& ctx, uint8_t* base) {
	// 0x2AE600: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AE608: movss [0x005717C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5717C8u, ctx.xmm[0].u32[0]);
	// 0x2AE610: ret
	return;
}

void sub_2AE620(X86Context& ctx, uint8_t* base) {
	// 0x2AE620: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AE628: movss [0x00571768], xmm0
	X86_MEM_WRITE_u32(base, 0x571768u, ctx.xmm[0].u32[0]);
	// 0x2AE630: ret
	return;
}

void sub_2AE640(X86Context& ctx, uint8_t* base) {
	// 0x2AE640: movss xmm0, dword ptr [0x00571768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571768u);
	// 0x2AE648: movss [0x005717B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5717B0u, ctx.xmm[0].u32[0]);
	// 0x2AE650: ret
	return;
}

void sub_2AE660(X86Context& ctx, uint8_t* base) {
	// 0x2AE660: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AE668: movss [0x00571574], xmm0
	X86_MEM_WRITE_u32(base, 0x571574u, ctx.xmm[0].u32[0]);
	// 0x2AE670: ret
	return;
}

void sub_2AE680(X86Context& ctx, uint8_t* base) {
	// 0x2AE680: movss xmm0, dword ptr [0x00571594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571594u);
	// 0x2AE688: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AE690: movss [0x00571790], xmm0
	X86_MEM_WRITE_u32(base, 0x571790u, ctx.xmm[0].u32[0]);
	// 0x2AE698: ret
	return;
}

void sub_2AE6A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE6A0: movss xmm0, dword ptr [0x00571594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571594u);
	// 0x2AE6A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AE6B0: movss [0x0057163C], xmm0
	X86_MEM_WRITE_u32(base, 0x57163Cu, ctx.xmm[0].u32[0]);
	// 0x2AE6B8: ret
	return;
}

void sub_2AE6C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE6C0: movss xmm0, dword ptr [0x00571594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571594u);
	// 0x2AE6C8: subss xmm0, [0x0057163C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57163Cu);
	// 0x2AE6D0: movss [0x005715B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5715B4u, ctx.xmm[0].u32[0]);
	// 0x2AE6D8: ret
	return;
}

void sub_2AE6E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE6E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AE6E8: movss [0x005716F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5716F0u, ctx.xmm[0].u32[0]);
	// 0x2AE6F0: ret
	return;
}

void sub_2AE700(X86Context& ctx, uint8_t* base) {
	// 0x2AE700: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AE708: movss [0x0057159C], xmm0
	X86_MEM_WRITE_u32(base, 0x57159Cu, ctx.xmm[0].u32[0]);
	// 0x2AE710: ret
	return;
}

void sub_2AE720(X86Context& ctx, uint8_t* base) {
	// 0x2AE720: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AE728: movss [0x0057160C], xmm0
	X86_MEM_WRITE_u32(base, 0x57160Cu, ctx.xmm[0].u32[0]);
	// 0x2AE730: ret
	return;
}

void sub_2AE740(X86Context& ctx, uint8_t* base) {
	// 0x2AE740: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AE748: movss [0x00571738], xmm0
	X86_MEM_WRITE_u32(base, 0x571738u, ctx.xmm[0].u32[0]);
	// 0x2AE750: ret
	return;
}

void sub_2AE760(X86Context& ctx, uint8_t* base) {
	// 0x2AE760: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AE768: movss [0x005716C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5716C8u, ctx.xmm[0].u32[0]);
	// 0x2AE770: ret
	return;
}

void sub_2AE780(X86Context& ctx, uint8_t* base) {
	// 0x2AE780: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AE788: movss [0x00571584], xmm0
	X86_MEM_WRITE_u32(base, 0x571584u, ctx.xmm[0].u32[0]);
	// 0x2AE790: ret
	return;
}

void sub_2AE7A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE7A0: movss xmm0, dword ptr [0x0057160C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57160Cu);
	// 0x2AE7A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AE7B0: movss [0x00571578], xmm0
	X86_MEM_WRITE_u32(base, 0x571578u, ctx.xmm[0].u32[0]);
	// 0x2AE7B8: ret
	return;
}

void sub_2AE7C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE7C0: movss xmm0, dword ptr [0x00571738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571738u);
	// 0x2AE7C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AE7D0: movss [0x00571670], xmm0
	X86_MEM_WRITE_u32(base, 0x571670u, ctx.xmm[0].u32[0]);
	// 0x2AE7D8: ret
	return;
}

void sub_2AE7E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE7E0: movss xmm0, dword ptr [0x00571578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571578u);
	// 0x2AE7E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AE7F0: movss [0x005716A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5716A4u, ctx.xmm[0].u32[0]);
	// 0x2AE7F8: ret
	return;
}

void sub_2AE800(X86Context& ctx, uint8_t* base) {
	// 0x2AE800: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AE808: movss [0x00571568], xmm0
	X86_MEM_WRITE_u32(base, 0x571568u, ctx.xmm[0].u32[0]);
	// 0x2AE810: ret
	return;
}

void sub_2AE820(X86Context& ctx, uint8_t* base) {
	// 0x2AE820: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AE828: movss [0x00571618], xmm0
	X86_MEM_WRITE_u32(base, 0x571618u, ctx.xmm[0].u32[0]);
	// 0x2AE830: ret
	return;
}

void sub_2AE840(X86Context& ctx, uint8_t* base) {
	// 0x2AE840: movss xmm0, dword ptr [0x0057160C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57160Cu);
	// 0x2AE848: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AE850: movss [0x00571634], xmm0
	X86_MEM_WRITE_u32(base, 0x571634u, ctx.xmm[0].u32[0]);
	// 0x2AE858: ret
	return;
}

void sub_2AE860(X86Context& ctx, uint8_t* base) {
	// 0x2AE860: movss xmm0, dword ptr [0x00571738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571738u);
	// 0x2AE868: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AE870: movss [0x0057174C], xmm0
	X86_MEM_WRITE_u32(base, 0x57174Cu, ctx.xmm[0].u32[0]);
	// 0x2AE878: ret
	return;
}

void sub_2AE880(X86Context& ctx, uint8_t* base) {
	// 0x2AE880: movss xmm0, dword ptr [0x00571634]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571634u);
	// 0x2AE888: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE890: movss [0x005716FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5716FCu, ctx.xmm[0].u32[0]);
	// 0x2AE898: ret
	return;
}

void sub_2AE8A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE8A0: movss xmm0, dword ptr [0x0057174C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57174Cu);
	// 0x2AE8A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE8B0: movss [0x00571774], xmm0
	X86_MEM_WRITE_u32(base, 0x571774u, ctx.xmm[0].u32[0]);
	// 0x2AE8B8: ret
	return;
}

void sub_2AE8C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE8C0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AE8C8: movss [0x0057157C], xmm0
	X86_MEM_WRITE_u32(base, 0x57157Cu, ctx.xmm[0].u32[0]);
	// 0x2AE8D0: ret
	return;
}

void sub_2AE8E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE8E0: movss xmm0, dword ptr [0x0057160C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57160Cu);
	// 0x2AE8E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE8F0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AE8F8: movss [0x0057171C], xmm0
	X86_MEM_WRITE_u32(base, 0x57171Cu, ctx.xmm[0].u32[0]);
	// 0x2AE900: ret
	return;
}

void sub_2AE910(X86Context& ctx, uint8_t* base) {
	// 0x2AE910: movss xmm0, dword ptr [0x00571738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571738u);
	// 0x2AE918: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE920: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AE928: movss [0x005715D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5715D4u, ctx.xmm[0].u32[0]);
	// 0x2AE930: ret
	return;
}

void sub_2AE940(X86Context& ctx, uint8_t* base) {
	// 0x2AE940: movss xmm0, dword ptr [0x0057160C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57160Cu);
	// 0x2AE948: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE950: movss [0x005715E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5715E4u, ctx.xmm[0].u32[0]);
	// 0x2AE958: ret
	return;
}

void sub_2AE960(X86Context& ctx, uint8_t* base) {
	// 0x2AE960: movss xmm0, dword ptr [0x00571738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571738u);
	// 0x2AE968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AE970: movss [0x0057175C], xmm0
	X86_MEM_WRITE_u32(base, 0x57175Cu, ctx.xmm[0].u32[0]);
	// 0x2AE978: ret
	return;
}

void sub_2AE980(X86Context& ctx, uint8_t* base) {
	// 0x2AE980: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AE988: movss [0x00571580], xmm0
	X86_MEM_WRITE_u32(base, 0x571580u, ctx.xmm[0].u32[0]);
	// 0x2AE990: ret
	return;
}

void sub_2AE9A0(X86Context& ctx, uint8_t* base) {
	// 0x2AE9A0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AE9A8: movss [0x00571628], xmm0
	X86_MEM_WRITE_u32(base, 0x571628u, ctx.xmm[0].u32[0]);
	// 0x2AE9B0: ret
	return;
}

void sub_2AE9C0(X86Context& ctx, uint8_t* base) {
	// 0x2AE9C0: movss xmm0, dword ptr [0x00571580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571580u);
	// 0x2AE9C8: movss [0x005717A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5717A0u, ctx.xmm[0].u32[0]);
	// 0x2AE9D0: ret
	return;
}

void sub_2AE9E0(X86Context& ctx, uint8_t* base) {
	// 0x2AE9E0: movss xmm0, dword ptr [0x00571738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571738u);
	// 0x2AE9E8: subss xmm0, [0x00571580]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571580u);
	// 0x2AE9F0: movss [0x005716C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5716C0u, ctx.xmm[0].u32[0]);
	// 0x2AE9F8: ret
	return;
}

void sub_2AEA00(X86Context& ctx, uint8_t* base) {
	// 0x2AEA00: movss xmm0, dword ptr [0x005716C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716C0u);
	// 0x2AEA08: subss xmm0, [0x00571628]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571628u);
	// 0x2AEA10: movss [0x005716A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5716A0u, ctx.xmm[0].u32[0]);
	// 0x2AEA18: ret
	return;
}

void sub_2AEA20(X86Context& ctx, uint8_t* base) {
	// 0x2AEA20: movss xmm0, dword ptr [0x0057175C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57175Cu);
	// 0x2AEA28: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AEA30: movss [0x00571660], xmm0
	X86_MEM_WRITE_u32(base, 0x571660u, ctx.xmm[0].u32[0]);
	// 0x2AEA38: ret
	return;
}

void sub_2AEA40(X86Context& ctx, uint8_t* base) {
	// 0x2AEA40: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AEA48: movss [0x00571624], xmm0
	X86_MEM_WRITE_u32(base, 0x571624u, ctx.xmm[0].u32[0]);
	// 0x2AEA50: ret
	return;
}

void sub_2AEA60(X86Context& ctx, uint8_t* base) {
	// 0x2AEA60: movss xmm0, dword ptr [0x00571660]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571660u);
	// 0x2AEA68: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AEA70: movss [0x0057170C], xmm0
	X86_MEM_WRITE_u32(base, 0x57170Cu, ctx.xmm[0].u32[0]);
	// 0x2AEA78: ret
	return;
}

void sub_2AEA80(X86Context& ctx, uint8_t* base) {
	// 0x2AEA80: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2AEA88: movss [0x00571674], xmm0
	X86_MEM_WRITE_u32(base, 0x571674u, ctx.xmm[0].u32[0]);
	// 0x2AEA90: ret
	return;
}

void sub_2AEAA0(X86Context& ctx, uint8_t* base) {
	// 0x2AEAA0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2AEAA8: movss [0x00571600], xmm0
	X86_MEM_WRITE_u32(base, 0x571600u, ctx.xmm[0].u32[0]);
	// 0x2AEAB0: ret
	return;
}

void sub_2AEAC0(X86Context& ctx, uint8_t* base) {
	// 0x2AEAC0: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2AEAC8: movss [0x005715DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5715DCu, ctx.xmm[0].u32[0]);
	// 0x2AEAD0: ret
	return;
}

void sub_2AEAE0(X86Context& ctx, uint8_t* base) {
	// 0x2AEAE0: movss xmm0, dword ptr [0x005715DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715DCu);
	// 0x2AEAE8: addss xmm0, [0x003A69BC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69BCu);
	// 0x2AEAF0: movss [0x005715D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5715D0u, ctx.xmm[0].u32[0]);
	// 0x2AEAF8: ret
	return;
}

void sub_2AEB00(X86Context& ctx, uint8_t* base) {
	// 0x2AEB00: movss xmm0, dword ptr [0x005715D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715D0u);
	// 0x2AEB08: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x2AEB10: movss [0x00571688], xmm0
	X86_MEM_WRITE_u32(base, 0x571688u, ctx.xmm[0].u32[0]);
	// 0x2AEB18: ret
	return;
}

void sub_2AEB20(X86Context& ctx, uint8_t* base) {
	// 0x2AEB20: movss xmm0, dword ptr [0x00571688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571688u);
	// 0x2AEB28: movss [0x00571664], xmm0
	X86_MEM_WRITE_u32(base, 0x571664u, ctx.xmm[0].u32[0]);
	// 0x2AEB30: ret
	return;
}

void sub_2AEB40(X86Context& ctx, uint8_t* base) {
	// 0x2AEB40: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2AEB48: movss [0x005715C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5715C0u, ctx.xmm[0].u32[0]);
	// 0x2AEB50: ret
	return;
}

void sub_2AEB60(X86Context& ctx, uint8_t* base) {
	// 0x2AEB60: movss xmm0, dword ptr [0x005715C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715C0u);
	// 0x2AEB68: addss xmm0, [0x003A69BC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69BCu);
	// 0x2AEB70: movss [0x005715EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5715ECu, ctx.xmm[0].u32[0]);
	// 0x2AEB78: ret
	return;
}

void sub_2AEB80(X86Context& ctx, uint8_t* base) {
	// 0x2AEB80: movss xmm0, dword ptr [0x005715EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715ECu);
	// 0x2AEB88: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x2AEB90: movss [0x005715A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5715A4u, ctx.xmm[0].u32[0]);
	// 0x2AEB98: ret
	return;
}

void sub_2AEBA0(X86Context& ctx, uint8_t* base) {
	// 0x2AEBA0: mov eax, [0x004080D8]
	ctx.eax = X86_MEM_READ_u32(base, 0x4080D8u);
	// 0x2AEBA5: mov ecx, [0x004080DC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x4080DCu);
	// 0x2AEBAB: mov [0x00571780], eax
	X86_MEM_WRITE_u32(base, 0x571780u, ctx.eax);
	// 0x2AEBB0: mov [0x00571784], ecx
	X86_MEM_WRITE_u32(base, 0x571784u, ctx.ecx);
	// 0x2AEBB6: ret
	return;
}

void sub_2AEBC0(X86Context& ctx, uint8_t* base) {
	// 0x2AEBC0: mov eax, [0x004080D8]
	ctx.eax = X86_MEM_READ_u32(base, 0x4080D8u);
	// 0x2AEBC5: mov ecx, [0x004080DC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x4080DCu);
	// 0x2AEBCB: mov [0x00571640], eax
	X86_MEM_WRITE_u32(base, 0x571640u, ctx.eax);
	// 0x2AEBD0: mov [0x00571644], ecx
	X86_MEM_WRITE_u32(base, 0x571644u, ctx.ecx);
	// 0x2AEBD6: ret
	return;
}

void sub_2AEBE0(X86Context& ctx, uint8_t* base) {
	// 0x2AEBE0: mov eax, [0x00571640]
	ctx.eax = X86_MEM_READ_u32(base, 0x571640u);
	// 0x2AEBE5: mov ecx, [0x00571644]
	ctx.ecx = X86_MEM_READ_u32(base, 0x571644u);
	// 0x2AEBEB: mov [0x005715C8], eax
	X86_MEM_WRITE_u32(base, 0x5715C8u, ctx.eax);
	// 0x2AEBF0: mov [0x005715CC], ecx
	X86_MEM_WRITE_u32(base, 0x5715CCu, ctx.ecx);
	// 0x2AEBF6: ret
	return;
}

