#include "x86_recomp_shared.h"

void sub_2BD840(X86Context& ctx, uint8_t* base) {
	// 0x2BD840: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BD848: movss [0x005A87F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87F8u, ctx.xmm[0].u32[0]);
	// 0x2BD850: ret
	return;
}

void sub_2BD860(X86Context& ctx, uint8_t* base) {
	// 0x2BD860: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BD868: movss [0x005A8828], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8828u, ctx.xmm[0].u32[0]);
	// 0x2BD870: ret
	return;
}

void sub_2BD880(X86Context& ctx, uint8_t* base) {
	// 0x2BD880: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BD888: movss [0x005A8810], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8810u, ctx.xmm[0].u32[0]);
	// 0x2BD890: ret
	return;
}

void sub_2BD8A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD8A0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BD8A8: movss [0x005A87EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87ECu, ctx.xmm[0].u32[0]);
	// 0x2BD8B0: ret
	return;
}

void sub_2BD8C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD8C0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BD8C8: movss [0x005A87E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A87E4u, ctx.xmm[0].u32[0]);
	// 0x2BD8D0: ret
	return;
}

void sub_2BD8E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD8E0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2BD8E8: movss [0x005A880C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A880Cu, ctx.xmm[0].u32[0]);
	// 0x2BD8F0: ret
	return;
}

void sub_2BD900(X86Context& ctx, uint8_t* base) {
	// 0x2BD900: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BD908: movss [0x005A8858], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8858u, ctx.xmm[0].u32[0]);
	// 0x2BD910: ret
	return;
}

void sub_2BD920(X86Context& ctx, uint8_t* base) {
	// 0x2BD920: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BD928: movss [0x005A8864], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8864u, ctx.xmm[0].u32[0]);
	// 0x2BD930: ret
	return;
}

void sub_2BD940(X86Context& ctx, uint8_t* base) {
	// 0x2BD940: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BD948: movss [0x005A8854], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8854u, ctx.xmm[0].u32[0]);
	// 0x2BD950: ret
	return;
}

void sub_2BD960(X86Context& ctx, uint8_t* base) {
	// 0x2BD960: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BD968: movss [0x005A883C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A883Cu, ctx.xmm[0].u32[0]);
	// 0x2BD970: ret
	return;
}

void sub_2BD980(X86Context& ctx, uint8_t* base) {
	// 0x2BD980: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BD988: movss [0x005A885C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A885Cu, ctx.xmm[0].u32[0]);
	// 0x2BD990: ret
	return;
}

void sub_2BD9A0(X86Context& ctx, uint8_t* base) {
	// 0x2BD9A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BD9A8: movss [0x005A8844], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8844u, ctx.xmm[0].u32[0]);
	// 0x2BD9B0: ret
	return;
}

void sub_2BD9C0(X86Context& ctx, uint8_t* base) {
	// 0x2BD9C0: movss xmm0, dword ptr [0x005A885C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A885Cu);
	// 0x2BD9C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BD9D0: movss [0x005A886C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A886Cu, ctx.xmm[0].u32[0]);
	// 0x2BD9D8: ret
	return;
}

void sub_2BD9E0(X86Context& ctx, uint8_t* base) {
	// 0x2BD9E0: movss xmm0, dword ptr [0x005A8844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8844u);
	// 0x2BD9E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BD9F0: movss [0x005A8868], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8868u, ctx.xmm[0].u32[0]);
	// 0x2BD9F8: ret
	return;
}

void sub_2BDA00(X86Context& ctx, uint8_t* base) {
	// 0x2BDA00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BDA08: movss [0x005A887C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A887Cu, ctx.xmm[0].u32[0]);
	// 0x2BDA10: ret
	return;
}

void sub_2BDA20(X86Context& ctx, uint8_t* base) {
	// 0x2BDA20: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BDA28: movss [0x005A8870], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8870u, ctx.xmm[0].u32[0]);
	// 0x2BDA30: ret
	return;
}

void sub_2BDA40(X86Context& ctx, uint8_t* base) {
	// 0x2BDA40: movss xmm0, dword ptr [0x005A8870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8870u);
	// 0x2BDA48: movss [0x005A8878], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8878u, ctx.xmm[0].u32[0]);
	// 0x2BDA50: ret
	return;
}

void sub_2BDA60(X86Context& ctx, uint8_t* base) {
	// 0x2BDA60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BDA68: movss [0x005A8840], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8840u, ctx.xmm[0].u32[0]);
	// 0x2BDA70: ret
	return;
}

void sub_2BDA80(X86Context& ctx, uint8_t* base) {
	// 0x2BDA80: movss xmm0, dword ptr [0x005A8844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8844u);
	// 0x2BDA88: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BDA90: movss [0x005A8874], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8874u, ctx.xmm[0].u32[0]);
	// 0x2BDA98: ret
	return;
}

void sub_2BDAA0(X86Context& ctx, uint8_t* base) {
	// 0x2BDAA0: movss xmm0, dword ptr [0x005A8844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8844u);
	// 0x2BDAA8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BDAB0: movss [0x005A8850], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8850u, ctx.xmm[0].u32[0]);
	// 0x2BDAB8: ret
	return;
}

void sub_2BDAC0(X86Context& ctx, uint8_t* base) {
	// 0x2BDAC0: movss xmm0, dword ptr [0x005A8844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8844u);
	// 0x2BDAC8: subss xmm0, [0x005A8850]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8850u);
	// 0x2BDAD0: movss [0x005A884C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A884Cu, ctx.xmm[0].u32[0]);
	// 0x2BDAD8: ret
	return;
}

void sub_2BDAE0(X86Context& ctx, uint8_t* base) {
	// 0x2BDAE0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BDAE8: movss [0x005A8860], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8860u, ctx.xmm[0].u32[0]);
	// 0x2BDAF0: ret
	return;
}

void sub_2BDB00(X86Context& ctx, uint8_t* base) {
	// 0x2BDB00: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BDB08: movss [0x005A8848], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8848u, ctx.xmm[0].u32[0]);
	// 0x2BDB10: ret
	return;
}

void sub_2BDB20(X86Context& ctx, uint8_t* base) {
	// 0x2BDB20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BDB28: movss [0x005A88A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88A4u, ctx.xmm[0].u32[0]);
	// 0x2BDB30: ret
	return;
}

void sub_2BDB40(X86Context& ctx, uint8_t* base) {
	// 0x2BDB40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BDB48: movss [0x005A88AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88ACu, ctx.xmm[0].u32[0]);
	// 0x2BDB50: ret
	return;
}

void sub_2BDB60(X86Context& ctx, uint8_t* base) {
	// 0x2BDB60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BDB68: movss [0x005A889C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A889Cu, ctx.xmm[0].u32[0]);
	// 0x2BDB70: ret
	return;
}

void sub_2BDB80(X86Context& ctx, uint8_t* base) {
	// 0x2BDB80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BDB88: movss [0x005A8880], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8880u, ctx.xmm[0].u32[0]);
	// 0x2BDB90: ret
	return;
}

void sub_2BDBA0(X86Context& ctx, uint8_t* base) {
	// 0x2BDBA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BDBA8: movss [0x005A88A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88A8u, ctx.xmm[0].u32[0]);
	// 0x2BDBB0: ret
	return;
}

void sub_2BDBC0(X86Context& ctx, uint8_t* base) {
	// 0x2BDBC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BDBC8: movss [0x005A8884], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8884u, ctx.xmm[0].u32[0]);
	// 0x2BDBD0: ret
	return;
}

void sub_2BDBE0(X86Context& ctx, uint8_t* base) {
	// 0x2BDBE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BDBE8: movss [0x005A88B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88B8u, ctx.xmm[0].u32[0]);
	// 0x2BDBF0: ret
	return;
}

void sub_2BDC00(X86Context& ctx, uint8_t* base) {
	// 0x2BDC00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BDC08: movss [0x005A88A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88A0u, ctx.xmm[0].u32[0]);
	// 0x2BDC10: ret
	return;
}

void sub_2BDC20(X86Context& ctx, uint8_t* base) {
	// 0x2BDC20: movss xmm0, dword ptr [0x005A88B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88B8u);
	// 0x2BDC28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BDC30: movss [0x005A888C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A888Cu, ctx.xmm[0].u32[0]);
	// 0x2BDC38: ret
	return;
}

void sub_2BDC40(X86Context& ctx, uint8_t* base) {
	// 0x2BDC40: movss xmm0, dword ptr [0x005A88A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88A0u);
	// 0x2BDC48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BDC50: movss [0x005A88B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88B4u, ctx.xmm[0].u32[0]);
	// 0x2BDC58: ret
	return;
}

void sub_2BDC60(X86Context& ctx, uint8_t* base) {
	// 0x2BDC60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BDC68: movss [0x005A88C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88C4u, ctx.xmm[0].u32[0]);
	// 0x2BDC70: ret
	return;
}

void sub_2BDC80(X86Context& ctx, uint8_t* base) {
	// 0x2BDC80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BDC88: movss [0x005A88BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88BCu, ctx.xmm[0].u32[0]);
	// 0x2BDC90: ret
	return;
}

void sub_2BDCA0(X86Context& ctx, uint8_t* base) {
	// 0x2BDCA0: movss xmm0, dword ptr [0x005A88BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88BCu);
	// 0x2BDCA8: movss [0x005A88C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88C0u, ctx.xmm[0].u32[0]);
	// 0x2BDCB0: ret
	return;
}

void sub_2BDCC0(X86Context& ctx, uint8_t* base) {
	// 0x2BDCC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BDCC8: movss [0x005A8898], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8898u, ctx.xmm[0].u32[0]);
	// 0x2BDCD0: ret
	return;
}

void sub_2BDCE0(X86Context& ctx, uint8_t* base) {
	// 0x2BDCE0: movss xmm0, dword ptr [0x005A88A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88A0u);
	// 0x2BDCE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BDCF0: movss [0x005A8894], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8894u, ctx.xmm[0].u32[0]);
	// 0x2BDCF8: ret
	return;
}

void sub_2BDD00(X86Context& ctx, uint8_t* base) {
	// 0x2BDD00: movss xmm0, dword ptr [0x005A88A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88A0u);
	// 0x2BDD08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BDD10: movss [0x005A88B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88B0u, ctx.xmm[0].u32[0]);
	// 0x2BDD18: ret
	return;
}

void sub_2BDD20(X86Context& ctx, uint8_t* base) {
	// 0x2BDD20: movss xmm0, dword ptr [0x005A88A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88A0u);
	// 0x2BDD28: subss xmm0, [0x005A88B0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A88B0u);
	// 0x2BDD30: movss [0x005A8888], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8888u, ctx.xmm[0].u32[0]);
	// 0x2BDD38: ret
	return;
}

void sub_2BDD40(X86Context& ctx, uint8_t* base) {
	// 0x2BDD40: movss xmm0, dword ptr [0x003B1730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2BDD48: movss [0x005A8890], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8890u, ctx.xmm[0].u32[0]);
	// 0x2BDD50: ret
	return;
}

void sub_2BDD60(X86Context& ctx, uint8_t* base) {
	// 0x2BDD60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BDD68: movss [0x005A88CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88CCu, ctx.xmm[0].u32[0]);
	// 0x2BDD70: ret
	return;
}

void sub_2BDD80(X86Context& ctx, uint8_t* base) {
	// 0x2BDD80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BDD88: movss [0x005A88D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88D0u, ctx.xmm[0].u32[0]);
	// 0x2BDD90: ret
	return;
}

void sub_2BDDA0(X86Context& ctx, uint8_t* base) {
	// 0x2BDDA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BDDA8: movss [0x005A88C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88C8u, ctx.xmm[0].u32[0]);
	// 0x2BDDB0: ret
	return;
}

void sub_2BDDC0(X86Context& ctx, uint8_t* base) {
	// 0x2BDDC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BDDC8: movss [0x005A88F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88F0u, ctx.xmm[0].u32[0]);
	// 0x2BDDD0: ret
	return;
}

void sub_2BDDE0(X86Context& ctx, uint8_t* base) {
	// 0x2BDDE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BDDE8: movss [0x005A88FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88FCu, ctx.xmm[0].u32[0]);
	// 0x2BDDF0: ret
	return;
}

void sub_2BDE00(X86Context& ctx, uint8_t* base) {
	// 0x2BDE00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BDE08: movss [0x005A88EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88ECu, ctx.xmm[0].u32[0]);
	// 0x2BDE10: ret
	return;
}

void sub_2BDE20(X86Context& ctx, uint8_t* base) {
	// 0x2BDE20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BDE28: movss [0x005A88D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88D4u, ctx.xmm[0].u32[0]);
	// 0x2BDE30: ret
	return;
}

void sub_2BDE40(X86Context& ctx, uint8_t* base) {
	// 0x2BDE40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BDE48: movss [0x005A88F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88F4u, ctx.xmm[0].u32[0]);
	// 0x2BDE50: ret
	return;
}

void sub_2BDE60(X86Context& ctx, uint8_t* base) {
	// 0x2BDE60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BDE68: movss [0x005A88DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88DCu, ctx.xmm[0].u32[0]);
	// 0x2BDE70: ret
	return;
}

void sub_2BDE80(X86Context& ctx, uint8_t* base) {
	// 0x2BDE80: movss xmm0, dword ptr [0x005A88F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88F4u);
	// 0x2BDE88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BDE90: movss [0x005A8904], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8904u, ctx.xmm[0].u32[0]);
	// 0x2BDE98: ret
	return;
}

void sub_2BDEA0(X86Context& ctx, uint8_t* base) {
	// 0x2BDEA0: movss xmm0, dword ptr [0x005A88DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88DCu);
	// 0x2BDEA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BDEB0: movss [0x005A8900], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8900u, ctx.xmm[0].u32[0]);
	// 0x2BDEB8: ret
	return;
}

void sub_2BDEC0(X86Context& ctx, uint8_t* base) {
	// 0x2BDEC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BDEC8: movss [0x005A8914], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8914u, ctx.xmm[0].u32[0]);
	// 0x2BDED0: ret
	return;
}

void sub_2BDEE0(X86Context& ctx, uint8_t* base) {
	// 0x2BDEE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BDEE8: movss [0x005A8908], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8908u, ctx.xmm[0].u32[0]);
	// 0x2BDEF0: ret
	return;
}

void sub_2BDF00(X86Context& ctx, uint8_t* base) {
	// 0x2BDF00: movss xmm0, dword ptr [0x005A8908]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8908u);
	// 0x2BDF08: movss [0x005A8910], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8910u, ctx.xmm[0].u32[0]);
	// 0x2BDF10: ret
	return;
}

void sub_2BDF20(X86Context& ctx, uint8_t* base) {
	// 0x2BDF20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BDF28: movss [0x005A88D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88D8u, ctx.xmm[0].u32[0]);
	// 0x2BDF30: ret
	return;
}

void sub_2BDF40(X86Context& ctx, uint8_t* base) {
	// 0x2BDF40: movss xmm0, dword ptr [0x005A88DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88DCu);
	// 0x2BDF48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BDF50: movss [0x005A890C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A890Cu, ctx.xmm[0].u32[0]);
	// 0x2BDF58: ret
	return;
}

void sub_2BDF60(X86Context& ctx, uint8_t* base) {
	// 0x2BDF60: movss xmm0, dword ptr [0x005A88DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88DCu);
	// 0x2BDF68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BDF70: movss [0x005A88E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88E8u, ctx.xmm[0].u32[0]);
	// 0x2BDF78: ret
	return;
}

void sub_2BDF80(X86Context& ctx, uint8_t* base) {
	// 0x2BDF80: movss xmm0, dword ptr [0x005A88DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A88DCu);
	// 0x2BDF88: subss xmm0, [0x005A88E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A88E8u);
	// 0x2BDF90: movss [0x005A88E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88E4u, ctx.xmm[0].u32[0]);
	// 0x2BDF98: ret
	return;
}

void sub_2BDFA0(X86Context& ctx, uint8_t* base) {
	// 0x2BDFA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BDFA8: movss [0x005A88F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88F8u, ctx.xmm[0].u32[0]);
	// 0x2BDFB0: ret
	return;
}

void sub_2BDFC0(X86Context& ctx, uint8_t* base) {
	// 0x2BDFC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BDFC8: movss [0x005A88E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A88E0u, ctx.xmm[0].u32[0]);
	// 0x2BDFD0: ret
	return;
}

void sub_2BDFE0(X86Context& ctx, uint8_t* base) {
	// 0x2BDFE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BDFE8: movss [0x005A896C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A896Cu, ctx.xmm[0].u32[0]);
	// 0x2BDFF0: ret
	return;
}

void sub_2BE000(X86Context& ctx, uint8_t* base) {
	// 0x2BE000: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BE008: movss [0x005A8988], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8988u, ctx.xmm[0].u32[0]);
	// 0x2BE010: ret
	return;
}

void sub_2BE020(X86Context& ctx, uint8_t* base) {
	// 0x2BE020: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BE028: movss [0x005A8960], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8960u, ctx.xmm[0].u32[0]);
	// 0x2BE030: ret
	return;
}

void sub_2BE040(X86Context& ctx, uint8_t* base) {
	// 0x2BE040: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BE048: movss [0x005A8918], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8918u, ctx.xmm[0].u32[0]);
	// 0x2BE050: ret
	return;
}

void sub_2BE060(X86Context& ctx, uint8_t* base) {
	// 0x2BE060: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BE068: movss [0x005A8970], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8970u, ctx.xmm[0].u32[0]);
	// 0x2BE070: ret
	return;
}

void sub_2BE080(X86Context& ctx, uint8_t* base) {
	// 0x2BE080: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BE088: movss [0x005A8934], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8934u, ctx.xmm[0].u32[0]);
	// 0x2BE090: ret
	return;
}

void sub_2BE0A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE0A0: movss xmm0, dword ptr [0x005A8970]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8970u);
	// 0x2BE0A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BE0B0: movss [0x005A89A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89A8u, ctx.xmm[0].u32[0]);
	// 0x2BE0B8: ret
	return;
}

void sub_2BE0C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE0C0: movss xmm0, dword ptr [0x005A8934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8934u);
	// 0x2BE0C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BE0D0: movss [0x005A8990], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8990u, ctx.xmm[0].u32[0]);
	// 0x2BE0D8: ret
	return;
}

void sub_2BE0E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE0E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BE0E8: movss [0x005A89C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89C0u, ctx.xmm[0].u32[0]);
	// 0x2BE0F0: ret
	return;
}

void sub_2BE100(X86Context& ctx, uint8_t* base) {
	// 0x2BE100: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BE108: movss [0x005A89AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89ACu, ctx.xmm[0].u32[0]);
	// 0x2BE110: ret
	return;
}

void sub_2BE120(X86Context& ctx, uint8_t* base) {
	// 0x2BE120: movss xmm0, dword ptr [0x005A89AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89ACu);
	// 0x2BE128: movss [0x005A89BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89BCu, ctx.xmm[0].u32[0]);
	// 0x2BE130: ret
	return;
}

void sub_2BE140(X86Context& ctx, uint8_t* base) {
	// 0x2BE140: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BE148: movss [0x005A8920], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8920u, ctx.xmm[0].u32[0]);
	// 0x2BE150: ret
	return;
}

void sub_2BE160(X86Context& ctx, uint8_t* base) {
	// 0x2BE160: movss xmm0, dword ptr [0x005A8934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8934u);
	// 0x2BE168: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BE170: movss [0x005A89B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89B4u, ctx.xmm[0].u32[0]);
	// 0x2BE178: ret
	return;
}

void sub_2BE180(X86Context& ctx, uint8_t* base) {
	// 0x2BE180: movss xmm0, dword ptr [0x005A8934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8934u);
	// 0x2BE188: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BE190: movss [0x005A895C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A895Cu, ctx.xmm[0].u32[0]);
	// 0x2BE198: ret
	return;
}

void sub_2BE1A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE1A0: movss xmm0, dword ptr [0x005A8934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8934u);
	// 0x2BE1A8: subss xmm0, [0x005A895C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A895Cu);
	// 0x2BE1B0: movss [0x005A893C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A893Cu, ctx.xmm[0].u32[0]);
	// 0x2BE1B8: ret
	return;
}

void sub_2BE1C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE1C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BE1C8: movss [0x005A8984], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8984u, ctx.xmm[0].u32[0]);
	// 0x2BE1D0: ret
	return;
}

void sub_2BE1E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE1E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BE1E8: movss [0x005A8938], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8938u, ctx.xmm[0].u32[0]);
	// 0x2BE1F0: ret
	return;
}

void sub_2BE200(X86Context& ctx, uint8_t* base) {
	// 0x2BE200: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BE208: movss [0x005A8948], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8948u, ctx.xmm[0].u32[0]);
	// 0x2BE210: ret
	return;
}

void sub_2BE220(X86Context& ctx, uint8_t* base) {
	// 0x2BE220: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BE228: movss [0x005A899C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A899Cu, ctx.xmm[0].u32[0]);
	// 0x2BE230: ret
	return;
}

void sub_2BE240(X86Context& ctx, uint8_t* base) {
	// 0x2BE240: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2BE248: movss [0x005A8980], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8980u, ctx.xmm[0].u32[0]);
	// 0x2BE250: ret
	return;
}

void sub_2BE260(X86Context& ctx, uint8_t* base) {
	// 0x2BE260: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2BE268: movss [0x005A8930], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8930u, ctx.xmm[0].u32[0]);
	// 0x2BE270: ret
	return;
}

void sub_2BE280(X86Context& ctx, uint8_t* base) {
	// 0x2BE280: movss xmm0, dword ptr [0x005A8948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8948u);
	// 0x2BE288: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BE290: movss [0x005A8924], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8924u, ctx.xmm[0].u32[0]);
	// 0x2BE298: ret
	return;
}

void sub_2BE2A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE2A0: movss xmm0, dword ptr [0x005A899C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A899Cu);
	// 0x2BE2A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BE2B0: movss [0x005A8968], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8968u, ctx.xmm[0].u32[0]);
	// 0x2BE2B8: ret
	return;
}

void sub_2BE2C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE2C0: movss xmm0, dword ptr [0x005A8924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8924u);
	// 0x2BE2C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BE2D0: movss [0x005A8978], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8978u, ctx.xmm[0].u32[0]);
	// 0x2BE2D8: ret
	return;
}

void sub_2BE2E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE2E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2BE2E8: movss [0x005A891C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A891Cu, ctx.xmm[0].u32[0]);
	// 0x2BE2F0: ret
	return;
}

void sub_2BE300(X86Context& ctx, uint8_t* base) {
	// 0x2BE300: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2BE308: movss [0x005A894C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A894Cu, ctx.xmm[0].u32[0]);
	// 0x2BE310: ret
	return;
}

void sub_2BE320(X86Context& ctx, uint8_t* base) {
	// 0x2BE320: movss xmm0, dword ptr [0x005A8948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8948u);
	// 0x2BE328: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2BE330: movss [0x005A8958], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8958u, ctx.xmm[0].u32[0]);
	// 0x2BE338: ret
	return;
}

