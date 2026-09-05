#include "x86_recomp_shared.h"

void sub_275350(X86Context& ctx, uint8_t* base) {
	// 0x275350: movss xmm0, dword ptr [0x00568E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568E98u);
	// 0x275358: subss xmm0, [0x00568E20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568E20u);
	// 0x275360: movss [0x00568E78], xmm0
	X86_MEM_WRITE_u32(base, 0x568E78u, ctx.xmm[0].u32[0]);
	// 0x275368: ret
	return;
}

void sub_275370(X86Context& ctx, uint8_t* base) {
	// 0x275370: movss xmm0, dword ptr [0x00568E78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568E78u);
	// 0x275378: subss xmm0, [0x00568E4C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568E4Cu);
	// 0x275380: movss [0x00568E70], xmm0
	X86_MEM_WRITE_u32(base, 0x568E70u, ctx.xmm[0].u32[0]);
	// 0x275388: ret
	return;
}

void sub_275390(X86Context& ctx, uint8_t* base) {
	// 0x275390: movss xmm0, dword ptr [0x00568EA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EA0u);
	// 0x275398: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2753A0: movss [0x00568E5C], xmm0
	X86_MEM_WRITE_u32(base, 0x568E5Cu, ctx.xmm[0].u32[0]);
	// 0x2753A8: ret
	return;
}

void sub_2753B0(X86Context& ctx, uint8_t* base) {
	// 0x2753B0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2753B8: movss [0x00568E48], xmm0
	X86_MEM_WRITE_u32(base, 0x568E48u, ctx.xmm[0].u32[0]);
	// 0x2753C0: ret
	return;
}

void sub_2753D0(X86Context& ctx, uint8_t* base) {
	// 0x2753D0: movss xmm0, dword ptr [0x00568E5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568E5Cu);
	// 0x2753D8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2753E0: movss [0x00568E90], xmm0
	X86_MEM_WRITE_u32(base, 0x568E90u, ctx.xmm[0].u32[0]);
	// 0x2753E8: ret
	return;
}

void sub_2753F0(X86Context& ctx, uint8_t* base) {
	// 0x2753F0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2753F8: movss [0x00568E64], xmm0
	X86_MEM_WRITE_u32(base, 0x568E64u, ctx.xmm[0].u32[0]);
	// 0x275400: ret
	return;
}

void sub_275410(X86Context& ctx, uint8_t* base) {
	// 0x275410: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x275418: movss [0x00568E3C], xmm0
	X86_MEM_WRITE_u32(base, 0x568E3Cu, ctx.xmm[0].u32[0]);
	// 0x275420: ret
	return;
}

void sub_275430(X86Context& ctx, uint8_t* base) {
	// 0x275430: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x275438: movss [0x00568F1C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F1Cu, ctx.xmm[0].u32[0]);
	// 0x275440: ret
	return;
}

void sub_275450(X86Context& ctx, uint8_t* base) {
	// 0x275450: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x275458: movss [0x00568F38], xmm0
	X86_MEM_WRITE_u32(base, 0x568F38u, ctx.xmm[0].u32[0]);
	// 0x275460: ret
	return;
}

void sub_275470(X86Context& ctx, uint8_t* base) {
	// 0x275470: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x275478: movss [0x00568F0C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F0Cu, ctx.xmm[0].u32[0]);
	// 0x275480: ret
	return;
}

void sub_275490(X86Context& ctx, uint8_t* base) {
	// 0x275490: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x275498: movss [0x00568EC0], xmm0
	X86_MEM_WRITE_u32(base, 0x568EC0u, ctx.xmm[0].u32[0]);
	// 0x2754A0: ret
	return;
}

void sub_2754B0(X86Context& ctx, uint8_t* base) {
	// 0x2754B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2754B8: movss [0x00568F20], xmm0
	X86_MEM_WRITE_u32(base, 0x568F20u, ctx.xmm[0].u32[0]);
	// 0x2754C0: ret
	return;
}

void sub_2754D0(X86Context& ctx, uint8_t* base) {
	// 0x2754D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2754D8: movss [0x00568EDC], xmm0
	X86_MEM_WRITE_u32(base, 0x568EDCu, ctx.xmm[0].u32[0]);
	// 0x2754E0: ret
	return;
}

void sub_2754F0(X86Context& ctx, uint8_t* base) {
	// 0x2754F0: movss xmm0, dword ptr [0x00568F20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F20u);
	// 0x2754F8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x275500: movss [0x00568F58], xmm0
	X86_MEM_WRITE_u32(base, 0x568F58u, ctx.xmm[0].u32[0]);
	// 0x275508: ret
	return;
}

void sub_275510(X86Context& ctx, uint8_t* base) {
	// 0x275510: movss xmm0, dword ptr [0x00568EDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EDCu);
	// 0x275518: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x275520: movss [0x00568F40], xmm0
	X86_MEM_WRITE_u32(base, 0x568F40u, ctx.xmm[0].u32[0]);
	// 0x275528: ret
	return;
}

void sub_275530(X86Context& ctx, uint8_t* base) {
	// 0x275530: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x275538: movss [0x00568F70], xmm0
	X86_MEM_WRITE_u32(base, 0x568F70u, ctx.xmm[0].u32[0]);
	// 0x275540: ret
	return;
}

void sub_275550(X86Context& ctx, uint8_t* base) {
	// 0x275550: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x275558: movss [0x00568F5C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F5Cu, ctx.xmm[0].u32[0]);
	// 0x275560: ret
	return;
}

void sub_275570(X86Context& ctx, uint8_t* base) {
	// 0x275570: movss xmm0, dword ptr [0x00568F5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F5Cu);
	// 0x275578: movss [0x00568F6C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F6Cu, ctx.xmm[0].u32[0]);
	// 0x275580: ret
	return;
}

void sub_275590(X86Context& ctx, uint8_t* base) {
	// 0x275590: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x275598: movss [0x00568EC8], xmm0
	X86_MEM_WRITE_u32(base, 0x568EC8u, ctx.xmm[0].u32[0]);
	// 0x2755A0: ret
	return;
}

void sub_2755B0(X86Context& ctx, uint8_t* base) {
	// 0x2755B0: movss xmm0, dword ptr [0x00568EDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EDCu);
	// 0x2755B8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2755C0: movss [0x00568F64], xmm0
	X86_MEM_WRITE_u32(base, 0x568F64u, ctx.xmm[0].u32[0]);
	// 0x2755C8: ret
	return;
}

void sub_2755D0(X86Context& ctx, uint8_t* base) {
	// 0x2755D0: movss xmm0, dword ptr [0x00568EDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EDCu);
	// 0x2755D8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2755E0: movss [0x00568F08], xmm0
	X86_MEM_WRITE_u32(base, 0x568F08u, ctx.xmm[0].u32[0]);
	// 0x2755E8: ret
	return;
}

void sub_2755F0(X86Context& ctx, uint8_t* base) {
	// 0x2755F0: movss xmm0, dword ptr [0x00568EDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EDCu);
	// 0x2755F8: subss xmm0, [0x00568F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568F08u);
	// 0x275600: movss [0x00568EE4], xmm0
	X86_MEM_WRITE_u32(base, 0x568EE4u, ctx.xmm[0].u32[0]);
	// 0x275608: ret
	return;
}

void sub_275610(X86Context& ctx, uint8_t* base) {
	// 0x275610: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x275618: movss [0x00568F34], xmm0
	X86_MEM_WRITE_u32(base, 0x568F34u, ctx.xmm[0].u32[0]);
	// 0x275620: ret
	return;
}

void sub_275630(X86Context& ctx, uint8_t* base) {
	// 0x275630: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x275638: movss [0x00568EE0], xmm0
	X86_MEM_WRITE_u32(base, 0x568EE0u, ctx.xmm[0].u32[0]);
	// 0x275640: ret
	return;
}

void sub_275650(X86Context& ctx, uint8_t* base) {
	// 0x275650: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x275658: movss [0x00568EF4], xmm0
	X86_MEM_WRITE_u32(base, 0x568EF4u, ctx.xmm[0].u32[0]);
	// 0x275660: ret
	return;
}

void sub_275670(X86Context& ctx, uint8_t* base) {
	// 0x275670: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x275678: movss [0x00568F4C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F4Cu, ctx.xmm[0].u32[0]);
	// 0x275680: ret
	return;
}

void sub_275690(X86Context& ctx, uint8_t* base) {
	// 0x275690: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x275698: movss [0x00568F30], xmm0
	X86_MEM_WRITE_u32(base, 0x568F30u, ctx.xmm[0].u32[0]);
	// 0x2756A0: ret
	return;
}

void sub_2756B0(X86Context& ctx, uint8_t* base) {
	// 0x2756B0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2756B8: movss [0x00568ED8], xmm0
	X86_MEM_WRITE_u32(base, 0x568ED8u, ctx.xmm[0].u32[0]);
	// 0x2756C0: ret
	return;
}

void sub_2756D0(X86Context& ctx, uint8_t* base) {
	// 0x2756D0: movss xmm0, dword ptr [0x00568EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EF4u);
	// 0x2756D8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2756E0: movss [0x00568ECC], xmm0
	X86_MEM_WRITE_u32(base, 0x568ECCu, ctx.xmm[0].u32[0]);
	// 0x2756E8: ret
	return;
}

void sub_2756F0(X86Context& ctx, uint8_t* base) {
	// 0x2756F0: movss xmm0, dword ptr [0x00568F4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F4Cu);
	// 0x2756F8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x275700: movss [0x00568F14], xmm0
	X86_MEM_WRITE_u32(base, 0x568F14u, ctx.xmm[0].u32[0]);
	// 0x275708: ret
	return;
}

void sub_275710(X86Context& ctx, uint8_t* base) {
	// 0x275710: movss xmm0, dword ptr [0x00568ECC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568ECCu);
	// 0x275718: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x275720: movss [0x00568F28], xmm0
	X86_MEM_WRITE_u32(base, 0x568F28u, ctx.xmm[0].u32[0]);
	// 0x275728: ret
	return;
}

