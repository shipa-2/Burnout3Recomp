#include "x86_recomp_shared.h"

void sub_2C34E0(X86Context& ctx, uint8_t* base) {
	// 0x2C34E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C34E8: movss [0x005A9244], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9244u, ctx.xmm[0].u32[0]);
	// 0x2C34F0: ret
	return;
}

void sub_2C3500(X86Context& ctx, uint8_t* base) {
	// 0x2C3500: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C3508: movss [0x005A923C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A923Cu, ctx.xmm[0].u32[0]);
	// 0x2C3510: ret
	return;
}

void sub_2C3520(X86Context& ctx, uint8_t* base) {
	// 0x2C3520: movss xmm0, dword ptr [0x005A923C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A923Cu);
	// 0x2C3528: movss [0x005A9240], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9240u, ctx.xmm[0].u32[0]);
	// 0x2C3530: ret
	return;
}

void sub_2C3540(X86Context& ctx, uint8_t* base) {
	// 0x2C3540: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3548: movss [0x005A9218], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9218u, ctx.xmm[0].u32[0]);
	// 0x2C3550: ret
	return;
}

void sub_2C3560(X86Context& ctx, uint8_t* base) {
	// 0x2C3560: movss xmm0, dword ptr [0x005A9220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9220u);
	// 0x2C3568: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C3570: movss [0x005A9214], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9214u, ctx.xmm[0].u32[0]);
	// 0x2C3578: ret
	return;
}

void sub_2C3580(X86Context& ctx, uint8_t* base) {
	// 0x2C3580: movss xmm0, dword ptr [0x005A9220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9220u);
	// 0x2C3588: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C3590: movss [0x005A922C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A922Cu, ctx.xmm[0].u32[0]);
	// 0x2C3598: ret
	return;
}

void sub_2C35A0(X86Context& ctx, uint8_t* base) {
	// 0x2C35A0: movss xmm0, dword ptr [0x005A9220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9220u);
	// 0x2C35A8: subss xmm0, [0x005A922C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A922Cu);
	// 0x2C35B0: movss [0x005A920C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A920Cu, ctx.xmm[0].u32[0]);
	// 0x2C35B8: ret
	return;
}

void sub_2C35C0(X86Context& ctx, uint8_t* base) {
	// 0x2C35C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C35C8: movss [0x005A9264], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9264u, ctx.xmm[0].u32[0]);
	// 0x2C35D0: ret
	return;
}

void sub_2C35E0(X86Context& ctx, uint8_t* base) {
	// 0x2C35E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C35E8: movss [0x005A9270], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9270u, ctx.xmm[0].u32[0]);
	// 0x2C35F0: ret
	return;
}

void sub_2C3600(X86Context& ctx, uint8_t* base) {
	// 0x2C3600: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C3608: movss [0x005A9260], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9260u, ctx.xmm[0].u32[0]);
	// 0x2C3610: ret
	return;
}

void sub_2C3620(X86Context& ctx, uint8_t* base) {
	// 0x2C3620: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C3628: movss [0x005A9248], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9248u, ctx.xmm[0].u32[0]);
	// 0x2C3630: ret
	return;
}

void sub_2C3640(X86Context& ctx, uint8_t* base) {
	// 0x2C3640: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C3648: movss [0x005A9268], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9268u, ctx.xmm[0].u32[0]);
	// 0x2C3650: ret
	return;
}

void sub_2C3660(X86Context& ctx, uint8_t* base) {
	// 0x2C3660: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3668: movss [0x005A9250], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9250u, ctx.xmm[0].u32[0]);
	// 0x2C3670: ret
	return;
}

void sub_2C3680(X86Context& ctx, uint8_t* base) {
	// 0x2C3680: movss xmm0, dword ptr [0x005A9268]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9268u);
	// 0x2C3688: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C3690: movss [0x005A927C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A927Cu, ctx.xmm[0].u32[0]);
	// 0x2C3698: ret
	return;
}

void sub_2C36A0(X86Context& ctx, uint8_t* base) {
	// 0x2C36A0: movss xmm0, dword ptr [0x005A9250]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9250u);
	// 0x2C36A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C36B0: movss [0x005A9274], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9274u, ctx.xmm[0].u32[0]);
	// 0x2C36B8: ret
	return;
}

void sub_2C36C0(X86Context& ctx, uint8_t* base) {
	// 0x2C36C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C36C8: movss [0x005A9290], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9290u, ctx.xmm[0].u32[0]);
	// 0x2C36D0: ret
	return;
}

void sub_2C36E0(X86Context& ctx, uint8_t* base) {
	// 0x2C36E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C36E8: movss [0x005A9280], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9280u, ctx.xmm[0].u32[0]);
	// 0x2C36F0: ret
	return;
}

void sub_2C3700(X86Context& ctx, uint8_t* base) {
	// 0x2C3700: movss xmm0, dword ptr [0x005A9280]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9280u);
	// 0x2C3708: movss [0x005A928C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A928Cu, ctx.xmm[0].u32[0]);
	// 0x2C3710: ret
	return;
}

void sub_2C3720(X86Context& ctx, uint8_t* base) {
	// 0x2C3720: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3728: movss [0x005A924C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A924Cu, ctx.xmm[0].u32[0]);
	// 0x2C3730: ret
	return;
}

void sub_2C3740(X86Context& ctx, uint8_t* base) {
	// 0x2C3740: movss xmm0, dword ptr [0x005A9250]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9250u);
	// 0x2C3748: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C3750: movss [0x005A9284], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9284u, ctx.xmm[0].u32[0]);
	// 0x2C3758: ret
	return;
}

void sub_2C3760(X86Context& ctx, uint8_t* base) {
	// 0x2C3760: movss xmm0, dword ptr [0x005A9250]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9250u);
	// 0x2C3768: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C3770: movss [0x005A925C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A925Cu, ctx.xmm[0].u32[0]);
	// 0x2C3778: ret
	return;
}

void sub_2C3780(X86Context& ctx, uint8_t* base) {
	// 0x2C3780: movss xmm0, dword ptr [0x005A9250]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9250u);
	// 0x2C3788: subss xmm0, [0x005A925C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A925Cu);
	// 0x2C3790: movss [0x005A9258], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9258u, ctx.xmm[0].u32[0]);
	// 0x2C3798: ret
	return;
}

void sub_2C37A0(X86Context& ctx, uint8_t* base) {
	// 0x2C37A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C37A8: movss [0x005A926C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A926Cu, ctx.xmm[0].u32[0]);
	// 0x2C37B0: ret
	return;
}

void sub_2C37C0(X86Context& ctx, uint8_t* base) {
	// 0x2C37C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C37C8: movss [0x005A9254], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9254u, ctx.xmm[0].u32[0]);
	// 0x2C37D0: ret
	return;
}

void sub_2C37E0(X86Context& ctx, uint8_t* base) {
	// 0x2C37E0: movss xmm0, dword ptr [0x003B1F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F64u);
	// 0x2C37E8: movss [0x005A9278], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9278u, ctx.xmm[0].u32[0]);
	// 0x2C37F0: ret
	return;
}

void sub_2C3800(X86Context& ctx, uint8_t* base) {
	// 0x2C3800: movss xmm0, dword ptr [0x003A7ED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7ED8u);
	// 0x2C3808: movss [0x005A9288], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9288u, ctx.xmm[0].u32[0]);
	// 0x2C3810: ret
	return;
}

void sub_2C3820(X86Context& ctx, uint8_t* base) {
	// 0x2C3820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C3828: movss [0x005A92B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92B0u, ctx.xmm[0].u32[0]);
	// 0x2C3830: ret
	return;
}

void sub_2C3840(X86Context& ctx, uint8_t* base) {
	// 0x2C3840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C3848: movss [0x005A92BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92BCu, ctx.xmm[0].u32[0]);
	// 0x2C3850: ret
	return;
}

void sub_2C3860(X86Context& ctx, uint8_t* base) {
	// 0x2C3860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C3868: movss [0x005A92AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92ACu, ctx.xmm[0].u32[0]);
	// 0x2C3870: ret
	return;
}

void sub_2C3880(X86Context& ctx, uint8_t* base) {
	// 0x2C3880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C3888: movss [0x005A9294], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9294u, ctx.xmm[0].u32[0]);
	// 0x2C3890: ret
	return;
}

void sub_2C38A0(X86Context& ctx, uint8_t* base) {
	// 0x2C38A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C38A8: movss [0x005A92B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92B4u, ctx.xmm[0].u32[0]);
	// 0x2C38B0: ret
	return;
}

