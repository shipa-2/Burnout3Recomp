#include "x86_recomp_shared.h"

void sub_289A40(X86Context& ctx, uint8_t* base) {
	// 0x289A40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x289A48: movss [0x0056B688], xmm0
	X86_MEM_WRITE_u32(base, 0x56B688u, ctx.xmm[0].u32[0]);
	// 0x289A50: ret
	return;
}

void sub_289A60(X86Context& ctx, uint8_t* base) {
	// 0x289A60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x289A68: movss [0x0056B6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6DCu, ctx.xmm[0].u32[0]);
	// 0x289A70: ret
	return;
}

void sub_289A80(X86Context& ctx, uint8_t* base) {
	// 0x289A80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x289A88: movss [0x0056B6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6C0u, ctx.xmm[0].u32[0]);
	// 0x289A90: ret
	return;
}

void sub_289AA0(X86Context& ctx, uint8_t* base) {
	// 0x289AA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x289AA8: movss [0x0056B670], xmm0
	X86_MEM_WRITE_u32(base, 0x56B670u, ctx.xmm[0].u32[0]);
	// 0x289AB0: ret
	return;
}

void sub_289AC0(X86Context& ctx, uint8_t* base) {
	// 0x289AC0: movss xmm0, dword ptr [0x0056B688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B688u);
	// 0x289AC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289AD0: movss [0x0056B664], xmm0
	X86_MEM_WRITE_u32(base, 0x56B664u, ctx.xmm[0].u32[0]);
	// 0x289AD8: ret
	return;
}

void sub_289AE0(X86Context& ctx, uint8_t* base) {
	// 0x289AE0: movss xmm0, dword ptr [0x0056B6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6DCu);
	// 0x289AE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x289AF0: movss [0x0056B6A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6A8u, ctx.xmm[0].u32[0]);
	// 0x289AF8: ret
	return;
}

void sub_289B00(X86Context& ctx, uint8_t* base) {
	// 0x289B00: movss xmm0, dword ptr [0x0056B664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B664u);
	// 0x289B08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289B10: movss [0x0056B6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6B8u, ctx.xmm[0].u32[0]);
	// 0x289B18: ret
	return;
}

void sub_289B20(X86Context& ctx, uint8_t* base) {
	// 0x289B20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x289B28: movss [0x0056B65C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B65Cu, ctx.xmm[0].u32[0]);
	// 0x289B30: ret
	return;
}

void sub_289B40(X86Context& ctx, uint8_t* base) {
	// 0x289B40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x289B48: movss [0x0056B68C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B68Cu, ctx.xmm[0].u32[0]);
	// 0x289B50: ret
	return;
}

void sub_289B60(X86Context& ctx, uint8_t* base) {
	// 0x289B60: movss xmm0, dword ptr [0x0056B688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B688u);
	// 0x289B68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x289B70: movss [0x0056B698], xmm0
	X86_MEM_WRITE_u32(base, 0x56B698u, ctx.xmm[0].u32[0]);
	// 0x289B78: ret
	return;
}

void sub_289B80(X86Context& ctx, uint8_t* base) {
	// 0x289B80: movss xmm0, dword ptr [0x0056B6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6DCu);
	// 0x289B88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x289B90: movss [0x0056B6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6E0u, ctx.xmm[0].u32[0]);
	// 0x289B98: ret
	return;
}

void sub_289BA0(X86Context& ctx, uint8_t* base) {
	// 0x289BA0: movss xmm0, dword ptr [0x0056B698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B698u);
	// 0x289BA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289BB0: movss [0x0056B6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6CCu, ctx.xmm[0].u32[0]);
	// 0x289BB8: ret
	return;
}

void sub_289BC0(X86Context& ctx, uint8_t* base) {
	// 0x289BC0: movss xmm0, dword ptr [0x0056B6E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6E0u);
	// 0x289BC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289BD0: movss [0x0056B6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6F0u, ctx.xmm[0].u32[0]);
	// 0x289BD8: ret
	return;
}

void sub_289BE0(X86Context& ctx, uint8_t* base) {
	// 0x289BE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x289BE8: movss [0x0056B668], xmm0
	X86_MEM_WRITE_u32(base, 0x56B668u, ctx.xmm[0].u32[0]);
	// 0x289BF0: ret
	return;
}

void sub_289C00(X86Context& ctx, uint8_t* base) {
	// 0x289C00: movss xmm0, dword ptr [0x0056B688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B688u);
	// 0x289C08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289C10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x289C18: movss [0x0056B6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6D8u, ctx.xmm[0].u32[0]);
	// 0x289C20: ret
	return;
}

void sub_289C30(X86Context& ctx, uint8_t* base) {
	// 0x289C30: movss xmm0, dword ptr [0x0056B6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6DCu);
	// 0x289C38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289C40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x289C48: movss [0x0056B680], xmm0
	X86_MEM_WRITE_u32(base, 0x56B680u, ctx.xmm[0].u32[0]);
	// 0x289C50: ret
	return;
}

void sub_289C60(X86Context& ctx, uint8_t* base) {
	// 0x289C60: movss xmm0, dword ptr [0x0056B688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B688u);
	// 0x289C68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289C70: movss [0x0056B684], xmm0
	X86_MEM_WRITE_u32(base, 0x56B684u, ctx.xmm[0].u32[0]);
	// 0x289C78: ret
	return;
}

void sub_289C80(X86Context& ctx, uint8_t* base) {
	// 0x289C80: movss xmm0, dword ptr [0x0056B6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6DCu);
	// 0x289C88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289C90: movss [0x0056B6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6E4u, ctx.xmm[0].u32[0]);
	// 0x289C98: ret
	return;
}

void sub_289CA0(X86Context& ctx, uint8_t* base) {
	// 0x289CA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x289CA8: movss [0x0056B66C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B66Cu, ctx.xmm[0].u32[0]);
	// 0x289CB0: ret
	return;
}

void sub_289CC0(X86Context& ctx, uint8_t* base) {
	// 0x289CC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x289CC8: movss [0x0056B694], xmm0
	X86_MEM_WRITE_u32(base, 0x56B694u, ctx.xmm[0].u32[0]);
	// 0x289CD0: ret
	return;
}

void sub_289CE0(X86Context& ctx, uint8_t* base) {
	// 0x289CE0: movss xmm0, dword ptr [0x0056B66C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B66Cu);
	// 0x289CE8: movss [0x0056B6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6F8u, ctx.xmm[0].u32[0]);
	// 0x289CF0: ret
	return;
}

void sub_289D00(X86Context& ctx, uint8_t* base) {
	// 0x289D00: movss xmm0, dword ptr [0x0056B6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6DCu);
	// 0x289D08: subss xmm0, [0x0056B66C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B66Cu);
	// 0x289D10: movss [0x0056B6BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6BCu, ctx.xmm[0].u32[0]);
	// 0x289D18: ret
	return;
}

void sub_289D20(X86Context& ctx, uint8_t* base) {
	// 0x289D20: movss xmm0, dword ptr [0x0056B6BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6BCu);
	// 0x289D28: subss xmm0, [0x0056B694]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B694u);
	// 0x289D30: movss [0x0056B6B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6B4u, ctx.xmm[0].u32[0]);
	// 0x289D38: ret
	return;
}

void sub_289D40(X86Context& ctx, uint8_t* base) {
	// 0x289D40: movss xmm0, dword ptr [0x0056B6E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6E4u);
	// 0x289D48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x289D50: movss [0x0056B6A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6A4u, ctx.xmm[0].u32[0]);
	// 0x289D58: ret
	return;
}

void sub_289D60(X86Context& ctx, uint8_t* base) {
	// 0x289D60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x289D68: movss [0x0056B690], xmm0
	X86_MEM_WRITE_u32(base, 0x56B690u, ctx.xmm[0].u32[0]);
	// 0x289D70: ret
	return;
}

void sub_289D80(X86Context& ctx, uint8_t* base) {
	// 0x289D80: movss xmm0, dword ptr [0x0056B6A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6A4u);
	// 0x289D88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x289D90: movss [0x0056B6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6D4u, ctx.xmm[0].u32[0]);
	// 0x289D98: ret
	return;
}

void sub_289DA0(X86Context& ctx, uint8_t* base) {
	// 0x289DA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x289DA8: movss [0x0056B758], xmm0
	X86_MEM_WRITE_u32(base, 0x56B758u, ctx.xmm[0].u32[0]);
	// 0x289DB0: ret
	return;
}

void sub_289DC0(X86Context& ctx, uint8_t* base) {
	// 0x289DC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x289DC8: movss [0x0056B774], xmm0
	X86_MEM_WRITE_u32(base, 0x56B774u, ctx.xmm[0].u32[0]);
	// 0x289DD0: ret
	return;
}

void sub_289DE0(X86Context& ctx, uint8_t* base) {
	// 0x289DE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x289DE8: movss [0x0056B74C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B74Cu, ctx.xmm[0].u32[0]);
	// 0x289DF0: ret
	return;
}

void sub_289E00(X86Context& ctx, uint8_t* base) {
	// 0x289E00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x289E08: movss [0x0056B704], xmm0
	X86_MEM_WRITE_u32(base, 0x56B704u, ctx.xmm[0].u32[0]);
	// 0x289E10: ret
	return;
}

void sub_289E20(X86Context& ctx, uint8_t* base) {
	// 0x289E20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x289E28: movss [0x0056B75C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B75Cu, ctx.xmm[0].u32[0]);
	// 0x289E30: ret
	return;
}

void sub_289E40(X86Context& ctx, uint8_t* base) {
	// 0x289E40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x289E48: movss [0x0056B720], xmm0
	X86_MEM_WRITE_u32(base, 0x56B720u, ctx.xmm[0].u32[0]);
	// 0x289E50: ret
	return;
}

