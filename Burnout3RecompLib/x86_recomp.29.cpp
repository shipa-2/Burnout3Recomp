#include "x86_recomp_shared.h"

void sub_257BA0(X86Context& ctx, uint8_t* base) {
	// 0x257BA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x257BA8: movss [0x004D5474], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5474u, ctx.xmm[0].u32[0]);
	// 0x257BB0: ret
	return;
}

void sub_257BC0(X86Context& ctx, uint8_t* base) {
	// 0x257BC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x257BC8: movss [0x004D5494], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5494u, ctx.xmm[0].u32[0]);
	// 0x257BD0: ret
	return;
}

void sub_257BE0(X86Context& ctx, uint8_t* base) {
	// 0x257BE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x257BE8: movss [0x004D547C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D547Cu, ctx.xmm[0].u32[0]);
	// 0x257BF0: ret
	return;
}

void sub_257C00(X86Context& ctx, uint8_t* base) {
	// 0x257C00: movss xmm0, dword ptr [0x004D5494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5494u);
	// 0x257C08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x257C10: movss [0x004D54A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54A4u, ctx.xmm[0].u32[0]);
	// 0x257C18: ret
	return;
}

void sub_257C20(X86Context& ctx, uint8_t* base) {
	// 0x257C20: movss xmm0, dword ptr [0x004D547C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D547Cu);
	// 0x257C28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x257C30: movss [0x004D54A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54A0u, ctx.xmm[0].u32[0]);
	// 0x257C38: ret
	return;
}

void sub_257C40(X86Context& ctx, uint8_t* base) {
	// 0x257C40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x257C48: movss [0x004D54B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54B4u, ctx.xmm[0].u32[0]);
	// 0x257C50: ret
	return;
}

void sub_257C60(X86Context& ctx, uint8_t* base) {
	// 0x257C60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x257C68: movss [0x004D54A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54A8u, ctx.xmm[0].u32[0]);
	// 0x257C70: ret
	return;
}

void sub_257C80(X86Context& ctx, uint8_t* base) {
	// 0x257C80: movss xmm0, dword ptr [0x004D54A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54A8u);
	// 0x257C88: movss [0x004D54B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54B0u, ctx.xmm[0].u32[0]);
	// 0x257C90: ret
	return;
}

void sub_257CA0(X86Context& ctx, uint8_t* base) {
	// 0x257CA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x257CA8: movss [0x004D5478], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5478u, ctx.xmm[0].u32[0]);
	// 0x257CB0: ret
	return;
}

void sub_257CC0(X86Context& ctx, uint8_t* base) {
	// 0x257CC0: movss xmm0, dword ptr [0x004D547C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D547Cu);
	// 0x257CC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x257CD0: movss [0x004D54AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54ACu, ctx.xmm[0].u32[0]);
	// 0x257CD8: ret
	return;
}

void sub_257CE0(X86Context& ctx, uint8_t* base) {
	// 0x257CE0: movss xmm0, dword ptr [0x004D547C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D547Cu);
	// 0x257CE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x257CF0: movss [0x004D5488], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5488u, ctx.xmm[0].u32[0]);
	// 0x257CF8: ret
	return;
}

void sub_257D00(X86Context& ctx, uint8_t* base) {
	// 0x257D00: movss xmm0, dword ptr [0x004D547C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D547Cu);
	// 0x257D08: subss xmm0, [0x004D5488]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5488u);
	// 0x257D10: movss [0x004D5484], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5484u, ctx.xmm[0].u32[0]);
	// 0x257D18: ret
	return;
}

void sub_257D20(X86Context& ctx, uint8_t* base) {
	// 0x257D20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x257D28: movss [0x004D5498], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5498u, ctx.xmm[0].u32[0]);
	// 0x257D30: ret
	return;
}

void sub_257D40(X86Context& ctx, uint8_t* base) {
	// 0x257D40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x257D48: movss [0x004D5480], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5480u, ctx.xmm[0].u32[0]);
	// 0x257D50: ret
	return;
}

void sub_257D60(X86Context& ctx, uint8_t* base) {
	// 0x257D60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x257D68: movss [0x004D5514], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5514u, ctx.xmm[0].u32[0]);
	// 0x257D70: ret
	return;
}

void sub_257D80(X86Context& ctx, uint8_t* base) {
	// 0x257D80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x257D88: movss [0x004D5530], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5530u, ctx.xmm[0].u32[0]);
	// 0x257D90: ret
	return;
}

void sub_257DA0(X86Context& ctx, uint8_t* base) {
	// 0x257DA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x257DA8: movss [0x004D5504], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5504u, ctx.xmm[0].u32[0]);
	// 0x257DB0: ret
	return;
}

void sub_257DC0(X86Context& ctx, uint8_t* base) {
	// 0x257DC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x257DC8: movss [0x004D54B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54B8u, ctx.xmm[0].u32[0]);
	// 0x257DD0: ret
	return;
}

void sub_257DE0(X86Context& ctx, uint8_t* base) {
	// 0x257DE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x257DE8: movss [0x004D5518], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5518u, ctx.xmm[0].u32[0]);
	// 0x257DF0: ret
	return;
}

void sub_257E00(X86Context& ctx, uint8_t* base) {
	// 0x257E00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x257E08: movss [0x004D54D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54D4u, ctx.xmm[0].u32[0]);
	// 0x257E10: ret
	return;
}

void sub_257E20(X86Context& ctx, uint8_t* base) {
	// 0x257E20: movss xmm0, dword ptr [0x004D5518]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5518u);
	// 0x257E28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x257E30: movss [0x004D5550], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5550u, ctx.xmm[0].u32[0]);
	// 0x257E38: ret
	return;
}

void sub_257E40(X86Context& ctx, uint8_t* base) {
	// 0x257E40: movss xmm0, dword ptr [0x004D54D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54D4u);
	// 0x257E48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x257E50: movss [0x004D5538], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5538u, ctx.xmm[0].u32[0]);
	// 0x257E58: ret
	return;
}

void sub_257E60(X86Context& ctx, uint8_t* base) {
	// 0x257E60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x257E68: movss [0x004D5568], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5568u, ctx.xmm[0].u32[0]);
	// 0x257E70: ret
	return;
}

void sub_257E80(X86Context& ctx, uint8_t* base) {
	// 0x257E80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x257E88: movss [0x004D5554], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5554u, ctx.xmm[0].u32[0]);
	// 0x257E90: ret
	return;
}

void sub_257EA0(X86Context& ctx, uint8_t* base) {
	// 0x257EA0: movss xmm0, dword ptr [0x004D5554]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5554u);
	// 0x257EA8: movss [0x004D5564], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5564u, ctx.xmm[0].u32[0]);
	// 0x257EB0: ret
	return;
}

void sub_257EC0(X86Context& ctx, uint8_t* base) {
	// 0x257EC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x257EC8: movss [0x004D54C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54C0u, ctx.xmm[0].u32[0]);
	// 0x257ED0: ret
	return;
}

void sub_257EE0(X86Context& ctx, uint8_t* base) {
	// 0x257EE0: movss xmm0, dword ptr [0x004D54D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54D4u);
	// 0x257EE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x257EF0: movss [0x004D555C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D555Cu, ctx.xmm[0].u32[0]);
	// 0x257EF8: ret
	return;
}

void sub_257F00(X86Context& ctx, uint8_t* base) {
	// 0x257F00: movss xmm0, dword ptr [0x004D54D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54D4u);
	// 0x257F08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x257F10: movss [0x004D5500], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5500u, ctx.xmm[0].u32[0]);
	// 0x257F18: ret
	return;
}

void sub_257F20(X86Context& ctx, uint8_t* base) {
	// 0x257F20: movss xmm0, dword ptr [0x004D54D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54D4u);
	// 0x257F28: subss xmm0, [0x004D5500]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5500u);
	// 0x257F30: movss [0x004D54DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54DCu, ctx.xmm[0].u32[0]);
	// 0x257F38: ret
	return;
}

void sub_257F40(X86Context& ctx, uint8_t* base) {
	// 0x257F40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x257F48: movss [0x004D552C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D552Cu, ctx.xmm[0].u32[0]);
	// 0x257F50: ret
	return;
}

