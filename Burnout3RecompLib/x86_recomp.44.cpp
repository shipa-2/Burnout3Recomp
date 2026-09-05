#include "x86_recomp_shared.h"

void sub_279490(X86Context& ctx, uint8_t* base) {
	// 0x279490: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x279498: movss [0x00569718], xmm0
	X86_MEM_WRITE_u32(base, 0x569718u, ctx.xmm[0].u32[0]);
	// 0x2794A0: ret
	return;
}

void sub_2794B0(X86Context& ctx, uint8_t* base) {
	// 0x2794B0: movss xmm0, dword ptr [0x00569718]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569718u);
	// 0x2794B8: movss [0x00569728], xmm0
	X86_MEM_WRITE_u32(base, 0x569728u, ctx.xmm[0].u32[0]);
	// 0x2794C0: ret
	return;
}

void sub_2794D0(X86Context& ctx, uint8_t* base) {
	// 0x2794D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2794D8: movss [0x00569684], xmm0
	X86_MEM_WRITE_u32(base, 0x569684u, ctx.xmm[0].u32[0]);
	// 0x2794E0: ret
	return;
}

void sub_2794F0(X86Context& ctx, uint8_t* base) {
	// 0x2794F0: movss xmm0, dword ptr [0x00569698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569698u);
	// 0x2794F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x279500: movss [0x00569720], xmm0
	X86_MEM_WRITE_u32(base, 0x569720u, ctx.xmm[0].u32[0]);
	// 0x279508: ret
	return;
}

void sub_279510(X86Context& ctx, uint8_t* base) {
	// 0x279510: movss xmm0, dword ptr [0x00569698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569698u);
	// 0x279518: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x279520: movss [0x005696C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5696C4u, ctx.xmm[0].u32[0]);
	// 0x279528: ret
	return;
}

void sub_279530(X86Context& ctx, uint8_t* base) {
	// 0x279530: movss xmm0, dword ptr [0x00569698]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569698u);
	// 0x279538: subss xmm0, [0x005696C4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5696C4u);
	// 0x279540: movss [0x005696A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5696A0u, ctx.xmm[0].u32[0]);
	// 0x279548: ret
	return;
}

void sub_279550(X86Context& ctx, uint8_t* base) {
	// 0x279550: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x279558: movss [0x005696F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5696F4u, ctx.xmm[0].u32[0]);
	// 0x279560: ret
	return;
}

void sub_279570(X86Context& ctx, uint8_t* base) {
	// 0x279570: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x279578: movss [0x0056969C], xmm0
	X86_MEM_WRITE_u32(base, 0x56969Cu, ctx.xmm[0].u32[0]);
	// 0x279580: ret
	return;
}

void sub_279590(X86Context& ctx, uint8_t* base) {
	// 0x279590: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x279598: movss [0x005696B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5696B0u, ctx.xmm[0].u32[0]);
	// 0x2795A0: ret
	return;
}

void sub_2795B0(X86Context& ctx, uint8_t* base) {
	// 0x2795B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2795B8: movss [0x00569708], xmm0
	X86_MEM_WRITE_u32(base, 0x569708u, ctx.xmm[0].u32[0]);
	// 0x2795C0: ret
	return;
}

void sub_2795D0(X86Context& ctx, uint8_t* base) {
	// 0x2795D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2795D8: movss [0x005696F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5696F0u, ctx.xmm[0].u32[0]);
	// 0x2795E0: ret
	return;
}

void sub_2795F0(X86Context& ctx, uint8_t* base) {
	// 0x2795F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2795F8: movss [0x00569694], xmm0
	X86_MEM_WRITE_u32(base, 0x569694u, ctx.xmm[0].u32[0]);
	// 0x279600: ret
	return;
}

void sub_279610(X86Context& ctx, uint8_t* base) {
	// 0x279610: movss xmm0, dword ptr [0x005696B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696B0u);
	// 0x279618: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x279620: movss [0x00569688], xmm0
	X86_MEM_WRITE_u32(base, 0x569688u, ctx.xmm[0].u32[0]);
	// 0x279628: ret
	return;
}

void sub_279630(X86Context& ctx, uint8_t* base) {
	// 0x279630: movss xmm0, dword ptr [0x00569708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569708u);
	// 0x279638: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x279640: movss [0x005696D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5696D0u, ctx.xmm[0].u32[0]);
	// 0x279648: ret
	return;
}

void sub_279650(X86Context& ctx, uint8_t* base) {
	// 0x279650: movss xmm0, dword ptr [0x00569688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569688u);
	// 0x279658: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x279660: movss [0x005696E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5696E8u, ctx.xmm[0].u32[0]);
	// 0x279668: ret
	return;
}

void sub_279670(X86Context& ctx, uint8_t* base) {
	// 0x279670: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x279678: movss [0x00569680], xmm0
	X86_MEM_WRITE_u32(base, 0x569680u, ctx.xmm[0].u32[0]);
	// 0x279680: ret
	return;
}

void sub_279690(X86Context& ctx, uint8_t* base) {
	// 0x279690: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x279698: movss [0x005696B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5696B4u, ctx.xmm[0].u32[0]);
	// 0x2796A0: ret
	return;
}

void sub_2796B0(X86Context& ctx, uint8_t* base) {
	// 0x2796B0: movss xmm0, dword ptr [0x005696B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696B0u);
	// 0x2796B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2796C0: movss [0x005696C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5696C0u, ctx.xmm[0].u32[0]);
	// 0x2796C8: ret
	return;
}

void sub_2796D0(X86Context& ctx, uint8_t* base) {
	// 0x2796D0: movss xmm0, dword ptr [0x00569708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569708u);
	// 0x2796D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2796E0: movss [0x0056970C], xmm0
	X86_MEM_WRITE_u32(base, 0x56970Cu, ctx.xmm[0].u32[0]);
	// 0x2796E8: ret
	return;
}

void sub_2796F0(X86Context& ctx, uint8_t* base) {
	// 0x2796F0: movss xmm0, dword ptr [0x005696C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696C0u);
	// 0x2796F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279700: movss [0x005696F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5696F8u, ctx.xmm[0].u32[0]);
	// 0x279708: ret
	return;
}

void sub_279710(X86Context& ctx, uint8_t* base) {
	// 0x279710: movss xmm0, dword ptr [0x0056970C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56970Cu);
	// 0x279718: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279720: movss [0x0056971C], xmm0
	X86_MEM_WRITE_u32(base, 0x56971Cu, ctx.xmm[0].u32[0]);
	// 0x279728: ret
	return;
}

void sub_279730(X86Context& ctx, uint8_t* base) {
	// 0x279730: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x279738: movss [0x0056968C], xmm0
	X86_MEM_WRITE_u32(base, 0x56968Cu, ctx.xmm[0].u32[0]);
	// 0x279740: ret
	return;
}

void sub_279750(X86Context& ctx, uint8_t* base) {
	// 0x279750: movss xmm0, dword ptr [0x005696B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696B0u);
	// 0x279758: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279760: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x279768: movss [0x00569704], xmm0
	X86_MEM_WRITE_u32(base, 0x569704u, ctx.xmm[0].u32[0]);
	// 0x279770: ret
	return;
}

void sub_279780(X86Context& ctx, uint8_t* base) {
	// 0x279780: movss xmm0, dword ptr [0x00569708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569708u);
	// 0x279788: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279790: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x279798: movss [0x005696A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5696A4u, ctx.xmm[0].u32[0]);
	// 0x2797A0: ret
	return;
}

void sub_2797B0(X86Context& ctx, uint8_t* base) {
	// 0x2797B0: movss xmm0, dword ptr [0x005696B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696B0u);
	// 0x2797B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2797C0: movss [0x005696A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5696A8u, ctx.xmm[0].u32[0]);
	// 0x2797C8: ret
	return;
}

void sub_2797D0(X86Context& ctx, uint8_t* base) {
	// 0x2797D0: movss xmm0, dword ptr [0x00569708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569708u);
	// 0x2797D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2797E0: movss [0x00569710], xmm0
	X86_MEM_WRITE_u32(base, 0x569710u, ctx.xmm[0].u32[0]);
	// 0x2797E8: ret
	return;
}

void sub_2797F0(X86Context& ctx, uint8_t* base) {
	// 0x2797F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2797F8: movss [0x00569690], xmm0
	X86_MEM_WRITE_u32(base, 0x569690u, ctx.xmm[0].u32[0]);
	// 0x279800: ret
	return;
}

void sub_279810(X86Context& ctx, uint8_t* base) {
	// 0x279810: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x279818: movss [0x005696BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5696BCu, ctx.xmm[0].u32[0]);
	// 0x279820: ret
	return;
}

void sub_279830(X86Context& ctx, uint8_t* base) {
	// 0x279830: movss xmm0, dword ptr [0x00569690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569690u);
	// 0x279838: movss [0x00569724], xmm0
	X86_MEM_WRITE_u32(base, 0x569724u, ctx.xmm[0].u32[0]);
	// 0x279840: ret
	return;
}

void sub_279850(X86Context& ctx, uint8_t* base) {
	// 0x279850: movss xmm0, dword ptr [0x00569708]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569708u);
	// 0x279858: subss xmm0, [0x00569690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569690u);
	// 0x279860: movss [0x005696EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5696ECu, ctx.xmm[0].u32[0]);
	// 0x279868: ret
	return;
}

void sub_279870(X86Context& ctx, uint8_t* base) {
	// 0x279870: movss xmm0, dword ptr [0x005696EC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696ECu);
	// 0x279878: subss xmm0, [0x005696BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5696BCu);
	// 0x279880: movss [0x005696E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5696E4u, ctx.xmm[0].u32[0]);
	// 0x279888: ret
	return;
}

void sub_279890(X86Context& ctx, uint8_t* base) {
	// 0x279890: movss xmm0, dword ptr [0x00569710]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569710u);
	// 0x279898: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2798A0: movss [0x005696CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5696CCu, ctx.xmm[0].u32[0]);
	// 0x2798A8: ret
	return;
}

void sub_2798B0(X86Context& ctx, uint8_t* base) {
	// 0x2798B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2798B8: movss [0x005696B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5696B8u, ctx.xmm[0].u32[0]);
	// 0x2798C0: ret
	return;
}