void sub_289E60(X86Context& ctx, uint8_t* base) {
	// 0x289E60: movss xmm0, dword ptr [0x0056B75C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B75Cu);
	// 0x289E68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289E70: movss [0x0056B794], xmm0
	X86_MEM_WRITE_u32(base, 0x56B794u, ctx.xmm[0].u32[0]);
	// 0x289E78: ret
	return;
}

void sub_289E80(X86Context& ctx, uint8_t* base) {
	// 0x289E80: movss xmm0, dword ptr [0x0056B720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B720u);
	// 0x289E88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x289E90: movss [0x0056B77C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B77Cu, ctx.xmm[0].u32[0]);
	// 0x289E98: ret
	return;
}

void sub_289EA0(X86Context& ctx, uint8_t* base) {
	// 0x289EA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x289EA8: movss [0x0056B7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7ACu, ctx.xmm[0].u32[0]);
	// 0x289EB0: ret
	return;
}

void sub_289EC0(X86Context& ctx, uint8_t* base) {
	// 0x289EC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x289EC8: movss [0x0056B798], xmm0
	X86_MEM_WRITE_u32(base, 0x56B798u, ctx.xmm[0].u32[0]);
	// 0x289ED0: ret
	return;
}

void sub_289EE0(X86Context& ctx, uint8_t* base) {
	// 0x289EE0: movss xmm0, dword ptr [0x0056B798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B798u);
	// 0x289EE8: movss [0x0056B7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7A8u, ctx.xmm[0].u32[0]);
	// 0x289EF0: ret
	return;
}

void sub_289F00(X86Context& ctx, uint8_t* base) {
	// 0x289F00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x289F08: movss [0x0056B70C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B70Cu, ctx.xmm[0].u32[0]);
	// 0x289F10: ret
	return;
}

void sub_289F20(X86Context& ctx, uint8_t* base) {
	// 0x289F20: movss xmm0, dword ptr [0x0056B720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B720u);
	// 0x289F28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x289F30: movss [0x0056B7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7A0u, ctx.xmm[0].u32[0]);
	// 0x289F38: ret
	return;
}

void sub_289F40(X86Context& ctx, uint8_t* base) {
	// 0x289F40: movss xmm0, dword ptr [0x0056B720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B720u);
	// 0x289F48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x289F50: movss [0x0056B748], xmm0
	X86_MEM_WRITE_u32(base, 0x56B748u, ctx.xmm[0].u32[0]);
	// 0x289F58: ret
	return;
}

void sub_289F60(X86Context& ctx, uint8_t* base) {
	// 0x289F60: movss xmm0, dword ptr [0x0056B720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B720u);
	// 0x289F68: subss xmm0, [0x0056B748]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B748u);
	// 0x289F70: movss [0x0056B728], xmm0
	X86_MEM_WRITE_u32(base, 0x56B728u, ctx.xmm[0].u32[0]);
	// 0x289F78: ret
	return;
}

void sub_289F80(X86Context& ctx, uint8_t* base) {
	// 0x289F80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x289F88: movss [0x0056B770], xmm0
	X86_MEM_WRITE_u32(base, 0x56B770u, ctx.xmm[0].u32[0]);
	// 0x289F90: ret
	return;
}

void sub_289FA0(X86Context& ctx, uint8_t* base) {
	// 0x289FA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x289FA8: movss [0x0056B724], xmm0
	X86_MEM_WRITE_u32(base, 0x56B724u, ctx.xmm[0].u32[0]);
	// 0x289FB0: ret
	return;
}

void sub_289FC0(X86Context& ctx, uint8_t* base) {
	// 0x289FC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x289FC8: movss [0x0056B734], xmm0
	X86_MEM_WRITE_u32(base, 0x56B734u, ctx.xmm[0].u32[0]);
	// 0x289FD0: ret
	return;
}

void sub_289FE0(X86Context& ctx, uint8_t* base) {
	// 0x289FE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x289FE8: movss [0x0056B788], xmm0
	X86_MEM_WRITE_u32(base, 0x56B788u, ctx.xmm[0].u32[0]);
	// 0x289FF0: ret
	return;
}

void sub_28A000(X86Context& ctx, uint8_t* base) {
	// 0x28A000: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28A008: movss [0x0056B76C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B76Cu, ctx.xmm[0].u32[0]);
	// 0x28A010: ret
	return;
}

void sub_28A020(X86Context& ctx, uint8_t* base) {
	// 0x28A020: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28A028: movss [0x0056B71C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B71Cu, ctx.xmm[0].u32[0]);
	// 0x28A030: ret
	return;
}

void sub_28A040(X86Context& ctx, uint8_t* base) {
	// 0x28A040: movss xmm0, dword ptr [0x0056B734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B734u);
	// 0x28A048: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28A050: movss [0x0056B710], xmm0
	X86_MEM_WRITE_u32(base, 0x56B710u, ctx.xmm[0].u32[0]);
	// 0x28A058: ret
	return;
}

void sub_28A060(X86Context& ctx, uint8_t* base) {
	// 0x28A060: movss xmm0, dword ptr [0x0056B788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B788u);
	// 0x28A068: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28A070: movss [0x0056B754], xmm0
	X86_MEM_WRITE_u32(base, 0x56B754u, ctx.xmm[0].u32[0]);
	// 0x28A078: ret
	return;
}

void sub_28A080(X86Context& ctx, uint8_t* base) {
	// 0x28A080: movss xmm0, dword ptr [0x0056B710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B710u);
	// 0x28A088: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28A090: movss [0x0056B764], xmm0
	X86_MEM_WRITE_u32(base, 0x56B764u, ctx.xmm[0].u32[0]);
	// 0x28A098: ret
	return;
}

void sub_28A0A0(X86Context& ctx, uint8_t* base) {
	// 0x28A0A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28A0A8: movss [0x0056B708], xmm0
	X86_MEM_WRITE_u32(base, 0x56B708u, ctx.xmm[0].u32[0]);
	// 0x28A0B0: ret
	return;
}

void sub_28A0C0(X86Context& ctx, uint8_t* base) {
	// 0x28A0C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28A0C8: movss [0x0056B738], xmm0
	X86_MEM_WRITE_u32(base, 0x56B738u, ctx.xmm[0].u32[0]);
	// 0x28A0D0: ret
	return;
}

void sub_28A0E0(X86Context& ctx, uint8_t* base) {
	// 0x28A0E0: movss xmm0, dword ptr [0x0056B734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B734u);
	// 0x28A0E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28A0F0: movss [0x0056B744], xmm0
	X86_MEM_WRITE_u32(base, 0x56B744u, ctx.xmm[0].u32[0]);
	// 0x28A0F8: ret
	return;
}

void sub_28A100(X86Context& ctx, uint8_t* base) {
	// 0x28A100: movss xmm0, dword ptr [0x0056B788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B788u);
	// 0x28A108: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28A110: movss [0x0056B78C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B78Cu, ctx.xmm[0].u32[0]);
	// 0x28A118: ret
	return;
}

void sub_28A120(X86Context& ctx, uint8_t* base) {
	// 0x28A120: movss xmm0, dword ptr [0x0056B744]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B744u);
	// 0x28A128: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A130: movss [0x0056B778], xmm0
	X86_MEM_WRITE_u32(base, 0x56B778u, ctx.xmm[0].u32[0]);
	// 0x28A138: ret
	return;
}

void sub_28A140(X86Context& ctx, uint8_t* base) {
	// 0x28A140: movss xmm0, dword ptr [0x0056B78C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B78Cu);
	// 0x28A148: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A150: movss [0x0056B79C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B79Cu, ctx.xmm[0].u32[0]);
	// 0x28A158: ret
	return;
}

void sub_28A160(X86Context& ctx, uint8_t* base) {
	// 0x28A160: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28A168: movss [0x0056B714], xmm0
	X86_MEM_WRITE_u32(base, 0x56B714u, ctx.xmm[0].u32[0]);
	// 0x28A170: ret
	return;
}

void sub_28A180(X86Context& ctx, uint8_t* base) {
	// 0x28A180: movss xmm0, dword ptr [0x0056B734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B734u);
	// 0x28A188: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A190: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28A198: movss [0x0056B784], xmm0
	X86_MEM_WRITE_u32(base, 0x56B784u, ctx.xmm[0].u32[0]);
	// 0x28A1A0: ret
	return;
}

void sub_28A1B0(X86Context& ctx, uint8_t* base) {
	// 0x28A1B0: movss xmm0, dword ptr [0x0056B788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B788u);
	// 0x28A1B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A1C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28A1C8: movss [0x0056B72C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B72Cu, ctx.xmm[0].u32[0]);
	// 0x28A1D0: ret
	return;
}

void sub_28A1E0(X86Context& ctx, uint8_t* base) {
	// 0x28A1E0: movss xmm0, dword ptr [0x0056B734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B734u);
	// 0x28A1E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A1F0: movss [0x0056B730], xmm0
	X86_MEM_WRITE_u32(base, 0x56B730u, ctx.xmm[0].u32[0]);
	// 0x28A1F8: ret
	return;
}

void sub_28A200(X86Context& ctx, uint8_t* base) {
	// 0x28A200: movss xmm0, dword ptr [0x0056B788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B788u);
	// 0x28A208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A210: movss [0x0056B790], xmm0
	X86_MEM_WRITE_u32(base, 0x56B790u, ctx.xmm[0].u32[0]);
	// 0x28A218: ret
	return;
}

void sub_28A220(X86Context& ctx, uint8_t* base) {
	// 0x28A220: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28A228: movss [0x0056B718], xmm0
	X86_MEM_WRITE_u32(base, 0x56B718u, ctx.xmm[0].u32[0]);
	// 0x28A230: ret
	return;
}

void sub_28A240(X86Context& ctx, uint8_t* base) {
	// 0x28A240: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28A248: movss [0x0056B740], xmm0
	X86_MEM_WRITE_u32(base, 0x56B740u, ctx.xmm[0].u32[0]);
	// 0x28A250: ret
	return;
}

