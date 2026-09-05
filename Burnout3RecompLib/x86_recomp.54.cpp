#include "x86_recomp_shared.h"

void sub_28DBC0(X86Context& ctx, uint8_t* base) {
	// 0x28DBC0: movss xmm0, dword ptr [0x0056BE88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE88u);
	// 0x28DBC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28DBD0: movss [0x0056BE48], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE48u, ctx.xmm[0].u32[0]);
	// 0x28DBD8: ret
	return;
}

void sub_28DBE0(X86Context& ctx, uint8_t* base) {
	// 0x28DBE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28DBE8: movss [0x0056BE34], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE34u, ctx.xmm[0].u32[0]);
	// 0x28DBF0: ret
	return;
}

void sub_28DC00(X86Context& ctx, uint8_t* base) {
	// 0x28DC00: movss xmm0, dword ptr [0x0056BE48]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BE48u);
	// 0x28DC08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28DC10: movss [0x0056BE78], xmm0
	X86_MEM_WRITE_u32(base, 0x56BE78u, ctx.xmm[0].u32[0]);
	// 0x28DC18: ret
	return;
}

void sub_28DC20(X86Context& ctx, uint8_t* base) {
	// 0x28DC20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28DC28: movss [0x0056BEFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEFCu, ctx.xmm[0].u32[0]);
	// 0x28DC30: ret
	return;
}

void sub_28DC40(X86Context& ctx, uint8_t* base) {
	// 0x28DC40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28DC48: movss [0x0056BF18], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF18u, ctx.xmm[0].u32[0]);
	// 0x28DC50: ret
	return;
}

void sub_28DC60(X86Context& ctx, uint8_t* base) {
	// 0x28DC60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28DC68: movss [0x0056BEF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEF0u, ctx.xmm[0].u32[0]);
	// 0x28DC70: ret
	return;
}

void sub_28DC80(X86Context& ctx, uint8_t* base) {
	// 0x28DC80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28DC88: movss [0x0056BEA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEA8u, ctx.xmm[0].u32[0]);
	// 0x28DC90: ret
	return;
}

void sub_28DCA0(X86Context& ctx, uint8_t* base) {
	// 0x28DCA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28DCA8: movss [0x0056BF00], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF00u, ctx.xmm[0].u32[0]);
	// 0x28DCB0: ret
	return;
}

void sub_28DCC0(X86Context& ctx, uint8_t* base) {
	// 0x28DCC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28DCC8: movss [0x0056BEC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEC4u, ctx.xmm[0].u32[0]);
	// 0x28DCD0: ret
	return;
}

void sub_28DCE0(X86Context& ctx, uint8_t* base) {
	// 0x28DCE0: movss xmm0, dword ptr [0x0056BF00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF00u);
	// 0x28DCE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28DCF0: movss [0x0056BF38], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF38u, ctx.xmm[0].u32[0]);
	// 0x28DCF8: ret
	return;
}

void sub_28DD00(X86Context& ctx, uint8_t* base) {
	// 0x28DD00: movss xmm0, dword ptr [0x0056BEC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEC4u);
	// 0x28DD08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28DD10: movss [0x0056BF20], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF20u, ctx.xmm[0].u32[0]);
	// 0x28DD18: ret
	return;
}

void sub_28DD20(X86Context& ctx, uint8_t* base) {
	// 0x28DD20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28DD28: movss [0x0056BF50], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF50u, ctx.xmm[0].u32[0]);
	// 0x28DD30: ret
	return;
}

void sub_28DD40(X86Context& ctx, uint8_t* base) {
	// 0x28DD40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28DD48: movss [0x0056BF3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF3Cu, ctx.xmm[0].u32[0]);
	// 0x28DD50: ret
	return;
}

void sub_28DD60(X86Context& ctx, uint8_t* base) {
	// 0x28DD60: movss xmm0, dword ptr [0x0056BF3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF3Cu);
	// 0x28DD68: movss [0x0056BF4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF4Cu, ctx.xmm[0].u32[0]);
	// 0x28DD70: ret
	return;
}

void sub_28DD80(X86Context& ctx, uint8_t* base) {
	// 0x28DD80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28DD88: movss [0x0056BEB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEB0u, ctx.xmm[0].u32[0]);
	// 0x28DD90: ret
	return;
}

void sub_28DDA0(X86Context& ctx, uint8_t* base) {
	// 0x28DDA0: movss xmm0, dword ptr [0x0056BEC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEC4u);
	// 0x28DDA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28DDB0: movss [0x0056BF44], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF44u, ctx.xmm[0].u32[0]);
	// 0x28DDB8: ret
	return;
}

void sub_28DDC0(X86Context& ctx, uint8_t* base) {
	// 0x28DDC0: movss xmm0, dword ptr [0x0056BEC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEC4u);
	// 0x28DDC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28DDD0: movss [0x0056BEEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEECu, ctx.xmm[0].u32[0]);
	// 0x28DDD8: ret
	return;
}

void sub_28DDE0(X86Context& ctx, uint8_t* base) {
	// 0x28DDE0: movss xmm0, dword ptr [0x0056BEC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEC4u);
	// 0x28DDE8: subss xmm0, [0x0056BEEC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BEECu);
	// 0x28DDF0: movss [0x0056BECC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BECCu, ctx.xmm[0].u32[0]);
	// 0x28DDF8: ret
	return;
}

void sub_28DE00(X86Context& ctx, uint8_t* base) {
	// 0x28DE00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28DE08: movss [0x0056BF14], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF14u, ctx.xmm[0].u32[0]);
	// 0x28DE10: ret
	return;
}

void sub_28DE20(X86Context& ctx, uint8_t* base) {
	// 0x28DE20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28DE28: movss [0x0056BEC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEC8u, ctx.xmm[0].u32[0]);
	// 0x28DE30: ret
	return;
}

void sub_28DE40(X86Context& ctx, uint8_t* base) {
	// 0x28DE40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28DE48: movss [0x0056BED8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BED8u, ctx.xmm[0].u32[0]);
	// 0x28DE50: ret
	return;
}

void sub_28DE60(X86Context& ctx, uint8_t* base) {
	// 0x28DE60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28DE68: movss [0x0056BF2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF2Cu, ctx.xmm[0].u32[0]);
	// 0x28DE70: ret
	return;
}

void sub_28DE80(X86Context& ctx, uint8_t* base) {
	// 0x28DE80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28DE88: movss [0x0056BF10], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF10u, ctx.xmm[0].u32[0]);
	// 0x28DE90: ret
	return;
}

void sub_28DEA0(X86Context& ctx, uint8_t* base) {
	// 0x28DEA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28DEA8: movss [0x0056BEC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEC0u, ctx.xmm[0].u32[0]);
	// 0x28DEB0: ret
	return;
}

void sub_28DEC0(X86Context& ctx, uint8_t* base) {
	// 0x28DEC0: movss xmm0, dword ptr [0x0056BED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BED8u);
	// 0x28DEC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28DED0: movss [0x0056BEB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEB4u, ctx.xmm[0].u32[0]);
	// 0x28DED8: ret
	return;
}

void sub_28DEE0(X86Context& ctx, uint8_t* base) {
	// 0x28DEE0: movss xmm0, dword ptr [0x0056BF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF2Cu);
	// 0x28DEE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28DEF0: movss [0x0056BEF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEF8u, ctx.xmm[0].u32[0]);
	// 0x28DEF8: ret
	return;
}

void sub_28DF00(X86Context& ctx, uint8_t* base) {
	// 0x28DF00: movss xmm0, dword ptr [0x0056BEB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEB4u);
	// 0x28DF08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28DF10: movss [0x0056BF08], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF08u, ctx.xmm[0].u32[0]);
	// 0x28DF18: ret
	return;
}

void sub_28DF20(X86Context& ctx, uint8_t* base) {
	// 0x28DF20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28DF28: movss [0x0056BEAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEACu, ctx.xmm[0].u32[0]);
	// 0x28DF30: ret
	return;
}

void sub_28DF40(X86Context& ctx, uint8_t* base) {
	// 0x28DF40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28DF48: movss [0x0056BEDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEDCu, ctx.xmm[0].u32[0]);
	// 0x28DF50: ret
	return;
}

void sub_28DF60(X86Context& ctx, uint8_t* base) {
	// 0x28DF60: movss xmm0, dword ptr [0x0056BED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BED8u);
	// 0x28DF68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28DF70: movss [0x0056BEE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEE8u, ctx.xmm[0].u32[0]);
	// 0x28DF78: ret
	return;
}

void sub_28DF80(X86Context& ctx, uint8_t* base) {
	// 0x28DF80: movss xmm0, dword ptr [0x0056BF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF2Cu);
	// 0x28DF88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28DF90: movss [0x0056BF30], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF30u, ctx.xmm[0].u32[0]);
	// 0x28DF98: ret
	return;
}

void sub_28DFA0(X86Context& ctx, uint8_t* base) {
	// 0x28DFA0: movss xmm0, dword ptr [0x0056BEE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEE8u);
	// 0x28DFA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DFB0: movss [0x0056BF1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF1Cu, ctx.xmm[0].u32[0]);
	// 0x28DFB8: ret
	return;
}

void sub_28DFC0(X86Context& ctx, uint8_t* base) {
	// 0x28DFC0: movss xmm0, dword ptr [0x0056BF30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF30u);
	// 0x28DFC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28DFD0: movss [0x0056BF40], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF40u, ctx.xmm[0].u32[0]);
	// 0x28DFD8: ret
	return;
}

void sub_28DFE0(X86Context& ctx, uint8_t* base) {
	// 0x28DFE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28DFE8: movss [0x0056BEB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEB8u, ctx.xmm[0].u32[0]);
	// 0x28DFF0: ret
	return;
}

