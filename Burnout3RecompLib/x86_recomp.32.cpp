#include "x86_recomp_shared.h"

void sub_25DCB0(X86Context& ctx, uint8_t* base) {
	// 0x25DCB0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x25DCB8: movss [0x004D6050], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6050u, ctx.xmm[0].u32[0]);
	// 0x25DCC0: ret
	return;
}

void sub_25DCD0(X86Context& ctx, uint8_t* base) {
	// 0x25DCD0: movss xmm0, dword ptr [0x004D6024]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6024u);
	// 0x25DCD8: movss [0x004D60B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60B8u, ctx.xmm[0].u32[0]);
	// 0x25DCE0: ret
	return;
}

void sub_25DCF0(X86Context& ctx, uint8_t* base) {
	// 0x25DCF0: movss xmm0, dword ptr [0x004D609C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D609Cu);
	// 0x25DCF8: subss xmm0, [0x004D6024]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D6024u);
	// 0x25DD00: movss [0x004D607C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D607Cu, ctx.xmm[0].u32[0]);
	// 0x25DD08: ret
	return;
}

void sub_25DD10(X86Context& ctx, uint8_t* base) {
	// 0x25DD10: movss xmm0, dword ptr [0x004D607C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D607Cu);
	// 0x25DD18: subss xmm0, [0x004D6050]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D6050u);
	// 0x25DD20: movss [0x004D6074], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6074u, ctx.xmm[0].u32[0]);
	// 0x25DD28: ret
	return;
}

void sub_25DD30(X86Context& ctx, uint8_t* base) {
	// 0x25DD30: movss xmm0, dword ptr [0x004D60A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60A4u);
	// 0x25DD38: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x25DD40: movss [0x004D6060], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6060u, ctx.xmm[0].u32[0]);
	// 0x25DD48: ret
	return;
}

void sub_25DD50(X86Context& ctx, uint8_t* base) {
	// 0x25DD50: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x25DD58: movss [0x004D604C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D604Cu, ctx.xmm[0].u32[0]);
	// 0x25DD60: ret
	return;
}

void sub_25DD70(X86Context& ctx, uint8_t* base) {
	// 0x25DD70: movss xmm0, dword ptr [0x004D6060]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6060u);
	// 0x25DD78: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x25DD80: movss [0x004D6094], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6094u, ctx.xmm[0].u32[0]);
	// 0x25DD88: ret
	return;
}

void sub_25DD90(X86Context& ctx, uint8_t* base) {
	// 0x25DD90: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25DD98: movss [0x004D6068], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6068u, ctx.xmm[0].u32[0]);
	// 0x25DDA0: ret
	return;
}

void sub_25DDB0(X86Context& ctx, uint8_t* base) {
	// 0x25DDB0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x25DDB8: movss [0x004D6040], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6040u, ctx.xmm[0].u32[0]);
	// 0x25DDC0: ret
	return;
}

void sub_25DDD0(X86Context& ctx, uint8_t* base) {
	// 0x25DDD0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25DDD8: movss [0x004D610C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D610Cu, ctx.xmm[0].u32[0]);
	// 0x25DDE0: ret
	return;
}

void sub_25DDF0(X86Context& ctx, uint8_t* base) {
	// 0x25DDF0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25DDF8: movss [0x004D6120], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6120u, ctx.xmm[0].u32[0]);
	// 0x25DE00: ret
	return;
}

void sub_25DE10(X86Context& ctx, uint8_t* base) {
	// 0x25DE10: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25DE18: movss [0x004D60FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60FCu, ctx.xmm[0].u32[0]);
	// 0x25DE20: ret
	return;
}

void sub_25DE30(X86Context& ctx, uint8_t* base) {
	// 0x25DE30: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25DE38: movss [0x004D60C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60C8u, ctx.xmm[0].u32[0]);
	// 0x25DE40: ret
	return;
}

void sub_25DE50(X86Context& ctx, uint8_t* base) {
	// 0x25DE50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25DE58: movss [0x004D6110], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6110u, ctx.xmm[0].u32[0]);
	// 0x25DE60: ret
	return;
}

void sub_25DE70(X86Context& ctx, uint8_t* base) {
	// 0x25DE70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25DE78: movss [0x004D60D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60D0u, ctx.xmm[0].u32[0]);
	// 0x25DE80: ret
	return;
}

void sub_25DE90(X86Context& ctx, uint8_t* base) {
	// 0x25DE90: movss xmm0, dword ptr [0x004D6110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6110u);
	// 0x25DE98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25DEA0: movss [0x004D6138], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6138u, ctx.xmm[0].u32[0]);
	// 0x25DEA8: ret
	return;
}

void sub_25DEB0(X86Context& ctx, uint8_t* base) {
	// 0x25DEB0: movss xmm0, dword ptr [0x004D60D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60D0u);
	// 0x25DEB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25DEC0: movss [0x004D6128], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6128u, ctx.xmm[0].u32[0]);
	// 0x25DEC8: ret
	return;
}

void sub_25DED0(X86Context& ctx, uint8_t* base) {
	// 0x25DED0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25DED8: movss [0x004D6158], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6158u, ctx.xmm[0].u32[0]);
	// 0x25DEE0: ret
	return;
}

void sub_25DEF0(X86Context& ctx, uint8_t* base) {
	// 0x25DEF0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25DEF8: movss [0x004D613C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D613Cu, ctx.xmm[0].u32[0]);
	// 0x25DF00: ret
	return;
}

void sub_25DF10(X86Context& ctx, uint8_t* base) {
	// 0x25DF10: movss xmm0, dword ptr [0x004D613C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D613Cu);
	// 0x25DF18: movss [0x004D6150], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6150u, ctx.xmm[0].u32[0]);
	// 0x25DF20: ret
	return;
}

void sub_25DF30(X86Context& ctx, uint8_t* base) {
	// 0x25DF30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25DF38: movss [0x004D60CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60CCu, ctx.xmm[0].u32[0]);
	// 0x25DF40: ret
	return;
}

void sub_25DF50(X86Context& ctx, uint8_t* base) {
	// 0x25DF50: movss xmm0, dword ptr [0x004D60D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60D0u);
	// 0x25DF58: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25DF60: movss [0x004D6140], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6140u, ctx.xmm[0].u32[0]);
	// 0x25DF68: ret
	return;
}

void sub_25DF70(X86Context& ctx, uint8_t* base) {
	// 0x25DF70: movss xmm0, dword ptr [0x004D60D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60D0u);
	// 0x25DF78: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25DF80: movss [0x004D60F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60F4u, ctx.xmm[0].u32[0]);
	// 0x25DF88: ret
	return;
}

void sub_25DF90(X86Context& ctx, uint8_t* base) {
	// 0x25DF90: movss xmm0, dword ptr [0x004D60D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60D0u);
	// 0x25DF98: subss xmm0, [0x004D60F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D60F4u);
	// 0x25DFA0: movss [0x004D60DC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60DCu, ctx.xmm[0].u32[0]);
	// 0x25DFA8: ret
	return;
}

void sub_25DFB0(X86Context& ctx, uint8_t* base) {
	// 0x25DFB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25DFB8: movss [0x004D611C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D611Cu, ctx.xmm[0].u32[0]);
	// 0x25DFC0: ret
	return;
}

void sub_25DFD0(X86Context& ctx, uint8_t* base) {
	// 0x25DFD0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25DFD8: movss [0x004D60D4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60D4u, ctx.xmm[0].u32[0]);
	// 0x25DFE0: ret
	return;
}

void sub_25DFF0(X86Context& ctx, uint8_t* base) {
	// 0x25DFF0: movss xmm0, dword ptr [0x003B1A90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A90u);
	// 0x25DFF8: movss [0x004D6108], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6108u, ctx.xmm[0].u32[0]);
	// 0x25E000: ret
	return;
}

void sub_25E010(X86Context& ctx, uint8_t* base) {
	// 0x25E010: movss xmm0, dword ptr [0x0038845C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x38845Cu);
	// 0x25E018: movss [0x004D612C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D612Cu, ctx.xmm[0].u32[0]);
	// 0x25E020: ret
	return;
}

void sub_25E030(X86Context& ctx, uint8_t* base) {
	// 0x25E030: movss xmm0, dword ptr [0x003B2118]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2118u);
	// 0x25E038: movss [0x004D6154], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6154u, ctx.xmm[0].u32[0]);
	// 0x25E040: ret
	return;
}

void sub_25E050(X86Context& ctx, uint8_t* base) {
	// 0x25E050: movss xmm0, dword ptr [0x003B211C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B211Cu);
	// 0x25E058: movss [0x004D60D8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60D8u, ctx.xmm[0].u32[0]);
	// 0x25E060: ret
	return;
}

void sub_25E070(X86Context& ctx, uint8_t* base) {
	// 0x25E070: movss xmm0, dword ptr [0x004D60D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D60D8u);
	// 0x25E078: mulss xmm0, [0x003B2120]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B2120u);
	// 0x25E080: movss [0x004D6148], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6148u, ctx.xmm[0].u32[0]);
	// 0x25E088: ret
	return;
}

void sub_25E090(X86Context& ctx, uint8_t* base) {
	// 0x25E090: movss xmm0, dword ptr [0x003B2118]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2118u);
	// 0x25E098: movss [0x004D6104], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6104u, ctx.xmm[0].u32[0]);
	// 0x25E0A0: ret
	return;
}

void sub_25E0B0(X86Context& ctx, uint8_t* base) {
	// 0x25E0B0: movss xmm0, dword ptr [0x003B2124]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2124u);
	// 0x25E0B8: movss [0x004D6114], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6114u, ctx.xmm[0].u32[0]);
	// 0x25E0C0: ret
	return;
}

void sub_25E0D0(X86Context& ctx, uint8_t* base) {
	// 0x25E0D0: movss xmm0, dword ptr [0x003B2128]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2128u);
	// 0x25E0D8: movss [0x004D60E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60E8u, ctx.xmm[0].u32[0]);
	// 0x25E0E0: ret
	return;
}

void sub_25E0F0(X86Context& ctx, uint8_t* base) {
	// 0x25E0F0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x25E0F8: subss xmm0, [0x004D6154]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D6154u);
	// 0x25E100: subss xmm0, [0x004D60E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D60E8u);
	// 0x25E108: movss [0x004D60EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60ECu, ctx.xmm[0].u32[0]);
	// 0x25E110: ret
	return;
}

void sub_25E120(X86Context& ctx, uint8_t* base) {
	// 0x25E120: movss xmm0, dword ptr [0x003B212C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B212Cu);
	// 0x25E128: movss [0x004D60E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60E4u, ctx.xmm[0].u32[0]);
	// 0x25E130: ret
	return;
}

void sub_25E140(X86Context& ctx, uint8_t* base) {
	// 0x25E140: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x25E148: subss xmm0, [0x004D60E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D60E4u);
	// 0x25E150: movss xmm1, dword ptr [0x004D6114]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x4D6114u);
	// 0x25E158: subss xmm0, [0x004D60E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D60E8u);
	// 0x25E160: mulss xmm1, [0x003A55F8]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3A55F8u);
	// 0x25E168: subss xmm0, xmm1
	ctx.xmm[0].f32[0] -= ctx.xmm[1].f32[0];
	// 0x25E16C: movss [0x004D6130], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6130u, ctx.xmm[0].u32[0]);
	// 0x25E174: ret
	return;
}

void sub_25E180(X86Context& ctx, uint8_t* base) {
	// 0x25E180: movss xmm0, dword ptr [0x003A3230]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A3230u);
	// 0x25E188: movss [0x004D6124], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6124u, ctx.xmm[0].u32[0]);
	// 0x25E190: ret
	return;
}

void sub_25E1A0(X86Context& ctx, uint8_t* base) {
	// 0x25E1A0: movss xmm0, dword ptr [0x003B2130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2130u);
	// 0x25E1A8: movss [0x004D60F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60F0u, ctx.xmm[0].u32[0]);
	// 0x25E1B0: ret
	return;
}

void sub_25E1C0(X86Context& ctx, uint8_t* base) {
	// 0x25E1C0: movss xmm0, dword ptr [0x003A7F38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7F38u);
	// 0x25E1C8: movss [0x004D614C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D614Cu, ctx.xmm[0].u32[0]);
	// 0x25E1D0: ret
	return;
}

void sub_25E1E0(X86Context& ctx, uint8_t* base) {
	// 0x25E1E0: movss xmm0, dword ptr [0x003B2134]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2134u);
	// 0x25E1E8: movss [0x004D6144], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6144u, ctx.xmm[0].u32[0]);
	// 0x25E1F0: ret
	return;
}

void sub_25E200(X86Context& ctx, uint8_t* base) {
	// 0x25E200: movss xmm0, dword ptr [0x003B2138]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2138u);
	// 0x25E208: movss [0x004D60F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60F8u, ctx.xmm[0].u32[0]);
	// 0x25E210: ret
	return;
}

void sub_25E220(X86Context& ctx, uint8_t* base) {
	// 0x25E220: movss xmm0, dword ptr [0x003B2134]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2134u);
	// 0x25E228: movss [0x004D60C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60C4u, ctx.xmm[0].u32[0]);
	// 0x25E230: ret
	return;
}

void sub_25E240(X86Context& ctx, uint8_t* base) {
	// 0x25E240: movss xmm0, dword ptr [0x003A55F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x25E248: movss [0x004D6134], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6134u, ctx.xmm[0].u32[0]);
	// 0x25E250: ret
	return;
}

void sub_25E260(X86Context& ctx, uint8_t* base) {
	// 0x25E260: movss xmm0, dword ptr [0x004D6134]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6134u);
	// 0x25E268: addss xmm0, [0x003B1730]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1730u);
	// 0x25E270: movss [0x004D6118], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6118u, ctx.xmm[0].u32[0]);
	// 0x25E278: ret
	return;
}

void sub_25E280(X86Context& ctx, uint8_t* base) {
	// 0x25E280: movss xmm0, dword ptr [0x004D6118]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6118u);
	// 0x25E288: addss xmm0, [0x003B1730]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1730u);
	// 0x25E290: movss [0x004D60E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D60E0u, ctx.xmm[0].u32[0]);
	// 0x25E298: ret
	return;
}

void sub_25E2A0(X86Context& ctx, uint8_t* base) {
	// 0x25E2A0: movss xmm0, dword ptr [0x003B213C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B213Cu);
	// 0x25E2A8: movss [0x004D6100], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6100u, ctx.xmm[0].u32[0]);
	// 0x25E2B0: ret
	return;
}

void sub_25E2C0(X86Context& ctx, uint8_t* base) {
	// 0x25E2C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25E2C8: movss [0x004D6C28], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C28u, ctx.xmm[0].u32[0]);
	// 0x25E2D0: ret
	return;
}

void sub_25E2E0(X86Context& ctx, uint8_t* base) {
	// 0x25E2E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25E2E8: movss [0x004D6C34], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C34u, ctx.xmm[0].u32[0]);
	// 0x25E2F0: ret
	return;
}

void sub_25E300(X86Context& ctx, uint8_t* base) {
	// 0x25E300: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25E308: movss [0x004D6C24], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C24u, ctx.xmm[0].u32[0]);
	// 0x25E310: ret
	return;
}

void sub_25E320(X86Context& ctx, uint8_t* base) {
	// 0x25E320: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25E328: movss [0x004D615C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D615Cu, ctx.xmm[0].u32[0]);
	// 0x25E330: ret
	return;
}

void sub_25E340(X86Context& ctx, uint8_t* base) {
	// 0x25E340: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25E348: movss [0x004D6C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C2Cu, ctx.xmm[0].u32[0]);
	// 0x25E350: ret
	return;
}

void sub_25E360(X86Context& ctx, uint8_t* base) {
	// 0x25E360: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25E368: movss [0x004D6164], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6164u, ctx.xmm[0].u32[0]);
	// 0x25E370: ret
	return;
}

void sub_25E380(X86Context& ctx, uint8_t* base) {
	// 0x25E380: movss xmm0, dword ptr [0x004D6C2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6C2Cu);
	// 0x25E388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25E390: movss [0x004D6C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C3Cu, ctx.xmm[0].u32[0]);
	// 0x25E398: ret
	return;
}

void sub_25E3A0(X86Context& ctx, uint8_t* base) {
	// 0x25E3A0: movss xmm0, dword ptr [0x004D6164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6164u);
	// 0x25E3A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25E3B0: movss [0x004D6C38], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C38u, ctx.xmm[0].u32[0]);
	// 0x25E3B8: ret
	return;
}

void sub_25E3C0(X86Context& ctx, uint8_t* base) {
	// 0x25E3C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25E3C8: movss [0x004D6C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C4Cu, ctx.xmm[0].u32[0]);
	// 0x25E3D0: ret
	return;
}

void sub_25E3E0(X86Context& ctx, uint8_t* base) {
	// 0x25E3E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25E3E8: movss [0x004D6C40], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C40u, ctx.xmm[0].u32[0]);
	// 0x25E3F0: ret
	return;
}

void sub_25E400(X86Context& ctx, uint8_t* base) {
	// 0x25E400: movss xmm0, dword ptr [0x004D6C40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6C40u);
	// 0x25E408: movss [0x004D6C48], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C48u, ctx.xmm[0].u32[0]);
	// 0x25E410: ret
	return;
}

void sub_25E420(X86Context& ctx, uint8_t* base) {
	// 0x25E420: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25E428: movss [0x004D6160], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6160u, ctx.xmm[0].u32[0]);
	// 0x25E430: ret
	return;
}

void sub_25E440(X86Context& ctx, uint8_t* base) {
	// 0x25E440: movss xmm0, dword ptr [0x004D6164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6164u);
	// 0x25E448: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25E450: movss [0x004D6C44], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C44u, ctx.xmm[0].u32[0]);
	// 0x25E458: ret
	return;
}

void sub_25E460(X86Context& ctx, uint8_t* base) {
	// 0x25E460: movss xmm0, dword ptr [0x004D6164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6164u);
	// 0x25E468: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25E470: movss [0x004D6C20], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C20u, ctx.xmm[0].u32[0]);
	// 0x25E478: ret
	return;
}

void sub_25E480(X86Context& ctx, uint8_t* base) {
	// 0x25E480: movss xmm0, dword ptr [0x004D6164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6164u);
	// 0x25E488: subss xmm0, [0x004D6C20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D6C20u);
	// 0x25E490: movss [0x004D616C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D616Cu, ctx.xmm[0].u32[0]);
	// 0x25E498: ret
	return;
}

void sub_25E4A0(X86Context& ctx, uint8_t* base) {
	// 0x25E4A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25E4A8: movss [0x004D6C30], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C30u, ctx.xmm[0].u32[0]);
	// 0x25E4B0: ret
	return;
}

void sub_25E4C0(X86Context& ctx, uint8_t* base) {
	// 0x25E4C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25E4C8: movss [0x004D6168], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6168u, ctx.xmm[0].u32[0]);
	// 0x25E4D0: ret
	return;
}

void sub_25E4E0(X86Context& ctx, uint8_t* base) {
	// 0x25E4E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25E4E8: movss [0x004D6C54], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C54u, ctx.xmm[0].u32[0]);
	// 0x25E4F0: ret
	return;
}

void sub_25E500(X86Context& ctx, uint8_t* base) {
	// 0x25E500: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25E508: movss [0x004D6C58], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C58u, ctx.xmm[0].u32[0]);
	// 0x25E510: ret
	return;
}

void sub_25E520(X86Context& ctx, uint8_t* base) {
	// 0x25E520: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25E528: movss [0x004D6C50], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C50u, ctx.xmm[0].u32[0]);
	// 0x25E530: ret
	return;
}

void sub_25E540(X86Context& ctx, uint8_t* base) {
	// 0x25E540: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25E548: movss [0x004D6C68], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C68u, ctx.xmm[0].u32[0]);
	// 0x25E550: ret
	return;
}

void sub_25E560(X86Context& ctx, uint8_t* base) {
	// 0x25E560: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25E568: movss [0x004D6C70], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C70u, ctx.xmm[0].u32[0]);
	// 0x25E570: ret
	return;
}

void sub_25E580(X86Context& ctx, uint8_t* base) {
	// 0x25E580: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25E588: movss [0x004D6C64], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C64u, ctx.xmm[0].u32[0]);
	// 0x25E590: ret
	return;
}

void sub_25E5A0(X86Context& ctx, uint8_t* base) {
	// 0x25E5A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25E5A8: movss [0x004D6C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C5Cu, ctx.xmm[0].u32[0]);
	// 0x25E5B0: ret
	return;
}

void sub_25E5C0(X86Context& ctx, uint8_t* base) {
	// 0x25E5C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25E5C8: movss [0x004D6C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C6Cu, ctx.xmm[0].u32[0]);
	// 0x25E5D0: ret
	return;
}

void sub_25E5E0(X86Context& ctx, uint8_t* base) {
	// 0x25E5E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25E5E8: movss [0x004D6C60], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C60u, ctx.xmm[0].u32[0]);
	// 0x25E5F0: ret
	return;
}

void sub_25E600(X86Context& ctx, uint8_t* base) {
	// 0x25E600: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25E608: movss [0x004D7018], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7018u, ctx.xmm[0].u32[0]);
	// 0x25E610: ret
	return;
}

void sub_25E620(X86Context& ctx, uint8_t* base) {
	// 0x25E620: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25E628: movss [0x004D7024], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7024u, ctx.xmm[0].u32[0]);
	// 0x25E630: ret
	return;
}

void sub_25E640(X86Context& ctx, uint8_t* base) {
	// 0x25E640: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25E648: movss [0x004D7014], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7014u, ctx.xmm[0].u32[0]);
	// 0x25E650: ret
	return;
}

void sub_25E660(X86Context& ctx, uint8_t* base) {
	// 0x25E660: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25E668: movss [0x004D6C74], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C74u, ctx.xmm[0].u32[0]);
	// 0x25E670: ret
	return;
}

void sub_25E680(X86Context& ctx, uint8_t* base) {
	// 0x25E680: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25E688: movss [0x004D701C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D701Cu, ctx.xmm[0].u32[0]);
	// 0x25E690: ret
	return;
}

void sub_25E6A0(X86Context& ctx, uint8_t* base) {
	// 0x25E6A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25E6A8: movss [0x004D6C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C7Cu, ctx.xmm[0].u32[0]);
	// 0x25E6B0: ret
	return;
}

void sub_25E6C0(X86Context& ctx, uint8_t* base) {
	// 0x25E6C0: movss xmm0, dword ptr [0x004D701C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D701Cu);
	// 0x25E6C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25E6D0: movss [0x004D702C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D702Cu, ctx.xmm[0].u32[0]);
	// 0x25E6D8: ret
	return;
}

void sub_25E6E0(X86Context& ctx, uint8_t* base) {
	// 0x25E6E0: movss xmm0, dword ptr [0x004D6C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6C7Cu);
	// 0x25E6E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25E6F0: movss [0x004D7028], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7028u, ctx.xmm[0].u32[0]);
	// 0x25E6F8: ret
	return;
}

void sub_25E700(X86Context& ctx, uint8_t* base) {
	// 0x25E700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25E708: movss [0x004D703C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D703Cu, ctx.xmm[0].u32[0]);
	// 0x25E710: ret
	return;
}

void sub_25E720(X86Context& ctx, uint8_t* base) {
	// 0x25E720: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25E728: movss [0x004D7030], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7030u, ctx.xmm[0].u32[0]);
	// 0x25E730: ret
	return;
}

void sub_25E740(X86Context& ctx, uint8_t* base) {
	// 0x25E740: movss xmm0, dword ptr [0x004D7030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D7030u);
	// 0x25E748: movss [0x004D7038], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7038u, ctx.xmm[0].u32[0]);
	// 0x25E750: ret
	return;
}

void sub_25E760(X86Context& ctx, uint8_t* base) {
	// 0x25E760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25E768: movss [0x004D6C78], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C78u, ctx.xmm[0].u32[0]);
	// 0x25E770: ret
	return;
}

void sub_25E780(X86Context& ctx, uint8_t* base) {
	// 0x25E780: movss xmm0, dword ptr [0x004D6C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6C7Cu);
	// 0x25E788: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25E790: movss [0x004D7034], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7034u, ctx.xmm[0].u32[0]);
	// 0x25E798: ret
	return;
}

void sub_25E7A0(X86Context& ctx, uint8_t* base) {
	// 0x25E7A0: movss xmm0, dword ptr [0x004D6C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6C7Cu);
	// 0x25E7A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25E7B0: movss [0x004D7010], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7010u, ctx.xmm[0].u32[0]);
	// 0x25E7B8: ret
	return;
}

void sub_25E7C0(X86Context& ctx, uint8_t* base) {
	// 0x25E7C0: movss xmm0, dword ptr [0x004D6C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D6C7Cu);
	// 0x25E7C8: subss xmm0, [0x004D7010]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D7010u);
	// 0x25E7D0: movss [0x004D6C84], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C84u, ctx.xmm[0].u32[0]);
	// 0x25E7D8: ret
	return;
}

void sub_25E7E0(X86Context& ctx, uint8_t* base) {
	// 0x25E7E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25E7E8: movss [0x004D7020], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7020u, ctx.xmm[0].u32[0]);
	// 0x25E7F0: ret
	return;
}

void sub_25E800(X86Context& ctx, uint8_t* base) {
	// 0x25E800: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25E808: movss [0x004D6C80], xmm0
	X86_MEM_WRITE_u32(base, 0x4D6C80u, ctx.xmm[0].u32[0]);
	// 0x25E810: ret
	return;
}

void sub_25E820(X86Context& ctx, uint8_t* base) {
	// 0x25E820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25E828: movss [0x004D9140], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9140u, ctx.xmm[0].u32[0]);
	// 0x25E830: ret
	return;
}

void sub_25E840(X86Context& ctx, uint8_t* base) {
	// 0x25E840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25E848: movss [0x004D914C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D914Cu, ctx.xmm[0].u32[0]);
	// 0x25E850: ret
	return;
}

void sub_25E860(X86Context& ctx, uint8_t* base) {
	// 0x25E860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25E868: movss [0x004D705C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D705Cu, ctx.xmm[0].u32[0]);
	// 0x25E870: ret
	return;
}

void sub_25E880(X86Context& ctx, uint8_t* base) {
	// 0x25E880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25E888: movss [0x004D7040], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7040u, ctx.xmm[0].u32[0]);
	// 0x25E890: ret
	return;
}

void sub_25E8A0(X86Context& ctx, uint8_t* base) {
	// 0x25E8A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25E8A8: movss [0x004D9144], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9144u, ctx.xmm[0].u32[0]);
	// 0x25E8B0: ret
	return;
}

void sub_25E8C0(X86Context& ctx, uint8_t* base) {
	// 0x25E8C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25E8C8: movss [0x004D7048], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7048u, ctx.xmm[0].u32[0]);
	// 0x25E8D0: ret
	return;
}

void sub_25E8E0(X86Context& ctx, uint8_t* base) {
	// 0x25E8E0: movss xmm0, dword ptr [0x004D9144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D9144u);
	// 0x25E8E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25E8F0: movss [0x004D9158], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9158u, ctx.xmm[0].u32[0]);
	// 0x25E8F8: ret
	return;
}

void sub_25E900(X86Context& ctx, uint8_t* base) {
	// 0x25E900: movss xmm0, dword ptr [0x004D7048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D7048u);
	// 0x25E908: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25E910: movss [0x004D9150], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9150u, ctx.xmm[0].u32[0]);
	// 0x25E918: ret
	return;
}

void sub_25E920(X86Context& ctx, uint8_t* base) {
	// 0x25E920: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25E928: movss [0x004D9178], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9178u, ctx.xmm[0].u32[0]);
	// 0x25E930: ret
	return;
}

void sub_25E940(X86Context& ctx, uint8_t* base) {
	// 0x25E940: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25E948: movss [0x004D915C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D915Cu, ctx.xmm[0].u32[0]);
	// 0x25E950: ret
	return;
}

void sub_25E960(X86Context& ctx, uint8_t* base) {
	// 0x25E960: movss xmm0, dword ptr [0x004D915C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D915Cu);
	// 0x25E968: movss [0x004D9170], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9170u, ctx.xmm[0].u32[0]);
	// 0x25E970: ret
	return;
}

void sub_25E980(X86Context& ctx, uint8_t* base) {
	// 0x25E980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25E988: movss [0x004D7044], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7044u, ctx.xmm[0].u32[0]);
	// 0x25E990: ret
	return;
}

void sub_25E9A0(X86Context& ctx, uint8_t* base) {
	// 0x25E9A0: movss xmm0, dword ptr [0x004D7048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D7048u);
	// 0x25E9A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25E9B0: movss [0x004D9160], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9160u, ctx.xmm[0].u32[0]);
	// 0x25E9B8: ret
	return;
}

void sub_25E9C0(X86Context& ctx, uint8_t* base) {
	// 0x25E9C0: movss xmm0, dword ptr [0x004D7048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D7048u);
	// 0x25E9C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25E9D0: movss [0x004D7054], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7054u, ctx.xmm[0].u32[0]);
	// 0x25E9D8: ret
	return;
}

void sub_25E9E0(X86Context& ctx, uint8_t* base) {
	// 0x25E9E0: movss xmm0, dword ptr [0x004D7048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D7048u);
	// 0x25E9E8: subss xmm0, [0x004D7054]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D7054u);
	// 0x25E9F0: movss [0x004D7050], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7050u, ctx.xmm[0].u32[0]);
	// 0x25E9F8: ret
	return;
}

void sub_25EA00(X86Context& ctx, uint8_t* base) {
	// 0x25EA00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25EA08: movss [0x004D9148], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9148u, ctx.xmm[0].u32[0]);
	// 0x25EA10: ret
	return;
}

void sub_25EA20(X86Context& ctx, uint8_t* base) {
	// 0x25EA20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25EA28: movss [0x004D704C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D704Cu, ctx.xmm[0].u32[0]);
	// 0x25EA30: ret
	return;
}

void sub_25EA40(X86Context& ctx, uint8_t* base) {
	// 0x25EA40: movss xmm0, dword ptr [0x003B2140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2140u);
	// 0x25EA48: movss [0x004D7058], xmm0
	X86_MEM_WRITE_u32(base, 0x4D7058u, ctx.xmm[0].u32[0]);
	// 0x25EA50: ret
	return;
}

void sub_25EA60(X86Context& ctx, uint8_t* base) {
	// 0x25EA60: movss xmm0, dword ptr [0x003B1A90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A90u);
	// 0x25EA68: movss [0x004D9154], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9154u, ctx.xmm[0].u32[0]);
	// 0x25EA70: ret
	return;
}

void sub_25EA80(X86Context& ctx, uint8_t* base) {
	// 0x25EA80: movss xmm0, dword ptr [0x003B2140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2140u);
	// 0x25EA88: movss [0x004D9164], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9164u, ctx.xmm[0].u32[0]);
	// 0x25EA90: ret
	return;
}

void sub_25EAA0(X86Context& ctx, uint8_t* base) {
	// 0x25EAA0: movss xmm0, dword ptr [0x003B1F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F50u);
	// 0x25EAA8: movss [0x004D9168], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9168u, ctx.xmm[0].u32[0]);
	// 0x25EAB0: ret
	return;
}

void sub_25EAC0(X86Context& ctx, uint8_t* base) {
	// 0x25EAC0: movss xmm0, dword ptr [0x003B18F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B18F0u);
	// 0x25EAC8: movss [0x004D9174], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9174u, ctx.xmm[0].u32[0]);
	// 0x25EAD0: ret
	return;
}

void sub_25EAE0(X86Context& ctx, uint8_t* base) {
	// 0x25EAE0: movss xmm0, dword ptr [0x003B2144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2144u);
	// 0x25EAE8: movss [0x004D916C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D916Cu, ctx.xmm[0].u32[0]);
	// 0x25EAF0: ret
	return;
}

void sub_25EB00(X86Context& ctx, uint8_t* base) {
	// 0x25EB00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25EB08: movss [0x004D9180], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9180u, ctx.xmm[0].u32[0]);
	// 0x25EB10: ret
	return;
}

void sub_25EB20(X86Context& ctx, uint8_t* base) {
	// 0x25EB20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25EB28: movss [0x004D9184], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9184u, ctx.xmm[0].u32[0]);
	// 0x25EB30: ret
	return;
}

void sub_25EB40(X86Context& ctx, uint8_t* base) {
	// 0x25EB40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25EB48: movss [0x004D917C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D917Cu, ctx.xmm[0].u32[0]);
	// 0x25EB50: ret
	return;
}

void sub_25EB60(X86Context& ctx, uint8_t* base) {
	// 0x25EB60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x25EB68: movss [0x004D9230], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9230u, ctx.xmm[0].u32[0]);
	// 0x25EB70: ret
	return;
}

void sub_25EB80(X86Context& ctx, uint8_t* base) {
	// 0x25EB80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x25EB88: movss [0x004D9314], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9314u, ctx.xmm[0].u32[0]);
	// 0x25EB90: ret
	return;
}

void sub_25EBA0(X86Context& ctx, uint8_t* base) {
	// 0x25EBA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x25EBA8: movss [0x004D9210], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9210u, ctx.xmm[0].u32[0]);
	// 0x25EBB0: ret
	return;
}

void sub_25EBC0(X86Context& ctx, uint8_t* base) {
	// 0x25EBC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x25EBC8: movss [0x004D9188], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9188u, ctx.xmm[0].u32[0]);
	// 0x25EBD0: ret
	return;
}

void sub_25EBE0(X86Context& ctx, uint8_t* base) {
	// 0x25EBE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x25EBE8: movss [0x004D9234], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9234u, ctx.xmm[0].u32[0]);
	// 0x25EBF0: ret
	return;
}

void sub_25EC00(X86Context& ctx, uint8_t* base) {
	// 0x25EC00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x25EC08: movss [0x004D9190], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9190u, ctx.xmm[0].u32[0]);
	// 0x25EC10: ret
	return;
}

