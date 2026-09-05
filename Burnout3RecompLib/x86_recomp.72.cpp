#include "x86_recomp_shared.h"

void sub_2B2E80(X86Context& ctx, uint8_t* base) {
	// 0x2B2E80: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B2E88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2E90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B2E98: movss [0x00571E94], xmm0
	X86_MEM_WRITE_u32(base, 0x571E94u, ctx.xmm[0].u32[0]);
	// 0x2B2EA0: ret
	return;
}

void sub_2B2EB0(X86Context& ctx, uint8_t* base) {
	// 0x2B2EB0: movss xmm0, dword ptr [0x00571E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E98u);
	// 0x2B2EB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2EC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B2EC8: movss [0x00571E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E3Cu, ctx.xmm[0].u32[0]);
	// 0x2B2ED0: ret
	return;
}

void sub_2B2EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B2EE0: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B2EE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2EF0: movss [0x00571E40], xmm0
	X86_MEM_WRITE_u32(base, 0x571E40u, ctx.xmm[0].u32[0]);
	// 0x2B2EF8: ret
	return;
}

void sub_2B2F00(X86Context& ctx, uint8_t* base) {
	// 0x2B2F00: movss xmm0, dword ptr [0x00571E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E98u);
	// 0x2B2F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2F10: movss [0x00571EA0], xmm0
	X86_MEM_WRITE_u32(base, 0x571EA0u, ctx.xmm[0].u32[0]);
	// 0x2B2F18: ret
	return;
}

void sub_2B2F20(X86Context& ctx, uint8_t* base) {
	// 0x2B2F20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B2F28: movss [0x00571E28], xmm0
	X86_MEM_WRITE_u32(base, 0x571E28u, ctx.xmm[0].u32[0]);
	// 0x2B2F30: ret
	return;
}

void sub_2B2F40(X86Context& ctx, uint8_t* base) {
	// 0x2B2F40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B2F48: movss [0x00571E50], xmm0
	X86_MEM_WRITE_u32(base, 0x571E50u, ctx.xmm[0].u32[0]);
	// 0x2B2F50: ret
	return;
}

void sub_2B2F60(X86Context& ctx, uint8_t* base) {
	// 0x2B2F60: movss xmm0, dword ptr [0x00571E28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E28u);
	// 0x2B2F68: movss [0x00571EB4], xmm0
	X86_MEM_WRITE_u32(base, 0x571EB4u, ctx.xmm[0].u32[0]);
	// 0x2B2F70: ret
	return;
}

void sub_2B2F80(X86Context& ctx, uint8_t* base) {
	// 0x2B2F80: movss xmm0, dword ptr [0x00571E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E98u);
	// 0x2B2F88: subss xmm0, [0x00571E28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571E28u);
	// 0x2B2F90: movss [0x00571E78], xmm0
	X86_MEM_WRITE_u32(base, 0x571E78u, ctx.xmm[0].u32[0]);
	// 0x2B2F98: ret
	return;
}

void sub_2B2FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B2FA0: movss xmm0, dword ptr [0x00571E78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E78u);
	// 0x2B2FA8: subss xmm0, [0x00571E50]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571E50u);
	// 0x2B2FB0: movss [0x00571E70], xmm0
	X86_MEM_WRITE_u32(base, 0x571E70u, ctx.xmm[0].u32[0]);
	// 0x2B2FB8: ret
	return;
}

void sub_2B2FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B2FC0: movss xmm0, dword ptr [0x00571EA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EA0u);
	// 0x2B2FC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B2FD0: movss [0x00571E60], xmm0
	X86_MEM_WRITE_u32(base, 0x571E60u, ctx.xmm[0].u32[0]);
	// 0x2B2FD8: ret
	return;
}

void sub_2B2FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B2FE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B2FE8: movss [0x00571E4C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E4Cu, ctx.xmm[0].u32[0]);
	// 0x2B2FF0: ret
	return;
}

void sub_2B3000(X86Context& ctx, uint8_t* base) {
	// 0x2B3000: movss xmm0, dword ptr [0x00571E60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E60u);
	// 0x2B3008: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B3010: movss [0x00571E90], xmm0
	X86_MEM_WRITE_u32(base, 0x571E90u, ctx.xmm[0].u32[0]);
	// 0x2B3018: ret
	return;
}

void sub_2B3020(X86Context& ctx, uint8_t* base) {
	// 0x2B3020: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B3028: subss xmm0, [0x003A2808]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A2808u);
	// 0x2B3030: movss [0x004087B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4087B8u, ctx.xmm[0].u32[0]);
	// 0x2B3038: ret
	return;
}

void sub_2B3040(X86Context& ctx, uint8_t* base) {
	// 0x2B3040: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B3048: subss xmm0, [0x003A2808]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A2808u);
	// 0x2B3050: movss [0x004087D0], xmm0
	X86_MEM_WRITE_u32(base, 0x4087D0u, ctx.xmm[0].u32[0]);
	// 0x2B3058: ret
	return;
}

void sub_2B3060(X86Context& ctx, uint8_t* base) {
	// 0x2B3060: movss xmm0, dword ptr [0x00571E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E20u);
	// 0x2B3068: subss xmm0, [0x003B1884]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1884u);
	// 0x2B3070: movss [0x004087E0], xmm0
	X86_MEM_WRITE_u32(base, 0x4087E0u, ctx.xmm[0].u32[0]);
	// 0x2B3078: ret
	return;
}

void sub_2B3080(X86Context& ctx, uint8_t* base) {
	// 0x2B3080: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B3088: movss [0x004087E8], xmm0
	X86_MEM_WRITE_u32(base, 0x4087E8u, ctx.xmm[0].u32[0]);
	// 0x2B3090: ret
	return;
}

void sub_2B30A0(X86Context& ctx, uint8_t* base) {
	// 0x2B30A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B30A8: movss [0x00571F1C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F1Cu, ctx.xmm[0].u32[0]);
	// 0x2B30B0: ret
	return;
}

void sub_2B30C0(X86Context& ctx, uint8_t* base) {
	// 0x2B30C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B30C8: movss [0x00571F48], xmm0
	X86_MEM_WRITE_u32(base, 0x571F48u, ctx.xmm[0].u32[0]);
	// 0x2B30D0: ret
	return;
}

void sub_2B30E0(X86Context& ctx, uint8_t* base) {
	// 0x2B30E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B30E8: movss [0x00571F0C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F0Cu, ctx.xmm[0].u32[0]);
	// 0x2B30F0: ret
	return;
}

void sub_2B3100(X86Context& ctx, uint8_t* base) {
	// 0x2B3100: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B3108: movss [0x00571EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x571EC0u, ctx.xmm[0].u32[0]);
	// 0x2B3110: ret
	return;
}

void sub_2B3120(X86Context& ctx, uint8_t* base) {
	// 0x2B3120: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B3128: movss [0x00571F20], xmm0
	X86_MEM_WRITE_u32(base, 0x571F20u, ctx.xmm[0].u32[0]);
	// 0x2B3130: ret
	return;
}

void sub_2B3140(X86Context& ctx, uint8_t* base) {
	// 0x2B3140: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B3148: movss [0x00571EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x571EE0u, ctx.xmm[0].u32[0]);
	// 0x2B3150: ret
	return;
}

void sub_2B3160(X86Context& ctx, uint8_t* base) {
	// 0x2B3160: movss xmm0, dword ptr [0x00571F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F20u);
	// 0x2B3168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3170: movss [0x00571F68], xmm0
	X86_MEM_WRITE_u32(base, 0x571F68u, ctx.xmm[0].u32[0]);
	// 0x2B3178: ret
	return;
}

void sub_2B3180(X86Context& ctx, uint8_t* base) {
	// 0x2B3180: movss xmm0, dword ptr [0x00571EE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EE0u);
	// 0x2B3188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B3190: movss [0x00571F50], xmm0
	X86_MEM_WRITE_u32(base, 0x571F50u, ctx.xmm[0].u32[0]);
	// 0x2B3198: ret
	return;
}

void sub_2B31A0(X86Context& ctx, uint8_t* base) {
	// 0x2B31A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B31A8: movss [0x00571F80], xmm0
	X86_MEM_WRITE_u32(base, 0x571F80u, ctx.xmm[0].u32[0]);
	// 0x2B31B0: ret
	return;
}

void sub_2B31C0(X86Context& ctx, uint8_t* base) {
	// 0x2B31C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B31C8: movss [0x00571F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F6Cu, ctx.xmm[0].u32[0]);
	// 0x2B31D0: ret
	return;
}

void sub_2B31E0(X86Context& ctx, uint8_t* base) {
	// 0x2B31E0: movss xmm0, dword ptr [0x00571F6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F6Cu);
	// 0x2B31E8: movss [0x00571F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F7Cu, ctx.xmm[0].u32[0]);
	// 0x2B31F0: ret
	return;
}

void sub_2B3200(X86Context& ctx, uint8_t* base) {
	// 0x2B3200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B3208: movss [0x00571ECC], xmm0
	X86_MEM_WRITE_u32(base, 0x571ECCu, ctx.xmm[0].u32[0]);
	// 0x2B3210: ret
	return;
}

void sub_2B3220(X86Context& ctx, uint8_t* base) {
	// 0x2B3220: movss xmm0, dword ptr [0x00571EE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EE0u);
	// 0x2B3228: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B3230: movss [0x00571F74], xmm0
	X86_MEM_WRITE_u32(base, 0x571F74u, ctx.xmm[0].u32[0]);
	// 0x2B3238: ret
	return;
}

void sub_2B3240(X86Context& ctx, uint8_t* base) {
	// 0x2B3240: movss xmm0, dword ptr [0x00571EE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EE0u);
	// 0x2B3248: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B3250: movss [0x00571F08], xmm0
	X86_MEM_WRITE_u32(base, 0x571F08u, ctx.xmm[0].u32[0]);
	// 0x2B3258: ret
	return;
}

void sub_2B3260(X86Context& ctx, uint8_t* base) {
	// 0x2B3260: movss xmm0, dword ptr [0x00571EE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EE0u);
	// 0x2B3268: subss xmm0, [0x00571F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571F08u);
	// 0x2B3270: movss [0x00571EE8], xmm0
	X86_MEM_WRITE_u32(base, 0x571EE8u, ctx.xmm[0].u32[0]);
	// 0x2B3278: ret
	return;
}

void sub_2B3280(X86Context& ctx, uint8_t* base) {
	// 0x2B3280: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B3288: movss [0x00571F44], xmm0
	X86_MEM_WRITE_u32(base, 0x571F44u, ctx.xmm[0].u32[0]);
	// 0x2B3290: ret
	return;
}

void sub_2B32A0(X86Context& ctx, uint8_t* base) {
	// 0x2B32A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B32A8: movss [0x00571EE4], xmm0
	X86_MEM_WRITE_u32(base, 0x571EE4u, ctx.xmm[0].u32[0]);
	// 0x2B32B0: ret
	return;
}

void sub_2B32C0(X86Context& ctx, uint8_t* base) {
	// 0x2B32C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B32C8: movss [0x00571EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x571EF4u, ctx.xmm[0].u32[0]);
	// 0x2B32D0: ret
	return;
}

