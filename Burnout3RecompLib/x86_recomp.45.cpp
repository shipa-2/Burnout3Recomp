#include "x86_recomp_shared.h"

void sub_27B550(X86Context& ctx, uint8_t* base) {
	// 0x27B550: movss xmm0, dword ptr [0x00569A94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A94u);
	// 0x27B558: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27B560: movss [0x00569A50], xmm0
	X86_MEM_WRITE_u32(base, 0x569A50u, ctx.xmm[0].u32[0]);
	// 0x27B568: ret
	return;
}

void sub_27B570(X86Context& ctx, uint8_t* base) {
	// 0x27B570: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27B578: movss [0x00569A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A3Cu, ctx.xmm[0].u32[0]);
	// 0x27B580: ret
	return;
}

void sub_27B590(X86Context& ctx, uint8_t* base) {
	// 0x27B590: movss xmm0, dword ptr [0x00569A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A50u);
	// 0x27B598: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27B5A0: movss [0x00569A84], xmm0
	X86_MEM_WRITE_u32(base, 0x569A84u, ctx.xmm[0].u32[0]);
	// 0x27B5A8: ret
	return;
}

void sub_27B5B0(X86Context& ctx, uint8_t* base) {
	// 0x27B5B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27B5B8: movss [0x00569A58], xmm0
	X86_MEM_WRITE_u32(base, 0x569A58u, ctx.xmm[0].u32[0]);
	// 0x27B5C0: ret
	return;
}

void sub_27B5D0(X86Context& ctx, uint8_t* base) {
	// 0x27B5D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27B5D8: movss [0x00569A30], xmm0
	X86_MEM_WRITE_u32(base, 0x569A30u, ctx.xmm[0].u32[0]);
	// 0x27B5E0: ret
	return;
}

void sub_27B5F0(X86Context& ctx, uint8_t* base) {
	// 0x27B5F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27B5F8: movss [0x00569B10], xmm0
	X86_MEM_WRITE_u32(base, 0x569B10u, ctx.xmm[0].u32[0]);
	// 0x27B600: ret
	return;
}

void sub_27B610(X86Context& ctx, uint8_t* base) {
	// 0x27B610: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27B618: movss [0x00569B2C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B2Cu, ctx.xmm[0].u32[0]);
	// 0x27B620: ret
	return;
}

void sub_27B630(X86Context& ctx, uint8_t* base) {
	// 0x27B630: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27B638: movss [0x00569B00], xmm0
	X86_MEM_WRITE_u32(base, 0x569B00u, ctx.xmm[0].u32[0]);
	// 0x27B640: ret
	return;
}

void sub_27B650(X86Context& ctx, uint8_t* base) {
	// 0x27B650: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27B658: movss [0x00569AB4], xmm0
	X86_MEM_WRITE_u32(base, 0x569AB4u, ctx.xmm[0].u32[0]);
	// 0x27B660: ret
	return;
}

void sub_27B670(X86Context& ctx, uint8_t* base) {
	// 0x27B670: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27B678: movss [0x00569B14], xmm0
	X86_MEM_WRITE_u32(base, 0x569B14u, ctx.xmm[0].u32[0]);
	// 0x27B680: ret
	return;
}

void sub_27B690(X86Context& ctx, uint8_t* base) {
	// 0x27B690: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27B698: movss [0x00569AD0], xmm0
	X86_MEM_WRITE_u32(base, 0x569AD0u, ctx.xmm[0].u32[0]);
	// 0x27B6A0: ret
	return;
}

void sub_27B6B0(X86Context& ctx, uint8_t* base) {
	// 0x27B6B0: movss xmm0, dword ptr [0x00569B14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B14u);
	// 0x27B6B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27B6C0: movss [0x00569B4C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B4Cu, ctx.xmm[0].u32[0]);
	// 0x27B6C8: ret
	return;
}

void sub_27B6D0(X86Context& ctx, uint8_t* base) {
	// 0x27B6D0: movss xmm0, dword ptr [0x00569AD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AD0u);
	// 0x27B6D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27B6E0: movss [0x00569B34], xmm0
	X86_MEM_WRITE_u32(base, 0x569B34u, ctx.xmm[0].u32[0]);
	// 0x27B6E8: ret
	return;
}

void sub_27B6F0(X86Context& ctx, uint8_t* base) {
	// 0x27B6F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27B6F8: movss [0x00569B64], xmm0
	X86_MEM_WRITE_u32(base, 0x569B64u, ctx.xmm[0].u32[0]);
	// 0x27B700: ret
	return;
}

void sub_27B710(X86Context& ctx, uint8_t* base) {
	// 0x27B710: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27B718: movss [0x00569B50], xmm0
	X86_MEM_WRITE_u32(base, 0x569B50u, ctx.xmm[0].u32[0]);
	// 0x27B720: ret
	return;
}

void sub_27B730(X86Context& ctx, uint8_t* base) {
	// 0x27B730: movss xmm0, dword ptr [0x00569B50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B50u);
	// 0x27B738: movss [0x00569B60], xmm0
	X86_MEM_WRITE_u32(base, 0x569B60u, ctx.xmm[0].u32[0]);
	// 0x27B740: ret
	return;
}

void sub_27B750(X86Context& ctx, uint8_t* base) {
	// 0x27B750: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27B758: movss [0x00569ABC], xmm0
	X86_MEM_WRITE_u32(base, 0x569ABCu, ctx.xmm[0].u32[0]);
	// 0x27B760: ret
	return;
}

void sub_27B770(X86Context& ctx, uint8_t* base) {
	// 0x27B770: movss xmm0, dword ptr [0x00569AD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AD0u);
	// 0x27B778: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27B780: movss [0x00569B58], xmm0
	X86_MEM_WRITE_u32(base, 0x569B58u, ctx.xmm[0].u32[0]);
	// 0x27B788: ret
	return;
}

void sub_27B790(X86Context& ctx, uint8_t* base) {
	// 0x27B790: movss xmm0, dword ptr [0x00569AD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AD0u);
	// 0x27B798: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27B7A0: movss [0x00569AFC], xmm0
	X86_MEM_WRITE_u32(base, 0x569AFCu, ctx.xmm[0].u32[0]);
	// 0x27B7A8: ret
	return;
}

void sub_27B7B0(X86Context& ctx, uint8_t* base) {
	// 0x27B7B0: movss xmm0, dword ptr [0x00569AD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AD0u);
	// 0x27B7B8: subss xmm0, [0x00569AFC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569AFCu);
	// 0x27B7C0: movss [0x00569AD8], xmm0
	X86_MEM_WRITE_u32(base, 0x569AD8u, ctx.xmm[0].u32[0]);
	// 0x27B7C8: ret
	return;
}

void sub_27B7D0(X86Context& ctx, uint8_t* base) {
	// 0x27B7D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27B7D8: movss [0x00569B28], xmm0
	X86_MEM_WRITE_u32(base, 0x569B28u, ctx.xmm[0].u32[0]);
	// 0x27B7E0: ret
	return;
}

void sub_27B7F0(X86Context& ctx, uint8_t* base) {
	// 0x27B7F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27B7F8: movss [0x00569AD4], xmm0
	X86_MEM_WRITE_u32(base, 0x569AD4u, ctx.xmm[0].u32[0]);
	// 0x27B800: ret
	return;
}

void sub_27B810(X86Context& ctx, uint8_t* base) {
	// 0x27B810: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27B818: movss [0x00569AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x569AE8u, ctx.xmm[0].u32[0]);
	// 0x27B820: ret
	return;
}

void sub_27B830(X86Context& ctx, uint8_t* base) {
	// 0x27B830: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27B838: movss [0x00569B40], xmm0
	X86_MEM_WRITE_u32(base, 0x569B40u, ctx.xmm[0].u32[0]);
	// 0x27B840: ret
	return;
}

void sub_27B850(X86Context& ctx, uint8_t* base) {
	// 0x27B850: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27B858: movss [0x00569B24], xmm0
	X86_MEM_WRITE_u32(base, 0x569B24u, ctx.xmm[0].u32[0]);
	// 0x27B860: ret
	return;
}

void sub_27B870(X86Context& ctx, uint8_t* base) {
	// 0x27B870: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27B878: movss [0x00569ACC], xmm0
	X86_MEM_WRITE_u32(base, 0x569ACCu, ctx.xmm[0].u32[0]);
	// 0x27B880: ret
	return;
}

void sub_27B890(X86Context& ctx, uint8_t* base) {
	// 0x27B890: movss xmm0, dword ptr [0x00569AE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AE8u);
	// 0x27B898: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27B8A0: movss [0x00569AC0], xmm0
	X86_MEM_WRITE_u32(base, 0x569AC0u, ctx.xmm[0].u32[0]);
	// 0x27B8A8: ret
	return;
}

void sub_27B8B0(X86Context& ctx, uint8_t* base) {
	// 0x27B8B0: movss xmm0, dword ptr [0x00569B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B40u);
	// 0x27B8B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27B8C0: movss [0x00569B08], xmm0
	X86_MEM_WRITE_u32(base, 0x569B08u, ctx.xmm[0].u32[0]);
	// 0x27B8C8: ret
	return;
}

void sub_27B8D0(X86Context& ctx, uint8_t* base) {
	// 0x27B8D0: movss xmm0, dword ptr [0x00569AC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AC0u);
	// 0x27B8D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27B8E0: movss [0x00569B1C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B1Cu, ctx.xmm[0].u32[0]);
	// 0x27B8E8: ret
	return;
}

void sub_27B8F0(X86Context& ctx, uint8_t* base) {
	// 0x27B8F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27B8F8: movss [0x00569AB8], xmm0
	X86_MEM_WRITE_u32(base, 0x569AB8u, ctx.xmm[0].u32[0]);
	// 0x27B900: ret
	return;
}

void sub_27B910(X86Context& ctx, uint8_t* base) {
	// 0x27B910: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27B918: movss [0x00569AEC], xmm0
	X86_MEM_WRITE_u32(base, 0x569AECu, ctx.xmm[0].u32[0]);
	// 0x27B920: ret
	return;
}

void sub_27B930(X86Context& ctx, uint8_t* base) {
	// 0x27B930: movss xmm0, dword ptr [0x00569AE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AE8u);
	// 0x27B938: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27B940: movss [0x00569AF8], xmm0
	X86_MEM_WRITE_u32(base, 0x569AF8u, ctx.xmm[0].u32[0]);
	// 0x27B948: ret
	return;
}

