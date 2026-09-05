#include "x86_recomp_shared.h"

void sub_281750(X86Context& ctx, uint8_t* base) {
	// 0x281750: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x281758: movss [0x0056A624], xmm0
	X86_MEM_WRITE_u32(base, 0x56A624u, ctx.xmm[0].u32[0]);
	// 0x281760: ret
	return;
}

void sub_281770(X86Context& ctx, uint8_t* base) {
	// 0x281770: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x281778: movss [0x0056A64C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A64Cu, ctx.xmm[0].u32[0]);
	// 0x281780: ret
	return;
}

void sub_281790(X86Context& ctx, uint8_t* base) {
	// 0x281790: movss xmm0, dword ptr [0x0056A624]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A624u);
	// 0x281798: movss [0x0056A6B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6B0u, ctx.xmm[0].u32[0]);
	// 0x2817A0: ret
	return;
}

void sub_2817B0(X86Context& ctx, uint8_t* base) {
	// 0x2817B0: movss xmm0, dword ptr [0x0056A694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A694u);
	// 0x2817B8: subss xmm0, [0x0056A624]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A624u);
	// 0x2817C0: movss [0x0056A674], xmm0
	X86_MEM_WRITE_u32(base, 0x56A674u, ctx.xmm[0].u32[0]);
	// 0x2817C8: ret
	return;
}

void sub_2817D0(X86Context& ctx, uint8_t* base) {
	// 0x2817D0: movss xmm0, dword ptr [0x0056A674]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A674u);
	// 0x2817D8: subss xmm0, [0x0056A64C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A64Cu);
	// 0x2817E0: movss [0x0056A66C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A66Cu, ctx.xmm[0].u32[0]);
	// 0x2817E8: ret
	return;
}

void sub_2817F0(X86Context& ctx, uint8_t* base) {
	// 0x2817F0: movss xmm0, dword ptr [0x0056A69C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A69Cu);
	// 0x2817F8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x281800: movss [0x0056A65C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A65Cu, ctx.xmm[0].u32[0]);
	// 0x281808: ret
	return;
}

void sub_281810(X86Context& ctx, uint8_t* base) {
	// 0x281810: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x281818: movss [0x0056A648], xmm0
	X86_MEM_WRITE_u32(base, 0x56A648u, ctx.xmm[0].u32[0]);
	// 0x281820: ret
	return;
}

void sub_281830(X86Context& ctx, uint8_t* base) {
	// 0x281830: movss xmm0, dword ptr [0x0056A65C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A65Cu);
	// 0x281838: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x281840: movss [0x0056A68C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A68Cu, ctx.xmm[0].u32[0]);
	// 0x281848: ret
	return;
}

void sub_281850(X86Context& ctx, uint8_t* base) {
	// 0x281850: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x281858: movss [0x0056A710], xmm0
	X86_MEM_WRITE_u32(base, 0x56A710u, ctx.xmm[0].u32[0]);
	// 0x281860: ret
	return;
}

void sub_281870(X86Context& ctx, uint8_t* base) {
	// 0x281870: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x281878: movss [0x0056A72C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A72Cu, ctx.xmm[0].u32[0]);
	// 0x281880: ret
	return;
}

void sub_281890(X86Context& ctx, uint8_t* base) {
	// 0x281890: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x281898: movss [0x0056A704], xmm0
	X86_MEM_WRITE_u32(base, 0x56A704u, ctx.xmm[0].u32[0]);
	// 0x2818A0: ret
	return;
}

void sub_2818B0(X86Context& ctx, uint8_t* base) {
	// 0x2818B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2818B8: movss [0x0056A6BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6BCu, ctx.xmm[0].u32[0]);
	// 0x2818C0: ret
	return;
}

void sub_2818D0(X86Context& ctx, uint8_t* base) {
	// 0x2818D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2818D8: movss [0x0056A714], xmm0
	X86_MEM_WRITE_u32(base, 0x56A714u, ctx.xmm[0].u32[0]);
	// 0x2818E0: ret
	return;
}

void sub_2818F0(X86Context& ctx, uint8_t* base) {
	// 0x2818F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2818F8: movss [0x0056A6D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6D8u, ctx.xmm[0].u32[0]);
	// 0x281900: ret
	return;
}

void sub_281910(X86Context& ctx, uint8_t* base) {
	// 0x281910: movss xmm0, dword ptr [0x0056A714]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A714u);
	// 0x281918: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281920: movss [0x0056A74C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A74Cu, ctx.xmm[0].u32[0]);
	// 0x281928: ret
	return;
}

void sub_281930(X86Context& ctx, uint8_t* base) {
	// 0x281930: movss xmm0, dword ptr [0x0056A6D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6D8u);
	// 0x281938: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x281940: movss [0x0056A734], xmm0
	X86_MEM_WRITE_u32(base, 0x56A734u, ctx.xmm[0].u32[0]);
	// 0x281948: ret
	return;
}

void sub_281950(X86Context& ctx, uint8_t* base) {
	// 0x281950: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x281958: movss [0x0056A764], xmm0
	X86_MEM_WRITE_u32(base, 0x56A764u, ctx.xmm[0].u32[0]);
	// 0x281960: ret
	return;
}

void sub_281970(X86Context& ctx, uint8_t* base) {
	// 0x281970: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x281978: movss [0x0056A750], xmm0
	X86_MEM_WRITE_u32(base, 0x56A750u, ctx.xmm[0].u32[0]);
	// 0x281980: ret
	return;
}

void sub_281990(X86Context& ctx, uint8_t* base) {
	// 0x281990: movss xmm0, dword ptr [0x0056A750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A750u);
	// 0x281998: movss [0x0056A760], xmm0
	X86_MEM_WRITE_u32(base, 0x56A760u, ctx.xmm[0].u32[0]);
	// 0x2819A0: ret
	return;
}

void sub_2819B0(X86Context& ctx, uint8_t* base) {
	// 0x2819B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2819B8: movss [0x0056A6C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6C4u, ctx.xmm[0].u32[0]);
	// 0x2819C0: ret
	return;
}

void sub_2819D0(X86Context& ctx, uint8_t* base) {
	// 0x2819D0: movss xmm0, dword ptr [0x0056A6D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6D8u);
	// 0x2819D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2819E0: movss [0x0056A758], xmm0
	X86_MEM_WRITE_u32(base, 0x56A758u, ctx.xmm[0].u32[0]);
	// 0x2819E8: ret
	return;
}

void sub_2819F0(X86Context& ctx, uint8_t* base) {
	// 0x2819F0: movss xmm0, dword ptr [0x0056A6D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6D8u);
	// 0x2819F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x281A00: movss [0x0056A700], xmm0
	X86_MEM_WRITE_u32(base, 0x56A700u, ctx.xmm[0].u32[0]);
	// 0x281A08: ret
	return;
}

void sub_281A10(X86Context& ctx, uint8_t* base) {
	// 0x281A10: movss xmm0, dword ptr [0x0056A6D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6D8u);
	// 0x281A18: subss xmm0, [0x0056A700]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A700u);
	// 0x281A20: movss [0x0056A6E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6E0u, ctx.xmm[0].u32[0]);
	// 0x281A28: ret
	return;
}

void sub_281A30(X86Context& ctx, uint8_t* base) {
	// 0x281A30: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x281A38: movss [0x0056A728], xmm0
	X86_MEM_WRITE_u32(base, 0x56A728u, ctx.xmm[0].u32[0]);
	// 0x281A40: ret
	return;
}

void sub_281A50(X86Context& ctx, uint8_t* base) {
	// 0x281A50: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x281A58: movss [0x0056A6DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6DCu, ctx.xmm[0].u32[0]);
	// 0x281A60: ret
	return;
}

void sub_281A70(X86Context& ctx, uint8_t* base) {
	// 0x281A70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x281A78: movss [0x0056A6EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6ECu, ctx.xmm[0].u32[0]);
	// 0x281A80: ret
	return;
}

void sub_281A90(X86Context& ctx, uint8_t* base) {
	// 0x281A90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x281A98: movss [0x0056A740], xmm0
	X86_MEM_WRITE_u32(base, 0x56A740u, ctx.xmm[0].u32[0]);
	// 0x281AA0: ret
	return;
}

void sub_281AB0(X86Context& ctx, uint8_t* base) {
	// 0x281AB0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x281AB8: movss [0x0056A724], xmm0
	X86_MEM_WRITE_u32(base, 0x56A724u, ctx.xmm[0].u32[0]);
	// 0x281AC0: ret
	return;
}

void sub_281AD0(X86Context& ctx, uint8_t* base) {
	// 0x281AD0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x281AD8: movss [0x0056A6D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6D4u, ctx.xmm[0].u32[0]);
	// 0x281AE0: ret
	return;
}

void sub_281AF0(X86Context& ctx, uint8_t* base) {
	// 0x281AF0: movss xmm0, dword ptr [0x0056A6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6ECu);
	// 0x281AF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281B00: movss [0x0056A6C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6C8u, ctx.xmm[0].u32[0]);
	// 0x281B08: ret
	return;
}

void sub_281B10(X86Context& ctx, uint8_t* base) {
	// 0x281B10: movss xmm0, dword ptr [0x0056A740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A740u);
	// 0x281B18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x281B20: movss [0x0056A70C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A70Cu, ctx.xmm[0].u32[0]);
	// 0x281B28: ret
	return;
}

void sub_281B30(X86Context& ctx, uint8_t* base) {
	// 0x281B30: movss xmm0, dword ptr [0x0056A6C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6C8u);
	// 0x281B38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281B40: movss [0x0056A71C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A71Cu, ctx.xmm[0].u32[0]);
	// 0x281B48: ret
	return;
}