void sub_2BE340(X86Context& ctx, uint8_t* base) {
	// 0x2BE340: movss xmm0, dword ptr [0x005A899C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A899Cu);
	// 0x2BE348: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2BE350: movss [0x005A89A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89A0u, ctx.xmm[0].u32[0]);
	// 0x2BE358: ret
	return;
}

void sub_2BE360(X86Context& ctx, uint8_t* base) {
	// 0x2BE360: movss xmm0, dword ptr [0x005A8958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8958u);
	// 0x2BE368: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BE370: movss [0x005A898C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A898Cu, ctx.xmm[0].u32[0]);
	// 0x2BE378: ret
	return;
}

void sub_2BE380(X86Context& ctx, uint8_t* base) {
	// 0x2BE380: movss xmm0, dword ptr [0x005A89A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89A0u);
	// 0x2BE388: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BE390: movss [0x005A89B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89B0u, ctx.xmm[0].u32[0]);
	// 0x2BE398: ret
	return;
}

void sub_2BE3A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE3A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2BE3A8: movss [0x005A8928], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8928u, ctx.xmm[0].u32[0]);
	// 0x2BE3B0: ret
	return;
}

void sub_2BE3C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE3C0: movss xmm0, dword ptr [0x005A8948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8948u);
	// 0x2BE3C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BE3D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2BE3D8: movss [0x005A8998], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8998u, ctx.xmm[0].u32[0]);
	// 0x2BE3E0: ret
	return;
}

void sub_2BE3F0(X86Context& ctx, uint8_t* base) {
	// 0x2BE3F0: movss xmm0, dword ptr [0x005A899C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A899Cu);
	// 0x2BE3F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BE400: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2BE408: movss [0x005A8940], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8940u, ctx.xmm[0].u32[0]);
	// 0x2BE410: ret
	return;
}

void sub_2BE420(X86Context& ctx, uint8_t* base) {
	// 0x2BE420: movss xmm0, dword ptr [0x005A8948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8948u);
	// 0x2BE428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BE430: movss [0x005A8944], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8944u, ctx.xmm[0].u32[0]);
	// 0x2BE438: ret
	return;
}

void sub_2BE440(X86Context& ctx, uint8_t* base) {
	// 0x2BE440: movss xmm0, dword ptr [0x005A899C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A899Cu);
	// 0x2BE448: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2BE450: movss [0x005A89A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89A4u, ctx.xmm[0].u32[0]);
	// 0x2BE458: ret
	return;
}

void sub_2BE460(X86Context& ctx, uint8_t* base) {
	// 0x2BE460: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2BE468: movss [0x005A892C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A892Cu, ctx.xmm[0].u32[0]);
	// 0x2BE470: ret
	return;
}

void sub_2BE480(X86Context& ctx, uint8_t* base) {
	// 0x2BE480: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2BE488: movss [0x005A8954], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8954u, ctx.xmm[0].u32[0]);
	// 0x2BE490: ret
	return;
}

void sub_2BE4A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE4A0: movss xmm0, dword ptr [0x005A892C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A892Cu);
	// 0x2BE4A8: movss [0x005A89B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89B8u, ctx.xmm[0].u32[0]);
	// 0x2BE4B0: ret
	return;
}

void sub_2BE4C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE4C0: movss xmm0, dword ptr [0x005A899C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A899Cu);
	// 0x2BE4C8: subss xmm0, [0x005A892C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A892Cu);
	// 0x2BE4D0: movss [0x005A897C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A897Cu, ctx.xmm[0].u32[0]);
	// 0x2BE4D8: ret
	return;
}

void sub_2BE4E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE4E0: movss xmm0, dword ptr [0x005A897C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A897Cu);
	// 0x2BE4E8: subss xmm0, [0x005A8954]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8954u);
	// 0x2BE4F0: movss [0x005A8974], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8974u, ctx.xmm[0].u32[0]);
	// 0x2BE4F8: ret
	return;
}

void sub_2BE500(X86Context& ctx, uint8_t* base) {
	// 0x2BE500: movss xmm0, dword ptr [0x005A89A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89A4u);
	// 0x2BE508: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2BE510: movss [0x005A8964], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8964u, ctx.xmm[0].u32[0]);
	// 0x2BE518: ret
	return;
}

void sub_2BE520(X86Context& ctx, uint8_t* base) {
	// 0x2BE520: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2BE528: movss [0x005A8950], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8950u, ctx.xmm[0].u32[0]);
	// 0x2BE530: ret
	return;
}

void sub_2BE540(X86Context& ctx, uint8_t* base) {
	// 0x2BE540: movss xmm0, dword ptr [0x005A8964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8964u);
	// 0x2BE548: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2BE550: movss [0x005A8994], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8994u, ctx.xmm[0].u32[0]);
	// 0x2BE558: ret
	return;
}

void sub_2BE560(X86Context& ctx, uint8_t* base) {
	// 0x2BE560: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BE568: movss [0x005A89E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89E0u, ctx.xmm[0].u32[0]);
	// 0x2BE570: ret
	return;
}

void sub_2BE580(X86Context& ctx, uint8_t* base) {
	// 0x2BE580: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BE588: movss [0x005A89EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89ECu, ctx.xmm[0].u32[0]);
	// 0x2BE590: ret
	return;
}

void sub_2BE5A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE5A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BE5A8: movss [0x005A89DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89DCu, ctx.xmm[0].u32[0]);
	// 0x2BE5B0: ret
	return;
}

void sub_2BE5C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE5C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BE5C8: movss [0x005A89C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89C4u, ctx.xmm[0].u32[0]);
	// 0x2BE5D0: ret
	return;
}

void sub_2BE5E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE5E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BE5E8: movss [0x005A89E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89E4u, ctx.xmm[0].u32[0]);
	// 0x2BE5F0: ret
	return;
}

void sub_2BE600(X86Context& ctx, uint8_t* base) {
	// 0x2BE600: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BE608: movss [0x005A89CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89CCu, ctx.xmm[0].u32[0]);
	// 0x2BE610: ret
	return;
}

void sub_2BE620(X86Context& ctx, uint8_t* base) {
	// 0x2BE620: movss xmm0, dword ptr [0x005A89E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89E4u);
	// 0x2BE628: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BE630: movss [0x005A89F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89F4u, ctx.xmm[0].u32[0]);
	// 0x2BE638: ret
	return;
}

void sub_2BE640(X86Context& ctx, uint8_t* base) {
	// 0x2BE640: movss xmm0, dword ptr [0x005A89CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89CCu);
	// 0x2BE648: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BE650: movss [0x005A89F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89F0u, ctx.xmm[0].u32[0]);
	// 0x2BE658: ret
	return;
}

void sub_2BE660(X86Context& ctx, uint8_t* base) {
	// 0x2BE660: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BE668: movss [0x005A8A04], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A04u, ctx.xmm[0].u32[0]);
	// 0x2BE670: ret
	return;
}

void sub_2BE680(X86Context& ctx, uint8_t* base) {
	// 0x2BE680: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BE688: movss [0x005A89F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89F8u, ctx.xmm[0].u32[0]);
	// 0x2BE690: ret
	return;
}

void sub_2BE6A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE6A0: movss xmm0, dword ptr [0x005A89F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89F8u);
	// 0x2BE6A8: movss [0x005A8A00], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A00u, ctx.xmm[0].u32[0]);
	// 0x2BE6B0: ret
	return;
}

void sub_2BE6C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE6C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BE6C8: movss [0x005A89C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89C8u, ctx.xmm[0].u32[0]);
	// 0x2BE6D0: ret
	return;
}

void sub_2BE6E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE6E0: movss xmm0, dword ptr [0x005A89CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89CCu);
	// 0x2BE6E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BE6F0: movss [0x005A89FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89FCu, ctx.xmm[0].u32[0]);
	// 0x2BE6F8: ret
	return;
}

void sub_2BE700(X86Context& ctx, uint8_t* base) {
	// 0x2BE700: movss xmm0, dword ptr [0x005A89CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89CCu);
	// 0x2BE708: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BE710: movss [0x005A89D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89D8u, ctx.xmm[0].u32[0]);
	// 0x2BE718: ret
	return;
}

void sub_2BE720(X86Context& ctx, uint8_t* base) {
	// 0x2BE720: movss xmm0, dword ptr [0x005A89CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A89CCu);
	// 0x2BE728: subss xmm0, [0x005A89D8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A89D8u);
	// 0x2BE730: movss [0x005A89D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89D4u, ctx.xmm[0].u32[0]);
	// 0x2BE738: ret
	return;
}

void sub_2BE740(X86Context& ctx, uint8_t* base) {
	// 0x2BE740: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BE748: movss [0x005A89E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89E8u, ctx.xmm[0].u32[0]);
	// 0x2BE750: ret
	return;
}

void sub_2BE760(X86Context& ctx, uint8_t* base) {
	// 0x2BE760: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BE768: movss [0x005A89D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A89D0u, ctx.xmm[0].u32[0]);
	// 0x2BE770: ret
	return;
}

void sub_2BE780(X86Context& ctx, uint8_t* base) {
	// 0x2BE780: movss xmm0, dword ptr [0x003B2344]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2344u);
	// 0x2BE788: movss [0x005A8A08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A08u, ctx.xmm[0].u32[0]);
	// 0x2BE790: ret
	return;
}

void sub_2BE7A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE7A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BE7A8: movss [0x005A8A14], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A14u, ctx.xmm[0].u32[0]);
	// 0x2BE7B0: ret
	return;
}

void sub_2BE7C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE7C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BE7C8: movss [0x005A8A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A1Cu, ctx.xmm[0].u32[0]);
	// 0x2BE7D0: ret
	return;
}

void sub_2BE7E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE7E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BE7E8: movss [0x005A8A10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A10u, ctx.xmm[0].u32[0]);
	// 0x2BE7F0: ret
	return;
}

void sub_2BE800(X86Context& ctx, uint8_t* base) {
	// 0x2BE800: movss xmm0, dword ptr [0x003A55F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x2BE808: movss [0x005A8A20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A20u, ctx.xmm[0].u32[0]);
	// 0x2BE810: ret
	return;
}

void sub_2BE820(X86Context& ctx, uint8_t* base) {
	// 0x2BE820: movss xmm0, dword ptr [0x003A55F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x2BE828: movss [0x005A8A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A0Cu, ctx.xmm[0].u32[0]);
	// 0x2BE830: ret
	return;
}

void sub_2BE840(X86Context& ctx, uint8_t* base) {
	// 0x2BE840: movss xmm0, dword ptr [0x003B1730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2BE848: movss [0x005A8A18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A18u, ctx.xmm[0].u32[0]);
	// 0x2BE850: ret
	return;
}

void sub_2BE860(X86Context& ctx, uint8_t* base) {
	// 0x2BE860: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BE868: movss [0x005A8A50], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A50u, ctx.xmm[0].u32[0]);
	// 0x2BE870: ret
	return;
}

void sub_2BE880(X86Context& ctx, uint8_t* base) {
	// 0x2BE880: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BE888: movss [0x005A8A3C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A3Cu, ctx.xmm[0].u32[0]);
	// 0x2BE890: ret
	return;
}

void sub_2BE8A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE8A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BE8A8: movss [0x005A8A48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A48u, ctx.xmm[0].u32[0]);
	// 0x2BE8B0: ret
	return;
}

void sub_2BE8C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE8C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BE8C8: movss [0x005A8A24], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A24u, ctx.xmm[0].u32[0]);
	// 0x2BE8D0: ret
	return;
}

void sub_2BE8E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE8E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BE8E8: movss [0x005A8A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A4Cu, ctx.xmm[0].u32[0]);
	// 0x2BE8F0: ret
	return;
}

void sub_2BE900(X86Context& ctx, uint8_t* base) {
	// 0x2BE900: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BE908: movss [0x005A8A28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A28u, ctx.xmm[0].u32[0]);
	// 0x2BE910: ret
	return;
}

void sub_2BE920(X86Context& ctx, uint8_t* base) {
	// 0x2BE920: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BE928: movss [0x005A8A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A5Cu, ctx.xmm[0].u32[0]);
	// 0x2BE930: ret
	return;
}

void sub_2BE940(X86Context& ctx, uint8_t* base) {
	// 0x2BE940: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BE948: movss [0x005A8A44], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A44u, ctx.xmm[0].u32[0]);
	// 0x2BE950: ret
	return;
}

void sub_2BE960(X86Context& ctx, uint8_t* base) {
	// 0x2BE960: movss xmm0, dword ptr [0x005A8A5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A5Cu);
	// 0x2BE968: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BE970: movss [0x005A8A30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A30u, ctx.xmm[0].u32[0]);
	// 0x2BE978: ret
	return;
}

void sub_2BE980(X86Context& ctx, uint8_t* base) {
	// 0x2BE980: movss xmm0, dword ptr [0x005A8A44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A44u);
	// 0x2BE988: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BE990: movss [0x005A8A58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A58u, ctx.xmm[0].u32[0]);
	// 0x2BE998: ret
	return;
}

void sub_2BE9A0(X86Context& ctx, uint8_t* base) {
	// 0x2BE9A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BE9A8: movss [0x005A8A68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A68u, ctx.xmm[0].u32[0]);
	// 0x2BE9B0: ret
	return;
}

void sub_2BE9C0(X86Context& ctx, uint8_t* base) {
	// 0x2BE9C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BE9C8: movss [0x005A8A60], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A60u, ctx.xmm[0].u32[0]);
	// 0x2BE9D0: ret
	return;
}

void sub_2BE9E0(X86Context& ctx, uint8_t* base) {
	// 0x2BE9E0: movss xmm0, dword ptr [0x005A8A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A60u);
	// 0x2BE9E8: movss [0x005A8A64], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A64u, ctx.xmm[0].u32[0]);
	// 0x2BE9F0: ret
	return;
}

void sub_2BEA00(X86Context& ctx, uint8_t* base) {
	// 0x2BEA00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BEA08: movss [0x005A8A38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A38u, ctx.xmm[0].u32[0]);
	// 0x2BEA10: ret
	return;
}

void sub_2BEA20(X86Context& ctx, uint8_t* base) {
	// 0x2BEA20: movss xmm0, dword ptr [0x005A8A44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A44u);
	// 0x2BEA28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BEA30: movss [0x005A8A34], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A34u, ctx.xmm[0].u32[0]);
	// 0x2BEA38: ret
	return;
}

void sub_2BEA40(X86Context& ctx, uint8_t* base) {
	// 0x2BEA40: movss xmm0, dword ptr [0x005A8A44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A44u);
	// 0x2BEA48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BEA50: movss [0x005A8A54], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A54u, ctx.xmm[0].u32[0]);
	// 0x2BEA58: ret
	return;
}

void sub_2BEA60(X86Context& ctx, uint8_t* base) {
	// 0x2BEA60: movss xmm0, dword ptr [0x005A8A44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A44u);
	// 0x2BEA68: subss xmm0, [0x005A8A54]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8A54u);
	// 0x2BEA70: movss [0x005A8A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A2Cu, ctx.xmm[0].u32[0]);
	// 0x2BEA78: ret
	return;
}

void sub_2BEA80(X86Context& ctx, uint8_t* base) {
	// 0x2BEA80: movss xmm0, dword ptr [0x003B2348]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2348u);
	// 0x2BEA88: movss [0x005A8A40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A40u, ctx.xmm[0].u32[0]);
	// 0x2BEA90: ret
	return;
}

void sub_2BEAA0(X86Context& ctx, uint8_t* base) {
	// 0x2BEAA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BEAA8: movss [0x005A8A88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A88u, ctx.xmm[0].u32[0]);
	// 0x2BEAB0: ret
	return;
}

void sub_2BEAC0(X86Context& ctx, uint8_t* base) {
	// 0x2BEAC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BEAC8: movss [0x005A8A94], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A94u, ctx.xmm[0].u32[0]);
	// 0x2BEAD0: ret
	return;
}

void sub_2BEAE0(X86Context& ctx, uint8_t* base) {
	// 0x2BEAE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BEAE8: movss [0x005A8A84], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A84u, ctx.xmm[0].u32[0]);
	// 0x2BEAF0: ret
	return;
}

void sub_2BEB00(X86Context& ctx, uint8_t* base) {
	// 0x2BEB00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BEB08: movss [0x005A8A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A6Cu, ctx.xmm[0].u32[0]);
	// 0x2BEB10: ret
	return;
}

void sub_2BEB20(X86Context& ctx, uint8_t* base) {
	// 0x2BEB20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BEB28: movss [0x005A8A8C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A8Cu, ctx.xmm[0].u32[0]);
	// 0x2BEB30: ret
	return;
}

void sub_2BEB40(X86Context& ctx, uint8_t* base) {
	// 0x2BEB40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BEB48: movss [0x005A8A74], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A74u, ctx.xmm[0].u32[0]);
	// 0x2BEB50: ret
	return;
}

void sub_2BEB60(X86Context& ctx, uint8_t* base) {
	// 0x2BEB60: movss xmm0, dword ptr [0x005A8A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A8Cu);
	// 0x2BEB68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BEB70: movss [0x005A8A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A9Cu, ctx.xmm[0].u32[0]);
	// 0x2BEB78: ret
	return;
}

void sub_2BEB80(X86Context& ctx, uint8_t* base) {
	// 0x2BEB80: movss xmm0, dword ptr [0x005A8A74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A74u);
	// 0x2BEB88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BEB90: movss [0x005A8A98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A98u, ctx.xmm[0].u32[0]);
	// 0x2BEB98: ret
	return;
}

void sub_2BEBA0(X86Context& ctx, uint8_t* base) {
	// 0x2BEBA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BEBA8: movss [0x005A8AAC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AACu, ctx.xmm[0].u32[0]);
	// 0x2BEBB0: ret
	return;
}

void sub_2BEBC0(X86Context& ctx, uint8_t* base) {
	// 0x2BEBC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BEBC8: movss [0x005A8AA0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AA0u, ctx.xmm[0].u32[0]);
	// 0x2BEBD0: ret
	return;
}

void sub_2BEBE0(X86Context& ctx, uint8_t* base) {
	// 0x2BEBE0: movss xmm0, dword ptr [0x005A8AA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8AA0u);
	// 0x2BEBE8: movss [0x005A8AA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AA8u, ctx.xmm[0].u32[0]);
	// 0x2BEBF0: ret
	return;
}

void sub_2BEC00(X86Context& ctx, uint8_t* base) {
	// 0x2BEC00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BEC08: movss [0x005A8A70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A70u, ctx.xmm[0].u32[0]);
	// 0x2BEC10: ret
	return;
}

void sub_2BEC20(X86Context& ctx, uint8_t* base) {
	// 0x2BEC20: movss xmm0, dword ptr [0x005A8A74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A74u);
	// 0x2BEC28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BEC30: movss [0x005A8AA4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AA4u, ctx.xmm[0].u32[0]);
	// 0x2BEC38: ret
	return;
}

void sub_2BEC40(X86Context& ctx, uint8_t* base) {
	// 0x2BEC40: movss xmm0, dword ptr [0x005A8A74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A74u);
	// 0x2BEC48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BEC50: movss [0x005A8A80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A80u, ctx.xmm[0].u32[0]);
	// 0x2BEC58: ret
	return;
}

void sub_2BEC60(X86Context& ctx, uint8_t* base) {
	// 0x2BEC60: movss xmm0, dword ptr [0x005A8A74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8A74u);
	// 0x2BEC68: subss xmm0, [0x005A8A80]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8A80u);
	// 0x2BEC70: movss [0x005A8A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A7Cu, ctx.xmm[0].u32[0]);
	// 0x2BEC78: ret
	return;
}

void sub_2BEC80(X86Context& ctx, uint8_t* base) {
	// 0x2BEC80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BEC88: movss [0x005A8A90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A90u, ctx.xmm[0].u32[0]);
	// 0x2BEC90: ret
	return;
}

void sub_2BECA0(X86Context& ctx, uint8_t* base) {
	// 0x2BECA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BECA8: movss [0x005A8A78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8A78u, ctx.xmm[0].u32[0]);
	// 0x2BECB0: ret
	return;
}

void sub_2BECC0(X86Context& ctx, uint8_t* base) {
	// 0x2BECC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BECC8: movss [0x005A8AB4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AB4u, ctx.xmm[0].u32[0]);
	// 0x2BECD0: ret
	return;
}

void sub_2BECE0(X86Context& ctx, uint8_t* base) {
	// 0x2BECE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BECE8: movss [0x005A8AB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AB8u, ctx.xmm[0].u32[0]);
	// 0x2BECF0: ret
	return;
}

void sub_2BED00(X86Context& ctx, uint8_t* base) {
	// 0x2BED00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BED08: movss [0x005A8AB0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AB0u, ctx.xmm[0].u32[0]);
	// 0x2BED10: ret
	return;
}

void sub_2BED20(X86Context& ctx, uint8_t* base) {
	// 0x2BED20: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BED28: movss [0x005A8AC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AC0u, ctx.xmm[0].u32[0]);
	// 0x2BED30: ret
	return;
}

void sub_2BED40(X86Context& ctx, uint8_t* base) {
	// 0x2BED40: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BED48: movss [0x005A8ABC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8ABCu, ctx.xmm[0].u32[0]);
	// 0x2BED50: ret
	return;
}

void sub_2BED60(X86Context& ctx, uint8_t* base) {
	// 0x2BED60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2BED68: movss [0x005A8AE0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AE0u, ctx.xmm[0].u32[0]);
	// 0x2BED70: ret
	return;
}

void sub_2BED80(X86Context& ctx, uint8_t* base) {
	// 0x2BED80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2BED88: movss [0x005A8AEC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AECu, ctx.xmm[0].u32[0]);
	// 0x2BED90: ret
	return;
}

void sub_2BEDA0(X86Context& ctx, uint8_t* base) {
	// 0x2BEDA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2BEDA8: movss [0x005A8ADC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8ADCu, ctx.xmm[0].u32[0]);
	// 0x2BEDB0: ret
	return;
}

void sub_2BEDC0(X86Context& ctx, uint8_t* base) {
	// 0x2BEDC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2BEDC8: movss [0x005A8AC4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AC4u, ctx.xmm[0].u32[0]);
	// 0x2BEDD0: ret
	return;
}

void sub_2BEDE0(X86Context& ctx, uint8_t* base) {
	// 0x2BEDE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2BEDE8: movss [0x005A8AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AE4u, ctx.xmm[0].u32[0]);
	// 0x2BEDF0: ret
	return;
}

void sub_2BEE00(X86Context& ctx, uint8_t* base) {
	// 0x2BEE00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2BEE08: movss [0x005A8ACC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8ACCu, ctx.xmm[0].u32[0]);
	// 0x2BEE10: ret
	return;
}

void sub_2BEE20(X86Context& ctx, uint8_t* base) {
	// 0x2BEE20: movss xmm0, dword ptr [0x005A8AE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8AE4u);
	// 0x2BEE28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2BEE30: movss [0x005A8AF4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AF4u, ctx.xmm[0].u32[0]);
	// 0x2BEE38: ret
	return;
}

void sub_2BEE40(X86Context& ctx, uint8_t* base) {
	// 0x2BEE40: movss xmm0, dword ptr [0x005A8ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8ACCu);
	// 0x2BEE48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2BEE50: movss [0x005A8AF0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AF0u, ctx.xmm[0].u32[0]);
	// 0x2BEE58: ret
	return;
}