void sub_2C38C0(X86Context& ctx, uint8_t* base) {
	// 0x2C38C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C38C8: movss [0x005A929C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A929Cu, ctx.xmm[0].u32[0]);
	// 0x2C38D0: ret
	return;
}

void sub_2C38E0(X86Context& ctx, uint8_t* base) {
	// 0x2C38E0: movss xmm0, dword ptr [0x005A92B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A92B4u);
	// 0x2C38E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C38F0: movss [0x005A92C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92C4u, ctx.xmm[0].u32[0]);
	// 0x2C38F8: ret
	return;
}

void sub_2C3900(X86Context& ctx, uint8_t* base) {
	// 0x2C3900: movss xmm0, dword ptr [0x005A929C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A929Cu);
	// 0x2C3908: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C3910: movss [0x005A92C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92C0u, ctx.xmm[0].u32[0]);
	// 0x2C3918: ret
	return;
}

void sub_2C3920(X86Context& ctx, uint8_t* base) {
	// 0x2C3920: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3928: movss [0x005A92D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92D4u, ctx.xmm[0].u32[0]);
	// 0x2C3930: ret
	return;
}

void sub_2C3940(X86Context& ctx, uint8_t* base) {
	// 0x2C3940: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C3948: movss [0x005A92C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92C8u, ctx.xmm[0].u32[0]);
	// 0x2C3950: ret
	return;
}

void sub_2C3960(X86Context& ctx, uint8_t* base) {
	// 0x2C3960: movss xmm0, dword ptr [0x005A92C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A92C8u);
	// 0x2C3968: movss [0x005A92D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92D0u, ctx.xmm[0].u32[0]);
	// 0x2C3970: ret
	return;
}

void sub_2C3980(X86Context& ctx, uint8_t* base) {
	// 0x2C3980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3988: movss [0x005A9298], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9298u, ctx.xmm[0].u32[0]);
	// 0x2C3990: ret
	return;
}

void sub_2C39A0(X86Context& ctx, uint8_t* base) {
	// 0x2C39A0: movss xmm0, dword ptr [0x005A929C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A929Cu);
	// 0x2C39A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C39B0: movss [0x005A92CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92CCu, ctx.xmm[0].u32[0]);
	// 0x2C39B8: ret
	return;
}

void sub_2C39C0(X86Context& ctx, uint8_t* base) {
	// 0x2C39C0: movss xmm0, dword ptr [0x005A929C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A929Cu);
	// 0x2C39C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C39D0: movss [0x005A92A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92A8u, ctx.xmm[0].u32[0]);
	// 0x2C39D8: ret
	return;
}

void sub_2C39E0(X86Context& ctx, uint8_t* base) {
	// 0x2C39E0: movss xmm0, dword ptr [0x005A929C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A929Cu);
	// 0x2C39E8: subss xmm0, [0x005A92A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A92A8u);
	// 0x2C39F0: movss [0x005A92A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92A4u, ctx.xmm[0].u32[0]);
	// 0x2C39F8: ret
	return;
}

void sub_2C3A00(X86Context& ctx, uint8_t* base) {
	// 0x2C3A00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C3A08: movss [0x005A92B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92B8u, ctx.xmm[0].u32[0]);
	// 0x2C3A10: ret
	return;
}

void sub_2C3A20(X86Context& ctx, uint8_t* base) {
	// 0x2C3A20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C3A28: movss [0x005A92A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92A0u, ctx.xmm[0].u32[0]);
	// 0x2C3A30: ret
	return;
}

void sub_2C3A40(X86Context& ctx, uint8_t* base) {
	// 0x2C3A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C3A48: movss [0x005A92DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92DCu, ctx.xmm[0].u32[0]);
	// 0x2C3A50: ret
	return;
}

void sub_2C3A60(X86Context& ctx, uint8_t* base) {
	// 0x2C3A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C3A68: movss [0x005A92D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92D8u, ctx.xmm[0].u32[0]);
	// 0x2C3A70: ret
	return;
}

void sub_2C3A80(X86Context& ctx, uint8_t* base) {
	// 0x2C3A80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C3A88: movss [0x005A92FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92FCu, ctx.xmm[0].u32[0]);
	// 0x2C3A90: ret
	return;
}

void sub_2C3AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C3AA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C3AA8: movss [0x005A9308], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9308u, ctx.xmm[0].u32[0]);
	// 0x2C3AB0: ret
	return;
}

void sub_2C3AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C3AC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C3AC8: movss [0x005A92F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92F8u, ctx.xmm[0].u32[0]);
	// 0x2C3AD0: ret
	return;
}

void sub_2C3AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C3AE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C3AE8: movss [0x005A92E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92E0u, ctx.xmm[0].u32[0]);
	// 0x2C3AF0: ret
	return;
}

void sub_2C3B00(X86Context& ctx, uint8_t* base) {
	// 0x2C3B00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C3B08: movss [0x005A9300], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9300u, ctx.xmm[0].u32[0]);
	// 0x2C3B10: ret
	return;
}

void sub_2C3B20(X86Context& ctx, uint8_t* base) {
	// 0x2C3B20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3B28: movss [0x005A92E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92E8u, ctx.xmm[0].u32[0]);
	// 0x2C3B30: ret
	return;
}

void sub_2C3B40(X86Context& ctx, uint8_t* base) {
	// 0x2C3B40: movss xmm0, dword ptr [0x005A9300]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9300u);
	// 0x2C3B48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C3B50: movss [0x005A9310], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9310u, ctx.xmm[0].u32[0]);
	// 0x2C3B58: ret
	return;
}

void sub_2C3B60(X86Context& ctx, uint8_t* base) {
	// 0x2C3B60: movss xmm0, dword ptr [0x005A92E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A92E8u);
	// 0x2C3B68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C3B70: movss [0x005A930C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A930Cu, ctx.xmm[0].u32[0]);
	// 0x2C3B78: ret
	return;
}

void sub_2C3B80(X86Context& ctx, uint8_t* base) {
	// 0x2C3B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3B88: movss [0x005A9320], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9320u, ctx.xmm[0].u32[0]);
	// 0x2C3B90: ret
	return;
}

void sub_2C3BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C3BA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C3BA8: movss [0x005A9314], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9314u, ctx.xmm[0].u32[0]);
	// 0x2C3BB0: ret
	return;
}

void sub_2C3BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C3BC0: movss xmm0, dword ptr [0x005A9314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9314u);
	// 0x2C3BC8: movss [0x005A931C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A931Cu, ctx.xmm[0].u32[0]);
	// 0x2C3BD0: ret
	return;
}

void sub_2C3BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C3BE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3BE8: movss [0x005A92E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92E4u, ctx.xmm[0].u32[0]);
	// 0x2C3BF0: ret
	return;
}

void sub_2C3C00(X86Context& ctx, uint8_t* base) {
	// 0x2C3C00: movss xmm0, dword ptr [0x005A92E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A92E8u);
	// 0x2C3C08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C3C10: movss [0x005A9318], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9318u, ctx.xmm[0].u32[0]);
	// 0x2C3C18: ret
	return;
}

void sub_2C3C20(X86Context& ctx, uint8_t* base) {
	// 0x2C3C20: movss xmm0, dword ptr [0x005A92E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A92E8u);
	// 0x2C3C28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C3C30: movss [0x005A92F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92F4u, ctx.xmm[0].u32[0]);
	// 0x2C3C38: ret
	return;
}

void sub_2C3C40(X86Context& ctx, uint8_t* base) {
	// 0x2C3C40: movss xmm0, dword ptr [0x005A92E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A92E8u);
	// 0x2C3C48: subss xmm0, [0x005A92F4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A92F4u);
	// 0x2C3C50: movss [0x005A92F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92F0u, ctx.xmm[0].u32[0]);
	// 0x2C3C58: ret
	return;
}

void sub_2C3C60(X86Context& ctx, uint8_t* base) {
	// 0x2C3C60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C3C68: movss [0x005A9304], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9304u, ctx.xmm[0].u32[0]);
	// 0x2C3C70: ret
	return;
}

void sub_2C3C80(X86Context& ctx, uint8_t* base) {
	// 0x2C3C80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C3C88: movss [0x005A92EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A92ECu, ctx.xmm[0].u32[0]);
	// 0x2C3C90: ret
	return;
}

void sub_2C3CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C3CA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C3CA8: movss [0x005A9340], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9340u, ctx.xmm[0].u32[0]);
	// 0x2C3CB0: ret
	return;
}

void sub_2C3CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C3CC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C3CC8: movss [0x005A934C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A934Cu, ctx.xmm[0].u32[0]);
	// 0x2C3CD0: ret
	return;
}

