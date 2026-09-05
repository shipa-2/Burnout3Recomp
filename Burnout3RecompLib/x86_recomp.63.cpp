#include "x86_recomp_shared.h"

void sub_2A0320(X86Context& ctx, uint8_t* base) {
	// 0x2A0320: movss xmm0, dword ptr [0x0056F95C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F95Cu);
	// 0x2A0328: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A0330: movss [0x0056F91C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F91Cu, ctx.xmm[0].u32[0]);
	// 0x2A0338: ret
	return;
}

void sub_2A0340(X86Context& ctx, uint8_t* base) {
	// 0x2A0340: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A0348: movss [0x0056F908], xmm0
	X86_MEM_WRITE_u32(base, 0x56F908u, ctx.xmm[0].u32[0]);
	// 0x2A0350: ret
	return;
}

void sub_2A0360(X86Context& ctx, uint8_t* base) {
	// 0x2A0360: movss xmm0, dword ptr [0x0056F91C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F91Cu);
	// 0x2A0368: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A0370: movss [0x0056F94C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F94Cu, ctx.xmm[0].u32[0]);
	// 0x2A0378: ret
	return;
}

void sub_2A0380(X86Context& ctx, uint8_t* base) {
	// 0x2A0380: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A0388: movss [0x0056F9D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9D0u, ctx.xmm[0].u32[0]);
	// 0x2A0390: ret
	return;
}

void sub_2A03A0(X86Context& ctx, uint8_t* base) {
	// 0x2A03A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A03A8: movss [0x0056F9EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9ECu, ctx.xmm[0].u32[0]);
	// 0x2A03B0: ret
	return;
}

void sub_2A03C0(X86Context& ctx, uint8_t* base) {
	// 0x2A03C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A03C8: movss [0x0056F9C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9C4u, ctx.xmm[0].u32[0]);
	// 0x2A03D0: ret
	return;
}

void sub_2A03E0(X86Context& ctx, uint8_t* base) {
	// 0x2A03E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A03E8: movss [0x0056F97C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F97Cu, ctx.xmm[0].u32[0]);
	// 0x2A03F0: ret
	return;
}

void sub_2A0400(X86Context& ctx, uint8_t* base) {
	// 0x2A0400: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A0408: movss [0x0056F9D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9D4u, ctx.xmm[0].u32[0]);
	// 0x2A0410: ret
	return;
}

void sub_2A0420(X86Context& ctx, uint8_t* base) {
	// 0x2A0420: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A0428: movss [0x0056F998], xmm0
	X86_MEM_WRITE_u32(base, 0x56F998u, ctx.xmm[0].u32[0]);
	// 0x2A0430: ret
	return;
}

void sub_2A0440(X86Context& ctx, uint8_t* base) {
	// 0x2A0440: movss xmm0, dword ptr [0x0056F9D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9D4u);
	// 0x2A0448: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A0450: movss [0x0056FA0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA0Cu, ctx.xmm[0].u32[0]);
	// 0x2A0458: ret
	return;
}

void sub_2A0460(X86Context& ctx, uint8_t* base) {
	// 0x2A0460: movss xmm0, dword ptr [0x0056F998]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F998u);
	// 0x2A0468: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A0470: movss [0x0056F9F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9F4u, ctx.xmm[0].u32[0]);
	// 0x2A0478: ret
	return;
}

void sub_2A0480(X86Context& ctx, uint8_t* base) {
	// 0x2A0480: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A0488: movss [0x0056FA24], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA24u, ctx.xmm[0].u32[0]);
	// 0x2A0490: ret
	return;
}

void sub_2A04A0(X86Context& ctx, uint8_t* base) {
	// 0x2A04A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A04A8: movss [0x0056FA10], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA10u, ctx.xmm[0].u32[0]);
	// 0x2A04B0: ret
	return;
}

void sub_2A04C0(X86Context& ctx, uint8_t* base) {
	// 0x2A04C0: movss xmm0, dword ptr [0x0056FA10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA10u);
	// 0x2A04C8: movss [0x0056FA20], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA20u, ctx.xmm[0].u32[0]);
	// 0x2A04D0: ret
	return;
}

void sub_2A04E0(X86Context& ctx, uint8_t* base) {
	// 0x2A04E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A04E8: movss [0x0056F984], xmm0
	X86_MEM_WRITE_u32(base, 0x56F984u, ctx.xmm[0].u32[0]);
	// 0x2A04F0: ret
	return;
}

void sub_2A0500(X86Context& ctx, uint8_t* base) {
	// 0x2A0500: movss xmm0, dword ptr [0x0056F998]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F998u);
	// 0x2A0508: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A0510: movss [0x0056FA18], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA18u, ctx.xmm[0].u32[0]);
	// 0x2A0518: ret
	return;
}

void sub_2A0520(X86Context& ctx, uint8_t* base) {
	// 0x2A0520: movss xmm0, dword ptr [0x0056F998]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F998u);
	// 0x2A0528: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A0530: movss [0x0056F9C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9C0u, ctx.xmm[0].u32[0]);
	// 0x2A0538: ret
	return;
}

void sub_2A0540(X86Context& ctx, uint8_t* base) {
	// 0x2A0540: movss xmm0, dword ptr [0x0056F998]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F998u);
	// 0x2A0548: subss xmm0, [0x0056F9C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F9C0u);
	// 0x2A0550: movss [0x0056F9A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9A0u, ctx.xmm[0].u32[0]);
	// 0x2A0558: ret
	return;
}

void sub_2A0560(X86Context& ctx, uint8_t* base) {
	// 0x2A0560: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A0568: movss [0x0056F9E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9E8u, ctx.xmm[0].u32[0]);
	// 0x2A0570: ret
	return;
}

void sub_2A0580(X86Context& ctx, uint8_t* base) {
	// 0x2A0580: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A0588: movss [0x0056F99C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F99Cu, ctx.xmm[0].u32[0]);
	// 0x2A0590: ret
	return;
}

void sub_2A05A0(X86Context& ctx, uint8_t* base) {
	// 0x2A05A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A05A8: movss [0x0056F9AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9ACu, ctx.xmm[0].u32[0]);
	// 0x2A05B0: ret
	return;
}

void sub_2A05C0(X86Context& ctx, uint8_t* base) {
	// 0x2A05C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A05C8: movss [0x0056FA00], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA00u, ctx.xmm[0].u32[0]);
	// 0x2A05D0: ret
	return;
}

void sub_2A05E0(X86Context& ctx, uint8_t* base) {
	// 0x2A05E0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A05E8: movss [0x0056F9E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9E4u, ctx.xmm[0].u32[0]);
	// 0x2A05F0: ret
	return;
}

void sub_2A0600(X86Context& ctx, uint8_t* base) {
	// 0x2A0600: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A0608: movss [0x0056F994], xmm0
	X86_MEM_WRITE_u32(base, 0x56F994u, ctx.xmm[0].u32[0]);
	// 0x2A0610: ret
	return;
}

void sub_2A0620(X86Context& ctx, uint8_t* base) {
	// 0x2A0620: movss xmm0, dword ptr [0x0056F9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9ACu);
	// 0x2A0628: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A0630: movss [0x0056F988], xmm0
	X86_MEM_WRITE_u32(base, 0x56F988u, ctx.xmm[0].u32[0]);
	// 0x2A0638: ret
	return;
}

void sub_2A0640(X86Context& ctx, uint8_t* base) {
	// 0x2A0640: movss xmm0, dword ptr [0x0056FA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA00u);
	// 0x2A0648: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A0650: movss [0x0056F9CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9CCu, ctx.xmm[0].u32[0]);
	// 0x2A0658: ret
	return;
}

void sub_2A0660(X86Context& ctx, uint8_t* base) {
	// 0x2A0660: movss xmm0, dword ptr [0x0056F988]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F988u);
	// 0x2A0668: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A0670: movss [0x0056F9DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9DCu, ctx.xmm[0].u32[0]);
	// 0x2A0678: ret
	return;
}

void sub_2A0680(X86Context& ctx, uint8_t* base) {
	// 0x2A0680: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A0688: movss [0x0056F980], xmm0
	X86_MEM_WRITE_u32(base, 0x56F980u, ctx.xmm[0].u32[0]);
	// 0x2A0690: ret
	return;
}

void sub_2A06A0(X86Context& ctx, uint8_t* base) {
	// 0x2A06A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A06A8: movss [0x0056F9B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9B0u, ctx.xmm[0].u32[0]);
	// 0x2A06B0: ret
	return;
}

void sub_2A06C0(X86Context& ctx, uint8_t* base) {
	// 0x2A06C0: movss xmm0, dword ptr [0x0056F9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9ACu);
	// 0x2A06C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A06D0: movss [0x0056F9BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9BCu, ctx.xmm[0].u32[0]);
	// 0x2A06D8: ret
	return;
}

void sub_2A06E0(X86Context& ctx, uint8_t* base) {
	// 0x2A06E0: movss xmm0, dword ptr [0x0056FA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA00u);
	// 0x2A06E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A06F0: movss [0x0056FA04], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA04u, ctx.xmm[0].u32[0]);
	// 0x2A06F8: ret
	return;
}

