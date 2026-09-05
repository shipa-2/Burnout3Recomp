#include "x86_recomp_shared.h"

void sub_291D20(X86Context& ctx, uint8_t* base) {
	// 0x291D20: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x291D28: movss [0x0056C634], xmm0
	X86_MEM_WRITE_u32(base, 0x56C634u, ctx.xmm[0].u32[0]);
	// 0x291D30: ret
	return;
}

void sub_291D40(X86Context& ctx, uint8_t* base) {
	// 0x291D40: movss xmm0, dword ptr [0x0056C654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C654u);
	// 0x291D48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291D50: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x291D58: movss [0x0056C6A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6A4u, ctx.xmm[0].u32[0]);
	// 0x291D60: ret
	return;
}

void sub_291D70(X86Context& ctx, uint8_t* base) {
	// 0x291D70: movss xmm0, dword ptr [0x0056C6A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6A8u);
	// 0x291D78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291D80: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x291D88: movss [0x0056C64C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C64Cu, ctx.xmm[0].u32[0]);
	// 0x291D90: ret
	return;
}

void sub_291DA0(X86Context& ctx, uint8_t* base) {
	// 0x291DA0: movss xmm0, dword ptr [0x0056C654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C654u);
	// 0x291DA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291DB0: movss [0x0056C650], xmm0
	X86_MEM_WRITE_u32(base, 0x56C650u, ctx.xmm[0].u32[0]);
	// 0x291DB8: ret
	return;
}

void sub_291DC0(X86Context& ctx, uint8_t* base) {
	// 0x291DC0: movss xmm0, dword ptr [0x0056C6A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6A8u);
	// 0x291DC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x291DD0: movss [0x0056C6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6B0u, ctx.xmm[0].u32[0]);
	// 0x291DD8: ret
	return;
}

void sub_291DE0(X86Context& ctx, uint8_t* base) {
	// 0x291DE0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x291DE8: movss [0x0056C638], xmm0
	X86_MEM_WRITE_u32(base, 0x56C638u, ctx.xmm[0].u32[0]);
	// 0x291DF0: ret
	return;
}

void sub_291E00(X86Context& ctx, uint8_t* base) {
	// 0x291E00: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x291E08: movss [0x0056C660], xmm0
	X86_MEM_WRITE_u32(base, 0x56C660u, ctx.xmm[0].u32[0]);
	// 0x291E10: ret
	return;
}

void sub_291E20(X86Context& ctx, uint8_t* base) {
	// 0x291E20: movss xmm0, dword ptr [0x0056C638]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C638u);
	// 0x291E28: movss [0x0056C6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6C4u, ctx.xmm[0].u32[0]);
	// 0x291E30: ret
	return;
}

void sub_291E40(X86Context& ctx, uint8_t* base) {
	// 0x291E40: movss xmm0, dword ptr [0x0056C6A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6A8u);
	// 0x291E48: subss xmm0, [0x0056C638]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C638u);
	// 0x291E50: movss [0x0056C688], xmm0
	X86_MEM_WRITE_u32(base, 0x56C688u, ctx.xmm[0].u32[0]);
	// 0x291E58: ret
	return;
}

void sub_291E60(X86Context& ctx, uint8_t* base) {
	// 0x291E60: movss xmm0, dword ptr [0x0056C688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C688u);
	// 0x291E68: subss xmm0, [0x0056C660]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C660u);
	// 0x291E70: movss [0x0056C680], xmm0
	X86_MEM_WRITE_u32(base, 0x56C680u, ctx.xmm[0].u32[0]);
	// 0x291E78: ret
	return;
}

void sub_291E80(X86Context& ctx, uint8_t* base) {
	// 0x291E80: movss xmm0, dword ptr [0x0056C6B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6B0u);
	// 0x291E88: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x291E90: movss [0x0056C670], xmm0
	X86_MEM_WRITE_u32(base, 0x56C670u, ctx.xmm[0].u32[0]);
	// 0x291E98: ret
	return;
}

void sub_291EA0(X86Context& ctx, uint8_t* base) {
	// 0x291EA0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x291EA8: movss [0x0056C65C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C65Cu, ctx.xmm[0].u32[0]);
	// 0x291EB0: ret
	return;
}

void sub_291EC0(X86Context& ctx, uint8_t* base) {
	// 0x291EC0: movss xmm0, dword ptr [0x0056C670]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C670u);
	// 0x291EC8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x291ED0: movss [0x0056C6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6A0u, ctx.xmm[0].u32[0]);
	// 0x291ED8: ret
	return;
}

void sub_291EE0(X86Context& ctx, uint8_t* base) {
	// 0x291EE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x291EE8: movss [0x0056C724], xmm0
	X86_MEM_WRITE_u32(base, 0x56C724u, ctx.xmm[0].u32[0]);
	// 0x291EF0: ret
	return;
}

void sub_291F00(X86Context& ctx, uint8_t* base) {
	// 0x291F00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x291F08: movss [0x0056C740], xmm0
	X86_MEM_WRITE_u32(base, 0x56C740u, ctx.xmm[0].u32[0]);
	// 0x291F10: ret
	return;
}

void sub_291F20(X86Context& ctx, uint8_t* base) {
	// 0x291F20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x291F28: movss [0x0056C718], xmm0
	X86_MEM_WRITE_u32(base, 0x56C718u, ctx.xmm[0].u32[0]);
	// 0x291F30: ret
	return;
}

void sub_291F40(X86Context& ctx, uint8_t* base) {
	// 0x291F40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x291F48: movss [0x0056C6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6D0u, ctx.xmm[0].u32[0]);
	// 0x291F50: ret
	return;
}

void sub_291F60(X86Context& ctx, uint8_t* base) {
	// 0x291F60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x291F68: movss [0x0056C728], xmm0
	X86_MEM_WRITE_u32(base, 0x56C728u, ctx.xmm[0].u32[0]);
	// 0x291F70: ret
	return;
}

void sub_291F80(X86Context& ctx, uint8_t* base) {
	// 0x291F80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x291F88: movss [0x0056C6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6ECu, ctx.xmm[0].u32[0]);
	// 0x291F90: ret
	return;
}

void sub_291FA0(X86Context& ctx, uint8_t* base) {
	// 0x291FA0: movss xmm0, dword ptr [0x0056C728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C728u);
	// 0x291FA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x291FB0: movss [0x0056C760], xmm0
	X86_MEM_WRITE_u32(base, 0x56C760u, ctx.xmm[0].u32[0]);
	// 0x291FB8: ret
	return;
}

void sub_291FC0(X86Context& ctx, uint8_t* base) {
	// 0x291FC0: movss xmm0, dword ptr [0x0056C6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6ECu);
	// 0x291FC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x291FD0: movss [0x0056C748], xmm0
	X86_MEM_WRITE_u32(base, 0x56C748u, ctx.xmm[0].u32[0]);
	// 0x291FD8: ret
	return;
}

void sub_291FE0(X86Context& ctx, uint8_t* base) {
	// 0x291FE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x291FE8: movss [0x0056C778], xmm0
	X86_MEM_WRITE_u32(base, 0x56C778u, ctx.xmm[0].u32[0]);
	// 0x291FF0: ret
	return;
}

void sub_292000(X86Context& ctx, uint8_t* base) {
	// 0x292000: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x292008: movss [0x0056C764], xmm0
	X86_MEM_WRITE_u32(base, 0x56C764u, ctx.xmm[0].u32[0]);
	// 0x292010: ret
	return;
}

void sub_292020(X86Context& ctx, uint8_t* base) {
	// 0x292020: movss xmm0, dword ptr [0x0056C764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C764u);
	// 0x292028: movss [0x0056C774], xmm0
	X86_MEM_WRITE_u32(base, 0x56C774u, ctx.xmm[0].u32[0]);
	// 0x292030: ret
	return;
}

void sub_292040(X86Context& ctx, uint8_t* base) {
	// 0x292040: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x292048: movss [0x0056C6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6D8u, ctx.xmm[0].u32[0]);
	// 0x292050: ret
	return;
}

void sub_292060(X86Context& ctx, uint8_t* base) {
	// 0x292060: movss xmm0, dword ptr [0x0056C6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6ECu);
	// 0x292068: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x292070: movss [0x0056C76C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C76Cu, ctx.xmm[0].u32[0]);
	// 0x292078: ret
	return;
}

void sub_292080(X86Context& ctx, uint8_t* base) {
	// 0x292080: movss xmm0, dword ptr [0x0056C6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6ECu);
	// 0x292088: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x292090: movss [0x0056C714], xmm0
	X86_MEM_WRITE_u32(base, 0x56C714u, ctx.xmm[0].u32[0]);
	// 0x292098: ret
	return;
}

void sub_2920A0(X86Context& ctx, uint8_t* base) {
	// 0x2920A0: movss xmm0, dword ptr [0x0056C6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6ECu);
	// 0x2920A8: subss xmm0, [0x0056C714]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C714u);
	// 0x2920B0: movss [0x0056C6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6F4u, ctx.xmm[0].u32[0]);
	// 0x2920B8: ret
	return;
}

void sub_2920C0(X86Context& ctx, uint8_t* base) {
	// 0x2920C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2920C8: movss [0x0056C73C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C73Cu, ctx.xmm[0].u32[0]);
	// 0x2920D0: ret
	return;
}

void sub_2920E0(X86Context& ctx, uint8_t* base) {
	// 0x2920E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2920E8: movss [0x0056C6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6F0u, ctx.xmm[0].u32[0]);
	// 0x2920F0: ret
	return;
}

void sub_292100(X86Context& ctx, uint8_t* base) {
	// 0x292100: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x292108: movss [0x0056C700], xmm0
	X86_MEM_WRITE_u32(base, 0x56C700u, ctx.xmm[0].u32[0]);
	// 0x292110: ret
	return;
}