void sub_2C3CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C3CE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C3CE8: movss [0x005A933C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A933Cu, ctx.xmm[0].u32[0]);
	// 0x2C3CF0: ret
	return;
}

void sub_2C3D00(X86Context& ctx, uint8_t* base) {
	// 0x2C3D00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C3D08: movss [0x005A9324], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9324u, ctx.xmm[0].u32[0]);
	// 0x2C3D10: ret
	return;
}

void sub_2C3D20(X86Context& ctx, uint8_t* base) {
	// 0x2C3D20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C3D28: movss [0x005A9344], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9344u, ctx.xmm[0].u32[0]);
	// 0x2C3D30: ret
	return;
}

void sub_2C3D40(X86Context& ctx, uint8_t* base) {
	// 0x2C3D40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3D48: movss [0x005A932C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A932Cu, ctx.xmm[0].u32[0]);
	// 0x2C3D50: ret
	return;
}

void sub_2C3D60(X86Context& ctx, uint8_t* base) {
	// 0x2C3D60: movss xmm0, dword ptr [0x005A9344]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9344u);
	// 0x2C3D68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C3D70: movss [0x005A9354], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9354u, ctx.xmm[0].u32[0]);
	// 0x2C3D78: ret
	return;
}

void sub_2C3D80(X86Context& ctx, uint8_t* base) {
	// 0x2C3D80: movss xmm0, dword ptr [0x005A932C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A932Cu);
	// 0x2C3D88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C3D90: movss [0x005A9350], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9350u, ctx.xmm[0].u32[0]);
	// 0x2C3D98: ret
	return;
}

void sub_2C3DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C3DA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3DA8: movss [0x005A9364], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9364u, ctx.xmm[0].u32[0]);
	// 0x2C3DB0: ret
	return;
}

void sub_2C3DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C3DC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C3DC8: movss [0x005A9358], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9358u, ctx.xmm[0].u32[0]);
	// 0x2C3DD0: ret
	return;
}

void sub_2C3DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C3DE0: movss xmm0, dword ptr [0x005A9358]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9358u);
	// 0x2C3DE8: movss [0x005A9360], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9360u, ctx.xmm[0].u32[0]);
	// 0x2C3DF0: ret
	return;
}

void sub_2C3E00(X86Context& ctx, uint8_t* base) {
	// 0x2C3E00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3E08: movss [0x005A9328], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9328u, ctx.xmm[0].u32[0]);
	// 0x2C3E10: ret
	return;
}

void sub_2C3E20(X86Context& ctx, uint8_t* base) {
	// 0x2C3E20: movss xmm0, dword ptr [0x005A932C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A932Cu);
	// 0x2C3E28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C3E30: movss [0x005A935C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A935Cu, ctx.xmm[0].u32[0]);
	// 0x2C3E38: ret
	return;
}

void sub_2C3E40(X86Context& ctx, uint8_t* base) {
	// 0x2C3E40: movss xmm0, dword ptr [0x005A932C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A932Cu);
	// 0x2C3E48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C3E50: movss [0x005A9338], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9338u, ctx.xmm[0].u32[0]);
	// 0x2C3E58: ret
	return;
}

void sub_2C3E60(X86Context& ctx, uint8_t* base) {
	// 0x2C3E60: movss xmm0, dword ptr [0x005A932C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A932Cu);
	// 0x2C3E68: subss xmm0, [0x005A9338]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9338u);
	// 0x2C3E70: movss [0x005A9334], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9334u, ctx.xmm[0].u32[0]);
	// 0x2C3E78: ret
	return;
}

void sub_2C3E80(X86Context& ctx, uint8_t* base) {
	// 0x2C3E80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C3E88: movss [0x005A9348], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9348u, ctx.xmm[0].u32[0]);
	// 0x2C3E90: ret
	return;
}

void sub_2C3EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C3EA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C3EA8: movss [0x005A9330], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9330u, ctx.xmm[0].u32[0]);
	// 0x2C3EB0: ret
	return;
}

void sub_2C3EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C3EC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C3EC8: movss [0x005A9384], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9384u, ctx.xmm[0].u32[0]);
	// 0x2C3ED0: ret
	return;
}

void sub_2C3EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C3EE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C3EE8: movss [0x005A9390], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9390u, ctx.xmm[0].u32[0]);
	// 0x2C3EF0: ret
	return;
}

void sub_2C3F00(X86Context& ctx, uint8_t* base) {
	// 0x2C3F00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C3F08: movss [0x005A9380], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9380u, ctx.xmm[0].u32[0]);
	// 0x2C3F10: ret
	return;
}

void sub_2C3F20(X86Context& ctx, uint8_t* base) {
	// 0x2C3F20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C3F28: movss [0x005A9368], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9368u, ctx.xmm[0].u32[0]);
	// 0x2C3F30: ret
	return;
}

void sub_2C3F40(X86Context& ctx, uint8_t* base) {
	// 0x2C3F40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C3F48: movss [0x005A9388], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9388u, ctx.xmm[0].u32[0]);
	// 0x2C3F50: ret
	return;
}

void sub_2C3F60(X86Context& ctx, uint8_t* base) {
	// 0x2C3F60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C3F68: movss [0x005A9370], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9370u, ctx.xmm[0].u32[0]);
	// 0x2C3F70: ret
	return;
}

void sub_2C3F80(X86Context& ctx, uint8_t* base) {
	// 0x2C3F80: movss xmm0, dword ptr [0x005A9388]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9388u);
	// 0x2C3F88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C3F90: movss [0x005A9398], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9398u, ctx.xmm[0].u32[0]);
	// 0x2C3F98: ret
	return;
}

void sub_2C3FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C3FA0: movss xmm0, dword ptr [0x005A9370]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9370u);
	// 0x2C3FA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C3FB0: movss [0x005A9394], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9394u, ctx.xmm[0].u32[0]);
	// 0x2C3FB8: ret
	return;
}

void sub_2C3FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C3FC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C3FC8: movss [0x005A93A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93A8u, ctx.xmm[0].u32[0]);
	// 0x2C3FD0: ret
	return;
}

void sub_2C3FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C3FE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C3FE8: movss [0x005A939C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A939Cu, ctx.xmm[0].u32[0]);
	// 0x2C3FF0: ret
	return;
}

void sub_2C4000(X86Context& ctx, uint8_t* base) {
	// 0x2C4000: movss xmm0, dword ptr [0x005A939C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A939Cu);
	// 0x2C4008: movss [0x005A93A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93A4u, ctx.xmm[0].u32[0]);
	// 0x2C4010: ret
	return;
}

void sub_2C4020(X86Context& ctx, uint8_t* base) {
	// 0x2C4020: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4028: movss [0x005A936C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A936Cu, ctx.xmm[0].u32[0]);
	// 0x2C4030: ret
	return;
}

void sub_2C4040(X86Context& ctx, uint8_t* base) {
	// 0x2C4040: movss xmm0, dword ptr [0x005A9370]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9370u);
	// 0x2C4048: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C4050: movss [0x005A93A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93A0u, ctx.xmm[0].u32[0]);
	// 0x2C4058: ret
	return;
}

void sub_2C4060(X86Context& ctx, uint8_t* base) {
	// 0x2C4060: movss xmm0, dword ptr [0x005A9370]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9370u);
	// 0x2C4068: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C4070: movss [0x005A937C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A937Cu, ctx.xmm[0].u32[0]);
	// 0x2C4078: ret
	return;
}

void sub_2C4080(X86Context& ctx, uint8_t* base) {
	// 0x2C4080: movss xmm0, dword ptr [0x005A9370]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9370u);
	// 0x2C4088: subss xmm0, [0x005A937C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A937Cu);
	// 0x2C4090: movss [0x005A9378], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9378u, ctx.xmm[0].u32[0]);
	// 0x2C4098: ret
	return;
}

void sub_2C40A0(X86Context& ctx, uint8_t* base) {
	// 0x2C40A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C40A8: movss [0x005A938C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A938Cu, ctx.xmm[0].u32[0]);
	// 0x2C40B0: ret
	return;
}

void sub_2C40C0(X86Context& ctx, uint8_t* base) {
	// 0x2C40C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C40C8: movss [0x005A9374], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9374u, ctx.xmm[0].u32[0]);
	// 0x2C40D0: ret
	return;
}

void sub_2C40E0(X86Context& ctx, uint8_t* base) {
	// 0x2C40E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C40E8: movss [0x005A93C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93C8u, ctx.xmm[0].u32[0]);
	// 0x2C40F0: ret
	return;
}

void sub_2C4100(X86Context& ctx, uint8_t* base) {
	// 0x2C4100: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4108: movss [0x005A93D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93D4u, ctx.xmm[0].u32[0]);
	// 0x2C4110: ret
	return;
}

