#include "x86_recomp_shared.h"

void sub_295EC0(X86Context& ctx, uint8_t* base) {
	// 0x295EC0: movss xmm0, dword ptr [0x0056E5E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5E0u);
	// 0x295EC8: movss [0x0056E5F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5F0u, ctx.xmm[0].u32[0]);
	// 0x295ED0: ret
	return;
}

void sub_295EE0(X86Context& ctx, uint8_t* base) {
	// 0x295EE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x295EE8: movss [0x0056E550], xmm0
	X86_MEM_WRITE_u32(base, 0x56E550u, ctx.xmm[0].u32[0]);
	// 0x295EF0: ret
	return;
}

void sub_295F00(X86Context& ctx, uint8_t* base) {
	// 0x295F00: movss xmm0, dword ptr [0x0056E564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E564u);
	// 0x295F08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x295F10: movss [0x0056E5E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5E8u, ctx.xmm[0].u32[0]);
	// 0x295F18: ret
	return;
}

void sub_295F20(X86Context& ctx, uint8_t* base) {
	// 0x295F20: movss xmm0, dword ptr [0x0056E564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E564u);
	// 0x295F28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x295F30: movss [0x0056E590], xmm0
	X86_MEM_WRITE_u32(base, 0x56E590u, ctx.xmm[0].u32[0]);
	// 0x295F38: ret
	return;
}

void sub_295F40(X86Context& ctx, uint8_t* base) {
	// 0x295F40: movss xmm0, dword ptr [0x0056E564]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E564u);
	// 0x295F48: subss xmm0, [0x0056E590]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E590u);
	// 0x295F50: movss [0x0056E56C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E56Cu, ctx.xmm[0].u32[0]);
	// 0x295F58: ret
	return;
}

void sub_295F60(X86Context& ctx, uint8_t* base) {
	// 0x295F60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x295F68: movss [0x0056E5B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5B8u, ctx.xmm[0].u32[0]);
	// 0x295F70: ret
	return;
}

void sub_295F80(X86Context& ctx, uint8_t* base) {
	// 0x295F80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x295F88: movss [0x0056E568], xmm0
	X86_MEM_WRITE_u32(base, 0x56E568u, ctx.xmm[0].u32[0]);
	// 0x295F90: ret
	return;
}

void sub_295FA0(X86Context& ctx, uint8_t* base) {
	// 0x295FA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x295FA8: movss [0x0056E57C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E57Cu, ctx.xmm[0].u32[0]);
	// 0x295FB0: ret
	return;
}

void sub_295FC0(X86Context& ctx, uint8_t* base) {
	// 0x295FC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x295FC8: movss [0x0056E5D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5D0u, ctx.xmm[0].u32[0]);
	// 0x295FD0: ret
	return;
}

void sub_295FE0(X86Context& ctx, uint8_t* base) {
	// 0x295FE0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x295FE8: movss [0x0056E5B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5B4u, ctx.xmm[0].u32[0]);
	// 0x295FF0: ret
	return;
}

void sub_296000(X86Context& ctx, uint8_t* base) {
	// 0x296000: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x296008: movss [0x0056E560], xmm0
	X86_MEM_WRITE_u32(base, 0x56E560u, ctx.xmm[0].u32[0]);
	// 0x296010: ret
	return;
}

void sub_296020(X86Context& ctx, uint8_t* base) {
	// 0x296020: movss xmm0, dword ptr [0x0056E57C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E57Cu);
	// 0x296028: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296030: movss [0x0056E554], xmm0
	X86_MEM_WRITE_u32(base, 0x56E554u, ctx.xmm[0].u32[0]);
	// 0x296038: ret
	return;
}

void sub_296040(X86Context& ctx, uint8_t* base) {
	// 0x296040: movss xmm0, dword ptr [0x0056E5D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D0u);
	// 0x296048: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x296050: movss [0x0056E59C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E59Cu, ctx.xmm[0].u32[0]);
	// 0x296058: ret
	return;
}

void sub_296060(X86Context& ctx, uint8_t* base) {
	// 0x296060: movss xmm0, dword ptr [0x0056E554]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E554u);
	// 0x296068: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296070: movss [0x0056E5AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5ACu, ctx.xmm[0].u32[0]);
	// 0x296078: ret
	return;
}

void sub_296080(X86Context& ctx, uint8_t* base) {
	// 0x296080: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x296088: movss [0x0056E54C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E54Cu, ctx.xmm[0].u32[0]);
	// 0x296090: ret
	return;
}

void sub_2960A0(X86Context& ctx, uint8_t* base) {
	// 0x2960A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2960A8: movss [0x0056E580], xmm0
	X86_MEM_WRITE_u32(base, 0x56E580u, ctx.xmm[0].u32[0]);
	// 0x2960B0: ret
	return;
}

void sub_2960C0(X86Context& ctx, uint8_t* base) {
	// 0x2960C0: movss xmm0, dword ptr [0x0056E57C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E57Cu);
	// 0x2960C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2960D0: movss [0x0056E58C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E58Cu, ctx.xmm[0].u32[0]);
	// 0x2960D8: ret
	return;
}

void sub_2960E0(X86Context& ctx, uint8_t* base) {
	// 0x2960E0: movss xmm0, dword ptr [0x0056E5D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D0u);
	// 0x2960E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2960F0: movss [0x0056E5D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5D4u, ctx.xmm[0].u32[0]);
	// 0x2960F8: ret
	return;
}

void sub_296100(X86Context& ctx, uint8_t* base) {
	// 0x296100: movss xmm0, dword ptr [0x0056E58C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E58Cu);
	// 0x296108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296110: movss [0x0056E5C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5C0u, ctx.xmm[0].u32[0]);
	// 0x296118: ret
	return;
}

void sub_296120(X86Context& ctx, uint8_t* base) {
	// 0x296120: movss xmm0, dword ptr [0x0056E5D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D4u);
	// 0x296128: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296130: movss [0x0056E5E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5E4u, ctx.xmm[0].u32[0]);
	// 0x296138: ret
	return;
}

void sub_296140(X86Context& ctx, uint8_t* base) {
	// 0x296140: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x296148: movss [0x0056E558], xmm0
	X86_MEM_WRITE_u32(base, 0x56E558u, ctx.xmm[0].u32[0]);
	// 0x296150: ret
	return;
}

void sub_296160(X86Context& ctx, uint8_t* base) {
	// 0x296160: movss xmm0, dword ptr [0x0056E57C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E57Cu);
	// 0x296168: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296170: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x296178: movss [0x0056E5CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5CCu, ctx.xmm[0].u32[0]);
	// 0x296180: ret
	return;
}

void sub_296190(X86Context& ctx, uint8_t* base) {
	// 0x296190: movss xmm0, dword ptr [0x0056E5D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D0u);
	// 0x296198: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2961A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2961A8: movss [0x0056E570], xmm0
	X86_MEM_WRITE_u32(base, 0x56E570u, ctx.xmm[0].u32[0]);
	// 0x2961B0: ret
	return;
}

void sub_2961C0(X86Context& ctx, uint8_t* base) {
	// 0x2961C0: movss xmm0, dword ptr [0x0056E57C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E57Cu);
	// 0x2961C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2961D0: movss [0x0056E578], xmm0
	X86_MEM_WRITE_u32(base, 0x56E578u, ctx.xmm[0].u32[0]);
	// 0x2961D8: ret
	return;
}

void sub_2961E0(X86Context& ctx, uint8_t* base) {
	// 0x2961E0: movss xmm0, dword ptr [0x0056E5D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D0u);
	// 0x2961E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2961F0: movss [0x0056E5D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5D8u, ctx.xmm[0].u32[0]);
	// 0x2961F8: ret
	return;
}

void sub_296200(X86Context& ctx, uint8_t* base) {
	// 0x296200: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x296208: movss [0x0056E55C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E55Cu, ctx.xmm[0].u32[0]);
	// 0x296210: ret
	return;
}

void sub_296220(X86Context& ctx, uint8_t* base) {
	// 0x296220: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x296228: movss [0x0056E588], xmm0
	X86_MEM_WRITE_u32(base, 0x56E588u, ctx.xmm[0].u32[0]);
	// 0x296230: ret
	return;
}

void sub_296240(X86Context& ctx, uint8_t* base) {
	// 0x296240: movss xmm0, dword ptr [0x0056E55C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E55Cu);
	// 0x296248: movss [0x0056E5EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5ECu, ctx.xmm[0].u32[0]);
	// 0x296250: ret
	return;
}

void sub_296260(X86Context& ctx, uint8_t* base) {
	// 0x296260: movss xmm0, dword ptr [0x0056E5D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D0u);
	// 0x296268: subss xmm0, [0x0056E55C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E55Cu);
	// 0x296270: movss [0x0056E5B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5B0u, ctx.xmm[0].u32[0]);
	// 0x296278: ret
	return;
}

void sub_296280(X86Context& ctx, uint8_t* base) {
	// 0x296280: movss xmm0, dword ptr [0x0056E5B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5B0u);
	// 0x296288: subss xmm0, [0x0056E588]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E588u);
	// 0x296290: movss [0x0056E5A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5A8u, ctx.xmm[0].u32[0]);
	// 0x296298: ret
	return;
}

void sub_2962A0(X86Context& ctx, uint8_t* base) {
	// 0x2962A0: movss xmm0, dword ptr [0x0056E5D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E5D8u);
	// 0x2962A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2962B0: movss [0x0056E598], xmm0
	X86_MEM_WRITE_u32(base, 0x56E598u, ctx.xmm[0].u32[0]);
	// 0x2962B8: ret
	return;
}

void sub_2962C0(X86Context& ctx, uint8_t* base) {
	// 0x2962C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2962C8: movss [0x0056E584], xmm0
	X86_MEM_WRITE_u32(base, 0x56E584u, ctx.xmm[0].u32[0]);
	// 0x2962D0: ret
	return;
}

