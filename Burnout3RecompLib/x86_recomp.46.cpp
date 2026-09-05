#include "x86_recomp_shared.h"

void sub_27D5F0(X86Context& ctx, uint8_t* base) {
	// 0x27D5F0: movss xmm0, dword ptr [0x00569E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E6Cu);
	// 0x27D5F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27D600: movss [0x00569E7C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E7Cu, ctx.xmm[0].u32[0]);
	// 0x27D608: ret
	return;
}

void sub_27D610(X86Context& ctx, uint8_t* base) {
	// 0x27D610: movss xmm0, dword ptr [0x00569EC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EC4u);
	// 0x27D618: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27D620: movss [0x00569EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x569EC8u, ctx.xmm[0].u32[0]);
	// 0x27D628: ret
	return;
}

void sub_27D630(X86Context& ctx, uint8_t* base) {
	// 0x27D630: movss xmm0, dword ptr [0x00569E7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E7Cu);
	// 0x27D638: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D640: movss [0x00569EB4], xmm0
	X86_MEM_WRITE_u32(base, 0x569EB4u, ctx.xmm[0].u32[0]);
	// 0x27D648: ret
	return;
}

void sub_27D650(X86Context& ctx, uint8_t* base) {
	// 0x27D650: movss xmm0, dword ptr [0x00569EC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EC8u);
	// 0x27D658: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D660: movss [0x00569ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x569ED8u, ctx.xmm[0].u32[0]);
	// 0x27D668: ret
	return;
}

void sub_27D670(X86Context& ctx, uint8_t* base) {
	// 0x27D670: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27D678: movss [0x00569E48], xmm0
	X86_MEM_WRITE_u32(base, 0x569E48u, ctx.xmm[0].u32[0]);
	// 0x27D680: ret
	return;
}

void sub_27D690(X86Context& ctx, uint8_t* base) {
	// 0x27D690: movss xmm0, dword ptr [0x00569E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E6Cu);
	// 0x27D698: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D6A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27D6A8: movss [0x00569EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x569EC0u, ctx.xmm[0].u32[0]);
	// 0x27D6B0: ret
	return;
}

void sub_27D6C0(X86Context& ctx, uint8_t* base) {
	// 0x27D6C0: movss xmm0, dword ptr [0x00569EC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EC4u);
	// 0x27D6C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D6D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27D6D8: movss [0x00569E60], xmm0
	X86_MEM_WRITE_u32(base, 0x569E60u, ctx.xmm[0].u32[0]);
	// 0x27D6E0: ret
	return;
}

void sub_27D6F0(X86Context& ctx, uint8_t* base) {
	// 0x27D6F0: movss xmm0, dword ptr [0x00569E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E6Cu);
	// 0x27D6F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D700: movss [0x00569E64], xmm0
	X86_MEM_WRITE_u32(base, 0x569E64u, ctx.xmm[0].u32[0]);
	// 0x27D708: ret
	return;
}

void sub_27D710(X86Context& ctx, uint8_t* base) {
	// 0x27D710: movss xmm0, dword ptr [0x00569EC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EC4u);
	// 0x27D718: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27D720: movss [0x00569ECC], xmm0
	X86_MEM_WRITE_u32(base, 0x569ECCu, ctx.xmm[0].u32[0]);
	// 0x27D728: ret
	return;
}

void sub_27D730(X86Context& ctx, uint8_t* base) {
	// 0x27D730: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27D738: movss [0x00569E4C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E4Cu, ctx.xmm[0].u32[0]);
	// 0x27D740: ret
	return;
}

void sub_27D750(X86Context& ctx, uint8_t* base) {
	// 0x27D750: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27D758: movss [0x00569E78], xmm0
	X86_MEM_WRITE_u32(base, 0x569E78u, ctx.xmm[0].u32[0]);
	// 0x27D760: ret
	return;
}

void sub_27D770(X86Context& ctx, uint8_t* base) {
	// 0x27D770: movss xmm0, dword ptr [0x00569E4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E4Cu);
	// 0x27D778: movss [0x00569EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x569EE0u, ctx.xmm[0].u32[0]);
	// 0x27D780: ret
	return;
}

void sub_27D790(X86Context& ctx, uint8_t* base) {
	// 0x27D790: movss xmm0, dword ptr [0x00569EC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EC4u);
	// 0x27D798: subss xmm0, [0x00569E4C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569E4Cu);
	// 0x27D7A0: movss [0x00569EA4], xmm0
	X86_MEM_WRITE_u32(base, 0x569EA4u, ctx.xmm[0].u32[0]);
	// 0x27D7A8: ret
	return;
}

void sub_27D7B0(X86Context& ctx, uint8_t* base) {
	// 0x27D7B0: movss xmm0, dword ptr [0x00569EA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EA4u);
	// 0x27D7B8: subss xmm0, [0x00569E78]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569E78u);
	// 0x27D7C0: movss [0x00569E9C], xmm0
	X86_MEM_WRITE_u32(base, 0x569E9Cu, ctx.xmm[0].u32[0]);
	// 0x27D7C8: ret
	return;
}

void sub_27D7D0(X86Context& ctx, uint8_t* base) {
	// 0x27D7D0: movss xmm0, dword ptr [0x00569ECC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569ECCu);
	// 0x27D7D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27D7E0: movss [0x00569E88], xmm0
	X86_MEM_WRITE_u32(base, 0x569E88u, ctx.xmm[0].u32[0]);
	// 0x27D7E8: ret
	return;
}

void sub_27D7F0(X86Context& ctx, uint8_t* base) {
	// 0x27D7F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27D7F8: movss [0x00569E74], xmm0
	X86_MEM_WRITE_u32(base, 0x569E74u, ctx.xmm[0].u32[0]);
	// 0x27D800: ret
	return;
}

void sub_27D810(X86Context& ctx, uint8_t* base) {
	// 0x27D810: movss xmm0, dword ptr [0x00569E88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569E88u);
	// 0x27D818: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27D820: movss [0x00569EBC], xmm0
	X86_MEM_WRITE_u32(base, 0x569EBCu, ctx.xmm[0].u32[0]);
	// 0x27D828: ret
	return;
}

void sub_27D830(X86Context& ctx, uint8_t* base) {
	// 0x27D830: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27D838: movss [0x00569E90], xmm0
	X86_MEM_WRITE_u32(base, 0x569E90u, ctx.xmm[0].u32[0]);
	// 0x27D840: ret
	return;
}

void sub_27D850(X86Context& ctx, uint8_t* base) {
	// 0x27D850: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27D858: movss [0x00569E68], xmm0
	X86_MEM_WRITE_u32(base, 0x569E68u, ctx.xmm[0].u32[0]);
	// 0x27D860: ret
	return;
}

void sub_27D870(X86Context& ctx, uint8_t* base) {
	// 0x27D870: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27D878: movss [0x00569F48], xmm0
	X86_MEM_WRITE_u32(base, 0x569F48u, ctx.xmm[0].u32[0]);
	// 0x27D880: ret
	return;
}

void sub_27D890(X86Context& ctx, uint8_t* base) {
	// 0x27D890: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27D898: movss [0x00569F64], xmm0
	X86_MEM_WRITE_u32(base, 0x569F64u, ctx.xmm[0].u32[0]);
	// 0x27D8A0: ret
	return;
}

void sub_27D8B0(X86Context& ctx, uint8_t* base) {
	// 0x27D8B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27D8B8: movss [0x00569F38], xmm0
	X86_MEM_WRITE_u32(base, 0x569F38u, ctx.xmm[0].u32[0]);
	// 0x27D8C0: ret
	return;
}

void sub_27D8D0(X86Context& ctx, uint8_t* base) {
	// 0x27D8D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27D8D8: movss [0x00569EEC], xmm0
	X86_MEM_WRITE_u32(base, 0x569EECu, ctx.xmm[0].u32[0]);
	// 0x27D8E0: ret
	return;
}

void sub_27D8F0(X86Context& ctx, uint8_t* base) {
	// 0x27D8F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27D8F8: movss [0x00569F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F4Cu, ctx.xmm[0].u32[0]);
	// 0x27D900: ret
	return;
}

void sub_27D910(X86Context& ctx, uint8_t* base) {
	// 0x27D910: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27D918: movss [0x00569F08], xmm0
	X86_MEM_WRITE_u32(base, 0x569F08u, ctx.xmm[0].u32[0]);
	// 0x27D920: ret
	return;
}

void sub_27D930(X86Context& ctx, uint8_t* base) {
	// 0x27D930: movss xmm0, dword ptr [0x00569F4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F4Cu);
	// 0x27D938: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27D940: movss [0x00569F84], xmm0
	X86_MEM_WRITE_u32(base, 0x569F84u, ctx.xmm[0].u32[0]);
	// 0x27D948: ret
	return;
}

void sub_27D950(X86Context& ctx, uint8_t* base) {
	// 0x27D950: movss xmm0, dword ptr [0x00569F08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F08u);
	// 0x27D958: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27D960: movss [0x00569F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F6Cu, ctx.xmm[0].u32[0]);
	// 0x27D968: ret
	return;
}

void sub_27D970(X86Context& ctx, uint8_t* base) {
	// 0x27D970: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27D978: movss [0x00569F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F9Cu, ctx.xmm[0].u32[0]);
	// 0x27D980: ret
	return;
}

void sub_27D990(X86Context& ctx, uint8_t* base) {
	// 0x27D990: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27D998: movss [0x00569F88], xmm0
	X86_MEM_WRITE_u32(base, 0x569F88u, ctx.xmm[0].u32[0]);
	// 0x27D9A0: ret
	return;
}

void sub_27D9B0(X86Context& ctx, uint8_t* base) {
	// 0x27D9B0: movss xmm0, dword ptr [0x00569F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F88u);
	// 0x27D9B8: movss [0x00569F98], xmm0
	X86_MEM_WRITE_u32(base, 0x569F98u, ctx.xmm[0].u32[0]);
	// 0x27D9C0: ret
	return;
}

void sub_27D9D0(X86Context& ctx, uint8_t* base) {
	// 0x27D9D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27D9D8: movss [0x00569EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x569EF4u, ctx.xmm[0].u32[0]);
	// 0x27D9E0: ret
	return;
}

