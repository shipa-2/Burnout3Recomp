#include "x86_recomp_shared.h"

void sub_26B000(X86Context& ctx, uint8_t* base) {
	// 0x26B000: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26B008: movss [0x0056714C], xmm0
	X86_MEM_WRITE_u32(base, 0x56714Cu, ctx.xmm[0].u32[0]);
	// 0x26B010: ret
	return;
}

void sub_26B020(X86Context& ctx, uint8_t* base) {
	// 0x26B020: movss xmm0, dword ptr [0x0056714C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56714Cu);
	// 0x26B028: movss [0x00567154], xmm0
	X86_MEM_WRITE_u32(base, 0x567154u, ctx.xmm[0].u32[0]);
	// 0x26B030: ret
	return;
}

void sub_26B040(X86Context& ctx, uint8_t* base) {
	// 0x26B040: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26B048: movss [0x0056711C], xmm0
	X86_MEM_WRITE_u32(base, 0x56711Cu, ctx.xmm[0].u32[0]);
	// 0x26B050: ret
	return;
}

void sub_26B060(X86Context& ctx, uint8_t* base) {
	// 0x26B060: movss xmm0, dword ptr [0x00567120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567120u);
	// 0x26B068: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26B070: movss [0x00567150], xmm0
	X86_MEM_WRITE_u32(base, 0x567150u, ctx.xmm[0].u32[0]);
	// 0x26B078: ret
	return;
}

void sub_26B080(X86Context& ctx, uint8_t* base) {
	// 0x26B080: movss xmm0, dword ptr [0x00567120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567120u);
	// 0x26B088: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26B090: movss [0x0056712C], xmm0
	X86_MEM_WRITE_u32(base, 0x56712Cu, ctx.xmm[0].u32[0]);
	// 0x26B098: ret
	return;
}

void sub_26B0A0(X86Context& ctx, uint8_t* base) {
	// 0x26B0A0: movss xmm0, dword ptr [0x00567120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567120u);
	// 0x26B0A8: subss xmm0, [0x0056712C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56712Cu);
	// 0x26B0B0: movss [0x00567128], xmm0
	X86_MEM_WRITE_u32(base, 0x567128u, ctx.xmm[0].u32[0]);
	// 0x26B0B8: ret
	return;
}

void sub_26B0C0(X86Context& ctx, uint8_t* base) {
	// 0x26B0C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26B0C8: movss [0x0056713C], xmm0
	X86_MEM_WRITE_u32(base, 0x56713Cu, ctx.xmm[0].u32[0]);
	// 0x26B0D0: ret
	return;
}

void sub_26B0E0(X86Context& ctx, uint8_t* base) {
	// 0x26B0E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26B0E8: movss [0x00567124], xmm0
	X86_MEM_WRITE_u32(base, 0x567124u, ctx.xmm[0].u32[0]);
	// 0x26B0F0: ret
	return;
}

void sub_26B100(X86Context& ctx, uint8_t* base) {
	// 0x26B100: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26B108: movss [0x00567AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x567AE8u, ctx.xmm[0].u32[0]);
	// 0x26B110: ret
	return;
}

void sub_26B120(X86Context& ctx, uint8_t* base) {
	// 0x26B120: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26B128: movss [0x00567AF4], xmm0
	X86_MEM_WRITE_u32(base, 0x567AF4u, ctx.xmm[0].u32[0]);
	// 0x26B130: ret
	return;
}

void sub_26B140(X86Context& ctx, uint8_t* base) {
	// 0x26B140: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26B148: movss [0x00567AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x567AE4u, ctx.xmm[0].u32[0]);
	// 0x26B150: ret
	return;
}

void sub_26B160(X86Context& ctx, uint8_t* base) {
	// 0x26B160: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26B168: movss [0x0056715C], xmm0
	X86_MEM_WRITE_u32(base, 0x56715Cu, ctx.xmm[0].u32[0]);
	// 0x26B170: ret
	return;
}

void sub_26B180(X86Context& ctx, uint8_t* base) {
	// 0x26B180: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26B188: movss [0x00567AEC], xmm0
	X86_MEM_WRITE_u32(base, 0x567AECu, ctx.xmm[0].u32[0]);
	// 0x26B190: ret
	return;
}

void sub_26B1A0(X86Context& ctx, uint8_t* base) {
	// 0x26B1A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26B1A8: movss [0x00567164], xmm0
	X86_MEM_WRITE_u32(base, 0x567164u, ctx.xmm[0].u32[0]);
	// 0x26B1B0: ret
	return;
}

void sub_26B1C0(X86Context& ctx, uint8_t* base) {
	// 0x26B1C0: movss xmm0, dword ptr [0x00567AEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567AECu);
	// 0x26B1C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26B1D0: movss [0x00567AFC], xmm0
	X86_MEM_WRITE_u32(base, 0x567AFCu, ctx.xmm[0].u32[0]);
	// 0x26B1D8: ret
	return;
}

void sub_26B1E0(X86Context& ctx, uint8_t* base) {
	// 0x26B1E0: movss xmm0, dword ptr [0x00567164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567164u);
	// 0x26B1E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26B1F0: movss [0x00567AF8], xmm0
	X86_MEM_WRITE_u32(base, 0x567AF8u, ctx.xmm[0].u32[0]);
	// 0x26B1F8: ret
	return;
}

void sub_26B200(X86Context& ctx, uint8_t* base) {
	// 0x26B200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26B208: movss [0x00567B0C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B0Cu, ctx.xmm[0].u32[0]);
	// 0x26B210: ret
	return;
}

void sub_26B220(X86Context& ctx, uint8_t* base) {
	// 0x26B220: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26B228: movss [0x00567B00], xmm0
	X86_MEM_WRITE_u32(base, 0x567B00u, ctx.xmm[0].u32[0]);
	// 0x26B230: ret
	return;
}

void sub_26B240(X86Context& ctx, uint8_t* base) {
	// 0x26B240: movss xmm0, dword ptr [0x00567B00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B00u);
	// 0x26B248: movss [0x00567B08], xmm0
	X86_MEM_WRITE_u32(base, 0x567B08u, ctx.xmm[0].u32[0]);
	// 0x26B250: ret
	return;
}

void sub_26B260(X86Context& ctx, uint8_t* base) {
	// 0x26B260: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26B268: movss [0x00567160], xmm0
	X86_MEM_WRITE_u32(base, 0x567160u, ctx.xmm[0].u32[0]);
	// 0x26B270: ret
	return;
}

void sub_26B280(X86Context& ctx, uint8_t* base) {
	// 0x26B280: movss xmm0, dword ptr [0x00567164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567164u);
	// 0x26B288: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26B290: movss [0x00567B04], xmm0
	X86_MEM_WRITE_u32(base, 0x567B04u, ctx.xmm[0].u32[0]);
	// 0x26B298: ret
	return;
}

void sub_26B2A0(X86Context& ctx, uint8_t* base) {
	// 0x26B2A0: movss xmm0, dword ptr [0x00567164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567164u);
	// 0x26B2A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26B2B0: movss [0x00567AE0], xmm0
	X86_MEM_WRITE_u32(base, 0x567AE0u, ctx.xmm[0].u32[0]);
	// 0x26B2B8: ret
	return;
}

void sub_26B2C0(X86Context& ctx, uint8_t* base) {
	// 0x26B2C0: movss xmm0, dword ptr [0x00567164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567164u);
	// 0x26B2C8: subss xmm0, [0x00567AE0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567AE0u);
	// 0x26B2D0: movss [0x0056716C], xmm0
	X86_MEM_WRITE_u32(base, 0x56716Cu, ctx.xmm[0].u32[0]);
	// 0x26B2D8: ret
	return;
}

void sub_26B2E0(X86Context& ctx, uint8_t* base) {
	// 0x26B2E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26B2E8: movss [0x00567AF0], xmm0
	X86_MEM_WRITE_u32(base, 0x567AF0u, ctx.xmm[0].u32[0]);
	// 0x26B2F0: ret
	return;
}

void sub_26B300(X86Context& ctx, uint8_t* base) {
	// 0x26B300: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26B308: movss [0x00567168], xmm0
	X86_MEM_WRITE_u32(base, 0x567168u, ctx.xmm[0].u32[0]);
	// 0x26B310: ret
	return;
}