void sub_292120(X86Context& ctx, uint8_t* base) {
	// 0x292120: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x292128: movss [0x0056C754], xmm0
	X86_MEM_WRITE_u32(base, 0x56C754u, ctx.xmm[0].u32[0]);
	// 0x292130: ret
	return;
}

void sub_292140(X86Context& ctx, uint8_t* base) {
	// 0x292140: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x292148: movss [0x0056C738], xmm0
	X86_MEM_WRITE_u32(base, 0x56C738u, ctx.xmm[0].u32[0]);
	// 0x292150: ret
	return;
}

void sub_292160(X86Context& ctx, uint8_t* base) {
	// 0x292160: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x292168: movss [0x0056C6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6E8u, ctx.xmm[0].u32[0]);
	// 0x292170: ret
	return;
}

void sub_292180(X86Context& ctx, uint8_t* base) {
	// 0x292180: movss xmm0, dword ptr [0x0056C700]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C700u);
	// 0x292188: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292190: movss [0x0056C6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6DCu, ctx.xmm[0].u32[0]);
	// 0x292198: ret
	return;
}

void sub_2921A0(X86Context& ctx, uint8_t* base) {
	// 0x2921A0: movss xmm0, dword ptr [0x0056C754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C754u);
	// 0x2921A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2921B0: movss [0x0056C720], xmm0
	X86_MEM_WRITE_u32(base, 0x56C720u, ctx.xmm[0].u32[0]);
	// 0x2921B8: ret
	return;
}

void sub_2921C0(X86Context& ctx, uint8_t* base) {
	// 0x2921C0: movss xmm0, dword ptr [0x0056C6DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6DCu);
	// 0x2921C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2921D0: movss [0x0056C730], xmm0
	X86_MEM_WRITE_u32(base, 0x56C730u, ctx.xmm[0].u32[0]);
	// 0x2921D8: ret
	return;
}

void sub_2921E0(X86Context& ctx, uint8_t* base) {
	// 0x2921E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2921E8: movss [0x0056C6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6D4u, ctx.xmm[0].u32[0]);
	// 0x2921F0: ret
	return;
}

void sub_292200(X86Context& ctx, uint8_t* base) {
	// 0x292200: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x292208: movss [0x0056C704], xmm0
	X86_MEM_WRITE_u32(base, 0x56C704u, ctx.xmm[0].u32[0]);
	// 0x292210: ret
	return;
}

void sub_292220(X86Context& ctx, uint8_t* base) {
	// 0x292220: movss xmm0, dword ptr [0x0056C700]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C700u);
	// 0x292228: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x292230: movss [0x0056C710], xmm0
	X86_MEM_WRITE_u32(base, 0x56C710u, ctx.xmm[0].u32[0]);
	// 0x292238: ret
	return;
}

void sub_292240(X86Context& ctx, uint8_t* base) {
	// 0x292240: movss xmm0, dword ptr [0x0056C754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C754u);
	// 0x292248: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x292250: movss [0x0056C758], xmm0
	X86_MEM_WRITE_u32(base, 0x56C758u, ctx.xmm[0].u32[0]);
	// 0x292258: ret
	return;
}

void sub_292260(X86Context& ctx, uint8_t* base) {
	// 0x292260: movss xmm0, dword ptr [0x0056C710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C710u);
	// 0x292268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292270: movss [0x0056C744], xmm0
	X86_MEM_WRITE_u32(base, 0x56C744u, ctx.xmm[0].u32[0]);
	// 0x292278: ret
	return;
}

void sub_292280(X86Context& ctx, uint8_t* base) {
	// 0x292280: movss xmm0, dword ptr [0x0056C758]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C758u);
	// 0x292288: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292290: movss [0x0056C768], xmm0
	X86_MEM_WRITE_u32(base, 0x56C768u, ctx.xmm[0].u32[0]);
	// 0x292298: ret
	return;
}

void sub_2922A0(X86Context& ctx, uint8_t* base) {
	// 0x2922A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2922A8: movss [0x0056C6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6E0u, ctx.xmm[0].u32[0]);
	// 0x2922B0: ret
	return;
}

void sub_2922C0(X86Context& ctx, uint8_t* base) {
	// 0x2922C0: movss xmm0, dword ptr [0x0056C700]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C700u);
	// 0x2922C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2922D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2922D8: movss [0x0056C750], xmm0
	X86_MEM_WRITE_u32(base, 0x56C750u, ctx.xmm[0].u32[0]);
	// 0x2922E0: ret
	return;
}

void sub_2922F0(X86Context& ctx, uint8_t* base) {
	// 0x2922F0: movss xmm0, dword ptr [0x0056C754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C754u);
	// 0x2922F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292300: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x292308: movss [0x0056C6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6F8u, ctx.xmm[0].u32[0]);
	// 0x292310: ret
	return;
}

void sub_292320(X86Context& ctx, uint8_t* base) {
	// 0x292320: movss xmm0, dword ptr [0x0056C700]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C700u);
	// 0x292328: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292330: movss [0x0056C6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6FCu, ctx.xmm[0].u32[0]);
	// 0x292338: ret
	return;
}

void sub_292340(X86Context& ctx, uint8_t* base) {
	// 0x292340: movss xmm0, dword ptr [0x0056C754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C754u);
	// 0x292348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292350: movss [0x0056C75C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C75Cu, ctx.xmm[0].u32[0]);
	// 0x292358: ret
	return;
}

void sub_292360(X86Context& ctx, uint8_t* base) {
	// 0x292360: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x292368: movss [0x0056C6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C6E4u, ctx.xmm[0].u32[0]);
	// 0x292370: ret
	return;
}

void sub_292380(X86Context& ctx, uint8_t* base) {
	// 0x292380: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x292388: movss [0x0056C70C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C70Cu, ctx.xmm[0].u32[0]);
	// 0x292390: ret
	return;
}

void sub_2923A0(X86Context& ctx, uint8_t* base) {
	// 0x2923A0: movss xmm0, dword ptr [0x0056C6E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C6E4u);
	// 0x2923A8: movss [0x0056C770], xmm0
	X86_MEM_WRITE_u32(base, 0x56C770u, ctx.xmm[0].u32[0]);
	// 0x2923B0: ret
	return;
}

void sub_2923C0(X86Context& ctx, uint8_t* base) {
	// 0x2923C0: movss xmm0, dword ptr [0x0056C754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C754u);
	// 0x2923C8: subss xmm0, [0x0056C6E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C6E4u);
	// 0x2923D0: movss [0x0056C734], xmm0
	X86_MEM_WRITE_u32(base, 0x56C734u, ctx.xmm[0].u32[0]);
	// 0x2923D8: ret
	return;
}

void sub_2923E0(X86Context& ctx, uint8_t* base) {
	// 0x2923E0: movss xmm0, dword ptr [0x0056C734]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C734u);
	// 0x2923E8: subss xmm0, [0x0056C70C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C70Cu);
	// 0x2923F0: movss [0x0056C72C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C72Cu, ctx.xmm[0].u32[0]);
	// 0x2923F8: ret
	return;
}

void sub_292400(X86Context& ctx, uint8_t* base) {
	// 0x292400: movss xmm0, dword ptr [0x0056C75C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C75Cu);
	// 0x292408: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x292410: movss [0x0056C71C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C71Cu, ctx.xmm[0].u32[0]);
	// 0x292418: ret
	return;
}

void sub_292420(X86Context& ctx, uint8_t* base) {
	// 0x292420: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x292428: movss [0x0056C708], xmm0
	X86_MEM_WRITE_u32(base, 0x56C708u, ctx.xmm[0].u32[0]);
	// 0x292430: ret
	return;
}

void sub_292440(X86Context& ctx, uint8_t* base) {
	// 0x292440: movss xmm0, dword ptr [0x0056C71C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C71Cu);
	// 0x292448: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x292450: movss [0x0056C74C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C74Cu, ctx.xmm[0].u32[0]);
	// 0x292458: ret
	return;
}

void sub_292460(X86Context& ctx, uint8_t* base) {
	// 0x292460: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x292468: movss [0x0056C7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7D0u, ctx.xmm[0].u32[0]);
	// 0x292470: ret
	return;
}

void sub_292480(X86Context& ctx, uint8_t* base) {
	// 0x292480: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x292488: movss [0x0056C7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7ECu, ctx.xmm[0].u32[0]);
	// 0x292490: ret
	return;
}

void sub_2924A0(X86Context& ctx, uint8_t* base) {
	// 0x2924A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2924A8: movss [0x0056C7C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7C4u, ctx.xmm[0].u32[0]);
	// 0x2924B0: ret
	return;
}

void sub_2924C0(X86Context& ctx, uint8_t* base) {
	// 0x2924C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2924C8: movss [0x0056C77C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C77Cu, ctx.xmm[0].u32[0]);
	// 0x2924D0: ret
	return;
}

void sub_2924E0(X86Context& ctx, uint8_t* base) {
	// 0x2924E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2924E8: movss [0x0056C7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7D4u, ctx.xmm[0].u32[0]);
	// 0x2924F0: ret
	return;
}

void sub_292500(X86Context& ctx, uint8_t* base) {
	// 0x292500: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x292508: movss [0x0056C798], xmm0
	X86_MEM_WRITE_u32(base, 0x56C798u, ctx.xmm[0].u32[0]);
	// 0x292510: ret
	return;
}

void sub_292520(X86Context& ctx, uint8_t* base) {
	// 0x292520: movss xmm0, dword ptr [0x0056C7D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7D4u);
	// 0x292528: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292530: movss [0x0056C80C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C80Cu, ctx.xmm[0].u32[0]);
	// 0x292538: ret
	return;
}

