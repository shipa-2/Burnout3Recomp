#include "x86_recomp_shared.h"

void IDirectSoundBuffer_SetLoopRegion(X86Context& ctx, uint8_t* base) {
	// 0x2F56D4: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F56D8: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F56DC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F56DE: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F56E2: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F56E5: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F56E7: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F56E9: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F56EB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F56EC: call 0x002F4B58
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetLoopRegion(ctx, base);
	ctx.esp += 4;
	// 0x2F56F1: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSoundBuffer_GetStatus(X86Context& ctx, uint8_t* base) {
	// 0x2F56F4: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F56F8: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F56FC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F56FE: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F5701: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F5703: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F5705: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F5707: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5708: call 0x002F4B07
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_GetStatus(ctx, base);
	ctx.esp += 4;
	// 0x2F570D: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_GetCurrentPosition(X86Context& ctx, uint8_t* base) {
	// 0x2F5710: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F5714: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5718: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F571A: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F571E: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F5721: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F5723: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F5725: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F5727: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5728: call 0x002F4BDD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_GetCurrentPosition(ctx, base);
	ctx.esp += 4;
	// 0x2F572D: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSoundBuffer_SetCurrentPosition(X86Context& ctx, uint8_t* base) {
	// 0x2F5730: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F5734: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5738: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F573A: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F573D: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F573F: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F5741: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F5743: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5744: call 0x002F4C32
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetCurrentPosition(ctx, base);
	ctx.esp += 4;
	// 0x2F5749: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundStream_SetVolume(X86Context& ctx, uint8_t* base) {
	// 0x2F574C: jmp 0x002F540A
	CDirectSoundStream_SetVolume(ctx, base);
	return;
}

void IDirectSoundStream_SetHeadroom(X86Context& ctx, uint8_t* base) {
	// 0x2F5751: jmp 0x002F545C
	CDirectSoundStream_SetHeadroom(ctx, base);
	return;
}

void IDirectSoundStream_SetMixBinVolumes(X86Context& ctx, uint8_t* base) {
	// 0x2F5756: jmp 0x002F54AE
	CDirectSoundStream_SetMixBinVolumes_8(ctx, base);
	return;
}

void IDirectSoundStream_Pause(X86Context& ctx, uint8_t* base) {
	// 0x2F575B: jmp 0x002F4F1D
	CDirectSoundStream_Pause(ctx, base);
	return;
}

void IDirectSoundStream_FlushEx(X86Context& ctx, uint8_t* base) {
	// 0x2F5760: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5764: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5768: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F576C: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5770: call 0x002F4F6E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundStream_FlushEx(ctx, base);
	ctx.esp += 4;
	// 0x2F5775: ret 0x10
	ctx.esp += 16;
	return;
}

void DirectSoundDoWork(X86Context& ctx, uint8_t* base) {
	// 0x2F5778: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5779: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F577E: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5781: mov eax, [0x00300B20]
	ctx.eax = X86_MEM_READ_u32(base, 0x300B20u);
	// 0x2F5786: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F5788: jz 0x002F5790
	if (ctx.flags.zf) goto loc_2F5790;
	// 0x2F578A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F578B: call 0x002F45C3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_DoWork(ctx, base);
	ctx.esp += 4;
loc_2F5790:
	// 0x2F5790: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5792: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5793: jz 0x002F57A0
	if (ctx.flags.zf) goto loc_2F57A0;
	// 0x2F5795: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F579A: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F57A0:
	// 0x2F57A0: ret
	return;
}

void sub_2F57A1(X86Context& ctx, uint8_t* base) {
	// 0x2F57A1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F57A2: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F57A4: call 0x002F42D5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F42D5(ctx, base);
	ctx.esp += 4;
	// 0x2F57A9: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F57AE: jz 0x002F57B6
	if (ctx.flags.zf) goto loc_2F57B6;
	// 0x2F57B0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F57B1: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F57B6:
	// 0x2F57B6: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F57B8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F57B9: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F57BC(X86Context& ctx, uint8_t* base) {
	// 0x2F57BC: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F57C0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F57C1: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F57C3: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F57C5: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F57C7: jnz 0x002F57F5
	if (!ctx.flags.zf) goto loc_2F57F5;
	// 0x2F57C9: test dword ptr [esi+0x08], 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x8u) & 2097168, 32);
	// 0x2F57D0: jz 0x002F57D9
	if (ctx.flags.zf) goto loc_2F57D9;
	// 0x2F57D2: mov eax, 0x300254
	ctx.eax = 3146324;
	// 0x2F57D7: jmp 0x002F57F5
	goto loc_2F57F5;
loc_2F57D9:
	// 0x2F57D9: cmp [esi+0xB0], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xB0u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F57DF: jz 0x002F57E8
	if (ctx.flags.zf) goto loc_2F57E8;
	// 0x2F57E1: mov eax, 0x2FEF9C
	ctx.eax = 3141532;
	// 0x2F57E6: jmp 0x002F57F5
	goto loc_2F57F5;
loc_2F57E8:
	// 0x2F57E8: movzx eax, byte ptr [esi+0x0E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0xEu));
	// 0x2F57EC: shr eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F57EE: mov eax, [eax*4+0x2FEF8C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x2FEF8Cu);
loc_2F57F5:
	// 0x2F57F5: cmp [eax], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F57F7: jbe 0x002F5818
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F5818;
	// 0x2F57F9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F57FA:
	// 0x2F57FA: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F57FD: mov dl, [edx+ecx*8]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.edx + ctx.ecx * 8);
	// 0x2F5800: mov [esi+ecx*1+0x28], dl
	X86_MEM_WRITE_u8(base, ctx.esi + ctx.ecx + 0x28u, X86_REG8L(ctx.edx));
	// 0x2F5804: mov edi, [eax+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F5807: mov edi, [edi+ecx*8+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi + ctx.ecx * 8 + 0x4u);
	// 0x2F580B: movzx edx, dl
	ctx.edx = (uint32_t)(X86_REG8L(ctx.edx));
	// 0x2F580E: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F580F: mov [esi+edx*4+0x30], edi
	X86_MEM_WRITE_u32(base, ctx.esi + ctx.edx * 4 + 0x30u, ctx.edi);
	// 0x2F5813: cmp ecx, [eax]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5815: jb 0x002F57FA
	if (ctx.flags.cf) goto loc_2F57FA;
	// 0x2F5817: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5818:
	// 0x2F5818: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F581A: mov [esi+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.eax);
	// 0x2F581D: mov eax, [esi+0xB0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xB0u);
	// 0x2F5823: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F5825: jz 0x002F5840
	if (ctx.flags.zf) goto loc_2F5840;
	// 0x2F5827: mov eax, [eax+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	// 0x2F582A: test dword ptr [eax+0x08], 0x82000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 532480, 32);
	// 0x2F5831: jz 0x002F5840
	if (ctx.flags.zf) goto loc_2F5840;
	// 0x2F5833: push [eax+0xD4]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xD4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5839: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F583B: call 0x002F4734
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F4734(ctx, base);
	ctx.esp += 4;
loc_2F5840:
	// 0x2F5840: test byte ptr [esi+0x08], 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x8u) & 16, 8);
	// 0x2F5844: jz 0x002F5883
	if (ctx.flags.zf) goto loc_2F5883;
	// 0x2F5846: cmp dword ptr [esi+0x24], 0x05
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x24u); uint32_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F584A: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F584C: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F584D: jb 0x002F586C
	if (ctx.flags.cf) goto loc_2F586C;
	// 0x2F584F: cmp [esi+0x2C], dl
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi + 0x2Cu); uint8_t _s = X86_REG8L(ctx.edx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F5852: jnz 0x002F586C
	if (!ctx.flags.zf) goto loc_2F586C;
	// 0x2F5854: lea ecx, [esi+0xB4]
	ctx.ecx = ctx.esi + 0xB4u;
	// 0x2F585A: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F585C: test [eax+0x58], dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x58u) & X86_REG8L(ctx.edx), 8);
	// 0x2F585F: jnz 0x002F5883
	if (!ctx.flags.zf) goto loc_2F5883;
	// 0x2F5861: or [eax+0x58], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x58u, X86_MEM_READ_u32(base, ctx.eax + 0x58u) | ctx.edx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x58u), 32);
	// 0x2F5864: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F5866: or byte ptr [eax+0x03], 0x04
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3u, X86_MEM_READ_u8(base, ctx.eax + 0x3u) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x3u), 8);
	// 0x2F586A: jmp 0x002F5883
	goto loc_2F5883;
loc_2F586C:
	// 0x2F586C: lea ecx, [esi+0xB4]
	ctx.ecx = ctx.esi + 0xB4u;
	// 0x2F5872: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F5874: test [eax+0x58], dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x58u) & X86_REG8L(ctx.edx), 8);
	// 0x2F5877: jz 0x002F5883
	if (ctx.flags.zf) goto loc_2F5883;
	// 0x2F5879: and dword ptr [eax+0x58], 0xFFFFFFFD
	X86_MEM_WRITE_u32(base, ctx.eax + 0x58u, X86_MEM_READ_u32(base, ctx.eax + 0x58u) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x58u), 32);
	// 0x2F587D: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F587F: or byte ptr [ecx+0x03], 0x04
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x3u, X86_MEM_READ_u8(base, ctx.ecx + 0x3u) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx + 0x3u), 8);
loc_2F5883:
	// 0x2F5883: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5884: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F5887(X86Context& ctx, uint8_t* base) {
	// 0x2F5887: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5888: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F588A: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F588D: and dword ptr [ebp-0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, X86_MEM_READ_u32(base, ctx.ebp - 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x14u), 32);
	// 0x2F5891: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5892: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F5894: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5895: lea ecx, [ebp-0x18]
	ctx.ecx = ctx.ebp - 0x18u;
	// 0x2F5898: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F589D: mov ecx, [esi+0xB0]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xB0u);
	// 0x2F58A3: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F58A5: jz 0x002F58FF
	if (ctx.flags.zf) goto loc_2F58FF;
	// 0x2F58A7: mov eax, [ecx+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x2F58AA: test dword ptr [eax+0x08], 0x82000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 532480, 32);
	// 0x2F58B1: jz 0x002F58F2
	if (ctx.flags.zf) goto loc_2F58F2;
	// 0x2F58B3: mov eax, [eax+0xD4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xD4u);
	// 0x2F58B9: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F58BB: cmp [esi+0x24], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x24u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F58BE: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F58C1: jbe 0x002F58E3
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F58E3;
	// 0x2F58C3: mov eax, [esi+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x2F58C6: lea edx, [esi+0x28]
	ctx.edx = ctx.esi + 0x28u;
	// 0x2F58C9: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F58CC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F58CD:
	// 0x2F58CD: mov al, [edx]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edx);
	// 0x2F58CF: movzx ebx, al
	ctx.ebx = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F58D2: cmp [ebp-0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F58D5: jz 0x002F58DC
	if (ctx.flags.zf) goto loc_2F58DC;
	// 0x2F58D7: mov [ebp+edi*1-0x10], al
	X86_MEM_WRITE_u8(base, ctx.ebp + ctx.edi - 0x10u, X86_REG8L(ctx.eax));
	// 0x2F58DB: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
loc_2F58DC:
	// 0x2F58DC: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F58DD: dec [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F58E0: jnz 0x002F58CD
	if (!ctx.flags.zf) goto loc_2F58CD;
	// 0x2F58E2: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F58E3:
	// 0x2F58E3: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2F58E6: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x2F58E9: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2F58EC: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x2F58EF: mov [esi+0x24], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.edi);
loc_2F58F2:
	// 0x2F58F2: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F58F4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F58F5: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F58F8: and dword ptr [esi+0xB0], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xB0u, X86_MEM_READ_u32(base, ctx.esi + 0xB0u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xB0u), 32);
loc_2F58FF:
	// 0x2F58FF: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5902: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F5907: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F5909: mov [esi+0xB0], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xB0u, ctx.eax);
	// 0x2F590F: jz 0x002F594C
	if (ctx.flags.zf) goto loc_2F594C;
	// 0x2F5911: mov eax, [eax+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	// 0x2F5914: test dword ptr [eax+0x08], 0x82000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 532480, 32);
	// 0x2F591B: jz 0x002F594C
	if (ctx.flags.zf) goto loc_2F594C;
	// 0x2F591D: mov edi, [eax+0xD4]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0xD4u);
	// 0x2F5923: and dword ptr [esi+0x24], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, X86_MEM_READ_u32(base, ctx.esi + 0x24u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x24u), 32);
	// 0x2F5927: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5928: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F592A: call 0x002F4734
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F4734(ctx, base);
	ctx.esp += 4;
	// 0x2F592F: movzx eax, byte ptr [esi+0x0E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0xEu));
	// 0x2F5933: mov [ebp+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.eax);
	// 0x2F5936: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5937: fild [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)));
	// 0x2F593A: fdivr [0x003B168C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu) / ctx.fp_stack[ctx.fp_top]);
	// 0x2F5940: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F5943: call 0x002F402B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F402B(ctx, base);
	ctx.esp += 4;
	// 0x2F5948: mov [esi+edi*4+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esi + ctx.edi * 4 + 0x30u, ctx.eax);
loc_2F594C:
	// 0x2F594C: lea ecx, [ebp-0x18]
	ctx.ecx = ctx.ebp - 0x18u;
	// 0x2F594F: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F5954: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5955: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5956: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5957: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F595A(X86Context& ctx, uint8_t* base) {
	// 0x2F595A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F595B: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F595F: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F5961: lea eax, [esi+0x14]
	ctx.eax = ctx.esi + 0x14u;
	// 0x2F5964: mov dword ptr [esi+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 1);
	// 0x2F596B: mov dword ptr [esi], 0x36C110
	X86_MEM_WRITE_u32(base, ctx.esi, 3588368);
	// 0x2F5971: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x2F5974: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F5976: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F597B: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x2F597E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F5980: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5981: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F5984(X86Context& ctx, uint8_t* base) {
	// 0x2F5984: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5985: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F5987: call 0x002F47A2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F47A2(ctx, base);
	ctx.esp += 4;
	// 0x2F598C: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F5991: jz 0x002F5999
	if (ctx.flags.zf) goto loc_2F5999;
	// 0x2F5993: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5994: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F5999:
	// 0x2F5999: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F599B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F599C: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F599F(X86Context& ctx, uint8_t* base) {
	// 0x2F599F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F59A0: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F59A4: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F59A9: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F59AD: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F59B1: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x2F59B4: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F59B9: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x2F59BC: test byte ptr [eax+0x08], 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x8u) & 16, 8);
	// 0x2F59C0: jz 0x002F5A32
	if (ctx.flags.zf) goto loc_2F5A32;
	// 0x2F59C2: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F59C5: lea eax, [esi+0x14]
	ctx.eax = ctx.esi + 0x14u;
	// 0x2F59C8: add ecx, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)16, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F59CB: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F59CD: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F59D0: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2F59D3: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F59D5: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F59D7: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2F59DA: mov eax, [0x00300498]
	ctx.eax = X86_MEM_READ_u32(base, 0x300498u);
	// 0x2F59DF: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x2F59E1: and edx, 0xFFFF
	ctx.edx = ctx.edx & 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2F59E7: cmp edx, 0x02
	{ uint32_t _d = ctx.edx; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F59EA: mov ecx, 0x4000000
	ctx.ecx = 67108864;
	// 0x2F59EF: jz 0x002F59F8
	if (ctx.flags.zf) goto loc_2F59F8;
	// 0x2F59F1: test eax, 0x10000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 65536, 32);
	// 0x2F59F6: jz 0x002F5A14
	if (ctx.flags.zf) goto loc_2F5A14;
loc_2F59F8:
	// 0x2F59F8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F59FA: js 0x002F5A14
	if (ctx.flags.sf) goto loc_2F5A14;
	// 0x2F59FC: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F59FF: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2F5A05: or dword ptr [eax+0x58], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x58u, X86_MEM_READ_u32(base, ctx.eax + 0x58u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x58u), 32);
	// 0x2F5A09: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F5A0C: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2F5A12: or [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
loc_2F5A14:
	// 0x2F5A14: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F5A17: test byte ptr [eax+0x0A], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xAu) & 2, 8);
	// 0x2F5A1B: jz 0x002F5A32
	if (ctx.flags.zf) goto loc_2F5A32;
	// 0x2F5A1D: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2F5A23: or dword ptr [eax+0x58], 0x04
	X86_MEM_WRITE_u32(base, ctx.eax + 0x58u, X86_MEM_READ_u32(base, ctx.eax + 0x58u) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x58u), 32);
	// 0x2F5A27: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F5A2A: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2F5A30: or [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) | ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
loc_2F5A32:
	// 0x2F5A32: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5A33: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSoundVoice_SetFrequency(X86Context& ctx, uint8_t* base) {
	// 0x2F5A36: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5A3A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F5A3C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A3D: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5A41: jnz 0x002F5A49
	if (!ctx.flags.zf) goto loc_2F5A49;
	// 0x2F5A43: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F5A46: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
loc_2F5A49:
	// 0x2F5A49: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A4A: call 0x002F424C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XAudioCalculatePitch(ctx, base);
	ctx.esp += 4;
	// 0x2F5A4F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A50: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A51: call 0x002F47EF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetPitch(ctx, base);
	ctx.esp += 4;
	// 0x2F5A56: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5A57: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundVoice_SetOutputBuffer(X86Context& ctx, uint8_t* base) {
	// 0x2F5A5A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A5B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A5C: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F5A60: lea eax, [esi-0x1C]
	ctx.eax = ctx.esi - 0x1Cu;
	// 0x2F5A63: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F5A65: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F5A67: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A68: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F5A6C: and esi, eax
	ctx.esi = ctx.esi & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F5A6E: mov eax, [edi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	// 0x2F5A71: mov eax, [eax+0xB0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB0u);
	// 0x2F5A77: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F5A79: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5A7B: jz 0x002F5AA6
	if (ctx.flags.zf) goto loc_2F5AA6;
	// 0x2F5A7D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F5A7F: jz 0x002F5A8F
	if (ctx.flags.zf) goto loc_2F5A8F;
	// 0x2F5A81: mov ecx, [edi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x2F5A84: call 0x002FB982
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB982(ctx, base);
	ctx.esp += 4;
	// 0x2F5A89: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2F5A8B: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F5A8D: jl 0x002F5AA6
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F5AA6;
loc_2F5A8F:
	// 0x2F5A8F: mov ecx, [edi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	// 0x2F5A92: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5A93: call 0x002F5887
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F5887(ctx, base);
	ctx.esp += 4;
	// 0x2F5A98: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5A9A: jz 0x002F5AA6
	if (ctx.flags.zf) goto loc_2F5AA6;
	// 0x2F5A9C: mov ecx, [edi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x2F5A9F: call 0x002FB875
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB875(ctx, base);
	ctx.esp += 4;
	// 0x2F5AA4: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_2F5AA6:
	// 0x2F5AA6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5AA7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5AA8: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F5AAA: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5AAB: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundVoice_SetMixBins(X86Context& ctx, uint8_t* base) {
	// 0x2F5AAE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5AAF: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5AB3: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5AB7: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F5ABA: call 0x002F57BC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F57BC(ctx, base);
	ctx.esp += 4;
	// 0x2F5ABF: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F5AC2: call 0x002FB3E1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetMixBins(ctx, base);
	ctx.esp += 4;
	// 0x2F5AC7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5AC8: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundVoice_SetAllParameters(X86Context& ctx, uint8_t* base) {
	// 0x2F5ACB: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F5ACF: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5AD2: mov edx, [ecx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5AD8: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5ADC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5ADD: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F5AE0: mov [edx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.esi);
	// 0x2F5AE3: mov esi, [ecx+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F5AE6: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5AE9: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5AEF: mov [edx+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.esi);
	// 0x2F5AF2: mov esi, [ecx+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x2F5AF5: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5AF8: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5AFE: mov [edx+0x10], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x10u, ctx.esi);
	// 0x2F5B01: mov esi, [ecx+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x2F5B04: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B07: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B0D: mov [edx+0x14], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x14u, ctx.esi);
	// 0x2F5B10: mov esi, [ecx+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x2F5B13: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B16: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B1C: mov [edx+0x18], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x18u, ctx.esi);
	// 0x2F5B1F: mov esi, [ecx+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x2F5B22: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B25: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B2B: mov [edx+0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x1Cu, ctx.esi);
	// 0x2F5B2E: mov esi, [ecx+0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x2F5B31: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B34: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B3A: mov [edx+0x20], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x20u, ctx.esi);
	// 0x2F5B3D: mov esi, [ecx+0x20]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x2F5B40: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B43: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B49: mov [edx+0x24], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x24u, ctx.esi);
	// 0x2F5B4C: mov esi, [ecx+0x24]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x24u);
	// 0x2F5B4F: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B52: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B58: mov [edx+0x28], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x28u, ctx.esi);
	// 0x2F5B5B: mov esi, [ecx+0x28]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x28u);
	// 0x2F5B5E: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B61: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B67: mov [edx+0x2C], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x2Cu, ctx.esi);
	// 0x2F5B6A: mov esi, [ecx+0x2C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x2Cu);
	// 0x2F5B6D: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B70: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B76: mov [edx+0x30], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x30u, ctx.esi);
	// 0x2F5B79: mov esi, [ecx+0x30]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x30u);
	// 0x2F5B7C: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B7F: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B85: mov [edx+0x34], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x34u, ctx.esi);
	// 0x2F5B88: mov esi, [ecx+0x34]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x34u);
	// 0x2F5B8B: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B8E: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5B94: mov [edx+0x38], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x38u, ctx.esi);
	// 0x2F5B97: mov esi, [ecx+0x38]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x38u);
	// 0x2F5B9A: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5B9D: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5BA3: mov [edx+0x3C], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x3Cu, ctx.esi);
	// 0x2F5BA6: mov esi, [ecx+0x3C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x3Cu);
	// 0x2F5BA9: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5BAC: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5BB2: mov [edx+0x40], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x40u, ctx.esi);
	// 0x2F5BB5: mov esi, [ecx+0x40]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x40u);
	// 0x2F5BB8: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5BBB: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5BC1: mov [edx+0x44], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x44u, ctx.esi);
	// 0x2F5BC4: mov esi, [ecx+0x44]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x44u);
	// 0x2F5BC7: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5BCA: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5BD0: mov [edx+0x48], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x48u, ctx.esi);
	// 0x2F5BD3: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5BD6: mov ecx, [ecx+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x48u);
	// 0x2F5BD9: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5BDF: mov [edx+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4Cu, ctx.ecx);
	// 0x2F5BE2: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5BE5: mov ecx, [ecx+0xB4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5BEB: or word ptr [ecx+0x02], 0xFFFF
	X86_MEM_WRITE_u16(base, ctx.ecx + 0x2u, X86_MEM_READ_u16(base, ctx.ecx + 0x2u) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ecx + 0x2u), 16);
	// 0x2F5BF0: test byte ptr [esp+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x10u) & 1, 8);
	// 0x2F5BF5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5BF6: jnz 0x002F5BFE
	if (!ctx.flags.zf) goto loc_2F5BFE;
	// 0x2F5BF8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5BF9: call 0x002F4864
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F5BFE:
	// 0x2F5BFE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F5C00: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSoundVoice_SetRolloffCurve(X86Context& ctx, uint8_t* base) {
	// 0x2F5C03: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F5C07: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C0A: mov ecx, [ecx+0xB4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5C10: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5C14: mov [ecx+0x50], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x50u, ctx.edx);
	// 0x2F5C17: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C1A: mov ecx, [ecx+0xB4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5C20: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F5C24: mov [ecx+0x54], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x54u, ctx.edx);
	// 0x2F5C27: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C2A: mov ecx, [ecx+0xB4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5C30: or byte ptr [ecx+0x03], 0x01
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x3u, X86_MEM_READ_u8(base, ctx.ecx + 0x3u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx + 0x3u), 8);
	// 0x2F5C34: test byte ptr [esp+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x10u) & 1, 8);
	// 0x2F5C39: jnz 0x002F5C41
	if (!ctx.flags.zf) goto loc_2F5C41;
	// 0x2F5C3B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5C3C: call 0x002F4864
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F5C41:
	// 0x2F5C41: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F5C43: ret 0x10
	ctx.esp += 16;
	return;
}

void CDirectSoundVoice_SetI3DL2Source(X86Context& ctx, uint8_t* base) {
	// 0x2F5C46: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F5C4A: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C4D: mov edx, [ecx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5C53: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5C57: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5C58: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F5C5A: mov [edx+0x80], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x80u, ctx.esi);
	// 0x2F5C60: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F5C63: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C66: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5C6C: mov [edx+0x84], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x84u, ctx.esi);
	// 0x2F5C72: mov esi, [ecx+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F5C75: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C78: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5C7E: mov [edx+0x88], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x88u, ctx.esi);
	// 0x2F5C84: mov esi, [ecx+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x2F5C87: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C8A: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5C90: mov [edx+0x8C], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8Cu, ctx.esi);
	// 0x2F5C96: mov esi, [ecx+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x2F5C99: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5C9C: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5CA2: mov [edx+0x90], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x90u, ctx.esi);
	// 0x2F5CA8: mov esi, [ecx+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x2F5CAB: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5CAE: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5CB4: mov [edx+0x94], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x94u, ctx.esi);
	// 0x2F5CBA: mov esi, [ecx+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x2F5CBD: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5CC0: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5CC6: mov [edx+0x98], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x98u, ctx.esi);
	// 0x2F5CCC: mov esi, [ecx+0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x2F5CCF: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5CD2: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5CD8: mov [edx+0x9C], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x9Cu, ctx.esi);
	// 0x2F5CDE: mov edx, [eax+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5CE1: mov ecx, [ecx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x2F5CE4: mov edx, [edx+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB4u);
	// 0x2F5CEA: mov [edx+0xA0], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xA0u, ctx.ecx);
	// 0x2F5CF0: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F5CF3: mov ecx, [ecx+0xB4]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xB4u);
	// 0x2F5CF9: or byte ptr [ecx+0x7E], 0x7F
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x7Eu, X86_MEM_READ_u8(base, ctx.ecx + 0x7Eu) | 127);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx + 0x7Eu), 8);
	// 0x2F5CFD: test byte ptr [esp+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x10u) & 1, 8);
	// 0x2F5D02: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5D03: jnz 0x002F5D0B
	if (!ctx.flags.zf) goto loc_2F5D0B;
	// 0x2F5D05: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D06: call 0x002F4864
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F5D0B:
	// 0x2F5D0B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F5D0D: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F5D10(X86Context& ctx, uint8_t* base) {
	// 0x2F5D10: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F5D14: and dword ptr [ecx+0xCC], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCCu, X86_MEM_READ_u32(base, ctx.ecx + 0xCCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0xCCu), 32);
	// 0x2F5D1B: mov [ecx+0xC4], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xC4u, ctx.eax);
	// 0x2F5D21: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F5D25: mov [ecx+0xC8], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xC8u, ctx.eax);
	// 0x2F5D2B: mov [ecx+0xD0], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xD0u, ctx.eax);
	// 0x2F5D31: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F5D34(X86Context& ctx, uint8_t* base) {
	// 0x2F5D34: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D35: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D39: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F5D3B: call 0x002F595A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F595A(ctx, base);
	ctx.esp += 4;
	// 0x2F5D40: mov dword ptr [esi], 0x36C120
	X86_MEM_WRITE_u32(base, ctx.esi, 3588384);
	// 0x2F5D46: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F5D48: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5D49: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F5D4C(X86Context& ctx, uint8_t* base) {
	// 0x2F5D4C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D4D: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F5D4F: call 0x002F494A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F494A(ctx, base);
	ctx.esp += 4;
	// 0x2F5D54: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F5D59: jz 0x002F5D61
	if (ctx.flags.zf) goto loc_2F5D61;
	// 0x2F5D5B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D5C: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F5D61:
	// 0x2F5D61: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F5D63: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5D64: ret 0x04
	ctx.esp += 4;
	return;
}

void CDirectSoundBuffer_SetPlayRegion(X86Context& ctx, uint8_t* base) {
	// 0x2F5D67: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D68: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F5D6A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D6B: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5D70: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5D77: movzx edi, al
	ctx.edi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5D7A: jz 0x002F5D92
	if (ctx.flags.zf) goto loc_2F5D92;
	// 0x2F5D7C: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F5D7E: jz 0x002F5D8B
	if (ctx.flags.zf) goto loc_2F5D8B;
	// 0x2F5D80: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D85: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5D8B:
	// 0x2F5D8B: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5D90: jmp 0x002F5DE2
	goto loc_2F5DE2;
loc_2F5D92:
	// 0x2F5D92: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F5D95: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F5D97: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F5D9A: mov ecx, [edx+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x1Cu);
	// 0x2F5D9D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5D9E: jz 0x002F5DB4
	if (ctx.flags.zf) goto loc_2F5DB4;
	// 0x2F5DA0: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F5DA3: add esi, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.eax, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F5DA5: cmp esi, [ecx+0xC0]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0xC0u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5DAB: jbe 0x002F5DBD
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F5DBD;
	// 0x2F5DAD: mov esi, 0x88780032
	ctx.esi = -2005401550;
	// 0x2F5DB2: jmp 0x002F5DD0
	goto loc_2F5DD0;
loc_2F5DB4:
	// 0x2F5DB4: mov eax, [ecx+0xC0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xC0u);
	// 0x2F5DBA: sub eax, [ebp+0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2F5DBD:
	// 0x2F5DBD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5DBE: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5DC1: call 0x002F5D10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F5D10(ctx, base);
	ctx.esp += 4;
	// 0x2F5DC6: mov ecx, [edx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x20u);
	// 0x2F5DC9: call 0x002FC58C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC58C(ctx, base);
	ctx.esp += 4;
	// 0x2F5DCE: mov esi, eax
	ctx.esi = ctx.eax;
loc_2F5DD0:
	// 0x2F5DD0: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F5DD2: jz 0x002F5DDF
	if (ctx.flags.zf) goto loc_2F5DDF;
	// 0x2F5DD4: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5DD9: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5DDF:
	// 0x2F5DDF: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F5DE1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5DE2:
	// 0x2F5DE2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5DE3: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5DE4: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSoundBuffer_SetFrequency(X86Context& ctx, uint8_t* base) {
	// 0x2F5E02: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E03: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5E08: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5E0F: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5E12: jz 0x002F5E2A
	if (ctx.flags.zf) goto loc_2F5E2A;
	// 0x2F5E14: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5E16: jz 0x002F5E23
	if (ctx.flags.zf) goto loc_2F5E23;
	// 0x2F5E18: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E1D: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5E23:
	// 0x2F5E23: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5E28: jmp 0x002F5E4C
	goto loc_2F5E4C;
loc_2F5E2A:
	// 0x2F5E2A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E2B: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E2F: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E33: call 0x002F5A36
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetFrequency(ctx, base);
	ctx.esp += 4;
	// 0x2F5E38: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5E3A: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F5E3C: jz 0x002F5E49
	if (ctx.flags.zf) goto loc_2F5E49;
	// 0x2F5E3E: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E43: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5E49:
	// 0x2F5E49: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F5E4B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5E4C:
	// 0x2F5E4C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5E4D: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundBuffer_SetOutputBuffer(X86Context& ctx, uint8_t* base) {
	// 0x2F5E50: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E51: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5E56: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5E5D: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5E60: jz 0x002F5E78
	if (ctx.flags.zf) goto loc_2F5E78;
	// 0x2F5E62: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5E64: jz 0x002F5E71
	if (ctx.flags.zf) goto loc_2F5E71;
	// 0x2F5E66: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E6B: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5E71:
	// 0x2F5E71: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5E76: jmp 0x002F5E9A
	goto loc_2F5E9A;
loc_2F5E78:
	// 0x2F5E78: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E79: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E7D: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E81: call 0x002F5A5A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetOutputBuffer(ctx, base);
	ctx.esp += 4;
	// 0x2F5E86: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5E88: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F5E8A: jz 0x002F5E97
	if (ctx.flags.zf) goto loc_2F5E97;
	// 0x2F5E8C: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E91: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5E97:
	// 0x2F5E97: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F5E99: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5E9A:
	// 0x2F5E9A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5E9B: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundBuffer_SetMixBins(X86Context& ctx, uint8_t* base) {
	// 0x2F5E9E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5E9F: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5EA4: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5EAB: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5EAE: jz 0x002F5EC6
	if (ctx.flags.zf) goto loc_2F5EC6;
	// 0x2F5EB0: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5EB2: jz 0x002F5EBF
	if (ctx.flags.zf) goto loc_2F5EBF;
	// 0x2F5EB4: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5EB9: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5EBF:
	// 0x2F5EBF: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5EC4: jmp 0x002F5EE8
	goto loc_2F5EE8;
loc_2F5EC6:
	// 0x2F5EC6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5EC7: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5ECB: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5ECF: call 0x002F5AAE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetMixBins(ctx, base);
	ctx.esp += 4;
	// 0x2F5ED4: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5ED6: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F5ED8: jz 0x002F5EE5
	if (ctx.flags.zf) goto loc_2F5EE5;
	// 0x2F5EDA: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5EDF: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5EE5:
	// 0x2F5EE5: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F5EE7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5EE8:
	// 0x2F5EE8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5EE9: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundBuffer_SetAllParameters(X86Context& ctx, uint8_t* base) {
	// 0x2F5EEC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5EED: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5EF2: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5EF9: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5EFC: jz 0x002F5F14
	if (ctx.flags.zf) goto loc_2F5F14;
	// 0x2F5EFE: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5F00: jz 0x002F5F0D
	if (ctx.flags.zf) goto loc_2F5F0D;
	// 0x2F5F02: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F07: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5F0D:
	// 0x2F5F0D: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5F12: jmp 0x002F5F3A
	goto loc_2F5F3A;
loc_2F5F14:
	// 0x2F5F14: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F15: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F19: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F1D: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F21: call 0x002F5ACB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetAllParameters(ctx, base);
	ctx.esp += 4;
	// 0x2F5F26: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5F28: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F5F2A: jz 0x002F5F37
	if (ctx.flags.zf) goto loc_2F5F37;
	// 0x2F5F2C: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F31: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5F37:
	// 0x2F5F37: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F5F39: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5F3A:
	// 0x2F5F3A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5F3B: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSoundBuffer_SetRolloffCurve(X86Context& ctx, uint8_t* base) {
	// 0x2F5F3E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F3F: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5F44: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5F4B: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5F4E: jz 0x002F5F66
	if (ctx.flags.zf) goto loc_2F5F66;
	// 0x2F5F50: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5F52: jz 0x002F5F5F
	if (ctx.flags.zf) goto loc_2F5F5F;
	// 0x2F5F54: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F59: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5F5F:
	// 0x2F5F5F: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5F64: jmp 0x002F5F90
	goto loc_2F5F90;
loc_2F5F66:
	// 0x2F5F66: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F67: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F6B: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F6F: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F73: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F77: call 0x002F5C03
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetRolloffCurve(ctx, base);
	ctx.esp += 4;
	// 0x2F5F7C: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5F7E: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F5F80: jz 0x002F5F8D
	if (ctx.flags.zf) goto loc_2F5F8D;
	// 0x2F5F82: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F87: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5F8D:
	// 0x2F5F8D: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F5F8F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5F90:
	// 0x2F5F90: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5F91: ret 0x10
	ctx.esp += 16;
	return;
}

void CDirectSoundBuffer_SetI3DL2Source(X86Context& ctx, uint8_t* base) {
	// 0x2F5F94: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5F95: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5F9A: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5FA1: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5FA4: jz 0x002F5FBC
	if (ctx.flags.zf) goto loc_2F5FBC;
	// 0x2F5FA6: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5FA8: jz 0x002F5FB5
	if (ctx.flags.zf) goto loc_2F5FB5;
	// 0x2F5FAA: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FAF: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5FB5:
	// 0x2F5FB5: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F5FBA: jmp 0x002F5FE2
	goto loc_2F5FE2;
loc_2F5FBC:
	// 0x2F5FBC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FBD: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FC1: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FC5: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FC9: call 0x002F5C46
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetI3DL2Source(ctx, base);
	ctx.esp += 4;
	// 0x2F5FCE: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5FD0: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F5FD2: jz 0x002F5FDF
	if (ctx.flags.zf) goto loc_2F5FDF;
	// 0x2F5FD4: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FD9: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F5FDF:
	// 0x2F5FDF: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F5FE1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F5FE2:
	// 0x2F5FE2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F5FE3: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSoundStream_SetMixBins(X86Context& ctx, uint8_t* base) {
	// 0x2F5FE6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F5FE7: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F5FEC: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F5FF3: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F5FF6: jz 0x002F600E
	if (ctx.flags.zf) goto loc_2F600E;
	// 0x2F5FF8: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F5FFA: jz 0x002F6007
	if (ctx.flags.zf) goto loc_2F6007;
	// 0x2F5FFC: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6001: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6007:
	// 0x2F6007: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F600C: jmp 0x002F6034
	goto loc_2F6034;
loc_2F600E:
	// 0x2F600E: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F6012: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6013: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6017: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F601A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F601B: call 0x002F5AAE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetMixBins(ctx, base);
	ctx.esp += 4;
	// 0x2F6020: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6022: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F6024: jz 0x002F6031
	if (ctx.flags.zf) goto loc_2F6031;
	// 0x2F6026: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F602B: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6031:
	// 0x2F6031: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F6033: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F6034:
	// 0x2F6034: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6035: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_SetFrequency(X86Context& ctx, uint8_t* base) {
	// 0x2F6038: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F603C: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6040: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6042: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6045: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F6047: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6049: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F604B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F604C: call 0x002F5E02
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetFrequency(ctx, base);
	ctx.esp += 4;
	// 0x2F6051: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_SetOutputBuffer(X86Context& ctx, uint8_t* base) {
	// 0x2F6054: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F6058: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F605C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F605E: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6061: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F6063: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6065: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6067: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6068: call 0x002F5E50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetOutputBuffer(ctx, base);
	ctx.esp += 4;
	// 0x2F606D: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_SetMixBins(X86Context& ctx, uint8_t* base) {
	// 0x2F6070: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F6074: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6078: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F607A: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F607D: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F607F: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6081: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6083: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6084: call 0x002F5E9E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetMixBins(ctx, base);
	ctx.esp += 4;
	// 0x2F6089: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_SetAllParameters(X86Context& ctx, uint8_t* base) {
	// 0x2F608C: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F6090: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6094: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6096: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F609A: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F609D: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F609F: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F60A1: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F60A3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60A4: call 0x002F5EEC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetAllParameters(ctx, base);
	ctx.esp += 4;
	// 0x2F60A9: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSoundBuffer_SetRolloffCurve(X86Context& ctx, uint8_t* base) {
	// 0x2F60AC: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60B0: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F60B4: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60B8: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F60BA: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60BE: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F60C1: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F60C3: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F60C5: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F60C7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60C8: call 0x002F5F3E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetRolloffCurve(ctx, base);
	ctx.esp += 4;
	// 0x2F60CD: ret 0x10
	ctx.esp += 16;
	return;
}

void IDirectSoundBuffer_SetI3DL2Source(X86Context& ctx, uint8_t* base) {
	// 0x2F60D0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F60D4: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60D8: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F60DA: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60DE: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F60E1: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F60E3: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F60E5: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F60E7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60E8: call 0x002F5F94
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetI3DL2Source(ctx, base);
	ctx.esp += 4;
	// 0x2F60ED: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSoundBuffer_SetPlayRegion(X86Context& ctx, uint8_t* base) {
	// 0x2F60F0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F60F4: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60F8: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F60FA: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F60FE: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6101: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F6103: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6105: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6107: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6108: call 0x002F5D67
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetPlayRegion(ctx, base);
	ctx.esp += 4;
	// 0x2F610D: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSoundStream_SetMixBins(X86Context& ctx, uint8_t* base) {
	// 0x2F6110: jmp 0x002F5FE6
	CDirectSoundStream_SetMixBins(ctx, base);
	return;
}

void sub_2F6115(X86Context& ctx, uint8_t* base) {
	// 0x2F6115: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6116: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F6118: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6119: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F611A: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F611F: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6126: movzx eax, al
	ctx.eax = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6129: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F612C: jz 0x002F6147
	if (ctx.flags.zf) goto loc_2F6147;
	// 0x2F612E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6130: jz 0x002F613D
	if (ctx.flags.zf) goto loc_2F613D;
	// 0x2F6132: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6137: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F613D:
	// 0x2F613D: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6142: jmp 0x002F61DA
	goto loc_2F61DA;
loc_2F6147:
	// 0x2F6147: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6148: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6149: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F614C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F614D: call 0x002F400A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DSound_CRefCount_Release(ctx, base);
	ctx.esp += 4;
	// 0x2F6152: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6154: cmp esi, 0x05
	{ uint32_t _d = ctx.esi; uint32_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6157: jnz 0x002F61C5
	if (!ctx.flags.zf) goto loc_2F61C5;
	// 0x2F6159: lea esi, [edi+0x18]
	ctx.esi = ctx.edi + 0x18u;
	// 0x2F615C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F615D: mov ebx, esi
	ctx.ebx = ctx.esi;
	// 0x2F615F: mov dword ptr [ebp+0x08], 0x04
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 4);
loc_2F6166:
	// 0x2F6166: push [ebx]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebx)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6168: call 0x002F5698
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundBuffer_Stop(ctx, base);
	ctx.esp += 4;
	// 0x2F616D: add ebx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)4, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F6170: dec [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x2F6173: jnz 0x002F6166
	if (!ctx.flags.zf) goto loc_2F6166;
	// 0x2F6175: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6177:
	// 0x2F6177: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6178: call 0x002F45C3
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_DoWork(ctx, base);
	ctx.esp += 4;
	// 0x2F617D: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F617F: lea ecx, [ebp-0x04]
	ctx.ecx = ctx.ebp - 0x4u;
	// 0x2F6182: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6183: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6184: call 0x002F56F4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundBuffer_GetStatus(ctx, base);
	ctx.esp += 4;
	// 0x2F6189: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F618B: jl 0x002F6193
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6193;
	// 0x2F618D: test byte ptr [ebp-0x04], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp - 0x4u) & 1, 8);
	// 0x2F6191: jnz 0x002F6177
	if (!ctx.flags.zf) goto loc_2F6177;
loc_2F6193:
	// 0x2F6193: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F6195: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6197: jz 0x002F61A2
	if (ctx.flags.zf) goto loc_2F61A2;
	// 0x2F6199: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F619A: call 0x002F4217
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundBuffer_Release(ctx, base);
	ctx.esp += 4;
	// 0x2F619F: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
loc_2F61A2:
	// 0x2F61A2: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F61A3: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F61A6: cmp ebx, 0x04
	{ uint32_t _d = ctx.ebx; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F61A9: jb 0x002F6177
	if (ctx.flags.cf) goto loc_2F6177;
	// 0x2F61AB: mov eax, [edi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x28u);
	// 0x2F61AE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F61B0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F61B1: jz 0x002F61BD
	if (ctx.flags.zf) goto loc_2F61BD;
	// 0x2F61B3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F61B4: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F61B9: and dword ptr [edi+0x28], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi + 0x28u, X86_MEM_READ_u32(base, ctx.edi + 0x28u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi + 0x28u), 32);
loc_2F61BD:
	// 0x2F61BD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F61BE: call 0x002F400A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DSound_CRefCount_Release(ctx, base);
	ctx.esp += 4;
	// 0x2F61C3: mov esi, eax
	ctx.esi = ctx.eax;
loc_2F61C5:
	// 0x2F61C5: cmp dword ptr [ebp-0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F61C9: jz 0x002F61D6
	if (ctx.flags.zf) goto loc_2F61D6;
	// 0x2F61CB: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F61D0: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F61D6:
	// 0x2F61D6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F61D7: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F61D9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F61DA:
	// 0x2F61DA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F61DB: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F61DE(X86Context& ctx, uint8_t* base) {
	// 0x2F61DE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F61DF: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F61E1: cmp dword ptr [esi+0xB0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0xB0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F61E8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F61E9: mov dword ptr [esi], 0x36C100
	X86_MEM_WRITE_u32(base, ctx.esi, 3588352);
	// 0x2F61EF: jz 0x002F61F8
	if (ctx.flags.zf) goto loc_2F61F8;
	// 0x2F61F1: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F61F3: call 0x002F5887
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F5887(ctx, base);
	ctx.esp += 4;
loc_2F61F8:
	// 0x2F61F8: lea edi, [esi+0xB4]
	ctx.edi = ctx.esi + 0xB4u;
	// 0x2F61FE: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F6200: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6202: jz 0x002F620D
	if (ctx.flags.zf) goto loc_2F620D;
	// 0x2F6204: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6205: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F620A: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
loc_2F620D:
	// 0x2F620D: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x2F6213: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F6215: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6217: jz 0x002F6222
	if (ctx.flags.zf) goto loc_2F6222;
	// 0x2F6219: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F621A: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F621F: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
loc_2F6222:
	// 0x2F6222: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6223: mov dword ptr [esi], 0x36C17C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588476);
	// 0x2F6229: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F622A: ret
	return;
}

void sub_2F622B(X86Context& ctx, uint8_t* base) {
	// 0x2F622B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F622C: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F622E: sub esp, 0x48
	{ uint32_t _d = ctx.esp; uint32_t _s = 72;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F6231: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6232: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6233: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6234: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6237: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F6239: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x2F623C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F623D: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F623F: call 0x002F76CB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F76CB(ctx, base);
	ctx.esp += 4;
	// 0x2F6244: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F6246: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6248: jz 0x002F629D
	if (ctx.flags.zf) goto loc_2F629D;
	// 0x2F624A: test dword ptr [esi+0x08], 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x8u) & 2097168, 32);
	// 0x2F6251: jnz 0x002F629D
	if (!ctx.flags.zf) goto loc_2F629D;
	// 0x2F6253: cmp [ebp+0x0C], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6256: jz 0x002F629D
	if (ctx.flags.zf) goto loc_2F629D;
	// 0x2F6258: lea eax, [ebp-0x48]
	ctx.eax = ctx.ebp - 0x48u;
	// 0x2F625B: mov [ebp-0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ebx);
	// 0x2F625E: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
loc_2F6261:
	// 0x2F6261: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F6264: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6267: jnb 0x002F628F
	if (!ctx.flags.cf) goto loc_2F628F;
	// 0x2F6269: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F626B: lea edx, [ebp+eax*8-0x48]
	ctx.edx = ctx.ebp + ctx.eax * 8 - 0x48u;
	// 0x2F626F: call 0x002F4074
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F4074(ctx, base);
	ctx.esp += 4;
	// 0x2F6274: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x2F6276: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F6279: mov [ebp+eax*8-0x44], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.eax * 8 - 0x44u, ctx.ebx);
	// 0x2F627D: mov ecx, [edx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2F627F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F6281: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6282: shl eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F6284: not eax
	ctx.eax = ~ctx.eax;
	// 0x2F6286: and edi, eax
	ctx.edi = ctx.edi & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2F6288: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2F628B: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F628D: jnz 0x002F6261
	if (!ctx.flags.zf) goto loc_2F6261;
loc_2F628F:
	// 0x2F628F: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2F6292: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6293: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F6295: call 0x002F57BC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F57BC(ctx, base);
	ctx.esp += 4;
	// 0x2F629A: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F629C: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_2F629D:
	// 0x2F629D: push [esi+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62A0: call 0x002F424C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XAudioCalculatePitch(ctx, base);
	ctx.esp += 4;
	// 0x2F62A5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F62A6: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x2F62A9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F62AA: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F62AC: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F62AD: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F62AE: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundVoice_SetFormat(X86Context& ctx, uint8_t* base) {
	// 0x2F62B1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62B2: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F62B6: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F62B9: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62BB: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62BF: call 0x002F622B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F622B(ctx, base);
	ctx.esp += 4;
	// 0x2F62C4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F62C6: jnz 0x002F62D1
	if (!ctx.flags.zf) goto loc_2F62D1;
	// 0x2F62C8: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F62CB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62CC: call 0x002F57BC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F57BC(ctx, base);
	ctx.esp += 4;
loc_2F62D1:
	// 0x2F62D1: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F62D4: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F62D6: call [eax+0x14]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F62D9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F62DB: jl 0x002F62F1
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F62F1;
	// 0x2F62DD: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F62E0: call 0x002FB3E1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetMixBins(ctx, base);
	ctx.esp += 4;
	// 0x2F62E5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F62E7: jl 0x002F62F1
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F62F1;
	// 0x2F62E9: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F62EC: call 0x002FB53A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetPitch(ctx, base);
	ctx.esp += 4;
loc_2F62F1:
	// 0x2F62F1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F62F2: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundBufferSettings_SetBufferData(X86Context& ctx, uint8_t* base) {
	// 0x2F62F5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62F6: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F62F8: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62F9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62FA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62FB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F62FC: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F62FE: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F6300: mov edi, 0x80000000
	ctx.edi = -2147483648;
	// 0x2F6305: test [esi+0x08], edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x8u) & ctx.edi, 32);
	// 0x2F6308: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x2F630B: jnz 0x002F631D
	if (!ctx.flags.zf) goto loc_2F631D;
	// 0x2F630D: mov eax, [esi+0xBC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xBCu);
	// 0x2F6313: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6315: jz 0x002F6323
	if (ctx.flags.zf) goto loc_2F6323;
	// 0x2F6317: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6318: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F631D:
	// 0x2F631D: mov [esi+0xBC], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xBCu, ctx.ebx);
loc_2F6323:
	// 0x2F6323: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F6326: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6328: mov [esi+0xC0], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, ctx.eax);
	// 0x2F632E: jz 0x002F6369
	if (ctx.flags.zf) goto loc_2F6369;
	// 0x2F6330: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F6333: cmp ecx, ebx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6335: jz 0x002F6342
	if (ctx.flags.zf) goto loc_2F6342;
	// 0x2F6337: or [esi+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
	// 0x2F633A: mov [esi+0xBC], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xBCu, ctx.ecx);
	// 0x2F6340: jmp 0x002F6369
	goto loc_2F6369;
loc_2F6342:
	// 0x2F6342: and byte ptr [esi+0x0B], 0x7F
	X86_MEM_WRITE_u8(base, ctx.esi + 0xBu, X86_MEM_READ_u8(base, ctx.esi + 0xBu) & 127);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xBu), 8);
	// 0x2F6346: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6347: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6348: push 0x61645344
	{ auto _pv = (uint32_t)(1633964868); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F634D: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F6352: mov [esi+0xBC], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xBCu, ctx.eax);
	// 0x2F6358: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F635A: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F635C: and eax, 0x7FF8FFF2
	ctx.eax = ctx.eax & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F6361: add eax, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-2147024882, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6366: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
loc_2F6369:
	// 0x2F6369: push [esi+0xC0]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0xC0u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F636F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F6371: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6372: call 0x002F5D10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F5D10(ctx, base);
	ctx.esp += 4;
	// 0x2F6377: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F637A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F637B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F637C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F637D: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F637E: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundBuffer_SetBufferData(X86Context& ctx, uint8_t* base) {
	// 0x2F6381: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6382: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F6384: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6385: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6386: mov ebx, [ebp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F6389: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F638A: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F638C: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F638E: jnz 0x002F6398
	if (!ctx.flags.zf) goto loc_2F6398;
	// 0x2F6390: cmp [ebp+0x10], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6393: mov [ebp+0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.edi);
	// 0x2F6396: jz 0x002F639F
	if (ctx.flags.zf) goto loc_2F639F;
loc_2F6398:
	// 0x2F6398: mov dword ptr [ebp+0x0C], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, 1);
loc_2F639F:
	// 0x2F639F: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F63A4: cmp [0x003004A0], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F63AA: movzx eax, al
	ctx.eax = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F63AD: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F63B0: jz 0x002F63C8
	if (ctx.flags.zf) goto loc_2F63C8;
	// 0x2F63B2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F63B4: jz 0x002F63C1
	if (ctx.flags.zf) goto loc_2F63C1;
	// 0x2F63B6: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F63BB: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F63C1:
	// 0x2F63C1: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F63C6: jmp 0x002F6429
	goto loc_2F6429;
loc_2F63C8:
	// 0x2F63C8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F63C9: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F63CC: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F63CF: cmp ebx, [eax+0xBC]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0xBCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F63D5: jnz 0x002F63E2
	if (!ctx.flags.zf) goto loc_2F63E2;
	// 0x2F63D7: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F63DA: cmp ecx, [eax+0xC0]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0xC0u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F63E0: jz 0x002F6415
	if (ctx.flags.zf) goto loc_2F6415;
loc_2F63E2:
	// 0x2F63E2: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F63E5: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2F63E8: call 0x002FC8EF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC8EF(ctx, base);
	ctx.esp += 4;
	// 0x2F63ED: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F63EF: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F63F1: jl 0x002F6415
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6415;
	// 0x2F63F3: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F63F6: mov ecx, [esi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F63F9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F63FA: call 0x002F62F5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBufferSettings_SetBufferData(ctx, base);
	ctx.esp += 4;
	// 0x2F63FF: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F6401: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F6403: jl 0x002F6415
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6415;
	// 0x2F6405: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6409: jz 0x002F6415
	if (ctx.flags.zf) goto loc_2F6415;
	// 0x2F640B: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2F640E: call 0x002FC79F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxBuffer_SetBufferData(ctx, base);
	ctx.esp += 4;
	// 0x2F6413: mov edi, eax
	ctx.edi = ctx.eax;
loc_2F6415:
	// 0x2F6415: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6419: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F641A: jz 0x002F6427
	if (ctx.flags.zf) goto loc_2F6427;
	// 0x2F641C: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6421: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6427:
	// 0x2F6427: mov eax, edi
	ctx.eax = ctx.edi;
loc_2F6429:
	// 0x2F6429: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F642A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F642B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F642C: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSoundStream_Constructor(X86Context& ctx, uint8_t* base) {
	// 0x2F642F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6430: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F6432: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6433: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6437: lea edi, [esi+0x04]
	ctx.edi = ctx.esi + 0x4u;
	// 0x2F643A: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F643C: call 0x002F595A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F595A(ctx, base);
	ctx.esp += 4;
	// 0x2F6441: mov dword ptr [edi], 0x36C130
	X86_MEM_WRITE_u32(base, ctx.edi, 3588400);
	// 0x2F6447: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6448: mov dword ptr [esi], 0x36C140
	X86_MEM_WRITE_u32(base, ctx.esi, 3588416);
	// 0x2F644E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F6450: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6451: ret 0x04
	ctx.esp += 4;
	return;
}

void CDirectSound3DCalculator_Calculate3D(X86Context& ctx, uint8_t* base) {
	// 0x2F6454: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6455: lea ebp, [esp-0x70]
	ctx.ebp = ctx.esp - 0x70u;
	// 0x2F6459: sub esp, 0xD4
	{ uint32_t _d = ctx.esp; uint32_t _s = 212;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F645F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6460: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6461: lea ecx, [ebp+0x78]
	ctx.ecx = ctx.ebp + 0x78u;
	// 0x2F6464: call 0x002F3FA9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FA9(ctx, base);
	ctx.esp += 4;
	// 0x2F6469: mov esi, [ebp+0x78]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x78u);
	// 0x2F646C: mov ebx, [ebp+0x7C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x7Cu);
	// 0x2F646F: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F6471: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F6473: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x2F6476: mov [ebp+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, ctx.eax);
	// 0x2F6479: mov [ebp+0x68], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x68u, ctx.ecx);
	// 0x2F647C: jz 0x002F6489
	if (ctx.flags.zf) goto loc_2F6489;
	// 0x2F647E: or eax, [ebx]
	ctx.eax = ctx.eax | X86_MEM_READ_u32(base, ctx.ebx);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F6480: or ecx, [ebx+0x04]
	ctx.ecx = ctx.ecx | X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6483: mov [ebp+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, ctx.eax);
	// 0x2F6486: mov [ebp+0x68], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x68u, ctx.ecx);
loc_2F6489:
	// 0x2F6489: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x2F648B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F648C: jnz 0x002F6493
	if (!ctx.flags.zf) goto loc_2F6493;
	// 0x2F648E: test cl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 64, 8);
	// 0x2F6491: jnz 0x002F64C8
	if (!ctx.flags.zf) goto loc_2F64C8;
loc_2F6493:
	// 0x2F6493: lea eax, [ebp-0x20]
	ctx.eax = ctx.ebp - 0x20u;
	// 0x2F6496: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6497: lea eax, [esi+0x2C]
	ctx.eax = ctx.esi + 0x2Cu;
	// 0x2F649A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F649B: lea eax, [esi+0x20]
	ctx.eax = ctx.esi + 0x20u;
	// 0x2F649E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F649F: call 0x002F77CB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F77CB(ctx, base);
	ctx.esp += 4;
	// 0x2F64A4: lea eax, [esi+0x44]
	ctx.eax = ctx.esi + 0x44u;
	// 0x2F64A7: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F64A9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F64AA: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F64AC: lea esi, [ebp-0x20]
	ctx.esi = ctx.ebp - 0x20u;
	// 0x2F64AF: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F64B1: repe cmpsd
	while (ctx.ecx) {
		uint32_t _a = X86_MEM_READ_u32(base, ctx.esi);
		uint32_t _b = X86_MEM_READ_u32(base, ctx.edi);
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
		{ uint64_t _res = (uint64_t)_a - (uint64_t)_b;
		  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_a, (int32_t)_b, 32); }
		if (!ctx.flags.zf) break;
	}
	// 0x2F64B3: jz 0x002F64C1
	if (ctx.flags.zf) goto loc_2F64C1;
	// 0x2F64B5: or dword ptr [ebp+0x6C], 0x40
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) | 64);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu), 32);
	// 0x2F64B9: lea esi, [ebp-0x20]
	ctx.esi = ctx.ebp - 0x20u;
	// 0x2F64BC: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F64BE: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x2F64BF: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x2F64C0: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
loc_2F64C1:
	// 0x2F64C1: or dword ptr [ebp+0x68], 0x40
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x68u, X86_MEM_READ_u32(base, ctx.ebp + 0x68u) | 64);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x68u), 32);
	// 0x2F64C5: mov esi, [ebp+0x78]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x78u);
loc_2F64C8:
	// 0x2F64C8: mov eax, [ebp+0x6C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu);
	// 0x2F64CB: and eax, 0x400000
	ctx.eax = ctx.eax & 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F64D0: jz 0x002F64E3
	if (ctx.flags.zf) goto loc_2F64E3;
	// 0x2F64D2: cmp dword ptr [ebx+0x40], 0x02
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x40u); uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F64D6: jz 0x002F64E0
	if (ctx.flags.zf) goto loc_2F64E0;
	// 0x2F64D8: or word ptr [ebp+0x6E], 0x7FF
	X86_MEM_WRITE_u16(base, ctx.ebp + 0x6Eu, X86_MEM_READ_u16(base, ctx.ebp + 0x6Eu) | 2047);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ebp + 0x6Eu), 16);
	// 0x2F64DE: jmp 0x002F64E3
	goto loc_2F64E3;
loc_2F64E0:
	// 0x2F64E0: mov [ebp+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, ctx.eax);
loc_2F64E3:
	// 0x2F64E3: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F64E5: jz 0x002F6656
	if (ctx.flags.zf) goto loc_2F6656;
	// 0x2F64EB: mov ecx, [ebx+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x40u);
	// 0x2F64EE: cmp ecx, 0x02
	{ uint32_t _d = ctx.ecx; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F64F1: jz 0x002F6656
	if (ctx.flags.zf) goto loc_2F6656;
	// 0x2F64F7: test dword ptr [ebp+0x6C], 0x410001
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) & 4259841, 32);
	// 0x2F64FE: jnz 0x002F650E
	if (!ctx.flags.zf) goto loc_2F650E;
	// 0x2F6500: mov edx, [ebp+0x68]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x68u);
	// 0x2F6503: mov eax, 0x18000000
	ctx.eax = 402653184;
	// 0x2F6508: and edx, eax
	ctx.edx = ctx.edx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2F650A: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F650C: jz 0x002F6562
	if (ctx.flags.zf) goto loc_2F6562;
loc_2F650E:
	// 0x2F650E: lea eax, [ebp+0x54]
	ctx.eax = ctx.ebp + 0x54u;
	// 0x2F6511: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6512: lea eax, [ebp+0x48]
	ctx.eax = ctx.ebp + 0x48u;
	// 0x2F6515: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6516: lea eax, [ebx+0x08]
	ctx.eax = ctx.ebx + 0x8u;
	// 0x2F6519: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F651A: add esi, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)8, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F651D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F651E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F651F: call [0x00300B4C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x300B4Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F6525: lea eax, [ebx+0x5C]
	ctx.eax = ctx.ebx + 0x5Cu;
	// 0x2F6528: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F652A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F652B: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F652D: lea esi, [ebp+0x48]
	ctx.esi = ctx.ebp + 0x48u;
	// 0x2F6530: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F6532: repe cmpsd
	while (ctx.ecx) {
		uint32_t _a = X86_MEM_READ_u32(base, ctx.esi);
		uint32_t _b = X86_MEM_READ_u32(base, ctx.edi);
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
		{ uint64_t _res = (uint64_t)_a - (uint64_t)_b;
		  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_a, (int32_t)_b, 32); }
		if (!ctx.flags.zf) break;
	}
	// 0x2F6534: jz 0x002F6542
	if (ctx.flags.zf) goto loc_2F6542;
	// 0x2F6536: or byte ptr [ebp+0x6F], 0x08
	X86_MEM_WRITE_u8(base, ctx.ebp + 0x6Fu, X86_MEM_READ_u8(base, ctx.ebp + 0x6Fu) | 8);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp + 0x6Fu), 8);
	// 0x2F653A: lea esi, [ebp+0x48]
	ctx.esi = ctx.ebp + 0x48u;
	// 0x2F653D: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F653F: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x2F6540: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x2F6541: movsd
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
	ctx.esi += ctx.flags.df ? -4 : 4;
	ctx.edi += ctx.flags.df ? -4 : 4;
loc_2F6542:
	// 0x2F6542: fld [ebx+0x68]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x68u));
	// 0x2F6545: fld [ebp+0x54]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x54u));
	// 0x2F6548: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F654A: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F654C: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F654F: jnp 0x002F655B
	if (!ctx.flags.pf) goto loc_2F655B;
	// 0x2F6551: mov eax, [ebp+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x54u);
	// 0x2F6554: or byte ptr [ebp+0x6F], 0x10
	X86_MEM_WRITE_u8(base, ctx.ebp + 0x6Fu, X86_MEM_READ_u8(base, ctx.ebp + 0x6Fu) | 16);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp + 0x6Fu), 8);
	// 0x2F6558: mov [ebx+0x68], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x68u, ctx.eax);
loc_2F655B:
	// 0x2F655B: or byte ptr [ebp+0x6B], 0x18
	X86_MEM_WRITE_u8(base, ctx.ebp + 0x6Bu, X86_MEM_READ_u8(base, ctx.ebp + 0x6Bu) | 24);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebp + 0x6Bu), 8);
	// 0x2F655F: mov esi, [ebp+0x78]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x78u);
loc_2F6562:
	// 0x2F6562: test dword ptr [ebp+0x6C], 0x18400044
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) & 406847556, 32);
	// 0x2F6569: mov edi, 0x20000000
	ctx.edi = 536870912;
	// 0x2F656E: jnz 0x002F6575
	if (!ctx.flags.zf) goto loc_2F6575;
	// 0x2F6570: test [ebp+0x68], edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebp + 0x68u) & ctx.edi, 32);
	// 0x2F6573: jnz 0x002F65CC
	if (!ctx.flags.zf) goto loc_2F65CC;
loc_2F6575:
	// 0x2F6575: fld [ebx+0x68]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x68u));
	// 0x2F6578: lea eax, [ebp+0x64]
	ctx.eax = ctx.ebp + 0x64u;
	// 0x2F657B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F657C: lea eax, [ebp+0x60]
	ctx.eax = ctx.ebp + 0x60u;
	// 0x2F657F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6580: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6581: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F6584: lea eax, [ebx+0x5C]
	ctx.eax = ctx.ebx + 0x5Cu;
	// 0x2F6587: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6588: lea eax, [esi+0x44]
	ctx.eax = ctx.esi + 0x44u;
	// 0x2F658B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F658C: lea eax, [esi+0x2C]
	ctx.eax = ctx.esi + 0x2Cu;
	// 0x2F658F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6590: lea eax, [esi+0x20]
	ctx.eax = ctx.esi + 0x20u;
	// 0x2F6593: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6594: push [ebx+0x40]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0x40u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6597: call 0x002F4078
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F4078(ctx, base);
	ctx.esp += 4;
	// 0x2F659C: fld [ebx+0x74]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x74u));
	// 0x2F659F: fld [ebp+0x60]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x60u));
	// 0x2F65A2: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F65A4: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F65A6: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F65A9: jp 0x002F65BA
	if (ctx.flags.pf) goto loc_2F65BA;
	// 0x2F65AB: fld [ebx+0x78]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x78u));
	// 0x2F65AE: fld [ebp+0x64]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x64u));
	// 0x2F65B1: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F65B3: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F65B5: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F65B8: jnp 0x002F65C9
	if (!ctx.flags.pf) goto loc_2F65C9;
loc_2F65BA:
	// 0x2F65BA: mov eax, [ebp+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x60u);
	// 0x2F65BD: or [ebp+0x6C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu), 32);
	// 0x2F65C0: mov [ebx+0x74], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x74u, ctx.eax);
	// 0x2F65C3: mov eax, [ebp+0x64]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x64u);
	// 0x2F65C6: mov [ebx+0x78], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x78u, ctx.eax);
loc_2F65C9:
	// 0x2F65C9: or [ebp+0x68], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x68u, X86_MEM_READ_u32(base, ctx.ebp + 0x68u) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x68u), 32);
loc_2F65CC:
	// 0x2F65CC: test word ptr [ebp+0x6E], 0x808
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.ebp + 0x6Eu) & 2056, 16);
	// 0x2F65D2: mov edi, 0x40000000
	ctx.edi = 1073741824;
	// 0x2F65D7: jnz 0x002F65DE
	if (!ctx.flags.zf) goto loc_2F65DE;
	// 0x2F65D9: test [ebp+0x68], edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebp + 0x68u) & ctx.edi, 32);
	// 0x2F65DC: jnz 0x002F660B
	if (!ctx.flags.zf) goto loc_2F660B;
loc_2F65DE:
	// 0x2F65DE: lea eax, [ebp+0x5C]
	ctx.eax = ctx.ebp + 0x5Cu;
	// 0x2F65E1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F65E2: lea eax, [ebx+0x5C]
	ctx.eax = ctx.ebx + 0x5Cu;
	// 0x2F65E5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F65E6: lea eax, [ebx+0x28]
	ctx.eax = ctx.ebx + 0x28u;
	// 0x2F65E9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F65EA: call [0x00300B54]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x300B54u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F65F0: fld [ebx+0x70]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x70u));
	// 0x2F65F3: fld [ebp+0x5C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x5Cu));
	// 0x2F65F6: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F65F8: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F65FA: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F65FD: jnp 0x002F6608
	if (!ctx.flags.pf) goto loc_2F6608;
	// 0x2F65FF: mov eax, [ebp+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x5Cu);
	// 0x2F6602: or [ebp+0x6C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu), 32);
	// 0x2F6605: mov [ebx+0x70], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x70u, ctx.eax);
loc_2F6608:
	// 0x2F6608: or [ebp+0x68], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x68u, X86_MEM_READ_u32(base, ctx.ebp + 0x68u) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x68u), 32);
loc_2F660B:
	// 0x2F660B: test dword ptr [ebp+0x6C], 0x8420002
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) & 138543106, 32);
	// 0x2F6612: mov edi, 0x80000000
	ctx.edi = -2147483648;
	// 0x2F6617: jnz 0x002F6622
	if (!ctx.flags.zf) goto loc_2F6622;
	// 0x2F6619: mov eax, [ebp+0x68]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x68u);
	// 0x2F661C: and eax, edi
	ctx.eax = ctx.eax & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F661E: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6620: jz 0x002F6656
	if (ctx.flags.zf) goto loc_2F6656;
loc_2F6622:
	// 0x2F6622: lea eax, [ebp+0x58]
	ctx.eax = ctx.ebp + 0x58u;
	// 0x2F6625: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6626: lea eax, [ebx+0x5C]
	ctx.eax = ctx.ebx + 0x5Cu;
	// 0x2F6629: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F662A: lea eax, [ebx+0x14]
	ctx.eax = ctx.ebx + 0x14u;
	// 0x2F662D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F662E: lea eax, [esi+0x14]
	ctx.eax = ctx.esi + 0x14u;
	// 0x2F6631: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6632: push [ebx+0x40]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0x40u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6635: call [0x00300B58]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x300B58u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F663B: fld [ebx+0x6C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x6Cu));
	// 0x2F663E: fld [ebp+0x58]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x58u));
	// 0x2F6641: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F6643: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F6645: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F6648: jnp 0x002F6653
	if (!ctx.flags.pf) goto loc_2F6653;
	// 0x2F664A: mov eax, [ebp+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x58u);
	// 0x2F664D: or [ebp+0x6C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x6Cu, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu), 32);
	// 0x2F6650: mov [ebx+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x6Cu, ctx.eax);
loc_2F6653:
	// 0x2F6653: or [ebp+0x68], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x68u, X86_MEM_READ_u32(base, ctx.ebp + 0x68u) | ctx.edi);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x68u), 32);
loc_2F6656:
	// 0x2F6656: mov ecx, [ebp+0x6C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x6Cu);
	// 0x2F6659: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F665B: and eax, 0x7F
	ctx.eax = ctx.eax & 127;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F665E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F665F: jz 0x002F6663
	if (ctx.flags.zf) goto loc_2F6663;
	// 0x2F6661: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
loc_2F6663:
	// 0x2F6663: mov eax, [ebp+0x68]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x68u);
	// 0x2F6666: and eax, 0x7F
	ctx.eax = ctx.eax & 127;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F6669: jz 0x002F666E
	if (ctx.flags.zf) goto loc_2F666E;
	// 0x2F666B: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
loc_2F666E:
	// 0x2F666E: mov eax, 0xFFFF0000
	ctx.eax = -65536;
	// 0x2F6673: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6675: jz 0x002F6679
	if (ctx.flags.zf) goto loc_2F6679;
	// 0x2F6677: mov [ebx], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.ecx);
loc_2F6679:
	// 0x2F6679: mov ecx, [ebp+0x68]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x68u);
	// 0x2F667C: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F667E: jz 0x002F6683
	if (ctx.flags.zf) goto loc_2F6683;
	// 0x2F6680: mov [ebx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.ecx);
loc_2F6683:
	// 0x2F6683: lea ecx, [ebp+0x78]
	ctx.ecx = ctx.ebp + 0x78u;
	// 0x2F6686: call 0x002F3FCE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FCE(ctx, base);
	ctx.esp += 4;
	// 0x2F668B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F668C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F668D: add ebp, 0x70
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebp) + (uint64_t)(uint32_t)(112);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebp, (int32_t)112, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x2F6690: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6691: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundBuffer_SetFormat(X86Context& ctx, uint8_t* base) {
	// 0x2F6694: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6695: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F669A: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F66A1: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F66A4: jz 0x002F66BC
	if (ctx.flags.zf) goto loc_2F66BC;
	// 0x2F66A6: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F66A8: jz 0x002F66B5
	if (ctx.flags.zf) goto loc_2F66B5;
	// 0x2F66AA: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66AF: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F66B5:
	// 0x2F66B5: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F66BA: jmp 0x002F66DE
	goto loc_2F66DE;
loc_2F66BC:
	// 0x2F66BC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66BD: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66C1: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66C5: call 0x002F62B1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetFormat(ctx, base);
	ctx.esp += 4;
	// 0x2F66CA: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F66CC: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F66CE: jz 0x002F66DB
	if (ctx.flags.zf) goto loc_2F66DB;
	// 0x2F66D0: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66D5: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F66DB:
	// 0x2F66DB: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F66DD: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F66DE:
	// 0x2F66DE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F66DF: ret 0x08
	ctx.esp += 8;
	return;
}

void CDirectSoundStream_SetFormat(X86Context& ctx, uint8_t* base) {
	// 0x2F66E2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66E3: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F66E8: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F66EF: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F66F2: jz 0x002F670A
	if (ctx.flags.zf) goto loc_2F670A;
	// 0x2F66F4: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F66F6: jz 0x002F6703
	if (ctx.flags.zf) goto loc_2F6703;
	// 0x2F66F8: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F66FD: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6703:
	// 0x2F6703: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6708: jmp 0x002F6730
	goto loc_2F6730;
loc_2F670A:
	// 0x2F670A: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F670E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F670F: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6713: add eax, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6716: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6717: call 0x002F62B1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_SetFormat(ctx, base);
	ctx.esp += 4;
	// 0x2F671C: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F671E: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F6720: jz 0x002F672D
	if (ctx.flags.zf) goto loc_2F672D;
	// 0x2F6722: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6727: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F672D:
	// 0x2F672D: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F672F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F6730:
	// 0x2F6730: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6731: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_SetFormat(X86Context& ctx, uint8_t* base) {
	// 0x2F6734: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F6738: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F673C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F673E: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6741: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F6743: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6745: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6747: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6748: call 0x002F6694
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetFormat(ctx, base);
	ctx.esp += 4;
	// 0x2F674D: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSoundBuffer_SetBufferData(X86Context& ctx, uint8_t* base) {
	// 0x2F6750: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F6754: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6758: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F675A: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F675E: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6761: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F6763: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6765: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6767: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6768: call 0x002F6381
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBuffer_SetBufferData(ctx, base);
	ctx.esp += 4;
	// 0x2F676D: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSoundStream_SetFormat(X86Context& ctx, uint8_t* base) {
	// 0x2F6770: jmp 0x002F66E2
	CDirectSoundStream_SetFormat(ctx, base);
	return;
}

void sub_2F6775(X86Context& ctx, uint8_t* base) {
	// 0x2F6775: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6776: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6777: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6778: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6779: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2F677B: push 0x0F
	{ auto _pv = (uint32_t)(15); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F677D: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F677E: push 0x3F
	{ auto _pv = (uint32_t)(63); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6780: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6781: mov dword ptr [ebx+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, 1);
	// 0x2F6788: mov dword ptr [ebx], 0x36C17C
	X86_MEM_WRITE_u32(base, ctx.ebx, 3588476);
	// 0x2F678E: lea edi, [ebx+0x38]
	ctx.edi = ctx.ebx + 0x38u;
	// 0x2F6791: mov esi, 0x3001A4
	ctx.esi = 3146148;
	// 0x2F6796: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F6798: lea eax, [ebx+0x80]
	ctx.eax = ctx.ebx + 0x80u;
	// 0x2F679E: mov edx, 0xFFF
	ctx.edx = 4095;
	// 0x2F67A3: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F67A5: mov [ebx+0x30], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x30u, ctx.ebp);
	// 0x2F67A8: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2F67AA: lea edi, [ebx+0x84]
	ctx.edi = ctx.ebx + 0x84u;
	// 0x2F67B0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F67B1: mov esi, 0x300170
	ctx.esi = 3146096;
	// 0x2F67B6: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F67B8: mov [ebx+0x30], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x30u, ctx.ebp);
	// 0x2F67BB: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2F67BD: mov eax, [0x0030049C]
	ctx.eax = X86_MEM_READ_u32(base, 0x30049Cu);
	// 0x2F67C2: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F67C4: and ecx, 0xFFFF
	ctx.ecx = ctx.ecx & 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F67CA: cmp ecx, 0x02
	{ uint32_t _d = ctx.ecx; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F67CD: jnbe 0x002F67D6
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_2F67D6;
	// 0x2F67CF: test eax, 0xFFFC0000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & -262144, 32);
	// 0x2F67D4: jz 0x002F67DB
	if (ctx.flags.zf) goto loc_2F67DB;
loc_2F67D6:
	// 0x2F67D6: call 0x001D00F2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XGetAudioFlags(ctx, base);
	ctx.esp += 4;
loc_2F67DB:
	// 0x2F67DB: mov [0x00300498], eax
	X86_MEM_WRITE_u32(base, 0x300498u, ctx.eax);
	// 0x2F67E0: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F67E2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F67E3: lea edi, [ebx+0x10]
	ctx.edi = ctx.ebx + 0x10u;
	// 0x2F67E6: mov eax, 0x1010101
	ctx.eax = 16843009;
	// 0x2F67EB: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F67ED: stosw
	X86_MEM_WRITE_u16(base, ctx.edi, X86_REG16(ctx.eax));
	ctx.edi += ctx.flags.df ? -2 : 2;
	// 0x2F67EF: stosb
	X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
	ctx.edi += ctx.flags.df ? -1 : 1;
	// 0x2F67F0: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F67F2: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2F67F4: mov byte ptr [ebx+0x2F], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x2Fu, 0);
	// 0x2F67F8: call 0x002F4296
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F4296(ctx, base);
	ctx.esp += 4;
	// 0x2F67FD: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F67FE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F67FF: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6800: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F6802: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6803: ret
	return;
}

void CDirectSound_CommitDeferredSettings(X86Context& ctx, uint8_t* base) {
	// 0x2F6804: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6805: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F6807: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6808: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F680D: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6814: movzx eax, al
	ctx.eax = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6817: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F681A: jz 0x002F6832
	if (ctx.flags.zf) goto loc_2F6832;
	// 0x2F681C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F681E: jz 0x002F682B
	if (ctx.flags.zf) goto loc_2F682B;
	// 0x2F6820: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6825: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F682B:
	// 0x2F682B: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6830: jmp 0x002F689A
	goto loc_2F689A;
loc_2F6832:
	// 0x2F6832: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6833: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6834: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6835: lea ecx, [ebp+0x08]
	ctx.ecx = ctx.ebp + 0x8u;
	// 0x2F6838: call 0x002F3FA9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FA9(ctx, base);
	ctx.esp += 4;
	// 0x2F683D: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F6840: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F6843: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6845: add eax, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)48, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6848: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6849: call 0x002F6454
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound3DCalculator_Calculate3D(ctx, base);
	ctx.esp += 4;
	// 0x2F684E: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F6851: call 0x002F8A7B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8A7B(ctx, base);
	ctx.esp += 4;
	// 0x2F6856: lea ebx, [esi+0x10]
	ctx.ebx = ctx.esi + 0x10u;
	// 0x2F6859: mov edi, [ebx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F685B: jmp 0x002F6868
	goto loc_2F6868;
loc_2F685D:
	// 0x2F685D: lea eax, [edi-0x14]
	ctx.eax = ctx.edi - 0x14u;
	// 0x2F6860: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6861: call 0x002F4864
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundVoice_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
	// 0x2F6866: mov edi, [edi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi);
loc_2F6868:
	// 0x2F6868: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F686A: jnz 0x002F685D
	if (!ctx.flags.zf) goto loc_2F685D;
	// 0x2F686C: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F686F: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F6871: mov [eax+0x30], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, ctx.edi);
	// 0x2F6874: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F6877: lea ecx, [ebp+0x08]
	ctx.ecx = ctx.ebp + 0x8u;
	// 0x2F687A: mov [eax+0x80], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x80u, ctx.edi);
	// 0x2F6880: call 0x002F3FCE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FCE(ctx, base);
	ctx.esp += 4;
	// 0x2F6885: cmp [ebp-0x04], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6888: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6889: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F688A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F688B: jz 0x002F6898
	if (ctx.flags.zf) goto loc_2F6898;
	// 0x2F688D: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6892: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6898:
	// 0x2F6898: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F689A:
	// 0x2F689A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F689B: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F689E(X86Context& ctx, uint8_t* base) {
	// 0x2F689E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F689F: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F68A1: call 0x002F61DE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F61DE(ctx, base);
	ctx.esp += 4;
	// 0x2F68A6: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F68AB: jz 0x002F68B3
	if (ctx.flags.zf) goto loc_2F68B3;
	// 0x2F68AD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F68AE: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F68B3:
	// 0x2F68B3: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F68B5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F68B6: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F68B9(X86Context& ctx, uint8_t* base) {
	// 0x2F68B9: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F68BD: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F68BE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F68BF: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2F68C1: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F68C3: test eax, 0x182000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 1581056, 32);
	// 0x2F68C8: mov [ebx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, ctx.eax);
	// 0x2F68CB: jz 0x002F68D2
	if (ctx.flags.zf) goto loc_2F68D2;
loc_2F68CD:
	// 0x2F68CD: mov [ebx+0x20], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x20u, ctx.ebp);
	// 0x2F68D0: jmp 0x002F68E0
	goto loc_2F68E0;
loc_2F68D2:
	// 0x2F68D2: test eax, 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 2097168, 32);
	// 0x2F68D7: jnz 0x002F68CD
	if (!ctx.flags.zf) goto loc_2F68CD;
	// 0x2F68D9: mov dword ptr [ebx+0x20], 0x258
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x20u, 600);
loc_2F68E0:
	// 0x2F68E0: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x2F68E2: jz 0x002F6953
	if (ctx.flags.zf) goto loc_2F6953;
	// 0x2F68E4: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F68E6: push 0xA4
	{ auto _pv = (uint32_t)(164); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F68EB: push 0x61645344
	{ auto _pv = (uint32_t)(1633964868); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F68F0: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F68F5: mov ebp, eax
	ctx.ebp = ctx.eax;
	// 0x2F68F7: neg ebp
	{ uint32_t _d = ctx.ebp;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ebp = _res; }
	// 0x2F68F9: sbb ebp, ebp
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x2F68FB: and ebp, 0x7FF8FFF2
	ctx.ebp = ctx.ebp & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebp, 32);
	// 0x2F6901: add ebp, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebp) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebp, (int32_t)-2147024882, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x2F6907: mov [ebx+0xB4], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xB4u, ctx.eax);
	// 0x2F690D: js 0x002F69B4
	if (ctx.flags.sf) goto loc_2F69B4;
	// 0x2F6913: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6914: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6915: push 0x12
	{ auto _pv = (uint32_t)(18); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6917: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6918: lea edi, [eax+0x08]
	ctx.edi = ctx.eax + 0x8u;
	// 0x2F691B: mov esi, 0x30020C
	ctx.esi = 3146252;
	// 0x2F6920: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F6922: mov edi, [ebx+0xB4]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0xB4u);
	// 0x2F6928: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F692A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F692B: add edi, 0x80
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(128);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)128, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F6931: mov esi, 0x3001E0
	ctx.esi = 3146208;
	// 0x2F6936: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F6938: mov eax, [ebx+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0xB4u);
	// 0x2F693E: mov dword ptr [eax], 0x7FF0000
	X86_MEM_WRITE_u32(base, ctx.eax, 134152192);
	// 0x2F6944: mov eax, [ebx+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0xB4u);
	// 0x2F694A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F694B: mov dword ptr [eax+0x7C], 0x7F0000
	X86_MEM_WRITE_u32(base, ctx.eax + 0x7Cu, 8323072);
	// 0x2F6952: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F6953:
	// 0x2F6953: test dword ptr [ebx+0x08], 0x400010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ebx + 0x8u) & 4194320, 32);
	// 0x2F695A: jz 0x002F6984
	if (ctx.flags.zf) goto loc_2F6984;
	// 0x2F695C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F695E: push 0x38
	{ auto _pv = (uint32_t)(56); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6960: push 0x61645344
	{ auto _pv = (uint32_t)(1633964868); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6965: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F696A: mov [ebx+0xB8], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xB8u, ctx.eax);
	// 0x2F6970: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F6972: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6974: and eax, 0x7FF8FFF2
	ctx.eax = ctx.eax & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F6979: add eax, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-2147024882, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F697E: or byte ptr [ebx+0x0B], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebx + 0xBu, X86_MEM_READ_u8(base, ctx.ebx + 0xBu) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ebx + 0xBu), 8);
	// 0x2F6982: mov ebp, eax
	ctx.ebp = ctx.eax;
loc_2F6984:
	// 0x2F6984: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x2F6986: jl 0x002F69B4
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F69B4;
	// 0x2F6988: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F698A: cmp [esp+0x14], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x14u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F698E: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2F6990: setz al
	X86_REG8L(ctx.eax) = (ctx.flags.zf) ? 1 : 0;
	// 0x2F6993: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6994: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6998: call 0x002F622B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F622B(ctx, base);
	ctx.esp += 4;
	// 0x2F699D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F699F: jnz 0x002F69AC
	if (!ctx.flags.zf) goto loc_2F69AC;
	// 0x2F69A1: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69A5: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2F69A7: call 0x002F57BC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F57BC(ctx, base);
	ctx.esp += 4;
loc_2F69AC:
	// 0x2F69AC: mov eax, [ebx+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x20u);
	// 0x2F69AF: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F69B1: mov [ebx+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x1Cu, ctx.eax);
loc_2F69B4:
	// 0x2F69B4: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x2F69B6: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F69B7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F69B8: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F69BB(X86Context& ctx, uint8_t* base) {
	// 0x2F69BB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69BC: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69BE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F69C0: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69C2: mov dword ptr [esi], 0x36C15C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588444);
	// 0x2F69C8: call 0x002F62F5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBufferSettings_SetBufferData(ctx, base);
	ctx.esp += 4;
	// 0x2F69CD: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69CF: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69D1: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F69D3: call 0x002F4875
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F4875(ctx, base);
	ctx.esp += 4;
	// 0x2F69D8: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F69DA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F69DB: jmp 0x002F61DE
	sub_2F61DE(ctx, base);
	return;
}

void sub_2F69E0(X86Context& ctx, uint8_t* base) {
	// 0x2F69E0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69E1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F69E5: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x2F69E8: test eax, 0x182000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 1581056, 32);
	// 0x2F69ED: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69EE: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F69F0: mov ecx, 0x2FEF78
	ctx.ecx = 3141496;
	// 0x2F69F5: jnz 0x002F69FA
	if (!ctx.flags.zf) goto loc_2F69FA;
	// 0x2F69F7: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
loc_2F69FA:
	// 0x2F69FA: push [esi+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69FD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69FE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F69FF: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F6A01: call 0x002F68B9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F68B9(ctx, base);
	ctx.esp += 4;
	// 0x2F6A06: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6A08: jl 0x002F6A40
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6A40;
	// 0x2F6A0A: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x2F6A0D: test ecx, 0x180000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & 1572864, 32);
	// 0x2F6A13: jz 0x002F6A20
	if (ctx.flags.zf) goto loc_2F6A20;
	// 0x2F6A15: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F6A18: mov [edi+0xD4], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0xD4u, ctx.ecx);
	// 0x2F6A1E: jmp 0x002F6A2F
	goto loc_2F6A2F;
loc_2F6A20:
	// 0x2F6A20: test ch, 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.ecx) & 32, 8);
	// 0x2F6A23: jz 0x002F6A2F
	if (ctx.flags.zf) goto loc_2F6A2F;
	// 0x2F6A25: mov dword ptr [edi+0xD4], 0x1F
	X86_MEM_WRITE_u32(base, ctx.edi + 0xD4u, 31);
loc_2F6A2F:
	// 0x2F6A2F: mov esi, [esi+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F6A32: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6A34: jz 0x002F6A40
	if (ctx.flags.zf) goto loc_2F6A40;
	// 0x2F6A36: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A37: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A39: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F6A3B: call 0x002F62F5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundBufferSettings_SetBufferData(ctx, base);
	ctx.esp += 4;
loc_2F6A40:
	// 0x2F6A40: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6A41: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6A42: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F6A45(X86Context& ctx, uint8_t* base) {
	// 0x2F6A45: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A46: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6A4B: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6A52: movzx eax, al
	ctx.eax = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6A55: mov [esp], eax
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.eax);
	// 0x2F6A58: jz 0x002F6A73
	if (ctx.flags.zf) goto loc_2F6A73;
	// 0x2F6A5A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6A5C: jz 0x002F6A69
	if (ctx.flags.zf) goto loc_2F6A69;
	// 0x2F6A5E: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A63: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6A69:
	// 0x2F6A69: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6A6E: jmp 0x002F6B28
	goto loc_2F6B28;
loc_2F6A73:
	// 0x2F6A73: push 0xE0
	{ auto _pv = (uint32_t)(224); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A78: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F6A7D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6A7F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6A80: jz 0x002F6A93
	if (ctx.flags.zf) goto loc_2F6A93;
	// 0x2F6A82: mov dword ptr [eax+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 1);
	// 0x2F6A89: mov dword ptr [eax], 0x36C15C
	X86_MEM_WRITE_u32(base, ctx.eax, 3588444);
	// 0x2F6A8F: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6A91: jmp 0x002F6A95
	goto loc_2F6A95;
loc_2F6A93:
	// 0x2F6A93: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6A95:
	// 0x2F6A95: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A96: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A97: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6A98: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F6A9A: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F6A9C: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6A9E: mov ebp, 0x7FF8FFF2
	ctx.ebp = 2147024882;
	// 0x2F6AA3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6AA4: mov edi, [esp+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x2F6AA8: and esi, ebp
	ctx.esi = ctx.esi & ctx.ebp;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F6AAA: mov ebx, 0x8007000E
	ctx.ebx = -2147024882;
	// 0x2F6AAF: add esi, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.ebx, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6AB1: mov [edi+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x1Cu, ctx.ecx);
	// 0x2F6AB4: js 0x002F6B10
	if (ctx.flags.sf) goto loc_2F6B10;
	// 0x2F6AB6: push [esp+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6ABA: call 0x002F69E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F69E0(ctx, base);
	ctx.esp += 4;
	// 0x2F6ABF: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6AC1: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6AC3: jl 0x002F6B10
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6B10;
	// 0x2F6AC5: push 0x158
	{ auto _pv = (uint32_t)(344); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6ACA: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F6ACF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6AD1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6AD2: jz 0x002F6AE6
	if (ctx.flags.zf) goto loc_2F6AE6;
	// 0x2F6AD4: push [edi+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6AD7: mov ecx, [edi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x2F6ADA: push [ecx+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6ADD: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6ADF: call 0x002FC2DC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC2DC(ctx, base);
	ctx.esp += 4;
	// 0x2F6AE4: jmp 0x002F6AE8
	goto loc_2F6AE8;
loc_2F6AE6:
	// 0x2F6AE6: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6AE8:
	// 0x2F6AE8: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6AEA: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F6AEC: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6AEE: and esi, ebp
	ctx.esi = ctx.esi & ctx.ebp;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F6AF0: add esi, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.ebx, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6AF2: mov [edi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x20u, ctx.eax);
	// 0x2F6AF5: js 0x002F6B10
	if (ctx.flags.sf) goto loc_2F6B10;
	// 0x2F6AF7: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6AF9: call 0x002FC77B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC77B(ctx, base);
	ctx.esp += 4;
	// 0x2F6AFE: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6B00: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6B02: jl 0x002F6B10
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6B10;
	// 0x2F6B04: push [edi+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B07: push [edi+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B0A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B0B: call 0x002F599F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F599F(ctx, base);
	ctx.esp += 4;
loc_2F6B10:
	// 0x2F6B10: cmp dword ptr [esp+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6B15: jz 0x002F6B22
	if (ctx.flags.zf) goto loc_2F6B22;
	// 0x2F6B17: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B1C: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6B22:
	// 0x2F6B22: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B23: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F6B25: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B26: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B27: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F6B28:
	// 0x2F6B28: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B29: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F6B2C(X86Context& ctx, uint8_t* base) {
	// 0x2F6B2C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B2D: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F6B2F: mov dword ptr [esi], 0x36C16C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588460);
	// 0x2F6B35: call 0x002F61DE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F61DE(ctx, base);
	ctx.esp += 4;
	// 0x2F6B3A: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F6B3F: jz 0x002F6B47
	if (ctx.flags.zf) goto loc_2F6B47;
	// 0x2F6B41: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B42: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F6B47:
	// 0x2F6B47: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F6B49: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B4A: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F6B4D(X86Context& ctx, uint8_t* base) {
	// 0x2F6B4D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B4E: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F6B52: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B53: push [esi+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B56: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F6B58: push [esi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B5B: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B5D: call 0x002F68B9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F68B9(ctx, base);
	ctx.esp += 4;
	// 0x2F6B62: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6B64: jl 0x002F6B81
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6B81;
	// 0x2F6B66: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x2F6B69: mov [edi+0xBC], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0xBCu, ctx.ecx);
	// 0x2F6B6F: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F6B72: mov [edi+0xC0], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0xC0u, ctx.ecx);
	// 0x2F6B78: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x2F6B7B: mov [edi+0xC4], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0xC4u, ctx.ecx);
loc_2F6B81:
	// 0x2F6B81: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B82: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B83: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F6B86(X86Context& ctx, uint8_t* base) {
	// 0x2F6B86: push 0xC8
	{ auto _pv = (uint32_t)(200); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6B8B: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F6B90: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6B92: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6B93: jz 0x002F6BA6
	if (ctx.flags.zf) goto loc_2F6BA6;
	// 0x2F6B95: mov dword ptr [eax+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 1);
	// 0x2F6B9C: mov dword ptr [eax], 0x36C16C
	X86_MEM_WRITE_u32(base, ctx.eax, 3588460);
	// 0x2F6BA2: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6BA4: jmp 0x002F6BA8
	goto loc_2F6BA8;
loc_2F6BA6:
	// 0x2F6BA6: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6BA8:
	// 0x2F6BA8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BA9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BAA: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F6BAC: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F6BAE: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6BB0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BB1: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F6BB5: and esi, 0x7FF8FFF2
	ctx.esi = ctx.esi & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F6BBB: mov ebx, 0x8007000E
	ctx.ebx = -2147024882;
	// 0x2F6BC0: add esi, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.ebx, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6BC2: mov [edi+0x20], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x20u, ctx.ecx);
	// 0x2F6BC5: js 0x002F6C28
	if (ctx.flags.sf) goto loc_2F6C28;
	// 0x2F6BC7: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BCB: call 0x002F6B4D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F6B4D(ctx, base);
	ctx.esp += 4;
	// 0x2F6BD0: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6BD2: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6BD4: jl 0x002F6C28
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6C28;
	// 0x2F6BD6: push 0x198
	{ auto _pv = (uint32_t)(408); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BDB: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F6BE0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F6BE2: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6BE3: jz 0x002F6BF7
	if (ctx.flags.zf) goto loc_2F6BF7;
	// 0x2F6BE5: push [edi+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BE8: mov ecx, [edi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x2F6BEB: push [ecx+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6BEE: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6BF0: call 0x002F952F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F952F(ctx, base);
	ctx.esp += 4;
	// 0x2F6BF5: jmp 0x002F6BF9
	goto loc_2F6BF9;
loc_2F6BF7:
	// 0x2F6BF7: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6BF9:
	// 0x2F6BF9: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6BFB: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F6BFD: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6BFF: and esi, 0x7FF8FFF2
	ctx.esi = ctx.esi & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F6C05: add esi, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.ebx, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6C07: mov [edi+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x24u, ctx.eax);
	// 0x2F6C0A: js 0x002F6C28
	if (ctx.flags.sf) goto loc_2F6C28;
	// 0x2F6C0C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6C0E: call 0x002F906D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F906D(ctx, base);
	ctx.esp += 4;
	// 0x2F6C13: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6C15: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6C17: jl 0x002F6C28
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6C28;
	// 0x2F6C19: push [edi+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C1C: add edi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)4, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F6C1F: push [edi+0x20]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x20u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C22: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C23: call 0x002F599F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F599F(ctx, base);
	ctx.esp += 4;
loc_2F6C28:
	// 0x2F6C28: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6C29: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F6C2B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6C2C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6C2D: ret 0x08
	ctx.esp += 8;
	return;
}

void IDirectSound_CommitDeferredSettings(X86Context& ctx, uint8_t* base) {
	// 0x2F6C30: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F6C34: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6C36: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6C39: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F6C3B: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F6C3D: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F6C3F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C40: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
	// 0x2F6C45: ret 0x04
	ctx.esp += 4;
	return;
}

void CDirectSound_CreateSoundBuffer(X86Context& ctx, uint8_t* base) {
	// 0x2F6C48: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C49: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C4A: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6C4F: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F6C51: cmp [0x003004A0], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6C57: movzx ebx, al
	ctx.ebx = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6C5A: jz 0x002F6C72
	if (ctx.flags.zf) goto loc_2F6C72;
	// 0x2F6C5C: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6C5E: jz 0x002F6C6B
	if (ctx.flags.zf) goto loc_2F6C6B;
	// 0x2F6C60: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C65: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6C6B:
	// 0x2F6C6B: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6C70: jmp 0x002F6CDF
	goto loc_2F6CDF;
loc_2F6C72:
	// 0x2F6C72: push 0x24
	{ auto _pv = (uint32_t)(36); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C74: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F6C79: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6C7B: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6C7C: jz 0x002F6C8B
	if (ctx.flags.zf) goto loc_2F6C8B;
	// 0x2F6C7E: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C82: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6C84: call 0x002F5D34
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F5D34(ctx, base);
	ctx.esp += 4;
	// 0x2F6C89: mov edi, eax
	ctx.edi = ctx.eax;
loc_2F6C8B:
	// 0x2F6C8B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6C8C: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x2F6C8E: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F6C90: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6C92: and esi, 0x7FF8FFF2
	ctx.esi = ctx.esi & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F6C98: add esi, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)-2147024882, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6C9E: js 0x002F6CC3
	if (ctx.flags.sf) goto loc_2F6CC3;
	// 0x2F6CA0: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6CA4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6CA5: call 0x002F6A45
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F6A45(ctx, base);
	ctx.esp += 4;
	// 0x2F6CAA: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6CAC: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6CAE: jl 0x002F6CC3
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6CC3;
	// 0x2F6CB0: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x2F6CB4: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F6CB6: add edi, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)28, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F6CB9: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F6CBB: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F6CBD: and eax, edi
	ctx.eax = ctx.eax & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F6CBF: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F6CC1: jmp 0x002F6CCD
	goto loc_2F6CCD;
loc_2F6CC3:
	// 0x2F6CC3: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F6CC5: jz 0x002F6CCD
	if (ctx.flags.zf) goto loc_2F6CCD;
	// 0x2F6CC7: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F6CC9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6CCA: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6CCD:
	// 0x2F6CCD: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F6CCF: jz 0x002F6CDC
	if (ctx.flags.zf) goto loc_2F6CDC;
	// 0x2F6CD1: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6CD6: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6CDC:
	// 0x2F6CDC: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F6CDE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F6CDF:
	// 0x2F6CDF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6CE0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6CE1: ret 0x10
	ctx.esp += 16;
	return;
}

void CDirectSound_CreateSoundStream(X86Context& ctx, uint8_t* base) {
	// 0x2F6CE4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6CE5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6CE6: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6CEB: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F6CED: cmp [0x003004A0], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6CF3: movzx ebx, al
	ctx.ebx = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6CF6: jz 0x002F6D0E
	if (ctx.flags.zf) goto loc_2F6D0E;
	// 0x2F6CF8: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6CFA: jz 0x002F6D07
	if (ctx.flags.zf) goto loc_2F6D07;
	// 0x2F6CFC: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D01: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6D07:
	// 0x2F6D07: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6D0C: jmp 0x002F6D70
	goto loc_2F6D70;
loc_2F6D0E:
	// 0x2F6D0E: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D10: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F6D15: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6D17: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6D18: jz 0x002F6D27
	if (ctx.flags.zf) goto loc_2F6D27;
	// 0x2F6D1A: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D1E: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F6D20: call 0x002F642F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSoundStream_Constructor(ctx, base);
	ctx.esp += 4;
	// 0x2F6D25: mov edi, eax
	ctx.edi = ctx.eax;
loc_2F6D27:
	// 0x2F6D27: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D28: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x2F6D2A: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F6D2C: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6D2E: and esi, 0x7FF8FFF2
	ctx.esi = ctx.esi & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F6D34: add esi, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)-2147024882, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F6D3A: js 0x002F6D54
	if (ctx.flags.sf) goto loc_2F6D54;
	// 0x2F6D3C: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D40: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D41: call 0x002F6B86
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F6B86(ctx, base);
	ctx.esp += 4;
	// 0x2F6D46: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F6D48: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6D4A: jl 0x002F6D54
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F6D54;
	// 0x2F6D4C: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x2F6D50: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x2F6D52: jmp 0x002F6D5E
	goto loc_2F6D5E;
loc_2F6D54:
	// 0x2F6D54: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F6D56: jz 0x002F6D5E
	if (ctx.flags.zf) goto loc_2F6D5E;
	// 0x2F6D58: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F6D5A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D5B: call [eax+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6D5E:
	// 0x2F6D5E: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F6D60: jz 0x002F6D6D
	if (ctx.flags.zf) goto loc_2F6D6D;
	// 0x2F6D62: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D67: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6D6D:
	// 0x2F6D6D: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F6D6F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F6D70:
	// 0x2F6D70: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6D71: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6D72: ret 0x10
	ctx.esp += 16;
	return;
}

void CDirectSound_SetDistanceFactor(X86Context& ctx, uint8_t* base) {
	// 0x2F6D75: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D76: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6D7B: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6D82: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6D85: jz 0x002F6D9D
	if (ctx.flags.zf) goto loc_2F6D9D;
	// 0x2F6D87: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6D89: jz 0x002F6D96
	if (ctx.flags.zf) goto loc_2F6D96;
	// 0x2F6D8B: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6D90: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6D96:
	// 0x2F6D96: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6D9B: jmp 0x002F6DD0
	goto loc_2F6DD0;
loc_2F6D9D:
	// 0x2F6D9D: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F6DA1: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F6DA4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F6DA8: mov [eax+0x68], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x68u, ctx.edx);
	// 0x2F6DAB: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F6DAE: or dword ptr [eax+0x30], 0x08
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, X86_MEM_READ_u32(base, ctx.eax + 0x30u) | 8);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x30u), 32);
	// 0x2F6DB2: test byte ptr [esp+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x10u) & 1, 8);
	// 0x2F6DB7: jnz 0x002F6DBF
	if (!ctx.flags.zf) goto loc_2F6DBF;
	// 0x2F6DB9: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6DBA: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F6DBF:
	// 0x2F6DBF: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6DC1: jz 0x002F6DCE
	if (ctx.flags.zf) goto loc_2F6DCE;
	// 0x2F6DC3: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6DC8: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6DCE:
	// 0x2F6DCE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6DD0:
	// 0x2F6DD0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6DD1: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSound_SetDopplerFactor(X86Context& ctx, uint8_t* base) {
	// 0x2F6DD4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6DD5: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6DDA: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6DE1: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6DE4: jz 0x002F6DFC
	if (ctx.flags.zf) goto loc_2F6DFC;
	// 0x2F6DE6: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6DE8: jz 0x002F6DF5
	if (ctx.flags.zf) goto loc_2F6DF5;
	// 0x2F6DEA: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6DEF: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6DF5:
	// 0x2F6DF5: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6DFA: jmp 0x002F6E2F
	goto loc_2F6E2F;
loc_2F6DFC:
	// 0x2F6DFC: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F6E00: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F6E03: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F6E07: mov [eax+0x70], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, ctx.edx);
	// 0x2F6E0A: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F6E0D: or dword ptr [eax+0x30], 0x20
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, X86_MEM_READ_u32(base, ctx.eax + 0x30u) | 32);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x30u), 32);
	// 0x2F6E11: test byte ptr [esp+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x10u) & 1, 8);
	// 0x2F6E16: jnz 0x002F6E1E
	if (!ctx.flags.zf) goto loc_2F6E1E;
	// 0x2F6E18: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E19: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F6E1E:
	// 0x2F6E1E: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6E20: jz 0x002F6E2D
	if (ctx.flags.zf) goto loc_2F6E2D;
	// 0x2F6E22: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E27: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6E2D:
	// 0x2F6E2D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6E2F:
	// 0x2F6E2F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6E30: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSound_SetRolloffFactor(X86Context& ctx, uint8_t* base) {
	// 0x2F6E33: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E34: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6E39: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6E40: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6E43: jz 0x002F6E5B
	if (ctx.flags.zf) goto loc_2F6E5B;
	// 0x2F6E45: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6E47: jz 0x002F6E54
	if (ctx.flags.zf) goto loc_2F6E54;
	// 0x2F6E49: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E4E: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6E54:
	// 0x2F6E54: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6E59: jmp 0x002F6E8E
	goto loc_2F6E8E;
loc_2F6E5B:
	// 0x2F6E5B: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F6E5F: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F6E62: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F6E66: mov [eax+0x6C], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, ctx.edx);
	// 0x2F6E69: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F6E6C: or dword ptr [eax+0x30], 0x10
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, X86_MEM_READ_u32(base, ctx.eax + 0x30u) | 16);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x30u), 32);
	// 0x2F6E70: test byte ptr [esp+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x10u) & 1, 8);
	// 0x2F6E75: jnz 0x002F6E7D
	if (!ctx.flags.zf) goto loc_2F6E7D;
	// 0x2F6E77: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E78: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F6E7D:
	// 0x2F6E7D: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6E7F: jz 0x002F6E8C
	if (ctx.flags.zf) goto loc_2F6E8C;
	// 0x2F6E81: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E86: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6E8C:
	// 0x2F6E8C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6E8E:
	// 0x2F6E8E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6E8F: ret 0x0C
	ctx.esp += 12;
	return;
}

void CDirectSound_SetOrientation(X86Context& ctx, uint8_t* base) {
	// 0x2F6E92: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E93: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F6E95: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6E96: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6E9B: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6EA2: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6EA5: jz 0x002F6EBD
	if (ctx.flags.zf) goto loc_2F6EBD;
	// 0x2F6EA7: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6EA9: jz 0x002F6EB6
	if (ctx.flags.zf) goto loc_2F6EB6;
	// 0x2F6EAB: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6EB0: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6EB6:
	// 0x2F6EB6: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6EBB: jmp 0x002F6F1A
	goto loc_2F6F1A;
loc_2F6EBD:
	// 0x2F6EBD: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F6EC0: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6EC3: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F6EC6: mov [ecx+0x50], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x50u, ctx.edx);
	// 0x2F6EC9: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6ECC: mov edx, [ebp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F6ECF: mov [ecx+0x54], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x54u, ctx.edx);
	// 0x2F6ED2: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6ED5: mov edx, [ebp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F6ED8: mov [ecx+0x58], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x58u, ctx.edx);
	// 0x2F6EDB: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6EDE: mov edx, [ebp+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F6EE1: mov [ecx+0x5C], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x5Cu, ctx.edx);
	// 0x2F6EE4: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6EE7: mov edx, [ebp+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x2F6EEA: mov [ecx+0x60], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x60u, ctx.edx);
	// 0x2F6EED: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6EF0: mov edx, [ebp+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x20u);
	// 0x2F6EF3: mov [ecx+0x64], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x64u, ctx.edx);
	// 0x2F6EF6: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F6EF9: or dword ptr [ecx+0x30], 0x04
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x30u, X86_MEM_READ_u32(base, ctx.ecx + 0x30u) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0x30u), 32);
	// 0x2F6EFD: test byte ptr [ebp+0x24], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x24u) & 1, 8);
	// 0x2F6F01: jnz 0x002F6F09
	if (!ctx.flags.zf) goto loc_2F6F09;
	// 0x2F6F03: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F04: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F6F09:
	// 0x2F6F09: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6F0B: jz 0x002F6F18
	if (ctx.flags.zf) goto loc_2F6F18;
	// 0x2F6F0D: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F12: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6F18:
	// 0x2F6F18: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6F1A:
	// 0x2F6F1A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6F1B: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6F1C: ret 0x20
	ctx.esp += 32;
	return;
}

void CDirectSound_SetPosition(X86Context& ctx, uint8_t* base) {
	// 0x2F6F1F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F20: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F6F22: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F23: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6F28: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6F2F: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6F32: jz 0x002F6F4A
	if (ctx.flags.zf) goto loc_2F6F4A;
	// 0x2F6F34: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6F36: jz 0x002F6F43
	if (ctx.flags.zf) goto loc_2F6F43;
	// 0x2F6F38: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F3D: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6F43:
	// 0x2F6F43: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6F48: jmp 0x002F6F8D
	goto loc_2F6F8D;
loc_2F6F4A:
	// 0x2F6F4A: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F6F4D: lea eax, [ecx+0x08]
	ctx.eax = ctx.ecx + 0x8u;
	// 0x2F6F50: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6F52: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F53: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F6F56: mov [edx+0x38], edi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x38u, ctx.edi);
	// 0x2F6F59: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6F5B: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F6F5E: mov [edx+0x3C], edi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x3Cu, ctx.edi);
	// 0x2F6F61: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6F63: mov edi, [ebp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F6F66: mov [edx+0x40], edi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x40u, ctx.edi);
	// 0x2F6F69: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6F6B: or dword ptr [eax+0x30], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, X86_MEM_READ_u32(base, ctx.eax + 0x30u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x30u), 32);
	// 0x2F6F6F: test byte ptr [ebp+0x18], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x18u) & 1, 8);
	// 0x2F6F73: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6F74: jnz 0x002F6F7C
	if (!ctx.flags.zf) goto loc_2F6F7C;
	// 0x2F6F76: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F77: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F6F7C:
	// 0x2F6F7C: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6F7E: jz 0x002F6F8B
	if (ctx.flags.zf) goto loc_2F6F8B;
	// 0x2F6F80: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F85: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6F8B:
	// 0x2F6F8B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F6F8D:
	// 0x2F6F8D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6F8E: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6F8F: ret 0x14
	ctx.esp += 20;
	return;
}

void CDirectSound_SetVelocity(X86Context& ctx, uint8_t* base) {
	// 0x2F6F92: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F93: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F6F95: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6F96: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F6F9B: cmp dword ptr [0x003004A0], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F6FA2: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F6FA5: jz 0x002F6FBD
	if (ctx.flags.zf) goto loc_2F6FBD;
	// 0x2F6FA7: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6FA9: jz 0x002F6FB6
	if (ctx.flags.zf) goto loc_2F6FB6;
	// 0x2F6FAB: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6FB0: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6FB6:
	// 0x2F6FB6: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F6FBB: jmp 0x002F7000
	goto loc_2F7000;
loc_2F6FBD:
	// 0x2F6FBD: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F6FC0: lea eax, [ecx+0x08]
	ctx.eax = ctx.ecx + 0x8u;
	// 0x2F6FC3: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6FC5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6FC6: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F6FC9: mov [edx+0x44], edi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x44u, ctx.edi);
	// 0x2F6FCC: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6FCE: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F6FD1: mov [edx+0x48], edi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x48u, ctx.edi);
	// 0x2F6FD4: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6FD6: mov edi, [ebp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F6FD9: mov [edx+0x4C], edi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4Cu, ctx.edi);
	// 0x2F6FDC: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F6FDE: or dword ptr [eax+0x30], 0x02
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, X86_MEM_READ_u32(base, ctx.eax + 0x30u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x30u), 32);
	// 0x2F6FE2: test byte ptr [ebp+0x18], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x18u) & 1, 8);
	// 0x2F6FE6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F6FE7: jnz 0x002F6FEF
	if (!ctx.flags.zf) goto loc_2F6FEF;
	// 0x2F6FE9: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6FEA: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F6FEF:
	// 0x2F6FEF: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F6FF1: jz 0x002F6FFE
	if (ctx.flags.zf) goto loc_2F6FFE;
	// 0x2F6FF3: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F6FF8: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F6FFE:
	// 0x2F6FFE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F7000:
	// 0x2F7000: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7001: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7002: ret 0x14
	ctx.esp += 20;
	return;
}

void CDirectSound_SetI3DL2Listener(X86Context& ctx, uint8_t* base) {
	// 0x2F7005: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7006: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7007: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F7009: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F700E: cmp [0x003004A0], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x3004A0u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7014: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F7017: jz 0x002F7032
	if (ctx.flags.zf) goto loc_2F7032;
	// 0x2F7019: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F701B: jz 0x002F7028
	if (ctx.flags.zf) goto loc_2F7028;
	// 0x2F701D: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7022: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F7028:
	// 0x2F7028: mov eax, 0x80004005
	ctx.eax = -2147467259;
	// 0x2F702D: jmp 0x002F7108
	goto loc_2F7108;
loc_2F7032:
	// 0x2F7032: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F7036: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F7039: cmp dword ptr [ecx+0x08], 0xFFFFFFFF
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x8u); uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F703D: jnz 0x002F7049
	if (!ctx.flags.zf) goto loc_2F7049;
	// 0x2F703F: mov edi, 0x88780032
	ctx.edi = -2005401550;
	// 0x2F7044: jmp 0x002F70F7
	goto loc_2F70F7;
loc_2F7049:
	// 0x2F7049: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F704C: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F7050: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7051: mov ebx, [ecx]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F7053: mov [edx+0x84], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x84u, ctx.ebx);
	// 0x2F7059: mov ebx, [ecx+0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F705C: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F705F: mov [edx+0x88], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x88u, ctx.ebx);
	// 0x2F7065: mov ebx, [ecx+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F7068: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F706B: mov [edx+0x8C], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8Cu, ctx.ebx);
	// 0x2F7071: mov ebx, [ecx+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x2F7074: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F7077: mov [edx+0x90], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x90u, ctx.ebx);
	// 0x2F707D: mov ebx, [ecx+0x10]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x2F7080: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F7083: mov [edx+0x94], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x94u, ctx.ebx);
	// 0x2F7089: mov ebx, [ecx+0x14]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x2F708C: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F708F: mov [edx+0x98], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x98u, ctx.ebx);
	// 0x2F7095: mov ebx, [ecx+0x18]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x2F7098: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F709B: mov [edx+0x9C], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x9Cu, ctx.ebx);
	// 0x2F70A1: mov ebx, [ecx+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x2F70A4: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F70A7: mov [edx+0xA0], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xA0u, ctx.ebx);
	// 0x2F70AD: mov ebx, [ecx+0x20]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x2F70B0: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F70B3: mov [edx+0xA4], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xA4u, ctx.ebx);
	// 0x2F70B9: mov ebx, [ecx+0x24]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x24u);
	// 0x2F70BC: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F70BF: mov [edx+0xA8], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xA8u, ctx.ebx);
	// 0x2F70C5: mov ebx, [ecx+0x28]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x28u);
	// 0x2F70C8: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F70CB: mov [edx+0xAC], ebx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xACu, ctx.ebx);
	// 0x2F70D1: mov ecx, [ecx+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x2Cu);
	// 0x2F70D4: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F70D7: mov [edx+0xB0], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xB0u, ctx.ecx);
	// 0x2F70DD: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F70E0: or word ptr [ecx+0x80], 0xFFF
	X86_MEM_WRITE_u16(base, ctx.ecx + 0x80u, X86_MEM_READ_u16(base, ctx.ecx + 0x80u) | 4095);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ecx + 0x80u), 16);
	// 0x2F70E9: test byte ptr [esp+0x18], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x18u) & 1, 8);
	// 0x2F70EE: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F70EF: jnz 0x002F70F7
	if (!ctx.flags.zf) goto loc_2F70F7;
	// 0x2F70F1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F70F2: call 0x002F6804
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CommitDeferredSettings(ctx, base);
	ctx.esp += 4;
loc_2F70F7:
	// 0x2F70F7: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F70F9: jz 0x002F7106
	if (ctx.flags.zf) goto loc_2F7106;
	// 0x2F70FB: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7100: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F7106:
	// 0x2F7106: mov eax, edi
	ctx.eax = ctx.edi;
loc_2F7108:
	// 0x2F7108: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7109: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F710A: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F710D(X86Context& ctx, uint8_t* base) {
	// 0x2F710D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F710E: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F7110: call 0x002F69BB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F69BB(ctx, base);
	ctx.esp += 4;
	// 0x2F7115: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F711A: jz 0x002F7122
	if (ctx.flags.zf) goto loc_2F7122;
	// 0x2F711C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F711D: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F7122:
	// 0x2F7122: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F7124: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7125: ret 0x04
	ctx.esp += 4;
	return;
}

void IDirectSound_CreateSoundBuffer(X86Context& ctx, uint8_t* base) {
	// 0x2F7128: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F712C: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F7130: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7134: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7136: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F713A: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F713D: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F713F: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7141: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F7143: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7144: call 0x002F6C48
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CreateSoundBuffer(ctx, base);
	ctx.esp += 4;
	// 0x2F7149: ret 0x10
	ctx.esp += 16;
	return;
}

void IDirectSound_SetDistanceFactor(X86Context& ctx, uint8_t* base) {
	// 0x2F714C: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7150: fld [esp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0xCu));
	// 0x2F7154: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F7158: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7159: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F715B: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F715E: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7161: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F7163: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7165: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F7167: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7168: call 0x002F6D75
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetDistanceFactor(ctx, base);
	ctx.esp += 4;
	// 0x2F716D: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSound_SetDopplerFactor(X86Context& ctx, uint8_t* base) {
	// 0x2F7170: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7174: fld [esp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0xCu));
	// 0x2F7178: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F717C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F717D: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F717F: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7182: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7185: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F7187: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7189: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F718B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F718C: call 0x002F6DD4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetDopplerFactor(ctx, base);
	ctx.esp += 4;
	// 0x2F7191: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSound_SetOrientation(X86Context& ctx, uint8_t* base) {
	// 0x2F7194: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7195: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7197: push [ebp+0x24]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x24u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F719A: fld [ebp+0x20]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x20u));
	// 0x2F719D: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F71A0: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F71A3: fstp [esp+0x14]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x14u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71A7: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F71A9: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F71AC: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F71AF: fstp [esp+0x10]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x10u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71B3: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F71B5: fld [ebp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x18u));
	// 0x2F71B8: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F71BA: fstp [esp+0x0C]
	X86_MEM_WRITE_F32(base, ctx.esp + 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71BE: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F71C0: fld [ebp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x14u));
	// 0x2F71C3: fstp [esp+0x08]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71C7: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	// 0x2F71CA: fstp [esp+0x04]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71CE: fld [ebp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F71D1: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71D4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F71D5: call 0x002F6E92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetOrientation(ctx, base);
	ctx.esp += 4;
	// 0x2F71DA: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F71DB: ret 0x20
	ctx.esp += 32;
	return;
}

void IDirectSound_SetPosition(X86Context& ctx, uint8_t* base) {
	// 0x2F71DE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F71DF: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F71E1: push [ebp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F71E4: fld [ebp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x14u));
	// 0x2F71E7: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F71EA: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F71ED: fstp [esp+0x08]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71F1: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F71F3: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	// 0x2F71F6: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F71F9: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F71FB: fstp [esp+0x04]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F71FF: fld [ebp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F7202: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7204: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F7206: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7209: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F720A: call 0x002F6F1F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetPosition(ctx, base);
	ctx.esp += 4;
	// 0x2F720F: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7210: ret 0x14
	ctx.esp += 20;
	return;
}

void IDirectSound_SetRolloffFactor(X86Context& ctx, uint8_t* base) {
	// 0x2F7213: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7217: fld [esp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0xCu));
	// 0x2F721B: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F721F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7220: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7222: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7225: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7228: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F722A: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F722C: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F722E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F722F: call 0x002F6E33
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetRolloffFactor(ctx, base);
	ctx.esp += 4;
	// 0x2F7234: ret 0x0C
	ctx.esp += 12;
	return;
}

void IDirectSound_SetVelocity(X86Context& ctx, uint8_t* base) {
	// 0x2F7237: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7238: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F723A: push [ebp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F723D: fld [ebp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x14u));
	// 0x2F7240: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F7243: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F7246: fstp [esp+0x08]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F724A: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F724C: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	// 0x2F724F: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7252: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F7254: fstp [esp+0x04]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7258: fld [ebp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F725B: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F725D: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F725F: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7262: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7263: call 0x002F6F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetVelocity(ctx, base);
	ctx.esp += 4;
	// 0x2F7268: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7269: ret 0x14
	ctx.esp += 20;
	return;
}

void IDirectSound_SetI3DL2Listener(X86Context& ctx, uint8_t* base) {
	// 0x2F726C: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F7270: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7274: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7276: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F727A: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F727D: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F727F: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7281: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F7283: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7284: call 0x002F7005
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_SetI3DL2Listener(ctx, base);
	ctx.esp += 4;
	// 0x2F7289: ret 0x0C
	ctx.esp += 12;
	return;
}

void DirectSound_CDirectSound_Initialize(X86Context& ctx, uint8_t* base) {
	// 0x2F728C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F728D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F728F: sub esp, 0x60
	{ uint32_t _d = ctx.esp; uint32_t _s = 96;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F7292: push 0xB4
	{ auto _pv = (uint32_t)(180); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7297: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F729C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F729E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F729F: jz 0x002F72AA
	if (ctx.flags.zf) goto loc_2F72AA;
	// 0x2F72A1: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F72A3: call 0x002F6775
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F6775(ctx, base);
	ctx.esp += 4;
	// 0x2F72A8: jmp 0x002F72AC
	goto loc_2F72AC;
loc_2F72AA:
	// 0x2F72AA: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F72AC:
	// 0x2F72AC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F72AD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F72AE: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F72B1: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x2F72B4: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F72B6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F72B7: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F72B9: mov edi, 0x7FF8FFF2
	ctx.edi = 2147024882;
	// 0x2F72BE: and eax, edi
	ctx.eax = ctx.eax & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F72C0: mov ebx, 0x8007000E
	ctx.ebx = -2147024882;
	// 0x2F72C5: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F72C7: js 0x002F73BE
	if (ctx.flags.sf) goto loc_2F73BE;
	// 0x2F72CD: push 0x540
	{ auto _pv = (uint32_t)(1344); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F72D2: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F72D7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F72D9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F72DA: jz 0x002F72EA
	if (ctx.flags.zf) goto loc_2F72EA;
	// 0x2F72DC: push [esi+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F72DF: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F72E1: call 0x002F82D5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F82D5(ctx, base);
	ctx.esp += 4;
	// 0x2F72E6: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F72E8: jmp 0x002F72EC
	goto loc_2F72EC;
loc_2F72EA:
	// 0x2F72EA: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F72EC:
	// 0x2F72EC: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F72EE: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F72F0: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F72F2: and eax, edi
	ctx.eax = ctx.eax & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F72F4: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F72F6: mov [esi+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ecx);
	// 0x2F72F9: js 0x002F73BE
	if (ctx.flags.sf) goto loc_2F73BE;
	// 0x2F72FF: call 0x002F8E8D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8E8D(ctx, base);
	ctx.esp += 4;
	// 0x2F7304: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7306: jl 0x002F73BE
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F73BE;
	// 0x2F730C: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F730E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F730F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F7311: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7313: lea edi, [ebp-0x20]
	ctx.edi = ctx.ebp - 0x20u;
	// 0x2F7316: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F7318: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7319: lea edi, [ebp-0x60]
	ctx.edi = ctx.ebp - 0x60u;
	// 0x2F731C: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F731E: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7320: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2F7323: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x2F7326: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7328: lea eax, [ebp-0x60]
	ctx.eax = ctx.ebp - 0x60u;
	// 0x2F732B: push 0x626F5344
	{ auto _pv = (uint32_t)(1651462980); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7330: mov dword ptr [ebp-0x20], 0x18
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, 24);
	// 0x2F7337: mov dword ptr [ebp-0x14], 0x2FEFA4
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, 3141540);
	// 0x2F733E: mov dword ptr [ebp-0x08], 0x08
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 8);
	// 0x2F7345: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F7348: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F734D: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x2F7350: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F7352: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7354: and eax, 0x7FF8FFF2
	ctx.eax = ctx.eax & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F7359: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F735B: js 0x002F73BE
	if (ctx.flags.sf) goto loc_2F73BE;
	// 0x2F735D: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F735F: mov [ebp+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.edi);
	// 0x2F7362: lea ebx, [esi+0x18]
	ctx.ebx = ctx.esi + 0x18u;
loc_2F7365:
	// 0x2F7365: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F7368: cmp ecx, 0x20
	{ uint32_t _d = ctx.ecx; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F736B: jnb 0x002F73BE
	if (!ctx.flags.cf) goto loc_2F73BE;
	// 0x2F736D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F736F:
	// 0x2F736F: lea edx, [ecx+eax*1]
	ctx.edx = ctx.ecx + ctx.eax;
	// 0x2F7372: mov [ebp+eax*8-0x60], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.eax * 8 - 0x60u, ctx.edx);
	// 0x2F7376: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7377: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F737A: jb 0x002F736F
	if (ctx.flags.cf) goto loc_2F736F;
	// 0x2F737C: cmp dword ptr [ebp-0x28], 0x1F
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x28u); uint32_t _s = 31;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7380: jnz 0x002F7385
	if (!ctx.flags.zf) goto loc_2F7385;
	// 0x2F7382: dec [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
loc_2F7385:
	// 0x2F7385: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7386: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7387: lea eax, [ebp-0x20]
	ctx.eax = ctx.ebp - 0x20u;
	// 0x2F738A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F738B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F738C: call 0x002F6C48
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CreateSoundBuffer(ctx, base);
	ctx.esp += 4;
	// 0x2F7391: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7393: jl 0x002F73B3
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F73B3;
	// 0x2F7395: mov eax, [esi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x2F7398: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F739A: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F739C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F739D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F739E: call 0x002F6750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundBuffer_SetBufferData(ctx, base);
	ctx.esp += 4;
	// 0x2F73A3: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F73A5: jl 0x002F73B3
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F73B3;
	// 0x2F73A7: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F73A9: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73AB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73AC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73AD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73AE: call 0x002F5674
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	IDirectSoundBuffer_Play(ctx, base);
	ctx.esp += 4;
loc_2F73B3:
	// 0x2F73B3: add dword ptr [ebp+0x08], 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)8, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x2F73B7: add ebx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)4, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F73BA: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F73BC: jnl 0x002F7365
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F7365;
loc_2F73BE:
	// 0x2F73BE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F73BF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F73C0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F73C1: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F73C2: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F73C5(X86Context& ctx, uint8_t* base) {
	// 0x2F73C5: mov eax, [0x00300B20]
	ctx.eax = X86_MEM_READ_u32(base, 0x300B20u);
	// 0x2F73CA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73CB: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F73CD: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F73CF: jz 0x002F73DF
	if (ctx.flags.zf) goto loc_2F73DF;
	// 0x2F73D1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73D2: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F73D7: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F73DB: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F73DD: jmp 0x002F742C
	goto loc_2F742C;
loc_2F73DF:
	// 0x2F73DF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73E0: push 0x2C
	{ auto _pv = (uint32_t)(44); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F73E2: call 0x002F3F5F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	operator_new_4(ctx, base);
	ctx.esp += 4;
	// 0x2F73E7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F73E9: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F73EA: jz 0x002F73F7
	if (ctx.flags.zf) goto loc_2F73F7;
	// 0x2F73EC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F73EE: call 0x002F42B8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_CDirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F73F3: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F73F5: jmp 0x002F73F9
	goto loc_2F73F9;
loc_2F73F7:
	// 0x2F73F7: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F73F9:
	// 0x2F73F9: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x2F73FB: neg esi
	{ uint32_t _d = ctx.esi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.esi = _res; }
	// 0x2F73FD: sbb esi, esi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F73FF: and esi, 0x7FF8FFF2
	ctx.esi = ctx.esi & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F7405: add esi, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)-2147024882, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F740B: js 0x002F7421
	if (ctx.flags.sf) goto loc_2F7421;
	// 0x2F740D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F740E: call 0x002F728C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_CDirectSound_Initialize(ctx, base);
	ctx.esp += 4;
	// 0x2F7413: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F7415: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F7417: jl 0x002F7421
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F7421;
	// 0x2F7419: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F741D: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x2F741F: jmp 0x002F742B
	goto loc_2F742B;
loc_2F7421:
	// 0x2F7421: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F7423: jz 0x002F742B
	if (ctx.flags.zf) goto loc_2F742B;
	// 0x2F7425: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F7427: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7428: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F742B:
	// 0x2F742B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F742C:
	// 0x2F742C: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F742E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F742F: ret 0x04
	ctx.esp += 4;
	return;
}

void DirectSoundCreate(X86Context& ctx, uint8_t* base) {
	// 0x2F7432: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7433: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7435: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7436: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7437: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7438: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F743D: movzx esi, al
	ctx.esi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F7440: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x2F7443: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7444: call 0x002F73C5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F73C5(ctx, base);
	ctx.esp += 4;
	// 0x2F7449: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F744B: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F744D: jl 0x002F7462
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F7462;
	// 0x2F744F: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F7452: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7454: add eax, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7457: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2F7459: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F745B: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F745D: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F7460: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
loc_2F7462:
	// 0x2F7462: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F7464: jz 0x002F7471
	if (ctx.flags.zf) goto loc_2F7471;
	// 0x2F7466: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F746B: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F7471:
	// 0x2F7471: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F7473: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7474: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7475: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7476: ret 0x0C
	ctx.esp += 12;
	return;
}

void DirectSoundCreateStream(X86Context& ctx, uint8_t* base) {
	// 0x2F7479: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F747A: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F747C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F747D: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F7481: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7482: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7483: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7484: call 0x002F4175
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSoundEnterCriticalSection(ctx, base);
	ctx.esp += 4;
	// 0x2F7489: movzx edi, al
	ctx.edi = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x2F748C: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x2F748F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7490: call 0x002F73C5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F73C5(ctx, base);
	ctx.esp += 4;
	// 0x2F7495: mov esi, [ebp-0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F7498: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2F749A: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F749C: jl 0x002F74AE
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F74AE;
	// 0x2F749E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74A0: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74A3: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74A6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74A7: call 0x002F6CE4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound_CreateSoundStream(ctx, base);
	ctx.esp += 4;
	// 0x2F74AC: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_2F74AE:
	// 0x2F74AE: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F74B0: jz 0x002F74B8
	if (ctx.flags.zf) goto loc_2F74B8;
	// 0x2F74B2: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F74B4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74B5: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F74B8:
	// 0x2F74B8: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F74BA: jz 0x002F74C7
	if (ctx.flags.zf) goto loc_2F74C7;
	// 0x2F74BC: push 0x3004AC
	{ auto _pv = (uint32_t)(3146924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74C1: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F74C7:
	// 0x2F74C7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F74C8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F74C9: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F74CB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F74CC: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F74CD: ret 0x08
	ctx.esp += 8;
	return;
}

void DSound_CMemoryManager_PoolAlloc(X86Context& ctx, uint8_t* base) {
	// 0x2F74D0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74D1: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74D5: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74D9: call [0x0036B924]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B924u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F74DF: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F74E1: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F74E3: jz 0x002F7511
	if (ctx.flags.zf) goto loc_2F7511;
	// 0x2F74E5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F74E6: call [0x0036B970]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B970u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F74EC: mov edx, [0x00300B48]
	ctx.edx = X86_MEM_READ_u32(base, 0x300B48u);
	// 0x2F74F2: add [edx], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edx), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.edx, (uint32_t)_res); }
	// 0x2F74F4: cmp dword ptr [esp+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F74F9: jz 0x002F7511
	if (ctx.flags.zf) goto loc_2F7511;
	// 0x2F74FB: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F74FD: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x2F74FF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7500: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F7503: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F7505: mov edi, esi
	ctx.edi = ctx.esi;
	// 0x2F7507: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F7509: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x2F750B: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F750E: rep stosb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x2F7510: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F7511:
	// 0x2F7511: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F7513: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7514: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F7517(X86Context& ctx, uint8_t* base) {
	// 0x2F7517: push [esp+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F751B: call [0x0036B970]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B970u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F7521: mov ecx, [0x00300B48]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300B48u);
	// 0x2F7527: sub [ecx], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx, (uint32_t)_res); }
	// 0x2F7529: jmp [0x0036B928]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B928u));
	return;
}

void sub_2F752F(X86Context& ctx, uint8_t* base) {
	// 0x2F752F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7530: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7534: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7538: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F753A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F753C: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7540: call [0x0036B814]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B814u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F7546: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F7548: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F754A: jz 0x002F7578
	if (ctx.flags.zf) goto loc_2F7578;
	// 0x2F754C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F754D: call [0x0036B818]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B818u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F7553: mov edx, [0x00300B44]
	ctx.edx = X86_MEM_READ_u32(base, 0x300B44u);
	// 0x2F7559: add [edx], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edx), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.edx, (uint32_t)_res); }
	// 0x2F755B: cmp dword ptr [esp+0x14], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x14u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7560: jz 0x002F7578
	if (ctx.flags.zf) goto loc_2F7578;
	// 0x2F7562: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7564: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x2F7566: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7567: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F756A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F756C: mov edi, esi
	ctx.edi = ctx.esi;
	// 0x2F756E: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F7570: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x2F7572: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F7575: rep stosb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x2F7577: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F7578:
	// 0x2F7578: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F757A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F757B: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F757E(X86Context& ctx, uint8_t* base) {
	// 0x2F757E: push [esp+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7582: call [0x0036B818]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B818u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F7588: mov ecx, [0x00300B44]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300B44u);
	// 0x2F758E: sub [ecx], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx, (uint32_t)_res); }
	// 0x2F7590: jmp [0x0036B820]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B820u));
	return;
}

void sub_2F7596(X86Context& ctx, uint8_t* base) {
	// 0x2F7596: mov ecx, [0x00300A98]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300A98u);
	// 0x2F759C: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F759E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F759F: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F75A3: jz 0x002F75D2
	if (ctx.flags.zf) goto loc_2F75D2;
	// 0x2F75A5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F75A6: call 0x002FA1B1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA1B1(ctx, base);
	ctx.esp += 4;
	// 0x2F75AB: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x2F75AD: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F75AF: jz 0x002F75D8
	if (ctx.flags.zf) goto loc_2F75D8;
	// 0x2F75B1: cmp dword ptr [esp+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F75B6: jz 0x002F75D4
	if (ctx.flags.zf) goto loc_2F75D4;
	// 0x2F75B8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F75B9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F75BA: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F75BC: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2F75BE: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F75C1: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F75C3: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x2F75C5: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F75C7: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2F75C9: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F75CC: rep stosb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_REG8L(ctx.eax));
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x2F75CE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F75CF: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F75D0: jmp 0x002F75D4
	goto loc_2F75D4;
loc_2F75D2:
	// 0x2F75D2: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F75D4:
	// 0x2F75D4: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F75D6: jnz 0x002F75F8
	if (!ctx.flags.zf) goto loc_2F75F8;
loc_2F75D8:
	// 0x2F75D8: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F75DC: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F75DF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F75E0: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F75E4: call 0x002F74D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DSound_CMemoryManager_PoolAlloc(ctx, base);
	ctx.esp += 4;
	// 0x2F75E9: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x2F75EB: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F75ED: jz 0x002F75F8
	if (ctx.flags.zf) goto loc_2F75F8;
	// 0x2F75EF: mov dword ptr [edx], 0x6C6F6F70
	X86_MEM_WRITE_u32(base, ctx.edx, 1819242352);
	// 0x2F75F5: add edx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)4, 32);
	  ctx.edx = (uint32_t)_res; }
loc_2F75F8:
	// 0x2F75F8: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x2F75FA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F75FB: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F75FE(X86Context& ctx, uint8_t* base) {
	// 0x2F75FE: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F7602: lea eax, [edx-0x04]
	ctx.eax = ctx.edx - 0x4u;
	// 0x2F7605: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F7607: cmp ecx, 0x6C6F6F70
	{ uint32_t _d = ctx.ecx; uint32_t _s = 1819242352;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F760D: jnz 0x002F7617
	if (!ctx.flags.zf) goto loc_2F7617;
	// 0x2F760F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7610: call 0x002F7517
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7517(ctx, base);
	ctx.esp += 4;
	// 0x2F7615: jmp 0x002F762F
	goto loc_2F762F;
loc_2F7617:
	// 0x2F7617: cmp ecx, 0x706F6C73
	{ uint32_t _d = ctx.ecx; uint32_t _s = 1886350451;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F761D: jnz 0x002F762F
	if (!ctx.flags.zf) goto loc_2F762F;
	// 0x2F761F: mov ecx, [0x00300A98]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300A98u);
	// 0x2F7625: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F7627: jz 0x002F762F
	if (ctx.flags.zf) goto loc_2F762F;
	// 0x2F7629: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F762A: call 0x002FA3CE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA3CE(ctx, base);
	ctx.esp += 4;
loc_2F762F:
	// 0x2F762F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F7632(X86Context& ctx, uint8_t* base) {
	// 0x2F7632: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F7636: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F763A: mov word ptr [eax], 0x01
	X86_MEM_WRITE_u16(base, ctx.eax, 1);
	// 0x2F763F: mov dl, [ecx+0x02]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ecx + 0x2u);
	// 0x2F7642: mov [eax+0x02], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x2u, X86_REG8L(ctx.edx));
	// 0x2F7645: mov dl, [ecx+0x0E]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ecx + 0xEu);
	// 0x2F7648: mov [eax+0x03], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3u, X86_REG8L(ctx.edx));
	// 0x2F764B: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F764E: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x2F7651: movzx ecx, byte ptr [ecx+0x0C]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0xCu));
	// 0x2F7655: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2F7658: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F765B(X86Context& ctx, uint8_t* base) {
	// 0x2F765B: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F765F: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F7663: mov word ptr [eax], 0x69
	X86_MEM_WRITE_u16(base, ctx.eax, 105);
	// 0x2F7668: mov dl, [ecx+0x02]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ecx + 0x2u);
	// 0x2F766B: mov [eax+0x02], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x2u, X86_REG8L(ctx.edx));
	// 0x2F766E: mov byte ptr [eax+0x03], 0x04
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3u, 4);
	// 0x2F7672: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F7675: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x2F7678: movzx ecx, byte ptr [ecx+0x0C]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0xCu));
	// 0x2F767C: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2F767F: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F7682(X86Context& ctx, uint8_t* base) {
	// 0x2F7682: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7683: mov ebx, [esp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F7687: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7688: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7689: lea eax, [ebx+0x18]
	ctx.eax = ctx.ebx + 0x18u;
	// 0x2F768C: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F768E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F768F: mov edi, 0x300160
	ctx.edi = 3146080;
	// 0x2F7694: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F7696: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F7698: repe cmpsd
	while (ctx.ecx) {
		uint32_t _a = X86_MEM_READ_u32(base, ctx.esi);
		uint32_t _b = X86_MEM_READ_u32(base, ctx.edi);
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
		{ uint64_t _res = (uint64_t)_a - (uint64_t)_b;
		  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_a, (int32_t)_b, 32); }
		if (!ctx.flags.zf) break;
	}
	// 0x2F769A: jnz 0x002F76A8
	if (!ctx.flags.zf) goto loc_2F76A8;
	// 0x2F769C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F769D: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76A1: call 0x002F7632
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7632(ctx, base);
	ctx.esp += 4;
	// 0x2F76A6: jmp 0x002F76C2
	goto loc_2F76C2;
loc_2F76A8:
	// 0x2F76A8: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76AA: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F76AC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F76AD: mov edi, 0x300150
	ctx.edi = 3146064;
	// 0x2F76B2: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F76B4: repe cmpsd
	while (ctx.ecx) {
		uint32_t _a = X86_MEM_READ_u32(base, ctx.esi);
		uint32_t _b = X86_MEM_READ_u32(base, ctx.edi);
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
		{ uint64_t _res = (uint64_t)_a - (uint64_t)_b;
		  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_a, (int32_t)_b, 32); }
		if (!ctx.flags.zf) break;
	}
	// 0x2F76B6: jnz 0x002F76C2
	if (!ctx.flags.zf) goto loc_2F76C2;
	// 0x2F76B8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76B9: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76BD: call 0x002F765B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F765B(ctx, base);
	ctx.esp += 4;
loc_2F76C2:
	// 0x2F76C2: mov eax, [ebx+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	// 0x2F76C5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F76C6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F76C7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F76C8: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F76CB(X86Context& ctx, uint8_t* base) {
	// 0x2F76CB: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F76CF: movzx eax, word ptr [ecx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx));
	// 0x2F76D2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76D3: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F76D5: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F76D6: jz 0x002F76FE
	if (ctx.flags.zf) goto loc_2F76FE;
	// 0x2F76D8: sub eax, 0x68
	{ uint32_t _d = ctx.eax; uint32_t _s = 104;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F76DB: jz 0x002F76F2
	if (ctx.flags.zf) goto loc_2F76F2;
	// 0x2F76DD: sub eax, 0xFF95
	{ uint32_t _d = ctx.eax; uint32_t _s = 65429;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F76E2: jnz 0x002F7708
	if (!ctx.flags.zf) goto loc_2F7708;
	// 0x2F76E4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76E5: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76E9: call 0x002F7682
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7682(ctx, base);
	ctx.esp += 4;
	// 0x2F76EE: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F76F0: jmp 0x002F7708
	goto loc_2F7708;
loc_2F76F2:
	// 0x2F76F2: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76F3: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76F7: call 0x002F765B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F765B(ctx, base);
	ctx.esp += 4;
	// 0x2F76FC: jmp 0x002F7708
	goto loc_2F7708;
loc_2F76FE:
	// 0x2F76FE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F76FF: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7703: call 0x002F7632
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7632(ctx, base);
	ctx.esp += 4;
loc_2F7708:
	// 0x2F7708: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F770A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F770B: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F770E(X86Context& ctx, uint8_t* base) {
	// 0x2F770E: mov dword ptr [0x00300B48], 0x300474
	X86_MEM_WRITE_u32(base, 0x300B48u, 3146868);
	// 0x2F7718: ret
	return;
}

void sub_2F7719(X86Context& ctx, uint8_t* base) {
	// 0x2F7719: mov dword ptr [0x00300B44], 0x300478
	X86_MEM_WRITE_u32(base, 0x300B44u, 3146872);
	// 0x2F7723: ret
	return;
}

void sub_2F7724(X86Context& ctx, uint8_t* base) {
	// 0x2F7724: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F7728: fld [eax+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F772B: fld [eax+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F772E: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F7730: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2F7732: fmul st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[1]);
	// 0x2F7734: fld st2
	X86_FPU_PUSH(ctx, ctx.fp_stack[2]);
	// 0x2F7736: fmul st0, st3
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[3]);
	// 0x2F7738: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F773A: fld st3
	X86_FPU_PUSH(ctx, ctx.fp_stack[3]);
	// 0x2F773C: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x2F773E: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7740: fsqrt
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, sqrt(ctx.fp_stack[ctx.fp_top]));
	// 0x2F7742: fstp st3
	ctx.fp_stack[3] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7744: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7746: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7748: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F774B(X86Context& ctx, uint8_t* base) {
	// 0x2F774B: fld [esp+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x4u));
	// 0x2F774F: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x2F7755: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7757: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2F775A: jnz 0x002F777D
	if (!ctx.flags.zf) goto loc_2F777D;
	// 0x2F775C: fld [esp+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x4u));
	// 0x2F7760: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7761: fadd [0x003B168C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x2F7767: fldlg2
	X86_FPU_PUSH(ctx, 0.3010299957316877); // log10(2)
	// 0x2F7769: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x2F776B: fyl2x
	{ double _y = ctx.fp_stack[(ctx.fp_top + 1) & 7];
	  double _x = ctx.fp_stack[ctx.fp_top];
	  X86_FPU_POP(ctx);
	  ctx.fp_stack[ctx.fp_top] = _y * log2(_x); }
	// 0x2F776D: fmul [0x0036C1FC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x36C1FCu));
	// 0x2F7773: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7776: call 0x002FC98A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC98A(ctx, base);
	ctx.esp += 4;
	// 0x2F777B: jmp 0x002F777F
	goto loc_2F777F;
loc_2F777D:
	// 0x2F777D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F777F:
	// 0x2F777F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F7782(X86Context& ctx, uint8_t* base) {
	// 0x2F7782: fld [esp+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x4u));
	// 0x2F7786: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x2F778C: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F778E: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F7791: jp 0x002F779A
	if (ctx.flags.pf) goto loc_2F779A;
	// 0x2F7793: mov eax, 0xFFFFD8F0
	ctx.eax = -10000;
	// 0x2F7798: jmp 0x002F77C8
	goto loc_2F77C8;
loc_2F779A:
	// 0x2F779A: fld [esp+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x4u));
	// 0x2F779E: fcomp [0x003B168C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	X86_FPU_POP(ctx);
	// 0x2F77A4: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F77A6: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2F77A9: jnz 0x002F77AF
	if (!ctx.flags.zf) goto loc_2F77AF;
	// 0x2F77AB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F77AD: jmp 0x002F77C8
	goto loc_2F77C8;
loc_2F77AF:
	// 0x2F77AF: fld [esp+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x4u));
	// 0x2F77B3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F77B4: fldlg2
	X86_FPU_PUSH(ctx, 0.3010299957316877); // log10(2)
	// 0x2F77B6: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x2F77B8: fyl2x
	{ double _y = ctx.fp_stack[(ctx.fp_top + 1) & 7];
	  double _x = ctx.fp_stack[ctx.fp_top];
	  X86_FPU_POP(ctx);
	  ctx.fp_stack[ctx.fp_top] = _y * log2(_x); }
	// 0x2F77BA: fmul [0x003B16CC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16CCu));
	// 0x2F77C0: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F77C3: call 0x002FC98A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC98A(ctx, base);
	ctx.esp += 4;
loc_2F77C8:
	// 0x2F77C8: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F77CB(X86Context& ctx, uint8_t* base) {
	// 0x2F77CB: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F77CF: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F77D3: fld [ecx+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x4u));
	// 0x2F77D6: fmul [eax+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F77D9: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F77DD: fld [ecx+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F77E0: fmul [eax+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F77E3: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F77E5: fstp [edx]
	X86_MEM_WRITE_F32(base, ctx.edx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F77E7: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F77E9: fmul [ecx+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F77EC: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F77EE: fmul [eax+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F77F1: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F77F3: fstp [edx+0x04]
	X86_MEM_WRITE_F32(base, ctx.edx + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F77F6: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F77F8: fmul [eax+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F77FB: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F77FD: fmul [ecx+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx + 0x4u));
	// 0x2F7800: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7802: fstp [edx+0x08]
	X86_MEM_WRITE_F32(base, ctx.edx + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7805: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F7808(X86Context& ctx, uint8_t* base) {
	// 0x2F7808: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7809: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F780B: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F780E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F780F: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F7812: fld [esi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi));
	// 0x2F7814: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7815: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F7818: fsub [edi]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi));
	// 0x2F781A: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x2F781D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F781E: fstp [ebp-0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7821: fld [esi+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x4u));
	// 0x2F7824: fsub [edi+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x4u));
	// 0x2F7827: fstp [ebp-0x08]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F782A: fld [esi+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x8u));
	// 0x2F782D: fsub [edi+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x8u));
	// 0x2F7830: fstp [ebp-0x04]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7833: call 0x002F7724
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7724(ctx, base);
	ctx.esp += 4;
	// 0x2F7838: fstp [ebp+0x08]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F783B: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x2F783E: fld [esi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi));
	// 0x2F7840: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7841: fadd [edi]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, ctx.edi));
	// 0x2F7843: fstp [ebp-0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7846: fld [edi+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x4u));
	// 0x2F7849: fadd [esi+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, ctx.esi + 0x4u));
	// 0x2F784C: fstp [ebp-0x08]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F784F: fld [edi+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x8u));
	// 0x2F7852: fadd [esi+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, ctx.esi + 0x8u));
	// 0x2F7855: fstp [ebp-0x04]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7858: call 0x002F7724
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7724(ctx, base);
	ctx.esp += 4;
	// 0x2F785D: fcom [ebp+0x08]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7860: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7861: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7862: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7864: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x2F7867: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F786A: jp 0x002F787F
	if (ctx.flags.pf) goto loc_2F787F;
	// 0x2F786C: fdiv [ebp+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] / (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F786F: fmul [0x003B1770]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1770u));
	// 0x2F7875: fmul [0x003B1690]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1690u));
	// 0x2F787B: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F787D: jmp 0x002F789A
	goto loc_2F789A;
loc_2F787F:
	// 0x2F787F: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7882: fdiv st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] / ctx.fp_stack[1]);
	// 0x2F7884: fmul [0x003B1770]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1770u));
	// 0x2F788A: fsubr [0x003B1850]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x3B1850u) - ctx.fp_stack[ctx.fp_top]);
	// 0x2F7890: fmul [0x003B1690]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1690u));
	// 0x2F7896: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7898: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_2F789A:
	// 0x2F789A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F789B: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F789E(X86Context& ctx, uint8_t* base) {
	// 0x2F789E: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F789F: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F78A1: cmp dword ptr [ebp+0x08], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F78A5: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F78A8: fld [eax+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F78AB: jnz 0x002F78C1
	if (!ctx.flags.zf) goto loc_2F78C1;
	// 0x2F78AD: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F78B0: fmul [ecx+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F78B3: fld [eax+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F78B6: fmul [ecx+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx + 0x4u));
	// 0x2F78B9: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F78BB: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F78BD: fmul [ecx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F78BF: jmp 0x002F78DE
	goto loc_2F78DE;
loc_2F78C1:
	// 0x2F78C1: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F78C4: fsub [ecx+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F78C7: mov edx, [ebp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F78CA: fmul [edx+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.edx + 0x8u));
	// 0x2F78CD: fld [eax+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F78D0: fsub [ecx+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ecx + 0x4u));
	// 0x2F78D3: fmul [edx+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.edx + 0x4u));
	// 0x2F78D6: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F78D8: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F78DA: fsub [ecx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F78DC: fmul [edx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.edx));
loc_2F78DE:
	// 0x2F78DE: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F78E1: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F78E3: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F78E5: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F78E6: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_2F78E9(X86Context& ctx, uint8_t* base) {
	// 0x2F78E9: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F78EA: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F78EC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F78ED: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F78EE: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F78F1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F78F2: fcomp [ebp+0x0C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	X86_FPU_POP(ctx);
	// 0x2F78F5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F78F6: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F78F8: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F78FB: jnz 0x002F79EE
	if (!ctx.flags.zf) goto loc_2F79EE;
	// 0x2F7901: cmp dword ptr [ebp+0x20], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x20u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7905: jz 0x002F7922
	if (ctx.flags.zf) goto loc_2F7922;
	// 0x2F7907: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F790A: fcomp [ebp+0x10]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	X86_FPU_POP(ctx);
	// 0x2F790D: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F790F: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2F7912: jnz 0x002F7922
	if (!ctx.flags.zf) goto loc_2F7922;
	// 0x2F7914: mov eax, [ebp+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x24u);
	// 0x2F7917: mov dword ptr [eax], 0xFFFFD8F0
	X86_MEM_WRITE_u32(base, ctx.eax, -10000);
	// 0x2F791D: jmp 0x002F79F4
	goto loc_2F79F4;
loc_2F7922:
	// 0x2F7922: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F7925: fcomp [ebp+0x10]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	X86_FPU_POP(ctx);
	// 0x2F7928: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F792A: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F792D: jnz 0x002F7935
	if (!ctx.flags.zf) goto loc_2F7935;
	// 0x2F792F: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F7932: mov [ebp+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x1Cu, ctx.eax);
loc_2F7935:
	// 0x2F7935: mov edi, [ebp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7938: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F793A: jz 0x002F79D4
	if (ctx.flags.zf) goto loc_2F79D4;
	// 0x2F7940: mov esi, [ebp+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F7943: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F7945: jz 0x002F79D4
	if (ctx.flags.zf) goto loc_2F79D4;
	// 0x2F794B: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F794E: mov [ebp+0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x1Cu, ctx.esi);
	// 0x2F7951: fsub [ebp+0x0C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F7954: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	// 0x2F7957: fsub [ebp+0x0C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F795A: fild [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu)));
	// 0x2F795D: jnl 0x002F7965
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F7965;
	// 0x2F795F: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_2F7965:
	// 0x2F7965: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7967: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2F7969: fdiv st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] / ctx.fp_stack[1]);
	// 0x2F796B: fst [ebp+0x1C]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x1Cu, ctx.fp_stack[ctx.fp_top]);
	// 0x2F796E: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x2F7970: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x2F7975: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7977: jb 0x002F797C
	if (ctx.flags.cf) goto loc_2F797C;
	// 0x2F7979: lea eax, [esi-0x01]
	ctx.eax = ctx.esi - 0x1u;
loc_2F797C:
	// 0x2F797C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F797E: jnz 0x002F798E
	if (!ctx.flags.zf) goto loc_2F798E;
	// 0x2F7980: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F7982: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7984: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2F7986: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F7989: fstp [ebp-0x08]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F798C: jmp 0x002F79B2
	goto loc_2F79B2;
loc_2F798E:
	// 0x2F798E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7990: lea ecx, [edi+eax*4]
	ctx.ecx = ctx.edi + ctx.eax * 4;
	// 0x2F7993: mov edx, [ecx-0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx - 0x4u);
	// 0x2F7996: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F7998: mov [ebp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.eax);
	// 0x2F799B: fild [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)));
	// 0x2F799E: mov [ebp-0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.edx);
	// 0x2F79A1: mov [ebp-0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ecx);
	// 0x2F79A4: jnl 0x002F79AC
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F79AC;
	// 0x2F79A6: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_2F79AC:
	// 0x2F79AC: fmul st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[1]);
	// 0x2F79AE: fsubp st2, st0
	ctx.fp_stack[2] = X86_FPU_ROUND(ctx, ctx.fp_stack[2] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F79B0: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_2F79B2:
	// 0x2F79B2: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F79B5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F79B6: fmul st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[1]);
	// 0x2F79B8: fld [ebp-0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp - 0x4u));
	// 0x2F79BB: fsub [ebp-0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ebp - 0x8u));
	// 0x2F79BE: fmulp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] * ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F79C0: fadd [ebp-0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, ctx.ebp - 0x8u));
	// 0x2F79C3: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F79C6: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F79C8: call 0x002F402B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F402B(ctx, base);
	ctx.esp += 4;
loc_2F79CD:
	// 0x2F79CD: mov ecx, [ebp+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x24u);
	// 0x2F79D0: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F79D2: jmp 0x002F79F4
	goto loc_2F79F4;
loc_2F79D4:
	// 0x2F79D4: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F79D7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F79D8: fdiv [ebp+0x0C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] / (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F79DB: fsub [0x003B168C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x2F79E1: fmul [ebp+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F79E4: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F79E7: call 0x002F774B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F774B(ctx, base);
	ctx.esp += 4;
	// 0x2F79EC: jmp 0x002F79CD
	goto loc_2F79CD;
loc_2F79EE:
	// 0x2F79EE: mov eax, [ebp+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x24u);
	// 0x2F79F1: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
loc_2F79F4:
	// 0x2F79F4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F79F5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F79F6: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F79F7: ret 0x20
	ctx.esp += 32;
	return;
}

void sub_2F79FA(X86Context& ctx, uint8_t* base) {
	// 0x2F79FA: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F79FB: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F79FD: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F7A00: fild [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)));
	// 0x2F7A03: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F7A05: jnl 0x002F7A0D
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F7A0D;
	// 0x2F7A07: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_2F7A0D:
	// 0x2F7A0D: fld [ebp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x14u));
	// 0x2F7A10: fcomp st1
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[1]);
	X86_FPU_POP(ctx);
	// 0x2F7A12: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7A14: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F7A17: jp 0x002F7A23
	if (ctx.flags.pf) goto loc_2F7A23;
	// 0x2F7A19: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F7A1C: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7A1E: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2F7A21: jmp 0x002F7A86
	goto loc_2F7A86;
loc_2F7A23:
	// 0x2F7A23: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F7A26: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7A28: jnb 0x002F7A50
	if (!ctx.flags.cf) goto loc_2F7A50;
	// 0x2F7A2A: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F7A2C: mov [ebp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.ecx);
	// 0x2F7A2F: fild [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)));
	// 0x2F7A32: jnl 0x002F7A3A
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F7A3A;
	// 0x2F7A34: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_2F7A3A:
	// 0x2F7A3A: fcomp [ebp+0x14]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.ebp + 0x14u));
	X86_FPU_POP(ctx);
	// 0x2F7A3D: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7A3F: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F7A42: jp 0x002F7A50
	if (ctx.flags.pf) goto loc_2F7A50;
	// 0x2F7A44: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F7A47: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7A49: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F7A4C: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F7A4E: jmp 0x002F7A86
	goto loc_2F7A86;
loc_2F7A50:
	// 0x2F7A50: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F7A52: sub eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7A54: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7A57: jnb 0x002F7A5C
	if (!ctx.flags.cf) goto loc_2F7A5C;
	// 0x2F7A59: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F7A5B: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2F7A5C:
	// 0x2F7A5C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7A5E: fld [ebp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x14u));
	// 0x2F7A61: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x2F7A63: mov [ebp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x14u, ctx.eax);
	// 0x2F7A66: fimul [ebp+0x10]
	ctx.fp_stack[ctx.fp_top] *= (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u));
	// 0x2F7A69: fild [ebp+0x14]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x14u)));
	// 0x2F7A6C: jnl 0x002F7A74
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F7A74;
	// 0x2F7A6E: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_2F7A74:
	// 0x2F7A74: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7A76: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7A77: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7A7A: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7A7C: call 0x002FC98A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC98A(ctx, base);
	ctx.esp += 4;
	// 0x2F7A81: mov ecx, [ebp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F7A84: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
loc_2F7A86:
	// 0x2F7A86: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7A87: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_2F7A8A(X86Context& ctx, uint8_t* base) {
	// 0x2F7A8A: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7A8B: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7A8D: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7A90: fmul [ebp+0x0C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F7A93: fmul [ebp+0x10]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	// 0x2F7A96: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x2F7A9C: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F7A9E: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F7AA0: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7AA2: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F7AA5: jp 0x002F7AB1
	if (ctx.flags.pf) goto loc_2F7AB1;
	// 0x2F7AA7: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7AAA: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7AAC: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2F7AAF: jmp 0x002F7AFF
	goto loc_2F7AFF;
loc_2F7AB1:
	// 0x2F7AB1: fcom [0x002FF08C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x2FF08Cu));
	// 0x2F7AB7: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7AB9: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2F7ABC: jnz 0x002F7ACB
	if (!ctx.flags.zf) goto loc_2F7ACB;
	// 0x2F7ABE: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7AC1: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7AC3: mov dword ptr [eax], 0xFFFF8001
	X86_MEM_WRITE_u32(base, ctx.eax, -32767);
	// 0x2F7AC9: jmp 0x002F7AFF
	goto loc_2F7AFF;
loc_2F7ACB:
	// 0x2F7ACB: fcom [0x0036C204]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x36C204u));
	// 0x2F7AD1: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7AD3: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F7AD6: jp 0x002F7AE5
	if (ctx.flags.pf) goto loc_2F7AE5;
	// 0x2F7AD8: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7ADB: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7ADD: mov dword ptr [eax], 0x1000
	X86_MEM_WRITE_u32(base, ctx.eax, 4096);
	// 0x2F7AE3: jmp 0x002F7AFF
	goto loc_2F7AFF;
loc_2F7AE5:
	// 0x2F7AE5: fmul [0x0036C200]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x36C200u));
	// 0x2F7AEB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7AEC: fsubr [0x003B168C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu) - ctx.fp_stack[ctx.fp_top]);
	// 0x2F7AF2: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7AF5: call 0x002F9DE9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9DE9(ctx, base);
	ctx.esp += 4;
	// 0x2F7AFA: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7AFD: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
loc_2F7AFF:
	// 0x2F7AFF: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7B00: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F7B03(X86Context& ctx, uint8_t* base) {
	// 0x2F7B03: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7B04: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7B06: cmp dword ptr [ebp+0x08], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7B0A: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F7B0D: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F7B0F: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7B12: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7B14: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F7B17: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2F7B1A: jz 0x002F7B2E
	if (ctx.flags.zf) goto loc_2F7B2E;
	// 0x2F7B1C: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F7B1E: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F7B21: fsub [ecx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F7B23: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7B25: fld [eax+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F7B28: fsub [ecx+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F7B2B: fstp [eax+0x08]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7B2E:
	// 0x2F7B2E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7B2F: call 0x002F9D72
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9D72(ctx, base);
	ctx.esp += 4;
	// 0x2F7B34: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F7B37: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7B39: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7B3A: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_2F7B3D(X86Context& ctx, uint8_t* base) {
	// 0x2F7B3D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7B3E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7B40: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F7B43: cmp dword ptr [ebp+0x08], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7B47: jz 0x002F7B51
	if (ctx.flags.zf) goto loc_2F7B51;
	// 0x2F7B49: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7B4C: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F7B4F: jmp 0x002F7B5B
	goto loc_2F7B5B;
loc_2F7B51:
	// 0x2F7B51: mov ecx, 0x2FF090
	ctx.ecx = 3141776;
	// 0x2F7B56: mov edx, 0x3001BC
	ctx.edx = 3146172;
loc_2F7B5B:
	// 0x2F7B5B: mov eax, [ebp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F7B5E: fld [edx+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edx + 0x8u));
	// 0x2F7B61: fmul [eax+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F7B64: fld [edx+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edx + 0x4u));
	// 0x2F7B67: fmul [eax+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F7B6A: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7B6C: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F7B6E: fmul [edx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.edx));
	// 0x2F7B70: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7B72: fld [ecx+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F7B75: fmul [eax+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x8u));
	// 0x2F7B78: fld [ecx+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x4u));
	// 0x2F7B7B: fmul [eax+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x4u));
	// 0x2F7B7E: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7B80: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x2F7B82: mov eax, [ebp+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x24u);
	// 0x2F7B85: fmul [ecx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F7B87: mov ecx, [ebp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x20u);
	// 0x2F7B8A: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F7B8C: fstp [ebp-0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp - 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7B8F: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x2F7B91: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7B93: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x2F7B99: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2F7B9B: fld [ebp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x1Cu));
	// 0x2F7B9E: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F7BA0: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7BA2: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F7BA5: jnp 0x002F7BDA
	if (!ctx.flags.pf) goto loc_2F7BDA;
	// 0x2F7BA7: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F7BA9: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x2F7BAB: fld [ebp-0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp - 0xCu));
	// 0x2F7BAE: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x2F7BB0: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F7BB2: fcomp st1
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[1]);
	X86_FPU_POP(ctx);
	// 0x2F7BB4: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7BB6: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F7BB9: jnz 0x002F7BC9
	if (!ctx.flags.zf) goto loc_2F7BC9;
	// 0x2F7BBB: fdiv st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] / ctx.fp_stack[1]);
	// 0x2F7BBD: fmul [0x003B1770]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1770u));
	// 0x2F7BC3: fstp [ecx]
	X86_MEM_WRITE_F32(base, ctx.ecx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7BC5:
	// 0x2F7BC5: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7BC7: jmp 0x002F7BDE
	goto loc_2F7BDE;
loc_2F7BC9:
	// 0x2F7BC9: fld st2
	X86_FPU_PUSH(ctx, ctx.fp_stack[2]);
	// 0x2F7BCB: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F7BCD: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F7BCF: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7BD1: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F7BD4: jp 0x002F7C0F
	if (ctx.flags.pf) goto loc_2F7C0F;
	// 0x2F7BD6: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7BD8: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_2F7BDA:
	// 0x2F7BDA: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x2F7BDC: fstp [ecx]
	X86_MEM_WRITE_F32(base, ctx.ecx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7BDE:
	// 0x2F7BDE: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F7BE0: fcompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F7BE2: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7BE4: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7BE6: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x2F7BE9: jp 0x002F7BF5
	if (ctx.flags.pf) goto loc_2F7BF5;
	// 0x2F7BEB: fld [0x003B1A04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B1A04u));
	// 0x2F7BF1: fsub [ecx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F7BF3: fstp [ecx]
	X86_MEM_WRITE_F32(base, ctx.ecx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7BF5:
	// 0x2F7BF5: fld [ebp-0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp - 0xCu));
	// 0x2F7BF8: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x2F7BFE: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7C00: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x2F7C03: jp 0x002F7C0B
	if (ctx.flags.pf) goto loc_2F7C0B;
	// 0x2F7C05: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F7C07: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
	// 0x2F7C09: fstp [ecx]
	X86_MEM_WRITE_F32(base, ctx.ecx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7C0B:
	// 0x2F7C0B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7C0C: ret 0x20
	ctx.esp += 32;
	return;
loc_2F7C0F:
	// 0x2F7C0F: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F7C11: fdiv st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] / ctx.fp_stack[1]);
	// 0x2F7C13: fmul [0x003B1770]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1770u));
	// 0x2F7C19: fsubr [0x003B1850]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x3B1850u) - ctx.fp_stack[ctx.fp_top]);
	// 0x2F7C1F: fstp [ecx]
	X86_MEM_WRITE_F32(base, ctx.ecx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7C21: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7C23: jmp 0x002F7BC5
	goto loc_2F7BC5;
}

void sub_2F7C25(X86Context& ctx, uint8_t* base) {
	// 0x2F7C25: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7C26: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7C28: cmp dword ptr [ebp+0x18], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x18u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7C2C: jz 0x002F7CC9
	if (ctx.flags.zf) goto loc_2F7CC9;
	// 0x2F7C32: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7C35: fmul [ebp+0x0C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x2F7C38: fld [ebp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x10u));
	// 0x2F7C3B: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x2F7C3D: fstp [ebp+0x18]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x18u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7C40: fld [0x003B1684]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x2F7C46: fld [0x003B168C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x2F7C4C: fld [ebp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x18u));
	// 0x2F7C4F: fmul [0x003B1EAC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1EACu));
	// 0x2F7C55: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x2F7C57: fadd st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] + ctx.fp_stack[1]);
	// 0x2F7C59: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x2F7C5B: fadd st0, st0
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] + ctx.fp_stack[0]);
	// 0x2F7C5D: fsub st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[2]);
	// 0x2F7C5F: fst [ebp+0x18]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x18u, ctx.fp_stack[ctx.fp_top]);
	// 0x2F7C62: fcomp st1
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[1]);
	X86_FPU_POP(ctx);
	// 0x2F7C64: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7C66: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x2F7C69: jnz 0x002F7C6F
	if (!ctx.flags.zf) goto loc_2F7C6F;
	// 0x2F7C6B: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2F7C6D: jmp 0x002F7C81
	goto loc_2F7C81;
loc_2F7C6F:
	// 0x2F7C6F: fld [ebp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x18u));
	// 0x2F7C72: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x2F7C78: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7C7A: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x2F7C7D: jp 0x002F7C84
	if (ctx.flags.pf) goto loc_2F7C84;
	// 0x2F7C7F: fldz
	X86_FPU_PUSH(ctx, 0.0);
loc_2F7C81:
	// 0x2F7C81: fstp [ebp+0x18]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x18u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7C84:
	// 0x2F7C84: fld st2
	X86_FPU_PUSH(ctx, ctx.fp_stack[2]);
	// 0x2F7C86: fcomp st2
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[2]);
	X86_FPU_POP(ctx);
	// 0x2F7C88: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7C8A: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x2F7C8D: jp 0x002F7C9D
	if (ctx.flags.pf) goto loc_2F7C9D;
	// 0x2F7C8F: fld [ebp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x18u));
	// 0x2F7C92: fsub st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[2]);
	// 0x2F7C94: fmul st0, st3
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[3]);
	// 0x2F7C96: fadd st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] + ctx.fp_stack[1]);
	// 0x2F7C98: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x2F7C9A: fstp [ebp+0x18]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x18u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F7C9D:
	// 0x2F7C9D: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7C9F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7CA0: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7CA2: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F7CA4: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2F7CA6: fsub [ebp+0x18]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.ebp + 0x18u));
	// 0x2F7CA9: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7CAC: call 0x002F7782
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7782(ctx, base);
	ctx.esp += 4;
	// 0x2F7CB1: mov ecx, [ebp+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x2F7CB4: fld [ebp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x18u));
	// 0x2F7CB7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7CB8: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7CBB: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F7CBD: call 0x002F7782
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7782(ctx, base);
	ctx.esp += 4;
	// 0x2F7CC2: mov ecx, [ebp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x20u);
	// 0x2F7CC5: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F7CC7: jmp 0x002F7CD8
	goto loc_2F7CD8;
loc_2F7CC9:
	// 0x2F7CC9: mov eax, [ebp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x2F7CCC: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2F7CCF: mov eax, [ebp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x20u);
	// 0x2F7CD2: mov dword ptr [eax], 0xFFFFD8F0
	X86_MEM_WRITE_u32(base, ctx.eax, -10000);
loc_2F7CD8:
	// 0x2F7CD8: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7CD9: ret 0x1C
	ctx.esp += 28;
	return;
}

void CLightHRTFSource_GetCenterVolume(X86Context& ctx, uint8_t* base) {
	// 0x2F7CDC: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7CDD: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7CDF: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7CE2: fcom [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x2F7CE8: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7CEA: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2F7CED: jz 0x002F7CF1
	if (ctx.flags.zf) goto loc_2F7CF1;
	// 0x2F7CEF: fchs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, -ctx.fp_stack[ctx.fp_top]);
loc_2F7CF1:
	// 0x2F7CF1: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7CF2: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7CF5: call 0x002FC98A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC98A(ctx, base);
	ctx.esp += 4;
	// 0x2F7CFA: cmp eax, 0x2D
	{ uint32_t _d = ctx.eax; uint32_t _s = 45;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7CFD: jnl 0x002F7D32
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2F7D32;
	// 0x2F7CFF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D00: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F7D02: shl esi, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x2F7D05: fld [esi+0x2FF158]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x2FF158u));
	// 0x2F7D0B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D0C: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7D0F: call 0x002F402B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F402B(ctx, base);
	ctx.esp += 4;
	// 0x2F7D14: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7D17: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2F7D19: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F7D1B: fsub [esi+0x2FF0A0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x2FF0A0u));
	// 0x2F7D21: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D22: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7D25: call 0x002F402B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F402B(ctx, base);
	ctx.esp += 4;
	// 0x2F7D2A: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F7D2D: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F7D2F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7D30: jmp 0x002F7D41
	goto loc_2F7D41;
loc_2F7D32:
	// 0x2F7D32: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F7D35: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2F7D38: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7D3B: mov dword ptr [eax], 0xFFFFD8F0
	X86_MEM_WRITE_u32(base, ctx.eax, -10000);
loc_2F7D41:
	// 0x2F7D41: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7D42: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F7D45(X86Context& ctx, uint8_t* base) {
	// 0x2F7D45: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D46: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7D48: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7D4B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D4C: fabs
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, fabs(ctx.fp_stack[ctx.fp_top]));
	// 0x2F7D4E: fadd [0x003B1870]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B1870u));
	// 0x2F7D54: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F7D57: call 0x002FC98A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FC98A(ctx, base);
	ctx.esp += 4;
	// 0x2F7D5C: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x2F7D5D: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D5F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7D60: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x2F7D62: cmp dword ptr [ebp+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7D66: lea ecx, [eax+eax*2]
	ctx.ecx = ctx.eax + ctx.eax * 2;
	// 0x2F7D69: mov eax, 0xB4
	ctx.eax = 180;
	// 0x2F7D6E: jz 0x002F7D7B
	if (ctx.flags.zf) goto loc_2F7D7B;
	// 0x2F7D70: cmp ecx, 0x5A
	{ uint32_t _d = ctx.ecx; uint32_t _s = 90;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7D73: jle 0x002F7D7B
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2F7D7B;
	// 0x2F7D75: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x2F7D77: sub edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F7D79: mov ecx, edx
	ctx.ecx = ctx.edx;
loc_2F7D7B:
	// 0x2F7D7B: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7D7D: jle 0x002F7D81
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2F7D81;
	// 0x2F7D7F: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F7D81:
	// 0x2F7D81: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7D83: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F7D86: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x2F7D87: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x2F7D8D: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7D8F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7D90: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x2F7D92: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7D94: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F7D96: shl ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F7D98: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F7D9B: lea edx, [ecx+0x2FF210]
	ctx.edx = ctx.ecx + 0x2FF210u;
	// 0x2F7DA1: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2F7DA4: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F7DA7: lea ecx, [ecx+0x2FF230]
	ctx.ecx = ctx.ecx + 0x2FF230u;
	// 0x2F7DAD: jnz 0x002F7DB6
	if (!ctx.flags.zf) goto loc_2F7DB6;
	// 0x2F7DAF: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2F7DB1: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2F7DB4: jmp 0x002F7DBB
	goto loc_2F7DBB;
loc_2F7DB6:
	// 0x2F7DB6: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x2F7DB9: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
loc_2F7DBB:
	// 0x2F7DBB: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7DBC: ret 0x10
	ctx.esp += 16;
	return;
}

void CHRTFSource_SetLightHRTF5Channel(X86Context& ctx, uint8_t* base) {
	// 0x2F7DBF: mov dword ptr [0x00300B4C], 0x2F7B03
	X86_MEM_WRITE_u32(base, 0x300B4Cu, 3111683);
	// 0x2F7DC9: mov dword ptr [0x00300B50], 0x2F7B3D
	X86_MEM_WRITE_u32(base, 0x300B50u, 3111741);
	// 0x2F7DD3: mov dword ptr [0x00300B54], 0x2F7808
	X86_MEM_WRITE_u32(base, 0x300B54u, 3110920);
	// 0x2F7DDD: mov dword ptr [0x00300B58], 0x2F789E
	X86_MEM_WRITE_u32(base, 0x300B58u, 3111070);
	// 0x2F7DE7: mov dword ptr [0x00300B5C], 0x2F78E9
	X86_MEM_WRITE_u32(base, 0x300B5Cu, 3111145);
	// 0x2F7DF1: mov dword ptr [0x00300B60], 0x2F79FA
	X86_MEM_WRITE_u32(base, 0x300B60u, 3111418);
	// 0x2F7DFB: mov dword ptr [0x00300B64], 0x2F7C25
	X86_MEM_WRITE_u32(base, 0x300B64u, 3111973);
	// 0x2F7E05: mov dword ptr [0x00300B68], 0x2F7CDC
	X86_MEM_WRITE_u32(base, 0x300B68u, 3112156);
	// 0x2F7E0F: mov dword ptr [0x00300B6C], 0x2F7A8A
	X86_MEM_WRITE_u32(base, 0x300B6Cu, 3111562);
	// 0x2F7E19: mov dword ptr [0x00300B70], 0x2F7D45
	X86_MEM_WRITE_u32(base, 0x300B70u, 3112261);
	// 0x2F7E23: mov dword ptr [0x00300B74], 0x04
	X86_MEM_WRITE_u32(base, 0x300B74u, 4);
	// 0x2F7E2D: ret
	return;
}

void sub_2F7E2E(X86Context& ctx, uint8_t* base) {
	// 0x2F7E2E: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F7E30: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F7E32: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2F7E35: mov [eax+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.ecx);
	// 0x2F7E38: mov dword ptr [eax+0x14], 0x1000
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, 4096);
	// 0x2F7E3F: mov [eax+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.ecx);
	// 0x2F7E42: mov dword ptr [eax+0x18], 0x8000
	X86_MEM_WRITE_u32(base, ctx.eax + 0x18u, 32768);
	// 0x2F7E49: mov [eax+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1Cu, ctx.ecx);
	// 0x2F7E4C: ret
	return;
}

void sub_2F7E4D(X86Context& ctx, uint8_t* base) {
	// 0x2F7E4D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E4E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E4F: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E51: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E53: mov edi, 0x626F5344
	ctx.edi = 1651462980;
	// 0x2F7E58: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E59: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F7E5B: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F7E60: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7E62: jz 0x002F7E6D
	if (ctx.flags.zf) goto loc_2F7E6D;
	// 0x2F7E64: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2F7E67: and dword ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, X86_MEM_READ_u32(base, ctx.eax + 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x4u), 32);
	// 0x2F7E6B: jmp 0x002F7E6F
	goto loc_2F7E6F;
loc_2F7E6D:
	// 0x2F7E6D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F7E6F:
	// 0x2F7E6F: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E71: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E73: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x2F7E76: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E77: mov dword ptr [eax], 0x3004C8
	X86_MEM_WRITE_u32(base, ctx.eax, 3146952);
	// 0x2F7E7D: mov dword ptr [eax+0x04], 0x5CC
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 1484);
	// 0x2F7E84: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F7E89: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7E8B: jz 0x002F7E98
	if (ctx.flags.zf) goto loc_2F7E98;
	// 0x2F7E8D: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E8F: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7E91: call 0x002FD458
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD458(ctx, base);
	ctx.esp += 4;
	// 0x2F7E96: jmp 0x002F7E9A
	goto loc_2F7E9A;
loc_2F7E98:
	// 0x2F7E98: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F7E9A:
	// 0x2F7E9A: push 0x204
	{ auto _pv = (uint32_t)(516); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7E9F: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F7EA1: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x2F7EA4: call 0x002FD4A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD4A0(ctx, base);
	ctx.esp += 4;
	// 0x2F7EA9: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F7EAC: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F7EAE: jz 0x002F7EBF
	if (ctx.flags.zf) goto loc_2F7EBF;
	// 0x2F7EB0: mov esi, [esi+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F7EB3: push [esi+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7EB6: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7EB8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7EBA: call 0x002FD5A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD5A5(ctx, base);
	ctx.esp += 4;
loc_2F7EBF:
	// 0x2F7EBF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7EC0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F7EC1: ret
	return;
}

void sub_2F7EC2(X86Context& ctx, uint8_t* base) {
	// 0x2F7EC2: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7EC3: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F7EC5: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F7EC8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7EC9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7ECA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7ECB: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F7ECD: mov eax, [edi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x2F7ED0: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F7ED3: mov ebx, [eax]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F7ED5: mov eax, [ebx+0x80C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x80Cu);
	// 0x2F7EDB: add eax, [ebx+0x804]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0x804u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebx + 0x804u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7EE1: mov ecx, [edi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x20u);
	// 0x2F7EE4: lea esi, [ebx+eax*4+0x818]
	ctx.esi = ctx.ebx + ctx.eax * 4 + 0x818u;
	// 0x2F7EEB: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F7EED: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7EEE: shl eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F7EF1: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7EF4: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F7EF6: mov [ebp-0x14], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.edi);
	// 0x2F7EF9: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x2F7EFC: jz 0x002F7F0B
	if (ctx.flags.zf) goto loc_2F7F0B;
	// 0x2F7EFE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7EFF: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F7F04: and dword ptr [edi+0x20], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi + 0x20u, X86_MEM_READ_u32(base, ctx.edi + 0x20u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi + 0x20u), 32);
	// 0x2F7F08: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
loc_2F7F0B:
	// 0x2F7F0B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F0D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F0E: push 0x626F5344
	{ auto _pv = (uint32_t)(1651462980); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F13: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F7F18: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7F1A: mov [edi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x20u, ctx.eax);
	// 0x2F7F1D: jnz 0x002F7F29
	if (!ctx.flags.zf) goto loc_2F7F29;
	// 0x2F7F1F: mov eax, 0x8007000E
	ctx.eax = -2147024882;
	// 0x2F7F24: jmp 0x002F8030
	goto loc_2F8030;
loc_2F7F29:
	// 0x2F7F29: push [esi+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F2C: mov ecx, [edi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x2F7F2F: call 0x002FD5CD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD5CD(ctx, base);
	ctx.esp += 4;
	// 0x2F7F34: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7F36: jl 0x002F8030
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8030;
	// 0x2F7F3C: lea eax, [ebx+0x818]
	ctx.eax = ctx.ebx + 0x818u;
	// 0x2F7F42: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F7F45: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2F7F48: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7F4A: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F7F4D: lea eax, [ebp-0x1C]
	ctx.eax = ctx.ebp - 0x1Cu;
	// 0x2F7F50: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F51: call 0x002FD71E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD71E(ctx, base);
	ctx.esp += 4;
	// 0x2F7F56: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F7F58: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F5A: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F5D: shl eax, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F7F60: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F61: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F64: lea eax, [ebp-0x1C]
	ctx.eax = ctx.ebp - 0x1Cu;
	// 0x2F7F67: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F68: call 0x002FD74B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD74B(ctx, base);
	ctx.esp += 4;
	// 0x2F7F6D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7F6F: jle 0x002F7F7D
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2F7F7D;
	// 0x2F7F71: and eax, 0xFFFF
	ctx.eax = ctx.eax & 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F7F76: or eax, 0x80070000
	ctx.eax = ctx.eax | -2147024896;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F7F7B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
loc_2F7F7D:
	// 0x2F7F7D: jl 0x002F8030
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8030;
	// 0x2F7F83: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2F7F87: cmp dword ptr [esi], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F7F8A: jbe 0x002F800B
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F800B;
	// 0x2F7F8C: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F7F8F: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F7F92: lea edi, [esi+0x08]
	ctx.edi = ctx.esi + 0x8u;
loc_2F7F95:
	// 0x2F7F95: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F97: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F9A: push [edi+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7F9D: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7FA0: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F7FA3: call 0x002FD74B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD74B(ctx, base);
	ctx.esp += 4;
	// 0x2F7FA8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F7FAA: jle 0x002F7FB8
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2F7FB8;
	// 0x2F7FAC: and eax, 0xFFFF
	ctx.eax = ctx.eax & 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F7FB1: or eax, 0x80070000
	ctx.eax = ctx.eax | -2147024896;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F7FB6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
loc_2F7FB8:
	// 0x2F7FB8: jl 0x002F8030
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8030;
	// 0x2F7FBA: mov eax, [edi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x2F7FBD: add [ebp-0x04], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x4u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F7FC0: mov eax, [ebp-0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x2F7FC3: mov ecx, [eax+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x2F7FC6: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F7FC9: add dword ptr [edi+0x10], 0xFE836000
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x10u)) + (uint64_t)(uint32_t)(-24944640);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edi + 0x10u), (int32_t)-24944640, 32);
	  X86_MEM_WRITE_u32(base, ctx.edi + 0x10u, (uint32_t)_res); }
	// 0x2F7FD0: add dword ptr [ebp-0x08], 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), (int32_t)8, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2F7FD4: sub ecx, 0x17C6818
	{ uint32_t _d = ctx.ecx; uint32_t _s = 24930328;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7FDA: add [edi], ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi)) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edi), (int32_t)ctx.ecx, 32);
	  X86_MEM_WRITE_u32(base, ctx.edi, (uint32_t)_res); }
	// 0x2F7FDC: mov ecx, 0xFFA0BE7A
	ctx.ecx = -6242694;
	// 0x2F7FE1: sub ecx, [ebx+0x804]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebx + 0x804u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F7FE7: add edi, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)32, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F7FEA: shl ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F7FED: add [edi-0x18], ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi - 0x18u)) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edi - 0x18u), (int32_t)ctx.ecx, 32);
	  X86_MEM_WRITE_u32(base, ctx.edi - 0x18u, (uint32_t)_res); }
	// 0x2F7FF0: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F7FF3: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x2F7FF6: sub eax, 0xC000
	{ uint32_t _d = ctx.eax; uint32_t _s = 49152;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F7FFB: add [edi-0x08], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi - 0x8u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edi - 0x8u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.edi - 0x8u, (uint32_t)_res); }
	// 0x2F7FFE: inc [ebp-0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x2F8001: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2F8004: cmp eax, [esi]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8006: jb 0x002F7F95
	if (ctx.flags.cf) goto loc_2F7F95;
	// 0x2F8008: mov edi, [ebp-0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
loc_2F800B:
	// 0x2F800B: mov ecx, [ebp-0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2F800E: mov edi, [edi+0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi + 0x20u);
	// 0x2F8011: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F8013: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F8016: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F8018: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F801A: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F801C: pop eax
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F801D: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F801F: add ebx, 0x810
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(2064);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)2064, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8025: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x2F8027: mov [ebx], eax
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.eax);
loc_2F8029:
	// 0x2F8029: cmp dword ptr [ebx], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F802C: jnz 0x002F8029
	if (!ctx.flags.zf) goto loc_2F8029;
	// 0x2F802E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F8030:
	// 0x2F8030: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8031: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8032: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8033: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8034: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8037(X86Context& ctx, uint8_t* base) {
	// 0x2F8037: mov eax, [ecx+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x2F803A: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F803C: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F8040: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F8041: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8043: jbe 0x002F804C
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F804C;
	// 0x2F8045: mov eax, 0x88780032
	ctx.eax = -2005401550;
	// 0x2F804A: jmp 0x002F805B
	goto loc_2F805B;
loc_2F804C:
	// 0x2F804C: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F804F: lea eax, [ecx+eax*1+0x08]
	ctx.eax = ctx.ecx + ctx.eax + 0x8u;
	// 0x2F8053: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F8057: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F8059: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F805B:
	// 0x2F805B: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F805E(X86Context& ctx, uint8_t* base) {
	// 0x2F805E: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F8062: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F8064: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8065: jnz 0x002F807B
	if (!ctx.flags.zf) goto loc_2F807B;
	// 0x2F8067: mov esi, [ecx+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x2F806A: cmp esi, 0x8000
	{ uint32_t _d = ctx.esi; uint32_t _s = 32768;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8070: mov edx, [ecx+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x2F8073: jz 0x002F80BF
	if (ctx.flags.zf) goto loc_2F80BF;
	// 0x2F8075: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F8077: jz 0x002F80BF
	if (ctx.flags.zf) goto loc_2F80BF;
	// 0x2F8079: jmp 0x002F807F
	goto loc_2F807F;
loc_2F807B:
	// 0x2F807B: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
loc_2F807F:
	// 0x2F807F: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F8082: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F8085: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F8087: add eax, 0x800
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(2048);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)2048, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2F808C:
	// 0x2F808C: cmp dword ptr [eax+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8090: jnz 0x002F808C
	if (!ctx.flags.zf) goto loc_2F808C;
	// 0x2F8092: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8093: mov ebx, esi
	ctx.ebx = ctx.esi;
	// 0x2F8095: shr ebx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)(ctx.ebx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x2F8098: sub ebx, [eax+0x04]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F809B: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2F809E: sub ebx, 0x206
	{ uint32_t _d = ctx.ebx; uint32_t _s = 518;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F80A4: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x2F80A6: mov [eax+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.esi);
	// 0x2F80A9: mov [eax+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.edx);
	// 0x2F80AC: mov dword ptr [eax+0x10], 0x02
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, 2);
	// 0x2F80B3: and dword ptr [ecx+0x1C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x1Cu, X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu), 32);
	// 0x2F80B7: mov dword ptr [ecx+0x18], 0x8000
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x18u, 32768);
	// 0x2F80BE: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F80BF:
	// 0x2F80BF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F80C0: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F80C3(X86Context& ctx, uint8_t* base) {
	// 0x2F80C3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80C4: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80C8: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F80CB: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80CF: call 0x002FD553
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD553(ctx, base);
	ctx.esp += 4;
	// 0x2F80D4: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F80D7(X86Context& ctx, uint8_t* base) {
	// 0x2F80D7: lea eax, [ecx+0x04]
	ctx.eax = ctx.ecx + 0x4u;
	// 0x2F80DA: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F80DD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80DE: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80E2: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80E6: call 0x002FD553
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD553(ctx, base);
	ctx.esp += 4;
	// 0x2F80EB: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F80EE(X86Context& ctx, uint8_t* base) {
	// 0x2F80EE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80EF: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F80F1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F80F2: mov edi, [esi+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F80F5: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F80F7: jz 0x002F810A
	if (ctx.flags.zf) goto loc_2F810A;
	// 0x2F80F9: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F80FB: call 0x002FD472
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD472(ctx, base);
	ctx.esp += 4;
	// 0x2F8100: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8101: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F8106: and dword ptr [esi+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
loc_2F810A:
	// 0x2F810A: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F810D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F810F: jz 0x002F811B
	if (ctx.flags.zf) goto loc_2F811B;
	// 0x2F8111: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8112: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F8117: and dword ptr [esi+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
loc_2F811B:
	// 0x2F811B: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2F811E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8120: jz 0x002F812C
	if (ctx.flags.zf) goto loc_2F812C;
	// 0x2F8122: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8123: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F8128: and dword ptr [esi+0x20], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, X86_MEM_READ_u32(base, ctx.esi + 0x20u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x20u), 32);
loc_2F812C:
	// 0x2F812C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F812D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F812E: ret
	return;
}

void sub_2F812F(X86Context& ctx, uint8_t* base) {
	// 0x2F812F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8130: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8132: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8133: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8134: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8135: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8136: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x2F8138: mov [ebp-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edx);
	// 0x2F813B: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F813E: mov eax, [edx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x2F8141: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F8144: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F8146: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8148: add esi, 0x800
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(2048);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)2048, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F814E: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8150: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8151: mov edi, esi
	ctx.edi = ctx.esi;
	// 0x2F8153: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F8155: mov eax, [ebx+0x800]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x800u);
	// 0x2F815B: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x2F815D: mov eax, [ebx+0x804]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x804u);
	// 0x2F8163: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x2F8166: mov eax, [ebx+0x808]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x808u);
	// 0x2F816C: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x2F816F: mov eax, [ebx+0x80C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x80Cu);
	// 0x2F8175: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x2F8178: mov eax, [ebx+0x814]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x814u);
	// 0x2F817E: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x2F8181: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F8184: mov ecx, [edx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x2F8187: add eax, 0xFFFFF7E8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-2072);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-2072, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F818C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F818D: lea eax, [ebx+0x818]
	ctx.eax = ctx.ebx + 0x818u;
	// 0x2F8193: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8194: push 0x818
	{ auto _pv = (uint32_t)(2072); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8199: call 0x002FD5A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD5A5(ctx, base);
	ctx.esp += 4;
	// 0x2F819E: mov edi, [ebp-0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F81A1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81A2: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F81A4: call 0x002F7EC2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7EC2(ctx, base);
	ctx.esp += 4;
	// 0x2F81A9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F81AB: jl 0x002F81C1
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F81C1;
	// 0x2F81AD: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F81B0: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F81B2: jz 0x002F81B9
	if (ctx.flags.zf) goto loc_2F81B9;
	// 0x2F81B4: mov edx, [edi+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x20u);
	// 0x2F81B7: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_2F81B9:
	// 0x2F81B9: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81BB: add edi, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)36, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F81BE: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F81BF: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
loc_2F81C1:
	// 0x2F81C1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F81C2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F81C3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F81C4: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F81C5: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F81C8(X86Context& ctx, uint8_t* base) {
	// 0x2F81C8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81C9: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F81CB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81CC: lea eax, [ebp+0x08]
	ctx.eax = ctx.ebp + 0x8u;
	// 0x2F81CF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81D0: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81D3: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F81D5: call 0x002F8037
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8037(ctx, base);
	ctx.esp += 4;
	// 0x2F81DA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F81DC: jl 0x002F826C
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F826C;
	// 0x2F81E2: mov ecx, [edi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x2F81E5: mov eax, [ecx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x2F81E8: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F81EA: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F81ED: mov eax, [eax+0x804]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x804u);
	// 0x2F81F3: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x2F81F6: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81F7: mov ebx, [ebp+0x14]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F81FA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81FB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81FC: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F81FF: lea esi, [edx+eax*4+0x17D0618]
	ctx.esi = ctx.edx + ctx.eax * 4 + 0x17D0618u;
	// 0x2F8206: add esi, [ebp+0x0C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0xCu), 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F8209: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F820A: call 0x002FD5A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FD5A5(ctx, base);
	ctx.esp += 4;
	// 0x2F820F: test byte ptr [ebp+0x18], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x18u) & 1, 8);
	// 0x2F8213: jz 0x002F824C
	if (ctx.flags.zf) goto loc_2F824C;
	// 0x2F8215: mov eax, [edi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x2F8218: cmp eax, 0x8000
	{ uint32_t _d = ctx.eax; uint32_t _s = 32768;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F821D: jz 0x002F823E
	if (ctx.flags.zf) goto loc_2F823E;
	// 0x2F821F: mov ecx, [edi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x1Cu);
	// 0x2F8222: lea edx, [ecx+eax*1]
	ctx.edx = ctx.ecx + ctx.eax;
	// 0x2F8225: cmp edx, esi
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8227: jnb 0x002F8233
	if (!ctx.flags.cf) goto loc_2F8233;
	// 0x2F8229: mov edx, esi
	ctx.edx = ctx.esi;
	// 0x2F822B: sub edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F822D: sub edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F822F: add ebx, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)ctx.edx, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8231: jmp 0x002F823E
	goto loc_2F823E;
loc_2F8233:
	// 0x2F8233: lea ecx, [esi+ebx*1]
	ctx.ecx = ctx.esi + ctx.ebx;
	// 0x2F8236: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8238: jbe 0x002F823E
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F823E;
	// 0x2F823A: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2F823C: sub ebx, esi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
loc_2F823E:
	// 0x2F823E: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8240: jb 0x002F8244
	if (ctx.flags.cf) goto loc_2F8244;
	// 0x2F8242: mov eax, esi
	ctx.eax = ctx.esi;
loc_2F8244:
	// 0x2F8244: add [edi+0x1C], ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x1Cu)) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.edi + 0x1Cu), (int32_t)ctx.ebx, 32);
	  X86_MEM_WRITE_u32(base, ctx.edi + 0x1Cu, (uint32_t)_res); }
	// 0x2F8247: mov [edi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x18u, ctx.eax);
	// 0x2F824A: jmp 0x002F8268
	goto loc_2F8268;
loc_2F824C:
	// 0x2F824C: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F824F: mov edi, [eax+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F8252: add edi, [ebp+0x0C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0xCu), 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F8255: mov esi, [ebp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F8258: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2F825A: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F825C: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F825F: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F8261: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F8263: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F8266: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
loc_2F8268:
	// 0x2F8268: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8269: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F826B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F826C:
	// 0x2F826C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F826D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F826E: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_2F8271(X86Context& ctx, uint8_t* base) {
	// 0x2F8271: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8272: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8274: lea eax, [ebp+0x08]
	ctx.eax = ctx.ebp + 0x8u;
	// 0x2F8277: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8278: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F827B: call 0x002F8037
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8037(ctx, base);
	ctx.esp += 4;
	// 0x2F8280: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8282: jl 0x002F82A7
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F82A7;
	// 0x2F8284: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8287: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x2F828A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F828B: mov esi, [eax+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F828E: add esi, [ebp+0x0C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0xCu), 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F8291: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F8293: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8294: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2F8297: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F829A: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F829C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2F829E: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F82A1: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x2F82A3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F82A4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F82A6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F82A7:
	// 0x2F82A7: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F82A8: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F82AB(X86Context& ctx, uint8_t* base) {
	// 0x2F82AB: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F82AF: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F82B1: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F82B4: mov [ecx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.edx);
	// 0x2F82B7: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F82BA: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F82BC: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x2F82BE: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F82C2: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F82C4: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F82C7: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x2F82CA: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2F82CD: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F82D0: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F82D2: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F82D5(X86Context& ctx, uint8_t* base) {
	// 0x2F82D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F82D6: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F82D8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F82D9: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F82DD: lea edi, [esi+0x08]
	ctx.edi = ctx.esi + 0x8u;
	// 0x2F82E0: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F82E2: mov dword ptr [esi], 0x36C17C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588476);
	// 0x2F82E8: mov dword ptr [esi+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 1);
	// 0x2F82EF: call 0x002FDF4D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDF4D(ctx, base);
	ctx.esp += 4;
	// 0x2F82F4: lea ecx, [esi+0x60]
	ctx.ecx = ctx.esi + 0x60u;
	// 0x2F82F7: mov dword ptr [esi], 0x36C20C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588620);
	// 0x2F82FD: mov dword ptr [edi], 0x36C208
	X86_MEM_WRITE_u32(base, ctx.edi, 3588616);
	// 0x2F8303: mov dword ptr [esi+0x58], 0x300484
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, 3146884);
	// 0x2F830A: mov dword ptr [esi+0x5C], 0x300488
	X86_MEM_WRITE_u32(base, ctx.esi + 0x5Cu, 3146888);
	// 0x2F8311: call 0x002F9E64
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E64(ctx, base);
	ctx.esp += 4;
	// 0x2F8316: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8318: lea eax, [esi+0x488]
	ctx.eax = ctx.esi + 0x488u;
	// 0x2F831E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F831F:
	// 0x2F831F: mov [eax+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.eax);
	// 0x2F8322: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F8324: add eax, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F8327: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F8328: jnz 0x002F831F
	if (!ctx.flags.zf) goto loc_2F831F;
	// 0x2F832A: lea eax, [esi+0x4A0]
	ctx.eax = ctx.esi + 0x4A0u;
	// 0x2F8330: mov [esi+0x4A4], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4A4u, ctx.eax);
	// 0x2F8336: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F8338: lea eax, [esi+0x4A8]
	ctx.eax = ctx.esi + 0x4A8u;
	// 0x2F833E: mov [esi+0x4AC], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4ACu, ctx.eax);
	// 0x2F8344: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F8346: lea eax, [esi+0x4B0]
	ctx.eax = ctx.esi + 0x4B0u;
	// 0x2F834C: mov [esi+0x4B4], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4B4u, ctx.eax);
	// 0x2F8352: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F8354: mov eax, [esi+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
	// 0x2F8357: mov dword ptr [eax], 0xC0
	X86_MEM_WRITE_u32(base, ctx.eax, 192);
	// 0x2F835D: mov eax, [esi+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	// 0x2F8360: mov dword ptr [eax], 0x40
	X86_MEM_WRITE_u32(base, ctx.eax, 64);
	// 0x2F8366: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8367: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F8369: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F836A: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F836D(X86Context& ctx, uint8_t* base) {
	// 0x2F836D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F836E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8370: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F8373: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x2F8377: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8378: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8379: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F837B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F837C: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2F837F: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F8384: add dword ptr [esi+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F838B: lea ebx, [esi+0x488]
	ctx.ebx = ctx.esi + 0x488u;
	// 0x2F8391: mov dword ptr [ebp-0x04], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 3);
loc_2F8398:
	// 0x2F8398: mov edi, [ebx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F839A: jmp 0x002F83A8
	goto loc_2F83A8;
loc_2F839C:
	// 0x2F839C: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F839E: lea ecx, [edi-0x4C]
	ctx.ecx = ctx.edi - 0x4Cu;
	// 0x2F83A1: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
	// 0x2F83A6: mov edi, [edi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi);
loc_2F83A8:
	// 0x2F83A8: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F83AA: jnz 0x002F839C
	if (!ctx.flags.zf) goto loc_2F839C;
	// 0x2F83AC: add ebx, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)8, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F83AF: dec [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F83B2: jnz 0x002F8398
	if (!ctx.flags.zf) goto loc_2F8398;
	// 0x2F83B4: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F83BB: lea ecx, [esi+0x08]
	ctx.ecx = ctx.esi + 0x8u;
	// 0x2F83BE: call 0x002FE35A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE35A(ctx, base);
	ctx.esp += 4;
	// 0x2F83C3: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2F83C6: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F83CB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F83CC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F83CD: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F83CE: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F83CF: ret
	return;
}

void sub_2F83D0(X86Context& ctx, uint8_t* base) {
	// 0x2F83D0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F83D1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F83D3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F83D4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F83D5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F83D6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F83D7: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F83D9: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F83DB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F83DC: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F83DF: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x2F83E2: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F83E7: add dword ptr [esi+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F83EE: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F83F1: mov eax, [ecx+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2F83F4: test dword ptr [eax+0x08], 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 2097168, 32);
	// 0x2F83FB: jz 0x002F8402
	if (ctx.flags.zf) goto loc_2F8402;
	// 0x2F83FD: mov edx, [esi+0x5C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	// 0x2F8400: jmp 0x002F8408
	goto loc_2F8408;
loc_2F8402:
	// 0x2F8402: mov edx, [esi+0x58]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
	// 0x2F8405: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8407: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F8408:
	// 0x2F8408: movzx edi, byte ptr [ecx+0x64]
	ctx.edi = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0x64u));
	// 0x2F840C: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2F840E: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8410: jnbe 0x002F8444
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_2F8444;
	// 0x2F8412: sub eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F8414: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x2F8416: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x2F8418: cmp [ecx+0x64], dl
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ecx + 0x64u); uint8_t _s = X86_REG8L(ctx.edx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F841B: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x2F841D: jbe 0x002F8440
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F8440;
loc_2F841F:
	// 0x2F841F: movzx eax, di
	ctx.eax = (uint32_t)(X86_REG16(ctx.edi));
	// 0x2F8422: lea eax, [esi+eax*4+0x88]
	ctx.eax = ctx.esi + ctx.eax * 4 + 0x88u;
	// 0x2F8429: cmp dword ptr [eax], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F842C: jnz 0x002F843A
	if (!ctx.flags.zf) goto loc_2F843A;
	// 0x2F842E: movzx ebx, dl
	ctx.ebx = (uint32_t)(X86_REG8L(ctx.edx));
	// 0x2F8431: mov [ecx+ebx*2+0x0C], di
	X86_MEM_WRITE_u16(base, ctx.ecx + ctx.ebx * 2 + 0xCu, X86_REG16(ctx.edi));
	// 0x2F8436: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F8438: inc dl
	{ uint8_t _d = X86_REG8L(ctx.edx);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.edx) = (uint8_t)_res; }
loc_2F843A:
	// 0x2F843A: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F843B: cmp dl, [ecx+0x64]
	{ uint8_t _d = X86_REG8L(ctx.edx); uint8_t _s = X86_MEM_READ_u8(base, ctx.ecx + 0x64u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F843E: jb 0x002F841F
	if (ctx.flags.cf) goto loc_2F841F;
loc_2F8440:
	// 0x2F8440: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8442: jmp 0x002F8449
	goto loc_2F8449;
loc_2F8444:
	// 0x2F8444: mov edi, 0x88780032
	ctx.edi = -2005401550;
loc_2F8449:
	// 0x2F8449: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F8450: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8453: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F8458: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F845A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F845B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F845C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F845D: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F845E: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8461(X86Context& ctx, uint8_t* base) {
	// 0x2F8461: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8462: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8464: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8465: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8466: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F846A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F846B: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F846D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F846E: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8471: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F8476: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8479: add dword ptr [esi+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F8480: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8482: cmp byte ptr [edx+0x64], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.edx + 0x64u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F8486: jbe 0x002F84B9
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F84B9;
loc_2F8488:
	// 0x2F8488: movzx eax, di
	ctx.eax = (uint32_t)(X86_REG16(ctx.edi));
	// 0x2F848B: lea eax, [edx+eax*2+0x0C]
	ctx.eax = ctx.edx + ctx.eax * 2 + 0xCu;
	// 0x2F848F: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2F8492: or word ptr [eax], 0xFFFF
	X86_MEM_WRITE_u16(base, ctx.eax, X86_MEM_READ_u16(base, ctx.eax) | -1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.eax), 16);
	// 0x2F8497: and dword ptr [esi+ecx*4+0x88], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + ctx.ecx * 4 + 0x88u, X86_MEM_READ_u32(base, ctx.esi + ctx.ecx * 4 + 0x88u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + ctx.ecx * 4 + 0x88u), 32);
	// 0x2F849F: cmp ecx, 0x40
	{ uint32_t _d = ctx.ecx; uint32_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F84A2: jnb 0x002F84A9
	if (!ctx.flags.cf) goto loc_2F84A9;
	// 0x2F84A4: mov eax, [esi+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	// 0x2F84A7: jmp 0x002F84AC
	goto loc_2F84AC;
loc_2F84A9:
	// 0x2F84A9: mov eax, [esi+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
loc_2F84AC:
	// 0x2F84AC: inc [eax]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x2F84AE: movzx ax, byte ptr [edx+0x64]
	X86_REG16(ctx.eax) = (uint16_t)(X86_MEM_READ_u8(base, ctx.edx + 0x64u));
	// 0x2F84B3: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F84B4: cmp di, ax
	{ uint16_t _d = X86_REG16(ctx.edi); uint16_t _s = X86_REG16(ctx.eax);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F84B7: jb 0x002F8488
	if (ctx.flags.cf) goto loc_2F8488;
loc_2F84B9:
	// 0x2F84B9: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F84C0: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F84C3: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F84C8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F84C9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F84CA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F84CB: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F84CE(X86Context& ctx, uint8_t* base) {
	// 0x2F84CE: mov eax, [0x00300A94]
	ctx.eax = X86_MEM_READ_u32(base, 0x300A94u);
	// 0x2F84D3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F84D4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F84D5: mov esi, [0x00300C18]
	ctx.esi = X86_MEM_READ_u32(base, 0x300C18u);
	// 0x2F84DB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F84DC: push 0x64
	{ auto _pv = (uint32_t)(100); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F84DE: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F84DF: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F84E0: mov [0x00300A94], eax
	X86_MEM_WRITE_u32(base, 0x300A94u, ctx.eax);
	// 0x2F84E5: lea edi, [ecx+0x08]
	ctx.edi = ctx.ecx + 0x8u;
	// 0x2F84E8: not eax
	ctx.eax = ~ctx.eax;
	// 0x2F84EA: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x2F84EC: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F84EE: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F84F0: call 0x002FDCC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDCC0(ctx, base);
	ctx.esp += 4;
	// 0x2F84F5: mov eax, [0x00300C1C]
	ctx.eax = X86_MEM_READ_u32(base, 0x300C1Cu);
	// 0x2F84FA: mov [0xFE801324], eax
	X86_MEM_WRITE_u32(base, 0xFE801324u, ctx.eax);
	// 0x2F84FF: mov eax, [0x00300A94]
	ctx.eax = X86_MEM_READ_u32(base, 0x300A94u);
	// 0x2F8504: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8506: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F8508: mov [0xFE801334], eax
	X86_MEM_WRITE_u32(base, 0xFE801334u, ctx.eax);
	// 0x2F850D: call 0x002FDCC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDCC0(ctx, base);
	ctx.esp += 4;
	// 0x2F8512: jmp 0x002F8523
	goto loc_2F8523;
loc_2F8514:
	// 0x2F8514: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F8516: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8517: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8519: jz 0x002F852D
	if (ctx.flags.zf) goto loc_2F852D;
	// 0x2F851B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F851D: call [0x0036B93C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B93Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F8523:
	// 0x2F8523: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F8525: cmp eax, [0x00300A94]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, 0x300A94u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F852B: jnz 0x002F8514
	if (!ctx.flags.zf) goto loc_2F8514;
loc_2F852D:
	// 0x2F852D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F852E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F852F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8530: ret
	return;
}

void sub_2F8531(X86Context& ctx, uint8_t* base) {
	// 0x2F8531: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8532: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8534: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8535: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8536: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8537: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8538: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F853A: call 0x002F84CE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F84CE(ctx, base);
	ctx.esp += 4;
	// 0x2F853F: lea ebx, [esi+0x488]
	ctx.ebx = ctx.esi + 0x488u;
	// 0x2F8545: mov dword ptr [ebp-0x04], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 3);
loc_2F854C:
	// 0x2F854C: mov edi, [ebx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F854E: jmp 0x002F8570
	goto loc_2F8570;
loc_2F8550:
	// 0x2F8550: lea ecx, [edi-0x4C]
	ctx.ecx = ctx.edi - 0x4Cu;
	// 0x2F8553: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F8555: call [eax+0x18]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8558: add dword ptr [esi+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F855F: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F8561: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8563: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F8565: jnz 0x002F8569
	if (!ctx.flags.zf) goto loc_2F8569;
	// 0x2F8567: mov edi, [ebx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx);
loc_2F8569:
	// 0x2F8569: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
loc_2F8570:
	// 0x2F8570: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8572: jnz 0x002F8550
	if (!ctx.flags.zf) goto loc_2F8550;
	// 0x2F8574: add ebx, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)8, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8577: dec [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F857A: jnz 0x002F854C
	if (!ctx.flags.zf) goto loc_2F854C;
	// 0x2F857C: lea edi, [esi+0x4A0]
	ctx.edi = ctx.esi + 0x4A0u;
loc_2F8582:
	// 0x2F8582: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8584: add dword ptr [esi+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F858B: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F8590: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F8597: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8599: jz 0x002F85A5
	if (ctx.flags.zf) goto loc_2F85A5;
	// 0x2F859B: lea ecx, [eax-0x54]
	ctx.ecx = ctx.eax - 0x54u;
	// 0x2F859E: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F85A0: call [eax+0x18]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F85A3: jmp 0x002F8582
	goto loc_2F8582;
loc_2F85A5:
	// 0x2F85A5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F85A6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F85A7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F85A8: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F85A9: ret
	return;
}

void sub_2F85AA(X86Context& ctx, uint8_t* base) {
	// 0x2F85AA: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F85AB: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F85AD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F85AE: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F85B1: lea eax, [esi+0x4B8]
	ctx.eax = ctx.esi + 0x4B8u;
	// 0x2F85B7: mov [ebp+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.eax);
	// 0x2F85BA: mov edx, 0x00
	ctx.edx = 0;
	// 0x2F85BF: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F85C2: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
loc_2F85C4:
	// 0x2F85C4: cmpxchg [ecx], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx);
	  if ((uint32_t)(ctx.eax) == _d) {
	    ctx.flags.zf = 1;
	    X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	  } else {
	    ctx.flags.zf = 0;
	    ctx.eax = _d;
	  } }
	// 0x2F85C7: jnz 0x002F85C4
	if (!ctx.flags.zf) goto loc_2F85C4;
	// 0x2F85C9: or [esi+0x4C0], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4C0u, X86_MEM_READ_u32(base, ctx.esi + 0x4C0u) | ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x4C0u), 32);
	// 0x2F85CF: mov al, 0x01
	X86_REG8L(ctx.eax) = (uint8_t)(1);
	// 0x2F85D1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F85D2: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F85D3: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F85D6(X86Context& ctx, uint8_t* base) {
	// 0x2F85D6: inc [0x00300490]
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x300490u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, 0x300490u, (uint32_t)_res); }
	// 0x2F85DC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F85DD: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F85DF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F85E0: lea edi, [esi+0x08]
	ctx.edi = ctx.esi + 0x8u;
	// 0x2F85E3: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F85E5: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F85E7: call 0x002FDD52
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDD52(ctx, base);
	ctx.esp += 4;
	// 0x2F85EC: mov ecx, [esi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F85EF: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F85F1: jz 0x002F85F8
	if (ctx.flags.zf) goto loc_2F85F8;
	// 0x2F85F3: call 0x002FE736
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE736(ctx, base);
	ctx.esp += 4;
loc_2F85F8:
	// 0x2F85F8: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2F85FB: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F85FD: jz 0x002F8604
	if (ctx.flags.zf) goto loc_2F8604;
	// 0x2F85FF: call 0x002FE736
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE736(ctx, base);
	ctx.esp += 4;
loc_2F8604:
	// 0x2F8604: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F8606: call 0x002FDEA7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDEA7(ctx, base);
	ctx.esp += 4;
	// 0x2F860B: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F860D: mov dword ptr [0xFE85FFFC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE85FFFCu, 1);
	// 0x2F8617: call 0x002FDA2C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDA2C(ctx, base);
	ctx.esp += 4;
	// 0x2F861C: mov ecx, [esi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F861F: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F8621: jz 0x002F862A
	if (ctx.flags.zf) goto loc_2F862A;
	// 0x2F8623: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8625: call 0x002FE7F6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE7F6(ctx, base);
	ctx.esp += 4;
loc_2F862A:
	// 0x2F862A: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2F862D: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F862F: jz 0x002F8638
	if (ctx.flags.zf) goto loc_2F8638;
	// 0x2F8631: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8633: call 0x002FE7F6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE7F6(ctx, base);
	ctx.esp += 4;
loc_2F8638:
	// 0x2F8638: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F863A: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F863C: call 0x002FDD52
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDD52(ctx, base);
	ctx.esp += 4;
	// 0x2F8641: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8642: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8643: ret
	return;
}

void sub_2F8644(X86Context& ctx, uint8_t* base) {
	// 0x2F8644: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F8648: cmp eax, 0x100
	{ uint32_t _d = ctx.eax; uint32_t _s = 256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F864D: jnb 0x002F8691
	if (!ctx.flags.cf) goto loc_2F8691;
	// 0x2F864F: cmp dword ptr [ecx+0x84], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x84u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8656: jnz 0x002F8691
	if (!ctx.flags.zf) goto loc_2F8691;
	// 0x2F8658: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8659: mov esi, [0x00300C28]
	ctx.esi = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2F865F: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x2F8661: shl edx, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2F8664: test dword ptr [edx+esi*1+0x04], 0x800000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.edx + ctx.esi + 0x4u) & 8388608, 32);
	// 0x2F866C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F866D: jnz 0x002F8691
	if (!ctx.flags.zf) goto loc_2F8691;
	// 0x2F866F: mov ecx, [ecx+eax*4+0x88]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4 + 0x88u);
	// 0x2F8676: movzx edx, byte ptr [ecx+0x64]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0x64u));
	// 0x2F867A: movzx edx, word ptr [ecx+edx*2+0x0A]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx + ctx.edx * 2 + 0xAu));
	// 0x2F867F: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8681: jnz 0x002F8691
	if (!ctx.flags.zf) goto loc_2F8691;
	// 0x2F8683: lea eax, [ecx+0x4C]
	ctx.eax = ctx.ecx + 0x4Cu;
	// 0x2F8686: cmp [eax], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8688: jz 0x002F8691
	if (ctx.flags.zf) goto loc_2F8691;
	// 0x2F868A: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F868C: call 0x002FAAEF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAAEF(ctx, base);
	ctx.esp += 4;
loc_2F8691:
	// 0x2F8691: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8694(X86Context& ctx, uint8_t* base) {
	// 0x2F8694: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F8698: test byte ptr [eax+0x08], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x8u) & 2, 8);
	// 0x2F869C: jnz 0x002F86B3
	if (!ctx.flags.zf) goto loc_2F86B3;
	// 0x2F869E: add ecx, 0x4B0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(1200);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)1200, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F86A4: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F86A6: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F86A9: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2F86AC: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F86AE: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F86B0: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
loc_2F86B3:
	// 0x2F86B3: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F86B5: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F86B6: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F86B9(X86Context& ctx, uint8_t* base) {
	// 0x2F86B9: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F86BD: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F86BE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F86BF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F86C0: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F86C2: lea esi, [edi+0x4A8]
	ctx.esi = ctx.edi + 0x4A8u;
	// 0x2F86C8: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F86CA: cmp eax, [esi]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F86CC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F86CD: setz bl
	X86_REG8L(ctx.ebx) = (ctx.flags.zf) ? 1 : 0;
	// 0x2F86D0: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F86D5: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F86D7: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F86D9: jnz 0x002F86F7
	if (!ctx.flags.zf) goto loc_2F86F7;
	// 0x2F86DB: lea eax, [edi+0x4E8]
	ctx.eax = ctx.edi + 0x4E8u;
	// 0x2F86E1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F86E2: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F86E8: add edi, 0x510
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(1296);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)1296, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F86EE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F86EF: call [0x0036B974]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B974u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F86F5: jmp 0x002F8715
	goto loc_2F8715;
loc_2F86F7:
	// 0x2F86F7: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2F86F9: jz 0x002F8715
	if (ctx.flags.zf) goto loc_2F8715;
	// 0x2F86FB: lea ecx, [edi+0x510]
	ctx.ecx = ctx.edi + 0x510u;
	// 0x2F8701: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8702: push [eax+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8705: add edi, 0x4E8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(1256);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)1256, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F870B: push [eax+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F870E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F870F: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F8715:
	// 0x2F8715: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8716: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8717: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8718: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F871B(X86Context& ctx, uint8_t* base) {
	// 0x2F871B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F871C: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F871E: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F8721: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2F8725: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8726: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8727: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2F8729: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F872A: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F872D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F8732: lea edi, [ebx+0x4A8]
	ctx.edi = ctx.ebx + 0x4A8u;
	// 0x2F8738: jmp 0x002F876E
	goto loc_2F876E;
loc_2F873A:
	// 0x2F873A: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2F873D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F873E: call [0x0036B7DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B7DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8744: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F8747: cmp eax, [ebp-0x04]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F874A: jnle 0x002F8776
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_2F8776;
	// 0x2F874C: jl 0x002F8756
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8756;
	// 0x2F874E: mov eax, [esi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2F8751: cmp eax, [ebp-0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8754: jnbe 0x002F8776
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_2F8776;
loc_2F8756:
	// 0x2F8756: and dword ptr [esi+0x08], 0xFFFFFFFD
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
	// 0x2F875A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F875B: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F8760: push [esi+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8763: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F8766: push [esi+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8769: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F876B: call [eax+0x24]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x24u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F876E:
	// 0x2F876E: mov esi, [edi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F8770: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8772: jnz 0x002F873A
	if (!ctx.flags.zf) goto loc_2F873A;
	// 0x2F8774: jmp 0x002F8790
	goto loc_2F8790;
loc_2F8776:
	// 0x2F8776: lea eax, [ebx+0x510]
	ctx.eax = ctx.ebx + 0x510u;
	// 0x2F877C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F877D: push [esi+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8780: add ebx, 0x4E8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(1256);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)1256, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8786: push [esi+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8789: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F878A: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F8790:
	// 0x2F8790: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F8793: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F8798: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8799: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F879A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F879B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F879C: ret
	return;
}

void CMcpxAPU_ServiceDeferredCommandsLow(X86Context& ctx, uint8_t* base) {
	// 0x2F879D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F879E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F87A0: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F87A3: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2F87A7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F87A8: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2F87AB: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F87AD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F87AE: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F87B1: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F87B4: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F87B7: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F87BC: lea edi, [esi+0x4B0]
	ctx.edi = ctx.esi + 0x4B0u;
	// 0x2F87C2: jmp 0x002F87CE
	goto loc_2F87CE;
loc_2F87C4:
	// 0x2F87C4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F87C5: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2F87C8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F87C9: call 0x002F82AB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F82AB(ctx, base);
	ctx.esp += 4;
loc_2F87CE:
	// 0x2F87CE: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F87D0: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F87D2: jnz 0x002F87C4
	if (!ctx.flags.zf) goto loc_2F87C4;
	// 0x2F87D4: jmp 0x002F8812
	goto loc_2F8812;
loc_2F87D6:
	// 0x2F87D6: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F87D9: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x2F87DB: jz 0x002F87EE
	if (ctx.flags.zf) goto loc_2F87EE;
	// 0x2F87DD: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x2F87DF: mov eax, [edi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x2F87E2: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x2F87E5: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x2F87E7: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F87E9: mov [eax+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.esi);
	// 0x2F87EC: jmp 0x002F87F4
	goto loc_2F87F4;
loc_2F87EE:
	// 0x2F87EE: and eax, 0xFFFFFFFD
	ctx.eax = ctx.eax & -3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F87F1: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
loc_2F87F4:
	// 0x2F87F4: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F87F7: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F87FC: push [esi+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F87FF: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F8802: push [esi+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8805: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F8807: call [eax+0x24]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x24u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F880A: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F880D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
loc_2F8812:
	// 0x2F8812: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8815: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F881A: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2F881C: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2F881F: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8821: jnz 0x002F87D6
	if (!ctx.flags.zf) goto loc_2F87D6;
	// 0x2F8823: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F8826: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F882B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F882C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F882D: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F882E: ret
	return;
}

void sub_2F882F(X86Context& ctx, uint8_t* base) {
	// 0x2F882F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8830: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8832: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8833: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8834: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F8838: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F883B: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
loc_2F8840:
	// 0x2F8840: mov eax, [0xFE820010]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2F8845: and eax, 0xFFFFFFFC
	ctx.eax = ctx.eax & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F8848: cmp eax, 0x04
	{ uint32_t _d = ctx.eax; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F884B: jb 0x002F8840
	if (ctx.flags.cf) goto loc_2F8840;
	// 0x2F884D: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8850: and eax, 0x07
	ctx.eax = ctx.eax & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F8853: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8856: mov [0xFE820280], eax
	X86_MEM_WRITE_u32(base, 0xFE820280u, ctx.eax);
	// 0x2F885B: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F8860: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8862: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8863: ret 0x04
	ctx.esp += 4;
	return;
}

void CMcpxAPU_SetMixBinHeadroom(X86Context& ctx, uint8_t* base) {
	// 0x2F8866: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8867: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8869: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F886A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F886B: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F886F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8870: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8872: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8875: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
loc_2F887A:
	// 0x2F887A: mov eax, [0xFE820010]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2F887F: and eax, 0xFFFFFFFC
	ctx.eax = ctx.eax & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F8882: cmp eax, 0x04
	{ uint32_t _d = ctx.eax; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8885: jb 0x002F887A
	if (ctx.flags.cf) goto loc_2F887A;
	// 0x2F8887: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F888A: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F888D: movzx ecx, byte ptr [ecx+eax*1+0x10]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + ctx.eax + 0x10u));
	// 0x2F8892: and ecx, 0x07
	ctx.ecx = ctx.ecx & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F8895: mov [eax*4-0x17DFE00], ecx
	X86_MEM_WRITE_u32(base, ctx.eax * 4 - 0x17DFE00u, ctx.ecx);
	// 0x2F889C: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F889F: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F88A4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F88A6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F88A7: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F88A8: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F88AB(X86Context& ctx, uint8_t* base) {
	// 0x2F88AB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88AC: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F88AE: sub esp, 0x34
	{ uint32_t _d = ctx.esp; uint32_t _s = 52;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F88B1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88B2: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F88B4: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F88B7: mov eax, [eax+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x2F88BA: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F88BD: jz 0x002F88FF
	if (ctx.flags.zf) goto loc_2F88FF;
	// 0x2F88BF: push 0x34
	{ auto _pv = (uint32_t)(52); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88C1: lea ecx, [ebp-0x34]
	ctx.ecx = ctx.ebp - 0x34u;
	// 0x2F88C4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88C5: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F88C8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88CA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88CB: call 0x002F8271
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8271(ctx, base);
	ctx.esp += 4;
	// 0x2F88D0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F88D2: jl 0x002F88FF
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F88FF;
	// 0x2F88D4: test byte ptr [0x0030049B], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, 0x30049Bu) & -128, 8);
	// 0x2F88DB: jz 0x002F88E3
	if (ctx.flags.zf) goto loc_2F88E3;
	// 0x2F88DD: and dword ptr [ebp-0x24], 0xFFFFFFFD
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, X86_MEM_READ_u32(base, ctx.ebp - 0x24u) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x24u), 32);
	// 0x2F88E1: jmp 0x002F88E7
	goto loc_2F88E7;
loc_2F88E3:
	// 0x2F88E3: or dword ptr [ebp-0x24], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, X86_MEM_READ_u32(base, ctx.ebp - 0x24u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x24u), 32);
loc_2F88E7:
	// 0x2F88E7: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F88EA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88EC: push 0x34
	{ auto _pv = (uint32_t)(52); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88EE: lea eax, [ebp-0x34]
	ctx.eax = ctx.ebp - 0x34u;
	// 0x2F88F1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88F2: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F88F5: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88F7: push [eax+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F88FA: call 0x002F81C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F81C8(ctx, base);
	ctx.esp += 4;
loc_2F88FF:
	// 0x2F88FF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8901: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8902: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8903: ret
	return;
}

void sub_2F8904(X86Context& ctx, uint8_t* base) {
	// 0x2F8904: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F8908: movzx edx, byte ptr [edx+0x64]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.edx + 0x64u));
	// 0x2F890C: add ecx, 0x53C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(1340);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)1340, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F8912: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8913: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F8915: add edx, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.esi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F8917: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8919: cmp edx, 0x1D
	{ uint32_t _d = ctx.edx; uint32_t _s = 29;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F891C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F891D: jbe 0x002F8926
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F8926;
	// 0x2F891F: mov eax, 0x88780032
	ctx.eax = -2005401550;
	// 0x2F8924: jmp 0x002F8928
	goto loc_2F8928;
loc_2F8926:
	// 0x2F8926: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_2F8928:
	// 0x2F8928: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F892B(X86Context& ctx, uint8_t* base) {
	// 0x2F892B: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F892F: movzx eax, byte ptr [eax+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x64u));
	// 0x2F8933: sub [ecx+0x53C], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x53Cu); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx + 0x53Cu, (uint32_t)_res); }
	// 0x2F8939: ret 0x04
	ctx.esp += 4;
	return;
}

void CMcpxAPU_SynchPlayback(X86Context& ctx, uint8_t* base) {
	// 0x2F893C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F893D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F893F: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F8942: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8943: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8944: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8946: mov eax, [esi+0x53C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x53Cu);
	// 0x2F894C: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F894E: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8950: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8951: mov [ebp-0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.ebx);
	// 0x2F8954: jz 0x002F8A74
	if (ctx.flags.zf) goto loc_2F8A74;
	// 0x2F895A: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F895C: add eax, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.eax, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F895E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F895F: push 0x61645344
	{ auto _pv = (uint32_t)(1633964868); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8964: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F8969: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F896B: mov ebx, edi
	ctx.ebx = ctx.edi;
	// 0x2F896D: neg ebx
	{ uint32_t _d = ctx.ebx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ebx = _res; }
	// 0x2F896F: sbb ebx, ebx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8971: and ebx, 0x7FF8FFF2
	ctx.ebx = ctx.ebx & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2F8977: add ebx, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)-2147024882, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F897D: mov [ebp-0x14], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.ebx);
	// 0x2F8980: js 0x002F8A6A
	if (ctx.flags.sf) goto loc_2F8A6A;
	// 0x2F8986: and dword ptr [ebp-0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, X86_MEM_READ_u32(base, ctx.ebp - 0x18u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x18u), 32);
	// 0x2F898A: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x2F898D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F8992: add dword ptr [esi+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F8999: lea eax, [esi+0x88]
	ctx.eax = ctx.esi + 0x88u;
	// 0x2F899F: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F89A1: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F89A4: mov dword ptr [ebp-0x0C], 0x100
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, 256);
loc_2F89AB:
	// 0x2F89AB: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F89AE: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F89B0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F89B2: jz 0x002F89F5
	if (ctx.flags.zf) goto loc_2F89F5;
	// 0x2F89B4: mov dx, [eax+0x12]
	X86_REG16(ctx.edx) = X86_MEM_READ_u16(base, ctx.eax + 0x12u);
	// 0x2F89B8: and dx, 0x447
	X86_REG16(ctx.edx) = X86_REG16(ctx.edx) & 1095;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.edx), 16);
	// 0x2F89BD: cmp dx, 0x43
	{ uint16_t _d = X86_REG16(ctx.edx); uint16_t _s = 67;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F89C1: jnz 0x002F89E9
	if (!ctx.flags.zf) goto loc_2F89E9;
	// 0x2F89C3: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F89C7: cmp byte ptr [eax+0x64], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax + 0x64u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F89CB: jbe 0x002F89E9
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F89E9;
	// 0x2F89CD: lea edx, [eax+0x0C]
	ctx.edx = ctx.eax + 0xCu;
loc_2F89D0:
	// 0x2F89D0: mov bx, [edx]
	X86_REG16(ctx.ebx) = X86_MEM_READ_u16(base, ctx.edx);
	// 0x2F89D3: mov [edi+ecx*2], bx
	X86_MEM_WRITE_u16(base, ctx.edi + ctx.ecx * 2, X86_REG16(ctx.ebx));
	// 0x2F89D7: movzx ebx, byte ptr [eax+0x64]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x64u));
	// 0x2F89DB: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F89DC: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F89DF: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F89E0: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F89E1: cmp [ebp-0x04], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F89E4: jb 0x002F89D0
	if (ctx.flags.cf) goto loc_2F89D0;
	// 0x2F89E6: mov ebx, [ebp-0x14]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
loc_2F89E9:
	// 0x2F89E9: mov dx, [eax+0x12]
	X86_REG16(ctx.edx) = X86_MEM_READ_u16(base, ctx.eax + 0x12u);
	// 0x2F89ED: and dx, 0xFFBF
	X86_REG16(ctx.edx) = X86_REG16(ctx.edx) & -65;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.edx), 16);
	// 0x2F89F1: mov [eax+0x12], dx
	X86_MEM_WRITE_u16(base, ctx.eax + 0x12u, X86_REG16(ctx.edx));
loc_2F89F5:
	// 0x2F89F5: add dword ptr [ebp-0x08], 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), (int32_t)4, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2F89F9: dec [ebp-0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x2F89FC: jnz 0x002F89AB
	if (!ctx.flags.zf) goto loc_2F89AB;
	// 0x2F89FE: and dword ptr [esi+0x53C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x53Cu, X86_MEM_READ_u32(base, ctx.esi + 0x53Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x53Cu), 32);
	// 0x2F8A05: lea eax, [ecx+0x03]
	ctx.eax = ctx.ecx + 0x3u;
loc_2F8A08:
	// 0x2F8A08: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2F8A0E: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2F8A11: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8A13: jb 0x002F8A08
	if (ctx.flags.cf) goto loc_2F8A08;
	// 0x2F8A15: movzx eax, word ptr [edi]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi));
	// 0x2F8A18: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F8A1C: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F8A1E: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2F8A23: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2F8A2D: jbe 0x002F8A51
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F8A51;
loc_2F8A2F:
	// 0x2F8A2F: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F8A32: movzx eax, word ptr [edi+eax*2]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi + ctx.eax * 2));
	// 0x2F8A36: mov edx, [ebp-0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2F8A39: and edx, 0xFFFF0000
	ctx.edx = ctx.edx & -65536;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2F8A3F: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F8A41: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F8A44: cmp [ebp-0x04], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8A47: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x2F8A4A: mov [0xFE820140], eax
	X86_MEM_WRITE_u32(base, 0xFE820140u, ctx.eax);
	// 0x2F8A4F: jb 0x002F8A2F
	if (ctx.flags.cf) goto loc_2F8A2F;
loc_2F8A51:
	// 0x2F8A51: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2F8A5B: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2F8A62: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x2F8A65: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
loc_2F8A6A:
	// 0x2F8A6A: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F8A6C: jz 0x002F8A74
	if (ctx.flags.zf) goto loc_2F8A74;
	// 0x2F8A6E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8A6F: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F8A74:
	// 0x2F8A74: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8A75: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8A76: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F8A78: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8A79: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8A7A: ret
	return;
}

void sub_2F8A7B(X86Context& ctx, uint8_t* base) {
	// 0x2F8A7B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8A7C: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8A7E: sub esp, 0x224
	{ uint32_t _d = ctx.esp; uint32_t _s = 548;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F8A84: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8A85: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8A87: lea ecx, [ebp-0x04]
	ctx.ecx = ctx.ebp - 0x4u;
	// 0x2F8A8A: call 0x002F3FA9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FA9(ctx, base);
	ctx.esp += 4;
	// 0x2F8A8F: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F8A92: test word ptr [eax+0x80], 0xFFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.eax + 0x80u) & 4095, 16);
	// 0x2F8A9B: jz 0x002F8B27
	if (ctx.flags.zf) goto loc_2F8B27;
	// 0x2F8AA1: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F8AA4: cmp eax, 0xFFFFFFFF
	{ uint32_t _d = ctx.eax; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8AA7: jz 0x002F8B27
	if (ctx.flags.zf) goto loc_2F8B27;
	// 0x2F8AA9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AAA: mov edi, 0x118
	ctx.edi = 280;
	// 0x2F8AAF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AB0: lea ecx, [ebp-0x224]
	ctx.ecx = ctx.ebp - 0x224u;
	// 0x2F8AB6: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AB7: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F8ABA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8ABC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8ABD: call 0x002F8271
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8271(ctx, base);
	ctx.esp += 4;
	// 0x2F8AC2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8AC4: jl 0x002F8B26
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8B26;
	// 0x2F8AC6: lea eax, [ebp-0x224]
	ctx.eax = ctx.ebp - 0x224u;
	// 0x2F8ACC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8ACD: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F8AD0: add eax, 0x80
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(128);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)128, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F8AD5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AD6: call 0x002F52B9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F52B9(ctx, base);
	ctx.esp += 4;
	// 0x2F8ADB: or dword ptr [ebp-0x214], 0x04
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x214u, X86_MEM_READ_u32(base, ctx.ebp - 0x214u) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x214u), 32);
	// 0x2F8AE2: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F8AE5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AE7: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AE9: lea eax, [ebp-0x214]
	ctx.eax = ctx.ebp - 0x214u;
	// 0x2F8AEF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AF0: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F8AF3: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AF5: push [eax+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8AF8: call 0x002F81C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F81C8(ctx, base);
	ctx.esp += 4;
	// 0x2F8AFD: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F8B00: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B02: push 0x108
	{ auto _pv = (uint32_t)(264); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B07: lea eax, [ebp-0x10C]
	ctx.eax = ctx.ebp - 0x10Cu;
	// 0x2F8B0D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B0E: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F8B11: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B12: push [eax+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B15: call 0x002F81C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F81C8(ctx, base);
	ctx.esp += 4;
	// 0x2F8B1A: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F8B1D: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B1F: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B21: call 0x002F805E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F805E(ctx, base);
	ctx.esp += 4;
loc_2F8B26:
	// 0x2F8B26: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F8B27:
	// 0x2F8B27: lea ecx, [ebp-0x04]
	ctx.ecx = ctx.ebp - 0x4u;
	// 0x2F8B2A: call 0x002F3FCE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FCE(ctx, base);
	ctx.esp += 4;
	// 0x2F8B2F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8B30: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8B31: ret
	return;
}

void sub_2F8B32(X86Context& ctx, uint8_t* base) {
	// 0x2F8B32: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F8B36: call 0x002F871B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F871B(ctx, base);
	ctx.esp += 4;
	// 0x2F8B3B: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F8B3E(X86Context& ctx, uint8_t* base) {
	// 0x2F8B3E: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F8B42: add ecx, 0xFFFFFAD4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(-1324);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)-1324, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F8B48: mov dword ptr [0x003004A0], 0x01
	X86_MEM_WRITE_u32(base, 0x3004A0u, 1);
	// 0x2F8B52: call 0x002F836D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F836D(ctx, base);
	ctx.esp += 4;
	// 0x2F8B57: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8B5A(X86Context& ctx, uint8_t* base) {
	// 0x2F8B5A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B5B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B5C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B5D: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8B5F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B60: mov dword ptr [esi], 0x36C20C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588620);
	// 0x2F8B66: mov dword ptr [esi+0x08], 0x36C208
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 3588616);
	// 0x2F8B6D: call 0x002F836D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F836D(ctx, base);
	ctx.esp += 4;
	// 0x2F8B72: cmp dword ptr [0x00300B78], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x300B78u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8B79: jz 0x002F8B8D
	if (ctx.flags.zf) goto loc_2F8B8D;
	// 0x2F8B7B: push 0x300B78
	{ auto _pv = (uint32_t)(3148664); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B80: call [0x0036B960]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B960u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8B86: and dword ptr [0x00300B78], 0x00
	X86_MEM_WRITE_u32(base, 0x300B78u, X86_MEM_READ_u32(base, 0x300B78u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, 0x300B78u), 32);
loc_2F8B8D:
	// 0x2F8B8D: lea eax, [esi+0x4E8]
	ctx.eax = ctx.esi + 0x4E8u;
	// 0x2F8B93: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8B94: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8B9A: mov ebp, [0x0036B974]
	ctx.ebp = X86_MEM_READ_u32(base, 0x36B974u);
	// 0x2F8BA0: lea edi, [esi+0x4C8]
	ctx.edi = ctx.esi + 0x4C8u;
	// 0x2F8BA6: cmp word ptr [edi], 0x13
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.edi); uint16_t _s = 19;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F8BAA: jnz 0x002F8BB2
	if (!ctx.flags.zf) goto loc_2F8BB2;
	// 0x2F8BAC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8BAD: call ebp
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.ebp);
	ctx.esp += 4;
	// 0x2F8BAF: not [edi]
	X86_MEM_WRITE_u16(base, ctx.edi, ~X86_MEM_READ_u16(base, ctx.edi));
loc_2F8BB2:
	// 0x2F8BB2: lea ebx, [esi+0x510]
	ctx.ebx = ctx.esi + 0x510u;
	// 0x2F8BB8: cmp word ptr [ebx], 0x13
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ebx); uint16_t _s = 19;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F8BBC: jnz 0x002F8BCA
	if (!ctx.flags.zf) goto loc_2F8BCA;
	// 0x2F8BBE: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8BBF: call ebp
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.ebp);
	ctx.esp += 4;
	// 0x2F8BC1: mov ax, [edi]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi);
	// 0x2F8BC4: not ax
	X86_REG16(ctx.eax) = ~X86_REG16(ctx.eax);
	// 0x2F8BC7: mov [ebx], ax
	X86_MEM_WRITE_u16(base, ctx.ebx, X86_REG16(ctx.eax));
loc_2F8BCA:
	// 0x2F8BCA: lea edi, [esi+0x52C]
	ctx.edi = ctx.esi + 0x52Cu;
	// 0x2F8BD0: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F8BD2: cmp [edi], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8BD4: jz 0x002F8BE0
	if (ctx.flags.zf) goto loc_2F8BE0;
	// 0x2F8BD6: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8BD7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8BD8: call [0x0036B8D4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8D4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8BDE: mov [edi], ebx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ebx);
loc_2F8BE0:
	// 0x2F8BE0: mov eax, [esi+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
	// 0x2F8BE3: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x2F8BE5: mov eax, [esi+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	// 0x2F8BE8: lea ecx, [esi+0x60]
	ctx.ecx = ctx.esi + 0x60u;
	// 0x2F8BEB: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x2F8BED: call 0x002F9E84
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E84(ctx, base);
	ctx.esp += 4;
	// 0x2F8BF2: lea ecx, [esi+0x08]
	ctx.ecx = ctx.esi + 0x8u;
	// 0x2F8BF5: call 0x002FDF70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDF70(ctx, base);
	ctx.esp += 4;
	// 0x2F8BFA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8BFB: mov dword ptr [esi], 0x36C17C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588476);
	// 0x2F8C01: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C02: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C03: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C04: ret
	return;
}

void sub_2F8C05(X86Context& ctx, uint8_t* base) {
	// 0x2F8C05: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C06: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C07: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C08: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C09: mov edi, [0x0036B978]
	ctx.edi = X86_MEM_READ_u32(base, 0x36B978u);
	// 0x2F8C0F: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8C11: mov ebp, 0x2F85AA
	ctx.ebp = 3114410;
	// 0x2F8C16: mov ebx, 0x300B78
	ctx.ebx = 3148664;
	// 0x2F8C1B: jmp 0x002F8C34
	goto loc_2F8C34;
loc_2F8C1D:
	// 0x2F8C1D: test byte ptr [esi+0x4C0], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x4C0u) & 64, 8);
	// 0x2F8C24: jz 0x002F8C2D
	if (ctx.flags.zf) goto loc_2F8C2D;
	// 0x2F8C26: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F8C28: call 0x002F8531
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8531(ctx, base);
	ctx.esp += 4;
loc_2F8C2D:
	// 0x2F8C2D: and dword ptr [esi+0x4C0], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4C0u, X86_MEM_READ_u32(base, ctx.esi + 0x4C0u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x4C0u), 32);
loc_2F8C34:
	// 0x2F8C34: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C35: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C36: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C37: call edi
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.edi);
	ctx.esp += 4;
	// 0x2F8C39: test byte ptr [esi+0x4C0], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x4C0u) & 1, 8);
	// 0x2F8C40: jnz 0x002F8C1D
	if (!ctx.flags.zf) goto loc_2F8C1D;
	// 0x2F8C42: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C43: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C44: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C45: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C46: ret
	return;
}

void sub_2F8C47(X86Context& ctx, uint8_t* base) {
	// 0x2F8C47: cmp dword ptr [esp+0x04], 0x8000
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x4u); uint32_t _s = 32768;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8C4F: jnz 0x002F8C5A
	if (!ctx.flags.zf) goto loc_2F8C5A;
	// 0x2F8C51: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C55: call 0x002F8644
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8644(ctx, base);
	ctx.esp += 4;
loc_2F8C5A:
	// 0x2F8C5A: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F8C5D(X86Context& ctx, uint8_t* base) {
	// 0x2F8C5D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C5E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8C60: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C61: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C62: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F8C66: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C67: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C68: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F8C6A: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8C6D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F8C72: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8C75: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F8C78: test al, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 2, 8);
	// 0x2F8C7A: jz 0x002F8C8F
	if (ctx.flags.zf) goto loc_2F8C8F;
	// 0x2F8C7C: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x2F8C7E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8C7F: jz 0x002F8C88
	if (ctx.flags.zf) goto loc_2F8C88;
	// 0x2F8C81: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F8C86: jmp 0x002F8C8F
	goto loc_2F8C8F;
loc_2F8C88:
	// 0x2F8C88: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F8C8A: call 0x002F86B9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F86B9(ctx, base);
	ctx.esp += 4;
loc_2F8C8F:
	// 0x2F8C8F: and dword ptr [esi+0x08], 0xFFFFFFFD
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
	// 0x2F8C93: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8C96: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F8C9B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C9C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C9D: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8C9E: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8CA1(X86Context& ctx, uint8_t* base) {
	// 0x2F8CA1: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F8CA5: call 0x002F8C05
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8C05(ctx, base);
	ctx.esp += 4;
	// 0x2F8CAA: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F8CC8(X86Context& ctx, uint8_t* base) {
	// 0x2F8CC8: mov eax, [0xFE801100]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE801100u);
	// 0x2F8CCD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8CCE: mov edx, 0xF00
	ctx.edx = 3840;
	// 0x2F8CD3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8CD4: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F8CD6: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8CD8: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F8CDA: mov ecx, [0xFE801300]
	ctx.ecx = X86_MEM_READ_u32(base, 0xFE801300u);
	// 0x2F8CE0: mov esi, [0xFE801304]
	ctx.esi = X86_MEM_READ_u32(base, 0xFE801304u);
	// 0x2F8CE6: jnz 0x002F8CF7
	if (!ctx.flags.zf) goto loc_2F8CF7;
	// 0x2F8CE8: and ecx, 0xFFFF
	ctx.ecx = ctx.ecx & 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F8CEE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8CEF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8CF0: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F8CF2: call 0x002F8C47
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8C47(ctx, base);
	ctx.esp += 4;
loc_2F8CF7:
	// 0x2F8CF7: lea esi, [edi+0x08]
	ctx.esi = ctx.edi + 0x8u;
	// 0x2F8CFA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8CFC: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F8CFE: call 0x002FDCF7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDCF7(ctx, base);
	ctx.esp += 4;
	// 0x2F8D03: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8D05: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F8D07: call 0x002FDCF7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDCF7(ctx, base);
	ctx.esp += 4;
	// 0x2F8D0C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8D0D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8D0E: ret
	return;
}

void sub_2F8D0F(X86Context& ctx, uint8_t* base) {
	// 0x2F8D0F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8D10: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8D12: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F8D15: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8D16: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8D19: mov eax, [esi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2F8D1C: or eax, [esi+0x1C]
	ctx.eax = ctx.eax | X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F8D1F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8D20: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F8D22: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x2F8D25: jz 0x002F8DD8
	if (ctx.flags.zf) goto loc_2F8DD8;
	// 0x2F8D2B: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x2F8D2E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8D2F: call [0x0036B7DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B7DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8D35: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F8D38: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8D3A: mov ecx, [esi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2F8D3D: jnle 0x002F8D55
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_2F8D55;
	// 0x2F8D3F: jl 0x002F8D45
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8D45;
	// 0x2F8D41: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F8D43: jnbe 0x002F8D55
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_2F8D55;
loc_2F8D45:
	// 0x2F8D45: mov edx, [ebp-0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2F8D48: sub edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F8D4A: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F8D4D: sbb ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F8D4F: mov [esi+0x18], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.edx);
	// 0x2F8D52: mov [esi+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.ecx);
loc_2F8D55:
	// 0x2F8D55: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F8D58: cmp eax, [ebp-0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8D5B: jl 0x002F8DD8
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8DD8;
	// 0x2F8D5D: jnle 0x002F8D67
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_2F8D67;
	// 0x2F8D5F: mov eax, [esi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2F8D62: cmp eax, [ebp-0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8D65: jbe 0x002F8DD8
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F8DD8;
loc_2F8D67:
	// 0x2F8D67: test byte ptr [esi+0x08], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x8u) & 2, 8);
	// 0x2F8D6B: mov dword ptr [ebp+0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 1);
	// 0x2F8D72: jz 0x002F8D7C
	if (ctx.flags.zf) goto loc_2F8D7C;
	// 0x2F8D74: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8D75: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F8D77: call 0x002F8C5D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8C5D(ctx, base);
	ctx.esp += 4;
loc_2F8D7C:
	// 0x2F8D7C: lea ecx, [edi+0x4A8]
	ctx.ecx = ctx.edi + 0x4A8u;
	// 0x2F8D82: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F8D84: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8D86: jz 0x002F8DA9
	if (ctx.flags.zf) goto loc_2F8DA9;
	// 0x2F8D88: mov edx, [esi+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2F8D8B: mov edi, [esi+0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F8D8E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F8D8F:
	// 0x2F8D8F: mov ebx, [eax+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	// 0x2F8D92: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8D94: jnle 0x002F8DA5
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_2F8DA5;
	// 0x2F8D96: jl 0x002F8D9F
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8D9F;
	// 0x2F8D98: mov ebx, [eax+0x18]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x2F8D9B: cmp ebx, edx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8D9D: jnbe 0x002F8DA5
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_2F8DA5;
loc_2F8D9F:
	// 0x2F8D9F: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F8DA1: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8DA3: jnz 0x002F8D8F
	if (!ctx.flags.zf) goto loc_2F8D8F;
loc_2F8DA5:
	// 0x2F8DA5: mov edi, [ebp-0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F8DA8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F8DA9:
	// 0x2F8DA9: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x2F8DAB: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F8DAE: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x2F8DB1: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x2F8DB3: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F8DB5: mov [eax+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.esi);
	// 0x2F8DB8: cmp esi, [ecx]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8DBA: jnz 0x002F8DDC
	if (!ctx.flags.zf) goto loc_2F8DDC;
	// 0x2F8DBC: lea eax, [edi+0x510]
	ctx.eax = ctx.edi + 0x510u;
	// 0x2F8DC2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DC3: push [esi+0x1C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x1Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DC6: add edi, 0x4E8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(1256);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)1256, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F8DCC: push [esi+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DCF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DD0: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8DD6: jmp 0x002F8DDC
	goto loc_2F8DDC;
loc_2F8DD8:
	// 0x2F8DD8: and dword ptr [ebp+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, X86_MEM_READ_u32(base, ctx.ebp + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
loc_2F8DDC:
	// 0x2F8DDC: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8DDF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8DE0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8DE1: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8DE2: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8DE5(X86Context& ctx, uint8_t* base) {
	// 0x2F8DE5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DE6: mov ebx, [0xFE801000]
	ctx.ebx = X86_MEM_READ_u32(base, 0xFE801000u);
	// 0x2F8DEC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DED: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8DEE: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x2F8DF0: and edi, 0x01
	ctx.edi = ctx.edi & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2F8DF3: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8DF5: jz 0x002F8E34
	if (ctx.flags.zf) goto loc_2F8E34;
	// 0x2F8DF7: mov [0xFE801000], ebx
	X86_MEM_WRITE_u32(base, 0xFE801000u, ctx.ebx);
	// 0x2F8DFD: or [esi+0x4B8], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4B8u, X86_MEM_READ_u32(base, ctx.esi + 0x4B8u) | ctx.ebx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x4B8u), 32);
	// 0x2F8E03: test bl, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 16, 8);
	// 0x2F8E06: jz 0x002F8E0D
	if (ctx.flags.zf) goto loc_2F8E0D;
	// 0x2F8E08: call 0x002F8CC8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8CC8(ctx, base);
	ctx.esp += 4;
loc_2F8E0D:
	// 0x2F8E0D: test bl, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 8, 8);
	// 0x2F8E10: jz 0x002F8E19
	if (ctx.flags.zf) goto loc_2F8E19;
	// 0x2F8E12: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F8E14: call 0x002F85D6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F85D6(ctx, base);
	ctx.esp += 4;
loc_2F8E19:
	// 0x2F8E19: test bl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 64, 8);
	// 0x2F8E1C: jz 0x002F8E2F
	if (ctx.flags.zf) goto loc_2F8E2F;
	// 0x2F8E1E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E20: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E22: add esi, 0x4C8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(1224);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)1224, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2F8E28: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E29: call [0x0036B948]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B948u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F8E2F:
	// 0x2F8E2F: mov eax, [0xFE801000]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE801000u);
loc_2F8E34:
	// 0x2F8E34: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F8E36: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8E37: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8E38: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8E39: ret
	return;
}

void sub_2F8E3A(X86Context& ctx, uint8_t* base) {
	// 0x2F8E3A: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E3B: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8E3D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E3E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E3F: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F8E43: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E44: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E45: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F8E47: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8E4A: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F8E4F: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8E52: test byte ptr [esi+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x8u) & 1, 8);
	// 0x2F8E56: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F8E58: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E59: jz 0x002F8E62
	if (ctx.flags.zf) goto loc_2F8E62;
	// 0x2F8E5B: call 0x002F8694
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8694(ctx, base);
	ctx.esp += 4;
	// 0x2F8E60: jmp 0x002F8E67
	goto loc_2F8E67;
loc_2F8E62:
	// 0x2F8E62: call 0x002F8D0F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8D0F(ctx, base);
	ctx.esp += 4;
loc_2F8E67:
	// 0x2F8E67: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F8E69: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F8E6B: jz 0x002F8E71
	if (ctx.flags.zf) goto loc_2F8E71;
	// 0x2F8E6D: or dword ptr [esi+0x08], 0x02
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
loc_2F8E71:
	// 0x2F8E71: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F8E74: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F8E79: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F8E7B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8E7C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8E7D: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8E7E: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8E81(X86Context& ctx, uint8_t* base) {
	// 0x2F8E81: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F8E85: call 0x002F8DE5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8DE5(ctx, base);
	ctx.esp += 4;
	// 0x2F8E8A: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F8E8D(X86Context& ctx, uint8_t* base) {
	// 0x2F8E8D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E8E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E8F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E90: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E91: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F8E93: lea ebp, [esi+0x08]
	ctx.ebp = ctx.esi + 0x8u;
	// 0x2F8E96: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8E97: mov ecx, ebp
	ctx.ecx = ctx.ebp;
	// 0x2F8E99: call 0x002FE3D7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE3D7(ctx, base);
	ctx.esp += 4;
	// 0x2F8E9E: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F8EA0: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F8EA2: jl 0x002F8F61
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8F61;
	// 0x2F8EA8: push 0x7FF
	{ auto _pv = (uint32_t)(2047); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EAD: lea ecx, [esi+0x60]
	ctx.ecx = ctx.esi + 0x60u;
	// 0x2F8EB0: call 0x002F9EA6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9EA6(ctx, base);
	ctx.esp += 4;
	// 0x2F8EB5: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F8EB7: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F8EB9: jl 0x002F8F61
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8F61;
	// 0x2F8EBF: mov ebx, [0x0036B8F0]
	ctx.ebx = X86_MEM_READ_u32(base, 0x36B8F0u);
	// 0x2F8EC5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EC6: push 0x2F8CA1
	{ auto _pv = (uint32_t)(3116193); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8ECB: lea eax, [esi+0x4C8]
	ctx.eax = ctx.esi + 0x4C8u;
	// 0x2F8ED1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8ED2: call ebx
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.ebx);
	ctx.esp += 4;
	// 0x2F8ED4: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8ED6: lea eax, [esi+0x4E8]
	ctx.eax = ctx.esi + 0x4E8u;
	// 0x2F8EDC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EDD: call [0x0036B8DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8EE3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EE4: push 0x2F8B32
	{ auto _pv = (uint32_t)(3115826); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EE9: lea eax, [esi+0x510]
	ctx.eax = ctx.esi + 0x510u;
	// 0x2F8EEF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EF0: call ebx
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.ebx);
	ctx.esp += 4;
	// 0x2F8EF2: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x2F8EF6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EF7: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8EF9: call [0x0036B92C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B92Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8EFF: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F01: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F03: push [esp+0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F07: mov ebx, 0x300B78
	ctx.ebx = 3148664;
	// 0x2F8F0C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F0D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F0E: push 0x2F8E81
	{ auto _pv = (uint32_t)(3116673); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F13: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F14: call [0x0036B938]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B938u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8F1A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F1B: call [0x0036B934]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B934u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8F21: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x2F8F23: jnz 0x002F8F2A
	if (!ctx.flags.zf) goto loc_2F8F2A;
	// 0x2F8F25: mov edi, 0x80004005
	ctx.edi = -2147467259;
loc_2F8F2A:
	// 0x2F8F2A: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F8F2C: jl 0x002F8F61
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8F61;
	// 0x2F8F2E: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F30: mov ecx, ebp
	ctx.ecx = ctx.ebp;
	// 0x2F8F32: mov dword ptr [0xFE801000], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, 0xFE801000u, -1);
	// 0x2F8F3C: call 0x002FDC89
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDC89(ctx, base);
	ctx.esp += 4;
	// 0x2F8F41: lea eax, [esi+0x52C]
	ctx.eax = ctx.esi + 0x52Cu;
	// 0x2F8F47: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F49: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F4A: mov dword ptr [eax], 0x2F8B3E
	X86_MEM_WRITE_u32(base, ctx.eax, 3115838);
	// 0x2F8F50: call [0x0036B8D4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8D4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8F56: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F58: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F8F5A: call 0x002F882F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F882F(ctx, base);
	ctx.esp += 4;
	// 0x2F8F5F: mov edi, eax
	ctx.edi = ctx.eax;
loc_2F8F61:
	// 0x2F8F61: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F8F63:
	// 0x2F8F63: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F8F65: jl 0x002F8F77
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F8F77;
	// 0x2F8F67: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F68: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F8F6A: call 0x002F8866
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxAPU_SetMixBinHeadroom(ctx, base);
	ctx.esp += 4;
	// 0x2F8F6F: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F8F70: cmp ebx, 0x20
	{ uint32_t _d = ctx.ebx; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8F73: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F8F75: jb 0x002F8F63
	if (ctx.flags.cf) goto loc_2F8F63;
loc_2F8F77:
	// 0x2F8F77: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F8F79: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8F7A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8F7B: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8F7C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8F7D: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8F7E: ret
	return;
}

void sub_2F8F7F(X86Context& ctx, uint8_t* base) {
	// 0x2F8F7F: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F8F83: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F8F86: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8F88: jz 0x002F8F8D
	if (ctx.flags.zf) goto loc_2F8F8D;
	// 0x2F8F8A: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
loc_2F8F8D:
	// 0x2F8F8D: mov eax, [ecx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x2F8F90: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8F92: jz 0x002F8F9A
	if (ctx.flags.zf) goto loc_2F8F9A;
	// 0x2F8F94: mov dword ptr [eax], 0x8000000A
	X86_MEM_WRITE_u32(base, ctx.eax, -2147483638);
loc_2F8F9A:
	// 0x2F8F9A: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F8F9D(X86Context& ctx, uint8_t* base) {
	// 0x2F8F9D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8F9E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F8FA0: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F8FA3: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2F8FA6: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F8FA8: jz 0x002F8FAF
	if (ctx.flags.zf) goto loc_2F8FAF;
	// 0x2F8FAA: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F8FAD: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_2F8FAF:
	// 0x2F8FAF: mov ecx, [eax+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x2F8FB2: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F8FB4: mov edx, [ebp+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x2F8FB7: jz 0x002F8FBB
	if (ctx.flags.zf) goto loc_2F8FBB;
	// 0x2F8FB9: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_2F8FBB:
	// 0x2F8FBB: cmp dword ptr [ebp+0x10], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x10u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8FBF: jz 0x002F8FCD
	if (ctx.flags.zf) goto loc_2F8FCD;
	// 0x2F8FC1: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FC2: push [eax+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FC5: push [ebp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FC8: call [ebp+0x10]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F8FCB: jmp 0x002F8FDD
	goto loc_2F8FDD;
loc_2F8FCD:
	// 0x2F8FCD: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2F8FD0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F8FD2: jz 0x002F8FDD
	if (ctx.flags.zf) goto loc_2F8FDD;
	// 0x2F8FD4: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FD6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FD7: call [0x0036B868]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B868u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F8FDD:
	// 0x2F8FDD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8FDE: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_2F8FE1(X86Context& ctx, uint8_t* base) {
	// 0x2F8FE1: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F8FE5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FE6: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F8FE8: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F8FEA: jz 0x002F8FF6
	if (ctx.flags.zf) goto loc_2F8FF6;
	// 0x2F8FEC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FED: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F8FF1: call 0x002F82AB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F82AB(ctx, base);
	ctx.esp += 4;
loc_2F8FF6:
	// 0x2F8FF6: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F8FF8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F8FF9: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F8FFC(X86Context& ctx, uint8_t* base) {
	// 0x2F8FFC: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9000: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F9002: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9005: movzx eax, byte ptr [eax+ecx*1+0x0F]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + ctx.ecx + 0xFu));
	// 0x2F900A: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F900B: jz 0x002F9014
	if (ctx.flags.zf) goto loc_2F9014;
	// 0x2F900D: sub eax, 0x7F
	{ uint32_t _d = ctx.eax; uint32_t _s = 127;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9010: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9012: jmp 0x002F9017
	goto loc_2F9017;
loc_2F9014:
	// 0x2F9014: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9016: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2F9017:
	// 0x2F9017: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F901A(X86Context& ctx, uint8_t* base) {
	// 0x2F901A: mov ecx, [ecx+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2F901D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9021: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9023: div [ecx+0x14]
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x2F9026: cmp word ptr [ecx+0x0C], 0x69
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ecx + 0xCu); uint16_t _s = 105;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F902B: jnz 0x002F9030
	if (!ctx.flags.zf) goto loc_2F9030;
	// 0x2F902D: shl eax, 0x06
	{ auto _cnt = 0x6u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
loc_2F9030:
	// 0x2F9030: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9033(X86Context& ctx, uint8_t* base) {
	// 0x2F9033: mov ecx, [ecx+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2F9036: cmp word ptr [ecx+0x0C], 0x69
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.ecx + 0xCu); uint16_t _s = 105;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F903B: jnz 0x002F904A
	if (!ctx.flags.zf) goto loc_2F904A;
	// 0x2F903D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9041: shr eax, 0x06
	{ auto _cnt = 0x6u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9044: imul eax, [ecx+0x14]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x2F9048: jmp 0x002F9052
	goto loc_2F9052;
loc_2F904A:
	// 0x2F904A: mov eax, [ecx+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x2F904D: imul eax, [esp+0x04]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
loc_2F9052:
	// 0x2F9052: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9055(X86Context& ctx, uint8_t* base) {
	// 0x2F9055: lea eax, [ecx+0xA8]
	ctx.eax = ctx.ecx + 0xA8u;
	// 0x2F905B: cmp [eax], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F905D: jnz 0x002F9069
	if (!ctx.flags.zf) goto loc_2F9069;
	// 0x2F905F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9061: cmp [ecx+0x194], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x194u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9067: jz 0x002F906C
	if (ctx.flags.zf) goto loc_2F906C;
loc_2F9069:
	// 0x2F9069: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F906B: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2F906C:
	// 0x2F906C: ret
	return;
}

void sub_2F906D(X86Context& ctx, uint8_t* base) {
	// 0x2F906D: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F906E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F906F: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9071: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9073: call 0x002FA50E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA50E(ctx, base);
	ctx.esp += 4;
	// 0x2F9078: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F907A: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F907C: jl 0x002F9111
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F9111;
	// 0x2F9082: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F9088: mov eax, [eax+0xBC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xBCu);
	// 0x2F908E: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x2F9091: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9093: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9096: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9097: push 0x61645344
	{ auto _pv = (uint32_t)(1633964868); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F909C: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F90A1: mov [esi+0xC0], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, ctx.eax);
	// 0x2F90A7: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2F90A9: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F90AB: and eax, 0x7FF8FFF2
	ctx.eax = ctx.eax & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F90B0: add eax, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-2147024882, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F90B5: js 0x002F9111
	if (ctx.flags.sf) goto loc_2F9111;
	// 0x2F90B7: mov ecx, [esi+0x80]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F90BD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F90BE: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F90C0: cmp [ecx+0xBC], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0xBCu); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F90C6: jbe 0x002F90FB
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F90FB;
	// 0x2F90C8: lea edx, [esi+0xB0]
	ctx.edx = ctx.esi + 0xB0u;
	// 0x2F90CE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F90CF:
	// 0x2F90CF: mov ecx, [esi+0xC0]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xC0u);
	// 0x2F90D5: add ecx, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.ebx, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F90D7: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x2F90D9: mov ebp, [edx+0x04]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x2F90DC: mov [ecx+0x04], ebp
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.ebp);
	// 0x2F90DF: mov [edx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.ecx);
	// 0x2F90E2: mov ebp, [ecx+0x04]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F90E5: mov [ebp], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp, ctx.ecx);
	// 0x2F90E8: mov ecx, [esi+0x80]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F90EE: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F90EF: add ebx, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)48, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F90F2: cmp edi, [ecx+0xBC]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0xBCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F90F8: jb 0x002F90CF
	if (ctx.flags.cf) goto loc_2F90CF;
	// 0x2F90FA: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F90FB:
	// 0x2F90FB: mov ecx, [esi+0x80]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F9101: test byte ptr [ecx+0x0A], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ecx + 0xAu) & 4, 8);
	// 0x2F9105: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9106: jnz 0x002F9111
	if (!ctx.flags.zf) goto loc_2F9111;
	// 0x2F9108: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F910A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F910B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F910C: jmp 0x002FB267
	sub_2FB267(ctx, base);
	return;
loc_2F9111:
	// 0x2F9111: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9112: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9113: ret
	return;
}

void CMcpxStream_Stop(X86Context& ctx, uint8_t* base) {
	// 0x2F9114: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9115: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9117: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9118: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9119: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F911A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F911B: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F911D: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F911F: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F9122: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x2F9125: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F912A: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2F912D: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2F912F: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9131: jnz 0x002F9176
	if (!ctx.flags.zf) goto loc_2F9176;
	// 0x2F9133: test byte ptr [ebp+0x08], 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x8u) & 6, 8);
	// 0x2F9137: jz 0x002F915C
	if (ctx.flags.zf) goto loc_2F915C;
	// 0x2F9139: test byte ptr [ebp+0x08], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x8u) & 4, 8);
	// 0x2F913D: jz 0x002F914D
	if (ctx.flags.zf) goto loc_2F914D;
	// 0x2F913F: mov ax, [esi+0x12]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0x12u);
	// 0x2F9143: or ax, 0x1000
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) | 4096;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x2F9147: mov [esi+0x12], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x12u, X86_REG16(ctx.eax));
	// 0x2F914B: jmp 0x002F9153
	goto loc_2F9153;
loc_2F914D:
	// 0x2F914D: and word ptr [esi+0x12], 0xEFFF
	X86_MEM_WRITE_u16(base, ctx.esi + 0x12u, X86_MEM_READ_u16(base, ctx.esi + 0x12u) & -4097);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.esi + 0x12u), 16);
loc_2F9153:
	// 0x2F9153: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9155: call 0x002FAD30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAD30(ctx, base);
	ctx.esp += 4;
	// 0x2F915A: jmp 0x002F9164
	goto loc_2F9164;
loc_2F915C:
	// 0x2F915C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F915D: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F915F: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
loc_2F9164:
	// 0x2F9164: test byte ptr [ebp+0x08], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x8u) & 4, 8);
	// 0x2F9168: jnz 0x002F9176
	if (!ctx.flags.zf) goto loc_2F9176;
	// 0x2F916A: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F916C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F916D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F916E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F916F: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9171: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9173: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F9176:
	// 0x2F9176: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F9179: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F917E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F917F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9181: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9182: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9183: ret 0x04
	ctx.esp += 4;
	return;
}

void CMcpxStream_GetStatus(X86Context& ctx, uint8_t* base) {
	// 0x2F9186: movzx edx, word ptr [ecx+0x12]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx + 0x12u));
	// 0x2F918A: lea eax, [ecx+0xB0]
	ctx.eax = ctx.ecx + 0xB0u;
	// 0x2F9190: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9192: cmp [eax], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9194: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9198: setnz cl
	X86_REG8L(ctx.ecx) = (!ctx.flags.zf) ? 1 : 0;
	// 0x2F919B: test dh, 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.edx) & 32, 8);
	// 0x2F919E: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F91A0: jz 0x002F91A6
	if (ctx.flags.zf) goto loc_2F91A6;
	// 0x2F91A2: or byte ptr [eax+0x02], 0x08
	X86_MEM_WRITE_u8(base, ctx.eax + 0x2u, X86_MEM_READ_u8(base, ctx.eax + 0x2u) | 8);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x2u), 8);
loc_2F91A6:
	// 0x2F91A6: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x2F91A8: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F91AB: cmp cl, 0x03
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F91AE: jnz 0x002F91CC
	if (!ctx.flags.zf) goto loc_2F91CC;
	// 0x2F91B0: test dx, 0x444
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & 1092, 16);
	// 0x2F91B5: jz 0x002F91D7
	if (ctx.flags.zf) goto loc_2F91D7;
	// 0x2F91B7: or byte ptr [eax+0x02], 0x02
	X86_MEM_WRITE_u8(base, ctx.eax + 0x2u, X86_MEM_READ_u8(base, ctx.eax + 0x2u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x2u), 8);
	// 0x2F91BB: test dh, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.edx) & 4, 8);
	// 0x2F91BE: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F91C0: jz 0x002F91DB
	if (ctx.flags.zf) goto loc_2F91DB;
	// 0x2F91C2: or ecx, 0x40000
	ctx.ecx = ctx.ecx | 262144;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F91C8: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F91CA: jmp 0x002F91DB
	goto loc_2F91DB;
loc_2F91CC:
	// 0x2F91CC: mov ecx, 0x8001
	ctx.ecx = 32769;
	// 0x2F91D1: and edx, ecx
	ctx.edx = ctx.edx & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2F91D3: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F91D5: jnz 0x002F91DB
	if (!ctx.flags.zf) goto loc_2F91DB;
loc_2F91D7:
	// 0x2F91D7: or byte ptr [eax+0x02], 0x01
	X86_MEM_WRITE_u8(base, ctx.eax + 0x2u, X86_MEM_READ_u8(base, ctx.eax + 0x2u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x2u), 8);
loc_2F91DB:
	// 0x2F91DB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F91DD: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F91E0(X86Context& ctx, uint8_t* base) {
	// 0x2F91E0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F91E1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F91E2: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F91E4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F91E5: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F91E7: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
	// 0x2F91EC: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F91F2: mov [esi+0x190], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x190u, ctx.edi);
	// 0x2F91F8: test byte ptr [eax+0x0A], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xAu) & 4, 8);
	// 0x2F91FC: jz 0x002F920A
	if (ctx.flags.zf) goto loc_2F920A;
	// 0x2F91FE: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F9200: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9201: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9202: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9203: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9205: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9207: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F920A:
	// 0x2F920A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F920B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F920C: ret
	return;
}

void sub_2F920D(X86Context& ctx, uint8_t* base) {
	// 0x2F920D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F920E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9210: sub esp, 0x24
	{ uint32_t _d = ctx.esp; uint32_t _s = 36;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F9213: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F9216: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x2F921A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F921B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F921C: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F921F: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9222: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9223: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F9225: lea ebx, [eax+edi*1+0x88]
	ctx.ebx = ctx.eax + ctx.edi + 0x88u;
	// 0x2F922C: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2F922F: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x2F9232: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x2F9235: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2F9238: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2F923B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F923D: jz 0x002F9245
	if (ctx.flags.zf) goto loc_2F9245;
	// 0x2F923F: add [ebp-0x0C], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0xCu)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0xCu), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x2F9242: sub [ebp-0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
loc_2F9245:
	// 0x2F9245: push 0xFFFF
	{ auto _pv = (uint32_t)(65535); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F924A: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F924C: call 0x002F9033
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9033(ctx, base);
	ctx.esp += 4;
	// 0x2F9251: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9255: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x2F9258: jbe 0x002F935A
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F935A;
loc_2F925E:
	// 0x2F925E: cmp dword ptr [ebx+0x08], 0x10
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x8u); uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9262: jnb 0x002F9352
	if (!ctx.flags.cf) goto loc_2F9352;
	// 0x2F9268: mov ecx, [ebp-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F926B: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F926E: sub ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F9270: cmp ecx, [ebp-0x1C]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9273: jb 0x002F9278
	if (ctx.flags.cf) goto loc_2F9278;
	// 0x2F9275: mov ecx, [ebp-0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
loc_2F9278:
	// 0x2F9278: lea edx, [ebp-0x18]
	ctx.edx = ctx.ebp - 0x18u;
	// 0x2F927B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F927C: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F927E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F927F: mov ecx, [ebp-0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2F9282: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F9284: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9285: call 0x002FDDB4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FDDB4(ctx, base);
	ctx.esp += 4;
	// 0x2F928A: push [ebp-0x18]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x18u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F928D: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F928F: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x2F9292: call 0x002F901A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F901A(ctx, base);
	ctx.esp += 4;
	// 0x2F9297: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9298: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F929A: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x2F929D: call 0x002F9033
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9033(ctx, base);
	ctx.esp += 4;
	// 0x2F92A2: cmp dword ptr [ebp-0x20], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x20u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F92A6: mov [ebp-0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.eax);
	// 0x2F92A9: jz 0x002F9352
	if (ctx.flags.zf) goto loc_2F9352;
	// 0x2F92AF: mov eax, [edi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x80u);
	// 0x2F92B5: movzx eax, byte ptr [eax+0x0F]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0xFu));
	// 0x2F92B9: shl eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F92BB: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x2F92BC: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F92BE: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F92BF: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x2F92C1: mov [ebp-0x24], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, ctx.eax);
	// 0x2F92C4: movzx eax, byte ptr [edi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + 0x64u));
	// 0x2F92C8: lea ecx, [eax+eax*2]
	ctx.ecx = ctx.eax + ctx.eax * 2;
loc_2F92CB:
	// 0x2F92CB: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2F92D1: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2F92D4: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F92D6: jb 0x002F92CB
	if (ctx.flags.cf) goto loc_2F92CB;
	// 0x2F92D8: and dword ptr [ebp-0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, X86_MEM_READ_u32(base, ctx.ebp - 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x14u), 32);
	// 0x2F92DC: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F92DE: jbe 0x002F933A
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F933A;
	// 0x2F92E0: lea eax, [edi+0x0C]
	ctx.eax = ctx.edi + 0xCu;
loc_2F92E3:
	// 0x2F92E3: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2F92E6: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F92E9: mov esi, [edi+0x84]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi + 0x84u);
	// 0x2F92EF: lea ecx, [edx+ecx*2]
	ctx.ecx = ctx.edx + ctx.ecx * 2;
	// 0x2F92F2: shl ecx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F92F5: add ecx, [ebx+0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebx + 0x8u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F92F8: and esi, 0xFFFF0000
	ctx.esi = ctx.esi & -65536;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F92FE: or esi, [ebp-0x20]
	ctx.esi = ctx.esi | X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2F9301: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x2F9303: and ecx, 0x3FFFC0
	ctx.ecx = ctx.ecx & 4194240;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F9309: mov [0xFE820190], ecx
	X86_MEM_WRITE_u32(base, 0xFE820190u, ctx.ecx);
	// 0x2F930F: mov ecx, [ebp-0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2F9312: and edx, 0x3F
	ctx.edx = ctx.edx & 63;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2F9315: mov [edx*8-0x17DFA00], ecx
	X86_MEM_WRITE_u32(base, ctx.edx * 8 - 0x17DFA00u, ctx.ecx);
	// 0x2F931C: mov ecx, [ebp-0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x24u);
	// 0x2F931F: add [ebp-0x10], ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x10u)) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x10u), (int32_t)ctx.ecx, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, (uint32_t)_res); }
	// 0x2F9322: inc [ebp-0x14]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, (uint32_t)_res); }
	// 0x2F9325: mov [edx*8-0x17DF9FC], esi
	X86_MEM_WRITE_u32(base, ctx.edx * 8 - 0x17DF9FCu, ctx.esi);
	// 0x2F932C: movzx ecx, byte ptr [edi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + 0x64u));
	// 0x2F9330: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9331: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9332: cmp [ebp-0x14], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9335: jb 0x002F92E3
	if (ctx.flags.cf) goto loc_2F92E3;
	// 0x2F9337: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
loc_2F933A:
	// 0x2F933A: mov eax, [ebp-0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x2F933D: add [ebp-0x08], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2F9340: add [ebx+0x0C], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0xCu)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebx + 0xCu), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebx + 0xCu, (uint32_t)_res); }
	// 0x2F9343: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F9346: inc [ebx+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, (uint32_t)_res); }
	// 0x2F9349: cmp eax, [ebp-0x04]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F934C: jb 0x002F925E
	if (ctx.flags.cf) goto loc_2F925E;
loc_2F9352:
	// 0x2F9352: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F9355: cmp eax, [ebp-0x04]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9358: jb 0x002F9366
	if (ctx.flags.cf) goto loc_2F9366;
loc_2F935A:
	// 0x2F935A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F935B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F935C: call 0x002F82AB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F82AB(ctx, base);
	ctx.esp += 4;
	// 0x2F9361: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F9364: jmp 0x002F9369
	goto loc_2F9369;
loc_2F9366:
	// 0x2F9366: add [esi+0x20], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x20u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x20u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, (uint32_t)_res); }
loc_2F9369:
	// 0x2F9369: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F936A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F936B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F936C: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F936D: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F9370(X86Context& ctx, uint8_t* base) {
	// 0x2F9370: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9371: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9373: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9374: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9375: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9377: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2F937B: lea ecx, [eax+eax*1]
	ctx.ecx = ctx.eax + ctx.eax;
loc_2F937E:
	// 0x2F937E: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2F9384: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2F9387: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9389: jb 0x002F937E
	if (ctx.flags.cf) goto loc_2F937E;
	// 0x2F938B: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F938F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9391: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F9394: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9395: jbe 0x002F93E8
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F93E8;
	// 0x2F9397: lea eax, [edx+0x09]
	ctx.eax = ctx.edx + 0x9u;
	// 0x2F939A: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F939D: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F939F: mov [ebp+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.eax);
	// 0x2F93A2: lea edi, [esi+0x0C]
	ctx.edi = ctx.esi + 0xCu;
	// 0x2F93A5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F93A6:
	// 0x2F93A6: movzx eax, word ptr [edi]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi));
	// 0x2F93A9: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F93AC: mov ebx, [ebx]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F93AE: lea ecx, [edx+eax*2]
	ctx.ecx = ctx.edx + ctx.eax * 2;
	// 0x2F93B1: shl ecx, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F93B4: and ecx, 0xFFFF00
	ctx.ecx = ctx.ecx & 16776960;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F93BA: and ebx, 0xFF
	ctx.ebx = ctx.ebx & 255;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2F93C0: or ecx, ebx
	ctx.ecx = ctx.ecx | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F93C2: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2F93C4: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2F93C9: jnz 0x002F93D3
	if (!ctx.flags.zf) goto loc_2F93D3;
	// 0x2F93CB: mov [0xFE820320], ecx
	X86_MEM_WRITE_u32(base, 0xFE820320u, ctx.ecx);
	// 0x2F93D1: jmp 0x002F93D9
	goto loc_2F93D9;
loc_2F93D3:
	// 0x2F93D3: mov [0xFE82035C], ecx
	X86_MEM_WRITE_u32(base, 0xFE82035Cu, ctx.ecx);
loc_2F93D9:
	// 0x2F93D9: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2F93DC: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2F93E0: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F93E1: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F93E2: cmp [ebp-0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F93E5: jb 0x002F93A6
	if (ctx.flags.cf) goto loc_2F93A6;
	// 0x2F93E7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F93E8:
	// 0x2F93E8: mov ecx, [esi+0x68]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x68u);
	// 0x2F93EB: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x2F93ED: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F93F0: mov byte ptr [ecx+eax*1+0x0F], 0x80
	X86_MEM_WRITE_u8(base, ctx.ecx + ctx.eax + 0xFu, -128);
	// 0x2F93F5: lea eax, [esi+0x194]
	ctx.eax = ctx.esi + 0x194u;
	// 0x2F93FB: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F93FD: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F93FF: lea edi, [ecx+0x01]
	ctx.edi = ctx.ecx + 0x1u;
	// 0x2F9402: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x2F9404: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9405: jnz 0x002F940D
	if (!ctx.flags.zf) goto loc_2F940D;
	// 0x2F9407: mov [esi+0x190], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x190u, ctx.edx);
loc_2F940D:
	// 0x2F940D: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F9413: test byte ptr [eax+0x0B], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xBu) & 64, 8);
	// 0x2F9417: jnz 0x002F9428
	if (!ctx.flags.zf) goto loc_2F9428;
	// 0x2F9419: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F941B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F941D: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F941F: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9421: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9423: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9425: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F9428:
	// 0x2F9428: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F942A: call 0x002FBAC1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FBAC1(ctx, base);
	ctx.esp += 4;
	// 0x2F942F: movzx eax, word ptr [esi+0x12]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x12u));
	// 0x2F9433: and eax, 0xFFFFFBFF
	ctx.eax = ctx.eax & -1025;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9438: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9439: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F943B: call 0x002FAE08
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAE08(ctx, base);
	ctx.esp += 4;
	// 0x2F9440: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9441: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9442: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9445(X86Context& ctx, uint8_t* base) {
	// 0x2F9445: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9446: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9447: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F944B: mov eax, [esi+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x2F944E: cmp eax, 0x8000000A
	{ uint32_t _d = ctx.eax; uint32_t _s = -2147483638;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9453: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9454: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2F9456: jz 0x002F945C
	if (ctx.flags.zf) goto loc_2F945C;
	// 0x2F9458: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
loc_2F945C:
	// 0x2F945C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F945E: push [esi+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9461: lea edi, [esi+0x08]
	ctx.edi = ctx.esi + 0x8u;
	// 0x2F9464: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9466: call [0x0036B944]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B944u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F946C: push [esp+0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9470: mov eax, [ebx+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x80u);
	// 0x2F9476: push [eax+0xC4]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xC4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F947C: push [eax+0xC0]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xC0u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9482: push [esi+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9485: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9486: call 0x002F8F9D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8F9D(ctx, base);
	ctx.esp += 4;
	// 0x2F948B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F948C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F948D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F948E: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F9491(X86Context& ctx, uint8_t* base) {
	// 0x2F9491: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9492: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9493: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9494: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9496: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9498: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
	// 0x2F949D: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F949F: lea edi, [esi+0xD8]
	ctx.edi = ctx.esi + 0xD8u;
loc_2F94A5:
	// 0x2F94A5: test byte ptr [edi], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.edi) & 1, 8);
	// 0x2F94A8: jz 0x002F94B2
	if (ctx.flags.zf) goto loc_2F94B2;
	// 0x2F94AA: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F94AC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F94AD: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F94AF: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F94B2:
	// 0x2F94B2: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F94B3: add edi, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)32, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F94B6: cmp ebx, 0x06
	{ uint32_t _d = ctx.ebx; uint32_t _s = 6;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F94B9: jb 0x002F94A5
	if (ctx.flags.cf) goto loc_2F94A5;
	// 0x2F94BB: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2F94BE: mov dx, 0x3111
	X86_REG16(ctx.edx) = (uint16_t)(12561);
	// 0x2F94C2: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
	// 0x2F94C7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F94C8: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F94CA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F94CB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F94CC: jmp 0x002FA66C
	sub_2FA66C(ctx, base);
	return;
}

void sub_2F94D1(X86Context& ctx, uint8_t* base) {
	// 0x2F94D1: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F94D5: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F94D9: shl eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F94DC: lea eax, [eax+ecx*1+0xD0]
	ctx.eax = ctx.eax + ctx.ecx + 0xD0u;
	// 0x2F94E3: mov [eax+0x18], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x18u, ctx.edx);
	// 0x2F94E6: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F94EA: mov [eax+0x1C], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1Cu, ctx.edx);
	// 0x2F94ED: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F94F1: mov [eax+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.edx);
	// 0x2F94F4: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F94F7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F94F8: call 0x002F8E3A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8E3A(ctx, base);
	ctx.esp += 4;
	// 0x2F94FD: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F9500(X86Context& ctx, uint8_t* base) {
	// 0x2F9500: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9504: shl eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9507: lea eax, [eax+ecx*1+0xD0]
	ctx.eax = ctx.eax + ctx.ecx + 0xD0u;
	// 0x2F950E: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2F9511: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9512: call 0x002F8C5D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8C5D(ctx, base);
	ctx.esp += 4;
	// 0x2F9517: ret 0x04
	ctx.esp += 4;
	return;
}

void DirectSound_AddRef_DirectSound_CDirectSound(X86Context& ctx, uint8_t* base) {
	// 0x2F951A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F951B: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F951F: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F9521: jz 0x002F9529
	if (ctx.flags.zf) goto loc_2F9529;
	// 0x2F9523: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F9525: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9526: call [eax+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F9529:
	// 0x2F9529: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F952B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F952C: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F952F(X86Context& ctx, uint8_t* base) {
	// 0x2F952F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9530: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9534: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9536: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F953A: call 0x002FB651
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB651(ctx, base);
	ctx.esp += 4;
	// 0x2F953F: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9543: mov dword ptr [esi], 0x36C21C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588636);
	// 0x2F9549: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2F954E: mov [esi+0x80], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x80u, ctx.eax);
	// 0x2F9554: lea eax, [esi+0xB0]
	ctx.eax = ctx.esi + 0xB0u;
	// 0x2F955A: mov [esi+0xB4], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xB4u, ctx.eax);
	// 0x2F9560: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F9562: lea eax, [esi+0xA8]
	ctx.eax = ctx.esi + 0xA8u;
	// 0x2F9568: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F956A: mov [esi+0xAC], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xACu, ctx.eax);
	// 0x2F9570: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F9572: lea eax, [esi+0xB8]
	ctx.eax = ctx.esi + 0xB8u;
	// 0x2F9578: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9579: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F957B: mov [esi+0xBC], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xBCu, ctx.eax);
	// 0x2F9581: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F9583: lea eax, [esi+0x88]
	ctx.eax = ctx.esi + 0x88u;
	// 0x2F9589: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F958A:
	// 0x2F958A: mov [eax+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.eax);
	// 0x2F958D: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F958F: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9591: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F9592: jnz 0x002F958A
	if (!ctx.flags.zf) goto loc_2F958A;
	// 0x2F9594: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9596: lea eax, [esi+0xD0]
	ctx.eax = ctx.esi + 0xD0u;
loc_2F959C:
	// 0x2F959C: mov [eax+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.ecx);
	// 0x2F959F: mov [eax+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.eax);
	// 0x2F95A2: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2F95A4: mov [eax+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.esi);
	// 0x2F95A7: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F95A8: add eax, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)32, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F95AB: cmp ecx, 0x06
	{ uint32_t _d = ctx.ecx; uint32_t _s = 6;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F95AE: jb 0x002F959C
	if (ctx.flags.cf) goto loc_2F959C;
	// 0x2F95B0: or dword ptr [esi+0xD8], 0x05
	X86_MEM_WRITE_u32(base, ctx.esi + 0xD8u, X86_MEM_READ_u32(base, ctx.esi + 0xD8u) | 5);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xD8u), 32);
	// 0x2F95B7: or dword ptr [esi+0xF8], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0xF8u, X86_MEM_READ_u32(base, ctx.esi + 0xF8u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xF8u), 32);
	// 0x2F95BE: or dword ptr [esi+0x118], 0x05
	X86_MEM_WRITE_u32(base, ctx.esi + 0x118u, X86_MEM_READ_u32(base, ctx.esi + 0x118u) | 5);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x118u), 32);
	// 0x2F95C5: or dword ptr [esi+0x138], 0x05
	X86_MEM_WRITE_u32(base, ctx.esi + 0x138u, X86_MEM_READ_u32(base, ctx.esi + 0x138u) | 5);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x138u), 32);
	// 0x2F95CC: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2F95CF: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2F95D4: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F95D6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F95D7: ret 0x08
	ctx.esp += 8;
	return;
}

void CMcpxStream_Stop_Ex(X86Context& ctx, uint8_t* base) {
	// 0x2F95DA: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95DB: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F95DD: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F95E0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95E1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95E2: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F95E4: or eax, [ebp+0x0C]
	ctx.eax = ctx.eax | X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F95E7: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F95E9: jz 0x002F95FF
	if (ctx.flags.zf) goto loc_2F95FF;
	// 0x2F95EB: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95EE: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F95F0: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95F3: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95F6: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F95F8: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F95FB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F95FD: jnz 0x002F960B
	if (!ctx.flags.zf) goto loc_2F960B;
loc_2F95FF:
	// 0x2F95FF: push [ebp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9602: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9604: call 0x002F9114
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Stop(ctx, base);
	ctx.esp += 4;
	// 0x2F9609: mov edi, eax
	ctx.edi = ctx.eax;
loc_2F960B:
	// 0x2F960B: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F960D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F960E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F960F: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9610: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F9613(X86Context& ctx, uint8_t* base) {
	// 0x2F9613: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9614: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9616: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9617: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F961B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F961C: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F961F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9620: lea eax, [ebx+0x09]
	ctx.eax = ctx.ebx + 0x9u;
	// 0x2F9623: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9626: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9628: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9629: lea edi, [eax+esi*1]
	ctx.edi = ctx.eax + ctx.esi;
	// 0x2F962C: cmp dword ptr [edi], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F962F: jnz 0x002F9670
	if (!ctx.flags.zf) goto loc_2F9670;
loc_2F9631:
	// 0x2F9631: lea ecx, [esi+0xA8]
	ctx.ecx = ctx.esi + 0xA8u;
	// 0x2F9637: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F9639: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F963B: jz 0x002F9662
	if (ctx.flags.zf) goto loc_2F9662;
	// 0x2F963D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F963E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F963F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9641: call 0x002F920D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F920D(ctx, base);
	ctx.esp += 4;
	// 0x2F9646: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9648: jz 0x002F9662
	if (ctx.flags.zf) goto loc_2F9662;
	// 0x2F964A: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F9650: test byte ptr [eax+0x0B], 0x60
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xBu) & 96, 8);
	// 0x2F9654: mov dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1);
	// 0x2F965B: jnz 0x002F9668
	if (!ctx.flags.zf) goto loc_2F9668;
	// 0x2F965D: cmp dword ptr [edi], 0x10
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9660: jb 0x002F9631
	if (ctx.flags.cf) goto loc_2F9631;
loc_2F9662:
	// 0x2F9662: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9666: jz 0x002F9670
	if (ctx.flags.zf) goto loc_2F9670;
loc_2F9668:
	// 0x2F9668: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9669: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F966B: call 0x002F9370
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9370(ctx, base);
	ctx.esp += 4;
loc_2F9670:
	// 0x2F9670: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F9673: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9674: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9675: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9676: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9677: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F967A(X86Context& ctx, uint8_t* base) {
	// 0x2F967A: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F967B: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F967D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F967E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F967F: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F9683: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9684: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9685: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F9688: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9689: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F968B: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F968E: lea ebx, [edi+0xB8]
	ctx.ebx = ctx.edi + 0xB8u;
	// 0x2F9694: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F9699: cmp ebx, esi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F969B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F969C: jnz 0x002F96D7
	if (!ctx.flags.zf) goto loc_2F96D7;
	// 0x2F969E: jmp 0x002F96B4
	goto loc_2F96B4;
loc_2F96A0:
	// 0x2F96A0: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F96A3: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F96A5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F96A6: call 0x002F9445
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9445(ctx, base);
	ctx.esp += 4;
	// 0x2F96AB: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F96AE: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F96B3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F96B4:
	// 0x2F96B4: lea eax, [edi+0xB0]
	ctx.eax = ctx.edi + 0xB0u;
	// 0x2F96BA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F96BB: call 0x002F8FE1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8FE1(ctx, base);
	ctx.esp += 4;
	// 0x2F96C0: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F96C3: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2F96C5: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F96CA: cmp ebx, esi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F96CC: jnz 0x002F96A0
	if (!ctx.flags.zf) goto loc_2F96A0;
	// 0x2F96CE: jmp 0x002F96E9
	goto loc_2F96E9;
loc_2F96D0:
	// 0x2F96D0: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2F96D3: mov [eax+0x24], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x24u, ctx.ecx);
	// 0x2F96D6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F96D7:
	// 0x2F96D7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F96D8: call 0x002F8FE1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8FE1(ctx, base);
	ctx.esp += 4;
	// 0x2F96DD: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F96DF: jnz 0x002F96D0
	if (!ctx.flags.zf) goto loc_2F96D0;
	// 0x2F96E1: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F96E4: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
loc_2F96E9:
	// 0x2F96E9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F96EA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F96EB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F96EC: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F96ED: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F96F0(X86Context& ctx, uint8_t* base) {
	// 0x2F96F0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F96F1: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F96F3: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2F96F6: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2F96F8: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F96FA: jz 0x002F9703
	if (ctx.flags.zf) goto loc_2F9703;
	// 0x2F96FC: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F96FE: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9700: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F9703:
	// 0x2F9703: push 0x8000000A
	{ auto _pv = (uint32_t)(-2147483638); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9708: lea eax, [esi+0xB8]
	ctx.eax = ctx.esi + 0xB8u;
	// 0x2F970E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F970F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9711: call 0x002F967A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F967A(ctx, base);
	ctx.esp += 4;
	// 0x2F9716: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9717: ret
	return;
}

void CMcpxStream_Discontinuity(X86Context& ctx, uint8_t* base) {
	// 0x2F9718: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9719: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F971A: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F971C: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F971E: call 0x002F9055
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9055(ctx, base);
	ctx.esp += 4;
	// 0x2F9723: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9725: jz 0x002F9735
	if (ctx.flags.zf) goto loc_2F9735;
	// 0x2F9727: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2F972A: mov dx, 0x800
	X86_REG16(ctx.edx) = (uint16_t)(2048);
	// 0x2F972E: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2F9733: jmp 0x002F9740
	goto loc_2F9740;
loc_2F9735:
	// 0x2F9735: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9737: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9739: call 0x002F9114
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Stop(ctx, base);
	ctx.esp += 4;
	// 0x2F973E: mov edi, eax
	ctx.edi = ctx.eax;
loc_2F9740:
	// 0x2F9740: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F9742: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9743: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9744: ret
	return;
}

void sub_2F9745(X86Context& ctx, uint8_t* base) {
	// 0x2F9745: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9746: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9748: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9749: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F974A: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F974E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F974F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9750: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9752: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F9755: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F975A: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F975D: lea ecx, [eax+0x09]
	ctx.ecx = ctx.eax + 0x9u;
	// 0x2F9760: shl ecx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F9763: lea ebx, [ecx+esi*1]
	ctx.ebx = ctx.ecx + ctx.esi;
	// 0x2F9766: cmp dword ptr [ebx], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9769: jz 0x002F97FA
	if (ctx.flags.zf) goto loc_2F97FA;
	// 0x2F976F: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2F9773: lea edx, [ecx+ecx*1]
	ctx.edx = ctx.ecx + ctx.ecx;
	// 0x2F9776: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F9777:
	// 0x2F9777: mov edi, [0xFE820010]
	ctx.edi = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2F977D: shr edi, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (_cnt - 1)) & 1;
	  ctx.edi = (uint32_t)(ctx.edi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x2F9780: cmp edi, edx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9782: jb 0x002F9777
	if (ctx.flags.cf) goto loc_2F9777;
	// 0x2F9784: and dword ptr [ebp+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, X86_MEM_READ_u32(base, ctx.ebp + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
	// 0x2F9788: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F978A: jbe 0x002F97C4
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F97C4;
	// 0x2F978C: lea edi, [esi+0x0C]
	ctx.edi = ctx.esi + 0xCu;
loc_2F978F:
	// 0x2F978F: movzx ecx, word ptr [edi]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi));
	// 0x2F9792: lea edx, [eax+ecx*2]
	ctx.edx = ctx.eax + ctx.ecx * 2;
	// 0x2F9795: shl edx, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2F9798: and edx, 0xFFFF00
	ctx.edx = ctx.edx & 16776960;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2F979E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F97A0: mov [0xFE8202F8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.ecx);
	// 0x2F97A6: jnz 0x002F97B0
	if (!ctx.flags.zf) goto loc_2F97B0;
	// 0x2F97A8: mov [0xFE820320], edx
	X86_MEM_WRITE_u32(base, 0xFE820320u, ctx.edx);
	// 0x2F97AE: jmp 0x002F97B6
	goto loc_2F97B6;
loc_2F97B0:
	// 0x2F97B0: mov [0xFE82035C], edx
	X86_MEM_WRITE_u32(base, 0xFE82035Cu, ctx.edx);
loc_2F97B6:
	// 0x2F97B6: inc [ebp+0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x2F97B9: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2F97BD: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F97BE: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F97BF: cmp [ebp+0x08], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F97C2: jb 0x002F978F
	if (ctx.flags.cf) goto loc_2F978F;
loc_2F97C4:
	// 0x2F97C4: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F97C7: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F97CA: lea edi, [eax+esi*1]
	ctx.edi = ctx.eax + ctx.esi;
	// 0x2F97CD: lea eax, [edi+0x88]
	ctx.eax = ctx.edi + 0x88u;
	// 0x2F97D3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F97D4: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F97D6: call 0x002F967A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F967A(ctx, base);
	ctx.esp += 4;
	// 0x2F97DB: and dword ptr [edi+0x94], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi + 0x94u, X86_MEM_READ_u32(base, ctx.edi + 0x94u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi + 0x94u), 32);
	// 0x2F97E2: and dword ptr [ebx], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebx, X86_MEM_READ_u32(base, ctx.ebx) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebx), 32);
	// 0x2F97E5: dec [esi+0x194]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x194u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x194u, (uint32_t)_res); }
	// 0x2F97EB: lea eax, [esi+0x190]
	ctx.eax = ctx.esi + 0x190u;
	// 0x2F97F1: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F97F3: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F97F4: and ecx, 0x01
	ctx.ecx = ctx.ecx & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F97F7: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F97F9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F97FA:
	// 0x2F97FA: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2F97FD: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F9802: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9803: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9804: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9805: ret 0x08
	ctx.esp += 8;
	return;
}

void CMcpxStream_Flush(X86Context& ctx, uint8_t* base) {
	// 0x2F9808: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9809: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F980B: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F980E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F980F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9810: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9812: movzx eax, byte ptr fs:[0x00000024]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, 0x24u));
	// 0x2F981A: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F981C: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2F9820: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x2F9823: mov [ebp-0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edi);
	// 0x2F9826: jz 0x002F98D6
	if (ctx.flags.zf) goto loc_2F98D6;
	// 0x2F982C: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F982F: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
loc_2F9834:
	// 0x2F9834: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F9836: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9837: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9839: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F983C: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F983D: cmp edi, 0x06
	{ uint32_t _d = ctx.edi; uint32_t _s = 6;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9840: jb 0x002F9834
	if (ctx.flags.cf) goto loc_2F9834;
	// 0x2F9842: mov edi, [esi+0x190]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x190u);
	// 0x2F9848: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9849: mov dword ptr [ebp-0x08], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, 2);
	// 0x2F9850: mov ebx, 0x80004004
	ctx.ebx = -2147467260;
loc_2F9855:
	// 0x2F9855: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9856: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9857: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9859: call 0x002F9745
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9745(ctx, base);
	ctx.esp += 4;
	// 0x2F985E: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F985F: and edi, 0x01
	ctx.edi = ctx.edi & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2F9862: dec [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2F9865: jnz 0x002F9855
	if (!ctx.flags.zf) goto loc_2F9855;
	// 0x2F9867: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9869: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F986A: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F986C: mov [esi+0x190], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x190u, ctx.edi);
	// 0x2F9872: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
	// 0x2F9877: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F987A: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F987F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9881: call 0x002FB5CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB5CC(ctx, base);
	ctx.esp += 4;
	// 0x2F9886: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9887: lea eax, [esi+0xA8]
	ctx.eax = ctx.esi + 0xA8u;
	// 0x2F988D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F988E: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9890: call 0x002F967A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F967A(ctx, base);
	ctx.esp += 4;
	// 0x2F9895: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F989B: test byte ptr [eax+0x0A], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xAu) & 4, 8);
	// 0x2F989F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F98A0: jz 0x002F98BB
	if (ctx.flags.zf) goto loc_2F98BB;
	// 0x2F98A2: cmp byte ptr [ebp-0x01], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x1u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F98A6: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F98A8: jnz 0x002F98B1
	if (!ctx.flags.zf) goto loc_2F98B1;
	// 0x2F98AA: call 0x002F9491
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9491(ctx, base);
	ctx.esp += 4;
	// 0x2F98AF: jmp 0x002F98C1
	goto loc_2F98C1;
loc_2F98B1:
	// 0x2F98B1: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F98B3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98B4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98B5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98B6: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98B8: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F98BB:
	// 0x2F98BB: cmp byte ptr [ebp-0x01], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebp - 0x1u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F98BF: jnz 0x002F98CA
	if (!ctx.flags.zf) goto loc_2F98CA;
loc_2F98C1:
	// 0x2F98C1: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F98C3: call 0x002F96F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F96F0(ctx, base);
	ctx.esp += 4;
	// 0x2F98C8: jmp 0x002F98D6
	goto loc_2F98D6;
loc_2F98CA:
	// 0x2F98CA: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F98CC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98CD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98CE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98CF: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98D1: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F98D3: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F98D6:
	// 0x2F98D6: cmp dword ptr [ebp+0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F98DA: jnz 0x002F98E2
	if (!ctx.flags.zf) goto loc_2F98E2;
	// 0x2F98DC: and word ptr [esi+0x12], 0xCFFF
	X86_MEM_WRITE_u16(base, ctx.esi + 0x12u, X86_MEM_READ_u16(base, ctx.esi + 0x12u) & -12289);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.esi + 0x12u), 16);
loc_2F98E2:
	// 0x2F98E2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F98E3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F98E4: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F98E5: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F98E8(X86Context& ctx, uint8_t* base) {
	// 0x2F98E8: test word ptr [ecx+0x12], 0x8002
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.ecx + 0x12u) & -32766, 16);
	// 0x2F98EE: jnz 0x002F98F7
	if (!ctx.flags.zf) goto loc_2F98F7;
	// 0x2F98F0: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98F2: call 0x002F9808
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Flush(ctx, base);
	ctx.esp += 4;
loc_2F98F7:
	// 0x2F98F7: ret
	return;
}

void sub_2F98F8(X86Context& ctx, uint8_t* base) {
	// 0x2F98F8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F98F9: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F98FB: sub esp, 0x14
	{ uint32_t _d = ctx.esp; uint32_t _s = 20;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F98FE: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F9902: and dword ptr [ebp-0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, X86_MEM_READ_u32(base, ctx.ebp - 0x10u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x10u), 32);
	// 0x2F9906: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9907: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9909: lea ecx, [ebp-0x14]
	ctx.ecx = ctx.ebp - 0x14u;
	// 0x2F990C: mov dword ptr [ebp-0x0C], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, 1);
	// 0x2F9913: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F9918: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9919: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2F991A:
	// 0x2F991A: mov edi, [esi+0x190]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x190u);
	// 0x2F9920: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
loc_2F9924:
	// 0x2F9924: lea ebx, [esi+0x68]
	ctx.ebx = ctx.esi + 0x68u;
	// 0x2F9927: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9928: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2F992A: call 0x002F8FFC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8FFC(ctx, base);
	ctx.esp += 4;
	// 0x2F992F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9931: jz 0x002F9976
	if (ctx.flags.zf) goto loc_2F9976;
	// 0x2F9933: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9935: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9936: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9938: call 0x002F9745
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9745(ctx, base);
	ctx.esp += 4;
	// 0x2F993D: or dword ptr [ebp-0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F9941: test word ptr [esi+0x12], 0x1000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0x12u) & 4096, 16);
	// 0x2F9947: jz 0x002F9969
	if (ctx.flags.zf) goto loc_2F9969;
	// 0x2F9949: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F994B: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2F994D: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9950: cmp byte ptr [eax+ecx*1+0x0E], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.eax + ctx.ecx + 0xEu); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9955: jnz 0x002F9969
	if (!ctx.flags.zf) goto loc_2F9969;
	// 0x2F9957: and word ptr [esi+0x12], 0xEFFF
	X86_MEM_WRITE_u16(base, ctx.esi + 0x12u, X86_MEM_READ_u16(base, ctx.esi + 0x12u) & -4097);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.esi + 0x12u), 16);
	// 0x2F995D: mov ax, [esi+0x12]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0x12u);
	// 0x2F9961: or ax, 0x2000
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) | 8192;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x2F9965: mov [esi+0x12], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x12u, X86_REG16(ctx.eax));
loc_2F9969:
	// 0x2F9969: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F996A: and edi, 0x01
	ctx.edi = ctx.edi & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2F996D: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2F9970: cmp dword ptr [ebp-0x08], 0x02
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9974: jb 0x002F9924
	if (ctx.flags.cf) goto loc_2F9924;
loc_2F9976:
	// 0x2F9976: test word ptr [esi+0x12], 0x2000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0x12u) & 8192, 16);
	// 0x2F997C: jnz 0x002F99B9
	if (!ctx.flags.zf) goto loc_2F99B9;
	// 0x2F997E: mov edi, [esi+0x194]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x194u);
	// 0x2F9984: add edi, [esi+0x190]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x190u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x190u), 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F998A: and edi, 0x01
	ctx.edi = ctx.edi & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2F998D: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F998F:
	// 0x2F998F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9990: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9992: call 0x002F9613
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9613(ctx, base);
	ctx.esp += 4;
	// 0x2F9997: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9999: jz 0x002F99AB
	if (ctx.flags.zf) goto loc_2F99AB;
	// 0x2F999B: or dword ptr [ebp-0x04], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2F999F: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F99A0: and edi, 0x01
	ctx.edi = ctx.edi & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2F99A3: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F99A4: cmp ebx, 0x02
	{ uint32_t _d = ctx.ebx; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F99A7: jb 0x002F998F
	if (ctx.flags.cf) goto loc_2F998F;
	// 0x2F99A9: jmp 0x002F99AF
	goto loc_2F99AF;
loc_2F99AB:
	// 0x2F99AB: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
loc_2F99AF:
	// 0x2F99AF: cmp dword ptr [ebp-0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F99B3: jnz 0x002F991A
	if (!ctx.flags.zf) goto loc_2F991A;
loc_2F99B9:
	// 0x2F99B9: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F99BF: test byte ptr [eax+0x0B], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xBu) & 64, 8);
	// 0x2F99C3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F99C4: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F99C5: jz 0x002F99CE
	if (ctx.flags.zf) goto loc_2F99CE;
	// 0x2F99C7: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F99C9: call 0x002F96F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F96F0(ctx, base);
	ctx.esp += 4;
loc_2F99CE:
	// 0x2F99CE: lea ecx, [ebp-0x14]
	ctx.ecx = ctx.ebp - 0x14u;
	// 0x2F99D1: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F99D6: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F99D9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F99DA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F99DB: ret
	return;
}

void sub_2F99DC(X86Context& ctx, uint8_t* base) {
	// 0x2F99DC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F99DD: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F99DF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F99E0: lea edi, [esi+0x68]
	ctx.edi = ctx.esi + 0x68u;
	// 0x2F99E3: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F99E5: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F99E7: call 0x002F8FFC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8FFC(ctx, base);
	ctx.esp += 4;
	// 0x2F99EC: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F99EE: jz 0x002F9A1B
	if (ctx.flags.zf) goto loc_2F9A1B;
	// 0x2F99F0: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F99F2: mov byte ptr [eax+0x3F], 0x80
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3Fu, -128);
	// 0x2F99F6: lea eax, [esi+0x12]
	ctx.eax = ctx.esi + 0x12u;
	// 0x2F99F9: test word ptr [eax], 0x1000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.eax) & 4096, 16);
	// 0x2F99FE: jz 0x002F9A10
	if (ctx.flags.zf) goto loc_2F9A10;
	// 0x2F9A00: and word ptr [eax], 0xEFFF
	X86_MEM_WRITE_u16(base, ctx.eax, X86_MEM_READ_u16(base, ctx.eax) & -4097);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.eax), 16);
	// 0x2F9A05: mov cx, [eax]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.eax);
	// 0x2F9A08: or cx, 0x2000
	X86_REG16(ctx.ecx) = X86_REG16(ctx.ecx) | 8192;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.ecx), 16);
	// 0x2F9A0D: mov [eax], cx
	X86_MEM_WRITE_u16(base, ctx.eax, X86_REG16(ctx.ecx));
loc_2F9A10:
	// 0x2F9A10: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A12: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A14: call 0x002F9808
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Flush(ctx, base);
	ctx.esp += 4;
	// 0x2F9A19: jmp 0x002F9A5E
	goto loc_2F9A5E;
loc_2F9A1B:
	// 0x2F9A1B: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2F9A1E: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2F9A20: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9A22: jnz 0x002F9A5E
	if (!ctx.flags.zf) goto loc_2F9A5E;
	// 0x2F9A24: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A26: call 0x002F98F8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F98F8(ctx, base);
	ctx.esp += 4;
	// 0x2F9A2B: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2F9A2D: cmp al, 0x01
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9A2F: jnz 0x002F9A5E
	if (!ctx.flags.zf) goto loc_2F9A5E;
	// 0x2F9A31: cmp dword ptr [esi+0x194], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x194u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9A38: jnz 0x002F9A5E
	if (!ctx.flags.zf) goto loc_2F9A5E;
	// 0x2F9A3A: test word ptr [esi+0x12], 0x2800
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0x12u) & 10240, 16);
	// 0x2F9A40: jz 0x002F9A4B
	if (ctx.flags.zf) goto loc_2F9A4B;
	// 0x2F9A42: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A44: call 0x002F91E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F91E0(ctx, base);
	ctx.esp += 4;
	// 0x2F9A49: jmp 0x002F9A5E
	goto loc_2F9A5E;
loc_2F9A4B:
	// 0x2F9A4B: mov eax, 0x400
	ctx.eax = 1024;
	// 0x2F9A50: test [esi+0x12], ax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0x12u) & X86_REG16(ctx.eax), 16);
	// 0x2F9A54: jnz 0x002F9A5E
	if (!ctx.flags.zf) goto loc_2F9A5E;
	// 0x2F9A56: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A57: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A59: call 0x002FAE08
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAE08(ctx, base);
	ctx.esp += 4;
loc_2F9A5E:
	// 0x2F9A5E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9A60: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9A61: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9A62: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9A63: ret
	return;
}

void sub_2F9A64(X86Context& ctx, uint8_t* base) {
	// 0x2F9A64: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A65: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9A67: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A68: mov dword ptr [esi], 0x36C21C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588636);
	// 0x2F9A6E: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2F9A70:
	// 0x2F9A70: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A71: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A73: call 0x002F9500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9500(ctx, base);
	ctx.esp += 4;
	// 0x2F9A78: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2F9A79: cmp edi, 0x06
	{ uint32_t _d = ctx.edi; uint32_t _s = 6;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9A7C: jb 0x002F9A70
	if (ctx.flags.cf) goto loc_2F9A70;
	// 0x2F9A7E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A80: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A82: call 0x002F9808
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Flush(ctx, base);
	ctx.esp += 4;
	// 0x2F9A87: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9A89: call 0x002F9491
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9491(ctx, base);
	ctx.esp += 4;
	// 0x2F9A8E: lea edi, [esi+0x80]
	ctx.edi = ctx.esi + 0x80u;
	// 0x2F9A94: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F9A96: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9A98: jz 0x002F9AA3
	if (ctx.flags.zf) goto loc_2F9AA3;
	// 0x2F9A9A: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F9A9C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9A9D: call [ecx+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F9AA0: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
loc_2F9AA3:
	// 0x2F9AA3: lea edi, [esi+0xC0]
	ctx.edi = ctx.esi + 0xC0u;
	// 0x2F9AA9: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2F9AAB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9AAD: jz 0x002F9AB8
	if (ctx.flags.zf) goto loc_2F9AB8;
	// 0x2F9AAF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9AB0: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F9AB5: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
loc_2F9AB8:
	// 0x2F9AB8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9AB9: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9ABB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9ABC: jmp 0x002FBA89
	sub_2FBA89(ctx, base);
	return;
}

void sub_2F9AC1(X86Context& ctx, uint8_t* base) {
	// 0x2F9AC1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9AC2: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9AC4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9AC6: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2F9AC9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9ACA: and eax, 0x01
	ctx.eax = ctx.eax & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9ACD: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F9ACF: jz 0x002F9AF3
	if (ctx.flags.zf) goto loc_2F9AF3;
	// 0x2F9AD1: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9AD3: call 0x002F9808
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Flush(ctx, base);
	ctx.esp += 4;
	// 0x2F9AD8: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F9ADE: movzx eax, byte ptr [eax+0x0E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0xEu));
	// 0x2F9AE2: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9AE3: sar eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9AE5: inc al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x2F9AE7: cmp al, [esi+0x64]
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0x64u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9AEA: jz 0x002F9AF3
	if (ctx.flags.zf) goto loc_2F9AF3;
	// 0x2F9AEC: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9AEE: call 0x002F9491
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9491(ctx, base);
	ctx.esp += 4;
loc_2F9AF3:
	// 0x2F9AF3: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9AF5: call 0x002FA559
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA559(ctx, base);
	ctx.esp += 4;
	// 0x2F9AFA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9AFC: jl 0x002F9BAD
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F9BAD;
	// 0x2F9B02: mov edx, [esi+0x80]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2F9B08: movzx ecx, word ptr [edx+0x0C]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx + 0xCu));
	// 0x2F9B0C: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F9B0D: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9B0E: jz 0x002F9B2D
	if (ctx.flags.zf) goto loc_2F9B2D;
	// 0x2F9B10: sub ecx, 0x68
	{ uint32_t _d = ctx.ecx; uint32_t _s = 104;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F9B13: jnz 0x002F9B65
	if (!ctx.flags.zf) goto loc_2F9B65;
	// 0x2F9B15: lea ecx, [esi+0x84]
	ctx.ecx = ctx.esi + 0x84u;
	// 0x2F9B1B: mov ebx, [ecx]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F9B1D: and ebx, 0xFFFEFFFF
	ctx.ebx = ctx.ebx & -65537;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2F9B23: or ebx, 0x20000
	ctx.ebx = ctx.ebx | 131072;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
loc_2F9B29:
	// 0x2F9B29: mov [ecx], ebx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ebx);
	// 0x2F9B2B: jmp 0x002F9B65
	goto loc_2F9B65;
loc_2F9B2D:
	// 0x2F9B2D: mov cl, [edx+0x0F]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edx + 0xFu);
	// 0x2F9B30: cmp cl, 0x08
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9B33: jz 0x002F9B5E
	if (ctx.flags.zf) goto loc_2F9B5E;
	// 0x2F9B35: cmp cl, 0x10
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9B38: jz 0x002F9B48
	if (ctx.flags.zf) goto loc_2F9B48;
	// 0x2F9B3A: cmp cl, 0x20
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9B3D: jnz 0x002F9B65
	if (!ctx.flags.zf) goto loc_2F9B65;
	// 0x2F9B3F: or byte ptr [esi+0x86], 0x03
	X86_MEM_WRITE_u8(base, ctx.esi + 0x86u, X86_MEM_READ_u8(base, ctx.esi + 0x86u) | 3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x86u), 8);
	// 0x2F9B46: jmp 0x002F9B65
	goto loc_2F9B65;
loc_2F9B48:
	// 0x2F9B48: lea ecx, [esi+0x84]
	ctx.ecx = ctx.esi + 0x84u;
	// 0x2F9B4E: mov ebx, [ecx]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F9B50: and ebx, 0xFFFDFFFF
	ctx.ebx = ctx.ebx & -131073;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2F9B56: or ebx, 0x10000
	ctx.ebx = ctx.ebx | 65536;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2F9B5C: jmp 0x002F9B29
	goto loc_2F9B29;
loc_2F9B5E:
	// 0x2F9B5E: and byte ptr [esi+0x86], 0xFC
	X86_MEM_WRITE_u8(base, ctx.esi + 0x86u, X86_MEM_READ_u8(base, ctx.esi + 0x86u) & -4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x86u), 8);
loc_2F9B65:
	// 0x2F9B65: movzx ecx, byte ptr [edx+0x0E]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.edx + 0xEu));
	// 0x2F9B69: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2F9B6A: shl ecx, 0x12
	{ auto _cnt = 0x12u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2F9B6D: xor ecx, [esi+0x84]
	ctx.ecx = ctx.ecx ^ X86_MEM_READ_u32(base, ctx.esi + 0x84u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F9B73: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9B74: and ecx, 0x7C0000
	ctx.ecx = ctx.ecx & 8126464;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F9B7A: xor [esi+0x84], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, X86_MEM_READ_u32(base, ctx.esi + 0x84u) ^ ctx.ecx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x84u), 32);
	// 0x2F9B80: cmp byte ptr [edx+0x0E], 0x01
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.edx + 0xEu); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9B84: mov ecx, [esi+0x84]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x84u);
	// 0x2F9B8A: jbe 0x002F9B94
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F9B94;
	// 0x2F9B8C: or ecx, 0x800000
	ctx.ecx = ctx.ecx | 8388608;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2F9B92: jmp 0x002F9B9A
	goto loc_2F9B9A;
loc_2F9B94:
	// 0x2F9B94: and ecx, 0xFF7FFFFF
	ctx.ecx = ctx.ecx & -8388609;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_2F9B9A:
	// 0x2F9B9A: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2F9B9C: mov [esi+0x84], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, ctx.ecx);
	// 0x2F9BA2: jz 0x002F9BAD
	if (ctx.flags.zf) goto loc_2F9BAD;
	// 0x2F9BA4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9BA5: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9BA7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9BA8: jmp 0x002FB267
	sub_2FB267(ctx, base);
	return;
loc_2F9BAD:
	// 0x2F9BAD: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9BAE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9BAF: ret
	return;
}

void sub_2F9BB0(X86Context& ctx, uint8_t* base) {
	// 0x2F9BB0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BB1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9BB3: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2F9BB6: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2F9BBA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BBB: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BBE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9BC0: mov [ebp-0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.esi);
	// 0x2F9BC3: call 0x002F8F7F
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8F7F(ctx, base);
	ctx.esp += 4;
	// 0x2F9BC8: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2F9BCB: test word ptr [ecx], 0x2000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.ecx) & 8192, 16);
	// 0x2F9BD0: jnz 0x002F9BED
	if (!ctx.flags.zf) goto loc_2F9BED;
	// 0x2F9BD2: mov dx, 0xF7FF
	X86_REG16(ctx.edx) = (uint16_t)(-2049);
	// 0x2F9BD6: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
	// 0x2F9BDB: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F9BDD: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BDF: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9BE1: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F9BE4: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2F9BE6: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BE8: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9BEA: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2F9BED:
	// 0x2F9BED: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9BEF: call 0x002FB267
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB267(ctx, base);
	ctx.esp += 4;
	// 0x2F9BF4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9BF6: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2F9BF9: jl 0x002F9C76
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2F9C76;
	// 0x2F9BFB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BFC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9BFD: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F9C00: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F9C05: push [esi+0xB0]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0xB0u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C0B: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F9C10: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F9C13: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2F9C15: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F9C1A: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2F9C1D: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C1F: lea eax, [ebx+0x08]
	ctx.eax = ctx.ebx + 0x8u;
	// 0x2F9C22: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9C23: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2F9C25: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2F9C27: and dword ptr [ebx+0x20], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x20u, X86_MEM_READ_u32(base, ctx.ebx + 0x20u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebx + 0x20u), 32);
	// 0x2F9C2B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C2D: mov dword ptr [ebx+0x24], 0x8000000A
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x24u, -2147483638);
	// 0x2F9C34: push [ebx+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebx + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C37: push [eax]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C39: call [0x0036B944]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B944u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2F9C3F: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F9C42: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2F9C47: mov esi, [ebp-0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2F9C4A: lea eax, [esi+0xA8]
	ctx.eax = ctx.esi + 0xA8u;
	// 0x2F9C50: mov [ebx], eax
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.eax);
	// 0x2F9C52: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F9C55: mov [ebx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.eax);
	// 0x2F9C58: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
	// 0x2F9C5A: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2F9C5C: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2F9C5F: mov [eax+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ebx);
	// 0x2F9C62: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2F9C67: test byte ptr [esi+0x12], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 32, 8);
	// 0x2F9C6B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9C6C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9C6D: jnz 0x002F9C76
	if (!ctx.flags.zf) goto loc_2F9C76;
	// 0x2F9C6F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9C71: call 0x002F98F8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F98F8(ctx, base);
	ctx.esp += 4;
loc_2F9C76:
	// 0x2F9C76: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F9C79: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9C7A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9C7B: ret 0x04
	ctx.esp += 4;
	return;
}

void CMcpxStream_Pause(X86Context& ctx, uint8_t* base) {
	// 0x2F9C7E: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9C82: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9C84: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C85: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9C87: jnz 0x002F9CB2
	if (!ctx.flags.zf) goto loc_2F9CB2;
	// 0x2F9C89: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9C8A: lea edi, [esi+0x12]
	ctx.edi = ctx.esi + 0x12u;
	// 0x2F9C8D: test byte ptr [edi], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.edi) & 32, 8);
	// 0x2F9C90: jz 0x002F9CA1
	if (ctx.flags.zf) goto loc_2F9CA1;
	// 0x2F9C92: mov ax, [edi]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi);
	// 0x2F9C95: and ax, 0xFFDF
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & -33;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x2F9C99: mov [edi], ax
	X86_MEM_WRITE_u16(base, ctx.edi, X86_REG16(ctx.eax));
	// 0x2F9C9C: call 0x002F98F8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F98F8(ctx, base);
	ctx.esp += 4;
loc_2F9CA1:
	// 0x2F9CA1: movzx eax, word ptr [edi]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi));
	// 0x2F9CA4: and eax, 0xFFFFFFBB
	ctx.eax = ctx.eax & -69;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9CA7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9CA8: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9CAA: call 0x002FAE08
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAE08(ctx, base);
	ctx.esp += 4;
	// 0x2F9CAF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9CB0: jmp 0x002F9D08
	goto loc_2F9D08;
loc_2F9CB2:
	// 0x2F9CB2: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9CB5: jnz 0x002F9CC3
	if (!ctx.flags.zf) goto loc_2F9CC3;
	// 0x2F9CB7: movzx eax, word ptr [esi+0x12]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x12u));
	// 0x2F9CBB: and eax, 0xFFFFFFBF
	ctx.eax = ctx.eax & -65;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9CBE: or eax, 0x04
	ctx.eax = ctx.eax | 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9CC1: jmp 0x002F9CE9
	goto loc_2F9CE9;
loc_2F9CC3:
	// 0x2F9CC3: cmp eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9CC6: jnz 0x002F9CD4
	if (!ctx.flags.zf) goto loc_2F9CD4;
	// 0x2F9CC8: movzx eax, word ptr [esi+0x12]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x12u));
	// 0x2F9CCC: and eax, 0xFFFFFFFB
	ctx.eax = ctx.eax & -5;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9CCF: or eax, 0x40
	ctx.eax = ctx.eax | 64;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2F9CD2: jmp 0x002F9CE9
	goto loc_2F9CE9;
loc_2F9CD4:
	// 0x2F9CD4: cmp eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9CD7: jnz 0x002F9D03
	if (!ctx.flags.zf) goto loc_2F9D03;
	// 0x2F9CD9: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2F9CDC: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2F9CDE: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2F9CE0: jnz 0x002F9CF3
	if (!ctx.flags.zf) goto loc_2F9CF3;
	// 0x2F9CE2: movzx eax, word ptr [esi+0x12]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x12u));
	// 0x2F9CE6: and eax, 0xFFFFFFBB
	ctx.eax = ctx.eax & -69;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2F9CE9:
	// 0x2F9CE9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9CEA: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9CEC: call 0x002FAE08
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAE08(ctx, base);
	ctx.esp += 4;
	// 0x2F9CF1: jmp 0x002F9D08
	goto loc_2F9D08;
loc_2F9CF3:
	// 0x2F9CF3: mov ax, [esi+0x12]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0x12u);
	// 0x2F9CF7: or ax, 0x20
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) | 32;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x2F9CFB: mov [esi+0x12], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x12u, X86_REG16(ctx.eax));
	// 0x2F9CFF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9D01: jmp 0x002F9D08
	goto loc_2F9D08;
loc_2F9D03:
	// 0x2F9D03: mov eax, 0x80004005
	ctx.eax = -2147467259;
loc_2F9D08:
	// 0x2F9D08: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9D09: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9D0C(X86Context& ctx, uint8_t* base) {
	// 0x2F9D0C: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9D10: sub eax, 0x00
	{ uint32_t _d = ctx.eax; uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9D13: jz 0x002F9D4F
	if (ctx.flags.zf) goto loc_2F9D4F;
	// 0x2F9D15: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9D16: jz 0x002F9D48
	if (ctx.flags.zf) goto loc_2F9D48;
	// 0x2F9D18: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9D19: jz 0x002F9D41
	if (ctx.flags.zf) goto loc_2F9D41;
	// 0x2F9D1B: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9D1C: jz 0x002F9D3A
	if (ctx.flags.zf) goto loc_2F9D3A;
	// 0x2F9D1E: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9D1F: jz 0x002F9D2F
	if (ctx.flags.zf) goto loc_2F9D2F;
	// 0x2F9D21: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9D22: jnz 0x002F9D54
	if (!ctx.flags.zf) goto loc_2F9D54;
	// 0x2F9D24: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9D28: call 0x002F9C7E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Pause(ctx, base);
	ctx.esp += 4;
	// 0x2F9D2D: jmp 0x002F9D54
	goto loc_2F9D54;
loc_2F9D2F:
	// 0x2F9D2F: push [esp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9D33: call 0x002F9114
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxStream_Stop(ctx, base);
	ctx.esp += 4;
	// 0x2F9D38: jmp 0x002F9D54
	goto loc_2F9D54;
loc_2F9D3A:
	// 0x2F9D3A: call 0x002F98E8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F98E8(ctx, base);
	ctx.esp += 4;
	// 0x2F9D3F: jmp 0x002F9D54
	goto loc_2F9D54;
loc_2F9D41:
	// 0x2F9D41: call 0x002F96F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F96F0(ctx, base);
	ctx.esp += 4;
	// 0x2F9D46: jmp 0x002F9D54
	goto loc_2F9D54;
loc_2F9D48:
	// 0x2F9D48: call 0x002F9491
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9491(ctx, base);
	ctx.esp += 4;
	// 0x2F9D4D: jmp 0x002F9D54
	goto loc_2F9D54;
loc_2F9D4F:
	// 0x2F9D4F: call 0x002FADB4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FADB4(ctx, base);
	ctx.esp += 4;
loc_2F9D54:
	// 0x2F9D54: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2F9D57(X86Context& ctx, uint8_t* base) {
	// 0x2F9D57: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9D58: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9D5A: call 0x002F9A64
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9A64(ctx, base);
	ctx.esp += 4;
	// 0x2F9D5F: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2F9D64: jz 0x002F9D6C
	if (ctx.flags.zf) goto loc_2F9D6C;
	// 0x2F9D66: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9D67: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2F9D6C:
	// 0x2F9D6C: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F9D6E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9D6F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9D72(X86Context& ctx, uint8_t* base) {
	// 0x2F9D72: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9D76: fldz
	X86_FPU_PUSH(ctx, 0.0);
	// 0x2F9D78: fstp [ecx+0x04]
	X86_MEM_WRITE_F32(base, ctx.ecx + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F9D7B: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x2F9D81: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2F9D83: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F9D85: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F9D87: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F9D89: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F9D8C: jp 0x002F9D9C
	if (ctx.flags.pf) goto loc_2F9D9C;
	// 0x2F9D8E: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2F9D90: fld [ecx+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F9D93: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F9D95: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F9D97: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F9D9A: jnp 0x002F9DE6
	if (!ctx.flags.pf) goto loc_2F9DE6;
loc_2F9D9C:
	// 0x2F9D9C: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F9D9E: fld [0x003B172C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B172Cu));
	// 0x2F9DA4: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F9DA6: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F9DA8: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F9DAA: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F9DAC: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F9DAF: jnp 0x002F9DE6
	if (!ctx.flags.pf) goto loc_2F9DE6;
	// 0x2F9DB1: fld [ecx+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F9DB4: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F9DB6: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x2F9DB8: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2F9DBA: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x2F9DBD: jnp 0x002F9DE6
	if (!ctx.flags.pf) goto loc_2F9DE6;
	// 0x2F9DBF: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F9DC1: fld [ecx+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F9DC4: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F9DC6: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F9DC8: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x2F9DCA: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x2F9DCC: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x2F9DCE: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x2F9DD0: fsqrt
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, sqrt(ctx.fp_stack[ctx.fp_top]));
	// 0x2F9DD2: fstp st2
	ctx.fp_stack[2] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F9DD4: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x2F9DD6: fld1
	X86_FPU_PUSH(ctx, 1.0);
	// 0x2F9DD8: fdiv st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] / ctx.fp_stack[1]);
	// 0x2F9DDA: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x2F9DDC: fmul [ecx]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x2F9DDE: fstp [ecx]
	X86_MEM_WRITE_F32(base, ctx.ecx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F9DE0: fmul [ecx+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.ecx + 0x8u));
	// 0x2F9DE3: fstp [ecx+0x08]
	X86_MEM_WRITE_F32(base, ctx.ecx + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_2F9DE6:
	// 0x2F9DE6: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9DE9(X86Context& ctx, uint8_t* base) {
	// 0x2F9DE9: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9DEA: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9DEC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9DED: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9DEE: mov dword ptr [ebp-0x04], 0x45800000
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, 1166016512);
	// 0x2F9DF5: fld [ebp-0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp - 0x4u));
	// 0x2F9DF8: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x2F9DFB: fyl2x
	{ double _y = ctx.fp_stack[(ctx.fp_top + 1) & 7];
	  double _x = ctx.fp_stack[ctx.fp_top];
	  X86_FPU_POP(ctx);
	  ctx.fp_stack[ctx.fp_top] = _y * log2(_x); }
	// 0x2F9DFD: fistp [ebp-0x08]
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (int32_t)ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2F9E00: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2F9E03: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9E04: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9E07(X86Context& ctx, uint8_t* base) {
	// 0x2F9E07: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9E0B: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F9E0F: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F9E11: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2F9E14: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x2F9E16: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2F9E18: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2F9E1B: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F9E1E: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F9E20: mov cx, [esp+0x08]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.esp + 0x8u);
	// 0x2F9E25: and dword ptr [eax+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, X86_MEM_READ_u32(base, ctx.eax + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0xCu), 32);
	// 0x2F9E29: and dword ptr [eax+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, X86_MEM_READ_u32(base, ctx.eax + 0x10u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x10u), 32);
	// 0x2F9E2D: mov [eax+0x08], cx
	X86_MEM_WRITE_u16(base, ctx.eax + 0x8u, X86_REG16(ctx.ecx));
	// 0x2F9E31: mov cx, [esp+0x0C]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.esp + 0xCu);
	// 0x2F9E36: mov [eax+0x0A], cx
	X86_MEM_WRITE_u16(base, ctx.eax + 0xAu, X86_REG16(ctx.ecx));
	// 0x2F9E3A: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2F9E3D(X86Context& ctx, uint8_t* base) {
	// 0x2F9E3D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2F9E41: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x2F9E45: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2F9E47: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2F9E4A: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x2F9E4C: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2F9E4E: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2F9E51: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F9E54: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2F9E56: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2F9E5A: and dword ptr [eax+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, X86_MEM_READ_u32(base, ctx.eax + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0xCu), 32);
	// 0x2F9E5E: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2F9E61: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2F9E64(X86Context& ctx, uint8_t* base) {
	// 0x2F9E64: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2F9E66: lea ecx, [eax+0x04]
	ctx.ecx = ctx.eax + 0x4u;
	// 0x2F9E69: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2F9E6C: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x2F9E6E: lea ecx, [eax+0x0C]
	ctx.ecx = ctx.eax + 0xCu;
	// 0x2F9E71: mov dword ptr [eax], 0x36C244
	X86_MEM_WRITE_u32(base, ctx.eax, 3588676);
	// 0x2F9E77: mov dword ptr [eax+0x1C], 0x30048C
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1Cu, 3146892);
	// 0x2F9E7E: mov [eax+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.ecx);
	// 0x2F9E81: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x2F9E83: ret
	return;
}

void sub_2F9E84(X86Context& ctx, uint8_t* base) {
	// 0x2F9E84: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9E85: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9E87: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F9E8A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9E8C: mov dword ptr [esi], 0x36C244
	X86_MEM_WRITE_u32(base, ctx.esi, 3588676);
	// 0x2F9E92: jz 0x002F9E9E
	if (ctx.flags.zf) goto loc_2F9E9E;
	// 0x2F9E94: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9E95: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
	// 0x2F9E9A: and dword ptr [esi+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, X86_MEM_READ_u32(base, ctx.esi + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x14u), 32);
loc_2F9E9E:
	// 0x2F9E9E: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F9EA1: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2F9EA4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9EA5: ret
	return;
}

void sub_2F9EA6(X86Context& ctx, uint8_t* base) {
	// 0x2F9EA6: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EA7: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2F9EA9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EAA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EAB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EAC: movzx edi, word ptr [ebp+0x08]
	ctx.edi = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp + 0x8u));
	// 0x2F9EB0: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2F9EB2: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2F9EB5: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x2F9EB7: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EB9: lea eax, [edi+edi*4+0x05]
	ctx.eax = ctx.edi + ctx.edi * 4 + 0x5u;
	// 0x2F9EBD: shl eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2F9EC0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EC1: push 0x61645344
	{ auto _pv = (uint32_t)(1633964868); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EC6: call 0x002F7596
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F7596(ctx, base);
	ctx.esp += 4;
	// 0x2F9ECB: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2F9ECD: neg ebx
	{ uint32_t _d = ctx.ebx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ebx = _res; }
	// 0x2F9ECF: sbb ebx, ebx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F9ED1: and ebx, 0x7FF8FFF2
	ctx.ebx = ctx.ebx & 2147024882;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2F9ED7: add ebx, 0x8007000E
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(-2147024882);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)-2147024882, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2F9EDD: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x2F9EE0: js 0x002F9F28
	if (ctx.flags.sf) goto loc_2F9F28;
	// 0x2F9EE2: lea ecx, [esi+0x04]
	ctx.ecx = ctx.esi + 0x4u;
	// 0x2F9EE5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EE6: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EE9: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2F9EEB: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EED: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9EEE: call 0x002F9E07
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E07(ctx, base);
	ctx.esp += 4;
	// 0x2F9EF3: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x2F9EF6: lea eax, [edi+0x01]
	ctx.eax = ctx.edi + 0x1u;
	// 0x2F9EF9: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9EFC: jbe 0x002F9F28
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F9F28;
	// 0x2F9EFE: lea ecx, [esi+0x0C]
	ctx.ecx = ctx.esi + 0xCu;
	// 0x2F9F01: mov dword ptr [ebp+0x08], 0x14
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 20);
	// 0x2F9F08: lea edx, [eax-0x01]
	ctx.edx = ctx.eax - 0x1u;
loc_2F9F0B:
	// 0x2F9F0B: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2F9F0E: add eax, [ebp+0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2F9F11: add dword ptr [ebp+0x08], 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)20, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x2F9F15: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2F9F16: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2F9F18: mov edi, [ecx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2F9F1B: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x2F9F1E: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2F9F21: mov edi, [eax+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2F9F24: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	// 0x2F9F26: jnz 0x002F9F0B
	if (!ctx.flags.zf) goto loc_2F9F0B;
loc_2F9F28:
	// 0x2F9F28: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9F29: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9F2A: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2F9F2C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9F2D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9F2E: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2F9F31(X86Context& ctx, uint8_t* base) {
	// 0x2F9F31: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9F32: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9F33: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2F9F35: mov eax, [edi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x2F9F38: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9F3A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2F9F3C: jz 0x002F9FFB
	if (ctx.flags.zf) goto loc_2F9FFB;
	// 0x2F9F42: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9F43: mov bx, [esp+0x14]
	X86_REG16(ctx.ebx) = X86_MEM_READ_u16(base, ctx.esp + 0x14u);
	// 0x2F9F48: cmp [eax+0x0A], bx
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.eax + 0xAu); uint16_t _s = X86_REG16(ctx.ebx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F9F4C: jb 0x002F9FFA
	if (ctx.flags.cf) goto loc_2F9FFA;
	// 0x2F9F52: lea edx, [edi+0x04]
	ctx.edx = ctx.edi + 0x4u;
	// 0x2F9F55: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2F9F57: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9F59: jz 0x002F9FFA
	if (ctx.flags.zf) goto loc_2F9FFA;
loc_2F9F5F:
	// 0x2F9F5F: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9F63: jnz 0x002F9F7A
	if (!ctx.flags.zf) goto loc_2F9F7A;
	// 0x2F9F65: mov cx, [eax+0x0A]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.eax + 0xAu);
	// 0x2F9F69: cmp cx, bx
	{ uint16_t _d = X86_REG16(ctx.ecx); uint16_t _s = X86_REG16(ctx.ebx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F9F6C: jb 0x002F9F7A
	if (ctx.flags.cf) goto loc_2F9F7A;
	// 0x2F9F6E: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F9F70: jz 0x002F9F78
	if (ctx.flags.zf) goto loc_2F9F78;
	// 0x2F9F72: cmp cx, [esi+0x0A]
	{ uint16_t _d = X86_REG16(ctx.ecx); uint16_t _s = X86_MEM_READ_u16(base, ctx.esi + 0xAu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F9F76: jnb 0x002F9F7A
	if (!ctx.flags.cf) goto loc_2F9F7A;
loc_2F9F78:
	// 0x2F9F78: mov esi, eax
	ctx.esi = ctx.eax;
loc_2F9F7A:
	// 0x2F9F7A: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2F9F7C: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9F7E: jnz 0x002F9F5F
	if (!ctx.flags.zf) goto loc_2F9F5F;
	// 0x2F9F80: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2F9F82: jz 0x002F9FFA
	if (ctx.flags.zf) goto loc_2F9FFA;
	// 0x2F9F84: cmp bx, [esi+0x0A]
	{ uint16_t _d = X86_REG16(ctx.ebx); uint16_t _s = X86_MEM_READ_u16(base, ctx.esi + 0xAu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F9F88: jnb 0x002F9FB3
	if (!ctx.flags.cf) goto loc_2F9FB3;
	// 0x2F9F8A: push [edi+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9F8D: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2F9F92: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9F94: mov cx, [esi+0x0A]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.esi + 0xAu);
	// 0x2F9F98: sub cx, bx
	{ uint16_t _d = X86_REG16(ctx.ecx); uint16_t _s = X86_REG16(ctx.ebx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16);
	  X86_REG16(ctx.ecx) = (uint16_t)_res; }
	// 0x2F9F9B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9F9C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9F9D: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2F9F9F: mov cx, [esi+0x08]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.esi + 0x8u);
	// 0x2F9FA3: add cx, bx
	{ uint64_t _res = (uint64_t)(uint16_t)(X86_REG16(ctx.ecx)) + (uint64_t)(uint16_t)(X86_REG16(ctx.ebx));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int16_t)X86_REG16(ctx.ecx), (int16_t)X86_REG16(ctx.ebx), 16);
	  X86_REG16(ctx.ecx) = (uint16_t)_res; }
	// 0x2F9FA6: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9FA7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2F9FA8: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2F9FAA: call 0x002F9E07
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E07(ctx, base);
	ctx.esp += 4;
	// 0x2F9FAF: mov [esi+0x0A], bx
	X86_MEM_WRITE_u16(base, ctx.esi + 0xAu, X86_REG16(ctx.ebx));
loc_2F9FB3:
	// 0x2F9FB3: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x2F9FB7: movzx ecx, word ptr [esi+0x0A]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0xAu));
	// 0x2F9FBB: mov dword ptr [esi+0x0C], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, 1);
	// 0x2F9FC2: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x2F9FC5: mov eax, [edi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x1Cu);
	// 0x2F9FC8: sub [eax], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x2F9FCA: cmp esi, [edi+0x18]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9FCD: jnz 0x002F9FFA
	if (!ctx.flags.zf) goto loc_2F9FFA;
	// 0x2F9FCF: and dword ptr [edi+0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi + 0x18u, X86_MEM_READ_u32(base, ctx.edi + 0x18u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi + 0x18u), 32);
	// 0x2F9FD3: lea edx, [edi+0x04]
	ctx.edx = ctx.edi + 0x4u;
	// 0x2F9FD6: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2F9FD8: jmp 0x002F9FF6
	goto loc_2F9FF6;
loc_2F9FDA:
	// 0x2F9FDA: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9FDE: jnz 0x002F9FF4
	if (!ctx.flags.zf) goto loc_2F9FF4;
	// 0x2F9FE0: mov ecx, [edi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x2F9FE3: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2F9FE5: jz 0x002F9FF1
	if (ctx.flags.zf) goto loc_2F9FF1;
	// 0x2F9FE7: mov bx, [eax+0x0A]
	X86_REG16(ctx.ebx) = X86_MEM_READ_u16(base, ctx.eax + 0xAu);
	// 0x2F9FEB: cmp bx, [ecx+0x0A]
	{ uint16_t _d = X86_REG16(ctx.ebx); uint16_t _s = X86_MEM_READ_u16(base, ctx.ecx + 0xAu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2F9FEF: jbe 0x002F9FF4
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2F9FF4;
loc_2F9FF1:
	// 0x2F9FF1: mov [edi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x18u, ctx.eax);
loc_2F9FF4:
	// 0x2F9FF4: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
loc_2F9FF6:
	// 0x2F9FF6: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2F9FF8: jnz 0x002F9FDA
	if (!ctx.flags.zf) goto loc_2F9FDA;
loc_2F9FFA:
	// 0x2F9FFA: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2F9FFB:
	// 0x2F9FFB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9FFC: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2F9FFE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2F9FFF: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FA002(X86Context& ctx, uint8_t* base) {
	// 0x2FA002: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FA006: mov dx, [eax+0x0A]
	X86_REG16(ctx.edx) = X86_MEM_READ_u16(base, ctx.eax + 0xAu);
	// 0x2FA00A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA00B: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FA00F: add [esi+0x0A], dx
	{ uint64_t _res = (uint64_t)(uint16_t)(X86_MEM_READ_u16(base, ctx.esi + 0xAu)) + (uint64_t)(uint16_t)(X86_REG16(ctx.edx));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int16_t)X86_MEM_READ_u16(base, ctx.esi + 0xAu), (int16_t)X86_REG16(ctx.edx), 16);
	  X86_MEM_WRITE_u16(base, ctx.esi + 0xAu, (uint16_t)_res); }
	// 0x2FA013: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA014: add ecx, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)12, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA017: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA018: call 0x002F82AB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F82AB(ctx, base);
	ctx.esp += 4;
	// 0x2FA01D: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FA01F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA020: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FA023(X86Context& ctx, uint8_t* base) {
	// 0x2FA023: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA024: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA026: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA027: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA028: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA02C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA02D: mov ebx, [ebp+0x10]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2FA030: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA032: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2FA034: shl eax, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA037: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA038: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA03B: call [0x0036B944]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B944u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FA041: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2FA043: jz 0x002FA08B
	if (ctx.flags.zf) goto loc_2FA08B;
	// 0x2FA045: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA046: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA047: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
loc_2FA04A:
	// 0x2FA04A: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA04D: call [0x0036B940]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B940u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FA053: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA056: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x2FA058: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
loc_2FA05D:
	// 0x2FA05D: mov eax, [0xFE820010]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FA062: and eax, 0xFFFFFFFC
	ctx.eax = ctx.eax & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA065: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA068: jb 0x002FA05D
	if (ctx.flags.cf) goto loc_2FA05D;
	// 0x2FA06A: mov [0xFE820804], edi
	X86_MEM_WRITE_u32(base, 0xFE820804u, ctx.edi);
	// 0x2FA070: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA073: mov [0xFE820808], esi
	X86_MEM_WRITE_u32(base, 0xFE820808u, ctx.esi);
	// 0x2FA079: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA07E: add dword ptr [ebp+0x0C], 0x1000
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)) + (uint64_t)(uint32_t)(4096);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0xCu), (int32_t)4096, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, (uint32_t)_res); }
	// 0x2FA085: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FA086: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FA087: jnz 0x002FA04A
	if (!ctx.flags.zf) goto loc_2FA04A;
	// 0x2FA089: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA08A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FA08B:
	// 0x2FA08B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA08C: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA08D: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2FA090(X86Context& ctx, uint8_t* base) {
	// 0x2FA090: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FA094: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA096: shl eax, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA099: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA09A: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA09E: call [0x0036B944]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B944u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FA0A4: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FA0A7(X86Context& ctx, uint8_t* base) {
	// 0x2FA0A7: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x2FA0A9: lea ecx, [eax+0x08]
	ctx.ecx = ctx.eax + 0x8u;
	// 0x2FA0AC: mov dword ptr [eax+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 1);
	// 0x2FA0B3: mov dword ptr [eax], 0x36C248
	X86_MEM_WRITE_u32(base, ctx.eax, 3588680);
	// 0x2FA0B9: mov [0x00300A98], eax
	X86_MEM_WRITE_u32(base, 0x300A98u, ctx.eax);
	// 0x2FA0BE: mov [eax+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.ecx);
	// 0x2FA0C1: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x2FA0C3: lea ecx, [eax+0x10]
	ctx.ecx = ctx.eax + 0x10u;
	// 0x2FA0C6: mov [eax+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.ecx);
	// 0x2FA0C9: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x2FA0CB: ret
	return;
}

void sub_2FA0CC(X86Context& ctx, uint8_t* base) {
	// 0x2FA0CC: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA0CD: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA0CF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA0D0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA0D1: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA0D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA0D6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA0D7: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2FA0D9: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA0DC: mov dword ptr [edi], 0x36C248
	X86_MEM_WRITE_u32(base, ctx.edi, 3588680);
	// 0x2FA0E2: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA0E7: and dword ptr [0x00300A98], 0x00
	X86_MEM_WRITE_u32(base, 0x300A98u, X86_MEM_READ_u32(base, 0x300A98u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, 0x300A98u), 32);
	// 0x2FA0EE: lea esi, [edi+0x08]
	ctx.esi = ctx.edi + 0x8u;
	// 0x2FA0F1: jmp 0x002FA100
	goto loc_2FA100;
loc_2FA0F3:
	// 0x2FA0F3: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA0F6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FA0F8: jz 0x002FA100
	if (ctx.flags.zf) goto loc_2FA100;
	// 0x2FA0FA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA0FB: call 0x002F757E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F757E(ctx, base);
	ctx.esp += 4;
loc_2FA100:
	// 0x2FA100: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA102: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2FA107: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA109: jnz 0x002FA0F3
	if (!ctx.flags.zf) goto loc_2FA0F3;
	// 0x2FA10B: mov eax, [0x00300BEC]
	ctx.eax = X86_MEM_READ_u32(base, 0x300BECu);
	// 0x2FA110: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2FA113: mov eax, [0x00300BE8]
	ctx.eax = X86_MEM_READ_u32(base, 0x300BE8u);
	// 0x2FA118: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2FA11B: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA11E: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA123: mov dword ptr [edi], 0x36C17C
	X86_MEM_WRITE_u32(base, ctx.edi, 3588476);
	// 0x2FA129: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA12A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA12B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA12C: ret
	return;
}

void sub_2FA12D(X86Context& ctx, uint8_t* base) {
	// 0x2FA12D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA12E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA130: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA131: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA132: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA136: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA137: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA139: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA13A: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA13D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA142: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FA145: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x2FA148: push 0x5C
	{ auto _pv = (uint32_t)(92); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA14A: sub edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA14C: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA14D: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA14F: sbb edi, edi
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FA151: neg edi
	{ uint32_t _d = ctx.edi;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.edi = _res; }
	// 0x2FA153: jz 0x002FA1A1
	if (ctx.flags.zf) goto loc_2FA1A1;
	// 0x2FA155: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA158: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA15A: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x2FA15D: lea ecx, [esi+0x08]
	ctx.ecx = ctx.esi + 0x8u;
	// 0x2FA160: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2FA162: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA163: mov ebx, [ecx+0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2FA166: mov [eax+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ebx);
	// 0x2FA169: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2FA16C: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2FA16F: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FA171: lea ecx, [esi+0x10]
	ctx.ecx = ctx.esi + 0x10u;
	// 0x2FA174: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA175: add edx, 0xFFFFFFF4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(-12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)-12, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA178: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA179: add eax, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)12, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA17C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA17D: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FA17F: call 0x002F9E3D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E3D(ctx, base);
	ctx.esp += 4;
	// 0x2FA184: mov ecx, [esi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2FA187: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FA189: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA18A: jz 0x002FA194
	if (ctx.flags.zf) goto loc_2FA194;
	// 0x2FA18C: mov edx, [eax+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA18F: cmp edx, [ecx+0x08]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA192: jbe 0x002FA197
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA197;
loc_2FA194:
	// 0x2FA194: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
loc_2FA197:
	// 0x2FA197: mov eax, [0x00300BEC]
	ctx.eax = X86_MEM_READ_u32(base, 0x300BECu);
	// 0x2FA19C: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FA19F: add [eax], ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.eax)) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.eax), (int32_t)ctx.ecx, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
loc_2FA1A1:
	// 0x2FA1A1: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA1A4: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA1A9: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2FA1AB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA1AC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA1AD: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA1AE: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_2FA1B1(X86Context& ctx, uint8_t* base) {
	// 0x2FA1B1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA1B2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA1B4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA1B5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA1B6: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA1B7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA1B8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA1B9: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2FA1BB: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA1BD: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA1C0: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x2FA1C3: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA1C8: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA1CB: mov eax, [edi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x2FA1CE: add esi, 0x17
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(23);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)23, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA1D1: shr esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x2FA1D4: shl esi, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x2FA1D7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FA1D9: jz 0x002FA278
	if (ctx.flags.zf) goto loc_2FA278;
	// 0x2FA1DF: cmp [eax+0x08], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x8u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA1E2: jb 0x002FA278
	if (ctx.flags.cf) goto loc_2FA278;
	// 0x2FA1E8: lea edx, [edi+0x10]
	ctx.edx = ctx.edi + 0x10u;
	// 0x2FA1EB: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2FA1ED: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA1EF: jz 0x002FA278
	if (ctx.flags.zf) goto loc_2FA278;
loc_2FA1F5:
	// 0x2FA1F5: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA1F9: jnz 0x002FA20D
	if (!ctx.flags.zf) goto loc_2FA20D;
	// 0x2FA1FB: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA1FE: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA200: jb 0x002FA20D
	if (ctx.flags.cf) goto loc_2FA20D;
	// 0x2FA202: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2FA204: jz 0x002FA20B
	if (ctx.flags.zf) goto loc_2FA20B;
	// 0x2FA206: cmp ecx, [ebx+0x08]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebx + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA209: jnb 0x002FA20D
	if (!ctx.flags.cf) goto loc_2FA20D;
loc_2FA20B:
	// 0x2FA20B: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_2FA20D:
	// 0x2FA20D: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FA20F: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA211: jnz 0x002FA1F5
	if (!ctx.flags.zf) goto loc_2FA1F5;
	// 0x2FA213: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2FA215: jz 0x002FA278
	if (ctx.flags.zf) goto loc_2FA278;
	// 0x2FA217: mov eax, [ebx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x8u);
	// 0x2FA21A: lea ecx, [esi+0x50]
	ctx.ecx = ctx.esi + 0x50u;
	// 0x2FA21D: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA21F: jnb 0x002FA233
	if (!ctx.flags.cf) goto loc_2FA233;
	// 0x2FA221: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA222: sub eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA224: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA225: lea eax, [ebx+esi*1]
	ctx.eax = ctx.ebx + ctx.esi;
	// 0x2FA228: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA229: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FA22B: call 0x002F9E3D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E3D(ctx, base);
	ctx.esp += 4;
	// 0x2FA230: mov [ebx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, ctx.esi);
loc_2FA233:
	// 0x2FA233: mov dword ptr [ebx+0x0C], 0x706F6C73
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xCu, 1886350451);
	// 0x2FA23A: cmp ebx, [edi+0x18]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA23D: jnz 0x002FA268
	if (!ctx.flags.zf) goto loc_2FA268;
	// 0x2FA23F: and dword ptr [edi+0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi + 0x18u, X86_MEM_READ_u32(base, ctx.edi + 0x18u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi + 0x18u), 32);
	// 0x2FA243: lea ecx, [edi+0x10]
	ctx.ecx = ctx.edi + 0x10u;
	// 0x2FA246: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FA248: jmp 0x002FA264
	goto loc_2FA264;
loc_2FA24A:
	// 0x2FA24A: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA24E: jnz 0x002FA262
	if (!ctx.flags.zf) goto loc_2FA262;
	// 0x2FA250: mov edx, [edi+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x2FA253: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FA255: jz 0x002FA25F
	if (ctx.flags.zf) goto loc_2FA25F;
	// 0x2FA257: mov esi, [eax+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA25A: cmp esi, [edx+0x08]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA25D: jbe 0x002FA262
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA262;
loc_2FA25F:
	// 0x2FA25F: mov [edi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x18u, ctx.eax);
loc_2FA262:
	// 0x2FA262: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
loc_2FA264:
	// 0x2FA264: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA266: jnz 0x002FA24A
	if (!ctx.flags.zf) goto loc_2FA24A;
loc_2FA268:
	// 0x2FA268: mov eax, [0x00300BE8]
	ctx.eax = X86_MEM_READ_u32(base, 0x300BE8u);
	// 0x2FA26D: mov ecx, [ebx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x8u);
	// 0x2FA270: add [eax], ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.eax)) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.eax), (int32_t)ctx.ecx, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x2FA272: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FA274: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA275: call [eax+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2FA278:
	// 0x2FA278: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA27B: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA280: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2FA282: add ebx, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)16, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FA285: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2FA287: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA288: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA28A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA28B: and eax, ebx
	ctx.eax = ctx.eax & ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA28D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA28E: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA28F: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA292(X86Context& ctx, uint8_t* base) {
	// 0x2FA292: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FA296: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA299: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA29A: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FA29E: add [esi+0x08], ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x8u)) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x8u), (int32_t)ctx.ecx, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, (uint32_t)_res); }
	// 0x2FA2A1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2A2: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2FA2A7: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FA2A9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA2AA: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FA2AD(X86Context& ctx, uint8_t* base) {
	// 0x2FA2AD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2AE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA2B0: call 0x002F9E84
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9E84(ctx, base);
	ctx.esp += 4;
	// 0x2FA2B5: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2FA2BA: jz 0x002FA2C2
	if (ctx.flags.zf) goto loc_2FA2C2;
	// 0x2FA2BC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2BD: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2FA2C2:
	// 0x2FA2C2: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FA2C4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA2C5: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA2C8(X86Context& ctx, uint8_t* base) {
	// 0x2FA2C8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2C9: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA2CB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2CC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2CD: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA2D1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2D2: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA2D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2D6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA2D7: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2FA2D9: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FA2DC: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2FA2DE: and eax, 0xFFF
	ctx.eax = ctx.eax & 4095;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA2E3: lea esi, [eax+ecx*1+0xFFF]
	ctx.esi = ctx.eax + ctx.ecx + 0xFFFu;
	// 0x2FA2EA: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA2ED: shr esi, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x2FA2F0: and ebx, 0xFFFFF000
	ctx.ebx = ctx.ebx & -4096;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA2F6: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA2FB: lea ecx, [edi+0x04]
	ctx.ecx = ctx.edi + 0x4u;
	// 0x2FA2FE: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FA300: jmp 0x002FA315
	goto loc_2FA315;
loc_2FA302:
	// 0x2FA302: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA306: jz 0x002FA313
	if (ctx.flags.zf) goto loc_2FA313;
	// 0x2FA308: cmp ebx, [eax+0x10]
	{ uint32_t _d = ctx.ebx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA30B: jnz 0x002FA313
	if (!ctx.flags.zf) goto loc_2FA313;
	// 0x2FA30D: cmp si, [eax+0x0A]
	{ uint16_t _d = X86_REG16(ctx.esi); uint16_t _s = X86_MEM_READ_u16(base, ctx.eax + 0xAu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2FA311: jz 0x002FA350
	if (ctx.flags.zf) goto loc_2FA350;
loc_2FA313:
	// 0x2FA313: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
loc_2FA315:
	// 0x2FA315: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA317: jnz 0x002FA302
	if (!ctx.flags.zf) goto loc_2FA302;
	// 0x2FA319: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA31A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA31B: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FA31D: call 0x002F9F31
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9F31(ctx, base);
	ctx.esp += 4;
	// 0x2FA322: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2FA324: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2FA326: jz 0x002FA33F
	if (ctx.flags.zf) goto loc_2FA33F;
	// 0x2FA328: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA32B: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA330: movzx eax, si
	ctx.eax = (uint32_t)(X86_REG16(ctx.esi));
	// 0x2FA333: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA334: movzx eax, word ptr [edi+0x08]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi + 0x8u));
	// 0x2FA338: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA339: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA33A: call 0x002FA023
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA023(ctx, base);
	ctx.esp += 4;
loc_2FA33F:
	// 0x2FA33F: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA342: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA347: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2FA349: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA34A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA34B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA34C: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA34D: ret 0x08
	ctx.esp += 8;
	return;
loc_2FA350:
	// 0x2FA350: inc [eax+0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, (uint32_t)_res); }
	// 0x2FA353: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2FA355: jmp 0x002FA33F
	goto loc_2FA33F;
}

void sub_2FA357(X86Context& ctx, uint8_t* base) {
	// 0x2FA357: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2FA35B: movzx edx, word ptr [eax+0x0A]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0xAu));
	// 0x2FA35F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA360: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA362: mov ecx, [esi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2FA365: add [ecx], edx
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx)) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ecx), (int32_t)ctx.edx, 32);
	  X86_MEM_WRITE_u32(base, ctx.ecx, (uint32_t)_res); }
	// 0x2FA367: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA368: lea edi, [esi+0x04]
	ctx.edi = ctx.esi + 0x4u;
	// 0x2FA36B: jmp 0x002FA37C
	goto loc_2FA37C;
loc_2FA36D:
	// 0x2FA36D: cmp dword ptr [ecx+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA371: jnz 0x002FA393
	if (!ctx.flags.zf) goto loc_2FA393;
	// 0x2FA373: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA374: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA375: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FA377: call 0x002FA002
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA002(ctx, base);
	ctx.esp += 4;
loc_2FA37C:
	// 0x2FA37C: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FA37E: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA380: jnz 0x002FA36D
	if (!ctx.flags.zf) goto loc_2FA36D;
	// 0x2FA382: jmp 0x002FA393
	goto loc_2FA393;
loc_2FA384:
	// 0x2FA384: cmp dword ptr [ecx+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA388: jnz 0x002FA39A
	if (!ctx.flags.zf) goto loc_2FA39A;
	// 0x2FA38A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA38B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA38C: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FA38E: call 0x002FA002
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA002(ctx, base);
	ctx.esp += 4;
loc_2FA393:
	// 0x2FA393: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2FA396: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA398: jnz 0x002FA384
	if (!ctx.flags.zf) goto loc_2FA384;
loc_2FA39A:
	// 0x2FA39A: mov ecx, [esi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2FA39D: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FA39F: jz 0x002FA3AB
	if (ctx.flags.zf) goto loc_2FA3AB;
	// 0x2FA3A1: mov dx, [eax+0x0A]
	X86_REG16(ctx.edx) = X86_MEM_READ_u16(base, ctx.eax + 0xAu);
	// 0x2FA3A5: cmp dx, [ecx+0x0A]
	{ uint16_t _d = X86_REG16(ctx.edx); uint16_t _s = X86_MEM_READ_u16(base, ctx.ecx + 0xAu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2FA3A9: jbe 0x002FA3AE
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA3AE;
loc_2FA3AB:
	// 0x2FA3AB: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
loc_2FA3AE:
	// 0x2FA3AE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA3AF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA3B0: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA3B3(X86Context& ctx, uint8_t* base) {
	// 0x2FA3B3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3B4: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA3B6: call 0x002FA0CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA0CC(ctx, base);
	ctx.esp += 4;
	// 0x2FA3BB: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2FA3C0: jz 0x002FA3C8
	if (ctx.flags.zf) goto loc_2FA3C8;
	// 0x2FA3C2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3C3: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2FA3C8:
	// 0x2FA3C8: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FA3CA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA3CB: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA3CE(X86Context& ctx, uint8_t* base) {
	// 0x2FA3CE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3CF: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA3D1: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3D2: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3D3: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA3D7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3D8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3D9: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA3DC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA3DD: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2FA3DF: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA3E2: add esi, 0xFFFFFFF0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(-16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)-16, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA3E5: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA3EA: mov eax, [0x00300BE8]
	ctx.eax = X86_MEM_READ_u32(base, 0x300BE8u);
	// 0x2FA3EF: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FA3F2: sub [eax], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x2FA3F4: and dword ptr [esi+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x2FA3F8: lea ebx, [edi+0x10]
	ctx.ebx = ctx.edi + 0x10u;
	// 0x2FA3FB: jmp 0x002FA417
	goto loc_2FA417;
loc_2FA3FD:
	// 0x2FA3FD: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA401: jnz 0x002FA439
	if (!ctx.flags.zf) goto loc_2FA439;
	// 0x2FA403: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FA406: add ecx, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.esi, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA408: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA40A: jnz 0x002FA439
	if (!ctx.flags.zf) goto loc_2FA439;
	// 0x2FA40C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA40D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA40E: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FA410: call 0x002FA292
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA292(ctx, base);
	ctx.esp += 4;
	// 0x2FA415: mov esi, eax
	ctx.esi = ctx.eax;
loc_2FA417:
	// 0x2FA417: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FA419: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA41B: jnz 0x002FA3FD
	if (!ctx.flags.zf) goto loc_2FA3FD;
	// 0x2FA41D: jmp 0x002FA439
	goto loc_2FA439;
loc_2FA41F:
	// 0x2FA41F: cmp dword ptr [eax+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA423: jnz 0x002FA440
	if (!ctx.flags.zf) goto loc_2FA440;
	// 0x2FA425: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA428: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA42A: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA42C: jnz 0x002FA440
	if (!ctx.flags.zf) goto loc_2FA440;
	// 0x2FA42E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA42F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA430: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FA432: call 0x002FA292
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA292(ctx, base);
	ctx.esp += 4;
	// 0x2FA437: mov esi, eax
	ctx.esi = ctx.eax;
loc_2FA439:
	// 0x2FA439: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x2FA43C: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA43E: jnz 0x002FA41F
	if (!ctx.flags.zf) goto loc_2FA41F;
loc_2FA440:
	// 0x2FA440: mov eax, [edi+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x2FA443: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FA445: jz 0x002FA44F
	if (ctx.flags.zf) goto loc_2FA44F;
	// 0x2FA447: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FA44A: cmp ecx, [eax+0x08]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA44D: jbe 0x002FA452
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA452;
loc_2FA44F:
	// 0x2FA44F: mov [edi+0x18], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x18u, ctx.esi);
loc_2FA452:
	// 0x2FA452: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FA454: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA455: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FA458: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA45B: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA460: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA461: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA462: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA463: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA464: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA467(X86Context& ctx, uint8_t* base) {
	// 0x2FA467: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA468: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA46A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA46B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA46C: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA470: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA471: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2FA473: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA476: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA47B: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA47E: dec [eax+0x0C]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, (uint32_t)_res); }
	// 0x2FA481: jnz 0x002FA4A5
	if (!ctx.flags.zf) goto loc_2FA4A5;
	// 0x2FA483: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA484: mov esi, [eax+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x2FA487: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA488: movzx edi, word ptr [eax+0x0A]
	ctx.edi = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0xAu));
	// 0x2FA48C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA48D: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2FA48F: call 0x002FA357
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA357(ctx, base);
	ctx.esp += 4;
	// 0x2FA494: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA497: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA49C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA49D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA49E: call 0x002FA090
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA090(ctx, base);
	ctx.esp += 4;
	// 0x2FA4A3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA4A4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FA4A5:
	// 0x2FA4A5: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA4A8: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA4AD: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA4AE: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA4AF: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA4B2(X86Context& ctx, uint8_t* base) {
	// 0x2FA4B2: mov dword ptr [0x00300BEC], 0x30047C
	X86_MEM_WRITE_u32(base, 0x300BECu, 3146876);
	// 0x2FA4BC: ret
	return;
}

void sub_2FA4BD(X86Context& ctx, uint8_t* base) {
	// 0x2FA4BD: mov dword ptr [0x00300BE8], 0x300480
	X86_MEM_WRITE_u32(base, 0x300BE8u, 3146880);
	// 0x2FA4C7: ret
	return;
}

void sub_2FA4C8(X86Context& ctx, uint8_t* base) {
	// 0x2FA4C8: and [ecx], dx
	X86_MEM_WRITE_u16(base, ctx.ecx, X86_MEM_READ_u16(base, ctx.ecx) & X86_REG16(ctx.edx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ecx), 16);
	// 0x2FA4CB: ret
	return;
}

void sub_2FA4CC(X86Context& ctx, uint8_t* base) {
	// 0x2FA4CC: or [ecx], dx
	X86_MEM_WRITE_u16(base, ctx.ecx, X86_MEM_READ_u16(base, ctx.ecx) | X86_REG16(ctx.edx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ecx), 16);
	// 0x2FA4CF: ret
	return;
}

void sub_2FA4D0(X86Context& ctx, uint8_t* base) {
	// 0x2FA4D0: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA4D4: fld [esp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0xCu));
	// 0x2FA4D8: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA4DC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA4DD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA4DE: fstp [esp+0x04]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2FA4E2: fld [esp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x14u));
	// 0x2FA4E6: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2FA4E9: call [0x00300B70]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x300B70u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FA4EF: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_2FA4F2(X86Context& ctx, uint8_t* base) {
	// 0x2FA4F2: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA4F4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA4F6: cmp [ecx+0x04], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x4u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA4F9: jbe 0x002FA50D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA50D;
	// 0x2FA4FB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2FA4FC:
	// 0x2FA4FC: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FA4FE: mov byte ptr [edx+esi*1+0x0F], 0x80
	X86_MEM_WRITE_u8(base, ctx.edx + ctx.esi + 0xFu, -128);
	// 0x2FA503: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA504: add edx, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)16, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA507: cmp eax, [ecx+0x04]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA50A: jb 0x002FA4FC
	if (ctx.flags.cf) goto loc_2FA4FC;
	// 0x2FA50C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FA50D:
	// 0x2FA50D: ret
	return;
}

void sub_2FA50E(X86Context& ctx, uint8_t* base) {
	// 0x2FA50E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA510: cmp [esp+0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA514: jz 0x002FA51A
	if (ctx.flags.zf) goto loc_2FA51A;
	// 0x2FA516: or byte ptr [ecx+0x17], 0x01
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x17u, X86_MEM_READ_u8(base, ctx.ecx + 0x17u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx + 0x17u), 8);
loc_2FA51A:
	// 0x2FA51A: mov edx, [ecx+0x70]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA51D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA51E: mov esi, 0x2000
	ctx.esi = 8192;
	// 0x2FA523: test [edx+0x08], esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.edx + 0x8u) & ctx.esi, 32);
	// 0x2FA526: jz 0x002FA52E
	if (ctx.flags.zf) goto loc_2FA52E;
	// 0x2FA528: or word ptr [ecx+0x16], 0x43F
	X86_MEM_WRITE_u16(base, ctx.ecx + 0x16u, X86_MEM_READ_u16(base, ctx.ecx + 0x16u) | 1087);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.ecx + 0x16u), 16);
loc_2FA52E:
	// 0x2FA52E: cmp [esp+0x08], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x8u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA532: jz 0x002FA538
	if (ctx.flags.zf) goto loc_2FA538;
	// 0x2FA534: or byte ptr [ecx+0x1A], 0x80
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x1Au, X86_MEM_READ_u8(base, ctx.ecx + 0x1Au) | -128);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx + 0x1Au), 8);
loc_2FA538:
	// 0x2FA538: test dword ptr [edx+0x08], 0x182000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.edx + 0x8u) & 1581056, 32);
	// 0x2FA53F: jnz 0x002FA545
	if (!ctx.flags.zf) goto loc_2FA545;
	// 0x2FA541: or byte ptr [ecx+0x15], 0xE0
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x15u, X86_MEM_READ_u8(base, ctx.ecx + 0x15u) | -32);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.ecx + 0x15u), 8);
loc_2FA545:
	// 0x2FA545: test [edx+0x08], esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.edx + 0x8u) & ctx.esi, 32);
	// 0x2FA548: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA549: jz 0x002FA551
	if (ctx.flags.zf) goto loc_2FA551;
	// 0x2FA54B: mov byte ptr [ecx+0x64], 0x01
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x64u, 1);
	// 0x2FA54F: jmp 0x002FA556
	goto loc_2FA556;
loc_2FA551:
	// 0x2FA551: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FA553: call [eax+0x14]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2FA556:
	// 0x2FA556: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FA559(X86Context& ctx, uint8_t* base) {
	// 0x2FA559: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA55A: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA55C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA55D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA55E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA55F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA560: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA562: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA564: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA567: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x2FA56A: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA56F: mov ecx, [esi+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FA572: movzx eax, byte ptr [ecx+0x0E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0xEu));
	// 0x2FA576: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA577: sar eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA579: inc al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x2FA57B: cmp al, [esi+0x64]
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0x64u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA57E: jz 0x002FA593
	if (ctx.flags.zf) goto loc_2FA593;
	// 0x2FA580: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FA584: jz 0x002FA590
	if (ctx.flags.zf) goto loc_2FA590;
	// 0x2FA586: mov edi, 0x88780032
	ctx.edi = -2005401550;
	// 0x2FA58B: jmp 0x002FA65E
	goto loc_2FA65E;
loc_2FA590:
	// 0x2FA590: mov [esi+0x64], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x64u, X86_REG8L(ctx.eax));
loc_2FA593:
	// 0x2FA593: movzx eax, word ptr [ecx+0x0C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx + 0xCu));
	// 0x2FA597: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA598: jz 0x002FA5B1
	if (ctx.flags.zf) goto loc_2FA5B1;
	// 0x2FA59A: sub eax, 0x68
	{ uint32_t _d = ctx.eax; uint32_t _s = 104;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA59D: jnz 0x002FA5EC
	if (!ctx.flags.zf) goto loc_2FA5EC;
	// 0x2FA59F: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FA5A2: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5A7: or eax, 0xA0000000
	ctx.eax = ctx.eax | -1610612736;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FA5AC:
	// 0x2FA5AC: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x2FA5AF: jmp 0x002FA5EC
	goto loc_2FA5EC;
loc_2FA5B1:
	// 0x2FA5B1: mov al, [ecx+0x0F]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ecx + 0xFu);
	// 0x2FA5B4: cmp al, 0x08
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA5B6: jz 0x002FA5E8
	if (ctx.flags.zf) goto loc_2FA5E8;
	// 0x2FA5B8: cmp al, 0x10
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA5BA: jz 0x002FA5D9
	if (ctx.flags.zf) goto loc_2FA5D9;
	// 0x2FA5BC: cmp al, 0x18
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA5BE: jz 0x002FA5CA
	if (ctx.flags.zf) goto loc_2FA5CA;
	// 0x2FA5C0: cmp al, 0x20
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA5C2: jnz 0x002FA5EC
	if (!ctx.flags.zf) goto loc_2FA5EC;
	// 0x2FA5C4: or byte ptr [esi+0x17], 0xF0
	X86_MEM_WRITE_u8(base, ctx.esi + 0x17u, X86_MEM_READ_u8(base, ctx.esi + 0x17u) | -16);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x17u), 8);
	// 0x2FA5C8: jmp 0x002FA5EC
	goto loc_2FA5EC;
loc_2FA5CA:
	// 0x2FA5CA: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FA5CD: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5D2: or eax, 0xE0000000
	ctx.eax = ctx.eax | -536870912;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5D7: jmp 0x002FA5AC
	goto loc_2FA5AC;
loc_2FA5D9:
	// 0x2FA5D9: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FA5DC: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5E1: or eax, 0x50000000
	ctx.eax = ctx.eax | 1342177280;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5E6: jmp 0x002FA5AC
	goto loc_2FA5AC;
loc_2FA5E8:
	// 0x2FA5E8: and byte ptr [esi+0x17], 0x0F
	X86_MEM_WRITE_u8(base, ctx.esi + 0x17u, X86_MEM_READ_u8(base, ctx.esi + 0x17u) & 15);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x17u), 8);
loc_2FA5EC:
	// 0x2FA5EC: movzx eax, byte ptr [ecx+0x0E]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0xEu));
	// 0x2FA5F0: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA5F1: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA5F4: xor eax, [esi+0x14]
	ctx.eax = ctx.eax ^ X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5F7: and eax, 0x1F0000
	ctx.eax = ctx.eax & 2031616;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA5FC: xor [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, X86_MEM_READ_u32(base, ctx.esi + 0x14u) ^ ctx.eax);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x14u), 32);
	// 0x2FA5FF: cmp byte ptr [ecx+0x0E], 0x01
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ecx + 0xEu); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA603: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FA606: jnz 0x002FA60F
	if (!ctx.flags.zf) goto loc_2FA60F;
	// 0x2FA608: and eax, 0xF7FFFFFF
	ctx.eax = ctx.eax & -134217729;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA60D: jmp 0x002FA614
	goto loc_2FA614;
loc_2FA60F:
	// 0x2FA60F: or eax, 0x8000000
	ctx.eax = ctx.eax | 134217728;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FA614:
	// 0x2FA614: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FA618: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x2FA61B: jz 0x002FA65E
	if (ctx.flags.zf) goto loc_2FA65E;
	// 0x2FA61D: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FA621: lea ecx, [eax+eax*1]
	ctx.ecx = ctx.eax + ctx.eax;
loc_2FA624:
	// 0x2FA624: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FA62A: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FA62D: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA62F: jb 0x002FA624
	if (ctx.flags.cf) goto loc_2FA624;
	// 0x2FA631: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA633: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA635: jbe 0x002FA65E
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA65E;
	// 0x2FA637: lea ecx, [esi+0x0C]
	ctx.ecx = ctx.esi + 0xCu;
loc_2FA63A:
	// 0x2FA63A: cmp edx, edi
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA63C: movzx eax, word ptr [ecx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx));
	// 0x2FA63F: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2FA644: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FA647: jz 0x002FA64E
	if (ctx.flags.zf) goto loc_2FA64E;
	// 0x2FA649: or eax, 0x400000
	ctx.eax = ctx.eax | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FA64E:
	// 0x2FA64E: mov [0xFE820304], eax
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.eax);
	// 0x2FA653: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FA657: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA658: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA659: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA65A: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA65C: jb 0x002FA63A
	if (ctx.flags.cf) goto loc_2FA63A;
loc_2FA65E:
	// 0x2FA65E: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FA661: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA666: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2FA668: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA669: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA66A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA66B: ret
	return;
}

void sub_2FA66C(X86Context& ctx, uint8_t* base) {
	// 0x2FA66C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA66D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA66F: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FA672: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x2FA676: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA677: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA678: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA67A: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FA67D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FA682: lea ebx, [esi+0x12]
	ctx.ebx = ctx.esi + 0x12u;
	// 0x2FA685: test byte ptr [ebx], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx) & 1, 8);
	// 0x2FA688: jz 0x002FA6E8
	if (ctx.flags.zf) goto loc_2FA6E8;
	// 0x2FA68A: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FA68E: cmp byte ptr [esi+0x64], 0x00
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi + 0x64u); uint8_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA692: jbe 0x002FA6CC
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA6CC;
	// 0x2FA694: lea edx, [esi+0x0C]
	ctx.edx = ctx.esi + 0xCu;
	// 0x2FA697: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_2FA698:
	// 0x2FA698: movzx edi, word ptr [edx]
	ctx.edi = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FA69B: shl edi, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x2FA69E: add edi, [0x00300C28]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, 0x300C28u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)X86_MEM_READ_u32(base, 0x300C28u), 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FA6A4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA6A6: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA6A8: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA6A9: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2FA6AB: movzx eax, word ptr [edx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FA6AE: mov edi, [0x00300C28]
	ctx.edi = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2FA6B4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2FA6B6: shl ecx, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2FA6B9: inc [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2FA6BC: mov [ecx+edi*1+0x7C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.edi + 0x7Cu, ctx.eax);
	// 0x2FA6C0: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FA6C4: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA6C5: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA6C6: cmp [ebp-0x04], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA6C9: jb 0x002FA698
	if (ctx.flags.cf) goto loc_2FA698;
	// 0x2FA6CB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FA6CC:
	// 0x2FA6CC: and dword ptr [esi+0x68], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x68u, X86_MEM_READ_u32(base, ctx.esi + 0x68u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x68u), 32);
	// 0x2FA6D0: and dword ptr [esi+0x6C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, X86_MEM_READ_u32(base, ctx.esi + 0x6Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x6Cu), 32);
	// 0x2FA6D4: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FA6D7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA6D8: call 0x002F8461
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8461(ctx, base);
	ctx.esp += 4;
	// 0x2FA6DD: mov dx, 0x10
	X86_REG16(ctx.edx) = (uint16_t)(16);
	// 0x2FA6E1: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2FA6E3: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
loc_2FA6E8:
	// 0x2FA6E8: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FA6EB: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FA6F0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA6F1: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA6F2: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA6F3: ret
	return;
}

void sub_2FA6F4(X86Context& ctx, uint8_t* base) {
	// 0x2FA6F4: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA6F5: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA6F7: sub esp, 0x20
	{ uint32_t _d = ctx.esp; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FA6FA: mov ecx, [ecx+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA6FD: mov edx, [ecx+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x24u);
	// 0x2FA700: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA701: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA703: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FA705: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA706: jbe 0x002FA718
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA718;
	// 0x2FA708: add ecx, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)40, 32);
	  ctx.ecx = (uint32_t)_res; }
loc_2FA70B:
	// 0x2FA70B: movzx esi, byte ptr [ecx]
	ctx.esi = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx));
	// 0x2FA70E: mov [ebp+eax*4-0x20], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u, ctx.esi);
	// 0x2FA712: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA713: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA714: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA716: jb 0x002FA70B
	if (ctx.flags.cf) goto loc_2FA70B;
loc_2FA718:
	// 0x2FA718: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA71A: jmp 0x002FA737
	goto loc_2FA737;
loc_2FA71C:
	// 0x2FA71C: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA71E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FA720: jbe 0x002FA731
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA731;
loc_2FA722:
	// 0x2FA722: cmp edx, [ebp+ecx*4-0x20]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x20u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA726: jz 0x002FA72D
	if (ctx.flags.zf) goto loc_2FA72D;
	// 0x2FA728: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA729: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA72B: jb 0x002FA722
	if (ctx.flags.cf) goto loc_2FA722;
loc_2FA72D:
	// 0x2FA72D: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA72F: jb 0x002FA736
	if (ctx.flags.cf) goto loc_2FA736;
loc_2FA731:
	// 0x2FA731: mov [ebp+eax*4-0x20], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u, ctx.edx);
	// 0x2FA735: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2FA736:
	// 0x2FA736: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
loc_2FA737:
	// 0x2FA737: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA73A: jb 0x002FA71C
	if (ctx.flags.cf) goto loc_2FA71C;
	// 0x2FA73C: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA73F: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
	// 0x2FA742: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA744: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA746: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2FA748:
	// 0x2FA748: mov edi, [ebp+eax*4-0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u);
	// 0x2FA74C: shl edi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x2FA74E: add ecx, 0x05
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(5);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)5, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA751: or edx, edi
	ctx.edx = ctx.edx | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FA753: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA754: cmp ecx, 0x0F
	{ uint32_t _d = ctx.ecx; uint32_t _s = 15;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA757: jb 0x002FA748
	if (ctx.flags.cf) goto loc_2FA748;
	// 0x2FA759: cmp eax, 0x06
	{ uint32_t _d = ctx.eax; uint32_t _s = 6;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA75C: mov [esi], edx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edx);
	// 0x2FA75E: jnb 0x002FA777
	if (!ctx.flags.cf) goto loc_2FA777;
	// 0x2FA760: lea ecx, [eax+eax*4+0x01]
	ctx.ecx = ctx.eax + ctx.eax * 4 + 0x1u;
loc_2FA764:
	// 0x2FA764: mov edi, [ebp+eax*4-0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u);
	// 0x2FA768: shl edi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x2FA76A: add ecx, 0x05
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(5);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)5, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA76D: or edx, edi
	ctx.edx = ctx.edx | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FA76F: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA770: cmp ecx, 0x1F
	{ uint32_t _d = ctx.ecx; uint32_t _s = 31;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA773: jb 0x002FA764
	if (ctx.flags.cf) goto loc_2FA764;
	// 0x2FA775: mov [esi], edx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edx);
loc_2FA777:
	// 0x2FA777: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FA77A: and word ptr [edx], 0xFC00
	X86_MEM_WRITE_u16(base, ctx.edx, X86_MEM_READ_u16(base, ctx.edx) & -1024);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.edx), 16);
	// 0x2FA77F: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA782: mov ecx, [edx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2FA784: jnb 0x002FA79F
	if (!ctx.flags.cf) goto loc_2FA79F;
	// 0x2FA786: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FA788: lea ecx, [eax+eax*4-0x1E]
	ctx.ecx = ctx.eax + ctx.eax * 4 - 0x1Eu;
loc_2FA78C:
	// 0x2FA78C: mov edi, [ebp+eax*4-0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u);
	// 0x2FA790: shl edi, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x2FA792: add ecx, 0x05
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(5);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)5, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FA795: or esi, edi
	ctx.esi = ctx.esi | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2FA797: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA798: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA79B: jb 0x002FA78C
	if (ctx.flags.cf) goto loc_2FA78C;
	// 0x2FA79D: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
loc_2FA79F:
	// 0x2FA79F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA7A0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA7A1: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA7A2: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FA7A5(X86Context& ctx, uint8_t* base) {
	// 0x2FA7A5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA7A6: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FA7A8: sub esp, 0x4C
	{ uint32_t _d = ctx.esp; uint32_t _s = 76;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FA7AB: and dword ptr [ebp-0x24], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, X86_MEM_READ_u32(base, ctx.ebp - 0x24u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x24u), 32);
	// 0x2FA7AF: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA7B0: mov ebx, [ecx+0x70]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA7B3: cmp dword ptr [ebx+0xB8], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebx + 0xB8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA7BA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA7BB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA7BC: mov [ebp-0x2C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x2Cu, ctx.ecx);
	// 0x2FA7BF: jz 0x002FA891
	if (ctx.flags.zf) goto loc_2FA891;
	// 0x2FA7C5: test byte ptr [ebx+0x0B], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx + 0xBu) & 1, 8);
	// 0x2FA7C9: jz 0x002FA891
	if (ctx.flags.zf) goto loc_2FA891;
	// 0x2FA7CF: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x2FA7D1: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FA7D7: mov edi, [eax+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FA7DA: add edi, [eax+0x04]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x4u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)X86_MEM_READ_u32(base, ctx.eax + 0x4u), 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FA7DD: mov eax, 0xFFFFD8F0
	ctx.eax = -10000;
	// 0x2FA7E2: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA7E4: mov [ebp-0x10], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edi);
	// 0x2FA7E7: jnl 0x002FA7ED
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2FA7ED;
	// 0x2FA7E9: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x2FA7EB: jmp 0x002FA7F3
	goto loc_2FA7F3;
loc_2FA7ED:
	// 0x2FA7ED: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2FA7EF: jle 0x002FA7F6
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2FA7F6;
	// 0x2FA7F1: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2FA7F3:
	// 0x2FA7F3: mov [ebp-0x10], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edi);
loc_2FA7F6:
	// 0x2FA7F6: mov edx, [ecx+0x70]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA7F9: mov edx, [edx+0xB8]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB8u);
	// 0x2FA7FF: mov esi, [edx+0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x1Cu);
	// 0x2FA802: add esi, [edx+0x14]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx + 0x14u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.edx + 0x14u), 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA805: add esi, [edx+0x0C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx + 0xCu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.edx + 0xCu), 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA808: add esi, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.edi, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA80A: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA80C: mov [ebp-0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.esi);
	// 0x2FA80F: jnl 0x002FA816
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2FA816;
	// 0x2FA811: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x2FA814: jmp 0x002FA81E
	goto loc_2FA81E;
loc_2FA816:
	// 0x2FA816: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2FA818: jle 0x002FA81E
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2FA81E;
	// 0x2FA81A: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
loc_2FA81E:
	// 0x2FA81E: mov edx, [ecx+0x70]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA821: mov esi, [edx+0xB8]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0xB8u);
	// 0x2FA827: mov edx, [esi+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2FA82A: add edx, [esi+0x10]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x10u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x10u), 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA82D: add edx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.edi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA82F: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA831: mov [ebp-0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.edx);
	// 0x2FA834: jnl 0x002FA83B
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2FA83B;
	// 0x2FA836: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2FA839: jmp 0x002FA843
	goto loc_2FA843;
loc_2FA83B:
	// 0x2FA83B: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FA83D: jle 0x002FA843
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2FA843;
	// 0x2FA83F: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
loc_2FA843:
	// 0x2FA843: mov edx, [ecx+0x70]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA846: mov edx, [edx+0xB8]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB8u);
	// 0x2FA84C: mov esi, [edx+0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x1Cu);
	// 0x2FA84F: add esi, [edx+0x18]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx + 0x18u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.edx + 0x18u), 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA852: add esi, [edx+0x0C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx + 0xCu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)X86_MEM_READ_u32(base, ctx.edx + 0xCu), 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA855: add esi, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.edi, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA857: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA859: mov [ebp-0x14], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.esi);
	// 0x2FA85C: jnl 0x002FA863
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2FA863;
	// 0x2FA85E: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
	// 0x2FA861: jmp 0x002FA86B
	goto loc_2FA86B;
loc_2FA863:
	// 0x2FA863: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2FA865: jle 0x002FA86B
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2FA86B;
	// 0x2FA867: and dword ptr [ebp-0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, X86_MEM_READ_u32(base, ctx.ebp - 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x14u), 32);
loc_2FA86B:
	// 0x2FA86B: mov edx, [ebx+0xB8]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0xB8u);
	// 0x2FA871: mov edx, [edx+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x20u);
	// 0x2FA874: add edx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.edi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FA876: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA878: mov [ebp-0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edx);
	// 0x2FA87B: jnl 0x002FA882
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2FA882;
	// 0x2FA87D: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2FA880: jmp 0x002FA88A
	goto loc_2FA88A;
loc_2FA882:
	// 0x2FA882: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FA884: jle 0x002FA88A
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2FA88A;
	// 0x2FA886: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
loc_2FA88A:
	// 0x2FA88A: mov dword ptr [ebp-0x24], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x24u, 1);
loc_2FA891:
	// 0x2FA891: movzx edi, byte ptr [ecx+0x64]
	ctx.edi = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0x64u));
	// 0x2FA895: mov eax, [ebx+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x24u);
	// 0x2FA898: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA89A: div edi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.edi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x2FA89C: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA89E: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2FA8A0: mov [ebp-0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.esi);
	// 0x2FA8A3: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x2FA8A6: jbe 0x002FA9E9
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA9E9;
	// 0x2FA8AC: mov edi, 0xFFF
	ctx.edi = 4095;
loc_2FA8B1:
	// 0x2FA8B1: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA8B3: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FA8B5: imul eax, [ebp-0x20]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x2FA8B9: mov [ebp-0x18], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.ebx);
	// 0x2FA8BC: mov [ebp-0x28], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x28u, ctx.eax);
	// 0x2FA8BF: jmp 0x002FA8C4
	goto loc_2FA8C4;
loc_2FA8C1:
	// 0x2FA8C1: mov eax, [ebp-0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x28u);
loc_2FA8C4:
	// 0x2FA8C4: cmp ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA8C6: jb 0x002FA9F0
	if (ctx.flags.cf) goto loc_2FA9F0;
	// 0x2FA8CC: lea eax, [esi+0x01]
	ctx.eax = ctx.esi + 0x1u;
	// 0x2FA8CF: imul eax, [ebp-0x20]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x2FA8D3: cmp ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA8D5: jnb 0x002FA9F0
	if (!ctx.flags.cf) goto loc_2FA9F0;
	// 0x2FA8DB: mov edx, [ecx+0x70]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA8DE: movzx eax, byte ptr [edx+ebx*1+0x28]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.edx + ctx.ebx + 0x28u));
	// 0x2FA8E3: mov eax, [edx+eax*4+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + ctx.eax * 4 + 0x30u);
	// 0x2FA8E7: add eax, [edx+0x1C]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx + 0x1Cu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.edx + 0x1Cu), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA8EA: lea esi, [ebp+ebx*4-0x4C]
	ctx.esi = ctx.ebp + ctx.ebx * 4 - 0x4Cu;
	// 0x2FA8EE: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2FA8F0: cmp dword ptr [ebp-0x24], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x24u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA8F4: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x2FA8F6: jz 0x002FA92E
	if (ctx.flags.zf) goto loc_2FA92E;
	// 0x2FA8F8: mov bl, [ebx+edx*1+0x28]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.ebx + ctx.edx + 0x28u);
	// 0x2FA8FC: cmp bl, 0x02
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA8FF: jz 0x002FA929
	if (ctx.flags.zf) goto loc_2FA929;
	// 0x2FA901: cmp bl, 0x05
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA904: jbe 0x002FA924
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA924;
	// 0x2FA906: cmp bl, 0x07
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 7;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA909: jbe 0x002FA91F
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA91F;
	// 0x2FA90B: cmp bl, 0x09
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 9;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA90E: jbe 0x002FA91A
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA91A;
	// 0x2FA910: cmp bl, 0x0A
	{ uint8_t _d = X86_REG8L(ctx.ebx); uint8_t _s = 10;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FA913: jnz 0x002FA924
	if (!ctx.flags.zf) goto loc_2FA924;
	// 0x2FA915: sub eax, [ebp-0x04]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA918: jmp 0x002FA92C
	goto loc_2FA92C;
loc_2FA91A:
	// 0x2FA91A: sub eax, [ebp-0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA91D: jmp 0x002FA92C
	goto loc_2FA92C;
loc_2FA91F:
	// 0x2FA91F: sub eax, [ebp-0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA922: jmp 0x002FA92C
	goto loc_2FA92C;
loc_2FA924:
	// 0x2FA924: sub eax, [ebp-0x10]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FA927: jmp 0x002FA92C
	goto loc_2FA92C;
loc_2FA929:
	// 0x2FA929: sub eax, [ebp-0x14]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2FA92C:
	// 0x2FA92C: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
loc_2FA92E:
	// 0x2FA92E: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FA930: push 0x64
	{ auto _pv = (uint32_t)(100); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA932: shl eax, 0x06
	{ auto _cnt = 0x6u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA935: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FA937: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA938: div ebx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ebx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x2FA93A: mov ebx, [ebp-0x18]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x2FA93D: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA93F: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x2FA941: jbe 0x002FA945
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FA945;
	// 0x2FA943: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
loc_2FA945:
	// 0x2FA945: mov esi, [ebp-0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
loc_2FA948:
	// 0x2FA948: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FA949: cmp ebx, 0x08
	{ uint32_t _d = ctx.ebx; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA94C: mov [ebp-0x18], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.ebx);
	// 0x2FA94F: jb 0x002FA8C1
	if (ctx.flags.cf) goto loc_2FA8C1;
	// 0x2FA955: mov eax, [ebp-0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x30u);
	// 0x2FA958: mov edx, [ebp-0x48]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x48u);
	// 0x2FA95B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2FA95D: and ecx, 0x0F
	ctx.ecx = ctx.ecx & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FA960: shl edx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FA963: or ecx, edx
	ctx.ecx = ctx.ecx | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FA965: mov edx, [ebp-0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x4Cu);
	// 0x2FA968: shl ecx, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2FA96B: and edx, edi
	ctx.edx = ctx.edx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FA96D: or ecx, edx
	ctx.ecx = ctx.ecx | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FA96F: mov edx, [ebp-0x34]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x34u);
	// 0x2FA972: shl ecx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2FA975: mov ebx, edx
	ctx.ebx = ctx.edx;
	// 0x2FA977: and ebx, 0x0F
	ctx.ebx = ctx.ebx & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA97A: or ecx, ebx
	ctx.ecx = ctx.ecx | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FA97C: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA97F: mov [ebx+esi*4], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx + ctx.esi * 4, ctx.ecx);
	// 0x2FA982: mov ecx, [ebp-0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x40u);
	// 0x2FA985: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2FA987: and ebx, 0xF0
	ctx.ebx = ctx.ebx & 240;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA98D: shl ecx, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2FA990: or ebx, ecx
	ctx.ebx = ctx.ebx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA992: mov ecx, [ebp-0x44]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x44u);
	// 0x2FA995: shl ebx, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x2FA998: and ecx, edi
	ctx.ecx = ctx.ecx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FA99A: or ebx, ecx
	ctx.ebx = ctx.ebx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA99C: shl ebx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x2FA99F: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x2FA9A1: shr ecx, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2FA9A4: and ecx, 0x0F
	ctx.ecx = ctx.ecx & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FA9A7: or ebx, ecx
	ctx.ebx = ctx.ebx | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA9A9: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FA9AC: mov [ecx+esi*4+0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.esi * 4 + 0xCu, ctx.ebx);
	// 0x2FA9B0: mov ebx, [ebp-0x38]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x38u);
	// 0x2FA9B3: and eax, 0xF00
	ctx.eax = ctx.eax & 3840;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA9B8: shl ebx, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x2FA9BB: or eax, ebx
	ctx.eax = ctx.eax | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA9BD: mov ebx, [ebp-0x3C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x3Cu);
	// 0x2FA9C0: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA9C3: and ebx, edi
	ctx.ebx = ctx.ebx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FA9C5: or eax, ebx
	ctx.eax = ctx.eax | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA9C7: shr edx, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FA9CA: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FA9CD: and edx, 0x0F
	ctx.edx = ctx.edx & 15;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FA9D0: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FA9D2: mov [ecx+esi*4+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + ctx.esi * 4 + 0x18u, ctx.eax);
	// 0x2FA9D6: mov ecx, [ebp-0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x2Cu);
	// 0x2FA9D9: movzx eax, byte ptr [ecx+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0x64u));
	// 0x2FA9DD: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FA9DE: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FA9E0: mov [ebp-0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.esi);
	// 0x2FA9E3: jb 0x002FA8B1
	if (ctx.flags.cf) goto loc_2FA8B1;
loc_2FA9E9:
	// 0x2FA9E9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA9EA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA9EB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA9EC: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FA9ED: ret 0x04
	ctx.esp += 4;
	return;
loc_2FA9F0:
	// 0x2FA9F0: mov [ebp+ebx*4-0x4C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + ctx.ebx * 4 - 0x4Cu, ctx.edi);
loc_2FA9F4:
	// 0x2FA9F4: jmp 0x002FA948
	goto loc_2FA948;
}

void sub_2FA9F9(X86Context& ctx, uint8_t* base) {
	// 0x2FA9F9: mov edx, [ecx+0x70]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FA9FC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FA9FD: mov esi, [edx+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x2FAA00: test esi, 0x182000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & 1581056, 32);
	// 0x2FAA06: jz 0x002FAA0C
	if (ctx.flags.zf) goto loc_2FAA0C;
	// 0x2FAA08: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAA0A: jmp 0x002FAA6E
	goto loc_2FAA6E;
loc_2FAA0C:
	// 0x2FAA0C: mov ecx, [ecx+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FAA0F: cmp dword ptr [ecx+0xB8], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0xB8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAA16: mov eax, [ecx+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x2FAA19: jz 0x002FAA2C
	if (ctx.flags.zf) goto loc_2FAA2C;
	// 0x2FAA1B: test esi, 0x1000000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & 16777216, 32);
	// 0x2FAA21: jz 0x002FAA2C
	if (ctx.flags.zf) goto loc_2FAA2C;
	// 0x2FAA23: mov ecx, [edx+0xB8]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0xB8u);
	// 0x2FAA29: add eax, [ecx+0x24]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x24u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x24u), 32);
	  ctx.eax = (uint32_t)_res; }
loc_2FAA2C:
	// 0x2FAA2C: mov edx, [edx+0xB0]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xB0u);
	// 0x2FAA32: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FAA34: jz 0x002FAA5A
	if (ctx.flags.zf) goto loc_2FAA5A;
	// 0x2FAA36: mov ecx, [edx+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x20u);
	// 0x2FAA39: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FAA3B: jz 0x002FAA5A
	if (ctx.flags.zf) goto loc_2FAA5A;
	// 0x2FAA3D: lea edx, [ecx+0x80]
	ctx.edx = ctx.ecx + 0x80u;
	// 0x2FAA43: mov ecx, [edx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x2FAA45: add eax, [ecx+0x18]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x18u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x18u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FAA48: cmp dword ptr [ecx+0xB8], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0xB8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAA4F: jz 0x002FAA5A
	if (ctx.flags.zf) goto loc_2FAA5A;
	// 0x2FAA51: mov ecx, [ecx+0xB8]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xB8u);
	// 0x2FAA57: add eax, [ecx+0x24]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x24u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x24u), 32);
	  ctx.eax = (uint32_t)_res; }
loc_2FAA5A:
	// 0x2FAA5A: mov ecx, 0xFFFF8001
	ctx.ecx = -32767;
	// 0x2FAA5F: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAA61: jl 0x002FAA6C
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2FAA6C;
	// 0x2FAA63: mov ecx, 0x1FFF
	ctx.ecx = 8191;
	// 0x2FAA68: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAA6A: jle 0x002FAA6E
	if ((ctx.flags.zf || ctx.flags.sf != ctx.flags.of)) goto loc_2FAA6E;
loc_2FAA6C:
	// 0x2FAA6C: mov eax, ecx
	ctx.eax = ctx.ecx;
loc_2FAA6E:
	// 0x2FAA6E: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FAA72: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FAA75: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FAA77: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAA78: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FAA7B(X86Context& ctx, uint8_t* base) {
	// 0x2FAA7B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAA7C: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FAA7E: mov eax, [ecx+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x70u);
	// 0x2FAA81: mov edx, [eax+0xB0]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0xB0u);
	// 0x2FAA87: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAA88: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAA8A: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAA8C: jz 0x002FAAC2
	if (ctx.flags.zf) goto loc_2FAAC2;
	// 0x2FAA8E: mov edx, [edx+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x20u);
	// 0x2FAA91: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAA93: jz 0x002FAAC2
	if (ctx.flags.zf) goto loc_2FAAC2;
	// 0x2FAA95: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAA96: mov esi, [edx+0x70]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x70u);
	// 0x2FAA99: test dword ptr [esi+0x08], 0x82000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esi + 0x8u) & 532480, 32);
	// 0x2FAAA0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAAA1: jz 0x002FAAC2
	if (ctx.flags.zf) goto loc_2FAAC2;
	// 0x2FAAA3: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAAA6: mov byte ptr [eax], 0x02
	X86_MEM_WRITE_u8(base, ctx.eax, 2);
	// 0x2FAAA9: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x2FAAAC: mov edx, [edx+0x50]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x50u);
	// 0x2FAAAF: add eax, 0x498
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(1176);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)1176, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FAAB4: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAAB6: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FAAB9: jz 0x002FAAE8
	if (ctx.flags.zf) goto loc_2FAAE8;
	// 0x2FAABB: add edx, 0xFFFFFFB4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(-76);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)-76, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FAABE: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2FAAC0: jmp 0x002FAAEA
	goto loc_2FAAEA;
loc_2FAAC2:
	// 0x2FAAC2: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x2FAAC5: test eax, 0x182000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 1581056, 32);
	// 0x2FAACA: jz 0x002FAAD4
	if (ctx.flags.zf) goto loc_2FAAD4;
	// 0x2FAACC: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAACF: mov byte ptr [eax], 0x02
	X86_MEM_WRITE_u8(base, ctx.eax, 2);
	// 0x2FAAD2: jmp 0x002FAAE5
	goto loc_2FAAE5;
loc_2FAAD4:
	// 0x2FAAD4: test eax, 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 2097168, 32);
	// 0x2FAAD9: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAADC: jz 0x002FAAE3
	if (ctx.flags.zf) goto loc_2FAAE3;
	// 0x2FAADE: mov byte ptr [eax], 0x01
	X86_MEM_WRITE_u8(base, ctx.eax, 1);
	// 0x2FAAE1: jmp 0x002FAAE5
	goto loc_2FAAE5;
loc_2FAAE3:
	// 0x2FAAE3: mov [eax], bl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ebx));
loc_2FAAE5:
	// 0x2FAAE5: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
loc_2FAAE8:
	// 0x2FAAE8: mov [eax], ebx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebx);
loc_2FAAEA:
	// 0x2FAAEA: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAAEB: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAAEC: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FAAEF(X86Context& ctx, uint8_t* base) {
	// 0x2FAAEF: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAAF0: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FAAF2: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FAAF5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAAF6: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FAAF8: movzx ecx, byte ptr [esi+0x65]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x65u));
	// 0x2FAAFC: lea eax, [ecx+ecx*2]
	ctx.eax = ctx.ecx + ctx.ecx * 2;
	// 0x2FAAFF: shl eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FAB02: mov edx, [eax+0x300328]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x300328u);
	// 0x2FAB08: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAB09: mov edi, [edx-0x1800000]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx - 0x1800000u);
	// 0x2FAB0F: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x2FAB12: mov edi, [eax+0x30032C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x30032Cu);
	// 0x2FAB18: mov eax, [eax+0x300330]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x300330u);
	// 0x2FAB1E: mov edi, [edi-0x1800000]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi - 0x1800000u);
	// 0x2FAB24: mov eax, [eax-0x1800000]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax - 0x1800000u);
	// 0x2FAB2A: mov [ebp-0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.eax);
	// 0x2FAB2D: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FAB30: lea ecx, [eax+ecx*8+0x488]
	ctx.ecx = ctx.eax + ctx.ecx * 8 + 0x488u;
	// 0x2FAB37: mov eax, [esi+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x2FAB3A: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAB3C: mov [ebp-0x18], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.edi);
	// 0x2FAB3F: jnz 0x002FAB4A
	if (!ctx.flags.zf) goto loc_2FAB4A;
	// 0x2FAB41: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAB43: mov eax, 0xFFFF
	ctx.eax = 65535;
	// 0x2FAB48: jmp 0x002FAB56
	goto loc_2FAB56;
loc_2FAB4A:
	// 0x2FAB4A: lea edi, [eax-0x4C]
	ctx.edi = ctx.eax - 0x4Cu;
	// 0x2FAB4D: movzx eax, byte ptr [edi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + 0x64u));
	// 0x2FAB51: movzx eax, word ptr [edi+eax*2+0x0A]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi + ctx.eax * 2 + 0xAu));
loc_2FAB56:
	// 0x2FAB56: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAB57: mov ebx, [esi+0x4C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x2FAB5A: cmp ecx, ebx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAB5C: jnz 0x002FAB69
	if (!ctx.flags.zf) goto loc_2FAB69;
	// 0x2FAB5E: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2FAB62: mov ebx, 0xFFFF
	ctx.ebx = 65535;
	// 0x2FAB67: jmp 0x002FAB73
	goto loc_2FAB73;
loc_2FAB69:
	// 0x2FAB69: add ebx, 0xFFFFFFB4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(-76);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)-76, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FAB6C: mov [ebp-0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.ebx);
	// 0x2FAB6F: movzx ebx, word ptr [ebx+0x0C]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebx + 0xCu));
loc_2FAB73:
	// 0x2FAB73: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2FAB75: jz 0x002FAB91
	if (ctx.flags.zf) goto loc_2FAB91;
	// 0x2FAB77: mov ecx, [0x00300C28]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2FAB7D: shl eax, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FAB80: lea ecx, [eax+ecx*1+0x7C]
	ctx.ecx = ctx.eax + ctx.ecx + 0x7Cu;
	// 0x2FAB84: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FAB86: and eax, 0xFFFF0000
	ctx.eax = ctx.eax & -65536;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FAB8B: or eax, ebx
	ctx.eax = ctx.eax | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FAB8D: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FAB8F: jmp 0x002FAB9A
	goto loc_2FAB9A;
loc_2FAB91:
	// 0x2FAB91: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x2FAB94: mov [edx-0x1800000], ebx
	X86_MEM_WRITE_u32(base, ctx.edx - 0x1800000u, ctx.ebx);
loc_2FAB9A:
	// 0x2FAB9A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAB9C: cmp [esi+0x64], al
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi + 0x64u); uint8_t _s = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FAB9F: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x2FABA2: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x2FABA5: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
	// 0x2FABA8: jbe 0x002FAC5E
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FAC5E;
	// 0x2FABAE: lea edx, [esi+0x0C]
	ctx.edx = ctx.esi + 0xCu;
loc_2FABB1:
	// 0x2FABB1: movzx eax, word ptr [edx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FABB4: cmp [ebp-0x18], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x18u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FABB7: jnz 0x002FABC0
	if (!ctx.flags.zf) goto loc_2FABC0;
	// 0x2FABB9: mov dword ptr [ebp-0x10], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, 1);
loc_2FABC0:
	// 0x2FABC0: cmp [ebp-0x1C], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FABC3: jnz 0x002FABCC
	if (!ctx.flags.zf) goto loc_2FABCC;
	// 0x2FABC5: mov dword ptr [ebp-0x14], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, 1);
loc_2FABCC:
	// 0x2FABCC: movzx edi, word ptr [edx]
	ctx.edi = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FABCF: mov ecx, [0x00300C28]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2FABD5: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2FABD7: shl eax, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FABDA: lea ecx, [eax+ecx*1+0x7C]
	ctx.ecx = ctx.eax + ctx.ecx + 0x7Cu;
	// 0x2FABDE: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FABE0: and eax, 0xFFFF0000
	ctx.eax = ctx.eax & -65536;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FABE5: or eax, edi
	ctx.eax = ctx.eax | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FABE7: inc [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2FABEA: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FABEC: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FABF0: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FABF1: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FABF2: cmp [ebp-0x08], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FABF5: jb 0x002FABB1
	if (ctx.flags.cf) goto loc_2FABB1;
	// 0x2FABF7: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FABF9: cmp [ebp-0x10], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x10u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FABFC: jz 0x002FAC3C
	if (ctx.flags.zf) goto loc_2FAC3C;
	// 0x2FABFE: cmp [ebp-0x0C], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAC01: jz 0x002FAC1E
	if (ctx.flags.zf) goto loc_2FAC1E;
	// 0x2FAC03: mov eax, [0x00300C28]
	ctx.eax = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2FAC08: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2FAC0A: shl ebx, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (32 - _cnt)) & 1;
	  ctx.ebx = ctx.ebx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x2FAC0D: mov ebx, [ebx+eax*1+0x7C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebx + ctx.eax + 0x7Cu);
	// 0x2FAC11: mov eax, 0xFFFF
	ctx.eax = 65535;
	// 0x2FAC16: and ebx, eax
	ctx.ebx = ctx.ebx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FAC18: cmp ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAC1A: jnz 0x002FAC26
	if (!ctx.flags.zf) goto loc_2FAC26;
	// 0x2FAC1C: jmp 0x002FAC23
	goto loc_2FAC23;
loc_2FAC1E:
	// 0x2FAC1E: mov ecx, 0xFFFF
	ctx.ecx = 65535;
loc_2FAC23:
	// 0x2FAC23: mov ebx, [ebp-0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_2FAC26:
	// 0x2FAC26: movzx eax, byte ptr [esi+0x65]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x65u));
	// 0x2FAC2A: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x2FAC2D: mov eax, [eax*4+0x30032C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x30032Cu);
	// 0x2FAC34: mov [eax-0x1800000], ecx
	X86_MEM_WRITE_u32(base, ctx.eax - 0x1800000u, ctx.ecx);
	// 0x2FAC3A: jmp 0x002FAC4A
	goto loc_2FAC4A;
loc_2FAC3C:
	// 0x2FAC3C: cmp [ebp-0x14], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAC3F: jz 0x002FAC5E
	if (ctx.flags.zf) goto loc_2FAC5E;
	// 0x2FAC41: cmp dword ptr [ebp-0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAC45: jnz 0x002FAC4A
	if (!ctx.flags.zf) goto loc_2FAC4A;
	// 0x2FAC47: mov ebx, [ebp-0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
loc_2FAC4A:
	// 0x2FAC4A: movzx eax, byte ptr [esi+0x65]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x65u));
	// 0x2FAC4E: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x2FAC51: mov eax, [eax*4+0x300330]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x300330u);
	// 0x2FAC58: mov [eax-0x1800000], ebx
	X86_MEM_WRITE_u32(base, ctx.eax - 0x1800000u, ctx.ebx);
loc_2FAC5E:
	// 0x2FAC5E: lea eax, [esi+0x4C]
	ctx.eax = ctx.esi + 0x4Cu;
	// 0x2FAC61: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAC62: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2FAC67: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2FAC6A: test word ptr [ecx], 0x8000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.ecx) & -32768, 16);
	// 0x2FAC6F: mov byte ptr [esi+0x65], 0xFF
	X86_MEM_WRITE_u8(base, ctx.esi + 0x65u, -1);
	// 0x2FAC73: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAC74: jz 0x002FAC81
	if (ctx.flags.zf) goto loc_2FAC81;
	// 0x2FAC76: mov dx, 0x7FFF
	X86_REG16(ctx.edx) = (uint16_t)(32767);
	// 0x2FAC7A: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
	// 0x2FAC7F: jmp 0x002FACC5
	goto loc_2FACC5;
loc_2FAC81:
	// 0x2FAC81: mov eax, [esi+0x68]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x68u);
	// 0x2FAC84: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAC86: cmp [ebp+0x08], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAC89: mov byte ptr [eax+0x3F], 0x01
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3Fu, 1);
	// 0x2FAC8D: jz 0x002FACC5
	if (ctx.flags.zf) goto loc_2FACC5;
	// 0x2FAC8F: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FAC92: lea eax, [esi+0x54]
	ctx.eax = ctx.esi + 0x54u;
	// 0x2FAC95: add ecx, 0x4A0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(1184);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)1184, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FAC9B: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2FAC9D: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2FACA0: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2FACA3: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FACA5: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FACA7: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2FACAA: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FACAD: or dword ptr [eax+0x4B8], 0x40
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4B8u, X86_MEM_READ_u32(base, ctx.eax + 0x4B8u) | 64);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x4B8u), 32);
	// 0x2FACB4: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FACB7: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACB8: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACB9: add eax, 0x4C8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(1224);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)1224, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FACBE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACBF: call [0x0036B948]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B948u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2FACC5:
	// 0x2FACC5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FACC6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FACC7: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FACC8: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FACCB(X86Context& ctx, uint8_t* base) {
	// 0x2FACCB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACCC: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FACCE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACCF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACD0: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FACD4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACD5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACD6: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FACD8: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FACDB: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FACE0: inc [0x00300A9C]
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x300A9Cu);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, 0x300A9Cu, (uint32_t)_res); }
	// 0x2FACE6: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FACE9: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FACEB: add ecx, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)8, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FACEE: call 0x002FE262
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE262(ctx, base);
	ctx.esp += 4;
	// 0x2FACF3: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2FACF5: mov ax, [esi+0x12]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0x12u);
	// 0x2FACF9: and ax, 0x8001
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & -32767;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x2FACFD: cmp ax, 0x8001
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = -32767;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2FAD01: jnz 0x002FAD0C
	if (!ctx.flags.zf) goto loc_2FAD0C;
	// 0x2FAD03: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAD05: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FAD07: call 0x002FAAEF
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAAEF(ctx, base);
	ctx.esp += 4;
loc_2FAD0C:
	// 0x2FAD0C: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x2FAD0E: jz 0x002FAD1D
	if (ctx.flags.zf) goto loc_2FAD1D;
	// 0x2FAD10: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FAD13: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAD15: add ecx, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)8, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FAD18: call 0x002FE262
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FE262(ctx, base);
	ctx.esp += 4;
loc_2FAD1D:
	// 0x2FAD1D: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FAD1F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FAD21: call [eax+0x18]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FAD24: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FAD27: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FAD2C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAD2D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAD2E: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAD2F: ret
	return;
}

void sub_2FAD30(X86Context& ctx, uint8_t* base) {
	// 0x2FAD30: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAD31: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FAD33: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAD34: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAD35: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FAD39: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAD3A: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FAD3C: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FAD3F: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FAD44: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2FAD47: mov al, [ecx]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ecx);
	// 0x2FAD49: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2FAD4B: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FAD4D: jnz 0x002FADA9
	if (!ctx.flags.zf) goto loc_2FADA9;
	// 0x2FAD4F: mov dx, 0x08
	X86_REG16(ctx.edx) = (uint16_t)(8);
	// 0x2FAD53: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2FAD58: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FAD5C: and byte ptr [esi+0x16], 0x7F
	X86_MEM_WRITE_u8(base, ctx.esi + 0x16u, X86_MEM_READ_u8(base, ctx.esi + 0x16u) & 127);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x16u), 8);
	// 0x2FAD60: lea ecx, [eax+eax*2]
	ctx.ecx = ctx.eax + ctx.eax * 2;
loc_2FAD63:
	// 0x2FAD63: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FAD69: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FAD6C: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAD6E: jb 0x002FAD63
	if (ctx.flags.cf) goto loc_2FAD63;
	// 0x2FAD70: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAD72: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FAD74: jbe 0x002FADA9
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FADA9;
	// 0x2FAD76: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
loc_2FAD79:
	// 0x2FAD79: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FAD7B: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2FAD7E: mov [0xFE8202F8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.ecx);
	// 0x2FAD84: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FAD87: jz 0x002FAD8F
	if (ctx.flags.zf) goto loc_2FAD8F;
	// 0x2FAD89: or ecx, 0x400000
	ctx.ecx = ctx.ecx | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_2FAD8F:
	// 0x2FAD8F: mov [0xFE820304], ecx
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.ecx);
	// 0x2FAD95: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2FAD98: mov [0xFE82012C], ecx
	X86_MEM_WRITE_u32(base, 0xFE82012Cu, ctx.ecx);
	// 0x2FAD9E: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FADA2: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FADA3: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FADA4: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FADA5: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FADA7: jb 0x002FAD79
	if (ctx.flags.cf) goto loc_2FAD79;
loc_2FADA9:
	// 0x2FADA9: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FADAC: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FADB1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FADB2: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FADB3: ret
	return;
}

void sub_2FADB4(X86Context& ctx, uint8_t* base) {
	// 0x2FADB4: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FADB5: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FADB7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FADB8: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FADB9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FADBA: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2FADBD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FADBE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FADC0: call [0x0036B7DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B7DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FADC6: mov ax, [esi+0x12]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0x12u);
	// 0x2FADCA: and ax, 0x8001
	X86_REG16(ctx.eax) = X86_REG16(ctx.eax) & -32767;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.eax), 16);
	// 0x2FADCE: cmp ax, 0x8001
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = -32767;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x2FADD2: jnz 0x002FADFC
	if (!ctx.flags.zf) goto loc_2FADFC;
	// 0x2FADD4: mov ecx, [esi+0x78]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x78u);
	// 0x2FADD7: mov eax, [esi+0x7C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x7Cu);
	// 0x2FADDA: mov edx, [ebp-0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FADDD: add ecx, 0x4C4B40
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(5000000);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)5000000, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FADE3: adc eax, 0x00
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(0) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)0, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FADE6: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FADE8: jl 0x002FAE05
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2FAE05;
	// 0x2FADEA: jnle 0x002FADF3
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_2FADF3;
	// 0x2FADEC: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2FADEF: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FADF1: jb 0x002FAE05
	if (ctx.flags.cf) goto loc_2FAE05;
loc_2FADF3:
	// 0x2FADF3: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FADF5: call 0x002FACCB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FACCB(ctx, base);
	ctx.esp += 4;
	// 0x2FADFA: jmp 0x002FAE05
	goto loc_2FAE05;
loc_2FADFC:
	// 0x2FADFC: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FADFE: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAE00: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FAE02: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2FAE05:
	// 0x2FAE05: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAE06: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAE07: ret
	return;
}

void sub_2FAE08(X86Context& ctx, uint8_t* base) {
	// 0x2FAE08: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAE09: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FAE0B: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FAE0E: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FAE12: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x2FAE16: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAE17: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAE18: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FAE1A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAE1B: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FAE1E: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FAE23: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAE25: lea edi, [esi+0x12]
	ctx.edi = ctx.esi + 0x12u;
	// 0x2FAE28: mov ax, [edi]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi);
	// 0x2FAE2B: mov ebx, 0x444
	ctx.ebx = 1092;
	// 0x2FAE30: and [ebp+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, X86_MEM_READ_u32(base, ctx.ebp + 0x8u) & ctx.ebx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0x8u), 32);
	// 0x2FAE33: and eax, ebx
	ctx.eax = ctx.eax & ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FAE35: cmp eax, [ebp+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAE38: jz 0x002FAEDC
	if (ctx.flags.zf) goto loc_2FAEDC;
	// 0x2FAE3E: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAE41: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAE43: mov cl, [edi]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x2FAE45: and eax, 0x40
	ctx.eax = ctx.eax & 64;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FAE48: and ecx, 0x40
	ctx.ecx = ctx.ecx & 64;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FAE4B: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAE4D: jz 0x002FAE66
	if (ctx.flags.zf) goto loc_2FAE66;
	// 0x2FAE4F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FAE51: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FAE54: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAE55: jz 0x002FAE61
	if (ctx.flags.zf) goto loc_2FAE61;
	// 0x2FAE57: call 0x002F8904
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F8904(ctx, base);
	ctx.esp += 4;
	// 0x2FAE5C: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2FAE5F: jmp 0x002FAE66
	goto loc_2FAE66;
loc_2FAE61:
	// 0x2FAE61: call 0x002F892B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F892B(ctx, base);
	ctx.esp += 4;
loc_2FAE66:
	// 0x2FAE66: mov cx, [edi]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.edi);
	// 0x2FAE69: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAE6C: and cx, bx
	X86_REG16(ctx.ecx) = X86_REG16(ctx.ecx) & X86_REG16(ctx.ebx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.ecx), 16);
	// 0x2FAE6F: neg cx
	{ uint16_t _d = X86_REG16(ctx.ecx);
	  uint16_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int16_t)0, (int16_t)_d, 16);
	  ctx.flags.cf = (_d != 0);
	  X86_REG16(ctx.ecx) = _res; }
	// 0x2FAE72: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FAE74: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAE76: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x2FAE78: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FAE7A: setnz dl
	X86_REG8L(ctx.edx) = (!ctx.flags.zf) ? 1 : 0;
	// 0x2FAE7D: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAE7F: jz 0x002FAEC9
	if (ctx.flags.zf) goto loc_2FAEC9;
	// 0x2FAE81: mov cl, [edi]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x2FAE83: and cl, 0x03
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x2FAE86: cmp cl, 0x03
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FAE89: jnz 0x002FAEC9
	if (!ctx.flags.zf) goto loc_2FAEC9;
	// 0x2FAE8B: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FAE8F: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2FAE91: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FAE93: and eax, 0x40000
	ctx.eax = ctx.eax & 262144;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FAE98:
	// 0x2FAE98: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FAE9E: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FAEA1: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAEA3: jb 0x002FAE98
	if (ctx.flags.cf) goto loc_2FAE98;
	// 0x2FAEA5: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAEA7: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FAEA9: jbe 0x002FAEC9
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FAEC9;
	// 0x2FAEAB: and eax, 0xFFFF0000
	ctx.eax = ctx.eax & -65536;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FAEB0: lea ecx, [esi+0x0C]
	ctx.ecx = ctx.esi + 0xCu;
loc_2FAEB3:
	// 0x2FAEB3: movzx ebx, word ptr [ecx]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx));
	// 0x2FAEB6: or ebx, eax
	ctx.ebx = ctx.ebx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x2FAEB8: mov [0xFE820140], ebx
	X86_MEM_WRITE_u32(base, 0xFE820140u, ctx.ebx);
	// 0x2FAEBE: movzx ebx, byte ptr [esi+0x64]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FAEC2: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FAEC3: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FAEC4: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FAEC5: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAEC7: jb 0x002FAEB3
	if (ctx.flags.cf) goto loc_2FAEB3;
loc_2FAEC9:
	// 0x2FAEC9: mov dx, 0xFBBB
	X86_REG16(ctx.edx) = (uint16_t)(-1093);
	// 0x2FAECD: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FAECF: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
	// 0x2FAED4: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAED7: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
loc_2FAEDC:
	// 0x2FAEDC: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FAEDF: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FAEE4: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FAEE7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAEE8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAEE9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAEEA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FAEEB: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FAEEE(X86Context& ctx, uint8_t* base) {
	// 0x2FAEEE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAEEF: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FAEF1: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FAEF4: and dword ptr [ebp-0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, X86_MEM_READ_u32(base, ctx.ebp - 0x18u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x18u), 32);
	// 0x2FAEF8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAEF9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAEFA: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FAEFC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAEFD: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x2FAF00: mov [ebp-0x08], esi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.esi);
	// 0x2FAF03: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FAF08: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAF0B: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FAF0D: jnz 0x002FAF1E
	if (!ctx.flags.zf) goto loc_2FAF1E;
	// 0x2FAF0F: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FAF12: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2FAF18: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FAF1A: jz 0x002FAF1E
	if (ctx.flags.zf) goto loc_2FAF1E;
	// 0x2FAF1C: mov edx, eax
	ctx.edx = ctx.eax;
loc_2FAF1E:
	// 0x2FAF1E: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FAF21: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FAF23: mov edi, 0xFFFF
	ctx.edi = 65535;
	// 0x2FAF28: jnz 0x002FAF3C
	if (!ctx.flags.zf) goto loc_2FAF3C;
	// 0x2FAF2A: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FAF2D: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FAF33: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FAF35: jz 0x002FAF7D
	if (ctx.flags.zf) goto loc_2FAF7D;
	// 0x2FAF37: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2FAF39: mov [ebp+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.ecx);
loc_2FAF3C:
	// 0x2FAF3C: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x2FAF3E: jz 0x002FAF46
	if (ctx.flags.zf) goto loc_2FAF46;
	// 0x2FAF40: cmp dword ptr [edx+0x40], 0x02
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edx + 0x40u); uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAF44: jz 0x002FAF7D
	if (ctx.flags.zf) goto loc_2FAF7D;
loc_2FAF46:
	// 0x2FAF46: mov eax, [0x00300498]
	ctx.eax = X86_MEM_READ_u32(base, 0x300498u);
	// 0x2FAF4B: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x2FAF4D: and edx, edi
	ctx.edx = ctx.edx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FAF4F: cmp edx, 0x02
	{ uint32_t _d = ctx.edx; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAF52: jz 0x002FAF5F
	if (ctx.flags.zf) goto loc_2FAF5F;
	// 0x2FAF54: test eax, 0x10000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 65536, 32);
	// 0x2FAF59: jnz 0x002FAF5F
	if (!ctx.flags.zf) goto loc_2FAF5F;
	// 0x2FAF5B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAF5D: jmp 0x002FAF62
	goto loc_2FAF62;
loc_2FAF5F:
	// 0x2FAF5F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAF61: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_2FAF62:
	// 0x2FAF62: fld [ecx+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x2Cu));
	// 0x2FAF65: lea edx, [ebp-0x14]
	ctx.edx = ctx.ebp - 0x14u;
	// 0x2FAF68: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAF69: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAF6A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAF6B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FAF6C: fstp [esp+0x04]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2FAF70: fld [ecx+0x28]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx + 0x28u));
	// 0x2FAF73: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x2FAF76: call 0x002FA4D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4D0(ctx, base);
	ctx.esp += 4;
	// 0x2FAF7B: jmp 0x002FAF88
	goto loc_2FAF88;
loc_2FAF7D:
	// 0x2FAF7D: mov eax, 0x30034C
	ctx.eax = 3146572;
	// 0x2FAF82: mov [ebp-0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.eax);
	// 0x2FAF85: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
loc_2FAF88:
	// 0x2FAF88: mov cl, [esi+0x66]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0x66u);
	// 0x2FAF8B: movzx eax, word ptr [esi+0x0C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0xCu));
	// 0x2FAF8F: movzx edx, cl
	ctx.edx = (uint32_t)(X86_REG8L(ctx.ecx));
	// 0x2FAF92: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x2FAF94: setz cl
	X86_REG8L(ctx.ecx) = (ctx.flags.zf) ? 1 : 0;
	// 0x2FAF97: lea eax, [edx+eax*2]
	ctx.eax = ctx.edx + ctx.eax * 2;
	// 0x2FAF9A: mov [esi+0x66], cl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x66u, X86_REG8L(ctx.ecx));
loc_2FAF9D:
	// 0x2FAF9D: mov ecx, [0xFE820010]
	ctx.ecx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FAFA3: and ecx, 0xFFFFFFFC
	ctx.ecx = ctx.ecx & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FAFA6: cmp ecx, 0x4C
	{ uint32_t _d = ctx.ecx; uint32_t _s = 76;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAFA9: jb 0x002FAF9D
	if (ctx.flags.cf) goto loc_2FAF9D;
	// 0x2FAFAB: and eax, edi
	ctx.eax = ctx.eax & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FAFAD: mov [0xFE820160], eax
	X86_MEM_WRITE_u32(base, 0xFE820160u, ctx.eax);
	// 0x2FAFB2: mov edi, [ebp-0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2FAFB5: mov ecx, [ebp-0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x2FAFB8: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x2FAFBB: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x2FAFBE: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAFC0: sub [ebp-0x04], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x2FAFC3: mov dword ptr [ebp+0x08], 0xFE820400
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, -25033728);
	// 0x2FAFCA: lea eax, [ecx+0x01]
	ctx.eax = ctx.ecx + 0x1u;
loc_2FAFCD:
	// 0x2FAFCD: mov ebx, [ebp-0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FAFD0: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FAFD2: mov dh, [ebx+eax*1]
	X86_REG8H(ctx.edx) = X86_MEM_READ_u8(base, ctx.ebx + ctx.eax);
	// 0x2FAFD5: movzx ebx, byte ptr [edi+esi*2]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + ctx.esi * 2));
	// 0x2FAFD9: mov dl, [eax]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x2FAFDB: shl edx, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FAFDE: or edx, ebx
	ctx.edx = ctx.edx | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FAFE0: movzx ebx, byte ptr [eax-0x01]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax - 0x1u));
	// 0x2FAFE4: shl edx, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FAFE7: or edx, ebx
	ctx.edx = ctx.edx | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x2FAFE9: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FAFEC: add dword ptr [ebp+0x08], 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x8u), (int32_t)4, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, (uint32_t)_res); }
	// 0x2FAFF0: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x2FAFF1: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FAFF2: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FAFF3: cmp dword ptr [ebp+0x08], 0xFE82043C
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = -25033668;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FAFFA: mov [ebx], edx
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.edx);
	// 0x2FAFFC: jl 0x002FAFCD
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2FAFCD;
	// 0x2FAFFE: lea eax, [esi+esi*1]
	ctx.eax = ctx.esi + ctx.esi;
	// 0x2FB001: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB003: mov dh, [eax+edi*1]
	X86_REG8H(ctx.edx) = X86_MEM_READ_u8(base, ctx.eax + ctx.edi);
	// 0x2FB006: mov dl, [eax+ecx*1]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.eax + ctx.ecx);
	// 0x2FB009: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x2FB00C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB00E: jz 0x002FB02E
	if (ctx.flags.zf) goto loc_2FB02E;
	// 0x2FB010: fld [eax+0x28]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x28u));
	// 0x2FB013: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x2FB019: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x2FB01B: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x2FB01E: jnz 0x002FB026
	if (!ctx.flags.zf) goto loc_2FB026;
	// 0x2FB020: movzx eax, byte ptr [ecx+0x1F]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ecx + 0x1Fu));
	// 0x2FB024: jmp 0x002FB030
	goto loc_2FB030;
loc_2FB026:
	// 0x2FB026: movzx eax, byte ptr [edi+0x1F]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + 0x1Fu));
	// 0x2FB02A: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x2FB02C: jmp 0x002FB030
	goto loc_2FB030;
loc_2FB02E:
	// 0x2FB02E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_2FB030:
	// 0x2FB030: shl eax, 0x19
	{ auto _cnt = 0x19u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB033: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB035: mov [0xFE82043C], eax
	X86_MEM_WRITE_u32(base, 0xFE82043Cu, ctx.eax);
	// 0x2FB03A: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2FB03D: movzx eax, word ptr [eax+0x0C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0xCu));
	// 0x2FB041: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2FB046: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2FB049: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x2FB04C: mov [0xFE82031C], eax
	X86_MEM_WRITE_u32(base, 0xFE82031Cu, ctx.eax);
	// 0x2FB051: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB056: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB057: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB058: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB059: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB05A: ret 0x08
	ctx.esp += 8;
	return;
}

void CMcpxVoiceClient_SetFilter(X86Context& ctx, uint8_t* base) {
	// 0x2FB05D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB05E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB060: sub esp, 0x20
	{ uint32_t _d = ctx.esp; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB063: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FB067: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB068: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB069: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x2FB06B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB06C: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB06F: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB074: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FB077: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x2FB079: mov edx, 0xFFFF
	ctx.edx = 65535;
	// 0x2FB07E: jz 0x002FB093
	if (ctx.flags.zf) goto loc_2FB093;
	// 0x2FB080: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB082: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB083: lea edi, [ebp-0x20]
	ctx.edi = ctx.ebp - 0x20u;
	// 0x2FB086: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x2FB088: mov esi, [ebp-0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x2FB08B: mov ecx, [ebp-0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x18u);
	// 0x2FB08E: mov eax, [ebp-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x1Cu);
	// 0x2FB091: jmp 0x002FB0BF
	goto loc_2FB0BF;
loc_2FB093:
	// 0x2FB093: mov ecx, [ebx+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x38u);
	// 0x2FB096: mov edi, [ebx+0x3C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0x3Cu);
	// 0x2FB099: movzx esi, word ptr [ebx+0x3A]
	ctx.esi = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebx + 0x3Au));
	// 0x2FB09D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB09F: mov al, [ebx+0x1A]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + 0x1Au);
	// 0x2FB0A2: and ecx, edx
	ctx.ecx = ctx.ecx & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FB0A4: and eax, 0x03
	ctx.eax = ctx.eax & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB0A7: mov [ebp-0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x20u, ctx.eax);
	// 0x2FB0AA: mov eax, [ebx+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x18u);
	// 0x2FB0AD: shr eax, 0x12
	{ auto _cnt = 0x12u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB0B0: and eax, 0x07
	ctx.eax = ctx.eax & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB0B3: and edi, edx
	ctx.edi = ctx.edi & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2FB0B5: mov [ebp-0x10], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edi);
	// 0x2FB0B8: movzx edi, word ptr [ebx+0x3E]
	ctx.edi = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebx + 0x3Eu));
	// 0x2FB0BC: mov [ebp-0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edi);
loc_2FB0BF:
	// 0x2FB0BF: mov edi, [ebx+0x70]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0x70u);
	// 0x2FB0C2: test dword ptr [edi+0x08], 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.edi + 0x8u) & 2097168, 32);
	// 0x2FB0C9: mov edi, [ebp-0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x20u);
	// 0x2FB0CC: jz 0x002FB0D5
	if (ctx.flags.zf) goto loc_2FB0D5;
	// 0x2FB0CE: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x2FB0D0: jnz 0x002FB0D5
	if (!ctx.flags.zf) goto loc_2FB0D5;
	// 0x2FB0D2: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB0D4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FB0D5:
	// 0x2FB0D5: and eax, 0x07
	ctx.eax = ctx.eax & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB0D8: shl eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB0DB: and edi, 0x03
	ctx.edi = ctx.edi & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2FB0DE: or eax, edi
	ctx.eax = ctx.eax | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB0E0: mov edi, [ebx+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0x18u);
	// 0x2FB0E3: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB0E6: and ecx, edx
	ctx.ecx = ctx.ecx & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FB0E8: and edi, 0xFFE0FFFF
	ctx.edi = ctx.edi & -2031617;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x2FB0EE: shl esi, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x2FB0F1: or eax, edi
	ctx.eax = ctx.eax | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB0F3: or esi, ecx
	ctx.esi = ctx.esi | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x2FB0F5: mov ecx, [ebx+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x70u);
	// 0x2FB0F8: mov [ebx+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x18u, ctx.eax);
	// 0x2FB0FB: lea eax, [ecx+0xB8]
	ctx.eax = ctx.ecx + 0xB8u;
	// 0x2FB101: mov [ebx+0x38], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x38u, ctx.esi);
	// 0x2FB104: cmp dword ptr [eax], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB107: jz 0x002FB120
	if (ctx.flags.zf) goto loc_2FB120;
	// 0x2FB109: test byte ptr [ecx+0x0B], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ecx + 0xBu) & 1, 8);
	// 0x2FB10D: jz 0x002FB120
	if (ctx.flags.zf) goto loc_2FB120;
	// 0x2FB10F: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FB111: mov ecx, [ecx+0x30]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x30u);
	// 0x2FB114: and ecx, edx
	ctx.ecx = ctx.ecx & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FB116: mov [ebx+0x3C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x3Cu, ctx.ecx);
	// 0x2FB119: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FB11B: mov eax, [eax+0x34]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x34u);
	// 0x2FB11E: jmp 0x002FB128
	goto loc_2FB128;
loc_2FB120:
	// 0x2FB120: mov ecx, [ebp-0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2FB123: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2FB126: and ecx, edx
	ctx.ecx = ctx.ecx & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_2FB128:
	// 0x2FB128: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB12A: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB12D: or eax, ecx
	ctx.eax = ctx.eax | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB12F: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FB130: test [ebx+0x12], dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx + 0x12u) & X86_REG8L(ctx.edx), 8);
	// 0x2FB133: mov [ebx+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x3Cu, ctx.eax);
	// 0x2FB136: jz 0x002FB196
	if (ctx.flags.zf) goto loc_2FB196;
	// 0x2FB138: movzx eax, byte ptr [ebx+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ebx + 0x64u));
	// 0x2FB13C: lea ecx, [eax+eax*2]
	ctx.ecx = ctx.eax + ctx.eax * 2;
	// 0x2FB13F: shl ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
loc_2FB141:
	// 0x2FB141: mov esi, [0xFE820010]
	ctx.esi = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB147: shr esi, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x2FB14A: cmp esi, ecx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB14C: jb 0x002FB141
	if (ctx.flags.cf) goto loc_2FB141;
	// 0x2FB14E: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB150: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB152: jbe 0x002FB196
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB196;
	// 0x2FB154: lea eax, [ebx+0x0C]
	ctx.eax = ctx.ebx + 0xCu;
loc_2FB157:
	// 0x2FB157: movzx esi, word ptr [eax]
	ctx.esi = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2FB15A: mov [0xFE8202F8], esi
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.esi);
	// 0x2FB160: mov [0xFE8202FC], edx
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, ctx.edx);
	// 0x2FB166: mov esi, [ebx+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebx + 0x18u);
	// 0x2FB169: mov [0xFE820318], esi
	X86_MEM_WRITE_u32(base, 0xFE820318u, ctx.esi);
	// 0x2FB16F: mov esi, [ebx+0x38]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebx + 0x38u);
	// 0x2FB172: mov [0xFE820374], esi
	X86_MEM_WRITE_u32(base, 0xFE820374u, ctx.esi);
	// 0x2FB178: mov esi, [ebx+0x3C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebx + 0x3Cu);
	// 0x2FB17B: mov [0xFE820378], esi
	X86_MEM_WRITE_u32(base, 0xFE820378u, ctx.esi);
	// 0x2FB181: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2FB18B: movzx esi, byte ptr [ebx+0x64]
	ctx.esi = (uint32_t)(X86_MEM_READ_u8(base, ctx.ebx + 0x64u));
	// 0x2FB18F: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB190: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB191: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB192: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB194: jb 0x002FB157
	if (ctx.flags.cf) goto loc_2FB157;
loc_2FB196:
	// 0x2FB196: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB199: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB19E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB19F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB1A0: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB1A2: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB1A3: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB1A4: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FB1A7(X86Context& ctx, uint8_t* base) {
	// 0x2FB1A7: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB1A8: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB1AA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB1AB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB1AC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB1AD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB1AE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB1B0: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB1B2: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB1B5: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
	// 0x2FB1B8: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB1BD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB1BF: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB1C0: test [esi+0x12], al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & X86_REG8L(ctx.eax), 8);
	// 0x2FB1C3: jz 0x002FB224
	if (ctx.flags.zf) goto loc_2FB224;
	// 0x2FB1C5: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB1C9: movzx ecx, word ptr [esi+ecx*2+0x0A]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + ctx.ecx * 2 + 0xAu));
	// 0x2FB1CE: mov edx, [0x00300C28]
	ctx.edx = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2FB1D4: shl ecx, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x2FB1D7: test dword ptr [ecx+edx*1+0x54], 0x100000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ecx + ctx.edx + 0x54u) & 1048576, 32);
	// 0x2FB1DF: jnz 0x002FB224
	if (!ctx.flags.zf) goto loc_2FB224;
loc_2FB1E1:
	// 0x2FB1E1: mov ecx, [0xFE820010]
	ctx.ecx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB1E7: and ecx, 0xFFFFFFFC
	ctx.ecx = ctx.ecx & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FB1EA: cmp ecx, 0x0C
	{ uint32_t _d = ctx.ecx; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB1ED: jb 0x002FB1E1
	if (ctx.flags.cf) goto loc_2FB1E1;
	// 0x2FB1EF: movzx ecx, word ptr [esi+0x0C]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0xCu));
	// 0x2FB1F3: mov [0xFE8202F8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.ecx);
	// 0x2FB1F9: mov [0xFE8202FC], eax
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, ctx.eax);
	// 0x2FB1FE: movzx eax, word ptr [esi+0x0C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0xCu));
	// 0x2FB202: mov ecx, [0x00300C28]
	ctx.ecx = X86_MEM_READ_u32(base, 0x300C28u);
	// 0x2FB208: shl eax, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB20B: mov eax, [eax+ecx*1+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + ctx.ecx + 0x58u);
	// 0x2FB20F: and eax, 0xFFFFFF
	ctx.eax = ctx.eax & 16777215;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB214: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB215: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB217: mov [0xFE8202FC], edi
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, ctx.edi);
	// 0x2FB21D: call 0x002F9033
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F9033(ctx, base);
	ctx.esp += 4;
	// 0x2FB222: mov edi, eax
	ctx.edi = ctx.eax;
loc_2FB224:
	// 0x2FB224: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB227: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB22C: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x2FB22E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB22F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB230: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB231: ret
	return;
}

void sub_2FB232(X86Context& ctx, uint8_t* base) {
	// 0x2FB232: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x2FB236: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FB239: add eax, [0x00300C38]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, 0x300C38u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, 0x300C38u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB23F: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FB241: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x2FB245: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2FB248: call 0x002FA4F2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4F2(ctx, base);
	ctx.esp += 4;
	// 0x2FB24D: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FB250(X86Context& ctx, uint8_t* base) {
	// 0x2FB250: movzx eax, word ptr [esp+0x04]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esp + 0x4u));
	// 0x2FB255: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB257: lea eax, [eax*4+0x02]
	ctx.eax = ctx.eax * 4 + 0x2u;
	// 0x2FB25E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB25F: call 0x002FB232
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB232(ctx, base);
	ctx.esp += 4;
	// 0x2FB264: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FB267(X86Context& ctx, uint8_t* base) {
	// 0x2FB267: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB268: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB26A: sub esp, 0x38
	{ uint32_t _d = ctx.esp; uint32_t _s = 56;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB26D: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FB271: and dword ptr [ebp-0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, X86_MEM_READ_u32(base, ctx.ebp - 0x10u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x10u), 32);
	// 0x2FB275: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB276: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB277: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB279: lea ecx, [ebp-0x14]
	ctx.ecx = ctx.ebp - 0x14u;
	// 0x2FB27C: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB281: lea ebx, [esi+0x12]
	ctx.ebx = ctx.esi + 0x12u;
	// 0x2FB284: test byte ptr [ebx], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx) & 1, 8);
	// 0x2FB287: jnz 0x002FB3D2
	if (!ctx.flags.zf) goto loc_2FB3D2;
	// 0x2FB28D: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FB290: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB291: call 0x002F83D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F83D0(ctx, base);
	ctx.esp += 4;
	// 0x2FB296: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB298: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2FB29B: jl 0x002FB3D2
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_2FB3D2;
	// 0x2FB2A1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB2A2: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB2A4: lea edi, [esi+0x0C]
	ctx.edi = ctx.esi + 0xCu;
	// 0x2FB2A7: mov ax, [edi]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi);
	// 0x2FB2AA: lea ecx, [esi+0x68]
	ctx.ecx = ctx.esi + 0x68u;
	// 0x2FB2AD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB2AE: call 0x002FB250
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB250(ctx, base);
	ctx.esp += 4;
	// 0x2FB2B3: mov dx, 0x01
	X86_REG16(ctx.edx) = (uint16_t)(1);
	// 0x2FB2B7: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x2FB2B9: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2FB2BE: lea ebx, [esi+0x14]
	ctx.ebx = ctx.esi + 0x14u;
	// 0x2FB2C1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB2C2: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2FB2C5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB2C6: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB2C8: call 0x002FA6F4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA6F4(ctx, base);
	ctx.esp += 4;
	// 0x2FB2CD: lea eax, [ebp-0x38]
	ctx.eax = ctx.ebp - 0x38u;
	// 0x2FB2D0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB2D1: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB2D3: call 0x002FA7A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA7A5(ctx, base);
	ctx.esp += 4;
	// 0x2FB2D8: lea eax, [ebp-0x0C]
	ctx.eax = ctx.ebp - 0xCu;
	// 0x2FB2DB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB2DC: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB2DE: call 0x002FA9F9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA9F9(ctx, base);
	ctx.esp += 4;
	// 0x2FB2E3: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB2E5: cmp [esi+0x64], al
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi + 0x64u); uint8_t _s = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB2E8: jbe 0x002FB3BA
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB3BA;
loc_2FB2EE:
	// 0x2FB2EE: mov ecx, [0xFE820010]
	ctx.ecx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB2F4: and ecx, 0xFFFFFFFC
	ctx.ecx = ctx.ecx & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FB2F7: cmp ecx, 0x48
	{ uint32_t _d = ctx.ecx; uint32_t _s = 72;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB2FA: jb 0x002FB2EE
	if (ctx.flags.cf) goto loc_2FB2EE;
	// 0x2FB2FC: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB2FE: movzx ecx, word ptr [edi]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi));
	// 0x2FB301: mov [0xFE8202F8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.ecx);
	// 0x2FB307: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x2FB309: jz 0x002FB311
	if (ctx.flags.zf) goto loc_2FB311;
	// 0x2FB30B: or ecx, 0x400000
	ctx.ecx = ctx.ecx | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_2FB311:
	// 0x2FB311: mov [0xFE820304], ecx
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.ecx);
	// 0x2FB317: mov ecx, [esi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x2FB31A: mov [0xFE820318], ecx
	X86_MEM_WRITE_u32(base, 0xFE820318u, ctx.ecx);
	// 0x2FB320: mov ecx, [esi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x2FB323: mov [0xFE820308], ecx
	X86_MEM_WRITE_u32(base, 0xFE820308u, ctx.ecx);
	// 0x2FB329: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x2FB32C: mov [0xFE82030C], ecx
	X86_MEM_WRITE_u32(base, 0xFE82030Cu, ctx.ecx);
	// 0x2FB332: mov ecx, [esi+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x2FB335: mov [0xFE820310], ecx
	X86_MEM_WRITE_u32(base, 0xFE820310u, ctx.ecx);
	// 0x2FB33B: mov ecx, [esi+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x2FB33E: mov [0xFE820314], ecx
	X86_MEM_WRITE_u32(base, 0xFE820314u, ctx.ecx);
	// 0x2FB344: mov ecx, [esi+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x2FB347: mov [0xFE820350], ecx
	X86_MEM_WRITE_u32(base, 0xFE820350u, ctx.ecx);
	// 0x2FB34D: mov ecx, [esi+0x30]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	// 0x2FB350: mov [0xFE82036C], ecx
	X86_MEM_WRITE_u32(base, 0xFE82036Cu, ctx.ecx);
	// 0x2FB356: mov ecx, [esi+0x34]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x34u);
	// 0x2FB359: mov [0xFE820370], ecx
	X86_MEM_WRITE_u32(base, 0xFE820370u, ctx.ecx);
	// 0x2FB35F: mov ecx, [esi+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x2FB362: mov [0xFE820374], ecx
	X86_MEM_WRITE_u32(base, 0xFE820374u, ctx.ecx);
	// 0x2FB368: mov ecx, [esi+0x3C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x3Cu);
	// 0x2FB36B: mov [0xFE820378], ecx
	X86_MEM_WRITE_u32(base, 0xFE820378u, ctx.ecx);
	// 0x2FB371: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2FB374: mov [0xFE820300], ecx
	X86_MEM_WRITE_u32(base, 0xFE820300u, ctx.ecx);
	// 0x2FB37A: mov ecx, [ebp+eax*4-0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x38u);
	// 0x2FB37E: mov [0xFE820360], ecx
	X86_MEM_WRITE_u32(base, 0xFE820360u, ctx.ecx);
	// 0x2FB384: mov ecx, [ebp+eax*4-0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x2Cu);
	// 0x2FB388: mov [0xFE820364], ecx
	X86_MEM_WRITE_u32(base, 0xFE820364u, ctx.ecx);
	// 0x2FB38E: mov ecx, [ebp+eax*4-0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u);
	// 0x2FB392: mov [0xFE820368], ecx
	X86_MEM_WRITE_u32(base, 0xFE820368u, ctx.ecx);
	// 0x2FB398: mov ecx, [ebp-0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2FB39B: mov [0xFE82037C], ecx
	X86_MEM_WRITE_u32(base, 0xFE82037Cu, ctx.ecx);
	// 0x2FB3A1: mov dword ptr [0xFE82031C], 0xFFFF
	X86_MEM_WRITE_u32(base, 0xFE82031Cu, 65535);
	// 0x2FB3AB: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB3AF: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB3B0: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FB3B1: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FB3B2: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB3B4: jb 0x002FB2EE
	if (ctx.flags.cf) goto loc_2FB2EE;
loc_2FB3BA:
	// 0x2FB3BA: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB3BD: test dword ptr [eax+0x08], 0x200010
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 2097168, 32);
	// 0x2FB3C4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB3C5: jz 0x002FB3D2
	if (ctx.flags.zf) goto loc_2FB3D2;
	// 0x2FB3C7: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB3C9: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB3CB: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB3CD: call 0x002FAEEE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAEEE(ctx, base);
	ctx.esp += 4;
loc_2FB3D2:
	// 0x2FB3D2: lea ecx, [ebp-0x14]
	ctx.ecx = ctx.ebp - 0x14u;
	// 0x2FB3D5: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB3DA: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FB3DD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB3DE: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB3DF: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB3E0: ret
	return;
}

void CMcpxVoiceClient_SetMixBins(X86Context& ctx, uint8_t* base) {
	// 0x2FB3E1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB3E2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB3E4: sub esp, 0x30
	{ uint32_t _d = ctx.esp; uint32_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB3E7: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x2FB3EB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB3EC: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB3EE: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FB3F1: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB3F6: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FB3FA: jz 0x002FB495
	if (ctx.flags.zf) goto loc_2FB495;
	// 0x2FB400: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB401: lea edi, [esi+0x14]
	ctx.edi = ctx.esi + 0x14u;
	// 0x2FB404: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB405: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x2FB408: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB409: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB40B: call 0x002FA6F4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA6F4(ctx, base);
	ctx.esp += 4;
	// 0x2FB410: lea eax, [ebp-0x30]
	ctx.eax = ctx.ebp - 0x30u;
	// 0x2FB413: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB414: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB416: call 0x002FA7A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA7A5(ctx, base);
	ctx.esp += 4;
	// 0x2FB41B: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB41F: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2FB421: shl ecx, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
loc_2FB424:
	// 0x2FB424: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB42A: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FB42D: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB42F: jb 0x002FB424
	if (ctx.flags.cf) goto loc_2FB424;
	// 0x2FB431: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB433: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB435: jbe 0x002FB494
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB494;
	// 0x2FB437: lea edx, [esi+0x0C]
	ctx.edx = ctx.esi + 0xCu;
loc_2FB43A:
	// 0x2FB43A: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FB43C: movzx eax, word ptr [edx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FB43F: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2FB444: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FB447: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2FB451: mov [0xFE820300], eax
	X86_MEM_WRITE_u32(base, 0xFE820300u, ctx.eax);
	// 0x2FB456: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FB458: jz 0x002FB45F
	if (ctx.flags.zf) goto loc_2FB45F;
	// 0x2FB45A: or eax, 0x400000
	ctx.eax = ctx.eax | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FB45F:
	// 0x2FB45F: mov [0xFE820304], eax
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.eax);
	// 0x2FB464: mov eax, [ebp+ecx*4-0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x30u);
	// 0x2FB468: mov [0xFE820360], eax
	X86_MEM_WRITE_u32(base, 0xFE820360u, ctx.eax);
	// 0x2FB46D: mov eax, [ebp+ecx*4-0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x24u);
	// 0x2FB471: mov [0xFE820364], eax
	X86_MEM_WRITE_u32(base, 0xFE820364u, ctx.eax);
	// 0x2FB476: mov eax, [ebp+ecx*4-0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x18u);
	// 0x2FB47A: mov [0xFE820368], eax
	X86_MEM_WRITE_u32(base, 0xFE820368u, ctx.eax);
	// 0x2FB47F: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2FB489: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB48D: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB48E: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FB48F: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FB490: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB492: jb 0x002FB43A
	if (ctx.flags.cf) goto loc_2FB43A;
loc_2FB494:
	// 0x2FB494: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FB495:
	// 0x2FB495: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FB498: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB49D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB49F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB4A0: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB4A1: ret
	return;
}

void CMcpxVoiceClient_SetVolume(X86Context& ctx, uint8_t* base) {
	// 0x2FB4A2: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB4A3: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB4A5: sub esp, 0x2C
	{ uint32_t _d = ctx.esp; uint32_t _s = 44;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB4A8: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FB4AC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB4AD: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB4AF: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB4B2: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB4B7: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FB4BB: jz 0x002FB52D
	if (ctx.flags.zf) goto loc_2FB52D;
	// 0x2FB4BD: lea eax, [ebp-0x2C]
	ctx.eax = ctx.ebp - 0x2Cu;
	// 0x2FB4C0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB4C1: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB4C3: call 0x002FA7A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA7A5(ctx, base);
	ctx.esp += 4;
	// 0x2FB4C8: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB4CC: lea eax, [ecx+ecx*2]
	ctx.eax = ctx.ecx + ctx.ecx * 2;
	// 0x2FB4CF: shl eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
loc_2FB4D1:
	// 0x2FB4D1: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB4D7: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FB4DA: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB4DC: jb 0x002FB4D1
	if (ctx.flags.cf) goto loc_2FB4D1;
	// 0x2FB4DE: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB4E0: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FB4E2: jbe 0x002FB52D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB52D;
	// 0x2FB4E4: lea ecx, [esi+0x0C]
	ctx.ecx = ctx.esi + 0xCu;
loc_2FB4E7:
	// 0x2FB4E7: movzx edx, word ptr [ecx]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ecx));
	// 0x2FB4EA: mov [0xFE8202F8], edx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.edx);
	// 0x2FB4F0: mov edx, [ebp+eax*4-0x2C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x2Cu);
	// 0x2FB4F4: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2FB4FE: mov [0xFE820360], edx
	X86_MEM_WRITE_u32(base, 0xFE820360u, ctx.edx);
	// 0x2FB504: mov edx, [ebp+eax*4-0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x20u);
	// 0x2FB508: mov [0xFE820364], edx
	X86_MEM_WRITE_u32(base, 0xFE820364u, ctx.edx);
	// 0x2FB50E: mov edx, [ebp+eax*4-0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + ctx.eax * 4 - 0x14u);
	// 0x2FB512: mov [0xFE820368], edx
	X86_MEM_WRITE_u32(base, 0xFE820368u, ctx.edx);
	// 0x2FB518: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2FB522: movzx edx, byte ptr [esi+0x64]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB526: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB527: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB528: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB529: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB52B: jb 0x002FB4E7
	if (ctx.flags.cf) goto loc_2FB4E7;
loc_2FB52D:
	// 0x2FB52D: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB530: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB535: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB537: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB538: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB539: ret
	return;
}

void CMcpxVoiceClient_SetPitch(X86Context& ctx, uint8_t* base) {
loc_2FB53A:
	// 0x2FB53A: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB53B: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB53D: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB540: and dword ptr [ebp-0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, X86_MEM_READ_u32(base, ctx.ebp - 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	// 0x2FB544: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB545: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB547: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB548: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FB54B: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB550: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB553: test dword ptr [eax+0x08], 0x182000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 1581056, 32);
	// 0x2FB55A: jz 0x002FB573
	if (ctx.flags.zf) goto loc_2FB573;
	// 0x2FB55C: lea edi, [esi+0x44]
	ctx.edi = ctx.esi + 0x44u;
	// 0x2FB55F: mov esi, [edi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FB561: jmp 0x002FB56D
	goto loc_2FB56D;
loc_2FB563:
	// 0x2FB563: lea ecx, [esi-0x5C]
	ctx.ecx = ctx.esi - 0x5Cu;
	// 0x2FB566: call 0x002FB53A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetPitch(ctx, base);
	ctx.esp += 4;
	// 0x2FB56B: mov esi, [esi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi);
loc_2FB56D:
	// 0x2FB56D: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB56F: jnz 0x002FB563
	if (!ctx.flags.zf) goto loc_2FB563;
	// 0x2FB571: jmp 0x002FB5BE
	goto loc_2FB5BE;
loc_2FB573:
	// 0x2FB573: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FB577: jz 0x002FB5BE
	if (ctx.flags.zf) goto loc_2FB5BE;
	// 0x2FB579: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x2FB57C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB57D: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB57F: call 0x002FA9F9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA9F9(ctx, base);
	ctx.esp += 4;
	// 0x2FB584: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB588: lea ecx, [eax+eax*1]
	ctx.ecx = ctx.eax + ctx.eax;
loc_2FB58B:
	// 0x2FB58B: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB591: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FB594: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB596: jb 0x002FB58B
	if (ctx.flags.cf) goto loc_2FB58B;
	// 0x2FB598: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB59A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB59C: jbe 0x002FB5BE
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB5BE;
	// 0x2FB59E: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
loc_2FB5A1:
	// 0x2FB5A1: movzx edx, word ptr [eax]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2FB5A4: mov [0xFE8202F8], edx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.edx);
	// 0x2FB5AA: mov edx, [ebp-0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FB5AD: mov [0xFE82037C], edx
	X86_MEM_WRITE_u32(base, 0xFE82037Cu, ctx.edx);
	// 0x2FB5B3: movzx edx, byte ptr [esi+0x64]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB5B7: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB5B8: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB5B9: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB5BA: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB5BC: jb 0x002FB5A1
	if (ctx.flags.cf) goto loc_2FB5A1;
loc_2FB5BE:
	// 0x2FB5BE: lea ecx, [ebp-0x0C]
	ctx.ecx = ctx.ebp - 0xCu;
	// 0x2FB5C1: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB5C6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB5C7: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB5C9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB5CA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB5CB: ret
	return;
}

void sub_2FB5CC(X86Context& ctx, uint8_t* base) {
	// 0x2FB5CC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB5CD: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB5CF: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FB5D3: jz 0x002FB5E6
	if (ctx.flags.zf) goto loc_2FB5E6;
	// 0x2FB5D5: jmp 0x002FB5DE
	goto loc_2FB5DE;
loc_2FB5D7:
	// 0x2FB5D7: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB5D9: call 0x002FADB4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FADB4(ctx, base);
	ctx.esp += 4;
loc_2FB5DE:
	// 0x2FB5DE: test word ptr [esi+0x12], 0x8000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.esi + 0x12u) & -32768, 16);
	// 0x2FB5E4: jnz 0x002FB5D7
	if (!ctx.flags.zf) goto loc_2FB5D7;
loc_2FB5E6:
	// 0x2FB5E6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB5E7: ret
	return;
}

void sub_2FB5E8(X86Context& ctx, uint8_t* base) {
	// 0x2FB5E8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB5E9: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB5EB: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB5EE: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FB5F4: test byte ptr [eax], 0x1F
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax) & 31, 8);
	// 0x2FB5F7: jz 0x002FB5FE
	if (ctx.flags.zf) goto loc_2FB5FE;
	// 0x2FB5F9: call 0x002FB4A2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetVolume(ctx, base);
	ctx.esp += 4;
loc_2FB5FE:
	// 0x2FB5FE: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB601: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FB607: test byte ptr [eax], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax) & 32, 8);
	// 0x2FB60A: jz 0x002FB613
	if (ctx.flags.zf) goto loc_2FB613;
	// 0x2FB60C: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB60E: call 0x002FB53A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetPitch(ctx, base);
	ctx.esp += 4;
loc_2FB613:
	// 0x2FB613: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB616: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FB61C: test byte ptr [eax], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax) & 64, 8);
	// 0x2FB61F: jz 0x002FB62C
	if (ctx.flags.zf) goto loc_2FB62C;
	// 0x2FB621: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB623: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB625: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB627: call 0x002FAEEE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAEEE(ctx, base);
	ctx.esp += 4;
loc_2FB62C:
	// 0x2FB62C: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB62F: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FB635: test byte ptr [eax], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax) & -128, 8);
	// 0x2FB638: jz 0x002FB643
	if (ctx.flags.zf) goto loc_2FB643;
	// 0x2FB63A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB63C: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB63E: call 0x002FB05D
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_SetFilter(ctx, base);
	ctx.esp += 4;
loc_2FB643:
	// 0x2FB643: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB646: mov eax, [eax+0xB8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB8u);
	// 0x2FB64C: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2FB64F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB650: ret
	return;
}

void sub_2FB651(X86Context& ctx, uint8_t* base) {
	// 0x2FB651: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB652: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB654: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB655: push [esp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB659: mov dword ptr [esi+0x04], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 1);
	// 0x2FB660: mov dword ptr [esi], 0x36C258
	X86_MEM_WRITE_u32(base, ctx.esi, 3588696);
	// 0x2FB666: and dword ptr [esi+0x68], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x68u, X86_MEM_READ_u32(base, ctx.esi + 0x68u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x68u), 32);
	// 0x2FB66A: and dword ptr [esi+0x6C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, X86_MEM_READ_u32(base, ctx.esi + 0x6Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x6Cu), 32);
	// 0x2FB66E: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2FB673: push [esp+0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB677: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x2FB67A: call 0x002F951A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	DirectSound_AddRef_DirectSound_CDirectSound(ctx, base);
	ctx.esp += 4;
	// 0x2FB67F: mov [esi+0x70], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x70u, ctx.eax);
	// 0x2FB682: lea eax, [esi+0x4C]
	ctx.eax = ctx.esi + 0x4Cu;
	// 0x2FB685: mov [esi+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x50u, ctx.eax);
	// 0x2FB688: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2FB68A: lea eax, [esi+0x54]
	ctx.eax = ctx.esi + 0x54u;
	// 0x2FB68D: mov [esi+0x58], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, ctx.eax);
	// 0x2FB690: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2FB692: lea eax, [esi+0x5C]
	ctx.eax = ctx.esi + 0x5Cu;
	// 0x2FB695: mov [esi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x60u, ctx.eax);
	// 0x2FB698: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2FB69A: lea eax, [esi+0x44]
	ctx.eax = ctx.esi + 0x44u;
	// 0x2FB69D: mov [esi+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.eax);
	// 0x2FB6A0: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x2FB6A2: mov byte ptr [esi+0x65], 0xFF
	X86_MEM_WRITE_u8(base, ctx.esi + 0x65u, -1);
	// 0x2FB6A6: lea edi, [esi+0x0C]
	ctx.edi = ctx.esi + 0xCu;
	// 0x2FB6A9: or eax, 0xFFFFFFFF
	ctx.eax = ctx.eax | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB6AC: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x2FB6AD: stosw
	X86_MEM_WRITE_u16(base, ctx.edi, X86_REG16(ctx.eax));
	ctx.edi += ctx.flags.df ? -2 : 2;
	// 0x2FB6AF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB6B0: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FB6B2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB6B3: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_2FB6B6(X86Context& ctx, uint8_t* base) {
	// 0x2FB6B6: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6B7: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB6B9: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6BA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6BB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6BC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6BD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6BE: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB6C0: lea edi, [esi+0x12]
	ctx.edi = ctx.esi + 0x12u;
	// 0x2FB6C3: movzx eax, word ptr [edi]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edi));
	// 0x2FB6C6: and eax, 0xFFFFFFBF
	ctx.eax = ctx.eax & -65;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FB6C9: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB6CB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB6CC: mov [ebp-0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ebx);
	// 0x2FB6CF: call 0x002FAE08
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAE08(ctx, base);
	ctx.esp += 4;
	// 0x2FB6D4: mov al, [edi]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi);
	// 0x2FB6D6: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2FB6D8: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB6DA: jnz 0x002FB7CE
	if (!ctx.flags.zf) goto loc_2FB7CE;
	// 0x2FB6E0: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB6E3: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB6E8: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FB6EB: add dword ptr [eax+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.eax + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax + 0x84u, (uint32_t)_res); }
	// 0x2FB6F2: mov dx, 0x3111
	X86_REG16(ctx.edx) = (uint16_t)(12561);
	// 0x2FB6F6: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FB6F8: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
	// 0x2FB6FD: and word ptr [esi+0x16], 0xFD7F
	X86_MEM_WRITE_u16(base, ctx.esi + 0x16u, X86_MEM_READ_u16(base, ctx.esi + 0x16u) & -641);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u16(base, ctx.esi + 0x16u), 16);
	// 0x2FB703: cmp byte ptr [esi+0x65], 0x03
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi + 0x65u); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB707: jnb 0x002FB75F
	if (!ctx.flags.cf) goto loc_2FB75F;
	// 0x2FB709: mov dx, 0x8000
	X86_REG16(ctx.edx) = (uint16_t)(-32768);
	// 0x2FB70D: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2FB712: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB716: lea ecx, [eax+eax*2]
	ctx.ecx = ctx.eax + ctx.eax * 2;
loc_2FB719:
	// 0x2FB719: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB71F: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FB722: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB724: jb 0x002FB719
	if (ctx.flags.cf) goto loc_2FB719;
	// 0x2FB726: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB728: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB72A: jbe 0x002FB75F
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB75F;
	// 0x2FB72C: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
loc_2FB72F:
	// 0x2FB72F: cmp edx, ebx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB731: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2FB734: mov [0xFE8202F8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.ecx);
	// 0x2FB73A: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FB73D: jz 0x002FB745
	if (ctx.flags.zf) goto loc_2FB745;
	// 0x2FB73F: or ecx, 0x400000
	ctx.ecx = ctx.ecx | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_2FB745:
	// 0x2FB745: mov [0xFE820304], ecx
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.ecx);
	// 0x2FB74B: movzx ecx, word ptr [eax]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax));
	// 0x2FB74E: mov [0xFE820128], ecx
	X86_MEM_WRITE_u32(base, 0xFE820128u, ctx.ecx);
	// 0x2FB754: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB758: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FB759: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB75A: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB75B: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB75D: jb 0x002FB72F
	if (ctx.flags.cf) goto loc_2FB72F;
loc_2FB75F:
	// 0x2FB75F: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FB762: sub dword ptr [eax+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax + 0x84u, (uint32_t)_res); }
	// 0x2FB769: lea eax, [esi+0x78]
	ctx.eax = ctx.esi + 0x78u;
	// 0x2FB76C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB76D: call [0x0036B7DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B7DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FB773: cmp [ebp+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB776: jnz 0x002FB783
	if (!ctx.flags.zf) goto loc_2FB783;
	// 0x2FB778: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FB77A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB77B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB77C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB77D: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB77E: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB780: call [eax+0x1C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x1Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2FB783:
	// 0x2FB783: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB786: mov eax, [eax+0xB0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB0u);
	// 0x2FB78C: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB78E: jz 0x002FB7C4
	if (ctx.flags.zf) goto loc_2FB7C4;
	// 0x2FB790: mov ecx, [eax+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	// 0x2FB793: cmp ecx, ebx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB795: jz 0x002FB7C4
	if (ctx.flags.zf) goto loc_2FB7C4;
	// 0x2FB797: mov eax, [ecx+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x80u);
	// 0x2FB79D: test dword ptr [eax+0x08], 0x82000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 532480, 32);
	// 0x2FB7A4: jz 0x002FB7C4
	if (ctx.flags.zf) goto loc_2FB7C4;
	// 0x2FB7A6: lea edi, [ecx+0x44]
	ctx.edi = ctx.ecx + 0x44u;
	// 0x2FB7A9: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FB7AB: jmp 0x002FB7BA
	goto loc_2FB7BA;
loc_2FB7AD:
	// 0x2FB7AD: mov dl, [eax-0x4A]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.eax - 0x4Au);
	// 0x2FB7B0: and dl, 0x03
	X86_REG8L(ctx.edx) = X86_REG8L(ctx.edx) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.edx), 8);
	// 0x2FB7B3: cmp dl, 0x03
	{ uint8_t _d = X86_REG8L(ctx.edx); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB7B6: jz 0x002FB7C4
	if (ctx.flags.zf) goto loc_2FB7C4;
	// 0x2FB7B8: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
loc_2FB7BA:
	// 0x2FB7BA: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB7BC: jnz 0x002FB7AD
	if (!ctx.flags.zf) goto loc_2FB7AD;
	// 0x2FB7BE: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB7BF: call 0x002FC5F5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxBuffer_Stop(ctx, base);
	ctx.esp += 4;
loc_2FB7C4:
	// 0x2FB7C4: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FB7C7: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB7CC: jmp 0x002FB7DD
	goto loc_2FB7DD;
loc_2FB7CE:
	// 0x2FB7CE: test word ptr [edi], 0x8000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.edi) & -32768, 16);
	// 0x2FB7D3: jnz 0x002FB7DD
	if (!ctx.flags.zf) goto loc_2FB7DD;
	// 0x2FB7D5: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FB7D7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB7D8: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB7DA: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_2FB7DD:
	// 0x2FB7DD: cmp [ebp+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB7E0: jz 0x002FB7E9
	if (ctx.flags.zf) goto loc_2FB7E9;
	// 0x2FB7E2: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB7E4: call 0x002FB5CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB5CC(ctx, base);
	ctx.esp += 4;
loc_2FB7E9:
	// 0x2FB7E9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB7EA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB7EB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB7EC: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB7ED: ret 0x04
	ctx.esp += 4;
	return;
}

void CMcpxVoiceClient_Commit3dSettings(X86Context& ctx, uint8_t* base) {
	// 0x2FB7F0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB7F1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB7F3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB7F4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB7F5: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB7F7: lea ecx, [ebp-0x04]
	ctx.ecx = ctx.ebp - 0x4u;
	// 0x2FB7FA: call 0x002F3FA9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FA9(ctx, base);
	ctx.esp += 4;
	// 0x2FB7FF: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2FB802: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2FB804: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB806: jnz 0x002FB86A
	if (!ctx.flags.zf) goto loc_2FB86A;
	// 0x2FB808: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB80B: push [eax+0xB4]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xB4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB811: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FB814: mov eax, [eax+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x2FB817: add eax, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)48, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FB81A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB81B: call 0x002F6454
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound3DCalculator_Calculate3D(ctx, base);
	ctx.esp += 4;
	// 0x2FB820: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB823: push [eax+0xB8]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xB8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB829: mov edx, [eax+0xB4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2FB82F: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FB832: mov ecx, [ecx+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x2FB835: lea eax, [edx+0x7C]
	ctx.eax = ctx.edx + 0x7Cu;
	// 0x2FB838: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB839: lea eax, [ecx+0x80]
	ctx.eax = ctx.ecx + 0x80u;
	// 0x2FB83F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB840: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB841: add ecx, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)48, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB844: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB845: call 0x002F4FD8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CDirectSound3DCalculator_GetVoiceData(ctx, base);
	ctx.esp += 4;
	// 0x2FB84A: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB84D: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2FB853: and dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, X86_MEM_READ_u32(base, ctx.eax) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax), 32);
	// 0x2FB856: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB859: mov eax, [eax+0xB4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB4u);
	// 0x2FB85F: and dword ptr [eax+0x7C], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x7Cu, X86_MEM_READ_u32(base, ctx.eax + 0x7Cu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x7Cu), 32);
	// 0x2FB863: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB865: call 0x002FB5E8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB5E8(ctx, base);
	ctx.esp += 4;
loc_2FB86A:
	// 0x2FB86A: lea ecx, [ebp-0x04]
	ctx.ecx = ctx.ebp - 0x4u;
	// 0x2FB86D: call 0x002F3FCE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3FCE(ctx, base);
	ctx.esp += 4;
	// 0x2FB872: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB873: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB874: ret
	return;
}

void sub_2FB875(X86Context& ctx, uint8_t* base) {
	// 0x2FB875: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB876: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB878: sub esp, 0x34
	{ uint32_t _d = ctx.esp; uint32_t _s = 52;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB87B: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2FB87F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB880: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB882: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB883: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2FB886: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB88B: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB88E: mov eax, [eax+0xB0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB0u);
	// 0x2FB894: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB896: jnz 0x002FB89C
	if (!ctx.flags.zf) goto loc_2FB89C;
	// 0x2FB898: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB89A: jmp 0x002FB89F
	goto loc_2FB89F;
loc_2FB89C:
	// 0x2FB89C: mov edi, [eax+0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
loc_2FB89F:
	// 0x2FB89F: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2FB8A2: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2FB8A4: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB8A6: jnz 0x002FB8B1
	if (!ctx.flags.zf) goto loc_2FB8B1;
	// 0x2FB8A8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB8AA: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB8AC: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
loc_2FB8B1:
	// 0x2FB8B1: lea eax, [esi+0x5C]
	ctx.eax = ctx.esi + 0x5Cu;
	// 0x2FB8B4: lea ecx, [edi+0x44]
	ctx.ecx = ctx.edi + 0x44u;
	// 0x2FB8B7: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x2FB8B9: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x2FB8BC: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2FB8BF: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FB8C1: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FB8C3: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2FB8C6: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FB8CA: jz 0x002FB974
	if (ctx.flags.zf) goto loc_2FB974;
	// 0x2FB8D0: lea edi, [esi+0x14]
	ctx.edi = ctx.esi + 0x14u;
	// 0x2FB8D3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB8D4: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x2FB8D7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB8D8: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB8DA: call 0x002FA6F4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA6F4(ctx, base);
	ctx.esp += 4;
	// 0x2FB8DF: lea eax, [ebp-0x34]
	ctx.eax = ctx.ebp - 0x34u;
	// 0x2FB8E2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB8E3: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB8E5: call 0x002FA7A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA7A5(ctx, base);
	ctx.esp += 4;
	// 0x2FB8EA: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2FB8ED: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB8EE: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB8F0: call 0x002FA9F9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA9F9(ctx, base);
	ctx.esp += 4;
	// 0x2FB8F5: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB8F9: lea ecx, [eax+eax*8]
	ctx.ecx = ctx.eax + ctx.eax * 8;
loc_2FB8FC:
	// 0x2FB8FC: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FB902: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FB905: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB907: jb 0x002FB8FC
	if (ctx.flags.cf) goto loc_2FB8FC;
	// 0x2FB909: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB90B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FB90D: jbe 0x002FB974
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FB974;
	// 0x2FB90F: lea edx, [esi+0x0C]
	ctx.edx = ctx.esi + 0xCu;
loc_2FB912:
	// 0x2FB912: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FB914: movzx eax, word ptr [edx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FB917: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2FB91C: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FB91F: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2FB929: mov [0xFE820300], eax
	X86_MEM_WRITE_u32(base, 0xFE820300u, ctx.eax);
	// 0x2FB92E: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FB930: jz 0x002FB937
	if (ctx.flags.zf) goto loc_2FB937;
	// 0x2FB932: or eax, 0x400000
	ctx.eax = ctx.eax | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FB937:
	// 0x2FB937: mov [0xFE820304], eax
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.eax);
	// 0x2FB93C: mov eax, [ebp+ecx*4-0x34]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x34u);
	// 0x2FB940: mov [0xFE820360], eax
	X86_MEM_WRITE_u32(base, 0xFE820360u, ctx.eax);
	// 0x2FB945: mov eax, [ebp+ecx*4-0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x28u);
	// 0x2FB949: mov [0xFE820364], eax
	X86_MEM_WRITE_u32(base, 0xFE820364u, ctx.eax);
	// 0x2FB94E: mov eax, [ebp+ecx*4-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x1Cu);
	// 0x2FB952: mov [0xFE820368], eax
	X86_MEM_WRITE_u32(base, 0xFE820368u, ctx.eax);
	// 0x2FB957: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2FB95A: mov [0xFE82037C], eax
	X86_MEM_WRITE_u32(base, 0xFE82037Cu, ctx.eax);
	// 0x2FB95F: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2FB969: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FB96D: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FB96E: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FB96F: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FB970: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB972: jb 0x002FB912
	if (ctx.flags.cf) goto loc_2FB912;
loc_2FB974:
	// 0x2FB974: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2FB977: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FB97C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB97D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB97F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB980: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FB981: ret
	return;
}

void sub_2FB982(X86Context& ctx, uint8_t* base) {
	// 0x2FB982: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB983: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FB985: sub esp, 0x34
	{ uint32_t _d = ctx.esp; uint32_t _s = 52;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FB988: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB989: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB98A: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FB98C: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FB98E: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2FB991: mov [ebp-0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edi);
	// 0x2FB994: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FB999: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FB99C: mov eax, [eax+0xB0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB0u);
	// 0x2FB9A2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB9A4: jz 0x002FBA7B
	if (ctx.flags.zf) goto loc_2FBA7B;
	// 0x2FB9AA: cmp [eax+0x20], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x20u); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FB9AD: jz 0x002FBA7B
	if (ctx.flags.zf) goto loc_2FBA7B;
	// 0x2FB9B3: mov al, [esi+0x12]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x12u);
	// 0x2FB9B6: and al, 0x03
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x2FB9B8: cmp al, 0x03
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x2FB9BA: jnz 0x002FB9C4
	if (!ctx.flags.zf) goto loc_2FB9C4;
	// 0x2FB9BC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB9BD: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB9BF: call 0x002FB6B6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB6B6(ctx, base);
	ctx.esp += 4;
loc_2FB9C4:
	// 0x2FB9C4: lea eax, [esi+0x5C]
	ctx.eax = ctx.esi + 0x5Cu;
	// 0x2FB9C7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB9C8: call 0x002F3F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F40(ctx, base);
	ctx.esp += 4;
	// 0x2FB9CD: test byte ptr [esi+0x12], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x12u) & 1, 8);
	// 0x2FB9D1: jz 0x002FBA7B
	if (ctx.flags.zf) goto loc_2FBA7B;
	// 0x2FB9D7: lea edi, [esi+0x14]
	ctx.edi = ctx.esi + 0x14u;
	// 0x2FB9DA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB9DB: lea eax, [ebp-0x04]
	ctx.eax = ctx.ebp - 0x4u;
	// 0x2FB9DE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB9DF: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB9E1: call 0x002FA6F4
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA6F4(ctx, base);
	ctx.esp += 4;
	// 0x2FB9E6: lea eax, [ebp-0x34]
	ctx.eax = ctx.ebp - 0x34u;
	// 0x2FB9E9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB9EA: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB9EC: call 0x002FA7A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA7A5(ctx, base);
	ctx.esp += 4;
	// 0x2FB9F1: lea eax, [ebp-0x08]
	ctx.eax = ctx.ebp - 0x8u;
	// 0x2FB9F4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FB9F5: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FB9F7: call 0x002FA9F9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA9F9(ctx, base);
	ctx.esp += 4;
	// 0x2FB9FC: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FBA00: lea ecx, [eax+eax*8]
	ctx.ecx = ctx.eax + ctx.eax * 8;
loc_2FBA03:
	// 0x2FBA03: mov edx, [0xFE820010]
	ctx.edx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FBA09: shr edx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FBA0C: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBA0E: jb 0x002FBA03
	if (ctx.flags.cf) goto loc_2FBA03;
	// 0x2FBA10: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FBA12: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBA14: jbe 0x002FBA7B
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FBA7B;
	// 0x2FBA16: lea edx, [esi+0x0C]
	ctx.edx = ctx.esi + 0xCu;
loc_2FBA19:
	// 0x2FBA19: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FBA1B: movzx eax, word ptr [edx]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FBA1E: mov [0xFE8202F8], eax
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.eax);
	// 0x2FBA23: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FBA26: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2FBA30: mov [0xFE820300], eax
	X86_MEM_WRITE_u32(base, 0xFE820300u, ctx.eax);
	// 0x2FBA35: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FBA37: jz 0x002FBA3E
	if (ctx.flags.zf) goto loc_2FBA3E;
	// 0x2FBA39: or eax, 0x400000
	ctx.eax = ctx.eax | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FBA3E:
	// 0x2FBA3E: mov [0xFE820304], eax
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.eax);
	// 0x2FBA43: mov eax, [ebp+ecx*4-0x34]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x34u);
	// 0x2FBA47: mov [0xFE820360], eax
	X86_MEM_WRITE_u32(base, 0xFE820360u, ctx.eax);
	// 0x2FBA4C: mov eax, [ebp+ecx*4-0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x28u);
	// 0x2FBA50: mov [0xFE820364], eax
	X86_MEM_WRITE_u32(base, 0xFE820364u, ctx.eax);
	// 0x2FBA55: mov eax, [ebp+ecx*4-0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + ctx.ecx * 4 - 0x1Cu);
	// 0x2FBA59: mov [0xFE820368], eax
	X86_MEM_WRITE_u32(base, 0xFE820368u, ctx.eax);
	// 0x2FBA5E: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x2FBA61: mov [0xFE82037C], eax
	X86_MEM_WRITE_u32(base, 0xFE82037Cu, ctx.eax);
	// 0x2FBA66: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2FBA70: movzx eax, byte ptr [esi+0x64]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FBA74: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FBA75: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FBA76: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FBA77: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBA79: jb 0x002FBA19
	if (ctx.flags.cf) goto loc_2FBA19;
loc_2FBA7B:
	// 0x2FBA7B: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2FBA7E: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FBA83: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBA84: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FBA86: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBA87: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBA88: ret
	return;
}

void sub_2FBA89(X86Context& ctx, uint8_t* base) {
	// 0x2FBA89: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBA8A: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FBA8C: mov dword ptr [esi], 0x36C258
	X86_MEM_WRITE_u32(base, ctx.esi, 3588696);
	// 0x2FBA92: call 0x002FB982
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB982(ctx, base);
	ctx.esp += 4;
	// 0x2FBA97: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FBA9A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBA9C: jz 0x002FBAA8
	if (ctx.flags.zf) goto loc_2FBAA8;
	// 0x2FBA9E: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FBAA0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBAA1: call [ecx+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FBAA4: and dword ptr [esi+0x70], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x70u, X86_MEM_READ_u32(base, ctx.esi + 0x70u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x70u), 32);
loc_2FBAA8:
	// 0x2FBAA8: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FBAAB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBAAD: jz 0x002FBAB9
	if (ctx.flags.zf) goto loc_2FBAB9;
	// 0x2FBAAF: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FBAB1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBAB2: call [ecx+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FBAB5: and dword ptr [esi+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, X86_MEM_READ_u32(base, ctx.esi + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x8u), 32);
loc_2FBAB9:
	// 0x2FBAB9: mov dword ptr [esi], 0x36C17C
	X86_MEM_WRITE_u32(base, ctx.esi, 3588476);
	// 0x2FBABF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBAC0: ret
	return;
}

void sub_2FBAC1(X86Context& ctx, uint8_t* base) {
	// 0x2FBAC1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBAC2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FBAC4: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FBAC7: and dword ptr [ebp-0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, X86_MEM_READ_u32(base, ctx.ebp - 0x18u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x18u), 32);
	// 0x2FBACB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBACC: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FBACE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBACF: lea edi, [esi+0x12]
	ctx.edi = ctx.esi + 0x12u;
	// 0x2FBAD2: test byte ptr [edi], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.edi) & 2, 8);
	// 0x2FBAD5: mov [ebp-0x14], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.edi);
	// 0x2FBAD8: jnz 0x002FBC89
	if (!ctx.flags.zf) goto loc_2FBC89;
	// 0x2FBADE: call 0x002FB5CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB5CC(ctx, base);
	ctx.esp += 4;
	// 0x2FBAE3: mov dx, 0x02
	X86_REG16(ctx.edx) = (uint16_t)(2);
	// 0x2FBAE7: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x2FBAE9: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2FBAEE: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FBAF1: test byte ptr [eax+0x08], 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x8u) & 16, 8);
	// 0x2FBAF5: jz 0x002FBAFE
	if (ctx.flags.zf) goto loc_2FBAFE;
	// 0x2FBAF7: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBAF9: call 0x002FB7F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxVoiceClient_Commit3dSettings(ctx, base);
	ctx.esp += 4;
loc_2FBAFE:
	// 0x2FBAFE: mov eax, [esi+0x70]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x70u);
	// 0x2FBB01: mov eax, [eax+0xB0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xB0u);
	// 0x2FBB07: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBB09: jz 0x002FBB2A
	if (ctx.flags.zf) goto loc_2FBB2A;
	// 0x2FBB0B: mov eax, [eax+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	// 0x2FBB0E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBB10: jz 0x002FBB2A
	if (ctx.flags.zf) goto loc_2FBB2A;
	// 0x2FBB12: mov ecx, [eax+0x80]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x80u);
	// 0x2FBB18: test dword ptr [ecx+0x08], 0x82000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.ecx + 0x8u) & 532480, 32);
	// 0x2FBB1F: jz 0x002FBB2A
	if (ctx.flags.zf) goto loc_2FBB2A;
	// 0x2FBB21: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBB23: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x2FBB25: call 0x002FC4DC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxBuffer_Play(ctx, base);
	ctx.esp += 4;
loc_2FBB2A:
	// 0x2FBB2A: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x2FBB2D: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
loc_2FBB32:
	// 0x2FBB32: mov eax, [0xFE820010]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FBB37: and eax, 0xFFFFFFFC
	ctx.eax = ctx.eax & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBB3A: cmp eax, 0x80
	{ uint32_t _d = ctx.eax; uint32_t _s = 128;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBB3F: jb 0x002FBB32
	if (ctx.flags.cf) goto loc_2FBB32;
	// 0x2FBB41: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FBB44: add dword ptr [eax+0x84], 0x01
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x84u)) + (uint64_t)(uint32_t)(1);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.eax + 0x84u), (int32_t)1, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax + 0x84u, (uint32_t)_res); }
	// 0x2FBB4B: lea ecx, [esi+0x68]
	ctx.ecx = ctx.esi + 0x68u;
	// 0x2FBB4E: call 0x002FA4F2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4F2(ctx, base);
	ctx.esp += 4;
	// 0x2FBB53: test byte ptr [edi], 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.edi) & 16, 8);
	// 0x2FBB56: jz 0x002FBB5E
	if (ctx.flags.zf) goto loc_2FBB5E;
	// 0x2FBB58: or byte ptr [esi+0x16], 0x80
	X86_MEM_WRITE_u8(base, ctx.esi + 0x16u, X86_MEM_READ_u8(base, ctx.esi + 0x16u) | -128);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x16u), 8);
	// 0x2FBB5C: jmp 0x002FBB62
	goto loc_2FBB62;
loc_2FBB5E:
	// 0x2FBB5E: and byte ptr [esi+0x16], 0x7F
	X86_MEM_WRITE_u8(base, ctx.esi + 0x16u, X86_MEM_READ_u8(base, ctx.esi + 0x16u) & 127);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x16u), 8);
loc_2FBB62:
	// 0x2FBB62: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x2FBB65: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBB66: lea eax, [ebp-0x01]
	ctx.eax = ctx.ebp - 0x1u;
	// 0x2FBB69: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBB6A: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBB6C: call 0x002FAA7B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FAA7B(ctx, base);
	ctx.esp += 4;
	// 0x2FBB71: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2FBB74: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBB76: jz 0x002FBB83
	if (ctx.flags.zf) goto loc_2FBB83;
	// 0x2FBB78: movzx ecx, byte ptr [eax+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x64u));
	// 0x2FBB7C: movzx eax, word ptr [eax+ecx*2+0x0A]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + ctx.ecx * 2 + 0xAu));
	// 0x2FBB81: jmp 0x002FBB95
	goto loc_2FBB95;
loc_2FBB83:
	// 0x2FBB83: movzx eax, byte ptr [ebp-0x01]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.ebp - 0x1u));
	// 0x2FBB87: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FBB88: shl eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FBB8B: and eax, 0x30000
	ctx.eax = ctx.eax & 196608;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBB90: or eax, 0xFFFF
	ctx.eax = ctx.eax | 65535;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_2FBB95:
	// 0x2FBB95: mov cx, [edi]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.edi);
	// 0x2FBB98: movzx edx, byte ptr [esi+0x64]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FBB9C: and cx, 0x444
	X86_REG16(ctx.ecx) = X86_REG16(ctx.ecx) & 1092;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG16(ctx.ecx), 16);
	// 0x2FBBA1: neg cx
	{ uint16_t _d = X86_REG16(ctx.ecx);
	  uint16_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int16_t)0, (int16_t)_d, 16);
	  ctx.flags.cf = (_d != 0);
	  X86_REG16(ctx.ecx) = _res; }
	// 0x2FBBA4: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x2FBBA7: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x2FBBA9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBBAA: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FBBAC: and ecx, 0x40000
	ctx.ecx = ctx.ecx & 262144;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FBBB2: imul eax, eax, 0x07
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)7;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
loc_2FBBB5:
	// 0x2FBBB5: mov ebx, [0xFE820010]
	ctx.ebx = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FBBBB: shr ebx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)(ctx.ebx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x2FBBBE: cmp ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBBC0: jb 0x002FBBB5
	if (ctx.flags.cf) goto loc_2FBBB5;
	// 0x2FBBC2: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FBBC3: mov [ebp-0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.edx);
	// 0x2FBBC6: js 0x002FBC30
	if (ctx.flags.sf) goto loc_2FBC30;
	// 0x2FBBC8: lea ebx, [esi+edx*2+0x0C]
	ctx.ebx = ctx.esi + ctx.edx * 2 + 0xCu;
	// 0x2FBBCC: mov edi, 0xFFFF0000
	ctx.edi = -65536;
loc_2FBBD1:
	// 0x2FBBD1: movzx edx, word ptr [ebx]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebx));
	// 0x2FBBD4: mov eax, [esi+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x2FBBD7: and eax, edi
	ctx.eax = ctx.eax & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBBD9: and ecx, edi
	ctx.ecx = ctx.ecx & ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FBBDB: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBBDD: or ecx, edx
	ctx.ecx = ctx.ecx | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FBBDF: cmp dword ptr [ebp-0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBBE3: mov [0xFE8202F8], edx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.edx);
	// 0x2FBBE9: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2FBBF3: mov edx, [esi+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FBBF6: jz 0x002FBBFE
	if (ctx.flags.zf) goto loc_2FBBFE;
	// 0x2FBBF8: or edx, 0x400000
	ctx.edx = ctx.edx | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
loc_2FBBFE:
	// 0x2FBBFE: dec [ebp-0x08]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, (uint32_t)_res); }
	// 0x2FBC01: mov [0xFE820304], edx
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.edx);
	// 0x2FBC07: mov edx, [ebp-0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x2FBC0A: mov [0xFE820120], edx
	X86_MEM_WRITE_u32(base, 0xFE820120u, ctx.edx);
	// 0x2FBC10: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FBC11: mov [0xFE820124], eax
	X86_MEM_WRITE_u32(base, 0xFE820124u, ctx.eax);
	// 0x2FBC16: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FBC17: cmp dword ptr [ebp-0x08], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x8u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBC1B: mov [0xFE820140], ecx
	X86_MEM_WRITE_u32(base, 0xFE820140u, ctx.ecx);
	// 0x2FBC21: mov dword ptr [0xFE8202FC], 0x00
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 0);
	// 0x2FBC2B: jnl 0x002FBBD1
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_2FBBD1;
	// 0x2FBC2D: mov edi, [ebp-0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
loc_2FBC30:
	// 0x2FBC30: mov ecx, [ebp-0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x2FBC33: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FBC35: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBC36: lea eax, [esi+0x4C]
	ctx.eax = ctx.esi + 0x4Cu;
	// 0x2FBC39: jz 0x002FBC40
	if (ctx.flags.zf) goto loc_2FBC40;
	// 0x2FBC3B: add ecx, 0x4C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(76);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)76, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FBC3E: jmp 0x002FBC4E
	goto loc_2FBC4E;
loc_2FBC40:
	// 0x2FBC40: movzx ecx, byte ptr [ebp-0x01]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.ebp - 0x1u));
	// 0x2FBC44: mov edx, [esi+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FBC47: lea ecx, [edx+ecx*8+0x488]
	ctx.ecx = ctx.edx + ctx.ecx * 8 + 0x488u;
loc_2FBC4E:
	// 0x2FBC4E: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x2FBC50: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x2FBC52: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x2FBC55: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x2FBC57: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x2FBC5A: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x2FBC5D: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x2FBC5F: mov al, [ebp-0x01]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x2FBC62: mov [esi+0x65], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x65u, X86_REG8L(ctx.eax));
loc_2FBC65:
	// 0x2FBC65: mov eax, [0xFE820010]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FBC6A: and eax, 0xFFFFFFFC
	ctx.eax = ctx.eax & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBC6D: cmp eax, 0x80
	{ uint32_t _d = ctx.eax; uint32_t _s = 128;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBC72: jb 0x002FBC65
	if (ctx.flags.cf) goto loc_2FBC65;
	// 0x2FBC74: mov esi, [esi+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FBC77: sub dword ptr [esi+0x84], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x84u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  X86_MEM_WRITE_u32(base, ctx.esi + 0x84u, (uint32_t)_res); }
	// 0x2FBC7E: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x2FBC81: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FBC86: mov ax, [edi]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi);
loc_2FBC89:
	// 0x2FBC89: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBC8A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBC8B: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBC8C: ret
	return;
}

void sub_2FBC8D(X86Context& ctx, uint8_t* base) {
	// 0x2FBC8D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBC8E: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FBC90: call 0x002FBA89
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FBA89(ctx, base);
	ctx.esp += 4;
	// 0x2FBC95: test byte ptr [esp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esp + 0x8u) & 1, 8);
	// 0x2FBC9A: jz 0x002FBCA2
	if (ctx.flags.zf) goto loc_2FBCA2;
	// 0x2FBC9C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBC9D: call 0x002F75FE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F75FE(ctx, base);
	ctx.esp += 4;
loc_2FBCA2:
	// 0x2FBCA2: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x2FBCA4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBCA5: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FBCA8(X86Context& ctx, uint8_t* base) {
	// 0x2FBCA8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBCA9: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FBCAB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBCAC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBCAD: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FBCB1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBCB2: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FBCB4: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FBCB7: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FBCBC: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2FBCC2: test byte ptr [eax+0x0A], 0x18
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0xAu) & 24, 8);
	// 0x2FBCC6: jz 0x002FBCDB
	if (ctx.flags.zf) goto loc_2FBCDB;
	// 0x2FBCC8: mov ecx, [eax+0xBC]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xBCu);
	// 0x2FBCCE: and ecx, 0xFFF
	ctx.ecx = ctx.ecx & 4095;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FBCD4: mov eax, 0x7FF
	ctx.eax = 2047;
	// 0x2FBCD9: jmp 0x002FBD02
	goto loc_2FBD02;
loc_2FBCDB:
	// 0x2FBCDB: mov eax, [eax+0xBC]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xBCu);
	// 0x2FBCE1: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FBCE4: mov edx, 0xFFF
	ctx.edx = 4095;
	// 0x2FBCE9: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBCEB: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FBCED: mov eax, [esi+0x84]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x84u);
	// 0x2FBCF3: movzx eax, word ptr [eax+0x08]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0x8u));
	// 0x2FBCF7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBCF8: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x2FBCFA: shr edi, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (_cnt - 1)) & 1;
	  ctx.edi = (uint32_t)(ctx.edi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x2FBCFD: add eax, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FBCFF: and ecx, edx
	ctx.ecx = ctx.ecx & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FBD01: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FBD02:
	// 0x2FBD02: shl eax, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FBD05: or eax, ecx
	ctx.eax = ctx.eax | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x2FBD07: lea ecx, [ebp-0x08]
	ctx.ecx = ctx.ebp - 0x8u;
	// 0x2FBD0A: mov [esi+0x154], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x154u, ctx.eax);
	// 0x2FBD10: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FBD15: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBD16: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBD17: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_2FBD1A(X86Context& ctx, uint8_t* base) {
	// 0x2FBD1A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD1B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD1D: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FBD1F: call 0x002FC5F5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CMcpxBuffer_Stop(ctx, base);
	ctx.esp += 4;
	// 0x2FBD24: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBD26: call 0x002FB5CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FB5CC(ctx, base);
	ctx.esp += 4;
	// 0x2FBD2B: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2FBD2E: test word ptr [ecx], 0x100
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_MEM_READ_u16(base, ctx.ecx) & 256, 16);
	// 0x2FBD33: jz 0x002FBD5B
	if (ctx.flags.zf) goto loc_2FBD5B;
	// 0x2FBD35: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD36: mov dx, 0xFEFF
	X86_REG16(ctx.edx) = (uint16_t)(-257);
	// 0x2FBD3A: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
	// 0x2FBD3F: lea edi, [esi+0x84]
	ctx.edi = ctx.esi + 0x84u;
	// 0x2FBD45: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x2FBD47: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBD49: jz 0x002FBD5A
	if (ctx.flags.zf) goto loc_2FBD5A;
	// 0x2FBD4B: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x2FBD4E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD4F: add ecx, 0x60
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(96);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)96, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FBD52: call 0x002FA467
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA467(ctx, base);
	ctx.esp += 4;
	// 0x2FBD57: and dword ptr [edi], 0x00
	X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.edi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.edi), 32);
loc_2FBD5A:
	// 0x2FBD5A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_2FBD5B:
	// 0x2FBD5B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBD5C: ret
	return;
}

void sub_2FBD5D(X86Context& ctx, uint8_t* base) {
	// 0x2FBD5D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD5E: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x2FBD60: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x2FBD63: and dword ptr [ebp-0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, X86_MEM_READ_u32(base, ctx.ebp - 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0xCu), 32);
	// 0x2FBD67: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD68: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD69: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x2FBD6B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD6C: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2FBD6F: call 0x002F3F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F70(ctx, base);
	ctx.esp += 4;
	// 0x2FBD74: test byte ptr [ebp+0x08], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x8u) & 1, 8);
	// 0x2FBD78: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBD7A: jz 0x002FBDB5
	if (ctx.flags.zf) goto loc_2FBDB5;
	// 0x2FBD7C: or byte ptr [esi+0x17], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0x17u, X86_MEM_READ_u8(base, ctx.esi + 0x17u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x17u), 8);
	// 0x2FBD80: mov edi, [esi+0x80]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2FBD86: mov ebx, [edi+0xCC]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.edi + 0xCCu);
	// 0x2FBD8C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD8D: call 0x002F901A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F901A(ctx, base);
	ctx.esp += 4;
	// 0x2FBD92: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x2FBD95: mov eax, [edi+0xD0]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0xD0u);
	// 0x2FBD9B: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FBD9D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBD9E: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBDA0: call 0x002F901A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F901A(ctx, base);
	ctx.esp += 4;
	// 0x2FBDA5: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2FBDA8: mov dx, 0x200
	X86_REG16(ctx.edx) = (uint16_t)(512);
	// 0x2FBDAC: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2FBDAE: call 0x002FA4CC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4CC(ctx, base);
	ctx.esp += 4;
	// 0x2FBDB3: jmp 0x002FBDDC
	goto loc_2FBDDC;
loc_2FBDB5:
	// 0x2FBDB5: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2FBDBB: and byte ptr [esi+0x17], 0xFD
	X86_MEM_WRITE_u8(base, ctx.esi + 0x17u, X86_MEM_READ_u8(base, ctx.esi + 0x17u) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x17u), 8);
	// 0x2FBDBF: push [eax+0xC8]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0xC8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBDC5: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x2FBDC9: call 0x002F901A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F901A(ctx, base);
	ctx.esp += 4;
	// 0x2FBDCE: lea ecx, [esi+0x12]
	ctx.ecx = ctx.esi + 0x12u;
	// 0x2FBDD1: mov dx, 0xFDFF
	X86_REG16(ctx.edx) = (uint16_t)(-513);
	// 0x2FBDD5: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x2FBDD7: call 0x002FA4C8
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FA4C8(ctx, base);
	ctx.esp += 4;
loc_2FBDDC:
	// 0x2FBDDC: mov eax, [esi+0x80]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x80u);
	// 0x2FBDE2: movzx eax, byte ptr [eax+0x0F]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0xFu));
	// 0x2FBDE6: shl eax, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FBDE8: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBDEA: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x2FBDEB: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBDEC: idiv ecx
	{ int64_t _dividend = (int64_t)(((uint64_t)ctx.edx << 32) | ctx.eax);
	  int32_t _divisor = (int32_t)ctx.ecx;
	  ctx.eax = (uint32_t)(int32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(int32_t)(_dividend % _divisor); }
	// 0x2FBDEE: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FBDF2: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x2FBDF4: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x2FBDF5: shl edx, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x2FBDF8: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
loc_2FBDFB:
	// 0x2FBDFB: mov eax, [0xFE820010]
	ctx.eax = X86_MEM_READ_u32(base, 0xFE820010u);
	// 0x2FBE00: shr eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x2FBE03: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBE05: jb 0x002FBDFB
	if (ctx.flags.cf) goto loc_2FBDFB;
	// 0x2FBE07: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FBE09: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x2FBE0B: jbe 0x002FBE7F
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_2FBE7F;
	// 0x2FBE0D: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x2FBE10: and ecx, 0x02
	ctx.ecx = ctx.ecx & 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x2FBE13: mov [ebp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.ecx);
	// 0x2FBE16: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FBE18: lea edx, [esi+0x0C]
	ctx.edx = ctx.esi + 0xCu;
loc_2FBE1B:
	// 0x2FBE1B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x2FBE1D: movzx ecx, word ptr [edx]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx));
	// 0x2FBE20: mov [0xFE8202F8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202F8u, ctx.ecx);
	// 0x2FBE26: mov dword ptr [0xFE8202FC], 0x01
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, 1);
	// 0x2FBE30: mov ecx, [esi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x2FBE33: jz 0x002FBE3B
	if (ctx.flags.zf) goto loc_2FBE3B;
	// 0x2FBE35: or ecx, 0x400000
	ctx.ecx = ctx.ecx | 4194304;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
loc_2FBE3B:
	// 0x2FBE3B: mov [0xFE820304], ecx
	X86_MEM_WRITE_u32(base, 0xFE820304u, ctx.ecx);
	// 0x2FBE41: mov ecx, [esi+0x154]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x154u);
	// 0x2FBE47: add ecx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.edi, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x2FBE49: mov [0xFE8203A0], ecx
	X86_MEM_WRITE_u32(base, 0xFE8203A0u, ctx.ecx);
	// 0x2FBE4F: mov ecx, [ebp-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x2FBE52: mov [0xFE8203DC], ebx
	X86_MEM_WRITE_u32(base, 0xFE8203DCu, ctx.ebx);
	// 0x2FBE58: mov [0xFE8203A4], ecx
	X86_MEM_WRITE_u32(base, 0xFE8203A4u, ctx.ecx);
	// 0x2FBE5E: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x2FBE60: cmp [ebp+0x08], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBE63: jz 0x002FBE6B
	if (ctx.flags.zf) goto loc_2FBE6B;
	// 0x2FBE65: mov [0xFE8203D8], ecx
	X86_MEM_WRITE_u32(base, 0xFE8203D8u, ctx.ecx);
loc_2FBE6B:
	// 0x2FBE6B: add edi, [ebp-0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x8u), 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x2FBE6E: mov [0xFE8202FC], ecx
	X86_MEM_WRITE_u32(base, 0xFE8202FCu, ctx.ecx);
	// 0x2FBE74: movzx ecx, byte ptr [esi+0x64]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x64u));
	// 0x2FBE78: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x2FBE79: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FBE7A: inc edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x2FBE7B: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x2FBE7D: jb 0x002FBE1B
	if (ctx.flags.cf) goto loc_2FBE1B;
loc_2FBE7F:
	// 0x2FBE7F: lea ecx, [ebp-0x10]
	ctx.ecx = ctx.ebp - 0x10u;
	// 0x2FBE82: call 0x002F3F92
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2F3F92(ctx, base);
	ctx.esp += 4;
	// 0x2FBE87: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBE89: call 0x002FBAC1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2FBAC1(ctx, base);
	ctx.esp += 4;
	// 0x2FBE8E: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x2FBE90: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x2FBE92: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x2FBE94: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x2FBE97: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBE98: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBE99: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBE9A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x2FBE9B: ret 0x04
	ctx.esp += 4;
	return;
}