void sub_26B320(X86Context& ctx, uint8_t* base) {
	// 0x26B320: mov eax, 0x567170
	ctx.eax = 5665136;
	// 0x26B325: jmp 0x00064230
	goto loc_64230;
	// ---- chunk at 0x64230 (size 0x23B) ----
loc_64230:
	// 0x64230: mov dword ptr [eax], 0x3AC188
	X86_MEM_WRITE_u32(base, ctx.eax, 3850632);
	// 0x64236: mov dword ptr [eax+0x18], 0x3AC160
	X86_MEM_WRITE_u32(base, ctx.eax + 0x18u, 3850592);
	// 0x6423D: mov dword ptr [eax+0x30], 0x3AC148
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, 3850568);
	// 0x64244: mov dword ptr [eax+0x90], 0x3AC118
	X86_MEM_WRITE_u32(base, ctx.eax + 0x90u, 3850520);
	// 0x6424E: mov dword ptr [eax+0xA8], 0x3AC100
	X86_MEM_WRITE_u32(base, ctx.eax + 0xA8u, 3850496);
	// 0x64258: mov dword ptr [eax+0xC0], 0x3AC12C
	X86_MEM_WRITE_u32(base, ctx.eax + 0xC0u, 3850540);
	// 0x64262: mov dword ptr [eax+0xE0], 0x3AC1F0
	X86_MEM_WRITE_u32(base, ctx.eax + 0xE0u, 3850736);
	// 0x6426C: mov dword ptr [eax+0x100], 0x3AC1D4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x100u, 3850708);
	// 0x64276: mov dword ptr [eax+0x120], 0x3AC1B8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x120u, 3850680);
	// 0x64280: mov dword ptr [eax+0x138], 0x3AC178
	X86_MEM_WRITE_u32(base, ctx.eax + 0x138u, 3850616);
	// 0x6428A: mov dword ptr [eax+0x158], 0x3AC16C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x158u, 3850604);
	// 0x64294: mov dword ptr [eax+0x178], 0x3AC150
	X86_MEM_WRITE_u32(base, ctx.eax + 0x178u, 3850576);
	// 0x6429E: mov dword ptr [eax+0x1A8], 0x3AC13C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1A8u, 3850556);
	// 0x642A8: mov dword ptr [eax+0x1C8], 0x3AC124
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1C8u, 3850532);
	// 0x642B2: mov dword ptr [eax+0x1E0], 0x3AC110
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1E0u, 3850512);
	// 0x642BC: mov dword ptr [eax+0x1F8], 0x3AC1FC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1F8u, 3850748);
	// 0x642C6: mov dword ptr [eax+0x210], 0x3AC1E8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x210u, 3850728);
	// 0x642D0: mov dword ptr [eax+0x228], 0x3AC1D8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x228u, 3850712);
	// 0x642DA: mov dword ptr [eax+0x240], 0x3AC1C4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x240u, 3850692);
	// 0x642E4: mov dword ptr [eax+0x260], 0x3AC15C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x260u, 3850588);
	// 0x642EE: mov dword ptr [eax+0x290], 0x3AC11C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x290u, 3850524);
	// 0x642F8: mov dword ptr [eax+0x2B0], 0x3AC104
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2B0u, 3850500);
	// 0x64302: mov dword ptr [eax+0x2C8], 0x3AC1F4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2C8u, 3850740);
	// 0x6430C: mov dword ptr [eax+0x2E8], 0x3AC1D0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2E8u, 3850704);
	// 0x64316: mov dword ptr [eax+0x300], 0x3AC1BC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x300u, 3850684);
	// 0x64320: mov dword ptr [eax+0x318], 0x3AC138
	X86_MEM_WRITE_u32(base, ctx.eax + 0x318u, 3850552);
	// 0x6432A: mov dword ptr [eax+0x338], 0x3AC114
	X86_MEM_WRITE_u32(base, ctx.eax + 0x338u, 3850516);
	// 0x64334: mov dword ptr [eax+0x350], 0x3AC200
	X86_MEM_WRITE_u32(base, ctx.eax + 0x350u, 3850752);
	// 0x6433E: mov dword ptr [eax+0x368], 0x3AC1EC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x368u, 3850732);
	// 0x64348: mov dword ptr [eax+0x380], 0x3AC1DC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x380u, 3850716);
	// 0x64352: mov dword ptr [eax+0x398], 0x3AC1C0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x398u, 3850688);
	// 0x6435C: mov dword ptr [eax+0x3B0], 0x3AC134
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3B0u, 3850548);
	// 0x64366: mov dword ptr [eax+0x3C8], 0x3AC1AC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3C8u, 3850668);
	// 0x64370: mov dword ptr [eax+0x3E0], 0x3AC184
	X86_MEM_WRITE_u32(base, ctx.eax + 0x3E0u, 3850628);
	// 0x6437A: mov dword ptr [eax+0x400], 0x3AC174
	X86_MEM_WRITE_u32(base, ctx.eax + 0x400u, 3850612);
	// 0x64384: mov dword ptr [eax+0x460], 0x3AC168
	X86_MEM_WRITE_u32(base, ctx.eax + 0x460u, 3850600);
	// 0x6438E: mov dword ptr [eax+0x478], 0x3AC158
	X86_MEM_WRITE_u32(base, ctx.eax + 0x478u, 3850584);
	// 0x64398: mov dword ptr [eax+0x490], 0x3AC140
	X86_MEM_WRITE_u32(base, ctx.eax + 0x490u, 3850560);
	// 0x643A2: mov dword ptr [eax+0x4B8], 0x3AC120
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4B8u, 3850528);
	// 0x643AC: mov dword ptr [eax+0x4D8], 0x3AC10C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4D8u, 3850508);
	// 0x643B6: mov dword ptr [eax+0x4F0], 0x3AC1F8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4F0u, 3850744);
	// 0x643C0: mov dword ptr [eax+0x508], 0x3AC1E0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x508u, 3850720);
	// 0x643CA: mov dword ptr [eax+0x528], 0x3AC1C8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x528u, 3850696);
	// 0x643D4: mov dword ptr [eax+0x548], 0x3AC1B4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x548u, 3850676);
	// 0x643DE: mov dword ptr [eax+0x568], 0x3AC1A4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x568u, 3850660);
	// 0x643E8: mov dword ptr [eax+0x590], 0x3AC1E4
	X86_MEM_WRITE_u32(base, ctx.eax + 0x590u, 3850724);
	// 0x643F2: mov dword ptr [eax+0x5B0], 0x3AC164
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5B0u, 3850596);
	// 0x643FC: mov dword ptr [eax+0x5D0], 0x3AC1A8
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5D0u, 3850664);
	// 0x64406: mov dword ptr [eax+0x5F0], 0x3AC144
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5F0u, 3850564);
	// 0x64410: mov dword ptr [eax+0x610], 0x3AC17C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x610u, 3850620);
	// 0x6441A: mov dword ptr [eax+0x630], 0x3AC170
	X86_MEM_WRITE_u32(base, ctx.eax + 0x630u, 3850608);
	// 0x64424: mov dword ptr [eax+0x6C0], 0x3AC128
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6C0u, 3850536);
	// 0x6442E: mov dword ptr [eax+0x6D8], 0x3AC108
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6D8u, 3850504);
	// 0x64438: mov dword ptr [eax+0x6F8], 0x3AC1CC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6F8u, 3850700);
	// 0x64442: mov dword ptr [eax+0x808], 0x3AC180
	X86_MEM_WRITE_u32(base, ctx.eax + 0x808u, 3850624);
	// 0x6444C: mov dword ptr [eax+0x830], 0x3AC154
	X86_MEM_WRITE_u32(base, ctx.eax + 0x830u, 3850580);
	// 0x64456: mov dword ptr [eax+0x928], 0x3AC130
	X86_MEM_WRITE_u32(base, ctx.eax + 0x928u, 3850544);
	// 0x64460: mov dword ptr [eax+0x948], 0x3AC1B0
	X86_MEM_WRITE_u32(base, ctx.eax + 0x948u, 3850672);
	// 0x6446A: ret
	return;
}

void sub_26B330(X86Context& ctx, uint8_t* base) {
	// 0x26B330: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26B338: movss [0x00567B6C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B6Cu, ctx.xmm[0].u32[0]);
	// 0x26B340: ret
	return;
}

void sub_26B350(X86Context& ctx, uint8_t* base) {
	// 0x26B350: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26B358: movss [0x00567B88], xmm0
	X86_MEM_WRITE_u32(base, 0x567B88u, ctx.xmm[0].u32[0]);
	// 0x26B360: ret
	return;
}

void sub_26B370(X86Context& ctx, uint8_t* base) {
	// 0x26B370: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26B378: movss [0x00567B5C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B5Cu, ctx.xmm[0].u32[0]);
	// 0x26B380: ret
	return;
}

void sub_26B390(X86Context& ctx, uint8_t* base) {
	// 0x26B390: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26B398: movss [0x00567B10], xmm0
	X86_MEM_WRITE_u32(base, 0x567B10u, ctx.xmm[0].u32[0]);
	// 0x26B3A0: ret
	return;
}

void sub_26B3B0(X86Context& ctx, uint8_t* base) {
	// 0x26B3B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26B3B8: movss [0x00567B70], xmm0
	X86_MEM_WRITE_u32(base, 0x567B70u, ctx.xmm[0].u32[0]);
	// 0x26B3C0: ret
	return;
}

void sub_26B3D0(X86Context& ctx, uint8_t* base) {
	// 0x26B3D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26B3D8: movss [0x00567B2C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B2Cu, ctx.xmm[0].u32[0]);
	// 0x26B3E0: ret
	return;
}

void sub_26B3F0(X86Context& ctx, uint8_t* base) {
	// 0x26B3F0: movss xmm0, dword ptr [0x00567B70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B70u);
	// 0x26B3F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26B400: movss [0x00567BA8], xmm0
	X86_MEM_WRITE_u32(base, 0x567BA8u, ctx.xmm[0].u32[0]);
	// 0x26B408: ret
	return;
}

void sub_26B410(X86Context& ctx, uint8_t* base) {
	// 0x26B410: movss xmm0, dword ptr [0x00567B2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B2Cu);
	// 0x26B418: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26B420: movss [0x00567B90], xmm0
	X86_MEM_WRITE_u32(base, 0x567B90u, ctx.xmm[0].u32[0]);
	// 0x26B428: ret
	return;
}

void sub_26B430(X86Context& ctx, uint8_t* base) {
	// 0x26B430: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26B438: movss [0x00567BC0], xmm0
	X86_MEM_WRITE_u32(base, 0x567BC0u, ctx.xmm[0].u32[0]);
	// 0x26B440: ret
	return;
}

void sub_26B450(X86Context& ctx, uint8_t* base) {
	// 0x26B450: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26B458: movss [0x00567BAC], xmm0
	X86_MEM_WRITE_u32(base, 0x567BACu, ctx.xmm[0].u32[0]);
	// 0x26B460: ret
	return;
}

void sub_26B470(X86Context& ctx, uint8_t* base) {
	// 0x26B470: movss xmm0, dword ptr [0x00567BAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BACu);
	// 0x26B478: movss [0x00567BBC], xmm0
	X86_MEM_WRITE_u32(base, 0x567BBCu, ctx.xmm[0].u32[0]);
	// 0x26B480: ret
	return;
}

void sub_26B490(X86Context& ctx, uint8_t* base) {
	// 0x26B490: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26B498: movss [0x00567B18], xmm0
	X86_MEM_WRITE_u32(base, 0x567B18u, ctx.xmm[0].u32[0]);
	// 0x26B4A0: ret
	return;
}

void sub_26B4B0(X86Context& ctx, uint8_t* base) {
	// 0x26B4B0: movss xmm0, dword ptr [0x00567B2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B2Cu);
	// 0x26B4B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26B4C0: movss [0x00567BB4], xmm0
	X86_MEM_WRITE_u32(base, 0x567BB4u, ctx.xmm[0].u32[0]);
	// 0x26B4C8: ret
	return;
}

void sub_26B4D0(X86Context& ctx, uint8_t* base) {
	// 0x26B4D0: movss xmm0, dword ptr [0x00567B2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B2Cu);
	// 0x26B4D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26B4E0: movss [0x00567B58], xmm0
	X86_MEM_WRITE_u32(base, 0x567B58u, ctx.xmm[0].u32[0]);
	// 0x26B4E8: ret
	return;
}

void sub_26B4F0(X86Context& ctx, uint8_t* base) {
	// 0x26B4F0: movss xmm0, dword ptr [0x00567B2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B2Cu);
	// 0x26B4F8: subss xmm0, [0x00567B58]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567B58u);
	// 0x26B500: movss [0x00567B34], xmm0
	X86_MEM_WRITE_u32(base, 0x567B34u, ctx.xmm[0].u32[0]);
	// 0x26B508: ret
	return;
}

void sub_26B510(X86Context& ctx, uint8_t* base) {
	// 0x26B510: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26B518: movss [0x00567B84], xmm0
	X86_MEM_WRITE_u32(base, 0x567B84u, ctx.xmm[0].u32[0]);
	// 0x26B520: ret
	return;
}

void sub_26B530(X86Context& ctx, uint8_t* base) {
	// 0x26B530: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26B538: movss [0x00567B30], xmm0
	X86_MEM_WRITE_u32(base, 0x567B30u, ctx.xmm[0].u32[0]);
	// 0x26B540: ret
	return;
}

void sub_26B550(X86Context& ctx, uint8_t* base) {
	// 0x26B550: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26B558: movss [0x00567B44], xmm0
	X86_MEM_WRITE_u32(base, 0x567B44u, ctx.xmm[0].u32[0]);
	// 0x26B560: ret
	return;
}

void sub_26B570(X86Context& ctx, uint8_t* base) {
	// 0x26B570: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26B578: movss [0x00567B9C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B9Cu, ctx.xmm[0].u32[0]);
	// 0x26B580: ret
	return;
}

void sub_26B590(X86Context& ctx, uint8_t* base) {
	// 0x26B590: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26B598: movss [0x00567B80], xmm0
	X86_MEM_WRITE_u32(base, 0x567B80u, ctx.xmm[0].u32[0]);
	// 0x26B5A0: ret
	return;
}

void sub_26B5B0(X86Context& ctx, uint8_t* base) {
	// 0x26B5B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26B5B8: movss [0x00567B28], xmm0
	X86_MEM_WRITE_u32(base, 0x567B28u, ctx.xmm[0].u32[0]);
	// 0x26B5C0: ret
	return;
}

void sub_26B5D0(X86Context& ctx, uint8_t* base) {
	// 0x26B5D0: movss xmm0, dword ptr [0x00567B44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B44u);
	// 0x26B5D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26B5E0: movss [0x00567B1C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B1Cu, ctx.xmm[0].u32[0]);
	// 0x26B5E8: ret
	return;
}