void sub_28E000(X86Context& ctx, uint8_t* base) {
	// 0x28E000: movss xmm0, dword ptr [0x0056BED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BED8u);
	// 0x28E008: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E010: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28E018: movss [0x0056BF28], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF28u, ctx.xmm[0].u32[0]);
	// 0x28E020: ret
	return;
}

void sub_28E030(X86Context& ctx, uint8_t* base) {
	// 0x28E030: movss xmm0, dword ptr [0x0056BF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF2Cu);
	// 0x28E038: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E040: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28E048: movss [0x0056BED0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BED0u, ctx.xmm[0].u32[0]);
	// 0x28E050: ret
	return;
}

void sub_28E060(X86Context& ctx, uint8_t* base) {
	// 0x28E060: movss xmm0, dword ptr [0x0056BED8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BED8u);
	// 0x28E068: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E070: movss [0x0056BED4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BED4u, ctx.xmm[0].u32[0]);
	// 0x28E078: ret
	return;
}

void sub_28E080(X86Context& ctx, uint8_t* base) {
	// 0x28E080: movss xmm0, dword ptr [0x0056BF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF2Cu);
	// 0x28E088: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E090: movss [0x0056BF34], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF34u, ctx.xmm[0].u32[0]);
	// 0x28E098: ret
	return;
}

void sub_28E0A0(X86Context& ctx, uint8_t* base) {
	// 0x28E0A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28E0A8: movss [0x0056BEBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEBCu, ctx.xmm[0].u32[0]);
	// 0x28E0B0: ret
	return;
}

void sub_28E0C0(X86Context& ctx, uint8_t* base) {
	// 0x28E0C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28E0C8: movss [0x0056BEE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEE4u, ctx.xmm[0].u32[0]);
	// 0x28E0D0: ret
	return;
}

void sub_28E0E0(X86Context& ctx, uint8_t* base) {
	// 0x28E0E0: movss xmm0, dword ptr [0x0056BEBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEBCu);
	// 0x28E0E8: movss [0x0056BF48], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF48u, ctx.xmm[0].u32[0]);
	// 0x28E0F0: ret
	return;
}

void sub_28E100(X86Context& ctx, uint8_t* base) {
	// 0x28E100: movss xmm0, dword ptr [0x0056BF2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF2Cu);
	// 0x28E108: subss xmm0, [0x0056BEBC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BEBCu);
	// 0x28E110: movss [0x0056BF0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF0Cu, ctx.xmm[0].u32[0]);
	// 0x28E118: ret
	return;
}

void sub_28E120(X86Context& ctx, uint8_t* base) {
	// 0x28E120: movss xmm0, dword ptr [0x0056BF0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF0Cu);
	// 0x28E128: subss xmm0, [0x0056BEE4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BEE4u);
	// 0x28E130: movss [0x0056BF04], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF04u, ctx.xmm[0].u32[0]);
	// 0x28E138: ret
	return;
}

void sub_28E140(X86Context& ctx, uint8_t* base) {
	// 0x28E140: movss xmm0, dword ptr [0x0056BF34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF34u);
	// 0x28E148: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28E150: movss [0x0056BEF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEF4u, ctx.xmm[0].u32[0]);
	// 0x28E158: ret
	return;
}

void sub_28E160(X86Context& ctx, uint8_t* base) {
	// 0x28E160: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28E168: movss [0x0056BEE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BEE0u, ctx.xmm[0].u32[0]);
	// 0x28E170: ret
	return;
}

void sub_28E180(X86Context& ctx, uint8_t* base) {
	// 0x28E180: movss xmm0, dword ptr [0x0056BEF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BEF4u);
	// 0x28E188: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28E190: movss [0x0056BF24], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF24u, ctx.xmm[0].u32[0]);
	// 0x28E198: ret
	return;
}

void sub_28E1A0(X86Context& ctx, uint8_t* base) {
	// 0x28E1A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28E1A8: movss [0x0056BFA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFA8u, ctx.xmm[0].u32[0]);
	// 0x28E1B0: ret
	return;
}

void sub_28E1C0(X86Context& ctx, uint8_t* base) {
	// 0x28E1C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28E1C8: movss [0x0056BFC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFC4u, ctx.xmm[0].u32[0]);
	// 0x28E1D0: ret
	return;
}

void sub_28E1E0(X86Context& ctx, uint8_t* base) {
	// 0x28E1E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28E1E8: movss [0x0056BF9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF9Cu, ctx.xmm[0].u32[0]);
	// 0x28E1F0: ret
	return;
}

void sub_28E200(X86Context& ctx, uint8_t* base) {
	// 0x28E200: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28E208: movss [0x0056BF54], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF54u, ctx.xmm[0].u32[0]);
	// 0x28E210: ret
	return;
}

void sub_28E220(X86Context& ctx, uint8_t* base) {
	// 0x28E220: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28E228: movss [0x0056BFAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFACu, ctx.xmm[0].u32[0]);
	// 0x28E230: ret
	return;
}

void sub_28E240(X86Context& ctx, uint8_t* base) {
	// 0x28E240: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28E248: movss [0x0056BF70], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF70u, ctx.xmm[0].u32[0]);
	// 0x28E250: ret
	return;
}

void sub_28E260(X86Context& ctx, uint8_t* base) {
	// 0x28E260: movss xmm0, dword ptr [0x0056BFAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFACu);
	// 0x28E268: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28E270: movss [0x0056BFE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFE4u, ctx.xmm[0].u32[0]);
	// 0x28E278: ret
	return;
}

void sub_28E280(X86Context& ctx, uint8_t* base) {
	// 0x28E280: movss xmm0, dword ptr [0x0056BF70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF70u);
	// 0x28E288: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28E290: movss [0x0056BFCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFCCu, ctx.xmm[0].u32[0]);
	// 0x28E298: ret
	return;
}

void sub_28E2A0(X86Context& ctx, uint8_t* base) {
	// 0x28E2A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28E2A8: movss [0x0056BFFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFFCu, ctx.xmm[0].u32[0]);
	// 0x28E2B0: ret
	return;
}

void sub_28E2C0(X86Context& ctx, uint8_t* base) {
	// 0x28E2C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28E2C8: movss [0x0056BFE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFE8u, ctx.xmm[0].u32[0]);
	// 0x28E2D0: ret
	return;
}

void sub_28E2E0(X86Context& ctx, uint8_t* base) {
	// 0x28E2E0: movss xmm0, dword ptr [0x0056BFE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFE8u);
	// 0x28E2E8: movss [0x0056BFF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFF8u, ctx.xmm[0].u32[0]);
	// 0x28E2F0: ret
	return;
}

void sub_28E300(X86Context& ctx, uint8_t* base) {
	// 0x28E300: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28E308: movss [0x0056BF5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF5Cu, ctx.xmm[0].u32[0]);
	// 0x28E310: ret
	return;
}

void sub_28E320(X86Context& ctx, uint8_t* base) {
	// 0x28E320: movss xmm0, dword ptr [0x0056BF70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF70u);
	// 0x28E328: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28E330: movss [0x0056BFF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFF0u, ctx.xmm[0].u32[0]);
	// 0x28E338: ret
	return;
}

void sub_28E340(X86Context& ctx, uint8_t* base) {
	// 0x28E340: movss xmm0, dword ptr [0x0056BF70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF70u);
	// 0x28E348: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28E350: movss [0x0056BF98], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF98u, ctx.xmm[0].u32[0]);
	// 0x28E358: ret
	return;
}

void sub_28E360(X86Context& ctx, uint8_t* base) {
	// 0x28E360: movss xmm0, dword ptr [0x0056BF70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF70u);
	// 0x28E368: subss xmm0, [0x0056BF98]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BF98u);
	// 0x28E370: movss [0x0056BF78], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF78u, ctx.xmm[0].u32[0]);
	// 0x28E378: ret
	return;
}

void sub_28E380(X86Context& ctx, uint8_t* base) {
	// 0x28E380: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28E388: movss [0x0056BFC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFC0u, ctx.xmm[0].u32[0]);
	// 0x28E390: ret
	return;
}

void sub_28E3A0(X86Context& ctx, uint8_t* base) {
	// 0x28E3A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28E3A8: movss [0x0056BF74], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF74u, ctx.xmm[0].u32[0]);
	// 0x28E3B0: ret
	return;
}

void sub_28E3C0(X86Context& ctx, uint8_t* base) {
	// 0x28E3C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28E3C8: movss [0x0056BF84], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF84u, ctx.xmm[0].u32[0]);
	// 0x28E3D0: ret
	return;
}

void sub_28E3E0(X86Context& ctx, uint8_t* base) {
	// 0x28E3E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28E3E8: movss [0x0056BFD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFD8u, ctx.xmm[0].u32[0]);
	// 0x28E3F0: ret
	return;
}

void sub_28E400(X86Context& ctx, uint8_t* base) {
	// 0x28E400: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28E408: movss [0x0056BFBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFBCu, ctx.xmm[0].u32[0]);
	// 0x28E410: ret
	return;
}

void sub_28E420(X86Context& ctx, uint8_t* base) {
	// 0x28E420: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28E428: movss [0x0056BF6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF6Cu, ctx.xmm[0].u32[0]);
	// 0x28E430: ret
	return;
}

void sub_28E440(X86Context& ctx, uint8_t* base) {
	// 0x28E440: movss xmm0, dword ptr [0x0056BF84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF84u);
	// 0x28E448: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28E450: movss [0x0056BF60], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF60u, ctx.xmm[0].u32[0]);
	// 0x28E458: ret
	return;
}

void sub_28E460(X86Context& ctx, uint8_t* base) {
	// 0x28E460: movss xmm0, dword ptr [0x0056BFD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFD8u);
	// 0x28E468: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28E470: movss [0x0056BFA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFA4u, ctx.xmm[0].u32[0]);
	// 0x28E478: ret
	return;
}

