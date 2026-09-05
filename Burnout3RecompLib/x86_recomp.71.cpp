#include "x86_recomp_shared.h"

void sub_2B0D50(X86Context& ctx, uint8_t* base) {
	// 0x2B0D50: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B0D58: movss [0x00571A08], xmm0
	X86_MEM_WRITE_u32(base, 0x571A08u, ctx.xmm[0].u32[0]);
	// 0x2B0D60: ret
	return;
}

void sub_2B0D70(X86Context& ctx, uint8_t* base) {
	// 0x2B0D70: movss xmm0, dword ptr [0x003B1730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2B0D78: movss [0x00571A0C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A0Cu, ctx.xmm[0].u32[0]);
	// 0x2B0D80: ret
	return;
}

void sub_2B0D90(X86Context& ctx, uint8_t* base) {
	// 0x2B0D90: movss xmm0, dword ptr [0x003B2214]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2214u);
	// 0x2B0D98: movss [0x00571AA4], xmm0
	X86_MEM_WRITE_u32(base, 0x571AA4u, ctx.xmm[0].u32[0]);
	// 0x2B0DA0: ret
	return;
}

void sub_2B0DB0(X86Context& ctx, uint8_t* base) {
	// 0x2B0DB0: movss xmm0, dword ptr [0x003895BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3895BCu);
	// 0x2B0DB8: movss [0x005719DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5719DCu, ctx.xmm[0].u32[0]);
	// 0x2B0DC0: ret
	return;
}

void sub_2B0DD0(X86Context& ctx, uint8_t* base) {
	// 0x2B0DD0: movss xmm0, dword ptr [0x003B16F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16F0u);
	// 0x2B0DD8: movss [0x00571A80], xmm0
	X86_MEM_WRITE_u32(base, 0x571A80u, ctx.xmm[0].u32[0]);
	// 0x2B0DE0: ret
	return;
}

void sub_2B0DF0(X86Context& ctx, uint8_t* base) {
	// 0x2B0DF0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B0DF8: movss [0x005719F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5719F0u, ctx.xmm[0].u32[0]);
	// 0x2B0E00: ret
	return;
}

void sub_2B0E10(X86Context& ctx, uint8_t* base) {
	// 0x2B0E10: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B0E18: movss [0x00571998], xmm0
	X86_MEM_WRITE_u32(base, 0x571998u, ctx.xmm[0].u32[0]);
	// 0x2B0E20: ret
	return;
}

void sub_2B0E30(X86Context& ctx, uint8_t* base) {
	// 0x2B0E30: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B0E38: movss [0x00571990], xmm0
	X86_MEM_WRITE_u32(base, 0x571990u, ctx.xmm[0].u32[0]);
	// 0x2B0E40: ret
	return;
}

void sub_2B0E50(X86Context& ctx, uint8_t* base) {
	// 0x2B0E50: movss xmm0, dword ptr [0x003B1688]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1688u);
	// 0x2B0E58: movss [0x00571A7C], xmm0
	X86_MEM_WRITE_u32(base, 0x571A7Cu, ctx.xmm[0].u32[0]);
	// 0x2B0E60: ret
	return;
}

void sub_2B0E70(X86Context& ctx, uint8_t* base) {
	// 0x2B0E70: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B0E78: movss [0x00571A50], xmm0
	X86_MEM_WRITE_u32(base, 0x571A50u, ctx.xmm[0].u32[0]);
	// 0x2B0E80: ret
	return;
}

void sub_2B0E90(X86Context& ctx, uint8_t* base) {
	// 0x2B0E90: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B0E98: movss [0x00571A38], xmm0
	X86_MEM_WRITE_u32(base, 0x571A38u, ctx.xmm[0].u32[0]);
	// 0x2B0EA0: ret
	return;
}

void sub_2B0EB0(X86Context& ctx, uint8_t* base) {
	// 0x2B0EB0: movss xmm0, dword ptr [0x003B17E4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17E4u);
	// 0x2B0EB8: movss [0x00571A24], xmm0
	X86_MEM_WRITE_u32(base, 0x571A24u, ctx.xmm[0].u32[0]);
	// 0x2B0EC0: ret
	return;
}

void sub_2B0ED0(X86Context& ctx, uint8_t* base) {
	// 0x2B0ED0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B0ED1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B0ED3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B0ED6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B0ED9: movss xmm0, dword ptr [0x003B1684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2B0EE1: xorps xmm1, xmm1
	memset(&ctx.xmm[1], 0, sizeof(ctx.xmm[1]));
	// 0x2B0EE4: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B0EE9: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B0EEC: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x2B0EF2: movss xmm1, dword ptr [0x003A55F8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3A55F8u);
	// 0x2B0EFA: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B0EFE: movss [esp+0x08], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[1].u32[0]);
	// 0x2B0F04: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B0F08: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B0F0E: mov [0x005719F8], eax
	X86_MEM_WRITE_u32(base, 0x5719F8u, ctx.eax);
	// 0x2B0F13: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B0F17: mov [0x005719FC], ecx
	X86_MEM_WRITE_u32(base, 0x5719FCu, ctx.ecx);
	// 0x2B0F1D: mov [0x00571A00], edx
	X86_MEM_WRITE_u32(base, 0x571A00u, ctx.edx);
	// 0x2B0F23: mov [0x00571A04], eax
	X86_MEM_WRITE_u32(base, 0x571A04u, ctx.eax);
	// 0x2B0F28: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B0F2A: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B0F2B: ret
	return;
}

void sub_2B0F30(X86Context& ctx, uint8_t* base) {
	// 0x2B0F30: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B0F31: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B0F33: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B0F36: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B0F39: movss xmm0, dword ptr [0x003B1730]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1730u);
	// 0x2B0F41: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B0F46: xorps xmm0, xmm0
	memset(&ctx.xmm[0], 0, sizeof(ctx.xmm[0]));
	// 0x2B0F49: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B0F4C: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B0F52: movss xmm0, dword ptr [0x003B1684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2B0F5A: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B0F5E: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B0F64: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B0F68: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B0F6E: mov [0x00571A88], eax
	X86_MEM_WRITE_u32(base, 0x571A88u, ctx.eax);
	// 0x2B0F73: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B0F77: mov [0x00571A8C], ecx
	X86_MEM_WRITE_u32(base, 0x571A8Cu, ctx.ecx);
	// 0x2B0F7D: mov [0x00571A90], edx
	X86_MEM_WRITE_u32(base, 0x571A90u, ctx.edx);
	// 0x2B0F83: mov [0x00571A94], eax
	X86_MEM_WRITE_u32(base, 0x571A94u, ctx.eax);
	// 0x2B0F88: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B0F8A: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B0F8B: ret
	return;
}

void sub_2B0F90(X86Context& ctx, uint8_t* base) {
	// 0x2B0F90: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B0F98: movss [0x00571B50], xmm0
	X86_MEM_WRITE_u32(base, 0x571B50u, ctx.xmm[0].u32[0]);
	// 0x2B0FA0: ret
	return;
}

void sub_2B0FB0(X86Context& ctx, uint8_t* base) {
	// 0x2B0FB0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B0FB8: movss [0x00571B84], xmm0
	X86_MEM_WRITE_u32(base, 0x571B84u, ctx.xmm[0].u32[0]);
	// 0x2B0FC0: ret
	return;
}

void sub_2B0FD0(X86Context& ctx, uint8_t* base) {
	// 0x2B0FD0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B0FD8: movss [0x00571B30], xmm0
	X86_MEM_WRITE_u32(base, 0x571B30u, ctx.xmm[0].u32[0]);
	// 0x2B0FE0: ret
	return;
}

void sub_2B0FF0(X86Context& ctx, uint8_t* base) {
	// 0x2B0FF0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B0FF8: movss [0x00571AB0], xmm0
	X86_MEM_WRITE_u32(base, 0x571AB0u, ctx.xmm[0].u32[0]);
	// 0x2B1000: ret
	return;
}

void sub_2B1010(X86Context& ctx, uint8_t* base) {
	// 0x2B1010: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B1018: movss [0x00571B54], xmm0
	X86_MEM_WRITE_u32(base, 0x571B54u, ctx.xmm[0].u32[0]);
	// 0x2B1020: ret
	return;
}

void sub_2B1030(X86Context& ctx, uint8_t* base) {
	// 0x2B1030: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B1038: movss [0x00571ACC], xmm0
	X86_MEM_WRITE_u32(base, 0x571ACCu, ctx.xmm[0].u32[0]);
	// 0x2B1040: ret
	return;
}

void sub_2B1050(X86Context& ctx, uint8_t* base) {
	// 0x2B1050: movss xmm0, dword ptr [0x00571B54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B54u);
	// 0x2B1058: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B1060: movss [0x00571BBC], xmm0
	X86_MEM_WRITE_u32(base, 0x571BBCu, ctx.xmm[0].u32[0]);
	// 0x2B1068: ret
	return;
}

void sub_2B1070(X86Context& ctx, uint8_t* base) {
	// 0x2B1070: movss xmm0, dword ptr [0x00571ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ACCu);
	// 0x2B1078: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B1080: movss [0x00571B8C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B8Cu, ctx.xmm[0].u32[0]);
	// 0x2B1088: ret
	return;
}

void sub_2B1090(X86Context& ctx, uint8_t* base) {
	// 0x2B1090: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B1098: movss [0x00571BF4], xmm0
	X86_MEM_WRITE_u32(base, 0x571BF4u, ctx.xmm[0].u32[0]);
	// 0x2B10A0: ret
	return;
}

void sub_2B10B0(X86Context& ctx, uint8_t* base) {
	// 0x2B10B0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B10B8: movss [0x00571BC0], xmm0
	X86_MEM_WRITE_u32(base, 0x571BC0u, ctx.xmm[0].u32[0]);
	// 0x2B10C0: ret
	return;
}

void sub_2B10D0(X86Context& ctx, uint8_t* base) {
	// 0x2B10D0: movss xmm0, dword ptr [0x00571BC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BC0u);
	// 0x2B10D8: movss [0x00571BF0], xmm0
	X86_MEM_WRITE_u32(base, 0x571BF0u, ctx.xmm[0].u32[0]);
	// 0x2B10E0: ret
	return;
}

void sub_2B10F0(X86Context& ctx, uint8_t* base) {
	// 0x2B10F0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B10F8: movss [0x00571AB8], xmm0
	X86_MEM_WRITE_u32(base, 0x571AB8u, ctx.xmm[0].u32[0]);
	// 0x2B1100: ret
	return;
}

void sub_2B1110(X86Context& ctx, uint8_t* base) {
	// 0x2B1110: movss xmm0, dword ptr [0x00571ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ACCu);
	// 0x2B1118: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B1120: movss [0x00571BDC], xmm0
	X86_MEM_WRITE_u32(base, 0x571BDCu, ctx.xmm[0].u32[0]);
	// 0x2B1128: ret
	return;
}

void sub_2B1130(X86Context& ctx, uint8_t* base) {
	// 0x2B1130: movss xmm0, dword ptr [0x00571ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ACCu);
	// 0x2B1138: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B1140: movss [0x00571B28], xmm0
	X86_MEM_WRITE_u32(base, 0x571B28u, ctx.xmm[0].u32[0]);
	// 0x2B1148: ret
	return;
}