void sub_26B5F0(X86Context& ctx, uint8_t* base) {
	// 0x26B5F0: movss xmm0, dword ptr [0x00567B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B9Cu);
	// 0x26B5F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26B600: movss [0x00567B64], xmm0
	X86_MEM_WRITE_u32(base, 0x567B64u, ctx.xmm[0].u32[0]);
	// 0x26B608: ret
	return;
}

void sub_26B610(X86Context& ctx, uint8_t* base) {
	// 0x26B610: movss xmm0, dword ptr [0x00567B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B1Cu);
	// 0x26B618: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26B620: movss [0x00567B78], xmm0
	X86_MEM_WRITE_u32(base, 0x567B78u, ctx.xmm[0].u32[0]);
	// 0x26B628: ret
	return;
}

void sub_26B630(X86Context& ctx, uint8_t* base) {
	// 0x26B630: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26B638: movss [0x00567B14], xmm0
	X86_MEM_WRITE_u32(base, 0x567B14u, ctx.xmm[0].u32[0]);
	// 0x26B640: ret
	return;
}

void sub_26B650(X86Context& ctx, uint8_t* base) {
	// 0x26B650: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26B658: movss [0x00567B48], xmm0
	X86_MEM_WRITE_u32(base, 0x567B48u, ctx.xmm[0].u32[0]);
	// 0x26B660: ret
	return;
}

void sub_26B670(X86Context& ctx, uint8_t* base) {
	// 0x26B670: movss xmm0, dword ptr [0x00567B44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B44u);
	// 0x26B678: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26B680: movss [0x00567B54], xmm0
	X86_MEM_WRITE_u32(base, 0x567B54u, ctx.xmm[0].u32[0]);
	// 0x26B688: ret
	return;
}

void sub_26B690(X86Context& ctx, uint8_t* base) {
	// 0x26B690: movss xmm0, dword ptr [0x00567B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B9Cu);
	// 0x26B698: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26B6A0: movss [0x00567BA0], xmm0
	X86_MEM_WRITE_u32(base, 0x567BA0u, ctx.xmm[0].u32[0]);
	// 0x26B6A8: ret
	return;
}

void sub_26B6B0(X86Context& ctx, uint8_t* base) {
	// 0x26B6B0: movss xmm0, dword ptr [0x00567B54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B54u);
	// 0x26B6B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26B6C0: movss [0x00567B8C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B8Cu, ctx.xmm[0].u32[0]);
	// 0x26B6C8: ret
	return;
}

void sub_26B6D0(X86Context& ctx, uint8_t* base) {
	// 0x26B6D0: movss xmm0, dword ptr [0x00567BA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BA0u);
	// 0x26B6D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26B6E0: movss [0x00567BB0], xmm0
	X86_MEM_WRITE_u32(base, 0x567BB0u, ctx.xmm[0].u32[0]);
	// 0x26B6E8: ret
	return;
}

void sub_26B6F0(X86Context& ctx, uint8_t* base) {
	// 0x26B6F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26B6F8: movss [0x00567B20], xmm0
	X86_MEM_WRITE_u32(base, 0x567B20u, ctx.xmm[0].u32[0]);
	// 0x26B700: ret
	return;
}

void sub_26B710(X86Context& ctx, uint8_t* base) {
	// 0x26B710: movss xmm0, dword ptr [0x00567B44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B44u);
	// 0x26B718: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26B720: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26B728: movss [0x00567B98], xmm0
	X86_MEM_WRITE_u32(base, 0x567B98u, ctx.xmm[0].u32[0]);
	// 0x26B730: ret
	return;
}

void sub_26B740(X86Context& ctx, uint8_t* base) {
	// 0x26B740: movss xmm0, dword ptr [0x00567B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B9Cu);
	// 0x26B748: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26B750: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26B758: movss [0x00567B38], xmm0
	X86_MEM_WRITE_u32(base, 0x567B38u, ctx.xmm[0].u32[0]);
	// 0x26B760: ret
	return;
}

void sub_26B770(X86Context& ctx, uint8_t* base) {
	// 0x26B770: movss xmm0, dword ptr [0x00567B44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B44u);
	// 0x26B778: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26B780: movss [0x00567B3C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B3Cu, ctx.xmm[0].u32[0]);
	// 0x26B788: ret
	return;
}

void sub_26B790(X86Context& ctx, uint8_t* base) {
	// 0x26B790: movss xmm0, dword ptr [0x00567B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B9Cu);
	// 0x26B798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26B7A0: movss [0x00567BA4], xmm0
	X86_MEM_WRITE_u32(base, 0x567BA4u, ctx.xmm[0].u32[0]);
	// 0x26B7A8: ret
	return;
}

void sub_26B7B0(X86Context& ctx, uint8_t* base) {
	// 0x26B7B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26B7B8: movss [0x00567B24], xmm0
	X86_MEM_WRITE_u32(base, 0x567B24u, ctx.xmm[0].u32[0]);
	// 0x26B7C0: ret
	return;
}

void sub_26B7D0(X86Context& ctx, uint8_t* base) {
	// 0x26B7D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26B7D8: movss [0x00567B50], xmm0
	X86_MEM_WRITE_u32(base, 0x567B50u, ctx.xmm[0].u32[0]);
	// 0x26B7E0: ret
	return;
}

void sub_26B7F0(X86Context& ctx, uint8_t* base) {
	// 0x26B7F0: movss xmm0, dword ptr [0x00567B24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B24u);
	// 0x26B7F8: movss [0x00567BB8], xmm0
	X86_MEM_WRITE_u32(base, 0x567BB8u, ctx.xmm[0].u32[0]);
	// 0x26B800: ret
	return;
}

void sub_26B810(X86Context& ctx, uint8_t* base) {
	// 0x26B810: movss xmm0, dword ptr [0x00567B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B9Cu);
	// 0x26B818: subss xmm0, [0x00567B24]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567B24u);
	// 0x26B820: movss [0x00567B7C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B7Cu, ctx.xmm[0].u32[0]);
	// 0x26B828: ret
	return;
}

void sub_26B830(X86Context& ctx, uint8_t* base) {
	// 0x26B830: movss xmm0, dword ptr [0x00567B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B7Cu);
	// 0x26B838: subss xmm0, [0x00567B50]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567B50u);
	// 0x26B840: movss [0x00567B74], xmm0
	X86_MEM_WRITE_u32(base, 0x567B74u, ctx.xmm[0].u32[0]);
	// 0x26B848: ret
	return;
}

void sub_26B850(X86Context& ctx, uint8_t* base) {
	// 0x26B850: movss xmm0, dword ptr [0x00567BA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BA4u);
	// 0x26B858: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26B860: movss [0x00567B60], xmm0
	X86_MEM_WRITE_u32(base, 0x567B60u, ctx.xmm[0].u32[0]);
	// 0x26B868: ret
	return;
}

void sub_26B870(X86Context& ctx, uint8_t* base) {
	// 0x26B870: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26B878: movss [0x00567B4C], xmm0
	X86_MEM_WRITE_u32(base, 0x567B4Cu, ctx.xmm[0].u32[0]);
	// 0x26B880: ret
	return;
}

void sub_26B890(X86Context& ctx, uint8_t* base) {
	// 0x26B890: movss xmm0, dword ptr [0x00567B60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567B60u);
	// 0x26B898: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26B8A0: movss [0x00567B94], xmm0
	X86_MEM_WRITE_u32(base, 0x567B94u, ctx.xmm[0].u32[0]);
	// 0x26B8A8: ret
	return;
}

void sub_26B8B0(X86Context& ctx, uint8_t* base) {
	// 0x26B8B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26B8B8: movss [0x00567B68], xmm0
	X86_MEM_WRITE_u32(base, 0x567B68u, ctx.xmm[0].u32[0]);
	// 0x26B8C0: ret
	return;
}

void sub_26B8D0(X86Context& ctx, uint8_t* base) {
	// 0x26B8D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26B8D8: movss [0x00567B40], xmm0
	X86_MEM_WRITE_u32(base, 0x567B40u, ctx.xmm[0].u32[0]);
	// 0x26B8E0: ret
	return;
}

void sub_26B8F0(X86Context& ctx, uint8_t* base) {
	// 0x26B8F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26B8F8: movss [0x00567C20], xmm0
	X86_MEM_WRITE_u32(base, 0x567C20u, ctx.xmm[0].u32[0]);
	// 0x26B900: ret
	return;
}

void sub_26B910(X86Context& ctx, uint8_t* base) {
	// 0x26B910: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26B918: movss [0x00567C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C3Cu, ctx.xmm[0].u32[0]);
	// 0x26B920: ret
	return;
}

void sub_26B930(X86Context& ctx, uint8_t* base) {
	// 0x26B930: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26B938: movss [0x00567C10], xmm0
	X86_MEM_WRITE_u32(base, 0x567C10u, ctx.xmm[0].u32[0]);
	// 0x26B940: ret
	return;
}

void sub_26B950(X86Context& ctx, uint8_t* base) {
	// 0x26B950: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26B958: movss [0x00567BC4], xmm0
	X86_MEM_WRITE_u32(base, 0x567BC4u, ctx.xmm[0].u32[0]);
	// 0x26B960: ret
	return;
}

void sub_26B970(X86Context& ctx, uint8_t* base) {
	// 0x26B970: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26B978: movss [0x00567C24], xmm0
	X86_MEM_WRITE_u32(base, 0x567C24u, ctx.xmm[0].u32[0]);
	// 0x26B980: ret
	return;
}

void sub_26B990(X86Context& ctx, uint8_t* base) {
	// 0x26B990: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26B998: movss [0x00567BE0], xmm0
	X86_MEM_WRITE_u32(base, 0x567BE0u, ctx.xmm[0].u32[0]);
	// 0x26B9A0: ret
	return;
}

void sub_26B9B0(X86Context& ctx, uint8_t* base) {
	// 0x26B9B0: movss xmm0, dword ptr [0x00567C24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C24u);
	// 0x26B9B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26B9C0: movss [0x00567C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C5Cu, ctx.xmm[0].u32[0]);
	// 0x26B9C8: ret
	return;
}

void sub_26B9D0(X86Context& ctx, uint8_t* base) {
	// 0x26B9D0: movss xmm0, dword ptr [0x00567BE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BE0u);
	// 0x26B9D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26B9E0: movss [0x00567C44], xmm0
	X86_MEM_WRITE_u32(base, 0x567C44u, ctx.xmm[0].u32[0]);
	// 0x26B9E8: ret
	return;
}

void sub_26B9F0(X86Context& ctx, uint8_t* base) {
	// 0x26B9F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26B9F8: movss [0x00567C74], xmm0
	X86_MEM_WRITE_u32(base, 0x567C74u, ctx.xmm[0].u32[0]);
	// 0x26BA00: ret
	return;
}

void sub_26BA10(X86Context& ctx, uint8_t* base) {
	// 0x26BA10: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26BA18: movss [0x00567C60], xmm0
	X86_MEM_WRITE_u32(base, 0x567C60u, ctx.xmm[0].u32[0]);
	// 0x26BA20: ret
	return;
}

void sub_26BA30(X86Context& ctx, uint8_t* base) {
	// 0x26BA30: movss xmm0, dword ptr [0x00567C60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C60u);
	// 0x26BA38: movss [0x00567C70], xmm0
	X86_MEM_WRITE_u32(base, 0x567C70u, ctx.xmm[0].u32[0]);
	// 0x26BA40: ret
	return;
}