void sub_2962E0(X86Context& ctx, uint8_t* base) {
	// 0x2962E0: movss xmm0, dword ptr [0x0056E598]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E598u);
	// 0x2962E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2962F0: movss [0x0056E5C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5C8u, ctx.xmm[0].u32[0]);
	// 0x2962F8: ret
	return;
}

void sub_296300(X86Context& ctx, uint8_t* base) {
	// 0x296300: movss xmm0, dword ptr [0x003B1FAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1FACu);
	// 0x296308: movss [0x0056E5F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5F4u, ctx.xmm[0].u32[0]);
	// 0x296310: ret
	return;
}

void sub_296320(X86Context& ctx, uint8_t* base) {
	// 0x296320: movss xmm0, dword ptr [0x0056E57C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E57Cu);
	// 0x296328: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x296330: movss [0x00404EA0], xmm0
	X86_MEM_WRITE_u32(base, 0x404EA0u, ctx.xmm[0].u32[0]);
	// 0x296338: ret
	return;
}

void sub_296340(X86Context& ctx, uint8_t* base) {
	// 0x296340: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x296348: movss [0x0056E574], xmm0
	X86_MEM_WRITE_u32(base, 0x56E574u, ctx.xmm[0].u32[0]);
	// 0x296350: ret
	return;
}

void sub_296360(X86Context& ctx, uint8_t* base) {
	// 0x296360: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x296368: movss [0x0056E658], xmm0
	X86_MEM_WRITE_u32(base, 0x56E658u, ctx.xmm[0].u32[0]);
	// 0x296370: ret
	return;
}

void sub_296380(X86Context& ctx, uint8_t* base) {
	// 0x296380: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x296388: movss [0x0056E674], xmm0
	X86_MEM_WRITE_u32(base, 0x56E674u, ctx.xmm[0].u32[0]);
	// 0x296390: ret
	return;
}

void sub_2963A0(X86Context& ctx, uint8_t* base) {
	// 0x2963A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2963A8: movss [0x0056E648], xmm0
	X86_MEM_WRITE_u32(base, 0x56E648u, ctx.xmm[0].u32[0]);
	// 0x2963B0: ret
	return;
}

void sub_2963C0(X86Context& ctx, uint8_t* base) {
	// 0x2963C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2963C8: movss [0x0056E5FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E5FCu, ctx.xmm[0].u32[0]);
	// 0x2963D0: ret
	return;
}

void sub_2963E0(X86Context& ctx, uint8_t* base) {
	// 0x2963E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2963E8: movss [0x0056E65C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E65Cu, ctx.xmm[0].u32[0]);
	// 0x2963F0: ret
	return;
}

void sub_296400(X86Context& ctx, uint8_t* base) {
	// 0x296400: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x296408: movss [0x0056E618], xmm0
	X86_MEM_WRITE_u32(base, 0x56E618u, ctx.xmm[0].u32[0]);
	// 0x296410: ret
	return;
}

void sub_296420(X86Context& ctx, uint8_t* base) {
	// 0x296420: movss xmm0, dword ptr [0x0056E65C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E65Cu);
	// 0x296428: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296430: movss [0x0056E694], xmm0
	X86_MEM_WRITE_u32(base, 0x56E694u, ctx.xmm[0].u32[0]);
	// 0x296438: ret
	return;
}

void sub_296440(X86Context& ctx, uint8_t* base) {
	// 0x296440: movss xmm0, dword ptr [0x0056E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E618u);
	// 0x296448: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x296450: movss [0x0056E67C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E67Cu, ctx.xmm[0].u32[0]);
	// 0x296458: ret
	return;
}

void sub_296460(X86Context& ctx, uint8_t* base) {
	// 0x296460: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x296468: movss [0x0056E6AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6ACu, ctx.xmm[0].u32[0]);
	// 0x296470: ret
	return;
}

void sub_296480(X86Context& ctx, uint8_t* base) {
	// 0x296480: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x296488: movss [0x0056E698], xmm0
	X86_MEM_WRITE_u32(base, 0x56E698u, ctx.xmm[0].u32[0]);
	// 0x296490: ret
	return;
}

void sub_2964A0(X86Context& ctx, uint8_t* base) {
	// 0x2964A0: movss xmm0, dword ptr [0x0056E698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E698u);
	// 0x2964A8: movss [0x0056E6A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6A8u, ctx.xmm[0].u32[0]);
	// 0x2964B0: ret
	return;
}

void sub_2964C0(X86Context& ctx, uint8_t* base) {
	// 0x2964C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2964C8: movss [0x0056E604], xmm0
	X86_MEM_WRITE_u32(base, 0x56E604u, ctx.xmm[0].u32[0]);
	// 0x2964D0: ret
	return;
}

void sub_2964E0(X86Context& ctx, uint8_t* base) {
	// 0x2964E0: movss xmm0, dword ptr [0x0056E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E618u);
	// 0x2964E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2964F0: movss [0x0056E6A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6A0u, ctx.xmm[0].u32[0]);
	// 0x2964F8: ret
	return;
}

void sub_296500(X86Context& ctx, uint8_t* base) {
	// 0x296500: movss xmm0, dword ptr [0x0056E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E618u);
	// 0x296508: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x296510: movss [0x0056E644], xmm0
	X86_MEM_WRITE_u32(base, 0x56E644u, ctx.xmm[0].u32[0]);
	// 0x296518: ret
	return;
}

void sub_296520(X86Context& ctx, uint8_t* base) {
	// 0x296520: movss xmm0, dword ptr [0x0056E618]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E618u);
	// 0x296528: subss xmm0, [0x0056E644]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E644u);
	// 0x296530: movss [0x0056E620], xmm0
	X86_MEM_WRITE_u32(base, 0x56E620u, ctx.xmm[0].u32[0]);
	// 0x296538: ret
	return;
}

void sub_296540(X86Context& ctx, uint8_t* base) {
	// 0x296540: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x296548: movss [0x0056E670], xmm0
	X86_MEM_WRITE_u32(base, 0x56E670u, ctx.xmm[0].u32[0]);
	// 0x296550: ret
	return;
}

void sub_296560(X86Context& ctx, uint8_t* base) {
	// 0x296560: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x296568: movss [0x0056E61C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E61Cu, ctx.xmm[0].u32[0]);
	// 0x296570: ret
	return;
}

void sub_296580(X86Context& ctx, uint8_t* base) {
	// 0x296580: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x296588: movss [0x0056E630], xmm0
	X86_MEM_WRITE_u32(base, 0x56E630u, ctx.xmm[0].u32[0]);
	// 0x296590: ret
	return;
}

void sub_2965A0(X86Context& ctx, uint8_t* base) {
	// 0x2965A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2965A8: movss [0x0056E688], xmm0
	X86_MEM_WRITE_u32(base, 0x56E688u, ctx.xmm[0].u32[0]);
	// 0x2965B0: ret
	return;
}

void sub_2965C0(X86Context& ctx, uint8_t* base) {
	// 0x2965C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2965C8: movss [0x0056E66C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E66Cu, ctx.xmm[0].u32[0]);
	// 0x2965D0: ret
	return;
}

void sub_2965E0(X86Context& ctx, uint8_t* base) {
	// 0x2965E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2965E8: movss [0x0056E614], xmm0
	X86_MEM_WRITE_u32(base, 0x56E614u, ctx.xmm[0].u32[0]);
	// 0x2965F0: ret
	return;
}

void sub_296600(X86Context& ctx, uint8_t* base) {
	// 0x296600: movss xmm0, dword ptr [0x0056E630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E630u);
	// 0x296608: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296610: movss [0x0056E608], xmm0
	X86_MEM_WRITE_u32(base, 0x56E608u, ctx.xmm[0].u32[0]);
	// 0x296618: ret
	return;
}

void sub_296620(X86Context& ctx, uint8_t* base) {
	// 0x296620: movss xmm0, dword ptr [0x0056E688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E688u);
	// 0x296628: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x296630: movss [0x0056E650], xmm0
	X86_MEM_WRITE_u32(base, 0x56E650u, ctx.xmm[0].u32[0]);
	// 0x296638: ret
	return;
}

void sub_296640(X86Context& ctx, uint8_t* base) {
	// 0x296640: movss xmm0, dword ptr [0x0056E608]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E608u);
	// 0x296648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296650: movss [0x0056E664], xmm0
	X86_MEM_WRITE_u32(base, 0x56E664u, ctx.xmm[0].u32[0]);
	// 0x296658: ret
	return;
}

void sub_296660(X86Context& ctx, uint8_t* base) {
	// 0x296660: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x296668: movss [0x0056E600], xmm0
	X86_MEM_WRITE_u32(base, 0x56E600u, ctx.xmm[0].u32[0]);
	// 0x296670: ret
	return;
}

void sub_296680(X86Context& ctx, uint8_t* base) {
	// 0x296680: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x296688: movss [0x0056E634], xmm0
	X86_MEM_WRITE_u32(base, 0x56E634u, ctx.xmm[0].u32[0]);
	// 0x296690: ret
	return;
}

void sub_2966A0(X86Context& ctx, uint8_t* base) {
	// 0x2966A0: movss xmm0, dword ptr [0x0056E630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E630u);
	// 0x2966A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2966B0: movss [0x0056E640], xmm0
	X86_MEM_WRITE_u32(base, 0x56E640u, ctx.xmm[0].u32[0]);
	// 0x2966B8: ret
	return;
}

void sub_2966C0(X86Context& ctx, uint8_t* base) {
	// 0x2966C0: movss xmm0, dword ptr [0x0056E688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E688u);
	// 0x2966C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2966D0: movss [0x0056E68C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E68Cu, ctx.xmm[0].u32[0]);
	// 0x2966D8: ret
	return;
}