void sub_2B1150(X86Context& ctx, uint8_t* base) {
	// 0x2B1150: movss xmm0, dword ptr [0x00571ACC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ACCu);
	// 0x2B1158: subss xmm0, [0x00571B28]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571B28u);
	// 0x2B1160: movss [0x00571AE4], xmm0
	X86_MEM_WRITE_u32(base, 0x571AE4u, ctx.xmm[0].u32[0]);
	// 0x2B1168: ret
	return;
}

void sub_2B1170(X86Context& ctx, uint8_t* base) {
	// 0x2B1170: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B1178: movss [0x00571B80], xmm0
	X86_MEM_WRITE_u32(base, 0x571B80u, ctx.xmm[0].u32[0]);
	// 0x2B1180: ret
	return;
}

void sub_2B1190(X86Context& ctx, uint8_t* base) {
	// 0x2B1190: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B1198: movss [0x00571AD8], xmm0
	X86_MEM_WRITE_u32(base, 0x571AD8u, ctx.xmm[0].u32[0]);
	// 0x2B11A0: ret
	return;
}

void sub_2B11B0(X86Context& ctx, uint8_t* base) {
	// 0x2B11B0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B11B8: movss [0x00571B08], xmm0
	X86_MEM_WRITE_u32(base, 0x571B08u, ctx.xmm[0].u32[0]);
	// 0x2B11C0: ret
	return;
}

void sub_2B11D0(X86Context& ctx, uint8_t* base) {
	// 0x2B11D0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B11D8: movss [0x00571BA8], xmm0
	X86_MEM_WRITE_u32(base, 0x571BA8u, ctx.xmm[0].u32[0]);
	// 0x2B11E0: ret
	return;
}

void sub_2B11F0(X86Context& ctx, uint8_t* base) {
	// 0x2B11F0: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B11F8: movss [0x00571B70], xmm0
	X86_MEM_WRITE_u32(base, 0x571B70u, ctx.xmm[0].u32[0]);
	// 0x2B1200: ret
	return;
}

void sub_2B1210(X86Context& ctx, uint8_t* base) {
	// 0x2B1210: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B1218: movss [0x00571AC8], xmm0
	X86_MEM_WRITE_u32(base, 0x571AC8u, ctx.xmm[0].u32[0]);
	// 0x2B1220: ret
	return;
}

void sub_2B1230(X86Context& ctx, uint8_t* base) {
	// 0x2B1230: movss xmm0, dword ptr [0x00571B08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B08u);
	// 0x2B1238: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B1240: movss [0x00571ABC], xmm0
	X86_MEM_WRITE_u32(base, 0x571ABCu, ctx.xmm[0].u32[0]);
	// 0x2B1248: ret
	return;
}

void sub_2B1250(X86Context& ctx, uint8_t* base) {
	// 0x2B1250: movss xmm0, dword ptr [0x00571BA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BA8u);
	// 0x2B1258: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B1260: movss [0x00571B4C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B4Cu, ctx.xmm[0].u32[0]);
	// 0x2B1268: ret
	return;
}

void sub_2B1270(X86Context& ctx, uint8_t* base) {
	// 0x2B1270: movss xmm0, dword ptr [0x00571ABC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ABCu);
	// 0x2B1278: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B1280: movss [0x00571B5C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B5Cu, ctx.xmm[0].u32[0]);
	// 0x2B1288: ret
	return;
}

void sub_2B1290(X86Context& ctx, uint8_t* base) {
	// 0x2B1290: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B1298: movss [0x00571AB4], xmm0
	X86_MEM_WRITE_u32(base, 0x571AB4u, ctx.xmm[0].u32[0]);
	// 0x2B12A0: ret
	return;
}

void sub_2B12B0(X86Context& ctx, uint8_t* base) {
	// 0x2B12B0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B12B8: movss [0x00571B0C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B0Cu, ctx.xmm[0].u32[0]);
	// 0x2B12C0: ret
	return;
}

void sub_2B12D0(X86Context& ctx, uint8_t* base) {
	// 0x2B12D0: movss xmm0, dword ptr [0x00571B08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B08u);
	// 0x2B12D8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B12E0: movss [0x00571B1C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B1Cu, ctx.xmm[0].u32[0]);
	// 0x2B12E8: ret
	return;
}

void sub_2B12F0(X86Context& ctx, uint8_t* base) {
	// 0x2B12F0: movss xmm0, dword ptr [0x00571BA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BA8u);
	// 0x2B12F8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B1300: movss [0x00571BB4], xmm0
	X86_MEM_WRITE_u32(base, 0x571BB4u, ctx.xmm[0].u32[0]);
	// 0x2B1308: ret
	return;
}

void sub_2B1310(X86Context& ctx, uint8_t* base) {
	// 0x2B1310: movss xmm0, dword ptr [0x00571B1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B1Cu);
	// 0x2B1318: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1320: movss [0x00571B88], xmm0
	X86_MEM_WRITE_u32(base, 0x571B88u, ctx.xmm[0].u32[0]);
	// 0x2B1328: ret
	return;
}

void sub_2B1330(X86Context& ctx, uint8_t* base) {
	// 0x2B1330: movss xmm0, dword ptr [0x00571BB4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BB4u);
	// 0x2B1338: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1340: movss [0x00571BC4], xmm0
	X86_MEM_WRITE_u32(base, 0x571BC4u, ctx.xmm[0].u32[0]);
	// 0x2B1348: ret
	return;
}

void sub_2B1350(X86Context& ctx, uint8_t* base) {
	// 0x2B1350: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B1358: movss [0x00571AC0], xmm0
	X86_MEM_WRITE_u32(base, 0x571AC0u, ctx.xmm[0].u32[0]);
	// 0x2B1360: ret
	return;
}

void sub_2B1370(X86Context& ctx, uint8_t* base) {
	// 0x2B1370: movss xmm0, dword ptr [0x00571B08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B08u);
	// 0x2B1378: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1380: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B1388: movss [0x00571BA0], xmm0
	X86_MEM_WRITE_u32(base, 0x571BA0u, ctx.xmm[0].u32[0]);
	// 0x2B1390: ret
	return;
}

void sub_2B13A0(X86Context& ctx, uint8_t* base) {
	// 0x2B13A0: movss xmm0, dword ptr [0x00571BA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BA8u);
	// 0x2B13A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B13B0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B13B8: movss [0x00571AF0], xmm0
	X86_MEM_WRITE_u32(base, 0x571AF0u, ctx.xmm[0].u32[0]);
	// 0x2B13C0: ret
	return;
}

void sub_2B13D0(X86Context& ctx, uint8_t* base) {
	// 0x2B13D0: movss xmm0, dword ptr [0x00571B08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B08u);
	// 0x2B13D8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B13E0: movss [0x00571AF8], xmm0
	X86_MEM_WRITE_u32(base, 0x571AF8u, ctx.xmm[0].u32[0]);
	// 0x2B13E8: ret
	return;
}

void sub_2B13F0(X86Context& ctx, uint8_t* base) {
	// 0x2B13F0: movss xmm0, dword ptr [0x00571BA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BA8u);
	// 0x2B13F8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1400: movss [0x00571BB8], xmm0
	X86_MEM_WRITE_u32(base, 0x571BB8u, ctx.xmm[0].u32[0]);
	// 0x2B1408: ret
	return;
}

void sub_2B1410(X86Context& ctx, uint8_t* base) {
	// 0x2B1410: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B1418: movss [0x00571AC4], xmm0
	X86_MEM_WRITE_u32(base, 0x571AC4u, ctx.xmm[0].u32[0]);
	// 0x2B1420: ret
	return;
}

void sub_2B1430(X86Context& ctx, uint8_t* base) {
	// 0x2B1430: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B1438: movss [0x00571B18], xmm0
	X86_MEM_WRITE_u32(base, 0x571B18u, ctx.xmm[0].u32[0]);
	// 0x2B1440: ret
	return;
}

void sub_2B1450(X86Context& ctx, uint8_t* base) {
	// 0x2B1450: movss xmm0, dword ptr [0x00571AC4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571AC4u);
	// 0x2B1458: movss [0x00571BE0], xmm0
	X86_MEM_WRITE_u32(base, 0x571BE0u, ctx.xmm[0].u32[0]);
	// 0x2B1460: ret
	return;
}

void sub_2B1470(X86Context& ctx, uint8_t* base) {
	// 0x2B1470: movss xmm0, dword ptr [0x00571BA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BA8u);
	// 0x2B1478: subss xmm0, [0x00571AC4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571AC4u);
	// 0x2B1480: movss [0x00571B68], xmm0
	X86_MEM_WRITE_u32(base, 0x571B68u, ctx.xmm[0].u32[0]);
	// 0x2B1488: ret
	return;
}

void sub_2B1490(X86Context& ctx, uint8_t* base) {
	// 0x2B1490: movss xmm0, dword ptr [0x00571B68]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B68u);
	// 0x2B1498: subss xmm0, [0x00571B18]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571B18u);
	// 0x2B14A0: movss [0x00571B58], xmm0
	X86_MEM_WRITE_u32(base, 0x571B58u, ctx.xmm[0].u32[0]);
	// 0x2B14A8: ret
	return;
}

void sub_2B14B0(X86Context& ctx, uint8_t* base) {
	// 0x2B14B0: movss xmm0, dword ptr [0x00571BB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BB8u);
	// 0x2B14B8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B14C0: movss [0x00571B40], xmm0
	X86_MEM_WRITE_u32(base, 0x571B40u, ctx.xmm[0].u32[0]);
	// 0x2B14C8: ret
	return;
}

void sub_2B14D0(X86Context& ctx, uint8_t* base) {
	// 0x2B14D0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B14D8: movss [0x00571B14], xmm0
	X86_MEM_WRITE_u32(base, 0x571B14u, ctx.xmm[0].u32[0]);
	// 0x2B14E0: ret
	return;
}

void sub_2B14F0(X86Context& ctx, uint8_t* base) {
	// 0x2B14F0: movss xmm0, dword ptr [0x00571B40]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B40u);
	// 0x2B14F8: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B1500: movss [0x00571B90], xmm0
	X86_MEM_WRITE_u32(base, 0x571B90u, ctx.xmm[0].u32[0]);
	// 0x2B1508: ret
	return;
}

void sub_2B1510(X86Context& ctx, uint8_t* base) {
	// 0x2B1510: movss xmm0, dword ptr [0x003A7964]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7964u);
	// 0x2B1518: movss [0x00571B44], xmm0
	X86_MEM_WRITE_u32(base, 0x571B44u, ctx.xmm[0].u32[0]);
	// 0x2B1520: ret
	return;
}

void sub_2B1530(X86Context& ctx, uint8_t* base) {
	// 0x2B1530: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x2B1538: movss [0x00571B04], xmm0
	X86_MEM_WRITE_u32(base, 0x571B04u, ctx.xmm[0].u32[0]);
	// 0x2B1540: ret
	return;
}

void sub_2B1550(X86Context& ctx, uint8_t* base) {
	// 0x2B1550: movss xmm0, dword ptr [0x003B16B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16B8u);
	// 0x2B1558: movss [0x00571AEC], xmm0
	X86_MEM_WRITE_u32(base, 0x571AECu, ctx.xmm[0].u32[0]);
	// 0x2B1560: ret
	return;
}

void sub_2B1570(X86Context& ctx, uint8_t* base) {
	// 0x2B1570: movss xmm0, dword ptr [0x003B1770]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1770u);
	// 0x2B1578: movss [0x00571AAC], xmm0
	X86_MEM_WRITE_u32(base, 0x571AACu, ctx.xmm[0].u32[0]);
	// 0x2B1580: ret
	return;
}