void sub_2798D0(X86Context& ctx, uint8_t* base) {
	// 0x2798D0: movss xmm0, dword ptr [0x005696CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5696CCu);
	// 0x2798D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2798E0: movss [0x00569700], xmm0
	X86_MEM_WRITE_u32(base, 0x569700u, ctx.xmm[0].u32[0]);
	// 0x2798E8: ret
	return;
}

void sub_2798F0(X86Context& ctx, uint8_t* base) {
	// 0x2798F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2798F8: movss [0x005696D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5696D4u, ctx.xmm[0].u32[0]);
	// 0x279900: ret
	return;
}

void sub_279910(X86Context& ctx, uint8_t* base) {
	// 0x279910: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x279918: movss [0x005696AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5696ACu, ctx.xmm[0].u32[0]);
	// 0x279920: ret
	return;
}

void sub_279930(X86Context& ctx, uint8_t* base) {
	// 0x279930: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x279938: movss [0x0056978C], xmm0
	X86_MEM_WRITE_u32(base, 0x56978Cu, ctx.xmm[0].u32[0]);
	// 0x279940: ret
	return;
}

void sub_279950(X86Context& ctx, uint8_t* base) {
	// 0x279950: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x279958: movss [0x005697A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5697A8u, ctx.xmm[0].u32[0]);
	// 0x279960: ret
	return;
}

void sub_279970(X86Context& ctx, uint8_t* base) {
	// 0x279970: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x279978: movss [0x0056977C], xmm0
	X86_MEM_WRITE_u32(base, 0x56977Cu, ctx.xmm[0].u32[0]);
	// 0x279980: ret
	return;
}

void sub_279990(X86Context& ctx, uint8_t* base) {
	// 0x279990: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x279998: movss [0x00569730], xmm0
	X86_MEM_WRITE_u32(base, 0x569730u, ctx.xmm[0].u32[0]);
	// 0x2799A0: ret
	return;
}

void sub_2799B0(X86Context& ctx, uint8_t* base) {
	// 0x2799B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2799B8: movss [0x00569790], xmm0
	X86_MEM_WRITE_u32(base, 0x569790u, ctx.xmm[0].u32[0]);
	// 0x2799C0: ret
	return;
}

void sub_2799D0(X86Context& ctx, uint8_t* base) {
	// 0x2799D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2799D8: movss [0x0056974C], xmm0
	X86_MEM_WRITE_u32(base, 0x56974Cu, ctx.xmm[0].u32[0]);
	// 0x2799E0: ret
	return;
}

void sub_2799F0(X86Context& ctx, uint8_t* base) {
	// 0x2799F0: movss xmm0, dword ptr [0x00569790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569790u);
	// 0x2799F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x279A00: movss [0x005697C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5697C8u, ctx.xmm[0].u32[0]);
	// 0x279A08: ret
	return;
}

void sub_279A10(X86Context& ctx, uint8_t* base) {
	// 0x279A10: movss xmm0, dword ptr [0x0056974C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56974Cu);
	// 0x279A18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x279A20: movss [0x005697B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5697B0u, ctx.xmm[0].u32[0]);
	// 0x279A28: ret
	return;
}

void sub_279A30(X86Context& ctx, uint8_t* base) {
	// 0x279A30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x279A38: movss [0x005697E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5697E0u, ctx.xmm[0].u32[0]);
	// 0x279A40: ret
	return;
}

void sub_279A50(X86Context& ctx, uint8_t* base) {
	// 0x279A50: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x279A58: movss [0x005697CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5697CCu, ctx.xmm[0].u32[0]);
	// 0x279A60: ret
	return;
}

void sub_279A70(X86Context& ctx, uint8_t* base) {
	// 0x279A70: movss xmm0, dword ptr [0x005697CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697CCu);
	// 0x279A78: movss [0x005697DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5697DCu, ctx.xmm[0].u32[0]);
	// 0x279A80: ret
	return;
}

void sub_279A90(X86Context& ctx, uint8_t* base) {
	// 0x279A90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x279A98: movss [0x00569738], xmm0
	X86_MEM_WRITE_u32(base, 0x569738u, ctx.xmm[0].u32[0]);
	// 0x279AA0: ret
	return;
}

void sub_279AB0(X86Context& ctx, uint8_t* base) {
	// 0x279AB0: movss xmm0, dword ptr [0x0056974C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56974Cu);
	// 0x279AB8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x279AC0: movss [0x005697D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5697D4u, ctx.xmm[0].u32[0]);
	// 0x279AC8: ret
	return;
}

void sub_279AD0(X86Context& ctx, uint8_t* base) {
	// 0x279AD0: movss xmm0, dword ptr [0x0056974C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56974Cu);
	// 0x279AD8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x279AE0: movss [0x00569778], xmm0
	X86_MEM_WRITE_u32(base, 0x569778u, ctx.xmm[0].u32[0]);
	// 0x279AE8: ret
	return;
}

void sub_279AF0(X86Context& ctx, uint8_t* base) {
	// 0x279AF0: movss xmm0, dword ptr [0x0056974C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56974Cu);
	// 0x279AF8: subss xmm0, [0x00569778]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569778u);
	// 0x279B00: movss [0x00569754], xmm0
	X86_MEM_WRITE_u32(base, 0x569754u, ctx.xmm[0].u32[0]);
	// 0x279B08: ret
	return;
}

void sub_279B10(X86Context& ctx, uint8_t* base) {
	// 0x279B10: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x279B18: movss [0x005697A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5697A4u, ctx.xmm[0].u32[0]);
	// 0x279B20: ret
	return;
}

void sub_279B30(X86Context& ctx, uint8_t* base) {
	// 0x279B30: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x279B38: movss [0x00569750], xmm0
	X86_MEM_WRITE_u32(base, 0x569750u, ctx.xmm[0].u32[0]);
	// 0x279B40: ret
	return;
}

void sub_279B50(X86Context& ctx, uint8_t* base) {
	// 0x279B50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x279B58: movss [0x00569764], xmm0
	X86_MEM_WRITE_u32(base, 0x569764u, ctx.xmm[0].u32[0]);
	// 0x279B60: ret
	return;
}

void sub_279B70(X86Context& ctx, uint8_t* base) {
	// 0x279B70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x279B78: movss [0x005697BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5697BCu, ctx.xmm[0].u32[0]);
	// 0x279B80: ret
	return;
}

void sub_279B90(X86Context& ctx, uint8_t* base) {
	// 0x279B90: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x279B98: movss [0x005697A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5697A0u, ctx.xmm[0].u32[0]);
	// 0x279BA0: ret
	return;
}

void sub_279BB0(X86Context& ctx, uint8_t* base) {
	// 0x279BB0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x279BB8: movss [0x00569748], xmm0
	X86_MEM_WRITE_u32(base, 0x569748u, ctx.xmm[0].u32[0]);
	// 0x279BC0: ret
	return;
}

void sub_279BD0(X86Context& ctx, uint8_t* base) {
	// 0x279BD0: movss xmm0, dword ptr [0x00569764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569764u);
	// 0x279BD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x279BE0: movss [0x0056973C], xmm0
	X86_MEM_WRITE_u32(base, 0x56973Cu, ctx.xmm[0].u32[0]);
	// 0x279BE8: ret
	return;
}

void sub_279BF0(X86Context& ctx, uint8_t* base) {
	// 0x279BF0: movss xmm0, dword ptr [0x005697BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697BCu);
	// 0x279BF8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x279C00: movss [0x00569784], xmm0
	X86_MEM_WRITE_u32(base, 0x569784u, ctx.xmm[0].u32[0]);
	// 0x279C08: ret
	return;
}

void sub_279C10(X86Context& ctx, uint8_t* base) {
	// 0x279C10: movss xmm0, dword ptr [0x0056973C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56973Cu);
	// 0x279C18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x279C20: movss [0x00569798], xmm0
	X86_MEM_WRITE_u32(base, 0x569798u, ctx.xmm[0].u32[0]);
	// 0x279C28: ret
	return;
}

void sub_279C30(X86Context& ctx, uint8_t* base) {
	// 0x279C30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x279C38: movss [0x00569734], xmm0
	X86_MEM_WRITE_u32(base, 0x569734u, ctx.xmm[0].u32[0]);
	// 0x279C40: ret
	return;
}

void sub_279C50(X86Context& ctx, uint8_t* base) {
	// 0x279C50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x279C58: movss [0x00569768], xmm0
	X86_MEM_WRITE_u32(base, 0x569768u, ctx.xmm[0].u32[0]);
	// 0x279C60: ret
	return;
}

void sub_279C70(X86Context& ctx, uint8_t* base) {
	// 0x279C70: movss xmm0, dword ptr [0x00569764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569764u);
	// 0x279C78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x279C80: movss [0x00569774], xmm0
	X86_MEM_WRITE_u32(base, 0x569774u, ctx.xmm[0].u32[0]);
	// 0x279C88: ret
	return;
}

void sub_279C90(X86Context& ctx, uint8_t* base) {
	// 0x279C90: movss xmm0, dword ptr [0x005697BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697BCu);
	// 0x279C98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x279CA0: movss [0x005697C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5697C0u, ctx.xmm[0].u32[0]);
	// 0x279CA8: ret
	return;
}

void sub_279CB0(X86Context& ctx, uint8_t* base) {
	// 0x279CB0: movss xmm0, dword ptr [0x00569774]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569774u);
	// 0x279CB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279CC0: movss [0x005697AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5697ACu, ctx.xmm[0].u32[0]);
	// 0x279CC8: ret
	return;
}

void sub_279CD0(X86Context& ctx, uint8_t* base) {
	// 0x279CD0: movss xmm0, dword ptr [0x005697C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697C0u);
	// 0x279CD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279CE0: movss [0x005697D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5697D0u, ctx.xmm[0].u32[0]);
	// 0x279CE8: ret
	return;
}

void sub_279CF0(X86Context& ctx, uint8_t* base) {
	// 0x279CF0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x279CF8: movss [0x00569740], xmm0
	X86_MEM_WRITE_u32(base, 0x569740u, ctx.xmm[0].u32[0]);
	// 0x279D00: ret
	return;
}