void sub_2A0700(X86Context& ctx, uint8_t* base) {
	// 0x2A0700: movss xmm0, dword ptr [0x0056F9BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9BCu);
	// 0x2A0708: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0710: movss [0x0056F9F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9F0u, ctx.xmm[0].u32[0]);
	// 0x2A0718: ret
	return;
}

void sub_2A0720(X86Context& ctx, uint8_t* base) {
	// 0x2A0720: movss xmm0, dword ptr [0x0056FA04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA04u);
	// 0x2A0728: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0730: movss [0x0056FA14], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA14u, ctx.xmm[0].u32[0]);
	// 0x2A0738: ret
	return;
}

void sub_2A0740(X86Context& ctx, uint8_t* base) {
	// 0x2A0740: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A0748: movss [0x0056F98C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F98Cu, ctx.xmm[0].u32[0]);
	// 0x2A0750: ret
	return;
}

void sub_2A0760(X86Context& ctx, uint8_t* base) {
	// 0x2A0760: movss xmm0, dword ptr [0x0056F9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9ACu);
	// 0x2A0768: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0770: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A0778: movss [0x0056F9FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9FCu, ctx.xmm[0].u32[0]);
	// 0x2A0780: ret
	return;
}

void sub_2A0790(X86Context& ctx, uint8_t* base) {
	// 0x2A0790: movss xmm0, dword ptr [0x0056FA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA00u);
	// 0x2A0798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A07A0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A07A8: movss [0x0056F9A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9A4u, ctx.xmm[0].u32[0]);
	// 0x2A07B0: ret
	return;
}

void sub_2A07C0(X86Context& ctx, uint8_t* base) {
	// 0x2A07C0: movss xmm0, dword ptr [0x0056F9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9ACu);
	// 0x2A07C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A07D0: movss [0x0056F9A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9A8u, ctx.xmm[0].u32[0]);
	// 0x2A07D8: ret
	return;
}

void sub_2A07E0(X86Context& ctx, uint8_t* base) {
	// 0x2A07E0: movss xmm0, dword ptr [0x0056FA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA00u);
	// 0x2A07E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A07F0: movss [0x0056FA08], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA08u, ctx.xmm[0].u32[0]);
	// 0x2A07F8: ret
	return;
}

void sub_2A0800(X86Context& ctx, uint8_t* base) {
	// 0x2A0800: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A0808: movss [0x0056F990], xmm0
	X86_MEM_WRITE_u32(base, 0x56F990u, ctx.xmm[0].u32[0]);
	// 0x2A0810: ret
	return;
}

void sub_2A0820(X86Context& ctx, uint8_t* base) {
	// 0x2A0820: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A0828: movss [0x0056F9B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9B8u, ctx.xmm[0].u32[0]);
	// 0x2A0830: ret
	return;
}

void sub_2A0840(X86Context& ctx, uint8_t* base) {
	// 0x2A0840: movss xmm0, dword ptr [0x0056F990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F990u);
	// 0x2A0848: movss [0x0056FA1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA1Cu, ctx.xmm[0].u32[0]);
	// 0x2A0850: ret
	return;
}

void sub_2A0860(X86Context& ctx, uint8_t* base) {
	// 0x2A0860: movss xmm0, dword ptr [0x0056FA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA00u);
	// 0x2A0868: subss xmm0, [0x0056F990]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F990u);
	// 0x2A0870: movss [0x0056F9E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9E0u, ctx.xmm[0].u32[0]);
	// 0x2A0878: ret
	return;
}

void sub_2A0880(X86Context& ctx, uint8_t* base) {
	// 0x2A0880: movss xmm0, dword ptr [0x0056F9E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9E0u);
	// 0x2A0888: subss xmm0, [0x0056F9B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F9B8u);
	// 0x2A0890: movss [0x0056F9D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9D8u, ctx.xmm[0].u32[0]);
	// 0x2A0898: ret
	return;
}

void sub_2A08A0(X86Context& ctx, uint8_t* base) {
	// 0x2A08A0: movss xmm0, dword ptr [0x0056FA08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA08u);
	// 0x2A08A8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A08B0: movss [0x0056F9C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9C8u, ctx.xmm[0].u32[0]);
	// 0x2A08B8: ret
	return;
}

void sub_2A08C0(X86Context& ctx, uint8_t* base) {
	// 0x2A08C0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A08C8: movss [0x0056F9B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9B4u, ctx.xmm[0].u32[0]);
	// 0x2A08D0: ret
	return;
}

void sub_2A08E0(X86Context& ctx, uint8_t* base) {
	// 0x2A08E0: movss xmm0, dword ptr [0x0056F9C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F9C8u);
	// 0x2A08E8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A08F0: movss [0x0056F9F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F9F8u, ctx.xmm[0].u32[0]);
	// 0x2A08F8: ret
	return;
}

void sub_2A0900(X86Context& ctx, uint8_t* base) {
	// 0x2A0900: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A0908: movss [0x0056FA84], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA84u, ctx.xmm[0].u32[0]);
	// 0x2A0910: ret
	return;
}

void sub_2A0920(X86Context& ctx, uint8_t* base) {
	// 0x2A0920: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A0928: movss [0x0056FAA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAA0u, ctx.xmm[0].u32[0]);
	// 0x2A0930: ret
	return;
}

void sub_2A0940(X86Context& ctx, uint8_t* base) {
	// 0x2A0940: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A0948: movss [0x0056FA74], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA74u, ctx.xmm[0].u32[0]);
	// 0x2A0950: ret
	return;
}

void sub_2A0960(X86Context& ctx, uint8_t* base) {
	// 0x2A0960: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A0968: movss [0x0056FA28], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA28u, ctx.xmm[0].u32[0]);
	// 0x2A0970: ret
	return;
}

void sub_2A0980(X86Context& ctx, uint8_t* base) {
	// 0x2A0980: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A0988: movss [0x0056FA88], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA88u, ctx.xmm[0].u32[0]);
	// 0x2A0990: ret
	return;
}

void sub_2A09A0(X86Context& ctx, uint8_t* base) {
	// 0x2A09A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A09A8: movss [0x0056FA44], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA44u, ctx.xmm[0].u32[0]);
	// 0x2A09B0: ret
	return;
}

void sub_2A09C0(X86Context& ctx, uint8_t* base) {
	// 0x2A09C0: movss xmm0, dword ptr [0x0056FA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA88u);
	// 0x2A09C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A09D0: movss [0x0056FAC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAC0u, ctx.xmm[0].u32[0]);
	// 0x2A09D8: ret
	return;
}

void sub_2A09E0(X86Context& ctx, uint8_t* base) {
	// 0x2A09E0: movss xmm0, dword ptr [0x0056FA44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA44u);
	// 0x2A09E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A09F0: movss [0x0056FAA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAA8u, ctx.xmm[0].u32[0]);
	// 0x2A09F8: ret
	return;
}

void sub_2A0A00(X86Context& ctx, uint8_t* base) {
	// 0x2A0A00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A0A08: movss [0x0056FAD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAD8u, ctx.xmm[0].u32[0]);
	// 0x2A0A10: ret
	return;
}

void sub_2A0A20(X86Context& ctx, uint8_t* base) {
	// 0x2A0A20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A0A28: movss [0x0056FAC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAC4u, ctx.xmm[0].u32[0]);
	// 0x2A0A30: ret
	return;
}

void sub_2A0A40(X86Context& ctx, uint8_t* base) {
	// 0x2A0A40: movss xmm0, dword ptr [0x0056FAC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAC4u);
	// 0x2A0A48: movss [0x0056FAD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAD4u, ctx.xmm[0].u32[0]);
	// 0x2A0A50: ret
	return;
}

void sub_2A0A60(X86Context& ctx, uint8_t* base) {
	// 0x2A0A60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A0A68: movss [0x0056FA30], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA30u, ctx.xmm[0].u32[0]);
	// 0x2A0A70: ret
	return;
}

void sub_2A0A80(X86Context& ctx, uint8_t* base) {
	// 0x2A0A80: movss xmm0, dword ptr [0x0056FA44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA44u);
	// 0x2A0A88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A0A90: movss [0x0056FACC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FACCu, ctx.xmm[0].u32[0]);
	// 0x2A0A98: ret
	return;
}

void sub_2A0AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A0AA0: movss xmm0, dword ptr [0x0056FA44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA44u);
	// 0x2A0AA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A0AB0: movss [0x0056FA70], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA70u, ctx.xmm[0].u32[0]);
	// 0x2A0AB8: ret
	return;
}

void sub_2A0AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A0AC0: movss xmm0, dword ptr [0x0056FA44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA44u);
	// 0x2A0AC8: subss xmm0, [0x0056FA70]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FA70u);
	// 0x2A0AD0: movss [0x0056FA4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA4Cu, ctx.xmm[0].u32[0]);
	// 0x2A0AD8: ret
	return;
}

void sub_2A0AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A0AE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A0AE8: movss [0x0056FA9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA9Cu, ctx.xmm[0].u32[0]);
	// 0x2A0AF0: ret
	return;
}

void sub_2A0B00(X86Context& ctx, uint8_t* base) {
	// 0x2A0B00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A0B08: movss [0x0056FA48], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA48u, ctx.xmm[0].u32[0]);
	// 0x2A0B10: ret
	return;
}

void sub_2A0B20(X86Context& ctx, uint8_t* base) {
	// 0x2A0B20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A0B28: movss [0x0056FA5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA5Cu, ctx.xmm[0].u32[0]);
	// 0x2A0B30: ret
	return;
}