void sub_275730(X86Context& ctx, uint8_t* base) {
	// 0x275730: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x275738: movss [0x00568EC4], xmm0
	X86_MEM_WRITE_u32(base, 0x568EC4u, ctx.xmm[0].u32[0]);
	// 0x275740: ret
	return;
}

void sub_275750(X86Context& ctx, uint8_t* base) {
	// 0x275750: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x275758: movss [0x00568EF8], xmm0
	X86_MEM_WRITE_u32(base, 0x568EF8u, ctx.xmm[0].u32[0]);
	// 0x275760: ret
	return;
}

void sub_275770(X86Context& ctx, uint8_t* base) {
	// 0x275770: movss xmm0, dword ptr [0x00568EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EF4u);
	// 0x275778: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x275780: movss [0x00568F04], xmm0
	X86_MEM_WRITE_u32(base, 0x568F04u, ctx.xmm[0].u32[0]);
	// 0x275788: ret
	return;
}

void sub_275790(X86Context& ctx, uint8_t* base) {
	// 0x275790: movss xmm0, dword ptr [0x00568F4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F4Cu);
	// 0x275798: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2757A0: movss [0x00568F50], xmm0
	X86_MEM_WRITE_u32(base, 0x568F50u, ctx.xmm[0].u32[0]);
	// 0x2757A8: ret
	return;
}

void sub_2757B0(X86Context& ctx, uint8_t* base) {
	// 0x2757B0: movss xmm0, dword ptr [0x00568F04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F04u);
	// 0x2757B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2757C0: movss [0x00568F3C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F3Cu, ctx.xmm[0].u32[0]);
	// 0x2757C8: ret
	return;
}

void sub_2757D0(X86Context& ctx, uint8_t* base) {
	// 0x2757D0: movss xmm0, dword ptr [0x00568F50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F50u);
	// 0x2757D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2757E0: movss [0x00568F60], xmm0
	X86_MEM_WRITE_u32(base, 0x568F60u, ctx.xmm[0].u32[0]);
	// 0x2757E8: ret
	return;
}

void sub_2757F0(X86Context& ctx, uint8_t* base) {
	// 0x2757F0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2757F8: movss [0x00568ED0], xmm0
	X86_MEM_WRITE_u32(base, 0x568ED0u, ctx.xmm[0].u32[0]);
	// 0x275800: ret
	return;
}

void sub_275810(X86Context& ctx, uint8_t* base) {
	// 0x275810: movss xmm0, dword ptr [0x00568EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EF4u);
	// 0x275818: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275820: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x275828: movss [0x00568F48], xmm0
	X86_MEM_WRITE_u32(base, 0x568F48u, ctx.xmm[0].u32[0]);
	// 0x275830: ret
	return;
}

void sub_275840(X86Context& ctx, uint8_t* base) {
	// 0x275840: movss xmm0, dword ptr [0x00568F4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F4Cu);
	// 0x275848: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275850: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x275858: movss [0x00568EE8], xmm0
	X86_MEM_WRITE_u32(base, 0x568EE8u, ctx.xmm[0].u32[0]);
	// 0x275860: ret
	return;
}

void sub_275870(X86Context& ctx, uint8_t* base) {
	// 0x275870: movss xmm0, dword ptr [0x00568EF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568EF4u);
	// 0x275878: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275880: movss [0x00568EEC], xmm0
	X86_MEM_WRITE_u32(base, 0x568EECu, ctx.xmm[0].u32[0]);
	// 0x275888: ret
	return;
}

void sub_275890(X86Context& ctx, uint8_t* base) {
	// 0x275890: movss xmm0, dword ptr [0x00568F4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F4Cu);
	// 0x275898: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2758A0: movss [0x00568F54], xmm0
	X86_MEM_WRITE_u32(base, 0x568F54u, ctx.xmm[0].u32[0]);
	// 0x2758A8: ret
	return;
}

void sub_2758B0(X86Context& ctx, uint8_t* base) {
	// 0x2758B0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2758B8: movss [0x00568ED4], xmm0
	X86_MEM_WRITE_u32(base, 0x568ED4u, ctx.xmm[0].u32[0]);
	// 0x2758C0: ret
	return;
}

void sub_2758D0(X86Context& ctx, uint8_t* base) {
	// 0x2758D0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2758D8: movss [0x00568F00], xmm0
	X86_MEM_WRITE_u32(base, 0x568F00u, ctx.xmm[0].u32[0]);
	// 0x2758E0: ret
	return;
}

void sub_2758F0(X86Context& ctx, uint8_t* base) {
	// 0x2758F0: movss xmm0, dword ptr [0x00568ED4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568ED4u);
	// 0x2758F8: movss [0x00568F68], xmm0
	X86_MEM_WRITE_u32(base, 0x568F68u, ctx.xmm[0].u32[0]);
	// 0x275900: ret
	return;
}

void sub_275910(X86Context& ctx, uint8_t* base) {
	// 0x275910: movss xmm0, dword ptr [0x00568F4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F4Cu);
	// 0x275918: subss xmm0, [0x00568ED4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568ED4u);
	// 0x275920: movss [0x00568F2C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F2Cu, ctx.xmm[0].u32[0]);
	// 0x275928: ret
	return;
}

void sub_275930(X86Context& ctx, uint8_t* base) {
	// 0x275930: movss xmm0, dword ptr [0x00568F2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F2Cu);
	// 0x275938: subss xmm0, [0x00568F00]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568F00u);
	// 0x275940: movss [0x00568F24], xmm0
	X86_MEM_WRITE_u32(base, 0x568F24u, ctx.xmm[0].u32[0]);
	// 0x275948: ret
	return;
}

void sub_275950(X86Context& ctx, uint8_t* base) {
	// 0x275950: movss xmm0, dword ptr [0x00568F54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F54u);
	// 0x275958: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x275960: movss [0x00568F10], xmm0
	X86_MEM_WRITE_u32(base, 0x568F10u, ctx.xmm[0].u32[0]);
	// 0x275968: ret
	return;
}

void sub_275970(X86Context& ctx, uint8_t* base) {
	// 0x275970: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x275978: movss [0x00568EFC], xmm0
	X86_MEM_WRITE_u32(base, 0x568EFCu, ctx.xmm[0].u32[0]);
	// 0x275980: ret
	return;
}

void sub_275990(X86Context& ctx, uint8_t* base) {
	// 0x275990: movss xmm0, dword ptr [0x00568F10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F10u);
	// 0x275998: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2759A0: movss [0x00568F44], xmm0
	X86_MEM_WRITE_u32(base, 0x568F44u, ctx.xmm[0].u32[0]);
	// 0x2759A8: ret
	return;
}

void sub_2759B0(X86Context& ctx, uint8_t* base) {
	// 0x2759B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2759B8: movss [0x00568F18], xmm0
	X86_MEM_WRITE_u32(base, 0x568F18u, ctx.xmm[0].u32[0]);
	// 0x2759C0: ret
	return;
}

void sub_2759D0(X86Context& ctx, uint8_t* base) {
	// 0x2759D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2759D8: movss [0x00568EF0], xmm0
	X86_MEM_WRITE_u32(base, 0x568EF0u, ctx.xmm[0].u32[0]);
	// 0x2759E0: ret
	return;
}

void sub_2759F0(X86Context& ctx, uint8_t* base) {
	// 0x2759F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2759F8: movss [0x00568FD0], xmm0
	X86_MEM_WRITE_u32(base, 0x568FD0u, ctx.xmm[0].u32[0]);
	// 0x275A00: ret
	return;
}

void sub_275A10(X86Context& ctx, uint8_t* base) {
	// 0x275A10: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x275A18: movss [0x00568FEC], xmm0
	X86_MEM_WRITE_u32(base, 0x568FECu, ctx.xmm[0].u32[0]);
	// 0x275A20: ret
	return;
}

void sub_275A30(X86Context& ctx, uint8_t* base) {
	// 0x275A30: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x275A38: movss [0x00568FC0], xmm0
	X86_MEM_WRITE_u32(base, 0x568FC0u, ctx.xmm[0].u32[0]);
	// 0x275A40: ret
	return;
}

void sub_275A50(X86Context& ctx, uint8_t* base) {
	// 0x275A50: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x275A58: movss [0x00568F74], xmm0
	X86_MEM_WRITE_u32(base, 0x568F74u, ctx.xmm[0].u32[0]);
	// 0x275A60: ret
	return;
}

void sub_275A70(X86Context& ctx, uint8_t* base) {
	// 0x275A70: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x275A78: movss [0x00568FD4], xmm0
	X86_MEM_WRITE_u32(base, 0x568FD4u, ctx.xmm[0].u32[0]);
	// 0x275A80: ret
	return;
}

void sub_275A90(X86Context& ctx, uint8_t* base) {
	// 0x275A90: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x275A98: movss [0x00568F90], xmm0
	X86_MEM_WRITE_u32(base, 0x568F90u, ctx.xmm[0].u32[0]);
	// 0x275AA0: ret
	return;
}

void sub_275AB0(X86Context& ctx, uint8_t* base) {
	// 0x275AB0: movss xmm0, dword ptr [0x00568FD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FD4u);
	// 0x275AB8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x275AC0: movss [0x0056900C], xmm0
	X86_MEM_WRITE_u32(base, 0x56900Cu, ctx.xmm[0].u32[0]);
	// 0x275AC8: ret
	return;
}

void sub_275AD0(X86Context& ctx, uint8_t* base) {
	// 0x275AD0: movss xmm0, dword ptr [0x00568F90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F90u);
	// 0x275AD8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x275AE0: movss [0x00568FF4], xmm0
	X86_MEM_WRITE_u32(base, 0x568FF4u, ctx.xmm[0].u32[0]);
	// 0x275AE8: ret
	return;
}

void sub_275AF0(X86Context& ctx, uint8_t* base) {
	// 0x275AF0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x275AF8: movss [0x00569024], xmm0
	X86_MEM_WRITE_u32(base, 0x569024u, ctx.xmm[0].u32[0]);
	// 0x275B00: ret
	return;
}

void sub_275B10(X86Context& ctx, uint8_t* base) {
	// 0x275B10: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x275B18: movss [0x00569010], xmm0
	X86_MEM_WRITE_u32(base, 0x569010u, ctx.xmm[0].u32[0]);
	// 0x275B20: ret
	return;
}

