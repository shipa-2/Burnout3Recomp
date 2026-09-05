#include "x86_recomp_shared.h"

void sub_287980(X86Context& ctx, uint8_t* base) {
	// 0x287980: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x287988: movss [0x0056B2B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2B8u, ctx.xmm[0].u32[0]);
	// 0x287990: ret
	return;
}

void sub_2879A0(X86Context& ctx, uint8_t* base) {
	// 0x2879A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2879A8: movss [0x0056B268], xmm0
	X86_MEM_WRITE_u32(base, 0x56B268u, ctx.xmm[0].u32[0]);
	// 0x2879B0: ret
	return;
}

void sub_2879C0(X86Context& ctx, uint8_t* base) {
	// 0x2879C0: movss xmm0, dword ptr [0x0056B280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B280u);
	// 0x2879C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2879D0: movss [0x0056B25C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B25Cu, ctx.xmm[0].u32[0]);
	// 0x2879D8: ret
	return;
}

void sub_2879E0(X86Context& ctx, uint8_t* base) {
	// 0x2879E0: movss xmm0, dword ptr [0x0056B2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2D4u);
	// 0x2879E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2879F0: movss [0x0056B2A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2A0u, ctx.xmm[0].u32[0]);
	// 0x2879F8: ret
	return;
}

void sub_287A00(X86Context& ctx, uint8_t* base) {
	// 0x287A00: movss xmm0, dword ptr [0x0056B25C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B25Cu);
	// 0x287A08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287A10: movss [0x0056B2B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2B0u, ctx.xmm[0].u32[0]);
	// 0x287A18: ret
	return;
}

void sub_287A20(X86Context& ctx, uint8_t* base) {
	// 0x287A20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x287A28: movss [0x0056B254], xmm0
	X86_MEM_WRITE_u32(base, 0x56B254u, ctx.xmm[0].u32[0]);
	// 0x287A30: ret
	return;
}

void sub_287A40(X86Context& ctx, uint8_t* base) {
	// 0x287A40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x287A48: movss [0x0056B284], xmm0
	X86_MEM_WRITE_u32(base, 0x56B284u, ctx.xmm[0].u32[0]);
	// 0x287A50: ret
	return;
}

void sub_287A60(X86Context& ctx, uint8_t* base) {
	// 0x287A60: movss xmm0, dword ptr [0x0056B280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B280u);
	// 0x287A68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x287A70: movss [0x0056B290], xmm0
	X86_MEM_WRITE_u32(base, 0x56B290u, ctx.xmm[0].u32[0]);
	// 0x287A78: ret
	return;
}

void sub_287A80(X86Context& ctx, uint8_t* base) {
	// 0x287A80: movss xmm0, dword ptr [0x0056B2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2D4u);
	// 0x287A88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x287A90: movss [0x0056B2D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2D8u, ctx.xmm[0].u32[0]);
	// 0x287A98: ret
	return;
}

void sub_287AA0(X86Context& ctx, uint8_t* base) {
	// 0x287AA0: movss xmm0, dword ptr [0x0056B290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B290u);
	// 0x287AA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287AB0: movss [0x0056B2C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2C4u, ctx.xmm[0].u32[0]);
	// 0x287AB8: ret
	return;
}

void sub_287AC0(X86Context& ctx, uint8_t* base) {
	// 0x287AC0: movss xmm0, dword ptr [0x0056B2D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2D8u);
	// 0x287AC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287AD0: movss [0x0056B2E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2E8u, ctx.xmm[0].u32[0]);
	// 0x287AD8: ret
	return;
}

void sub_287AE0(X86Context& ctx, uint8_t* base) {
	// 0x287AE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x287AE8: movss [0x0056B260], xmm0
	X86_MEM_WRITE_u32(base, 0x56B260u, ctx.xmm[0].u32[0]);
	// 0x287AF0: ret
	return;
}

void sub_287B00(X86Context& ctx, uint8_t* base) {
	// 0x287B00: movss xmm0, dword ptr [0x0056B280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B280u);
	// 0x287B08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287B10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x287B18: movss [0x0056B2D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2D0u, ctx.xmm[0].u32[0]);
	// 0x287B20: ret
	return;
}

void sub_287B30(X86Context& ctx, uint8_t* base) {
	// 0x287B30: movss xmm0, dword ptr [0x0056B2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2D4u);
	// 0x287B38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287B40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x287B48: movss [0x0056B278], xmm0
	X86_MEM_WRITE_u32(base, 0x56B278u, ctx.xmm[0].u32[0]);
	// 0x287B50: ret
	return;
}

void sub_287B60(X86Context& ctx, uint8_t* base) {
	// 0x287B60: movss xmm0, dword ptr [0x0056B280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B280u);
	// 0x287B68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287B70: movss [0x0056B27C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B27Cu, ctx.xmm[0].u32[0]);
	// 0x287B78: ret
	return;
}

void sub_287B80(X86Context& ctx, uint8_t* base) {
	// 0x287B80: movss xmm0, dword ptr [0x0056B2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2D4u);
	// 0x287B88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x287B90: movss [0x0056B2DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2DCu, ctx.xmm[0].u32[0]);
	// 0x287B98: ret
	return;
}

void sub_287BA0(X86Context& ctx, uint8_t* base) {
	// 0x287BA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x287BA8: movss [0x0056B264], xmm0
	X86_MEM_WRITE_u32(base, 0x56B264u, ctx.xmm[0].u32[0]);
	// 0x287BB0: ret
	return;
}

void sub_287BC0(X86Context& ctx, uint8_t* base) {
	// 0x287BC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x287BC8: movss [0x0056B28C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B28Cu, ctx.xmm[0].u32[0]);
	// 0x287BD0: ret
	return;
}

void sub_287BE0(X86Context& ctx, uint8_t* base) {
	// 0x287BE0: movss xmm0, dword ptr [0x0056B264]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B264u);
	// 0x287BE8: movss [0x0056B2F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2F0u, ctx.xmm[0].u32[0]);
	// 0x287BF0: ret
	return;
}

void sub_287C00(X86Context& ctx, uint8_t* base) {
	// 0x287C00: movss xmm0, dword ptr [0x0056B2D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2D4u);
	// 0x287C08: subss xmm0, [0x0056B264]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B264u);
	// 0x287C10: movss [0x0056B2B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2B4u, ctx.xmm[0].u32[0]);
	// 0x287C18: ret
	return;
}

void sub_287C20(X86Context& ctx, uint8_t* base) {
	// 0x287C20: movss xmm0, dword ptr [0x0056B2B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2B4u);
	// 0x287C28: subss xmm0, [0x0056B28C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B28Cu);
	// 0x287C30: movss [0x0056B2AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2ACu, ctx.xmm[0].u32[0]);
	// 0x287C38: ret
	return;
}

void sub_287C40(X86Context& ctx, uint8_t* base) {
	// 0x287C40: movss xmm0, dword ptr [0x0056B2DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B2DCu);
	// 0x287C48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x287C50: movss [0x0056B29C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B29Cu, ctx.xmm[0].u32[0]);
	// 0x287C58: ret
	return;
}

void sub_287C60(X86Context& ctx, uint8_t* base) {
	// 0x287C60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x287C68: movss [0x0056B288], xmm0
	X86_MEM_WRITE_u32(base, 0x56B288u, ctx.xmm[0].u32[0]);
	// 0x287C70: ret
	return;
}

void sub_287C80(X86Context& ctx, uint8_t* base) {
	// 0x287C80: movss xmm0, dword ptr [0x0056B29C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B29Cu);
	// 0x287C88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x287C90: movss [0x0056B2CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2CCu, ctx.xmm[0].u32[0]);
	// 0x287C98: ret
	return;
}

void sub_287CA0(X86Context& ctx, uint8_t* base) {
	// 0x287CA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x287CA8: movss [0x0056B350], xmm0
	X86_MEM_WRITE_u32(base, 0x56B350u, ctx.xmm[0].u32[0]);
	// 0x287CB0: ret
	return;
}

void sub_287CC0(X86Context& ctx, uint8_t* base) {
	// 0x287CC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x287CC8: movss [0x0056B36C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B36Cu, ctx.xmm[0].u32[0]);
	// 0x287CD0: ret
	return;
}

void sub_287CE0(X86Context& ctx, uint8_t* base) {
	// 0x287CE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x287CE8: movss [0x0056B344], xmm0
	X86_MEM_WRITE_u32(base, 0x56B344u, ctx.xmm[0].u32[0]);
	// 0x287CF0: ret
	return;
}

void sub_287D00(X86Context& ctx, uint8_t* base) {
	// 0x287D00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x287D08: movss [0x0056B2FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B2FCu, ctx.xmm[0].u32[0]);
	// 0x287D10: ret
	return;
}

void sub_287D20(X86Context& ctx, uint8_t* base) {
	// 0x287D20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x287D28: movss [0x0056B354], xmm0
	X86_MEM_WRITE_u32(base, 0x56B354u, ctx.xmm[0].u32[0]);
	// 0x287D30: ret
	return;
}

void sub_287D40(X86Context& ctx, uint8_t* base) {
	// 0x287D40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x287D48: movss [0x0056B318], xmm0
	X86_MEM_WRITE_u32(base, 0x56B318u, ctx.xmm[0].u32[0]);
	// 0x287D50: ret
	return;
}

void sub_287D60(X86Context& ctx, uint8_t* base) {
	// 0x287D60: movss xmm0, dword ptr [0x0056B354]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B354u);
	// 0x287D68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287D70: movss [0x0056B38C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B38Cu, ctx.xmm[0].u32[0]);
	// 0x287D78: ret
	return;
}