void sub_2A0B40(X86Context& ctx, uint8_t* base) {
	// 0x2A0B40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A0B48: movss [0x0056FAB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAB4u, ctx.xmm[0].u32[0]);
	// 0x2A0B50: ret
	return;
}

void sub_2A0B60(X86Context& ctx, uint8_t* base) {
	// 0x2A0B60: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A0B68: movss [0x0056FA98], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA98u, ctx.xmm[0].u32[0]);
	// 0x2A0B70: ret
	return;
}

void sub_2A0B80(X86Context& ctx, uint8_t* base) {
	// 0x2A0B80: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A0B88: movss [0x0056FA40], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA40u, ctx.xmm[0].u32[0]);
	// 0x2A0B90: ret
	return;
}

void sub_2A0BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A0BA0: movss xmm0, dword ptr [0x0056FA5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA5Cu);
	// 0x2A0BA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A0BB0: movss [0x0056FA34], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA34u, ctx.xmm[0].u32[0]);
	// 0x2A0BB8: ret
	return;
}

void sub_2A0BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A0BC0: movss xmm0, dword ptr [0x0056FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAB4u);
	// 0x2A0BC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A0BD0: movss [0x0056FA7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA7Cu, ctx.xmm[0].u32[0]);
	// 0x2A0BD8: ret
	return;
}

void sub_2A0BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A0BE0: movss xmm0, dword ptr [0x0056FA34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA34u);
	// 0x2A0BE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A0BF0: movss [0x0056FA90], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA90u, ctx.xmm[0].u32[0]);
	// 0x2A0BF8: ret
	return;
}

void sub_2A0C00(X86Context& ctx, uint8_t* base) {
	// 0x2A0C00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A0C08: movss [0x0056FA2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA2Cu, ctx.xmm[0].u32[0]);
	// 0x2A0C10: ret
	return;
}

void sub_2A0C20(X86Context& ctx, uint8_t* base) {
	// 0x2A0C20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A0C28: movss [0x0056FA60], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA60u, ctx.xmm[0].u32[0]);
	// 0x2A0C30: ret
	return;
}

void sub_2A0C40(X86Context& ctx, uint8_t* base) {
	// 0x2A0C40: movss xmm0, dword ptr [0x0056FA5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA5Cu);
	// 0x2A0C48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A0C50: movss [0x0056FA6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA6Cu, ctx.xmm[0].u32[0]);
	// 0x2A0C58: ret
	return;
}

void sub_2A0C60(X86Context& ctx, uint8_t* base) {
	// 0x2A0C60: movss xmm0, dword ptr [0x0056FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAB4u);
	// 0x2A0C68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A0C70: movss [0x0056FAB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAB8u, ctx.xmm[0].u32[0]);
	// 0x2A0C78: ret
	return;
}

void sub_2A0C80(X86Context& ctx, uint8_t* base) {
	// 0x2A0C80: movss xmm0, dword ptr [0x0056FA6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA6Cu);
	// 0x2A0C88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0C90: movss [0x0056FAA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAA4u, ctx.xmm[0].u32[0]);
	// 0x2A0C98: ret
	return;
}

void sub_2A0CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A0CA0: movss xmm0, dword ptr [0x0056FAB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAB8u);
	// 0x2A0CA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0CB0: movss [0x0056FAC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAC8u, ctx.xmm[0].u32[0]);
	// 0x2A0CB8: ret
	return;
}

void sub_2A0CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A0CC0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A0CC8: movss [0x0056FA38], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA38u, ctx.xmm[0].u32[0]);
	// 0x2A0CD0: ret
	return;
}

void sub_2A0CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A0CE0: movss xmm0, dword ptr [0x0056FA5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA5Cu);
	// 0x2A0CE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0CF0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A0CF8: movss [0x0056FAB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAB0u, ctx.xmm[0].u32[0]);
	// 0x2A0D00: ret
	return;
}

void sub_2A0D10(X86Context& ctx, uint8_t* base) {
	// 0x2A0D10: movss xmm0, dword ptr [0x0056FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAB4u);
	// 0x2A0D18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0D20: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A0D28: movss [0x0056FA50], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA50u, ctx.xmm[0].u32[0]);
	// 0x2A0D30: ret
	return;
}

void sub_2A0D40(X86Context& ctx, uint8_t* base) {
	// 0x2A0D40: movss xmm0, dword ptr [0x0056FA5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA5Cu);
	// 0x2A0D48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0D50: movss [0x0056FA54], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA54u, ctx.xmm[0].u32[0]);
	// 0x2A0D58: ret
	return;
}

void sub_2A0D60(X86Context& ctx, uint8_t* base) {
	// 0x2A0D60: movss xmm0, dword ptr [0x0056FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAB4u);
	// 0x2A0D68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A0D70: movss [0x0056FABC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FABCu, ctx.xmm[0].u32[0]);
	// 0x2A0D78: ret
	return;
}

void sub_2A0D80(X86Context& ctx, uint8_t* base) {
	// 0x2A0D80: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A0D88: movss [0x0056FA3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA3Cu, ctx.xmm[0].u32[0]);
	// 0x2A0D90: ret
	return;
}

void sub_2A0DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A0DA0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A0DA8: movss [0x0056FA68], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA68u, ctx.xmm[0].u32[0]);
	// 0x2A0DB0: ret
	return;
}

void sub_2A0DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A0DC0: movss xmm0, dword ptr [0x0056FA3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA3Cu);
	// 0x2A0DC8: movss [0x0056FAD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAD0u, ctx.xmm[0].u32[0]);
	// 0x2A0DD0: ret
	return;
}

void sub_2A0DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A0DE0: movss xmm0, dword ptr [0x0056FAB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAB4u);
	// 0x2A0DE8: subss xmm0, [0x0056FA3C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FA3Cu);
	// 0x2A0DF0: movss [0x0056FA94], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA94u, ctx.xmm[0].u32[0]);
	// 0x2A0DF8: ret
	return;
}

void sub_2A0E00(X86Context& ctx, uint8_t* base) {
	// 0x2A0E00: movss xmm0, dword ptr [0x0056FA94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA94u);
	// 0x2A0E08: subss xmm0, [0x0056FA68]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FA68u);
	// 0x2A0E10: movss [0x0056FA8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA8Cu, ctx.xmm[0].u32[0]);
	// 0x2A0E18: ret
	return;
}

void sub_2A0E20(X86Context& ctx, uint8_t* base) {
	// 0x2A0E20: movss xmm0, dword ptr [0x0056FABC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FABCu);
	// 0x2A0E28: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A0E30: movss [0x0056FA78], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA78u, ctx.xmm[0].u32[0]);
	// 0x2A0E38: ret
	return;
}

void sub_2A0E40(X86Context& ctx, uint8_t* base) {
	// 0x2A0E40: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A0E48: movss [0x0056FA64], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA64u, ctx.xmm[0].u32[0]);
	// 0x2A0E50: ret
	return;
}

void sub_2A0E60(X86Context& ctx, uint8_t* base) {
	// 0x2A0E60: movss xmm0, dword ptr [0x0056FA78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FA78u);
	// 0x2A0E68: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A0E70: movss [0x0056FAAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAACu, ctx.xmm[0].u32[0]);
	// 0x2A0E78: ret
	return;
}

void sub_2A0E80(X86Context& ctx, uint8_t* base) {
	// 0x2A0E80: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2A0E88: movss [0x0056FA80], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA80u, ctx.xmm[0].u32[0]);
	// 0x2A0E90: ret
	return;
}

void sub_2A0EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A0EA0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2A0EA8: movss [0x0056FA58], xmm0
	X86_MEM_WRITE_u32(base, 0x56FA58u, ctx.xmm[0].u32[0]);
	// 0x2A0EB0: ret
	return;
}

void sub_2A0EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A0EC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A0EC8: movss [0x0056FB34], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB34u, ctx.xmm[0].u32[0]);
	// 0x2A0ED0: ret
	return;
}

void sub_2A0EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A0EE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A0EE8: movss [0x0056FB50], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB50u, ctx.xmm[0].u32[0]);
	// 0x2A0EF0: ret
	return;
}

void sub_2A0F00(X86Context& ctx, uint8_t* base) {
	// 0x2A0F00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A0F08: movss [0x0056FB24], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB24u, ctx.xmm[0].u32[0]);
	// 0x2A0F10: ret
	return;
}

void sub_2A0F20(X86Context& ctx, uint8_t* base) {
	// 0x2A0F20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A0F28: movss [0x0056FADC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FADCu, ctx.xmm[0].u32[0]);
	// 0x2A0F30: ret
	return;
}

void sub_2A0F40(X86Context& ctx, uint8_t* base) {
	// 0x2A0F40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A0F48: movss [0x0056FB38], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB38u, ctx.xmm[0].u32[0]);
	// 0x2A0F50: ret
	return;
}

void sub_2A0F60(X86Context& ctx, uint8_t* base) {
	// 0x2A0F60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A0F68: movss [0x0056FAF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAF8u, ctx.xmm[0].u32[0]);
	// 0x2A0F70: ret
	return;
}

