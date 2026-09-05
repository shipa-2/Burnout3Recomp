#include "x86_recomp_shared.h"

void sub_29A0A0(X86Context& ctx, uint8_t* base) {
	// 0x29A0A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29A0A8: movss [0x0056EDBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDBCu, ctx.xmm[0].u32[0]);
	// 0x29A0B0: ret
	return;
}

void sub_29A0C0(X86Context& ctx, uint8_t* base) {
	// 0x29A0C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29A0C8: movss [0x0056ED80], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED80u, ctx.xmm[0].u32[0]);
	// 0x29A0D0: ret
	return;
}

void sub_29A0E0(X86Context& ctx, uint8_t* base) {
	// 0x29A0E0: movss xmm0, dword ptr [0x0056EDBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDBCu);
	// 0x29A0E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29A0F0: movss [0x0056EDF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDF4u, ctx.xmm[0].u32[0]);
	// 0x29A0F8: ret
	return;
}

void sub_29A100(X86Context& ctx, uint8_t* base) {
	// 0x29A100: movss xmm0, dword ptr [0x0056ED80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED80u);
	// 0x29A108: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29A110: movss [0x0056EDDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDDCu, ctx.xmm[0].u32[0]);
	// 0x29A118: ret
	return;
}

void sub_29A120(X86Context& ctx, uint8_t* base) {
	// 0x29A120: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29A128: movss [0x0056EE0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE0Cu, ctx.xmm[0].u32[0]);
	// 0x29A130: ret
	return;
}

void sub_29A140(X86Context& ctx, uint8_t* base) {
	// 0x29A140: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29A148: movss [0x0056EDF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDF8u, ctx.xmm[0].u32[0]);
	// 0x29A150: ret
	return;
}

void sub_29A160(X86Context& ctx, uint8_t* base) {
	// 0x29A160: movss xmm0, dword ptr [0x0056EDF8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDF8u);
	// 0x29A168: movss [0x0056EE08], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE08u, ctx.xmm[0].u32[0]);
	// 0x29A170: ret
	return;
}

void sub_29A180(X86Context& ctx, uint8_t* base) {
	// 0x29A180: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29A188: movss [0x0056ED6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED6Cu, ctx.xmm[0].u32[0]);
	// 0x29A190: ret
	return;
}

void sub_29A1A0(X86Context& ctx, uint8_t* base) {
	// 0x29A1A0: movss xmm0, dword ptr [0x0056ED80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED80u);
	// 0x29A1A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29A1B0: movss [0x0056EE00], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE00u, ctx.xmm[0].u32[0]);
	// 0x29A1B8: ret
	return;
}

void sub_29A1C0(X86Context& ctx, uint8_t* base) {
	// 0x29A1C0: movss xmm0, dword ptr [0x0056ED80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED80u);
	// 0x29A1C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29A1D0: movss [0x0056EDA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDA8u, ctx.xmm[0].u32[0]);
	// 0x29A1D8: ret
	return;
}

void sub_29A1E0(X86Context& ctx, uint8_t* base) {
	// 0x29A1E0: movss xmm0, dword ptr [0x0056ED80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED80u);
	// 0x29A1E8: subss xmm0, [0x0056EDA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EDA8u);
	// 0x29A1F0: movss [0x0056ED88], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED88u, ctx.xmm[0].u32[0]);
	// 0x29A1F8: ret
	return;
}

void sub_29A200(X86Context& ctx, uint8_t* base) {
	// 0x29A200: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29A208: movss [0x0056EDD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDD0u, ctx.xmm[0].u32[0]);
	// 0x29A210: ret
	return;
}

void sub_29A220(X86Context& ctx, uint8_t* base) {
	// 0x29A220: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29A228: movss [0x0056ED84], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED84u, ctx.xmm[0].u32[0]);
	// 0x29A230: ret
	return;
}

void sub_29A240(X86Context& ctx, uint8_t* base) {
	// 0x29A240: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29A248: movss [0x0056ED94], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED94u, ctx.xmm[0].u32[0]);
	// 0x29A250: ret
	return;
}

void sub_29A260(X86Context& ctx, uint8_t* base) {
	// 0x29A260: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29A268: movss [0x0056EDE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDE8u, ctx.xmm[0].u32[0]);
	// 0x29A270: ret
	return;
}

void sub_29A280(X86Context& ctx, uint8_t* base) {
	// 0x29A280: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29A288: movss [0x0056EDCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDCCu, ctx.xmm[0].u32[0]);
	// 0x29A290: ret
	return;
}

void sub_29A2A0(X86Context& ctx, uint8_t* base) {
	// 0x29A2A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29A2A8: movss [0x0056ED7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED7Cu, ctx.xmm[0].u32[0]);
	// 0x29A2B0: ret
	return;
}

void sub_29A2C0(X86Context& ctx, uint8_t* base) {
	// 0x29A2C0: movss xmm0, dword ptr [0x0056ED94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED94u);
	// 0x29A2C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29A2D0: movss [0x0056ED70], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED70u, ctx.xmm[0].u32[0]);
	// 0x29A2D8: ret
	return;
}

void sub_29A2E0(X86Context& ctx, uint8_t* base) {
	// 0x29A2E0: movss xmm0, dword ptr [0x0056EDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDE8u);
	// 0x29A2E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29A2F0: movss [0x0056EDB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDB4u, ctx.xmm[0].u32[0]);
	// 0x29A2F8: ret
	return;
}

void sub_29A300(X86Context& ctx, uint8_t* base) {
	// 0x29A300: movss xmm0, dword ptr [0x0056ED70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED70u);
	// 0x29A308: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29A310: movss [0x0056EDC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDC4u, ctx.xmm[0].u32[0]);
	// 0x29A318: ret
	return;
}

void sub_29A320(X86Context& ctx, uint8_t* base) {
	// 0x29A320: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29A328: movss [0x0056ED68], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED68u, ctx.xmm[0].u32[0]);
	// 0x29A330: ret
	return;
}

void sub_29A340(X86Context& ctx, uint8_t* base) {
	// 0x29A340: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29A348: movss [0x0056ED98], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED98u, ctx.xmm[0].u32[0]);
	// 0x29A350: ret
	return;
}

void sub_29A360(X86Context& ctx, uint8_t* base) {
	// 0x29A360: movss xmm0, dword ptr [0x0056ED94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED94u);
	// 0x29A368: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29A370: movss [0x0056EDA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDA4u, ctx.xmm[0].u32[0]);
	// 0x29A378: ret
	return;
}

void sub_29A380(X86Context& ctx, uint8_t* base) {
	// 0x29A380: movss xmm0, dword ptr [0x0056EDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDE8u);
	// 0x29A388: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29A390: movss [0x0056EDEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDECu, ctx.xmm[0].u32[0]);
	// 0x29A398: ret
	return;
}

void sub_29A3A0(X86Context& ctx, uint8_t* base) {
	// 0x29A3A0: movss xmm0, dword ptr [0x0056EDA4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDA4u);
	// 0x29A3A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A3B0: movss [0x0056EDD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDD8u, ctx.xmm[0].u32[0]);
	// 0x29A3B8: ret
	return;
}

void sub_29A3C0(X86Context& ctx, uint8_t* base) {
	// 0x29A3C0: movss xmm0, dword ptr [0x0056EDEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDECu);
	// 0x29A3C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A3D0: movss [0x0056EDFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDFCu, ctx.xmm[0].u32[0]);
	// 0x29A3D8: ret
	return;
}

void sub_29A3E0(X86Context& ctx, uint8_t* base) {
	// 0x29A3E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29A3E8: movss [0x0056ED74], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED74u, ctx.xmm[0].u32[0]);
	// 0x29A3F0: ret
	return;
}

void sub_29A400(X86Context& ctx, uint8_t* base) {
	// 0x29A400: movss xmm0, dword ptr [0x0056ED94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED94u);
	// 0x29A408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A410: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29A418: movss [0x0056EDE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDE4u, ctx.xmm[0].u32[0]);
	// 0x29A420: ret
	return;
}

void sub_29A430(X86Context& ctx, uint8_t* base) {
	// 0x29A430: movss xmm0, dword ptr [0x0056EDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDE8u);
	// 0x29A438: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A440: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29A448: movss [0x0056ED8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED8Cu, ctx.xmm[0].u32[0]);
	// 0x29A450: ret
	return;
}

void sub_29A460(X86Context& ctx, uint8_t* base) {
	// 0x29A460: movss xmm0, dword ptr [0x0056ED94]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED94u);
	// 0x29A468: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A470: movss [0x0056ED90], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED90u, ctx.xmm[0].u32[0]);
	// 0x29A478: ret
	return;
}

void sub_29A480(X86Context& ctx, uint8_t* base) {
	// 0x29A480: movss xmm0, dword ptr [0x0056EDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDE8u);
	// 0x29A488: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A490: movss [0x0056EDF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDF0u, ctx.xmm[0].u32[0]);
	// 0x29A498: ret
	return;
}

void sub_29A4A0(X86Context& ctx, uint8_t* base) {
	// 0x29A4A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29A4A8: movss [0x0056ED78], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED78u, ctx.xmm[0].u32[0]);
	// 0x29A4B0: ret
	return;
}

void sub_29A4C0(X86Context& ctx, uint8_t* base) {
	// 0x29A4C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29A4C8: movss [0x0056EDA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDA0u, ctx.xmm[0].u32[0]);
	// 0x29A4D0: ret
	return;
}

void sub_29A4E0(X86Context& ctx, uint8_t* base) {
	// 0x29A4E0: movss xmm0, dword ptr [0x0056ED78]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56ED78u);
	// 0x29A4E8: movss [0x0056EE04], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE04u, ctx.xmm[0].u32[0]);
	// 0x29A4F0: ret
	return;
}

