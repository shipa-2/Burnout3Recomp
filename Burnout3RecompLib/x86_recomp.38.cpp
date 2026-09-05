#include "x86_recomp_shared.h"

void sub_26D090(X86Context& ctx, uint8_t* base) {
	// 0x26D090: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26D098: movss [0x00567EB0], xmm0
	X86_MEM_WRITE_u32(base, 0x567EB0u, ctx.xmm[0].u32[0]);
	// 0x26D0A0: ret
	return;
}

void sub_26D0B0(X86Context& ctx, uint8_t* base) {
	// 0x26D0B0: movss xmm0, dword ptr [0x00567EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EF4u);
	// 0x26D0B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26D0C0: movss [0x00567F2C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F2Cu, ctx.xmm[0].u32[0]);
	// 0x26D0C8: ret
	return;
}

void sub_26D0D0(X86Context& ctx, uint8_t* base) {
	// 0x26D0D0: movss xmm0, dword ptr [0x00567EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EB0u);
	// 0x26D0D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26D0E0: movss [0x00567F14], xmm0
	X86_MEM_WRITE_u32(base, 0x567F14u, ctx.xmm[0].u32[0]);
	// 0x26D0E8: ret
	return;
}

void sub_26D0F0(X86Context& ctx, uint8_t* base) {
	// 0x26D0F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26D0F8: movss [0x00567F44], xmm0
	X86_MEM_WRITE_u32(base, 0x567F44u, ctx.xmm[0].u32[0]);
	// 0x26D100: ret
	return;
}

void sub_26D110(X86Context& ctx, uint8_t* base) {
	// 0x26D110: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26D118: movss [0x00567F30], xmm0
	X86_MEM_WRITE_u32(base, 0x567F30u, ctx.xmm[0].u32[0]);
	// 0x26D120: ret
	return;
}

void sub_26D130(X86Context& ctx, uint8_t* base) {
	// 0x26D130: movss xmm0, dword ptr [0x00567F30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F30u);
	// 0x26D138: movss [0x00567F40], xmm0
	X86_MEM_WRITE_u32(base, 0x567F40u, ctx.xmm[0].u32[0]);
	// 0x26D140: ret
	return;
}

void sub_26D150(X86Context& ctx, uint8_t* base) {
	// 0x26D150: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26D158: movss [0x00567E9C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E9Cu, ctx.xmm[0].u32[0]);
	// 0x26D160: ret
	return;
}

void sub_26D170(X86Context& ctx, uint8_t* base) {
	// 0x26D170: movss xmm0, dword ptr [0x00567EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EB0u);
	// 0x26D178: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26D180: movss [0x00567F38], xmm0
	X86_MEM_WRITE_u32(base, 0x567F38u, ctx.xmm[0].u32[0]);
	// 0x26D188: ret
	return;
}

void sub_26D190(X86Context& ctx, uint8_t* base) {
	// 0x26D190: movss xmm0, dword ptr [0x00567EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EB0u);
	// 0x26D198: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26D1A0: movss [0x00567EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x567EDCu, ctx.xmm[0].u32[0]);
	// 0x26D1A8: ret
	return;
}

void sub_26D1B0(X86Context& ctx, uint8_t* base) {
	// 0x26D1B0: movss xmm0, dword ptr [0x00567EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EB0u);
	// 0x26D1B8: subss xmm0, [0x00567EDC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567EDCu);
	// 0x26D1C0: movss [0x00567EB8], xmm0
	X86_MEM_WRITE_u32(base, 0x567EB8u, ctx.xmm[0].u32[0]);
	// 0x26D1C8: ret
	return;
}

void sub_26D1D0(X86Context& ctx, uint8_t* base) {
	// 0x26D1D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26D1D8: movss [0x00567F08], xmm0
	X86_MEM_WRITE_u32(base, 0x567F08u, ctx.xmm[0].u32[0]);
	// 0x26D1E0: ret
	return;
}

void sub_26D1F0(X86Context& ctx, uint8_t* base) {
	// 0x26D1F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26D1F8: movss [0x00567EB4], xmm0
	X86_MEM_WRITE_u32(base, 0x567EB4u, ctx.xmm[0].u32[0]);
	// 0x26D200: ret
	return;
}

void sub_26D210(X86Context& ctx, uint8_t* base) {
	// 0x26D210: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26D218: movss [0x00567EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x567EC8u, ctx.xmm[0].u32[0]);
	// 0x26D220: ret
	return;
}

void sub_26D230(X86Context& ctx, uint8_t* base) {
	// 0x26D230: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26D238: movss [0x00567F20], xmm0
	X86_MEM_WRITE_u32(base, 0x567F20u, ctx.xmm[0].u32[0]);
	// 0x26D240: ret
	return;
}

void sub_26D250(X86Context& ctx, uint8_t* base) {
	// 0x26D250: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26D258: movss [0x00567F04], xmm0
	X86_MEM_WRITE_u32(base, 0x567F04u, ctx.xmm[0].u32[0]);
	// 0x26D260: ret
	return;
}

void sub_26D270(X86Context& ctx, uint8_t* base) {
	// 0x26D270: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26D278: movss [0x00567EAC], xmm0
	X86_MEM_WRITE_u32(base, 0x567EACu, ctx.xmm[0].u32[0]);
	// 0x26D280: ret
	return;
}

void sub_26D290(X86Context& ctx, uint8_t* base) {
	// 0x26D290: movss xmm0, dword ptr [0x00567EC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EC8u);
	// 0x26D298: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26D2A0: movss [0x00567EA0], xmm0
	X86_MEM_WRITE_u32(base, 0x567EA0u, ctx.xmm[0].u32[0]);
	// 0x26D2A8: ret
	return;
}

void sub_26D2B0(X86Context& ctx, uint8_t* base) {
	// 0x26D2B0: movss xmm0, dword ptr [0x00567F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F20u);
	// 0x26D2B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26D2C0: movss [0x00567EE8], xmm0
	X86_MEM_WRITE_u32(base, 0x567EE8u, ctx.xmm[0].u32[0]);
	// 0x26D2C8: ret
	return;
}

void sub_26D2D0(X86Context& ctx, uint8_t* base) {
	// 0x26D2D0: movss xmm0, dword ptr [0x00567EA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EA0u);
	// 0x26D2D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26D2E0: movss [0x00567EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x567EFCu, ctx.xmm[0].u32[0]);
	// 0x26D2E8: ret
	return;
}

void sub_26D2F0(X86Context& ctx, uint8_t* base) {
	// 0x26D2F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26D2F8: movss [0x00567E98], xmm0
	X86_MEM_WRITE_u32(base, 0x567E98u, ctx.xmm[0].u32[0]);
	// 0x26D300: ret
	return;
}

void sub_26D310(X86Context& ctx, uint8_t* base) {
	// 0x26D310: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26D318: movss [0x00567ECC], xmm0
	X86_MEM_WRITE_u32(base, 0x567ECCu, ctx.xmm[0].u32[0]);
	// 0x26D320: ret
	return;
}

void sub_26D330(X86Context& ctx, uint8_t* base) {
	// 0x26D330: movss xmm0, dword ptr [0x00567EC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EC8u);
	// 0x26D338: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26D340: movss [0x00567ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x567ED8u, ctx.xmm[0].u32[0]);
	// 0x26D348: ret
	return;
}

void sub_26D350(X86Context& ctx, uint8_t* base) {
	// 0x26D350: movss xmm0, dword ptr [0x00567F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F20u);
	// 0x26D358: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26D360: movss [0x00567F24], xmm0
	X86_MEM_WRITE_u32(base, 0x567F24u, ctx.xmm[0].u32[0]);
	// 0x26D368: ret
	return;
}

void sub_26D370(X86Context& ctx, uint8_t* base) {
	// 0x26D370: movss xmm0, dword ptr [0x00567ED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567ED8u);
	// 0x26D378: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D380: movss [0x00567F10], xmm0
	X86_MEM_WRITE_u32(base, 0x567F10u, ctx.xmm[0].u32[0]);
	// 0x26D388: ret
	return;
}

void sub_26D390(X86Context& ctx, uint8_t* base) {
	// 0x26D390: movss xmm0, dword ptr [0x00567F24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F24u);
	// 0x26D398: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D3A0: movss [0x00567F34], xmm0
	X86_MEM_WRITE_u32(base, 0x567F34u, ctx.xmm[0].u32[0]);
	// 0x26D3A8: ret
	return;
}

void sub_26D3B0(X86Context& ctx, uint8_t* base) {
	// 0x26D3B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26D3B8: movss [0x00567EA4], xmm0
	X86_MEM_WRITE_u32(base, 0x567EA4u, ctx.xmm[0].u32[0]);
	// 0x26D3C0: ret
	return;
}

void sub_26D3D0(X86Context& ctx, uint8_t* base) {
	// 0x26D3D0: movss xmm0, dword ptr [0x00567EC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EC8u);
	// 0x26D3D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D3E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26D3E8: movss [0x00567F1C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F1Cu, ctx.xmm[0].u32[0]);
	// 0x26D3F0: ret
	return;
}

void sub_26D400(X86Context& ctx, uint8_t* base) {
	// 0x26D400: movss xmm0, dword ptr [0x00567F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F20u);
	// 0x26D408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D410: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26D418: movss [0x00567EBC], xmm0
	X86_MEM_WRITE_u32(base, 0x567EBCu, ctx.xmm[0].u32[0]);
	// 0x26D420: ret
	return;
}

void sub_26D430(X86Context& ctx, uint8_t* base) {
	// 0x26D430: movss xmm0, dword ptr [0x00567EC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EC8u);
	// 0x26D438: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D440: movss [0x00567EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x567EC0u, ctx.xmm[0].u32[0]);
	// 0x26D448: ret
	return;
}

void sub_26D450(X86Context& ctx, uint8_t* base) {
	// 0x26D450: movss xmm0, dword ptr [0x00567F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F20u);
	// 0x26D458: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D460: movss [0x00567F28], xmm0
	X86_MEM_WRITE_u32(base, 0x567F28u, ctx.xmm[0].u32[0]);
	// 0x26D468: ret
	return;
}

