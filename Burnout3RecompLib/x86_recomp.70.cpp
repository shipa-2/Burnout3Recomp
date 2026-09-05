#include "x86_recomp_shared.h"

void sub_2AEC00(X86Context& ctx, uint8_t* base) {
	// 0x2AEC00: movss xmm0, dword ptr [0x003B22CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22CCu);
	// 0x2AEC08: movss [0x005716C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5716C4u, ctx.xmm[0].u32[0]);
	// 0x2AEC10: ret
	return;
}

void sub_2AEC20(X86Context& ctx, uint8_t* base) {
	// 0x2AEC20: movss xmm0, dword ptr [0x003B20EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B20ECu);
	// 0x2AEC28: movss [0x005715F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5715F4u, ctx.xmm[0].u32[0]);
	// 0x2AEC30: ret
	return;
}

void sub_2AEC40(X86Context& ctx, uint8_t* base) {
	// 0x2AEC40: movss xmm0, dword ptr [0x003B1A98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A98u);
	// 0x2AEC48: movss [0x005716DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5716DCu, ctx.xmm[0].u32[0]);
	// 0x2AEC50: ret
	return;
}

void sub_2AEC60(X86Context& ctx, uint8_t* base) {
	// 0x2AEC60: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AEC68: movss [0x005716E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5716E0u, ctx.xmm[0].u32[0]);
	// 0x2AEC70: ret
	return;
}

void sub_2AEC80(X86Context& ctx, uint8_t* base) {
	// 0x2AEC80: movss xmm0, dword ptr [0x003B1A98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A98u);
	// 0x2AEC88: movss [0x005715D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5715D8u, ctx.xmm[0].u32[0]);
	// 0x2AEC90: ret
	return;
}

void sub_2AECA0(X86Context& ctx, uint8_t* base) {
	// 0x2AECA0: movss xmm0, dword ptr [0x005715D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715D8u);
	// 0x2AECA8: movss [0x005715A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5715A0u, ctx.xmm[0].u32[0]);
	// 0x2AECB0: ret
	return;
}

void sub_2AECC0(X86Context& ctx, uint8_t* base) {
	// 0x2AECC0: movss xmm0, dword ptr [0x005715D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715D8u);
	// 0x2AECC8: movss [0x0057162C], xmm0
	X86_MEM_WRITE_u32(base, 0x57162Cu, ctx.xmm[0].u32[0]);
	// 0x2AECD0: ret
	return;
}

void sub_2AECE0(X86Context& ctx, uint8_t* base) {
	// 0x2AECE0: movss xmm0, dword ptr [0x003B208C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B208Cu);
	// 0x2AECE8: movss [0x00571654], xmm0
	X86_MEM_WRITE_u32(base, 0x571654u, ctx.xmm[0].u32[0]);
	// 0x2AECF0: ret
	return;
}

void sub_2AED00(X86Context& ctx, uint8_t* base) {
	// 0x2AED00: movss xmm0, dword ptr [0x003B18BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B18BCu);
	// 0x2AED08: movss [0x00571788], xmm0
	X86_MEM_WRITE_u32(base, 0x571788u, ctx.xmm[0].u32[0]);
	// 0x2AED10: ret
	return;
}

void sub_2AED20(X86Context& ctx, uint8_t* base) {
	// 0x2AED20: movss xmm0, dword ptr [0x005715D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715D8u);
	// 0x2AED28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AED30: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AED38: movss [0x00571720], xmm0
	X86_MEM_WRITE_u32(base, 0x571720u, ctx.xmm[0].u32[0]);
	// 0x2AED40: ret
	return;
}

void sub_2AED50(X86Context& ctx, uint8_t* base) {
	// 0x2AED50: movss xmm0, dword ptr [0x005716E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716E0u);
	// 0x2AED58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AED60: movss [0x005716D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5716D0u, ctx.xmm[0].u32[0]);
	// 0x2AED68: ret
	return;
}

void sub_2AED70(X86Context& ctx, uint8_t* base) {
	// 0x2AED70: movss xmm0, dword ptr [0x005715D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715D8u);
	// 0x2AED78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AED80: movss [0x00571684], xmm0
	X86_MEM_WRITE_u32(base, 0x571684u, ctx.xmm[0].u32[0]);
	// 0x2AED88: ret
	return;
}

void sub_2AED90(X86Context& ctx, uint8_t* base) {
	// 0x2AED90: movss xmm0, dword ptr [0x005716E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716E0u);
	// 0x2AED98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AEDA0: movss [0x00571704], xmm0
	X86_MEM_WRITE_u32(base, 0x571704u, ctx.xmm[0].u32[0]);
	// 0x2AEDA8: ret
	return;
}

void sub_2AEDB0(X86Context& ctx, uint8_t* base) {
	// 0x2AEDB0: movss xmm0, dword ptr [0x003B22D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22D0u);
	// 0x2AEDB8: movss [0x0057166C], xmm0
	X86_MEM_WRITE_u32(base, 0x57166Cu, ctx.xmm[0].u32[0]);
	// 0x2AEDC0: ret
	return;
}

void sub_2AEDD0(X86Context& ctx, uint8_t* base) {
	// 0x2AEDD0: movss xmm0, dword ptr [0x00395840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395840u);
	// 0x2AEDD8: movss [0x005717A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5717A4u, ctx.xmm[0].u32[0]);
	// 0x2AEDE0: ret
	return;
}

void sub_2AEDF0(X86Context& ctx, uint8_t* base) {
	// 0x2AEDF0: movss xmm0, dword ptr [0x005717A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717A4u);
	// 0x2AEDF8: subss xmm0, [0x0057166C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57166Cu);
	// 0x2AEE00: mulss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AEE08: movss [0x005715E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5715E8u, ctx.xmm[0].u32[0]);
	// 0x2AEE10: ret
	return;
}

void sub_2AEE20(X86Context& ctx, uint8_t* base) {
	// 0x2AEE20: movss xmm0, dword ptr [0x00397540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397540u);
	// 0x2AEE28: movss [0x005715AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5715ACu, ctx.xmm[0].u32[0]);
	// 0x2AEE30: ret
	return;
}

void sub_2AEE40(X86Context& ctx, uint8_t* base) {
	// 0x2AEE40: movss xmm0, dword ptr [0x00398B94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398B94u);
	// 0x2AEE48: movss [0x00571714], xmm0
	X86_MEM_WRITE_u32(base, 0x571714u, ctx.xmm[0].u32[0]);
	// 0x2AEE50: ret
	return;
}

void sub_2AEE60(X86Context& ctx, uint8_t* base) {
	// 0x2AEE60: movss xmm0, dword ptr [0x00571714]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571714u);
	// 0x2AEE68: addss xmm0, [0x003B1E24]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1E24u);
	// 0x2AEE70: movss [0x005716AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5716ACu, ctx.xmm[0].u32[0]);
	// 0x2AEE78: ret
	return;
}

void sub_2AEE80(X86Context& ctx, uint8_t* base) {
	// 0x2AEE80: movss xmm0, dword ptr [0x005716E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716E0u);
	// 0x2AEE88: subss xmm0, [0x00571714]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571714u);
	// 0x2AEE90: movss [0x00571604], xmm0
	X86_MEM_WRITE_u32(base, 0x571604u, ctx.xmm[0].u32[0]);
	// 0x2AEE98: ret
	return;
}

void sub_2AEEA0(X86Context& ctx, uint8_t* base) {
	// 0x2AEEA0: movss xmm0, dword ptr [0x003B22D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22D4u);
	// 0x2AEEA8: movss [0x005715E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5715E0u, ctx.xmm[0].u32[0]);
	// 0x2AEEB0: ret
	return;
}

void sub_2AEEC0(X86Context& ctx, uint8_t* base) {
	// 0x2AEEC0: movss xmm0, dword ptr [0x003B1798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1798u);
	// 0x2AEEC8: movss [0x00571638], xmm0
	X86_MEM_WRITE_u32(base, 0x571638u, ctx.xmm[0].u32[0]);
	// 0x2AEED0: ret
	return;
}

void sub_2AEEE0(X86Context& ctx, uint8_t* base) {
	// 0x2AEEE0: movss xmm0, dword ptr [0x003F831C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F831Cu);
	// 0x2AEEE8: movss [0x00571610], xmm0
	X86_MEM_WRITE_u32(base, 0x571610u, ctx.xmm[0].u32[0]);
	// 0x2AEEF0: ret
	return;
}

void sub_2AEF00(X86Context& ctx, uint8_t* base) {
	// 0x2AEF00: movss xmm0, dword ptr [0x003B1A10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A10u);
	// 0x2AEF08: movss [0x00571778], xmm0
	X86_MEM_WRITE_u32(base, 0x571778u, ctx.xmm[0].u32[0]);
	// 0x2AEF10: ret
	return;
}

void sub_2AEF20(X86Context& ctx, uint8_t* base) {
	// 0x2AEF20: movss xmm0, dword ptr [0x003B22D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22D8u);
	// 0x2AEF28: movss [0x00571650], xmm0
	X86_MEM_WRITE_u32(base, 0x571650u, ctx.xmm[0].u32[0]);
	// 0x2AEF30: ret
	return;
}

void sub_2AEF40(X86Context& ctx, uint8_t* base) {
	// 0x2AEF40: movss xmm0, dword ptr [0x003B22B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B0u);
	// 0x2AEF48: movss [0x00571658], xmm0
	X86_MEM_WRITE_u32(base, 0x571658u, ctx.xmm[0].u32[0]);
	// 0x2AEF50: ret
	return;
}

void sub_2AEF60(X86Context& ctx, uint8_t* base) {
	// 0x2AEF60: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2AEF68: divss xmm0, [0x00571658]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571658u);
	// 0x2AEF70: movss [0x005716B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5716B4u, ctx.xmm[0].u32[0]);
	// 0x2AEF78: ret
	return;
}

void sub_2AEF80(X86Context& ctx, uint8_t* base) {
	// 0x2AEF80: movss xmm0, dword ptr [0x00571714]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571714u);
	// 0x2AEF88: movss [0x00571614], xmm0
	X86_MEM_WRITE_u32(base, 0x571614u, ctx.xmm[0].u32[0]);
	// 0x2AEF90: ret
	return;
}

void sub_2AEFA0(X86Context& ctx, uint8_t* base) {
	// 0x2AEFA0: movss xmm0, dword ptr [0x00397540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397540u);
	// 0x2AEFA8: movss [0x0057165C], xmm0
	X86_MEM_WRITE_u32(base, 0x57165Cu, ctx.xmm[0].u32[0]);
	// 0x2AEFB0: ret
	return;
}

void sub_2AEFC0(X86Context& ctx, uint8_t* base) {
	// 0x2AEFC0: movss xmm0, dword ptr [0x0057165C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57165Cu);
	// 0x2AEFC8: movss [0x005717B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5717B4u, ctx.xmm[0].u32[0]);
	// 0x2AEFD0: ret
	return;
}

