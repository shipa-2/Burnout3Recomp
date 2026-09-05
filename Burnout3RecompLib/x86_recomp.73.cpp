#include "x86_recomp_shared.h"

void sub_2B5140(X86Context& ctx, uint8_t* base) {
	// 0x2B5140: movss xmm0, dword ptr [0x005723E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5723E0u);
	// 0x2B5148: movss [0x004A3564], xmm0
	X86_MEM_WRITE_u32(base, 0x4A3564u, ctx.xmm[0].u32[0]);
	// 0x2B5150: ret
	return;
}

void sub_2B5160(X86Context& ctx, uint8_t* base) {
	// 0x2B5160: movss xmm0, dword ptr [0x005723E0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5723E0u);
	// 0x2B5168: movss [0x004A3568], xmm0
	X86_MEM_WRITE_u32(base, 0x4A3568u, ctx.xmm[0].u32[0]);
	// 0x2B5170: ret
	return;
}

void sub_2B5180(X86Context& ctx, uint8_t* base) {
	// 0x2B5180: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B5181: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B5183: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B5186: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B5189: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B5191: divss xmm0, [0x00572428]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x572428u);
	// 0x2B5199: movss xmm1, dword ptr [0x003EBDA4]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3EBDA4u);
	// 0x2B51A1: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B51A5: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x2B51AA: movss xmm1, dword ptr [0x003EBDA8]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3EBDA8u);
	// 0x2B51B2: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B51B5: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B51B9: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x2B51BF: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B51C3: mov [0x00572438], eax
	X86_MEM_WRITE_u32(base, 0x572438u, ctx.eax);
	// 0x2B51C8: mov [0x0057243C], ecx
	X86_MEM_WRITE_u32(base, 0x57243Cu, ctx.ecx);
	// 0x2B51CE: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B51D0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B51D1: ret
	return;
}

void sub_2B51E0(X86Context& ctx, uint8_t* base) {
	// 0x2B51E0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B51E1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B51E3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B51E6: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B51E9: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B51F1: divss xmm0, [0x00572428]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x572428u);
	// 0x2B51F9: movss xmm1, dword ptr [0x005723DC]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x5723DCu);
	// 0x2B5201: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B5205: movss [esp], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[1].u32[0]);
	// 0x2B520A: movss xmm1, dword ptr [0x0057244C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x57244Cu);
	// 0x2B5212: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B5215: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B5219: movss [esp+0x04], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[1].u32[0]);
	// 0x2B521F: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B5223: mov [0x005723D0], eax
	X86_MEM_WRITE_u32(base, 0x5723D0u, ctx.eax);
	// 0x2B5228: mov [0x005723D4], ecx
	X86_MEM_WRITE_u32(base, 0x5723D4u, ctx.ecx);
	// 0x2B522E: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B5230: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B5231: ret
	return;
}

void sub_2B5240(X86Context& ctx, uint8_t* base) {
	// 0x2B5240: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B5241: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B5243: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B5246: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B5249: movss xmm3, dword ptr [0x00572428]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x572428u);
	// 0x2B5251: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B5259: movaps xmm1, xmm3
	ctx.xmm[1] = ctx.xmm[3];
	// 0x2B525C: subss xmm1, [0x003EBDA8]
	ctx.xmm[1].f32[0] -= X86_MEM_READ_F32(base, 0x3EBDA8u);
	// 0x2B5264: mulss xmm1, [0x003B1684]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B526C: movaps xmm2, xmm3
	ctx.xmm[2] = ctx.xmm[3];
	// 0x2B526F: subss xmm2, [0x003EBDA4]
	ctx.xmm[2].f32[0] -= X86_MEM_READ_F32(base, 0x3EBDA4u);
	// 0x2B5277: divss xmm0, xmm3
	ctx.xmm[0].f32[0] /= ctx.xmm[3].f32[0];
	// 0x2B527B: movaps xmm3, xmm0
	ctx.xmm[3] = ctx.xmm[0];
	// 0x2B527E: mulss xmm3, xmm2
	ctx.xmm[3].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B5282: mulss xmm0, xmm1
	ctx.xmm[0].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2B5286: movss [esp], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[3].u32[0]);
	// 0x2B528B: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B528E: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B5294: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B5298: mov [0x00572440], eax
	X86_MEM_WRITE_u32(base, 0x572440u, ctx.eax);
	// 0x2B529D: mov [0x00572444], ecx
	X86_MEM_WRITE_u32(base, 0x572444u, ctx.ecx);
	// 0x2B52A3: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B52A5: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B52A6: ret
	return;
}

void sub_2B52B0(X86Context& ctx, uint8_t* base) {
	// 0x2B52B0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B52B1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B52B3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B52B6: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B52B9: movss xmm3, dword ptr [0x00572428]
	ctx.xmm[3].u32[0] = X86_MEM_READ_u32(base, 0x572428u);
	// 0x2B52C1: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B52C9: movaps xmm1, xmm3
	ctx.xmm[1] = ctx.xmm[3];
	// 0x2B52CC: subss xmm1, [0x005723DC]
	ctx.xmm[1].f32[0] -= X86_MEM_READ_F32(base, 0x5723DCu);
	// 0x2B52D4: mulss xmm1, [0x003B1684]
	ctx.xmm[1].f32[0] *= X86_MEM_READ_F32(base, 0x3B1684u);
	// 0x2B52DC: movaps xmm2, xmm3
	ctx.xmm[2] = ctx.xmm[3];
	// 0x2B52DF: subss xmm2, [0x0057244C]
	ctx.xmm[2].f32[0] -= X86_MEM_READ_F32(base, 0x57244Cu);
	// 0x2B52E7: divss xmm0, xmm3
	ctx.xmm[0].f32[0] /= ctx.xmm[3].f32[0];
	// 0x2B52EB: movaps xmm3, xmm0
	ctx.xmm[3] = ctx.xmm[0];
	// 0x2B52EE: mulss xmm3, xmm1
	ctx.xmm[3].f32[0] *= ctx.xmm[1].f32[0];
	// 0x2B52F2: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B52F6: movss [esp], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[3].u32[0]);
	// 0x2B52FB: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B52FE: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B5304: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B5308: mov [0x005723E8], eax
	X86_MEM_WRITE_u32(base, 0x5723E8u, ctx.eax);
	// 0x2B530D: mov [0x005723EC], ecx
	X86_MEM_WRITE_u32(base, 0x5723ECu, ctx.ecx);
	// 0x2B5313: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B5315: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B5316: ret
	return;
}

void sub_2B5320(X86Context& ctx, uint8_t* base) {
	// 0x2B5320: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B5328: movss [0x00572484], xmm0
	X86_MEM_WRITE_u32(base, 0x572484u, ctx.xmm[0].u32[0]);
	// 0x2B5330: ret
	return;
}

void sub_2B5340(X86Context& ctx, uint8_t* base) {
	// 0x2B5340: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5348: movss [0x00572488], xmm0
	X86_MEM_WRITE_u32(base, 0x572488u, ctx.xmm[0].u32[0]);
	// 0x2B5350: ret
	return;
}

void sub_2B5360(X86Context& ctx, uint8_t* base) {
	// 0x2B5360: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5368: movss [0x00572480], xmm0
	X86_MEM_WRITE_u32(base, 0x572480u, ctx.xmm[0].u32[0]);
	// 0x2B5370: ret
	return;
}

void sub_2B5380(X86Context& ctx, uint8_t* base) {
	// 0x2B5380: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B5381: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B5383: and esp, 0xFFFFFFF0
	ctx.esp = ctx.esp & -16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B5386: sub esp, 0x20
	{ uint32_t _d = ctx.esp; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B5389: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B5391: movss [esp+0x10], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.xmm[0].u32[0]);
	// 0x2B5397: movss [esp+0x14], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.xmm[0].u32[0]);
	// 0x2B539D: movss [esp+0x18], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.xmm[0].u32[0]);
	// 0x2B53A3: movss xmm0, dword ptr [0x003A5600]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A5600u);
	// 0x2B53AB: movss [esp+0x1C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.xmm[0].u32[0]);
	// 0x2B53B1: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B53B9: movaps xmm1, [esp+0x10]
	X86_MEM_READ_XMM(base, ctx.esp + 0x10u, ctx.xmm[1]);
	// 0x2B53BE: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B53C4: lea eax, [esp+0x0C]
	ctx.eax = ctx.esp + 0xCu;
	// 0x2B53C8: movss xmm0, dword ptr [eax]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2B53CC: shufps xmm0, xmm0, 0x00
	{ X86XmmReg _tmp;
	  _tmp.f32[0] = ctx.xmm[0].f32[0 & 3];
	  _tmp.f32[1] = ctx.xmm[0].f32[(0 >> 2) & 3];
	  _tmp.f32[2] = ctx.xmm[0].f32[(0 >> 4) & 3];
	  _tmp.f32[3] = ctx.xmm[0].f32[(0 >> 6) & 3];
	  ctx.xmm[0] = _tmp; }
	// 0x2B53D0: divps xmm1, xmm0
	X86_SSE_DIVPS(ctx.xmm[1], ctx.xmm[0]);
	// 0x2B53D3: movaps [0x00572470], xmm1
	X86_MEM_WRITE_XMM(base, 0x572470u, ctx.xmm[1]);
	// 0x2B53DA: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B53DC: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B53DD: ret
	return;
}

void sub_2B53E0(X86Context& ctx, uint8_t* base) {
	// 0x2B53E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B53E8: movss [0x005724A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5724A8u, ctx.xmm[0].u32[0]);
	// 0x2B53F0: ret
	return;
}

void sub_2B5400(X86Context& ctx, uint8_t* base) {
	// 0x2B5400: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5408: movss [0x005724B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5724B4u, ctx.xmm[0].u32[0]);
	// 0x2B5410: ret
	return;
}

void sub_2B5420(X86Context& ctx, uint8_t* base) {
	// 0x2B5420: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5428: movss [0x005724A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5724A4u, ctx.xmm[0].u32[0]);
	// 0x2B5430: ret
	return;
}

void sub_2B5440(X86Context& ctx, uint8_t* base) {
	// 0x2B5440: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B5448: movss [0x0057248C], xmm0
	X86_MEM_WRITE_u32(base, 0x57248Cu, ctx.xmm[0].u32[0]);
	// 0x2B5450: ret
	return;
}

void sub_2B5460(X86Context& ctx, uint8_t* base) {
	// 0x2B5460: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B5468: movss [0x005724AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5724ACu, ctx.xmm[0].u32[0]);
	// 0x2B5470: ret
	return;
}

void sub_2B5480(X86Context& ctx, uint8_t* base) {
	// 0x2B5480: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B5488: movss [0x00572494], xmm0
	X86_MEM_WRITE_u32(base, 0x572494u, ctx.xmm[0].u32[0]);
	// 0x2B5490: ret
	return;
}

void sub_2B54A0(X86Context& ctx, uint8_t* base) {
	// 0x2B54A0: movss xmm0, dword ptr [0x005724AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724ACu);
	// 0x2B54A8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B54B0: movss [0x005724BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5724BCu, ctx.xmm[0].u32[0]);
	// 0x2B54B8: ret
	return;
}

void sub_2B54C0(X86Context& ctx, uint8_t* base) {
	// 0x2B54C0: movss xmm0, dword ptr [0x00572494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572494u);
	// 0x2B54C8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B54D0: movss [0x005724B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5724B8u, ctx.xmm[0].u32[0]);
	// 0x2B54D8: ret
	return;
}

void sub_2B54E0(X86Context& ctx, uint8_t* base) {
	// 0x2B54E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B54E8: movss [0x005724CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5724CCu, ctx.xmm[0].u32[0]);
	// 0x2B54F0: ret
	return;
}

void sub_2B5500(X86Context& ctx, uint8_t* base) {
	// 0x2B5500: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B5508: movss [0x005724C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5724C0u, ctx.xmm[0].u32[0]);
	// 0x2B5510: ret
	return;
}

void sub_2B5520(X86Context& ctx, uint8_t* base) {
	// 0x2B5520: movss xmm0, dword ptr [0x005724C0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724C0u);
	// 0x2B5528: movss [0x005724C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5724C8u, ctx.xmm[0].u32[0]);
	// 0x2B5530: ret
	return;
}

void sub_2B5540(X86Context& ctx, uint8_t* base) {
	// 0x2B5540: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5548: movss [0x00572490], xmm0
	X86_MEM_WRITE_u32(base, 0x572490u, ctx.xmm[0].u32[0]);
	// 0x2B5550: ret
	return;
}