void sub_2966E0(X86Context& ctx, uint8_t* base) {
	// 0x2966E0: movss xmm0, dword ptr [0x0056E640]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E640u);
	// 0x2966E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2966F0: movss [0x0056E678], xmm0
	X86_MEM_WRITE_u32(base, 0x56E678u, ctx.xmm[0].u32[0]);
	// 0x2966F8: ret
	return;
}

void sub_296700(X86Context& ctx, uint8_t* base) {
	// 0x296700: movss xmm0, dword ptr [0x0056E68C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E68Cu);
	// 0x296708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296710: movss [0x0056E69C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E69Cu, ctx.xmm[0].u32[0]);
	// 0x296718: ret
	return;
}

void sub_296720(X86Context& ctx, uint8_t* base) {
	// 0x296720: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x296728: movss [0x0056E60C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E60Cu, ctx.xmm[0].u32[0]);
	// 0x296730: ret
	return;
}

void sub_296740(X86Context& ctx, uint8_t* base) {
	// 0x296740: movss xmm0, dword ptr [0x0056E630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E630u);
	// 0x296748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296750: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x296758: movss [0x0056E684], xmm0
	X86_MEM_WRITE_u32(base, 0x56E684u, ctx.xmm[0].u32[0]);
	// 0x296760: ret
	return;
}

void sub_296770(X86Context& ctx, uint8_t* base) {
	// 0x296770: movss xmm0, dword ptr [0x0056E688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E688u);
	// 0x296778: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296780: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x296788: movss [0x0056E624], xmm0
	X86_MEM_WRITE_u32(base, 0x56E624u, ctx.xmm[0].u32[0]);
	// 0x296790: ret
	return;
}

void sub_2967A0(X86Context& ctx, uint8_t* base) {
	// 0x2967A0: movss xmm0, dword ptr [0x0056E630]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E630u);
	// 0x2967A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2967B0: movss [0x0056E628], xmm0
	X86_MEM_WRITE_u32(base, 0x56E628u, ctx.xmm[0].u32[0]);
	// 0x2967B8: ret
	return;
}

void sub_2967C0(X86Context& ctx, uint8_t* base) {
	// 0x2967C0: movss xmm0, dword ptr [0x0056E688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E688u);
	// 0x2967C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2967D0: movss [0x0056E690], xmm0
	X86_MEM_WRITE_u32(base, 0x56E690u, ctx.xmm[0].u32[0]);
	// 0x2967D8: ret
	return;
}

void sub_2967E0(X86Context& ctx, uint8_t* base) {
	// 0x2967E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2967E8: movss [0x0056E610], xmm0
	X86_MEM_WRITE_u32(base, 0x56E610u, ctx.xmm[0].u32[0]);
	// 0x2967F0: ret
	return;
}

void sub_296800(X86Context& ctx, uint8_t* base) {
	// 0x296800: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x296808: movss [0x0056E63C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E63Cu, ctx.xmm[0].u32[0]);
	// 0x296810: ret
	return;
}

void sub_296820(X86Context& ctx, uint8_t* base) {
	// 0x296820: movss xmm0, dword ptr [0x0056E610]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E610u);
	// 0x296828: movss [0x0056E6A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6A4u, ctx.xmm[0].u32[0]);
	// 0x296830: ret
	return;
}

void sub_296840(X86Context& ctx, uint8_t* base) {
	// 0x296840: movss xmm0, dword ptr [0x0056E688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E688u);
	// 0x296848: subss xmm0, [0x0056E610]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E610u);
	// 0x296850: movss [0x0056E668], xmm0
	X86_MEM_WRITE_u32(base, 0x56E668u, ctx.xmm[0].u32[0]);
	// 0x296858: ret
	return;
}

void sub_296860(X86Context& ctx, uint8_t* base) {
	// 0x296860: movss xmm0, dword ptr [0x0056E668]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E668u);
	// 0x296868: subss xmm0, [0x0056E63C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E63Cu);
	// 0x296870: movss [0x0056E660], xmm0
	X86_MEM_WRITE_u32(base, 0x56E660u, ctx.xmm[0].u32[0]);
	// 0x296878: ret
	return;
}

void sub_296880(X86Context& ctx, uint8_t* base) {
	// 0x296880: movss xmm0, dword ptr [0x0056E690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E690u);
	// 0x296888: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x296890: movss [0x0056E64C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E64Cu, ctx.xmm[0].u32[0]);
	// 0x296898: ret
	return;
}

void sub_2968A0(X86Context& ctx, uint8_t* base) {
	// 0x2968A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2968A8: movss [0x0056E638], xmm0
	X86_MEM_WRITE_u32(base, 0x56E638u, ctx.xmm[0].u32[0]);
	// 0x2968B0: ret
	return;
}

void sub_2968C0(X86Context& ctx, uint8_t* base) {
	// 0x2968C0: movss xmm0, dword ptr [0x0056E64C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E64Cu);
	// 0x2968C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2968D0: movss [0x0056E680], xmm0
	X86_MEM_WRITE_u32(base, 0x56E680u, ctx.xmm[0].u32[0]);
	// 0x2968D8: ret
	return;
}

void sub_2968E0(X86Context& ctx, uint8_t* base) {
	// 0x2968E0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2968E8: movss [0x0056E654], xmm0
	X86_MEM_WRITE_u32(base, 0x56E654u, ctx.xmm[0].u32[0]);
	// 0x2968F0: ret
	return;
}

void sub_296900(X86Context& ctx, uint8_t* base) {
	// 0x296900: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x296908: movss [0x0056E62C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E62Cu, ctx.xmm[0].u32[0]);
	// 0x296910: ret
	return;
}

void sub_296920(X86Context& ctx, uint8_t* base) {
	// 0x296920: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x296928: movss [0x0056E720], xmm0
	X86_MEM_WRITE_u32(base, 0x56E720u, ctx.xmm[0].u32[0]);
	// 0x296930: ret
	return;
}

void sub_296940(X86Context& ctx, uint8_t* base) {
	// 0x296940: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x296948: movss [0x0056E73C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E73Cu, ctx.xmm[0].u32[0]);
	// 0x296950: ret
	return;
}

void sub_296960(X86Context& ctx, uint8_t* base) {
	// 0x296960: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x296968: movss [0x0056E714], xmm0
	X86_MEM_WRITE_u32(base, 0x56E714u, ctx.xmm[0].u32[0]);
	// 0x296970: ret
	return;
}

void sub_296980(X86Context& ctx, uint8_t* base) {
	// 0x296980: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x296988: movss [0x0056E6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6B0u, ctx.xmm[0].u32[0]);
	// 0x296990: ret
	return;
}

void sub_2969A0(X86Context& ctx, uint8_t* base) {
	// 0x2969A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2969A8: movss [0x0056E724], xmm0
	X86_MEM_WRITE_u32(base, 0x56E724u, ctx.xmm[0].u32[0]);
	// 0x2969B0: ret
	return;
}

void sub_2969C0(X86Context& ctx, uint8_t* base) {
	// 0x2969C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2969C8: movss [0x0056E6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6D4u, ctx.xmm[0].u32[0]);
	// 0x2969D0: ret
	return;
}

void sub_2969E0(X86Context& ctx, uint8_t* base) {
	// 0x2969E0: movss xmm0, dword ptr [0x0056E724]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E724u);
	// 0x2969E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2969F0: movss [0x0056E760], xmm0
	X86_MEM_WRITE_u32(base, 0x56E760u, ctx.xmm[0].u32[0]);
	// 0x2969F8: ret
	return;
}

void sub_296A00(X86Context& ctx, uint8_t* base) {
	// 0x296A00: movss xmm0, dword ptr [0x0056E6D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6D4u);
	// 0x296A08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x296A10: movss [0x0056E744], xmm0
	X86_MEM_WRITE_u32(base, 0x56E744u, ctx.xmm[0].u32[0]);
	// 0x296A18: ret
	return;
}

void sub_296A20(X86Context& ctx, uint8_t* base) {
	// 0x296A20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x296A28: movss [0x0056E77C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E77Cu, ctx.xmm[0].u32[0]);
	// 0x296A30: ret
	return;
}

void sub_296A40(X86Context& ctx, uint8_t* base) {
	// 0x296A40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x296A48: movss [0x0056E764], xmm0
	X86_MEM_WRITE_u32(base, 0x56E764u, ctx.xmm[0].u32[0]);
	// 0x296A50: ret
	return;
}

void sub_296A60(X86Context& ctx, uint8_t* base) {
	// 0x296A60: movss xmm0, dword ptr [0x0056E764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E764u);
	// 0x296A68: movss [0x0056E778], xmm0
	X86_MEM_WRITE_u32(base, 0x56E778u, ctx.xmm[0].u32[0]);
	// 0x296A70: ret
	return;
}

void sub_296A80(X86Context& ctx, uint8_t* base) {
	// 0x296A80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x296A88: movss [0x0056E6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6C0u, ctx.xmm[0].u32[0]);
	// 0x296A90: ret
	return;
}

void sub_296AA0(X86Context& ctx, uint8_t* base) {
	// 0x296AA0: movss xmm0, dword ptr [0x0056E6D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6D4u);
	// 0x296AA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x296AB0: movss [0x0056E76C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E76Cu, ctx.xmm[0].u32[0]);
	// 0x296AB8: ret
	return;
}

void sub_296AC0(X86Context& ctx, uint8_t* base) {
	// 0x296AC0: movss xmm0, dword ptr [0x0056E6D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6D4u);
	// 0x296AC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x296AD0: movss [0x0056E70C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E70Cu, ctx.xmm[0].u32[0]);
	// 0x296AD8: ret
	return;
}

void sub_296AE0(X86Context& ctx, uint8_t* base) {
	// 0x296AE0: movss xmm0, dword ptr [0x0056E6D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6D4u);
	// 0x296AE8: subss xmm0, [0x0056E70C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E70Cu);
	// 0x296AF0: movss [0x0056E6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6DCu, ctx.xmm[0].u32[0]);
	// 0x296AF8: ret
	return;
}