void sub_28A260(X86Context& ctx, uint8_t* base) {
	// 0x28A260: movss xmm0, dword ptr [0x0056B718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B718u);
	// 0x28A268: movss [0x0056B7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7A4u, ctx.xmm[0].u32[0]);
	// 0x28A270: ret
	return;
}

void sub_28A280(X86Context& ctx, uint8_t* base) {
	// 0x28A280: movss xmm0, dword ptr [0x0056B788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B788u);
	// 0x28A288: subss xmm0, [0x0056B718]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B718u);
	// 0x28A290: movss [0x0056B768], xmm0
	X86_MEM_WRITE_u32(base, 0x56B768u, ctx.xmm[0].u32[0]);
	// 0x28A298: ret
	return;
}

void sub_28A2A0(X86Context& ctx, uint8_t* base) {
	// 0x28A2A0: movss xmm0, dword ptr [0x0056B768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B768u);
	// 0x28A2A8: subss xmm0, [0x0056B740]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B740u);
	// 0x28A2B0: movss [0x0056B760], xmm0
	X86_MEM_WRITE_u32(base, 0x56B760u, ctx.xmm[0].u32[0]);
	// 0x28A2B8: ret
	return;
}

void sub_28A2C0(X86Context& ctx, uint8_t* base) {
	// 0x28A2C0: movss xmm0, dword ptr [0x0056B790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B790u);
	// 0x28A2C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28A2D0: movss [0x0056B750], xmm0
	X86_MEM_WRITE_u32(base, 0x56B750u, ctx.xmm[0].u32[0]);
	// 0x28A2D8: ret
	return;
}

void sub_28A2E0(X86Context& ctx, uint8_t* base) {
	// 0x28A2E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28A2E8: movss [0x0056B73C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B73Cu, ctx.xmm[0].u32[0]);
	// 0x28A2F0: ret
	return;
}

void sub_28A300(X86Context& ctx, uint8_t* base) {
	// 0x28A300: movss xmm0, dword ptr [0x0056B750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B750u);
	// 0x28A308: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28A310: movss [0x0056B780], xmm0
	X86_MEM_WRITE_u32(base, 0x56B780u, ctx.xmm[0].u32[0]);
	// 0x28A318: ret
	return;
}

void sub_28A320(X86Context& ctx, uint8_t* base) {
	// 0x28A320: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28A328: movss [0x0056B804], xmm0
	X86_MEM_WRITE_u32(base, 0x56B804u, ctx.xmm[0].u32[0]);
	// 0x28A330: ret
	return;
}

void sub_28A340(X86Context& ctx, uint8_t* base) {
	// 0x28A340: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28A348: movss [0x0056B820], xmm0
	X86_MEM_WRITE_u32(base, 0x56B820u, ctx.xmm[0].u32[0]);
	// 0x28A350: ret
	return;
}

void sub_28A360(X86Context& ctx, uint8_t* base) {
	// 0x28A360: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28A368: movss [0x0056B7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7F8u, ctx.xmm[0].u32[0]);
	// 0x28A370: ret
	return;
}

void sub_28A380(X86Context& ctx, uint8_t* base) {
	// 0x28A380: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28A388: movss [0x0056B7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7B0u, ctx.xmm[0].u32[0]);
	// 0x28A390: ret
	return;
}

void sub_28A3A0(X86Context& ctx, uint8_t* base) {
	// 0x28A3A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28A3A8: movss [0x0056B808], xmm0
	X86_MEM_WRITE_u32(base, 0x56B808u, ctx.xmm[0].u32[0]);
	// 0x28A3B0: ret
	return;
}

void sub_28A3C0(X86Context& ctx, uint8_t* base) {
	// 0x28A3C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28A3C8: movss [0x0056B7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7CCu, ctx.xmm[0].u32[0]);
	// 0x28A3D0: ret
	return;
}

void sub_28A3E0(X86Context& ctx, uint8_t* base) {
	// 0x28A3E0: movss xmm0, dword ptr [0x0056B808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B808u);
	// 0x28A3E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28A3F0: movss [0x0056B840], xmm0
	X86_MEM_WRITE_u32(base, 0x56B840u, ctx.xmm[0].u32[0]);
	// 0x28A3F8: ret
	return;
}

void sub_28A400(X86Context& ctx, uint8_t* base) {
	// 0x28A400: movss xmm0, dword ptr [0x0056B7CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7CCu);
	// 0x28A408: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28A410: movss [0x0056B828], xmm0
	X86_MEM_WRITE_u32(base, 0x56B828u, ctx.xmm[0].u32[0]);
	// 0x28A418: ret
	return;
}

void sub_28A420(X86Context& ctx, uint8_t* base) {
	// 0x28A420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28A428: movss [0x0056B858], xmm0
	X86_MEM_WRITE_u32(base, 0x56B858u, ctx.xmm[0].u32[0]);
	// 0x28A430: ret
	return;
}

void sub_28A440(X86Context& ctx, uint8_t* base) {
	// 0x28A440: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28A448: movss [0x0056B844], xmm0
	X86_MEM_WRITE_u32(base, 0x56B844u, ctx.xmm[0].u32[0]);
	// 0x28A450: ret
	return;
}

void sub_28A460(X86Context& ctx, uint8_t* base) {
	// 0x28A460: movss xmm0, dword ptr [0x0056B844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B844u);
	// 0x28A468: movss [0x0056B854], xmm0
	X86_MEM_WRITE_u32(base, 0x56B854u, ctx.xmm[0].u32[0]);
	// 0x28A470: ret
	return;
}

void sub_28A480(X86Context& ctx, uint8_t* base) {
	// 0x28A480: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28A488: movss [0x0056B7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7B8u, ctx.xmm[0].u32[0]);
	// 0x28A490: ret
	return;
}

void sub_28A4A0(X86Context& ctx, uint8_t* base) {
	// 0x28A4A0: movss xmm0, dword ptr [0x0056B7CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7CCu);
	// 0x28A4A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28A4B0: movss [0x0056B84C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B84Cu, ctx.xmm[0].u32[0]);
	// 0x28A4B8: ret
	return;
}

void sub_28A4C0(X86Context& ctx, uint8_t* base) {
	// 0x28A4C0: movss xmm0, dword ptr [0x0056B7CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7CCu);
	// 0x28A4C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28A4D0: movss [0x0056B7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7F4u, ctx.xmm[0].u32[0]);
	// 0x28A4D8: ret
	return;
}

void sub_28A4E0(X86Context& ctx, uint8_t* base) {
	// 0x28A4E0: movss xmm0, dword ptr [0x0056B7CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7CCu);
	// 0x28A4E8: subss xmm0, [0x0056B7F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B7F4u);
	// 0x28A4F0: movss [0x0056B7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7D4u, ctx.xmm[0].u32[0]);
	// 0x28A4F8: ret
	return;
}

void sub_28A500(X86Context& ctx, uint8_t* base) {
	// 0x28A500: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28A508: movss [0x0056B81C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B81Cu, ctx.xmm[0].u32[0]);
	// 0x28A510: ret
	return;
}

void sub_28A520(X86Context& ctx, uint8_t* base) {
	// 0x28A520: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28A528: movss [0x0056B7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7D0u, ctx.xmm[0].u32[0]);
	// 0x28A530: ret
	return;
}

void sub_28A540(X86Context& ctx, uint8_t* base) {
	// 0x28A540: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28A548: movss [0x0056B7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7E0u, ctx.xmm[0].u32[0]);
	// 0x28A550: ret
	return;
}

void sub_28A560(X86Context& ctx, uint8_t* base) {
	// 0x28A560: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28A568: movss [0x0056B834], xmm0
	X86_MEM_WRITE_u32(base, 0x56B834u, ctx.xmm[0].u32[0]);
	// 0x28A570: ret
	return;
}

void sub_28A580(X86Context& ctx, uint8_t* base) {
	// 0x28A580: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28A588: movss [0x0056B818], xmm0
	X86_MEM_WRITE_u32(base, 0x56B818u, ctx.xmm[0].u32[0]);
	// 0x28A590: ret
	return;
}

void sub_28A5A0(X86Context& ctx, uint8_t* base) {
	// 0x28A5A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28A5A8: movss [0x0056B7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7C8u, ctx.xmm[0].u32[0]);
	// 0x28A5B0: ret
	return;
}

void sub_28A5C0(X86Context& ctx, uint8_t* base) {
	// 0x28A5C0: movss xmm0, dword ptr [0x0056B7E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7E0u);
	// 0x28A5C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28A5D0: movss [0x0056B7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7BCu, ctx.xmm[0].u32[0]);
	// 0x28A5D8: ret
	return;
}

void sub_28A5E0(X86Context& ctx, uint8_t* base) {
	// 0x28A5E0: movss xmm0, dword ptr [0x0056B834]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B834u);
	// 0x28A5E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28A5F0: movss [0x0056B800], xmm0
	X86_MEM_WRITE_u32(base, 0x56B800u, ctx.xmm[0].u32[0]);
	// 0x28A5F8: ret
	return;
}

void sub_28A600(X86Context& ctx, uint8_t* base) {
	// 0x28A600: movss xmm0, dword ptr [0x0056B7BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7BCu);
	// 0x28A608: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28A610: movss [0x0056B810], xmm0
	X86_MEM_WRITE_u32(base, 0x56B810u, ctx.xmm[0].u32[0]);
	// 0x28A618: ret
	return;
}

void sub_28A620(X86Context& ctx, uint8_t* base) {
	// 0x28A620: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28A628: movss [0x0056B7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7B4u, ctx.xmm[0].u32[0]);
	// 0x28A630: ret
	return;
}

void sub_28A640(X86Context& ctx, uint8_t* base) {
	// 0x28A640: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28A648: movss [0x0056B7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7E4u, ctx.xmm[0].u32[0]);
	// 0x28A650: ret
	return;
}