void sub_292540(X86Context& ctx, uint8_t* base) {
	// 0x292540: movss xmm0, dword ptr [0x0056C798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C798u);
	// 0x292548: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x292550: movss [0x0056C7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7F4u, ctx.xmm[0].u32[0]);
	// 0x292558: ret
	return;
}

void sub_292560(X86Context& ctx, uint8_t* base) {
	// 0x292560: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x292568: movss [0x0056C824], xmm0
	X86_MEM_WRITE_u32(base, 0x56C824u, ctx.xmm[0].u32[0]);
	// 0x292570: ret
	return;
}

void sub_292580(X86Context& ctx, uint8_t* base) {
	// 0x292580: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x292588: movss [0x0056C810], xmm0
	X86_MEM_WRITE_u32(base, 0x56C810u, ctx.xmm[0].u32[0]);
	// 0x292590: ret
	return;
}

void sub_2925A0(X86Context& ctx, uint8_t* base) {
	// 0x2925A0: movss xmm0, dword ptr [0x0056C810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C810u);
	// 0x2925A8: movss [0x0056C820], xmm0
	X86_MEM_WRITE_u32(base, 0x56C820u, ctx.xmm[0].u32[0]);
	// 0x2925B0: ret
	return;
}

void sub_2925C0(X86Context& ctx, uint8_t* base) {
	// 0x2925C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2925C8: movss [0x0056C784], xmm0
	X86_MEM_WRITE_u32(base, 0x56C784u, ctx.xmm[0].u32[0]);
	// 0x2925D0: ret
	return;
}

void sub_2925E0(X86Context& ctx, uint8_t* base) {
	// 0x2925E0: movss xmm0, dword ptr [0x0056C798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C798u);
	// 0x2925E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2925F0: movss [0x0056C818], xmm0
	X86_MEM_WRITE_u32(base, 0x56C818u, ctx.xmm[0].u32[0]);
	// 0x2925F8: ret
	return;
}

void sub_292600(X86Context& ctx, uint8_t* base) {
	// 0x292600: movss xmm0, dword ptr [0x0056C798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C798u);
	// 0x292608: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x292610: movss [0x0056C7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7C0u, ctx.xmm[0].u32[0]);
	// 0x292618: ret
	return;
}

void sub_292620(X86Context& ctx, uint8_t* base) {
	// 0x292620: movss xmm0, dword ptr [0x0056C798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C798u);
	// 0x292628: subss xmm0, [0x0056C7C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C7C0u);
	// 0x292630: movss [0x0056C7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7A0u, ctx.xmm[0].u32[0]);
	// 0x292638: ret
	return;
}

void sub_292640(X86Context& ctx, uint8_t* base) {
	// 0x292640: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x292648: movss [0x0056C7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7E8u, ctx.xmm[0].u32[0]);
	// 0x292650: ret
	return;
}

void sub_292660(X86Context& ctx, uint8_t* base) {
	// 0x292660: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x292668: movss [0x0056C79C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C79Cu, ctx.xmm[0].u32[0]);
	// 0x292670: ret
	return;
}

void sub_292680(X86Context& ctx, uint8_t* base) {
	// 0x292680: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x292688: movss [0x0056C7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7ACu, ctx.xmm[0].u32[0]);
	// 0x292690: ret
	return;
}

void sub_2926A0(X86Context& ctx, uint8_t* base) {
	// 0x2926A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2926A8: movss [0x0056C800], xmm0
	X86_MEM_WRITE_u32(base, 0x56C800u, ctx.xmm[0].u32[0]);
	// 0x2926B0: ret
	return;
}

void sub_2926C0(X86Context& ctx, uint8_t* base) {
	// 0x2926C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2926C8: movss [0x0056C7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7E4u, ctx.xmm[0].u32[0]);
	// 0x2926D0: ret
	return;
}

void sub_2926E0(X86Context& ctx, uint8_t* base) {
	// 0x2926E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2926E8: movss [0x0056C794], xmm0
	X86_MEM_WRITE_u32(base, 0x56C794u, ctx.xmm[0].u32[0]);
	// 0x2926F0: ret
	return;
}

void sub_292700(X86Context& ctx, uint8_t* base) {
	// 0x292700: movss xmm0, dword ptr [0x0056C7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7ACu);
	// 0x292708: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292710: movss [0x0056C788], xmm0
	X86_MEM_WRITE_u32(base, 0x56C788u, ctx.xmm[0].u32[0]);
	// 0x292718: ret
	return;
}

void sub_292720(X86Context& ctx, uint8_t* base) {
	// 0x292720: movss xmm0, dword ptr [0x0056C800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C800u);
	// 0x292728: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x292730: movss [0x0056C7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7CCu, ctx.xmm[0].u32[0]);
	// 0x292738: ret
	return;
}

void sub_292740(X86Context& ctx, uint8_t* base) {
	// 0x292740: movss xmm0, dword ptr [0x0056C788]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C788u);
	// 0x292748: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292750: movss [0x0056C7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7DCu, ctx.xmm[0].u32[0]);
	// 0x292758: ret
	return;
}

void sub_292760(X86Context& ctx, uint8_t* base) {
	// 0x292760: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x292768: movss [0x0056C780], xmm0
	X86_MEM_WRITE_u32(base, 0x56C780u, ctx.xmm[0].u32[0]);
	// 0x292770: ret
	return;
}

void sub_292780(X86Context& ctx, uint8_t* base) {
	// 0x292780: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x292788: movss [0x0056C7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7B0u, ctx.xmm[0].u32[0]);
	// 0x292790: ret
	return;
}

void sub_2927A0(X86Context& ctx, uint8_t* base) {
	// 0x2927A0: movss xmm0, dword ptr [0x0056C7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7ACu);
	// 0x2927A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2927B0: movss [0x0056C7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7BCu, ctx.xmm[0].u32[0]);
	// 0x2927B8: ret
	return;
}

void sub_2927C0(X86Context& ctx, uint8_t* base) {
	// 0x2927C0: movss xmm0, dword ptr [0x0056C800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C800u);
	// 0x2927C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2927D0: movss [0x0056C804], xmm0
	X86_MEM_WRITE_u32(base, 0x56C804u, ctx.xmm[0].u32[0]);
	// 0x2927D8: ret
	return;
}

void sub_2927E0(X86Context& ctx, uint8_t* base) {
	// 0x2927E0: movss xmm0, dword ptr [0x0056C7BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7BCu);
	// 0x2927E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2927F0: movss [0x0056C7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7F0u, ctx.xmm[0].u32[0]);
	// 0x2927F8: ret
	return;
}

void sub_292800(X86Context& ctx, uint8_t* base) {
	// 0x292800: movss xmm0, dword ptr [0x0056C804]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C804u);
	// 0x292808: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292810: movss [0x0056C814], xmm0
	X86_MEM_WRITE_u32(base, 0x56C814u, ctx.xmm[0].u32[0]);
	// 0x292818: ret
	return;
}

void sub_292820(X86Context& ctx, uint8_t* base) {
	// 0x292820: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x292828: movss [0x0056C78C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C78Cu, ctx.xmm[0].u32[0]);
	// 0x292830: ret
	return;
}

void sub_292840(X86Context& ctx, uint8_t* base) {
	// 0x292840: movss xmm0, dword ptr [0x0056C7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7ACu);
	// 0x292848: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292850: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x292858: movss [0x0056C7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7FCu, ctx.xmm[0].u32[0]);
	// 0x292860: ret
	return;
}

void sub_292870(X86Context& ctx, uint8_t* base) {
	// 0x292870: movss xmm0, dword ptr [0x0056C800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C800u);
	// 0x292878: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292880: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x292888: movss [0x0056C7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7A4u, ctx.xmm[0].u32[0]);
	// 0x292890: ret
	return;
}

void sub_2928A0(X86Context& ctx, uint8_t* base) {
	// 0x2928A0: movss xmm0, dword ptr [0x0056C7AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7ACu);
	// 0x2928A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2928B0: movss [0x0056C7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7A8u, ctx.xmm[0].u32[0]);
	// 0x2928B8: ret
	return;
}

void sub_2928C0(X86Context& ctx, uint8_t* base) {
	// 0x2928C0: movss xmm0, dword ptr [0x0056C800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C800u);
	// 0x2928C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2928D0: movss [0x0056C808], xmm0
	X86_MEM_WRITE_u32(base, 0x56C808u, ctx.xmm[0].u32[0]);
	// 0x2928D8: ret
	return;
}

void sub_2928E0(X86Context& ctx, uint8_t* base) {
	// 0x2928E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2928E8: movss [0x0056C790], xmm0
	X86_MEM_WRITE_u32(base, 0x56C790u, ctx.xmm[0].u32[0]);
	// 0x2928F0: ret
	return;
}

void sub_292900(X86Context& ctx, uint8_t* base) {
	// 0x292900: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x292908: movss [0x0056C7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7B8u, ctx.xmm[0].u32[0]);
	// 0x292910: ret
	return;
}

void sub_292920(X86Context& ctx, uint8_t* base) {
	// 0x292920: movss xmm0, dword ptr [0x0056C790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C790u);
	// 0x292928: movss [0x0056C81C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C81Cu, ctx.xmm[0].u32[0]);
	// 0x292930: ret
	return;
}

void sub_292940(X86Context& ctx, uint8_t* base) {
	// 0x292940: movss xmm0, dword ptr [0x0056C800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C800u);
	// 0x292948: subss xmm0, [0x0056C790]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C790u);
	// 0x292950: movss [0x0056C7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7E0u, ctx.xmm[0].u32[0]);
	// 0x292958: ret
	return;
}