void sub_28E480(X86Context& ctx, uint8_t* base) {
	// 0x28E480: movss xmm0, dword ptr [0x0056BF60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF60u);
	// 0x28E488: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28E490: movss [0x0056BFB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFB4u, ctx.xmm[0].u32[0]);
	// 0x28E498: ret
	return;
}

void sub_28E4A0(X86Context& ctx, uint8_t* base) {
	// 0x28E4A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28E4A8: movss [0x0056BF58], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF58u, ctx.xmm[0].u32[0]);
	// 0x28E4B0: ret
	return;
}

void sub_28E4C0(X86Context& ctx, uint8_t* base) {
	// 0x28E4C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28E4C8: movss [0x0056BF88], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF88u, ctx.xmm[0].u32[0]);
	// 0x28E4D0: ret
	return;
}

void sub_28E4E0(X86Context& ctx, uint8_t* base) {
	// 0x28E4E0: movss xmm0, dword ptr [0x0056BF84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF84u);
	// 0x28E4E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28E4F0: movss [0x0056BF94], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF94u, ctx.xmm[0].u32[0]);
	// 0x28E4F8: ret
	return;
}

void sub_28E500(X86Context& ctx, uint8_t* base) {
	// 0x28E500: movss xmm0, dword ptr [0x0056BFD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFD8u);
	// 0x28E508: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28E510: movss [0x0056BFDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFDCu, ctx.xmm[0].u32[0]);
	// 0x28E518: ret
	return;
}

void sub_28E520(X86Context& ctx, uint8_t* base) {
	// 0x28E520: movss xmm0, dword ptr [0x0056BF94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF94u);
	// 0x28E528: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E530: movss [0x0056BFC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFC8u, ctx.xmm[0].u32[0]);
	// 0x28E538: ret
	return;
}

void sub_28E540(X86Context& ctx, uint8_t* base) {
	// 0x28E540: movss xmm0, dword ptr [0x0056BFDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFDCu);
	// 0x28E548: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E550: movss [0x0056BFEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFECu, ctx.xmm[0].u32[0]);
	// 0x28E558: ret
	return;
}

void sub_28E560(X86Context& ctx, uint8_t* base) {
	// 0x28E560: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28E568: movss [0x0056BF64], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF64u, ctx.xmm[0].u32[0]);
	// 0x28E570: ret
	return;
}

void sub_28E580(X86Context& ctx, uint8_t* base) {
	// 0x28E580: movss xmm0, dword ptr [0x0056BF84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF84u);
	// 0x28E588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E590: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28E598: movss [0x0056BFD4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFD4u, ctx.xmm[0].u32[0]);
	// 0x28E5A0: ret
	return;
}

void sub_28E5B0(X86Context& ctx, uint8_t* base) {
	// 0x28E5B0: movss xmm0, dword ptr [0x0056BFD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFD8u);
	// 0x28E5B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E5C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28E5C8: movss [0x0056BF7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF7Cu, ctx.xmm[0].u32[0]);
	// 0x28E5D0: ret
	return;
}

void sub_28E5E0(X86Context& ctx, uint8_t* base) {
	// 0x28E5E0: movss xmm0, dword ptr [0x0056BF84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF84u);
	// 0x28E5E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E5F0: movss [0x0056BF80], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF80u, ctx.xmm[0].u32[0]);
	// 0x28E5F8: ret
	return;
}

void sub_28E600(X86Context& ctx, uint8_t* base) {
	// 0x28E600: movss xmm0, dword ptr [0x0056BFD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFD8u);
	// 0x28E608: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28E610: movss [0x0056BFE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFE0u, ctx.xmm[0].u32[0]);
	// 0x28E618: ret
	return;
}

void sub_28E620(X86Context& ctx, uint8_t* base) {
	// 0x28E620: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28E628: movss [0x0056BF68], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF68u, ctx.xmm[0].u32[0]);
	// 0x28E630: ret
	return;
}

void sub_28E640(X86Context& ctx, uint8_t* base) {
	// 0x28E640: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28E648: movss [0x0056BF90], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF90u, ctx.xmm[0].u32[0]);
	// 0x28E650: ret
	return;
}

void sub_28E660(X86Context& ctx, uint8_t* base) {
	// 0x28E660: movss xmm0, dword ptr [0x0056BF68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BF68u);
	// 0x28E668: movss [0x0056BFF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFF4u, ctx.xmm[0].u32[0]);
	// 0x28E670: ret
	return;
}

void sub_28E680(X86Context& ctx, uint8_t* base) {
	// 0x28E680: movss xmm0, dword ptr [0x0056BFD8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFD8u);
	// 0x28E688: subss xmm0, [0x0056BF68]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BF68u);
	// 0x28E690: movss [0x0056BFB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFB8u, ctx.xmm[0].u32[0]);
	// 0x28E698: ret
	return;
}

void sub_28E6A0(X86Context& ctx, uint8_t* base) {
	// 0x28E6A0: movss xmm0, dword ptr [0x0056BFB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFB8u);
	// 0x28E6A8: subss xmm0, [0x0056BF90]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56BF90u);
	// 0x28E6B0: movss [0x0056BFB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFB0u, ctx.xmm[0].u32[0]);
	// 0x28E6B8: ret
	return;
}

void sub_28E6C0(X86Context& ctx, uint8_t* base) {
	// 0x28E6C0: movss xmm0, dword ptr [0x0056BFE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFE0u);
	// 0x28E6C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28E6D0: movss [0x0056BFA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFA0u, ctx.xmm[0].u32[0]);
	// 0x28E6D8: ret
	return;
}

void sub_28E6E0(X86Context& ctx, uint8_t* base) {
	// 0x28E6E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28E6E8: movss [0x0056BF8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56BF8Cu, ctx.xmm[0].u32[0]);
	// 0x28E6F0: ret
	return;
}

void sub_28E700(X86Context& ctx, uint8_t* base) {
	// 0x28E700: movss xmm0, dword ptr [0x0056BFA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56BFA0u);
	// 0x28E708: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28E710: movss [0x0056BFD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56BFD0u, ctx.xmm[0].u32[0]);
	// 0x28E718: ret
	return;
}

void sub_28E720(X86Context& ctx, uint8_t* base) {
	// 0x28E720: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28E728: movss [0x0056C054], xmm0
	X86_MEM_WRITE_u32(base, 0x56C054u, ctx.xmm[0].u32[0]);
	// 0x28E730: ret
	return;
}

void sub_28E740(X86Context& ctx, uint8_t* base) {
	// 0x28E740: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28E748: movss [0x0056C070], xmm0
	X86_MEM_WRITE_u32(base, 0x56C070u, ctx.xmm[0].u32[0]);
	// 0x28E750: ret
	return;
}

void sub_28E760(X86Context& ctx, uint8_t* base) {
	// 0x28E760: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28E768: movss [0x0056C048], xmm0
	X86_MEM_WRITE_u32(base, 0x56C048u, ctx.xmm[0].u32[0]);
	// 0x28E770: ret
	return;
}

void sub_28E780(X86Context& ctx, uint8_t* base) {
	// 0x28E780: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28E788: movss [0x0056C000], xmm0
	X86_MEM_WRITE_u32(base, 0x56C000u, ctx.xmm[0].u32[0]);
	// 0x28E790: ret
	return;
}

void sub_28E7A0(X86Context& ctx, uint8_t* base) {
	// 0x28E7A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28E7A8: movss [0x0056C058], xmm0
	X86_MEM_WRITE_u32(base, 0x56C058u, ctx.xmm[0].u32[0]);
	// 0x28E7B0: ret
	return;
}

void sub_28E7C0(X86Context& ctx, uint8_t* base) {
	// 0x28E7C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28E7C8: movss [0x0056C01C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C01Cu, ctx.xmm[0].u32[0]);
	// 0x28E7D0: ret
	return;
}

void sub_28E7E0(X86Context& ctx, uint8_t* base) {
	// 0x28E7E0: movss xmm0, dword ptr [0x0056C058]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C058u);
	// 0x28E7E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28E7F0: movss [0x0056C090], xmm0
	X86_MEM_WRITE_u32(base, 0x56C090u, ctx.xmm[0].u32[0]);
	// 0x28E7F8: ret
	return;
}

void sub_28E800(X86Context& ctx, uint8_t* base) {
	// 0x28E800: movss xmm0, dword ptr [0x0056C01C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C01Cu);
	// 0x28E808: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28E810: movss [0x0056C078], xmm0
	X86_MEM_WRITE_u32(base, 0x56C078u, ctx.xmm[0].u32[0]);
	// 0x28E818: ret
	return;
}

void sub_28E820(X86Context& ctx, uint8_t* base) {
	// 0x28E820: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28E828: movss [0x0056C0A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0A8u, ctx.xmm[0].u32[0]);
	// 0x28E830: ret
	return;
}

void sub_28E840(X86Context& ctx, uint8_t* base) {
	// 0x28E840: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28E848: movss [0x0056C094], xmm0
	X86_MEM_WRITE_u32(base, 0x56C094u, ctx.xmm[0].u32[0]);
	// 0x28E850: ret
	return;
}

void sub_28E860(X86Context& ctx, uint8_t* base) {
	// 0x28E860: movss xmm0, dword ptr [0x0056C094]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C094u);
	// 0x28E868: movss [0x0056C0A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0A4u, ctx.xmm[0].u32[0]);
	// 0x28E870: ret
	return;
}

void sub_28E880(X86Context& ctx, uint8_t* base) {
	// 0x28E880: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28E888: movss [0x0056C008], xmm0
	X86_MEM_WRITE_u32(base, 0x56C008u, ctx.xmm[0].u32[0]);
	// 0x28E890: ret
	return;
}

