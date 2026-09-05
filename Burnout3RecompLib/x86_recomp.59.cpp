#include "x86_recomp_shared.h"

void sub_297FA0(X86Context& ctx, uint8_t* base) {
	// 0x297FA0: movss xmm0, dword ptr [0x0056E920]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E920u);
	// 0x297FA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297FB0: movss [0x0056E918], xmm0
	X86_MEM_WRITE_u32(base, 0x56E918u, ctx.xmm[0].u32[0]);
	// 0x297FB8: ret
	return;
}

void sub_297FC0(X86Context& ctx, uint8_t* base) {
	// 0x297FC0: movss xmm0, dword ptr [0x0056E978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E978u);
	// 0x297FC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x297FD0: movss [0x0056E980], xmm0
	X86_MEM_WRITE_u32(base, 0x56E980u, ctx.xmm[0].u32[0]);
	// 0x297FD8: ret
	return;
}

void sub_297FE0(X86Context& ctx, uint8_t* base) {
	// 0x297FE0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x297FE8: movss [0x0056E8FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E8FCu, ctx.xmm[0].u32[0]);
	// 0x297FF0: ret
	return;
}

void sub_298000(X86Context& ctx, uint8_t* base) {
	// 0x298000: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x298008: movss [0x0056E92C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E92Cu, ctx.xmm[0].u32[0]);
	// 0x298010: ret
	return;
}

void sub_298020(X86Context& ctx, uint8_t* base) {
	// 0x298020: movss xmm0, dword ptr [0x0056E8FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E8FCu);
	// 0x298028: movss [0x0056E994], xmm0
	X86_MEM_WRITE_u32(base, 0x56E994u, ctx.xmm[0].u32[0]);
	// 0x298030: ret
	return;
}

void sub_298040(X86Context& ctx, uint8_t* base) {
	// 0x298040: movss xmm0, dword ptr [0x0056E978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E978u);
	// 0x298048: subss xmm0, [0x0056E8FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E8FCu);
	// 0x298050: movss [0x0056E958], xmm0
	X86_MEM_WRITE_u32(base, 0x56E958u, ctx.xmm[0].u32[0]);
	// 0x298058: ret
	return;
}

void sub_298060(X86Context& ctx, uint8_t* base) {
	// 0x298060: movss xmm0, dword ptr [0x0056E958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E958u);
	// 0x298068: subss xmm0, [0x0056E92C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E92Cu);
	// 0x298070: movss [0x0056E950], xmm0
	X86_MEM_WRITE_u32(base, 0x56E950u, ctx.xmm[0].u32[0]);
	// 0x298078: ret
	return;
}

void sub_298080(X86Context& ctx, uint8_t* base) {
	// 0x298080: movss xmm0, dword ptr [0x0056E980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E980u);
	// 0x298088: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x298090: movss [0x0056E93C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E93Cu, ctx.xmm[0].u32[0]);
	// 0x298098: ret
	return;
}

void sub_2980A0(X86Context& ctx, uint8_t* base) {
	// 0x2980A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2980A8: movss [0x0056E928], xmm0
	X86_MEM_WRITE_u32(base, 0x56E928u, ctx.xmm[0].u32[0]);
	// 0x2980B0: ret
	return;
}

void sub_2980C0(X86Context& ctx, uint8_t* base) {
	// 0x2980C0: movss xmm0, dword ptr [0x0056E93C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E93Cu);
	// 0x2980C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2980D0: movss [0x0056E970], xmm0
	X86_MEM_WRITE_u32(base, 0x56E970u, ctx.xmm[0].u32[0]);
	// 0x2980D8: ret
	return;
}

void sub_2980E0(X86Context& ctx, uint8_t* base) {
	// 0x2980E0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2980E8: movss [0x0056E944], xmm0
	X86_MEM_WRITE_u32(base, 0x56E944u, ctx.xmm[0].u32[0]);
	// 0x2980F0: ret
	return;
}

void sub_298100(X86Context& ctx, uint8_t* base) {
	// 0x298100: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x298108: movss [0x0056E91C], xmm0
	X86_MEM_WRITE_u32(base, 0x56E91Cu, ctx.xmm[0].u32[0]);
	// 0x298110: ret
	return;
}

void sub_298120(X86Context& ctx, uint8_t* base) {
	// 0x298120: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x298128: movss [0x0056E914], xmm0
	X86_MEM_WRITE_u32(base, 0x56E914u, ctx.xmm[0].u32[0]);
	// 0x298130: ret
	return;
}

void sub_298140(X86Context& ctx, uint8_t* base) {
	// 0x298140: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x298148: movss [0x0056E9F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9F4u, ctx.xmm[0].u32[0]);
	// 0x298150: ret
	return;
}

void sub_298160(X86Context& ctx, uint8_t* base) {
	// 0x298160: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x298168: movss [0x0056EA10], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA10u, ctx.xmm[0].u32[0]);
	// 0x298170: ret
	return;
}

void sub_298180(X86Context& ctx, uint8_t* base) {
	// 0x298180: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x298188: movss [0x0056E9E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9E8u, ctx.xmm[0].u32[0]);
	// 0x298190: ret
	return;
}

void sub_2981A0(X86Context& ctx, uint8_t* base) {
	// 0x2981A0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2981A8: movss [0x0056E9A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9A0u, ctx.xmm[0].u32[0]);
	// 0x2981B0: ret
	return;
}

void sub_2981C0(X86Context& ctx, uint8_t* base) {
	// 0x2981C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2981C8: movss [0x0056E9F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9F8u, ctx.xmm[0].u32[0]);
	// 0x2981D0: ret
	return;
}

void sub_2981E0(X86Context& ctx, uint8_t* base) {
	// 0x2981E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2981E8: movss [0x0056E9BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9BCu, ctx.xmm[0].u32[0]);
	// 0x2981F0: ret
	return;
}

void sub_298200(X86Context& ctx, uint8_t* base) {
	// 0x298200: movss xmm0, dword ptr [0x0056E9F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9F8u);
	// 0x298208: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x298210: movss [0x0056EA30], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA30u, ctx.xmm[0].u32[0]);
	// 0x298218: ret
	return;
}

void sub_298220(X86Context& ctx, uint8_t* base) {
	// 0x298220: movss xmm0, dword ptr [0x0056E9BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9BCu);
	// 0x298228: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x298230: movss [0x0056EA18], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA18u, ctx.xmm[0].u32[0]);
	// 0x298238: ret
	return;
}

void sub_298240(X86Context& ctx, uint8_t* base) {
	// 0x298240: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x298248: movss [0x0056EA48], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA48u, ctx.xmm[0].u32[0]);
	// 0x298250: ret
	return;
}

void sub_298260(X86Context& ctx, uint8_t* base) {
	// 0x298260: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x298268: movss [0x0056EA34], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA34u, ctx.xmm[0].u32[0]);
	// 0x298270: ret
	return;
}

void sub_298280(X86Context& ctx, uint8_t* base) {
	// 0x298280: movss xmm0, dword ptr [0x0056EA34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA34u);
	// 0x298288: movss [0x0056EA44], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA44u, ctx.xmm[0].u32[0]);
	// 0x298290: ret
	return;
}

void sub_2982A0(X86Context& ctx, uint8_t* base) {
	// 0x2982A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2982A8: movss [0x0056E9A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9A8u, ctx.xmm[0].u32[0]);
	// 0x2982B0: ret
	return;
}

void sub_2982C0(X86Context& ctx, uint8_t* base) {
	// 0x2982C0: movss xmm0, dword ptr [0x0056E9BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9BCu);
	// 0x2982C8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2982D0: movss [0x0056EA3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA3Cu, ctx.xmm[0].u32[0]);
	// 0x2982D8: ret
	return;
}

void sub_2982E0(X86Context& ctx, uint8_t* base) {
	// 0x2982E0: movss xmm0, dword ptr [0x0056E9BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9BCu);
	// 0x2982E8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2982F0: movss [0x0056E9E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9E4u, ctx.xmm[0].u32[0]);
	// 0x2982F8: ret
	return;
}

void sub_298300(X86Context& ctx, uint8_t* base) {
	// 0x298300: movss xmm0, dword ptr [0x0056E9BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9BCu);
	// 0x298308: subss xmm0, [0x0056E9E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E9E4u);
	// 0x298310: movss [0x0056E9C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9C4u, ctx.xmm[0].u32[0]);
	// 0x298318: ret
	return;
}

void sub_298320(X86Context& ctx, uint8_t* base) {
	// 0x298320: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x298328: movss [0x0056EA0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA0Cu, ctx.xmm[0].u32[0]);
	// 0x298330: ret
	return;
}

void sub_298340(X86Context& ctx, uint8_t* base) {
	// 0x298340: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x298348: movss [0x0056E9C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9C0u, ctx.xmm[0].u32[0]);
	// 0x298350: ret
	return;
}

void sub_298360(X86Context& ctx, uint8_t* base) {
	// 0x298360: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x298368: movss [0x0056E9D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9D0u, ctx.xmm[0].u32[0]);
	// 0x298370: ret
	return;
}

void sub_298380(X86Context& ctx, uint8_t* base) {
	// 0x298380: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x298388: movss [0x0056EA24], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA24u, ctx.xmm[0].u32[0]);
	// 0x298390: ret
	return;
}