void sub_2B1590(X86Context& ctx, uint8_t* base) {
	// 0x2B1590: movss xmm0, dword ptr [0x003B1F8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F8Cu);
	// 0x2B1598: movss [0x00571AD0], xmm0
	X86_MEM_WRITE_u32(base, 0x571AD0u, ctx.xmm[0].u32[0]);
	// 0x2B15A0: ret
	return;
}

void sub_2B15B0(X86Context& ctx, uint8_t* base) {
	// 0x2B15B0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B15B8: movss [0x00571BA4], xmm0
	X86_MEM_WRITE_u32(base, 0x571BA4u, ctx.xmm[0].u32[0]);
	// 0x2B15C0: ret
	return;
}

void sub_2B15D0(X86Context& ctx, uint8_t* base) {
	// 0x2B15D0: movss xmm0, dword ptr [0x004084B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4084B8u);
	// 0x2B15D8: addss xmm0, [0x00571B44]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571B44u);
	// 0x2B15E0: movss [0x00571AE8], xmm0
	X86_MEM_WRITE_u32(base, 0x571AE8u, ctx.xmm[0].u32[0]);
	// 0x2B15E8: ret
	return;
}

void sub_2B15F0(X86Context& ctx, uint8_t* base) {
	// 0x2B15F0: movss xmm0, dword ptr [0x00571AE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571AE8u);
	// 0x2B15F8: addss xmm0, [0x00571B44]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571B44u);
	// 0x2B1600: mulss xmm0, [0x003B1684]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B1608: movss [0x00571AFC], xmm0
	X86_MEM_WRITE_u32(base, 0x571AFCu, ctx.xmm[0].u32[0]);
	// 0x2B1610: ret
	return;
}

void sub_2B1620(X86Context& ctx, uint8_t* base) {
	// 0x2B1620: movss xmm0, dword ptr [0x004084B8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x4084B8u);
	// 0x2B1628: addss xmm0, [0x00571B44]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571B44u);
	// 0x2B1630: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B1638: movss [0x00571AD4], xmm0
	X86_MEM_WRITE_u32(base, 0x571AD4u, ctx.xmm[0].u32[0]);
	// 0x2B1640: ret
	return;
}

void sub_2B1650(X86Context& ctx, uint8_t* base) {
	// 0x2B1650: movss xmm0, dword ptr [0x00571ABC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571ABCu);
	// 0x2B1658: subss xmm0, [0x00571AD4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571AD4u);
	// 0x2B1660: movss [0x00571B74], xmm0
	X86_MEM_WRITE_u32(base, 0x571B74u, ctx.xmm[0].u32[0]);
	// 0x2B1668: ret
	return;
}

void sub_2B1670(X86Context& ctx, uint8_t* base) {
	// 0x2B1670: movss xmm0, dword ptr [0x00395BF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x395BF0u);
	// 0x2B1678: movss [0x00571B10], xmm0
	X86_MEM_WRITE_u32(base, 0x571B10u, ctx.xmm[0].u32[0]);
	// 0x2B1680: ret
	return;
}

void sub_2B1690(X86Context& ctx, uint8_t* base) {
	// 0x2B1690: movss xmm0, dword ptr [0x00571B74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B74u);
	// 0x2B1698: movss [0x00571BD0], xmm0
	X86_MEM_WRITE_u32(base, 0x571BD0u, ctx.xmm[0].u32[0]);
	// 0x2B16A0: movss xmm0, dword ptr [0x00571B10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B10u);
	// 0x2B16A8: movss [0x00571BD4], xmm0
	X86_MEM_WRITE_u32(base, 0x571BD4u, ctx.xmm[0].u32[0]);
	// 0x2B16B0: ret
	return;
}

void sub_2B16C0(X86Context& ctx, uint8_t* base) {
	// 0x2B16C0: movss xmm0, dword ptr [0x003B2054]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2054u);
	// 0x2B16C8: movss [0x00571B2C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B2Cu, ctx.xmm[0].u32[0]);
	// 0x2B16D0: ret
	return;
}

void sub_2B16E0(X86Context& ctx, uint8_t* base) {
	// 0x2B16E0: movss xmm0, dword ptr [0x00571B74]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B74u);
	// 0x2B16E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B16F0: movss [0x00571BE8], xmm0
	X86_MEM_WRITE_u32(base, 0x571BE8u, ctx.xmm[0].u32[0]);
	// 0x2B16F8: ret
	return;
}

void sub_2B1700(X86Context& ctx, uint8_t* base) {
	// 0x2B1700: movss xmm0, dword ptr [0x00571AD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571AD4u);
	// 0x2B1708: addss xmm0, [0x003B16B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B4u);
	// 0x2B1710: movss [0x00571AA8], xmm0
	X86_MEM_WRITE_u32(base, 0x571AA8u, ctx.xmm[0].u32[0]);
	// 0x2B1718: ret
	return;
}

void sub_2B1720(X86Context& ctx, uint8_t* base) {
	// 0x2B1720: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B1728: mulss xmm0, [0x003B16E8]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B16E8u);
	// 0x2B1730: movss [0x00571BC8], xmm0
	X86_MEM_WRITE_u32(base, 0x571BC8u, ctx.xmm[0].u32[0]);
	// 0x2B1738: ret
	return;
}

void sub_2B1740(X86Context& ctx, uint8_t* base) {
	// 0x2B1740: movss xmm0, dword ptr [0x00571BC8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BC8u);
	// 0x2B1748: addss xmm0, [0x00571AA8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571AA8u);
	// 0x2B1750: movss [0x00571B94], xmm0
	X86_MEM_WRITE_u32(base, 0x571B94u, ctx.xmm[0].u32[0]);
	// 0x2B1758: ret
	return;
}

void sub_2B1760(X86Context& ctx, uint8_t* base) {
	// 0x2B1760: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B1768: mulss xmm0, [0x003B16E8]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B16E8u);
	// 0x2B1770: movss [0x00571B6C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B6Cu, ctx.xmm[0].u32[0]);
	// 0x2B1778: ret
	return;
}

void sub_2B1780(X86Context& ctx, uint8_t* base) {
	// 0x2B1780: movss xmm0, dword ptr [0x00571B6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B6Cu);
	// 0x2B1788: addss xmm0, [0x00571B94]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571B94u);
	// 0x2B1790: movss [0x00571B64], xmm0
	X86_MEM_WRITE_u32(base, 0x571B64u, ctx.xmm[0].u32[0]);
	// 0x2B1798: ret
	return;
}

void sub_2B17A0(X86Context& ctx, uint8_t* base) {
	// 0x2B17A0: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B17A8: mulss xmm0, [0x003B22F0]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B22F0u);
	// 0x2B17B0: movss [0x00571B9C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B9Cu, ctx.xmm[0].u32[0]);
	// 0x2B17B8: ret
	return;
}

void sub_2B17C0(X86Context& ctx, uint8_t* base) {
	// 0x2B17C0: movss xmm0, dword ptr [0x00571AD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571AD4u);
	// 0x2B17C8: addss xmm0, [0x003B16B4]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3B16B4u);
	// 0x2B17D0: movss [0x00571B24], xmm0
	X86_MEM_WRITE_u32(base, 0x571B24u, ctx.xmm[0].u32[0]);
	// 0x2B17D8: ret
	return;
}

void sub_2B17E0(X86Context& ctx, uint8_t* base) {
	// 0x2B17E0: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B17E8: mulss xmm0, [0x003A69C4]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3A69C4u);
	// 0x2B17F0: movss [0x00571AF4], xmm0
	X86_MEM_WRITE_u32(base, 0x571AF4u, ctx.xmm[0].u32[0]);
	// 0x2B17F8: ret
	return;
}

void sub_2B1800(X86Context& ctx, uint8_t* base) {
	// 0x2B1800: movss xmm0, dword ptr [0x00571AF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571AF4u);
	// 0x2B1808: addss xmm0, [0x00571B24]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571B24u);
	// 0x2B1810: movss [0x00571BEC], xmm0
	X86_MEM_WRITE_u32(base, 0x571BECu, ctx.xmm[0].u32[0]);
	// 0x2B1818: ret
	return;
}

void sub_2B1820(X86Context& ctx, uint8_t* base) {
	// 0x2B1820: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B1828: mulss xmm0, [0x003A5600]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3A5600u);
	// 0x2B1830: movss [0x00571BB0], xmm0
	X86_MEM_WRITE_u32(base, 0x571BB0u, ctx.xmm[0].u32[0]);
	// 0x2B1838: ret
	return;
}

void sub_2B1840(X86Context& ctx, uint8_t* base) {
	// 0x2B1840: movss xmm0, dword ptr [0x00571BB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BB0u);
	// 0x2B1848: addss xmm0, [0x00571BEC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571BECu);
	// 0x2B1850: movss [0x00571B34], xmm0
	X86_MEM_WRITE_u32(base, 0x571B34u, ctx.xmm[0].u32[0]);
	// 0x2B1858: ret
	return;
}

void sub_2B1860(X86Context& ctx, uint8_t* base) {
	// 0x2B1860: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B1868: mulss xmm0, [0x003B22F4]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B22F4u);
	// 0x2B1870: movss [0x00571BD8], xmm0
	X86_MEM_WRITE_u32(base, 0x571BD8u, ctx.xmm[0].u32[0]);
	// 0x2B1878: ret
	return;
}

void sub_2B1880(X86Context& ctx, uint8_t* base) {
	// 0x2B1880: movss xmm0, dword ptr [0x00571BE8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571BE8u);
	// 0x2B1888: addss xmm0, [0x003A7F34]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3A7F34u);
	// 0x2B1890: movss [0x00571BE4], xmm0
	X86_MEM_WRITE_u32(base, 0x571BE4u, ctx.xmm[0].u32[0]);
	// 0x2B1898: ret
	return;
}

void sub_2B18A0(X86Context& ctx, uint8_t* base) {
	// 0x2B18A0: movss xmm0, dword ptr [0x003B1750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2B18A8: movss [0x00571B3C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B3Cu, ctx.xmm[0].u32[0]);
	// 0x2B18B0: ret
	return;
}

void sub_2B18C0(X86Context& ctx, uint8_t* base) {
	// 0x2B18C0: movss xmm0, dword ptr [0x003B1768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x2B18C8: movss [0x00571AE0], xmm0
	X86_MEM_WRITE_u32(base, 0x571AE0u, ctx.xmm[0].u32[0]);
	// 0x2B18D0: ret
	return;
}

void sub_2B18E0(X86Context& ctx, uint8_t* base) {
	// 0x2B18E0: movss xmm0, dword ptr [0x003B1750]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1750u);
	// 0x2B18E8: movss [0x00571B98], xmm0
	X86_MEM_WRITE_u32(base, 0x571B98u, ctx.xmm[0].u32[0]);
	// 0x2B18F0: ret
	return;
}

void sub_2B1900(X86Context& ctx, uint8_t* base) {
	// 0x2B1900: movss xmm0, dword ptr [0x003B1768]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1768u);
	// 0x2B1908: movss [0x00571B60], xmm0
	X86_MEM_WRITE_u32(base, 0x571B60u, ctx.xmm[0].u32[0]);
	// 0x2B1910: ret
	return;
}