void sub_275B30(X86Context& ctx, uint8_t* base) {
	// 0x275B30: movss xmm0, dword ptr [0x00569010]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569010u);
	// 0x275B38: movss [0x00569020], xmm0
	X86_MEM_WRITE_u32(base, 0x569020u, ctx.xmm[0].u32[0]);
	// 0x275B40: ret
	return;
}

void sub_275B50(X86Context& ctx, uint8_t* base) {
	// 0x275B50: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x275B58: movss [0x00568F7C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F7Cu, ctx.xmm[0].u32[0]);
	// 0x275B60: ret
	return;
}

void sub_275B70(X86Context& ctx, uint8_t* base) {
	// 0x275B70: movss xmm0, dword ptr [0x00568F90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F90u);
	// 0x275B78: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x275B80: movss [0x00569018], xmm0
	X86_MEM_WRITE_u32(base, 0x569018u, ctx.xmm[0].u32[0]);
	// 0x275B88: ret
	return;
}

void sub_275B90(X86Context& ctx, uint8_t* base) {
	// 0x275B90: movss xmm0, dword ptr [0x00568F90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F90u);
	// 0x275B98: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x275BA0: movss [0x00568FBC], xmm0
	X86_MEM_WRITE_u32(base, 0x568FBCu, ctx.xmm[0].u32[0]);
	// 0x275BA8: ret
	return;
}

void sub_275BB0(X86Context& ctx, uint8_t* base) {
	// 0x275BB0: movss xmm0, dword ptr [0x00568F90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F90u);
	// 0x275BB8: subss xmm0, [0x00568FBC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568FBCu);
	// 0x275BC0: movss [0x00568F98], xmm0
	X86_MEM_WRITE_u32(base, 0x568F98u, ctx.xmm[0].u32[0]);
	// 0x275BC8: ret
	return;
}

void sub_275BD0(X86Context& ctx, uint8_t* base) {
	// 0x275BD0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x275BD8: movss [0x00568FE8], xmm0
	X86_MEM_WRITE_u32(base, 0x568FE8u, ctx.xmm[0].u32[0]);
	// 0x275BE0: ret
	return;
}

void sub_275BF0(X86Context& ctx, uint8_t* base) {
	// 0x275BF0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x275BF8: movss [0x00568F94], xmm0
	X86_MEM_WRITE_u32(base, 0x568F94u, ctx.xmm[0].u32[0]);
	// 0x275C00: ret
	return;
}

void sub_275C10(X86Context& ctx, uint8_t* base) {
	// 0x275C10: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x275C18: movss [0x00568FA8], xmm0
	X86_MEM_WRITE_u32(base, 0x568FA8u, ctx.xmm[0].u32[0]);
	// 0x275C20: ret
	return;
}

void sub_275C30(X86Context& ctx, uint8_t* base) {
	// 0x275C30: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x275C38: movss [0x00569000], xmm0
	X86_MEM_WRITE_u32(base, 0x569000u, ctx.xmm[0].u32[0]);
	// 0x275C40: ret
	return;
}

void sub_275C50(X86Context& ctx, uint8_t* base) {
	// 0x275C50: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x275C58: movss [0x00568FE4], xmm0
	X86_MEM_WRITE_u32(base, 0x568FE4u, ctx.xmm[0].u32[0]);
	// 0x275C60: ret
	return;
}

void sub_275C70(X86Context& ctx, uint8_t* base) {
	// 0x275C70: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x275C78: movss [0x00568F8C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F8Cu, ctx.xmm[0].u32[0]);
	// 0x275C80: ret
	return;
}

void sub_275C90(X86Context& ctx, uint8_t* base) {
	// 0x275C90: movss xmm0, dword ptr [0x00568FA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FA8u);
	// 0x275C98: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x275CA0: movss [0x00568F80], xmm0
	X86_MEM_WRITE_u32(base, 0x568F80u, ctx.xmm[0].u32[0]);
	// 0x275CA8: ret
	return;
}

void sub_275CB0(X86Context& ctx, uint8_t* base) {
	// 0x275CB0: movss xmm0, dword ptr [0x00569000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569000u);
	// 0x275CB8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x275CC0: movss [0x00568FC8], xmm0
	X86_MEM_WRITE_u32(base, 0x568FC8u, ctx.xmm[0].u32[0]);
	// 0x275CC8: ret
	return;
}

void sub_275CD0(X86Context& ctx, uint8_t* base) {
	// 0x275CD0: movss xmm0, dword ptr [0x00568F80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F80u);
	// 0x275CD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x275CE0: movss [0x00568FDC], xmm0
	X86_MEM_WRITE_u32(base, 0x568FDCu, ctx.xmm[0].u32[0]);
	// 0x275CE8: ret
	return;
}

void sub_275CF0(X86Context& ctx, uint8_t* base) {
	// 0x275CF0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x275CF8: movss [0x00568F78], xmm0
	X86_MEM_WRITE_u32(base, 0x568F78u, ctx.xmm[0].u32[0]);
	// 0x275D00: ret
	return;
}

void sub_275D10(X86Context& ctx, uint8_t* base) {
	// 0x275D10: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x275D18: movss [0x00568FAC], xmm0
	X86_MEM_WRITE_u32(base, 0x568FACu, ctx.xmm[0].u32[0]);
	// 0x275D20: ret
	return;
}

void sub_275D30(X86Context& ctx, uint8_t* base) {
	// 0x275D30: movss xmm0, dword ptr [0x00568FA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FA8u);
	// 0x275D38: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x275D40: movss [0x00568FB8], xmm0
	X86_MEM_WRITE_u32(base, 0x568FB8u, ctx.xmm[0].u32[0]);
	// 0x275D48: ret
	return;
}

void sub_275D50(X86Context& ctx, uint8_t* base) {
	// 0x275D50: movss xmm0, dword ptr [0x00569000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569000u);
	// 0x275D58: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x275D60: movss [0x00569004], xmm0
	X86_MEM_WRITE_u32(base, 0x569004u, ctx.xmm[0].u32[0]);
	// 0x275D68: ret
	return;
}

void sub_275D70(X86Context& ctx, uint8_t* base) {
	// 0x275D70: movss xmm0, dword ptr [0x00568FB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FB8u);
	// 0x275D78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275D80: movss [0x00568FF0], xmm0
	X86_MEM_WRITE_u32(base, 0x568FF0u, ctx.xmm[0].u32[0]);
	// 0x275D88: ret
	return;
}

void sub_275D90(X86Context& ctx, uint8_t* base) {
	// 0x275D90: movss xmm0, dword ptr [0x00569004]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569004u);
	// 0x275D98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275DA0: movss [0x00569014], xmm0
	X86_MEM_WRITE_u32(base, 0x569014u, ctx.xmm[0].u32[0]);
	// 0x275DA8: ret
	return;
}

void sub_275DB0(X86Context& ctx, uint8_t* base) {
	// 0x275DB0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x275DB8: movss [0x00568F84], xmm0
	X86_MEM_WRITE_u32(base, 0x568F84u, ctx.xmm[0].u32[0]);
	// 0x275DC0: ret
	return;
}

void sub_275DD0(X86Context& ctx, uint8_t* base) {
	// 0x275DD0: movss xmm0, dword ptr [0x00568FA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FA8u);
	// 0x275DD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275DE0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x275DE8: movss [0x00568FFC], xmm0
	X86_MEM_WRITE_u32(base, 0x568FFCu, ctx.xmm[0].u32[0]);
	// 0x275DF0: ret
	return;
}

void sub_275E00(X86Context& ctx, uint8_t* base) {
	// 0x275E00: movss xmm0, dword ptr [0x00569000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569000u);
	// 0x275E08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275E10: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x275E18: movss [0x00568F9C], xmm0
	X86_MEM_WRITE_u32(base, 0x568F9Cu, ctx.xmm[0].u32[0]);
	// 0x275E20: ret
	return;
}

void sub_275E30(X86Context& ctx, uint8_t* base) {
	// 0x275E30: movss xmm0, dword ptr [0x00568FA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FA8u);
	// 0x275E38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275E40: movss [0x00568FA0], xmm0
	X86_MEM_WRITE_u32(base, 0x568FA0u, ctx.xmm[0].u32[0]);
	// 0x275E48: ret
	return;
}

void sub_275E50(X86Context& ctx, uint8_t* base) {
	// 0x275E50: movss xmm0, dword ptr [0x00569000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569000u);
	// 0x275E58: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x275E60: movss [0x00569008], xmm0
	X86_MEM_WRITE_u32(base, 0x569008u, ctx.xmm[0].u32[0]);
	// 0x275E68: ret
	return;
}

void sub_275E70(X86Context& ctx, uint8_t* base) {
	// 0x275E70: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x275E78: movss [0x00568F88], xmm0
	X86_MEM_WRITE_u32(base, 0x568F88u, ctx.xmm[0].u32[0]);
	// 0x275E80: ret
	return;
}

void sub_275E90(X86Context& ctx, uint8_t* base) {
	// 0x275E90: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x275E98: movss [0x00568FB4], xmm0
	X86_MEM_WRITE_u32(base, 0x568FB4u, ctx.xmm[0].u32[0]);
	// 0x275EA0: ret
	return;
}

void sub_275EB0(X86Context& ctx, uint8_t* base) {
	// 0x275EB0: movss xmm0, dword ptr [0x00568F88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568F88u);
	// 0x275EB8: movss [0x0056901C], xmm0
	X86_MEM_WRITE_u32(base, 0x56901Cu, ctx.xmm[0].u32[0]);
	// 0x275EC0: ret
	return;
}

void sub_275ED0(X86Context& ctx, uint8_t* base) {
	// 0x275ED0: movss xmm0, dword ptr [0x00569000]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569000u);
	// 0x275ED8: subss xmm0, [0x00568F88]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568F88u);
	// 0x275EE0: movss [0x00568FE0], xmm0
	X86_MEM_WRITE_u32(base, 0x568FE0u, ctx.xmm[0].u32[0]);
	// 0x275EE8: ret
	return;
}