void sub_2983A0(X86Context& ctx, uint8_t* base) {
	// 0x2983A0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2983A8: movss [0x0056EA08], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA08u, ctx.xmm[0].u32[0]);
	// 0x2983B0: ret
	return;
}

void sub_2983C0(X86Context& ctx, uint8_t* base) {
	// 0x2983C0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2983C8: movss [0x0056E9B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9B8u, ctx.xmm[0].u32[0]);
	// 0x2983D0: ret
	return;
}

void sub_2983E0(X86Context& ctx, uint8_t* base) {
	// 0x2983E0: movss xmm0, dword ptr [0x0056E9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9D0u);
	// 0x2983E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2983F0: movss [0x0056E9AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9ACu, ctx.xmm[0].u32[0]);
	// 0x2983F8: ret
	return;
}

void sub_298400(X86Context& ctx, uint8_t* base) {
	// 0x298400: movss xmm0, dword ptr [0x0056EA24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA24u);
	// 0x298408: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x298410: movss [0x0056E9F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9F0u, ctx.xmm[0].u32[0]);
	// 0x298418: ret
	return;
}

void sub_298420(X86Context& ctx, uint8_t* base) {
	// 0x298420: movss xmm0, dword ptr [0x0056E9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9ACu);
	// 0x298428: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x298430: movss [0x0056EA00], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA00u, ctx.xmm[0].u32[0]);
	// 0x298438: ret
	return;
}

void sub_298440(X86Context& ctx, uint8_t* base) {
	// 0x298440: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x298448: movss [0x0056E9A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9A4u, ctx.xmm[0].u32[0]);
	// 0x298450: ret
	return;
}

void sub_298460(X86Context& ctx, uint8_t* base) {
	// 0x298460: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x298468: movss [0x0056E9D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9D4u, ctx.xmm[0].u32[0]);
	// 0x298470: ret
	return;
}

void sub_298480(X86Context& ctx, uint8_t* base) {
	// 0x298480: movss xmm0, dword ptr [0x0056E9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9D0u);
	// 0x298488: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x298490: movss [0x0056E9E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9E0u, ctx.xmm[0].u32[0]);
	// 0x298498: ret
	return;
}

void sub_2984A0(X86Context& ctx, uint8_t* base) {
	// 0x2984A0: movss xmm0, dword ptr [0x0056EA24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA24u);
	// 0x2984A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2984B0: movss [0x0056EA28], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA28u, ctx.xmm[0].u32[0]);
	// 0x2984B8: ret
	return;
}

void sub_2984C0(X86Context& ctx, uint8_t* base) {
	// 0x2984C0: movss xmm0, dword ptr [0x0056E9E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9E0u);
	// 0x2984C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2984D0: movss [0x0056EA14], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA14u, ctx.xmm[0].u32[0]);
	// 0x2984D8: ret
	return;
}

void sub_2984E0(X86Context& ctx, uint8_t* base) {
	// 0x2984E0: movss xmm0, dword ptr [0x0056EA28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA28u);
	// 0x2984E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2984F0: movss [0x0056EA38], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA38u, ctx.xmm[0].u32[0]);
	// 0x2984F8: ret
	return;
}

void sub_298500(X86Context& ctx, uint8_t* base) {
	// 0x298500: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x298508: movss [0x0056E9B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9B0u, ctx.xmm[0].u32[0]);
	// 0x298510: ret
	return;
}

void sub_298520(X86Context& ctx, uint8_t* base) {
	// 0x298520: movss xmm0, dword ptr [0x0056E9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9D0u);
	// 0x298528: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298530: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x298538: movss [0x0056EA20], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA20u, ctx.xmm[0].u32[0]);
	// 0x298540: ret
	return;
}

void sub_298550(X86Context& ctx, uint8_t* base) {
	// 0x298550: movss xmm0, dword ptr [0x0056EA24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA24u);
	// 0x298558: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298560: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x298568: movss [0x0056E9C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9C8u, ctx.xmm[0].u32[0]);
	// 0x298570: ret
	return;
}

void sub_298580(X86Context& ctx, uint8_t* base) {
	// 0x298580: movss xmm0, dword ptr [0x0056E9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9D0u);
	// 0x298588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298590: movss [0x0056E9CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9CCu, ctx.xmm[0].u32[0]);
	// 0x298598: ret
	return;
}

void sub_2985A0(X86Context& ctx, uint8_t* base) {
	// 0x2985A0: movss xmm0, dword ptr [0x0056EA24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA24u);
	// 0x2985A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2985B0: movss [0x0056EA2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA2Cu, ctx.xmm[0].u32[0]);
	// 0x2985B8: ret
	return;
}

void sub_2985C0(X86Context& ctx, uint8_t* base) {
	// 0x2985C0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2985C8: movss [0x0056E9B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9B4u, ctx.xmm[0].u32[0]);
	// 0x2985D0: ret
	return;
}

void sub_2985E0(X86Context& ctx, uint8_t* base) {
	// 0x2985E0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2985E8: movss [0x0056E9DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9DCu, ctx.xmm[0].u32[0]);
	// 0x2985F0: ret
	return;
}

void sub_298600(X86Context& ctx, uint8_t* base) {
	// 0x298600: movss xmm0, dword ptr [0x0056E9B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9B4u);
	// 0x298608: movss [0x0056EA40], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA40u, ctx.xmm[0].u32[0]);
	// 0x298610: ret
	return;
}

void sub_298620(X86Context& ctx, uint8_t* base) {
	// 0x298620: movss xmm0, dword ptr [0x0056EA24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA24u);
	// 0x298628: subss xmm0, [0x0056E9B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E9B4u);
	// 0x298630: movss [0x0056EA04], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA04u, ctx.xmm[0].u32[0]);
	// 0x298638: ret
	return;
}

void sub_298640(X86Context& ctx, uint8_t* base) {
	// 0x298640: movss xmm0, dword ptr [0x0056EA04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA04u);
	// 0x298648: subss xmm0, [0x0056E9DC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56E9DCu);
	// 0x298650: movss [0x0056E9FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9FCu, ctx.xmm[0].u32[0]);
	// 0x298658: ret
	return;
}

void sub_298660(X86Context& ctx, uint8_t* base) {
	// 0x298660: movss xmm0, dword ptr [0x0056EA2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA2Cu);
	// 0x298668: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x298670: movss [0x0056E9EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9ECu, ctx.xmm[0].u32[0]);
	// 0x298678: ret
	return;
}

void sub_298680(X86Context& ctx, uint8_t* base) {
	// 0x298680: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x298688: movss [0x0056E9D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56E9D8u, ctx.xmm[0].u32[0]);
	// 0x298690: ret
	return;
}

void sub_2986A0(X86Context& ctx, uint8_t* base) {
	// 0x2986A0: movss xmm0, dword ptr [0x0056E9EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56E9ECu);
	// 0x2986A8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2986B0: movss [0x0056EA1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA1Cu, ctx.xmm[0].u32[0]);
	// 0x2986B8: ret
	return;
}

void sub_2986C0(X86Context& ctx, uint8_t* base) {
	// 0x2986C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2986C8: movss [0x0056EABC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EABCu, ctx.xmm[0].u32[0]);
	// 0x2986D0: ret
	return;
}

void sub_2986E0(X86Context& ctx, uint8_t* base) {
	// 0x2986E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2986E8: movss [0x0056EADC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EADCu, ctx.xmm[0].u32[0]);
	// 0x2986F0: ret
	return;
}

void sub_298700(X86Context& ctx, uint8_t* base) {
	// 0x298700: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x298708: movss [0x0056EAAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAACu, ctx.xmm[0].u32[0]);
	// 0x298710: ret
	return;
}

void sub_298720(X86Context& ctx, uint8_t* base) {
	// 0x298720: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x298728: movss [0x0056EA50], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA50u, ctx.xmm[0].u32[0]);
	// 0x298730: ret
	return;
}

void sub_298740(X86Context& ctx, uint8_t* base) {
	// 0x298740: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x298748: movss [0x0056EAC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAC0u, ctx.xmm[0].u32[0]);
	// 0x298750: ret
	return;
}

void sub_298760(X86Context& ctx, uint8_t* base) {
	// 0x298760: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x298768: movss [0x0056EA6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA6Cu, ctx.xmm[0].u32[0]);
	// 0x298770: ret
	return;
}

void sub_298780(X86Context& ctx, uint8_t* base) {
	// 0x298780: movss xmm0, dword ptr [0x0056EAC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAC0u);
	// 0x298788: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x298790: movss [0x0056EAFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAFCu, ctx.xmm[0].u32[0]);
	// 0x298798: ret
	return;
}

void sub_2987A0(X86Context& ctx, uint8_t* base) {
	// 0x2987A0: movss xmm0, dword ptr [0x0056EA6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA6Cu);
	// 0x2987A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2987B0: movss [0x0056EAE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAE4u, ctx.xmm[0].u32[0]);
	// 0x2987B8: ret
	return;
}

void sub_2987C0(X86Context& ctx, uint8_t* base) {
	// 0x2987C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2987C8: movss [0x0056EB18], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB18u, ctx.xmm[0].u32[0]);
	// 0x2987D0: ret
	return;
}