void sub_2B32E0(X86Context& ctx, uint8_t* base) {
	// 0x2B32E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B32E8: movss [0x00571F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F5Cu, ctx.xmm[0].u32[0]);
	// 0x2B32F0: ret
	return;
}

void sub_2B3300(X86Context& ctx, uint8_t* base) {
	// 0x2B3300: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B3308: movss [0x00571F34], xmm0
	X86_MEM_WRITE_u32(base, 0x571F34u, ctx.xmm[0].u32[0]);
	// 0x2B3310: ret
	return;
}

void sub_2B3320(X86Context& ctx, uint8_t* base) {
	// 0x2B3320: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B3328: movss [0x00571EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x571EDCu, ctx.xmm[0].u32[0]);
	// 0x2B3330: ret
	return;
}

void sub_2B3340(X86Context& ctx, uint8_t* base) {
	// 0x2B3340: movss xmm0, dword ptr [0x00571EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EF4u);
	// 0x2B3348: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3350: movss [0x00571ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x571ED0u, ctx.xmm[0].u32[0]);
	// 0x2B3358: ret
	return;
}

void sub_2B3360(X86Context& ctx, uint8_t* base) {
	// 0x2B3360: movss xmm0, dword ptr [0x00571F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F5Cu);
	// 0x2B3368: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B3370: movss [0x00571F18], xmm0
	X86_MEM_WRITE_u32(base, 0x571F18u, ctx.xmm[0].u32[0]);
	// 0x2B3378: ret
	return;
}

void sub_2B3380(X86Context& ctx, uint8_t* base) {
	// 0x2B3380: movss xmm0, dword ptr [0x00571ED0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ED0u);
	// 0x2B3388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3390: movss [0x00571F2C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F2Cu, ctx.xmm[0].u32[0]);
	// 0x2B3398: ret
	return;
}

void sub_2B33A0(X86Context& ctx, uint8_t* base) {
	// 0x2B33A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B33A8: movss [0x00571EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x571EC8u, ctx.xmm[0].u32[0]);
	// 0x2B33B0: ret
	return;
}

void sub_2B33C0(X86Context& ctx, uint8_t* base) {
	// 0x2B33C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B33C8: movss [0x00571EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x571EF8u, ctx.xmm[0].u32[0]);
	// 0x2B33D0: ret
	return;
}

void sub_2B33E0(X86Context& ctx, uint8_t* base) {
	// 0x2B33E0: movss xmm0, dword ptr [0x00571EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EF4u);
	// 0x2B33E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B33F0: movss [0x00571F04], xmm0
	X86_MEM_WRITE_u32(base, 0x571F04u, ctx.xmm[0].u32[0]);
	// 0x2B33F8: ret
	return;
}

void sub_2B3400(X86Context& ctx, uint8_t* base) {
	// 0x2B3400: movss xmm0, dword ptr [0x00571F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F5Cu);
	// 0x2B3408: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B3410: movss [0x00571F60], xmm0
	X86_MEM_WRITE_u32(base, 0x571F60u, ctx.xmm[0].u32[0]);
	// 0x2B3418: ret
	return;
}

void sub_2B3420(X86Context& ctx, uint8_t* base) {
	// 0x2B3420: movss xmm0, dword ptr [0x00571F04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F04u);
	// 0x2B3428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3430: movss [0x00571F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F4Cu, ctx.xmm[0].u32[0]);
	// 0x2B3438: ret
	return;
}

void sub_2B3440(X86Context& ctx, uint8_t* base) {
	// 0x2B3440: movss xmm0, dword ptr [0x00571F60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F60u);
	// 0x2B3448: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3450: movss [0x00571F70], xmm0
	X86_MEM_WRITE_u32(base, 0x571F70u, ctx.xmm[0].u32[0]);
	// 0x2B3458: ret
	return;
}

void sub_2B3460(X86Context& ctx, uint8_t* base) {
	// 0x2B3460: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B3468: movss [0x00571ED4], xmm0
	X86_MEM_WRITE_u32(base, 0x571ED4u, ctx.xmm[0].u32[0]);
	// 0x2B3470: ret
	return;
}

void sub_2B3480(X86Context& ctx, uint8_t* base) {
	// 0x2B3480: movss xmm0, dword ptr [0x00571EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EF4u);
	// 0x2B3488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3490: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B3498: movss [0x00571F58], xmm0
	X86_MEM_WRITE_u32(base, 0x571F58u, ctx.xmm[0].u32[0]);
	// 0x2B34A0: ret
	return;
}

void sub_2B34B0(X86Context& ctx, uint8_t* base) {
	// 0x2B34B0: movss xmm0, dword ptr [0x00571F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F5Cu);
	// 0x2B34B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B34C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B34C8: movss [0x00571EEC], xmm0
	X86_MEM_WRITE_u32(base, 0x571EECu, ctx.xmm[0].u32[0]);
	// 0x2B34D0: ret
	return;
}

void sub_2B34E0(X86Context& ctx, uint8_t* base) {
	// 0x2B34E0: movss xmm0, dword ptr [0x00571EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EF4u);
	// 0x2B34E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B34F0: movss [0x00571EF0], xmm0
	X86_MEM_WRITE_u32(base, 0x571EF0u, ctx.xmm[0].u32[0]);
	// 0x2B34F8: ret
	return;
}

void sub_2B3500(X86Context& ctx, uint8_t* base) {
	// 0x2B3500: movss xmm0, dword ptr [0x00571F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F5Cu);
	// 0x2B3508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3510: movss [0x00571F64], xmm0
	X86_MEM_WRITE_u32(base, 0x571F64u, ctx.xmm[0].u32[0]);
	// 0x2B3518: ret
	return;
}

void sub_2B3520(X86Context& ctx, uint8_t* base) {
	// 0x2B3520: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B3528: movss [0x00571ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x571ED8u, ctx.xmm[0].u32[0]);
	// 0x2B3530: ret
	return;
}

void sub_2B3540(X86Context& ctx, uint8_t* base) {
	// 0x2B3540: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B3548: movss [0x00571F00], xmm0
	X86_MEM_WRITE_u32(base, 0x571F00u, ctx.xmm[0].u32[0]);
	// 0x2B3550: ret
	return;
}

void sub_2B3560(X86Context& ctx, uint8_t* base) {
	// 0x2B3560: movss xmm0, dword ptr [0x00571ED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ED8u);
	// 0x2B3568: movss [0x00571F78], xmm0
	X86_MEM_WRITE_u32(base, 0x571F78u, ctx.xmm[0].u32[0]);
	// 0x2B3570: ret
	return;
}

void sub_2B3580(X86Context& ctx, uint8_t* base) {
	// 0x2B3580: movss xmm0, dword ptr [0x00571F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F5Cu);
	// 0x2B3588: subss xmm0, [0x00571ED8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571ED8u);
	// 0x2B3590: movss [0x00571F30], xmm0
	X86_MEM_WRITE_u32(base, 0x571F30u, ctx.xmm[0].u32[0]);
	// 0x2B3598: ret
	return;
}

void sub_2B35A0(X86Context& ctx, uint8_t* base) {
	// 0x2B35A0: movss xmm0, dword ptr [0x00571F30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F30u);
	// 0x2B35A8: subss xmm0, [0x00571F00]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571F00u);
	// 0x2B35B0: movss [0x00571F28], xmm0
	X86_MEM_WRITE_u32(base, 0x571F28u, ctx.xmm[0].u32[0]);
	// 0x2B35B8: ret
	return;
}

void sub_2B35C0(X86Context& ctx, uint8_t* base) {
	// 0x2B35C0: movss xmm0, dword ptr [0x00571F64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F64u);
	// 0x2B35C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B35D0: movss [0x00571F10], xmm0
	X86_MEM_WRITE_u32(base, 0x571F10u, ctx.xmm[0].u32[0]);
	// 0x2B35D8: ret
	return;
}

void sub_2B35E0(X86Context& ctx, uint8_t* base) {
	// 0x2B35E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B35E8: movss [0x00571EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x571EFCu, ctx.xmm[0].u32[0]);
	// 0x2B35F0: ret
	return;
}

void sub_2B3600(X86Context& ctx, uint8_t* base) {
	// 0x2B3600: movss xmm0, dword ptr [0x00571F10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F10u);
	// 0x2B3608: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B3610: movss [0x00571F54], xmm0
	X86_MEM_WRITE_u32(base, 0x571F54u, ctx.xmm[0].u32[0]);
	// 0x2B3618: ret
	return;
}

void sub_2B3620(X86Context& ctx, uint8_t* base) {
	// 0x2B3620: movss xmm0, dword ptr [0x00571F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F34u);
	// 0x2B3628: movss [0x00571F14], xmm0
	X86_MEM_WRITE_u32(base, 0x571F14u, ctx.xmm[0].u32[0]);
	// 0x2B3630: ret
	return;
}

void sub_2B3640(X86Context& ctx, uint8_t* base) {
	// 0x2B3640: movss xmm0, dword ptr [0x00571F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F34u);
	// 0x2B3648: movss [0x00571F40], xmm0
	X86_MEM_WRITE_u32(base, 0x571F40u, ctx.xmm[0].u32[0]);
	// 0x2B3650: ret
	return;
}

void sub_2B3660(X86Context& ctx, uint8_t* base) {
	// 0x2B3660: movss xmm0, dword ptr [0x00571F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F34u);
	// 0x2B3668: movss [0x00571F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F3Cu, ctx.xmm[0].u32[0]);
	// 0x2B3670: ret
	return;
}

void sub_2B3680(X86Context& ctx, uint8_t* base) {
	// 0x2B3680: movss xmm0, dword ptr [0x00571F18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F18u);
	// 0x2B3688: subss xmm0, [0x003B22F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B22F8u);
	// 0x2B3690: movss [0x00571EC4], xmm0
	X86_MEM_WRITE_u32(base, 0x571EC4u, ctx.xmm[0].u32[0]);
	// 0x2B3698: ret
	return;
}

void sub_2B36A0(X86Context& ctx, uint8_t* base) {
	// 0x2B36A0: movss xmm0, dword ptr [0x00571F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F34u);
	// 0x2B36A8: movss [0x00571F24], xmm0
	X86_MEM_WRITE_u32(base, 0x571F24u, ctx.xmm[0].u32[0]);
	// 0x2B36B0: ret
	return;
}

void sub_2B36C0(X86Context& ctx, uint8_t* base) {
	// 0x2B36C0: movss xmm0, dword ptr [0x00571EDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EDCu);
	// 0x2B36C8: movss [0x00571F38], xmm0
	X86_MEM_WRITE_u32(base, 0x571F38u, ctx.xmm[0].u32[0]);
	// 0x2B36D0: ret
	return;
}

void sub_2B36E0(X86Context& ctx, uint8_t* base) {
	// 0x2B36E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B36E8: movss [0x00571FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x571FDCu, ctx.xmm[0].u32[0]);
	// 0x2B36F0: ret
	return;
}

void sub_2B3700(X86Context& ctx, uint8_t* base) {
	// 0x2B3700: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B3708: movss [0x00571FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x571FF8u, ctx.xmm[0].u32[0]);
	// 0x2B3710: ret
	return;
}