void sub_27B950(X86Context& ctx, uint8_t* base) {
	// 0x27B950: movss xmm0, dword ptr [0x00569B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B40u);
	// 0x27B958: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27B960: movss [0x00569B44], xmm0
	X86_MEM_WRITE_u32(base, 0x569B44u, ctx.xmm[0].u32[0]);
	// 0x27B968: ret
	return;
}

void sub_27B970(X86Context& ctx, uint8_t* base) {
	// 0x27B970: movss xmm0, dword ptr [0x00569AF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AF8u);
	// 0x27B978: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B980: movss [0x00569B30], xmm0
	X86_MEM_WRITE_u32(base, 0x569B30u, ctx.xmm[0].u32[0]);
	// 0x27B988: ret
	return;
}

void sub_27B990(X86Context& ctx, uint8_t* base) {
	// 0x27B990: movss xmm0, dword ptr [0x00569B44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B44u);
	// 0x27B998: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B9A0: movss [0x00569B54], xmm0
	X86_MEM_WRITE_u32(base, 0x569B54u, ctx.xmm[0].u32[0]);
	// 0x27B9A8: ret
	return;
}

void sub_27B9B0(X86Context& ctx, uint8_t* base) {
	// 0x27B9B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27B9B8: movss [0x00569AC4], xmm0
	X86_MEM_WRITE_u32(base, 0x569AC4u, ctx.xmm[0].u32[0]);
	// 0x27B9C0: ret
	return;
}

void sub_27B9D0(X86Context& ctx, uint8_t* base) {
	// 0x27B9D0: movss xmm0, dword ptr [0x00569AE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AE8u);
	// 0x27B9D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B9E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27B9E8: movss [0x00569B3C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B3Cu, ctx.xmm[0].u32[0]);
	// 0x27B9F0: ret
	return;
}

void sub_27BA00(X86Context& ctx, uint8_t* base) {
	// 0x27BA00: movss xmm0, dword ptr [0x00569B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B40u);
	// 0x27BA08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BA10: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27BA18: movss [0x00569ADC], xmm0
	X86_MEM_WRITE_u32(base, 0x569ADCu, ctx.xmm[0].u32[0]);
	// 0x27BA20: ret
	return;
}

void sub_27BA30(X86Context& ctx, uint8_t* base) {
	// 0x27BA30: movss xmm0, dword ptr [0x00569AE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AE8u);
	// 0x27BA38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BA40: movss [0x00569AE0], xmm0
	X86_MEM_WRITE_u32(base, 0x569AE0u, ctx.xmm[0].u32[0]);
	// 0x27BA48: ret
	return;
}

void sub_27BA50(X86Context& ctx, uint8_t* base) {
	// 0x27BA50: movss xmm0, dword ptr [0x00569B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B40u);
	// 0x27BA58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BA60: movss [0x00569B48], xmm0
	X86_MEM_WRITE_u32(base, 0x569B48u, ctx.xmm[0].u32[0]);
	// 0x27BA68: ret
	return;
}

void sub_27BA70(X86Context& ctx, uint8_t* base) {
	// 0x27BA70: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27BA78: movss [0x00569AC8], xmm0
	X86_MEM_WRITE_u32(base, 0x569AC8u, ctx.xmm[0].u32[0]);
	// 0x27BA80: ret
	return;
}

void sub_27BA90(X86Context& ctx, uint8_t* base) {
	// 0x27BA90: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27BA98: movss [0x00569AF4], xmm0
	X86_MEM_WRITE_u32(base, 0x569AF4u, ctx.xmm[0].u32[0]);
	// 0x27BAA0: ret
	return;
}

void sub_27BAB0(X86Context& ctx, uint8_t* base) {
	// 0x27BAB0: movss xmm0, dword ptr [0x00569AC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569AC8u);
	// 0x27BAB8: movss [0x00569B5C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B5Cu, ctx.xmm[0].u32[0]);
	// 0x27BAC0: ret
	return;
}

void sub_27BAD0(X86Context& ctx, uint8_t* base) {
	// 0x27BAD0: movss xmm0, dword ptr [0x00569B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B40u);
	// 0x27BAD8: subss xmm0, [0x00569AC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569AC8u);
	// 0x27BAE0: movss [0x00569B20], xmm0
	X86_MEM_WRITE_u32(base, 0x569B20u, ctx.xmm[0].u32[0]);
	// 0x27BAE8: ret
	return;
}

void sub_27BAF0(X86Context& ctx, uint8_t* base) {
	// 0x27BAF0: movss xmm0, dword ptr [0x00569B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B20u);
	// 0x27BAF8: subss xmm0, [0x00569AF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569AF4u);
	// 0x27BB00: movss [0x00569B18], xmm0
	X86_MEM_WRITE_u32(base, 0x569B18u, ctx.xmm[0].u32[0]);
	// 0x27BB08: ret
	return;
}

void sub_27BB10(X86Context& ctx, uint8_t* base) {
	// 0x27BB10: movss xmm0, dword ptr [0x00569B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B48u);
	// 0x27BB18: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27BB20: movss [0x00569B04], xmm0
	X86_MEM_WRITE_u32(base, 0x569B04u, ctx.xmm[0].u32[0]);
	// 0x27BB28: ret
	return;
}

void sub_27BB30(X86Context& ctx, uint8_t* base) {
	// 0x27BB30: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27BB38: movss [0x00569AF0], xmm0
	X86_MEM_WRITE_u32(base, 0x569AF0u, ctx.xmm[0].u32[0]);
	// 0x27BB40: ret
	return;
}

void sub_27BB50(X86Context& ctx, uint8_t* base) {
	// 0x27BB50: movss xmm0, dword ptr [0x00569B04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B04u);
	// 0x27BB58: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27BB60: movss [0x00569B38], xmm0
	X86_MEM_WRITE_u32(base, 0x569B38u, ctx.xmm[0].u32[0]);
	// 0x27BB68: ret
	return;
}

void sub_27BB70(X86Context& ctx, uint8_t* base) {
	// 0x27BB70: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27BB78: movss [0x00569B0C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B0Cu, ctx.xmm[0].u32[0]);
	// 0x27BB80: ret
	return;
}

void sub_27BB90(X86Context& ctx, uint8_t* base) {
	// 0x27BB90: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27BB98: movss [0x00569AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x569AE4u, ctx.xmm[0].u32[0]);
	// 0x27BBA0: ret
	return;
}

void sub_27BBB0(X86Context& ctx, uint8_t* base) {
	// 0x27BBB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27BBB8: movss [0x00569BC4], xmm0
	X86_MEM_WRITE_u32(base, 0x569BC4u, ctx.xmm[0].u32[0]);
	// 0x27BBC0: ret
	return;
}

void sub_27BBD0(X86Context& ctx, uint8_t* base) {
	// 0x27BBD0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27BBD8: movss [0x00569BE0], xmm0
	X86_MEM_WRITE_u32(base, 0x569BE0u, ctx.xmm[0].u32[0]);
	// 0x27BBE0: ret
	return;
}

void sub_27BBF0(X86Context& ctx, uint8_t* base) {
	// 0x27BBF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27BBF8: movss [0x00569BB4], xmm0
	X86_MEM_WRITE_u32(base, 0x569BB4u, ctx.xmm[0].u32[0]);
	// 0x27BC00: ret
	return;
}

void sub_27BC10(X86Context& ctx, uint8_t* base) {
	// 0x27BC10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27BC18: movss [0x00569B68], xmm0
	X86_MEM_WRITE_u32(base, 0x569B68u, ctx.xmm[0].u32[0]);
	// 0x27BC20: ret
	return;
}

void sub_27BC30(X86Context& ctx, uint8_t* base) {
	// 0x27BC30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27BC38: movss [0x00569BC8], xmm0
	X86_MEM_WRITE_u32(base, 0x569BC8u, ctx.xmm[0].u32[0]);
	// 0x27BC40: ret
	return;
}

void sub_27BC50(X86Context& ctx, uint8_t* base) {
	// 0x27BC50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27BC58: movss [0x00569B84], xmm0
	X86_MEM_WRITE_u32(base, 0x569B84u, ctx.xmm[0].u32[0]);
	// 0x27BC60: ret
	return;
}

void sub_27BC70(X86Context& ctx, uint8_t* base) {
	// 0x27BC70: movss xmm0, dword ptr [0x00569BC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BC8u);
	// 0x27BC78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27BC80: movss [0x00569C00], xmm0
	X86_MEM_WRITE_u32(base, 0x569C00u, ctx.xmm[0].u32[0]);
	// 0x27BC88: ret
	return;
}

void sub_27BC90(X86Context& ctx, uint8_t* base) {
	// 0x27BC90: movss xmm0, dword ptr [0x00569B84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B84u);
	// 0x27BC98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27BCA0: movss [0x00569BE8], xmm0
	X86_MEM_WRITE_u32(base, 0x569BE8u, ctx.xmm[0].u32[0]);
	// 0x27BCA8: ret
	return;
}

void sub_27BCB0(X86Context& ctx, uint8_t* base) {
	// 0x27BCB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27BCB8: movss [0x00569C18], xmm0
	X86_MEM_WRITE_u32(base, 0x569C18u, ctx.xmm[0].u32[0]);
	// 0x27BCC0: ret
	return;
}

void sub_27BCD0(X86Context& ctx, uint8_t* base) {
	// 0x27BCD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27BCD8: movss [0x00569C04], xmm0
	X86_MEM_WRITE_u32(base, 0x569C04u, ctx.xmm[0].u32[0]);
	// 0x27BCE0: ret
	return;
}

void sub_27BCF0(X86Context& ctx, uint8_t* base) {
	// 0x27BCF0: movss xmm0, dword ptr [0x00569C04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C04u);
	// 0x27BCF8: movss [0x00569C14], xmm0
	X86_MEM_WRITE_u32(base, 0x569C14u, ctx.xmm[0].u32[0]);
	// 0x27BD00: ret
	return;
}

void sub_27BD10(X86Context& ctx, uint8_t* base) {
	// 0x27BD10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27BD18: movss [0x00569B70], xmm0
	X86_MEM_WRITE_u32(base, 0x569B70u, ctx.xmm[0].u32[0]);
	// 0x27BD20: ret
	return;
}

void sub_27BD30(X86Context& ctx, uint8_t* base) {
	// 0x27BD30: movss xmm0, dword ptr [0x00569B84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B84u);
	// 0x27BD38: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27BD40: movss [0x00569C0C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C0Cu, ctx.xmm[0].u32[0]);
	// 0x27BD48: ret
	return;
}