void sub_281B50(X86Context& ctx, uint8_t* base) {
	// 0x281B50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x281B58: movss [0x0056A6C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6C0u, ctx.xmm[0].u32[0]);
	// 0x281B60: ret
	return;
}

void sub_281B70(X86Context& ctx, uint8_t* base) {
	// 0x281B70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x281B78: movss [0x0056A6F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6F0u, ctx.xmm[0].u32[0]);
	// 0x281B80: ret
	return;
}

void sub_281B90(X86Context& ctx, uint8_t* base) {
	// 0x281B90: movss xmm0, dword ptr [0x0056A6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6ECu);
	// 0x281B98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x281BA0: movss [0x0056A6FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6FCu, ctx.xmm[0].u32[0]);
	// 0x281BA8: ret
	return;
}

void sub_281BB0(X86Context& ctx, uint8_t* base) {
	// 0x281BB0: movss xmm0, dword ptr [0x0056A740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A740u);
	// 0x281BB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x281BC0: movss [0x0056A744], xmm0
	X86_MEM_WRITE_u32(base, 0x56A744u, ctx.xmm[0].u32[0]);
	// 0x281BC8: ret
	return;
}

void sub_281BD0(X86Context& ctx, uint8_t* base) {
	// 0x281BD0: movss xmm0, dword ptr [0x0056A6FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6FCu);
	// 0x281BD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281BE0: movss [0x0056A730], xmm0
	X86_MEM_WRITE_u32(base, 0x56A730u, ctx.xmm[0].u32[0]);
	// 0x281BE8: ret
	return;
}

void sub_281BF0(X86Context& ctx, uint8_t* base) {
	// 0x281BF0: movss xmm0, dword ptr [0x0056A744]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A744u);
	// 0x281BF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281C00: movss [0x0056A754], xmm0
	X86_MEM_WRITE_u32(base, 0x56A754u, ctx.xmm[0].u32[0]);
	// 0x281C08: ret
	return;
}

void sub_281C10(X86Context& ctx, uint8_t* base) {
	// 0x281C10: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x281C18: movss [0x0056A6CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6CCu, ctx.xmm[0].u32[0]);
	// 0x281C20: ret
	return;
}

void sub_281C30(X86Context& ctx, uint8_t* base) {
	// 0x281C30: movss xmm0, dword ptr [0x0056A6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6ECu);
	// 0x281C38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281C40: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x281C48: movss [0x0056A73C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A73Cu, ctx.xmm[0].u32[0]);
	// 0x281C50: ret
	return;
}

void sub_281C60(X86Context& ctx, uint8_t* base) {
	// 0x281C60: movss xmm0, dword ptr [0x0056A740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A740u);
	// 0x281C68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281C70: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x281C78: movss [0x0056A6E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6E4u, ctx.xmm[0].u32[0]);
	// 0x281C80: ret
	return;
}

void sub_281C90(X86Context& ctx, uint8_t* base) {
	// 0x281C90: movss xmm0, dword ptr [0x0056A6EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6ECu);
	// 0x281C98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281CA0: movss [0x0056A6E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6E8u, ctx.xmm[0].u32[0]);
	// 0x281CA8: ret
	return;
}

void sub_281CB0(X86Context& ctx, uint8_t* base) {
	// 0x281CB0: movss xmm0, dword ptr [0x0056A740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A740u);
	// 0x281CB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x281CC0: movss [0x0056A748], xmm0
	X86_MEM_WRITE_u32(base, 0x56A748u, ctx.xmm[0].u32[0]);
	// 0x281CC8: ret
	return;
}

void sub_281CD0(X86Context& ctx, uint8_t* base) {
	// 0x281CD0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x281CD8: movss [0x0056A6D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6D0u, ctx.xmm[0].u32[0]);
	// 0x281CE0: ret
	return;
}

void sub_281CF0(X86Context& ctx, uint8_t* base) {
	// 0x281CF0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x281CF8: movss [0x0056A6F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6F8u, ctx.xmm[0].u32[0]);
	// 0x281D00: ret
	return;
}

void sub_281D10(X86Context& ctx, uint8_t* base) {
	// 0x281D10: movss xmm0, dword ptr [0x0056A6D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A6D0u);
	// 0x281D18: movss [0x0056A75C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A75Cu, ctx.xmm[0].u32[0]);
	// 0x281D20: ret
	return;
}

void sub_281D30(X86Context& ctx, uint8_t* base) {
	// 0x281D30: movss xmm0, dword ptr [0x0056A740]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A740u);
	// 0x281D38: subss xmm0, [0x0056A6D0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A6D0u);
	// 0x281D40: movss [0x0056A720], xmm0
	X86_MEM_WRITE_u32(base, 0x56A720u, ctx.xmm[0].u32[0]);
	// 0x281D48: ret
	return;
}

void sub_281D50(X86Context& ctx, uint8_t* base) {
	// 0x281D50: movss xmm0, dword ptr [0x0056A720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A720u);
	// 0x281D58: subss xmm0, [0x0056A6F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A6F8u);
	// 0x281D60: movss [0x0056A718], xmm0
	X86_MEM_WRITE_u32(base, 0x56A718u, ctx.xmm[0].u32[0]);
	// 0x281D68: ret
	return;
}

void sub_281D70(X86Context& ctx, uint8_t* base) {
	// 0x281D70: movss xmm0, dword ptr [0x0056A748]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A748u);
	// 0x281D78: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x281D80: movss [0x0056A708], xmm0
	X86_MEM_WRITE_u32(base, 0x56A708u, ctx.xmm[0].u32[0]);
	// 0x281D88: ret
	return;
}

void sub_281D90(X86Context& ctx, uint8_t* base) {
	// 0x281D90: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x281D98: movss [0x0056A6F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A6F4u, ctx.xmm[0].u32[0]);
	// 0x281DA0: ret
	return;
}

void sub_281DB0(X86Context& ctx, uint8_t* base) {
	// 0x281DB0: movss xmm0, dword ptr [0x0056A708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A708u);
	// 0x281DB8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x281DC0: movss [0x0056A738], xmm0
	X86_MEM_WRITE_u32(base, 0x56A738u, ctx.xmm[0].u32[0]);
	// 0x281DC8: ret
	return;
}

void sub_281DD0(X86Context& ctx, uint8_t* base) {
	// 0x281DD0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x281DD8: movss [0x0056A7BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7BCu, ctx.xmm[0].u32[0]);
	// 0x281DE0: ret
	return;
}

void sub_281DF0(X86Context& ctx, uint8_t* base) {
	// 0x281DF0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x281DF8: movss [0x0056A7D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7D8u, ctx.xmm[0].u32[0]);
	// 0x281E00: ret
	return;
}

void sub_281E10(X86Context& ctx, uint8_t* base) {
	// 0x281E10: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x281E18: movss [0x0056A7B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7B0u, ctx.xmm[0].u32[0]);
	// 0x281E20: ret
	return;
}

void sub_281E30(X86Context& ctx, uint8_t* base) {
	// 0x281E30: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x281E38: movss [0x0056A768], xmm0
	X86_MEM_WRITE_u32(base, 0x56A768u, ctx.xmm[0].u32[0]);
	// 0x281E40: ret
	return;
}

void sub_281E50(X86Context& ctx, uint8_t* base) {
	// 0x281E50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x281E58: movss [0x0056A7C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7C0u, ctx.xmm[0].u32[0]);
	// 0x281E60: ret
	return;
}

void sub_281E70(X86Context& ctx, uint8_t* base) {
	// 0x281E70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x281E78: movss [0x0056A784], xmm0
	X86_MEM_WRITE_u32(base, 0x56A784u, ctx.xmm[0].u32[0]);
	// 0x281E80: ret
	return;
}

void sub_281E90(X86Context& ctx, uint8_t* base) {
	// 0x281E90: movss xmm0, dword ptr [0x0056A7C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7C0u);
	// 0x281E98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x281EA0: movss [0x0056A7F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7F8u, ctx.xmm[0].u32[0]);
	// 0x281EA8: ret
	return;
}

void sub_281EB0(X86Context& ctx, uint8_t* base) {
	// 0x281EB0: movss xmm0, dword ptr [0x0056A784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A784u);
	// 0x281EB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x281EC0: movss [0x0056A7E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7E0u, ctx.xmm[0].u32[0]);
	// 0x281EC8: ret
	return;
}

void sub_281ED0(X86Context& ctx, uint8_t* base) {
	// 0x281ED0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x281ED8: movss [0x0056A810], xmm0
	X86_MEM_WRITE_u32(base, 0x56A810u, ctx.xmm[0].u32[0]);
	// 0x281EE0: ret
	return;
}

void sub_281EF0(X86Context& ctx, uint8_t* base) {
	// 0x281EF0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x281EF8: movss [0x0056A7FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7FCu, ctx.xmm[0].u32[0]);
	// 0x281F00: ret
	return;
}

void sub_281F10(X86Context& ctx, uint8_t* base) {
	// 0x281F10: movss xmm0, dword ptr [0x0056A7FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7FCu);
	// 0x281F18: movss [0x0056A80C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A80Cu, ctx.xmm[0].u32[0]);
	// 0x281F20: ret
	return;
}

void sub_281F30(X86Context& ctx, uint8_t* base) {
	// 0x281F30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x281F38: movss [0x0056A770], xmm0
	X86_MEM_WRITE_u32(base, 0x56A770u, ctx.xmm[0].u32[0]);
	// 0x281F40: ret
	return;
}