void sub_2C4120(X86Context& ctx, uint8_t* base) {
	// 0x2C4120: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4128: movss [0x005A93C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93C4u, ctx.xmm[0].u32[0]);
	// 0x2C4130: ret
	return;
}

void sub_2C4140(X86Context& ctx, uint8_t* base) {
	// 0x2C4140: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C4148: movss [0x005A93AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93ACu, ctx.xmm[0].u32[0]);
	// 0x2C4150: ret
	return;
}

void sub_2C4160(X86Context& ctx, uint8_t* base) {
	// 0x2C4160: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C4168: movss [0x005A93CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93CCu, ctx.xmm[0].u32[0]);
	// 0x2C4170: ret
	return;
}

void sub_2C4180(X86Context& ctx, uint8_t* base) {
	// 0x2C4180: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C4188: movss [0x005A93B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93B4u, ctx.xmm[0].u32[0]);
	// 0x2C4190: ret
	return;
}

void sub_2C41A0(X86Context& ctx, uint8_t* base) {
	// 0x2C41A0: movss xmm0, dword ptr [0x005A93CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A93CCu);
	// 0x2C41A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C41B0: movss [0x005A93DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93DCu, ctx.xmm[0].u32[0]);
	// 0x2C41B8: ret
	return;
}

void sub_2C41C0(X86Context& ctx, uint8_t* base) {
	// 0x2C41C0: movss xmm0, dword ptr [0x005A93B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A93B4u);
	// 0x2C41C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C41D0: movss [0x005A93D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93D8u, ctx.xmm[0].u32[0]);
	// 0x2C41D8: ret
	return;
}

void sub_2C41E0(X86Context& ctx, uint8_t* base) {
	// 0x2C41E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C41E8: movss [0x005A93EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93ECu, ctx.xmm[0].u32[0]);
	// 0x2C41F0: ret
	return;
}

void sub_2C4200(X86Context& ctx, uint8_t* base) {
	// 0x2C4200: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C4208: movss [0x005A93E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93E0u, ctx.xmm[0].u32[0]);
	// 0x2C4210: ret
	return;
}

void sub_2C4220(X86Context& ctx, uint8_t* base) {
	// 0x2C4220: movss xmm0, dword ptr [0x005A93E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A93E0u);
	// 0x2C4228: movss [0x005A93E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93E8u, ctx.xmm[0].u32[0]);
	// 0x2C4230: ret
	return;
}

void sub_2C4240(X86Context& ctx, uint8_t* base) {
	// 0x2C4240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4248: movss [0x005A93B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93B0u, ctx.xmm[0].u32[0]);
	// 0x2C4250: ret
	return;
}

void sub_2C4260(X86Context& ctx, uint8_t* base) {
	// 0x2C4260: movss xmm0, dword ptr [0x005A93B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A93B4u);
	// 0x2C4268: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C4270: movss [0x005A93E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93E4u, ctx.xmm[0].u32[0]);
	// 0x2C4278: ret
	return;
}

void sub_2C4280(X86Context& ctx, uint8_t* base) {
	// 0x2C4280: movss xmm0, dword ptr [0x005A93B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A93B4u);
	// 0x2C4288: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C4290: movss [0x005A93C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93C0u, ctx.xmm[0].u32[0]);
	// 0x2C4298: ret
	return;
}

void sub_2C42A0(X86Context& ctx, uint8_t* base) {
	// 0x2C42A0: movss xmm0, dword ptr [0x005A93B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A93B4u);
	// 0x2C42A8: subss xmm0, [0x005A93C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A93C0u);
	// 0x2C42B0: movss [0x005A93BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93BCu, ctx.xmm[0].u32[0]);
	// 0x2C42B8: ret
	return;
}

void sub_2C42C0(X86Context& ctx, uint8_t* base) {
	// 0x2C42C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C42C8: movss [0x005A93D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93D0u, ctx.xmm[0].u32[0]);
	// 0x2C42D0: ret
	return;
}

void sub_2C42E0(X86Context& ctx, uint8_t* base) {
	// 0x2C42E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C42E8: movss [0x005A93B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93B8u, ctx.xmm[0].u32[0]);
	// 0x2C42F0: ret
	return;
}

void sub_2C4300(X86Context& ctx, uint8_t* base) {
	// 0x2C4300: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4308: movss [0x005A9410], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9410u, ctx.xmm[0].u32[0]);
	// 0x2C4310: ret
	return;
}

void sub_2C4320(X86Context& ctx, uint8_t* base) {
	// 0x2C4320: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4328: movss [0x005A941C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A941Cu, ctx.xmm[0].u32[0]);
	// 0x2C4330: ret
	return;
}

void sub_2C4340(X86Context& ctx, uint8_t* base) {
	// 0x2C4340: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4348: movss [0x005A9408], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9408u, ctx.xmm[0].u32[0]);
	// 0x2C4350: ret
	return;
}

void sub_2C4360(X86Context& ctx, uint8_t* base) {
	// 0x2C4360: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C4368: movss [0x005A93F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93F0u, ctx.xmm[0].u32[0]);
	// 0x2C4370: ret
	return;
}

void sub_2C4380(X86Context& ctx, uint8_t* base) {
	// 0x2C4380: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C4388: movss [0x005A9414], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9414u, ctx.xmm[0].u32[0]);
	// 0x2C4390: ret
	return;
}

void sub_2C43A0(X86Context& ctx, uint8_t* base) {
	// 0x2C43A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C43A8: movss [0x005A93F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93F4u, ctx.xmm[0].u32[0]);
	// 0x2C43B0: ret
	return;
}

void sub_2C43C0(X86Context& ctx, uint8_t* base) {
	// 0x2C43C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C43C8: movss [0x005A9424], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9424u, ctx.xmm[0].u32[0]);
	// 0x2C43D0: ret
	return;
}

void sub_2C43E0(X86Context& ctx, uint8_t* base) {
	// 0x2C43E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C43E8: movss [0x005A940C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A940Cu, ctx.xmm[0].u32[0]);
	// 0x2C43F0: ret
	return;
}

void sub_2C4400(X86Context& ctx, uint8_t* base) {
	// 0x2C4400: movss xmm0, dword ptr [0x005A9424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9424u);
	// 0x2C4408: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C4410: movss [0x005A93FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93FCu, ctx.xmm[0].u32[0]);
	// 0x2C4418: ret
	return;
}

void sub_2C4420(X86Context& ctx, uint8_t* base) {
	// 0x2C4420: movss xmm0, dword ptr [0x005A940C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A940Cu);
	// 0x2C4428: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C4430: movss [0x005A9420], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9420u, ctx.xmm[0].u32[0]);
	// 0x2C4438: ret
	return;
}

void sub_2C4440(X86Context& ctx, uint8_t* base) {
	// 0x2C4440: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4448: movss [0x005A9430], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9430u, ctx.xmm[0].u32[0]);
	// 0x2C4450: ret
	return;
}

void sub_2C4460(X86Context& ctx, uint8_t* base) {
	// 0x2C4460: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C4468: movss [0x005A9428], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9428u, ctx.xmm[0].u32[0]);
	// 0x2C4470: ret
	return;
}

void sub_2C4480(X86Context& ctx, uint8_t* base) {
	// 0x2C4480: movss xmm0, dword ptr [0x005A9428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9428u);
	// 0x2C4488: movss [0x005A942C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A942Cu, ctx.xmm[0].u32[0]);
	// 0x2C4490: ret
	return;
}

void sub_2C44A0(X86Context& ctx, uint8_t* base) {
	// 0x2C44A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C44A8: movss [0x005A9404], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9404u, ctx.xmm[0].u32[0]);
	// 0x2C44B0: ret
	return;
}

void sub_2C44C0(X86Context& ctx, uint8_t* base) {
	// 0x2C44C0: movss xmm0, dword ptr [0x005A940C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A940Cu);
	// 0x2C44C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C44D0: movss [0x005A9400], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9400u, ctx.xmm[0].u32[0]);
	// 0x2C44D8: ret
	return;
}

void sub_2C44E0(X86Context& ctx, uint8_t* base) {
	// 0x2C44E0: movss xmm0, dword ptr [0x005A940C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A940Cu);
	// 0x2C44E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C44F0: movss [0x005A9418], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9418u, ctx.xmm[0].u32[0]);
	// 0x2C44F8: ret
	return;
}