void sub_26D470(X86Context& ctx, uint8_t* base) {
	// 0x26D470: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26D478: movss [0x00567EA8], xmm0
	X86_MEM_WRITE_u32(base, 0x567EA8u, ctx.xmm[0].u32[0]);
	// 0x26D480: ret
	return;
}

void sub_26D490(X86Context& ctx, uint8_t* base) {
	// 0x26D490: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26D498: movss [0x00567ED4], xmm0
	X86_MEM_WRITE_u32(base, 0x567ED4u, ctx.xmm[0].u32[0]);
	// 0x26D4A0: ret
	return;
}

void sub_26D4B0(X86Context& ctx, uint8_t* base) {
	// 0x26D4B0: movss xmm0, dword ptr [0x00567EA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EA8u);
	// 0x26D4B8: movss [0x00567F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F3Cu, ctx.xmm[0].u32[0]);
	// 0x26D4C0: ret
	return;
}

void sub_26D4D0(X86Context& ctx, uint8_t* base) {
	// 0x26D4D0: movss xmm0, dword ptr [0x00567F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F20u);
	// 0x26D4D8: subss xmm0, [0x00567EA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567EA8u);
	// 0x26D4E0: movss [0x00567F00], xmm0
	X86_MEM_WRITE_u32(base, 0x567F00u, ctx.xmm[0].u32[0]);
	// 0x26D4E8: ret
	return;
}

void sub_26D4F0(X86Context& ctx, uint8_t* base) {
	// 0x26D4F0: movss xmm0, dword ptr [0x00567F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F00u);
	// 0x26D4F8: subss xmm0, [0x00567ED4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567ED4u);
	// 0x26D500: movss [0x00567EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x567EF8u, ctx.xmm[0].u32[0]);
	// 0x26D508: ret
	return;
}

void sub_26D510(X86Context& ctx, uint8_t* base) {
	// 0x26D510: movss xmm0, dword ptr [0x00567F28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F28u);
	// 0x26D518: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26D520: movss [0x00567EE4], xmm0
	X86_MEM_WRITE_u32(base, 0x567EE4u, ctx.xmm[0].u32[0]);
	// 0x26D528: ret
	return;
}

void sub_26D530(X86Context& ctx, uint8_t* base) {
	// 0x26D530: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26D538: movss [0x00567ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x567ED0u, ctx.xmm[0].u32[0]);
	// 0x26D540: ret
	return;
}

void sub_26D550(X86Context& ctx, uint8_t* base) {
	// 0x26D550: movss xmm0, dword ptr [0x00567EE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567EE4u);
	// 0x26D558: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26D560: movss [0x00567F18], xmm0
	X86_MEM_WRITE_u32(base, 0x567F18u, ctx.xmm[0].u32[0]);
	// 0x26D568: ret
	return;
}

void sub_26D570(X86Context& ctx, uint8_t* base) {
	// 0x26D570: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26D578: movss [0x00567EEC], xmm0
	X86_MEM_WRITE_u32(base, 0x567EECu, ctx.xmm[0].u32[0]);
	// 0x26D580: ret
	return;
}

void sub_26D590(X86Context& ctx, uint8_t* base) {
	// 0x26D590: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26D598: movss [0x00567EC4], xmm0
	X86_MEM_WRITE_u32(base, 0x567EC4u, ctx.xmm[0].u32[0]);
	// 0x26D5A0: ret
	return;
}

void sub_26D5B0(X86Context& ctx, uint8_t* base) {
	// 0x26D5B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26D5B8: movss [0x00567FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x567FA4u, ctx.xmm[0].u32[0]);
	// 0x26D5C0: ret
	return;
}

void sub_26D5D0(X86Context& ctx, uint8_t* base) {
	// 0x26D5D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26D5D8: movss [0x00567FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x567FC0u, ctx.xmm[0].u32[0]);
	// 0x26D5E0: ret
	return;
}

void sub_26D5F0(X86Context& ctx, uint8_t* base) {
	// 0x26D5F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26D5F8: movss [0x00567F94], xmm0
	X86_MEM_WRITE_u32(base, 0x567F94u, ctx.xmm[0].u32[0]);
	// 0x26D600: ret
	return;
}

void sub_26D610(X86Context& ctx, uint8_t* base) {
	// 0x26D610: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26D618: movss [0x00567F48], xmm0
	X86_MEM_WRITE_u32(base, 0x567F48u, ctx.xmm[0].u32[0]);
	// 0x26D620: ret
	return;
}

void sub_26D630(X86Context& ctx, uint8_t* base) {
	// 0x26D630: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26D638: movss [0x00567FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x567FA8u, ctx.xmm[0].u32[0]);
	// 0x26D640: ret
	return;
}

void sub_26D650(X86Context& ctx, uint8_t* base) {
	// 0x26D650: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26D658: movss [0x00567F64], xmm0
	X86_MEM_WRITE_u32(base, 0x567F64u, ctx.xmm[0].u32[0]);
	// 0x26D660: ret
	return;
}

void sub_26D670(X86Context& ctx, uint8_t* base) {
	// 0x26D670: movss xmm0, dword ptr [0x00567FA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FA8u);
	// 0x26D678: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26D680: movss [0x00567FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x567FE0u, ctx.xmm[0].u32[0]);
	// 0x26D688: ret
	return;
}

void sub_26D690(X86Context& ctx, uint8_t* base) {
	// 0x26D690: movss xmm0, dword ptr [0x00567F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F64u);
	// 0x26D698: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26D6A0: movss [0x00567FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x567FC8u, ctx.xmm[0].u32[0]);
	// 0x26D6A8: ret
	return;
}

void sub_26D6B0(X86Context& ctx, uint8_t* base) {
	// 0x26D6B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26D6B8: movss [0x00567FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x567FF8u, ctx.xmm[0].u32[0]);
	// 0x26D6C0: ret
	return;
}

void sub_26D6D0(X86Context& ctx, uint8_t* base) {
	// 0x26D6D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26D6D8: movss [0x00567FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x567FE4u, ctx.xmm[0].u32[0]);
	// 0x26D6E0: ret
	return;
}

void sub_26D6F0(X86Context& ctx, uint8_t* base) {
	// 0x26D6F0: movss xmm0, dword ptr [0x00567FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FE4u);
	// 0x26D6F8: movss [0x00567FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x567FF4u, ctx.xmm[0].u32[0]);
	// 0x26D700: ret
	return;
}

void sub_26D710(X86Context& ctx, uint8_t* base) {
	// 0x26D710: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26D718: movss [0x00567F50], xmm0
	X86_MEM_WRITE_u32(base, 0x567F50u, ctx.xmm[0].u32[0]);
	// 0x26D720: ret
	return;
}

void sub_26D730(X86Context& ctx, uint8_t* base) {
	// 0x26D730: movss xmm0, dword ptr [0x00567F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F64u);
	// 0x26D738: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26D740: movss [0x00567FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x567FECu, ctx.xmm[0].u32[0]);
	// 0x26D748: ret
	return;
}

void sub_26D750(X86Context& ctx, uint8_t* base) {
	// 0x26D750: movss xmm0, dword ptr [0x00567F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F64u);
	// 0x26D758: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26D760: movss [0x00567F90], xmm0
	X86_MEM_WRITE_u32(base, 0x567F90u, ctx.xmm[0].u32[0]);
	// 0x26D768: ret
	return;
}

void sub_26D770(X86Context& ctx, uint8_t* base) {
	// 0x26D770: movss xmm0, dword ptr [0x00567F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F64u);
	// 0x26D778: subss xmm0, [0x00567F90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567F90u);
	// 0x26D780: movss [0x00567F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F6Cu, ctx.xmm[0].u32[0]);
	// 0x26D788: ret
	return;
}

void sub_26D790(X86Context& ctx, uint8_t* base) {
	// 0x26D790: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26D798: movss [0x00567FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x567FBCu, ctx.xmm[0].u32[0]);
	// 0x26D7A0: ret
	return;
}

void sub_26D7B0(X86Context& ctx, uint8_t* base) {
	// 0x26D7B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26D7B8: movss [0x00567F68], xmm0
	X86_MEM_WRITE_u32(base, 0x567F68u, ctx.xmm[0].u32[0]);
	// 0x26D7C0: ret
	return;
}

void sub_26D7D0(X86Context& ctx, uint8_t* base) {
	// 0x26D7D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26D7D8: movss [0x00567F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F7Cu, ctx.xmm[0].u32[0]);
	// 0x26D7E0: ret
	return;
}

void sub_26D7F0(X86Context& ctx, uint8_t* base) {
	// 0x26D7F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26D7F8: movss [0x00567FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x567FD4u, ctx.xmm[0].u32[0]);
	// 0x26D800: ret
	return;
}

void sub_26D810(X86Context& ctx, uint8_t* base) {
	// 0x26D810: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26D818: movss [0x00567FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x567FB8u, ctx.xmm[0].u32[0]);
	// 0x26D820: ret
	return;
}

void sub_26D830(X86Context& ctx, uint8_t* base) {
	// 0x26D830: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26D838: movss [0x00567F60], xmm0
	X86_MEM_WRITE_u32(base, 0x567F60u, ctx.xmm[0].u32[0]);
	// 0x26D840: ret
	return;
}

void sub_26D850(X86Context& ctx, uint8_t* base) {
	// 0x26D850: movss xmm0, dword ptr [0x00567F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F7Cu);
	// 0x26D858: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26D860: movss [0x00567F54], xmm0
	X86_MEM_WRITE_u32(base, 0x567F54u, ctx.xmm[0].u32[0]);
	// 0x26D868: ret
	return;
}

void sub_26D870(X86Context& ctx, uint8_t* base) {
	// 0x26D870: movss xmm0, dword ptr [0x00567FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FD4u);
	// 0x26D878: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26D880: movss [0x00567F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F9Cu, ctx.xmm[0].u32[0]);
	// 0x26D888: ret
	return;
}

void sub_26D890(X86Context& ctx, uint8_t* base) {
	// 0x26D890: movss xmm0, dword ptr [0x00567F54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F54u);
	// 0x26D898: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26D8A0: movss [0x00567FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x567FB0u, ctx.xmm[0].u32[0]);
	// 0x26D8A8: ret
	return;
}