void sub_292960(X86Context& ctx, uint8_t* base) {
	// 0x292960: movss xmm0, dword ptr [0x0056C7E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7E0u);
	// 0x292968: subss xmm0, [0x0056C7B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C7B8u);
	// 0x292970: movss [0x0056C7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7D8u, ctx.xmm[0].u32[0]);
	// 0x292978: ret
	return;
}

void sub_292980(X86Context& ctx, uint8_t* base) {
	// 0x292980: movss xmm0, dword ptr [0x0056C808]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C808u);
	// 0x292988: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x292990: movss [0x0056C7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7C8u, ctx.xmm[0].u32[0]);
	// 0x292998: ret
	return;
}

void sub_2929A0(X86Context& ctx, uint8_t* base) {
	// 0x2929A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2929A8: movss [0x0056C7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7B4u, ctx.xmm[0].u32[0]);
	// 0x2929B0: ret
	return;
}

void sub_2929C0(X86Context& ctx, uint8_t* base) {
	// 0x2929C0: movss xmm0, dword ptr [0x0056C7C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C7C8u);
	// 0x2929C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2929D0: movss [0x0056C7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C7F8u, ctx.xmm[0].u32[0]);
	// 0x2929D8: ret
	return;
}

void sub_2929E0(X86Context& ctx, uint8_t* base) {
	// 0x2929E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2929E8: movss [0x0056D840], xmm0
	X86_MEM_WRITE_u32(base, 0x56D840u, ctx.xmm[0].u32[0]);
	// 0x2929F0: ret
	return;
}

void sub_292A00(X86Context& ctx, uint8_t* base) {
	// 0x292A00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x292A08: movss [0x0056D808], xmm0
	X86_MEM_WRITE_u32(base, 0x56D808u, ctx.xmm[0].u32[0]);
	// 0x292A10: ret
	return;
}

void sub_292A20(X86Context& ctx, uint8_t* base) {
	// 0x292A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x292A28: movss [0x0056D838], xmm0
	X86_MEM_WRITE_u32(base, 0x56D838u, ctx.xmm[0].u32[0]);
	// 0x292A30: ret
	return;
}

void sub_292A40(X86Context& ctx, uint8_t* base) {
	// 0x292A40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x292A48: movss [0x0056C828], xmm0
	X86_MEM_WRITE_u32(base, 0x56C828u, ctx.xmm[0].u32[0]);
	// 0x292A50: ret
	return;
}

void sub_292A60(X86Context& ctx, uint8_t* base) {
	// 0x292A60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x292A68: movss [0x0056D83C], xmm0
	X86_MEM_WRITE_u32(base, 0x56D83Cu, ctx.xmm[0].u32[0]);
	// 0x292A70: ret
	return;
}

void sub_292A80(X86Context& ctx, uint8_t* base) {
	// 0x292A80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x292A88: movss [0x0056C83C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C83Cu, ctx.xmm[0].u32[0]);
	// 0x292A90: ret
	return;
}

void sub_292AA0(X86Context& ctx, uint8_t* base) {
	// 0x292AA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x292AA8: movss [0x0056DB40], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB40u, ctx.xmm[0].u32[0]);
	// 0x292AB0: ret
	return;
}

void sub_292AC0(X86Context& ctx, uint8_t* base) {
	// 0x292AC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x292AC8: movss [0x0056D830], xmm0
	X86_MEM_WRITE_u32(base, 0x56D830u, ctx.xmm[0].u32[0]);
	// 0x292AD0: ret
	return;
}

void sub_292AE0(X86Context& ctx, uint8_t* base) {
	// 0x292AE0: movss xmm0, dword ptr [0x0056DB40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB40u);
	// 0x292AE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292AF0: movss [0x0056C848], xmm0
	X86_MEM_WRITE_u32(base, 0x56C848u, ctx.xmm[0].u32[0]);
	// 0x292AF8: ret
	return;
}

void sub_292B00(X86Context& ctx, uint8_t* base) {
	// 0x292B00: movss xmm0, dword ptr [0x0056D830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D830u);
	// 0x292B08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x292B10: movss [0x0056DB30], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB30u, ctx.xmm[0].u32[0]);
	// 0x292B18: ret
	return;
}

void sub_292B20(X86Context& ctx, uint8_t* base) {
	// 0x292B20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x292B28: movss [0x0056DB54], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB54u, ctx.xmm[0].u32[0]);
	// 0x292B30: ret
	return;
}

void sub_292B40(X86Context& ctx, uint8_t* base) {
	// 0x292B40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x292B48: movss [0x0056DB44], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB44u, ctx.xmm[0].u32[0]);
	// 0x292B50: ret
	return;
}

void sub_292B60(X86Context& ctx, uint8_t* base) {
	// 0x292B60: movss xmm0, dword ptr [0x0056DB44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB44u);
	// 0x292B68: movss [0x0056DB50], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB50u, ctx.xmm[0].u32[0]);
	// 0x292B70: ret
	return;
}

void sub_292B80(X86Context& ctx, uint8_t* base) {
	// 0x292B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x292B88: movss [0x0056D804], xmm0
	X86_MEM_WRITE_u32(base, 0x56D804u, ctx.xmm[0].u32[0]);
	// 0x292B90: ret
	return;
}

void sub_292BA0(X86Context& ctx, uint8_t* base) {
	// 0x292BA0: movss xmm0, dword ptr [0x0056D830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D830u);
	// 0x292BA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x292BB0: movss [0x0056D6A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56D6A4u, ctx.xmm[0].u32[0]);
	// 0x292BB8: ret
	return;
}

void sub_292BC0(X86Context& ctx, uint8_t* base) {
	// 0x292BC0: movss xmm0, dword ptr [0x0056D830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D830u);
	// 0x292BC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x292BD0: movss [0x0056D8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56D8A8u, ctx.xmm[0].u32[0]);
	// 0x292BD8: ret
	return;
}

void sub_292BE0(X86Context& ctx, uint8_t* base) {
	// 0x292BE0: movss xmm0, dword ptr [0x0056D830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D830u);
	// 0x292BE8: subss xmm0, [0x0056D8A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56D8A8u);
	// 0x292BF0: movss [0x0056C844], xmm0
	X86_MEM_WRITE_u32(base, 0x56C844u, ctx.xmm[0].u32[0]);
	// 0x292BF8: ret
	return;
}

void sub_292C00(X86Context& ctx, uint8_t* base) {
	// 0x292C00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x292C08: movss [0x0056D7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56D7F0u, ctx.xmm[0].u32[0]);
	// 0x292C10: ret
	return;
}

void sub_292C20(X86Context& ctx, uint8_t* base) {
	// 0x292C20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x292C28: movss [0x0056DB34], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB34u, ctx.xmm[0].u32[0]);
	// 0x292C30: ret
	return;
}

void sub_292C40(X86Context& ctx, uint8_t* base) {
	// 0x292C40: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x292C48: movss [0x0056D8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56D8A4u, ctx.xmm[0].u32[0]);
	// 0x292C50: ret
	return;
}

void sub_292C60(X86Context& ctx, uint8_t* base) {
	// 0x292C60: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x292C68: movss [0x0056C840], xmm0
	X86_MEM_WRITE_u32(base, 0x56C840u, ctx.xmm[0].u32[0]);
	// 0x292C70: ret
	return;
}

void sub_292C80(X86Context& ctx, uint8_t* base) {
	// 0x292C80: movss xmm0, dword ptr [0x0056D7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D7F0u);
	// 0x292C88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292C90: movss [0x0056C830], xmm0
	X86_MEM_WRITE_u32(base, 0x56C830u, ctx.xmm[0].u32[0]);
	// 0x292C98: ret
	return;
}

void sub_292CA0(X86Context& ctx, uint8_t* base) {
	// 0x292CA0: movss xmm0, dword ptr [0x0056DB34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB34u);
	// 0x292CA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x292CB0: movss [0x0056D834], xmm0
	X86_MEM_WRITE_u32(base, 0x56D834u, ctx.xmm[0].u32[0]);
	// 0x292CB8: ret
	return;
}

void sub_292CC0(X86Context& ctx, uint8_t* base) {
	// 0x292CC0: movss xmm0, dword ptr [0x0056C830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C830u);
	// 0x292CC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x292CD0: movss [0x0056D848], xmm0
	X86_MEM_WRITE_u32(base, 0x56D848u, ctx.xmm[0].u32[0]);
	// 0x292CD8: ret
	return;
}

void sub_292CE0(X86Context& ctx, uint8_t* base) {
	// 0x292CE0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x292CE8: movss [0x0056C82C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C82Cu, ctx.xmm[0].u32[0]);
	// 0x292CF0: ret
	return;
}

void sub_292D00(X86Context& ctx, uint8_t* base) {
	// 0x292D00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x292D08: movss [0x0056D7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56D7F4u, ctx.xmm[0].u32[0]);
	// 0x292D10: ret
	return;
}

void sub_292D20(X86Context& ctx, uint8_t* base) {
	// 0x292D20: movss xmm0, dword ptr [0x0056D7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D7F0u);
	// 0x292D28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x292D30: movss [0x0056D800], xmm0
	X86_MEM_WRITE_u32(base, 0x56D800u, ctx.xmm[0].u32[0]);
	// 0x292D38: ret
	return;
}

void sub_292D40(X86Context& ctx, uint8_t* base) {
	// 0x292D40: movss xmm0, dword ptr [0x0056DB34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB34u);
	// 0x292D48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x292D50: movss [0x0056DB38], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB38u, ctx.xmm[0].u32[0]);
	// 0x292D58: ret
	return;
}

void sub_292D60(X86Context& ctx, uint8_t* base) {
	// 0x292D60: movss xmm0, dword ptr [0x0056D800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D800u);
	// 0x292D68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292D70: movss [0x0056D8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56D8ACu, ctx.xmm[0].u32[0]);
	// 0x292D78: ret
	return;
}