void sub_28E8A0(X86Context& ctx, uint8_t* base) {
	// 0x28E8A0: movss xmm0, dword ptr [0x0056C01C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C01Cu);
	// 0x28E8A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28E8B0: movss [0x0056C09C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C09Cu, ctx.xmm[0].u32[0]);
	// 0x28E8B8: ret
	return;
}

void sub_28E8C0(X86Context& ctx, uint8_t* base) {
	// 0x28E8C0: movss xmm0, dword ptr [0x0056C01C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C01Cu);
	// 0x28E8C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28E8D0: movss [0x0056C044], xmm0
	X86_MEM_WRITE_u32(base, 0x56C044u, ctx.xmm[0].u32[0]);
	// 0x28E8D8: ret
	return;
}

void sub_28E8E0(X86Context& ctx, uint8_t* base) {
	// 0x28E8E0: movss xmm0, dword ptr [0x0056C01C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C01Cu);
	// 0x28E8E8: subss xmm0, [0x0056C044]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C044u);
	// 0x28E8F0: movss [0x0056C024], xmm0
	X86_MEM_WRITE_u32(base, 0x56C024u, ctx.xmm[0].u32[0]);
	// 0x28E8F8: ret
	return;
}

void sub_28E900(X86Context& ctx, uint8_t* base) {
	// 0x28E900: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28E908: movss [0x0056C06C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C06Cu, ctx.xmm[0].u32[0]);
	// 0x28E910: ret
	return;
}

void sub_28E920(X86Context& ctx, uint8_t* base) {
	// 0x28E920: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28E928: movss [0x0056C020], xmm0
	X86_MEM_WRITE_u32(base, 0x56C020u, ctx.xmm[0].u32[0]);
	// 0x28E930: ret
	return;
}

void sub_28E940(X86Context& ctx, uint8_t* base) {
	// 0x28E940: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28E948: movss [0x0056C030], xmm0
	X86_MEM_WRITE_u32(base, 0x56C030u, ctx.xmm[0].u32[0]);
	// 0x28E950: ret
	return;
}

void sub_28E960(X86Context& ctx, uint8_t* base) {
	// 0x28E960: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28E968: movss [0x0056C084], xmm0
	X86_MEM_WRITE_u32(base, 0x56C084u, ctx.xmm[0].u32[0]);
	// 0x28E970: ret
	return;
}

void sub_28E980(X86Context& ctx, uint8_t* base) {
	// 0x28E980: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28E988: movss [0x0056C068], xmm0
	X86_MEM_WRITE_u32(base, 0x56C068u, ctx.xmm[0].u32[0]);
	// 0x28E990: ret
	return;
}

void sub_28E9A0(X86Context& ctx, uint8_t* base) {
	// 0x28E9A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28E9A8: movss [0x0056C018], xmm0
	X86_MEM_WRITE_u32(base, 0x56C018u, ctx.xmm[0].u32[0]);
	// 0x28E9B0: ret
	return;
}

void sub_28E9C0(X86Context& ctx, uint8_t* base) {
	// 0x28E9C0: movss xmm0, dword ptr [0x0056C030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C030u);
	// 0x28E9C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28E9D0: movss [0x0056C00C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C00Cu, ctx.xmm[0].u32[0]);
	// 0x28E9D8: ret
	return;
}

void sub_28E9E0(X86Context& ctx, uint8_t* base) {
	// 0x28E9E0: movss xmm0, dword ptr [0x0056C084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C084u);
	// 0x28E9E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28E9F0: movss [0x0056C050], xmm0
	X86_MEM_WRITE_u32(base, 0x56C050u, ctx.xmm[0].u32[0]);
	// 0x28E9F8: ret
	return;
}

void sub_28EA00(X86Context& ctx, uint8_t* base) {
	// 0x28EA00: movss xmm0, dword ptr [0x0056C00C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C00Cu);
	// 0x28EA08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28EA10: movss [0x0056C060], xmm0
	X86_MEM_WRITE_u32(base, 0x56C060u, ctx.xmm[0].u32[0]);
	// 0x28EA18: ret
	return;
}

void sub_28EA20(X86Context& ctx, uint8_t* base) {
	// 0x28EA20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28EA28: movss [0x0056C004], xmm0
	X86_MEM_WRITE_u32(base, 0x56C004u, ctx.xmm[0].u32[0]);
	// 0x28EA30: ret
	return;
}

void sub_28EA40(X86Context& ctx, uint8_t* base) {
	// 0x28EA40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28EA48: movss [0x0056C034], xmm0
	X86_MEM_WRITE_u32(base, 0x56C034u, ctx.xmm[0].u32[0]);
	// 0x28EA50: ret
	return;
}

void sub_28EA60(X86Context& ctx, uint8_t* base) {
	// 0x28EA60: movss xmm0, dword ptr [0x0056C030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C030u);
	// 0x28EA68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28EA70: movss [0x0056C040], xmm0
	X86_MEM_WRITE_u32(base, 0x56C040u, ctx.xmm[0].u32[0]);
	// 0x28EA78: ret
	return;
}

void sub_28EA80(X86Context& ctx, uint8_t* base) {
	// 0x28EA80: movss xmm0, dword ptr [0x0056C084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C084u);
	// 0x28EA88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28EA90: movss [0x0056C088], xmm0
	X86_MEM_WRITE_u32(base, 0x56C088u, ctx.xmm[0].u32[0]);
	// 0x28EA98: ret
	return;
}

void sub_28EAA0(X86Context& ctx, uint8_t* base) {
	// 0x28EAA0: movss xmm0, dword ptr [0x0056C040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C040u);
	// 0x28EAA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28EAB0: movss [0x0056C074], xmm0
	X86_MEM_WRITE_u32(base, 0x56C074u, ctx.xmm[0].u32[0]);
	// 0x28EAB8: ret
	return;
}

void sub_28EAC0(X86Context& ctx, uint8_t* base) {
	// 0x28EAC0: movss xmm0, dword ptr [0x0056C088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C088u);
	// 0x28EAC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28EAD0: movss [0x0056C098], xmm0
	X86_MEM_WRITE_u32(base, 0x56C098u, ctx.xmm[0].u32[0]);
	// 0x28EAD8: ret
	return;
}

void sub_28EAE0(X86Context& ctx, uint8_t* base) {
	// 0x28EAE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28EAE8: movss [0x0056C010], xmm0
	X86_MEM_WRITE_u32(base, 0x56C010u, ctx.xmm[0].u32[0]);
	// 0x28EAF0: ret
	return;
}

void sub_28EB00(X86Context& ctx, uint8_t* base) {
	// 0x28EB00: movss xmm0, dword ptr [0x0056C030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C030u);
	// 0x28EB08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28EB10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28EB18: movss [0x0056C080], xmm0
	X86_MEM_WRITE_u32(base, 0x56C080u, ctx.xmm[0].u32[0]);
	// 0x28EB20: ret
	return;
}

void sub_28EB30(X86Context& ctx, uint8_t* base) {
	// 0x28EB30: movss xmm0, dword ptr [0x0056C084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C084u);
	// 0x28EB38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28EB40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28EB48: movss [0x0056C028], xmm0
	X86_MEM_WRITE_u32(base, 0x56C028u, ctx.xmm[0].u32[0]);
	// 0x28EB50: ret
	return;
}

void sub_28EB60(X86Context& ctx, uint8_t* base) {
	// 0x28EB60: movss xmm0, dword ptr [0x0056C030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C030u);
	// 0x28EB68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28EB70: movss [0x0056C02C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C02Cu, ctx.xmm[0].u32[0]);
	// 0x28EB78: ret
	return;
}

void sub_28EB80(X86Context& ctx, uint8_t* base) {
	// 0x28EB80: movss xmm0, dword ptr [0x0056C084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C084u);
	// 0x28EB88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28EB90: movss [0x0056C08C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C08Cu, ctx.xmm[0].u32[0]);
	// 0x28EB98: ret
	return;
}

void sub_28EBA0(X86Context& ctx, uint8_t* base) {
	// 0x28EBA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28EBA8: movss [0x0056C014], xmm0
	X86_MEM_WRITE_u32(base, 0x56C014u, ctx.xmm[0].u32[0]);
	// 0x28EBB0: ret
	return;
}

void sub_28EBC0(X86Context& ctx, uint8_t* base) {
	// 0x28EBC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28EBC8: movss [0x0056C03C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C03Cu, ctx.xmm[0].u32[0]);
	// 0x28EBD0: ret
	return;
}

void sub_28EBE0(X86Context& ctx, uint8_t* base) {
	// 0x28EBE0: movss xmm0, dword ptr [0x0056C014]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C014u);
	// 0x28EBE8: movss [0x0056C0A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0A0u, ctx.xmm[0].u32[0]);
	// 0x28EBF0: ret
	return;
}

void sub_28EC00(X86Context& ctx, uint8_t* base) {
	// 0x28EC00: movss xmm0, dword ptr [0x0056C084]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C084u);
	// 0x28EC08: subss xmm0, [0x0056C014]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C014u);
	// 0x28EC10: movss [0x0056C064], xmm0
	X86_MEM_WRITE_u32(base, 0x56C064u, ctx.xmm[0].u32[0]);
	// 0x28EC18: ret
	return;
}

void sub_28EC20(X86Context& ctx, uint8_t* base) {
	// 0x28EC20: movss xmm0, dword ptr [0x0056C064]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C064u);
	// 0x28EC28: subss xmm0, [0x0056C03C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C03Cu);
	// 0x28EC30: movss [0x0056C05C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C05Cu, ctx.xmm[0].u32[0]);
	// 0x28EC38: ret
	return;
}

void sub_28EC40(X86Context& ctx, uint8_t* base) {
	// 0x28EC40: movss xmm0, dword ptr [0x0056C08C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C08Cu);
	// 0x28EC48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28EC50: movss [0x0056C04C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C04Cu, ctx.xmm[0].u32[0]);
	// 0x28EC58: ret
	return;
}