void sub_27BD50(X86Context& ctx, uint8_t* base) {
	// 0x27BD50: movss xmm0, dword ptr [0x00569B84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B84u);
	// 0x27BD58: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27BD60: movss [0x00569BB0], xmm0
	X86_MEM_WRITE_u32(base, 0x569BB0u, ctx.xmm[0].u32[0]);
	// 0x27BD68: ret
	return;
}

void sub_27BD70(X86Context& ctx, uint8_t* base) {
	// 0x27BD70: movss xmm0, dword ptr [0x00569B84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B84u);
	// 0x27BD78: subss xmm0, [0x00569BB0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569BB0u);
	// 0x27BD80: movss [0x00569B8C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B8Cu, ctx.xmm[0].u32[0]);
	// 0x27BD88: ret
	return;
}

void sub_27BD90(X86Context& ctx, uint8_t* base) {
	// 0x27BD90: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27BD98: movss [0x00569BDC], xmm0
	X86_MEM_WRITE_u32(base, 0x569BDCu, ctx.xmm[0].u32[0]);
	// 0x27BDA0: ret
	return;
}

void sub_27BDB0(X86Context& ctx, uint8_t* base) {
	// 0x27BDB0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27BDB8: movss [0x00569B88], xmm0
	X86_MEM_WRITE_u32(base, 0x569B88u, ctx.xmm[0].u32[0]);
	// 0x27BDC0: ret
	return;
}

void sub_27BDD0(X86Context& ctx, uint8_t* base) {
	// 0x27BDD0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27BDD8: movss [0x00569B9C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B9Cu, ctx.xmm[0].u32[0]);
	// 0x27BDE0: ret
	return;
}

void sub_27BDF0(X86Context& ctx, uint8_t* base) {
	// 0x27BDF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27BDF8: movss [0x00569BF4], xmm0
	X86_MEM_WRITE_u32(base, 0x569BF4u, ctx.xmm[0].u32[0]);
	// 0x27BE00: ret
	return;
}

void sub_27BE10(X86Context& ctx, uint8_t* base) {
	// 0x27BE10: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27BE18: movss [0x00569BD8], xmm0
	X86_MEM_WRITE_u32(base, 0x569BD8u, ctx.xmm[0].u32[0]);
	// 0x27BE20: ret
	return;
}

void sub_27BE30(X86Context& ctx, uint8_t* base) {
	// 0x27BE30: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27BE38: movss [0x00569B80], xmm0
	X86_MEM_WRITE_u32(base, 0x569B80u, ctx.xmm[0].u32[0]);
	// 0x27BE40: ret
	return;
}

void sub_27BE50(X86Context& ctx, uint8_t* base) {
	// 0x27BE50: movss xmm0, dword ptr [0x00569B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B9Cu);
	// 0x27BE58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27BE60: movss [0x00569B74], xmm0
	X86_MEM_WRITE_u32(base, 0x569B74u, ctx.xmm[0].u32[0]);
	// 0x27BE68: ret
	return;
}

void sub_27BE70(X86Context& ctx, uint8_t* base) {
	// 0x27BE70: movss xmm0, dword ptr [0x00569BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BF4u);
	// 0x27BE78: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27BE80: movss [0x00569BBC], xmm0
	X86_MEM_WRITE_u32(base, 0x569BBCu, ctx.xmm[0].u32[0]);
	// 0x27BE88: ret
	return;
}

void sub_27BE90(X86Context& ctx, uint8_t* base) {
	// 0x27BE90: movss xmm0, dword ptr [0x00569B74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B74u);
	// 0x27BE98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27BEA0: movss [0x00569BD0], xmm0
	X86_MEM_WRITE_u32(base, 0x569BD0u, ctx.xmm[0].u32[0]);
	// 0x27BEA8: ret
	return;
}

void sub_27BEB0(X86Context& ctx, uint8_t* base) {
	// 0x27BEB0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27BEB8: movss [0x00569B6C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B6Cu, ctx.xmm[0].u32[0]);
	// 0x27BEC0: ret
	return;
}

void sub_27BED0(X86Context& ctx, uint8_t* base) {
	// 0x27BED0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27BED8: movss [0x00569BA0], xmm0
	X86_MEM_WRITE_u32(base, 0x569BA0u, ctx.xmm[0].u32[0]);
	// 0x27BEE0: ret
	return;
}

void sub_27BEF0(X86Context& ctx, uint8_t* base) {
	// 0x27BEF0: movss xmm0, dword ptr [0x00569B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B9Cu);
	// 0x27BEF8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27BF00: movss [0x00569BAC], xmm0
	X86_MEM_WRITE_u32(base, 0x569BACu, ctx.xmm[0].u32[0]);
	// 0x27BF08: ret
	return;
}

void sub_27BF10(X86Context& ctx, uint8_t* base) {
	// 0x27BF10: movss xmm0, dword ptr [0x00569BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BF4u);
	// 0x27BF18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27BF20: movss [0x00569BF8], xmm0
	X86_MEM_WRITE_u32(base, 0x569BF8u, ctx.xmm[0].u32[0]);
	// 0x27BF28: ret
	return;
}

void sub_27BF30(X86Context& ctx, uint8_t* base) {
	// 0x27BF30: movss xmm0, dword ptr [0x00569BAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BACu);
	// 0x27BF38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BF40: movss [0x00569BE4], xmm0
	X86_MEM_WRITE_u32(base, 0x569BE4u, ctx.xmm[0].u32[0]);
	// 0x27BF48: ret
	return;
}

void sub_27BF50(X86Context& ctx, uint8_t* base) {
	// 0x27BF50: movss xmm0, dword ptr [0x00569BF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BF8u);
	// 0x27BF58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BF60: movss [0x00569C08], xmm0
	X86_MEM_WRITE_u32(base, 0x569C08u, ctx.xmm[0].u32[0]);
	// 0x27BF68: ret
	return;
}

void sub_27BF70(X86Context& ctx, uint8_t* base) {
	// 0x27BF70: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27BF78: movss [0x00569B78], xmm0
	X86_MEM_WRITE_u32(base, 0x569B78u, ctx.xmm[0].u32[0]);
	// 0x27BF80: ret
	return;
}

void sub_27BF90(X86Context& ctx, uint8_t* base) {
	// 0x27BF90: movss xmm0, dword ptr [0x00569B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B9Cu);
	// 0x27BF98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BFA0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27BFA8: movss [0x00569BF0], xmm0
	X86_MEM_WRITE_u32(base, 0x569BF0u, ctx.xmm[0].u32[0]);
	// 0x27BFB0: ret
	return;
}

void sub_27BFC0(X86Context& ctx, uint8_t* base) {
	// 0x27BFC0: movss xmm0, dword ptr [0x00569BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BF4u);
	// 0x27BFC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27BFD0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27BFD8: movss [0x00569B90], xmm0
	X86_MEM_WRITE_u32(base, 0x569B90u, ctx.xmm[0].u32[0]);
	// 0x27BFE0: ret
	return;
}

void sub_27BFF0(X86Context& ctx, uint8_t* base) {
	// 0x27BFF0: movss xmm0, dword ptr [0x00569B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B9Cu);
	// 0x27BFF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C000: movss [0x00569B94], xmm0
	X86_MEM_WRITE_u32(base, 0x569B94u, ctx.xmm[0].u32[0]);
	// 0x27C008: ret
	return;
}

void sub_27C010(X86Context& ctx, uint8_t* base) {
	// 0x27C010: movss xmm0, dword ptr [0x00569BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BF4u);
	// 0x27C018: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C020: movss [0x00569BFC], xmm0
	X86_MEM_WRITE_u32(base, 0x569BFCu, ctx.xmm[0].u32[0]);
	// 0x27C028: ret
	return;
}

void sub_27C030(X86Context& ctx, uint8_t* base) {
	// 0x27C030: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27C038: movss [0x00569B7C], xmm0
	X86_MEM_WRITE_u32(base, 0x569B7Cu, ctx.xmm[0].u32[0]);
	// 0x27C040: ret
	return;
}

void sub_27C050(X86Context& ctx, uint8_t* base) {
	// 0x27C050: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27C058: movss [0x00569BA8], xmm0
	X86_MEM_WRITE_u32(base, 0x569BA8u, ctx.xmm[0].u32[0]);
	// 0x27C060: ret
	return;
}

void sub_27C070(X86Context& ctx, uint8_t* base) {
	// 0x27C070: movss xmm0, dword ptr [0x00569B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569B7Cu);
	// 0x27C078: movss [0x00569C10], xmm0
	X86_MEM_WRITE_u32(base, 0x569C10u, ctx.xmm[0].u32[0]);
	// 0x27C080: ret
	return;
}

void sub_27C090(X86Context& ctx, uint8_t* base) {
	// 0x27C090: movss xmm0, dword ptr [0x00569BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BF4u);
	// 0x27C098: subss xmm0, [0x00569B7C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569B7Cu);
	// 0x27C0A0: movss [0x00569BD4], xmm0
	X86_MEM_WRITE_u32(base, 0x569BD4u, ctx.xmm[0].u32[0]);
	// 0x27C0A8: ret
	return;
}

void sub_27C0B0(X86Context& ctx, uint8_t* base) {
	// 0x27C0B0: movss xmm0, dword ptr [0x00569BD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BD4u);
	// 0x27C0B8: subss xmm0, [0x00569BA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569BA8u);
	// 0x27C0C0: movss [0x00569BCC], xmm0
	X86_MEM_WRITE_u32(base, 0x569BCCu, ctx.xmm[0].u32[0]);
	// 0x27C0C8: ret
	return;
}

void sub_27C0D0(X86Context& ctx, uint8_t* base) {
	// 0x27C0D0: movss xmm0, dword ptr [0x00569BFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BFCu);
	// 0x27C0D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27C0E0: movss [0x00569BB8], xmm0
	X86_MEM_WRITE_u32(base, 0x569BB8u, ctx.xmm[0].u32[0]);
	// 0x27C0E8: ret
	return;
}

void sub_27C0F0(X86Context& ctx, uint8_t* base) {
	// 0x27C0F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27C0F8: movss [0x00569BA4], xmm0
	X86_MEM_WRITE_u32(base, 0x569BA4u, ctx.xmm[0].u32[0]);
	// 0x27C100: ret
	return;
}

void sub_27C110(X86Context& ctx, uint8_t* base) {
	// 0x27C110: movss xmm0, dword ptr [0x00569BB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569BB8u);
	// 0x27C118: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27C120: movss [0x00569BEC], xmm0
	X86_MEM_WRITE_u32(base, 0x569BECu, ctx.xmm[0].u32[0]);
	// 0x27C128: ret
	return;
}