void sub_292D80(X86Context& ctx, uint8_t* base) {
	// 0x292D80: movss xmm0, dword ptr [0x0056DB38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB38u);
	// 0x292D88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292D90: movss [0x0056DB48], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB48u, ctx.xmm[0].u32[0]);
	// 0x292D98: ret
	return;
}

void sub_292DA0(X86Context& ctx, uint8_t* base) {
	// 0x292DA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x292DA8: movss [0x0056C834], xmm0
	X86_MEM_WRITE_u32(base, 0x56C834u, ctx.xmm[0].u32[0]);
	// 0x292DB0: ret
	return;
}

void sub_292DC0(X86Context& ctx, uint8_t* base) {
	// 0x292DC0: movss xmm0, dword ptr [0x0056D7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D7F0u);
	// 0x292DC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292DD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x292DD8: movss [0x0056D8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56D8E0u, ctx.xmm[0].u32[0]);
	// 0x292DE0: ret
	return;
}

void sub_292DF0(X86Context& ctx, uint8_t* base) {
	// 0x292DF0: movss xmm0, dword ptr [0x0056DB34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB34u);
	// 0x292DF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292E00: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x292E08: movss [0x0056C84C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C84Cu, ctx.xmm[0].u32[0]);
	// 0x292E10: ret
	return;
}

void sub_292E20(X86Context& ctx, uint8_t* base) {
	// 0x292E20: movss xmm0, dword ptr [0x0056D7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D7F0u);
	// 0x292E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292E30: movss [0x0056D6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56D6A0u, ctx.xmm[0].u32[0]);
	// 0x292E38: ret
	return;
}

void sub_292E40(X86Context& ctx, uint8_t* base) {
	// 0x292E40: movss xmm0, dword ptr [0x0056DB34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB34u);
	// 0x292E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x292E50: movss [0x0056DB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB3Cu, ctx.xmm[0].u32[0]);
	// 0x292E58: ret
	return;
}

void sub_292E60(X86Context& ctx, uint8_t* base) {
	// 0x292E60: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x292E68: movss [0x0056C838], xmm0
	X86_MEM_WRITE_u32(base, 0x56C838u, ctx.xmm[0].u32[0]);
	// 0x292E70: ret
	return;
}

void sub_292E80(X86Context& ctx, uint8_t* base) {
	// 0x292E80: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x292E88: movss [0x0056D7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56D7FCu, ctx.xmm[0].u32[0]);
	// 0x292E90: ret
	return;
}

void sub_292EA0(X86Context& ctx, uint8_t* base) {
	// 0x292EA0: movss xmm0, dword ptr [0x0056C838]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C838u);
	// 0x292EA8: movss [0x0056DB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB4Cu, ctx.xmm[0].u32[0]);
	// 0x292EB0: ret
	return;
}

void sub_292EC0(X86Context& ctx, uint8_t* base) {
	// 0x292EC0: movss xmm0, dword ptr [0x0056DB34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB34u);
	// 0x292EC8: subss xmm0, [0x0056C838]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C838u);
	// 0x292ED0: movss [0x0056D8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56D8A0u, ctx.xmm[0].u32[0]);
	// 0x292ED8: ret
	return;
}

void sub_292EE0(X86Context& ctx, uint8_t* base) {
	// 0x292EE0: movss xmm0, dword ptr [0x0056D8A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D8A0u);
	// 0x292EE8: subss xmm0, [0x0056D7FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56D7FCu);
	// 0x292EF0: movss [0x0056D844], xmm0
	X86_MEM_WRITE_u32(base, 0x56D844u, ctx.xmm[0].u32[0]);
	// 0x292EF8: ret
	return;
}

void sub_292F00(X86Context& ctx, uint8_t* base) {
	// 0x292F00: movss xmm0, dword ptr [0x0056DB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DB3Cu);
	// 0x292F08: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x292F10: movss [0x0056D80C], xmm0
	X86_MEM_WRITE_u32(base, 0x56D80Cu, ctx.xmm[0].u32[0]);
	// 0x292F18: ret
	return;
}

void sub_292F20(X86Context& ctx, uint8_t* base) {
	// 0x292F20: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x292F28: movss [0x0056D7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56D7F8u, ctx.xmm[0].u32[0]);
	// 0x292F30: ret
	return;
}

void sub_292F40(X86Context& ctx, uint8_t* base) {
	// 0x292F40: movss xmm0, dword ptr [0x0056D80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56D80Cu);
	// 0x292F48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x292F50: movss [0x0056D8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56D8B0u, ctx.xmm[0].u32[0]);
	// 0x292F58: ret
	return;
}

void sub_292F60(X86Context& ctx, uint8_t* base) {
	// 0x292F60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x292F68: movss [0x0056E010], xmm0
	X86_MEM_WRITE_u32(base, 0x56E010u, ctx.xmm[0].u32[0]);
	// 0x292F70: ret
	return;
}

void sub_292F80(X86Context& ctx, uint8_t* base) {
	// 0x292F80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x292F88: movss [0x0056E02C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E02Cu, ctx.xmm[0].u32[0]);
	// 0x292F90: ret
	return;
}

void sub_292FA0(X86Context& ctx, uint8_t* base) {
	// 0x292FA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x292FA8: movss [0x0056DFBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFBCu, ctx.xmm[0].u32[0]);
	// 0x292FB0: ret
	return;
}

void sub_292FC0(X86Context& ctx, uint8_t* base) {
	// 0x292FC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x292FC8: movss [0x0056DB58], xmm0
	X86_MEM_WRITE_u32(base, 0x56DB58u, ctx.xmm[0].u32[0]);
	// 0x292FD0: ret
	return;
}

void sub_292FE0(X86Context& ctx, uint8_t* base) {
	// 0x292FE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x292FE8: movss [0x0056E014], xmm0
	X86_MEM_WRITE_u32(base, 0x56E014u, ctx.xmm[0].u32[0]);
	// 0x292FF0: ret
	return;
}

void sub_293000(X86Context& ctx, uint8_t* base) {
	// 0x293000: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x293008: movss [0x0056DDFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDFCu, ctx.xmm[0].u32[0]);
	// 0x293010: ret
	return;
}

void sub_293020(X86Context& ctx, uint8_t* base) {
	// 0x293020: movss xmm0, dword ptr [0x0056E014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E014u);
	// 0x293028: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293030: movss [0x0056E04C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E04Cu, ctx.xmm[0].u32[0]);
	// 0x293038: ret
	return;
}

void sub_293040(X86Context& ctx, uint8_t* base) {
	// 0x293040: movss xmm0, dword ptr [0x0056DDFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDFCu);
	// 0x293048: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x293050: movss [0x0056E034], xmm0
	X86_MEM_WRITE_u32(base, 0x56E034u, ctx.xmm[0].u32[0]);
	// 0x293058: ret
	return;
}

void sub_293060(X86Context& ctx, uint8_t* base) {
	// 0x293060: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x293068: movss [0x0056E064], xmm0
	X86_MEM_WRITE_u32(base, 0x56E064u, ctx.xmm[0].u32[0]);
	// 0x293070: ret
	return;
}

void sub_293080(X86Context& ctx, uint8_t* base) {
	// 0x293080: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x293088: movss [0x0056E050], xmm0
	X86_MEM_WRITE_u32(base, 0x56E050u, ctx.xmm[0].u32[0]);
	// 0x293090: ret
	return;
}

void sub_2930A0(X86Context& ctx, uint8_t* base) {
	// 0x2930A0: movss xmm0, dword ptr [0x0056E050]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E050u);
	// 0x2930A8: movss [0x0056E060], xmm0
	X86_MEM_WRITE_u32(base, 0x56E060u, ctx.xmm[0].u32[0]);
	// 0x2930B0: ret
	return;
}

void sub_2930C0(X86Context& ctx, uint8_t* base) {
	// 0x2930C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2930C8: movss [0x0056DDE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDE8u, ctx.xmm[0].u32[0]);
	// 0x2930D0: ret
	return;
}

void sub_2930E0(X86Context& ctx, uint8_t* base) {
	// 0x2930E0: movss xmm0, dword ptr [0x0056DDFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDFCu);
	// 0x2930E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2930F0: movss [0x0056E058], xmm0
	X86_MEM_WRITE_u32(base, 0x56E058u, ctx.xmm[0].u32[0]);
	// 0x2930F8: ret
	return;
}

void sub_293100(X86Context& ctx, uint8_t* base) {
	// 0x293100: movss xmm0, dword ptr [0x0056DDFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDFCu);
	// 0x293108: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x293110: movss [0x0056DFB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFB8u, ctx.xmm[0].u32[0]);
	// 0x293118: ret
	return;
}

void sub_293120(X86Context& ctx, uint8_t* base) {
	// 0x293120: movss xmm0, dword ptr [0x0056DDFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDFCu);
	// 0x293128: subss xmm0, [0x0056DFB8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56DFB8u);
	// 0x293130: movss [0x0056DF90], xmm0
	X86_MEM_WRITE_u32(base, 0x56DF90u, ctx.xmm[0].u32[0]);
	// 0x293138: ret
	return;
}

void sub_293140(X86Context& ctx, uint8_t* base) {
	// 0x293140: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x293148: movss [0x0056E028], xmm0
	X86_MEM_WRITE_u32(base, 0x56E028u, ctx.xmm[0].u32[0]);
	// 0x293150: ret
	return;
}

void sub_293160(X86Context& ctx, uint8_t* base) {
	// 0x293160: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x293168: movss [0x0056DE00], xmm0
	X86_MEM_WRITE_u32(base, 0x56DE00u, ctx.xmm[0].u32[0]);
	// 0x293170: ret
	return;
}

void sub_293180(X86Context& ctx, uint8_t* base) {
	// 0x293180: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x293188: movss [0x0056DFA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFA4u, ctx.xmm[0].u32[0]);
	// 0x293190: ret
	return;
}