void sub_25EC20(X86Context& ctx, uint8_t* base) {
	// 0x25EC20: movss xmm0, dword ptr [0x004D9234]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D9234u);
	// 0x25EC28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x25EC30: movss [0x004D93E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93E8u, ctx.xmm[0].u32[0]);
	// 0x25EC38: ret
	return;
}

void sub_25EC40(X86Context& ctx, uint8_t* base) {
	// 0x25EC40: movss xmm0, dword ptr [0x004D9190]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D9190u);
	// 0x25EC48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x25EC50: movss [0x004D93E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93E0u, ctx.xmm[0].u32[0]);
	// 0x25EC58: ret
	return;
}

void sub_25EC60(X86Context& ctx, uint8_t* base) {
	// 0x25EC60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25EC68: movss [0x004D9410], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9410u, ctx.xmm[0].u32[0]);
	// 0x25EC70: ret
	return;
}

void sub_25EC80(X86Context& ctx, uint8_t* base) {
	// 0x25EC80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x25EC88: movss [0x004D93EC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93ECu, ctx.xmm[0].u32[0]);
	// 0x25EC90: ret
	return;
}

void sub_25ECA0(X86Context& ctx, uint8_t* base) {
	// 0x25ECA0: movss xmm0, dword ptr [0x004D93EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D93ECu);
	// 0x25ECA8: movss [0x004D9400], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9400u, ctx.xmm[0].u32[0]);
	// 0x25ECB0: ret
	return;
}

void sub_25ECC0(X86Context& ctx, uint8_t* base) {
	// 0x25ECC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x25ECC8: movss [0x004D918C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D918Cu, ctx.xmm[0].u32[0]);
	// 0x25ECD0: ret
	return;
}

void sub_25ECE0(X86Context& ctx, uint8_t* base) {
	// 0x25ECE0: movss xmm0, dword ptr [0x004D9190]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D9190u);
	// 0x25ECE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x25ECF0: movss [0x004D93F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93F0u, ctx.xmm[0].u32[0]);
	// 0x25ECF8: ret
	return;
}

void sub_25ED00(X86Context& ctx, uint8_t* base) {
	// 0x25ED00: movss xmm0, dword ptr [0x004D9190]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D9190u);
	// 0x25ED08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x25ED10: movss [0x004D9208], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9208u, ctx.xmm[0].u32[0]);
	// 0x25ED18: ret
	return;
}

void sub_25ED20(X86Context& ctx, uint8_t* base) {
	// 0x25ED20: movss xmm0, dword ptr [0x004D9190]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D9190u);
	// 0x25ED28: subss xmm0, [0x004D9208]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D9208u);
	// 0x25ED30: movss [0x004D91F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D91F8u, ctx.xmm[0].u32[0]);
	// 0x25ED38: ret
	return;
}

void sub_25ED40(X86Context& ctx, uint8_t* base) {
	// 0x25ED40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25ED48: movss [0x004D9310], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9310u, ctx.xmm[0].u32[0]);
	// 0x25ED50: ret
	return;
}

void sub_25ED60(X86Context& ctx, uint8_t* base) {
	// 0x25ED60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x25ED68: movss [0x004D9194], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9194u, ctx.xmm[0].u32[0]);
	// 0x25ED70: ret
	return;
}

void sub_25ED80(X86Context& ctx, uint8_t* base) {
	// 0x25ED80: movss xmm0, dword ptr [0x003B2140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2140u);
	// 0x25ED88: movss [0x004D920C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D920Cu, ctx.xmm[0].u32[0]);
	// 0x25ED90: ret
	return;
}

void sub_25EDA0(X86Context& ctx, uint8_t* base) {
	// 0x25EDA0: movss xmm0, dword ptr [0x003B1A90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A90u);
	// 0x25EDA8: movss [0x004D93E4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93E4u, ctx.xmm[0].u32[0]);
	// 0x25EDB0: ret
	return;
}

void sub_25EDC0(X86Context& ctx, uint8_t* base) {
	// 0x25EDC0: movss xmm0, dword ptr [0x003B2140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2140u);
	// 0x25EDC8: movss [0x004D93F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93F4u, ctx.xmm[0].u32[0]);
	// 0x25EDD0: ret
	return;
}

void sub_25EDE0(X86Context& ctx, uint8_t* base) {
	// 0x25EDE0: movss xmm0, dword ptr [0x003B1F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F50u);
	// 0x25EDE8: movss [0x004D93FC], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93FCu, ctx.xmm[0].u32[0]);
	// 0x25EDF0: ret
	return;
}

void sub_25EE00(X86Context& ctx, uint8_t* base) {
	// 0x25EE00: movss xmm0, dword ptr [0x003B2148]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2148u);
	// 0x25EE08: movss [0x004D93F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4D93F8u, ctx.xmm[0].u32[0]);
	// 0x25EE10: ret
	return;
}