void sub_2987E0(X86Context& ctx, uint8_t* base) {
	// 0x2987E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2987E8: movss [0x0056EB00], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB00u, ctx.xmm[0].u32[0]);
	// 0x2987F0: ret
	return;
}

void sub_298800(X86Context& ctx, uint8_t* base) {
	// 0x298800: movss xmm0, dword ptr [0x0056EB00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB00u);
	// 0x298808: movss [0x0056EB14], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB14u, ctx.xmm[0].u32[0]);
	// 0x298810: ret
	return;
}

void sub_298820(X86Context& ctx, uint8_t* base) {
	// 0x298820: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x298828: movss [0x0056EA58], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA58u, ctx.xmm[0].u32[0]);
	// 0x298830: ret
	return;
}

void sub_298840(X86Context& ctx, uint8_t* base) {
	// 0x298840: movss xmm0, dword ptr [0x0056EA6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA6Cu);
	// 0x298848: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x298850: movss [0x0056EB08], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB08u, ctx.xmm[0].u32[0]);
	// 0x298858: ret
	return;
}

void sub_298860(X86Context& ctx, uint8_t* base) {
	// 0x298860: movss xmm0, dword ptr [0x0056EA6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA6Cu);
	// 0x298868: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x298870: movss [0x0056EAA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAA8u, ctx.xmm[0].u32[0]);
	// 0x298878: ret
	return;
}

void sub_298880(X86Context& ctx, uint8_t* base) {
	// 0x298880: movss xmm0, dword ptr [0x0056EA6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA6Cu);
	// 0x298888: subss xmm0, [0x0056EAA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EAA8u);
	// 0x298890: movss [0x0056EA74], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA74u, ctx.xmm[0].u32[0]);
	// 0x298898: ret
	return;
}

void sub_2988A0(X86Context& ctx, uint8_t* base) {
	// 0x2988A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2988A8: movss [0x0056EAD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAD8u, ctx.xmm[0].u32[0]);
	// 0x2988B0: ret
	return;
}

void sub_2988C0(X86Context& ctx, uint8_t* base) {
	// 0x2988C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2988C8: movss [0x0056EA70], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA70u, ctx.xmm[0].u32[0]);
	// 0x2988D0: ret
	return;
}

void sub_2988E0(X86Context& ctx, uint8_t* base) {
	// 0x2988E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2988E8: movss [0x0056EA88], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA88u, ctx.xmm[0].u32[0]);
	// 0x2988F0: ret
	return;
}

void sub_298900(X86Context& ctx, uint8_t* base) {
	// 0x298900: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x298908: movss [0x0056EAF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAF0u, ctx.xmm[0].u32[0]);
	// 0x298910: ret
	return;
}

void sub_298920(X86Context& ctx, uint8_t* base) {
	// 0x298920: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x298928: movss [0x0056EAD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAD4u, ctx.xmm[0].u32[0]);
	// 0x298930: ret
	return;
}

void sub_298940(X86Context& ctx, uint8_t* base) {
	// 0x298940: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x298948: movss [0x0056EA68], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA68u, ctx.xmm[0].u32[0]);
	// 0x298950: ret
	return;
}

void sub_298960(X86Context& ctx, uint8_t* base) {
	// 0x298960: movss xmm0, dword ptr [0x0056EA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA88u);
	// 0x298968: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x298970: movss [0x0056EA5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA5Cu, ctx.xmm[0].u32[0]);
	// 0x298978: ret
	return;
}

void sub_298980(X86Context& ctx, uint8_t* base) {
	// 0x298980: movss xmm0, dword ptr [0x0056EAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF0u);
	// 0x298988: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x298990: movss [0x0056EAB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAB8u, ctx.xmm[0].u32[0]);
	// 0x298998: ret
	return;
}

void sub_2989A0(X86Context& ctx, uint8_t* base) {
	// 0x2989A0: movss xmm0, dword ptr [0x0056EA5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA5Cu);
	// 0x2989A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2989B0: movss [0x0056EAC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAC8u, ctx.xmm[0].u32[0]);
	// 0x2989B8: ret
	return;
}

void sub_2989C0(X86Context& ctx, uint8_t* base) {
	// 0x2989C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2989C8: movss [0x0056EA54], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA54u, ctx.xmm[0].u32[0]);
	// 0x2989D0: ret
	return;
}

void sub_2989E0(X86Context& ctx, uint8_t* base) {
	// 0x2989E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2989E8: movss [0x0056EA98], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA98u, ctx.xmm[0].u32[0]);
	// 0x2989F0: ret
	return;
}

void sub_298A00(X86Context& ctx, uint8_t* base) {
	// 0x298A00: movss xmm0, dword ptr [0x0056EA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA88u);
	// 0x298A08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x298A10: movss [0x0056EAA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAA4u, ctx.xmm[0].u32[0]);
	// 0x298A18: ret
	return;
}

void sub_298A20(X86Context& ctx, uint8_t* base) {
	// 0x298A20: movss xmm0, dword ptr [0x0056EAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF0u);
	// 0x298A28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x298A30: movss [0x0056EAF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAF4u, ctx.xmm[0].u32[0]);
	// 0x298A38: ret
	return;
}

void sub_298A40(X86Context& ctx, uint8_t* base) {
	// 0x298A40: movss xmm0, dword ptr [0x0056EAA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAA4u);
	// 0x298A48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298A50: movss [0x0056EAE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAE0u, ctx.xmm[0].u32[0]);
	// 0x298A58: ret
	return;
}

void sub_298A60(X86Context& ctx, uint8_t* base) {
	// 0x298A60: movss xmm0, dword ptr [0x0056EAF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF4u);
	// 0x298A68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298A70: movss [0x0056EB04], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB04u, ctx.xmm[0].u32[0]);
	// 0x298A78: ret
	return;
}

void sub_298A80(X86Context& ctx, uint8_t* base) {
	// 0x298A80: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x298A88: movss [0x0056EA60], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA60u, ctx.xmm[0].u32[0]);
	// 0x298A90: ret
	return;
}

void sub_298AA0(X86Context& ctx, uint8_t* base) {
	// 0x298AA0: movss xmm0, dword ptr [0x0056EA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA88u);
	// 0x298AA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298AB0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x298AB8: movss [0x0056EAEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAECu, ctx.xmm[0].u32[0]);
	// 0x298AC0: ret
	return;
}

void sub_298AD0(X86Context& ctx, uint8_t* base) {
	// 0x298AD0: movss xmm0, dword ptr [0x0056EAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF0u);
	// 0x298AD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298AE0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x298AE8: movss [0x0056EA78], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA78u, ctx.xmm[0].u32[0]);
	// 0x298AF0: ret
	return;
}

void sub_298B00(X86Context& ctx, uint8_t* base) {
	// 0x298B00: movss xmm0, dword ptr [0x0056EA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA88u);
	// 0x298B08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298B10: movss [0x0056EA7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA7Cu, ctx.xmm[0].u32[0]);
	// 0x298B18: ret
	return;
}

void sub_298B20(X86Context& ctx, uint8_t* base) {
	// 0x298B20: movss xmm0, dword ptr [0x0056EAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF0u);
	// 0x298B28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x298B30: movss [0x0056EAF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAF8u, ctx.xmm[0].u32[0]);
	// 0x298B38: ret
	return;
}

void sub_298B40(X86Context& ctx, uint8_t* base) {
	// 0x298B40: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x298B48: movss [0x0056EA64], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA64u, ctx.xmm[0].u32[0]);
	// 0x298B50: ret
	return;
}

void sub_298B60(X86Context& ctx, uint8_t* base) {
	// 0x298B60: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x298B68: movss [0x0056EAA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAA0u, ctx.xmm[0].u32[0]);
	// 0x298B70: ret
	return;
}

void sub_298B80(X86Context& ctx, uint8_t* base) {
	// 0x298B80: movss xmm0, dword ptr [0x0056EA64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA64u);
	// 0x298B88: movss [0x0056EB10], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB10u, ctx.xmm[0].u32[0]);
	// 0x298B90: ret
	return;
}

void sub_298BA0(X86Context& ctx, uint8_t* base) {
	// 0x298BA0: movss xmm0, dword ptr [0x0056EAF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF0u);
	// 0x298BA8: subss xmm0, [0x0056EA64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EA64u);
	// 0x298BB0: movss [0x0056EAD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAD0u, ctx.xmm[0].u32[0]);
	// 0x298BB8: ret
	return;
}

void sub_298BC0(X86Context& ctx, uint8_t* base) {
	// 0x298BC0: movss xmm0, dword ptr [0x0056EAD0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAD0u);
	// 0x298BC8: subss xmm0, [0x0056EAA0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EAA0u);
	// 0x298BD0: movss [0x0056EAC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAC4u, ctx.xmm[0].u32[0]);
	// 0x298BD8: ret
	return;
}

void sub_298BE0(X86Context& ctx, uint8_t* base) {
	// 0x298BE0: movss xmm0, dword ptr [0x0056EAF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAF8u);
	// 0x298BE8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x298BF0: movss [0x0056EAB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAB0u, ctx.xmm[0].u32[0]);
	// 0x298BF8: ret
	return;
}