void sub_2B5560(X86Context& ctx, uint8_t* base) {
	// 0x2B5560: movss xmm0, dword ptr [0x00572494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572494u);
	// 0x2B5568: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B5570: movss [0x005724C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5724C4u, ctx.xmm[0].u32[0]);
	// 0x2B5578: ret
	return;
}

void sub_2B5580(X86Context& ctx, uint8_t* base) {
	// 0x2B5580: movss xmm0, dword ptr [0x00572494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572494u);
	// 0x2B5588: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B5590: movss [0x005724A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5724A0u, ctx.xmm[0].u32[0]);
	// 0x2B5598: ret
	return;
}

void sub_2B55A0(X86Context& ctx, uint8_t* base) {
	// 0x2B55A0: movss xmm0, dword ptr [0x00572494]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572494u);
	// 0x2B55A8: subss xmm0, [0x005724A0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5724A0u);
	// 0x2B55B0: movss [0x0057249C], xmm0
	X86_MEM_WRITE_u32(base, 0x57249Cu, ctx.xmm[0].u32[0]);
	// 0x2B55B8: ret
	return;
}

void sub_2B55C0(X86Context& ctx, uint8_t* base) {
	// 0x2B55C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B55C8: movss [0x005724B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5724B0u, ctx.xmm[0].u32[0]);
	// 0x2B55D0: ret
	return;
}

void sub_2B55E0(X86Context& ctx, uint8_t* base) {
	// 0x2B55E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B55E8: movss [0x00572498], xmm0
	X86_MEM_WRITE_u32(base, 0x572498u, ctx.xmm[0].u32[0]);
	// 0x2B55F0: ret
	return;
}

void sub_2B5600(X86Context& ctx, uint8_t* base) {
	// 0x2B5600: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B5608: movss [0x005724EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5724ECu, ctx.xmm[0].u32[0]);
	// 0x2B5610: ret
	return;
}

void sub_2B5620(X86Context& ctx, uint8_t* base) {
	// 0x2B5620: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5628: movss [0x005724F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5724F8u, ctx.xmm[0].u32[0]);
	// 0x2B5630: ret
	return;
}

void sub_2B5640(X86Context& ctx, uint8_t* base) {
	// 0x2B5640: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5648: movss [0x005724E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5724E8u, ctx.xmm[0].u32[0]);
	// 0x2B5650: ret
	return;
}

void sub_2B5660(X86Context& ctx, uint8_t* base) {
	// 0x2B5660: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B5668: movss [0x005724D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5724D0u, ctx.xmm[0].u32[0]);
	// 0x2B5670: ret
	return;
}

void sub_2B5680(X86Context& ctx, uint8_t* base) {
	// 0x2B5680: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B5688: movss [0x005724F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5724F0u, ctx.xmm[0].u32[0]);
	// 0x2B5690: ret
	return;
}

void sub_2B56A0(X86Context& ctx, uint8_t* base) {
	// 0x2B56A0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B56A8: movss [0x005724D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5724D8u, ctx.xmm[0].u32[0]);
	// 0x2B56B0: ret
	return;
}

void sub_2B56C0(X86Context& ctx, uint8_t* base) {
	// 0x2B56C0: movss xmm0, dword ptr [0x005724F0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724F0u);
	// 0x2B56C8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B56D0: movss [0x00572500], xmm0
	X86_MEM_WRITE_u32(base, 0x572500u, ctx.xmm[0].u32[0]);
	// 0x2B56D8: ret
	return;
}

void sub_2B56E0(X86Context& ctx, uint8_t* base) {
	// 0x2B56E0: movss xmm0, dword ptr [0x005724D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724D8u);
	// 0x2B56E8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B56F0: movss [0x005724FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5724FCu, ctx.xmm[0].u32[0]);
	// 0x2B56F8: ret
	return;
}

void sub_2B5700(X86Context& ctx, uint8_t* base) {
	// 0x2B5700: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5708: movss [0x00572510], xmm0
	X86_MEM_WRITE_u32(base, 0x572510u, ctx.xmm[0].u32[0]);
	// 0x2B5710: ret
	return;
}

void sub_2B5720(X86Context& ctx, uint8_t* base) {
	// 0x2B5720: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B5728: movss [0x00572504], xmm0
	X86_MEM_WRITE_u32(base, 0x572504u, ctx.xmm[0].u32[0]);
	// 0x2B5730: ret
	return;
}

void sub_2B5740(X86Context& ctx, uint8_t* base) {
	// 0x2B5740: movss xmm0, dword ptr [0x00572504]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572504u);
	// 0x2B5748: movss [0x0057250C], xmm0
	X86_MEM_WRITE_u32(base, 0x57250Cu, ctx.xmm[0].u32[0]);
	// 0x2B5750: ret
	return;
}

void sub_2B5760(X86Context& ctx, uint8_t* base) {
	// 0x2B5760: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5768: movss [0x005724D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5724D4u, ctx.xmm[0].u32[0]);
	// 0x2B5770: ret
	return;
}

void sub_2B5780(X86Context& ctx, uint8_t* base) {
	// 0x2B5780: movss xmm0, dword ptr [0x005724D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724D8u);
	// 0x2B5788: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B5790: movss [0x00572508], xmm0
	X86_MEM_WRITE_u32(base, 0x572508u, ctx.xmm[0].u32[0]);
	// 0x2B5798: ret
	return;
}

void sub_2B57A0(X86Context& ctx, uint8_t* base) {
	// 0x2B57A0: movss xmm0, dword ptr [0x005724D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724D8u);
	// 0x2B57A8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B57B0: movss [0x005724E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5724E4u, ctx.xmm[0].u32[0]);
	// 0x2B57B8: ret
	return;
}

void sub_2B57C0(X86Context& ctx, uint8_t* base) {
	// 0x2B57C0: movss xmm0, dword ptr [0x005724D8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5724D8u);
	// 0x2B57C8: subss xmm0, [0x005724E4]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5724E4u);
	// 0x2B57D0: movss [0x005724E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5724E0u, ctx.xmm[0].u32[0]);
	// 0x2B57D8: ret
	return;
}

void sub_2B57E0(X86Context& ctx, uint8_t* base) {
	// 0x2B57E0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B57E8: movss [0x005724F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5724F4u, ctx.xmm[0].u32[0]);
	// 0x2B57F0: ret
	return;
}

void sub_2B5800(X86Context& ctx, uint8_t* base) {
	// 0x2B5800: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B5808: movss [0x005724DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5724DCu, ctx.xmm[0].u32[0]);
	// 0x2B5810: ret
	return;
}

void sub_2B5820(X86Context& ctx, uint8_t* base) {
	// 0x2B5820: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B5828: movss [0x00572538], xmm0
	X86_MEM_WRITE_u32(base, 0x572538u, ctx.xmm[0].u32[0]);
	// 0x2B5830: ret
	return;
}

void sub_2B5840(X86Context& ctx, uint8_t* base) {
	// 0x2B5840: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5848: movss [0x00572544], xmm0
	X86_MEM_WRITE_u32(base, 0x572544u, ctx.xmm[0].u32[0]);
	// 0x2B5850: ret
	return;
}

void sub_2B5860(X86Context& ctx, uint8_t* base) {
	// 0x2B5860: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5868: movss [0x00572534], xmm0
	X86_MEM_WRITE_u32(base, 0x572534u, ctx.xmm[0].u32[0]);
	// 0x2B5870: ret
	return;
}

void sub_2B5880(X86Context& ctx, uint8_t* base) {
	// 0x2B5880: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B5888: movss [0x00572514], xmm0
	X86_MEM_WRITE_u32(base, 0x572514u, ctx.xmm[0].u32[0]);
	// 0x2B5890: ret
	return;
}

void sub_2B58A0(X86Context& ctx, uint8_t* base) {
	// 0x2B58A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B58A8: movss [0x0057253C], xmm0
	X86_MEM_WRITE_u32(base, 0x57253Cu, ctx.xmm[0].u32[0]);
	// 0x2B58B0: ret
	return;
}

void sub_2B58C0(X86Context& ctx, uint8_t* base) {
	// 0x2B58C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B58C8: movss [0x0057251C], xmm0
	X86_MEM_WRITE_u32(base, 0x57251Cu, ctx.xmm[0].u32[0]);
	// 0x2B58D0: ret
	return;
}

void sub_2B58E0(X86Context& ctx, uint8_t* base) {
	// 0x2B58E0: movss xmm0, dword ptr [0x0057253C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57253Cu);
	// 0x2B58E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B58F0: movss [0x00572550], xmm0
	X86_MEM_WRITE_u32(base, 0x572550u, ctx.xmm[0].u32[0]);
	// 0x2B58F8: ret
	return;
}

void sub_2B5900(X86Context& ctx, uint8_t* base) {
	// 0x2B5900: movss xmm0, dword ptr [0x0057251C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57251Cu);
	// 0x2B5908: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B5910: movss [0x00572548], xmm0
	X86_MEM_WRITE_u32(base, 0x572548u, ctx.xmm[0].u32[0]);
	// 0x2B5918: ret
	return;
}

void sub_2B5920(X86Context& ctx, uint8_t* base) {
	// 0x2B5920: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5928: movss [0x00572560], xmm0
	X86_MEM_WRITE_u32(base, 0x572560u, ctx.xmm[0].u32[0]);
	// 0x2B5930: ret
	return;
}

void sub_2B5940(X86Context& ctx, uint8_t* base) {
	// 0x2B5940: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B5948: movss [0x00572554], xmm0
	X86_MEM_WRITE_u32(base, 0x572554u, ctx.xmm[0].u32[0]);
	// 0x2B5950: ret
	return;
}

void sub_2B5960(X86Context& ctx, uint8_t* base) {
	// 0x2B5960: movss xmm0, dword ptr [0x00572554]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572554u);
	// 0x2B5968: movss [0x0057255C], xmm0
	X86_MEM_WRITE_u32(base, 0x57255Cu, ctx.xmm[0].u32[0]);
	// 0x2B5970: ret
	return;
}

void sub_2B5980(X86Context& ctx, uint8_t* base) {
	// 0x2B5980: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5988: movss [0x00572518], xmm0
	X86_MEM_WRITE_u32(base, 0x572518u, ctx.xmm[0].u32[0]);
	// 0x2B5990: ret
	return;
}

void sub_2B59A0(X86Context& ctx, uint8_t* base) {
	// 0x2B59A0: movss xmm0, dword ptr [0x0057251C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57251Cu);
	// 0x2B59A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B59B0: movss [0x00572558], xmm0
	X86_MEM_WRITE_u32(base, 0x572558u, ctx.xmm[0].u32[0]);
	// 0x2B59B8: ret
	return;
}

void sub_2B59C0(X86Context& ctx, uint8_t* base) {
	// 0x2B59C0: movss xmm0, dword ptr [0x0057251C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57251Cu);
	// 0x2B59C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B59D0: movss [0x0057252C], xmm0
	X86_MEM_WRITE_u32(base, 0x57252Cu, ctx.xmm[0].u32[0]);
	// 0x2B59D8: ret
	return;
}

void sub_2B59E0(X86Context& ctx, uint8_t* base) {
	// 0x2B59E0: movss xmm0, dword ptr [0x0057251C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57251Cu);
	// 0x2B59E8: subss xmm0, [0x0057252C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57252Cu);
	// 0x2B59F0: movss [0x00572524], xmm0
	X86_MEM_WRITE_u32(base, 0x572524u, ctx.xmm[0].u32[0]);
	// 0x2B59F8: ret
	return;
}

void sub_2B5A00(X86Context& ctx, uint8_t* base) {
	// 0x2B5A00: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B5A08: movss [0x00572540], xmm0
	X86_MEM_WRITE_u32(base, 0x572540u, ctx.xmm[0].u32[0]);
	// 0x2B5A10: ret
	return;
}

void sub_2B5A20(X86Context& ctx, uint8_t* base) {
	// 0x2B5A20: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B5A28: movss [0x00572520], xmm0
	X86_MEM_WRITE_u32(base, 0x572520u, ctx.xmm[0].u32[0]);
	// 0x2B5A30: ret
	return;
}

void sub_2B5A40(X86Context& ctx, uint8_t* base) {
	// 0x2B5A40: movss xmm0, dword ptr [0x003B2310]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2310u);
	// 0x2B5A48: movss [0x00572528], xmm0
	X86_MEM_WRITE_u32(base, 0x572528u, ctx.xmm[0].u32[0]);
	// 0x2B5A50: ret
	return;
}