void sub_29A500(X86Context& ctx, uint8_t* base) {
	// 0x29A500: movss xmm0, dword ptr [0x0056EDE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDE8u);
	// 0x29A508: subss xmm0, [0x0056ED78]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56ED78u);
	// 0x29A510: movss [0x0056EDC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDC8u, ctx.xmm[0].u32[0]);
	// 0x29A518: ret
	return;
}

void sub_29A520(X86Context& ctx, uint8_t* base) {
	// 0x29A520: movss xmm0, dword ptr [0x0056EDC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDC8u);
	// 0x29A528: subss xmm0, [0x0056EDA0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EDA0u);
	// 0x29A530: movss [0x0056EDC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDC0u, ctx.xmm[0].u32[0]);
	// 0x29A538: ret
	return;
}

void sub_29A540(X86Context& ctx, uint8_t* base) {
	// 0x29A540: movss xmm0, dword ptr [0x0056EDF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDF0u);
	// 0x29A548: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29A550: movss [0x0056EDB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDB0u, ctx.xmm[0].u32[0]);
	// 0x29A558: ret
	return;
}

void sub_29A560(X86Context& ctx, uint8_t* base) {
	// 0x29A560: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29A568: movss [0x0056ED9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56ED9Cu, ctx.xmm[0].u32[0]);
	// 0x29A570: ret
	return;
}

void sub_29A580(X86Context& ctx, uint8_t* base) {
	// 0x29A580: movss xmm0, dword ptr [0x0056EDB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EDB0u);
	// 0x29A588: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29A590: movss [0x0056EDE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EDE0u, ctx.xmm[0].u32[0]);
	// 0x29A598: ret
	return;
}

void sub_29A5A0(X86Context& ctx, uint8_t* base) {
	// 0x29A5A0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29A5A8: movss [0x0056EE78], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE78u, ctx.xmm[0].u32[0]);
	// 0x29A5B0: ret
	return;
}

void sub_29A5C0(X86Context& ctx, uint8_t* base) {
	// 0x29A5C0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29A5C8: movss [0x0056EE94], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE94u, ctx.xmm[0].u32[0]);
	// 0x29A5D0: ret
	return;
}

void sub_29A5E0(X86Context& ctx, uint8_t* base) {
	// 0x29A5E0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29A5E8: movss [0x0056EE6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE6Cu, ctx.xmm[0].u32[0]);
	// 0x29A5F0: ret
	return;
}

void sub_29A600(X86Context& ctx, uint8_t* base) {
	// 0x29A600: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29A608: movss [0x0056EE10], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE10u, ctx.xmm[0].u32[0]);
	// 0x29A610: ret
	return;
}

void sub_29A620(X86Context& ctx, uint8_t* base) {
	// 0x29A620: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29A628: movss [0x0056EE7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE7Cu, ctx.xmm[0].u32[0]);
	// 0x29A630: ret
	return;
}

void sub_29A640(X86Context& ctx, uint8_t* base) {
	// 0x29A640: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29A648: movss [0x0056EE3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE3Cu, ctx.xmm[0].u32[0]);
	// 0x29A650: ret
	return;
}

void sub_29A660(X86Context& ctx, uint8_t* base) {
	// 0x29A660: movss xmm0, dword ptr [0x0056EE7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE7Cu);
	// 0x29A668: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29A670: movss [0x0056EEB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEB4u, ctx.xmm[0].u32[0]);
	// 0x29A678: ret
	return;
}

void sub_29A680(X86Context& ctx, uint8_t* base) {
	// 0x29A680: movss xmm0, dword ptr [0x0056EE3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE3Cu);
	// 0x29A688: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29A690: movss [0x0056EE9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE9Cu, ctx.xmm[0].u32[0]);
	// 0x29A698: ret
	return;
}

void sub_29A6A0(X86Context& ctx, uint8_t* base) {
	// 0x29A6A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29A6A8: movss [0x0056EECC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EECCu, ctx.xmm[0].u32[0]);
	// 0x29A6B0: ret
	return;
}

void sub_29A6C0(X86Context& ctx, uint8_t* base) {
	// 0x29A6C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29A6C8: movss [0x0056EEB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEB8u, ctx.xmm[0].u32[0]);
	// 0x29A6D0: ret
	return;
}

void sub_29A6E0(X86Context& ctx, uint8_t* base) {
	// 0x29A6E0: movss xmm0, dword ptr [0x0056EEB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEB8u);
	// 0x29A6E8: movss [0x0056EEC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEC8u, ctx.xmm[0].u32[0]);
	// 0x29A6F0: ret
	return;
}

void sub_29A700(X86Context& ctx, uint8_t* base) {
	// 0x29A700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29A708: movss [0x0056EE28], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE28u, ctx.xmm[0].u32[0]);
	// 0x29A710: ret
	return;
}

void sub_29A720(X86Context& ctx, uint8_t* base) {
	// 0x29A720: movss xmm0, dword ptr [0x0056EE3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE3Cu);
	// 0x29A728: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29A730: movss [0x0056EEC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEC0u, ctx.xmm[0].u32[0]);
	// 0x29A738: ret
	return;
}

void sub_29A740(X86Context& ctx, uint8_t* base) {
	// 0x29A740: movss xmm0, dword ptr [0x0056EE3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE3Cu);
	// 0x29A748: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29A750: movss [0x0056EE68], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE68u, ctx.xmm[0].u32[0]);
	// 0x29A758: ret
	return;
}

void sub_29A760(X86Context& ctx, uint8_t* base) {
	// 0x29A760: movss xmm0, dword ptr [0x0056EE3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE3Cu);
	// 0x29A768: subss xmm0, [0x0056EE68]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EE68u);
	// 0x29A770: movss [0x0056EE48], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE48u, ctx.xmm[0].u32[0]);
	// 0x29A778: ret
	return;
}

void sub_29A780(X86Context& ctx, uint8_t* base) {
	// 0x29A780: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29A788: movss [0x0056EE90], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE90u, ctx.xmm[0].u32[0]);
	// 0x29A790: ret
	return;
}

void sub_29A7A0(X86Context& ctx, uint8_t* base) {
	// 0x29A7A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29A7A8: movss [0x0056EE40], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE40u, ctx.xmm[0].u32[0]);
	// 0x29A7B0: ret
	return;
}

void sub_29A7C0(X86Context& ctx, uint8_t* base) {
	// 0x29A7C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29A7C8: movss [0x0056EE54], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE54u, ctx.xmm[0].u32[0]);
	// 0x29A7D0: ret
	return;
}

void sub_29A7E0(X86Context& ctx, uint8_t* base) {
	// 0x29A7E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29A7E8: movss [0x0056EEA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEA8u, ctx.xmm[0].u32[0]);
	// 0x29A7F0: ret
	return;
}

void sub_29A800(X86Context& ctx, uint8_t* base) {
	// 0x29A800: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29A808: movss [0x0056EE8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE8Cu, ctx.xmm[0].u32[0]);
	// 0x29A810: ret
	return;
}

void sub_29A820(X86Context& ctx, uint8_t* base) {
	// 0x29A820: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29A828: movss [0x0056EE38], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE38u, ctx.xmm[0].u32[0]);
	// 0x29A830: ret
	return;
}

void sub_29A840(X86Context& ctx, uint8_t* base) {
	// 0x29A840: movss xmm0, dword ptr [0x0056EE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE54u);
	// 0x29A848: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29A850: movss [0x0056EE2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE2Cu, ctx.xmm[0].u32[0]);
	// 0x29A858: ret
	return;
}

void sub_29A860(X86Context& ctx, uint8_t* base) {
	// 0x29A860: movss xmm0, dword ptr [0x0056EEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEA8u);
	// 0x29A868: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29A870: movss [0x0056EE74], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE74u, ctx.xmm[0].u32[0]);
	// 0x29A878: ret
	return;
}

void sub_29A880(X86Context& ctx, uint8_t* base) {
	// 0x29A880: movss xmm0, dword ptr [0x0056EE2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE2Cu);
	// 0x29A888: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29A890: movss [0x0056EE84], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE84u, ctx.xmm[0].u32[0]);
	// 0x29A898: ret
	return;
}

void sub_29A8A0(X86Context& ctx, uint8_t* base) {
	// 0x29A8A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29A8A8: movss [0x0056EE20], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE20u, ctx.xmm[0].u32[0]);
	// 0x29A8B0: ret
	return;
}

void sub_29A8C0(X86Context& ctx, uint8_t* base) {
	// 0x29A8C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29A8C8: movss [0x0056EE58], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE58u, ctx.xmm[0].u32[0]);
	// 0x29A8D0: ret
	return;
}

void sub_29A8E0(X86Context& ctx, uint8_t* base) {
	// 0x29A8E0: movss xmm0, dword ptr [0x0056EE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE54u);
	// 0x29A8E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29A8F0: movss [0x0056EE64], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE64u, ctx.xmm[0].u32[0]);
	// 0x29A8F8: ret
	return;
}

void sub_29A900(X86Context& ctx, uint8_t* base) {
	// 0x29A900: movss xmm0, dword ptr [0x0056EEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEA8u);
	// 0x29A908: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29A910: movss [0x0056EEAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEACu, ctx.xmm[0].u32[0]);
	// 0x29A918: ret
	return;
}

void sub_29A920(X86Context& ctx, uint8_t* base) {
	// 0x29A920: movss xmm0, dword ptr [0x0056EE64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE64u);
	// 0x29A928: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A930: movss [0x0056EE98], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE98u, ctx.xmm[0].u32[0]);
	// 0x29A938: ret
	return;
}

