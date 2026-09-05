#include "x86_recomp_shared.h"

void sub_2A6750(X86Context& ctx, uint8_t* base) {
	// 0x2A6750: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A6758: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A6760: movss [0x00570580], xmm0
	X86_MEM_WRITE_u32(base, 0x570580u, ctx.xmm[0].u32[0]);
	// 0x2A6768: ret
	return;
}

void sub_2A6770(X86Context& ctx, uint8_t* base) {
	// 0x2A6770: movss xmm0, dword ptr [0x00570620]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570620u);
	// 0x2A6778: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A6780: movss [0x005705DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5705DCu, ctx.xmm[0].u32[0]);
	// 0x2A6788: ret
	return;
}

void sub_2A6790(X86Context& ctx, uint8_t* base) {
	// 0x2A6790: movss xmm0, dword ptr [0x00570580]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570580u);
	// 0x2A6798: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A67A0: movss [0x005705F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5705F0u, ctx.xmm[0].u32[0]);
	// 0x2A67A8: ret
	return;
}

void sub_2A67B0(X86Context& ctx, uint8_t* base) {
	// 0x2A67B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A67B8: movss [0x00570578], xmm0
	X86_MEM_WRITE_u32(base, 0x570578u, ctx.xmm[0].u32[0]);
	// 0x2A67C0: ret
	return;
}

void sub_2A67D0(X86Context& ctx, uint8_t* base) {
	// 0x2A67D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A67D8: movss [0x005705B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5705B4u, ctx.xmm[0].u32[0]);
	// 0x2A67E0: ret
	return;
}

void sub_2A67F0(X86Context& ctx, uint8_t* base) {
	// 0x2A67F0: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A67F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A6800: movss [0x005705C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5705C4u, ctx.xmm[0].u32[0]);
	// 0x2A6808: ret
	return;
}

void sub_2A6810(X86Context& ctx, uint8_t* base) {
	// 0x2A6810: movss xmm0, dword ptr [0x00570620]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570620u);
	// 0x2A6818: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A6820: movss [0x00570624], xmm0
	X86_MEM_WRITE_u32(base, 0x570624u, ctx.xmm[0].u32[0]);
	// 0x2A6828: ret
	return;
}

void sub_2A6830(X86Context& ctx, uint8_t* base) {
	// 0x2A6830: movss xmm0, dword ptr [0x005705C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705C4u);
	// 0x2A6838: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6840: movss [0x00570610], xmm0
	X86_MEM_WRITE_u32(base, 0x570610u, ctx.xmm[0].u32[0]);
	// 0x2A6848: ret
	return;
}

void sub_2A6850(X86Context& ctx, uint8_t* base) {
	// 0x2A6850: movss xmm0, dword ptr [0x00570624]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570624u);
	// 0x2A6858: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6860: movss [0x00570634], xmm0
	X86_MEM_WRITE_u32(base, 0x570634u, ctx.xmm[0].u32[0]);
	// 0x2A6868: ret
	return;
}

void sub_2A6870(X86Context& ctx, uint8_t* base) {
	// 0x2A6870: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A6878: movss [0x00570584], xmm0
	X86_MEM_WRITE_u32(base, 0x570584u, ctx.xmm[0].u32[0]);
	// 0x2A6880: ret
	return;
}

void sub_2A6890(X86Context& ctx, uint8_t* base) {
	// 0x2A6890: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A6898: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A68A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A68A8: movss [0x0057061C], xmm0
	X86_MEM_WRITE_u32(base, 0x57061Cu, ctx.xmm[0].u32[0]);
	// 0x2A68B0: ret
	return;
}

void sub_2A68C0(X86Context& ctx, uint8_t* base) {
	// 0x2A68C0: movss xmm0, dword ptr [0x00570620]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570620u);
	// 0x2A68C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A68D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A68D8: movss [0x005705A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5705A4u, ctx.xmm[0].u32[0]);
	// 0x2A68E0: ret
	return;
}

void sub_2A68F0(X86Context& ctx, uint8_t* base) {
	// 0x2A68F0: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A68F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6900: movss [0x005705A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5705A8u, ctx.xmm[0].u32[0]);
	// 0x2A6908: ret
	return;
}

void sub_2A6910(X86Context& ctx, uint8_t* base) {
	// 0x2A6910: movss xmm0, dword ptr [0x00570620]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570620u);
	// 0x2A6918: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6920: movss [0x00570628], xmm0
	X86_MEM_WRITE_u32(base, 0x570628u, ctx.xmm[0].u32[0]);
	// 0x2A6928: ret
	return;
}

void sub_2A6930(X86Context& ctx, uint8_t* base) {
	// 0x2A6930: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A6938: movss [0x00570588], xmm0
	X86_MEM_WRITE_u32(base, 0x570588u, ctx.xmm[0].u32[0]);
	// 0x2A6940: ret
	return;
}

void sub_2A6950(X86Context& ctx, uint8_t* base) {
	// 0x2A6950: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A6958: movss [0x005705C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5705C0u, ctx.xmm[0].u32[0]);
	// 0x2A6960: ret
	return;
}

void sub_2A6970(X86Context& ctx, uint8_t* base) {
	// 0x2A6970: movss xmm0, dword ptr [0x00570588]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570588u);
	// 0x2A6978: movss [0x00570644], xmm0
	X86_MEM_WRITE_u32(base, 0x570644u, ctx.xmm[0].u32[0]);
	// 0x2A6980: ret
	return;
}

void sub_2A6990(X86Context& ctx, uint8_t* base) {
	// 0x2A6990: movss xmm0, dword ptr [0x00570620]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570620u);
	// 0x2A6998: subss xmm0, [0x00570588]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570588u);
	// 0x2A69A0: movss [0x005705F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5705F4u, ctx.xmm[0].u32[0]);
	// 0x2A69A8: ret
	return;
}

void sub_2A69B0(X86Context& ctx, uint8_t* base) {
	// 0x2A69B0: movss xmm0, dword ptr [0x005705F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705F4u);
	// 0x2A69B8: subss xmm0, [0x005705C0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5705C0u);
	// 0x2A69C0: movss [0x005705EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5705ECu, ctx.xmm[0].u32[0]);
	// 0x2A69C8: ret
	return;
}

void sub_2A69D0(X86Context& ctx, uint8_t* base) {
	// 0x2A69D0: movss xmm0, dword ptr [0x00570628]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570628u);
	// 0x2A69D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A69E0: movss [0x005705D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5705D4u, ctx.xmm[0].u32[0]);
	// 0x2A69E8: ret
	return;
}

void sub_2A69F0(X86Context& ctx, uint8_t* base) {
	// 0x2A69F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A69F8: movss [0x005705BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5705BCu, ctx.xmm[0].u32[0]);
	// 0x2A6A00: ret
	return;
}

void sub_2A6A10(X86Context& ctx, uint8_t* base) {
	// 0x2A6A10: movss xmm0, dword ptr [0x005705D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705D4u);
	// 0x2A6A18: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A6A20: movss [0x00570618], xmm0
	X86_MEM_WRITE_u32(base, 0x570618u, ctx.xmm[0].u32[0]);
	// 0x2A6A28: ret
	return;
}

void sub_2A6A30(X86Context& ctx, uint8_t* base) {
	// 0x2A6A30: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A6A38: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A6A40: movss [0x005705D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5705D8u, ctx.xmm[0].u32[0]);
	// 0x2A6A48: ret
	return;
}

void sub_2A6A50(X86Context& ctx, uint8_t* base) {
	// 0x2A6A50: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A6A58: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A6A60: movss [0x005705AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5705ACu, ctx.xmm[0].u32[0]);
	// 0x2A6A68: ret
	return;
}

void sub_2A6A70(X86Context& ctx, uint8_t* base) {
	// 0x2A6A70: movss xmm0, dword ptr [0x005705D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705D8u);
	// 0x2A6A78: movss [0x00570640], xmm0
	X86_MEM_WRITE_u32(base, 0x570640u, ctx.xmm[0].u32[0]);
	// 0x2A6A80: ret
	return;
}

void sub_2A6A90(X86Context& ctx, uint8_t* base) {
	// 0x2A6A90: movss xmm0, dword ptr [0x00395D54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395D54u);
	// 0x2A6A98: movss [0x00570568], xmm0
	X86_MEM_WRITE_u32(base, 0x570568u, ctx.xmm[0].u32[0]);
	// 0x2A6AA0: ret
	return;
}

void sub_2A6AB0(X86Context& ctx, uint8_t* base) {
	// 0x2A6AB0: movss xmm0, dword ptr [0x005705D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705D8u);
	// 0x2A6AB8: movss [0x00570598], xmm0
	X86_MEM_WRITE_u32(base, 0x570598u, ctx.xmm[0].u32[0]);
	// 0x2A6AC0: ret
	return;
}

void sub_2A6AD0(X86Context& ctx, uint8_t* base) {
	// 0x2A6AD0: movss xmm0, dword ptr [0x00570568]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570568u);
	// 0x2A6AD8: addss xmm0, [0x003B17E4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B17E4u);
	// 0x2A6AE0: movss [0x005705E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5705E8u, ctx.xmm[0].u32[0]);
	// 0x2A6AE8: ret
	return;
}

void sub_2A6AF0(X86Context& ctx, uint8_t* base) {
	// 0x2A6AF0: movss xmm0, dword ptr [0x005705D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705D8u);
	// 0x2A6AF8: movss [0x00570574], xmm0
	X86_MEM_WRITE_u32(base, 0x570574u, ctx.xmm[0].u32[0]);
	// 0x2A6B00: ret
	return;
}

void sub_2A6B10(X86Context& ctx, uint8_t* base) {
	// 0x2A6B10: movss xmm0, dword ptr [0x005705E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705E8u);
	// 0x2A6B18: addss xmm0, [0x003B1884]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B1884u);
	// 0x2A6B20: movss [0x00570570], xmm0
	X86_MEM_WRITE_u32(base, 0x570570u, ctx.xmm[0].u32[0]);
	// 0x2A6B28: ret
	return;
}

void sub_2A6B30(X86Context& ctx, uint8_t* base) {
	// 0x2A6B30: movss xmm0, dword ptr [0x005705B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B0u);
	// 0x2A6B38: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A6B40: movss [0x005705A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5705A0u, ctx.xmm[0].u32[0]);
	// 0x2A6B48: ret
	return;
}

void sub_2A6B50(X86Context& ctx, uint8_t* base) {
	// 0x2A6B50: movss xmm0, dword ptr [0x003A1A00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A1A00u);
	// 0x2A6B58: movss [0x00570600], xmm0
	X86_MEM_WRITE_u32(base, 0x570600u, ctx.xmm[0].u32[0]);
	// 0x2A6B60: ret
	return;
}