void sub_26D8B0(X86Context& ctx, uint8_t* base) {
	// 0x26D8B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26D8B8: movss [0x00567F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F4Cu, ctx.xmm[0].u32[0]);
	// 0x26D8C0: ret
	return;
}

void sub_26D8D0(X86Context& ctx, uint8_t* base) {
	// 0x26D8D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26D8D8: movss [0x00567F80], xmm0
	X86_MEM_WRITE_u32(base, 0x567F80u, ctx.xmm[0].u32[0]);
	// 0x26D8E0: ret
	return;
}

void sub_26D8F0(X86Context& ctx, uint8_t* base) {
	// 0x26D8F0: movss xmm0, dword ptr [0x00567F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F7Cu);
	// 0x26D8F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26D900: movss [0x00567F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F8Cu, ctx.xmm[0].u32[0]);
	// 0x26D908: ret
	return;
}

void sub_26D910(X86Context& ctx, uint8_t* base) {
	// 0x26D910: movss xmm0, dword ptr [0x00567FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FD4u);
	// 0x26D918: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26D920: movss [0x00567FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x567FD8u, ctx.xmm[0].u32[0]);
	// 0x26D928: ret
	return;
}

void sub_26D930(X86Context& ctx, uint8_t* base) {
	// 0x26D930: movss xmm0, dword ptr [0x00567F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F8Cu);
	// 0x26D938: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D940: movss [0x00567FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x567FC4u, ctx.xmm[0].u32[0]);
	// 0x26D948: ret
	return;
}

void sub_26D950(X86Context& ctx, uint8_t* base) {
	// 0x26D950: movss xmm0, dword ptr [0x00567FD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FD8u);
	// 0x26D958: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D960: movss [0x00567FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x567FE8u, ctx.xmm[0].u32[0]);
	// 0x26D968: ret
	return;
}

void sub_26D970(X86Context& ctx, uint8_t* base) {
	// 0x26D970: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26D978: movss [0x00567F58], xmm0
	X86_MEM_WRITE_u32(base, 0x567F58u, ctx.xmm[0].u32[0]);
	// 0x26D980: ret
	return;
}

void sub_26D990(X86Context& ctx, uint8_t* base) {
	// 0x26D990: movss xmm0, dword ptr [0x00567F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F7Cu);
	// 0x26D998: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D9A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26D9A8: movss [0x00567FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x567FD0u, ctx.xmm[0].u32[0]);
	// 0x26D9B0: ret
	return;
}

void sub_26D9C0(X86Context& ctx, uint8_t* base) {
	// 0x26D9C0: movss xmm0, dword ptr [0x00567FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FD4u);
	// 0x26D9C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26D9D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26D9D8: movss [0x00567F70], xmm0
	X86_MEM_WRITE_u32(base, 0x567F70u, ctx.xmm[0].u32[0]);
	// 0x26D9E0: ret
	return;
}

void sub_26D9F0(X86Context& ctx, uint8_t* base) {
	// 0x26D9F0: movss xmm0, dword ptr [0x00567F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F7Cu);
	// 0x26D9F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DA00: movss [0x00567F74], xmm0
	X86_MEM_WRITE_u32(base, 0x567F74u, ctx.xmm[0].u32[0]);
	// 0x26DA08: ret
	return;
}

void sub_26DA10(X86Context& ctx, uint8_t* base) {
	// 0x26DA10: movss xmm0, dword ptr [0x00567FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FD4u);
	// 0x26DA18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DA20: movss [0x00567FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x567FDCu, ctx.xmm[0].u32[0]);
	// 0x26DA28: ret
	return;
}

void sub_26DA30(X86Context& ctx, uint8_t* base) {
	// 0x26DA30: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26DA38: movss [0x00567F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F5Cu, ctx.xmm[0].u32[0]);
	// 0x26DA40: ret
	return;
}

void sub_26DA50(X86Context& ctx, uint8_t* base) {
	// 0x26DA50: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26DA58: movss [0x00567F88], xmm0
	X86_MEM_WRITE_u32(base, 0x567F88u, ctx.xmm[0].u32[0]);
	// 0x26DA60: ret
	return;
}

void sub_26DA70(X86Context& ctx, uint8_t* base) {
	// 0x26DA70: movss xmm0, dword ptr [0x00567F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F5Cu);
	// 0x26DA78: movss [0x00567FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x567FF0u, ctx.xmm[0].u32[0]);
	// 0x26DA80: ret
	return;
}

void sub_26DA90(X86Context& ctx, uint8_t* base) {
	// 0x26DA90: movss xmm0, dword ptr [0x00567FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FD4u);
	// 0x26DA98: subss xmm0, [0x00567F5C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567F5Cu);
	// 0x26DAA0: movss [0x00567FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x567FB4u, ctx.xmm[0].u32[0]);
	// 0x26DAA8: ret
	return;
}

void sub_26DAB0(X86Context& ctx, uint8_t* base) {
	// 0x26DAB0: movss xmm0, dword ptr [0x00567FB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FB4u);
	// 0x26DAB8: subss xmm0, [0x00567F88]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567F88u);
	// 0x26DAC0: movss [0x00567FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x567FACu, ctx.xmm[0].u32[0]);
	// 0x26DAC8: ret
	return;
}

void sub_26DAD0(X86Context& ctx, uint8_t* base) {
	// 0x26DAD0: movss xmm0, dword ptr [0x00567FDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567FDCu);
	// 0x26DAD8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26DAE0: movss [0x00567F98], xmm0
	X86_MEM_WRITE_u32(base, 0x567F98u, ctx.xmm[0].u32[0]);
	// 0x26DAE8: ret
	return;
}

void sub_26DAF0(X86Context& ctx, uint8_t* base) {
	// 0x26DAF0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26DAF8: movss [0x00567F84], xmm0
	X86_MEM_WRITE_u32(base, 0x567F84u, ctx.xmm[0].u32[0]);
	// 0x26DB00: ret
	return;
}

void sub_26DB10(X86Context& ctx, uint8_t* base) {
	// 0x26DB10: movss xmm0, dword ptr [0x00567F98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567F98u);
	// 0x26DB18: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26DB20: movss [0x00567FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x567FCCu, ctx.xmm[0].u32[0]);
	// 0x26DB28: ret
	return;
}

void sub_26DB30(X86Context& ctx, uint8_t* base) {
	// 0x26DB30: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26DB38: movss [0x00567FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x567FA0u, ctx.xmm[0].u32[0]);
	// 0x26DB40: ret
	return;
}

void sub_26DB50(X86Context& ctx, uint8_t* base) {
	// 0x26DB50: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26DB58: movss [0x00567F78], xmm0
	X86_MEM_WRITE_u32(base, 0x567F78u, ctx.xmm[0].u32[0]);
	// 0x26DB60: ret
	return;
}

void sub_26DB70(X86Context& ctx, uint8_t* base) {
	// 0x26DB70: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26DB78: movss [0x00568058], xmm0
	X86_MEM_WRITE_u32(base, 0x568058u, ctx.xmm[0].u32[0]);
	// 0x26DB80: ret
	return;
}

void sub_26DB90(X86Context& ctx, uint8_t* base) {
	// 0x26DB90: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26DB98: movss [0x00568074], xmm0
	X86_MEM_WRITE_u32(base, 0x568074u, ctx.xmm[0].u32[0]);
	// 0x26DBA0: ret
	return;
}

void sub_26DBB0(X86Context& ctx, uint8_t* base) {
	// 0x26DBB0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26DBB8: movss [0x00568048], xmm0
	X86_MEM_WRITE_u32(base, 0x568048u, ctx.xmm[0].u32[0]);
	// 0x26DBC0: ret
	return;
}

void sub_26DBD0(X86Context& ctx, uint8_t* base) {
	// 0x26DBD0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26DBD8: movss [0x00567FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x567FFCu, ctx.xmm[0].u32[0]);
	// 0x26DBE0: ret
	return;
}

void sub_26DBF0(X86Context& ctx, uint8_t* base) {
	// 0x26DBF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26DBF8: movss [0x0056805C], xmm0
	X86_MEM_WRITE_u32(base, 0x56805Cu, ctx.xmm[0].u32[0]);
	// 0x26DC00: ret
	return;
}

void sub_26DC10(X86Context& ctx, uint8_t* base) {
	// 0x26DC10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26DC18: movss [0x00568018], xmm0
	X86_MEM_WRITE_u32(base, 0x568018u, ctx.xmm[0].u32[0]);
	// 0x26DC20: ret
	return;
}

void sub_26DC30(X86Context& ctx, uint8_t* base) {
	// 0x26DC30: movss xmm0, dword ptr [0x0056805C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56805Cu);
	// 0x26DC38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26DC40: movss [0x00568094], xmm0
	X86_MEM_WRITE_u32(base, 0x568094u, ctx.xmm[0].u32[0]);
	// 0x26DC48: ret
	return;
}

void sub_26DC50(X86Context& ctx, uint8_t* base) {
	// 0x26DC50: movss xmm0, dword ptr [0x00568018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568018u);
	// 0x26DC58: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26DC60: movss [0x0056807C], xmm0
	X86_MEM_WRITE_u32(base, 0x56807Cu, ctx.xmm[0].u32[0]);
	// 0x26DC68: ret
	return;
}

void sub_26DC70(X86Context& ctx, uint8_t* base) {
	// 0x26DC70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26DC78: movss [0x005680AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5680ACu, ctx.xmm[0].u32[0]);
	// 0x26DC80: ret
	return;
}

void sub_26DC90(X86Context& ctx, uint8_t* base) {
	// 0x26DC90: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26DC98: movss [0x00568098], xmm0
	X86_MEM_WRITE_u32(base, 0x568098u, ctx.xmm[0].u32[0]);
	// 0x26DCA0: ret
	return;
}

void sub_26DCB0(X86Context& ctx, uint8_t* base) {
	// 0x26DCB0: movss xmm0, dword ptr [0x00568098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568098u);
	// 0x26DCB8: movss [0x005680A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5680A8u, ctx.xmm[0].u32[0]);
	// 0x26DCC0: ret
	return;
}

void sub_26DCD0(X86Context& ctx, uint8_t* base) {
	// 0x26DCD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26DCD8: movss [0x00568004], xmm0
	X86_MEM_WRITE_u32(base, 0x568004u, ctx.xmm[0].u32[0]);
	// 0x26DCE0: ret
	return;
}