void sub_29A940(X86Context& ctx, uint8_t* base) {
	// 0x29A940: movss xmm0, dword ptr [0x0056EEAC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEACu);
	// 0x29A948: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A950: movss [0x0056EEBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEBCu, ctx.xmm[0].u32[0]);
	// 0x29A958: ret
	return;
}

void sub_29A960(X86Context& ctx, uint8_t* base) {
	// 0x29A960: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29A968: movss [0x0056EE30], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE30u, ctx.xmm[0].u32[0]);
	// 0x29A970: ret
	return;
}

void sub_29A980(X86Context& ctx, uint8_t* base) {
	// 0x29A980: movss xmm0, dword ptr [0x0056EE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE54u);
	// 0x29A988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A990: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29A998: movss [0x0056EEA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEA4u, ctx.xmm[0].u32[0]);
	// 0x29A9A0: ret
	return;
}

void sub_29A9B0(X86Context& ctx, uint8_t* base) {
	// 0x29A9B0: movss xmm0, dword ptr [0x0056EEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEA8u);
	// 0x29A9B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A9C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29A9C8: movss [0x0056EE4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE4Cu, ctx.xmm[0].u32[0]);
	// 0x29A9D0: ret
	return;
}

void sub_29A9E0(X86Context& ctx, uint8_t* base) {
	// 0x29A9E0: movss xmm0, dword ptr [0x0056EE54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE54u);
	// 0x29A9E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29A9F0: movss [0x0056EE50], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE50u, ctx.xmm[0].u32[0]);
	// 0x29A9F8: ret
	return;
}

void sub_29AA00(X86Context& ctx, uint8_t* base) {
	// 0x29AA00: movss xmm0, dword ptr [0x0056EEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEA8u);
	// 0x29AA08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29AA10: movss [0x0056EEB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEB0u, ctx.xmm[0].u32[0]);
	// 0x29AA18: ret
	return;
}

void sub_29AA20(X86Context& ctx, uint8_t* base) {
	// 0x29AA20: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29AA28: movss [0x0056EE34], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE34u, ctx.xmm[0].u32[0]);
	// 0x29AA30: ret
	return;
}

void sub_29AA40(X86Context& ctx, uint8_t* base) {
	// 0x29AA40: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29AA48: movss [0x0056EE60], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE60u, ctx.xmm[0].u32[0]);
	// 0x29AA50: ret
	return;
}

void sub_29AA60(X86Context& ctx, uint8_t* base) {
	// 0x29AA60: movss xmm0, dword ptr [0x0056EE34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE34u);
	// 0x29AA68: movss [0x0056EEC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEC4u, ctx.xmm[0].u32[0]);
	// 0x29AA70: ret
	return;
}

void sub_29AA80(X86Context& ctx, uint8_t* base) {
	// 0x29AA80: movss xmm0, dword ptr [0x0056EEA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEA8u);
	// 0x29AA88: subss xmm0, [0x0056EE34]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EE34u);
	// 0x29AA90: movss [0x0056EE88], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE88u, ctx.xmm[0].u32[0]);
	// 0x29AA98: ret
	return;
}

void sub_29AAA0(X86Context& ctx, uint8_t* base) {
	// 0x29AAA0: movss xmm0, dword ptr [0x0056EE88]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE88u);
	// 0x29AAA8: subss xmm0, [0x0056EE60]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EE60u);
	// 0x29AAB0: movss [0x0056EE80], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE80u, ctx.xmm[0].u32[0]);
	// 0x29AAB8: ret
	return;
}

void sub_29AAC0(X86Context& ctx, uint8_t* base) {
	// 0x29AAC0: movss xmm0, dword ptr [0x0056EEB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEB0u);
	// 0x29AAC8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29AAD0: movss [0x0056EE70], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE70u, ctx.xmm[0].u32[0]);
	// 0x29AAD8: ret
	return;
}

void sub_29AAE0(X86Context& ctx, uint8_t* base) {
	// 0x29AAE0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29AAE8: movss [0x0056EE5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE5Cu, ctx.xmm[0].u32[0]);
	// 0x29AAF0: ret
	return;
}

void sub_29AB00(X86Context& ctx, uint8_t* base) {
	// 0x29AB00: movss xmm0, dword ptr [0x0056EE70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EE70u);
	// 0x29AB08: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29AB10: movss [0x0056EEA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEA0u, ctx.xmm[0].u32[0]);
	// 0x29AB18: ret
	return;
}

void sub_29AB20(X86Context& ctx, uint8_t* base) {
	// 0x29AB20: movss xmm0, dword ptr [0x003B2298]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2298u);
	// 0x29AB28: movss [0x0056EE24], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE24u, ctx.xmm[0].u32[0]);
	// 0x29AB30: ret
	return;
}

void sub_29AB40(X86Context& ctx, uint8_t* base) {
	// 0x29AB40: movss xmm0, dword ptr [0x004057B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4057B8u);
	// 0x29AB48: addss xmm0, [0x004057B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x4057B0u);
	// 0x29AB50: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x29AB58: movss [0x0056EE18], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE18u, ctx.xmm[0].u32[0]);
	// 0x29AB60: movss xmm0, dword ptr [0x004057B4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4057B4u);
	// 0x29AB68: movss [0x0056EE1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE1Cu, ctx.xmm[0].u32[0]);
	// 0x29AB70: ret
	return;
}

void sub_29AB80(X86Context& ctx, uint8_t* base) {
	// 0x29AB80: movss xmm0, dword ptr [0x004057BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4057BCu);
	// 0x29AB88: movss [0x0056EE44], xmm0
	X86_MEM_WRITE_u32(base, 0x56EE44u, ctx.xmm[0].u32[0]);
	// 0x29AB90: ret
	return;
}

void sub_29ABA0(X86Context& ctx, uint8_t* base) {
	// 0x29ABA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29ABA8: movss [0x0056EF3C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF3Cu, ctx.xmm[0].u32[0]);
	// 0x29ABB0: ret
	return;
}

void sub_29ABC0(X86Context& ctx, uint8_t* base) {
	// 0x29ABC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29ABC8: movss [0x0056EF58], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF58u, ctx.xmm[0].u32[0]);
	// 0x29ABD0: ret
	return;
}

void sub_29ABE0(X86Context& ctx, uint8_t* base) {
	// 0x29ABE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29ABE8: movss [0x0056EF2C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF2Cu, ctx.xmm[0].u32[0]);
	// 0x29ABF0: ret
	return;
}

void sub_29AC00(X86Context& ctx, uint8_t* base) {
	// 0x29AC00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29AC08: movss [0x0056EED0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EED0u, ctx.xmm[0].u32[0]);
	// 0x29AC10: ret
	return;
}

void sub_29AC20(X86Context& ctx, uint8_t* base) {
	// 0x29AC20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29AC28: movss [0x0056EF40], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF40u, ctx.xmm[0].u32[0]);
	// 0x29AC30: ret
	return;
}

void sub_29AC40(X86Context& ctx, uint8_t* base) {
	// 0x29AC40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29AC48: movss [0x0056EEEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEECu, ctx.xmm[0].u32[0]);
	// 0x29AC50: ret
	return;
}

void sub_29AC60(X86Context& ctx, uint8_t* base) {
	// 0x29AC60: movss xmm0, dword ptr [0x0056EF40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF40u);
	// 0x29AC68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29AC70: movss [0x0056EF78], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF78u, ctx.xmm[0].u32[0]);
	// 0x29AC78: ret
	return;
}

void sub_29AC80(X86Context& ctx, uint8_t* base) {
	// 0x29AC80: movss xmm0, dword ptr [0x0056EEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEECu);
	// 0x29AC88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29AC90: movss [0x0056EF60], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF60u, ctx.xmm[0].u32[0]);
	// 0x29AC98: ret
	return;
}

void sub_29ACA0(X86Context& ctx, uint8_t* base) {
	// 0x29ACA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29ACA8: movss [0x0056EF90], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF90u, ctx.xmm[0].u32[0]);
	// 0x29ACB0: ret
	return;
}

void sub_29ACC0(X86Context& ctx, uint8_t* base) {
	// 0x29ACC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29ACC8: movss [0x0056EF7C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF7Cu, ctx.xmm[0].u32[0]);
	// 0x29ACD0: ret
	return;
}

void sub_29ACE0(X86Context& ctx, uint8_t* base) {
	// 0x29ACE0: movss xmm0, dword ptr [0x0056EF7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF7Cu);
	// 0x29ACE8: movss [0x0056EF8C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF8Cu, ctx.xmm[0].u32[0]);
	// 0x29ACF0: ret
	return;
}

void sub_29AD00(X86Context& ctx, uint8_t* base) {
	// 0x29AD00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29AD08: movss [0x0056EED8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EED8u, ctx.xmm[0].u32[0]);
	// 0x29AD10: ret
	return;
}

void sub_29AD20(X86Context& ctx, uint8_t* base) {
	// 0x29AD20: movss xmm0, dword ptr [0x0056EEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEECu);
	// 0x29AD28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29AD30: movss [0x0056EF84], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF84u, ctx.xmm[0].u32[0]);
	// 0x29AD38: ret
	return;
}

void sub_29AD40(X86Context& ctx, uint8_t* base) {
	// 0x29AD40: movss xmm0, dword ptr [0x0056EEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEECu);
	// 0x29AD48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29AD50: movss [0x0056EF28], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF28u, ctx.xmm[0].u32[0]);
	// 0x29AD58: ret
	return;
}

void sub_29AD60(X86Context& ctx, uint8_t* base) {
	// 0x29AD60: movss xmm0, dword ptr [0x0056EEEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEECu);
	// 0x29AD68: subss xmm0, [0x0056EF28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EF28u);
	// 0x29AD70: movss [0x0056EF00], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF00u, ctx.xmm[0].u32[0]);
	// 0x29AD78: ret
	return;
}