void sub_2AEFE0(X86Context& ctx, uint8_t* base) {
	// 0x2AEFE0: movss xmm0, dword ptr [0x003B1DF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1DF8u);
	// 0x2AEFE8: movss [0x00571630], xmm0
	X86_MEM_WRITE_u32(base, 0x571630u, ctx.xmm[0].u32[0]);
	// 0x2AEFF0: ret
	return;
}

void sub_2AF000(X86Context& ctx, uint8_t* base) {
	// 0x2AF000: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AF008: movss [0x00571620], xmm0
	X86_MEM_WRITE_u32(base, 0x571620u, ctx.xmm[0].u32[0]);
	// 0x2AF010: ret
	return;
}

void sub_2AF020(X86Context& ctx, uint8_t* base) {
	// 0x2AF020: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AF028: movss [0x00571794], xmm0
	X86_MEM_WRITE_u32(base, 0x571794u, ctx.xmm[0].u32[0]);
	// 0x2AF030: ret
	return;
}

void sub_2AF040(X86Context& ctx, uint8_t* base) {
	// 0x2AF040: movss xmm0, dword ptr [0x003895BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x2AF048: movss [0x00571748], xmm0
	X86_MEM_WRITE_u32(base, 0x571748u, ctx.xmm[0].u32[0]);
	// 0x2AF050: ret
	return;
}

void sub_2AF060(X86Context& ctx, uint8_t* base) {
	// 0x2AF060: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AF068: movss [0x005717B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5717B8u, ctx.xmm[0].u32[0]);
	// 0x2AF070: ret
	return;
}

void sub_2AF080(X86Context& ctx, uint8_t* base) {
	// 0x2AF080: movss xmm0, dword ptr [0x003B1750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2AF088: movss [0x005715FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5715FCu, ctx.xmm[0].u32[0]);
	// 0x2AF090: ret
	return;
}

void sub_2AF0A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF0A0: movss xmm0, dword ptr [0x005715FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715FCu);
	// 0x2AF0A8: addss xmm0, [0x003B16E8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16E8u);
	// 0x2AF0B0: movss [0x0057176C], xmm0
	X86_MEM_WRITE_u32(base, 0x57176Cu, ctx.xmm[0].u32[0]);
	// 0x2AF0B8: ret
	return;
}

void sub_2AF0C0(X86Context& ctx, uint8_t* base) {
	// 0x2AF0C0: movss xmm0, dword ptr [0x0057176C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57176Cu);
	// 0x2AF0C8: addss xmm0, [0x003A69B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69B4u);
	// 0x2AF0D0: movss [0x005717C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5717C4u, ctx.xmm[0].u32[0]);
	// 0x2AF0D8: ret
	return;
}

void sub_2AF0E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF0E0: movss xmm0, dword ptr [0x005717C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717C4u);
	// 0x2AF0E8: addss xmm0, [0x003A5600]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A5600u);
	// 0x2AF0F0: movss [0x00571798], xmm0
	X86_MEM_WRITE_u32(base, 0x571798u, ctx.xmm[0].u32[0]);
	// 0x2AF0F8: ret
	return;
}

void sub_2AF100(X86Context& ctx, uint8_t* base) {
	// 0x2AF100: movss xmm0, dword ptr [0x00571798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571798u);
	// 0x2AF108: addss xmm0, [0x003B16E8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16E8u);
	// 0x2AF110: movss [0x005717C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5717C0u, ctx.xmm[0].u32[0]);
	// 0x2AF118: ret
	return;
}

void sub_2AF120(X86Context& ctx, uint8_t* base) {
	// 0x2AF120: movss xmm0, dword ptr [0x005717C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717C0u);
	// 0x2AF128: movss [0x00571668], xmm0
	X86_MEM_WRITE_u32(base, 0x571668u, ctx.xmm[0].u32[0]);
	// 0x2AF130: ret
	return;
}

void sub_2AF140(X86Context& ctx, uint8_t* base) {
	// 0x2AF140: movss xmm0, dword ptr [0x003B1DF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1DF8u);
	// 0x2AF148: movss [0x005716A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5716A8u, ctx.xmm[0].u32[0]);
	// 0x2AF150: ret
	return;
}

void sub_2AF160(X86Context& ctx, uint8_t* base) {
	// 0x2AF160: movss xmm0, dword ptr [0x003B1DF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1DF8u);
	// 0x2AF168: movss [0x005716B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5716B0u, ctx.xmm[0].u32[0]);
	// 0x2AF170: ret
	return;
}

void sub_2AF180(X86Context& ctx, uint8_t* base) {
	// 0x2AF180: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2AF188: movss [0x00571758], xmm0
	X86_MEM_WRITE_u32(base, 0x571758u, ctx.xmm[0].u32[0]);
	// 0x2AF190: ret
	return;
}

void sub_2AF1A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF1A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AF1A8: movss [0x00571770], xmm0
	X86_MEM_WRITE_u32(base, 0x571770u, ctx.xmm[0].u32[0]);
	// 0x2AF1B0: ret
	return;
}

void sub_2AF1C0(X86Context& ctx, uint8_t* base) {
	// 0x2AF1C0: movss xmm0, dword ptr [0x0039B6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B6ECu);
	// 0x2AF1C8: movss [0x0057179C], xmm0
	X86_MEM_WRITE_u32(base, 0x57179Cu, ctx.xmm[0].u32[0]);
	// 0x2AF1D0: ret
	return;
}

void sub_2AF1E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF1E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AF1E8: movss [0x00571678], xmm0
	X86_MEM_WRITE_u32(base, 0x571678u, ctx.xmm[0].u32[0]);
	// 0x2AF1F0: ret
	return;
}

void sub_2AF200(X86Context& ctx, uint8_t* base) {
	// 0x2AF200: movss xmm0, dword ptr [0x003B22DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22DCu);
	// 0x2AF208: movss [0x00571734], xmm0
	X86_MEM_WRITE_u32(base, 0x571734u, ctx.xmm[0].u32[0]);
	// 0x2AF210: ret
	return;
}

void sub_2AF220(X86Context& ctx, uint8_t* base) {
	// 0x2AF220: movss xmm0, dword ptr [0x00571734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571734u);
	// 0x2AF228: subss xmm0, [0x00571678]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571678u);
	// 0x2AF230: movss [0x005716BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5716BCu, ctx.xmm[0].u32[0]);
	// 0x2AF238: ret
	return;
}

void sub_2AF240(X86Context& ctx, uint8_t* base) {
	// 0x2AF240: movss xmm0, dword ptr [0x003A69C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A69C4u);
	// 0x2AF248: movss [0x00571560], xmm0
	X86_MEM_WRITE_u32(base, 0x571560u, ctx.xmm[0].u32[0]);
	// 0x2AF250: ret
	return;
}

void sub_2AF260(X86Context& ctx, uint8_t* base) {
	// 0x2AF260: movss xmm0, dword ptr [0x00571560]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571560u);
	// 0x2AF268: addss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x2AF270: movss [0x00571690], xmm0
	X86_MEM_WRITE_u32(base, 0x571690u, ctx.xmm[0].u32[0]);
	// 0x2AF278: ret
	return;
}

void sub_2AF280(X86Context& ctx, uint8_t* base) {
	// 0x2AF280: movss xmm0, dword ptr [0x00571690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571690u);
	// 0x2AF288: movss [0x00571564], xmm0
	X86_MEM_WRITE_u32(base, 0x571564u, ctx.xmm[0].u32[0]);
	// 0x2AF290: ret
	return;
}

void sub_2AF2A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF2A0: movss xmm0, dword ptr [0x00571564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571564u);
	// 0x2AF2A8: addss xmm0, [0x003B1750]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1750u);
	// 0x2AF2B0: movss [0x005717D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5717D0u, ctx.xmm[0].u32[0]);
	// 0x2AF2B8: ret
	return;
}

void sub_2AF2C0(X86Context& ctx, uint8_t* base) {
	// 0x2AF2C0: movss xmm0, dword ptr [0x005717D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717D0u);
	// 0x2AF2C8: addss xmm0, [0x003B1A78]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1A78u);
	// 0x2AF2D0: movss [0x005715B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5715B8u, ctx.xmm[0].u32[0]);
	// 0x2AF2D8: ret
	return;
}

void sub_2AF2E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF2E0: movss xmm0, dword ptr [0x005715B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715B8u);
	// 0x2AF2E8: movss [0x0057178C], xmm0
	X86_MEM_WRITE_u32(base, 0x57178Cu, ctx.xmm[0].u32[0]);
	// 0x2AF2F0: ret
	return;
}

void sub_2AF300(X86Context& ctx, uint8_t* base) {
	// 0x2AF300: movss xmm0, dword ptr [0x0057178C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57178Cu);
	// 0x2AF308: movss [0x005716D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5716D4u, ctx.xmm[0].u32[0]);
	// 0x2AF310: ret
	return;
}

void sub_2AF320(X86Context& ctx, uint8_t* base) {
	// 0x2AF320: movss xmm0, dword ptr [0x005716D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716D4u);
	// 0x2AF328: addss xmm0, [0x003B16E8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16E8u);
	// 0x2AF330: movss [0x0057161C], xmm0
	X86_MEM_WRITE_u32(base, 0x57161Cu, ctx.xmm[0].u32[0]);
	// 0x2AF338: ret
	return;
}

void sub_2AF340(X86Context& ctx, uint8_t* base) {
	// 0x2AF340: movss xmm0, dword ptr [0x0057161C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57161Cu);
	// 0x2AF348: movss [0x005717AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5717ACu, ctx.xmm[0].u32[0]);
	// 0x2AF350: ret
	return;
}

void sub_2AF360(X86Context& ctx, uint8_t* base) {
	// 0x2AF360: movss xmm0, dword ptr [0x005717AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717ACu);
	// 0x2AF368: addss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AF370: movss [0x005716B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5716B8u, ctx.xmm[0].u32[0]);
	// 0x2AF378: ret
	return;
}

void sub_2AF380(X86Context& ctx, uint8_t* base) {
	// 0x2AF380: movss xmm0, dword ptr [0x005716B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716B8u);
	// 0x2AF388: addss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AF390: movss [0x005715BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5715BCu, ctx.xmm[0].u32[0]);
	// 0x2AF398: ret
	return;
}

void sub_2AF3A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF3A0: movss xmm0, dword ptr [0x005715BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715BCu);
	// 0x2AF3A8: addss xmm0, [0x003B1750]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1750u);
	// 0x2AF3B0: movss [0x0057156C], xmm0
	X86_MEM_WRITE_u32(base, 0x57156Cu, ctx.xmm[0].u32[0]);
	// 0x2AF3B8: ret
	return;
}

void sub_2AF3C0(X86Context& ctx, uint8_t* base) {
	// 0x2AF3C0: movss xmm0, dword ptr [0x003B22E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22E0u);
	// 0x2AF3C8: movss [0x00571590], xmm0
	X86_MEM_WRITE_u32(base, 0x571590u, ctx.xmm[0].u32[0]);
	// 0x2AF3D0: ret
	return;
}

void sub_2AF3E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF3E0: movss xmm0, dword ptr [0x003B22E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22E4u);
	// 0x2AF3E8: movss [0x005716CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5716CCu, ctx.xmm[0].u32[0]);
	// 0x2AF3F0: ret
	return;
}