void sub_2A6B70(X86Context& ctx, uint8_t* base) {
	// 0x2A6B70: movss xmm0, dword ptr [0x00570600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570600u);
	// 0x2A6B78: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A6B80: movss [0x005705F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5705F8u, ctx.xmm[0].u32[0]);
	// 0x2A6B88: ret
	return;
}

void sub_2A6B90(X86Context& ctx, uint8_t* base) {
	// 0x2A6B90: movss xmm0, dword ptr [0x003B1CE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CE0u);
	// 0x2A6B98: movss [0x00570604], xmm0
	X86_MEM_WRITE_u32(base, 0x570604u, ctx.xmm[0].u32[0]);
	// 0x2A6BA0: ret
	return;
}

void sub_2A6BB0(X86Context& ctx, uint8_t* base) {
	// 0x2A6BB0: movss xmm0, dword ptr [0x00570604]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570604u);
	// 0x2A6BB8: movss [0x005705B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5705B8u, ctx.xmm[0].u32[0]);
	// 0x2A6BC0: ret
	return;
}

void sub_2A6BD0(X86Context& ctx, uint8_t* base) {
	// 0x2A6BD0: movss xmm0, dword ptr [0x005705B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5705B8u);
	// 0x2A6BD8: movss [0x00570638], xmm0
	X86_MEM_WRITE_u32(base, 0x570638u, ctx.xmm[0].u32[0]);
	// 0x2A6BE0: ret
	return;
}

void sub_2A6BF0(X86Context& ctx, uint8_t* base) {
	// 0x2A6BF0: movss xmm0, dword ptr [0x00570638]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570638u);
	// 0x2A6BF8: addss xmm0, [0x003B17E4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B17E4u);
	// 0x2A6C00: movss [0x005705CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5705CCu, ctx.xmm[0].u32[0]);
	// 0x2A6C08: ret
	return;
}

void sub_2A6C10(X86Context& ctx, uint8_t* base) {
	// 0x2A6C10: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A6C18: movss [0x005706A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5706A8u, ctx.xmm[0].u32[0]);
	// 0x2A6C20: ret
	return;
}

void sub_2A6C30(X86Context& ctx, uint8_t* base) {
	// 0x2A6C30: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A6C38: movss [0x005706C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5706C8u, ctx.xmm[0].u32[0]);
	// 0x2A6C40: ret
	return;
}

void sub_2A6C50(X86Context& ctx, uint8_t* base) {
	// 0x2A6C50: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A6C58: movss [0x00570698], xmm0
	X86_MEM_WRITE_u32(base, 0x570698u, ctx.xmm[0].u32[0]);
	// 0x2A6C60: ret
	return;
}

void sub_2A6C70(X86Context& ctx, uint8_t* base) {
	// 0x2A6C70: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A6C78: movss [0x00570650], xmm0
	X86_MEM_WRITE_u32(base, 0x570650u, ctx.xmm[0].u32[0]);
	// 0x2A6C80: ret
	return;
}

void sub_2A6C90(X86Context& ctx, uint8_t* base) {
	// 0x2A6C90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A6C98: movss [0x005706AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5706ACu, ctx.xmm[0].u32[0]);
	// 0x2A6CA0: ret
	return;
}

void sub_2A6CB0(X86Context& ctx, uint8_t* base) {
	// 0x2A6CB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A6CB8: movss [0x0057066C], xmm0
	X86_MEM_WRITE_u32(base, 0x57066Cu, ctx.xmm[0].u32[0]);
	// 0x2A6CC0: ret
	return;
}

void sub_2A6CD0(X86Context& ctx, uint8_t* base) {
	// 0x2A6CD0: movss xmm0, dword ptr [0x005706AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706ACu);
	// 0x2A6CD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A6CE0: movss [0x005706E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5706E8u, ctx.xmm[0].u32[0]);
	// 0x2A6CE8: ret
	return;
}

void sub_2A6CF0(X86Context& ctx, uint8_t* base) {
	// 0x2A6CF0: movss xmm0, dword ptr [0x0057066C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57066Cu);
	// 0x2A6CF8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A6D00: movss [0x005706D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5706D0u, ctx.xmm[0].u32[0]);
	// 0x2A6D08: ret
	return;
}

void sub_2A6D10(X86Context& ctx, uint8_t* base) {
	// 0x2A6D10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A6D18: movss [0x00570700], xmm0
	X86_MEM_WRITE_u32(base, 0x570700u, ctx.xmm[0].u32[0]);
	// 0x2A6D20: ret
	return;
}

void sub_2A6D30(X86Context& ctx, uint8_t* base) {
	// 0x2A6D30: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A6D38: movss [0x005706EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5706ECu, ctx.xmm[0].u32[0]);
	// 0x2A6D40: ret
	return;
}

void sub_2A6D50(X86Context& ctx, uint8_t* base) {
	// 0x2A6D50: movss xmm0, dword ptr [0x005706EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706ECu);
	// 0x2A6D58: movss [0x005706FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5706FCu, ctx.xmm[0].u32[0]);
	// 0x2A6D60: ret
	return;
}

void sub_2A6D70(X86Context& ctx, uint8_t* base) {
	// 0x2A6D70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A6D78: movss [0x00570658], xmm0
	X86_MEM_WRITE_u32(base, 0x570658u, ctx.xmm[0].u32[0]);
	// 0x2A6D80: ret
	return;
}

void sub_2A6D90(X86Context& ctx, uint8_t* base) {
	// 0x2A6D90: movss xmm0, dword ptr [0x0057066C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57066Cu);
	// 0x2A6D98: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A6DA0: movss [0x005706F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5706F4u, ctx.xmm[0].u32[0]);
	// 0x2A6DA8: ret
	return;
}

void sub_2A6DB0(X86Context& ctx, uint8_t* base) {
	// 0x2A6DB0: movss xmm0, dword ptr [0x0057066C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57066Cu);
	// 0x2A6DB8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A6DC0: movss [0x00570694], xmm0
	X86_MEM_WRITE_u32(base, 0x570694u, ctx.xmm[0].u32[0]);
	// 0x2A6DC8: ret
	return;
}

void sub_2A6DD0(X86Context& ctx, uint8_t* base) {
	// 0x2A6DD0: movss xmm0, dword ptr [0x0057066C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57066Cu);
	// 0x2A6DD8: subss xmm0, [0x00570694]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570694u);
	// 0x2A6DE0: movss [0x00570674], xmm0
	X86_MEM_WRITE_u32(base, 0x570674u, ctx.xmm[0].u32[0]);
	// 0x2A6DE8: ret
	return;
}

void sub_2A6DF0(X86Context& ctx, uint8_t* base) {
	// 0x2A6DF0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A6DF8: movss [0x005706C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5706C4u, ctx.xmm[0].u32[0]);
	// 0x2A6E00: ret
	return;
}

void sub_2A6E10(X86Context& ctx, uint8_t* base) {
	// 0x2A6E10: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A6E18: movss [0x00570670], xmm0
	X86_MEM_WRITE_u32(base, 0x570670u, ctx.xmm[0].u32[0]);
	// 0x2A6E20: ret
	return;
}

void sub_2A6E30(X86Context& ctx, uint8_t* base) {
	// 0x2A6E30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A6E38: movss [0x00570680], xmm0
	X86_MEM_WRITE_u32(base, 0x570680u, ctx.xmm[0].u32[0]);
	// 0x2A6E40: ret
	return;
}

void sub_2A6E50(X86Context& ctx, uint8_t* base) {
	// 0x2A6E50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A6E58: movss [0x005706DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5706DCu, ctx.xmm[0].u32[0]);
	// 0x2A6E60: ret
	return;
}

void sub_2A6E70(X86Context& ctx, uint8_t* base) {
	// 0x2A6E70: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A6E78: movss [0x005706BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5706BCu, ctx.xmm[0].u32[0]);
	// 0x2A6E80: ret
	return;
}

void sub_2A6E90(X86Context& ctx, uint8_t* base) {
	// 0x2A6E90: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A6E98: movss [0x00570668], xmm0
	X86_MEM_WRITE_u32(base, 0x570668u, ctx.xmm[0].u32[0]);
	// 0x2A6EA0: ret
	return;
}

void sub_2A6EB0(X86Context& ctx, uint8_t* base) {
	// 0x2A6EB0: movss xmm0, dword ptr [0x00570680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570680u);
	// 0x2A6EB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A6EC0: movss [0x0057065C], xmm0
	X86_MEM_WRITE_u32(base, 0x57065Cu, ctx.xmm[0].u32[0]);
	// 0x2A6EC8: ret
	return;
}

void sub_2A6ED0(X86Context& ctx, uint8_t* base) {
	// 0x2A6ED0: movss xmm0, dword ptr [0x005706DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706DCu);
	// 0x2A6ED8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A6EE0: movss [0x005706A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5706A4u, ctx.xmm[0].u32[0]);
	// 0x2A6EE8: ret
	return;
}

void sub_2A6EF0(X86Context& ctx, uint8_t* base) {
	// 0x2A6EF0: movss xmm0, dword ptr [0x0057065C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57065Cu);
	// 0x2A6EF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A6F00: movss [0x005706B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5706B4u, ctx.xmm[0].u32[0]);
	// 0x2A6F08: ret
	return;
}

void sub_2A6F10(X86Context& ctx, uint8_t* base) {
	// 0x2A6F10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A6F18: movss [0x00570654], xmm0
	X86_MEM_WRITE_u32(base, 0x570654u, ctx.xmm[0].u32[0]);
	// 0x2A6F20: ret
	return;
}

void sub_2A6F30(X86Context& ctx, uint8_t* base) {
	// 0x2A6F30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A6F38: movss [0x00570684], xmm0
	X86_MEM_WRITE_u32(base, 0x570684u, ctx.xmm[0].u32[0]);
	// 0x2A6F40: ret
	return;
}

void sub_2A6F50(X86Context& ctx, uint8_t* base) {
	// 0x2A6F50: movss xmm0, dword ptr [0x00570680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570680u);
	// 0x2A6F58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A6F60: movss [0x00570690], xmm0
	X86_MEM_WRITE_u32(base, 0x570690u, ctx.xmm[0].u32[0]);
	// 0x2A6F68: ret
	return;
}

void sub_2A6F70(X86Context& ctx, uint8_t* base) {
	// 0x2A6F70: movss xmm0, dword ptr [0x005706DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706DCu);
	// 0x2A6F78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A6F80: movss [0x005706E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5706E0u, ctx.xmm[0].u32[0]);
	// 0x2A6F88: ret
	return;
}