void sub_287D80(X86Context& ctx, uint8_t* base) {
	// 0x287D80: movss xmm0, dword ptr [0x0056B318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B318u);
	// 0x287D88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x287D90: movss [0x0056B374], xmm0
	X86_MEM_WRITE_u32(base, 0x56B374u, ctx.xmm[0].u32[0]);
	// 0x287D98: ret
	return;
}

void sub_287DA0(X86Context& ctx, uint8_t* base) {
	// 0x287DA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x287DA8: movss [0x0056B3A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3A4u, ctx.xmm[0].u32[0]);
	// 0x287DB0: ret
	return;
}

void sub_287DC0(X86Context& ctx, uint8_t* base) {
	// 0x287DC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x287DC8: movss [0x0056B390], xmm0
	X86_MEM_WRITE_u32(base, 0x56B390u, ctx.xmm[0].u32[0]);
	// 0x287DD0: ret
	return;
}

void sub_287DE0(X86Context& ctx, uint8_t* base) {
	// 0x287DE0: movss xmm0, dword ptr [0x0056B390]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B390u);
	// 0x287DE8: movss [0x0056B3A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3A0u, ctx.xmm[0].u32[0]);
	// 0x287DF0: ret
	return;
}

void sub_287E00(X86Context& ctx, uint8_t* base) {
	// 0x287E00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x287E08: movss [0x0056B304], xmm0
	X86_MEM_WRITE_u32(base, 0x56B304u, ctx.xmm[0].u32[0]);
	// 0x287E10: ret
	return;
}

void sub_287E20(X86Context& ctx, uint8_t* base) {
	// 0x287E20: movss xmm0, dword ptr [0x0056B318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B318u);
	// 0x287E28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x287E30: movss [0x0056B398], xmm0
	X86_MEM_WRITE_u32(base, 0x56B398u, ctx.xmm[0].u32[0]);
	// 0x287E38: ret
	return;
}

void sub_287E40(X86Context& ctx, uint8_t* base) {
	// 0x287E40: movss xmm0, dword ptr [0x0056B318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B318u);
	// 0x287E48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x287E50: movss [0x0056B340], xmm0
	X86_MEM_WRITE_u32(base, 0x56B340u, ctx.xmm[0].u32[0]);
	// 0x287E58: ret
	return;
}

void sub_287E60(X86Context& ctx, uint8_t* base) {
	// 0x287E60: movss xmm0, dword ptr [0x0056B318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B318u);
	// 0x287E68: subss xmm0, [0x0056B340]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B340u);
	// 0x287E70: movss [0x0056B320], xmm0
	X86_MEM_WRITE_u32(base, 0x56B320u, ctx.xmm[0].u32[0]);
	// 0x287E78: ret
	return;
}

void sub_287E80(X86Context& ctx, uint8_t* base) {
	// 0x287E80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x287E88: movss [0x0056B368], xmm0
	X86_MEM_WRITE_u32(base, 0x56B368u, ctx.xmm[0].u32[0]);
	// 0x287E90: ret
	return;
}

void sub_287EA0(X86Context& ctx, uint8_t* base) {
	// 0x287EA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x287EA8: movss [0x0056B31C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B31Cu, ctx.xmm[0].u32[0]);
	// 0x287EB0: ret
	return;
}

void sub_287EC0(X86Context& ctx, uint8_t* base) {
	// 0x287EC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x287EC8: movss [0x0056B32C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B32Cu, ctx.xmm[0].u32[0]);
	// 0x287ED0: ret
	return;
}

void sub_287EE0(X86Context& ctx, uint8_t* base) {
	// 0x287EE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x287EE8: movss [0x0056B380], xmm0
	X86_MEM_WRITE_u32(base, 0x56B380u, ctx.xmm[0].u32[0]);
	// 0x287EF0: ret
	return;
}

void sub_287F00(X86Context& ctx, uint8_t* base) {
	// 0x287F00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x287F08: movss [0x0056B364], xmm0
	X86_MEM_WRITE_u32(base, 0x56B364u, ctx.xmm[0].u32[0]);
	// 0x287F10: ret
	return;
}

void sub_287F20(X86Context& ctx, uint8_t* base) {
	// 0x287F20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x287F28: movss [0x0056B314], xmm0
	X86_MEM_WRITE_u32(base, 0x56B314u, ctx.xmm[0].u32[0]);
	// 0x287F30: ret
	return;
}

void sub_287F40(X86Context& ctx, uint8_t* base) {
	// 0x287F40: movss xmm0, dword ptr [0x0056B32C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B32Cu);
	// 0x287F48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287F50: movss [0x0056B308], xmm0
	X86_MEM_WRITE_u32(base, 0x56B308u, ctx.xmm[0].u32[0]);
	// 0x287F58: ret
	return;
}

void sub_287F60(X86Context& ctx, uint8_t* base) {
	// 0x287F60: movss xmm0, dword ptr [0x0056B380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B380u);
	// 0x287F68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x287F70: movss [0x0056B34C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B34Cu, ctx.xmm[0].u32[0]);
	// 0x287F78: ret
	return;
}

void sub_287F80(X86Context& ctx, uint8_t* base) {
	// 0x287F80: movss xmm0, dword ptr [0x0056B308]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B308u);
	// 0x287F88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x287F90: movss [0x0056B35C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B35Cu, ctx.xmm[0].u32[0]);
	// 0x287F98: ret
	return;
}

void sub_287FA0(X86Context& ctx, uint8_t* base) {
	// 0x287FA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x287FA8: movss [0x0056B300], xmm0
	X86_MEM_WRITE_u32(base, 0x56B300u, ctx.xmm[0].u32[0]);
	// 0x287FB0: ret
	return;
}

void sub_287FC0(X86Context& ctx, uint8_t* base) {
	// 0x287FC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x287FC8: movss [0x0056B330], xmm0
	X86_MEM_WRITE_u32(base, 0x56B330u, ctx.xmm[0].u32[0]);
	// 0x287FD0: ret
	return;
}

void sub_287FE0(X86Context& ctx, uint8_t* base) {
	// 0x287FE0: movss xmm0, dword ptr [0x0056B32C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B32Cu);
	// 0x287FE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x287FF0: movss [0x0056B33C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B33Cu, ctx.xmm[0].u32[0]);
	// 0x287FF8: ret
	return;
}

void sub_288000(X86Context& ctx, uint8_t* base) {
	// 0x288000: movss xmm0, dword ptr [0x0056B380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B380u);
	// 0x288008: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x288010: movss [0x0056B384], xmm0
	X86_MEM_WRITE_u32(base, 0x56B384u, ctx.xmm[0].u32[0]);
	// 0x288018: ret
	return;
}

void sub_288020(X86Context& ctx, uint8_t* base) {
	// 0x288020: movss xmm0, dword ptr [0x0056B33C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B33Cu);
	// 0x288028: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288030: movss [0x0056B370], xmm0
	X86_MEM_WRITE_u32(base, 0x56B370u, ctx.xmm[0].u32[0]);
	// 0x288038: ret
	return;
}

void sub_288040(X86Context& ctx, uint8_t* base) {
	// 0x288040: movss xmm0, dword ptr [0x0056B384]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B384u);
	// 0x288048: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288050: movss [0x0056B394], xmm0
	X86_MEM_WRITE_u32(base, 0x56B394u, ctx.xmm[0].u32[0]);
	// 0x288058: ret
	return;
}

void sub_288060(X86Context& ctx, uint8_t* base) {
	// 0x288060: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x288068: movss [0x0056B30C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B30Cu, ctx.xmm[0].u32[0]);
	// 0x288070: ret
	return;
}

void sub_288080(X86Context& ctx, uint8_t* base) {
	// 0x288080: movss xmm0, dword ptr [0x0056B32C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B32Cu);
	// 0x288088: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288090: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x288098: movss [0x0056B37C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B37Cu, ctx.xmm[0].u32[0]);
	// 0x2880A0: ret
	return;
}

void sub_2880B0(X86Context& ctx, uint8_t* base) {
	// 0x2880B0: movss xmm0, dword ptr [0x0056B380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B380u);
	// 0x2880B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2880C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2880C8: movss [0x0056B324], xmm0
	X86_MEM_WRITE_u32(base, 0x56B324u, ctx.xmm[0].u32[0]);
	// 0x2880D0: ret
	return;
}

void sub_2880E0(X86Context& ctx, uint8_t* base) {
	// 0x2880E0: movss xmm0, dword ptr [0x0056B32C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B32Cu);
	// 0x2880E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2880F0: movss [0x0056B328], xmm0
	X86_MEM_WRITE_u32(base, 0x56B328u, ctx.xmm[0].u32[0]);
	// 0x2880F8: ret
	return;
}

void sub_288100(X86Context& ctx, uint8_t* base) {
	// 0x288100: movss xmm0, dword ptr [0x0056B380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B380u);
	// 0x288108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288110: movss [0x0056B388], xmm0
	X86_MEM_WRITE_u32(base, 0x56B388u, ctx.xmm[0].u32[0]);
	// 0x288118: ret
	return;
}

void sub_288120(X86Context& ctx, uint8_t* base) {
	// 0x288120: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x288128: movss [0x0056B310], xmm0
	X86_MEM_WRITE_u32(base, 0x56B310u, ctx.xmm[0].u32[0]);
	// 0x288130: ret
	return;
}

void sub_288140(X86Context& ctx, uint8_t* base) {
	// 0x288140: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x288148: movss [0x0056B338], xmm0
	X86_MEM_WRITE_u32(base, 0x56B338u, ctx.xmm[0].u32[0]);
	// 0x288150: ret
	return;
}

void sub_288160(X86Context& ctx, uint8_t* base) {
	// 0x288160: movss xmm0, dword ptr [0x0056B310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B310u);
	// 0x288168: movss [0x0056B39C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B39Cu, ctx.xmm[0].u32[0]);
	// 0x288170: ret
	return;
}