void sub_279D10(X86Context& ctx, uint8_t* base) {
	// 0x279D10: movss xmm0, dword ptr [0x00569764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569764u);
	// 0x279D18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279D20: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x279D28: movss [0x005697B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5697B8u, ctx.xmm[0].u32[0]);
	// 0x279D30: ret
	return;
}

void sub_279D40(X86Context& ctx, uint8_t* base) {
	// 0x279D40: movss xmm0, dword ptr [0x005697BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697BCu);
	// 0x279D48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279D50: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x279D58: movss [0x00569758], xmm0
	X86_MEM_WRITE_u32(base, 0x569758u, ctx.xmm[0].u32[0]);
	// 0x279D60: ret
	return;
}

void sub_279D70(X86Context& ctx, uint8_t* base) {
	// 0x279D70: movss xmm0, dword ptr [0x00569764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569764u);
	// 0x279D78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279D80: movss [0x0056975C], xmm0
	X86_MEM_WRITE_u32(base, 0x56975Cu, ctx.xmm[0].u32[0]);
	// 0x279D88: ret
	return;
}

void sub_279D90(X86Context& ctx, uint8_t* base) {
	// 0x279D90: movss xmm0, dword ptr [0x005697BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697BCu);
	// 0x279D98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x279DA0: movss [0x005697C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5697C4u, ctx.xmm[0].u32[0]);
	// 0x279DA8: ret
	return;
}

void sub_279DB0(X86Context& ctx, uint8_t* base) {
	// 0x279DB0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x279DB8: movss [0x00569744], xmm0
	X86_MEM_WRITE_u32(base, 0x569744u, ctx.xmm[0].u32[0]);
	// 0x279DC0: ret
	return;
}

void sub_279DD0(X86Context& ctx, uint8_t* base) {
	// 0x279DD0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x279DD8: movss [0x00569770], xmm0
	X86_MEM_WRITE_u32(base, 0x569770u, ctx.xmm[0].u32[0]);
	// 0x279DE0: ret
	return;
}

void sub_279DF0(X86Context& ctx, uint8_t* base) {
	// 0x279DF0: movss xmm0, dword ptr [0x00569744]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569744u);
	// 0x279DF8: movss [0x005697D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5697D8u, ctx.xmm[0].u32[0]);
	// 0x279E00: ret
	return;
}

void sub_279E10(X86Context& ctx, uint8_t* base) {
	// 0x279E10: movss xmm0, dword ptr [0x005697BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697BCu);
	// 0x279E18: subss xmm0, [0x00569744]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569744u);
	// 0x279E20: movss [0x0056979C], xmm0
	X86_MEM_WRITE_u32(base, 0x56979Cu, ctx.xmm[0].u32[0]);
	// 0x279E28: ret
	return;
}

void sub_279E30(X86Context& ctx, uint8_t* base) {
	// 0x279E30: movss xmm0, dword ptr [0x0056979C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56979Cu);
	// 0x279E38: subss xmm0, [0x00569770]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569770u);
	// 0x279E40: movss [0x00569794], xmm0
	X86_MEM_WRITE_u32(base, 0x569794u, ctx.xmm[0].u32[0]);
	// 0x279E48: ret
	return;
}

void sub_279E50(X86Context& ctx, uint8_t* base) {
	// 0x279E50: movss xmm0, dword ptr [0x005697C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697C4u);
	// 0x279E58: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x279E60: movss [0x00569780], xmm0
	X86_MEM_WRITE_u32(base, 0x569780u, ctx.xmm[0].u32[0]);
	// 0x279E68: ret
	return;
}

void sub_279E70(X86Context& ctx, uint8_t* base) {
	// 0x279E70: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x279E78: movss [0x0056976C], xmm0
	X86_MEM_WRITE_u32(base, 0x56976Cu, ctx.xmm[0].u32[0]);
	// 0x279E80: ret
	return;
}

void sub_279E90(X86Context& ctx, uint8_t* base) {
	// 0x279E90: movss xmm0, dword ptr [0x00569780]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569780u);
	// 0x279E98: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x279EA0: movss [0x005697B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5697B4u, ctx.xmm[0].u32[0]);
	// 0x279EA8: ret
	return;
}

void sub_279EB0(X86Context& ctx, uint8_t* base) {
	// 0x279EB0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x279EB8: movss [0x00569788], xmm0
	X86_MEM_WRITE_u32(base, 0x569788u, ctx.xmm[0].u32[0]);
	// 0x279EC0: ret
	return;
}

void sub_279ED0(X86Context& ctx, uint8_t* base) {
	// 0x279ED0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x279ED8: movss [0x00569760], xmm0
	X86_MEM_WRITE_u32(base, 0x569760u, ctx.xmm[0].u32[0]);
	// 0x279EE0: ret
	return;
}

void sub_279EF0(X86Context& ctx, uint8_t* base) {
	// 0x279EF0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x279EF8: movss [0x00569840], xmm0
	X86_MEM_WRITE_u32(base, 0x569840u, ctx.xmm[0].u32[0]);
	// 0x279F00: ret
	return;
}

void sub_279F10(X86Context& ctx, uint8_t* base) {
	// 0x279F10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x279F18: movss [0x0056985C], xmm0
	X86_MEM_WRITE_u32(base, 0x56985Cu, ctx.xmm[0].u32[0]);
	// 0x279F20: ret
	return;
}

void sub_279F30(X86Context& ctx, uint8_t* base) {
	// 0x279F30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x279F38: movss [0x00569830], xmm0
	X86_MEM_WRITE_u32(base, 0x569830u, ctx.xmm[0].u32[0]);
	// 0x279F40: ret
	return;
}

void sub_279F50(X86Context& ctx, uint8_t* base) {
	// 0x279F50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x279F58: movss [0x005697E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5697E4u, ctx.xmm[0].u32[0]);
	// 0x279F60: ret
	return;
}

void sub_279F70(X86Context& ctx, uint8_t* base) {
	// 0x279F70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x279F78: movss [0x00569844], xmm0
	X86_MEM_WRITE_u32(base, 0x569844u, ctx.xmm[0].u32[0]);
	// 0x279F80: ret
	return;
}

void sub_279F90(X86Context& ctx, uint8_t* base) {
	// 0x279F90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x279F98: movss [0x00569800], xmm0
	X86_MEM_WRITE_u32(base, 0x569800u, ctx.xmm[0].u32[0]);
	// 0x279FA0: ret
	return;
}

void sub_279FB0(X86Context& ctx, uint8_t* base) {
	// 0x279FB0: movss xmm0, dword ptr [0x00569844]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569844u);
	// 0x279FB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x279FC0: movss [0x0056987C], xmm0
	X86_MEM_WRITE_u32(base, 0x56987Cu, ctx.xmm[0].u32[0]);
	// 0x279FC8: ret
	return;
}

void sub_279FD0(X86Context& ctx, uint8_t* base) {
	// 0x279FD0: movss xmm0, dword ptr [0x00569800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569800u);
	// 0x279FD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x279FE0: movss [0x00569864], xmm0
	X86_MEM_WRITE_u32(base, 0x569864u, ctx.xmm[0].u32[0]);
	// 0x279FE8: ret
	return;
}

void sub_279FF0(X86Context& ctx, uint8_t* base) {
	// 0x279FF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x279FF8: movss [0x00569894], xmm0
	X86_MEM_WRITE_u32(base, 0x569894u, ctx.xmm[0].u32[0]);
	// 0x27A000: ret
	return;
}

void sub_27A010(X86Context& ctx, uint8_t* base) {
	// 0x27A010: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27A018: movss [0x00569880], xmm0
	X86_MEM_WRITE_u32(base, 0x569880u, ctx.xmm[0].u32[0]);
	// 0x27A020: ret
	return;
}

void sub_27A030(X86Context& ctx, uint8_t* base) {
	// 0x27A030: movss xmm0, dword ptr [0x00569880]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569880u);
	// 0x27A038: movss [0x00569890], xmm0
	X86_MEM_WRITE_u32(base, 0x569890u, ctx.xmm[0].u32[0]);
	// 0x27A040: ret
	return;
}

void sub_27A050(X86Context& ctx, uint8_t* base) {
	// 0x27A050: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27A058: movss [0x005697EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5697ECu, ctx.xmm[0].u32[0]);
	// 0x27A060: ret
	return;
}

void sub_27A070(X86Context& ctx, uint8_t* base) {
	// 0x27A070: movss xmm0, dword ptr [0x00569800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569800u);
	// 0x27A078: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27A080: movss [0x00569888], xmm0
	X86_MEM_WRITE_u32(base, 0x569888u, ctx.xmm[0].u32[0]);
	// 0x27A088: ret
	return;
}

void sub_27A090(X86Context& ctx, uint8_t* base) {
	// 0x27A090: movss xmm0, dword ptr [0x00569800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569800u);
	// 0x27A098: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27A0A0: movss [0x0056982C], xmm0
	X86_MEM_WRITE_u32(base, 0x56982Cu, ctx.xmm[0].u32[0]);
	// 0x27A0A8: ret
	return;
}

void sub_27A0B0(X86Context& ctx, uint8_t* base) {
	// 0x27A0B0: movss xmm0, dword ptr [0x00569800]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569800u);
	// 0x27A0B8: subss xmm0, [0x0056982C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56982Cu);
	// 0x27A0C0: movss [0x00569808], xmm0
	X86_MEM_WRITE_u32(base, 0x569808u, ctx.xmm[0].u32[0]);
	// 0x27A0C8: ret
	return;
}

void sub_27A0D0(X86Context& ctx, uint8_t* base) {
	// 0x27A0D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27A0D8: movss [0x00569858], xmm0
	X86_MEM_WRITE_u32(base, 0x569858u, ctx.xmm[0].u32[0]);
	// 0x27A0E0: ret
	return;
}

void sub_27A0F0(X86Context& ctx, uint8_t* base) {
	// 0x27A0F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27A0F8: movss [0x00569804], xmm0
	X86_MEM_WRITE_u32(base, 0x569804u, ctx.xmm[0].u32[0]);
	// 0x27A100: ret
	return;
}