void sub_27C130(X86Context& ctx, uint8_t* base) {
	// 0x27C130: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27C138: movss [0x00569BC0], xmm0
	X86_MEM_WRITE_u32(base, 0x569BC0u, ctx.xmm[0].u32[0]);
	// 0x27C140: ret
	return;
}

void sub_27C150(X86Context& ctx, uint8_t* base) {
	// 0x27C150: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27C158: movss [0x00569B98], xmm0
	X86_MEM_WRITE_u32(base, 0x569B98u, ctx.xmm[0].u32[0]);
	// 0x27C160: ret
	return;
}

void sub_27C170(X86Context& ctx, uint8_t* base) {
	// 0x27C170: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27C178: movss [0x00569C78], xmm0
	X86_MEM_WRITE_u32(base, 0x569C78u, ctx.xmm[0].u32[0]);
	// 0x27C180: ret
	return;
}

void sub_27C190(X86Context& ctx, uint8_t* base) {
	// 0x27C190: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27C198: movss [0x00569C94], xmm0
	X86_MEM_WRITE_u32(base, 0x569C94u, ctx.xmm[0].u32[0]);
	// 0x27C1A0: ret
	return;
}

void sub_27C1B0(X86Context& ctx, uint8_t* base) {
	// 0x27C1B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27C1B8: movss [0x00569C68], xmm0
	X86_MEM_WRITE_u32(base, 0x569C68u, ctx.xmm[0].u32[0]);
	// 0x27C1C0: ret
	return;
}

void sub_27C1D0(X86Context& ctx, uint8_t* base) {
	// 0x27C1D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27C1D8: movss [0x00569C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C1Cu, ctx.xmm[0].u32[0]);
	// 0x27C1E0: ret
	return;
}

void sub_27C1F0(X86Context& ctx, uint8_t* base) {
	// 0x27C1F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27C1F8: movss [0x00569C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C7Cu, ctx.xmm[0].u32[0]);
	// 0x27C200: ret
	return;
}

void sub_27C210(X86Context& ctx, uint8_t* base) {
	// 0x27C210: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27C218: movss [0x00569C38], xmm0
	X86_MEM_WRITE_u32(base, 0x569C38u, ctx.xmm[0].u32[0]);
	// 0x27C220: ret
	return;
}

void sub_27C230(X86Context& ctx, uint8_t* base) {
	// 0x27C230: movss xmm0, dword ptr [0x00569C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C7Cu);
	// 0x27C238: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27C240: movss [0x00569CB4], xmm0
	X86_MEM_WRITE_u32(base, 0x569CB4u, ctx.xmm[0].u32[0]);
	// 0x27C248: ret
	return;
}

void sub_27C250(X86Context& ctx, uint8_t* base) {
	// 0x27C250: movss xmm0, dword ptr [0x00569C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C38u);
	// 0x27C258: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27C260: movss [0x00569C9C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C9Cu, ctx.xmm[0].u32[0]);
	// 0x27C268: ret
	return;
}

void sub_27C270(X86Context& ctx, uint8_t* base) {
	// 0x27C270: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27C278: movss [0x00569CCC], xmm0
	X86_MEM_WRITE_u32(base, 0x569CCCu, ctx.xmm[0].u32[0]);
	// 0x27C280: ret
	return;
}

void sub_27C290(X86Context& ctx, uint8_t* base) {
	// 0x27C290: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27C298: movss [0x00569CB8], xmm0
	X86_MEM_WRITE_u32(base, 0x569CB8u, ctx.xmm[0].u32[0]);
	// 0x27C2A0: ret
	return;
}

void sub_27C2B0(X86Context& ctx, uint8_t* base) {
	// 0x27C2B0: movss xmm0, dword ptr [0x00569CB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CB8u);
	// 0x27C2B8: movss [0x00569CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x569CC8u, ctx.xmm[0].u32[0]);
	// 0x27C2C0: ret
	return;
}

void sub_27C2D0(X86Context& ctx, uint8_t* base) {
	// 0x27C2D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27C2D8: movss [0x00569C24], xmm0
	X86_MEM_WRITE_u32(base, 0x569C24u, ctx.xmm[0].u32[0]);
	// 0x27C2E0: ret
	return;
}

void sub_27C2F0(X86Context& ctx, uint8_t* base) {
	// 0x27C2F0: movss xmm0, dword ptr [0x00569C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C38u);
	// 0x27C2F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27C300: movss [0x00569CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x569CC0u, ctx.xmm[0].u32[0]);
	// 0x27C308: ret
	return;
}

void sub_27C310(X86Context& ctx, uint8_t* base) {
	// 0x27C310: movss xmm0, dword ptr [0x00569C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C38u);
	// 0x27C318: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27C320: movss [0x00569C64], xmm0
	X86_MEM_WRITE_u32(base, 0x569C64u, ctx.xmm[0].u32[0]);
	// 0x27C328: ret
	return;
}

void sub_27C330(X86Context& ctx, uint8_t* base) {
	// 0x27C330: movss xmm0, dword ptr [0x00569C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C38u);
	// 0x27C338: subss xmm0, [0x00569C64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569C64u);
	// 0x27C340: movss [0x00569C40], xmm0
	X86_MEM_WRITE_u32(base, 0x569C40u, ctx.xmm[0].u32[0]);
	// 0x27C348: ret
	return;
}

void sub_27C350(X86Context& ctx, uint8_t* base) {
	// 0x27C350: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27C358: movss [0x00569C90], xmm0
	X86_MEM_WRITE_u32(base, 0x569C90u, ctx.xmm[0].u32[0]);
	// 0x27C360: ret
	return;
}

void sub_27C370(X86Context& ctx, uint8_t* base) {
	// 0x27C370: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27C378: movss [0x00569C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C3Cu, ctx.xmm[0].u32[0]);
	// 0x27C380: ret
	return;
}

void sub_27C390(X86Context& ctx, uint8_t* base) {
	// 0x27C390: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27C398: movss [0x00569C50], xmm0
	X86_MEM_WRITE_u32(base, 0x569C50u, ctx.xmm[0].u32[0]);
	// 0x27C3A0: ret
	return;
}

void sub_27C3B0(X86Context& ctx, uint8_t* base) {
	// 0x27C3B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27C3B8: movss [0x00569CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x569CA8u, ctx.xmm[0].u32[0]);
	// 0x27C3C0: ret
	return;
}

void sub_27C3D0(X86Context& ctx, uint8_t* base) {
	// 0x27C3D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27C3D8: movss [0x00569C8C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C8Cu, ctx.xmm[0].u32[0]);
	// 0x27C3E0: ret
	return;
}

void sub_27C3F0(X86Context& ctx, uint8_t* base) {
	// 0x27C3F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27C3F8: movss [0x00569C34], xmm0
	X86_MEM_WRITE_u32(base, 0x569C34u, ctx.xmm[0].u32[0]);
	// 0x27C400: ret
	return;
}

void sub_27C410(X86Context& ctx, uint8_t* base) {
	// 0x27C410: movss xmm0, dword ptr [0x00569C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C50u);
	// 0x27C418: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27C420: movss [0x00569C28], xmm0
	X86_MEM_WRITE_u32(base, 0x569C28u, ctx.xmm[0].u32[0]);
	// 0x27C428: ret
	return;
}

void sub_27C430(X86Context& ctx, uint8_t* base) {
	// 0x27C430: movss xmm0, dword ptr [0x00569CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CA8u);
	// 0x27C438: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27C440: movss [0x00569C70], xmm0
	X86_MEM_WRITE_u32(base, 0x569C70u, ctx.xmm[0].u32[0]);
	// 0x27C448: ret
	return;
}

void sub_27C450(X86Context& ctx, uint8_t* base) {
	// 0x27C450: movss xmm0, dword ptr [0x00569C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C28u);
	// 0x27C458: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27C460: movss [0x00569C84], xmm0
	X86_MEM_WRITE_u32(base, 0x569C84u, ctx.xmm[0].u32[0]);
	// 0x27C468: ret
	return;
}

void sub_27C470(X86Context& ctx, uint8_t* base) {
	// 0x27C470: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27C478: movss [0x00569C20], xmm0
	X86_MEM_WRITE_u32(base, 0x569C20u, ctx.xmm[0].u32[0]);
	// 0x27C480: ret
	return;
}

void sub_27C490(X86Context& ctx, uint8_t* base) {
	// 0x27C490: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27C498: movss [0x00569C54], xmm0
	X86_MEM_WRITE_u32(base, 0x569C54u, ctx.xmm[0].u32[0]);
	// 0x27C4A0: ret
	return;
}

void sub_27C4B0(X86Context& ctx, uint8_t* base) {
	// 0x27C4B0: movss xmm0, dword ptr [0x00569C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C50u);
	// 0x27C4B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27C4C0: movss [0x00569C60], xmm0
	X86_MEM_WRITE_u32(base, 0x569C60u, ctx.xmm[0].u32[0]);
	// 0x27C4C8: ret
	return;
}

void sub_27C4D0(X86Context& ctx, uint8_t* base) {
	// 0x27C4D0: movss xmm0, dword ptr [0x00569CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CA8u);
	// 0x27C4D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27C4E0: movss [0x00569CAC], xmm0
	X86_MEM_WRITE_u32(base, 0x569CACu, ctx.xmm[0].u32[0]);
	// 0x27C4E8: ret
	return;
}

void sub_27C4F0(X86Context& ctx, uint8_t* base) {
	// 0x27C4F0: movss xmm0, dword ptr [0x00569C60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C60u);
	// 0x27C4F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C500: movss [0x00569C98], xmm0
	X86_MEM_WRITE_u32(base, 0x569C98u, ctx.xmm[0].u32[0]);
	// 0x27C508: ret
	return;
}

void sub_27C510(X86Context& ctx, uint8_t* base) {
	// 0x27C510: movss xmm0, dword ptr [0x00569CAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CACu);
	// 0x27C518: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C520: movss [0x00569CBC], xmm0
	X86_MEM_WRITE_u32(base, 0x569CBCu, ctx.xmm[0].u32[0]);
	// 0x27C528: ret
	return;
}

void sub_27C530(X86Context& ctx, uint8_t* base) {
	// 0x27C530: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27C538: movss [0x00569C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C2Cu, ctx.xmm[0].u32[0]);
	// 0x27C540: ret
	return;
}

void sub_27C550(X86Context& ctx, uint8_t* base) {
	// 0x27C550: movss xmm0, dword ptr [0x00569C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C50u);
	// 0x27C558: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C560: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27C568: movss [0x00569CA4], xmm0
	X86_MEM_WRITE_u32(base, 0x569CA4u, ctx.xmm[0].u32[0]);
	// 0x27C570: ret
	return;
}