void sub_2A6F90(X86Context& ctx, uint8_t* base) {
	// 0x2A6F90: movss xmm0, dword ptr [0x00570690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570690u);
	// 0x2A6F98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6FA0: movss [0x005706CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5706CCu, ctx.xmm[0].u32[0]);
	// 0x2A6FA8: ret
	return;
}

void sub_2A6FB0(X86Context& ctx, uint8_t* base) {
	// 0x2A6FB0: movss xmm0, dword ptr [0x005706E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706E0u);
	// 0x2A6FB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A6FC0: movss [0x005706F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5706F0u, ctx.xmm[0].u32[0]);
	// 0x2A6FC8: ret
	return;
}

void sub_2A6FD0(X86Context& ctx, uint8_t* base) {
	// 0x2A6FD0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A6FD8: movss [0x00570660], xmm0
	X86_MEM_WRITE_u32(base, 0x570660u, ctx.xmm[0].u32[0]);
	// 0x2A6FE0: ret
	return;
}

void sub_2A6FF0(X86Context& ctx, uint8_t* base) {
	// 0x2A6FF0: movss xmm0, dword ptr [0x00570680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570680u);
	// 0x2A6FF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7000: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A7008: movss [0x005706D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5706D8u, ctx.xmm[0].u32[0]);
	// 0x2A7010: ret
	return;
}

void sub_2A7020(X86Context& ctx, uint8_t* base) {
	// 0x2A7020: movss xmm0, dword ptr [0x005706DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706DCu);
	// 0x2A7028: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7030: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A7038: movss [0x00570678], xmm0
	X86_MEM_WRITE_u32(base, 0x570678u, ctx.xmm[0].u32[0]);
	// 0x2A7040: ret
	return;
}

void sub_2A7050(X86Context& ctx, uint8_t* base) {
	// 0x2A7050: movss xmm0, dword ptr [0x00570680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570680u);
	// 0x2A7058: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7060: movss [0x0057067C], xmm0
	X86_MEM_WRITE_u32(base, 0x57067Cu, ctx.xmm[0].u32[0]);
	// 0x2A7068: ret
	return;
}

void sub_2A7070(X86Context& ctx, uint8_t* base) {
	// 0x2A7070: movss xmm0, dword ptr [0x005706DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706DCu);
	// 0x2A7078: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7080: movss [0x005706E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5706E4u, ctx.xmm[0].u32[0]);
	// 0x2A7088: ret
	return;
}

void sub_2A7090(X86Context& ctx, uint8_t* base) {
	// 0x2A7090: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A7098: movss [0x00570664], xmm0
	X86_MEM_WRITE_u32(base, 0x570664u, ctx.xmm[0].u32[0]);
	// 0x2A70A0: ret
	return;
}

void sub_2A70B0(X86Context& ctx, uint8_t* base) {
	// 0x2A70B0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A70B8: movss [0x0057068C], xmm0
	X86_MEM_WRITE_u32(base, 0x57068Cu, ctx.xmm[0].u32[0]);
	// 0x2A70C0: ret
	return;
}

void sub_2A70D0(X86Context& ctx, uint8_t* base) {
	// 0x2A70D0: movss xmm0, dword ptr [0x00570664]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570664u);
	// 0x2A70D8: movss [0x005706F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5706F8u, ctx.xmm[0].u32[0]);
	// 0x2A70E0: ret
	return;
}

void sub_2A70F0(X86Context& ctx, uint8_t* base) {
	// 0x2A70F0: movss xmm0, dword ptr [0x005706DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706DCu);
	// 0x2A70F8: subss xmm0, [0x00570664]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570664u);
	// 0x2A7100: movss [0x005706B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5706B8u, ctx.xmm[0].u32[0]);
	// 0x2A7108: ret
	return;
}

void sub_2A7110(X86Context& ctx, uint8_t* base) {
	// 0x2A7110: movss xmm0, dword ptr [0x005706B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706B8u);
	// 0x2A7118: subss xmm0, [0x0057068C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57068Cu);
	// 0x2A7120: movss [0x005706B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5706B0u, ctx.xmm[0].u32[0]);
	// 0x2A7128: ret
	return;
}

void sub_2A7130(X86Context& ctx, uint8_t* base) {
	// 0x2A7130: movss xmm0, dword ptr [0x005706E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5706E4u);
	// 0x2A7138: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A7140: movss [0x0057069C], xmm0
	X86_MEM_WRITE_u32(base, 0x57069Cu, ctx.xmm[0].u32[0]);
	// 0x2A7148: ret
	return;
}

void sub_2A7150(X86Context& ctx, uint8_t* base) {
	// 0x2A7150: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A7158: movss [0x00570688], xmm0
	X86_MEM_WRITE_u32(base, 0x570688u, ctx.xmm[0].u32[0]);
	// 0x2A7160: ret
	return;
}

void sub_2A7170(X86Context& ctx, uint8_t* base) {
	// 0x2A7170: movss xmm0, dword ptr [0x0057069C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57069Cu);
	// 0x2A7178: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A7180: movss [0x005706D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5706D4u, ctx.xmm[0].u32[0]);
	// 0x2A7188: ret
	return;
}

void sub_2A7190(X86Context& ctx, uint8_t* base) {
	// 0x2A7190: movss xmm0, dword ptr [0x00570680]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570680u);
	// 0x2A7198: movss [0x005706C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5706C0u, ctx.xmm[0].u32[0]);
	// 0x2A71A0: ret
	return;
}

void sub_2A71B0(X86Context& ctx, uint8_t* base) {
	// 0x2A71B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A71B8: movss [0x005706A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5706A0u, ctx.xmm[0].u32[0]);
	// 0x2A71C0: ret
	return;
}

void sub_2A71D0(X86Context& ctx, uint8_t* base) {
	// 0x2A71D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A71D8: movss [0x00570788], xmm0
	X86_MEM_WRITE_u32(base, 0x570788u, ctx.xmm[0].u32[0]);
	// 0x2A71E0: ret
	return;
}

void sub_2A71F0(X86Context& ctx, uint8_t* base) {
	// 0x2A71F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A71F8: movss [0x005707B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5707B4u, ctx.xmm[0].u32[0]);
	// 0x2A7200: ret
	return;
}

void sub_2A7210(X86Context& ctx, uint8_t* base) {
	// 0x2A7210: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A7218: movss [0x00570778], xmm0
	X86_MEM_WRITE_u32(base, 0x570778u, ctx.xmm[0].u32[0]);
	// 0x2A7220: ret
	return;
}

void sub_2A7230(X86Context& ctx, uint8_t* base) {
	// 0x2A7230: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A7238: movss [0x00570708], xmm0
	X86_MEM_WRITE_u32(base, 0x570708u, ctx.xmm[0].u32[0]);
	// 0x2A7240: ret
	return;
}

void sub_2A7250(X86Context& ctx, uint8_t* base) {
	// 0x2A7250: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A7258: movss [0x0057078C], xmm0
	X86_MEM_WRITE_u32(base, 0x57078Cu, ctx.xmm[0].u32[0]);
	// 0x2A7260: ret
	return;
}

void sub_2A7270(X86Context& ctx, uint8_t* base) {
	// 0x2A7270: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A7278: movss [0x00570728], xmm0
	X86_MEM_WRITE_u32(base, 0x570728u, ctx.xmm[0].u32[0]);
	// 0x2A7280: ret
	return;
}

void sub_2A7290(X86Context& ctx, uint8_t* base) {
	// 0x2A7290: movss xmm0, dword ptr [0x0057078C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57078Cu);
	// 0x2A7298: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A72A0: movss [0x005707E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5707E0u, ctx.xmm[0].u32[0]);
	// 0x2A72A8: ret
	return;
}

void sub_2A72B0(X86Context& ctx, uint8_t* base) {
	// 0x2A72B0: movss xmm0, dword ptr [0x00570728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570728u);
	// 0x2A72B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A72C0: movss [0x005707C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5707C4u, ctx.xmm[0].u32[0]);
	// 0x2A72C8: ret
	return;
}

void sub_2A72D0(X86Context& ctx, uint8_t* base) {
	// 0x2A72D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A72D8: movss [0x0057080C], xmm0
	X86_MEM_WRITE_u32(base, 0x57080Cu, ctx.xmm[0].u32[0]);
	// 0x2A72E0: ret
	return;
}

void sub_2A72F0(X86Context& ctx, uint8_t* base) {
	// 0x2A72F0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A72F8: movss [0x005707E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5707E4u, ctx.xmm[0].u32[0]);
	// 0x2A7300: ret
	return;
}

void sub_2A7310(X86Context& ctx, uint8_t* base) {
	// 0x2A7310: movss xmm0, dword ptr [0x005707E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707E4u);
	// 0x2A7318: movss [0x00570804], xmm0
	X86_MEM_WRITE_u32(base, 0x570804u, ctx.xmm[0].u32[0]);
	// 0x2A7320: ret
	return;
}

void sub_2A7330(X86Context& ctx, uint8_t* base) {
	// 0x2A7330: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A7338: movss [0x00570714], xmm0
	X86_MEM_WRITE_u32(base, 0x570714u, ctx.xmm[0].u32[0]);
	// 0x2A7340: ret
	return;
}

void sub_2A7350(X86Context& ctx, uint8_t* base) {
	// 0x2A7350: movss xmm0, dword ptr [0x00570728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570728u);
	// 0x2A7358: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A7360: movss [0x005707F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5707F8u, ctx.xmm[0].u32[0]);
	// 0x2A7368: ret
	return;
}

void sub_2A7370(X86Context& ctx, uint8_t* base) {
	// 0x2A7370: movss xmm0, dword ptr [0x00570728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570728u);
	// 0x2A7378: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A7380: movss [0x00570770], xmm0
	X86_MEM_WRITE_u32(base, 0x570770u, ctx.xmm[0].u32[0]);
	// 0x2A7388: ret
	return;
}

void sub_2A7390(X86Context& ctx, uint8_t* base) {
	// 0x2A7390: movss xmm0, dword ptr [0x00570728]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570728u);
	// 0x2A7398: subss xmm0, [0x00570770]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570770u);
	// 0x2A73A0: movss [0x00570738], xmm0
	X86_MEM_WRITE_u32(base, 0x570738u, ctx.xmm[0].u32[0]);
	// 0x2A73A8: ret
	return;
}

void sub_2A73B0(X86Context& ctx, uint8_t* base) {
	// 0x2A73B0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A73B8: movss [0x005707AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5707ACu, ctx.xmm[0].u32[0]);
	// 0x2A73C0: ret
	return;
}