void sub_296B00(X86Context& ctx, uint8_t* base) {
	// 0x296B00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x296B08: movss [0x0056E738], xmm0
	X86_MEM_WRITE_u32(base, 0x56E738u, ctx.xmm[0].u32[0]);
	// 0x296B10: ret
	return;
}

void sub_296B20(X86Context& ctx, uint8_t* base) {
	// 0x296B20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x296B28: movss [0x0056E6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6D8u, ctx.xmm[0].u32[0]);
	// 0x296B30: ret
	return;
}

void sub_296B40(X86Context& ctx, uint8_t* base) {
	// 0x296B40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x296B48: movss [0x0056E6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6F4u, ctx.xmm[0].u32[0]);
	// 0x296B50: ret
	return;
}

void sub_296B60(X86Context& ctx, uint8_t* base) {
	// 0x296B60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x296B68: movss [0x0056E754], xmm0
	X86_MEM_WRITE_u32(base, 0x56E754u, ctx.xmm[0].u32[0]);
	// 0x296B70: ret
	return;
}

void sub_296B80(X86Context& ctx, uint8_t* base) {
	// 0x296B80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x296B88: movss [0x0056E734], xmm0
	X86_MEM_WRITE_u32(base, 0x56E734u, ctx.xmm[0].u32[0]);
	// 0x296B90: ret
	return;
}

void sub_296BA0(X86Context& ctx, uint8_t* base) {
	// 0x296BA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x296BA8: movss [0x0056E6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6D0u, ctx.xmm[0].u32[0]);
	// 0x296BB0: ret
	return;
}

void sub_296BC0(X86Context& ctx, uint8_t* base) {
	// 0x296BC0: movss xmm0, dword ptr [0x0056E6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6F4u);
	// 0x296BC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296BD0: movss [0x0056E6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6C4u, ctx.xmm[0].u32[0]);
	// 0x296BD8: ret
	return;
}

void sub_296BE0(X86Context& ctx, uint8_t* base) {
	// 0x296BE0: movss xmm0, dword ptr [0x0056E754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E754u);
	// 0x296BE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x296BF0: movss [0x0056E71C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E71Cu, ctx.xmm[0].u32[0]);
	// 0x296BF8: ret
	return;
}

void sub_296C00(X86Context& ctx, uint8_t* base) {
	// 0x296C00: movss xmm0, dword ptr [0x0056E6C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6C4u);
	// 0x296C08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x296C10: movss [0x0056E72C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E72Cu, ctx.xmm[0].u32[0]);
	// 0x296C18: ret
	return;
}

void sub_296C20(X86Context& ctx, uint8_t* base) {
	// 0x296C20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x296C28: movss [0x0056E6B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6B4u, ctx.xmm[0].u32[0]);
	// 0x296C30: ret
	return;
}

void sub_296C40(X86Context& ctx, uint8_t* base) {
	// 0x296C40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x296C48: movss [0x0056E6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6F8u, ctx.xmm[0].u32[0]);
	// 0x296C50: ret
	return;
}

void sub_296C60(X86Context& ctx, uint8_t* base) {
	// 0x296C60: movss xmm0, dword ptr [0x0056E6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6F4u);
	// 0x296C68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x296C70: movss [0x0056E708], xmm0
	X86_MEM_WRITE_u32(base, 0x56E708u, ctx.xmm[0].u32[0]);
	// 0x296C78: ret
	return;
}

void sub_296C80(X86Context& ctx, uint8_t* base) {
	// 0x296C80: movss xmm0, dword ptr [0x0056E754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E754u);
	// 0x296C88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x296C90: movss [0x0056E758], xmm0
	X86_MEM_WRITE_u32(base, 0x56E758u, ctx.xmm[0].u32[0]);
	// 0x296C98: ret
	return;
}

void sub_296CA0(X86Context& ctx, uint8_t* base) {
	// 0x296CA0: movss xmm0, dword ptr [0x0056E708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E708u);
	// 0x296CA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296CB0: movss [0x0056E740], xmm0
	X86_MEM_WRITE_u32(base, 0x56E740u, ctx.xmm[0].u32[0]);
	// 0x296CB8: ret
	return;
}

void sub_296CC0(X86Context& ctx, uint8_t* base) {
	// 0x296CC0: movss xmm0, dword ptr [0x0056E758]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E758u);
	// 0x296CC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296CD0: movss [0x0056E768], xmm0
	X86_MEM_WRITE_u32(base, 0x56E768u, ctx.xmm[0].u32[0]);
	// 0x296CD8: ret
	return;
}

void sub_296CE0(X86Context& ctx, uint8_t* base) {
	// 0x296CE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x296CE8: movss [0x0056E6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6C8u, ctx.xmm[0].u32[0]);
	// 0x296CF0: ret
	return;
}

void sub_296D00(X86Context& ctx, uint8_t* base) {
	// 0x296D00: movss xmm0, dword ptr [0x0056E6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6F4u);
	// 0x296D08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296D10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x296D18: movss [0x0056E74C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E74Cu, ctx.xmm[0].u32[0]);
	// 0x296D20: ret
	return;
}

void sub_296D30(X86Context& ctx, uint8_t* base) {
	// 0x296D30: movss xmm0, dword ptr [0x0056E754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E754u);
	// 0x296D38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296D40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x296D48: movss [0x0056E6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6E4u, ctx.xmm[0].u32[0]);
	// 0x296D50: ret
	return;
}

void sub_296D60(X86Context& ctx, uint8_t* base) {
	// 0x296D60: movss xmm0, dword ptr [0x0056E6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6F4u);
	// 0x296D68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296D70: movss [0x0056E6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6E8u, ctx.xmm[0].u32[0]);
	// 0x296D78: ret
	return;
}

void sub_296D80(X86Context& ctx, uint8_t* base) {
	// 0x296D80: movss xmm0, dword ptr [0x0056E754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E754u);
	// 0x296D88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x296D90: movss [0x0056E75C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E75Cu, ctx.xmm[0].u32[0]);
	// 0x296D98: ret
	return;
}

void sub_296DA0(X86Context& ctx, uint8_t* base) {
	// 0x296DA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x296DA8: movss [0x0056E6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6CCu, ctx.xmm[0].u32[0]);
	// 0x296DB0: ret
	return;
}

void sub_296DC0(X86Context& ctx, uint8_t* base) {
	// 0x296DC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x296DC8: movss [0x0056E704], xmm0
	X86_MEM_WRITE_u32(base, 0x56E704u, ctx.xmm[0].u32[0]);
	// 0x296DD0: ret
	return;
}

void sub_296DE0(X86Context& ctx, uint8_t* base) {
	// 0x296DE0: movss xmm0, dword ptr [0x0056E6CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6CCu);
	// 0x296DE8: movss [0x0056E770], xmm0
	X86_MEM_WRITE_u32(base, 0x56E770u, ctx.xmm[0].u32[0]);
	// 0x296DF0: ret
	return;
}

void sub_296E00(X86Context& ctx, uint8_t* base) {
	// 0x296E00: movss xmm0, dword ptr [0x0056E754]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E754u);
	// 0x296E08: subss xmm0, [0x0056E6CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E6CCu);
	// 0x296E10: movss [0x0056E730], xmm0
	X86_MEM_WRITE_u32(base, 0x56E730u, ctx.xmm[0].u32[0]);
	// 0x296E18: ret
	return;
}

void sub_296E20(X86Context& ctx, uint8_t* base) {
	// 0x296E20: movss xmm0, dword ptr [0x0056E730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E730u);
	// 0x296E28: subss xmm0, [0x0056E704]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E704u);
	// 0x296E30: movss [0x0056E728], xmm0
	X86_MEM_WRITE_u32(base, 0x56E728u, ctx.xmm[0].u32[0]);
	// 0x296E38: ret
	return;
}

void sub_296E40(X86Context& ctx, uint8_t* base) {
	// 0x296E40: movss xmm0, dword ptr [0x0056E75C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E75Cu);
	// 0x296E48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x296E50: movss [0x0056E718], xmm0
	X86_MEM_WRITE_u32(base, 0x56E718u, ctx.xmm[0].u32[0]);
	// 0x296E58: ret
	return;
}

void sub_296E60(X86Context& ctx, uint8_t* base) {
	// 0x296E60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x296E68: movss [0x0056E700], xmm0
	X86_MEM_WRITE_u32(base, 0x56E700u, ctx.xmm[0].u32[0]);
	// 0x296E70: ret
	return;
}

void sub_296E80(X86Context& ctx, uint8_t* base) {
	// 0x296E80: movss xmm0, dword ptr [0x0056E718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E718u);
	// 0x296E88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x296E90: movss [0x0056E748], xmm0
	X86_MEM_WRITE_u32(base, 0x56E748u, ctx.xmm[0].u32[0]);
	// 0x296E98: ret
	return;
}

void sub_296EA0(X86Context& ctx, uint8_t* base) {
	// 0x296EA0: movss xmm0, dword ptr [0x00395D54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395D54u);
	// 0x296EA8: movss [0x0056E774], xmm0
	X86_MEM_WRITE_u32(base, 0x56E774u, ctx.xmm[0].u32[0]);
	// 0x296EB0: ret
	return;
}

void sub_296EC0(X86Context& ctx, uint8_t* base) {
	// 0x296EC0: movss xmm0, dword ptr [0x003B2288]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2288u);
	// 0x296EC8: movss [0x0056E6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6F0u, ctx.xmm[0].u32[0]);
	// 0x296ED0: ret
	return;
}

void sub_296EE0(X86Context& ctx, uint8_t* base) {
	// 0x296EE0: movss xmm0, dword ptr [0x003B226C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B226Cu);
	// 0x296EE8: movss [0x0056E6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6ECu, ctx.xmm[0].u32[0]);
	// 0x296EF0: ret
	return;
}