void sub_26BA50(X86Context& ctx, uint8_t* base) {
	// 0x26BA50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26BA58: movss [0x00567BCC], xmm0
	X86_MEM_WRITE_u32(base, 0x567BCCu, ctx.xmm[0].u32[0]);
	// 0x26BA60: ret
	return;
}

void sub_26BA70(X86Context& ctx, uint8_t* base) {
	// 0x26BA70: movss xmm0, dword ptr [0x00567BE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BE0u);
	// 0x26BA78: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26BA80: movss [0x00567C68], xmm0
	X86_MEM_WRITE_u32(base, 0x567C68u, ctx.xmm[0].u32[0]);
	// 0x26BA88: ret
	return;
}

void sub_26BA90(X86Context& ctx, uint8_t* base) {
	// 0x26BA90: movss xmm0, dword ptr [0x00567BE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BE0u);
	// 0x26BA98: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26BAA0: movss [0x00567C0C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C0Cu, ctx.xmm[0].u32[0]);
	// 0x26BAA8: ret
	return;
}

void sub_26BAB0(X86Context& ctx, uint8_t* base) {
	// 0x26BAB0: movss xmm0, dword ptr [0x00567BE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BE0u);
	// 0x26BAB8: subss xmm0, [0x00567C0C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567C0Cu);
	// 0x26BAC0: movss [0x00567BE8], xmm0
	X86_MEM_WRITE_u32(base, 0x567BE8u, ctx.xmm[0].u32[0]);
	// 0x26BAC8: ret
	return;
}

void sub_26BAD0(X86Context& ctx, uint8_t* base) {
	// 0x26BAD0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26BAD8: movss [0x00567C38], xmm0
	X86_MEM_WRITE_u32(base, 0x567C38u, ctx.xmm[0].u32[0]);
	// 0x26BAE0: ret
	return;
}

void sub_26BAF0(X86Context& ctx, uint8_t* base) {
	// 0x26BAF0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26BAF8: movss [0x00567BE4], xmm0
	X86_MEM_WRITE_u32(base, 0x567BE4u, ctx.xmm[0].u32[0]);
	// 0x26BB00: ret
	return;
}

void sub_26BB10(X86Context& ctx, uint8_t* base) {
	// 0x26BB10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26BB18: movss [0x00567BF8], xmm0
	X86_MEM_WRITE_u32(base, 0x567BF8u, ctx.xmm[0].u32[0]);
	// 0x26BB20: ret
	return;
}

void sub_26BB30(X86Context& ctx, uint8_t* base) {
	// 0x26BB30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26BB38: movss [0x00567C50], xmm0
	X86_MEM_WRITE_u32(base, 0x567C50u, ctx.xmm[0].u32[0]);
	// 0x26BB40: ret
	return;
}

void sub_26BB50(X86Context& ctx, uint8_t* base) {
	// 0x26BB50: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26BB58: movss [0x00567C34], xmm0
	X86_MEM_WRITE_u32(base, 0x567C34u, ctx.xmm[0].u32[0]);
	// 0x26BB60: ret
	return;
}

void sub_26BB70(X86Context& ctx, uint8_t* base) {
	// 0x26BB70: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26BB78: movss [0x00567BDC], xmm0
	X86_MEM_WRITE_u32(base, 0x567BDCu, ctx.xmm[0].u32[0]);
	// 0x26BB80: ret
	return;
}

void sub_26BB90(X86Context& ctx, uint8_t* base) {
	// 0x26BB90: movss xmm0, dword ptr [0x00567BF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BF8u);
	// 0x26BB98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26BBA0: movss [0x00567BD0], xmm0
	X86_MEM_WRITE_u32(base, 0x567BD0u, ctx.xmm[0].u32[0]);
	// 0x26BBA8: ret
	return;
}

void sub_26BBB0(X86Context& ctx, uint8_t* base) {
	// 0x26BBB0: movss xmm0, dword ptr [0x00567C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C50u);
	// 0x26BBB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26BBC0: movss [0x00567C18], xmm0
	X86_MEM_WRITE_u32(base, 0x567C18u, ctx.xmm[0].u32[0]);
	// 0x26BBC8: ret
	return;
}

void sub_26BBD0(X86Context& ctx, uint8_t* base) {
	// 0x26BBD0: movss xmm0, dword ptr [0x00567BD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BD0u);
	// 0x26BBD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26BBE0: movss [0x00567C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C2Cu, ctx.xmm[0].u32[0]);
	// 0x26BBE8: ret
	return;
}

void sub_26BBF0(X86Context& ctx, uint8_t* base) {
	// 0x26BBF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26BBF8: movss [0x00567BC8], xmm0
	X86_MEM_WRITE_u32(base, 0x567BC8u, ctx.xmm[0].u32[0]);
	// 0x26BC00: ret
	return;
}

void sub_26BC10(X86Context& ctx, uint8_t* base) {
	// 0x26BC10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26BC18: movss [0x00567BFC], xmm0
	X86_MEM_WRITE_u32(base, 0x567BFCu, ctx.xmm[0].u32[0]);
	// 0x26BC20: ret
	return;
}

void sub_26BC30(X86Context& ctx, uint8_t* base) {
	// 0x26BC30: movss xmm0, dword ptr [0x00567BF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BF8u);
	// 0x26BC38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26BC40: movss [0x00567C08], xmm0
	X86_MEM_WRITE_u32(base, 0x567C08u, ctx.xmm[0].u32[0]);
	// 0x26BC48: ret
	return;
}

void sub_26BC50(X86Context& ctx, uint8_t* base) {
	// 0x26BC50: movss xmm0, dword ptr [0x00567C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C50u);
	// 0x26BC58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26BC60: movss [0x00567C54], xmm0
	X86_MEM_WRITE_u32(base, 0x567C54u, ctx.xmm[0].u32[0]);
	// 0x26BC68: ret
	return;
}

void sub_26BC70(X86Context& ctx, uint8_t* base) {
	// 0x26BC70: movss xmm0, dword ptr [0x00567C08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C08u);
	// 0x26BC78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26BC80: movss [0x00567C40], xmm0
	X86_MEM_WRITE_u32(base, 0x567C40u, ctx.xmm[0].u32[0]);
	// 0x26BC88: ret
	return;
}

void sub_26BC90(X86Context& ctx, uint8_t* base) {
	// 0x26BC90: movss xmm0, dword ptr [0x00567C54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C54u);
	// 0x26BC98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26BCA0: movss [0x00567C64], xmm0
	X86_MEM_WRITE_u32(base, 0x567C64u, ctx.xmm[0].u32[0]);
	// 0x26BCA8: ret
	return;
}

void sub_26BCB0(X86Context& ctx, uint8_t* base) {
	// 0x26BCB0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26BCB8: movss [0x00567BD4], xmm0
	X86_MEM_WRITE_u32(base, 0x567BD4u, ctx.xmm[0].u32[0]);
	// 0x26BCC0: ret
	return;
}

void sub_26BCD0(X86Context& ctx, uint8_t* base) {
	// 0x26BCD0: movss xmm0, dword ptr [0x00567BF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BF8u);
	// 0x26BCD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26BCE0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26BCE8: movss [0x00567C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C4Cu, ctx.xmm[0].u32[0]);
	// 0x26BCF0: ret
	return;
}

void sub_26BD00(X86Context& ctx, uint8_t* base) {
	// 0x26BD00: movss xmm0, dword ptr [0x00567C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C50u);
	// 0x26BD08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26BD10: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26BD18: movss [0x00567BEC], xmm0
	X86_MEM_WRITE_u32(base, 0x567BECu, ctx.xmm[0].u32[0]);
	// 0x26BD20: ret
	return;
}

void sub_26BD30(X86Context& ctx, uint8_t* base) {
	// 0x26BD30: movss xmm0, dword ptr [0x00567BF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BF8u);
	// 0x26BD38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26BD40: movss [0x00567BF0], xmm0
	X86_MEM_WRITE_u32(base, 0x567BF0u, ctx.xmm[0].u32[0]);
	// 0x26BD48: ret
	return;
}

void sub_26BD50(X86Context& ctx, uint8_t* base) {
	// 0x26BD50: movss xmm0, dword ptr [0x00567C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C50u);
	// 0x26BD58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26BD60: movss [0x00567C58], xmm0
	X86_MEM_WRITE_u32(base, 0x567C58u, ctx.xmm[0].u32[0]);
	// 0x26BD68: ret
	return;
}

void sub_26BD70(X86Context& ctx, uint8_t* base) {
	// 0x26BD70: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26BD78: movss [0x00567BD8], xmm0
	X86_MEM_WRITE_u32(base, 0x567BD8u, ctx.xmm[0].u32[0]);
	// 0x26BD80: ret
	return;
}

void sub_26BD90(X86Context& ctx, uint8_t* base) {
	// 0x26BD90: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26BD98: movss [0x00567C04], xmm0
	X86_MEM_WRITE_u32(base, 0x567C04u, ctx.xmm[0].u32[0]);
	// 0x26BDA0: ret
	return;
}

void sub_26BDB0(X86Context& ctx, uint8_t* base) {
	// 0x26BDB0: movss xmm0, dword ptr [0x00567BD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567BD8u);
	// 0x26BDB8: movss [0x00567C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C6Cu, ctx.xmm[0].u32[0]);
	// 0x26BDC0: ret
	return;
}

void sub_26BDD0(X86Context& ctx, uint8_t* base) {
	// 0x26BDD0: movss xmm0, dword ptr [0x00567C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C50u);
	// 0x26BDD8: subss xmm0, [0x00567BD8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567BD8u);
	// 0x26BDE0: movss [0x00567C30], xmm0
	X86_MEM_WRITE_u32(base, 0x567C30u, ctx.xmm[0].u32[0]);
	// 0x26BDE8: ret
	return;
}

void sub_26BDF0(X86Context& ctx, uint8_t* base) {
	// 0x26BDF0: movss xmm0, dword ptr [0x00567C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C30u);
	// 0x26BDF8: subss xmm0, [0x00567C04]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567C04u);
	// 0x26BE00: movss [0x00567C28], xmm0
	X86_MEM_WRITE_u32(base, 0x567C28u, ctx.xmm[0].u32[0]);
	// 0x26BE08: ret
	return;
}

void sub_26BE10(X86Context& ctx, uint8_t* base) {
	// 0x26BE10: movss xmm0, dword ptr [0x00567C58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C58u);
	// 0x26BE18: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26BE20: movss [0x00567C14], xmm0
	X86_MEM_WRITE_u32(base, 0x567C14u, ctx.xmm[0].u32[0]);
	// 0x26BE28: ret
	return;
}

void sub_26BE30(X86Context& ctx, uint8_t* base) {
	// 0x26BE30: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26BE38: movss [0x00567C00], xmm0
	X86_MEM_WRITE_u32(base, 0x567C00u, ctx.xmm[0].u32[0]);
	// 0x26BE40: ret
	return;
}

void sub_26BE50(X86Context& ctx, uint8_t* base) {
	// 0x26BE50: movss xmm0, dword ptr [0x00567C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C14u);
	// 0x26BE58: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26BE60: movss [0x00567C48], xmm0
	X86_MEM_WRITE_u32(base, 0x567C48u, ctx.xmm[0].u32[0]);
	// 0x26BE68: ret
	return;
}

void sub_26BE70(X86Context& ctx, uint8_t* base) {
	// 0x26BE70: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26BE78: movss [0x00567C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C1Cu, ctx.xmm[0].u32[0]);
	// 0x26BE80: ret
	return;
}