void sub_2BEE60(X86Context& ctx, uint8_t* base) {
	// 0x2BEE60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BEE68: movss [0x005A8B04], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B04u, ctx.xmm[0].u32[0]);
	// 0x2BEE70: ret
	return;
}

void sub_2BEE80(X86Context& ctx, uint8_t* base) {
	// 0x2BEE80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2BEE88: movss [0x005A8AF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AF8u, ctx.xmm[0].u32[0]);
	// 0x2BEE90: ret
	return;
}

void sub_2BEEA0(X86Context& ctx, uint8_t* base) {
	// 0x2BEEA0: movss xmm0, dword ptr [0x005A8AF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8AF8u);
	// 0x2BEEA8: movss [0x005A8B00], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B00u, ctx.xmm[0].u32[0]);
	// 0x2BEEB0: ret
	return;
}

void sub_2BEEC0(X86Context& ctx, uint8_t* base) {
	// 0x2BEEC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2BEEC8: movss [0x005A8AC8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AC8u, ctx.xmm[0].u32[0]);
	// 0x2BEED0: ret
	return;
}

void sub_2BEEE0(X86Context& ctx, uint8_t* base) {
	// 0x2BEEE0: movss xmm0, dword ptr [0x005A8ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8ACCu);
	// 0x2BEEE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2BEEF0: movss [0x005A8AFC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AFCu, ctx.xmm[0].u32[0]);
	// 0x2BEEF8: ret
	return;
}

void sub_2BEF00(X86Context& ctx, uint8_t* base) {
	// 0x2BEF00: movss xmm0, dword ptr [0x005A8ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8ACCu);
	// 0x2BEF08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2BEF10: movss [0x005A8AD8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AD8u, ctx.xmm[0].u32[0]);
	// 0x2BEF18: ret
	return;
}

void sub_2BEF20(X86Context& ctx, uint8_t* base) {
	// 0x2BEF20: movss xmm0, dword ptr [0x005A8ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8ACCu);
	// 0x2BEF28: subss xmm0, [0x005A8AD8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8AD8u);
	// 0x2BEF30: movss [0x005A8AD4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AD4u, ctx.xmm[0].u32[0]);
	// 0x2BEF38: ret
	return;
}

void sub_2BEF40(X86Context& ctx, uint8_t* base) {
	// 0x2BEF40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2BEF48: movss [0x005A8AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AE8u, ctx.xmm[0].u32[0]);
	// 0x2BEF50: ret
	return;
}

void sub_2BEF60(X86Context& ctx, uint8_t* base) {
	// 0x2BEF60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2BEF68: movss [0x005A8AD0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8AD0u, ctx.xmm[0].u32[0]);
	// 0x2BEF70: ret
	return;
}

void sub_2BEF80(X86Context& ctx, uint8_t* base) {
	// 0x2BEF80: mov eax, 0x03
	ctx.eax = 3;
	// 0x2BEF85: mov ecx, 0x04
	ctx.ecx = 4;
	// 0x2BEF8A: mov edx, 0x02
	ctx.edx = 2;
	// 0x2BEF8F: mov [0x00419A24], eax
	X86_MEM_WRITE_u32(base, 0x419A24u, ctx.eax);
	// 0x2BEF94: mov dword ptr [0x00419A28], 0x3ED230
	X86_MEM_WRITE_u32(base, 0x419A28u, 4117040);
	// 0x2BEF9E: mov dword ptr [0x00419A2C], 0x05
	X86_MEM_WRITE_u32(base, 0x419A2Cu, 5);
	// 0x2BEFA8: mov dword ptr [0x00419A30], 0x3ED118
	X86_MEM_WRITE_u32(base, 0x419A30u, 4116760);
	// 0x2BEFB2: mov [0x00419A34], eax
	X86_MEM_WRITE_u32(base, 0x419A34u, ctx.eax);
	// 0x2BEFB7: mov dword ptr [0x00419A38], 0x3ED190
	X86_MEM_WRITE_u32(base, 0x419A38u, 4116880);
	// 0x2BEFC1: mov [0x00419A3C], ecx
	X86_MEM_WRITE_u32(base, 0x419A3Cu, ctx.ecx);
	// 0x2BEFC7: mov dword ptr [0x00419A40], 0x3ED2F8
	X86_MEM_WRITE_u32(base, 0x419A40u, 4117240);
	// 0x2BEFD1: mov [0x00419A44], eax
	X86_MEM_WRITE_u32(base, 0x419A44u, ctx.eax);
	// 0x2BEFD6: mov dword ptr [0x00419A48], 0x3ED370
	X86_MEM_WRITE_u32(base, 0x419A48u, 4117360);
	// 0x2BEFE0: mov [0x00419A4C], edx
	X86_MEM_WRITE_u32(base, 0x419A4Cu, ctx.edx);
	// 0x2BEFE6: mov dword ptr [0x00419A50], 0x3ED3C0
	X86_MEM_WRITE_u32(base, 0x419A50u, 4117440);
	// 0x2BEFF0: mov [0x00419A54], edx
	X86_MEM_WRITE_u32(base, 0x419A54u, ctx.edx);
	// 0x2BEFF6: mov dword ptr [0x00419A58], 0x3ED410
	X86_MEM_WRITE_u32(base, 0x419A58u, 4117520);
	// 0x2BF000: mov [0x00419A5C], edx
	X86_MEM_WRITE_u32(base, 0x419A5Cu, ctx.edx);
	// 0x2BF006: mov dword ptr [0x00419A60], 0x3ED578
	X86_MEM_WRITE_u32(base, 0x419A60u, 4117880);
	// 0x2BF010: mov [0x00419A64], edx
	X86_MEM_WRITE_u32(base, 0x419A64u, ctx.edx);
	// 0x2BF016: mov dword ptr [0x00419A68], 0x3ED500
	X86_MEM_WRITE_u32(base, 0x419A68u, 4117760);
	// 0x2BF020: mov [0x00419A6C], eax
	X86_MEM_WRITE_u32(base, 0x419A6Cu, ctx.eax);
	// 0x2BF025: mov dword ptr [0x00419A70], 0x3ED460
	X86_MEM_WRITE_u32(base, 0x419A70u, 4117600);
	// 0x2BF02F: mov [0x00419A74], ecx
	X86_MEM_WRITE_u32(base, 0x419A74u, ctx.ecx);
	// 0x2BF035: mov dword ptr [0x00419A78], 0x3ED7F8
	X86_MEM_WRITE_u32(base, 0x419A78u, 4118520);
	// 0x2BF03F: mov [0x00419A7C], eax
	X86_MEM_WRITE_u32(base, 0x419A7Cu, ctx.eax);
	// 0x2BF044: mov dword ptr [0x00419A80], 0x3ED870
	X86_MEM_WRITE_u32(base, 0x419A80u, 4118640);
	// 0x2BF04E: mov [0x00419A84], ecx
	X86_MEM_WRITE_u32(base, 0x419A84u, ctx.ecx);
	// 0x2BF054: mov dword ptr [0x00419A88], 0x3ED5C8
	X86_MEM_WRITE_u32(base, 0x419A88u, 4117960);
	// 0x2BF05E: mov [0x00419A8C], eax
	X86_MEM_WRITE_u32(base, 0x419A8Cu, ctx.eax);
	// 0x2BF063: mov dword ptr [0x00419A90], 0x3ED6B8
	X86_MEM_WRITE_u32(base, 0x419A90u, 4118200);
	// 0x2BF06D: mov dword ptr [0x00419A94], 0x08
	X86_MEM_WRITE_u32(base, 0x419A94u, 8);
	// 0x2BF077: mov dword ptr [0x00419A98], 0x3ED640
	X86_MEM_WRITE_u32(base, 0x419A98u, 4118080);
	// 0x2BF081: mov [0x00419A9C], eax
	X86_MEM_WRITE_u32(base, 0x419A9Cu, ctx.eax);
	// 0x2BF086: mov dword ptr [0x00419AA0], 0x3ED910
	X86_MEM_WRITE_u32(base, 0x419AA0u, 4118800);
	// 0x2BF090: mov dword ptr [0x00419AA4], 0x05
	X86_MEM_WRITE_u32(base, 0x419AA4u, 5);
	// 0x2BF09A: mov dword ptr [0x00419AA8], 0x3ED9D8
	X86_MEM_WRITE_u32(base, 0x419AA8u, 4119000);
	// 0x2BF0A4: mov [0x00419AAC], ecx
	X86_MEM_WRITE_u32(base, 0x419AACu, ctx.ecx);
	// 0x2BF0AA: mov dword ptr [0x00419AB0], 0x3EDB68
	X86_MEM_WRITE_u32(base, 0x419AB0u, 4119400);
	// 0x2BF0B4: mov [0x00419AB4], edx
	X86_MEM_WRITE_u32(base, 0x419AB4u, ctx.edx);
	// 0x2BF0BA: mov dword ptr [0x00419AB8], 0x3EDAF0
	X86_MEM_WRITE_u32(base, 0x419AB8u, 4119280);
	// 0x2BF0C4: mov [0x00419ABC], eax
	X86_MEM_WRITE_u32(base, 0x419ABCu, ctx.eax);
	// 0x2BF0C9: mov dword ptr [0x00419AC0], 0x3EDA78
	X86_MEM_WRITE_u32(base, 0x419AC0u, 4119160);
	// 0x2BF0D3: mov [0x00419AC4], eax
	X86_MEM_WRITE_u32(base, 0x419AC4u, ctx.eax);
	// 0x2BF0D8: mov dword ptr [0x00419AC8], 0x3EDD20
	X86_MEM_WRITE_u32(base, 0x419AC8u, 4119840);
	// 0x2BF0E2: mov [0x00419ACC], eax
	X86_MEM_WRITE_u32(base, 0x419ACCu, ctx.eax);
	// 0x2BF0E7: mov dword ptr [0x00419AD0], 0x3EDBB8
	X86_MEM_WRITE_u32(base, 0x419AD0u, 4119480);
	// 0x2BF0F1: mov [0x00419AD4], eax
	X86_MEM_WRITE_u32(base, 0x419AD4u, ctx.eax);
	// 0x2BF0F6: mov dword ptr [0x00419AD8], 0x3EDCA8
	X86_MEM_WRITE_u32(base, 0x419AD8u, 4119720);
	// 0x2BF100: mov [0x00419ADC], eax
	X86_MEM_WRITE_u32(base, 0x419ADCu, ctx.eax);
	// 0x2BF105: mov dword ptr [0x00419AE0], 0x3EDD98
	X86_MEM_WRITE_u32(base, 0x419AE0u, 4119960);
	// 0x2BF10F: mov [0x00419AE4], ecx
	X86_MEM_WRITE_u32(base, 0x419AE4u, ctx.ecx);
	// 0x2BF115: mov dword ptr [0x00419AE8], 0x3EDC30
	X86_MEM_WRITE_u32(base, 0x419AE8u, 4119600);
	// 0x2BF11F: mov [0x00419AEC], eax
	X86_MEM_WRITE_u32(base, 0x419AECu, ctx.eax);
	// 0x2BF124: mov dword ptr [0x00419AF0], 0x3EDF28
	X86_MEM_WRITE_u32(base, 0x419AF0u, 4120360);
	// 0x2BF12E: mov [0x00419AF4], ecx
	X86_MEM_WRITE_u32(base, 0x419AF4u, ctx.ecx);
	// 0x2BF134: mov dword ptr [0x00419AF8], 0x3EE130
	X86_MEM_WRITE_u32(base, 0x419AF8u, 4120880);
	// 0x2BF13E: mov [0x00419AFC], eax
	X86_MEM_WRITE_u32(base, 0x419AFCu, ctx.eax);
	// 0x2BF143: mov dword ptr [0x00419B00], 0x3EDE38
	X86_MEM_WRITE_u32(base, 0x419B00u, 4120120);
	// 0x2BF14D: mov dword ptr [0x00419B04], 0x06
	X86_MEM_WRITE_u32(base, 0x419B04u, 6);
	// 0x2BF157: mov dword ptr [0x00419B08], 0x3EE090
	X86_MEM_WRITE_u32(base, 0x419B08u, 4120720);
	// 0x2BF161: mov [0x00419B0C], ecx
	X86_MEM_WRITE_u32(base, 0x419B0Cu, ctx.ecx);
	// 0x2BF167: mov dword ptr [0x00419B10], 0x3EDFC8
	X86_MEM_WRITE_u32(base, 0x419B10u, 4120520);
	// 0x2BF171: mov dword ptr [0x00419B14], 0x05
	X86_MEM_WRITE_u32(base, 0x419B14u, 5);
	// 0x2BF17B: mov dword ptr [0x00419B18], 0x3EE1A8
	X86_MEM_WRITE_u32(base, 0x419B18u, 4121000);
	// 0x2BF185: mov [0x00419B1C], eax
	X86_MEM_WRITE_u32(base, 0x419B1Cu, ctx.eax);
	// 0x2BF18A: mov dword ptr [0x00419B20], 0x3EE298
	X86_MEM_WRITE_u32(base, 0x419B20u, 4121240);
	// 0x2BF194: mov dword ptr [0x00419B24], 0x01
	X86_MEM_WRITE_u32(base, 0x419B24u, 1);
	// 0x2BF19E: mov dword ptr [0x00419B28], 0x3EE2C0
	X86_MEM_WRITE_u32(base, 0x419B28u, 4121280);
	// 0x2BF1A8: mov [0x00419B2C], edx
	X86_MEM_WRITE_u32(base, 0x419B2Cu, ctx.edx);
	// 0x2BF1AE: mov dword ptr [0x00419B30], 0x3EE220
	X86_MEM_WRITE_u32(base, 0x419B30u, 4121120);
	// 0x2BF1B8: mov [0x00419B34], eax
	X86_MEM_WRITE_u32(base, 0x419B34u, ctx.eax);
	// 0x2BF1BD: mov dword ptr [0x00419B38], 0x3EE400
	X86_MEM_WRITE_u32(base, 0x419B38u, 4121600);
	// 0x2BF1C7: mov [0x00419B3C], ecx
	X86_MEM_WRITE_u32(base, 0x419B3Cu, ctx.ecx);
	// 0x2BF1CD: mov dword ptr [0x00419B40], 0x3EE310
	X86_MEM_WRITE_u32(base, 0x419B40u, 4121360);
	// 0x2BF1D7: mov [0x00419B44], eax
	X86_MEM_WRITE_u32(base, 0x419B44u, ctx.eax);
	// 0x2BF1DC: mov dword ptr [0x00419B48], 0x3EE568
	X86_MEM_WRITE_u32(base, 0x419B48u, 4121960);
	// 0x2BF1E6: mov [0x00419B4C], eax
	X86_MEM_WRITE_u32(base, 0x419B4Cu, ctx.eax);
	// 0x2BF1EB: mov dword ptr [0x00419B50], 0x3EE388
	X86_MEM_WRITE_u32(base, 0x419B50u, 4121480);
	// 0x2BF1F5: mov [0x00419B54], eax
	X86_MEM_WRITE_u32(base, 0x419B54u, ctx.eax);
	// 0x2BF1FA: mov dword ptr [0x00419B58], 0x3EE4F0
	X86_MEM_WRITE_u32(base, 0x419B58u, 4121840);
	// 0x2BF204: mov [0x00419B5C], eax
	X86_MEM_WRITE_u32(base, 0x419B5Cu, ctx.eax);
	// 0x2BF209: mov dword ptr [0x00419B60], 0x3EE4A0
	X86_MEM_WRITE_u32(base, 0x419B60u, 4121760);
	// 0x2BF213: mov [0x00419B64], edx
	X86_MEM_WRITE_u32(base, 0x419B64u, ctx.edx);
	// 0x2BF219: mov dword ptr [0x00419B68], 0x3EE5E0
	X86_MEM_WRITE_u32(base, 0x419B68u, 4122080);
	// 0x2BF223: mov [0x00419B6C], ecx
	X86_MEM_WRITE_u32(base, 0x419B6Cu, ctx.ecx);
	// 0x2BF229: mov dword ptr [0x00419B70], 0x3EE680
	X86_MEM_WRITE_u32(base, 0x419B70u, 4122240);
	// 0x2BF233: mov [0x00419B74], eax
	X86_MEM_WRITE_u32(base, 0x419B74u, ctx.eax);
	// 0x2BF238: mov dword ptr [0x00419B78], 0x3EE6F8
	X86_MEM_WRITE_u32(base, 0x419B78u, 4122360);
	// 0x2BF242: mov [0x00419B7C], eax
	X86_MEM_WRITE_u32(base, 0x419B7Cu, ctx.eax);
	// 0x2BF247: mov dword ptr [0x00419B80], 0x3EE7E8
	X86_MEM_WRITE_u32(base, 0x419B80u, 4122600);
	// 0x2BF251: mov dword ptr [0x00419B84], 0x06
	X86_MEM_WRITE_u32(base, 0x419B84u, 6);
	// 0x2BF25B: mov dword ptr [0x00419B88], 0x3EE770
	X86_MEM_WRITE_u32(base, 0x419B88u, 4122480);
	// 0x2BF265: mov [0x00419B8C], eax
	X86_MEM_WRITE_u32(base, 0x419B8Cu, ctx.eax);
	// 0x2BF26A: ret
	return;
}