void sub_296F00(X86Context& ctx, uint8_t* base) {
	// 0x296F00: movss xmm0, dword ptr [0x0056E6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6F4u);
	// 0x296F08: subss xmm0, [0x0056E6F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E6F0u);
	// 0x296F10: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x296F18: movss [0x0056E6B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6B8u, ctx.xmm[0].u32[0]);
	// 0x296F20: ret
	return;
}

void sub_296F30(X86Context& ctx, uint8_t* base) {
	// 0x296F30: movss xmm0, dword ptr [0x00397898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397898u);
	// 0x296F38: movss [0x0056E750], xmm0
	X86_MEM_WRITE_u32(base, 0x56E750u, ctx.xmm[0].u32[0]);
	// 0x296F40: ret
	return;
}

void sub_296F50(X86Context& ctx, uint8_t* base) {
	// 0x296F50: movss xmm0, dword ptr [0x0056E774]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E774u);
	// 0x296F58: addss xmm0, [0x003B1C1C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1C1Cu);
	// 0x296F60: movss [0x0056E710], xmm0
	X86_MEM_WRITE_u32(base, 0x56E710u, ctx.xmm[0].u32[0]);
	// 0x296F68: ret
	return;
}

void sub_296F70(X86Context& ctx, uint8_t* base) {
	// 0x296F70: movss xmm0, dword ptr [0x003B226C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B226Cu);
	// 0x296F78: movss [0x0056E6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6E0u, ctx.xmm[0].u32[0]);
	// 0x296F80: ret
	return;
}

void sub_296F90(X86Context& ctx, uint8_t* base) {
	// 0x296F90: movss xmm0, dword ptr [0x0056E6F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E6F4u);
	// 0x296F98: subss xmm0, [0x0056E710]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E710u);
	// 0x296FA0: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x296FA8: movss [0x0056E6BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6BCu, ctx.xmm[0].u32[0]);
	// 0x296FB0: ret
	return;
}

void sub_296FC0(X86Context& ctx, uint8_t* base) {
	// 0x296FC0: movss xmm0, dword ptr [0x00397898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x397898u);
	// 0x296FC8: movss [0x0056E6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E6FCu, ctx.xmm[0].u32[0]);
	// 0x296FD0: ret
	return;
}

void sub_296FE0(X86Context& ctx, uint8_t* base) {
	// 0x296FE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x296FE8: movss [0x0056E7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7DCu, ctx.xmm[0].u32[0]);
	// 0x296FF0: ret
	return;
}

void sub_297000(X86Context& ctx, uint8_t* base) {
	// 0x297000: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x297008: movss [0x0056E7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7F8u, ctx.xmm[0].u32[0]);
	// 0x297010: ret
	return;
}

void sub_297020(X86Context& ctx, uint8_t* base) {
	// 0x297020: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x297028: movss [0x0056E7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7D0u, ctx.xmm[0].u32[0]);
	// 0x297030: ret
	return;
}

void sub_297040(X86Context& ctx, uint8_t* base) {
	// 0x297040: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x297048: movss [0x0056E780], xmm0
	X86_MEM_WRITE_u32(base, 0x56E780u, ctx.xmm[0].u32[0]);
	// 0x297050: ret
	return;
}

void sub_297060(X86Context& ctx, uint8_t* base) {
	// 0x297060: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x297068: movss [0x0056E7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7E0u, ctx.xmm[0].u32[0]);
	// 0x297070: ret
	return;
}

void sub_297080(X86Context& ctx, uint8_t* base) {
	// 0x297080: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x297088: movss [0x0056E7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7A4u, ctx.xmm[0].u32[0]);
	// 0x297090: ret
	return;
}

void sub_2970A0(X86Context& ctx, uint8_t* base) {
	// 0x2970A0: movss xmm0, dword ptr [0x0056E7E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7E0u);
	// 0x2970A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2970B0: movss [0x0056E818], xmm0
	X86_MEM_WRITE_u32(base, 0x56E818u, ctx.xmm[0].u32[0]);
	// 0x2970B8: ret
	return;
}

void sub_2970C0(X86Context& ctx, uint8_t* base) {
	// 0x2970C0: movss xmm0, dword ptr [0x0056E7A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7A4u);
	// 0x2970C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2970D0: movss [0x0056E800], xmm0
	X86_MEM_WRITE_u32(base, 0x56E800u, ctx.xmm[0].u32[0]);
	// 0x2970D8: ret
	return;
}

void sub_2970E0(X86Context& ctx, uint8_t* base) {
	// 0x2970E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2970E8: movss [0x0056E830], xmm0
	X86_MEM_WRITE_u32(base, 0x56E830u, ctx.xmm[0].u32[0]);
	// 0x2970F0: ret
	return;
}

void sub_297100(X86Context& ctx, uint8_t* base) {
	// 0x297100: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x297108: movss [0x0056E81C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E81Cu, ctx.xmm[0].u32[0]);
	// 0x297110: ret
	return;
}

void sub_297120(X86Context& ctx, uint8_t* base) {
	// 0x297120: movss xmm0, dword ptr [0x0056E81C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E81Cu);
	// 0x297128: movss [0x0056E82C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E82Cu, ctx.xmm[0].u32[0]);
	// 0x297130: ret
	return;
}

void sub_297140(X86Context& ctx, uint8_t* base) {
	// 0x297140: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x297148: movss [0x0056E790], xmm0
	X86_MEM_WRITE_u32(base, 0x56E790u, ctx.xmm[0].u32[0]);
	// 0x297150: ret
	return;
}

void sub_297160(X86Context& ctx, uint8_t* base) {
	// 0x297160: movss xmm0, dword ptr [0x0056E7A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7A4u);
	// 0x297168: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x297170: movss [0x0056E824], xmm0
	X86_MEM_WRITE_u32(base, 0x56E824u, ctx.xmm[0].u32[0]);
	// 0x297178: ret
	return;
}

void sub_297180(X86Context& ctx, uint8_t* base) {
	// 0x297180: movss xmm0, dword ptr [0x0056E7A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7A4u);
	// 0x297188: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x297190: movss [0x0056E7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7CCu, ctx.xmm[0].u32[0]);
	// 0x297198: ret
	return;
}

void sub_2971A0(X86Context& ctx, uint8_t* base) {
	// 0x2971A0: movss xmm0, dword ptr [0x0056E7A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7A4u);
	// 0x2971A8: subss xmm0, [0x0056E7CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E7CCu);
	// 0x2971B0: movss [0x0056E7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7ACu, ctx.xmm[0].u32[0]);
	// 0x2971B8: ret
	return;
}

void sub_2971C0(X86Context& ctx, uint8_t* base) {
	// 0x2971C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2971C8: movss [0x0056E7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7F4u, ctx.xmm[0].u32[0]);
	// 0x2971D0: ret
	return;
}

void sub_2971E0(X86Context& ctx, uint8_t* base) {
	// 0x2971E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2971E8: movss [0x0056E7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7A8u, ctx.xmm[0].u32[0]);
	// 0x2971F0: ret
	return;
}

void sub_297200(X86Context& ctx, uint8_t* base) {
	// 0x297200: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x297208: movss [0x0056E7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7B8u, ctx.xmm[0].u32[0]);
	// 0x297210: ret
	return;
}

void sub_297220(X86Context& ctx, uint8_t* base) {
	// 0x297220: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x297228: movss [0x0056E80C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E80Cu, ctx.xmm[0].u32[0]);
	// 0x297230: ret
	return;
}

void sub_297240(X86Context& ctx, uint8_t* base) {
	// 0x297240: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x297248: movss [0x0056E7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7F0u, ctx.xmm[0].u32[0]);
	// 0x297250: ret
	return;
}

void sub_297260(X86Context& ctx, uint8_t* base) {
	// 0x297260: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x297268: movss [0x0056E7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7A0u, ctx.xmm[0].u32[0]);
	// 0x297270: ret
	return;
}

void sub_297280(X86Context& ctx, uint8_t* base) {
	// 0x297280: movss xmm0, dword ptr [0x0056E7B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7B8u);
	// 0x297288: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297290: movss [0x0056E794], xmm0
	X86_MEM_WRITE_u32(base, 0x56E794u, ctx.xmm[0].u32[0]);
	// 0x297298: ret
	return;
}

void sub_2972A0(X86Context& ctx, uint8_t* base) {
	// 0x2972A0: movss xmm0, dword ptr [0x0056E80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E80Cu);
	// 0x2972A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2972B0: movss [0x0056E7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7D8u, ctx.xmm[0].u32[0]);
	// 0x2972B8: ret
	return;
}

void sub_2972C0(X86Context& ctx, uint8_t* base) {
	// 0x2972C0: movss xmm0, dword ptr [0x0056E794]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E794u);
	// 0x2972C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2972D0: movss [0x0056E7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7E8u, ctx.xmm[0].u32[0]);
	// 0x2972D8: ret
	return;
}

void sub_2972E0(X86Context& ctx, uint8_t* base) {
	// 0x2972E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2972E8: movss [0x0056E784], xmm0
	X86_MEM_WRITE_u32(base, 0x56E784u, ctx.xmm[0].u32[0]);
	// 0x2972F0: ret
	return;
}

void sub_297300(X86Context& ctx, uint8_t* base) {
	// 0x297300: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x297308: movss [0x0056E7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7BCu, ctx.xmm[0].u32[0]);
	// 0x297310: ret
	return;
}

void sub_297320(X86Context& ctx, uint8_t* base) {
	// 0x297320: movss xmm0, dword ptr [0x0056E7B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7B8u);
	// 0x297328: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x297330: movss [0x0056E7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7C8u, ctx.xmm[0].u32[0]);
	// 0x297338: ret
	return;
}