void sub_29AD80(X86Context& ctx, uint8_t* base) {
	// 0x29AD80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29AD88: movss [0x0056EF54], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF54u, ctx.xmm[0].u32[0]);
	// 0x29AD90: ret
	return;
}

void sub_29ADA0(X86Context& ctx, uint8_t* base) {
	// 0x29ADA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29ADA8: movss [0x0056EEF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEF8u, ctx.xmm[0].u32[0]);
	// 0x29ADB0: ret
	return;
}

void sub_29ADC0(X86Context& ctx, uint8_t* base) {
	// 0x29ADC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29ADC8: movss [0x0056EF14], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF14u, ctx.xmm[0].u32[0]);
	// 0x29ADD0: ret
	return;
}

void sub_29ADE0(X86Context& ctx, uint8_t* base) {
	// 0x29ADE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29ADE8: movss [0x0056EF6C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF6Cu, ctx.xmm[0].u32[0]);
	// 0x29ADF0: ret
	return;
}

void sub_29AE00(X86Context& ctx, uint8_t* base) {
	// 0x29AE00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29AE08: movss [0x0056EF50], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF50u, ctx.xmm[0].u32[0]);
	// 0x29AE10: ret
	return;
}

void sub_29AE20(X86Context& ctx, uint8_t* base) {
	// 0x29AE20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29AE28: movss [0x0056EEE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEE8u, ctx.xmm[0].u32[0]);
	// 0x29AE30: ret
	return;
}

void sub_29AE40(X86Context& ctx, uint8_t* base) {
	// 0x29AE40: movss xmm0, dword ptr [0x0056EF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF14u);
	// 0x29AE48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29AE50: movss [0x0056EEDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEDCu, ctx.xmm[0].u32[0]);
	// 0x29AE58: ret
	return;
}

void sub_29AE60(X86Context& ctx, uint8_t* base) {
	// 0x29AE60: movss xmm0, dword ptr [0x0056EF6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF6Cu);
	// 0x29AE68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29AE70: movss [0x0056EF34], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF34u, ctx.xmm[0].u32[0]);
	// 0x29AE78: ret
	return;
}

void sub_29AE80(X86Context& ctx, uint8_t* base) {
	// 0x29AE80: movss xmm0, dword ptr [0x0056EEDC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEDCu);
	// 0x29AE88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29AE90: movss [0x0056EF48], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF48u, ctx.xmm[0].u32[0]);
	// 0x29AE98: ret
	return;
}

void sub_29AEA0(X86Context& ctx, uint8_t* base) {
	// 0x29AEA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29AEA8: movss [0x0056EED4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EED4u, ctx.xmm[0].u32[0]);
	// 0x29AEB0: ret
	return;
}

void sub_29AEC0(X86Context& ctx, uint8_t* base) {
	// 0x29AEC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29AEC8: movss [0x0056EF18], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF18u, ctx.xmm[0].u32[0]);
	// 0x29AED0: ret
	return;
}

void sub_29AEE0(X86Context& ctx, uint8_t* base) {
	// 0x29AEE0: movss xmm0, dword ptr [0x0056EF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF14u);
	// 0x29AEE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29AEF0: movss [0x0056EF24], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF24u, ctx.xmm[0].u32[0]);
	// 0x29AEF8: ret
	return;
}

void sub_29AF00(X86Context& ctx, uint8_t* base) {
	// 0x29AF00: movss xmm0, dword ptr [0x0056EF6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF6Cu);
	// 0x29AF08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29AF10: movss [0x0056EF70], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF70u, ctx.xmm[0].u32[0]);
	// 0x29AF18: ret
	return;
}

void sub_29AF20(X86Context& ctx, uint8_t* base) {
	// 0x29AF20: movss xmm0, dword ptr [0x0056EF24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF24u);
	// 0x29AF28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29AF30: movss [0x0056EF5C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF5Cu, ctx.xmm[0].u32[0]);
	// 0x29AF38: ret
	return;
}

void sub_29AF40(X86Context& ctx, uint8_t* base) {
	// 0x29AF40: movss xmm0, dword ptr [0x0056EF70]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF70u);
	// 0x29AF48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29AF50: movss [0x0056EF80], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF80u, ctx.xmm[0].u32[0]);
	// 0x29AF58: ret
	return;
}

void sub_29AF60(X86Context& ctx, uint8_t* base) {
	// 0x29AF60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29AF68: movss [0x0056EEE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEE0u, ctx.xmm[0].u32[0]);
	// 0x29AF70: ret
	return;
}

void sub_29AF80(X86Context& ctx, uint8_t* base) {
	// 0x29AF80: movss xmm0, dword ptr [0x0056EF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF14u);
	// 0x29AF88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29AF90: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29AF98: movss [0x0056EF68], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF68u, ctx.xmm[0].u32[0]);
	// 0x29AFA0: ret
	return;
}

void sub_29AFB0(X86Context& ctx, uint8_t* base) {
	// 0x29AFB0: movss xmm0, dword ptr [0x0056EF6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF6Cu);
	// 0x29AFB8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29AFC0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29AFC8: movss [0x0056EF04], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF04u, ctx.xmm[0].u32[0]);
	// 0x29AFD0: ret
	return;
}

void sub_29AFE0(X86Context& ctx, uint8_t* base) {
	// 0x29AFE0: movss xmm0, dword ptr [0x0056EF14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF14u);
	// 0x29AFE8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29AFF0: movss [0x0056EF08], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF08u, ctx.xmm[0].u32[0]);
	// 0x29AFF8: ret
	return;
}

void sub_29B000(X86Context& ctx, uint8_t* base) {
	// 0x29B000: movss xmm0, dword ptr [0x0056EF6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF6Cu);
	// 0x29B008: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B010: movss [0x0056EF74], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF74u, ctx.xmm[0].u32[0]);
	// 0x29B018: ret
	return;
}

void sub_29B020(X86Context& ctx, uint8_t* base) {
	// 0x29B020: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29B028: movss [0x0056EEE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEE4u, ctx.xmm[0].u32[0]);
	// 0x29B030: ret
	return;
}

void sub_29B040(X86Context& ctx, uint8_t* base) {
	// 0x29B040: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29B048: movss [0x0056EF20], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF20u, ctx.xmm[0].u32[0]);
	// 0x29B050: ret
	return;
}

void sub_29B060(X86Context& ctx, uint8_t* base) {
	// 0x29B060: movss xmm0, dword ptr [0x0056EEE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EEE4u);
	// 0x29B068: movss [0x0056EF88], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF88u, ctx.xmm[0].u32[0]);
	// 0x29B070: ret
	return;
}

void sub_29B080(X86Context& ctx, uint8_t* base) {
	// 0x29B080: movss xmm0, dword ptr [0x0056EF6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF6Cu);
	// 0x29B088: subss xmm0, [0x0056EEE4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EEE4u);
	// 0x29B090: movss [0x0056EF4C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF4Cu, ctx.xmm[0].u32[0]);
	// 0x29B098: ret
	return;
}

void sub_29B0A0(X86Context& ctx, uint8_t* base) {
	// 0x29B0A0: movss xmm0, dword ptr [0x0056EF4C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF4Cu);
	// 0x29B0A8: subss xmm0, [0x0056EF20]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EF20u);
	// 0x29B0B0: movss [0x0056EF44], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF44u, ctx.xmm[0].u32[0]);
	// 0x29B0B8: ret
	return;
}

void sub_29B0C0(X86Context& ctx, uint8_t* base) {
	// 0x29B0C0: movss xmm0, dword ptr [0x0056EF74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF74u);
	// 0x29B0C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29B0D0: movss [0x0056EF30], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF30u, ctx.xmm[0].u32[0]);
	// 0x29B0D8: ret
	return;
}

void sub_29B0E0(X86Context& ctx, uint8_t* base) {
	// 0x29B0E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29B0E8: movss [0x0056EF1C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF1Cu, ctx.xmm[0].u32[0]);
	// 0x29B0F0: ret
	return;
}

void sub_29B100(X86Context& ctx, uint8_t* base) {
	// 0x29B100: movss xmm0, dword ptr [0x0056EF30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EF30u);
	// 0x29B108: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29B110: movss [0x0056EF64], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF64u, ctx.xmm[0].u32[0]);
	// 0x29B118: ret
	return;
}

void sub_29B120(X86Context& ctx, uint8_t* base) {
	// 0x29B120: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x29B128: movss [0x0056EF38], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF38u, ctx.xmm[0].u32[0]);
	// 0x29B130: ret
	return;
}

void sub_29B140(X86Context& ctx, uint8_t* base) {
	// 0x29B140: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29B148: movss [0x0056EF0C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF0Cu, ctx.xmm[0].u32[0]);
	// 0x29B150: ret
	return;
}

void sub_29B160(X86Context& ctx, uint8_t* base) {
	// 0x29B160: movss xmm0, dword ptr [0x00405878]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x405878u);
	// 0x29B168: addss xmm0, [0x00405870]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x405870u);
	// 0x29B170: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x29B178: movss [0x0056EEF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEF0u, ctx.xmm[0].u32[0]);
	// 0x29B180: movss xmm0, dword ptr [0x00405874]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x405874u);
	// 0x29B188: movss [0x0056EEF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEF4u, ctx.xmm[0].u32[0]);
	// 0x29B190: ret
	return;
}

void sub_29B1A0(X86Context& ctx, uint8_t* base) {
	// 0x29B1A0: movss xmm0, dword ptr [0x0040587C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x40587Cu);
	// 0x29B1A8: movss [0x0056EF10], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF10u, ctx.xmm[0].u32[0]);
	// 0x29B1B0: ret
	return;
}

void sub_29B1C0(X86Context& ctx, uint8_t* base) {
	// 0x29B1C0: movss xmm0, dword ptr [0x003B1C6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C6Cu);
	// 0x29B1C8: movss [0x0056EEFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EEFCu, ctx.xmm[0].u32[0]);
	// 0x29B1D0: ret
	return;
}