void sub_2AF400(X86Context& ctx, uint8_t* base) {
	// 0x2AF400: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2AF401: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2AF403: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2AF406: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2AF409: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AF411: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2AF416: movss xmm0, dword ptr [0x003B2100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2100u);
	// 0x2AF41E: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2AF421: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2AF427: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2AF42B: mov [0x00571698], eax
	X86_MEM_WRITE_u32(base, 0x571698u, ctx.eax);
	// 0x2AF430: mov [0x0057169C], ecx
	X86_MEM_WRITE_u32(base, 0x57169Cu, ctx.ecx);
	// 0x2AF436: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2AF438: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2AF439: ret
	return;
}

void sub_2AF440(X86Context& ctx, uint8_t* base) {
	// 0x2AF440: movss xmm0, dword ptr [0x003B1824]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1824u);
	// 0x2AF448: movss [0x00571760], xmm0
	X86_MEM_WRITE_u32(base, 0x571760u, ctx.xmm[0].u32[0]);
	// 0x2AF450: ret
	return;
}

void sub_2AF460(X86Context& ctx, uint8_t* base) {
	// 0x2AF460: movss xmm0, dword ptr [0x003B1698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x2AF468: movss [0x0057168C], xmm0
	X86_MEM_WRITE_u32(base, 0x57168Cu, ctx.xmm[0].u32[0]);
	// 0x2AF470: ret
	return;
}

void sub_2AF480(X86Context& ctx, uint8_t* base) {
	// 0x2AF480: movss xmm0, dword ptr [0x003B2154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2154u);
	// 0x2AF488: movss [0x0057164C], xmm0
	X86_MEM_WRITE_u32(base, 0x57164Cu, ctx.xmm[0].u32[0]);
	// 0x2AF490: ret
	return;
}

void sub_2AF4A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF4A0: movss xmm0, dword ptr [0x003B17D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17D0u);
	// 0x2AF4A8: movss [0x0057177C], xmm0
	X86_MEM_WRITE_u32(base, 0x57177Cu, ctx.xmm[0].u32[0]);
	// 0x2AF4B0: ret
	return;
}

void sub_2AF4C0(X86Context& ctx, uint8_t* base) {
	// 0x2AF4C0: movss xmm0, dword ptr [0x005716C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716C4u);
	// 0x2AF4C8: addss xmm0, [0x003B178C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B178Cu);
	// 0x2AF4D0: movss [0x00571598], xmm0
	X86_MEM_WRITE_u32(base, 0x571598u, ctx.xmm[0].u32[0]);
	// 0x2AF4D8: ret
	return;
}

void sub_2AF4E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF4E0: movss xmm0, dword ptr [0x005715F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5715F4u);
	// 0x2AF4E8: addss xmm0, [0x003B1824]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1824u);
	// 0x2AF4F0: movss [0x005716F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5716F4u, ctx.xmm[0].u32[0]);
	// 0x2AF4F8: ret
	return;
}

void sub_2AF500(X86Context& ctx, uint8_t* base) {
	// 0x2AF500: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AF508: movss [0x0057173C], xmm0
	X86_MEM_WRITE_u32(base, 0x57173Cu, ctx.xmm[0].u32[0]);
	// 0x2AF510: ret
	return;
}

void sub_2AF520(X86Context& ctx, uint8_t* base) {
	// 0x2AF520: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2AF521: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2AF523: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2AF526: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2AF529: movss xmm0, dword ptr [0x003B1870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x2AF531: movss xmm1, dword ptr [0x00408128]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x408128u);
	// 0x2AF539: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2AF53D: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x2AF542: movss xmm1, dword ptr [0x0040812C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x40812Cu);
	// 0x2AF54A: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2AF54D: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2AF551: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x2AF557: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2AF55B: mov [0x005716E8], eax
	X86_MEM_WRITE_u32(base, 0x5716E8u, ctx.eax);
	// 0x2AF560: mov [0x005716EC], ecx
	X86_MEM_WRITE_u32(base, 0x5716ECu, ctx.ecx);
	// 0x2AF566: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2AF568: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2AF569: ret
	return;
}

void sub_2AF570(X86Context& ctx, uint8_t* base) {
	// 0x2AF570: movss xmm0, dword ptr [0x003895BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x2AF578: movss [0x005715B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5715B0u, ctx.xmm[0].u32[0]);
	// 0x2AF580: ret
	return;
}

void sub_2AF590(X86Context& ctx, uint8_t* base) {
	// 0x2AF590: movss xmm0, dword ptr [0x003B1DF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1DF8u);
	// 0x2AF598: movss [0x00571718], xmm0
	X86_MEM_WRITE_u32(base, 0x571718u, ctx.xmm[0].u32[0]);
	// 0x2AF5A0: ret
	return;
}

void sub_2AF5B0(X86Context& ctx, uint8_t* base) {
	// 0x2AF5B0: movss xmm0, dword ptr [0x003A69C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x2AF5B8: movss [0x00571730], xmm0
	X86_MEM_WRITE_u32(base, 0x571730u, ctx.xmm[0].u32[0]);
	// 0x2AF5C0: ret
	return;
}

void sub_2AF5D0(X86Context& ctx, uint8_t* base) {
	// 0x2AF5D0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2AF5D8: divss xmm0, [0x00571730]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571730u);
	// 0x2AF5E0: movss [0x005717CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5717CCu, ctx.xmm[0].u32[0]);
	// 0x2AF5E8: ret
	return;
}

void sub_2AF5F0(X86Context& ctx, uint8_t* base) {
	// 0x2AF5F0: movss xmm0, dword ptr [0x00571608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571608u);
	// 0x2AF5F8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2AF600: movss [0x00571608], xmm0
	X86_MEM_WRITE_u32(base, 0x571608u, ctx.xmm[0].u32[0]);
	// 0x2AF608: ret
	return;
}

void sub_2AF610(X86Context& ctx, uint8_t* base) {
	// 0x2AF610: movss xmm0, dword ptr [0x00571608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571608u);
	// 0x2AF618: addss xmm0, [0x003B1824]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1824u);
	// 0x2AF620: movss [0x005717BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5717BCu, ctx.xmm[0].u32[0]);
	// 0x2AF628: ret
	return;
}

void sub_2AF630(X86Context& ctx, uint8_t* base) {
	// 0x2AF630: movss xmm0, dword ptr [0x005717BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717BCu);
	// 0x2AF638: addss xmm0, [0x003A7950]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A7950u);
	// 0x2AF640: movss [0x00571588], xmm0
	X86_MEM_WRITE_u32(base, 0x571588u, ctx.xmm[0].u32[0]);
	// 0x2AF648: ret
	return;
}

void sub_2AF650(X86Context& ctx, uint8_t* base) {
	// 0x2AF650: movss xmm0, dword ptr [0x003B16B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x2AF658: movss [0x005717A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5717A8u, ctx.xmm[0].u32[0]);
	// 0x2AF660: ret
	return;
}

void sub_2AF670(X86Context& ctx, uint8_t* base) {
	// 0x2AF670: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2AF678: movss [0x00571570], xmm0
	X86_MEM_WRITE_u32(base, 0x571570u, ctx.xmm[0].u32[0]);
	// 0x2AF680: ret
	return;
}

void sub_2AF690(X86Context& ctx, uint8_t* base) {
	// 0x2AF690: movss xmm0, dword ptr [0x003B17D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17D8u);
	// 0x2AF698: movss [0x0057158C], xmm0
	X86_MEM_WRITE_u32(base, 0x57158Cu, ctx.xmm[0].u32[0]);
	// 0x2AF6A0: ret
	return;
}

void sub_2AF6B0(X86Context& ctx, uint8_t* base) {
	// 0x2AF6B0: movss xmm0, dword ptr [0x003B1DF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1DF8u);
	// 0x2AF6B8: movss [0x005715F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5715F8u, ctx.xmm[0].u32[0]);
	// 0x2AF6C0: ret
	return;
}

void sub_2AF6D0(X86Context& ctx, uint8_t* base) {
	// 0x2AF6D0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2AF6D8: divss xmm0, [0x0057158C]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x57158Cu);
	// 0x2AF6E0: movss [0x005716D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5716D8u, ctx.xmm[0].u32[0]);
	// 0x2AF6E8: ret
	return;
}

void sub_2AF6F0(X86Context& ctx, uint8_t* base) {
	// 0x2AF6F0: movss xmm0, dword ptr [0x003895BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x2AF6F8: movss [0x00571710], xmm0
	X86_MEM_WRITE_u32(base, 0x571710u, ctx.xmm[0].u32[0]);
	// 0x2AF700: ret
	return;
}

void sub_2AF710(X86Context& ctx, uint8_t* base) {
	// 0x2AF710: movss xmm0, dword ptr [0x003B1768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x2AF718: movss [0x005715A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5715A8u, ctx.xmm[0].u32[0]);
	// 0x2AF720: ret
	return;
}

void sub_2AF730(X86Context& ctx, uint8_t* base) {
	// 0x2AF730: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2AF738: movss [0x00571724], xmm0
	X86_MEM_WRITE_u32(base, 0x571724u, ctx.xmm[0].u32[0]);
	// 0x2AF740: ret
	return;
}

void sub_2AF750(X86Context& ctx, uint8_t* base) {
	// 0x2AF750: movss xmm0, dword ptr [0x00571724]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571724u);
	// 0x2AF758: addss xmm0, [0x003A5600]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A5600u);
	// 0x2AF760: movss [0x00571700], xmm0
	X86_MEM_WRITE_u32(base, 0x571700u, ctx.xmm[0].u32[0]);
	// 0x2AF768: ret
	return;
}

void sub_2AF770(X86Context& ctx, uint8_t* base) {
	// 0x2AF770: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AF778: movss [0x005715F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5715F0u, ctx.xmm[0].u32[0]);
	// 0x2AF780: ret
	return;
}

void sub_2AF790(X86Context& ctx, uint8_t* base) {
	// 0x2AF790: movss xmm0, dword ptr [0x005717BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717BCu);
	// 0x2AF798: movss [0x00408134], xmm0
	X86_MEM_WRITE_u32(base, 0x408134u, ctx.xmm[0].u32[0]);
	// 0x2AF7A0: ret
	return;
}

void sub_2AF7B0(X86Context& ctx, uint8_t* base) {
	// 0x2AF7B0: movss xmm0, dword ptr [0x00571588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571588u);
	// 0x2AF7B8: movss [0x0040813C], xmm0
	X86_MEM_WRITE_u32(base, 0x40813Cu, ctx.xmm[0].u32[0]);
	// 0x2AF7C0: ret
	return;
}

void sub_2AF7D0(X86Context& ctx, uint8_t* base) {
	// 0x2AF7D0: movss xmm0, dword ptr [0x005717BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717BCu);
	// 0x2AF7D8: movss [0x00408144], xmm0
	X86_MEM_WRITE_u32(base, 0x408144u, ctx.xmm[0].u32[0]);
	// 0x2AF7E0: ret
	return;
}