void sub_2BF270(X86Context& ctx, uint8_t* base) {
	// 0x2BF270: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2BF271: mov eax, 0x03
	ctx.eax = 3;
	// 0x2BF276: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2BF277: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2BF278: mov ecx, 0x02
	ctx.ecx = 2;
	// 0x2BF27D: mov esi, 0x01
	ctx.esi = 1;
	// 0x2BF282: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2BF284: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2BF285: mov edi, 0x04
	ctx.edi = 4;
	// 0x2BF28A: mov [0x00419BA0], eax
	X86_MEM_WRITE_u32(base, 0x419BA0u, ctx.eax);
	// 0x2BF28F: mov word ptr [0x00419BA4], 0x58D
	X86_MEM_WRITE_u16(base, 0x419BA4u, 1421);
	// 0x2BF298: mov word ptr [0x00419BA6], 0x1BB
	X86_MEM_WRITE_u16(base, 0x419BA6u, 443);
	// 0x2BF2A1: mov [0x00419BA8], ecx
	X86_MEM_WRITE_u32(base, 0x419BA8u, ctx.ecx);
	// 0x2BF2A7: mov dword ptr [0x00419BAC], 0x77
	X86_MEM_WRITE_u32(base, 0x419BACu, 119);
	// 0x2BF2B1: mov dword ptr [0x00419BB0], 0x3ED460
	X86_MEM_WRITE_u32(base, 0x419BB0u, 4117600);
	// 0x2BF2BB: mov [0x00419BB4], edi
	X86_MEM_WRITE_u32(base, 0x419BB4u, ctx.edi);
	// 0x2BF2C1: mov word ptr [0x00419BB8], 0x27A
	X86_MEM_WRITE_u16(base, 0x419BB8u, 634);
	// 0x2BF2CA: mov word ptr [0x00419BBA], 0x2C6
	X86_MEM_WRITE_u16(base, 0x419BBAu, 710);
	// 0x2BF2D3: mov [0x00419BBC], esi
	X86_MEM_WRITE_u32(base, 0x419BBCu, ctx.esi);
	// 0x2BF2D9: mov dword ptr [0x00419BC0], 0x7E
	X86_MEM_WRITE_u32(base, 0x419BC0u, 126);
	// 0x2BF2E3: mov dword ptr [0x00419BC4], 0x3ED3C0
	X86_MEM_WRITE_u32(base, 0x419BC4u, 4117440);
	// 0x2BF2ED: mov [0x00419BC8], ecx
	X86_MEM_WRITE_u32(base, 0x419BC8u, ctx.ecx);
	// 0x2BF2F3: mov word ptr [0x00419BCC], 0x299
	X86_MEM_WRITE_u16(base, 0x419BCCu, 665);
	// 0x2BF2FC: mov word ptr [0x00419BCE], 0x222
	X86_MEM_WRITE_u16(base, 0x419BCEu, 546);
	// 0x2BF305: mov [0x00419BD0], eax
	X86_MEM_WRITE_u32(base, 0x419BD0u, ctx.eax);
	// 0x2BF30A: mov dword ptr [0x00419BD4], 0x7C
	X86_MEM_WRITE_u32(base, 0x419BD4u, 124);
	// 0x2BF314: mov dword ptr [0x00419BD8], 0x3ED2F8
	X86_MEM_WRITE_u32(base, 0x419BD8u, 4117240);
	// 0x2BF31E: mov [0x00419BDC], eax
	X86_MEM_WRITE_u32(base, 0x419BDCu, ctx.eax);
	// 0x2BF323: mov word ptr [0x00419BE0], 0x4AB
	X86_MEM_WRITE_u16(base, 0x419BE0u, 1195);
	// 0x2BF32C: mov word ptr [0x00419BE2], 0x23A
	X86_MEM_WRITE_u16(base, 0x419BE2u, 570);
	// 0x2BF335: mov [0x00419BE4], esi
	X86_MEM_WRITE_u32(base, 0x419BE4u, ctx.esi);
	// 0x2BF33B: mov dword ptr [0x00419BE8], 0x75
	X86_MEM_WRITE_u32(base, 0x419BE8u, 117);
	// 0x2BF345: mov dword ptr [0x00419BEC], 0x3ED578
	X86_MEM_WRITE_u32(base, 0x419BECu, 4117880);
	// 0x2BF34F: mov [0x00419BF0], ecx
	X86_MEM_WRITE_u32(base, 0x419BF0u, ctx.ecx);
	// 0x2BF355: mov word ptr [0x00419BF4], 0x69
	X86_MEM_WRITE_u16(base, 0x419BF4u, 105);
	// 0x2BF35E: mov word ptr [0x00419BF6], 0x15C
	X86_MEM_WRITE_u16(base, 0x419BF6u, 348);
	// 0x2BF367: mov [0x00419BF8], eax
	X86_MEM_WRITE_u32(base, 0x419BF8u, ctx.eax);
	// 0x2BF36C: mov dword ptr [0x00419BFC], 0x7B
	X86_MEM_WRITE_u32(base, 0x419BFCu, 123);
	// 0x2BF376: mov dword ptr [0x00419C00], 0x3ED190
	X86_MEM_WRITE_u32(base, 0x419C00u, 4116880);
	// 0x2BF380: mov [0x00419C04], edi
	X86_MEM_WRITE_u32(base, 0x419C04u, ctx.edi);
	// 0x2BF386: mov word ptr [0x00419C08], 0xB4
	X86_MEM_WRITE_u16(base, 0x419C08u, 180);
	// 0x2BF38F: mov word ptr [0x00419C0A], 0x1EA
	X86_MEM_WRITE_u16(base, 0x419C0Au, 490);
	// 0x2BF398: mov [0x00419C0C], eax
	X86_MEM_WRITE_u32(base, 0x419C0Cu, ctx.eax);
	// 0x2BF39D: mov dword ptr [0x00419C10], 0x64
	X86_MEM_WRITE_u32(base, 0x419C10u, 100);
	// 0x2BF3A7: mov dword ptr [0x00419C14], 0x3ED640
	X86_MEM_WRITE_u32(base, 0x419C14u, 4118080);
	// 0x2BF3B1: mov [0x00419C18], eax
	X86_MEM_WRITE_u32(base, 0x419C18u, ctx.eax);
	// 0x2BF3B6: mov word ptr [0x00419C1C], 0x489
	X86_MEM_WRITE_u16(base, 0x419C1Cu, 1161);
	// 0x2BF3BF: mov word ptr [0x00419C1E], 0x19B
	X86_MEM_WRITE_u16(base, 0x419C1Eu, 411);
	// 0x2BF3C8: mov [0x00419C20], edx
	X86_MEM_WRITE_u32(base, 0x419C20u, ctx.edx);
	// 0x2BF3CE: mov dword ptr [0x00419C24], 0x56
	X86_MEM_WRITE_u32(base, 0x419C24u, 86);
	// 0x2BF3D8: mov dword ptr [0x00419C28], 0x3EDF28
	X86_MEM_WRITE_u32(base, 0x419C28u, 4120360);
	// 0x2BF3E2: mov [0x00419C2C], edi
	X86_MEM_WRITE_u32(base, 0x419C2Cu, ctx.edi);
	// 0x2BF3E8: mov word ptr [0x00419C30], 0x2DB
	X86_MEM_WRITE_u16(base, 0x419C30u, 731);
	// 0x2BF3F1: mov word ptr [0x00419C32], 0x25B
	X86_MEM_WRITE_u16(base, 0x419C32u, 603);
	// 0x2BF3FA: mov [0x00419C34], edx
	X86_MEM_WRITE_u32(base, 0x419C34u, ctx.edx);
	// 0x2BF400: mov dword ptr [0x00419C38], 0x52
	X86_MEM_WRITE_u32(base, 0x419C38u, 82);
	// 0x2BF40A: mov dword ptr [0x00419C3C], 0x3ED9D8
	X86_MEM_WRITE_u32(base, 0x419C3Cu, 4119000);
	// 0x2BF414: mov [0x00419C40], edi
	X86_MEM_WRITE_u32(base, 0x419C40u, ctx.edi);
	// 0x2BF41A: mov word ptr [0x00419C44], 0x4C9
	X86_MEM_WRITE_u16(base, 0x419C44u, 1225);
	// 0x2BF423: mov word ptr [0x00419C46], 0x2B1
	X86_MEM_WRITE_u16(base, 0x419C46u, 689);
	// 0x2BF42C: mov [0x00419C48], esi
	X86_MEM_WRITE_u32(base, 0x419C48u, ctx.esi);
	// 0x2BF432: mov dword ptr [0x00419C4C], 0x5B
	X86_MEM_WRITE_u32(base, 0x419C4Cu, 91);
	// 0x2BF43C: mov dword ptr [0x00419C50], 0x3EDD20
	X86_MEM_WRITE_u32(base, 0x419C50u, 4119840);
	// 0x2BF446: mov [0x00419C54], eax
	X86_MEM_WRITE_u32(base, 0x419C54u, ctx.eax);
	// 0x2BF44B: mov word ptr [0x00419C58], 0x105
	X86_MEM_WRITE_u16(base, 0x419C58u, 261);
	// 0x2BF454: mov word ptr [0x00419C5A], 0x20D
	X86_MEM_WRITE_u16(base, 0x419C5Au, 525);
	// 0x2BF45D: mov [0x00419C5C], edx
	X86_MEM_WRITE_u32(base, 0x419C5Cu, ctx.edx);
	// 0x2BF463: mov dword ptr [0x00419C60], 0x60
	X86_MEM_WRITE_u32(base, 0x419C60u, 96);
	// 0x2BF46D: mov dword ptr [0x00419C64], 0x3ED7F8
	X86_MEM_WRITE_u32(base, 0x419C64u, 4118520);
	// 0x2BF477: mov [0x00419C68], eax
	X86_MEM_WRITE_u32(base, 0x419C68u, ctx.eax);
	// 0x2BF47C: mov word ptr [0x00419C6C], 0x404
	X86_MEM_WRITE_u16(base, 0x419C6Cu, 1028);
	// 0x2BF485: mov word ptr [0x00419C6E], 0x198
	X86_MEM_WRITE_u16(base, 0x419C6Eu, 408);
	// 0x2BF48E: mov [0x00419C70], esi
	X86_MEM_WRITE_u32(base, 0x419C70u, ctx.esi);
	// 0x2BF494: mov dword ptr [0x00419C74], 0x5A
	X86_MEM_WRITE_u32(base, 0x419C74u, 90);
	// 0x2BF49E: mov dword ptr [0x00419C78], 0x3EDFC8
	X86_MEM_WRITE_u32(base, 0x419C78u, 4120520);
	// 0x2BF4A8: mov dword ptr [0x00419C7C], 0x05
	X86_MEM_WRITE_u32(base, 0x419C7Cu, 5);
	// 0x2BF4B2: mov word ptr [0x00419C80], 0xFF
	X86_MEM_WRITE_u16(base, 0x419C80u, 255);
	// 0x2BF4BB: mov word ptr [0x00419C82], 0x1EF
	X86_MEM_WRITE_u16(base, 0x419C82u, 495);
	// 0x2BF4C4: mov [0x00419C84], ecx
	X86_MEM_WRITE_u32(base, 0x419C84u, ctx.ecx);
	// 0x2BF4CA: mov dword ptr [0x00419C88], 0x63
	X86_MEM_WRITE_u32(base, 0x419C88u, 99);
	// 0x2BF4D4: mov dword ptr [0x00419C8C], 0x3ED6B8
	X86_MEM_WRITE_u32(base, 0x419C8Cu, 4118200);
	// 0x2BF4DE: mov ebx, 0x6B
	ctx.ebx = 107;
	// 0x2BF4E3: mov ebp, 0x3EE400
	ctx.ebp = 4121600;
	// 0x2BF4E8: mov [0x00419D00], ebx
	X86_MEM_WRITE_u32(base, 0x419D00u, ctx.ebx);
	// 0x2BF4EE: mov [0x00419D04], ebp
	X86_MEM_WRITE_u32(base, 0x419D04u, ctx.ebp);
	// 0x2BF4F4: mov [0x00419D14], ebx
	X86_MEM_WRITE_u32(base, 0x419D14u, ctx.ebx);
	// 0x2BF4FA: mov [0x00419D18], ebp
	X86_MEM_WRITE_u32(base, 0x419D18u, ctx.ebp);
	// 0x2BF500: mov ebx, 0x78
	ctx.ebx = 120;
	// 0x2BF505: mov ebp, 0x249
	ctx.ebp = 585;
	// 0x2BF50A: mov dword ptr [0x00419C90], 0x08
	X86_MEM_WRITE_u32(base, 0x419C90u, 8);
	// 0x2BF514: mov word ptr [0x00419C94], 0x557
	X86_MEM_WRITE_u16(base, 0x419C94u, 1367);
	// 0x2BF51D: mov word ptr [0x00419C96], 0x264
	X86_MEM_WRITE_u16(base, 0x419C96u, 612);
	// 0x2BF526: mov [0x00419C98], edx
	X86_MEM_WRITE_u32(base, 0x419C98u, ctx.edx);
	// 0x2BF52C: mov dword ptr [0x00419C9C], 0x5D
	X86_MEM_WRITE_u32(base, 0x419C9Cu, 93);
	// 0x2BF536: mov dword ptr [0x00419CA0], 0x3EDCA8
	X86_MEM_WRITE_u32(base, 0x419CA0u, 4119720);
	// 0x2BF540: mov [0x00419CA4], eax
	X86_MEM_WRITE_u32(base, 0x419CA4u, ctx.eax);
	// 0x2BF545: mov word ptr [0x00419CA8], 0x428
	X86_MEM_WRITE_u16(base, 0x419CA8u, 1064);
	// 0x2BF54E: mov word ptr [0x00419CAA], 0x1AF
	X86_MEM_WRITE_u16(base, 0x419CAAu, 431);
	// 0x2BF557: mov [0x00419CAC], esi
	X86_MEM_WRITE_u32(base, 0x419CACu, ctx.esi);
	// 0x2BF55D: mov dword ptr [0x00419CB0], 0x6F
	X86_MEM_WRITE_u32(base, 0x419CB0u, 111);
	// 0x2BF567: mov dword ptr [0x00419CB4], 0x3EE4F0
	X86_MEM_WRITE_u32(base, 0x419CB4u, 4121840);
	// 0x2BF571: mov [0x00419CB8], eax
	X86_MEM_WRITE_u32(base, 0x419CB8u, ctx.eax);
	// 0x2BF576: mov word ptr [0x00419CBC], 0x1A6
	X86_MEM_WRITE_u16(base, 0x419CBCu, 422);
	// 0x2BF57F: mov word ptr [0x00419CBE], 0x260
	X86_MEM_WRITE_u16(base, 0x419CBEu, 608);
	// 0x2BF588: mov [0x00419CC0], ecx
	X86_MEM_WRITE_u32(base, 0x419CC0u, ctx.ecx);
	// 0x2BF58E: mov dword ptr [0x00419CC4], 0x71
	X86_MEM_WRITE_u32(base, 0x419CC4u, 113);
	// 0x2BF598: mov dword ptr [0x00419CC8], 0x3EE1A8
	X86_MEM_WRITE_u32(base, 0x419CC8u, 4121000);
	// 0x2BF5A2: mov [0x00419CCC], eax
	X86_MEM_WRITE_u32(base, 0x419CCCu, ctx.eax);
	// 0x2BF5A7: mov word ptr [0x00419CD0], 0x438
	X86_MEM_WRITE_u16(base, 0x419CD0u, 1080);
	// 0x2BF5B0: mov word ptr [0x00419CD2], 0x2B7
	X86_MEM_WRITE_u16(base, 0x419CD2u, 695);
	// 0x2BF5B9: mov [0x00419CD4], eax
	X86_MEM_WRITE_u32(base, 0x419CD4u, ctx.eax);
	// 0x2BF5BE: mov dword ptr [0x00419CD8], 0x67
	X86_MEM_WRITE_u32(base, 0x419CD8u, 103);
	// 0x2BF5C8: mov dword ptr [0x00419CDC], 0x3EE680
	X86_MEM_WRITE_u32(base, 0x419CDCu, 4122240);
	// 0x2BF5D2: mov [0x00419CE0], eax
	X86_MEM_WRITE_u32(base, 0x419CE0u, ctx.eax);
	// 0x2BF5D7: mov word ptr [0x00419CE4], 0x1F4
	X86_MEM_WRITE_u16(base, 0x419CE4u, 500);
	// 0x2BF5E0: mov word ptr [0x00419CE6], 0x316
	X86_MEM_WRITE_u16(base, 0x419CE6u, 790);
	// 0x2BF5E9: mov [0x00419CE8], edx
	X86_MEM_WRITE_u32(base, 0x419CE8u, ctx.edx);
	// 0x2BF5EF: mov dword ptr [0x00419CEC], 0x74
	X86_MEM_WRITE_u32(base, 0x419CECu, 116);
	// 0x2BF5F9: mov dword ptr [0x00419CF0], 0x3EE220
	X86_MEM_WRITE_u32(base, 0x419CF0u, 4121120);
	// 0x2BF603: mov [0x00419CF4], eax
	X86_MEM_WRITE_u32(base, 0x419CF4u, ctx.eax);
	// 0x2BF608: mov word ptr [0x00419CF8], 0x4B4
	X86_MEM_WRITE_u16(base, 0x419CF8u, 1204);
	// 0x2BF611: mov word ptr [0x00419CFA], 0x1C8
	X86_MEM_WRITE_u16(base, 0x419CFAu, 456);
	// 0x2BF61A: mov [0x00419CFC], edx
	X86_MEM_WRITE_u32(base, 0x419CFCu, ctx.edx);
	// 0x2BF620: mov [0x00419D08], edi
	X86_MEM_WRITE_u32(base, 0x419D08u, ctx.edi);
	// 0x2BF626: mov word ptr [0x00419D0C], 0x4B4
	X86_MEM_WRITE_u16(base, 0x419D0Cu, 1204);
	// 0x2BF62F: mov word ptr [0x00419D0E], 0x1C8
	X86_MEM_WRITE_u16(base, 0x419D0Eu, 456);
	// 0x2BF638: mov [0x00419D10], edx
	X86_MEM_WRITE_u32(base, 0x419D10u, ctx.edx);
	// 0x2BF63E: mov [0x00419D1C], edi
	X86_MEM_WRITE_u32(base, 0x419D1Cu, ctx.edi);
	// 0x2BF644: mov word ptr [0x00419D20], 0xDC
	X86_MEM_WRITE_u16(base, 0x419D20u, 220);
	// 0x2BF64D: mov word ptr [0x00419D22], 0x216
	X86_MEM_WRITE_u16(base, 0x419D22u, 534);
	// 0x2BF656: mov [0x00419D24], esi
	X86_MEM_WRITE_u32(base, 0x419D24u, ctx.esi);
	// 0x2BF65C: mov [0x00419D28], ebx
	X86_MEM_WRITE_u32(base, 0x419D28u, ctx.ebx);
	// 0x2BF662: mov dword ptr [0x00419D2C], 0x3ECA68
	X86_MEM_WRITE_u32(base, 0x419D2Cu, 4115048);
	// 0x2BF66C: mov [0x00419D30], eax
	X86_MEM_WRITE_u32(base, 0x419D30u, ctx.eax);
	// 0x2BF671: mov word ptr [0x00419D34], 0x30C
	X86_MEM_WRITE_u16(base, 0x419D34u, 780);
	// 0x2BF67A: mov [0x00419D36], bp
	X86_MEM_WRITE_u16(base, 0x419D36u, X86_REG16(ctx.ebp));
	// 0x2BF681: mov [0x00419D38], ecx
	X86_MEM_WRITE_u32(base, 0x419D38u, ctx.ecx);
	// 0x2BF687: mov dword ptr [0x00419D3C], 0x7D
	X86_MEM_WRITE_u32(base, 0x419D3Cu, 125);
	// 0x2BF691: mov dword ptr [0x00419D40], 0x3ED370
	X86_MEM_WRITE_u32(base, 0x419D40u, 4117360);
	// 0x2BF69B: mov [0x00419D44], ecx
	X86_MEM_WRITE_u32(base, 0x419D44u, ctx.ecx);
	// 0x2BF6A1: mov word ptr [0x00419D48], 0x55A
	X86_MEM_WRITE_u16(base, 0x419D48u, 1370);
	// 0x2BF6AA: mov word ptr [0x00419D4A], 0x244
	X86_MEM_WRITE_u16(base, 0x419D4Au, 580);
	// 0x2BF6B3: mov [0x00419D4C], edx
	X86_MEM_WRITE_u32(base, 0x419D4Cu, ctx.edx);
	// 0x2BF6B9: mov dword ptr [0x00419D50], 0x76
	X86_MEM_WRITE_u32(base, 0x419D50u, 118);
	// 0x2BF6C3: mov dword ptr [0x00419D54], 0x3ED500
	X86_MEM_WRITE_u32(base, 0x419D54u, 4117760);
	// 0x2BF6CD: mov [0x00419D58], eax
	X86_MEM_WRITE_u32(base, 0x419D58u, ctx.eax);
	// 0x2BF6D2: mov word ptr [0x00419D5C], 0x139
	X86_MEM_WRITE_u16(base, 0x419D5Cu, 313);
	// 0x2BF6DB: mov word ptr [0x00419D5E], 0x1CE
	X86_MEM_WRITE_u16(base, 0x419D5Eu, 462);
	// 0x2BF6E4: mov [0x00419D60], edx
	X86_MEM_WRITE_u32(base, 0x419D60u, ctx.edx);
	// 0x2BF6EA: mov dword ptr [0x00419D64], 0x79
	X86_MEM_WRITE_u32(base, 0x419D64u, 121);
	// 0x2BF6F4: mov dword ptr [0x00419D68], 0x3ED230
	X86_MEM_WRITE_u32(base, 0x419D68u, 4117040);
	// 0x2BF6FE: mov dword ptr [0x00419D6C], 0x05
	X86_MEM_WRITE_u32(base, 0x419D6Cu, 5);
	// 0x2BF708: mov word ptr [0x00419D70], 0x4AB
	X86_MEM_WRITE_u16(base, 0x419D70u, 1195);
	// 0x2BF711: mov word ptr [0x00419D72], 0x23A
	X86_MEM_WRITE_u16(base, 0x419D72u, 570);
	// 0x2BF71A: mov [0x00419D74], esi
	X86_MEM_WRITE_u32(base, 0x419D74u, ctx.esi);
	// 0x2BF720: mov dword ptr [0x00419D78], 0x75
	X86_MEM_WRITE_u32(base, 0x419D78u, 117);
	// 0x2BF72A: mov dword ptr [0x00419D7C], 0x3ED578
	X86_MEM_WRITE_u32(base, 0x419D7Cu, 4117880);
	// 0x2BF734: mov [0x00419D80], ecx
	X86_MEM_WRITE_u32(base, 0x419D80u, ctx.ecx);
	// 0x2BF73A: mov word ptr [0x00419D84], 0x299
	X86_MEM_WRITE_u16(base, 0x419D84u, 665);
	// 0x2BF743: mov word ptr [0x00419D86], 0x222
	X86_MEM_WRITE_u16(base, 0x419D86u, 546);
	// 0x2BF74C: mov [0x00419D88], eax
	X86_MEM_WRITE_u32(base, 0x419D88u, ctx.eax);
	// 0x2BF751: mov dword ptr [0x00419D8C], 0x7C
	X86_MEM_WRITE_u32(base, 0x419D8Cu, 124);
	// 0x2BF75B: mov [0x00419DAC], bx
	X86_MEM_WRITE_u16(base, 0x419DACu, X86_REG16(ctx.ebx));
	// 0x2BF762: mov ebx, 0x12C
	ctx.ebx = 300;
	// 0x2BF767: mov dword ptr [0x00419D90], 0x3ED2F8
	X86_MEM_WRITE_u32(base, 0x419D90u, 4117240);
	// 0x2BF771: mov [0x00419D94], eax
	X86_MEM_WRITE_u32(base, 0x419D94u, ctx.eax);
	// 0x2BF776: mov word ptr [0x00419D98], 0x440
	X86_MEM_WRITE_u16(base, 0x419D98u, 1088);
	// 0x2BF77F: mov word ptr [0x00419D9A], 0x10E
	X86_MEM_WRITE_u16(base, 0x419D9Au, 270);
	// 0x2BF788: mov [0x00419D9C], eax
	X86_MEM_WRITE_u32(base, 0x419D9Cu, ctx.eax);
	// 0x2BF78D: mov dword ptr [0x00419DA0], 0x57
	X86_MEM_WRITE_u32(base, 0x419DA0u, 87);
	// 0x2BF797: mov dword ptr [0x00419DA4], 0x3EE130
	X86_MEM_WRITE_u32(base, 0x419DA4u, 4120880);
	// 0x2BF7A1: mov [0x00419DA8], eax
	X86_MEM_WRITE_u32(base, 0x419DA8u, ctx.eax);
	// 0x2BF7A6: mov word ptr [0x00419DAE], 0x1E0
	X86_MEM_WRITE_u16(base, 0x419DAEu, 480);
	// 0x2BF7AF: mov [0x00419DB0], eax
	X86_MEM_WRITE_u32(base, 0x419DB0u, ctx.eax);
	// 0x2BF7B4: mov dword ptr [0x00419DB4], 0x62
	X86_MEM_WRITE_u32(base, 0x419DB4u, 98);
	// 0x2BF7BE: mov dword ptr [0x00419DB8], 0x3ED5C8
	X86_MEM_WRITE_u32(base, 0x419DB8u, 4117960);
	// 0x2BF7C8: mov [0x00419DBC], eax
	X86_MEM_WRITE_u32(base, 0x419DBCu, ctx.eax);
	// 0x2BF7CD: mov word ptr [0x00419DC0], 0x50E
	X86_MEM_WRITE_u16(base, 0x419DC0u, 1294);
	// 0x2BF7D6: mov word ptr [0x00419DC2], 0x1E9
	X86_MEM_WRITE_u16(base, 0x419DC2u, 489);
	// 0x2BF7DF: mov [0x00419DC4], eax
	X86_MEM_WRITE_u32(base, 0x419DC4u, ctx.eax);
	// 0x2BF7E4: mov dword ptr [0x00419DC8], 0x5C
	X86_MEM_WRITE_u32(base, 0x419DC8u, 92);
	// 0x2BF7EE: mov dword ptr [0x00419DCC], 0x3EDBB8
	X86_MEM_WRITE_u32(base, 0x419DCCu, 4119480);
	// 0x2BF7F8: mov [0x00419DD0], eax
	X86_MEM_WRITE_u32(base, 0x419DD0u, ctx.eax);
	// 0x2BF7FD: mov word ptr [0x00419DD4], 0x2DB
	X86_MEM_WRITE_u16(base, 0x419DD4u, 731);
	// 0x2BF806: mov word ptr [0x00419DD6], 0x25B
	X86_MEM_WRITE_u16(base, 0x419DD6u, 603);
	// 0x2BF80F: mov [0x00419DD8], edx
	X86_MEM_WRITE_u32(base, 0x419DD8u, ctx.edx);
	// 0x2BF815: mov dword ptr [0x00419DDC], 0x52
	X86_MEM_WRITE_u32(base, 0x419DDCu, 82);
	// 0x2BF81F: mov dword ptr [0x00419DE0], 0x3ED9D8
	X86_MEM_WRITE_u32(base, 0x419DE0u, 4119000);
	// 0x2BF829: mov [0x00419DE4], edi
	X86_MEM_WRITE_u32(base, 0x419DE4u, ctx.edi);
	// 0x2BF82F: mov word ptr [0x00419DE8], 0x3D4
	X86_MEM_WRITE_u16(base, 0x419DE8u, 980);
	// 0x2BF838: mov word ptr [0x00419DEA], 0x14A
	X86_MEM_WRITE_u16(base, 0x419DEAu, 330);
	// 0x2BF841: mov [0x00419DEC], eax
	X86_MEM_WRITE_u32(base, 0x419DECu, ctx.eax);
	// 0x2BF846: mov dword ptr [0x00419DF0], 0x59
	X86_MEM_WRITE_u32(base, 0x419DF0u, 89);
	// 0x2BF850: mov dword ptr [0x00419DF4], 0x3EE090
	X86_MEM_WRITE_u32(base, 0x419DF4u, 4120720);
	// 0x2BF85A: mov [0x00419DF8], edi
	X86_MEM_WRITE_u32(base, 0x419DF8u, ctx.edi);
	// 0x2BF860: mov word ptr [0x00419DFC], 0x4E3
	X86_MEM_WRITE_u16(base, 0x419DFCu, 1251);
	// 0x2BF869: mov [0x00419DFE], bp
	X86_MEM_WRITE_u16(base, 0x419DFEu, X86_REG16(ctx.ebp));
	// 0x2BF870: mov [0x00419E00], esi
	X86_MEM_WRITE_u32(base, 0x419E00u, ctx.esi);
	// 0x2BF876: mov dword ptr [0x00419E04], 0x5E
	X86_MEM_WRITE_u32(base, 0x419E04u, 94);
	// 0x2BF880: mov dword ptr [0x00419E08], 0x3EDD98
	X86_MEM_WRITE_u32(base, 0x419E08u, 4119960);
	// 0x2BF88A: mov [0x00419E0C], edi
	X86_MEM_WRITE_u32(base, 0x419E0Cu, ctx.edi);
	// 0x2BF890: mov word ptr [0x00419E10], 0xEC
	X86_MEM_WRITE_u16(base, 0x419E10u, 236);
	// 0x2BF899: mov word ptr [0x00419E12], 0x261
	X86_MEM_WRITE_u16(base, 0x419E12u, 609);
	// 0x2BF8A2: mov [0x00419E14], edx
	X86_MEM_WRITE_u32(base, 0x419E14u, ctx.edx);
	// 0x2BF8A8: mov dword ptr [0x00419E18], 0x61
	X86_MEM_WRITE_u32(base, 0x419E18u, 97);
	// 0x2BF8B2: mov dword ptr [0x00419E1C], 0x3ED870
	X86_MEM_WRITE_u32(base, 0x419E1Cu, 4118640);
	// 0x2BF8BC: mov [0x00419E20], edi
	X86_MEM_WRITE_u32(base, 0x419E20u, ctx.edi);
	// 0x2BF8C2: mov word ptr [0x00419E24], 0x2B7
	X86_MEM_WRITE_u16(base, 0x419E24u, 695);
	// 0x2BF8CB: mov word ptr [0x00419E26], 0x25D
	X86_MEM_WRITE_u16(base, 0x419E26u, 605);
	// 0x2BF8D4: mov [0x00419E28], edx
	X86_MEM_WRITE_u32(base, 0x419E28u, ctx.edx);
	// 0x2BF8DA: mov dword ptr [0x00419E2C], 0x55
	X86_MEM_WRITE_u32(base, 0x419E2Cu, 85);
	// 0x2BF8E4: mov dword ptr [0x00419E30], 0x3EDA78
	X86_MEM_WRITE_u32(base, 0x419E30u, 4119160);
	// 0x2BF8EE: mov [0x00419E34], eax
	X86_MEM_WRITE_u32(base, 0x419E34u, ctx.eax);
	// 0x2BF8F3: mov word ptr [0x00419E38], 0x4E0
	X86_MEM_WRITE_u16(base, 0x419E38u, 1248);
	// 0x2BF8FC: mov [0x00419E3A], bx
	X86_MEM_WRITE_u16(base, 0x419E3Au, X86_REG16(ctx.ebx));
	// 0x2BF903: mov [0x00419E3C], ecx
	X86_MEM_WRITE_u32(base, 0x419E3Cu, ctx.ecx);
	// 0x2BF909: mov dword ptr [0x00419E40], 0x6C
	X86_MEM_WRITE_u32(base, 0x419E40u, 108);
	// 0x2BF913: mov dword ptr [0x00419E44], 0x3EE310
	X86_MEM_WRITE_u32(base, 0x419E44u, 4121360);
	// 0x2BF91D: mov [0x00419E48], eax
	X86_MEM_WRITE_u32(base, 0x419E48u, ctx.eax);
	// 0x2BF922: mov word ptr [0x00419E4C], 0x512
	X86_MEM_WRITE_u16(base, 0x419E4Cu, 1298);
	// 0x2BF92B: mov word ptr [0x00419E4E], 0x34C
	X86_MEM_WRITE_u16(base, 0x419E4Eu, 844);
	// 0x2BF934: mov [0x00419E50], edx
	X86_MEM_WRITE_u32(base, 0x419E50u, ctx.edx);
	// 0x2BF93A: mov dword ptr [0x00419E54], 0x66
	X86_MEM_WRITE_u32(base, 0x419E54u, 102);
	// 0x2BF944: mov dword ptr [0x00419E58], 0x3EE5E0
	X86_MEM_WRITE_u32(base, 0x419E58u, 4122080);
	// 0x2BF94E: mov [0x00419E5C], edi
	X86_MEM_WRITE_u32(base, 0x419E5Cu, ctx.edi);
	// 0x2BF954: mov word ptr [0x00419E60], 0x1A6
	X86_MEM_WRITE_u16(base, 0x419E60u, 422);
	// 0x2BF95D: mov word ptr [0x00419E62], 0x260
	X86_MEM_WRITE_u16(base, 0x419E62u, 608);
	// 0x2BF966: mov [0x00419E64], ecx
	X86_MEM_WRITE_u32(base, 0x419E64u, ctx.ecx);
	// 0x2BF96C: mov dword ptr [0x00419E68], 0x71
	X86_MEM_WRITE_u32(base, 0x419E68u, 113);
	// 0x2BF976: mov dword ptr [0x00419E6C], 0x3EE1A8
	X86_MEM_WRITE_u32(base, 0x419E6Cu, 4121000);
	// 0x2BF980: mov [0x00419E70], eax
	X86_MEM_WRITE_u32(base, 0x419E70u, ctx.eax);
	// 0x2BF985: mov word ptr [0x00419E74], 0x483
	X86_MEM_WRITE_u16(base, 0x419E74u, 1155);
	// 0x2BF98E: mov word ptr [0x00419E76], 0x217
	X86_MEM_WRITE_u16(base, 0x419E76u, 535);
	// 0x2BF997: mov [0x00419E78], edx
	X86_MEM_WRITE_u32(base, 0x419E78u, ctx.edx);
	// 0x2BF99D: mov dword ptr [0x00419E7C], 0x70
	X86_MEM_WRITE_u32(base, 0x419E7Cu, 112);
	// 0x2BF9A7: mov dword ptr [0x00419E80], 0x3EE4A0
	X86_MEM_WRITE_u32(base, 0x419E80u, 4121760);
	// 0x2BF9B1: mov [0x00419E84], ecx
	X86_MEM_WRITE_u32(base, 0x419E84u, ctx.ecx);
	// 0x2BF9B7: mov word ptr [0x00419E88], 0x460
	X86_MEM_WRITE_u16(base, 0x419E88u, 1120);
	// 0x2BF9C0: mov word ptr [0x00419E8A], 0x127
	X86_MEM_WRITE_u16(base, 0x419E8Au, 295);
	// 0x2BF9C9: mov [0x00419E8C], eax
	X86_MEM_WRITE_u32(base, 0x419E8Cu, ctx.eax);
	// 0x2BF9CE: mov dword ptr [0x00419E90], 0x6D
	X86_MEM_WRITE_u32(base, 0x419E90u, 109);
	// 0x2BF9D8: mov dword ptr [0x00419E94], 0x3EE568
	X86_MEM_WRITE_u32(base, 0x419E94u, 4121960);
	// 0x2BF9E2: mov [0x00419E98], eax
	X86_MEM_WRITE_u32(base, 0x419E98u, ctx.eax);
	// 0x2BF9E7: mov word ptr [0x00419E9C], 0x122
	X86_MEM_WRITE_u16(base, 0x419E9Cu, 290);
	// 0x2BF9F0: mov word ptr [0x00419E9E], 0x320
	X86_MEM_WRITE_u16(base, 0x419E9Eu, 800);
	// 0x2BF9F9: mov [0x00419EA0], esi
	X86_MEM_WRITE_u32(base, 0x419EA0u, ctx.esi);
	// 0x2BF9FF: mov dword ptr [0x00419EA4], 0x72
	X86_MEM_WRITE_u32(base, 0x419EA4u, 114);
	// 0x2BFA09: mov dword ptr [0x00419EA8], 0x3EE298
	X86_MEM_WRITE_u32(base, 0x419EA8u, 4121240);
	// 0x2BFA13: mov [0x00419EAC], esi
	X86_MEM_WRITE_u32(base, 0x419EACu, ctx.esi);
	// 0x2BFA19: mov word ptr [0x00419EB0], 0x55A
	X86_MEM_WRITE_u16(base, 0x419EB0u, 1370);
	// 0x2BFA22: mov word ptr [0x00419EB2], 0x244
	X86_MEM_WRITE_u16(base, 0x419EB2u, 580);
	// 0x2BFA2B: mov [0x00419EB4], edx
	X86_MEM_WRITE_u32(base, 0x419EB4u, ctx.edx);
	// 0x2BFA31: mov dword ptr [0x00419EB8], 0x76
	X86_MEM_WRITE_u32(base, 0x419EB8u, 118);
	// 0x2BFA3B: mov dword ptr [0x00419EBC], 0x3ED500
	X86_MEM_WRITE_u32(base, 0x419EBCu, 4117760);
	// 0x2BFA45: mov [0x00419EC0], eax
	X86_MEM_WRITE_u32(base, 0x419EC0u, ctx.eax);
	// 0x2BFA4A: mov word ptr [0x00419EC4], 0xDC
	X86_MEM_WRITE_u16(base, 0x419EC4u, 220);
	// 0x2BFA53: mov word ptr [0x00419EC6], 0x216
	X86_MEM_WRITE_u16(base, 0x419EC6u, 534);
	// 0x2BFA5C: mov [0x00419EC8], esi
	X86_MEM_WRITE_u32(base, 0x419EC8u, ctx.esi);
	// 0x2BFA62: mov dword ptr [0x00419ECC], 0x78
	X86_MEM_WRITE_u32(base, 0x419ECCu, 120);
	// 0x2BFA6C: mov dword ptr [0x00419ED0], 0x3ECA68
	X86_MEM_WRITE_u32(base, 0x419ED0u, 4115048);
	// 0x2BFA76: mov [0x00419ED4], eax
	X86_MEM_WRITE_u32(base, 0x419ED4u, ctx.eax);
	// 0x2BFA7B: mov word ptr [0x00419ED8], 0x27A
	X86_MEM_WRITE_u16(base, 0x419ED8u, 634);
	// 0x2BFA84: mov word ptr [0x00419EDA], 0x2C6
	X86_MEM_WRITE_u16(base, 0x419EDAu, 710);
	// 0x2BFA8D: mov [0x00419EDC], esi
	X86_MEM_WRITE_u32(base, 0x419EDCu, ctx.esi);
	// 0x2BFA93: mov dword ptr [0x00419EE0], 0x7E
	X86_MEM_WRITE_u32(base, 0x419EE0u, 126);
	// 0x2BFA9D: mov dword ptr [0x00419EE4], 0x3ED3C0
	X86_MEM_WRITE_u32(base, 0x419EE4u, 4117440);
	// 0x2BFAA7: mov [0x00419EE8], ecx
	X86_MEM_WRITE_u32(base, 0x419EE8u, ctx.ecx);
	// 0x2BFAAD: mov word ptr [0x00419EEC], 0x58D
	X86_MEM_WRITE_u16(base, 0x419EECu, 1421);
	// 0x2BFAB6: mov word ptr [0x00419EEE], 0x1BB
	X86_MEM_WRITE_u16(base, 0x419EEEu, 443);
	// 0x2BFABF: mov [0x00419EF0], ecx
	X86_MEM_WRITE_u32(base, 0x419EF0u, ctx.ecx);
	// 0x2BFAC5: mov dword ptr [0x00419EF4], 0x77
	X86_MEM_WRITE_u32(base, 0x419EF4u, 119);
	// 0x2BFACF: mov dword ptr [0x00419EF8], 0x3ED460
	X86_MEM_WRITE_u32(base, 0x419EF8u, 4117600);
	// 0x2BFAD9: mov [0x00419EFC], edi
	X86_MEM_WRITE_u32(base, 0x419EFCu, ctx.edi);
	// 0x2BFADF: mov word ptr [0x00419F00], 0x89
	X86_MEM_WRITE_u16(base, 0x419F00u, 137);
	// 0x2BFAE8: mov word ptr [0x00419F02], 0x199
	X86_MEM_WRITE_u16(base, 0x419F02u, 409);
	// 0x2BFAF1: mov [0x00419F04], eax
	X86_MEM_WRITE_u32(base, 0x419F04u, ctx.eax);
	// 0x2BFAF6: mov dword ptr [0x00419F08], 0x7A
	X86_MEM_WRITE_u32(base, 0x419F08u, 122);
	// 0x2BFB00: mov dword ptr [0x00419F0C], 0x3ED118
	X86_MEM_WRITE_u32(base, 0x419F0Cu, 4116760);
	// 0x2BFB0A: mov [0x00419F10], eax
	X86_MEM_WRITE_u32(base, 0x419F10u, ctx.eax);
	// 0x2BFB0F: mov word ptr [0x00419F14], 0x55A
	X86_MEM_WRITE_u16(base, 0x419F14u, 1370);
	// 0x2BFB18: mov word ptr [0x00419F16], 0x244
	X86_MEM_WRITE_u16(base, 0x419F16u, 580);
	// 0x2BFB21: mov [0x00419F18], edx
	X86_MEM_WRITE_u32(base, 0x419F18u, ctx.edx);
	// 0x2BFB27: mov dword ptr [0x00419F1C], 0x76
	X86_MEM_WRITE_u32(base, 0x419F1Cu, 118);
	// 0x2BFB31: mov dword ptr [0x00419F20], 0x3ED500
	X86_MEM_WRITE_u32(base, 0x419F20u, 4117760);
	// 0x2BFB3B: mov [0x00419F24], eax
	X86_MEM_WRITE_u32(base, 0x419F24u, ctx.eax);
	// 0x2BFB40: mov word ptr [0x00419F28], 0x317
	X86_MEM_WRITE_u16(base, 0x419F28u, 791);
	// 0x2BFB49: mov word ptr [0x00419F2A], 0x1FB
	X86_MEM_WRITE_u16(base, 0x419F2Au, 507);
	// 0x2BFB52: mov [0x00419F2C], edx
	X86_MEM_WRITE_u32(base, 0x419F2Cu, ctx.edx);
	// 0x2BFB58: mov dword ptr [0x00419F30], 0x54
	X86_MEM_WRITE_u32(base, 0x419F30u, 84);
	// 0x2BFB62: mov dword ptr [0x00419F34], 0x3EDAF0
	X86_MEM_WRITE_u32(base, 0x419F34u, 4119280);
	// 0x2BFB6C: mov [0x00419F38], eax
	X86_MEM_WRITE_u32(base, 0x419F38u, ctx.eax);
	// 0x2BFB71: mov word ptr [0x00419F3C], 0x50E
	X86_MEM_WRITE_u16(base, 0x419F3Cu, 1294);
	// 0x2BFB7A: mov word ptr [0x00419F3E], 0x1E9
	X86_MEM_WRITE_u16(base, 0x419F3Eu, 489);
	// 0x2BFB83: mov [0x00419F40], eax
	X86_MEM_WRITE_u32(base, 0x419F40u, ctx.eax);
	// 0x2BFB88: mov dword ptr [0x00419F44], 0x5C
	X86_MEM_WRITE_u32(base, 0x419F44u, 92);
	// 0x2BFB92: mov dword ptr [0x00419F48], 0x3EDBB8
	X86_MEM_WRITE_u32(base, 0x419F48u, 4119480);
	// 0x2BFB9C: mov [0x00419F4C], eax
	X86_MEM_WRITE_u32(base, 0x419F4Cu, ctx.eax);
	// 0x2BFBA1: mov word ptr [0x00419F50], 0x404
	X86_MEM_WRITE_u16(base, 0x419F50u, 1028);
	// 0x2BFBAA: mov word ptr [0x00419F52], 0x198
	X86_MEM_WRITE_u16(base, 0x419F52u, 408);
	// 0x2BFBB3: mov [0x00419F54], esi
	X86_MEM_WRITE_u32(base, 0x419F54u, ctx.esi);
	// 0x2BFBB9: mov dword ptr [0x00419F58], 0x5A
	X86_MEM_WRITE_u32(base, 0x419F58u, 90);
	// 0x2BFBC3: mov dword ptr [0x00419F5C], 0x3EDFC8
	X86_MEM_WRITE_u32(base, 0x419F5Cu, 4120520);
	// 0x2BFBCD: mov dword ptr [0x00419F60], 0x05
	X86_MEM_WRITE_u32(base, 0x419F60u, 5);
	// 0x2BFBD7: mov word ptr [0x00419F64], 0xA6
	X86_MEM_WRITE_u16(base, 0x419F64u, 166);
	// 0x2BFBE0: mov word ptr [0x00419F66], 0x263
	X86_MEM_WRITE_u16(base, 0x419F66u, 611);
	// 0x2BFBE9: mov [0x00419F68], edx
	X86_MEM_WRITE_u32(base, 0x419F68u, ctx.edx);
	// 0x2BFBEF: mov dword ptr [0x00419F6C], 0x65
	X86_MEM_WRITE_u32(base, 0x419F6Cu, 101);
	// 0x2BFBF9: mov dword ptr [0x00419F70], 0x3ED910
	X86_MEM_WRITE_u32(base, 0x419F70u, 4118800);
	// 0x2BFC03: mov dword ptr [0x00419F74], 0x05
	X86_MEM_WRITE_u32(base, 0x419F74u, 5);
	// 0x2BFC0D: mov word ptr [0x00419F78], 0x105
	X86_MEM_WRITE_u16(base, 0x419F78u, 261);
	// 0x2BFC16: mov word ptr [0x00419F7A], 0x20D
	X86_MEM_WRITE_u16(base, 0x419F7Au, 525);
	// 0x2BFC1F: mov [0x00419F7C], edx
	X86_MEM_WRITE_u32(base, 0x419F7Cu, ctx.edx);
	// 0x2BFC25: mov dword ptr [0x00419F80], 0x60
	X86_MEM_WRITE_u32(base, 0x419F80u, 96);
	// 0x2BFC2F: mov dword ptr [0x00419F84], 0x3ED7F8
	X86_MEM_WRITE_u32(base, 0x419F84u, 4118520);
	// 0x2BFC39: mov [0x00419F88], eax
	X86_MEM_WRITE_u32(base, 0x419F88u, ctx.eax);
	// 0x2BFC3E: mov word ptr [0x00419F8C], 0x440
	X86_MEM_WRITE_u16(base, 0x419F8Cu, 1088);
	// 0x2BFC47: mov word ptr [0x00419F8E], 0x10E
	X86_MEM_WRITE_u16(base, 0x419F8Eu, 270);
	// 0x2BFC50: mov [0x00419F90], eax
	X86_MEM_WRITE_u32(base, 0x419F90u, ctx.eax);
	// 0x2BFC55: mov dword ptr [0x00419F94], 0x57
	X86_MEM_WRITE_u32(base, 0x419F94u, 87);
	// 0x2BFC5F: mov dword ptr [0x00419F98], 0x3EE130
	X86_MEM_WRITE_u32(base, 0x419F98u, 4120880);
	// 0x2BFC69: mov [0x00419F9C], eax
	X86_MEM_WRITE_u32(base, 0x419F9Cu, ctx.eax);
	// 0x2BFC6E: mov word ptr [0x00419FA0], 0x557
	X86_MEM_WRITE_u16(base, 0x419FA0u, 1367);
	// 0x2BFC77: mov word ptr [0x00419FA2], 0x264
	X86_MEM_WRITE_u16(base, 0x419FA2u, 612);
	// 0x2BFC80: mov [0x00419FA4], edx
	X86_MEM_WRITE_u32(base, 0x419FA4u, ctx.edx);
	// 0x2BFC86: mov dword ptr [0x00419FA8], 0x5D
	X86_MEM_WRITE_u32(base, 0x419FA8u, 93);
	// 0x2BFC90: mov dword ptr [0x00419FAC], 0x3EDCA8
	X86_MEM_WRITE_u32(base, 0x419FACu, 4119720);
	// 0x2BFC9A: mov [0x00419FB0], eax
	X86_MEM_WRITE_u32(base, 0x419FB0u, ctx.eax);
	// 0x2BFC9F: mov word ptr [0x00419FB4], 0x27B
	X86_MEM_WRITE_u16(base, 0x419FB4u, 635);
	// 0x2BFCA8: mov word ptr [0x00419FB6], 0x165
	X86_MEM_WRITE_u16(base, 0x419FB6u, 357);
	// 0x2BFCB1: mov [0x00419FB8], ecx
	X86_MEM_WRITE_u32(base, 0x419FB8u, ctx.ecx);
	// 0x2BFCB7: mov dword ptr [0x00419FBC], 0x53
	X86_MEM_WRITE_u32(base, 0x419FBCu, 83);
	// 0x2BFCC1: mov dword ptr [0x00419FC0], 0x3EDB68
	X86_MEM_WRITE_u32(base, 0x419FC0u, 4119400);
	// 0x2BFCCB: mov [0x00419FC4], ecx
	X86_MEM_WRITE_u32(base, 0x419FC4u, ctx.ecx);
	// 0x2BFCD1: mov word ptr [0x00419FC8], 0x4E0
	X86_MEM_WRITE_u16(base, 0x419FC8u, 1248);
	// 0x2BFCDA: mov [0x00419FCA], bx
	X86_MEM_WRITE_u16(base, 0x419FCAu, X86_REG16(ctx.ebx));
	// 0x2BFCE1: mov [0x00419FCC], ecx
	X86_MEM_WRITE_u32(base, 0x419FCCu, ctx.ecx);
	// 0x2BFCE7: mov dword ptr [0x00419FD0], 0x6C
	X86_MEM_WRITE_u32(base, 0x419FD0u, 108);
	// 0x2BFCF1: mov dword ptr [0x00419FD4], 0x3EE310
	X86_MEM_WRITE_u32(base, 0x419FD4u, 4121360);
	// 0x2BFCFB: mov [0x00419FD8], eax
	X86_MEM_WRITE_u32(base, 0x419FD8u, ctx.eax);
	// 0x2BFD00: mov word ptr [0x00419FDC], 0x122
	X86_MEM_WRITE_u16(base, 0x419FDCu, 290);
	// 0x2BFD09: mov word ptr [0x00419FDE], 0x320
	X86_MEM_WRITE_u16(base, 0x419FDEu, 800);
	// 0x2BFD12: mov [0x00419FE0], esi
	X86_MEM_WRITE_u32(base, 0x419FE0u, ctx.esi);
	// 0x2BFD18: mov dword ptr [0x00419FE4], 0x72
	X86_MEM_WRITE_u32(base, 0x419FE4u, 114);
	// 0x2BFD22: mov dword ptr [0x00419FE8], 0x3EE298
	X86_MEM_WRITE_u32(base, 0x419FE8u, 4121240);
	// 0x2BFD2C: mov [0x00419FEC], esi
	X86_MEM_WRITE_u32(base, 0x419FECu, ctx.esi);
	// 0x2BFD32: mov word ptr [0x00419FF0], 0x4A8
	X86_MEM_WRITE_u16(base, 0x419FF0u, 1192);
	// 0x2BFD3B: mov word ptr [0x00419FF2], 0x267
	X86_MEM_WRITE_u16(base, 0x419FF2u, 615);
	// 0x2BFD44: mov [0x00419FF4], ecx
	X86_MEM_WRITE_u32(base, 0x419FF4u, ctx.ecx);
	// 0x2BFD4A: mov dword ptr [0x00419FF8], 0x69
	X86_MEM_WRITE_u32(base, 0x419FF8u, 105);
	// 0x2BFD54: mov dword ptr [0x00419FFC], 0x3EE7E8
	X86_MEM_WRITE_u32(base, 0x419FFCu, 4122600);
	// 0x2BFD5E: mov dword ptr [0x0041A000], 0x06
	X86_MEM_WRITE_u32(base, 0x41A000u, 6);
	// 0x2BFD68: mov word ptr [0x0041A004], 0x136
	X86_MEM_WRITE_u16(base, 0x41A004u, 310);
	// 0x2BFD71: mov word ptr [0x0041A006], 0x299
	X86_MEM_WRITE_u16(base, 0x41A006u, 665);
	// 0x2BFD7A: mov [0x0041A008], eax
	X86_MEM_WRITE_u32(base, 0x41A008u, ctx.eax);
	// 0x2BFD7F: mov dword ptr [0x0041A00C], 0x73
	X86_MEM_WRITE_u32(base, 0x41A00Cu, 115);
	// 0x2BFD89: mov dword ptr [0x0041A010], 0x3EE2C0
	X86_MEM_WRITE_u32(base, 0x41A010u, 4121280);
	// 0x2BFD93: mov [0x0041A014], ecx
	X86_MEM_WRITE_u32(base, 0x41A014u, ctx.ecx);
	// 0x2BFD99: mov word ptr [0x0041A018], 0x460
	X86_MEM_WRITE_u16(base, 0x41A018u, 1120);
	// 0x2BFDA2: mov word ptr [0x0041A01A], 0x127
	X86_MEM_WRITE_u16(base, 0x41A01Au, 295);
	// 0x2BFDAB: mov [0x0041A01C], eax
	X86_MEM_WRITE_u32(base, 0x41A01Cu, ctx.eax);
	// 0x2BFDB0: mov dword ptr [0x0041A020], 0x6D
	X86_MEM_WRITE_u32(base, 0x41A020u, 109);
	// 0x2BFDBA: mov dword ptr [0x0041A024], 0x3EE568
	X86_MEM_WRITE_u32(base, 0x41A024u, 4121960);
	// 0x2BFDC4: mov [0x0041A028], eax
	X86_MEM_WRITE_u32(base, 0x41A028u, ctx.eax);
	// 0x2BFDC9: mov word ptr [0x0041A02C], 0x438
	X86_MEM_WRITE_u16(base, 0x41A02Cu, 1080);
	// 0x2BFDD2: mov word ptr [0x0041A02E], 0x2B7
	X86_MEM_WRITE_u16(base, 0x41A02Eu, 695);
	// 0x2BFDDB: mov [0x0041A030], eax
	X86_MEM_WRITE_u32(base, 0x41A030u, ctx.eax);
	// 0x2BFDE0: mov dword ptr [0x0041A034], 0x67
	X86_MEM_WRITE_u32(base, 0x41A034u, 103);
	// 0x2BFDEA: mov dword ptr [0x0041A038], 0x3EE680
	X86_MEM_WRITE_u32(base, 0x41A038u, 4122240);
	// 0x2BFDF4: mov [0x0041A03C], eax
	X86_MEM_WRITE_u32(base, 0x41A03Cu, ctx.eax);
	// 0x2BFDF9: mov word ptr [0x0041A040], 0x139
	X86_MEM_WRITE_u16(base, 0x41A040u, 313);
	// 0x2BFE02: mov word ptr [0x0041A042], 0x1CE
	X86_MEM_WRITE_u16(base, 0x41A042u, 462);
	// 0x2BFE0B: mov [0x0041A044], edx
	X86_MEM_WRITE_u32(base, 0x41A044u, ctx.edx);
	// 0x2BFE11: mov dword ptr [0x0041A048], 0x79
	X86_MEM_WRITE_u32(base, 0x41A048u, 121);
	// 0x2BFE1B: mov dword ptr [0x0041A04C], 0x3ED230
	X86_MEM_WRITE_u32(base, 0x41A04Cu, 4117040);
	// 0x2BFE25: mov dword ptr [0x0041A050], 0x05
	X86_MEM_WRITE_u32(base, 0x41A050u, 5);
	// 0x2BFE2F: mov word ptr [0x0041A054], 0x58D
	X86_MEM_WRITE_u16(base, 0x41A054u, 1421);
	// 0x2BFE38: mov word ptr [0x0041A056], 0x1BB
	X86_MEM_WRITE_u16(base, 0x41A056u, 443);
	// 0x2BFE41: mov [0x0041A058], ecx
	X86_MEM_WRITE_u32(base, 0x41A058u, ctx.ecx);
	// 0x2BFE47: mov dword ptr [0x0041A05C], 0x77
	X86_MEM_WRITE_u32(base, 0x41A05Cu, 119);
	// 0x2BFE51: mov dword ptr [0x0041A060], 0x3ED460
	X86_MEM_WRITE_u32(base, 0x41A060u, 4117600);
	// 0x2BFE5B: mov [0x0041A064], edi
	X86_MEM_WRITE_u32(base, 0x41A064u, ctx.edi);
	// 0x2BFE61: mov word ptr [0x0041A068], 0x30C
	X86_MEM_WRITE_u16(base, 0x41A068u, 780);
	// 0x2BFE6A: mov [0x0041A06A], bp
	X86_MEM_WRITE_u16(base, 0x41A06Au, X86_REG16(ctx.ebp));
	// 0x2BFE71: mov [0x0041A06C], ecx
	X86_MEM_WRITE_u32(base, 0x41A06Cu, ctx.ecx);
	// 0x2BFE77: mov dword ptr [0x0041A070], 0x7D
	X86_MEM_WRITE_u32(base, 0x41A070u, 125);
	// 0x2BFE81: mov dword ptr [0x0041A074], 0x3ED370
	X86_MEM_WRITE_u32(base, 0x41A074u, 4117360);
	// 0x2BFE8B: mov [0x0041A078], ecx
	X86_MEM_WRITE_u32(base, 0x41A078u, ctx.ecx);
	// 0x2BFE91: mov word ptr [0x0041A07C], 0xDC
	X86_MEM_WRITE_u16(base, 0x41A07Cu, 220);
	// 0x2BFE9A: mov word ptr [0x0041A07E], 0x216
	X86_MEM_WRITE_u16(base, 0x41A07Eu, 534);
	// 0x2BFEA3: mov [0x0041A080], esi
	X86_MEM_WRITE_u32(base, 0x41A080u, ctx.esi);
	// 0x2BFEA9: mov dword ptr [0x0041A084], 0x78
	X86_MEM_WRITE_u32(base, 0x41A084u, 120);
	// 0x2BFEB3: mov dword ptr [0x0041A088], 0x3ECA68
	X86_MEM_WRITE_u32(base, 0x41A088u, 4115048);
	// 0x2BFEBD: mov [0x0041A08C], eax
	X86_MEM_WRITE_u32(base, 0x41A08Cu, ctx.eax);
	// 0x2BFEC2: mov word ptr [0x0041A090], 0x27A
	X86_MEM_WRITE_u16(base, 0x41A090u, 634);
	// 0x2BFECB: mov word ptr [0x0041A092], 0x2C6
	X86_MEM_WRITE_u16(base, 0x41A092u, 710);
	// 0x2BFED4: mov [0x0041A094], esi
	X86_MEM_WRITE_u32(base, 0x41A094u, ctx.esi);
	// 0x2BFEDA: mov dword ptr [0x0041A098], 0x7E
	X86_MEM_WRITE_u32(base, 0x41A098u, 126);
	// 0x2BFEE4: mov dword ptr [0x0041A09C], 0x3ED3C0
	X86_MEM_WRITE_u32(base, 0x41A09Cu, 4117440);
	// 0x2BFEEE: mov [0x0041A0A0], ecx
	X86_MEM_WRITE_u32(base, 0x41A0A0u, ctx.ecx);
	// 0x2BFEF4: mov word ptr [0x0041A0A4], 0x368
	X86_MEM_WRITE_u16(base, 0x41A0A4u, 872);
	// 0x2BFEFD: mov word ptr [0x0041A0A6], 0x28A
	X86_MEM_WRITE_u16(base, 0x41A0A6u, 650);
	// 0x2BFF06: mov [0x0041A0A8], edx
	X86_MEM_WRITE_u32(base, 0x41A0A8u, ctx.edx);
	// 0x2BFF0C: mov dword ptr [0x0041A0AC], 0x7F
	X86_MEM_WRITE_u32(base, 0x41A0ACu, 127);
	// 0x2BFF16: mov dword ptr [0x0041A0B0], 0x3ED410
	X86_MEM_WRITE_u32(base, 0x41A0B0u, 4117520);
	// 0x2BFF20: mov [0x0041A0B4], ecx
	X86_MEM_WRITE_u32(base, 0x41A0B4u, ctx.ecx);
	// 0x2BFF26: mov word ptr [0x0041A0B8], 0x2DB
	X86_MEM_WRITE_u16(base, 0x41A0B8u, 731);
	// 0x2BFF2F: mov word ptr [0x0041A0BA], 0x25B
	X86_MEM_WRITE_u16(base, 0x41A0BAu, 603);
	// 0x2BFF38: mov [0x0041A0BC], edx
	X86_MEM_WRITE_u32(base, 0x41A0BCu, ctx.edx);
	// 0x2BFF3E: mov dword ptr [0x0041A0C0], 0x52
	X86_MEM_WRITE_u32(base, 0x41A0C0u, 82);
	// 0x2BFF48: mov dword ptr [0x0041A0C4], 0x3ED9D8
	X86_MEM_WRITE_u32(base, 0x41A0C4u, 4119000);
	// 0x2BFF52: mov [0x0041A0C8], edi
	X86_MEM_WRITE_u32(base, 0x41A0C8u, ctx.edi);
	// 0x2BFF58: mov word ptr [0x0041A0CC], 0xEC
	X86_MEM_WRITE_u16(base, 0x41A0CCu, 236);
	// 0x2BFF61: mov word ptr [0x0041A0CE], 0x261
	X86_MEM_WRITE_u16(base, 0x41A0CEu, 609);
	// 0x2BFF6A: mov [0x0041A0D0], edx
	X86_MEM_WRITE_u32(base, 0x41A0D0u, ctx.edx);
	// 0x2BFF70: mov dword ptr [0x0041A0D4], 0x61
	X86_MEM_WRITE_u32(base, 0x41A0D4u, 97);
	// 0x2BFF7A: mov dword ptr [0x0041A0D8], 0x3ED870
	X86_MEM_WRITE_u32(base, 0x41A0D8u, 4118640);
	// 0x2BFF84: mov [0x0041A0DC], edi
	X86_MEM_WRITE_u32(base, 0x41A0DCu, ctx.edi);
	// 0x2BFF8A: mov word ptr [0x0041A0E0], 0x49B
	X86_MEM_WRITE_u16(base, 0x41A0E0u, 1179);
	// 0x2BFF93: mov [0x0041A0E2], bx
	X86_MEM_WRITE_u16(base, 0x41A0E2u, X86_REG16(ctx.ebx));
	// 0x2BFF9A: mov [0x0041A0E4], ecx
	X86_MEM_WRITE_u32(base, 0x41A0E4u, ctx.ecx);
	// 0x2BFFA0: mov dword ptr [0x0041A0E8], 0x58
	X86_MEM_WRITE_u32(base, 0x41A0E8u, 88);
	// 0x2BFFAA: mov dword ptr [0x0041A0EC], 0x3EDE38
	X86_MEM_WRITE_u32(base, 0x41A0ECu, 4120120);
	// 0x2BFFB4: mov dword ptr [0x0041A0F0], 0x06
	X86_MEM_WRITE_u32(base, 0x41A0F0u, 6);
	// 0x2BFFBE: mov word ptr [0x0041A0F4], 0x546
	X86_MEM_WRITE_u16(base, 0x41A0F4u, 1350);
	// 0x2BFFC7: mov word ptr [0x0041A0F6], 0x201
	X86_MEM_WRITE_u16(base, 0x41A0F6u, 513);
	// 0x2BFFD0: mov [0x0041A0F8], ecx
	X86_MEM_WRITE_u32(base, 0x41A0F8u, ctx.ecx);
	// 0x2BFFD6: mov dword ptr [0x0041A0FC], 0x5F
	X86_MEM_WRITE_u32(base, 0x41A0FCu, 95);
	// 0x2BFFE0: mov dword ptr [0x0041A100], 0x3EDC30
	X86_MEM_WRITE_u32(base, 0x41A100u, 4119600);
	// 0x2BFFEA: mov [0x0041A104], eax
	X86_MEM_WRITE_u32(base, 0x41A104u, ctx.eax);
	// 0x2BFFEF: mov word ptr [0x0041A108], 0x3D4
	X86_MEM_WRITE_u16(base, 0x41A108u, 980);
	// 0x2BFFF8: mov word ptr [0x0041A10A], 0x14A
	X86_MEM_WRITE_u16(base, 0x41A10Au, 330);
	// 0x2C0001: mov [0x0041A10C], eax
	X86_MEM_WRITE_u32(base, 0x41A10Cu, ctx.eax);
	// 0x2C0006: mov dword ptr [0x0041A110], 0x59
	X86_MEM_WRITE_u32(base, 0x41A110u, 89);
	// 0x2C0010: mov dword ptr [0x0041A114], 0x3EE090
	X86_MEM_WRITE_u32(base, 0x41A114u, 4120720);
	// 0x2C001A: mov [0x0041A118], edi
	X86_MEM_WRITE_u32(base, 0x41A118u, ctx.edi);
	// 0x2C0020: mov word ptr [0x0041A11C], 0x4E3
	X86_MEM_WRITE_u16(base, 0x41A11Cu, 1251);
	// 0x2C0029: mov [0x0041A11E], bp
	X86_MEM_WRITE_u16(base, 0x41A11Eu, X86_REG16(ctx.ebp));
	// 0x2C0030: mov [0x0041A120], esi
	X86_MEM_WRITE_u32(base, 0x41A120u, ctx.esi);
	// 0x2C0036: mov dword ptr [0x0041A124], 0x5E
	X86_MEM_WRITE_u32(base, 0x41A124u, 94);
	// 0x2C0040: mov dword ptr [0x0041A128], 0x3EDD98
	X86_MEM_WRITE_u32(base, 0x41A128u, 4119960);
	// 0x2C004A: mov [0x0041A12C], edi
	X86_MEM_WRITE_u32(base, 0x41A12Cu, ctx.edi);
	// 0x2C0050: mov word ptr [0x0041A130], 0x105
	X86_MEM_WRITE_u16(base, 0x41A130u, 261);
	// 0x2C0059: mov word ptr [0x0041A132], 0x20D
	X86_MEM_WRITE_u16(base, 0x41A132u, 525);
	// 0x2C0062: mov [0x0041A134], edx
	X86_MEM_WRITE_u32(base, 0x41A134u, ctx.edx);
	// 0x2C0068: mov dword ptr [0x0041A138], 0x60
	X86_MEM_WRITE_u32(base, 0x41A138u, 96);
	// 0x2C0072: mov dword ptr [0x0041A13C], 0x3ED7F8
	X86_MEM_WRITE_u32(base, 0x41A13Cu, 4118520);
	// 0x2C007C: mov [0x0041A140], eax
	X86_MEM_WRITE_u32(base, 0x41A140u, ctx.eax);
	// 0x2C0081: mov word ptr [0x0041A144], 0x2B7
	X86_MEM_WRITE_u16(base, 0x41A144u, 695);
	// 0x2C008A: mov word ptr [0x0041A146], 0x25D
	X86_MEM_WRITE_u16(base, 0x41A146u, 605);
	// 0x2C0093: mov [0x0041A148], edx
	X86_MEM_WRITE_u32(base, 0x41A148u, ctx.edx);
	// 0x2C0099: mov dword ptr [0x0041A14C], 0x55
	X86_MEM_WRITE_u32(base, 0x41A14Cu, 85);
	// 0x2C00A3: mov dword ptr [0x0041A150], 0x3EDA78
	X86_MEM_WRITE_u32(base, 0x41A150u, 4119160);
	// 0x2C00AD: mov [0x0041A154], eax
	X86_MEM_WRITE_u32(base, 0x41A154u, ctx.eax);
	// 0x2C00B2: mov word ptr [0x0041A158], 0x42D
	X86_MEM_WRITE_u16(base, 0x41A158u, 1069);
	// 0x2C00BB: mov word ptr [0x0041A15A], 0x257
	X86_MEM_WRITE_u16(base, 0x41A15Au, 599);
	// 0x2C00C4: mov [0x0041A15C], eax
	X86_MEM_WRITE_u32(base, 0x41A15Cu, ctx.eax);
	// 0x2C00C9: mov dword ptr [0x0041A160], 0x68
	X86_MEM_WRITE_u32(base, 0x41A160u, 104);
	// 0x2C00D3: mov dword ptr [0x0041A164], 0x3EE6F8
	X86_MEM_WRITE_u32(base, 0x41A164u, 4122360);
	// 0x2C00DD: mov [0x0041A168], eax
	X86_MEM_WRITE_u32(base, 0x41A168u, ctx.eax);
	// 0x2C00E2: mov word ptr [0x0041A16C], 0x483
	X86_MEM_WRITE_u16(base, 0x41A16Cu, 1155);
	// 0x2C00EB: mov word ptr [0x0041A16E], 0x217
	X86_MEM_WRITE_u16(base, 0x41A16Eu, 535);
	// 0x2C00F4: mov [0x0041A170], edx
	X86_MEM_WRITE_u32(base, 0x41A170u, ctx.edx);
	// 0x2C00FA: mov dword ptr [0x0041A174], 0x70
	X86_MEM_WRITE_u32(base, 0x41A174u, 112);
	// 0x2C0104: mov dword ptr [0x0041A178], 0x3EE4A0
	X86_MEM_WRITE_u32(base, 0x41A178u, 4121760);
	// 0x2C010E: mov [0x0041A17C], ecx
	X86_MEM_WRITE_u32(base, 0x41A17Cu, ctx.ecx);
	// 0x2C0114: mov word ptr [0x0041A180], 0x1F4
	X86_MEM_WRITE_u16(base, 0x41A180u, 500);
	// 0x2C011D: mov word ptr [0x0041A182], 0x316
	X86_MEM_WRITE_u16(base, 0x41A182u, 790);
	// 0x2C0126: mov [0x0041A184], edx
	X86_MEM_WRITE_u32(base, 0x41A184u, ctx.edx);
	// 0x2C012C: mov dword ptr [0x0041A188], 0x74
	X86_MEM_WRITE_u32(base, 0x41A188u, 116);
	// 0x2C0136: mov dword ptr [0x0041A18C], 0x3EE220
	X86_MEM_WRITE_u32(base, 0x41A18Cu, 4121120);
	// 0x2C0140: mov [0x0041A190], eax
	X86_MEM_WRITE_u32(base, 0x41A190u, ctx.eax);
	// 0x2C0145: mov word ptr [0x0041A194], 0x485
	X86_MEM_WRITE_u16(base, 0x41A194u, 1157);
	// 0x2C014E: mov word ptr [0x0041A196], 0x302
	X86_MEM_WRITE_u16(base, 0x41A196u, 770);
	// 0x2C0157: mov [0x0041A198], esi
	X86_MEM_WRITE_u32(base, 0x41A198u, ctx.esi);
	// 0x2C015D: mov dword ptr [0x0041A19C], 0x6A
	X86_MEM_WRITE_u32(base, 0x41A19Cu, 106);
	// 0x2C0167: mov dword ptr [0x0041A1A0], 0x3EE770
	X86_MEM_WRITE_u32(base, 0x41A1A0u, 4122480);
	// 0x2C0171: mov [0x0041A1A4], eax
	X86_MEM_WRITE_u32(base, 0x41A1A4u, ctx.eax);
	// 0x2C0176: mov word ptr [0x0041A1A8], 0x136
	X86_MEM_WRITE_u16(base, 0x41A1A8u, 310);
	// 0x2C017F: mov word ptr [0x0041A1AA], 0x299
	X86_MEM_WRITE_u16(base, 0x41A1AAu, 665);
	// 0x2C0188: mov [0x0041A1AC], eax
	X86_MEM_WRITE_u32(base, 0x41A1ACu, ctx.eax);
	// 0x2C018D: mov dword ptr [0x0041A1B0], 0x73
	X86_MEM_WRITE_u32(base, 0x41A1B0u, 115);
	// 0x2C0197: mov dword ptr [0x0041A1B4], 0x3EE2C0
	X86_MEM_WRITE_u32(base, 0x41A1B4u, 4121280);
	// 0x2C01A1: mov [0x0041A1B8], ecx
	X86_MEM_WRITE_u32(base, 0x41A1B8u, ctx.ecx);
	// 0x2C01A7: mov word ptr [0x0041A1BC], 0x4E0
	X86_MEM_WRITE_u16(base, 0x41A1BCu, 1248);
	// 0x2C01B0: mov [0x0041A1BE], bx
	X86_MEM_WRITE_u16(base, 0x41A1BEu, X86_REG16(ctx.ebx));
	// 0x2C01B7: mov [0x0041A1C0], ecx
	X86_MEM_WRITE_u32(base, 0x41A1C0u, ctx.ecx);
	// 0x2C01BD: mov [0x0041A222], bp
	X86_MEM_WRITE_u16(base, 0x41A222u, X86_REG16(ctx.ebp));
	// 0x2C01C4: mov ebp, 0x3EDE38
	ctx.ebp = 4120120;
	// 0x2C01C9: mov dword ptr [0x0041A1C4], 0x6C
	X86_MEM_WRITE_u32(base, 0x41A1C4u, 108);
	// 0x2C01D3: mov dword ptr [0x0041A1C8], 0x3EE310
	X86_MEM_WRITE_u32(base, 0x41A1C8u, 4121360);
	// 0x2C01DD: mov [0x0041A1CC], eax
	X86_MEM_WRITE_u32(base, 0x41A1CCu, ctx.eax);
	// 0x2C01E2: mov word ptr [0x0041A1D0], 0x89
	X86_MEM_WRITE_u16(base, 0x41A1D0u, 137);
	// 0x2C01EB: mov word ptr [0x0041A1D2], 0x199
	X86_MEM_WRITE_u16(base, 0x41A1D2u, 409);
	// 0x2C01F4: mov [0x0041A1D4], eax
	X86_MEM_WRITE_u32(base, 0x41A1D4u, ctx.eax);
	// 0x2C01F9: mov dword ptr [0x0041A1D8], 0x7A
	X86_MEM_WRITE_u32(base, 0x41A1D8u, 122);
	// 0x2C0203: mov dword ptr [0x0041A1DC], 0x3ED118
	X86_MEM_WRITE_u32(base, 0x41A1DCu, 4116760);
	// 0x2C020D: mov [0x0041A1E0], eax
	X86_MEM_WRITE_u32(base, 0x41A1E0u, ctx.eax);
	// 0x2C0212: mov word ptr [0x0041A1E4], 0x4AB
	X86_MEM_WRITE_u16(base, 0x41A1E4u, 1195);
	// 0x2C021B: mov word ptr [0x0041A1E6], 0x23A
	X86_MEM_WRITE_u16(base, 0x41A1E6u, 570);
	// 0x2C0224: mov [0x0041A1E8], esi
	X86_MEM_WRITE_u32(base, 0x41A1E8u, ctx.esi);
	// 0x2C022A: mov dword ptr [0x0041A1EC], 0x75
	X86_MEM_WRITE_u32(base, 0x41A1ECu, 117);
	// 0x2C0234: mov dword ptr [0x0041A1F0], 0x3ED578
	X86_MEM_WRITE_u32(base, 0x41A1F0u, 4117880);
	// 0x2C023E: mov [0x0041A1F4], ecx
	X86_MEM_WRITE_u32(base, 0x41A1F4u, ctx.ecx);
	// 0x2C0244: mov word ptr [0x0041A1F8], 0x58D
	X86_MEM_WRITE_u16(base, 0x41A1F8u, 1421);
	// 0x2C024D: mov word ptr [0x0041A1FA], 0x1BB
	X86_MEM_WRITE_u16(base, 0x41A1FAu, 443);
	// 0x2C0256: mov [0x0041A1FC], ecx
	X86_MEM_WRITE_u32(base, 0x41A1FCu, ctx.ecx);
	// 0x2C025C: mov dword ptr [0x0041A200], 0x77
	X86_MEM_WRITE_u32(base, 0x41A200u, 119);
	// 0x2C0266: mov dword ptr [0x0041A204], 0x3ED460
	X86_MEM_WRITE_u32(base, 0x41A204u, 4117600);
	// 0x2C0270: mov [0x0041A208], edi
	X86_MEM_WRITE_u32(base, 0x41A208u, ctx.edi);
	// 0x2C0276: mov word ptr [0x0041A20C], 0x58D
	X86_MEM_WRITE_u16(base, 0x41A20Cu, 1421);
	// 0x2C027F: mov word ptr [0x0041A20E], 0x1BB
	X86_MEM_WRITE_u16(base, 0x41A20Eu, 443);
	// 0x2C0288: mov [0x0041A210], ecx
	X86_MEM_WRITE_u32(base, 0x41A210u, ctx.ecx);
	// 0x2C028E: mov dword ptr [0x0041A214], 0x77
	X86_MEM_WRITE_u32(base, 0x41A214u, 119);
	// 0x2C0298: mov dword ptr [0x0041A218], 0x3ED460
	X86_MEM_WRITE_u32(base, 0x41A218u, 4117600);
	// 0x2C02A2: mov [0x0041A21C], edi
	X86_MEM_WRITE_u32(base, 0x41A21Cu, ctx.edi);
	// 0x2C02A8: mov word ptr [0x0041A220], 0x30C
	X86_MEM_WRITE_u16(base, 0x41A220u, 780);
	// 0x2C02B1: mov [0x0041A224], ecx
	X86_MEM_WRITE_u32(base, 0x41A224u, ctx.ecx);
	// 0x2C02B7: mov dword ptr [0x0041A228], 0x7D
	X86_MEM_WRITE_u32(base, 0x41A228u, 125);
	// 0x2C02C1: mov dword ptr [0x0041A22C], 0x3ED370
	X86_MEM_WRITE_u32(base, 0x41A22Cu, 4117360);
	// 0x2C02CB: mov [0x0041A230], ecx
	X86_MEM_WRITE_u32(base, 0x41A230u, ctx.ecx);
	// 0x2C02D1: mov word ptr [0x0041A234], 0x368
	X86_MEM_WRITE_u16(base, 0x41A234u, 872);
	// 0x2C02DA: mov word ptr [0x0041A236], 0x28A
	X86_MEM_WRITE_u16(base, 0x41A236u, 650);
	// 0x2C02E3: mov [0x0041A238], edx
	X86_MEM_WRITE_u32(base, 0x41A238u, ctx.edx);
	// 0x2C02E9: mov dword ptr [0x0041A23C], 0x7F
	X86_MEM_WRITE_u32(base, 0x41A23Cu, 127);
	// 0x2C02F3: mov dword ptr [0x0041A240], 0x3ED410
	X86_MEM_WRITE_u32(base, 0x41A240u, 4117520);
	// 0x2C02FD: mov [0x0041A244], ecx
	X86_MEM_WRITE_u32(base, 0x41A244u, ctx.ecx);
	// 0x2C0303: mov word ptr [0x0041A248], 0x78
	X86_MEM_WRITE_u16(base, 0x41A248u, 120);
	// 0x2C030C: mov word ptr [0x0041A24A], 0x1E0
	X86_MEM_WRITE_u16(base, 0x41A24Au, 480);
	// 0x2C0315: mov [0x0041A24C], eax
	X86_MEM_WRITE_u32(base, 0x41A24Cu, ctx.eax);
	// 0x2C031A: mov dword ptr [0x0041A250], 0x62
	X86_MEM_WRITE_u32(base, 0x41A250u, 98);
	// 0x2C0324: mov dword ptr [0x0041A254], 0x3ED5C8
	X86_MEM_WRITE_u32(base, 0x41A254u, 4117960);
	// 0x2C032E: mov [0x0041A258], eax
	X86_MEM_WRITE_u32(base, 0x41A258u, ctx.eax);
	// 0x2C0333: mov word ptr [0x0041A25C], 0x317
	X86_MEM_WRITE_u16(base, 0x41A25Cu, 791);
	// 0x2C033C: mov word ptr [0x0041A25E], 0x1FB
	X86_MEM_WRITE_u16(base, 0x41A25Eu, 507);
	// 0x2C0345: mov [0x0041A260], edx
	X86_MEM_WRITE_u32(base, 0x41A260u, ctx.edx);
	// 0x2C034B: mov dword ptr [0x0041A264], 0x54
	X86_MEM_WRITE_u32(base, 0x41A264u, 84);
	// 0x2C0355: mov dword ptr [0x0041A268], 0x3EDAF0
	X86_MEM_WRITE_u32(base, 0x41A268u, 4119280);
	// 0x2C035F: mov [0x0041A26C], eax
	X86_MEM_WRITE_u32(base, 0x41A26Cu, ctx.eax);
	// 0x2C0364: mov word ptr [0x0041A270], 0x49B
	X86_MEM_WRITE_u16(base, 0x41A270u, 1179);
	// 0x2C036D: mov [0x0041A272], bx
	X86_MEM_WRITE_u16(base, 0x41A272u, X86_REG16(ctx.ebx));
	// 0x2C0374: mov [0x0041A274], ecx
	X86_MEM_WRITE_u32(base, 0x41A274u, ctx.ecx);
	// 0x2C037A: mov dword ptr [0x0041A278], 0x58
	X86_MEM_WRITE_u32(base, 0x41A278u, 88);
	// 0x2C0384: mov [0x0041A27C], ebp
	X86_MEM_WRITE_u32(base, 0x41A27Cu, ctx.ebp);
	// 0x2C038A: mov dword ptr [0x0041A280], 0x06
	X86_MEM_WRITE_u32(base, 0x41A280u, 6);
	// 0x2C0394: mov word ptr [0x0041A284], 0x50E
	X86_MEM_WRITE_u16(base, 0x41A284u, 1294);
	// 0x2C039D: mov word ptr [0x0041A286], 0x1E9
	X86_MEM_WRITE_u16(base, 0x41A286u, 489);
	// 0x2C03A6: mov [0x0041A288], eax
	X86_MEM_WRITE_u32(base, 0x41A288u, ctx.eax);
	// 0x2C03AB: mov dword ptr [0x0041A28C], 0x5C
	X86_MEM_WRITE_u32(base, 0x41A28Cu, 92);
	// 0x2C03B5: mov dword ptr [0x0041A290], 0x3EDBB8
	X86_MEM_WRITE_u32(base, 0x41A290u, 4119480);
	// 0x2C03BF: mov [0x0041A294], eax
	X86_MEM_WRITE_u32(base, 0x41A294u, ctx.eax);
	// 0x2C03C4: mov word ptr [0x0041A298], 0xB4
	X86_MEM_WRITE_u16(base, 0x41A298u, 180);
	// 0x2C03CD: mov word ptr [0x0041A29A], 0x1EA
	X86_MEM_WRITE_u16(base, 0x41A29Au, 490);
	// 0x2C03D6: mov [0x0041A29C], eax
	X86_MEM_WRITE_u32(base, 0x41A29Cu, ctx.eax);
	// 0x2C03DB: mov dword ptr [0x0041A2A0], 0x64
	X86_MEM_WRITE_u32(base, 0x41A2A0u, 100);
	// 0x2C03E5: mov dword ptr [0x0041A2A4], 0x3ED640
	X86_MEM_WRITE_u32(base, 0x41A2A4u, 4118080);
	// 0x2C03EF: mov [0x0041A2A8], eax
	X86_MEM_WRITE_u32(base, 0x41A2A8u, ctx.eax);
	// 0x2C03F4: mov word ptr [0x0041A2AC], 0x49B
	X86_MEM_WRITE_u16(base, 0x41A2ACu, 1179);
	// 0x2C03FD: mov [0x0041A2AE], bx
	X86_MEM_WRITE_u16(base, 0x41A2AEu, X86_REG16(ctx.ebx));
	// 0x2C0404: mov [0x0041A2B0], ecx
	X86_MEM_WRITE_u32(base, 0x41A2B0u, ctx.ecx);
	// 0x2C040A: mov dword ptr [0x0041A2B4], 0x58
	X86_MEM_WRITE_u32(base, 0x41A2B4u, 88);
	// 0x2C0414: mov [0x0041A2B8], ebp
	X86_MEM_WRITE_u32(base, 0x41A2B8u, ctx.ebp);
	// 0x2C041A: mov dword ptr [0x0041A2BC], 0x06
	X86_MEM_WRITE_u32(base, 0x41A2BCu, 6);
	// 0x2C0424: mov word ptr [0x0041A2C0], 0x4C9
	X86_MEM_WRITE_u16(base, 0x41A2C0u, 1225);
	// 0x2C042D: mov word ptr [0x0041A2C2], 0x2B1
	X86_MEM_WRITE_u16(base, 0x41A2C2u, 689);
	// 0x2C0436: mov [0x0041A2C4], esi
	X86_MEM_WRITE_u32(base, 0x41A2C4u, ctx.esi);
	// 0x2C043C: mov dword ptr [0x0041A2C8], 0x5B
	X86_MEM_WRITE_u32(base, 0x41A2C8u, 91);
	// 0x2C0446: mov dword ptr [0x0041A2CC], 0x3EDD20
	X86_MEM_WRITE_u32(base, 0x41A2CCu, 4119840);
	// 0x2C0450: mov [0x0041A30C], edi
	X86_MEM_WRITE_u32(base, 0x41A30Cu, ctx.edi);
	// 0x2C0456: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2C0457: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2C0458: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2C0459: mov [0x0041A2D0], eax
	X86_MEM_WRITE_u32(base, 0x41A2D0u, ctx.eax);
	// 0x2C045E: mov word ptr [0x0041A2D4], 0x27B
	X86_MEM_WRITE_u16(base, 0x41A2D4u, 635);
	// 0x2C0467: mov word ptr [0x0041A2D6], 0x165
	X86_MEM_WRITE_u16(base, 0x41A2D6u, 357);
	// 0x2C0470: mov [0x0041A2D8], ecx
	X86_MEM_WRITE_u32(base, 0x41A2D8u, ctx.ecx);
	// 0x2C0476: mov dword ptr [0x0041A2DC], 0x53
	X86_MEM_WRITE_u32(base, 0x41A2DCu, 83);
	// 0x2C0480: mov dword ptr [0x0041A2E0], 0x3EDB68
	X86_MEM_WRITE_u32(base, 0x41A2E0u, 4119400);
	// 0x2C048A: mov [0x0041A2E4], ecx
	X86_MEM_WRITE_u32(base, 0x41A2E4u, ctx.ecx);
	// 0x2C0490: mov word ptr [0x0041A2E8], 0x4AB
	X86_MEM_WRITE_u16(base, 0x41A2E8u, 1195);
	// 0x2C0499: mov word ptr [0x0041A2EA], 0x1B6
	X86_MEM_WRITE_u16(base, 0x41A2EAu, 438);
	// 0x2C04A2: mov [0x0041A2EC], edx
	X86_MEM_WRITE_u32(base, 0x41A2ECu, ctx.edx);
	// 0x2C04A8: mov dword ptr [0x0041A2F0], 0x6E
	X86_MEM_WRITE_u32(base, 0x41A2F0u, 110);
	// 0x2C04B2: mov dword ptr [0x0041A2F4], 0x3EE388
	X86_MEM_WRITE_u32(base, 0x41A2F4u, 4121480);
	// 0x2C04BC: mov [0x0041A2F8], eax
	X86_MEM_WRITE_u32(base, 0x41A2F8u, ctx.eax);
	// 0x2C04C1: mov word ptr [0x0041A2FC], 0x512
	X86_MEM_WRITE_u16(base, 0x41A2FCu, 1298);
	// 0x2C04CA: mov word ptr [0x0041A2FE], 0x34C
	X86_MEM_WRITE_u16(base, 0x41A2FEu, 844);
	// 0x2C04D3: mov [0x0041A300], edx
	X86_MEM_WRITE_u32(base, 0x41A300u, ctx.edx);
	// 0x2C04D9: mov dword ptr [0x0041A304], 0x66
	X86_MEM_WRITE_u32(base, 0x41A304u, 102);
	// 0x2C04E3: mov dword ptr [0x0041A308], 0x3EE5E0
	X86_MEM_WRITE_u32(base, 0x41A308u, 4122080);
	// 0x2C04ED: mov word ptr [0x0041A310], 0x1F4
	X86_MEM_WRITE_u16(base, 0x41A310u, 500);
	// 0x2C04F6: mov word ptr [0x0041A312], 0x316
	X86_MEM_WRITE_u16(base, 0x41A312u, 790);
	// 0x2C04FF: mov [0x0041A314], edx
	X86_MEM_WRITE_u32(base, 0x41A314u, ctx.edx);
	// 0x2C0505: mov dword ptr [0x0041A318], 0x74
	X86_MEM_WRITE_u32(base, 0x41A318u, 116);
	// 0x2C050F: mov dword ptr [0x0041A31C], 0x3EE220
	X86_MEM_WRITE_u32(base, 0x41A31Cu, 4121120);
	// 0x2C0519: mov [0x0041A320], eax
	X86_MEM_WRITE_u32(base, 0x41A320u, ctx.eax);
	// 0x2C051E: mov word ptr [0x0041A324], 0x136
	X86_MEM_WRITE_u16(base, 0x41A324u, 310);
	// 0x2C0527: mov word ptr [0x0041A326], 0x299
	X86_MEM_WRITE_u16(base, 0x41A326u, 665);
	// 0x2C0530: mov [0x0041A328], ecx
	X86_MEM_WRITE_u32(base, 0x41A328u, ctx.ecx);
	// 0x2C0536: mov dword ptr [0x0041A32C], 0x73
	X86_MEM_WRITE_u32(base, 0x41A32Cu, 115);
	// 0x2C0540: mov dword ptr [0x0041A330], 0x3EE2C0
	X86_MEM_WRITE_u32(base, 0x41A330u, 4121280);
	// 0x2C054A: mov [0x0041A334], ecx
	X86_MEM_WRITE_u32(base, 0x41A334u, ctx.ecx);
	// 0x2C0550: mov word ptr [0x0041A338], 0x1A6
	X86_MEM_WRITE_u16(base, 0x41A338u, 422);
	// 0x2C0559: mov word ptr [0x0041A33A], 0x260
	X86_MEM_WRITE_u16(base, 0x41A33Au, 608);
	// 0x2C0562: mov [0x0041A33C], eax
	X86_MEM_WRITE_u32(base, 0x41A33Cu, ctx.eax);
	// 0x2C0567: mov dword ptr [0x0041A340], 0x71
	X86_MEM_WRITE_u32(base, 0x41A340u, 113);
	// 0x2C0571: mov dword ptr [0x0041A344], 0x3EE1A8
	X86_MEM_WRITE_u32(base, 0x41A344u, 4121000);
	// 0x2C057B: mov [0x0041A348], eax
	X86_MEM_WRITE_u32(base, 0x41A348u, ctx.eax);
	// 0x2C0580: mov word ptr [0x0041A34C], 0x42D
	X86_MEM_WRITE_u16(base, 0x41A34Cu, 1069);
	// 0x2C0589: mov word ptr [0x0041A34E], 0x257
	X86_MEM_WRITE_u16(base, 0x41A34Eu, 599);
	// 0x2C0592: mov [0x0041A350], eax
	X86_MEM_WRITE_u32(base, 0x41A350u, ctx.eax);
	// 0x2C0597: mov dword ptr [0x0041A354], 0x68
	X86_MEM_WRITE_u32(base, 0x41A354u, 104);
	// 0x2C05A1: mov dword ptr [0x0041A358], 0x3EE6F8
	X86_MEM_WRITE_u32(base, 0x41A358u, 4122360);
	// 0x2C05AB: mov [0x0041A35C], eax
	X86_MEM_WRITE_u32(base, 0x41A35Cu, ctx.eax);
	// 0x2C05B0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2C05B1: ret
	return;
}