void sub_257F60(X86Context& ctx, uint8_t* base) {
	// 0x257F60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x257F68: movss [0x004D54D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54D8u, ctx.xmm[0].u32[0]);
	// 0x257F70: ret
	return;
}

void sub_257F80(X86Context& ctx, uint8_t* base) {
	// 0x257F80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x257F88: movss [0x004D54EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54ECu, ctx.xmm[0].u32[0]);
	// 0x257F90: ret
	return;
}

void sub_257FA0(X86Context& ctx, uint8_t* base) {
	// 0x257FA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x257FA8: movss [0x004D5544], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5544u, ctx.xmm[0].u32[0]);
	// 0x257FB0: ret
	return;
}

void sub_257FC0(X86Context& ctx, uint8_t* base) {
	// 0x257FC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x257FC8: movss [0x004D5528], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5528u, ctx.xmm[0].u32[0]);
	// 0x257FD0: ret
	return;
}

void sub_257FE0(X86Context& ctx, uint8_t* base) {
	// 0x257FE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x257FE8: movss [0x004D54D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54D0u, ctx.xmm[0].u32[0]);
	// 0x257FF0: ret
	return;
}

void sub_258000(X86Context& ctx, uint8_t* base) {
	// 0x258000: movss xmm0, dword ptr [0x004D54EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54ECu);
	// 0x258008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x258010: movss [0x004D54C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54C4u, ctx.xmm[0].u32[0]);
	// 0x258018: ret
	return;
}

void sub_258020(X86Context& ctx, uint8_t* base) {
	// 0x258020: movss xmm0, dword ptr [0x004D5544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5544u);
	// 0x258028: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x258030: movss [0x004D550C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D550Cu, ctx.xmm[0].u32[0]);
	// 0x258038: ret
	return;
}

void sub_258040(X86Context& ctx, uint8_t* base) {
	// 0x258040: movss xmm0, dword ptr [0x004D54C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54C4u);
	// 0x258048: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x258050: movss [0x004D5520], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5520u, ctx.xmm[0].u32[0]);
	// 0x258058: ret
	return;
}

void sub_258060(X86Context& ctx, uint8_t* base) {
	// 0x258060: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x258068: movss [0x004D54BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54BCu, ctx.xmm[0].u32[0]);
	// 0x258070: ret
	return;
}

void sub_258080(X86Context& ctx, uint8_t* base) {
	// 0x258080: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x258088: movss [0x004D54F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54F0u, ctx.xmm[0].u32[0]);
	// 0x258090: ret
	return;
}

void sub_2580A0(X86Context& ctx, uint8_t* base) {
	// 0x2580A0: movss xmm0, dword ptr [0x004D54EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54ECu);
	// 0x2580A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2580B0: movss [0x004D54FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54FCu, ctx.xmm[0].u32[0]);
	// 0x2580B8: ret
	return;
}

void sub_2580C0(X86Context& ctx, uint8_t* base) {
	// 0x2580C0: movss xmm0, dword ptr [0x004D5544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5544u);
	// 0x2580C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2580D0: movss [0x004D5548], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5548u, ctx.xmm[0].u32[0]);
	// 0x2580D8: ret
	return;
}

void sub_2580E0(X86Context& ctx, uint8_t* base) {
	// 0x2580E0: movss xmm0, dword ptr [0x004D54FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54FCu);
	// 0x2580E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2580F0: movss [0x004D5534], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5534u, ctx.xmm[0].u32[0]);
	// 0x2580F8: ret
	return;
}

void sub_258100(X86Context& ctx, uint8_t* base) {
	// 0x258100: movss xmm0, dword ptr [0x004D5548]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5548u);
	// 0x258108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x258110: movss [0x004D5558], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5558u, ctx.xmm[0].u32[0]);
	// 0x258118: ret
	return;
}

void sub_258120(X86Context& ctx, uint8_t* base) {
	// 0x258120: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x258128: movss [0x004D54C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54C8u, ctx.xmm[0].u32[0]);
	// 0x258130: ret
	return;
}

void sub_258140(X86Context& ctx, uint8_t* base) {
	// 0x258140: movss xmm0, dword ptr [0x004D54EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54ECu);
	// 0x258148: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x258150: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x258158: movss [0x004D5540], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5540u, ctx.xmm[0].u32[0]);
	// 0x258160: ret
	return;
}

void sub_258170(X86Context& ctx, uint8_t* base) {
	// 0x258170: movss xmm0, dword ptr [0x004D5544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5544u);
	// 0x258178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x258180: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x258188: movss [0x004D54E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54E0u, ctx.xmm[0].u32[0]);
	// 0x258190: ret
	return;
}

void sub_2581A0(X86Context& ctx, uint8_t* base) {
	// 0x2581A0: movss xmm0, dword ptr [0x004D54EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54ECu);
	// 0x2581A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2581B0: movss [0x004D54E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54E4u, ctx.xmm[0].u32[0]);
	// 0x2581B8: ret
	return;
}

void sub_2581C0(X86Context& ctx, uint8_t* base) {
	// 0x2581C0: movss xmm0, dword ptr [0x004D5544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5544u);
	// 0x2581C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2581D0: movss [0x004D554C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D554Cu, ctx.xmm[0].u32[0]);
	// 0x2581D8: ret
	return;
}

void sub_2581E0(X86Context& ctx, uint8_t* base) {
	// 0x2581E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2581E8: movss [0x004D54CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54CCu, ctx.xmm[0].u32[0]);
	// 0x2581F0: ret
	return;
}

void sub_258200(X86Context& ctx, uint8_t* base) {
	// 0x258200: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x258208: movss [0x004D54F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54F8u, ctx.xmm[0].u32[0]);
	// 0x258210: ret
	return;
}

void sub_258220(X86Context& ctx, uint8_t* base) {
	// 0x258220: movss xmm0, dword ptr [0x004D54CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D54CCu);
	// 0x258228: movss [0x004D5560], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5560u, ctx.xmm[0].u32[0]);
	// 0x258230: ret
	return;
}

void sub_258240(X86Context& ctx, uint8_t* base) {
	// 0x258240: movss xmm0, dword ptr [0x004D5544]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5544u);
	// 0x258248: subss xmm0, [0x004D54CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D54CCu);
	// 0x258250: movss [0x004D5524], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5524u, ctx.xmm[0].u32[0]);
	// 0x258258: ret
	return;
}

void sub_258260(X86Context& ctx, uint8_t* base) {
	// 0x258260: movss xmm0, dword ptr [0x004D5524]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5524u);
	// 0x258268: subss xmm0, [0x004D54F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D54F8u);
	// 0x258270: movss [0x004D551C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D551Cu, ctx.xmm[0].u32[0]);
	// 0x258278: ret
	return;
}

void sub_258280(X86Context& ctx, uint8_t* base) {
	// 0x258280: movss xmm0, dword ptr [0x004D554C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D554Cu);
	// 0x258288: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x258290: movss [0x004D5508], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5508u, ctx.xmm[0].u32[0]);
	// 0x258298: ret
	return;
}

void sub_2582A0(X86Context& ctx, uint8_t* base) {
	// 0x2582A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2582A8: movss [0x004D54F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54F4u, ctx.xmm[0].u32[0]);
	// 0x2582B0: ret
	return;
}

void sub_2582C0(X86Context& ctx, uint8_t* base) {
	// 0x2582C0: movss xmm0, dword ptr [0x004D5508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5508u);
	// 0x2582C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2582D0: movss [0x004D553C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D553Cu, ctx.xmm[0].u32[0]);
	// 0x2582D8: ret
	return;
}

void sub_2582E0(X86Context& ctx, uint8_t* base) {
	// 0x2582E0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2582E8: movss [0x004D5510], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5510u, ctx.xmm[0].u32[0]);
	// 0x2582F0: ret
	return;
}

void sub_258300(X86Context& ctx, uint8_t* base) {
	// 0x258300: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x258308: movss [0x004D54E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D54E8u, ctx.xmm[0].u32[0]);
	// 0x258310: ret
	return;
}

void sub_258320(X86Context& ctx, uint8_t* base) {
	// 0x258320: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258328: movss [0x004D5588], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5588u, ctx.xmm[0].u32[0]);
	// 0x258330: ret
	return;
}