void sub_275EF0(X86Context& ctx, uint8_t* base) {
	// 0x275EF0: movss xmm0, dword ptr [0x00568FE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FE0u);
	// 0x275EF8: subss xmm0, [0x00568FB4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x568FB4u);
	// 0x275F00: movss [0x00568FD8], xmm0
	X86_MEM_WRITE_u32(base, 0x568FD8u, ctx.xmm[0].u32[0]);
	// 0x275F08: ret
	return;
}

void sub_275F10(X86Context& ctx, uint8_t* base) {
	// 0x275F10: movss xmm0, dword ptr [0x00569008]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569008u);
	// 0x275F18: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x275F20: movss [0x00568FC4], xmm0
	X86_MEM_WRITE_u32(base, 0x568FC4u, ctx.xmm[0].u32[0]);
	// 0x275F28: ret
	return;
}

void sub_275F30(X86Context& ctx, uint8_t* base) {
	// 0x275F30: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x275F38: movss [0x00568FB0], xmm0
	X86_MEM_WRITE_u32(base, 0x568FB0u, ctx.xmm[0].u32[0]);
	// 0x275F40: ret
	return;
}

void sub_275F50(X86Context& ctx, uint8_t* base) {
	// 0x275F50: movss xmm0, dword ptr [0x00568FC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x568FC4u);
	// 0x275F58: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x275F60: movss [0x00568FF8], xmm0
	X86_MEM_WRITE_u32(base, 0x568FF8u, ctx.xmm[0].u32[0]);
	// 0x275F68: ret
	return;
}

void sub_275F70(X86Context& ctx, uint8_t* base) {
	// 0x275F70: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x275F78: movss [0x00568FCC], xmm0
	X86_MEM_WRITE_u32(base, 0x568FCCu, ctx.xmm[0].u32[0]);
	// 0x275F80: ret
	return;
}

void sub_275F90(X86Context& ctx, uint8_t* base) {
	// 0x275F90: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x275F98: movss [0x00568FA4], xmm0
	X86_MEM_WRITE_u32(base, 0x568FA4u, ctx.xmm[0].u32[0]);
	// 0x275FA0: ret
	return;
}

void sub_275FB0(X86Context& ctx, uint8_t* base) {
	// 0x275FB0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x275FB8: movss [0x00569084], xmm0
	X86_MEM_WRITE_u32(base, 0x569084u, ctx.xmm[0].u32[0]);
	// 0x275FC0: ret
	return;
}

void sub_275FD0(X86Context& ctx, uint8_t* base) {
	// 0x275FD0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x275FD8: movss [0x005690A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5690A0u, ctx.xmm[0].u32[0]);
	// 0x275FE0: ret
	return;
}

void sub_275FF0(X86Context& ctx, uint8_t* base) {
	// 0x275FF0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x275FF8: movss [0x00569074], xmm0
	X86_MEM_WRITE_u32(base, 0x569074u, ctx.xmm[0].u32[0]);
}

void sub_276000(X86Context& ctx, uint8_t* base) {
	// 0x276000: ret
	return;
}

void sub_276010(X86Context& ctx, uint8_t* base) {
	// 0x276010: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x276018: movss [0x00569028], xmm0
	X86_MEM_WRITE_u32(base, 0x569028u, ctx.xmm[0].u32[0]);
	// 0x276020: ret
	return;
}

void sub_276030(X86Context& ctx, uint8_t* base) {
	// 0x276030: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x276038: movss [0x00569088], xmm0
	X86_MEM_WRITE_u32(base, 0x569088u, ctx.xmm[0].u32[0]);
	// 0x276040: ret
	return;
}

void sub_276050(X86Context& ctx, uint8_t* base) {
	// 0x276050: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x276058: movss [0x00569044], xmm0
	X86_MEM_WRITE_u32(base, 0x569044u, ctx.xmm[0].u32[0]);
	// 0x276060: ret
	return;
}

void sub_276070(X86Context& ctx, uint8_t* base) {
	// 0x276070: movss xmm0, dword ptr [0x00569088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569088u);
	// 0x276078: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276080: movss [0x005690C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5690C0u, ctx.xmm[0].u32[0]);
	// 0x276088: ret
	return;
}

void sub_276090(X86Context& ctx, uint8_t* base) {
	// 0x276090: movss xmm0, dword ptr [0x00569044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569044u);
	// 0x276098: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2760A0: movss [0x005690A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5690A8u, ctx.xmm[0].u32[0]);
	// 0x2760A8: ret
	return;
}

void sub_2760B0(X86Context& ctx, uint8_t* base) {
	// 0x2760B0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2760B8: movss [0x005690D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5690D8u, ctx.xmm[0].u32[0]);
	// 0x2760C0: ret
	return;
}

void sub_2760D0(X86Context& ctx, uint8_t* base) {
	// 0x2760D0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2760D8: movss [0x005690C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5690C4u, ctx.xmm[0].u32[0]);
	// 0x2760E0: ret
	return;
}

void sub_2760F0(X86Context& ctx, uint8_t* base) {
	// 0x2760F0: movss xmm0, dword ptr [0x005690C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690C4u);
	// 0x2760F8: movss [0x005690D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5690D4u, ctx.xmm[0].u32[0]);
	// 0x276100: ret
	return;
}

void sub_276110(X86Context& ctx, uint8_t* base) {
	// 0x276110: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x276118: movss [0x00569030], xmm0
	X86_MEM_WRITE_u32(base, 0x569030u, ctx.xmm[0].u32[0]);
	// 0x276120: ret
	return;
}

void sub_276130(X86Context& ctx, uint8_t* base) {
	// 0x276130: movss xmm0, dword ptr [0x00569044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569044u);
	// 0x276138: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x276140: movss [0x005690CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5690CCu, ctx.xmm[0].u32[0]);
	// 0x276148: ret
	return;
}

void sub_276150(X86Context& ctx, uint8_t* base) {
	// 0x276150: movss xmm0, dword ptr [0x00569044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569044u);
	// 0x276158: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x276160: movss [0x00569070], xmm0
	X86_MEM_WRITE_u32(base, 0x569070u, ctx.xmm[0].u32[0]);
	// 0x276168: ret
	return;
}

void sub_276170(X86Context& ctx, uint8_t* base) {
	// 0x276170: movss xmm0, dword ptr [0x00569044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569044u);
	// 0x276178: subss xmm0, [0x00569070]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569070u);
	// 0x276180: movss [0x0056904C], xmm0
	X86_MEM_WRITE_u32(base, 0x56904Cu, ctx.xmm[0].u32[0]);
	// 0x276188: ret
	return;
}

void sub_276190(X86Context& ctx, uint8_t* base) {
	// 0x276190: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x276198: movss [0x0056909C], xmm0
	X86_MEM_WRITE_u32(base, 0x56909Cu, ctx.xmm[0].u32[0]);
	// 0x2761A0: ret
	return;
}

void sub_2761B0(X86Context& ctx, uint8_t* base) {
	// 0x2761B0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2761B8: movss [0x00569048], xmm0
	X86_MEM_WRITE_u32(base, 0x569048u, ctx.xmm[0].u32[0]);
	// 0x2761C0: ret
	return;
}

void sub_2761D0(X86Context& ctx, uint8_t* base) {
	// 0x2761D0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2761D8: movss [0x0056905C], xmm0
	X86_MEM_WRITE_u32(base, 0x56905Cu, ctx.xmm[0].u32[0]);
	// 0x2761E0: ret
	return;
}

void sub_2761F0(X86Context& ctx, uint8_t* base) {
	// 0x2761F0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2761F8: movss [0x005690B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5690B4u, ctx.xmm[0].u32[0]);
	// 0x276200: ret
	return;
}

void sub_276210(X86Context& ctx, uint8_t* base) {
	// 0x276210: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x276218: movss [0x00569098], xmm0
	X86_MEM_WRITE_u32(base, 0x569098u, ctx.xmm[0].u32[0]);
	// 0x276220: ret
	return;
}

void sub_276230(X86Context& ctx, uint8_t* base) {
	// 0x276230: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x276238: movss [0x00569040], xmm0
	X86_MEM_WRITE_u32(base, 0x569040u, ctx.xmm[0].u32[0]);
	// 0x276240: ret
	return;
}

void sub_276250(X86Context& ctx, uint8_t* base) {
	// 0x276250: movss xmm0, dword ptr [0x0056905C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56905Cu);
	// 0x276258: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276260: movss [0x00569034], xmm0
	X86_MEM_WRITE_u32(base, 0x569034u, ctx.xmm[0].u32[0]);
	// 0x276268: ret
	return;
}

void sub_276270(X86Context& ctx, uint8_t* base) {
	// 0x276270: movss xmm0, dword ptr [0x005690B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690B4u);
	// 0x276278: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x276280: movss [0x0056907C], xmm0
	X86_MEM_WRITE_u32(base, 0x56907Cu, ctx.xmm[0].u32[0]);
	// 0x276288: ret
	return;
}

void sub_276290(X86Context& ctx, uint8_t* base) {
	// 0x276290: movss xmm0, dword ptr [0x00569034]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569034u);
	// 0x276298: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2762A0: movss [0x00569090], xmm0
	X86_MEM_WRITE_u32(base, 0x569090u, ctx.xmm[0].u32[0]);
	// 0x2762A8: ret
	return;
}

void sub_2762B0(X86Context& ctx, uint8_t* base) {
	// 0x2762B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2762B8: movss [0x0056902C], xmm0
	X86_MEM_WRITE_u32(base, 0x56902Cu, ctx.xmm[0].u32[0]);
	// 0x2762C0: ret
	return;
}

void sub_2762D0(X86Context& ctx, uint8_t* base) {
	// 0x2762D0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2762D8: movss [0x00569060], xmm0
	X86_MEM_WRITE_u32(base, 0x569060u, ctx.xmm[0].u32[0]);
	// 0x2762E0: ret
	return;
}

void sub_2762F0(X86Context& ctx, uint8_t* base) {
	// 0x2762F0: movss xmm0, dword ptr [0x0056905C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56905Cu);
	// 0x2762F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x276300: movss [0x0056906C], xmm0
	X86_MEM_WRITE_u32(base, 0x56906Cu, ctx.xmm[0].u32[0]);
	// 0x276308: ret
	return;
}