void sub_27D9F0(X86Context& ctx, uint8_t* base) {
	// 0x27D9F0: movss xmm0, dword ptr [0x00569F08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F08u);
	// 0x27D9F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27DA00: movss [0x00569F90], xmm0
	X86_MEM_WRITE_u32(base, 0x569F90u, ctx.xmm[0].u32[0]);
	// 0x27DA08: ret
	return;
}

void sub_27DA10(X86Context& ctx, uint8_t* base) {
	// 0x27DA10: movss xmm0, dword ptr [0x00569F08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F08u);
	// 0x27DA18: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27DA20: movss [0x00569F34], xmm0
	X86_MEM_WRITE_u32(base, 0x569F34u, ctx.xmm[0].u32[0]);
	// 0x27DA28: ret
	return;
}

void sub_27DA30(X86Context& ctx, uint8_t* base) {
	// 0x27DA30: movss xmm0, dword ptr [0x00569F08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F08u);
	// 0x27DA38: subss xmm0, [0x00569F34]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569F34u);
	// 0x27DA40: movss [0x00569F10], xmm0
	X86_MEM_WRITE_u32(base, 0x569F10u, ctx.xmm[0].u32[0]);
	// 0x27DA48: ret
	return;
}

void sub_27DA50(X86Context& ctx, uint8_t* base) {
	// 0x27DA50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27DA58: movss [0x00569F60], xmm0
	X86_MEM_WRITE_u32(base, 0x569F60u, ctx.xmm[0].u32[0]);
	// 0x27DA60: ret
	return;
}

void sub_27DA70(X86Context& ctx, uint8_t* base) {
	// 0x27DA70: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27DA78: movss [0x00569F0C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F0Cu, ctx.xmm[0].u32[0]);
	// 0x27DA80: ret
	return;
}

void sub_27DA90(X86Context& ctx, uint8_t* base) {
	// 0x27DA90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27DA98: movss [0x00569F20], xmm0
	X86_MEM_WRITE_u32(base, 0x569F20u, ctx.xmm[0].u32[0]);
	// 0x27DAA0: ret
	return;
}

void sub_27DAB0(X86Context& ctx, uint8_t* base) {
	// 0x27DAB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27DAB8: movss [0x00569F78], xmm0
	X86_MEM_WRITE_u32(base, 0x569F78u, ctx.xmm[0].u32[0]);
	// 0x27DAC0: ret
	return;
}

void sub_27DAD0(X86Context& ctx, uint8_t* base) {
	// 0x27DAD0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27DAD8: movss [0x00569F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F5Cu, ctx.xmm[0].u32[0]);
	// 0x27DAE0: ret
	return;
}

void sub_27DAF0(X86Context& ctx, uint8_t* base) {
	// 0x27DAF0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27DAF8: movss [0x00569F04], xmm0
	X86_MEM_WRITE_u32(base, 0x569F04u, ctx.xmm[0].u32[0]);
	// 0x27DB00: ret
	return;
}

void sub_27DB10(X86Context& ctx, uint8_t* base) {
	// 0x27DB10: movss xmm0, dword ptr [0x00569F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F20u);
	// 0x27DB18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27DB20: movss [0x00569EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x569EF8u, ctx.xmm[0].u32[0]);
	// 0x27DB28: ret
	return;
}

void sub_27DB30(X86Context& ctx, uint8_t* base) {
	// 0x27DB30: movss xmm0, dword ptr [0x00569F78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F78u);
	// 0x27DB38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27DB40: movss [0x00569F40], xmm0
	X86_MEM_WRITE_u32(base, 0x569F40u, ctx.xmm[0].u32[0]);
	// 0x27DB48: ret
	return;
}

void sub_27DB50(X86Context& ctx, uint8_t* base) {
	// 0x27DB50: movss xmm0, dword ptr [0x00569EF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569EF8u);
	// 0x27DB58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27DB60: movss [0x00569F54], xmm0
	X86_MEM_WRITE_u32(base, 0x569F54u, ctx.xmm[0].u32[0]);
	// 0x27DB68: ret
	return;
}

void sub_27DB70(X86Context& ctx, uint8_t* base) {
	// 0x27DB70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27DB78: movss [0x00569EF0], xmm0
	X86_MEM_WRITE_u32(base, 0x569EF0u, ctx.xmm[0].u32[0]);
	// 0x27DB80: ret
	return;
}

void sub_27DB90(X86Context& ctx, uint8_t* base) {
	// 0x27DB90: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27DB98: movss [0x00569F24], xmm0
	X86_MEM_WRITE_u32(base, 0x569F24u, ctx.xmm[0].u32[0]);
	// 0x27DBA0: ret
	return;
}

void sub_27DBB0(X86Context& ctx, uint8_t* base) {
	// 0x27DBB0: movss xmm0, dword ptr [0x00569F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F20u);
	// 0x27DBB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27DBC0: movss [0x00569F30], xmm0
	X86_MEM_WRITE_u32(base, 0x569F30u, ctx.xmm[0].u32[0]);
	// 0x27DBC8: ret
	return;
}

void sub_27DBD0(X86Context& ctx, uint8_t* base) {
	// 0x27DBD0: movss xmm0, dword ptr [0x00569F78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F78u);
	// 0x27DBD8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27DBE0: movss [0x00569F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F7Cu, ctx.xmm[0].u32[0]);
	// 0x27DBE8: ret
	return;
}

void sub_27DBF0(X86Context& ctx, uint8_t* base) {
	// 0x27DBF0: movss xmm0, dword ptr [0x00569F30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F30u);
	// 0x27DBF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27DC00: movss [0x00569F68], xmm0
	X86_MEM_WRITE_u32(base, 0x569F68u, ctx.xmm[0].u32[0]);
	// 0x27DC08: ret
	return;
}

void sub_27DC10(X86Context& ctx, uint8_t* base) {
	// 0x27DC10: movss xmm0, dword ptr [0x00569F7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F7Cu);
	// 0x27DC18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27DC20: movss [0x00569F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F8Cu, ctx.xmm[0].u32[0]);
	// 0x27DC28: ret
	return;
}

void sub_27DC30(X86Context& ctx, uint8_t* base) {
	// 0x27DC30: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27DC38: movss [0x00569EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x569EFCu, ctx.xmm[0].u32[0]);
	// 0x27DC40: ret
	return;
}

void sub_27DC50(X86Context& ctx, uint8_t* base) {
	// 0x27DC50: movss xmm0, dword ptr [0x00569F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F20u);
	// 0x27DC58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27DC60: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27DC68: movss [0x00569F74], xmm0
	X86_MEM_WRITE_u32(base, 0x569F74u, ctx.xmm[0].u32[0]);
	// 0x27DC70: ret
	return;
}

void sub_27DC80(X86Context& ctx, uint8_t* base) {
	// 0x27DC80: movss xmm0, dword ptr [0x00569F78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F78u);
	// 0x27DC88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27DC90: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27DC98: movss [0x00569F14], xmm0
	X86_MEM_WRITE_u32(base, 0x569F14u, ctx.xmm[0].u32[0]);
	// 0x27DCA0: ret
	return;
}

void sub_27DCB0(X86Context& ctx, uint8_t* base) {
	// 0x27DCB0: movss xmm0, dword ptr [0x00569F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F20u);
	// 0x27DCB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27DCC0: movss [0x00569F18], xmm0
	X86_MEM_WRITE_u32(base, 0x569F18u, ctx.xmm[0].u32[0]);
	// 0x27DCC8: ret
	return;
}

void sub_27DCD0(X86Context& ctx, uint8_t* base) {
	// 0x27DCD0: movss xmm0, dword ptr [0x00569F78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F78u);
	// 0x27DCD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27DCE0: movss [0x00569F80], xmm0
	X86_MEM_WRITE_u32(base, 0x569F80u, ctx.xmm[0].u32[0]);
	// 0x27DCE8: ret
	return;
}

void sub_27DCF0(X86Context& ctx, uint8_t* base) {
	// 0x27DCF0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27DCF8: movss [0x00569F00], xmm0
	X86_MEM_WRITE_u32(base, 0x569F00u, ctx.xmm[0].u32[0]);
	// 0x27DD00: ret
	return;
}

void sub_27DD10(X86Context& ctx, uint8_t* base) {
	// 0x27DD10: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27DD18: movss [0x00569F2C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F2Cu, ctx.xmm[0].u32[0]);
	// 0x27DD20: ret
	return;
}

void sub_27DD30(X86Context& ctx, uint8_t* base) {
	// 0x27DD30: movss xmm0, dword ptr [0x00569F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F00u);
	// 0x27DD38: movss [0x00569F94], xmm0
	X86_MEM_WRITE_u32(base, 0x569F94u, ctx.xmm[0].u32[0]);
	// 0x27DD40: ret
	return;
}

void sub_27DD50(X86Context& ctx, uint8_t* base) {
	// 0x27DD50: movss xmm0, dword ptr [0x00569F78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F78u);
	// 0x27DD58: subss xmm0, [0x00569F00]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569F00u);
	// 0x27DD60: movss [0x00569F58], xmm0
	X86_MEM_WRITE_u32(base, 0x569F58u, ctx.xmm[0].u32[0]);
	// 0x27DD68: ret
	return;
}

void sub_27DD70(X86Context& ctx, uint8_t* base) {
	// 0x27DD70: movss xmm0, dword ptr [0x00569F58]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F58u);
	// 0x27DD78: subss xmm0, [0x00569F2C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569F2Cu);
	// 0x27DD80: movss [0x00569F50], xmm0
	X86_MEM_WRITE_u32(base, 0x569F50u, ctx.xmm[0].u32[0]);
	// 0x27DD88: ret
	return;
}

void sub_27DD90(X86Context& ctx, uint8_t* base) {
	// 0x27DD90: movss xmm0, dword ptr [0x00569F80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F80u);
	// 0x27DD98: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27DDA0: movss [0x00569F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F3Cu, ctx.xmm[0].u32[0]);
	// 0x27DDA8: ret
	return;
}