void sub_2AF7F0(X86Context& ctx, uint8_t* base) {
	// 0x2AF7F0: movss xmm0, dword ptr [0x005717BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717BCu);
	// 0x2AF7F8: movss [0x0040814C], xmm0
	X86_MEM_WRITE_u32(base, 0x40814Cu, ctx.xmm[0].u32[0]);
	// 0x2AF800: ret
	return;
}

void sub_2AF810(X86Context& ctx, uint8_t* base) {
	// 0x2AF810: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2AF811: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2AF813: and esp, 0xFFFFFFF0
	ctx.esp = ctx.esp & -16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2AF816: sub esp, 0x20
	{ uint32_t _d = ctx.esp; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2AF819: movss xmm0, dword ptr [0x003B22EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22ECu);
	// 0x2AF821: movss [esp+0x10], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.xmm[0].u32[0]);
	// 0x2AF827: movss xmm0, dword ptr [0x003B20C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B20C8u);
	// 0x2AF82F: movss [esp+0x14], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.xmm[0].u32[0]);
	// 0x2AF835: movss xmm0, dword ptr [0x003B22E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22E8u);
	// 0x2AF83D: movss [esp+0x18], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.xmm[0].u32[0]);
	// 0x2AF843: movss xmm0, dword ptr [0x003B16C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16C4u);
	// 0x2AF84B: movss [esp+0x1C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.xmm[0].u32[0]);
	// 0x2AF851: movaps xmm1, [esp+0x10]
	X86_MEM_READ_XMM(base, ctx.esp + 0x10u, ctx.xmm[1]);
	// 0x2AF856: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2AF85C: lea eax, [esp+0x0C]
	ctx.eax = ctx.esp + 0xCu;
	// 0x2AF860: movss xmm0, dword ptr [eax]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2AF864: shufps xmm0, xmm0, 0x00
	{ X86XmmReg _tmp;
	  _tmp.f32[0] = ctx.xmm[0].f32[0 & 3];
	  _tmp.f32[1] = ctx.xmm[0].f32[(0 >> 2) & 3];
	  _tmp.f32[2] = ctx.xmm[0].f32[(0 >> 4) & 3];
	  _tmp.f32[3] = ctx.xmm[0].f32[(0 >> 6) & 3];
	  ctx.xmm[0] = _tmp; }
	// 0x2AF868: divps xmm1, xmm0
	X86_SSE_DIVPS(ctx.xmm[1], ctx.xmm[0]);
	// 0x2AF86B: movaps [0x00571550], xmm1
	X86_MEM_WRITE_XMM(base, 0x571550u, ctx.xmm[1]);
	// 0x2AF872: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2AF874: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2AF875: ret
	return;
}

void sub_2AF880(X86Context& ctx, uint8_t* base) {
	// 0x2AF880: movss xmm0, dword ptr [0x005716AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5716ACu);
	// 0x2AF888: addss xmm0, [0x003B17E8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B17E8u);
	// 0x2AF890: movss [0x00408178], xmm0
	X86_MEM_WRITE_u32(base, 0x408178u, ctx.xmm[0].u32[0]);
	// 0x2AF898: ret
	return;
}

void sub_2AF8A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF8A0: movss xmm0, dword ptr [0x00408178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x408178u);
	// 0x2AF8A8: movss [0x00571728], xmm0
	X86_MEM_WRITE_u32(base, 0x571728u, ctx.xmm[0].u32[0]);
	// 0x2AF8B0: movss xmm0, dword ptr [0x00571638]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571638u);
	// 0x2AF8B8: addss xmm0, [0x00398B94]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x398B94u);
	// 0x2AF8C0: mulss xmm0, [0x003B1824]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1824u);
	// 0x2AF8C8: addss xmm0, [0x00397EE0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x397EE0u);
	// 0x2AF8D0: movss [0x0057172C], xmm0
	X86_MEM_WRITE_u32(base, 0x57172Cu, ctx.xmm[0].u32[0]);
	// 0x2AF8D8: ret
	return;
}

void sub_2AF8E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF8E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AF8E8: movss [0x00571828], xmm0
	X86_MEM_WRITE_u32(base, 0x571828u, ctx.xmm[0].u32[0]);
	// 0x2AF8F0: ret
	return;
}

void sub_2AF900(X86Context& ctx, uint8_t* base) {
	// 0x2AF900: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AF908: movss [0x00571844], xmm0
	X86_MEM_WRITE_u32(base, 0x571844u, ctx.xmm[0].u32[0]);
	// 0x2AF910: ret
	return;
}

void sub_2AF920(X86Context& ctx, uint8_t* base) {
	// 0x2AF920: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AF928: movss [0x0057181C], xmm0
	X86_MEM_WRITE_u32(base, 0x57181Cu, ctx.xmm[0].u32[0]);
	// 0x2AF930: ret
	return;
}

void sub_2AF940(X86Context& ctx, uint8_t* base) {
	// 0x2AF940: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AF948: movss [0x005717D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5717D4u, ctx.xmm[0].u32[0]);
	// 0x2AF950: ret
	return;
}

void sub_2AF960(X86Context& ctx, uint8_t* base) {
	// 0x2AF960: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AF968: movss [0x0057182C], xmm0
	X86_MEM_WRITE_u32(base, 0x57182Cu, ctx.xmm[0].u32[0]);
	// 0x2AF970: ret
	return;
}

void sub_2AF980(X86Context& ctx, uint8_t* base) {
	// 0x2AF980: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AF988: movss [0x005717F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5717F0u, ctx.xmm[0].u32[0]);
	// 0x2AF990: ret
	return;
}

void sub_2AF9A0(X86Context& ctx, uint8_t* base) {
	// 0x2AF9A0: movss xmm0, dword ptr [0x0057182C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57182Cu);
	// 0x2AF9A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AF9B0: movss [0x00571864], xmm0
	X86_MEM_WRITE_u32(base, 0x571864u, ctx.xmm[0].u32[0]);
	// 0x2AF9B8: ret
	return;
}

void sub_2AF9C0(X86Context& ctx, uint8_t* base) {
	// 0x2AF9C0: movss xmm0, dword ptr [0x005717F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717F0u);
	// 0x2AF9C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AF9D0: movss [0x0057184C], xmm0
	X86_MEM_WRITE_u32(base, 0x57184Cu, ctx.xmm[0].u32[0]);
	// 0x2AF9D8: ret
	return;
}

void sub_2AF9E0(X86Context& ctx, uint8_t* base) {
	// 0x2AF9E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AF9E8: movss [0x0057187C], xmm0
	X86_MEM_WRITE_u32(base, 0x57187Cu, ctx.xmm[0].u32[0]);
	// 0x2AF9F0: ret
	return;
}

void sub_2AFA00(X86Context& ctx, uint8_t* base) {
	// 0x2AFA00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AFA08: movss [0x00571868], xmm0
	X86_MEM_WRITE_u32(base, 0x571868u, ctx.xmm[0].u32[0]);
	// 0x2AFA10: ret
	return;
}

void sub_2AFA20(X86Context& ctx, uint8_t* base) {
	// 0x2AFA20: movss xmm0, dword ptr [0x00571868]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571868u);
	// 0x2AFA28: movss [0x00571878], xmm0
	X86_MEM_WRITE_u32(base, 0x571878u, ctx.xmm[0].u32[0]);
	// 0x2AFA30: ret
	return;
}

void sub_2AFA40(X86Context& ctx, uint8_t* base) {
	// 0x2AFA40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AFA48: movss [0x005717DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5717DCu, ctx.xmm[0].u32[0]);
	// 0x2AFA50: ret
	return;
}

void sub_2AFA60(X86Context& ctx, uint8_t* base) {
	// 0x2AFA60: movss xmm0, dword ptr [0x005717F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717F0u);
	// 0x2AFA68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AFA70: movss [0x00571870], xmm0
	X86_MEM_WRITE_u32(base, 0x571870u, ctx.xmm[0].u32[0]);
	// 0x2AFA78: ret
	return;
}

void sub_2AFA80(X86Context& ctx, uint8_t* base) {
	// 0x2AFA80: movss xmm0, dword ptr [0x005717F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717F0u);
	// 0x2AFA88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2AFA90: movss [0x00571818], xmm0
	X86_MEM_WRITE_u32(base, 0x571818u, ctx.xmm[0].u32[0]);
	// 0x2AFA98: ret
	return;
}

void sub_2AFAA0(X86Context& ctx, uint8_t* base) {
	// 0x2AFAA0: movss xmm0, dword ptr [0x005717F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717F0u);
	// 0x2AFAA8: subss xmm0, [0x00571818]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571818u);
	// 0x2AFAB0: movss [0x005717F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5717F8u, ctx.xmm[0].u32[0]);
	// 0x2AFAB8: ret
	return;
}

void sub_2AFAC0(X86Context& ctx, uint8_t* base) {
	// 0x2AFAC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2AFAC8: movss [0x00571840], xmm0
	X86_MEM_WRITE_u32(base, 0x571840u, ctx.xmm[0].u32[0]);
	// 0x2AFAD0: ret
	return;
}

void sub_2AFAE0(X86Context& ctx, uint8_t* base) {
	// 0x2AFAE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2AFAE8: movss [0x005717F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5717F4u, ctx.xmm[0].u32[0]);
	// 0x2AFAF0: ret
	return;
}

void sub_2AFB00(X86Context& ctx, uint8_t* base) {
	// 0x2AFB00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AFB08: movss [0x00571804], xmm0
	X86_MEM_WRITE_u32(base, 0x571804u, ctx.xmm[0].u32[0]);
	// 0x2AFB10: ret
	return;
}

void sub_2AFB20(X86Context& ctx, uint8_t* base) {
	// 0x2AFB20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AFB28: movss [0x00571858], xmm0
	X86_MEM_WRITE_u32(base, 0x571858u, ctx.xmm[0].u32[0]);
	// 0x2AFB30: ret
	return;
}

void sub_2AFB40(X86Context& ctx, uint8_t* base) {
	// 0x2AFB40: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2AFB48: movss [0x0057183C], xmm0
	X86_MEM_WRITE_u32(base, 0x57183Cu, ctx.xmm[0].u32[0]);
	// 0x2AFB50: ret
	return;
}

void sub_2AFB60(X86Context& ctx, uint8_t* base) {
	// 0x2AFB60: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2AFB68: movss [0x005717EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5717ECu, ctx.xmm[0].u32[0]);
	// 0x2AFB70: ret
	return;
}

void sub_2AFB80(X86Context& ctx, uint8_t* base) {
	// 0x2AFB80: movss xmm0, dword ptr [0x00571804]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571804u);
	// 0x2AFB88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AFB90: movss [0x005717E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5717E0u, ctx.xmm[0].u32[0]);
	// 0x2AFB98: ret
	return;
}

void sub_2AFBA0(X86Context& ctx, uint8_t* base) {
	// 0x2AFBA0: movss xmm0, dword ptr [0x00571858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571858u);
	// 0x2AFBA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AFBB0: movss [0x00571824], xmm0
	X86_MEM_WRITE_u32(base, 0x571824u, ctx.xmm[0].u32[0]);
	// 0x2AFBB8: ret
	return;
}