void sub_28EC60(X86Context& ctx, uint8_t* base) {
	// 0x28EC60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28EC68: movss [0x0056C038], xmm0
	X86_MEM_WRITE_u32(base, 0x56C038u, ctx.xmm[0].u32[0]);
	// 0x28EC70: ret
	return;
}

void sub_28EC80(X86Context& ctx, uint8_t* base) {
	// 0x28EC80: movss xmm0, dword ptr [0x0056C04C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C04Cu);
	// 0x28EC88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28EC90: movss [0x0056C07C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C07Cu, ctx.xmm[0].u32[0]);
	// 0x28EC98: ret
	return;
}

void sub_28ECA0(X86Context& ctx, uint8_t* base) {
	// 0x28ECA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28ECA8: movss [0x0056C100], xmm0
	X86_MEM_WRITE_u32(base, 0x56C100u, ctx.xmm[0].u32[0]);
	// 0x28ECB0: ret
	return;
}

void sub_28ECC0(X86Context& ctx, uint8_t* base) {
	// 0x28ECC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28ECC8: movss [0x0056C11C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C11Cu, ctx.xmm[0].u32[0]);
	// 0x28ECD0: ret
	return;
}

void sub_28ECE0(X86Context& ctx, uint8_t* base) {
	// 0x28ECE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28ECE8: movss [0x0056C0F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0F4u, ctx.xmm[0].u32[0]);
	// 0x28ECF0: ret
	return;
}

void sub_28ED00(X86Context& ctx, uint8_t* base) {
	// 0x28ED00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28ED08: movss [0x0056C0AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0ACu, ctx.xmm[0].u32[0]);
	// 0x28ED10: ret
	return;
}

void sub_28ED20(X86Context& ctx, uint8_t* base) {
	// 0x28ED20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28ED28: movss [0x0056C104], xmm0
	X86_MEM_WRITE_u32(base, 0x56C104u, ctx.xmm[0].u32[0]);
	// 0x28ED30: ret
	return;
}

void sub_28ED40(X86Context& ctx, uint8_t* base) {
	// 0x28ED40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28ED48: movss [0x0056C0C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0C8u, ctx.xmm[0].u32[0]);
	// 0x28ED50: ret
	return;
}

void sub_28ED60(X86Context& ctx, uint8_t* base) {
	// 0x28ED60: movss xmm0, dword ptr [0x0056C104]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C104u);
	// 0x28ED68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28ED70: movss [0x0056C13C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C13Cu, ctx.xmm[0].u32[0]);
	// 0x28ED78: ret
	return;
}

void sub_28ED80(X86Context& ctx, uint8_t* base) {
	// 0x28ED80: movss xmm0, dword ptr [0x0056C0C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0C8u);
	// 0x28ED88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28ED90: movss [0x0056C124], xmm0
	X86_MEM_WRITE_u32(base, 0x56C124u, ctx.xmm[0].u32[0]);
	// 0x28ED98: ret
	return;
}

void sub_28EDA0(X86Context& ctx, uint8_t* base) {
	// 0x28EDA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28EDA8: movss [0x0056C154], xmm0
	X86_MEM_WRITE_u32(base, 0x56C154u, ctx.xmm[0].u32[0]);
	// 0x28EDB0: ret
	return;
}

void sub_28EDC0(X86Context& ctx, uint8_t* base) {
	// 0x28EDC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28EDC8: movss [0x0056C140], xmm0
	X86_MEM_WRITE_u32(base, 0x56C140u, ctx.xmm[0].u32[0]);
	// 0x28EDD0: ret
	return;
}

void sub_28EDE0(X86Context& ctx, uint8_t* base) {
	// 0x28EDE0: movss xmm0, dword ptr [0x0056C140]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C140u);
	// 0x28EDE8: movss [0x0056C150], xmm0
	X86_MEM_WRITE_u32(base, 0x56C150u, ctx.xmm[0].u32[0]);
	// 0x28EDF0: ret
	return;
}

void sub_28EE00(X86Context& ctx, uint8_t* base) {
	// 0x28EE00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28EE08: movss [0x0056C0B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0B4u, ctx.xmm[0].u32[0]);
	// 0x28EE10: ret
	return;
}

void sub_28EE20(X86Context& ctx, uint8_t* base) {
	// 0x28EE20: movss xmm0, dword ptr [0x0056C0C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0C8u);
	// 0x28EE28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28EE30: movss [0x0056C148], xmm0
	X86_MEM_WRITE_u32(base, 0x56C148u, ctx.xmm[0].u32[0]);
	// 0x28EE38: ret
	return;
}

void sub_28EE40(X86Context& ctx, uint8_t* base) {
	// 0x28EE40: movss xmm0, dword ptr [0x0056C0C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0C8u);
	// 0x28EE48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28EE50: movss [0x0056C0F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0F0u, ctx.xmm[0].u32[0]);
	// 0x28EE58: ret
	return;
}

void sub_28EE60(X86Context& ctx, uint8_t* base) {
	// 0x28EE60: movss xmm0, dword ptr [0x0056C0C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0C8u);
	// 0x28EE68: subss xmm0, [0x0056C0F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C0F0u);
	// 0x28EE70: movss [0x0056C0D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0D0u, ctx.xmm[0].u32[0]);
	// 0x28EE78: ret
	return;
}

void sub_28EE80(X86Context& ctx, uint8_t* base) {
	// 0x28EE80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28EE88: movss [0x0056C118], xmm0
	X86_MEM_WRITE_u32(base, 0x56C118u, ctx.xmm[0].u32[0]);
	// 0x28EE90: ret
	return;
}

void sub_28EEA0(X86Context& ctx, uint8_t* base) {
	// 0x28EEA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28EEA8: movss [0x0056C0CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0CCu, ctx.xmm[0].u32[0]);
	// 0x28EEB0: ret
	return;
}

void sub_28EEC0(X86Context& ctx, uint8_t* base) {
	// 0x28EEC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28EEC8: movss [0x0056C0DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0DCu, ctx.xmm[0].u32[0]);
	// 0x28EED0: ret
	return;
}

void sub_28EEE0(X86Context& ctx, uint8_t* base) {
	// 0x28EEE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28EEE8: movss [0x0056C130], xmm0
	X86_MEM_WRITE_u32(base, 0x56C130u, ctx.xmm[0].u32[0]);
	// 0x28EEF0: ret
	return;
}

void sub_28EF00(X86Context& ctx, uint8_t* base) {
	// 0x28EF00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28EF08: movss [0x0056C114], xmm0
	X86_MEM_WRITE_u32(base, 0x56C114u, ctx.xmm[0].u32[0]);
	// 0x28EF10: ret
	return;
}

void sub_28EF20(X86Context& ctx, uint8_t* base) {
	// 0x28EF20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28EF28: movss [0x0056C0C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0C4u, ctx.xmm[0].u32[0]);
	// 0x28EF30: ret
	return;
}

void sub_28EF40(X86Context& ctx, uint8_t* base) {
	// 0x28EF40: movss xmm0, dword ptr [0x0056C0DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0DCu);
	// 0x28EF48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28EF50: movss [0x0056C0B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0B8u, ctx.xmm[0].u32[0]);
	// 0x28EF58: ret
	return;
}

void sub_28EF60(X86Context& ctx, uint8_t* base) {
	// 0x28EF60: movss xmm0, dword ptr [0x0056C130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C130u);
	// 0x28EF68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28EF70: movss [0x0056C0FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0FCu, ctx.xmm[0].u32[0]);
	// 0x28EF78: ret
	return;
}

void sub_28EF80(X86Context& ctx, uint8_t* base) {
	// 0x28EF80: movss xmm0, dword ptr [0x0056C0B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0B8u);
	// 0x28EF88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28EF90: movss [0x0056C10C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C10Cu, ctx.xmm[0].u32[0]);
	// 0x28EF98: ret
	return;
}

void sub_28EFA0(X86Context& ctx, uint8_t* base) {
	// 0x28EFA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28EFA8: movss [0x0056C0B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0B0u, ctx.xmm[0].u32[0]);
	// 0x28EFB0: ret
	return;
}

void sub_28EFC0(X86Context& ctx, uint8_t* base) {
	// 0x28EFC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28EFC8: movss [0x0056C0E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0E0u, ctx.xmm[0].u32[0]);
	// 0x28EFD0: ret
	return;
}

void sub_28EFE0(X86Context& ctx, uint8_t* base) {
	// 0x28EFE0: movss xmm0, dword ptr [0x0056C0DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0DCu);
	// 0x28EFE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28EFF0: movss [0x0056C0EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0ECu, ctx.xmm[0].u32[0]);
	// 0x28EFF8: ret
	return;
}

void sub_28F000(X86Context& ctx, uint8_t* base) {
	// 0x28F000: movss xmm0, dword ptr [0x0056C130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C130u);
	// 0x28F008: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28F010: movss [0x0056C134], xmm0
	X86_MEM_WRITE_u32(base, 0x56C134u, ctx.xmm[0].u32[0]);
	// 0x28F018: ret
	return;
}

void sub_28F020(X86Context& ctx, uint8_t* base) {
	// 0x28F020: movss xmm0, dword ptr [0x0056C0EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0ECu);
	// 0x28F028: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F030: movss [0x0056C120], xmm0
	X86_MEM_WRITE_u32(base, 0x56C120u, ctx.xmm[0].u32[0]);
	// 0x28F038: ret
	return;
}

void sub_28F040(X86Context& ctx, uint8_t* base) {
	// 0x28F040: movss xmm0, dword ptr [0x0056C134]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C134u);
	// 0x28F048: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F050: movss [0x0056C144], xmm0
	X86_MEM_WRITE_u32(base, 0x56C144u, ctx.xmm[0].u32[0]);
	// 0x28F058: ret
	return;
}