void sub_2B3720(X86Context& ctx, uint8_t* base) {
	// 0x2B3720: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B3728: movss [0x00571FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x571FCCu, ctx.xmm[0].u32[0]);
	// 0x2B3730: ret
	return;
}

void sub_2B3740(X86Context& ctx, uint8_t* base) {
	// 0x2B3740: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B3748: movss [0x00571F84], xmm0
	X86_MEM_WRITE_u32(base, 0x571F84u, ctx.xmm[0].u32[0]);
	// 0x2B3750: ret
	return;
}

void sub_2B3760(X86Context& ctx, uint8_t* base) {
	// 0x2B3760: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B3768: movss [0x00571FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x571FE0u, ctx.xmm[0].u32[0]);
	// 0x2B3770: ret
	return;
}

void sub_2B3780(X86Context& ctx, uint8_t* base) {
	// 0x2B3780: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B3788: movss [0x00571FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x571FA0u, ctx.xmm[0].u32[0]);
	// 0x2B3790: ret
	return;
}

void sub_2B37A0(X86Context& ctx, uint8_t* base) {
	// 0x2B37A0: movss xmm0, dword ptr [0x00571FE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FE0u);
	// 0x2B37A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B37B0: movss [0x00572018], xmm0
	X86_MEM_WRITE_u32(base, 0x572018u, ctx.xmm[0].u32[0]);
	// 0x2B37B8: ret
	return;
}

void sub_2B37C0(X86Context& ctx, uint8_t* base) {
	// 0x2B37C0: movss xmm0, dword ptr [0x00571FA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FA0u);
	// 0x2B37C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B37D0: movss [0x00572000], xmm0
	X86_MEM_WRITE_u32(base, 0x572000u, ctx.xmm[0].u32[0]);
	// 0x2B37D8: ret
	return;
}

void sub_2B37E0(X86Context& ctx, uint8_t* base) {
	// 0x2B37E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B37E8: movss [0x00572030], xmm0
	X86_MEM_WRITE_u32(base, 0x572030u, ctx.xmm[0].u32[0]);
	// 0x2B37F0: ret
	return;
}

void sub_2B3800(X86Context& ctx, uint8_t* base) {
	// 0x2B3800: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B3808: movss [0x0057201C], xmm0
	X86_MEM_WRITE_u32(base, 0x57201Cu, ctx.xmm[0].u32[0]);
	// 0x2B3810: ret
	return;
}

void sub_2B3820(X86Context& ctx, uint8_t* base) {
	// 0x2B3820: movss xmm0, dword ptr [0x0057201C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57201Cu);
	// 0x2B3828: movss [0x0057202C], xmm0
	X86_MEM_WRITE_u32(base, 0x57202Cu, ctx.xmm[0].u32[0]);
	// 0x2B3830: ret
	return;
}

void sub_2B3840(X86Context& ctx, uint8_t* base) {
	// 0x2B3840: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B3848: movss [0x00571F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F8Cu, ctx.xmm[0].u32[0]);
	// 0x2B3850: ret
	return;
}

void sub_2B3860(X86Context& ctx, uint8_t* base) {
	// 0x2B3860: movss xmm0, dword ptr [0x00571FA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FA0u);
	// 0x2B3868: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B3870: movss [0x00572024], xmm0
	X86_MEM_WRITE_u32(base, 0x572024u, ctx.xmm[0].u32[0]);
	// 0x2B3878: ret
	return;
}

void sub_2B3880(X86Context& ctx, uint8_t* base) {
	// 0x2B3880: movss xmm0, dword ptr [0x00571FA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FA0u);
	// 0x2B3888: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B3890: movss [0x00571FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x571FC8u, ctx.xmm[0].u32[0]);
	// 0x2B3898: ret
	return;
}

void sub_2B38A0(X86Context& ctx, uint8_t* base) {
	// 0x2B38A0: movss xmm0, dword ptr [0x00571FA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FA0u);
	// 0x2B38A8: subss xmm0, [0x00571FC8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571FC8u);
	// 0x2B38B0: movss [0x00571FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x571FA8u, ctx.xmm[0].u32[0]);
	// 0x2B38B8: ret
	return;
}

void sub_2B38C0(X86Context& ctx, uint8_t* base) {
	// 0x2B38C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B38C8: movss [0x00571FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x571FF4u, ctx.xmm[0].u32[0]);
	// 0x2B38D0: ret
	return;
}

void sub_2B38E0(X86Context& ctx, uint8_t* base) {
	// 0x2B38E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B38E8: movss [0x00571FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x571FA4u, ctx.xmm[0].u32[0]);
	// 0x2B38F0: ret
	return;
}

void sub_2B3900(X86Context& ctx, uint8_t* base) {
	// 0x2B3900: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B3908: movss [0x00571FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x571FB4u, ctx.xmm[0].u32[0]);
	// 0x2B3910: ret
	return;
}

void sub_2B3920(X86Context& ctx, uint8_t* base) {
	// 0x2B3920: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B3928: movss [0x0057200C], xmm0
	X86_MEM_WRITE_u32(base, 0x57200Cu, ctx.xmm[0].u32[0]);
	// 0x2B3930: ret
	return;
}

void sub_2B3940(X86Context& ctx, uint8_t* base) {
	// 0x2B3940: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B3948: movss [0x00571FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x571FF0u, ctx.xmm[0].u32[0]);
	// 0x2B3950: ret
	return;
}

void sub_2B3960(X86Context& ctx, uint8_t* base) {
	// 0x2B3960: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B3968: movss [0x00571F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x571F9Cu, ctx.xmm[0].u32[0]);
	// 0x2B3970: ret
	return;
}

void sub_2B3980(X86Context& ctx, uint8_t* base) {
	// 0x2B3980: movss xmm0, dword ptr [0x00571FB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FB4u);
	// 0x2B3988: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3990: movss [0x00571F90], xmm0
	X86_MEM_WRITE_u32(base, 0x571F90u, ctx.xmm[0].u32[0]);
	// 0x2B3998: ret
	return;
}

void sub_2B39A0(X86Context& ctx, uint8_t* base) {
	// 0x2B39A0: movss xmm0, dword ptr [0x0057200C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57200Cu);
	// 0x2B39A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B39B0: movss [0x00571FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x571FD8u, ctx.xmm[0].u32[0]);
	// 0x2B39B8: ret
	return;
}

void sub_2B39C0(X86Context& ctx, uint8_t* base) {
	// 0x2B39C0: movss xmm0, dword ptr [0x00571F90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F90u);
	// 0x2B39C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B39D0: movss [0x00571FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x571FE8u, ctx.xmm[0].u32[0]);
	// 0x2B39D8: ret
	return;
}

void sub_2B39E0(X86Context& ctx, uint8_t* base) {
	// 0x2B39E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B39E8: movss [0x00571F88], xmm0
	X86_MEM_WRITE_u32(base, 0x571F88u, ctx.xmm[0].u32[0]);
	// 0x2B39F0: ret
	return;
}

void sub_2B3A00(X86Context& ctx, uint8_t* base) {
	// 0x2B3A00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B3A08: movss [0x00571FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x571FB8u, ctx.xmm[0].u32[0]);
	// 0x2B3A10: ret
	return;
}

void sub_2B3A20(X86Context& ctx, uint8_t* base) {
	// 0x2B3A20: movss xmm0, dword ptr [0x00571FB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FB4u);
	// 0x2B3A28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B3A30: movss [0x00571FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x571FC4u, ctx.xmm[0].u32[0]);
	// 0x2B3A38: ret
	return;
}

void sub_2B3A40(X86Context& ctx, uint8_t* base) {
	// 0x2B3A40: movss xmm0, dword ptr [0x0057200C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57200Cu);
	// 0x2B3A48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B3A50: movss [0x00572010], xmm0
	X86_MEM_WRITE_u32(base, 0x572010u, ctx.xmm[0].u32[0]);
	// 0x2B3A58: ret
	return;
}

void sub_2B3A60(X86Context& ctx, uint8_t* base) {
	// 0x2B3A60: movss xmm0, dword ptr [0x00571FC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FC4u);
	// 0x2B3A68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3A70: movss [0x00571FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x571FFCu, ctx.xmm[0].u32[0]);
	// 0x2B3A78: ret
	return;
}

void sub_2B3A80(X86Context& ctx, uint8_t* base) {
	// 0x2B3A80: movss xmm0, dword ptr [0x00572010]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572010u);
	// 0x2B3A88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3A90: movss [0x00572020], xmm0
	X86_MEM_WRITE_u32(base, 0x572020u, ctx.xmm[0].u32[0]);
	// 0x2B3A98: ret
	return;
}

void sub_2B3AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B3AA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B3AA8: movss [0x00571F94], xmm0
	X86_MEM_WRITE_u32(base, 0x571F94u, ctx.xmm[0].u32[0]);
	// 0x2B3AB0: ret
	return;
}

void sub_2B3AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B3AC0: movss xmm0, dword ptr [0x00571FB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FB4u);
	// 0x2B3AC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3AD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B3AD8: movss [0x00572008], xmm0
	X86_MEM_WRITE_u32(base, 0x572008u, ctx.xmm[0].u32[0]);
	// 0x2B3AE0: ret
	return;
}

void sub_2B3AF0(X86Context& ctx, uint8_t* base) {
	// 0x2B3AF0: movss xmm0, dword ptr [0x0057200C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57200Cu);
	// 0x2B3AF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3B00: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B3B08: movss [0x00571FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x571FACu, ctx.xmm[0].u32[0]);
	// 0x2B3B10: ret
	return;
}

void sub_2B3B20(X86Context& ctx, uint8_t* base) {
	// 0x2B3B20: movss xmm0, dword ptr [0x00571FB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FB4u);
	// 0x2B3B28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3B30: movss [0x00571FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x571FB0u, ctx.xmm[0].u32[0]);
	// 0x2B3B38: ret
	return;
}

void sub_2B3B40(X86Context& ctx, uint8_t* base) {
	// 0x2B3B40: movss xmm0, dword ptr [0x0057200C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57200Cu);
	// 0x2B3B48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B3B50: movss [0x00572014], xmm0
	X86_MEM_WRITE_u32(base, 0x572014u, ctx.xmm[0].u32[0]);
	// 0x2B3B58: ret
	return;
}

void sub_2B3B60(X86Context& ctx, uint8_t* base) {
	// 0x2B3B60: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B3B68: movss [0x00571F98], xmm0
	X86_MEM_WRITE_u32(base, 0x571F98u, ctx.xmm[0].u32[0]);
	// 0x2B3B70: ret
	return;
}

void sub_2B3B80(X86Context& ctx, uint8_t* base) {
	// 0x2B3B80: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B3B88: movss [0x00571FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x571FC0u, ctx.xmm[0].u32[0]);
	// 0x2B3B90: ret
	return;
}

void sub_2B3BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B3BA0: movss xmm0, dword ptr [0x00571F98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571F98u);
	// 0x2B3BA8: movss [0x00572028], xmm0
	X86_MEM_WRITE_u32(base, 0x572028u, ctx.xmm[0].u32[0]);
	// 0x2B3BB0: ret
	return;
}