void sub_25EE20(X86Context& ctx, uint8_t* base) {
	// 0x25EE20: movss xmm1, dword ptr [0x003A2D50]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25EE28: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x25EE30: movss xmm3, dword ptr [0x003A69C4]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A69C4u);
	// 0x25EE38: movss xmm7, dword ptr [0x003B16D4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16D4u);
	// 0x25EE40: movss xmm2, dword ptr [0x003A69B4]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3A69B4u);
	// 0x25EE48: xorps xmm4, xmm4
	memset(&ctx.xmm[4], 0, sizeof(ctx.xmm[4]));
	// 0x25EE4B: movss xmm5, dword ptr [0x003A7950]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3A7950u);
	// 0x25EE53: movss xmm6, dword ptr [0x003A7ED8]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25EE5B: movss [0x00418330], xmm1
	X86_MEM_WRITE_u32(base, 0x418330u, ctx.xmm[1].u32[0]);
	// 0x25EE63: movss xmm1, dword ptr [0x003A5600]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x25EE6B: movss [0x00418334], xmm1
	X86_MEM_WRITE_u32(base, 0x418334u, ctx.xmm[1].u32[0]);
	// 0x25EE73: movss xmm1, dword ptr [0x0039B2B0]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25EE7B: movss [0x00418348], xmm1
	X86_MEM_WRITE_u32(base, 0x418348u, ctx.xmm[1].u32[0]);
	// 0x25EE83: movss [0x0041834C], xmm1
	X86_MEM_WRITE_u32(base, 0x41834Cu, ctx.xmm[1].u32[0]);
	// 0x25EE8B: movss [0x00418350], xmm1
	X86_MEM_WRITE_u32(base, 0x418350u, ctx.xmm[1].u32[0]);
	// 0x25EE93: movss xmm1, dword ptr [0x003A795C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A795Cu);
	// 0x25EE9B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x25EE9C: movss [0x00418360], xmm1
	X86_MEM_WRITE_u32(base, 0x418360u, ctx.xmm[1].u32[0]);
	// 0x25EEA4: movss xmm1, dword ptr [0x003B2154]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B2154u);
	// 0x25EEAC: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x25EEAD: movss [0x00418364], xmm1
	X86_MEM_WRITE_u32(base, 0x418364u, ctx.xmm[1].u32[0]);
	// 0x25EEB5: movss xmm1, dword ptr [0x003B17C8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x25EEBD: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x25EEBF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x25EEC0: movss [0x0041838C], xmm1
	X86_MEM_WRITE_u32(base, 0x41838Cu, ctx.xmm[1].u32[0]);
	// 0x25EEC8: movss xmm1, dword ptr [0x003B1870]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25EED0: mov edx, 0x01
	ctx.edx = 1;
	// 0x25EED5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x25EED6: mov eax, 0xFF
	ctx.eax = 255;
	// 0x25EEDB: mov bl, 0xC0
	X86_REG8L(ctx.ebx) = (uint8_t)(-64);
	// 0x25EEDD: mov esi, 0x03
	ctx.esi = 3;
	// 0x25EEE2: mov ebp, 0x64
	ctx.ebp = 100;
	// 0x25EEE7: mov edi, 0x40
	ctx.edi = 64;
	// 0x25EEEC: movss [0x00418390], xmm1
	X86_MEM_WRITE_u32(base, 0x418390u, ctx.xmm[1].u32[0]);
	// 0x25EEF4: movss xmm1, dword ptr [0x003B1684]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x25EEFC: movss [0x00418318], xmm0
	X86_MEM_WRITE_u32(base, 0x418318u, ctx.xmm[0].u32[0]);
	// 0x25EF04: movss [0x0041831C], xmm0
	X86_MEM_WRITE_u32(base, 0x41831Cu, ctx.xmm[0].u32[0]);
	// 0x25EF0C: mov dword ptr [0x00418320], 0x3AAF44
	X86_MEM_WRITE_u32(base, 0x418320u, 3845956);
	// 0x25EF16: mov [0x00418324], dl
	X86_MEM_WRITE_u8(base, 0x418324u, X86_REG8L(ctx.edx));
	// 0x25EF1C: mov [0x00418328], esi
	X86_MEM_WRITE_u32(base, 0x418328u, ctx.esi);
	// 0x25EF22: mov [0x0041832C], ecx
	X86_MEM_WRITE_u32(base, 0x41832Cu, ctx.ecx);
	// 0x25EF28: mov byte ptr [0x00418338], 0x60
	X86_MEM_WRITE_u8(base, 0x418338u, 96);
	// 0x25EF2F: mov byte ptr [0x00418339], 0x60
	X86_MEM_WRITE_u8(base, 0x418339u, 96);
	// 0x25EF36: mov byte ptr [0x0041833A], 0x60
	X86_MEM_WRITE_u8(base, 0x41833Au, 96);
	// 0x25EF3D: mov [0x0041833B], al
	X86_MEM_WRITE_u8(base, 0x41833Bu, X86_REG8L(ctx.eax));
	// 0x25EF42: mov byte ptr [0x0041833C], 0x60
	X86_MEM_WRITE_u8(base, 0x41833Cu, 96);
	// 0x25EF49: mov byte ptr [0x0041833D], 0x60
	X86_MEM_WRITE_u8(base, 0x41833Du, 96);
	// 0x25EF50: mov byte ptr [0x0041833E], 0x60
	X86_MEM_WRITE_u8(base, 0x41833Eu, 96);
	// 0x25EF57: mov [0x0041833F], al
	X86_MEM_WRITE_u8(base, 0x41833Fu, X86_REG8L(ctx.eax));
	// 0x25EF5C: mov byte ptr [0x00418340], 0x60
	X86_MEM_WRITE_u8(base, 0x418340u, 96);
	// 0x25EF63: mov byte ptr [0x00418341], 0x60
	X86_MEM_WRITE_u8(base, 0x418341u, 96);
	// 0x25EF6A: mov byte ptr [0x00418342], 0x60
	X86_MEM_WRITE_u8(base, 0x418342u, 96);
	// 0x25EF71: mov byte ptr [0x00418343], 0x40
	X86_MEM_WRITE_u8(base, 0x418343u, 64);
	// 0x25EF78: mov [0x00418344], cl
	X86_MEM_WRITE_u8(base, 0x418344u, X86_REG8L(ctx.ecx));
	// 0x25EF7E: movss [0x00418354], xmm3
	X86_MEM_WRITE_u32(base, 0x418354u, ctx.xmm[3].u32[0]);
	// 0x25EF86: movss [0x00418358], xmm7
	X86_MEM_WRITE_u32(base, 0x418358u, ctx.xmm[7].u32[0]);
	// 0x25EF8E: movss [0x0041835C], xmm2
	X86_MEM_WRITE_u32(base, 0x41835Cu, ctx.xmm[2].u32[0]);
	// 0x25EF96: movss [0x00418368], xmm4
	X86_MEM_WRITE_u32(base, 0x418368u, ctx.xmm[4].u32[0]);
	// 0x25EF9E: movss [0x0041836C], xmm3
	X86_MEM_WRITE_u32(base, 0x41836Cu, ctx.xmm[3].u32[0]);
	// 0x25EFA6: movss [0x00418370], xmm3
	X86_MEM_WRITE_u32(base, 0x418370u, ctx.xmm[3].u32[0]);
	// 0x25EFAE: movss [0x00418374], xmm0
	X86_MEM_WRITE_u32(base, 0x418374u, ctx.xmm[0].u32[0]);
	// 0x25EFB6: movss [0x00418378], xmm0
	X86_MEM_WRITE_u32(base, 0x418378u, ctx.xmm[0].u32[0]);
	// 0x25EFBE: mov [0x0041837C], cl
	X86_MEM_WRITE_u8(base, 0x41837Cu, X86_REG8L(ctx.ecx));
	// 0x25EFC4: mov [0x0041837D], dl
	X86_MEM_WRITE_u8(base, 0x41837Du, X86_REG8L(ctx.edx));
	// 0x25EFCA: mov [0x00418380], ebp
	X86_MEM_WRITE_u32(base, 0x418380u, ctx.ebp);
	// 0x25EFD0: mov dword ptr [0x00418384], 0xC8
	X86_MEM_WRITE_u32(base, 0x418384u, 200);
	// 0x25EFDA: mov [0x00418388], edi
	X86_MEM_WRITE_u32(base, 0x418388u, ctx.edi);
	// 0x25EFE0: movss [0x00418394], xmm5
	X86_MEM_WRITE_u32(base, 0x418394u, ctx.xmm[5].u32[0]);
	// 0x25EFE8: movss [0x00418398], xmm0
	X86_MEM_WRITE_u32(base, 0x418398u, ctx.xmm[0].u32[0]);
	// 0x25EFF0: movss [0x0041839C], xmm0
	X86_MEM_WRITE_u32(base, 0x41839Cu, ctx.xmm[0].u32[0]);
	// 0x25EFF8: mov dword ptr [0x004183A0], 0x3AAF50
	X86_MEM_WRITE_u32(base, 0x4183A0u, 3845968);
	// 0x25F002: mov [0x004183A4], dl
	X86_MEM_WRITE_u8(base, 0x4183A4u, X86_REG8L(ctx.edx));
	// 0x25F008: mov [0x004183A8], ecx
	X86_MEM_WRITE_u32(base, 0x4183A8u, ctx.ecx);
	// 0x25F00E: mov [0x004183AC], ecx
	X86_MEM_WRITE_u32(base, 0x4183ACu, ctx.ecx);
	// 0x25F014: movss [0x004183B0], xmm1
	X86_MEM_WRITE_u32(base, 0x4183B0u, ctx.xmm[1].u32[0]);
	// 0x25F01C: movss [0x004183B4], xmm6
	X86_MEM_WRITE_u32(base, 0x4183B4u, ctx.xmm[6].u32[0]);
	// 0x25F024: mov [0x004183B8], bl
	X86_MEM_WRITE_u8(base, 0x4183B8u, X86_REG8L(ctx.ebx));
	// 0x25F02A: mov byte ptr [0x004183B9], 0xB0
	X86_MEM_WRITE_u8(base, 0x4183B9u, -80);
	// 0x25F031: mov byte ptr [0x004183BA], 0x90
	X86_MEM_WRITE_u8(base, 0x4183BAu, -112);
	// 0x25F038: mov [0x004183BB], cl
	X86_MEM_WRITE_u8(base, 0x4183BBu, X86_REG8L(ctx.ecx));
	// 0x25F03E: mov [0x004183BC], bl
	X86_MEM_WRITE_u8(base, 0x4183BCu, X86_REG8L(ctx.ebx));
	// 0x25F044: movss [0x004183D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4183D8u, ctx.xmm[7].u32[0]);
	// 0x25F04C: movss xmm7, dword ptr [0x003A795C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A795Cu);
	// 0x25F054: movss [0x004183E0], xmm7
	X86_MEM_WRITE_u32(base, 0x4183E0u, ctx.xmm[7].u32[0]);
	// 0x25F05C: movss xmm7, dword ptr [0x003B19C4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B19C4u);
	// 0x25F064: movss [0x004183E4], xmm7
	X86_MEM_WRITE_u32(base, 0x4183E4u, ctx.xmm[7].u32[0]);
	// 0x25F06C: movss xmm7, dword ptr [0x003B1768]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x25F074: movss xmm6, dword ptr [0x003B16EC]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x25F07C: movss [0x004183F4], xmm7
	X86_MEM_WRITE_u32(base, 0x4183F4u, ctx.xmm[7].u32[0]);
	// 0x25F084: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25F08C: movss [0x0041840C], xmm7
	X86_MEM_WRITE_u32(base, 0x41840Cu, ctx.xmm[7].u32[0]);
	// 0x25F094: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25F09C: movss [0x00418410], xmm7
	X86_MEM_WRITE_u32(base, 0x418410u, ctx.xmm[7].u32[0]);
	// 0x25F0A4: movss xmm7, dword ptr [0x003B1A08]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1A08u);
	// 0x25F0AC: movss [0x00418434], xmm7
	X86_MEM_WRITE_u32(base, 0x418434u, ctx.xmm[7].u32[0]);
	// 0x25F0B4: movss xmm7, dword ptr [0x003B16E8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x25F0BC: movss [0x00418448], xmm7
	X86_MEM_WRITE_u32(base, 0x418448u, ctx.xmm[7].u32[0]);
	// 0x25F0C4: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x25F0CC: movss [0x0041844C], xmm7
	X86_MEM_WRITE_u32(base, 0x41844Cu, ctx.xmm[7].u32[0]);
	// 0x25F0D4: movss xmm7, dword ptr [0x003A2D50]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25F0DC: movss [0x00418450], xmm7
	X86_MEM_WRITE_u32(base, 0x418450u, ctx.xmm[7].u32[0]);
	// 0x25F0E4: movss xmm7, dword ptr [0x00384A80]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x384A80u);
	// 0x25F0EC: movss [0x00418454], xmm7
	X86_MEM_WRITE_u32(base, 0x418454u, ctx.xmm[7].u32[0]);
	// 0x25F0F4: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25F0FC: movss [0x00418458], xmm7
	X86_MEM_WRITE_u32(base, 0x418458u, ctx.xmm[7].u32[0]);
	// 0x25F104: movss xmm7, dword ptr [0x003B1730]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x25F10C: movss [0x0041845C], xmm7
	X86_MEM_WRITE_u32(base, 0x41845Cu, ctx.xmm[7].u32[0]);
	// 0x25F114: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25F11C: movss [0x00418460], xmm7
	X86_MEM_WRITE_u32(base, 0x418460u, ctx.xmm[7].u32[0]);
	// 0x25F124: movss xmm7, dword ptr [0x003B1AC4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1AC4u);
	// 0x25F12C: movss [0x00418464], xmm7
	X86_MEM_WRITE_u32(base, 0x418464u, ctx.xmm[7].u32[0]);
	// 0x25F134: movss xmm7, dword ptr [0x003B1768]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x25F13C: mov byte ptr [0x004183BD], 0xB0
	X86_MEM_WRITE_u8(base, 0x4183BDu, -80);
	// 0x25F143: mov byte ptr [0x004183BE], 0x90
	X86_MEM_WRITE_u8(base, 0x4183BEu, -112);
	// 0x25F14A: mov [0x004183BF], al
	X86_MEM_WRITE_u8(base, 0x4183BFu, X86_REG8L(ctx.eax));
	// 0x25F14F: mov [0x004183C0], bl
	X86_MEM_WRITE_u8(base, 0x4183C0u, X86_REG8L(ctx.ebx));
	// 0x25F155: mov byte ptr [0x004183C1], 0xB0
	X86_MEM_WRITE_u8(base, 0x4183C1u, -80);
	// 0x25F15C: mov byte ptr [0x004183C2], 0x90
	X86_MEM_WRITE_u8(base, 0x4183C2u, -112);
	// 0x25F163: mov byte ptr [0x004183C3], 0x40
	X86_MEM_WRITE_u8(base, 0x4183C3u, 64);
	// 0x25F16A: mov [0x004183C4], cl
	X86_MEM_WRITE_u8(base, 0x4183C4u, X86_REG8L(ctx.ecx));
	// 0x25F170: movss [0x004183C8], xmm6
	X86_MEM_WRITE_u32(base, 0x4183C8u, ctx.xmm[6].u32[0]);
	// 0x25F178: movss [0x004183CC], xmm6
	X86_MEM_WRITE_u32(base, 0x4183CCu, ctx.xmm[6].u32[0]);
	// 0x25F180: movss [0x004183D0], xmm6
	X86_MEM_WRITE_u32(base, 0x4183D0u, ctx.xmm[6].u32[0]);
	// 0x25F188: movss [0x004183D4], xmm3
	X86_MEM_WRITE_u32(base, 0x4183D4u, ctx.xmm[3].u32[0]);
	// 0x25F190: movss [0x004183DC], xmm3
	X86_MEM_WRITE_u32(base, 0x4183DCu, ctx.xmm[3].u32[0]);
	// 0x25F198: movss [0x004183E8], xmm4
	X86_MEM_WRITE_u32(base, 0x4183E8u, ctx.xmm[4].u32[0]);
	// 0x25F1A0: movss [0x004183EC], xmm3
	X86_MEM_WRITE_u32(base, 0x4183ECu, ctx.xmm[3].u32[0]);
	// 0x25F1A8: movss [0x004183F0], xmm2
	X86_MEM_WRITE_u32(base, 0x4183F0u, ctx.xmm[2].u32[0]);
	// 0x25F1B0: movss [0x004183F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4183F8u, ctx.xmm[0].u32[0]);
	// 0x25F1B8: mov [0x004183FC], cl
	X86_MEM_WRITE_u8(base, 0x4183FCu, X86_REG8L(ctx.ecx));
	// 0x25F1BE: mov [0x004183FD], dl
	X86_MEM_WRITE_u8(base, 0x4183FDu, X86_REG8L(ctx.edx));
	// 0x25F1C4: mov dword ptr [0x00418400], 0x3C
	X86_MEM_WRITE_u32(base, 0x418400u, 60);
	// 0x25F1CE: mov [0x00418404], ecx
	X86_MEM_WRITE_u32(base, 0x418404u, ctx.ecx);
	// 0x25F1D4: mov [0x00418408], edi
	X86_MEM_WRITE_u32(base, 0x418408u, ctx.edi);
	// 0x25F1DA: movss [0x00418414], xmm5
	X86_MEM_WRITE_u32(base, 0x418414u, ctx.xmm[5].u32[0]);
	// 0x25F1E2: movss [0x00418418], xmm6
	X86_MEM_WRITE_u32(base, 0x418418u, ctx.xmm[6].u32[0]);
	// 0x25F1EA: movss [0x0041841C], xmm6
	X86_MEM_WRITE_u32(base, 0x41841Cu, ctx.xmm[6].u32[0]);
	// 0x25F1F2: mov dword ptr [0x00418420], 0x3AAF5C
	X86_MEM_WRITE_u32(base, 0x418420u, 3845980);
	// 0x25F1FC: mov [0x00418424], dl
	X86_MEM_WRITE_u8(base, 0x418424u, X86_REG8L(ctx.edx));
	// 0x25F202: mov [0x00418428], edx
	X86_MEM_WRITE_u32(base, 0x418428u, ctx.edx);
	// 0x25F208: mov [0x0041842C], ecx
	X86_MEM_WRITE_u32(base, 0x41842Cu, ctx.ecx);
	// 0x25F20E: movss [0x00418430], xmm1
	X86_MEM_WRITE_u32(base, 0x418430u, ctx.xmm[1].u32[0]);
	// 0x25F216: mov [0x00418438], al
	X86_MEM_WRITE_u8(base, 0x418438u, X86_REG8L(ctx.eax));
	// 0x25F21B: mov [0x00418439], al
	X86_MEM_WRITE_u8(base, 0x418439u, X86_REG8L(ctx.eax));
	// 0x25F220: mov [0x0041843A], al
	X86_MEM_WRITE_u8(base, 0x41843Au, X86_REG8L(ctx.eax));
	// 0x25F225: mov byte ptr [0x0041843B], 0x10
	X86_MEM_WRITE_u8(base, 0x41843Bu, 16);
	// 0x25F22C: mov [0x0041843C], al
	X86_MEM_WRITE_u8(base, 0x41843Cu, X86_REG8L(ctx.eax));
	// 0x25F231: mov [0x0041843D], al
	X86_MEM_WRITE_u8(base, 0x41843Du, X86_REG8L(ctx.eax));
	// 0x25F236: mov [0x0041843E], al
	X86_MEM_WRITE_u8(base, 0x41843Eu, X86_REG8L(ctx.eax));
	// 0x25F23B: mov byte ptr [0x0041843F], 0x80
	X86_MEM_WRITE_u8(base, 0x41843Fu, -128);
	// 0x25F242: mov [0x00418440], al
	X86_MEM_WRITE_u8(base, 0x418440u, X86_REG8L(ctx.eax));
	// 0x25F247: mov [0x00418441], al
	X86_MEM_WRITE_u8(base, 0x418441u, X86_REG8L(ctx.eax));
	// 0x25F24C: mov [0x00418442], al
	X86_MEM_WRITE_u8(base, 0x418442u, X86_REG8L(ctx.eax));
	// 0x25F251: mov [0x00418443], cl
	X86_MEM_WRITE_u8(base, 0x418443u, X86_REG8L(ctx.ecx));
	// 0x25F257: mov [0x00418444], cl
	X86_MEM_WRITE_u8(base, 0x418444u, X86_REG8L(ctx.ecx));
	// 0x25F25D: movss [0x00418468], xmm4
	X86_MEM_WRITE_u32(base, 0x418468u, ctx.xmm[4].u32[0]);
	// 0x25F265: movss [0x0041846C], xmm3
	X86_MEM_WRITE_u32(base, 0x41846Cu, ctx.xmm[3].u32[0]);
	// 0x25F26D: movss [0x00418470], xmm1
	X86_MEM_WRITE_u32(base, 0x418470u, ctx.xmm[1].u32[0]);
	// 0x25F275: movss [0x00418474], xmm7
	X86_MEM_WRITE_u32(base, 0x418474u, ctx.xmm[7].u32[0]);
	// 0x25F27D: movss [0x00418478], xmm0
	X86_MEM_WRITE_u32(base, 0x418478u, ctx.xmm[0].u32[0]);
	// 0x25F285: mov [0x0041847C], cl
	X86_MEM_WRITE_u8(base, 0x41847Cu, X86_REG8L(ctx.ecx));
	// 0x25F28B: mov [0x0041847D], dl
	X86_MEM_WRITE_u8(base, 0x41847Du, X86_REG8L(ctx.edx));
	// 0x25F291: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25F299: movss [0x0041848C], xmm7
	X86_MEM_WRITE_u32(base, 0x41848Cu, ctx.xmm[7].u32[0]);
	// 0x25F2A1: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x25F2A9: movss [0x00418490], xmm7
	X86_MEM_WRITE_u32(base, 0x418490u, ctx.xmm[7].u32[0]);
	// 0x25F2B1: movss xmm7, dword ptr [0x003A7F34]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7F34u);
	// 0x25F2B9: movss [0x00418494], xmm7
	X86_MEM_WRITE_u32(base, 0x418494u, ctx.xmm[7].u32[0]);
	// 0x25F2C1: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x25F2C9: movss [0x00418498], xmm7
	X86_MEM_WRITE_u32(base, 0x418498u, ctx.xmm[7].u32[0]);
	// 0x25F2D1: movss [0x0041849C], xmm7
	X86_MEM_WRITE_u32(base, 0x41849Cu, ctx.xmm[7].u32[0]);
	// 0x25F2D9: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x25F2E1: movss [0x004184B0], xmm7
	X86_MEM_WRITE_u32(base, 0x4184B0u, ctx.xmm[7].u32[0]);
	// 0x25F2E9: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x25F2F1: movss [0x004184B4], xmm7
	X86_MEM_WRITE_u32(base, 0x4184B4u, ctx.xmm[7].u32[0]);
	// 0x25F2F9: movss xmm7, dword ptr [0x003883C4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3883C4u);
	// 0x25F301: movss [0x004184C8], xmm7
	X86_MEM_WRITE_u32(base, 0x4184C8u, ctx.xmm[7].u32[0]);
	// 0x25F309: movss [0x004184CC], xmm7
	X86_MEM_WRITE_u32(base, 0x4184CCu, ctx.xmm[7].u32[0]);
	// 0x25F311: movss [0x004184D0], xmm7
	X86_MEM_WRITE_u32(base, 0x4184D0u, ctx.xmm[7].u32[0]);
	// 0x25F319: movss xmm7, dword ptr [0x003B17E4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x25F321: movss [0x004184D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4184D8u, ctx.xmm[7].u32[0]);
	// 0x25F329: movss xmm7, dword ptr [0x00387464]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x387464u);
	// 0x25F331: movss [0x004184E4], xmm7
	X86_MEM_WRITE_u32(base, 0x4184E4u, ctx.xmm[7].u32[0]);
	// 0x25F339: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x25F341: movss [0x004184F4], xmm7
	X86_MEM_WRITE_u32(base, 0x4184F4u, ctx.xmm[7].u32[0]);
	// 0x25F349: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25F351: movss [0x0041850C], xmm7
	X86_MEM_WRITE_u32(base, 0x41850Cu, ctx.xmm[7].u32[0]);
	// 0x25F359: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25F361: movss [0x00418510], xmm7
	X86_MEM_WRITE_u32(base, 0x418510u, ctx.xmm[7].u32[0]);
	// 0x25F369: movss xmm7, dword ptr [0x003A7F34]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7F34u);
	// 0x25F371: movss [0x00418514], xmm7
	X86_MEM_WRITE_u32(base, 0x418514u, ctx.xmm[7].u32[0]);
	// 0x25F379: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x25F381: mov [0x00418488], edi
	X86_MEM_WRITE_u32(base, 0x418488u, ctx.edi);
	// 0x25F387: mov edi, 0x3AAF64
	ctx.edi = 3845988;
	// 0x25F38C: movss [0x00418530], xmm7
	X86_MEM_WRITE_u32(base, 0x418530u, ctx.xmm[7].u32[0]);
	// 0x25F394: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x25F39C: mov [0x00418480], ebp
	X86_MEM_WRITE_u32(base, 0x418480u, ctx.ebp);
	// 0x25F3A2: mov [0x00418484], ecx
	X86_MEM_WRITE_u32(base, 0x418484u, ctx.ecx);
	// 0x25F3A8: mov [0x004184A0], edi
	X86_MEM_WRITE_u32(base, 0x4184A0u, ctx.edi);
	// 0x25F3AE: mov [0x004184A4], dl
	X86_MEM_WRITE_u8(base, 0x4184A4u, X86_REG8L(ctx.edx));
	// 0x25F3B4: mov [0x004184A8], esi
	X86_MEM_WRITE_u32(base, 0x4184A8u, ctx.esi);
	// 0x25F3BA: mov [0x004184AC], ecx
	X86_MEM_WRITE_u32(base, 0x4184ACu, ctx.ecx);
	// 0x25F3C0: mov [0x004184B8], al
	X86_MEM_WRITE_u8(base, 0x4184B8u, X86_REG8L(ctx.eax));
	// 0x25F3C5: mov [0x004184B9], al
	X86_MEM_WRITE_u8(base, 0x4184B9u, X86_REG8L(ctx.eax));
	// 0x25F3CA: mov [0x004184BA], al
	X86_MEM_WRITE_u8(base, 0x4184BAu, X86_REG8L(ctx.eax));
	// 0x25F3CF: mov [0x004184BB], bl
	X86_MEM_WRITE_u8(base, 0x4184BBu, X86_REG8L(ctx.ebx));
	// 0x25F3D5: mov [0x004184BC], al
	X86_MEM_WRITE_u8(base, 0x4184BCu, X86_REG8L(ctx.eax));
	// 0x25F3DA: mov [0x004184BD], al
	X86_MEM_WRITE_u8(base, 0x4184BDu, X86_REG8L(ctx.eax));
	// 0x25F3DF: mov [0x004184BE], al
	X86_MEM_WRITE_u8(base, 0x4184BEu, X86_REG8L(ctx.eax));
	// 0x25F3E4: mov [0x004184BF], bl
	X86_MEM_WRITE_u8(base, 0x4184BFu, X86_REG8L(ctx.ebx));
	// 0x25F3EA: mov [0x004184C0], al
	X86_MEM_WRITE_u8(base, 0x4184C0u, X86_REG8L(ctx.eax));
	// 0x25F3EF: mov [0x004184C1], al
	X86_MEM_WRITE_u8(base, 0x4184C1u, X86_REG8L(ctx.eax));
	// 0x25F3F4: mov [0x004184C2], al
	X86_MEM_WRITE_u8(base, 0x4184C2u, X86_REG8L(ctx.eax));
	// 0x25F3F9: mov [0x004184C3], cl
	X86_MEM_WRITE_u8(base, 0x4184C3u, X86_REG8L(ctx.ecx));
	// 0x25F3FF: mov [0x004184C4], cl
	X86_MEM_WRITE_u8(base, 0x4184C4u, X86_REG8L(ctx.ecx));
	// 0x25F405: movss [0x004184D4], xmm3
	X86_MEM_WRITE_u32(base, 0x4184D4u, ctx.xmm[3].u32[0]);
	// 0x25F40D: movss [0x004184DC], xmm2
	X86_MEM_WRITE_u32(base, 0x4184DCu, ctx.xmm[2].u32[0]);
	// 0x25F415: movss [0x004184E0], xmm5
	X86_MEM_WRITE_u32(base, 0x4184E0u, ctx.xmm[5].u32[0]);
	// 0x25F41D: movss [0x004184E8], xmm4
	X86_MEM_WRITE_u32(base, 0x4184E8u, ctx.xmm[4].u32[0]);
	// 0x25F425: movss [0x004184EC], xmm3
	X86_MEM_WRITE_u32(base, 0x4184ECu, ctx.xmm[3].u32[0]);
	// 0x25F42D: movss [0x004184F0], xmm2
	X86_MEM_WRITE_u32(base, 0x4184F0u, ctx.xmm[2].u32[0]);
	// 0x25F435: movss [0x004184F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4184F8u, ctx.xmm[0].u32[0]);
	// 0x25F43D: mov [0x004184FC], dl
	X86_MEM_WRITE_u8(base, 0x4184FCu, X86_REG8L(ctx.edx));
	// 0x25F443: mov [0x004184FD], dl
	X86_MEM_WRITE_u8(base, 0x4184FDu, X86_REG8L(ctx.edx));
	// 0x25F449: mov dword ptr [0x00418500], 0xB4
	X86_MEM_WRITE_u32(base, 0x418500u, 180);
	// 0x25F453: mov dword ptr [0x00418504], 0x21C
	X86_MEM_WRITE_u32(base, 0x418504u, 540);
	// 0x25F45D: mov [0x00418508], eax
	X86_MEM_WRITE_u32(base, 0x418508u, ctx.eax);
	// 0x25F462: movss [0x00418518], xmm0
	X86_MEM_WRITE_u32(base, 0x418518u, ctx.xmm[0].u32[0]);
	// 0x25F46A: movss [0x0041851C], xmm0
	X86_MEM_WRITE_u32(base, 0x41851Cu, ctx.xmm[0].u32[0]);
	// 0x25F472: mov [0x00418520], edi
	X86_MEM_WRITE_u32(base, 0x418520u, ctx.edi);
	// 0x25F478: mov [0x00418524], dl
	X86_MEM_WRITE_u8(base, 0x418524u, X86_REG8L(ctx.edx));
	// 0x25F47E: mov [0x00418528], esi
	X86_MEM_WRITE_u32(base, 0x418528u, ctx.esi);
	// 0x25F484: mov [0x0041852C], ecx
	X86_MEM_WRITE_u32(base, 0x41852Cu, ctx.ecx);
	// 0x25F48A: movss [0x00418534], xmm7
	X86_MEM_WRITE_u32(base, 0x418534u, ctx.xmm[7].u32[0]);
	// 0x25F492: mov [0x00418538], al
	X86_MEM_WRITE_u8(base, 0x418538u, X86_REG8L(ctx.eax));
	// 0x25F497: mov byte ptr [0x00418539], 0x64
	X86_MEM_WRITE_u8(base, 0x418539u, 100);
	// 0x25F49E: mov byte ptr [0x0041853A], 0x19
	X86_MEM_WRITE_u8(base, 0x41853Au, 25);
	// 0x25F4A5: mov byte ptr [0x0041853B], 0x96
	X86_MEM_WRITE_u8(base, 0x41853Bu, -106);
	// 0x25F4AC: mov [0x0041853C], al
	X86_MEM_WRITE_u8(base, 0x41853Cu, X86_REG8L(ctx.eax));
	// 0x25F4B1: mov byte ptr [0x0041853D], 0x64
	X86_MEM_WRITE_u8(base, 0x41853Du, 100);
	// 0x25F4B8: mov byte ptr [0x0041853E], 0x19
	X86_MEM_WRITE_u8(base, 0x41853Eu, 25);
	// 0x25F4BF: mov byte ptr [0x0041853F], 0x96
	X86_MEM_WRITE_u8(base, 0x41853Fu, -106);
	// 0x25F4C6: mov [0x00418540], al
	X86_MEM_WRITE_u8(base, 0x418540u, X86_REG8L(ctx.eax));
	// 0x25F4CB: movss xmm7, dword ptr [0x003B2150]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2150u);
	// 0x25F4D3: movss [0x00418548], xmm7
	X86_MEM_WRITE_u32(base, 0x418548u, ctx.xmm[7].u32[0]);
	// 0x25F4DB: movss [0x0041854C], xmm7
	X86_MEM_WRITE_u32(base, 0x41854Cu, ctx.xmm[7].u32[0]);
	// 0x25F4E3: movss [0x00418550], xmm7
	X86_MEM_WRITE_u32(base, 0x418550u, ctx.xmm[7].u32[0]);
	// 0x25F4EB: movss xmm7, dword ptr [0x003B17E4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x25F4F3: movss [0x00418558], xmm7
	X86_MEM_WRITE_u32(base, 0x418558u, ctx.xmm[7].u32[0]);
	// 0x25F4FB: movss xmm7, dword ptr [0x00387464]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x387464u);
	// 0x25F503: movss [0x00418564], xmm7
	X86_MEM_WRITE_u32(base, 0x418564u, ctx.xmm[7].u32[0]);
	// 0x25F50B: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x25F513: movss [0x00418574], xmm7
	X86_MEM_WRITE_u32(base, 0x418574u, ctx.xmm[7].u32[0]);
	// 0x25F51B: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25F523: movss [0x0041858C], xmm7
	X86_MEM_WRITE_u32(base, 0x41858Cu, ctx.xmm[7].u32[0]);
	// 0x25F52B: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25F533: movss [0x00418590], xmm7
	X86_MEM_WRITE_u32(base, 0x418590u, ctx.xmm[7].u32[0]);
	// 0x25F53B: movss xmm7, dword ptr [0x003B1698]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x25F543: movss [0x004185D0], xmm7
	X86_MEM_WRITE_u32(base, 0x4185D0u, ctx.xmm[7].u32[0]);
	// 0x25F54B: movss xmm7, dword ptr [0x003B16E8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x25F553: movss [0x004185D4], xmm7
	X86_MEM_WRITE_u32(base, 0x4185D4u, ctx.xmm[7].u32[0]);
	// 0x25F55B: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25F563: movss [0x004185D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4185D8u, ctx.xmm[7].u32[0]);
	// 0x25F56B: movss xmm7, dword ptr [0x003B16E8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x25F573: movss [0x004185DC], xmm7
	X86_MEM_WRITE_u32(base, 0x4185DCu, ctx.xmm[7].u32[0]);
	// 0x25F57B: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25F583: movss [0x004185E0], xmm7
	X86_MEM_WRITE_u32(base, 0x4185E0u, ctx.xmm[7].u32[0]);
	// 0x25F58B: movss xmm7, dword ptr [0x003B16E8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x25F593: movss [0x004185E4], xmm7
	X86_MEM_WRITE_u32(base, 0x4185E4u, ctx.xmm[7].u32[0]);
	// 0x25F59B: movss xmm7, dword ptr [0x003B1768]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x25F5A3: movss [0x00418560], xmm5
	X86_MEM_WRITE_u32(base, 0x418560u, ctx.xmm[5].u32[0]);
	// 0x25F5AB: movss [0x00418594], xmm5
	X86_MEM_WRITE_u32(base, 0x418594u, ctx.xmm[5].u32[0]);
	// 0x25F5B3: movss xmm5, dword ptr [0x003B1690]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x25F5BB: mov edi, 0x3AAF6C
	ctx.edi = 3845996;
	// 0x25F5C0: mov esi, 0x02
	ctx.esi = 2;
	// 0x25F5C5: movss [0x004185F4], xmm7
	X86_MEM_WRITE_u32(base, 0x4185F4u, ctx.xmm[7].u32[0]);
	// 0x25F5CD: movss xmm7, dword ptr [0x003A7F34]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7F34u);
	// 0x25F5D5: mov ebp, 0x78
	ctx.ebp = 120;
	// 0x25F5DA: mov byte ptr [0x00418541], 0x64
	X86_MEM_WRITE_u8(base, 0x418541u, 100);
	// 0x25F5E1: mov byte ptr [0x00418542], 0x19
	X86_MEM_WRITE_u8(base, 0x418542u, 25);
	// 0x25F5E8: mov [0x00418543], cl
	X86_MEM_WRITE_u8(base, 0x418543u, X86_REG8L(ctx.ecx));
	// 0x25F5EE: mov [0x00418544], cl
	X86_MEM_WRITE_u8(base, 0x418544u, X86_REG8L(ctx.ecx));
	// 0x25F5F4: movss [0x00418554], xmm3
	X86_MEM_WRITE_u32(base, 0x418554u, ctx.xmm[3].u32[0]);
	// 0x25F5FC: movss [0x0041855C], xmm2
	X86_MEM_WRITE_u32(base, 0x41855Cu, ctx.xmm[2].u32[0]);
	// 0x25F604: movss [0x00418568], xmm4
	X86_MEM_WRITE_u32(base, 0x418568u, ctx.xmm[4].u32[0]);
	// 0x25F60C: movss [0x0041856C], xmm3
	X86_MEM_WRITE_u32(base, 0x41856Cu, ctx.xmm[3].u32[0]);
	// 0x25F614: movss [0x00418570], xmm2
	X86_MEM_WRITE_u32(base, 0x418570u, ctx.xmm[2].u32[0]);
	// 0x25F61C: movss [0x00418578], xmm0
	X86_MEM_WRITE_u32(base, 0x418578u, ctx.xmm[0].u32[0]);
	// 0x25F624: mov [0x0041857C], dl
	X86_MEM_WRITE_u8(base, 0x41857Cu, X86_REG8L(ctx.edx));
	// 0x25F62A: mov [0x0041857D], dl
	X86_MEM_WRITE_u8(base, 0x41857Du, X86_REG8L(ctx.edx));
	// 0x25F630: mov dword ptr [0x00418580], 0x50
	X86_MEM_WRITE_u32(base, 0x418580u, 80);
	// 0x25F63A: mov dword ptr [0x00418584], 0xA0
	X86_MEM_WRITE_u32(base, 0x418584u, 160);
	// 0x25F644: mov [0x00418588], eax
	X86_MEM_WRITE_u32(base, 0x418588u, ctx.eax);
	// 0x25F649: movss [0x00418598], xmm0
	X86_MEM_WRITE_u32(base, 0x418598u, ctx.xmm[0].u32[0]);
	// 0x25F651: movss [0x0041859C], xmm0
	X86_MEM_WRITE_u32(base, 0x41859Cu, ctx.xmm[0].u32[0]);
	// 0x25F659: mov [0x004185A0], edi
	X86_MEM_WRITE_u32(base, 0x4185A0u, ctx.edi);
	// 0x25F65F: mov [0x004185A4], dl
	X86_MEM_WRITE_u8(base, 0x4185A4u, X86_REG8L(ctx.edx));
	// 0x25F665: mov [0x004185A8], esi
	X86_MEM_WRITE_u32(base, 0x4185A8u, ctx.esi);
	// 0x25F66B: mov [0x004185AC], ecx
	X86_MEM_WRITE_u32(base, 0x4185ACu, ctx.ecx);
	// 0x25F671: movss [0x004185B0], xmm5
	X86_MEM_WRITE_u32(base, 0x4185B0u, ctx.xmm[5].u32[0]);
	// 0x25F679: movss [0x004185B4], xmm3
	X86_MEM_WRITE_u32(base, 0x4185B4u, ctx.xmm[3].u32[0]);
	// 0x25F681: mov byte ptr [0x004185B8], 0xE0
	X86_MEM_WRITE_u8(base, 0x4185B8u, -32);
	// 0x25F688: mov byte ptr [0x004185B9], 0xE0
	X86_MEM_WRITE_u8(base, 0x4185B9u, -32);
	// 0x25F68F: mov byte ptr [0x004185BA], 0xE0
	X86_MEM_WRITE_u8(base, 0x4185BAu, -32);
	// 0x25F696: mov [0x004185BB], cl
	X86_MEM_WRITE_u8(base, 0x4185BBu, X86_REG8L(ctx.ecx));
	// 0x25F69C: mov byte ptr [0x004185BC], 0xE4
	X86_MEM_WRITE_u8(base, 0x4185BCu, -28);
	// 0x25F6A3: mov byte ptr [0x004185BD], 0xE4
	X86_MEM_WRITE_u8(base, 0x4185BDu, -28);
	// 0x25F6AA: mov byte ptr [0x004185BE], 0xE4
	X86_MEM_WRITE_u8(base, 0x4185BEu, -28);
	// 0x25F6B1: mov byte ptr [0x004185BF], 0x70
	X86_MEM_WRITE_u8(base, 0x4185BFu, 112);
	// 0x25F6B8: mov [0x004185C0], al
	X86_MEM_WRITE_u8(base, 0x4185C0u, X86_REG8L(ctx.eax));
	// 0x25F6BD: mov [0x004185C1], al
	X86_MEM_WRITE_u8(base, 0x4185C1u, X86_REG8L(ctx.eax));
	// 0x25F6C2: mov [0x004185C2], al
	X86_MEM_WRITE_u8(base, 0x4185C2u, X86_REG8L(ctx.eax));
	// 0x25F6C7: mov [0x004185C3], cl
	X86_MEM_WRITE_u8(base, 0x4185C3u, X86_REG8L(ctx.ecx));
	// 0x25F6CD: mov [0x004185C4], cl
	X86_MEM_WRITE_u8(base, 0x4185C4u, X86_REG8L(ctx.ecx));
	// 0x25F6D3: movss [0x004185C8], xmm6
	X86_MEM_WRITE_u32(base, 0x4185C8u, ctx.xmm[6].u32[0]);
	// 0x25F6DB: movss [0x004185CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4185CCu, ctx.xmm[0].u32[0]);
	// 0x25F6E3: movss [0x004185E8], xmm1
	X86_MEM_WRITE_u32(base, 0x4185E8u, ctx.xmm[1].u32[0]);
	// 0x25F6EB: movss [0x004185EC], xmm3
	X86_MEM_WRITE_u32(base, 0x4185ECu, ctx.xmm[3].u32[0]);
	// 0x25F6F3: movss [0x004185F0], xmm1
	X86_MEM_WRITE_u32(base, 0x4185F0u, ctx.xmm[1].u32[0]);
	// 0x25F6FB: movss [0x004185F8], xmm7
	X86_MEM_WRITE_u32(base, 0x4185F8u, ctx.xmm[7].u32[0]);
	// 0x25F703: mov [0x004185FC], cl
	X86_MEM_WRITE_u8(base, 0x4185FCu, X86_REG8L(ctx.ecx));
	// 0x25F709: mov [0x004185FD], dl
	X86_MEM_WRITE_u8(base, 0x4185FDu, X86_REG8L(ctx.edx));
	// 0x25F70F: mov [0x00418600], ebp
	X86_MEM_WRITE_u32(base, 0x418600u, ctx.ebp);
	// 0x25F715: mov dword ptr [0x00418604], 0x96
	X86_MEM_WRITE_u32(base, 0x418604u, 150);
	// 0x25F71F: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25F727: movss [0x0041860C], xmm7
	X86_MEM_WRITE_u32(base, 0x41860Cu, ctx.xmm[7].u32[0]);
	// 0x25F72F: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x25F737: movss [0x00418610], xmm7
	X86_MEM_WRITE_u32(base, 0x418610u, ctx.xmm[7].u32[0]);
	// 0x25F73F: movss xmm7, dword ptr [0x0039C16C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39C16Cu);
	// 0x25F747: movss [0x00418634], xmm7
	X86_MEM_WRITE_u32(base, 0x418634u, ctx.xmm[7].u32[0]);
	// 0x25F74F: movss xmm7, dword ptr [0x003B16E8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x25F757: movss [0x00418648], xmm7
	X86_MEM_WRITE_u32(base, 0x418648u, ctx.xmm[7].u32[0]);
	// 0x25F75F: movss [0x0041864C], xmm7
	X86_MEM_WRITE_u32(base, 0x41864Cu, ctx.xmm[7].u32[0]);
	// 0x25F767: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25F76F: movss [0x00418658], xmm7
	X86_MEM_WRITE_u32(base, 0x418658u, ctx.xmm[7].u32[0]);
	// 0x25F777: movss xmm7, dword ptr [0x003A7950]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7950u);
	// 0x25F77F: movss [0x00418660], xmm7
	X86_MEM_WRITE_u32(base, 0x418660u, ctx.xmm[7].u32[0]);
	// 0x25F787: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25F78F: movss [0x00418670], xmm7
	X86_MEM_WRITE_u32(base, 0x418670u, ctx.xmm[7].u32[0]);
	// 0x25F797: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x25F79F: movss [0x00418674], xmm7
	X86_MEM_WRITE_u32(base, 0x418674u, ctx.xmm[7].u32[0]);
	// 0x25F7A7: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x25F7AF: movss [0x00418678], xmm7
	X86_MEM_WRITE_u32(base, 0x418678u, ctx.xmm[7].u32[0]);
	// 0x25F7B7: movss xmm7, dword ptr [0x00395BE4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x25F7BF: movss [0x0041868C], xmm7
	X86_MEM_WRITE_u32(base, 0x41868Cu, ctx.xmm[7].u32[0]);
	// 0x25F7C7: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x25F7CF: movss [0x0041869C], xmm7
	X86_MEM_WRITE_u32(base, 0x41869Cu, ctx.xmm[7].u32[0]);
	// 0x25F7D7: movss xmm7, dword ptr [0x003B1698]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x25F7DF: movss [0x004186B0], xmm7
	X86_MEM_WRITE_u32(base, 0x4186B0u, ctx.xmm[7].u32[0]);
	// 0x25F7E7: movss xmm7, dword ptr [0x003B1A08]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1A08u);
	// 0x25F7EF: movss [0x004186B4], xmm7
	X86_MEM_WRITE_u32(base, 0x4186B4u, ctx.xmm[7].u32[0]);
	// 0x25F7F7: movss xmm7, dword ptr [0x0039B2B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x25F7FF: mov [0x00418608], eax
	X86_MEM_WRITE_u32(base, 0x418608u, ctx.eax);
	// 0x25F804: movss [0x00418614], xmm1
	X86_MEM_WRITE_u32(base, 0x418614u, ctx.xmm[1].u32[0]);
	// 0x25F80C: movss [0x00418618], xmm6
	X86_MEM_WRITE_u32(base, 0x418618u, ctx.xmm[6].u32[0]);
	// 0x25F814: movss [0x0041861C], xmm6
	X86_MEM_WRITE_u32(base, 0x41861Cu, ctx.xmm[6].u32[0]);
	// 0x25F81C: mov [0x00418620], edi
	X86_MEM_WRITE_u32(base, 0x418620u, ctx.edi);
	// 0x25F822: mov [0x00418624], dl
	X86_MEM_WRITE_u8(base, 0x418624u, X86_REG8L(ctx.edx));
	// 0x25F828: mov [0x00418628], esi
	X86_MEM_WRITE_u32(base, 0x418628u, ctx.esi);
	// 0x25F82E: mov [0x0041862C], ecx
	X86_MEM_WRITE_u32(base, 0x41862Cu, ctx.ecx);
	// 0x25F834: movss [0x00418630], xmm1
	X86_MEM_WRITE_u32(base, 0x418630u, ctx.xmm[1].u32[0]);
	// 0x25F83C: mov [0x00418638], al
	X86_MEM_WRITE_u8(base, 0x418638u, X86_REG8L(ctx.eax));
	// 0x25F841: mov [0x00418639], al
	X86_MEM_WRITE_u8(base, 0x418639u, X86_REG8L(ctx.eax));
	// 0x25F846: mov [0x0041863A], al
	X86_MEM_WRITE_u8(base, 0x41863Au, X86_REG8L(ctx.eax));
	// 0x25F84B: mov [0x0041863B], cl
	X86_MEM_WRITE_u8(base, 0x41863Bu, X86_REG8L(ctx.ecx));
	// 0x25F851: mov [0x0041863C], al
	X86_MEM_WRITE_u8(base, 0x41863Cu, X86_REG8L(ctx.eax));
	// 0x25F856: mov [0x0041863D], al
	X86_MEM_WRITE_u8(base, 0x41863Du, X86_REG8L(ctx.eax));
	// 0x25F85B: mov [0x0041863E], al
	X86_MEM_WRITE_u8(base, 0x41863Eu, X86_REG8L(ctx.eax));
	// 0x25F860: mov byte ptr [0x0041863F], 0xE0
	X86_MEM_WRITE_u8(base, 0x41863Fu, -32);
	// 0x25F867: mov [0x00418640], al
	X86_MEM_WRITE_u8(base, 0x418640u, X86_REG8L(ctx.eax));
	// 0x25F86C: mov [0x00418641], al
	X86_MEM_WRITE_u8(base, 0x418641u, X86_REG8L(ctx.eax));
	// 0x25F871: mov [0x00418642], al
	X86_MEM_WRITE_u8(base, 0x418642u, X86_REG8L(ctx.eax));
	// 0x25F876: mov [0x00418643], cl
	X86_MEM_WRITE_u8(base, 0x418643u, X86_REG8L(ctx.ecx));
	// 0x25F87C: mov [0x00418644], cl
	X86_MEM_WRITE_u8(base, 0x418644u, X86_REG8L(ctx.ecx));
	// 0x25F882: movss [0x00418650], xmm0
	X86_MEM_WRITE_u32(base, 0x418650u, ctx.xmm[0].u32[0]);
	// 0x25F88A: movss [0x00418654], xmm2
	X86_MEM_WRITE_u32(base, 0x418654u, ctx.xmm[2].u32[0]);
	// 0x25F892: movss [0x0041865C], xmm2
	X86_MEM_WRITE_u32(base, 0x41865Cu, ctx.xmm[2].u32[0]);
	// 0x25F89A: movss [0x00418664], xmm3
	X86_MEM_WRITE_u32(base, 0x418664u, ctx.xmm[3].u32[0]);
	// 0x25F8A2: movss [0x00418668], xmm1
	X86_MEM_WRITE_u32(base, 0x418668u, ctx.xmm[1].u32[0]);
	// 0x25F8AA: movss [0x0041866C], xmm4
	X86_MEM_WRITE_u32(base, 0x41866Cu, ctx.xmm[4].u32[0]);
	// 0x25F8B2: mov [0x0041867C], dl
	X86_MEM_WRITE_u8(base, 0x41867Cu, X86_REG8L(ctx.edx));
	// 0x25F8B8: mov [0x0041867D], dl
	X86_MEM_WRITE_u8(base, 0x41867Du, X86_REG8L(ctx.edx));
	// 0x25F8BE: mov dword ptr [0x00418680], 0xC8
	X86_MEM_WRITE_u32(base, 0x418680u, 200);
	// 0x25F8C8: mov [0x00418684], ecx
	X86_MEM_WRITE_u32(base, 0x418684u, ctx.ecx);
	// 0x25F8CE: mov [0x00418688], eax
	X86_MEM_WRITE_u32(base, 0x418688u, ctx.eax);
	// 0x25F8D3: movss [0x00418690], xmm5
	X86_MEM_WRITE_u32(base, 0x418690u, ctx.xmm[5].u32[0]);
	// 0x25F8DB: movss [0x00418694], xmm1
	X86_MEM_WRITE_u32(base, 0x418694u, ctx.xmm[1].u32[0]);
	// 0x25F8E3: movss [0x00418698], xmm6
	X86_MEM_WRITE_u32(base, 0x418698u, ctx.xmm[6].u32[0]);
	// 0x25F8EB: mov [0x004186A0], edi
	X86_MEM_WRITE_u32(base, 0x4186A0u, ctx.edi);
	// 0x25F8F1: mov [0x004186A4], dl
	X86_MEM_WRITE_u8(base, 0x4186A4u, X86_REG8L(ctx.edx));
	// 0x25F8F7: mov [0x004186A8], esi
	X86_MEM_WRITE_u32(base, 0x4186A8u, ctx.esi);
	// 0x25F8FD: mov [0x004186AC], ecx
	X86_MEM_WRITE_u32(base, 0x4186ACu, ctx.ecx);
	// 0x25F903: mov [0x004186B8], bl
	X86_MEM_WRITE_u8(base, 0x4186B8u, X86_REG8L(ctx.ebx));
	// 0x25F909: mov [0x004186B9], bl
	X86_MEM_WRITE_u8(base, 0x4186B9u, X86_REG8L(ctx.ebx));
	// 0x25F90F: mov [0x004186BA], bl
	X86_MEM_WRITE_u8(base, 0x4186BAu, X86_REG8L(ctx.ebx));
	// 0x25F915: mov [0x004186BB], cl
	X86_MEM_WRITE_u8(base, 0x4186BBu, X86_REG8L(ctx.ecx));
	// 0x25F91B: mov [0x004186BC], bl
	X86_MEM_WRITE_u8(base, 0x4186BCu, X86_REG8L(ctx.ebx));
	// 0x25F921: mov [0x004186BD], bl
	X86_MEM_WRITE_u8(base, 0x4186BDu, X86_REG8L(ctx.ebx));
	// 0x25F927: mov [0x004186BE], bl
	X86_MEM_WRITE_u8(base, 0x4186BEu, X86_REG8L(ctx.ebx));
	// 0x25F92D: mov byte ptr [0x004186BF], 0xE0
	X86_MEM_WRITE_u8(base, 0x4186BFu, -32);
	// 0x25F934: mov [0x004186C0], al
	X86_MEM_WRITE_u8(base, 0x4186C0u, X86_REG8L(ctx.eax));
	// 0x25F939: mov [0x004186C1], al
	X86_MEM_WRITE_u8(base, 0x4186C1u, X86_REG8L(ctx.eax));
	// 0x25F93E: mov [0x004186C2], al
	X86_MEM_WRITE_u8(base, 0x4186C2u, X86_REG8L(ctx.eax));
	// 0x25F943: mov [0x004186C3], cl
	X86_MEM_WRITE_u8(base, 0x4186C3u, X86_REG8L(ctx.ecx));
	// 0x25F949: mov [0x004186C4], cl
	X86_MEM_WRITE_u8(base, 0x4186C4u, X86_REG8L(ctx.ecx));
	// 0x25F94F: movss [0x004186C8], xmm7
	X86_MEM_WRITE_u32(base, 0x4186C8u, ctx.xmm[7].u32[0]);
	// 0x25F957: movss xmm7, dword ptr [0x003A55F8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x25F95F: movss [0x004186CC], xmm7
	X86_MEM_WRITE_u32(base, 0x4186CCu, ctx.xmm[7].u32[0]);
	// 0x25F967: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x25F96F: movss [0x004186D0], xmm7
	X86_MEM_WRITE_u32(base, 0x4186D0u, ctx.xmm[7].u32[0]);
	// 0x25F977: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25F97F: movss [0x004186D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4186D8u, ctx.xmm[7].u32[0]);
	// 0x25F987: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x25F98F: movss [0x004186DC], xmm7
	X86_MEM_WRITE_u32(base, 0x4186DCu, ctx.xmm[7].u32[0]);
	// 0x25F997: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25F99F: movss [0x004186E0], xmm7
	X86_MEM_WRITE_u32(base, 0x4186E0u, ctx.xmm[7].u32[0]);
	// 0x25F9A7: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25F9AF: movss [0x004186F0], xmm7
	X86_MEM_WRITE_u32(base, 0x4186F0u, ctx.xmm[7].u32[0]);
	// 0x25F9B7: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x25F9BF: movss [0x004186F4], xmm7
	X86_MEM_WRITE_u32(base, 0x4186F4u, ctx.xmm[7].u32[0]);
	// 0x25F9C7: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x25F9CF: movss [0x004186F8], xmm7
	X86_MEM_WRITE_u32(base, 0x4186F8u, ctx.xmm[7].u32[0]);
	// 0x25F9D7: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25F9DF: movss [0x0041870C], xmm7
	X86_MEM_WRITE_u32(base, 0x41870Cu, ctx.xmm[7].u32[0]);
	// 0x25F9E7: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x25F9EF: movss [0x00418730], xmm7
	X86_MEM_WRITE_u32(base, 0x418730u, ctx.xmm[7].u32[0]);
	// 0x25F9F7: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25F9FF: movss [0x00418748], xmm7
	X86_MEM_WRITE_u32(base, 0x418748u, ctx.xmm[7].u32[0]);
	// 0x25FA07: movss xmm7, dword ptr [0x00395E88]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395E88u);
	// 0x25FA0F: movss [0x0041874C], xmm7
	X86_MEM_WRITE_u32(base, 0x41874Cu, ctx.xmm[7].u32[0]);
	// 0x25FA17: movss xmm7, dword ptr [0x003B1730]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x25FA1F: movss [0x00418754], xmm7
	X86_MEM_WRITE_u32(base, 0x418754u, ctx.xmm[7].u32[0]);
	// 0x25FA27: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25FA2F: movss [0x00418758], xmm7
	X86_MEM_WRITE_u32(base, 0x418758u, ctx.xmm[7].u32[0]);
	// 0x25FA37: movss xmm7, dword ptr [0x003B1730]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x25FA3F: movss [0x0041875C], xmm7
	X86_MEM_WRITE_u32(base, 0x41875Cu, ctx.xmm[7].u32[0]);
	// 0x25FA47: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25FA4F: movss [0x00418760], xmm7
	X86_MEM_WRITE_u32(base, 0x418760u, ctx.xmm[7].u32[0]);
	// 0x25FA57: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25FA5F: movss [0x00418770], xmm7
	X86_MEM_WRITE_u32(base, 0x418770u, ctx.xmm[7].u32[0]);
	// 0x25FA67: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x25FA6F: movss [0x00418774], xmm7
	X86_MEM_WRITE_u32(base, 0x418774u, ctx.xmm[7].u32[0]);
	// 0x25FA77: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x25FA7F: movss [0x00418778], xmm7
	X86_MEM_WRITE_u32(base, 0x418778u, ctx.xmm[7].u32[0]);
	// 0x25FA87: movss xmm7, dword ptr [0x00395BE0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395BE0u);
	// 0x25FA8F: movss [0x004186D4], xmm2
	X86_MEM_WRITE_u32(base, 0x4186D4u, ctx.xmm[2].u32[0]);
	// 0x25FA97: movss [0x004186E4], xmm3
	X86_MEM_WRITE_u32(base, 0x4186E4u, ctx.xmm[3].u32[0]);
	// 0x25FA9F: movss [0x004186E8], xmm1
	X86_MEM_WRITE_u32(base, 0x4186E8u, ctx.xmm[1].u32[0]);
	// 0x25FAA7: movss [0x004186EC], xmm4
	X86_MEM_WRITE_u32(base, 0x4186ECu, ctx.xmm[4].u32[0]);
	// 0x25FAAF: mov [0x004186FC], dl
	X86_MEM_WRITE_u8(base, 0x4186FCu, X86_REG8L(ctx.edx));
	// 0x25FAB5: mov [0x004186FD], dl
	X86_MEM_WRITE_u8(base, 0x4186FDu, X86_REG8L(ctx.edx));
	// 0x25FABB: mov dword ptr [0x00418700], 0xF0
	X86_MEM_WRITE_u32(base, 0x418700u, 240);
	// 0x25FAC5: mov dword ptr [0x00418704], 0xF0
	X86_MEM_WRITE_u32(base, 0x418704u, 240);
	// 0x25FACF: mov [0x00418708], eax
	X86_MEM_WRITE_u32(base, 0x418708u, ctx.eax);
	// 0x25FAD4: movss [0x00418710], xmm5
	X86_MEM_WRITE_u32(base, 0x418710u, ctx.xmm[5].u32[0]);
	// 0x25FADC: movss [0x00418714], xmm1
	X86_MEM_WRITE_u32(base, 0x418714u, ctx.xmm[1].u32[0]);
	// 0x25FAE4: movss [0x00418718], xmm6
	X86_MEM_WRITE_u32(base, 0x418718u, ctx.xmm[6].u32[0]);
	// 0x25FAEC: movss [0x0041871C], xmm6
	X86_MEM_WRITE_u32(base, 0x41871Cu, ctx.xmm[6].u32[0]);
	// 0x25FAF4: mov [0x00418720], edi
	X86_MEM_WRITE_u32(base, 0x418720u, ctx.edi);
	// 0x25FAFA: mov [0x00418724], dl
	X86_MEM_WRITE_u8(base, 0x418724u, X86_REG8L(ctx.edx));
	// 0x25FB00: mov [0x00418728], esi
	X86_MEM_WRITE_u32(base, 0x418728u, ctx.esi);
	// 0x25FB06: mov [0x0041872C], ecx
	X86_MEM_WRITE_u32(base, 0x41872Cu, ctx.ecx);
	// 0x25FB0C: movss [0x00418734], xmm2
	X86_MEM_WRITE_u32(base, 0x418734u, ctx.xmm[2].u32[0]);
	// 0x25FB14: mov [0x00418738], al
	X86_MEM_WRITE_u8(base, 0x418738u, X86_REG8L(ctx.eax));
	// 0x25FB19: mov [0x00418739], al
	X86_MEM_WRITE_u8(base, 0x418739u, X86_REG8L(ctx.eax));
	// 0x25FB1E: mov [0x0041873A], al
	X86_MEM_WRITE_u8(base, 0x41873Au, X86_REG8L(ctx.eax));
	// 0x25FB23: mov [0x0041873B], cl
	X86_MEM_WRITE_u8(base, 0x41873Bu, X86_REG8L(ctx.ecx));
	// 0x25FB29: mov [0x0041873C], al
	X86_MEM_WRITE_u8(base, 0x41873Cu, X86_REG8L(ctx.eax));
	// 0x25FB2E: mov [0x0041873D], al
	X86_MEM_WRITE_u8(base, 0x41873Du, X86_REG8L(ctx.eax));
	// 0x25FB33: mov [0x0041873E], al
	X86_MEM_WRITE_u8(base, 0x41873Eu, X86_REG8L(ctx.eax));
	// 0x25FB38: mov byte ptr [0x0041873F], 0xA0
	X86_MEM_WRITE_u8(base, 0x41873Fu, -96);
	// 0x25FB3F: mov [0x00418740], al
	X86_MEM_WRITE_u8(base, 0x418740u, X86_REG8L(ctx.eax));
	// 0x25FB44: mov [0x00418741], al
	X86_MEM_WRITE_u8(base, 0x418741u, X86_REG8L(ctx.eax));
	// 0x25FB49: mov [0x00418742], al
	X86_MEM_WRITE_u8(base, 0x418742u, X86_REG8L(ctx.eax));
	// 0x25FB4E: mov [0x00418743], cl
	X86_MEM_WRITE_u8(base, 0x418743u, X86_REG8L(ctx.ecx));
	// 0x25FB54: mov [0x00418744], cl
	X86_MEM_WRITE_u8(base, 0x418744u, X86_REG8L(ctx.ecx));
	// 0x25FB5A: movss [0x00418750], xmm5
	X86_MEM_WRITE_u32(base, 0x418750u, ctx.xmm[5].u32[0]);
	// 0x25FB62: movss [0x00418764], xmm3
	X86_MEM_WRITE_u32(base, 0x418764u, ctx.xmm[3].u32[0]);
	// 0x25FB6A: movss [0x00418768], xmm1
	X86_MEM_WRITE_u32(base, 0x418768u, ctx.xmm[1].u32[0]);
	// 0x25FB72: movss [0x0041876C], xmm4
	X86_MEM_WRITE_u32(base, 0x41876Cu, ctx.xmm[4].u32[0]);
	// 0x25FB7A: mov [0x0041877C], dl
	X86_MEM_WRITE_u8(base, 0x41877Cu, X86_REG8L(ctx.edx));
	// 0x25FB80: mov [0x0041877D], dl
	X86_MEM_WRITE_u8(base, 0x41877Du, X86_REG8L(ctx.edx));
	// 0x25FB86: mov [0x00418780], ecx
	X86_MEM_WRITE_u32(base, 0x418780u, ctx.ecx);
	// 0x25FB8C: mov dword ptr [0x00418784], 0xF0
	X86_MEM_WRITE_u32(base, 0x418784u, 240);
	// 0x25FB96: mov [0x00418788], eax
	X86_MEM_WRITE_u32(base, 0x418788u, ctx.eax);
	// 0x25FB9B: movss [0x0041878C], xmm7
	X86_MEM_WRITE_u32(base, 0x41878Cu, ctx.xmm[7].u32[0]);
	// 0x25FBA3: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x25FBAB: movss [0x00418798], xmm7
	X86_MEM_WRITE_u32(base, 0x418798u, ctx.xmm[7].u32[0]);
	// 0x25FBB3: movss [0x0041879C], xmm7
	X86_MEM_WRITE_u32(base, 0x41879Cu, ctx.xmm[7].u32[0]);
	// 0x25FBBB: movss xmm7, dword ptr [0x003B1694]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x25FBC3: movss [0x004187B0], xmm7
	X86_MEM_WRITE_u32(base, 0x4187B0u, ctx.xmm[7].u32[0]);
	// 0x25FBCB: movss xmm7, dword ptr [0x0039CC08]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39CC08u);
	// 0x25FBD3: movss [0x004187C8], xmm7
	X86_MEM_WRITE_u32(base, 0x4187C8u, ctx.xmm[7].u32[0]);
	// 0x25FBDB: movss xmm7, dword ptr [0x003B03FC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B03FCu);
	// 0x25FBE3: movss [0x004187D0], xmm7
	X86_MEM_WRITE_u32(base, 0x4187D0u, ctx.xmm[7].u32[0]);
	// 0x25FBEB: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25FBF3: movss [0x004187D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4187D8u, ctx.xmm[7].u32[0]);
	// 0x25FBFB: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x25FC03: movss [0x004187DC], xmm7
	X86_MEM_WRITE_u32(base, 0x4187DCu, ctx.xmm[7].u32[0]);
	// 0x25FC0B: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25FC13: movss [0x004187E0], xmm7
	X86_MEM_WRITE_u32(base, 0x4187E0u, ctx.xmm[7].u32[0]);
	// 0x25FC1B: movss xmm7, dword ptr [0x003A69BC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69BCu);
	// 0x25FC23: movss [0x004187E4], xmm7
	X86_MEM_WRITE_u32(base, 0x4187E4u, ctx.xmm[7].u32[0]);
	// 0x25FC2B: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25FC33: movss [0x004187F0], xmm7
	X86_MEM_WRITE_u32(base, 0x4187F0u, ctx.xmm[7].u32[0]);
	// 0x25FC3B: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25FC43: movss [0x004187F4], xmm7
	X86_MEM_WRITE_u32(base, 0x4187F4u, ctx.xmm[7].u32[0]);
	// 0x25FC4B: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x25FC53: movss [0x004187F8], xmm7
	X86_MEM_WRITE_u32(base, 0x4187F8u, ctx.xmm[7].u32[0]);
	// 0x25FC5B: movss xmm7, dword ptr [0x003B03F4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B03F4u);
	// 0x25FC63: movss [0x0041880C], xmm7
	X86_MEM_WRITE_u32(base, 0x41880Cu, ctx.xmm[7].u32[0]);
	// 0x25FC6B: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x25FC73: movss [0x00418810], xmm7
	X86_MEM_WRITE_u32(base, 0x418810u, ctx.xmm[7].u32[0]);
	// 0x25FC7B: movss [0x00418814], xmm7
	X86_MEM_WRITE_u32(base, 0x418814u, ctx.xmm[7].u32[0]);
	// 0x25FC83: movss xmm7, dword ptr [0x003895BC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x25FC8B: movss [0x00418830], xmm7
	X86_MEM_WRITE_u32(base, 0x418830u, ctx.xmm[7].u32[0]);
	// 0x25FC93: movss xmm7, dword ptr [0x003B1A78]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1A78u);
	// 0x25FC9B: movss [0x00418834], xmm7
	X86_MEM_WRITE_u32(base, 0x418834u, ctx.xmm[7].u32[0]);
	// 0x25FCA3: movss xmm7, dword ptr [0x003A2D54]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2D54u);
	// 0x25FCAB: movss [0x00418790], xmm5
	X86_MEM_WRITE_u32(base, 0x418790u, ctx.xmm[5].u32[0]);
	// 0x25FCB3: movss [0x00418794], xmm1
	X86_MEM_WRITE_u32(base, 0x418794u, ctx.xmm[1].u32[0]);
	// 0x25FCBB: mov [0x004187A0], edi
	X86_MEM_WRITE_u32(base, 0x4187A0u, ctx.edi);
	// 0x25FCC1: mov [0x004187A4], dl
	X86_MEM_WRITE_u8(base, 0x4187A4u, X86_REG8L(ctx.edx));
	// 0x25FCC7: mov [0x004187A8], esi
	X86_MEM_WRITE_u32(base, 0x4187A8u, ctx.esi);
	// 0x25FCCD: mov [0x004187AC], ecx
	X86_MEM_WRITE_u32(base, 0x4187ACu, ctx.ecx);
	// 0x25FCD3: movss [0x004187B4], xmm3
	X86_MEM_WRITE_u32(base, 0x4187B4u, ctx.xmm[3].u32[0]);
	// 0x25FCDB: mov byte ptr [0x004187B8], 0xDC
	X86_MEM_WRITE_u8(base, 0x4187B8u, -36);
	// 0x25FCE2: mov byte ptr [0x004187B9], 0xD7
	X86_MEM_WRITE_u8(base, 0x4187B9u, -41);
	// 0x25FCE9: mov byte ptr [0x004187BA], 0xC8
	X86_MEM_WRITE_u8(base, 0x4187BAu, -56);
	// 0x25FCF0: mov byte ptr [0x004187BB], 0x0A
	X86_MEM_WRITE_u8(base, 0x4187BBu, 10);
	// 0x25FCF7: mov byte ptr [0x004187BC], 0xDC
	X86_MEM_WRITE_u8(base, 0x4187BCu, -36);
	// 0x25FCFE: mov byte ptr [0x004187BD], 0xD7
	X86_MEM_WRITE_u8(base, 0x4187BDu, -41);
	// 0x25FD05: mov byte ptr [0x004187BE], 0xC8
	X86_MEM_WRITE_u8(base, 0x4187BEu, -56);
	// 0x25FD0C: mov byte ptr [0x004187BF], 0xB4
	X86_MEM_WRITE_u8(base, 0x4187BFu, -76);
	// 0x25FD13: mov [0x004187C0], al
	X86_MEM_WRITE_u8(base, 0x4187C0u, X86_REG8L(ctx.eax));
	// 0x25FD18: mov [0x004187C1], al
	X86_MEM_WRITE_u8(base, 0x4187C1u, X86_REG8L(ctx.eax));
	// 0x25FD1D: mov byte ptr [0x004187C2], 0xF0
	X86_MEM_WRITE_u8(base, 0x4187C2u, -16);
	// 0x25FD24: mov [0x004187C3], cl
	X86_MEM_WRITE_u8(base, 0x4187C3u, X86_REG8L(ctx.ecx));
	// 0x25FD2A: mov [0x004187C4], cl
	X86_MEM_WRITE_u8(base, 0x4187C4u, X86_REG8L(ctx.ecx));
	// 0x25FD30: movss [0x004187CC], xmm5
	X86_MEM_WRITE_u32(base, 0x4187CCu, ctx.xmm[5].u32[0]);
	// 0x25FD38: movss [0x004187D4], xmm2
	X86_MEM_WRITE_u32(base, 0x4187D4u, ctx.xmm[2].u32[0]);
	// 0x25FD40: movss [0x004187E8], xmm1
	X86_MEM_WRITE_u32(base, 0x4187E8u, ctx.xmm[1].u32[0]);
	// 0x25FD48: movss [0x004187EC], xmm4
	X86_MEM_WRITE_u32(base, 0x4187ECu, ctx.xmm[4].u32[0]);
	// 0x25FD50: mov [0x004187FC], dl
	X86_MEM_WRITE_u8(base, 0x4187FCu, X86_REG8L(ctx.edx));
	// 0x25FD56: mov [0x004187FD], dl
	X86_MEM_WRITE_u8(base, 0x4187FDu, X86_REG8L(ctx.edx));
	// 0x25FD5C: mov dword ptr [0x00418800], 0xB4
	X86_MEM_WRITE_u32(base, 0x418800u, 180);
	// 0x25FD66: mov dword ptr [0x00418804], 0xDC
	X86_MEM_WRITE_u32(base, 0x418804u, 220);
	// 0x25FD70: mov [0x00418808], eax
	X86_MEM_WRITE_u32(base, 0x418808u, ctx.eax);
	// 0x25FD75: movss [0x00418818], xmm6
	X86_MEM_WRITE_u32(base, 0x418818u, ctx.xmm[6].u32[0]);
	// 0x25FD7D: movss [0x0041881C], xmm6
	X86_MEM_WRITE_u32(base, 0x41881Cu, ctx.xmm[6].u32[0]);
	// 0x25FD85: mov [0x00418820], edi
	X86_MEM_WRITE_u32(base, 0x418820u, ctx.edi);
	// 0x25FD8B: mov [0x00418824], dl
	X86_MEM_WRITE_u8(base, 0x418824u, X86_REG8L(ctx.edx));
	// 0x25FD91: mov [0x00418828], esi
	X86_MEM_WRITE_u32(base, 0x418828u, ctx.esi);
	// 0x25FD97: mov [0x0041882C], ecx
	X86_MEM_WRITE_u32(base, 0x41882Cu, ctx.ecx);
	// 0x25FD9D: mov byte ptr [0x00418838], 0x8C
	X86_MEM_WRITE_u8(base, 0x418838u, -116);
	// 0x25FDA4: mov byte ptr [0x00418839], 0x7D
	X86_MEM_WRITE_u8(base, 0x418839u, 125);
	// 0x25FDAB: mov byte ptr [0x0041883A], 0x4B
	X86_MEM_WRITE_u8(base, 0x41883Au, 75);
	// 0x25FDB2: mov byte ptr [0x0041883B], 0x60
	X86_MEM_WRITE_u8(base, 0x41883Bu, 96);
	// 0x25FDB9: mov byte ptr [0x0041883C], 0x96
	X86_MEM_WRITE_u8(base, 0x41883Cu, -106);
	// 0x25FDC0: mov byte ptr [0x0041883D], 0x8C
	X86_MEM_WRITE_u8(base, 0x41883Du, -116);
	// 0x25FDC7: mov byte ptr [0x0041883E], 0x64
	X86_MEM_WRITE_u8(base, 0x41883Eu, 100);
	// 0x25FDCE: mov [0x0041883F], bl
	X86_MEM_WRITE_u8(base, 0x41883Fu, X86_REG8L(ctx.ebx));
	// 0x25FDD4: mov byte ptr [0x00418840], 0xD2
	X86_MEM_WRITE_u8(base, 0x418840u, -46);
	// 0x25FDDB: mov byte ptr [0x00418841], 0xB4
	X86_MEM_WRITE_u8(base, 0x418841u, -76);
	// 0x25FDE2: mov byte ptr [0x00418842], 0x82
	X86_MEM_WRITE_u8(base, 0x418842u, -126);
	// 0x25FDE9: mov [0x00418843], cl
	X86_MEM_WRITE_u8(base, 0x418843u, X86_REG8L(ctx.ecx));
	// 0x25FDEF: mov [0x00418844], cl
	X86_MEM_WRITE_u8(base, 0x418844u, X86_REG8L(ctx.ecx));
	// 0x25FDF5: movss [0x00418848], xmm7
	X86_MEM_WRITE_u32(base, 0x418848u, ctx.xmm[7].u32[0]);
	// 0x25FDFD: movss xmm7, dword ptr [0x003A2D50]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25FE05: movss [0x0041884C], xmm7
	X86_MEM_WRITE_u32(base, 0x41884Cu, ctx.xmm[7].u32[0]);
	// 0x25FE0D: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25FE15: movss [0x00418858], xmm7
	X86_MEM_WRITE_u32(base, 0x418858u, ctx.xmm[7].u32[0]);
	// 0x25FE1D: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25FE25: movss [0x00418860], xmm7
	X86_MEM_WRITE_u32(base, 0x418860u, ctx.xmm[7].u32[0]);
	// 0x25FE2D: movss xmm7, dword ptr [0x0039B258]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39B258u);
	// 0x25FE35: movss [0x00418864], xmm7
	X86_MEM_WRITE_u32(base, 0x418864u, ctx.xmm[7].u32[0]);
	// 0x25FE3D: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25FE45: movss [0x00418870], xmm7
	X86_MEM_WRITE_u32(base, 0x418870u, ctx.xmm[7].u32[0]);
	// 0x25FE4D: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25FE55: movss [0x00418874], xmm7
	X86_MEM_WRITE_u32(base, 0x418874u, ctx.xmm[7].u32[0]);
	// 0x25FE5D: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x25FE65: movss [0x00418878], xmm7
	X86_MEM_WRITE_u32(base, 0x418878u, ctx.xmm[7].u32[0]);
	// 0x25FE6D: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25FE75: movss [0x0041888C], xmm7
	X86_MEM_WRITE_u32(base, 0x41888Cu, ctx.xmm[7].u32[0]);
	// 0x25FE7D: movss xmm7, dword ptr [0x003A2D50]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x25FE85: movss [0x004188B0], xmm7
	X86_MEM_WRITE_u32(base, 0x4188B0u, ctx.xmm[7].u32[0]);
	// 0x25FE8D: movss xmm7, dword ptr [0x00384148]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x384148u);
	// 0x25FE95: movss [0x004188B4], xmm7
	X86_MEM_WRITE_u32(base, 0x4188B4u, ctx.xmm[7].u32[0]);
	// 0x25FE9D: movss xmm7, dword ptr [0x003A55F8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x25FEA5: movss [0x004188C8], xmm7
	X86_MEM_WRITE_u32(base, 0x4188C8u, ctx.xmm[7].u32[0]);
	// 0x25FEAD: movss xmm7, dword ptr [0x003B1768]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x25FEB5: movss [0x004188CC], xmm7
	X86_MEM_WRITE_u32(base, 0x4188CCu, ctx.xmm[7].u32[0]);
	// 0x25FEBD: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x25FEC5: movss [0x004188D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4188D8u, ctx.xmm[7].u32[0]);
	// 0x25FECD: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x25FED5: movss [0x004188DC], xmm7
	X86_MEM_WRITE_u32(base, 0x4188DCu, ctx.xmm[7].u32[0]);
	// 0x25FEDD: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x25FEE5: movss [0x004188E0], xmm7
	X86_MEM_WRITE_u32(base, 0x4188E0u, ctx.xmm[7].u32[0]);
	// 0x25FEED: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x25FEF5: movss [0x004188F0], xmm7
	X86_MEM_WRITE_u32(base, 0x4188F0u, ctx.xmm[7].u32[0]);
	// 0x25FEFD: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x25FF05: movss [0x004188F4], xmm7
	X86_MEM_WRITE_u32(base, 0x4188F4u, ctx.xmm[7].u32[0]);
	// 0x25FF0D: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x25FF15: movss [0x004188F8], xmm7
	X86_MEM_WRITE_u32(base, 0x4188F8u, ctx.xmm[7].u32[0]);
	// 0x25FF1D: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x25FF25: movss [0x00418850], xmm5
	X86_MEM_WRITE_u32(base, 0x418850u, ctx.xmm[5].u32[0]);
	// 0x25FF2D: movss [0x00418854], xmm3
	X86_MEM_WRITE_u32(base, 0x418854u, ctx.xmm[3].u32[0]);
	// 0x25FF35: movss [0x0041885C], xmm3
	X86_MEM_WRITE_u32(base, 0x41885Cu, ctx.xmm[3].u32[0]);
	// 0x25FF3D: movss [0x00418868], xmm1
	X86_MEM_WRITE_u32(base, 0x418868u, ctx.xmm[1].u32[0]);
	// 0x25FF45: movss [0x0041886C], xmm4
	X86_MEM_WRITE_u32(base, 0x41886Cu, ctx.xmm[4].u32[0]);
	// 0x25FF4D: mov [0x0041887C], dl
	X86_MEM_WRITE_u8(base, 0x41887Cu, X86_REG8L(ctx.edx));
	// 0x25FF53: mov [0x0041887D], dl
	X86_MEM_WRITE_u8(base, 0x41887Du, X86_REG8L(ctx.edx));
	// 0x25FF59: mov dword ptr [0x00418880], 0xF0
	X86_MEM_WRITE_u32(base, 0x418880u, 240);
	// 0x25FF63: mov [0x00418884], ecx
	X86_MEM_WRITE_u32(base, 0x418884u, ctx.ecx);
	// 0x25FF69: mov [0x00418888], eax
	X86_MEM_WRITE_u32(base, 0x418888u, ctx.eax);
	// 0x25FF6E: movss [0x00418890], xmm5
	X86_MEM_WRITE_u32(base, 0x418890u, ctx.xmm[5].u32[0]);
	// 0x25FF76: movss [0x00418894], xmm1
	X86_MEM_WRITE_u32(base, 0x418894u, ctx.xmm[1].u32[0]);
	// 0x25FF7E: movss [0x00418898], xmm6
	X86_MEM_WRITE_u32(base, 0x418898u, ctx.xmm[6].u32[0]);
	// 0x25FF86: movss [0x0041889C], xmm6
	X86_MEM_WRITE_u32(base, 0x41889Cu, ctx.xmm[6].u32[0]);
	// 0x25FF8E: mov [0x004188A0], edi
	X86_MEM_WRITE_u32(base, 0x4188A0u, ctx.edi);
	// 0x25FF94: mov [0x004188A4], dl
	X86_MEM_WRITE_u8(base, 0x4188A4u, X86_REG8L(ctx.edx));
	// 0x25FF9A: mov [0x004188A8], esi
	X86_MEM_WRITE_u32(base, 0x4188A8u, ctx.esi);
	// 0x25FFA0: mov [0x004188AC], ecx
	X86_MEM_WRITE_u32(base, 0x4188ACu, ctx.ecx);
	// 0x25FFA6: mov [0x004188B8], bl
	X86_MEM_WRITE_u8(base, 0x4188B8u, X86_REG8L(ctx.ebx));
	// 0x25FFAC: mov byte ptr [0x004188B9], 0xAA
	X86_MEM_WRITE_u8(base, 0x4188B9u, -86);
	// 0x25FFB3: mov byte ptr [0x004188BA], 0xA0
	X86_MEM_WRITE_u8(base, 0x4188BAu, -96);
	// 0x25FFBA: mov [0x004188BB], cl
	X86_MEM_WRITE_u8(base, 0x4188BBu, X86_REG8L(ctx.ecx));
	// 0x25FFC0: mov [0x004188BC], bl
	X86_MEM_WRITE_u8(base, 0x4188BCu, X86_REG8L(ctx.ebx));
	// 0x25FFC6: mov byte ptr [0x004188BD], 0xA0
	X86_MEM_WRITE_u8(base, 0x4188BDu, -96);
	// 0x25FFCD: mov byte ptr [0x004188BE], 0xA0
	X86_MEM_WRITE_u8(base, 0x4188BEu, -96);
	// 0x25FFD4: mov byte ptr [0x004188BF], 0xE0
	X86_MEM_WRITE_u8(base, 0x4188BFu, -32);
	// 0x25FFDB: mov [0x004188C0], bl
	X86_MEM_WRITE_u8(base, 0x4188C0u, X86_REG8L(ctx.ebx));
	// 0x25FFE1: mov byte ptr [0x004188C1], 0xA0
	X86_MEM_WRITE_u8(base, 0x4188C1u, -96);
	// 0x25FFE8: mov byte ptr [0x004188C2], 0xA0
	X86_MEM_WRITE_u8(base, 0x4188C2u, -96);
	// 0x25FFEF: mov [0x004188C3], cl
	X86_MEM_WRITE_u8(base, 0x4188C3u, X86_REG8L(ctx.ecx));
	// 0x25FFF5: mov [0x004188C4], cl
	X86_MEM_WRITE_u8(base, 0x4188C4u, X86_REG8L(ctx.ecx));
	// 0x25FFFB: movss [0x004188D0], xmm5
	X86_MEM_WRITE_u32(base, 0x4188D0u, ctx.xmm[5].u32[0]);
	// 0x260003: movss [0x004188D4], xmm2
	X86_MEM_WRITE_u32(base, 0x4188D4u, ctx.xmm[2].u32[0]);
	// 0x26000B: movss [0x004188E4], xmm3
	X86_MEM_WRITE_u32(base, 0x4188E4u, ctx.xmm[3].u32[0]);
	// 0x260013: movss [0x004188E8], xmm1
	X86_MEM_WRITE_u32(base, 0x4188E8u, ctx.xmm[1].u32[0]);
	// 0x26001B: movss [0x004188EC], xmm4
	X86_MEM_WRITE_u32(base, 0x4188ECu, ctx.xmm[4].u32[0]);
	// 0x260023: mov [0x004188FC], dl
	X86_MEM_WRITE_u8(base, 0x4188FCu, X86_REG8L(ctx.edx));
	// 0x260029: mov [0x004188FD], dl
	X86_MEM_WRITE_u8(base, 0x4188FDu, X86_REG8L(ctx.edx));
	// 0x26002F: mov dword ptr [0x00418900], 0xF0
	X86_MEM_WRITE_u32(base, 0x418900u, 240);
	// 0x260039: mov [0x00418904], ecx
	X86_MEM_WRITE_u32(base, 0x418904u, ctx.ecx);
	// 0x26003F: mov [0x00418908], eax
	X86_MEM_WRITE_u32(base, 0x418908u, ctx.eax);
	// 0x260044: movss [0x0041890C], xmm7
	X86_MEM_WRITE_u32(base, 0x41890Cu, ctx.xmm[7].u32[0]);
	// 0x26004C: movss [0x00418910], xmm5
	X86_MEM_WRITE_u32(base, 0x418910u, ctx.xmm[5].u32[0]);
	// 0x260054: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x26005C: movss [0x00418914], xmm7
	X86_MEM_WRITE_u32(base, 0x418914u, ctx.xmm[7].u32[0]);
	// 0x260064: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x26006C: movss [0x00418918], xmm7
	X86_MEM_WRITE_u32(base, 0x418918u, ctx.xmm[7].u32[0]);
	// 0x260074: movss [0x0041891C], xmm7
	X86_MEM_WRITE_u32(base, 0x41891Cu, ctx.xmm[7].u32[0]);
	// 0x26007C: movss xmm7, dword ptr [0x003B1768]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x260084: movss [0x00418930], xmm7
	X86_MEM_WRITE_u32(base, 0x418930u, ctx.xmm[7].u32[0]);
	// 0x26008C: movss xmm7, dword ptr [0x003A5A44]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A44u);
	// 0x260094: movss [0x00418934], xmm7
	X86_MEM_WRITE_u32(base, 0x418934u, ctx.xmm[7].u32[0]);
	// 0x26009C: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2600A4: movss [0x00418950], xmm7
	X86_MEM_WRITE_u32(base, 0x418950u, ctx.xmm[7].u32[0]);
	// 0x2600AC: movss xmm7, dword ptr [0x003B1884]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1884u);
	// 0x2600B4: movss [0x00418958], xmm7
	X86_MEM_WRITE_u32(base, 0x418958u, ctx.xmm[7].u32[0]);
	// 0x2600BC: movss xmm7, dword ptr [0x003A7950]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7950u);
	// 0x2600C4: movss [0x00418960], xmm7
	X86_MEM_WRITE_u32(base, 0x418960u, ctx.xmm[7].u32[0]);
	// 0x2600CC: movss xmm7, dword ptr [0x003A5A58]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A58u);
	// 0x2600D4: movss [0x00418964], xmm7
	X86_MEM_WRITE_u32(base, 0x418964u, ctx.xmm[7].u32[0]);
	// 0x2600DC: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x2600E4: movss [0x00418970], xmm7
	X86_MEM_WRITE_u32(base, 0x418970u, ctx.xmm[7].u32[0]);
	// 0x2600EC: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x2600F4: movss [0x00418974], xmm7
	X86_MEM_WRITE_u32(base, 0x418974u, ctx.xmm[7].u32[0]);
	// 0x2600FC: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x260104: movss [0x00418978], xmm7
	X86_MEM_WRITE_u32(base, 0x418978u, ctx.xmm[7].u32[0]);
	// 0x26010C: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x260114: movss [0x0041898C], xmm7
	X86_MEM_WRITE_u32(base, 0x41898Cu, ctx.xmm[7].u32[0]);
	// 0x26011C: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x260124: movss [0x00418994], xmm7
	X86_MEM_WRITE_u32(base, 0x418994u, ctx.xmm[7].u32[0]);
	// 0x26012C: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x260134: movss [0x00418998], xmm7
	X86_MEM_WRITE_u32(base, 0x418998u, ctx.xmm[7].u32[0]);
	// 0x26013C: movss [0x0041899C], xmm7
	X86_MEM_WRITE_u32(base, 0x41899Cu, ctx.xmm[7].u32[0]);
	// 0x260144: movss xmm7, dword ptr [0x003B03EC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B03ECu);
	// 0x26014C: mov [0x00418920], edi
	X86_MEM_WRITE_u32(base, 0x418920u, ctx.edi);
	// 0x260152: mov edi, 0x3AAF74
	ctx.edi = 3846004;
	// 0x260157: movss [0x004189B0], xmm7
	X86_MEM_WRITE_u32(base, 0x4189B0u, ctx.xmm[7].u32[0]);
	// 0x26015F: movss xmm7, dword ptr [0x003A69BC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69BCu);
	// 0x260167: mov [0x00418924], dl
	X86_MEM_WRITE_u8(base, 0x418924u, X86_REG8L(ctx.edx));
	// 0x26016D: mov [0x00418928], esi
	X86_MEM_WRITE_u32(base, 0x418928u, ctx.esi);
	// 0x260173: mov [0x0041892C], ecx
	X86_MEM_WRITE_u32(base, 0x41892Cu, ctx.ecx);
	// 0x260179: mov byte ptr [0x00418938], 0xA8
	X86_MEM_WRITE_u8(base, 0x418938u, -88);
	// 0x260180: mov byte ptr [0x00418939], 0xB0
	X86_MEM_WRITE_u8(base, 0x418939u, -80);
	// 0x260187: mov byte ptr [0x0041893A], 0xB8
	X86_MEM_WRITE_u8(base, 0x41893Au, -72);
	// 0x26018E: mov [0x0041893B], cl
	X86_MEM_WRITE_u8(base, 0x41893Bu, X86_REG8L(ctx.ecx));
	// 0x260194: mov byte ptr [0x0041893C], 0xA8
	X86_MEM_WRITE_u8(base, 0x41893Cu, -88);
	// 0x26019B: mov byte ptr [0x0041893D], 0xB0
	X86_MEM_WRITE_u8(base, 0x41893Du, -80);
	// 0x2601A2: mov byte ptr [0x0041893E], 0xB8
	X86_MEM_WRITE_u8(base, 0x41893Eu, -72);
	// 0x2601A9: mov byte ptr [0x0041893F], 0x60
	X86_MEM_WRITE_u8(base, 0x41893Fu, 96);
	// 0x2601B0: mov byte ptr [0x00418940], 0xA8
	X86_MEM_WRITE_u8(base, 0x418940u, -88);
	// 0x2601B7: mov byte ptr [0x00418941], 0xB0
	X86_MEM_WRITE_u8(base, 0x418941u, -80);
	// 0x2601BE: mov byte ptr [0x00418942], 0xB8
	X86_MEM_WRITE_u8(base, 0x418942u, -72);
	// 0x2601C5: mov [0x00418943], cl
	X86_MEM_WRITE_u8(base, 0x418943u, X86_REG8L(ctx.ecx));
	// 0x2601CB: mov [0x00418944], cl
	X86_MEM_WRITE_u8(base, 0x418944u, X86_REG8L(ctx.ecx));
	// 0x2601D1: movss [0x00418948], xmm3
	X86_MEM_WRITE_u32(base, 0x418948u, ctx.xmm[3].u32[0]);
	// 0x2601D9: movss [0x0041894C], xmm2
	X86_MEM_WRITE_u32(base, 0x41894Cu, ctx.xmm[2].u32[0]);
	// 0x2601E1: movss [0x00418954], xmm3
	X86_MEM_WRITE_u32(base, 0x418954u, ctx.xmm[3].u32[0]);
	// 0x2601E9: movss [0x0041895C], xmm2
	X86_MEM_WRITE_u32(base, 0x41895Cu, ctx.xmm[2].u32[0]);
	// 0x2601F1: movss [0x00418968], xmm1
	X86_MEM_WRITE_u32(base, 0x418968u, ctx.xmm[1].u32[0]);
	// 0x2601F9: movss [0x0041896C], xmm4
	X86_MEM_WRITE_u32(base, 0x41896Cu, ctx.xmm[4].u32[0]);
	// 0x260201: mov [0x0041897C], dl
	X86_MEM_WRITE_u8(base, 0x41897Cu, X86_REG8L(ctx.edx));
	// 0x260207: mov [0x0041897D], cl
	X86_MEM_WRITE_u8(base, 0x41897Du, X86_REG8L(ctx.ecx));
	// 0x26020D: mov dword ptr [0x00418980], 0xF0
	X86_MEM_WRITE_u32(base, 0x418980u, 240);
	// 0x260217: mov [0x00418984], ecx
	X86_MEM_WRITE_u32(base, 0x418984u, ctx.ecx);
	// 0x26021D: mov [0x00418988], eax
	X86_MEM_WRITE_u32(base, 0x418988u, ctx.eax);
	// 0x260222: movss [0x00418990], xmm5
	X86_MEM_WRITE_u32(base, 0x418990u, ctx.xmm[5].u32[0]);
	// 0x26022A: mov [0x004189A0], edi
	X86_MEM_WRITE_u32(base, 0x4189A0u, ctx.edi);
	// 0x260230: mov [0x004189A4], dl
	X86_MEM_WRITE_u8(base, 0x4189A4u, X86_REG8L(ctx.edx));
	// 0x260236: mov [0x004189A8], ecx
	X86_MEM_WRITE_u32(base, 0x4189A8u, ctx.ecx);
	// 0x26023C: mov [0x004189AC], edx
	X86_MEM_WRITE_u32(base, 0x4189ACu, ctx.edx);
	// 0x260242: movss [0x004189B4], xmm7
	X86_MEM_WRITE_u32(base, 0x4189B4u, ctx.xmm[7].u32[0]);
	// 0x26024A: mov [0x004189B8], al
	X86_MEM_WRITE_u8(base, 0x4189B8u, X86_REG8L(ctx.eax));
	// 0x26024F: mov [0x004189B9], al
	X86_MEM_WRITE_u8(base, 0x4189B9u, X86_REG8L(ctx.eax));
	// 0x260254: mov [0x004189BA], al
	X86_MEM_WRITE_u8(base, 0x4189BAu, X86_REG8L(ctx.eax));
	// 0x260259: mov byte ptr [0x004189BB], 0x10
	X86_MEM_WRITE_u8(base, 0x4189BBu, 16);
	// 0x260260: mov [0x004189BC], al
	X86_MEM_WRITE_u8(base, 0x4189BCu, X86_REG8L(ctx.eax));
	// 0x260265: mov [0x004189BD], al
	X86_MEM_WRITE_u8(base, 0x4189BDu, X86_REG8L(ctx.eax));
	// 0x26026A: mov [0x004189BE], al
	X86_MEM_WRITE_u8(base, 0x4189BEu, X86_REG8L(ctx.eax));
	// 0x26026F: mov [0x004189BF], al
	X86_MEM_WRITE_u8(base, 0x4189BFu, X86_REG8L(ctx.eax));
	// 0x260274: mov [0x004189C0], al
	X86_MEM_WRITE_u8(base, 0x4189C0u, X86_REG8L(ctx.eax));
	// 0x260279: mov [0x004189C1], al
	X86_MEM_WRITE_u8(base, 0x4189C1u, X86_REG8L(ctx.eax));
	// 0x26027E: mov [0x004189C2], al
	X86_MEM_WRITE_u8(base, 0x4189C2u, X86_REG8L(ctx.eax));
	// 0x260283: mov [0x004189C3], cl
	X86_MEM_WRITE_u8(base, 0x4189C3u, X86_REG8L(ctx.ecx));
	// 0x260289: mov [0x004189C4], cl
	X86_MEM_WRITE_u8(base, 0x4189C4u, X86_REG8L(ctx.ecx));
	// 0x26028F: movss xmm7, dword ptr [0x003B1698]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x260297: movss [0x004189CC], xmm7
	X86_MEM_WRITE_u32(base, 0x4189CCu, ctx.xmm[7].u32[0]);
	// 0x26029F: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x2602A7: movss [0x004189D0], xmm7
	X86_MEM_WRITE_u32(base, 0x4189D0u, ctx.xmm[7].u32[0]);
	// 0x2602AF: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x2602B7: movss [0x004189D8], xmm7
	X86_MEM_WRITE_u32(base, 0x4189D8u, ctx.xmm[7].u32[0]);
	// 0x2602BF: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2602C7: movss [0x004189DC], xmm7
	X86_MEM_WRITE_u32(base, 0x4189DCu, ctx.xmm[7].u32[0]);
	// 0x2602CF: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x2602D7: movss [0x004189E0], xmm7
	X86_MEM_WRITE_u32(base, 0x4189E0u, ctx.xmm[7].u32[0]);
	// 0x2602DF: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x2602E7: movss [0x004189E4], xmm7
	X86_MEM_WRITE_u32(base, 0x4189E4u, ctx.xmm[7].u32[0]);
	// 0x2602EF: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x2602F7: movss [0x004189F0], xmm7
	X86_MEM_WRITE_u32(base, 0x4189F0u, ctx.xmm[7].u32[0]);
	// 0x2602FF: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x260307: movss [0x004189F8], xmm7
	X86_MEM_WRITE_u32(base, 0x4189F8u, ctx.xmm[7].u32[0]);
	// 0x26030F: movss xmm7, dword ptr [0x00395BE0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395BE0u);
	// 0x260317: movss [0x00418A0C], xmm7
	X86_MEM_WRITE_u32(base, 0x418A0Cu, ctx.xmm[7].u32[0]);
	// 0x26031F: movss xmm7, dword ptr [0x003B1698]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x260327: movss [0x00418A30], xmm7
	X86_MEM_WRITE_u32(base, 0x418A30u, ctx.xmm[7].u32[0]);
	// 0x26032F: movss xmm7, dword ptr [0x003B1730]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x260337: movss [0x00418A34], xmm7
	X86_MEM_WRITE_u32(base, 0x418A34u, ctx.xmm[7].u32[0]);
	// 0x26033F: movss [0x00418A48], xmm7
	X86_MEM_WRITE_u32(base, 0x418A48u, ctx.xmm[7].u32[0]);
	// 0x260347: movss xmm7, dword ptr [0x003B18B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B18B8u);
	// 0x26034F: movss [0x00418A4C], xmm7
	X86_MEM_WRITE_u32(base, 0x418A4Cu, ctx.xmm[7].u32[0]);
	// 0x260357: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x26035F: movss [0x00418A50], xmm7
	X86_MEM_WRITE_u32(base, 0x418A50u, ctx.xmm[7].u32[0]);
	// 0x260367: movss xmm7, dword ptr [0x003B16D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16D8u);
	// 0x26036F: movss [0x00418A58], xmm7
	X86_MEM_WRITE_u32(base, 0x418A58u, ctx.xmm[7].u32[0]);
	// 0x260377: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x26037F: movss [0x00418A5C], xmm7
	X86_MEM_WRITE_u32(base, 0x418A5Cu, ctx.xmm[7].u32[0]);
	// 0x260387: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x26038F: movss [0x00418A60], xmm7
	X86_MEM_WRITE_u32(base, 0x418A60u, ctx.xmm[7].u32[0]);
	// 0x260397: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x26039F: movss [0x00418A70], xmm7
	X86_MEM_WRITE_u32(base, 0x418A70u, ctx.xmm[7].u32[0]);
	// 0x2603A7: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x2603AF: movss [0x00418A74], xmm7
	X86_MEM_WRITE_u32(base, 0x418A74u, ctx.xmm[7].u32[0]);
	// 0x2603B7: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x2603BF: movss [0x00418A78], xmm7
	X86_MEM_WRITE_u32(base, 0x418A78u, ctx.xmm[7].u32[0]);
	// 0x2603C7: movss xmm7, dword ptr [0x003A49FC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A49FCu);
	// 0x2603CF: movss [0x004189C8], xmm0
	X86_MEM_WRITE_u32(base, 0x4189C8u, ctx.xmm[0].u32[0]);
	// 0x2603D7: movss [0x004189D4], xmm2
	X86_MEM_WRITE_u32(base, 0x4189D4u, ctx.xmm[2].u32[0]);
	// 0x2603DF: movss [0x004189E8], xmm1
	X86_MEM_WRITE_u32(base, 0x4189E8u, ctx.xmm[1].u32[0]);
	// 0x2603E7: movss [0x004189EC], xmm4
	X86_MEM_WRITE_u32(base, 0x4189ECu, ctx.xmm[4].u32[0]);
	// 0x2603EF: movss [0x004189F4], xmm0
	X86_MEM_WRITE_u32(base, 0x4189F4u, ctx.xmm[0].u32[0]);
	// 0x2603F7: mov [0x004189FC], cl
	X86_MEM_WRITE_u8(base, 0x4189FCu, X86_REG8L(ctx.ecx));
	// 0x2603FD: mov [0x004189FD], dl
	X86_MEM_WRITE_u8(base, 0x4189FDu, X86_REG8L(ctx.edx));
	// 0x260403: mov [0x00418A00], ecx
	X86_MEM_WRITE_u32(base, 0x418A00u, ctx.ecx);
	// 0x260409: mov [0x00418A04], ebp
	X86_MEM_WRITE_u32(base, 0x418A04u, ctx.ebp);
	// 0x26040F: mov [0x00418A08], eax
	X86_MEM_WRITE_u32(base, 0x418A08u, ctx.eax);
	// 0x260414: movss [0x00418A10], xmm5
	X86_MEM_WRITE_u32(base, 0x418A10u, ctx.xmm[5].u32[0]);
	// 0x26041C: movss [0x00418A14], xmm1
	X86_MEM_WRITE_u32(base, 0x418A14u, ctx.xmm[1].u32[0]);
	// 0x260424: movss [0x00418A18], xmm6
	X86_MEM_WRITE_u32(base, 0x418A18u, ctx.xmm[6].u32[0]);
	// 0x26042C: movss [0x00418A1C], xmm6
	X86_MEM_WRITE_u32(base, 0x418A1Cu, ctx.xmm[6].u32[0]);
	// 0x260434: mov [0x00418A20], edi
	X86_MEM_WRITE_u32(base, 0x418A20u, ctx.edi);
	// 0x26043A: mov [0x00418A24], dl
	X86_MEM_WRITE_u8(base, 0x418A24u, X86_REG8L(ctx.edx));
	// 0x260440: mov [0x00418A28], ecx
	X86_MEM_WRITE_u32(base, 0x418A28u, ctx.ecx);
	// 0x260446: mov [0x00418A2C], ecx
	X86_MEM_WRITE_u32(base, 0x418A2Cu, ctx.ecx);
	// 0x26044C: mov [0x00418A38], al
	X86_MEM_WRITE_u8(base, 0x418A38u, X86_REG8L(ctx.eax));
	// 0x260451: mov [0x00418A39], al
	X86_MEM_WRITE_u8(base, 0x418A39u, X86_REG8L(ctx.eax));
	// 0x260456: mov [0x00418A3A], bl
	X86_MEM_WRITE_u8(base, 0x418A3Au, X86_REG8L(ctx.ebx));
	// 0x26045C: mov [0x00418A3B], al
	X86_MEM_WRITE_u8(base, 0x418A3Bu, X86_REG8L(ctx.eax));
	// 0x260461: mov byte ptr [0x00418A3C], 0x60
	X86_MEM_WRITE_u8(base, 0x418A3Cu, 96);
	// 0x260468: mov byte ptr [0x00418A3D], 0x30
	X86_MEM_WRITE_u8(base, 0x418A3Du, 48);
	// 0x26046F: mov byte ptr [0x00418A3E], 0x18
	X86_MEM_WRITE_u8(base, 0x418A3Eu, 24);
	// 0x260476: mov byte ptr [0x00418A3F], 0x80
	X86_MEM_WRITE_u8(base, 0x418A3Fu, -128);
	// 0x26047D: mov [0x00418A40], cl
	X86_MEM_WRITE_u8(base, 0x418A40u, X86_REG8L(ctx.ecx));
	// 0x260483: mov [0x00418A41], cl
	X86_MEM_WRITE_u8(base, 0x418A41u, X86_REG8L(ctx.ecx));
	// 0x260489: mov [0x00418A42], cl
	X86_MEM_WRITE_u8(base, 0x418A42u, X86_REG8L(ctx.ecx));
	// 0x26048F: mov [0x00418A43], cl
	X86_MEM_WRITE_u8(base, 0x418A43u, X86_REG8L(ctx.ecx));
	// 0x260495: mov [0x00418A44], dl
	X86_MEM_WRITE_u8(base, 0x418A44u, X86_REG8L(ctx.edx));
	// 0x26049B: movss [0x00418A54], xmm2
	X86_MEM_WRITE_u32(base, 0x418A54u, ctx.xmm[2].u32[0]);
	// 0x2604A3: movss [0x00418A64], xmm6
	X86_MEM_WRITE_u32(base, 0x418A64u, ctx.xmm[6].u32[0]);
	// 0x2604AB: movss [0x00418A68], xmm1
	X86_MEM_WRITE_u32(base, 0x418A68u, ctx.xmm[1].u32[0]);
	// 0x2604B3: movss [0x00418A6C], xmm4
	X86_MEM_WRITE_u32(base, 0x418A6Cu, ctx.xmm[4].u32[0]);
	// 0x2604BB: mov [0x00418A7C], dl
	X86_MEM_WRITE_u8(base, 0x418A7Cu, X86_REG8L(ctx.edx));
	// 0x2604C1: mov [0x00418A7D], dl
	X86_MEM_WRITE_u8(base, 0x418A7Du, X86_REG8L(ctx.edx));
	// 0x2604C7: mov [0x00418A80], ecx
	X86_MEM_WRITE_u32(base, 0x418A80u, ctx.ecx);
	// 0x2604CD: mov dword ptr [0x00418A84], 0xC8
	X86_MEM_WRITE_u32(base, 0x418A84u, 200);
	// 0x2604D7: mov [0x00418A88], eax
	X86_MEM_WRITE_u32(base, 0x418A88u, ctx.eax);
	// 0x2604DC: movss [0x00418A8C], xmm7
	X86_MEM_WRITE_u32(base, 0x418A8Cu, ctx.xmm[7].u32[0]);
	// 0x2604E4: movss xmm7, dword ptr [0x003B1768]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x2604EC: movss [0x00418AB0], xmm7
	X86_MEM_WRITE_u32(base, 0x418AB0u, ctx.xmm[7].u32[0]);
	// 0x2604F4: movss xmm7, dword ptr [0x003B1B28]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1B28u);
	// 0x2604FC: movss [0x00418AB4], xmm7
	X86_MEM_WRITE_u32(base, 0x418AB4u, ctx.xmm[7].u32[0]);
	// 0x260504: movss xmm7, dword ptr [0x0039C16C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39C16Cu);
	// 0x26050C: movss [0x00418AC8], xmm7
	X86_MEM_WRITE_u32(base, 0x418AC8u, ctx.xmm[7].u32[0]);
	// 0x260514: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x26051C: movss [0x00418ACC], xmm7
	X86_MEM_WRITE_u32(base, 0x418ACCu, ctx.xmm[7].u32[0]);
	// 0x260524: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x26052C: movss [0x00418AD0], xmm7
	X86_MEM_WRITE_u32(base, 0x418AD0u, ctx.xmm[7].u32[0]);
	// 0x260534: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x26053C: movss [0x00418AD8], xmm7
	X86_MEM_WRITE_u32(base, 0x418AD8u, ctx.xmm[7].u32[0]);
	// 0x260544: movss xmm7, dword ptr [0x003B1884]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1884u);
	// 0x26054C: movss [0x00418AE0], xmm7
	X86_MEM_WRITE_u32(base, 0x418AE0u, ctx.xmm[7].u32[0]);
	// 0x260554: movss xmm7, dword ptr [0x00395E88]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395E88u);
	// 0x26055C: movss [0x00418AE4], xmm7
	X86_MEM_WRITE_u32(base, 0x418AE4u, ctx.xmm[7].u32[0]);
	// 0x260564: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x26056C: movss [0x00418AE8], xmm7
	X86_MEM_WRITE_u32(base, 0x418AE8u, ctx.xmm[7].u32[0]);
	// 0x260574: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x26057C: movss [0x00418AF0], xmm7
	X86_MEM_WRITE_u32(base, 0x418AF0u, ctx.xmm[7].u32[0]);
	// 0x260584: movss xmm7, dword ptr [0x003B17AC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17ACu);
	// 0x26058C: movss [0x00418AF4], xmm7
	X86_MEM_WRITE_u32(base, 0x418AF4u, ctx.xmm[7].u32[0]);
	// 0x260594: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x26059C: movss [0x00418AF8], xmm7
	X86_MEM_WRITE_u32(base, 0x418AF8u, ctx.xmm[7].u32[0]);
	// 0x2605A4: movss xmm7, dword ptr [0x00395BE4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2605AC: movss [0x00418B0C], xmm7
	X86_MEM_WRITE_u32(base, 0x418B0Cu, ctx.xmm[7].u32[0]);
	// 0x2605B4: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2605BC: movss [0x00418B14], xmm7
	X86_MEM_WRITE_u32(base, 0x418B14u, ctx.xmm[7].u32[0]);
	// 0x2605C4: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x2605CC: movss [0x00418B18], xmm7
	X86_MEM_WRITE_u32(base, 0x418B18u, ctx.xmm[7].u32[0]);
	// 0x2605D4: movss [0x00418B1C], xmm7
	X86_MEM_WRITE_u32(base, 0x418B1Cu, ctx.xmm[7].u32[0]);
	// 0x2605DC: movss xmm7, dword ptr [0x003B03EC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B03ECu);
	// 0x2605E4: movss [0x00418A90], xmm5
	X86_MEM_WRITE_u32(base, 0x418A90u, ctx.xmm[5].u32[0]);
	// 0x2605EC: movss [0x00418A94], xmm1
	X86_MEM_WRITE_u32(base, 0x418A94u, ctx.xmm[1].u32[0]);
	// 0x2605F4: movss [0x00418A98], xmm0
	X86_MEM_WRITE_u32(base, 0x418A98u, ctx.xmm[0].u32[0]);
	// 0x2605FC: movss [0x00418A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x418A9Cu, ctx.xmm[0].u32[0]);
	// 0x260604: mov dword ptr [0x00418AA0], 0x3AAF88
	X86_MEM_WRITE_u32(base, 0x418AA0u, 3846024);
	// 0x26060E: mov [0x00418AA4], dl
	X86_MEM_WRITE_u8(base, 0x418AA4u, X86_REG8L(ctx.edx));
	// 0x260614: mov [0x00418AA8], ecx
	X86_MEM_WRITE_u32(base, 0x418AA8u, ctx.ecx);
	// 0x26061A: mov [0x00418AAC], esi
	X86_MEM_WRITE_u32(base, 0x418AACu, ctx.esi);
	// 0x260620: mov [0x00418AB8], al
	X86_MEM_WRITE_u8(base, 0x418AB8u, X86_REG8L(ctx.eax));
	// 0x260625: mov [0x00418AB9], al
	X86_MEM_WRITE_u8(base, 0x418AB9u, X86_REG8L(ctx.eax));
	// 0x26062A: mov [0x00418ABA], al
	X86_MEM_WRITE_u8(base, 0x418ABAu, X86_REG8L(ctx.eax));
	// 0x26062F: mov [0x00418ABB], al
	X86_MEM_WRITE_u8(base, 0x418ABBu, X86_REG8L(ctx.eax));
	// 0x260634: mov [0x00418ABC], bl
	X86_MEM_WRITE_u8(base, 0x418ABCu, X86_REG8L(ctx.ebx));
	// 0x26063A: mov byte ptr [0x00418ABD], 0x80
	X86_MEM_WRITE_u8(base, 0x418ABDu, -128);
	// 0x260641: mov byte ptr [0x00418ABE], 0x40
	X86_MEM_WRITE_u8(base, 0x418ABEu, 64);
	// 0x260648: mov [0x00418ABF], al
	X86_MEM_WRITE_u8(base, 0x418ABFu, X86_REG8L(ctx.eax));
	// 0x26064D: mov byte ptr [0x00418AC0], 0x80
	X86_MEM_WRITE_u8(base, 0x418AC0u, -128);
	// 0x260654: mov byte ptr [0x00418AC1], 0x10
	X86_MEM_WRITE_u8(base, 0x418AC1u, 16);
	// 0x26065B: mov byte ptr [0x00418AC2], 0x08
	X86_MEM_WRITE_u8(base, 0x418AC2u, 8);
	// 0x260662: mov [0x00418AC3], cl
	X86_MEM_WRITE_u8(base, 0x418AC3u, X86_REG8L(ctx.ecx));
	// 0x260668: mov [0x00418AC4], dl
	X86_MEM_WRITE_u8(base, 0x418AC4u, X86_REG8L(ctx.edx));
	// 0x26066E: movss [0x00418AD4], xmm3
	X86_MEM_WRITE_u32(base, 0x418AD4u, ctx.xmm[3].u32[0]);
	// 0x260676: movss [0x00418ADC], xmm2
	X86_MEM_WRITE_u32(base, 0x418ADCu, ctx.xmm[2].u32[0]);
	// 0x26067E: movss [0x00418AEC], xmm4
	X86_MEM_WRITE_u32(base, 0x418AECu, ctx.xmm[4].u32[0]);
	// 0x260686: mov [0x00418AFC], dl
	X86_MEM_WRITE_u8(base, 0x418AFCu, X86_REG8L(ctx.edx));
	// 0x26068C: mov [0x00418AFD], dl
	X86_MEM_WRITE_u8(base, 0x418AFDu, X86_REG8L(ctx.edx));
	// 0x260692: mov [0x00418B00], ecx
	X86_MEM_WRITE_u32(base, 0x418B00u, ctx.ecx);
	// 0x260698: mov dword ptr [0x00418B04], 0x96
	X86_MEM_WRITE_u32(base, 0x418B04u, 150);
	// 0x2606A2: mov [0x00418B08], eax
	X86_MEM_WRITE_u32(base, 0x418B08u, ctx.eax);
	// 0x2606A7: movss [0x00418B10], xmm5
	X86_MEM_WRITE_u32(base, 0x418B10u, ctx.xmm[5].u32[0]);
	// 0x2606AF: mov [0x00418B20], edi
	X86_MEM_WRITE_u32(base, 0x418B20u, ctx.edi);
	// 0x2606B5: mov [0x00418B24], dl
	X86_MEM_WRITE_u8(base, 0x418B24u, X86_REG8L(ctx.edx));
	// 0x2606BB: mov [0x00418B28], ecx
	X86_MEM_WRITE_u32(base, 0x418B28u, ctx.ecx);
	// 0x2606C1: mov [0x00418B2C], ecx
	X86_MEM_WRITE_u32(base, 0x418B2Cu, ctx.ecx);
	// 0x2606C7: movss [0x00418B30], xmm7
	X86_MEM_WRITE_u32(base, 0x418B30u, ctx.xmm[7].u32[0]);
	// 0x2606CF: movss [0x00418B34], xmm1
	X86_MEM_WRITE_u32(base, 0x418B34u, ctx.xmm[1].u32[0]);
	// 0x2606D7: mov [0x00418B38], cl
	X86_MEM_WRITE_u8(base, 0x418B38u, X86_REG8L(ctx.ecx));
	// 0x2606DD: mov [0x00418B39], cl
	X86_MEM_WRITE_u8(base, 0x418B39u, X86_REG8L(ctx.ecx));
	// 0x2606E3: mov [0x00418B3A], cl
	X86_MEM_WRITE_u8(base, 0x418B3Au, X86_REG8L(ctx.ecx));
	// 0x2606E9: mov [0x00418B3B], al
	X86_MEM_WRITE_u8(base, 0x418B3Bu, X86_REG8L(ctx.eax));
	// 0x2606EE: mov [0x00418B3C], al
	X86_MEM_WRITE_u8(base, 0x418B3Cu, X86_REG8L(ctx.eax));
	// 0x2606F3: mov [0x00418B3D], al
	X86_MEM_WRITE_u8(base, 0x418B3Du, X86_REG8L(ctx.eax));
	// 0x2606F8: mov [0x00418B3E], al
	X86_MEM_WRITE_u8(base, 0x418B3Eu, X86_REG8L(ctx.eax));
	// 0x2606FD: mov byte ptr [0x00418B3F], 0xA0
	X86_MEM_WRITE_u8(base, 0x418B3Fu, -96);
	// 0x260704: mov [0x00418B40], al
	X86_MEM_WRITE_u8(base, 0x418B40u, X86_REG8L(ctx.eax));
	// 0x260709: mov [0x00418B41], al
	X86_MEM_WRITE_u8(base, 0x418B41u, X86_REG8L(ctx.eax));
	// 0x26070E: mov [0x00418B42], al
	X86_MEM_WRITE_u8(base, 0x418B42u, X86_REG8L(ctx.eax));
	// 0x260713: mov [0x00418B43], cl
	X86_MEM_WRITE_u8(base, 0x418B43u, X86_REG8L(ctx.ecx));
	// 0x260719: mov [0x00418B44], cl
	X86_MEM_WRITE_u8(base, 0x418B44u, X86_REG8L(ctx.ecx));
	// 0x26071F: movss xmm7, dword ptr [0x003B1870]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x260727: movss [0x00418B4C], xmm7
	X86_MEM_WRITE_u32(base, 0x418B4Cu, ctx.xmm[7].u32[0]);
	// 0x26072F: movss xmm7, dword ptr [0x003B1698]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x260737: movss [0x00418B50], xmm7
	X86_MEM_WRITE_u32(base, 0x418B50u, ctx.xmm[7].u32[0]);
	// 0x26073F: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x260747: movss [0x00418B58], xmm7
	X86_MEM_WRITE_u32(base, 0x418B58u, ctx.xmm[7].u32[0]);
	// 0x26074F: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x260757: movss [0x00418B5C], xmm7
	X86_MEM_WRITE_u32(base, 0x418B5Cu, ctx.xmm[7].u32[0]);
	// 0x26075F: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x260767: movss [0x00418B60], xmm7
	X86_MEM_WRITE_u32(base, 0x418B60u, ctx.xmm[7].u32[0]);
	// 0x26076F: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x260777: movss [0x00418B64], xmm7
	X86_MEM_WRITE_u32(base, 0x418B64u, ctx.xmm[7].u32[0]);
	// 0x26077F: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x260787: movss [0x00418B70], xmm7
	X86_MEM_WRITE_u32(base, 0x418B70u, ctx.xmm[7].u32[0]);
	// 0x26078F: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x260797: movss [0x00418B74], xmm7
	X86_MEM_WRITE_u32(base, 0x418B74u, ctx.xmm[7].u32[0]);
	// 0x26079F: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x2607A7: movss [0x00418B78], xmm7
	X86_MEM_WRITE_u32(base, 0x418B78u, ctx.xmm[7].u32[0]);
	// 0x2607AF: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x2607B7: movss [0x00418B8C], xmm7
	X86_MEM_WRITE_u32(base, 0x418B8Cu, ctx.xmm[7].u32[0]);
	// 0x2607BF: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x2607C7: movss [0x00418BB0], xmm7
	X86_MEM_WRITE_u32(base, 0x418BB0u, ctx.xmm[7].u32[0]);
	// 0x2607CF: movss xmm7, dword ptr [0x003B1730]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2607D7: movss [0x00418BB4], xmm7
	X86_MEM_WRITE_u32(base, 0x418BB4u, ctx.xmm[7].u32[0]);
	// 0x2607DF: movss [0x00418BC8], xmm7
	X86_MEM_WRITE_u32(base, 0x418BC8u, ctx.xmm[7].u32[0]);
	// 0x2607E7: movss xmm7, dword ptr [0x003B18B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B18B8u);
	// 0x2607EF: movss [0x00418BCC], xmm7
	X86_MEM_WRITE_u32(base, 0x418BCCu, ctx.xmm[7].u32[0]);
	// 0x2607F7: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x2607FF: movss [0x00418BD0], xmm7
	X86_MEM_WRITE_u32(base, 0x418BD0u, ctx.xmm[7].u32[0]);
	// 0x260807: movss xmm7, dword ptr [0x003B16D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16D8u);
	// 0x26080F: movss [0x00418BD8], xmm7
	X86_MEM_WRITE_u32(base, 0x418BD8u, ctx.xmm[7].u32[0]);
	// 0x260817: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x26081F: movss [0x00418BDC], xmm7
	X86_MEM_WRITE_u32(base, 0x418BDCu, ctx.xmm[7].u32[0]);
	// 0x260827: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x26082F: movss [0x00418BE0], xmm7
	X86_MEM_WRITE_u32(base, 0x418BE0u, ctx.xmm[7].u32[0]);
	// 0x260837: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x26083F: movss [0x00418BE4], xmm7
	X86_MEM_WRITE_u32(base, 0x418BE4u, ctx.xmm[7].u32[0]);
	// 0x260847: movss xmm7, dword ptr [0x003A7ED8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x26084F: movss [0x00418BF0], xmm7
	X86_MEM_WRITE_u32(base, 0x418BF0u, ctx.xmm[7].u32[0]);
	// 0x260857: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x26085F: movss [0x00418BF4], xmm7
	X86_MEM_WRITE_u32(base, 0x418BF4u, ctx.xmm[7].u32[0]);
	// 0x260867: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x26086F: movss [0x00418B48], xmm2
	X86_MEM_WRITE_u32(base, 0x418B48u, ctx.xmm[2].u32[0]);
	// 0x260877: movss [0x00418B54], xmm2
	X86_MEM_WRITE_u32(base, 0x418B54u, ctx.xmm[2].u32[0]);
	// 0x26087F: movss [0x00418B68], xmm1
	X86_MEM_WRITE_u32(base, 0x418B68u, ctx.xmm[1].u32[0]);
	// 0x260887: movss [0x00418B6C], xmm4
	X86_MEM_WRITE_u32(base, 0x418B6Cu, ctx.xmm[4].u32[0]);
	// 0x26088F: mov [0x00418B7C], dl
	X86_MEM_WRITE_u8(base, 0x418B7Cu, X86_REG8L(ctx.edx));
	// 0x260895: mov [0x00418B7D], dl
	X86_MEM_WRITE_u8(base, 0x418B7Du, X86_REG8L(ctx.edx));
	// 0x26089B: mov [0x00418B80], ecx
	X86_MEM_WRITE_u32(base, 0x418B80u, ctx.ecx);
	// 0x2608A1: mov [0x00418B84], ebp
	X86_MEM_WRITE_u32(base, 0x418B84u, ctx.ebp);
	// 0x2608A7: mov [0x00418B88], eax
	X86_MEM_WRITE_u32(base, 0x418B88u, ctx.eax);
	// 0x2608AC: movss [0x00418B90], xmm5
	X86_MEM_WRITE_u32(base, 0x418B90u, ctx.xmm[5].u32[0]);
	// 0x2608B4: movss [0x00418B94], xmm1
	X86_MEM_WRITE_u32(base, 0x418B94u, ctx.xmm[1].u32[0]);
	// 0x2608BC: movss [0x00418B98], xmm6
	X86_MEM_WRITE_u32(base, 0x418B98u, ctx.xmm[6].u32[0]);
	// 0x2608C4: movss [0x00418B9C], xmm6
	X86_MEM_WRITE_u32(base, 0x418B9Cu, ctx.xmm[6].u32[0]);
	// 0x2608CC: mov [0x00418BA0], edi
	X86_MEM_WRITE_u32(base, 0x418BA0u, ctx.edi);
	// 0x2608D2: mov [0x00418BA4], dl
	X86_MEM_WRITE_u8(base, 0x418BA4u, X86_REG8L(ctx.edx));
	// 0x2608D8: mov [0x00418BA8], ecx
	X86_MEM_WRITE_u32(base, 0x418BA8u, ctx.ecx);
	// 0x2608DE: mov [0x00418BAC], ecx
	X86_MEM_WRITE_u32(base, 0x418BACu, ctx.ecx);
	// 0x2608E4: mov [0x00418BB8], al
	X86_MEM_WRITE_u8(base, 0x418BB8u, X86_REG8L(ctx.eax));
	// 0x2608E9: mov [0x00418BB9], al
	X86_MEM_WRITE_u8(base, 0x418BB9u, X86_REG8L(ctx.eax));
	// 0x2608EE: mov [0x00418BBA], bl
	X86_MEM_WRITE_u8(base, 0x418BBAu, X86_REG8L(ctx.ebx));
	// 0x2608F4: mov [0x00418BBB], al
	X86_MEM_WRITE_u8(base, 0x418BBBu, X86_REG8L(ctx.eax));
	// 0x2608F9: mov byte ptr [0x00418BBC], 0x60
	X86_MEM_WRITE_u8(base, 0x418BBCu, 96);
	// 0x260900: mov byte ptr [0x00418BBD], 0x30
	X86_MEM_WRITE_u8(base, 0x418BBDu, 48);
	// 0x260907: mov byte ptr [0x00418BBE], 0x18
	X86_MEM_WRITE_u8(base, 0x418BBEu, 24);
	// 0x26090E: mov byte ptr [0x00418BBF], 0x80
	X86_MEM_WRITE_u8(base, 0x418BBFu, -128);
	// 0x260915: mov [0x00418BC0], cl
	X86_MEM_WRITE_u8(base, 0x418BC0u, X86_REG8L(ctx.ecx));
	// 0x26091B: mov [0x00418BC1], cl
	X86_MEM_WRITE_u8(base, 0x418BC1u, X86_REG8L(ctx.ecx));
	// 0x260921: mov [0x00418BC2], cl
	X86_MEM_WRITE_u8(base, 0x418BC2u, X86_REG8L(ctx.ecx));
	// 0x260927: mov [0x00418BC3], cl
	X86_MEM_WRITE_u8(base, 0x418BC3u, X86_REG8L(ctx.ecx));
	// 0x26092D: mov [0x00418BC4], dl
	X86_MEM_WRITE_u8(base, 0x418BC4u, X86_REG8L(ctx.edx));
	// 0x260933: movss [0x00418BD4], xmm2
	X86_MEM_WRITE_u32(base, 0x418BD4u, ctx.xmm[2].u32[0]);
	// 0x26093B: movss [0x00418BE8], xmm1
	X86_MEM_WRITE_u32(base, 0x418BE8u, ctx.xmm[1].u32[0]);
	// 0x260943: movss [0x00418BEC], xmm4
	X86_MEM_WRITE_u32(base, 0x418BECu, ctx.xmm[4].u32[0]);
	// 0x26094B: movss [0x00418BF8], xmm7
	X86_MEM_WRITE_u32(base, 0x418BF8u, ctx.xmm[7].u32[0]);
	// 0x260953: mov [0x00418BFC], dl
	X86_MEM_WRITE_u8(base, 0x418BFCu, X86_REG8L(ctx.edx));
	// 0x260959: mov [0x00418BFD], dl
	X86_MEM_WRITE_u8(base, 0x418BFDu, X86_REG8L(ctx.edx));
	// 0x26095F: mov [0x00418C00], ecx
	X86_MEM_WRITE_u32(base, 0x418C00u, ctx.ecx);
	// 0x260965: mov dword ptr [0x00418C04], 0xC8
	X86_MEM_WRITE_u32(base, 0x418C04u, 200);
	// 0x26096F: mov [0x00418C08], eax
	X86_MEM_WRITE_u32(base, 0x418C08u, ctx.eax);
	// 0x260974: movss xmm7, dword ptr [0x003A49FC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A49FCu);
	// 0x26097C: movss [0x00418C0C], xmm7
	X86_MEM_WRITE_u32(base, 0x418C0Cu, ctx.xmm[7].u32[0]);
	// 0x260984: movss xmm7, dword ptr [0x0039C16C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39C16Cu);
	// 0x26098C: movss [0x00418C34], xmm7
	X86_MEM_WRITE_u32(base, 0x418C34u, ctx.xmm[7].u32[0]);
	// 0x260994: movss xmm7, dword ptr [0x003895AC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3895ACu);
	// 0x26099C: movss [0x00418C4C], xmm7
	X86_MEM_WRITE_u32(base, 0x418C4Cu, ctx.xmm[7].u32[0]);
	// 0x2609A4: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2609AC: movss [0x00418C50], xmm7
	X86_MEM_WRITE_u32(base, 0x418C50u, ctx.xmm[7].u32[0]);
	// 0x2609B4: movss xmm7, dword ptr [0x003B17AC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17ACu);
	// 0x2609BC: movss [0x00418C54], xmm3
	X86_MEM_WRITE_u32(base, 0x418C54u, ctx.xmm[3].u32[0]);
	// 0x2609C4: movss xmm3, dword ptr [0x003A2928]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x2609CC: movss [0x00418C74], xmm7
	X86_MEM_WRITE_u32(base, 0x418C74u, ctx.xmm[7].u32[0]);
	// 0x2609D4: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x2609DC: movss [0x00418C58], xmm3
	X86_MEM_WRITE_u32(base, 0x418C58u, ctx.xmm[3].u32[0]);
	// 0x2609E4: movss xmm3, dword ptr [0x003B1884]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1884u);
	// 0x2609EC: movss [0x00418C78], xmm7
	X86_MEM_WRITE_u32(base, 0x418C78u, ctx.xmm[7].u32[0]);
	// 0x2609F4: movss xmm7, dword ptr [0x00395BE4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2609FC: movss [0x00418C60], xmm3
	X86_MEM_WRITE_u32(base, 0x418C60u, ctx.xmm[3].u32[0]);
	// 0x260A04: movss xmm3, dword ptr [0x003B214C]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B214Cu);
	// 0x260A0C: movss [0x00418C8C], xmm7
	X86_MEM_WRITE_u32(base, 0x418C8Cu, ctx.xmm[7].u32[0]);
	// 0x260A14: movss xmm7, dword ptr [0x003B1688]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x260A1C: movss [0x00418C64], xmm3
	X86_MEM_WRITE_u32(base, 0x418C64u, ctx.xmm[3].u32[0]);
	// 0x260A24: movss xmm3, dword ptr [0x003A69C0]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x260A2C: movss [0x00418C94], xmm7
	X86_MEM_WRITE_u32(base, 0x418C94u, ctx.xmm[7].u32[0]);
	// 0x260A34: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x260A3C: movss [0x00418C68], xmm3
	X86_MEM_WRITE_u32(base, 0x418C68u, ctx.xmm[3].u32[0]);
	// 0x260A44: movss xmm3, dword ptr [0x003A7ED8]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x260A4C: movss [0x00418C98], xmm7
	X86_MEM_WRITE_u32(base, 0x418C98u, ctx.xmm[7].u32[0]);
	// 0x260A54: movss [0x00418C9C], xmm7
	X86_MEM_WRITE_u32(base, 0x418C9Cu, ctx.xmm[7].u32[0]);
	// 0x260A5C: movss xmm7, dword ptr [0x003B17D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17D8u);
	// 0x260A64: movss [0x00418C10], xmm5
	X86_MEM_WRITE_u32(base, 0x418C10u, ctx.xmm[5].u32[0]);
	// 0x260A6C: movss [0x00418C14], xmm1
	X86_MEM_WRITE_u32(base, 0x418C14u, ctx.xmm[1].u32[0]);
	// 0x260A74: movss [0x00418C18], xmm0
	X86_MEM_WRITE_u32(base, 0x418C18u, ctx.xmm[0].u32[0]);
	// 0x260A7C: movss [0x00418C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x418C1Cu, ctx.xmm[0].u32[0]);
	// 0x260A84: mov dword ptr [0x00418C20], 0x3AAF88
	X86_MEM_WRITE_u32(base, 0x418C20u, 3846024);
	// 0x260A8E: mov [0x00418C24], dl
	X86_MEM_WRITE_u8(base, 0x418C24u, X86_REG8L(ctx.edx));
	// 0x260A94: mov [0x00418C28], ecx
	X86_MEM_WRITE_u32(base, 0x418C28u, ctx.ecx);
	// 0x260A9A: mov [0x00418C2C], esi
	X86_MEM_WRITE_u32(base, 0x418C2Cu, ctx.esi);
	// 0x260AA0: movss [0x00418C30], xmm1
	X86_MEM_WRITE_u32(base, 0x418C30u, ctx.xmm[1].u32[0]);
	// 0x260AA8: mov [0x00418C38], al
	X86_MEM_WRITE_u8(base, 0x418C38u, X86_REG8L(ctx.eax));
	// 0x260AAD: mov [0x00418C39], al
	X86_MEM_WRITE_u8(base, 0x418C39u, X86_REG8L(ctx.eax));
	// 0x260AB2: mov [0x00418C3A], al
	X86_MEM_WRITE_u8(base, 0x418C3Au, X86_REG8L(ctx.eax));
	// 0x260AB7: mov [0x00418C3B], al
	X86_MEM_WRITE_u8(base, 0x418C3Bu, X86_REG8L(ctx.eax));
	// 0x260ABC: mov [0x00418C3C], bl
	X86_MEM_WRITE_u8(base, 0x418C3Cu, X86_REG8L(ctx.ebx));
	// 0x260AC2: mov byte ptr [0x00418C3D], 0x70
	X86_MEM_WRITE_u8(base, 0x418C3Du, 112);
	// 0x260AC9: mov byte ptr [0x00418C3E], 0x40
	X86_MEM_WRITE_u8(base, 0x418C3Eu, 64);
	// 0x260AD0: mov [0x00418C3F], al
	X86_MEM_WRITE_u8(base, 0x418C3Fu, X86_REG8L(ctx.eax));
	// 0x260AD5: mov byte ptr [0x00418C40], 0x80
	X86_MEM_WRITE_u8(base, 0x418C40u, -128);
	// 0x260ADC: mov byte ptr [0x00418C41], 0x10
	X86_MEM_WRITE_u8(base, 0x418C41u, 16);
	// 0x260AE3: mov byte ptr [0x00418C42], 0x08
	X86_MEM_WRITE_u8(base, 0x418C42u, 8);
	// 0x260AEA: mov [0x00418C43], cl
	X86_MEM_WRITE_u8(base, 0x418C43u, X86_REG8L(ctx.ecx));
	// 0x260AF0: mov [0x00418C44], dl
	X86_MEM_WRITE_u8(base, 0x418C44u, X86_REG8L(ctx.edx));
	// 0x260AF6: movss [0x00418C48], xmm2
	X86_MEM_WRITE_u32(base, 0x418C48u, ctx.xmm[2].u32[0]);
	// 0x260AFE: movss [0x00418C5C], xmm2
	X86_MEM_WRITE_u32(base, 0x418C5Cu, ctx.xmm[2].u32[0]);
	// 0x260B06: movss [0x00418C6C], xmm4
	X86_MEM_WRITE_u32(base, 0x418C6Cu, ctx.xmm[4].u32[0]);
	// 0x260B0E: movss [0x00418C70], xmm3
	X86_MEM_WRITE_u32(base, 0x418C70u, ctx.xmm[3].u32[0]);
	// 0x260B16: mov [0x00418C7C], dl
	X86_MEM_WRITE_u8(base, 0x418C7Cu, X86_REG8L(ctx.edx));
	// 0x260B1C: mov [0x00418C7D], dl
	X86_MEM_WRITE_u8(base, 0x418C7Du, X86_REG8L(ctx.edx));
	// 0x260B22: mov [0x00418C80], ecx
	X86_MEM_WRITE_u32(base, 0x418C80u, ctx.ecx);
	// 0x260B28: mov dword ptr [0x00418C84], 0xF0
	X86_MEM_WRITE_u32(base, 0x418C84u, 240);
	// 0x260B32: mov [0x00418C88], eax
	X86_MEM_WRITE_u32(base, 0x418C88u, ctx.eax);
	// 0x260B37: movss [0x00418C90], xmm5
	X86_MEM_WRITE_u32(base, 0x418C90u, ctx.xmm[5].u32[0]);
	// 0x260B3F: mov [0x00418CA0], edi
	X86_MEM_WRITE_u32(base, 0x418CA0u, ctx.edi);
	// 0x260B45: mov [0x00418CA4], dl
	X86_MEM_WRITE_u8(base, 0x418CA4u, X86_REG8L(ctx.edx));
	// 0x260B4B: mov [0x00418CA8], ecx
	X86_MEM_WRITE_u32(base, 0x418CA8u, ctx.ecx);
	// 0x260B51: mov [0x00418CAC], ecx
	X86_MEM_WRITE_u32(base, 0x418CACu, ctx.ecx);
	// 0x260B57: movss [0x00418CB0], xmm7
	X86_MEM_WRITE_u32(base, 0x418CB0u, ctx.xmm[7].u32[0]);
	// 0x260B5F: movss [0x00418CB4], xmm2
	X86_MEM_WRITE_u32(base, 0x418CB4u, ctx.xmm[2].u32[0]);
	// 0x260B67: mov [0x00418CB8], cl
	X86_MEM_WRITE_u8(base, 0x418CB8u, X86_REG8L(ctx.ecx));
	// 0x260B6D: mov [0x00418CB9], cl
	X86_MEM_WRITE_u8(base, 0x418CB9u, X86_REG8L(ctx.ecx));
	// 0x260B73: mov [0x00418CBA], cl
	X86_MEM_WRITE_u8(base, 0x418CBAu, X86_REG8L(ctx.ecx));
	// 0x260B79: mov [0x00418CBB], al
	X86_MEM_WRITE_u8(base, 0x418CBBu, X86_REG8L(ctx.eax));
	// 0x260B7E: mov [0x00418CBC], al
	X86_MEM_WRITE_u8(base, 0x418CBCu, X86_REG8L(ctx.eax));
	// 0x260B83: mov [0x00418CBD], al
	X86_MEM_WRITE_u8(base, 0x418CBDu, X86_REG8L(ctx.eax));
	// 0x260B88: mov [0x00418CBE], al
	X86_MEM_WRITE_u8(base, 0x418CBEu, X86_REG8L(ctx.eax));
	// 0x260B8D: mov byte ptr [0x00418CBF], 0xA0
	X86_MEM_WRITE_u8(base, 0x418CBFu, -96);
	// 0x260B94: mov [0x00418CC0], al
	X86_MEM_WRITE_u8(base, 0x418CC0u, X86_REG8L(ctx.eax));
	// 0x260B99: mov [0x00418CC1], al
	X86_MEM_WRITE_u8(base, 0x418CC1u, X86_REG8L(ctx.eax));
	// 0x260B9E: mov [0x00418CC2], al
	X86_MEM_WRITE_u8(base, 0x418CC2u, X86_REG8L(ctx.eax));
	// 0x260BA3: mov [0x00418CC3], cl
	X86_MEM_WRITE_u8(base, 0x418CC3u, X86_REG8L(ctx.ecx));
	// 0x260BA9: mov [0x00418CC4], cl
	X86_MEM_WRITE_u8(base, 0x418CC4u, X86_REG8L(ctx.ecx));
	// 0x260BAF: movss xmm7, dword ptr [0x003A2D50]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x260BB7: movss [0x00418CCC], xmm7
	X86_MEM_WRITE_u32(base, 0x418CCCu, ctx.xmm[7].u32[0]);
	// 0x260BBF: movss xmm7, dword ptr [0x003A5A48]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x260BC7: movss [0x00418CD0], xmm7
	X86_MEM_WRITE_u32(base, 0x418CD0u, ctx.xmm[7].u32[0]);
	// 0x260BCF: movss xmm7, dword ptr [0x003A2928]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x260BD7: movss [0x00418D18], xmm6
	X86_MEM_WRITE_u32(base, 0x418D18u, ctx.xmm[6].u32[0]);
	// 0x260BDF: movss [0x00418D1C], xmm6
	X86_MEM_WRITE_u32(base, 0x418D1Cu, ctx.xmm[6].u32[0]);
	// 0x260BE7: movss xmm6, dword ptr [0x003B1870]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x260BEF: movss [0x00418CD8], xmm7
	X86_MEM_WRITE_u32(base, 0x418CD8u, ctx.xmm[7].u32[0]);
	// 0x260BF7: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x260BFF: movss [0x00418D30], xmm6
	X86_MEM_WRITE_u32(base, 0x418D30u, ctx.xmm[6].u32[0]);
	// 0x260C07: movss xmm6, dword ptr [0x003B1730]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x260C0F: movss [0x00418CDC], xmm7
	X86_MEM_WRITE_u32(base, 0x418CDCu, ctx.xmm[7].u32[0]);
	// 0x260C17: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x260C1F: movss [0x00418D34], xmm6
	X86_MEM_WRITE_u32(base, 0x418D34u, ctx.xmm[6].u32[0]);
	// 0x260C27: movss xmm6, dword ptr [0x003A5A48]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3A5A48u);
	// 0x260C2F: movss [0x00418CE0], xmm7
	X86_MEM_WRITE_u32(base, 0x418CE0u, ctx.xmm[7].u32[0]);
	// 0x260C37: movss xmm7, dword ptr [0x003A69C0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x260C3F: movss [0x00418D48], xmm6
	X86_MEM_WRITE_u32(base, 0x418D48u, ctx.xmm[6].u32[0]);
	// 0x260C47: movss [0x00418D50], xmm6
	X86_MEM_WRITE_u32(base, 0x418D50u, ctx.xmm[6].u32[0]);
	// 0x260C4F: movss xmm6, dword ptr [0x003B16D8]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B16D8u);
	// 0x260C57: movss [0x00418CE4], xmm7
	X86_MEM_WRITE_u32(base, 0x418CE4u, ctx.xmm[7].u32[0]);
	// 0x260C5F: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x260C67: movss [0x00418D58], xmm6
	X86_MEM_WRITE_u32(base, 0x418D58u, ctx.xmm[6].u32[0]);
	// 0x260C6F: movss xmm6, dword ptr [0x003B1750]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x260C77: movss [0x00418CF4], xmm7
	X86_MEM_WRITE_u32(base, 0x418CF4u, ctx.xmm[7].u32[0]);
	// 0x260C7F: movss xmm7, dword ptr [0x003B16B0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x260C87: movss [0x00418D5C], xmm6
	X86_MEM_WRITE_u32(base, 0x418D5Cu, ctx.xmm[6].u32[0]);
	// 0x260C8F: movss xmm6, dword ptr [0x003B16B8]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x260C97: movss [0x00418CF8], xmm7
	X86_MEM_WRITE_u32(base, 0x418CF8u, ctx.xmm[7].u32[0]);
	// 0x260C9F: movss xmm7, dword ptr [0x00388E90]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x260CA7: movss [0x00418D60], xmm6
	X86_MEM_WRITE_u32(base, 0x418D60u, ctx.xmm[6].u32[0]);
	// 0x260CAF: movss xmm6, dword ptr [0x003B1688]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x260CB7: movss [0x00418D0C], xmm7
	X86_MEM_WRITE_u32(base, 0x418D0Cu, ctx.xmm[7].u32[0]);
	// 0x260CBF: movss xmm7, dword ptr [0x003B1C6C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1C6Cu);
	// 0x260CC7: movss [0x00418D64], xmm6
	X86_MEM_WRITE_u32(base, 0x418D64u, ctx.xmm[6].u32[0]);
	// 0x260CCF: movss xmm6, dword ptr [0x003B1694]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x260CD7: mov ebx, 0xC8
	ctx.ebx = 200;
	// 0x260CDC: movss [0x00418CC8], xmm1
	X86_MEM_WRITE_u32(base, 0x418CC8u, ctx.xmm[1].u32[0]);
	// 0x260CE4: movss [0x00418CD4], xmm2
	X86_MEM_WRITE_u32(base, 0x418CD4u, ctx.xmm[2].u32[0]);
	// 0x260CEC: movss [0x00418CE8], xmm1
	X86_MEM_WRITE_u32(base, 0x418CE8u, ctx.xmm[1].u32[0]);
	// 0x260CF4: movss [0x00418CEC], xmm4
	X86_MEM_WRITE_u32(base, 0x418CECu, ctx.xmm[4].u32[0]);
	// 0x260CFC: movss [0x00418CF0], xmm3
	X86_MEM_WRITE_u32(base, 0x418CF0u, ctx.xmm[3].u32[0]);
	// 0x260D04: mov [0x00418CFC], dl
	X86_MEM_WRITE_u8(base, 0x418CFCu, X86_REG8L(ctx.edx));
	// 0x260D0A: mov [0x00418CFD], dl
	X86_MEM_WRITE_u8(base, 0x418CFDu, X86_REG8L(ctx.edx));
	// 0x260D10: mov [0x00418D00], ecx
	X86_MEM_WRITE_u32(base, 0x418D00u, ctx.ecx);
	// 0x260D16: mov [0x00418D04], ebp
	X86_MEM_WRITE_u32(base, 0x418D04u, ctx.ebp);
	// 0x260D1C: mov [0x00418D08], eax
	X86_MEM_WRITE_u32(base, 0x418D08u, ctx.eax);
	// 0x260D21: movss [0x00418D10], xmm5
	X86_MEM_WRITE_u32(base, 0x418D10u, ctx.xmm[5].u32[0]);
	// 0x260D29: movss [0x00418D14], xmm1
	X86_MEM_WRITE_u32(base, 0x418D14u, ctx.xmm[1].u32[0]);
	// 0x260D31: mov dword ptr [0x00418D20], 0x3AAF90
	X86_MEM_WRITE_u32(base, 0x418D20u, 3846032);
	// 0x260D3B: mov [0x00418D24], dl
	X86_MEM_WRITE_u8(base, 0x418D24u, X86_REG8L(ctx.edx));
	// 0x260D41: mov [0x00418D28], ecx
	X86_MEM_WRITE_u32(base, 0x418D28u, ctx.ecx);
	// 0x260D47: mov [0x00418D2C], ecx
	X86_MEM_WRITE_u32(base, 0x418D2Cu, ctx.ecx);
	// 0x260D4D: mov [0x00418D38], al
	X86_MEM_WRITE_u8(base, 0x418D38u, X86_REG8L(ctx.eax));
	// 0x260D52: mov [0x00418D39], al
	X86_MEM_WRITE_u8(base, 0x418D39u, X86_REG8L(ctx.eax));
	// 0x260D57: mov [0x00418D3A], al
	X86_MEM_WRITE_u8(base, 0x418D3Au, X86_REG8L(ctx.eax));
	// 0x260D5C: mov byte ptr [0x00418D3B], 0x80
	X86_MEM_WRITE_u8(base, 0x418D3Bu, -128);
	// 0x260D63: mov [0x00418D3C], al
	X86_MEM_WRITE_u8(base, 0x418D3Cu, X86_REG8L(ctx.eax));
	// 0x260D68: mov byte ptr [0x00418D3D], 0xF0
	X86_MEM_WRITE_u8(base, 0x418D3Du, -16);
	// 0x260D6F: mov byte ptr [0x00418D3E], 0x90
	X86_MEM_WRITE_u8(base, 0x418D3Eu, -112);
	// 0x260D76: mov [0x00418D3F], al
	X86_MEM_WRITE_u8(base, 0x418D3Fu, X86_REG8L(ctx.eax));
	// 0x260D7B: mov byte ptr [0x00418D40], 0x60
	X86_MEM_WRITE_u8(base, 0x418D40u, 96);
	// 0x260D82: mov byte ptr [0x00418D41], 0x10
	X86_MEM_WRITE_u8(base, 0x418D41u, 16);
	// 0x260D89: mov [0x00418D42], cl
	X86_MEM_WRITE_u8(base, 0x418D42u, X86_REG8L(ctx.ecx));
	// 0x260D8F: mov [0x00418D43], cl
	X86_MEM_WRITE_u8(base, 0x418D43u, X86_REG8L(ctx.ecx));
	// 0x260D95: mov [0x00418D44], dl
	X86_MEM_WRITE_u8(base, 0x418D44u, X86_REG8L(ctx.edx));
	// 0x260D9B: movss [0x00418D4C], xmm5
	X86_MEM_WRITE_u32(base, 0x418D4Cu, ctx.xmm[5].u32[0]);
	// 0x260DA3: movss [0x00418D54], xmm2
	X86_MEM_WRITE_u32(base, 0x418D54u, ctx.xmm[2].u32[0]);
	// 0x260DAB: movss [0x00418D68], xmm4
	X86_MEM_WRITE_u32(base, 0x418D68u, ctx.xmm[4].u32[0]);
	// 0x260DB3: movss [0x00418D6C], xmm4
	X86_MEM_WRITE_u32(base, 0x418D6Cu, ctx.xmm[4].u32[0]);
	// 0x260DBB: movss [0x00418D70], xmm3
	X86_MEM_WRITE_u32(base, 0x418D70u, ctx.xmm[3].u32[0]);
	// 0x260DC3: movss [0x00418D74], xmm6
	X86_MEM_WRITE_u32(base, 0x418D74u, ctx.xmm[6].u32[0]);
	// 0x260DCB: movss [0x00418D78], xmm0
	X86_MEM_WRITE_u32(base, 0x418D78u, ctx.xmm[0].u32[0]);
	// 0x260DD3: mov [0x00418D7C], dl
	X86_MEM_WRITE_u8(base, 0x418D7Cu, X86_REG8L(ctx.edx));
	// 0x260DD9: mov [0x00418D7D], dl
	X86_MEM_WRITE_u8(base, 0x418D7Du, X86_REG8L(ctx.edx));
	// 0x260DDF: mov [0x00418D80], ecx
	X86_MEM_WRITE_u32(base, 0x418D80u, ctx.ecx);
	// 0x260DE5: mov [0x00418D84], ebx
	X86_MEM_WRITE_u32(base, 0x418D84u, ctx.ebx);
	// 0x260DEB: mov [0x00418D88], eax
	X86_MEM_WRITE_u32(base, 0x418D88u, ctx.eax);
	// 0x260DF0: movss [0x00418D8C], xmm7
	X86_MEM_WRITE_u32(base, 0x418D8Cu, ctx.xmm[7].u32[0]);
	// 0x260DF8: movss [0x00418D90], xmm5
	X86_MEM_WRITE_u32(base, 0x418D90u, ctx.xmm[5].u32[0]);
	// 0x260E00: movss xmm7, dword ptr [0x003B1698]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x260E08: movss [0x00418DB0], xmm7
	X86_MEM_WRITE_u32(base, 0x418DB0u, ctx.xmm[7].u32[0]);
	// 0x260E10: movss xmm7, dword ptr [0x00387C04]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x387C04u);
	// 0x260E18: movss [0x00418DB4], xmm7
	X86_MEM_WRITE_u32(base, 0x418DB4u, ctx.xmm[7].u32[0]);
	// 0x260E20: movss xmm7, dword ptr [0x003B16E8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x260E28: movss [0x00418DCC], xmm7
	X86_MEM_WRITE_u32(base, 0x418DCCu, ctx.xmm[7].u32[0]);
	// 0x260E30: movss xmm7, dword ptr [0x003B16D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16D8u);
	// 0x260E38: movss [0x00418DD8], xmm7
	X86_MEM_WRITE_u32(base, 0x418DD8u, ctx.xmm[7].u32[0]);
	// 0x260E40: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x260E48: movss [0x00418DDC], xmm7
	X86_MEM_WRITE_u32(base, 0x418DDCu, ctx.xmm[7].u32[0]);
	// 0x260E50: movss xmm7, dword ptr [0x003B16B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x260E58: movss [0x00418E14], xmm1
	X86_MEM_WRITE_u32(base, 0x418E14u, ctx.xmm[1].u32[0]);
	// 0x260E60: movss xmm1, dword ptr [0x003A5A44]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A5A44u);
	// 0x260E68: movss [0x00418DE0], xmm7
	X86_MEM_WRITE_u32(base, 0x418DE0u, ctx.xmm[7].u32[0]);
	// 0x260E70: movss xmm7, dword ptr [0x003B1730]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x260E78: movss [0x00418DF0], xmm3
	X86_MEM_WRITE_u32(base, 0x418DF0u, ctx.xmm[3].u32[0]);
	// 0x260E80: movss xmm3, dword ptr [0x003B16F0]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x260E88: movss [0x00418E30], xmm1
	X86_MEM_WRITE_u32(base, 0x418E30u, ctx.xmm[1].u32[0]);
	// 0x260E90: movss xmm1, dword ptr [0x003B1698]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1698u);
	// 0x260E98: movss [0x00418DE8], xmm7
	X86_MEM_WRITE_u32(base, 0x418DE8u, ctx.xmm[7].u32[0]);
	// 0x260EA0: movss xmm7, dword ptr [0x003A49FC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A49FCu);
	// 0x260EA8: movss [0x00418DF4], xmm3
	X86_MEM_WRITE_u32(base, 0x418DF4u, ctx.xmm[3].u32[0]);
	// 0x260EB0: movss xmm3, dword ptr [0x003B16B0]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B16B0u);
	// 0x260EB8: movss [0x00418E4C], xmm1
	X86_MEM_WRITE_u32(base, 0x418E4Cu, ctx.xmm[1].u32[0]);
	// 0x260EC0: movss xmm1, dword ptr [0x003A2928]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A2928u);
	// 0x260EC8: movss [0x00418D94], xmm6
	X86_MEM_WRITE_u32(base, 0x418D94u, ctx.xmm[6].u32[0]);
	// 0x260ED0: movss [0x00418D98], xmm0
	X86_MEM_WRITE_u32(base, 0x418D98u, ctx.xmm[0].u32[0]);
	// 0x260ED8: movss [0x00418D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x418D9Cu, ctx.xmm[0].u32[0]);
	// 0x260EE0: mov [0x00418DA0], edi
	X86_MEM_WRITE_u32(base, 0x418DA0u, ctx.edi);
	// 0x260EE6: mov [0x00418DA4], dl
	X86_MEM_WRITE_u8(base, 0x418DA4u, X86_REG8L(ctx.edx));
	// 0x260EEC: mov [0x00418DA8], esi
	X86_MEM_WRITE_u32(base, 0x418DA8u, ctx.esi);
	// 0x260EF2: mov [0x00418DAC], ecx
	X86_MEM_WRITE_u32(base, 0x418DACu, ctx.ecx);
	// 0x260EF8: mov [0x00418DB8], al
	X86_MEM_WRITE_u8(base, 0x418DB8u, X86_REG8L(ctx.eax));
	// 0x260EFD: mov byte ptr [0x00418DB9], 0xB0
	X86_MEM_WRITE_u8(base, 0x418DB9u, -80);
	// 0x260F04: mov byte ptr [0x00418DBA], 0x70
	X86_MEM_WRITE_u8(base, 0x418DBAu, 112);
	// 0x260F0B: mov [0x00418DBB], al
	X86_MEM_WRITE_u8(base, 0x418DBBu, X86_REG8L(ctx.eax));
	// 0x260F10: mov byte ptr [0x00418DBC], 0x40
	X86_MEM_WRITE_u8(base, 0x418DBCu, 64);
	// 0x260F17: mov byte ptr [0x00418DBD], 0x30
	X86_MEM_WRITE_u8(base, 0x418DBDu, 48);
	// 0x260F1E: mov byte ptr [0x00418DBE], 0x20
	X86_MEM_WRITE_u8(base, 0x418DBEu, 32);
	// 0x260F25: mov byte ptr [0x00418DBF], 0x80
	X86_MEM_WRITE_u8(base, 0x418DBFu, -128);
	// 0x260F2C: mov byte ptr [0x00418DC0], 0x60
	X86_MEM_WRITE_u8(base, 0x418DC0u, 96);
	// 0x260F33: mov byte ptr [0x00418DC1], 0x60
	X86_MEM_WRITE_u8(base, 0x418DC1u, 96);
	// 0x260F3A: mov byte ptr [0x00418DC2], 0x60
	X86_MEM_WRITE_u8(base, 0x418DC2u, 96);
	// 0x260F41: mov [0x00418DC3], cl
	X86_MEM_WRITE_u8(base, 0x418DC3u, X86_REG8L(ctx.ecx));
	// 0x260F47: mov [0x00418DC4], dl
	X86_MEM_WRITE_u8(base, 0x418DC4u, X86_REG8L(ctx.edx));
	// 0x260F4D: movss [0x00418DC8], xmm5
	X86_MEM_WRITE_u32(base, 0x418DC8u, ctx.xmm[5].u32[0]);
	// 0x260F55: movss [0x00418DD0], xmm5
	X86_MEM_WRITE_u32(base, 0x418DD0u, ctx.xmm[5].u32[0]);
	// 0x260F5D: movss [0x00418DD4], xmm2
	X86_MEM_WRITE_u32(base, 0x418DD4u, ctx.xmm[2].u32[0]);
	// 0x260F65: movss [0x00418DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x418DE4u, ctx.xmm[0].u32[0]);
	// 0x260F6D: movss [0x00418DEC], xmm4
	X86_MEM_WRITE_u32(base, 0x418DECu, ctx.xmm[4].u32[0]);
	// 0x260F75: movss [0x00418DF8], xmm3
	X86_MEM_WRITE_u32(base, 0x418DF8u, ctx.xmm[3].u32[0]);
	// 0x260F7D: mov [0x00418DFC], dl
	X86_MEM_WRITE_u8(base, 0x418DFCu, X86_REG8L(ctx.edx));
	// 0x260F83: mov [0x00418DFD], dl
	X86_MEM_WRITE_u8(base, 0x418DFDu, X86_REG8L(ctx.edx));
	// 0x260F89: mov [0x00418E00], ecx
	X86_MEM_WRITE_u32(base, 0x418E00u, ctx.ecx);
	// 0x260F8F: mov [0x00418E04], ebx
	X86_MEM_WRITE_u32(base, 0x418E04u, ctx.ebx);
	// 0x260F95: mov [0x00418E08], eax
	X86_MEM_WRITE_u32(base, 0x418E08u, ctx.eax);
	// 0x260F9A: movss [0x00418E0C], xmm7
	X86_MEM_WRITE_u32(base, 0x418E0Cu, ctx.xmm[7].u32[0]);
	// 0x260FA2: movss [0x00418E10], xmm5
	X86_MEM_WRITE_u32(base, 0x418E10u, ctx.xmm[5].u32[0]);
	// 0x260FAA: movss [0x00418E18], xmm0
	X86_MEM_WRITE_u32(base, 0x418E18u, ctx.xmm[0].u32[0]);
	// 0x260FB2: movss [0x00418E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x418E1Cu, ctx.xmm[0].u32[0]);
	// 0x260FBA: mov dword ptr [0x00418E20], 0x3AAFA0
	X86_MEM_WRITE_u32(base, 0x418E20u, 3846048);
	// 0x260FC4: mov [0x00418E24], cl
	X86_MEM_WRITE_u8(base, 0x418E24u, X86_REG8L(ctx.ecx));
	// 0x260FCA: mov [0x00418E28], ecx
	X86_MEM_WRITE_u32(base, 0x418E28u, ctx.ecx);
	// 0x260FD0: mov [0x00418E2C], esi
	X86_MEM_WRITE_u32(base, 0x418E2Cu, ctx.esi);
	// 0x260FD6: movss [0x00418E34], xmm2
	X86_MEM_WRITE_u32(base, 0x418E34u, ctx.xmm[2].u32[0]);
	// 0x260FDE: mov [0x00418E38], al
	X86_MEM_WRITE_u8(base, 0x418E38u, X86_REG8L(ctx.eax));
	// 0x260FE3: mov [0x00418E39], al
	X86_MEM_WRITE_u8(base, 0x418E39u, X86_REG8L(ctx.eax));
	// 0x260FE8: mov [0x00418E3A], al
	X86_MEM_WRITE_u8(base, 0x418E3Au, X86_REG8L(ctx.eax));
	// 0x260FED: mov [0x00418E3B], al
	X86_MEM_WRITE_u8(base, 0x418E3Bu, X86_REG8L(ctx.eax));
	// 0x260FF2: mov [0x00418E3C], al
	X86_MEM_WRITE_u8(base, 0x418E3Cu, X86_REG8L(ctx.eax));
	// 0x260FF7: mov [0x00418E3D], al
	X86_MEM_WRITE_u8(base, 0x418E3Du, X86_REG8L(ctx.eax));
	// 0x260FFC: mov [0x00418E3E], al
	X86_MEM_WRITE_u8(base, 0x418E3Eu, X86_REG8L(ctx.eax));
	// 0x261001: mov byte ptr [0x00418E3F], 0x40
	X86_MEM_WRITE_u8(base, 0x418E3Fu, 64);
	// 0x261008: mov [0x00418E40], al
	X86_MEM_WRITE_u8(base, 0x418E40u, X86_REG8L(ctx.eax));
	// 0x26100D: mov [0x00418E41], al
	X86_MEM_WRITE_u8(base, 0x418E41u, X86_REG8L(ctx.eax));
	// 0x261012: mov byte ptr [0x00418E42], 0x80
	X86_MEM_WRITE_u8(base, 0x418E42u, -128);
	// 0x261019: mov [0x00418E43], cl
	X86_MEM_WRITE_u8(base, 0x418E43u, X86_REG8L(ctx.ecx));
	// 0x26101F: mov [0x00418E44], cl
	X86_MEM_WRITE_u8(base, 0x418E44u, X86_REG8L(ctx.ecx));
	// 0x261025: movss [0x00418E48], xmm3
	X86_MEM_WRITE_u32(base, 0x418E48u, ctx.xmm[3].u32[0]);
	// 0x26102D: movss [0x00418E50], xmm0
	X86_MEM_WRITE_u32(base, 0x418E50u, ctx.xmm[0].u32[0]);
	// 0x261035: movss [0x00418E54], xmm2
	X86_MEM_WRITE_u32(base, 0x418E54u, ctx.xmm[2].u32[0]);
	// 0x26103D: movss [0x00418E58], xmm1
	X86_MEM_WRITE_u32(base, 0x418E58u, ctx.xmm[1].u32[0]);
	// 0x261045: movss xmm1, dword ptr [0x003B1750]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x26104D: movss [0x00418E5C], xmm1
	X86_MEM_WRITE_u32(base, 0x418E5Cu, ctx.xmm[1].u32[0]);
	// 0x261055: movss xmm1, dword ptr [0x003B16B8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x26105D: movss [0x00418E60], xmm1
	X86_MEM_WRITE_u32(base, 0x418E60u, ctx.xmm[1].u32[0]);
	// 0x261065: movss xmm1, dword ptr [0x003B1870]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1870u);
	// 0x26106D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x26106E: movss [0x00418E64], xmm1
	X86_MEM_WRITE_u32(base, 0x418E64u, ctx.xmm[1].u32[0]);
	// 0x261076: movss xmm1, dword ptr [0x003B17AC]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B17ACu);
	// 0x26107E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x26107F: movss [0x00418E70], xmm1
	X86_MEM_WRITE_u32(base, 0x418E70u, ctx.xmm[1].u32[0]);
	// 0x261087: movss [0x00418E74], xmm1
	X86_MEM_WRITE_u32(base, 0x418E74u, ctx.xmm[1].u32[0]);
	// 0x26108F: movss xmm1, dword ptr [0x003B1904]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B1904u);
	// 0x261097: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x261098: movss [0x00418E68], xmm4
	X86_MEM_WRITE_u32(base, 0x418E68u, ctx.xmm[4].u32[0]);
	// 0x2610A0: movss [0x00418E6C], xmm4
	X86_MEM_WRITE_u32(base, 0x418E6Cu, ctx.xmm[4].u32[0]);
	// 0x2610A8: movss [0x00418E78], xmm0
	X86_MEM_WRITE_u32(base, 0x418E78u, ctx.xmm[0].u32[0]);
	// 0x2610B0: mov [0x00418E7C], dl
	X86_MEM_WRITE_u8(base, 0x418E7Cu, X86_REG8L(ctx.edx));
	// 0x2610B6: mov [0x00418E7D], dl
	X86_MEM_WRITE_u8(base, 0x418E7Du, X86_REG8L(ctx.edx));
	// 0x2610BC: mov [0x00418E80], ecx
	X86_MEM_WRITE_u32(base, 0x418E80u, ctx.ecx);
	// 0x2610C2: mov dword ptr [0x00418E84], 0x32
	X86_MEM_WRITE_u32(base, 0x418E84u, 50);
	// 0x2610CC: mov [0x00418E88], eax
	X86_MEM_WRITE_u32(base, 0x418E88u, ctx.eax);
	// 0x2610D1: movss [0x00418E8C], xmm1
	X86_MEM_WRITE_u32(base, 0x418E8Cu, ctx.xmm[1].u32[0]);
	// 0x2610D9: movss [0x00418E90], xmm5
	X86_MEM_WRITE_u32(base, 0x418E90u, ctx.xmm[5].u32[0]);
	// 0x2610E1: movss [0x00418E94], xmm6
	X86_MEM_WRITE_u32(base, 0x418E94u, ctx.xmm[6].u32[0]);
	// 0x2610E9: movss [0x00418E98], xmm0
	X86_MEM_WRITE_u32(base, 0x418E98u, ctx.xmm[0].u32[0]);
	// 0x2610F1: movss [0x00418E9C], xmm0
	X86_MEM_WRITE_u32(base, 0x418E9Cu, ctx.xmm[0].u32[0]);
	// 0x2610F9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2610FA: ret
	return;
}