void sub_281F50(X86Context& ctx, uint8_t* base) {
	// 0x281F50: movss xmm0, dword ptr [0x0056A784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A784u);
	// 0x281F58: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x281F60: movss [0x0056A804], xmm0
	X86_MEM_WRITE_u32(base, 0x56A804u, ctx.xmm[0].u32[0]);
	// 0x281F68: ret
	return;
}

void sub_281F70(X86Context& ctx, uint8_t* base) {
	// 0x281F70: movss xmm0, dword ptr [0x0056A784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A784u);
	// 0x281F78: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x281F80: movss [0x0056A7AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7ACu, ctx.xmm[0].u32[0]);
	// 0x281F88: ret
	return;
}

void sub_281F90(X86Context& ctx, uint8_t* base) {
	// 0x281F90: movss xmm0, dword ptr [0x0056A784]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A784u);
	// 0x281F98: subss xmm0, [0x0056A7AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A7ACu);
	// 0x281FA0: movss [0x0056A78C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A78Cu, ctx.xmm[0].u32[0]);
	// 0x281FA8: ret
	return;
}

void sub_281FB0(X86Context& ctx, uint8_t* base) {
	// 0x281FB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x281FB8: movss [0x0056A7D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7D4u, ctx.xmm[0].u32[0]);
	// 0x281FC0: ret
	return;
}

void sub_281FD0(X86Context& ctx, uint8_t* base) {
	// 0x281FD0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x281FD8: movss [0x0056A788], xmm0
	X86_MEM_WRITE_u32(base, 0x56A788u, ctx.xmm[0].u32[0]);
	// 0x281FE0: ret
	return;
}

void sub_281FF0(X86Context& ctx, uint8_t* base) {
	// 0x281FF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x281FF8: movss [0x0056A798], xmm0
	X86_MEM_WRITE_u32(base, 0x56A798u, ctx.xmm[0].u32[0]);
	// 0x282000: ret
	return;
}

void sub_282010(X86Context& ctx, uint8_t* base) {
	// 0x282010: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x282018: movss [0x0056A7EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7ECu, ctx.xmm[0].u32[0]);
	// 0x282020: ret
	return;
}

void sub_282030(X86Context& ctx, uint8_t* base) {
	// 0x282030: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x282038: movss [0x0056A7D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7D0u, ctx.xmm[0].u32[0]);
	// 0x282040: ret
	return;
}

void sub_282050(X86Context& ctx, uint8_t* base) {
	// 0x282050: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x282058: movss [0x0056A780], xmm0
	X86_MEM_WRITE_u32(base, 0x56A780u, ctx.xmm[0].u32[0]);
	// 0x282060: ret
	return;
}

void sub_282070(X86Context& ctx, uint8_t* base) {
	// 0x282070: movss xmm0, dword ptr [0x0056A798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A798u);
	// 0x282078: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282080: movss [0x0056A774], xmm0
	X86_MEM_WRITE_u32(base, 0x56A774u, ctx.xmm[0].u32[0]);
	// 0x282088: ret
	return;
}

void sub_282090(X86Context& ctx, uint8_t* base) {
	// 0x282090: movss xmm0, dword ptr [0x0056A7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7ECu);
	// 0x282098: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2820A0: movss [0x0056A7B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7B8u, ctx.xmm[0].u32[0]);
	// 0x2820A8: ret
	return;
}

void sub_2820B0(X86Context& ctx, uint8_t* base) {
	// 0x2820B0: movss xmm0, dword ptr [0x0056A774]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A774u);
	// 0x2820B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2820C0: movss [0x0056A7C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7C8u, ctx.xmm[0].u32[0]);
	// 0x2820C8: ret
	return;
}

void sub_2820D0(X86Context& ctx, uint8_t* base) {
	// 0x2820D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2820D8: movss [0x0056A76C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A76Cu, ctx.xmm[0].u32[0]);
	// 0x2820E0: ret
	return;
}

void sub_2820F0(X86Context& ctx, uint8_t* base) {
	// 0x2820F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2820F8: movss [0x0056A79C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A79Cu, ctx.xmm[0].u32[0]);
	// 0x282100: ret
	return;
}

void sub_282110(X86Context& ctx, uint8_t* base) {
	// 0x282110: movss xmm0, dword ptr [0x0056A798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A798u);
	// 0x282118: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x282120: movss [0x0056A7A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7A8u, ctx.xmm[0].u32[0]);
	// 0x282128: ret
	return;
}

void sub_282130(X86Context& ctx, uint8_t* base) {
	// 0x282130: movss xmm0, dword ptr [0x0056A7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7ECu);
	// 0x282138: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x282140: movss [0x0056A7F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7F0u, ctx.xmm[0].u32[0]);
	// 0x282148: ret
	return;
}

void sub_282150(X86Context& ctx, uint8_t* base) {
	// 0x282150: movss xmm0, dword ptr [0x0056A7A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7A8u);
	// 0x282158: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282160: movss [0x0056A7DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7DCu, ctx.xmm[0].u32[0]);
	// 0x282168: ret
	return;
}

void sub_282170(X86Context& ctx, uint8_t* base) {
	// 0x282170: movss xmm0, dword ptr [0x0056A7F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7F0u);
	// 0x282178: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282180: movss [0x0056A800], xmm0
	X86_MEM_WRITE_u32(base, 0x56A800u, ctx.xmm[0].u32[0]);
	// 0x282188: ret
	return;
}

void sub_282190(X86Context& ctx, uint8_t* base) {
	// 0x282190: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x282198: movss [0x0056A778], xmm0
	X86_MEM_WRITE_u32(base, 0x56A778u, ctx.xmm[0].u32[0]);
	// 0x2821A0: ret
	return;
}

void sub_2821B0(X86Context& ctx, uint8_t* base) {
	// 0x2821B0: movss xmm0, dword ptr [0x0056A798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A798u);
	// 0x2821B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2821C0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2821C8: movss [0x0056A7E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7E8u, ctx.xmm[0].u32[0]);
	// 0x2821D0: ret
	return;
}

void sub_2821E0(X86Context& ctx, uint8_t* base) {
	// 0x2821E0: movss xmm0, dword ptr [0x0056A7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7ECu);
	// 0x2821E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2821F0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2821F8: movss [0x0056A790], xmm0
	X86_MEM_WRITE_u32(base, 0x56A790u, ctx.xmm[0].u32[0]);
	// 0x282200: ret
	return;
}

void sub_282210(X86Context& ctx, uint8_t* base) {
	// 0x282210: movss xmm0, dword ptr [0x0056A798]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A798u);
	// 0x282218: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282220: movss [0x0056A794], xmm0
	X86_MEM_WRITE_u32(base, 0x56A794u, ctx.xmm[0].u32[0]);
	// 0x282228: ret
	return;
}

void sub_282230(X86Context& ctx, uint8_t* base) {
	// 0x282230: movss xmm0, dword ptr [0x0056A7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7ECu);
	// 0x282238: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282240: movss [0x0056A7F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7F4u, ctx.xmm[0].u32[0]);
	// 0x282248: ret
	return;
}

void sub_282250(X86Context& ctx, uint8_t* base) {
	// 0x282250: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x282258: movss [0x0056A77C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A77Cu, ctx.xmm[0].u32[0]);
	// 0x282260: ret
	return;
}

void sub_282270(X86Context& ctx, uint8_t* base) {
	// 0x282270: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x282278: movss [0x0056A7A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7A4u, ctx.xmm[0].u32[0]);
	// 0x282280: ret
	return;
}

void sub_282290(X86Context& ctx, uint8_t* base) {
	// 0x282290: movss xmm0, dword ptr [0x0056A77C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A77Cu);
	// 0x282298: movss [0x0056A808], xmm0
	X86_MEM_WRITE_u32(base, 0x56A808u, ctx.xmm[0].u32[0]);
	// 0x2822A0: ret
	return;
}

void sub_2822B0(X86Context& ctx, uint8_t* base) {
	// 0x2822B0: movss xmm0, dword ptr [0x0056A7EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7ECu);
	// 0x2822B8: subss xmm0, [0x0056A77C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A77Cu);
	// 0x2822C0: movss [0x0056A7CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7CCu, ctx.xmm[0].u32[0]);
	// 0x2822C8: ret
	return;
}

void sub_2822D0(X86Context& ctx, uint8_t* base) {
	// 0x2822D0: movss xmm0, dword ptr [0x0056A7CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7CCu);
	// 0x2822D8: subss xmm0, [0x0056A7A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A7A4u);
	// 0x2822E0: movss [0x0056A7C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7C4u, ctx.xmm[0].u32[0]);
	// 0x2822E8: ret
	return;
}

void sub_2822F0(X86Context& ctx, uint8_t* base) {
	// 0x2822F0: movss xmm0, dword ptr [0x0056A7F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7F4u);
	// 0x2822F8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x282300: movss [0x0056A7B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7B4u, ctx.xmm[0].u32[0]);
	// 0x282308: ret
	return;
}

void sub_282310(X86Context& ctx, uint8_t* base) {
	// 0x282310: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x282318: movss [0x0056A7A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7A0u, ctx.xmm[0].u32[0]);
	// 0x282320: ret
	return;
}

void sub_282330(X86Context& ctx, uint8_t* base) {
	// 0x282330: movss xmm0, dword ptr [0x0056A7B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A7B4u);
	// 0x282338: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x282340: movss [0x0056A7E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A7E4u, ctx.xmm[0].u32[0]);
	// 0x282348: ret
	return;
}