void sub_26DCF0(X86Context& ctx, uint8_t* base) {
	// 0x26DCF0: movss xmm0, dword ptr [0x00568018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568018u);
	// 0x26DCF8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26DD00: movss [0x005680A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5680A0u, ctx.xmm[0].u32[0]);
	// 0x26DD08: ret
	return;
}

void sub_26DD10(X86Context& ctx, uint8_t* base) {
	// 0x26DD10: movss xmm0, dword ptr [0x00568018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568018u);
	// 0x26DD18: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26DD20: movss [0x00568044], xmm0
	X86_MEM_WRITE_u32(base, 0x568044u, ctx.xmm[0].u32[0]);
	// 0x26DD28: ret
	return;
}

void sub_26DD30(X86Context& ctx, uint8_t* base) {
	// 0x26DD30: movss xmm0, dword ptr [0x00568018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568018u);
	// 0x26DD38: subss xmm0, [0x00568044]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568044u);
	// 0x26DD40: movss [0x00568020], xmm0
	X86_MEM_WRITE_u32(base, 0x568020u, ctx.xmm[0].u32[0]);
	// 0x26DD48: ret
	return;
}

void sub_26DD50(X86Context& ctx, uint8_t* base) {
	// 0x26DD50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26DD58: movss [0x00568070], xmm0
	X86_MEM_WRITE_u32(base, 0x568070u, ctx.xmm[0].u32[0]);
	// 0x26DD60: ret
	return;
}

void sub_26DD70(X86Context& ctx, uint8_t* base) {
	// 0x26DD70: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26DD78: movss [0x0056801C], xmm0
	X86_MEM_WRITE_u32(base, 0x56801Cu, ctx.xmm[0].u32[0]);
	// 0x26DD80: ret
	return;
}

void sub_26DD90(X86Context& ctx, uint8_t* base) {
	// 0x26DD90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26DD98: movss [0x00568030], xmm0
	X86_MEM_WRITE_u32(base, 0x568030u, ctx.xmm[0].u32[0]);
	// 0x26DDA0: ret
	return;
}

void sub_26DDB0(X86Context& ctx, uint8_t* base) {
	// 0x26DDB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26DDB8: movss [0x00568088], xmm0
	X86_MEM_WRITE_u32(base, 0x568088u, ctx.xmm[0].u32[0]);
	// 0x26DDC0: ret
	return;
}

void sub_26DDD0(X86Context& ctx, uint8_t* base) {
	// 0x26DDD0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26DDD8: movss [0x0056806C], xmm0
	X86_MEM_WRITE_u32(base, 0x56806Cu, ctx.xmm[0].u32[0]);
	// 0x26DDE0: ret
	return;
}

void sub_26DDF0(X86Context& ctx, uint8_t* base) {
	// 0x26DDF0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26DDF8: movss [0x00568014], xmm0
	X86_MEM_WRITE_u32(base, 0x568014u, ctx.xmm[0].u32[0]);
	// 0x26DE00: ret
	return;
}

void sub_26DE10(X86Context& ctx, uint8_t* base) {
	// 0x26DE10: movss xmm0, dword ptr [0x00568030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568030u);
	// 0x26DE18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26DE20: movss [0x00568008], xmm0
	X86_MEM_WRITE_u32(base, 0x568008u, ctx.xmm[0].u32[0]);
	// 0x26DE28: ret
	return;
}

void sub_26DE30(X86Context& ctx, uint8_t* base) {
	// 0x26DE30: movss xmm0, dword ptr [0x00568088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568088u);
	// 0x26DE38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26DE40: movss [0x00568050], xmm0
	X86_MEM_WRITE_u32(base, 0x568050u, ctx.xmm[0].u32[0]);
	// 0x26DE48: ret
	return;
}

void sub_26DE50(X86Context& ctx, uint8_t* base) {
	// 0x26DE50: movss xmm0, dword ptr [0x00568008]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568008u);
	// 0x26DE58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26DE60: movss [0x00568064], xmm0
	X86_MEM_WRITE_u32(base, 0x568064u, ctx.xmm[0].u32[0]);
	// 0x26DE68: ret
	return;
}

void sub_26DE70(X86Context& ctx, uint8_t* base) {
	// 0x26DE70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26DE78: movss [0x00568000], xmm0
	X86_MEM_WRITE_u32(base, 0x568000u, ctx.xmm[0].u32[0]);
	// 0x26DE80: ret
	return;
}

void sub_26DE90(X86Context& ctx, uint8_t* base) {
	// 0x26DE90: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26DE98: movss [0x00568034], xmm0
	X86_MEM_WRITE_u32(base, 0x568034u, ctx.xmm[0].u32[0]);
	// 0x26DEA0: ret
	return;
}

void sub_26DEB0(X86Context& ctx, uint8_t* base) {
	// 0x26DEB0: movss xmm0, dword ptr [0x00568030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568030u);
	// 0x26DEB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26DEC0: movss [0x00568040], xmm0
	X86_MEM_WRITE_u32(base, 0x568040u, ctx.xmm[0].u32[0]);
	// 0x26DEC8: ret
	return;
}

void sub_26DED0(X86Context& ctx, uint8_t* base) {
	// 0x26DED0: movss xmm0, dword ptr [0x00568088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568088u);
	// 0x26DED8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26DEE0: movss [0x0056808C], xmm0
	X86_MEM_WRITE_u32(base, 0x56808Cu, ctx.xmm[0].u32[0]);
	// 0x26DEE8: ret
	return;
}

void sub_26DEF0(X86Context& ctx, uint8_t* base) {
	// 0x26DEF0: movss xmm0, dword ptr [0x00568040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568040u);
	// 0x26DEF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DF00: movss [0x00568078], xmm0
	X86_MEM_WRITE_u32(base, 0x568078u, ctx.xmm[0].u32[0]);
	// 0x26DF08: ret
	return;
}

void sub_26DF10(X86Context& ctx, uint8_t* base) {
	// 0x26DF10: movss xmm0, dword ptr [0x0056808C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56808Cu);
	// 0x26DF18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DF20: movss [0x0056809C], xmm0
	X86_MEM_WRITE_u32(base, 0x56809Cu, ctx.xmm[0].u32[0]);
	// 0x26DF28: ret
	return;
}

void sub_26DF30(X86Context& ctx, uint8_t* base) {
	// 0x26DF30: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26DF38: movss [0x0056800C], xmm0
	X86_MEM_WRITE_u32(base, 0x56800Cu, ctx.xmm[0].u32[0]);
	// 0x26DF40: ret
	return;
}

void sub_26DF50(X86Context& ctx, uint8_t* base) {
	// 0x26DF50: movss xmm0, dword ptr [0x00568030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568030u);
	// 0x26DF58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DF60: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26DF68: movss [0x00568084], xmm0
	X86_MEM_WRITE_u32(base, 0x568084u, ctx.xmm[0].u32[0]);
	// 0x26DF70: ret
	return;
}

void sub_26DF80(X86Context& ctx, uint8_t* base) {
	// 0x26DF80: movss xmm0, dword ptr [0x00568088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568088u);
	// 0x26DF88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DF90: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26DF98: movss [0x00568024], xmm0
	X86_MEM_WRITE_u32(base, 0x568024u, ctx.xmm[0].u32[0]);
	// 0x26DFA0: ret
	return;
}

void sub_26DFB0(X86Context& ctx, uint8_t* base) {
	// 0x26DFB0: movss xmm0, dword ptr [0x00568030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568030u);
	// 0x26DFB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DFC0: movss [0x00568028], xmm0
	X86_MEM_WRITE_u32(base, 0x568028u, ctx.xmm[0].u32[0]);
	// 0x26DFC8: ret
	return;
}

void sub_26DFD0(X86Context& ctx, uint8_t* base) {
	// 0x26DFD0: movss xmm0, dword ptr [0x00568088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568088u);
	// 0x26DFD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26DFE0: movss [0x00568090], xmm0
	X86_MEM_WRITE_u32(base, 0x568090u, ctx.xmm[0].u32[0]);
	// 0x26DFE8: ret
	return;
}

void sub_26DFF0(X86Context& ctx, uint8_t* base) {
	// 0x26DFF0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26DFF8: movss [0x00568010], xmm0
	X86_MEM_WRITE_u32(base, 0x568010u, ctx.xmm[0].u32[0]);
	// 0x26E000: ret
	return;
}

void sub_26E010(X86Context& ctx, uint8_t* base) {
	// 0x26E010: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26E018: movss [0x0056803C], xmm0
	X86_MEM_WRITE_u32(base, 0x56803Cu, ctx.xmm[0].u32[0]);
	// 0x26E020: ret
	return;
}

void sub_26E030(X86Context& ctx, uint8_t* base) {
	// 0x26E030: movss xmm0, dword ptr [0x00568010]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568010u);
	// 0x26E038: movss [0x005680A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5680A4u, ctx.xmm[0].u32[0]);
	// 0x26E040: ret
	return;
}

void sub_26E050(X86Context& ctx, uint8_t* base) {
	// 0x26E050: movss xmm0, dword ptr [0x00568088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568088u);
	// 0x26E058: subss xmm0, [0x00568010]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568010u);
	// 0x26E060: movss [0x00568068], xmm0
	X86_MEM_WRITE_u32(base, 0x568068u, ctx.xmm[0].u32[0]);
	// 0x26E068: ret
	return;
}

void sub_26E070(X86Context& ctx, uint8_t* base) {
	// 0x26E070: movss xmm0, dword ptr [0x00568068]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568068u);
	// 0x26E078: subss xmm0, [0x0056803C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56803Cu);
	// 0x26E080: movss [0x00568060], xmm0
	X86_MEM_WRITE_u32(base, 0x568060u, ctx.xmm[0].u32[0]);
	// 0x26E088: ret
	return;
}

void sub_26E090(X86Context& ctx, uint8_t* base) {
	// 0x26E090: movss xmm0, dword ptr [0x00568090]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568090u);
	// 0x26E098: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26E0A0: movss [0x0056804C], xmm0
	X86_MEM_WRITE_u32(base, 0x56804Cu, ctx.xmm[0].u32[0]);
	// 0x26E0A8: ret
	return;
}