void sub_261100(X86Context& ctx, uint8_t* base) {
	// 0x261100: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x261108: movss [0x00549234], xmm0
	X86_MEM_WRITE_u32(base, 0x549234u, ctx.xmm[0].u32[0]);
	// 0x261110: ret
	return;
}

void sub_261120(X86Context& ctx, uint8_t* base) {
	// 0x261120: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x261128: movss [0x00549240], xmm0
	X86_MEM_WRITE_u32(base, 0x549240u, ctx.xmm[0].u32[0]);
	// 0x261130: ret
	return;
}

void sub_261140(X86Context& ctx, uint8_t* base) {
	// 0x261140: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x261148: movss [0x00549230], xmm0
	X86_MEM_WRITE_u32(base, 0x549230u, ctx.xmm[0].u32[0]);
	// 0x261150: ret
	return;
}

void sub_261160(X86Context& ctx, uint8_t* base) {
	// 0x261160: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x261168: movss [0x004D9414], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9414u, ctx.xmm[0].u32[0]);
	// 0x261170: ret
	return;
}

void sub_261180(X86Context& ctx, uint8_t* base) {
	// 0x261180: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x261188: movss [0x00549238], xmm0
	X86_MEM_WRITE_u32(base, 0x549238u, ctx.xmm[0].u32[0]);
	// 0x261190: ret
	return;
}