void sub_2B5A60(X86Context& ctx, uint8_t* base) {
	// 0x2B5A60: movss xmm0, dword ptr [0x003B2314]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2314u);
	// 0x2B5A68: movss [0x0057254C], xmm0
	X86_MEM_WRITE_u32(base, 0x57254Cu, ctx.xmm[0].u32[0]);
	// 0x2B5A70: ret
	return;
}

void sub_2B5A80(X86Context& ctx, uint8_t* base) {
	// 0x2B5A80: movss xmm0, dword ptr [0x003B2318]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2318u);
	// 0x2B5A88: movss [0x00572530], xmm0
	X86_MEM_WRITE_u32(base, 0x572530u, ctx.xmm[0].u32[0]);
	// 0x2B5A90: ret
	return;
}

void sub_2B5AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B5AA0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B5AA8: movss [0x00572580], xmm0
	X86_MEM_WRITE_u32(base, 0x572580u, ctx.xmm[0].u32[0]);
	// 0x2B5AB0: ret
	return;
}

void sub_2B5AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B5AC0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5AC8: movss [0x0057258C], xmm0
	X86_MEM_WRITE_u32(base, 0x57258Cu, ctx.xmm[0].u32[0]);
	// 0x2B5AD0: ret
	return;
}

void sub_2B5AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B5AE0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5AE8: movss [0x0057257C], xmm0
	X86_MEM_WRITE_u32(base, 0x57257Cu, ctx.xmm[0].u32[0]);
	// 0x2B5AF0: ret
	return;
}

void sub_2B5B00(X86Context& ctx, uint8_t* base) {
	// 0x2B5B00: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B5B08: movss [0x00572564], xmm0
	X86_MEM_WRITE_u32(base, 0x572564u, ctx.xmm[0].u32[0]);
	// 0x2B5B10: ret
	return;
}

void sub_2B5B20(X86Context& ctx, uint8_t* base) {
	// 0x2B5B20: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B5B28: movss [0x00572584], xmm0
	X86_MEM_WRITE_u32(base, 0x572584u, ctx.xmm[0].u32[0]);
	// 0x2B5B30: ret
	return;
}

void sub_2B5B40(X86Context& ctx, uint8_t* base) {
	// 0x2B5B40: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B5B48: movss [0x0057256C], xmm0
	X86_MEM_WRITE_u32(base, 0x57256Cu, ctx.xmm[0].u32[0]);
	// 0x2B5B50: ret
	return;
}

void sub_2B5B60(X86Context& ctx, uint8_t* base) {
	// 0x2B5B60: movss xmm0, dword ptr [0x00572584]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572584u);
	// 0x2B5B68: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B5B70: movss [0x00572594], xmm0
	X86_MEM_WRITE_u32(base, 0x572594u, ctx.xmm[0].u32[0]);
	// 0x2B5B78: ret
	return;
}

void sub_2B5B80(X86Context& ctx, uint8_t* base) {
	// 0x2B5B80: movss xmm0, dword ptr [0x0057256C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57256Cu);
	// 0x2B5B88: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B5B90: movss [0x00572590], xmm0
	X86_MEM_WRITE_u32(base, 0x572590u, ctx.xmm[0].u32[0]);
	// 0x2B5B98: ret
	return;
}

void sub_2B5BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B5BA0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5BA8: movss [0x005725A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5725A4u, ctx.xmm[0].u32[0]);
	// 0x2B5BB0: ret
	return;
}

void sub_2B5BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B5BC0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B5BC8: movss [0x00572598], xmm0
	X86_MEM_WRITE_u32(base, 0x572598u, ctx.xmm[0].u32[0]);
	// 0x2B5BD0: ret
	return;
}

void sub_2B5BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B5BE0: movss xmm0, dword ptr [0x00572598]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572598u);
	// 0x2B5BE8: movss [0x005725A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5725A0u, ctx.xmm[0].u32[0]);
	// 0x2B5BF0: ret
	return;
}

void sub_2B5C00(X86Context& ctx, uint8_t* base) {
	// 0x2B5C00: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5C08: movss [0x00572568], xmm0
	X86_MEM_WRITE_u32(base, 0x572568u, ctx.xmm[0].u32[0]);
	// 0x2B5C10: ret
	return;
}

void sub_2B5C20(X86Context& ctx, uint8_t* base) {
	// 0x2B5C20: movss xmm0, dword ptr [0x0057256C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57256Cu);
	// 0x2B5C28: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B5C30: movss [0x0057259C], xmm0
	X86_MEM_WRITE_u32(base, 0x57259Cu, ctx.xmm[0].u32[0]);
	// 0x2B5C38: ret
	return;
}

void sub_2B5C40(X86Context& ctx, uint8_t* base) {
	// 0x2B5C40: movss xmm0, dword ptr [0x0057256C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57256Cu);
	// 0x2B5C48: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B5C50: movss [0x00572578], xmm0
	X86_MEM_WRITE_u32(base, 0x572578u, ctx.xmm[0].u32[0]);
	// 0x2B5C58: ret
	return;
}

void sub_2B5C60(X86Context& ctx, uint8_t* base) {
	// 0x2B5C60: movss xmm0, dword ptr [0x0057256C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57256Cu);
	// 0x2B5C68: subss xmm0, [0x00572578]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572578u);
	// 0x2B5C70: movss [0x00572574], xmm0
	X86_MEM_WRITE_u32(base, 0x572574u, ctx.xmm[0].u32[0]);
	// 0x2B5C78: ret
	return;
}

void sub_2B5C80(X86Context& ctx, uint8_t* base) {
	// 0x2B5C80: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B5C88: movss [0x00572588], xmm0
	X86_MEM_WRITE_u32(base, 0x572588u, ctx.xmm[0].u32[0]);
	// 0x2B5C90: ret
	return;
}

void sub_2B5CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B5CA0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B5CA8: movss [0x00572570], xmm0
	X86_MEM_WRITE_u32(base, 0x572570u, ctx.xmm[0].u32[0]);
	// 0x2B5CB0: ret
	return;
}

void sub_2B5CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B5CC0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B5CC8: movss [0x005725C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5725C4u, ctx.xmm[0].u32[0]);
	// 0x2B5CD0: ret
	return;
}

void sub_2B5CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B5CE0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5CE8: movss [0x005725D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5725D0u, ctx.xmm[0].u32[0]);
	// 0x2B5CF0: ret
	return;
}

void sub_2B5D00(X86Context& ctx, uint8_t* base) {
	// 0x2B5D00: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5D08: movss [0x005725C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5725C0u, ctx.xmm[0].u32[0]);
	// 0x2B5D10: ret
	return;
}

void sub_2B5D20(X86Context& ctx, uint8_t* base) {
	// 0x2B5D20: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B5D28: movss [0x005725A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5725A8u, ctx.xmm[0].u32[0]);
	// 0x2B5D30: ret
	return;
}

void sub_2B5D40(X86Context& ctx, uint8_t* base) {
	// 0x2B5D40: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B5D48: movss [0x005725C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5725C8u, ctx.xmm[0].u32[0]);
	// 0x2B5D50: ret
	return;
}

void sub_2B5D60(X86Context& ctx, uint8_t* base) {
	// 0x2B5D60: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B5D68: movss [0x005725B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5725B0u, ctx.xmm[0].u32[0]);
	// 0x2B5D70: ret
	return;
}

void sub_2B5D80(X86Context& ctx, uint8_t* base) {
	// 0x2B5D80: movss xmm0, dword ptr [0x005725C8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725C8u);
	// 0x2B5D88: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B5D90: movss [0x005725D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5725D8u, ctx.xmm[0].u32[0]);
	// 0x2B5D98: ret
	return;
}

void sub_2B5DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B5DA0: movss xmm0, dword ptr [0x005725B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725B0u);
	// 0x2B5DA8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B5DB0: movss [0x005725D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5725D4u, ctx.xmm[0].u32[0]);
	// 0x2B5DB8: ret
	return;
}

void sub_2B5DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B5DC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5DC8: movss [0x005725E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5725E8u, ctx.xmm[0].u32[0]);
	// 0x2B5DD0: ret
	return;
}

void sub_2B5DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B5DE0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B5DE8: movss [0x005725DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5725DCu, ctx.xmm[0].u32[0]);
	// 0x2B5DF0: ret
	return;
}

void sub_2B5E00(X86Context& ctx, uint8_t* base) {
	// 0x2B5E00: movss xmm0, dword ptr [0x005725DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725DCu);
	// 0x2B5E08: movss [0x005725E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5725E4u, ctx.xmm[0].u32[0]);
	// 0x2B5E10: ret
	return;
}

void sub_2B5E20(X86Context& ctx, uint8_t* base) {
	// 0x2B5E20: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5E28: movss [0x005725AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5725ACu, ctx.xmm[0].u32[0]);
	// 0x2B5E30: ret
	return;
}

void sub_2B5E40(X86Context& ctx, uint8_t* base) {
	// 0x2B5E40: movss xmm0, dword ptr [0x005725B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725B0u);
	// 0x2B5E48: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B5E50: movss [0x005725E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5725E0u, ctx.xmm[0].u32[0]);
	// 0x2B5E58: ret
	return;
}

void sub_2B5E60(X86Context& ctx, uint8_t* base) {
	// 0x2B5E60: movss xmm0, dword ptr [0x005725B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725B0u);
	// 0x2B5E68: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B5E70: movss [0x005725BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5725BCu, ctx.xmm[0].u32[0]);
	// 0x2B5E78: ret
	return;
}

void sub_2B5E80(X86Context& ctx, uint8_t* base) {
	// 0x2B5E80: movss xmm0, dword ptr [0x005725B0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725B0u);
	// 0x2B5E88: subss xmm0, [0x005725BC]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5725BCu);
	// 0x2B5E90: movss [0x005725B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5725B8u, ctx.xmm[0].u32[0]);
	// 0x2B5E98: ret
	return;
}

void sub_2B5EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B5EA0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B5EA8: movss [0x005725CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5725CCu, ctx.xmm[0].u32[0]);
	// 0x2B5EB0: ret
	return;
}

void sub_2B5EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B5EC0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B5EC8: movss [0x005725B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5725B4u, ctx.xmm[0].u32[0]);
	// 0x2B5ED0: ret
	return;
}

void sub_2B5EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B5EE0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B5EE8: movss [0x00572608], xmm0
	X86_MEM_WRITE_u32(base, 0x572608u, ctx.xmm[0].u32[0]);
	// 0x2B5EF0: ret
	return;
}

void sub_2B5F00(X86Context& ctx, uint8_t* base) {
	// 0x2B5F00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B5F08: movss [0x00572614], xmm0
	X86_MEM_WRITE_u32(base, 0x572614u, ctx.xmm[0].u32[0]);
	// 0x2B5F10: ret
	return;
}

void sub_2B5F20(X86Context& ctx, uint8_t* base) {
	// 0x2B5F20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B5F28: movss [0x00572604], xmm0
	X86_MEM_WRITE_u32(base, 0x572604u, ctx.xmm[0].u32[0]);
	// 0x2B5F30: ret
	return;
}

void sub_2B5F40(X86Context& ctx, uint8_t* base) {
	// 0x2B5F40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B5F48: movss [0x005725EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5725ECu, ctx.xmm[0].u32[0]);
	// 0x2B5F50: ret
	return;
}

void sub_2B5F60(X86Context& ctx, uint8_t* base) {
	// 0x2B5F60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B5F68: movss [0x0057260C], xmm0
	X86_MEM_WRITE_u32(base, 0x57260Cu, ctx.xmm[0].u32[0]);
	// 0x2B5F70: ret
	return;
}

void sub_2B5F80(X86Context& ctx, uint8_t* base) {
	// 0x2B5F80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B5F88: movss [0x005725F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5725F4u, ctx.xmm[0].u32[0]);
	// 0x2B5F90: ret
	return;
}

void sub_2B5FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B5FA0: movss xmm0, dword ptr [0x0057260C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57260Cu);
	// 0x2B5FA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B5FB0: movss [0x00572620], xmm0
	X86_MEM_WRITE_u32(base, 0x572620u, ctx.xmm[0].u32[0]);
	// 0x2B5FB8: ret
	return;
}

void sub_2B5FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B5FC0: movss xmm0, dword ptr [0x005725F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725F4u);
	// 0x2B5FC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B5FD0: movss [0x0057261C], xmm0
	X86_MEM_WRITE_u32(base, 0x57261Cu, ctx.xmm[0].u32[0]);
	// 0x2B5FD8: ret
	return;
}

