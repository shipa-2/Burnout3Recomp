#include "x86_recomp_shared.h"

void sub_259BC0(X86Context& ctx, uint8_t* base) {
	// 0x259BC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x259BC8: movss [0x004D5884], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5884u, ctx.xmm[0].u32[0]);
	// 0x259BD0: ret
	return;
}

void sub_259BE0(X86Context& ctx, uint8_t* base) {
	// 0x259BE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259BE8: movss [0x004D5888], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5888u, ctx.xmm[0].u32[0]);
	// 0x259BF0: ret
	return;
}

void sub_259C00(X86Context& ctx, uint8_t* base) {
	// 0x259C00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x259C08: movss [0x004D5880], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5880u, ctx.xmm[0].u32[0]);
	// 0x259C10: ret
	return;
}

void sub_259C20(X86Context& ctx, uint8_t* base) {
	// 0x259C20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x259C28: movss [0x004D58A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58A8u, ctx.xmm[0].u32[0]);
	// 0x259C30: ret
	return;
}

void sub_259C40(X86Context& ctx, uint8_t* base) {
	// 0x259C40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259C48: movss [0x004D58B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58B4u, ctx.xmm[0].u32[0]);
	// 0x259C50: ret
	return;
}

void sub_259C60(X86Context& ctx, uint8_t* base) {
	// 0x259C60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x259C68: movss [0x004D58A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58A4u, ctx.xmm[0].u32[0]);
	// 0x259C70: ret
	return;
}

void sub_259C80(X86Context& ctx, uint8_t* base) {
	// 0x259C80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x259C88: movss [0x004D588C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D588Cu, ctx.xmm[0].u32[0]);
	// 0x259C90: ret
	return;
}

void sub_259CA0(X86Context& ctx, uint8_t* base) {
	// 0x259CA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x259CA8: movss [0x004D58AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58ACu, ctx.xmm[0].u32[0]);
	// 0x259CB0: ret
	return;
}

void sub_259CC0(X86Context& ctx, uint8_t* base) {
	// 0x259CC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259CC8: movss [0x004D5894], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5894u, ctx.xmm[0].u32[0]);
	// 0x259CD0: ret
	return;
}

void sub_259CE0(X86Context& ctx, uint8_t* base) {
	// 0x259CE0: movss xmm0, dword ptr [0x004D58AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D58ACu);
	// 0x259CE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x259CF0: movss [0x004D58BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58BCu, ctx.xmm[0].u32[0]);
	// 0x259CF8: ret
	return;
}

void sub_259D00(X86Context& ctx, uint8_t* base) {
	// 0x259D00: movss xmm0, dword ptr [0x004D5894]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5894u);
	// 0x259D08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x259D10: movss [0x004D58B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58B8u, ctx.xmm[0].u32[0]);
	// 0x259D18: ret
	return;
}

void sub_259D20(X86Context& ctx, uint8_t* base) {
	// 0x259D20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259D28: movss [0x004D58CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58CCu, ctx.xmm[0].u32[0]);
	// 0x259D30: ret
	return;
}

void sub_259D40(X86Context& ctx, uint8_t* base) {
	// 0x259D40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x259D48: movss [0x004D58C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58C0u, ctx.xmm[0].u32[0]);
	// 0x259D50: ret
	return;
}

void sub_259D60(X86Context& ctx, uint8_t* base) {
	// 0x259D60: movss xmm0, dword ptr [0x004D58C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D58C0u);
	// 0x259D68: movss [0x004D58C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58C8u, ctx.xmm[0].u32[0]);
	// 0x259D70: ret
	return;
}

void sub_259D80(X86Context& ctx, uint8_t* base) {
	// 0x259D80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259D88: movss [0x004D5890], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5890u, ctx.xmm[0].u32[0]);
	// 0x259D90: ret
	return;
}

void sub_259DA0(X86Context& ctx, uint8_t* base) {
	// 0x259DA0: movss xmm0, dword ptr [0x004D5894]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5894u);
	// 0x259DA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x259DB0: movss [0x004D58C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58C4u, ctx.xmm[0].u32[0]);
	// 0x259DB8: ret
	return;
}

void sub_259DC0(X86Context& ctx, uint8_t* base) {
	// 0x259DC0: movss xmm0, dword ptr [0x004D5894]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5894u);
	// 0x259DC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x259DD0: movss [0x004D58A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58A0u, ctx.xmm[0].u32[0]);
	// 0x259DD8: ret
	return;
}

void sub_259DE0(X86Context& ctx, uint8_t* base) {
	// 0x259DE0: movss xmm0, dword ptr [0x004D5894]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5894u);
	// 0x259DE8: subss xmm0, [0x004D58A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D58A0u);
	// 0x259DF0: movss [0x004D589C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D589Cu, ctx.xmm[0].u32[0]);
	// 0x259DF8: ret
	return;
}

void sub_259E00(X86Context& ctx, uint8_t* base) {
	// 0x259E00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x259E08: movss [0x004D58B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58B0u, ctx.xmm[0].u32[0]);
	// 0x259E10: ret
	return;
}

void sub_259E20(X86Context& ctx, uint8_t* base) {
	// 0x259E20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x259E28: movss [0x004D5898], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5898u, ctx.xmm[0].u32[0]);
	// 0x259E30: ret
	return;
}

void sub_259E40(X86Context& ctx, uint8_t* base) {
	// 0x259E40: movss xmm0, dword ptr [0x003B17BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17BCu);
	// 0x259E48: movss [0x004D58D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58D0u, ctx.xmm[0].u32[0]);
	// 0x259E50: movss [0x004D58D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58D4u, ctx.xmm[0].u32[0]);
	// 0x259E58: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x259E5B: movss [0x004D58D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58D8u, ctx.xmm[0].u32[0]);
	// 0x259E63: movss [0x004D58DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58DCu, ctx.xmm[0].u32[0]);
	// 0x259E6B: movss [0x004D58E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58E0u, ctx.xmm[0].u32[0]);
	// 0x259E73: movss [0x004D58E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58E4u, ctx.xmm[0].u32[0]);
	// 0x259E7B: movss xmm0, dword ptr [0x003B1A78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A78u);
	// 0x259E83: movss [0x004D58E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58E8u, ctx.xmm[0].u32[0]);
	// 0x259E8B: movss xmm0, dword ptr [0x00384A80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x384A80u);
	// 0x259E93: movss [0x004D58EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58ECu, ctx.xmm[0].u32[0]);
	// 0x259E9B: movss [0x004D58F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58F0u, ctx.xmm[0].u32[0]);
	// 0x259EA3: ret
	return;
}

void sub_259EB0(X86Context& ctx, uint8_t* base) {
	// 0x259EB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x259EB8: movss [0x004D5910], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5910u, ctx.xmm[0].u32[0]);
	// 0x259EC0: ret
	return;
}

void sub_259ED0(X86Context& ctx, uint8_t* base) {
	// 0x259ED0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x259ED8: movss [0x004D591C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D591Cu, ctx.xmm[0].u32[0]);
	// 0x259EE0: ret
	return;
}

void sub_259EF0(X86Context& ctx, uint8_t* base) {
	// 0x259EF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x259EF8: movss [0x004D590C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D590Cu, ctx.xmm[0].u32[0]);
	// 0x259F00: ret
	return;
}

void sub_259F10(X86Context& ctx, uint8_t* base) {
	// 0x259F10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x259F18: movss [0x004D58F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58F4u, ctx.xmm[0].u32[0]);
	// 0x259F20: ret
	return;
}

void sub_259F30(X86Context& ctx, uint8_t* base) {
	// 0x259F30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x259F38: movss [0x004D5914], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5914u, ctx.xmm[0].u32[0]);
	// 0x259F40: ret
	return;
}

void sub_259F50(X86Context& ctx, uint8_t* base) {
	// 0x259F50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x259F58: movss [0x004D58FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58FCu, ctx.xmm[0].u32[0]);
	// 0x259F60: ret
	return;
}

void sub_259F70(X86Context& ctx, uint8_t* base) {
	// 0x259F70: movss xmm0, dword ptr [0x004D5914]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5914u);
	// 0x259F78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x259F80: movss [0x004D5924], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5924u, ctx.xmm[0].u32[0]);
	// 0x259F88: ret
	return;
}

void sub_259F90(X86Context& ctx, uint8_t* base) {
	// 0x259F90: movss xmm0, dword ptr [0x004D58FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D58FCu);
	// 0x259F98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x259FA0: movss [0x004D5920], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5920u, ctx.xmm[0].u32[0]);
	// 0x259FA8: ret
	return;
}

void sub_259FB0(X86Context& ctx, uint8_t* base) {
	// 0x259FB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x259FB8: movss [0x004D5934], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5934u, ctx.xmm[0].u32[0]);
	// 0x259FC0: ret
	return;
}