void sub_27DDB0(X86Context& ctx, uint8_t* base) {
	// 0x27DDB0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27DDB8: movss [0x00569F28], xmm0
	X86_MEM_WRITE_u32(base, 0x569F28u, ctx.xmm[0].u32[0]);
	// 0x27DDC0: ret
	return;
}

void sub_27DDD0(X86Context& ctx, uint8_t* base) {
	// 0x27DDD0: movss xmm0, dword ptr [0x00569F3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569F3Cu);
	// 0x27DDD8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27DDE0: movss [0x00569F70], xmm0
	X86_MEM_WRITE_u32(base, 0x569F70u, ctx.xmm[0].u32[0]);
	// 0x27DDE8: ret
	return;
}

void sub_27DDF0(X86Context& ctx, uint8_t* base) {
	// 0x27DDF0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27DDF8: movss [0x00569F44], xmm0
	X86_MEM_WRITE_u32(base, 0x569F44u, ctx.xmm[0].u32[0]);
	// 0x27DE00: ret
	return;
}

void sub_27DE10(X86Context& ctx, uint8_t* base) {
	// 0x27DE10: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27DE18: movss [0x00569F1C], xmm0
	X86_MEM_WRITE_u32(base, 0x569F1Cu, ctx.xmm[0].u32[0]);
	// 0x27DE20: ret
	return;
}

void sub_27DE30(X86Context& ctx, uint8_t* base) {
	// 0x27DE30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27DE38: movss [0x00569FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x569FFCu, ctx.xmm[0].u32[0]);
	// 0x27DE40: ret
	return;
}

void sub_27DE50(X86Context& ctx, uint8_t* base) {
	// 0x27DE50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27DE58: movss [0x0056A018], xmm0
	X86_MEM_WRITE_u32(base, 0x56A018u, ctx.xmm[0].u32[0]);
	// 0x27DE60: ret
	return;
}

void sub_27DE70(X86Context& ctx, uint8_t* base) {
	// 0x27DE70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27DE78: movss [0x00569FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x569FECu, ctx.xmm[0].u32[0]);
	// 0x27DE80: ret
	return;
}

void sub_27DE90(X86Context& ctx, uint8_t* base) {
	// 0x27DE90: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27DE98: movss [0x00569FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x569FA0u, ctx.xmm[0].u32[0]);
	// 0x27DEA0: ret
	return;
}

void sub_27DEB0(X86Context& ctx, uint8_t* base) {
	// 0x27DEB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27DEB8: movss [0x0056A000], xmm0
	X86_MEM_WRITE_u32(base, 0x56A000u, ctx.xmm[0].u32[0]);
	// 0x27DEC0: ret
	return;
}

void sub_27DED0(X86Context& ctx, uint8_t* base) {
	// 0x27DED0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27DED8: movss [0x00569FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x569FBCu, ctx.xmm[0].u32[0]);
	// 0x27DEE0: ret
	return;
}

void sub_27DEF0(X86Context& ctx, uint8_t* base) {
	// 0x27DEF0: movss xmm0, dword ptr [0x0056A000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A000u);
	// 0x27DEF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27DF00: movss [0x0056A038], xmm0
	X86_MEM_WRITE_u32(base, 0x56A038u, ctx.xmm[0].u32[0]);
	// 0x27DF08: ret
	return;
}

void sub_27DF10(X86Context& ctx, uint8_t* base) {
	// 0x27DF10: movss xmm0, dword ptr [0x00569FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FBCu);
	// 0x27DF18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27DF20: movss [0x0056A020], xmm0
	X86_MEM_WRITE_u32(base, 0x56A020u, ctx.xmm[0].u32[0]);
	// 0x27DF28: ret
	return;
}

void sub_27DF30(X86Context& ctx, uint8_t* base) {
	// 0x27DF30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27DF38: movss [0x0056A050], xmm0
	X86_MEM_WRITE_u32(base, 0x56A050u, ctx.xmm[0].u32[0]);
	// 0x27DF40: ret
	return;
}

void sub_27DF50(X86Context& ctx, uint8_t* base) {
	// 0x27DF50: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27DF58: movss [0x0056A03C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A03Cu, ctx.xmm[0].u32[0]);
	// 0x27DF60: ret
	return;
}

void sub_27DF70(X86Context& ctx, uint8_t* base) {
	// 0x27DF70: movss xmm0, dword ptr [0x0056A03C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A03Cu);
	// 0x27DF78: movss [0x0056A04C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A04Cu, ctx.xmm[0].u32[0]);
	// 0x27DF80: ret
	return;
}

void sub_27DF90(X86Context& ctx, uint8_t* base) {
	// 0x27DF90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27DF98: movss [0x00569FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x569FA8u, ctx.xmm[0].u32[0]);
	// 0x27DFA0: ret
	return;
}

void sub_27DFB0(X86Context& ctx, uint8_t* base) {
	// 0x27DFB0: movss xmm0, dword ptr [0x00569FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FBCu);
	// 0x27DFB8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27DFC0: movss [0x0056A044], xmm0
	X86_MEM_WRITE_u32(base, 0x56A044u, ctx.xmm[0].u32[0]);
	// 0x27DFC8: ret
	return;
}

void sub_27DFD0(X86Context& ctx, uint8_t* base) {
	// 0x27DFD0: movss xmm0, dword ptr [0x00569FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FBCu);
	// 0x27DFD8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27DFE0: movss [0x00569FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x569FE8u, ctx.xmm[0].u32[0]);
	// 0x27DFE8: ret
	return;
}

void sub_27DFF0(X86Context& ctx, uint8_t* base) {
	// 0x27DFF0: movss xmm0, dword ptr [0x00569FBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FBCu);
	// 0x27DFF8: subss xmm0, [0x00569FE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569FE8u);
	// 0x27E000: movss [0x00569FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x569FC4u, ctx.xmm[0].u32[0]);
	// 0x27E008: ret
	return;
}

void sub_27E010(X86Context& ctx, uint8_t* base) {
	// 0x27E010: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27E018: movss [0x0056A014], xmm0
	X86_MEM_WRITE_u32(base, 0x56A014u, ctx.xmm[0].u32[0]);
	// 0x27E020: ret
	return;
}

void sub_27E030(X86Context& ctx, uint8_t* base) {
	// 0x27E030: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27E038: movss [0x00569FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x569FC0u, ctx.xmm[0].u32[0]);
	// 0x27E040: ret
	return;
}

void sub_27E050(X86Context& ctx, uint8_t* base) {
	// 0x27E050: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27E058: movss [0x00569FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x569FD4u, ctx.xmm[0].u32[0]);
	// 0x27E060: ret
	return;
}

void sub_27E070(X86Context& ctx, uint8_t* base) {
	// 0x27E070: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27E078: movss [0x0056A02C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A02Cu, ctx.xmm[0].u32[0]);
	// 0x27E080: ret
	return;
}

void sub_27E090(X86Context& ctx, uint8_t* base) {
	// 0x27E090: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27E098: movss [0x0056A010], xmm0
	X86_MEM_WRITE_u32(base, 0x56A010u, ctx.xmm[0].u32[0]);
	// 0x27E0A0: ret
	return;
}

void sub_27E0B0(X86Context& ctx, uint8_t* base) {
	// 0x27E0B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27E0B8: movss [0x00569FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x569FB8u, ctx.xmm[0].u32[0]);
	// 0x27E0C0: ret
	return;
}

void sub_27E0D0(X86Context& ctx, uint8_t* base) {
	// 0x27E0D0: movss xmm0, dword ptr [0x00569FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FD4u);
	// 0x27E0D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27E0E0: movss [0x00569FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x569FACu, ctx.xmm[0].u32[0]);
	// 0x27E0E8: ret
	return;
}

void sub_27E0F0(X86Context& ctx, uint8_t* base) {
	// 0x27E0F0: movss xmm0, dword ptr [0x0056A02C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A02Cu);
	// 0x27E0F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27E100: movss [0x00569FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x569FF4u, ctx.xmm[0].u32[0]);
	// 0x27E108: ret
	return;
}

void sub_27E110(X86Context& ctx, uint8_t* base) {
	// 0x27E110: movss xmm0, dword ptr [0x00569FAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FACu);
	// 0x27E118: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27E120: movss [0x0056A008], xmm0
	X86_MEM_WRITE_u32(base, 0x56A008u, ctx.xmm[0].u32[0]);
	// 0x27E128: ret
	return;
}

void sub_27E130(X86Context& ctx, uint8_t* base) {
	// 0x27E130: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27E138: movss [0x00569FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x569FA4u, ctx.xmm[0].u32[0]);
	// 0x27E140: ret
	return;
}

void sub_27E150(X86Context& ctx, uint8_t* base) {
	// 0x27E150: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27E158: movss [0x00569FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x569FD8u, ctx.xmm[0].u32[0]);
	// 0x27E160: ret
	return;
}

void sub_27E170(X86Context& ctx, uint8_t* base) {
	// 0x27E170: movss xmm0, dword ptr [0x00569FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FD4u);
	// 0x27E178: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27E180: movss [0x00569FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x569FE4u, ctx.xmm[0].u32[0]);
	// 0x27E188: ret
	return;
}

void sub_27E190(X86Context& ctx, uint8_t* base) {
	// 0x27E190: movss xmm0, dword ptr [0x0056A02C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A02Cu);
	// 0x27E198: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27E1A0: movss [0x0056A030], xmm0
	X86_MEM_WRITE_u32(base, 0x56A030u, ctx.xmm[0].u32[0]);
	// 0x27E1A8: ret
	return;
}

void sub_27E1B0(X86Context& ctx, uint8_t* base) {
	// 0x27E1B0: movss xmm0, dword ptr [0x00569FE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FE4u);
	// 0x27E1B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E1C0: movss [0x0056A01C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A01Cu, ctx.xmm[0].u32[0]);
	// 0x27E1C8: ret
	return;
}

void sub_27E1D0(X86Context& ctx, uint8_t* base) {
	// 0x27E1D0: movss xmm0, dword ptr [0x0056A030]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A030u);
	// 0x27E1D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E1E0: movss [0x0056A040], xmm0
	X86_MEM_WRITE_u32(base, 0x56A040u, ctx.xmm[0].u32[0]);
	// 0x27E1E8: ret
	return;
}