void sub_2AFBC0(X86Context& ctx, uint8_t* base) {
	// 0x2AFBC0: movss xmm0, dword ptr [0x005717E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717E0u);
	// 0x2AFBC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AFBD0: movss [0x00571834], xmm0
	X86_MEM_WRITE_u32(base, 0x571834u, ctx.xmm[0].u32[0]);
	// 0x2AFBD8: ret
	return;
}

void sub_2AFBE0(X86Context& ctx, uint8_t* base) {
	// 0x2AFBE0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AFBE8: movss [0x005717D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5717D8u, ctx.xmm[0].u32[0]);
	// 0x2AFBF0: ret
	return;
}

void sub_2AFC00(X86Context& ctx, uint8_t* base) {
	// 0x2AFC00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2AFC08: movss [0x00571808], xmm0
	X86_MEM_WRITE_u32(base, 0x571808u, ctx.xmm[0].u32[0]);
	// 0x2AFC10: ret
	return;
}

void sub_2AFC20(X86Context& ctx, uint8_t* base) {
	// 0x2AFC20: movss xmm0, dword ptr [0x00571804]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571804u);
	// 0x2AFC28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AFC30: movss [0x00571814], xmm0
	X86_MEM_WRITE_u32(base, 0x571814u, ctx.xmm[0].u32[0]);
	// 0x2AFC38: ret
	return;
}

void sub_2AFC40(X86Context& ctx, uint8_t* base) {
	// 0x2AFC40: movss xmm0, dword ptr [0x00571858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571858u);
	// 0x2AFC48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2AFC50: movss [0x0057185C], xmm0
	X86_MEM_WRITE_u32(base, 0x57185Cu, ctx.xmm[0].u32[0]);
	// 0x2AFC58: ret
	return;
}

void sub_2AFC60(X86Context& ctx, uint8_t* base) {
	// 0x2AFC60: movss xmm0, dword ptr [0x00571814]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571814u);
	// 0x2AFC68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AFC70: movss [0x00571848], xmm0
	X86_MEM_WRITE_u32(base, 0x571848u, ctx.xmm[0].u32[0]);
	// 0x2AFC78: ret
	return;
}

void sub_2AFC80(X86Context& ctx, uint8_t* base) {
	// 0x2AFC80: movss xmm0, dword ptr [0x0057185C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57185Cu);
	// 0x2AFC88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AFC90: movss [0x0057186C], xmm0
	X86_MEM_WRITE_u32(base, 0x57186Cu, ctx.xmm[0].u32[0]);
	// 0x2AFC98: ret
	return;
}

void sub_2AFCA0(X86Context& ctx, uint8_t* base) {
	// 0x2AFCA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2AFCA8: movss [0x005717E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5717E4u, ctx.xmm[0].u32[0]);
	// 0x2AFCB0: ret
	return;
}

void sub_2AFCC0(X86Context& ctx, uint8_t* base) {
	// 0x2AFCC0: movss xmm0, dword ptr [0x00571804]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571804u);
	// 0x2AFCC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AFCD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2AFCD8: movss [0x00571854], xmm0
	X86_MEM_WRITE_u32(base, 0x571854u, ctx.xmm[0].u32[0]);
	// 0x2AFCE0: ret
	return;
}

void sub_2AFCF0(X86Context& ctx, uint8_t* base) {
	// 0x2AFCF0: movss xmm0, dword ptr [0x00571858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571858u);
	// 0x2AFCF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AFD00: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2AFD08: movss [0x005717FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5717FCu, ctx.xmm[0].u32[0]);
	// 0x2AFD10: ret
	return;
}

void sub_2AFD20(X86Context& ctx, uint8_t* base) {
	// 0x2AFD20: movss xmm0, dword ptr [0x00571804]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571804u);
	// 0x2AFD28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AFD30: movss [0x00571800], xmm0
	X86_MEM_WRITE_u32(base, 0x571800u, ctx.xmm[0].u32[0]);
	// 0x2AFD38: ret
	return;
}

void sub_2AFD40(X86Context& ctx, uint8_t* base) {
	// 0x2AFD40: movss xmm0, dword ptr [0x00571858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571858u);
	// 0x2AFD48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2AFD50: movss [0x00571860], xmm0
	X86_MEM_WRITE_u32(base, 0x571860u, ctx.xmm[0].u32[0]);
	// 0x2AFD58: ret
	return;
}

void sub_2AFD60(X86Context& ctx, uint8_t* base) {
	// 0x2AFD60: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2AFD68: movss [0x005717E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5717E8u, ctx.xmm[0].u32[0]);
	// 0x2AFD70: ret
	return;
}

void sub_2AFD80(X86Context& ctx, uint8_t* base) {
	// 0x2AFD80: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2AFD88: movss [0x00571810], xmm0
	X86_MEM_WRITE_u32(base, 0x571810u, ctx.xmm[0].u32[0]);
	// 0x2AFD90: ret
	return;
}

void sub_2AFDA0(X86Context& ctx, uint8_t* base) {
	// 0x2AFDA0: movss xmm0, dword ptr [0x005717E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5717E8u);
	// 0x2AFDA8: movss [0x00571874], xmm0
	X86_MEM_WRITE_u32(base, 0x571874u, ctx.xmm[0].u32[0]);
	// 0x2AFDB0: ret
	return;
}

void sub_2AFDC0(X86Context& ctx, uint8_t* base) {
	// 0x2AFDC0: movss xmm0, dword ptr [0x00571858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571858u);
	// 0x2AFDC8: subss xmm0, [0x005717E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5717E8u);
	// 0x2AFDD0: movss [0x00571838], xmm0
	X86_MEM_WRITE_u32(base, 0x571838u, ctx.xmm[0].u32[0]);
	// 0x2AFDD8: ret
	return;
}

void sub_2AFDE0(X86Context& ctx, uint8_t* base) {
	// 0x2AFDE0: movss xmm0, dword ptr [0x00571838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571838u);
	// 0x2AFDE8: subss xmm0, [0x00571810]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571810u);
	// 0x2AFDF0: movss [0x00571830], xmm0
	X86_MEM_WRITE_u32(base, 0x571830u, ctx.xmm[0].u32[0]);
	// 0x2AFDF8: ret
	return;
}

void sub_2AFE00(X86Context& ctx, uint8_t* base) {
	// 0x2AFE00: movss xmm0, dword ptr [0x00571860]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571860u);
	// 0x2AFE08: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2AFE10: movss [0x00571820], xmm0
	X86_MEM_WRITE_u32(base, 0x571820u, ctx.xmm[0].u32[0]);
	// 0x2AFE18: ret
	return;
}

void sub_2AFE20(X86Context& ctx, uint8_t* base) {
	// 0x2AFE20: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2AFE28: movss [0x0057180C], xmm0
	X86_MEM_WRITE_u32(base, 0x57180Cu, ctx.xmm[0].u32[0]);
	// 0x2AFE30: ret
	return;
}

void sub_2AFE40(X86Context& ctx, uint8_t* base) {
	// 0x2AFE40: movss xmm0, dword ptr [0x00571820]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571820u);
	// 0x2AFE48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2AFE50: movss [0x00571850], xmm0
	X86_MEM_WRITE_u32(base, 0x571850u, ctx.xmm[0].u32[0]);
	// 0x2AFE58: ret
	return;
}

void sub_2AFE60(X86Context& ctx, uint8_t* base) {
	// 0x2AFE60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2AFE68: movss [0x005718F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5718F4u, ctx.xmm[0].u32[0]);
	// 0x2AFE70: ret
	return;
}

void sub_2AFE80(X86Context& ctx, uint8_t* base) {
	// 0x2AFE80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2AFE88: movss [0x00571928], xmm0
	X86_MEM_WRITE_u32(base, 0x571928u, ctx.xmm[0].u32[0]);
	// 0x2AFE90: ret
	return;
}

void sub_2AFEA0(X86Context& ctx, uint8_t* base) {
	// 0x2AFEA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2AFEA8: movss [0x005718E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5718E4u, ctx.xmm[0].u32[0]);
	// 0x2AFEB0: ret
	return;
}

void sub_2AFEC0(X86Context& ctx, uint8_t* base) {
	// 0x2AFEC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2AFEC8: movss [0x00571880], xmm0
	X86_MEM_WRITE_u32(base, 0x571880u, ctx.xmm[0].u32[0]);
	// 0x2AFED0: ret
	return;
}

void sub_2AFEE0(X86Context& ctx, uint8_t* base) {
	// 0x2AFEE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2AFEE8: movss [0x005718F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5718F8u, ctx.xmm[0].u32[0]);
	// 0x2AFEF0: ret
	return;
}

void sub_2AFF00(X86Context& ctx, uint8_t* base) {
	// 0x2AFF00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2AFF08: movss [0x005718A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5718A0u, ctx.xmm[0].u32[0]);
	// 0x2AFF10: ret
	return;
}

void sub_2AFF20(X86Context& ctx, uint8_t* base) {
	// 0x2AFF20: movss xmm0, dword ptr [0x005718F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718F8u);
	// 0x2AFF28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2AFF30: movss [0x00571958], xmm0
	X86_MEM_WRITE_u32(base, 0x571958u, ctx.xmm[0].u32[0]);
	// 0x2AFF38: ret
	return;
}

void sub_2AFF40(X86Context& ctx, uint8_t* base) {
	// 0x2AFF40: movss xmm0, dword ptr [0x005718A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718A0u);
	// 0x2AFF48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2AFF50: movss [0x00571930], xmm0
	X86_MEM_WRITE_u32(base, 0x571930u, ctx.xmm[0].u32[0]);
	// 0x2AFF58: ret
	return;
}

void sub_2AFF60(X86Context& ctx, uint8_t* base) {
	// 0x2AFF60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AFF68: movss [0x00571984], xmm0
	X86_MEM_WRITE_u32(base, 0x571984u, ctx.xmm[0].u32[0]);
	// 0x2AFF70: ret
	return;
}

void sub_2AFF80(X86Context& ctx, uint8_t* base) {
	// 0x2AFF80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2AFF88: movss [0x0057195C], xmm0
	X86_MEM_WRITE_u32(base, 0x57195Cu, ctx.xmm[0].u32[0]);
	// 0x2AFF90: ret
	return;
}

void sub_2AFFA0(X86Context& ctx, uint8_t* base) {
	// 0x2AFFA0: movss xmm0, dword ptr [0x0057195C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57195Cu);
	// 0x2AFFA8: movss [0x00571978], xmm0
	X86_MEM_WRITE_u32(base, 0x571978u, ctx.xmm[0].u32[0]);
	// 0x2AFFB0: ret
	return;
}

void sub_2AFFC0(X86Context& ctx, uint8_t* base) {
	// 0x2AFFC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2AFFC8: movss [0x0057188C], xmm0
	X86_MEM_WRITE_u32(base, 0x57188Cu, ctx.xmm[0].u32[0]);
	// 0x2AFFD0: ret
	return;
}