void sub_258340(X86Context& ctx, uint8_t* base) {
	// 0x258340: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258348: movss [0x004D5594], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5594u, ctx.xmm[0].u32[0]);
	// 0x258350: ret
	return;
}

void sub_258360(X86Context& ctx, uint8_t* base) {
	// 0x258360: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258368: movss [0x004D5584], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5584u, ctx.xmm[0].u32[0]);
	// 0x258370: ret
	return;
}

void sub_258380(X86Context& ctx, uint8_t* base) {
	// 0x258380: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x258388: movss [0x004D556C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D556Cu, ctx.xmm[0].u32[0]);
	// 0x258390: ret
	return;
}

void sub_2583A0(X86Context& ctx, uint8_t* base) {
	// 0x2583A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2583A8: movss [0x004D558C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D558Cu, ctx.xmm[0].u32[0]);
	// 0x2583B0: ret
	return;
}

void sub_2583C0(X86Context& ctx, uint8_t* base) {
	// 0x2583C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2583C8: movss [0x004D5574], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5574u, ctx.xmm[0].u32[0]);
	// 0x2583D0: ret
	return;
}

void sub_2583E0(X86Context& ctx, uint8_t* base) {
	// 0x2583E0: movss xmm0, dword ptr [0x004D558C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D558Cu);
	// 0x2583E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2583F0: movss [0x004D559C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D559Cu, ctx.xmm[0].u32[0]);
	// 0x2583F8: ret
	return;
}

void sub_258400(X86Context& ctx, uint8_t* base) {
	// 0x258400: movss xmm0, dword ptr [0x004D5574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5574u);
	// 0x258408: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x258410: movss [0x004D5598], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5598u, ctx.xmm[0].u32[0]);
	// 0x258418: ret
	return;
}

void sub_258420(X86Context& ctx, uint8_t* base) {
	// 0x258420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258428: movss [0x004D55AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55ACu, ctx.xmm[0].u32[0]);
	// 0x258430: ret
	return;
}

void sub_258440(X86Context& ctx, uint8_t* base) {
	// 0x258440: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x258448: movss [0x004D55A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55A0u, ctx.xmm[0].u32[0]);
	// 0x258450: ret
	return;
}

void sub_258460(X86Context& ctx, uint8_t* base) {
	// 0x258460: movss xmm0, dword ptr [0x004D55A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55A0u);
	// 0x258468: movss [0x004D55A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55A8u, ctx.xmm[0].u32[0]);
	// 0x258470: ret
	return;
}

void sub_258480(X86Context& ctx, uint8_t* base) {
	// 0x258480: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258488: movss [0x004D5570], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5570u, ctx.xmm[0].u32[0]);
	// 0x258490: ret
	return;
}

void sub_2584A0(X86Context& ctx, uint8_t* base) {
	// 0x2584A0: movss xmm0, dword ptr [0x004D5574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5574u);
	// 0x2584A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2584B0: movss [0x004D55A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55A4u, ctx.xmm[0].u32[0]);
	// 0x2584B8: ret
	return;
}

void sub_2584C0(X86Context& ctx, uint8_t* base) {
	// 0x2584C0: movss xmm0, dword ptr [0x004D5574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5574u);
	// 0x2584C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2584D0: movss [0x004D5580], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5580u, ctx.xmm[0].u32[0]);
	// 0x2584D8: ret
	return;
}

void sub_2584E0(X86Context& ctx, uint8_t* base) {
	// 0x2584E0: movss xmm0, dword ptr [0x004D5574]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5574u);
	// 0x2584E8: subss xmm0, [0x004D5580]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5580u);
	// 0x2584F0: movss [0x004D557C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D557Cu, ctx.xmm[0].u32[0]);
	// 0x2584F8: ret
	return;
}

void sub_258500(X86Context& ctx, uint8_t* base) {
	// 0x258500: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x258508: movss [0x004D5590], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5590u, ctx.xmm[0].u32[0]);
	// 0x258510: ret
	return;
}

void sub_258520(X86Context& ctx, uint8_t* base) {
	// 0x258520: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x258528: movss [0x004D5578], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5578u, ctx.xmm[0].u32[0]);
	// 0x258530: ret
	return;
}

void sub_258540(X86Context& ctx, uint8_t* base) {
	// 0x258540: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258548: movss [0x004D55CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55CCu, ctx.xmm[0].u32[0]);
	// 0x258550: ret
	return;
}

void sub_258560(X86Context& ctx, uint8_t* base) {
	// 0x258560: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258568: movss [0x004D55D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55D8u, ctx.xmm[0].u32[0]);
	// 0x258570: ret
	return;
}

void sub_258580(X86Context& ctx, uint8_t* base) {
	// 0x258580: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258588: movss [0x004D55C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55C8u, ctx.xmm[0].u32[0]);
	// 0x258590: ret
	return;
}

void sub_2585A0(X86Context& ctx, uint8_t* base) {
	// 0x2585A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2585A8: movss [0x004D55B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55B0u, ctx.xmm[0].u32[0]);
	// 0x2585B0: ret
	return;
}

void sub_2585C0(X86Context& ctx, uint8_t* base) {
	// 0x2585C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2585C8: movss [0x004D55D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55D0u, ctx.xmm[0].u32[0]);
	// 0x2585D0: ret
	return;
}

void sub_2585E0(X86Context& ctx, uint8_t* base) {
	// 0x2585E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2585E8: movss [0x004D55B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55B8u, ctx.xmm[0].u32[0]);
	// 0x2585F0: ret
	return;
}

void sub_258600(X86Context& ctx, uint8_t* base) {
	// 0x258600: movss xmm0, dword ptr [0x004D55D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55D0u);
	// 0x258608: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x258610: movss [0x004D55E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55E0u, ctx.xmm[0].u32[0]);
	// 0x258618: ret
	return;
}

void sub_258620(X86Context& ctx, uint8_t* base) {
	// 0x258620: movss xmm0, dword ptr [0x004D55B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55B8u);
	// 0x258628: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x258630: movss [0x004D55DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55DCu, ctx.xmm[0].u32[0]);
	// 0x258638: ret
	return;
}

void sub_258640(X86Context& ctx, uint8_t* base) {
	// 0x258640: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258648: movss [0x004D55F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55F0u, ctx.xmm[0].u32[0]);
	// 0x258650: ret
	return;
}

void sub_258660(X86Context& ctx, uint8_t* base) {
	// 0x258660: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x258668: movss [0x004D55E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55E4u, ctx.xmm[0].u32[0]);
	// 0x258670: ret
	return;
}

void sub_258680(X86Context& ctx, uint8_t* base) {
	// 0x258680: movss xmm0, dword ptr [0x004D55E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55E4u);
	// 0x258688: movss [0x004D55EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55ECu, ctx.xmm[0].u32[0]);
	// 0x258690: ret
	return;
}

void sub_2586A0(X86Context& ctx, uint8_t* base) {
	// 0x2586A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2586A8: movss [0x004D55B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55B4u, ctx.xmm[0].u32[0]);
	// 0x2586B0: ret
	return;
}

void sub_2586C0(X86Context& ctx, uint8_t* base) {
	// 0x2586C0: movss xmm0, dword ptr [0x004D55B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55B8u);
	// 0x2586C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2586D0: movss [0x004D55E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55E8u, ctx.xmm[0].u32[0]);
	// 0x2586D8: ret
	return;
}

void sub_2586E0(X86Context& ctx, uint8_t* base) {
	// 0x2586E0: movss xmm0, dword ptr [0x004D55B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55B8u);
	// 0x2586E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2586F0: movss [0x004D55C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55C4u, ctx.xmm[0].u32[0]);
	// 0x2586F8: ret
	return;
}

void sub_258700(X86Context& ctx, uint8_t* base) {
	// 0x258700: movss xmm0, dword ptr [0x004D55B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D55B8u);
	// 0x258708: subss xmm0, [0x004D55C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D55C4u);
	// 0x258710: movss [0x004D55C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55C0u, ctx.xmm[0].u32[0]);
	// 0x258718: ret
	return;
}

void sub_258720(X86Context& ctx, uint8_t* base) {
	// 0x258720: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x258728: movss [0x004D55D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55D4u, ctx.xmm[0].u32[0]);
	// 0x258730: ret
	return;
}