void sub_2C4500(X86Context& ctx, uint8_t* base) {
	// 0x2C4500: movss xmm0, dword ptr [0x005A940C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A940Cu);
	// 0x2C4508: subss xmm0, [0x005A9418]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9418u);
	// 0x2C4510: movss [0x005A93F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A93F8u, ctx.xmm[0].u32[0]);
	// 0x2C4518: ret
	return;
}

void sub_2C4520(X86Context& ctx, uint8_t* base) {
	// 0x2C4520: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4528: movss [0x005A9438], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9438u, ctx.xmm[0].u32[0]);
	// 0x2C4530: ret
	return;
}

void sub_2C4540(X86Context& ctx, uint8_t* base) {
	// 0x2C4540: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4548: movss [0x005A943C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A943Cu, ctx.xmm[0].u32[0]);
	// 0x2C4550: ret
	return;
}

void sub_2C4560(X86Context& ctx, uint8_t* base) {
	// 0x2C4560: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4568: movss [0x005A9434], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9434u, ctx.xmm[0].u32[0]);
	// 0x2C4570: ret
	return;
}

void sub_2C4580(X86Context& ctx, uint8_t* base) {
	// 0x2C4580: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4588: movss [0x005A945C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A945Cu, ctx.xmm[0].u32[0]);
	// 0x2C4590: ret
	return;
}

void sub_2C45A0(X86Context& ctx, uint8_t* base) {
	// 0x2C45A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C45A8: movss [0x005A9468], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9468u, ctx.xmm[0].u32[0]);
	// 0x2C45B0: ret
	return;
}

void sub_2C45C0(X86Context& ctx, uint8_t* base) {
	// 0x2C45C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C45C8: movss [0x005A9458], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9458u, ctx.xmm[0].u32[0]);
	// 0x2C45D0: ret
	return;
}

void sub_2C45E0(X86Context& ctx, uint8_t* base) {
	// 0x2C45E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C45E8: movss [0x005A9440], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9440u, ctx.xmm[0].u32[0]);
	// 0x2C45F0: ret
	return;
}

void sub_2C4600(X86Context& ctx, uint8_t* base) {
	// 0x2C4600: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C4608: movss [0x005A9460], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9460u, ctx.xmm[0].u32[0]);
	// 0x2C4610: ret
	return;
}

void sub_2C4620(X86Context& ctx, uint8_t* base) {
	// 0x2C4620: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C4628: movss [0x005A9448], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9448u, ctx.xmm[0].u32[0]);
	// 0x2C4630: ret
	return;
}

void sub_2C4640(X86Context& ctx, uint8_t* base) {
	// 0x2C4640: movss xmm0, dword ptr [0x005A9460]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9460u);
	// 0x2C4648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C4650: movss [0x005A9470], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9470u, ctx.xmm[0].u32[0]);
	// 0x2C4658: ret
	return;
}

void sub_2C4660(X86Context& ctx, uint8_t* base) {
	// 0x2C4660: movss xmm0, dword ptr [0x005A9448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9448u);
	// 0x2C4668: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C4670: movss [0x005A946C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A946Cu, ctx.xmm[0].u32[0]);
	// 0x2C4678: ret
	return;
}

void sub_2C4680(X86Context& ctx, uint8_t* base) {
	// 0x2C4680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4688: movss [0x005A9480], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9480u, ctx.xmm[0].u32[0]);
	// 0x2C4690: ret
	return;
}

void sub_2C46A0(X86Context& ctx, uint8_t* base) {
	// 0x2C46A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C46A8: movss [0x005A9474], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9474u, ctx.xmm[0].u32[0]);
	// 0x2C46B0: ret
	return;
}

void sub_2C46C0(X86Context& ctx, uint8_t* base) {
	// 0x2C46C0: movss xmm0, dword ptr [0x005A9474]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9474u);
	// 0x2C46C8: movss [0x005A947C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A947Cu, ctx.xmm[0].u32[0]);
	// 0x2C46D0: ret
	return;
}

void sub_2C46E0(X86Context& ctx, uint8_t* base) {
	// 0x2C46E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C46E8: movss [0x005A9444], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9444u, ctx.xmm[0].u32[0]);
	// 0x2C46F0: ret
	return;
}

void sub_2C4700(X86Context& ctx, uint8_t* base) {
	// 0x2C4700: movss xmm0, dword ptr [0x005A9448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9448u);
	// 0x2C4708: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C4710: movss [0x005A9478], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9478u, ctx.xmm[0].u32[0]);
	// 0x2C4718: ret
	return;
}

void sub_2C4720(X86Context& ctx, uint8_t* base) {
	// 0x2C4720: movss xmm0, dword ptr [0x005A9448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9448u);
	// 0x2C4728: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C4730: movss [0x005A9454], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9454u, ctx.xmm[0].u32[0]);
	// 0x2C4738: ret
	return;
}

void sub_2C4740(X86Context& ctx, uint8_t* base) {
	// 0x2C4740: movss xmm0, dword ptr [0x005A9448]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9448u);
	// 0x2C4748: subss xmm0, [0x005A9454]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9454u);
	// 0x2C4750: movss [0x005A9450], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9450u, ctx.xmm[0].u32[0]);
	// 0x2C4758: ret
	return;
}

void sub_2C4760(X86Context& ctx, uint8_t* base) {
	// 0x2C4760: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C4768: movss [0x005A9464], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9464u, ctx.xmm[0].u32[0]);
	// 0x2C4770: ret
	return;
}

void sub_2C4780(X86Context& ctx, uint8_t* base) {
	// 0x2C4780: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C4788: movss [0x005A944C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A944Cu, ctx.xmm[0].u32[0]);
	// 0x2C4790: ret
	return;
}

void sub_2C47A0(X86Context& ctx, uint8_t* base) {
	// 0x2C47A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C47A8: movss [0x005A9488], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9488u, ctx.xmm[0].u32[0]);
	// 0x2C47B0: ret
	return;
}

void sub_2C47C0(X86Context& ctx, uint8_t* base) {
	// 0x2C47C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C47C8: movss [0x005A948C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A948Cu, ctx.xmm[0].u32[0]);
	// 0x2C47D0: ret
	return;
}

void sub_2C47E0(X86Context& ctx, uint8_t* base) {
	// 0x2C47E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C47E8: movss [0x005A9484], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9484u, ctx.xmm[0].u32[0]);
	// 0x2C47F0: ret
	return;
}

void sub_2C4800(X86Context& ctx, uint8_t* base) {
	// 0x2C4800: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4808: movss [0x005A94B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94B0u, ctx.xmm[0].u32[0]);
	// 0x2C4810: ret
	return;
}

void sub_2C4820(X86Context& ctx, uint8_t* base) {
	// 0x2C4820: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4828: movss [0x005A94BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94BCu, ctx.xmm[0].u32[0]);
	// 0x2C4830: ret
	return;
}

void sub_2C4840(X86Context& ctx, uint8_t* base) {
	// 0x2C4840: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4848: movss [0x005A94A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94A8u, ctx.xmm[0].u32[0]);
	// 0x2C4850: ret
	return;
}

void sub_2C4860(X86Context& ctx, uint8_t* base) {
	// 0x2C4860: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C4868: movss [0x005A9490], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9490u, ctx.xmm[0].u32[0]);
	// 0x2C4870: ret
	return;
}

void sub_2C4880(X86Context& ctx, uint8_t* base) {
	// 0x2C4880: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C4888: movss [0x005A94B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94B4u, ctx.xmm[0].u32[0]);
	// 0x2C4890: ret
	return;
}

void sub_2C48A0(X86Context& ctx, uint8_t* base) {
	// 0x2C48A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C48A8: movss [0x005A9494], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9494u, ctx.xmm[0].u32[0]);
	// 0x2C48B0: ret
	return;
}

void sub_2C48C0(X86Context& ctx, uint8_t* base) {
	// 0x2C48C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C48C8: movss [0x005A94C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94C4u, ctx.xmm[0].u32[0]);
	// 0x2C48D0: ret
	return;
}

void sub_2C48E0(X86Context& ctx, uint8_t* base) {
	// 0x2C48E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C48E8: movss [0x005A94AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94ACu, ctx.xmm[0].u32[0]);
	// 0x2C48F0: ret
	return;
}

void sub_2C4900(X86Context& ctx, uint8_t* base) {
	// 0x2C4900: movss xmm0, dword ptr [0x005A94C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94C4u);
	// 0x2C4908: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C4910: movss [0x005A949C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A949Cu, ctx.xmm[0].u32[0]);
	// 0x2C4918: ret
	return;
}

void sub_2C4920(X86Context& ctx, uint8_t* base) {
	// 0x2C4920: movss xmm0, dword ptr [0x005A94AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94ACu);
	// 0x2C4928: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C4930: movss [0x005A94C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94C0u, ctx.xmm[0].u32[0]);
	// 0x2C4938: ret
	return;
}