void sub_2B1920(X86Context& ctx, uint8_t* base) {
	// 0x2B1920: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B1928: divss xmm0, [0x00571B3C]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571B3Cu);
	// 0x2B1930: movss [0x00571B38], xmm0
	X86_MEM_WRITE_u32(base, 0x571B38u, ctx.xmm[0].u32[0]);
	// 0x2B1938: ret
	return;
}

void sub_2B1940(X86Context& ctx, uint8_t* base) {
	// 0x2B1940: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B1948: divss xmm0, [0x00571AE0]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571AE0u);
	// 0x2B1950: movss [0x00571B00], xmm0
	X86_MEM_WRITE_u32(base, 0x571B00u, ctx.xmm[0].u32[0]);
	// 0x2B1958: ret
	return;
}

void sub_2B1960(X86Context& ctx, uint8_t* base) {
	// 0x2B1960: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B1968: divss xmm0, [0x00571B98]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571B98u);
	// 0x2B1970: movss [0x00571B20], xmm0
	X86_MEM_WRITE_u32(base, 0x571B20u, ctx.xmm[0].u32[0]);
	// 0x2B1978: ret
	return;
}

void sub_2B1980(X86Context& ctx, uint8_t* base) {
	// 0x2B1980: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B1988: divss xmm0, [0x00571B60]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x571B60u);
	// 0x2B1990: movss [0x00571BAC], xmm0
	X86_MEM_WRITE_u32(base, 0x571BACu, ctx.xmm[0].u32[0]);
	// 0x2B1998: ret
	return;
}

void sub_2B19A0(X86Context& ctx, uint8_t* base) {
	// 0x2B19A0: movss xmm0, dword ptr [0x00571B3C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B3Cu);
	// 0x2B19A8: movss [0x00571B78], xmm0
	X86_MEM_WRITE_u32(base, 0x571B78u, ctx.xmm[0].u32[0]);
	// 0x2B19B0: ret
	return;
}

void sub_2B19C0(X86Context& ctx, uint8_t* base) {
	// 0x2B19C0: movss xmm0, dword ptr [0x00571AE0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571AE0u);
	// 0x2B19C8: addss xmm0, [0x00571B78]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571B78u);
	// 0x2B19D0: movss [0x00571B7C], xmm0
	X86_MEM_WRITE_u32(base, 0x571B7Cu, ctx.xmm[0].u32[0]);
	// 0x2B19D8: ret
	return;
}

void sub_2B19E0(X86Context& ctx, uint8_t* base) {
	// 0x2B19E0: movss xmm0, dword ptr [0x00571B98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B98u);
	// 0x2B19E8: movss [0x00571ADC], xmm0
	X86_MEM_WRITE_u32(base, 0x571ADCu, ctx.xmm[0].u32[0]);
	// 0x2B19F0: ret
	return;
}

void sub_2B1A00(X86Context& ctx, uint8_t* base) {
	// 0x2B1A00: movss xmm0, dword ptr [0x00571B60]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571B60u);
	// 0x2B1A08: addss xmm0, [0x00571ADC]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x571ADCu);
	// 0x2B1A10: movss [0x00571B48], xmm0
	X86_MEM_WRITE_u32(base, 0x571B48u, ctx.xmm[0].u32[0]);
	// 0x2B1A18: ret
	return;
}

void sub_2B1A20(X86Context& ctx, uint8_t* base) {
	// 0x2B1A20: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B1A28: movss [0x00571C4C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C4Cu, ctx.xmm[0].u32[0]);
	// 0x2B1A30: ret
	return;
}

void sub_2B1A40(X86Context& ctx, uint8_t* base) {
	// 0x2B1A40: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B1A48: movss [0x00571C68], xmm0
	X86_MEM_WRITE_u32(base, 0x571C68u, ctx.xmm[0].u32[0]);
	// 0x2B1A50: ret
	return;
}

void sub_2B1A60(X86Context& ctx, uint8_t* base) {
	// 0x2B1A60: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B1A68: movss [0x00571C40], xmm0
	X86_MEM_WRITE_u32(base, 0x571C40u, ctx.xmm[0].u32[0]);
	// 0x2B1A70: ret
	return;
}

void sub_2B1A80(X86Context& ctx, uint8_t* base) {
	// 0x2B1A80: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B1A88: movss [0x00571BF8], xmm0
	X86_MEM_WRITE_u32(base, 0x571BF8u, ctx.xmm[0].u32[0]);
	// 0x2B1A90: ret
	return;
}

void sub_2B1AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B1AA0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B1AA8: movss [0x00571C50], xmm0
	X86_MEM_WRITE_u32(base, 0x571C50u, ctx.xmm[0].u32[0]);
	// 0x2B1AB0: ret
	return;
}

void sub_2B1AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B1AC0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B1AC8: movss [0x00571C14], xmm0
	X86_MEM_WRITE_u32(base, 0x571C14u, ctx.xmm[0].u32[0]);
	// 0x2B1AD0: ret
	return;
}

void sub_2B1AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B1AE0: movss xmm0, dword ptr [0x00571C50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C50u);
	// 0x2B1AE8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B1AF0: movss [0x00571C88], xmm0
	X86_MEM_WRITE_u32(base, 0x571C88u, ctx.xmm[0].u32[0]);
	// 0x2B1AF8: ret
	return;
}

void sub_2B1B00(X86Context& ctx, uint8_t* base) {
	// 0x2B1B00: movss xmm0, dword ptr [0x00571C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C14u);
	// 0x2B1B08: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B1B10: movss [0x00571C70], xmm0
	X86_MEM_WRITE_u32(base, 0x571C70u, ctx.xmm[0].u32[0]);
	// 0x2B1B18: ret
	return;
}

void sub_2B1B20(X86Context& ctx, uint8_t* base) {
	// 0x2B1B20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B1B28: movss [0x00571CA0], xmm0
	X86_MEM_WRITE_u32(base, 0x571CA0u, ctx.xmm[0].u32[0]);
	// 0x2B1B30: ret
	return;
}

void sub_2B1B40(X86Context& ctx, uint8_t* base) {
	// 0x2B1B40: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B1B48: movss [0x00571C8C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C8Cu, ctx.xmm[0].u32[0]);
	// 0x2B1B50: ret
	return;
}

void sub_2B1B60(X86Context& ctx, uint8_t* base) {
	// 0x2B1B60: movss xmm0, dword ptr [0x00571C8C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C8Cu);
	// 0x2B1B68: movss [0x00571C9C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C9Cu, ctx.xmm[0].u32[0]);
	// 0x2B1B70: ret
	return;
}

void sub_2B1B80(X86Context& ctx, uint8_t* base) {
	// 0x2B1B80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B1B88: movss [0x00571C00], xmm0
	X86_MEM_WRITE_u32(base, 0x571C00u, ctx.xmm[0].u32[0]);
	// 0x2B1B90: ret
	return;
}

void sub_2B1BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B1BA0: movss xmm0, dword ptr [0x00571C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C14u);
	// 0x2B1BA8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B1BB0: movss [0x00571C94], xmm0
	X86_MEM_WRITE_u32(base, 0x571C94u, ctx.xmm[0].u32[0]);
	// 0x2B1BB8: ret
	return;
}

void sub_2B1BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B1BC0: movss xmm0, dword ptr [0x00571C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C14u);
	// 0x2B1BC8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B1BD0: movss [0x00571C3C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C3Cu, ctx.xmm[0].u32[0]);
	// 0x2B1BD8: ret
	return;
}

void sub_2B1BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B1BE0: movss xmm0, dword ptr [0x00571C14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C14u);
	// 0x2B1BE8: subss xmm0, [0x00571C3C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571C3Cu);
	// 0x2B1BF0: movss [0x00571C1C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C1Cu, ctx.xmm[0].u32[0]);
	// 0x2B1BF8: ret
	return;
}

void sub_2B1C00(X86Context& ctx, uint8_t* base) {
	// 0x2B1C00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B1C08: movss [0x00571C64], xmm0
	X86_MEM_WRITE_u32(base, 0x571C64u, ctx.xmm[0].u32[0]);
	// 0x2B1C10: ret
	return;
}

void sub_2B1C20(X86Context& ctx, uint8_t* base) {
	// 0x2B1C20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B1C28: movss [0x00571C18], xmm0
	X86_MEM_WRITE_u32(base, 0x571C18u, ctx.xmm[0].u32[0]);
	// 0x2B1C30: ret
	return;
}

void sub_2B1C40(X86Context& ctx, uint8_t* base) {
	// 0x2B1C40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B1C48: movss [0x00571C28], xmm0
	X86_MEM_WRITE_u32(base, 0x571C28u, ctx.xmm[0].u32[0]);
	// 0x2B1C50: ret
	return;
}

void sub_2B1C60(X86Context& ctx, uint8_t* base) {
	// 0x2B1C60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B1C68: movss [0x00571C7C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C7Cu, ctx.xmm[0].u32[0]);
	// 0x2B1C70: ret
	return;
}

void sub_2B1C80(X86Context& ctx, uint8_t* base) {
	// 0x2B1C80: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B1C88: movss [0x00571C60], xmm0
	X86_MEM_WRITE_u32(base, 0x571C60u, ctx.xmm[0].u32[0]);
	// 0x2B1C90: ret
	return;
}

void sub_2B1CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B1CA0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B1CA8: movss [0x00571C10], xmm0
	X86_MEM_WRITE_u32(base, 0x571C10u, ctx.xmm[0].u32[0]);
	// 0x2B1CB0: ret
	return;
}

void sub_2B1CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B1CC0: movss xmm0, dword ptr [0x00571C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C28u);
	// 0x2B1CC8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B1CD0: movss [0x00571C04], xmm0
	X86_MEM_WRITE_u32(base, 0x571C04u, ctx.xmm[0].u32[0]);
	// 0x2B1CD8: ret
	return;
}

void sub_2B1CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B1CE0: movss xmm0, dword ptr [0x00571C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C7Cu);
	// 0x2B1CE8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B1CF0: movss [0x00571C48], xmm0
	X86_MEM_WRITE_u32(base, 0x571C48u, ctx.xmm[0].u32[0]);
	// 0x2B1CF8: ret
	return;
}

void sub_2B1D00(X86Context& ctx, uint8_t* base) {
	// 0x2B1D00: movss xmm0, dword ptr [0x00571C04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C04u);
	// 0x2B1D08: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B1D10: movss [0x00571C58], xmm0
	X86_MEM_WRITE_u32(base, 0x571C58u, ctx.xmm[0].u32[0]);
	// 0x2B1D18: ret
	return;
}

void sub_2B1D20(X86Context& ctx, uint8_t* base) {
	// 0x2B1D20: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B1D28: movss [0x00571BFC], xmm0
	X86_MEM_WRITE_u32(base, 0x571BFCu, ctx.xmm[0].u32[0]);
	// 0x2B1D30: ret
	return;
}

void sub_2B1D40(X86Context& ctx, uint8_t* base) {
	// 0x2B1D40: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B1D48: movss [0x00571C2C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C2Cu, ctx.xmm[0].u32[0]);
	// 0x2B1D50: ret
	return;
}

void sub_2B1D60(X86Context& ctx, uint8_t* base) {
	// 0x2B1D60: movss xmm0, dword ptr [0x00571C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C28u);
	// 0x2B1D68: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B1D70: movss [0x00571C38], xmm0
	X86_MEM_WRITE_u32(base, 0x571C38u, ctx.xmm[0].u32[0]);
	// 0x2B1D78: ret
	return;
}