void sub_26E0B0(X86Context& ctx, uint8_t* base) {
	// 0x26E0B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26E0B8: movss [0x00568038], xmm0
	X86_MEM_WRITE_u32(base, 0x568038u, ctx.xmm[0].u32[0]);
	// 0x26E0C0: ret
	return;
}

void sub_26E0D0(X86Context& ctx, uint8_t* base) {
	// 0x26E0D0: movss xmm0, dword ptr [0x0056804C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56804Cu);
	// 0x26E0D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26E0E0: movss [0x00568080], xmm0
	X86_MEM_WRITE_u32(base, 0x568080u, ctx.xmm[0].u32[0]);
	// 0x26E0E8: ret
	return;
}

void sub_26E0F0(X86Context& ctx, uint8_t* base) {
	// 0x26E0F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26E0F8: movss [0x00568054], xmm0
	X86_MEM_WRITE_u32(base, 0x568054u, ctx.xmm[0].u32[0]);
	// 0x26E100: ret
	return;
}

void sub_26E110(X86Context& ctx, uint8_t* base) {
	// 0x26E110: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26E118: movss [0x0056802C], xmm0
	X86_MEM_WRITE_u32(base, 0x56802Cu, ctx.xmm[0].u32[0]);
	// 0x26E120: ret
	return;
}

void sub_26E130(X86Context& ctx, uint8_t* base) {
	// 0x26E130: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26E138: movss [0x0056810C], xmm0
	X86_MEM_WRITE_u32(base, 0x56810Cu, ctx.xmm[0].u32[0]);
	// 0x26E140: ret
	return;
}

void sub_26E150(X86Context& ctx, uint8_t* base) {
	// 0x26E150: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26E158: movss [0x00568128], xmm0
	X86_MEM_WRITE_u32(base, 0x568128u, ctx.xmm[0].u32[0]);
	// 0x26E160: ret
	return;
}

void sub_26E170(X86Context& ctx, uint8_t* base) {
	// 0x26E170: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26E178: movss [0x005680FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5680FCu, ctx.xmm[0].u32[0]);
	// 0x26E180: ret
	return;
}

void sub_26E190(X86Context& ctx, uint8_t* base) {
	// 0x26E190: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26E198: movss [0x005680B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5680B0u, ctx.xmm[0].u32[0]);
	// 0x26E1A0: ret
	return;
}

void sub_26E1B0(X86Context& ctx, uint8_t* base) {
	// 0x26E1B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26E1B8: movss [0x00568110], xmm0
	X86_MEM_WRITE_u32(base, 0x568110u, ctx.xmm[0].u32[0]);
	// 0x26E1C0: ret
	return;
}

void sub_26E1D0(X86Context& ctx, uint8_t* base) {
	// 0x26E1D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26E1D8: movss [0x005680CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5680CCu, ctx.xmm[0].u32[0]);
	// 0x26E1E0: ret
	return;
}

void sub_26E1F0(X86Context& ctx, uint8_t* base) {
	// 0x26E1F0: movss xmm0, dword ptr [0x00568110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568110u);
	// 0x26E1F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26E200: movss [0x00568148], xmm0
	X86_MEM_WRITE_u32(base, 0x568148u, ctx.xmm[0].u32[0]);
	// 0x26E208: ret
	return;
}

void sub_26E210(X86Context& ctx, uint8_t* base) {
	// 0x26E210: movss xmm0, dword ptr [0x005680CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680CCu);
	// 0x26E218: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26E220: movss [0x00568130], xmm0
	X86_MEM_WRITE_u32(base, 0x568130u, ctx.xmm[0].u32[0]);
	// 0x26E228: ret
	return;
}

void sub_26E230(X86Context& ctx, uint8_t* base) {
	// 0x26E230: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26E238: movss [0x00568160], xmm0
	X86_MEM_WRITE_u32(base, 0x568160u, ctx.xmm[0].u32[0]);
	// 0x26E240: ret
	return;
}

void sub_26E250(X86Context& ctx, uint8_t* base) {
	// 0x26E250: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26E258: movss [0x0056814C], xmm0
	X86_MEM_WRITE_u32(base, 0x56814Cu, ctx.xmm[0].u32[0]);
	// 0x26E260: ret
	return;
}

void sub_26E270(X86Context& ctx, uint8_t* base) {
	// 0x26E270: movss xmm0, dword ptr [0x0056814C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56814Cu);
	// 0x26E278: movss [0x0056815C], xmm0
	X86_MEM_WRITE_u32(base, 0x56815Cu, ctx.xmm[0].u32[0]);
	// 0x26E280: ret
	return;
}

void sub_26E290(X86Context& ctx, uint8_t* base) {
	// 0x26E290: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26E298: movss [0x005680B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5680B8u, ctx.xmm[0].u32[0]);
	// 0x26E2A0: ret
	return;
}

void sub_26E2B0(X86Context& ctx, uint8_t* base) {
	// 0x26E2B0: movss xmm0, dword ptr [0x005680CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680CCu);
	// 0x26E2B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26E2C0: movss [0x00568154], xmm0
	X86_MEM_WRITE_u32(base, 0x568154u, ctx.xmm[0].u32[0]);
	// 0x26E2C8: ret
	return;
}

void sub_26E2D0(X86Context& ctx, uint8_t* base) {
	// 0x26E2D0: movss xmm0, dword ptr [0x005680CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680CCu);
	// 0x26E2D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26E2E0: movss [0x005680F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5680F8u, ctx.xmm[0].u32[0]);
	// 0x26E2E8: ret
	return;
}

void sub_26E2F0(X86Context& ctx, uint8_t* base) {
	// 0x26E2F0: movss xmm0, dword ptr [0x005680CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680CCu);
	// 0x26E2F8: subss xmm0, [0x005680F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5680F8u);
	// 0x26E300: movss [0x005680D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5680D4u, ctx.xmm[0].u32[0]);
	// 0x26E308: ret
	return;
}

void sub_26E310(X86Context& ctx, uint8_t* base) {
	// 0x26E310: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26E318: movss [0x00568124], xmm0
	X86_MEM_WRITE_u32(base, 0x568124u, ctx.xmm[0].u32[0]);
	// 0x26E320: ret
	return;
}

void sub_26E330(X86Context& ctx, uint8_t* base) {
	// 0x26E330: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26E338: movss [0x005680D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5680D0u, ctx.xmm[0].u32[0]);
	// 0x26E340: ret
	return;
}

void sub_26E350(X86Context& ctx, uint8_t* base) {
	// 0x26E350: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26E358: movss [0x005680E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5680E4u, ctx.xmm[0].u32[0]);
	// 0x26E360: ret
	return;
}

void sub_26E370(X86Context& ctx, uint8_t* base) {
	// 0x26E370: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26E378: movss [0x0056813C], xmm0
	X86_MEM_WRITE_u32(base, 0x56813Cu, ctx.xmm[0].u32[0]);
	// 0x26E380: ret
	return;
}

void sub_26E390(X86Context& ctx, uint8_t* base) {
	// 0x26E390: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26E398: movss [0x00568120], xmm0
	X86_MEM_WRITE_u32(base, 0x568120u, ctx.xmm[0].u32[0]);
	// 0x26E3A0: ret
	return;
}

void sub_26E3B0(X86Context& ctx, uint8_t* base) {
	// 0x26E3B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26E3B8: movss [0x005680C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5680C8u, ctx.xmm[0].u32[0]);
	// 0x26E3C0: ret
	return;
}

void sub_26E3D0(X86Context& ctx, uint8_t* base) {
	// 0x26E3D0: movss xmm0, dword ptr [0x005680E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680E4u);
	// 0x26E3D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26E3E0: movss [0x005680BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5680BCu, ctx.xmm[0].u32[0]);
	// 0x26E3E8: ret
	return;
}

void sub_26E3F0(X86Context& ctx, uint8_t* base) {
	// 0x26E3F0: movss xmm0, dword ptr [0x0056813C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56813Cu);
	// 0x26E3F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26E400: movss [0x00568104], xmm0
	X86_MEM_WRITE_u32(base, 0x568104u, ctx.xmm[0].u32[0]);
	// 0x26E408: ret
	return;
}

void sub_26E410(X86Context& ctx, uint8_t* base) {
	// 0x26E410: movss xmm0, dword ptr [0x005680BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680BCu);
	// 0x26E418: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26E420: movss [0x00568118], xmm0
	X86_MEM_WRITE_u32(base, 0x568118u, ctx.xmm[0].u32[0]);
	// 0x26E428: ret
	return;
}

void sub_26E430(X86Context& ctx, uint8_t* base) {
	// 0x26E430: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26E438: movss [0x005680B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5680B4u, ctx.xmm[0].u32[0]);
	// 0x26E440: ret
	return;
}

void sub_26E450(X86Context& ctx, uint8_t* base) {
	// 0x26E450: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26E458: movss [0x005680E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5680E8u, ctx.xmm[0].u32[0]);
	// 0x26E460: ret
	return;
}

void sub_26E470(X86Context& ctx, uint8_t* base) {
	// 0x26E470: movss xmm0, dword ptr [0x005680E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680E4u);
	// 0x26E478: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26E480: movss [0x005680F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5680F4u, ctx.xmm[0].u32[0]);
	// 0x26E488: ret
	return;
}

void sub_26E490(X86Context& ctx, uint8_t* base) {
	// 0x26E490: movss xmm0, dword ptr [0x0056813C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56813Cu);
	// 0x26E498: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26E4A0: movss [0x00568140], xmm0
	X86_MEM_WRITE_u32(base, 0x568140u, ctx.xmm[0].u32[0]);
	// 0x26E4A8: ret
	return;
}

void sub_26E4B0(X86Context& ctx, uint8_t* base) {
	// 0x26E4B0: movss xmm0, dword ptr [0x005680F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680F4u);
	// 0x26E4B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26E4C0: movss [0x0056812C], xmm0
	X86_MEM_WRITE_u32(base, 0x56812Cu, ctx.xmm[0].u32[0]);
	// 0x26E4C8: ret
	return;
}