void sub_2B3BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B3BC0: movss xmm0, dword ptr [0x0057200C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57200Cu);
	// 0x2B3BC8: subss xmm0, [0x00571F98]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571F98u);
	// 0x2B3BD0: movss [0x00571FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x571FECu, ctx.xmm[0].u32[0]);
	// 0x2B3BD8: ret
	return;
}

void sub_2B3BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B3BE0: movss xmm0, dword ptr [0x00571FEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FECu);
	// 0x2B3BE8: subss xmm0, [0x00571FC0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571FC0u);
	// 0x2B3BF0: movss [0x00571FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x571FE4u, ctx.xmm[0].u32[0]);
	// 0x2B3BF8: ret
	return;
}

void sub_2B3C00(X86Context& ctx, uint8_t* base) {
	// 0x2B3C00: movss xmm0, dword ptr [0x00572014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572014u);
	// 0x2B3C08: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B3C10: movss [0x00571FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x571FD0u, ctx.xmm[0].u32[0]);
	// 0x2B3C18: ret
	return;
}

void sub_2B3C20(X86Context& ctx, uint8_t* base) {
	// 0x2B3C20: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B3C28: movss [0x00571FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x571FBCu, ctx.xmm[0].u32[0]);
	// 0x2B3C30: ret
	return;
}

void sub_2B3C40(X86Context& ctx, uint8_t* base) {
	// 0x2B3C40: movss xmm0, dword ptr [0x00571FD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571FD0u);
	// 0x2B3C48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B3C50: movss [0x00572004], xmm0
	X86_MEM_WRITE_u32(base, 0x572004u, ctx.xmm[0].u32[0]);
	// 0x2B3C58: ret
	return;
}

void sub_2B3C60(X86Context& ctx, uint8_t* base) {
	// 0x2B3C60: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B3C68: movss [0x00571FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x571FD4u, ctx.xmm[0].u32[0]);
	// 0x2B3C70: ret
	return;
}

void sub_2B3C80(X86Context& ctx, uint8_t* base) {
	// 0x2B3C80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B3C88: movss [0x0057209C], xmm0
	X86_MEM_WRITE_u32(base, 0x57209Cu, ctx.xmm[0].u32[0]);
	// 0x2B3C90: ret
	return;
}

void sub_2B3CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B3CA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B3CA8: movss [0x005720BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5720BCu, ctx.xmm[0].u32[0]);
	// 0x2B3CB0: ret
	return;
}

void sub_2B3CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B3CC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B3CC8: movss [0x00572088], xmm0
	X86_MEM_WRITE_u32(base, 0x572088u, ctx.xmm[0].u32[0]);
	// 0x2B3CD0: ret
	return;
}

void sub_2B3CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B3CE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B3CE8: movss [0x00572038], xmm0
	X86_MEM_WRITE_u32(base, 0x572038u, ctx.xmm[0].u32[0]);
	// 0x2B3CF0: ret
	return;
}

void sub_2B3D00(X86Context& ctx, uint8_t* base) {
	// 0x2B3D00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B3D08: movss [0x005720A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5720A0u, ctx.xmm[0].u32[0]);
	// 0x2B3D10: ret
	return;
}

void sub_2B3D20(X86Context& ctx, uint8_t* base) {
	// 0x2B3D20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B3D28: movss [0x00572058], xmm0
	X86_MEM_WRITE_u32(base, 0x572058u, ctx.xmm[0].u32[0]);
	// 0x2B3D30: ret
	return;
}

void sub_2B3D40(X86Context& ctx, uint8_t* base) {
	// 0x2B3D40: movss xmm0, dword ptr [0x005720A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720A0u);
	// 0x2B3D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3D50: movss [0x005720E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5720E0u, ctx.xmm[0].u32[0]);
	// 0x2B3D58: ret
	return;
}

void sub_2B3D60(X86Context& ctx, uint8_t* base) {
	// 0x2B3D60: movss xmm0, dword ptr [0x00572058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572058u);
	// 0x2B3D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B3D70: movss [0x005720C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5720C4u, ctx.xmm[0].u32[0]);
	// 0x2B3D78: ret
	return;
}

void sub_2B3D80(X86Context& ctx, uint8_t* base) {
	// 0x2B3D80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B3D88: movss [0x00572100], xmm0
	X86_MEM_WRITE_u32(base, 0x572100u, ctx.xmm[0].u32[0]);
	// 0x2B3D90: ret
	return;
}

void sub_2B3DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B3DA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B3DA8: movss [0x005720E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5720E4u, ctx.xmm[0].u32[0]);
	// 0x2B3DB0: ret
	return;
}

void sub_2B3DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B3DC0: movss xmm0, dword ptr [0x005720E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720E4u);
	// 0x2B3DC8: movss [0x005720F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5720F8u, ctx.xmm[0].u32[0]);
	// 0x2B3DD0: ret
	return;
}

void sub_2B3DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B3DE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B3DE8: movss [0x00572040], xmm0
	X86_MEM_WRITE_u32(base, 0x572040u, ctx.xmm[0].u32[0]);
	// 0x2B3DF0: ret
	return;
}

void sub_2B3E00(X86Context& ctx, uint8_t* base) {
	// 0x2B3E00: movss xmm0, dword ptr [0x00572058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572058u);
	// 0x2B3E08: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B3E10: movss [0x005720EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5720ECu, ctx.xmm[0].u32[0]);
	// 0x2B3E18: ret
	return;
}

void sub_2B3E20(X86Context& ctx, uint8_t* base) {
	// 0x2B3E20: movss xmm0, dword ptr [0x00572058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572058u);
	// 0x2B3E28: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B3E30: movss [0x00572084], xmm0
	X86_MEM_WRITE_u32(base, 0x572084u, ctx.xmm[0].u32[0]);
	// 0x2B3E38: ret
	return;
}

void sub_2B3E40(X86Context& ctx, uint8_t* base) {
	// 0x2B3E40: movss xmm0, dword ptr [0x00572058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572058u);
	// 0x2B3E48: subss xmm0, [0x00572084]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572084u);
	// 0x2B3E50: movss [0x00572064], xmm0
	X86_MEM_WRITE_u32(base, 0x572064u, ctx.xmm[0].u32[0]);
	// 0x2B3E58: ret
	return;
}

void sub_2B3E60(X86Context& ctx, uint8_t* base) {
	// 0x2B3E60: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B3E68: movss [0x005720B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5720B8u, ctx.xmm[0].u32[0]);
	// 0x2B3E70: ret
	return;
}

void sub_2B3E80(X86Context& ctx, uint8_t* base) {
	// 0x2B3E80: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B3E88: movss [0x0057205C], xmm0
	X86_MEM_WRITE_u32(base, 0x57205Cu, ctx.xmm[0].u32[0]);
	// 0x2B3E90: ret
	return;
}

void sub_2B3EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B3EA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B3EA8: movss [0x00572070], xmm0
	X86_MEM_WRITE_u32(base, 0x572070u, ctx.xmm[0].u32[0]);
	// 0x2B3EB0: ret
	return;
}

void sub_2B3EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B3EC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B3EC8: movss [0x005720D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5720D4u, ctx.xmm[0].u32[0]);
	// 0x2B3ED0: ret
	return;
}

void sub_2B3EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B3EE0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B3EE8: movss [0x005720B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5720B4u, ctx.xmm[0].u32[0]);
	// 0x2B3EF0: ret
	return;
}

void sub_2B3F00(X86Context& ctx, uint8_t* base) {
	// 0x2B3F00: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B3F08: movss [0x00572054], xmm0
	X86_MEM_WRITE_u32(base, 0x572054u, ctx.xmm[0].u32[0]);
	// 0x2B3F10: ret
	return;
}

void sub_2B3F20(X86Context& ctx, uint8_t* base) {
	// 0x2B3F20: movss xmm0, dword ptr [0x00572070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572070u);
	// 0x2B3F28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3F30: movss [0x00572048], xmm0
	X86_MEM_WRITE_u32(base, 0x572048u, ctx.xmm[0].u32[0]);
	// 0x2B3F38: ret
	return;
}

void sub_2B3F40(X86Context& ctx, uint8_t* base) {
	// 0x2B3F40: movss xmm0, dword ptr [0x005720D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720D4u);
	// 0x2B3F48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B3F50: movss [0x00572098], xmm0
	X86_MEM_WRITE_u32(base, 0x572098u, ctx.xmm[0].u32[0]);
	// 0x2B3F58: ret
	return;
}

void sub_2B3F60(X86Context& ctx, uint8_t* base) {
	// 0x2B3F60: movss xmm0, dword ptr [0x00572048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572048u);
	// 0x2B3F68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B3F70: movss [0x005720AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5720ACu, ctx.xmm[0].u32[0]);
	// 0x2B3F78: ret
	return;
}

void sub_2B3F80(X86Context& ctx, uint8_t* base) {
	// 0x2B3F80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B3F88: movss [0x0057203C], xmm0
	X86_MEM_WRITE_u32(base, 0x57203Cu, ctx.xmm[0].u32[0]);
	// 0x2B3F90: ret
	return;
}

void sub_2B3FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B3FA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B3FA8: movss [0x00572074], xmm0
	X86_MEM_WRITE_u32(base, 0x572074u, ctx.xmm[0].u32[0]);
	// 0x2B3FB0: ret
	return;
}

void sub_2B3FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B3FC0: movss xmm0, dword ptr [0x00572070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572070u);
	// 0x2B3FC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B3FD0: movss [0x00572080], xmm0
	X86_MEM_WRITE_u32(base, 0x572080u, ctx.xmm[0].u32[0]);
	// 0x2B3FD8: ret
	return;
}

void sub_2B3FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B3FE0: movss xmm0, dword ptr [0x005720D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720D4u);
	// 0x2B3FE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B3FF0: movss [0x005720D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5720D8u, ctx.xmm[0].u32[0]);
	// 0x2B3FF8: ret
	return;
}

void sub_2B4000(X86Context& ctx, uint8_t* base) {
	// 0x2B4000: movss xmm0, dword ptr [0x00572080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572080u);
	// 0x2B4008: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4010: movss [0x005720C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5720C0u, ctx.xmm[0].u32[0]);
	// 0x2B4018: ret
	return;
}

void sub_2B4020(X86Context& ctx, uint8_t* base) {
	// 0x2B4020: movss xmm0, dword ptr [0x005720D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720D8u);
	// 0x2B4028: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4030: movss [0x005720E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5720E8u, ctx.xmm[0].u32[0]);
	// 0x2B4038: ret
	return;
}

void sub_2B4040(X86Context& ctx, uint8_t* base) {
	// 0x2B4040: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B4048: movss [0x0057204C], xmm0
	X86_MEM_WRITE_u32(base, 0x57204Cu, ctx.xmm[0].u32[0]);
	// 0x2B4050: ret
	return;
}

void sub_2B4060(X86Context& ctx, uint8_t* base) {
	// 0x2B4060: movss xmm0, dword ptr [0x00572070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572070u);
	// 0x2B4068: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4070: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B4078: movss [0x005720CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5720CCu, ctx.xmm[0].u32[0]);
	// 0x2B4080: ret
	return;
}