void sub_259FD0(X86Context& ctx, uint8_t* base) {
	// 0x259FD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x259FD8: movss [0x004D5928], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5928u, ctx.xmm[0].u32[0]);
	// 0x259FE0: ret
	return;
}

void sub_259FF0(X86Context& ctx, uint8_t* base) {
	// 0x259FF0: movss xmm0, dword ptr [0x004D5928]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5928u);
	// 0x259FF8: movss [0x004D5930], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5930u, ctx.xmm[0].u32[0]);
	// 0x25A000: ret
	return;
}

void sub_25A010(X86Context& ctx, uint8_t* base) {
	// 0x25A010: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A018: movss [0x004D58F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D58F8u, ctx.xmm[0].u32[0]);
	// 0x25A020: ret
	return;
}

void sub_25A030(X86Context& ctx, uint8_t* base) {
	// 0x25A030: movss xmm0, dword ptr [0x004D58FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D58FCu);
	// 0x25A038: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25A040: movss [0x004D592C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D592Cu, ctx.xmm[0].u32[0]);
	// 0x25A048: ret
	return;
}

void sub_25A050(X86Context& ctx, uint8_t* base) {
	// 0x25A050: movss xmm0, dword ptr [0x004D58FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D58FCu);
	// 0x25A058: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25A060: movss [0x004D5908], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5908u, ctx.xmm[0].u32[0]);
	// 0x25A068: ret
	return;
}

void sub_25A070(X86Context& ctx, uint8_t* base) {
	// 0x25A070: movss xmm0, dword ptr [0x004D58FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D58FCu);
	// 0x25A078: subss xmm0, [0x004D5908]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5908u);
	// 0x25A080: movss [0x004D5904], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5904u, ctx.xmm[0].u32[0]);
	// 0x25A088: ret
	return;
}

void sub_25A090(X86Context& ctx, uint8_t* base) {
	// 0x25A090: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25A098: movss [0x004D5918], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5918u, ctx.xmm[0].u32[0]);
	// 0x25A0A0: ret
	return;
}

void sub_25A0B0(X86Context& ctx, uint8_t* base) {
	// 0x25A0B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25A0B8: movss [0x004D5900], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5900u, ctx.xmm[0].u32[0]);
	// 0x25A0C0: ret
	return;
}

void sub_25A0D0(X86Context& ctx, uint8_t* base) {
	// 0x25A0D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25A0D8: movss [0x004D5954], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5954u, ctx.xmm[0].u32[0]);
	// 0x25A0E0: ret
	return;
}

void sub_25A0F0(X86Context& ctx, uint8_t* base) {
	// 0x25A0F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25A0F8: movss [0x004D5960], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5960u, ctx.xmm[0].u32[0]);
	// 0x25A100: ret
	return;
}

void sub_25A110(X86Context& ctx, uint8_t* base) {
	// 0x25A110: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25A118: movss [0x004D5950], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5950u, ctx.xmm[0].u32[0]);
	// 0x25A120: ret
	return;
}

void sub_25A130(X86Context& ctx, uint8_t* base) {
	// 0x25A130: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25A138: movss [0x004D5938], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5938u, ctx.xmm[0].u32[0]);
	// 0x25A140: ret
	return;
}

void sub_25A150(X86Context& ctx, uint8_t* base) {
	// 0x25A150: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25A158: movss [0x004D5958], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5958u, ctx.xmm[0].u32[0]);
	// 0x25A160: ret
	return;
}

void sub_25A170(X86Context& ctx, uint8_t* base) {
	// 0x25A170: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25A178: movss [0x004D5940], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5940u, ctx.xmm[0].u32[0]);
	// 0x25A180: ret
	return;
}

void sub_25A190(X86Context& ctx, uint8_t* base) {
	// 0x25A190: movss xmm0, dword ptr [0x004D5958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5958u);
	// 0x25A198: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25A1A0: movss [0x004D5968], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5968u, ctx.xmm[0].u32[0]);
	// 0x25A1A8: ret
	return;
}

void sub_25A1B0(X86Context& ctx, uint8_t* base) {
	// 0x25A1B0: movss xmm0, dword ptr [0x004D5940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5940u);
	// 0x25A1B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25A1C0: movss [0x004D5964], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5964u, ctx.xmm[0].u32[0]);
	// 0x25A1C8: ret
	return;
}

void sub_25A1D0(X86Context& ctx, uint8_t* base) {
	// 0x25A1D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A1D8: movss [0x004D5978], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5978u, ctx.xmm[0].u32[0]);
	// 0x25A1E0: ret
	return;
}

void sub_25A1F0(X86Context& ctx, uint8_t* base) {
	// 0x25A1F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25A1F8: movss [0x004D596C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D596Cu, ctx.xmm[0].u32[0]);
	// 0x25A200: ret
	return;
}

void sub_25A210(X86Context& ctx, uint8_t* base) {
	// 0x25A210: movss xmm0, dword ptr [0x004D596C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D596Cu);
	// 0x25A218: movss [0x004D5974], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5974u, ctx.xmm[0].u32[0]);
	// 0x25A220: ret
	return;
}

void sub_25A230(X86Context& ctx, uint8_t* base) {
	// 0x25A230: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A238: movss [0x004D593C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D593Cu, ctx.xmm[0].u32[0]);
	// 0x25A240: ret
	return;
}

void sub_25A250(X86Context& ctx, uint8_t* base) {
	// 0x25A250: movss xmm0, dword ptr [0x004D5940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5940u);
	// 0x25A258: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25A260: movss [0x004D5970], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5970u, ctx.xmm[0].u32[0]);
	// 0x25A268: ret
	return;
}

void sub_25A270(X86Context& ctx, uint8_t* base) {
	// 0x25A270: movss xmm0, dword ptr [0x004D5940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5940u);
	// 0x25A278: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25A280: movss [0x004D594C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D594Cu, ctx.xmm[0].u32[0]);
	// 0x25A288: ret
	return;
}

void sub_25A290(X86Context& ctx, uint8_t* base) {
	// 0x25A290: movss xmm0, dword ptr [0x004D5940]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5940u);
	// 0x25A298: subss xmm0, [0x004D594C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D594Cu);
	// 0x25A2A0: movss [0x004D5948], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5948u, ctx.xmm[0].u32[0]);
	// 0x25A2A8: ret
	return;
}

void sub_25A2B0(X86Context& ctx, uint8_t* base) {
	// 0x25A2B0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25A2B8: movss [0x004D595C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D595Cu, ctx.xmm[0].u32[0]);
	// 0x25A2C0: ret
	return;
}

void sub_25A2D0(X86Context& ctx, uint8_t* base) {
	// 0x25A2D0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25A2D8: movss [0x004D5944], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5944u, ctx.xmm[0].u32[0]);
	// 0x25A2E0: ret
	return;
}

void sub_25A2F0(X86Context& ctx, uint8_t* base) {
	// 0x25A2F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25A2F8: movss [0x004D5998], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5998u, ctx.xmm[0].u32[0]);
	// 0x25A300: ret
	return;
}

void sub_25A310(X86Context& ctx, uint8_t* base) {
	// 0x25A310: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25A318: movss [0x004D59A4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59A4u, ctx.xmm[0].u32[0]);
	// 0x25A320: ret
	return;
}

void sub_25A330(X86Context& ctx, uint8_t* base) {
	// 0x25A330: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25A338: movss [0x004D5994], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5994u, ctx.xmm[0].u32[0]);
	// 0x25A340: ret
	return;
}

void sub_25A350(X86Context& ctx, uint8_t* base) {
	// 0x25A350: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25A358: movss [0x004D597C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D597Cu, ctx.xmm[0].u32[0]);
	// 0x25A360: ret
	return;
}

void sub_25A370(X86Context& ctx, uint8_t* base) {
	// 0x25A370: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25A378: movss [0x004D599C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D599Cu, ctx.xmm[0].u32[0]);
	// 0x25A380: ret
	return;
}

void sub_25A390(X86Context& ctx, uint8_t* base) {
	// 0x25A390: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25A398: movss [0x004D5984], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5984u, ctx.xmm[0].u32[0]);
	// 0x25A3A0: ret
	return;
}

void sub_25A3B0(X86Context& ctx, uint8_t* base) {
	// 0x25A3B0: movss xmm0, dword ptr [0x004D599C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D599Cu);
	// 0x25A3B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25A3C0: movss [0x004D59AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59ACu, ctx.xmm[0].u32[0]);
	// 0x25A3C8: ret
	return;
}

void sub_25A3D0(X86Context& ctx, uint8_t* base) {
	// 0x25A3D0: movss xmm0, dword ptr [0x004D5984]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5984u);
	// 0x25A3D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25A3E0: movss [0x004D59A8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59A8u, ctx.xmm[0].u32[0]);
	// 0x25A3E8: ret
	return;
}