void sub_2B1D80(X86Context& ctx, uint8_t* base) {
	// 0x2B1D80: movss xmm0, dword ptr [0x00571C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C7Cu);
	// 0x2B1D88: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B1D90: movss [0x00571C80], xmm0
	X86_MEM_WRITE_u32(base, 0x571C80u, ctx.xmm[0].u32[0]);
	// 0x2B1D98: ret
	return;
}

void sub_2B1DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B1DA0: movss xmm0, dword ptr [0x00571C38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C38u);
	// 0x2B1DA8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1DB0: movss [0x00571C6C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C6Cu, ctx.xmm[0].u32[0]);
	// 0x2B1DB8: ret
	return;
}

void sub_2B1DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B1DC0: movss xmm0, dword ptr [0x00571C80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C80u);
	// 0x2B1DC8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1DD0: movss [0x00571C90], xmm0
	X86_MEM_WRITE_u32(base, 0x571C90u, ctx.xmm[0].u32[0]);
	// 0x2B1DD8: ret
	return;
}

void sub_2B1DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B1DE0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B1DE8: movss [0x00571C08], xmm0
	X86_MEM_WRITE_u32(base, 0x571C08u, ctx.xmm[0].u32[0]);
	// 0x2B1DF0: ret
	return;
}

void sub_2B1E00(X86Context& ctx, uint8_t* base) {
	// 0x2B1E00: movss xmm0, dword ptr [0x00571C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C28u);
	// 0x2B1E08: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1E10: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B1E18: movss [0x00571C78], xmm0
	X86_MEM_WRITE_u32(base, 0x571C78u, ctx.xmm[0].u32[0]);
	// 0x2B1E20: ret
	return;
}

void sub_2B1E30(X86Context& ctx, uint8_t* base) {
	// 0x2B1E30: movss xmm0, dword ptr [0x00571C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C7Cu);
	// 0x2B1E38: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1E40: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B1E48: movss [0x00571C20], xmm0
	X86_MEM_WRITE_u32(base, 0x571C20u, ctx.xmm[0].u32[0]);
	// 0x2B1E50: ret
	return;
}

void sub_2B1E60(X86Context& ctx, uint8_t* base) {
	// 0x2B1E60: movss xmm0, dword ptr [0x00571C28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C28u);
	// 0x2B1E68: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1E70: movss [0x00571C24], xmm0
	X86_MEM_WRITE_u32(base, 0x571C24u, ctx.xmm[0].u32[0]);
	// 0x2B1E78: ret
	return;
}

void sub_2B1E80(X86Context& ctx, uint8_t* base) {
	// 0x2B1E80: movss xmm0, dword ptr [0x00571C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C7Cu);
	// 0x2B1E88: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B1E90: movss [0x00571C84], xmm0
	X86_MEM_WRITE_u32(base, 0x571C84u, ctx.xmm[0].u32[0]);
	// 0x2B1E98: ret
	return;
}

void sub_2B1EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B1EA0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B1EA8: movss [0x00571C0C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C0Cu, ctx.xmm[0].u32[0]);
	// 0x2B1EB0: ret
	return;
}

void sub_2B1EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B1EC0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B1EC8: movss [0x00571C34], xmm0
	X86_MEM_WRITE_u32(base, 0x571C34u, ctx.xmm[0].u32[0]);
	// 0x2B1ED0: ret
	return;
}

void sub_2B1EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B1EE0: movss xmm0, dword ptr [0x00571C0C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C0Cu);
	// 0x2B1EE8: movss [0x00571C98], xmm0
	X86_MEM_WRITE_u32(base, 0x571C98u, ctx.xmm[0].u32[0]);
	// 0x2B1EF0: ret
	return;
}

void sub_2B1F00(X86Context& ctx, uint8_t* base) {
	// 0x2B1F00: movss xmm0, dword ptr [0x00571C7C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C7Cu);
	// 0x2B1F08: subss xmm0, [0x00571C0C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571C0Cu);
	// 0x2B1F10: movss [0x00571C5C], xmm0
	X86_MEM_WRITE_u32(base, 0x571C5Cu, ctx.xmm[0].u32[0]);
	// 0x2B1F18: ret
	return;
}

void sub_2B1F20(X86Context& ctx, uint8_t* base) {
	// 0x2B1F20: movss xmm0, dword ptr [0x00571C5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C5Cu);
	// 0x2B1F28: subss xmm0, [0x00571C34]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571C34u);
	// 0x2B1F30: movss [0x00571C54], xmm0
	X86_MEM_WRITE_u32(base, 0x571C54u, ctx.xmm[0].u32[0]);
	// 0x2B1F38: ret
	return;
}

void sub_2B1F40(X86Context& ctx, uint8_t* base) {
	// 0x2B1F40: movss xmm0, dword ptr [0x00571C84]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C84u);
	// 0x2B1F48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B1F50: movss [0x00571C44], xmm0
	X86_MEM_WRITE_u32(base, 0x571C44u, ctx.xmm[0].u32[0]);
	// 0x2B1F58: ret
	return;
}

void sub_2B1F60(X86Context& ctx, uint8_t* base) {
	// 0x2B1F60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B1F68: movss [0x00571C30], xmm0
	X86_MEM_WRITE_u32(base, 0x571C30u, ctx.xmm[0].u32[0]);
	// 0x2B1F70: ret
	return;
}

void sub_2B1F80(X86Context& ctx, uint8_t* base) {
	// 0x2B1F80: movss xmm0, dword ptr [0x00571C44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571C44u);
	// 0x2B1F88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B1F90: movss [0x00571C74], xmm0
	X86_MEM_WRITE_u32(base, 0x571C74u, ctx.xmm[0].u32[0]);
	// 0x2B1F98: ret
	return;
}

void sub_2B1FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B1FA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B1FA8: movss [0x00571CF8], xmm0
	X86_MEM_WRITE_u32(base, 0x571CF8u, ctx.xmm[0].u32[0]);
	// 0x2B1FB0: ret
	return;
}

void sub_2B1FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B1FC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B1FC8: movss [0x00571D14], xmm0
	X86_MEM_WRITE_u32(base, 0x571D14u, ctx.xmm[0].u32[0]);
	// 0x2B1FD0: ret
	return;
}

void sub_2B1FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B1FE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B1FE8: movss [0x00571CEC], xmm0
	X86_MEM_WRITE_u32(base, 0x571CECu, ctx.xmm[0].u32[0]);
	// 0x2B1FF0: ret
	return;
}

void sub_2B2000(X86Context& ctx, uint8_t* base) {
	// 0x2B2000: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B2008: movss [0x00571CA4], xmm0
	X86_MEM_WRITE_u32(base, 0x571CA4u, ctx.xmm[0].u32[0]);
	// 0x2B2010: ret
	return;
}

void sub_2B2020(X86Context& ctx, uint8_t* base) {
	// 0x2B2020: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B2028: movss [0x00571CFC], xmm0
	X86_MEM_WRITE_u32(base, 0x571CFCu, ctx.xmm[0].u32[0]);
	// 0x2B2030: ret
	return;
}

void sub_2B2040(X86Context& ctx, uint8_t* base) {
	// 0x2B2040: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B2048: movss [0x00571CC0], xmm0
	X86_MEM_WRITE_u32(base, 0x571CC0u, ctx.xmm[0].u32[0]);
	// 0x2B2050: ret
	return;
}

void sub_2B2060(X86Context& ctx, uint8_t* base) {
	// 0x2B2060: movss xmm0, dword ptr [0x00571CFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CFCu);
	// 0x2B2068: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2070: movss [0x00571D34], xmm0
	X86_MEM_WRITE_u32(base, 0x571D34u, ctx.xmm[0].u32[0]);
	// 0x2B2078: ret
	return;
}

void sub_2B2080(X86Context& ctx, uint8_t* base) {
	// 0x2B2080: movss xmm0, dword ptr [0x00571CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CC0u);
	// 0x2B2088: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B2090: movss [0x00571D1C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D1Cu, ctx.xmm[0].u32[0]);
	// 0x2B2098: ret
	return;
}

void sub_2B20A0(X86Context& ctx, uint8_t* base) {
	// 0x2B20A0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B20A8: movss [0x00571D4C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D4Cu, ctx.xmm[0].u32[0]);
	// 0x2B20B0: ret
	return;
}

void sub_2B20C0(X86Context& ctx, uint8_t* base) {
	// 0x2B20C0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B20C8: movss [0x00571D38], xmm0
	X86_MEM_WRITE_u32(base, 0x571D38u, ctx.xmm[0].u32[0]);
	// 0x2B20D0: ret
	return;
}

void sub_2B20E0(X86Context& ctx, uint8_t* base) {
	// 0x2B20E0: movss xmm0, dword ptr [0x00571D38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D38u);
	// 0x2B20E8: movss [0x00571D48], xmm0
	X86_MEM_WRITE_u32(base, 0x571D48u, ctx.xmm[0].u32[0]);
	// 0x2B20F0: ret
	return;
}

void sub_2B2100(X86Context& ctx, uint8_t* base) {
	// 0x2B2100: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B2108: movss [0x00571CAC], xmm0
	X86_MEM_WRITE_u32(base, 0x571CACu, ctx.xmm[0].u32[0]);
	// 0x2B2110: ret
	return;
}

void sub_2B2120(X86Context& ctx, uint8_t* base) {
	// 0x2B2120: movss xmm0, dword ptr [0x00571CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CC0u);
	// 0x2B2128: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B2130: movss [0x00571D40], xmm0
	X86_MEM_WRITE_u32(base, 0x571D40u, ctx.xmm[0].u32[0]);
	// 0x2B2138: ret
	return;
}

void sub_2B2140(X86Context& ctx, uint8_t* base) {
	// 0x2B2140: movss xmm0, dword ptr [0x00571CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CC0u);
	// 0x2B2148: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B2150: movss [0x00571CE8], xmm0
	X86_MEM_WRITE_u32(base, 0x571CE8u, ctx.xmm[0].u32[0]);
	// 0x2B2158: ret
	return;
}

void sub_2B2160(X86Context& ctx, uint8_t* base) {
	// 0x2B2160: movss xmm0, dword ptr [0x00571CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CC0u);
	// 0x2B2168: subss xmm0, [0x00571CE8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571CE8u);
	// 0x2B2170: movss [0x00571CC8], xmm0
	X86_MEM_WRITE_u32(base, 0x571CC8u, ctx.xmm[0].u32[0]);
	// 0x2B2178: ret
	return;
}

void sub_2B2180(X86Context& ctx, uint8_t* base) {
	// 0x2B2180: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B2188: movss [0x00571D10], xmm0
	X86_MEM_WRITE_u32(base, 0x571D10u, ctx.xmm[0].u32[0]);
	// 0x2B2190: ret
	return;
}

void sub_2B21A0(X86Context& ctx, uint8_t* base) {
	// 0x2B21A0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B21A8: movss [0x00571CC4], xmm0
	X86_MEM_WRITE_u32(base, 0x571CC4u, ctx.xmm[0].u32[0]);
	// 0x2B21B0: ret
	return;
}

void sub_2B21C0(X86Context& ctx, uint8_t* base) {
	// 0x2B21C0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B21C8: movss [0x00571CD4], xmm0
	X86_MEM_WRITE_u32(base, 0x571CD4u, ctx.xmm[0].u32[0]);
	// 0x2B21D0: ret
	return;
}