void sub_282350(X86Context& ctx, uint8_t* base) {
	// 0x282350: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x282358: movss [0x0056A868], xmm0
	X86_MEM_WRITE_u32(base, 0x56A868u, ctx.xmm[0].u32[0]);
	// 0x282360: ret
	return;
}

void sub_282370(X86Context& ctx, uint8_t* base) {
	// 0x282370: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x282378: movss [0x0056A884], xmm0
	X86_MEM_WRITE_u32(base, 0x56A884u, ctx.xmm[0].u32[0]);
	// 0x282380: ret
	return;
}

void sub_282390(X86Context& ctx, uint8_t* base) {
	// 0x282390: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x282398: movss [0x0056A85C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A85Cu, ctx.xmm[0].u32[0]);
	// 0x2823A0: ret
	return;
}

void sub_2823B0(X86Context& ctx, uint8_t* base) {
	// 0x2823B0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2823B8: movss [0x0056A814], xmm0
	X86_MEM_WRITE_u32(base, 0x56A814u, ctx.xmm[0].u32[0]);
	// 0x2823C0: ret
	return;
}

void sub_2823D0(X86Context& ctx, uint8_t* base) {
	// 0x2823D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2823D8: movss [0x0056A86C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A86Cu, ctx.xmm[0].u32[0]);
	// 0x2823E0: ret
	return;
}

void sub_2823F0(X86Context& ctx, uint8_t* base) {
	// 0x2823F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2823F8: movss [0x0056A830], xmm0
	X86_MEM_WRITE_u32(base, 0x56A830u, ctx.xmm[0].u32[0]);
	// 0x282400: ret
	return;
}

void sub_282410(X86Context& ctx, uint8_t* base) {
	// 0x282410: movss xmm0, dword ptr [0x0056A86C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A86Cu);
	// 0x282418: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282420: movss [0x0056A8A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8A4u, ctx.xmm[0].u32[0]);
	// 0x282428: ret
	return;
}

void sub_282430(X86Context& ctx, uint8_t* base) {
	// 0x282430: movss xmm0, dword ptr [0x0056A830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A830u);
	// 0x282438: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x282440: movss [0x0056A88C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A88Cu, ctx.xmm[0].u32[0]);
	// 0x282448: ret
	return;
}

void sub_282450(X86Context& ctx, uint8_t* base) {
	// 0x282450: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x282458: movss [0x0056A8BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8BCu, ctx.xmm[0].u32[0]);
	// 0x282460: ret
	return;
}

void sub_282470(X86Context& ctx, uint8_t* base) {
	// 0x282470: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x282478: movss [0x0056A8A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8A8u, ctx.xmm[0].u32[0]);
	// 0x282480: ret
	return;
}

void sub_282490(X86Context& ctx, uint8_t* base) {
	// 0x282490: movss xmm0, dword ptr [0x0056A8A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8A8u);
	// 0x282498: movss [0x0056A8B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8B8u, ctx.xmm[0].u32[0]);
	// 0x2824A0: ret
	return;
}

void sub_2824B0(X86Context& ctx, uint8_t* base) {
	// 0x2824B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2824B8: movss [0x0056A81C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A81Cu, ctx.xmm[0].u32[0]);
	// 0x2824C0: ret
	return;
}

void sub_2824D0(X86Context& ctx, uint8_t* base) {
	// 0x2824D0: movss xmm0, dword ptr [0x0056A830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A830u);
	// 0x2824D8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2824E0: movss [0x0056A8B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8B0u, ctx.xmm[0].u32[0]);
	// 0x2824E8: ret
	return;
}

void sub_2824F0(X86Context& ctx, uint8_t* base) {
	// 0x2824F0: movss xmm0, dword ptr [0x0056A830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A830u);
	// 0x2824F8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x282500: movss [0x0056A858], xmm0
	X86_MEM_WRITE_u32(base, 0x56A858u, ctx.xmm[0].u32[0]);
	// 0x282508: ret
	return;
}

void sub_282510(X86Context& ctx, uint8_t* base) {
	// 0x282510: movss xmm0, dword ptr [0x0056A830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A830u);
	// 0x282518: subss xmm0, [0x0056A858]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A858u);
	// 0x282520: movss [0x0056A838], xmm0
	X86_MEM_WRITE_u32(base, 0x56A838u, ctx.xmm[0].u32[0]);
	// 0x282528: ret
	return;
}

void sub_282530(X86Context& ctx, uint8_t* base) {
	// 0x282530: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x282538: movss [0x0056A880], xmm0
	X86_MEM_WRITE_u32(base, 0x56A880u, ctx.xmm[0].u32[0]);
	// 0x282540: ret
	return;
}

void sub_282550(X86Context& ctx, uint8_t* base) {
	// 0x282550: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x282558: movss [0x0056A834], xmm0
	X86_MEM_WRITE_u32(base, 0x56A834u, ctx.xmm[0].u32[0]);
	// 0x282560: ret
	return;
}

void sub_282570(X86Context& ctx, uint8_t* base) {
	// 0x282570: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x282578: movss [0x0056A844], xmm0
	X86_MEM_WRITE_u32(base, 0x56A844u, ctx.xmm[0].u32[0]);
	// 0x282580: ret
	return;
}

void sub_282590(X86Context& ctx, uint8_t* base) {
	// 0x282590: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x282598: movss [0x0056A898], xmm0
	X86_MEM_WRITE_u32(base, 0x56A898u, ctx.xmm[0].u32[0]);
	// 0x2825A0: ret
	return;
}

void sub_2825B0(X86Context& ctx, uint8_t* base) {
	// 0x2825B0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2825B8: movss [0x0056A87C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A87Cu, ctx.xmm[0].u32[0]);
	// 0x2825C0: ret
	return;
}

void sub_2825D0(X86Context& ctx, uint8_t* base) {
	// 0x2825D0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2825D8: movss [0x0056A82C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A82Cu, ctx.xmm[0].u32[0]);
	// 0x2825E0: ret
	return;
}

void sub_2825F0(X86Context& ctx, uint8_t* base) {
	// 0x2825F0: movss xmm0, dword ptr [0x0056A844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A844u);
	// 0x2825F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282600: movss [0x0056A820], xmm0
	X86_MEM_WRITE_u32(base, 0x56A820u, ctx.xmm[0].u32[0]);
	// 0x282608: ret
	return;
}

void sub_282610(X86Context& ctx, uint8_t* base) {
	// 0x282610: movss xmm0, dword ptr [0x0056A898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A898u);
	// 0x282618: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x282620: movss [0x0056A864], xmm0
	X86_MEM_WRITE_u32(base, 0x56A864u, ctx.xmm[0].u32[0]);
	// 0x282628: ret
	return;
}

void sub_282630(X86Context& ctx, uint8_t* base) {
	// 0x282630: movss xmm0, dword ptr [0x0056A820]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A820u);
	// 0x282638: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282640: movss [0x0056A874], xmm0
	X86_MEM_WRITE_u32(base, 0x56A874u, ctx.xmm[0].u32[0]);
	// 0x282648: ret
	return;
}

void sub_282650(X86Context& ctx, uint8_t* base) {
	// 0x282650: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x282658: movss [0x0056A818], xmm0
	X86_MEM_WRITE_u32(base, 0x56A818u, ctx.xmm[0].u32[0]);
	// 0x282660: ret
	return;
}

void sub_282670(X86Context& ctx, uint8_t* base) {
	// 0x282670: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x282678: movss [0x0056A848], xmm0
	X86_MEM_WRITE_u32(base, 0x56A848u, ctx.xmm[0].u32[0]);
	// 0x282680: ret
	return;
}

void sub_282690(X86Context& ctx, uint8_t* base) {
	// 0x282690: movss xmm0, dword ptr [0x0056A844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A844u);
	// 0x282698: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2826A0: movss [0x0056A854], xmm0
	X86_MEM_WRITE_u32(base, 0x56A854u, ctx.xmm[0].u32[0]);
	// 0x2826A8: ret
	return;
}

void sub_2826B0(X86Context& ctx, uint8_t* base) {
	// 0x2826B0: movss xmm0, dword ptr [0x0056A898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A898u);
	// 0x2826B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2826C0: movss [0x0056A89C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A89Cu, ctx.xmm[0].u32[0]);
	// 0x2826C8: ret
	return;
}

void sub_2826D0(X86Context& ctx, uint8_t* base) {
	// 0x2826D0: movss xmm0, dword ptr [0x0056A854]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A854u);
	// 0x2826D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2826E0: movss [0x0056A888], xmm0
	X86_MEM_WRITE_u32(base, 0x56A888u, ctx.xmm[0].u32[0]);
	// 0x2826E8: ret
	return;
}

void sub_2826F0(X86Context& ctx, uint8_t* base) {
	// 0x2826F0: movss xmm0, dword ptr [0x0056A89C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A89Cu);
	// 0x2826F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282700: movss [0x0056A8AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8ACu, ctx.xmm[0].u32[0]);
	// 0x282708: ret
	return;
}

void sub_282710(X86Context& ctx, uint8_t* base) {
	// 0x282710: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x282718: movss [0x0056A824], xmm0
	X86_MEM_WRITE_u32(base, 0x56A824u, ctx.xmm[0].u32[0]);
	// 0x282720: ret
	return;
}

void sub_282730(X86Context& ctx, uint8_t* base) {
	// 0x282730: movss xmm0, dword ptr [0x0056A844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A844u);
	// 0x282738: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282740: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x282748: movss [0x0056A894], xmm0
	X86_MEM_WRITE_u32(base, 0x56A894u, ctx.xmm[0].u32[0]);
	// 0x282750: ret
	return;
}