void sub_25A3F0(X86Context& ctx, uint8_t* base) {
	// 0x25A3F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A3F8: movss [0x004D59BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59BCu, ctx.xmm[0].u32[0]);
	// 0x25A400: ret
	return;
}

void sub_25A410(X86Context& ctx, uint8_t* base) {
	// 0x25A410: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25A418: movss [0x004D59B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59B0u, ctx.xmm[0].u32[0]);
	// 0x25A420: ret
	return;
}

void sub_25A430(X86Context& ctx, uint8_t* base) {
	// 0x25A430: movss xmm0, dword ptr [0x004D59B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59B0u);
	// 0x25A438: movss [0x004D59B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59B8u, ctx.xmm[0].u32[0]);
	// 0x25A440: ret
	return;
}

void sub_25A450(X86Context& ctx, uint8_t* base) {
	// 0x25A450: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A458: movss [0x004D5980], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5980u, ctx.xmm[0].u32[0]);
	// 0x25A460: ret
	return;
}

void sub_25A470(X86Context& ctx, uint8_t* base) {
	// 0x25A470: movss xmm0, dword ptr [0x004D5984]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5984u);
	// 0x25A478: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25A480: movss [0x004D59B4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59B4u, ctx.xmm[0].u32[0]);
	// 0x25A488: ret
	return;
}

void sub_25A490(X86Context& ctx, uint8_t* base) {
	// 0x25A490: movss xmm0, dword ptr [0x004D5984]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5984u);
	// 0x25A498: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25A4A0: movss [0x004D5990], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5990u, ctx.xmm[0].u32[0]);
	// 0x25A4A8: ret
	return;
}

void sub_25A4B0(X86Context& ctx, uint8_t* base) {
	// 0x25A4B0: movss xmm0, dword ptr [0x004D5984]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5984u);
	// 0x25A4B8: subss xmm0, [0x004D5990]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5990u);
	// 0x25A4C0: movss [0x004D598C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D598Cu, ctx.xmm[0].u32[0]);
	// 0x25A4C8: ret
	return;
}

void sub_25A4D0(X86Context& ctx, uint8_t* base) {
	// 0x25A4D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25A4D8: movss [0x004D59A0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59A0u, ctx.xmm[0].u32[0]);
	// 0x25A4E0: ret
	return;
}

void sub_25A4F0(X86Context& ctx, uint8_t* base) {
	// 0x25A4F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25A4F8: movss [0x004D5988], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5988u, ctx.xmm[0].u32[0]);
	// 0x25A500: ret
	return;
}

void sub_25A510(X86Context& ctx, uint8_t* base) {
	// 0x25A510: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25A518: movss [0x004D59DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59DCu, ctx.xmm[0].u32[0]);
	// 0x25A520: ret
	return;
}

void sub_25A530(X86Context& ctx, uint8_t* base) {
	// 0x25A530: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25A538: movss [0x004D59E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59E8u, ctx.xmm[0].u32[0]);
	// 0x25A540: ret
	return;
}

void sub_25A550(X86Context& ctx, uint8_t* base) {
	// 0x25A550: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25A558: movss [0x004D59D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59D8u, ctx.xmm[0].u32[0]);
	// 0x25A560: ret
	return;
}

void sub_25A570(X86Context& ctx, uint8_t* base) {
	// 0x25A570: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25A578: movss [0x004D59C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59C0u, ctx.xmm[0].u32[0]);
	// 0x25A580: ret
	return;
}

void sub_25A590(X86Context& ctx, uint8_t* base) {
	// 0x25A590: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25A598: movss [0x004D59E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59E0u, ctx.xmm[0].u32[0]);
	// 0x25A5A0: ret
	return;
}

void sub_25A5B0(X86Context& ctx, uint8_t* base) {
	// 0x25A5B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25A5B8: movss [0x004D59C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59C8u, ctx.xmm[0].u32[0]);
	// 0x25A5C0: ret
	return;
}

void sub_25A5D0(X86Context& ctx, uint8_t* base) {
	// 0x25A5D0: movss xmm0, dword ptr [0x004D59E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59E0u);
	// 0x25A5D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25A5E0: movss [0x004D59F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59F0u, ctx.xmm[0].u32[0]);
	// 0x25A5E8: ret
	return;
}

void sub_25A5F0(X86Context& ctx, uint8_t* base) {
	// 0x25A5F0: movss xmm0, dword ptr [0x004D59C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59C8u);
	// 0x25A5F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25A600: movss [0x004D59EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59ECu, ctx.xmm[0].u32[0]);
	// 0x25A608: ret
	return;
}

void sub_25A610(X86Context& ctx, uint8_t* base) {
	// 0x25A610: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A618: movss [0x004D5A00], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A00u, ctx.xmm[0].u32[0]);
	// 0x25A620: ret
	return;
}

void sub_25A630(X86Context& ctx, uint8_t* base) {
	// 0x25A630: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25A638: movss [0x004D59F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59F4u, ctx.xmm[0].u32[0]);
	// 0x25A640: ret
	return;
}

void sub_25A650(X86Context& ctx, uint8_t* base) {
	// 0x25A650: movss xmm0, dword ptr [0x004D59F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59F4u);
	// 0x25A658: movss [0x004D59FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59FCu, ctx.xmm[0].u32[0]);
	// 0x25A660: ret
	return;
}

void sub_25A670(X86Context& ctx, uint8_t* base) {
	// 0x25A670: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A678: movss [0x004D59C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59C4u, ctx.xmm[0].u32[0]);
	// 0x25A680: ret
	return;
}

void sub_25A690(X86Context& ctx, uint8_t* base) {
	// 0x25A690: movss xmm0, dword ptr [0x004D59C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59C8u);
	// 0x25A698: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25A6A0: movss [0x004D59F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59F8u, ctx.xmm[0].u32[0]);
	// 0x25A6A8: ret
	return;
}

void sub_25A6B0(X86Context& ctx, uint8_t* base) {
	// 0x25A6B0: movss xmm0, dword ptr [0x004D59C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59C8u);
	// 0x25A6B8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25A6C0: movss [0x004D59D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59D4u, ctx.xmm[0].u32[0]);
	// 0x25A6C8: ret
	return;
}

void sub_25A6D0(X86Context& ctx, uint8_t* base) {
	// 0x25A6D0: movss xmm0, dword ptr [0x004D59C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D59C8u);
	// 0x25A6D8: subss xmm0, [0x004D59D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D59D4u);
	// 0x25A6E0: movss [0x004D59D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59D0u, ctx.xmm[0].u32[0]);
	// 0x25A6E8: ret
	return;
}

void sub_25A6F0(X86Context& ctx, uint8_t* base) {
	// 0x25A6F0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25A6F8: movss [0x004D59E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59E4u, ctx.xmm[0].u32[0]);
	// 0x25A700: ret
	return;
}

void sub_25A710(X86Context& ctx, uint8_t* base) {
	// 0x25A710: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25A718: movss [0x004D59CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D59CCu, ctx.xmm[0].u32[0]);
	// 0x25A720: ret
	return;
}

void sub_25A730(X86Context& ctx, uint8_t* base) {
	// 0x25A730: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25A738: movss [0x004D5A20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A20u, ctx.xmm[0].u32[0]);
	// 0x25A740: ret
	return;
}

void sub_25A750(X86Context& ctx, uint8_t* base) {
	// 0x25A750: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25A758: movss [0x004D5A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A2Cu, ctx.xmm[0].u32[0]);
	// 0x25A760: ret
	return;
}

void sub_25A770(X86Context& ctx, uint8_t* base) {
	// 0x25A770: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25A778: movss [0x004D5A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A1Cu, ctx.xmm[0].u32[0]);
	// 0x25A780: ret
	return;
}

void sub_25A790(X86Context& ctx, uint8_t* base) {
	// 0x25A790: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25A798: movss [0x004D5A04], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A04u, ctx.xmm[0].u32[0]);
	// 0x25A7A0: ret
	return;
}

void sub_25A7B0(X86Context& ctx, uint8_t* base) {
	// 0x25A7B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25A7B8: movss [0x004D5A24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A24u, ctx.xmm[0].u32[0]);
	// 0x25A7C0: ret
	return;
}

void sub_25A7D0(X86Context& ctx, uint8_t* base) {
	// 0x25A7D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25A7D8: movss [0x004D5A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A0Cu, ctx.xmm[0].u32[0]);
	// 0x25A7E0: ret
	return;
}

void sub_25A7F0(X86Context& ctx, uint8_t* base) {
	// 0x25A7F0: movss xmm0, dword ptr [0x004D5A24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A24u);
	// 0x25A7F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25A800: movss [0x004D5A34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A34u, ctx.xmm[0].u32[0]);
	// 0x25A808: ret
	return;
}