void sub_2B5FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B5FE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B5FE8: movss [0x00572630], xmm0
	X86_MEM_WRITE_u32(base, 0x572630u, ctx.xmm[0].u32[0]);
	// 0x2B5FF0: ret
	return;
}

void sub_2B6000(X86Context& ctx, uint8_t* base) {
	// 0x2B6000: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B6008: movss [0x00572624], xmm0
	X86_MEM_WRITE_u32(base, 0x572624u, ctx.xmm[0].u32[0]);
	// 0x2B6010: ret
	return;
}

void sub_2B6020(X86Context& ctx, uint8_t* base) {
	// 0x2B6020: movss xmm0, dword ptr [0x00572624]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572624u);
	// 0x2B6028: movss [0x0057262C], xmm0
	X86_MEM_WRITE_u32(base, 0x57262Cu, ctx.xmm[0].u32[0]);
	// 0x2B6030: ret
	return;
}

void sub_2B6040(X86Context& ctx, uint8_t* base) {
	// 0x2B6040: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6048: movss [0x005725F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5725F0u, ctx.xmm[0].u32[0]);
	// 0x2B6050: ret
	return;
}

void sub_2B6060(X86Context& ctx, uint8_t* base) {
	// 0x2B6060: movss xmm0, dword ptr [0x005725F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725F4u);
	// 0x2B6068: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B6070: movss [0x00572628], xmm0
	X86_MEM_WRITE_u32(base, 0x572628u, ctx.xmm[0].u32[0]);
	// 0x2B6078: ret
	return;
}

void sub_2B6080(X86Context& ctx, uint8_t* base) {
	// 0x2B6080: movss xmm0, dword ptr [0x005725F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725F4u);
	// 0x2B6088: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B6090: movss [0x00572600], xmm0
	X86_MEM_WRITE_u32(base, 0x572600u, ctx.xmm[0].u32[0]);
	// 0x2B6098: ret
	return;
}

void sub_2B60A0(X86Context& ctx, uint8_t* base) {
	// 0x2B60A0: movss xmm0, dword ptr [0x005725F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5725F4u);
	// 0x2B60A8: subss xmm0, [0x00572600]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572600u);
	// 0x2B60B0: movss [0x005725FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5725FCu, ctx.xmm[0].u32[0]);
	// 0x2B60B8: ret
	return;
}

void sub_2B60C0(X86Context& ctx, uint8_t* base) {
	// 0x2B60C0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B60C8: movss [0x00572610], xmm0
	X86_MEM_WRITE_u32(base, 0x572610u, ctx.xmm[0].u32[0]);
	// 0x2B60D0: ret
	return;
}

void sub_2B60E0(X86Context& ctx, uint8_t* base) {
	// 0x2B60E0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B60E8: movss [0x005725F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5725F8u, ctx.xmm[0].u32[0]);
	// 0x2B60F0: ret
	return;
}

void sub_2B6100(X86Context& ctx, uint8_t* base) {
	// 0x2B6100: movss xmm0, dword ptr [0x003B1690]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1690u);
	// 0x2B6108: movss [0x00572618], xmm0
	X86_MEM_WRITE_u32(base, 0x572618u, ctx.xmm[0].u32[0]);
	// 0x2B6110: ret
	return;
}

void sub_2B6120(X86Context& ctx, uint8_t* base) {
	// 0x2B6120: movss xmm0, dword ptr [0x00399654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x399654u);
	// 0x2B6128: divss xmm0, [0x00409300]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409300u);
	// 0x2B6130: movss [0x00409308], xmm0
	X86_MEM_WRITE_u32(base, 0x409308u, ctx.xmm[0].u32[0]);
	// 0x2B6138: ret
	return;
}

void sub_2B6140(X86Context& ctx, uint8_t* base) {
	// 0x2B6140: movss xmm0, dword ptr [0x00399654]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x399654u);
	// 0x2B6148: divss xmm0, [0x00409300]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409300u);
	// 0x2B6150: movss [0x004A35F0], xmm0
	X86_MEM_WRITE_u32(base, 0x4A35F0u, ctx.xmm[0].u32[0]);
	// 0x2B6158: ret
	return;
}

void sub_2B6160(X86Context& ctx, uint8_t* base) {
	// 0x2B6160: movss xmm0, dword ptr [0x00398B9C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398B9Cu);
	// 0x2B6168: divss xmm0, [0x00409300]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409300u);
	// 0x2B6170: movss [0x00409310], xmm0
	X86_MEM_WRITE_u32(base, 0x409310u, ctx.xmm[0].u32[0]);
	// 0x2B6178: ret
	return;
}

void sub_2B6180(X86Context& ctx, uint8_t* base) {
	// 0x2B6180: movss xmm0, dword ptr [0x00389CB8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x389CB8u);
	// 0x2B6188: divss xmm0, [0x00409300]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409300u);
	// 0x2B6190: movss [0x004A35F8], xmm0
	X86_MEM_WRITE_u32(base, 0x4A35F8u, ctx.xmm[0].u32[0]);
	// 0x2B6198: ret
	return;
}

void sub_2B61A0(X86Context& ctx, uint8_t* base) {
	// 0x2B61A0: movss xmm0, dword ptr [0x003B231C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B231Cu);
	// 0x2B61A8: divss xmm0, [0x00409320]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409320u);
	// 0x2B61B0: movss [0x00409330], xmm0
	X86_MEM_WRITE_u32(base, 0x409330u, ctx.xmm[0].u32[0]);
	// 0x2B61B8: ret
	return;
}

void sub_2B61C0(X86Context& ctx, uint8_t* base) {
	// 0x2B61C0: movss xmm0, dword ptr [0x003B231C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B231Cu);
	// 0x2B61C8: divss xmm0, [0x00409320]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409320u);
	// 0x2B61D0: movss [0x004A3600], xmm0
	X86_MEM_WRITE_u32(base, 0x4A3600u, ctx.xmm[0].u32[0]);
	// 0x2B61D8: ret
	return;
}

void sub_2B61E0(X86Context& ctx, uint8_t* base) {
	// 0x2B61E0: movss xmm0, dword ptr [0x00398C98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398C98u);
	// 0x2B61E8: divss xmm0, [0x00409320]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409320u);
	// 0x2B61F0: movss [0x00409338], xmm0
	X86_MEM_WRITE_u32(base, 0x409338u, ctx.xmm[0].u32[0]);
	// 0x2B61F8: ret
	return;
}

void sub_2B6200(X86Context& ctx, uint8_t* base) {
	// 0x2B6200: movss xmm0, dword ptr [0x00398C98]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x398C98u);
	// 0x2B6208: divss xmm0, [0x00409320]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409320u);
	// 0x2B6210: movss [0x004A3608], xmm0
	X86_MEM_WRITE_u32(base, 0x4A3608u, ctx.xmm[0].u32[0]);
	// 0x2B6218: ret
	return;
}

void sub_2B6220(X86Context& ctx, uint8_t* base) {
	// 0x2B6220: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B6228: movss [0x00572654], xmm0
	X86_MEM_WRITE_u32(base, 0x572654u, ctx.xmm[0].u32[0]);
	// 0x2B6230: ret
	return;
}

void sub_2B6240(X86Context& ctx, uint8_t* base) {
	// 0x2B6240: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B6248: movss [0x00572664], xmm0
	X86_MEM_WRITE_u32(base, 0x572664u, ctx.xmm[0].u32[0]);
	// 0x2B6250: ret
	return;
}

void sub_2B6260(X86Context& ctx, uint8_t* base) {
	// 0x2B6260: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B6268: movss [0x00572650], xmm0
	X86_MEM_WRITE_u32(base, 0x572650u, ctx.xmm[0].u32[0]);
	// 0x2B6270: ret
	return;
}

void sub_2B6280(X86Context& ctx, uint8_t* base) {
	// 0x2B6280: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B6288: movss [0x00572634], xmm0
	X86_MEM_WRITE_u32(base, 0x572634u, ctx.xmm[0].u32[0]);
	// 0x2B6290: ret
	return;
}

void sub_2B62A0(X86Context& ctx, uint8_t* base) {
	// 0x2B62A0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B62A8: movss [0x00572658], xmm0
	X86_MEM_WRITE_u32(base, 0x572658u, ctx.xmm[0].u32[0]);
	// 0x2B62B0: ret
	return;
}

void sub_2B62C0(X86Context& ctx, uint8_t* base) {
	// 0x2B62C0: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B62C8: movss [0x0057263C], xmm0
	X86_MEM_WRITE_u32(base, 0x57263Cu, ctx.xmm[0].u32[0]);
	// 0x2B62D0: ret
	return;
}

void sub_2B62E0(X86Context& ctx, uint8_t* base) {
	// 0x2B62E0: movss xmm0, dword ptr [0x00572658]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572658u);
	// 0x2B62E8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B62F0: movss [0x00572690], xmm0
	X86_MEM_WRITE_u32(base, 0x572690u, ctx.xmm[0].u32[0]);
	// 0x2B62F8: ret
	return;
}

void sub_2B6300(X86Context& ctx, uint8_t* base) {
	// 0x2B6300: movss xmm0, dword ptr [0x0057263C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57263Cu);
	// 0x2B6308: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B6310: movss [0x00572668], xmm0
	X86_MEM_WRITE_u32(base, 0x572668u, ctx.xmm[0].u32[0]);
	// 0x2B6318: ret
	return;
}

void sub_2B6320(X86Context& ctx, uint8_t* base) {
	// 0x2B6320: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6328: movss [0x005726A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5726A0u, ctx.xmm[0].u32[0]);
	// 0x2B6330: ret
	return;
}

void sub_2B6340(X86Context& ctx, uint8_t* base) {
	// 0x2B6340: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B6348: movss [0x00572694], xmm0
	X86_MEM_WRITE_u32(base, 0x572694u, ctx.xmm[0].u32[0]);
	// 0x2B6350: ret
	return;
}

void sub_2B6360(X86Context& ctx, uint8_t* base) {
	// 0x2B6360: movss xmm0, dword ptr [0x00572694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572694u);
	// 0x2B6368: movss [0x0057269C], xmm0
	X86_MEM_WRITE_u32(base, 0x57269Cu, ctx.xmm[0].u32[0]);
	// 0x2B6370: ret
	return;
}

void sub_2B6380(X86Context& ctx, uint8_t* base) {
	// 0x2B6380: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6388: movss [0x00572638], xmm0
	X86_MEM_WRITE_u32(base, 0x572638u, ctx.xmm[0].u32[0]);
	// 0x2B6390: ret
	return;
}

void sub_2B63A0(X86Context& ctx, uint8_t* base) {
	// 0x2B63A0: movss xmm0, dword ptr [0x0057263C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57263Cu);
	// 0x2B63A8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B63B0: movss [0x00572698], xmm0
	X86_MEM_WRITE_u32(base, 0x572698u, ctx.xmm[0].u32[0]);
	// 0x2B63B8: ret
	return;
}

void sub_2B63C0(X86Context& ctx, uint8_t* base) {
	// 0x2B63C0: movss xmm0, dword ptr [0x0057263C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57263Cu);
	// 0x2B63C8: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B63D0: movss [0x0057264C], xmm0
	X86_MEM_WRITE_u32(base, 0x57264Cu, ctx.xmm[0].u32[0]);
	// 0x2B63D8: ret
	return;
}

void sub_2B63E0(X86Context& ctx, uint8_t* base) {
	// 0x2B63E0: movss xmm0, dword ptr [0x0057263C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57263Cu);
	// 0x2B63E8: subss xmm0, [0x0057264C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57264Cu);
	// 0x2B63F0: movss [0x00572644], xmm0
	X86_MEM_WRITE_u32(base, 0x572644u, ctx.xmm[0].u32[0]);
	// 0x2B63F8: ret
	return;
}

void sub_2B6400(X86Context& ctx, uint8_t* base) {
	// 0x2B6400: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B6408: movss [0x00572660], xmm0
	X86_MEM_WRITE_u32(base, 0x572660u, ctx.xmm[0].u32[0]);
	// 0x2B6410: ret
	return;
}

void sub_2B6420(X86Context& ctx, uint8_t* base) {
	// 0x2B6420: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B6428: movss [0x00572640], xmm0
	X86_MEM_WRITE_u32(base, 0x572640u, ctx.xmm[0].u32[0]);
	// 0x2B6430: ret
	return;
}