void sub_2AFFE0(X86Context& ctx, uint8_t* base) {
	// 0x2AFFE0: movss xmm0, dword ptr [0x005718A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718A0u);
	// 0x2AFFE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2AFFF0: movss [0x0057196C], xmm0
	X86_MEM_WRITE_u32(base, 0x57196Cu, ctx.xmm[0].u32[0]);
	// 0x2AFFF8: ret
	return;
}

void sub_2B0000(X86Context& ctx, uint8_t* base) {
	// 0x2B0000: movss xmm0, dword ptr [0x005718A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718A0u);
	// 0x2B0008: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B0010: movss [0x005718DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5718DCu, ctx.xmm[0].u32[0]);
	// 0x2B0018: ret
	return;
}

void sub_2B0020(X86Context& ctx, uint8_t* base) {
	// 0x2B0020: movss xmm0, dword ptr [0x005718A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718A0u);
	// 0x2B0028: subss xmm0, [0x005718DC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5718DCu);
	// 0x2B0030: movss [0x005718B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5718B0u, ctx.xmm[0].u32[0]);
	// 0x2B0038: ret
	return;
}

void sub_2B0040(X86Context& ctx, uint8_t* base) {
	// 0x2B0040: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B0048: movss [0x00571924], xmm0
	X86_MEM_WRITE_u32(base, 0x571924u, ctx.xmm[0].u32[0]);
	// 0x2B0050: ret
	return;
}

void sub_2B0060(X86Context& ctx, uint8_t* base) {
	// 0x2B0060: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B0068: movss [0x005718A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5718A8u, ctx.xmm[0].u32[0]);
	// 0x2B0070: ret
	return;
}

void sub_2B0080(X86Context& ctx, uint8_t* base) {
	// 0x2B0080: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B0088: movss [0x005718C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5718C8u, ctx.xmm[0].u32[0]);
	// 0x2B0090: ret
	return;
}

void sub_2B00A0(X86Context& ctx, uint8_t* base) {
	// 0x2B00A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B00A8: movss [0x00571944], xmm0
	X86_MEM_WRITE_u32(base, 0x571944u, ctx.xmm[0].u32[0]);
	// 0x2B00B0: ret
	return;
}

void sub_2B00C0(X86Context& ctx, uint8_t* base) {
	// 0x2B00C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B00C8: movss [0x00571918], xmm0
	X86_MEM_WRITE_u32(base, 0x571918u, ctx.xmm[0].u32[0]);
	// 0x2B00D0: ret
	return;
}

void sub_2B00E0(X86Context& ctx, uint8_t* base) {
	// 0x2B00E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B00E8: movss [0x0057189C], xmm0
	X86_MEM_WRITE_u32(base, 0x57189Cu, ctx.xmm[0].u32[0]);
	// 0x2B00F0: ret
	return;
}

void sub_2B0100(X86Context& ctx, uint8_t* base) {
	// 0x2B0100: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B0108: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B0110: movss [0x00571890], xmm0
	X86_MEM_WRITE_u32(base, 0x571890u, ctx.xmm[0].u32[0]);
	// 0x2B0118: ret
	return;
}

void sub_2B0120(X86Context& ctx, uint8_t* base) {
	// 0x2B0120: movss xmm0, dword ptr [0x00571944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571944u);
	// 0x2B0128: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B0130: movss [0x005718F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5718F0u, ctx.xmm[0].u32[0]);
	// 0x2B0138: ret
	return;
}

void sub_2B0140(X86Context& ctx, uint8_t* base) {
	// 0x2B0140: movss xmm0, dword ptr [0x00571890]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571890u);
	// 0x2B0148: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B0150: movss [0x00571908], xmm0
	X86_MEM_WRITE_u32(base, 0x571908u, ctx.xmm[0].u32[0]);
	// 0x2B0158: ret
	return;
}

void sub_2B0160(X86Context& ctx, uint8_t* base) {
	// 0x2B0160: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B0168: movss [0x00571884], xmm0
	X86_MEM_WRITE_u32(base, 0x571884u, ctx.xmm[0].u32[0]);
	// 0x2B0170: ret
	return;
}

void sub_2B0180(X86Context& ctx, uint8_t* base) {
	// 0x2B0180: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B0188: movss [0x005718CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5718CCu, ctx.xmm[0].u32[0]);
	// 0x2B0190: ret
	return;
}

void sub_2B01A0(X86Context& ctx, uint8_t* base) {
	// 0x2B01A0: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B01A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B01B0: movss [0x005718D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5718D8u, ctx.xmm[0].u32[0]);
	// 0x2B01B8: ret
	return;
}

void sub_2B01C0(X86Context& ctx, uint8_t* base) {
	// 0x2B01C0: movss xmm0, dword ptr [0x00571944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571944u);
	// 0x2B01C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B01D0: movss [0x0057194C], xmm0
	X86_MEM_WRITE_u32(base, 0x57194Cu, ctx.xmm[0].u32[0]);
	// 0x2B01D8: ret
	return;
}

void sub_2B01E0(X86Context& ctx, uint8_t* base) {
	// 0x2B01E0: movss xmm0, dword ptr [0x005718D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718D8u);
	// 0x2B01E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B01F0: movss [0x0057192C], xmm0
	X86_MEM_WRITE_u32(base, 0x57192Cu, ctx.xmm[0].u32[0]);
	// 0x2B01F8: ret
	return;
}

void sub_2B0200(X86Context& ctx, uint8_t* base) {
	// 0x2B0200: movss xmm0, dword ptr [0x0057194C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57194Cu);
	// 0x2B0208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0210: movss [0x00571960], xmm0
	X86_MEM_WRITE_u32(base, 0x571960u, ctx.xmm[0].u32[0]);
	// 0x2B0218: ret
	return;
}

void sub_2B0220(X86Context& ctx, uint8_t* base) {
	// 0x2B0220: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B0228: movss [0x00571894], xmm0
	X86_MEM_WRITE_u32(base, 0x571894u, ctx.xmm[0].u32[0]);
	// 0x2B0230: ret
	return;
}

void sub_2B0240(X86Context& ctx, uint8_t* base) {
	// 0x2B0240: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B0248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0250: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B0258: movss [0x00571938], xmm0
	X86_MEM_WRITE_u32(base, 0x571938u, ctx.xmm[0].u32[0]);
	// 0x2B0260: ret
	return;
}

void sub_2B0270(X86Context& ctx, uint8_t* base) {
	// 0x2B0270: movss xmm0, dword ptr [0x00571944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571944u);
	// 0x2B0278: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0280: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B0288: movss [0x005718B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5718B8u, ctx.xmm[0].u32[0]);
	// 0x2B0290: ret
	return;
}

void sub_2B02A0(X86Context& ctx, uint8_t* base) {
	// 0x2B02A0: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B02A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B02B0: movss [0x005718BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5718BCu, ctx.xmm[0].u32[0]);
	// 0x2B02B8: ret
	return;
}

void sub_2B02C0(X86Context& ctx, uint8_t* base) {
	// 0x2B02C0: movss xmm0, dword ptr [0x00571944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571944u);
	// 0x2B02C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B02D0: movss [0x00571954], xmm0
	X86_MEM_WRITE_u32(base, 0x571954u, ctx.xmm[0].u32[0]);
	// 0x2B02D8: ret
	return;
}

void sub_2B02E0(X86Context& ctx, uint8_t* base) {
	// 0x2B02E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B02E8: movss [0x00571898], xmm0
	X86_MEM_WRITE_u32(base, 0x571898u, ctx.xmm[0].u32[0]);
	// 0x2B02F0: ret
	return;
}

void sub_2B0300(X86Context& ctx, uint8_t* base) {
	// 0x2B0300: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B0308: movss [0x005718D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5718D4u, ctx.xmm[0].u32[0]);
	// 0x2B0310: ret
	return;
}

void sub_2B0320(X86Context& ctx, uint8_t* base) {
	// 0x2B0320: movss xmm0, dword ptr [0x00571898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571898u);
	// 0x2B0328: movss [0x00571974], xmm0
	X86_MEM_WRITE_u32(base, 0x571974u, ctx.xmm[0].u32[0]);
	// 0x2B0330: ret
	return;
}

void sub_2B0340(X86Context& ctx, uint8_t* base) {
	// 0x2B0340: movss xmm0, dword ptr [0x00571944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571944u);
	// 0x2B0348: subss xmm0, [0x00571898]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571898u);
	// 0x2B0350: movss [0x00571910], xmm0
	X86_MEM_WRITE_u32(base, 0x571910u, ctx.xmm[0].u32[0]);
	// 0x2B0358: ret
	return;
}

void sub_2B0360(X86Context& ctx, uint8_t* base) {
	// 0x2B0360: movss xmm0, dword ptr [0x00571910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571910u);
	// 0x2B0368: subss xmm0, [0x005718D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5718D4u);
	// 0x2B0370: movss [0x00571904], xmm0
	X86_MEM_WRITE_u32(base, 0x571904u, ctx.xmm[0].u32[0]);
	// 0x2B0378: ret
	return;
}

void sub_2B0380(X86Context& ctx, uint8_t* base) {
	// 0x2B0380: movss xmm0, dword ptr [0x00571954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571954u);
	// 0x2B0388: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B0390: movss [0x005718E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5718E8u, ctx.xmm[0].u32[0]);
	// 0x2B0398: ret
	return;
}

void sub_2B03A0(X86Context& ctx, uint8_t* base) {
	// 0x2B03A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B03A8: movss [0x005718D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5718D0u, ctx.xmm[0].u32[0]);
	// 0x2B03B0: ret
	return;
}

void sub_2B03C0(X86Context& ctx, uint8_t* base) {
	// 0x2B03C0: movss xmm0, dword ptr [0x005718E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718E8u);
	// 0x2B03C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B03D0: movss [0x00571934], xmm0
	X86_MEM_WRITE_u32(base, 0x571934u, ctx.xmm[0].u32[0]);
	// 0x2B03D8: ret
	return;
}

void sub_2B03E0(X86Context& ctx, uint8_t* base) {
	// 0x2B03E0: movss xmm0, dword ptr [0x00398C98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398C98u);
	// 0x2B03E8: movss [0x00571948], xmm0
	X86_MEM_WRITE_u32(base, 0x571948u, ctx.xmm[0].u32[0]);
	// 0x2B03F0: ret
	return;
}

void sub_2B0400(X86Context& ctx, uint8_t* base) {
	// 0x2B0400: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2B0408: movss [0x005718C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5718C0u, ctx.xmm[0].u32[0]);
	// 0x2B0410: ret
	return;
}

void sub_2B0420(X86Context& ctx, uint8_t* base) {
	// 0x2B0420: movss xmm0, dword ptr [0x005718CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718CCu);
	// 0x2B0428: movss [0x00571888], xmm0
	X86_MEM_WRITE_u32(base, 0x571888u, ctx.xmm[0].u32[0]);
	// 0x2B0430: ret
	return;
}

void sub_2B0440(X86Context& ctx, uint8_t* base) {
	// 0x2B0440: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2B0448: movss [0x005718EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5718ECu, ctx.xmm[0].u32[0]);
	// 0x2B0450: ret
	return;
}