void sub_29B1E0(X86Context& ctx, uint8_t* base) {
	// 0x29B1E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29B1E8: movss [0x0056F008], xmm0
	X86_MEM_WRITE_u32(base, 0x56F008u, ctx.xmm[0].u32[0]);
	// 0x29B1F0: ret
	return;
}

void sub_29B200(X86Context& ctx, uint8_t* base) {
	// 0x29B200: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29B208: movss [0x0056F02C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F02Cu, ctx.xmm[0].u32[0]);
	// 0x29B210: ret
	return;
}

void sub_29B220(X86Context& ctx, uint8_t* base) {
	// 0x29B220: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29B228: movss [0x0056EFF4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFF4u, ctx.xmm[0].u32[0]);
	// 0x29B230: ret
	return;
}

void sub_29B240(X86Context& ctx, uint8_t* base) {
	// 0x29B240: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29B248: movss [0x0056EF94], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF94u, ctx.xmm[0].u32[0]);
	// 0x29B250: ret
	return;
}

void sub_29B260(X86Context& ctx, uint8_t* base) {
	// 0x29B260: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29B268: movss [0x0056F00C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F00Cu, ctx.xmm[0].u32[0]);
	// 0x29B270: ret
	return;
}

void sub_29B280(X86Context& ctx, uint8_t* base) {
	// 0x29B280: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29B288: movss [0x0056EFB0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFB0u, ctx.xmm[0].u32[0]);
	// 0x29B290: ret
	return;
}

void sub_29B2A0(X86Context& ctx, uint8_t* base) {
	// 0x29B2A0: movss xmm0, dword ptr [0x0056F00C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F00Cu);
	// 0x29B2A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29B2B0: movss [0x0056F04C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F04Cu, ctx.xmm[0].u32[0]);
	// 0x29B2B8: ret
	return;
}

void sub_29B2C0(X86Context& ctx, uint8_t* base) {
	// 0x29B2C0: movss xmm0, dword ptr [0x0056EFB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFB0u);
	// 0x29B2C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29B2D0: movss [0x0056F034], xmm0
	X86_MEM_WRITE_u32(base, 0x56F034u, ctx.xmm[0].u32[0]);
	// 0x29B2D8: ret
	return;
}

void sub_29B2E0(X86Context& ctx, uint8_t* base) {
	// 0x29B2E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29B2E8: movss [0x0056F068], xmm0
	X86_MEM_WRITE_u32(base, 0x56F068u, ctx.xmm[0].u32[0]);
	// 0x29B2F0: ret
	return;
}

void sub_29B300(X86Context& ctx, uint8_t* base) {
	// 0x29B300: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29B308: movss [0x0056F054], xmm0
	X86_MEM_WRITE_u32(base, 0x56F054u, ctx.xmm[0].u32[0]);
	// 0x29B310: ret
	return;
}

void sub_29B320(X86Context& ctx, uint8_t* base) {
	// 0x29B320: movss xmm0, dword ptr [0x0056F054]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F054u);
	// 0x29B328: movss [0x0056F064], xmm0
	X86_MEM_WRITE_u32(base, 0x56F064u, ctx.xmm[0].u32[0]);
	// 0x29B330: ret
	return;
}

void sub_29B340(X86Context& ctx, uint8_t* base) {
	// 0x29B340: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29B348: movss [0x0056EF9C], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF9Cu, ctx.xmm[0].u32[0]);
	// 0x29B350: ret
	return;
}

void sub_29B360(X86Context& ctx, uint8_t* base) {
	// 0x29B360: movss xmm0, dword ptr [0x0056EFB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFB0u);
	// 0x29B368: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29B370: movss [0x0056F05C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F05Cu, ctx.xmm[0].u32[0]);
	// 0x29B378: ret
	return;
}

void sub_29B380(X86Context& ctx, uint8_t* base) {
	// 0x29B380: movss xmm0, dword ptr [0x0056EFB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFB0u);
	// 0x29B388: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29B390: movss [0x0056EFEC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFECu, ctx.xmm[0].u32[0]);
	// 0x29B398: ret
	return;
}

void sub_29B3A0(X86Context& ctx, uint8_t* base) {
	// 0x29B3A0: movss xmm0, dword ptr [0x0056EFB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFB0u);
	// 0x29B3A8: subss xmm0, [0x0056EFEC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EFECu);
	// 0x29B3B0: movss [0x0056EFB8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFB8u, ctx.xmm[0].u32[0]);
	// 0x29B3B8: ret
	return;
}

void sub_29B3C0(X86Context& ctx, uint8_t* base) {
	// 0x29B3C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29B3C8: movss [0x0056F028], xmm0
	X86_MEM_WRITE_u32(base, 0x56F028u, ctx.xmm[0].u32[0]);
	// 0x29B3D0: ret
	return;
}

void sub_29B3E0(X86Context& ctx, uint8_t* base) {
	// 0x29B3E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29B3E8: movss [0x0056EFB4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFB4u, ctx.xmm[0].u32[0]);
	// 0x29B3F0: ret
	return;
}

void sub_29B400(X86Context& ctx, uint8_t* base) {
	// 0x29B400: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29B408: movss [0x0056EFCC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFCCu, ctx.xmm[0].u32[0]);
	// 0x29B410: ret
	return;
}

void sub_29B420(X86Context& ctx, uint8_t* base) {
	// 0x29B420: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29B428: movss [0x0056F040], xmm0
	X86_MEM_WRITE_u32(base, 0x56F040u, ctx.xmm[0].u32[0]);
	// 0x29B430: ret
	return;
}

void sub_29B440(X86Context& ctx, uint8_t* base) {
	// 0x29B440: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29B448: movss [0x0056F020], xmm0
	X86_MEM_WRITE_u32(base, 0x56F020u, ctx.xmm[0].u32[0]);
	// 0x29B450: ret
	return;
}

void sub_29B460(X86Context& ctx, uint8_t* base) {
	// 0x29B460: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29B468: movss [0x0056EFAC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFACu, ctx.xmm[0].u32[0]);
	// 0x29B470: ret
	return;
}

void sub_29B480(X86Context& ctx, uint8_t* base) {
	// 0x29B480: movss xmm0, dword ptr [0x0056EFCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFCCu);
	// 0x29B488: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29B490: movss [0x0056EFA0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFA0u, ctx.xmm[0].u32[0]);
	// 0x29B498: ret
	return;
}

void sub_29B4A0(X86Context& ctx, uint8_t* base) {
	// 0x29B4A0: movss xmm0, dword ptr [0x0056F040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F040u);
	// 0x29B4A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29B4B0: movss [0x0056F000], xmm0
	X86_MEM_WRITE_u32(base, 0x56F000u, ctx.xmm[0].u32[0]);
	// 0x29B4B8: ret
	return;
}

void sub_29B4C0(X86Context& ctx, uint8_t* base) {
	// 0x29B4C0: movss xmm0, dword ptr [0x0056EFA0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFA0u);
	// 0x29B4C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29B4D0: movss [0x0056F014], xmm0
	X86_MEM_WRITE_u32(base, 0x56F014u, ctx.xmm[0].u32[0]);
	// 0x29B4D8: ret
	return;
}

void sub_29B4E0(X86Context& ctx, uint8_t* base) {
	// 0x29B4E0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29B4E8: movss [0x0056EF98], xmm0
	X86_MEM_WRITE_u32(base, 0x56EF98u, ctx.xmm[0].u32[0]);
	// 0x29B4F0: ret
	return;
}

void sub_29B500(X86Context& ctx, uint8_t* base) {
	// 0x29B500: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29B508: movss [0x0056EFD0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFD0u, ctx.xmm[0].u32[0]);
	// 0x29B510: ret
	return;
}

void sub_29B520(X86Context& ctx, uint8_t* base) {
	// 0x29B520: movss xmm0, dword ptr [0x0056EFCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFCCu);
	// 0x29B528: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29B530: movss [0x0056EFE8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFE8u, ctx.xmm[0].u32[0]);
	// 0x29B538: ret
	return;
}

void sub_29B540(X86Context& ctx, uint8_t* base) {
	// 0x29B540: movss xmm0, dword ptr [0x0056F040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F040u);
	// 0x29B548: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29B550: movss [0x0056F044], xmm0
	X86_MEM_WRITE_u32(base, 0x56F044u, ctx.xmm[0].u32[0]);
	// 0x29B558: ret
	return;
}

void sub_29B560(X86Context& ctx, uint8_t* base) {
	// 0x29B560: movss xmm0, dword ptr [0x0056EFE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFE8u);
	// 0x29B568: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B570: movss [0x0056F030], xmm0
	X86_MEM_WRITE_u32(base, 0x56F030u, ctx.xmm[0].u32[0]);
	// 0x29B578: ret
	return;
}

void sub_29B580(X86Context& ctx, uint8_t* base) {
	// 0x29B580: movss xmm0, dword ptr [0x0056F044]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F044u);
	// 0x29B588: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B590: movss [0x0056F058], xmm0
	X86_MEM_WRITE_u32(base, 0x56F058u, ctx.xmm[0].u32[0]);
	// 0x29B598: ret
	return;
}

void sub_29B5A0(X86Context& ctx, uint8_t* base) {
	// 0x29B5A0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29B5A8: movss [0x0056EFA4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFA4u, ctx.xmm[0].u32[0]);
	// 0x29B5B0: ret
	return;
}

void sub_29B5C0(X86Context& ctx, uint8_t* base) {
	// 0x29B5C0: movss xmm0, dword ptr [0x0056EFCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFCCu);
	// 0x29B5C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B5D0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29B5D8: movss [0x0056F03C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F03Cu, ctx.xmm[0].u32[0]);
	// 0x29B5E0: ret
	return;
}