void sub_2B6440(X86Context& ctx, uint8_t* base) {
	// 0x2B6440: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B6441: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B6443: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B6446: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B6449: movss xmm0, dword ptr [0x003B1C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B6451: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B6456: movss xmm0, dword ptr [0x003B1684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2B645E: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B6461: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B6467: movss xmm0, dword ptr [0x003B1900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1900u);
	// 0x2B646F: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B6473: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B6479: movss xmm0, dword ptr [0x003B2228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2228u);
	// 0x2B6481: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B6485: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B648B: mov [0x00572670], eax
	X86_MEM_WRITE_u32(base, 0x572670u, ctx.eax);
	// 0x2B6490: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B6494: mov [0x00572674], ecx
	X86_MEM_WRITE_u32(base, 0x572674u, ctx.ecx);
	// 0x2B649A: mov [0x00572678], edx
	X86_MEM_WRITE_u32(base, 0x572678u, ctx.edx);
	// 0x2B64A0: mov [0x0057267C], eax
	X86_MEM_WRITE_u32(base, 0x57267Cu, ctx.eax);
	// 0x2B64A5: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B64A7: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B64A8: ret
	return;
}

void sub_2B64B0(X86Context& ctx, uint8_t* base) {
	// 0x2B64B0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B64B1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B64B3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B64B6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B64B9: movss xmm0, dword ptr [0x003B1C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B64C1: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B64C6: movss xmm0, dword ptr [0x003B2228]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2228u);
	// 0x2B64CE: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B64D1: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B64D7: movss xmm0, dword ptr [0x003B1900]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1900u);
	// 0x2B64DF: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B64E3: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B64E9: movss xmm0, dword ptr [0x003B1684]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1684u);
	// 0x2B64F1: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B64F5: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B64FB: mov [0x00572680], eax
	X86_MEM_WRITE_u32(base, 0x572680u, ctx.eax);
	// 0x2B6500: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B6504: mov [0x00572684], ecx
	X86_MEM_WRITE_u32(base, 0x572684u, ctx.ecx);
	// 0x2B650A: mov [0x00572688], edx
	X86_MEM_WRITE_u32(base, 0x572688u, ctx.edx);
	// 0x2B6510: mov [0x0057268C], eax
	X86_MEM_WRITE_u32(base, 0x57268Cu, ctx.eax);
	// 0x2B6515: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B6517: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B6518: ret
	return;
}

void sub_2B6520(X86Context& ctx, uint8_t* base) {
	// 0x2B6520: movss xmm0, dword ptr [0x003A7F34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3A7F34u);
	// 0x2B6528: movss [0x0057265C], xmm0
	X86_MEM_WRITE_u32(base, 0x57265Cu, ctx.xmm[0].u32[0]);
	// 0x2B6530: ret
	return;
}

void sub_2B6540(X86Context& ctx, uint8_t* base) {
	// 0x2B6540: movss xmm0, dword ptr [0x0057265C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57265Cu);
	// 0x2B6548: mulss xmm0, [0x003B2320]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B2320u);
	// 0x2B6550: movss [0x00572648], xmm0
	X86_MEM_WRITE_u32(base, 0x572648u, ctx.xmm[0].u32[0]);
	// 0x2B6558: ret
	return;
}

void sub_2B6560(X86Context& ctx, uint8_t* base) {
	// 0x2B6560: movss xmm0, dword ptr [0x00572648]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572648u);
	// 0x2B6568: movss [0x004A3624], xmm0
	X86_MEM_WRITE_u32(base, 0x4A3624u, ctx.xmm[0].u32[0]);
	// 0x2B6570: ret
	return;
}

void sub_2B6580(X86Context& ctx, uint8_t* base) {
	// 0x2B6580: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B6588: movss [0x005726C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5726C0u, ctx.xmm[0].u32[0]);
	// 0x2B6590: ret
	return;
}

void sub_2B65A0(X86Context& ctx, uint8_t* base) {
	// 0x2B65A0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B65A8: movss [0x005726D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5726D0u, ctx.xmm[0].u32[0]);
	// 0x2B65B0: ret
	return;
}

void sub_2B65C0(X86Context& ctx, uint8_t* base) {
	// 0x2B65C0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B65C8: movss [0x005726BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5726BCu, ctx.xmm[0].u32[0]);
	// 0x2B65D0: ret
	return;
}

void sub_2B65E0(X86Context& ctx, uint8_t* base) {
	// 0x2B65E0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B65E8: movss [0x005726A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5726A4u, ctx.xmm[0].u32[0]);
	// 0x2B65F0: ret
	return;
}

void sub_2B6600(X86Context& ctx, uint8_t* base) {
	// 0x2B6600: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B6608: movss [0x005726C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5726C4u, ctx.xmm[0].u32[0]);
	// 0x2B6610: ret
	return;
}

void sub_2B6620(X86Context& ctx, uint8_t* base) {
	// 0x2B6620: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B6628: movss [0x005726AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5726ACu, ctx.xmm[0].u32[0]);
	// 0x2B6630: ret
	return;
}

void sub_2B6640(X86Context& ctx, uint8_t* base) {
	// 0x2B6640: movss xmm0, dword ptr [0x005726C4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726C4u);
	// 0x2B6648: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B6650: movss [0x005726D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5726D8u, ctx.xmm[0].u32[0]);
	// 0x2B6658: ret
	return;
}

void sub_2B6660(X86Context& ctx, uint8_t* base) {
	// 0x2B6660: movss xmm0, dword ptr [0x005726AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726ACu);
	// 0x2B6668: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B6670: movss [0x005726D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5726D4u, ctx.xmm[0].u32[0]);
	// 0x2B6678: ret
	return;
}

void sub_2B6680(X86Context& ctx, uint8_t* base) {
	// 0x2B6680: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6688: movss [0x005726E8], xmm0
	X86_MEM_WRITE_u32(base, 0x5726E8u, ctx.xmm[0].u32[0]);
	// 0x2B6690: ret
	return;
}

void sub_2B66A0(X86Context& ctx, uint8_t* base) {
	// 0x2B66A0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B66A8: movss [0x005726DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5726DCu, ctx.xmm[0].u32[0]);
	// 0x2B66B0: ret
	return;
}

void sub_2B66C0(X86Context& ctx, uint8_t* base) {
	// 0x2B66C0: movss xmm0, dword ptr [0x005726DC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726DCu);
	// 0x2B66C8: movss [0x005726E4], xmm0
	X86_MEM_WRITE_u32(base, 0x5726E4u, ctx.xmm[0].u32[0]);
	// 0x2B66D0: ret
	return;
}

void sub_2B66E0(X86Context& ctx, uint8_t* base) {
	// 0x2B66E0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B66E8: movss [0x005726A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5726A8u, ctx.xmm[0].u32[0]);
	// 0x2B66F0: ret
	return;
}

void sub_2B6700(X86Context& ctx, uint8_t* base) {
	// 0x2B6700: movss xmm0, dword ptr [0x005726AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726ACu);
	// 0x2B6708: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B6710: movss [0x005726E0], xmm0
	X86_MEM_WRITE_u32(base, 0x5726E0u, ctx.xmm[0].u32[0]);
	// 0x2B6718: ret
	return;
}

void sub_2B6720(X86Context& ctx, uint8_t* base) {
	// 0x2B6720: movss xmm0, dword ptr [0x005726AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726ACu);
	// 0x2B6728: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B6730: movss [0x005726B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5726B8u, ctx.xmm[0].u32[0]);
	// 0x2B6738: ret
	return;
}

void sub_2B6740(X86Context& ctx, uint8_t* base) {
	// 0x2B6740: movss xmm0, dword ptr [0x005726AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726ACu);
	// 0x2B6748: subss xmm0, [0x005726B8]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5726B8u);
	// 0x2B6750: movss [0x005726B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5726B4u, ctx.xmm[0].u32[0]);
	// 0x2B6758: ret
	return;
}

void sub_2B6760(X86Context& ctx, uint8_t* base) {
	// 0x2B6760: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B6768: movss [0x005726CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5726CCu, ctx.xmm[0].u32[0]);
	// 0x2B6770: ret
	return;
}

void sub_2B6780(X86Context& ctx, uint8_t* base) {
	// 0x2B6780: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B6788: movss [0x005726B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5726B0u, ctx.xmm[0].u32[0]);
	// 0x2B6790: ret
	return;
}

void sub_2B67A0(X86Context& ctx, uint8_t* base) {
	// 0x2B67A0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B67A8: movss [0x005726C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5726C8u, ctx.xmm[0].u32[0]);
	// 0x2B67B0: ret
	return;
}

void sub_2B67C0(X86Context& ctx, uint8_t* base) {
	// 0x2B67C0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B67C8: movss [0x00572708], xmm0
	X86_MEM_WRITE_u32(base, 0x572708u, ctx.xmm[0].u32[0]);
	// 0x2B67D0: ret
	return;
}

void sub_2B67E0(X86Context& ctx, uint8_t* base) {
	// 0x2B67E0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B67E8: movss [0x00572714], xmm0
	X86_MEM_WRITE_u32(base, 0x572714u, ctx.xmm[0].u32[0]);
	// 0x2B67F0: ret
	return;
}

void sub_2B6800(X86Context& ctx, uint8_t* base) {
	// 0x2B6800: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B6808: movss [0x00572704], xmm0
	X86_MEM_WRITE_u32(base, 0x572704u, ctx.xmm[0].u32[0]);
	// 0x2B6810: ret
	return;
}

void sub_2B6820(X86Context& ctx, uint8_t* base) {
	// 0x2B6820: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B6828: movss [0x005726EC], xmm0
	X86_MEM_WRITE_u32(base, 0x5726ECu, ctx.xmm[0].u32[0]);
	// 0x2B6830: ret
	return;
}

void sub_2B6840(X86Context& ctx, uint8_t* base) {
	// 0x2B6840: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B6848: movss [0x0057270C], xmm0
	X86_MEM_WRITE_u32(base, 0x57270Cu, ctx.xmm[0].u32[0]);
	// 0x2B6850: ret
	return;
}

void sub_2B6860(X86Context& ctx, uint8_t* base) {
	// 0x2B6860: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B6868: movss [0x005726F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5726F4u, ctx.xmm[0].u32[0]);
	// 0x2B6870: ret
	return;
}

void sub_2B6880(X86Context& ctx, uint8_t* base) {
	// 0x2B6880: movss xmm0, dword ptr [0x0057270C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x57270Cu);
	// 0x2B6888: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B6890: movss [0x0057271C], xmm0
	X86_MEM_WRITE_u32(base, 0x57271Cu, ctx.xmm[0].u32[0]);
	// 0x2B6898: ret
	return;
}

void sub_2B68A0(X86Context& ctx, uint8_t* base) {
	// 0x2B68A0: movss xmm0, dword ptr [0x005726F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726F4u);
	// 0x2B68A8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B68B0: movss [0x00572718], xmm0
	X86_MEM_WRITE_u32(base, 0x572718u, ctx.xmm[0].u32[0]);
	// 0x2B68B8: ret
	return;
}

void sub_2B68C0(X86Context& ctx, uint8_t* base) {
	// 0x2B68C0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B68C8: movss [0x0057272C], xmm0
	X86_MEM_WRITE_u32(base, 0x57272Cu, ctx.xmm[0].u32[0]);
	// 0x2B68D0: ret
	return;
}

void sub_2B68E0(X86Context& ctx, uint8_t* base) {
	// 0x2B68E0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B68E8: movss [0x00572720], xmm0
	X86_MEM_WRITE_u32(base, 0x572720u, ctx.xmm[0].u32[0]);
	// 0x2B68F0: ret
	return;
}

void sub_2B6900(X86Context& ctx, uint8_t* base) {
	// 0x2B6900: movss xmm0, dword ptr [0x00572720]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572720u);
	// 0x2B6908: movss [0x00572728], xmm0
	X86_MEM_WRITE_u32(base, 0x572728u, ctx.xmm[0].u32[0]);
	// 0x2B6910: ret
	return;
}

void sub_2B6920(X86Context& ctx, uint8_t* base) {
	// 0x2B6920: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6928: movss [0x005726F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5726F0u, ctx.xmm[0].u32[0]);
	// 0x2B6930: ret
	return;
}

void sub_2B6940(X86Context& ctx, uint8_t* base) {
	// 0x2B6940: movss xmm0, dword ptr [0x005726F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726F4u);
	// 0x2B6948: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B6950: movss [0x00572724], xmm0
	X86_MEM_WRITE_u32(base, 0x572724u, ctx.xmm[0].u32[0]);
	// 0x2B6958: ret
	return;
}