void sub_2611A0(X86Context& ctx, uint8_t* base) {
	// 0x2611A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2611A8: movss [0x004D941C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D941Cu, ctx.xmm[0].u32[0]);
	// 0x2611B0: ret
	return;
}

void sub_2611C0(X86Context& ctx, uint8_t* base) {
	// 0x2611C0: movss xmm0, dword ptr [0x00549238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549238u);
	// 0x2611C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2611D0: movss [0x0054924C], xmm0
	X86_MEM_WRITE_u32(base, 0x54924Cu, ctx.xmm[0].u32[0]);
	// 0x2611D8: ret
	return;
}

void sub_2611E0(X86Context& ctx, uint8_t* base) {
	// 0x2611E0: movss xmm0, dword ptr [0x004D941C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D941Cu);
	// 0x2611E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2611F0: movss [0x00549244], xmm0
	X86_MEM_WRITE_u32(base, 0x549244u, ctx.xmm[0].u32[0]);
	// 0x2611F8: ret
	return;
}

void sub_261200(X86Context& ctx, uint8_t* base) {
	// 0x261200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x261208: movss [0x0054925C], xmm0
	X86_MEM_WRITE_u32(base, 0x54925Cu, ctx.xmm[0].u32[0]);
	// 0x261210: ret
	return;
}