void sub_2B4090(X86Context& ctx, uint8_t* base) {
	// 0x2B4090: movss xmm0, dword ptr [0x005720D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720D4u);
	// 0x2B4098: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B40A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B40A8: movss [0x00572068], xmm0
	X86_MEM_WRITE_u32(base, 0x572068u, ctx.xmm[0].u32[0]);
	// 0x2B40B0: ret
	return;
}

void sub_2B40C0(X86Context& ctx, uint8_t* base) {
	// 0x2B40C0: movss xmm0, dword ptr [0x00572070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572070u);
	// 0x2B40C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B40D0: movss [0x0057206C], xmm0
	X86_MEM_WRITE_u32(base, 0x57206Cu, ctx.xmm[0].u32[0]);
	// 0x2B40D8: ret
	return;
}

void sub_2B40E0(X86Context& ctx, uint8_t* base) {
	// 0x2B40E0: movss xmm0, dword ptr [0x005720D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720D4u);
	// 0x2B40E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B40F0: movss [0x005720DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5720DCu, ctx.xmm[0].u32[0]);
	// 0x2B40F8: ret
	return;
}

void sub_2B4100(X86Context& ctx, uint8_t* base) {
	// 0x2B4100: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B4108: movss [0x00572050], xmm0
	X86_MEM_WRITE_u32(base, 0x572050u, ctx.xmm[0].u32[0]);
	// 0x2B4110: ret
	return;
}

void sub_2B4120(X86Context& ctx, uint8_t* base) {
	// 0x2B4120: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B4128: movss [0x0057207C], xmm0
	X86_MEM_WRITE_u32(base, 0x57207Cu, ctx.xmm[0].u32[0]);
	// 0x2B4130: ret
	return;
}

void sub_2B4140(X86Context& ctx, uint8_t* base) {
	// 0x2B4140: movss xmm0, dword ptr [0x00572050]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572050u);
	// 0x2B4148: movss [0x005720F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5720F4u, ctx.xmm[0].u32[0]);
	// 0x2B4150: ret
	return;
}

void sub_2B4160(X86Context& ctx, uint8_t* base) {
	// 0x2B4160: movss xmm0, dword ptr [0x005720D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720D4u);
	// 0x2B4168: subss xmm0, [0x00572050]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572050u);
	// 0x2B4170: movss [0x005720B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5720B0u, ctx.xmm[0].u32[0]);
	// 0x2B4178: ret
	return;
}

void sub_2B4180(X86Context& ctx, uint8_t* base) {
	// 0x2B4180: movss xmm0, dword ptr [0x005720B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720B0u);
	// 0x2B4188: subss xmm0, [0x0057207C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57207Cu);
	// 0x2B4190: movss [0x005720A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5720A8u, ctx.xmm[0].u32[0]);
	// 0x2B4198: ret
	return;
}

void sub_2B41A0(X86Context& ctx, uint8_t* base) {
	// 0x2B41A0: movss xmm0, dword ptr [0x005720DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720DCu);
	// 0x2B41A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B41B0: movss [0x0057208C], xmm0
	X86_MEM_WRITE_u32(base, 0x57208Cu, ctx.xmm[0].u32[0]);
	// 0x2B41B8: ret
	return;
}

void sub_2B41C0(X86Context& ctx, uint8_t* base) {
	// 0x2B41C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B41C8: movss [0x00572078], xmm0
	X86_MEM_WRITE_u32(base, 0x572078u, ctx.xmm[0].u32[0]);
	// 0x2B41D0: ret
	return;
}

void sub_2B41E0(X86Context& ctx, uint8_t* base) {
	// 0x2B41E0: movss xmm0, dword ptr [0x0057208C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57208Cu);
	// 0x2B41E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B41F0: movss [0x005720C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5720C8u, ctx.xmm[0].u32[0]);
	// 0x2B41F8: ret
	return;
}

void sub_2B4200(X86Context& ctx, uint8_t* base) {
	// 0x2B4200: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B4208: movss [0x00572090], xmm0
	X86_MEM_WRITE_u32(base, 0x572090u, ctx.xmm[0].u32[0]);
	// 0x2B4210: ret
	return;
}

void sub_2B4220(X86Context& ctx, uint8_t* base) {
	// 0x2B4220: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2B4228: movss [0x00572094], xmm0
	X86_MEM_WRITE_u32(base, 0x572094u, ctx.xmm[0].u32[0]);
	// 0x2B4230: ret
	return;
}

void sub_2B4240(X86Context& ctx, uint8_t* base) {
	// 0x2B4240: movss xmm0, dword ptr [0x00572094]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572094u);
	// 0x2B4248: mulss xmm0, [0x003B1FE0]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1FE0u);
	// 0x2B4250: addss xmm0, [0x00408A20]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x408A20u);
	// 0x2B4258: movss [0x00572034], xmm0
	X86_MEM_WRITE_u32(base, 0x572034u, ctx.xmm[0].u32[0]);
	// 0x2B4260: ret
	return;
}

void sub_2B4270(X86Context& ctx, uint8_t* base) {
	// 0x2B4270: movss xmm0, dword ptr [0x003B22B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B0u);
	// 0x2B4278: movss [0x005720FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5720FCu, ctx.xmm[0].u32[0]);
	// 0x2B4280: ret
	return;
}

void sub_2B4290(X86Context& ctx, uint8_t* base) {
	// 0x2B4290: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B4298: divss xmm0, [0x005720FC]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x5720FCu);
	// 0x2B42A0: movss [0x00572060], xmm0
	X86_MEM_WRITE_u32(base, 0x572060u, ctx.xmm[0].u32[0]);
	// 0x2B42A8: ret
	return;
}

void sub_2B42B0(X86Context& ctx, uint8_t* base) {
	// 0x2B42B0: movss xmm0, dword ptr [0x003B22FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22FCu);
	// 0x2B42B8: movss [0x00572044], xmm0
	X86_MEM_WRITE_u32(base, 0x572044u, ctx.xmm[0].u32[0]);
	// 0x2B42C0: ret
	return;
}

void sub_2B42D0(X86Context& ctx, uint8_t* base) {
	// 0x2B42D0: movss xmm0, dword ptr [0x003B2304]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2304u);
	// 0x2B42D8: movss xmm1, dword ptr [0x003B2300]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B2300u);
	// 0x2B42E0: movss [0x00572104], xmm0
	X86_MEM_WRITE_u32(base, 0x572104u, ctx.xmm[0].u32[0]);
	// 0x2B42E8: movss [0x00572108], xmm0
	X86_MEM_WRITE_u32(base, 0x572108u, ctx.xmm[0].u32[0]);
	// 0x2B42F0: movss [0x0057210C], xmm0
	X86_MEM_WRITE_u32(base, 0x57210Cu, ctx.xmm[0].u32[0]);
	// 0x2B42F8: movss [0x00572110], xmm0
	X86_MEM_WRITE_u32(base, 0x572110u, ctx.xmm[0].u32[0]);
	// 0x2B4300: movss [0x00572114], xmm0
	X86_MEM_WRITE_u32(base, 0x572114u, ctx.xmm[0].u32[0]);
	// 0x2B4308: movss [0x00572118], xmm0
	X86_MEM_WRITE_u32(base, 0x572118u, ctx.xmm[0].u32[0]);
	// 0x2B4310: movss [0x0057211C], xmm1
	X86_MEM_WRITE_u32(base, 0x57211Cu, ctx.xmm[1].u32[0]);
	// 0x2B4318: movss [0x00572120], xmm0
	X86_MEM_WRITE_u32(base, 0x572120u, ctx.xmm[0].u32[0]);
	// 0x2B4320: movss [0x00572124], xmm0
	X86_MEM_WRITE_u32(base, 0x572124u, ctx.xmm[0].u32[0]);
	// 0x2B4328: ret
	return;
}

void sub_2B4330(X86Context& ctx, uint8_t* base) {
	// 0x2B4330: movss xmm0, dword ptr [0x00572104]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572104u);
	// 0x2B4338: addss xmm0, [0x00396EB0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x396EB0u);
	// 0x2B4340: movss [0x005720F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5720F0u, ctx.xmm[0].u32[0]);
	// 0x2B4348: ret
	return;
}

void sub_2B4350(X86Context& ctx, uint8_t* base) {
	// 0x2B4350: movss xmm0, dword ptr [0x003B2308]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2308u);
	// 0x2B4358: movss [0x005720D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5720D0u, ctx.xmm[0].u32[0]);
	// 0x2B4360: ret
	return;
}

void sub_2B4370(X86Context& ctx, uint8_t* base) {
	// 0x2B4370: movss xmm0, dword ptr [0x003B230C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B230Cu);
	// 0x2B4378: movss [0x005720A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5720A4u, ctx.xmm[0].u32[0]);
	// 0x2B4380: ret
	return;
}

void sub_2B4390(X86Context& ctx, uint8_t* base) {
	// 0x2B4390: movss xmm0, dword ptr [0x005720A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5720A4u);
	// 0x2B4398: movss [0x00408A38], xmm0
	X86_MEM_WRITE_u32(base, 0x408A38u, ctx.xmm[0].u32[0]);
	// 0x2B43A0: ret
	return;
}

void sub_2B43B0(X86Context& ctx, uint8_t* base) {
	// 0x2B43B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B43B8: movss [0x00572194], xmm0
	X86_MEM_WRITE_u32(base, 0x572194u, ctx.xmm[0].u32[0]);
	// 0x2B43C0: ret
	return;
}

void sub_2B43D0(X86Context& ctx, uint8_t* base) {
	// 0x2B43D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B43D8: movss [0x005721B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5721B4u, ctx.xmm[0].u32[0]);
	// 0x2B43E0: ret
	return;
}

void sub_2B43F0(X86Context& ctx, uint8_t* base) {
	// 0x2B43F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B43F8: movss [0x00572180], xmm0
	X86_MEM_WRITE_u32(base, 0x572180u, ctx.xmm[0].u32[0]);
	// 0x2B4400: ret
	return;
}

void sub_2B4410(X86Context& ctx, uint8_t* base) {
	// 0x2B4410: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B4418: movss [0x00572128], xmm0
	X86_MEM_WRITE_u32(base, 0x572128u, ctx.xmm[0].u32[0]);
	// 0x2B4420: ret
	return;
}

void sub_2B4430(X86Context& ctx, uint8_t* base) {
	// 0x2B4430: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B4438: movss [0x00572198], xmm0
	X86_MEM_WRITE_u32(base, 0x572198u, ctx.xmm[0].u32[0]);
	// 0x2B4440: ret
	return;
}

void sub_2B4450(X86Context& ctx, uint8_t* base) {
	// 0x2B4450: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B4458: movss [0x00572144], xmm0
	X86_MEM_WRITE_u32(base, 0x572144u, ctx.xmm[0].u32[0]);
	// 0x2B4460: ret
	return;
}

void sub_2B4470(X86Context& ctx, uint8_t* base) {
	// 0x2B4470: movss xmm0, dword ptr [0x00572198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572198u);
	// 0x2B4478: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B4480: movss [0x005721D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5721D4u, ctx.xmm[0].u32[0]);
	// 0x2B4488: ret
	return;
}