void sub_27A110(X86Context& ctx, uint8_t* base) {
	// 0x27A110: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27A118: movss [0x00569818], xmm0
	X86_MEM_WRITE_u32(base, 0x569818u, ctx.xmm[0].u32[0]);
	// 0x27A120: ret
	return;
}

void sub_27A130(X86Context& ctx, uint8_t* base) {
	// 0x27A130: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27A138: movss [0x00569870], xmm0
	X86_MEM_WRITE_u32(base, 0x569870u, ctx.xmm[0].u32[0]);
	// 0x27A140: ret
	return;
}

void sub_27A150(X86Context& ctx, uint8_t* base) {
	// 0x27A150: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27A158: movss [0x00569854], xmm0
	X86_MEM_WRITE_u32(base, 0x569854u, ctx.xmm[0].u32[0]);
	// 0x27A160: ret
	return;
}

void sub_27A170(X86Context& ctx, uint8_t* base) {
	// 0x27A170: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27A178: movss [0x005697FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5697FCu, ctx.xmm[0].u32[0]);
	// 0x27A180: ret
	return;
}

void sub_27A190(X86Context& ctx, uint8_t* base) {
	// 0x27A190: movss xmm0, dword ptr [0x00569818]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569818u);
	// 0x27A198: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27A1A0: movss [0x005697F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5697F0u, ctx.xmm[0].u32[0]);
	// 0x27A1A8: ret
	return;
}

void sub_27A1B0(X86Context& ctx, uint8_t* base) {
	// 0x27A1B0: movss xmm0, dword ptr [0x00569870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569870u);
	// 0x27A1B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27A1C0: movss [0x00569838], xmm0
	X86_MEM_WRITE_u32(base, 0x569838u, ctx.xmm[0].u32[0]);
	// 0x27A1C8: ret
	return;
}

void sub_27A1D0(X86Context& ctx, uint8_t* base) {
	// 0x27A1D0: movss xmm0, dword ptr [0x005697F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697F0u);
	// 0x27A1D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27A1E0: movss [0x0056984C], xmm0
	X86_MEM_WRITE_u32(base, 0x56984Cu, ctx.xmm[0].u32[0]);
	// 0x27A1E8: ret
	return;
}

void sub_27A1F0(X86Context& ctx, uint8_t* base) {
	// 0x27A1F0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27A1F8: movss [0x005697E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5697E8u, ctx.xmm[0].u32[0]);
	// 0x27A200: ret
	return;
}

void sub_27A210(X86Context& ctx, uint8_t* base) {
	// 0x27A210: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27A218: movss [0x0056981C], xmm0
	X86_MEM_WRITE_u32(base, 0x56981Cu, ctx.xmm[0].u32[0]);
	// 0x27A220: ret
	return;
}

void sub_27A230(X86Context& ctx, uint8_t* base) {
	// 0x27A230: movss xmm0, dword ptr [0x00569818]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569818u);
	// 0x27A238: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27A240: movss [0x00569828], xmm0
	X86_MEM_WRITE_u32(base, 0x569828u, ctx.xmm[0].u32[0]);
	// 0x27A248: ret
	return;
}

void sub_27A250(X86Context& ctx, uint8_t* base) {
	// 0x27A250: movss xmm0, dword ptr [0x00569870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569870u);
	// 0x27A258: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27A260: movss [0x00569874], xmm0
	X86_MEM_WRITE_u32(base, 0x569874u, ctx.xmm[0].u32[0]);
	// 0x27A268: ret
	return;
}

void sub_27A270(X86Context& ctx, uint8_t* base) {
	// 0x27A270: movss xmm0, dword ptr [0x00569828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569828u);
	// 0x27A278: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A280: movss [0x00569860], xmm0
	X86_MEM_WRITE_u32(base, 0x569860u, ctx.xmm[0].u32[0]);
	// 0x27A288: ret
	return;
}

void sub_27A290(X86Context& ctx, uint8_t* base) {
	// 0x27A290: movss xmm0, dword ptr [0x00569874]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569874u);
	// 0x27A298: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A2A0: movss [0x00569884], xmm0
	X86_MEM_WRITE_u32(base, 0x569884u, ctx.xmm[0].u32[0]);
	// 0x27A2A8: ret
	return;
}

void sub_27A2B0(X86Context& ctx, uint8_t* base) {
	// 0x27A2B0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27A2B8: movss [0x005697F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5697F4u, ctx.xmm[0].u32[0]);
	// 0x27A2C0: ret
	return;
}

void sub_27A2D0(X86Context& ctx, uint8_t* base) {
	// 0x27A2D0: movss xmm0, dword ptr [0x00569818]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569818u);
	// 0x27A2D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A2E0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27A2E8: movss [0x0056986C], xmm0
	X86_MEM_WRITE_u32(base, 0x56986Cu, ctx.xmm[0].u32[0]);
	// 0x27A2F0: ret
	return;
}

void sub_27A300(X86Context& ctx, uint8_t* base) {
	// 0x27A300: movss xmm0, dword ptr [0x00569870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569870u);
	// 0x27A308: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A310: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27A318: movss [0x0056980C], xmm0
	X86_MEM_WRITE_u32(base, 0x56980Cu, ctx.xmm[0].u32[0]);
	// 0x27A320: ret
	return;
}

void sub_27A330(X86Context& ctx, uint8_t* base) {
	// 0x27A330: movss xmm0, dword ptr [0x00569818]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569818u);
	// 0x27A338: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A340: movss [0x00569810], xmm0
	X86_MEM_WRITE_u32(base, 0x569810u, ctx.xmm[0].u32[0]);
	// 0x27A348: ret
	return;
}

void sub_27A350(X86Context& ctx, uint8_t* base) {
	// 0x27A350: movss xmm0, dword ptr [0x00569870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569870u);
	// 0x27A358: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A360: movss [0x00569878], xmm0
	X86_MEM_WRITE_u32(base, 0x569878u, ctx.xmm[0].u32[0]);
	// 0x27A368: ret
	return;
}

void sub_27A370(X86Context& ctx, uint8_t* base) {
	// 0x27A370: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27A378: movss [0x005697F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5697F8u, ctx.xmm[0].u32[0]);
	// 0x27A380: ret
	return;
}

void sub_27A390(X86Context& ctx, uint8_t* base) {
	// 0x27A390: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27A398: movss [0x00569824], xmm0
	X86_MEM_WRITE_u32(base, 0x569824u, ctx.xmm[0].u32[0]);
	// 0x27A3A0: ret
	return;
}

void sub_27A3B0(X86Context& ctx, uint8_t* base) {
	// 0x27A3B0: movss xmm0, dword ptr [0x005697F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5697F8u);
	// 0x27A3B8: movss [0x0056988C], xmm0
	X86_MEM_WRITE_u32(base, 0x56988Cu, ctx.xmm[0].u32[0]);
	// 0x27A3C0: ret
	return;
}

void sub_27A3D0(X86Context& ctx, uint8_t* base) {
	// 0x27A3D0: movss xmm0, dword ptr [0x00569870]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569870u);
	// 0x27A3D8: subss xmm0, [0x005697F8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5697F8u);
	// 0x27A3E0: movss [0x00569850], xmm0
	X86_MEM_WRITE_u32(base, 0x569850u, ctx.xmm[0].u32[0]);
	// 0x27A3E8: ret
	return;
}

void sub_27A3F0(X86Context& ctx, uint8_t* base) {
	// 0x27A3F0: movss xmm0, dword ptr [0x00569850]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569850u);
	// 0x27A3F8: subss xmm0, [0x00569824]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569824u);
	// 0x27A400: movss [0x00569848], xmm0
	X86_MEM_WRITE_u32(base, 0x569848u, ctx.xmm[0].u32[0]);
	// 0x27A408: ret
	return;
}

void sub_27A410(X86Context& ctx, uint8_t* base) {
	// 0x27A410: movss xmm0, dword ptr [0x00569878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569878u);
	// 0x27A418: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27A420: movss [0x00569834], xmm0
	X86_MEM_WRITE_u32(base, 0x569834u, ctx.xmm[0].u32[0]);
	// 0x27A428: ret
	return;
}

void sub_27A430(X86Context& ctx, uint8_t* base) {
	// 0x27A430: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27A438: movss [0x00569820], xmm0
	X86_MEM_WRITE_u32(base, 0x569820u, ctx.xmm[0].u32[0]);
	// 0x27A440: ret
	return;
}

void sub_27A450(X86Context& ctx, uint8_t* base) {
	// 0x27A450: movss xmm0, dword ptr [0x00569834]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569834u);
	// 0x27A458: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27A460: movss [0x00569868], xmm0
	X86_MEM_WRITE_u32(base, 0x569868u, ctx.xmm[0].u32[0]);
	// 0x27A468: ret
	return;
}

void sub_27A470(X86Context& ctx, uint8_t* base) {
	// 0x27A470: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27A478: movss [0x0056983C], xmm0
	X86_MEM_WRITE_u32(base, 0x56983Cu, ctx.xmm[0].u32[0]);
	// 0x27A480: ret
	return;
}

void sub_27A490(X86Context& ctx, uint8_t* base) {
	// 0x27A490: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27A498: movss [0x00569814], xmm0
	X86_MEM_WRITE_u32(base, 0x569814u, ctx.xmm[0].u32[0]);
	// 0x27A4A0: ret
	return;
}

void sub_27A4B0(X86Context& ctx, uint8_t* base) {
	// 0x27A4B0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27A4B8: movss [0x005698F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5698F4u, ctx.xmm[0].u32[0]);
	// 0x27A4C0: ret
	return;
}

void sub_27A4D0(X86Context& ctx, uint8_t* base) {
	// 0x27A4D0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27A4D8: movss [0x00569910], xmm0
	X86_MEM_WRITE_u32(base, 0x569910u, ctx.xmm[0].u32[0]);
	// 0x27A4E0: ret
	return;
}

void sub_27A4F0(X86Context& ctx, uint8_t* base) {
	// 0x27A4F0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27A4F8: movss [0x005698E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5698E4u, ctx.xmm[0].u32[0]);
	// 0x27A500: ret
	return;
}