void sub_26BE90(X86Context& ctx, uint8_t* base) {
	// 0x26BE90: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26BE98: movss [0x00567BF4], xmm0
	X86_MEM_WRITE_u32(base, 0x567BF4u, ctx.xmm[0].u32[0]);
	// 0x26BEA0: ret
	return;
}

void sub_26BEB0(X86Context& ctx, uint8_t* base) {
	// 0x26BEB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26BEB8: movss [0x00567CD4], xmm0
	X86_MEM_WRITE_u32(base, 0x567CD4u, ctx.xmm[0].u32[0]);
	// 0x26BEC0: ret
	return;
}

void sub_26BED0(X86Context& ctx, uint8_t* base) {
	// 0x26BED0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26BED8: movss [0x00567CF0], xmm0
	X86_MEM_WRITE_u32(base, 0x567CF0u, ctx.xmm[0].u32[0]);
	// 0x26BEE0: ret
	return;
}

void sub_26BEF0(X86Context& ctx, uint8_t* base) {
	// 0x26BEF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26BEF8: movss [0x00567CC4], xmm0
	X86_MEM_WRITE_u32(base, 0x567CC4u, ctx.xmm[0].u32[0]);
	// 0x26BF00: ret
	return;
}

void sub_26BF10(X86Context& ctx, uint8_t* base) {
	// 0x26BF10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26BF18: movss [0x00567C78], xmm0
	X86_MEM_WRITE_u32(base, 0x567C78u, ctx.xmm[0].u32[0]);
	// 0x26BF20: ret
	return;
}

void sub_26BF30(X86Context& ctx, uint8_t* base) {
	// 0x26BF30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26BF38: movss [0x00567CD8], xmm0
	X86_MEM_WRITE_u32(base, 0x567CD8u, ctx.xmm[0].u32[0]);
	// 0x26BF40: ret
	return;
}

void sub_26BF50(X86Context& ctx, uint8_t* base) {
	// 0x26BF50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26BF58: movss [0x00567C94], xmm0
	X86_MEM_WRITE_u32(base, 0x567C94u, ctx.xmm[0].u32[0]);
	// 0x26BF60: ret
	return;
}

void sub_26BF70(X86Context& ctx, uint8_t* base) {
	// 0x26BF70: movss xmm0, dword ptr [0x00567CD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CD8u);
	// 0x26BF78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26BF80: movss [0x00567D10], xmm0
	X86_MEM_WRITE_u32(base, 0x567D10u, ctx.xmm[0].u32[0]);
	// 0x26BF88: ret
	return;
}

void sub_26BF90(X86Context& ctx, uint8_t* base) {
	// 0x26BF90: movss xmm0, dword ptr [0x00567C94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C94u);
	// 0x26BF98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26BFA0: movss [0x00567CF8], xmm0
	X86_MEM_WRITE_u32(base, 0x567CF8u, ctx.xmm[0].u32[0]);
	// 0x26BFA8: ret
	return;
}

void sub_26BFB0(X86Context& ctx, uint8_t* base) {
	// 0x26BFB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26BFB8: movss [0x00567D28], xmm0
	X86_MEM_WRITE_u32(base, 0x567D28u, ctx.xmm[0].u32[0]);
	// 0x26BFC0: ret
	return;
}

void sub_26BFD0(X86Context& ctx, uint8_t* base) {
	// 0x26BFD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26BFD8: movss [0x00567D14], xmm0
	X86_MEM_WRITE_u32(base, 0x567D14u, ctx.xmm[0].u32[0]);
	// 0x26BFE0: ret
	return;
}

void sub_26BFF0(X86Context& ctx, uint8_t* base) {
	// 0x26BFF0: movss xmm0, dword ptr [0x00567D14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D14u);
	// 0x26BFF8: movss [0x00567D24], xmm0
	X86_MEM_WRITE_u32(base, 0x567D24u, ctx.xmm[0].u32[0]);
	// 0x26C000: ret
	return;
}

void sub_26C010(X86Context& ctx, uint8_t* base) {
	// 0x26C010: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26C018: movss [0x00567C80], xmm0
	X86_MEM_WRITE_u32(base, 0x567C80u, ctx.xmm[0].u32[0]);
	// 0x26C020: ret
	return;
}

void sub_26C030(X86Context& ctx, uint8_t* base) {
	// 0x26C030: movss xmm0, dword ptr [0x00567C94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C94u);
	// 0x26C038: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26C040: movss [0x00567D1C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D1Cu, ctx.xmm[0].u32[0]);
	// 0x26C048: ret
	return;
}

void sub_26C050(X86Context& ctx, uint8_t* base) {
	// 0x26C050: movss xmm0, dword ptr [0x00567C94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C94u);
	// 0x26C058: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26C060: movss [0x00567CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x567CC0u, ctx.xmm[0].u32[0]);
	// 0x26C068: ret
	return;
}

void sub_26C070(X86Context& ctx, uint8_t* base) {
	// 0x26C070: movss xmm0, dword ptr [0x00567C94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C94u);
	// 0x26C078: subss xmm0, [0x00567CC0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567CC0u);
	// 0x26C080: movss [0x00567C9C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C9Cu, ctx.xmm[0].u32[0]);
	// 0x26C088: ret
	return;
}

void sub_26C090(X86Context& ctx, uint8_t* base) {
	// 0x26C090: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26C098: movss [0x00567CEC], xmm0
	X86_MEM_WRITE_u32(base, 0x567CECu, ctx.xmm[0].u32[0]);
	// 0x26C0A0: ret
	return;
}

void sub_26C0B0(X86Context& ctx, uint8_t* base) {
	// 0x26C0B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26C0B8: movss [0x00567C98], xmm0
	X86_MEM_WRITE_u32(base, 0x567C98u, ctx.xmm[0].u32[0]);
	// 0x26C0C0: ret
	return;
}

void sub_26C0D0(X86Context& ctx, uint8_t* base) {
	// 0x26C0D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26C0D8: movss [0x00567CAC], xmm0
	X86_MEM_WRITE_u32(base, 0x567CACu, ctx.xmm[0].u32[0]);
	// 0x26C0E0: ret
	return;
}

void sub_26C0F0(X86Context& ctx, uint8_t* base) {
	// 0x26C0F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26C0F8: movss [0x00567D04], xmm0
	X86_MEM_WRITE_u32(base, 0x567D04u, ctx.xmm[0].u32[0]);
	// 0x26C100: ret
	return;
}

void sub_26C110(X86Context& ctx, uint8_t* base) {
	// 0x26C110: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26C118: movss [0x00567CE8], xmm0
	X86_MEM_WRITE_u32(base, 0x567CE8u, ctx.xmm[0].u32[0]);
	// 0x26C120: ret
	return;
}

void sub_26C130(X86Context& ctx, uint8_t* base) {
	// 0x26C130: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26C138: movss [0x00567C90], xmm0
	X86_MEM_WRITE_u32(base, 0x567C90u, ctx.xmm[0].u32[0]);
	// 0x26C140: ret
	return;
}

void sub_26C150(X86Context& ctx, uint8_t* base) {
	// 0x26C150: movss xmm0, dword ptr [0x00567CAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CACu);
	// 0x26C158: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26C160: movss [0x00567C84], xmm0
	X86_MEM_WRITE_u32(base, 0x567C84u, ctx.xmm[0].u32[0]);
	// 0x26C168: ret
	return;
}

void sub_26C170(X86Context& ctx, uint8_t* base) {
	// 0x26C170: movss xmm0, dword ptr [0x00567D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D04u);
	// 0x26C178: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26C180: movss [0x00567CCC], xmm0
	X86_MEM_WRITE_u32(base, 0x567CCCu, ctx.xmm[0].u32[0]);
	// 0x26C188: ret
	return;
}

void sub_26C190(X86Context& ctx, uint8_t* base) {
	// 0x26C190: movss xmm0, dword ptr [0x00567C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C84u);
	// 0x26C198: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26C1A0: movss [0x00567CE0], xmm0
	X86_MEM_WRITE_u32(base, 0x567CE0u, ctx.xmm[0].u32[0]);
	// 0x26C1A8: ret
	return;
}

void sub_26C1B0(X86Context& ctx, uint8_t* base) {
	// 0x26C1B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26C1B8: movss [0x00567C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C7Cu, ctx.xmm[0].u32[0]);
	// 0x26C1C0: ret
	return;
}

void sub_26C1D0(X86Context& ctx, uint8_t* base) {
	// 0x26C1D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26C1D8: movss [0x00567CB0], xmm0
	X86_MEM_WRITE_u32(base, 0x567CB0u, ctx.xmm[0].u32[0]);
	// 0x26C1E0: ret
	return;
}

void sub_26C1F0(X86Context& ctx, uint8_t* base) {
	// 0x26C1F0: movss xmm0, dword ptr [0x00567CAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CACu);
	// 0x26C1F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26C200: movss [0x00567CBC], xmm0
	X86_MEM_WRITE_u32(base, 0x567CBCu, ctx.xmm[0].u32[0]);
	// 0x26C208: ret
	return;
}

void sub_26C210(X86Context& ctx, uint8_t* base) {
	// 0x26C210: movss xmm0, dword ptr [0x00567D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D04u);
	// 0x26C218: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26C220: movss [0x00567D08], xmm0
	X86_MEM_WRITE_u32(base, 0x567D08u, ctx.xmm[0].u32[0]);
	// 0x26C228: ret
	return;
}

void sub_26C230(X86Context& ctx, uint8_t* base) {
	// 0x26C230: movss xmm0, dword ptr [0x00567CBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CBCu);
	// 0x26C238: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C240: movss [0x00567CF4], xmm0
	X86_MEM_WRITE_u32(base, 0x567CF4u, ctx.xmm[0].u32[0]);
	// 0x26C248: ret
	return;
}

void sub_26C250(X86Context& ctx, uint8_t* base) {
	// 0x26C250: movss xmm0, dword ptr [0x00567D08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D08u);
	// 0x26C258: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C260: movss [0x00567D18], xmm0
	X86_MEM_WRITE_u32(base, 0x567D18u, ctx.xmm[0].u32[0]);
	// 0x26C268: ret
	return;
}

void sub_26C270(X86Context& ctx, uint8_t* base) {
	// 0x26C270: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26C278: movss [0x00567C88], xmm0
	X86_MEM_WRITE_u32(base, 0x567C88u, ctx.xmm[0].u32[0]);
	// 0x26C280: ret
	return;
}

void sub_26C290(X86Context& ctx, uint8_t* base) {
	// 0x26C290: movss xmm0, dword ptr [0x00567CAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CACu);
	// 0x26C298: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C2A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26C2A8: movss [0x00567D00], xmm0
	X86_MEM_WRITE_u32(base, 0x567D00u, ctx.xmm[0].u32[0]);
	// 0x26C2B0: ret
	return;
}

void sub_26C2C0(X86Context& ctx, uint8_t* base) {
	// 0x26C2C0: movss xmm0, dword ptr [0x00567D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D04u);
	// 0x26C2C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C2D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26C2D8: movss [0x00567CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x567CA0u, ctx.xmm[0].u32[0]);
	// 0x26C2E0: ret
	return;
}

void sub_26C2F0(X86Context& ctx, uint8_t* base) {
	// 0x26C2F0: movss xmm0, dword ptr [0x00567CAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CACu);
	// 0x26C2F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C300: movss [0x00567CA4], xmm0
	X86_MEM_WRITE_u32(base, 0x567CA4u, ctx.xmm[0].u32[0]);
	// 0x26C308: ret
	return;
}