void sub_297340(X86Context& ctx, uint8_t* base) {
	// 0x297340: movss xmm0, dword ptr [0x0056E80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E80Cu);
	// 0x297348: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x297350: movss [0x0056E810], xmm0
	X86_MEM_WRITE_u32(base, 0x56E810u, ctx.xmm[0].u32[0]);
	// 0x297358: ret
	return;
}

void sub_297360(X86Context& ctx, uint8_t* base) {
	// 0x297360: movss xmm0, dword ptr [0x0056E7C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7C8u);
	// 0x297368: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297370: movss [0x0056E7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7FCu, ctx.xmm[0].u32[0]);
	// 0x297378: ret
	return;
}

void sub_297380(X86Context& ctx, uint8_t* base) {
	// 0x297380: movss xmm0, dword ptr [0x0056E810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E810u);
	// 0x297388: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297390: movss [0x0056E820], xmm0
	X86_MEM_WRITE_u32(base, 0x56E820u, ctx.xmm[0].u32[0]);
	// 0x297398: ret
	return;
}

void sub_2973A0(X86Context& ctx, uint8_t* base) {
	// 0x2973A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2973A8: movss [0x0056E798], xmm0
	X86_MEM_WRITE_u32(base, 0x56E798u, ctx.xmm[0].u32[0]);
	// 0x2973B0: ret
	return;
}

void sub_2973C0(X86Context& ctx, uint8_t* base) {
	// 0x2973C0: movss xmm0, dword ptr [0x0056E7B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7B8u);
	// 0x2973C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2973D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2973D8: movss [0x0056E808], xmm0
	X86_MEM_WRITE_u32(base, 0x56E808u, ctx.xmm[0].u32[0]);
	// 0x2973E0: ret
	return;
}

void sub_2973F0(X86Context& ctx, uint8_t* base) {
	// 0x2973F0: movss xmm0, dword ptr [0x0056E80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E80Cu);
	// 0x2973F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297400: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x297408: movss [0x0056E7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7B0u, ctx.xmm[0].u32[0]);
	// 0x297410: ret
	return;
}

void sub_297420(X86Context& ctx, uint8_t* base) {
	// 0x297420: movss xmm0, dword ptr [0x0056E7B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7B8u);
	// 0x297428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297430: movss [0x0056E7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7B4u, ctx.xmm[0].u32[0]);
	// 0x297438: ret
	return;
}

void sub_297440(X86Context& ctx, uint8_t* base) {
	// 0x297440: movss xmm0, dword ptr [0x0056E80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E80Cu);
	// 0x297448: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297450: movss [0x0056E814], xmm0
	X86_MEM_WRITE_u32(base, 0x56E814u, ctx.xmm[0].u32[0]);
	// 0x297458: ret
	return;
}

void sub_297460(X86Context& ctx, uint8_t* base) {
	// 0x297460: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x297468: movss [0x0056E79C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E79Cu, ctx.xmm[0].u32[0]);
	// 0x297470: ret
	return;
}

void sub_297480(X86Context& ctx, uint8_t* base) {
	// 0x297480: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x297488: movss [0x0056E7C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7C4u, ctx.xmm[0].u32[0]);
	// 0x297490: ret
	return;
}

void sub_2974A0(X86Context& ctx, uint8_t* base) {
	// 0x2974A0: movss xmm0, dword ptr [0x0056E79C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E79Cu);
	// 0x2974A8: movss [0x0056E828], xmm0
	X86_MEM_WRITE_u32(base, 0x56E828u, ctx.xmm[0].u32[0]);
	// 0x2974B0: ret
	return;
}

void sub_2974C0(X86Context& ctx, uint8_t* base) {
	// 0x2974C0: movss xmm0, dword ptr [0x0056E80C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E80Cu);
	// 0x2974C8: subss xmm0, [0x0056E79C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E79Cu);
	// 0x2974D0: movss [0x0056E7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7ECu, ctx.xmm[0].u32[0]);
	// 0x2974D8: ret
	return;
}

void sub_2974E0(X86Context& ctx, uint8_t* base) {
	// 0x2974E0: movss xmm0, dword ptr [0x0056E7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7ECu);
	// 0x2974E8: subss xmm0, [0x0056E7C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E7C4u);
	// 0x2974F0: movss [0x0056E7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7E4u, ctx.xmm[0].u32[0]);
	// 0x2974F8: ret
	return;
}

void sub_297500(X86Context& ctx, uint8_t* base) {
	// 0x297500: movss xmm0, dword ptr [0x0056E814]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E814u);
	// 0x297508: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x297510: movss [0x0056E7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7D4u, ctx.xmm[0].u32[0]);
	// 0x297518: ret
	return;
}

void sub_297520(X86Context& ctx, uint8_t* base) {
	// 0x297520: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x297528: movss [0x0056E7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E7C0u, ctx.xmm[0].u32[0]);
	// 0x297530: ret
	return;
}

void sub_297540(X86Context& ctx, uint8_t* base) {
	// 0x297540: movss xmm0, dword ptr [0x0056E7D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E7D4u);
	// 0x297548: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x297550: movss [0x0056E804], xmm0
	X86_MEM_WRITE_u32(base, 0x56E804u, ctx.xmm[0].u32[0]);
	// 0x297558: ret
	return;
}

void sub_297560(X86Context& ctx, uint8_t* base) {
	// 0x297560: movss xmm0, dword ptr [0x003B228C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B228Cu);
	// 0x297568: movss [0x0056E78C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E78Cu, ctx.xmm[0].u32[0]);
	// 0x297570: ret
	return;
}

void sub_297580(X86Context& ctx, uint8_t* base) {
	// 0x297580: movss xmm0, dword ptr [0x003B1904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1904u);
	// 0x297588: movss [0x0056E788], xmm0
	X86_MEM_WRITE_u32(base, 0x56E788u, ctx.xmm[0].u32[0]);
	// 0x297590: ret
	return;
}

void sub_2975A0(X86Context& ctx, uint8_t* base) {
	// 0x2975A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2975A8: movss [0x0056E890], xmm0
	X86_MEM_WRITE_u32(base, 0x56E890u, ctx.xmm[0].u32[0]);
	// 0x2975B0: ret
	return;
}

void sub_2975C0(X86Context& ctx, uint8_t* base) {
	// 0x2975C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2975C8: movss [0x0056E8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8ACu, ctx.xmm[0].u32[0]);
	// 0x2975D0: ret
	return;
}

void sub_2975E0(X86Context& ctx, uint8_t* base) {
	// 0x2975E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2975E8: movss [0x0056E880], xmm0
	X86_MEM_WRITE_u32(base, 0x56E880u, ctx.xmm[0].u32[0]);
	// 0x2975F0: ret
	return;
}

void sub_297600(X86Context& ctx, uint8_t* base) {
	// 0x297600: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x297608: movss [0x0056E834], xmm0
	X86_MEM_WRITE_u32(base, 0x56E834u, ctx.xmm[0].u32[0]);
	// 0x297610: ret
	return;
}

void sub_297620(X86Context& ctx, uint8_t* base) {
	// 0x297620: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x297628: movss [0x0056E894], xmm0
	X86_MEM_WRITE_u32(base, 0x56E894u, ctx.xmm[0].u32[0]);
	// 0x297630: ret
	return;
}

void sub_297640(X86Context& ctx, uint8_t* base) {
	// 0x297640: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x297648: movss [0x0056E850], xmm0
	X86_MEM_WRITE_u32(base, 0x56E850u, ctx.xmm[0].u32[0]);
	// 0x297650: ret
	return;
}

void sub_297660(X86Context& ctx, uint8_t* base) {
	// 0x297660: movss xmm0, dword ptr [0x0056E894]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E894u);
	// 0x297668: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297670: movss [0x0056E8CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8CCu, ctx.xmm[0].u32[0]);
	// 0x297678: ret
	return;
}

void sub_297680(X86Context& ctx, uint8_t* base) {
	// 0x297680: movss xmm0, dword ptr [0x0056E850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E850u);
	// 0x297688: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x297690: movss [0x0056E8B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8B4u, ctx.xmm[0].u32[0]);
	// 0x297698: ret
	return;
}

void sub_2976A0(X86Context& ctx, uint8_t* base) {
	// 0x2976A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2976A8: movss [0x0056E8E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8E4u, ctx.xmm[0].u32[0]);
	// 0x2976B0: ret
	return;
}

void sub_2976C0(X86Context& ctx, uint8_t* base) {
	// 0x2976C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2976C8: movss [0x0056E8D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8D0u, ctx.xmm[0].u32[0]);
	// 0x2976D0: ret
	return;
}

void sub_2976E0(X86Context& ctx, uint8_t* base) {
	// 0x2976E0: movss xmm0, dword ptr [0x0056E8D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8D0u);
	// 0x2976E8: movss [0x0056E8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8E0u, ctx.xmm[0].u32[0]);
	// 0x2976F0: ret
	return;
}

void sub_297700(X86Context& ctx, uint8_t* base) {
	// 0x297700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x297708: movss [0x0056E83C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E83Cu, ctx.xmm[0].u32[0]);
	// 0x297710: ret
	return;
}

void sub_297720(X86Context& ctx, uint8_t* base) {
	// 0x297720: movss xmm0, dword ptr [0x0056E850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E850u);
	// 0x297728: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x297730: movss [0x0056E8D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8D8u, ctx.xmm[0].u32[0]);
	// 0x297738: ret
	return;
}

void sub_297740(X86Context& ctx, uint8_t* base) {
	// 0x297740: movss xmm0, dword ptr [0x0056E850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E850u);
	// 0x297748: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x297750: movss [0x0056E87C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E87Cu, ctx.xmm[0].u32[0]);
	// 0x297758: ret
	return;
}