void sub_288180(X86Context& ctx, uint8_t* base) {
	// 0x288180: movss xmm0, dword ptr [0x0056B380]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B380u);
	// 0x288188: subss xmm0, [0x0056B310]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B310u);
	// 0x288190: movss [0x0056B360], xmm0
	X86_MEM_WRITE_u32(base, 0x56B360u, ctx.xmm[0].u32[0]);
	// 0x288198: ret
	return;
}

void sub_2881A0(X86Context& ctx, uint8_t* base) {
	// 0x2881A0: movss xmm0, dword ptr [0x0056B360]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B360u);
	// 0x2881A8: subss xmm0, [0x0056B338]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B338u);
	// 0x2881B0: movss [0x0056B358], xmm0
	X86_MEM_WRITE_u32(base, 0x56B358u, ctx.xmm[0].u32[0]);
	// 0x2881B8: ret
	return;
}

void sub_2881C0(X86Context& ctx, uint8_t* base) {
	// 0x2881C0: movss xmm0, dword ptr [0x0056B388]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B388u);
	// 0x2881C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2881D0: movss [0x0056B348], xmm0
	X86_MEM_WRITE_u32(base, 0x56B348u, ctx.xmm[0].u32[0]);
	// 0x2881D8: ret
	return;
}

void sub_2881E0(X86Context& ctx, uint8_t* base) {
	// 0x2881E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2881E8: movss [0x0056B334], xmm0
	X86_MEM_WRITE_u32(base, 0x56B334u, ctx.xmm[0].u32[0]);
	// 0x2881F0: ret
	return;
}

void sub_288200(X86Context& ctx, uint8_t* base) {
	// 0x288200: movss xmm0, dword ptr [0x0056B348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B348u);
	// 0x288208: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x288210: movss [0x0056B378], xmm0
	X86_MEM_WRITE_u32(base, 0x56B378u, ctx.xmm[0].u32[0]);
	// 0x288218: ret
	return;
}

void sub_288220(X86Context& ctx, uint8_t* base) {
	// 0x288220: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x288228: movss [0x0056B3FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3FCu, ctx.xmm[0].u32[0]);
	// 0x288230: ret
	return;
}

void sub_288240(X86Context& ctx, uint8_t* base) {
	// 0x288240: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x288248: movss [0x0056B418], xmm0
	X86_MEM_WRITE_u32(base, 0x56B418u, ctx.xmm[0].u32[0]);
	// 0x288250: ret
	return;
}

void sub_288260(X86Context& ctx, uint8_t* base) {
	// 0x288260: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x288268: movss [0x0056B3F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3F0u, ctx.xmm[0].u32[0]);
	// 0x288270: ret
	return;
}

void sub_288280(X86Context& ctx, uint8_t* base) {
	// 0x288280: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x288288: movss [0x0056B3A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3A8u, ctx.xmm[0].u32[0]);
	// 0x288290: ret
	return;
}

void sub_2882A0(X86Context& ctx, uint8_t* base) {
	// 0x2882A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2882A8: movss [0x0056B400], xmm0
	X86_MEM_WRITE_u32(base, 0x56B400u, ctx.xmm[0].u32[0]);
	// 0x2882B0: ret
	return;
}

void sub_2882C0(X86Context& ctx, uint8_t* base) {
	// 0x2882C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2882C8: movss [0x0056B3C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3C4u, ctx.xmm[0].u32[0]);
	// 0x2882D0: ret
	return;
}

void sub_2882E0(X86Context& ctx, uint8_t* base) {
	// 0x2882E0: movss xmm0, dword ptr [0x0056B400]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B400u);
	// 0x2882E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2882F0: movss [0x0056B438], xmm0
	X86_MEM_WRITE_u32(base, 0x56B438u, ctx.xmm[0].u32[0]);
	// 0x2882F8: ret
	return;
}

void sub_288300(X86Context& ctx, uint8_t* base) {
	// 0x288300: movss xmm0, dword ptr [0x0056B3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3C4u);
	// 0x288308: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x288310: movss [0x0056B420], xmm0
	X86_MEM_WRITE_u32(base, 0x56B420u, ctx.xmm[0].u32[0]);
	// 0x288318: ret
	return;
}

void sub_288320(X86Context& ctx, uint8_t* base) {
	// 0x288320: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x288328: movss [0x0056B450], xmm0
	X86_MEM_WRITE_u32(base, 0x56B450u, ctx.xmm[0].u32[0]);
	// 0x288330: ret
	return;
}

void sub_288340(X86Context& ctx, uint8_t* base) {
	// 0x288340: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x288348: movss [0x0056B43C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B43Cu, ctx.xmm[0].u32[0]);
	// 0x288350: ret
	return;
}

void sub_288360(X86Context& ctx, uint8_t* base) {
	// 0x288360: movss xmm0, dword ptr [0x0056B43C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B43Cu);
	// 0x288368: movss [0x0056B44C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B44Cu, ctx.xmm[0].u32[0]);
	// 0x288370: ret
	return;
}

void sub_288380(X86Context& ctx, uint8_t* base) {
	// 0x288380: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x288388: movss [0x0056B3B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3B0u, ctx.xmm[0].u32[0]);
	// 0x288390: ret
	return;
}

void sub_2883A0(X86Context& ctx, uint8_t* base) {
	// 0x2883A0: movss xmm0, dword ptr [0x0056B3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3C4u);
	// 0x2883A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2883B0: movss [0x0056B444], xmm0
	X86_MEM_WRITE_u32(base, 0x56B444u, ctx.xmm[0].u32[0]);
	// 0x2883B8: ret
	return;
}

void sub_2883C0(X86Context& ctx, uint8_t* base) {
	// 0x2883C0: movss xmm0, dword ptr [0x0056B3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3C4u);
	// 0x2883C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2883D0: movss [0x0056B3EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3ECu, ctx.xmm[0].u32[0]);
	// 0x2883D8: ret
	return;
}

void sub_2883E0(X86Context& ctx, uint8_t* base) {
	// 0x2883E0: movss xmm0, dword ptr [0x0056B3C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3C4u);
	// 0x2883E8: subss xmm0, [0x0056B3EC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B3ECu);
	// 0x2883F0: movss [0x0056B3CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3CCu, ctx.xmm[0].u32[0]);
	// 0x2883F8: ret
	return;
}

void sub_288400(X86Context& ctx, uint8_t* base) {
	// 0x288400: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x288408: movss [0x0056B414], xmm0
	X86_MEM_WRITE_u32(base, 0x56B414u, ctx.xmm[0].u32[0]);
	// 0x288410: ret
	return;
}

void sub_288420(X86Context& ctx, uint8_t* base) {
	// 0x288420: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x288428: movss [0x0056B3C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3C8u, ctx.xmm[0].u32[0]);
	// 0x288430: ret
	return;
}

void sub_288440(X86Context& ctx, uint8_t* base) {
	// 0x288440: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x288448: movss [0x0056B3D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3D8u, ctx.xmm[0].u32[0]);
	// 0x288450: ret
	return;
}

void sub_288460(X86Context& ctx, uint8_t* base) {
	// 0x288460: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x288468: movss [0x0056B42C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B42Cu, ctx.xmm[0].u32[0]);
	// 0x288470: ret
	return;
}

void sub_288480(X86Context& ctx, uint8_t* base) {
	// 0x288480: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x288488: movss [0x0056B410], xmm0
	X86_MEM_WRITE_u32(base, 0x56B410u, ctx.xmm[0].u32[0]);
	// 0x288490: ret
	return;
}

void sub_2884A0(X86Context& ctx, uint8_t* base) {
	// 0x2884A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2884A8: movss [0x0056B3C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3C0u, ctx.xmm[0].u32[0]);
	// 0x2884B0: ret
	return;
}

void sub_2884C0(X86Context& ctx, uint8_t* base) {
	// 0x2884C0: movss xmm0, dword ptr [0x0056B3D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3D8u);
	// 0x2884C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2884D0: movss [0x0056B3B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3B4u, ctx.xmm[0].u32[0]);
	// 0x2884D8: ret
	return;
}

void sub_2884E0(X86Context& ctx, uint8_t* base) {
	// 0x2884E0: movss xmm0, dword ptr [0x0056B42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B42Cu);
	// 0x2884E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2884F0: movss [0x0056B3F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3F8u, ctx.xmm[0].u32[0]);
	// 0x2884F8: ret
	return;
}

void sub_288500(X86Context& ctx, uint8_t* base) {
	// 0x288500: movss xmm0, dword ptr [0x0056B3B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3B4u);
	// 0x288508: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x288510: movss [0x0056B408], xmm0
	X86_MEM_WRITE_u32(base, 0x56B408u, ctx.xmm[0].u32[0]);
	// 0x288518: ret
	return;
}

void sub_288520(X86Context& ctx, uint8_t* base) {
	// 0x288520: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x288528: movss [0x0056B3AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3ACu, ctx.xmm[0].u32[0]);
	// 0x288530: ret
	return;
}

void sub_288540(X86Context& ctx, uint8_t* base) {
	// 0x288540: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x288548: movss [0x0056B3DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3DCu, ctx.xmm[0].u32[0]);
	// 0x288550: ret
	return;
}

void sub_288560(X86Context& ctx, uint8_t* base) {
	// 0x288560: movss xmm0, dword ptr [0x0056B3D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3D8u);
	// 0x288568: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x288570: movss [0x0056B3E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3E8u, ctx.xmm[0].u32[0]);
	// 0x288578: ret
	return;
}

void sub_288580(X86Context& ctx, uint8_t* base) {
	// 0x288580: movss xmm0, dword ptr [0x0056B42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B42Cu);
	// 0x288588: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x288590: movss [0x0056B430], xmm0
	X86_MEM_WRITE_u32(base, 0x56B430u, ctx.xmm[0].u32[0]);
	// 0x288598: ret
	return;
}