void sub_2C05C0(X86Context& ctx, uint8_t* base) {
	// 0x2C05C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C05C8: movss [0x005A8B0C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B0Cu, ctx.xmm[0].u32[0]);
	// 0x2C05D0: ret
	return;
}

void sub_2C05E0(X86Context& ctx, uint8_t* base) {
	// 0x2C05E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C05E8: movss [0x005A8B10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B10u, ctx.xmm[0].u32[0]);
	// 0x2C05F0: ret
	return;
}

void sub_2C0600(X86Context& ctx, uint8_t* base) {
	// 0x2C0600: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C0608: movss [0x005A8B08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B08u, ctx.xmm[0].u32[0]);
	// 0x2C0610: ret
	return;
}

void sub_2C0620(X86Context& ctx, uint8_t* base) {
	// 0x2C0620: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C0628: movss [0x005A8B30], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B30u, ctx.xmm[0].u32[0]);
	// 0x2C0630: ret
	return;
}

void sub_2C0640(X86Context& ctx, uint8_t* base) {
	// 0x2C0640: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C0648: movss [0x005A8B3C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B3Cu, ctx.xmm[0].u32[0]);
	// 0x2C0650: ret
	return;
}

void sub_2C0660(X86Context& ctx, uint8_t* base) {
	// 0x2C0660: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C0668: movss [0x005A8B2C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B2Cu, ctx.xmm[0].u32[0]);
	// 0x2C0670: ret
	return;
}