void sub_2931A0(X86Context& ctx, uint8_t* base) {
	// 0x2931A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2931A8: movss [0x0056E040], xmm0
	X86_MEM_WRITE_u32(base, 0x56E040u, ctx.xmm[0].u32[0]);
	// 0x2931B0: ret
	return;
}

void sub_2931C0(X86Context& ctx, uint8_t* base) {
	// 0x2931C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2931C8: movss [0x0056E024], xmm0
	X86_MEM_WRITE_u32(base, 0x56E024u, ctx.xmm[0].u32[0]);
	// 0x2931D0: ret
	return;
}

void sub_2931E0(X86Context& ctx, uint8_t* base) {
	// 0x2931E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2931E8: movss [0x0056DDF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDF8u, ctx.xmm[0].u32[0]);
	// 0x2931F0: ret
	return;
}

void sub_293200(X86Context& ctx, uint8_t* base) {
	// 0x293200: movss xmm0, dword ptr [0x0056DFA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DFA4u);
	// 0x293208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293210: movss [0x0056DDEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDECu, ctx.xmm[0].u32[0]);
	// 0x293218: ret
	return;
}

void sub_293220(X86Context& ctx, uint8_t* base) {
	// 0x293220: movss xmm0, dword ptr [0x0056E040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E040u);
	// 0x293228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x293230: movss [0x0056E00C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E00Cu, ctx.xmm[0].u32[0]);
	// 0x293238: ret
	return;
}

void sub_293240(X86Context& ctx, uint8_t* base) {
	// 0x293240: movss xmm0, dword ptr [0x0056DDEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDECu);
	// 0x293248: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293250: movss [0x0056E01C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E01Cu, ctx.xmm[0].u32[0]);
	// 0x293258: ret
	return;
}

void sub_293260(X86Context& ctx, uint8_t* base) {
	// 0x293260: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x293268: movss [0x0056DDE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDE0u, ctx.xmm[0].u32[0]);
	// 0x293270: ret
	return;
}

void sub_293280(X86Context& ctx, uint8_t* base) {
	// 0x293280: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x293288: movss [0x0056DFA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFA8u, ctx.xmm[0].u32[0]);
	// 0x293290: ret
	return;
}

void sub_2932A0(X86Context& ctx, uint8_t* base) {
	// 0x2932A0: movss xmm0, dword ptr [0x0056DFA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DFA4u);
	// 0x2932A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2932B0: movss [0x0056DFB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFB4u, ctx.xmm[0].u32[0]);
	// 0x2932B8: ret
	return;
}

void sub_2932C0(X86Context& ctx, uint8_t* base) {
	// 0x2932C0: movss xmm0, dword ptr [0x0056E040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E040u);
	// 0x2932C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2932D0: movss [0x0056E044], xmm0
	X86_MEM_WRITE_u32(base, 0x56E044u, ctx.xmm[0].u32[0]);
	// 0x2932D8: ret
	return;
}

void sub_2932E0(X86Context& ctx, uint8_t* base) {
	// 0x2932E0: movss xmm0, dword ptr [0x0056DFB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DFB4u);
	// 0x2932E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2932F0: movss [0x0056E030], xmm0
	X86_MEM_WRITE_u32(base, 0x56E030u, ctx.xmm[0].u32[0]);
	// 0x2932F8: ret
	return;
}

void sub_293300(X86Context& ctx, uint8_t* base) {
	// 0x293300: movss xmm0, dword ptr [0x0056E044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E044u);
	// 0x293308: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293310: movss [0x0056E054], xmm0
	X86_MEM_WRITE_u32(base, 0x56E054u, ctx.xmm[0].u32[0]);
	// 0x293318: ret
	return;
}

void sub_293320(X86Context& ctx, uint8_t* base) {
	// 0x293320: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x293328: movss [0x0056DDF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDF0u, ctx.xmm[0].u32[0]);
	// 0x293330: ret
	return;
}

void sub_293340(X86Context& ctx, uint8_t* base) {
	// 0x293340: movss xmm0, dword ptr [0x0056DFA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DFA4u);
	// 0x293348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293350: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x293358: movss [0x0056E03C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E03Cu, ctx.xmm[0].u32[0]);
	// 0x293360: ret
	return;
}

void sub_293370(X86Context& ctx, uint8_t* base) {
	// 0x293370: movss xmm0, dword ptr [0x0056E040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E040u);
	// 0x293378: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293380: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x293388: movss [0x0056DF98], xmm0
	X86_MEM_WRITE_u32(base, 0x56DF98u, ctx.xmm[0].u32[0]);
	// 0x293390: ret
	return;
}

void sub_2933A0(X86Context& ctx, uint8_t* base) {
	// 0x2933A0: movss xmm0, dword ptr [0x0056DFA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DFA4u);
	// 0x2933A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2933B0: movss [0x0056DF9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56DF9Cu, ctx.xmm[0].u32[0]);
	// 0x2933B8: ret
	return;
}

void sub_2933C0(X86Context& ctx, uint8_t* base) {
	// 0x2933C0: movss xmm0, dword ptr [0x0056E040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E040u);
	// 0x2933C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2933D0: movss [0x0056E048], xmm0
	X86_MEM_WRITE_u32(base, 0x56E048u, ctx.xmm[0].u32[0]);
	// 0x2933D8: ret
	return;
}

void sub_2933E0(X86Context& ctx, uint8_t* base) {
	// 0x2933E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2933E8: movss [0x0056DDF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDF4u, ctx.xmm[0].u32[0]);
	// 0x2933F0: ret
	return;
}

void sub_293400(X86Context& ctx, uint8_t* base) {
	// 0x293400: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x293408: movss [0x0056DFB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFB0u, ctx.xmm[0].u32[0]);
	// 0x293410: ret
	return;
}

void sub_293420(X86Context& ctx, uint8_t* base) {
	// 0x293420: movss xmm0, dword ptr [0x0056DDF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDF4u);
	// 0x293428: movss [0x0056E05C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E05Cu, ctx.xmm[0].u32[0]);
	// 0x293430: ret
	return;
}

void sub_293440(X86Context& ctx, uint8_t* base) {
	// 0x293440: movss xmm0, dword ptr [0x0056E040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E040u);
	// 0x293448: subss xmm0, [0x0056DDF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56DDF4u);
	// 0x293450: movss [0x0056E020], xmm0
	X86_MEM_WRITE_u32(base, 0x56E020u, ctx.xmm[0].u32[0]);
	// 0x293458: ret
	return;
}

void sub_293460(X86Context& ctx, uint8_t* base) {
	// 0x293460: movss xmm0, dword ptr [0x0056E020]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E020u);
	// 0x293468: subss xmm0, [0x0056DFB0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56DFB0u);
	// 0x293470: movss [0x0056E018], xmm0
	X86_MEM_WRITE_u32(base, 0x56E018u, ctx.xmm[0].u32[0]);
	// 0x293478: ret
	return;
}

void sub_293480(X86Context& ctx, uint8_t* base) {
	// 0x293480: movss xmm0, dword ptr [0x0056E048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E048u);
	// 0x293488: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x293490: movss [0x0056E004], xmm0
	X86_MEM_WRITE_u32(base, 0x56E004u, ctx.xmm[0].u32[0]);
	// 0x293498: ret
	return;
}

void sub_2934A0(X86Context& ctx, uint8_t* base) {
	// 0x2934A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2934A8: movss [0x0056DFAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFACu, ctx.xmm[0].u32[0]);
	// 0x2934B0: ret
	return;
}

void sub_2934C0(X86Context& ctx, uint8_t* base) {
	// 0x2934C0: movss xmm0, dword ptr [0x0056E004]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E004u);
	// 0x2934C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2934D0: movss [0x0056E038], xmm0
	X86_MEM_WRITE_u32(base, 0x56E038u, ctx.xmm[0].u32[0]);
	// 0x2934D8: ret
	return;
}

void sub_2934E0(X86Context& ctx, uint8_t* base) {
	// 0x2934E0: movss xmm0, dword ptr [0x003B1A04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A04u);
	// 0x2934E8: movss [0x0056E008], xmm0
	X86_MEM_WRITE_u32(base, 0x56E008u, ctx.xmm[0].u32[0]);
	// 0x2934F0: ret
	return;
}

void sub_293500(X86Context& ctx, uint8_t* base) {
	// 0x293500: movss xmm0, dword ptr [0x00397898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397898u);
	// 0x293508: movss [0x0056DFA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56DFA0u, ctx.xmm[0].u32[0]);
	// 0x293510: ret
	return;
}

void sub_293520(X86Context& ctx, uint8_t* base) {
	// 0x293520: movss xmm0, dword ptr [0x0056DDEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56DDECu);
	// 0x293528: subss xmm0, [0x0056E008]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E008u);
	// 0x293530: movss [0x0056DDE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56DDE4u, ctx.xmm[0].u32[0]);
	// 0x293538: ret
	return;
}

void sub_293540(X86Context& ctx, uint8_t* base) {
	// 0x293540: movss xmm0, dword ptr [0x003B226C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B226Cu);
	// 0x293548: movss [0x0056E000], xmm0
	X86_MEM_WRITE_u32(base, 0x56E000u, ctx.xmm[0].u32[0]);
	// 0x293550: ret
	return;
}

void sub_293560(X86Context& ctx, uint8_t* base) {
	// 0x293560: movss xmm0, dword ptr [0x003B2284]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2284u);
	// 0x293568: movss [0x0056DF94], xmm0
	X86_MEM_WRITE_u32(base, 0x56DF94u, ctx.xmm[0].u32[0]);
	// 0x293570: ret
	return;
}