void sub_2885A0(X86Context& ctx, uint8_t* base) {
	// 0x2885A0: movss xmm0, dword ptr [0x0056B3E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3E8u);
	// 0x2885A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2885B0: movss [0x0056B41C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B41Cu, ctx.xmm[0].u32[0]);
	// 0x2885B8: ret
	return;
}

void sub_2885C0(X86Context& ctx, uint8_t* base) {
	// 0x2885C0: movss xmm0, dword ptr [0x0056B430]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B430u);
	// 0x2885C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2885D0: movss [0x0056B440], xmm0
	X86_MEM_WRITE_u32(base, 0x56B440u, ctx.xmm[0].u32[0]);
	// 0x2885D8: ret
	return;
}

void sub_2885E0(X86Context& ctx, uint8_t* base) {
	// 0x2885E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2885E8: movss [0x0056B3B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3B8u, ctx.xmm[0].u32[0]);
	// 0x2885F0: ret
	return;
}

void sub_288600(X86Context& ctx, uint8_t* base) {
	// 0x288600: movss xmm0, dword ptr [0x0056B3D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3D8u);
	// 0x288608: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288610: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x288618: movss [0x0056B428], xmm0
	X86_MEM_WRITE_u32(base, 0x56B428u, ctx.xmm[0].u32[0]);
	// 0x288620: ret
	return;
}

void sub_288630(X86Context& ctx, uint8_t* base) {
	// 0x288630: movss xmm0, dword ptr [0x0056B42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B42Cu);
	// 0x288638: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288640: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x288648: movss [0x0056B3D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3D0u, ctx.xmm[0].u32[0]);
	// 0x288650: ret
	return;
}

void sub_288660(X86Context& ctx, uint8_t* base) {
	// 0x288660: movss xmm0, dword ptr [0x0056B3D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3D8u);
	// 0x288668: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288670: movss [0x0056B3D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3D4u, ctx.xmm[0].u32[0]);
	// 0x288678: ret
	return;
}

void sub_288680(X86Context& ctx, uint8_t* base) {
	// 0x288680: movss xmm0, dword ptr [0x0056B42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B42Cu);
	// 0x288688: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288690: movss [0x0056B434], xmm0
	X86_MEM_WRITE_u32(base, 0x56B434u, ctx.xmm[0].u32[0]);
	// 0x288698: ret
	return;
}

void sub_2886A0(X86Context& ctx, uint8_t* base) {
	// 0x2886A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2886A8: movss [0x0056B3BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3BCu, ctx.xmm[0].u32[0]);
	// 0x2886B0: ret
	return;
}

void sub_2886C0(X86Context& ctx, uint8_t* base) {
	// 0x2886C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2886C8: movss [0x0056B3E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3E4u, ctx.xmm[0].u32[0]);
	// 0x2886D0: ret
	return;
}

void sub_2886E0(X86Context& ctx, uint8_t* base) {
	// 0x2886E0: movss xmm0, dword ptr [0x0056B3BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3BCu);
	// 0x2886E8: movss [0x0056B448], xmm0
	X86_MEM_WRITE_u32(base, 0x56B448u, ctx.xmm[0].u32[0]);
	// 0x2886F0: ret
	return;
}

void sub_288700(X86Context& ctx, uint8_t* base) {
	// 0x288700: movss xmm0, dword ptr [0x0056B42C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B42Cu);
	// 0x288708: subss xmm0, [0x0056B3BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B3BCu);
	// 0x288710: movss [0x0056B40C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B40Cu, ctx.xmm[0].u32[0]);
	// 0x288718: ret
	return;
}

void sub_288720(X86Context& ctx, uint8_t* base) {
	// 0x288720: movss xmm0, dword ptr [0x0056B40C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B40Cu);
	// 0x288728: subss xmm0, [0x0056B3E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B3E4u);
	// 0x288730: movss [0x0056B404], xmm0
	X86_MEM_WRITE_u32(base, 0x56B404u, ctx.xmm[0].u32[0]);
	// 0x288738: ret
	return;
}

void sub_288740(X86Context& ctx, uint8_t* base) {
	// 0x288740: movss xmm0, dword ptr [0x0056B434]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B434u);
	// 0x288748: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x288750: movss [0x0056B3F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3F4u, ctx.xmm[0].u32[0]);
	// 0x288758: ret
	return;
}

void sub_288760(X86Context& ctx, uint8_t* base) {
	// 0x288760: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x288768: movss [0x0056B3E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B3E0u, ctx.xmm[0].u32[0]);
	// 0x288770: ret
	return;
}

void sub_288780(X86Context& ctx, uint8_t* base) {
	// 0x288780: movss xmm0, dword ptr [0x0056B3F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B3F4u);
	// 0x288788: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x288790: movss [0x0056B424], xmm0
	X86_MEM_WRITE_u32(base, 0x56B424u, ctx.xmm[0].u32[0]);
	// 0x288798: ret
	return;
}

void sub_2887A0(X86Context& ctx, uint8_t* base) {
	// 0x2887A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2887A8: movss [0x0056B4A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4A8u, ctx.xmm[0].u32[0]);
	// 0x2887B0: ret
	return;
}

void sub_2887C0(X86Context& ctx, uint8_t* base) {
	// 0x2887C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2887C8: movss [0x0056B4C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4C4u, ctx.xmm[0].u32[0]);
	// 0x2887D0: ret
	return;
}

void sub_2887E0(X86Context& ctx, uint8_t* base) {
	// 0x2887E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2887E8: movss [0x0056B49C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B49Cu, ctx.xmm[0].u32[0]);
	// 0x2887F0: ret
	return;
}

void sub_288800(X86Context& ctx, uint8_t* base) {
	// 0x288800: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x288808: movss [0x0056B454], xmm0
	X86_MEM_WRITE_u32(base, 0x56B454u, ctx.xmm[0].u32[0]);
	// 0x288810: ret
	return;
}

void sub_288820(X86Context& ctx, uint8_t* base) {
	// 0x288820: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x288828: movss [0x0056B4AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4ACu, ctx.xmm[0].u32[0]);
	// 0x288830: ret
	return;
}

void sub_288840(X86Context& ctx, uint8_t* base) {
	// 0x288840: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x288848: movss [0x0056B470], xmm0
	X86_MEM_WRITE_u32(base, 0x56B470u, ctx.xmm[0].u32[0]);
	// 0x288850: ret
	return;
}

void sub_288860(X86Context& ctx, uint8_t* base) {
	// 0x288860: movss xmm0, dword ptr [0x0056B4AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4ACu);
	// 0x288868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x288870: movss [0x0056B4E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4E4u, ctx.xmm[0].u32[0]);
	// 0x288878: ret
	return;
}

void sub_288880(X86Context& ctx, uint8_t* base) {
	// 0x288880: movss xmm0, dword ptr [0x0056B470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B470u);
	// 0x288888: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x288890: movss [0x0056B4CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4CCu, ctx.xmm[0].u32[0]);
	// 0x288898: ret
	return;
}

void sub_2888A0(X86Context& ctx, uint8_t* base) {
	// 0x2888A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2888A8: movss [0x0056B4FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4FCu, ctx.xmm[0].u32[0]);
	// 0x2888B0: ret
	return;
}

void sub_2888C0(X86Context& ctx, uint8_t* base) {
	// 0x2888C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2888C8: movss [0x0056B4E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4E8u, ctx.xmm[0].u32[0]);
	// 0x2888D0: ret
	return;
}

void sub_2888E0(X86Context& ctx, uint8_t* base) {
	// 0x2888E0: movss xmm0, dword ptr [0x0056B4E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4E8u);
	// 0x2888E8: movss [0x0056B4F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4F8u, ctx.xmm[0].u32[0]);
	// 0x2888F0: ret
	return;
}

void sub_288900(X86Context& ctx, uint8_t* base) {
	// 0x288900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x288908: movss [0x0056B45C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B45Cu, ctx.xmm[0].u32[0]);
	// 0x288910: ret
	return;
}

void sub_288920(X86Context& ctx, uint8_t* base) {
	// 0x288920: movss xmm0, dword ptr [0x0056B470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B470u);
	// 0x288928: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x288930: movss [0x0056B4F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4F0u, ctx.xmm[0].u32[0]);
	// 0x288938: ret
	return;
}

void sub_288940(X86Context& ctx, uint8_t* base) {
	// 0x288940: movss xmm0, dword ptr [0x0056B470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B470u);
	// 0x288948: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x288950: movss [0x0056B498], xmm0
	X86_MEM_WRITE_u32(base, 0x56B498u, ctx.xmm[0].u32[0]);
	// 0x288958: ret
	return;
}

void sub_288960(X86Context& ctx, uint8_t* base) {
	// 0x288960: movss xmm0, dword ptr [0x0056B470]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B470u);
	// 0x288968: subss xmm0, [0x0056B498]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B498u);
	// 0x288970: movss [0x0056B478], xmm0
	X86_MEM_WRITE_u32(base, 0x56B478u, ctx.xmm[0].u32[0]);
	// 0x288978: ret
	return;
}

void sub_288980(X86Context& ctx, uint8_t* base) {
	// 0x288980: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x288988: movss [0x0056B4C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4C0u, ctx.xmm[0].u32[0]);
	// 0x288990: ret
	return;
}

void sub_2889A0(X86Context& ctx, uint8_t* base) {
	// 0x2889A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2889A8: movss [0x0056B474], xmm0
	X86_MEM_WRITE_u32(base, 0x56B474u, ctx.xmm[0].u32[0]);
	// 0x2889B0: ret
	return;
}

void sub_2889C0(X86Context& ctx, uint8_t* base) {
	// 0x2889C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2889C8: movss [0x0056B484], xmm0
	X86_MEM_WRITE_u32(base, 0x56B484u, ctx.xmm[0].u32[0]);
	// 0x2889D0: ret
	return;
}