void sub_26C310(X86Context& ctx, uint8_t* base) {
	// 0x26C310: movss xmm0, dword ptr [0x00567D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D04u);
	// 0x26C318: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C320: movss [0x00567D0C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D0Cu, ctx.xmm[0].u32[0]);
	// 0x26C328: ret
	return;
}

void sub_26C330(X86Context& ctx, uint8_t* base) {
	// 0x26C330: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26C338: movss [0x00567C8C], xmm0
	X86_MEM_WRITE_u32(base, 0x567C8Cu, ctx.xmm[0].u32[0]);
	// 0x26C340: ret
	return;
}

void sub_26C350(X86Context& ctx, uint8_t* base) {
	// 0x26C350: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26C358: movss [0x00567CB8], xmm0
	X86_MEM_WRITE_u32(base, 0x567CB8u, ctx.xmm[0].u32[0]);
	// 0x26C360: ret
	return;
}

void sub_26C370(X86Context& ctx, uint8_t* base) {
	// 0x26C370: movss xmm0, dword ptr [0x00567C8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567C8Cu);
	// 0x26C378: movss [0x00567D20], xmm0
	X86_MEM_WRITE_u32(base, 0x567D20u, ctx.xmm[0].u32[0]);
	// 0x26C380: ret
	return;
}

void sub_26C390(X86Context& ctx, uint8_t* base) {
	// 0x26C390: movss xmm0, dword ptr [0x00567D04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D04u);
	// 0x26C398: subss xmm0, [0x00567C8C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567C8Cu);
	// 0x26C3A0: movss [0x00567CE4], xmm0
	X86_MEM_WRITE_u32(base, 0x567CE4u, ctx.xmm[0].u32[0]);
	// 0x26C3A8: ret
	return;
}

void sub_26C3B0(X86Context& ctx, uint8_t* base) {
	// 0x26C3B0: movss xmm0, dword ptr [0x00567CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CE4u);
	// 0x26C3B8: subss xmm0, [0x00567CB8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567CB8u);
	// 0x26C3C0: movss [0x00567CDC], xmm0
	X86_MEM_WRITE_u32(base, 0x567CDCu, ctx.xmm[0].u32[0]);
	// 0x26C3C8: ret
	return;
}

void sub_26C3D0(X86Context& ctx, uint8_t* base) {
	// 0x26C3D0: movss xmm0, dword ptr [0x00567D0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D0Cu);
	// 0x26C3D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26C3E0: movss [0x00567CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x567CC8u, ctx.xmm[0].u32[0]);
	// 0x26C3E8: ret
	return;
}

void sub_26C3F0(X86Context& ctx, uint8_t* base) {
	// 0x26C3F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26C3F8: movss [0x00567CB4], xmm0
	X86_MEM_WRITE_u32(base, 0x567CB4u, ctx.xmm[0].u32[0]);
	// 0x26C400: ret
	return;
}

void sub_26C410(X86Context& ctx, uint8_t* base) {
	// 0x26C410: movss xmm0, dword ptr [0x00567CC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567CC8u);
	// 0x26C418: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26C420: movss [0x00567CFC], xmm0
	X86_MEM_WRITE_u32(base, 0x567CFCu, ctx.xmm[0].u32[0]);
	// 0x26C428: ret
	return;
}

void sub_26C430(X86Context& ctx, uint8_t* base) {
	// 0x26C430: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26C438: movss [0x00567CD0], xmm0
	X86_MEM_WRITE_u32(base, 0x567CD0u, ctx.xmm[0].u32[0]);
	// 0x26C440: ret
	return;
}

void sub_26C450(X86Context& ctx, uint8_t* base) {
	// 0x26C450: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26C458: movss [0x00567CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x567CA8u, ctx.xmm[0].u32[0]);
	// 0x26C460: ret
	return;
}

void sub_26C470(X86Context& ctx, uint8_t* base) {
	// 0x26C470: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26C478: movss [0x00567D88], xmm0
	X86_MEM_WRITE_u32(base, 0x567D88u, ctx.xmm[0].u32[0]);
	// 0x26C480: ret
	return;
}

void sub_26C490(X86Context& ctx, uint8_t* base) {
	// 0x26C490: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26C498: movss [0x00567DA4], xmm0
	X86_MEM_WRITE_u32(base, 0x567DA4u, ctx.xmm[0].u32[0]);
	// 0x26C4A0: ret
	return;
}

void sub_26C4B0(X86Context& ctx, uint8_t* base) {
	// 0x26C4B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26C4B8: movss [0x00567D78], xmm0
	X86_MEM_WRITE_u32(base, 0x567D78u, ctx.xmm[0].u32[0]);
	// 0x26C4C0: ret
	return;
}

void sub_26C4D0(X86Context& ctx, uint8_t* base) {
	// 0x26C4D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26C4D8: movss [0x00567D2C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D2Cu, ctx.xmm[0].u32[0]);
	// 0x26C4E0: ret
	return;
}

void sub_26C4F0(X86Context& ctx, uint8_t* base) {
	// 0x26C4F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26C4F8: movss [0x00567D8C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D8Cu, ctx.xmm[0].u32[0]);
	// 0x26C500: ret
	return;
}

void sub_26C510(X86Context& ctx, uint8_t* base) {
	// 0x26C510: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26C518: movss [0x00567D48], xmm0
	X86_MEM_WRITE_u32(base, 0x567D48u, ctx.xmm[0].u32[0]);
	// 0x26C520: ret
	return;
}

void sub_26C530(X86Context& ctx, uint8_t* base) {
	// 0x26C530: movss xmm0, dword ptr [0x00567D8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D8Cu);
	// 0x26C538: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26C540: movss [0x00567DC4], xmm0
	X86_MEM_WRITE_u32(base, 0x567DC4u, ctx.xmm[0].u32[0]);
	// 0x26C548: ret
	return;
}

void sub_26C550(X86Context& ctx, uint8_t* base) {
	// 0x26C550: movss xmm0, dword ptr [0x00567D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D48u);
	// 0x26C558: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26C560: movss [0x00567DAC], xmm0
	X86_MEM_WRITE_u32(base, 0x567DACu, ctx.xmm[0].u32[0]);
	// 0x26C568: ret
	return;
}

void sub_26C570(X86Context& ctx, uint8_t* base) {
	// 0x26C570: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26C578: movss [0x00567DDC], xmm0
	X86_MEM_WRITE_u32(base, 0x567DDCu, ctx.xmm[0].u32[0]);
	// 0x26C580: ret
	return;
}

void sub_26C590(X86Context& ctx, uint8_t* base) {
	// 0x26C590: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26C598: movss [0x00567DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x567DC8u, ctx.xmm[0].u32[0]);
	// 0x26C5A0: ret
	return;
}

void sub_26C5B0(X86Context& ctx, uint8_t* base) {
	// 0x26C5B0: movss xmm0, dword ptr [0x00567DC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DC8u);
	// 0x26C5B8: movss [0x00567DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x567DD8u, ctx.xmm[0].u32[0]);
	// 0x26C5C0: ret
	return;
}

void sub_26C5D0(X86Context& ctx, uint8_t* base) {
	// 0x26C5D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26C5D8: movss [0x00567D34], xmm0
	X86_MEM_WRITE_u32(base, 0x567D34u, ctx.xmm[0].u32[0]);
	// 0x26C5E0: ret
	return;
}

void sub_26C5F0(X86Context& ctx, uint8_t* base) {
	// 0x26C5F0: movss xmm0, dword ptr [0x00567D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D48u);
	// 0x26C5F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26C600: movss [0x00567DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x567DD0u, ctx.xmm[0].u32[0]);
	// 0x26C608: ret
	return;
}

void sub_26C610(X86Context& ctx, uint8_t* base) {
	// 0x26C610: movss xmm0, dword ptr [0x00567D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D48u);
	// 0x26C618: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26C620: movss [0x00567D74], xmm0
	X86_MEM_WRITE_u32(base, 0x567D74u, ctx.xmm[0].u32[0]);
	// 0x26C628: ret
	return;
}

void sub_26C630(X86Context& ctx, uint8_t* base) {
	// 0x26C630: movss xmm0, dword ptr [0x00567D48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D48u);
	// 0x26C638: subss xmm0, [0x00567D74]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567D74u);
	// 0x26C640: movss [0x00567D50], xmm0
	X86_MEM_WRITE_u32(base, 0x567D50u, ctx.xmm[0].u32[0]);
	// 0x26C648: ret
	return;
}

void sub_26C650(X86Context& ctx, uint8_t* base) {
	// 0x26C650: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26C658: movss [0x00567DA0], xmm0
	X86_MEM_WRITE_u32(base, 0x567DA0u, ctx.xmm[0].u32[0]);
	// 0x26C660: ret
	return;
}

void sub_26C670(X86Context& ctx, uint8_t* base) {
	// 0x26C670: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26C678: movss [0x00567D4C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D4Cu, ctx.xmm[0].u32[0]);
	// 0x26C680: ret
	return;
}

void sub_26C690(X86Context& ctx, uint8_t* base) {
	// 0x26C690: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26C698: movss [0x00567D60], xmm0
	X86_MEM_WRITE_u32(base, 0x567D60u, ctx.xmm[0].u32[0]);
	// 0x26C6A0: ret
	return;
}

void sub_26C6B0(X86Context& ctx, uint8_t* base) {
	// 0x26C6B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26C6B8: movss [0x00567DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x567DB8u, ctx.xmm[0].u32[0]);
	// 0x26C6C0: ret
	return;
}

void sub_26C6D0(X86Context& ctx, uint8_t* base) {
	// 0x26C6D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26C6D8: movss [0x00567D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D9Cu, ctx.xmm[0].u32[0]);
	// 0x26C6E0: ret
	return;
}

void sub_26C6F0(X86Context& ctx, uint8_t* base) {
	// 0x26C6F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26C6F8: movss [0x00567D44], xmm0
	X86_MEM_WRITE_u32(base, 0x567D44u, ctx.xmm[0].u32[0]);
	// 0x26C700: ret
	return;
}

void sub_26C710(X86Context& ctx, uint8_t* base) {
	// 0x26C710: movss xmm0, dword ptr [0x00567D60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D60u);
	// 0x26C718: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26C720: movss [0x00567D38], xmm0
	X86_MEM_WRITE_u32(base, 0x567D38u, ctx.xmm[0].u32[0]);
	// 0x26C728: ret
	return;
}

void sub_26C730(X86Context& ctx, uint8_t* base) {
	// 0x26C730: movss xmm0, dword ptr [0x00567DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DB8u);
	// 0x26C738: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26C740: movss [0x00567D80], xmm0
	X86_MEM_WRITE_u32(base, 0x567D80u, ctx.xmm[0].u32[0]);
	// 0x26C748: ret
	return;
}

void sub_26C750(X86Context& ctx, uint8_t* base) {
	// 0x26C750: movss xmm0, dword ptr [0x00567D38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D38u);
	// 0x26C758: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26C760: movss [0x00567D94], xmm0
	X86_MEM_WRITE_u32(base, 0x567D94u, ctx.xmm[0].u32[0]);
	// 0x26C768: ret
	return;
}

void sub_26C770(X86Context& ctx, uint8_t* base) {
	// 0x26C770: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26C778: movss [0x00567D30], xmm0
	X86_MEM_WRITE_u32(base, 0x567D30u, ctx.xmm[0].u32[0]);
	// 0x26C780: ret
	return;
}