void sub_27E1F0(X86Context& ctx, uint8_t* base) {
	// 0x27E1F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27E1F8: movss [0x00569FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x569FB0u, ctx.xmm[0].u32[0]);
	// 0x27E200: ret
	return;
}

void sub_27E210(X86Context& ctx, uint8_t* base) {
	// 0x27E210: movss xmm0, dword ptr [0x00569FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FD4u);
	// 0x27E218: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E220: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27E228: movss [0x0056A028], xmm0
	X86_MEM_WRITE_u32(base, 0x56A028u, ctx.xmm[0].u32[0]);
	// 0x27E230: ret
	return;
}

void sub_27E240(X86Context& ctx, uint8_t* base) {
	// 0x27E240: movss xmm0, dword ptr [0x0056A02C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A02Cu);
	// 0x27E248: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E250: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27E258: movss [0x00569FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x569FC8u, ctx.xmm[0].u32[0]);
	// 0x27E260: ret
	return;
}

void sub_27E270(X86Context& ctx, uint8_t* base) {
	// 0x27E270: movss xmm0, dword ptr [0x00569FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FD4u);
	// 0x27E278: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E280: movss [0x00569FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x569FCCu, ctx.xmm[0].u32[0]);
	// 0x27E288: ret
	return;
}

void sub_27E290(X86Context& ctx, uint8_t* base) {
	// 0x27E290: movss xmm0, dword ptr [0x0056A02C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A02Cu);
	// 0x27E298: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E2A0: movss [0x0056A034], xmm0
	X86_MEM_WRITE_u32(base, 0x56A034u, ctx.xmm[0].u32[0]);
	// 0x27E2A8: ret
	return;
}

void sub_27E2B0(X86Context& ctx, uint8_t* base) {
	// 0x27E2B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27E2B8: movss [0x00569FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x569FB4u, ctx.xmm[0].u32[0]);
	// 0x27E2C0: ret
	return;
}

void sub_27E2D0(X86Context& ctx, uint8_t* base) {
	// 0x27E2D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27E2D8: movss [0x00569FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x569FE0u, ctx.xmm[0].u32[0]);
	// 0x27E2E0: ret
	return;
}

void sub_27E2F0(X86Context& ctx, uint8_t* base) {
	// 0x27E2F0: movss xmm0, dword ptr [0x00569FB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FB4u);
	// 0x27E2F8: movss [0x0056A048], xmm0
	X86_MEM_WRITE_u32(base, 0x56A048u, ctx.xmm[0].u32[0]);
	// 0x27E300: ret
	return;
}

void sub_27E310(X86Context& ctx, uint8_t* base) {
	// 0x27E310: movss xmm0, dword ptr [0x0056A02C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A02Cu);
	// 0x27E318: subss xmm0, [0x00569FB4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569FB4u);
	// 0x27E320: movss [0x0056A00C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A00Cu, ctx.xmm[0].u32[0]);
	// 0x27E328: ret
	return;
}

void sub_27E330(X86Context& ctx, uint8_t* base) {
	// 0x27E330: movss xmm0, dword ptr [0x0056A00C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A00Cu);
	// 0x27E338: subss xmm0, [0x00569FE0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569FE0u);
	// 0x27E340: movss [0x0056A004], xmm0
	X86_MEM_WRITE_u32(base, 0x56A004u, ctx.xmm[0].u32[0]);
	// 0x27E348: ret
	return;
}

void sub_27E350(X86Context& ctx, uint8_t* base) {
	// 0x27E350: movss xmm0, dword ptr [0x0056A034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A034u);
	// 0x27E358: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27E360: movss [0x00569FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x569FF0u, ctx.xmm[0].u32[0]);
	// 0x27E368: ret
	return;
}

void sub_27E370(X86Context& ctx, uint8_t* base) {
	// 0x27E370: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27E378: movss [0x00569FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x569FDCu, ctx.xmm[0].u32[0]);
	// 0x27E380: ret
	return;
}

void sub_27E390(X86Context& ctx, uint8_t* base) {
	// 0x27E390: movss xmm0, dword ptr [0x00569FF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569FF0u);
	// 0x27E398: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27E3A0: movss [0x0056A024], xmm0
	X86_MEM_WRITE_u32(base, 0x56A024u, ctx.xmm[0].u32[0]);
	// 0x27E3A8: ret
	return;
}

void sub_27E3B0(X86Context& ctx, uint8_t* base) {
	// 0x27E3B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27E3B8: movss [0x00569FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x569FF8u, ctx.xmm[0].u32[0]);
	// 0x27E3C0: ret
	return;
}

void sub_27E3D0(X86Context& ctx, uint8_t* base) {
	// 0x27E3D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27E3D8: movss [0x00569FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x569FD0u, ctx.xmm[0].u32[0]);
	// 0x27E3E0: ret
	return;
}

void sub_27E3F0(X86Context& ctx, uint8_t* base) {
	// 0x27E3F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27E3F8: movss [0x0056A0B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0B0u, ctx.xmm[0].u32[0]);
	// 0x27E400: ret
	return;
}

void sub_27E410(X86Context& ctx, uint8_t* base) {
	// 0x27E410: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27E418: movss [0x0056A0CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0CCu, ctx.xmm[0].u32[0]);
	// 0x27E420: ret
	return;
}

void sub_27E430(X86Context& ctx, uint8_t* base) {
	// 0x27E430: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27E438: movss [0x0056A0A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0A0u, ctx.xmm[0].u32[0]);
	// 0x27E440: ret
	return;
}

void sub_27E450(X86Context& ctx, uint8_t* base) {
	// 0x27E450: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27E458: movss [0x0056A054], xmm0
	X86_MEM_WRITE_u32(base, 0x56A054u, ctx.xmm[0].u32[0]);
	// 0x27E460: ret
	return;
}

void sub_27E470(X86Context& ctx, uint8_t* base) {
	// 0x27E470: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27E478: movss [0x0056A0B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0B4u, ctx.xmm[0].u32[0]);
	// 0x27E480: ret
	return;
}

void sub_27E490(X86Context& ctx, uint8_t* base) {
	// 0x27E490: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27E498: movss [0x0056A070], xmm0
	X86_MEM_WRITE_u32(base, 0x56A070u, ctx.xmm[0].u32[0]);
	// 0x27E4A0: ret
	return;
}

void sub_27E4B0(X86Context& ctx, uint8_t* base) {
	// 0x27E4B0: movss xmm0, dword ptr [0x0056A0B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0B4u);
	// 0x27E4B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27E4C0: movss [0x0056A0EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0ECu, ctx.xmm[0].u32[0]);
	// 0x27E4C8: ret
	return;
}

void sub_27E4D0(X86Context& ctx, uint8_t* base) {
	// 0x27E4D0: movss xmm0, dword ptr [0x0056A070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A070u);
	// 0x27E4D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27E4E0: movss [0x0056A0D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0D4u, ctx.xmm[0].u32[0]);
	// 0x27E4E8: ret
	return;
}

void sub_27E4F0(X86Context& ctx, uint8_t* base) {
	// 0x27E4F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27E4F8: movss [0x0056A104], xmm0
	X86_MEM_WRITE_u32(base, 0x56A104u, ctx.xmm[0].u32[0]);
	// 0x27E500: ret
	return;
}

void sub_27E510(X86Context& ctx, uint8_t* base) {
	// 0x27E510: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27E518: movss [0x0056A0F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0F0u, ctx.xmm[0].u32[0]);
	// 0x27E520: ret
	return;
}

void sub_27E530(X86Context& ctx, uint8_t* base) {
	// 0x27E530: movss xmm0, dword ptr [0x0056A0F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0F0u);
	// 0x27E538: movss [0x0056A100], xmm0
	X86_MEM_WRITE_u32(base, 0x56A100u, ctx.xmm[0].u32[0]);
	// 0x27E540: ret
	return;
}

void sub_27E550(X86Context& ctx, uint8_t* base) {
	// 0x27E550: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27E558: movss [0x0056A05C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A05Cu, ctx.xmm[0].u32[0]);
	// 0x27E560: ret
	return;
}

void sub_27E570(X86Context& ctx, uint8_t* base) {
	// 0x27E570: movss xmm0, dword ptr [0x0056A070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A070u);
	// 0x27E578: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27E580: movss [0x0056A0F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0F8u, ctx.xmm[0].u32[0]);
	// 0x27E588: ret
	return;
}

void sub_27E590(X86Context& ctx, uint8_t* base) {
	// 0x27E590: movss xmm0, dword ptr [0x0056A070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A070u);
	// 0x27E598: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27E5A0: movss [0x0056A09C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A09Cu, ctx.xmm[0].u32[0]);
	// 0x27E5A8: ret
	return;
}

void sub_27E5B0(X86Context& ctx, uint8_t* base) {
	// 0x27E5B0: movss xmm0, dword ptr [0x0056A070]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A070u);
	// 0x27E5B8: subss xmm0, [0x0056A09C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A09Cu);
	// 0x27E5C0: movss [0x0056A078], xmm0
	X86_MEM_WRITE_u32(base, 0x56A078u, ctx.xmm[0].u32[0]);
	// 0x27E5C8: ret
	return;
}

void sub_27E5D0(X86Context& ctx, uint8_t* base) {
	// 0x27E5D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27E5D8: movss [0x0056A0C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0C8u, ctx.xmm[0].u32[0]);
	// 0x27E5E0: ret
	return;
}

void sub_27E5F0(X86Context& ctx, uint8_t* base) {
	// 0x27E5F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27E5F8: movss [0x0056A074], xmm0
	X86_MEM_WRITE_u32(base, 0x56A074u, ctx.xmm[0].u32[0]);
	// 0x27E600: ret
	return;
}

void sub_27E610(X86Context& ctx, uint8_t* base) {
	// 0x27E610: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27E618: movss [0x0056A088], xmm0
	X86_MEM_WRITE_u32(base, 0x56A088u, ctx.xmm[0].u32[0]);
	// 0x27E620: ret
	return;
}