void sub_298C00(X86Context& ctx, uint8_t* base) {
	// 0x298C00: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x298C08: movss [0x0056EA9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA9Cu, ctx.xmm[0].u32[0]);
	// 0x298C10: ret
	return;
}

void sub_298C20(X86Context& ctx, uint8_t* base) {
	// 0x298C20: movss xmm0, dword ptr [0x0056EAB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EAB0u);
	// 0x298C28: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x298C30: movss [0x0056EAE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAE8u, ctx.xmm[0].u32[0]);
	// 0x298C38: ret
	return;
}

void sub_298C40(X86Context& ctx, uint8_t* base) {
	// 0x298C40: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x298C48: movss [0x0056EAB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EAB4u, ctx.xmm[0].u32[0]);
	// 0x298C50: ret
	return;
}

void sub_298C60(X86Context& ctx, uint8_t* base) {
	// 0x298C60: movss xmm0, dword ptr [0x00388E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x298C68: movss [0x0056EB0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB0Cu, ctx.xmm[0].u32[0]);
	// 0x298C70: ret
	return;
}

void sub_298C80(X86Context& ctx, uint8_t* base) {
	// 0x298C80: movss xmm0, dword ptr [0x003B2290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2290u);
	// 0x298C88: movss [0x0056EA80], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA80u, ctx.xmm[0].u32[0]);
	// 0x298C90: ret
	return;
}

void sub_298CA0(X86Context& ctx, uint8_t* base) {
	// 0x298CA0: movss xmm0, dword ptr [0x003B1904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1904u);
	// 0x298CA8: movss [0x0056EA4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA4Cu, ctx.xmm[0].u32[0]);
	// 0x298CB0: ret
	return;
}

void sub_298CC0(X86Context& ctx, uint8_t* base) {
	// 0x298CC0: movss xmm0, dword ptr [0x0056EA88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA88u);
	// 0x298CC8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x298CD0: movss [0x004053B0], xmm0
	X86_MEM_WRITE_u32(base, 0x4053B0u, ctx.xmm[0].u32[0]);
	// 0x298CD8: ret
	return;
}

void sub_298CE0(X86Context& ctx, uint8_t* base) {
	// 0x298CE0: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x298CE8: movss [0x0056EA84], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA84u, ctx.xmm[0].u32[0]);
	// 0x298CF0: ret
	return;
}

void sub_298D00(X86Context& ctx, uint8_t* base) {
	// 0x298D00: movss xmm0, dword ptr [0x0056EA80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA80u);
	// 0x298D08: addss xmm0, [0x0056EAB4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x56EAB4u);
	// 0x298D10: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x298D18: movss [0x0056EA90], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA90u, ctx.xmm[0].u32[0]);
	// 0x298D20: movss xmm0, dword ptr [0x0056EB0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB0Cu);
	// 0x298D28: movss [0x0056EA94], xmm0
	X86_MEM_WRITE_u32(base, 0x56EA94u, ctx.xmm[0].u32[0]);
	// 0x298D30: ret
	return;
}

void sub_298D40(X86Context& ctx, uint8_t* base) {
	// 0x298D40: movss xmm0, dword ptr [0x0056EA4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EA4Cu);
	// 0x298D48: movss [0x0056EACC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EACCu, ctx.xmm[0].u32[0]);
	// 0x298D50: ret
	return;
}

void sub_298D60(X86Context& ctx, uint8_t* base) {
	// 0x298D60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x298D68: movss [0x0056EB84], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB84u, ctx.xmm[0].u32[0]);
	// 0x298D70: ret
	return;
}

void sub_298D80(X86Context& ctx, uint8_t* base) {
	// 0x298D80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x298D88: movss [0x0056EBA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBA0u, ctx.xmm[0].u32[0]);
	// 0x298D90: ret
	return;
}

void sub_298DA0(X86Context& ctx, uint8_t* base) {
	// 0x298DA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x298DA8: movss [0x0056EB78], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB78u, ctx.xmm[0].u32[0]);
	// 0x298DB0: ret
	return;
}

void sub_298DC0(X86Context& ctx, uint8_t* base) {
	// 0x298DC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x298DC8: movss [0x0056EB1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB1Cu, ctx.xmm[0].u32[0]);
	// 0x298DD0: ret
	return;
}

void sub_298DE0(X86Context& ctx, uint8_t* base) {
	// 0x298DE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x298DE8: movss [0x0056EB88], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB88u, ctx.xmm[0].u32[0]);
	// 0x298DF0: ret
	return;
}

void sub_298E00(X86Context& ctx, uint8_t* base) {
	// 0x298E00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x298E08: movss [0x0056EB3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB3Cu, ctx.xmm[0].u32[0]);
	// 0x298E10: ret
	return;
}

void sub_298E20(X86Context& ctx, uint8_t* base) {
	// 0x298E20: movss xmm0, dword ptr [0x0056EB88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB88u);
	// 0x298E28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x298E30: movss [0x0056EBC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBC4u, ctx.xmm[0].u32[0]);
	// 0x298E38: ret
	return;
}

void sub_298E40(X86Context& ctx, uint8_t* base) {
	// 0x298E40: movss xmm0, dword ptr [0x0056EB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB3Cu);
	// 0x298E48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x298E50: movss [0x0056EBA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBA8u, ctx.xmm[0].u32[0]);
	// 0x298E58: ret
	return;
}

void sub_298E60(X86Context& ctx, uint8_t* base) {
	// 0x298E60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x298E68: movss [0x0056EBE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBE0u, ctx.xmm[0].u32[0]);
	// 0x298E70: ret
	return;
}

void sub_298E80(X86Context& ctx, uint8_t* base) {
	// 0x298E80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x298E88: movss [0x0056EBC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBC8u, ctx.xmm[0].u32[0]);
	// 0x298E90: ret
	return;
}

void sub_298EA0(X86Context& ctx, uint8_t* base) {
	// 0x298EA0: movss xmm0, dword ptr [0x0056EBC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBC8u);
	// 0x298EA8: movss [0x0056EBD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBD8u, ctx.xmm[0].u32[0]);
	// 0x298EB0: ret
	return;
}

void sub_298EC0(X86Context& ctx, uint8_t* base) {
	// 0x298EC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x298EC8: movss [0x0056EB28], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB28u, ctx.xmm[0].u32[0]);
	// 0x298ED0: ret
	return;
}

void sub_298EE0(X86Context& ctx, uint8_t* base) {
	// 0x298EE0: movss xmm0, dword ptr [0x0056EB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB3Cu);
	// 0x298EE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x298EF0: movss [0x0056EBD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBD0u, ctx.xmm[0].u32[0]);
	// 0x298EF8: ret
	return;
}

void sub_298F00(X86Context& ctx, uint8_t* base) {
	// 0x298F00: movss xmm0, dword ptr [0x0056EB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB3Cu);
	// 0x298F08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x298F10: movss [0x0056EB74], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB74u, ctx.xmm[0].u32[0]);
	// 0x298F18: ret
	return;
}

void sub_298F20(X86Context& ctx, uint8_t* base) {
	// 0x298F20: movss xmm0, dword ptr [0x0056EB3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB3Cu);
	// 0x298F28: subss xmm0, [0x0056EB74]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EB74u);
	// 0x298F30: movss [0x0056EB44], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB44u, ctx.xmm[0].u32[0]);
	// 0x298F38: ret
	return;
}

void sub_298F40(X86Context& ctx, uint8_t* base) {
	// 0x298F40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x298F48: movss [0x0056EB9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB9Cu, ctx.xmm[0].u32[0]);
	// 0x298F50: ret
	return;
}

void sub_298F60(X86Context& ctx, uint8_t* base) {
	// 0x298F60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x298F68: movss [0x0056EB40], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB40u, ctx.xmm[0].u32[0]);
	// 0x298F70: ret
	return;
}

void sub_298F80(X86Context& ctx, uint8_t* base) {
	// 0x298F80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x298F88: movss [0x0056EB58], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB58u, ctx.xmm[0].u32[0]);
	// 0x298F90: ret
	return;
}

void sub_298FA0(X86Context& ctx, uint8_t* base) {
	// 0x298FA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x298FA8: movss [0x0056EBB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBB4u, ctx.xmm[0].u32[0]);
	// 0x298FB0: ret
	return;
}

void sub_298FC0(X86Context& ctx, uint8_t* base) {
	// 0x298FC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x298FC8: movss [0x0056EB98], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB98u, ctx.xmm[0].u32[0]);
	// 0x298FD0: ret
	return;
}

void sub_298FE0(X86Context& ctx, uint8_t* base) {
	// 0x298FE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x298FE8: movss [0x0056EB38], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB38u, ctx.xmm[0].u32[0]);
	// 0x298FF0: ret
	return;
}

void sub_299000(X86Context& ctx, uint8_t* base) {
	// 0x299000: movss xmm0, dword ptr [0x0056EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB58u);
	// 0x299008: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x299010: movss [0x0056EB2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB2Cu, ctx.xmm[0].u32[0]);
	// 0x299018: ret
	return;
}