void sub_27A510(X86Context& ctx, uint8_t* base) {
	// 0x27A510: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27A518: movss [0x00569898], xmm0
	X86_MEM_WRITE_u32(base, 0x569898u, ctx.xmm[0].u32[0]);
	// 0x27A520: ret
	return;
}

void sub_27A530(X86Context& ctx, uint8_t* base) {
	// 0x27A530: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27A538: movss [0x005698F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5698F8u, ctx.xmm[0].u32[0]);
	// 0x27A540: ret
	return;
}

void sub_27A550(X86Context& ctx, uint8_t* base) {
	// 0x27A550: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27A558: movss [0x005698B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5698B4u, ctx.xmm[0].u32[0]);
	// 0x27A560: ret
	return;
}

void sub_27A570(X86Context& ctx, uint8_t* base) {
	// 0x27A570: movss xmm0, dword ptr [0x005698F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698F8u);
	// 0x27A578: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27A580: movss [0x00569930], xmm0
	X86_MEM_WRITE_u32(base, 0x569930u, ctx.xmm[0].u32[0]);
	// 0x27A588: ret
	return;
}

void sub_27A590(X86Context& ctx, uint8_t* base) {
	// 0x27A590: movss xmm0, dword ptr [0x005698B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698B4u);
	// 0x27A598: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27A5A0: movss [0x00569918], xmm0
	X86_MEM_WRITE_u32(base, 0x569918u, ctx.xmm[0].u32[0]);
	// 0x27A5A8: ret
	return;
}

void sub_27A5B0(X86Context& ctx, uint8_t* base) {
	// 0x27A5B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27A5B8: movss [0x00569948], xmm0
	X86_MEM_WRITE_u32(base, 0x569948u, ctx.xmm[0].u32[0]);
	// 0x27A5C0: ret
	return;
}

void sub_27A5D0(X86Context& ctx, uint8_t* base) {
	// 0x27A5D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27A5D8: movss [0x00569934], xmm0
	X86_MEM_WRITE_u32(base, 0x569934u, ctx.xmm[0].u32[0]);
	// 0x27A5E0: ret
	return;
}

void sub_27A5F0(X86Context& ctx, uint8_t* base) {
	// 0x27A5F0: movss xmm0, dword ptr [0x00569934]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569934u);
	// 0x27A5F8: movss [0x00569944], xmm0
	X86_MEM_WRITE_u32(base, 0x569944u, ctx.xmm[0].u32[0]);
	// 0x27A600: ret
	return;
}

void sub_27A610(X86Context& ctx, uint8_t* base) {
	// 0x27A610: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27A618: movss [0x005698A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5698A0u, ctx.xmm[0].u32[0]);
	// 0x27A620: ret
	return;
}

void sub_27A630(X86Context& ctx, uint8_t* base) {
	// 0x27A630: movss xmm0, dword ptr [0x005698B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698B4u);
	// 0x27A638: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27A640: movss [0x0056993C], xmm0
	X86_MEM_WRITE_u32(base, 0x56993Cu, ctx.xmm[0].u32[0]);
	// 0x27A648: ret
	return;
}

void sub_27A650(X86Context& ctx, uint8_t* base) {
	// 0x27A650: movss xmm0, dword ptr [0x005698B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698B4u);
	// 0x27A658: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27A660: movss [0x005698E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5698E0u, ctx.xmm[0].u32[0]);
	// 0x27A668: ret
	return;
}

void sub_27A670(X86Context& ctx, uint8_t* base) {
	// 0x27A670: movss xmm0, dword ptr [0x005698B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698B4u);
	// 0x27A678: subss xmm0, [0x005698E0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5698E0u);
	// 0x27A680: movss [0x005698BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5698BCu, ctx.xmm[0].u32[0]);
	// 0x27A688: ret
	return;
}

void sub_27A690(X86Context& ctx, uint8_t* base) {
	// 0x27A690: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27A698: movss [0x0056990C], xmm0
	X86_MEM_WRITE_u32(base, 0x56990Cu, ctx.xmm[0].u32[0]);
	// 0x27A6A0: ret
	return;
}

void sub_27A6B0(X86Context& ctx, uint8_t* base) {
	// 0x27A6B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27A6B8: movss [0x005698B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5698B8u, ctx.xmm[0].u32[0]);
	// 0x27A6C0: ret
	return;
}

void sub_27A6D0(X86Context& ctx, uint8_t* base) {
	// 0x27A6D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27A6D8: movss [0x005698CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5698CCu, ctx.xmm[0].u32[0]);
	// 0x27A6E0: ret
	return;
}

void sub_27A6F0(X86Context& ctx, uint8_t* base) {
	// 0x27A6F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27A6F8: movss [0x00569924], xmm0
	X86_MEM_WRITE_u32(base, 0x569924u, ctx.xmm[0].u32[0]);
	// 0x27A700: ret
	return;
}

void sub_27A710(X86Context& ctx, uint8_t* base) {
	// 0x27A710: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27A718: movss [0x00569908], xmm0
	X86_MEM_WRITE_u32(base, 0x569908u, ctx.xmm[0].u32[0]);
	// 0x27A720: ret
	return;
}

void sub_27A730(X86Context& ctx, uint8_t* base) {
	// 0x27A730: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27A738: movss [0x005698B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5698B0u, ctx.xmm[0].u32[0]);
	// 0x27A740: ret
	return;
}

void sub_27A750(X86Context& ctx, uint8_t* base) {
	// 0x27A750: movss xmm0, dword ptr [0x005698CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698CCu);
	// 0x27A758: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27A760: movss [0x005698A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5698A4u, ctx.xmm[0].u32[0]);
	// 0x27A768: ret
	return;
}

void sub_27A770(X86Context& ctx, uint8_t* base) {
	// 0x27A770: movss xmm0, dword ptr [0x00569924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569924u);
	// 0x27A778: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27A780: movss [0x005698EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5698ECu, ctx.xmm[0].u32[0]);
	// 0x27A788: ret
	return;
}

void sub_27A790(X86Context& ctx, uint8_t* base) {
	// 0x27A790: movss xmm0, dword ptr [0x005698A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698A4u);
	// 0x27A798: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27A7A0: movss [0x00569900], xmm0
	X86_MEM_WRITE_u32(base, 0x569900u, ctx.xmm[0].u32[0]);
	// 0x27A7A8: ret
	return;
}

void sub_27A7B0(X86Context& ctx, uint8_t* base) {
	// 0x27A7B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27A7B8: movss [0x0056989C], xmm0
	X86_MEM_WRITE_u32(base, 0x56989Cu, ctx.xmm[0].u32[0]);
	// 0x27A7C0: ret
	return;
}

void sub_27A7D0(X86Context& ctx, uint8_t* base) {
	// 0x27A7D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27A7D8: movss [0x005698D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5698D0u, ctx.xmm[0].u32[0]);
	// 0x27A7E0: ret
	return;
}

void sub_27A7F0(X86Context& ctx, uint8_t* base) {
	// 0x27A7F0: movss xmm0, dword ptr [0x005698CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698CCu);
	// 0x27A7F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27A800: movss [0x005698DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5698DCu, ctx.xmm[0].u32[0]);
	// 0x27A808: ret
	return;
}

void sub_27A810(X86Context& ctx, uint8_t* base) {
	// 0x27A810: movss xmm0, dword ptr [0x00569924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569924u);
	// 0x27A818: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27A820: movss [0x00569928], xmm0
	X86_MEM_WRITE_u32(base, 0x569928u, ctx.xmm[0].u32[0]);
	// 0x27A828: ret
	return;
}

void sub_27A830(X86Context& ctx, uint8_t* base) {
	// 0x27A830: movss xmm0, dword ptr [0x005698DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698DCu);
	// 0x27A838: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A840: movss [0x00569914], xmm0
	X86_MEM_WRITE_u32(base, 0x569914u, ctx.xmm[0].u32[0]);
	// 0x27A848: ret
	return;
}

void sub_27A850(X86Context& ctx, uint8_t* base) {
	// 0x27A850: movss xmm0, dword ptr [0x00569928]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569928u);
	// 0x27A858: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A860: movss [0x00569938], xmm0
	X86_MEM_WRITE_u32(base, 0x569938u, ctx.xmm[0].u32[0]);
	// 0x27A868: ret
	return;
}

void sub_27A870(X86Context& ctx, uint8_t* base) {
	// 0x27A870: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27A878: movss [0x005698A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5698A8u, ctx.xmm[0].u32[0]);
	// 0x27A880: ret
	return;
}

void sub_27A890(X86Context& ctx, uint8_t* base) {
	// 0x27A890: movss xmm0, dword ptr [0x005698CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698CCu);
	// 0x27A898: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A8A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27A8A8: movss [0x00569920], xmm0
	X86_MEM_WRITE_u32(base, 0x569920u, ctx.xmm[0].u32[0]);
	// 0x27A8B0: ret
	return;
}

void sub_27A8C0(X86Context& ctx, uint8_t* base) {
	// 0x27A8C0: movss xmm0, dword ptr [0x00569924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569924u);
	// 0x27A8C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A8D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27A8D8: movss [0x005698C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5698C0u, ctx.xmm[0].u32[0]);
	// 0x27A8E0: ret
	return;
}

void sub_27A8F0(X86Context& ctx, uint8_t* base) {
	// 0x27A8F0: movss xmm0, dword ptr [0x005698CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698CCu);
	// 0x27A8F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A900: movss [0x005698C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5698C4u, ctx.xmm[0].u32[0]);
	// 0x27A908: ret
	return;
}

void sub_27A910(X86Context& ctx, uint8_t* base) {
	// 0x27A910: movss xmm0, dword ptr [0x00569924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569924u);
	// 0x27A918: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27A920: movss [0x0056992C], xmm0
	X86_MEM_WRITE_u32(base, 0x56992Cu, ctx.xmm[0].u32[0]);
	// 0x27A928: ret
	return;
}

void sub_27A930(X86Context& ctx, uint8_t* base) {
	// 0x27A930: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27A938: movss [0x005698AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5698ACu, ctx.xmm[0].u32[0]);
	// 0x27A940: ret
	return;
}