void sub_276310(X86Context& ctx, uint8_t* base) {
	// 0x276310: movss xmm0, dword ptr [0x005690B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690B4u);
	// 0x276318: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x276320: movss [0x005690B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5690B8u, ctx.xmm[0].u32[0]);
	// 0x276328: ret
	return;
}

void sub_276330(X86Context& ctx, uint8_t* base) {
	// 0x276330: movss xmm0, dword ptr [0x0056906C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56906Cu);
	// 0x276338: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276340: movss [0x005690A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5690A4u, ctx.xmm[0].u32[0]);
	// 0x276348: ret
	return;
}

void sub_276350(X86Context& ctx, uint8_t* base) {
	// 0x276350: movss xmm0, dword ptr [0x005690B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690B8u);
	// 0x276358: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276360: movss [0x005690C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5690C8u, ctx.xmm[0].u32[0]);
	// 0x276368: ret
	return;
}

void sub_276370(X86Context& ctx, uint8_t* base) {
	// 0x276370: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x276378: movss [0x00569038], xmm0
	X86_MEM_WRITE_u32(base, 0x569038u, ctx.xmm[0].u32[0]);
	// 0x276380: ret
	return;
}

void sub_276390(X86Context& ctx, uint8_t* base) {
	// 0x276390: movss xmm0, dword ptr [0x0056905C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56905Cu);
	// 0x276398: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2763A0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2763A8: movss [0x005690B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5690B0u, ctx.xmm[0].u32[0]);
	// 0x2763B0: ret
	return;
}

void sub_2763C0(X86Context& ctx, uint8_t* base) {
	// 0x2763C0: movss xmm0, dword ptr [0x005690B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690B4u);
	// 0x2763C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2763D0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2763D8: movss [0x00569050], xmm0
	X86_MEM_WRITE_u32(base, 0x569050u, ctx.xmm[0].u32[0]);
	// 0x2763E0: ret
	return;
}

void sub_2763F0(X86Context& ctx, uint8_t* base) {
	// 0x2763F0: movss xmm0, dword ptr [0x0056905C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56905Cu);
	// 0x2763F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276400: movss [0x00569054], xmm0
	X86_MEM_WRITE_u32(base, 0x569054u, ctx.xmm[0].u32[0]);
	// 0x276408: ret
	return;
}

void sub_276410(X86Context& ctx, uint8_t* base) {
	// 0x276410: movss xmm0, dword ptr [0x005690B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690B4u);
	// 0x276418: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276420: movss [0x005690BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5690BCu, ctx.xmm[0].u32[0]);
	// 0x276428: ret
	return;
}

void sub_276430(X86Context& ctx, uint8_t* base) {
	// 0x276430: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x276438: movss [0x0056903C], xmm0
	X86_MEM_WRITE_u32(base, 0x56903Cu, ctx.xmm[0].u32[0]);
	// 0x276440: ret
	return;
}

void sub_276450(X86Context& ctx, uint8_t* base) {
	// 0x276450: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x276458: movss [0x00569068], xmm0
	X86_MEM_WRITE_u32(base, 0x569068u, ctx.xmm[0].u32[0]);
	// 0x276460: ret
	return;
}

void sub_276470(X86Context& ctx, uint8_t* base) {
	// 0x276470: movss xmm0, dword ptr [0x0056903C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56903Cu);
	// 0x276478: movss [0x005690D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5690D0u, ctx.xmm[0].u32[0]);
	// 0x276480: ret
	return;
}

void sub_276490(X86Context& ctx, uint8_t* base) {
	// 0x276490: movss xmm0, dword ptr [0x005690B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690B4u);
	// 0x276498: subss xmm0, [0x0056903C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56903Cu);
	// 0x2764A0: movss [0x00569094], xmm0
	X86_MEM_WRITE_u32(base, 0x569094u, ctx.xmm[0].u32[0]);
	// 0x2764A8: ret
	return;
}

void sub_2764B0(X86Context& ctx, uint8_t* base) {
	// 0x2764B0: movss xmm0, dword ptr [0x00569094]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569094u);
	// 0x2764B8: subss xmm0, [0x00569068]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569068u);
	// 0x2764C0: movss [0x0056908C], xmm0
	X86_MEM_WRITE_u32(base, 0x56908Cu, ctx.xmm[0].u32[0]);
	// 0x2764C8: ret
	return;
}

void sub_2764D0(X86Context& ctx, uint8_t* base) {
	// 0x2764D0: movss xmm0, dword ptr [0x005690BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690BCu);
	// 0x2764D8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2764E0: movss [0x00569078], xmm0
	X86_MEM_WRITE_u32(base, 0x569078u, ctx.xmm[0].u32[0]);
	// 0x2764E8: ret
	return;
}

void sub_2764F0(X86Context& ctx, uint8_t* base) {
	// 0x2764F0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2764F8: movss [0x00569064], xmm0
	X86_MEM_WRITE_u32(base, 0x569064u, ctx.xmm[0].u32[0]);
	// 0x276500: ret
	return;
}

void sub_276510(X86Context& ctx, uint8_t* base) {
	// 0x276510: movss xmm0, dword ptr [0x00569078]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569078u);
	// 0x276518: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x276520: movss [0x005690AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5690ACu, ctx.xmm[0].u32[0]);
	// 0x276528: ret
	return;
}

void sub_276530(X86Context& ctx, uint8_t* base) {
	// 0x276530: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x276538: movss [0x00569080], xmm0
	X86_MEM_WRITE_u32(base, 0x569080u, ctx.xmm[0].u32[0]);
	// 0x276540: ret
	return;
}

void sub_276550(X86Context& ctx, uint8_t* base) {
	// 0x276550: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x276558: movss [0x00569058], xmm0
	X86_MEM_WRITE_u32(base, 0x569058u, ctx.xmm[0].u32[0]);
	// 0x276560: ret
	return;
}

void sub_276570(X86Context& ctx, uint8_t* base) {
	// 0x276570: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x276578: movss [0x00569138], xmm0
	X86_MEM_WRITE_u32(base, 0x569138u, ctx.xmm[0].u32[0]);
	// 0x276580: ret
	return;
}

void sub_276590(X86Context& ctx, uint8_t* base) {
	// 0x276590: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x276598: movss [0x00569154], xmm0
	X86_MEM_WRITE_u32(base, 0x569154u, ctx.xmm[0].u32[0]);
	// 0x2765A0: ret
	return;
}

void sub_2765B0(X86Context& ctx, uint8_t* base) {
	// 0x2765B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2765B8: movss [0x00569128], xmm0
	X86_MEM_WRITE_u32(base, 0x569128u, ctx.xmm[0].u32[0]);
	// 0x2765C0: ret
	return;
}

void sub_2765D0(X86Context& ctx, uint8_t* base) {
	// 0x2765D0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2765D8: movss [0x005690DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5690DCu, ctx.xmm[0].u32[0]);
	// 0x2765E0: ret
	return;
}

void sub_2765F0(X86Context& ctx, uint8_t* base) {
	// 0x2765F0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2765F8: movss [0x0056913C], xmm0
	X86_MEM_WRITE_u32(base, 0x56913Cu, ctx.xmm[0].u32[0]);
	// 0x276600: ret
	return;
}

void sub_276610(X86Context& ctx, uint8_t* base) {
	// 0x276610: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x276618: movss [0x005690F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5690F8u, ctx.xmm[0].u32[0]);
	// 0x276620: ret
	return;
}

void sub_276630(X86Context& ctx, uint8_t* base) {
	// 0x276630: movss xmm0, dword ptr [0x0056913C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56913Cu);
	// 0x276638: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276640: movss [0x00569174], xmm0
	X86_MEM_WRITE_u32(base, 0x569174u, ctx.xmm[0].u32[0]);
	// 0x276648: ret
	return;
}

void sub_276650(X86Context& ctx, uint8_t* base) {
	// 0x276650: movss xmm0, dword ptr [0x005690F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690F8u);
	// 0x276658: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x276660: movss [0x0056915C], xmm0
	X86_MEM_WRITE_u32(base, 0x56915Cu, ctx.xmm[0].u32[0]);
	// 0x276668: ret
	return;
}

void sub_276670(X86Context& ctx, uint8_t* base) {
	// 0x276670: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x276678: movss [0x0056918C], xmm0
	X86_MEM_WRITE_u32(base, 0x56918Cu, ctx.xmm[0].u32[0]);
	// 0x276680: ret
	return;
}

void sub_276690(X86Context& ctx, uint8_t* base) {
	// 0x276690: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x276698: movss [0x00569178], xmm0
	X86_MEM_WRITE_u32(base, 0x569178u, ctx.xmm[0].u32[0]);
	// 0x2766A0: ret
	return;
}

void sub_2766B0(X86Context& ctx, uint8_t* base) {
	// 0x2766B0: movss xmm0, dword ptr [0x00569178]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569178u);
	// 0x2766B8: movss [0x00569188], xmm0
	X86_MEM_WRITE_u32(base, 0x569188u, ctx.xmm[0].u32[0]);
	// 0x2766C0: ret
	return;
}

void sub_2766D0(X86Context& ctx, uint8_t* base) {
	// 0x2766D0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2766D8: movss [0x005690E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5690E4u, ctx.xmm[0].u32[0]);
	// 0x2766E0: ret
	return;
}

void sub_2766F0(X86Context& ctx, uint8_t* base) {
	// 0x2766F0: movss xmm0, dword ptr [0x005690F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690F8u);
	// 0x2766F8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x276700: movss [0x00569180], xmm0
	X86_MEM_WRITE_u32(base, 0x569180u, ctx.xmm[0].u32[0]);
	// 0x276708: ret
	return;
}

void sub_276710(X86Context& ctx, uint8_t* base) {
	// 0x276710: movss xmm0, dword ptr [0x005690F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690F8u);
	// 0x276718: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x276720: movss [0x00569124], xmm0
	X86_MEM_WRITE_u32(base, 0x569124u, ctx.xmm[0].u32[0]);
	// 0x276728: ret
	return;
}