void sub_28A660(X86Context& ctx, uint8_t* base) {
	// 0x28A660: movss xmm0, dword ptr [0x0056B7E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7E0u);
	// 0x28A668: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28A670: movss [0x0056B7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7F0u, ctx.xmm[0].u32[0]);
	// 0x28A678: ret
	return;
}

void sub_28A680(X86Context& ctx, uint8_t* base) {
	// 0x28A680: movss xmm0, dword ptr [0x0056B834]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B834u);
	// 0x28A688: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28A690: movss [0x0056B838], xmm0
	X86_MEM_WRITE_u32(base, 0x56B838u, ctx.xmm[0].u32[0]);
	// 0x28A698: ret
	return;
}

void sub_28A6A0(X86Context& ctx, uint8_t* base) {
	// 0x28A6A0: movss xmm0, dword ptr [0x0056B7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7F0u);
	// 0x28A6A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A6B0: movss [0x0056B824], xmm0
	X86_MEM_WRITE_u32(base, 0x56B824u, ctx.xmm[0].u32[0]);
	// 0x28A6B8: ret
	return;
}

void sub_28A6C0(X86Context& ctx, uint8_t* base) {
	// 0x28A6C0: movss xmm0, dword ptr [0x0056B838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B838u);
	// 0x28A6C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A6D0: movss [0x0056B848], xmm0
	X86_MEM_WRITE_u32(base, 0x56B848u, ctx.xmm[0].u32[0]);
	// 0x28A6D8: ret
	return;
}

void sub_28A6E0(X86Context& ctx, uint8_t* base) {
	// 0x28A6E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28A6E8: movss [0x0056B7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7C0u, ctx.xmm[0].u32[0]);
	// 0x28A6F0: ret
	return;
}

void sub_28A700(X86Context& ctx, uint8_t* base) {
	// 0x28A700: movss xmm0, dword ptr [0x0056B7E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7E0u);
	// 0x28A708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A710: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28A718: movss [0x0056B830], xmm0
	X86_MEM_WRITE_u32(base, 0x56B830u, ctx.xmm[0].u32[0]);
	// 0x28A720: ret
	return;
}

void sub_28A730(X86Context& ctx, uint8_t* base) {
	// 0x28A730: movss xmm0, dword ptr [0x0056B834]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B834u);
	// 0x28A738: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A740: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28A748: movss [0x0056B7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7D8u, ctx.xmm[0].u32[0]);
	// 0x28A750: ret
	return;
}

void sub_28A760(X86Context& ctx, uint8_t* base) {
	// 0x28A760: movss xmm0, dword ptr [0x0056B7E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7E0u);
	// 0x28A768: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A770: movss [0x0056B7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7DCu, ctx.xmm[0].u32[0]);
	// 0x28A778: ret
	return;
}

void sub_28A780(X86Context& ctx, uint8_t* base) {
	// 0x28A780: movss xmm0, dword ptr [0x0056B834]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B834u);
	// 0x28A788: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28A790: movss [0x0056B83C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B83Cu, ctx.xmm[0].u32[0]);
	// 0x28A798: ret
	return;
}

void sub_28A7A0(X86Context& ctx, uint8_t* base) {
	// 0x28A7A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28A7A8: movss [0x0056B7C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7C4u, ctx.xmm[0].u32[0]);
	// 0x28A7B0: ret
	return;
}

void sub_28A7C0(X86Context& ctx, uint8_t* base) {
	// 0x28A7C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28A7C8: movss [0x0056B7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7ECu, ctx.xmm[0].u32[0]);
	// 0x28A7D0: ret
	return;
}

void sub_28A7E0(X86Context& ctx, uint8_t* base) {
	// 0x28A7E0: movss xmm0, dword ptr [0x0056B7C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7C4u);
	// 0x28A7E8: movss [0x0056B850], xmm0
	X86_MEM_WRITE_u32(base, 0x56B850u, ctx.xmm[0].u32[0]);
	// 0x28A7F0: ret
	return;
}

void sub_28A800(X86Context& ctx, uint8_t* base) {
	// 0x28A800: movss xmm0, dword ptr [0x0056B834]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B834u);
	// 0x28A808: subss xmm0, [0x0056B7C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B7C4u);
	// 0x28A810: movss [0x0056B814], xmm0
	X86_MEM_WRITE_u32(base, 0x56B814u, ctx.xmm[0].u32[0]);
	// 0x28A818: ret
	return;
}

void sub_28A820(X86Context& ctx, uint8_t* base) {
	// 0x28A820: movss xmm0, dword ptr [0x0056B814]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B814u);
	// 0x28A828: subss xmm0, [0x0056B7EC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B7ECu);
	// 0x28A830: movss [0x0056B80C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B80Cu, ctx.xmm[0].u32[0]);
	// 0x28A838: ret
	return;
}

void sub_28A840(X86Context& ctx, uint8_t* base) {
	// 0x28A840: movss xmm0, dword ptr [0x0056B83C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B83Cu);
	// 0x28A848: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28A850: movss [0x0056B7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7FCu, ctx.xmm[0].u32[0]);
	// 0x28A858: ret
	return;
}

void sub_28A860(X86Context& ctx, uint8_t* base) {
	// 0x28A860: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28A868: movss [0x0056B7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B7E8u, ctx.xmm[0].u32[0]);
	// 0x28A870: ret
	return;
}

void sub_28A880(X86Context& ctx, uint8_t* base) {
	// 0x28A880: movss xmm0, dword ptr [0x0056B7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B7FCu);
	// 0x28A888: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28A890: movss [0x0056B82C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B82Cu, ctx.xmm[0].u32[0]);
	// 0x28A898: ret
	return;
}

void sub_28A8A0(X86Context& ctx, uint8_t* base) {
	// 0x28A8A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28A8A8: movss [0x0056B8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8B0u, ctx.xmm[0].u32[0]);
	// 0x28A8B0: ret
	return;
}

void sub_28A8C0(X86Context& ctx, uint8_t* base) {
	// 0x28A8C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28A8C8: movss [0x0056B8CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8CCu, ctx.xmm[0].u32[0]);
	// 0x28A8D0: ret
	return;
}

void sub_28A8E0(X86Context& ctx, uint8_t* base) {
	// 0x28A8E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28A8E8: movss [0x0056B8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8A4u, ctx.xmm[0].u32[0]);
	// 0x28A8F0: ret
	return;
}

void sub_28A900(X86Context& ctx, uint8_t* base) {
	// 0x28A900: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28A908: movss [0x0056B85C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B85Cu, ctx.xmm[0].u32[0]);
	// 0x28A910: ret
	return;
}

void sub_28A920(X86Context& ctx, uint8_t* base) {
	// 0x28A920: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28A928: movss [0x0056B8B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8B4u, ctx.xmm[0].u32[0]);
	// 0x28A930: ret
	return;
}

void sub_28A940(X86Context& ctx, uint8_t* base) {
	// 0x28A940: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28A948: movss [0x0056B878], xmm0
	X86_MEM_WRITE_u32(base, 0x56B878u, ctx.xmm[0].u32[0]);
	// 0x28A950: ret
	return;
}

void sub_28A960(X86Context& ctx, uint8_t* base) {
	// 0x28A960: movss xmm0, dword ptr [0x0056B8B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8B4u);
	// 0x28A968: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28A970: movss [0x0056B8EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8ECu, ctx.xmm[0].u32[0]);
	// 0x28A978: ret
	return;
}

void sub_28A980(X86Context& ctx, uint8_t* base) {
	// 0x28A980: movss xmm0, dword ptr [0x0056B878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B878u);
	// 0x28A988: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28A990: movss [0x0056B8D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8D4u, ctx.xmm[0].u32[0]);
	// 0x28A998: ret
	return;
}

void sub_28A9A0(X86Context& ctx, uint8_t* base) {
	// 0x28A9A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28A9A8: movss [0x0056B904], xmm0
	X86_MEM_WRITE_u32(base, 0x56B904u, ctx.xmm[0].u32[0]);
	// 0x28A9B0: ret
	return;
}

void sub_28A9C0(X86Context& ctx, uint8_t* base) {
	// 0x28A9C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28A9C8: movss [0x0056B8F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8F0u, ctx.xmm[0].u32[0]);
	// 0x28A9D0: ret
	return;
}

void sub_28A9E0(X86Context& ctx, uint8_t* base) {
	// 0x28A9E0: movss xmm0, dword ptr [0x0056B8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8F0u);
	// 0x28A9E8: movss [0x0056B900], xmm0
	X86_MEM_WRITE_u32(base, 0x56B900u, ctx.xmm[0].u32[0]);
	// 0x28A9F0: ret
	return;
}

void sub_28AA00(X86Context& ctx, uint8_t* base) {
	// 0x28AA00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28AA08: movss [0x0056B864], xmm0
	X86_MEM_WRITE_u32(base, 0x56B864u, ctx.xmm[0].u32[0]);
	// 0x28AA10: ret
	return;
}

void sub_28AA20(X86Context& ctx, uint8_t* base) {
	// 0x28AA20: movss xmm0, dword ptr [0x0056B878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B878u);
	// 0x28AA28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28AA30: movss [0x0056B8F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8F8u, ctx.xmm[0].u32[0]);
	// 0x28AA38: ret
	return;
}

void sub_28AA40(X86Context& ctx, uint8_t* base) {
	// 0x28AA40: movss xmm0, dword ptr [0x0056B878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B878u);
	// 0x28AA48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28AA50: movss [0x0056B8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8A0u, ctx.xmm[0].u32[0]);
	// 0x28AA58: ret
	return;
}

void sub_28AA60(X86Context& ctx, uint8_t* base) {
	// 0x28AA60: movss xmm0, dword ptr [0x0056B878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B878u);
	// 0x28AA68: subss xmm0, [0x0056B8A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B8A0u);
	// 0x28AA70: movss [0x0056B880], xmm0
	X86_MEM_WRITE_u32(base, 0x56B880u, ctx.xmm[0].u32[0]);
	// 0x28AA78: ret
	return;
}