void sub_2889E0(X86Context& ctx, uint8_t* base) {
	// 0x2889E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2889E8: movss [0x0056B4D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4D8u, ctx.xmm[0].u32[0]);
	// 0x2889F0: ret
	return;
}

void sub_288A00(X86Context& ctx, uint8_t* base) {
	// 0x288A00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x288A08: movss [0x0056B4BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4BCu, ctx.xmm[0].u32[0]);
	// 0x288A10: ret
	return;
}

void sub_288A20(X86Context& ctx, uint8_t* base) {
	// 0x288A20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x288A28: movss [0x0056B46C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B46Cu, ctx.xmm[0].u32[0]);
	// 0x288A30: ret
	return;
}

void sub_288A40(X86Context& ctx, uint8_t* base) {
	// 0x288A40: movss xmm0, dword ptr [0x0056B484]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B484u);
	// 0x288A48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x288A50: movss [0x0056B460], xmm0
	X86_MEM_WRITE_u32(base, 0x56B460u, ctx.xmm[0].u32[0]);
	// 0x288A58: ret
	return;
}

void sub_288A60(X86Context& ctx, uint8_t* base) {
	// 0x288A60: movss xmm0, dword ptr [0x0056B4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4D8u);
	// 0x288A68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x288A70: movss [0x0056B4A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4A4u, ctx.xmm[0].u32[0]);
	// 0x288A78: ret
	return;
}

void sub_288A80(X86Context& ctx, uint8_t* base) {
	// 0x288A80: movss xmm0, dword ptr [0x0056B460]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B460u);
	// 0x288A88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x288A90: movss [0x0056B4B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4B4u, ctx.xmm[0].u32[0]);
	// 0x288A98: ret
	return;
}

void sub_288AA0(X86Context& ctx, uint8_t* base) {
	// 0x288AA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x288AA8: movss [0x0056B458], xmm0
	X86_MEM_WRITE_u32(base, 0x56B458u, ctx.xmm[0].u32[0]);
	// 0x288AB0: ret
	return;
}

void sub_288AC0(X86Context& ctx, uint8_t* base) {
	// 0x288AC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x288AC8: movss [0x0056B488], xmm0
	X86_MEM_WRITE_u32(base, 0x56B488u, ctx.xmm[0].u32[0]);
	// 0x288AD0: ret
	return;
}

void sub_288AE0(X86Context& ctx, uint8_t* base) {
	// 0x288AE0: movss xmm0, dword ptr [0x0056B484]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B484u);
	// 0x288AE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x288AF0: movss [0x0056B494], xmm0
	X86_MEM_WRITE_u32(base, 0x56B494u, ctx.xmm[0].u32[0]);
	// 0x288AF8: ret
	return;
}

void sub_288B00(X86Context& ctx, uint8_t* base) {
	// 0x288B00: movss xmm0, dword ptr [0x0056B4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4D8u);
	// 0x288B08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x288B10: movss [0x0056B4DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4DCu, ctx.xmm[0].u32[0]);
	// 0x288B18: ret
	return;
}

void sub_288B20(X86Context& ctx, uint8_t* base) {
	// 0x288B20: movss xmm0, dword ptr [0x0056B494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B494u);
	// 0x288B28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288B30: movss [0x0056B4C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4C8u, ctx.xmm[0].u32[0]);
	// 0x288B38: ret
	return;
}

void sub_288B40(X86Context& ctx, uint8_t* base) {
	// 0x288B40: movss xmm0, dword ptr [0x0056B4DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4DCu);
	// 0x288B48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288B50: movss [0x0056B4EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4ECu, ctx.xmm[0].u32[0]);
	// 0x288B58: ret
	return;
}

void sub_288B60(X86Context& ctx, uint8_t* base) {
	// 0x288B60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x288B68: movss [0x0056B464], xmm0
	X86_MEM_WRITE_u32(base, 0x56B464u, ctx.xmm[0].u32[0]);
	// 0x288B70: ret
	return;
}

void sub_288B80(X86Context& ctx, uint8_t* base) {
	// 0x288B80: movss xmm0, dword ptr [0x0056B484]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B484u);
	// 0x288B88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288B90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x288B98: movss [0x0056B4D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4D4u, ctx.xmm[0].u32[0]);
	// 0x288BA0: ret
	return;
}

void sub_288BB0(X86Context& ctx, uint8_t* base) {
	// 0x288BB0: movss xmm0, dword ptr [0x0056B4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4D8u);
	// 0x288BB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288BC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x288BC8: movss [0x0056B47C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B47Cu, ctx.xmm[0].u32[0]);
	// 0x288BD0: ret
	return;
}

void sub_288BE0(X86Context& ctx, uint8_t* base) {
	// 0x288BE0: movss xmm0, dword ptr [0x0056B484]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B484u);
	// 0x288BE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288BF0: movss [0x0056B480], xmm0
	X86_MEM_WRITE_u32(base, 0x56B480u, ctx.xmm[0].u32[0]);
	// 0x288BF8: ret
	return;
}

void sub_288C00(X86Context& ctx, uint8_t* base) {
	// 0x288C00: movss xmm0, dword ptr [0x0056B4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4D8u);
	// 0x288C08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x288C10: movss [0x0056B4E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4E0u, ctx.xmm[0].u32[0]);
	// 0x288C18: ret
	return;
}

void sub_288C20(X86Context& ctx, uint8_t* base) {
	// 0x288C20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x288C28: movss [0x0056B468], xmm0
	X86_MEM_WRITE_u32(base, 0x56B468u, ctx.xmm[0].u32[0]);
	// 0x288C30: ret
	return;
}

void sub_288C40(X86Context& ctx, uint8_t* base) {
	// 0x288C40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x288C48: movss [0x0056B490], xmm0
	X86_MEM_WRITE_u32(base, 0x56B490u, ctx.xmm[0].u32[0]);
	// 0x288C50: ret
	return;
}

void sub_288C60(X86Context& ctx, uint8_t* base) {
	// 0x288C60: movss xmm0, dword ptr [0x0056B468]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B468u);
	// 0x288C68: movss [0x0056B4F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4F4u, ctx.xmm[0].u32[0]);
	// 0x288C70: ret
	return;
}

void sub_288C80(X86Context& ctx, uint8_t* base) {
	// 0x288C80: movss xmm0, dword ptr [0x0056B4D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4D8u);
	// 0x288C88: subss xmm0, [0x0056B468]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B468u);
	// 0x288C90: movss [0x0056B4B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4B8u, ctx.xmm[0].u32[0]);
	// 0x288C98: ret
	return;
}

void sub_288CA0(X86Context& ctx, uint8_t* base) {
	// 0x288CA0: movss xmm0, dword ptr [0x0056B4B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4B8u);
	// 0x288CA8: subss xmm0, [0x0056B490]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B490u);
	// 0x288CB0: movss [0x0056B4B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4B0u, ctx.xmm[0].u32[0]);
	// 0x288CB8: ret
	return;
}

void sub_288CC0(X86Context& ctx, uint8_t* base) {
	// 0x288CC0: movss xmm0, dword ptr [0x0056B4E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4E0u);
	// 0x288CC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x288CD0: movss [0x0056B4A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4A0u, ctx.xmm[0].u32[0]);
	// 0x288CD8: ret
	return;
}

void sub_288CE0(X86Context& ctx, uint8_t* base) {
	// 0x288CE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x288CE8: movss [0x0056B48C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B48Cu, ctx.xmm[0].u32[0]);
	// 0x288CF0: ret
	return;
}

void sub_288D00(X86Context& ctx, uint8_t* base) {
	// 0x288D00: movss xmm0, dword ptr [0x0056B4A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B4A0u);
	// 0x288D08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x288D10: movss [0x0056B4D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B4D0u, ctx.xmm[0].u32[0]);
	// 0x288D18: ret
	return;
}

void sub_288D20(X86Context& ctx, uint8_t* base) {
	// 0x288D20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x288D28: movss [0x0056B554], xmm0
	X86_MEM_WRITE_u32(base, 0x56B554u, ctx.xmm[0].u32[0]);
	// 0x288D30: ret
	return;
}

void sub_288D40(X86Context& ctx, uint8_t* base) {
	// 0x288D40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x288D48: movss [0x0056B570], xmm0
	X86_MEM_WRITE_u32(base, 0x56B570u, ctx.xmm[0].u32[0]);
	// 0x288D50: ret
	return;
}

void sub_288D60(X86Context& ctx, uint8_t* base) {
	// 0x288D60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x288D68: movss [0x0056B548], xmm0
	X86_MEM_WRITE_u32(base, 0x56B548u, ctx.xmm[0].u32[0]);
	// 0x288D70: ret
	return;
}

void sub_288D80(X86Context& ctx, uint8_t* base) {
	// 0x288D80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x288D88: movss [0x0056B500], xmm0
	X86_MEM_WRITE_u32(base, 0x56B500u, ctx.xmm[0].u32[0]);
	// 0x288D90: ret
	return;
}

void sub_288DA0(X86Context& ctx, uint8_t* base) {
	// 0x288DA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x288DA8: movss [0x0056B558], xmm0
	X86_MEM_WRITE_u32(base, 0x56B558u, ctx.xmm[0].u32[0]);
	// 0x288DB0: ret
	return;
}

void sub_288DC0(X86Context& ctx, uint8_t* base) {
	// 0x288DC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x288DC8: movss [0x0056B51C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B51Cu, ctx.xmm[0].u32[0]);
	// 0x288DD0: ret
	return;
}

void sub_288DE0(X86Context& ctx, uint8_t* base) {
	// 0x288DE0: movss xmm0, dword ptr [0x0056B558]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B558u);
	// 0x288DE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x288DF0: movss [0x0056B590], xmm0
	X86_MEM_WRITE_u32(base, 0x56B590u, ctx.xmm[0].u32[0]);
	// 0x288DF8: ret
	return;
}