void sub_25A810(X86Context& ctx, uint8_t* base) {
	// 0x25A810: movss xmm0, dword ptr [0x004D5A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A0Cu);
	// 0x25A818: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25A820: movss [0x004D5A30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A30u, ctx.xmm[0].u32[0]);
	// 0x25A828: ret
	return;
}

void sub_25A830(X86Context& ctx, uint8_t* base) {
	// 0x25A830: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A838: movss [0x004D5A44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A44u, ctx.xmm[0].u32[0]);
	// 0x25A840: ret
	return;
}

void sub_25A850(X86Context& ctx, uint8_t* base) {
	// 0x25A850: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25A858: movss [0x004D5A38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A38u, ctx.xmm[0].u32[0]);
	// 0x25A860: ret
	return;
}

void sub_25A870(X86Context& ctx, uint8_t* base) {
	// 0x25A870: movss xmm0, dword ptr [0x004D5A38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A38u);
	// 0x25A878: movss [0x004D5A40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A40u, ctx.xmm[0].u32[0]);
	// 0x25A880: ret
	return;
}

void sub_25A890(X86Context& ctx, uint8_t* base) {
	// 0x25A890: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25A898: movss [0x004D5A08], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A08u, ctx.xmm[0].u32[0]);
	// 0x25A8A0: ret
	return;
}

void sub_25A8B0(X86Context& ctx, uint8_t* base) {
	// 0x25A8B0: movss xmm0, dword ptr [0x004D5A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A0Cu);
	// 0x25A8B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25A8C0: movss [0x004D5A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A3Cu, ctx.xmm[0].u32[0]);
	// 0x25A8C8: ret
	return;
}

void sub_25A8D0(X86Context& ctx, uint8_t* base) {
	// 0x25A8D0: movss xmm0, dword ptr [0x004D5A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A0Cu);
	// 0x25A8D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25A8E0: movss [0x004D5A18], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A18u, ctx.xmm[0].u32[0]);
	// 0x25A8E8: ret
	return;
}

void sub_25A8F0(X86Context& ctx, uint8_t* base) {
	// 0x25A8F0: movss xmm0, dword ptr [0x004D5A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A0Cu);
	// 0x25A8F8: subss xmm0, [0x004D5A18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5A18u);
	// 0x25A900: movss [0x004D5A14], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A14u, ctx.xmm[0].u32[0]);
	// 0x25A908: ret
	return;
}

void sub_25A910(X86Context& ctx, uint8_t* base) {
	// 0x25A910: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25A918: movss [0x004D5A28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A28u, ctx.xmm[0].u32[0]);
	// 0x25A920: ret
	return;
}

void sub_25A930(X86Context& ctx, uint8_t* base) {
	// 0x25A930: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25A938: movss [0x004D5A10], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A10u, ctx.xmm[0].u32[0]);
	// 0x25A940: ret
	return;
}

void sub_25A950(X86Context& ctx, uint8_t* base) {
	// 0x25A950: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25A958: movss [0x004D5A64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A64u, ctx.xmm[0].u32[0]);
	// 0x25A960: ret
	return;
}

void sub_25A970(X86Context& ctx, uint8_t* base) {
	// 0x25A970: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25A978: movss [0x004D5A70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A70u, ctx.xmm[0].u32[0]);
	// 0x25A980: ret
	return;
}

void sub_25A990(X86Context& ctx, uint8_t* base) {
	// 0x25A990: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25A998: movss [0x004D5A60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A60u, ctx.xmm[0].u32[0]);
	// 0x25A9A0: ret
	return;
}

void sub_25A9B0(X86Context& ctx, uint8_t* base) {
	// 0x25A9B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25A9B8: movss [0x004D5A48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A48u, ctx.xmm[0].u32[0]);
	// 0x25A9C0: ret
	return;
}

void sub_25A9D0(X86Context& ctx, uint8_t* base) {
	// 0x25A9D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25A9D8: movss [0x004D5A68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A68u, ctx.xmm[0].u32[0]);
	// 0x25A9E0: ret
	return;
}

void sub_25A9F0(X86Context& ctx, uint8_t* base) {
	// 0x25A9F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25A9F8: movss [0x004D5A50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A50u, ctx.xmm[0].u32[0]);
	// 0x25AA00: ret
	return;
}

void sub_25AA10(X86Context& ctx, uint8_t* base) {
	// 0x25AA10: movss xmm0, dword ptr [0x004D5A68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A68u);
	// 0x25AA18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25AA20: movss [0x004D5A78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A78u, ctx.xmm[0].u32[0]);
	// 0x25AA28: ret
	return;
}

void sub_25AA30(X86Context& ctx, uint8_t* base) {
	// 0x25AA30: movss xmm0, dword ptr [0x004D5A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A50u);
	// 0x25AA38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25AA40: movss [0x004D5A74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A74u, ctx.xmm[0].u32[0]);
	// 0x25AA48: ret
	return;
}

void sub_25AA50(X86Context& ctx, uint8_t* base) {
	// 0x25AA50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25AA58: movss [0x004D5A88], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A88u, ctx.xmm[0].u32[0]);
	// 0x25AA60: ret
	return;
}

void sub_25AA70(X86Context& ctx, uint8_t* base) {
	// 0x25AA70: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25AA78: movss [0x004D5A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A7Cu, ctx.xmm[0].u32[0]);
	// 0x25AA80: ret
	return;
}

void sub_25AA90(X86Context& ctx, uint8_t* base) {
	// 0x25AA90: movss xmm0, dword ptr [0x004D5A7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A7Cu);
	// 0x25AA98: movss [0x004D5A84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A84u, ctx.xmm[0].u32[0]);
	// 0x25AAA0: ret
	return;
}

void sub_25AAB0(X86Context& ctx, uint8_t* base) {
	// 0x25AAB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25AAB8: movss [0x004D5A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A4Cu, ctx.xmm[0].u32[0]);
	// 0x25AAC0: ret
	return;
}

void sub_25AAD0(X86Context& ctx, uint8_t* base) {
	// 0x25AAD0: movss xmm0, dword ptr [0x004D5A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A50u);
	// 0x25AAD8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25AAE0: movss [0x004D5A80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A80u, ctx.xmm[0].u32[0]);
	// 0x25AAE8: ret
	return;
}

void sub_25AAF0(X86Context& ctx, uint8_t* base) {
	// 0x25AAF0: movss xmm0, dword ptr [0x004D5A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A50u);
	// 0x25AAF8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25AB00: movss [0x004D5A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A5Cu, ctx.xmm[0].u32[0]);
	// 0x25AB08: ret
	return;
}

void sub_25AB10(X86Context& ctx, uint8_t* base) {
	// 0x25AB10: movss xmm0, dword ptr [0x004D5A50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A50u);
	// 0x25AB18: subss xmm0, [0x004D5A5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5A5Cu);
	// 0x25AB20: movss [0x004D5A58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A58u, ctx.xmm[0].u32[0]);
	// 0x25AB28: ret
	return;
}

void sub_25AB30(X86Context& ctx, uint8_t* base) {
	// 0x25AB30: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25AB38: movss [0x004D5A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A6Cu, ctx.xmm[0].u32[0]);
	// 0x25AB40: ret
	return;
}

void sub_25AB50(X86Context& ctx, uint8_t* base) {
	// 0x25AB50: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25AB58: movss [0x004D5A54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A54u, ctx.xmm[0].u32[0]);
	// 0x25AB60: ret
	return;
}

void sub_25AB70(X86Context& ctx, uint8_t* base) {
	// 0x25AB70: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25AB78: movss [0x004D5AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AE8u, ctx.xmm[0].u32[0]);
	// 0x25AB80: ret
	return;
}

void sub_25AB90(X86Context& ctx, uint8_t* base) {
	// 0x25AB90: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25AB98: movss [0x004D5B04], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B04u, ctx.xmm[0].u32[0]);
	// 0x25ABA0: ret
	return;
}

void sub_25ABB0(X86Context& ctx, uint8_t* base) {
	// 0x25ABB0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25ABB8: movss [0x004D5AD8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AD8u, ctx.xmm[0].u32[0]);
	// 0x25ABC0: ret
	return;
}

void sub_25ABD0(X86Context& ctx, uint8_t* base) {
	// 0x25ABD0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25ABD8: movss [0x004D5A8C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A8Cu, ctx.xmm[0].u32[0]);
	// 0x25ABE0: ret
	return;
}

void sub_25ABF0(X86Context& ctx, uint8_t* base) {
	// 0x25ABF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25ABF8: movss [0x004D5AEC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AECu, ctx.xmm[0].u32[0]);
	// 0x25AC00: ret
	return;
}

void sub_25AC10(X86Context& ctx, uint8_t* base) {
	// 0x25AC10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25AC18: movss [0x004D5AA8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AA8u, ctx.xmm[0].u32[0]);
	// 0x25AC20: ret
	return;
}