void sub_28AA80(X86Context& ctx, uint8_t* base) {
	// 0x28AA80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28AA88: movss [0x0056B8C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8C8u, ctx.xmm[0].u32[0]);
	// 0x28AA90: ret
	return;
}

void sub_28AAA0(X86Context& ctx, uint8_t* base) {
	// 0x28AAA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28AAA8: movss [0x0056B87C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B87Cu, ctx.xmm[0].u32[0]);
	// 0x28AAB0: ret
	return;
}

void sub_28AAC0(X86Context& ctx, uint8_t* base) {
	// 0x28AAC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28AAC8: movss [0x0056B88C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B88Cu, ctx.xmm[0].u32[0]);
	// 0x28AAD0: ret
	return;
}

void sub_28AAE0(X86Context& ctx, uint8_t* base) {
	// 0x28AAE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28AAE8: movss [0x0056B8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8E0u, ctx.xmm[0].u32[0]);
	// 0x28AAF0: ret
	return;
}

void sub_28AB00(X86Context& ctx, uint8_t* base) {
	// 0x28AB00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28AB08: movss [0x0056B8C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8C4u, ctx.xmm[0].u32[0]);
	// 0x28AB10: ret
	return;
}

void sub_28AB20(X86Context& ctx, uint8_t* base) {
	// 0x28AB20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28AB28: movss [0x0056B874], xmm0
	X86_MEM_WRITE_u32(base, 0x56B874u, ctx.xmm[0].u32[0]);
	// 0x28AB30: ret
	return;
}

void sub_28AB40(X86Context& ctx, uint8_t* base) {
	// 0x28AB40: movss xmm0, dword ptr [0x0056B88C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B88Cu);
	// 0x28AB48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28AB50: movss [0x0056B868], xmm0
	X86_MEM_WRITE_u32(base, 0x56B868u, ctx.xmm[0].u32[0]);
	// 0x28AB58: ret
	return;
}

void sub_28AB60(X86Context& ctx, uint8_t* base) {
	// 0x28AB60: movss xmm0, dword ptr [0x0056B8E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E0u);
	// 0x28AB68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28AB70: movss [0x0056B8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8ACu, ctx.xmm[0].u32[0]);
	// 0x28AB78: ret
	return;
}

void sub_28AB80(X86Context& ctx, uint8_t* base) {
	// 0x28AB80: movss xmm0, dword ptr [0x0056B868]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B868u);
	// 0x28AB88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28AB90: movss [0x0056B8BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8BCu, ctx.xmm[0].u32[0]);
	// 0x28AB98: ret
	return;
}

void sub_28ABA0(X86Context& ctx, uint8_t* base) {
	// 0x28ABA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28ABA8: movss [0x0056B860], xmm0
	X86_MEM_WRITE_u32(base, 0x56B860u, ctx.xmm[0].u32[0]);
	// 0x28ABB0: ret
	return;
}

void sub_28ABC0(X86Context& ctx, uint8_t* base) {
	// 0x28ABC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28ABC8: movss [0x0056B890], xmm0
	X86_MEM_WRITE_u32(base, 0x56B890u, ctx.xmm[0].u32[0]);
	// 0x28ABD0: ret
	return;
}

void sub_28ABE0(X86Context& ctx, uint8_t* base) {
	// 0x28ABE0: movss xmm0, dword ptr [0x0056B88C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B88Cu);
	// 0x28ABE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28ABF0: movss [0x0056B89C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B89Cu, ctx.xmm[0].u32[0]);
	// 0x28ABF8: ret
	return;
}

void sub_28AC00(X86Context& ctx, uint8_t* base) {
	// 0x28AC00: movss xmm0, dword ptr [0x0056B8E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E0u);
	// 0x28AC08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28AC10: movss [0x0056B8E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8E4u, ctx.xmm[0].u32[0]);
	// 0x28AC18: ret
	return;
}

void sub_28AC20(X86Context& ctx, uint8_t* base) {
	// 0x28AC20: movss xmm0, dword ptr [0x0056B89C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B89Cu);
	// 0x28AC28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28AC30: movss [0x0056B8D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8D0u, ctx.xmm[0].u32[0]);
	// 0x28AC38: ret
	return;
}

void sub_28AC40(X86Context& ctx, uint8_t* base) {
	// 0x28AC40: movss xmm0, dword ptr [0x0056B8E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E4u);
	// 0x28AC48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28AC50: movss [0x0056B8F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8F4u, ctx.xmm[0].u32[0]);
	// 0x28AC58: ret
	return;
}

void sub_28AC60(X86Context& ctx, uint8_t* base) {
	// 0x28AC60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28AC68: movss [0x0056B86C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B86Cu, ctx.xmm[0].u32[0]);
	// 0x28AC70: ret
	return;
}

void sub_28AC80(X86Context& ctx, uint8_t* base) {
	// 0x28AC80: movss xmm0, dword ptr [0x0056B88C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B88Cu);
	// 0x28AC88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28AC90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28AC98: movss [0x0056B8DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8DCu, ctx.xmm[0].u32[0]);
	// 0x28ACA0: ret
	return;
}

void sub_28ACB0(X86Context& ctx, uint8_t* base) {
	// 0x28ACB0: movss xmm0, dword ptr [0x0056B8E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E0u);
	// 0x28ACB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28ACC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28ACC8: movss [0x0056B884], xmm0
	X86_MEM_WRITE_u32(base, 0x56B884u, ctx.xmm[0].u32[0]);
	// 0x28ACD0: ret
	return;
}

void sub_28ACE0(X86Context& ctx, uint8_t* base) {
	// 0x28ACE0: movss xmm0, dword ptr [0x0056B88C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B88Cu);
	// 0x28ACE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28ACF0: movss [0x0056B888], xmm0
	X86_MEM_WRITE_u32(base, 0x56B888u, ctx.xmm[0].u32[0]);
	// 0x28ACF8: ret
	return;
}

void sub_28AD00(X86Context& ctx, uint8_t* base) {
	// 0x28AD00: movss xmm0, dword ptr [0x0056B8E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E0u);
	// 0x28AD08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28AD10: movss [0x0056B8E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8E8u, ctx.xmm[0].u32[0]);
	// 0x28AD18: ret
	return;
}

void sub_28AD20(X86Context& ctx, uint8_t* base) {
	// 0x28AD20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28AD28: movss [0x0056B870], xmm0
	X86_MEM_WRITE_u32(base, 0x56B870u, ctx.xmm[0].u32[0]);
	// 0x28AD30: ret
	return;
}

void sub_28AD40(X86Context& ctx, uint8_t* base) {
	// 0x28AD40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28AD48: movss [0x0056B898], xmm0
	X86_MEM_WRITE_u32(base, 0x56B898u, ctx.xmm[0].u32[0]);
	// 0x28AD50: ret
	return;
}

void sub_28AD60(X86Context& ctx, uint8_t* base) {
	// 0x28AD60: movss xmm0, dword ptr [0x0056B870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B870u);
	// 0x28AD68: movss [0x0056B8FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8FCu, ctx.xmm[0].u32[0]);
	// 0x28AD70: ret
	return;
}

void sub_28AD80(X86Context& ctx, uint8_t* base) {
	// 0x28AD80: movss xmm0, dword ptr [0x0056B8E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E0u);
	// 0x28AD88: subss xmm0, [0x0056B870]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B870u);
	// 0x28AD90: movss [0x0056B8C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8C0u, ctx.xmm[0].u32[0]);
	// 0x28AD98: ret
	return;
}

void sub_28ADA0(X86Context& ctx, uint8_t* base) {
	// 0x28ADA0: movss xmm0, dword ptr [0x0056B8C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8C0u);
	// 0x28ADA8: subss xmm0, [0x0056B898]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B898u);
	// 0x28ADB0: movss [0x0056B8B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8B8u, ctx.xmm[0].u32[0]);
	// 0x28ADB8: ret
	return;
}

void sub_28ADC0(X86Context& ctx, uint8_t* base) {
	// 0x28ADC0: movss xmm0, dword ptr [0x0056B8E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8E8u);
	// 0x28ADC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28ADD0: movss [0x0056B8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8A8u, ctx.xmm[0].u32[0]);
	// 0x28ADD8: ret
	return;
}

void sub_28ADE0(X86Context& ctx, uint8_t* base) {
	// 0x28ADE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28ADE8: movss [0x0056B894], xmm0
	X86_MEM_WRITE_u32(base, 0x56B894u, ctx.xmm[0].u32[0]);
	// 0x28ADF0: ret
	return;
}

void sub_28AE00(X86Context& ctx, uint8_t* base) {
	// 0x28AE00: movss xmm0, dword ptr [0x0056B8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B8A8u);
	// 0x28AE08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28AE10: movss [0x0056B8D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B8D8u, ctx.xmm[0].u32[0]);
	// 0x28AE18: ret
	return;
}

void sub_28AE20(X86Context& ctx, uint8_t* base) {
	// 0x28AE20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28AE28: movss [0x0056B95C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B95Cu, ctx.xmm[0].u32[0]);
	// 0x28AE30: ret
	return;
}

void sub_28AE40(X86Context& ctx, uint8_t* base) {
	// 0x28AE40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28AE48: movss [0x0056B978], xmm0
	X86_MEM_WRITE_u32(base, 0x56B978u, ctx.xmm[0].u32[0]);
	// 0x28AE50: ret
	return;
}

void sub_28AE60(X86Context& ctx, uint8_t* base) {
	// 0x28AE60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28AE68: movss [0x0056B950], xmm0
	X86_MEM_WRITE_u32(base, 0x56B950u, ctx.xmm[0].u32[0]);
	// 0x28AE70: ret
	return;
}