void sub_282760(X86Context& ctx, uint8_t* base) {
	// 0x282760: movss xmm0, dword ptr [0x0056A898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A898u);
	// 0x282768: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282770: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x282778: movss [0x0056A83C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A83Cu, ctx.xmm[0].u32[0]);
	// 0x282780: ret
	return;
}

void sub_282790(X86Context& ctx, uint8_t* base) {
	// 0x282790: movss xmm0, dword ptr [0x0056A844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A844u);
	// 0x282798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2827A0: movss [0x0056A840], xmm0
	X86_MEM_WRITE_u32(base, 0x56A840u, ctx.xmm[0].u32[0]);
	// 0x2827A8: ret
	return;
}

void sub_2827B0(X86Context& ctx, uint8_t* base) {
	// 0x2827B0: movss xmm0, dword ptr [0x0056A898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A898u);
	// 0x2827B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2827C0: movss [0x0056A8A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8A0u, ctx.xmm[0].u32[0]);
	// 0x2827C8: ret
	return;
}

void sub_2827D0(X86Context& ctx, uint8_t* base) {
	// 0x2827D0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2827D8: movss [0x0056A828], xmm0
	X86_MEM_WRITE_u32(base, 0x56A828u, ctx.xmm[0].u32[0]);
	// 0x2827E0: ret
	return;
}

void sub_2827F0(X86Context& ctx, uint8_t* base) {
	// 0x2827F0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2827F8: movss [0x0056A850], xmm0
	X86_MEM_WRITE_u32(base, 0x56A850u, ctx.xmm[0].u32[0]);
	// 0x282800: ret
	return;
}

void sub_282810(X86Context& ctx, uint8_t* base) {
	// 0x282810: movss xmm0, dword ptr [0x0056A828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A828u);
	// 0x282818: movss [0x0056A8B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8B4u, ctx.xmm[0].u32[0]);
	// 0x282820: ret
	return;
}

void sub_282830(X86Context& ctx, uint8_t* base) {
	// 0x282830: movss xmm0, dword ptr [0x0056A898]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A898u);
	// 0x282838: subss xmm0, [0x0056A828]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A828u);
	// 0x282840: movss [0x0056A878], xmm0
	X86_MEM_WRITE_u32(base, 0x56A878u, ctx.xmm[0].u32[0]);
	// 0x282848: ret
	return;
}

void sub_282850(X86Context& ctx, uint8_t* base) {
	// 0x282850: movss xmm0, dword ptr [0x0056A878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A878u);
	// 0x282858: subss xmm0, [0x0056A850]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A850u);
	// 0x282860: movss [0x0056A870], xmm0
	X86_MEM_WRITE_u32(base, 0x56A870u, ctx.xmm[0].u32[0]);
	// 0x282868: ret
	return;
}

void sub_282870(X86Context& ctx, uint8_t* base) {
	// 0x282870: movss xmm0, dword ptr [0x0056A8A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8A0u);
	// 0x282878: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x282880: movss [0x0056A860], xmm0
	X86_MEM_WRITE_u32(base, 0x56A860u, ctx.xmm[0].u32[0]);
	// 0x282888: ret
	return;
}

void sub_282890(X86Context& ctx, uint8_t* base) {
	// 0x282890: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x282898: movss [0x0056A84C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A84Cu, ctx.xmm[0].u32[0]);
	// 0x2828A0: ret
	return;
}

void sub_2828B0(X86Context& ctx, uint8_t* base) {
	// 0x2828B0: movss xmm0, dword ptr [0x0056A860]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A860u);
	// 0x2828B8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2828C0: movss [0x0056A890], xmm0
	X86_MEM_WRITE_u32(base, 0x56A890u, ctx.xmm[0].u32[0]);
	// 0x2828C8: ret
	return;
}

void sub_2828D0(X86Context& ctx, uint8_t* base) {
	// 0x2828D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2828D8: movss [0x0056A914], xmm0
	X86_MEM_WRITE_u32(base, 0x56A914u, ctx.xmm[0].u32[0]);
	// 0x2828E0: ret
	return;
}

void sub_2828F0(X86Context& ctx, uint8_t* base) {
	// 0x2828F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2828F8: movss [0x0056A930], xmm0
	X86_MEM_WRITE_u32(base, 0x56A930u, ctx.xmm[0].u32[0]);
	// 0x282900: ret
	return;
}

void sub_282910(X86Context& ctx, uint8_t* base) {
	// 0x282910: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x282918: movss [0x0056A908], xmm0
	X86_MEM_WRITE_u32(base, 0x56A908u, ctx.xmm[0].u32[0]);
	// 0x282920: ret
	return;
}

void sub_282930(X86Context& ctx, uint8_t* base) {
	// 0x282930: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x282938: movss [0x0056A8C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8C0u, ctx.xmm[0].u32[0]);
	// 0x282940: ret
	return;
}

void sub_282950(X86Context& ctx, uint8_t* base) {
	// 0x282950: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x282958: movss [0x0056A918], xmm0
	X86_MEM_WRITE_u32(base, 0x56A918u, ctx.xmm[0].u32[0]);
	// 0x282960: ret
	return;
}

void sub_282970(X86Context& ctx, uint8_t* base) {
	// 0x282970: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x282978: movss [0x0056A8DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8DCu, ctx.xmm[0].u32[0]);
	// 0x282980: ret
	return;
}

void sub_282990(X86Context& ctx, uint8_t* base) {
	// 0x282990: movss xmm0, dword ptr [0x0056A918]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A918u);
	// 0x282998: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2829A0: movss [0x0056A950], xmm0
	X86_MEM_WRITE_u32(base, 0x56A950u, ctx.xmm[0].u32[0]);
	// 0x2829A8: ret
	return;
}

void sub_2829B0(X86Context& ctx, uint8_t* base) {
	// 0x2829B0: movss xmm0, dword ptr [0x0056A8DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8DCu);
	// 0x2829B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2829C0: movss [0x0056A938], xmm0
	X86_MEM_WRITE_u32(base, 0x56A938u, ctx.xmm[0].u32[0]);
	// 0x2829C8: ret
	return;
}

void sub_2829D0(X86Context& ctx, uint8_t* base) {
	// 0x2829D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2829D8: movss [0x0056A968], xmm0
	X86_MEM_WRITE_u32(base, 0x56A968u, ctx.xmm[0].u32[0]);
	// 0x2829E0: ret
	return;
}

void sub_2829F0(X86Context& ctx, uint8_t* base) {
	// 0x2829F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2829F8: movss [0x0056A954], xmm0
	X86_MEM_WRITE_u32(base, 0x56A954u, ctx.xmm[0].u32[0]);
	// 0x282A00: ret
	return;
}

void sub_282A10(X86Context& ctx, uint8_t* base) {
	// 0x282A10: movss xmm0, dword ptr [0x0056A954]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A954u);
	// 0x282A18: movss [0x0056A964], xmm0
	X86_MEM_WRITE_u32(base, 0x56A964u, ctx.xmm[0].u32[0]);
	// 0x282A20: ret
	return;
}

void sub_282A30(X86Context& ctx, uint8_t* base) {
	// 0x282A30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x282A38: movss [0x0056A8C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8C8u, ctx.xmm[0].u32[0]);
	// 0x282A40: ret
	return;
}

void sub_282A50(X86Context& ctx, uint8_t* base) {
	// 0x282A50: movss xmm0, dword ptr [0x0056A8DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8DCu);
	// 0x282A58: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x282A60: movss [0x0056A95C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A95Cu, ctx.xmm[0].u32[0]);
	// 0x282A68: ret
	return;
}

void sub_282A70(X86Context& ctx, uint8_t* base) {
	// 0x282A70: movss xmm0, dword ptr [0x0056A8DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8DCu);
	// 0x282A78: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x282A80: movss [0x0056A904], xmm0
	X86_MEM_WRITE_u32(base, 0x56A904u, ctx.xmm[0].u32[0]);
	// 0x282A88: ret
	return;
}

void sub_282A90(X86Context& ctx, uint8_t* base) {
	// 0x282A90: movss xmm0, dword ptr [0x0056A8DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8DCu);
	// 0x282A98: subss xmm0, [0x0056A904]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A904u);
	// 0x282AA0: movss [0x0056A8E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8E4u, ctx.xmm[0].u32[0]);
	// 0x282AA8: ret
	return;
}

void sub_282AB0(X86Context& ctx, uint8_t* base) {
	// 0x282AB0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x282AB8: movss [0x0056A92C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A92Cu, ctx.xmm[0].u32[0]);
	// 0x282AC0: ret
	return;
}

void sub_282AD0(X86Context& ctx, uint8_t* base) {
	// 0x282AD0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x282AD8: movss [0x0056A8E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8E0u, ctx.xmm[0].u32[0]);
	// 0x282AE0: ret
	return;
}

void sub_282AF0(X86Context& ctx, uint8_t* base) {
	// 0x282AF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x282AF8: movss [0x0056A8F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8F0u, ctx.xmm[0].u32[0]);
	// 0x282B00: ret
	return;
}

void sub_282B10(X86Context& ctx, uint8_t* base) {
	// 0x282B10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x282B18: movss [0x0056A944], xmm0
	X86_MEM_WRITE_u32(base, 0x56A944u, ctx.xmm[0].u32[0]);
	// 0x282B20: ret
	return;
}

void sub_282B30(X86Context& ctx, uint8_t* base) {
	// 0x282B30: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x282B38: movss [0x0056A928], xmm0
	X86_MEM_WRITE_u32(base, 0x56A928u, ctx.xmm[0].u32[0]);
	// 0x282B40: ret
	return;
}