void sub_2B21E0(X86Context& ctx, uint8_t* base) {
	// 0x2B21E0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B21E8: movss [0x00571D28], xmm0
	X86_MEM_WRITE_u32(base, 0x571D28u, ctx.xmm[0].u32[0]);
	// 0x2B21F0: ret
	return;
}

void sub_2B2200(X86Context& ctx, uint8_t* base) {
	// 0x2B2200: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B2208: movss [0x00571D0C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D0Cu, ctx.xmm[0].u32[0]);
	// 0x2B2210: ret
	return;
}

void sub_2B2220(X86Context& ctx, uint8_t* base) {
	// 0x2B2220: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B2228: movss [0x00571CBC], xmm0
	X86_MEM_WRITE_u32(base, 0x571CBCu, ctx.xmm[0].u32[0]);
	// 0x2B2230: ret
	return;
}

void sub_2B2240(X86Context& ctx, uint8_t* base) {
	// 0x2B2240: movss xmm0, dword ptr [0x00571CD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CD4u);
	// 0x2B2248: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2250: movss [0x00571CB0], xmm0
	X86_MEM_WRITE_u32(base, 0x571CB0u, ctx.xmm[0].u32[0]);
	// 0x2B2258: ret
	return;
}

void sub_2B2260(X86Context& ctx, uint8_t* base) {
	// 0x2B2260: movss xmm0, dword ptr [0x00571D28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D28u);
	// 0x2B2268: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B2270: movss [0x00571CF4], xmm0
	X86_MEM_WRITE_u32(base, 0x571CF4u, ctx.xmm[0].u32[0]);
	// 0x2B2278: ret
	return;
}

void sub_2B2280(X86Context& ctx, uint8_t* base) {
	// 0x2B2280: movss xmm0, dword ptr [0x00571CB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CB0u);
	// 0x2B2288: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2290: movss [0x00571D04], xmm0
	X86_MEM_WRITE_u32(base, 0x571D04u, ctx.xmm[0].u32[0]);
	// 0x2B2298: ret
	return;
}

void sub_2B22A0(X86Context& ctx, uint8_t* base) {
	// 0x2B22A0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B22A8: movss [0x00571CA8], xmm0
	X86_MEM_WRITE_u32(base, 0x571CA8u, ctx.xmm[0].u32[0]);
	// 0x2B22B0: ret
	return;
}

void sub_2B22C0(X86Context& ctx, uint8_t* base) {
	// 0x2B22C0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B22C8: movss [0x00571CD8], xmm0
	X86_MEM_WRITE_u32(base, 0x571CD8u, ctx.xmm[0].u32[0]);
	// 0x2B22D0: ret
	return;
}

void sub_2B22E0(X86Context& ctx, uint8_t* base) {
	// 0x2B22E0: movss xmm0, dword ptr [0x00571CD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CD4u);
	// 0x2B22E8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B22F0: movss [0x00571CE4], xmm0
	X86_MEM_WRITE_u32(base, 0x571CE4u, ctx.xmm[0].u32[0]);
	// 0x2B22F8: ret
	return;
}

void sub_2B2300(X86Context& ctx, uint8_t* base) {
	// 0x2B2300: movss xmm0, dword ptr [0x00571D28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D28u);
	// 0x2B2308: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B2310: movss [0x00571D2C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D2Cu, ctx.xmm[0].u32[0]);
	// 0x2B2318: ret
	return;
}

void sub_2B2320(X86Context& ctx, uint8_t* base) {
	// 0x2B2320: movss xmm0, dword ptr [0x00571CE4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CE4u);
	// 0x2B2328: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2330: movss [0x00571D18], xmm0
	X86_MEM_WRITE_u32(base, 0x571D18u, ctx.xmm[0].u32[0]);
	// 0x2B2338: ret
	return;
}

void sub_2B2340(X86Context& ctx, uint8_t* base) {
	// 0x2B2340: movss xmm0, dword ptr [0x00571D2C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D2Cu);
	// 0x2B2348: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2350: movss [0x00571D3C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D3Cu, ctx.xmm[0].u32[0]);
	// 0x2B2358: ret
	return;
}

void sub_2B2360(X86Context& ctx, uint8_t* base) {
	// 0x2B2360: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B2368: movss [0x00571CB4], xmm0
	X86_MEM_WRITE_u32(base, 0x571CB4u, ctx.xmm[0].u32[0]);
	// 0x2B2370: ret
	return;
}

void sub_2B2380(X86Context& ctx, uint8_t* base) {
	// 0x2B2380: movss xmm0, dword ptr [0x00571CD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CD4u);
	// 0x2B2388: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2390: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B2398: movss [0x00571D24], xmm0
	X86_MEM_WRITE_u32(base, 0x571D24u, ctx.xmm[0].u32[0]);
	// 0x2B23A0: ret
	return;
}

void sub_2B23B0(X86Context& ctx, uint8_t* base) {
	// 0x2B23B0: movss xmm0, dword ptr [0x00571D28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D28u);
	// 0x2B23B8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B23C0: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B23C8: movss [0x00571CCC], xmm0
	X86_MEM_WRITE_u32(base, 0x571CCCu, ctx.xmm[0].u32[0]);
	// 0x2B23D0: ret
	return;
}

void sub_2B23E0(X86Context& ctx, uint8_t* base) {
	// 0x2B23E0: movss xmm0, dword ptr [0x00571CD4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CD4u);
	// 0x2B23E8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B23F0: movss [0x00571CD0], xmm0
	X86_MEM_WRITE_u32(base, 0x571CD0u, ctx.xmm[0].u32[0]);
	// 0x2B23F8: ret
	return;
}

void sub_2B2400(X86Context& ctx, uint8_t* base) {
	// 0x2B2400: movss xmm0, dword ptr [0x00571D28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D28u);
	// 0x2B2408: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2410: movss [0x00571D30], xmm0
	X86_MEM_WRITE_u32(base, 0x571D30u, ctx.xmm[0].u32[0]);
	// 0x2B2418: ret
	return;
}

void sub_2B2420(X86Context& ctx, uint8_t* base) {
	// 0x2B2420: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B2428: movss [0x00571CB8], xmm0
	X86_MEM_WRITE_u32(base, 0x571CB8u, ctx.xmm[0].u32[0]);
	// 0x2B2430: ret
	return;
}

void sub_2B2440(X86Context& ctx, uint8_t* base) {
	// 0x2B2440: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B2448: movss [0x00571CE0], xmm0
	X86_MEM_WRITE_u32(base, 0x571CE0u, ctx.xmm[0].u32[0]);
	// 0x2B2450: ret
	return;
}

void sub_2B2460(X86Context& ctx, uint8_t* base) {
	// 0x2B2460: movss xmm0, dword ptr [0x00571CB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CB8u);
	// 0x2B2468: movss [0x00571D44], xmm0
	X86_MEM_WRITE_u32(base, 0x571D44u, ctx.xmm[0].u32[0]);
	// 0x2B2470: ret
	return;
}

void sub_2B2480(X86Context& ctx, uint8_t* base) {
	// 0x2B2480: movss xmm0, dword ptr [0x00571D28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D28u);
	// 0x2B2488: subss xmm0, [0x00571CB8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571CB8u);
	// 0x2B2490: movss [0x00571D08], xmm0
	X86_MEM_WRITE_u32(base, 0x571D08u, ctx.xmm[0].u32[0]);
	// 0x2B2498: ret
	return;
}

void sub_2B24A0(X86Context& ctx, uint8_t* base) {
	// 0x2B24A0: movss xmm0, dword ptr [0x00571D08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D08u);
	// 0x2B24A8: subss xmm0, [0x00571CE0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571CE0u);
	// 0x2B24B0: movss [0x00571D00], xmm0
	X86_MEM_WRITE_u32(base, 0x571D00u, ctx.xmm[0].u32[0]);
	// 0x2B24B8: ret
	return;
}

void sub_2B24C0(X86Context& ctx, uint8_t* base) {
	// 0x2B24C0: movss xmm0, dword ptr [0x00571D30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D30u);
	// 0x2B24C8: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B24D0: movss [0x00571CF0], xmm0
	X86_MEM_WRITE_u32(base, 0x571CF0u, ctx.xmm[0].u32[0]);
	// 0x2B24D8: ret
	return;
}

void sub_2B24E0(X86Context& ctx, uint8_t* base) {
	// 0x2B24E0: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B24E8: movss [0x00571CDC], xmm0
	X86_MEM_WRITE_u32(base, 0x571CDCu, ctx.xmm[0].u32[0]);
	// 0x2B24F0: ret
	return;
}

void sub_2B2500(X86Context& ctx, uint8_t* base) {
	// 0x2B2500: movss xmm0, dword ptr [0x00571CF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571CF0u);
	// 0x2B2508: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B2510: movss [0x00571D20], xmm0
	X86_MEM_WRITE_u32(base, 0x571D20u, ctx.xmm[0].u32[0]);
	// 0x2B2518: ret
	return;
}

void sub_2B2520(X86Context& ctx, uint8_t* base) {
	// 0x2B2520: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B2528: movss [0x00571DBC], xmm0
	X86_MEM_WRITE_u32(base, 0x571DBCu, ctx.xmm[0].u32[0]);
	// 0x2B2530: ret
	return;
}

void sub_2B2540(X86Context& ctx, uint8_t* base) {
	// 0x2B2540: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B2548: movss [0x00571DD8], xmm0
	X86_MEM_WRITE_u32(base, 0x571DD8u, ctx.xmm[0].u32[0]);
	// 0x2B2550: ret
	return;
}

void sub_2B2560(X86Context& ctx, uint8_t* base) {
	// 0x2B2560: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B2568: movss [0x00571D98], xmm0
	X86_MEM_WRITE_u32(base, 0x571D98u, ctx.xmm[0].u32[0]);
	// 0x2B2570: ret
	return;
}

void sub_2B2580(X86Context& ctx, uint8_t* base) {
	// 0x2B2580: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B2588: movss [0x00571D50], xmm0
	X86_MEM_WRITE_u32(base, 0x571D50u, ctx.xmm[0].u32[0]);
	// 0x2B2590: ret
	return;
}

void sub_2B25A0(X86Context& ctx, uint8_t* base) {
	// 0x2B25A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B25A8: movss [0x00571DC0], xmm0
	X86_MEM_WRITE_u32(base, 0x571DC0u, ctx.xmm[0].u32[0]);
	// 0x2B25B0: ret
	return;
}

void sub_2B25C0(X86Context& ctx, uint8_t* base) {
	// 0x2B25C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B25C8: movss [0x00571D6C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D6Cu, ctx.xmm[0].u32[0]);
	// 0x2B25D0: ret
	return;
}

void sub_2B25E0(X86Context& ctx, uint8_t* base) {
	// 0x2B25E0: movss xmm0, dword ptr [0x00571DC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DC0u);
	// 0x2B25E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B25F0: movss [0x00571DF8], xmm0
	X86_MEM_WRITE_u32(base, 0x571DF8u, ctx.xmm[0].u32[0]);
	// 0x2B25F8: ret
	return;
}

void sub_2B2600(X86Context& ctx, uint8_t* base) {
	// 0x2B2600: movss xmm0, dword ptr [0x00571D6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D6Cu);
	// 0x2B2608: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B2610: movss [0x00571DE0], xmm0
	X86_MEM_WRITE_u32(base, 0x571DE0u, ctx.xmm[0].u32[0]);
	// 0x2B2618: ret
	return;
}