void sub_28AE80(X86Context& ctx, uint8_t* base) {
	// 0x28AE80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28AE88: movss [0x0056B908], xmm0
	X86_MEM_WRITE_u32(base, 0x56B908u, ctx.xmm[0].u32[0]);
	// 0x28AE90: ret
	return;
}

void sub_28AEA0(X86Context& ctx, uint8_t* base) {
	// 0x28AEA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28AEA8: movss [0x0056B960], xmm0
	X86_MEM_WRITE_u32(base, 0x56B960u, ctx.xmm[0].u32[0]);
	// 0x28AEB0: ret
	return;
}

void sub_28AEC0(X86Context& ctx, uint8_t* base) {
	// 0x28AEC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28AEC8: movss [0x0056B924], xmm0
	X86_MEM_WRITE_u32(base, 0x56B924u, ctx.xmm[0].u32[0]);
	// 0x28AED0: ret
	return;
}

void sub_28AEE0(X86Context& ctx, uint8_t* base) {
	// 0x28AEE0: movss xmm0, dword ptr [0x0056B960]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B960u);
	// 0x28AEE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28AEF0: movss [0x0056B998], xmm0
	X86_MEM_WRITE_u32(base, 0x56B998u, ctx.xmm[0].u32[0]);
	// 0x28AEF8: ret
	return;
}

void sub_28AF00(X86Context& ctx, uint8_t* base) {
	// 0x28AF00: movss xmm0, dword ptr [0x0056B924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B924u);
	// 0x28AF08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28AF10: movss [0x0056B980], xmm0
	X86_MEM_WRITE_u32(base, 0x56B980u, ctx.xmm[0].u32[0]);
	// 0x28AF18: ret
	return;
}

void sub_28AF20(X86Context& ctx, uint8_t* base) {
	// 0x28AF20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28AF28: movss [0x0056B9B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9B0u, ctx.xmm[0].u32[0]);
	// 0x28AF30: ret
	return;
}

void sub_28AF40(X86Context& ctx, uint8_t* base) {
	// 0x28AF40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28AF48: movss [0x0056B99C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B99Cu, ctx.xmm[0].u32[0]);
	// 0x28AF50: ret
	return;
}

void sub_28AF60(X86Context& ctx, uint8_t* base) {
	// 0x28AF60: movss xmm0, dword ptr [0x0056B99C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B99Cu);
	// 0x28AF68: movss [0x0056B9AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9ACu, ctx.xmm[0].u32[0]);
	// 0x28AF70: ret
	return;
}

void sub_28AF80(X86Context& ctx, uint8_t* base) {
	// 0x28AF80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28AF88: movss [0x0056B910], xmm0
	X86_MEM_WRITE_u32(base, 0x56B910u, ctx.xmm[0].u32[0]);
	// 0x28AF90: ret
	return;
}

void sub_28AFA0(X86Context& ctx, uint8_t* base) {
	// 0x28AFA0: movss xmm0, dword ptr [0x0056B924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B924u);
	// 0x28AFA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28AFB0: movss [0x0056B9A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9A4u, ctx.xmm[0].u32[0]);
	// 0x28AFB8: ret
	return;
}

void sub_28AFC0(X86Context& ctx, uint8_t* base) {
	// 0x28AFC0: movss xmm0, dword ptr [0x0056B924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B924u);
	// 0x28AFC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28AFD0: movss [0x0056B94C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B94Cu, ctx.xmm[0].u32[0]);
	// 0x28AFD8: ret
	return;
}

void sub_28AFE0(X86Context& ctx, uint8_t* base) {
	// 0x28AFE0: movss xmm0, dword ptr [0x0056B924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B924u);
	// 0x28AFE8: subss xmm0, [0x0056B94C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B94Cu);
	// 0x28AFF0: movss [0x0056B92C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B92Cu, ctx.xmm[0].u32[0]);
	// 0x28AFF8: ret
	return;
}

void sub_28B000(X86Context& ctx, uint8_t* base) {
	// 0x28B000: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28B008: movss [0x0056B974], xmm0
	X86_MEM_WRITE_u32(base, 0x56B974u, ctx.xmm[0].u32[0]);
	// 0x28B010: ret
	return;
}

void sub_28B020(X86Context& ctx, uint8_t* base) {
	// 0x28B020: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28B028: movss [0x0056B928], xmm0
	X86_MEM_WRITE_u32(base, 0x56B928u, ctx.xmm[0].u32[0]);
	// 0x28B030: ret
	return;
}

void sub_28B040(X86Context& ctx, uint8_t* base) {
	// 0x28B040: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28B048: movss [0x0056B938], xmm0
	X86_MEM_WRITE_u32(base, 0x56B938u, ctx.xmm[0].u32[0]);
	// 0x28B050: ret
	return;
}

void sub_28B060(X86Context& ctx, uint8_t* base) {
	// 0x28B060: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28B068: movss [0x0056B98C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B98Cu, ctx.xmm[0].u32[0]);
	// 0x28B070: ret
	return;
}

void sub_28B080(X86Context& ctx, uint8_t* base) {
	// 0x28B080: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28B088: movss [0x0056B970], xmm0
	X86_MEM_WRITE_u32(base, 0x56B970u, ctx.xmm[0].u32[0]);
	// 0x28B090: ret
	return;
}

void sub_28B0A0(X86Context& ctx, uint8_t* base) {
	// 0x28B0A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28B0A8: movss [0x0056B920], xmm0
	X86_MEM_WRITE_u32(base, 0x56B920u, ctx.xmm[0].u32[0]);
	// 0x28B0B0: ret
	return;
}

void sub_28B0C0(X86Context& ctx, uint8_t* base) {
	// 0x28B0C0: movss xmm0, dword ptr [0x0056B938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B938u);
	// 0x28B0C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28B0D0: movss [0x0056B914], xmm0
	X86_MEM_WRITE_u32(base, 0x56B914u, ctx.xmm[0].u32[0]);
	// 0x28B0D8: ret
	return;
}

void sub_28B0E0(X86Context& ctx, uint8_t* base) {
	// 0x28B0E0: movss xmm0, dword ptr [0x0056B98C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B98Cu);
	// 0x28B0E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28B0F0: movss [0x0056B958], xmm0
	X86_MEM_WRITE_u32(base, 0x56B958u, ctx.xmm[0].u32[0]);
	// 0x28B0F8: ret
	return;
}

void sub_28B100(X86Context& ctx, uint8_t* base) {
	// 0x28B100: movss xmm0, dword ptr [0x0056B914]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B914u);
	// 0x28B108: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28B110: movss [0x0056B968], xmm0
	X86_MEM_WRITE_u32(base, 0x56B968u, ctx.xmm[0].u32[0]);
	// 0x28B118: ret
	return;
}

void sub_28B120(X86Context& ctx, uint8_t* base) {
	// 0x28B120: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28B128: movss [0x0056B90C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B90Cu, ctx.xmm[0].u32[0]);
	// 0x28B130: ret
	return;
}

void sub_28B140(X86Context& ctx, uint8_t* base) {
	// 0x28B140: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28B148: movss [0x0056B93C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B93Cu, ctx.xmm[0].u32[0]);
	// 0x28B150: ret
	return;
}

void sub_28B160(X86Context& ctx, uint8_t* base) {
	// 0x28B160: movss xmm0, dword ptr [0x0056B938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B938u);
	// 0x28B168: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28B170: movss [0x0056B948], xmm0
	X86_MEM_WRITE_u32(base, 0x56B948u, ctx.xmm[0].u32[0]);
	// 0x28B178: ret
	return;
}

void sub_28B180(X86Context& ctx, uint8_t* base) {
	// 0x28B180: movss xmm0, dword ptr [0x0056B98C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B98Cu);
	// 0x28B188: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28B190: movss [0x0056B990], xmm0
	X86_MEM_WRITE_u32(base, 0x56B990u, ctx.xmm[0].u32[0]);
	// 0x28B198: ret
	return;
}

void sub_28B1A0(X86Context& ctx, uint8_t* base) {
	// 0x28B1A0: movss xmm0, dword ptr [0x0056B948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B948u);
	// 0x28B1A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B1B0: movss [0x0056B97C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B97Cu, ctx.xmm[0].u32[0]);
	// 0x28B1B8: ret
	return;
}

void sub_28B1C0(X86Context& ctx, uint8_t* base) {
	// 0x28B1C0: movss xmm0, dword ptr [0x0056B990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B990u);
	// 0x28B1C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B1D0: movss [0x0056B9A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9A0u, ctx.xmm[0].u32[0]);
	// 0x28B1D8: ret
	return;
}

void sub_28B1E0(X86Context& ctx, uint8_t* base) {
	// 0x28B1E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28B1E8: movss [0x0056B918], xmm0
	X86_MEM_WRITE_u32(base, 0x56B918u, ctx.xmm[0].u32[0]);
	// 0x28B1F0: ret
	return;
}

void sub_28B200(X86Context& ctx, uint8_t* base) {
	// 0x28B200: movss xmm0, dword ptr [0x0056B938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B938u);
	// 0x28B208: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B210: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28B218: movss [0x0056B988], xmm0
	X86_MEM_WRITE_u32(base, 0x56B988u, ctx.xmm[0].u32[0]);
	// 0x28B220: ret
	return;
}

void sub_28B230(X86Context& ctx, uint8_t* base) {
	// 0x28B230: movss xmm0, dword ptr [0x0056B98C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B98Cu);
	// 0x28B238: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B240: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28B248: movss [0x0056B930], xmm0
	X86_MEM_WRITE_u32(base, 0x56B930u, ctx.xmm[0].u32[0]);
	// 0x28B250: ret
	return;
}

void sub_28B260(X86Context& ctx, uint8_t* base) {
	// 0x28B260: movss xmm0, dword ptr [0x0056B938]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B938u);
	// 0x28B268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B270: movss [0x0056B934], xmm0
	X86_MEM_WRITE_u32(base, 0x56B934u, ctx.xmm[0].u32[0]);
	// 0x28B278: ret
	return;
}