void sub_2A0F80(X86Context& ctx, uint8_t* base) {
	// 0x2A0F80: movss xmm0, dword ptr [0x0056FB38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB38u);
	// 0x2A0F88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A0F90: movss [0x0056FB70], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB70u, ctx.xmm[0].u32[0]);
	// 0x2A0F98: ret
	return;
}

void sub_2A0FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A0FA0: movss xmm0, dword ptr [0x0056FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAF8u);
	// 0x2A0FA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A0FB0: movss [0x0056FB58], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB58u, ctx.xmm[0].u32[0]);
	// 0x2A0FB8: ret
	return;
}

void sub_2A0FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A0FC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A0FC8: movss [0x0056FB88], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB88u, ctx.xmm[0].u32[0]);
	// 0x2A0FD0: ret
	return;
}

void sub_2A0FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A0FE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A0FE8: movss [0x0056FB74], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB74u, ctx.xmm[0].u32[0]);
	// 0x2A0FF0: ret
	return;
}

void sub_2A1000(X86Context& ctx, uint8_t* base) {
	// 0x2A1000: movss xmm0, dword ptr [0x0056FB74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB74u);
	// 0x2A1008: movss [0x0056FB84], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB84u, ctx.xmm[0].u32[0]);
	// 0x2A1010: ret
	return;
}

void sub_2A1020(X86Context& ctx, uint8_t* base) {
	// 0x2A1020: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A1028: movss [0x0056FAE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAE4u, ctx.xmm[0].u32[0]);
	// 0x2A1030: ret
	return;
}

void sub_2A1040(X86Context& ctx, uint8_t* base) {
	// 0x2A1040: movss xmm0, dword ptr [0x0056FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAF8u);
	// 0x2A1048: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A1050: movss [0x0056FB7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB7Cu, ctx.xmm[0].u32[0]);
	// 0x2A1058: ret
	return;
}

void sub_2A1060(X86Context& ctx, uint8_t* base) {
	// 0x2A1060: movss xmm0, dword ptr [0x0056FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAF8u);
	// 0x2A1068: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A1070: movss [0x0056FB20], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB20u, ctx.xmm[0].u32[0]);
	// 0x2A1078: ret
	return;
}

void sub_2A1080(X86Context& ctx, uint8_t* base) {
	// 0x2A1080: movss xmm0, dword ptr [0x0056FAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAF8u);
	// 0x2A1088: subss xmm0, [0x0056FB20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FB20u);
	// 0x2A1090: movss [0x0056FB00], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB00u, ctx.xmm[0].u32[0]);
	// 0x2A1098: ret
	return;
}

void sub_2A10A0(X86Context& ctx, uint8_t* base) {
	// 0x2A10A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A10A8: movss [0x0056FB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB4Cu, ctx.xmm[0].u32[0]);
	// 0x2A10B0: ret
	return;
}

void sub_2A10C0(X86Context& ctx, uint8_t* base) {
	// 0x2A10C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A10C8: movss [0x0056FAFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAFCu, ctx.xmm[0].u32[0]);
	// 0x2A10D0: ret
	return;
}

void sub_2A10E0(X86Context& ctx, uint8_t* base) {
	// 0x2A10E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A10E8: movss [0x0056FB0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB0Cu, ctx.xmm[0].u32[0]);
	// 0x2A10F0: ret
	return;
}

void sub_2A1100(X86Context& ctx, uint8_t* base) {
	// 0x2A1100: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A1108: movss [0x0056FB64], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB64u, ctx.xmm[0].u32[0]);
	// 0x2A1110: ret
	return;
}

void sub_2A1120(X86Context& ctx, uint8_t* base) {
	// 0x2A1120: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A1128: movss [0x0056FB48], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB48u, ctx.xmm[0].u32[0]);
	// 0x2A1130: ret
	return;
}

void sub_2A1140(X86Context& ctx, uint8_t* base) {
	// 0x2A1140: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A1148: movss [0x0056FAF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAF4u, ctx.xmm[0].u32[0]);
	// 0x2A1150: ret
	return;
}

void sub_2A1160(X86Context& ctx, uint8_t* base) {
	// 0x2A1160: movss xmm0, dword ptr [0x0056FB0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB0Cu);
	// 0x2A1168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1170: movss [0x0056FAE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAE8u, ctx.xmm[0].u32[0]);
	// 0x2A1178: ret
	return;
}

void sub_2A1180(X86Context& ctx, uint8_t* base) {
	// 0x2A1180: movss xmm0, dword ptr [0x0056FB64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB64u);
	// 0x2A1188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A1190: movss [0x0056FB30], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB30u, ctx.xmm[0].u32[0]);
	// 0x2A1198: ret
	return;
}

void sub_2A11A0(X86Context& ctx, uint8_t* base) {
	// 0x2A11A0: movss xmm0, dword ptr [0x0056FAE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAE8u);
	// 0x2A11A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A11B0: movss [0x0056FB40], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB40u, ctx.xmm[0].u32[0]);
	// 0x2A11B8: ret
	return;
}

void sub_2A11C0(X86Context& ctx, uint8_t* base) {
	// 0x2A11C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A11C8: movss [0x0056FAE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAE0u, ctx.xmm[0].u32[0]);
	// 0x2A11D0: ret
	return;
}

void sub_2A11E0(X86Context& ctx, uint8_t* base) {
	// 0x2A11E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A11E8: movss [0x0056FB10], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB10u, ctx.xmm[0].u32[0]);
	// 0x2A11F0: ret
	return;
}

void sub_2A1200(X86Context& ctx, uint8_t* base) {
	// 0x2A1200: movss xmm0, dword ptr [0x0056FB0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB0Cu);
	// 0x2A1208: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A1210: movss [0x0056FB1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB1Cu, ctx.xmm[0].u32[0]);
	// 0x2A1218: ret
	return;
}

void sub_2A1220(X86Context& ctx, uint8_t* base) {
	// 0x2A1220: movss xmm0, dword ptr [0x0056FB64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB64u);
	// 0x2A1228: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A1230: movss [0x0056FB68], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB68u, ctx.xmm[0].u32[0]);
	// 0x2A1238: ret
	return;
}

void sub_2A1240(X86Context& ctx, uint8_t* base) {
	// 0x2A1240: movss xmm0, dword ptr [0x0056FB1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB1Cu);
	// 0x2A1248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1250: movss [0x0056FB54], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB54u, ctx.xmm[0].u32[0]);
	// 0x2A1258: ret
	return;
}

void sub_2A1260(X86Context& ctx, uint8_t* base) {
	// 0x2A1260: movss xmm0, dword ptr [0x0056FB68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB68u);
	// 0x2A1268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1270: movss [0x0056FB78], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB78u, ctx.xmm[0].u32[0]);
	// 0x2A1278: ret
	return;
}

void sub_2A1280(X86Context& ctx, uint8_t* base) {
	// 0x2A1280: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A1288: movss [0x0056FAEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAECu, ctx.xmm[0].u32[0]);
	// 0x2A1290: ret
	return;
}

void sub_2A12A0(X86Context& ctx, uint8_t* base) {
	// 0x2A12A0: movss xmm0, dword ptr [0x0056FB0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB0Cu);
	// 0x2A12A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A12B0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A12B8: movss [0x0056FB60], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB60u, ctx.xmm[0].u32[0]);
	// 0x2A12C0: ret
	return;
}

void sub_2A12D0(X86Context& ctx, uint8_t* base) {
	// 0x2A12D0: movss xmm0, dword ptr [0x0056FB64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB64u);
	// 0x2A12D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A12E0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A12E8: movss [0x0056FB04], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB04u, ctx.xmm[0].u32[0]);
	// 0x2A12F0: ret
	return;
}

void sub_2A1300(X86Context& ctx, uint8_t* base) {
	// 0x2A1300: movss xmm0, dword ptr [0x0056FB0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB0Cu);
	// 0x2A1308: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1310: movss [0x0056FB08], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB08u, ctx.xmm[0].u32[0]);
	// 0x2A1318: ret
	return;
}

void sub_2A1320(X86Context& ctx, uint8_t* base) {
	// 0x2A1320: movss xmm0, dword ptr [0x0056FB64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB64u);
	// 0x2A1328: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1330: movss [0x0056FB6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB6Cu, ctx.xmm[0].u32[0]);
	// 0x2A1338: ret
	return;
}

void sub_2A1340(X86Context& ctx, uint8_t* base) {
	// 0x2A1340: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A1348: movss [0x0056FAF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FAF0u, ctx.xmm[0].u32[0]);
	// 0x2A1350: ret
	return;
}

void sub_2A1360(X86Context& ctx, uint8_t* base) {
	// 0x2A1360: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A1368: movss [0x0056FB18], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB18u, ctx.xmm[0].u32[0]);
	// 0x2A1370: ret
	return;
}

void sub_2A1380(X86Context& ctx, uint8_t* base) {
	// 0x2A1380: movss xmm0, dword ptr [0x0056FAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FAF0u);
	// 0x2A1388: movss [0x0056FB80], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB80u, ctx.xmm[0].u32[0]);
	// 0x2A1390: ret
	return;
}

void sub_2A13A0(X86Context& ctx, uint8_t* base) {
	// 0x2A13A0: movss xmm0, dword ptr [0x0056FB64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB64u);
	// 0x2A13A8: subss xmm0, [0x0056FAF0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FAF0u);
	// 0x2A13B0: movss [0x0056FB44], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB44u, ctx.xmm[0].u32[0]);
	// 0x2A13B8: ret
	return;
}