void sub_288E00(X86Context& ctx, uint8_t* base) {
	// 0x288E00: movss xmm0, dword ptr [0x0056B51C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B51Cu);
	// 0x288E08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x288E10: movss [0x0056B578], xmm0
	X86_MEM_WRITE_u32(base, 0x56B578u, ctx.xmm[0].u32[0]);
	// 0x288E18: ret
	return;
}

void sub_288E20(X86Context& ctx, uint8_t* base) {
	// 0x288E20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x288E28: movss [0x0056B5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5A8u, ctx.xmm[0].u32[0]);
	// 0x288E30: ret
	return;
}

void sub_288E40(X86Context& ctx, uint8_t* base) {
	// 0x288E40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x288E48: movss [0x0056B594], xmm0
	X86_MEM_WRITE_u32(base, 0x56B594u, ctx.xmm[0].u32[0]);
	// 0x288E50: ret
	return;
}

void sub_288E60(X86Context& ctx, uint8_t* base) {
	// 0x288E60: movss xmm0, dword ptr [0x0056B594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B594u);
	// 0x288E68: movss [0x0056B5A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5A4u, ctx.xmm[0].u32[0]);
	// 0x288E70: ret
	return;
}

void sub_288E80(X86Context& ctx, uint8_t* base) {
	// 0x288E80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x288E88: movss [0x0056B508], xmm0
	X86_MEM_WRITE_u32(base, 0x56B508u, ctx.xmm[0].u32[0]);
	// 0x288E90: ret
	return;
}

void sub_288EA0(X86Context& ctx, uint8_t* base) {
	// 0x288EA0: movss xmm0, dword ptr [0x0056B51C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B51Cu);
	// 0x288EA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x288EB0: movss [0x0056B59C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B59Cu, ctx.xmm[0].u32[0]);
	// 0x288EB8: ret
	return;
}

void sub_288EC0(X86Context& ctx, uint8_t* base) {
	// 0x288EC0: movss xmm0, dword ptr [0x0056B51C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B51Cu);
	// 0x288EC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x288ED0: movss [0x0056B544], xmm0
	X86_MEM_WRITE_u32(base, 0x56B544u, ctx.xmm[0].u32[0]);
	// 0x288ED8: ret
	return;
}

void sub_288EE0(X86Context& ctx, uint8_t* base) {
	// 0x288EE0: movss xmm0, dword ptr [0x0056B51C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B51Cu);
	// 0x288EE8: subss xmm0, [0x0056B544]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B544u);
	// 0x288EF0: movss [0x0056B524], xmm0
	X86_MEM_WRITE_u32(base, 0x56B524u, ctx.xmm[0].u32[0]);
	// 0x288EF8: ret
	return;
}

void sub_288F00(X86Context& ctx, uint8_t* base) {
	// 0x288F00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x288F08: movss [0x0056B56C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B56Cu, ctx.xmm[0].u32[0]);
	// 0x288F10: ret
	return;
}

void sub_288F20(X86Context& ctx, uint8_t* base) {
	// 0x288F20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x288F28: movss [0x0056B520], xmm0
	X86_MEM_WRITE_u32(base, 0x56B520u, ctx.xmm[0].u32[0]);
	// 0x288F30: ret
	return;
}

void sub_288F40(X86Context& ctx, uint8_t* base) {
	// 0x288F40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x288F48: movss [0x0056B530], xmm0
	X86_MEM_WRITE_u32(base, 0x56B530u, ctx.xmm[0].u32[0]);
	// 0x288F50: ret
	return;
}

void sub_288F60(X86Context& ctx, uint8_t* base) {
	// 0x288F60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x288F68: movss [0x0056B584], xmm0
	X86_MEM_WRITE_u32(base, 0x56B584u, ctx.xmm[0].u32[0]);
	// 0x288F70: ret
	return;
}

void sub_288F80(X86Context& ctx, uint8_t* base) {
	// 0x288F80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x288F88: movss [0x0056B568], xmm0
	X86_MEM_WRITE_u32(base, 0x56B568u, ctx.xmm[0].u32[0]);
	// 0x288F90: ret
	return;
}

void sub_288FA0(X86Context& ctx, uint8_t* base) {
	// 0x288FA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x288FA8: movss [0x0056B518], xmm0
	X86_MEM_WRITE_u32(base, 0x56B518u, ctx.xmm[0].u32[0]);
	// 0x288FB0: ret
	return;
}

void sub_288FC0(X86Context& ctx, uint8_t* base) {
	// 0x288FC0: movss xmm0, dword ptr [0x0056B530]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B530u);
	// 0x288FC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x288FD0: movss [0x0056B50C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B50Cu, ctx.xmm[0].u32[0]);
	// 0x288FD8: ret
	return;
}

void sub_288FE0(X86Context& ctx, uint8_t* base) {
	// 0x288FE0: movss xmm0, dword ptr [0x0056B584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B584u);
	// 0x288FE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x288FF0: movss [0x0056B550], xmm0
	X86_MEM_WRITE_u32(base, 0x56B550u, ctx.xmm[0].u32[0]);
	// 0x288FF8: ret
	return;
}

void sub_289000(X86Context& ctx, uint8_t* base) {
	// 0x289000: movss xmm0, dword ptr [0x0056B50C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B50Cu);
	// 0x289008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289010: movss [0x0056B560], xmm0
	X86_MEM_WRITE_u32(base, 0x56B560u, ctx.xmm[0].u32[0]);
	// 0x289018: ret
	return;
}

void sub_289020(X86Context& ctx, uint8_t* base) {
	// 0x289020: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x289028: movss [0x0056B504], xmm0
	X86_MEM_WRITE_u32(base, 0x56B504u, ctx.xmm[0].u32[0]);
	// 0x289030: ret
	return;
}

void sub_289040(X86Context& ctx, uint8_t* base) {
	// 0x289040: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x289048: movss [0x0056B534], xmm0
	X86_MEM_WRITE_u32(base, 0x56B534u, ctx.xmm[0].u32[0]);
	// 0x289050: ret
	return;
}

void sub_289060(X86Context& ctx, uint8_t* base) {
	// 0x289060: movss xmm0, dword ptr [0x0056B530]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B530u);
	// 0x289068: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x289070: movss [0x0056B540], xmm0
	X86_MEM_WRITE_u32(base, 0x56B540u, ctx.xmm[0].u32[0]);
	// 0x289078: ret
	return;
}

void sub_289080(X86Context& ctx, uint8_t* base) {
	// 0x289080: movss xmm0, dword ptr [0x0056B584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B584u);
	// 0x289088: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x289090: movss [0x0056B588], xmm0
	X86_MEM_WRITE_u32(base, 0x56B588u, ctx.xmm[0].u32[0]);
	// 0x289098: ret
	return;
}

void sub_2890A0(X86Context& ctx, uint8_t* base) {
	// 0x2890A0: movss xmm0, dword ptr [0x0056B540]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B540u);
	// 0x2890A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2890B0: movss [0x0056B574], xmm0
	X86_MEM_WRITE_u32(base, 0x56B574u, ctx.xmm[0].u32[0]);
	// 0x2890B8: ret
	return;
}

void sub_2890C0(X86Context& ctx, uint8_t* base) {
	// 0x2890C0: movss xmm0, dword ptr [0x0056B588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B588u);
	// 0x2890C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2890D0: movss [0x0056B598], xmm0
	X86_MEM_WRITE_u32(base, 0x56B598u, ctx.xmm[0].u32[0]);
	// 0x2890D8: ret
	return;
}

void sub_2890E0(X86Context& ctx, uint8_t* base) {
	// 0x2890E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2890E8: movss [0x0056B510], xmm0
	X86_MEM_WRITE_u32(base, 0x56B510u, ctx.xmm[0].u32[0]);
	// 0x2890F0: ret
	return;
}

void sub_289100(X86Context& ctx, uint8_t* base) {
	// 0x289100: movss xmm0, dword ptr [0x0056B530]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B530u);
	// 0x289108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289110: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x289118: movss [0x0056B580], xmm0
	X86_MEM_WRITE_u32(base, 0x56B580u, ctx.xmm[0].u32[0]);
	// 0x289120: ret
	return;
}

void sub_289130(X86Context& ctx, uint8_t* base) {
	// 0x289130: movss xmm0, dword ptr [0x0056B584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B584u);
	// 0x289138: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289140: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x289148: movss [0x0056B528], xmm0
	X86_MEM_WRITE_u32(base, 0x56B528u, ctx.xmm[0].u32[0]);
	// 0x289150: ret
	return;
}

void sub_289160(X86Context& ctx, uint8_t* base) {
	// 0x289160: movss xmm0, dword ptr [0x0056B530]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B530u);
	// 0x289168: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289170: movss [0x0056B52C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B52Cu, ctx.xmm[0].u32[0]);
	// 0x289178: ret
	return;
}

void sub_289180(X86Context& ctx, uint8_t* base) {
	// 0x289180: movss xmm0, dword ptr [0x0056B584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B584u);
	// 0x289188: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289190: movss [0x0056B58C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B58Cu, ctx.xmm[0].u32[0]);
	// 0x289198: ret
	return;
}

void sub_2891A0(X86Context& ctx, uint8_t* base) {
	// 0x2891A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2891A8: movss [0x0056B514], xmm0
	X86_MEM_WRITE_u32(base, 0x56B514u, ctx.xmm[0].u32[0]);
	// 0x2891B0: ret
	return;
}

void sub_2891C0(X86Context& ctx, uint8_t* base) {
	// 0x2891C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2891C8: movss [0x0056B53C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B53Cu, ctx.xmm[0].u32[0]);
	// 0x2891D0: ret
	return;
}