void sub_2C4940(X86Context& ctx, uint8_t* base) {
	// 0x2C4940: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4948: movss [0x005A94D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94D0u, ctx.xmm[0].u32[0]);
	// 0x2C4950: ret
	return;
}

void sub_2C4960(X86Context& ctx, uint8_t* base) {
	// 0x2C4960: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C4968: movss [0x005A94C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94C8u, ctx.xmm[0].u32[0]);
	// 0x2C4970: ret
	return;
}

void sub_2C4980(X86Context& ctx, uint8_t* base) {
	// 0x2C4980: movss xmm0, dword ptr [0x005A94C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94C8u);
	// 0x2C4988: movss [0x005A94CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94CCu, ctx.xmm[0].u32[0]);
	// 0x2C4990: ret
	return;
}

void sub_2C49A0(X86Context& ctx, uint8_t* base) {
	// 0x2C49A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C49A8: movss [0x005A94A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94A4u, ctx.xmm[0].u32[0]);
	// 0x2C49B0: ret
	return;
}

void sub_2C49C0(X86Context& ctx, uint8_t* base) {
	// 0x2C49C0: movss xmm0, dword ptr [0x005A94AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94ACu);
	// 0x2C49C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C49D0: movss [0x005A94A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94A0u, ctx.xmm[0].u32[0]);
	// 0x2C49D8: ret
	return;
}

void sub_2C49E0(X86Context& ctx, uint8_t* base) {
	// 0x2C49E0: movss xmm0, dword ptr [0x005A94AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94ACu);
	// 0x2C49E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C49F0: movss [0x005A94B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94B8u, ctx.xmm[0].u32[0]);
	// 0x2C49F8: ret
	return;
}

void sub_2C4A00(X86Context& ctx, uint8_t* base) {
	// 0x2C4A00: movss xmm0, dword ptr [0x005A94AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94ACu);
	// 0x2C4A08: subss xmm0, [0x005A94B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A94B8u);
	// 0x2C4A10: movss [0x005A9498], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9498u, ctx.xmm[0].u32[0]);
	// 0x2C4A18: ret
	return;
}

void sub_2C4A20(X86Context& ctx, uint8_t* base) {
	// 0x2C4A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4A28: movss [0x005A94F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94F4u, ctx.xmm[0].u32[0]);
	// 0x2C4A30: ret
	return;
}

void sub_2C4A40(X86Context& ctx, uint8_t* base) {
	// 0x2C4A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4A48: movss [0x005A9500], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9500u, ctx.xmm[0].u32[0]);
	// 0x2C4A50: ret
	return;
}

void sub_2C4A60(X86Context& ctx, uint8_t* base) {
	// 0x2C4A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4A68: movss [0x005A94EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94ECu, ctx.xmm[0].u32[0]);
	// 0x2C4A70: ret
	return;
}

void sub_2C4A80(X86Context& ctx, uint8_t* base) {
	// 0x2C4A80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C4A88: movss [0x005A94D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94D4u, ctx.xmm[0].u32[0]);
	// 0x2C4A90: ret
	return;
}

void sub_2C4AA0(X86Context& ctx, uint8_t* base) {
	// 0x2C4AA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C4AA8: movss [0x005A94F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94F8u, ctx.xmm[0].u32[0]);
	// 0x2C4AB0: ret
	return;
}

void sub_2C4AC0(X86Context& ctx, uint8_t* base) {
	// 0x2C4AC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C4AC8: movss [0x005A94D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94D8u, ctx.xmm[0].u32[0]);
	// 0x2C4AD0: ret
	return;
}

void sub_2C4AE0(X86Context& ctx, uint8_t* base) {
	// 0x2C4AE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C4AE8: movss [0x005A9508], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9508u, ctx.xmm[0].u32[0]);
	// 0x2C4AF0: ret
	return;
}

void sub_2C4B00(X86Context& ctx, uint8_t* base) {
	// 0x2C4B00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C4B08: movss [0x005A94F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94F0u, ctx.xmm[0].u32[0]);
	// 0x2C4B10: ret
	return;
}

void sub_2C4B20(X86Context& ctx, uint8_t* base) {
	// 0x2C4B20: movss xmm0, dword ptr [0x005A9508]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9508u);
	// 0x2C4B28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C4B30: movss [0x005A94E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94E0u, ctx.xmm[0].u32[0]);
	// 0x2C4B38: ret
	return;
}

void sub_2C4B40(X86Context& ctx, uint8_t* base) {
	// 0x2C4B40: movss xmm0, dword ptr [0x005A94F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94F0u);
	// 0x2C4B48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C4B50: movss [0x005A9504], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9504u, ctx.xmm[0].u32[0]);
	// 0x2C4B58: ret
	return;
}

void sub_2C4B60(X86Context& ctx, uint8_t* base) {
	// 0x2C4B60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4B68: movss [0x005A9514], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9514u, ctx.xmm[0].u32[0]);
	// 0x2C4B70: ret
	return;
}

void sub_2C4B80(X86Context& ctx, uint8_t* base) {
	// 0x2C4B80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C4B88: movss [0x005A950C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A950Cu, ctx.xmm[0].u32[0]);
	// 0x2C4B90: ret
	return;
}

void sub_2C4BA0(X86Context& ctx, uint8_t* base) {
	// 0x2C4BA0: movss xmm0, dword ptr [0x005A950C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A950Cu);
	// 0x2C4BA8: movss [0x005A9510], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9510u, ctx.xmm[0].u32[0]);
	// 0x2C4BB0: ret
	return;
}

void sub_2C4BC0(X86Context& ctx, uint8_t* base) {
	// 0x2C4BC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4BC8: movss [0x005A94E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94E8u, ctx.xmm[0].u32[0]);
	// 0x2C4BD0: ret
	return;
}

void sub_2C4BE0(X86Context& ctx, uint8_t* base) {
	// 0x2C4BE0: movss xmm0, dword ptr [0x005A94F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94F0u);
	// 0x2C4BE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C4BF0: movss [0x005A94E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94E4u, ctx.xmm[0].u32[0]);
	// 0x2C4BF8: ret
	return;
}

void sub_2C4C00(X86Context& ctx, uint8_t* base) {
	// 0x2C4C00: movss xmm0, dword ptr [0x005A94F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94F0u);
	// 0x2C4C08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C4C10: movss [0x005A94FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94FCu, ctx.xmm[0].u32[0]);
	// 0x2C4C18: ret
	return;
}

void sub_2C4C20(X86Context& ctx, uint8_t* base) {
	// 0x2C4C20: movss xmm0, dword ptr [0x005A94F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A94F0u);
	// 0x2C4C28: subss xmm0, [0x005A94FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A94FCu);
	// 0x2C4C30: movss [0x005A94DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A94DCu, ctx.xmm[0].u32[0]);
	// 0x2C4C38: ret
	return;
}

void sub_2C4C40(X86Context& ctx, uint8_t* base) {
	// 0x2C4C40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4C48: movss [0x005A9538], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9538u, ctx.xmm[0].u32[0]);
	// 0x2C4C50: ret
	return;
}

void sub_2C4C60(X86Context& ctx, uint8_t* base) {
	// 0x2C4C60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4C68: movss [0x005A9544], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9544u, ctx.xmm[0].u32[0]);
	// 0x2C4C70: ret
	return;
}

void sub_2C4C80(X86Context& ctx, uint8_t* base) {
	// 0x2C4C80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4C88: movss [0x005A9530], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9530u, ctx.xmm[0].u32[0]);
	// 0x2C4C90: ret
	return;
}

void sub_2C4CA0(X86Context& ctx, uint8_t* base) {
	// 0x2C4CA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C4CA8: movss [0x005A9518], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9518u, ctx.xmm[0].u32[0]);
	// 0x2C4CB0: ret
	return;
}

void sub_2C4CC0(X86Context& ctx, uint8_t* base) {
	// 0x2C4CC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C4CC8: movss [0x005A953C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A953Cu, ctx.xmm[0].u32[0]);
	// 0x2C4CD0: ret
	return;
}

void sub_2C4CE0(X86Context& ctx, uint8_t* base) {
	// 0x2C4CE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C4CE8: movss [0x005A951C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A951Cu, ctx.xmm[0].u32[0]);
	// 0x2C4CF0: ret
	return;
}

void sub_2C4D00(X86Context& ctx, uint8_t* base) {
	// 0x2C4D00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C4D08: movss [0x005A954C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A954Cu, ctx.xmm[0].u32[0]);
	// 0x2C4D10: ret
	return;
}