void sub_276730(X86Context& ctx, uint8_t* base) {
	// 0x276730: movss xmm0, dword ptr [0x005690F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690F8u);
	// 0x276738: subss xmm0, [0x00569124]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x569124u);
	// 0x276740: movss [0x00569100], xmm0
	X86_MEM_WRITE_u32(base, 0x569100u, ctx.xmm[0].u32[0]);
	// 0x276748: ret
	return;
}

void sub_276750(X86Context& ctx, uint8_t* base) {
	// 0x276750: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x276758: movss [0x00569150], xmm0
	X86_MEM_WRITE_u32(base, 0x569150u, ctx.xmm[0].u32[0]);
	// 0x276760: ret
	return;
}

void sub_276770(X86Context& ctx, uint8_t* base) {
	// 0x276770: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x276778: movss [0x005690FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5690FCu, ctx.xmm[0].u32[0]);
	// 0x276780: ret
	return;
}

void sub_276790(X86Context& ctx, uint8_t* base) {
	// 0x276790: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x276798: movss [0x00569110], xmm0
	X86_MEM_WRITE_u32(base, 0x569110u, ctx.xmm[0].u32[0]);
	// 0x2767A0: ret
	return;
}

void sub_2767B0(X86Context& ctx, uint8_t* base) {
	// 0x2767B0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2767B8: movss [0x00569168], xmm0
	X86_MEM_WRITE_u32(base, 0x569168u, ctx.xmm[0].u32[0]);
	// 0x2767C0: ret
	return;
}

void sub_2767D0(X86Context& ctx, uint8_t* base) {
	// 0x2767D0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2767D8: movss [0x0056914C], xmm0
	X86_MEM_WRITE_u32(base, 0x56914Cu, ctx.xmm[0].u32[0]);
	// 0x2767E0: ret
	return;
}

void sub_2767F0(X86Context& ctx, uint8_t* base) {
	// 0x2767F0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2767F8: movss [0x005690F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5690F4u, ctx.xmm[0].u32[0]);
	// 0x276800: ret
	return;
}

void sub_276810(X86Context& ctx, uint8_t* base) {
	// 0x276810: movss xmm0, dword ptr [0x00569110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569110u);
	// 0x276818: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276820: movss [0x005690E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5690E8u, ctx.xmm[0].u32[0]);
	// 0x276828: ret
	return;
}

void sub_276830(X86Context& ctx, uint8_t* base) {
	// 0x276830: movss xmm0, dword ptr [0x00569168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569168u);
	// 0x276838: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x276840: movss [0x00569130], xmm0
	X86_MEM_WRITE_u32(base, 0x569130u, ctx.xmm[0].u32[0]);
	// 0x276848: ret
	return;
}

void sub_276850(X86Context& ctx, uint8_t* base) {
	// 0x276850: movss xmm0, dword ptr [0x005690E8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690E8u);
	// 0x276858: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276860: movss [0x00569144], xmm0
	X86_MEM_WRITE_u32(base, 0x569144u, ctx.xmm[0].u32[0]);
	// 0x276868: ret
	return;
}

void sub_276870(X86Context& ctx, uint8_t* base) {
	// 0x276870: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x276878: movss [0x005690E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5690E0u, ctx.xmm[0].u32[0]);
	// 0x276880: ret
	return;
}

void sub_276890(X86Context& ctx, uint8_t* base) {
	// 0x276890: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x276898: movss [0x00569114], xmm0
	X86_MEM_WRITE_u32(base, 0x569114u, ctx.xmm[0].u32[0]);
	// 0x2768A0: ret
	return;
}

void sub_2768B0(X86Context& ctx, uint8_t* base) {
	// 0x2768B0: movss xmm0, dword ptr [0x00569110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569110u);
	// 0x2768B8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2768C0: movss [0x00569120], xmm0
	X86_MEM_WRITE_u32(base, 0x569120u, ctx.xmm[0].u32[0]);
	// 0x2768C8: ret
	return;
}

void sub_2768D0(X86Context& ctx, uint8_t* base) {
	// 0x2768D0: movss xmm0, dword ptr [0x00569168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569168u);
	// 0x2768D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2768E0: movss [0x0056916C], xmm0
	X86_MEM_WRITE_u32(base, 0x56916Cu, ctx.xmm[0].u32[0]);
	// 0x2768E8: ret
	return;
}

void sub_2768F0(X86Context& ctx, uint8_t* base) {
	// 0x2768F0: movss xmm0, dword ptr [0x00569120]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569120u);
	// 0x2768F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276900: movss [0x00569158], xmm0
	X86_MEM_WRITE_u32(base, 0x569158u, ctx.xmm[0].u32[0]);
	// 0x276908: ret
	return;
}

void sub_276910(X86Context& ctx, uint8_t* base) {
	// 0x276910: movss xmm0, dword ptr [0x0056916C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56916Cu);
	// 0x276918: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276920: movss [0x0056917C], xmm0
	X86_MEM_WRITE_u32(base, 0x56917Cu, ctx.xmm[0].u32[0]);
	// 0x276928: ret
	return;
}

void sub_276930(X86Context& ctx, uint8_t* base) {
	// 0x276930: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x276938: movss [0x005690EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5690ECu, ctx.xmm[0].u32[0]);
	// 0x276940: ret
	return;
}

void sub_276950(X86Context& ctx, uint8_t* base) {
	// 0x276950: movss xmm0, dword ptr [0x00569110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569110u);
	// 0x276958: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276960: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x276968: movss [0x00569164], xmm0
	X86_MEM_WRITE_u32(base, 0x569164u, ctx.xmm[0].u32[0]);
	// 0x276970: ret
	return;
}

void sub_276980(X86Context& ctx, uint8_t* base) {
	// 0x276980: movss xmm0, dword ptr [0x00569168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569168u);
	// 0x276988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276990: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x276998: movss [0x00569104], xmm0
	X86_MEM_WRITE_u32(base, 0x569104u, ctx.xmm[0].u32[0]);
	// 0x2769A0: ret
	return;
}

void sub_2769B0(X86Context& ctx, uint8_t* base) {
	// 0x2769B0: movss xmm0, dword ptr [0x00569110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569110u);
	// 0x2769B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2769C0: movss [0x00569108], xmm0
	X86_MEM_WRITE_u32(base, 0x569108u, ctx.xmm[0].u32[0]);
	// 0x2769C8: ret
	return;
}

void sub_2769D0(X86Context& ctx, uint8_t* base) {
	// 0x2769D0: movss xmm0, dword ptr [0x00569168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569168u);
	// 0x2769D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2769E0: movss [0x00569170], xmm0
	X86_MEM_WRITE_u32(base, 0x569170u, ctx.xmm[0].u32[0]);
	// 0x2769E8: ret
	return;
}

void sub_2769F0(X86Context& ctx, uint8_t* base) {
	// 0x2769F0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2769F8: movss [0x005690F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5690F0u, ctx.xmm[0].u32[0]);
	// 0x276A00: ret
	return;
}

void sub_276A10(X86Context& ctx, uint8_t* base) {
	// 0x276A10: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x276A18: movss [0x0056911C], xmm0
	X86_MEM_WRITE_u32(base, 0x56911Cu, ctx.xmm[0].u32[0]);
	// 0x276A20: ret
	return;
}

void sub_276A30(X86Context& ctx, uint8_t* base) {
	// 0x276A30: movss xmm0, dword ptr [0x005690F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5690F0u);
	// 0x276A38: movss [0x00569184], xmm0
	X86_MEM_WRITE_u32(base, 0x569184u, ctx.xmm[0].u32[0]);
	// 0x276A40: ret
	return;
}

void sub_276A50(X86Context& ctx, uint8_t* base) {
	// 0x276A50: movss xmm0, dword ptr [0x00569168]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569168u);
	// 0x276A58: subss xmm0, [0x005690F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5690F0u);
	// 0x276A60: movss [0x00569148], xmm0
	X86_MEM_WRITE_u32(base, 0x569148u, ctx.xmm[0].u32[0]);
	// 0x276A68: ret
	return;
}

void sub_276A70(X86Context& ctx, uint8_t* base) {
	// 0x276A70: movss xmm0, dword ptr [0x00569148]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569148u);
	// 0x276A78: subss xmm0, [0x0056911C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56911Cu);
	// 0x276A80: movss [0x00569140], xmm0
	X86_MEM_WRITE_u32(base, 0x569140u, ctx.xmm[0].u32[0]);
	// 0x276A88: ret
	return;
}

void sub_276A90(X86Context& ctx, uint8_t* base) {
	// 0x276A90: movss xmm0, dword ptr [0x00569170]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569170u);
	// 0x276A98: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x276AA0: movss [0x0056912C], xmm0
	X86_MEM_WRITE_u32(base, 0x56912Cu, ctx.xmm[0].u32[0]);
	// 0x276AA8: ret
	return;
}

void sub_276AB0(X86Context& ctx, uint8_t* base) {
	// 0x276AB0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x276AB8: movss [0x00569118], xmm0
	X86_MEM_WRITE_u32(base, 0x569118u, ctx.xmm[0].u32[0]);
	// 0x276AC0: ret
	return;
}

void sub_276AD0(X86Context& ctx, uint8_t* base) {
	// 0x276AD0: movss xmm0, dword ptr [0x0056912C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56912Cu);
	// 0x276AD8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x276AE0: movss [0x00569160], xmm0
	X86_MEM_WRITE_u32(base, 0x569160u, ctx.xmm[0].u32[0]);
	// 0x276AE8: ret
	return;
}

void sub_276AF0(X86Context& ctx, uint8_t* base) {
	// 0x276AF0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x276AF8: movss [0x00569134], xmm0
	X86_MEM_WRITE_u32(base, 0x569134u, ctx.xmm[0].u32[0]);
	// 0x276B00: ret
	return;
}

void sub_276B10(X86Context& ctx, uint8_t* base) {
	// 0x276B10: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x276B18: movss [0x0056910C], xmm0
	X86_MEM_WRITE_u32(base, 0x56910Cu, ctx.xmm[0].u32[0]);
	// 0x276B20: ret
	return;
}