void sub_27E630(X86Context& ctx, uint8_t* base) {
	// 0x27E630: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27E638: movss [0x0056A0E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0E0u, ctx.xmm[0].u32[0]);
	// 0x27E640: ret
	return;
}

void sub_27E650(X86Context& ctx, uint8_t* base) {
	// 0x27E650: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27E658: movss [0x0056A0C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0C4u, ctx.xmm[0].u32[0]);
	// 0x27E660: ret
	return;
}

void sub_27E670(X86Context& ctx, uint8_t* base) {
	// 0x27E670: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27E678: movss [0x0056A06C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A06Cu, ctx.xmm[0].u32[0]);
	// 0x27E680: ret
	return;
}

void sub_27E690(X86Context& ctx, uint8_t* base) {
	// 0x27E690: movss xmm0, dword ptr [0x0056A088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A088u);
	// 0x27E698: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27E6A0: movss [0x0056A060], xmm0
	X86_MEM_WRITE_u32(base, 0x56A060u, ctx.xmm[0].u32[0]);
	// 0x27E6A8: ret
	return;
}

void sub_27E6B0(X86Context& ctx, uint8_t* base) {
	// 0x27E6B0: movss xmm0, dword ptr [0x0056A0E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E0u);
	// 0x27E6B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27E6C0: movss [0x0056A0A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0A8u, ctx.xmm[0].u32[0]);
	// 0x27E6C8: ret
	return;
}

void sub_27E6D0(X86Context& ctx, uint8_t* base) {
	// 0x27E6D0: movss xmm0, dword ptr [0x0056A060]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A060u);
	// 0x27E6D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27E6E0: movss [0x0056A0BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0BCu, ctx.xmm[0].u32[0]);
	// 0x27E6E8: ret
	return;
}

void sub_27E6F0(X86Context& ctx, uint8_t* base) {
	// 0x27E6F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27E6F8: movss [0x0056A058], xmm0
	X86_MEM_WRITE_u32(base, 0x56A058u, ctx.xmm[0].u32[0]);
	// 0x27E700: ret
	return;
}

void sub_27E710(X86Context& ctx, uint8_t* base) {
	// 0x27E710: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27E718: movss [0x0056A08C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A08Cu, ctx.xmm[0].u32[0]);
	// 0x27E720: ret
	return;
}

void sub_27E730(X86Context& ctx, uint8_t* base) {
	// 0x27E730: movss xmm0, dword ptr [0x0056A088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A088u);
	// 0x27E738: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27E740: movss [0x0056A098], xmm0
	X86_MEM_WRITE_u32(base, 0x56A098u, ctx.xmm[0].u32[0]);
	// 0x27E748: ret
	return;
}

void sub_27E750(X86Context& ctx, uint8_t* base) {
	// 0x27E750: movss xmm0, dword ptr [0x0056A0E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E0u);
	// 0x27E758: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27E760: movss [0x0056A0E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0E4u, ctx.xmm[0].u32[0]);
	// 0x27E768: ret
	return;
}

void sub_27E770(X86Context& ctx, uint8_t* base) {
	// 0x27E770: movss xmm0, dword ptr [0x0056A098]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A098u);
	// 0x27E778: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E780: movss [0x0056A0D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0D0u, ctx.xmm[0].u32[0]);
	// 0x27E788: ret
	return;
}

void sub_27E790(X86Context& ctx, uint8_t* base) {
	// 0x27E790: movss xmm0, dword ptr [0x0056A0E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E4u);
	// 0x27E798: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E7A0: movss [0x0056A0F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0F4u, ctx.xmm[0].u32[0]);
	// 0x27E7A8: ret
	return;
}

void sub_27E7B0(X86Context& ctx, uint8_t* base) {
	// 0x27E7B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27E7B8: movss [0x0056A064], xmm0
	X86_MEM_WRITE_u32(base, 0x56A064u, ctx.xmm[0].u32[0]);
	// 0x27E7C0: ret
	return;
}

void sub_27E7D0(X86Context& ctx, uint8_t* base) {
	// 0x27E7D0: movss xmm0, dword ptr [0x0056A088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A088u);
	// 0x27E7D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E7E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27E7E8: movss [0x0056A0DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0DCu, ctx.xmm[0].u32[0]);
	// 0x27E7F0: ret
	return;
}

void sub_27E800(X86Context& ctx, uint8_t* base) {
	// 0x27E800: movss xmm0, dword ptr [0x0056A0E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E0u);
	// 0x27E808: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E810: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27E818: movss [0x0056A07C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A07Cu, ctx.xmm[0].u32[0]);
	// 0x27E820: ret
	return;
}

void sub_27E830(X86Context& ctx, uint8_t* base) {
	// 0x27E830: movss xmm0, dword ptr [0x0056A088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A088u);
	// 0x27E838: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E840: movss [0x0056A080], xmm0
	X86_MEM_WRITE_u32(base, 0x56A080u, ctx.xmm[0].u32[0]);
	// 0x27E848: ret
	return;
}

void sub_27E850(X86Context& ctx, uint8_t* base) {
	// 0x27E850: movss xmm0, dword ptr [0x0056A0E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E0u);
	// 0x27E858: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27E860: movss [0x0056A0E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0E8u, ctx.xmm[0].u32[0]);
	// 0x27E868: ret
	return;
}

void sub_27E870(X86Context& ctx, uint8_t* base) {
	// 0x27E870: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27E878: movss [0x0056A068], xmm0
	X86_MEM_WRITE_u32(base, 0x56A068u, ctx.xmm[0].u32[0]);
	// 0x27E880: ret
	return;
}

void sub_27E890(X86Context& ctx, uint8_t* base) {
	// 0x27E890: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27E898: movss [0x0056A094], xmm0
	X86_MEM_WRITE_u32(base, 0x56A094u, ctx.xmm[0].u32[0]);
	// 0x27E8A0: ret
	return;
}

void sub_27E8B0(X86Context& ctx, uint8_t* base) {
	// 0x27E8B0: movss xmm0, dword ptr [0x0056A068]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A068u);
	// 0x27E8B8: movss [0x0056A0FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0FCu, ctx.xmm[0].u32[0]);
	// 0x27E8C0: ret
	return;
}

void sub_27E8D0(X86Context& ctx, uint8_t* base) {
	// 0x27E8D0: movss xmm0, dword ptr [0x0056A0E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E0u);
	// 0x27E8D8: subss xmm0, [0x0056A068]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A068u);
	// 0x27E8E0: movss [0x0056A0C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0C0u, ctx.xmm[0].u32[0]);
	// 0x27E8E8: ret
	return;
}

void sub_27E8F0(X86Context& ctx, uint8_t* base) {
	// 0x27E8F0: movss xmm0, dword ptr [0x0056A0C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0C0u);
	// 0x27E8F8: subss xmm0, [0x0056A094]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A094u);
	// 0x27E900: movss [0x0056A0B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0B8u, ctx.xmm[0].u32[0]);
	// 0x27E908: ret
	return;
}

void sub_27E910(X86Context& ctx, uint8_t* base) {
	// 0x27E910: movss xmm0, dword ptr [0x0056A0E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0E8u);
	// 0x27E918: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27E920: movss [0x0056A0A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0A4u, ctx.xmm[0].u32[0]);
	// 0x27E928: ret
	return;
}

void sub_27E930(X86Context& ctx, uint8_t* base) {
	// 0x27E930: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27E938: movss [0x0056A090], xmm0
	X86_MEM_WRITE_u32(base, 0x56A090u, ctx.xmm[0].u32[0]);
	// 0x27E940: ret
	return;
}

void sub_27E950(X86Context& ctx, uint8_t* base) {
	// 0x27E950: movss xmm0, dword ptr [0x0056A0A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A0A4u);
	// 0x27E958: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27E960: movss [0x0056A0D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0D8u, ctx.xmm[0].u32[0]);
	// 0x27E968: ret
	return;
}

void sub_27E970(X86Context& ctx, uint8_t* base) {
	// 0x27E970: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27E978: movss [0x0056A0AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A0ACu, ctx.xmm[0].u32[0]);
	// 0x27E980: ret
	return;
}

void sub_27E990(X86Context& ctx, uint8_t* base) {
	// 0x27E990: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27E998: movss [0x0056A084], xmm0
	X86_MEM_WRITE_u32(base, 0x56A084u, ctx.xmm[0].u32[0]);
	// 0x27E9A0: ret
	return;
}

void sub_27E9B0(X86Context& ctx, uint8_t* base) {
	// 0x27E9B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27E9B8: movss [0x0056A164], xmm0
	X86_MEM_WRITE_u32(base, 0x56A164u, ctx.xmm[0].u32[0]);
	// 0x27E9C0: ret
	return;
}

void sub_27E9D0(X86Context& ctx, uint8_t* base) {
	// 0x27E9D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27E9D8: movss [0x0056A180], xmm0
	X86_MEM_WRITE_u32(base, 0x56A180u, ctx.xmm[0].u32[0]);
	// 0x27E9E0: ret
	return;
}

void sub_27E9F0(X86Context& ctx, uint8_t* base) {
	// 0x27E9F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27E9F8: movss [0x0056A154], xmm0
	X86_MEM_WRITE_u32(base, 0x56A154u, ctx.xmm[0].u32[0]);
	// 0x27EA00: ret
	return;
}

void sub_27EA10(X86Context& ctx, uint8_t* base) {
	// 0x27EA10: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27EA18: movss [0x0056A108], xmm0
	X86_MEM_WRITE_u32(base, 0x56A108u, ctx.xmm[0].u32[0]);
	// 0x27EA20: ret
	return;
}

void sub_27EA30(X86Context& ctx, uint8_t* base) {
	// 0x27EA30: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27EA38: movss [0x0056A168], xmm0
	X86_MEM_WRITE_u32(base, 0x56A168u, ctx.xmm[0].u32[0]);
	// 0x27EA40: ret
	return;
}

void sub_27EA50(X86Context& ctx, uint8_t* base) {
	// 0x27EA50: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27EA58: movss [0x0056A124], xmm0
	X86_MEM_WRITE_u32(base, 0x56A124u, ctx.xmm[0].u32[0]);
	// 0x27EA60: ret
	return;
}