void sub_29B5F0(X86Context& ctx, uint8_t* base) {
	// 0x29B5F0: movss xmm0, dword ptr [0x0056F040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F040u);
	// 0x29B5F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B600: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29B608: movss [0x0056EFC0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFC0u, ctx.xmm[0].u32[0]);
	// 0x29B610: ret
	return;
}

void sub_29B620(X86Context& ctx, uint8_t* base) {
	// 0x29B620: movss xmm0, dword ptr [0x0056EFCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFCCu);
	// 0x29B628: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B630: movss [0x0056EFC4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFC4u, ctx.xmm[0].u32[0]);
	// 0x29B638: ret
	return;
}

void sub_29B640(X86Context& ctx, uint8_t* base) {
	// 0x29B640: movss xmm0, dword ptr [0x0056F040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F040u);
	// 0x29B648: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29B650: movss [0x0056F048], xmm0
	X86_MEM_WRITE_u32(base, 0x56F048u, ctx.xmm[0].u32[0]);
	// 0x29B658: ret
	return;
}

void sub_29B660(X86Context& ctx, uint8_t* base) {
	// 0x29B660: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29B668: movss [0x0056EFA8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFA8u, ctx.xmm[0].u32[0]);
	// 0x29B670: ret
	return;
}

void sub_29B680(X86Context& ctx, uint8_t* base) {
	// 0x29B680: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29B688: movss [0x0056EFE4], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFE4u, ctx.xmm[0].u32[0]);
	// 0x29B690: ret
	return;
}

void sub_29B6A0(X86Context& ctx, uint8_t* base) {
	// 0x29B6A0: movss xmm0, dword ptr [0x0056EFA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFA8u);
	// 0x29B6A8: movss [0x0056F060], xmm0
	X86_MEM_WRITE_u32(base, 0x56F060u, ctx.xmm[0].u32[0]);
	// 0x29B6B0: ret
	return;
}

void sub_29B6C0(X86Context& ctx, uint8_t* base) {
	// 0x29B6C0: movss xmm0, dword ptr [0x0056F040]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F040u);
	// 0x29B6C8: subss xmm0, [0x0056EFA8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EFA8u);
	// 0x29B6D0: movss [0x0056F01C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F01Cu, ctx.xmm[0].u32[0]);
	// 0x29B6D8: ret
	return;
}

void sub_29B6E0(X86Context& ctx, uint8_t* base) {
	// 0x29B6E0: movss xmm0, dword ptr [0x0056F01C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F01Cu);
	// 0x29B6E8: subss xmm0, [0x0056EFE4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56EFE4u);
	// 0x29B6F0: movss [0x0056F010], xmm0
	X86_MEM_WRITE_u32(base, 0x56F010u, ctx.xmm[0].u32[0]);
	// 0x29B6F8: ret
	return;
}

void sub_29B700(X86Context& ctx, uint8_t* base) {
	// 0x29B700: movss xmm0, dword ptr [0x0056F048]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F048u);
	// 0x29B708: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29B710: movss [0x0056EFFC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFFCu, ctx.xmm[0].u32[0]);
	// 0x29B718: ret
	return;
}

void sub_29B720(X86Context& ctx, uint8_t* base) {
	// 0x29B720: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29B728: movss [0x0056EFE0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFE0u, ctx.xmm[0].u32[0]);
	// 0x29B730: ret
	return;
}

void sub_29B740(X86Context& ctx, uint8_t* base) {
	// 0x29B740: movss xmm0, dword ptr [0x0056EFFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFFCu);
	// 0x29B748: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29B750: movss [0x0056F038], xmm0
	X86_MEM_WRITE_u32(base, 0x56F038u, ctx.xmm[0].u32[0]);
	// 0x29B758: ret
	return;
}

void sub_29B760(X86Context& ctx, uint8_t* base) {
	// 0x29B760: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x29B768: movss [0x0056F004], xmm0
	X86_MEM_WRITE_u32(base, 0x56F004u, ctx.xmm[0].u32[0]);
	// 0x29B770: ret
	return;
}

void sub_29B780(X86Context& ctx, uint8_t* base) {
	// 0x29B780: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29B788: movss [0x0056EFC8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFC8u, ctx.xmm[0].u32[0]);
	// 0x29B790: ret
	return;
}

void sub_29B7A0(X86Context& ctx, uint8_t* base) {
	// 0x29B7A0: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x29B7A8: movss [0x0056EFF8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFF8u, ctx.xmm[0].u32[0]);
	// 0x29B7B0: ret
	return;
}

void sub_29B7C0(X86Context& ctx, uint8_t* base) {
	// 0x29B7C0: movss xmm0, dword ptr [0x00388E90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x388E90u);
	// 0x29B7C8: movss [0x0056EFBC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFBCu, ctx.xmm[0].u32[0]);
	// 0x29B7D0: ret
	return;
}

void sub_29B7E0(X86Context& ctx, uint8_t* base) {
	// 0x29B7E0: movss xmm0, dword ptr [0x003B2290]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2290u);
	// 0x29B7E8: movss [0x0056F050], xmm0
	X86_MEM_WRITE_u32(base, 0x56F050u, ctx.xmm[0].u32[0]);
	// 0x29B7F0: ret
	return;
}

void sub_29B800(X86Context& ctx, uint8_t* base) {
	// 0x29B800: movss xmm0, dword ptr [0x003B1904]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1904u);
	// 0x29B808: movss [0x0056F018], xmm0
	X86_MEM_WRITE_u32(base, 0x56F018u, ctx.xmm[0].u32[0]);
	// 0x29B810: ret
	return;
}

void sub_29B820(X86Context& ctx, uint8_t* base) {
	// 0x29B820: movss xmm0, dword ptr [0x0056EFCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFCCu);
	// 0x29B828: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x29B830: movss [0x00405930], xmm0
	X86_MEM_WRITE_u32(base, 0x405930u, ctx.xmm[0].u32[0]);
	// 0x29B838: ret
	return;
}

void sub_29B840(X86Context& ctx, uint8_t* base) {
	// 0x29B840: movss xmm0, dword ptr [0x003F8320]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3F8320u);
	// 0x29B848: movss [0x0056F024], xmm0
	X86_MEM_WRITE_u32(base, 0x56F024u, ctx.xmm[0].u32[0]);
	// 0x29B850: ret
	return;
}

void sub_29B860(X86Context& ctx, uint8_t* base) {
	// 0x29B860: movss xmm0, dword ptr [0x0056F050]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F050u);
	// 0x29B868: addss xmm0, [0x0056EFF8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x56EFF8u);
	// 0x29B870: addss xmm0, [0x003B16B0]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B0u);
	// 0x29B878: movss [0x0056EFD8], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFD8u, ctx.xmm[0].u32[0]);
	// 0x29B880: movss xmm0, dword ptr [0x0056EFBC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56EFBCu);
	// 0x29B888: movss [0x0056EFDC], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFDCu, ctx.xmm[0].u32[0]);
	// 0x29B890: ret
	return;
}

void sub_29B8A0(X86Context& ctx, uint8_t* base) {
	// 0x29B8A0: movss xmm0, dword ptr [0x0056F018]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F018u);
	// 0x29B8A8: movss [0x0056EFF0], xmm0
	X86_MEM_WRITE_u32(base, 0x56EFF0u, ctx.xmm[0].u32[0]);
	// 0x29B8B0: ret
	return;
}

void sub_29B8C0(X86Context& ctx, uint8_t* base) {
	// 0x29B8C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29B8C8: movss [0x0056F0C8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0C8u, ctx.xmm[0].u32[0]);
	// 0x29B8D0: ret
	return;
}

void sub_29B8E0(X86Context& ctx, uint8_t* base) {
	// 0x29B8E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29B8E8: movss [0x0056F0E4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0E4u, ctx.xmm[0].u32[0]);
	// 0x29B8F0: ret
	return;
}

void sub_29B900(X86Context& ctx, uint8_t* base) {
	// 0x29B900: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29B908: movss [0x0056F0B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0B8u, ctx.xmm[0].u32[0]);
	// 0x29B910: ret
	return;
}

void sub_29B920(X86Context& ctx, uint8_t* base) {
	// 0x29B920: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29B928: movss [0x0056F06C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F06Cu, ctx.xmm[0].u32[0]);
	// 0x29B930: ret
	return;
}

void sub_29B940(X86Context& ctx, uint8_t* base) {
	// 0x29B940: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29B948: movss [0x0056F0CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0CCu, ctx.xmm[0].u32[0]);
	// 0x29B950: ret
	return;
}

void sub_29B960(X86Context& ctx, uint8_t* base) {
	// 0x29B960: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29B968: movss [0x0056F088], xmm0
	X86_MEM_WRITE_u32(base, 0x56F088u, ctx.xmm[0].u32[0]);
	// 0x29B970: ret
	return;
}

void sub_29B980(X86Context& ctx, uint8_t* base) {
	// 0x29B980: movss xmm0, dword ptr [0x0056F0CC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0CCu);
	// 0x29B988: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29B990: movss [0x0056F104], xmm0
	X86_MEM_WRITE_u32(base, 0x56F104u, ctx.xmm[0].u32[0]);
	// 0x29B998: ret
	return;
}

void sub_29B9A0(X86Context& ctx, uint8_t* base) {
	// 0x29B9A0: movss xmm0, dword ptr [0x0056F088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F088u);
	// 0x29B9A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29B9B0: movss [0x0056F0EC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0ECu, ctx.xmm[0].u32[0]);
	// 0x29B9B8: ret
	return;
}

void sub_29B9C0(X86Context& ctx, uint8_t* base) {
	// 0x29B9C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29B9C8: movss [0x0056F11C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F11Cu, ctx.xmm[0].u32[0]);
	// 0x29B9D0: ret
	return;
}