void sub_2B4490(X86Context& ctx, uint8_t* base) {
	// 0x2B4490: movss xmm0, dword ptr [0x00572144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572144u);
	// 0x2B4498: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B44A0: movss [0x005721BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5721BCu, ctx.xmm[0].u32[0]);
	// 0x2B44A8: ret
	return;
}

void sub_2B44B0(X86Context& ctx, uint8_t* base) {
	// 0x2B44B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B44B8: movss [0x005721EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5721ECu, ctx.xmm[0].u32[0]);
	// 0x2B44C0: ret
	return;
}

void sub_2B44D0(X86Context& ctx, uint8_t* base) {
	// 0x2B44D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B44D8: movss [0x005721D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5721D8u, ctx.xmm[0].u32[0]);
	// 0x2B44E0: ret
	return;
}

void sub_2B44F0(X86Context& ctx, uint8_t* base) {
	// 0x2B44F0: movss xmm0, dword ptr [0x005721D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721D8u);
	// 0x2B44F8: movss [0x005721E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5721E8u, ctx.xmm[0].u32[0]);
	// 0x2B4500: ret
	return;
}

void sub_2B4510(X86Context& ctx, uint8_t* base) {
	// 0x2B4510: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B4518: movss [0x00572130], xmm0
	X86_MEM_WRITE_u32(base, 0x572130u, ctx.xmm[0].u32[0]);
	// 0x2B4520: ret
	return;
}

void sub_2B4530(X86Context& ctx, uint8_t* base) {
	// 0x2B4530: movss xmm0, dword ptr [0x00572144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572144u);
	// 0x2B4538: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B4540: movss [0x005721E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5721E0u, ctx.xmm[0].u32[0]);
	// 0x2B4548: ret
	return;
}

void sub_2B4550(X86Context& ctx, uint8_t* base) {
	// 0x2B4550: movss xmm0, dword ptr [0x00572144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572144u);
	// 0x2B4558: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B4560: movss [0x0057217C], xmm0
	X86_MEM_WRITE_u32(base, 0x57217Cu, ctx.xmm[0].u32[0]);
	// 0x2B4568: ret
	return;
}

void sub_2B4570(X86Context& ctx, uint8_t* base) {
	// 0x2B4570: movss xmm0, dword ptr [0x00572144]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572144u);
	// 0x2B4578: subss xmm0, [0x0057217C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57217Cu);
	// 0x2B4580: movss [0x00572154], xmm0
	X86_MEM_WRITE_u32(base, 0x572154u, ctx.xmm[0].u32[0]);
	// 0x2B4588: ret
	return;
}

void sub_2B4590(X86Context& ctx, uint8_t* base) {
	// 0x2B4590: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B4598: movss [0x005721B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5721B0u, ctx.xmm[0].u32[0]);
	// 0x2B45A0: ret
	return;
}

void sub_2B45B0(X86Context& ctx, uint8_t* base) {
	// 0x2B45B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B45B8: movss [0x0057214C], xmm0
	X86_MEM_WRITE_u32(base, 0x57214Cu, ctx.xmm[0].u32[0]);
	// 0x2B45C0: ret
	return;
}

void sub_2B45D0(X86Context& ctx, uint8_t* base) {
	// 0x2B45D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B45D8: movss [0x00572168], xmm0
	X86_MEM_WRITE_u32(base, 0x572168u, ctx.xmm[0].u32[0]);
	// 0x2B45E0: ret
	return;
}

void sub_2B45F0(X86Context& ctx, uint8_t* base) {
	// 0x2B45F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B45F8: movss [0x005721C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5721C8u, ctx.xmm[0].u32[0]);
	// 0x2B4600: ret
	return;
}

void sub_2B4610(X86Context& ctx, uint8_t* base) {
	// 0x2B4610: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B4618: movss [0x005721A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5721A8u, ctx.xmm[0].u32[0]);
	// 0x2B4620: ret
	return;
}

void sub_2B4630(X86Context& ctx, uint8_t* base) {
	// 0x2B4630: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B4638: movss [0x00572140], xmm0
	X86_MEM_WRITE_u32(base, 0x572140u, ctx.xmm[0].u32[0]);
	// 0x2B4640: ret
	return;
}

void sub_2B4650(X86Context& ctx, uint8_t* base) {
	// 0x2B4650: movss xmm0, dword ptr [0x00572168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572168u);
	// 0x2B4658: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B4660: movss [0x00572134], xmm0
	X86_MEM_WRITE_u32(base, 0x572134u, ctx.xmm[0].u32[0]);
	// 0x2B4668: ret
	return;
}

void sub_2B4670(X86Context& ctx, uint8_t* base) {
	// 0x2B4670: movss xmm0, dword ptr [0x005721C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721C8u);
	// 0x2B4678: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B4680: movss [0x0057218C], xmm0
	X86_MEM_WRITE_u32(base, 0x57218Cu, ctx.xmm[0].u32[0]);
	// 0x2B4688: ret
	return;
}

void sub_2B4690(X86Context& ctx, uint8_t* base) {
	// 0x2B4690: movss xmm0, dword ptr [0x00572134]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572134u);
	// 0x2B4698: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B46A0: movss [0x005721A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5721A0u, ctx.xmm[0].u32[0]);
	// 0x2B46A8: ret
	return;
}

void sub_2B46B0(X86Context& ctx, uint8_t* base) {
	// 0x2B46B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B46B8: movss [0x0057212C], xmm0
	X86_MEM_WRITE_u32(base, 0x57212Cu, ctx.xmm[0].u32[0]);
	// 0x2B46C0: ret
	return;
}

void sub_2B46D0(X86Context& ctx, uint8_t* base) {
	// 0x2B46D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B46D8: movss [0x0057216C], xmm0
	X86_MEM_WRITE_u32(base, 0x57216Cu, ctx.xmm[0].u32[0]);
	// 0x2B46E0: ret
	return;
}

void sub_2B46F0(X86Context& ctx, uint8_t* base) {
	// 0x2B46F0: movss xmm0, dword ptr [0x00572168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572168u);
	// 0x2B46F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B4700: movss [0x00572178], xmm0
	X86_MEM_WRITE_u32(base, 0x572178u, ctx.xmm[0].u32[0]);
	// 0x2B4708: ret
	return;
}

void sub_2B4710(X86Context& ctx, uint8_t* base) {
	// 0x2B4710: movss xmm0, dword ptr [0x005721C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721C8u);
	// 0x2B4718: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B4720: movss [0x005721CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5721CCu, ctx.xmm[0].u32[0]);
	// 0x2B4728: ret
	return;
}

void sub_2B4730(X86Context& ctx, uint8_t* base) {
	// 0x2B4730: movss xmm0, dword ptr [0x00572178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572178u);
	// 0x2B4738: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4740: movss [0x005721B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5721B8u, ctx.xmm[0].u32[0]);
	// 0x2B4748: ret
	return;
}

void sub_2B4750(X86Context& ctx, uint8_t* base) {
	// 0x2B4750: movss xmm0, dword ptr [0x005721CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721CCu);
	// 0x2B4758: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4760: movss [0x005721DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5721DCu, ctx.xmm[0].u32[0]);
	// 0x2B4768: ret
	return;
}

void sub_2B4770(X86Context& ctx, uint8_t* base) {
	// 0x2B4770: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B4778: movss [0x00572138], xmm0
	X86_MEM_WRITE_u32(base, 0x572138u, ctx.xmm[0].u32[0]);
	// 0x2B4780: ret
	return;
}

void sub_2B4790(X86Context& ctx, uint8_t* base) {
	// 0x2B4790: movss xmm0, dword ptr [0x00572168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572168u);
	// 0x2B4798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B47A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B47A8: movss [0x005721C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5721C4u, ctx.xmm[0].u32[0]);
	// 0x2B47B0: ret
	return;
}

void sub_2B47C0(X86Context& ctx, uint8_t* base) {
	// 0x2B47C0: movss xmm0, dword ptr [0x005721C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721C8u);
	// 0x2B47C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B47D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B47D8: movss [0x0057215C], xmm0
	X86_MEM_WRITE_u32(base, 0x57215Cu, ctx.xmm[0].u32[0]);
	// 0x2B47E0: ret
	return;
}

void sub_2B47F0(X86Context& ctx, uint8_t* base) {
	// 0x2B47F0: movss xmm0, dword ptr [0x00572168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572168u);
	// 0x2B47F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4800: movss [0x00572160], xmm0
	X86_MEM_WRITE_u32(base, 0x572160u, ctx.xmm[0].u32[0]);
	// 0x2B4808: ret
	return;
}

void sub_2B4810(X86Context& ctx, uint8_t* base) {
	// 0x2B4810: movss xmm0, dword ptr [0x005721C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721C8u);
	// 0x2B4818: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B4820: movss [0x005721D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5721D0u, ctx.xmm[0].u32[0]);
	// 0x2B4828: ret
	return;
}

void sub_2B4830(X86Context& ctx, uint8_t* base) {
	// 0x2B4830: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B4838: movss [0x0057213C], xmm0
	X86_MEM_WRITE_u32(base, 0x57213Cu, ctx.xmm[0].u32[0]);
	// 0x2B4840: ret
	return;
}

void sub_2B4850(X86Context& ctx, uint8_t* base) {
	// 0x2B4850: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B4858: movss [0x00572174], xmm0
	X86_MEM_WRITE_u32(base, 0x572174u, ctx.xmm[0].u32[0]);
	// 0x2B4860: ret
	return;
}

void sub_2B4870(X86Context& ctx, uint8_t* base) {
	// 0x2B4870: movss xmm0, dword ptr [0x0057213C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57213Cu);
	// 0x2B4878: movss [0x005721E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5721E4u, ctx.xmm[0].u32[0]);
	// 0x2B4880: ret
	return;
}

void sub_2B4890(X86Context& ctx, uint8_t* base) {
	// 0x2B4890: movss xmm0, dword ptr [0x005721C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721C8u);
	// 0x2B4898: subss xmm0, [0x0057213C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57213Cu);
	// 0x2B48A0: movss [0x005721A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5721A4u, ctx.xmm[0].u32[0]);
	// 0x2B48A8: ret
	return;
}

void sub_2B48B0(X86Context& ctx, uint8_t* base) {
	// 0x2B48B0: movss xmm0, dword ptr [0x005721A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721A4u);
	// 0x2B48B8: subss xmm0, [0x00572174]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572174u);
	// 0x2B48C0: movss [0x0057219C], xmm0
	X86_MEM_WRITE_u32(base, 0x57219Cu, ctx.xmm[0].u32[0]);
	// 0x2B48C8: ret
	return;
}

void sub_2B48D0(X86Context& ctx, uint8_t* base) {
	// 0x2B48D0: movss xmm0, dword ptr [0x005721D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721D0u);
	// 0x2B48D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B48E0: movss [0x00572184], xmm0
	X86_MEM_WRITE_u32(base, 0x572184u, ctx.xmm[0].u32[0]);
	// 0x2B48E8: ret
	return;
}