void sub_2B0460(X86Context& ctx, uint8_t* base) {
	// 0x2B0460: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2B0468: movss [0x005718C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5718C4u, ctx.xmm[0].u32[0]);
	// 0x2B0470: ret
	return;
}

void sub_2B0480(X86Context& ctx, uint8_t* base) {
	// 0x2B0480: movss xmm0, dword ptr [0x005718EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718ECu);
	// 0x2B0488: mulss xmm0, [0x003B1880]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1880u);
	// 0x2B0490: addss xmm0, [0x00408300]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x408300u);
	// 0x2B0498: movss [0x00571950], xmm0
	X86_MEM_WRITE_u32(base, 0x571950u, ctx.xmm[0].u32[0]);
	// 0x2B04A0: ret
	return;
}

void sub_2B04B0(X86Context& ctx, uint8_t* base) {
	// 0x2B04B0: movss xmm0, dword ptr [0x003B22B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B0u);
	// 0x2B04B8: movss [0x00571940], xmm0
	X86_MEM_WRITE_u32(base, 0x571940u, ctx.xmm[0].u32[0]);
	// 0x2B04C0: ret
	return;
}

void sub_2B04D0(X86Context& ctx, uint8_t* base) {
	// 0x2B04D0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B04D8: divss xmm0, [0x00571940]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571940u);
	// 0x2B04E0: movss [0x005718B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5718B4u, ctx.xmm[0].u32[0]);
	// 0x2B04E8: ret
	return;
}

void sub_2B04F0(X86Context& ctx, uint8_t* base) {
	// 0x2B04F0: movss xmm0, dword ptr [0x00571948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571948u);
	// 0x2B04F8: subss xmm0, [0x00396EB0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x396EB0u);
	// 0x2B0500: movss [0x005718FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5718FCu, ctx.xmm[0].u32[0]);
	// 0x2B0508: ret
	return;
}

void sub_2B0510(X86Context& ctx, uint8_t* base) {
	// 0x2B0510: movss xmm0, dword ptr [0x00388E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x2B0518: movss [0x005718E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5718E0u, ctx.xmm[0].u32[0]);
	// 0x2B0520: ret
	return;
}

void sub_2B0530(X86Context& ctx, uint8_t* base) {
	// 0x2B0530: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B0538: movss [0x0057191C], xmm0
	X86_MEM_WRITE_u32(base, 0x57191Cu, ctx.xmm[0].u32[0]);
	// 0x2B0540: ret
	return;
}

void sub_2B0550(X86Context& ctx, uint8_t* base) {
	// 0x2B0550: movss xmm0, dword ptr [0x00571944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571944u);
	// 0x2B0558: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B0560: movss [0x00571970], xmm0
	X86_MEM_WRITE_u32(base, 0x571970u, ctx.xmm[0].u32[0]);
	// 0x2B0568: ret
	return;
}

void sub_2B0570(X86Context& ctx, uint8_t* base) {
	// 0x2B0570: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B0578: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B0580: movss [0x00571968], xmm0
	X86_MEM_WRITE_u32(base, 0x571968u, ctx.xmm[0].u32[0]);
	// 0x2B0588: ret
	return;
}

void sub_2B0590(X86Context& ctx, uint8_t* base) {
	// 0x2B0590: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B0598: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B05A0: movss [0x00571920], xmm0
	X86_MEM_WRITE_u32(base, 0x571920u, ctx.xmm[0].u32[0]);
	// 0x2B05A8: ret
	return;
}

void sub_2B05B0(X86Context& ctx, uint8_t* base) {
	// 0x2B05B0: movss xmm0, dword ptr [0x003B2080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2080u);
	// 0x2B05B8: movss [0x005718A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5718A4u, ctx.xmm[0].u32[0]);
	// 0x2B05C0: ret
	return;
}

void sub_2B05D0(X86Context& ctx, uint8_t* base) {
	// 0x2B05D0: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B05D8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B05E0: movss [0x0057193C], xmm0
	X86_MEM_WRITE_u32(base, 0x57193Cu, ctx.xmm[0].u32[0]);
	// 0x2B05E8: ret
	return;
}

void sub_2B05F0(X86Context& ctx, uint8_t* base) {
	// 0x2B05F0: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B05F8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B0600: movss [0x00571964], xmm0
	X86_MEM_WRITE_u32(base, 0x571964u, ctx.xmm[0].u32[0]);
	// 0x2B0608: ret
	return;
}

void sub_2B0610(X86Context& ctx, uint8_t* base) {
	// 0x2B0610: movss xmm0, dword ptr [0x003B206C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B206Cu);
	// 0x2B0618: movss [0x0057197C], xmm0
	X86_MEM_WRITE_u32(base, 0x57197Cu, ctx.xmm[0].u32[0]);
	// 0x2B0620: ret
	return;
}

void sub_2B0630(X86Context& ctx, uint8_t* base) {
	// 0x2B0630: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B0638: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B0640: movss [0x00571914], xmm0
	X86_MEM_WRITE_u32(base, 0x571914u, ctx.xmm[0].u32[0]);
	// 0x2B0648: ret
	return;
}

void sub_2B0650(X86Context& ctx, uint8_t* base) {
	// 0x2B0650: movss xmm0, dword ptr [0x005718C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5718C8u);
	// 0x2B0658: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B0660: movss [0x00571980], xmm0
	X86_MEM_WRITE_u32(base, 0x571980u, ctx.xmm[0].u32[0]);
	// 0x2B0668: ret
	return;
}

void sub_2B0670(X86Context& ctx, uint8_t* base) {
	// 0x2B0670: movss xmm0, dword ptr [0x003B207C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B207Cu);
	// 0x2B0678: movss [0x00571900], xmm0
	X86_MEM_WRITE_u32(base, 0x571900u, ctx.xmm[0].u32[0]);
	// 0x2B0680: ret
	return;
}

void sub_2B0690(X86Context& ctx, uint8_t* base) {
	// 0x2B0690: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B0698: movss [0x005718AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5718ACu, ctx.xmm[0].u32[0]);
	// 0x2B06A0: ret
	return;
}

void sub_2B06B0(X86Context& ctx, uint8_t* base) {
	// 0x2B06B0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B06B8: movss [0x0057190C], xmm0
	X86_MEM_WRITE_u32(base, 0x57190Cu, ctx.xmm[0].u32[0]);
	// 0x2B06C0: ret
	return;
}

void sub_2B06D0(X86Context& ctx, uint8_t* base) {
	// 0x2B06D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B06D8: movss [0x00571A20], xmm0
	X86_MEM_WRITE_u32(base, 0x571A20u, ctx.xmm[0].u32[0]);
	// 0x2B06E0: ret
	return;
}

void sub_2B06F0(X86Context& ctx, uint8_t* base) {
	// 0x2B06F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B06F8: movss [0x00571A44], xmm0
	X86_MEM_WRITE_u32(base, 0x571A44u, ctx.xmm[0].u32[0]);
	// 0x2B0700: ret
	return;
}

void sub_2B0710(X86Context& ctx, uint8_t* base) {
	// 0x2B0710: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B0718: movss [0x005719F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5719F4u, ctx.xmm[0].u32[0]);
	// 0x2B0720: ret
	return;
}

void sub_2B0730(X86Context& ctx, uint8_t* base) {
	// 0x2B0730: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B0738: movss [0x00571988], xmm0
	X86_MEM_WRITE_u32(base, 0x571988u, ctx.xmm[0].u32[0]);
	// 0x2B0740: ret
	return;
}

void sub_2B0750(X86Context& ctx, uint8_t* base) {
	// 0x2B0750: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B0758: movss [0x00571A28], xmm0
	X86_MEM_WRITE_u32(base, 0x571A28u, ctx.xmm[0].u32[0]);
	// 0x2B0760: ret
	return;
}

void sub_2B0770(X86Context& ctx, uint8_t* base) {
	// 0x2B0770: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B0778: movss [0x005719A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5719A8u, ctx.xmm[0].u32[0]);
	// 0x2B0780: ret
	return;
}

void sub_2B0790(X86Context& ctx, uint8_t* base) {
	// 0x2B0790: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B0798: movss [0x00571A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A6Cu, ctx.xmm[0].u32[0]);
	// 0x2B07A0: ret
	return;
}

void sub_2B07B0(X86Context& ctx, uint8_t* base) {
	// 0x2B07B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B07B8: movss [0x00571A18], xmm0
	X86_MEM_WRITE_u32(base, 0x571A18u, ctx.xmm[0].u32[0]);
	// 0x2B07C0: ret
	return;
}

void sub_2B07D0(X86Context& ctx, uint8_t* base) {
	// 0x2B07D0: movss xmm0, dword ptr [0x00571A6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A6Cu);
	// 0x2B07D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B07E0: movss [0x005719B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5719B4u, ctx.xmm[0].u32[0]);
	// 0x2B07E8: ret
	return;
}

void sub_2B07F0(X86Context& ctx, uint8_t* base) {
	// 0x2B07F0: movss xmm0, dword ptr [0x00571A18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A18u);
	// 0x2B07F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B0800: movss [0x00571A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A5Cu, ctx.xmm[0].u32[0]);
	// 0x2B0808: ret
	return;
}

void sub_2B0810(X86Context& ctx, uint8_t* base) {
	// 0x2B0810: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B0818: movss [0x00571AA0], xmm0
	X86_MEM_WRITE_u32(base, 0x571AA0u, ctx.xmm[0].u32[0]);
	// 0x2B0820: ret
	return;
}

void sub_2B0830(X86Context& ctx, uint8_t* base) {
	// 0x2B0830: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B0838: movss [0x00571A74], xmm0
	X86_MEM_WRITE_u32(base, 0x571A74u, ctx.xmm[0].u32[0]);
	// 0x2B0840: ret
	return;
}

void sub_2B0850(X86Context& ctx, uint8_t* base) {
	// 0x2B0850: movss xmm0, dword ptr [0x00571A74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A74u);
	// 0x2B0858: movss [0x00571A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A9Cu, ctx.xmm[0].u32[0]);
	// 0x2B0860: ret
	return;
}

void sub_2B0870(X86Context& ctx, uint8_t* base) {
	// 0x2B0870: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B0878: movss [0x005719EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5719ECu, ctx.xmm[0].u32[0]);
	// 0x2B0880: ret
	return;
}

void sub_2B0890(X86Context& ctx, uint8_t* base) {
	// 0x2B0890: movss xmm0, dword ptr [0x00571A18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A18u);
	// 0x2B0898: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B08A0: movss [0x005719C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5719C4u, ctx.xmm[0].u32[0]);
	// 0x2B08A8: ret
	return;
}

void sub_2B08B0(X86Context& ctx, uint8_t* base) {
	// 0x2B08B0: movss xmm0, dword ptr [0x00571A18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A18u);
	// 0x2B08B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B08C0: movss [0x00571A40], xmm0
	X86_MEM_WRITE_u32(base, 0x571A40u, ctx.xmm[0].u32[0]);
	// 0x2B08C8: ret
	return;
}