void sub_2B6960(X86Context& ctx, uint8_t* base) {
	// 0x2B6960: movss xmm0, dword ptr [0x005726F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726F4u);
	// 0x2B6968: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B6970: movss [0x00572700], xmm0
	X86_MEM_WRITE_u32(base, 0x572700u, ctx.xmm[0].u32[0]);
	// 0x2B6978: ret
	return;
}

void sub_2B6980(X86Context& ctx, uint8_t* base) {
	// 0x2B6980: movss xmm0, dword ptr [0x005726F4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5726F4u);
	// 0x2B6988: subss xmm0, [0x00572700]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572700u);
	// 0x2B6990: movss [0x005726FC], xmm0
	X86_MEM_WRITE_u32(base, 0x5726FCu, ctx.xmm[0].u32[0]);
	// 0x2B6998: ret
	return;
}

void sub_2B69A0(X86Context& ctx, uint8_t* base) {
	// 0x2B69A0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B69A8: movss [0x00572710], xmm0
	X86_MEM_WRITE_u32(base, 0x572710u, ctx.xmm[0].u32[0]);
	// 0x2B69B0: ret
	return;
}

void sub_2B69C0(X86Context& ctx, uint8_t* base) {
	// 0x2B69C0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B69C8: movss [0x005726F8], xmm0
	X86_MEM_WRITE_u32(base, 0x5726F8u, ctx.xmm[0].u32[0]);
	// 0x2B69D0: ret
	return;
}

void sub_2B69E0(X86Context& ctx, uint8_t* base) {
	// 0x2B69E0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B69E8: movss [0x00572760], xmm0
	X86_MEM_WRITE_u32(base, 0x572760u, ctx.xmm[0].u32[0]);
	// 0x2B69F0: ret
	return;
}

void sub_2B6A00(X86Context& ctx, uint8_t* base) {
	// 0x2B6A00: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B6A08: movss [0x0057276C], xmm0
	X86_MEM_WRITE_u32(base, 0x57276Cu, ctx.xmm[0].u32[0]);
	// 0x2B6A10: ret
	return;
}

void sub_2B6A20(X86Context& ctx, uint8_t* base) {
	// 0x2B6A20: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B6A28: movss [0x0057275C], xmm0
	X86_MEM_WRITE_u32(base, 0x57275Cu, ctx.xmm[0].u32[0]);
	// 0x2B6A30: ret
	return;
}

void sub_2B6A40(X86Context& ctx, uint8_t* base) {
	// 0x2B6A40: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B6A48: movss [0x00572730], xmm0
	X86_MEM_WRITE_u32(base, 0x572730u, ctx.xmm[0].u32[0]);
	// 0x2B6A50: ret
	return;
}

void sub_2B6A60(X86Context& ctx, uint8_t* base) {
	// 0x2B6A60: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B6A68: movss [0x00572764], xmm0
	X86_MEM_WRITE_u32(base, 0x572764u, ctx.xmm[0].u32[0]);
	// 0x2B6A70: ret
	return;
}

void sub_2B6A80(X86Context& ctx, uint8_t* base) {
	// 0x2B6A80: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B6A88: movss [0x00572738], xmm0
	X86_MEM_WRITE_u32(base, 0x572738u, ctx.xmm[0].u32[0]);
	// 0x2B6A90: ret
	return;
}

void sub_2B6AA0(X86Context& ctx, uint8_t* base) {
	// 0x2B6AA0: movss xmm0, dword ptr [0x00572764]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572764u);
	// 0x2B6AA8: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B6AB0: movss [0x00572774], xmm0
	X86_MEM_WRITE_u32(base, 0x572774u, ctx.xmm[0].u32[0]);
	// 0x2B6AB8: ret
	return;
}

void sub_2B6AC0(X86Context& ctx, uint8_t* base) {
	// 0x2B6AC0: movss xmm0, dword ptr [0x00572738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572738u);
	// 0x2B6AC8: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B6AD0: movss [0x00572770], xmm0
	X86_MEM_WRITE_u32(base, 0x572770u, ctx.xmm[0].u32[0]);
	// 0x2B6AD8: ret
	return;
}

void sub_2B6AE0(X86Context& ctx, uint8_t* base) {
	// 0x2B6AE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6AE8: movss [0x00572784], xmm0
	X86_MEM_WRITE_u32(base, 0x572784u, ctx.xmm[0].u32[0]);
	// 0x2B6AF0: ret
	return;
}

void sub_2B6B00(X86Context& ctx, uint8_t* base) {
	// 0x2B6B00: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B6B08: movss [0x00572778], xmm0
	X86_MEM_WRITE_u32(base, 0x572778u, ctx.xmm[0].u32[0]);
	// 0x2B6B10: ret
	return;
}

void sub_2B6B20(X86Context& ctx, uint8_t* base) {
	// 0x2B6B20: movss xmm0, dword ptr [0x00572778]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572778u);
	// 0x2B6B28: movss [0x00572780], xmm0
	X86_MEM_WRITE_u32(base, 0x572780u, ctx.xmm[0].u32[0]);
	// 0x2B6B30: ret
	return;
}

void sub_2B6B40(X86Context& ctx, uint8_t* base) {
	// 0x2B6B40: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6B48: movss [0x00572734], xmm0
	X86_MEM_WRITE_u32(base, 0x572734u, ctx.xmm[0].u32[0]);
	// 0x2B6B50: ret
	return;
}

void sub_2B6B60(X86Context& ctx, uint8_t* base) {
	// 0x2B6B60: movss xmm0, dword ptr [0x00572738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572738u);
	// 0x2B6B68: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B6B70: movss [0x0057277C], xmm0
	X86_MEM_WRITE_u32(base, 0x57277Cu, ctx.xmm[0].u32[0]);
	// 0x2B6B78: ret
	return;
}

void sub_2B6B80(X86Context& ctx, uint8_t* base) {
	// 0x2B6B80: movss xmm0, dword ptr [0x00572738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572738u);
	// 0x2B6B88: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B6B90: movss [0x00572758], xmm0
	X86_MEM_WRITE_u32(base, 0x572758u, ctx.xmm[0].u32[0]);
	// 0x2B6B98: ret
	return;
}

void sub_2B6BA0(X86Context& ctx, uint8_t* base) {
	// 0x2B6BA0: movss xmm0, dword ptr [0x00572738]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572738u);
	// 0x2B6BA8: subss xmm0, [0x00572758]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x572758u);
	// 0x2B6BB0: movss [0x00572740], xmm0
	X86_MEM_WRITE_u32(base, 0x572740u, ctx.xmm[0].u32[0]);
	// 0x2B6BB8: ret
	return;
}

void sub_2B6BC0(X86Context& ctx, uint8_t* base) {
	// 0x2B6BC0: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B6BC8: movss [0x00572768], xmm0
	X86_MEM_WRITE_u32(base, 0x572768u, ctx.xmm[0].u32[0]);
	// 0x2B6BD0: ret
	return;
}

void sub_2B6BE0(X86Context& ctx, uint8_t* base) {
	// 0x2B6BE0: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B6BE8: movss [0x0057273C], xmm0
	X86_MEM_WRITE_u32(base, 0x57273Cu, ctx.xmm[0].u32[0]);
	// 0x2B6BF0: ret
	return;
}

void sub_2B6C00(X86Context& ctx, uint8_t* base) {
	// 0x2B6C00: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B6C01: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B6C03: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B6C06: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B6C09: movss xmm0, dword ptr [0x003B225C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B225Cu);
	// 0x2B6C11: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B6C16: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B6C19: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B6C1F: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B6C27: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B6C2B: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B6C31: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B6C35: movss [esp+0x0C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[0].u32[0]);
	// 0x2B6C3B: mov [0x00572748], eax
	X86_MEM_WRITE_u32(base, 0x572748u, ctx.eax);
	// 0x2B6C40: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B6C44: mov [0x0057274C], ecx
	X86_MEM_WRITE_u32(base, 0x57274Cu, ctx.ecx);
	// 0x2B6C4A: mov [0x00572750], edx
	X86_MEM_WRITE_u32(base, 0x572750u, ctx.edx);
	// 0x2B6C50: mov [0x00572754], eax
	X86_MEM_WRITE_u32(base, 0x572754u, ctx.eax);
	// 0x2B6C55: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B6C57: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B6C58: ret
	return;
}

void sub_2B6C60(X86Context& ctx, uint8_t* base) {
	// 0x2B6C60: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B6C68: movss [0x005727A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5727A4u, ctx.xmm[0].u32[0]);
	// 0x2B6C70: ret
	return;
}

void sub_2B6C80(X86Context& ctx, uint8_t* base) {
	// 0x2B6C80: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B6C88: movss [0x005727B0], xmm0
	X86_MEM_WRITE_u32(base, 0x5727B0u, ctx.xmm[0].u32[0]);
	// 0x2B6C90: ret
	return;
}

void sub_2B6CA0(X86Context& ctx, uint8_t* base) {
	// 0x2B6CA0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B6CA8: movss [0x005727A0], xmm0
	X86_MEM_WRITE_u32(base, 0x5727A0u, ctx.xmm[0].u32[0]);
	// 0x2B6CB0: ret
	return;
}

void sub_2B6CC0(X86Context& ctx, uint8_t* base) {
	// 0x2B6CC0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B6CC8: movss [0x00572788], xmm0
	X86_MEM_WRITE_u32(base, 0x572788u, ctx.xmm[0].u32[0]);
	// 0x2B6CD0: ret
	return;
}

void sub_2B6CE0(X86Context& ctx, uint8_t* base) {
	// 0x2B6CE0: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B6CE8: movss [0x005727A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5727A8u, ctx.xmm[0].u32[0]);
	// 0x2B6CF0: ret
	return;
}

void sub_2B6D00(X86Context& ctx, uint8_t* base) {
	// 0x2B6D00: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B6D08: movss [0x00572790], xmm0
	X86_MEM_WRITE_u32(base, 0x572790u, ctx.xmm[0].u32[0]);
	// 0x2B6D10: ret
	return;
}

void sub_2B6D20(X86Context& ctx, uint8_t* base) {
	// 0x2B6D20: movss xmm0, dword ptr [0x005727A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5727A8u);
	// 0x2B6D28: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B6D30: movss [0x005727B8], xmm0
	X86_MEM_WRITE_u32(base, 0x5727B8u, ctx.xmm[0].u32[0]);
	// 0x2B6D38: ret
	return;
}

void sub_2B6D40(X86Context& ctx, uint8_t* base) {
	// 0x2B6D40: movss xmm0, dword ptr [0x00572790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572790u);
	// 0x2B6D48: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B6D50: movss [0x005727B4], xmm0
	X86_MEM_WRITE_u32(base, 0x5727B4u, ctx.xmm[0].u32[0]);
	// 0x2B6D58: ret
	return;
}

void sub_2B6D60(X86Context& ctx, uint8_t* base) {
	// 0x2B6D60: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6D68: movss [0x005727C8], xmm0
	X86_MEM_WRITE_u32(base, 0x5727C8u, ctx.xmm[0].u32[0]);
	// 0x2B6D70: ret
	return;
}

void sub_2B6D80(X86Context& ctx, uint8_t* base) {
	// 0x2B6D80: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B6D88: movss [0x005727BC], xmm0
	X86_MEM_WRITE_u32(base, 0x5727BCu, ctx.xmm[0].u32[0]);
	// 0x2B6D90: ret
	return;
}

void sub_2B6DA0(X86Context& ctx, uint8_t* base) {
	// 0x2B6DA0: movss xmm0, dword ptr [0x005727BC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5727BCu);
	// 0x2B6DA8: movss [0x005727C4], xmm0
	X86_MEM_WRITE_u32(base, 0x5727C4u, ctx.xmm[0].u32[0]);
	// 0x2B6DB0: ret
	return;
}

void sub_2B6DC0(X86Context& ctx, uint8_t* base) {
	// 0x2B6DC0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6DC8: movss [0x0057278C], xmm0
	X86_MEM_WRITE_u32(base, 0x57278Cu, ctx.xmm[0].u32[0]);
	// 0x2B6DD0: ret
	return;
}

void sub_2B6DE0(X86Context& ctx, uint8_t* base) {
	// 0x2B6DE0: movss xmm0, dword ptr [0x00572790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572790u);
	// 0x2B6DE8: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B6DF0: movss [0x005727C0], xmm0
	X86_MEM_WRITE_u32(base, 0x5727C0u, ctx.xmm[0].u32[0]);
	// 0x2B6DF8: ret
	return;
}