void sub_27C580(X86Context& ctx, uint8_t* base) {
	// 0x27C580: movss xmm0, dword ptr [0x00569CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CA8u);
	// 0x27C588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C590: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27C598: movss [0x00569C44], xmm0
	X86_MEM_WRITE_u32(base, 0x569C44u, ctx.xmm[0].u32[0]);
	// 0x27C5A0: ret
	return;
}

void sub_27C5B0(X86Context& ctx, uint8_t* base) {
	// 0x27C5B0: movss xmm0, dword ptr [0x00569C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C50u);
	// 0x27C5B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C5C0: movss [0x00569C48], xmm0
	X86_MEM_WRITE_u32(base, 0x569C48u, ctx.xmm[0].u32[0]);
	// 0x27C5C8: ret
	return;
}

void sub_27C5D0(X86Context& ctx, uint8_t* base) {
	// 0x27C5D0: movss xmm0, dword ptr [0x00569CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CA8u);
	// 0x27C5D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27C5E0: movss [0x00569CB0], xmm0
	X86_MEM_WRITE_u32(base, 0x569CB0u, ctx.xmm[0].u32[0]);
	// 0x27C5E8: ret
	return;
}

void sub_27C5F0(X86Context& ctx, uint8_t* base) {
	// 0x27C5F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27C5F8: movss [0x00569C30], xmm0
	X86_MEM_WRITE_u32(base, 0x569C30u, ctx.xmm[0].u32[0]);
	// 0x27C600: ret
	return;
}

void sub_27C610(X86Context& ctx, uint8_t* base) {
	// 0x27C610: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27C618: movss [0x00569C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C5Cu, ctx.xmm[0].u32[0]);
	// 0x27C620: ret
	return;
}

void sub_27C630(X86Context& ctx, uint8_t* base) {
	// 0x27C630: movss xmm0, dword ptr [0x00569C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C30u);
	// 0x27C638: movss [0x00569CC4], xmm0
	X86_MEM_WRITE_u32(base, 0x569CC4u, ctx.xmm[0].u32[0]);
	// 0x27C640: ret
	return;
}

void sub_27C650(X86Context& ctx, uint8_t* base) {
	// 0x27C650: movss xmm0, dword ptr [0x00569CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CA8u);
	// 0x27C658: subss xmm0, [0x00569C30]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569C30u);
	// 0x27C660: movss [0x00569C88], xmm0
	X86_MEM_WRITE_u32(base, 0x569C88u, ctx.xmm[0].u32[0]);
	// 0x27C668: ret
	return;
}

void sub_27C670(X86Context& ctx, uint8_t* base) {
	// 0x27C670: movss xmm0, dword ptr [0x00569C88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C88u);
	// 0x27C678: subss xmm0, [0x00569C5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569C5Cu);
	// 0x27C680: movss [0x00569C80], xmm0
	X86_MEM_WRITE_u32(base, 0x569C80u, ctx.xmm[0].u32[0]);
	// 0x27C688: ret
	return;
}

void sub_27C690(X86Context& ctx, uint8_t* base) {
	// 0x27C690: movss xmm0, dword ptr [0x00569CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CB0u);
	// 0x27C698: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27C6A0: movss [0x00569C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C6Cu, ctx.xmm[0].u32[0]);
	// 0x27C6A8: ret
	return;
}

void sub_27C6B0(X86Context& ctx, uint8_t* base) {
	// 0x27C6B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27C6B8: movss [0x00569C58], xmm0
	X86_MEM_WRITE_u32(base, 0x569C58u, ctx.xmm[0].u32[0]);
	// 0x27C6C0: ret
	return;
}

void sub_27C6D0(X86Context& ctx, uint8_t* base) {
	// 0x27C6D0: movss xmm0, dword ptr [0x00569C6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569C6Cu);
	// 0x27C6D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27C6E0: movss [0x00569CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x569CA0u, ctx.xmm[0].u32[0]);
	// 0x27C6E8: ret
	return;
}

void sub_27C6F0(X86Context& ctx, uint8_t* base) {
	// 0x27C6F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27C6F8: movss [0x00569C74], xmm0
	X86_MEM_WRITE_u32(base, 0x569C74u, ctx.xmm[0].u32[0]);
	// 0x27C700: ret
	return;
}

void sub_27C710(X86Context& ctx, uint8_t* base) {
	// 0x27C710: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27C718: movss [0x00569C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x569C4Cu, ctx.xmm[0].u32[0]);
	// 0x27C720: ret
	return;
}

void sub_27C730(X86Context& ctx, uint8_t* base) {
	// 0x27C730: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27C738: movss [0x00569D2C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D2Cu, ctx.xmm[0].u32[0]);
	// 0x27C740: ret
	return;
}

void sub_27C750(X86Context& ctx, uint8_t* base) {
	// 0x27C750: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27C758: movss [0x00569D48], xmm0
	X86_MEM_WRITE_u32(base, 0x569D48u, ctx.xmm[0].u32[0]);
	// 0x27C760: ret
	return;
}

void sub_27C770(X86Context& ctx, uint8_t* base) {
	// 0x27C770: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27C778: movss [0x00569D1C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D1Cu, ctx.xmm[0].u32[0]);
	// 0x27C780: ret
	return;
}

void sub_27C790(X86Context& ctx, uint8_t* base) {
	// 0x27C790: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27C798: movss [0x00569CD0], xmm0
	X86_MEM_WRITE_u32(base, 0x569CD0u, ctx.xmm[0].u32[0]);
	// 0x27C7A0: ret
	return;
}

void sub_27C7B0(X86Context& ctx, uint8_t* base) {
	// 0x27C7B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27C7B8: movss [0x00569D30], xmm0
	X86_MEM_WRITE_u32(base, 0x569D30u, ctx.xmm[0].u32[0]);
	// 0x27C7C0: ret
	return;
}

void sub_27C7D0(X86Context& ctx, uint8_t* base) {
	// 0x27C7D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27C7D8: movss [0x00569CEC], xmm0
	X86_MEM_WRITE_u32(base, 0x569CECu, ctx.xmm[0].u32[0]);
	// 0x27C7E0: ret
	return;
}

void sub_27C7F0(X86Context& ctx, uint8_t* base) {
	// 0x27C7F0: movss xmm0, dword ptr [0x00569D30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D30u);
	// 0x27C7F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27C800: movss [0x00569D68], xmm0
	X86_MEM_WRITE_u32(base, 0x569D68u, ctx.xmm[0].u32[0]);
	// 0x27C808: ret
	return;
}

void sub_27C810(X86Context& ctx, uint8_t* base) {
	// 0x27C810: movss xmm0, dword ptr [0x00569CEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CECu);
	// 0x27C818: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27C820: movss [0x00569D50], xmm0
	X86_MEM_WRITE_u32(base, 0x569D50u, ctx.xmm[0].u32[0]);
	// 0x27C828: ret
	return;
}

void sub_27C830(X86Context& ctx, uint8_t* base) {
	// 0x27C830: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27C838: movss [0x00569D80], xmm0
	X86_MEM_WRITE_u32(base, 0x569D80u, ctx.xmm[0].u32[0]);
	// 0x27C840: ret
	return;
}

void sub_27C850(X86Context& ctx, uint8_t* base) {
	// 0x27C850: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27C858: movss [0x00569D6C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D6Cu, ctx.xmm[0].u32[0]);
	// 0x27C860: ret
	return;
}

void sub_27C870(X86Context& ctx, uint8_t* base) {
	// 0x27C870: movss xmm0, dword ptr [0x00569D6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D6Cu);
	// 0x27C878: movss [0x00569D7C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D7Cu, ctx.xmm[0].u32[0]);
	// 0x27C880: ret
	return;
}

void sub_27C890(X86Context& ctx, uint8_t* base) {
	// 0x27C890: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27C898: movss [0x00569CD8], xmm0
	X86_MEM_WRITE_u32(base, 0x569CD8u, ctx.xmm[0].u32[0]);
	// 0x27C8A0: ret
	return;
}

void sub_27C8B0(X86Context& ctx, uint8_t* base) {
	// 0x27C8B0: movss xmm0, dword ptr [0x00569CEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CECu);
	// 0x27C8B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27C8C0: movss [0x00569D74], xmm0
	X86_MEM_WRITE_u32(base, 0x569D74u, ctx.xmm[0].u32[0]);
	// 0x27C8C8: ret
	return;
}

void sub_27C8D0(X86Context& ctx, uint8_t* base) {
	// 0x27C8D0: movss xmm0, dword ptr [0x00569CEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CECu);
	// 0x27C8D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27C8E0: movss [0x00569D18], xmm0
	X86_MEM_WRITE_u32(base, 0x569D18u, ctx.xmm[0].u32[0]);
	// 0x27C8E8: ret
	return;
}

void sub_27C8F0(X86Context& ctx, uint8_t* base) {
	// 0x27C8F0: movss xmm0, dword ptr [0x00569CEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CECu);
	// 0x27C8F8: subss xmm0, [0x00569D18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569D18u);
	// 0x27C900: movss [0x00569CF4], xmm0
	X86_MEM_WRITE_u32(base, 0x569CF4u, ctx.xmm[0].u32[0]);
	// 0x27C908: ret
	return;
}

void sub_27C910(X86Context& ctx, uint8_t* base) {
	// 0x27C910: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27C918: movss [0x00569D44], xmm0
	X86_MEM_WRITE_u32(base, 0x569D44u, ctx.xmm[0].u32[0]);
	// 0x27C920: ret
	return;
}

void sub_27C930(X86Context& ctx, uint8_t* base) {
	// 0x27C930: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27C938: movss [0x00569CF0], xmm0
	X86_MEM_WRITE_u32(base, 0x569CF0u, ctx.xmm[0].u32[0]);
	// 0x27C940: ret
	return;
}

void sub_27C950(X86Context& ctx, uint8_t* base) {
	// 0x27C950: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27C958: movss [0x00569D04], xmm0
	X86_MEM_WRITE_u32(base, 0x569D04u, ctx.xmm[0].u32[0]);
	// 0x27C960: ret
	return;
}

void sub_27C970(X86Context& ctx, uint8_t* base) {
	// 0x27C970: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27C978: movss [0x00569D5C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D5Cu, ctx.xmm[0].u32[0]);
	// 0x27C980: ret
	return;
}

void sub_27C990(X86Context& ctx, uint8_t* base) {
	// 0x27C990: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27C998: movss [0x00569D40], xmm0
	X86_MEM_WRITE_u32(base, 0x569D40u, ctx.xmm[0].u32[0]);
	// 0x27C9A0: ret
	return;
}