void sub_2A73D0(X86Context& ctx, uint8_t* base) {
	// 0x2A73D0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A73D8: movss [0x00570734], xmm0
	X86_MEM_WRITE_u32(base, 0x570734u, ctx.xmm[0].u32[0]);
	// 0x2A73E0: ret
	return;
}

void sub_2A73F0(X86Context& ctx, uint8_t* base) {
	// 0x2A73F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A73F8: movss [0x00570750], xmm0
	X86_MEM_WRITE_u32(base, 0x570750u, ctx.xmm[0].u32[0]);
	// 0x2A7400: ret
	return;
}

void sub_2A7410(X86Context& ctx, uint8_t* base) {
	// 0x2A7410: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A7418: movss [0x005707D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5707D4u, ctx.xmm[0].u32[0]);
	// 0x2A7420: ret
	return;
}

void sub_2A7430(X86Context& ctx, uint8_t* base) {
	// 0x2A7430: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A7438: movss [0x005707A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5707A0u, ctx.xmm[0].u32[0]);
	// 0x2A7440: ret
	return;
}

void sub_2A7450(X86Context& ctx, uint8_t* base) {
	// 0x2A7450: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A7458: movss [0x00570724], xmm0
	X86_MEM_WRITE_u32(base, 0x570724u, ctx.xmm[0].u32[0]);
	// 0x2A7460: ret
	return;
}

void sub_2A7470(X86Context& ctx, uint8_t* base) {
	// 0x2A7470: movss xmm0, dword ptr [0x00570750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570750u);
	// 0x2A7478: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A7480: movss [0x00570718], xmm0
	X86_MEM_WRITE_u32(base, 0x570718u, ctx.xmm[0].u32[0]);
	// 0x2A7488: ret
	return;
}

void sub_2A7490(X86Context& ctx, uint8_t* base) {
	// 0x2A7490: movss xmm0, dword ptr [0x005707D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D4u);
	// 0x2A7498: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A74A0: movss [0x00570780], xmm0
	X86_MEM_WRITE_u32(base, 0x570780u, ctx.xmm[0].u32[0]);
	// 0x2A74A8: ret
	return;
}

void sub_2A74B0(X86Context& ctx, uint8_t* base) {
	// 0x2A74B0: movss xmm0, dword ptr [0x00570718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570718u);
	// 0x2A74B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A74C0: movss [0x00570794], xmm0
	X86_MEM_WRITE_u32(base, 0x570794u, ctx.xmm[0].u32[0]);
	// 0x2A74C8: ret
	return;
}

void sub_2A74D0(X86Context& ctx, uint8_t* base) {
	// 0x2A74D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A74D8: movss [0x0057070C], xmm0
	X86_MEM_WRITE_u32(base, 0x57070Cu, ctx.xmm[0].u32[0]);
	// 0x2A74E0: ret
	return;
}

void sub_2A74F0(X86Context& ctx, uint8_t* base) {
	// 0x2A74F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A74F8: movss [0x0057075C], xmm0
	X86_MEM_WRITE_u32(base, 0x57075Cu, ctx.xmm[0].u32[0]);
	// 0x2A7500: ret
	return;
}

void sub_2A7510(X86Context& ctx, uint8_t* base) {
	// 0x2A7510: movss xmm0, dword ptr [0x00570750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570750u);
	// 0x2A7518: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A7520: movss [0x0057076C], xmm0
	X86_MEM_WRITE_u32(base, 0x57076Cu, ctx.xmm[0].u32[0]);
	// 0x2A7528: ret
	return;
}

void sub_2A7530(X86Context& ctx, uint8_t* base) {
	// 0x2A7530: movss xmm0, dword ptr [0x005707D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D4u);
	// 0x2A7538: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A7540: movss [0x005707D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5707D8u, ctx.xmm[0].u32[0]);
	// 0x2A7548: ret
	return;
}

void sub_2A7550(X86Context& ctx, uint8_t* base) {
	// 0x2A7550: movss xmm0, dword ptr [0x0057076C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57076Cu);
	// 0x2A7558: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7560: movss [0x005707B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5707B8u, ctx.xmm[0].u32[0]);
	// 0x2A7568: ret
	return;
}

void sub_2A7570(X86Context& ctx, uint8_t* base) {
	// 0x2A7570: movss xmm0, dword ptr [0x005707D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D8u);
	// 0x2A7578: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7580: movss [0x005707E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5707E8u, ctx.xmm[0].u32[0]);
	// 0x2A7588: ret
	return;
}

void sub_2A7590(X86Context& ctx, uint8_t* base) {
	// 0x2A7590: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A7598: movss [0x0057071C], xmm0
	X86_MEM_WRITE_u32(base, 0x57071Cu, ctx.xmm[0].u32[0]);
	// 0x2A75A0: ret
	return;
}

void sub_2A75B0(X86Context& ctx, uint8_t* base) {
	// 0x2A75B0: movss xmm0, dword ptr [0x00570750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570750u);
	// 0x2A75B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A75C0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A75C8: movss [0x005707D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5707D0u, ctx.xmm[0].u32[0]);
	// 0x2A75D0: ret
	return;
}

void sub_2A75E0(X86Context& ctx, uint8_t* base) {
	// 0x2A75E0: movss xmm0, dword ptr [0x005707D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D4u);
	// 0x2A75E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A75F0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A75F8: movss [0x0057073C], xmm0
	X86_MEM_WRITE_u32(base, 0x57073Cu, ctx.xmm[0].u32[0]);
	// 0x2A7600: ret
	return;
}

void sub_2A7610(X86Context& ctx, uint8_t* base) {
	// 0x2A7610: movss xmm0, dword ptr [0x00570750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570750u);
	// 0x2A7618: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7620: movss [0x00570740], xmm0
	X86_MEM_WRITE_u32(base, 0x570740u, ctx.xmm[0].u32[0]);
	// 0x2A7628: ret
	return;
}

void sub_2A7630(X86Context& ctx, uint8_t* base) {
	// 0x2A7630: movss xmm0, dword ptr [0x005707D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D4u);
	// 0x2A7638: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7640: movss [0x005707DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5707DCu, ctx.xmm[0].u32[0]);
	// 0x2A7648: ret
	return;
}

void sub_2A7650(X86Context& ctx, uint8_t* base) {
	// 0x2A7650: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A7658: movss [0x00570720], xmm0
	X86_MEM_WRITE_u32(base, 0x570720u, ctx.xmm[0].u32[0]);
	// 0x2A7660: ret
	return;
}

void sub_2A7670(X86Context& ctx, uint8_t* base) {
	// 0x2A7670: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A7678: movss [0x00570768], xmm0
	X86_MEM_WRITE_u32(base, 0x570768u, ctx.xmm[0].u32[0]);
	// 0x2A7680: ret
	return;
}

void sub_2A7690(X86Context& ctx, uint8_t* base) {
	// 0x2A7690: movss xmm0, dword ptr [0x00570720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570720u);
	// 0x2A7698: movss [0x00570800], xmm0
	X86_MEM_WRITE_u32(base, 0x570800u, ctx.xmm[0].u32[0]);
	// 0x2A76A0: ret
	return;
}

void sub_2A76B0(X86Context& ctx, uint8_t* base) {
	// 0x2A76B0: movss xmm0, dword ptr [0x005707D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D4u);
	// 0x2A76B8: subss xmm0, [0x00570720]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570720u);
	// 0x2A76C0: movss [0x0057079C], xmm0
	X86_MEM_WRITE_u32(base, 0x57079Cu, ctx.xmm[0].u32[0]);
	// 0x2A76C8: ret
	return;
}

void sub_2A76D0(X86Context& ctx, uint8_t* base) {
	// 0x2A76D0: movss xmm0, dword ptr [0x0057079C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57079Cu);
	// 0x2A76D8: subss xmm0, [0x00570768]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570768u);
	// 0x2A76E0: movss [0x00570790], xmm0
	X86_MEM_WRITE_u32(base, 0x570790u, ctx.xmm[0].u32[0]);
	// 0x2A76E8: ret
	return;
}

void sub_2A76F0(X86Context& ctx, uint8_t* base) {
	// 0x2A76F0: movss xmm0, dword ptr [0x005707DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707DCu);
	// 0x2A76F8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A7700: movss [0x0057077C], xmm0
	X86_MEM_WRITE_u32(base, 0x57077Cu, ctx.xmm[0].u32[0]);
	// 0x2A7708: ret
	return;
}

void sub_2A7710(X86Context& ctx, uint8_t* base) {
	// 0x2A7710: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A7718: movss [0x00570764], xmm0
	X86_MEM_WRITE_u32(base, 0x570764u, ctx.xmm[0].u32[0]);
	// 0x2A7720: ret
	return;
}

void sub_2A7730(X86Context& ctx, uint8_t* base) {
	// 0x2A7730: movss xmm0, dword ptr [0x0057077C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57077Cu);
	// 0x2A7738: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A7740: movss [0x005707C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5707C8u, ctx.xmm[0].u32[0]);
	// 0x2A7748: ret
	return;
}

void sub_2A7750(X86Context& ctx, uint8_t* base) {
	// 0x2A7750: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2A7758: movss [0x00570784], xmm0
	X86_MEM_WRITE_u32(base, 0x570784u, ctx.xmm[0].u32[0]);
	// 0x2A7760: ret
	return;
}

void sub_2A7770(X86Context& ctx, uint8_t* base) {
	// 0x2A7770: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2A7778: movss [0x0057074C], xmm0
	X86_MEM_WRITE_u32(base, 0x57074Cu, ctx.xmm[0].u32[0]);
	// 0x2A7780: ret
	return;
}

void sub_2A7790(X86Context& ctx, uint8_t* base) {
	// 0x2A7790: movss xmm0, dword ptr [0x00570750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570750u);
	// 0x2A7798: movss [0x00570730], xmm0
	X86_MEM_WRITE_u32(base, 0x570730u, ctx.xmm[0].u32[0]);
	// 0x2A77A0: ret
	return;
}

void sub_2A77B0(X86Context& ctx, uint8_t* base) {
	// 0x2A77B0: movss xmm0, dword ptr [0x00395BE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE0u);
	// 0x2A77B8: movss [0x00570704], xmm0
	X86_MEM_WRITE_u32(base, 0x570704u, ctx.xmm[0].u32[0]);
	// 0x2A77C0: ret
	return;
}

void sub_2A77D0(X86Context& ctx, uint8_t* base) {
	// 0x2A77D0: movss xmm0, dword ptr [0x00570718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570718u);
	// 0x2A77D8: subss xmm0, [0x003B22A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B22A4u);
	// 0x2A77E0: movss [0x0057072C], xmm0
	X86_MEM_WRITE_u32(base, 0x57072Cu, ctx.xmm[0].u32[0]);
	// 0x2A77E8: ret
	return;
}