void sub_28F060(X86Context& ctx, uint8_t* base) {
	// 0x28F060: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28F068: movss [0x0056C0BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0BCu, ctx.xmm[0].u32[0]);
	// 0x28F070: ret
	return;
}

void sub_28F080(X86Context& ctx, uint8_t* base) {
	// 0x28F080: movss xmm0, dword ptr [0x0056C0DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0DCu);
	// 0x28F088: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F090: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28F098: movss [0x0056C12C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C12Cu, ctx.xmm[0].u32[0]);
	// 0x28F0A0: ret
	return;
}

void sub_28F0B0(X86Context& ctx, uint8_t* base) {
	// 0x28F0B0: movss xmm0, dword ptr [0x0056C130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C130u);
	// 0x28F0B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F0C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28F0C8: movss [0x0056C0D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0D4u, ctx.xmm[0].u32[0]);
	// 0x28F0D0: ret
	return;
}

void sub_28F0E0(X86Context& ctx, uint8_t* base) {
	// 0x28F0E0: movss xmm0, dword ptr [0x0056C0DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0DCu);
	// 0x28F0E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F0F0: movss [0x0056C0D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0D8u, ctx.xmm[0].u32[0]);
	// 0x28F0F8: ret
	return;
}

void sub_28F100(X86Context& ctx, uint8_t* base) {
	// 0x28F100: movss xmm0, dword ptr [0x0056C130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C130u);
	// 0x28F108: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F110: movss [0x0056C138], xmm0
	X86_MEM_WRITE_u32(base, 0x56C138u, ctx.xmm[0].u32[0]);
	// 0x28F118: ret
	return;
}

void sub_28F120(X86Context& ctx, uint8_t* base) {
	// 0x28F120: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28F128: movss [0x0056C0C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0C0u, ctx.xmm[0].u32[0]);
	// 0x28F130: ret
	return;
}

void sub_28F140(X86Context& ctx, uint8_t* base) {
	// 0x28F140: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28F148: movss [0x0056C0E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0E8u, ctx.xmm[0].u32[0]);
	// 0x28F150: ret
	return;
}

void sub_28F160(X86Context& ctx, uint8_t* base) {
	// 0x28F160: movss xmm0, dword ptr [0x0056C0C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0C0u);
	// 0x28F168: movss [0x0056C14C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C14Cu, ctx.xmm[0].u32[0]);
	// 0x28F170: ret
	return;
}

void sub_28F180(X86Context& ctx, uint8_t* base) {
	// 0x28F180: movss xmm0, dword ptr [0x0056C130]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C130u);
	// 0x28F188: subss xmm0, [0x0056C0C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C0C0u);
	// 0x28F190: movss [0x0056C110], xmm0
	X86_MEM_WRITE_u32(base, 0x56C110u, ctx.xmm[0].u32[0]);
	// 0x28F198: ret
	return;
}

void sub_28F1A0(X86Context& ctx, uint8_t* base) {
	// 0x28F1A0: movss xmm0, dword ptr [0x0056C110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C110u);
	// 0x28F1A8: subss xmm0, [0x0056C0E8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C0E8u);
	// 0x28F1B0: movss [0x0056C108], xmm0
	X86_MEM_WRITE_u32(base, 0x56C108u, ctx.xmm[0].u32[0]);
	// 0x28F1B8: ret
	return;
}

void sub_28F1C0(X86Context& ctx, uint8_t* base) {
	// 0x28F1C0: movss xmm0, dword ptr [0x0056C138]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C138u);
	// 0x28F1C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28F1D0: movss [0x0056C0F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0F8u, ctx.xmm[0].u32[0]);
	// 0x28F1D8: ret
	return;
}

void sub_28F1E0(X86Context& ctx, uint8_t* base) {
	// 0x28F1E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28F1E8: movss [0x0056C0E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C0E4u, ctx.xmm[0].u32[0]);
	// 0x28F1F0: ret
	return;
}

void sub_28F200(X86Context& ctx, uint8_t* base) {
	// 0x28F200: movss xmm0, dword ptr [0x0056C0F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C0F8u);
	// 0x28F208: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28F210: movss [0x0056C128], xmm0
	X86_MEM_WRITE_u32(base, 0x56C128u, ctx.xmm[0].u32[0]);
	// 0x28F218: ret
	return;
}

void sub_28F220(X86Context& ctx, uint8_t* base) {
	// 0x28F220: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28F228: movss [0x0056C1AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1ACu, ctx.xmm[0].u32[0]);
	// 0x28F230: ret
	return;
}

void sub_28F240(X86Context& ctx, uint8_t* base) {
	// 0x28F240: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28F248: movss [0x0056C1C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1C8u, ctx.xmm[0].u32[0]);
	// 0x28F250: ret
	return;
}

void sub_28F260(X86Context& ctx, uint8_t* base) {
	// 0x28F260: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28F268: movss [0x0056C1A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1A0u, ctx.xmm[0].u32[0]);
	// 0x28F270: ret
	return;
}

void sub_28F280(X86Context& ctx, uint8_t* base) {
	// 0x28F280: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28F288: movss [0x0056C158], xmm0
	X86_MEM_WRITE_u32(base, 0x56C158u, ctx.xmm[0].u32[0]);
	// 0x28F290: ret
	return;
}

void sub_28F2A0(X86Context& ctx, uint8_t* base) {
	// 0x28F2A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28F2A8: movss [0x0056C1B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1B0u, ctx.xmm[0].u32[0]);
	// 0x28F2B0: ret
	return;
}

void sub_28F2C0(X86Context& ctx, uint8_t* base) {
	// 0x28F2C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28F2C8: movss [0x0056C174], xmm0
	X86_MEM_WRITE_u32(base, 0x56C174u, ctx.xmm[0].u32[0]);
	// 0x28F2D0: ret
	return;
}

void sub_28F2E0(X86Context& ctx, uint8_t* base) {
	// 0x28F2E0: movss xmm0, dword ptr [0x0056C1B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1B0u);
	// 0x28F2E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28F2F0: movss [0x0056C1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1E8u, ctx.xmm[0].u32[0]);
	// 0x28F2F8: ret
	return;
}

void sub_28F300(X86Context& ctx, uint8_t* base) {
	// 0x28F300: movss xmm0, dword ptr [0x0056C174]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C174u);
	// 0x28F308: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28F310: movss [0x0056C1D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1D0u, ctx.xmm[0].u32[0]);
	// 0x28F318: ret
	return;
}

void sub_28F320(X86Context& ctx, uint8_t* base) {
	// 0x28F320: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28F328: movss [0x0056C200], xmm0
	X86_MEM_WRITE_u32(base, 0x56C200u, ctx.xmm[0].u32[0]);
	// 0x28F330: ret
	return;
}

void sub_28F340(X86Context& ctx, uint8_t* base) {
	// 0x28F340: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28F348: movss [0x0056C1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1ECu, ctx.xmm[0].u32[0]);
	// 0x28F350: ret
	return;
}

void sub_28F360(X86Context& ctx, uint8_t* base) {
	// 0x28F360: movss xmm0, dword ptr [0x0056C1EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1ECu);
	// 0x28F368: movss [0x0056C1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1FCu, ctx.xmm[0].u32[0]);
	// 0x28F370: ret
	return;
}

void sub_28F380(X86Context& ctx, uint8_t* base) {
	// 0x28F380: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28F388: movss [0x0056C160], xmm0
	X86_MEM_WRITE_u32(base, 0x56C160u, ctx.xmm[0].u32[0]);
	// 0x28F390: ret
	return;
}

void sub_28F3A0(X86Context& ctx, uint8_t* base) {
	// 0x28F3A0: movss xmm0, dword ptr [0x0056C174]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C174u);
	// 0x28F3A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28F3B0: movss [0x0056C1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1F4u, ctx.xmm[0].u32[0]);
	// 0x28F3B8: ret
	return;
}

void sub_28F3C0(X86Context& ctx, uint8_t* base) {
	// 0x28F3C0: movss xmm0, dword ptr [0x0056C174]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C174u);
	// 0x28F3C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28F3D0: movss [0x0056C19C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C19Cu, ctx.xmm[0].u32[0]);
	// 0x28F3D8: ret
	return;
}

void sub_28F3E0(X86Context& ctx, uint8_t* base) {
	// 0x28F3E0: movss xmm0, dword ptr [0x0056C174]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C174u);
	// 0x28F3E8: subss xmm0, [0x0056C19C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C19Cu);
	// 0x28F3F0: movss [0x0056C17C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C17Cu, ctx.xmm[0].u32[0]);
	// 0x28F3F8: ret
	return;
}

void sub_28F400(X86Context& ctx, uint8_t* base) {
	// 0x28F400: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28F408: movss [0x0056C1C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1C4u, ctx.xmm[0].u32[0]);
	// 0x28F410: ret
	return;
}

void sub_28F420(X86Context& ctx, uint8_t* base) {
	// 0x28F420: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28F428: movss [0x0056C178], xmm0
	X86_MEM_WRITE_u32(base, 0x56C178u, ctx.xmm[0].u32[0]);
	// 0x28F430: ret
	return;
}

void sub_28F440(X86Context& ctx, uint8_t* base) {
	// 0x28F440: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28F448: movss [0x0056C188], xmm0
	X86_MEM_WRITE_u32(base, 0x56C188u, ctx.xmm[0].u32[0]);
	// 0x28F450: ret
	return;
}

void sub_28F460(X86Context& ctx, uint8_t* base) {
	// 0x28F460: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28F468: movss [0x0056C1DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1DCu, ctx.xmm[0].u32[0]);
	// 0x28F470: ret
	return;
}

void sub_28F480(X86Context& ctx, uint8_t* base) {
	// 0x28F480: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28F488: movss [0x0056C1C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1C0u, ctx.xmm[0].u32[0]);
	// 0x28F490: ret
	return;
}