void sub_299020(X86Context& ctx, uint8_t* base) {
	// 0x299020: movss xmm0, dword ptr [0x0056EBB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBB4u);
	// 0x299028: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x299030: movss [0x0056EB80], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB80u, ctx.xmm[0].u32[0]);
	// 0x299038: ret
	return;
}

void sub_299040(X86Context& ctx, uint8_t* base) {
	// 0x299040: movss xmm0, dword ptr [0x0056EB2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB2Cu);
	// 0x299048: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x299050: movss [0x0056EB90], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB90u, ctx.xmm[0].u32[0]);
	// 0x299058: ret
	return;
}

void sub_299060(X86Context& ctx, uint8_t* base) {
	// 0x299060: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x299068: movss [0x0056EB24], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB24u, ctx.xmm[0].u32[0]);
	// 0x299070: ret
	return;
}

void sub_299080(X86Context& ctx, uint8_t* base) {
	// 0x299080: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x299088: movss [0x0056EB5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB5Cu, ctx.xmm[0].u32[0]);
	// 0x299090: ret
	return;
}

void sub_2990A0(X86Context& ctx, uint8_t* base) {
	// 0x2990A0: movss xmm0, dword ptr [0x0056EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB58u);
	// 0x2990A8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2990B0: movss [0x0056EB70], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB70u, ctx.xmm[0].u32[0]);
	// 0x2990B8: ret
	return;
}

void sub_2990C0(X86Context& ctx, uint8_t* base) {
	// 0x2990C0: movss xmm0, dword ptr [0x0056EBB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBB4u);
	// 0x2990C8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2990D0: movss [0x0056EBBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBBCu, ctx.xmm[0].u32[0]);
	// 0x2990D8: ret
	return;
}

void sub_2990E0(X86Context& ctx, uint8_t* base) {
	// 0x2990E0: movss xmm0, dword ptr [0x0056EB70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB70u);
	// 0x2990E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2990F0: movss [0x0056EBA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBA4u, ctx.xmm[0].u32[0]);
	// 0x2990F8: ret
	return;
}

void sub_299100(X86Context& ctx, uint8_t* base) {
	// 0x299100: movss xmm0, dword ptr [0x0056EBBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBBCu);
	// 0x299108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299110: movss [0x0056EBCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBCCu, ctx.xmm[0].u32[0]);
	// 0x299118: ret
	return;
}

void sub_299120(X86Context& ctx, uint8_t* base) {
	// 0x299120: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x299128: movss [0x0056EB30], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB30u, ctx.xmm[0].u32[0]);
	// 0x299130: ret
	return;
}

void sub_299140(X86Context& ctx, uint8_t* base) {
	// 0x299140: movss xmm0, dword ptr [0x0056EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB58u);
	// 0x299148: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299150: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x299158: movss [0x0056EBB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBB0u, ctx.xmm[0].u32[0]);
	// 0x299160: ret
	return;
}

void sub_299170(X86Context& ctx, uint8_t* base) {
	// 0x299170: movss xmm0, dword ptr [0x0056EBB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBB4u);
	// 0x299178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299180: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x299188: movss [0x0056EB4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB4Cu, ctx.xmm[0].u32[0]);
	// 0x299190: ret
	return;
}

void sub_2991A0(X86Context& ctx, uint8_t* base) {
	// 0x2991A0: movss xmm0, dword ptr [0x0056EB58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB58u);
	// 0x2991A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2991B0: movss [0x0056EB50], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB50u, ctx.xmm[0].u32[0]);
	// 0x2991B8: ret
	return;
}

void sub_2991C0(X86Context& ctx, uint8_t* base) {
	// 0x2991C0: movss xmm0, dword ptr [0x0056EBB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBB4u);
	// 0x2991C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2991D0: movss [0x0056EBC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBC0u, ctx.xmm[0].u32[0]);
	// 0x2991D8: ret
	return;
}

void sub_2991E0(X86Context& ctx, uint8_t* base) {
	// 0x2991E0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2991E8: movss [0x0056EB34], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB34u, ctx.xmm[0].u32[0]);
	// 0x2991F0: ret
	return;
}

void sub_299200(X86Context& ctx, uint8_t* base) {
	// 0x299200: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x299208: movss [0x0056EB64], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB64u, ctx.xmm[0].u32[0]);
	// 0x299210: ret
	return;
}

void sub_299220(X86Context& ctx, uint8_t* base) {
	// 0x299220: movss xmm0, dword ptr [0x0056EB34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB34u);
	// 0x299228: movss [0x0056EBD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBD4u, ctx.xmm[0].u32[0]);
	// 0x299230: ret
	return;
}

void sub_299240(X86Context& ctx, uint8_t* base) {
	// 0x299240: movss xmm0, dword ptr [0x0056EBB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBB4u);
	// 0x299248: subss xmm0, [0x0056EB34]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EB34u);
	// 0x299250: movss [0x0056EB94], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB94u, ctx.xmm[0].u32[0]);
	// 0x299258: ret
	return;
}

void sub_299260(X86Context& ctx, uint8_t* base) {
	// 0x299260: movss xmm0, dword ptr [0x0056EB94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB94u);
	// 0x299268: subss xmm0, [0x0056EB64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EB64u);
	// 0x299270: movss [0x0056EB8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB8Cu, ctx.xmm[0].u32[0]);
	// 0x299278: ret
	return;
}

void sub_299280(X86Context& ctx, uint8_t* base) {
	// 0x299280: movss xmm0, dword ptr [0x0056EBC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBC0u);
	// 0x299288: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x299290: movss [0x0056EB7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB7Cu, ctx.xmm[0].u32[0]);
	// 0x299298: ret
	return;
}

void sub_2992A0(X86Context& ctx, uint8_t* base) {
	// 0x2992A0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2992A8: movss [0x0056EB60], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB60u, ctx.xmm[0].u32[0]);
	// 0x2992B0: ret
	return;
}

void sub_2992C0(X86Context& ctx, uint8_t* base) {
	// 0x2992C0: movss xmm0, dword ptr [0x0056EB7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB7Cu);
	// 0x2992C8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2992D0: movss [0x0056EBAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBACu, ctx.xmm[0].u32[0]);
	// 0x2992D8: ret
	return;
}

void sub_2992E0(X86Context& ctx, uint8_t* base) {
	// 0x2992E0: movss xmm0, dword ptr [0x0056EB98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB98u);
	// 0x2992E8: movss [0x0056EBB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBB8u, ctx.xmm[0].u32[0]);
	// 0x2992F0: ret
	return;
}

void sub_299300(X86Context& ctx, uint8_t* base) {
	// 0x299300: movss xmm0, dword ptr [0x00405488]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x405488u);
	// 0x299308: addss xmm0, [0x00405480]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x405480u);
	// 0x299310: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x299318: movss [0x0056EB68], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB68u, ctx.xmm[0].u32[0]);
	// 0x299320: movss xmm0, dword ptr [0x00405484]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x405484u);
	// 0x299328: movss [0x0056EB6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB6Cu, ctx.xmm[0].u32[0]);
	// 0x299330: ret
	return;
}

void sub_299340(X86Context& ctx, uint8_t* base) {
	// 0x299340: movss xmm0, dword ptr [0x0040548C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x40548Cu);
	// 0x299348: movss [0x0056EB54], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB54u, ctx.xmm[0].u32[0]);
	// 0x299350: ret
	return;
}

void sub_299360(X86Context& ctx, uint8_t* base) {
	// 0x299360: movss xmm0, dword ptr [0x003B203C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B203Cu);
	// 0x299368: movss [0x0056EB20], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB20u, ctx.xmm[0].u32[0]);
	// 0x299370: ret
	return;
}

void sub_299380(X86Context& ctx, uint8_t* base) {
	// 0x299380: movss xmm0, dword ptr [0x003B2070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2070u);
	// 0x299388: movss [0x0056EB48], xmm0
	X86_MEM_WRITE_u32(base, 0x56EB48u, ctx.xmm[0].u32[0]);
	// 0x299390: ret
	return;
}

void sub_2993A0(X86Context& ctx, uint8_t* base) {
	// 0x2993A0: movss xmm0, dword ptr [0x003B1880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1880u);
	// 0x2993A8: movss [0x0056EBDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBDCu, ctx.xmm[0].u32[0]);
	// 0x2993B0: ret
	return;
}

void sub_2993C0(X86Context& ctx, uint8_t* base) {
	// 0x2993C0: movss xmm0, dword ptr [0x0056EB98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EB98u);
	// 0x2993C8: movss [0x00405498], xmm0
	X86_MEM_WRITE_u32(base, 0x405498u, ctx.xmm[0].u32[0]);
	// 0x2993D0: ret
	return;
}

void sub_2993E0(X86Context& ctx, uint8_t* base) {
	// 0x2993E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2993E8: movss [0x0056EC44], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC44u, ctx.xmm[0].u32[0]);
	// 0x2993F0: ret
	return;
}

void sub_299400(X86Context& ctx, uint8_t* base) {
	// 0x299400: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x299408: movss [0x0056EC60], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC60u, ctx.xmm[0].u32[0]);
	// 0x299410: ret
	return;
}

void sub_299420(X86Context& ctx, uint8_t* base) {
	// 0x299420: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x299428: movss [0x0056EC34], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC34u, ctx.xmm[0].u32[0]);
	// 0x299430: ret
	return;
}