void sub_26E4D0(X86Context& ctx, uint8_t* base) {
	// 0x26E4D0: movss xmm0, dword ptr [0x00568140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568140u);
	// 0x26E4D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26E4E0: movss [0x00568150], xmm0
	X86_MEM_WRITE_u32(base, 0x568150u, ctx.xmm[0].u32[0]);
	// 0x26E4E8: ret
	return;
}

void sub_26E4F0(X86Context& ctx, uint8_t* base) {
	// 0x26E4F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26E4F8: movss [0x005680C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5680C0u, ctx.xmm[0].u32[0]);
	// 0x26E500: ret
	return;
}

void sub_26E510(X86Context& ctx, uint8_t* base) {
	// 0x26E510: movss xmm0, dword ptr [0x005680E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680E4u);
	// 0x26E518: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26E520: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26E528: movss [0x00568138], xmm0
	X86_MEM_WRITE_u32(base, 0x568138u, ctx.xmm[0].u32[0]);
	// 0x26E530: ret
	return;
}

void sub_26E540(X86Context& ctx, uint8_t* base) {
	// 0x26E540: movss xmm0, dword ptr [0x0056813C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56813Cu);
	// 0x26E548: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26E550: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26E558: movss [0x005680D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5680D8u, ctx.xmm[0].u32[0]);
	// 0x26E560: ret
	return;
}

void sub_26E570(X86Context& ctx, uint8_t* base) {
	// 0x26E570: movss xmm0, dword ptr [0x005680E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680E4u);
	// 0x26E578: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26E580: movss [0x005680DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5680DCu, ctx.xmm[0].u32[0]);
	// 0x26E588: ret
	return;
}

void sub_26E590(X86Context& ctx, uint8_t* base) {
	// 0x26E590: movss xmm0, dword ptr [0x0056813C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56813Cu);
	// 0x26E598: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26E5A0: movss [0x00568144], xmm0
	X86_MEM_WRITE_u32(base, 0x568144u, ctx.xmm[0].u32[0]);
	// 0x26E5A8: ret
	return;
}

void sub_26E5B0(X86Context& ctx, uint8_t* base) {
	// 0x26E5B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26E5B8: movss [0x005680C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5680C4u, ctx.xmm[0].u32[0]);
	// 0x26E5C0: ret
	return;
}

void sub_26E5D0(X86Context& ctx, uint8_t* base) {
	// 0x26E5D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26E5D8: movss [0x005680F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5680F0u, ctx.xmm[0].u32[0]);
	// 0x26E5E0: ret
	return;
}

void sub_26E5F0(X86Context& ctx, uint8_t* base) {
	// 0x26E5F0: movss xmm0, dword ptr [0x005680C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5680C4u);
	// 0x26E5F8: movss [0x00568158], xmm0
	X86_MEM_WRITE_u32(base, 0x568158u, ctx.xmm[0].u32[0]);
	// 0x26E600: ret
	return;
}

void sub_26E610(X86Context& ctx, uint8_t* base) {
	// 0x26E610: movss xmm0, dword ptr [0x0056813C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56813Cu);
	// 0x26E618: subss xmm0, [0x005680C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5680C4u);
	// 0x26E620: movss [0x0056811C], xmm0
	X86_MEM_WRITE_u32(base, 0x56811Cu, ctx.xmm[0].u32[0]);
	// 0x26E628: ret
	return;
}

void sub_26E630(X86Context& ctx, uint8_t* base) {
	// 0x26E630: movss xmm0, dword ptr [0x0056811C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56811Cu);
	// 0x26E638: subss xmm0, [0x005680F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5680F0u);
	// 0x26E640: movss [0x00568114], xmm0
	X86_MEM_WRITE_u32(base, 0x568114u, ctx.xmm[0].u32[0]);
	// 0x26E648: ret
	return;
}

void sub_26E650(X86Context& ctx, uint8_t* base) {
	// 0x26E650: movss xmm0, dword ptr [0x00568144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568144u);
	// 0x26E658: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26E660: movss [0x00568100], xmm0
	X86_MEM_WRITE_u32(base, 0x568100u, ctx.xmm[0].u32[0]);
	// 0x26E668: ret
	return;
}

void sub_26E670(X86Context& ctx, uint8_t* base) {
	// 0x26E670: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26E678: movss [0x005680EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5680ECu, ctx.xmm[0].u32[0]);
	// 0x26E680: ret
	return;
}

void sub_26E690(X86Context& ctx, uint8_t* base) {
	// 0x26E690: movss xmm0, dword ptr [0x00568100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568100u);
	// 0x26E698: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26E6A0: movss [0x00568134], xmm0
	X86_MEM_WRITE_u32(base, 0x568134u, ctx.xmm[0].u32[0]);
	// 0x26E6A8: ret
	return;
}

void sub_26E6B0(X86Context& ctx, uint8_t* base) {
	// 0x26E6B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26E6B8: movss [0x00568108], xmm0
	X86_MEM_WRITE_u32(base, 0x568108u, ctx.xmm[0].u32[0]);
	// 0x26E6C0: ret
	return;
}

void sub_26E6D0(X86Context& ctx, uint8_t* base) {
	// 0x26E6D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26E6D8: movss [0x005680E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5680E0u, ctx.xmm[0].u32[0]);
	// 0x26E6E0: ret
	return;
}

void sub_26E6F0(X86Context& ctx, uint8_t* base) {
	// 0x26E6F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26E6F8: movss [0x005681C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5681C0u, ctx.xmm[0].u32[0]);
	// 0x26E700: ret
	return;
}

void sub_26E710(X86Context& ctx, uint8_t* base) {
	// 0x26E710: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26E718: movss [0x005681DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5681DCu, ctx.xmm[0].u32[0]);
	// 0x26E720: ret
	return;
}

void sub_26E730(X86Context& ctx, uint8_t* base) {
	// 0x26E730: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26E738: movss [0x005681B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5681B0u, ctx.xmm[0].u32[0]);
	// 0x26E740: ret
	return;
}

void sub_26E750(X86Context& ctx, uint8_t* base) {
	// 0x26E750: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26E758: movss [0x00568164], xmm0
	X86_MEM_WRITE_u32(base, 0x568164u, ctx.xmm[0].u32[0]);
	// 0x26E760: ret
	return;
}

void sub_26E770(X86Context& ctx, uint8_t* base) {
	// 0x26E770: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26E778: movss [0x005681C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5681C4u, ctx.xmm[0].u32[0]);
	// 0x26E780: ret
	return;
}

void sub_26E790(X86Context& ctx, uint8_t* base) {
	// 0x26E790: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26E798: movss [0x00568180], xmm0
	X86_MEM_WRITE_u32(base, 0x568180u, ctx.xmm[0].u32[0]);
	// 0x26E7A0: ret
	return;
}

void sub_26E7B0(X86Context& ctx, uint8_t* base) {
	// 0x26E7B0: movss xmm0, dword ptr [0x005681C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681C4u);
	// 0x26E7B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26E7C0: movss [0x005681FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5681FCu, ctx.xmm[0].u32[0]);
	// 0x26E7C8: ret
	return;
}

void sub_26E7D0(X86Context& ctx, uint8_t* base) {
	// 0x26E7D0: movss xmm0, dword ptr [0x00568180]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568180u);
	// 0x26E7D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26E7E0: movss [0x005681E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5681E4u, ctx.xmm[0].u32[0]);
	// 0x26E7E8: ret
	return;
}

void sub_26E7F0(X86Context& ctx, uint8_t* base) {
	// 0x26E7F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26E7F8: movss [0x00568214], xmm0
	X86_MEM_WRITE_u32(base, 0x568214u, ctx.xmm[0].u32[0]);
	// 0x26E800: ret
	return;
}

void sub_26E810(X86Context& ctx, uint8_t* base) {
	// 0x26E810: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26E818: movss [0x00568200], xmm0
	X86_MEM_WRITE_u32(base, 0x568200u, ctx.xmm[0].u32[0]);
	// 0x26E820: ret
	return;
}

void sub_26E830(X86Context& ctx, uint8_t* base) {
	// 0x26E830: movss xmm0, dword ptr [0x00568200]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568200u);
	// 0x26E838: movss [0x00568210], xmm0
	X86_MEM_WRITE_u32(base, 0x568210u, ctx.xmm[0].u32[0]);
	// 0x26E840: ret
	return;
}

void sub_26E850(X86Context& ctx, uint8_t* base) {
	// 0x26E850: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26E858: movss [0x0056816C], xmm0
	X86_MEM_WRITE_u32(base, 0x56816Cu, ctx.xmm[0].u32[0]);
	// 0x26E860: ret
	return;
}

void sub_26E870(X86Context& ctx, uint8_t* base) {
	// 0x26E870: movss xmm0, dword ptr [0x00568180]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568180u);
	// 0x26E878: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26E880: movss [0x00568208], xmm0
	X86_MEM_WRITE_u32(base, 0x568208u, ctx.xmm[0].u32[0]);
	// 0x26E888: ret
	return;
}

void sub_26E890(X86Context& ctx, uint8_t* base) {
	// 0x26E890: movss xmm0, dword ptr [0x00568180]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568180u);
	// 0x26E898: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26E8A0: movss [0x005681AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5681ACu, ctx.xmm[0].u32[0]);
	// 0x26E8A8: ret
	return;
}

void sub_26E8B0(X86Context& ctx, uint8_t* base) {
	// 0x26E8B0: movss xmm0, dword ptr [0x00568180]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568180u);
	// 0x26E8B8: subss xmm0, [0x005681AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5681ACu);
	// 0x26E8C0: movss [0x00568188], xmm0
	X86_MEM_WRITE_u32(base, 0x568188u, ctx.xmm[0].u32[0]);
	// 0x26E8C8: ret
	return;
}

void sub_26E8D0(X86Context& ctx, uint8_t* base) {
	// 0x26E8D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26E8D8: movss [0x005681D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5681D8u, ctx.xmm[0].u32[0]);
	// 0x26E8E0: ret
	return;
}

void sub_26E8F0(X86Context& ctx, uint8_t* base) {
	// 0x26E8F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26E8F8: movss [0x00568184], xmm0
	X86_MEM_WRITE_u32(base, 0x568184u, ctx.xmm[0].u32[0]);
	// 0x26E900: ret
	return;
}