void sub_2C4D20(X86Context& ctx, uint8_t* base) {
	// 0x2C4D20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C4D28: movss [0x005A9534], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9534u, ctx.xmm[0].u32[0]);
	// 0x2C4D30: ret
	return;
}

void sub_2C4D40(X86Context& ctx, uint8_t* base) {
	// 0x2C4D40: movss xmm0, dword ptr [0x005A954C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A954Cu);
	// 0x2C4D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C4D50: movss [0x005A9524], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9524u, ctx.xmm[0].u32[0]);
	// 0x2C4D58: ret
	return;
}

void sub_2C4D60(X86Context& ctx, uint8_t* base) {
	// 0x2C4D60: movss xmm0, dword ptr [0x005A9534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9534u);
	// 0x2C4D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C4D70: movss [0x005A9548], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9548u, ctx.xmm[0].u32[0]);
	// 0x2C4D78: ret
	return;
}

void sub_2C4D80(X86Context& ctx, uint8_t* base) {
	// 0x2C4D80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4D88: movss [0x005A9558], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9558u, ctx.xmm[0].u32[0]);
	// 0x2C4D90: ret
	return;
}

void sub_2C4DA0(X86Context& ctx, uint8_t* base) {
	// 0x2C4DA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C4DA8: movss [0x005A9550], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9550u, ctx.xmm[0].u32[0]);
	// 0x2C4DB0: ret
	return;
}

void sub_2C4DC0(X86Context& ctx, uint8_t* base) {
	// 0x2C4DC0: movss xmm0, dword ptr [0x005A9550]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9550u);
	// 0x2C4DC8: movss [0x005A9554], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9554u, ctx.xmm[0].u32[0]);
	// 0x2C4DD0: ret
	return;
}

void sub_2C4DE0(X86Context& ctx, uint8_t* base) {
	// 0x2C4DE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4DE8: movss [0x005A952C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A952Cu, ctx.xmm[0].u32[0]);
	// 0x2C4DF0: ret
	return;
}

void sub_2C4E00(X86Context& ctx, uint8_t* base) {
	// 0x2C4E00: movss xmm0, dword ptr [0x005A9534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9534u);
	// 0x2C4E08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C4E10: movss [0x005A9528], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9528u, ctx.xmm[0].u32[0]);
	// 0x2C4E18: ret
	return;
}

void sub_2C4E20(X86Context& ctx, uint8_t* base) {
	// 0x2C4E20: movss xmm0, dword ptr [0x005A9534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9534u);
	// 0x2C4E28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C4E30: movss [0x005A9540], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9540u, ctx.xmm[0].u32[0]);
	// 0x2C4E38: ret
	return;
}

void sub_2C4E40(X86Context& ctx, uint8_t* base) {
	// 0x2C4E40: movss xmm0, dword ptr [0x005A9534]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9534u);
	// 0x2C4E48: subss xmm0, [0x005A9540]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9540u);
	// 0x2C4E50: movss [0x005A9520], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9520u, ctx.xmm[0].u32[0]);
	// 0x2C4E58: ret
	return;
}

void sub_2C4E60(X86Context& ctx, uint8_t* base) {
	// 0x2C4E60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C4E68: movss [0x005A957C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A957Cu, ctx.xmm[0].u32[0]);
	// 0x2C4E70: ret
	return;
}

void sub_2C4E80(X86Context& ctx, uint8_t* base) {
	// 0x2C4E80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C4E88: movss [0x005A9588], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9588u, ctx.xmm[0].u32[0]);
	// 0x2C4E90: ret
	return;
}

void sub_2C4EA0(X86Context& ctx, uint8_t* base) {
	// 0x2C4EA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C4EA8: movss [0x005A9574], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9574u, ctx.xmm[0].u32[0]);
	// 0x2C4EB0: ret
	return;
}

void sub_2C4EC0(X86Context& ctx, uint8_t* base) {
	// 0x2C4EC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C4EC8: movss [0x005A955C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A955Cu, ctx.xmm[0].u32[0]);
	// 0x2C4ED0: ret
	return;
}

void sub_2C4EE0(X86Context& ctx, uint8_t* base) {
	// 0x2C4EE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C4EE8: movss [0x005A9580], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9580u, ctx.xmm[0].u32[0]);
	// 0x2C4EF0: ret
	return;
}

void sub_2C4F00(X86Context& ctx, uint8_t* base) {
	// 0x2C4F00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C4F08: movss [0x005A9560], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9560u, ctx.xmm[0].u32[0]);
	// 0x2C4F10: ret
	return;
}

void sub_2C4F20(X86Context& ctx, uint8_t* base) {
	// 0x2C4F20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C4F28: movss [0x005A9590], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9590u, ctx.xmm[0].u32[0]);
	// 0x2C4F30: ret
	return;
}

void sub_2C4F40(X86Context& ctx, uint8_t* base) {
	// 0x2C4F40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C4F48: movss [0x005A9578], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9578u, ctx.xmm[0].u32[0]);
	// 0x2C4F50: ret
	return;
}

void sub_2C4F60(X86Context& ctx, uint8_t* base) {
	// 0x2C4F60: movss xmm0, dword ptr [0x005A9590]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9590u);
	// 0x2C4F68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C4F70: movss [0x005A9568], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9568u, ctx.xmm[0].u32[0]);
	// 0x2C4F78: ret
	return;
}

void sub_2C4F80(X86Context& ctx, uint8_t* base) {
	// 0x2C4F80: movss xmm0, dword ptr [0x005A9578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9578u);
	// 0x2C4F88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C4F90: movss [0x005A958C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A958Cu, ctx.xmm[0].u32[0]);
	// 0x2C4F98: ret
	return;
}

void sub_2C4FA0(X86Context& ctx, uint8_t* base) {
	// 0x2C4FA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C4FA8: movss [0x005A959C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A959Cu, ctx.xmm[0].u32[0]);
	// 0x2C4FB0: ret
	return;
}

void sub_2C4FC0(X86Context& ctx, uint8_t* base) {
	// 0x2C4FC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C4FC8: movss [0x005A9594], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9594u, ctx.xmm[0].u32[0]);
	// 0x2C4FD0: ret
	return;
}

void sub_2C4FE0(X86Context& ctx, uint8_t* base) {
	// 0x2C4FE0: movss xmm0, dword ptr [0x005A9594]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9594u);
	// 0x2C4FE8: movss [0x005A9598], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9598u, ctx.xmm[0].u32[0]);
	// 0x2C4FF0: ret
	return;
}

void sub_2C5000(X86Context& ctx, uint8_t* base) {
	// 0x2C5000: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5008: movss [0x005A9570], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9570u, ctx.xmm[0].u32[0]);
	// 0x2C5010: ret
	return;
}

void sub_2C5020(X86Context& ctx, uint8_t* base) {
	// 0x2C5020: movss xmm0, dword ptr [0x005A9578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9578u);
	// 0x2C5028: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5030: movss [0x005A956C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A956Cu, ctx.xmm[0].u32[0]);
	// 0x2C5038: ret
	return;
}

void sub_2C5040(X86Context& ctx, uint8_t* base) {
	// 0x2C5040: movss xmm0, dword ptr [0x005A9578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9578u);
	// 0x2C5048: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C5050: movss [0x005A9584], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9584u, ctx.xmm[0].u32[0]);
	// 0x2C5058: ret
	return;
}

void sub_2C5060(X86Context& ctx, uint8_t* base) {
	// 0x2C5060: movss xmm0, dword ptr [0x005A9578]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9578u);
	// 0x2C5068: subss xmm0, [0x005A9584]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A9584u);
	// 0x2C5070: movss [0x005A9564], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9564u, ctx.xmm[0].u32[0]);
	// 0x2C5078: ret
	return;
}

void sub_2C5080(X86Context& ctx, uint8_t* base) {
	// 0x2C5080: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C5088: movss [0x005A95C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95C0u, ctx.xmm[0].u32[0]);
	// 0x2C5090: ret
	return;
}

void sub_2C50A0(X86Context& ctx, uint8_t* base) {
	// 0x2C50A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C50A8: movss [0x005A95CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95CCu, ctx.xmm[0].u32[0]);
	// 0x2C50B0: ret
	return;
}

void sub_2C50C0(X86Context& ctx, uint8_t* base) {
	// 0x2C50C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C50C8: movss [0x005A95B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95B8u, ctx.xmm[0].u32[0]);
	// 0x2C50D0: ret
	return;
}

void sub_2C50E0(X86Context& ctx, uint8_t* base) {
	// 0x2C50E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C50E8: movss [0x005A95A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95A0u, ctx.xmm[0].u32[0]);
	// 0x2C50F0: ret
	return;
}