void sub_2C0680(X86Context& ctx, uint8_t* base) {
	// 0x2C0680: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C0688: movss [0x005A8B14], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B14u, ctx.xmm[0].u32[0]);
	// 0x2C0690: ret
	return;
}

void sub_2C06A0(X86Context& ctx, uint8_t* base) {
	// 0x2C06A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C06A8: movss [0x005A8B34], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B34u, ctx.xmm[0].u32[0]);
	// 0x2C06B0: ret
	return;
}

void sub_2C06C0(X86Context& ctx, uint8_t* base) {
	// 0x2C06C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C06C8: movss [0x005A8B1C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B1Cu, ctx.xmm[0].u32[0]);
	// 0x2C06D0: ret
	return;
}

void sub_2C06E0(X86Context& ctx, uint8_t* base) {
	// 0x2C06E0: movss xmm0, dword ptr [0x005A8B34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B34u);
	// 0x2C06E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C06F0: movss [0x005A8B44], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B44u, ctx.xmm[0].u32[0]);
	// 0x2C06F8: ret
	return;
}

void sub_2C0700(X86Context& ctx, uint8_t* base) {
	// 0x2C0700: movss xmm0, dword ptr [0x005A8B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B1Cu);
	// 0x2C0708: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C0710: movss [0x005A8B40], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B40u, ctx.xmm[0].u32[0]);
	// 0x2C0718: ret
	return;
}