void sub_2B48F0(X86Context& ctx, uint8_t* base) {
	// 0x2B48F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B48F8: movss [0x00572170], xmm0
	X86_MEM_WRITE_u32(base, 0x572170u, ctx.xmm[0].u32[0]);
	// 0x2B4900: ret
	return;
}

void sub_2B4910(X86Context& ctx, uint8_t* base) {
	// 0x2B4910: movss xmm0, dword ptr [0x00572184]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572184u);
	// 0x2B4918: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B4920: movss [0x005721C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5721C0u, ctx.xmm[0].u32[0]);
	// 0x2B4928: ret
	return;
}

void sub_2B4930(X86Context& ctx, uint8_t* base) {
	// 0x2B4930: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2B4938: movss [0x00572190], xmm0
	X86_MEM_WRITE_u32(base, 0x572190u, ctx.xmm[0].u32[0]);
	// 0x2B4940: ret
	return;
}

void sub_2B4950(X86Context& ctx, uint8_t* base) {
	// 0x2B4950: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2B4958: movss [0x00572164], xmm0
	X86_MEM_WRITE_u32(base, 0x572164u, ctx.xmm[0].u32[0]);
	// 0x2B4960: ret
	return;
}

void sub_2B4970(X86Context& ctx, uint8_t* base) {
	// 0x2B4970: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2B4978: movss [0x00572188], xmm0
	X86_MEM_WRITE_u32(base, 0x572188u, ctx.xmm[0].u32[0]);
	// 0x2B4980: ret
	return;
}

void sub_2B4990(X86Context& ctx, uint8_t* base) {
	// 0x2B4990: movss xmm0, dword ptr [0x00572188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572188u);
	// 0x2B4998: mulss xmm0, [0x003B1880]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1880u);
	// 0x2B49A0: addss xmm0, [0x00408AF0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x408AF0u);
	// 0x2B49A8: movss [0x00572148], xmm0
	X86_MEM_WRITE_u32(base, 0x572148u, ctx.xmm[0].u32[0]);
	// 0x2B49B0: ret
	return;
}

void sub_2B49C0(X86Context& ctx, uint8_t* base) {
	// 0x2B49C0: movss xmm0, dword ptr [0x003B22B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22B0u);
	// 0x2B49C8: movss [0x005721AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5721ACu, ctx.xmm[0].u32[0]);
	// 0x2B49D0: ret
	return;
}

void sub_2B49E0(X86Context& ctx, uint8_t* base) {
	// 0x2B49E0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B49E8: divss xmm0, [0x005721AC]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x5721ACu);
	// 0x2B49F0: movss [0x00572150], xmm0
	X86_MEM_WRITE_u32(base, 0x572150u, ctx.xmm[0].u32[0]);
	// 0x2B49F8: ret
	return;
}

void sub_2B4A00(X86Context& ctx, uint8_t* base) {
	// 0x2B4A00: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2B4A08: movss [0x00572158], xmm0
	X86_MEM_WRITE_u32(base, 0x572158u, ctx.xmm[0].u32[0]);
	// 0x2B4A10: ret
	return;
}

void sub_2B4A20(X86Context& ctx, uint8_t* base) {
	// 0x2B4A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B4A28: movss [0x0057220C], xmm0
	X86_MEM_WRITE_u32(base, 0x57220Cu, ctx.xmm[0].u32[0]);
	// 0x2B4A30: ret
	return;
}

void sub_2B4A40(X86Context& ctx, uint8_t* base) {
	// 0x2B4A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B4A48: movss [0x005722CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5722CCu, ctx.xmm[0].u32[0]);
	// 0x2B4A50: ret
	return;
}

void sub_2B4A60(X86Context& ctx, uint8_t* base) {
	// 0x2B4A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B4A68: movss [0x00572208], xmm0
	X86_MEM_WRITE_u32(base, 0x572208u, ctx.xmm[0].u32[0]);
	// 0x2B4A70: ret
	return;
}

void sub_2B4A80(X86Context& ctx, uint8_t* base) {
	// 0x2B4A80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B4A88: movss [0x005721F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5721F0u, ctx.xmm[0].u32[0]);
	// 0x2B4A90: ret
	return;
}

void sub_2B4AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B4AA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B4AA8: movss [0x00572210], xmm0
	X86_MEM_WRITE_u32(base, 0x572210u, ctx.xmm[0].u32[0]);
	// 0x2B4AB0: ret
	return;
}

void sub_2B4AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B4AC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B4AC8: movss [0x005721F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5721F8u, ctx.xmm[0].u32[0]);
	// 0x2B4AD0: ret
	return;
}

void sub_2B4AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B4AE0: movss xmm0, dword ptr [0x00572210]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572210u);
	// 0x2B4AE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B4AF0: movss [0x00572388], xmm0
	X86_MEM_WRITE_u32(base, 0x572388u, ctx.xmm[0].u32[0]);
	// 0x2B4AF8: ret
	return;
}

void sub_2B4B00(X86Context& ctx, uint8_t* base) {
	// 0x2B4B00: movss xmm0, dword ptr [0x005721F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721F8u);
	// 0x2B4B08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B4B10: movss [0x005722D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5722D0u, ctx.xmm[0].u32[0]);
	// 0x2B4B18: ret
	return;
}

void sub_2B4B20(X86Context& ctx, uint8_t* base) {
	// 0x2B4B20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B4B28: movss [0x00572398], xmm0
	X86_MEM_WRITE_u32(base, 0x572398u, ctx.xmm[0].u32[0]);
	// 0x2B4B30: ret
	return;
}

void sub_2B4B40(X86Context& ctx, uint8_t* base) {
	// 0x2B4B40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B4B48: movss [0x0057238C], xmm0
	X86_MEM_WRITE_u32(base, 0x57238Cu, ctx.xmm[0].u32[0]);
	// 0x2B4B50: ret
	return;
}

void sub_2B4B60(X86Context& ctx, uint8_t* base) {
	// 0x2B4B60: movss xmm0, dword ptr [0x0057238C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57238Cu);
	// 0x2B4B68: movss [0x00572394], xmm0
	X86_MEM_WRITE_u32(base, 0x572394u, ctx.xmm[0].u32[0]);
	// 0x2B4B70: ret
	return;
}

void sub_2B4B80(X86Context& ctx, uint8_t* base) {
	// 0x2B4B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B4B88: movss [0x005721F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5721F4u, ctx.xmm[0].u32[0]);
	// 0x2B4B90: ret
	return;
}

void sub_2B4BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B4BA0: movss xmm0, dword ptr [0x005721F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721F8u);
	// 0x2B4BA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B4BB0: movss [0x00572390], xmm0
	X86_MEM_WRITE_u32(base, 0x572390u, ctx.xmm[0].u32[0]);
	// 0x2B4BB8: ret
	return;
}

void sub_2B4BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B4BC0: movss xmm0, dword ptr [0x005721F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721F8u);
	// 0x2B4BC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B4BD0: movss [0x00572204], xmm0
	X86_MEM_WRITE_u32(base, 0x572204u, ctx.xmm[0].u32[0]);
	// 0x2B4BD8: ret
	return;
}

void sub_2B4BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B4BE0: movss xmm0, dword ptr [0x005721F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5721F8u);
	// 0x2B4BE8: subss xmm0, [0x00572204]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572204u);
	// 0x2B4BF0: movss [0x00572200], xmm0
	X86_MEM_WRITE_u32(base, 0x572200u, ctx.xmm[0].u32[0]);
	// 0x2B4BF8: ret
	return;
}

void sub_2B4C00(X86Context& ctx, uint8_t* base) {
	// 0x2B4C00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B4C08: movss [0x005722C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5722C8u, ctx.xmm[0].u32[0]);
	// 0x2B4C10: ret
	return;
}

void sub_2B4C20(X86Context& ctx, uint8_t* base) {
	// 0x2B4C20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B4C28: movss [0x005721FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5721FCu, ctx.xmm[0].u32[0]);
	// 0x2B4C30: ret
	return;
}

void sub_2B4C40(X86Context& ctx, uint8_t* base) {
	// 0x2B4C40: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B4C48: movss [0x00572420], xmm0
	X86_MEM_WRITE_u32(base, 0x572420u, ctx.xmm[0].u32[0]);
	// 0x2B4C50: ret
	return;
}

void sub_2B4C60(X86Context& ctx, uint8_t* base) {
	// 0x2B4C60: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B4C68: movss [0x00572434], xmm0
	X86_MEM_WRITE_u32(base, 0x572434u, ctx.xmm[0].u32[0]);
	// 0x2B4C70: ret
	return;
}

void sub_2B4C80(X86Context& ctx, uint8_t* base) {
	// 0x2B4C80: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B4C88: movss [0x00572408], xmm0
	X86_MEM_WRITE_u32(base, 0x572408u, ctx.xmm[0].u32[0]);
	// 0x2B4C90: ret
	return;
}

void sub_2B4CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B4CA0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B4CA8: movss [0x0057239C], xmm0
	X86_MEM_WRITE_u32(base, 0x57239Cu, ctx.xmm[0].u32[0]);
	// 0x2B4CB0: ret
	return;
}

void sub_2B4CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B4CC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B4CC8: movss [0x00572424], xmm0
	X86_MEM_WRITE_u32(base, 0x572424u, ctx.xmm[0].u32[0]);
	// 0x2B4CD0: ret
	return;
}

void sub_2B4CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B4CE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B4CE8: movss [0x005723A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5723A4u, ctx.xmm[0].u32[0]);
	// 0x2B4CF0: ret
	return;
}

void sub_2B4D00(X86Context& ctx, uint8_t* base) {
	// 0x2B4D00: movss xmm0, dword ptr [0x00572424]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572424u);
	// 0x2B4D08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B4D10: movss [0x00572450], xmm0
	X86_MEM_WRITE_u32(base, 0x572450u, ctx.xmm[0].u32[0]);
	// 0x2B4D18: ret
	return;
}

void sub_2B4D20(X86Context& ctx, uint8_t* base) {
	// 0x2B4D20: movss xmm0, dword ptr [0x005723A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5723A4u);
	// 0x2B4D28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B4D30: movss [0x00572448], xmm0
	X86_MEM_WRITE_u32(base, 0x572448u, ctx.xmm[0].u32[0]);
	// 0x2B4D38: ret
	return;
}

void sub_2B4D40(X86Context& ctx, uint8_t* base) {
	// 0x2B4D40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B4D48: movss [0x00572460], xmm0
	X86_MEM_WRITE_u32(base, 0x572460u, ctx.xmm[0].u32[0]);
	// 0x2B4D50: ret
	return;
}

void sub_2B4D60(X86Context& ctx, uint8_t* base) {
	// 0x2B4D60: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B4D68: movss [0x00572454], xmm0
	X86_MEM_WRITE_u32(base, 0x572454u, ctx.xmm[0].u32[0]);
	// 0x2B4D70: ret
	return;
}

void sub_2B4D80(X86Context& ctx, uint8_t* base) {
	// 0x2B4D80: movss xmm0, dword ptr [0x00572454]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572454u);
	// 0x2B4D88: movss [0x0057245C], xmm0
	X86_MEM_WRITE_u32(base, 0x57245Cu, ctx.xmm[0].u32[0]);
	// 0x2B4D90: ret
	return;
}