void sub_27EA70(X86Context& ctx, uint8_t* base) {
	// 0x27EA70: movss xmm0, dword ptr [0x0056A168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A168u);
	// 0x27EA78: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27EA80: movss [0x0056A1A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1A0u, ctx.xmm[0].u32[0]);
	// 0x27EA88: ret
	return;
}

void sub_27EA90(X86Context& ctx, uint8_t* base) {
	// 0x27EA90: movss xmm0, dword ptr [0x0056A124]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A124u);
	// 0x27EA98: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27EAA0: movss [0x0056A188], xmm0
	X86_MEM_WRITE_u32(base, 0x56A188u, ctx.xmm[0].u32[0]);
	// 0x27EAA8: ret
	return;
}

void sub_27EAB0(X86Context& ctx, uint8_t* base) {
	// 0x27EAB0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27EAB8: movss [0x0056A1B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1B8u, ctx.xmm[0].u32[0]);
	// 0x27EAC0: ret
	return;
}

void sub_27EAD0(X86Context& ctx, uint8_t* base) {
	// 0x27EAD0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27EAD8: movss [0x0056A1A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1A4u, ctx.xmm[0].u32[0]);
	// 0x27EAE0: ret
	return;
}

void sub_27EAF0(X86Context& ctx, uint8_t* base) {
	// 0x27EAF0: movss xmm0, dword ptr [0x0056A1A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1A4u);
	// 0x27EAF8: movss [0x0056A1B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1B4u, ctx.xmm[0].u32[0]);
	// 0x27EB00: ret
	return;
}

void sub_27EB10(X86Context& ctx, uint8_t* base) {
	// 0x27EB10: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27EB18: movss [0x0056A110], xmm0
	X86_MEM_WRITE_u32(base, 0x56A110u, ctx.xmm[0].u32[0]);
	// 0x27EB20: ret
	return;
}

void sub_27EB30(X86Context& ctx, uint8_t* base) {
	// 0x27EB30: movss xmm0, dword ptr [0x0056A124]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A124u);
	// 0x27EB38: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27EB40: movss [0x0056A1AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1ACu, ctx.xmm[0].u32[0]);
	// 0x27EB48: ret
	return;
}

void sub_27EB50(X86Context& ctx, uint8_t* base) {
	// 0x27EB50: movss xmm0, dword ptr [0x0056A124]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A124u);
	// 0x27EB58: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27EB60: movss [0x0056A150], xmm0
	X86_MEM_WRITE_u32(base, 0x56A150u, ctx.xmm[0].u32[0]);
	// 0x27EB68: ret
	return;
}

void sub_27EB70(X86Context& ctx, uint8_t* base) {
	// 0x27EB70: movss xmm0, dword ptr [0x0056A124]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A124u);
	// 0x27EB78: subss xmm0, [0x0056A150]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A150u);
	// 0x27EB80: movss [0x0056A12C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A12Cu, ctx.xmm[0].u32[0]);
	// 0x27EB88: ret
	return;
}

void sub_27EB90(X86Context& ctx, uint8_t* base) {
	// 0x27EB90: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27EB98: movss [0x0056A17C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A17Cu, ctx.xmm[0].u32[0]);
	// 0x27EBA0: ret
	return;
}

void sub_27EBB0(X86Context& ctx, uint8_t* base) {
	// 0x27EBB0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27EBB8: movss [0x0056A128], xmm0
	X86_MEM_WRITE_u32(base, 0x56A128u, ctx.xmm[0].u32[0]);
	// 0x27EBC0: ret
	return;
}

void sub_27EBD0(X86Context& ctx, uint8_t* base) {
	// 0x27EBD0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27EBD8: movss [0x0056A13C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A13Cu, ctx.xmm[0].u32[0]);
	// 0x27EBE0: ret
	return;
}

void sub_27EBF0(X86Context& ctx, uint8_t* base) {
	// 0x27EBF0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27EBF8: movss [0x0056A194], xmm0
	X86_MEM_WRITE_u32(base, 0x56A194u, ctx.xmm[0].u32[0]);
	// 0x27EC00: ret
	return;
}

void sub_27EC10(X86Context& ctx, uint8_t* base) {
	// 0x27EC10: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27EC18: movss [0x0056A178], xmm0
	X86_MEM_WRITE_u32(base, 0x56A178u, ctx.xmm[0].u32[0]);
	// 0x27EC20: ret
	return;
}

void sub_27EC30(X86Context& ctx, uint8_t* base) {
	// 0x27EC30: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27EC38: movss [0x0056A120], xmm0
	X86_MEM_WRITE_u32(base, 0x56A120u, ctx.xmm[0].u32[0]);
	// 0x27EC40: ret
	return;
}

void sub_27EC50(X86Context& ctx, uint8_t* base) {
	// 0x27EC50: movss xmm0, dword ptr [0x0056A13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A13Cu);
	// 0x27EC58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27EC60: movss [0x0056A114], xmm0
	X86_MEM_WRITE_u32(base, 0x56A114u, ctx.xmm[0].u32[0]);
	// 0x27EC68: ret
	return;
}

void sub_27EC70(X86Context& ctx, uint8_t* base) {
	// 0x27EC70: movss xmm0, dword ptr [0x0056A194]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A194u);
	// 0x27EC78: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27EC80: movss [0x0056A15C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A15Cu, ctx.xmm[0].u32[0]);
	// 0x27EC88: ret
	return;
}

void sub_27EC90(X86Context& ctx, uint8_t* base) {
	// 0x27EC90: movss xmm0, dword ptr [0x0056A114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A114u);
	// 0x27EC98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27ECA0: movss [0x0056A170], xmm0
	X86_MEM_WRITE_u32(base, 0x56A170u, ctx.xmm[0].u32[0]);
	// 0x27ECA8: ret
	return;
}

void sub_27ECB0(X86Context& ctx, uint8_t* base) {
	// 0x27ECB0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27ECB8: movss [0x0056A10C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A10Cu, ctx.xmm[0].u32[0]);
	// 0x27ECC0: ret
	return;
}

void sub_27ECD0(X86Context& ctx, uint8_t* base) {
	// 0x27ECD0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27ECD8: movss [0x0056A140], xmm0
	X86_MEM_WRITE_u32(base, 0x56A140u, ctx.xmm[0].u32[0]);
	// 0x27ECE0: ret
	return;
}

void sub_27ECF0(X86Context& ctx, uint8_t* base) {
	// 0x27ECF0: movss xmm0, dword ptr [0x0056A13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A13Cu);
	// 0x27ECF8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27ED00: movss [0x0056A14C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A14Cu, ctx.xmm[0].u32[0]);
	// 0x27ED08: ret
	return;
}

void sub_27ED10(X86Context& ctx, uint8_t* base) {
	// 0x27ED10: movss xmm0, dword ptr [0x0056A194]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A194u);
	// 0x27ED18: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27ED20: movss [0x0056A198], xmm0
	X86_MEM_WRITE_u32(base, 0x56A198u, ctx.xmm[0].u32[0]);
	// 0x27ED28: ret
	return;
}

void sub_27ED30(X86Context& ctx, uint8_t* base) {
	// 0x27ED30: movss xmm0, dword ptr [0x0056A14C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A14Cu);
	// 0x27ED38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27ED40: movss [0x0056A184], xmm0
	X86_MEM_WRITE_u32(base, 0x56A184u, ctx.xmm[0].u32[0]);
	// 0x27ED48: ret
	return;
}

void sub_27ED50(X86Context& ctx, uint8_t* base) {
	// 0x27ED50: movss xmm0, dword ptr [0x0056A198]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A198u);
	// 0x27ED58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27ED60: movss [0x0056A1A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1A8u, ctx.xmm[0].u32[0]);
	// 0x27ED68: ret
	return;
}

void sub_27ED70(X86Context& ctx, uint8_t* base) {
	// 0x27ED70: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27ED78: movss [0x0056A118], xmm0
	X86_MEM_WRITE_u32(base, 0x56A118u, ctx.xmm[0].u32[0]);
	// 0x27ED80: ret
	return;
}

void sub_27ED90(X86Context& ctx, uint8_t* base) {
	// 0x27ED90: movss xmm0, dword ptr [0x0056A13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A13Cu);
	// 0x27ED98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27EDA0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27EDA8: movss [0x0056A190], xmm0
	X86_MEM_WRITE_u32(base, 0x56A190u, ctx.xmm[0].u32[0]);
	// 0x27EDB0: ret
	return;
}

void sub_27EDC0(X86Context& ctx, uint8_t* base) {
	// 0x27EDC0: movss xmm0, dword ptr [0x0056A194]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A194u);
	// 0x27EDC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27EDD0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27EDD8: movss [0x0056A130], xmm0
	X86_MEM_WRITE_u32(base, 0x56A130u, ctx.xmm[0].u32[0]);
	// 0x27EDE0: ret
	return;
}

void sub_27EDF0(X86Context& ctx, uint8_t* base) {
	// 0x27EDF0: movss xmm0, dword ptr [0x0056A13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A13Cu);
	// 0x27EDF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27EE00: movss [0x0056A134], xmm0
	X86_MEM_WRITE_u32(base, 0x56A134u, ctx.xmm[0].u32[0]);
	// 0x27EE08: ret
	return;
}

void sub_27EE10(X86Context& ctx, uint8_t* base) {
	// 0x27EE10: movss xmm0, dword ptr [0x0056A194]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A194u);
	// 0x27EE18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27EE20: movss [0x0056A19C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A19Cu, ctx.xmm[0].u32[0]);
	// 0x27EE28: ret
	return;
}

void sub_27EE30(X86Context& ctx, uint8_t* base) {
	// 0x27EE30: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27EE38: movss [0x0056A11C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A11Cu, ctx.xmm[0].u32[0]);
	// 0x27EE40: ret
	return;
}

void sub_27EE50(X86Context& ctx, uint8_t* base) {
	// 0x27EE50: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27EE58: movss [0x0056A148], xmm0
	X86_MEM_WRITE_u32(base, 0x56A148u, ctx.xmm[0].u32[0]);
	// 0x27EE60: ret
	return;
}