void sub_2A77F0(X86Context& ctx, uint8_t* base) {
	// 0x2A77F0: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x2A77F8: movss [0x00570758], xmm0
	X86_MEM_WRITE_u32(base, 0x570758u, ctx.xmm[0].u32[0]);
	// 0x2A7800: ret
	return;
}

void sub_2A7810(X86Context& ctx, uint8_t* base) {
	// 0x2A7810: movss xmm0, dword ptr [0x003B22A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22A8u);
	// 0x2A7818: movss [0x005707EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5707ECu, ctx.xmm[0].u32[0]);
	// 0x2A7820: ret
	return;
}

void sub_2A7830(X86Context& ctx, uint8_t* base) {
	// 0x2A7830: movss xmm0, dword ptr [0x003B2068]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2068u);
	// 0x2A7838: movss [0x005707B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5707B0u, ctx.xmm[0].u32[0]);
	// 0x2A7840: ret
	return;
}

void sub_2A7850(X86Context& ctx, uint8_t* base) {
	// 0x2A7850: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2A7853: movss [0x00570748], xmm0
	X86_MEM_WRITE_u32(base, 0x570748u, ctx.xmm[0].u32[0]);
	// 0x2A785B: ret
	return;
}

void sub_2A7860(X86Context& ctx, uint8_t* base) {
	// 0x2A7860: movss xmm0, dword ptr [0x00570758]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570758u);
	// 0x2A7868: addss xmm0, [0x005707EC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x5707ECu);
	// 0x2A7870: subss xmm0, [0x003A35C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A35C4u);
	// 0x2A7878: movss [0x00570798], xmm0
	X86_MEM_WRITE_u32(base, 0x570798u, ctx.xmm[0].u32[0]);
	// 0x2A7880: ret
	return;
}

void sub_2A7890(X86Context& ctx, uint8_t* base) {
	// 0x2A7890: movss xmm0, dword ptr [0x00570758]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570758u);
	// 0x2A7898: addss xmm0, [0x005707EC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x5707ECu);
	// 0x2A78A0: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A78A8: movss [0x005707A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5707A8u, ctx.xmm[0].u32[0]);
	// 0x2A78B0: ret
	return;
}

void sub_2A78C0(X86Context& ctx, uint8_t* base) {
	// 0x2A78C0: movss xmm0, dword ptr [0x00570750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570750u);
	// 0x2A78C8: movss [0x005707F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5707F4u, ctx.xmm[0].u32[0]);
	// 0x2A78D0: ret
	return;
}

void sub_2A78E0(X86Context& ctx, uint8_t* base) {
	// 0x2A78E0: movss xmm0, dword ptr [0x005707D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707D4u);
	// 0x2A78E8: movss [0x00570774], xmm0
	X86_MEM_WRITE_u32(base, 0x570774u, ctx.xmm[0].u32[0]);
	// 0x2A78F0: ret
	return;
}

void sub_2A7900(X86Context& ctx, uint8_t* base) {
	// 0x2A7900: movss xmm0, dword ptr [0x00570718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570718u);
	// 0x2A7908: movss [0x00570710], xmm0
	X86_MEM_WRITE_u32(base, 0x570710u, ctx.xmm[0].u32[0]);
	// 0x2A7910: ret
	return;
}

void sub_2A7920(X86Context& ctx, uint8_t* base) {
	// 0x2A7920: movss xmm0, dword ptr [0x00570710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570710u);
	// 0x2A7928: subss xmm0, [0x003A49FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A49FCu);
	// 0x2A7930: movss [0x00570760], xmm0
	X86_MEM_WRITE_u32(base, 0x570760u, ctx.xmm[0].u32[0]);
	// 0x2A7938: ret
	return;
}

void sub_2A7940(X86Context& ctx, uint8_t* base) {
	// 0x2A7940: movss xmm0, dword ptr [0x003B22AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B22ACu);
	// 0x2A7948: movss [0x005707F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5707F0u, ctx.xmm[0].u32[0]);
	// 0x2A7950: ret
	return;
}

void sub_2A7960(X86Context& ctx, uint8_t* base) {
	// 0x2A7960: movss xmm0, dword ptr [0x00570718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570718u);
	// 0x2A7968: subss xmm0, [0x003A2928]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A2928u);
	// 0x2A7970: movss [0x005707CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5707CCu, ctx.xmm[0].u32[0]);
	// 0x2A7978: ret
	return;
}

void sub_2A7980(X86Context& ctx, uint8_t* base) {
	// 0x2A7980: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2A7988: movss [0x005707A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5707A4u, ctx.xmm[0].u32[0]);
	// 0x2A7990: ret
	return;
}

void sub_2A79A0(X86Context& ctx, uint8_t* base) {
	// 0x2A79A0: movss xmm0, dword ptr [0x005707A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5707A4u);
	// 0x2A79A8: subss xmm0, [0x005707CC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5707CCu);
	// 0x2A79B0: movss [0x00570808], xmm0
	X86_MEM_WRITE_u32(base, 0x570808u, ctx.xmm[0].u32[0]);
	// 0x2A79B8: ret
	return;
}

void sub_2A79C0(X86Context& ctx, uint8_t* base) {
	// 0x2A79C0: movss xmm0, dword ptr [0x00388F08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388F08u);
	// 0x2A79C8: movss [0x005707C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5707C0u, ctx.xmm[0].u32[0]);
	// 0x2A79D0: ret
	return;
}

void sub_2A79E0(X86Context& ctx, uint8_t* base) {
	// 0x2A79E0: movss xmm0, dword ptr [0x00388F08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388F08u);
	// 0x2A79E8: movss [0x005707FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5707FCu, ctx.xmm[0].u32[0]);
	// 0x2A79F0: ret
	return;
}

void sub_2A7A00(X86Context& ctx, uint8_t* base) {
	// 0x2A7A00: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2A7A08: movss [0x005707BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5707BCu, ctx.xmm[0].u32[0]);
	// 0x2A7A10: ret
	return;
}

void sub_2A7A20(X86Context& ctx, uint8_t* base) {
	// 0x2A7A20: movss xmm0, dword ptr [0x003B2068]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2068u);
	// 0x2A7A28: movss [0x00570744], xmm0
	X86_MEM_WRITE_u32(base, 0x570744u, ctx.xmm[0].u32[0]);
	// 0x2A7A30: ret
	return;
}

void sub_2A7A40(X86Context& ctx, uint8_t* base) {
	// 0x2A7A40: movss xmm0, dword ptr [0x003B178C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B178Cu);
	// 0x2A7A48: movss [0x00570754], xmm0
	X86_MEM_WRITE_u32(base, 0x570754u, ctx.xmm[0].u32[0]);
	// 0x2A7A50: ret
	return;
}

void sub_2A7A60(X86Context& ctx, uint8_t* base) {
	// 0x2A7A60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A7A68: movss [0x00570870], xmm0
	X86_MEM_WRITE_u32(base, 0x570870u, ctx.xmm[0].u32[0]);
	// 0x2A7A70: ret
	return;
}

void sub_2A7A80(X86Context& ctx, uint8_t* base) {
	// 0x2A7A80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A7A88: movss [0x00570890], xmm0
	X86_MEM_WRITE_u32(base, 0x570890u, ctx.xmm[0].u32[0]);
	// 0x2A7A90: ret
	return;
}

void sub_2A7AA0(X86Context& ctx, uint8_t* base) {
	// 0x2A7AA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A7AA8: movss [0x00570860], xmm0
	X86_MEM_WRITE_u32(base, 0x570860u, ctx.xmm[0].u32[0]);
	// 0x2A7AB0: ret
	return;
}

void sub_2A7AC0(X86Context& ctx, uint8_t* base) {
	// 0x2A7AC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A7AC8: movss [0x00570810], xmm0
	X86_MEM_WRITE_u32(base, 0x570810u, ctx.xmm[0].u32[0]);
	// 0x2A7AD0: ret
	return;
}

void sub_2A7AE0(X86Context& ctx, uint8_t* base) {
	// 0x2A7AE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A7AE8: movss [0x00570874], xmm0
	X86_MEM_WRITE_u32(base, 0x570874u, ctx.xmm[0].u32[0]);
	// 0x2A7AF0: ret
	return;
}

void sub_2A7B00(X86Context& ctx, uint8_t* base) {
	// 0x2A7B00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A7B08: movss [0x00570830], xmm0
	X86_MEM_WRITE_u32(base, 0x570830u, ctx.xmm[0].u32[0]);
	// 0x2A7B10: ret
	return;
}

void sub_2A7B20(X86Context& ctx, uint8_t* base) {
	// 0x2A7B20: movss xmm0, dword ptr [0x00570874]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570874u);
	// 0x2A7B28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A7B30: movss [0x005708B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5708B0u, ctx.xmm[0].u32[0]);
	// 0x2A7B38: ret
	return;
}

void sub_2A7B40(X86Context& ctx, uint8_t* base) {
	// 0x2A7B40: movss xmm0, dword ptr [0x00570830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570830u);
	// 0x2A7B48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A7B50: movss [0x00570898], xmm0
	X86_MEM_WRITE_u32(base, 0x570898u, ctx.xmm[0].u32[0]);
	// 0x2A7B58: ret
	return;
}

void sub_2A7B60(X86Context& ctx, uint8_t* base) {
	// 0x2A7B60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A7B68: movss [0x005708CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5708CCu, ctx.xmm[0].u32[0]);
	// 0x2A7B70: ret
	return;
}

void sub_2A7B80(X86Context& ctx, uint8_t* base) {
	// 0x2A7B80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A7B88: movss [0x005708B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5708B4u, ctx.xmm[0].u32[0]);
	// 0x2A7B90: ret
	return;
}

void sub_2A7BA0(X86Context& ctx, uint8_t* base) {
	// 0x2A7BA0: movss xmm0, dword ptr [0x005708B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708B4u);
	// 0x2A7BA8: movss [0x005708C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5708C8u, ctx.xmm[0].u32[0]);
	// 0x2A7BB0: ret
	return;
}

void sub_2A7BC0(X86Context& ctx, uint8_t* base) {
	// 0x2A7BC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A7BC8: movss [0x0057081C], xmm0
	X86_MEM_WRITE_u32(base, 0x57081Cu, ctx.xmm[0].u32[0]);
	// 0x2A7BD0: ret
	return;
}