void sub_28F4A0(X86Context& ctx, uint8_t* base) {
	// 0x28F4A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28F4A8: movss [0x0056C170], xmm0
	X86_MEM_WRITE_u32(base, 0x56C170u, ctx.xmm[0].u32[0]);
	// 0x28F4B0: ret
	return;
}

void sub_28F4C0(X86Context& ctx, uint8_t* base) {
	// 0x28F4C0: movss xmm0, dword ptr [0x0056C188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C188u);
	// 0x28F4C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28F4D0: movss [0x0056C164], xmm0
	X86_MEM_WRITE_u32(base, 0x56C164u, ctx.xmm[0].u32[0]);
	// 0x28F4D8: ret
	return;
}

void sub_28F4E0(X86Context& ctx, uint8_t* base) {
	// 0x28F4E0: movss xmm0, dword ptr [0x0056C1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1DCu);
	// 0x28F4E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28F4F0: movss [0x0056C1A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1A8u, ctx.xmm[0].u32[0]);
	// 0x28F4F8: ret
	return;
}

void sub_28F500(X86Context& ctx, uint8_t* base) {
	// 0x28F500: movss xmm0, dword ptr [0x0056C164]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C164u);
	// 0x28F508: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28F510: movss [0x0056C1B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1B8u, ctx.xmm[0].u32[0]);
	// 0x28F518: ret
	return;
}

void sub_28F520(X86Context& ctx, uint8_t* base) {
	// 0x28F520: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28F528: movss [0x0056C15C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C15Cu, ctx.xmm[0].u32[0]);
	// 0x28F530: ret
	return;
}

void sub_28F540(X86Context& ctx, uint8_t* base) {
	// 0x28F540: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28F548: movss [0x0056C18C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C18Cu, ctx.xmm[0].u32[0]);
	// 0x28F550: ret
	return;
}

void sub_28F560(X86Context& ctx, uint8_t* base) {
	// 0x28F560: movss xmm0, dword ptr [0x0056C188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C188u);
	// 0x28F568: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28F570: movss [0x0056C198], xmm0
	X86_MEM_WRITE_u32(base, 0x56C198u, ctx.xmm[0].u32[0]);
	// 0x28F578: ret
	return;
}

void sub_28F580(X86Context& ctx, uint8_t* base) {
	// 0x28F580: movss xmm0, dword ptr [0x0056C1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1DCu);
	// 0x28F588: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28F590: movss [0x0056C1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1E0u, ctx.xmm[0].u32[0]);
	// 0x28F598: ret
	return;
}

void sub_28F5A0(X86Context& ctx, uint8_t* base) {
	// 0x28F5A0: movss xmm0, dword ptr [0x0056C198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C198u);
	// 0x28F5A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F5B0: movss [0x0056C1CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1CCu, ctx.xmm[0].u32[0]);
	// 0x28F5B8: ret
	return;
}

void sub_28F5C0(X86Context& ctx, uint8_t* base) {
	// 0x28F5C0: movss xmm0, dword ptr [0x0056C1E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1E0u);
	// 0x28F5C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F5D0: movss [0x0056C1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1F0u, ctx.xmm[0].u32[0]);
	// 0x28F5D8: ret
	return;
}

void sub_28F5E0(X86Context& ctx, uint8_t* base) {
	// 0x28F5E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28F5E8: movss [0x0056C168], xmm0
	X86_MEM_WRITE_u32(base, 0x56C168u, ctx.xmm[0].u32[0]);
	// 0x28F5F0: ret
	return;
}

void sub_28F600(X86Context& ctx, uint8_t* base) {
	// 0x28F600: movss xmm0, dword ptr [0x0056C188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C188u);
	// 0x28F608: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F610: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28F618: movss [0x0056C1D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1D8u, ctx.xmm[0].u32[0]);
	// 0x28F620: ret
	return;
}

void sub_28F630(X86Context& ctx, uint8_t* base) {
	// 0x28F630: movss xmm0, dword ptr [0x0056C1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1DCu);
	// 0x28F638: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F640: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28F648: movss [0x0056C180], xmm0
	X86_MEM_WRITE_u32(base, 0x56C180u, ctx.xmm[0].u32[0]);
	// 0x28F650: ret
	return;
}

void sub_28F660(X86Context& ctx, uint8_t* base) {
	// 0x28F660: movss xmm0, dword ptr [0x0056C188]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C188u);
	// 0x28F668: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F670: movss [0x0056C184], xmm0
	X86_MEM_WRITE_u32(base, 0x56C184u, ctx.xmm[0].u32[0]);
	// 0x28F678: ret
	return;
}

void sub_28F680(X86Context& ctx, uint8_t* base) {
	// 0x28F680: movss xmm0, dword ptr [0x0056C1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1DCu);
	// 0x28F688: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28F690: movss [0x0056C1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1E4u, ctx.xmm[0].u32[0]);
	// 0x28F698: ret
	return;
}

void sub_28F6A0(X86Context& ctx, uint8_t* base) {
	// 0x28F6A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28F6A8: movss [0x0056C16C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C16Cu, ctx.xmm[0].u32[0]);
	// 0x28F6B0: ret
	return;
}

void sub_28F6C0(X86Context& ctx, uint8_t* base) {
	// 0x28F6C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28F6C8: movss [0x0056C194], xmm0
	X86_MEM_WRITE_u32(base, 0x56C194u, ctx.xmm[0].u32[0]);
	// 0x28F6D0: ret
	return;
}

void sub_28F6E0(X86Context& ctx, uint8_t* base) {
	// 0x28F6E0: movss xmm0, dword ptr [0x0056C16C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C16Cu);
	// 0x28F6E8: movss [0x0056C1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1F8u, ctx.xmm[0].u32[0]);
	// 0x28F6F0: ret
	return;
}

void sub_28F700(X86Context& ctx, uint8_t* base) {
	// 0x28F700: movss xmm0, dword ptr [0x0056C1DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1DCu);
	// 0x28F708: subss xmm0, [0x0056C16C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C16Cu);
	// 0x28F710: movss [0x0056C1BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1BCu, ctx.xmm[0].u32[0]);
	// 0x28F718: ret
	return;
}

void sub_28F720(X86Context& ctx, uint8_t* base) {
	// 0x28F720: movss xmm0, dword ptr [0x0056C1BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1BCu);
	// 0x28F728: subss xmm0, [0x0056C194]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C194u);
	// 0x28F730: movss [0x0056C1B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1B4u, ctx.xmm[0].u32[0]);
	// 0x28F738: ret
	return;
}

void sub_28F740(X86Context& ctx, uint8_t* base) {
	// 0x28F740: movss xmm0, dword ptr [0x0056C1E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1E4u);
	// 0x28F748: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x28F750: movss [0x0056C1A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1A4u, ctx.xmm[0].u32[0]);
	// 0x28F758: ret
	return;
}

void sub_28F760(X86Context& ctx, uint8_t* base) {
	// 0x28F760: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x28F768: movss [0x0056C190], xmm0
	X86_MEM_WRITE_u32(base, 0x56C190u, ctx.xmm[0].u32[0]);
	// 0x28F770: ret
	return;
}

void sub_28F780(X86Context& ctx, uint8_t* base) {
	// 0x28F780: movss xmm0, dword ptr [0x0056C1A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C1A4u);
	// 0x28F788: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x28F790: movss [0x0056C1D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C1D4u, ctx.xmm[0].u32[0]);
	// 0x28F798: ret
	return;
}

void sub_28F7A0(X86Context& ctx, uint8_t* base) {
	// 0x28F7A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x28F7A8: movss [0x0056C260], xmm0
	X86_MEM_WRITE_u32(base, 0x56C260u, ctx.xmm[0].u32[0]);
	// 0x28F7B0: ret
	return;
}

void sub_28F7C0(X86Context& ctx, uint8_t* base) {
	// 0x28F7C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x28F7C8: movss [0x0056C27C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C27Cu, ctx.xmm[0].u32[0]);
	// 0x28F7D0: ret
	return;
}

void sub_28F7E0(X86Context& ctx, uint8_t* base) {
	// 0x28F7E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x28F7E8: movss [0x0056C250], xmm0
	X86_MEM_WRITE_u32(base, 0x56C250u, ctx.xmm[0].u32[0]);
	// 0x28F7F0: ret
	return;
}

void sub_28F800(X86Context& ctx, uint8_t* base) {
	// 0x28F800: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x28F808: movss [0x0056C204], xmm0
	X86_MEM_WRITE_u32(base, 0x56C204u, ctx.xmm[0].u32[0]);
	// 0x28F810: ret
	return;
}

void sub_28F820(X86Context& ctx, uint8_t* base) {
	// 0x28F820: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28F828: movss [0x0056C264], xmm0
	X86_MEM_WRITE_u32(base, 0x56C264u, ctx.xmm[0].u32[0]);
	// 0x28F830: ret
	return;
}

void sub_28F840(X86Context& ctx, uint8_t* base) {
	// 0x28F840: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28F848: movss [0x0056C220], xmm0
	X86_MEM_WRITE_u32(base, 0x56C220u, ctx.xmm[0].u32[0]);
	// 0x28F850: ret
	return;
}

void sub_28F860(X86Context& ctx, uint8_t* base) {
	// 0x28F860: movss xmm0, dword ptr [0x0056C264]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C264u);
	// 0x28F868: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28F870: movss [0x0056C29C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C29Cu, ctx.xmm[0].u32[0]);
	// 0x28F878: ret
	return;
}

void sub_28F880(X86Context& ctx, uint8_t* base) {
	// 0x28F880: movss xmm0, dword ptr [0x0056C220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C220u);
	// 0x28F888: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28F890: movss [0x0056C284], xmm0
	X86_MEM_WRITE_u32(base, 0x56C284u, ctx.xmm[0].u32[0]);
	// 0x28F898: ret
	return;
}