void sub_27A950(X86Context& ctx, uint8_t* base) {
	// 0x27A950: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27A958: movss [0x005698D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5698D8u, ctx.xmm[0].u32[0]);
	// 0x27A960: ret
	return;
}

void sub_27A970(X86Context& ctx, uint8_t* base) {
	// 0x27A970: movss xmm0, dword ptr [0x005698AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698ACu);
	// 0x27A978: movss [0x00569940], xmm0
	X86_MEM_WRITE_u32(base, 0x569940u, ctx.xmm[0].u32[0]);
	// 0x27A980: ret
	return;
}

void sub_27A990(X86Context& ctx, uint8_t* base) {
	// 0x27A990: movss xmm0, dword ptr [0x00569924]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569924u);
	// 0x27A998: subss xmm0, [0x005698AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5698ACu);
	// 0x27A9A0: movss [0x00569904], xmm0
	X86_MEM_WRITE_u32(base, 0x569904u, ctx.xmm[0].u32[0]);
	// 0x27A9A8: ret
	return;
}

void sub_27A9B0(X86Context& ctx, uint8_t* base) {
	// 0x27A9B0: movss xmm0, dword ptr [0x00569904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569904u);
	// 0x27A9B8: subss xmm0, [0x005698D8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5698D8u);
	// 0x27A9C0: movss [0x005698FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5698FCu, ctx.xmm[0].u32[0]);
	// 0x27A9C8: ret
	return;
}

void sub_27A9D0(X86Context& ctx, uint8_t* base) {
	// 0x27A9D0: movss xmm0, dword ptr [0x0056992C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56992Cu);
	// 0x27A9D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27A9E0: movss [0x005698E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5698E8u, ctx.xmm[0].u32[0]);
	// 0x27A9E8: ret
	return;
}

void sub_27A9F0(X86Context& ctx, uint8_t* base) {
	// 0x27A9F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27A9F8: movss [0x005698D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5698D4u, ctx.xmm[0].u32[0]);
	// 0x27AA00: ret
	return;
}

void sub_27AA10(X86Context& ctx, uint8_t* base) {
	// 0x27AA10: movss xmm0, dword ptr [0x005698E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5698E8u);
	// 0x27AA18: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27AA20: movss [0x0056991C], xmm0
	X86_MEM_WRITE_u32(base, 0x56991Cu, ctx.xmm[0].u32[0]);
	// 0x27AA28: ret
	return;
}

void sub_27AA30(X86Context& ctx, uint8_t* base) {
	// 0x27AA30: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27AA38: movss [0x005698F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5698F0u, ctx.xmm[0].u32[0]);
	// 0x27AA40: ret
	return;
}

void sub_27AA50(X86Context& ctx, uint8_t* base) {
	// 0x27AA50: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27AA58: movss [0x005698C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5698C8u, ctx.xmm[0].u32[0]);
	// 0x27AA60: ret
	return;
}

void sub_27AA70(X86Context& ctx, uint8_t* base) {
	// 0x27AA70: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27AA78: movss [0x005699A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5699A8u, ctx.xmm[0].u32[0]);
	// 0x27AA80: ret
	return;
}

void sub_27AA90(X86Context& ctx, uint8_t* base) {
	// 0x27AA90: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27AA98: movss [0x005699C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5699C4u, ctx.xmm[0].u32[0]);
	// 0x27AAA0: ret
	return;
}

void sub_27AAB0(X86Context& ctx, uint8_t* base) {
	// 0x27AAB0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27AAB8: movss [0x00569998], xmm0
	X86_MEM_WRITE_u32(base, 0x569998u, ctx.xmm[0].u32[0]);
	// 0x27AAC0: ret
	return;
}

void sub_27AAD0(X86Context& ctx, uint8_t* base) {
	// 0x27AAD0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27AAD8: movss [0x0056994C], xmm0
	X86_MEM_WRITE_u32(base, 0x56994Cu, ctx.xmm[0].u32[0]);
	// 0x27AAE0: ret
	return;
}

void sub_27AAF0(X86Context& ctx, uint8_t* base) {
	// 0x27AAF0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27AAF8: movss [0x005699AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5699ACu, ctx.xmm[0].u32[0]);
	// 0x27AB00: ret
	return;
}

void sub_27AB10(X86Context& ctx, uint8_t* base) {
	// 0x27AB10: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27AB18: movss [0x00569968], xmm0
	X86_MEM_WRITE_u32(base, 0x569968u, ctx.xmm[0].u32[0]);
	// 0x27AB20: ret
	return;
}

void sub_27AB30(X86Context& ctx, uint8_t* base) {
	// 0x27AB30: movss xmm0, dword ptr [0x005699AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699ACu);
	// 0x27AB38: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27AB40: movss [0x005699E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5699E4u, ctx.xmm[0].u32[0]);
	// 0x27AB48: ret
	return;
}

void sub_27AB50(X86Context& ctx, uint8_t* base) {
	// 0x27AB50: movss xmm0, dword ptr [0x00569968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569968u);
	// 0x27AB58: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27AB60: movss [0x005699CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5699CCu, ctx.xmm[0].u32[0]);
	// 0x27AB68: ret
	return;
}

void sub_27AB70(X86Context& ctx, uint8_t* base) {
	// 0x27AB70: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27AB78: movss [0x005699FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5699FCu, ctx.xmm[0].u32[0]);
	// 0x27AB80: ret
	return;
}

void sub_27AB90(X86Context& ctx, uint8_t* base) {
	// 0x27AB90: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27AB98: movss [0x005699E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5699E8u, ctx.xmm[0].u32[0]);
	// 0x27ABA0: ret
	return;
}

void sub_27ABB0(X86Context& ctx, uint8_t* base) {
	// 0x27ABB0: movss xmm0, dword ptr [0x005699E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699E8u);
	// 0x27ABB8: movss [0x005699F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5699F8u, ctx.xmm[0].u32[0]);
	// 0x27ABC0: ret
	return;
}

void sub_27ABD0(X86Context& ctx, uint8_t* base) {
	// 0x27ABD0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27ABD8: movss [0x00569954], xmm0
	X86_MEM_WRITE_u32(base, 0x569954u, ctx.xmm[0].u32[0]);
	// 0x27ABE0: ret
	return;
}

void sub_27ABF0(X86Context& ctx, uint8_t* base) {
	// 0x27ABF0: movss xmm0, dword ptr [0x00569968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569968u);
	// 0x27ABF8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27AC00: movss [0x005699F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5699F0u, ctx.xmm[0].u32[0]);
	// 0x27AC08: ret
	return;
}

void sub_27AC10(X86Context& ctx, uint8_t* base) {
	// 0x27AC10: movss xmm0, dword ptr [0x00569968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569968u);
	// 0x27AC18: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27AC20: movss [0x00569994], xmm0
	X86_MEM_WRITE_u32(base, 0x569994u, ctx.xmm[0].u32[0]);
	// 0x27AC28: ret
	return;
}

void sub_27AC30(X86Context& ctx, uint8_t* base) {
	// 0x27AC30: movss xmm0, dword ptr [0x00569968]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569968u);
	// 0x27AC38: subss xmm0, [0x00569994]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569994u);
	// 0x27AC40: movss [0x00569970], xmm0
	X86_MEM_WRITE_u32(base, 0x569970u, ctx.xmm[0].u32[0]);
	// 0x27AC48: ret
	return;
}

void sub_27AC50(X86Context& ctx, uint8_t* base) {
	// 0x27AC50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27AC58: movss [0x005699C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5699C0u, ctx.xmm[0].u32[0]);
	// 0x27AC60: ret
	return;
}

void sub_27AC70(X86Context& ctx, uint8_t* base) {
	// 0x27AC70: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27AC78: movss [0x0056996C], xmm0
	X86_MEM_WRITE_u32(base, 0x56996Cu, ctx.xmm[0].u32[0]);
	// 0x27AC80: ret
	return;
}

void sub_27AC90(X86Context& ctx, uint8_t* base) {
	// 0x27AC90: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27AC98: movss [0x00569980], xmm0
	X86_MEM_WRITE_u32(base, 0x569980u, ctx.xmm[0].u32[0]);
	// 0x27ACA0: ret
	return;
}

void sub_27ACB0(X86Context& ctx, uint8_t* base) {
	// 0x27ACB0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27ACB8: movss [0x005699D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5699D8u, ctx.xmm[0].u32[0]);
	// 0x27ACC0: ret
	return;
}

void sub_27ACD0(X86Context& ctx, uint8_t* base) {
	// 0x27ACD0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27ACD8: movss [0x005699BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5699BCu, ctx.xmm[0].u32[0]);
	// 0x27ACE0: ret
	return;
}

void sub_27ACF0(X86Context& ctx, uint8_t* base) {
	// 0x27ACF0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27ACF8: movss [0x00569964], xmm0
	X86_MEM_WRITE_u32(base, 0x569964u, ctx.xmm[0].u32[0]);
	// 0x27AD00: ret
	return;
}

void sub_27AD10(X86Context& ctx, uint8_t* base) {
	// 0x27AD10: movss xmm0, dword ptr [0x00569980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569980u);
	// 0x27AD18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27AD20: movss [0x00569958], xmm0
	X86_MEM_WRITE_u32(base, 0x569958u, ctx.xmm[0].u32[0]);
	// 0x27AD28: ret
	return;
}

void sub_27AD30(X86Context& ctx, uint8_t* base) {
	// 0x27AD30: movss xmm0, dword ptr [0x005699D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699D8u);
	// 0x27AD38: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27AD40: movss [0x005699A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5699A0u, ctx.xmm[0].u32[0]);
	// 0x27AD48: ret
	return;
}

void sub_27AD50(X86Context& ctx, uint8_t* base) {
	// 0x27AD50: movss xmm0, dword ptr [0x00569958]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569958u);
	// 0x27AD58: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27AD60: movss [0x005699B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5699B4u, ctx.xmm[0].u32[0]);
	// 0x27AD68: ret
	return;
}