void sub_299440(X86Context& ctx, uint8_t* base) {
	// 0x299440: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x299448: movss [0x0056EBE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBE4u, ctx.xmm[0].u32[0]);
	// 0x299450: ret
	return;
}

void sub_299460(X86Context& ctx, uint8_t* base) {
	// 0x299460: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x299468: movss [0x0056EC48], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC48u, ctx.xmm[0].u32[0]);
	// 0x299470: ret
	return;
}

void sub_299480(X86Context& ctx, uint8_t* base) {
	// 0x299480: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x299488: movss [0x0056EC00], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC00u, ctx.xmm[0].u32[0]);
	// 0x299490: ret
	return;
}

void sub_2994A0(X86Context& ctx, uint8_t* base) {
	// 0x2994A0: movss xmm0, dword ptr [0x0056EC48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC48u);
	// 0x2994A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2994B0: movss [0x0056EC80], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC80u, ctx.xmm[0].u32[0]);
	// 0x2994B8: ret
	return;
}

void sub_2994C0(X86Context& ctx, uint8_t* base) {
	// 0x2994C0: movss xmm0, dword ptr [0x0056EC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC00u);
	// 0x2994C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2994D0: movss [0x0056EC68], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC68u, ctx.xmm[0].u32[0]);
	// 0x2994D8: ret
	return;
}

void sub_2994E0(X86Context& ctx, uint8_t* base) {
	// 0x2994E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2994E8: movss [0x0056EC9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC9Cu, ctx.xmm[0].u32[0]);
	// 0x2994F0: ret
	return;
}

void sub_299500(X86Context& ctx, uint8_t* base) {
	// 0x299500: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x299508: movss [0x0056EC84], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC84u, ctx.xmm[0].u32[0]);
	// 0x299510: ret
	return;
}

void sub_299520(X86Context& ctx, uint8_t* base) {
	// 0x299520: movss xmm0, dword ptr [0x0056EC84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC84u);
	// 0x299528: movss [0x0056EC98], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC98u, ctx.xmm[0].u32[0]);
	// 0x299530: ret
	return;
}

void sub_299540(X86Context& ctx, uint8_t* base) {
	// 0x299540: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x299548: movss [0x0056EBEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBECu, ctx.xmm[0].u32[0]);
	// 0x299550: ret
	return;
}

void sub_299560(X86Context& ctx, uint8_t* base) {
	// 0x299560: movss xmm0, dword ptr [0x0056EC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC00u);
	// 0x299568: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x299570: movss [0x0056EC8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC8Cu, ctx.xmm[0].u32[0]);
	// 0x299578: ret
	return;
}

void sub_299580(X86Context& ctx, uint8_t* base) {
	// 0x299580: movss xmm0, dword ptr [0x0056EC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC00u);
	// 0x299588: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x299590: movss [0x0056EC30], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC30u, ctx.xmm[0].u32[0]);
	// 0x299598: ret
	return;
}

void sub_2995A0(X86Context& ctx, uint8_t* base) {
	// 0x2995A0: movss xmm0, dword ptr [0x0056EC00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC00u);
	// 0x2995A8: subss xmm0, [0x0056EC30]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EC30u);
	// 0x2995B0: movss [0x0056EC08], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC08u, ctx.xmm[0].u32[0]);
	// 0x2995B8: ret
	return;
}

void sub_2995C0(X86Context& ctx, uint8_t* base) {
	// 0x2995C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2995C8: movss [0x0056EC5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC5Cu, ctx.xmm[0].u32[0]);
	// 0x2995D0: ret
	return;
}

void sub_2995E0(X86Context& ctx, uint8_t* base) {
	// 0x2995E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2995E8: movss [0x0056EC04], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC04u, ctx.xmm[0].u32[0]);
	// 0x2995F0: ret
	return;
}

void sub_299600(X86Context& ctx, uint8_t* base) {
	// 0x299600: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x299608: movss [0x0056EC14], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC14u, ctx.xmm[0].u32[0]);
	// 0x299610: ret
	return;
}

void sub_299620(X86Context& ctx, uint8_t* base) {
	// 0x299620: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x299628: movss [0x0056EC74], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC74u, ctx.xmm[0].u32[0]);
	// 0x299630: ret
	return;
}

void sub_299640(X86Context& ctx, uint8_t* base) {
	// 0x299640: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x299648: movss [0x0056EC58], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC58u, ctx.xmm[0].u32[0]);
	// 0x299650: ret
	return;
}

void sub_299660(X86Context& ctx, uint8_t* base) {
	// 0x299660: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x299668: movss [0x0056EBFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBFCu, ctx.xmm[0].u32[0]);
	// 0x299670: ret
	return;
}

void sub_299680(X86Context& ctx, uint8_t* base) {
	// 0x299680: movss xmm0, dword ptr [0x0056EC14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC14u);
	// 0x299688: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x299690: movss [0x0056EBF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBF0u, ctx.xmm[0].u32[0]);
	// 0x299698: ret
	return;
}

void sub_2996A0(X86Context& ctx, uint8_t* base) {
	// 0x2996A0: movss xmm0, dword ptr [0x0056EC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC74u);
	// 0x2996A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2996B0: movss [0x0056EC40], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC40u, ctx.xmm[0].u32[0]);
	// 0x2996B8: ret
	return;
}

void sub_2996C0(X86Context& ctx, uint8_t* base) {
	// 0x2996C0: movss xmm0, dword ptr [0x0056EBF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBF0u);
	// 0x2996C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2996D0: movss [0x0056EC50], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC50u, ctx.xmm[0].u32[0]);
	// 0x2996D8: ret
	return;
}

void sub_2996E0(X86Context& ctx, uint8_t* base) {
	// 0x2996E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2996E8: movss [0x0056EBE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBE8u, ctx.xmm[0].u32[0]);
	// 0x2996F0: ret
	return;
}

void sub_299700(X86Context& ctx, uint8_t* base) {
	// 0x299700: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x299708: movss [0x0056EC20], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC20u, ctx.xmm[0].u32[0]);
	// 0x299710: ret
	return;
}

void sub_299720(X86Context& ctx, uint8_t* base) {
	// 0x299720: movss xmm0, dword ptr [0x0056EC14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC14u);
	// 0x299728: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x299730: movss [0x0056EC2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC2Cu, ctx.xmm[0].u32[0]);
	// 0x299738: ret
	return;
}

void sub_299740(X86Context& ctx, uint8_t* base) {
	// 0x299740: movss xmm0, dword ptr [0x0056EC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC74u);
	// 0x299748: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x299750: movss [0x0056EC78], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC78u, ctx.xmm[0].u32[0]);
	// 0x299758: ret
	return;
}

void sub_299760(X86Context& ctx, uint8_t* base) {
	// 0x299760: movss xmm0, dword ptr [0x0056EC2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC2Cu);
	// 0x299768: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299770: movss [0x0056EC64], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC64u, ctx.xmm[0].u32[0]);
	// 0x299778: ret
	return;
}

void sub_299780(X86Context& ctx, uint8_t* base) {
	// 0x299780: movss xmm0, dword ptr [0x0056EC78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC78u);
	// 0x299788: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299790: movss [0x0056EC88], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC88u, ctx.xmm[0].u32[0]);
	// 0x299798: ret
	return;
}

void sub_2997A0(X86Context& ctx, uint8_t* base) {
	// 0x2997A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2997A8: movss [0x0056EBF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBF4u, ctx.xmm[0].u32[0]);
	// 0x2997B0: ret
	return;
}

void sub_2997C0(X86Context& ctx, uint8_t* base) {
	// 0x2997C0: movss xmm0, dword ptr [0x0056EC14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC14u);
	// 0x2997C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2997D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2997D8: movss [0x0056EC70], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC70u, ctx.xmm[0].u32[0]);
	// 0x2997E0: ret
	return;
}

void sub_2997F0(X86Context& ctx, uint8_t* base) {
	// 0x2997F0: movss xmm0, dword ptr [0x0056EC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC74u);
	// 0x2997F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299800: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x299808: movss [0x0056EC0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC0Cu, ctx.xmm[0].u32[0]);
	// 0x299810: ret
	return;
}

void sub_299820(X86Context& ctx, uint8_t* base) {
	// 0x299820: movss xmm0, dword ptr [0x0056EC14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC14u);
	// 0x299828: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299830: movss [0x0056EC10], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC10u, ctx.xmm[0].u32[0]);
	// 0x299838: ret
	return;
}

void sub_299840(X86Context& ctx, uint8_t* base) {
	// 0x299840: movss xmm0, dword ptr [0x0056EC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC74u);
	// 0x299848: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299850: movss [0x0056EC7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC7Cu, ctx.xmm[0].u32[0]);
	// 0x299858: ret
	return;
}

void sub_299860(X86Context& ctx, uint8_t* base) {
	// 0x299860: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x299868: movss [0x0056EBF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EBF8u, ctx.xmm[0].u32[0]);
	// 0x299870: ret
	return;
}

void sub_299880(X86Context& ctx, uint8_t* base) {
	// 0x299880: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x299888: movss [0x0056EC28], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC28u, ctx.xmm[0].u32[0]);
	// 0x299890: ret
	return;
}