void sub_2A7BE0(X86Context& ctx, uint8_t* base) {
	// 0x2A7BE0: movss xmm0, dword ptr [0x00570830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570830u);
	// 0x2A7BE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A7BF0: movss [0x005708BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5708BCu, ctx.xmm[0].u32[0]);
	// 0x2A7BF8: ret
	return;
}

void sub_2A7C00(X86Context& ctx, uint8_t* base) {
	// 0x2A7C00: movss xmm0, dword ptr [0x00570830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570830u);
	// 0x2A7C08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A7C10: movss [0x0057085C], xmm0
	X86_MEM_WRITE_u32(base, 0x57085Cu, ctx.xmm[0].u32[0]);
	// 0x2A7C18: ret
	return;
}

void sub_2A7C20(X86Context& ctx, uint8_t* base) {
	// 0x2A7C20: movss xmm0, dword ptr [0x00570830]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570830u);
	// 0x2A7C28: subss xmm0, [0x0057085C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57085Cu);
	// 0x2A7C30: movss [0x00570838], xmm0
	X86_MEM_WRITE_u32(base, 0x570838u, ctx.xmm[0].u32[0]);
	// 0x2A7C38: ret
	return;
}

void sub_2A7C40(X86Context& ctx, uint8_t* base) {
	// 0x2A7C40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A7C48: movss [0x0057088C], xmm0
	X86_MEM_WRITE_u32(base, 0x57088Cu, ctx.xmm[0].u32[0]);
	// 0x2A7C50: ret
	return;
}

void sub_2A7C60(X86Context& ctx, uint8_t* base) {
	// 0x2A7C60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A7C68: movss [0x00570834], xmm0
	X86_MEM_WRITE_u32(base, 0x570834u, ctx.xmm[0].u32[0]);
	// 0x2A7C70: ret
	return;
}

void sub_2A7C80(X86Context& ctx, uint8_t* base) {
	// 0x2A7C80: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A7C88: movss [0x00570844], xmm0
	X86_MEM_WRITE_u32(base, 0x570844u, ctx.xmm[0].u32[0]);
	// 0x2A7C90: ret
	return;
}

void sub_2A7CA0(X86Context& ctx, uint8_t* base) {
	// 0x2A7CA0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A7CA8: movss [0x005708A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5708A4u, ctx.xmm[0].u32[0]);
	// 0x2A7CB0: ret
	return;
}

void sub_2A7CC0(X86Context& ctx, uint8_t* base) {
	// 0x2A7CC0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A7CC8: movss [0x00570888], xmm0
	X86_MEM_WRITE_u32(base, 0x570888u, ctx.xmm[0].u32[0]);
	// 0x2A7CD0: ret
	return;
}

void sub_2A7CE0(X86Context& ctx, uint8_t* base) {
	// 0x2A7CE0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A7CE8: movss [0x0057082C], xmm0
	X86_MEM_WRITE_u32(base, 0x57082Cu, ctx.xmm[0].u32[0]);
	// 0x2A7CF0: ret
	return;
}

void sub_2A7D00(X86Context& ctx, uint8_t* base) {
	// 0x2A7D00: movss xmm0, dword ptr [0x00570844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570844u);
	// 0x2A7D08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A7D10: movss [0x00570820], xmm0
	X86_MEM_WRITE_u32(base, 0x570820u, ctx.xmm[0].u32[0]);
	// 0x2A7D18: ret
	return;
}

void sub_2A7D20(X86Context& ctx, uint8_t* base) {
	// 0x2A7D20: movss xmm0, dword ptr [0x005708A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A4u);
	// 0x2A7D28: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A7D30: movss [0x0057086C], xmm0
	X86_MEM_WRITE_u32(base, 0x57086Cu, ctx.xmm[0].u32[0]);
	// 0x2A7D38: ret
	return;
}

void sub_2A7D40(X86Context& ctx, uint8_t* base) {
	// 0x2A7D40: movss xmm0, dword ptr [0x00570820]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570820u);
	// 0x2A7D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A7D50: movss [0x00570880], xmm0
	X86_MEM_WRITE_u32(base, 0x570880u, ctx.xmm[0].u32[0]);
	// 0x2A7D58: ret
	return;
}

void sub_2A7D60(X86Context& ctx, uint8_t* base) {
	// 0x2A7D60: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A7D68: movss [0x00570818], xmm0
	X86_MEM_WRITE_u32(base, 0x570818u, ctx.xmm[0].u32[0]);
	// 0x2A7D70: ret
	return;
}

void sub_2A7D80(X86Context& ctx, uint8_t* base) {
	// 0x2A7D80: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A7D88: movss [0x0057084C], xmm0
	X86_MEM_WRITE_u32(base, 0x57084Cu, ctx.xmm[0].u32[0]);
	// 0x2A7D90: ret
	return;
}

void sub_2A7DA0(X86Context& ctx, uint8_t* base) {
	// 0x2A7DA0: movss xmm0, dword ptr [0x00570844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570844u);
	// 0x2A7DA8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A7DB0: movss [0x00570858], xmm0
	X86_MEM_WRITE_u32(base, 0x570858u, ctx.xmm[0].u32[0]);
	// 0x2A7DB8: ret
	return;
}

void sub_2A7DC0(X86Context& ctx, uint8_t* base) {
	// 0x2A7DC0: movss xmm0, dword ptr [0x005708A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A4u);
	// 0x2A7DC8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A7DD0: movss [0x005708A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5708A8u, ctx.xmm[0].u32[0]);
	// 0x2A7DD8: ret
	return;
}

void sub_2A7DE0(X86Context& ctx, uint8_t* base) {
	// 0x2A7DE0: movss xmm0, dword ptr [0x00570858]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570858u);
	// 0x2A7DE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7DF0: movss [0x00570894], xmm0
	X86_MEM_WRITE_u32(base, 0x570894u, ctx.xmm[0].u32[0]);
	// 0x2A7DF8: ret
	return;
}

void sub_2A7E00(X86Context& ctx, uint8_t* base) {
	// 0x2A7E00: movss xmm0, dword ptr [0x005708A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A8u);
	// 0x2A7E08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7E10: movss [0x005708B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5708B8u, ctx.xmm[0].u32[0]);
	// 0x2A7E18: ret
	return;
}

void sub_2A7E20(X86Context& ctx, uint8_t* base) {
	// 0x2A7E20: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A7E28: movss [0x00570824], xmm0
	X86_MEM_WRITE_u32(base, 0x570824u, ctx.xmm[0].u32[0]);
	// 0x2A7E30: ret
	return;
}

void sub_2A7E40(X86Context& ctx, uint8_t* base) {
	// 0x2A7E40: movss xmm0, dword ptr [0x00570844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570844u);
	// 0x2A7E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7E50: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A7E58: movss [0x005708A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5708A0u, ctx.xmm[0].u32[0]);
	// 0x2A7E60: ret
	return;
}

void sub_2A7E70(X86Context& ctx, uint8_t* base) {
	// 0x2A7E70: movss xmm0, dword ptr [0x005708A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A4u);
	// 0x2A7E78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7E80: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A7E88: movss [0x0057083C], xmm0
	X86_MEM_WRITE_u32(base, 0x57083Cu, ctx.xmm[0].u32[0]);
	// 0x2A7E90: ret
	return;
}

void sub_2A7EA0(X86Context& ctx, uint8_t* base) {
	// 0x2A7EA0: movss xmm0, dword ptr [0x00570844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570844u);
	// 0x2A7EA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7EB0: movss [0x00570840], xmm0
	X86_MEM_WRITE_u32(base, 0x570840u, ctx.xmm[0].u32[0]);
	// 0x2A7EB8: ret
	return;
}

void sub_2A7EC0(X86Context& ctx, uint8_t* base) {
	// 0x2A7EC0: movss xmm0, dword ptr [0x005708A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A4u);
	// 0x2A7EC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A7ED0: movss [0x005708AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5708ACu, ctx.xmm[0].u32[0]);
	// 0x2A7ED8: ret
	return;
}

void sub_2A7EE0(X86Context& ctx, uint8_t* base) {
	// 0x2A7EE0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A7EE8: movss [0x00570828], xmm0
	X86_MEM_WRITE_u32(base, 0x570828u, ctx.xmm[0].u32[0]);
	// 0x2A7EF0: ret
	return;
}

void sub_2A7F00(X86Context& ctx, uint8_t* base) {
	// 0x2A7F00: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A7F08: movss [0x00570854], xmm0
	X86_MEM_WRITE_u32(base, 0x570854u, ctx.xmm[0].u32[0]);
	// 0x2A7F10: ret
	return;
}

void sub_2A7F20(X86Context& ctx, uint8_t* base) {
	// 0x2A7F20: movss xmm0, dword ptr [0x00570828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570828u);
	// 0x2A7F28: movss [0x005708C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5708C0u, ctx.xmm[0].u32[0]);
	// 0x2A7F30: ret
	return;
}

void sub_2A7F40(X86Context& ctx, uint8_t* base) {
	// 0x2A7F40: movss xmm0, dword ptr [0x005708A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A4u);
	// 0x2A7F48: subss xmm0, [0x00570828]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570828u);
	// 0x2A7F50: movss [0x00570884], xmm0
	X86_MEM_WRITE_u32(base, 0x570884u, ctx.xmm[0].u32[0]);
	// 0x2A7F58: ret
	return;
}

void sub_2A7F60(X86Context& ctx, uint8_t* base) {
	// 0x2A7F60: movss xmm0, dword ptr [0x00570884]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570884u);
	// 0x2A7F68: subss xmm0, [0x00570854]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570854u);
	// 0x2A7F70: movss [0x00570878], xmm0
	X86_MEM_WRITE_u32(base, 0x570878u, ctx.xmm[0].u32[0]);
	// 0x2A7F78: ret
	return;
}

void sub_2A7F80(X86Context& ctx, uint8_t* base) {
	// 0x2A7F80: movss xmm0, dword ptr [0x005708AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708ACu);
	// 0x2A7F88: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A7F90: movss [0x00570864], xmm0
	X86_MEM_WRITE_u32(base, 0x570864u, ctx.xmm[0].u32[0]);
	// 0x2A7F98: ret
	return;
}

void sub_2A7FA0(X86Context& ctx, uint8_t* base) {
	// 0x2A7FA0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A7FA8: movss [0x00570850], xmm0
	X86_MEM_WRITE_u32(base, 0x570850u, ctx.xmm[0].u32[0]);
	// 0x2A7FB0: ret
	return;
}