void sub_28B280(X86Context& ctx, uint8_t* base) {
	// 0x28B280: movss xmm0, dword ptr [0x0056B98C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B98Cu);
	// 0x28B288: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B290: movss [0x0056B994], xmm0
	X86_MEM_WRITE_u32(base, 0x56B994u, ctx.xmm[0].u32[0]);
	// 0x28B298: ret
	return;
}

void sub_28B2A0(X86Context& ctx, uint8_t* base) {
	// 0x28B2A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28B2A8: movss [0x0056B91C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B91Cu, ctx.xmm[0].u32[0]);
	// 0x28B2B0: ret
	return;
}

void sub_28B2C0(X86Context& ctx, uint8_t* base) {
	// 0x28B2C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28B2C8: movss [0x0056B944], xmm0
	X86_MEM_WRITE_u32(base, 0x56B944u, ctx.xmm[0].u32[0]);
	// 0x28B2D0: ret
	return;
}

void sub_28B2E0(X86Context& ctx, uint8_t* base) {
	// 0x28B2E0: movss xmm0, dword ptr [0x0056B91C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B91Cu);
	// 0x28B2E8: movss [0x0056B9A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9A8u, ctx.xmm[0].u32[0]);
	// 0x28B2F0: ret
	return;
}

void sub_28B300(X86Context& ctx, uint8_t* base) {
	// 0x28B300: movss xmm0, dword ptr [0x0056B98C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B98Cu);
	// 0x28B308: subss xmm0, [0x0056B91C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B91Cu);
	// 0x28B310: movss [0x0056B96C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B96Cu, ctx.xmm[0].u32[0]);
	// 0x28B318: ret
	return;
}

void sub_28B320(X86Context& ctx, uint8_t* base) {
	// 0x28B320: movss xmm0, dword ptr [0x0056B96C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B96Cu);
	// 0x28B328: subss xmm0, [0x0056B944]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B944u);
	// 0x28B330: movss [0x0056B964], xmm0
	X86_MEM_WRITE_u32(base, 0x56B964u, ctx.xmm[0].u32[0]);
	// 0x28B338: ret
	return;
}

void sub_28B340(X86Context& ctx, uint8_t* base) {
	// 0x28B340: movss xmm0, dword ptr [0x0056B994]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B994u);
	// 0x28B348: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28B350: movss [0x0056B954], xmm0
	X86_MEM_WRITE_u32(base, 0x56B954u, ctx.xmm[0].u32[0]);
	// 0x28B358: ret
	return;
}

void sub_28B360(X86Context& ctx, uint8_t* base) {
	// 0x28B360: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28B368: movss [0x0056B940], xmm0
	X86_MEM_WRITE_u32(base, 0x56B940u, ctx.xmm[0].u32[0]);
	// 0x28B370: ret
	return;
}

void sub_28B380(X86Context& ctx, uint8_t* base) {
	// 0x28B380: movss xmm0, dword ptr [0x0056B954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B954u);
	// 0x28B388: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28B390: movss [0x0056B984], xmm0
	X86_MEM_WRITE_u32(base, 0x56B984u, ctx.xmm[0].u32[0]);
	// 0x28B398: ret
	return;
}

void sub_28B3A0(X86Context& ctx, uint8_t* base) {
	// 0x28B3A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28B3A8: movss [0x0056BA08], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA08u, ctx.xmm[0].u32[0]);
	// 0x28B3B0: ret
	return;
}

void sub_28B3C0(X86Context& ctx, uint8_t* base) {
	// 0x28B3C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28B3C8: movss [0x0056BA24], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA24u, ctx.xmm[0].u32[0]);
	// 0x28B3D0: ret
	return;
}

void sub_28B3E0(X86Context& ctx, uint8_t* base) {
	// 0x28B3E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28B3E8: movss [0x0056B9FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9FCu, ctx.xmm[0].u32[0]);
	// 0x28B3F0: ret
	return;
}

void sub_28B400(X86Context& ctx, uint8_t* base) {
	// 0x28B400: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28B408: movss [0x0056B9B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9B4u, ctx.xmm[0].u32[0]);
	// 0x28B410: ret
	return;
}

void sub_28B420(X86Context& ctx, uint8_t* base) {
	// 0x28B420: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28B428: movss [0x0056BA0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA0Cu, ctx.xmm[0].u32[0]);
	// 0x28B430: ret
	return;
}

void sub_28B440(X86Context& ctx, uint8_t* base) {
	// 0x28B440: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28B448: movss [0x0056B9D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9D0u, ctx.xmm[0].u32[0]);
	// 0x28B450: ret
	return;
}

void sub_28B460(X86Context& ctx, uint8_t* base) {
	// 0x28B460: movss xmm0, dword ptr [0x0056BA0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA0Cu);
	// 0x28B468: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28B470: movss [0x0056BA44], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA44u, ctx.xmm[0].u32[0]);
	// 0x28B478: ret
	return;
}

void sub_28B480(X86Context& ctx, uint8_t* base) {
	// 0x28B480: movss xmm0, dword ptr [0x0056B9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9D0u);
	// 0x28B488: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28B490: movss [0x0056BA2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA2Cu, ctx.xmm[0].u32[0]);
	// 0x28B498: ret
	return;
}

void sub_28B4A0(X86Context& ctx, uint8_t* base) {
	// 0x28B4A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28B4A8: movss [0x0056BA5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA5Cu, ctx.xmm[0].u32[0]);
	// 0x28B4B0: ret
	return;
}

void sub_28B4C0(X86Context& ctx, uint8_t* base) {
	// 0x28B4C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28B4C8: movss [0x0056BA48], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA48u, ctx.xmm[0].u32[0]);
	// 0x28B4D0: ret
	return;
}

void sub_28B4E0(X86Context& ctx, uint8_t* base) {
	// 0x28B4E0: movss xmm0, dword ptr [0x0056BA48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA48u);
	// 0x28B4E8: movss [0x0056BA58], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA58u, ctx.xmm[0].u32[0]);
	// 0x28B4F0: ret
	return;
}

void sub_28B500(X86Context& ctx, uint8_t* base) {
	// 0x28B500: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28B508: movss [0x0056B9BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9BCu, ctx.xmm[0].u32[0]);
	// 0x28B510: ret
	return;
}

void sub_28B520(X86Context& ctx, uint8_t* base) {
	// 0x28B520: movss xmm0, dword ptr [0x0056B9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9D0u);
	// 0x28B528: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28B530: movss [0x0056BA50], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA50u, ctx.xmm[0].u32[0]);
	// 0x28B538: ret
	return;
}

void sub_28B540(X86Context& ctx, uint8_t* base) {
	// 0x28B540: movss xmm0, dword ptr [0x0056B9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9D0u);
	// 0x28B548: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28B550: movss [0x0056B9F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9F8u, ctx.xmm[0].u32[0]);
	// 0x28B558: ret
	return;
}

void sub_28B560(X86Context& ctx, uint8_t* base) {
	// 0x28B560: movss xmm0, dword ptr [0x0056B9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9D0u);
	// 0x28B568: subss xmm0, [0x0056B9F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B9F8u);
	// 0x28B570: movss [0x0056B9D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9D8u, ctx.xmm[0].u32[0]);
	// 0x28B578: ret
	return;
}

void sub_28B580(X86Context& ctx, uint8_t* base) {
	// 0x28B580: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28B588: movss [0x0056BA20], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA20u, ctx.xmm[0].u32[0]);
	// 0x28B590: ret
	return;
}

void sub_28B5A0(X86Context& ctx, uint8_t* base) {
	// 0x28B5A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28B5A8: movss [0x0056B9D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9D4u, ctx.xmm[0].u32[0]);
	// 0x28B5B0: ret
	return;
}

void sub_28B5C0(X86Context& ctx, uint8_t* base) {
	// 0x28B5C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28B5C8: movss [0x0056B9E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9E4u, ctx.xmm[0].u32[0]);
	// 0x28B5D0: ret
	return;
}

void sub_28B5E0(X86Context& ctx, uint8_t* base) {
	// 0x28B5E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28B5E8: movss [0x0056BA38], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA38u, ctx.xmm[0].u32[0]);
	// 0x28B5F0: ret
	return;
}

void sub_28B600(X86Context& ctx, uint8_t* base) {
	// 0x28B600: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28B608: movss [0x0056BA1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA1Cu, ctx.xmm[0].u32[0]);
	// 0x28B610: ret
	return;
}

void sub_28B620(X86Context& ctx, uint8_t* base) {
	// 0x28B620: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28B628: movss [0x0056B9CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9CCu, ctx.xmm[0].u32[0]);
	// 0x28B630: ret
	return;
}

void sub_28B640(X86Context& ctx, uint8_t* base) {
	// 0x28B640: movss xmm0, dword ptr [0x0056B9E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9E4u);
	// 0x28B648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28B650: movss [0x0056B9C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9C0u, ctx.xmm[0].u32[0]);
	// 0x28B658: ret
	return;
}

void sub_28B660(X86Context& ctx, uint8_t* base) {
	// 0x28B660: movss xmm0, dword ptr [0x0056BA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA38u);
	// 0x28B668: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28B670: movss [0x0056BA04], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA04u, ctx.xmm[0].u32[0]);
	// 0x28B678: ret
	return;
}

void sub_28B680(X86Context& ctx, uint8_t* base) {
	// 0x28B680: movss xmm0, dword ptr [0x0056B9C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9C0u);
	// 0x28B688: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28B690: movss [0x0056BA14], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA14u, ctx.xmm[0].u32[0]);
	// 0x28B698: ret
	return;
}

void sub_28B6A0(X86Context& ctx, uint8_t* base) {
	// 0x28B6A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28B6A8: movss [0x0056B9B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9B8u, ctx.xmm[0].u32[0]);
	// 0x28B6B0: ret
	return;
}