void sub_2A13C0(X86Context& ctx, uint8_t* base) {
	// 0x2A13C0: movss xmm0, dword ptr [0x0056FB44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB44u);
	// 0x2A13C8: subss xmm0, [0x0056FB18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FB18u);
	// 0x2A13D0: movss [0x0056FB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB3Cu, ctx.xmm[0].u32[0]);
	// 0x2A13D8: ret
	return;
}

void sub_2A13E0(X86Context& ctx, uint8_t* base) {
	// 0x2A13E0: movss xmm0, dword ptr [0x0056FB6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB6Cu);
	// 0x2A13E8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A13F0: movss [0x0056FB28], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB28u, ctx.xmm[0].u32[0]);
	// 0x2A13F8: ret
	return;
}

void sub_2A1400(X86Context& ctx, uint8_t* base) {
	// 0x2A1400: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A1408: movss [0x0056FB14], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB14u, ctx.xmm[0].u32[0]);
	// 0x2A1410: ret
	return;
}

void sub_2A1420(X86Context& ctx, uint8_t* base) {
	// 0x2A1420: movss xmm0, dword ptr [0x0056FB28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FB28u);
	// 0x2A1428: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A1430: movss [0x0056FB5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB5Cu, ctx.xmm[0].u32[0]);
	// 0x2A1438: ret
	return;
}

void sub_2A1440(X86Context& ctx, uint8_t* base) {
	// 0x2A1440: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2A1448: movss [0x0056FB2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB2Cu, ctx.xmm[0].u32[0]);
	// 0x2A1450: ret
	return;
}

void sub_2A1460(X86Context& ctx, uint8_t* base) {
	// 0x2A1460: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A1468: movss [0x0056FBF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBF0u, ctx.xmm[0].u32[0]);
	// 0x2A1470: ret
	return;
}

void sub_2A1480(X86Context& ctx, uint8_t* base) {
	// 0x2A1480: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A1488: movss [0x0056FC0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC0Cu, ctx.xmm[0].u32[0]);
	// 0x2A1490: ret
	return;
}

void sub_2A14A0(X86Context& ctx, uint8_t* base) {
	// 0x2A14A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A14A8: movss [0x0056FBE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBE0u, ctx.xmm[0].u32[0]);
	// 0x2A14B0: ret
	return;
}

void sub_2A14C0(X86Context& ctx, uint8_t* base) {
	// 0x2A14C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A14C8: movss [0x0056FB8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB8Cu, ctx.xmm[0].u32[0]);
	// 0x2A14D0: ret
	return;
}

void sub_2A14E0(X86Context& ctx, uint8_t* base) {
	// 0x2A14E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A14E8: movss [0x0056FBF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBF4u, ctx.xmm[0].u32[0]);
	// 0x2A14F0: ret
	return;
}

void sub_2A1500(X86Context& ctx, uint8_t* base) {
	// 0x2A1500: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A1508: movss [0x0056FBB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBB0u, ctx.xmm[0].u32[0]);
	// 0x2A1510: ret
	return;
}

void sub_2A1520(X86Context& ctx, uint8_t* base) {
	// 0x2A1520: movss xmm0, dword ptr [0x0056FBF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBF4u);
	// 0x2A1528: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1530: movss [0x0056FC2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC2Cu, ctx.xmm[0].u32[0]);
	// 0x2A1538: ret
	return;
}

void sub_2A1540(X86Context& ctx, uint8_t* base) {
	// 0x2A1540: movss xmm0, dword ptr [0x0056FBB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBB0u);
	// 0x2A1548: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A1550: movss [0x0056FC14], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC14u, ctx.xmm[0].u32[0]);
	// 0x2A1558: ret
	return;
}

void sub_2A1560(X86Context& ctx, uint8_t* base) {
	// 0x2A1560: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A1568: movss [0x0056FC4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC4Cu, ctx.xmm[0].u32[0]);
	// 0x2A1570: ret
	return;
}

void sub_2A1580(X86Context& ctx, uint8_t* base) {
	// 0x2A1580: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A1588: movss [0x0056FC30], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC30u, ctx.xmm[0].u32[0]);
	// 0x2A1590: ret
	return;
}

void sub_2A15A0(X86Context& ctx, uint8_t* base) {
	// 0x2A15A0: movss xmm0, dword ptr [0x0056FC30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC30u);
	// 0x2A15A8: movss [0x0056FC48], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC48u, ctx.xmm[0].u32[0]);
	// 0x2A15B0: ret
	return;
}

void sub_2A15C0(X86Context& ctx, uint8_t* base) {
	// 0x2A15C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A15C8: movss [0x0056FB9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB9Cu, ctx.xmm[0].u32[0]);
	// 0x2A15D0: ret
	return;
}

void sub_2A15E0(X86Context& ctx, uint8_t* base) {
	// 0x2A15E0: movss xmm0, dword ptr [0x0056FBB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBB0u);
	// 0x2A15E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A15F0: movss [0x0056FC38], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC38u, ctx.xmm[0].u32[0]);
	// 0x2A15F8: ret
	return;
}

void sub_2A1600(X86Context& ctx, uint8_t* base) {
	// 0x2A1600: movss xmm0, dword ptr [0x0056FBB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBB0u);
	// 0x2A1608: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A1610: movss [0x0056FBDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBDCu, ctx.xmm[0].u32[0]);
	// 0x2A1618: ret
	return;
}

void sub_2A1620(X86Context& ctx, uint8_t* base) {
	// 0x2A1620: movss xmm0, dword ptr [0x0056FBB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBB0u);
	// 0x2A1628: subss xmm0, [0x0056FBDC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FBDCu);
	// 0x2A1630: movss [0x0056FBB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBB8u, ctx.xmm[0].u32[0]);
	// 0x2A1638: ret
	return;
}

void sub_2A1640(X86Context& ctx, uint8_t* base) {
	// 0x2A1640: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A1648: movss [0x0056FC08], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC08u, ctx.xmm[0].u32[0]);
	// 0x2A1650: ret
	return;
}

void sub_2A1660(X86Context& ctx, uint8_t* base) {
	// 0x2A1660: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A1668: movss [0x0056FBB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBB4u, ctx.xmm[0].u32[0]);
	// 0x2A1670: ret
	return;
}

void sub_2A1680(X86Context& ctx, uint8_t* base) {
	// 0x2A1680: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A1688: movss [0x0056FBC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBC8u, ctx.xmm[0].u32[0]);
	// 0x2A1690: ret
	return;
}

void sub_2A16A0(X86Context& ctx, uint8_t* base) {
	// 0x2A16A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A16A8: movss [0x0056FC20], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC20u, ctx.xmm[0].u32[0]);
	// 0x2A16B0: ret
	return;
}

void sub_2A16C0(X86Context& ctx, uint8_t* base) {
	// 0x2A16C0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A16C8: movss [0x0056FC04], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC04u, ctx.xmm[0].u32[0]);
	// 0x2A16D0: ret
	return;
}

void sub_2A16E0(X86Context& ctx, uint8_t* base) {
	// 0x2A16E0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A16E8: movss [0x0056FBAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBACu, ctx.xmm[0].u32[0]);
	// 0x2A16F0: ret
	return;
}

void sub_2A1700(X86Context& ctx, uint8_t* base) {
	// 0x2A1700: movss xmm0, dword ptr [0x0056FBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBC8u);
	// 0x2A1708: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1710: movss [0x0056FBA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBA0u, ctx.xmm[0].u32[0]);
	// 0x2A1718: ret
	return;
}

void sub_2A1720(X86Context& ctx, uint8_t* base) {
	// 0x2A1720: movss xmm0, dword ptr [0x0056FC20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC20u);
	// 0x2A1728: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A1730: movss [0x0056FBEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBECu, ctx.xmm[0].u32[0]);
	// 0x2A1738: ret
	return;
}

void sub_2A1740(X86Context& ctx, uint8_t* base) {
	// 0x2A1740: movss xmm0, dword ptr [0x0056FBA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBA0u);
	// 0x2A1748: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1750: movss [0x0056FBFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBFCu, ctx.xmm[0].u32[0]);
	// 0x2A1758: ret
	return;
}

void sub_2A1760(X86Context& ctx, uint8_t* base) {
	// 0x2A1760: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A1768: movss [0x0056FB94], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB94u, ctx.xmm[0].u32[0]);
	// 0x2A1770: ret
	return;
}

void sub_2A1780(X86Context& ctx, uint8_t* base) {
	// 0x2A1780: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A1788: movss [0x0056FBCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBCCu, ctx.xmm[0].u32[0]);
	// 0x2A1790: ret
	return;
}

void sub_2A17A0(X86Context& ctx, uint8_t* base) {
	// 0x2A17A0: movss xmm0, dword ptr [0x0056FBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBC8u);
	// 0x2A17A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A17B0: movss [0x0056FBD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBD8u, ctx.xmm[0].u32[0]);
	// 0x2A17B8: ret
	return;
}

void sub_2A17C0(X86Context& ctx, uint8_t* base) {
	// 0x2A17C0: movss xmm0, dword ptr [0x0056FC20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC20u);
	// 0x2A17C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A17D0: movss [0x0056FC24], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC24u, ctx.xmm[0].u32[0]);
	// 0x2A17D8: ret
	return;
}