void sub_2B08D0(X86Context& ctx, uint8_t* base) {
	// 0x2B08D0: movss xmm0, dword ptr [0x00571A18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A18u);
	// 0x2B08D8: subss xmm0, [0x00571A40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571A40u);
	// 0x2B08E0: movss [0x005719B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5719B0u, ctx.xmm[0].u32[0]);
	// 0x2B08E8: ret
	return;
}

void sub_2B08F0(X86Context& ctx, uint8_t* base) {
	// 0x2B08F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B08F8: movss [0x005719D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5719D0u, ctx.xmm[0].u32[0]);
	// 0x2B0900: ret
	return;
}

void sub_2B0910(X86Context& ctx, uint8_t* base) {
	// 0x2B0910: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B0918: movss [0x00571A60], xmm0
	X86_MEM_WRITE_u32(base, 0x571A60u, ctx.xmm[0].u32[0]);
	// 0x2B0920: ret
	return;
}

void sub_2B0930(X86Context& ctx, uint8_t* base) {
	// 0x2B0930: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B0938: movss [0x00571A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A3Cu, ctx.xmm[0].u32[0]);
	// 0x2B0940: ret
	return;
}

void sub_2B0950(X86Context& ctx, uint8_t* base) {
	// 0x2B0950: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B0958: movss [0x005719AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5719ACu, ctx.xmm[0].u32[0]);
	// 0x2B0960: ret
	return;
}

void sub_2B0970(X86Context& ctx, uint8_t* base) {
	// 0x2B0970: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0978: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B0980: movss [0x0057199C], xmm0
	X86_MEM_WRITE_u32(base, 0x57199Cu, ctx.xmm[0].u32[0]);
	// 0x2B0988: ret
	return;
}

void sub_2B0990(X86Context& ctx, uint8_t* base) {
	// 0x2B0990: movss xmm0, dword ptr [0x00571A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A60u);
	// 0x2B0998: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B09A0: movss [0x00571A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A1Cu, ctx.xmm[0].u32[0]);
	// 0x2B09A8: ret
	return;
}

void sub_2B09B0(X86Context& ctx, uint8_t* base) {
	// 0x2B09B0: movss xmm0, dword ptr [0x0057199C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57199Cu);
	// 0x2B09B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B09C0: movss [0x00571A30], xmm0
	X86_MEM_WRITE_u32(base, 0x571A30u, ctx.xmm[0].u32[0]);
	// 0x2B09C8: ret
	return;
}

void sub_2B09D0(X86Context& ctx, uint8_t* base) {
	// 0x2B09D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B09D8: movss [0x00571994], xmm0
	X86_MEM_WRITE_u32(base, 0x571994u, ctx.xmm[0].u32[0]);
	// 0x2B09E0: ret
	return;
}

void sub_2B09F0(X86Context& ctx, uint8_t* base) {
	// 0x2B09F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B09F8: movss [0x005719D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5719D8u, ctx.xmm[0].u32[0]);
	// 0x2B0A00: ret
	return;
}

void sub_2B0A10(X86Context& ctx, uint8_t* base) {
	// 0x2B0A10: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0A18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B0A20: movss [0x005719E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5719E8u, ctx.xmm[0].u32[0]);
	// 0x2B0A28: ret
	return;
}

void sub_2B0A30(X86Context& ctx, uint8_t* base) {
	// 0x2B0A30: movss xmm0, dword ptr [0x00571A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A60u);
	// 0x2B0A38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B0A40: movss [0x00571A64], xmm0
	X86_MEM_WRITE_u32(base, 0x571A64u, ctx.xmm[0].u32[0]);
	// 0x2B0A48: ret
	return;
}

void sub_2B0A50(X86Context& ctx, uint8_t* base) {
	// 0x2B0A50: movss xmm0, dword ptr [0x005719E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719E8u);
	// 0x2B0A58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0A60: movss [0x00571A48], xmm0
	X86_MEM_WRITE_u32(base, 0x571A48u, ctx.xmm[0].u32[0]);
	// 0x2B0A68: ret
	return;
}

void sub_2B0A70(X86Context& ctx, uint8_t* base) {
	// 0x2B0A70: movss xmm0, dword ptr [0x00571A64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A64u);
	// 0x2B0A78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0A80: movss [0x00571A78], xmm0
	X86_MEM_WRITE_u32(base, 0x571A78u, ctx.xmm[0].u32[0]);
	// 0x2B0A88: ret
	return;
}

void sub_2B0A90(X86Context& ctx, uint8_t* base) {
	// 0x2B0A90: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B0A98: movss [0x005719A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5719A0u, ctx.xmm[0].u32[0]);
	// 0x2B0AA0: ret
	return;
}

void sub_2B0AB0(X86Context& ctx, uint8_t* base) {
	// 0x2B0AB0: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0AB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0AC0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B0AC8: movss [0x00571A58], xmm0
	X86_MEM_WRITE_u32(base, 0x571A58u, ctx.xmm[0].u32[0]);
	// 0x2B0AD0: ret
	return;
}

void sub_2B0AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B0AE0: movss xmm0, dword ptr [0x00571A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A60u);
	// 0x2B0AE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0AF0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B0AF8: movss [0x005719B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5719B8u, ctx.xmm[0].u32[0]);
	// 0x2B0B00: ret
	return;
}

void sub_2B0B10(X86Context& ctx, uint8_t* base) {
	// 0x2B0B10: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0B18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0B20: movss [0x005719C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5719C0u, ctx.xmm[0].u32[0]);
	// 0x2B0B28: ret
	return;
}

void sub_2B0B30(X86Context& ctx, uint8_t* base) {
	// 0x2B0B30: movss xmm0, dword ptr [0x00571A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A60u);
	// 0x2B0B38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B0B40: movss [0x00571A68], xmm0
	X86_MEM_WRITE_u32(base, 0x571A68u, ctx.xmm[0].u32[0]);
	// 0x2B0B48: ret
	return;
}

void sub_2B0B50(X86Context& ctx, uint8_t* base) {
	// 0x2B0B50: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B0B58: movss [0x005719A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5719A4u, ctx.xmm[0].u32[0]);
	// 0x2B0B60: ret
	return;
}

void sub_2B0B70(X86Context& ctx, uint8_t* base) {
	// 0x2B0B70: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B0B78: movss [0x005719E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5719E4u, ctx.xmm[0].u32[0]);
	// 0x2B0B80: ret
	return;
}

void sub_2B0B90(X86Context& ctx, uint8_t* base) {
	// 0x2B0B90: movss xmm0, dword ptr [0x005719A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719A4u);
	// 0x2B0B98: movss [0x00571A98], xmm0
	X86_MEM_WRITE_u32(base, 0x571A98u, ctx.xmm[0].u32[0]);
	// 0x2B0BA0: ret
	return;
}

void sub_2B0BB0(X86Context& ctx, uint8_t* base) {
	// 0x2B0BB0: movss xmm0, dword ptr [0x00571A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A60u);
	// 0x2B0BB8: subss xmm0, [0x005719A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5719A4u);
	// 0x2B0BC0: movss [0x00571A34], xmm0
	X86_MEM_WRITE_u32(base, 0x571A34u, ctx.xmm[0].u32[0]);
	// 0x2B0BC8: ret
	return;
}

void sub_2B0BD0(X86Context& ctx, uint8_t* base) {
	// 0x2B0BD0: movss xmm0, dword ptr [0x00571A34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A34u);
	// 0x2B0BD8: subss xmm0, [0x005719E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5719E4u);
	// 0x2B0BE0: movss [0x00571A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A2Cu, ctx.xmm[0].u32[0]);
	// 0x2B0BE8: ret
	return;
}

void sub_2B0BF0(X86Context& ctx, uint8_t* base) {
	// 0x2B0BF0: movss xmm0, dword ptr [0x00571A68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A68u);
	// 0x2B0BF8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B0C00: movss [0x00571A10], xmm0
	X86_MEM_WRITE_u32(base, 0x571A10u, ctx.xmm[0].u32[0]);
	// 0x2B0C08: ret
	return;
}

void sub_2B0C10(X86Context& ctx, uint8_t* base) {
	// 0x2B0C10: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B0C18: movss [0x005719E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5719E0u, ctx.xmm[0].u32[0]);
	// 0x2B0C20: ret
	return;
}

void sub_2B0C30(X86Context& ctx, uint8_t* base) {
	// 0x2B0C30: movss xmm0, dword ptr [0x00571A10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A10u);
	// 0x2B0C38: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B0C40: movss [0x00571A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A4Cu, ctx.xmm[0].u32[0]);
	// 0x2B0C48: ret
	return;
}

void sub_2B0C50(X86Context& ctx, uint8_t* base) {
	// 0x2B0C50: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0C58: subss xmm0, [0x003B1884]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1884u);
	// 0x2B0C60: movss [0x00571A14], xmm0
	X86_MEM_WRITE_u32(base, 0x571A14u, ctx.xmm[0].u32[0]);
	// 0x2B0C68: ret
	return;
}

void sub_2B0C70(X86Context& ctx, uint8_t* base) {
	// 0x2B0C70: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0C78: subss xmm0, [0x003B17E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B17E4u);
	// 0x2B0C80: movss [0x005719C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5719C8u, ctx.xmm[0].u32[0]);
	// 0x2B0C88: ret
	return;
}

void sub_2B0C90(X86Context& ctx, uint8_t* base) {
	// 0x2B0C90: movss xmm0, dword ptr [0x003A60AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A60ACu);
	// 0x2B0C98: movss [0x00571A54], xmm0
	X86_MEM_WRITE_u32(base, 0x571A54u, ctx.xmm[0].u32[0]);
	// 0x2B0CA0: ret
	return;
}

void sub_2B0CB0(X86Context& ctx, uint8_t* base) {
	// 0x2B0CB0: movss xmm0, dword ptr [0x005719D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5719D0u);
	// 0x2B0CB8: movss [0x00571A70], xmm0
	X86_MEM_WRITE_u32(base, 0x571A70u, ctx.xmm[0].u32[0]);
	// 0x2B0CC0: ret
	return;
}

void sub_2B0CD0(X86Context& ctx, uint8_t* base) {
	// 0x2B0CD0: movss xmm0, dword ptr [0x00571A70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571A70u);
	// 0x2B0CD8: movss [0x0057198C], xmm0
	X86_MEM_WRITE_u32(base, 0x57198Cu, ctx.xmm[0].u32[0]);
	// 0x2B0CE0: ret
	return;
}

void sub_2B0CF0(X86Context& ctx, uint8_t* base) {
	// 0x2B0CF0: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2B0CF3: subss xmm0, [0x00571A70]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571A70u);
	// 0x2B0CFB: movss [0x005719D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5719D4u, ctx.xmm[0].u32[0]);
	// 0x2B0D03: ret
	return;
}

void sub_2B0D10(X86Context& ctx, uint8_t* base) {
	// 0x2B0D10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B0D18: movss [0x005719CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5719CCu, ctx.xmm[0].u32[0]);
	// 0x2B0D20: ret
	return;
}

void sub_2B0D30(X86Context& ctx, uint8_t* base) {
	// 0x2B0D30: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B0D38: movss [0x005719BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5719BCu, ctx.xmm[0].u32[0]);
	// 0x2B0D40: ret
	return;
}