void sub_2891E0(X86Context& ctx, uint8_t* base) {
	// 0x2891E0: movss xmm0, dword ptr [0x0056B514]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B514u);
	// 0x2891E8: movss [0x0056B5A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5A0u, ctx.xmm[0].u32[0]);
	// 0x2891F0: ret
	return;
}

void sub_289200(X86Context& ctx, uint8_t* base) {
	// 0x289200: movss xmm0, dword ptr [0x0056B584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B584u);
	// 0x289208: subss xmm0, [0x0056B514]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B514u);
	// 0x289210: movss [0x0056B564], xmm0
	X86_MEM_WRITE_u32(base, 0x56B564u, ctx.xmm[0].u32[0]);
	// 0x289218: ret
	return;
}

void sub_289220(X86Context& ctx, uint8_t* base) {
	// 0x289220: movss xmm0, dword ptr [0x0056B564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B564u);
	// 0x289228: subss xmm0, [0x0056B53C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B53Cu);
	// 0x289230: movss [0x0056B55C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B55Cu, ctx.xmm[0].u32[0]);
	// 0x289238: ret
	return;
}

void sub_289240(X86Context& ctx, uint8_t* base) {
	// 0x289240: movss xmm0, dword ptr [0x0056B58C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B58Cu);
	// 0x289248: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x289250: movss [0x0056B54C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B54Cu, ctx.xmm[0].u32[0]);
	// 0x289258: ret
	return;
}

void sub_289260(X86Context& ctx, uint8_t* base) {
	// 0x289260: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x289268: movss [0x0056B538], xmm0
	X86_MEM_WRITE_u32(base, 0x56B538u, ctx.xmm[0].u32[0]);
	// 0x289270: ret
	return;
}

void sub_289280(X86Context& ctx, uint8_t* base) {
	// 0x289280: movss xmm0, dword ptr [0x0056B54C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B54Cu);
	// 0x289288: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x289290: movss [0x0056B57C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B57Cu, ctx.xmm[0].u32[0]);
	// 0x289298: ret
	return;
}

void sub_2892A0(X86Context& ctx, uint8_t* base) {
	// 0x2892A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2892A8: movss [0x0056B600], xmm0
	X86_MEM_WRITE_u32(base, 0x56B600u, ctx.xmm[0].u32[0]);
	// 0x2892B0: ret
	return;
}

void sub_2892C0(X86Context& ctx, uint8_t* base) {
	// 0x2892C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2892C8: movss [0x0056B61C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B61Cu, ctx.xmm[0].u32[0]);
	// 0x2892D0: ret
	return;
}

void sub_2892E0(X86Context& ctx, uint8_t* base) {
	// 0x2892E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2892E8: movss [0x0056B5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5F4u, ctx.xmm[0].u32[0]);
	// 0x2892F0: ret
	return;
}

void sub_289300(X86Context& ctx, uint8_t* base) {
	// 0x289300: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x289308: movss [0x0056B5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5ACu, ctx.xmm[0].u32[0]);
	// 0x289310: ret
	return;
}

void sub_289320(X86Context& ctx, uint8_t* base) {
	// 0x289320: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x289328: movss [0x0056B604], xmm0
	X86_MEM_WRITE_u32(base, 0x56B604u, ctx.xmm[0].u32[0]);
	// 0x289330: ret
	return;
}

void sub_289340(X86Context& ctx, uint8_t* base) {
	// 0x289340: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x289348: movss [0x0056B5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5C8u, ctx.xmm[0].u32[0]);
	// 0x289350: ret
	return;
}

void sub_289360(X86Context& ctx, uint8_t* base) {
	// 0x289360: movss xmm0, dword ptr [0x0056B604]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B604u);
	// 0x289368: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289370: movss [0x0056B63C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B63Cu, ctx.xmm[0].u32[0]);
	// 0x289378: ret
	return;
}

void sub_289380(X86Context& ctx, uint8_t* base) {
	// 0x289380: movss xmm0, dword ptr [0x0056B5C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5C8u);
	// 0x289388: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x289390: movss [0x0056B624], xmm0
	X86_MEM_WRITE_u32(base, 0x56B624u, ctx.xmm[0].u32[0]);
	// 0x289398: ret
	return;
}

void sub_2893A0(X86Context& ctx, uint8_t* base) {
	// 0x2893A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2893A8: movss [0x0056B654], xmm0
	X86_MEM_WRITE_u32(base, 0x56B654u, ctx.xmm[0].u32[0]);
	// 0x2893B0: ret
	return;
}

void sub_2893C0(X86Context& ctx, uint8_t* base) {
	// 0x2893C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2893C8: movss [0x0056B640], xmm0
	X86_MEM_WRITE_u32(base, 0x56B640u, ctx.xmm[0].u32[0]);
	// 0x2893D0: ret
	return;
}

void sub_2893E0(X86Context& ctx, uint8_t* base) {
	// 0x2893E0: movss xmm0, dword ptr [0x0056B640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B640u);
	// 0x2893E8: movss [0x0056B650], xmm0
	X86_MEM_WRITE_u32(base, 0x56B650u, ctx.xmm[0].u32[0]);
	// 0x2893F0: ret
	return;
}

void sub_289400(X86Context& ctx, uint8_t* base) {
	// 0x289400: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x289408: movss [0x0056B5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5B4u, ctx.xmm[0].u32[0]);
	// 0x289410: ret
	return;
}

void sub_289420(X86Context& ctx, uint8_t* base) {
	// 0x289420: movss xmm0, dword ptr [0x0056B5C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5C8u);
	// 0x289428: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x289430: movss [0x0056B648], xmm0
	X86_MEM_WRITE_u32(base, 0x56B648u, ctx.xmm[0].u32[0]);
	// 0x289438: ret
	return;
}

void sub_289440(X86Context& ctx, uint8_t* base) {
	// 0x289440: movss xmm0, dword ptr [0x0056B5C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5C8u);
	// 0x289448: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x289450: movss [0x0056B5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5F0u, ctx.xmm[0].u32[0]);
	// 0x289458: ret
	return;
}

void sub_289460(X86Context& ctx, uint8_t* base) {
	// 0x289460: movss xmm0, dword ptr [0x0056B5C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5C8u);
	// 0x289468: subss xmm0, [0x0056B5F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B5F0u);
	// 0x289470: movss [0x0056B5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5D0u, ctx.xmm[0].u32[0]);
	// 0x289478: ret
	return;
}

void sub_289480(X86Context& ctx, uint8_t* base) {
	// 0x289480: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x289488: movss [0x0056B618], xmm0
	X86_MEM_WRITE_u32(base, 0x56B618u, ctx.xmm[0].u32[0]);
	// 0x289490: ret
	return;
}

void sub_2894A0(X86Context& ctx, uint8_t* base) {
	// 0x2894A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2894A8: movss [0x0056B5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5CCu, ctx.xmm[0].u32[0]);
	// 0x2894B0: ret
	return;
}

void sub_2894C0(X86Context& ctx, uint8_t* base) {
	// 0x2894C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2894C8: movss [0x0056B5DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5DCu, ctx.xmm[0].u32[0]);
	// 0x2894D0: ret
	return;
}

void sub_2894E0(X86Context& ctx, uint8_t* base) {
	// 0x2894E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2894E8: movss [0x0056B630], xmm0
	X86_MEM_WRITE_u32(base, 0x56B630u, ctx.xmm[0].u32[0]);
	// 0x2894F0: ret
	return;
}

void sub_289500(X86Context& ctx, uint8_t* base) {
	// 0x289500: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x289508: movss [0x0056B614], xmm0
	X86_MEM_WRITE_u32(base, 0x56B614u, ctx.xmm[0].u32[0]);
	// 0x289510: ret
	return;
}

void sub_289520(X86Context& ctx, uint8_t* base) {
	// 0x289520: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x289528: movss [0x0056B5C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5C4u, ctx.xmm[0].u32[0]);
	// 0x289530: ret
	return;
}

void sub_289540(X86Context& ctx, uint8_t* base) {
	// 0x289540: movss xmm0, dword ptr [0x0056B5DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5DCu);
	// 0x289548: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289550: movss [0x0056B5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5B8u, ctx.xmm[0].u32[0]);
	// 0x289558: ret
	return;
}

void sub_289560(X86Context& ctx, uint8_t* base) {
	// 0x289560: movss xmm0, dword ptr [0x0056B630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B630u);
	// 0x289568: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x289570: movss [0x0056B5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5FCu, ctx.xmm[0].u32[0]);
	// 0x289578: ret
	return;
}

void sub_289580(X86Context& ctx, uint8_t* base) {
	// 0x289580: movss xmm0, dword ptr [0x0056B5B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5B8u);
	// 0x289588: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x289590: movss [0x0056B60C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B60Cu, ctx.xmm[0].u32[0]);
	// 0x289598: ret
	return;
}

void sub_2895A0(X86Context& ctx, uint8_t* base) {
	// 0x2895A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2895A8: movss [0x0056B5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5B0u, ctx.xmm[0].u32[0]);
	// 0x2895B0: ret
	return;
}

void sub_2895C0(X86Context& ctx, uint8_t* base) {
	// 0x2895C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2895C8: movss [0x0056B5E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5E0u, ctx.xmm[0].u32[0]);
	// 0x2895D0: ret
	return;
}

void sub_2895E0(X86Context& ctx, uint8_t* base) {
	// 0x2895E0: movss xmm0, dword ptr [0x0056B5DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5DCu);
	// 0x2895E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2895F0: movss [0x0056B5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5ECu, ctx.xmm[0].u32[0]);
	// 0x2895F8: ret
	return;
}