void sub_2A17E0(X86Context& ctx, uint8_t* base) {
	// 0x2A17E0: movss xmm0, dword ptr [0x0056FBD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBD8u);
	// 0x2A17E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A17F0: movss [0x0056FC10], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC10u, ctx.xmm[0].u32[0]);
	// 0x2A17F8: ret
	return;
}

void sub_2A1800(X86Context& ctx, uint8_t* base) {
	// 0x2A1800: movss xmm0, dword ptr [0x0056FC24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC24u);
	// 0x2A1808: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1810: movss [0x0056FC34], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC34u, ctx.xmm[0].u32[0]);
	// 0x2A1818: ret
	return;
}

void sub_2A1820(X86Context& ctx, uint8_t* base) {
	// 0x2A1820: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A1828: movss [0x0056FBA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBA4u, ctx.xmm[0].u32[0]);
	// 0x2A1830: ret
	return;
}

void sub_2A1840(X86Context& ctx, uint8_t* base) {
	// 0x2A1840: movss xmm0, dword ptr [0x0056FBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBC8u);
	// 0x2A1848: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1850: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A1858: movss [0x0056FC1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC1Cu, ctx.xmm[0].u32[0]);
	// 0x2A1860: ret
	return;
}

void sub_2A1870(X86Context& ctx, uint8_t* base) {
	// 0x2A1870: movss xmm0, dword ptr [0x0056FC20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC20u);
	// 0x2A1878: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1880: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A1888: movss [0x0056FBBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBBCu, ctx.xmm[0].u32[0]);
	// 0x2A1890: ret
	return;
}

void sub_2A18A0(X86Context& ctx, uint8_t* base) {
	// 0x2A18A0: movss xmm0, dword ptr [0x0056FBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBC8u);
	// 0x2A18A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A18B0: movss [0x0056FBC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBC0u, ctx.xmm[0].u32[0]);
	// 0x2A18B8: ret
	return;
}

void sub_2A18C0(X86Context& ctx, uint8_t* base) {
	// 0x2A18C0: movss xmm0, dword ptr [0x0056FC20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC20u);
	// 0x2A18C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A18D0: movss [0x0056FC28], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC28u, ctx.xmm[0].u32[0]);
	// 0x2A18D8: ret
	return;
}

void sub_2A18E0(X86Context& ctx, uint8_t* base) {
	// 0x2A18E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A18E8: movss [0x0056FBA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBA8u, ctx.xmm[0].u32[0]);
	// 0x2A18F0: ret
	return;
}

void sub_2A1900(X86Context& ctx, uint8_t* base) {
	// 0x2A1900: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A1908: movss [0x0056FBD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBD4u, ctx.xmm[0].u32[0]);
	// 0x2A1910: ret
	return;
}

void sub_2A1920(X86Context& ctx, uint8_t* base) {
	// 0x2A1920: movss xmm0, dword ptr [0x0056FBA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBA8u);
	// 0x2A1928: movss [0x0056FC44], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC44u, ctx.xmm[0].u32[0]);
	// 0x2A1930: ret
	return;
}

void sub_2A1940(X86Context& ctx, uint8_t* base) {
	// 0x2A1940: movss xmm0, dword ptr [0x0056FC20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC20u);
	// 0x2A1948: subss xmm0, [0x0056FBA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FBA8u);
	// 0x2A1950: movss [0x0056FC00], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC00u, ctx.xmm[0].u32[0]);
	// 0x2A1958: ret
	return;
}

void sub_2A1960(X86Context& ctx, uint8_t* base) {
	// 0x2A1960: movss xmm0, dword ptr [0x0056FC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC00u);
	// 0x2A1968: subss xmm0, [0x0056FBD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FBD4u);
	// 0x2A1970: movss [0x0056FBF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBF8u, ctx.xmm[0].u32[0]);
	// 0x2A1978: ret
	return;
}

void sub_2A1980(X86Context& ctx, uint8_t* base) {
	// 0x2A1980: movss xmm0, dword ptr [0x0056FC28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC28u);
	// 0x2A1988: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A1990: movss [0x0056FBE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBE4u, ctx.xmm[0].u32[0]);
	// 0x2A1998: ret
	return;
}

void sub_2A19A0(X86Context& ctx, uint8_t* base) {
	// 0x2A19A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A19A8: movss [0x0056FBD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBD0u, ctx.xmm[0].u32[0]);
	// 0x2A19B0: ret
	return;
}

void sub_2A19C0(X86Context& ctx, uint8_t* base) {
	// 0x2A19C0: movss xmm0, dword ptr [0x0056FBE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FBE4u);
	// 0x2A19C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A19D0: movss [0x0056FC18], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC18u, ctx.xmm[0].u32[0]);
	// 0x2A19D8: ret
	return;
}

void sub_2A19E0(X86Context& ctx, uint8_t* base) {
	// 0x2A19E0: movss xmm0, dword ptr [0x003A292C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A292Cu);
	// 0x2A19E8: movss [0x0056FBE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBE8u, ctx.xmm[0].u32[0]);
	// 0x2A19F0: ret
	return;
}

void sub_2A1A00(X86Context& ctx, uint8_t* base) {
	// 0x2A1A00: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2A1A08: movss [0x0056FBC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FBC4u, ctx.xmm[0].u32[0]);
	// 0x2A1A10: ret
	return;
}

void sub_2A1A20(X86Context& ctx, uint8_t* base) {
	// 0x2A1A20: movss xmm0, dword ptr [0x003B229C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B229Cu);
	// 0x2A1A28: movss [0x0056FB98], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB98u, ctx.xmm[0].u32[0]);
	// 0x2A1A30: ret
	return;
}

void sub_2A1A40(X86Context& ctx, uint8_t* base) {
	// 0x2A1A40: movss xmm0, dword ptr [0x003B22A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22A0u);
	// 0x2A1A48: movss [0x0056FC40], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC40u, ctx.xmm[0].u32[0]);
	// 0x2A1A50: ret
	return;
}

void sub_2A1A60(X86Context& ctx, uint8_t* base) {
	// 0x2A1A60: movss xmm0, dword ptr [0x003B220C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B220Cu);
	// 0x2A1A68: movss [0x0056FB90], xmm0
	X86_MEM_WRITE_u32(base, 0x56FB90u, ctx.xmm[0].u32[0]);
	// 0x2A1A70: ret
	return;
}

void sub_2A1A80(X86Context& ctx, uint8_t* base) {
	// 0x2A1A80: movss xmm0, dword ptr [0x003B1A28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1A28u);
	// 0x2A1A88: movss [0x0056FC3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC3Cu, ctx.xmm[0].u32[0]);
	// 0x2A1A90: ret
	return;
}

void sub_2A1AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A1AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A1AA8: movss [0x0056FCB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCB0u, ctx.xmm[0].u32[0]);
	// 0x2A1AB0: ret
	return;
}

void sub_2A1AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A1AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A1AC8: movss [0x0056FCCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCCCu, ctx.xmm[0].u32[0]);
	// 0x2A1AD0: ret
	return;
}

void sub_2A1AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A1AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A1AE8: movss [0x0056FC9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC9Cu, ctx.xmm[0].u32[0]);
	// 0x2A1AF0: ret
	return;
}

void sub_2A1B00(X86Context& ctx, uint8_t* base) {
	// 0x2A1B00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A1B08: movss [0x0056FC50], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC50u, ctx.xmm[0].u32[0]);
	// 0x2A1B10: ret
	return;
}

void sub_2A1B20(X86Context& ctx, uint8_t* base) {
	// 0x2A1B20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A1B28: movss [0x0056FCB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCB4u, ctx.xmm[0].u32[0]);
	// 0x2A1B30: ret
	return;
}

void sub_2A1B40(X86Context& ctx, uint8_t* base) {
	// 0x2A1B40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A1B48: movss [0x0056FC70], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC70u, ctx.xmm[0].u32[0]);
	// 0x2A1B50: ret
	return;
}

void sub_2A1B60(X86Context& ctx, uint8_t* base) {
	// 0x2A1B60: movss xmm0, dword ptr [0x0056FCB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCB4u);
	// 0x2A1B68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1B70: movss [0x0056FCEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCECu, ctx.xmm[0].u32[0]);
	// 0x2A1B78: ret
	return;
}

void sub_2A1B80(X86Context& ctx, uint8_t* base) {
	// 0x2A1B80: movss xmm0, dword ptr [0x0056FC70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC70u);
	// 0x2A1B88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A1B90: movss [0x0056FCD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCD4u, ctx.xmm[0].u32[0]);
	// 0x2A1B98: ret
	return;
}

void sub_2A1BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A1BA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A1BA8: movss [0x0056FD04], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD04u, ctx.xmm[0].u32[0]);
	// 0x2A1BB0: ret
	return;
}

void sub_2A1BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A1BC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A1BC8: movss [0x0056FCF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCF0u, ctx.xmm[0].u32[0]);
	// 0x2A1BD0: ret
	return;
}

void sub_2A1BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A1BE0: movss xmm0, dword ptr [0x0056FCF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCF0u);
	// 0x2A1BE8: movss [0x0056FD00], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD00u, ctx.xmm[0].u32[0]);
	// 0x2A1BF0: ret
	return;
}