void sub_25AC30(X86Context& ctx, uint8_t* base) {
	// 0x25AC30: movss xmm0, dword ptr [0x004D5AEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AECu);
	// 0x25AC38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25AC40: movss [0x004D5B24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B24u, ctx.xmm[0].u32[0]);
	// 0x25AC48: ret
	return;
}

void sub_25AC50(X86Context& ctx, uint8_t* base) {
	// 0x25AC50: movss xmm0, dword ptr [0x004D5AA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AA8u);
	// 0x25AC58: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25AC60: movss [0x004D5B0C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B0Cu, ctx.xmm[0].u32[0]);
	// 0x25AC68: ret
	return;
}

void sub_25AC70(X86Context& ctx, uint8_t* base) {
	// 0x25AC70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25AC78: movss [0x004D5B3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B3Cu, ctx.xmm[0].u32[0]);
	// 0x25AC80: ret
	return;
}

void sub_25AC90(X86Context& ctx, uint8_t* base) {
	// 0x25AC90: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25AC98: movss [0x004D5B28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B28u, ctx.xmm[0].u32[0]);
	// 0x25ACA0: ret
	return;
}

void sub_25ACB0(X86Context& ctx, uint8_t* base) {
	// 0x25ACB0: movss xmm0, dword ptr [0x004D5B28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B28u);
	// 0x25ACB8: movss [0x004D5B38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B38u, ctx.xmm[0].u32[0]);
	// 0x25ACC0: ret
	return;
}

void sub_25ACD0(X86Context& ctx, uint8_t* base) {
	// 0x25ACD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25ACD8: movss [0x004D5A94], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A94u, ctx.xmm[0].u32[0]);
	// 0x25ACE0: ret
	return;
}

void sub_25ACF0(X86Context& ctx, uint8_t* base) {
	// 0x25ACF0: movss xmm0, dword ptr [0x004D5AA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AA8u);
	// 0x25ACF8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25AD00: movss [0x004D5B30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B30u, ctx.xmm[0].u32[0]);
	// 0x25AD08: ret
	return;
}

void sub_25AD10(X86Context& ctx, uint8_t* base) {
	// 0x25AD10: movss xmm0, dword ptr [0x004D5AA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AA8u);
	// 0x25AD18: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25AD20: movss [0x004D5AD4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AD4u, ctx.xmm[0].u32[0]);
	// 0x25AD28: ret
	return;
}

void sub_25AD30(X86Context& ctx, uint8_t* base) {
	// 0x25AD30: movss xmm0, dword ptr [0x004D5AA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AA8u);
	// 0x25AD38: subss xmm0, [0x004D5AD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5AD4u);
	// 0x25AD40: movss [0x004D5AB0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AB0u, ctx.xmm[0].u32[0]);
	// 0x25AD48: ret
	return;
}

void sub_25AD50(X86Context& ctx, uint8_t* base) {
	// 0x25AD50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25AD58: movss [0x004D5B00], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B00u, ctx.xmm[0].u32[0]);
	// 0x25AD60: ret
	return;
}

void sub_25AD70(X86Context& ctx, uint8_t* base) {
	// 0x25AD70: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25AD78: movss [0x004D5AAC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AACu, ctx.xmm[0].u32[0]);
	// 0x25AD80: ret
	return;
}

void sub_25AD90(X86Context& ctx, uint8_t* base) {
	// 0x25AD90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25AD98: movss [0x004D5AC0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AC0u, ctx.xmm[0].u32[0]);
	// 0x25ADA0: ret
	return;
}

void sub_25ADB0(X86Context& ctx, uint8_t* base) {
	// 0x25ADB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25ADB8: movss [0x004D5B18], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B18u, ctx.xmm[0].u32[0]);
	// 0x25ADC0: ret
	return;
}

void sub_25ADD0(X86Context& ctx, uint8_t* base) {
	// 0x25ADD0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x25ADD8: movss [0x004D5AFC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AFCu, ctx.xmm[0].u32[0]);
	// 0x25ADE0: ret
	return;
}

void sub_25ADF0(X86Context& ctx, uint8_t* base) {
	// 0x25ADF0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x25ADF8: movss [0x004D5AA4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AA4u, ctx.xmm[0].u32[0]);
	// 0x25AE00: ret
	return;
}

void sub_25AE10(X86Context& ctx, uint8_t* base) {
	// 0x25AE10: movss xmm0, dword ptr [0x004D5AC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AC0u);
	// 0x25AE18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25AE20: movss [0x004D5A98], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A98u, ctx.xmm[0].u32[0]);
	// 0x25AE28: ret
	return;
}

void sub_25AE30(X86Context& ctx, uint8_t* base) {
	// 0x25AE30: movss xmm0, dword ptr [0x004D5B18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B18u);
	// 0x25AE38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25AE40: movss [0x004D5AE0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AE0u, ctx.xmm[0].u32[0]);
	// 0x25AE48: ret
	return;
}

void sub_25AE50(X86Context& ctx, uint8_t* base) {
	// 0x25AE50: movss xmm0, dword ptr [0x004D5A98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5A98u);
	// 0x25AE58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25AE60: movss [0x004D5AF4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AF4u, ctx.xmm[0].u32[0]);
	// 0x25AE68: ret
	return;
}

void sub_25AE70(X86Context& ctx, uint8_t* base) {
	// 0x25AE70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25AE78: movss [0x004D5A90], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A90u, ctx.xmm[0].u32[0]);
	// 0x25AE80: ret
	return;
}

void sub_25AE90(X86Context& ctx, uint8_t* base) {
	// 0x25AE90: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25AE98: movss [0x004D5AC4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AC4u, ctx.xmm[0].u32[0]);
	// 0x25AEA0: ret
	return;
}

void sub_25AEB0(X86Context& ctx, uint8_t* base) {
	// 0x25AEB0: movss xmm0, dword ptr [0x004D5AC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AC0u);
	// 0x25AEB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25AEC0: movss [0x004D5AD0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AD0u, ctx.xmm[0].u32[0]);
	// 0x25AEC8: ret
	return;
}

void sub_25AED0(X86Context& ctx, uint8_t* base) {
	// 0x25AED0: movss xmm0, dword ptr [0x004D5B18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B18u);
	// 0x25AED8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x25AEE0: movss [0x004D5B1C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B1Cu, ctx.xmm[0].u32[0]);
	// 0x25AEE8: ret
	return;
}

void sub_25AEF0(X86Context& ctx, uint8_t* base) {
	// 0x25AEF0: movss xmm0, dword ptr [0x004D5AD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AD0u);
	// 0x25AEF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25AF00: movss [0x004D5B08], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B08u, ctx.xmm[0].u32[0]);
	// 0x25AF08: ret
	return;
}

void sub_25AF10(X86Context& ctx, uint8_t* base) {
	// 0x25AF10: movss xmm0, dword ptr [0x004D5B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B1Cu);
	// 0x25AF18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25AF20: movss [0x004D5B2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B2Cu, ctx.xmm[0].u32[0]);
	// 0x25AF28: ret
	return;
}

void sub_25AF30(X86Context& ctx, uint8_t* base) {
	// 0x25AF30: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x25AF38: movss [0x004D5A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5A9Cu, ctx.xmm[0].u32[0]);
	// 0x25AF40: ret
	return;
}

void sub_25AF50(X86Context& ctx, uint8_t* base) {
	// 0x25AF50: movss xmm0, dword ptr [0x004D5AC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AC0u);
	// 0x25AF58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25AF60: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x25AF68: movss [0x004D5B14], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B14u, ctx.xmm[0].u32[0]);
	// 0x25AF70: ret
	return;
}

void sub_25AF80(X86Context& ctx, uint8_t* base) {
	// 0x25AF80: movss xmm0, dword ptr [0x004D5B18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B18u);
	// 0x25AF88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25AF90: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x25AF98: movss [0x004D5AB4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AB4u, ctx.xmm[0].u32[0]);
	// 0x25AFA0: ret
	return;
}

void sub_25AFB0(X86Context& ctx, uint8_t* base) {
	// 0x25AFB0: movss xmm0, dword ptr [0x004D5AC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AC0u);
	// 0x25AFB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25AFC0: movss [0x004D5AB8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AB8u, ctx.xmm[0].u32[0]);
	// 0x25AFC8: ret
	return;
}

void sub_25AFD0(X86Context& ctx, uint8_t* base) {
	// 0x25AFD0: movss xmm0, dword ptr [0x004D5B18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B18u);
	// 0x25AFD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x25AFE0: movss [0x004D5B20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B20u, ctx.xmm[0].u32[0]);
	// 0x25AFE8: ret
	return;
}

void sub_25AFF0(X86Context& ctx, uint8_t* base) {
	// 0x25AFF0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x25AFF8: movss [0x004D5AA0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AA0u, ctx.xmm[0].u32[0]);
	// 0x25B000: ret
	return;
}