void sub_27C9B0(X86Context& ctx, uint8_t* base) {
	// 0x27C9B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27C9B8: movss [0x00569CE8], xmm0
	X86_MEM_WRITE_u32(base, 0x569CE8u, ctx.xmm[0].u32[0]);
	// 0x27C9C0: ret
	return;
}

void sub_27C9D0(X86Context& ctx, uint8_t* base) {
	// 0x27C9D0: movss xmm0, dword ptr [0x00569D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D04u);
	// 0x27C9D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27C9E0: movss [0x00569CDC], xmm0
	X86_MEM_WRITE_u32(base, 0x569CDCu, ctx.xmm[0].u32[0]);
	// 0x27C9E8: ret
	return;
}

void sub_27C9F0(X86Context& ctx, uint8_t* base) {
	// 0x27C9F0: movss xmm0, dword ptr [0x00569D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D5Cu);
	// 0x27C9F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27CA00: movss [0x00569D24], xmm0
	X86_MEM_WRITE_u32(base, 0x569D24u, ctx.xmm[0].u32[0]);
	// 0x27CA08: ret
	return;
}

void sub_27CA10(X86Context& ctx, uint8_t* base) {
	// 0x27CA10: movss xmm0, dword ptr [0x00569CDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CDCu);
	// 0x27CA18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27CA20: movss [0x00569D38], xmm0
	X86_MEM_WRITE_u32(base, 0x569D38u, ctx.xmm[0].u32[0]);
	// 0x27CA28: ret
	return;
}

void sub_27CA30(X86Context& ctx, uint8_t* base) {
	// 0x27CA30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27CA38: movss [0x00569CD4], xmm0
	X86_MEM_WRITE_u32(base, 0x569CD4u, ctx.xmm[0].u32[0]);
	// 0x27CA40: ret
	return;
}

void sub_27CA50(X86Context& ctx, uint8_t* base) {
	// 0x27CA50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27CA58: movss [0x00569D08], xmm0
	X86_MEM_WRITE_u32(base, 0x569D08u, ctx.xmm[0].u32[0]);
	// 0x27CA60: ret
	return;
}

void sub_27CA70(X86Context& ctx, uint8_t* base) {
	// 0x27CA70: movss xmm0, dword ptr [0x00569D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D04u);
	// 0x27CA78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27CA80: movss [0x00569D14], xmm0
	X86_MEM_WRITE_u32(base, 0x569D14u, ctx.xmm[0].u32[0]);
	// 0x27CA88: ret
	return;
}

void sub_27CA90(X86Context& ctx, uint8_t* base) {
	// 0x27CA90: movss xmm0, dword ptr [0x00569D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D5Cu);
	// 0x27CA98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27CAA0: movss [0x00569D60], xmm0
	X86_MEM_WRITE_u32(base, 0x569D60u, ctx.xmm[0].u32[0]);
	// 0x27CAA8: ret
	return;
}

void sub_27CAB0(X86Context& ctx, uint8_t* base) {
	// 0x27CAB0: movss xmm0, dword ptr [0x00569D14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D14u);
	// 0x27CAB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27CAC0: movss [0x00569D4C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D4Cu, ctx.xmm[0].u32[0]);
	// 0x27CAC8: ret
	return;
}

void sub_27CAD0(X86Context& ctx, uint8_t* base) {
	// 0x27CAD0: movss xmm0, dword ptr [0x00569D60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D60u);
	// 0x27CAD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27CAE0: movss [0x00569D70], xmm0
	X86_MEM_WRITE_u32(base, 0x569D70u, ctx.xmm[0].u32[0]);
	// 0x27CAE8: ret
	return;
}

void sub_27CAF0(X86Context& ctx, uint8_t* base) {
	// 0x27CAF0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27CAF8: movss [0x00569CE0], xmm0
	X86_MEM_WRITE_u32(base, 0x569CE0u, ctx.xmm[0].u32[0]);
	// 0x27CB00: ret
	return;
}

void sub_27CB10(X86Context& ctx, uint8_t* base) {
	// 0x27CB10: movss xmm0, dword ptr [0x00569D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D04u);
	// 0x27CB18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27CB20: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27CB28: movss [0x00569D58], xmm0
	X86_MEM_WRITE_u32(base, 0x569D58u, ctx.xmm[0].u32[0]);
	// 0x27CB30: ret
	return;
}

void sub_27CB40(X86Context& ctx, uint8_t* base) {
	// 0x27CB40: movss xmm0, dword ptr [0x00569D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D5Cu);
	// 0x27CB48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27CB50: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27CB58: movss [0x00569CF8], xmm0
	X86_MEM_WRITE_u32(base, 0x569CF8u, ctx.xmm[0].u32[0]);
	// 0x27CB60: ret
	return;
}

void sub_27CB70(X86Context& ctx, uint8_t* base) {
	// 0x27CB70: movss xmm0, dword ptr [0x00569D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D04u);
	// 0x27CB78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27CB80: movss [0x00569CFC], xmm0
	X86_MEM_WRITE_u32(base, 0x569CFCu, ctx.xmm[0].u32[0]);
	// 0x27CB88: ret
	return;
}

void sub_27CB90(X86Context& ctx, uint8_t* base) {
	// 0x27CB90: movss xmm0, dword ptr [0x00569D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D5Cu);
	// 0x27CB98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27CBA0: movss [0x00569D64], xmm0
	X86_MEM_WRITE_u32(base, 0x569D64u, ctx.xmm[0].u32[0]);
	// 0x27CBA8: ret
	return;
}

void sub_27CBB0(X86Context& ctx, uint8_t* base) {
	// 0x27CBB0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27CBB8: movss [0x00569CE4], xmm0
	X86_MEM_WRITE_u32(base, 0x569CE4u, ctx.xmm[0].u32[0]);
	// 0x27CBC0: ret
	return;
}

void sub_27CBD0(X86Context& ctx, uint8_t* base) {
	// 0x27CBD0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27CBD8: movss [0x00569D10], xmm0
	X86_MEM_WRITE_u32(base, 0x569D10u, ctx.xmm[0].u32[0]);
	// 0x27CBE0: ret
	return;
}

void sub_27CBF0(X86Context& ctx, uint8_t* base) {
	// 0x27CBF0: movss xmm0, dword ptr [0x00569CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569CE4u);
	// 0x27CBF8: movss [0x00569D78], xmm0
	X86_MEM_WRITE_u32(base, 0x569D78u, ctx.xmm[0].u32[0]);
	// 0x27CC00: ret
	return;
}

void sub_27CC10(X86Context& ctx, uint8_t* base) {
	// 0x27CC10: movss xmm0, dword ptr [0x00569D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D5Cu);
	// 0x27CC18: subss xmm0, [0x00569CE4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569CE4u);
	// 0x27CC20: movss [0x00569D3C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D3Cu, ctx.xmm[0].u32[0]);
	// 0x27CC28: ret
	return;
}

void sub_27CC30(X86Context& ctx, uint8_t* base) {
	// 0x27CC30: movss xmm0, dword ptr [0x00569D3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D3Cu);
	// 0x27CC38: subss xmm0, [0x00569D10]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569D10u);
	// 0x27CC40: movss [0x00569D34], xmm0
	X86_MEM_WRITE_u32(base, 0x569D34u, ctx.xmm[0].u32[0]);
	// 0x27CC48: ret
	return;
}

void sub_27CC50(X86Context& ctx, uint8_t* base) {
	// 0x27CC50: movss xmm0, dword ptr [0x00569D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D64u);
	// 0x27CC58: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27CC60: movss [0x00569D20], xmm0
	X86_MEM_WRITE_u32(base, 0x569D20u, ctx.xmm[0].u32[0]);
	// 0x27CC68: ret
	return;
}

void sub_27CC70(X86Context& ctx, uint8_t* base) {
	// 0x27CC70: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27CC78: movss [0x00569D0C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D0Cu, ctx.xmm[0].u32[0]);
	// 0x27CC80: ret
	return;
}

void sub_27CC90(X86Context& ctx, uint8_t* base) {
	// 0x27CC90: movss xmm0, dword ptr [0x00569D20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D20u);
	// 0x27CC98: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27CCA0: movss [0x00569D54], xmm0
	X86_MEM_WRITE_u32(base, 0x569D54u, ctx.xmm[0].u32[0]);
	// 0x27CCA8: ret
	return;
}

void sub_27CCB0(X86Context& ctx, uint8_t* base) {
	// 0x27CCB0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27CCB8: movss [0x00569D28], xmm0
	X86_MEM_WRITE_u32(base, 0x569D28u, ctx.xmm[0].u32[0]);
	// 0x27CCC0: ret
	return;
}

void sub_27CCD0(X86Context& ctx, uint8_t* base) {
	// 0x27CCD0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27CCD8: movss [0x00569D00], xmm0
	X86_MEM_WRITE_u32(base, 0x569D00u, ctx.xmm[0].u32[0]);
	// 0x27CCE0: ret
	return;
}

void sub_27CCF0(X86Context& ctx, uint8_t* base) {
	// 0x27CCF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27CCF8: movss [0x00569DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x569DE0u, ctx.xmm[0].u32[0]);
	// 0x27CD00: ret
	return;
}

void sub_27CD10(X86Context& ctx, uint8_t* base) {
	// 0x27CD10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27CD18: movss [0x00569DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x569DFCu, ctx.xmm[0].u32[0]);
	// 0x27CD20: ret
	return;
}

void sub_27CD30(X86Context& ctx, uint8_t* base) {
	// 0x27CD30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27CD38: movss [0x00569DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x569DD0u, ctx.xmm[0].u32[0]);
	// 0x27CD40: ret
	return;
}

void sub_27CD50(X86Context& ctx, uint8_t* base) {
	// 0x27CD50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27CD58: movss [0x00569D84], xmm0
	X86_MEM_WRITE_u32(base, 0x569D84u, ctx.xmm[0].u32[0]);
	// 0x27CD60: ret
	return;
}

void sub_27CD70(X86Context& ctx, uint8_t* base) {
	// 0x27CD70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27CD78: movss [0x00569DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x569DE4u, ctx.xmm[0].u32[0]);
	// 0x27CD80: ret
	return;
}

void sub_27CD90(X86Context& ctx, uint8_t* base) {
	// 0x27CD90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27CD98: movss [0x00569DA0], xmm0
	X86_MEM_WRITE_u32(base, 0x569DA0u, ctx.xmm[0].u32[0]);
	// 0x27CDA0: ret
	return;
}