void sub_2B6E00(X86Context& ctx, uint8_t* base) {
	// 0x2B6E00: movss xmm0, dword ptr [0x00572790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572790u);
	// 0x2B6E08: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B6E10: movss [0x0057279C], xmm0
	X86_MEM_WRITE_u32(base, 0x57279Cu, ctx.xmm[0].u32[0]);
	// 0x2B6E18: ret
	return;
}

void sub_2B6E20(X86Context& ctx, uint8_t* base) {
	// 0x2B6E20: movss xmm0, dword ptr [0x00572790]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572790u);
	// 0x2B6E28: subss xmm0, [0x0057279C]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x57279Cu);
	// 0x2B6E30: movss [0x00572798], xmm0
	X86_MEM_WRITE_u32(base, 0x572798u, ctx.xmm[0].u32[0]);
	// 0x2B6E38: ret
	return;
}

void sub_2B6E40(X86Context& ctx, uint8_t* base) {
	// 0x2B6E40: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B6E48: movss [0x005727AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5727ACu, ctx.xmm[0].u32[0]);
	// 0x2B6E50: ret
	return;
}

void sub_2B6E60(X86Context& ctx, uint8_t* base) {
	// 0x2B6E60: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B6E68: movss [0x00572794], xmm0
	X86_MEM_WRITE_u32(base, 0x572794u, ctx.xmm[0].u32[0]);
	// 0x2B6E70: ret
	return;
}

void sub_2B6E80(X86Context& ctx, uint8_t* base) {
	// 0x2B6E80: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B6E88: movss [0x0057280C], xmm0
	X86_MEM_WRITE_u32(base, 0x57280Cu, ctx.xmm[0].u32[0]);
	// 0x2B6E90: ret
	return;
}

void sub_2B6EA0(X86Context& ctx, uint8_t* base) {
	// 0x2B6EA0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B6EA8: movss [0x0057281C], xmm0
	X86_MEM_WRITE_u32(base, 0x57281Cu, ctx.xmm[0].u32[0]);
	// 0x2B6EB0: ret
	return;
}

void sub_2B6EC0(X86Context& ctx, uint8_t* base) {
	// 0x2B6EC0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B6EC8: movss [0x005727F4], xmm0
	X86_MEM_WRITE_u32(base, 0x5727F4u, ctx.xmm[0].u32[0]);
	// 0x2B6ED0: ret
	return;
}

void sub_2B6EE0(X86Context& ctx, uint8_t* base) {
	// 0x2B6EE0: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B6EE8: movss [0x005727CC], xmm0
	X86_MEM_WRITE_u32(base, 0x5727CCu, ctx.xmm[0].u32[0]);
	// 0x2B6EF0: ret
	return;
}

void sub_2B6F00(X86Context& ctx, uint8_t* base) {
	// 0x2B6F00: movss xmm0, dword ptr [0x003B1F00]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1F00u);
	// 0x2B6F08: movss [0x00572810], xmm0
	X86_MEM_WRITE_u32(base, 0x572810u, ctx.xmm[0].u32[0]);
	// 0x2B6F10: ret
	return;
}

void sub_2B6F20(X86Context& ctx, uint8_t* base) {
	// 0x2B6F20: movss xmm0, dword ptr [0x003B1EEC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1EECu);
	// 0x2B6F28: movss [0x005727D4], xmm0
	X86_MEM_WRITE_u32(base, 0x5727D4u, ctx.xmm[0].u32[0]);
	// 0x2B6F30: ret
	return;
}

void sub_2B6F40(X86Context& ctx, uint8_t* base) {
	// 0x2B6F40: movss xmm0, dword ptr [0x00572810]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572810u);
	// 0x2B6F48: subss xmm0, [0x003A7964]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x3A7964u);
	// 0x2B6F50: movss [0x00572824], xmm0
	X86_MEM_WRITE_u32(base, 0x572824u, ctx.xmm[0].u32[0]);
	// 0x2B6F58: ret
	return;
}

void sub_2B6F60(X86Context& ctx, uint8_t* base) {
	// 0x2B6F60: movss xmm0, dword ptr [0x005727D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5727D4u);
	// 0x2B6F68: subss xmm0, [0x00388F08]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x388F08u);
	// 0x2B6F70: movss [0x00572820], xmm0
	X86_MEM_WRITE_u32(base, 0x572820u, ctx.xmm[0].u32[0]);
	// 0x2B6F78: ret
	return;
}

void sub_2B6F80(X86Context& ctx, uint8_t* base) {
	// 0x2B6F80: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6F88: movss [0x00572834], xmm0
	X86_MEM_WRITE_u32(base, 0x572834u, ctx.xmm[0].u32[0]);
	// 0x2B6F90: ret
	return;
}

void sub_2B6FA0(X86Context& ctx, uint8_t* base) {
	// 0x2B6FA0: movss xmm0, dword ptr [0x003897A8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3897A8u);
	// 0x2B6FA8: movss [0x00572828], xmm0
	X86_MEM_WRITE_u32(base, 0x572828u, ctx.xmm[0].u32[0]);
	// 0x2B6FB0: ret
	return;
}

void sub_2B6FC0(X86Context& ctx, uint8_t* base) {
	// 0x2B6FC0: movss xmm0, dword ptr [0x00572828]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x572828u);
	// 0x2B6FC8: movss [0x00572830], xmm0
	X86_MEM_WRITE_u32(base, 0x572830u, ctx.xmm[0].u32[0]);
	// 0x2B6FD0: ret
	return;
}

void sub_2B6FE0(X86Context& ctx, uint8_t* base) {
	// 0x2B6FE0: movss xmm0, dword ptr [0x003B1CA8]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1CA8u);
	// 0x2B6FE8: movss [0x005727D0], xmm0
	X86_MEM_WRITE_u32(base, 0x5727D0u, ctx.xmm[0].u32[0]);
	// 0x2B6FF0: ret
	return;
}

void sub_2B7000(X86Context& ctx, uint8_t* base) {
	// 0x2B7000: movss xmm0, dword ptr [0x005727D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5727D4u);
	// 0x2B7008: mulss xmm0, [0x003B1728]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x3B1728u);
	// 0x2B7010: movss [0x0057282C], xmm0
	X86_MEM_WRITE_u32(base, 0x57282Cu, ctx.xmm[0].u32[0]);
	// 0x2B7018: ret
	return;
}

void sub_2B7020(X86Context& ctx, uint8_t* base) {
	// 0x2B7020: movss xmm0, dword ptr [0x005727D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5727D4u);
	// 0x2B7028: mulss xmm0, [0x0039922C]
	ctx.xmm[0].f32[0] *= X86_MEM_READ_F32(base, 0x39922Cu);
	// 0x2B7030: movss [0x005727F0], xmm0
	X86_MEM_WRITE_u32(base, 0x5727F0u, ctx.xmm[0].u32[0]);
	// 0x2B7038: ret
	return;
}

void sub_2B7040(X86Context& ctx, uint8_t* base) {
	// 0x2B7040: movss xmm0, dword ptr [0x005727D4]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x5727D4u);
	// 0x2B7048: subss xmm0, [0x005727F0]
	ctx.xmm[0].f32[0] -= X86_MEM_READ_F32(base, 0x5727F0u);
	// 0x2B7050: movss [0x005727DC], xmm0
	X86_MEM_WRITE_u32(base, 0x5727DCu, ctx.xmm[0].u32[0]);
	// 0x2B7058: ret
	return;
}

void sub_2B7060(X86Context& ctx, uint8_t* base) {
	// 0x2B7060: movss xmm0, dword ptr [0x003B1694]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1694u);
	// 0x2B7068: movss [0x00572818], xmm0
	X86_MEM_WRITE_u32(base, 0x572818u, ctx.xmm[0].u32[0]);
	// 0x2B7070: ret
	return;
}

void sub_2B7080(X86Context& ctx, uint8_t* base) {
	// 0x2B7080: movss xmm0, dword ptr [0x003B16D0]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B16D0u);
	// 0x2B7088: movss [0x005727D8], xmm0
	X86_MEM_WRITE_u32(base, 0x5727D8u, ctx.xmm[0].u32[0]);
	// 0x2B7090: ret
	return;
}

void sub_2B70A0(X86Context& ctx, uint8_t* base) {
	// 0x2B70A0: movss xmm0, dword ptr [0x003B168C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B70A8: movss [0x00572814], xmm0
	X86_MEM_WRITE_u32(base, 0x572814u, ctx.xmm[0].u32[0]);
	// 0x2B70B0: ret
	return;
}

void sub_2B70C0(X86Context& ctx, uint8_t* base) {
	// 0x2B70C0: movss xmm0, dword ptr [0x003B17AC]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B17ACu);
	// 0x2B70C8: movss [0x00572808], xmm0
	X86_MEM_WRITE_u32(base, 0x572808u, ctx.xmm[0].u32[0]);
	// 0x2B70D0: ret
	return;
}

void sub_2B70E0(X86Context& ctx, uint8_t* base) {
	// 0x2B70E0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B70E1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B70E3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B70E6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B70E9: movss xmm1, dword ptr [0x003B168C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B70F1: movss xmm2, dword ptr [0x003B1E24]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B1E24u);
	// 0x2B70F9: movaps xmm0, xmm1
	ctx.xmm[0] = ctx.xmm[1];
	// 0x2B70FC: divss xmm0, [0x00409800]
	ctx.xmm[0].f32[0] /= X86_MEM_READ_F32(base, 0x409800u);
	// 0x2B7104: divss xmm1, [0x00409804]
	ctx.xmm[1].f32[0] /= X86_MEM_READ_F32(base, 0x409804u);
	// 0x2B710C: movaps xmm3, xmm0
	ctx.xmm[3] = ctx.xmm[0];
	// 0x2B710F: mulss xmm3, xmm2
	ctx.xmm[3].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B7113: movss [esp], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[3].u32[0]);
	// 0x2B7118: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B711B: movaps xmm3, xmm1
	ctx.xmm[3] = ctx.xmm[1];
	// 0x2B711E: mulss xmm3, xmm2
	ctx.xmm[3].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B7122: movss xmm2, dword ptr [0x003B17C8]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x3B17C8u);
	// 0x2B712A: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B712E: mulss xmm1, xmm2
	ctx.xmm[1].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B7132: movss [esp+0x04], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[3].u32[0]);
	// 0x2B7138: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B713C: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B7142: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B7146: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B714C: mov [0x005727F8], eax
	X86_MEM_WRITE_u32(base, 0x5727F8u, ctx.eax);
	// 0x2B7151: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B7155: mov [0x005727FC], ecx
	X86_MEM_WRITE_u32(base, 0x5727FCu, ctx.ecx);
	// 0x2B715B: mov [0x00572800], edx
	X86_MEM_WRITE_u32(base, 0x572800u, ctx.edx);
	// 0x2B7161: mov [0x00572804], eax
	X86_MEM_WRITE_u32(base, 0x572804u, ctx.eax);
	// 0x2B7166: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B7168: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B7169: ret
	return;
}

void sub_2B7170(X86Context& ctx, uint8_t* base) {
	// 0x2B7170: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B7171: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B7173: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B7176: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B7179: movss xmm1, dword ptr [0x003B168C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B7181: movss xmm2, dword ptr [0x00409800]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x409800u);
	// 0x2B7189: xorps xmm3, xmm3
	memset(&ctx.xmm[3], 0, sizeof(ctx.xmm[3]));
	// 0x2B718C: movaps xmm0, xmm1
	ctx.xmm[0] = ctx.xmm[1];
	// 0x2B718F: divss xmm0, xmm2
	ctx.xmm[0].f32[0] /= ctx.xmm[2].f32[0];
	// 0x2B7193: movaps xmm4, xmm0
	ctx.xmm[4] = ctx.xmm[0];
	// 0x2B7196: mulss xmm4, xmm3
	ctx.xmm[4].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B719A: movss [esp], xmm4
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[4].u32[0]);
	// 0x2B719F: movss xmm4, dword ptr [0x00409804]
	ctx.xmm[4].u32[0] = X86_MEM_READ_u32(base, 0x409804u);
	// 0x2B71A7: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B71AA: divss xmm1, xmm4
	ctx.xmm[1].f32[0] /= ctx.xmm[4].f32[0];
	// 0x2B71AE: movaps xmm5, xmm1
	ctx.xmm[5] = ctx.xmm[1];
	// 0x2B71B1: mulss xmm5, xmm3
	ctx.xmm[5].f32[0] *= ctx.xmm[3].f32[0];
	// 0x2B71B5: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B71B9: mulss xmm1, xmm4
	ctx.xmm[1].f32[0] *= ctx.xmm[4].f32[0];
	// 0x2B71BD: movss [esp+0x04], xmm5
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[5].u32[0]);
	// 0x2B71C3: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B71C7: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B71CD: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B71D1: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B71D7: mov [0x005727E0], eax
	X86_MEM_WRITE_u32(base, 0x5727E0u, ctx.eax);
	// 0x2B71DC: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B71E0: mov [0x005727E4], ecx
	X86_MEM_WRITE_u32(base, 0x5727E4u, ctx.ecx);
	// 0x2B71E6: mov [0x005727E8], edx
	X86_MEM_WRITE_u32(base, 0x5727E8u, ctx.edx);
	// 0x2B71EC: mov [0x005727EC], eax
	X86_MEM_WRITE_u32(base, 0x5727ECu, ctx.eax);
	// 0x2B71F1: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B71F3: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B71F4: ret
	return;
}