void sub_25B010(X86Context& ctx, uint8_t* base) {
	// 0x25B010: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x25B018: movss [0x004D5ACC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ACCu, ctx.xmm[0].u32[0]);
	// 0x25B020: ret
	return;
}

void sub_25B030(X86Context& ctx, uint8_t* base) {
	// 0x25B030: movss xmm0, dword ptr [0x004D5AA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AA0u);
	// 0x25B038: movss [0x004D5B34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B34u, ctx.xmm[0].u32[0]);
	// 0x25B040: ret
	return;
}

void sub_25B050(X86Context& ctx, uint8_t* base) {
	// 0x25B050: movss xmm0, dword ptr [0x004D5B18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B18u);
	// 0x25B058: subss xmm0, [0x004D5AA0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5AA0u);
	// 0x25B060: movss [0x004D5AF8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AF8u, ctx.xmm[0].u32[0]);
	// 0x25B068: ret
	return;
}

void sub_25B070(X86Context& ctx, uint8_t* base) {
	// 0x25B070: movss xmm0, dword ptr [0x004D5AF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5AF8u);
	// 0x25B078: subss xmm0, [0x004D5ACC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5ACCu);
	// 0x25B080: movss [0x004D5AF0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AF0u, ctx.xmm[0].u32[0]);
	// 0x25B088: ret
	return;
}

void sub_25B090(X86Context& ctx, uint8_t* base) {
	// 0x25B090: movss xmm0, dword ptr [0x004D5B20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B20u);
	// 0x25B098: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x25B0A0: movss [0x004D5ADC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ADCu, ctx.xmm[0].u32[0]);
	// 0x25B0A8: ret
	return;
}

void sub_25B0B0(X86Context& ctx, uint8_t* base) {
	// 0x25B0B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x25B0B8: movss [0x004D5AC8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AC8u, ctx.xmm[0].u32[0]);
	// 0x25B0C0: ret
	return;
}

void sub_25B0D0(X86Context& ctx, uint8_t* base) {
	// 0x25B0D0: movss xmm0, dword ptr [0x004D5ADC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5ADCu);
	// 0x25B0D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x25B0E0: movss [0x004D5B10], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B10u, ctx.xmm[0].u32[0]);
	// 0x25B0E8: ret
	return;
}

void sub_25B0F0(X86Context& ctx, uint8_t* base) {
	// 0x25B0F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25B0F8: movss [0x004D5AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5AE4u, ctx.xmm[0].u32[0]);
	// 0x25B100: ret
	return;
}

void sub_25B110(X86Context& ctx, uint8_t* base) {
	// 0x25B110: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x25B118: movss [0x004D5ABC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5ABCu, ctx.xmm[0].u32[0]);
	// 0x25B120: ret
	return;
}

void sub_25B130(X86Context& ctx, uint8_t* base) {
	// 0x25B130: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25B138: movss [0x004D5B5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B5Cu, ctx.xmm[0].u32[0]);
	// 0x25B140: ret
	return;
}

void sub_25B150(X86Context& ctx, uint8_t* base) {
	// 0x25B150: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25B158: movss [0x004D5B68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B68u, ctx.xmm[0].u32[0]);
	// 0x25B160: ret
	return;
}

void sub_25B170(X86Context& ctx, uint8_t* base) {
	// 0x25B170: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25B178: movss [0x004D5B58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B58u, ctx.xmm[0].u32[0]);
	// 0x25B180: ret
	return;
}

void sub_25B190(X86Context& ctx, uint8_t* base) {
	// 0x25B190: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25B198: movss [0x004D5B40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B40u, ctx.xmm[0].u32[0]);
	// 0x25B1A0: ret
	return;
}

void sub_25B1B0(X86Context& ctx, uint8_t* base) {
	// 0x25B1B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25B1B8: movss [0x004D5B60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B60u, ctx.xmm[0].u32[0]);
	// 0x25B1C0: ret
	return;
}

void sub_25B1D0(X86Context& ctx, uint8_t* base) {
	// 0x25B1D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25B1D8: movss [0x004D5B48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B48u, ctx.xmm[0].u32[0]);
	// 0x25B1E0: ret
	return;
}

void sub_25B1F0(X86Context& ctx, uint8_t* base) {
	// 0x25B1F0: movss xmm0, dword ptr [0x004D5B60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B60u);
	// 0x25B1F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25B200: movss [0x004D5B70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B70u, ctx.xmm[0].u32[0]);
	// 0x25B208: ret
	return;
}

void sub_25B210(X86Context& ctx, uint8_t* base) {
	// 0x25B210: movss xmm0, dword ptr [0x004D5B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B48u);
	// 0x25B218: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25B220: movss [0x004D5B6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B6Cu, ctx.xmm[0].u32[0]);
	// 0x25B228: ret
	return;
}

void sub_25B230(X86Context& ctx, uint8_t* base) {
	// 0x25B230: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B238: movss [0x004D5B80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B80u, ctx.xmm[0].u32[0]);
	// 0x25B240: ret
	return;
}

void sub_25B250(X86Context& ctx, uint8_t* base) {
	// 0x25B250: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25B258: movss [0x004D5B74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B74u, ctx.xmm[0].u32[0]);
	// 0x25B260: ret
	return;
}

void sub_25B270(X86Context& ctx, uint8_t* base) {
	// 0x25B270: movss xmm0, dword ptr [0x004D5B74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B74u);
	// 0x25B278: movss [0x004D5B7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B7Cu, ctx.xmm[0].u32[0]);
	// 0x25B280: ret
	return;
}

void sub_25B290(X86Context& ctx, uint8_t* base) {
	// 0x25B290: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B298: movss [0x004D5B44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B44u, ctx.xmm[0].u32[0]);
	// 0x25B2A0: ret
	return;
}

void sub_25B2B0(X86Context& ctx, uint8_t* base) {
	// 0x25B2B0: movss xmm0, dword ptr [0x004D5B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B48u);
	// 0x25B2B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25B2C0: movss [0x004D5B78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B78u, ctx.xmm[0].u32[0]);
	// 0x25B2C8: ret
	return;
}

void sub_25B2D0(X86Context& ctx, uint8_t* base) {
	// 0x25B2D0: movss xmm0, dword ptr [0x004D5B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B48u);
	// 0x25B2D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25B2E0: movss [0x004D5B54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B54u, ctx.xmm[0].u32[0]);
	// 0x25B2E8: ret
	return;
}

void sub_25B2F0(X86Context& ctx, uint8_t* base) {
	// 0x25B2F0: movss xmm0, dword ptr [0x004D5B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B48u);
	// 0x25B2F8: subss xmm0, [0x004D5B54]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5B54u);
	// 0x25B300: movss [0x004D5B50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B50u, ctx.xmm[0].u32[0]);
	// 0x25B308: ret
	return;
}

void sub_25B310(X86Context& ctx, uint8_t* base) {
	// 0x25B310: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25B318: movss [0x004D5B64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B64u, ctx.xmm[0].u32[0]);
	// 0x25B320: ret
	return;
}

void sub_25B330(X86Context& ctx, uint8_t* base) {
	// 0x25B330: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25B338: movss [0x004D5B4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B4Cu, ctx.xmm[0].u32[0]);
	// 0x25B340: ret
	return;
}

void sub_25B350(X86Context& ctx, uint8_t* base) {
	// 0x25B350: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25B358: movss [0x004D5BA0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BA0u, ctx.xmm[0].u32[0]);
	// 0x25B360: ret
	return;
}

void sub_25B370(X86Context& ctx, uint8_t* base) {
	// 0x25B370: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25B378: movss [0x004D5BAC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BACu, ctx.xmm[0].u32[0]);
	// 0x25B380: ret
	return;
}

void sub_25B390(X86Context& ctx, uint8_t* base) {
	// 0x25B390: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25B398: movss [0x004D5B9C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B9Cu, ctx.xmm[0].u32[0]);
	// 0x25B3A0: ret
	return;
}

void sub_25B3B0(X86Context& ctx, uint8_t* base) {
	// 0x25B3B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25B3B8: movss [0x004D5B84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B84u, ctx.xmm[0].u32[0]);
	// 0x25B3C0: ret
	return;
}

void sub_25B3D0(X86Context& ctx, uint8_t* base) {
	// 0x25B3D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25B3D8: movss [0x004D5BA4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BA4u, ctx.xmm[0].u32[0]);
	// 0x25B3E0: ret
	return;
}

void sub_25B3F0(X86Context& ctx, uint8_t* base) {
	// 0x25B3F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25B3F8: movss [0x004D5B8C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B8Cu, ctx.xmm[0].u32[0]);
	// 0x25B400: ret
	return;
}