void sub_293580(X86Context& ctx, uint8_t* base) {
	// 0x293580: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x293588: movss [0x0056E0BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0BCu, ctx.xmm[0].u32[0]);
	// 0x293590: ret
	return;
}

void sub_2935A0(X86Context& ctx, uint8_t* base) {
	// 0x2935A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2935A8: movss [0x0056E0D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0D8u, ctx.xmm[0].u32[0]);
	// 0x2935B0: ret
	return;
}

void sub_2935C0(X86Context& ctx, uint8_t* base) {
	// 0x2935C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2935C8: movss [0x0056E0B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0B0u, ctx.xmm[0].u32[0]);
	// 0x2935D0: ret
	return;
}

void sub_2935E0(X86Context& ctx, uint8_t* base) {
	// 0x2935E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2935E8: movss [0x0056E068], xmm0
	X86_MEM_WRITE_u32(base, 0x56E068u, ctx.xmm[0].u32[0]);
	// 0x2935F0: ret
	return;
}

void sub_293600(X86Context& ctx, uint8_t* base) {
	// 0x293600: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x293608: movss [0x0056E0C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0C0u, ctx.xmm[0].u32[0]);
	// 0x293610: ret
	return;
}

void sub_293620(X86Context& ctx, uint8_t* base) {
	// 0x293620: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x293628: movss [0x0056E084], xmm0
	X86_MEM_WRITE_u32(base, 0x56E084u, ctx.xmm[0].u32[0]);
	// 0x293630: ret
	return;
}

void sub_293640(X86Context& ctx, uint8_t* base) {
	// 0x293640: movss xmm0, dword ptr [0x0056E0C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0C0u);
	// 0x293648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293650: movss [0x0056E0F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0F8u, ctx.xmm[0].u32[0]);
	// 0x293658: ret
	return;
}

void sub_293660(X86Context& ctx, uint8_t* base) {
	// 0x293660: movss xmm0, dword ptr [0x0056E084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E084u);
	// 0x293668: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x293670: movss [0x0056E0E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0E0u, ctx.xmm[0].u32[0]);
	// 0x293678: ret
	return;
}

void sub_293680(X86Context& ctx, uint8_t* base) {
	// 0x293680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x293688: movss [0x0056E110], xmm0
	X86_MEM_WRITE_u32(base, 0x56E110u, ctx.xmm[0].u32[0]);
	// 0x293690: ret
	return;
}

void sub_2936A0(X86Context& ctx, uint8_t* base) {
	// 0x2936A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2936A8: movss [0x0056E0FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0FCu, ctx.xmm[0].u32[0]);
	// 0x2936B0: ret
	return;
}

void sub_2936C0(X86Context& ctx, uint8_t* base) {
	// 0x2936C0: movss xmm0, dword ptr [0x0056E0FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0FCu);
	// 0x2936C8: movss [0x0056E10C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E10Cu, ctx.xmm[0].u32[0]);
	// 0x2936D0: ret
	return;
}

void sub_2936E0(X86Context& ctx, uint8_t* base) {
	// 0x2936E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2936E8: movss [0x0056E070], xmm0
	X86_MEM_WRITE_u32(base, 0x56E070u, ctx.xmm[0].u32[0]);
	// 0x2936F0: ret
	return;
}

void sub_293700(X86Context& ctx, uint8_t* base) {
	// 0x293700: movss xmm0, dword ptr [0x0056E084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E084u);
	// 0x293708: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x293710: movss [0x0056E104], xmm0
	X86_MEM_WRITE_u32(base, 0x56E104u, ctx.xmm[0].u32[0]);
	// 0x293718: ret
	return;
}

void sub_293720(X86Context& ctx, uint8_t* base) {
	// 0x293720: movss xmm0, dword ptr [0x0056E084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E084u);
	// 0x293728: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x293730: movss [0x0056E0AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0ACu, ctx.xmm[0].u32[0]);
	// 0x293738: ret
	return;
}

void sub_293740(X86Context& ctx, uint8_t* base) {
	// 0x293740: movss xmm0, dword ptr [0x0056E084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E084u);
	// 0x293748: subss xmm0, [0x0056E0AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E0ACu);
	// 0x293750: movss [0x0056E08C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E08Cu, ctx.xmm[0].u32[0]);
	// 0x293758: ret
	return;
}

void sub_293760(X86Context& ctx, uint8_t* base) {
	// 0x293760: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x293768: movss [0x0056E0D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0D4u, ctx.xmm[0].u32[0]);
	// 0x293770: ret
	return;
}

void sub_293780(X86Context& ctx, uint8_t* base) {
	// 0x293780: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x293788: movss [0x0056E088], xmm0
	X86_MEM_WRITE_u32(base, 0x56E088u, ctx.xmm[0].u32[0]);
	// 0x293790: ret
	return;
}

void sub_2937A0(X86Context& ctx, uint8_t* base) {
	// 0x2937A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2937A8: movss [0x0056E098], xmm0
	X86_MEM_WRITE_u32(base, 0x56E098u, ctx.xmm[0].u32[0]);
	// 0x2937B0: ret
	return;
}

void sub_2937C0(X86Context& ctx, uint8_t* base) {
	// 0x2937C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2937C8: movss [0x0056E0EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0ECu, ctx.xmm[0].u32[0]);
	// 0x2937D0: ret
	return;
}

void sub_2937E0(X86Context& ctx, uint8_t* base) {
	// 0x2937E0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2937E8: movss [0x0056E0D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0D0u, ctx.xmm[0].u32[0]);
	// 0x2937F0: ret
	return;
}

void sub_293800(X86Context& ctx, uint8_t* base) {
	// 0x293800: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x293808: movss [0x0056E080], xmm0
	X86_MEM_WRITE_u32(base, 0x56E080u, ctx.xmm[0].u32[0]);
	// 0x293810: ret
	return;
}

void sub_293820(X86Context& ctx, uint8_t* base) {
	// 0x293820: movss xmm0, dword ptr [0x0056E098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E098u);
	// 0x293828: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293830: movss [0x0056E074], xmm0
	X86_MEM_WRITE_u32(base, 0x56E074u, ctx.xmm[0].u32[0]);
	// 0x293838: ret
	return;
}

void sub_293840(X86Context& ctx, uint8_t* base) {
	// 0x293840: movss xmm0, dword ptr [0x0056E0EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0ECu);
	// 0x293848: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x293850: movss [0x0056E0B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0B8u, ctx.xmm[0].u32[0]);
	// 0x293858: ret
	return;
}

void sub_293860(X86Context& ctx, uint8_t* base) {
	// 0x293860: movss xmm0, dword ptr [0x0056E074]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E074u);
	// 0x293868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293870: movss [0x0056E0C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0C8u, ctx.xmm[0].u32[0]);
	// 0x293878: ret
	return;
}

void sub_293880(X86Context& ctx, uint8_t* base) {
	// 0x293880: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x293888: movss [0x0056E06C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E06Cu, ctx.xmm[0].u32[0]);
	// 0x293890: ret
	return;
}

void sub_2938A0(X86Context& ctx, uint8_t* base) {
	// 0x2938A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2938A8: movss [0x0056E09C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E09Cu, ctx.xmm[0].u32[0]);
	// 0x2938B0: ret
	return;
}

void sub_2938C0(X86Context& ctx, uint8_t* base) {
	// 0x2938C0: movss xmm0, dword ptr [0x0056E098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E098u);
	// 0x2938C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2938D0: movss [0x0056E0A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0A8u, ctx.xmm[0].u32[0]);
	// 0x2938D8: ret
	return;
}

void sub_2938E0(X86Context& ctx, uint8_t* base) {
	// 0x2938E0: movss xmm0, dword ptr [0x0056E0EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0ECu);
	// 0x2938E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2938F0: movss [0x0056E0F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0F0u, ctx.xmm[0].u32[0]);
	// 0x2938F8: ret
	return;
}

void sub_293900(X86Context& ctx, uint8_t* base) {
	// 0x293900: movss xmm0, dword ptr [0x0056E0A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0A8u);
	// 0x293908: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293910: movss [0x0056E0DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0DCu, ctx.xmm[0].u32[0]);
	// 0x293918: ret
	return;
}

void sub_293920(X86Context& ctx, uint8_t* base) {
	// 0x293920: movss xmm0, dword ptr [0x0056E0F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0F0u);
	// 0x293928: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293930: movss [0x0056E100], xmm0
	X86_MEM_WRITE_u32(base, 0x56E100u, ctx.xmm[0].u32[0]);
	// 0x293938: ret
	return;
}

void sub_293940(X86Context& ctx, uint8_t* base) {
	// 0x293940: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x293948: movss [0x0056E078], xmm0
	X86_MEM_WRITE_u32(base, 0x56E078u, ctx.xmm[0].u32[0]);
	// 0x293950: ret
	return;
}

void sub_293960(X86Context& ctx, uint8_t* base) {
	// 0x293960: movss xmm0, dword ptr [0x0056E098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E098u);
	// 0x293968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x293970: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x293978: movss [0x0056E0E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0E8u, ctx.xmm[0].u32[0]);
	// 0x293980: ret
	return;
}

void sub_293990(X86Context& ctx, uint8_t* base) {
	// 0x293990: movss xmm0, dword ptr [0x0056E0EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0ECu);
	// 0x293998: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2939A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2939A8: movss [0x0056E090], xmm0
	X86_MEM_WRITE_u32(base, 0x56E090u, ctx.xmm[0].u32[0]);
	// 0x2939B0: ret
	return;
}

void sub_2939C0(X86Context& ctx, uint8_t* base) {
	// 0x2939C0: movss xmm0, dword ptr [0x0056E098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E098u);
	// 0x2939C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2939D0: movss [0x0056E094], xmm0
	X86_MEM_WRITE_u32(base, 0x56E094u, ctx.xmm[0].u32[0]);
	// 0x2939D8: ret
	return;
}