void sub_2C5100(X86Context& ctx, uint8_t* base) {
	// 0x2C5100: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5108: movss [0x005A95C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95C4u, ctx.xmm[0].u32[0]);
	// 0x2C5110: ret
	return;
}

void sub_2C5120(X86Context& ctx, uint8_t* base) {
	// 0x2C5120: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5128: movss [0x005A95A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95A4u, ctx.xmm[0].u32[0]);
	// 0x2C5130: ret
	return;
}

void sub_2C5140(X86Context& ctx, uint8_t* base) {
	// 0x2C5140: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C5148: movss [0x005A95D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95D4u, ctx.xmm[0].u32[0]);
	// 0x2C5150: ret
	return;
}

void sub_2C5160(X86Context& ctx, uint8_t* base) {
	// 0x2C5160: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C5168: movss [0x005A95BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95BCu, ctx.xmm[0].u32[0]);
	// 0x2C5170: ret
	return;
}

void sub_2C5180(X86Context& ctx, uint8_t* base) {
	// 0x2C5180: movss xmm0, dword ptr [0x005A95D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A95D4u);
	// 0x2C5188: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C5190: movss [0x005A95AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95ACu, ctx.xmm[0].u32[0]);
	// 0x2C5198: ret
	return;
}

void sub_2C51A0(X86Context& ctx, uint8_t* base) {
	// 0x2C51A0: movss xmm0, dword ptr [0x005A95BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A95BCu);
	// 0x2C51A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C51B0: movss [0x005A95D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95D0u, ctx.xmm[0].u32[0]);
	// 0x2C51B8: ret
	return;
}

void sub_2C51C0(X86Context& ctx, uint8_t* base) {
	// 0x2C51C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C51C8: movss [0x005A95E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95E0u, ctx.xmm[0].u32[0]);
	// 0x2C51D0: ret
	return;
}

void sub_2C51E0(X86Context& ctx, uint8_t* base) {
	// 0x2C51E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C51E8: movss [0x005A95D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95D8u, ctx.xmm[0].u32[0]);
	// 0x2C51F0: ret
	return;
}

void sub_2C5200(X86Context& ctx, uint8_t* base) {
	// 0x2C5200: movss xmm0, dword ptr [0x005A95D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A95D8u);
	// 0x2C5208: movss [0x005A95DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95DCu, ctx.xmm[0].u32[0]);
	// 0x2C5210: ret
	return;
}

void sub_2C5220(X86Context& ctx, uint8_t* base) {
	// 0x2C5220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5228: movss [0x005A95B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95B4u, ctx.xmm[0].u32[0]);
	// 0x2C5230: ret
	return;
}

void sub_2C5240(X86Context& ctx, uint8_t* base) {
	// 0x2C5240: movss xmm0, dword ptr [0x005A95BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A95BCu);
	// 0x2C5248: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5250: movss [0x005A95B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95B0u, ctx.xmm[0].u32[0]);
	// 0x2C5258: ret
	return;
}

void sub_2C5260(X86Context& ctx, uint8_t* base) {
	// 0x2C5260: movss xmm0, dword ptr [0x005A95BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A95BCu);
	// 0x2C5268: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C5270: movss [0x005A95C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95C8u, ctx.xmm[0].u32[0]);
	// 0x2C5278: ret
	return;
}

void sub_2C5280(X86Context& ctx, uint8_t* base) {
	// 0x2C5280: movss xmm0, dword ptr [0x005A95BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A95BCu);
	// 0x2C5288: subss xmm0, [0x005A95C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A95C8u);
	// 0x2C5290: movss [0x005A95A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95A8u, ctx.xmm[0].u32[0]);
	// 0x2C5298: ret
	return;
}

void sub_2C52A0(X86Context& ctx, uint8_t* base) {
	// 0x2C52A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C52A8: movss [0x005A9604], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9604u, ctx.xmm[0].u32[0]);
	// 0x2C52B0: ret
	return;
}

void sub_2C52C0(X86Context& ctx, uint8_t* base) {
	// 0x2C52C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C52C8: movss [0x005A9610], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9610u, ctx.xmm[0].u32[0]);
	// 0x2C52D0: ret
	return;
}

void sub_2C52E0(X86Context& ctx, uint8_t* base) {
	// 0x2C52E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C52E8: movss [0x005A95FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95FCu, ctx.xmm[0].u32[0]);
	// 0x2C52F0: ret
	return;
}

void sub_2C5300(X86Context& ctx, uint8_t* base) {
	// 0x2C5300: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C5308: movss [0x005A95E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95E4u, ctx.xmm[0].u32[0]);
	// 0x2C5310: ret
	return;
}

void sub_2C5320(X86Context& ctx, uint8_t* base) {
	// 0x2C5320: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C5328: movss [0x005A9608], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9608u, ctx.xmm[0].u32[0]);
	// 0x2C5330: ret
	return;
}

void sub_2C5340(X86Context& ctx, uint8_t* base) {
	// 0x2C5340: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C5348: movss [0x005A95E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95E8u, ctx.xmm[0].u32[0]);
	// 0x2C5350: ret
	return;
}

void sub_2C5360(X86Context& ctx, uint8_t* base) {
	// 0x2C5360: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C5368: movss [0x005A9618], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9618u, ctx.xmm[0].u32[0]);
	// 0x2C5370: ret
	return;
}

void sub_2C5380(X86Context& ctx, uint8_t* base) {
	// 0x2C5380: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C5388: movss [0x005A9600], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9600u, ctx.xmm[0].u32[0]);
	// 0x2C5390: ret
	return;
}

void sub_2C53A0(X86Context& ctx, uint8_t* base) {
	// 0x2C53A0: movss xmm0, dword ptr [0x005A9618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9618u);
	// 0x2C53A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C53B0: movss [0x005A95F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95F0u, ctx.xmm[0].u32[0]);
	// 0x2C53B8: ret
	return;
}

void sub_2C53C0(X86Context& ctx, uint8_t* base) {
	// 0x2C53C0: movss xmm0, dword ptr [0x005A9600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9600u);
	// 0x2C53C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C53D0: movss [0x005A9614], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9614u, ctx.xmm[0].u32[0]);
	// 0x2C53D8: ret
	return;
}

void sub_2C53E0(X86Context& ctx, uint8_t* base) {
	// 0x2C53E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C53E8: movss [0x005A9624], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9624u, ctx.xmm[0].u32[0]);
	// 0x2C53F0: ret
	return;
}

void sub_2C5400(X86Context& ctx, uint8_t* base) {
	// 0x2C5400: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C5408: movss [0x005A961C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A961Cu, ctx.xmm[0].u32[0]);
	// 0x2C5410: ret
	return;
}

void sub_2C5420(X86Context& ctx, uint8_t* base) {
	// 0x2C5420: movss xmm0, dword ptr [0x005A961C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A961Cu);
	// 0x2C5428: movss [0x005A9620], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9620u, ctx.xmm[0].u32[0]);
	// 0x2C5430: ret
	return;
}

void sub_2C5440(X86Context& ctx, uint8_t* base) {
	// 0x2C5440: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C5448: movss [0x005A95F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95F8u, ctx.xmm[0].u32[0]);
	// 0x2C5450: ret
	return;
}

void sub_2C5460(X86Context& ctx, uint8_t* base) {
	// 0x2C5460: movss xmm0, dword ptr [0x005A9600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9600u);
	// 0x2C5468: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C5470: movss [0x005A95F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95F4u, ctx.xmm[0].u32[0]);
	// 0x2C5478: ret
	return;
}

void sub_2C5480(X86Context& ctx, uint8_t* base) {
	// 0x2C5480: movss xmm0, dword ptr [0x005A9600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9600u);
	// 0x2C5488: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C5490: movss [0x005A960C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A960Cu, ctx.xmm[0].u32[0]);
	// 0x2C5498: ret
	return;
}

void sub_2C54A0(X86Context& ctx, uint8_t* base) {
	// 0x2C54A0: movss xmm0, dword ptr [0x005A9600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A9600u);
	// 0x2C54A8: subss xmm0, [0x005A960C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A960Cu);
	// 0x2C54B0: movss [0x005A95EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A95ECu, ctx.xmm[0].u32[0]);
	// 0x2C54B8: ret
	return;
}

void sub_2C54C0(X86Context& ctx, uint8_t* base) {
	// 0x2C54C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C54C8: movss [0x005A9648], xmm0
	X86_MEM_WRITE_u32(base, 0x5A9648u, ctx.xmm[0].u32[0]);
	// 0x2C54D0: ret
	return;
}