void sub_282B50(X86Context& ctx, uint8_t* base) {
	// 0x282B50: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x282B58: movss [0x0056A8D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8D8u, ctx.xmm[0].u32[0]);
	// 0x282B60: ret
	return;
}

void sub_282B70(X86Context& ctx, uint8_t* base) {
	// 0x282B70: movss xmm0, dword ptr [0x0056A8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8F0u);
	// 0x282B78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282B80: movss [0x0056A8CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8CCu, ctx.xmm[0].u32[0]);
	// 0x282B88: ret
	return;
}

void sub_282B90(X86Context& ctx, uint8_t* base) {
	// 0x282B90: movss xmm0, dword ptr [0x0056A944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A944u);
	// 0x282B98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x282BA0: movss [0x0056A910], xmm0
	X86_MEM_WRITE_u32(base, 0x56A910u, ctx.xmm[0].u32[0]);
	// 0x282BA8: ret
	return;
}

void sub_282BB0(X86Context& ctx, uint8_t* base) {
	// 0x282BB0: movss xmm0, dword ptr [0x0056A8CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8CCu);
	// 0x282BB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282BC0: movss [0x0056A920], xmm0
	X86_MEM_WRITE_u32(base, 0x56A920u, ctx.xmm[0].u32[0]);
	// 0x282BC8: ret
	return;
}

void sub_282BD0(X86Context& ctx, uint8_t* base) {
	// 0x282BD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x282BD8: movss [0x0056A8C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8C4u, ctx.xmm[0].u32[0]);
	// 0x282BE0: ret
	return;
}

void sub_282BF0(X86Context& ctx, uint8_t* base) {
	// 0x282BF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x282BF8: movss [0x0056A8F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8F4u, ctx.xmm[0].u32[0]);
	// 0x282C00: ret
	return;
}

void sub_282C10(X86Context& ctx, uint8_t* base) {
	// 0x282C10: movss xmm0, dword ptr [0x0056A8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8F0u);
	// 0x282C18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x282C20: movss [0x0056A900], xmm0
	X86_MEM_WRITE_u32(base, 0x56A900u, ctx.xmm[0].u32[0]);
	// 0x282C28: ret
	return;
}

void sub_282C30(X86Context& ctx, uint8_t* base) {
	// 0x282C30: movss xmm0, dword ptr [0x0056A944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A944u);
	// 0x282C38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x282C40: movss [0x0056A948], xmm0
	X86_MEM_WRITE_u32(base, 0x56A948u, ctx.xmm[0].u32[0]);
	// 0x282C48: ret
	return;
}

void sub_282C50(X86Context& ctx, uint8_t* base) {
	// 0x282C50: movss xmm0, dword ptr [0x0056A900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A900u);
	// 0x282C58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282C60: movss [0x0056A934], xmm0
	X86_MEM_WRITE_u32(base, 0x56A934u, ctx.xmm[0].u32[0]);
	// 0x282C68: ret
	return;
}

void sub_282C70(X86Context& ctx, uint8_t* base) {
	// 0x282C70: movss xmm0, dword ptr [0x0056A948]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A948u);
	// 0x282C78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282C80: movss [0x0056A958], xmm0
	X86_MEM_WRITE_u32(base, 0x56A958u, ctx.xmm[0].u32[0]);
	// 0x282C88: ret
	return;
}

void sub_282C90(X86Context& ctx, uint8_t* base) {
	// 0x282C90: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x282C98: movss [0x0056A8D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8D0u, ctx.xmm[0].u32[0]);
	// 0x282CA0: ret
	return;
}

void sub_282CB0(X86Context& ctx, uint8_t* base) {
	// 0x282CB0: movss xmm0, dword ptr [0x0056A8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8F0u);
	// 0x282CB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282CC0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x282CC8: movss [0x0056A940], xmm0
	X86_MEM_WRITE_u32(base, 0x56A940u, ctx.xmm[0].u32[0]);
	// 0x282CD0: ret
	return;
}

void sub_282CE0(X86Context& ctx, uint8_t* base) {
	// 0x282CE0: movss xmm0, dword ptr [0x0056A944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A944u);
	// 0x282CE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282CF0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x282CF8: movss [0x0056A8E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8E8u, ctx.xmm[0].u32[0]);
	// 0x282D00: ret
	return;
}

void sub_282D10(X86Context& ctx, uint8_t* base) {
	// 0x282D10: movss xmm0, dword ptr [0x0056A8F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8F0u);
	// 0x282D18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282D20: movss [0x0056A8EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8ECu, ctx.xmm[0].u32[0]);
	// 0x282D28: ret
	return;
}

void sub_282D30(X86Context& ctx, uint8_t* base) {
	// 0x282D30: movss xmm0, dword ptr [0x0056A944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A944u);
	// 0x282D38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x282D40: movss [0x0056A94C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A94Cu, ctx.xmm[0].u32[0]);
	// 0x282D48: ret
	return;
}

void sub_282D50(X86Context& ctx, uint8_t* base) {
	// 0x282D50: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x282D58: movss [0x0056A8D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8D4u, ctx.xmm[0].u32[0]);
	// 0x282D60: ret
	return;
}

void sub_282D70(X86Context& ctx, uint8_t* base) {
	// 0x282D70: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x282D78: movss [0x0056A8FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8FCu, ctx.xmm[0].u32[0]);
	// 0x282D80: ret
	return;
}

void sub_282D90(X86Context& ctx, uint8_t* base) {
	// 0x282D90: movss xmm0, dword ptr [0x0056A8D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A8D4u);
	// 0x282D98: movss [0x0056A960], xmm0
	X86_MEM_WRITE_u32(base, 0x56A960u, ctx.xmm[0].u32[0]);
	// 0x282DA0: ret
	return;
}

void sub_282DB0(X86Context& ctx, uint8_t* base) {
	// 0x282DB0: movss xmm0, dword ptr [0x0056A944]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A944u);
	// 0x282DB8: subss xmm0, [0x0056A8D4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A8D4u);
	// 0x282DC0: movss [0x0056A924], xmm0
	X86_MEM_WRITE_u32(base, 0x56A924u, ctx.xmm[0].u32[0]);
	// 0x282DC8: ret
	return;
}

void sub_282DD0(X86Context& ctx, uint8_t* base) {
	// 0x282DD0: movss xmm0, dword ptr [0x0056A924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A924u);
	// 0x282DD8: subss xmm0, [0x0056A8FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A8FCu);
	// 0x282DE0: movss [0x0056A91C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A91Cu, ctx.xmm[0].u32[0]);
	// 0x282DE8: ret
	return;
}

void sub_282DF0(X86Context& ctx, uint8_t* base) {
	// 0x282DF0: movss xmm0, dword ptr [0x0056A94C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A94Cu);
	// 0x282DF8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x282E00: movss [0x0056A90C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A90Cu, ctx.xmm[0].u32[0]);
	// 0x282E08: ret
	return;
}

void sub_282E10(X86Context& ctx, uint8_t* base) {
	// 0x282E10: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x282E18: movss [0x0056A8F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A8F8u, ctx.xmm[0].u32[0]);
	// 0x282E20: ret
	return;
}

void sub_282E30(X86Context& ctx, uint8_t* base) {
	// 0x282E30: movss xmm0, dword ptr [0x0056A90C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A90Cu);
	// 0x282E38: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x282E40: movss [0x0056A93C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A93Cu, ctx.xmm[0].u32[0]);
	// 0x282E48: ret
	return;
}

void sub_282E50(X86Context& ctx, uint8_t* base) {
	// 0x282E50: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x282E58: movss [0x0056A9C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9C0u, ctx.xmm[0].u32[0]);
	// 0x282E60: ret
	return;
}

void sub_282E70(X86Context& ctx, uint8_t* base) {
	// 0x282E70: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x282E78: movss [0x0056A9DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9DCu, ctx.xmm[0].u32[0]);
	// 0x282E80: ret
	return;
}

void sub_282E90(X86Context& ctx, uint8_t* base) {
	// 0x282E90: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x282E98: movss [0x0056A9B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9B4u, ctx.xmm[0].u32[0]);
	// 0x282EA0: ret
	return;
}

void sub_282EB0(X86Context& ctx, uint8_t* base) {
	// 0x282EB0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x282EB8: movss [0x0056A96C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A96Cu, ctx.xmm[0].u32[0]);
	// 0x282EC0: ret
	return;
}

void sub_282ED0(X86Context& ctx, uint8_t* base) {
	// 0x282ED0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x282ED8: movss [0x0056A9C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9C4u, ctx.xmm[0].u32[0]);
	// 0x282EE0: ret
	return;
}

void sub_282EF0(X86Context& ctx, uint8_t* base) {
	// 0x282EF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x282EF8: movss [0x0056A988], xmm0
	X86_MEM_WRITE_u32(base, 0x56A988u, ctx.xmm[0].u32[0]);
	// 0x282F00: ret
	return;
}

void sub_282F10(X86Context& ctx, uint8_t* base) {
	// 0x282F10: movss xmm0, dword ptr [0x0056A9C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9C4u);
	// 0x282F18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x282F20: movss [0x0056A9FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9FCu, ctx.xmm[0].u32[0]);
	// 0x282F28: ret
	return;
}

void sub_282F30(X86Context& ctx, uint8_t* base) {
	// 0x282F30: movss xmm0, dword ptr [0x0056A988]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A988u);
	// 0x282F38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x282F40: movss [0x0056A9E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9E4u, ctx.xmm[0].u32[0]);
	// 0x282F48: ret
	return;
}