void sub_26E910(X86Context& ctx, uint8_t* base) {
	// 0x26E910: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26E918: movss [0x00568198], xmm0
	X86_MEM_WRITE_u32(base, 0x568198u, ctx.xmm[0].u32[0]);
	// 0x26E920: ret
	return;
}

void sub_26E930(X86Context& ctx, uint8_t* base) {
	// 0x26E930: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26E938: movss [0x005681F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5681F0u, ctx.xmm[0].u32[0]);
	// 0x26E940: ret
	return;
}

void sub_26E950(X86Context& ctx, uint8_t* base) {
	// 0x26E950: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26E958: movss [0x005681D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5681D4u, ctx.xmm[0].u32[0]);
	// 0x26E960: ret
	return;
}

void sub_26E970(X86Context& ctx, uint8_t* base) {
	// 0x26E970: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26E978: movss [0x0056817C], xmm0
	X86_MEM_WRITE_u32(base, 0x56817Cu, ctx.xmm[0].u32[0]);
	// 0x26E980: ret
	return;
}

void sub_26E990(X86Context& ctx, uint8_t* base) {
	// 0x26E990: movss xmm0, dword ptr [0x00568198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568198u);
	// 0x26E998: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26E9A0: movss [0x00568170], xmm0
	X86_MEM_WRITE_u32(base, 0x568170u, ctx.xmm[0].u32[0]);
	// 0x26E9A8: ret
	return;
}

void sub_26E9B0(X86Context& ctx, uint8_t* base) {
	// 0x26E9B0: movss xmm0, dword ptr [0x005681F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F0u);
	// 0x26E9B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26E9C0: movss [0x005681B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5681B8u, ctx.xmm[0].u32[0]);
	// 0x26E9C8: ret
	return;
}

void sub_26E9D0(X86Context& ctx, uint8_t* base) {
	// 0x26E9D0: movss xmm0, dword ptr [0x00568170]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568170u);
	// 0x26E9D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26E9E0: movss [0x005681CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5681CCu, ctx.xmm[0].u32[0]);
	// 0x26E9E8: ret
	return;
}

void sub_26E9F0(X86Context& ctx, uint8_t* base) {
	// 0x26E9F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26E9F8: movss [0x00568168], xmm0
	X86_MEM_WRITE_u32(base, 0x568168u, ctx.xmm[0].u32[0]);
	// 0x26EA00: ret
	return;
}

void sub_26EA10(X86Context& ctx, uint8_t* base) {
	// 0x26EA10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26EA18: movss [0x0056819C], xmm0
	X86_MEM_WRITE_u32(base, 0x56819Cu, ctx.xmm[0].u32[0]);
	// 0x26EA20: ret
	return;
}

void sub_26EA30(X86Context& ctx, uint8_t* base) {
	// 0x26EA30: movss xmm0, dword ptr [0x00568198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568198u);
	// 0x26EA38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26EA40: movss [0x005681A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5681A8u, ctx.xmm[0].u32[0]);
	// 0x26EA48: ret
	return;
}

void sub_26EA50(X86Context& ctx, uint8_t* base) {
	// 0x26EA50: movss xmm0, dword ptr [0x005681F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F0u);
	// 0x26EA58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26EA60: movss [0x005681F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5681F4u, ctx.xmm[0].u32[0]);
	// 0x26EA68: ret
	return;
}

void sub_26EA70(X86Context& ctx, uint8_t* base) {
	// 0x26EA70: movss xmm0, dword ptr [0x005681A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681A8u);
	// 0x26EA78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26EA80: movss [0x005681E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5681E0u, ctx.xmm[0].u32[0]);
	// 0x26EA88: ret
	return;
}

void sub_26EA90(X86Context& ctx, uint8_t* base) {
	// 0x26EA90: movss xmm0, dword ptr [0x005681F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F4u);
	// 0x26EA98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26EAA0: movss [0x00568204], xmm0
	X86_MEM_WRITE_u32(base, 0x568204u, ctx.xmm[0].u32[0]);
	// 0x26EAA8: ret
	return;
}

void sub_26EAB0(X86Context& ctx, uint8_t* base) {
	// 0x26EAB0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26EAB8: movss [0x00568174], xmm0
	X86_MEM_WRITE_u32(base, 0x568174u, ctx.xmm[0].u32[0]);
	// 0x26EAC0: ret
	return;
}

void sub_26EAD0(X86Context& ctx, uint8_t* base) {
	// 0x26EAD0: movss xmm0, dword ptr [0x00568198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568198u);
	// 0x26EAD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26EAE0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26EAE8: movss [0x005681EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5681ECu, ctx.xmm[0].u32[0]);
	// 0x26EAF0: ret
	return;
}

void sub_26EB00(X86Context& ctx, uint8_t* base) {
	// 0x26EB00: movss xmm0, dword ptr [0x005681F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F0u);
	// 0x26EB08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26EB10: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26EB18: movss [0x0056818C], xmm0
	X86_MEM_WRITE_u32(base, 0x56818Cu, ctx.xmm[0].u32[0]);
	// 0x26EB20: ret
	return;
}

void sub_26EB30(X86Context& ctx, uint8_t* base) {
	// 0x26EB30: movss xmm0, dword ptr [0x00568198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568198u);
	// 0x26EB38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26EB40: movss [0x00568190], xmm0
	X86_MEM_WRITE_u32(base, 0x568190u, ctx.xmm[0].u32[0]);
	// 0x26EB48: ret
	return;
}

void sub_26EB50(X86Context& ctx, uint8_t* base) {
	// 0x26EB50: movss xmm0, dword ptr [0x005681F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F0u);
	// 0x26EB58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26EB60: movss [0x005681F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5681F8u, ctx.xmm[0].u32[0]);
	// 0x26EB68: ret
	return;
}

void sub_26EB70(X86Context& ctx, uint8_t* base) {
	// 0x26EB70: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26EB78: movss [0x00568178], xmm0
	X86_MEM_WRITE_u32(base, 0x568178u, ctx.xmm[0].u32[0]);
	// 0x26EB80: ret
	return;
}

void sub_26EB90(X86Context& ctx, uint8_t* base) {
	// 0x26EB90: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26EB98: movss [0x005681A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5681A4u, ctx.xmm[0].u32[0]);
	// 0x26EBA0: ret
	return;
}

void sub_26EBB0(X86Context& ctx, uint8_t* base) {
	// 0x26EBB0: movss xmm0, dword ptr [0x00568178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568178u);
	// 0x26EBB8: movss [0x0056820C], xmm0
	X86_MEM_WRITE_u32(base, 0x56820Cu, ctx.xmm[0].u32[0]);
	// 0x26EBC0: ret
	return;
}

void sub_26EBD0(X86Context& ctx, uint8_t* base) {
	// 0x26EBD0: movss xmm0, dword ptr [0x005681F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F0u);
	// 0x26EBD8: subss xmm0, [0x00568178]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568178u);
	// 0x26EBE0: movss [0x005681D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5681D0u, ctx.xmm[0].u32[0]);
	// 0x26EBE8: ret
	return;
}

void sub_26EBF0(X86Context& ctx, uint8_t* base) {
	// 0x26EBF0: movss xmm0, dword ptr [0x005681D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681D0u);
	// 0x26EBF8: subss xmm0, [0x005681A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5681A4u);
	// 0x26EC00: movss [0x005681C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5681C8u, ctx.xmm[0].u32[0]);
	// 0x26EC08: ret
	return;
}

void sub_26EC10(X86Context& ctx, uint8_t* base) {
	// 0x26EC10: movss xmm0, dword ptr [0x005681F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681F8u);
	// 0x26EC18: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26EC20: movss [0x005681B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5681B4u, ctx.xmm[0].u32[0]);
	// 0x26EC28: ret
	return;
}

void sub_26EC30(X86Context& ctx, uint8_t* base) {
	// 0x26EC30: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26EC38: movss [0x005681A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5681A0u, ctx.xmm[0].u32[0]);
	// 0x26EC40: ret
	return;
}

void sub_26EC50(X86Context& ctx, uint8_t* base) {
	// 0x26EC50: movss xmm0, dword ptr [0x005681B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5681B4u);
	// 0x26EC58: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26EC60: movss [0x005681E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5681E8u, ctx.xmm[0].u32[0]);
	// 0x26EC68: ret
	return;
}

void sub_26EC70(X86Context& ctx, uint8_t* base) {
	// 0x26EC70: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26EC78: movss [0x005681BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5681BCu, ctx.xmm[0].u32[0]);
	// 0x26EC80: ret
	return;
}

void sub_26EC90(X86Context& ctx, uint8_t* base) {
	// 0x26EC90: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26EC98: movss [0x00568194], xmm0
	X86_MEM_WRITE_u32(base, 0x568194u, ctx.xmm[0].u32[0]);
	// 0x26ECA0: ret
	return;
}

void sub_26ECB0(X86Context& ctx, uint8_t* base) {
	// 0x26ECB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26ECB8: movss [0x00568274], xmm0
	X86_MEM_WRITE_u32(base, 0x568274u, ctx.xmm[0].u32[0]);
	// 0x26ECC0: ret
	return;
}

void sub_26ECD0(X86Context& ctx, uint8_t* base) {
	// 0x26ECD0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26ECD8: movss [0x00568290], xmm0
	X86_MEM_WRITE_u32(base, 0x568290u, ctx.xmm[0].u32[0]);
	// 0x26ECE0: ret
	return;
}

void sub_26ECF0(X86Context& ctx, uint8_t* base) {
	// 0x26ECF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26ECF8: movss [0x00568264], xmm0
	X86_MEM_WRITE_u32(base, 0x568264u, ctx.xmm[0].u32[0]);
	// 0x26ED00: ret
	return;
}

void sub_26ED10(X86Context& ctx, uint8_t* base) {
	// 0x26ED10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26ED18: movss [0x00568218], xmm0
	X86_MEM_WRITE_u32(base, 0x568218u, ctx.xmm[0].u32[0]);
	// 0x26ED20: ret
	return;
}

void sub_26ED30(X86Context& ctx, uint8_t* base) {
	// 0x26ED30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26ED38: movss [0x00568278], xmm0
	X86_MEM_WRITE_u32(base, 0x568278u, ctx.xmm[0].u32[0]);
	// 0x26ED40: ret
	return;
}