void sub_2C0720(X86Context& ctx, uint8_t* base) {
	// 0x2C0720: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C0728: movss [0x005A8B54], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B54u, ctx.xmm[0].u32[0]);
	// 0x2C0730: ret
	return;
}

void sub_2C0740(X86Context& ctx, uint8_t* base) {
	// 0x2C0740: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C0748: movss [0x005A8B48], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B48u, ctx.xmm[0].u32[0]);
	// 0x2C0750: ret
	return;
}

void sub_2C0760(X86Context& ctx, uint8_t* base) {
	// 0x2C0760: movss xmm0, dword ptr [0x005A8B48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B48u);
	// 0x2C0768: movss [0x005A8B50], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B50u, ctx.xmm[0].u32[0]);
	// 0x2C0770: ret
	return;
}

void sub_2C0780(X86Context& ctx, uint8_t* base) {
	// 0x2C0780: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C0788: movss [0x005A8B18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B18u, ctx.xmm[0].u32[0]);
	// 0x2C0790: ret
	return;
}

void sub_2C07A0(X86Context& ctx, uint8_t* base) {
	// 0x2C07A0: movss xmm0, dword ptr [0x005A8B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B1Cu);
	// 0x2C07A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C07B0: movss [0x005A8B4C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B4Cu, ctx.xmm[0].u32[0]);
	// 0x2C07B8: ret
	return;
}

void sub_2C07C0(X86Context& ctx, uint8_t* base) {
	// 0x2C07C0: movss xmm0, dword ptr [0x005A8B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B1Cu);
	// 0x2C07C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C07D0: movss [0x005A8B28], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B28u, ctx.xmm[0].u32[0]);
	// 0x2C07D8: ret
	return;
}

void sub_2C07E0(X86Context& ctx, uint8_t* base) {
	// 0x2C07E0: movss xmm0, dword ptr [0x005A8B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B1Cu);
	// 0x2C07E8: subss xmm0, [0x005A8B28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8B28u);
	// 0x2C07F0: movss [0x005A8B24], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B24u, ctx.xmm[0].u32[0]);
	// 0x2C07F8: ret
	return;
}

void sub_2C0800(X86Context& ctx, uint8_t* base) {
	// 0x2C0800: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C0808: movss [0x005A8B38], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B38u, ctx.xmm[0].u32[0]);
	// 0x2C0810: ret
	return;
}

void sub_2C0820(X86Context& ctx, uint8_t* base) {
	// 0x2C0820: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C0828: movss [0x005A8B20], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B20u, ctx.xmm[0].u32[0]);
	// 0x2C0830: ret
	return;
}