void sub_276B30(X86Context& ctx, uint8_t* base) {
	// 0x276B30: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x276B38: movss [0x005691EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5691ECu, ctx.xmm[0].u32[0]);
	// 0x276B40: ret
	return;
}

void sub_276B50(X86Context& ctx, uint8_t* base) {
	// 0x276B50: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x276B58: movss [0x00569208], xmm0
	X86_MEM_WRITE_u32(base, 0x569208u, ctx.xmm[0].u32[0]);
	// 0x276B60: ret
	return;
}

void sub_276B70(X86Context& ctx, uint8_t* base) {
	// 0x276B70: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x276B78: movss [0x005691DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5691DCu, ctx.xmm[0].u32[0]);
	// 0x276B80: ret
	return;
}

void sub_276B90(X86Context& ctx, uint8_t* base) {
	// 0x276B90: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x276B98: movss [0x00569190], xmm0
	X86_MEM_WRITE_u32(base, 0x569190u, ctx.xmm[0].u32[0]);
	// 0x276BA0: ret
	return;
}

void sub_276BB0(X86Context& ctx, uint8_t* base) {
	// 0x276BB0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x276BB8: movss [0x005691F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5691F0u, ctx.xmm[0].u32[0]);
	// 0x276BC0: ret
	return;
}

void sub_276BD0(X86Context& ctx, uint8_t* base) {
	// 0x276BD0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x276BD8: movss [0x005691AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5691ACu, ctx.xmm[0].u32[0]);
	// 0x276BE0: ret
	return;
}

void sub_276BF0(X86Context& ctx, uint8_t* base) {
	// 0x276BF0: movss xmm0, dword ptr [0x005691F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691F0u);
	// 0x276BF8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276C00: movss [0x00569228], xmm0
	X86_MEM_WRITE_u32(base, 0x569228u, ctx.xmm[0].u32[0]);
	// 0x276C08: ret
	return;
}

void sub_276C10(X86Context& ctx, uint8_t* base) {
	// 0x276C10: movss xmm0, dword ptr [0x005691AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691ACu);
	// 0x276C18: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x276C20: movss [0x00569210], xmm0
	X86_MEM_WRITE_u32(base, 0x569210u, ctx.xmm[0].u32[0]);
	// 0x276C28: ret
	return;
}

void sub_276C30(X86Context& ctx, uint8_t* base) {
	// 0x276C30: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x276C38: movss [0x00569240], xmm0
	X86_MEM_WRITE_u32(base, 0x569240u, ctx.xmm[0].u32[0]);
	// 0x276C40: ret
	return;
}

void sub_276C50(X86Context& ctx, uint8_t* base) {
	// 0x276C50: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x276C58: movss [0x0056922C], xmm0
	X86_MEM_WRITE_u32(base, 0x56922Cu, ctx.xmm[0].u32[0]);
	// 0x276C60: ret
	return;
}

void sub_276C70(X86Context& ctx, uint8_t* base) {
	// 0x276C70: movss xmm0, dword ptr [0x0056922C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56922Cu);
	// 0x276C78: movss [0x0056923C], xmm0
	X86_MEM_WRITE_u32(base, 0x56923Cu, ctx.xmm[0].u32[0]);
	// 0x276C80: ret
	return;
}

void sub_276C90(X86Context& ctx, uint8_t* base) {
	// 0x276C90: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x276C98: movss [0x00569198], xmm0
	X86_MEM_WRITE_u32(base, 0x569198u, ctx.xmm[0].u32[0]);
	// 0x276CA0: ret
	return;
}

void sub_276CB0(X86Context& ctx, uint8_t* base) {
	// 0x276CB0: movss xmm0, dword ptr [0x005691AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691ACu);
	// 0x276CB8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x276CC0: movss [0x00569234], xmm0
	X86_MEM_WRITE_u32(base, 0x569234u, ctx.xmm[0].u32[0]);
	// 0x276CC8: ret
	return;
}

void sub_276CD0(X86Context& ctx, uint8_t* base) {
	// 0x276CD0: movss xmm0, dword ptr [0x005691AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691ACu);
	// 0x276CD8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x276CE0: movss [0x005691D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5691D8u, ctx.xmm[0].u32[0]);
	// 0x276CE8: ret
	return;
}

void sub_276CF0(X86Context& ctx, uint8_t* base) {
	// 0x276CF0: movss xmm0, dword ptr [0x005691AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691ACu);
	// 0x276CF8: subss xmm0, [0x005691D8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5691D8u);
	// 0x276D00: movss [0x005691B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5691B4u, ctx.xmm[0].u32[0]);
	// 0x276D08: ret
	return;
}

void sub_276D10(X86Context& ctx, uint8_t* base) {
	// 0x276D10: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x276D18: movss [0x00569204], xmm0
	X86_MEM_WRITE_u32(base, 0x569204u, ctx.xmm[0].u32[0]);
	// 0x276D20: ret
	return;
}

void sub_276D30(X86Context& ctx, uint8_t* base) {
	// 0x276D30: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x276D38: movss [0x005691B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5691B0u, ctx.xmm[0].u32[0]);
	// 0x276D40: ret
	return;
}

void sub_276D50(X86Context& ctx, uint8_t* base) {
	// 0x276D50: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x276D58: movss [0x005691C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5691C4u, ctx.xmm[0].u32[0]);
	// 0x276D60: ret
	return;
}

void sub_276D70(X86Context& ctx, uint8_t* base) {
	// 0x276D70: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x276D78: movss [0x0056921C], xmm0
	X86_MEM_WRITE_u32(base, 0x56921Cu, ctx.xmm[0].u32[0]);
	// 0x276D80: ret
	return;
}

void sub_276D90(X86Context& ctx, uint8_t* base) {
	// 0x276D90: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x276D98: movss [0x00569200], xmm0
	X86_MEM_WRITE_u32(base, 0x569200u, ctx.xmm[0].u32[0]);
	// 0x276DA0: ret
	return;
}

void sub_276DB0(X86Context& ctx, uint8_t* base) {
	// 0x276DB0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x276DB8: movss [0x005691A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5691A8u, ctx.xmm[0].u32[0]);
	// 0x276DC0: ret
	return;
}

void sub_276DD0(X86Context& ctx, uint8_t* base) {
	// 0x276DD0: movss xmm0, dword ptr [0x005691C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691C4u);
	// 0x276DD8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276DE0: movss [0x0056919C], xmm0
	X86_MEM_WRITE_u32(base, 0x56919Cu, ctx.xmm[0].u32[0]);
	// 0x276DE8: ret
	return;
}

void sub_276DF0(X86Context& ctx, uint8_t* base) {
	// 0x276DF0: movss xmm0, dword ptr [0x0056921C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56921Cu);
	// 0x276DF8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x276E00: movss [0x005691E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5691E4u, ctx.xmm[0].u32[0]);
	// 0x276E08: ret
	return;
}

void sub_276E10(X86Context& ctx, uint8_t* base) {
	// 0x276E10: movss xmm0, dword ptr [0x0056919C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56919Cu);
	// 0x276E18: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x276E20: movss [0x005691F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5691F8u, ctx.xmm[0].u32[0]);
	// 0x276E28: ret
	return;
}

void sub_276E30(X86Context& ctx, uint8_t* base) {
	// 0x276E30: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x276E38: movss [0x00569194], xmm0
	X86_MEM_WRITE_u32(base, 0x569194u, ctx.xmm[0].u32[0]);
	// 0x276E40: ret
	return;
}

void sub_276E50(X86Context& ctx, uint8_t* base) {
	// 0x276E50: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x276E58: movss [0x005691C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5691C8u, ctx.xmm[0].u32[0]);
	// 0x276E60: ret
	return;
}

void sub_276E70(X86Context& ctx, uint8_t* base) {
	// 0x276E70: movss xmm0, dword ptr [0x005691C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691C4u);
	// 0x276E78: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x276E80: movss [0x005691D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5691D4u, ctx.xmm[0].u32[0]);
	// 0x276E88: ret
	return;
}

void sub_276E90(X86Context& ctx, uint8_t* base) {
	// 0x276E90: movss xmm0, dword ptr [0x0056921C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56921Cu);
	// 0x276E98: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x276EA0: movss [0x00569220], xmm0
	X86_MEM_WRITE_u32(base, 0x569220u, ctx.xmm[0].u32[0]);
	// 0x276EA8: ret
	return;
}

void sub_276EB0(X86Context& ctx, uint8_t* base) {
	// 0x276EB0: movss xmm0, dword ptr [0x005691D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691D4u);
	// 0x276EB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276EC0: movss [0x0056920C], xmm0
	X86_MEM_WRITE_u32(base, 0x56920Cu, ctx.xmm[0].u32[0]);
	// 0x276EC8: ret
	return;
}

void sub_276ED0(X86Context& ctx, uint8_t* base) {
	// 0x276ED0: movss xmm0, dword ptr [0x00569220]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569220u);
	// 0x276ED8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276EE0: movss [0x00569230], xmm0
	X86_MEM_WRITE_u32(base, 0x569230u, ctx.xmm[0].u32[0]);
	// 0x276EE8: ret
	return;
}

void sub_276EF0(X86Context& ctx, uint8_t* base) {
	// 0x276EF0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x276EF8: movss [0x005691A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5691A0u, ctx.xmm[0].u32[0]);
	// 0x276F00: ret
	return;
}

void sub_276F10(X86Context& ctx, uint8_t* base) {
	// 0x276F10: movss xmm0, dword ptr [0x005691C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691C4u);
	// 0x276F18: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276F20: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x276F28: movss [0x00569218], xmm0
	X86_MEM_WRITE_u32(base, 0x569218u, ctx.xmm[0].u32[0]);
	// 0x276F30: ret
	return;
}

void sub_276F40(X86Context& ctx, uint8_t* base) {
	// 0x276F40: movss xmm0, dword ptr [0x0056921C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56921Cu);
	// 0x276F48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276F50: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x276F58: movss [0x005691B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5691B8u, ctx.xmm[0].u32[0]);
	// 0x276F60: ret
	return;
}