void sub_27AD70(X86Context& ctx, uint8_t* base) {
	// 0x27AD70: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27AD78: movss [0x00569950], xmm0
	X86_MEM_WRITE_u32(base, 0x569950u, ctx.xmm[0].u32[0]);
	// 0x27AD80: ret
	return;
}

void sub_27AD90(X86Context& ctx, uint8_t* base) {
	// 0x27AD90: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27AD98: movss [0x00569984], xmm0
	X86_MEM_WRITE_u32(base, 0x569984u, ctx.xmm[0].u32[0]);
	// 0x27ADA0: ret
	return;
}

void sub_27ADB0(X86Context& ctx, uint8_t* base) {
	// 0x27ADB0: movss xmm0, dword ptr [0x00569980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569980u);
	// 0x27ADB8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27ADC0: movss [0x00569990], xmm0
	X86_MEM_WRITE_u32(base, 0x569990u, ctx.xmm[0].u32[0]);
	// 0x27ADC8: ret
	return;
}

void sub_27ADD0(X86Context& ctx, uint8_t* base) {
	// 0x27ADD0: movss xmm0, dword ptr [0x005699D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699D8u);
	// 0x27ADD8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27ADE0: movss [0x005699DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5699DCu, ctx.xmm[0].u32[0]);
	// 0x27ADE8: ret
	return;
}

void sub_27ADF0(X86Context& ctx, uint8_t* base) {
	// 0x27ADF0: movss xmm0, dword ptr [0x00569990]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569990u);
	// 0x27ADF8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27AE00: movss [0x005699C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5699C8u, ctx.xmm[0].u32[0]);
	// 0x27AE08: ret
	return;
}

void sub_27AE10(X86Context& ctx, uint8_t* base) {
	// 0x27AE10: movss xmm0, dword ptr [0x005699DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699DCu);
	// 0x27AE18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27AE20: movss [0x005699EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5699ECu, ctx.xmm[0].u32[0]);
	// 0x27AE28: ret
	return;
}

void sub_27AE30(X86Context& ctx, uint8_t* base) {
	// 0x27AE30: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27AE38: movss [0x0056995C], xmm0
	X86_MEM_WRITE_u32(base, 0x56995Cu, ctx.xmm[0].u32[0]);
	// 0x27AE40: ret
	return;
}

void sub_27AE50(X86Context& ctx, uint8_t* base) {
	// 0x27AE50: movss xmm0, dword ptr [0x00569980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569980u);
	// 0x27AE58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27AE60: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27AE68: movss [0x005699D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5699D4u, ctx.xmm[0].u32[0]);
	// 0x27AE70: ret
	return;
}

void sub_27AE80(X86Context& ctx, uint8_t* base) {
	// 0x27AE80: movss xmm0, dword ptr [0x005699D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699D8u);
	// 0x27AE88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27AE90: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27AE98: movss [0x00569974], xmm0
	X86_MEM_WRITE_u32(base, 0x569974u, ctx.xmm[0].u32[0]);
	// 0x27AEA0: ret
	return;
}

void sub_27AEB0(X86Context& ctx, uint8_t* base) {
	// 0x27AEB0: movss xmm0, dword ptr [0x00569980]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569980u);
	// 0x27AEB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27AEC0: movss [0x00569978], xmm0
	X86_MEM_WRITE_u32(base, 0x569978u, ctx.xmm[0].u32[0]);
	// 0x27AEC8: ret
	return;
}

void sub_27AED0(X86Context& ctx, uint8_t* base) {
	// 0x27AED0: movss xmm0, dword ptr [0x005699D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699D8u);
	// 0x27AED8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27AEE0: movss [0x005699E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5699E0u, ctx.xmm[0].u32[0]);
	// 0x27AEE8: ret
	return;
}

void sub_27AEF0(X86Context& ctx, uint8_t* base) {
	// 0x27AEF0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27AEF8: movss [0x00569960], xmm0
	X86_MEM_WRITE_u32(base, 0x569960u, ctx.xmm[0].u32[0]);
	// 0x27AF00: ret
	return;
}

void sub_27AF10(X86Context& ctx, uint8_t* base) {
	// 0x27AF10: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27AF18: movss [0x0056998C], xmm0
	X86_MEM_WRITE_u32(base, 0x56998Cu, ctx.xmm[0].u32[0]);
	// 0x27AF20: ret
	return;
}

void sub_27AF30(X86Context& ctx, uint8_t* base) {
	// 0x27AF30: movss xmm0, dword ptr [0x00569960]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569960u);
	// 0x27AF38: movss [0x005699F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5699F4u, ctx.xmm[0].u32[0]);
	// 0x27AF40: ret
	return;
}

void sub_27AF50(X86Context& ctx, uint8_t* base) {
	// 0x27AF50: movss xmm0, dword ptr [0x005699D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699D8u);
	// 0x27AF58: subss xmm0, [0x00569960]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569960u);
	// 0x27AF60: movss [0x005699B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5699B8u, ctx.xmm[0].u32[0]);
	// 0x27AF68: ret
	return;
}

void sub_27AF70(X86Context& ctx, uint8_t* base) {
	// 0x27AF70: movss xmm0, dword ptr [0x005699B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699B8u);
	// 0x27AF78: subss xmm0, [0x0056998C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56998Cu);
	// 0x27AF80: movss [0x005699B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5699B0u, ctx.xmm[0].u32[0]);
	// 0x27AF88: ret
	return;
}

void sub_27AF90(X86Context& ctx, uint8_t* base) {
	// 0x27AF90: movss xmm0, dword ptr [0x005699E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5699E0u);
	// 0x27AF98: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x27AFA0: movss [0x0056999C], xmm0
	X86_MEM_WRITE_u32(base, 0x56999Cu, ctx.xmm[0].u32[0]);
	// 0x27AFA8: ret
	return;
}

void sub_27AFB0(X86Context& ctx, uint8_t* base) {
	// 0x27AFB0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x27AFB8: movss [0x00569988], xmm0
	X86_MEM_WRITE_u32(base, 0x569988u, ctx.xmm[0].u32[0]);
	// 0x27AFC0: ret
	return;
}

void sub_27AFD0(X86Context& ctx, uint8_t* base) {
	// 0x27AFD0: movss xmm0, dword ptr [0x0056999C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56999Cu);
	// 0x27AFD8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x27AFE0: movss [0x005699D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5699D0u, ctx.xmm[0].u32[0]);
	// 0x27AFE8: ret
	return;
}

void sub_27AFF0(X86Context& ctx, uint8_t* base) {
	// 0x27AFF0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x27AFF8: movss [0x005699A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5699A4u, ctx.xmm[0].u32[0]);
	// 0x27B000: ret
	return;
}

void sub_27B010(X86Context& ctx, uint8_t* base) {
	// 0x27B010: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x27B018: movss [0x0056997C], xmm0
	X86_MEM_WRITE_u32(base, 0x56997Cu, ctx.xmm[0].u32[0]);
	// 0x27B020: ret
	return;
}

void sub_27B030(X86Context& ctx, uint8_t* base) {
	// 0x27B030: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x27B038: movss [0x00569A5C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A5Cu, ctx.xmm[0].u32[0]);
	// 0x27B040: ret
	return;
}

void sub_27B050(X86Context& ctx, uint8_t* base) {
	// 0x27B050: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x27B058: movss [0x00569A78], xmm0
	X86_MEM_WRITE_u32(base, 0x569A78u, ctx.xmm[0].u32[0]);
	// 0x27B060: ret
	return;
}

void sub_27B070(X86Context& ctx, uint8_t* base) {
	// 0x27B070: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x27B078: movss [0x00569A4C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A4Cu, ctx.xmm[0].u32[0]);
	// 0x27B080: ret
	return;
}

void sub_27B090(X86Context& ctx, uint8_t* base) {
	// 0x27B090: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x27B098: movss [0x00569A00], xmm0
	X86_MEM_WRITE_u32(base, 0x569A00u, ctx.xmm[0].u32[0]);
	// 0x27B0A0: ret
	return;
}

void sub_27B0B0(X86Context& ctx, uint8_t* base) {
	// 0x27B0B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27B0B8: movss [0x00569A60], xmm0
	X86_MEM_WRITE_u32(base, 0x569A60u, ctx.xmm[0].u32[0]);
	// 0x27B0C0: ret
	return;
}

void sub_27B0D0(X86Context& ctx, uint8_t* base) {
	// 0x27B0D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27B0D8: movss [0x00569A1C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A1Cu, ctx.xmm[0].u32[0]);
	// 0x27B0E0: ret
	return;
}

void sub_27B0F0(X86Context& ctx, uint8_t* base) {
	// 0x27B0F0: movss xmm0, dword ptr [0x00569A60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A60u);
	// 0x27B0F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27B100: movss [0x00569A98], xmm0
	X86_MEM_WRITE_u32(base, 0x569A98u, ctx.xmm[0].u32[0]);
	// 0x27B108: ret
	return;
}

void sub_27B110(X86Context& ctx, uint8_t* base) {
	// 0x27B110: movss xmm0, dword ptr [0x00569A1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A1Cu);
	// 0x27B118: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27B120: movss [0x00569A80], xmm0
	X86_MEM_WRITE_u32(base, 0x569A80u, ctx.xmm[0].u32[0]);
	// 0x27B128: ret
	return;
}

void sub_27B130(X86Context& ctx, uint8_t* base) {
	// 0x27B130: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27B138: movss [0x00569AB0], xmm0
	X86_MEM_WRITE_u32(base, 0x569AB0u, ctx.xmm[0].u32[0]);
	// 0x27B140: ret
	return;
}

void sub_27B150(X86Context& ctx, uint8_t* base) {
	// 0x27B150: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x27B158: movss [0x00569A9C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A9Cu, ctx.xmm[0].u32[0]);
	// 0x27B160: ret
	return;
}

void sub_27B170(X86Context& ctx, uint8_t* base) {
	// 0x27B170: movss xmm0, dword ptr [0x00569A9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A9Cu);
	// 0x27B178: movss [0x00569AAC], xmm0
	X86_MEM_WRITE_u32(base, 0x569AACu, ctx.xmm[0].u32[0]);
	// 0x27B180: ret
	return;
}