void sub_28F8A0(X86Context& ctx, uint8_t* base) {
	// 0x28F8A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28F8A8: movss [0x0056C2B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2B4u, ctx.xmm[0].u32[0]);
	// 0x28F8B0: ret
	return;
}

void sub_28F8C0(X86Context& ctx, uint8_t* base) {
	// 0x28F8C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x28F8C8: movss [0x0056C2A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2A0u, ctx.xmm[0].u32[0]);
	// 0x28F8D0: ret
	return;
}

void sub_28F8E0(X86Context& ctx, uint8_t* base) {
	// 0x28F8E0: movss xmm0, dword ptr [0x0056C2A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C2A0u);
	// 0x28F8E8: movss [0x0056C2B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2B0u, ctx.xmm[0].u32[0]);
	// 0x28F8F0: ret
	return;
}

void sub_28F900(X86Context& ctx, uint8_t* base) {
	// 0x28F900: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x28F908: movss [0x0056C20C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C20Cu, ctx.xmm[0].u32[0]);
	// 0x28F910: ret
	return;
}

void sub_28F920(X86Context& ctx, uint8_t* base) {
	// 0x28F920: movss xmm0, dword ptr [0x0056C220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C220u);
	// 0x28F928: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x28F930: movss [0x0056C2A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2A8u, ctx.xmm[0].u32[0]);
	// 0x28F938: ret
	return;
}

void sub_28F940(X86Context& ctx, uint8_t* base) {
	// 0x28F940: movss xmm0, dword ptr [0x0056C220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C220u);
	// 0x28F948: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x28F950: movss [0x0056C24C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C24Cu, ctx.xmm[0].u32[0]);
	// 0x28F958: ret
	return;
}

void sub_28F960(X86Context& ctx, uint8_t* base) {
	// 0x28F960: movss xmm0, dword ptr [0x0056C220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C220u);
	// 0x28F968: subss xmm0, [0x0056C24C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56C24Cu);
	// 0x28F970: movss [0x0056C228], xmm0
	X86_MEM_WRITE_u32(base, 0x56C228u, ctx.xmm[0].u32[0]);
	// 0x28F978: ret
	return;
}

void sub_28F980(X86Context& ctx, uint8_t* base) {
	// 0x28F980: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x28F988: movss [0x0056C278], xmm0
	X86_MEM_WRITE_u32(base, 0x56C278u, ctx.xmm[0].u32[0]);
	// 0x28F990: ret
	return;
}

void sub_28F9A0(X86Context& ctx, uint8_t* base) {
	// 0x28F9A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x28F9A8: movss [0x0056C224], xmm0
	X86_MEM_WRITE_u32(base, 0x56C224u, ctx.xmm[0].u32[0]);
	// 0x28F9B0: ret
	return;
}

void sub_28F9C0(X86Context& ctx, uint8_t* base) {
	// 0x28F9C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x28F9C8: movss [0x0056C238], xmm0
	X86_MEM_WRITE_u32(base, 0x56C238u, ctx.xmm[0].u32[0]);
	// 0x28F9D0: ret
	return;
}

void sub_28F9E0(X86Context& ctx, uint8_t* base) {
	// 0x28F9E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x28F9E8: movss [0x0056C290], xmm0
	X86_MEM_WRITE_u32(base, 0x56C290u, ctx.xmm[0].u32[0]);
	// 0x28F9F0: ret
	return;
}

void sub_28FA00(X86Context& ctx, uint8_t* base) {
	// 0x28FA00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x28FA08: movss [0x0056C274], xmm0
	X86_MEM_WRITE_u32(base, 0x56C274u, ctx.xmm[0].u32[0]);
	// 0x28FA10: ret
	return;
}

void sub_28FA20(X86Context& ctx, uint8_t* base) {
	// 0x28FA20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x28FA28: movss [0x0056C21C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C21Cu, ctx.xmm[0].u32[0]);
	// 0x28FA30: ret
	return;
}

void sub_28FA40(X86Context& ctx, uint8_t* base) {
	// 0x28FA40: movss xmm0, dword ptr [0x0056C238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C238u);
	// 0x28FA48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28FA50: movss [0x0056C210], xmm0
	X86_MEM_WRITE_u32(base, 0x56C210u, ctx.xmm[0].u32[0]);
	// 0x28FA58: ret
	return;
}

void sub_28FA60(X86Context& ctx, uint8_t* base) {
	// 0x28FA60: movss xmm0, dword ptr [0x0056C290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C290u);
	// 0x28FA68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x28FA70: movss [0x0056C25C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C25Cu, ctx.xmm[0].u32[0]);
	// 0x28FA78: ret
	return;
}

void sub_28FA80(X86Context& ctx, uint8_t* base) {
	// 0x28FA80: movss xmm0, dword ptr [0x0056C210]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C210u);
	// 0x28FA88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x28FA90: movss [0x0056C26C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C26Cu, ctx.xmm[0].u32[0]);
	// 0x28FA98: ret
	return;
}

void sub_28FAA0(X86Context& ctx, uint8_t* base) {
	// 0x28FAA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28FAA8: movss [0x0056C208], xmm0
	X86_MEM_WRITE_u32(base, 0x56C208u, ctx.xmm[0].u32[0]);
	// 0x28FAB0: ret
	return;
}

void sub_28FAC0(X86Context& ctx, uint8_t* base) {
	// 0x28FAC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x28FAC8: movss [0x0056C23C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C23Cu, ctx.xmm[0].u32[0]);
	// 0x28FAD0: ret
	return;
}

void sub_28FAE0(X86Context& ctx, uint8_t* base) {
	// 0x28FAE0: movss xmm0, dword ptr [0x0056C238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C238u);
	// 0x28FAE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28FAF0: movss [0x0056C248], xmm0
	X86_MEM_WRITE_u32(base, 0x56C248u, ctx.xmm[0].u32[0]);
	// 0x28FAF8: ret
	return;
}

void sub_28FB00(X86Context& ctx, uint8_t* base) {
	// 0x28FB00: movss xmm0, dword ptr [0x0056C290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C290u);
	// 0x28FB08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x28FB10: movss [0x0056C294], xmm0
	X86_MEM_WRITE_u32(base, 0x56C294u, ctx.xmm[0].u32[0]);
	// 0x28FB18: ret
	return;
}

void sub_28FB20(X86Context& ctx, uint8_t* base) {
	// 0x28FB20: movss xmm0, dword ptr [0x0056C248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C248u);
	// 0x28FB28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28FB30: movss [0x0056C280], xmm0
	X86_MEM_WRITE_u32(base, 0x56C280u, ctx.xmm[0].u32[0]);
	// 0x28FB38: ret
	return;
}

void sub_28FB40(X86Context& ctx, uint8_t* base) {
	// 0x28FB40: movss xmm0, dword ptr [0x0056C294]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C294u);
	// 0x28FB48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28FB50: movss [0x0056C2A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2A4u, ctx.xmm[0].u32[0]);
	// 0x28FB58: ret
	return;
}

void sub_28FB60(X86Context& ctx, uint8_t* base) {
	// 0x28FB60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x28FB68: movss [0x0056C214], xmm0
	X86_MEM_WRITE_u32(base, 0x56C214u, ctx.xmm[0].u32[0]);
	// 0x28FB70: ret
	return;
}

void sub_28FB80(X86Context& ctx, uint8_t* base) {
	// 0x28FB80: movss xmm0, dword ptr [0x0056C238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C238u);
	// 0x28FB88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28FB90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x28FB98: movss [0x0056C28C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C28Cu, ctx.xmm[0].u32[0]);
	// 0x28FBA0: ret
	return;
}

void sub_28FBB0(X86Context& ctx, uint8_t* base) {
	// 0x28FBB0: movss xmm0, dword ptr [0x0056C290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C290u);
	// 0x28FBB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28FBC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x28FBC8: movss [0x0056C22C], xmm0
	X86_MEM_WRITE_u32(base, 0x56C22Cu, ctx.xmm[0].u32[0]);
	// 0x28FBD0: ret
	return;
}

void sub_28FBE0(X86Context& ctx, uint8_t* base) {
	// 0x28FBE0: movss xmm0, dword ptr [0x0056C238]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C238u);
	// 0x28FBE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28FBF0: movss [0x0056C230], xmm0
	X86_MEM_WRITE_u32(base, 0x56C230u, ctx.xmm[0].u32[0]);
	// 0x28FBF8: ret
	return;
}

void sub_28FC00(X86Context& ctx, uint8_t* base) {
	// 0x28FC00: movss xmm0, dword ptr [0x0056C290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C290u);
	// 0x28FC08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x28FC10: movss [0x0056C298], xmm0
	X86_MEM_WRITE_u32(base, 0x56C298u, ctx.xmm[0].u32[0]);
	// 0x28FC18: ret
	return;
}

void sub_28FC20(X86Context& ctx, uint8_t* base) {
	// 0x28FC20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x28FC28: movss [0x0056C218], xmm0
	X86_MEM_WRITE_u32(base, 0x56C218u, ctx.xmm[0].u32[0]);
	// 0x28FC30: ret
	return;
}

void sub_28FC40(X86Context& ctx, uint8_t* base) {
	// 0x28FC40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x28FC48: movss [0x0056C244], xmm0
	X86_MEM_WRITE_u32(base, 0x56C244u, ctx.xmm[0].u32[0]);
	// 0x28FC50: ret
	return;
}

void sub_28FC60(X86Context& ctx, uint8_t* base) {
	// 0x28FC60: movss xmm0, dword ptr [0x0056C218]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56C218u);
	// 0x28FC68: movss [0x0056C2AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56C2ACu, ctx.xmm[0].u32[0]);
	// 0x28FC70: ret
	return;
}