void sub_27CDB0(X86Context& ctx, uint8_t* base) {
	// 0x27CDB0: movss xmm0, dword ptr [0x00569DE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DE4u);
	// 0x27CDB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27CDC0: movss [0x00569E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E1Cu, ctx.xmm[0].u32[0]);
	// 0x27CDC8: ret
	return;
}

void sub_27CDD0(X86Context& ctx, uint8_t* base) {
	// 0x27CDD0: movss xmm0, dword ptr [0x00569DA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DA0u);
	// 0x27CDD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27CDE0: movss [0x00569E04], xmm0
	X86_MEM_WRITE_u32(base, 0x569E04u, ctx.xmm[0].u32[0]);
	// 0x27CDE8: ret
	return;
}

void sub_27CDF0(X86Context& ctx, uint8_t* base) {
	// 0x27CDF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27CDF8: movss [0x00569E34], xmm0
	X86_MEM_WRITE_u32(base, 0x569E34u, ctx.xmm[0].u32[0]);
	// 0x27CE00: ret
	return;
}

void sub_27CE10(X86Context& ctx, uint8_t* base) {
	// 0x27CE10: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27CE18: movss [0x00569E20], xmm0
	X86_MEM_WRITE_u32(base, 0x569E20u, ctx.xmm[0].u32[0]);
	// 0x27CE20: ret
	return;
}

void sub_27CE30(X86Context& ctx, uint8_t* base) {
	// 0x27CE30: movss xmm0, dword ptr [0x00569E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E20u);
	// 0x27CE38: movss [0x00569E30], xmm0
	X86_MEM_WRITE_u32(base, 0x569E30u, ctx.xmm[0].u32[0]);
	// 0x27CE40: ret
	return;
}

void sub_27CE50(X86Context& ctx, uint8_t* base) {
	// 0x27CE50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27CE58: movss [0x00569D8C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D8Cu, ctx.xmm[0].u32[0]);
	// 0x27CE60: ret
	return;
}

void sub_27CE70(X86Context& ctx, uint8_t* base) {
	// 0x27CE70: movss xmm0, dword ptr [0x00569DA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DA0u);
	// 0x27CE78: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27CE80: movss [0x00569E28], xmm0
	X86_MEM_WRITE_u32(base, 0x569E28u, ctx.xmm[0].u32[0]);
	// 0x27CE88: ret
	return;
}

void sub_27CE90(X86Context& ctx, uint8_t* base) {
	// 0x27CE90: movss xmm0, dword ptr [0x00569DA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DA0u);
	// 0x27CE98: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27CEA0: movss [0x00569DCC], xmm0
	X86_MEM_WRITE_u32(base, 0x569DCCu, ctx.xmm[0].u32[0]);
	// 0x27CEA8: ret
	return;
}

void sub_27CEB0(X86Context& ctx, uint8_t* base) {
	// 0x27CEB0: movss xmm0, dword ptr [0x00569DA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DA0u);
	// 0x27CEB8: subss xmm0, [0x00569DCC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569DCCu);
	// 0x27CEC0: movss [0x00569DA8], xmm0
	X86_MEM_WRITE_u32(base, 0x569DA8u, ctx.xmm[0].u32[0]);
	// 0x27CEC8: ret
	return;
}

void sub_27CED0(X86Context& ctx, uint8_t* base) {
	// 0x27CED0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27CED8: movss [0x00569DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x569DF8u, ctx.xmm[0].u32[0]);
	// 0x27CEE0: ret
	return;
}

void sub_27CEF0(X86Context& ctx, uint8_t* base) {
	// 0x27CEF0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27CEF8: movss [0x00569DA4], xmm0
	X86_MEM_WRITE_u32(base, 0x569DA4u, ctx.xmm[0].u32[0]);
	// 0x27CF00: ret
	return;
}

void sub_27CF10(X86Context& ctx, uint8_t* base) {
	// 0x27CF10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27CF18: movss [0x00569DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x569DB8u, ctx.xmm[0].u32[0]);
	// 0x27CF20: ret
	return;
}

void sub_27CF30(X86Context& ctx, uint8_t* base) {
	// 0x27CF30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27CF38: movss [0x00569E10], xmm0
	X86_MEM_WRITE_u32(base, 0x569E10u, ctx.xmm[0].u32[0]);
	// 0x27CF40: ret
	return;
}

void sub_27CF50(X86Context& ctx, uint8_t* base) {
	// 0x27CF50: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27CF58: movss [0x00569DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x569DF4u, ctx.xmm[0].u32[0]);
	// 0x27CF60: ret
	return;
}

void sub_27CF70(X86Context& ctx, uint8_t* base) {
	// 0x27CF70: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27CF78: movss [0x00569D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x569D9Cu, ctx.xmm[0].u32[0]);
	// 0x27CF80: ret
	return;
}

void sub_27CF90(X86Context& ctx, uint8_t* base) {
	// 0x27CF90: movss xmm0, dword ptr [0x00569DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DB8u);
	// 0x27CF98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27CFA0: movss [0x00569D90], xmm0
	X86_MEM_WRITE_u32(base, 0x569D90u, ctx.xmm[0].u32[0]);
	// 0x27CFA8: ret
	return;
}

void sub_27CFB0(X86Context& ctx, uint8_t* base) {
	// 0x27CFB0: movss xmm0, dword ptr [0x00569E10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E10u);
	// 0x27CFB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27CFC0: movss [0x00569DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x569DD8u, ctx.xmm[0].u32[0]);
	// 0x27CFC8: ret
	return;
}

void sub_27CFD0(X86Context& ctx, uint8_t* base) {
	// 0x27CFD0: movss xmm0, dword ptr [0x00569D90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D90u);
	// 0x27CFD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27CFE0: movss [0x00569DEC], xmm0
	X86_MEM_WRITE_u32(base, 0x569DECu, ctx.xmm[0].u32[0]);
	// 0x27CFE8: ret
	return;
}

void sub_27CFF0(X86Context& ctx, uint8_t* base) {
	// 0x27CFF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27CFF8: movss [0x00569D88], xmm0
	X86_MEM_WRITE_u32(base, 0x569D88u, ctx.xmm[0].u32[0]);
	// 0x27D000: ret
	return;
}

void sub_27D010(X86Context& ctx, uint8_t* base) {
	// 0x27D010: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27D018: movss [0x00569DBC], xmm0
	X86_MEM_WRITE_u32(base, 0x569DBCu, ctx.xmm[0].u32[0]);
	// 0x27D020: ret
	return;
}

void sub_27D030(X86Context& ctx, uint8_t* base) {
	// 0x27D030: movss xmm0, dword ptr [0x00569DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DB8u);
	// 0x27D038: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27D040: movss [0x00569DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x569DC8u, ctx.xmm[0].u32[0]);
	// 0x27D048: ret
	return;
}

void sub_27D050(X86Context& ctx, uint8_t* base) {
	// 0x27D050: movss xmm0, dword ptr [0x00569E10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E10u);
	// 0x27D058: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27D060: movss [0x00569E14], xmm0
	X86_MEM_WRITE_u32(base, 0x569E14u, ctx.xmm[0].u32[0]);
	// 0x27D068: ret
	return;
}

void sub_27D070(X86Context& ctx, uint8_t* base) {
	// 0x27D070: movss xmm0, dword ptr [0x00569DC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DC8u);
	// 0x27D078: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D080: movss [0x00569E00], xmm0
	X86_MEM_WRITE_u32(base, 0x569E00u, ctx.xmm[0].u32[0]);
	// 0x27D088: ret
	return;
}

void sub_27D090(X86Context& ctx, uint8_t* base) {
	// 0x27D090: movss xmm0, dword ptr [0x00569E14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E14u);
	// 0x27D098: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D0A0: movss [0x00569E24], xmm0
	X86_MEM_WRITE_u32(base, 0x569E24u, ctx.xmm[0].u32[0]);
	// 0x27D0A8: ret
	return;
}

void sub_27D0B0(X86Context& ctx, uint8_t* base) {
	// 0x27D0B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27D0B8: movss [0x00569D94], xmm0
	X86_MEM_WRITE_u32(base, 0x569D94u, ctx.xmm[0].u32[0]);
	// 0x27D0C0: ret
	return;
}

void sub_27D0D0(X86Context& ctx, uint8_t* base) {
	// 0x27D0D0: movss xmm0, dword ptr [0x00569DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DB8u);
	// 0x27D0D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D0E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27D0E8: movss [0x00569E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E0Cu, ctx.xmm[0].u32[0]);
	// 0x27D0F0: ret
	return;
}

void sub_27D100(X86Context& ctx, uint8_t* base) {
	// 0x27D100: movss xmm0, dword ptr [0x00569E10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E10u);
	// 0x27D108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D110: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27D118: movss [0x00569DAC], xmm0
	X86_MEM_WRITE_u32(base, 0x569DACu, ctx.xmm[0].u32[0]);
	// 0x27D120: ret
	return;
}

void sub_27D130(X86Context& ctx, uint8_t* base) {
	// 0x27D130: movss xmm0, dword ptr [0x00569DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DB8u);
	// 0x27D138: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D140: movss [0x00569DB0], xmm0
	X86_MEM_WRITE_u32(base, 0x569DB0u, ctx.xmm[0].u32[0]);
	// 0x27D148: ret
	return;
}

void sub_27D150(X86Context& ctx, uint8_t* base) {
	// 0x27D150: movss xmm0, dword ptr [0x00569E10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E10u);
	// 0x27D158: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D160: movss [0x00569E18], xmm0
	X86_MEM_WRITE_u32(base, 0x569E18u, ctx.xmm[0].u32[0]);
	// 0x27D168: ret
	return;
}

void sub_27D170(X86Context& ctx, uint8_t* base) {
	// 0x27D170: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27D178: movss [0x00569D98], xmm0
	X86_MEM_WRITE_u32(base, 0x569D98u, ctx.xmm[0].u32[0]);
	// 0x27D180: ret
	return;
}

void sub_27D190(X86Context& ctx, uint8_t* base) {
	// 0x27D190: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27D198: movss [0x00569DC4], xmm0
	X86_MEM_WRITE_u32(base, 0x569DC4u, ctx.xmm[0].u32[0]);
	// 0x27D1A0: ret
	return;
}

void sub_27D1B0(X86Context& ctx, uint8_t* base) {
	// 0x27D1B0: movss xmm0, dword ptr [0x00569D98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569D98u);
	// 0x27D1B8: movss [0x00569E2C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E2Cu, ctx.xmm[0].u32[0]);
	// 0x27D1C0: ret
	return;
}