void sub_26C790(X86Context& ctx, uint8_t* base) {
	// 0x26C790: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26C798: movss [0x00567D64], xmm0
	X86_MEM_WRITE_u32(base, 0x567D64u, ctx.xmm[0].u32[0]);
	// 0x26C7A0: ret
	return;
}

void sub_26C7B0(X86Context& ctx, uint8_t* base) {
	// 0x26C7B0: movss xmm0, dword ptr [0x00567D60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D60u);
	// 0x26C7B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26C7C0: movss [0x00567D70], xmm0
	X86_MEM_WRITE_u32(base, 0x567D70u, ctx.xmm[0].u32[0]);
	// 0x26C7C8: ret
	return;
}

void sub_26C7D0(X86Context& ctx, uint8_t* base) {
	// 0x26C7D0: movss xmm0, dword ptr [0x00567DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DB8u);
	// 0x26C7D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26C7E0: movss [0x00567DBC], xmm0
	X86_MEM_WRITE_u32(base, 0x567DBCu, ctx.xmm[0].u32[0]);
	// 0x26C7E8: ret
	return;
}

void sub_26C7F0(X86Context& ctx, uint8_t* base) {
	// 0x26C7F0: movss xmm0, dword ptr [0x00567D70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D70u);
	// 0x26C7F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C800: movss [0x00567DA8], xmm0
	X86_MEM_WRITE_u32(base, 0x567DA8u, ctx.xmm[0].u32[0]);
	// 0x26C808: ret
	return;
}

void sub_26C810(X86Context& ctx, uint8_t* base) {
	// 0x26C810: movss xmm0, dword ptr [0x00567DBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DBCu);
	// 0x26C818: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C820: movss [0x00567DCC], xmm0
	X86_MEM_WRITE_u32(base, 0x567DCCu, ctx.xmm[0].u32[0]);
	// 0x26C828: ret
	return;
}

void sub_26C830(X86Context& ctx, uint8_t* base) {
	// 0x26C830: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26C838: movss [0x00567D3C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D3Cu, ctx.xmm[0].u32[0]);
	// 0x26C840: ret
	return;
}

void sub_26C850(X86Context& ctx, uint8_t* base) {
	// 0x26C850: movss xmm0, dword ptr [0x00567D60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D60u);
	// 0x26C858: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C860: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26C868: movss [0x00567DB4], xmm0
	X86_MEM_WRITE_u32(base, 0x567DB4u, ctx.xmm[0].u32[0]);
	// 0x26C870: ret
	return;
}

void sub_26C880(X86Context& ctx, uint8_t* base) {
	// 0x26C880: movss xmm0, dword ptr [0x00567DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DB8u);
	// 0x26C888: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C890: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26C898: movss [0x00567D54], xmm0
	X86_MEM_WRITE_u32(base, 0x567D54u, ctx.xmm[0].u32[0]);
	// 0x26C8A0: ret
	return;
}

void sub_26C8B0(X86Context& ctx, uint8_t* base) {
	// 0x26C8B0: movss xmm0, dword ptr [0x00567D60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D60u);
	// 0x26C8B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C8C0: movss [0x00567D58], xmm0
	X86_MEM_WRITE_u32(base, 0x567D58u, ctx.xmm[0].u32[0]);
	// 0x26C8C8: ret
	return;
}

void sub_26C8D0(X86Context& ctx, uint8_t* base) {
	// 0x26C8D0: movss xmm0, dword ptr [0x00567DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DB8u);
	// 0x26C8D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26C8E0: movss [0x00567DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x567DC0u, ctx.xmm[0].u32[0]);
	// 0x26C8E8: ret
	return;
}

void sub_26C8F0(X86Context& ctx, uint8_t* base) {
	// 0x26C8F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26C8F8: movss [0x00567D40], xmm0
	X86_MEM_WRITE_u32(base, 0x567D40u, ctx.xmm[0].u32[0]);
	// 0x26C900: ret
	return;
}

void sub_26C910(X86Context& ctx, uint8_t* base) {
	// 0x26C910: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26C918: movss [0x00567D6C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D6Cu, ctx.xmm[0].u32[0]);
	// 0x26C920: ret
	return;
}

void sub_26C930(X86Context& ctx, uint8_t* base) {
	// 0x26C930: movss xmm0, dword ptr [0x00567D40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D40u);
	// 0x26C938: movss [0x00567DD4], xmm0
	X86_MEM_WRITE_u32(base, 0x567DD4u, ctx.xmm[0].u32[0]);
	// 0x26C940: ret
	return;
}

void sub_26C950(X86Context& ctx, uint8_t* base) {
	// 0x26C950: movss xmm0, dword ptr [0x00567DB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DB8u);
	// 0x26C958: subss xmm0, [0x00567D40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567D40u);
	// 0x26C960: movss [0x00567D98], xmm0
	X86_MEM_WRITE_u32(base, 0x567D98u, ctx.xmm[0].u32[0]);
	// 0x26C968: ret
	return;
}

void sub_26C970(X86Context& ctx, uint8_t* base) {
	// 0x26C970: movss xmm0, dword ptr [0x00567D98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D98u);
	// 0x26C978: subss xmm0, [0x00567D6C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567D6Cu);
	// 0x26C980: movss [0x00567D90], xmm0
	X86_MEM_WRITE_u32(base, 0x567D90u, ctx.xmm[0].u32[0]);
	// 0x26C988: ret
	return;
}

void sub_26C990(X86Context& ctx, uint8_t* base) {
	// 0x26C990: movss xmm0, dword ptr [0x00567DC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DC0u);
	// 0x26C998: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26C9A0: movss [0x00567D7C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D7Cu, ctx.xmm[0].u32[0]);
	// 0x26C9A8: ret
	return;
}

void sub_26C9B0(X86Context& ctx, uint8_t* base) {
	// 0x26C9B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26C9B8: movss [0x00567D68], xmm0
	X86_MEM_WRITE_u32(base, 0x567D68u, ctx.xmm[0].u32[0]);
	// 0x26C9C0: ret
	return;
}

void sub_26C9D0(X86Context& ctx, uint8_t* base) {
	// 0x26C9D0: movss xmm0, dword ptr [0x00567D7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567D7Cu);
	// 0x26C9D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26C9E0: movss [0x00567DB0], xmm0
	X86_MEM_WRITE_u32(base, 0x567DB0u, ctx.xmm[0].u32[0]);
	// 0x26C9E8: ret
	return;
}

void sub_26C9F0(X86Context& ctx, uint8_t* base) {
	// 0x26C9F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26C9F8: movss [0x00567D84], xmm0
	X86_MEM_WRITE_u32(base, 0x567D84u, ctx.xmm[0].u32[0]);
	// 0x26CA00: ret
	return;
}

void sub_26CA10(X86Context& ctx, uint8_t* base) {
	// 0x26CA10: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26CA18: movss [0x00567D5C], xmm0
	X86_MEM_WRITE_u32(base, 0x567D5Cu, ctx.xmm[0].u32[0]);
	// 0x26CA20: ret
	return;
}

void sub_26CA30(X86Context& ctx, uint8_t* base) {
	// 0x26CA30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26CA38: movss [0x00567E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E3Cu, ctx.xmm[0].u32[0]);
	// 0x26CA40: ret
	return;
}

void sub_26CA50(X86Context& ctx, uint8_t* base) {
	// 0x26CA50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26CA58: movss [0x00567E58], xmm0
	X86_MEM_WRITE_u32(base, 0x567E58u, ctx.xmm[0].u32[0]);
	// 0x26CA60: ret
	return;
}

void sub_26CA70(X86Context& ctx, uint8_t* base) {
	// 0x26CA70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26CA78: movss [0x00567E2C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E2Cu, ctx.xmm[0].u32[0]);
	// 0x26CA80: ret
	return;
}

void sub_26CA90(X86Context& ctx, uint8_t* base) {
	// 0x26CA90: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26CA98: movss [0x00567DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x567DE0u, ctx.xmm[0].u32[0]);
	// 0x26CAA0: ret
	return;
}

void sub_26CAB0(X86Context& ctx, uint8_t* base) {
	// 0x26CAB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26CAB8: movss [0x00567E40], xmm0
	X86_MEM_WRITE_u32(base, 0x567E40u, ctx.xmm[0].u32[0]);
	// 0x26CAC0: ret
	return;
}

void sub_26CAD0(X86Context& ctx, uint8_t* base) {
	// 0x26CAD0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26CAD8: movss [0x00567DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x567DFCu, ctx.xmm[0].u32[0]);
	// 0x26CAE0: ret
	return;
}

void sub_26CAF0(X86Context& ctx, uint8_t* base) {
	// 0x26CAF0: movss xmm0, dword ptr [0x00567E40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E40u);
	// 0x26CAF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26CB00: movss [0x00567E78], xmm0
	X86_MEM_WRITE_u32(base, 0x567E78u, ctx.xmm[0].u32[0]);
	// 0x26CB08: ret
	return;
}

void sub_26CB10(X86Context& ctx, uint8_t* base) {
	// 0x26CB10: movss xmm0, dword ptr [0x00567DFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DFCu);
	// 0x26CB18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26CB20: movss [0x00567E60], xmm0
	X86_MEM_WRITE_u32(base, 0x567E60u, ctx.xmm[0].u32[0]);
	// 0x26CB28: ret
	return;
}

void sub_26CB30(X86Context& ctx, uint8_t* base) {
	// 0x26CB30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26CB38: movss [0x00567E90], xmm0
	X86_MEM_WRITE_u32(base, 0x567E90u, ctx.xmm[0].u32[0]);
	// 0x26CB40: ret
	return;
}

void sub_26CB50(X86Context& ctx, uint8_t* base) {
	// 0x26CB50: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x26CB58: movss [0x00567E7C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E7Cu, ctx.xmm[0].u32[0]);
	// 0x26CB60: ret
	return;
}

void sub_26CB70(X86Context& ctx, uint8_t* base) {
	// 0x26CB70: movss xmm0, dword ptr [0x00567E7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E7Cu);
	// 0x26CB78: movss [0x00567E8C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E8Cu, ctx.xmm[0].u32[0]);
	// 0x26CB80: ret
	return;
}

void sub_26CB90(X86Context& ctx, uint8_t* base) {
	// 0x26CB90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x26CB98: movss [0x00567DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x567DE8u, ctx.xmm[0].u32[0]);
	// 0x26CBA0: ret
	return;
}

void sub_26CBB0(X86Context& ctx, uint8_t* base) {
	// 0x26CBB0: movss xmm0, dword ptr [0x00567DFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DFCu);
	// 0x26CBB8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x26CBC0: movss [0x00567E84], xmm0
	X86_MEM_WRITE_u32(base, 0x567E84u, ctx.xmm[0].u32[0]);
	// 0x26CBC8: ret
	return;
}

void sub_26CBD0(X86Context& ctx, uint8_t* base) {
	// 0x26CBD0: movss xmm0, dword ptr [0x00567DFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DFCu);
	// 0x26CBD8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x26CBE0: movss [0x00567E28], xmm0
	X86_MEM_WRITE_u32(base, 0x567E28u, ctx.xmm[0].u32[0]);
	// 0x26CBE8: ret
	return;
}

void sub_26CBF0(X86Context& ctx, uint8_t* base) {
	// 0x26CBF0: movss xmm0, dword ptr [0x00567DFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DFCu);
	// 0x26CBF8: subss xmm0, [0x00567E28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567E28u);
	// 0x26CC00: movss [0x00567E04], xmm0
	X86_MEM_WRITE_u32(base, 0x567E04u, ctx.xmm[0].u32[0]);
	// 0x26CC08: ret
	return;
}