void sub_2B7200(X86Context& ctx, uint8_t* base) {
	// 0x2B7200: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B7201: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B7203: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B7206: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B7209: movss xmm1, dword ptr [0x003B168C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B7211: movss xmm2, dword ptr [0x00409800]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x409800u);
	// 0x2B7219: movaps xmm0, xmm1
	ctx.xmm[0] = ctx.xmm[1];
	// 0x2B721C: divss xmm0, xmm2
	ctx.xmm[0].f32[0] /= ctx.xmm[2].f32[0];
	// 0x2B7220: movaps xmm3, xmm0
	ctx.xmm[3] = ctx.xmm[0];
	// 0x2B7223: mulss xmm3, xmm2
	ctx.xmm[3].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B7227: movss xmm2, dword ptr [0x00409804]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x409804u);
	// 0x2B722F: movss [esp], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[3].u32[0]);
	// 0x2B7234: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B7237: divss xmm1, xmm2
	ctx.xmm[1].f32[0] /= ctx.xmm[2].f32[0];
	// 0x2B723B: movaps xmm3, xmm1
	ctx.xmm[3] = ctx.xmm[1];
	// 0x2B723E: mulss xmm3, xmm2
	ctx.xmm[3].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B7242: xorps xmm2, xmm2
	memset(&ctx.xmm[2], 0, sizeof(ctx.xmm[2]));
	// 0x2B7245: mulss xmm0, xmm2
	ctx.xmm[0].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B7249: mulss xmm1, xmm2
	ctx.xmm[1].f32[0] *= ctx.xmm[2].f32[0];
	// 0x2B724D: movss [esp+0x04], xmm3
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[3].u32[0]);
	// 0x2B7253: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B7257: movss [esp+0x08], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[0].u32[0]);
	// 0x2B725D: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B7261: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B7267: mov [0x00572838], eax
	X86_MEM_WRITE_u32(base, 0x572838u, ctx.eax);
	// 0x2B726C: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B7270: mov [0x0057283C], ecx
	X86_MEM_WRITE_u32(base, 0x57283Cu, ctx.ecx);
	// 0x2B7276: mov [0x00572840], edx
	X86_MEM_WRITE_u32(base, 0x572840u, ctx.edx);
	// 0x2B727C: mov [0x00572844], eax
	X86_MEM_WRITE_u32(base, 0x572844u, ctx.eax);
	// 0x2B7281: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B7283: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B7284: ret
	return;
}

void sub_2B7290(X86Context& ctx, uint8_t* base) {
	// 0x2B7290: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7298: movss [0x0057285C], xmm0
	X86_MEM_WRITE_u32(base, 0x57285Cu, ctx.xmm[0].u32[0]);
	// 0x2B72A0: ret
	return;
}

void sub_2B72B0(X86Context& ctx, uint8_t* base) {
	// 0x2B72B0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B72B8: movss [0x00572860], xmm0
	X86_MEM_WRITE_u32(base, 0x572860u, ctx.xmm[0].u32[0]);
	// 0x2B72C0: ret
	return;
}

void sub_2B72D0(X86Context& ctx, uint8_t* base) {
	// 0x2B72D0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B72D8: movss [0x00572858], xmm0
	X86_MEM_WRITE_u32(base, 0x572858u, ctx.xmm[0].u32[0]);
	// 0x2B72E0: ret
	return;
}

void sub_2B72F0(X86Context& ctx, uint8_t* base) {
	// 0x2B72F0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B72F1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B72F3: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B72F6: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B72F9: movss xmm1, dword ptr [0x003B2328]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B2328u);
	// 0x2B7301: movss xmm0, dword ptr [0x003B2324]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2324u);
	// 0x2B7309: movss [esp+0x08], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[1].u32[0]);
	// 0x2B730F: movss xmm1, dword ptr [0x00409884]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x409884u);
	// 0x2B7317: addss xmm1, [0x003B168C]
	ctx.xmm[1].f32[0] += X86_MEM_READ_F32(base, 0x3B168Cu);
	// 0x2B731F: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B7323: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B7328: movss xmm0, dword ptr [0x003B1C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B7330: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B7333: mulss xmm1, xmm0
	ctx.xmm[1].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B7337: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B733D: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B7341: movss [esp+0x0C], xmm1
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[1].u32[0]);
	// 0x2B7347: mov [0x00572848], eax
	X86_MEM_WRITE_u32(base, 0x572848u, ctx.eax);
	// 0x2B734C: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B7350: mov [0x0057284C], ecx
	X86_MEM_WRITE_u32(base, 0x57284Cu, ctx.ecx);
	// 0x2B7356: mov [0x00572850], edx
	X86_MEM_WRITE_u32(base, 0x572850u, ctx.edx);
	// 0x2B735C: mov [0x00572854], eax
	X86_MEM_WRITE_u32(base, 0x572854u, ctx.eax);
	// 0x2B7361: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B7363: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B7364: ret
	return;
}

void sub_2B7370(X86Context& ctx, uint8_t* base) {
	// 0x2B7370: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2B7371: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2B7373: and esp, 0xFFFFFFF8
	ctx.esp = ctx.esp & -8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x2B7376: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2B7379: movss xmm0, dword ptr [0x003B1C30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B1C30u);
	// 0x2B7381: movss xmm1, dword ptr [0x003B168C]
	ctx.xmm[1].u32[0] = X86_MEM_READ_u32(base, 0x3B168Cu);
	// 0x2B7389: movss xmm2, dword ptr [0x00409880]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x409880u);
	// 0x2B7391: addss xmm2, xmm1
	ctx.xmm[2].f32[0] += ctx.xmm[1].f32[0];
	// 0x2B7395: mulss xmm2, xmm0
	ctx.xmm[2].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B7399: movss [esp+0x08], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.xmm[2].u32[0]);
	// 0x2B739F: movss xmm2, dword ptr [0x00409884]
	ctx.xmm[2].u32[0] = X86_MEM_READ_u32(base, 0x409884u);
	// 0x2B73A7: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2B73AB: movss [esp], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.xmm[0].u32[0]);
	// 0x2B73B0: mov eax, [esp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	// 0x2B73B3: addss xmm2, xmm1
	ctx.xmm[2].f32[0] += ctx.xmm[1].f32[0];
	// 0x2B73B7: mulss xmm2, xmm0
	ctx.xmm[2].f32[0] *= ctx.xmm[0].f32[0];
	// 0x2B73BB: movss [esp+0x04], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.xmm[0].u32[0]);
	// 0x2B73C1: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2B73C5: movss [esp+0x0C], xmm2
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.xmm[2].u32[0]);
	// 0x2B73CB: mov [0x00572868], eax
	X86_MEM_WRITE_u32(base, 0x572868u, ctx.eax);
	// 0x2B73D0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2B73D4: mov [0x0057286C], ecx
	X86_MEM_WRITE_u32(base, 0x57286Cu, ctx.ecx);
	// 0x2B73DA: mov [0x00572870], edx
	X86_MEM_WRITE_u32(base, 0x572870u, ctx.edx);
	// 0x2B73E0: mov [0x00572874], eax
	X86_MEM_WRITE_u32(base, 0x572874u, ctx.eax);
	// 0x2B73E5: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x2B73E7: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2B73E8: ret
	return;
}

void sub_2B73F0(X86Context& ctx, uint8_t* base) {
	// 0x2B73F0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B73F8: movss [0x00572880], xmm0
	X86_MEM_WRITE_u32(base, 0x572880u, ctx.xmm[0].u32[0]);
	// 0x2B7400: ret
	return;
}

void sub_2B7410(X86Context& ctx, uint8_t* base) {
	// 0x2B7410: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7418: movss [0x00572884], xmm0
	X86_MEM_WRITE_u32(base, 0x572884u, ctx.xmm[0].u32[0]);
	// 0x2B7420: ret
	return;
}

void sub_2B7430(X86Context& ctx, uint8_t* base) {
	// 0x2B7430: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7438: movss [0x0057287C], xmm0
	X86_MEM_WRITE_u32(base, 0x57287Cu, ctx.xmm[0].u32[0]);
	// 0x2B7440: ret
	return;
}

void sub_2B7450(X86Context& ctx, uint8_t* base) {
	// 0x2B7450: movss xmm0, dword ptr [0x003B2110]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2110u);
	// 0x2B7458: movss [0x00572878], xmm0
	X86_MEM_WRITE_u32(base, 0x572878u, ctx.xmm[0].u32[0]);
	// 0x2B7460: ret
	return;
}

void sub_2B7470(X86Context& ctx, uint8_t* base) {
	// 0x2B7470: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7478: movss [0x0057288C], xmm0
	X86_MEM_WRITE_u32(base, 0x57288Cu, ctx.xmm[0].u32[0]);
	// 0x2B7480: ret
	return;
}

void sub_2B7490(X86Context& ctx, uint8_t* base) {
	// 0x2B7490: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7498: movss [0x00572890], xmm0
	X86_MEM_WRITE_u32(base, 0x572890u, ctx.xmm[0].u32[0]);
	// 0x2B74A0: ret
	return;
}

void sub_2B74B0(X86Context& ctx, uint8_t* base) {
	// 0x2B74B0: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B74B8: movss [0x00572888], xmm0
	X86_MEM_WRITE_u32(base, 0x572888u, ctx.xmm[0].u32[0]);
	// 0x2B74C0: ret
	return;
}

void sub_2B74D0(X86Context& ctx, uint8_t* base) {
	// 0x2B74D0: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B74D8: movss [0x00572898], xmm0
	X86_MEM_WRITE_u32(base, 0x572898u, ctx.xmm[0].u32[0]);
	// 0x2B74E0: ret
	return;
}

void sub_2B74F0(X86Context& ctx, uint8_t* base) {
	// 0x2B74F0: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B74F8: movss [0x0057289C], xmm0
	X86_MEM_WRITE_u32(base, 0x57289Cu, ctx.xmm[0].u32[0]);
	// 0x2B7500: ret
	return;
}

void sub_2B7510(X86Context& ctx, uint8_t* base) {
	// 0x2B7510: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7518: movss [0x00572894], xmm0
	X86_MEM_WRITE_u32(base, 0x572894u, ctx.xmm[0].u32[0]);
	// 0x2B7520: ret
	return;
}

void sub_2B7530(X86Context& ctx, uint8_t* base) {
	// 0x2B7530: movss xmm0, dword ptr [0x003B191C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B191Cu);
	// 0x2B7538: movss [0x005728A8], xmm0
	X86_MEM_WRITE_u32(base, 0x5728A8u, ctx.xmm[0].u32[0]);
	// 0x2B7540: ret
	return;
}

void sub_2B7550(X86Context& ctx, uint8_t* base) {
	// 0x2B7550: movss xmm0, dword ptr [0x003B2108]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B2108u);
	// 0x2B7558: movss [0x005728AC], xmm0
	X86_MEM_WRITE_u32(base, 0x5728ACu, ctx.xmm[0].u32[0]);
	// 0x2B7560: ret
	return;
}

void sub_2B7570(X86Context& ctx, uint8_t* base) {
	// 0x2B7570: movss xmm0, dword ptr [0x003B210C]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, 0x3B210Cu);
	// 0x2B7578: movss [0x005728A4], xmm0
	X86_MEM_WRITE_u32(base, 0x5728A4u, ctx.xmm[0].u32[0]);
	// 0x2B7580: ret
	return;
}