void sub_297760(X86Context& ctx, uint8_t* base) {
	// 0x297760: movss xmm0, dword ptr [0x0056E850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E850u);
	// 0x297768: subss xmm0, [0x0056E87C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E87Cu);
	// 0x297770: movss [0x0056E858], xmm0
	X86_MEM_WRITE_u32(base, 0x56E858u, ctx.xmm[0].u32[0]);
	// 0x297778: ret
	return;
}

void sub_297780(X86Context& ctx, uint8_t* base) {
	// 0x297780: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x297788: movss [0x0056E8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8A8u, ctx.xmm[0].u32[0]);
	// 0x297790: ret
	return;
}

void sub_2977A0(X86Context& ctx, uint8_t* base) {
	// 0x2977A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2977A8: movss [0x0056E854], xmm0
	X86_MEM_WRITE_u32(base, 0x56E854u, ctx.xmm[0].u32[0]);
	// 0x2977B0: ret
	return;
}

void sub_2977C0(X86Context& ctx, uint8_t* base) {
	// 0x2977C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2977C8: movss [0x0056E868], xmm0
	X86_MEM_WRITE_u32(base, 0x56E868u, ctx.xmm[0].u32[0]);
	// 0x2977D0: ret
	return;
}

void sub_2977E0(X86Context& ctx, uint8_t* base) {
	// 0x2977E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2977E8: movss [0x0056E8C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8C0u, ctx.xmm[0].u32[0]);
	// 0x2977F0: ret
	return;
}

void sub_297800(X86Context& ctx, uint8_t* base) {
	// 0x297800: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x297808: movss [0x0056E8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8A4u, ctx.xmm[0].u32[0]);
	// 0x297810: ret
	return;
}

void sub_297820(X86Context& ctx, uint8_t* base) {
	// 0x297820: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x297828: movss [0x0056E84C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E84Cu, ctx.xmm[0].u32[0]);
	// 0x297830: ret
	return;
}

void sub_297840(X86Context& ctx, uint8_t* base) {
	// 0x297840: movss xmm0, dword ptr [0x0056E868]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E868u);
	// 0x297848: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297850: movss [0x0056E840], xmm0
	X86_MEM_WRITE_u32(base, 0x56E840u, ctx.xmm[0].u32[0]);
	// 0x297858: ret
	return;
}

void sub_297860(X86Context& ctx, uint8_t* base) {
	// 0x297860: movss xmm0, dword ptr [0x0056E8C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C0u);
	// 0x297868: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x297870: movss [0x0056E888], xmm0
	X86_MEM_WRITE_u32(base, 0x56E888u, ctx.xmm[0].u32[0]);
	// 0x297878: ret
	return;
}

void sub_297880(X86Context& ctx, uint8_t* base) {
	// 0x297880: movss xmm0, dword ptr [0x0056E840]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E840u);
	// 0x297888: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297890: movss [0x0056E89C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E89Cu, ctx.xmm[0].u32[0]);
	// 0x297898: ret
	return;
}

void sub_2978A0(X86Context& ctx, uint8_t* base) {
	// 0x2978A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2978A8: movss [0x0056E838], xmm0
	X86_MEM_WRITE_u32(base, 0x56E838u, ctx.xmm[0].u32[0]);
	// 0x2978B0: ret
	return;
}

void sub_2978C0(X86Context& ctx, uint8_t* base) {
	// 0x2978C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2978C8: movss [0x0056E86C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E86Cu, ctx.xmm[0].u32[0]);
	// 0x2978D0: ret
	return;
}

void sub_2978E0(X86Context& ctx, uint8_t* base) {
	// 0x2978E0: movss xmm0, dword ptr [0x0056E868]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E868u);
	// 0x2978E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2978F0: movss [0x0056E878], xmm0
	X86_MEM_WRITE_u32(base, 0x56E878u, ctx.xmm[0].u32[0]);
	// 0x2978F8: ret
	return;
}

void sub_297900(X86Context& ctx, uint8_t* base) {
	// 0x297900: movss xmm0, dword ptr [0x0056E8C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C0u);
	// 0x297908: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x297910: movss [0x0056E8C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8C4u, ctx.xmm[0].u32[0]);
	// 0x297918: ret
	return;
}

void sub_297920(X86Context& ctx, uint8_t* base) {
	// 0x297920: movss xmm0, dword ptr [0x0056E878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E878u);
	// 0x297928: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297930: movss [0x0056E8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8B0u, ctx.xmm[0].u32[0]);
	// 0x297938: ret
	return;
}

void sub_297940(X86Context& ctx, uint8_t* base) {
	// 0x297940: movss xmm0, dword ptr [0x0056E8C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C4u);
	// 0x297948: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297950: movss [0x0056E8D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8D4u, ctx.xmm[0].u32[0]);
	// 0x297958: ret
	return;
}

void sub_297960(X86Context& ctx, uint8_t* base) {
	// 0x297960: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x297968: movss [0x0056E844], xmm0
	X86_MEM_WRITE_u32(base, 0x56E844u, ctx.xmm[0].u32[0]);
	// 0x297970: ret
	return;
}

void sub_297980(X86Context& ctx, uint8_t* base) {
	// 0x297980: movss xmm0, dword ptr [0x0056E868]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E868u);
	// 0x297988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297990: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x297998: movss [0x0056E8BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8BCu, ctx.xmm[0].u32[0]);
	// 0x2979A0: ret
	return;
}

void sub_2979B0(X86Context& ctx, uint8_t* base) {
	// 0x2979B0: movss xmm0, dword ptr [0x0056E8C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C0u);
	// 0x2979B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2979C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2979C8: movss [0x0056E85C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E85Cu, ctx.xmm[0].u32[0]);
	// 0x2979D0: ret
	return;
}

void sub_2979E0(X86Context& ctx, uint8_t* base) {
	// 0x2979E0: movss xmm0, dword ptr [0x0056E868]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E868u);
	// 0x2979E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2979F0: movss [0x0056E860], xmm0
	X86_MEM_WRITE_u32(base, 0x56E860u, ctx.xmm[0].u32[0]);
	// 0x2979F8: ret
	return;
}

void sub_297A00(X86Context& ctx, uint8_t* base) {
	// 0x297A00: movss xmm0, dword ptr [0x0056E8C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C0u);
	// 0x297A08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297A10: movss [0x0056E8C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8C8u, ctx.xmm[0].u32[0]);
	// 0x297A18: ret
	return;
}

void sub_297A20(X86Context& ctx, uint8_t* base) {
	// 0x297A20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x297A28: movss [0x0056E848], xmm0
	X86_MEM_WRITE_u32(base, 0x56E848u, ctx.xmm[0].u32[0]);
	// 0x297A30: ret
	return;
}

void sub_297A40(X86Context& ctx, uint8_t* base) {
	// 0x297A40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x297A48: movss [0x0056E874], xmm0
	X86_MEM_WRITE_u32(base, 0x56E874u, ctx.xmm[0].u32[0]);
	// 0x297A50: ret
	return;
}

void sub_297A60(X86Context& ctx, uint8_t* base) {
	// 0x297A60: movss xmm0, dword ptr [0x0056E848]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E848u);
	// 0x297A68: movss [0x0056E8DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8DCu, ctx.xmm[0].u32[0]);
	// 0x297A70: ret
	return;
}

void sub_297A80(X86Context& ctx, uint8_t* base) {
	// 0x297A80: movss xmm0, dword ptr [0x0056E8C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C0u);
	// 0x297A88: subss xmm0, [0x0056E848]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E848u);
	// 0x297A90: movss [0x0056E8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8A0u, ctx.xmm[0].u32[0]);
	// 0x297A98: ret
	return;
}

void sub_297AA0(X86Context& ctx, uint8_t* base) {
	// 0x297AA0: movss xmm0, dword ptr [0x0056E8A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8A0u);
	// 0x297AA8: subss xmm0, [0x0056E874]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E874u);
	// 0x297AB0: movss [0x0056E898], xmm0
	X86_MEM_WRITE_u32(base, 0x56E898u, ctx.xmm[0].u32[0]);
	// 0x297AB8: ret
	return;
}

void sub_297AC0(X86Context& ctx, uint8_t* base) {
	// 0x297AC0: movss xmm0, dword ptr [0x0056E8C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8C8u);
	// 0x297AC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x297AD0: movss [0x0056E884], xmm0
	X86_MEM_WRITE_u32(base, 0x56E884u, ctx.xmm[0].u32[0]);
	// 0x297AD8: ret
	return;
}

void sub_297AE0(X86Context& ctx, uint8_t* base) {
	// 0x297AE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x297AE8: movss [0x0056E870], xmm0
	X86_MEM_WRITE_u32(base, 0x56E870u, ctx.xmm[0].u32[0]);
	// 0x297AF0: ret
	return;
}

void sub_297B00(X86Context& ctx, uint8_t* base) {
	// 0x297B00: movss xmm0, dword ptr [0x0056E884]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E884u);
	// 0x297B08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x297B10: movss [0x0056E8B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8B8u, ctx.xmm[0].u32[0]);
	// 0x297B18: ret
	return;
}

void sub_297B20(X86Context& ctx, uint8_t* base) {
	// 0x297B20: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x297B28: movss [0x0056E88C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E88Cu, ctx.xmm[0].u32[0]);
	// 0x297B30: ret
	return;
}

void sub_297B40(X86Context& ctx, uint8_t* base) {
	// 0x297B40: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x297B48: movss [0x0056E864], xmm0
	X86_MEM_WRITE_u32(base, 0x56E864u, ctx.xmm[0].u32[0]);
	// 0x297B50: ret
	return;
}

void sub_297B60(X86Context& ctx, uint8_t* base) {
	// 0x297B60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x297B68: movss [0x0056E948], xmm0
	X86_MEM_WRITE_u32(base, 0x56E948u, ctx.xmm[0].u32[0]);
	// 0x297B70: ret
	return;
}

void sub_297B80(X86Context& ctx, uint8_t* base) {
	// 0x297B80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x297B88: movss [0x0056E964], xmm0
	X86_MEM_WRITE_u32(base, 0x56E964u, ctx.xmm[0].u32[0]);
	// 0x297B90: ret
	return;
}