void sub_27EE70(X86Context& ctx, uint8_t* base) {
	// 0x27EE70: movss xmm0, dword ptr [0x0056A11C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A11Cu);
	// 0x27EE78: movss [0x0056A1B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1B0u, ctx.xmm[0].u32[0]);
	// 0x27EE80: ret
	return;
}

void sub_27EE90(X86Context& ctx, uint8_t* base) {
	// 0x27EE90: movss xmm0, dword ptr [0x0056A194]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A194u);
	// 0x27EE98: subss xmm0, [0x0056A11C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A11Cu);
	// 0x27EEA0: movss [0x0056A174], xmm0
	X86_MEM_WRITE_u32(base, 0x56A174u, ctx.xmm[0].u32[0]);
	// 0x27EEA8: ret
	return;
}

void sub_27EEB0(X86Context& ctx, uint8_t* base) {
	// 0x27EEB0: movss xmm0, dword ptr [0x0056A174]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A174u);
	// 0x27EEB8: subss xmm0, [0x0056A148]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A148u);
	// 0x27EEC0: movss [0x0056A16C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A16Cu, ctx.xmm[0].u32[0]);
	// 0x27EEC8: ret
	return;
}

void sub_27EED0(X86Context& ctx, uint8_t* base) {
	// 0x27EED0: movss xmm0, dword ptr [0x0056A19C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A19Cu);
	// 0x27EED8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27EEE0: movss [0x0056A158], xmm0
	X86_MEM_WRITE_u32(base, 0x56A158u, ctx.xmm[0].u32[0]);
	// 0x27EEE8: ret
	return;
}

void sub_27EEF0(X86Context& ctx, uint8_t* base) {
	// 0x27EEF0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27EEF8: movss [0x0056A144], xmm0
	X86_MEM_WRITE_u32(base, 0x56A144u, ctx.xmm[0].u32[0]);
	// 0x27EF00: ret
	return;
}

void sub_27EF10(X86Context& ctx, uint8_t* base) {
	// 0x27EF10: movss xmm0, dword ptr [0x0056A158]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A158u);
	// 0x27EF18: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27EF20: movss [0x0056A18C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A18Cu, ctx.xmm[0].u32[0]);
	// 0x27EF28: ret
	return;
}

void sub_27EF30(X86Context& ctx, uint8_t* base) {
	// 0x27EF30: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27EF38: movss [0x0056A160], xmm0
	X86_MEM_WRITE_u32(base, 0x56A160u, ctx.xmm[0].u32[0]);
	// 0x27EF40: ret
	return;
}

void sub_27EF50(X86Context& ctx, uint8_t* base) {
	// 0x27EF50: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27EF58: movss [0x0056A138], xmm0
	X86_MEM_WRITE_u32(base, 0x56A138u, ctx.xmm[0].u32[0]);
	// 0x27EF60: ret
	return;
}

void sub_27EF70(X86Context& ctx, uint8_t* base) {
	// 0x27EF70: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27EF78: movss [0x0056A218], xmm0
	X86_MEM_WRITE_u32(base, 0x56A218u, ctx.xmm[0].u32[0]);
	// 0x27EF80: ret
	return;
}

void sub_27EF90(X86Context& ctx, uint8_t* base) {
	// 0x27EF90: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27EF98: movss [0x0056A234], xmm0
	X86_MEM_WRITE_u32(base, 0x56A234u, ctx.xmm[0].u32[0]);
	// 0x27EFA0: ret
	return;
}

void sub_27EFB0(X86Context& ctx, uint8_t* base) {
	// 0x27EFB0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27EFB8: movss [0x0056A208], xmm0
	X86_MEM_WRITE_u32(base, 0x56A208u, ctx.xmm[0].u32[0]);
	// 0x27EFC0: ret
	return;
}

void sub_27EFD0(X86Context& ctx, uint8_t* base) {
	// 0x27EFD0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27EFD8: movss [0x0056A1BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1BCu, ctx.xmm[0].u32[0]);
	// 0x27EFE0: ret
	return;
}

void sub_27EFF0(X86Context& ctx, uint8_t* base) {
	// 0x27EFF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27EFF8: movss [0x0056A21C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A21Cu, ctx.xmm[0].u32[0]);
	// 0x27F000: ret
	return;
}

void sub_27F010(X86Context& ctx, uint8_t* base) {
	// 0x27F010: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27F018: movss [0x0056A1D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1D8u, ctx.xmm[0].u32[0]);
	// 0x27F020: ret
	return;
}

void sub_27F030(X86Context& ctx, uint8_t* base) {
	// 0x27F030: movss xmm0, dword ptr [0x0056A21C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A21Cu);
	// 0x27F038: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27F040: movss [0x0056A254], xmm0
	X86_MEM_WRITE_u32(base, 0x56A254u, ctx.xmm[0].u32[0]);
	// 0x27F048: ret
	return;
}

void sub_27F050(X86Context& ctx, uint8_t* base) {
	// 0x27F050: movss xmm0, dword ptr [0x0056A1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1D8u);
	// 0x27F058: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27F060: movss [0x0056A23C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A23Cu, ctx.xmm[0].u32[0]);
	// 0x27F068: ret
	return;
}

void sub_27F070(X86Context& ctx, uint8_t* base) {
	// 0x27F070: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27F078: movss [0x0056A26C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A26Cu, ctx.xmm[0].u32[0]);
	// 0x27F080: ret
	return;
}

void sub_27F090(X86Context& ctx, uint8_t* base) {
	// 0x27F090: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27F098: movss [0x0056A258], xmm0
	X86_MEM_WRITE_u32(base, 0x56A258u, ctx.xmm[0].u32[0]);
	// 0x27F0A0: ret
	return;
}

void sub_27F0B0(X86Context& ctx, uint8_t* base) {
	// 0x27F0B0: movss xmm0, dword ptr [0x0056A258]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A258u);
	// 0x27F0B8: movss [0x0056A268], xmm0
	X86_MEM_WRITE_u32(base, 0x56A268u, ctx.xmm[0].u32[0]);
	// 0x27F0C0: ret
	return;
}

void sub_27F0D0(X86Context& ctx, uint8_t* base) {
	// 0x27F0D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27F0D8: movss [0x0056A1C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1C4u, ctx.xmm[0].u32[0]);
	// 0x27F0E0: ret
	return;
}

void sub_27F0F0(X86Context& ctx, uint8_t* base) {
	// 0x27F0F0: movss xmm0, dword ptr [0x0056A1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1D8u);
	// 0x27F0F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27F100: movss [0x0056A260], xmm0
	X86_MEM_WRITE_u32(base, 0x56A260u, ctx.xmm[0].u32[0]);
	// 0x27F108: ret
	return;
}

void sub_27F110(X86Context& ctx, uint8_t* base) {
	// 0x27F110: movss xmm0, dword ptr [0x0056A1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1D8u);
	// 0x27F118: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27F120: movss [0x0056A204], xmm0
	X86_MEM_WRITE_u32(base, 0x56A204u, ctx.xmm[0].u32[0]);
	// 0x27F128: ret
	return;
}

void sub_27F130(X86Context& ctx, uint8_t* base) {
	// 0x27F130: movss xmm0, dword ptr [0x0056A1D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1D8u);
	// 0x27F138: subss xmm0, [0x0056A204]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A204u);
	// 0x27F140: movss [0x0056A1E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1E0u, ctx.xmm[0].u32[0]);
	// 0x27F148: ret
	return;
}

void sub_27F150(X86Context& ctx, uint8_t* base) {
	// 0x27F150: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27F158: movss [0x0056A230], xmm0
	X86_MEM_WRITE_u32(base, 0x56A230u, ctx.xmm[0].u32[0]);
	// 0x27F160: ret
	return;
}

void sub_27F170(X86Context& ctx, uint8_t* base) {
	// 0x27F170: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27F178: movss [0x0056A1DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1DCu, ctx.xmm[0].u32[0]);
	// 0x27F180: ret
	return;
}

void sub_27F190(X86Context& ctx, uint8_t* base) {
	// 0x27F190: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27F198: movss [0x0056A1F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1F0u, ctx.xmm[0].u32[0]);
	// 0x27F1A0: ret
	return;
}

void sub_27F1B0(X86Context& ctx, uint8_t* base) {
	// 0x27F1B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27F1B8: movss [0x0056A248], xmm0
	X86_MEM_WRITE_u32(base, 0x56A248u, ctx.xmm[0].u32[0]);
	// 0x27F1C0: ret
	return;
}

void sub_27F1D0(X86Context& ctx, uint8_t* base) {
	// 0x27F1D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27F1D8: movss [0x0056A22C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A22Cu, ctx.xmm[0].u32[0]);
	// 0x27F1E0: ret
	return;
}

void sub_27F1F0(X86Context& ctx, uint8_t* base) {
	// 0x27F1F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27F1F8: movss [0x0056A1D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1D4u, ctx.xmm[0].u32[0]);
	// 0x27F200: ret
	return;
}

void sub_27F210(X86Context& ctx, uint8_t* base) {
	// 0x27F210: movss xmm0, dword ptr [0x0056A1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1F0u);
	// 0x27F218: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27F220: movss [0x0056A1C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1C8u, ctx.xmm[0].u32[0]);
	// 0x27F228: ret
	return;
}

void sub_27F230(X86Context& ctx, uint8_t* base) {
	// 0x27F230: movss xmm0, dword ptr [0x0056A248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A248u);
	// 0x27F238: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27F240: movss [0x0056A210], xmm0
	X86_MEM_WRITE_u32(base, 0x56A210u, ctx.xmm[0].u32[0]);
	// 0x27F248: ret
	return;
}

void sub_27F250(X86Context& ctx, uint8_t* base) {
	// 0x27F250: movss xmm0, dword ptr [0x0056A1C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1C8u);
	// 0x27F258: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27F260: movss [0x0056A224], xmm0
	X86_MEM_WRITE_u32(base, 0x56A224u, ctx.xmm[0].u32[0]);
	// 0x27F268: ret
	return;
}

void sub_27F270(X86Context& ctx, uint8_t* base) {
	// 0x27F270: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27F278: movss [0x0056A1C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1C0u, ctx.xmm[0].u32[0]);
	// 0x27F280: ret
	return;
}