void sub_25B410(X86Context& ctx, uint8_t* base) {
	// 0x25B410: movss xmm0, dword ptr [0x004D5BA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BA4u);
	// 0x25B418: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25B420: movss [0x004D5BB4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BB4u, ctx.xmm[0].u32[0]);
	// 0x25B428: ret
	return;
}

void sub_25B430(X86Context& ctx, uint8_t* base) {
	// 0x25B430: movss xmm0, dword ptr [0x004D5B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B8Cu);
	// 0x25B438: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25B440: movss [0x004D5BB0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BB0u, ctx.xmm[0].u32[0]);
	// 0x25B448: ret
	return;
}

void sub_25B450(X86Context& ctx, uint8_t* base) {
	// 0x25B450: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B458: movss [0x004D5BC4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BC4u, ctx.xmm[0].u32[0]);
	// 0x25B460: ret
	return;
}

void sub_25B470(X86Context& ctx, uint8_t* base) {
	// 0x25B470: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25B478: movss [0x004D5BB8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BB8u, ctx.xmm[0].u32[0]);
	// 0x25B480: ret
	return;
}

void sub_25B490(X86Context& ctx, uint8_t* base) {
	// 0x25B490: movss xmm0, dword ptr [0x004D5BB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BB8u);
	// 0x25B498: movss [0x004D5BC0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BC0u, ctx.xmm[0].u32[0]);
	// 0x25B4A0: ret
	return;
}

void sub_25B4B0(X86Context& ctx, uint8_t* base) {
	// 0x25B4B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B4B8: movss [0x004D5B88], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B88u, ctx.xmm[0].u32[0]);
	// 0x25B4C0: ret
	return;
}

void sub_25B4D0(X86Context& ctx, uint8_t* base) {
	// 0x25B4D0: movss xmm0, dword ptr [0x004D5B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B8Cu);
	// 0x25B4D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25B4E0: movss [0x004D5BBC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BBCu, ctx.xmm[0].u32[0]);
	// 0x25B4E8: ret
	return;
}

void sub_25B4F0(X86Context& ctx, uint8_t* base) {
	// 0x25B4F0: movss xmm0, dword ptr [0x004D5B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B8Cu);
	// 0x25B4F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25B500: movss [0x004D5B98], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B98u, ctx.xmm[0].u32[0]);
	// 0x25B508: ret
	return;
}

void sub_25B510(X86Context& ctx, uint8_t* base) {
	// 0x25B510: movss xmm0, dword ptr [0x004D5B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5B8Cu);
	// 0x25B518: subss xmm0, [0x004D5B98]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5B98u);
	// 0x25B520: movss [0x004D5B94], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B94u, ctx.xmm[0].u32[0]);
	// 0x25B528: ret
	return;
}

void sub_25B530(X86Context& ctx, uint8_t* base) {
	// 0x25B530: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25B538: movss [0x004D5BA8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BA8u, ctx.xmm[0].u32[0]);
	// 0x25B540: ret
	return;
}

void sub_25B550(X86Context& ctx, uint8_t* base) {
	// 0x25B550: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25B558: movss [0x004D5B90], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5B90u, ctx.xmm[0].u32[0]);
	// 0x25B560: ret
	return;
}

void sub_25B570(X86Context& ctx, uint8_t* base) {
	// 0x25B570: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25B578: movss [0x004D5BE4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BE4u, ctx.xmm[0].u32[0]);
	// 0x25B580: ret
	return;
}

void sub_25B590(X86Context& ctx, uint8_t* base) {
	// 0x25B590: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25B598: movss [0x004D5BF0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BF0u, ctx.xmm[0].u32[0]);
	// 0x25B5A0: ret
	return;
}

void sub_25B5B0(X86Context& ctx, uint8_t* base) {
	// 0x25B5B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25B5B8: movss [0x004D5BE0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BE0u, ctx.xmm[0].u32[0]);
	// 0x25B5C0: ret
	return;
}

void sub_25B5D0(X86Context& ctx, uint8_t* base) {
	// 0x25B5D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25B5D8: movss [0x004D5BC8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BC8u, ctx.xmm[0].u32[0]);
	// 0x25B5E0: ret
	return;
}

void sub_25B5F0(X86Context& ctx, uint8_t* base) {
	// 0x25B5F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25B5F8: movss [0x004D5BE8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BE8u, ctx.xmm[0].u32[0]);
	// 0x25B600: ret
	return;
}

void sub_25B610(X86Context& ctx, uint8_t* base) {
	// 0x25B610: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25B618: movss [0x004D5BD0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BD0u, ctx.xmm[0].u32[0]);
	// 0x25B620: ret
	return;
}

void sub_25B630(X86Context& ctx, uint8_t* base) {
	// 0x25B630: movss xmm0, dword ptr [0x004D5BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BE8u);
	// 0x25B638: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25B640: movss [0x004D5BF8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BF8u, ctx.xmm[0].u32[0]);
	// 0x25B648: ret
	return;
}

void sub_25B650(X86Context& ctx, uint8_t* base) {
	// 0x25B650: movss xmm0, dword ptr [0x004D5BD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BD0u);
	// 0x25B658: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25B660: movss [0x004D5BF4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BF4u, ctx.xmm[0].u32[0]);
	// 0x25B668: ret
	return;
}

void sub_25B670(X86Context& ctx, uint8_t* base) {
	// 0x25B670: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B678: movss [0x004D5C08], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C08u, ctx.xmm[0].u32[0]);
	// 0x25B680: ret
	return;
}

void sub_25B690(X86Context& ctx, uint8_t* base) {
	// 0x25B690: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25B698: movss [0x004D5BFC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BFCu, ctx.xmm[0].u32[0]);
	// 0x25B6A0: ret
	return;
}

void sub_25B6B0(X86Context& ctx, uint8_t* base) {
	// 0x25B6B0: movss xmm0, dword ptr [0x004D5BFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BFCu);
	// 0x25B6B8: movss [0x004D5C04], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C04u, ctx.xmm[0].u32[0]);
	// 0x25B6C0: ret
	return;
}

void sub_25B6D0(X86Context& ctx, uint8_t* base) {
	// 0x25B6D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B6D8: movss [0x004D5BCC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BCCu, ctx.xmm[0].u32[0]);
	// 0x25B6E0: ret
	return;
}

void sub_25B6F0(X86Context& ctx, uint8_t* base) {
	// 0x25B6F0: movss xmm0, dword ptr [0x004D5BD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BD0u);
	// 0x25B6F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25B700: movss [0x004D5C00], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C00u, ctx.xmm[0].u32[0]);
	// 0x25B708: ret
	return;
}

void sub_25B710(X86Context& ctx, uint8_t* base) {
	// 0x25B710: movss xmm0, dword ptr [0x004D5BD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BD0u);
	// 0x25B718: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25B720: movss [0x004D5BDC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BDCu, ctx.xmm[0].u32[0]);
	// 0x25B728: ret
	return;
}

void sub_25B730(X86Context& ctx, uint8_t* base) {
	// 0x25B730: movss xmm0, dword ptr [0x004D5BD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5BD0u);
	// 0x25B738: subss xmm0, [0x004D5BDC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5BDCu);
	// 0x25B740: movss [0x004D5BD8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BD8u, ctx.xmm[0].u32[0]);
	// 0x25B748: ret
	return;
}

void sub_25B750(X86Context& ctx, uint8_t* base) {
	// 0x25B750: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25B758: movss [0x004D5BEC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BECu, ctx.xmm[0].u32[0]);
	// 0x25B760: ret
	return;
}

void sub_25B770(X86Context& ctx, uint8_t* base) {
	// 0x25B770: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25B778: movss [0x004D5BD4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5BD4u, ctx.xmm[0].u32[0]);
	// 0x25B780: ret
	return;
}

void sub_25B790(X86Context& ctx, uint8_t* base) {
	// 0x25B790: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25B798: movss [0x004D5C28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C28u, ctx.xmm[0].u32[0]);
	// 0x25B7A0: ret
	return;
}

void sub_25B7B0(X86Context& ctx, uint8_t* base) {
	// 0x25B7B0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25B7B8: movss [0x004D5C34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C34u, ctx.xmm[0].u32[0]);
	// 0x25B7C0: ret
	return;
}

void sub_25B7D0(X86Context& ctx, uint8_t* base) {
	// 0x25B7D0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25B7D8: movss [0x004D5C24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C24u, ctx.xmm[0].u32[0]);
	// 0x25B7E0: ret
	return;
}

void sub_25B7F0(X86Context& ctx, uint8_t* base) {
	// 0x25B7F0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25B7F8: movss [0x004D5C0C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C0Cu, ctx.xmm[0].u32[0]);
	// 0x25B800: ret
	return;
}

void sub_25B810(X86Context& ctx, uint8_t* base) {
	// 0x25B810: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25B818: movss [0x004D5C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C2Cu, ctx.xmm[0].u32[0]);
	// 0x25B820: ret
	return;
}