void sub_2B2620(X86Context& ctx, uint8_t* base) {
	// 0x2B2620: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B2628: movss [0x00571E10], xmm0
	X86_MEM_WRITE_u32(base, 0x571E10u, ctx.xmm[0].u32[0]);
	// 0x2B2630: ret
	return;
}

void sub_2B2640(X86Context& ctx, uint8_t* base) {
	// 0x2B2640: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B2648: movss [0x00571DFC], xmm0
	X86_MEM_WRITE_u32(base, 0x571DFCu, ctx.xmm[0].u32[0]);
	// 0x2B2650: ret
	return;
}

void sub_2B2660(X86Context& ctx, uint8_t* base) {
	// 0x2B2660: movss xmm0, dword ptr [0x00571DFC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DFCu);
	// 0x2B2668: movss [0x00571E0C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E0Cu, ctx.xmm[0].u32[0]);
	// 0x2B2670: ret
	return;
}

void sub_2B2680(X86Context& ctx, uint8_t* base) {
	// 0x2B2680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B2688: movss [0x00571D58], xmm0
	X86_MEM_WRITE_u32(base, 0x571D58u, ctx.xmm[0].u32[0]);
	// 0x2B2690: ret
	return;
}

void sub_2B26A0(X86Context& ctx, uint8_t* base) {
	// 0x2B26A0: movss xmm0, dword ptr [0x00571D6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D6Cu);
	// 0x2B26A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B26B0: movss [0x00571E04], xmm0
	X86_MEM_WRITE_u32(base, 0x571E04u, ctx.xmm[0].u32[0]);
	// 0x2B26B8: ret
	return;
}

void sub_2B26C0(X86Context& ctx, uint8_t* base) {
	// 0x2B26C0: movss xmm0, dword ptr [0x00571D6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D6Cu);
	// 0x2B26C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B26D0: movss [0x00571D94], xmm0
	X86_MEM_WRITE_u32(base, 0x571D94u, ctx.xmm[0].u32[0]);
	// 0x2B26D8: ret
	return;
}

void sub_2B26E0(X86Context& ctx, uint8_t* base) {
	// 0x2B26E0: movss xmm0, dword ptr [0x00571D6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D6Cu);
	// 0x2B26E8: subss xmm0, [0x00571D94]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571D94u);
	// 0x2B26F0: movss [0x00571D74], xmm0
	X86_MEM_WRITE_u32(base, 0x571D74u, ctx.xmm[0].u32[0]);
	// 0x2B26F8: ret
	return;
}

void sub_2B2700(X86Context& ctx, uint8_t* base) {
	// 0x2B2700: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B2708: movss [0x00571DD4], xmm0
	X86_MEM_WRITE_u32(base, 0x571DD4u, ctx.xmm[0].u32[0]);
	// 0x2B2710: ret
	return;
}

void sub_2B2720(X86Context& ctx, uint8_t* base) {
	// 0x2B2720: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B2728: movss [0x00571D70], xmm0
	X86_MEM_WRITE_u32(base, 0x571D70u, ctx.xmm[0].u32[0]);
	// 0x2B2730: ret
	return;
}

void sub_2B2740(X86Context& ctx, uint8_t* base) {
	// 0x2B2740: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B2748: movss [0x00571D80], xmm0
	X86_MEM_WRITE_u32(base, 0x571D80u, ctx.xmm[0].u32[0]);
	// 0x2B2750: ret
	return;
}

void sub_2B2760(X86Context& ctx, uint8_t* base) {
	// 0x2B2760: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B2768: movss [0x00571DEC], xmm0
	X86_MEM_WRITE_u32(base, 0x571DECu, ctx.xmm[0].u32[0]);
	// 0x2B2770: ret
	return;
}

void sub_2B2780(X86Context& ctx, uint8_t* base) {
	// 0x2B2780: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B2788: movss [0x00571DD0], xmm0
	X86_MEM_WRITE_u32(base, 0x571DD0u, ctx.xmm[0].u32[0]);
	// 0x2B2790: ret
	return;
}

void sub_2B27A0(X86Context& ctx, uint8_t* base) {
	// 0x2B27A0: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B27A8: movss [0x00571D68], xmm0
	X86_MEM_WRITE_u32(base, 0x571D68u, ctx.xmm[0].u32[0]);
	// 0x2B27B0: ret
	return;
}

void sub_2B27C0(X86Context& ctx, uint8_t* base) {
	// 0x2B27C0: movss xmm0, dword ptr [0x00571D80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D80u);
	// 0x2B27C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B27D0: movss [0x00571D5C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D5Cu, ctx.xmm[0].u32[0]);
	// 0x2B27D8: ret
	return;
}

void sub_2B27E0(X86Context& ctx, uint8_t* base) {
	// 0x2B27E0: movss xmm0, dword ptr [0x00571DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DECu);
	// 0x2B27E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B27F0: movss [0x00571DB8], xmm0
	X86_MEM_WRITE_u32(base, 0x571DB8u, ctx.xmm[0].u32[0]);
	// 0x2B27F8: ret
	return;
}

void sub_2B2800(X86Context& ctx, uint8_t* base) {
	// 0x2B2800: movss xmm0, dword ptr [0x00571D5C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D5Cu);
	// 0x2B2808: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2810: movss [0x00571DC8], xmm0
	X86_MEM_WRITE_u32(base, 0x571DC8u, ctx.xmm[0].u32[0]);
	// 0x2B2818: ret
	return;
}

void sub_2B2820(X86Context& ctx, uint8_t* base) {
	// 0x2B2820: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B2828: movss [0x00571D54], xmm0
	X86_MEM_WRITE_u32(base, 0x571D54u, ctx.xmm[0].u32[0]);
	// 0x2B2830: ret
	return;
}

void sub_2B2840(X86Context& ctx, uint8_t* base) {
	// 0x2B2840: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B2848: movss [0x00571D84], xmm0
	X86_MEM_WRITE_u32(base, 0x571D84u, ctx.xmm[0].u32[0]);
	// 0x2B2850: ret
	return;
}

void sub_2B2860(X86Context& ctx, uint8_t* base) {
	// 0x2B2860: movss xmm0, dword ptr [0x00571D80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D80u);
	// 0x2B2868: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B2870: movss [0x00571D90], xmm0
	X86_MEM_WRITE_u32(base, 0x571D90u, ctx.xmm[0].u32[0]);
	// 0x2B2878: ret
	return;
}

void sub_2B2880(X86Context& ctx, uint8_t* base) {
	// 0x2B2880: movss xmm0, dword ptr [0x00571DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DECu);
	// 0x2B2888: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B2890: movss [0x00571DF0], xmm0
	X86_MEM_WRITE_u32(base, 0x571DF0u, ctx.xmm[0].u32[0]);
	// 0x2B2898: ret
	return;
}

void sub_2B28A0(X86Context& ctx, uint8_t* base) {
	// 0x2B28A0: movss xmm0, dword ptr [0x00571D90]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D90u);
	// 0x2B28A8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B28B0: movss [0x00571DDC], xmm0
	X86_MEM_WRITE_u32(base, 0x571DDCu, ctx.xmm[0].u32[0]);
	// 0x2B28B8: ret
	return;
}

void sub_2B28C0(X86Context& ctx, uint8_t* base) {
	// 0x2B28C0: movss xmm0, dword ptr [0x00571DF0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DF0u);
	// 0x2B28C8: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B28D0: movss [0x00571E00], xmm0
	X86_MEM_WRITE_u32(base, 0x571E00u, ctx.xmm[0].u32[0]);
	// 0x2B28D8: ret
	return;
}

void sub_2B28E0(X86Context& ctx, uint8_t* base) {
	// 0x2B28E0: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B28E8: movss [0x00571D60], xmm0
	X86_MEM_WRITE_u32(base, 0x571D60u, ctx.xmm[0].u32[0]);
	// 0x2B28F0: ret
	return;
}

void sub_2B2900(X86Context& ctx, uint8_t* base) {
	// 0x2B2900: movss xmm0, dword ptr [0x00571D80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D80u);
	// 0x2B2908: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2910: mulss xmm0, [0x003B1A90]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1A90u);
	// 0x2B2918: movss [0x00571DE8], xmm0
	X86_MEM_WRITE_u32(base, 0x571DE8u, ctx.xmm[0].u32[0]);
	// 0x2B2920: ret
	return;
}

void sub_2B2930(X86Context& ctx, uint8_t* base) {
	// 0x2B2930: movss xmm0, dword ptr [0x00571DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DECu);
	// 0x2B2938: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2940: mulss xmm0, [0x003B1C30]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C30u);
	// 0x2B2948: movss [0x00571D78], xmm0
	X86_MEM_WRITE_u32(base, 0x571D78u, ctx.xmm[0].u32[0]);
	// 0x2B2950: ret
	return;
}

void sub_2B2960(X86Context& ctx, uint8_t* base) {
	// 0x2B2960: movss xmm0, dword ptr [0x00571D80]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D80u);
	// 0x2B2968: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2970: movss [0x00571D7C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D7Cu, ctx.xmm[0].u32[0]);
	// 0x2B2978: ret
	return;
}

void sub_2B2980(X86Context& ctx, uint8_t* base) {
	// 0x2B2980: movss xmm0, dword ptr [0x00571DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DECu);
	// 0x2B2988: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2990: movss [0x00571DF4], xmm0
	X86_MEM_WRITE_u32(base, 0x571DF4u, ctx.xmm[0].u32[0]);
	// 0x2B2998: ret
	return;
}

void sub_2B29A0(X86Context& ctx, uint8_t* base) {
	// 0x2B29A0: movss xmm0, dword ptr [0x0035BF1C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x35BF1Cu);
	// 0x2B29A8: movss [0x00571D64], xmm0
	X86_MEM_WRITE_u32(base, 0x571D64u, ctx.xmm[0].u32[0]);
	// 0x2B29B0: ret
	return;
}

void sub_2B29C0(X86Context& ctx, uint8_t* base) {
	// 0x2B29C0: movss xmm0, dword ptr [0x003B17C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B29C8: movss [0x00571D8C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D8Cu, ctx.xmm[0].u32[0]);
	// 0x2B29D0: ret
	return;
}

void sub_2B29E0(X86Context& ctx, uint8_t* base) {
	// 0x2B29E0: movss xmm0, dword ptr [0x00571D64]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D64u);
	// 0x2B29E8: movss [0x00571E08], xmm0
	X86_MEM_WRITE_u32(base, 0x571E08u, ctx.xmm[0].u32[0]);
	// 0x2B29F0: ret
	return;
}

void sub_2B2A00(X86Context& ctx, uint8_t* base) {
	// 0x2B2A00: movss xmm0, dword ptr [0x00571DEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DECu);
	// 0x2B2A08: subss xmm0, [0x00571D64]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571D64u);
	// 0x2B2A10: movss [0x00571DCC], xmm0
	X86_MEM_WRITE_u32(base, 0x571DCCu, ctx.xmm[0].u32[0]);
	// 0x2B2A18: ret
	return;
}

void sub_2B2A20(X86Context& ctx, uint8_t* base) {
	// 0x2B2A20: movss xmm0, dword ptr [0x00571DCC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DCCu);
	// 0x2B2A28: subss xmm0, [0x00571D8C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571D8Cu);
	// 0x2B2A30: movss [0x00571DC4], xmm0
	X86_MEM_WRITE_u32(base, 0x571DC4u, ctx.xmm[0].u32[0]);
	// 0x2B2A38: ret
	return;
}