void sub_27B190(X86Context& ctx, uint8_t* base) {
	// 0x27B190: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x27B198: movss [0x00569A08], xmm0
	X86_MEM_WRITE_u32(base, 0x569A08u, ctx.xmm[0].u32[0]);
	// 0x27B1A0: ret
	return;
}

void sub_27B1B0(X86Context& ctx, uint8_t* base) {
	// 0x27B1B0: movss xmm0, dword ptr [0x00569A1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A1Cu);
	// 0x27B1B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x27B1C0: movss [0x00569AA4], xmm0
	X86_MEM_WRITE_u32(base, 0x569AA4u, ctx.xmm[0].u32[0]);
	// 0x27B1C8: ret
	return;
}

void sub_27B1D0(X86Context& ctx, uint8_t* base) {
	// 0x27B1D0: movss xmm0, dword ptr [0x00569A1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A1Cu);
	// 0x27B1D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x27B1E0: movss [0x00569A48], xmm0
	X86_MEM_WRITE_u32(base, 0x569A48u, ctx.xmm[0].u32[0]);
	// 0x27B1E8: ret
	return;
}

void sub_27B1F0(X86Context& ctx, uint8_t* base) {
	// 0x27B1F0: movss xmm0, dword ptr [0x00569A1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A1Cu);
	// 0x27B1F8: subss xmm0, [0x00569A48]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569A48u);
	// 0x27B200: movss [0x00569A24], xmm0
	X86_MEM_WRITE_u32(base, 0x569A24u, ctx.xmm[0].u32[0]);
	// 0x27B208: ret
	return;
}

void sub_27B210(X86Context& ctx, uint8_t* base) {
	// 0x27B210: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x27B218: movss [0x00569A74], xmm0
	X86_MEM_WRITE_u32(base, 0x569A74u, ctx.xmm[0].u32[0]);
	// 0x27B220: ret
	return;
}

void sub_27B230(X86Context& ctx, uint8_t* base) {
	// 0x27B230: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x27B238: movss [0x00569A20], xmm0
	X86_MEM_WRITE_u32(base, 0x569A20u, ctx.xmm[0].u32[0]);
	// 0x27B240: ret
	return;
}

void sub_27B250(X86Context& ctx, uint8_t* base) {
	// 0x27B250: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x27B258: movss [0x00569A34], xmm0
	X86_MEM_WRITE_u32(base, 0x569A34u, ctx.xmm[0].u32[0]);
	// 0x27B260: ret
	return;
}

void sub_27B270(X86Context& ctx, uint8_t* base) {
	// 0x27B270: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x27B278: movss [0x00569A8C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A8Cu, ctx.xmm[0].u32[0]);
	// 0x27B280: ret
	return;
}

void sub_27B290(X86Context& ctx, uint8_t* base) {
	// 0x27B290: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x27B298: movss [0x00569A70], xmm0
	X86_MEM_WRITE_u32(base, 0x569A70u, ctx.xmm[0].u32[0]);
	// 0x27B2A0: ret
	return;
}

void sub_27B2B0(X86Context& ctx, uint8_t* base) {
	// 0x27B2B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x27B2B8: movss [0x00569A18], xmm0
	X86_MEM_WRITE_u32(base, 0x569A18u, ctx.xmm[0].u32[0]);
	// 0x27B2C0: ret
	return;
}

void sub_27B2D0(X86Context& ctx, uint8_t* base) {
	// 0x27B2D0: movss xmm0, dword ptr [0x00569A34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A34u);
	// 0x27B2D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27B2E0: movss [0x00569A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A0Cu, ctx.xmm[0].u32[0]);
	// 0x27B2E8: ret
	return;
}

void sub_27B2F0(X86Context& ctx, uint8_t* base) {
	// 0x27B2F0: movss xmm0, dword ptr [0x00569A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A8Cu);
	// 0x27B2F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x27B300: movss [0x00569A54], xmm0
	X86_MEM_WRITE_u32(base, 0x569A54u, ctx.xmm[0].u32[0]);
	// 0x27B308: ret
	return;
}

void sub_27B310(X86Context& ctx, uint8_t* base) {
	// 0x27B310: movss xmm0, dword ptr [0x00569A0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A0Cu);
	// 0x27B318: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x27B320: movss [0x00569A68], xmm0
	X86_MEM_WRITE_u32(base, 0x569A68u, ctx.xmm[0].u32[0]);
	// 0x27B328: ret
	return;
}

void sub_27B330(X86Context& ctx, uint8_t* base) {
	// 0x27B330: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27B338: movss [0x00569A04], xmm0
	X86_MEM_WRITE_u32(base, 0x569A04u, ctx.xmm[0].u32[0]);
	// 0x27B340: ret
	return;
}

void sub_27B350(X86Context& ctx, uint8_t* base) {
	// 0x27B350: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x27B358: movss [0x00569A38], xmm0
	X86_MEM_WRITE_u32(base, 0x569A38u, ctx.xmm[0].u32[0]);
	// 0x27B360: ret
	return;
}

void sub_27B370(X86Context& ctx, uint8_t* base) {
	// 0x27B370: movss xmm0, dword ptr [0x00569A34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A34u);
	// 0x27B378: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27B380: movss [0x00569A44], xmm0
	X86_MEM_WRITE_u32(base, 0x569A44u, ctx.xmm[0].u32[0]);
	// 0x27B388: ret
	return;
}

void sub_27B390(X86Context& ctx, uint8_t* base) {
	// 0x27B390: movss xmm0, dword ptr [0x00569A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A8Cu);
	// 0x27B398: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x27B3A0: movss [0x00569A90], xmm0
	X86_MEM_WRITE_u32(base, 0x569A90u, ctx.xmm[0].u32[0]);
	// 0x27B3A8: ret
	return;
}

void sub_27B3B0(X86Context& ctx, uint8_t* base) {
	// 0x27B3B0: movss xmm0, dword ptr [0x00569A44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A44u);
	// 0x27B3B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B3C0: movss [0x00569A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A7Cu, ctx.xmm[0].u32[0]);
	// 0x27B3C8: ret
	return;
}

void sub_27B3D0(X86Context& ctx, uint8_t* base) {
	// 0x27B3D0: movss xmm0, dword ptr [0x00569A90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A90u);
	// 0x27B3D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B3E0: movss [0x00569AA0], xmm0
	X86_MEM_WRITE_u32(base, 0x569AA0u, ctx.xmm[0].u32[0]);
	// 0x27B3E8: ret
	return;
}

void sub_27B3F0(X86Context& ctx, uint8_t* base) {
	// 0x27B3F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x27B3F8: movss [0x00569A10], xmm0
	X86_MEM_WRITE_u32(base, 0x569A10u, ctx.xmm[0].u32[0]);
	// 0x27B400: ret
	return;
}

void sub_27B410(X86Context& ctx, uint8_t* base) {
	// 0x27B410: movss xmm0, dword ptr [0x00569A34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A34u);
	// 0x27B418: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B420: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x27B428: movss [0x00569A88], xmm0
	X86_MEM_WRITE_u32(base, 0x569A88u, ctx.xmm[0].u32[0]);
	// 0x27B430: ret
	return;
}

void sub_27B440(X86Context& ctx, uint8_t* base) {
	// 0x27B440: movss xmm0, dword ptr [0x00569A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A8Cu);
	// 0x27B448: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B450: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x27B458: movss [0x00569A28], xmm0
	X86_MEM_WRITE_u32(base, 0x569A28u, ctx.xmm[0].u32[0]);
	// 0x27B460: ret
	return;
}

void sub_27B470(X86Context& ctx, uint8_t* base) {
	// 0x27B470: movss xmm0, dword ptr [0x00569A34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A34u);
	// 0x27B478: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B480: movss [0x00569A2C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A2Cu, ctx.xmm[0].u32[0]);
	// 0x27B488: ret
	return;
}

void sub_27B490(X86Context& ctx, uint8_t* base) {
	// 0x27B490: movss xmm0, dword ptr [0x00569A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A8Cu);
	// 0x27B498: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x27B4A0: movss [0x00569A94], xmm0
	X86_MEM_WRITE_u32(base, 0x569A94u, ctx.xmm[0].u32[0]);
	// 0x27B4A8: ret
	return;
}

void sub_27B4B0(X86Context& ctx, uint8_t* base) {
	// 0x27B4B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x27B4B8: movss [0x00569A14], xmm0
	X86_MEM_WRITE_u32(base, 0x569A14u, ctx.xmm[0].u32[0]);
	// 0x27B4C0: ret
	return;
}

void sub_27B4D0(X86Context& ctx, uint8_t* base) {
	// 0x27B4D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x27B4D8: movss [0x00569A40], xmm0
	X86_MEM_WRITE_u32(base, 0x569A40u, ctx.xmm[0].u32[0]);
	// 0x27B4E0: ret
	return;
}

void sub_27B4F0(X86Context& ctx, uint8_t* base) {
	// 0x27B4F0: movss xmm0, dword ptr [0x00569A14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A14u);
	// 0x27B4F8: movss [0x00569AA8], xmm0
	X86_MEM_WRITE_u32(base, 0x569AA8u, ctx.xmm[0].u32[0]);
	// 0x27B500: ret
	return;
}

void sub_27B510(X86Context& ctx, uint8_t* base) {
	// 0x27B510: movss xmm0, dword ptr [0x00569A8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A8Cu);
	// 0x27B518: subss xmm0, [0x00569A14]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569A14u);
	// 0x27B520: movss [0x00569A6C], xmm0
	X86_MEM_WRITE_u32(base, 0x569A6Cu, ctx.xmm[0].u32[0]);
	// 0x27B528: ret
	return;
}

void sub_27B530(X86Context& ctx, uint8_t* base) {
	// 0x27B530: movss xmm0, dword ptr [0x00569A6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569A6Cu);
	// 0x27B538: subss xmm0, [0x00569A40]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569A40u);
	// 0x27B540: movss [0x00569A64], xmm0
	X86_MEM_WRITE_u32(base, 0x569A64u, ctx.xmm[0].u32[0]);
	// 0x27B548: ret
	return;
}