void sub_2A1C00(X86Context& ctx, uint8_t* base) {
	// 0x2A1C00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A1C08: movss [0x0056FC5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC5Cu, ctx.xmm[0].u32[0]);
	// 0x2A1C10: ret
	return;
}

void sub_2A1C20(X86Context& ctx, uint8_t* base) {
	// 0x2A1C20: movss xmm0, dword ptr [0x0056FC70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC70u);
	// 0x2A1C28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A1C30: movss [0x0056FCF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCF8u, ctx.xmm[0].u32[0]);
	// 0x2A1C38: ret
	return;
}

void sub_2A1C40(X86Context& ctx, uint8_t* base) {
	// 0x2A1C40: movss xmm0, dword ptr [0x0056FC70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC70u);
	// 0x2A1C48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A1C50: movss [0x0056FC98], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC98u, ctx.xmm[0].u32[0]);
	// 0x2A1C58: ret
	return;
}

void sub_2A1C60(X86Context& ctx, uint8_t* base) {
	// 0x2A1C60: movss xmm0, dword ptr [0x0056FC70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC70u);
	// 0x2A1C68: subss xmm0, [0x0056FC98]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FC98u);
	// 0x2A1C70: movss [0x0056FC78], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC78u, ctx.xmm[0].u32[0]);
	// 0x2A1C78: ret
	return;
}

void sub_2A1C80(X86Context& ctx, uint8_t* base) {
	// 0x2A1C80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A1C88: movss [0x0056FCC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCC8u, ctx.xmm[0].u32[0]);
	// 0x2A1C90: ret
	return;
}

void sub_2A1CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A1CA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A1CA8: movss [0x0056FC74], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC74u, ctx.xmm[0].u32[0]);
	// 0x2A1CB0: ret
	return;
}

void sub_2A1CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A1CC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A1CC8: movss [0x0056FC84], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC84u, ctx.xmm[0].u32[0]);
	// 0x2A1CD0: ret
	return;
}

void sub_2A1CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A1CE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A1CE8: movss [0x0056FCE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCE0u, ctx.xmm[0].u32[0]);
	// 0x2A1CF0: ret
	return;
}

void sub_2A1D00(X86Context& ctx, uint8_t* base) {
	// 0x2A1D00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A1D08: movss [0x0056FCC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCC4u, ctx.xmm[0].u32[0]);
	// 0x2A1D10: ret
	return;
}

void sub_2A1D20(X86Context& ctx, uint8_t* base) {
	// 0x2A1D20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A1D28: movss [0x0056FC6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC6Cu, ctx.xmm[0].u32[0]);
	// 0x2A1D30: ret
	return;
}

void sub_2A1D40(X86Context& ctx, uint8_t* base) {
	// 0x2A1D40: movss xmm0, dword ptr [0x0056FC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC84u);
	// 0x2A1D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1D50: movss [0x0056FC60], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC60u, ctx.xmm[0].u32[0]);
	// 0x2A1D58: ret
	return;
}

void sub_2A1D60(X86Context& ctx, uint8_t* base) {
	// 0x2A1D60: movss xmm0, dword ptr [0x0056FCE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE0u);
	// 0x2A1D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A1D70: movss [0x0056FCAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCACu, ctx.xmm[0].u32[0]);
	// 0x2A1D78: ret
	return;
}

void sub_2A1D80(X86Context& ctx, uint8_t* base) {
	// 0x2A1D80: movss xmm0, dword ptr [0x0056FC60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC60u);
	// 0x2A1D88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A1D90: movss [0x0056FCBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCBCu, ctx.xmm[0].u32[0]);
	// 0x2A1D98: ret
	return;
}

void sub_2A1DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A1DA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A1DA8: movss [0x0056FC54], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC54u, ctx.xmm[0].u32[0]);
	// 0x2A1DB0: ret
	return;
}

void sub_2A1DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A1DC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A1DC8: movss [0x0056FC88], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC88u, ctx.xmm[0].u32[0]);
	// 0x2A1DD0: ret
	return;
}

void sub_2A1DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A1DE0: movss xmm0, dword ptr [0x0056FC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC84u);
	// 0x2A1DE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A1DF0: movss [0x0056FC94], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC94u, ctx.xmm[0].u32[0]);
	// 0x2A1DF8: ret
	return;
}

void sub_2A1E00(X86Context& ctx, uint8_t* base) {
	// 0x2A1E00: movss xmm0, dword ptr [0x0056FCE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE0u);
	// 0x2A1E08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A1E10: movss [0x0056FCE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCE4u, ctx.xmm[0].u32[0]);
	// 0x2A1E18: ret
	return;
}

void sub_2A1E20(X86Context& ctx, uint8_t* base) {
	// 0x2A1E20: movss xmm0, dword ptr [0x0056FC94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC94u);
	// 0x2A1E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1E30: movss [0x0056FCD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCD0u, ctx.xmm[0].u32[0]);
	// 0x2A1E38: ret
	return;
}

void sub_2A1E40(X86Context& ctx, uint8_t* base) {
	// 0x2A1E40: movss xmm0, dword ptr [0x0056FCE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE4u);
	// 0x2A1E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1E50: movss [0x0056FCF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCF4u, ctx.xmm[0].u32[0]);
	// 0x2A1E58: ret
	return;
}

void sub_2A1E60(X86Context& ctx, uint8_t* base) {
	// 0x2A1E60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A1E68: movss [0x0056FC64], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC64u, ctx.xmm[0].u32[0]);
	// 0x2A1E70: ret
	return;
}

void sub_2A1E80(X86Context& ctx, uint8_t* base) {
	// 0x2A1E80: movss xmm0, dword ptr [0x0056FC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC84u);
	// 0x2A1E88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1E90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A1E98: movss [0x0056FCDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCDCu, ctx.xmm[0].u32[0]);
	// 0x2A1EA0: ret
	return;
}

void sub_2A1EB0(X86Context& ctx, uint8_t* base) {
	// 0x2A1EB0: movss xmm0, dword ptr [0x0056FCE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE0u);
	// 0x2A1EB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1EC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A1EC8: movss [0x0056FC7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC7Cu, ctx.xmm[0].u32[0]);
	// 0x2A1ED0: ret
	return;
}

void sub_2A1EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A1EE0: movss xmm0, dword ptr [0x0056FC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC84u);
	// 0x2A1EE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1EF0: movss [0x0056FC80], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC80u, ctx.xmm[0].u32[0]);
	// 0x2A1EF8: ret
	return;
}

void sub_2A1F00(X86Context& ctx, uint8_t* base) {
	// 0x2A1F00: movss xmm0, dword ptr [0x0056FCE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE0u);
	// 0x2A1F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A1F10: movss [0x0056FCE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCE8u, ctx.xmm[0].u32[0]);
	// 0x2A1F18: ret
	return;
}

void sub_2A1F20(X86Context& ctx, uint8_t* base) {
	// 0x2A1F20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A1F28: movss [0x0056FC68], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC68u, ctx.xmm[0].u32[0]);
	// 0x2A1F30: ret
	return;
}

void sub_2A1F40(X86Context& ctx, uint8_t* base) {
	// 0x2A1F40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A1F48: movss [0x0056FC90], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC90u, ctx.xmm[0].u32[0]);
	// 0x2A1F50: ret
	return;
}

void sub_2A1F60(X86Context& ctx, uint8_t* base) {
	// 0x2A1F60: movss xmm0, dword ptr [0x0056FC68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC68u);
	// 0x2A1F68: movss [0x0056FCFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCFCu, ctx.xmm[0].u32[0]);
	// 0x2A1F70: ret
	return;
}

void sub_2A1F80(X86Context& ctx, uint8_t* base) {
	// 0x2A1F80: movss xmm0, dword ptr [0x0056FCE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE0u);
	// 0x2A1F88: subss xmm0, [0x0056FC68]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FC68u);
	// 0x2A1F90: movss [0x0056FCC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCC0u, ctx.xmm[0].u32[0]);
	// 0x2A1F98: ret
	return;
}

void sub_2A1FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A1FA0: movss xmm0, dword ptr [0x0056FCC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCC0u);
	// 0x2A1FA8: subss xmm0, [0x0056FC90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FC90u);
	// 0x2A1FB0: movss [0x0056FCB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCB8u, ctx.xmm[0].u32[0]);
	// 0x2A1FB8: ret
	return;
}

void sub_2A1FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A1FC0: movss xmm0, dword ptr [0x0056FCE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCE8u);
	// 0x2A1FC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A1FD0: movss [0x0056FCA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCA8u, ctx.xmm[0].u32[0]);
	// 0x2A1FD8: ret
	return;
}

void sub_2A1FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A1FE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A1FE8: movss [0x0056FC8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC8Cu, ctx.xmm[0].u32[0]);
	// 0x2A1FF0: ret
	return;
}

void sub_2A2000(X86Context& ctx, uint8_t* base) {
	// 0x2A2000: movss xmm0, dword ptr [0x0056FCA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FCA8u);
	// 0x2A2008: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A2010: movss [0x0056FCD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCD8u, ctx.xmm[0].u32[0]);
	// 0x2A2018: ret
	return;
}