void sub_282F50(X86Context& ctx, uint8_t* base) {
	// 0x282F50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x282F58: movss [0x0056AA14], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA14u, ctx.xmm[0].u32[0]);
	// 0x282F60: ret
	return;
}

void sub_282F70(X86Context& ctx, uint8_t* base) {
	// 0x282F70: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x282F78: movss [0x0056AA00], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA00u, ctx.xmm[0].u32[0]);
	// 0x282F80: ret
	return;
}

void sub_282F90(X86Context& ctx, uint8_t* base) {
	// 0x282F90: movss xmm0, dword ptr [0x0056AA00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA00u);
	// 0x282F98: movss [0x0056AA10], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA10u, ctx.xmm[0].u32[0]);
	// 0x282FA0: ret
	return;
}

void sub_282FB0(X86Context& ctx, uint8_t* base) {
	// 0x282FB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x282FB8: movss [0x0056A974], xmm0
	X86_MEM_WRITE_u32(base, 0x56A974u, ctx.xmm[0].u32[0]);
	// 0x282FC0: ret
	return;
}

void sub_282FD0(X86Context& ctx, uint8_t* base) {
	// 0x282FD0: movss xmm0, dword ptr [0x0056A988]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A988u);
	// 0x282FD8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x282FE0: movss [0x0056AA08], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA08u, ctx.xmm[0].u32[0]);
	// 0x282FE8: ret
	return;
}

void sub_282FF0(X86Context& ctx, uint8_t* base) {
	// 0x282FF0: movss xmm0, dword ptr [0x0056A988]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A988u);
	// 0x282FF8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x283000: movss [0x0056A9B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9B0u, ctx.xmm[0].u32[0]);
	// 0x283008: ret
	return;
}

void sub_283010(X86Context& ctx, uint8_t* base) {
	// 0x283010: movss xmm0, dword ptr [0x0056A988]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A988u);
	// 0x283018: subss xmm0, [0x0056A9B0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A9B0u);
	// 0x283020: movss [0x0056A990], xmm0
	X86_MEM_WRITE_u32(base, 0x56A990u, ctx.xmm[0].u32[0]);
	// 0x283028: ret
	return;
}

void sub_283030(X86Context& ctx, uint8_t* base) {
	// 0x283030: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x283038: movss [0x0056A9D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9D8u, ctx.xmm[0].u32[0]);
	// 0x283040: ret
	return;
}

void sub_283050(X86Context& ctx, uint8_t* base) {
	// 0x283050: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x283058: movss [0x0056A98C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A98Cu, ctx.xmm[0].u32[0]);
	// 0x283060: ret
	return;
}

void sub_283070(X86Context& ctx, uint8_t* base) {
	// 0x283070: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x283078: movss [0x0056A99C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A99Cu, ctx.xmm[0].u32[0]);
	// 0x283080: ret
	return;
}

void sub_283090(X86Context& ctx, uint8_t* base) {
	// 0x283090: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x283098: movss [0x0056A9F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9F0u, ctx.xmm[0].u32[0]);
	// 0x2830A0: ret
	return;
}

void sub_2830B0(X86Context& ctx, uint8_t* base) {
	// 0x2830B0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2830B8: movss [0x0056A9D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9D4u, ctx.xmm[0].u32[0]);
	// 0x2830C0: ret
	return;
}

void sub_2830D0(X86Context& ctx, uint8_t* base) {
	// 0x2830D0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2830D8: movss [0x0056A984], xmm0
	X86_MEM_WRITE_u32(base, 0x56A984u, ctx.xmm[0].u32[0]);
	// 0x2830E0: ret
	return;
}

void sub_2830F0(X86Context& ctx, uint8_t* base) {
	// 0x2830F0: movss xmm0, dword ptr [0x0056A99C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A99Cu);
	// 0x2830F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x283100: movss [0x0056A978], xmm0
	X86_MEM_WRITE_u32(base, 0x56A978u, ctx.xmm[0].u32[0]);
	// 0x283108: ret
	return;
}

void sub_283110(X86Context& ctx, uint8_t* base) {
	// 0x283110: movss xmm0, dword ptr [0x0056A9F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F0u);
	// 0x283118: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x283120: movss [0x0056A9BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9BCu, ctx.xmm[0].u32[0]);
	// 0x283128: ret
	return;
}

void sub_283130(X86Context& ctx, uint8_t* base) {
	// 0x283130: movss xmm0, dword ptr [0x0056A978]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A978u);
	// 0x283138: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x283140: movss [0x0056A9CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9CCu, ctx.xmm[0].u32[0]);
	// 0x283148: ret
	return;
}

void sub_283150(X86Context& ctx, uint8_t* base) {
	// 0x283150: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x283158: movss [0x0056A970], xmm0
	X86_MEM_WRITE_u32(base, 0x56A970u, ctx.xmm[0].u32[0]);
	// 0x283160: ret
	return;
}

void sub_283170(X86Context& ctx, uint8_t* base) {
	// 0x283170: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x283178: movss [0x0056A9A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9A0u, ctx.xmm[0].u32[0]);
	// 0x283180: ret
	return;
}

void sub_283190(X86Context& ctx, uint8_t* base) {
	// 0x283190: movss xmm0, dword ptr [0x0056A99C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A99Cu);
	// 0x283198: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2831A0: movss [0x0056A9AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9ACu, ctx.xmm[0].u32[0]);
	// 0x2831A8: ret
	return;
}

void sub_2831B0(X86Context& ctx, uint8_t* base) {
	// 0x2831B0: movss xmm0, dword ptr [0x0056A9F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F0u);
	// 0x2831B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2831C0: movss [0x0056A9F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9F4u, ctx.xmm[0].u32[0]);
	// 0x2831C8: ret
	return;
}

void sub_2831D0(X86Context& ctx, uint8_t* base) {
	// 0x2831D0: movss xmm0, dword ptr [0x0056A9AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9ACu);
	// 0x2831D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2831E0: movss [0x0056A9E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9E0u, ctx.xmm[0].u32[0]);
	// 0x2831E8: ret
	return;
}

void sub_2831F0(X86Context& ctx, uint8_t* base) {
	// 0x2831F0: movss xmm0, dword ptr [0x0056A9F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F4u);
	// 0x2831F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283200: movss [0x0056AA04], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA04u, ctx.xmm[0].u32[0]);
	// 0x283208: ret
	return;
}

void sub_283210(X86Context& ctx, uint8_t* base) {
	// 0x283210: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x283218: movss [0x0056A97C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A97Cu, ctx.xmm[0].u32[0]);
	// 0x283220: ret
	return;
}

void sub_283230(X86Context& ctx, uint8_t* base) {
	// 0x283230: movss xmm0, dword ptr [0x0056A99C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A99Cu);
	// 0x283238: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283240: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x283248: movss [0x0056A9EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9ECu, ctx.xmm[0].u32[0]);
	// 0x283250: ret
	return;
}

void sub_283260(X86Context& ctx, uint8_t* base) {
	// 0x283260: movss xmm0, dword ptr [0x0056A9F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F0u);
	// 0x283268: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283270: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x283278: movss [0x0056A994], xmm0
	X86_MEM_WRITE_u32(base, 0x56A994u, ctx.xmm[0].u32[0]);
	// 0x283280: ret
	return;
}

void sub_283290(X86Context& ctx, uint8_t* base) {
	// 0x283290: movss xmm0, dword ptr [0x0056A99C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A99Cu);
	// 0x283298: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2832A0: movss [0x0056A998], xmm0
	X86_MEM_WRITE_u32(base, 0x56A998u, ctx.xmm[0].u32[0]);
	// 0x2832A8: ret
	return;
}

void sub_2832B0(X86Context& ctx, uint8_t* base) {
	// 0x2832B0: movss xmm0, dword ptr [0x0056A9F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F0u);
	// 0x2832B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2832C0: movss [0x0056A9F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9F8u, ctx.xmm[0].u32[0]);
	// 0x2832C8: ret
	return;
}

void sub_2832D0(X86Context& ctx, uint8_t* base) {
	// 0x2832D0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2832D8: movss [0x0056A980], xmm0
	X86_MEM_WRITE_u32(base, 0x56A980u, ctx.xmm[0].u32[0]);
	// 0x2832E0: ret
	return;
}

void sub_2832F0(X86Context& ctx, uint8_t* base) {
	// 0x2832F0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2832F8: movss [0x0056A9A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9A8u, ctx.xmm[0].u32[0]);
	// 0x283300: ret
	return;
}

void sub_283310(X86Context& ctx, uint8_t* base) {
	// 0x283310: movss xmm0, dword ptr [0x0056A980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A980u);
	// 0x283318: movss [0x0056AA0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA0Cu, ctx.xmm[0].u32[0]);
	// 0x283320: ret
	return;
}

void sub_283330(X86Context& ctx, uint8_t* base) {
	// 0x283330: movss xmm0, dword ptr [0x0056A9F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F0u);
	// 0x283338: subss xmm0, [0x0056A980]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A980u);
	// 0x283340: movss [0x0056A9D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9D0u, ctx.xmm[0].u32[0]);
	// 0x283348: ret
	return;
}

void sub_283350(X86Context& ctx, uint8_t* base) {
	// 0x283350: movss xmm0, dword ptr [0x0056A9D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9D0u);
	// 0x283358: subss xmm0, [0x0056A9A8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A9A8u);
	// 0x283360: movss [0x0056A9C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9C8u, ctx.xmm[0].u32[0]);
	// 0x283368: ret
	return;
}

void sub_283370(X86Context& ctx, uint8_t* base) {
	// 0x283370: movss xmm0, dword ptr [0x0056A9F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9F8u);
	// 0x283378: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x283380: movss [0x0056A9B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9B8u, ctx.xmm[0].u32[0]);
	// 0x283388: ret
	return;
}