void sub_261220(X86Context& ctx, uint8_t* base) {
	// 0x261220: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x261228: movss [0x00549250], xmm0
	X86_MEM_WRITE_u32(base, 0x549250u, ctx.xmm[0].u32[0]);
	// 0x261230: ret
	return;
}

void sub_261240(X86Context& ctx, uint8_t* base) {
	// 0x261240: movss xmm0, dword ptr [0x00549250]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549250u);
	// 0x261248: movss [0x00549258], xmm0
	X86_MEM_WRITE_u32(base, 0x549258u, ctx.xmm[0].u32[0]);
	// 0x261250: ret
	return;
}

void sub_261260(X86Context& ctx, uint8_t* base) {
	// 0x261260: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x261268: movss [0x004D9418], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9418u, ctx.xmm[0].u32[0]);
	// 0x261270: ret
	return;
}

void sub_261280(X86Context& ctx, uint8_t* base) {
	// 0x261280: movss xmm0, dword ptr [0x004D941C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D941Cu);
	// 0x261288: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x261290: movss [0x00549254], xmm0
	X86_MEM_WRITE_u32(base, 0x549254u, ctx.xmm[0].u32[0]);
	// 0x261298: ret
	return;
}

void sub_2612A0(X86Context& ctx, uint8_t* base) {
	// 0x2612A0: movss xmm0, dword ptr [0x004D941C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D941Cu);
	// 0x2612A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2612B0: movss [0x004D942C], xmm0
	X86_MEM_WRITE_u32(base, 0x4D942Cu, ctx.xmm[0].u32[0]);
	// 0x2612B8: ret
	return;
}