void sub_2C0840(X86Context& ctx, uint8_t* base) {
	// 0x2C0840: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2C0841: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2C0842: mov edi, 0x27
	ctx.edi = 39;
	// 0x2C0847: mov [0x0041A364], edi
	X86_MEM_WRITE_u32(base, 0x41A364u, ctx.edi);
	// 0x2C084D: mov esi, 0x3EECE8
	ctx.esi = 4123880;
	// 0x2C0852: mov [0x0041A394], edi
	X86_MEM_WRITE_u32(base, 0x41A394u, ctx.edi);
	// 0x2C0858: mov edx, 0x21
	ctx.edx = 33;
	// 0x2C085D: mov eax, 0x1A
	ctx.eax = 26;
	// 0x2C0862: mov edi, 0x2C
	ctx.edi = 44;
	// 0x2C0867: mov [0x0041A370], esi
	X86_MEM_WRITE_u32(base, 0x41A370u, ctx.esi);
	// 0x2C086D: mov [0x0041A398], esi
	X86_MEM_WRITE_u32(base, 0x41A398u, ctx.esi);
	// 0x2C0873: mov esi, 0x3F2208
	ctx.esi = 4137480;
	// 0x2C0878: mov [0x0041A374], edx
	X86_MEM_WRITE_u32(base, 0x41A374u, ctx.edx);
	// 0x2C087E: mov ecx, 0x3EE8D8
	ctx.ecx = 4122840;
	// 0x2C0883: mov [0x0041A38C], eax
	X86_MEM_WRITE_u32(base, 0x41A38Cu, ctx.eax);
	// 0x2C0888: mov [0x0041A39C], edx
	X86_MEM_WRITE_u32(base, 0x41A39Cu, ctx.edx);
	// 0x2C088E: mov [0x0041A3A4], eax
	X86_MEM_WRITE_u32(base, 0x41A3A4u, ctx.eax);
	// 0x2C0893: mov eax, 0x1D
	ctx.eax = 29;
	// 0x2C0898: mov [0x0041A3BC], edi
	X86_MEM_WRITE_u32(base, 0x41A3BCu, ctx.edi);
	// 0x2C089E: mov edx, 0x3F1880
	ctx.edx = 4135040;
	// 0x2C08A3: mov [0x0041A3F4], edi
	X86_MEM_WRITE_u32(base, 0x41A3F4u, ctx.edi);
	// 0x2C08A9: mov edi, 0x23
	ctx.edi = 35;
	// 0x2C08AE: mov [0x0041A3D0], esi
	X86_MEM_WRITE_u32(base, 0x41A3D0u, ctx.esi);
	// 0x2C08B4: mov [0x0041A3F8], esi
	X86_MEM_WRITE_u32(base, 0x41A3F8u, ctx.esi);
	// 0x2C08BA: mov esi, 0x3F5070
	ctx.esi = 4149360;
	// 0x2C08BF: mov [0x0041A388], ecx
	X86_MEM_WRITE_u32(base, 0x41A388u, ctx.ecx);
	// 0x2C08C5: mov [0x0041A3A0], ecx
	X86_MEM_WRITE_u32(base, 0x41A3A0u, ctx.ecx);
	// 0x2C08CB: mov ecx, 0x20
	ctx.ecx = 32;
	// 0x2C08D0: mov [0x0041A3D4], eax
	X86_MEM_WRITE_u32(base, 0x41A3D4u, ctx.eax);
	// 0x2C08D5: mov [0x0041A3E0], edx
	X86_MEM_WRITE_u32(base, 0x41A3E0u, ctx.edx);
	// 0x2C08DB: mov [0x0041A3E4], eax
	X86_MEM_WRITE_u32(base, 0x41A3E4u, ctx.eax);
	// 0x2C08E0: mov [0x0041A3FC], eax
	X86_MEM_WRITE_u32(base, 0x41A3FCu, ctx.eax);
	// 0x2C08E5: mov [0x0041A400], edx
	X86_MEM_WRITE_u32(base, 0x41A400u, ctx.edx);
	// 0x2C08EB: mov [0x0041A404], eax
	X86_MEM_WRITE_u32(base, 0x41A404u, ctx.eax);
	// 0x2C08F0: mov [0x0041A40C], edi
	X86_MEM_WRITE_u32(base, 0x41A40Cu, ctx.edi);
	// 0x2C08F6: mov edx, 0x3F5570
	ctx.edx = 4150640;
	// 0x2C08FB: mov eax, 0x2D
	ctx.eax = 45;
	// 0x2C0900: mov [0x0041A42C], edi
	X86_MEM_WRITE_u32(base, 0x41A42Cu, ctx.edi);
	// 0x2C0906: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2C0907: mov [0x0041A418], esi
	X86_MEM_WRITE_u32(base, 0x41A418u, ctx.esi);
	// 0x2C090D: mov [0x0041A430], esi
	X86_MEM_WRITE_u32(base, 0x41A430u, ctx.esi);
	// 0x2C0913: mov dword ptr [0x0041A368], 0x3EF210
	X86_MEM_WRITE_u32(base, 0x41A368u, 4125200);
	// 0x2C091D: mov dword ptr [0x0041A36C], 0x5C
	X86_MEM_WRITE_u32(base, 0x41A36Cu, 92);
	// 0x2C0927: mov dword ptr [0x0041A378], 0x3F08E0
	X86_MEM_WRITE_u32(base, 0x41A378u, 4131040);
	// 0x2C0931: mov dword ptr [0x0041A37C], 0x38
	X86_MEM_WRITE_u32(base, 0x41A37Cu, 56);
	// 0x2C093B: mov dword ptr [0x0041A380], 0x3F0070
	X86_MEM_WRITE_u32(base, 0x41A380u, 4128880);
	// 0x2C0945: mov dword ptr [0x0041A384], 0x36
	X86_MEM_WRITE_u32(base, 0x41A384u, 54);
	// 0x2C094F: mov dword ptr [0x0041A390], 0x3ECAE0
	X86_MEM_WRITE_u32(base, 0x41A390u, 4115168);
	// 0x2C0959: mov dword ptr [0x0041A3A8], 0x3F1D08
	X86_MEM_WRITE_u32(base, 0x41A3A8u, 4136200);
	// 0x2C0963: mov [0x0041A3AC], ecx
	X86_MEM_WRITE_u32(base, 0x41A3ACu, ctx.ecx);
	// 0x2C0969: mov dword ptr [0x0041A3B0], 0x3F3090
	X86_MEM_WRITE_u32(base, 0x41A3B0u, 4141200);
	// 0x2C0973: mov dword ptr [0x0041A3B4], 0x50
	X86_MEM_WRITE_u32(base, 0x41A3B4u, 80);
	// 0x2C097D: mov dword ptr [0x0041A3B8], 0x3F11A0
	X86_MEM_WRITE_u32(base, 0x41A3B8u, 4133280);
	// 0x2C0987: mov dword ptr [0x0041A3C0], 0x3F48C8
	X86_MEM_WRITE_u32(base, 0x41A3C0u, 4147400);
	// 0x2C0991: mov dword ptr [0x0041A3C4], 0x31
	X86_MEM_WRITE_u32(base, 0x41A3C4u, 49);
	// 0x2C099B: mov dword ptr [0x0041A3C8], 0x3F3D10
	X86_MEM_WRITE_u32(base, 0x41A3C8u, 4144400);
	// 0x2C09A5: mov dword ptr [0x0041A3CC], 0x4B
	X86_MEM_WRITE_u32(base, 0x41A3CCu, 75);
	// 0x2C09AF: mov dword ptr [0x0041A3D8], 0x3F2690
	X86_MEM_WRITE_u32(base, 0x41A3D8u, 4138640);
	// 0x2C09B9: mov dword ptr [0x0041A3DC], 0x40
	X86_MEM_WRITE_u32(base, 0x41A3DCu, 64);
	// 0x2C09C3: mov dword ptr [0x0041A3E8], 0x3F1D08
	X86_MEM_WRITE_u32(base, 0x41A3E8u, 4136200);
	// 0x2C09CD: mov [0x0041A3EC], ecx
	X86_MEM_WRITE_u32(base, 0x41A3ECu, ctx.ecx);
	// 0x2C09D3: mov dword ptr [0x0041A3F0], 0x3F11A0
	X86_MEM_WRITE_u32(base, 0x41A3F0u, 4133280);
	// 0x2C09DD: mov dword ptr [0x0041A408], 0x3F5C78
	X86_MEM_WRITE_u32(base, 0x41A408u, 4152440);
	// 0x2C09E7: mov dword ptr [0x0041A410], 0x3F61F0
	X86_MEM_WRITE_u32(base, 0x41A410u, 4153840);
	// 0x2C09F1: mov dword ptr [0x0041A414], 0x60
	X86_MEM_WRITE_u32(base, 0x41A414u, 96);
	// 0x2C09FB: mov [0x0041A41C], ecx
	X86_MEM_WRITE_u32(base, 0x41A41Cu, ctx.ecx);
	// 0x2C0A01: mov [0x0041A420], edx
	X86_MEM_WRITE_u32(base, 0x41A420u, ctx.edx);
	// 0x2C0A07: mov [0x0041A424], eax
	X86_MEM_WRITE_u32(base, 0x41A424u, ctx.eax);
	// 0x2C0A0C: mov dword ptr [0x0041A428], 0x3F5C78
	X86_MEM_WRITE_u32(base, 0x41A428u, 4152440);
	// 0x2C0A16: mov [0x0041A434], ecx
	X86_MEM_WRITE_u32(base, 0x41A434u, ctx.ecx);
	// 0x2C0A1C: mov [0x0041A438], edx
	X86_MEM_WRITE_u32(base, 0x41A438u, ctx.edx);
	// 0x2C0A22: mov [0x0041A43C], eax
	X86_MEM_WRITE_u32(base, 0x41A43Cu, ctx.eax);
	// 0x2C0A27: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2C0A28: ret
	return;
}

void sub_2C0A30(X86Context& ctx, uint8_t* base) {
	// 0x2C0A30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C0A38: movss [0x005A8B5C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B5Cu, ctx.xmm[0].u32[0]);
	// 0x2C0A40: ret
	return;
}

void sub_2C0A50(X86Context& ctx, uint8_t* base) {
	// 0x2C0A50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C0A58: movss [0x005A8B60], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B60u, ctx.xmm[0].u32[0]);
	// 0x2C0A60: ret
	return;
}

void sub_2C0A70(X86Context& ctx, uint8_t* base) {
	// 0x2C0A70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C0A78: movss [0x005A8B58], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B58u, ctx.xmm[0].u32[0]);
	// 0x2C0A80: ret
	return;
}

void sub_2C0A90(X86Context& ctx, uint8_t* base) {
	// 0x2C0A90: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C0A98: movss [0x005A8B68], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B68u, ctx.xmm[0].u32[0]);
	// 0x2C0AA0: ret
	return;
}

void sub_2C0AB0(X86Context& ctx, uint8_t* base) {
	// 0x2C0AB0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C0AB8: movss [0x005A8B6C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B6Cu, ctx.xmm[0].u32[0]);
	// 0x2C0AC0: ret
	return;
}

void sub_2C0AD0(X86Context& ctx, uint8_t* base) {
	// 0x2C0AD0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C0AD8: movss [0x005A8B64], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B64u, ctx.xmm[0].u32[0]);
	// 0x2C0AE0: ret
	return;
}

void sub_2C0AF0(X86Context& ctx, uint8_t* base) {
	// 0x2C0AF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2C0AF8: movss [0x005A8BC4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BC4u, ctx.xmm[0].u32[0]);
	// 0x2C0B00: ret
	return;
}

void sub_2C0B10(X86Context& ctx, uint8_t* base) {
	// 0x2C0B10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2C0B18: movss [0x005A8BE0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BE0u, ctx.xmm[0].u32[0]);
	// 0x2C0B20: ret
	return;
}

void sub_2C0B30(X86Context& ctx, uint8_t* base) {
	// 0x2C0B30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2C0B38: movss [0x005A8BB8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BB8u, ctx.xmm[0].u32[0]);
	// 0x2C0B40: ret
	return;
}

void sub_2C0B50(X86Context& ctx, uint8_t* base) {
	// 0x2C0B50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2C0B58: movss [0x005A8B70], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B70u, ctx.xmm[0].u32[0]);
	// 0x2C0B60: ret
	return;
}

void sub_2C0B70(X86Context& ctx, uint8_t* base) {
	// 0x2C0B70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C0B78: movss [0x005A8BC8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BC8u, ctx.xmm[0].u32[0]);
	// 0x2C0B80: ret
	return;
}

void sub_2C0B90(X86Context& ctx, uint8_t* base) {
	// 0x2C0B90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C0B98: movss [0x005A8B8C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B8Cu, ctx.xmm[0].u32[0]);
	// 0x2C0BA0: ret
	return;
}

void sub_2C0BB0(X86Context& ctx, uint8_t* base) {
	// 0x2C0BB0: movss xmm0, dword ptr [0x005A8BC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BC8u);
	// 0x2C0BB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C0BC0: movss [0x005A8C00], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C00u, ctx.xmm[0].u32[0]);
	// 0x2C0BC8: ret
	return;
}

void sub_2C0BD0(X86Context& ctx, uint8_t* base) {
	// 0x2C0BD0: movss xmm0, dword ptr [0x005A8B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B8Cu);
	// 0x2C0BD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C0BE0: movss [0x005A8BE8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BE8u, ctx.xmm[0].u32[0]);
	// 0x2C0BE8: ret
	return;
}

void sub_2C0BF0(X86Context& ctx, uint8_t* base) {
	// 0x2C0BF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C0BF8: movss [0x005A8C18], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C18u, ctx.xmm[0].u32[0]);
	// 0x2C0C00: ret
	return;
}

void sub_2C0C10(X86Context& ctx, uint8_t* base) {
	// 0x2C0C10: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2C0C18: movss [0x005A8C04], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C04u, ctx.xmm[0].u32[0]);
	// 0x2C0C20: ret
	return;
}

void sub_2C0C30(X86Context& ctx, uint8_t* base) {
	// 0x2C0C30: movss xmm0, dword ptr [0x005A8C04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8C04u);
	// 0x2C0C38: movss [0x005A8C14], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C14u, ctx.xmm[0].u32[0]);
	// 0x2C0C40: ret
	return;
}

void sub_2C0C50(X86Context& ctx, uint8_t* base) {
	// 0x2C0C50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2C0C58: movss [0x005A8B78], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B78u, ctx.xmm[0].u32[0]);
	// 0x2C0C60: ret
	return;
}

void sub_2C0C70(X86Context& ctx, uint8_t* base) {
	// 0x2C0C70: movss xmm0, dword ptr [0x005A8B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B8Cu);
	// 0x2C0C78: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2C0C80: movss [0x005A8C0C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C0Cu, ctx.xmm[0].u32[0]);
	// 0x2C0C88: ret
	return;
}

void sub_2C0C90(X86Context& ctx, uint8_t* base) {
	// 0x2C0C90: movss xmm0, dword ptr [0x005A8B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B8Cu);
	// 0x2C0C98: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2C0CA0: movss [0x005A8BB4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BB4u, ctx.xmm[0].u32[0]);
	// 0x2C0CA8: ret
	return;
}

void sub_2C0CB0(X86Context& ctx, uint8_t* base) {
	// 0x2C0CB0: movss xmm0, dword ptr [0x005A8B8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B8Cu);
	// 0x2C0CB8: subss xmm0, [0x005A8BB4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8BB4u);
	// 0x2C0CC0: movss [0x005A8B94], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B94u, ctx.xmm[0].u32[0]);
	// 0x2C0CC8: ret
	return;
}

void sub_2C0CD0(X86Context& ctx, uint8_t* base) {
	// 0x2C0CD0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2C0CD8: movss [0x005A8BDC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BDCu, ctx.xmm[0].u32[0]);
	// 0x2C0CE0: ret
	return;
}

void sub_2C0CF0(X86Context& ctx, uint8_t* base) {
	// 0x2C0CF0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2C0CF8: movss [0x005A8B90], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B90u, ctx.xmm[0].u32[0]);
	// 0x2C0D00: ret
	return;
}

void sub_2C0D10(X86Context& ctx, uint8_t* base) {
	// 0x2C0D10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2C0D18: movss [0x005A8BA0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BA0u, ctx.xmm[0].u32[0]);
	// 0x2C0D20: ret
	return;
}

void sub_2C0D30(X86Context& ctx, uint8_t* base) {
	// 0x2C0D30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2C0D38: movss [0x005A8BF4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BF4u, ctx.xmm[0].u32[0]);
	// 0x2C0D40: ret
	return;
}

void sub_2C0D50(X86Context& ctx, uint8_t* base) {
	// 0x2C0D50: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2C0D58: movss [0x005A8BD8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BD8u, ctx.xmm[0].u32[0]);
	// 0x2C0D60: ret
	return;
}

void sub_2C0D70(X86Context& ctx, uint8_t* base) {
	// 0x2C0D70: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2C0D78: movss [0x005A8B88], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B88u, ctx.xmm[0].u32[0]);
	// 0x2C0D80: ret
	return;
}

void sub_2C0D90(X86Context& ctx, uint8_t* base) {
	// 0x2C0D90: movss xmm0, dword ptr [0x005A8BA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BA0u);
	// 0x2C0D98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C0DA0: movss [0x005A8B7C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B7Cu, ctx.xmm[0].u32[0]);
	// 0x2C0DA8: ret
	return;
}

void sub_2C0DB0(X86Context& ctx, uint8_t* base) {
	// 0x2C0DB0: movss xmm0, dword ptr [0x005A8BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BF4u);
	// 0x2C0DB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2C0DC0: movss [0x005A8BC0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BC0u, ctx.xmm[0].u32[0]);
	// 0x2C0DC8: ret
	return;
}

void sub_2C0DD0(X86Context& ctx, uint8_t* base) {
	// 0x2C0DD0: movss xmm0, dword ptr [0x005A8B7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B7Cu);
	// 0x2C0DD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2C0DE0: movss [0x005A8BD0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BD0u, ctx.xmm[0].u32[0]);
	// 0x2C0DE8: ret
	return;
}

void sub_2C0DF0(X86Context& ctx, uint8_t* base) {
	// 0x2C0DF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C0DF8: movss [0x005A8B74], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B74u, ctx.xmm[0].u32[0]);
	// 0x2C0E00: ret
	return;
}

void sub_2C0E10(X86Context& ctx, uint8_t* base) {
	// 0x2C0E10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2C0E18: movss [0x005A8BA4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BA4u, ctx.xmm[0].u32[0]);
	// 0x2C0E20: ret
	return;
}

void sub_2C0E30(X86Context& ctx, uint8_t* base) {
	// 0x2C0E30: movss xmm0, dword ptr [0x005A8BA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BA0u);
	// 0x2C0E38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C0E40: movss [0x005A8BB0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BB0u, ctx.xmm[0].u32[0]);
	// 0x2C0E48: ret
	return;
}

void sub_2C0E50(X86Context& ctx, uint8_t* base) {
	// 0x2C0E50: movss xmm0, dword ptr [0x005A8BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BF4u);
	// 0x2C0E58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2C0E60: movss [0x005A8BF8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BF8u, ctx.xmm[0].u32[0]);
	// 0x2C0E68: ret
	return;
}

void sub_2C0E70(X86Context& ctx, uint8_t* base) {
	// 0x2C0E70: movss xmm0, dword ptr [0x005A8BB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BB0u);
	// 0x2C0E78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C0E80: movss [0x005A8BE4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BE4u, ctx.xmm[0].u32[0]);
	// 0x2C0E88: ret
	return;
}

void sub_2C0E90(X86Context& ctx, uint8_t* base) {
	// 0x2C0E90: movss xmm0, dword ptr [0x005A8BF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BF8u);
	// 0x2C0E98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C0EA0: movss [0x005A8C08], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C08u, ctx.xmm[0].u32[0]);
	// 0x2C0EA8: ret
	return;
}

void sub_2C0EB0(X86Context& ctx, uint8_t* base) {
	// 0x2C0EB0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2C0EB8: movss [0x005A8B80], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B80u, ctx.xmm[0].u32[0]);
	// 0x2C0EC0: ret
	return;
}

void sub_2C0ED0(X86Context& ctx, uint8_t* base) {
	// 0x2C0ED0: movss xmm0, dword ptr [0x005A8BA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BA0u);
	// 0x2C0ED8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C0EE0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2C0EE8: movss [0x005A8BF0], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BF0u, ctx.xmm[0].u32[0]);
	// 0x2C0EF0: ret
	return;
}

void sub_2C0F00(X86Context& ctx, uint8_t* base) {
	// 0x2C0F00: movss xmm0, dword ptr [0x005A8BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BF4u);
	// 0x2C0F08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C0F10: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2C0F18: movss [0x005A8B98], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B98u, ctx.xmm[0].u32[0]);
	// 0x2C0F20: ret
	return;
}

void sub_2C0F30(X86Context& ctx, uint8_t* base) {
	// 0x2C0F30: movss xmm0, dword ptr [0x005A8BA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BA0u);
	// 0x2C0F38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C0F40: movss [0x005A8B9C], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B9Cu, ctx.xmm[0].u32[0]);
	// 0x2C0F48: ret
	return;
}

void sub_2C0F50(X86Context& ctx, uint8_t* base) {
	// 0x2C0F50: movss xmm0, dword ptr [0x005A8BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BF4u);
	// 0x2C0F58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2C0F60: movss [0x005A8BFC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BFCu, ctx.xmm[0].u32[0]);
	// 0x2C0F68: ret
	return;
}

void sub_2C0F70(X86Context& ctx, uint8_t* base) {
	// 0x2C0F70: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2C0F78: movss [0x005A8B84], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8B84u, ctx.xmm[0].u32[0]);
	// 0x2C0F80: ret
	return;
}

void sub_2C0F90(X86Context& ctx, uint8_t* base) {
	// 0x2C0F90: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2C0F98: movss [0x005A8BAC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BACu, ctx.xmm[0].u32[0]);
	// 0x2C0FA0: ret
	return;
}

void sub_2C0FB0(X86Context& ctx, uint8_t* base) {
	// 0x2C0FB0: movss xmm0, dword ptr [0x005A8B84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8B84u);
	// 0x2C0FB8: movss [0x005A8C10], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8C10u, ctx.xmm[0].u32[0]);
	// 0x2C0FC0: ret
	return;
}

void sub_2C0FD0(X86Context& ctx, uint8_t* base) {
	// 0x2C0FD0: movss xmm0, dword ptr [0x005A8BF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BF4u);
	// 0x2C0FD8: subss xmm0, [0x005A8B84]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8B84u);
	// 0x2C0FE0: movss [0x005A8BD4], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BD4u, ctx.xmm[0].u32[0]);
	// 0x2C0FE8: ret
	return;
}

void sub_2C0FF0(X86Context& ctx, uint8_t* base) {
	// 0x2C0FF0: movss xmm0, dword ptr [0x005A8BD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BD4u);
	// 0x2C0FF8: subss xmm0, [0x005A8BAC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5A8BACu);
	// 0x2C1000: movss [0x005A8BCC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BCCu, ctx.xmm[0].u32[0]);
	// 0x2C1008: ret
	return;
}

void sub_2C1010(X86Context& ctx, uint8_t* base) {
	// 0x2C1010: movss xmm0, dword ptr [0x005A8BFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5A8BFCu);
	// 0x2C1018: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2C1020: movss [0x005A8BBC], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BBCu, ctx.xmm[0].u32[0]);
	// 0x2C1028: ret
	return;
}

void sub_2C1030(X86Context& ctx, uint8_t* base) {
	// 0x2C1030: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2C1038: movss [0x005A8BA8], xmm0
	X86_MEM_WRITE_u32(base, 0x5A8BA8u, ctx.xmm[0].u32[0]);
	// 0x2C1040: ret
	return;
}