void sub_258740(X86Context& ctx, uint8_t* base) {
	// 0x258740: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x258748: movss [0x004D55BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55BCu, ctx.xmm[0].u32[0]);
	// 0x258750: ret
	return;
}

void sub_258760(X86Context& ctx, uint8_t* base) {
	// 0x258760: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258768: movss [0x004D55F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55F8u, ctx.xmm[0].u32[0]);
	// 0x258770: ret
	return;
}

void sub_258780(X86Context& ctx, uint8_t* base) {
	// 0x258780: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258788: movss [0x004D55FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55FCu, ctx.xmm[0].u32[0]);
	// 0x258790: ret
	return;
}

void sub_2587A0(X86Context& ctx, uint8_t* base) {
	// 0x2587A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2587A8: movss [0x004D55F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D55F4u, ctx.xmm[0].u32[0]);
	// 0x2587B0: ret
	return;
}

void sub_2587C0(X86Context& ctx, uint8_t* base) {
	// 0x2587C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2587C8: movss [0x004D5604], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5604u, ctx.xmm[0].u32[0]);
	// 0x2587D0: ret
	return;
}

void sub_2587E0(X86Context& ctx, uint8_t* base) {
	// 0x2587E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2587E8: movss [0x004D5608], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5608u, ctx.xmm[0].u32[0]);
	// 0x2587F0: ret
	return;
}

void sub_258800(X86Context& ctx, uint8_t* base) {
	// 0x258800: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258808: movss [0x004D5600], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5600u, ctx.xmm[0].u32[0]);
	// 0x258810: ret
	return;
}

void sub_258820(X86Context& ctx, uint8_t* base) {
	// 0x258820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258828: movss [0x004D5628], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5628u, ctx.xmm[0].u32[0]);
	// 0x258830: ret
	return;
}

void sub_258840(X86Context& ctx, uint8_t* base) {
	// 0x258840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258848: movss [0x004D5634], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5634u, ctx.xmm[0].u32[0]);
	// 0x258850: ret
	return;
}

void sub_258860(X86Context& ctx, uint8_t* base) {
	// 0x258860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258868: movss [0x004D5624], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5624u, ctx.xmm[0].u32[0]);
	// 0x258870: ret
	return;
}

void sub_258880(X86Context& ctx, uint8_t* base) {
	// 0x258880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x258888: movss [0x004D560C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D560Cu, ctx.xmm[0].u32[0]);
	// 0x258890: ret
	return;
}

void sub_2588A0(X86Context& ctx, uint8_t* base) {
	// 0x2588A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2588A8: movss [0x004D562C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D562Cu, ctx.xmm[0].u32[0]);
	// 0x2588B0: ret
	return;
}

void sub_2588C0(X86Context& ctx, uint8_t* base) {
	// 0x2588C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2588C8: movss [0x004D5614], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5614u, ctx.xmm[0].u32[0]);
	// 0x2588D0: ret
	return;
}

void sub_2588E0(X86Context& ctx, uint8_t* base) {
	// 0x2588E0: movss xmm0, dword ptr [0x004D562C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D562Cu);
	// 0x2588E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2588F0: movss [0x004D563C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D563Cu, ctx.xmm[0].u32[0]);
	// 0x2588F8: ret
	return;
}

void sub_258900(X86Context& ctx, uint8_t* base) {
	// 0x258900: movss xmm0, dword ptr [0x004D5614]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5614u);
	// 0x258908: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x258910: movss [0x004D5638], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5638u, ctx.xmm[0].u32[0]);
	// 0x258918: ret
	return;
}

void sub_258920(X86Context& ctx, uint8_t* base) {
	// 0x258920: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258928: movss [0x004D564C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D564Cu, ctx.xmm[0].u32[0]);
	// 0x258930: ret
	return;
}

void sub_258940(X86Context& ctx, uint8_t* base) {
	// 0x258940: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x258948: movss [0x004D5640], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5640u, ctx.xmm[0].u32[0]);
	// 0x258950: ret
	return;
}

void sub_258960(X86Context& ctx, uint8_t* base) {
	// 0x258960: movss xmm0, dword ptr [0x004D5640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5640u);
	// 0x258968: movss [0x004D5648], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5648u, ctx.xmm[0].u32[0]);
	// 0x258970: ret
	return;
}

void sub_258980(X86Context& ctx, uint8_t* base) {
	// 0x258980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258988: movss [0x004D5610], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5610u, ctx.xmm[0].u32[0]);
	// 0x258990: ret
	return;
}

void sub_2589A0(X86Context& ctx, uint8_t* base) {
	// 0x2589A0: movss xmm0, dword ptr [0x004D5614]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5614u);
	// 0x2589A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2589B0: movss [0x004D5644], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5644u, ctx.xmm[0].u32[0]);
	// 0x2589B8: ret
	return;
}

void sub_2589C0(X86Context& ctx, uint8_t* base) {
	// 0x2589C0: movss xmm0, dword ptr [0x004D5614]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5614u);
	// 0x2589C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2589D0: movss [0x004D5620], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5620u, ctx.xmm[0].u32[0]);
	// 0x2589D8: ret
	return;
}

void sub_2589E0(X86Context& ctx, uint8_t* base) {
	// 0x2589E0: movss xmm0, dword ptr [0x004D5614]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5614u);
	// 0x2589E8: subss xmm0, [0x004D5620]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5620u);
	// 0x2589F0: movss [0x004D561C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D561Cu, ctx.xmm[0].u32[0]);
	// 0x2589F8: ret
	return;
}

void sub_258A00(X86Context& ctx, uint8_t* base) {
	// 0x258A00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x258A08: movss [0x004D5630], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5630u, ctx.xmm[0].u32[0]);
	// 0x258A10: ret
	return;
}

void sub_258A20(X86Context& ctx, uint8_t* base) {
	// 0x258A20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x258A28: movss [0x004D5618], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5618u, ctx.xmm[0].u32[0]);
	// 0x258A30: ret
	return;
}

void sub_258A40(X86Context& ctx, uint8_t* base) {
	// 0x258A40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258A48: movss [0x004D5654], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5654u, ctx.xmm[0].u32[0]);
	// 0x258A50: ret
	return;
}

void sub_258A60(X86Context& ctx, uint8_t* base) {
	// 0x258A60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258A68: movss [0x004D5658], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5658u, ctx.xmm[0].u32[0]);
	// 0x258A70: ret
	return;
}

void sub_258A80(X86Context& ctx, uint8_t* base) {
	// 0x258A80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258A88: movss [0x004D5650], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5650u, ctx.xmm[0].u32[0]);
	// 0x258A90: ret
	return;
}

void sub_258AA0(X86Context& ctx, uint8_t* base) {
	// 0x258AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258AA8: movss [0x004D5660], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5660u, ctx.xmm[0].u32[0]);
	// 0x258AB0: ret
	return;
}

void sub_258AC0(X86Context& ctx, uint8_t* base) {
	// 0x258AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258AC8: movss [0x004D5664], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5664u, ctx.xmm[0].u32[0]);
	// 0x258AD0: ret
	return;
}

void sub_258AE0(X86Context& ctx, uint8_t* base) {
	// 0x258AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258AE8: movss [0x004D565C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D565Cu, ctx.xmm[0].u32[0]);
	// 0x258AF0: ret
	return;
}

void sub_258B00(X86Context& ctx, uint8_t* base) {
	// 0x258B00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258B08: movss [0x004D566C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D566Cu, ctx.xmm[0].u32[0]);
	// 0x258B10: ret
	return;
}

void sub_258B20(X86Context& ctx, uint8_t* base) {
	// 0x258B20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258B28: movss [0x004D5670], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5670u, ctx.xmm[0].u32[0]);
	// 0x258B30: ret
	return;
}

void sub_258B40(X86Context& ctx, uint8_t* base) {
	// 0x258B40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258B48: movss [0x004D5668], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5668u, ctx.xmm[0].u32[0]);
	// 0x258B50: ret
	return;
}

void sub_258B60(X86Context& ctx, uint8_t* base) {
	// 0x258B60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258B68: movss [0x004D5690], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5690u, ctx.xmm[0].u32[0]);
	// 0x258B70: ret
	return;
}

void sub_258B80(X86Context& ctx, uint8_t* base) {
	// 0x258B80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258B88: movss [0x004D569C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D569Cu, ctx.xmm[0].u32[0]);
	// 0x258B90: ret
	return;
}