void sub_283390(X86Context& ctx, uint8_t* base) {
	// 0x283390: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x283398: movss [0x0056A9A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9A4u, ctx.xmm[0].u32[0]);
	// 0x2833A0: ret
	return;
}

void sub_2833B0(X86Context& ctx, uint8_t* base) {
	// 0x2833B0: movss xmm0, dword ptr [0x0056A9B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A9B8u);
	// 0x2833B8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2833C0: movss [0x0056A9E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A9E8u, ctx.xmm[0].u32[0]);
	// 0x2833C8: ret
	return;
}

void sub_2833D0(X86Context& ctx, uint8_t* base) {
	// 0x2833D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2833D8: movss [0x0056AA7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA7Cu, ctx.xmm[0].u32[0]);
	// 0x2833E0: ret
	return;
}

void sub_2833F0(X86Context& ctx, uint8_t* base) {
	// 0x2833F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2833F8: movss [0x0056AA98], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA98u, ctx.xmm[0].u32[0]);
	// 0x283400: ret
	return;
}

void sub_283410(X86Context& ctx, uint8_t* base) {
	// 0x283410: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x283418: movss [0x0056AA68], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA68u, ctx.xmm[0].u32[0]);
	// 0x283420: ret
	return;
}

void sub_283430(X86Context& ctx, uint8_t* base) {
	// 0x283430: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x283438: movss [0x0056AA18], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA18u, ctx.xmm[0].u32[0]);
	// 0x283440: ret
	return;
}

void sub_283450(X86Context& ctx, uint8_t* base) {
	// 0x283450: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x283458: movss [0x0056AA80], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA80u, ctx.xmm[0].u32[0]);
	// 0x283460: ret
	return;
}

void sub_283470(X86Context& ctx, uint8_t* base) {
	// 0x283470: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x283478: movss [0x0056AA38], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA38u, ctx.xmm[0].u32[0]);
	// 0x283480: ret
	return;
}

void sub_283490(X86Context& ctx, uint8_t* base) {
	// 0x283490: movss xmm0, dword ptr [0x0056AA80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA80u);
	// 0x283498: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2834A0: movss [0x0056AAB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAB8u, ctx.xmm[0].u32[0]);
	// 0x2834A8: ret
	return;
}

void sub_2834B0(X86Context& ctx, uint8_t* base) {
	// 0x2834B0: movss xmm0, dword ptr [0x0056AA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA38u);
	// 0x2834B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2834C0: movss [0x0056AAA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAA0u, ctx.xmm[0].u32[0]);
	// 0x2834C8: ret
	return;
}

void sub_2834D0(X86Context& ctx, uint8_t* base) {
	// 0x2834D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2834D8: movss [0x0056AAD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAD0u, ctx.xmm[0].u32[0]);
	// 0x2834E0: ret
	return;
}

void sub_2834F0(X86Context& ctx, uint8_t* base) {
	// 0x2834F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2834F8: movss [0x0056AABC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AABCu, ctx.xmm[0].u32[0]);
	// 0x283500: ret
	return;
}

void sub_283510(X86Context& ctx, uint8_t* base) {
	// 0x283510: movss xmm0, dword ptr [0x0056AABC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AABCu);
	// 0x283518: movss [0x0056AACC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AACCu, ctx.xmm[0].u32[0]);
	// 0x283520: ret
	return;
}

void sub_283530(X86Context& ctx, uint8_t* base) {
	// 0x283530: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x283538: movss [0x0056AA24], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA24u, ctx.xmm[0].u32[0]);
	// 0x283540: ret
	return;
}

void sub_283550(X86Context& ctx, uint8_t* base) {
	// 0x283550: movss xmm0, dword ptr [0x0056AA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA38u);
	// 0x283558: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x283560: movss [0x0056AAC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAC4u, ctx.xmm[0].u32[0]);
	// 0x283568: ret
	return;
}

void sub_283570(X86Context& ctx, uint8_t* base) {
	// 0x283570: movss xmm0, dword ptr [0x0056AA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA38u);
	// 0x283578: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x283580: movss [0x0056AA64], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA64u, ctx.xmm[0].u32[0]);
	// 0x283588: ret
	return;
}

void sub_283590(X86Context& ctx, uint8_t* base) {
	// 0x283590: movss xmm0, dword ptr [0x0056AA38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA38u);
	// 0x283598: subss xmm0, [0x0056AA64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56AA64u);
	// 0x2835A0: movss [0x0056AA40], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA40u, ctx.xmm[0].u32[0]);
	// 0x2835A8: ret
	return;
}

void sub_2835B0(X86Context& ctx, uint8_t* base) {
	// 0x2835B0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2835B8: movss [0x0056AA94], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA94u, ctx.xmm[0].u32[0]);
	// 0x2835C0: ret
	return;
}

void sub_2835D0(X86Context& ctx, uint8_t* base) {
	// 0x2835D0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2835D8: movss [0x0056AA3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA3Cu, ctx.xmm[0].u32[0]);
	// 0x2835E0: ret
	return;
}

void sub_2835F0(X86Context& ctx, uint8_t* base) {
	// 0x2835F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2835F8: movss [0x0056AA50], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA50u, ctx.xmm[0].u32[0]);
	// 0x283600: ret
	return;
}

void sub_283610(X86Context& ctx, uint8_t* base) {
	// 0x283610: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x283618: movss [0x0056AAAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAACu, ctx.xmm[0].u32[0]);
	// 0x283620: ret
	return;
}

void sub_283630(X86Context& ctx, uint8_t* base) {
	// 0x283630: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x283638: movss [0x0056AA90], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA90u, ctx.xmm[0].u32[0]);
	// 0x283640: ret
	return;
}

void sub_283650(X86Context& ctx, uint8_t* base) {
	// 0x283650: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x283658: movss [0x0056AA34], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA34u, ctx.xmm[0].u32[0]);
	// 0x283660: ret
	return;
}

void sub_283670(X86Context& ctx, uint8_t* base) {
	// 0x283670: movss xmm0, dword ptr [0x0056AA50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA50u);
	// 0x283678: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x283680: movss [0x0056AA28], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA28u, ctx.xmm[0].u32[0]);
	// 0x283688: ret
	return;
}

void sub_283690(X86Context& ctx, uint8_t* base) {
	// 0x283690: movss xmm0, dword ptr [0x0056AAAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAACu);
	// 0x283698: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2836A0: movss [0x0056AA78], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA78u, ctx.xmm[0].u32[0]);
	// 0x2836A8: ret
	return;
}

void sub_2836B0(X86Context& ctx, uint8_t* base) {
	// 0x2836B0: movss xmm0, dword ptr [0x0056AA28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA28u);
	// 0x2836B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2836C0: movss [0x0056AA88], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA88u, ctx.xmm[0].u32[0]);
	// 0x2836C8: ret
	return;
}

void sub_2836D0(X86Context& ctx, uint8_t* base) {
	// 0x2836D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2836D8: movss [0x0056AA1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA1Cu, ctx.xmm[0].u32[0]);
	// 0x2836E0: ret
	return;
}

void sub_2836F0(X86Context& ctx, uint8_t* base) {
	// 0x2836F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2836F8: movss [0x0056AA54], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA54u, ctx.xmm[0].u32[0]);
	// 0x283700: ret
	return;
}

void sub_283710(X86Context& ctx, uint8_t* base) {
	// 0x283710: movss xmm0, dword ptr [0x0056AA50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA50u);
	// 0x283718: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x283720: movss [0x0056AA60], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA60u, ctx.xmm[0].u32[0]);
	// 0x283728: ret
	return;
}

void sub_283730(X86Context& ctx, uint8_t* base) {
	// 0x283730: movss xmm0, dword ptr [0x0056AAAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAACu);
	// 0x283738: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x283740: movss [0x0056AAB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAB0u, ctx.xmm[0].u32[0]);
	// 0x283748: ret
	return;
}

void sub_283750(X86Context& ctx, uint8_t* base) {
	// 0x283750: movss xmm0, dword ptr [0x0056AA60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA60u);
	// 0x283758: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283760: movss [0x0056AA9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA9Cu, ctx.xmm[0].u32[0]);
	// 0x283768: ret
	return;
}

void sub_283770(X86Context& ctx, uint8_t* base) {
	// 0x283770: movss xmm0, dword ptr [0x0056AAB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAB0u);
	// 0x283778: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x283780: movss [0x0056AAC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAC0u, ctx.xmm[0].u32[0]);
	// 0x283788: ret
	return;
}

void sub_283790(X86Context& ctx, uint8_t* base) {
	// 0x283790: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x283798: movss [0x0056AA2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA2Cu, ctx.xmm[0].u32[0]);
	// 0x2837A0: ret
	return;
}

void sub_2837B0(X86Context& ctx, uint8_t* base) {
	// 0x2837B0: movss xmm0, dword ptr [0x0056AA50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AA50u);
	// 0x2837B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2837C0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2837C8: movss [0x0056AAA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56AAA8u, ctx.xmm[0].u32[0]);
	// 0x2837D0: ret
	return;
}

void sub_2837E0(X86Context& ctx, uint8_t* base) {
	// 0x2837E0: movss xmm0, dword ptr [0x0056AAAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56AAACu);
	// 0x2837E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2837F0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2837F8: movss [0x0056AA48], xmm0
	X86_MEM_WRITE_u32(base, 0x56AA48u, ctx.xmm[0].u32[0]);
	// 0x283800: ret
	return;
}