void sub_2B4DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B4DA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B4DA8: movss [0x005723A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5723A0u, ctx.xmm[0].u32[0]);
	// 0x2B4DB0: ret
	return;
}

void sub_2B4DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B4DC0: movss xmm0, dword ptr [0x005723A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5723A4u);
	// 0x2B4DC8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B4DD0: movss [0x00572458], xmm0
	X86_MEM_WRITE_u32(base, 0x572458u, ctx.xmm[0].u32[0]);
	// 0x2B4DD8: ret
	return;
}

void sub_2B4DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B4DE0: movss xmm0, dword ptr [0x005723A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5723A4u);
	// 0x2B4DE8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B4DF0: movss [0x005723F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5723F0u, ctx.xmm[0].u32[0]);
	// 0x2B4DF8: ret
	return;
}

void sub_2B4E00(X86Context& ctx, uint8_t* base) {
	// 0x2B4E00: movss xmm0, dword ptr [0x005723A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5723A4u);
	// 0x2B4E08: subss xmm0, [0x005723F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5723F0u);
	// 0x2B4E10: movss [0x005723D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5723D8u, ctx.xmm[0].u32[0]);
	// 0x2B4E18: ret
	return;
}

void sub_2B4E20(X86Context& ctx, uint8_t* base) {
	// 0x2B4E20: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B4E28: movss [0x00572430], xmm0
	X86_MEM_WRITE_u32(base, 0x572430u, ctx.xmm[0].u32[0]);
	// 0x2B4E30: ret
	return;
}

void sub_2B4E40(X86Context& ctx, uint8_t* base) {
	// 0x2B4E40: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B4E48: movss [0x005723B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5723B8u, ctx.xmm[0].u32[0]);
	// 0x2B4E50: ret
	return;
}

void sub_2B4E60(X86Context& ctx, uint8_t* base) {
	// 0x2B4E60: movss xmm0, dword ptr [0x003EBDA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3EBDA8u);
	// 0x2B4E68: movss [0x005723DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5723DCu, ctx.xmm[0].u32[0]);
	// 0x2B4E70: ret
	return;
}

void sub_2B4E80(X86Context& ctx, uint8_t* base) {
	// 0x2B4E80: movss xmm0, dword ptr [0x003EBDA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3EBDA4u);
	// 0x2B4E88: movss [0x0057244C], xmm0
	X86_MEM_WRITE_u32(base, 0x57244Cu, ctx.xmm[0].u32[0]);
	// 0x2B4E90: ret
	return;
}

void sub_2B4EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B4EA0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B4EA1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B4EA3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B4EA6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B4EA9: movss xmm0, dword ptr [0x003EBDAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3EBDACu);
	// 0x2B4EB1: movss xmm2, dword ptr [0x003B1C30]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B4EB9: movss xmm3, dword ptr [0x003B1C34]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B4EC1: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2B4EC4: addss xmm0, [0x003EBDA4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3EBDA4u);
	// 0x2B4ECC: mulss xmm1, xmm2
	ctx.xmm[1].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B4ED0: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x2B4ED5: movss xmm1, dword ptr [0x004A1D74]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x4A1D74u);
	// 0x2B4EDD: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B4EE0: movaps xmm4, xmm1
	ctx.xmm[4] = ctx.xmm[1];
	// 0x2B4EE3: addss xmm1, [0x003EBDA8]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x3EBDA8u);
	// 0x2B4EEB: mulss xmm4, xmm3
	ctx.xmm[4].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B4EEF: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B4EF3: mulss xmm1, xmm3
	ctx.xmm[1].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B4EF7: movss [esp+0x04], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[4].u32[0]);
	// 0x2B4EFD: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B4F01: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B4F07: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B4F0B: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B4F11: mov [0x005723F8], eax
	X86_MEM_WRITE_u32(base, 0x5723F8u, ctx.eax);
	// 0x2B4F16: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B4F1A: mov [0x005723FC], ecx
	X86_MEM_WRITE_u32(base, 0x5723FCu, ctx.ecx);
	// 0x2B4F20: mov [0x00572400], edx
	X86_MEM_WRITE_u32(base, 0x572400u, ctx.edx);
	// 0x2B4F26: mov [0x00572404], eax
	X86_MEM_WRITE_u32(base, 0x572404u, ctx.eax);
	// 0x2B4F2B: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B4F2D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B4F2E: ret
	return;
}

void sub_2B4F30(X86Context& ctx, uint8_t* base) {
	// 0x2B4F30: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B4F31: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B4F33: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B4F36: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B4F39: movss xmm1, dword ptr [0x003EBDAC]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3EBDACu);
	// 0x2B4F41: movss xmm2, dword ptr [0x003B1C30]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B4F49: movss xmm3, dword ptr [0x003B1C34]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B4F51: movaps xmm0, xmm1
	ctx.xmm[0] = ctx.xmm[1];
	// 0x2B4F54: addss xmm0, [0x003EBDA4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3EBDA4u);
	// 0x2B4F5C: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B4F60: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B4F65: movss xmm0, dword ptr [0x004A1D74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4A1D74u);
	// 0x2B4F6D: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B4F70: movaps xmm4, xmm0
	ctx.xmm[4] = ctx.xmm[0];
	// 0x2B4F73: addss xmm0, [0x003EBDA8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3EBDA8u);
	// 0x2B4F7B: mulss xmm4, xmm3
	ctx.xmm[4].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B4F7F: mulss xmm1, xmm2
	ctx.xmm[1].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B4F83: mulss xmm0, xmm3
	ctx.xmm[0].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B4F87: movss [esp+0x04], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[4].u32[0]);
	// 0x2B4F8D: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B4F91: movss [esp+0x08], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[1].u32[0]);
	// 0x2B4F97: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B4F9B: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B4FA1: mov [0x005723C0], eax
	X86_MEM_WRITE_u32(base, 0x5723C0u, ctx.eax);
	// 0x2B4FA6: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B4FAA: mov [0x005723C4], ecx
	X86_MEM_WRITE_u32(base, 0x5723C4u, ctx.ecx);
	// 0x2B4FB0: mov [0x005723C8], edx
	X86_MEM_WRITE_u32(base, 0x5723C8u, ctx.edx);
	// 0x2B4FB6: mov [0x005723CC], eax
	X86_MEM_WRITE_u32(base, 0x5723CCu, ctx.eax);
	// 0x2B4FBB: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B4FBD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B4FBE: ret
	return;
}

void sub_2B4FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B4FC0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B4FC1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B4FC3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B4FC6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B4FC9: movss xmm0, dword ptr [0x004A1D78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4A1D78u);
	// 0x2B4FD1: movss xmm2, dword ptr [0x003B1C30]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B4FD9: movss xmm3, dword ptr [0x003B1C34]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B4FE1: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2B4FE4: addss xmm0, [0x005723DC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x5723DCu);
	// 0x2B4FEC: mulss xmm1, xmm2
	ctx.xmm[1].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B4FF0: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x2B4FF5: movss xmm1, dword ptr [0x004A1D7C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x4A1D7Cu);
	// 0x2B4FFD: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B5000: movaps xmm4, xmm1
	ctx.xmm[4] = ctx.xmm[1];
	// 0x2B5003: addss xmm4, [0x0057244C]
	ctx.xmm[4].f32[0] += X86_MEM_READ_F32(base, 0x57244Cu);
	// 0x2B500B: mulss xmm4, xmm3
	ctx.xmm[4].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B500F: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B5013: mulss xmm1, xmm3
	ctx.xmm[1].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B5017: movss [esp+0x04], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[4].u32[0]);
	// 0x2B501D: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B5021: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B5027: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B502B: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B5031: mov [0x005723A8], eax
	X86_MEM_WRITE_u32(base, 0x5723A8u, ctx.eax);
	// 0x2B5036: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B503A: mov [0x005723AC], ecx
	X86_MEM_WRITE_u32(base, 0x5723ACu, ctx.ecx);
	// 0x2B5040: mov [0x005723B0], edx
	X86_MEM_WRITE_u32(base, 0x5723B0u, ctx.edx);
	// 0x2B5046: mov [0x005723B4], eax
	X86_MEM_WRITE_u32(base, 0x5723B4u, ctx.eax);
	// 0x2B504B: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B504D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B504E: ret
	return;
}

void sub_2B5050(X86Context& ctx, uint8_t* base) {
	// 0x2B5050: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B5051: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B5053: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B5056: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B5059: movss xmm0, dword ptr [0x004A1D78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4A1D78u);
	// 0x2B5061: movss xmm2, dword ptr [0x003B1C30]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B5069: movss xmm3, dword ptr [0x003B1C34]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B5071: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2B5074: addss xmm0, [0x005723DC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x5723DCu);
	// 0x2B507C: mulss xmm1, xmm2
	ctx.xmm[1].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B5080: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x2B5085: movss xmm1, dword ptr [0x004A1D7C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x4A1D7Cu);
	// 0x2B508D: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B5090: movaps xmm4, xmm1
	ctx.xmm[4] = ctx.xmm[1];
	// 0x2B5093: addss xmm1, [0x0057244C]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x57244Cu);
	// 0x2B509B: mulss xmm4, xmm3
	ctx.xmm[4].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B509F: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B50A3: mulss xmm1, xmm3
	ctx.xmm[1].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B50A7: movss [esp+0x04], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[4].u32[0]);
	// 0x2B50AD: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B50B1: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B50B7: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B50BB: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B50C1: mov [0x00572410], eax
	X86_MEM_WRITE_u32(base, 0x572410u, ctx.eax);
	// 0x2B50C6: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B50CA: mov [0x00572414], ecx
	X86_MEM_WRITE_u32(base, 0x572414u, ctx.ecx);
	// 0x2B50D0: mov [0x00572418], edx
	X86_MEM_WRITE_u32(base, 0x572418u, ctx.edx);
	// 0x2B50D6: mov [0x0057241C], eax
	X86_MEM_WRITE_u32(base, 0x57241Cu, ctx.eax);
	// 0x2B50DB: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B50DD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B50DE: ret
	return;
}

void sub_2B50E0(X86Context& ctx, uint8_t* base) {
	// 0x2B50E0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B50E8: movss [0x00572428], xmm0
	X86_MEM_WRITE_u32(base, 0x572428u, ctx.xmm[0].u32[0]);
	// 0x2B50F0: ret
	return;
}

void sub_2B5100(X86Context& ctx, uint8_t* base) {
	// 0x2B5100: movss xmm0, dword ptr [0x00572428]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572428u);
	// 0x2B5108: subss xmm0, [0x003EBDA4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3EBDA4u);
	// 0x2B5110: movss [0x0057242C], xmm0
	X86_MEM_WRITE_u32(base, 0x57242Cu, ctx.xmm[0].u32[0]);
	// 0x2B5118: ret
	return;
}

void sub_2B5120(X86Context& ctx, uint8_t* base) {
	// 0x2B5120: movss xmm0, dword ptr [0x0057242C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57242Cu);
	// 0x2B5128: divss xmm0, [0x00572428]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x572428u);
	// 0x2B5130: movss [0x005723E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5723E0u, ctx.xmm[0].u32[0]);
	// 0x2B5138: ret
	return;
}