void sub_297BA0(X86Context& ctx, uint8_t* base) {
	// 0x297BA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x297BA8: movss [0x0056E938], xmm0
	X86_MEM_WRITE_u32(base, 0x56E938u, ctx.xmm[0].u32[0]);
	// 0x297BB0: ret
	return;
}

void sub_297BC0(X86Context& ctx, uint8_t* base) {
	// 0x297BC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x297BC8: movss [0x0056E8E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8E8u, ctx.xmm[0].u32[0]);
	// 0x297BD0: ret
	return;
}

void sub_297BE0(X86Context& ctx, uint8_t* base) {
	// 0x297BE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x297BE8: movss [0x0056E94C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E94Cu, ctx.xmm[0].u32[0]);
	// 0x297BF0: ret
	return;
}

void sub_297C00(X86Context& ctx, uint8_t* base) {
	// 0x297C00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x297C08: movss [0x0056E904], xmm0
	X86_MEM_WRITE_u32(base, 0x56E904u, ctx.xmm[0].u32[0]);
	// 0x297C10: ret
	return;
}

void sub_297C20(X86Context& ctx, uint8_t* base) {
	// 0x297C20: movss xmm0, dword ptr [0x0056E94C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E94Cu);
	// 0x297C28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297C30: movss [0x0056E984], xmm0
	X86_MEM_WRITE_u32(base, 0x56E984u, ctx.xmm[0].u32[0]);
	// 0x297C38: ret
	return;
}

void sub_297C40(X86Context& ctx, uint8_t* base) {
	// 0x297C40: movss xmm0, dword ptr [0x0056E904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E904u);
	// 0x297C48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x297C50: movss [0x0056E96C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E96Cu, ctx.xmm[0].u32[0]);
	// 0x297C58: ret
	return;
}

void sub_297C60(X86Context& ctx, uint8_t* base) {
	// 0x297C60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x297C68: movss [0x0056E99C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E99Cu, ctx.xmm[0].u32[0]);
	// 0x297C70: ret
	return;
}

void sub_297C80(X86Context& ctx, uint8_t* base) {
	// 0x297C80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x297C88: movss [0x0056E988], xmm0
	X86_MEM_WRITE_u32(base, 0x56E988u, ctx.xmm[0].u32[0]);
	// 0x297C90: ret
	return;
}

void sub_297CA0(X86Context& ctx, uint8_t* base) {
	// 0x297CA0: movss xmm0, dword ptr [0x0056E988]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E988u);
	// 0x297CA8: movss [0x0056E998], xmm0
	X86_MEM_WRITE_u32(base, 0x56E998u, ctx.xmm[0].u32[0]);
	// 0x297CB0: ret
	return;
}

void sub_297CC0(X86Context& ctx, uint8_t* base) {
	// 0x297CC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x297CC8: movss [0x0056E8F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8F0u, ctx.xmm[0].u32[0]);
	// 0x297CD0: ret
	return;
}

void sub_297CE0(X86Context& ctx, uint8_t* base) {
	// 0x297CE0: movss xmm0, dword ptr [0x0056E904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E904u);
	// 0x297CE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x297CF0: movss [0x0056E990], xmm0
	X86_MEM_WRITE_u32(base, 0x56E990u, ctx.xmm[0].u32[0]);
	// 0x297CF8: ret
	return;
}

void sub_297D00(X86Context& ctx, uint8_t* base) {
	// 0x297D00: movss xmm0, dword ptr [0x0056E904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E904u);
	// 0x297D08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x297D10: movss [0x0056E934], xmm0
	X86_MEM_WRITE_u32(base, 0x56E934u, ctx.xmm[0].u32[0]);
	// 0x297D18: ret
	return;
}

void sub_297D20(X86Context& ctx, uint8_t* base) {
	// 0x297D20: movss xmm0, dword ptr [0x0056E904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E904u);
	// 0x297D28: subss xmm0, [0x0056E934]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E934u);
	// 0x297D30: movss [0x0056E90C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E90Cu, ctx.xmm[0].u32[0]);
	// 0x297D38: ret
	return;
}

void sub_297D40(X86Context& ctx, uint8_t* base) {
	// 0x297D40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x297D48: movss [0x0056E960], xmm0
	X86_MEM_WRITE_u32(base, 0x56E960u, ctx.xmm[0].u32[0]);
	// 0x297D50: ret
	return;
}

void sub_297D60(X86Context& ctx, uint8_t* base) {
	// 0x297D60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x297D68: movss [0x0056E908], xmm0
	X86_MEM_WRITE_u32(base, 0x56E908u, ctx.xmm[0].u32[0]);
	// 0x297D70: ret
	return;
}

void sub_297D80(X86Context& ctx, uint8_t* base) {
	// 0x297D80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x297D88: movss [0x0056E920], xmm0
	X86_MEM_WRITE_u32(base, 0x56E920u, ctx.xmm[0].u32[0]);
	// 0x297D90: ret
	return;
}

void sub_297DA0(X86Context& ctx, uint8_t* base) {
	// 0x297DA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x297DA8: movss [0x0056E978], xmm0
	X86_MEM_WRITE_u32(base, 0x56E978u, ctx.xmm[0].u32[0]);
	// 0x297DB0: ret
	return;
}

void sub_297DC0(X86Context& ctx, uint8_t* base) {
	// 0x297DC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x297DC8: movss [0x0056E95C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E95Cu, ctx.xmm[0].u32[0]);
	// 0x297DD0: ret
	return;
}

void sub_297DE0(X86Context& ctx, uint8_t* base) {
	// 0x297DE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x297DE8: movss [0x0056E900], xmm0
	X86_MEM_WRITE_u32(base, 0x56E900u, ctx.xmm[0].u32[0]);
	// 0x297DF0: ret
	return;
}

void sub_297E00(X86Context& ctx, uint8_t* base) {
	// 0x297E00: movss xmm0, dword ptr [0x0056E920]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E920u);
	// 0x297E08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297E10: movss [0x0056E8F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8F4u, ctx.xmm[0].u32[0]);
	// 0x297E18: ret
	return;
}

void sub_297E20(X86Context& ctx, uint8_t* base) {
	// 0x297E20: movss xmm0, dword ptr [0x0056E978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E978u);
	// 0x297E28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x297E30: movss [0x0056E940], xmm0
	X86_MEM_WRITE_u32(base, 0x56E940u, ctx.xmm[0].u32[0]);
	// 0x297E38: ret
	return;
}

void sub_297E40(X86Context& ctx, uint8_t* base) {
	// 0x297E40: movss xmm0, dword ptr [0x0056E8F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8F4u);
	// 0x297E48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x297E50: movss [0x0056E954], xmm0
	X86_MEM_WRITE_u32(base, 0x56E954u, ctx.xmm[0].u32[0]);
	// 0x297E58: ret
	return;
}

void sub_297E60(X86Context& ctx, uint8_t* base) {
	// 0x297E60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x297E68: movss [0x0056E8EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8ECu, ctx.xmm[0].u32[0]);
	// 0x297E70: ret
	return;
}

void sub_297E80(X86Context& ctx, uint8_t* base) {
	// 0x297E80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x297E88: movss [0x0056E924], xmm0
	X86_MEM_WRITE_u32(base, 0x56E924u, ctx.xmm[0].u32[0]);
	// 0x297E90: ret
	return;
}

void sub_297EA0(X86Context& ctx, uint8_t* base) {
	// 0x297EA0: movss xmm0, dword ptr [0x0056E920]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E920u);
	// 0x297EA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x297EB0: movss [0x0056E930], xmm0
	X86_MEM_WRITE_u32(base, 0x56E930u, ctx.xmm[0].u32[0]);
	// 0x297EB8: ret
	return;
}

void sub_297EC0(X86Context& ctx, uint8_t* base) {
	// 0x297EC0: movss xmm0, dword ptr [0x0056E978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E978u);
	// 0x297EC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x297ED0: movss [0x0056E97C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E97Cu, ctx.xmm[0].u32[0]);
	// 0x297ED8: ret
	return;
}

void sub_297EE0(X86Context& ctx, uint8_t* base) {
	// 0x297EE0: movss xmm0, dword ptr [0x0056E930]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E930u);
	// 0x297EE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297EF0: movss [0x0056E968], xmm0
	X86_MEM_WRITE_u32(base, 0x56E968u, ctx.xmm[0].u32[0]);
	// 0x297EF8: ret
	return;
}

void sub_297F00(X86Context& ctx, uint8_t* base) {
	// 0x297F00: movss xmm0, dword ptr [0x0056E97C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E97Cu);
	// 0x297F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297F10: movss [0x0056E98C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E98Cu, ctx.xmm[0].u32[0]);
	// 0x297F18: ret
	return;
}

void sub_297F20(X86Context& ctx, uint8_t* base) {
	// 0x297F20: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x297F28: movss [0x0056E8F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8F8u, ctx.xmm[0].u32[0]);
	// 0x297F30: ret
	return;
}

void sub_297F40(X86Context& ctx, uint8_t* base) {
	// 0x297F40: movss xmm0, dword ptr [0x0056E920]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E920u);
	// 0x297F48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297F50: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x297F58: movss [0x0056E974], xmm0
	X86_MEM_WRITE_u32(base, 0x56E974u, ctx.xmm[0].u32[0]);
	// 0x297F60: ret
	return;
}

void sub_297F70(X86Context& ctx, uint8_t* base) {
	// 0x297F70: movss xmm0, dword ptr [0x0056E978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E978u);
	// 0x297F78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297F80: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x297F88: movss [0x0056E910], xmm0
	X86_MEM_WRITE_u32(base, 0x56E910u, ctx.xmm[0].u32[0]);
	// 0x297F90: ret
	return;
}