void sub_2998A0(X86Context& ctx, uint8_t* base) {
	// 0x2998A0: movss xmm0, dword ptr [0x0056EBF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBF8u);
	// 0x2998A8: movss [0x0056EC90], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC90u, ctx.xmm[0].u32[0]);
	// 0x2998B0: ret
	return;
}

void sub_2998C0(X86Context& ctx, uint8_t* base) {
	// 0x2998C0: movss xmm0, dword ptr [0x0056EC74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC74u);
	// 0x2998C8: subss xmm0, [0x0056EBF8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EBF8u);
	// 0x2998D0: movss [0x0056EC54], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC54u, ctx.xmm[0].u32[0]);
	// 0x2998D8: ret
	return;
}

void sub_2998E0(X86Context& ctx, uint8_t* base) {
	// 0x2998E0: movss xmm0, dword ptr [0x0056EC54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC54u);
	// 0x2998E8: subss xmm0, [0x0056EC28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EC28u);
	// 0x2998F0: movss [0x0056EC4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC4Cu, ctx.xmm[0].u32[0]);
	// 0x2998F8: ret
	return;
}

void sub_299900(X86Context& ctx, uint8_t* base) {
	// 0x299900: movss xmm0, dword ptr [0x0056EC7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC7Cu);
	// 0x299908: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x299910: movss [0x0056EC38], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC38u, ctx.xmm[0].u32[0]);
	// 0x299918: ret
	return;
}

void sub_299920(X86Context& ctx, uint8_t* base) {
	// 0x299920: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x299928: movss [0x0056EC24], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC24u, ctx.xmm[0].u32[0]);
	// 0x299930: ret
	return;
}

void sub_299940(X86Context& ctx, uint8_t* base) {
	// 0x299940: movss xmm0, dword ptr [0x0056EC38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC38u);
	// 0x299948: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x299950: movss [0x0056EC6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC6Cu, ctx.xmm[0].u32[0]);
	// 0x299958: ret
	return;
}

void sub_299960(X86Context& ctx, uint8_t* base) {
	// 0x299960: movss xmm0, dword ptr [0x0056EC58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EC58u);
	// 0x299968: movss [0x0056EC3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC3Cu, ctx.xmm[0].u32[0]);
	// 0x299970: ret
	return;
}

void sub_299980(X86Context& ctx, uint8_t* base) {
	// 0x299980: movss xmm0, dword ptr [0x0056EBFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EBFCu);
	// 0x299988: movss [0x0056EC18], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC18u, ctx.xmm[0].u32[0]);
	// 0x299990: ret
	return;
}

void sub_2999A0(X86Context& ctx, uint8_t* base) {
	// 0x2999A0: movss xmm0, dword ptr [0x003F8308]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8308u);
	// 0x2999A8: subss xmm0, [0x0056EC3C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EC3Cu);
	// 0x2999B0: movss [0x0056EC1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC1Cu, ctx.xmm[0].u32[0]);
	// 0x2999B8: ret
	return;
}

void sub_2999C0(X86Context& ctx, uint8_t* base) {
	// 0x2999C0: movss xmm0, dword ptr [0x003B2294]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2294u);
	// 0x2999C8: subss xmm0, [0x0056EC18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EC18u);
	// 0x2999D0: movss [0x0056EC94], xmm0
	X86_MEM_WRITE_u32(base, 0x56EC94u, ctx.xmm[0].u32[0]);
	// 0x2999D8: ret
	return;
}

void sub_2999E0(X86Context& ctx, uint8_t* base) {
	// 0x2999E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2999E8: movss [0x0056ED04], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED04u, ctx.xmm[0].u32[0]);
	// 0x2999F0: ret
	return;
}

void sub_299A00(X86Context& ctx, uint8_t* base) {
	// 0x299A00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x299A08: movss [0x0056ED20], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED20u, ctx.xmm[0].u32[0]);
	// 0x299A10: ret
	return;
}

void sub_299A20(X86Context& ctx, uint8_t* base) {
	// 0x299A20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x299A28: movss [0x0056ECF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECF8u, ctx.xmm[0].u32[0]);
	// 0x299A30: ret
	return;
}

void sub_299A40(X86Context& ctx, uint8_t* base) {
	// 0x299A40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x299A48: movss [0x0056ECA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECA0u, ctx.xmm[0].u32[0]);
	// 0x299A50: ret
	return;
}

void sub_299A60(X86Context& ctx, uint8_t* base) {
	// 0x299A60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x299A68: movss [0x0056ED08], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED08u, ctx.xmm[0].u32[0]);
	// 0x299A70: ret
	return;
}

void sub_299A80(X86Context& ctx, uint8_t* base) {
	// 0x299A80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x299A88: movss [0x0056ECBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECBCu, ctx.xmm[0].u32[0]);
	// 0x299A90: ret
	return;
}

void sub_299AA0(X86Context& ctx, uint8_t* base) {
	// 0x299AA0: movss xmm0, dword ptr [0x0056ED08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED08u);
	// 0x299AA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x299AB0: movss [0x0056ED40], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED40u, ctx.xmm[0].u32[0]);
	// 0x299AB8: ret
	return;
}

void sub_299AC0(X86Context& ctx, uint8_t* base) {
	// 0x299AC0: movss xmm0, dword ptr [0x0056ECBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECBCu);
	// 0x299AC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x299AD0: movss [0x0056ED28], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED28u, ctx.xmm[0].u32[0]);
	// 0x299AD8: ret
	return;
}

void sub_299AE0(X86Context& ctx, uint8_t* base) {
	// 0x299AE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x299AE8: movss [0x0056ED60], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED60u, ctx.xmm[0].u32[0]);
	// 0x299AF0: ret
	return;
}

void sub_299B00(X86Context& ctx, uint8_t* base) {
	// 0x299B00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x299B08: movss [0x0056ED44], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED44u, ctx.xmm[0].u32[0]);
	// 0x299B10: ret
	return;
}

void sub_299B20(X86Context& ctx, uint8_t* base) {
	// 0x299B20: movss xmm0, dword ptr [0x0056ED44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED44u);
	// 0x299B28: movss [0x0056ED54], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED54u, ctx.xmm[0].u32[0]);
	// 0x299B30: ret
	return;
}

void sub_299B40(X86Context& ctx, uint8_t* base) {
	// 0x299B40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x299B48: movss [0x0056ECA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECA8u, ctx.xmm[0].u32[0]);
	// 0x299B50: ret
	return;
}

void sub_299B60(X86Context& ctx, uint8_t* base) {
	// 0x299B60: movss xmm0, dword ptr [0x0056ECBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECBCu);
	// 0x299B68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x299B70: movss [0x0056ED4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED4Cu, ctx.xmm[0].u32[0]);
	// 0x299B78: ret
	return;
}

void sub_299B80(X86Context& ctx, uint8_t* base) {
	// 0x299B80: movss xmm0, dword ptr [0x0056ECBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECBCu);
	// 0x299B88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x299B90: movss [0x0056ECF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECF4u, ctx.xmm[0].u32[0]);
	// 0x299B98: ret
	return;
}

void sub_299BA0(X86Context& ctx, uint8_t* base) {
	// 0x299BA0: movss xmm0, dword ptr [0x0056ECBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECBCu);
	// 0x299BA8: subss xmm0, [0x0056ECF4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ECF4u);
	// 0x299BB0: movss [0x0056ECC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECC4u, ctx.xmm[0].u32[0]);
	// 0x299BB8: ret
	return;
}

void sub_299BC0(X86Context& ctx, uint8_t* base) {
	// 0x299BC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x299BC8: movss [0x0056ED1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED1Cu, ctx.xmm[0].u32[0]);
	// 0x299BD0: ret
	return;
}

void sub_299BE0(X86Context& ctx, uint8_t* base) {
	// 0x299BE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x299BE8: movss [0x0056ECC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECC0u, ctx.xmm[0].u32[0]);
	// 0x299BF0: ret
	return;
}

void sub_299C00(X86Context& ctx, uint8_t* base) {
	// 0x299C00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x299C08: movss [0x0056ECE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECE0u, ctx.xmm[0].u32[0]);
	// 0x299C10: ret
	return;
}

void sub_299C20(X86Context& ctx, uint8_t* base) {
	// 0x299C20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x299C28: movss [0x0056ED34], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED34u, ctx.xmm[0].u32[0]);
	// 0x299C30: ret
	return;
}

void sub_299C40(X86Context& ctx, uint8_t* base) {
	// 0x299C40: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x299C48: movss [0x0056ED18], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED18u, ctx.xmm[0].u32[0]);
	// 0x299C50: ret
	return;
}

void sub_299C60(X86Context& ctx, uint8_t* base) {
	// 0x299C60: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x299C68: movss [0x0056ECB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECB8u, ctx.xmm[0].u32[0]);
	// 0x299C70: ret
	return;
}

void sub_299C80(X86Context& ctx, uint8_t* base) {
	// 0x299C80: movss xmm0, dword ptr [0x0056ECE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECE0u);
	// 0x299C88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x299C90: movss [0x0056ECAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECACu, ctx.xmm[0].u32[0]);
	// 0x299C98: ret
	return;
}