void sub_258BA0(X86Context& ctx, uint8_t* base) {
	// 0x258BA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258BA8: movss [0x004D568C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D568Cu, ctx.xmm[0].u32[0]);
	// 0x258BB0: ret
	return;
}

void sub_258BC0(X86Context& ctx, uint8_t* base) {
	// 0x258BC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x258BC8: movss [0x004D5674], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5674u, ctx.xmm[0].u32[0]);
	// 0x258BD0: ret
	return;
}

void sub_258BE0(X86Context& ctx, uint8_t* base) {
	// 0x258BE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x258BE8: movss [0x004D5694], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5694u, ctx.xmm[0].u32[0]);
	// 0x258BF0: ret
	return;
}

void sub_258C00(X86Context& ctx, uint8_t* base) {
	// 0x258C00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x258C08: movss [0x004D567C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D567Cu, ctx.xmm[0].u32[0]);
	// 0x258C10: ret
	return;
}

void sub_258C20(X86Context& ctx, uint8_t* base) {
	// 0x258C20: movss xmm0, dword ptr [0x004D5694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5694u);
	// 0x258C28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x258C30: movss [0x004D56A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56A4u, ctx.xmm[0].u32[0]);
	// 0x258C38: ret
	return;
}

void sub_258C40(X86Context& ctx, uint8_t* base) {
	// 0x258C40: movss xmm0, dword ptr [0x004D567C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D567Cu);
	// 0x258C48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x258C50: movss [0x004D56A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56A0u, ctx.xmm[0].u32[0]);
	// 0x258C58: ret
	return;
}

void sub_258C60(X86Context& ctx, uint8_t* base) {
	// 0x258C60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258C68: movss [0x004D56B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56B4u, ctx.xmm[0].u32[0]);
	// 0x258C70: ret
	return;
}

void sub_258C80(X86Context& ctx, uint8_t* base) {
	// 0x258C80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x258C88: movss [0x004D56A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56A8u, ctx.xmm[0].u32[0]);
	// 0x258C90: ret
	return;
}

void sub_258CA0(X86Context& ctx, uint8_t* base) {
	// 0x258CA0: movss xmm0, dword ptr [0x004D56A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D56A8u);
	// 0x258CA8: movss [0x004D56B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56B0u, ctx.xmm[0].u32[0]);
	// 0x258CB0: ret
	return;
}

void sub_258CC0(X86Context& ctx, uint8_t* base) {
	// 0x258CC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258CC8: movss [0x004D5678], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5678u, ctx.xmm[0].u32[0]);
	// 0x258CD0: ret
	return;
}

void sub_258CE0(X86Context& ctx, uint8_t* base) {
	// 0x258CE0: movss xmm0, dword ptr [0x004D567C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D567Cu);
	// 0x258CE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x258CF0: movss [0x004D56AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56ACu, ctx.xmm[0].u32[0]);
	// 0x258CF8: ret
	return;
}

void sub_258D00(X86Context& ctx, uint8_t* base) {
	// 0x258D00: movss xmm0, dword ptr [0x004D567C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D567Cu);
	// 0x258D08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x258D10: movss [0x004D5688], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5688u, ctx.xmm[0].u32[0]);
	// 0x258D18: ret
	return;
}

void sub_258D20(X86Context& ctx, uint8_t* base) {
	// 0x258D20: movss xmm0, dword ptr [0x004D567C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D567Cu);
	// 0x258D28: subss xmm0, [0x004D5688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5688u);
	// 0x258D30: movss [0x004D5684], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5684u, ctx.xmm[0].u32[0]);
	// 0x258D38: ret
	return;
}

void sub_258D40(X86Context& ctx, uint8_t* base) {
	// 0x258D40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x258D48: movss [0x004D5698], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5698u, ctx.xmm[0].u32[0]);
	// 0x258D50: ret
	return;
}

void sub_258D60(X86Context& ctx, uint8_t* base) {
	// 0x258D60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x258D68: movss [0x004D5680], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5680u, ctx.xmm[0].u32[0]);
	// 0x258D70: ret
	return;
}

void sub_258D80(X86Context& ctx, uint8_t* base) {
	// 0x258D80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258D88: movss [0x004D56BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56BCu, ctx.xmm[0].u32[0]);
	// 0x258D90: ret
	return;
}

void sub_258DA0(X86Context& ctx, uint8_t* base) {
	// 0x258DA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258DA8: movss [0x004D56C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56C0u, ctx.xmm[0].u32[0]);
	// 0x258DB0: ret
	return;
}

void sub_258DC0(X86Context& ctx, uint8_t* base) {
	// 0x258DC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258DC8: movss [0x004D56B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56B8u, ctx.xmm[0].u32[0]);
	// 0x258DD0: ret
	return;
}

void sub_258DE0(X86Context& ctx, uint8_t* base) {
	// 0x258DE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258DE8: movss [0x004D56C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56C8u, ctx.xmm[0].u32[0]);
	// 0x258DF0: ret
	return;
}

void sub_258E00(X86Context& ctx, uint8_t* base) {
	// 0x258E00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258E08: movss [0x004D56CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56CCu, ctx.xmm[0].u32[0]);
	// 0x258E10: ret
	return;
}

void sub_258E20(X86Context& ctx, uint8_t* base) {
	// 0x258E20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258E28: movss [0x004D56C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56C4u, ctx.xmm[0].u32[0]);
	// 0x258E30: ret
	return;
}

void sub_258E40(X86Context& ctx, uint8_t* base) {
	// 0x258E40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258E48: movss [0x004D56D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56D4u, ctx.xmm[0].u32[0]);
	// 0x258E50: ret
	return;
}

void sub_258E60(X86Context& ctx, uint8_t* base) {
	// 0x258E60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258E68: movss [0x004D56D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56D8u, ctx.xmm[0].u32[0]);
	// 0x258E70: ret
	return;
}

void sub_258E80(X86Context& ctx, uint8_t* base) {
	// 0x258E80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258E88: movss [0x004D56D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56D0u, ctx.xmm[0].u32[0]);
	// 0x258E90: ret
	return;
}

void sub_258EA0(X86Context& ctx, uint8_t* base) {
	// 0x258EA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x258EA8: movss [0x004D56F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56F8u, ctx.xmm[0].u32[0]);
	// 0x258EB0: ret
	return;
}

void sub_258EC0(X86Context& ctx, uint8_t* base) {
	// 0x258EC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x258EC8: movss [0x004D5704], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5704u, ctx.xmm[0].u32[0]);
	// 0x258ED0: ret
	return;
}

void sub_258EE0(X86Context& ctx, uint8_t* base) {
	// 0x258EE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x258EE8: movss [0x004D56F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56F4u, ctx.xmm[0].u32[0]);
	// 0x258EF0: ret
	return;
}

void sub_258F00(X86Context& ctx, uint8_t* base) {
	// 0x258F00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x258F08: movss [0x004D56DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56DCu, ctx.xmm[0].u32[0]);
	// 0x258F10: ret
	return;
}

void sub_258F20(X86Context& ctx, uint8_t* base) {
	// 0x258F20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x258F28: movss [0x004D56FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56FCu, ctx.xmm[0].u32[0]);
	// 0x258F30: ret
	return;
}

void sub_258F40(X86Context& ctx, uint8_t* base) {
	// 0x258F40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x258F48: movss [0x004D56E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56E4u, ctx.xmm[0].u32[0]);
	// 0x258F50: ret
	return;
}

void sub_258F60(X86Context& ctx, uint8_t* base) {
	// 0x258F60: movss xmm0, dword ptr [0x004D56FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D56FCu);
	// 0x258F68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x258F70: movss [0x004D570C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D570Cu, ctx.xmm[0].u32[0]);
	// 0x258F78: ret
	return;
}

void sub_258F80(X86Context& ctx, uint8_t* base) {
	// 0x258F80: movss xmm0, dword ptr [0x004D56E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D56E4u);
	// 0x258F88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x258F90: movss [0x004D5708], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5708u, ctx.xmm[0].u32[0]);
	// 0x258F98: ret
	return;
}

void sub_258FA0(X86Context& ctx, uint8_t* base) {
	// 0x258FA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x258FA8: movss [0x004D571C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D571Cu, ctx.xmm[0].u32[0]);
	// 0x258FB0: ret
	return;
}