void sub_29B9E0(X86Context& ctx, uint8_t* base) {
	// 0x29B9E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29B9E8: movss [0x0056F108], xmm0
	X86_MEM_WRITE_u32(base, 0x56F108u, ctx.xmm[0].u32[0]);
	// 0x29B9F0: ret
	return;
}

void sub_29BA00(X86Context& ctx, uint8_t* base) {
	// 0x29BA00: movss xmm0, dword ptr [0x0056F108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F108u);
	// 0x29BA08: movss [0x0056F118], xmm0
	X86_MEM_WRITE_u32(base, 0x56F118u, ctx.xmm[0].u32[0]);
	// 0x29BA10: ret
	return;
}

void sub_29BA20(X86Context& ctx, uint8_t* base) {
	// 0x29BA20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29BA28: movss [0x0056F074], xmm0
	X86_MEM_WRITE_u32(base, 0x56F074u, ctx.xmm[0].u32[0]);
	// 0x29BA30: ret
	return;
}

void sub_29BA40(X86Context& ctx, uint8_t* base) {
	// 0x29BA40: movss xmm0, dword ptr [0x0056F088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F088u);
	// 0x29BA48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29BA50: movss [0x0056F110], xmm0
	X86_MEM_WRITE_u32(base, 0x56F110u, ctx.xmm[0].u32[0]);
	// 0x29BA58: ret
	return;
}

void sub_29BA60(X86Context& ctx, uint8_t* base) {
	// 0x29BA60: movss xmm0, dword ptr [0x0056F088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F088u);
	// 0x29BA68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29BA70: movss [0x0056F0B4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0B4u, ctx.xmm[0].u32[0]);
	// 0x29BA78: ret
	return;
}

void sub_29BA80(X86Context& ctx, uint8_t* base) {
	// 0x29BA80: movss xmm0, dword ptr [0x0056F088]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F088u);
	// 0x29BA88: subss xmm0, [0x0056F0B4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F0B4u);
	// 0x29BA90: movss [0x0056F090], xmm0
	X86_MEM_WRITE_u32(base, 0x56F090u, ctx.xmm[0].u32[0]);
	// 0x29BA98: ret
	return;
}

void sub_29BAA0(X86Context& ctx, uint8_t* base) {
	// 0x29BAA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29BAA8: movss [0x0056F0E0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0E0u, ctx.xmm[0].u32[0]);
	// 0x29BAB0: ret
	return;
}

void sub_29BAC0(X86Context& ctx, uint8_t* base) {
	// 0x29BAC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29BAC8: movss [0x0056F08C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F08Cu, ctx.xmm[0].u32[0]);
	// 0x29BAD0: ret
	return;
}

void sub_29BAE0(X86Context& ctx, uint8_t* base) {
	// 0x29BAE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29BAE8: movss [0x0056F0A0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0A0u, ctx.xmm[0].u32[0]);
	// 0x29BAF0: ret
	return;
}

void sub_29BB00(X86Context& ctx, uint8_t* base) {
	// 0x29BB00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29BB08: movss [0x0056F0F8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0F8u, ctx.xmm[0].u32[0]);
	// 0x29BB10: ret
	return;
}

void sub_29BB20(X86Context& ctx, uint8_t* base) {
	// 0x29BB20: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29BB28: movss [0x0056F0DC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0DCu, ctx.xmm[0].u32[0]);
	// 0x29BB30: ret
	return;
}

void sub_29BB40(X86Context& ctx, uint8_t* base) {
	// 0x29BB40: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29BB48: movss [0x0056F084], xmm0
	X86_MEM_WRITE_u32(base, 0x56F084u, ctx.xmm[0].u32[0]);
	// 0x29BB50: ret
	return;
}

void sub_29BB60(X86Context& ctx, uint8_t* base) {
	// 0x29BB60: movss xmm0, dword ptr [0x0056F0A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0A0u);
	// 0x29BB68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29BB70: movss [0x0056F078], xmm0
	X86_MEM_WRITE_u32(base, 0x56F078u, ctx.xmm[0].u32[0]);
	// 0x29BB78: ret
	return;
}

void sub_29BB80(X86Context& ctx, uint8_t* base) {
	// 0x29BB80: movss xmm0, dword ptr [0x0056F0F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0F8u);
	// 0x29BB88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29BB90: movss [0x0056F0C0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0C0u, ctx.xmm[0].u32[0]);
	// 0x29BB98: ret
	return;
}

void sub_29BBA0(X86Context& ctx, uint8_t* base) {
	// 0x29BBA0: movss xmm0, dword ptr [0x0056F078]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F078u);
	// 0x29BBA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29BBB0: movss [0x0056F0D4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0D4u, ctx.xmm[0].u32[0]);
	// 0x29BBB8: ret
	return;
}

void sub_29BBC0(X86Context& ctx, uint8_t* base) {
	// 0x29BBC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29BBC8: movss [0x0056F070], xmm0
	X86_MEM_WRITE_u32(base, 0x56F070u, ctx.xmm[0].u32[0]);
	// 0x29BBD0: ret
	return;
}

void sub_29BBE0(X86Context& ctx, uint8_t* base) {
	// 0x29BBE0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29BBE8: movss [0x0056F0A4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0A4u, ctx.xmm[0].u32[0]);
	// 0x29BBF0: ret
	return;
}

void sub_29BC00(X86Context& ctx, uint8_t* base) {
	// 0x29BC00: movss xmm0, dword ptr [0x0056F0A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0A0u);
	// 0x29BC08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29BC10: movss [0x0056F0B0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0B0u, ctx.xmm[0].u32[0]);
	// 0x29BC18: ret
	return;
}

void sub_29BC20(X86Context& ctx, uint8_t* base) {
	// 0x29BC20: movss xmm0, dword ptr [0x0056F0F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0F8u);
	// 0x29BC28: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x29BC30: movss [0x0056F0FC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0FCu, ctx.xmm[0].u32[0]);
	// 0x29BC38: ret
	return;
}

void sub_29BC40(X86Context& ctx, uint8_t* base) {
	// 0x29BC40: movss xmm0, dword ptr [0x0056F0B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0B0u);
	// 0x29BC48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29BC50: movss [0x0056F0E8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0E8u, ctx.xmm[0].u32[0]);
	// 0x29BC58: ret
	return;
}

void sub_29BC60(X86Context& ctx, uint8_t* base) {
	// 0x29BC60: movss xmm0, dword ptr [0x0056F0FC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0FCu);
	// 0x29BC68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29BC70: movss [0x0056F10C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F10Cu, ctx.xmm[0].u32[0]);
	// 0x29BC78: ret
	return;
}

void sub_29BC80(X86Context& ctx, uint8_t* base) {
	// 0x29BC80: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x29BC88: movss [0x0056F07C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F07Cu, ctx.xmm[0].u32[0]);
	// 0x29BC90: ret
	return;
}

void sub_29BCA0(X86Context& ctx, uint8_t* base) {
	// 0x29BCA0: movss xmm0, dword ptr [0x0056F0A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0A0u);
	// 0x29BCA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29BCB0: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x29BCB8: movss [0x0056F0F4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0F4u, ctx.xmm[0].u32[0]);
	// 0x29BCC0: ret
	return;
}

void sub_29BCD0(X86Context& ctx, uint8_t* base) {
	// 0x29BCD0: movss xmm0, dword ptr [0x0056F0F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0F8u);
	// 0x29BCD8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29BCE0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x29BCE8: movss [0x0056F094], xmm0
	X86_MEM_WRITE_u32(base, 0x56F094u, ctx.xmm[0].u32[0]);
	// 0x29BCF0: ret
	return;
}

void sub_29BD00(X86Context& ctx, uint8_t* base) {
	// 0x29BD00: movss xmm0, dword ptr [0x0056F0A0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0A0u);
	// 0x29BD08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29BD10: movss [0x0056F098], xmm0
	X86_MEM_WRITE_u32(base, 0x56F098u, ctx.xmm[0].u32[0]);
	// 0x29BD18: ret
	return;
}

void sub_29BD20(X86Context& ctx, uint8_t* base) {
	// 0x29BD20: movss xmm0, dword ptr [0x0056F0F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0F8u);
	// 0x29BD28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x29BD30: movss [0x0056F100], xmm0
	X86_MEM_WRITE_u32(base, 0x56F100u, ctx.xmm[0].u32[0]);
	// 0x29BD38: ret
	return;
}

void sub_29BD40(X86Context& ctx, uint8_t* base) {
	// 0x29BD40: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x29BD48: movss [0x0056F080], xmm0
	X86_MEM_WRITE_u32(base, 0x56F080u, ctx.xmm[0].u32[0]);
	// 0x29BD50: ret
	return;
}

void sub_29BD60(X86Context& ctx, uint8_t* base) {
	// 0x29BD60: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x29BD68: movss [0x0056F0AC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0ACu, ctx.xmm[0].u32[0]);
	// 0x29BD70: ret
	return;
}

void sub_29BD80(X86Context& ctx, uint8_t* base) {
	// 0x29BD80: movss xmm0, dword ptr [0x0056F080]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F080u);
	// 0x29BD88: movss [0x0056F114], xmm0
	X86_MEM_WRITE_u32(base, 0x56F114u, ctx.xmm[0].u32[0]);
	// 0x29BD90: ret
	return;
}

void sub_29BDA0(X86Context& ctx, uint8_t* base) {
	// 0x29BDA0: movss xmm0, dword ptr [0x0056F0F8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0F8u);
	// 0x29BDA8: subss xmm0, [0x0056F080]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F080u);
	// 0x29BDB0: movss [0x0056F0D8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0D8u, ctx.xmm[0].u32[0]);
	// 0x29BDB8: ret
	return;
}