void sub_2A2020(X86Context& ctx, uint8_t* base) {
	// 0x2A2020: movss xmm0, dword ptr [0x0056FC60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC60u);
	// 0x2A2028: subss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A2030: movss [0x004065B8], xmm0
	X86_MEM_WRITE_u32(base, 0x4065B8u, ctx.xmm[0].u32[0]);
	// 0x2A2038: ret
	return;
}

void sub_2A2040(X86Context& ctx, uint8_t* base) {
	// 0x2A2040: movss xmm0, dword ptr [0x0056FC60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC60u);
	// 0x2A2048: subss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A2050: movss [0x004065C0], xmm0
	X86_MEM_WRITE_u32(base, 0x4065C0u, ctx.xmm[0].u32[0]);
	// 0x2A2058: ret
	return;
}

void sub_2A2060(X86Context& ctx, uint8_t* base) {
	// 0x2A2060: movss xmm0, dword ptr [0x003B2214]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2214u);
	// 0x2A2068: movss [0x0056FCA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCA0u, ctx.xmm[0].u32[0]);
	// 0x2A2070: ret
	return;
}

void sub_2A2080(X86Context& ctx, uint8_t* base) {
	// 0x2A2080: movss xmm0, dword ptr [0x003B1708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1708u);
	// 0x2A2088: movss [0x0056FC58], xmm0
	X86_MEM_WRITE_u32(base, 0x56FC58u, ctx.xmm[0].u32[0]);
	// 0x2A2090: ret
	return;
}

void sub_2A20A0(X86Context& ctx, uint8_t* base) {
	// 0x2A20A0: movss xmm0, dword ptr [0x0056FC58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC58u);
	// 0x2A20A8: addss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A20B0: movss [0x0056FCA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FCA4u, ctx.xmm[0].u32[0]);
	// 0x2A20B8: ret
	return;
}

void sub_2A20C0(X86Context& ctx, uint8_t* base) {
	// 0x2A20C0: movss xmm0, dword ptr [0x0056FC58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC58u);
	// 0x2A20C8: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2A20CB: addss xmm1, [0x003B03EC]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x3B03ECu);
	// 0x2A20D3: addss xmm0, [0x003B168C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B168Cu);
	// 0x2A20DB: movss [0x004191A8], xmm1
	X86_MEM_WRITE_u32(base, 0x4191A8u, ctx.xmm[1].u32[0]);
	// 0x2A20E3: movss [0x004191AC], xmm0
	X86_MEM_WRITE_u32(base, 0x4191ACu, ctx.xmm[0].u32[0]);
	// 0x2A20EB: ret
	return;
}

void sub_2A20F0(X86Context& ctx, uint8_t* base) {
	// 0x2A20F0: movss xmm0, dword ptr [0x0056FC58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FC58u);
	// 0x2A20F8: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x2A20FB: addss xmm1, [0x003B03EC]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x3B03ECu);
	// 0x2A2103: addss xmm0, [0x003B168C]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B168Cu);
	// 0x2A210B: movss [0x00419194], xmm1
	X86_MEM_WRITE_u32(base, 0x419194u, ctx.xmm[1].u32[0]);
	// 0x2A2113: movss [0x00419198], xmm0
	X86_MEM_WRITE_u32(base, 0x419198u, ctx.xmm[0].u32[0]);
	// 0x2A211B: ret
	return;
}

void sub_2A2120(X86Context& ctx, uint8_t* base) {
	// 0x2A2120: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A2128: movss [0x0056FD90], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD90u, ctx.xmm[0].u32[0]);
	// 0x2A2130: ret
	return;
}

void sub_2A2140(X86Context& ctx, uint8_t* base) {
	// 0x2A2140: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A2148: movss [0x0056FDD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDD4u, ctx.xmm[0].u32[0]);
	// 0x2A2150: ret
	return;
}

void sub_2A2160(X86Context& ctx, uint8_t* base) {
	// 0x2A2160: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A2168: movss [0x0056FD80], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD80u, ctx.xmm[0].u32[0]);
	// 0x2A2170: ret
	return;
}

void sub_2A2180(X86Context& ctx, uint8_t* base) {
	// 0x2A2180: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A2188: movss [0x0056FD08], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD08u, ctx.xmm[0].u32[0]);
	// 0x2A2190: ret
	return;
}

void sub_2A21A0(X86Context& ctx, uint8_t* base) {
	// 0x2A21A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A21A8: movss [0x0056FD94], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD94u, ctx.xmm[0].u32[0]);
	// 0x2A21B0: ret
	return;
}

void sub_2A21C0(X86Context& ctx, uint8_t* base) {
	// 0x2A21C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A21C8: movss [0x0056FD28], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD28u, ctx.xmm[0].u32[0]);
	// 0x2A21D0: ret
	return;
}

void sub_2A21E0(X86Context& ctx, uint8_t* base) {
	// 0x2A21E0: movss xmm0, dword ptr [0x0056FD94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD94u);
	// 0x2A21E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A21F0: movss [0x0056FDF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDF4u, ctx.xmm[0].u32[0]);
	// 0x2A21F8: ret
	return;
}

void sub_2A2200(X86Context& ctx, uint8_t* base) {
	// 0x2A2200: movss xmm0, dword ptr [0x0056FD28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD28u);
	// 0x2A2208: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A2210: movss [0x0056FDDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDDCu, ctx.xmm[0].u32[0]);
	// 0x2A2218: ret
	return;
}

void sub_2A2220(X86Context& ctx, uint8_t* base) {
	// 0x2A2220: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A2228: movss [0x0056FE20], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE20u, ctx.xmm[0].u32[0]);
	// 0x2A2230: ret
	return;
}

void sub_2A2240(X86Context& ctx, uint8_t* base) {
	// 0x2A2240: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A2248: movss [0x0056FDF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDF8u, ctx.xmm[0].u32[0]);
	// 0x2A2250: ret
	return;
}

void sub_2A2260(X86Context& ctx, uint8_t* base) {
	// 0x2A2260: movss xmm0, dword ptr [0x0056FDF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FDF8u);
	// 0x2A2268: movss [0x0056FE1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE1Cu, ctx.xmm[0].u32[0]);
	// 0x2A2270: ret
	return;
}

void sub_2A2280(X86Context& ctx, uint8_t* base) {
	// 0x2A2280: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A2288: movss [0x0056FD14], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD14u, ctx.xmm[0].u32[0]);
	// 0x2A2290: ret
	return;
}

void sub_2A22A0(X86Context& ctx, uint8_t* base) {
	// 0x2A22A0: movss xmm0, dword ptr [0x0056FD28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD28u);
	// 0x2A22A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A22B0: movss [0x0056FE00], xmm0
	X86_MEM_WRITE_u32(base, 0x56FE00u, ctx.xmm[0].u32[0]);
	// 0x2A22B8: ret
	return;
}

void sub_2A22C0(X86Context& ctx, uint8_t* base) {
	// 0x2A22C0: movss xmm0, dword ptr [0x0056FD28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD28u);
	// 0x2A22C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A22D0: movss [0x0056FD7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD7Cu, ctx.xmm[0].u32[0]);
	// 0x2A22D8: ret
	return;
}

void sub_2A22E0(X86Context& ctx, uint8_t* base) {
	// 0x2A22E0: movss xmm0, dword ptr [0x0056FD28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD28u);
	// 0x2A22E8: subss xmm0, [0x0056FD7C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56FD7Cu);
	// 0x2A22F0: movss [0x0056FD44], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD44u, ctx.xmm[0].u32[0]);
	// 0x2A22F8: ret
	return;
}

void sub_2A2300(X86Context& ctx, uint8_t* base) {
	// 0x2A2300: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A2308: movss [0x0056FDD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDD0u, ctx.xmm[0].u32[0]);
	// 0x2A2310: ret
	return;
}

void sub_2A2320(X86Context& ctx, uint8_t* base) {
	// 0x2A2320: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A2328: movss [0x0056FD40], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD40u, ctx.xmm[0].u32[0]);
	// 0x2A2330: ret
	return;
}

void sub_2A2340(X86Context& ctx, uint8_t* base) {
	// 0x2A2340: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A2348: movss [0x0056FD58], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD58u, ctx.xmm[0].u32[0]);
	// 0x2A2350: ret
	return;
}

void sub_2A2360(X86Context& ctx, uint8_t* base) {
	// 0x2A2360: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A2368: movss [0x0056FDE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDE8u, ctx.xmm[0].u32[0]);
	// 0x2A2370: ret
	return;
}

void sub_2A2380(X86Context& ctx, uint8_t* base) {
	// 0x2A2380: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A2388: movss [0x0056FDC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56FDC8u, ctx.xmm[0].u32[0]);
	// 0x2A2390: ret
	return;
}

void sub_2A23A0(X86Context& ctx, uint8_t* base) {
	// 0x2A23A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A23A8: movss [0x0056FD24], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD24u, ctx.xmm[0].u32[0]);
	// 0x2A23B0: ret
	return;
}

void sub_2A23C0(X86Context& ctx, uint8_t* base) {
	// 0x2A23C0: movss xmm0, dword ptr [0x0056FD58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56FD58u);
	// 0x2A23C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A23D0: movss [0x0056FD18], xmm0
	X86_MEM_WRITE_u32(base, 0x56FD18u, ctx.xmm[0].u32[0]);
	// 0x2A23D8: ret
	return;
}