void sub_2939E0(X86Context& ctx, uint8_t* base) {
	// 0x2939E0: movss xmm0, dword ptr [0x0056E0EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0ECu);
	// 0x2939E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2939F0: movss [0x0056E0F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0F4u, ctx.xmm[0].u32[0]);
	// 0x2939F8: ret
	return;
}

void sub_293A00(X86Context& ctx, uint8_t* base) {
	// 0x293A00: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x293A08: movss [0x0056E07C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E07Cu, ctx.xmm[0].u32[0]);
	// 0x293A10: ret
	return;
}

void sub_293A20(X86Context& ctx, uint8_t* base) {
	// 0x293A20: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x293A28: movss [0x0056E0A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0A4u, ctx.xmm[0].u32[0]);
	// 0x293A30: ret
	return;
}

void sub_293A40(X86Context& ctx, uint8_t* base) {
	// 0x293A40: movss xmm0, dword ptr [0x0056E07C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E07Cu);
	// 0x293A48: movss [0x0056E108], xmm0
	X86_MEM_WRITE_u32(base, 0x56E108u, ctx.xmm[0].u32[0]);
	// 0x293A50: ret
	return;
}

void sub_293A60(X86Context& ctx, uint8_t* base) {
	// 0x293A60: movss xmm0, dword ptr [0x0056E0EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0ECu);
	// 0x293A68: subss xmm0, [0x0056E07C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E07Cu);
	// 0x293A70: movss [0x0056E0CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0CCu, ctx.xmm[0].u32[0]);
	// 0x293A78: ret
	return;
}

void sub_293A80(X86Context& ctx, uint8_t* base) {
	// 0x293A80: movss xmm0, dword ptr [0x0056E0CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0CCu);
	// 0x293A88: subss xmm0, [0x0056E0A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E0A4u);
	// 0x293A90: movss [0x0056E0C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0C4u, ctx.xmm[0].u32[0]);
	// 0x293A98: ret
	return;
}

void sub_293AA0(X86Context& ctx, uint8_t* base) {
	// 0x293AA0: movss xmm0, dword ptr [0x0056E0F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0F4u);
	// 0x293AA8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x293AB0: movss [0x0056E0B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0B4u, ctx.xmm[0].u32[0]);
	// 0x293AB8: ret
	return;
}

void sub_293AC0(X86Context& ctx, uint8_t* base) {
	// 0x293AC0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x293AC8: movss [0x0056E0A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0A0u, ctx.xmm[0].u32[0]);
	// 0x293AD0: ret
	return;
}

void sub_293AE0(X86Context& ctx, uint8_t* base) {
	// 0x293AE0: movss xmm0, dword ptr [0x0056E0B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E0B4u);
	// 0x293AE8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x293AF0: movss [0x0056E0E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E0E4u, ctx.xmm[0].u32[0]);
	// 0x293AF8: ret
	return;
}

void sub_293B00(X86Context& ctx, uint8_t* base) {
	// 0x293B00: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x293B08: movss [0x0056E168], xmm0
	X86_MEM_WRITE_u32(base, 0x56E168u, ctx.xmm[0].u32[0]);
	// 0x293B10: ret
	return;
}

void sub_293B20(X86Context& ctx, uint8_t* base) {
	// 0x293B20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x293B28: movss [0x0056E184], xmm0
	X86_MEM_WRITE_u32(base, 0x56E184u, ctx.xmm[0].u32[0]);
	// 0x293B30: ret
	return;
}

void sub_293B40(X86Context& ctx, uint8_t* base) {
	// 0x293B40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x293B48: movss [0x0056E15C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E15Cu, ctx.xmm[0].u32[0]);
	// 0x293B50: ret
	return;
}

void sub_293B60(X86Context& ctx, uint8_t* base) {
	// 0x293B60: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x293B68: movss [0x0056E114], xmm0
	X86_MEM_WRITE_u32(base, 0x56E114u, ctx.xmm[0].u32[0]);
	// 0x293B70: ret
	return;
}

void sub_293B80(X86Context& ctx, uint8_t* base) {
	// 0x293B80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x293B88: movss [0x0056E16C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E16Cu, ctx.xmm[0].u32[0]);
	// 0x293B90: ret
	return;
}

void sub_293BA0(X86Context& ctx, uint8_t* base) {
	// 0x293BA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x293BA8: movss [0x0056E130], xmm0
	X86_MEM_WRITE_u32(base, 0x56E130u, ctx.xmm[0].u32[0]);
	// 0x293BB0: ret
	return;
}

void sub_293BC0(X86Context& ctx, uint8_t* base) {
	// 0x293BC0: movss xmm0, dword ptr [0x0056E16C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E16Cu);
	// 0x293BC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293BD0: movss [0x0056E1A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1A4u, ctx.xmm[0].u32[0]);
	// 0x293BD8: ret
	return;
}

void sub_293BE0(X86Context& ctx, uint8_t* base) {
	// 0x293BE0: movss xmm0, dword ptr [0x0056E130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E130u);
	// 0x293BE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x293BF0: movss [0x0056E18C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E18Cu, ctx.xmm[0].u32[0]);
	// 0x293BF8: ret
	return;
}

void sub_293C00(X86Context& ctx, uint8_t* base) {
	// 0x293C00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x293C08: movss [0x0056E1BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1BCu, ctx.xmm[0].u32[0]);
	// 0x293C10: ret
	return;
}

void sub_293C20(X86Context& ctx, uint8_t* base) {
	// 0x293C20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x293C28: movss [0x0056E1A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1A8u, ctx.xmm[0].u32[0]);
	// 0x293C30: ret
	return;
}

void sub_293C40(X86Context& ctx, uint8_t* base) {
	// 0x293C40: movss xmm0, dword ptr [0x0056E1A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E1A8u);
	// 0x293C48: movss [0x0056E1B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1B8u, ctx.xmm[0].u32[0]);
	// 0x293C50: ret
	return;
}

void sub_293C60(X86Context& ctx, uint8_t* base) {
	// 0x293C60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x293C68: movss [0x0056E11C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E11Cu, ctx.xmm[0].u32[0]);
	// 0x293C70: ret
	return;
}

void sub_293C80(X86Context& ctx, uint8_t* base) {
	// 0x293C80: movss xmm0, dword ptr [0x0056E130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E130u);
	// 0x293C88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x293C90: movss [0x0056E1B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E1B0u, ctx.xmm[0].u32[0]);
	// 0x293C98: ret
	return;
}

void sub_293CA0(X86Context& ctx, uint8_t* base) {
	// 0x293CA0: movss xmm0, dword ptr [0x0056E130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E130u);
	// 0x293CA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x293CB0: movss [0x0056E158], xmm0
	X86_MEM_WRITE_u32(base, 0x56E158u, ctx.xmm[0].u32[0]);
	// 0x293CB8: ret
	return;
}

void sub_293CC0(X86Context& ctx, uint8_t* base) {
	// 0x293CC0: movss xmm0, dword ptr [0x0056E130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E130u);
	// 0x293CC8: subss xmm0, [0x0056E158]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E158u);
	// 0x293CD0: movss [0x0056E138], xmm0
	X86_MEM_WRITE_u32(base, 0x56E138u, ctx.xmm[0].u32[0]);
	// 0x293CD8: ret
	return;
}

void sub_293CE0(X86Context& ctx, uint8_t* base) {
	// 0x293CE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x293CE8: movss [0x0056E180], xmm0
	X86_MEM_WRITE_u32(base, 0x56E180u, ctx.xmm[0].u32[0]);
	// 0x293CF0: ret
	return;
}

void sub_293D00(X86Context& ctx, uint8_t* base) {
	// 0x293D00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x293D08: movss [0x0056E134], xmm0
	X86_MEM_WRITE_u32(base, 0x56E134u, ctx.xmm[0].u32[0]);
	// 0x293D10: ret
	return;
}

void sub_293D20(X86Context& ctx, uint8_t* base) {
	// 0x293D20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x293D28: movss [0x0056E144], xmm0
	X86_MEM_WRITE_u32(base, 0x56E144u, ctx.xmm[0].u32[0]);
	// 0x293D30: ret
	return;
}

void sub_293D40(X86Context& ctx, uint8_t* base) {
	// 0x293D40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x293D48: movss [0x0056E198], xmm0
	X86_MEM_WRITE_u32(base, 0x56E198u, ctx.xmm[0].u32[0]);
	// 0x293D50: ret
	return;
}

void sub_293D60(X86Context& ctx, uint8_t* base) {
	// 0x293D60: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x293D68: movss [0x0056E17C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E17Cu, ctx.xmm[0].u32[0]);
	// 0x293D70: ret
	return;
}

void sub_293D80(X86Context& ctx, uint8_t* base) {
	// 0x293D80: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x293D88: movss [0x0056E12C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E12Cu, ctx.xmm[0].u32[0]);
	// 0x293D90: ret
	return;
}

void sub_293DA0(X86Context& ctx, uint8_t* base) {
	// 0x293DA0: movss xmm0, dword ptr [0x0056E144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E144u);
	// 0x293DA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x293DB0: movss [0x0056E120], xmm0
	X86_MEM_WRITE_u32(base, 0x56E120u, ctx.xmm[0].u32[0]);
	// 0x293DB8: ret
	return;
}

void sub_293DC0(X86Context& ctx, uint8_t* base) {
	// 0x293DC0: movss xmm0, dword ptr [0x0056E198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E198u);
	// 0x293DC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x293DD0: movss [0x0056E164], xmm0
	X86_MEM_WRITE_u32(base, 0x56E164u, ctx.xmm[0].u32[0]);
	// 0x293DD8: ret
	return;
}