void sub_276F70(X86Context& ctx, uint8_t* base) {
	// 0x276F70: movss xmm0, dword ptr [0x005691C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691C4u);
	// 0x276F78: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276F80: movss [0x005691BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5691BCu, ctx.xmm[0].u32[0]);
	// 0x276F88: ret
	return;
}

void sub_276F90(X86Context& ctx, uint8_t* base) {
	// 0x276F90: movss xmm0, dword ptr [0x0056921C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56921Cu);
	// 0x276F98: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x276FA0: movss [0x00569224], xmm0
	X86_MEM_WRITE_u32(base, 0x569224u, ctx.xmm[0].u32[0]);
	// 0x276FA8: ret
	return;
}

void sub_276FB0(X86Context& ctx, uint8_t* base) {
	// 0x276FB0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x276FB8: movss [0x005691A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5691A4u, ctx.xmm[0].u32[0]);
	// 0x276FC0: ret
	return;
}

void sub_276FD0(X86Context& ctx, uint8_t* base) {
	// 0x276FD0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x276FD8: movss [0x005691D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5691D0u, ctx.xmm[0].u32[0]);
	// 0x276FE0: ret
	return;
}

void sub_276FF0(X86Context& ctx, uint8_t* base) {
	// 0x276FF0: movss xmm0, dword ptr [0x005691A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691A4u);
	// 0x276FF8: movss [0x00569238], xmm0
	X86_MEM_WRITE_u32(base, 0x569238u, ctx.xmm[0].u32[0]);
	// 0x277000: ret
	return;
}

void sub_277010(X86Context& ctx, uint8_t* base) {
	// 0x277010: movss xmm0, dword ptr [0x0056921C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56921Cu);
	// 0x277018: subss xmm0, [0x005691A4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5691A4u);
	// 0x277020: movss [0x005691FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5691FCu, ctx.xmm[0].u32[0]);
	// 0x277028: ret
	return;
}

void sub_277030(X86Context& ctx, uint8_t* base) {
	// 0x277030: movss xmm0, dword ptr [0x005691FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691FCu);
	// 0x277038: subss xmm0, [0x005691D0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5691D0u);
	// 0x277040: movss [0x005691F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5691F4u, ctx.xmm[0].u32[0]);
	// 0x277048: ret
	return;
}

void sub_277050(X86Context& ctx, uint8_t* base) {
	// 0x277050: movss xmm0, dword ptr [0x00569224]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569224u);
	// 0x277058: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x277060: movss [0x005691E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5691E0u, ctx.xmm[0].u32[0]);
	// 0x277068: ret
	return;
}

void sub_277070(X86Context& ctx, uint8_t* base) {
	// 0x277070: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x277078: movss [0x005691CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5691CCu, ctx.xmm[0].u32[0]);
	// 0x277080: ret
	return;
}

void sub_277090(X86Context& ctx, uint8_t* base) {
	// 0x277090: movss xmm0, dword ptr [0x005691E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5691E0u);
	// 0x277098: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2770A0: movss [0x00569214], xmm0
	X86_MEM_WRITE_u32(base, 0x569214u, ctx.xmm[0].u32[0]);
	// 0x2770A8: ret
	return;
}

void sub_2770B0(X86Context& ctx, uint8_t* base) {
	// 0x2770B0: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x2770B8: movss [0x005691E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5691E8u, ctx.xmm[0].u32[0]);
	// 0x2770C0: ret
	return;
}

void sub_2770D0(X86Context& ctx, uint8_t* base) {
	// 0x2770D0: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x2770D8: movss [0x005691C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5691C0u, ctx.xmm[0].u32[0]);
	// 0x2770E0: ret
	return;
}

void sub_2770F0(X86Context& ctx, uint8_t* base) {
	// 0x2770F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2770F8: movss [0x005692A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5692A0u, ctx.xmm[0].u32[0]);
	// 0x277100: ret
	return;
}

void sub_277110(X86Context& ctx, uint8_t* base) {
	// 0x277110: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x277118: movss [0x005692BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5692BCu, ctx.xmm[0].u32[0]);
	// 0x277120: ret
	return;
}

void sub_277130(X86Context& ctx, uint8_t* base) {
	// 0x277130: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x277138: movss [0x00569290], xmm0
	X86_MEM_WRITE_u32(base, 0x569290u, ctx.xmm[0].u32[0]);
	// 0x277140: ret
	return;
}

void sub_277150(X86Context& ctx, uint8_t* base) {
	// 0x277150: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x277158: movss [0x00569244], xmm0
	X86_MEM_WRITE_u32(base, 0x569244u, ctx.xmm[0].u32[0]);
	// 0x277160: ret
	return;
}

void sub_277170(X86Context& ctx, uint8_t* base) {
	// 0x277170: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x277178: movss [0x005692A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5692A4u, ctx.xmm[0].u32[0]);
	// 0x277180: ret
	return;
}

void sub_277190(X86Context& ctx, uint8_t* base) {
	// 0x277190: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x277198: movss [0x00569260], xmm0
	X86_MEM_WRITE_u32(base, 0x569260u, ctx.xmm[0].u32[0]);
	// 0x2771A0: ret
	return;
}

void sub_2771B0(X86Context& ctx, uint8_t* base) {
	// 0x2771B0: movss xmm0, dword ptr [0x005692A4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5692A4u);
	// 0x2771B8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2771C0: movss [0x005692DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5692DCu, ctx.xmm[0].u32[0]);
	// 0x2771C8: ret
	return;
}

void sub_2771D0(X86Context& ctx, uint8_t* base) {
	// 0x2771D0: movss xmm0, dword ptr [0x00569260]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569260u);
	// 0x2771D8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2771E0: movss [0x005692C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5692C4u, ctx.xmm[0].u32[0]);
	// 0x2771E8: ret
	return;
}

void sub_2771F0(X86Context& ctx, uint8_t* base) {
	// 0x2771F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2771F8: movss [0x005692F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5692F4u, ctx.xmm[0].u32[0]);
	// 0x277200: ret
	return;
}

void sub_277210(X86Context& ctx, uint8_t* base) {
	// 0x277210: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x277218: movss [0x005692E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5692E0u, ctx.xmm[0].u32[0]);
	// 0x277220: ret
	return;
}

void sub_277230(X86Context& ctx, uint8_t* base) {
	// 0x277230: movss xmm0, dword ptr [0x005692E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5692E0u);
	// 0x277238: movss [0x005692F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5692F0u, ctx.xmm[0].u32[0]);
	// 0x277240: ret
	return;
}

void sub_277250(X86Context& ctx, uint8_t* base) {
	// 0x277250: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x277258: movss [0x0056924C], xmm0
	X86_MEM_WRITE_u32(base, 0x56924Cu, ctx.xmm[0].u32[0]);
	// 0x277260: ret
	return;
}

void sub_277270(X86Context& ctx, uint8_t* base) {
	// 0x277270: movss xmm0, dword ptr [0x00569260]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569260u);
	// 0x277278: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x277280: movss [0x005692E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5692E8u, ctx.xmm[0].u32[0]);
	// 0x277288: ret
	return;
}

void sub_277290(X86Context& ctx, uint8_t* base) {
	// 0x277290: movss xmm0, dword ptr [0x00569260]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569260u);
	// 0x277298: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2772A0: movss [0x0056928C], xmm0
	X86_MEM_WRITE_u32(base, 0x56928Cu, ctx.xmm[0].u32[0]);
	// 0x2772A8: ret
	return;
}

void sub_2772B0(X86Context& ctx, uint8_t* base) {
	// 0x2772B0: movss xmm0, dword ptr [0x00569260]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569260u);
	// 0x2772B8: subss xmm0, [0x0056928C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56928Cu);
	// 0x2772C0: movss [0x00569268], xmm0
	X86_MEM_WRITE_u32(base, 0x569268u, ctx.xmm[0].u32[0]);
	// 0x2772C8: ret
	return;
}

void sub_2772D0(X86Context& ctx, uint8_t* base) {
	// 0x2772D0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2772D8: movss [0x005692B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5692B8u, ctx.xmm[0].u32[0]);
	// 0x2772E0: ret
	return;
}

void sub_2772F0(X86Context& ctx, uint8_t* base) {
	// 0x2772F0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2772F8: movss [0x00569264], xmm0
	X86_MEM_WRITE_u32(base, 0x569264u, ctx.xmm[0].u32[0]);
	// 0x277300: ret
	return;
}

void sub_277310(X86Context& ctx, uint8_t* base) {
	// 0x277310: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x277318: movss [0x00569278], xmm0
	X86_MEM_WRITE_u32(base, 0x569278u, ctx.xmm[0].u32[0]);
	// 0x277320: ret
	return;
}

void sub_277330(X86Context& ctx, uint8_t* base) {
	// 0x277330: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x277338: movss [0x005692D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5692D0u, ctx.xmm[0].u32[0]);
	// 0x277340: ret
	return;
}

void sub_277350(X86Context& ctx, uint8_t* base) {
	// 0x277350: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x277358: movss [0x005692B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5692B4u, ctx.xmm[0].u32[0]);
	// 0x277360: ret
	return;
}

void sub_277370(X86Context& ctx, uint8_t* base) {
	// 0x277370: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x277378: movss [0x0056925C], xmm0
	X86_MEM_WRITE_u32(base, 0x56925Cu, ctx.xmm[0].u32[0]);
	// 0x277380: ret
	return;
}

void sub_277390(X86Context& ctx, uint8_t* base) {
	// 0x277390: movss xmm0, dword ptr [0x00569278]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x569278u);
	// 0x277398: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2773A0: movss [0x00569250], xmm0
	X86_MEM_WRITE_u32(base, 0x569250u, ctx.xmm[0].u32[0]);
	// 0x2773A8: ret
	return;
}

void sub_2773B0(X86Context& ctx, uint8_t* base) {
	// 0x2773B0: movss xmm0, dword ptr [0x005692D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5692D0u);
	// 0x2773B8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2773C0: movss [0x00569298], xmm0
	X86_MEM_WRITE_u32(base, 0x569298u, ctx.xmm[0].u32[0]);
	// 0x2773C8: ret
	return;
}