void sub_258FC0(X86Context& ctx, uint8_t* base) {
	// 0x258FC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x258FC8: movss [0x004D5710], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5710u, ctx.xmm[0].u32[0]);
	// 0x258FD0: ret
	return;
}

void sub_258FE0(X86Context& ctx, uint8_t* base) {
	// 0x258FE0: movss xmm0, dword ptr [0x004D5710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5710u);
	// 0x258FE8: movss [0x004D5718], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5718u, ctx.xmm[0].u32[0]);
	// 0x258FF0: ret
	return;
}

void sub_259000(X86Context& ctx, uint8_t* base) {
	// 0x259000: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259008: movss [0x004D56E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56E0u, ctx.xmm[0].u32[0]);
	// 0x259010: ret
	return;
}

void sub_259020(X86Context& ctx, uint8_t* base) {
	// 0x259020: movss xmm0, dword ptr [0x004D56E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D56E4u);
	// 0x259028: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x259030: movss [0x004D5714], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5714u, ctx.xmm[0].u32[0]);
	// 0x259038: ret
	return;
}

void sub_259040(X86Context& ctx, uint8_t* base) {
	// 0x259040: movss xmm0, dword ptr [0x004D56E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D56E4u);
	// 0x259048: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259050: movss [0x004D56F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56F0u, ctx.xmm[0].u32[0]);
	// 0x259058: ret
	return;
}

void sub_259060(X86Context& ctx, uint8_t* base) {
	// 0x259060: movss xmm0, dword ptr [0x004D56E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D56E4u);
	// 0x259068: subss xmm0, [0x004D56F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D56F0u);
	// 0x259070: movss [0x004D56EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56ECu, ctx.xmm[0].u32[0]);
	// 0x259078: ret
	return;
}

void sub_259080(X86Context& ctx, uint8_t* base) {
	// 0x259080: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x259088: movss [0x004D5700], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5700u, ctx.xmm[0].u32[0]);
	// 0x259090: ret
	return;
}

void sub_2590A0(X86Context& ctx, uint8_t* base) {
	// 0x2590A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2590A8: movss [0x004D56E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D56E8u, ctx.xmm[0].u32[0]);
	// 0x2590B0: ret
	return;
}

void sub_2590C0(X86Context& ctx, uint8_t* base) {
	// 0x2590C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2590C8: movss [0x004D573C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D573Cu, ctx.xmm[0].u32[0]);
	// 0x2590D0: ret
	return;
}

void sub_2590E0(X86Context& ctx, uint8_t* base) {
	// 0x2590E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2590E8: movss [0x004D5748], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5748u, ctx.xmm[0].u32[0]);
	// 0x2590F0: ret
	return;
}

void sub_259100(X86Context& ctx, uint8_t* base) {
	// 0x259100: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x259108: movss [0x004D5738], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5738u, ctx.xmm[0].u32[0]);
	// 0x259110: ret
	return;
}

void sub_259120(X86Context& ctx, uint8_t* base) {
	// 0x259120: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x259128: movss [0x004D5720], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5720u, ctx.xmm[0].u32[0]);
	// 0x259130: ret
	return;
}

void sub_259140(X86Context& ctx, uint8_t* base) {
	// 0x259140: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x259148: movss [0x004D5740], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5740u, ctx.xmm[0].u32[0]);
	// 0x259150: ret
	return;
}

void sub_259160(X86Context& ctx, uint8_t* base) {
	// 0x259160: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259168: movss [0x004D5728], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5728u, ctx.xmm[0].u32[0]);
	// 0x259170: ret
	return;
}

void sub_259180(X86Context& ctx, uint8_t* base) {
	// 0x259180: movss xmm0, dword ptr [0x004D5740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5740u);
	// 0x259188: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x259190: movss [0x004D5750], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5750u, ctx.xmm[0].u32[0]);
	// 0x259198: ret
	return;
}

void sub_2591A0(X86Context& ctx, uint8_t* base) {
	// 0x2591A0: movss xmm0, dword ptr [0x004D5728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5728u);
	// 0x2591A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2591B0: movss [0x004D574C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D574Cu, ctx.xmm[0].u32[0]);
	// 0x2591B8: ret
	return;
}

void sub_2591C0(X86Context& ctx, uint8_t* base) {
	// 0x2591C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2591C8: movss [0x004D5760], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5760u, ctx.xmm[0].u32[0]);
	// 0x2591D0: ret
	return;
}

void sub_2591E0(X86Context& ctx, uint8_t* base) {
	// 0x2591E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2591E8: movss [0x004D5754], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5754u, ctx.xmm[0].u32[0]);
	// 0x2591F0: ret
	return;
}

void sub_259200(X86Context& ctx, uint8_t* base) {
	// 0x259200: movss xmm0, dword ptr [0x004D5754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5754u);
	// 0x259208: movss [0x004D575C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D575Cu, ctx.xmm[0].u32[0]);
	// 0x259210: ret
	return;
}

void sub_259220(X86Context& ctx, uint8_t* base) {
	// 0x259220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259228: movss [0x004D5724], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5724u, ctx.xmm[0].u32[0]);
	// 0x259230: ret
	return;
}

void sub_259240(X86Context& ctx, uint8_t* base) {
	// 0x259240: movss xmm0, dword ptr [0x004D5728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5728u);
	// 0x259248: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x259250: movss [0x004D5758], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5758u, ctx.xmm[0].u32[0]);
	// 0x259258: ret
	return;
}

void sub_259260(X86Context& ctx, uint8_t* base) {
	// 0x259260: movss xmm0, dword ptr [0x004D5728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5728u);
	// 0x259268: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259270: movss [0x004D5734], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5734u, ctx.xmm[0].u32[0]);
	// 0x259278: ret
	return;
}

void sub_259280(X86Context& ctx, uint8_t* base) {
	// 0x259280: movss xmm0, dword ptr [0x004D5728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5728u);
	// 0x259288: subss xmm0, [0x004D5734]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5734u);
	// 0x259290: movss [0x004D5730], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5730u, ctx.xmm[0].u32[0]);
	// 0x259298: ret
	return;
}

void sub_2592A0(X86Context& ctx, uint8_t* base) {
	// 0x2592A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2592A8: movss [0x004D5744], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5744u, ctx.xmm[0].u32[0]);
	// 0x2592B0: ret
	return;
}

void sub_2592C0(X86Context& ctx, uint8_t* base) {
	// 0x2592C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2592C8: movss [0x004D572C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D572Cu, ctx.xmm[0].u32[0]);
	// 0x2592D0: ret
	return;
}

void sub_2592E0(X86Context& ctx, uint8_t* base) {
	// 0x2592E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2592E8: movss [0x004D5780], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5780u, ctx.xmm[0].u32[0]);
	// 0x2592F0: ret
	return;
}

void sub_259300(X86Context& ctx, uint8_t* base) {
	// 0x259300: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259308: movss [0x004D578C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D578Cu, ctx.xmm[0].u32[0]);
	// 0x259310: ret
	return;
}

void sub_259320(X86Context& ctx, uint8_t* base) {
	// 0x259320: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x259328: movss [0x004D577C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D577Cu, ctx.xmm[0].u32[0]);
	// 0x259330: ret
	return;
}

void sub_259340(X86Context& ctx, uint8_t* base) {
	// 0x259340: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x259348: movss [0x004D5764], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5764u, ctx.xmm[0].u32[0]);
	// 0x259350: ret
	return;
}

void sub_259360(X86Context& ctx, uint8_t* base) {
	// 0x259360: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x259368: movss [0x004D5784], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5784u, ctx.xmm[0].u32[0]);
	// 0x259370: ret
	return;
}

void sub_259380(X86Context& ctx, uint8_t* base) {
	// 0x259380: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259388: movss [0x004D576C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D576Cu, ctx.xmm[0].u32[0]);
	// 0x259390: ret
	return;
}

void sub_2593A0(X86Context& ctx, uint8_t* base) {
	// 0x2593A0: movss xmm0, dword ptr [0x004D5784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5784u);
	// 0x2593A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2593B0: movss [0x004D5794], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5794u, ctx.xmm[0].u32[0]);
	// 0x2593B8: ret
	return;
}