void sub_2612C0(X86Context& ctx, uint8_t* base) {
	// 0x2612C0: movss xmm0, dword ptr [0x004D941C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4D941Cu);
	// 0x2612C8: subss xmm0, [0x004D942C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x4D942Cu);
	// 0x2612D0: movss [0x004D9424], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9424u, ctx.xmm[0].u32[0]);
	// 0x2612D8: ret
	return;
}

void sub_2612E0(X86Context& ctx, uint8_t* base) {
	// 0x2612E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2612E8: movss [0x0054923C], xmm0
	X86_MEM_WRITE_u32(base, 0x54923Cu, ctx.xmm[0].u32[0]);
	// 0x2612F0: ret
	return;
}

void sub_261300(X86Context& ctx, uint8_t* base) {
	// 0x261300: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x261308: movss [0x004D9420], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9420u, ctx.xmm[0].u32[0]);
	// 0x261310: ret
	return;
}

void sub_261320(X86Context& ctx, uint8_t* base) {
	// 0x261320: movss xmm0, dword ptr [0x003B2158]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2158u);
	// 0x261328: movss [0x004D9428], xmm0
	X86_MEM_WRITE_u32(base, 0x4D9428u, ctx.xmm[0].u32[0]);
	// 0x261330: ret
	return;
}

void sub_261340(X86Context& ctx, uint8_t* base) {
	// 0x261340: movss xmm0, dword ptr [0x003B2158]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2158u);
	// 0x261348: movss [0x00549248], xmm0
	X86_MEM_WRITE_u32(base, 0x549248u, ctx.xmm[0].u32[0]);
	// 0x261350: ret
	return;
}

void sub_261360(X86Context& ctx, uint8_t* base) {
	// 0x261360: movss xmm2, dword ptr [0x0039922C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x39922Cu);
	// 0x261368: movss xmm7, dword ptr [0x003B1728]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1728u);
	// 0x261370: movss xmm3, dword ptr [0x003B2188]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B2188u);
	// 0x261378: movss xmm0, dword ptr [0x003B1684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x261380: xorps xmm1, xmm1
	memset(&ctx.xmm[1], 0, sizeof(ctx.xmm[1]));
	// 0x261383: movss xmm5, dword ptr [0x003B17AC]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B17ACu);
	// 0x26138B: movss xmm6, dword ptr [0x00386DC0]
	ctx.xmm[6].u32[0] = X86_MEM_READ_u32(base, 0x386DC0u);
	// 0x261393: movss xmm4, dword ptr [0x003A69C0]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x3A69C0u);
	// 0x26139B: movss [0x00418F18], xmm2
	X86_MEM_WRITE_u32(base, 0x418F18u, ctx.xmm[2].u32[0]);
	// 0x2613A3: movss xmm2, dword ptr [0x003B2184]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2184u);
	// 0x2613AB: movss [0x00418F20], xmm2
	X86_MEM_WRITE_u32(base, 0x418F20u, ctx.xmm[2].u32[0]);
	// 0x2613B3: movss xmm2, dword ptr [0x003B2180]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B2180u);
	// 0x2613BB: movss [0x00418F24], xmm2
	X86_MEM_WRITE_u32(base, 0x418F24u, ctx.xmm[2].u32[0]);
	// 0x2613C3: movss xmm2, dword ptr [0x003B217C]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B217Cu);
	// 0x2613CB: movss [0x00418F74], xmm7
	X86_MEM_WRITE_u32(base, 0x418F74u, ctx.xmm[7].u32[0]);
	// 0x2613D3: movss xmm7, dword ptr [0x00386DC8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x386DC8u);
	// 0x2613DB: movss [0x00418F30], xmm2
	X86_MEM_WRITE_u32(base, 0x418F30u, ctx.xmm[2].u32[0]);
	// 0x2613E3: movss xmm2, dword ptr [0x003A69C4]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3A69C4u);
	// 0x2613EB: movss [0x00418F40], xmm3
	X86_MEM_WRITE_u32(base, 0x418F40u, ctx.xmm[3].u32[0]);
	// 0x2613F3: movss xmm3, dword ptr [0x003A69BC]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A69BCu);
	// 0x2613FB: movss [0x00418F78], xmm7
	X86_MEM_WRITE_u32(base, 0x418F78u, ctx.xmm[7].u32[0]);
	// 0x261403: movss xmm7, dword ptr [0x0039922C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39922Cu);
	// 0x26140B: movss [0x00418EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x418EF4u, ctx.xmm[0].u32[0]);
	// 0x261413: movss xmm0, dword ptr [0x00388054]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388054u);
	// 0x26141B: movss [0x00418F34], xmm2
	X86_MEM_WRITE_u32(base, 0x418F34u, ctx.xmm[2].u32[0]);
	// 0x261423: movss xmm2, dword ptr [0x003A5600]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x26142B: movss [0x00418F44], xmm3
	X86_MEM_WRITE_u32(base, 0x418F44u, ctx.xmm[3].u32[0]);
	// 0x261433: movss xmm3, dword ptr [0x003B2178]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B2178u);
	// 0x26143B: movss [0x00418F94], xmm7
	X86_MEM_WRITE_u32(base, 0x418F94u, ctx.xmm[7].u32[0]);
	// 0x261443: movss xmm7, dword ptr [0x0039D064]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39D064u);
	// 0x26144B: movss [0x00418EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x418EF8u, ctx.xmm[0].u32[0]);
	// 0x261453: movss xmm0, dword ptr [0x00386DC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x386DC8u);
	// 0x26145B: movss [0x00418F3C], xmm2
	X86_MEM_WRITE_u32(base, 0x418F3Cu, ctx.xmm[2].u32[0]);
	// 0x261463: movss [0x00418F4C], xmm2
	X86_MEM_WRITE_u32(base, 0x418F4Cu, ctx.xmm[2].u32[0]);
	// 0x26146B: movss xmm2, dword ptr [0x003B1750]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x261473: movss [0x00418F54], xmm3
	X86_MEM_WRITE_u32(base, 0x418F54u, ctx.xmm[3].u32[0]);
	// 0x26147B: movss xmm3, dword ptr [0x003B16EC]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x261483: movss [0x00418F9C], xmm7
	X86_MEM_WRITE_u32(base, 0x418F9Cu, ctx.xmm[7].u32[0]);
	// 0x26148B: movss xmm7, dword ptr [0x003B2174]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2174u);
	// 0x261493: mov eax, 0x3AAFC0
	ctx.eax = 3846080;
	// 0x261498: movss [0x00418EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x418EFCu, ctx.xmm[0].u32[0]);
	// 0x2614A0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2614A8: movss [0x00418F50], xmm2
	X86_MEM_WRITE_u32(base, 0x418F50u, ctx.xmm[2].u32[0]);
	// 0x2614B0: movss [0x00418F5C], xmm3
	X86_MEM_WRITE_u32(base, 0x418F5Cu, ctx.xmm[3].u32[0]);
	// 0x2614B8: movss xmm3, dword ptr [0x003A69B4]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3A69B4u);
	// 0x2614C0: movss [0x00418F60], xmm2
	X86_MEM_WRITE_u32(base, 0x418F60u, ctx.xmm[2].u32[0]);
	// 0x2614C8: movss xmm2, dword ptr [0x003B16E8]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2614D0: mov edx, 0x50
	ctx.edx = 80;
	// 0x2614D5: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2614D7: movss [0x00418FAC], xmm7
	X86_MEM_WRITE_u32(base, 0x418FACu, ctx.xmm[7].u32[0]);
	// 0x2614DF: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x2614E7: movss [0x00418EF0], xmm6
	X86_MEM_WRITE_u32(base, 0x418EF0u, ctx.xmm[6].u32[0]);
	// 0x2614EF: mov dword ptr [0x00418F00], 0x258
	X86_MEM_WRITE_u32(base, 0x418F00u, 600);
	// 0x2614F9: mov dword ptr [0x00418F04], 0xBB8
	X86_MEM_WRITE_u32(base, 0x418F04u, 3000);
	// 0x261503: mov [0x00418F08], eax
	X86_MEM_WRITE_u32(base, 0x418F08u, ctx.eax);
	// 0x261508: movss [0x00418F0C], xmm1
	X86_MEM_WRITE_u32(base, 0x418F0Cu, ctx.xmm[1].u32[0]);
	// 0x261510: movss [0x00418F10], xmm1
	X86_MEM_WRITE_u32(base, 0x418F10u, ctx.xmm[1].u32[0]);
	// 0x261518: movss [0x00418F14], xmm0
	X86_MEM_WRITE_u32(base, 0x418F14u, ctx.xmm[0].u32[0]);
	// 0x261520: movss [0x00418F1C], xmm0
	X86_MEM_WRITE_u32(base, 0x418F1Cu, ctx.xmm[0].u32[0]);
	// 0x261528: movss [0x00418F28], xmm0
	X86_MEM_WRITE_u32(base, 0x418F28u, ctx.xmm[0].u32[0]);
	// 0x261530: movss [0x00418F2C], xmm5
	X86_MEM_WRITE_u32(base, 0x418F2Cu, ctx.xmm[5].u32[0]);
	// 0x261538: movss [0x00418F38], xmm5
	X86_MEM_WRITE_u32(base, 0x418F38u, ctx.xmm[5].u32[0]);
	// 0x261540: movss [0x00418F48], xmm0
	X86_MEM_WRITE_u32(base, 0x418F48u, ctx.xmm[0].u32[0]);
	// 0x261548: movss [0x00418F58], xmm0
	X86_MEM_WRITE_u32(base, 0x418F58u, ctx.xmm[0].u32[0]);
	// 0x261550: movss [0x00418F64], xmm2
	X86_MEM_WRITE_u32(base, 0x418F64u, ctx.xmm[2].u32[0]);
	// 0x261558: movss [0x00418F68], xmm3
	X86_MEM_WRITE_u32(base, 0x418F68u, ctx.xmm[3].u32[0]);
	// 0x261560: movss [0x00418F6C], xmm6
	X86_MEM_WRITE_u32(base, 0x418F6Cu, ctx.xmm[6].u32[0]);
	// 0x261568: movss [0x00418F70], xmm4
	X86_MEM_WRITE_u32(base, 0x418F70u, ctx.xmm[4].u32[0]);
	// 0x261570: mov [0x00418F7C], edx
	X86_MEM_WRITE_u32(base, 0x418F7Cu, ctx.edx);
	// 0x261576: mov [0x00418F80], ecx
	X86_MEM_WRITE_u32(base, 0x418F80u, ctx.ecx);
	// 0x26157C: mov [0x00418F84], eax
	X86_MEM_WRITE_u32(base, 0x418F84u, ctx.eax);
	// 0x261581: movss [0x00418F88], xmm1
	X86_MEM_WRITE_u32(base, 0x418F88u, ctx.xmm[1].u32[0]);
	// 0x261589: movss [0x00418F8C], xmm1
	X86_MEM_WRITE_u32(base, 0x418F8Cu, ctx.xmm[1].u32[0]);
	// 0x261591: movss [0x00418F90], xmm0
	X86_MEM_WRITE_u32(base, 0x418F90u, ctx.xmm[0].u32[0]);
	// 0x261599: movss [0x00418F98], xmm0
	X86_MEM_WRITE_u32(base, 0x418F98u, ctx.xmm[0].u32[0]);
	// 0x2615A1: movss [0x00418FA0], xmm1
	X86_MEM_WRITE_u32(base, 0x418FA0u, ctx.xmm[1].u32[0]);
	// 0x2615A9: movss [0x00418FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x418FA4u, ctx.xmm[0].u32[0]);
	// 0x2615B1: movss [0x00418FA8], xmm5
	X86_MEM_WRITE_u32(base, 0x418FA8u, ctx.xmm[5].u32[0]);
	// 0x2615B9: movss [0x00418FB0], xmm1
	X86_MEM_WRITE_u32(base, 0x418FB0u, ctx.xmm[1].u32[0]);
	// 0x2615C1: movss [0x00418FB4], xmm5
	X86_MEM_WRITE_u32(base, 0x418FB4u, ctx.xmm[5].u32[0]);
	// 0x2615C9: movss [0x00418FB8], xmm7
	X86_MEM_WRITE_u32(base, 0x418FB8u, ctx.xmm[7].u32[0]);
	// 0x2615D1: movss xmm7, dword ptr [0x003B2170]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2170u);
	// 0x2615D9: movss [0x00418FBC], xmm7
	X86_MEM_WRITE_u32(base, 0x418FBCu, ctx.xmm[7].u32[0]);
	// 0x2615E1: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x2615E9: movss [0x00418FC8], xmm7
	X86_MEM_WRITE_u32(base, 0x418FC8u, ctx.xmm[7].u32[0]);
	// 0x2615F1: movss xmm7, dword ptr [0x003B17D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17D8u);
	// 0x2615F9: movss [0x00418FCC], xmm7
	X86_MEM_WRITE_u32(base, 0x418FCCu, ctx.xmm[7].u32[0]);
	// 0x261601: movss xmm7, dword ptr [0x003B16EC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x261609: movss [0x00418FD8], xmm7
	X86_MEM_WRITE_u32(base, 0x418FD8u, ctx.xmm[7].u32[0]);
	// 0x261611: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x261619: movss [0x00418FDC], xmm7
	X86_MEM_WRITE_u32(base, 0x418FDCu, ctx.xmm[7].u32[0]);
	// 0x261621: movss xmm7, dword ptr [0x003B1728]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1728u);
	// 0x261629: movss [0x00418FF0], xmm7
	X86_MEM_WRITE_u32(base, 0x418FF0u, ctx.xmm[7].u32[0]);
	// 0x261631: movss xmm7, dword ptr [0x00386DC8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x386DC8u);
	// 0x261639: movss [0x00418FF4], xmm7
	X86_MEM_WRITE_u32(base, 0x418FF4u, ctx.xmm[7].u32[0]);
	// 0x261641: movss xmm7, dword ptr [0x0039922C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39922Cu);
	// 0x261649: movss [0x00419010], xmm7
	X86_MEM_WRITE_u32(base, 0x419010u, ctx.xmm[7].u32[0]);
	// 0x261651: movss xmm7, dword ptr [0x003B1B28]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1B28u);
	// 0x261659: movss [0x0041901C], xmm7
	X86_MEM_WRITE_u32(base, 0x41901Cu, ctx.xmm[7].u32[0]);
	// 0x261661: movss xmm7, dword ptr [0x003B216C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B216Cu);
	// 0x261669: movss [0x00419024], xmm7
	X86_MEM_WRITE_u32(base, 0x419024u, ctx.xmm[7].u32[0]);
	// 0x261671: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x261679: movss [0x00419028], xmm7
	X86_MEM_WRITE_u32(base, 0x419028u, ctx.xmm[7].u32[0]);
	// 0x261681: movss xmm7, dword ptr [0x003B2168]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2168u);
	// 0x261689: movss [0x00419034], xmm7
	X86_MEM_WRITE_u32(base, 0x419034u, ctx.xmm[7].u32[0]);
	// 0x261691: movss xmm7, dword ptr [0x003B17D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17D8u);
	// 0x261699: movss [0x00419038], xmm7
	X86_MEM_WRITE_u32(base, 0x419038u, ctx.xmm[7].u32[0]);
	// 0x2616A1: movss xmm7, dword ptr [0x003A69C4]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69C4u);
	// 0x2616A9: movss [0x0041903C], xmm7
	X86_MEM_WRITE_u32(base, 0x41903Cu, ctx.xmm[7].u32[0]);
	// 0x2616B1: movss xmm7, dword ptr [0x003B2168]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2168u);
	// 0x2616B9: movss [0x00419044], xmm7
	X86_MEM_WRITE_u32(base, 0x419044u, ctx.xmm[7].u32[0]);
	// 0x2616C1: movss xmm7, dword ptr [0x003B2164]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2164u);
	// 0x2616C9: movss [0x0041904C], xmm7
	X86_MEM_WRITE_u32(base, 0x41904Cu, ctx.xmm[7].u32[0]);
	// 0x2616D1: movss xmm7, dword ptr [0x003B16EC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2616D9: movss [0x00419054], xmm7
	X86_MEM_WRITE_u32(base, 0x419054u, ctx.xmm[7].u32[0]);
	// 0x2616E1: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2616E9: movss [0x00419058], xmm7
	X86_MEM_WRITE_u32(base, 0x419058u, ctx.xmm[7].u32[0]);
	// 0x2616F1: movss xmm7, dword ptr [0x003B1728]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1728u);
	// 0x2616F9: movss [0x0041906C], xmm7
	X86_MEM_WRITE_u32(base, 0x41906Cu, ctx.xmm[7].u32[0]);
	// 0x261701: movss xmm7, dword ptr [0x00386DC8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x386DC8u);
	// 0x261709: movss [0x00419070], xmm7
	X86_MEM_WRITE_u32(base, 0x419070u, ctx.xmm[7].u32[0]);
	// 0x261711: movss xmm7, dword ptr [0x0039922C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39922Cu);
	// 0x261719: movss [0x0041908C], xmm7
	X86_MEM_WRITE_u32(base, 0x41908Cu, ctx.xmm[7].u32[0]);
	// 0x261721: movss xmm7, dword ptr [0x003A5A58]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5A58u);
	// 0x261729: movss [0x00419098], xmm7
	X86_MEM_WRITE_u32(base, 0x419098u, ctx.xmm[7].u32[0]);
	// 0x261731: movss xmm7, dword ptr [0x003B1B88]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1B88u);
	// 0x261739: movss [0x00418FC0], xmm1
	X86_MEM_WRITE_u32(base, 0x418FC0u, ctx.xmm[1].u32[0]);
	// 0x261741: movss [0x00418FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x418FC4u, ctx.xmm[0].u32[0]);
	// 0x261749: movss [0x00418FD0], xmm1
	X86_MEM_WRITE_u32(base, 0x418FD0u, ctx.xmm[1].u32[0]);
	// 0x261751: movss [0x00418FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x418FD4u, ctx.xmm[0].u32[0]);
	// 0x261759: movss [0x00418FE0], xmm2
	X86_MEM_WRITE_u32(base, 0x418FE0u, ctx.xmm[2].u32[0]);
	// 0x261761: movss [0x00418FE4], xmm3
	X86_MEM_WRITE_u32(base, 0x418FE4u, ctx.xmm[3].u32[0]);
	// 0x261769: movss [0x00418FE8], xmm6
	X86_MEM_WRITE_u32(base, 0x418FE8u, ctx.xmm[6].u32[0]);
	// 0x261771: movss [0x00418FEC], xmm4
	X86_MEM_WRITE_u32(base, 0x418FECu, ctx.xmm[4].u32[0]);
	// 0x261779: mov [0x00418FF8], edx
	X86_MEM_WRITE_u32(base, 0x418FF8u, ctx.edx);
	// 0x26177F: mov [0x00418FFC], ecx
	X86_MEM_WRITE_u32(base, 0x418FFCu, ctx.ecx);
	// 0x261785: mov [0x00419000], eax
	X86_MEM_WRITE_u32(base, 0x419000u, ctx.eax);
	// 0x26178A: movss [0x00419004], xmm1
	X86_MEM_WRITE_u32(base, 0x419004u, ctx.xmm[1].u32[0]);
	// 0x261792: movss [0x00419008], xmm1
	X86_MEM_WRITE_u32(base, 0x419008u, ctx.xmm[1].u32[0]);
	// 0x26179A: movss [0x0041900C], xmm0
	X86_MEM_WRITE_u32(base, 0x41900Cu, ctx.xmm[0].u32[0]);
	// 0x2617A2: movss [0x00419014], xmm4
	X86_MEM_WRITE_u32(base, 0x419014u, ctx.xmm[4].u32[0]);
	// 0x2617AA: movss [0x00419018], xmm4
	X86_MEM_WRITE_u32(base, 0x419018u, ctx.xmm[4].u32[0]);
	// 0x2617B2: movss [0x00419020], xmm0
	X86_MEM_WRITE_u32(base, 0x419020u, ctx.xmm[0].u32[0]);
	// 0x2617BA: movss [0x0041902C], xmm3
	X86_MEM_WRITE_u32(base, 0x41902Cu, ctx.xmm[3].u32[0]);
	// 0x2617C2: movss [0x00419030], xmm5
	X86_MEM_WRITE_u32(base, 0x419030u, ctx.xmm[5].u32[0]);
	// 0x2617CA: movss [0x00419040], xmm0
	X86_MEM_WRITE_u32(base, 0x419040u, ctx.xmm[0].u32[0]);
	// 0x2617D2: movss [0x00419048], xmm0
	X86_MEM_WRITE_u32(base, 0x419048u, ctx.xmm[0].u32[0]);
	// 0x2617DA: movss [0x00419050], xmm0
	X86_MEM_WRITE_u32(base, 0x419050u, ctx.xmm[0].u32[0]);
	// 0x2617E2: movss [0x0041905C], xmm2
	X86_MEM_WRITE_u32(base, 0x41905Cu, ctx.xmm[2].u32[0]);
	// 0x2617EA: movss [0x00419060], xmm3
	X86_MEM_WRITE_u32(base, 0x419060u, ctx.xmm[3].u32[0]);
	// 0x2617F2: movss [0x00419064], xmm6
	X86_MEM_WRITE_u32(base, 0x419064u, ctx.xmm[6].u32[0]);
	// 0x2617FA: movss [0x00419068], xmm4
	X86_MEM_WRITE_u32(base, 0x419068u, ctx.xmm[4].u32[0]);
	// 0x261802: mov [0x00419074], edx
	X86_MEM_WRITE_u32(base, 0x419074u, ctx.edx);
	// 0x261808: mov [0x00419078], ecx
	X86_MEM_WRITE_u32(base, 0x419078u, ctx.ecx);
	// 0x26180E: mov [0x0041907C], eax
	X86_MEM_WRITE_u32(base, 0x41907Cu, ctx.eax);
	// 0x261813: movss [0x00419080], xmm1
	X86_MEM_WRITE_u32(base, 0x419080u, ctx.xmm[1].u32[0]);
	// 0x26181B: movss [0x00419084], xmm1
	X86_MEM_WRITE_u32(base, 0x419084u, ctx.xmm[1].u32[0]);
	// 0x261823: movss [0x00419088], xmm0
	X86_MEM_WRITE_u32(base, 0x419088u, ctx.xmm[0].u32[0]);
	// 0x26182B: movss [0x00419090], xmm3
	X86_MEM_WRITE_u32(base, 0x419090u, ctx.xmm[3].u32[0]);
	// 0x261833: movss [0x00419094], xmm4
	X86_MEM_WRITE_u32(base, 0x419094u, ctx.xmm[4].u32[0]);
	// 0x26183B: movss [0x0041909C], xmm0
	X86_MEM_WRITE_u32(base, 0x41909Cu, ctx.xmm[0].u32[0]);
	// 0x261843: movss [0x004190A0], xmm7
	X86_MEM_WRITE_u32(base, 0x4190A0u, ctx.xmm[7].u32[0]);
	// 0x26184B: movss xmm7, dword ptr [0x003B16F0]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x261853: movss [0x004190A4], xmm7
	X86_MEM_WRITE_u32(base, 0x4190A4u, ctx.xmm[7].u32[0]);
	// 0x26185B: movss xmm7, dword ptr [0x003B2160]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2160u);
	// 0x261863: movss [0x004190B0], xmm7
	X86_MEM_WRITE_u32(base, 0x4190B0u, ctx.xmm[7].u32[0]);
	// 0x26186B: movss xmm7, dword ptr [0x003B17D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17D8u);
	// 0x261873: movss [0x004190B4], xmm7
	X86_MEM_WRITE_u32(base, 0x4190B4u, ctx.xmm[7].u32[0]);
	// 0x26187B: movss xmm7, dword ptr [0x003B2160]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B2160u);
	// 0x261883: movss [0x004190C0], xmm7
	X86_MEM_WRITE_u32(base, 0x4190C0u, ctx.xmm[7].u32[0]);
	// 0x26188B: movss xmm7, dword ptr [0x003B215C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B215Cu);
	// 0x261893: movss [0x004190C8], xmm7
	X86_MEM_WRITE_u32(base, 0x4190C8u, ctx.xmm[7].u32[0]);
	// 0x26189B: movss xmm7, dword ptr [0x003B16EC]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2618A3: movss [0x004190D0], xmm7
	X86_MEM_WRITE_u32(base, 0x4190D0u, ctx.xmm[7].u32[0]);
	// 0x2618AB: movss xmm7, dword ptr [0x003B1750]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2618B3: movss [0x004190D4], xmm7
	X86_MEM_WRITE_u32(base, 0x4190D4u, ctx.xmm[7].u32[0]);
	// 0x2618BB: movss xmm7, dword ptr [0x003B1728]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1728u);
	// 0x2618C3: movss [0x004190E8], xmm7
	X86_MEM_WRITE_u32(base, 0x4190E8u, ctx.xmm[7].u32[0]);
	// 0x2618CB: movss xmm7, dword ptr [0x00386DC8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x386DC8u);
	// 0x2618D3: movss [0x004190EC], xmm7
	X86_MEM_WRITE_u32(base, 0x4190ECu, ctx.xmm[7].u32[0]);
	// 0x2618DB: movss xmm7, dword ptr [0x0039922C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x39922Cu);
	// 0x2618E3: movss [0x004190AC], xmm5
	X86_MEM_WRITE_u32(base, 0x4190ACu, ctx.xmm[5].u32[0]);
	// 0x2618EB: movss [0x00419108], xmm7
	X86_MEM_WRITE_u32(base, 0x419108u, ctx.xmm[7].u32[0]);
	// 0x2618F3: movss xmm7, dword ptr [0x003B1684]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2618FB: movss [0x00419128], xmm5
	X86_MEM_WRITE_u32(base, 0x419128u, ctx.xmm[5].u32[0]);
	// 0x261903: movss xmm5, dword ptr [0x0039B2B0]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26190B: movss [0x0041910C], xmm7
	X86_MEM_WRITE_u32(base, 0x41910Cu, ctx.xmm[7].u32[0]);
	// 0x261913: movss xmm7, dword ptr [0x003A2D1C]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A2D1Cu);
	// 0x26191B: movss [0x00419130], xmm5
	X86_MEM_WRITE_u32(base, 0x419130u, ctx.xmm[5].u32[0]);
	// 0x261923: movss xmm5, dword ptr [0x003B1684]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x26192B: movss [0x00419110], xmm7
	X86_MEM_WRITE_u32(base, 0x419110u, ctx.xmm[7].u32[0]);
	// 0x261933: movss xmm7, dword ptr [0x003B17D8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3B17D8u);
	// 0x26193B: movss [0x00419134], xmm5
	X86_MEM_WRITE_u32(base, 0x419134u, ctx.xmm[5].u32[0]);
	// 0x261943: movss [0x00419140], xmm5
	X86_MEM_WRITE_u32(base, 0x419140u, ctx.xmm[5].u32[0]);
	// 0x26194B: movss xmm5, dword ptr [0x003B1B94]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B1B94u);
	// 0x261953: movss [0x004190A8], xmm2
	X86_MEM_WRITE_u32(base, 0x4190A8u, ctx.xmm[2].u32[0]);
	// 0x26195B: movss [0x004190D8], xmm2
	X86_MEM_WRITE_u32(base, 0x4190D8u, ctx.xmm[2].u32[0]);
	// 0x261963: movss [0x00419114], xmm7
	X86_MEM_WRITE_u32(base, 0x419114u, ctx.xmm[7].u32[0]);
	// 0x26196B: movss xmm7, dword ptr [0x003A69B8]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A69B8u);
	// 0x261973: movss [0x0041912C], xmm2
	X86_MEM_WRITE_u32(base, 0x41912Cu, ctx.xmm[2].u32[0]);
	// 0x26197B: movss [0x0041913C], xmm2
	X86_MEM_WRITE_u32(base, 0x41913Cu, ctx.xmm[2].u32[0]);
	// 0x261983: movss [0x00419144], xmm5
	X86_MEM_WRITE_u32(base, 0x419144u, ctx.xmm[5].u32[0]);
	// 0x26198B: movss xmm5, dword ptr [0x003B16EC]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x261993: movss [0x00419154], xmm2
	X86_MEM_WRITE_u32(base, 0x419154u, ctx.xmm[2].u32[0]);
	// 0x26199B: movss xmm2, dword ptr [0x003B1728]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1728u);
	// 0x2619A3: movss [0x004190BC], xmm0
	X86_MEM_WRITE_u32(base, 0x4190BCu, ctx.xmm[0].u32[0]);
	// 0x2619AB: movss [0x004190C4], xmm0
	X86_MEM_WRITE_u32(base, 0x4190C4u, ctx.xmm[0].u32[0]);
	// 0x2619B3: movss [0x004190CC], xmm0
	X86_MEM_WRITE_u32(base, 0x4190CCu, ctx.xmm[0].u32[0]);
	// 0x2619BB: movss [0x00419104], xmm0
	X86_MEM_WRITE_u32(base, 0x419104u, ctx.xmm[0].u32[0]);
	// 0x2619C3: movss [0x00419118], xmm0
	X86_MEM_WRITE_u32(base, 0x419118u, ctx.xmm[0].u32[0]);
	// 0x2619CB: movss [0x0041911C], xmm7
	X86_MEM_WRITE_u32(base, 0x41911Cu, ctx.xmm[7].u32[0]);
	// 0x2619D3: movss xmm7, dword ptr [0x003A5600]
	ctx.xmm[7].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x2619DB: movss [0x00419124], xmm0
	X86_MEM_WRITE_u32(base, 0x419124u, ctx.xmm[0].u32[0]);
	// 0x2619E3: movss [0x00419138], xmm0
	X86_MEM_WRITE_u32(base, 0x419138u, ctx.xmm[0].u32[0]);
	// 0x2619EB: movss [0x00419148], xmm0
	X86_MEM_WRITE_u32(base, 0x419148u, ctx.xmm[0].u32[0]);
	// 0x2619F3: movss [0x0041914C], xmm5
	X86_MEM_WRITE_u32(base, 0x41914Cu, ctx.xmm[5].u32[0]);
	// 0x2619FB: movss xmm5, dword ptr [0x003B1750]
	ctx.xmm[5].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x261A03: movss [0x00419164], xmm2
	X86_MEM_WRITE_u32(base, 0x419164u, ctx.xmm[2].u32[0]);
	// 0x261A0B: movss xmm2, dword ptr [0x00386DC8]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x386DC8u);
	// 0x261A13: movss [0x00419180], xmm0
	X86_MEM_WRITE_u32(base, 0x419180u, ctx.xmm[0].u32[0]);
	// 0x261A1B: movss xmm0, dword ptr [0x0039922C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39922Cu);
	// 0x261A23: movss [0x004190B8], xmm3
	X86_MEM_WRITE_u32(base, 0x4190B8u, ctx.xmm[3].u32[0]);
	// 0x261A2B: movss [0x004190DC], xmm3
	X86_MEM_WRITE_u32(base, 0x4190DCu, ctx.xmm[3].u32[0]);
	// 0x261A33: movss [0x004190E0], xmm6
	X86_MEM_WRITE_u32(base, 0x4190E0u, ctx.xmm[6].u32[0]);
	// 0x261A3B: movss [0x004190E4], xmm4
	X86_MEM_WRITE_u32(base, 0x4190E4u, ctx.xmm[4].u32[0]);
	// 0x261A43: mov [0x004190F0], edx
	X86_MEM_WRITE_u32(base, 0x4190F0u, ctx.edx);
	// 0x261A49: mov [0x004190F4], ecx
	X86_MEM_WRITE_u32(base, 0x4190F4u, ctx.ecx);
	// 0x261A4F: mov [0x004190F8], eax
	X86_MEM_WRITE_u32(base, 0x4190F8u, ctx.eax);
	// 0x261A54: movss [0x004190FC], xmm1
	X86_MEM_WRITE_u32(base, 0x4190FCu, ctx.xmm[1].u32[0]);
	// 0x261A5C: movss [0x00419100], xmm1
	X86_MEM_WRITE_u32(base, 0x419100u, ctx.xmm[1].u32[0]);
	// 0x261A64: movss [0x00419120], xmm7
	X86_MEM_WRITE_u32(base, 0x419120u, ctx.xmm[7].u32[0]);
	// 0x261A6C: movss [0x00419150], xmm5
	X86_MEM_WRITE_u32(base, 0x419150u, ctx.xmm[5].u32[0]);
	// 0x261A74: movss [0x00419158], xmm3
	X86_MEM_WRITE_u32(base, 0x419158u, ctx.xmm[3].u32[0]);
	// 0x261A7C: movss [0x0041915C], xmm6
	X86_MEM_WRITE_u32(base, 0x41915Cu, ctx.xmm[6].u32[0]);
	// 0x261A84: movss [0x00419160], xmm4
	X86_MEM_WRITE_u32(base, 0x419160u, ctx.xmm[4].u32[0]);
	// 0x261A8C: movss [0x00419168], xmm2
	X86_MEM_WRITE_u32(base, 0x419168u, ctx.xmm[2].u32[0]);
	// 0x261A94: mov [0x0041916C], edx
	X86_MEM_WRITE_u32(base, 0x41916Cu, ctx.edx);
	// 0x261A9A: mov [0x00419170], ecx
	X86_MEM_WRITE_u32(base, 0x419170u, ctx.ecx);
	// 0x261AA0: mov [0x00419174], eax
	X86_MEM_WRITE_u32(base, 0x419174u, ctx.eax);
	// 0x261AA5: movss [0x00419178], xmm1
	X86_MEM_WRITE_u32(base, 0x419178u, ctx.xmm[1].u32[0]);
	// 0x261AAD: movss [0x0041917C], xmm1
	X86_MEM_WRITE_u32(base, 0x41917Cu, ctx.xmm[1].u32[0]);
	// 0x261AB5: movss [0x00419184], xmm0
	X86_MEM_WRITE_u32(base, 0x419184u, ctx.xmm[0].u32[0]);
	// 0x261ABD: ret
	return;
}