void sub_2A7FC0(X86Context& ctx, uint8_t* base) {
	// 0x2A7FC0: movss xmm0, dword ptr [0x00570864]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570864u);
	// 0x2A7FC8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A7FD0: movss [0x0057089C], xmm0
	X86_MEM_WRITE_u32(base, 0x57089Cu, ctx.xmm[0].u32[0]);
	// 0x2A7FD8: ret
	return;
}

void sub_2A7FE0(X86Context& ctx, uint8_t* base) {
	// 0x2A7FE0: movss xmm0, dword ptr [0x00570844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570844u);
	// 0x2A7FE8: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2A7FF0: movss [0x00570868], xmm0
	X86_MEM_WRITE_u32(base, 0x570868u, ctx.xmm[0].u32[0]);
	// 0x2A7FF8: ret
	return;
}

void sub_2A8000(X86Context& ctx, uint8_t* base) {
	// 0x2A8000: movss xmm0, dword ptr [0x005708A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708A4u);
	// 0x2A8008: subss xmm0, [0x003B17E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B17E4u);
	// 0x2A8010: movss [0x00570848], xmm0
	X86_MEM_WRITE_u32(base, 0x570848u, ctx.xmm[0].u32[0]);
	// 0x2A8018: ret
	return;
}

void sub_2A8020(X86Context& ctx, uint8_t* base) {
	// 0x2A8020: movss xmm0, dword ptr [0x00570844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570844u);
	// 0x2A8028: subss xmm0, [0x003B17C8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B17C8u);
	// 0x2A8030: movss [0x0057087C], xmm0
	X86_MEM_WRITE_u32(base, 0x57087Cu, ctx.xmm[0].u32[0]);
	// 0x2A8038: ret
	return;
}

void sub_2A8040(X86Context& ctx, uint8_t* base) {
	// 0x2A8040: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2A8048: divss xmm0, [0x0057087C]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x57087Cu);
	// 0x2A8050: movss [0x00407300], xmm0
	X86_MEM_WRITE_u32(base, 0x407300u, ctx.xmm[0].u32[0]);
	// 0x2A8058: ret
	return;
}

void sub_2A8060(X86Context& ctx, uint8_t* base) {
	// 0x2A8060: movss xmm0, dword ptr [0x003B16EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16ECu);
	// 0x2A8068: movss [0x005708C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5708C4u, ctx.xmm[0].u32[0]);
	// 0x2A8070: ret
	return;
}

void sub_2A8080(X86Context& ctx, uint8_t* base) {
	// 0x2A8080: movss xmm0, dword ptr [0x003B16E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16E8u);
	// 0x2A8088: movss [0x00570814], xmm0
	X86_MEM_WRITE_u32(base, 0x570814u, ctx.xmm[0].u32[0]);
	// 0x2A8090: ret
	return;
}

void sub_2A80A0(X86Context& ctx, uint8_t* base) {
	// 0x2A80A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A80A8: movss [0x00570924], xmm0
	X86_MEM_WRITE_u32(base, 0x570924u, ctx.xmm[0].u32[0]);
	// 0x2A80B0: ret
	return;
}

void sub_2A80C0(X86Context& ctx, uint8_t* base) {
	// 0x2A80C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A80C8: movss [0x00570944], xmm0
	X86_MEM_WRITE_u32(base, 0x570944u, ctx.xmm[0].u32[0]);
	// 0x2A80D0: ret
	return;
}

void sub_2A80E0(X86Context& ctx, uint8_t* base) {
	// 0x2A80E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A80E8: movss [0x00570918], xmm0
	X86_MEM_WRITE_u32(base, 0x570918u, ctx.xmm[0].u32[0]);
	// 0x2A80F0: ret
	return;
}

void sub_2A8100(X86Context& ctx, uint8_t* base) {
	// 0x2A8100: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A8108: movss [0x005708D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5708D0u, ctx.xmm[0].u32[0]);
	// 0x2A8110: ret
	return;
}

void sub_2A8120(X86Context& ctx, uint8_t* base) {
	// 0x2A8120: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A8128: movss [0x00570928], xmm0
	X86_MEM_WRITE_u32(base, 0x570928u, ctx.xmm[0].u32[0]);
	// 0x2A8130: ret
	return;
}

void sub_2A8140(X86Context& ctx, uint8_t* base) {
	// 0x2A8140: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A8148: movss [0x005708EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5708ECu, ctx.xmm[0].u32[0]);
	// 0x2A8150: ret
	return;
}

void sub_2A8160(X86Context& ctx, uint8_t* base) {
	// 0x2A8160: movss xmm0, dword ptr [0x00570928]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570928u);
	// 0x2A8168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8170: movss [0x00570964], xmm0
	X86_MEM_WRITE_u32(base, 0x570964u, ctx.xmm[0].u32[0]);
	// 0x2A8178: ret
	return;
}

void sub_2A8180(X86Context& ctx, uint8_t* base) {
	// 0x2A8180: movss xmm0, dword ptr [0x005708EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708ECu);
	// 0x2A8188: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A8190: movss [0x0057094C], xmm0
	X86_MEM_WRITE_u32(base, 0x57094Cu, ctx.xmm[0].u32[0]);
	// 0x2A8198: ret
	return;
}

void sub_2A81A0(X86Context& ctx, uint8_t* base) {
	// 0x2A81A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A81A8: movss [0x0057097C], xmm0
	X86_MEM_WRITE_u32(base, 0x57097Cu, ctx.xmm[0].u32[0]);
	// 0x2A81B0: ret
	return;
}

void sub_2A81C0(X86Context& ctx, uint8_t* base) {
	// 0x2A81C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A81C8: movss [0x00570968], xmm0
	X86_MEM_WRITE_u32(base, 0x570968u, ctx.xmm[0].u32[0]);
	// 0x2A81D0: ret
	return;
}

void sub_2A81E0(X86Context& ctx, uint8_t* base) {
	// 0x2A81E0: movss xmm0, dword ptr [0x00570968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570968u);
	// 0x2A81E8: movss [0x00570978], xmm0
	X86_MEM_WRITE_u32(base, 0x570978u, ctx.xmm[0].u32[0]);
	// 0x2A81F0: ret
	return;
}

void sub_2A8200(X86Context& ctx, uint8_t* base) {
	// 0x2A8200: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A8208: movss [0x005708D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5708D8u, ctx.xmm[0].u32[0]);
	// 0x2A8210: ret
	return;
}

void sub_2A8220(X86Context& ctx, uint8_t* base) {
	// 0x2A8220: movss xmm0, dword ptr [0x005708EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708ECu);
	// 0x2A8228: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A8230: movss [0x00570970], xmm0
	X86_MEM_WRITE_u32(base, 0x570970u, ctx.xmm[0].u32[0]);
	// 0x2A8238: ret
	return;
}

void sub_2A8240(X86Context& ctx, uint8_t* base) {
	// 0x2A8240: movss xmm0, dword ptr [0x005708EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708ECu);
	// 0x2A8248: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2A8250: movss [0x00570914], xmm0
	X86_MEM_WRITE_u32(base, 0x570914u, ctx.xmm[0].u32[0]);
	// 0x2A8258: ret
	return;
}

void sub_2A8260(X86Context& ctx, uint8_t* base) {
	// 0x2A8260: movss xmm0, dword ptr [0x005708EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708ECu);
	// 0x2A8268: subss xmm0, [0x00570914]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x570914u);
	// 0x2A8270: movss [0x005708F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5708F4u, ctx.xmm[0].u32[0]);
	// 0x2A8278: ret
	return;
}

void sub_2A8280(X86Context& ctx, uint8_t* base) {
	// 0x2A8280: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2A8288: movss [0x00570940], xmm0
	X86_MEM_WRITE_u32(base, 0x570940u, ctx.xmm[0].u32[0]);
	// 0x2A8290: ret
	return;
}

void sub_2A82A0(X86Context& ctx, uint8_t* base) {
	// 0x2A82A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2A82A8: movss [0x005708F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5708F0u, ctx.xmm[0].u32[0]);
	// 0x2A82B0: ret
	return;
}

void sub_2A82C0(X86Context& ctx, uint8_t* base) {
	// 0x2A82C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A82C8: movss [0x00570900], xmm0
	X86_MEM_WRITE_u32(base, 0x570900u, ctx.xmm[0].u32[0]);
	// 0x2A82D0: ret
	return;
}

void sub_2A82E0(X86Context& ctx, uint8_t* base) {
	// 0x2A82E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A82E8: movss [0x00570958], xmm0
	X86_MEM_WRITE_u32(base, 0x570958u, ctx.xmm[0].u32[0]);
	// 0x2A82F0: ret
	return;
}

void sub_2A8300(X86Context& ctx, uint8_t* base) {
	// 0x2A8300: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2A8308: movss [0x0057093C], xmm0
	X86_MEM_WRITE_u32(base, 0x57093Cu, ctx.xmm[0].u32[0]);
	// 0x2A8310: ret
	return;
}

void sub_2A8320(X86Context& ctx, uint8_t* base) {
	// 0x2A8320: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2A8328: movss [0x005708E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5708E8u, ctx.xmm[0].u32[0]);
	// 0x2A8330: ret
	return;
}

void sub_2A8340(X86Context& ctx, uint8_t* base) {
	// 0x2A8340: movss xmm0, dword ptr [0x00570900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570900u);
	// 0x2A8348: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8350: movss [0x005708DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5708DCu, ctx.xmm[0].u32[0]);
	// 0x2A8358: ret
	return;
}

void sub_2A8360(X86Context& ctx, uint8_t* base) {
	// 0x2A8360: movss xmm0, dword ptr [0x00570958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570958u);
	// 0x2A8368: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A8370: movss [0x00570920], xmm0
	X86_MEM_WRITE_u32(base, 0x570920u, ctx.xmm[0].u32[0]);
	// 0x2A8378: ret
	return;
}

void sub_2A8380(X86Context& ctx, uint8_t* base) {
	// 0x2A8380: movss xmm0, dword ptr [0x005708DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708DCu);
	// 0x2A8388: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8390: movss [0x00570930], xmm0
	X86_MEM_WRITE_u32(base, 0x570930u, ctx.xmm[0].u32[0]);
	// 0x2A8398: ret
	return;
}

void sub_2A83A0(X86Context& ctx, uint8_t* base) {
	// 0x2A83A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A83A8: movss [0x005708D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5708D4u, ctx.xmm[0].u32[0]);
	// 0x2A83B0: ret
	return;
}

void sub_2A83C0(X86Context& ctx, uint8_t* base) {
	// 0x2A83C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2A83C8: movss [0x00570904], xmm0
	X86_MEM_WRITE_u32(base, 0x570904u, ctx.xmm[0].u32[0]);
	// 0x2A83D0: ret
	return;
}