void sub_2593C0(X86Context& ctx, uint8_t* base) {
	// 0x2593C0: movss xmm0, dword ptr [0x004D576C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D576Cu);
	// 0x2593C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2593D0: movss [0x004D5790], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5790u, ctx.xmm[0].u32[0]);
	// 0x2593D8: ret
	return;
}

void sub_2593E0(X86Context& ctx, uint8_t* base) {
	// 0x2593E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2593E8: movss [0x004D57A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57A4u, ctx.xmm[0].u32[0]);
	// 0x2593F0: ret
	return;
}

void sub_259400(X86Context& ctx, uint8_t* base) {
	// 0x259400: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x259408: movss [0x004D5798], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5798u, ctx.xmm[0].u32[0]);
	// 0x259410: ret
	return;
}

void sub_259420(X86Context& ctx, uint8_t* base) {
	// 0x259420: movss xmm0, dword ptr [0x004D5798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5798u);
	// 0x259428: movss [0x004D57A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57A0u, ctx.xmm[0].u32[0]);
	// 0x259430: ret
	return;
}

void sub_259440(X86Context& ctx, uint8_t* base) {
	// 0x259440: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259448: movss [0x004D5768], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5768u, ctx.xmm[0].u32[0]);
	// 0x259450: ret
	return;
}

void sub_259460(X86Context& ctx, uint8_t* base) {
	// 0x259460: movss xmm0, dword ptr [0x004D576C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D576Cu);
	// 0x259468: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x259470: movss [0x004D579C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D579Cu, ctx.xmm[0].u32[0]);
	// 0x259478: ret
	return;
}

void sub_259480(X86Context& ctx, uint8_t* base) {
	// 0x259480: movss xmm0, dword ptr [0x004D576C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D576Cu);
	// 0x259488: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259490: movss [0x004D5778], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5778u, ctx.xmm[0].u32[0]);
	// 0x259498: ret
	return;
}

void sub_2594A0(X86Context& ctx, uint8_t* base) {
	// 0x2594A0: movss xmm0, dword ptr [0x004D576C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D576Cu);
	// 0x2594A8: subss xmm0, [0x004D5778]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5778u);
	// 0x2594B0: movss [0x004D5774], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5774u, ctx.xmm[0].u32[0]);
	// 0x2594B8: ret
	return;
}

void sub_2594C0(X86Context& ctx, uint8_t* base) {
	// 0x2594C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2594C8: movss [0x004D5788], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5788u, ctx.xmm[0].u32[0]);
	// 0x2594D0: ret
	return;
}

void sub_2594E0(X86Context& ctx, uint8_t* base) {
	// 0x2594E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2594E8: movss [0x004D5770], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5770u, ctx.xmm[0].u32[0]);
	// 0x2594F0: ret
	return;
}

void sub_259500(X86Context& ctx, uint8_t* base) {
	// 0x259500: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x259508: movss [0x004D57AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57ACu, ctx.xmm[0].u32[0]);
	// 0x259510: ret
	return;
}

void sub_259520(X86Context& ctx, uint8_t* base) {
	// 0x259520: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259528: movss [0x004D57B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57B0u, ctx.xmm[0].u32[0]);
	// 0x259530: ret
	return;
}

void sub_259540(X86Context& ctx, uint8_t* base) {
	// 0x259540: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x259548: movss [0x004D57A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57A8u, ctx.xmm[0].u32[0]);
	// 0x259550: ret
	return;
}

void sub_259560(X86Context& ctx, uint8_t* base) {
	// 0x259560: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x259568: movss [0x004D57D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57D0u, ctx.xmm[0].u32[0]);
	// 0x259570: ret
	return;
}

void sub_259580(X86Context& ctx, uint8_t* base) {
	// 0x259580: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259588: movss [0x004D57DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57DCu, ctx.xmm[0].u32[0]);
	// 0x259590: ret
	return;
}

void sub_2595A0(X86Context& ctx, uint8_t* base) {
	// 0x2595A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2595A8: movss [0x004D57CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57CCu, ctx.xmm[0].u32[0]);
	// 0x2595B0: ret
	return;
}

void sub_2595C0(X86Context& ctx, uint8_t* base) {
	// 0x2595C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2595C8: movss [0x004D57B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57B4u, ctx.xmm[0].u32[0]);
	// 0x2595D0: ret
	return;
}

void sub_2595E0(X86Context& ctx, uint8_t* base) {
	// 0x2595E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2595E8: movss [0x004D57D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57D4u, ctx.xmm[0].u32[0]);
	// 0x2595F0: ret
	return;
}

void sub_259600(X86Context& ctx, uint8_t* base) {
	// 0x259600: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259608: movss [0x004D57BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57BCu, ctx.xmm[0].u32[0]);
	// 0x259610: ret
	return;
}

void sub_259620(X86Context& ctx, uint8_t* base) {
	// 0x259620: movss xmm0, dword ptr [0x004D57D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D57D4u);
	// 0x259628: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x259630: movss [0x004D57E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57E4u, ctx.xmm[0].u32[0]);
	// 0x259638: ret
	return;
}

void sub_259640(X86Context& ctx, uint8_t* base) {
	// 0x259640: movss xmm0, dword ptr [0x004D57BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D57BCu);
	// 0x259648: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x259650: movss [0x004D57E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57E0u, ctx.xmm[0].u32[0]);
	// 0x259658: ret
	return;
}

void sub_259660(X86Context& ctx, uint8_t* base) {
	// 0x259660: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259668: movss [0x004D57F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57F4u, ctx.xmm[0].u32[0]);
	// 0x259670: ret
	return;
}

void sub_259680(X86Context& ctx, uint8_t* base) {
	// 0x259680: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x259688: movss [0x004D57E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57E8u, ctx.xmm[0].u32[0]);
	// 0x259690: ret
	return;
}

void sub_2596A0(X86Context& ctx, uint8_t* base) {
	// 0x2596A0: movss xmm0, dword ptr [0x004D57E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D57E8u);
	// 0x2596A8: movss [0x004D57F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57F0u, ctx.xmm[0].u32[0]);
	// 0x2596B0: ret
	return;
}

void sub_2596C0(X86Context& ctx, uint8_t* base) {
	// 0x2596C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2596C8: movss [0x004D57B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57B8u, ctx.xmm[0].u32[0]);
	// 0x2596D0: ret
	return;
}

void sub_2596E0(X86Context& ctx, uint8_t* base) {
	// 0x2596E0: movss xmm0, dword ptr [0x004D57BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D57BCu);
	// 0x2596E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2596F0: movss [0x004D57EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57ECu, ctx.xmm[0].u32[0]);
	// 0x2596F8: ret
	return;
}

void sub_259700(X86Context& ctx, uint8_t* base) {
	// 0x259700: movss xmm0, dword ptr [0x004D57BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D57BCu);
	// 0x259708: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259710: movss [0x004D57C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57C8u, ctx.xmm[0].u32[0]);
	// 0x259718: ret
	return;
}

void sub_259720(X86Context& ctx, uint8_t* base) {
	// 0x259720: movss xmm0, dword ptr [0x004D57BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D57BCu);
	// 0x259728: subss xmm0, [0x004D57C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D57C8u);
	// 0x259730: movss [0x004D57C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57C4u, ctx.xmm[0].u32[0]);
	// 0x259738: ret
	return;
}

void sub_259740(X86Context& ctx, uint8_t* base) {
	// 0x259740: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x259748: movss [0x004D57D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57D8u, ctx.xmm[0].u32[0]);
	// 0x259750: ret
	return;
}

void sub_259760(X86Context& ctx, uint8_t* base) {
	// 0x259760: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x259768: movss [0x004D57C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57C0u, ctx.xmm[0].u32[0]);
	// 0x259770: ret
	return;
}

void sub_259780(X86Context& ctx, uint8_t* base) {
	// 0x259780: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259788: movss [0x004D581C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D581Cu, ctx.xmm[0].u32[0]);
	// 0x259790: ret
	return;
}

void sub_2597A0(X86Context& ctx, uint8_t* base) {
	// 0x2597A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2597A8: movss [0x004D5810], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5810u, ctx.xmm[0].u32[0]);
	// 0x2597B0: ret
	return;
}