void sub_261AC0(X86Context& ctx, uint8_t* base) {
	// 0x261AC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x261AC8: movss [0x00549294], xmm0
	X86_MEM_WRITE_u32(base, 0x549294u, ctx.xmm[0].u32[0]);
	// 0x261AD0: ret
	return;
}

void sub_261AE0(X86Context& ctx, uint8_t* base) {
	// 0x261AE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x261AE8: movss [0x005492A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5492A0u, ctx.xmm[0].u32[0]);
	// 0x261AF0: ret
	return;
}

void sub_261B00(X86Context& ctx, uint8_t* base) {
	// 0x261B00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x261B08: movss [0x00549290], xmm0
	X86_MEM_WRITE_u32(base, 0x549290u, ctx.xmm[0].u32[0]);
	// 0x261B10: ret
	return;
}

void sub_261B20(X86Context& ctx, uint8_t* base) {
	// 0x261B20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x261B28: movss [0x00549260], xmm0
	X86_MEM_WRITE_u32(base, 0x549260u, ctx.xmm[0].u32[0]);
	// 0x261B30: ret
	return;
}

void sub_261B40(X86Context& ctx, uint8_t* base) {
	// 0x261B40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x261B48: movss [0x00549298], xmm0
	X86_MEM_WRITE_u32(base, 0x549298u, ctx.xmm[0].u32[0]);
	// 0x261B50: ret
	return;
}

void sub_261B60(X86Context& ctx, uint8_t* base) {
	// 0x261B60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x261B68: movss [0x00549268], xmm0
	X86_MEM_WRITE_u32(base, 0x549268u, ctx.xmm[0].u32[0]);
	// 0x261B70: ret
	return;
}

void sub_261B80(X86Context& ctx, uint8_t* base) {
	// 0x261B80: movss xmm0, dword ptr [0x00549298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549298u);
	// 0x261B88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x261B90: movss [0x00549DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x549DF0u, ctx.xmm[0].u32[0]);
	// 0x261B98: ret
	return;
}

void sub_261BA0(X86Context& ctx, uint8_t* base) {
	// 0x261BA0: movss xmm0, dword ptr [0x00549268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549268u);
	// 0x261BA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x261BB0: movss [0x005492A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5492A4u, ctx.xmm[0].u32[0]);
	// 0x261BB8: ret
	return;
}

void sub_261BC0(X86Context& ctx, uint8_t* base) {
	// 0x261BC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x261BC8: movss [0x00549E00], xmm0
	X86_MEM_WRITE_u32(base, 0x549E00u, ctx.xmm[0].u32[0]);
	// 0x261BD0: ret
	return;
}

void sub_261BE0(X86Context& ctx, uint8_t* base) {
	// 0x261BE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x261BE8: movss [0x00549DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x549DF4u, ctx.xmm[0].u32[0]);
	// 0x261BF0: ret
	return;
}

void sub_261C00(X86Context& ctx, uint8_t* base) {
	// 0x261C00: movss xmm0, dword ptr [0x00549DF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549DF4u);
	// 0x261C08: movss [0x00549DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x549DFCu, ctx.xmm[0].u32[0]);
	// 0x261C10: ret
	return;
}

void sub_261C20(X86Context& ctx, uint8_t* base) {
	// 0x261C20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x261C28: movss [0x00549264], xmm0
	X86_MEM_WRITE_u32(base, 0x549264u, ctx.xmm[0].u32[0]);
	// 0x261C30: ret
	return;
}

void sub_261C40(X86Context& ctx, uint8_t* base) {
	// 0x261C40: movss xmm0, dword ptr [0x00549268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549268u);
	// 0x261C48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x261C50: movss [0x00549DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x549DF8u, ctx.xmm[0].u32[0]);
	// 0x261C58: ret
	return;
}

void sub_261C60(X86Context& ctx, uint8_t* base) {
	// 0x261C60: movss xmm0, dword ptr [0x00549268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549268u);
	// 0x261C68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x261C70: movss [0x00549274], xmm0
	X86_MEM_WRITE_u32(base, 0x549274u, ctx.xmm[0].u32[0]);
	// 0x261C78: ret
	return;
}

void sub_261C80(X86Context& ctx, uint8_t* base) {
	// 0x261C80: movss xmm0, dword ptr [0x00549268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549268u);
	// 0x261C88: subss xmm0, [0x00549274]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x549274u);
	// 0x261C90: movss [0x00549270], xmm0
	X86_MEM_WRITE_u32(base, 0x549270u, ctx.xmm[0].u32[0]);
	// 0x261C98: ret
	return;
}

void sub_261CA0(X86Context& ctx, uint8_t* base) {
	// 0x261CA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x261CA8: movss [0x0054929C], xmm0
	X86_MEM_WRITE_u32(base, 0x54929Cu, ctx.xmm[0].u32[0]);
	// 0x261CB0: ret
	return;
}

void sub_261CC0(X86Context& ctx, uint8_t* base) {
	// 0x261CC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x261CC8: movss [0x0054926C], xmm0
	X86_MEM_WRITE_u32(base, 0x54926Cu, ctx.xmm[0].u32[0]);
	// 0x261CD0: ret
	return;
}

void sub_261CE0(X86Context& ctx, uint8_t* base) {
	// 0x261CE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x261CE8: movss [0x00549E24], xmm0
	X86_MEM_WRITE_u32(base, 0x549E24u, ctx.xmm[0].u32[0]);
	// 0x261CF0: ret
	return;
}

void sub_261D00(X86Context& ctx, uint8_t* base) {
	// 0x261D00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x261D08: movss [0x00549E30], xmm0
	X86_MEM_WRITE_u32(base, 0x549E30u, ctx.xmm[0].u32[0]);
	// 0x261D10: ret
	return;
}

void sub_261D20(X86Context& ctx, uint8_t* base) {
	// 0x261D20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x261D28: movss [0x00549E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x549E1Cu, ctx.xmm[0].u32[0]);
	// 0x261D30: ret
	return;
}

void sub_261D40(X86Context& ctx, uint8_t* base) {
	// 0x261D40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x261D48: movss [0x00549E04], xmm0
	X86_MEM_WRITE_u32(base, 0x549E04u, ctx.xmm[0].u32[0]);
	// 0x261D50: ret
	return;
}

void sub_261D60(X86Context& ctx, uint8_t* base) {
	// 0x261D60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x261D68: movss [0x00549E28], xmm0
	X86_MEM_WRITE_u32(base, 0x549E28u, ctx.xmm[0].u32[0]);
	// 0x261D70: ret
	return;
}

void sub_261D80(X86Context& ctx, uint8_t* base) {
	// 0x261D80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x261D88: movss [0x00549E08], xmm0
	X86_MEM_WRITE_u32(base, 0x549E08u, ctx.xmm[0].u32[0]);
	// 0x261D90: ret
	return;
}

void sub_261DA0(X86Context& ctx, uint8_t* base) {
	// 0x261DA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x261DA8: movss [0x00549E38], xmm0
	X86_MEM_WRITE_u32(base, 0x549E38u, ctx.xmm[0].u32[0]);
	// 0x261DB0: ret
	return;
}

void sub_261DC0(X86Context& ctx, uint8_t* base) {
	// 0x261DC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x261DC8: movss [0x00549E20], xmm0
	X86_MEM_WRITE_u32(base, 0x549E20u, ctx.xmm[0].u32[0]);
	// 0x261DD0: ret
	return;
}

void sub_261DE0(X86Context& ctx, uint8_t* base) {
	// 0x261DE0: movss xmm0, dword ptr [0x00549E38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549E38u);
	// 0x261DE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x261DF0: movss [0x00549E10], xmm0
	X86_MEM_WRITE_u32(base, 0x549E10u, ctx.xmm[0].u32[0]);
	// 0x261DF8: ret
	return;
}

void sub_261E00(X86Context& ctx, uint8_t* base) {
	// 0x261E00: movss xmm0, dword ptr [0x00549E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549E20u);
	// 0x261E08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x261E10: movss [0x00549E34], xmm0
	X86_MEM_WRITE_u32(base, 0x549E34u, ctx.xmm[0].u32[0]);
	// 0x261E18: ret
	return;
}

void sub_261E20(X86Context& ctx, uint8_t* base) {
	// 0x261E20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x261E28: movss [0x00549E44], xmm0
	X86_MEM_WRITE_u32(base, 0x549E44u, ctx.xmm[0].u32[0]);
	// 0x261E30: ret
	return;
}

void sub_261E40(X86Context& ctx, uint8_t* base) {
	// 0x261E40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x261E48: movss [0x00549E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x549E3Cu, ctx.xmm[0].u32[0]);
	// 0x261E50: ret
	return;
}

void sub_261E60(X86Context& ctx, uint8_t* base) {
	// 0x261E60: movss xmm0, dword ptr [0x00549E3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549E3Cu);
	// 0x261E68: movss [0x00549E40], xmm0
	X86_MEM_WRITE_u32(base, 0x549E40u, ctx.xmm[0].u32[0]);
	// 0x261E70: ret
	return;
}

void sub_261E80(X86Context& ctx, uint8_t* base) {
	// 0x261E80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x261E88: movss [0x00549E18], xmm0
	X86_MEM_WRITE_u32(base, 0x549E18u, ctx.xmm[0].u32[0]);
	// 0x261E90: ret
	return;
}

void sub_261EA0(X86Context& ctx, uint8_t* base) {
	// 0x261EA0: movss xmm0, dword ptr [0x00549E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549E20u);
	// 0x261EA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x261EB0: movss [0x00549E14], xmm0
	X86_MEM_WRITE_u32(base, 0x549E14u, ctx.xmm[0].u32[0]);
	// 0x261EB8: ret
	return;
}

void sub_261EC0(X86Context& ctx, uint8_t* base) {
	// 0x261EC0: movss xmm0, dword ptr [0x00549E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549E20u);
	// 0x261EC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x261ED0: movss [0x00549E2C], xmm0
	X86_MEM_WRITE_u32(base, 0x549E2Cu, ctx.xmm[0].u32[0]);
	// 0x261ED8: ret
	return;
}

void sub_261EE0(X86Context& ctx, uint8_t* base) {
	// 0x261EE0: movss xmm0, dword ptr [0x00549E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549E20u);
	// 0x261EE8: subss xmm0, [0x00549E2C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x549E2Cu);
	// 0x261EF0: movss [0x00549E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x549E0Cu, ctx.xmm[0].u32[0]);
	// 0x261EF8: ret
	return;
}

void sub_261F00(X86Context& ctx, uint8_t* base) {
	// 0x261F00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x261F08: movss [0x00549F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F4Cu, ctx.xmm[0].u32[0]);
	// 0x261F10: ret
	return;
}

void sub_261F20(X86Context& ctx, uint8_t* base) {
	// 0x261F20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x261F28: movss [0x00549F58], xmm0
	X86_MEM_WRITE_u32(base, 0x549F58u, ctx.xmm[0].u32[0]);
	// 0x261F30: ret
	return;
}

void sub_261F40(X86Context& ctx, uint8_t* base) {
	// 0x261F40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x261F48: movss [0x00549F48], xmm0
	X86_MEM_WRITE_u32(base, 0x549F48u, ctx.xmm[0].u32[0]);
	// 0x261F50: ret
	return;
}

void sub_261F60(X86Context& ctx, uint8_t* base) {
	// 0x261F60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x261F68: movss [0x00549F30], xmm0
	X86_MEM_WRITE_u32(base, 0x549F30u, ctx.xmm[0].u32[0]);
	// 0x261F70: ret
	return;
}

void sub_261F80(X86Context& ctx, uint8_t* base) {
	// 0x261F80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x261F88: movss [0x00549F50], xmm0
	X86_MEM_WRITE_u32(base, 0x549F50u, ctx.xmm[0].u32[0]);
	// 0x261F90: ret
	return;
}

void sub_261FA0(X86Context& ctx, uint8_t* base) {
	// 0x261FA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x261FA8: movss [0x00549F38], xmm0
	X86_MEM_WRITE_u32(base, 0x549F38u, ctx.xmm[0].u32[0]);
	// 0x261FB0: ret
	return;
}

void sub_261FC0(X86Context& ctx, uint8_t* base) {
	// 0x261FC0: movss xmm0, dword ptr [0x00549F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F50u);
	// 0x261FC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x261FD0: movss [0x00549F60], xmm0
	X86_MEM_WRITE_u32(base, 0x549F60u, ctx.xmm[0].u32[0]);
	// 0x261FD8: ret
	return;
}

void sub_261FE0(X86Context& ctx, uint8_t* base) {
	// 0x261FE0: movss xmm0, dword ptr [0x00549F38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F38u);
	// 0x261FE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x261FF0: movss [0x00549F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F5Cu, ctx.xmm[0].u32[0]);
	// 0x261FF8: ret
	return;
}

void sub_262000(X86Context& ctx, uint8_t* base) {
	// 0x262000: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262008: movss [0x00549F70], xmm0
	X86_MEM_WRITE_u32(base, 0x549F70u, ctx.xmm[0].u32[0]);
	// 0x262010: ret
	return;
}

void sub_262020(X86Context& ctx, uint8_t* base) {
	// 0x262020: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x262028: movss [0x00549F64], xmm0
	X86_MEM_WRITE_u32(base, 0x549F64u, ctx.xmm[0].u32[0]);
	// 0x262030: ret
	return;
}

void sub_262040(X86Context& ctx, uint8_t* base) {
	// 0x262040: movss xmm0, dword ptr [0x00549F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F64u);
	// 0x262048: movss [0x00549F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F6Cu, ctx.xmm[0].u32[0]);
	// 0x262050: ret
	return;
}

void sub_262060(X86Context& ctx, uint8_t* base) {
	// 0x262060: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262068: movss [0x00549F34], xmm0
	X86_MEM_WRITE_u32(base, 0x549F34u, ctx.xmm[0].u32[0]);
	// 0x262070: ret
	return;
}

void sub_262080(X86Context& ctx, uint8_t* base) {
	// 0x262080: movss xmm0, dword ptr [0x00549F38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F38u);
	// 0x262088: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x262090: movss [0x00549F68], xmm0
	X86_MEM_WRITE_u32(base, 0x549F68u, ctx.xmm[0].u32[0]);
	// 0x262098: ret
	return;
}

void sub_2620A0(X86Context& ctx, uint8_t* base) {
	// 0x2620A0: movss xmm0, dword ptr [0x00549F38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F38u);
	// 0x2620A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2620B0: movss [0x00549F44], xmm0
	X86_MEM_WRITE_u32(base, 0x549F44u, ctx.xmm[0].u32[0]);
	// 0x2620B8: ret
	return;
}

void sub_2620C0(X86Context& ctx, uint8_t* base) {
	// 0x2620C0: movss xmm0, dword ptr [0x00549F38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F38u);
	// 0x2620C8: subss xmm0, [0x00549F44]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x549F44u);
	// 0x2620D0: movss [0x00549F40], xmm0
	X86_MEM_WRITE_u32(base, 0x549F40u, ctx.xmm[0].u32[0]);
	// 0x2620D8: ret
	return;
}

void sub_2620E0(X86Context& ctx, uint8_t* base) {
	// 0x2620E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2620E8: movss [0x00549F54], xmm0
	X86_MEM_WRITE_u32(base, 0x549F54u, ctx.xmm[0].u32[0]);
	// 0x2620F0: ret
	return;
}

void sub_262100(X86Context& ctx, uint8_t* base) {
	// 0x262100: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x262108: movss [0x00549F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F3Cu, ctx.xmm[0].u32[0]);
	// 0x262110: ret
	return;
}

void sub_262120(X86Context& ctx, uint8_t* base) {
	// 0x262120: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x262128: movss [0x00549F90], xmm0
	X86_MEM_WRITE_u32(base, 0x549F90u, ctx.xmm[0].u32[0]);
	// 0x262130: ret
	return;
}

void sub_262140(X86Context& ctx, uint8_t* base) {
	// 0x262140: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262148: movss [0x00549F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F9Cu, ctx.xmm[0].u32[0]);
	// 0x262150: ret
	return;
}

void sub_262160(X86Context& ctx, uint8_t* base) {
	// 0x262160: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262168: movss [0x00549F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F8Cu, ctx.xmm[0].u32[0]);
	// 0x262170: ret
	return;
}

void sub_262180(X86Context& ctx, uint8_t* base) {
	// 0x262180: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262188: movss [0x00549F74], xmm0
	X86_MEM_WRITE_u32(base, 0x549F74u, ctx.xmm[0].u32[0]);
	// 0x262190: ret
	return;
}

void sub_2621A0(X86Context& ctx, uint8_t* base) {
	// 0x2621A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2621A8: movss [0x00549F94], xmm0
	X86_MEM_WRITE_u32(base, 0x549F94u, ctx.xmm[0].u32[0]);
	// 0x2621B0: ret
	return;
}

void sub_2621C0(X86Context& ctx, uint8_t* base) {
	// 0x2621C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2621C8: movss [0x00549F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x549F7Cu, ctx.xmm[0].u32[0]);
	// 0x2621D0: ret
	return;
}

void sub_2621E0(X86Context& ctx, uint8_t* base) {
	// 0x2621E0: movss xmm0, dword ptr [0x00549F94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F94u);
	// 0x2621E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2621F0: movss [0x00549FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x549FA4u, ctx.xmm[0].u32[0]);
	// 0x2621F8: ret
	return;
}

void sub_262200(X86Context& ctx, uint8_t* base) {
	// 0x262200: movss xmm0, dword ptr [0x00549F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F7Cu);
	// 0x262208: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x262210: movss [0x00549FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x549FA0u, ctx.xmm[0].u32[0]);
	// 0x262218: ret
	return;
}

void sub_262220(X86Context& ctx, uint8_t* base) {
	// 0x262220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262228: movss [0x00549FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x549FB4u, ctx.xmm[0].u32[0]);
	// 0x262230: ret
	return;
}

void sub_262240(X86Context& ctx, uint8_t* base) {
	// 0x262240: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x262248: movss [0x00549FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x549FA8u, ctx.xmm[0].u32[0]);
	// 0x262250: ret
	return;
}

void sub_262260(X86Context& ctx, uint8_t* base) {
	// 0x262260: movss xmm0, dword ptr [0x00549FA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549FA8u);
	// 0x262268: movss [0x00549FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x549FB0u, ctx.xmm[0].u32[0]);
	// 0x262270: ret
	return;
}

void sub_262280(X86Context& ctx, uint8_t* base) {
	// 0x262280: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262288: movss [0x00549F78], xmm0
	X86_MEM_WRITE_u32(base, 0x549F78u, ctx.xmm[0].u32[0]);
	// 0x262290: ret
	return;
}

void sub_2622A0(X86Context& ctx, uint8_t* base) {
	// 0x2622A0: movss xmm0, dword ptr [0x00549F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F7Cu);
	// 0x2622A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2622B0: movss [0x00549FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x549FACu, ctx.xmm[0].u32[0]);
	// 0x2622B8: ret
	return;
}

void sub_2622C0(X86Context& ctx, uint8_t* base) {
	// 0x2622C0: movss xmm0, dword ptr [0x00549F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F7Cu);
	// 0x2622C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2622D0: movss [0x00549F88], xmm0
	X86_MEM_WRITE_u32(base, 0x549F88u, ctx.xmm[0].u32[0]);
	// 0x2622D8: ret
	return;
}

void sub_2622E0(X86Context& ctx, uint8_t* base) {
	// 0x2622E0: movss xmm0, dword ptr [0x00549F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549F7Cu);
	// 0x2622E8: subss xmm0, [0x00549F88]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x549F88u);
	// 0x2622F0: movss [0x00549F84], xmm0
	X86_MEM_WRITE_u32(base, 0x549F84u, ctx.xmm[0].u32[0]);
	// 0x2622F8: ret
	return;
}

void sub_262300(X86Context& ctx, uint8_t* base) {
	// 0x262300: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x262308: movss [0x00549F98], xmm0
	X86_MEM_WRITE_u32(base, 0x549F98u, ctx.xmm[0].u32[0]);
	// 0x262310: ret
	return;
}

void sub_262320(X86Context& ctx, uint8_t* base) {
	// 0x262320: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x262328: movss [0x00549F80], xmm0
	X86_MEM_WRITE_u32(base, 0x549F80u, ctx.xmm[0].u32[0]);
	// 0x262330: ret
	return;
}

void sub_262340(X86Context& ctx, uint8_t* base) {
	// 0x262340: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x262348: movss [0x00549FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x549FBCu, ctx.xmm[0].u32[0]);
	// 0x262350: ret
	return;
}

void sub_262360(X86Context& ctx, uint8_t* base) {
	// 0x262360: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x262368: movss [0x00549FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x549FC0u, ctx.xmm[0].u32[0]);
	// 0x262370: ret
	return;
}

void sub_262380(X86Context& ctx, uint8_t* base) {
	// 0x262380: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262388: movss [0x00549FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x549FB8u, ctx.xmm[0].u32[0]);
	// 0x262390: ret
	return;
}

void sub_2623A0(X86Context& ctx, uint8_t* base) {
	// 0x2623A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2623A8: movss [0x0054EAE4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAE4u, ctx.xmm[0].u32[0]);
	// 0x2623B0: ret
	return;
}

void sub_2623C0(X86Context& ctx, uint8_t* base) {
	// 0x2623C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2623C8: movss [0x0054EAF0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAF0u, ctx.xmm[0].u32[0]);
	// 0x2623D0: ret
	return;
}

void sub_2623E0(X86Context& ctx, uint8_t* base) {
	// 0x2623E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2623E8: movss [0x0054EAE0], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAE0u, ctx.xmm[0].u32[0]);
	// 0x2623F0: ret
	return;
}

void sub_262400(X86Context& ctx, uint8_t* base) {
	// 0x262400: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262408: movss [0x00549FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x549FC4u, ctx.xmm[0].u32[0]);
	// 0x262410: ret
	return;
}

void sub_262420(X86Context& ctx, uint8_t* base) {
	// 0x262420: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x262428: movss [0x0054EAE8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAE8u, ctx.xmm[0].u32[0]);
	// 0x262430: ret
	return;
}

void sub_262440(X86Context& ctx, uint8_t* base) {
	// 0x262440: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x262448: movss [0x00549FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x549FCCu, ctx.xmm[0].u32[0]);
	// 0x262450: ret
	return;
}

void sub_262460(X86Context& ctx, uint8_t* base) {
	// 0x262460: movss xmm0, dword ptr [0x0054EAE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EAE8u);
	// 0x262468: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x262470: movss [0x0054EAF8], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAF8u, ctx.xmm[0].u32[0]);
	// 0x262478: ret
	return;
}

void sub_262480(X86Context& ctx, uint8_t* base) {
	// 0x262480: movss xmm0, dword ptr [0x00549FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549FCCu);
	// 0x262488: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x262490: movss [0x0054EAF4], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAF4u, ctx.xmm[0].u32[0]);
	// 0x262498: ret
	return;
}

void sub_2624A0(X86Context& ctx, uint8_t* base) {
	// 0x2624A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2624A8: movss [0x0054EB08], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB08u, ctx.xmm[0].u32[0]);
	// 0x2624B0: ret
	return;
}

void sub_2624C0(X86Context& ctx, uint8_t* base) {
	// 0x2624C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2624C8: movss [0x0054EAFC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAFCu, ctx.xmm[0].u32[0]);
	// 0x2624D0: ret
	return;
}

void sub_2624E0(X86Context& ctx, uint8_t* base) {
	// 0x2624E0: movss xmm0, dword ptr [0x0054EAFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EAFCu);
	// 0x2624E8: movss [0x0054EB04], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB04u, ctx.xmm[0].u32[0]);
	// 0x2624F0: ret
	return;
}

void sub_262500(X86Context& ctx, uint8_t* base) {
	// 0x262500: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x262508: movss [0x00549FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x549FC8u, ctx.xmm[0].u32[0]);
	// 0x262510: ret
	return;
}

void sub_262520(X86Context& ctx, uint8_t* base) {
	// 0x262520: movss xmm0, dword ptr [0x00549FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549FCCu);
	// 0x262528: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x262530: movss [0x0054EB00], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB00u, ctx.xmm[0].u32[0]);
	// 0x262538: ret
	return;
}

void sub_262540(X86Context& ctx, uint8_t* base) {
	// 0x262540: movss xmm0, dword ptr [0x00549FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549FCCu);
	// 0x262548: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x262550: movss [0x00549FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x549FD8u, ctx.xmm[0].u32[0]);
	// 0x262558: ret
	return;
}

void sub_262560(X86Context& ctx, uint8_t* base) {
	// 0x262560: movss xmm0, dword ptr [0x00549FCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x549FCCu);
	// 0x262568: subss xmm0, [0x00549FD8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x549FD8u);
	// 0x262570: movss [0x00549FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x549FD4u, ctx.xmm[0].u32[0]);
	// 0x262578: ret
	return;
}

void sub_262580(X86Context& ctx, uint8_t* base) {
	// 0x262580: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x262588: movss [0x0054EAEC], xmm0
	X86_MEM_WRITE_u32(base, 0x54EAECu, ctx.xmm[0].u32[0]);
	// 0x262590: ret
	return;
}

void sub_2625A0(X86Context& ctx, uint8_t* base) {
	// 0x2625A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2625A8: movss [0x00549FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x549FD0u, ctx.xmm[0].u32[0]);
	// 0x2625B0: ret
	return;
}

void sub_2625C0(X86Context& ctx, uint8_t* base) {
	// 0x2625C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2625C8: movss [0x0054EB28], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB28u, ctx.xmm[0].u32[0]);
	// 0x2625D0: ret
	return;
}

void sub_2625E0(X86Context& ctx, uint8_t* base) {
	// 0x2625E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2625E8: movss [0x0054EB34], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB34u, ctx.xmm[0].u32[0]);
	// 0x2625F0: ret
	return;
}

void sub_262600(X86Context& ctx, uint8_t* base) {
	// 0x262600: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x262608: movss [0x0054EB24], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB24u, ctx.xmm[0].u32[0]);
	// 0x262610: ret
	return;
}

void sub_262620(X86Context& ctx, uint8_t* base) {
	// 0x262620: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x262628: movss [0x0054EB0C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB0Cu, ctx.xmm[0].u32[0]);
	// 0x262630: ret
	return;
}

void sub_262640(X86Context& ctx, uint8_t* base) {
	// 0x262640: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x262648: movss [0x0054EB2C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB2Cu, ctx.xmm[0].u32[0]);
	// 0x262650: ret
	return;
}

void sub_262660(X86Context& ctx, uint8_t* base) {
	// 0x262660: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x262668: movss [0x0054EB14], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB14u, ctx.xmm[0].u32[0]);
	// 0x262670: ret
	return;
}

void sub_262680(X86Context& ctx, uint8_t* base) {
	// 0x262680: movss xmm0, dword ptr [0x0054EB2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB2Cu);
	// 0x262688: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x262690: movss [0x0054EB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB3Cu, ctx.xmm[0].u32[0]);
	// 0x262698: ret
	return;
}

void sub_2626A0(X86Context& ctx, uint8_t* base) {
	// 0x2626A0: movss xmm0, dword ptr [0x0054EB14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x54EB14u);
	// 0x2626A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2626B0: movss [0x0054EB38], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB38u, ctx.xmm[0].u32[0]);
	// 0x2626B8: ret
	return;
}

void sub_2626C0(X86Context& ctx, uint8_t* base) {
	// 0x2626C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2626C8: movss [0x0054EB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x54EB4Cu, ctx.xmm[0].u32[0]);
	// 0x2626D0: ret
	return;
}