void sub_28B6C0(X86Context& ctx, uint8_t* base) {
	// 0x28B6C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28B6C8: movss [0x0056B9E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9E8u, ctx.xmm[0].u32[0]);
	// 0x28B6D0: ret
	return;
}

void sub_28B6E0(X86Context& ctx, uint8_t* base) {
	// 0x28B6E0: movss xmm0, dword ptr [0x0056B9E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9E4u);
	// 0x28B6E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28B6F0: movss [0x0056B9F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9F4u, ctx.xmm[0].u32[0]);
	// 0x28B6F8: ret
	return;
}

void sub_28B700(X86Context& ctx, uint8_t* base) {
	// 0x28B700: movss xmm0, dword ptr [0x0056BA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA38u);
	// 0x28B708: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28B710: movss [0x0056BA3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA3Cu, ctx.xmm[0].u32[0]);
	// 0x28B718: ret
	return;
}

void sub_28B720(X86Context& ctx, uint8_t* base) {
	// 0x28B720: movss xmm0, dword ptr [0x0056B9F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9F4u);
	// 0x28B728: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B730: movss [0x0056BA28], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA28u, ctx.xmm[0].u32[0]);
	// 0x28B738: ret
	return;
}

void sub_28B740(X86Context& ctx, uint8_t* base) {
	// 0x28B740: movss xmm0, dword ptr [0x0056BA3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA3Cu);
	// 0x28B748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B750: movss [0x0056BA4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA4Cu, ctx.xmm[0].u32[0]);
	// 0x28B758: ret
	return;
}

void sub_28B760(X86Context& ctx, uint8_t* base) {
	// 0x28B760: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28B768: movss [0x0056B9C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9C4u, ctx.xmm[0].u32[0]);
	// 0x28B770: ret
	return;
}

void sub_28B780(X86Context& ctx, uint8_t* base) {
	// 0x28B780: movss xmm0, dword ptr [0x0056B9E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9E4u);
	// 0x28B788: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B790: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28B798: movss [0x0056BA34], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA34u, ctx.xmm[0].u32[0]);
	// 0x28B7A0: ret
	return;
}

void sub_28B7B0(X86Context& ctx, uint8_t* base) {
	// 0x28B7B0: movss xmm0, dword ptr [0x0056BA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA38u);
	// 0x28B7B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B7C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28B7C8: movss [0x0056B9DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9DCu, ctx.xmm[0].u32[0]);
	// 0x28B7D0: ret
	return;
}

void sub_28B7E0(X86Context& ctx, uint8_t* base) {
	// 0x28B7E0: movss xmm0, dword ptr [0x0056B9E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9E4u);
	// 0x28B7E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B7F0: movss [0x0056B9E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9E0u, ctx.xmm[0].u32[0]);
	// 0x28B7F8: ret
	return;
}

void sub_28B800(X86Context& ctx, uint8_t* base) {
	// 0x28B800: movss xmm0, dword ptr [0x0056BA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA38u);
	// 0x28B808: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28B810: movss [0x0056BA40], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA40u, ctx.xmm[0].u32[0]);
	// 0x28B818: ret
	return;
}

void sub_28B820(X86Context& ctx, uint8_t* base) {
	// 0x28B820: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28B828: movss [0x0056B9C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9C8u, ctx.xmm[0].u32[0]);
	// 0x28B830: ret
	return;
}

void sub_28B840(X86Context& ctx, uint8_t* base) {
	// 0x28B840: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28B848: movss [0x0056B9F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9F0u, ctx.xmm[0].u32[0]);
	// 0x28B850: ret
	return;
}

void sub_28B860(X86Context& ctx, uint8_t* base) {
	// 0x28B860: movss xmm0, dword ptr [0x0056B9C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B9C8u);
	// 0x28B868: movss [0x0056BA54], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA54u, ctx.xmm[0].u32[0]);
	// 0x28B870: ret
	return;
}

void sub_28B880(X86Context& ctx, uint8_t* base) {
	// 0x28B880: movss xmm0, dword ptr [0x0056BA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA38u);
	// 0x28B888: subss xmm0, [0x0056B9C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B9C8u);
	// 0x28B890: movss [0x0056BA18], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA18u, ctx.xmm[0].u32[0]);
	// 0x28B898: ret
	return;
}

void sub_28B8A0(X86Context& ctx, uint8_t* base) {
	// 0x28B8A0: movss xmm0, dword ptr [0x0056BA18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA18u);
	// 0x28B8A8: subss xmm0, [0x0056B9F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B9F0u);
	// 0x28B8B0: movss [0x0056BA10], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA10u, ctx.xmm[0].u32[0]);
	// 0x28B8B8: ret
	return;
}

void sub_28B8C0(X86Context& ctx, uint8_t* base) {
	// 0x28B8C0: movss xmm0, dword ptr [0x0056BA40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA40u);
	// 0x28B8C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28B8D0: movss [0x0056BA00], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA00u, ctx.xmm[0].u32[0]);
	// 0x28B8D8: ret
	return;
}

void sub_28B8E0(X86Context& ctx, uint8_t* base) {
	// 0x28B8E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28B8E8: movss [0x0056B9EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B9ECu, ctx.xmm[0].u32[0]);
	// 0x28B8F0: ret
	return;
}

void sub_28B900(X86Context& ctx, uint8_t* base) {
	// 0x28B900: movss xmm0, dword ptr [0x0056BA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA00u);
	// 0x28B908: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28B910: movss [0x0056BA30], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA30u, ctx.xmm[0].u32[0]);
	// 0x28B918: ret
	return;
}

void sub_28B920(X86Context& ctx, uint8_t* base) {
	// 0x28B920: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28B928: movss [0x0056BAB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAB4u, ctx.xmm[0].u32[0]);
	// 0x28B930: ret
	return;
}

void sub_28B940(X86Context& ctx, uint8_t* base) {
	// 0x28B940: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28B948: movss [0x0056BAD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAD0u, ctx.xmm[0].u32[0]);
	// 0x28B950: ret
	return;
}

void sub_28B960(X86Context& ctx, uint8_t* base) {
	// 0x28B960: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28B968: movss [0x0056BAA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAA8u, ctx.xmm[0].u32[0]);
	// 0x28B970: ret
	return;
}

void sub_28B980(X86Context& ctx, uint8_t* base) {
	// 0x28B980: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28B988: movss [0x0056BA60], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA60u, ctx.xmm[0].u32[0]);
	// 0x28B990: ret
	return;
}

void sub_28B9A0(X86Context& ctx, uint8_t* base) {
	// 0x28B9A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28B9A8: movss [0x0056BAB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAB8u, ctx.xmm[0].u32[0]);
	// 0x28B9B0: ret
	return;
}

void sub_28B9C0(X86Context& ctx, uint8_t* base) {
	// 0x28B9C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28B9C8: movss [0x0056BA7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA7Cu, ctx.xmm[0].u32[0]);
	// 0x28B9D0: ret
	return;
}

void sub_28B9E0(X86Context& ctx, uint8_t* base) {
	// 0x28B9E0: movss xmm0, dword ptr [0x0056BAB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAB8u);
	// 0x28B9E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28B9F0: movss [0x0056BAF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAF0u, ctx.xmm[0].u32[0]);
	// 0x28B9F8: ret
	return;
}

void sub_28BA00(X86Context& ctx, uint8_t* base) {
	// 0x28BA00: movss xmm0, dword ptr [0x0056BA7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA7Cu);
	// 0x28BA08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28BA10: movss [0x0056BAD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAD8u, ctx.xmm[0].u32[0]);
	// 0x28BA18: ret
	return;
}

void sub_28BA20(X86Context& ctx, uint8_t* base) {
	// 0x28BA20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28BA28: movss [0x0056BB08], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB08u, ctx.xmm[0].u32[0]);
	// 0x28BA30: ret
	return;
}

void sub_28BA40(X86Context& ctx, uint8_t* base) {
	// 0x28BA40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28BA48: movss [0x0056BAF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAF4u, ctx.xmm[0].u32[0]);
	// 0x28BA50: ret
	return;
}

void sub_28BA60(X86Context& ctx, uint8_t* base) {
	// 0x28BA60: movss xmm0, dword ptr [0x0056BAF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BAF4u);
	// 0x28BA68: movss [0x0056BB04], xmm0
	X86_MEM_WRITE_u32(base, 0x56BB04u, ctx.xmm[0].u32[0]);
	// 0x28BA70: ret
	return;
}

void sub_28BA80(X86Context& ctx, uint8_t* base) {
	// 0x28BA80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28BA88: movss [0x0056BA68], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA68u, ctx.xmm[0].u32[0]);
	// 0x28BA90: ret
	return;
}

void sub_28BAA0(X86Context& ctx, uint8_t* base) {
	// 0x28BAA0: movss xmm0, dword ptr [0x0056BA7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA7Cu);
	// 0x28BAA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28BAB0: movss [0x0056BAFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAFCu, ctx.xmm[0].u32[0]);
	// 0x28BAB8: ret
	return;
}

void sub_28BAC0(X86Context& ctx, uint8_t* base) {
	// 0x28BAC0: movss xmm0, dword ptr [0x0056BA7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA7Cu);
	// 0x28BAC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28BAD0: movss [0x0056BAA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BAA4u, ctx.xmm[0].u32[0]);
	// 0x28BAD8: ret
	return;
}

void sub_28BAE0(X86Context& ctx, uint8_t* base) {
	// 0x28BAE0: movss xmm0, dword ptr [0x0056BA7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BA7Cu);
	// 0x28BAE8: subss xmm0, [0x0056BAA4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BAA4u);
	// 0x28BAF0: movss [0x0056BA84], xmm0
	X86_MEM_WRITE_u32(base, 0x56BA84u, ctx.xmm[0].u32[0]);
	// 0x28BAF8: ret
	return;
}