void sub_26ED50(X86Context& ctx, uint8_t* base) {
	// 0x26ED50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26ED58: movss [0x00568234], xmm0
	X86_MEM_WRITE_u32(base, 0x568234u, ctx.xmm[0].u32[0]);
	// 0x26ED60: ret
	return;
}

void sub_26ED70(X86Context& ctx, uint8_t* base) {
	// 0x26ED70: movss xmm0, dword ptr [0x00568278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568278u);
	// 0x26ED78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26ED80: movss [0x005682B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5682B0u, ctx.xmm[0].u32[0]);
	// 0x26ED88: ret
	return;
}

void sub_26ED90(X86Context& ctx, uint8_t* base) {
	// 0x26ED90: movss xmm0, dword ptr [0x00568234]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568234u);
	// 0x26ED98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26EDA0: movss [0x00568298], xmm0
	X86_MEM_WRITE_u32(base, 0x568298u, ctx.xmm[0].u32[0]);
	// 0x26EDA8: ret
	return;
}

void sub_26EDB0(X86Context& ctx, uint8_t* base) {
	// 0x26EDB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26EDB8: movss [0x005682C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5682C8u, ctx.xmm[0].u32[0]);
	// 0x26EDC0: ret
	return;
}

void sub_26EDD0(X86Context& ctx, uint8_t* base) {
	// 0x26EDD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26EDD8: movss [0x005682B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5682B4u, ctx.xmm[0].u32[0]);
	// 0x26EDE0: ret
	return;
}

void sub_26EDF0(X86Context& ctx, uint8_t* base) {
	// 0x26EDF0: movss xmm0, dword ptr [0x005682B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682B4u);
	// 0x26EDF8: movss [0x005682C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5682C4u, ctx.xmm[0].u32[0]);
	// 0x26EE00: ret
	return;
}

void sub_26EE10(X86Context& ctx, uint8_t* base) {
	// 0x26EE10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26EE18: movss [0x00568220], xmm0
	X86_MEM_WRITE_u32(base, 0x568220u, ctx.xmm[0].u32[0]);
	// 0x26EE20: ret
	return;
}

void sub_26EE30(X86Context& ctx, uint8_t* base) {
	// 0x26EE30: movss xmm0, dword ptr [0x00568234]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568234u);
	// 0x26EE38: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26EE40: movss [0x005682BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5682BCu, ctx.xmm[0].u32[0]);
	// 0x26EE48: ret
	return;
}

void sub_26EE50(X86Context& ctx, uint8_t* base) {
	// 0x26EE50: movss xmm0, dword ptr [0x00568234]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568234u);
	// 0x26EE58: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26EE60: movss [0x00568260], xmm0
	X86_MEM_WRITE_u32(base, 0x568260u, ctx.xmm[0].u32[0]);
	// 0x26EE68: ret
	return;
}

void sub_26EE70(X86Context& ctx, uint8_t* base) {
	// 0x26EE70: movss xmm0, dword ptr [0x00568234]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568234u);
	// 0x26EE78: subss xmm0, [0x00568260]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568260u);
	// 0x26EE80: movss [0x0056823C], xmm0
	X86_MEM_WRITE_u32(base, 0x56823Cu, ctx.xmm[0].u32[0]);
	// 0x26EE88: ret
	return;
}

void sub_26EE90(X86Context& ctx, uint8_t* base) {
	// 0x26EE90: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26EE98: movss [0x0056828C], xmm0
	X86_MEM_WRITE_u32(base, 0x56828Cu, ctx.xmm[0].u32[0]);
	// 0x26EEA0: ret
	return;
}

void sub_26EEB0(X86Context& ctx, uint8_t* base) {
	// 0x26EEB0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26EEB8: movss [0x00568238], xmm0
	X86_MEM_WRITE_u32(base, 0x568238u, ctx.xmm[0].u32[0]);
	// 0x26EEC0: ret
	return;
}

void sub_26EED0(X86Context& ctx, uint8_t* base) {
	// 0x26EED0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26EED8: movss [0x0056824C], xmm0
	X86_MEM_WRITE_u32(base, 0x56824Cu, ctx.xmm[0].u32[0]);
	// 0x26EEE0: ret
	return;
}

void sub_26EEF0(X86Context& ctx, uint8_t* base) {
	// 0x26EEF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26EEF8: movss [0x005682A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5682A4u, ctx.xmm[0].u32[0]);
	// 0x26EF00: ret
	return;
}

void sub_26EF10(X86Context& ctx, uint8_t* base) {
	// 0x26EF10: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26EF18: movss [0x00568288], xmm0
	X86_MEM_WRITE_u32(base, 0x568288u, ctx.xmm[0].u32[0]);
	// 0x26EF20: ret
	return;
}

void sub_26EF30(X86Context& ctx, uint8_t* base) {
	// 0x26EF30: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26EF38: movss [0x00568230], xmm0
	X86_MEM_WRITE_u32(base, 0x568230u, ctx.xmm[0].u32[0]);
	// 0x26EF40: ret
	return;
}

void sub_26EF50(X86Context& ctx, uint8_t* base) {
	// 0x26EF50: movss xmm0, dword ptr [0x0056824C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56824Cu);
	// 0x26EF58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26EF60: movss [0x00568224], xmm0
	X86_MEM_WRITE_u32(base, 0x568224u, ctx.xmm[0].u32[0]);
	// 0x26EF68: ret
	return;
}

void sub_26EF70(X86Context& ctx, uint8_t* base) {
	// 0x26EF70: movss xmm0, dword ptr [0x005682A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682A4u);
	// 0x26EF78: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26EF80: movss [0x0056826C], xmm0
	X86_MEM_WRITE_u32(base, 0x56826Cu, ctx.xmm[0].u32[0]);
	// 0x26EF88: ret
	return;
}

void sub_26EF90(X86Context& ctx, uint8_t* base) {
	// 0x26EF90: movss xmm0, dword ptr [0x00568224]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568224u);
	// 0x26EF98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26EFA0: movss [0x00568280], xmm0
	X86_MEM_WRITE_u32(base, 0x568280u, ctx.xmm[0].u32[0]);
	// 0x26EFA8: ret
	return;
}

void sub_26EFB0(X86Context& ctx, uint8_t* base) {
	// 0x26EFB0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26EFB8: movss [0x0056821C], xmm0
	X86_MEM_WRITE_u32(base, 0x56821Cu, ctx.xmm[0].u32[0]);
	// 0x26EFC0: ret
	return;
}

void sub_26EFD0(X86Context& ctx, uint8_t* base) {
	// 0x26EFD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26EFD8: movss [0x00568250], xmm0
	X86_MEM_WRITE_u32(base, 0x568250u, ctx.xmm[0].u32[0]);
	// 0x26EFE0: ret
	return;
}

void sub_26EFF0(X86Context& ctx, uint8_t* base) {
	// 0x26EFF0: movss xmm0, dword ptr [0x0056824C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56824Cu);
	// 0x26EFF8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26F000: movss [0x0056825C], xmm0
	X86_MEM_WRITE_u32(base, 0x56825Cu, ctx.xmm[0].u32[0]);
	// 0x26F008: ret
	return;
}

void sub_26F010(X86Context& ctx, uint8_t* base) {
	// 0x26F010: movss xmm0, dword ptr [0x005682A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682A4u);
	// 0x26F018: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26F020: movss [0x005682A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5682A8u, ctx.xmm[0].u32[0]);
	// 0x26F028: ret
	return;
}

void sub_26F030(X86Context& ctx, uint8_t* base) {
	// 0x26F030: movss xmm0, dword ptr [0x0056825C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56825Cu);
	// 0x26F038: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F040: movss [0x00568294], xmm0
	X86_MEM_WRITE_u32(base, 0x568294u, ctx.xmm[0].u32[0]);
	// 0x26F048: ret
	return;
}

void sub_26F050(X86Context& ctx, uint8_t* base) {
	// 0x26F050: movss xmm0, dword ptr [0x005682A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682A8u);
	// 0x26F058: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F060: movss [0x005682B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5682B8u, ctx.xmm[0].u32[0]);
	// 0x26F068: ret
	return;
}

void sub_26F070(X86Context& ctx, uint8_t* base) {
	// 0x26F070: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26F078: movss [0x00568228], xmm0
	X86_MEM_WRITE_u32(base, 0x568228u, ctx.xmm[0].u32[0]);
	// 0x26F080: ret
	return;
}

void sub_26F090(X86Context& ctx, uint8_t* base) {
	// 0x26F090: movss xmm0, dword ptr [0x0056824C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56824Cu);
	// 0x26F098: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F0A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26F0A8: movss [0x005682A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5682A0u, ctx.xmm[0].u32[0]);
	// 0x26F0B0: ret
	return;
}

void sub_26F0C0(X86Context& ctx, uint8_t* base) {
	// 0x26F0C0: movss xmm0, dword ptr [0x005682A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682A4u);
	// 0x26F0C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F0D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26F0D8: movss [0x00568240], xmm0
	X86_MEM_WRITE_u32(base, 0x568240u, ctx.xmm[0].u32[0]);
	// 0x26F0E0: ret
	return;
}

void sub_26F0F0(X86Context& ctx, uint8_t* base) {
	// 0x26F0F0: movss xmm0, dword ptr [0x0056824C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56824Cu);
	// 0x26F0F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F100: movss [0x00568244], xmm0
	X86_MEM_WRITE_u32(base, 0x568244u, ctx.xmm[0].u32[0]);
	// 0x26F108: ret
	return;
}

void sub_26F110(X86Context& ctx, uint8_t* base) {
	// 0x26F110: movss xmm0, dword ptr [0x005682A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5682A4u);
	// 0x26F118: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26F120: movss [0x005682AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5682ACu, ctx.xmm[0].u32[0]);
	// 0x26F128: ret
	return;
}

void sub_26F130(X86Context& ctx, uint8_t* base) {
	// 0x26F130: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26F138: movss [0x0056822C], xmm0
	X86_MEM_WRITE_u32(base, 0x56822Cu, ctx.xmm[0].u32[0]);
	// 0x26F140: ret
	return;
}