void sub_27D1D0(X86Context& ctx, uint8_t* base) {
	// 0x27D1D0: movss xmm0, dword ptr [0x00569E10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E10u);
	// 0x27D1D8: subss xmm0, [0x00569D98]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569D98u);
	// 0x27D1E0: movss [0x00569DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x569DF0u, ctx.xmm[0].u32[0]);
	// 0x27D1E8: ret
	return;
}

void sub_27D1F0(X86Context& ctx, uint8_t* base) {
	// 0x27D1F0: movss xmm0, dword ptr [0x00569DF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DF0u);
	// 0x27D1F8: subss xmm0, [0x00569DC4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569DC4u);
	// 0x27D200: movss [0x00569DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x569DE8u, ctx.xmm[0].u32[0]);
	// 0x27D208: ret
	return;
}

void sub_27D210(X86Context& ctx, uint8_t* base) {
	// 0x27D210: movss xmm0, dword ptr [0x00569E18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E18u);
	// 0x27D218: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27D220: movss [0x00569DD4], xmm0
	X86_MEM_WRITE_u32(base, 0x569DD4u, ctx.xmm[0].u32[0]);
	// 0x27D228: ret
	return;
}

void sub_27D230(X86Context& ctx, uint8_t* base) {
	// 0x27D230: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27D238: movss [0x00569DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x569DC0u, ctx.xmm[0].u32[0]);
	// 0x27D240: ret
	return;
}

void sub_27D250(X86Context& ctx, uint8_t* base) {
	// 0x27D250: movss xmm0, dword ptr [0x00569DD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569DD4u);
	// 0x27D258: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27D260: movss [0x00569E08], xmm0
	X86_MEM_WRITE_u32(base, 0x569E08u, ctx.xmm[0].u32[0]);
	// 0x27D268: ret
	return;
}

void sub_27D270(X86Context& ctx, uint8_t* base) {
	// 0x27D270: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27D278: movss [0x00569DDC], xmm0
	X86_MEM_WRITE_u32(base, 0x569DDCu, ctx.xmm[0].u32[0]);
	// 0x27D280: ret
	return;
}

void sub_27D290(X86Context& ctx, uint8_t* base) {
	// 0x27D290: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27D298: movss [0x00569DB4], xmm0
	X86_MEM_WRITE_u32(base, 0x569DB4u, ctx.xmm[0].u32[0]);
	// 0x27D2A0: ret
	return;
}

void sub_27D2B0(X86Context& ctx, uint8_t* base) {
	// 0x27D2B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27D2B8: movss [0x00569E94], xmm0
	X86_MEM_WRITE_u32(base, 0x569E94u, ctx.xmm[0].u32[0]);
	// 0x27D2C0: ret
	return;
}

void sub_27D2D0(X86Context& ctx, uint8_t* base) {
	// 0x27D2D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27D2D8: movss [0x00569EB0], xmm0
	X86_MEM_WRITE_u32(base, 0x569EB0u, ctx.xmm[0].u32[0]);
	// 0x27D2E0: ret
	return;
}

void sub_27D2F0(X86Context& ctx, uint8_t* base) {
	// 0x27D2F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27D2F8: movss [0x00569E84], xmm0
	X86_MEM_WRITE_u32(base, 0x569E84u, ctx.xmm[0].u32[0]);
	// 0x27D300: ret
	return;
}

void sub_27D310(X86Context& ctx, uint8_t* base) {
	// 0x27D310: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27D318: movss [0x00569E38], xmm0
	X86_MEM_WRITE_u32(base, 0x569E38u, ctx.xmm[0].u32[0]);
	// 0x27D320: ret
	return;
}

void sub_27D330(X86Context& ctx, uint8_t* base) {
	// 0x27D330: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27D338: movss [0x00569E98], xmm0
	X86_MEM_WRITE_u32(base, 0x569E98u, ctx.xmm[0].u32[0]);
	// 0x27D340: ret
	return;
}

void sub_27D350(X86Context& ctx, uint8_t* base) {
	// 0x27D350: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27D358: movss [0x00569E54], xmm0
	X86_MEM_WRITE_u32(base, 0x569E54u, ctx.xmm[0].u32[0]);
	// 0x27D360: ret
	return;
}

void sub_27D370(X86Context& ctx, uint8_t* base) {
	// 0x27D370: movss xmm0, dword ptr [0x00569E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E98u);
	// 0x27D378: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27D380: movss [0x00569ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x569ED0u, ctx.xmm[0].u32[0]);
	// 0x27D388: ret
	return;
}

void sub_27D390(X86Context& ctx, uint8_t* base) {
	// 0x27D390: movss xmm0, dword ptr [0x00569E54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E54u);
	// 0x27D398: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27D3A0: movss [0x00569EB8], xmm0
	X86_MEM_WRITE_u32(base, 0x569EB8u, ctx.xmm[0].u32[0]);
	// 0x27D3A8: ret
	return;
}

void sub_27D3B0(X86Context& ctx, uint8_t* base) {
	// 0x27D3B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27D3B8: movss [0x00569EE8], xmm0
	X86_MEM_WRITE_u32(base, 0x569EE8u, ctx.xmm[0].u32[0]);
	// 0x27D3C0: ret
	return;
}

void sub_27D3D0(X86Context& ctx, uint8_t* base) {
	// 0x27D3D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27D3D8: movss [0x00569ED4], xmm0
	X86_MEM_WRITE_u32(base, 0x569ED4u, ctx.xmm[0].u32[0]);
	// 0x27D3E0: ret
	return;
}

void sub_27D3F0(X86Context& ctx, uint8_t* base) {
	// 0x27D3F0: movss xmm0, dword ptr [0x00569ED4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569ED4u);
	// 0x27D3F8: movss [0x00569EE4], xmm0
	X86_MEM_WRITE_u32(base, 0x569EE4u, ctx.xmm[0].u32[0]);
	// 0x27D400: ret
	return;
}

void sub_27D410(X86Context& ctx, uint8_t* base) {
	// 0x27D410: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27D418: movss [0x00569E40], xmm0
	X86_MEM_WRITE_u32(base, 0x569E40u, ctx.xmm[0].u32[0]);
	// 0x27D420: ret
	return;
}

void sub_27D430(X86Context& ctx, uint8_t* base) {
	// 0x27D430: movss xmm0, dword ptr [0x00569E54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E54u);
	// 0x27D438: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27D440: movss [0x00569EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x569EDCu, ctx.xmm[0].u32[0]);
	// 0x27D448: ret
	return;
}

void sub_27D450(X86Context& ctx, uint8_t* base) {
	// 0x27D450: movss xmm0, dword ptr [0x00569E54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E54u);
	// 0x27D458: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27D460: movss [0x00569E80], xmm0
	X86_MEM_WRITE_u32(base, 0x569E80u, ctx.xmm[0].u32[0]);
	// 0x27D468: ret
	return;
}

void sub_27D470(X86Context& ctx, uint8_t* base) {
	// 0x27D470: movss xmm0, dword ptr [0x00569E54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E54u);
	// 0x27D478: subss xmm0, [0x00569E80]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569E80u);
	// 0x27D480: movss [0x00569E5C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E5Cu, ctx.xmm[0].u32[0]);
	// 0x27D488: ret
	return;
}

void sub_27D490(X86Context& ctx, uint8_t* base) {
	// 0x27D490: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27D498: movss [0x00569EAC], xmm0
	X86_MEM_WRITE_u32(base, 0x569EACu, ctx.xmm[0].u32[0]);
	// 0x27D4A0: ret
	return;
}

void sub_27D4B0(X86Context& ctx, uint8_t* base) {
	// 0x27D4B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27D4B8: movss [0x00569E58], xmm0
	X86_MEM_WRITE_u32(base, 0x569E58u, ctx.xmm[0].u32[0]);
	// 0x27D4C0: ret
	return;
}

void sub_27D4D0(X86Context& ctx, uint8_t* base) {
	// 0x27D4D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27D4D8: movss [0x00569E6C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E6Cu, ctx.xmm[0].u32[0]);
	// 0x27D4E0: ret
	return;
}

void sub_27D4F0(X86Context& ctx, uint8_t* base) {
	// 0x27D4F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27D4F8: movss [0x00569EC4], xmm0
	X86_MEM_WRITE_u32(base, 0x569EC4u, ctx.xmm[0].u32[0]);
	// 0x27D500: ret
	return;
}

void sub_27D510(X86Context& ctx, uint8_t* base) {
	// 0x27D510: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27D518: movss [0x00569EA8], xmm0
	X86_MEM_WRITE_u32(base, 0x569EA8u, ctx.xmm[0].u32[0]);
	// 0x27D520: ret
	return;
}

void sub_27D530(X86Context& ctx, uint8_t* base) {
	// 0x27D530: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27D538: movss [0x00569E50], xmm0
	X86_MEM_WRITE_u32(base, 0x569E50u, ctx.xmm[0].u32[0]);
	// 0x27D540: ret
	return;
}

void sub_27D550(X86Context& ctx, uint8_t* base) {
	// 0x27D550: movss xmm0, dword ptr [0x00569E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E6Cu);
	// 0x27D558: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27D560: movss [0x00569E44], xmm0
	X86_MEM_WRITE_u32(base, 0x569E44u, ctx.xmm[0].u32[0]);
	// 0x27D568: ret
	return;
}

void sub_27D570(X86Context& ctx, uint8_t* base) {
	// 0x27D570: movss xmm0, dword ptr [0x00569EC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EC4u);
	// 0x27D578: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27D580: movss [0x00569E8C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E8Cu, ctx.xmm[0].u32[0]);
	// 0x27D588: ret
	return;
}

void sub_27D590(X86Context& ctx, uint8_t* base) {
	// 0x27D590: movss xmm0, dword ptr [0x00569E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E44u);
	// 0x27D598: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27D5A0: movss [0x00569EA0], xmm0
	X86_MEM_WRITE_u32(base, 0x569EA0u, ctx.xmm[0].u32[0]);
	// 0x27D5A8: ret
	return;
}

void sub_27D5B0(X86Context& ctx, uint8_t* base) {
	// 0x27D5B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27D5B8: movss [0x00569E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E3Cu, ctx.xmm[0].u32[0]);
	// 0x27D5C0: ret
	return;
}

void sub_27D5D0(X86Context& ctx, uint8_t* base) {
	// 0x27D5D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27D5D8: movss [0x00569E70], xmm0
	X86_MEM_WRITE_u32(base, 0x569E70u, ctx.xmm[0].u32[0]);
	// 0x27D5E0: ret
	return;
}