void sub_26CC10(X86Context& ctx, uint8_t* base) {
	// 0x26CC10: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x26CC18: movss [0x00567E54], xmm0
	X86_MEM_WRITE_u32(base, 0x567E54u, ctx.xmm[0].u32[0]);
	// 0x26CC20: ret
	return;
}

void sub_26CC30(X86Context& ctx, uint8_t* base) {
	// 0x26CC30: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x26CC38: movss [0x00567E00], xmm0
	X86_MEM_WRITE_u32(base, 0x567E00u, ctx.xmm[0].u32[0]);
	// 0x26CC40: ret
	return;
}

void sub_26CC50(X86Context& ctx, uint8_t* base) {
	// 0x26CC50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26CC58: movss [0x00567E14], xmm0
	X86_MEM_WRITE_u32(base, 0x567E14u, ctx.xmm[0].u32[0]);
	// 0x26CC60: ret
	return;
}

void sub_26CC70(X86Context& ctx, uint8_t* base) {
	// 0x26CC70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x26CC78: movss [0x00567E6C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E6Cu, ctx.xmm[0].u32[0]);
	// 0x26CC80: ret
	return;
}

void sub_26CC90(X86Context& ctx, uint8_t* base) {
	// 0x26CC90: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x26CC98: movss [0x00567E50], xmm0
	X86_MEM_WRITE_u32(base, 0x567E50u, ctx.xmm[0].u32[0]);
	// 0x26CCA0: ret
	return;
}

void sub_26CCB0(X86Context& ctx, uint8_t* base) {
	// 0x26CCB0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x26CCB8: movss [0x00567DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x567DF8u, ctx.xmm[0].u32[0]);
	// 0x26CCC0: ret
	return;
}

void sub_26CCD0(X86Context& ctx, uint8_t* base) {
	// 0x26CCD0: movss xmm0, dword ptr [0x00567E14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E14u);
	// 0x26CCD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26CCE0: movss [0x00567DEC], xmm0
	X86_MEM_WRITE_u32(base, 0x567DECu, ctx.xmm[0].u32[0]);
	// 0x26CCE8: ret
	return;
}

void sub_26CCF0(X86Context& ctx, uint8_t* base) {
	// 0x26CCF0: movss xmm0, dword ptr [0x00567E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E6Cu);
	// 0x26CCF8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x26CD00: movss [0x00567E34], xmm0
	X86_MEM_WRITE_u32(base, 0x567E34u, ctx.xmm[0].u32[0]);
	// 0x26CD08: ret
	return;
}

void sub_26CD10(X86Context& ctx, uint8_t* base) {
	// 0x26CD10: movss xmm0, dword ptr [0x00567DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DECu);
	// 0x26CD18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x26CD20: movss [0x00567E48], xmm0
	X86_MEM_WRITE_u32(base, 0x567E48u, ctx.xmm[0].u32[0]);
	// 0x26CD28: ret
	return;
}

void sub_26CD30(X86Context& ctx, uint8_t* base) {
	// 0x26CD30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26CD38: movss [0x00567DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x567DE4u, ctx.xmm[0].u32[0]);
	// 0x26CD40: ret
	return;
}

void sub_26CD50(X86Context& ctx, uint8_t* base) {
	// 0x26CD50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x26CD58: movss [0x00567E18], xmm0
	X86_MEM_WRITE_u32(base, 0x567E18u, ctx.xmm[0].u32[0]);
	// 0x26CD60: ret
	return;
}

void sub_26CD70(X86Context& ctx, uint8_t* base) {
	// 0x26CD70: movss xmm0, dword ptr [0x00567E14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E14u);
	// 0x26CD78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26CD80: movss [0x00567E24], xmm0
	X86_MEM_WRITE_u32(base, 0x567E24u, ctx.xmm[0].u32[0]);
	// 0x26CD88: ret
	return;
}

void sub_26CD90(X86Context& ctx, uint8_t* base) {
	// 0x26CD90: movss xmm0, dword ptr [0x00567E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E6Cu);
	// 0x26CD98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x26CDA0: movss [0x00567E70], xmm0
	X86_MEM_WRITE_u32(base, 0x567E70u, ctx.xmm[0].u32[0]);
	// 0x26CDA8: ret
	return;
}

void sub_26CDB0(X86Context& ctx, uint8_t* base) {
	// 0x26CDB0: movss xmm0, dword ptr [0x00567E24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E24u);
	// 0x26CDB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26CDC0: movss [0x00567E5C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E5Cu, ctx.xmm[0].u32[0]);
	// 0x26CDC8: ret
	return;
}

void sub_26CDD0(X86Context& ctx, uint8_t* base) {
	// 0x26CDD0: movss xmm0, dword ptr [0x00567E70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E70u);
	// 0x26CDD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26CDE0: movss [0x00567E80], xmm0
	X86_MEM_WRITE_u32(base, 0x567E80u, ctx.xmm[0].u32[0]);
	// 0x26CDE8: ret
	return;
}

void sub_26CDF0(X86Context& ctx, uint8_t* base) {
	// 0x26CDF0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x26CDF8: movss [0x00567DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x567DF0u, ctx.xmm[0].u32[0]);
	// 0x26CE00: ret
	return;
}

void sub_26CE10(X86Context& ctx, uint8_t* base) {
	// 0x26CE10: movss xmm0, dword ptr [0x00567E14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E14u);
	// 0x26CE18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26CE20: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x26CE28: movss [0x00567E68], xmm0
	X86_MEM_WRITE_u32(base, 0x567E68u, ctx.xmm[0].u32[0]);
	// 0x26CE30: ret
	return;
}

void sub_26CE40(X86Context& ctx, uint8_t* base) {
	// 0x26CE40: movss xmm0, dword ptr [0x00567E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E6Cu);
	// 0x26CE48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26CE50: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x26CE58: movss [0x00567E08], xmm0
	X86_MEM_WRITE_u32(base, 0x567E08u, ctx.xmm[0].u32[0]);
	// 0x26CE60: ret
	return;
}

void sub_26CE70(X86Context& ctx, uint8_t* base) {
	// 0x26CE70: movss xmm0, dword ptr [0x00567E14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E14u);
	// 0x26CE78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26CE80: movss [0x00567E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E0Cu, ctx.xmm[0].u32[0]);
	// 0x26CE88: ret
	return;
}

void sub_26CE90(X86Context& ctx, uint8_t* base) {
	// 0x26CE90: movss xmm0, dword ptr [0x00567E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E6Cu);
	// 0x26CE98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x26CEA0: movss [0x00567E74], xmm0
	X86_MEM_WRITE_u32(base, 0x567E74u, ctx.xmm[0].u32[0]);
	// 0x26CEA8: ret
	return;
}

void sub_26CEB0(X86Context& ctx, uint8_t* base) {
	// 0x26CEB0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x26CEB8: movss [0x00567DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x567DF4u, ctx.xmm[0].u32[0]);
	// 0x26CEC0: ret
	return;
}

void sub_26CED0(X86Context& ctx, uint8_t* base) {
	// 0x26CED0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x26CED8: movss [0x00567E20], xmm0
	X86_MEM_WRITE_u32(base, 0x567E20u, ctx.xmm[0].u32[0]);
	// 0x26CEE0: ret
	return;
}

void sub_26CEF0(X86Context& ctx, uint8_t* base) {
	// 0x26CEF0: movss xmm0, dword ptr [0x00567DF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567DF4u);
	// 0x26CEF8: movss [0x00567E88], xmm0
	X86_MEM_WRITE_u32(base, 0x567E88u, ctx.xmm[0].u32[0]);
	// 0x26CF00: ret
	return;
}

void sub_26CF10(X86Context& ctx, uint8_t* base) {
	// 0x26CF10: movss xmm0, dword ptr [0x00567E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E6Cu);
	// 0x26CF18: subss xmm0, [0x00567DF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567DF4u);
	// 0x26CF20: movss [0x00567E4C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E4Cu, ctx.xmm[0].u32[0]);
	// 0x26CF28: ret
	return;
}

void sub_26CF30(X86Context& ctx, uint8_t* base) {
	// 0x26CF30: movss xmm0, dword ptr [0x00567E4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E4Cu);
	// 0x26CF38: subss xmm0, [0x00567E20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x567E20u);
	// 0x26CF40: movss [0x00567E44], xmm0
	X86_MEM_WRITE_u32(base, 0x567E44u, ctx.xmm[0].u32[0]);
	// 0x26CF48: ret
	return;
}

void sub_26CF50(X86Context& ctx, uint8_t* base) {
	// 0x26CF50: movss xmm0, dword ptr [0x00567E74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E74u);
	// 0x26CF58: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x26CF60: movss [0x00567E30], xmm0
	X86_MEM_WRITE_u32(base, 0x567E30u, ctx.xmm[0].u32[0]);
	// 0x26CF68: ret
	return;
}

void sub_26CF70(X86Context& ctx, uint8_t* base) {
	// 0x26CF70: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x26CF78: movss [0x00567E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x567E1Cu, ctx.xmm[0].u32[0]);
	// 0x26CF80: ret
	return;
}

void sub_26CF90(X86Context& ctx, uint8_t* base) {
	// 0x26CF90: movss xmm0, dword ptr [0x00567E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x567E30u);
	// 0x26CF98: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x26CFA0: movss [0x00567E64], xmm0
	X86_MEM_WRITE_u32(base, 0x567E64u, ctx.xmm[0].u32[0]);
	// 0x26CFA8: ret
	return;
}

void sub_26CFB0(X86Context& ctx, uint8_t* base) {
	// 0x26CFB0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x26CFB8: movss [0x00567E38], xmm0
	X86_MEM_WRITE_u32(base, 0x567E38u, ctx.xmm[0].u32[0]);
	// 0x26CFC0: ret
	return;
}

void sub_26CFD0(X86Context& ctx, uint8_t* base) {
	// 0x26CFD0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x26CFD8: movss [0x00567E10], xmm0
	X86_MEM_WRITE_u32(base, 0x567E10u, ctx.xmm[0].u32[0]);
	// 0x26CFE0: ret
	return;
}

void sub_26CFF0(X86Context& ctx, uint8_t* base) {
	// 0x26CFF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x26CFF8: movss [0x00567EF0], xmm0
	X86_MEM_WRITE_u32(base, 0x567EF0u, ctx.xmm[0].u32[0]);
	// 0x26D000: ret
	return;
}

void sub_26D010(X86Context& ctx, uint8_t* base) {
	// 0x26D010: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x26D018: movss [0x00567F0C], xmm0
	X86_MEM_WRITE_u32(base, 0x567F0Cu, ctx.xmm[0].u32[0]);
	// 0x26D020: ret
	return;
}

void sub_26D030(X86Context& ctx, uint8_t* base) {
	// 0x26D030: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x26D038: movss [0x00567EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x567EE0u, ctx.xmm[0].u32[0]);
	// 0x26D040: ret
	return;
}

void sub_26D050(X86Context& ctx, uint8_t* base) {
	// 0x26D050: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x26D058: movss [0x00567E94], xmm0
	X86_MEM_WRITE_u32(base, 0x567E94u, ctx.xmm[0].u32[0]);
	// 0x26D060: ret
	return;
}

void sub_26D070(X86Context& ctx, uint8_t* base) {
	// 0x26D070: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x26D078: movss [0x00567EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x567EF4u, ctx.xmm[0].u32[0]);
	// 0x26D080: ret
	return;
}