void sub_289600(X86Context& ctx, uint8_t* base) {
	// 0x289600: movss xmm0, dword ptr [0x0056B630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B630u);
	// 0x289608: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x289610: movss [0x0056B634], xmm0
	X86_MEM_WRITE_u32(base, 0x56B634u, ctx.xmm[0].u32[0]);
	// 0x289618: ret
	return;
}

void sub_289620(X86Context& ctx, uint8_t* base) {
	// 0x289620: movss xmm0, dword ptr [0x0056B5EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5ECu);
	// 0x289628: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289630: movss [0x0056B620], xmm0
	X86_MEM_WRITE_u32(base, 0x56B620u, ctx.xmm[0].u32[0]);
	// 0x289638: ret
	return;
}

void sub_289640(X86Context& ctx, uint8_t* base) {
	// 0x289640: movss xmm0, dword ptr [0x0056B634]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B634u);
	// 0x289648: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289650: movss [0x0056B644], xmm0
	X86_MEM_WRITE_u32(base, 0x56B644u, ctx.xmm[0].u32[0]);
	// 0x289658: ret
	return;
}

void sub_289660(X86Context& ctx, uint8_t* base) {
	// 0x289660: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x289668: movss [0x0056B5BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5BCu, ctx.xmm[0].u32[0]);
	// 0x289670: ret
	return;
}

void sub_289680(X86Context& ctx, uint8_t* base) {
	// 0x289680: movss xmm0, dword ptr [0x0056B5DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5DCu);
	// 0x289688: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289690: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x289698: movss [0x0056B62C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B62Cu, ctx.xmm[0].u32[0]);
	// 0x2896A0: ret
	return;
}

void sub_2896B0(X86Context& ctx, uint8_t* base) {
	// 0x2896B0: movss xmm0, dword ptr [0x0056B630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B630u);
	// 0x2896B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2896C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2896C8: movss [0x0056B5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5D4u, ctx.xmm[0].u32[0]);
	// 0x2896D0: ret
	return;
}

void sub_2896E0(X86Context& ctx, uint8_t* base) {
	// 0x2896E0: movss xmm0, dword ptr [0x0056B5DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5DCu);
	// 0x2896E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2896F0: movss [0x0056B5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5D8u, ctx.xmm[0].u32[0]);
	// 0x2896F8: ret
	return;
}

void sub_289700(X86Context& ctx, uint8_t* base) {
	// 0x289700: movss xmm0, dword ptr [0x0056B630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B630u);
	// 0x289708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x289710: movss [0x0056B638], xmm0
	X86_MEM_WRITE_u32(base, 0x56B638u, ctx.xmm[0].u32[0]);
	// 0x289718: ret
	return;
}

void sub_289720(X86Context& ctx, uint8_t* base) {
	// 0x289720: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x289728: movss [0x0056B5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5C0u, ctx.xmm[0].u32[0]);
	// 0x289730: ret
	return;
}

void sub_289740(X86Context& ctx, uint8_t* base) {
	// 0x289740: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x289748: movss [0x0056B5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5E8u, ctx.xmm[0].u32[0]);
	// 0x289750: ret
	return;
}

void sub_289760(X86Context& ctx, uint8_t* base) {
	// 0x289760: movss xmm0, dword ptr [0x0056B5C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5C0u);
	// 0x289768: movss [0x0056B64C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B64Cu, ctx.xmm[0].u32[0]);
	// 0x289770: ret
	return;
}

void sub_289780(X86Context& ctx, uint8_t* base) {
	// 0x289780: movss xmm0, dword ptr [0x0056B630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B630u);
	// 0x289788: subss xmm0, [0x0056B5C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B5C0u);
	// 0x289790: movss [0x0056B610], xmm0
	X86_MEM_WRITE_u32(base, 0x56B610u, ctx.xmm[0].u32[0]);
	// 0x289798: ret
	return;
}

void sub_2897A0(X86Context& ctx, uint8_t* base) {
	// 0x2897A0: movss xmm0, dword ptr [0x0056B610]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B610u);
	// 0x2897A8: subss xmm0, [0x0056B5E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B5E8u);
	// 0x2897B0: movss [0x0056B608], xmm0
	X86_MEM_WRITE_u32(base, 0x56B608u, ctx.xmm[0].u32[0]);
	// 0x2897B8: ret
	return;
}

void sub_2897C0(X86Context& ctx, uint8_t* base) {
	// 0x2897C0: movss xmm0, dword ptr [0x0056B638]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B638u);
	// 0x2897C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2897D0: movss [0x0056B5F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5F8u, ctx.xmm[0].u32[0]);
	// 0x2897D8: ret
	return;
}

void sub_2897E0(X86Context& ctx, uint8_t* base) {
	// 0x2897E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2897E8: movss [0x0056B5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B5E4u, ctx.xmm[0].u32[0]);
	// 0x2897F0: ret
	return;
}

void sub_289800(X86Context& ctx, uint8_t* base) {
	// 0x289800: movss xmm0, dword ptr [0x0056B5F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B5F8u);
	// 0x289808: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x289810: movss [0x0056B628], xmm0
	X86_MEM_WRITE_u32(base, 0x56B628u, ctx.xmm[0].u32[0]);
	// 0x289818: ret
	return;
}

void sub_289820(X86Context& ctx, uint8_t* base) {
	// 0x289820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x289828: movss [0x0056B6AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6ACu, ctx.xmm[0].u32[0]);
	// 0x289830: ret
	return;
}

void sub_289840(X86Context& ctx, uint8_t* base) {
	// 0x289840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x289848: movss [0x0056B6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6C8u, ctx.xmm[0].u32[0]);
	// 0x289850: ret
	return;
}

void sub_289860(X86Context& ctx, uint8_t* base) {
	// 0x289860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x289868: movss [0x0056B6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6A0u, ctx.xmm[0].u32[0]);
	// 0x289870: ret
	return;
}

void sub_289880(X86Context& ctx, uint8_t* base) {
	// 0x289880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x289888: movss [0x0056B658], xmm0
	X86_MEM_WRITE_u32(base, 0x56B658u, ctx.xmm[0].u32[0]);
	// 0x289890: ret
	return;
}

void sub_2898A0(X86Context& ctx, uint8_t* base) {
	// 0x2898A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2898A8: movss [0x0056B6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6B0u, ctx.xmm[0].u32[0]);
	// 0x2898B0: ret
	return;
}

void sub_2898C0(X86Context& ctx, uint8_t* base) {
	// 0x2898C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2898C8: movss [0x0056B674], xmm0
	X86_MEM_WRITE_u32(base, 0x56B674u, ctx.xmm[0].u32[0]);
	// 0x2898D0: ret
	return;
}

void sub_2898E0(X86Context& ctx, uint8_t* base) {
	// 0x2898E0: movss xmm0, dword ptr [0x0056B6B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6B0u);
	// 0x2898E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2898F0: movss [0x0056B6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6E8u, ctx.xmm[0].u32[0]);
	// 0x2898F8: ret
	return;
}

void sub_289900(X86Context& ctx, uint8_t* base) {
	// 0x289900: movss xmm0, dword ptr [0x0056B674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B674u);
	// 0x289908: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x289910: movss [0x0056B6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6D0u, ctx.xmm[0].u32[0]);
	// 0x289918: ret
	return;
}

void sub_289920(X86Context& ctx, uint8_t* base) {
	// 0x289920: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x289928: movss [0x0056B700], xmm0
	X86_MEM_WRITE_u32(base, 0x56B700u, ctx.xmm[0].u32[0]);
	// 0x289930: ret
	return;
}

void sub_289940(X86Context& ctx, uint8_t* base) {
	// 0x289940: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x289948: movss [0x0056B6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6ECu, ctx.xmm[0].u32[0]);
	// 0x289950: ret
	return;
}

void sub_289960(X86Context& ctx, uint8_t* base) {
	// 0x289960: movss xmm0, dword ptr [0x0056B6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B6ECu);
	// 0x289968: movss [0x0056B6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6FCu, ctx.xmm[0].u32[0]);
	// 0x289970: ret
	return;
}

void sub_289980(X86Context& ctx, uint8_t* base) {
	// 0x289980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x289988: movss [0x0056B660], xmm0
	X86_MEM_WRITE_u32(base, 0x56B660u, ctx.xmm[0].u32[0]);
	// 0x289990: ret
	return;
}

void sub_2899A0(X86Context& ctx, uint8_t* base) {
	// 0x2899A0: movss xmm0, dword ptr [0x0056B674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B674u);
	// 0x2899A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2899B0: movss [0x0056B6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6F4u, ctx.xmm[0].u32[0]);
	// 0x2899B8: ret
	return;
}

void sub_2899C0(X86Context& ctx, uint8_t* base) {
	// 0x2899C0: movss xmm0, dword ptr [0x0056B674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B674u);
	// 0x2899C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2899D0: movss [0x0056B69C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B69Cu, ctx.xmm[0].u32[0]);
	// 0x2899D8: ret
	return;
}

void sub_2899E0(X86Context& ctx, uint8_t* base) {
	// 0x2899E0: movss xmm0, dword ptr [0x0056B674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56B674u);
	// 0x2899E8: subss xmm0, [0x0056B69C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56B69Cu);
	// 0x2899F0: movss [0x0056B67C], xmm0
	X86_MEM_WRITE_u32(base, 0x56B67Cu, ctx.xmm[0].u32[0]);
	// 0x2899F8: ret
	return;
}

void sub_289A00(X86Context& ctx, uint8_t* base) {
	// 0x289A00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x289A08: movss [0x0056B6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56B6C4u, ctx.xmm[0].u32[0]);
	// 0x289A10: ret
	return;
}

void sub_289A20(X86Context& ctx, uint8_t* base) {
	// 0x289A20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x289A28: movss [0x0056B678], xmm0
	X86_MEM_WRITE_u32(base, 0x56B678u, ctx.xmm[0].u32[0]);
	// 0x289A30: ret
	return;
}