void sub_25B830(X86Context& ctx, uint8_t* base) {
	// 0x25B830: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25B838: movss [0x004D5C14], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C14u, ctx.xmm[0].u32[0]);
	// 0x25B840: ret
	return;
}

void sub_25B850(X86Context& ctx, uint8_t* base) {
	// 0x25B850: movss xmm0, dword ptr [0x004D5C2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C2Cu);
	// 0x25B858: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25B860: movss [0x004D5C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C3Cu, ctx.xmm[0].u32[0]);
	// 0x25B868: ret
	return;
}

void sub_25B870(X86Context& ctx, uint8_t* base) {
	// 0x25B870: movss xmm0, dword ptr [0x004D5C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C14u);
	// 0x25B878: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25B880: movss [0x004D5C38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C38u, ctx.xmm[0].u32[0]);
	// 0x25B888: ret
	return;
}

void sub_25B890(X86Context& ctx, uint8_t* base) {
	// 0x25B890: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B898: movss [0x004D5C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C4Cu, ctx.xmm[0].u32[0]);
	// 0x25B8A0: ret
	return;
}

void sub_25B8B0(X86Context& ctx, uint8_t* base) {
	// 0x25B8B0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25B8B8: movss [0x004D5C40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C40u, ctx.xmm[0].u32[0]);
	// 0x25B8C0: ret
	return;
}

void sub_25B8D0(X86Context& ctx, uint8_t* base) {
	// 0x25B8D0: movss xmm0, dword ptr [0x004D5C40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C40u);
	// 0x25B8D8: movss [0x004D5C48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C48u, ctx.xmm[0].u32[0]);
	// 0x25B8E0: ret
	return;
}

void sub_25B8F0(X86Context& ctx, uint8_t* base) {
	// 0x25B8F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25B8F8: movss [0x004D5C10], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C10u, ctx.xmm[0].u32[0]);
	// 0x25B900: ret
	return;
}

void sub_25B910(X86Context& ctx, uint8_t* base) {
	// 0x25B910: movss xmm0, dword ptr [0x004D5C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C14u);
	// 0x25B918: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25B920: movss [0x004D5C44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C44u, ctx.xmm[0].u32[0]);
	// 0x25B928: ret
	return;
}

void sub_25B930(X86Context& ctx, uint8_t* base) {
	// 0x25B930: movss xmm0, dword ptr [0x004D5C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C14u);
	// 0x25B938: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25B940: movss [0x004D5C20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C20u, ctx.xmm[0].u32[0]);
	// 0x25B948: ret
	return;
}

void sub_25B950(X86Context& ctx, uint8_t* base) {
	// 0x25B950: movss xmm0, dword ptr [0x004D5C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C14u);
	// 0x25B958: subss xmm0, [0x004D5C20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5C20u);
	// 0x25B960: movss [0x004D5C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C1Cu, ctx.xmm[0].u32[0]);
	// 0x25B968: ret
	return;
}

void sub_25B970(X86Context& ctx, uint8_t* base) {
	// 0x25B970: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25B978: movss [0x004D5C30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C30u, ctx.xmm[0].u32[0]);
	// 0x25B980: ret
	return;
}

void sub_25B990(X86Context& ctx, uint8_t* base) {
	// 0x25B990: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25B998: movss [0x004D5C18], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C18u, ctx.xmm[0].u32[0]);
	// 0x25B9A0: ret
	return;
}

void sub_25B9B0(X86Context& ctx, uint8_t* base) {
	// 0x25B9B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25B9B8: movss [0x004D5C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C6Cu, ctx.xmm[0].u32[0]);
	// 0x25B9C0: ret
	return;
}

void sub_25B9D0(X86Context& ctx, uint8_t* base) {
	// 0x25B9D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25B9D8: movss [0x004D5C78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C78u, ctx.xmm[0].u32[0]);
	// 0x25B9E0: ret
	return;
}

void sub_25B9F0(X86Context& ctx, uint8_t* base) {
	// 0x25B9F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25B9F8: movss [0x004D5C68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C68u, ctx.xmm[0].u32[0]);
	// 0x25BA00: ret
	return;
}

void sub_25BA10(X86Context& ctx, uint8_t* base) {
	// 0x25BA10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25BA18: movss [0x004D5C50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C50u, ctx.xmm[0].u32[0]);
	// 0x25BA20: ret
	return;
}

void sub_25BA30(X86Context& ctx, uint8_t* base) {
	// 0x25BA30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25BA38: movss [0x004D5C70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C70u, ctx.xmm[0].u32[0]);
	// 0x25BA40: ret
	return;
}

void sub_25BA50(X86Context& ctx, uint8_t* base) {
	// 0x25BA50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25BA58: movss [0x004D5C58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C58u, ctx.xmm[0].u32[0]);
	// 0x25BA60: ret
	return;
}

void sub_25BA70(X86Context& ctx, uint8_t* base) {
	// 0x25BA70: movss xmm0, dword ptr [0x004D5C70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C70u);
	// 0x25BA78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25BA80: movss [0x004D5C80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C80u, ctx.xmm[0].u32[0]);
	// 0x25BA88: ret
	return;
}

void sub_25BA90(X86Context& ctx, uint8_t* base) {
	// 0x25BA90: movss xmm0, dword ptr [0x004D5C58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C58u);
	// 0x25BA98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25BAA0: movss [0x004D5C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C7Cu, ctx.xmm[0].u32[0]);
	// 0x25BAA8: ret
	return;
}

void sub_25BAB0(X86Context& ctx, uint8_t* base) {
	// 0x25BAB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25BAB8: movss [0x004D5C90], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C90u, ctx.xmm[0].u32[0]);
	// 0x25BAC0: ret
	return;
}

void sub_25BAD0(X86Context& ctx, uint8_t* base) {
	// 0x25BAD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25BAD8: movss [0x004D5C84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C84u, ctx.xmm[0].u32[0]);
	// 0x25BAE0: ret
	return;
}

void sub_25BAF0(X86Context& ctx, uint8_t* base) {
	// 0x25BAF0: movss xmm0, dword ptr [0x004D5C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C84u);
	// 0x25BAF8: movss [0x004D5C8C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C8Cu, ctx.xmm[0].u32[0]);
	// 0x25BB00: ret
	return;
}

void sub_25BB10(X86Context& ctx, uint8_t* base) {
	// 0x25BB10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25BB18: movss [0x004D5C54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C54u, ctx.xmm[0].u32[0]);
	// 0x25BB20: ret
	return;
}

void sub_25BB30(X86Context& ctx, uint8_t* base) {
	// 0x25BB30: movss xmm0, dword ptr [0x004D5C58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C58u);
	// 0x25BB38: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25BB40: movss [0x004D5C88], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C88u, ctx.xmm[0].u32[0]);
	// 0x25BB48: ret
	return;
}

void sub_25BB50(X86Context& ctx, uint8_t* base) {
	// 0x25BB50: movss xmm0, dword ptr [0x004D5C58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C58u);
	// 0x25BB58: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25BB60: movss [0x004D5C64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C64u, ctx.xmm[0].u32[0]);
	// 0x25BB68: ret
	return;
}

void sub_25BB70(X86Context& ctx, uint8_t* base) {
	// 0x25BB70: movss xmm0, dword ptr [0x004D5C58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D5C58u);
	// 0x25BB78: subss xmm0, [0x004D5C64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D5C64u);
	// 0x25BB80: movss [0x004D5C60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C60u, ctx.xmm[0].u32[0]);
	// 0x25BB88: ret
	return;
}

void sub_25BB90(X86Context& ctx, uint8_t* base) {
	// 0x25BB90: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25BB98: movss [0x004D5C74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C74u, ctx.xmm[0].u32[0]);
	// 0x25BBA0: ret
	return;
}

void sub_25BBB0(X86Context& ctx, uint8_t* base) {
	// 0x25BBB0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25BBB8: movss [0x004D5C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5C5Cu, ctx.xmm[0].u32[0]);
	// 0x25BBC0: ret
	return;
}

void sub_25BBD0(X86Context& ctx, uint8_t* base) {
	// 0x25BBD0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25BBD8: movss [0x004D5CF0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CF0u, ctx.xmm[0].u32[0]);
	// 0x25BBE0: ret
	return;
}

void sub_25BBF0(X86Context& ctx, uint8_t* base) {
	// 0x25BBF0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25BBF8: movss [0x004D5D0C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5D0Cu, ctx.xmm[0].u32[0]);
	// 0x25BC00: ret
	return;
}

void sub_25BC10(X86Context& ctx, uint8_t* base) {
	// 0x25BC10: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25BC18: movss [0x004D5CE0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D5CE0u, ctx.xmm[0].u32[0]);
	// 0x25BC20: ret
	return;
}