void sub_299CA0(X86Context& ctx, uint8_t* base) {
	// 0x299CA0: movss xmm0, dword ptr [0x0056ED34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED34u);
	// 0x299CA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x299CB0: movss [0x0056ED00], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED00u, ctx.xmm[0].u32[0]);
	// 0x299CB8: ret
	return;
}

void sub_299CC0(X86Context& ctx, uint8_t* base) {
	// 0x299CC0: movss xmm0, dword ptr [0x0056ECAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECACu);
	// 0x299CC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x299CD0: movss [0x0056ED10], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED10u, ctx.xmm[0].u32[0]);
	// 0x299CD8: ret
	return;
}

void sub_299CE0(X86Context& ctx, uint8_t* base) {
	// 0x299CE0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x299CE8: movss [0x0056ECA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECA4u, ctx.xmm[0].u32[0]);
	// 0x299CF0: ret
	return;
}

void sub_299D00(X86Context& ctx, uint8_t* base) {
	// 0x299D00: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x299D08: movss [0x0056ECE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECE4u, ctx.xmm[0].u32[0]);
	// 0x299D10: ret
	return;
}

void sub_299D20(X86Context& ctx, uint8_t* base) {
	// 0x299D20: movss xmm0, dword ptr [0x0056ECE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECE0u);
	// 0x299D28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x299D30: movss [0x0056ECF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECF0u, ctx.xmm[0].u32[0]);
	// 0x299D38: ret
	return;
}

void sub_299D40(X86Context& ctx, uint8_t* base) {
	// 0x299D40: movss xmm0, dword ptr [0x0056ED34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED34u);
	// 0x299D48: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x299D50: movss [0x0056ED38], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED38u, ctx.xmm[0].u32[0]);
	// 0x299D58: ret
	return;
}

void sub_299D60(X86Context& ctx, uint8_t* base) {
	// 0x299D60: movss xmm0, dword ptr [0x0056ECF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECF0u);
	// 0x299D68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299D70: movss [0x0056ED24], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED24u, ctx.xmm[0].u32[0]);
	// 0x299D78: ret
	return;
}

void sub_299D80(X86Context& ctx, uint8_t* base) {
	// 0x299D80: movss xmm0, dword ptr [0x0056ED38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED38u);
	// 0x299D88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299D90: movss [0x0056ED48], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED48u, ctx.xmm[0].u32[0]);
	// 0x299D98: ret
	return;
}

void sub_299DA0(X86Context& ctx, uint8_t* base) {
	// 0x299DA0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x299DA8: movss [0x0056ECB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECB0u, ctx.xmm[0].u32[0]);
	// 0x299DB0: ret
	return;
}

void sub_299DC0(X86Context& ctx, uint8_t* base) {
	// 0x299DC0: movss xmm0, dword ptr [0x0056ECE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECE0u);
	// 0x299DC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299DD0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x299DD8: movss [0x0056ED30], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED30u, ctx.xmm[0].u32[0]);
	// 0x299DE0: ret
	return;
}

void sub_299DF0(X86Context& ctx, uint8_t* base) {
	// 0x299DF0: movss xmm0, dword ptr [0x0056ED34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED34u);
	// 0x299DF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299E00: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x299E08: movss [0x0056ECC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECC8u, ctx.xmm[0].u32[0]);
	// 0x299E10: ret
	return;
}

void sub_299E20(X86Context& ctx, uint8_t* base) {
	// 0x299E20: movss xmm0, dword ptr [0x0056ECE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECE0u);
	// 0x299E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299E30: movss [0x0056ECD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECD0u, ctx.xmm[0].u32[0]);
	// 0x299E38: ret
	return;
}

void sub_299E40(X86Context& ctx, uint8_t* base) {
	// 0x299E40: movss xmm0, dword ptr [0x0056ED34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED34u);
	// 0x299E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x299E50: movss [0x0056ED3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED3Cu, ctx.xmm[0].u32[0]);
	// 0x299E58: ret
	return;
}

void sub_299E60(X86Context& ctx, uint8_t* base) {
	// 0x299E60: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x299E68: movss [0x0056ECB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECB4u, ctx.xmm[0].u32[0]);
	// 0x299E70: ret
	return;
}

void sub_299E80(X86Context& ctx, uint8_t* base) {
	// 0x299E80: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x299E88: movss [0x0056ECEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECECu, ctx.xmm[0].u32[0]);
	// 0x299E90: ret
	return;
}

void sub_299EA0(X86Context& ctx, uint8_t* base) {
	// 0x299EA0: movss xmm0, dword ptr [0x0056ECB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECB4u);
	// 0x299EA8: movss [0x0056ED50], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED50u, ctx.xmm[0].u32[0]);
	// 0x299EB0: ret
	return;
}

void sub_299EC0(X86Context& ctx, uint8_t* base) {
	// 0x299EC0: movss xmm0, dword ptr [0x0056ED34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED34u);
	// 0x299EC8: subss xmm0, [0x0056ECB4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ECB4u);
	// 0x299ED0: movss [0x0056ED14], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED14u, ctx.xmm[0].u32[0]);
	// 0x299ED8: ret
	return;
}

void sub_299EE0(X86Context& ctx, uint8_t* base) {
	// 0x299EE0: movss xmm0, dword ptr [0x0056ED14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED14u);
	// 0x299EE8: subss xmm0, [0x0056ECEC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ECECu);
	// 0x299EF0: movss [0x0056ED0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED0Cu, ctx.xmm[0].u32[0]);
	// 0x299EF8: ret
	return;
}

void sub_299F00(X86Context& ctx, uint8_t* base) {
	// 0x299F00: movss xmm0, dword ptr [0x0056ED3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED3Cu);
	// 0x299F08: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x299F10: movss [0x0056ECFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECFCu, ctx.xmm[0].u32[0]);
	// 0x299F18: ret
	return;
}

void sub_299F20(X86Context& ctx, uint8_t* base) {
	// 0x299F20: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x299F28: movss [0x0056ECE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECE8u, ctx.xmm[0].u32[0]);
	// 0x299F30: ret
	return;
}

void sub_299F40(X86Context& ctx, uint8_t* base) {
	// 0x299F40: movss xmm0, dword ptr [0x0056ECFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECFCu);
	// 0x299F48: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x299F50: movss [0x0056ED2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED2Cu, ctx.xmm[0].u32[0]);
	// 0x299F58: ret
	return;
}

void sub_299F60(X86Context& ctx, uint8_t* base) {
	// 0x299F60: movss xmm0, dword ptr [0x003B1FAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1FACu);
	// 0x299F68: movss [0x0056ED5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED5Cu, ctx.xmm[0].u32[0]);
	// 0x299F70: ret
	return;
}

void sub_299F80(X86Context& ctx, uint8_t* base) {
	// 0x299F80: movss xmm0, dword ptr [0x0056ECE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ECE0u);
	// 0x299F88: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x299F90: movss [0x00405630], xmm0
	X86_MEM_WRITE_u32(base, 0x405630u, ctx.xmm[0].u32[0]);
	// 0x299F98: ret
	return;
}

void sub_299FA0(X86Context& ctx, uint8_t* base) {
	// 0x299FA0: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x299FA8: movss [0x0056ECCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECCCu, ctx.xmm[0].u32[0]);
	// 0x299FB0: ret
	return;
}

void sub_299FC0(X86Context& ctx, uint8_t* base) {
	// 0x299FC0: movss xmm0, dword ptr [0x00405658]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x405658u);
	// 0x299FC8: addss xmm0, [0x00405650]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x405650u);
	// 0x299FD0: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x299FD8: movss [0x0056ECD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECD8u, ctx.xmm[0].u32[0]);
	// 0x299FE0: movss xmm0, dword ptr [0x00405654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x405654u);
	// 0x299FE8: movss [0x0056ECDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56ECDCu, ctx.xmm[0].u32[0]);
	// 0x299FF0: ret
	return;
}

void sub_29A000(X86Context& ctx, uint8_t* base) {
	// 0x29A000: movss xmm0, dword ptr [0x0040565C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x40565Cu);
	// 0x29A008: movss [0x0056ED58], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED58u, ctx.xmm[0].u32[0]);
	// 0x29A010: ret
	return;
}

void sub_29A020(X86Context& ctx, uint8_t* base) {
	// 0x29A020: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29A028: movss [0x0056EDB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDB8u, ctx.xmm[0].u32[0]);
	// 0x29A030: ret
	return;
}

void sub_29A040(X86Context& ctx, uint8_t* base) {
	// 0x29A040: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29A048: movss [0x0056EDD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDD4u, ctx.xmm[0].u32[0]);
	// 0x29A050: ret
	return;
}

void sub_29A060(X86Context& ctx, uint8_t* base) {
	// 0x29A060: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29A068: movss [0x0056EDAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDACu, ctx.xmm[0].u32[0]);
	// 0x29A070: ret
	return;
}

void sub_29A080(X86Context& ctx, uint8_t* base) {
	// 0x29A080: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29A088: movss [0x0056ED64], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED64u, ctx.xmm[0].u32[0]);
	// 0x29A090: ret
	return;
}