void sub_27F290(X86Context& ctx, uint8_t* base) {
	// 0x27F290: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27F298: movss [0x0056A1F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1F4u, ctx.xmm[0].u32[0]);
	// 0x27F2A0: ret
	return;
}

void sub_27F2B0(X86Context& ctx, uint8_t* base) {
	// 0x27F2B0: movss xmm0, dword ptr [0x0056A1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1F0u);
	// 0x27F2B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27F2C0: movss [0x0056A200], xmm0
	X86_MEM_WRITE_u32(base, 0x56A200u, ctx.xmm[0].u32[0]);
	// 0x27F2C8: ret
	return;
}

void sub_27F2D0(X86Context& ctx, uint8_t* base) {
	// 0x27F2D0: movss xmm0, dword ptr [0x0056A248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A248u);
	// 0x27F2D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27F2E0: movss [0x0056A24C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A24Cu, ctx.xmm[0].u32[0]);
	// 0x27F2E8: ret
	return;
}

void sub_27F2F0(X86Context& ctx, uint8_t* base) {
	// 0x27F2F0: movss xmm0, dword ptr [0x0056A200]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A200u);
	// 0x27F2F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27F300: movss [0x0056A238], xmm0
	X86_MEM_WRITE_u32(base, 0x56A238u, ctx.xmm[0].u32[0]);
	// 0x27F308: ret
	return;
}

void sub_27F310(X86Context& ctx, uint8_t* base) {
	// 0x27F310: movss xmm0, dword ptr [0x0056A24C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A24Cu);
	// 0x27F318: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27F320: movss [0x0056A25C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A25Cu, ctx.xmm[0].u32[0]);
	// 0x27F328: ret
	return;
}

void sub_27F330(X86Context& ctx, uint8_t* base) {
	// 0x27F330: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27F338: movss [0x0056A1CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1CCu, ctx.xmm[0].u32[0]);
	// 0x27F340: ret
	return;
}

void sub_27F350(X86Context& ctx, uint8_t* base) {
	// 0x27F350: movss xmm0, dword ptr [0x0056A1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1F0u);
	// 0x27F358: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27F360: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27F368: movss [0x0056A244], xmm0
	X86_MEM_WRITE_u32(base, 0x56A244u, ctx.xmm[0].u32[0]);
	// 0x27F370: ret
	return;
}

void sub_27F380(X86Context& ctx, uint8_t* base) {
	// 0x27F380: movss xmm0, dword ptr [0x0056A248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A248u);
	// 0x27F388: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27F390: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27F398: movss [0x0056A1E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1E4u, ctx.xmm[0].u32[0]);
	// 0x27F3A0: ret
	return;
}

void sub_27F3B0(X86Context& ctx, uint8_t* base) {
	// 0x27F3B0: movss xmm0, dword ptr [0x0056A1F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1F0u);
	// 0x27F3B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27F3C0: movss [0x0056A1E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1E8u, ctx.xmm[0].u32[0]);
	// 0x27F3C8: ret
	return;
}

void sub_27F3D0(X86Context& ctx, uint8_t* base) {
	// 0x27F3D0: movss xmm0, dword ptr [0x0056A248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A248u);
	// 0x27F3D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27F3E0: movss [0x0056A250], xmm0
	X86_MEM_WRITE_u32(base, 0x56A250u, ctx.xmm[0].u32[0]);
	// 0x27F3E8: ret
	return;
}

void sub_27F3F0(X86Context& ctx, uint8_t* base) {
	// 0x27F3F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27F3F8: movss [0x0056A1D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1D0u, ctx.xmm[0].u32[0]);
	// 0x27F400: ret
	return;
}

void sub_27F410(X86Context& ctx, uint8_t* base) {
	// 0x27F410: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27F418: movss [0x0056A1FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1FCu, ctx.xmm[0].u32[0]);
	// 0x27F420: ret
	return;
}

void sub_27F430(X86Context& ctx, uint8_t* base) {
	// 0x27F430: movss xmm0, dword ptr [0x0056A1D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A1D0u);
	// 0x27F438: movss [0x0056A264], xmm0
	X86_MEM_WRITE_u32(base, 0x56A264u, ctx.xmm[0].u32[0]);
	// 0x27F440: ret
	return;
}

void sub_27F450(X86Context& ctx, uint8_t* base) {
	// 0x27F450: movss xmm0, dword ptr [0x0056A248]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A248u);
	// 0x27F458: subss xmm0, [0x0056A1D0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A1D0u);
	// 0x27F460: movss [0x0056A228], xmm0
	X86_MEM_WRITE_u32(base, 0x56A228u, ctx.xmm[0].u32[0]);
	// 0x27F468: ret
	return;
}

void sub_27F470(X86Context& ctx, uint8_t* base) {
	// 0x27F470: movss xmm0, dword ptr [0x0056A228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A228u);
	// 0x27F478: subss xmm0, [0x0056A1FC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56A1FCu);
	// 0x27F480: movss [0x0056A220], xmm0
	X86_MEM_WRITE_u32(base, 0x56A220u, ctx.xmm[0].u32[0]);
	// 0x27F488: ret
	return;
}

void sub_27F490(X86Context& ctx, uint8_t* base) {
	// 0x27F490: movss xmm0, dword ptr [0x0056A250]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A250u);
	// 0x27F498: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27F4A0: movss [0x0056A20C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A20Cu, ctx.xmm[0].u32[0]);
	// 0x27F4A8: ret
	return;
}

void sub_27F4B0(X86Context& ctx, uint8_t* base) {
	// 0x27F4B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27F4B8: movss [0x0056A1F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1F8u, ctx.xmm[0].u32[0]);
	// 0x27F4C0: ret
	return;
}

void sub_27F4D0(X86Context& ctx, uint8_t* base) {
	// 0x27F4D0: movss xmm0, dword ptr [0x0056A20C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A20Cu);
	// 0x27F4D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27F4E0: movss [0x0056A240], xmm0
	X86_MEM_WRITE_u32(base, 0x56A240u, ctx.xmm[0].u32[0]);
	// 0x27F4E8: ret
	return;
}

void sub_27F4F0(X86Context& ctx, uint8_t* base) {
	// 0x27F4F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27F4F8: movss [0x0056A214], xmm0
	X86_MEM_WRITE_u32(base, 0x56A214u, ctx.xmm[0].u32[0]);
	// 0x27F500: ret
	return;
}

void sub_27F510(X86Context& ctx, uint8_t* base) {
	// 0x27F510: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27F518: movss [0x0056A1EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A1ECu, ctx.xmm[0].u32[0]);
	// 0x27F520: ret
	return;
}

void sub_27F530(X86Context& ctx, uint8_t* base) {
	// 0x27F530: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27F538: movss [0x0056A28C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A28Cu, ctx.xmm[0].u32[0]);
	// 0x27F540: ret
	return;
}

void sub_27F550(X86Context& ctx, uint8_t* base) {
	// 0x27F550: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27F558: movss [0x0056A298], xmm0
	X86_MEM_WRITE_u32(base, 0x56A298u, ctx.xmm[0].u32[0]);
	// 0x27F560: ret
	return;
}

void sub_27F570(X86Context& ctx, uint8_t* base) {
	// 0x27F570: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27F578: movss [0x0056A288], xmm0
	X86_MEM_WRITE_u32(base, 0x56A288u, ctx.xmm[0].u32[0]);
	// 0x27F580: ret
	return;
}

void sub_27F590(X86Context& ctx, uint8_t* base) {
	// 0x27F590: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27F598: movss [0x0056A270], xmm0
	X86_MEM_WRITE_u32(base, 0x56A270u, ctx.xmm[0].u32[0]);
	// 0x27F5A0: ret
	return;
}

void sub_27F5B0(X86Context& ctx, uint8_t* base) {
	// 0x27F5B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27F5B8: movss [0x0056A290], xmm0
	X86_MEM_WRITE_u32(base, 0x56A290u, ctx.xmm[0].u32[0]);
	// 0x27F5C0: ret
	return;
}

void sub_27F5D0(X86Context& ctx, uint8_t* base) {
	// 0x27F5D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27F5D8: movss [0x0056A278], xmm0
	X86_MEM_WRITE_u32(base, 0x56A278u, ctx.xmm[0].u32[0]);
	// 0x27F5E0: ret
	return;
}

void sub_27F5F0(X86Context& ctx, uint8_t* base) {
	// 0x27F5F0: movss xmm0, dword ptr [0x0056A290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A290u);
	// 0x27F5F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27F600: movss [0x0056A2A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2A0u, ctx.xmm[0].u32[0]);
	// 0x27F608: ret
	return;
}

void sub_27F610(X86Context& ctx, uint8_t* base) {
	// 0x27F610: movss xmm0, dword ptr [0x0056A278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A278u);
	// 0x27F618: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27F620: movss [0x0056A29C], xmm0
	X86_MEM_WRITE_u32(base, 0x56A29Cu, ctx.xmm[0].u32[0]);
	// 0x27F628: ret
	return;
}

void sub_27F630(X86Context& ctx, uint8_t* base) {
	// 0x27F630: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27F638: movss [0x0056A2B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2B0u, ctx.xmm[0].u32[0]);
	// 0x27F640: ret
	return;
}

void sub_27F650(X86Context& ctx, uint8_t* base) {
	// 0x27F650: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27F658: movss [0x0056A2A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2A4u, ctx.xmm[0].u32[0]);
	// 0x27F660: ret
	return;
}

void sub_27F670(X86Context& ctx, uint8_t* base) {
	// 0x27F670: movss xmm0, dword ptr [0x0056A2A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56A2A4u);
	// 0x27F678: movss [0x0056A2AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56A2ACu, ctx.xmm[0].u32[0]);
	// 0x27F680: ret
	return;
}

void sub_27F690(X86Context& ctx, uint8_t* base) {
	// 0x27F690: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27F698: movss [0x0056A274], xmm0
	X86_MEM_WRITE_u32(base, 0x56A274u, ctx.xmm[0].u32[0]);
	// 0x27F6A0: ret
	return;
}