void sub_2B2A40(X86Context& ctx, uint8_t* base) {
	// 0x2B2A40: movss xmm0, dword ptr [0x00571DF4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571DF4u);
	// 0x2B2A48: subss xmm0, [0x003B1690]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1690u);
	// 0x2B2A50: movss [0x00571D9C], xmm0
	X86_MEM_WRITE_u32(base, 0x571D9Cu, ctx.xmm[0].u32[0]);
	// 0x2B2A58: ret
	return;
}

void sub_2B2A60(X86Context& ctx, uint8_t* base) {
	// 0x2B2A60: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B2A68: movss [0x00571D88], xmm0
	X86_MEM_WRITE_u32(base, 0x571D88u, ctx.xmm[0].u32[0]);
	// 0x2B2A70: ret
	return;
}

void sub_2B2A80(X86Context& ctx, uint8_t* base) {
	// 0x2B2A80: movss xmm0, dword ptr [0x00571D9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571D9Cu);
	// 0x2B2A88: subss xmm0, [0x003B1688]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3B1688u);
	// 0x2B2A90: movss [0x00571DE4], xmm0
	X86_MEM_WRITE_u32(base, 0x571DE4u, ctx.xmm[0].u32[0]);
	// 0x2B2A98: ret
	return;
}

void sub_2B2AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B2AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B2AA8: movss [0x00571E68], xmm0
	X86_MEM_WRITE_u32(base, 0x571E68u, ctx.xmm[0].u32[0]);
	// 0x2B2AB0: ret
	return;
}

void sub_2B2AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B2AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B2AC8: movss [0x00571E84], xmm0
	X86_MEM_WRITE_u32(base, 0x571E84u, ctx.xmm[0].u32[0]);
	// 0x2B2AD0: ret
	return;
}

void sub_2B2AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B2AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B2AE8: movss [0x00571E5C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E5Cu, ctx.xmm[0].u32[0]);
	// 0x2B2AF0: ret
	return;
}

void sub_2B2B00(X86Context& ctx, uint8_t* base) {
	// 0x2B2B00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B2B08: movss [0x00571E14], xmm0
	X86_MEM_WRITE_u32(base, 0x571E14u, ctx.xmm[0].u32[0]);
	// 0x2B2B10: ret
	return;
}

void sub_2B2B20(X86Context& ctx, uint8_t* base) {
	// 0x2B2B20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B2B28: movss [0x00571E6C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E6Cu, ctx.xmm[0].u32[0]);
	// 0x2B2B30: ret
	return;
}

void sub_2B2B40(X86Context& ctx, uint8_t* base) {
	// 0x2B2B40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B2B48: movss [0x00571E30], xmm0
	X86_MEM_WRITE_u32(base, 0x571E30u, ctx.xmm[0].u32[0]);
	// 0x2B2B50: ret
	return;
}

void sub_2B2B60(X86Context& ctx, uint8_t* base) {
	// 0x2B2B60: movss xmm0, dword ptr [0x00571E6C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E6Cu);
	// 0x2B2B68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2B70: movss [0x00571EA4], xmm0
	X86_MEM_WRITE_u32(base, 0x571EA4u, ctx.xmm[0].u32[0]);
	// 0x2B2B78: ret
	return;
}

void sub_2B2B80(X86Context& ctx, uint8_t* base) {
	// 0x2B2B80: movss xmm0, dword ptr [0x00571E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E30u);
	// 0x2B2B88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B2B90: movss [0x00571E8C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E8Cu, ctx.xmm[0].u32[0]);
	// 0x2B2B98: ret
	return;
}

void sub_2B2BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B2BA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B2BA8: movss [0x00571EBC], xmm0
	X86_MEM_WRITE_u32(base, 0x571EBCu, ctx.xmm[0].u32[0]);
	// 0x2B2BB0: ret
	return;
}

void sub_2B2BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B2BC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B2BC8: movss [0x00571EA8], xmm0
	X86_MEM_WRITE_u32(base, 0x571EA8u, ctx.xmm[0].u32[0]);
	// 0x2B2BD0: ret
	return;
}

void sub_2B2BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B2BE0: movss xmm0, dword ptr [0x00571EA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571EA8u);
	// 0x2B2BE8: movss [0x00571EB8], xmm0
	X86_MEM_WRITE_u32(base, 0x571EB8u, ctx.xmm[0].u32[0]);
	// 0x2B2BF0: ret
	return;
}

void sub_2B2C00(X86Context& ctx, uint8_t* base) {
	// 0x2B2C00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B2C08: movss [0x00571E1C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E1Cu, ctx.xmm[0].u32[0]);
	// 0x2B2C10: ret
	return;
}

void sub_2B2C20(X86Context& ctx, uint8_t* base) {
	// 0x2B2C20: movss xmm0, dword ptr [0x00571E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E30u);
	// 0x2B2C28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B2C30: movss [0x00571EB0], xmm0
	X86_MEM_WRITE_u32(base, 0x571EB0u, ctx.xmm[0].u32[0]);
	// 0x2B2C38: ret
	return;
}

void sub_2B2C40(X86Context& ctx, uint8_t* base) {
	// 0x2B2C40: movss xmm0, dword ptr [0x00571E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E30u);
	// 0x2B2C48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B2C50: movss [0x00571E58], xmm0
	X86_MEM_WRITE_u32(base, 0x571E58u, ctx.xmm[0].u32[0]);
	// 0x2B2C58: ret
	return;
}

void sub_2B2C60(X86Context& ctx, uint8_t* base) {
	// 0x2B2C60: movss xmm0, dword ptr [0x00571E30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E30u);
	// 0x2B2C68: subss xmm0, [0x00571E58]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x571E58u);
	// 0x2B2C70: movss [0x00571E38], xmm0
	X86_MEM_WRITE_u32(base, 0x571E38u, ctx.xmm[0].u32[0]);
	// 0x2B2C78: ret
	return;
}

void sub_2B2C80(X86Context& ctx, uint8_t* base) {
	// 0x2B2C80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B2C88: movss [0x00571E80], xmm0
	X86_MEM_WRITE_u32(base, 0x571E80u, ctx.xmm[0].u32[0]);
	// 0x2B2C90: ret
	return;
}

void sub_2B2CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B2CA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B2CA8: movss [0x00571E34], xmm0
	X86_MEM_WRITE_u32(base, 0x571E34u, ctx.xmm[0].u32[0]);
	// 0x2B2CB0: ret
	return;
}

void sub_2B2CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B2CC0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B2CC8: movss [0x00571E44], xmm0
	X86_MEM_WRITE_u32(base, 0x571E44u, ctx.xmm[0].u32[0]);
	// 0x2B2CD0: ret
	return;
}

void sub_2B2CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B2CE0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B2CE8: movss [0x00571E98], xmm0
	X86_MEM_WRITE_u32(base, 0x571E98u, ctx.xmm[0].u32[0]);
	// 0x2B2CF0: ret
	return;
}

void sub_2B2D00(X86Context& ctx, uint8_t* base) {
	// 0x2B2D00: movss xmm0, dword ptr [0x00396EB0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x396EB0u);
	// 0x2B2D08: movss [0x00571E7C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E7Cu, ctx.xmm[0].u32[0]);
	// 0x2B2D10: ret
	return;
}

void sub_2B2D20(X86Context& ctx, uint8_t* base) {
	// 0x2B2D20: movss xmm0, dword ptr [0x00398CC0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398CC0u);
	// 0x2B2D28: movss [0x00571E2C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E2Cu, ctx.xmm[0].u32[0]);
	// 0x2B2D30: ret
	return;
}

void sub_2B2D40(X86Context& ctx, uint8_t* base) {
	// 0x2B2D40: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B2D48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2D50: movss [0x00571E20], xmm0
	X86_MEM_WRITE_u32(base, 0x571E20u, ctx.xmm[0].u32[0]);
	// 0x2B2D58: ret
	return;
}

void sub_2B2D60(X86Context& ctx, uint8_t* base) {
	// 0x2B2D60: movss xmm0, dword ptr [0x00571E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E98u);
	// 0x2B2D68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B2D70: movss [0x00571E64], xmm0
	X86_MEM_WRITE_u32(base, 0x571E64u, ctx.xmm[0].u32[0]);
	// 0x2B2D78: ret
	return;
}

void sub_2B2D80(X86Context& ctx, uint8_t* base) {
	// 0x2B2D80: movss xmm0, dword ptr [0x00571E20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E20u);
	// 0x2B2D88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B2D90: movss [0x00571E74], xmm0
	X86_MEM_WRITE_u32(base, 0x571E74u, ctx.xmm[0].u32[0]);
	// 0x2B2D98: ret
	return;
}

void sub_2B2DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B2DA0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B2DA8: movss [0x00571E18], xmm0
	X86_MEM_WRITE_u32(base, 0x571E18u, ctx.xmm[0].u32[0]);
	// 0x2B2DB0: ret
	return;
}

void sub_2B2DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B2DC0: movss xmm0, dword ptr [0x003A2D50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A2D50u);
	// 0x2B2DC8: movss [0x00571E48], xmm0
	X86_MEM_WRITE_u32(base, 0x571E48u, ctx.xmm[0].u32[0]);
	// 0x2B2DD0: ret
	return;
}

void sub_2B2DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B2DE0: movss xmm0, dword ptr [0x00571E44]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E44u);
	// 0x2B2DE8: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B2DF0: movss [0x00571E54], xmm0
	X86_MEM_WRITE_u32(base, 0x571E54u, ctx.xmm[0].u32[0]);
	// 0x2B2DF8: ret
	return;
}

void sub_2B2E00(X86Context& ctx, uint8_t* base) {
	// 0x2B2E00: movss xmm0, dword ptr [0x00571E98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E98u);
	// 0x2B2E08: addss xmm0, [0x003980F8]
	ctx.xmm[0].f32[0] += X86_MEM_READ_F32(base, 0x3980F8u);
	// 0x2B2E10: movss [0x00571E9C], xmm0
	X86_MEM_WRITE_u32(base, 0x571E9Cu, ctx.xmm[0].u32[0]);
	// 0x2B2E18: ret
	return;
}

void sub_2B2E20(X86Context& ctx, uint8_t* base) {
	// 0x2B2E20: movss xmm0, dword ptr [0x00571E54]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E54u);
	// 0x2B2E28: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2E30: movss [0x00571E88], xmm0
	X86_MEM_WRITE_u32(base, 0x571E88u, ctx.xmm[0].u32[0]);
	// 0x2B2E38: ret
	return;
}

void sub_2B2E40(X86Context& ctx, uint8_t* base) {
	// 0x2B2E40: movss xmm0, dword ptr [0x00571E9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x571E9Cu);
	// 0x2B2E48: mulss xmm0, [0x003B1C34]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1C34u);
	// 0x2B2E50: movss [0x00571EAC], xmm0
	X86_MEM_WRITE_u32(base, 0x571EACu, ctx.xmm[0].u32[0]);
	// 0x2B2E58: ret
	return;
}

void sub_2B2E60(X86Context& ctx, uint8_t* base) {
	// 0x2B2E60: movss xmm0, dword ptr [0x003B1C34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C34u);
	// 0x2B2E68: movss [0x00571E24], xmm0
	X86_MEM_WRITE_u32(base, 0x571E24u, ctx.xmm[0].u32[0]);
	// 0x2B2E70: ret
	return;
}