void sub_2A83E0(X86Context& ctx, uint8_t* base) {
	// 0x2A83E0: movss xmm0, dword ptr [0x00570900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570900u);
	// 0x2A83E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A83F0: movss [0x00570910], xmm0
	X86_MEM_WRITE_u32(base, 0x570910u, ctx.xmm[0].u32[0]);
	// 0x2A83F8: ret
	return;
}

void sub_2A8400(X86Context& ctx, uint8_t* base) {
	// 0x2A8400: movss xmm0, dword ptr [0x00570958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570958u);
	// 0x2A8408: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2A8410: movss [0x0057095C], xmm0
	X86_MEM_WRITE_u32(base, 0x57095Cu, ctx.xmm[0].u32[0]);
	// 0x2A8418: ret
	return;
}

void sub_2A8420(X86Context& ctx, uint8_t* base) {
	// 0x2A8420: movss xmm0, dword ptr [0x00570910]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570910u);
	// 0x2A8428: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8430: movss [0x00570948], xmm0
	X86_MEM_WRITE_u32(base, 0x570948u, ctx.xmm[0].u32[0]);
	// 0x2A8438: ret
	return;
}

void sub_2A8440(X86Context& ctx, uint8_t* base) {
	// 0x2A8440: movss xmm0, dword ptr [0x0057095C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57095Cu);
	// 0x2A8448: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8450: movss [0x0057096C], xmm0
	X86_MEM_WRITE_u32(base, 0x57096Cu, ctx.xmm[0].u32[0]);
	// 0x2A8458: ret
	return;
}

void sub_2A8460(X86Context& ctx, uint8_t* base) {
	// 0x2A8460: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2A8468: movss [0x005708E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5708E0u, ctx.xmm[0].u32[0]);
	// 0x2A8470: ret
	return;
}

void sub_2A8480(X86Context& ctx, uint8_t* base) {
	// 0x2A8480: movss xmm0, dword ptr [0x00570900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570900u);
	// 0x2A8488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8490: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2A8498: movss [0x00570954], xmm0
	X86_MEM_WRITE_u32(base, 0x570954u, ctx.xmm[0].u32[0]);
	// 0x2A84A0: ret
	return;
}

void sub_2A84B0(X86Context& ctx, uint8_t* base) {
	// 0x2A84B0: movss xmm0, dword ptr [0x00570958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570958u);
	// 0x2A84B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A84C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2A84C8: movss [0x005708F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5708F8u, ctx.xmm[0].u32[0]);
	// 0x2A84D0: ret
	return;
}

void sub_2A84E0(X86Context& ctx, uint8_t* base) {
	// 0x2A84E0: movss xmm0, dword ptr [0x00570900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570900u);
	// 0x2A84E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A84F0: movss [0x005708FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5708FCu, ctx.xmm[0].u32[0]);
	// 0x2A84F8: ret
	return;
}

void sub_2A8500(X86Context& ctx, uint8_t* base) {
	// 0x2A8500: movss xmm0, dword ptr [0x00570958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570958u);
	// 0x2A8508: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2A8510: movss [0x00570960], xmm0
	X86_MEM_WRITE_u32(base, 0x570960u, ctx.xmm[0].u32[0]);
	// 0x2A8518: ret
	return;
}

void sub_2A8520(X86Context& ctx, uint8_t* base) {
	// 0x2A8520: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2A8528: movss [0x005708E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5708E4u, ctx.xmm[0].u32[0]);
	// 0x2A8530: ret
	return;
}

void sub_2A8540(X86Context& ctx, uint8_t* base) {
	// 0x2A8540: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2A8548: movss [0x0057090C], xmm0
	X86_MEM_WRITE_u32(base, 0x57090Cu, ctx.xmm[0].u32[0]);
	// 0x2A8550: ret
	return;
}

void sub_2A8560(X86Context& ctx, uint8_t* base) {
	// 0x2A8560: movss xmm0, dword ptr [0x005708E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708E4u);
	// 0x2A8568: movss [0x00570974], xmm0
	X86_MEM_WRITE_u32(base, 0x570974u, ctx.xmm[0].u32[0]);
	// 0x2A8570: ret
	return;
}

void sub_2A8580(X86Context& ctx, uint8_t* base) {
	// 0x2A8580: movss xmm0, dword ptr [0x00570958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570958u);
	// 0x2A8588: subss xmm0, [0x005708E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5708E4u);
	// 0x2A8590: movss [0x00570934], xmm0
	X86_MEM_WRITE_u32(base, 0x570934u, ctx.xmm[0].u32[0]);
	// 0x2A8598: ret
	return;
}

void sub_2A85A0(X86Context& ctx, uint8_t* base) {
	// 0x2A85A0: movss xmm0, dword ptr [0x00570934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570934u);
	// 0x2A85A8: subss xmm0, [0x0057090C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57090Cu);
	// 0x2A85B0: movss [0x0057092C], xmm0
	X86_MEM_WRITE_u32(base, 0x57092Cu, ctx.xmm[0].u32[0]);
	// 0x2A85B8: ret
	return;
}

void sub_2A85C0(X86Context& ctx, uint8_t* base) {
	// 0x2A85C0: movss xmm0, dword ptr [0x00570960]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570960u);
	// 0x2A85C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2A85D0: movss [0x0057091C], xmm0
	X86_MEM_WRITE_u32(base, 0x57091Cu, ctx.xmm[0].u32[0]);
	// 0x2A85D8: ret
	return;
}

void sub_2A85E0(X86Context& ctx, uint8_t* base) {
	// 0x2A85E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2A85E8: movss [0x00570908], xmm0
	X86_MEM_WRITE_u32(base, 0x570908u, ctx.xmm[0].u32[0]);
	// 0x2A85F0: ret
	return;
}

void sub_2A8600(X86Context& ctx, uint8_t* base) {
	// 0x2A8600: movss xmm0, dword ptr [0x0057091C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57091Cu);
	// 0x2A8608: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2A8610: movss [0x00570950], xmm0
	X86_MEM_WRITE_u32(base, 0x570950u, ctx.xmm[0].u32[0]);
	// 0x2A8618: ret
	return;
}

void sub_2A8620(X86Context& ctx, uint8_t* base) {
	// 0x2A8620: movss xmm0, dword ptr [0x005708DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5708DCu);
	// 0x2A8628: movss [0x00570980], xmm0
	X86_MEM_WRITE_u32(base, 0x570980u, ctx.xmm[0].u32[0]);
	// 0x2A8630: ret
	return;
}

void sub_2A8640(X86Context& ctx, uint8_t* base) {
	// 0x2A8640: movss xmm0, dword ptr [0x00395BE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BE4u);
	// 0x2A8648: movss [0x00570938], xmm0
	X86_MEM_WRITE_u32(base, 0x570938u, ctx.xmm[0].u32[0]);
	// 0x2A8650: ret
	return;
}

void sub_2A8660(X86Context& ctx, uint8_t* base) {
	// 0x2A8660: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2A8668: movss [0x005709DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5709DCu, ctx.xmm[0].u32[0]);
	// 0x2A8670: ret
	return;
}

void sub_2A8680(X86Context& ctx, uint8_t* base) {
	// 0x2A8680: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2A8688: movss [0x005709F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5709F8u, ctx.xmm[0].u32[0]);
	// 0x2A8690: ret
	return;
}

void sub_2A86A0(X86Context& ctx, uint8_t* base) {
	// 0x2A86A0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2A86A8: movss [0x005709CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5709CCu, ctx.xmm[0].u32[0]);
	// 0x2A86B0: ret
	return;
}

void sub_2A86C0(X86Context& ctx, uint8_t* base) {
	// 0x2A86C0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2A86C8: movss [0x00570984], xmm0
	X86_MEM_WRITE_u32(base, 0x570984u, ctx.xmm[0].u32[0]);
	// 0x2A86D0: ret
	return;
}

void sub_2A86E0(X86Context& ctx, uint8_t* base) {
	// 0x2A86E0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2A86E8: movss [0x005709E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5709E0u, ctx.xmm[0].u32[0]);
	// 0x2A86F0: ret
	return;
}

void sub_2A8700(X86Context& ctx, uint8_t* base) {
	// 0x2A8700: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2A8708: movss [0x005709A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5709A0u, ctx.xmm[0].u32[0]);
	// 0x2A8710: ret
	return;
}

void sub_2A8720(X86Context& ctx, uint8_t* base) {
	// 0x2A8720: movss xmm0, dword ptr [0x005709E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709E0u);
	// 0x2A8728: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2A8730: movss [0x00570A18], xmm0
	X86_MEM_WRITE_u32(base, 0x570A18u, ctx.xmm[0].u32[0]);
	// 0x2A8738: ret
	return;
}

void sub_2A8740(X86Context& ctx, uint8_t* base) {
	// 0x2A8740: movss xmm0, dword ptr [0x005709A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709A0u);
	// 0x2A8748: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2A8750: movss [0x00570A00], xmm0
	X86_MEM_WRITE_u32(base, 0x570A00u, ctx.xmm[0].u32[0]);
	// 0x2A8758: ret
	return;
}

void sub_2A8760(X86Context& ctx, uint8_t* base) {
	// 0x2A8760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A8768: movss [0x00570A30], xmm0
	X86_MEM_WRITE_u32(base, 0x570A30u, ctx.xmm[0].u32[0]);
	// 0x2A8770: ret
	return;
}

void sub_2A8780(X86Context& ctx, uint8_t* base) {
	// 0x2A8780: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2A8788: movss [0x00570A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A1Cu, ctx.xmm[0].u32[0]);
	// 0x2A8790: ret
	return;
}

void sub_2A87A0(X86Context& ctx, uint8_t* base) {
	// 0x2A87A0: movss xmm0, dword ptr [0x00570A1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x570A1Cu);
	// 0x2A87A8: movss [0x00570A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x570A2Cu, ctx.xmm[0].u32[0]);
	// 0x2A87B0: ret
	return;
}

void sub_2A87C0(X86Context& ctx, uint8_t* base) {
	// 0x2A87C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2A87C8: movss [0x0057098C], xmm0
	X86_MEM_WRITE_u32(base, 0x57098Cu, ctx.xmm[0].u32[0]);
	// 0x2A87D0: ret
	return;
}

void sub_2A87E0(X86Context& ctx, uint8_t* base) {
	// 0x2A87E0: movss xmm0, dword ptr [0x005709A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5709A0u);
	// 0x2A87E8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2A87F0: movss [0x00570A24], xmm0
	X86_MEM_WRITE_u32(base, 0x570A24u, ctx.xmm[0].u32[0]);
	// 0x2A87F8: ret
	return;
}