void sub_29BDC0(X86Context& ctx, uint8_t* base) {
	// 0x29BDC0: movss xmm0, dword ptr [0x0056F0D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0D8u);
	// 0x29BDC8: subss xmm0, [0x0056F0AC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F0ACu);
	// 0x29BDD0: movss [0x0056F0D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0D0u, ctx.xmm[0].u32[0]);
	// 0x29BDD8: ret
	return;
}

void sub_29BDE0(X86Context& ctx, uint8_t* base) {
	// 0x29BDE0: movss xmm0, dword ptr [0x0056F100]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F100u);
	// 0x29BDE8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x29BDF0: movss [0x0056F0BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0BCu, ctx.xmm[0].u32[0]);
	// 0x29BDF8: ret
	return;
}

void sub_29BE00(X86Context& ctx, uint8_t* base) {
	// 0x29BE00: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x29BE08: movss [0x0056F0A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0A8u, ctx.xmm[0].u32[0]);
	// 0x29BE10: ret
	return;
}

void sub_29BE20(X86Context& ctx, uint8_t* base) {
	// 0x29BE20: movss xmm0, dword ptr [0x0056F0BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F0BCu);
	// 0x29BE28: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x29BE30: movss [0x0056F0F0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0F0u, ctx.xmm[0].u32[0]);
	// 0x29BE38: ret
	return;
}

void sub_29BE40(X86Context& ctx, uint8_t* base) {
	// 0x29BE40: movss xmm0, dword ptr [0x0039B2B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x39B2B0u);
	// 0x29BE48: movss [0x0056F0C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F0C4u, ctx.xmm[0].u32[0]);
	// 0x29BE50: ret
	return;
}

void sub_29BE60(X86Context& ctx, uint8_t* base) {
	// 0x29BE60: movss xmm0, dword ptr [0x003B2114]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2114u);
	// 0x29BE68: movss [0x0056F09C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F09Cu, ctx.xmm[0].u32[0]);
	// 0x29BE70: ret
	return;
}

void sub_29BE80(X86Context& ctx, uint8_t* base) {
	// 0x29BE80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x29BE88: movss [0x0056F178], xmm0
	X86_MEM_WRITE_u32(base, 0x56F178u, ctx.xmm[0].u32[0]);
	// 0x29BE90: ret
	return;
}

void sub_29BEA0(X86Context& ctx, uint8_t* base) {
	// 0x29BEA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x29BEA8: movss [0x0056F194], xmm0
	X86_MEM_WRITE_u32(base, 0x56F194u, ctx.xmm[0].u32[0]);
	// 0x29BEB0: ret
	return;
}

void sub_29BEC0(X86Context& ctx, uint8_t* base) {
	// 0x29BEC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x29BEC8: movss [0x0056F16C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F16Cu, ctx.xmm[0].u32[0]);
	// 0x29BED0: ret
	return;
}

void sub_29BEE0(X86Context& ctx, uint8_t* base) {
	// 0x29BEE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x29BEE8: movss [0x0056F120], xmm0
	X86_MEM_WRITE_u32(base, 0x56F120u, ctx.xmm[0].u32[0]);
	// 0x29BEF0: ret
	return;
}

void sub_29BF00(X86Context& ctx, uint8_t* base) {
	// 0x29BF00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29BF08: movss [0x0056F17C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F17Cu, ctx.xmm[0].u32[0]);
	// 0x29BF10: ret
	return;
}

void sub_29BF20(X86Context& ctx, uint8_t* base) {
	// 0x29BF20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29BF28: movss [0x0056F13C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F13Cu, ctx.xmm[0].u32[0]);
	// 0x29BF30: ret
	return;
}

void sub_29BF40(X86Context& ctx, uint8_t* base) {
	// 0x29BF40: movss xmm0, dword ptr [0x0056F17C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F17Cu);
	// 0x29BF48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29BF50: movss [0x0056F1B8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1B8u, ctx.xmm[0].u32[0]);
	// 0x29BF58: ret
	return;
}

void sub_29BF60(X86Context& ctx, uint8_t* base) {
	// 0x29BF60: movss xmm0, dword ptr [0x0056F13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F13Cu);
	// 0x29BF68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29BF70: movss [0x0056F19C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F19Cu, ctx.xmm[0].u32[0]);
	// 0x29BF78: ret
	return;
}

void sub_29BF80(X86Context& ctx, uint8_t* base) {
	// 0x29BF80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29BF88: movss [0x0056F1D0], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1D0u, ctx.xmm[0].u32[0]);
	// 0x29BF90: ret
	return;
}

void sub_29BFA0(X86Context& ctx, uint8_t* base) {
	// 0x29BFA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x29BFA8: movss [0x0056F1BC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1BCu, ctx.xmm[0].u32[0]);
	// 0x29BFB0: ret
	return;
}

void sub_29BFC0(X86Context& ctx, uint8_t* base) {
	// 0x29BFC0: movss xmm0, dword ptr [0x0056F1BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1BCu);
	// 0x29BFC8: movss [0x0056F1CC], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1CCu, ctx.xmm[0].u32[0]);
	// 0x29BFD0: ret
	return;
}

void sub_29BFE0(X86Context& ctx, uint8_t* base) {
	// 0x29BFE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x29BFE8: movss [0x0056F128], xmm0
	X86_MEM_WRITE_u32(base, 0x56F128u, ctx.xmm[0].u32[0]);
	// 0x29BFF0: ret
	return;
}

void sub_29C000(X86Context& ctx, uint8_t* base) {
	// 0x29C000: movss xmm0, dword ptr [0x0056F13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F13Cu);
	// 0x29C008: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x29C010: movss [0x0056F1C4], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1C4u, ctx.xmm[0].u32[0]);
	// 0x29C018: ret
	return;
}

void sub_29C020(X86Context& ctx, uint8_t* base) {
	// 0x29C020: movss xmm0, dword ptr [0x0056F13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F13Cu);
	// 0x29C028: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x29C030: movss [0x0056F168], xmm0
	X86_MEM_WRITE_u32(base, 0x56F168u, ctx.xmm[0].u32[0]);
	// 0x29C038: ret
	return;
}

void sub_29C040(X86Context& ctx, uint8_t* base) {
	// 0x29C040: movss xmm0, dword ptr [0x0056F13C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F13Cu);
	// 0x29C048: subss xmm0, [0x0056F168]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x56F168u);
	// 0x29C050: movss [0x0056F148], xmm0
	X86_MEM_WRITE_u32(base, 0x56F148u, ctx.xmm[0].u32[0]);
	// 0x29C058: ret
	return;
}

void sub_29C060(X86Context& ctx, uint8_t* base) {
	// 0x29C060: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x29C068: movss [0x0056F190], xmm0
	X86_MEM_WRITE_u32(base, 0x56F190u, ctx.xmm[0].u32[0]);
	// 0x29C070: ret
	return;
}

void sub_29C080(X86Context& ctx, uint8_t* base) {
	// 0x29C080: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x29C088: movss [0x0056F144], xmm0
	X86_MEM_WRITE_u32(base, 0x56F144u, ctx.xmm[0].u32[0]);
	// 0x29C090: ret
	return;
}

void sub_29C0A0(X86Context& ctx, uint8_t* base) {
	// 0x29C0A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x29C0A8: movss [0x0056F154], xmm0
	X86_MEM_WRITE_u32(base, 0x56F154u, ctx.xmm[0].u32[0]);
	// 0x29C0B0: ret
	return;
}

void sub_29C0C0(X86Context& ctx, uint8_t* base) {
	// 0x29C0C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x29C0C8: movss [0x0056F1A8], xmm0
	X86_MEM_WRITE_u32(base, 0x56F1A8u, ctx.xmm[0].u32[0]);
	// 0x29C0D0: ret
	return;
}

void sub_29C0E0(X86Context& ctx, uint8_t* base) {
	// 0x29C0E0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x29C0E8: movss [0x0056F18C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F18Cu, ctx.xmm[0].u32[0]);
	// 0x29C0F0: ret
	return;
}

void sub_29C100(X86Context& ctx, uint8_t* base) {
	// 0x29C100: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x29C108: movss [0x0056F138], xmm0
	X86_MEM_WRITE_u32(base, 0x56F138u, ctx.xmm[0].u32[0]);
	// 0x29C110: ret
	return;
}

void sub_29C120(X86Context& ctx, uint8_t* base) {
	// 0x29C120: movss xmm0, dword ptr [0x0056F154]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F154u);
	// 0x29C128: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29C130: movss [0x0056F12C], xmm0
	X86_MEM_WRITE_u32(base, 0x56F12Cu, ctx.xmm[0].u32[0]);
	// 0x29C138: ret
	return;
}

void sub_29C140(X86Context& ctx, uint8_t* base) {
	// 0x29C140: movss xmm0, dword ptr [0x0056F1A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F1A8u);
	// 0x29C148: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x29C150: movss [0x0056F174], xmm0
	X86_MEM_WRITE_u32(base, 0x56F174u, ctx.xmm[0].u32[0]);
	// 0x29C158: ret
	return;
}

void sub_29C160(X86Context& ctx, uint8_t* base) {
	// 0x29C160: movss xmm0, dword ptr [0x0056F12C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x56F12Cu);
	// 0x29C168: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x29C170: movss [0x0056F184], xmm0
	X86_MEM_WRITE_u32(base, 0x56F184u, ctx.xmm[0].u32[0]);
	// 0x29C178: ret
	return;
}

void sub_29C180(X86Context& ctx, uint8_t* base) {
	// 0x29C180: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x29C188: movss [0x0056F124], xmm0
	X86_MEM_WRITE_u32(base, 0x56F124u, ctx.xmm[0].u32[0]);
	// 0x29C190: ret
	return;
}