void sub_2597C0(X86Context& ctx, uint8_t* base) {
	// 0x2597C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2597C8: movss [0x004D5814], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5814u, ctx.xmm[0].u32[0]);
	// 0x2597D0: ret
	return;
}

void sub_2597E0(X86Context& ctx, uint8_t* base) {
	// 0x2597E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2597E8: movss [0x004D57F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57F8u, ctx.xmm[0].u32[0]);
	// 0x2597F0: ret
	return;
}

void sub_259800(X86Context& ctx, uint8_t* base) {
	// 0x259800: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x259808: movss [0x004D5818], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5818u, ctx.xmm[0].u32[0]);
	// 0x259810: ret
	return;
}

void sub_259820(X86Context& ctx, uint8_t* base) {
	// 0x259820: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259828: movss [0x004D5800], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5800u, ctx.xmm[0].u32[0]);
	// 0x259830: ret
	return;
}

void sub_259840(X86Context& ctx, uint8_t* base) {
	// 0x259840: movss xmm0, dword ptr [0x004D5818]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5818u);
	// 0x259848: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x259850: movss [0x004D5828], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5828u, ctx.xmm[0].u32[0]);
	// 0x259858: ret
	return;
}

void sub_259860(X86Context& ctx, uint8_t* base) {
	// 0x259860: movss xmm0, dword ptr [0x004D5800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5800u);
	// 0x259868: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x259870: movss [0x004D5824], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5824u, ctx.xmm[0].u32[0]);
	// 0x259878: ret
	return;
}

void sub_259880(X86Context& ctx, uint8_t* base) {
	// 0x259880: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259888: movss [0x004D5838], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5838u, ctx.xmm[0].u32[0]);
	// 0x259890: ret
	return;
}

void sub_2598A0(X86Context& ctx, uint8_t* base) {
	// 0x2598A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2598A8: movss [0x004D582C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D582Cu, ctx.xmm[0].u32[0]);
	// 0x2598B0: ret
	return;
}

void sub_2598C0(X86Context& ctx, uint8_t* base) {
	// 0x2598C0: movss xmm0, dword ptr [0x004D582C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D582Cu);
	// 0x2598C8: movss [0x004D5834], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5834u, ctx.xmm[0].u32[0]);
	// 0x2598D0: ret
	return;
}

void sub_2598E0(X86Context& ctx, uint8_t* base) {
	// 0x2598E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2598E8: movss [0x004D57FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D57FCu, ctx.xmm[0].u32[0]);
	// 0x2598F0: ret
	return;
}

void sub_259900(X86Context& ctx, uint8_t* base) {
	// 0x259900: movss xmm0, dword ptr [0x004D5800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5800u);
	// 0x259908: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x259910: movss [0x004D5830], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5830u, ctx.xmm[0].u32[0]);
	// 0x259918: ret
	return;
}

void sub_259920(X86Context& ctx, uint8_t* base) {
	// 0x259920: movss xmm0, dword ptr [0x004D5800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5800u);
	// 0x259928: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259930: movss [0x004D580C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D580Cu, ctx.xmm[0].u32[0]);
	// 0x259938: ret
	return;
}

void sub_259940(X86Context& ctx, uint8_t* base) {
	// 0x259940: movss xmm0, dword ptr [0x004D5800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5800u);
	// 0x259948: subss xmm0, [0x004D580C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D580Cu);
	// 0x259950: movss [0x004D5808], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5808u, ctx.xmm[0].u32[0]);
	// 0x259958: ret
	return;
}

void sub_259960(X86Context& ctx, uint8_t* base) {
	// 0x259960: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x259968: movss [0x004D5820], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5820u, ctx.xmm[0].u32[0]);
	// 0x259970: ret
	return;
}

void sub_259980(X86Context& ctx, uint8_t* base) {
	// 0x259980: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x259988: movss [0x004D5804], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5804u, ctx.xmm[0].u32[0]);
	// 0x259990: ret
	return;
}

void sub_2599A0(X86Context& ctx, uint8_t* base) {
	// 0x2599A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2599A8: movss [0x004D5860], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5860u, ctx.xmm[0].u32[0]);
	// 0x2599B0: ret
	return;
}

void sub_2599C0(X86Context& ctx, uint8_t* base) {
	// 0x2599C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2599C8: movss [0x004D5854], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5854u, ctx.xmm[0].u32[0]);
	// 0x2599D0: ret
	return;
}

void sub_2599E0(X86Context& ctx, uint8_t* base) {
	// 0x2599E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2599E8: movss [0x004D5858], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5858u, ctx.xmm[0].u32[0]);
	// 0x2599F0: ret
	return;
}

void sub_259A00(X86Context& ctx, uint8_t* base) {
	// 0x259A00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x259A08: movss [0x004D583C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D583Cu, ctx.xmm[0].u32[0]);
	// 0x259A10: ret
	return;
}

void sub_259A20(X86Context& ctx, uint8_t* base) {
	// 0x259A20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x259A28: movss [0x004D585C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D585Cu, ctx.xmm[0].u32[0]);
	// 0x259A30: ret
	return;
}

void sub_259A40(X86Context& ctx, uint8_t* base) {
	// 0x259A40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259A48: movss [0x004D5844], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5844u, ctx.xmm[0].u32[0]);
	// 0x259A50: ret
	return;
}

void sub_259A60(X86Context& ctx, uint8_t* base) {
	// 0x259A60: movss xmm0, dword ptr [0x004D585C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D585Cu);
	// 0x259A68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x259A70: movss [0x004D586C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D586Cu, ctx.xmm[0].u32[0]);
	// 0x259A78: ret
	return;
}

void sub_259A80(X86Context& ctx, uint8_t* base) {
	// 0x259A80: movss xmm0, dword ptr [0x004D5844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5844u);
	// 0x259A88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x259A90: movss [0x004D5868], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5868u, ctx.xmm[0].u32[0]);
	// 0x259A98: ret
	return;
}

void sub_259AA0(X86Context& ctx, uint8_t* base) {
	// 0x259AA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259AA8: movss [0x004D587C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D587Cu, ctx.xmm[0].u32[0]);
	// 0x259AB0: ret
	return;
}

void sub_259AC0(X86Context& ctx, uint8_t* base) {
	// 0x259AC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x259AC8: movss [0x004D5870], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5870u, ctx.xmm[0].u32[0]);
	// 0x259AD0: ret
	return;
}

void sub_259AE0(X86Context& ctx, uint8_t* base) {
	// 0x259AE0: movss xmm0, dword ptr [0x004D5870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5870u);
	// 0x259AE8: movss [0x004D5878], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5878u, ctx.xmm[0].u32[0]);
	// 0x259AF0: ret
	return;
}

void sub_259B00(X86Context& ctx, uint8_t* base) {
	// 0x259B00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259B08: movss [0x004D5840], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5840u, ctx.xmm[0].u32[0]);
	// 0x259B10: ret
	return;
}

void sub_259B20(X86Context& ctx, uint8_t* base) {
	// 0x259B20: movss xmm0, dword ptr [0x004D5844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5844u);
	// 0x259B28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x259B30: movss [0x004D5874], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5874u, ctx.xmm[0].u32[0]);
	// 0x259B38: ret
	return;
}

void sub_259B40(X86Context& ctx, uint8_t* base) {
	// 0x259B40: movss xmm0, dword ptr [0x004D5844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5844u);
	// 0x259B48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259B50: movss [0x004D5850], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5850u, ctx.xmm[0].u32[0]);
	// 0x259B58: ret
	return;
}

void sub_259B60(X86Context& ctx, uint8_t* base) {
	// 0x259B60: movss xmm0, dword ptr [0x004D5844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5844u);
	// 0x259B68: subss xmm0, [0x004D5850]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5850u);
	// 0x259B70: movss [0x004D584C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D584Cu, ctx.xmm[0].u32[0]);
	// 0x259B78: ret
	return;
}

void sub_259B80(X86Context& ctx, uint8_t* base) {
	// 0x259B80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x259B88: movss [0x004D5864], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5864u, ctx.xmm[0].u32[0]);
	// 0x259B90: ret
	return;
}

void sub_259BA0(X86Context& ctx, uint8_t* base) {
	// 0x259BA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x259BA8: movss [0x004D5848], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5848u, ctx.xmm[0].u32[0]);
	// 0x259BB0: ret
	return;
}

