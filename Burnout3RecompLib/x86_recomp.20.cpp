#include "x86_recomp_shared.h"

void sub_1F6550(X86Context& ctx, uint8_t* base) {
	// 0x1F6550: mov edx, [0x00764168]
	ctx.edx = X86_MEM_READ_u32(base, 0x764168u);
	// 0x1F6556: cmp edx, 0x764168
	{ uint32_t _d = ctx.edx; uint32_t _s = 7749992;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F655C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F655D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F655E: jz 0x001F6589
	if (ctx.flags.zf) goto loc_1F6589;
	// 0x1F6560: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
loc_1F6564:
	// 0x1F6564: mov ecx, [edx-0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx - 0xCu);
	// 0x1F6567: lea esi, [edx-0x10]
	ctx.esi = ctx.edx - 0x10u;
	// 0x1F656A: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F656C: jz 0x001F657F
	if (ctx.flags.zf) goto loc_1F657F;
	// 0x1F656E: mov edi, edi
	ctx.edi = ctx.edi;
loc_1F6570:
	// 0x1F6570: mov edi, [ecx+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F6573: cmp [edi+0x0C], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi + 0xCu); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6576: jz 0x001F658B
	if (ctx.flags.zf) goto loc_1F658B;
	// 0x1F6578: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F657B: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F657D: jnz 0x001F6570
	if (!ctx.flags.zf) goto loc_1F6570;
loc_1F657F:
	// 0x1F657F: mov edx, [edx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F6581: cmp edx, 0x764168
	{ uint32_t _d = ctx.edx; uint32_t _s = 7749992;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6587: jnz 0x001F6564
	if (!ctx.flags.zf) goto loc_1F6564;
loc_1F6589:
	// 0x1F6589: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_1F658B:
	// 0x1F658B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F658C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F658D: ret
	return;
}

void RwaHeapBlockFree(X86Context& ctx, uint8_t* base) {
	// 0x1F6590: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F6594: add ecx, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)12, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1F6597: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1F659B: jmp 0x001FE140
	goto loc_1FE140;
	// ---- chunk at 0x1FE140 (size 0x2B) ----
loc_1FE140:
	// 0x1FE140: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FE144: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FE147: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FE148: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FE14C: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FE14E: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FE150: jz 0x001FE15E
	if (ctx.flags.zf) goto loc_1FE15E;
loc_1FE152:
	// 0x1FE152: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FE155: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FE156: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FE158: jz 0x001FE167
	if (ctx.flags.zf) goto loc_1FE167;
	// 0x1FE15A: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FE15C: jnz 0x001FE152
	if (!ctx.flags.zf) goto loc_1FE152;
loc_1FE15E:
	// 0x1FE15E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FE160: jz 0x001FE167
	if (ctx.flags.zf) goto loc_1FE167;
	// 0x1FE162: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1FE165: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FE166: ret
	return;
loc_1FE167:
	// 0x1FE167: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FE169: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FE16A: ret
	return;
}

void sub_1F65A0(X86Context& ctx, uint8_t* base) {
	// 0x1F65A0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F65A4: add eax, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)12, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F65A7: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1F65AB: jmp 0x001FE1C0
	goto loc_1FE1C0;
	// ---- chunk at 0x1FE1C0 (size 0x19) ----
loc_1FE1C0:
	// 0x1FE1C0: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FE1C4: mov ecx, [edx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FE1C7: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FE1C9: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FE1CB: jz 0x001FE1D8
	if (ctx.flags.zf) goto loc_1FE1D8;
	// 0x1FE1CD: lea ecx, [ecx]
	ctx.ecx = ctx.ecx;
loc_1FE1D0:
	// 0x1FE1D0: mov ecx, [ecx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FE1D3: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FE1D4: cmp ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FE1D6: jnz 0x001FE1D0
	if (!ctx.flags.zf) goto loc_1FE1D0;
loc_1FE1D8:
	// 0x1FE1D8: ret
	return;
}

void sub_1F65B0(X86Context& ctx, uint8_t* base) {
	// 0x1F65B0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F65B1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F65B5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F65B6: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F65BA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F65BB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F65BC: call 0x001F6530
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6530(ctx, base);
	ctx.esp += 4;
	// 0x1F65C1: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F65C4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F65C6: jz 0x001F65CD
	if (ctx.flags.zf) goto loc_1F65CD;
	// 0x1F65C8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F65C9: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F65CB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F65CC: ret
	return;
loc_1F65CD:
	// 0x1F65CD: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x1F65D0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F65D1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F65D2: call 0x001FE0E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE0E0(ctx, base);
	ctx.esp += 4;
	// 0x1F65D7: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F65DA: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F65DC: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F65DE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F65DF: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F65E1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F65E2: ret
	return;
}

void sub_1F65F0(X86Context& ctx, uint8_t* base) {
	// 0x1F65F0: mov eax, [0x0041B4C8]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B4C8u);
	// 0x1F65F5: ret
	return;
}

void sub_1F6600(X86Context& ctx, uint8_t* base) {
	// 0x1F6600: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6601: mov esi, [0x00764168]
	ctx.esi = X86_MEM_READ_u32(base, 0x764168u);
	// 0x1F6607: cmp esi, 0x764168
	{ uint32_t _d = ctx.esi; uint32_t _s = 7749992;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F660D: jz 0x001F662C
	if (ctx.flags.zf) goto loc_1F662C;
	// 0x1F660F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6610: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
loc_1F6614:
	// 0x1F6614: lea eax, [esi-0x10]
	ctx.eax = ctx.esi - 0x10u;
	// 0x1F6617: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6618: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6619: call 0x001FE220
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE220(ctx, base);
	ctx.esp += 4;
	// 0x1F661E: mov esi, [esi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F6620: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6623: cmp esi, 0x764168
	{ uint32_t _d = ctx.esi; uint32_t _s = 7749992;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6629: jnz 0x001F6614
	if (!ctx.flags.zf) goto loc_1F6614;
	// 0x1F662B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F662C:
	// 0x1F662C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F662D: ret
	return;
}

void sub_1F6630(X86Context& ctx, uint8_t* base) {
	// 0x1F6630: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6631: call 0x001FE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDFreeData(ctx, base);
	ctx.esp += 4;
	// 0x1F6636: mov al, [esi+0x1B]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x1Bu);
	// 0x1F6639: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F663C: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1F663E: jz 0x001F664F
	if (ctx.flags.zf) goto loc_1F664F;
	// 0x1F6640: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6641: push 0x764140
	{ auto _pv = (uint32_t)(7749952); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6646: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1F664B: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F664E: ret
	return;
loc_1F664F:
	// 0x1F664F: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x1F6651: jnz 0x001F665A
	if (!ctx.flags.zf) goto loc_1F665A;
	// 0x1F6653: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6654: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1F6659: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F665A:
	// 0x1F665A: ret
	return;
}

void sub_1F6660(X86Context& ctx, uint8_t* base) {
	// 0x1F6660: mov eax, [0x0041B4B4]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B4B4u);
	// 0x1F6665: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6666: call 0x001FEE90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaFreeAligned(ctx, base);
	ctx.esp += 4;
	// 0x1F666B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F666D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6670: mov [0x0041B4B4], eax
	X86_MEM_WRITE_u32(base, 0x41B4B4u, ctx.eax);
	// 0x1F6675: mov [0x003C114C], eax
	X86_MEM_WRITE_u32(base, 0x3C114Cu, ctx.eax);
	// 0x1F667A: ret
	return;
}

void _rwaWaveDictOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1F6680: push 0x40808
	{ auto _pv = (uint32_t)(264200); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6685: push 0x764140
	{ auto _pv = (uint32_t)(7749952); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F668A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F668C: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F668E: mov eax, 0x764168
	ctx.eax = 7749992;
	// 0x1F6693: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6695: push 0x30
	{ auto _pv = (uint32_t)(48); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6697: mov [0x00764168], eax
	X86_MEM_WRITE_u32(base, 0x764168u, ctx.eax);
	// 0x1F669C: mov [0x0076416C], eax
	X86_MEM_WRITE_u32(base, 0x76416Cu, ctx.eax);
	// 0x1F66A1: mov dword ptr [0x0041B4BC], 0x01
	X86_MEM_WRITE_u32(base, 0x41B4BCu, 1);
	// 0x1F66AB: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F66B0: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F66B3: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F66B5: jz 0x001F66F8
	if (ctx.flags.zf) goto loc_1F66F8;
	// 0x1F66B7: push 0x41B484
	{ auto _pv = (uint32_t)(4306052); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F66BC: call 0x001F63F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDictCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F66C1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F66C4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F66C6: mov [0x0041B4C8], eax
	X86_MEM_WRITE_u32(base, 0x41B4C8u, ctx.eax);
	// 0x1F66CB: mov [0x0041B4C4], eax
	X86_MEM_WRITE_u32(base, 0x41B4C4u, ctx.eax);
	// 0x1F66D0: jz 0x001F66EB
	if (ctx.flags.zf) goto loc_1F66EB;
	// 0x1F66D2: push 0x3830E0
	{ auto _pv = (uint32_t)(3682528); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F66D7: push 0x36DB48
	{ auto _pv = (uint32_t)(3595080); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F66DC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F66DD: call 0x001F64C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1F66E2: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F66E5: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F66EA: ret
	return;
loc_1F66EB:
	// 0x1F66EB: push 0x764140
	{ auto _pv = (uint32_t)(7749952); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F66F0: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F66F5: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F66F8:
	// 0x1F66F8: mov dword ptr [0x0041B4C4], 0x00
	X86_MEM_WRITE_u32(base, 0x41B4C4u, 0);
	// 0x1F6702: mov dword ptr [0x0041B4C8], 0x00
	X86_MEM_WRITE_u32(base, 0x41B4C8u, 0);
	// 0x1F670C: mov dword ptr [0x0041B4BC], 0x00
	X86_MEM_WRITE_u32(base, 0x41B4BCu, 0);
	// 0x1F6716: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6718: ret
	return;
}

void sub_1F6720(X86Context& ctx, uint8_t* base) {
	// 0x1F6720: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6721: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F6725: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x1F6728: mov ecx, [esi+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F672B: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F672D: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x1F6730: mov edx, [esi+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F6733: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1F6736: cmp esi, [0x0041B4C8]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, 0x41B4C8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F673C: jnz 0x001F674A
	if (!ctx.flags.zf) goto loc_1F674A;
	// 0x1F673E: mov ecx, [0x0041B4C4]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B4C4u);
	// 0x1F6744: mov [0x0041B4C8], ecx
	X86_MEM_WRITE_u32(base, 0x41B4C8u, ctx.ecx);
loc_1F674A:
	// 0x1F674A: test byte ptr [esi+0x1B], 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x1Bu) & 64, 8);
	// 0x1F674E: jz 0x001F6766
	if (ctx.flags.zf) goto loc_1F6766;
	// 0x1F6750: mov eax, [esi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x1F6753: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6755: jnz 0x001F675D
	if (!ctx.flags.zf) goto loc_1F675D;
	// 0x1F6757: test byte ptr [esi+0x1A], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x1Au) & 1, 8);
	// 0x1F675B: jz 0x001F6766
	if (ctx.flags.zf) goto loc_1F6766;
loc_1F675D:
	// 0x1F675D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F675E: call 0x001F6E40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6E40(ctx, base);
	ctx.esp += 4;
	// 0x1F6763: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F6766:
	// 0x1F6766: mov al, [esi+0x1B]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x1Bu);
	// 0x1F6769: test al, 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 32, 8);
	// 0x1F676B: jnz 0x001F67F2
	if (!ctx.flags.zf) goto loc_1F67F2;
	// 0x1F6771: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x1F6773: jz 0x001F6782
	if (ctx.flags.zf) goto loc_1F6782;
	// 0x1F6775: mov edx, [esi+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x1F6778: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6779: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1F677D: jmp 0x001FEE90
	rwaFreeAligned(ctx, base);
	return;
loc_1F6782:
	// 0x1F6782: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6783: mov ebp, [esi+0x10]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F6786: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x1F6789: cmp ebp, eax
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F678B: jz 0x001F67E0
	if (ctx.flags.zf) goto loc_1F67E0;
	// 0x1F678D: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F678E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F678F: nop
loc_1F6790:
	// 0x1F6790: mov edi, [0x00764168]
	ctx.edi = X86_MEM_READ_u32(base, 0x764168u);
	// 0x1F6796: cmp edi, 0x764168
	{ uint32_t _d = ctx.edi; uint32_t _s = 7749992;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F679C: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x1F679F: jnz 0x001F67B0
	if (!ctx.flags.zf) goto loc_1F67B0;
	// 0x1F67A1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F67A2: call 0x001FAB00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FAB00(ctx, base);
	ctx.esp += 4;
	// 0x1F67A7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F67AA: jmp 0x001F67CB
	goto loc_1F67CB;
	// 0x1F67AC: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_1F67B0:
	// 0x1F67B0: lea eax, [edi-0x1C]
	ctx.eax = ctx.edi - 0x1Cu;
	// 0x1F67B3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F67B4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F67B5: call 0x001F6530
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6530(ctx, base);
	ctx.esp += 4;
	// 0x1F67BA: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F67BD: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F67BF: jnz 0x001F67D4
	if (!ctx.flags.zf) goto loc_1F67D4;
	// 0x1F67C1: mov edi, [edi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F67C3: cmp edi, 0x764168
	{ uint32_t _d = ctx.edi; uint32_t _s = 7749992;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F67C9: jnz 0x001F67B0
	if (!ctx.flags.zf) goto loc_1F67B0;
loc_1F67CB:
	// 0x1F67CB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F67CC: call 0x001FAB00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FAB00(ctx, base);
	ctx.esp += 4;
	// 0x1F67D1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F67D4:
	// 0x1F67D4: mov ebp, [ebp+0x04]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.ebp + 0x4u);
	// 0x1F67D7: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x1F67DA: cmp ebp, eax
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F67DC: jnz 0x001F6790
	if (!ctx.flags.zf) goto loc_1F6790;
	// 0x1F67DE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F67DF: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F67E0:
	// 0x1F67E0: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x1F67E3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F67E4: call 0x001FE170
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE170(ctx, base);
	ctx.esp += 4;
	// 0x1F67E9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F67EC: call 0x001F6630
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6630(ctx, base);
	ctx.esp += 4;
	// 0x1F67F1: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F67F2:
	// 0x1F67F2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F67F3: ret
	return;
}

void _rwaWaveDictCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1F6800: mov eax, [0x00764168]
	ctx.eax = X86_MEM_READ_u32(base, 0x764168u);
	// 0x1F6805: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6806: mov esi, 0x764168
	ctx.esi = 7749992;
	// 0x1F680B: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F680D: mov dword ptr [0x0041B4C0], 0x01
	X86_MEM_WRITE_u32(base, 0x41B4C0u, 1);
	// 0x1F6817: jz 0x001F6835
	if (ctx.flags.zf) goto loc_1F6835;
	// 0x1F6819: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_1F6820:
	// 0x1F6820: add eax, 0xFFFFFFE4
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6823: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6824: call 0x001F6720
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6720(ctx, base);
	ctx.esp += 4;
	// 0x1F6829: mov eax, [0x00764168]
	ctx.eax = X86_MEM_READ_u32(base, 0x764168u);
	// 0x1F682E: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6831: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6833: jnz 0x001F6820
	if (!ctx.flags.zf) goto loc_1F6820;
loc_1F6835:
	// 0x1F6835: push 0x764140
	{ auto _pv = (uint32_t)(7749952); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F683A: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F683F: mov eax, [0x0041B4B4]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B4B4u);
	// 0x1F6844: mov [0x00764168], esi
	X86_MEM_WRITE_u32(base, 0x764168u, ctx.esi);
	// 0x1F684A: mov [0x0076416C], esi
	X86_MEM_WRITE_u32(base, 0x76416Cu, ctx.esi);
	// 0x1F6850: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6852: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6855: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6857: jz 0x001F686D
	if (ctx.flags.zf) goto loc_1F686D;
	// 0x1F6859: cmp dword ptr [0x0041B4B8], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41B4B8u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6860: jnz 0x001F686D
	if (!ctx.flags.zf) goto loc_1F686D;
	// 0x1F6862: call 0x001F6660
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6660(ctx, base);
	ctx.esp += 4;
	// 0x1F6867: mov [0x0041B4B8], esi
	X86_MEM_WRITE_u32(base, 0x41B4B8u, ctx.esi);
loc_1F686D:
	// 0x1F686D: mov [0x0041B4C4], esi
	X86_MEM_WRITE_u32(base, 0x41B4C4u, ctx.esi);
	// 0x1F6873: mov [0x0041B4C8], esi
	X86_MEM_WRITE_u32(base, 0x41B4C8u, ctx.esi);
	// 0x1F6879: mov [0x0041B4BC], esi
	X86_MEM_WRITE_u32(base, 0x41B4BCu, ctx.esi);
	// 0x1F687F: mov [0x0041B4C0], esi
	X86_MEM_WRITE_u32(base, 0x41B4C0u, ctx.esi);
	// 0x1F6885: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6886: ret
	return;
}

void sub_1F6890(X86Context& ctx, uint8_t* base) {
	// 0x1F6890: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F6894: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6896: mov dword ptr [eax+0x2C], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2Cu, 1);
	// 0x1F689D: mov [eax+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.ecx);
	// 0x1F68A0: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x1F68A3: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F68A5: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x1F68A8: mov [eax+0x40], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x40u, ctx.ecx);
	// 0x1F68AB: mov [eax+0x24], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x24u, ctx.ecx);
	// 0x1F68AE: mov [eax+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.ecx);
	// 0x1F68B1: mov [eax+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1Cu, ctx.ecx);
	// 0x1F68B4: mov [eax+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.ecx);
	// 0x1F68B7: mov [eax+0x20], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x20u, ctx.ecx);
	// 0x1F68BA: mov [eax+0x30], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, ctx.ecx);
	// 0x1F68BD: mov [eax+0x34], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x34u, ctx.ecx);
	// 0x1F68C0: ret
	return;
}

void sub_1F68D0(X86Context& ctx, uint8_t* base) {
	// 0x1F68D0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F68D4: test byte ptr [eax+0x30], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x30u) & 2, 8);
	// 0x1F68D8: jz 0x001F68E3
	if (ctx.flags.zf) goto loc_1F68E3;
	// 0x1F68DA: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1F68DE: jmp 0x001FEDC0
	RwaHeapFree(ctx, base);
	return;
loc_1F68E3:
	// 0x1F68E3: ret
	return;
}

void rwaWaveDictCreateDumpedWavesCallback(X86Context& ctx, uint8_t* base) {
	// 0x1F68F0: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F68F4: cmp dword ptr [eax], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F68F7: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F68FB: jnz 0x001F6904
	if (!ctx.flags.zf) goto loc_1F6904;
	// 0x1F68FD: mov dword ptr [ecx+0x50], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x50u, 0);
loc_1F6904:
	// 0x1F6904: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F6907: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1F6909: jnz 0x001F690E
	if (!ctx.flags.zf) goto loc_1F690E;
	// 0x1F690B: mov eax, [ecx+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x54u);
loc_1F690E:
	// 0x1F690E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F690F: and eax, 0x02
	ctx.eax = ctx.eax & 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F6912: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6913: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6915: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6917: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6919: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F691B: call 0x001FAA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveCreateLoadedWave(ctx, base);
	ctx.esp += 4;
	// 0x1F6920: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6923: ret
	return;
}

void RwaWaveDictStreamHeaderByteSwap(X86Context& ctx, uint8_t* base) {
	// 0x1F6930: sub esp, 0x30
	{ uint32_t _d = ctx.esp; uint32_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6933: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6934: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6935: mov edi, [esp+0x3C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1F6939: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F693B: lea ecx, [esp+0x0C]
	ctx.ecx = ctx.esp + 0xCu;
	// 0x1F693F: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x1F6943: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6944: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6945: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1F6949: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1F694E: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F6952: mov dl, [edi+0x04]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.edi + 0x4u);
	// 0x1F6955: mov [eax], dl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.edx));
	// 0x1F6957: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F695B: mov cl, [edi+0x05]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi + 0x5u);
	// 0x1F695E: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F695F: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1F6963: mov [eax], cl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ecx));
	// 0x1F6965: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F6969: mov dl, [edi+0x06]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.edi + 0x6u);
	// 0x1F696C: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F696D: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1F6971: mov [eax], dl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.edx));
	// 0x1F6973: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F6977: mov cl, [edi+0x07]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi + 0x7u);
	// 0x1F697A: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F697B: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1F697F: mov [eax], cl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ecx));
	// 0x1F6981: inc [esp+0x14]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, (uint32_t)_res); }
	// 0x1F6985: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6987: lea edx, [edi+0x08]
	ctx.edx = ctx.edi + 0x8u;
	// 0x1F698A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F698B: lea eax, [esp+0x1C]
	ctx.eax = ctx.esp + 0x1Cu;
	// 0x1F698F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6990: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1F6995: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6997: lea ecx, [edi+0x0C]
	ctx.ecx = ctx.edi + 0xCu;
	// 0x1F699A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F699B: lea edx, [esp+0x28]
	ctx.edx = ctx.esp + 0x28u;
	// 0x1F699F: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69A0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1F69A5: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69A7: lea eax, [edi+0x10]
	ctx.eax = ctx.edi + 0x10u;
	// 0x1F69AA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69AB: lea ecx, [esp+0x34]
	ctx.ecx = ctx.esp + 0x34u;
	// 0x1F69AF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69B0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1F69B5: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69B7: lea edx, [edi+0x14]
	ctx.edx = ctx.edi + 0x14u;
	// 0x1F69BA: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69BB: lea eax, [esp+0x40]
	ctx.eax = ctx.esp + 0x40u;
	// 0x1F69BF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69C0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1F69C5: lea esi, [edi+0x18]
	ctx.esi = ctx.edi + 0x18u;
	// 0x1F69C8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69C9: call 0x001FE2A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDByteSwap(ctx, base);
	ctx.esp += 4;
	// 0x1F69CE: mov ecx, [esp+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x48u);
	// 0x1F69D2: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F69D4: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1F69D6: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F69D9: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x1F69DC: mov edx, [esi+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x1F69DF: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F69E2: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F69E5: mov [ecx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, ctx.eax);
	// 0x1F69E8: mov eax, [esp+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x48u);
	// 0x1F69EC: add esp, 0x40
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(64);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)64, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F69EF: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69F1: lea ecx, [edi+0x28]
	ctx.ecx = ctx.edi + 0x28u;
	// 0x1F69F4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69F5: lea edx, [esp+0x10]
	ctx.edx = ctx.esp + 0x10u;
	// 0x1F69F9: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F69FC: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F69FD: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1F6A01: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1F6A06: mov ecx, 0x0B
	ctx.ecx = 11;
	// 0x1F6A0B: lea esi, [esp+0x18]
	ctx.esi = ctx.esp + 0x18u;
	// 0x1F6A0F: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A12: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1F6A14: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A15: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A16: add esp, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)48, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A19: ret
	return;
}

void sub_1F6A20(X86Context& ctx, uint8_t* base) {
	// 0x1F6A20: sub esp, 0x5C
	{ uint32_t _d = ctx.esp; uint32_t _s = 92;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A23: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A24: mov ebx, [esp+0x64]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x64u);
	// 0x1F6A28: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A29: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A2A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A2C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A2D: call 0x001F6590
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapBlockFree(ctx, base);
	ctx.esp += 4;
	// 0x1F6A32: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F6A34: mov eax, [esp+0x78]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x78u);
	// 0x1F6A38: add eax, 0x7FF
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(2047);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)2047, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6A3D: mov ecx, 0x17
	ctx.ecx = 23;
	// 0x1F6A42: lea edi, [esp+0x14]
	ctx.edi = ctx.esp + 0x14u;
	// 0x1F6A46: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1F6A48: mov edx, [esp+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F6A4C: shr eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F6A4F: lea ecx, [esp+0x14]
	ctx.ecx = ctx.esp + 0x14u;
	// 0x1F6A53: shl eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F6A56: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A57: mov [esp+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4Cu, ctx.eax);
	// 0x1F6A5B: call [edx+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edx + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6A5E: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A61: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6A63: jnz 0x001F6A6C
	if (!ctx.flags.zf) goto loc_1F6A6C;
	// 0x1F6A65: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A66: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A67: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A68: add esp, 0x5C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(92);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)92, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A6B: ret
	return;
loc_1F6A6C:
	// 0x1F6A6C: mov ecx, [esp+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	// 0x1F6A70: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A71: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A72: mov [ebx+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x28u, ctx.eax);
	// 0x1F6A75: mov [ebx+0x2C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x2Cu, ctx.ecx);
	// 0x1F6A78: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A79: add esp, 0x5C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(92);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)92, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A7C: ret
	return;
}

void sub_1F6A80(X86Context& ctx, uint8_t* base) {
	// 0x1F6A80: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A81: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F6A85: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F6A88: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6A89: call [eax+0x24]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x24u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6A8C: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6A8F: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6A91: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6A92: ret
	return;
}

void sub_1F6AA0(X86Context& ctx, uint8_t* base) {
	// 0x1F6AA0: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F6AA4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AA5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F6AA9: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F6AAC: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AAE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AAF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AB0: call [eax+0x2C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x2Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6AB3: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AB5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AB6: call 0x001FAB90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FAB90(ctx, base);
	ctx.esp += 4;
	// 0x1F6ABB: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6ABE: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6AC0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6AC1: ret
	return;
}

void sub_1F6AD0(X86Context& ctx, uint8_t* base) {
	// 0x1F6AD0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F6AD4: mov ecx, [eax+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	// 0x1F6AD7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AD8: push 0x1F6AA0
	{ auto _pv = (uint32_t)(2058912); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6ADD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6ADE: call 0x001F64F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDictForAllWaves(ctx, base);
	ctx.esp += 4;
	// 0x1F6AE3: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6AE6: ret
	return;
}

void sub_1F6AF0(X86Context& ctx, uint8_t* base) {
	// 0x1F6AF0: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F6AF4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AF5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F6AF9: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F6AFC: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AFE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6AFF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B00: call [eax+0x2C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x2Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6B03: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B05: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B06: call 0x001FAB90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FAB90(ctx, base);
	ctx.esp += 4;
	// 0x1F6B0B: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6B0E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6B10: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6B11: ret
	return;
}

void RwaWaveDictFixup(X86Context& ctx, uint8_t* base) {
	// 0x1F6B20: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F6B24: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B26: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B27: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B28: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B29: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F6B2D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B2E: jz 0x001F6B42
	if (ctx.flags.zf) goto loc_1F6B42;
	// 0x1F6B30: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B31: call 0x001FE320
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE320(ctx, base);
	ctx.esp += 4;
	// 0x1F6B36: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x1F6B39: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B3A: call 0x001FE320
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE320(ctx, base);
	ctx.esp += 4;
	// 0x1F6B3F: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F6B42:
	// 0x1F6B42: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F6B45: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B47: mov ebx, [esp+0x18]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F6B4B: jz 0x001F6B52
	if (ctx.flags.zf) goto loc_1F6B52;
	// 0x1F6B4D: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6B4F: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
loc_1F6B52:
	// 0x1F6B52: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F6B55: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B57: jz 0x001F6B5E
	if (ctx.flags.zf) goto loc_1F6B5E;
	// 0x1F6B59: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6B5B: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
loc_1F6B5E:
	// 0x1F6B5E: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F6B61: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B63: jz 0x001F6B6A
	if (ctx.flags.zf) goto loc_1F6B6A;
	// 0x1F6B65: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6B67: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
loc_1F6B6A:
	// 0x1F6B6A: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x1F6B6D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B6F: jz 0x001F6B76
	if (ctx.flags.zf) goto loc_1F6B76;
	// 0x1F6B71: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6B73: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
loc_1F6B76:
	// 0x1F6B76: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F6B79: mov edi, [esi+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F6B7C: mov [esp+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.ecx);
loc_1F6B80:
	// 0x1F6B80: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1F6B84: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B86: mov ebp, edi
	ctx.ebp = ctx.edi;
	// 0x1F6B88: jz 0x001F6B93
	if (ctx.flags.zf) goto loc_1F6B93;
	// 0x1F6B8A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6B8B: call 0x001FE320
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE320(ctx, base);
	ctx.esp += 4;
	// 0x1F6B90: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F6B93:
	// 0x1F6B93: mov eax, [edi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x1F6B96: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6B98: lea ecx, [edi+0x08]
	ctx.ecx = ctx.edi + 0x8u;
	// 0x1F6B9B: jz 0x001F6BA1
	if (ctx.flags.zf) goto loc_1F6BA1;
	// 0x1F6B9D: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6B9F: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
loc_1F6BA1:
	// 0x1F6BA1: mov eax, [edi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x1F6BA4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BA6: jz 0x001F6BAD
	if (ctx.flags.zf) goto loc_1F6BAD;
	// 0x1F6BA8: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6BAA: mov [edi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.eax);
loc_1F6BAD:
	// 0x1F6BAD: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F6BAF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BB1: jz 0x001F6BB7
	if (ctx.flags.zf) goto loc_1F6BB7;
	// 0x1F6BB3: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6BB5: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
loc_1F6BB7:
	// 0x1F6BB7: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1F6BBB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BBD: mov edi, [edi+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x1F6BC0: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F6BC2: jz 0x001F6BCD
	if (ctx.flags.zf) goto loc_1F6BCD;
	// 0x1F6BC4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6BC5: call 0x001FABD0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FABD0(ctx, base);
	ctx.esp += 4;
	// 0x1F6BCA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F6BCD:
	// 0x1F6BCD: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F6BCF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BD1: jz 0x001F6BD7
	if (ctx.flags.zf) goto loc_1F6BD7;
	// 0x1F6BD3: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6BD5: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
loc_1F6BD7:
	// 0x1F6BD7: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F6BDA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BDC: jz 0x001F6BE3
	if (ctx.flags.zf) goto loc_1F6BE3;
	// 0x1F6BDE: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6BE0: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
loc_1F6BE3:
	// 0x1F6BE3: mov eax, [esi+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F6BE6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BE8: jz 0x001F6BEF
	if (ctx.flags.zf) goto loc_1F6BEF;
	// 0x1F6BEA: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6BEC: mov [esi+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x50u, ctx.eax);
loc_1F6BEF:
	// 0x1F6BEF: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x1F6BF2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6BF4: jz 0x001F6BFB
	if (ctx.flags.zf) goto loc_1F6BFB;
	// 0x1F6BF6: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6BF8: mov [esi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.eax);
loc_1F6BFB:
	// 0x1F6BFB: mov eax, [esi+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x3Cu);
	// 0x1F6BFE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F6C00: jz 0x001F6C07
	if (ctx.flags.zf) goto loc_1F6C07;
	// 0x1F6C02: add eax, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ebx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6C04: mov [esi+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.eax);
loc_1F6C07:
	// 0x1F6C07: mov edx, [esi+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x1F6C0A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6C0B: call 0x001FA200
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA200(ctx, base);
	ctx.esp += 4;
	// 0x1F6C10: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x1F6C13: mov eax, [esi+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	// 0x1F6C16: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6C17: call 0x001FA200
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA200(ctx, base);
	ctx.esp += 4;
	// 0x1F6C1C: mov [esi+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, ctx.eax);
	// 0x1F6C1F: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1F6C23: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6C26: cmp ebp, eax
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6C28: jnz 0x001F6B80
	if (!ctx.flags.zf) goto loc_1F6B80;
	// 0x1F6C2E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6C2F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6C30: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6C31: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6C32: ret
	return;
}

void sub_1F6C40(X86Context& ctx, uint8_t* base) {
	// 0x1F6C40: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F6C44: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6C45: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6C47: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6C49: jnz 0x001F6C63
	if (!ctx.flags.zf) goto loc_1F6C63;
	// 0x1F6C4B: push 0x30808
	{ auto _pv = (uint32_t)(198664); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6C50: push 0x48
	{ auto _pv = (uint32_t)(72); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6C52: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1F6C57: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6C5A: mov dword ptr [eax+0x30], 0x02
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, 2);
	// 0x1F6C61: jmp 0x001F6C6A
	goto loc_1F6C6A;
loc_1F6C63:
	// 0x1F6C63: mov dword ptr [eax+0x30], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, 1);
loc_1F6C6A:
	// 0x1F6C6A: mov [eax+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.esi);
	// 0x1F6C6D: mov [eax+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.esi);
	// 0x1F6C70: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x1F6C72: mov [eax+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.esi);
	// 0x1F6C75: mov [eax+0x40], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x40u, ctx.esi);
	// 0x1F6C78: mov [eax+0x24], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x24u, ctx.esi);
	// 0x1F6C7B: mov [eax+0x10], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.esi);
	// 0x1F6C7E: mov [eax+0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x1Cu, ctx.esi);
	// 0x1F6C81: mov [eax+0x14], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.esi);
	// 0x1F6C84: mov [eax+0x20], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x20u, ctx.esi);
	// 0x1F6C87: mov [eax+0x30], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x30u, ctx.esi);
	// 0x1F6C8A: mov [eax+0x34], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x34u, ctx.esi);
	// 0x1F6C8D: mov dword ptr [eax+0x2C], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x2Cu, 1);
	// 0x1F6C94: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6C95: ret
	return;
}

void rwaWaveDictLoaderLoadData(X86Context& ctx, uint8_t* base) {
	// 0x1F6CA0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CA1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CA2: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F6CA6: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F6CA9: mov ebx, [esi+0x28]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x1F6CAC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CAD: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6CAF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CB0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CB1: call [0x0041B404]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B404u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6CB7: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6CBA: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6CBD: jnz 0x001F6D39
	if (!ctx.flags.zf) goto loc_1F6D39;
	// 0x1F6CBF: mov eax, [esi+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x44u);
	// 0x1F6CC2: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6CC3: jz 0x001F6D02
	if (ctx.flags.zf) goto loc_1F6D02;
	// 0x1F6CC5: sub eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6CC8: jnz 0x001F6D21
	if (!ctx.flags.zf) goto loc_1F6D21;
	// 0x1F6CCA: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F6CCC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CCD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CCE: call 0x001F6590
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapBlockFree(ctx, base);
	ctx.esp += 4;
	// 0x1F6CD3: mov ecx, [esi+0x34]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x34u);
	// 0x1F6CD6: mov edx, [0x003C114C]
	ctx.edx = X86_MEM_READ_u32(base, 0x3C114Cu);
	// 0x1F6CDC: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6CDF: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6CE1: jnb 0x001F6CE5
	if (!ctx.flags.cf) goto loc_1F6CE5;
	// 0x1F6CE3: mov ecx, edx
	ctx.ecx = ctx.edx;
loc_1F6CE5:
	// 0x1F6CE5: cmp ebx, ecx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6CE7: jb 0x001F6CEB
	if (ctx.flags.cf) goto loc_1F6CEB;
	// 0x1F6CE9: mov ebx, ecx
	ctx.ebx = ctx.ecx;
loc_1F6CEB:
	// 0x1F6CEB: mov edx, [esi+0x40]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1F6CEE: mov ecx, [eax+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F6CF1: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F6CF4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CF5: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CF6: mov edx, [esi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F6CF9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CFA: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6CFB: call [ecx+0x28]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ecx + 0x28u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6CFE: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F6D00: jmp 0x001F6D1E
	goto loc_1F6D1E;
loc_1F6D02:
	// 0x1F6D02: mov edi, [esi+0x34]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x34u);
	// 0x1F6D05: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6D07: jnb 0x001F6D0B
	if (!ctx.flags.cf) goto loc_1F6D0B;
	// 0x1F6D09: mov edi, ebx
	ctx.edi = ctx.ebx;
loc_1F6D0B:
	// 0x1F6D0B: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1F6D10: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F6D13: mov edx, [esi+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F6D16: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D17: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D19: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D1A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D1B: call [eax+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_1F6D1E:
	// 0x1F6D1E: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F6D21:
	// 0x1F6D21: mov edx, [esi+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x1F6D24: mov ecx, [esi+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1F6D27: mov eax, [esi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x1F6D2A: add edx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.edi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F6D2C: add ecx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.edi, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1F6D2E: sub eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F6D30: mov [esi+0x24], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.edx);
	// 0x1F6D33: mov [esi+0x40], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.ecx);
	// 0x1F6D36: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
loc_1F6D39:
	// 0x1F6D39: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6D3A: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6D3C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6D3D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6D3E: ret
	return;
}

void sub_1F6D40(X86Context& ctx, uint8_t* base) {
	// 0x1F6D40: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D41: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D42: mov esi, [esp+0x28]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1F6D46: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F6D48: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D49: mov edi, 0x02
	ctx.edi = 2;
	// 0x1F6D4E: jnz 0x001F6D5F
	if (!ctx.flags.zf) goto loc_1F6D5F;
	// 0x1F6D50: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D51: call 0x001F6C40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6C40(ctx, base);
	ctx.esp += 4;
	// 0x1F6D56: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F6D58: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6D5B: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F6D5D: jz 0x001F6D64
	if (ctx.flags.zf) goto loc_1F6D64;
loc_1F6D5F:
	// 0x1F6D5F: cmp [esi+0x2C], edi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu); uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6D62: jz 0x001F6D7C
	if (ctx.flags.zf) goto loc_1F6D7C;
loc_1F6D64:
	// 0x1F6D64: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1F6D69: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F6D6D: push 0x36DB98
	{ auto _pv = (uint32_t)(3595160); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D72: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D73: call [eax+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6D76: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6D79: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
loc_1F6D7C:
	// 0x1F6D7C: mov ebp, [esi+0x04]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F6D7F: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1F6D81: jz 0x001F6E32
	if (ctx.flags.zf) goto loc_1F6E32;
	// 0x1F6D87: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D89: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6D8A: call [0x0041B404]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B404u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6D90: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6D93: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6D96: jz 0x001F6DA1
	if (ctx.flags.zf) goto loc_1F6DA1;
	// 0x1F6D98: mov [esi+0x2C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.edi);
	// 0x1F6D9B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6D9C: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6D9E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6D9F: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6DA0: ret
	return;
loc_1F6DA1:
	// 0x1F6DA1: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F6DA5: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1F6DA7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DA8: jnz 0x001F6DCC
	if (!ctx.flags.zf) goto loc_1F6DCC;
	// 0x1F6DAA: push 0x30808
	{ auto _pv = (uint32_t)(198664); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DAF: push 0x800
	{ auto _pv = (uint32_t)(2048); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DB4: call 0x001FED90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FED90(ctx, base);
	ctx.esp += 4;
	// 0x1F6DB9: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6DBC: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F6DBE: mov ebx, 0x800
	ctx.ebx = 2048;
	// 0x1F6DC3: mov dword ptr [esi+0x18], 0x10
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, 16);
	// 0x1F6DCA: jmp 0x001F6DED
	goto loc_1F6DED;
loc_1F6DCC:
	// 0x1F6DCC: mov ebx, [esp+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1F6DD0: cmp ebx, 0x800
	{ uint32_t _d = ctx.ebx; uint32_t _s = 2048;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6DD6: jnb 0x001F6DE6
	if (!ctx.flags.cf) goto loc_1F6DE6;
	// 0x1F6DD8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6DD9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6DDA: mov dword ptr [esi+0x2C], 0x2000
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, 8192);
	// 0x1F6DE1: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6DE3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6DE4: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6DE5: ret
	return;
loc_1F6DE6:
	// 0x1F6DE6: mov dword ptr [esi+0x18], 0x20
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, 32);
loc_1F6DED:
	// 0x1F6DED: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1F6DF2: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DF3: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DF5: push 0x800
	{ auto _pv = (uint32_t)(2048); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DFA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6DFB: call [eax+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6DFE: mov edx, [esp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1F6E02: mov eax, [esp+0x34]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x34u);
	// 0x1F6E06: mov ecx, [esp+0x3C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1F6E0A: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6E0D: mov [esi+0x14], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.ebx);
	// 0x1F6E10: mov dword ptr [esi+0x2C], 0x30
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, 48);
	// 0x1F6E17: mov dword ptr [esi+0x24], 0x800
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, 2048);
	// 0x1F6E1E: mov [esi+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.edi);
	// 0x1F6E21: mov [esi+0x1C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.edx);
	// 0x1F6E24: mov [esi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.eax);
	// 0x1F6E27: mov [esi+0x34], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, ctx.ecx);
	// 0x1F6E2A: mov dword ptr [esi+0x44], 0x03
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, 3);
	// 0x1F6E31: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F6E32:
	// 0x1F6E32: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6E33: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F6E35: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6E36: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6E37: ret
	return;
}

void sub_1F6E40(X86Context& ctx, uint8_t* base) {
	// 0x1F6E40: sub esp, 0x5C
	{ uint32_t _d = ctx.esp; uint32_t _s = 92;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6E43: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E44: mov esi, [esp+0x64]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x64u);
	// 0x1F6E48: test byte ptr [esi+0x1A], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x1Au) & 1, 8);
	// 0x1F6E4C: jz 0x001F6E63
	if (ctx.flags.zf) goto loc_1F6E63;
	// 0x1F6E4E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E50: push 0x1F6A80
	{ auto _pv = (uint32_t)(2058880); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E55: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E56: call 0x001F64F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDictForAllWaves(ctx, base);
	ctx.esp += 4;
	// 0x1F6E5B: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6E5E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6E5F: add esp, 0x5C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(92);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)92, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6E62: ret
	return;
loc_1F6E63:
	// 0x1F6E63: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E64: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E65: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6E67: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E68: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E69: call 0x001F6590
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapBlockFree(ctx, base);
	ctx.esp += 4;
	// 0x1F6E6E: mov ecx, [esi+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x1F6E71: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F6E73: mov eax, [esi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x1F6E76: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E77: push 0x1F6AF0
	{ auto _pv = (uint32_t)(2058992); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E7C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E7D: mov [esp+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x6Cu, ctx.eax);
	// 0x1F6E81: mov [esp+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x54u, ctx.ecx);
	// 0x1F6E85: mov [esp+0x49], bl
	X86_MEM_WRITE_u8(base, ctx.esp + 0x49u, X86_REG8L(ctx.ebx));
	// 0x1F6E89: mov [esp+0x70], ebx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x70u, ctx.ebx);
	// 0x1F6E8D: call 0x001F64F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDictForAllWaves(ctx, base);
	ctx.esp += 4;
	// 0x1F6E92: lea eax, [esp+0x20]
	ctx.eax = ctx.esp + 0x20u;
	// 0x1F6E96: mov [esi+0x28], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.ebx);
	// 0x1F6E99: mov edx, [edi+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x1F6E9C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6E9D: call [edx+0x24]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edx + 0x24u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6EA0: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6EA3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EA4: mov [esi+0x28], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.ebx);
	// 0x1F6EA7: mov [esi+0x2C], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.ebx);
	// 0x1F6EAA: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EAB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EAC: add esp, 0x5C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(92);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)92, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6EAF: ret
	return;
}

void rwaWaveDictLoaderLoadWaves(X86Context& ctx, uint8_t* base) {
	// 0x1F6EB0: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6EB3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6EB4: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6EB5: mov ebp, [esp+0x24]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1F6EB9: mov ebx, [ebp+0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x4u);
	// 0x1F6EBC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6EBD: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F6EBF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6EC0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6EC1: mov [esp+0x14], esi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.esi);
	// 0x1F6EC5: mov [esp+0x30], ebx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.ebx);
	// 0x1F6EC9: call [0x0041B404]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B404u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6ECF: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6ED2: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6ED5: jnz 0x001F70AD
	if (!ctx.flags.zf) goto loc_1F70AD;
	// 0x1F6EDB: mov eax, [ebp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x2Cu);
	// 0x1F6EDE: cmp eax, 0x30
	{ uint32_t _d = ctx.eax; uint32_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6EE1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6EE2: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1F6EE5: jz 0x001F6EFA
	if (ctx.flags.zf) goto loc_1F6EFA;
	// 0x1F6EE7: cmp eax, 0x50
	{ uint32_t _d = ctx.eax; uint32_t _s = 80;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6EEA: jz 0x001F6FB0
	if (ctx.flags.zf) goto loc_1F6FB0;
	// 0x1F6EF0: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EF1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EF2: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1F6EF4: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EF5: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6EF6: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6EF9: ret
	return;
loc_1F6EFA:
	// 0x1F6EFA: mov al, [edi+0x04]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0x4u);
	// 0x1F6EFD: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x1F6EFF: jz 0x001F6F12
	if (ctx.flags.zf) goto loc_1F6F12;
	// 0x1F6F01: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F02: call 0x001F6930
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDictStreamHeaderByteSwap(ctx, base);
	ctx.esp += 4;
	// 0x1F6F07: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6F0A: mov dword ptr [esp+0x10], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, 1);
loc_1F6F12:
	// 0x1F6F12: mov eax, [edi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x1F6F15: cmp [ebp+0x24], eax
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x24u); uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6F18: lea esi, [edi+0x08]
	ctx.esi = ctx.edi + 0x8u;
	// 0x1F6F1B: jnb 0x001F6FAE
	if (!ctx.flags.cf) goto loc_1F6FAE;
	// 0x1F6F21: test byte ptr [ebp+0x18], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebp + 0x18u) & 32, 8);
	// 0x1F6F25: jz 0x001F6F3D
	if (ctx.flags.zf) goto loc_1F6F3D;
	// 0x1F6F27: cmp eax, [ebp+0x14]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F6F2A: jbe 0x001F6F7B
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F6F7B;
	// 0x1F6F2C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6F2D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6F2E: mov dword ptr [ebp+0x2C], 0x2000
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x2Cu, 8192);
	// 0x1F6F35: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1F6F37: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6F38: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6F39: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6F3C: ret
	return;
loc_1F6F3D:
	// 0x1F6F3D: push 0x30808
	{ auto _pv = (uint32_t)(198664); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F42: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F43: call 0x001FED90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FED90(ctx, base);
	ctx.esp += 4;
	// 0x1F6F48: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1F6F4B: mov esi, [ebp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1F6F4E: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x1F6F50: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1F6F52: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1F6F55: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x1F6F57: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1F6F59: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F6F5B: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F6F5E: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x1F6F60: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1F6F63: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F64: call 0x001FEE90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaFreeAligned(ctx, base);
	ctx.esp += 4;
	// 0x1F6F69: lea esi, [ebx+0x08]
	ctx.esi = ctx.ebx + 0x8u;
	// 0x1F6F6C: mov [ebp+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.ebx);
	// 0x1F6F6F: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F6F71: mov ebx, [esp+0x38]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
	// 0x1F6F75: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6F78: mov [ebp+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x14u, ctx.edx);
loc_1F6F7B:
	// 0x1F6F7B: mov edi, [ebp+0x24]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x24u);
	// 0x1F6F7E: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1F6F83: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F6F85: mov edx, [ebp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1F6F88: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F89: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F8B: sub ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1F6F8D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F8E: add edx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.edi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F6F90: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6F91: call [eax+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F6F94: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1F6F97: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6F9A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6F9B: mov [ebp+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x24u, ctx.eax);
	// 0x1F6F9E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6F9F: mov dword ptr [ebp+0x2C], 0x50
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x2Cu, 80);
	// 0x1F6FA6: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1F6FA8: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6FA9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F6FAA: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F6FAD: ret
	return;
loc_1F6FAE:
	// 0x1F6FAE: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_1F6FB0:
	// 0x1F6FB0: mov ecx, [edi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x1F6FB3: add ecx, [ebp+0x10]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x10u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x10u), 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1F6FB6: mov edx, [ebp+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x24u);
	// 0x1F6FB9: mov [ebp], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp, ctx.ecx);
	// 0x1F6FBC: mov [ebp+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.edx);
	// 0x1F6FBF: mov eax, [edi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x14u);
	// 0x1F6FC2: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x1F6FC5: mov ecx, [edi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x14u);
	// 0x1F6FC8: mov [ebp+0x38], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x38u, ctx.esi);
	// 0x1F6FCB: mov [ebp+0x3C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x3Cu, ctx.esi);
	// 0x1F6FCE: mov esi, [ebp]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x1F6FD1: mov [ebp+0x28], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x28u, ctx.ecx);
	// 0x1F6FD4: mov edx, [esi+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F6FD7: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x1F6FDA: mov ebx, [esi+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F6FDD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F6FDE: mov [esp+0x24], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.edx);
	// 0x1F6FE2: mov [esp+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x28u, ctx.eax);
	// 0x1F6FE6: call 0x001F63F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDictCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F6FEB: mov cl, [ebp+0x18]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp + 0x18u);
	// 0x1F6FEE: mov edx, [esp+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1F6FF2: mov eax, [esp+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1F6FF6: mov [esi+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.edx);
	// 0x1F6FF9: mov edx, [esp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F6FFD: mov [esi+0x1B], cl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x1Bu, X86_REG8L(ctx.ecx));
	// 0x1F7000: mov [esi+0x0C], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ebx);
	// 0x1F7003: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x1F7006: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1F7009: mov [esi+0x24], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.ecx);
	// 0x1F700C: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1F700F: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7010: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7011: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7012: call 0x001F6B20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDictFixup(ctx, base);
	ctx.esp += 4;
	// 0x1F7017: mov ecx, [0x003C1150]
	ctx.ecx = X86_MEM_READ_u32(base, 0x3C1150u);
	// 0x1F701D: add edi, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)24, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1F7020: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7021: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7022: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F7027: mov edx, [ebp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x30u);
	// 0x1F702A: lea eax, [esp+0x2C]
	ctx.eax = ctx.esp + 0x2Cu;
	// 0x1F702E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F702F: push 0x1F68F0
	{ auto _pv = (uint32_t)(2058480); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7034: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7035: mov dword ptr [esp+0x38], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp + 0x38u, 1);
	// 0x1F703D: mov [esp+0x3C], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x3Cu, ctx.edx);
	// 0x1F7041: call 0x001F64F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDictForAllWaves(ctx, base);
	ctx.esp += 4;
	// 0x1F7046: mov al, [ebp+0x30]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp + 0x30u);
	// 0x1F7049: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F704C: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x1F704E: jz 0x001F7061
	if (ctx.flags.zf) goto loc_1F7061;
	// 0x1F7050: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7051: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7052: mov dword ptr [ebp+0x2C], 0x300
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x2Cu, 768);
	// 0x1F7059: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1F705B: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F705C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F705D: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7060: ret
	return;
loc_1F7061:
	// 0x1F7061: mov eax, [ebp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x1F7064: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7066: mov dword ptr [ebp+0x2C], 0x70
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x2Cu, 112);
	// 0x1F706D: jnz 0x001F709A
	if (!ctx.flags.zf) goto loc_1F709A;
	// 0x1F706F: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x1F7072: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7073: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7074: call 0x001F6A20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6A20(ctx, base);
	ctx.esp += 4;
	// 0x1F7079: mov [ebp+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x1Cu, ctx.eax);
	// 0x1F707C: mov al, [esi+0x1B]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x1Bu);
	// 0x1F707F: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7082: or al, 0x40
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) | 64;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x1F7084: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7085: mov [esi+0x1B], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x1Bu, X86_REG8L(ctx.eax));
	// 0x1F7088: call 0x001F6CA0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDictLoaderLoadData(ctx, base);
	ctx.esp += 4;
	// 0x1F708D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7090: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7091: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7092: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1F7094: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7095: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7096: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7099: ret
	return;
loc_1F709A:
	// 0x1F709A: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x1F709D: mov edx, [ebp+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x20u);
	// 0x1F70A0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F70A1: mov [esi+0x2C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.edx);
	// 0x1F70A4: call 0x001F6CA0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDictLoaderLoadData(ctx, base);
	ctx.esp += 4;
	// 0x1F70A9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F70AC: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F70AD:
	// 0x1F70AD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F70AE: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1F70B0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F70B1: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F70B2: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F70B5: ret
	return;
}

void sub_1F70C0(X86Context& ctx, uint8_t* base) {
	// 0x1F70C0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F70C1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F70C5: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x1F70C8: cmp eax, 0x30
	{ uint32_t _d = ctx.eax; uint32_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F70CB: jz 0x001F7135
	if (ctx.flags.zf) goto loc_1F7135;
	// 0x1F70CD: cmp eax, 0x50
	{ uint32_t _d = ctx.eax; uint32_t _s = 80;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F70D0: jz 0x001F7135
	if (ctx.flags.zf) goto loc_1F7135;
	// 0x1F70D2: cmp eax, 0x70
	{ uint32_t _d = ctx.eax; uint32_t _s = 112;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F70D5: jnz 0x001F713E
	if (!ctx.flags.zf) goto loc_1F713E;
	// 0x1F70D7: mov eax, [esi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x28u);
	// 0x1F70DA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F70DC: jz 0x001F70EC
	if (ctx.flags.zf) goto loc_1F70EC;
	// 0x1F70DE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F70DF: call 0x001F6CA0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDictLoaderLoadData(ctx, base);
	ctx.esp += 4;
	// 0x1F70E4: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x1F70E7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F70EA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F70EB: ret
	return;
loc_1F70EC:
	// 0x1F70EC: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F70EF: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F70F1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F70F2: call [0x0041B404]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B404u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F70F8: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F70FB: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F70FE: jnz 0x001F713E
	if (!ctx.flags.zf) goto loc_1F713E;
	// 0x1F7100: test byte ptr [esi+0x30], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x30u) & 4, 8);
	// 0x1F7104: jz 0x001F7112
	if (ctx.flags.zf) goto loc_1F7112;
	// 0x1F7106: mov dword ptr [esi+0x2C], 0x500
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, 1280);
	// 0x1F710D: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x1F7110: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7111: ret
	return;
loc_1F7112:
	// 0x1F7112: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F7114: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7115: call 0x001F6AD0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6AD0(ctx, base);
	ctx.esp += 4;
	// 0x1F711A: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1F711F: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F7122: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7123: call [eax+0x08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F7126: mov dword ptr [esi+0x2C], 0x100
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, 256);
	// 0x1F712D: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x1F7130: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7133: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7134: ret
	return;
loc_1F7135:
	// 0x1F7135: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7136: call 0x001F6EB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDictLoaderLoadWaves(ctx, base);
	ctx.esp += 4;
	// 0x1F713B: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F713E:
	// 0x1F713E: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x1F7141: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7142: ret
	return;
}

void sub_1F7150(X86Context& ctx, uint8_t* base) {
	// 0x1F7150: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F7154: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7158: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F715C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F715D: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F7161: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7162: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7164: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7165: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7166: push 0x41B4D0
	{ auto _pv = (uint32_t)(4306128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F716B: call 0x001F6050
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F7170: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7173: ret
	return;
}

void RwaVirtualListenerUnregister(X86Context& ctx, uint8_t* base) {
	// 0x1F7180: mov eax, [0x0041B54C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B54Cu);
	// 0x1F7185: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7187: jz 0x001F719D
	if (ctx.flags.zf) goto loc_1F719D;
	// 0x1F7189: call 0x001FFF70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FFF70(ctx, base);
	ctx.esp += 4;
	// 0x1F718E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7190: jnz 0x001F7193
	if (!ctx.flags.zf) goto loc_1F7193;
	// 0x1F7192: ret
	return;
loc_1F7193:
	// 0x1F7193: mov dword ptr [0x0041B54C], 0x00
	X86_MEM_WRITE_u32(base, 0x41B54Cu, 0);
loc_1F719D:
	// 0x1F719D: push 0x41B4D0
	{ auto _pv = (uint32_t)(4306128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F71A2: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F71A7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F71AA: ret
	return;
}

void sub_1F71B0(X86Context& ctx, uint8_t* base) {
	// 0x1F71B0: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F71B3: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F71B7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F71B8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F71B9: lea ecx, [eax+0x30]
	ctx.ecx = ctx.eax + 0x30u;
	// 0x1F71BC: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x1F71BE: mov dword ptr [esp+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, 0);
	// 0x1F71C6: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F71CA: mov [edi], ecx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ecx);
	// 0x1F71CC: mov dword ptr [esp+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, 0);
	// 0x1F71D4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F71D8: mov [edi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.edx);
	// 0x1F71DB: mov dword ptr [esp+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, 0);
	// 0x1F71E3: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F71E7: mov [edi+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.esi);
	// 0x1F71EA: lea edi, [eax+0x3C]
	ctx.edi = ctx.eax + 0x3Cu;
	// 0x1F71ED: mov [edi], ecx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ecx);
	// 0x1F71EF: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F71F1: mov [edi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.edx);
	// 0x1F71F4: mov [edi+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.esi);
	// 0x1F71F7: mov [esp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.ecx);
	// 0x1F71FB: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F71FF: mov [esp+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.ecx);
	// 0x1F7203: mov [eax+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, ctx.ecx);
	// 0x1F7206: mov [eax+0x58], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x58u, ctx.ecx);
	// 0x1F7209: lea ecx, [eax+0x48]
	ctx.ecx = ctx.eax + 0x48u;
	// 0x1F720C: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1F720E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F7210: mov dword ptr [esp+0x0C], 0x3F800000
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, 1065353216);
	// 0x1F7218: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F721C: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F721F: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F7223: mov [edx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.esi);
	// 0x1F7226: fld [eax+0x50]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F7229: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F722F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7230: fld [eax+0x4C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F7233: mov dword ptr [eax+0x5C], 0x3F800000
	X86_MEM_WRITE_u32(base, ctx.eax + 0x5Cu, 1065353216);
	// 0x1F723A: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x1F723C: mov dword ptr [eax+0x6C], 0x0B
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, 11);
	// 0x1F7243: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7244: fstp [eax+0x60]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x60u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7247: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F7249: fsubr st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	// 0x1F724B: fstp [eax+0x64]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x64u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F724E: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7250: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F7252: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7258: fld [eax+0x4C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F725B: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7261: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7263: fstp [eax+0x68]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x68u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7266: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7269: ret
	return;
}

void sub_1F7270(X86Context& ctx, uint8_t* base) {
	// 0x1F7270: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7274: mov ecx, [eax+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	// 0x1F7277: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F7279: jz 0x001F728C
	if (ctx.flags.zf) goto loc_1F728C;
	// 0x1F727B: mov ecx, [eax+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x2Cu);
	// 0x1F727E: mov edx, [eax+0x28]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	// 0x1F7281: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1F7283: mov ecx, [eax+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	// 0x1F7286: mov edx, [eax+0x2C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x2Cu);
	// 0x1F7289: mov [ecx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.edx);
loc_1F728C:
	// 0x1F728C: ret
	return;
}

void sub_1F7290(X86Context& ctx, uint8_t* base) {
	// 0x1F7290: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7294: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7298: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7299: mov esi, [edx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F729B: lea ecx, [eax+0x30]
	ctx.ecx = ctx.eax + 0x30u;
	// 0x1F729E: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x1F72A0: mov esi, [edx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F72A3: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1F72A6: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F72A9: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F72AC: or dword ptr [eax+0x6C], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, X86_MEM_READ_u32(base, ctx.eax + 0x6Cu) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x6Cu), 32);
	// 0x1F72B0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F72B1: ret
	return;
}

void sub_1F72C0(X86Context& ctx, uint8_t* base) {
	// 0x1F72C0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F72C4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F72C8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F72C9: mov esi, [edx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F72CB: lea ecx, [eax+0x3C]
	ctx.ecx = ctx.eax + 0x3Cu;
	// 0x1F72CE: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x1F72D0: mov esi, [edx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F72D3: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1F72D6: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F72D9: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F72DC: or dword ptr [eax+0x6C], 0x02
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, X86_MEM_READ_u32(base, ctx.eax + 0x6Cu) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x6Cu), 32);
	// 0x1F72E0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F72E1: ret
	return;
}

void sub_1F72F0(X86Context& ctx, uint8_t* base) {
	// 0x1F72F0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F72F4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F72F8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F72F9: lea ecx, [eax+0x3C]
	ctx.ecx = ctx.eax + 0x3Cu;
	// 0x1F72FC: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F72FE: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F7300: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F7303: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F7306: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F7309: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F730C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F730D: ret
	return;
}

void sub_1F7310(X86Context& ctx, uint8_t* base) {
	// 0x1F7310: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7314: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7318: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7319: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F731A: lea edx, [ecx+0x10]
	ctx.edx = ctx.ecx + 0x10u;
	// 0x1F731D: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F731F: lea esi, [eax+0x48]
	ctx.esi = ctx.eax + 0x48u;
	// 0x1F7322: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F7324: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F7327: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F732A: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F732D: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F7330: lea edx, [ecx+0x20]
	ctx.edx = ctx.ecx + 0x20u;
	// 0x1F7333: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F7335: lea esi, [eax+0x54]
	ctx.esi = ctx.eax + 0x54u;
	// 0x1F7338: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F733A: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F733D: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F7340: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F7343: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F7346: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F7348: lea edx, [eax+0x60]
	ctx.edx = ctx.eax + 0x60u;
	// 0x1F734B: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F734D: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F7350: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F7353: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F7356: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F7359: mov ecx, [eax+0x6C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x6Cu);
	// 0x1F735C: or ecx, 0x0C
	ctx.ecx = ctx.ecx | 12;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F735F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7360: mov [eax+0x6C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, ctx.ecx);
	// 0x1F7363: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7364: ret
	return;
}

void sub_1F7370(X86Context& ctx, uint8_t* base) {
	// 0x1F7370: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7374: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7378: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7379: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F737A: lea edx, [eax+0x48]
	ctx.edx = ctx.eax + 0x48u;
	// 0x1F737D: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F737F: lea esi, [ecx+0x10]
	ctx.esi = ctx.ecx + 0x10u;
	// 0x1F7382: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F7384: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F7387: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F738A: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F738D: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F7390: lea edx, [eax+0x54]
	ctx.edx = ctx.eax + 0x54u;
	// 0x1F7393: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F7395: lea esi, [ecx+0x20]
	ctx.esi = ctx.ecx + 0x20u;
	// 0x1F7398: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F739A: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F739D: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F73A0: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F73A3: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F73A6: lea edx, [eax+0x60]
	ctx.edx = ctx.eax + 0x60u;
	// 0x1F73A9: mov esi, [edx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F73AB: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x1F73AD: mov esi, [edx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F73B0: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1F73B3: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F73B6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F73B7: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F73BA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F73BB: ret
	return;
}

void sub_1F73C0(X86Context& ctx, uint8_t* base) {
	// 0x1F73C0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F73C4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F73C8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F73C9: lea ecx, [eax+0x48]
	ctx.ecx = ctx.eax + 0x48u;
	// 0x1F73CC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F73CD: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F73CF: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x1F73D1: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F73D3: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F73D6: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F73D9: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F73DC: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F73DF: fld [eax+0x4C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F73E2: fmul [eax+0x5C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x5Cu));
	// 0x1F73E5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F73E6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F73E7: fld [eax+0x50]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F73EA: fmul [eax+0x58]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x58u));
	// 0x1F73ED: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F73EF: fstp [eax+0x60]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x60u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F73F2: fld [eax+0x54]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x54u));
	// 0x1F73F5: fmul [eax+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F73F8: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F73FA: fmul [eax+0x5C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x5Cu));
	// 0x1F73FD: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F73FF: fstp [eax+0x64]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x64u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7402: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F7404: mov ecx, [eax+0x6C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x6Cu);
	// 0x1F7407: fmul [eax+0x58]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x58u));
	// 0x1F740A: or ecx, 0x08
	ctx.ecx = ctx.ecx | 8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F740D: mov [eax+0x6C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, ctx.ecx);
	// 0x1F7410: fld [eax+0x54]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x54u));
	// 0x1F7413: fmul [eax+0x4C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F7416: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7418: fstp [eax+0x68]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x68u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F741B: ret
	return;
}

void sub_1F7420(X86Context& ctx, uint8_t* base) {
	// 0x1F7420: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7424: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7428: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7429: lea ecx, [eax+0x48]
	ctx.ecx = ctx.eax + 0x48u;
	// 0x1F742C: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F742E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F7430: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F7433: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F7436: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F7439: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F743C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F743D: ret
	return;
}

void sub_1F7440(X86Context& ctx, uint8_t* base) {
	// 0x1F7440: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7444: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7448: fld [eax+0x4C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F744B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F744C: lea ecx, [eax+0x54]
	ctx.ecx = ctx.eax + 0x54u;
	// 0x1F744F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7450: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F7452: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x1F7454: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F7456: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F7459: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F745C: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F745F: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F7462: fmul [eax+0x5C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x5Cu));
	// 0x1F7465: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7466: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7467: fld [eax+0x50]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F746A: fmul [eax+0x58]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x58u));
	// 0x1F746D: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F746F: fstp [eax+0x60]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x60u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7472: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F7474: fmul [eax+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F7477: fld [eax+0x48]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F747A: fmul [eax+0x5C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x5Cu));
	// 0x1F747D: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F747F: fstp [eax+0x64]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x64u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7482: fld [eax+0x48]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F7485: fmul [eax+0x58]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x58u));
	// 0x1F7488: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F748A: fmul [eax+0x4C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F748D: mov ecx, [eax+0x6C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x6Cu);
	// 0x1F7490: or ecx, 0x04
	ctx.ecx = ctx.ecx | 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F7493: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7495: mov [eax+0x6C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, ctx.ecx);
	// 0x1F7498: fstp [eax+0x68]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x68u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F749B: ret
	return;
}

void sub_1F74A0(X86Context& ctx, uint8_t* base) {
	// 0x1F74A0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F74A4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F74A8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74A9: lea ecx, [eax+0x60]
	ctx.ecx = ctx.eax + 0x60u;
	// 0x1F74AC: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F74AE: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F74B0: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F74B3: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F74B6: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F74B9: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F74BC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F74BD: ret
	return;
}

void sub_1F74C0(X86Context& ctx, uint8_t* base) {
	// 0x1F74C0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74C1: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74C3: push 0x36DB9C
	{ auto _pv = (uint32_t)(3595164); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74C8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74C9: call 0x001F8550
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1F74CE: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74D0: mov dword ptr [esi+0x40], 0x48
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, 72);
	// 0x1F74D7: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F74DC: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F74E1: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F74E4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F74E6: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F74E8: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F74EB: jz 0x001F7505
	if (ctx.flags.zf) goto loc_1F7505;
	// 0x1F74ED: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F74EF: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F74F4: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F74F9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F74FC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F74FE: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7500: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F7503: jmp 0x001F750A
	goto loc_1F750A;
loc_1F7505:
	// 0x1F7505: mov eax, 0x01
	ctx.eax = 1;
loc_1F750A:
	// 0x1F750A: test eax, 0xFFFF0000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & -65536, 32);
	// 0x1F750F: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7511: jz 0x001F760D
	if (ctx.flags.zf) goto loc_1F760D;
	// 0x1F7517: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F751C: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F7521: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7524: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F7526: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7528: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F752B: jz 0x001F7548
	if (ctx.flags.zf) goto loc_1F7548;
	// 0x1F752D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F752F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F7534: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F7539: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F753C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F753E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7540: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F7543: mov [esp], eax
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.eax);
	// 0x1F7546: jmp 0x001F754F
	goto loc_1F754F;
loc_1F7548:
	// 0x1F7548: mov dword ptr [esp], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp, 1);
loc_1F754F:
	// 0x1F754F: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F7551: mov ch, [esp+0x03]
	X86_REG8H(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esp + 0x3u);
	// 0x1F7555: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7557: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F7559: jz 0x001F75B6
	if (ctx.flags.zf) goto loc_1F75B6;
	// 0x1F755B: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F7560: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F7565: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7568: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F756A: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F756C: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F756F: jz 0x001F759C
	if (ctx.flags.zf) goto loc_1F759C;
	// 0x1F7571: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7573: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F7578: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F757D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7580: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F7582: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7584: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F7587: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F758A: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F7591: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7594: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7597: jmp 0x001F76D1
	goto loc_1F76D1;
loc_1F759C:
	// 0x1F759C: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F75A1: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F75A4: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F75AB: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F75AE: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F75B1: jmp 0x001F76D1
	goto loc_1F76D1;
loc_1F75B6:
	// 0x1F75B6: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F75BB: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F75C0: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F75C3: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F75C5: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F75C7: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F75CA: jz 0x001F75F5
	if (ctx.flags.zf) goto loc_1F75F5;
	// 0x1F75CC: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F75CE: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F75D3: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F75D8: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F75DB: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F75DD: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F75DF: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F75E2: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F75E5: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F75EC: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F75ED: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F75F0: jmp 0x001F76D1
	goto loc_1F76D1;
loc_1F75F5:
	// 0x1F75F5: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F75FA: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F75FD: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F7604: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7605: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7608: jmp 0x001F76D1
	goto loc_1F76D1;
loc_1F760D:
	// 0x1F760D: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F7612: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F7617: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F761A: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F761C: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F761E: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F7621: jz 0x001F763B
	if (ctx.flags.zf) goto loc_1F763B;
	// 0x1F7623: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7625: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F762A: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F762F: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7632: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F7634: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7636: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F7639: jmp 0x001F7640
	goto loc_1F7640;
loc_1F763B:
	// 0x1F763B: mov eax, 0x01
	ctx.eax = 1;
loc_1F7640:
	// 0x1F7640: test ah, 0xFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & -1, 8);
	// 0x1F7643: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7645: jz 0x001F7696
	if (ctx.flags.zf) goto loc_1F7696;
	// 0x1F7647: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F764C: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F7651: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7654: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F7656: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7658: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F765B: jz 0x001F7682
	if (ctx.flags.zf) goto loc_1F7682;
	// 0x1F765D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F765F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F7664: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F7669: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F766C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F766E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F7670: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F7673: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F7676: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F767D: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7680: jmp 0x001F76D1
	goto loc_1F76D1;
loc_1F7682:
	// 0x1F7682: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F7687: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F768A: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F7691: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7694: jmp 0x001F76D1
	goto loc_1F76D1;
loc_1F7696:
	// 0x1F7696: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F769B: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F76A0: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F76A3: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F76A5: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F76A7: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F76AA: jz 0x001F76C4
	if (ctx.flags.zf) goto loc_1F76C4;
	// 0x1F76AC: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F76AE: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F76B3: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F76B8: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F76BB: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F76BD: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F76BF: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F76C2: jmp 0x001F76C9
	goto loc_1F76C9;
loc_1F76C4:
	// 0x1F76C4: mov eax, 0x01
	ctx.eax = 1;
loc_1F76C9:
	// 0x1F76C9: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F76D0: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_1F76D1:
	// 0x1F76D1: mov ecx, [esi+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1F76D4: shl eax, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F76D7: or ecx, eax
	ctx.ecx = ctx.ecx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F76D9: mov [esi+0x40], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.ecx);
	// 0x1F76DC: mov dword ptr [esi+0x28], 0x1F71B0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 2060720);
	// 0x1F76E3: mov dword ptr [esi+0x34], 0x1F7270
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, 2060912);
	// 0x1F76EA: mov word ptr [esi+0x44], 0x00
	X86_MEM_WRITE_u16(base, ctx.esi + 0x44u, 0);
	// 0x1F76F0: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F76F1: ret
	return;
}

void sub_1F7700(X86Context& ctx, uint8_t* base) {
	// 0x1F7700: mov eax, [0x00764134]
	ctx.eax = X86_MEM_READ_u32(base, 0x764134u);
	// 0x1F7705: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7706: push 0x3080C
	{ auto _pv = (uint32_t)(198668); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F770B: push 0x41B52C
	{ auto _pv = (uint32_t)(4306220); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7710: push 0x41B534
	{ auto _pv = (uint32_t)(4306228); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7715: push 0x41B4D0
	{ auto _pv = (uint32_t)(4306128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F771A: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F771C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F771D: call 0x001F8E20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F7722: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F7724: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7727: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F7729: jz 0x001F775D
	if (ctx.flags.zf) goto loc_1F775D;
	// 0x1F772B: call 0x001F74C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F74C0(ctx, base);
	ctx.esp += 4;
	// 0x1F7730: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7732: push 0x3C11D0
	{ auto _pv = (uint32_t)(3936720); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7737: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7739: push 0x3C1158
	{ auto _pv = (uint32_t)(3936600); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F773E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F773F: call 0x001F8B70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8B70(ctx, base);
	ctx.esp += 4;
	// 0x1F7744: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7747: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7749: jz 0x001F7754
	if (ctx.flags.zf) goto loc_1F7754;
	// 0x1F774B: call 0x001FFF20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FFF20(ctx, base);
	ctx.esp += 4;
	// 0x1F7750: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7752: jnz 0x001F7761
	if (!ctx.flags.zf) goto loc_1F7761;
loc_1F7754:
	// 0x1F7754: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7755: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F775A: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F775D:
	// 0x1F775D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F775F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7760: ret
	return;
loc_1F7761:
	// 0x1F7761: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7762: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7763: call 0x001F8520
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8520(ctx, base);
	ctx.esp += 4;
	// 0x1F7768: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F776B: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F776D: mov dword ptr [0x0041B54C], 0x01
	X86_MEM_WRITE_u32(base, 0x41B54Cu, 1);
	// 0x1F7777: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7778: ret
	return;
}

void _rwaListenerManagerOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1F7780: mov eax, 0x41B550
	ctx.eax = 4306256;
	// 0x1F7785: mov dword ptr [0x0041B558], 0x01
	X86_MEM_WRITE_u32(base, 0x41B558u, 1);
	// 0x1F778F: mov [0x0041B550], eax
	X86_MEM_WRITE_u32(base, 0x41B550u, ctx.eax);
	// 0x1F7794: mov [0x0041B554], eax
	X86_MEM_WRITE_u32(base, 0x41B554u, ctx.eax);
	// 0x1F7799: call 0x001F7700
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F7700(ctx, base);
	ctx.esp += 4;
	// 0x1F779E: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F77A3: ret
	return;
}

void _rwaListenerManagerCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1F77B0: call 0x001F7180
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVirtualListenerUnregister(ctx, base);
	ctx.esp += 4;
	// 0x1F77B5: mov dword ptr [0x0041B558], 0x00
	X86_MEM_WRITE_u32(base, 0x41B558u, 0);
	// 0x1F77BF: ret
	return;
}

void sub_1F77C0(X86Context& ctx, uint8_t* base) {
	// 0x1F77C0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F77C4: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F77C7: mov dword ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 0);
	// 0x1F77CE: mov dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, 0);
	// 0x1F77D4: mov ecx, [0x0041B550]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B550u);
	// 0x1F77DA: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F77DC: mov dword ptr [eax+0x04], 0x41B550
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 4306256);
	// 0x1F77E3: mov edx, [0x0041B550]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B550u);
	// 0x1F77E9: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1F77EC: mov [0x0041B550], eax
	X86_MEM_WRITE_u32(base, 0x41B550u, ctx.eax);
	// 0x1F77F1: ret
	return;
}

void sub_1F7800(X86Context& ctx, uint8_t* base) {
	// 0x1F7800: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7804: mov [0x003C1260], eax
	X86_MEM_WRITE_u32(base, 0x3C1260u, ctx.eax);
	// 0x1F7809: ret
	return;
}

void sub_1F7810(X86Context& ctx, uint8_t* base) {
	// 0x1F7810: mov eax, [0x0041B550]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B550u);
	// 0x1F7815: cmp eax, 0x41B550
	{ uint32_t _d = ctx.eax; uint32_t _s = 4306256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F781A: jz 0x001F7837
	if (ctx.flags.zf) goto loc_1F7837;
	// 0x1F781C: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7820: lea ecx, [edx+0x28]
	ctx.ecx = ctx.edx + 0x28u;
loc_1F7823:
	// 0x1F7823: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F7825: jz 0x001F7831
	if (ctx.flags.zf) goto loc_1F7831;
	// 0x1F7827: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F7829: cmp eax, 0x41B550
	{ uint32_t _d = ctx.eax; uint32_t _s = 4306256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F782E: jnz 0x001F7823
	if (!ctx.flags.zf) goto loc_1F7823;
	// 0x1F7830: ret
	return;
loc_1F7831:
	// 0x1F7831: mov [0x0041B55C], edx
	X86_MEM_WRITE_u32(base, 0x41B55Cu, ctx.edx);
loc_1F7837:
	// 0x1F7837: ret
	return;
}

void sub_1F7840(X86Context& ctx, uint8_t* base) {
	// 0x1F7840: sub esp, 0x30
	{ uint32_t _d = ctx.esp; uint32_t _s = 48;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7843: lea eax, [edi+0x60]
	ctx.eax = ctx.edi + 0x60u;
	// 0x1F7846: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7847: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x1F784B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F784C: call 0x001DBA70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1DBA70(ctx, base);
	ctx.esp += 4;
	// 0x1F7851: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7853: lea edx, [edi+0x48]
	ctx.edx = ctx.edi + 0x48u;
	// 0x1F7856: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7857: lea eax, [esp+0x24]
	ctx.eax = ctx.esp + 0x24u;
	// 0x1F785B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F785C: call 0x001DBA70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1DBA70(ctx, base);
	ctx.esp += 4;
	// 0x1F7861: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7863: lea ecx, [edi+0x54]
	ctx.ecx = ctx.edi + 0x54u;
	// 0x1F7866: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7867: lea edx, [esp+0x38]
	ctx.edx = ctx.esp + 0x38u;
	// 0x1F786B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F786C: call 0x001DBA70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1DBA70(ctx, base);
	ctx.esp += 4;
	// 0x1F7871: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7873: fld [esi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi));
	// 0x1F7875: fsub [edi+0x30]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x30u));
	// 0x1F7878: fld [esi+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x4u));
	// 0x1F787B: fsub [edi+0x34]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x34u));
	// 0x1F787E: fld [esi+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x8u));
	// 0x1F7881: fsub [edi+0x38]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x38u));
	// 0x1F7884: fld [esp+0x28]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x28u));
	// 0x1F7888: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F788A: fld [esp+0x24]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x24u));
	// 0x1F788E: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F7890: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7892: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7896: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7898: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F789A: fstp [esi]
	X86_MEM_WRITE_F32(base, ctx.esi, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F789C: fld [esp+0x34]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x34u));
	// 0x1F78A0: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F78A2: fld [esp+0x30]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x30u));
	// 0x1F78A6: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F78A8: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F78AA: fld [esp+0x38]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x38u));
	// 0x1F78AE: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F78B0: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F78B2: fstp [esi+0x04]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F78B5: fld [esp+0x40]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x40u));
	// 0x1F78B9: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F78BB: fld [esp+0x3C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x3Cu));
	// 0x1F78BF: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F78C1: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F78C3: fld [esp+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x44u));
	// 0x1F78C7: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F78C9: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F78CB: fstp [esi+0x08]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F78CE: lea eax, [esi+0x18]
	ctx.eax = ctx.esi + 0x18u;
	// 0x1F78D1: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F78D3: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F78D5: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F78D7: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F78D9: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F78DB: mov [esp+0x18], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.edx);
	// 0x1F78DF: fld [esi+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0xCu));
	// 0x1F78E2: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F78E5: fsub [edi+0x3C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x3Cu));
	// 0x1F78E8: mov [esp+0x1C], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.edx);
	// 0x1F78EC: fld [esi+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x10u));
	// 0x1F78EF: fsub [edi+0x40]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x40u));
	// 0x1F78F2: fld [esi+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x14u));
	// 0x1F78F5: fsub [edi+0x44]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x44u));
	// 0x1F78F8: fld [esp+0x28]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x28u));
	// 0x1F78FC: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F78FE: fld [esp+0x24]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x24u));
	// 0x1F7902: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F7904: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7906: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F790A: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F790C: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F790E: fstp [esi+0x0C]
	X86_MEM_WRITE_F32(base, ctx.esi + 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7911: fld [esp+0x34]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x34u));
	// 0x1F7915: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7917: fld [esp+0x30]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x30u));
	// 0x1F791B: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F791D: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F791F: fld [esp+0x38]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x38u));
	// 0x1F7923: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7925: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7927: fstp [esi+0x10]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x10u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F792A: fld [esp+0x40]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x40u));
	// 0x1F792E: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7930: fld [esp+0x3C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x3Cu));
	// 0x1F7934: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F7936: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7938: fld [esp+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x44u));
	// 0x1F793C: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F793E: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7940: fstp [esi+0x14]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x14u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7943: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7945: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7947: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7949: fld [esp+0x28]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x28u));
	// 0x1F794D: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F7950: fmul [esp+0x1C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x1Cu));
	// 0x1F7954: mov [esp+0x20], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.ecx);
	// 0x1F7958: fld [esp+0x24]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x24u));
	// 0x1F795C: fmul [esp+0x18]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7960: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7962: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7966: fmul [esp+0x20]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x20u));
	// 0x1F796A: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F796C: fstp [eax]
	X86_MEM_WRITE_F32(base, ctx.eax, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F796E: fld [esp+0x34]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x34u));
	// 0x1F7972: fmul [esp+0x1C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x1Cu));
	// 0x1F7976: fld [esp+0x30]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x30u));
	// 0x1F797A: fmul [esp+0x18]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F797E: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7980: fld [esp+0x38]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x38u));
	// 0x1F7984: fmul [esp+0x20]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x20u));
	// 0x1F7988: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F798A: fstp [esi+0x1C]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x1Cu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F798D: fld [esp+0x40]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x40u));
	// 0x1F7991: fmul [esp+0x1C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x1Cu));
	// 0x1F7995: fld [esp+0x3C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x3Cu));
	// 0x1F7999: fmul [esp+0x18]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F799D: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F799F: fld [esp+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x44u));
	// 0x1F79A3: fmul [esp+0x20]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0x20u));
	// 0x1F79A7: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F79A9: fstp [esi+0x20]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x20u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F79AC: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F79AF: ret
	return;
}

void sub_1F79B0(X86Context& ctx, uint8_t* base) {
	// 0x1F79B0: mov eax, [0x003C1260]
	ctx.eax = X86_MEM_READ_u32(base, 0x3C1260u);
	// 0x1F79B5: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F79B8: sub eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F79BB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F79BC: mov esi, [esp+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F79C0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F79C1: jz 0x001F7A5D
	if (ctx.flags.zf) goto loc_1F7A5D;
	// 0x1F79C7: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F79C8: jnz 0x001F7A68
	if (!ctx.flags.zf) goto loc_1F7A68;
	// 0x1F79CE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F79CF: mov ebp, [0x0041B550]
	ctx.ebp = X86_MEM_READ_u32(base, 0x41B550u);
	// 0x1F79D5: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F79D7: cmp ebp, 0x41B550
	{ uint32_t _d = ctx.ebp; uint32_t _s = 4306256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F79DD: mov dword ptr [esp+0x0C], 0x7F7FFFFF
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, 2139095039);
	// 0x1F79E5: jz 0x001F7A55
	if (ctx.flags.zf) goto loc_1F7A55;
	// 0x1F79E7: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_1F79E8:
	// 0x1F79E8: fld [ebp+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0x8u));
	// 0x1F79EB: lea ebx, [ebp-0x28]
	ctx.ebx = ctx.ebp - 0x28u;
	// 0x1F79EE: fsub [esi]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi));
	// 0x1F79F0: mov eax, [0x0041B560]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B560u);
	// 0x1F79F5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F79F7: fld [ebx+0x34]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x34u));
	// 0x1F79FA: fsub [esi+0x04]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x4u));
	// 0x1F79FD: fld [ebx+0x38]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebx + 0x38u));
	// 0x1F7A00: fsub [esi+0x08]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x8u));
	// 0x1F7A03: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x1F7A05: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7A07: fld st3
	X86_FPU_PUSH(ctx, ctx.fp_stack[3]);
	// 0x1F7A09: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F7A0B: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7A0D: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x1F7A0F: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7A11: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7A13: fst [esp+0x14]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x14u, ctx.fp_stack[ctx.fp_top]);
	// 0x1F7A17: fstp st3
	ctx.fp_stack[3] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7A19: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7A1B: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7A1D: jz 0x001F7A34
	if (ctx.flags.zf) goto loc_1F7A34;
	// 0x1F7A1F: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F7A23: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7A25: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A26: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A27: call [0x0041B560]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B560u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F7A2D: fadd [esp+0x1C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, ctx.esp + 0x1Cu));
	// 0x1F7A31: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F7A34:
	// 0x1F7A34: fcom [esp+0x10]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7A38: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7A3A: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7A3D: jp 0x001F7A47
	if (ctx.flags.pf) goto loc_1F7A47;
	// 0x1F7A3F: fstp [esp+0x10]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x10u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7A43: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x1F7A45: jmp 0x001F7A49
	goto loc_1F7A49;
loc_1F7A47:
	// 0x1F7A47: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_1F7A49:
	// 0x1F7A49: mov ebp, [ebp]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x1F7A4C: cmp ebp, 0x41B550
	{ uint32_t _d = ctx.ebp; uint32_t _s = 4306256;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F7A52: jnz 0x001F79E8
	if (!ctx.flags.zf) goto loc_1F79E8;
	// 0x1F7A54: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F7A55:
	// 0x1F7A55: call 0x001F7840
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F7840(ctx, base);
	ctx.esp += 4;
	// 0x1F7A5A: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7A5B: jmp 0x001F7A68
	goto loc_1F7A68;
loc_1F7A5D:
	// 0x1F7A5D: mov edi, [0x0041B55C]
	ctx.edi = X86_MEM_READ_u32(base, 0x41B55Cu);
	// 0x1F7A63: call 0x001F7840
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F7840(ctx, base);
	ctx.esp += 4;
loc_1F7A68:
	// 0x1F7A68: mov ecx, [esp+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1F7A6C: mov edx, [esp+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1F7A70: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F7A74: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A75: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F7A79: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A7A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A7B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A7C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A7D: call 0x001F7BC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F7BC0(ctx, base);
	ctx.esp += 4;
	// 0x1F7A82: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7A85: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7A86: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7A87: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7A8A: ret
	return;
}

void sub_1F7A90(X86Context& ctx, uint8_t* base) {
	// 0x1F7A90: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7A94: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F7A98: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7A9C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A9D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7A9E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AA0: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AA1: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AA3: push 0x41B570
	{ auto _pv = (uint32_t)(4306288); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AA8: call 0x001F6050
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F7AAD: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7AB0: ret
	return;
}

void sub_1F7AC0(X86Context& ctx, uint8_t* base) {
	// 0x1F7AC0: mov eax, [0x0041B5E4]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B5E4u);
	// 0x1F7AC5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7AC7: jz 0x001F7ADD
	if (ctx.flags.zf) goto loc_1F7ADD;
	// 0x1F7AC9: call 0x001FFFD0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FFFD0(ctx, base);
	ctx.esp += 4;
	// 0x1F7ACE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F7AD0: jnz 0x001F7AD3
	if (!ctx.flags.zf) goto loc_1F7AD3;
	// 0x1F7AD2: ret
	return;
loc_1F7AD3:
	// 0x1F7AD3: mov dword ptr [0x0041B5E4], 0x00
	X86_MEM_WRITE_u32(base, 0x41B5E4u, 0);
loc_1F7ADD:
	// 0x1F7ADD: push 0x41B570
	{ auto _pv = (uint32_t)(4306288); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AE2: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F7AE7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7AEA: ret
	return;
}

void sub_1F7AF0(X86Context& ctx, uint8_t* base) {
	// 0x1F7AF0: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7AF3: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F7AF7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AF8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7AF9: lea ecx, [eax+0x28]
	ctx.ecx = ctx.eax + 0x28u;
	// 0x1F7AFC: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x1F7AFE: mov dword ptr [esp+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, 0);
	// 0x1F7B06: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F7B0A: mov [edi], ecx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ecx);
	// 0x1F7B0C: mov dword ptr [esp+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, 0);
	// 0x1F7B14: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7B18: mov [edi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.edx);
	// 0x1F7B1B: mov dword ptr [esp+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, 0);
	// 0x1F7B23: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F7B27: mov [edi+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.esi);
	// 0x1F7B2A: lea edi, [eax+0x34]
	ctx.edi = ctx.eax + 0x34u;
	// 0x1F7B2D: mov [edi], ecx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ecx);
	// 0x1F7B2F: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F7B31: mov [edi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.edx);
	// 0x1F7B34: mov [edi+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.esi);
	// 0x1F7B37: mov [esp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.ecx);
	// 0x1F7B3B: mov edi, [esp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F7B3F: mov [esp+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.ecx);
	// 0x1F7B43: mov [eax+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4Cu, ctx.ecx);
	// 0x1F7B46: mov [eax+0x50], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x50u, ctx.ecx);
	// 0x1F7B49: lea ecx, [eax+0x40]
	ctx.ecx = ctx.eax + 0x40u;
	// 0x1F7B4C: mov edx, 0x3F800000
	ctx.edx = 1065353216;
	// 0x1F7B51: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x1F7B53: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F7B55: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x1F7B57: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F7B5A: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F7B5E: mov [esi+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edi);
	// 0x1F7B61: fld [eax+0x48]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F7B64: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7B6A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7B6B: fld [eax+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x44u));
	// 0x1F7B6E: mov [eax+0x54], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, ctx.edx);
	// 0x1F7B71: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x1F7B73: mov [esp+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.edx);
	// 0x1F7B77: mov [eax+0x68], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x68u, ctx.edx);
	// 0x1F7B7A: fstp [eax+0x58]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x58u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7B7D: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F7B7F: mov [eax+0x6C], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, ctx.edx);
	// 0x1F7B82: fsubr st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	// 0x1F7B84: mov dword ptr [eax+0x64], 0x41200000
	X86_MEM_WRITE_u32(base, ctx.eax + 0x64u, 1092616192);
	// 0x1F7B8B: mov dword ptr [eax+0x70], 0x7B
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, 123);
	// 0x1F7B92: fstp [eax+0x5C]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x5Cu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7B95: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7B96: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7B98: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F7B9A: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7BA0: fld [eax+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x44u));
	// 0x1F7BA3: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7BA9: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7BAB: fstp [eax+0x60]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x60u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7BAE: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7BB1: ret
	return;
}

void sub_1F7BC0(X86Context& ctx, uint8_t* base) {
	// 0x1F7BC0: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7BC3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7BC4: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7BC5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7BC6: mov esi, [esp+0x28]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1F7BCA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7BCB: mov edi, [esp+0x30]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1F7BCF: fld [edi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi));
	// 0x1F7BD1: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x1F7BD5: fsub [esi+0x28]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x28u));
	// 0x1F7BD8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7BD9: lea ecx, [esp+0x30]
	ctx.ecx = ctx.esp + 0x30u;
	// 0x1F7BDD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7BDE: fstp [esp+0x18]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x18u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7BE2: fld [edi+0x04]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x4u));
	// 0x1F7BE5: fsub [esi+0x2C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x2Cu));
	// 0x1F7BE8: fstp [esp+0x1C]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x1Cu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7BEC: fld [edi+0x08]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x8u));
	// 0x1F7BEF: fsub [esi+0x30]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x30u));
	// 0x1F7BF2: fstp [esp+0x20]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x20u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7BF6: call 0x001FFE00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FFE00(ctx, base);
	ctx.esp += 4;
	// 0x1F7BFB: mov bl, [esp+0x44]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.esp + 0x44u);
	// 0x1F7BFF: mov ebp, [esp+0x3C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1F7C03: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7C06: test bl, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 2, 8);
	// 0x1F7C09: jz 0x001F7CB6
	if (ctx.flags.zf) goto loc_1F7CB6;
	// 0x1F7C0F: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7C15: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7C19: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x1F7C1B: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7C1D: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x1F7C20: jnp 0x001F7CAF
	if (!ctx.flags.pf) goto loc_1F7CAF;
	// 0x1F7C26: lea edx, [esp+0x10]
	ctx.edx = ctx.esp + 0x10u;
	// 0x1F7C2A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7C2B: lea eax, [esp+0x20]
	ctx.eax = ctx.esp + 0x20u;
	// 0x1F7C2F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7C30: call 0x001DBA70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1DBA70(ctx, base);
	ctx.esp += 4;
	// 0x1F7C35: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7C37: fld [edi+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0xCu));
	// 0x1F7C3A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7C3D: fsub [esi+0x34]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x34u));
	// 0x1F7C40: fld [edi+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x10u));
	// 0x1F7C43: fsub [esi+0x38]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x38u));
	// 0x1F7C46: fld [edi+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x14u));
	// 0x1F7C49: fsub [esi+0x3C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.esi + 0x3Cu));
	// 0x1F7C4C: fld [esp+0x20]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x20u));
	// 0x1F7C50: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7C52: fld [esp+0x1C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x1Cu));
	// 0x1F7C56: fmul st0, st4
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[4]);
	// 0x1F7C58: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7C5A: fld [esp+0x24]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x24u));
	// 0x1F7C5E: fmul st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[2]);
	// 0x1F7C60: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7C62: fmul [esi+0x68]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x68u));
	// 0x1F7C65: fstp st3
	ctx.fp_stack[3] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7C67: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7C69: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7C6B: fcom [0x003B16D8]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16D8u));
	// 0x1F7C71: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7C73: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1F7C76: jnz 0x001F7C82
	if (!ctx.flags.zf) goto loc_1F7C82;
	// 0x1F7C78: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7C7A: fld [0x003B16D8]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16D8u));
	// 0x1F7C80: jmp 0x001F7C97
	goto loc_1F7C97;
loc_1F7C82:
	// 0x1F7C82: fcom [0x0036DBC4]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x36DBC4u));
	// 0x1F7C88: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7C8A: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7C8D: jp 0x001F7C97
	if (ctx.flags.pf) goto loc_1F7C97;
	// 0x1F7C8F: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7C91: fld [0x0036DBC4]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x36DBC4u));
loc_1F7C97:
	// 0x1F7C97: fld [esi+0x6C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esi + 0x6Cu));
	// 0x1F7C9A: fmul [0x0036DBC0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x36DBC0u));
	// 0x1F7CA0: fld st0
	X86_FPU_PUSH(ctx, ctx.fp_stack[0]);
	// 0x1F7CA2: fadd st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] + ctx.fp_stack[2]);
	// 0x1F7CA4: fdivr st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	// 0x1F7CA6: fstp [ebp+0x04]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x4u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7CA9: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7CAB: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7CAD: jmp 0x001F7CB6
	goto loc_1F7CB6;
loc_1F7CAF:
	// 0x1F7CAF: mov dword ptr [ebp+0x04], 0x3F800000
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x4u, 1065353216);
loc_1F7CB6:
	// 0x1F7CB6: test bl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 1, 8);
	// 0x1F7CB9: jz 0x001F7D3A
	if (ctx.flags.zf) goto loc_1F7D3A;
	// 0x1F7CBB: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7CBF: fcomp [edi+0x28]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.edi + 0x28u));
	X86_FPU_POP(ctx);
	// 0x1F7CC2: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7CC4: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1F7CC7: jnz 0x001F7CD2
	if (!ctx.flags.zf) goto loc_1F7CD2;
	// 0x1F7CC9: mov dword ptr [ebp], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp, 0);
	// 0x1F7CD0: jmp 0x001F7D3A
	goto loc_1F7D3A;
loc_1F7CD2:
	// 0x1F7CD2: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7CD6: fcomp [edi+0x24]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.edi + 0x24u));
	X86_FPU_POP(ctx);
	// 0x1F7CD9: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7CDB: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7CDE: jp 0x001F7CE9
	if (ctx.flags.pf) goto loc_1F7CE9;
	// 0x1F7CE0: mov dword ptr [ebp], 0x3F800000
	X86_MEM_WRITE_u32(base, ctx.ebp, 1065353216);
	// 0x1F7CE7: jmp 0x001F7D3A
	goto loc_1F7D3A;
loc_1F7CE9:
	// 0x1F7CE9: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7CED: fsub [edi+0x24]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x24u));
	// 0x1F7CF0: fstp [esp+0x2C]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x2Cu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7CF4: fld [edi+0x28]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi + 0x28u));
	// 0x1F7CF7: fsub [edi+0x24]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, ctx.edi + 0x24u));
	// 0x1F7CFA: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7CFE: fmul [esi+0x64]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x64u));
	// 0x1F7D01: fst [esp+0x30]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x30u, ctx.fp_stack[ctx.fp_top]);
	// 0x1F7D05: fcomp [0x003B1910]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F64(base, 0x3B1910u));
	X86_FPU_POP(ctx);
	// 0x1F7D0B: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7D0D: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7D10: jp 0x001F7D27
	if (ctx.flags.pf) goto loc_1F7D27;
	// 0x1F7D12: fcom [0x003B169C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B169Cu));
	// 0x1F7D18: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7D1A: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7D1D: jp 0x001F7D27
	if (ctx.flags.pf) goto loc_1F7D27;
	// 0x1F7D1F: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7D21: fld [0x003B169C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B169Cu));
loc_1F7D27:
	// 0x1F7D27: fld [esp+0x2C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x2Cu));
	// 0x1F7D2B: fsubr st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	// 0x1F7D2D: fld [esp+0x30]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x30u));
	// 0x1F7D31: fadd st0, st2
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] + ctx.fp_stack[2]);
	// 0x1F7D33: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7D35: fstp [ebp]
	X86_MEM_WRITE_F32(base, ctx.ebp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7D38: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_1F7D3A:
	// 0x1F7D3A: test bl, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 4, 8);
	// 0x1F7D3D: jz 0x001F7F58
	if (ctx.flags.zf) goto loc_1F7F58;
	// 0x1F7D43: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7D49: mov ecx, [esi+0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F7D4C: fld [esp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7D50: mov [esp+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.ecx);
	// 0x1F7D54: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x1F7D56: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7D58: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x1F7D5B: jp 0x001F7D9C
	if (ctx.flags.pf) goto loc_1F7D9C;
	// 0x1F7D5D: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7D63: fld [esp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x14u));
	// 0x1F7D67: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x1F7D69: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7D6B: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x1F7D6E: jp 0x001F7D9C
	if (ctx.flags.pf) goto loc_1F7D9C;
	// 0x1F7D70: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7D76: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7D7A: fucompp
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	X86_FPU_POP(ctx);
	// 0x1F7D7C: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7D7E: test ah, 0x44
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 68, 8);
	// 0x1F7D81: jp 0x001F7D9C
	if (ctx.flags.pf) goto loc_1F7D9C;
	// 0x1F7D83: lea edx, [esi+0x4C]
	ctx.edx = ctx.esi + 0x4Cu;
	// 0x1F7D86: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F7D88: mov ecx, [edx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F7D8B: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F7D8E: mov [esp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.eax);
	// 0x1F7D92: mov [esp+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.ecx);
	// 0x1F7D96: mov [esp+0x18], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.edx);
	// 0x1F7D9A: jmp 0x001F7DAE
	goto loc_1F7DAE;
loc_1F7D9C:
	// 0x1F7D9C: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x1F7DA0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7DA1: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F7DA3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7DA4: call 0x001DBA70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1DBA70(ctx, base);
	ctx.esp += 4;
	// 0x1F7DA9: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7DAB: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F7DAE:
	// 0x1F7DAE: fld [esp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x14u));
	// 0x1F7DB2: fmul [esi+0x5C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x5Cu));
	// 0x1F7DB5: fld [esp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7DB9: fmul [esi+0x58]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x58u));
	// 0x1F7DBC: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7DBE: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7DC2: fmul [esi+0x60]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x60u));
	// 0x1F7DC5: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7DC7: fmul [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x1F7DCD: fsubr [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x3B1684u) - ctx.fp_stack[ctx.fp_top]);
	// 0x1F7DD3: fcom [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7DD9: fst [ebp+0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0xCu, ctx.fp_stack[ctx.fp_top]);
	// 0x1F7DDC: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7DDE: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7DE1: jp 0x001F7DED
	if (ctx.flags.pf) goto loc_1F7DED;
	// 0x1F7DE3: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7DE5: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7DEB: jmp 0x001F7E02
	goto loc_1F7E02;
loc_1F7DED:
	// 0x1F7DED: fcom [0x003B168C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x1F7DF3: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7DF5: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1F7DF8: jnz 0x001F7E02
	if (!ctx.flags.zf) goto loc_1F7E02;
	// 0x1F7DFA: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7DFC: fld [0x003B168C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu));
loc_1F7E02:
	// 0x1F7E02: fstp [ebp+0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7E05: fld [esp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x14u));
	// 0x1F7E09: fmul [esi+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x50u));
	// 0x1F7E0C: fld [esp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7E10: fmul [esi+0x4C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x4Cu));
	// 0x1F7E13: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7E15: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7E19: fmul [esi+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x54u));
	// 0x1F7E1C: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7E1E: fmul [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x1F7E24: fsubr [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, (double)X86_MEM_READ_F32(base, 0x3B1684u) - ctx.fp_stack[ctx.fp_top]);
	// 0x1F7E2A: fcom [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7E30: fst [ebp+0x10]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x10u, ctx.fp_stack[ctx.fp_top]);
	// 0x1F7E33: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7E35: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7E38: jp 0x001F7E44
	if (ctx.flags.pf) goto loc_1F7E44;
	// 0x1F7E3A: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7E3C: fld [0x003B16E0]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7E42: jmp 0x001F7E59
	goto loc_1F7E59;
loc_1F7E44:
	// 0x1F7E44: fcom [0x003B168C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x1F7E4A: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7E4C: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1F7E4F: jnz 0x001F7E59
	if (!ctx.flags.zf) goto loc_1F7E59;
	// 0x1F7E51: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7E53: fld [0x003B168C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu));
loc_1F7E59:
	// 0x1F7E59: fstp [ebp+0x10]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x10u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7E5C: fld [esp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x14u));
	// 0x1F7E60: fmul [esi+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x50u));
	// 0x1F7E63: fld [esp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7E67: fmul [esi+0x4C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x4Cu));
	// 0x1F7E6A: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7E6C: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7E70: fmul [esi+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x54u));
	// 0x1F7E73: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7E75: fst [esp+0x30]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x30u, ctx.fp_stack[ctx.fp_top]);
	// 0x1F7E79: fcomp [0x003B168C]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	X86_FPU_POP(ctx);
	// 0x1F7E7F: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7E81: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1F7E84: jnz 0x001F7E90
	if (!ctx.flags.zf) goto loc_1F7E90;
	// 0x1F7E86: mov dword ptr [esp+0x30], 0x3F800000
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, 1065353216);
	// 0x1F7E8E: jmp 0x001F7EA9
	goto loc_1F7EA9;
loc_1F7E90:
	// 0x1F7E90: fld [esp+0x30]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x30u));
	// 0x1F7E94: fcomp [0x003B16C0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16C0u));
	X86_FPU_POP(ctx);
	// 0x1F7E9A: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7E9C: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1F7E9F: jp 0x001F7EA9
	if (ctx.flags.pf) goto loc_1F7EA9;
	// 0x1F7EA1: mov dword ptr [esp+0x30], 0xBF800000
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, -1082130432);
loc_1F7EA9:
	// 0x1F7EA9: mov edx, [esp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1F7EAD: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7EAE: call 0x00175A00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_175A00(ctx, base);
	ctx.esp += 4;
	// 0x1F7EB3: fst [ebp+0x08]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	// 0x1F7EB6: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7EBA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7EBD: fmul [esi+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x54u));
	// 0x1F7EC0: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7EC4: fmul [esi+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x50u));
	// 0x1F7EC7: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7EC9: fld [esp+0x18]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x18u));
	// 0x1F7ECD: fmul [esi+0x4C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x4Cu));
	// 0x1F7ED0: fld [esp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7ED4: fmul [esi+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x54u));
	// 0x1F7ED7: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7ED9: fld [esp+0x10]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x10u));
	// 0x1F7EDD: fmul [esi+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x50u));
	// 0x1F7EE0: fld [esp+0x14]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.esp + 0x14u));
	// 0x1F7EE4: fmul [esi+0x4C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x4Cu));
	// 0x1F7EE7: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7EE9: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x1F7EEB: fmul [esi+0x44]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x44u));
	// 0x1F7EEE: fxch st2
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[2]; ctx.fp_stack[2] = _tmp; }
	// 0x1F7EF0: fmul [esi+0x40]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x40u));
	// 0x1F7EF3: faddp st2, st0
	ctx.fp_stack[2] = X86_FPU_ROUND(ctx, ctx.fp_stack[2] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7EF5: fmul [esi+0x48]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x48u));
	// 0x1F7EF8: faddp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F7EFA: fcomp [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	X86_FPU_POP(ctx);
	// 0x1F7F00: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1F7F02: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1F7F05: jnz 0x001F7F12
	if (!ctx.flags.zf) goto loc_1F7F12;
	// 0x1F7F07: fld [0x003B1738]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B1738u));
	// 0x1F7F0D: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x1F7F0F: fstp [ebp+0x08]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_1F7F12:
	// 0x1F7F12: mov eax, [esp+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
	// 0x1F7F16: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1F7F18: sub eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7F1B: jz 0x001F7F40
	if (ctx.flags.zf) goto loc_1F7F40;
	// 0x1F7F1D: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F7F1E: jnz 0x001F7F58
	if (!ctx.flags.zf) goto loc_1F7F58;
	// 0x1F7F20: fld [ebp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x1F7F23: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F24: fsub [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x1F7F2A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F2B: fadd [0x003B168C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x1F7F31: fmul [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x1F7F37: fstp [ebp+0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F7F3A: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F3B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F3C: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7F3F: ret
	return;
loc_1F7F40:
	// 0x1F7F40: fld [ebp+0x0C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ebp + 0xCu));
	// 0x1F7F43: fsub [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] - (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x1F7F49: fmul [0x003B16E0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1F7F4F: fadd [0x003B1684]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B1684u));
	// 0x1F7F55: fstp [ebp+0x0C]
	X86_MEM_WRITE_F32(base, ctx.ebp + 0xCu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_1F7F58:
	// 0x1F7F58: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F59: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F5A: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F5B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F5C: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F7F5F: ret
	return;
}

void sub_1F7F60(X86Context& ctx, uint8_t* base) {
	// 0x1F7F60: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7F64: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7F68: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7F69: mov esi, [edx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F7F6B: lea ecx, [eax+0x28]
	ctx.ecx = ctx.eax + 0x28u;
	// 0x1F7F6E: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x1F7F70: mov esi, [edx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F7F73: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1F7F76: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F7F79: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F7F7C: or dword ptr [eax+0x70], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, X86_MEM_READ_u32(base, ctx.eax + 0x70u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x70u), 32);
	// 0x1F7F80: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7F81: ret
	return;
}

void sub_1F7F90(X86Context& ctx, uint8_t* base) {
	// 0x1F7F90: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7F94: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7F98: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7F99: lea ecx, [eax+0x28]
	ctx.ecx = ctx.eax + 0x28u;
	// 0x1F7F9C: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F7F9E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F7FA0: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F7FA3: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F7FA6: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F7FA9: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F7FAC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7FAD: ret
	return;
}

void sub_1F7FB0(X86Context& ctx, uint8_t* base) {
	// 0x1F7FB0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7FB4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7FB8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7FB9: mov esi, [edx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F7FBB: lea ecx, [eax+0x34]
	ctx.ecx = ctx.eax + 0x34u;
	// 0x1F7FBE: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x1F7FC0: mov esi, [edx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F7FC3: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1F7FC6: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F7FC9: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F7FCC: or dword ptr [eax+0x70], 0x02
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, X86_MEM_READ_u32(base, ctx.eax + 0x70u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x70u), 32);
	// 0x1F7FD0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7FD1: ret
	return;
}

void sub_1F7FE0(X86Context& ctx, uint8_t* base) {
	// 0x1F7FE0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F7FE4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F7FE8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F7FE9: lea ecx, [eax+0x34]
	ctx.ecx = ctx.eax + 0x34u;
	// 0x1F7FEC: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F7FEE: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F7FF0: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F7FF3: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F7FF6: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F7FF9: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F7FFC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F7FFD: ret
	return;
}

void sub_1F8000(X86Context& ctx, uint8_t* base) {
	// 0x1F8000: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8004: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8008: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8009: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F800A: lea edx, [ecx+0x10]
	ctx.edx = ctx.ecx + 0x10u;
	// 0x1F800D: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F800F: lea esi, [eax+0x40]
	ctx.esi = ctx.eax + 0x40u;
	// 0x1F8012: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F8014: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F8017: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F801A: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F801D: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F8020: lea edx, [ecx+0x20]
	ctx.edx = ctx.ecx + 0x20u;
	// 0x1F8023: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F8025: lea esi, [eax+0x4C]
	ctx.esi = ctx.eax + 0x4Cu;
	// 0x1F8028: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F802A: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F802D: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F8030: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F8033: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F8036: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F8038: lea edx, [eax+0x58]
	ctx.edx = ctx.eax + 0x58u;
	// 0x1F803B: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F803D: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F8040: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F8043: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F8046: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F8049: mov ecx, [eax+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x70u);
	// 0x1F804C: or ecx, 0x0C
	ctx.ecx = ctx.ecx | 12;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F804F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8050: mov [eax+0x70], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, ctx.ecx);
	// 0x1F8053: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8054: ret
	return;
}

void sub_1F8060(X86Context& ctx, uint8_t* base) {
	// 0x1F8060: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8064: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8068: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8069: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F806A: lea edx, [eax+0x40]
	ctx.edx = ctx.eax + 0x40u;
	// 0x1F806D: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F806F: lea esi, [ecx+0x10]
	ctx.esi = ctx.ecx + 0x10u;
	// 0x1F8072: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F8074: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F8077: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F807A: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F807D: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F8080: lea edx, [eax+0x4C]
	ctx.edx = ctx.eax + 0x4Cu;
	// 0x1F8083: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F8085: lea esi, [ecx+0x20]
	ctx.esi = ctx.ecx + 0x20u;
	// 0x1F8088: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F808A: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F808D: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F8090: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F8093: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F8096: lea edx, [eax+0x58]
	ctx.edx = ctx.eax + 0x58u;
	// 0x1F8099: mov esi, [edx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F809B: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x1F809D: mov esi, [edx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F80A0: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1F80A3: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F80A6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F80A7: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F80AA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F80AB: ret
	return;
}

void sub_1F80B0(X86Context& ctx, uint8_t* base) {
	// 0x1F80B0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F80B4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F80B8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F80B9: lea ecx, [eax+0x40]
	ctx.ecx = ctx.eax + 0x40u;
	// 0x1F80BC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F80BD: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F80BF: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x1F80C1: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F80C3: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F80C6: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F80C9: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F80CC: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F80CF: fld [eax+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x44u));
	// 0x1F80D2: fmul [eax+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x54u));
	// 0x1F80D5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F80D6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F80D7: fld [eax+0x48]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F80DA: fmul [eax+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F80DD: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F80DF: fstp [eax+0x58]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x58u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F80E2: fld [eax+0x4C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F80E5: fmul [eax+0x48]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F80E8: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F80EA: fmul [eax+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x54u));
	// 0x1F80ED: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F80EF: fstp [eax+0x5C]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x5Cu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F80F2: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F80F4: mov ecx, [eax+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x70u);
	// 0x1F80F7: fmul [eax+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F80FA: or ecx, 0x08
	ctx.ecx = ctx.ecx | 8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F80FD: mov [eax+0x70], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, ctx.ecx);
	// 0x1F8100: fld [eax+0x4C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x4Cu));
	// 0x1F8103: fmul [eax+0x44]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x44u));
	// 0x1F8106: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F8108: fstp [eax+0x60]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x60u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F810B: ret
	return;
}

void sub_1F8110(X86Context& ctx, uint8_t* base) {
	// 0x1F8110: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8114: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8118: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8119: lea ecx, [eax+0x40]
	ctx.ecx = ctx.eax + 0x40u;
	// 0x1F811C: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F811E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F8120: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F8123: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F8126: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F8129: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F812C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F812D: ret
	return;
}

void sub_1F8130(X86Context& ctx, uint8_t* base) {
	// 0x1F8130: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8134: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8138: fld [eax+0x44]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x44u));
	// 0x1F813B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F813C: lea ecx, [eax+0x4C]
	ctx.ecx = ctx.eax + 0x4Cu;
	// 0x1F813F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8140: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F8142: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x1F8144: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F8146: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F8149: mov [esi+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edi);
	// 0x1F814C: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F814F: mov [esi+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edx);
	// 0x1F8152: fmul [eax+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x54u));
	// 0x1F8155: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8156: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8157: fld [eax+0x48]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F815A: fmul [eax+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F815D: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F815F: fstp [eax+0x58]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x58u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F8162: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F8164: fmul [eax+0x48]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x48u));
	// 0x1F8167: fld [eax+0x40]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x40u));
	// 0x1F816A: fmul [eax+0x54]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x54u));
	// 0x1F816D: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F816F: fstp [eax+0x5C]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x5Cu, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F8172: fld [eax+0x40]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax + 0x40u));
	// 0x1F8175: fmul [eax+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x50u));
	// 0x1F8178: fld [ecx]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.ecx));
	// 0x1F817A: fmul [eax+0x44]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.eax + 0x44u));
	// 0x1F817D: mov ecx, [eax+0x70]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x70u);
	// 0x1F8180: or ecx, 0x04
	ctx.ecx = ctx.ecx | 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F8183: fsubp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] - ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F8185: mov [eax+0x70], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, ctx.ecx);
	// 0x1F8188: fstp [eax+0x60]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x60u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1F818B: ret
	return;
}

void sub_1F8190(X86Context& ctx, uint8_t* base) {
	// 0x1F8190: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8194: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8198: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8199: lea ecx, [eax+0x4C]
	ctx.ecx = ctx.eax + 0x4Cu;
	// 0x1F819C: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F819E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F81A0: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F81A3: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F81A6: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F81A9: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F81AC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F81AD: ret
	return;
}

void sub_1F81B0(X86Context& ctx, uint8_t* base) {
	// 0x1F81B0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F81B4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F81B8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F81B9: lea ecx, [eax+0x58]
	ctx.ecx = ctx.eax + 0x58u;
	// 0x1F81BC: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F81BE: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1F81C0: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1F81C3: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1F81C6: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1F81C9: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F81CC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F81CD: ret
	return;
}

void sub_1F81D0(X86Context& ctx, uint8_t* base) {
	// 0x1F81D0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F81D4: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F81D6: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F81DA: mov [eax+0x68], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x68u, ctx.ecx);
	// 0x1F81DD: or dword ptr [eax+0x70], 0x20
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, X86_MEM_READ_u32(base, ctx.eax + 0x70u) | 32);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x70u), 32);
	// 0x1F81E1: ret
	return;
}

void sub_1F81F0(X86Context& ctx, uint8_t* base) {
	// 0x1F81F0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F81F4: mov ecx, [eax+0x68]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x68u);
	// 0x1F81F7: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F81FB: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F81FD: ret
	return;
}

void sub_1F8200(X86Context& ctx, uint8_t* base) {
	// 0x1F8200: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8204: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F8206: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F820A: mov [eax+0x6C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x6Cu, ctx.ecx);
	// 0x1F820D: or dword ptr [eax+0x70], 0x40
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, X86_MEM_READ_u32(base, ctx.eax + 0x70u) | 64);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x70u), 32);
	// 0x1F8211: ret
	return;
}

void sub_1F8220(X86Context& ctx, uint8_t* base) {
	// 0x1F8220: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8224: mov ecx, [eax+0x6C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x6Cu);
	// 0x1F8227: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F822B: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F822D: ret
	return;
}

void sub_1F8230(X86Context& ctx, uint8_t* base) {
	// 0x1F8230: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8234: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F8236: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F823A: mov [eax+0x64], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x64u, ctx.ecx);
	// 0x1F823D: or dword ptr [eax+0x70], 0x10
	X86_MEM_WRITE_u32(base, ctx.eax + 0x70u, X86_MEM_READ_u32(base, ctx.eax + 0x70u) | 16);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x70u), 32);
	// 0x1F8241: ret
	return;
}

void sub_1F8250(X86Context& ctx, uint8_t* base) {
	// 0x1F8250: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8254: mov ecx, [eax+0x64]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x64u);
	// 0x1F8257: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F825B: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F825D: ret
	return;
}

void sub_1F8260(X86Context& ctx, uint8_t* base) {
	// 0x1F8260: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8261: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8263: push 0x36DBAC
	{ auto _pv = (uint32_t)(3595180); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8268: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8269: call 0x001F8550
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1F826E: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8270: mov dword ptr [esi+0x40], 0x4C
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, 76);
	// 0x1F8277: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F827C: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8281: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8284: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F8286: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F8288: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F828B: jz 0x001F82A5
	if (ctx.flags.zf) goto loc_1F82A5;
	// 0x1F828D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F828F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F8294: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8299: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F829C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F829E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F82A0: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F82A3: jmp 0x001F82AA
	goto loc_1F82AA;
loc_1F82A5:
	// 0x1F82A5: mov eax, 0x01
	ctx.eax = 1;
loc_1F82AA:
	// 0x1F82AA: test eax, 0xFFFF0000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & -65536, 32);
	// 0x1F82AF: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F82B1: jz 0x001F83AD
	if (ctx.flags.zf) goto loc_1F83AD;
	// 0x1F82B7: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F82BC: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F82C1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F82C4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F82C6: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F82C8: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F82CB: jz 0x001F82E8
	if (ctx.flags.zf) goto loc_1F82E8;
	// 0x1F82CD: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F82CF: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F82D4: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F82D9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F82DC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F82DE: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F82E0: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F82E3: mov [esp], eax
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.eax);
	// 0x1F82E6: jmp 0x001F82EF
	goto loc_1F82EF;
loc_1F82E8:
	// 0x1F82E8: mov dword ptr [esp], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp, 1);
loc_1F82EF:
	// 0x1F82EF: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F82F1: mov ch, [esp+0x03]
	X86_REG8H(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esp + 0x3u);
	// 0x1F82F5: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F82F7: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F82F9: jz 0x001F8356
	if (ctx.flags.zf) goto loc_1F8356;
	// 0x1F82FB: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F8300: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8305: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8308: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F830A: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F830C: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F830F: jz 0x001F833C
	if (ctx.flags.zf) goto loc_1F833C;
	// 0x1F8311: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8313: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F8318: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F831D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8320: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F8322: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F8324: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F8327: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F832A: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F8331: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8334: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8337: jmp 0x001F8471
	goto loc_1F8471;
loc_1F833C:
	// 0x1F833C: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F8341: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F8344: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F834B: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F834E: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8351: jmp 0x001F8471
	goto loc_1F8471;
loc_1F8356:
	// 0x1F8356: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F835B: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8360: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8363: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F8365: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F8367: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F836A: jz 0x001F8395
	if (ctx.flags.zf) goto loc_1F8395;
	// 0x1F836C: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F836E: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F8373: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8378: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F837B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F837D: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F837F: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F8382: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F8385: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F838C: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F838D: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8390: jmp 0x001F8471
	goto loc_1F8471;
loc_1F8395:
	// 0x1F8395: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F839A: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F839D: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F83A4: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F83A5: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F83A8: jmp 0x001F8471
	goto loc_1F8471;
loc_1F83AD:
	// 0x1F83AD: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F83B2: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F83B7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F83BA: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F83BC: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F83BE: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F83C1: jz 0x001F83DB
	if (ctx.flags.zf) goto loc_1F83DB;
	// 0x1F83C3: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F83C5: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F83CA: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F83CF: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F83D2: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F83D4: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F83D6: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F83D9: jmp 0x001F83E0
	goto loc_1F83E0;
loc_1F83DB:
	// 0x1F83DB: mov eax, 0x01
	ctx.eax = 1;
loc_1F83E0:
	// 0x1F83E0: test ah, 0xFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & -1, 8);
	// 0x1F83E3: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F83E5: jz 0x001F8436
	if (ctx.flags.zf) goto loc_1F8436;
	// 0x1F83E7: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F83EC: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F83F1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F83F4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F83F6: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F83F8: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F83FB: jz 0x001F8422
	if (ctx.flags.zf) goto loc_1F8422;
	// 0x1F83FD: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F83FF: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F8404: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8409: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F840C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F840E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F8410: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F8413: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F8416: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F841D: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8420: jmp 0x001F8471
	goto loc_1F8471;
loc_1F8422:
	// 0x1F8422: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F8427: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F842A: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F8431: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8434: jmp 0x001F8471
	goto loc_1F8471;
loc_1F8436:
	// 0x1F8436: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F843B: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8440: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8443: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F8445: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F8447: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F844A: jz 0x001F8464
	if (ctx.flags.zf) goto loc_1F8464;
	// 0x1F844C: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F844E: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F8453: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F8458: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F845B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F845D: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F845F: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F8462: jmp 0x001F8469
	goto loc_1F8469;
loc_1F8464:
	// 0x1F8464: mov eax, 0x01
	ctx.eax = 1;
loc_1F8469:
	// 0x1F8469: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F8470: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_1F8471:
	// 0x1F8471: mov ecx, [esi+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1F8474: shl eax, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F8477: or ecx, eax
	ctx.ecx = ctx.ecx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F8479: mov [esi+0x40], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.ecx);
	// 0x1F847C: mov dword ptr [esi+0x28], 0x1F7AF0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 2063088);
	// 0x1F8483: mov word ptr [esi+0x44], 0x00
	X86_MEM_WRITE_u16(base, ctx.esi + 0x44u, 0);
	// 0x1F8489: mov word ptr [esi+0x46], 0x01
	X86_MEM_WRITE_u16(base, ctx.esi + 0x46u, 1);
	// 0x1F848F: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8490: ret
	return;
}

void sub_1F84A0(X86Context& ctx, uint8_t* base) {
	// 0x1F84A0: mov eax, [0x00764134]
	ctx.eax = X86_MEM_READ_u32(base, 0x764134u);
	// 0x1F84A5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84A6: push 0x3080C
	{ auto _pv = (uint32_t)(198668); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84AB: push 0x41B568
	{ auto _pv = (uint32_t)(4306280); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84B0: push 0x41B5CC
	{ auto _pv = (uint32_t)(4306380); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84B5: push 0x41B570
	{ auto _pv = (uint32_t)(4306288); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84BA: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84BC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84BD: call 0x001F8E20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F84C2: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F84C4: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F84C7: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F84C9: jz 0x001F84FD
	if (ctx.flags.zf) goto loc_1F84FD;
	// 0x1F84CB: call 0x001F8260
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8260(ctx, base);
	ctx.esp += 4;
	// 0x1F84D0: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84D2: push 0x3C1328
	{ auto _pv = (uint32_t)(3937064); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84D7: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84D9: push 0x3C1268
	{ auto _pv = (uint32_t)(3936872); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84DE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84DF: call 0x001F8B70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8B70(ctx, base);
	ctx.esp += 4;
	// 0x1F84E4: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F84E7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F84E9: jz 0x001F84F4
	if (ctx.flags.zf) goto loc_1F84F4;
	// 0x1F84EB: call 0x001FFF80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FFF80(ctx, base);
	ctx.esp += 4;
	// 0x1F84F0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F84F2: jnz 0x001F8501
	if (!ctx.flags.zf) goto loc_1F8501;
loc_1F84F4:
	// 0x1F84F4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F84F5: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F84FA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F84FD:
	// 0x1F84FD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F84FF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8500: ret
	return;
loc_1F8501:
	// 0x1F8501: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8502: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8503: call 0x001F8520
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8520(ctx, base);
	ctx.esp += 4;
	// 0x1F8508: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F850B: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F850D: mov dword ptr [0x0041B5E4], 0x01
	X86_MEM_WRITE_u32(base, 0x41B5E4u, 1);
	// 0x1F8517: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8518: ret
	return;
}

void sub_1F8520(X86Context& ctx, uint8_t* base) {
	// 0x1F8520: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8521: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8525: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8526: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F852A: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F852C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F852D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F852E: call 0x001FD370
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD370(ctx, base);
	ctx.esp += 4;
	// 0x1F8533: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8536: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8538: jnz 0x001F853D
	if (!ctx.flags.zf) goto loc_1F853D;
	// 0x1F853A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F853B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F853C: ret
	return;
loc_1F853D:
	// 0x1F853D: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8540: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1F8542: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8543: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8545: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8546: ret
	return;
}

void RwaObjDefAssignID(X86Context& ctx, uint8_t* base) {
	// 0x1F8550: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8554: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8555: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8559: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F855A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F855B: call 0x001FE480
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDAssignName(ctx, base);
	ctx.esp += 4;
	// 0x1F8560: mov ecx, [esp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8564: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8565: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8566: call 0x001FE4C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDAssignUUID(ctx, base);
	ctx.esp += 4;
	// 0x1F856B: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F856E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8570: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8571: ret
	return;
}

void sub_1F8580(X86Context& ctx, uint8_t* base) {
	// 0x1F8580: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8581: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8585: mov eax, [esi+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x3Cu);
	// 0x1F8588: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F858A: jz 0x001F859C
	if (ctx.flags.zf) goto loc_1F859C;
	// 0x1F858C: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8590: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8591: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8593: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x1F8595: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8598: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F859A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F859B: ret
	return;
loc_1F859C:
	// 0x1F859C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F859E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F859F: ret
	return;
}

void sub_1F85A0(X86Context& ctx, uint8_t* base) {
	// 0x1F85A0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85A1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F85A5: mov eax, [esi+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1F85A8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F85AA: jz 0x001F85B0
	if (ctx.flags.zf) goto loc_1F85B0;
	// 0x1F85AC: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F85AE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F85AF: ret
	return;
loc_1F85B0:
	// 0x1F85B0: mov ax, [esi+0x46]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.esi + 0x46u);
	// 0x1F85B4: cmp ax, 0x01
	{ uint16_t _d = X86_REG16(ctx.eax); uint16_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x1F85B8: jbe 0x001F8628
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F8628;
	// 0x1F85BA: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F85BE: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F85C0: mov ecx, [esi+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1F85C3: movzx eax, ax
	ctx.eax = (uint32_t)(X86_REG16(ctx.eax));
	// 0x1F85C6: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F85CB: jz 0x001F85FB
	if (ctx.flags.zf) goto loc_1F85FB;
	// 0x1F85CD: push 0x3080A
	{ auto _pv = (uint32_t)(198666); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85D2: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85D4: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85D5: shr ecx, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1F85D8: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F85DA: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F85DE: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85DF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85E0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F85E1: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F85E6: mov [esi+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.eax);
	// 0x1F85E9: or dword ptr [esi+0x0C], 0x40
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 64);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x1F85ED: mov eax, [esi+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1F85F0: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F85F3: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F85F5: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F85F7: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F85F9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F85FA: ret
	return;
loc_1F85FB:
	// 0x1F85FB: shr ecx, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1F85FE: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8600: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F8602: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8606: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8608: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8609: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F860A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F860B: call 0x001FE820
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE820(ctx, base);
	ctx.esp += 4;
	// 0x1F8610: mov [esi+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.eax);
	// 0x1F8613: or dword ptr [esi+0x0C], 0x80
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 128);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x1F861A: mov eax, [esi+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1F861D: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8620: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F8622: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8624: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F8626: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8627: ret
	return;
loc_1F8628:
	// 0x1F8628: mov dword ptr [esi+0x48], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, 1);
	// 0x1F862F: mov eax, [esi+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1F8632: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F8634: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8636: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F8638: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8639: ret
	return;
}

void sub_1F8640(X86Context& ctx, uint8_t* base) {
	// 0x1F8640: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8644: mov ecx, [eax+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F8647: test cl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 64, 8);
	// 0x1F864A: jz 0x001F865F
	if (ctx.flags.zf) goto loc_1F865F;
	// 0x1F864C: mov ecx, [eax+0x58]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x58u);
	// 0x1F864F: mov [esp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.ecx);
	// 0x1F8653: mov edx, [eax+0x48]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x1F8656: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1F865A: jmp 0x001FE900
	RwaFreeListAlloc(ctx, base);
	return;
loc_1F865F:
	// 0x1F865F: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x1F8661: jns 0x001F866F
	if (!ctx.flags.sf) goto loc_1F866F;
	// 0x1F8663: mov edx, [eax+0x48]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x48u);
	// 0x1F8666: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1F866A: jmp 0x001FE710
	sub_1FE710(ctx, base);
	return;
loc_1F866F:
	// 0x1F866F: mov eax, [eax+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x58u);
	// 0x1F8672: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8676: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8677: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8678: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1F867D: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8680: ret
	return;
}

void rwaObjDefFreeObj(X86Context& ctx, uint8_t* base) {
	// 0x1F8690: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8691: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8695: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F8698: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x1F869A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F869B: mov edi, [esi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F869D: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x1F869F: jz 0x001F86A6
	if (ctx.flags.zf) goto loc_1F86A6;
	// 0x1F86A1: mov ecx, [esi-0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi - 0x4u);
	// 0x1F86A4: jmp 0x001F86BF
	goto loc_1F86BF;
loc_1F86A6:
	// 0x1F86A6: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x1F86A8: jz 0x001F86BF
	if (ctx.flags.zf) goto loc_1F86BF;
	// 0x1F86AA: lea ecx, [esp+0x0C]
	ctx.ecx = ctx.esp + 0xCu;
	// 0x1F86AE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F86AF: and eax, 0x07
	ctx.eax = ctx.eax & 7;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F86B2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F86B3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F86B4: call 0x001F5E40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaObjCalcSize(ctx, base);
	ctx.esp += 4;
	// 0x1F86B9: mov ecx, [eax+esi*1]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + ctx.esi);
	// 0x1F86BC: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F86BF:
	// 0x1F86BF: mov eax, [edi+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x48u);
	// 0x1F86C2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F86C4: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F86C8: jz 0x001F8704
	if (ctx.flags.zf) goto loc_1F8704;
	// 0x1F86CA: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1F86CC: jz 0x001F86D4
	if (ctx.flags.zf) goto loc_1F86D4;
	// 0x1F86CE: test byte ptr [esi+0x1C], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x1Cu) & 32, 8);
	// 0x1F86D2: jnz 0x001F8704
	if (!ctx.flags.zf) goto loc_1F8704;
loc_1F86D4:
	// 0x1F86D4: mov edx, [edi+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x1F86D7: test dl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & 64, 8);
	// 0x1F86DA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F86DB: jz 0x001F86E9
	if (ctx.flags.zf) goto loc_1F86E9;
	// 0x1F86DD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F86DE: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1F86E3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F86E6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F86E7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F86E8: ret
	return;
loc_1F86E9:
	// 0x1F86E9: test dl, dl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.edx), 8);
	// 0x1F86EB: jns 0x001F86F9
	if (!ctx.flags.sf) goto loc_1F86F9;
	// 0x1F86ED: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F86EE: call 0x001FE770
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaFree(ctx, base);
	ctx.esp += 4;
	// 0x1F86F3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F86F6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F86F7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F86F8: ret
	return;
loc_1F86F9:
	// 0x1F86F9: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1F86FE: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8701: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8702: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8703: ret
	return;
loc_1F8704:
	// 0x1F8704: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1F8706: jz 0x001F8713
	if (ctx.flags.zf) goto loc_1F8713;
	// 0x1F8708: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F870C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F870D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F870E: call edx
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.edx);
	ctx.esp += 4;
	// 0x1F8710: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F8713:
	// 0x1F8713: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8714: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8715: ret
	return;
}

void rwaObjDefCreateSupported(X86Context& ctx, uint8_t* base) {
	// 0x1F8720: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F8724: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1F8727: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8728: lea esi, [eax+0x10]
	ctx.esi = ctx.eax + 0x10u;
	// 0x1F872B: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F872D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F872E: jz 0x001F8741
	if (ctx.flags.zf) goto loc_1F8741;
	// 0x1F8730: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
loc_1F8734:
	// 0x1F8734: lea edx, [ecx-0x18]
	ctx.edx = ctx.ecx - 0x18u;
	// 0x1F8737: cmp edx, edi
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8739: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F873B: jz 0x001F8743
	if (ctx.flags.zf) goto loc_1F8743;
	// 0x1F873D: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F873F: jnz 0x001F8734
	if (!ctx.flags.zf) goto loc_1F8734;
loc_1F8741:
	// 0x1F8741: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_1F8743:
	// 0x1F8743: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8744: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8745: ret
	return;
}

void sub_1F8750(X86Context& ctx, uint8_t* base) {
loc_1F8750:
	// 0x1F8750: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8751: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8752: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8753: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8757: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F8759: jnz 0x001F8761
	if (!ctx.flags.zf) goto loc_1F8761;
	// 0x1F875B: mov esi, [0x00764134]
	ctx.esi = X86_MEM_READ_u32(base, 0x764134u);
loc_1F8761:
	// 0x1F8761: cmp dword ptr [esp+0x20], 0x01
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x20u); uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8766: mov ebx, [esp+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1F876A: mov ebp, [esp+0x18]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F876E: mov [esp+0x10], esi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.esi);
	// 0x1F8772: jnz 0x001F8791
	if (!ctx.flags.zf) goto loc_1F8791;
	// 0x1F8774: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8775: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8776: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8777: call ebp
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.ebp);
	ctx.esp += 4;
	// 0x1F8779: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F877C: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F877F: jnz 0x001F8791
	if (!ctx.flags.zf) goto loc_1F8791;
	// 0x1F8781: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8785: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8787: jz 0x001F878B
	if (ctx.flags.zf) goto loc_1F878B;
	// 0x1F8789: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
loc_1F878B:
	// 0x1F878B: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F878D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F878E: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F878F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8790: ret
	return;
loc_1F8791:
	// 0x1F8791: lea eax, [esi+0x10]
	ctx.eax = ctx.esi + 0x10u;
	// 0x1F8794: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8795: mov edi, [eax]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F8797: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8799: mov [esp+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.eax);
	// 0x1F879D: jz 0x001F87D2
	if (ctx.flags.zf) goto loc_1F87D2;
	// 0x1F879F: nop
loc_1F87A0:
	// 0x1F87A0: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F87A4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87A5: lea esi, [edi-0x18]
	ctx.esi = ctx.edi - 0x18u;
	// 0x1F87A8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87A9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87AA: call ebp
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.ebp);
	ctx.esp += 4;
	// 0x1F87AC: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F87AF: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F87B2: jz 0x001F87E7
	if (ctx.flags.zf) goto loc_1F87E7;
	// 0x1F87B4: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F87B8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87BA: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87BB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87BC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87BD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F87BE: call 0x001F8750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8750(ctx, base);
	ctx.esp += 4;
	// 0x1F87C3: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F87C6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F87C8: jnz 0x001F87E2
	if (!ctx.flags.zf) goto loc_1F87E2;
	// 0x1F87CA: mov edi, [edi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F87CC: cmp edi, [esp+0x24]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F87D0: jnz 0x001F87A0
	if (!ctx.flags.zf) goto loc_1F87A0;
loc_1F87D2:
	// 0x1F87D2: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F87D6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F87D8: jz 0x001F87E0
	if (ctx.flags.zf) goto loc_1F87E0;
	// 0x1F87DA: mov dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, 0);
loc_1F87E0:
	// 0x1F87E0: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_1F87E2:
	// 0x1F87E2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87E3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87E4: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87E5: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87E6: ret
	return;
loc_1F87E7:
	// 0x1F87E7: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F87EB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F87ED: jz 0x001F87F5
	if (ctx.flags.zf) goto loc_1F87F5;
	// 0x1F87EF: mov edx, [esp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F87F3: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
loc_1F87F5:
	// 0x1F87F5: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87F6: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F87F8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87F9: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87FA: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F87FB: ret
	return;
}

void sub_1F8800(X86Context& ctx, uint8_t* base) {
	// 0x1F8800: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8801: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8805: test byte ptr [edi+0x0C], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.edi + 0xCu) & 4, 8);
	// 0x1F8809: jz 0x001F884E
	if (ctx.flags.zf) goto loc_1F884E;
	// 0x1F880B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F880C: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8810: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F8813: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8815: jz 0x001F884D
	if (ctx.flags.zf) goto loc_1F884D;
	// 0x1F8817: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F8819: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F881B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F881C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F881D: call 0x001FD370
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD370(ctx, base);
	ctx.esp += 4;
	// 0x1F8822: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8825: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8827: jz 0x001F884D
	if (ctx.flags.zf) goto loc_1F884D;
	// 0x1F8829: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F882C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F882D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F882E: call 0x001FE0E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE0E0(ctx, base);
	ctx.esp += 4;
	// 0x1F8833: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8836: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8838: jnz 0x001F884D
	if (!ctx.flags.zf) goto loc_1F884D;
	// 0x1F883A: mov edx, [esi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F883D: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F883E: call 0x001FE170
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE170(ctx, base);
	ctx.esp += 4;
	// 0x1F8843: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8846: mov dword ptr [esi+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 0);
loc_1F884D:
	// 0x1F884D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F884E:
	// 0x1F884E: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8850: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8851: ret
	return;
}

void sub_1F8860(X86Context& ctx, uint8_t* base) {
	// 0x1F8860: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8864: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8868: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F886A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F886B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F886C: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F8871: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8874: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F8876: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8878: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8879: ret
	return;
}

void RwaObjDefParamsFree(X86Context& ctx, uint8_t* base) {
	// 0x1F8880: test byte ptr [ebx+0x0C], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx + 0xCu) & 4, 8);
	// 0x1F8884: jz 0x001F890A
	if (ctx.flags.zf) goto loc_1F890A;
	// 0x1F888A: mov eax, [ebx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4Cu);
	// 0x1F888D: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1F8890: mov ax, [eax+0x0C]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.eax + 0xCu);
	// 0x1F8894: test ax, ax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & X86_REG16(ctx.eax), 16);
	// 0x1F8897: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8898: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8899: jbe 0x001F88B5
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F88B5;
	// 0x1F889B: movzx eax, ax
	ctx.eax = (uint32_t)(X86_REG16(ctx.eax));
	// 0x1F889E: lea edx, [eax+eax*2]
	ctx.edx = ctx.eax + ctx.eax * 2;
	// 0x1F88A1: lea esi, [ecx+edx*8]
	ctx.esi = ctx.ecx + ctx.edx * 8;
	// 0x1F88A4: mov edi, eax
	ctx.edi = ctx.eax;
loc_1F88A6:
	// 0x1F88A6: sub esi, 0x18
	{ uint32_t _d = ctx.esi; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1F88A9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F88AA: call 0x001FE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDFreeData(ctx, base);
	ctx.esp += 4;
	// 0x1F88AF: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F88B2: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1F88B3: jnz 0x001F88A6
	if (!ctx.flags.zf) goto loc_1F88A6;
loc_1F88B5:
	// 0x1F88B5: mov eax, [ebx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4Cu);
	// 0x1F88B8: mov ecx, [eax+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x1F88BB: mov ax, [eax+0x0E]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.eax + 0xEu);
	// 0x1F88BF: test ax, ax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & X86_REG16(ctx.eax), 16);
	// 0x1F88C2: jbe 0x001F88DF
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F88DF;
	// 0x1F88C4: movzx eax, ax
	ctx.eax = (uint32_t)(X86_REG16(ctx.eax));
	// 0x1F88C7: lea edx, [eax+eax*2]
	ctx.edx = ctx.eax + ctx.eax * 2;
	// 0x1F88CA: lea esi, [ecx+edx*8]
	ctx.esi = ctx.ecx + ctx.edx * 8;
	// 0x1F88CD: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F88CF: nop
loc_1F88D0:
	// 0x1F88D0: sub esi, 0x18
	{ uint32_t _d = ctx.esi; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1F88D3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F88D4: call 0x001FE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDFreeData(ctx, base);
	ctx.esp += 4;
	// 0x1F88D9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F88DC: dec edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1F88DD: jnz 0x001F88D0
	if (!ctx.flags.zf) goto loc_1F88D0;
loc_1F88DF:
	// 0x1F88DF: test byte ptr [ebx+0x0C], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx + 0xCu) & 1, 8);
	// 0x1F88E3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F88E4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F88E5: jnz 0x001F88F6
	if (!ctx.flags.zf) goto loc_1F88F6;
	// 0x1F88E7: mov eax, [ebx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4Cu);
	// 0x1F88EA: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1F88ED: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F88EE: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1F88F3: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F88F6:
	// 0x1F88F6: mov edx, [ebx+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x4Cu);
	// 0x1F88F9: mov dword ptr [edx+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.edx + 0x10u, 0);
	// 0x1F8900: mov eax, [ebx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4Cu);
	// 0x1F8903: mov dword ptr [eax+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, 0);
loc_1F890A:
	// 0x1F890A: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1F890C: ret
	return;
}

void sub_1F8910(X86Context& ctx, uint8_t* base) {
	// 0x1F8910: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8911: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x1F8913: call 0x001F8880
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefParamsFree(ctx, base);
	ctx.esp += 4;
	// 0x1F8918: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8919: call 0x001FE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDFreeData(ctx, base);
	ctx.esp += 4;
	// 0x1F891E: mov eax, [ebx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0xCu);
	// 0x1F8921: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8924: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x1F8926: jz 0x001F893D
	if (ctx.flags.zf) goto loc_1F893D;
	// 0x1F8928: test al, 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 32, 8);
	// 0x1F892A: jnz 0x001F893D
	if (!ctx.flags.zf) goto loc_1F893D;
	// 0x1F892C: mov eax, [ebx+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x50u);
	// 0x1F892F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8930: push 0x41B66C
	{ auto _pv = (uint32_t)(4306540); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8935: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1F893A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F893D:
	// 0x1F893D: mov eax, [ebx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0xCu);
	// 0x1F8940: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x1F8942: jz 0x001F8959
	if (ctx.flags.zf) goto loc_1F8959;
	// 0x1F8944: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x1F8946: jnz 0x001F8959
	if (!ctx.flags.zf) goto loc_1F8959;
	// 0x1F8948: mov ecx, [ebx+0x4C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x4Cu);
	// 0x1F894B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F894C: push 0x41B690
	{ auto _pv = (uint32_t)(4306576); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8951: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1F8956: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F8959:
	// 0x1F8959: test byte ptr [ebx+0x0C], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ebx + 0xCu) & 2, 8);
	// 0x1F895D: jz 0x001F896D
	if (ctx.flags.zf) goto loc_1F896D;
	// 0x1F895F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8960: push 0x41B5E8
	{ auto _pv = (uint32_t)(4306408); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8965: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1F896A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F896D:
	// 0x1F896D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F896E: ret
	return;
}

void RwaObjDefDestroy(X86Context& ctx, uint8_t* base) {
loc_1F8970:
	// 0x1F8970: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8971: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8975: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F8978: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8979: lea edi, [esi+0x10]
	ctx.edi = ctx.esi + 0x10u;
	// 0x1F897C: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F897E: jz 0x001F8996
	if (ctx.flags.zf) goto loc_1F8996;
loc_1F8980:
	// 0x1F8980: add eax, 0xFFFFFFE8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-24, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8983: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8984: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F8989: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F898C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F898E: jz 0x001F89FF
	if (ctx.flags.zf) goto loc_1F89FF;
	// 0x1F8990: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F8992: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8994: jnz 0x001F8980
	if (!ctx.flags.zf) goto loc_1F8980;
loc_1F8996:
	// 0x1F8996: mov eax, [esi+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1F8999: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F899B: jz 0x001F89A3
	if (ctx.flags.zf) goto loc_1F89A3;
	// 0x1F899D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F899E: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x1F89A0: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F89A3:
	// 0x1F89A3: test byte ptr [esi+0x0C], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 4, 8);
	// 0x1F89A7: jz 0x001F89C7
	if (ctx.flags.zf) goto loc_1F89C7;
	// 0x1F89A9: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F89AC: lea edi, [eax+0x04]
	ctx.edi = ctx.eax + 0x4u;
	// 0x1F89AF: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F89B1: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F89B3: jz 0x001F89C7
	if (ctx.flags.zf) goto loc_1F89C7;
loc_1F89B5:
	// 0x1F89B5: add eax, 0xFFFFFFEC
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-20, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F89B8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F89B9: call 0x001FD330
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceRemove(ctx, base);
	ctx.esp += 4;
	// 0x1F89BE: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F89C0: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F89C3: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F89C5: jnz 0x001F89B5
	if (!ctx.flags.zf) goto loc_1F89B5;
loc_1F89C7:
	// 0x1F89C7: test byte ptr [esi+0x0C], 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 8, 8);
	// 0x1F89CB: jz 0x001F89E8
	if (ctx.flags.zf) goto loc_1F89E8;
	// 0x1F89CD: mov edi, [esi+0x50]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F89D0: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F89D2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F89D4: jz 0x001F89E8
	if (ctx.flags.zf) goto loc_1F89E8;
loc_1F89D6:
	// 0x1F89D6: add eax, 0xFFFFFFE0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-32, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F89D9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F89DA: call 0x001FFFE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefAliasDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F89DF: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F89E1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F89E4: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F89E6: jnz 0x001F89D6
	if (!ctx.flags.zf) goto loc_1F89D6;
loc_1F89E8:
	// 0x1F89E8: mov eax, [esi+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1F89EB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F89ED: jz 0x001F8A18
	if (ctx.flags.zf) goto loc_1F8A18;
	// 0x1F89EF: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F89F2: test cl, 0x40
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 64, 8);
	// 0x1F89F5: jz 0x001F8A04
	if (ctx.flags.zf) goto loc_1F8A04;
	// 0x1F89F7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F89F8: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F89FD: jmp 0x001F8A0E
	goto loc_1F8A0E;
loc_1F89FF:
	// 0x1F89FF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8A00: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8A02: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8A03: ret
	return;
loc_1F8A04:
	// 0x1F8A04: test cl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & X86_REG8L(ctx.ecx), 8);
	// 0x1F8A06: jns 0x001F8A11
	if (!ctx.flags.sf) goto loc_1F8A11;
	// 0x1F8A08: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A09: call 0x001FE6B0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapDestroy(ctx, base);
	ctx.esp += 4;
loc_1F8A0E:
	// 0x1F8A0E: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F8A11:
	// 0x1F8A11: mov dword ptr [esi+0x48], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, 0);
loc_1F8A18:
	// 0x1F8A18: cmp esi, 0x41B610
	{ uint32_t _d = ctx.esi; uint32_t _s = 4306448;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8A1E: jz 0x001F8A31
	if (ctx.flags.zf) goto loc_1F8A31;
	// 0x1F8A20: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F8A23: mov ecx, [esi+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x1F8A26: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F8A28: mov edx, [esi+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	// 0x1F8A2B: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1F8A2E: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
loc_1F8A31:
	// 0x1F8A31: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8A33: call 0x001F8910
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8910(ctx, base);
	ctx.esp += 4;
	// 0x1F8A38: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8A39: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F8A3E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8A3F: ret
	return;
}

void sub_1F8A40(X86Context& ctx, uint8_t* base) {
	// 0x1F8A40: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8A43: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8A47: mov ecx, [esp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8A4B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A4C: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8A50: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F8A52: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1F8A56: mov [esp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.ecx);
	// 0x1F8A5A: jnz 0x001F8A62
	if (!ctx.flags.zf) goto loc_1F8A62;
	// 0x1F8A5C: mov esi, [0x00764134]
	ctx.esi = X86_MEM_READ_u32(base, 0x764134u);
loc_1F8A62:
	// 0x1F8A62: lea edx, [esp+0x04]
	ctx.edx = ctx.esp + 0x4u;
	// 0x1F8A66: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A67: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A68: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A69: call 0x001F8800
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8800(ctx, base);
	ctx.esp += 4;
	// 0x1F8A6E: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8A71: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8A74: jz 0x001F8AF2
	if (ctx.flags.zf) goto loc_1F8AF2;
	// 0x1F8A76: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A77: lea ebp, [esi+0x10]
	ctx.ebp = ctx.esi + 0x10u;
	// 0x1F8A7A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A7B: mov edi, [ebp]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x1F8A7E: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8A80: jz 0x001F8AF0
	if (ctx.flags.zf) goto loc_1F8AF0;
loc_1F8A82:
	// 0x1F8A82: mov al, [edi-0x0C]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi - 0xCu);
	// 0x1F8A85: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x1F8A87: lea esi, [edi-0x18]
	ctx.esi = ctx.edi - 0x18u;
	// 0x1F8A8A: jz 0x001F8ACF
	if (ctx.flags.zf) goto loc_1F8ACF;
	// 0x1F8A8C: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8A90: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8A92: jz 0x001F8ACF
	if (ctx.flags.zf) goto loc_1F8ACF;
	// 0x1F8A94: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8A98: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A9A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A9B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8A9C: call 0x001FD370
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD370(ctx, base);
	ctx.esp += 4;
	// 0x1F8AA1: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8AA4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8AA6: jz 0x001F8ACF
	if (ctx.flags.zf) goto loc_1F8ACF;
	// 0x1F8AA8: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8AAC: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8AAD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8AAE: call 0x001FE0E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE0E0(ctx, base);
	ctx.esp += 4;
	// 0x1F8AB3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8AB6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8AB8: jnz 0x001F8ACF
	if (!ctx.flags.zf) goto loc_1F8ACF;
	// 0x1F8ABA: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F8ABE: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8ABF: call 0x001FE170
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE170(ctx, base);
	ctx.esp += 4;
	// 0x1F8AC4: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8AC7: mov dword ptr [esp+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, 0);
loc_1F8ACF:
	// 0x1F8ACF: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8AD1: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x1F8AD5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8AD6: push 0x1F8800
	{ auto _pv = (uint32_t)(2066432); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8ADB: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8ADD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8ADE: call 0x001F8750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8750(ctx, base);
	ctx.esp += 4;
	// 0x1F8AE3: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8AE6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8AE8: jnz 0x001F8AF0
	if (!ctx.flags.zf) goto loc_1F8AF0;
	// 0x1F8AEA: mov edi, [edi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F8AEC: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8AEE: jnz 0x001F8A82
	if (!ctx.flags.zf) goto loc_1F8A82;
loc_1F8AF0:
	// 0x1F8AF0: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8AF1: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F8AF2:
	// 0x1F8AF2: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F8AF6: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8AF8: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F8AFA: setnz al
	X86_REG8L(ctx.eax) = (!ctx.flags.zf) ? 1 : 0;
	// 0x1F8AFD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8AFE: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8B01: ret
	return;
}

void sub_1F8B10(X86Context& ctx, uint8_t* base) {
	// 0x1F8B10: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8B13: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F8B17: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F8B19: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F8B1C: mov [esp], ecx
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.ecx);
	// 0x1F8B1F: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1F8B22: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1F8B26: mov edx, [eax+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F8B29: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B2B: lea eax, [esp+0x04]
	ctx.eax = ctx.esp + 0x4u;
	// 0x1F8B2F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B30: mov [esp+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.ecx);
	// 0x1F8B34: push 0x1F8860
	{ auto _pv = (uint32_t)(2066528); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B39: lea ecx, [esp+0x24]
	ctx.ecx = ctx.esp + 0x24u;
	// 0x1F8B3D: mov [esp+0x18], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.edx);
	// 0x1F8B41: mov edx, [esp+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F8B45: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B46: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B47: call 0x001F8750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8750(ctx, base);
	ctx.esp += 4;
	// 0x1F8B4C: mov ecx, [esp+0x30]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1F8B50: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8B53: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F8B55: jz 0x001F8B5D
	if (ctx.flags.zf) goto loc_1F8B5D;
	// 0x1F8B57: mov edx, [esp+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F8B5B: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_1F8B5D:
	// 0x1F8B5D: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8B60: ret
	return;
}

void sub_1F8B70(X86Context& ctx, uint8_t* base) {
	// 0x1F8B70: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B71: mov ebx, [esp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8B75: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x1F8B77: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B78: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B79: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8B7A: jnz 0x001F8BD5
	if (!ctx.flags.zf) goto loc_1F8BD5;
	// 0x1F8B7C: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F8B80: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8B82: jnz 0x001F8BD5
	if (!ctx.flags.zf) goto loc_1F8BD5;
	// 0x1F8B84: movzx edi, word ptr [esp+0x1C]
	ctx.edi = (uint32_t)(X86_MEM_READ_u16(base, ctx.esp + 0x1Cu));
	// 0x1F8B89: movzx eax, word ptr [esp+0x24]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esp + 0x24u));
	// 0x1F8B8E: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8B92: mov ebp, [esi+0x0C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F8B95: add eax, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F8B97: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x1F8B9A: shl eax, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F8B9D: push 0x3080A
	{ auto _pv = (uint32_t)(198666); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8BA2: and ebp, 0xFFFFFFFE
	ctx.ebp = ctx.ebp & -2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebp, 32);
	// 0x1F8BA5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8BA6: mov [esi+0x0C], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ebp);
	// 0x1F8BA9: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1F8BAE: mov ecx, [esi+0x4C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8BB1: mov [ecx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.eax);
	// 0x1F8BB4: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8BB7: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1F8BBA: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8BBD: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F8BBF: jz 0x001F8C82
	if (ctx.flags.zf) goto loc_1F8C82;
	// 0x1F8BC5: lea edx, [edi+edi*2]
	ctx.edx = ctx.edi + ctx.edi * 2;
	// 0x1F8BC8: lea ecx, [ecx+edx*8]
	ctx.ecx = ctx.ecx + ctx.edx * 8;
	// 0x1F8BCB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8BCC: mov [eax+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.ecx);
	// 0x1F8BCF: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8BD1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8BD2: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8BD3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8BD4: ret
	return;
loc_1F8BD5:
	// 0x1F8BD5: mov bp, [esp+0x1C]
	X86_REG16(ctx.ebp) = X86_MEM_READ_u16(base, ctx.esp + 0x1Cu);
	// 0x1F8BDA: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8BDC: test bp, bp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.ebp) & X86_REG16(ctx.ebp), 16);
	// 0x1F8BDF: jbe 0x001F8C12
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F8C12;
loc_1F8BE1:
	// 0x1F8BE1: movzx eax, di
	ctx.eax = (uint32_t)(X86_REG16(ctx.edi));
	// 0x1F8BE4: lea edx, [eax+eax*2]
	ctx.edx = ctx.eax + ctx.eax * 2;
	// 0x1F8BE7: lea esi, [ebx+edx*8]
	ctx.esi = ctx.ebx + ctx.edx * 8;
	// 0x1F8BEA: lea eax, [esi+0x0C]
	ctx.eax = ctx.esi + 0xCu;
	// 0x1F8BED: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8BEE: call 0x001FDB80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FDB80(ctx, base);
	ctx.esp += 4;
	// 0x1F8BF3: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8BF6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8BF8: jz 0x001F8C82
	if (ctx.flags.zf) goto loc_1F8C82;
	// 0x1F8BFE: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x1F8C01: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8C03: jnz 0x001F8C0C
	if (!ctx.flags.zf) goto loc_1F8C0C;
	// 0x1F8C05: mov dword ptr [esi+0x14], 0x2087B0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, 2131888);
loc_1F8C0C:
	// 0x1F8C0C: inc edi
	{ uint32_t _d = ctx.edi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1F8C0D: cmp di, bp
	{ uint16_t _d = X86_REG16(ctx.edi); uint16_t _s = X86_REG16(ctx.ebp);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x1F8C10: jb 0x001F8BE1
	if (ctx.flags.cf) goto loc_1F8BE1;
loc_1F8C12:
	// 0x1F8C12: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8C16: mov ecx, [esi+0x4C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8C19: mov [ecx+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.ebx);
	// 0x1F8C1C: mov edx, [esi+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8C1F: mov [edx+0x0C], bp
	X86_MEM_WRITE_u16(base, ctx.edx + 0xCu, X86_REG16(ctx.ebp));
	// 0x1F8C23: mov bp, [esp+0x24]
	X86_REG16(ctx.ebp) = X86_MEM_READ_u16(base, ctx.esp + 0x24u);
	// 0x1F8C28: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8C2A: test bp, bp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.ebp) & X86_REG16(ctx.ebp), 16);
	// 0x1F8C2D: jbe 0x001F8C61
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F8C61;
	// 0x1F8C2F: nop
loc_1F8C30:
	// 0x1F8C30: mov ecx, [esp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F8C34: movzx eax, bx
	ctx.eax = (uint32_t)(X86_REG16(ctx.ebx));
	// 0x1F8C37: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x1F8C3A: lea edi, [ecx+eax*8]
	ctx.edi = ctx.ecx + ctx.eax * 8;
	// 0x1F8C3D: lea edx, [edi+0x0C]
	ctx.edx = ctx.edi + 0xCu;
	// 0x1F8C40: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8C41: call 0x001FDB80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FDB80(ctx, base);
	ctx.esp += 4;
	// 0x1F8C46: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8C49: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8C4B: jz 0x001F8C82
	if (ctx.flags.zf) goto loc_1F8C82;
	// 0x1F8C4D: mov eax, [edi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x14u);
	// 0x1F8C50: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8C52: jnz 0x001F8C5B
	if (!ctx.flags.zf) goto loc_1F8C5B;
	// 0x1F8C54: mov dword ptr [edi+0x14], 0x2087B0
	X86_MEM_WRITE_u32(base, ctx.edi + 0x14u, 2131888);
loc_1F8C5B:
	// 0x1F8C5B: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x1F8C5C: cmp bx, bp
	{ uint16_t _d = X86_REG16(ctx.ebx); uint16_t _s = X86_REG16(ctx.ebp);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x1F8C5F: jb 0x001F8C30
	if (ctx.flags.cf) goto loc_1F8C30;
loc_1F8C61:
	// 0x1F8C61: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F8C64: mov ecx, [esp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F8C68: or eax, 0x01
	ctx.eax = ctx.eax | 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F8C6B: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x1F8C6E: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8C71: mov [eax+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.ecx);
	// 0x1F8C74: mov edx, [esi+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8C77: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C78: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8C7A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C7B: mov [edx+0x0E], bp
	X86_MEM_WRITE_u16(base, ctx.edx + 0xEu, X86_REG16(ctx.ebp));
	// 0x1F8C7F: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C80: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C81: ret
	return;
loc_1F8C82:
	// 0x1F8C82: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C83: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C84: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C85: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8C87: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8C88: ret
	return;
}

void sub_1F8C90(X86Context& ctx, uint8_t* base) {
	// 0x1F8C90: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8C91: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8C92: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8C93: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8C95: push 0x764110
	{ auto _pv = (uint32_t)(7749904); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8C9A: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F8C9C: call 0x00200130
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	SkyUpLoadAlignedRectangle(ctx, base);
	ctx.esp += 4;
	// 0x1F8CA1: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F8CA3: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F8CA7: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8CAA: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8CAD: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8CB0: jnz 0x001F8CEA
	if (!ctx.flags.zf) goto loc_1F8CEA;
	// 0x1F8CB2: mov ecx, [eax+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1F8CB5: mov ax, [eax+0x0C]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.eax + 0xCu);
	// 0x1F8CB9: test ax, ax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & X86_REG16(ctx.eax), 16);
	// 0x1F8CBC: jbe 0x001F8D22
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F8D22;
	// 0x1F8CBE: lea esi, [ecx+0x10]
	ctx.esi = ctx.ecx + 0x10u;
	// 0x1F8CC1: movzx ebx, ax
	ctx.ebx = (uint32_t)(X86_REG16(ctx.eax));
loc_1F8CC4:
	// 0x1F8CC4: lea eax, [esi-0x10]
	ctx.eax = ctx.esi - 0x10u;
	// 0x1F8CC7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8CC8: mov [esi-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi - 0x4u, ctx.edi);
	// 0x1F8CCB: mov dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, 0);
	// 0x1F8CD1: mov dword ptr [esi+0x04], 0x2087B0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 2131888);
	// 0x1F8CD8: call 0x001FE3D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDInitialize(ctx, base);
	ctx.esp += 4;
	// 0x1F8CDD: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8CE0: add esi, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)24, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1F8CE3: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x1F8CE4: jnz 0x001F8CC4
	if (!ctx.flags.zf) goto loc_1F8CC4;
	// 0x1F8CE6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8CE7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8CE8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8CE9: ret
	return;
loc_1F8CEA:
	// 0x1F8CEA: mov ecx, [eax+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x1F8CED: mov ax, [eax+0x0E]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.eax + 0xEu);
	// 0x1F8CF1: test ax, ax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.eax) & X86_REG16(ctx.eax), 16);
	// 0x1F8CF4: jbe 0x001F8D22
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F8D22;
	// 0x1F8CF6: lea esi, [ecx+0x10]
	ctx.esi = ctx.ecx + 0x10u;
	// 0x1F8CF9: movzx ebx, ax
	ctx.ebx = (uint32_t)(X86_REG16(ctx.eax));
	// 0x1F8CFC: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_1F8D00:
	// 0x1F8D00: lea ecx, [esi-0x10]
	ctx.ecx = ctx.esi - 0x10u;
	// 0x1F8D03: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D04: mov [esi-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.esi - 0x4u, ctx.edi);
	// 0x1F8D07: mov dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, 0);
	// 0x1F8D0D: mov dword ptr [esi+0x04], 0x2087B0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 2131888);
	// 0x1F8D14: call 0x001FE3D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDInitialize(ctx, base);
	ctx.esp += 4;
	// 0x1F8D19: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8D1C: add esi, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)24, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1F8D1F: dec ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x1F8D20: jnz 0x001F8D00
	if (!ctx.flags.zf) goto loc_1F8D00;
loc_1F8D22:
	// 0x1F8D22: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8D23: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8D24: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8D25: ret
	return;
}

void _rwaObjDefCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1F8D30: push 0x41B610
	{ auto _pv = (uint32_t)(4306448); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D35: mov dword ptr [0x0041B6B4], 0x01
	X86_MEM_WRITE_u32(base, 0x41B6B4u, 1);
	// 0x1F8D3F: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F8D44: push 0x41B66C
	{ auto _pv = (uint32_t)(4306540); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D49: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F8D4E: push 0x41B690
	{ auto _pv = (uint32_t)(4306576); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D53: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F8D58: push 0x41B5E8
	{ auto _pv = (uint32_t)(4306408); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D5D: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F8D62: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8D65: mov dword ptr [0x0041B6B8], 0x00
	X86_MEM_WRITE_u32(base, 0x41B6B8u, 0);
	// 0x1F8D6F: ret
	return;
}

void sub_1F8D70(X86Context& ctx, uint8_t* base) {
	// 0x1F8D70: test byte ptr [esi+0x0C], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 4, 8);
	// 0x1F8D74: jz 0x001F8D8B
	if (ctx.flags.zf) goto loc_1F8D8B;
	// 0x1F8D76: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D78: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8D7A: call 0x001F8C90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8C90(ctx, base);
	ctx.esp += 4;
	// 0x1F8D7F: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D81: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8D83: call 0x001F8C90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8C90(ctx, base);
	ctx.esp += 4;
	// 0x1F8D88: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F8D8B:
	// 0x1F8D8B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8D8C: call 0x001FE3D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDInitialize(ctx, base);
	ctx.esp += 4;
	// 0x1F8D91: mov cl, [esi+0x0C]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0xCu);
	// 0x1F8D94: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8D97: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8D99: test cl, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 4, 8);
	// 0x1F8D9C: jz 0x001F8DB9
	if (ctx.flags.zf) goto loc_1F8DB9;
	// 0x1F8D9E: mov ecx, [esi+0x4C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8DA1: lea edx, [ecx+0x04]
	ctx.edx = ctx.ecx + 0x4u;
	// 0x1F8DA4: mov [edx], edx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.edx);
	// 0x1F8DA6: mov [ecx+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edx);
	// 0x1F8DA9: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x1F8DAB: mov [ecx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.eax);
	// 0x1F8DAE: mov [ecx+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, ctx.eax);
	// 0x1F8DB1: mov [ecx+0x0C], ax
	X86_MEM_WRITE_u16(base, ctx.ecx + 0xCu, X86_REG16(ctx.eax));
	// 0x1F8DB5: mov [ecx+0x0E], ax
	X86_MEM_WRITE_u16(base, ctx.ecx + 0xEu, X86_REG16(ctx.eax));
loc_1F8DB9:
	// 0x1F8DB9: mov cl, [esi+0x0C]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0xCu);
	// 0x1F8DBC: mov edx, 0x08
	ctx.edx = 8;
	// 0x1F8DC1: test dl, cl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.ecx), 8);
	// 0x1F8DC3: jz 0x001F8DCD
	if (ctx.flags.zf) goto loc_1F8DCD;
	// 0x1F8DC5: mov ecx, [esi+0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F8DC8: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x1F8DCA: mov [ecx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.ecx);
loc_1F8DCD:
	// 0x1F8DCD: mov [esi+0x40], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.eax);
	// 0x1F8DD0: mov [esi+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.eax);
	// 0x1F8DD3: movsx ecx, byte ptr [0x003C0849]
	ctx.ecx = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, 0x3C0849u)));
	// 0x1F8DDA: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1F8DDB: shl ecx, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1F8DDE: or ecx, eax
	ctx.ecx = ctx.ecx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1F8DE0: mov [esi+0x40], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.ecx);
	// 0x1F8DE3: lea ecx, [esi+0x10]
	ctx.ecx = ctx.esi + 0x10u;
	// 0x1F8DE6: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x1F8DE8: mov [esi+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.ecx);
	// 0x1F8DEB: lea ecx, [esi+0x20]
	ctx.ecx = ctx.esi + 0x20u;
	// 0x1F8DEE: mov [esi+0x46], dx
	X86_MEM_WRITE_u16(base, ctx.esi + 0x46u, X86_REG16(ctx.edx));
	// 0x1F8DF2: mov [esi+0x44], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x44u, X86_REG16(ctx.eax));
	// 0x1F8DF6: mov [esi+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x54u, ctx.eax);
	// 0x1F8DF9: mov [esi+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.eax);
	// 0x1F8DFC: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x1F8DFF: mov [ecx], ecx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.ecx);
	// 0x1F8E01: mov [esi+0x24], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.ecx);
	// 0x1F8E04: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x1F8E07: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x1F8E0A: mov [esi+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, ctx.eax);
	// 0x1F8E0D: mov [esi+0x34], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, ctx.eax);
	// 0x1F8E10: mov [esi+0x38], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.eax);
	// 0x1F8E13: mov [esi+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.eax);
	// 0x1F8E16: ret
	return;
}

void RwaObjDefCreate(X86Context& ctx, uint8_t* base) {
	// 0x1F8E20: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E21: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E22: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F8E26: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1F8E28: jnz 0x001F8E39
	if (!ctx.flags.zf) goto loc_1F8E39;
	// 0x1F8E2A: mov eax, [0x0041B6BC]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B6BCu);
	// 0x1F8E2F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8E31: jnz 0x001F8E39
	if (!ctx.flags.zf) goto loc_1F8E39;
	// 0x1F8E33: mov edi, [0x00764134]
	ctx.edi = X86_MEM_READ_u32(base, 0x764134u);
loc_1F8E39:
	// 0x1F8E39: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F8E3D: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F8E3F: jnz 0x001F8E65
	if (!ctx.flags.zf) goto loc_1F8E65;
	// 0x1F8E41: push 0x3080A
	{ auto _pv = (uint32_t)(198666); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E46: push 0x41B5E8
	{ auto _pv = (uint32_t)(4306408); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E4B: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x1F8E50: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F8E52: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8E55: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F8E57: jnz 0x001F8E5C
	if (!ctx.flags.zf) goto loc_1F8E5C;
	// 0x1F8E59: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8E5A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8E5B: ret
	return;
loc_1F8E5C:
	// 0x1F8E5C: mov dword ptr [esi+0x0C], 0x02
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, 2);
	// 0x1F8E63: jmp 0x001F8E6C
	goto loc_1F8E6C;
loc_1F8E65:
	// 0x1F8E65: mov dword ptr [esi+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, 0);
loc_1F8E6C:
	// 0x1F8E6C: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F8E70: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E71: mov bl, [esp+0x14]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.esp + 0x14u);
	// 0x1F8E75: test bl, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 4, 8);
	// 0x1F8E78: mov [esi+0x58], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, ctx.eax);
	// 0x1F8E7B: jz 0x001F8ECC
	if (ctx.flags.zf) goto loc_1F8ECC;
	// 0x1F8E7D: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1F8E81: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8E83: jnz 0x001F8EAB
	if (!ctx.flags.zf) goto loc_1F8EAB;
	// 0x1F8E85: push 0x3080A
	{ auto _pv = (uint32_t)(198666); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E8A: push 0x41B690
	{ auto _pv = (uint32_t)(4306576); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8E8F: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x1F8E94: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8E97: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8E99: mov [esi+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.eax);
	// 0x1F8E9C: jnz 0x001F8EB2
	if (!ctx.flags.zf) goto loc_1F8EB2;
	// 0x1F8E9E: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8EA0: call 0x001F8910
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8910(ctx, base);
	ctx.esp += 4;
	// 0x1F8EA5: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8EA6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8EA7: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8EA9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8EAA: ret
	return;
loc_1F8EAB:
	// 0x1F8EAB: mov [esi+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.eax);
	// 0x1F8EAE: or dword ptr [esi+0x0C], 0x10
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 16);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
loc_1F8EB2:
	// 0x1F8EB2: mov edx, [esi+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F8EB5: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8EB7: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F8EB9: mov [edx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.ecx);
	// 0x1F8EBC: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F8EBF: mov [edx+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.ecx);
	// 0x1F8EC2: mov [edx+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x10u, ctx.ecx);
	// 0x1F8EC5: mov [edx+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x14u, ctx.ecx);
	// 0x1F8EC8: or dword ptr [esi+0x0C], 0x04
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
loc_1F8ECC:
	// 0x1F8ECC: test bl, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ebx) & 8, 8);
	// 0x1F8ECF: jz 0x001F8F14
	if (ctx.flags.zf) goto loc_1F8F14;
	// 0x1F8ED1: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F8ED5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8ED7: jnz 0x001F8EFF
	if (!ctx.flags.zf) goto loc_1F8EFF;
	// 0x1F8ED9: push 0x3080A
	{ auto _pv = (uint32_t)(198666); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8EDE: push 0x41B66C
	{ auto _pv = (uint32_t)(4306540); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8EE3: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x1F8EE8: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8EEB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8EED: mov [esi+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x50u, ctx.eax);
	// 0x1F8EF0: jnz 0x001F8F06
	if (!ctx.flags.zf) goto loc_1F8F06;
	// 0x1F8EF2: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8EF4: call 0x001F8910
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8910(ctx, base);
	ctx.esp += 4;
	// 0x1F8EF9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8EFA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8EFB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8EFD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8EFE: ret
	return;
loc_1F8EFF:
	// 0x1F8EFF: mov [esi+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x50u, ctx.eax);
	// 0x1F8F02: or dword ptr [esi+0x0C], 0x20
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 32);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
loc_1F8F06:
	// 0x1F8F06: mov ecx, [esi+0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F8F09: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8F0B: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x1F8F0D: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x1F8F10: or dword ptr [esi+0x0C], 0x08
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 8);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
loc_1F8F14:
	// 0x1F8F14: call 0x001F8D70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8D70(ctx, base);
	ctx.esp += 4;
	// 0x1F8F19: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1F8F1B: jz 0x001F8F32
	if (ctx.flags.zf) goto loc_1F8F32;
	// 0x1F8F1D: mov edx, [edi+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	// 0x1F8F20: lea eax, [edi+0x10]
	ctx.eax = ctx.edi + 0x10u;
	// 0x1F8F23: lea ecx, [esi+0x18]
	ctx.ecx = ctx.esi + 0x18u;
	// 0x1F8F26: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1F8F28: mov [esi+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.eax);
	// 0x1F8F2B: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F8F2D: mov [edx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.ecx);
	// 0x1F8F30: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
loc_1F8F32:
	// 0x1F8F32: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8F33: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8F34: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F8F36: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8F37: ret
	return;
}

void _rwaObjDefOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1F8F40: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F41: push 0x4080A
	{ auto _pv = (uint32_t)(264202); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F46: push 0x41B5E8
	{ auto _pv = (uint32_t)(4306408); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F4B: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F8F4D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F4E: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F50: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F52: push 0x5C
	{ auto _pv = (uint32_t)(92); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F54: mov [0x0041B6B4], edi
	X86_MEM_WRITE_u32(base, 0x41B6B4u, ctx.edi);
	// 0x1F8F5A: mov dword ptr [0x0041B6BC], 0x01
	X86_MEM_WRITE_u32(base, 0x41B6BCu, 1);
	// 0x1F8F64: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F8F69: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8F6C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8F6E: jz 0x001F9033
	if (ctx.flags.zf) goto loc_1F9033;
	// 0x1F8F74: push 0x4080A
	{ auto _pv = (uint32_t)(264202); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F79: push 0x41B690
	{ auto _pv = (uint32_t)(4306576); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F7E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F7F: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F81: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F83: push 0x18
	{ auto _pv = (uint32_t)(24); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F85: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F8F8A: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8F8D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8F8F: jz 0x001F9026
	if (ctx.flags.zf) goto loc_1F9026;
	// 0x1F8F95: push 0x4080A
	{ auto _pv = (uint32_t)(264202); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F9A: push 0x41B66C
	{ auto _pv = (uint32_t)(4306540); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8F9F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FA0: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FA2: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FA4: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FA6: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F8FAB: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8FAE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F8FB0: jz 0x001F9019
	if (ctx.flags.zf) goto loc_1F9019;
	// 0x1F8FB2: push 0x4080A
	{ auto _pv = (uint32_t)(264202); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FB7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FB8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FB9: push 0x41B610
	{ auto _pv = (uint32_t)(4306448); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FBE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FBF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FC0: mov dword ptr [0x0041B6B8], 0x01
	X86_MEM_WRITE_u32(base, 0x41B6B8u, 1);
	// 0x1F8FCA: call 0x001F8E20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F8FCF: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8FD2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F8FD4: mov [0x00764134], eax
	X86_MEM_WRITE_u32(base, 0x764134u, ctx.eax);
	// 0x1F8FD9: jz 0x001F900C
	if (ctx.flags.zf) goto loc_1F900C;
	// 0x1F8FDB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FDC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FDD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FDE: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F8FE0: call 0x001FE480
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDAssignName(ctx, base);
	ctx.esp += 4;
	// 0x1F8FE5: push 0x3C113C
	{ auto _pv = (uint32_t)(3936572); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FEA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F8FEB: call 0x001FE4C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDAssignUUID(ctx, base);
	ctx.esp += 4;
	// 0x1F8FF0: mov eax, [0x00764134]
	ctx.eax = X86_MEM_READ_u32(base, 0x764134u);
	// 0x1F8FF5: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F8FF8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F8FF9: mov word ptr [eax+0x46], 0x01
	X86_MEM_WRITE_u16(base, ctx.eax + 0x46u, 1);
	// 0x1F8FFF: mov [0x0041B6BC], edi
	X86_MEM_WRITE_u32(base, 0x41B6BCu, ctx.edi);
	// 0x1F9005: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F900A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F900B: ret
	return;
loc_1F900C:
	// 0x1F900C: push 0x41B66C
	{ auto _pv = (uint32_t)(4306540); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9011: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F9016: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9019:
	// 0x1F9019: push 0x41B690
	{ auto _pv = (uint32_t)(4306576); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F901E: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F9023: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9026:
	// 0x1F9026: push 0x41B5E8
	{ auto _pv = (uint32_t)(4306408); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F902B: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F9030: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9033:
	// 0x1F9033: mov [0x0041B6B8], edi
	X86_MEM_WRITE_u32(base, 0x41B6B8u, ctx.edi);
	// 0x1F9039: mov [0x0041B6BC], edi
	X86_MEM_WRITE_u32(base, 0x41B6BCu, ctx.edi);
	// 0x1F903F: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9041: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9042: ret
	return;
}

void sub_1F9050(X86Context& ctx, uint8_t* base) {
	// 0x1F9050: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F9054: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F9058: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F905C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F905D: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F9061: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9062: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9066: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9067: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9068: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9069: push 0x41B6E0
	{ auto _pv = (uint32_t)(4306656); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F906E: call 0x001F6050
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F9073: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9076: ret
	return;
}

void RwaStreamUnregister(X86Context& ctx, uint8_t* base) {
	// 0x1F9080: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9085: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9086: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x1F908B: mov ecx, [0x00764130]
	ctx.ecx = X86_MEM_READ_u32(base, 0x764130u);
	// 0x1F9091: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9092: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x1F9097: push 0x41B6E0
	{ auto _pv = (uint32_t)(4306656); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F909C: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F90A1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F90A4: ret
	return;
}

void sub_1F90B0(X86Context& ctx, uint8_t* base) {
	// 0x1F90B0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F90B4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90B5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F90B9: mov dword ptr [esi+0x270], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x270u, 0);
	// 0x1F90C3: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1F90C6: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F90C9: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F90CB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90CC: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F90D0: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90D1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90D2: push 0xBB80
	{ auto _pv = (uint32_t)(48000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90D7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90D8: lea edx, [esi+0xEC]
	ctx.edx = ctx.esi + 0xECu;
	// 0x1F90DE: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90DF: call 0x00201C50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201C50(ctx, base);
	ctx.esp += 4;
	// 0x1F90E4: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F90E7: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F90E9: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F90EB: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F90ED: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F90EE: ret
	return;
}

void sub_1F90F0(X86Context& ctx, uint8_t* base) {
	// 0x1F90F0: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F90F5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90F6: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F90FA: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90FC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F90FD: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F9102: lea ecx, [esi+0x154]
	ctx.ecx = ctx.esi + 0x154u;
	// 0x1F9108: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9109: add esi, 0xEC
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(236);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)236, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1F910F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9110: call 0x00200E00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_200E00(ctx, base);
	ctx.esp += 4;
	// 0x1F9115: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F911B: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F911E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9120: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9122: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9123: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9128: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9129: ret
	return;
}

void sub_1F9130(X86Context& ctx, uint8_t* base) {
	// 0x1F9130: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9131: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9135: lea eax, [esi+0xEC]
	ctx.eax = ctx.esi + 0xECu;
	// 0x1F913B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F913C: call 0x00201DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201DF0(ctx, base);
	ctx.esp += 4;
	// 0x1F9141: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9144: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9146: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9147: ret
	return;
}

void sub_1F9150(X86Context& ctx, uint8_t* base) {
	// 0x1F9150: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9154: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9156: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F9158: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x1F915B: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x1F915E: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9162: ret
	return;
}

void sub_1F9170(X86Context& ctx, uint8_t* base) {
	// 0x1F9170: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9174: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F9176: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9177: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9178: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9179: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F917A: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F917E: mov [edi+0x28], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x28u, ctx.ecx);
	// 0x1F9181: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F9184: lea esi, [edi+0x28]
	ctx.esi = ctx.edi + 0x28u;
	// 0x1F9187: mov [esi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edx);
	// 0x1F918A: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F918C: mov ebp, [edx]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F918E: lea ecx, [edi+0x30]
	ctx.ecx = ctx.edi + 0x30u;
	// 0x1F9191: mov ebx, ecx
	ctx.ebx = ctx.ecx;
	// 0x1F9193: mov [ebx], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.ebp);
	// 0x1F9195: mov ebp, [edx+0x04]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1F9198: mov [ebx+0x04], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.ebp);
	// 0x1F919B: mov ebp, [edx+0x08]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F919E: mov [ebx+0x08], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, ctx.ebp);
	// 0x1F91A1: mov edx, [edx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x1F91A4: mov [ebx+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xCu, ctx.edx);
	// 0x1F91A7: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x1F91A9: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F91AB: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F91AE: cmp ecx, 0x01
	{ uint32_t _d = ctx.ecx; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F91B1: jnz 0x001F91C9
	if (!ctx.flags.zf) goto loc_1F91C9;
	// 0x1F91B3: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F91B5: push 0x80
	{ auto _pv = (uint32_t)(128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F91BA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F91BB: lea ecx, [edi+0x40]
	ctx.ecx = ctx.edi + 0x40u;
	// 0x1F91BE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F91BF: call 0x00243880
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_243880(ctx, base);
	ctx.esp += 4;
	// 0x1F91C4: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F91C7: jmp 0x001F91EC
	goto loc_1F91EC;
loc_1F91C9:
	// 0x1F91C9: cmp ecx, 0x02
	{ uint32_t _d = ctx.ecx; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F91CC: jnz 0x001F91EC
	if (!ctx.flags.zf) goto loc_1F91EC;
	// 0x1F91CE: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F91D0: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F91D2: lea edx, [edi+0xDC]
	ctx.edx = ctx.edi + 0xDCu;
	// 0x1F91D8: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F91DA: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F91DD: mov [edx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.ecx);
	// 0x1F91E0: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1F91E3: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1F91E6: mov eax, [eax+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F91E9: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
loc_1F91EC:
	// 0x1F91EC: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F91F2: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F91F4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F91F5: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F91FA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F91FB: add edi, 0x15C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(348);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)348, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1F9201: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9202: call 0x00201EF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201EF0(ctx, base);
	ctx.esp += 4;
	// 0x1F9207: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F920D: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9210: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9212: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9214: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9215: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F921A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F921B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F921C: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F921D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F921E: ret
	return;
}

void sub_1F9220(X86Context& ctx, uint8_t* base) {
	// 0x1F9220: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9225: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9226: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9227: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9229: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F922A: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F922F: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9233: lea ecx, [esi+0x154]
	ctx.ecx = ctx.esi + 0x154u;
	// 0x1F9239: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F923A: lea edx, [esi+0xEC]
	ctx.edx = ctx.esi + 0xECu;
	// 0x1F9240: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9241: call 0x00200C70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_200C70(ctx, base);
	ctx.esp += 4;
	// 0x1F9246: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9249: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F924B: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1F924D: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F924F: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9251: jnz 0x001F926A
	if (!ctx.flags.zf) goto loc_1F926A;
	// 0x1F9253: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F9257: mov [eax+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edi);
	// 0x1F925A: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1F925C: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9261: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9262: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9267: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9268: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9269: ret
	return;
loc_1F926A:
	// 0x1F926A: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9270: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9271: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9276: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F927A: mov ecx, [esi+0x100]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x100u);
	// 0x1F9280: mov edx, [eax+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F9283: add ecx, 0x5C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(92);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)92, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1F9286: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F9287: jz 0x001F9294
	if (ctx.flags.zf) goto loc_1F9294;
	// 0x1F9289: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F928A: jnz 0x001F92C9
	if (!ctx.flags.zf) goto loc_1F92C9;
	// 0x1F928C: mov edx, [edi+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x1F928F: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x1F9292: jmp 0x001F92C9
	goto loc_1F92C9;
loc_1F9294:
	// 0x1F9294: mov edx, [edi+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x1F9297: fild [edi+0x08]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x8u)));
	// 0x1F929A: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1F929C: jnl 0x001F92A4
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1F92A4;
	// 0x1F929E: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1F92A4:
	// 0x1F92A4: mov edx, [esi+0xF8]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0xF8u);
	// 0x1F92AA: mov edx, [edx+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x18u);
	// 0x1F92AD: mov edx, [edx+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x14u);
	// 0x1F92B0: mov edx, [edx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F92B2: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1F92B4: mov [esp+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.edx);
	// 0x1F92B8: fild [esp+0x10]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)));
	// 0x1F92BC: jnl 0x001F92C4
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1F92C4;
	// 0x1F92BE: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1F92C4:
	// 0x1F92C4: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F92C6: fstp [eax+0x08]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_1F92C9:
	// 0x1F92C9: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F92CC: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F92CD: jz 0x001F92F2
	if (ctx.flags.zf) goto loc_1F92F2;
	// 0x1F92CF: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F92D0: jz 0x001F92DC
	if (ctx.flags.zf) goto loc_1F92DC;
	// 0x1F92D2: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F92D3: jnz 0x001F9306
	if (!ctx.flags.zf) goto loc_1F9306;
	// 0x1F92D5: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F92D7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F92D8: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F92DA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F92DB: ret
	return;
loc_1F92DC:
	// 0x1F92DC: mov edx, [ecx+0x12C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x12Cu);
	// 0x1F92E2: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F92E4: mov edx, [edx+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x10u);
	// 0x1F92E7: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1F92EA: mov ecx, [ecx+edx*1]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + ctx.edx);
	// 0x1F92ED: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F92EE: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1F92F0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F92F1: ret
	return;
loc_1F92F2:
	// 0x1F92F2: mov edx, [ecx+0x12C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x12Cu);
	// 0x1F92F8: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F92FA: mov edx, [edx+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x10u);
	// 0x1F92FD: shl ecx, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1F9300: mov ecx, [edx+ecx*1+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + ctx.ecx + 0x4u);
	// 0x1F9304: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
loc_1F9306:
	// 0x1F9306: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9307: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9308: ret
	return;
}

void rwaStreamSetLoopSegment(X86Context& ctx, uint8_t* base) {
	// 0x1F9310: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9315: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9317: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9318: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F931D: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9321: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9325: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9326: add edx, 0x15C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(348);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)348, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F932C: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F932D: call 0x00201F80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaStreamContainerCommandSetLoopSegment(ctx, base);
	ctx.esp += 4;
	// 0x1F9332: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9337: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F933A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F933C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F933E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F933F: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9344: ret
	return;
}

void sub_1F9350(X86Context& ctx, uint8_t* base) {
	// 0x1F9350: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9355: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9357: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9358: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F935D: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9361: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9363: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9367: jz 0x001F939F
	if (ctx.flags.zf) goto loc_1F939F;
	// 0x1F9369: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F936A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F936B: mov esi, [eax+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1F936E: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F9370: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9371: jz 0x001F9380
	if (ctx.flags.zf) goto loc_1F9380;
	// 0x1F9373: lea edi, [edx+0xC0]
	ctx.edi = ctx.edx + 0xC0u;
	// 0x1F9379: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1F937E: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
loc_1F9380:
	// 0x1F9380: lea ebx, [edx+0x240]
	ctx.ebx = ctx.edx + 0x240u;
	// 0x1F9386: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F9388: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x1F938A: mov ecx, 0x0C
	ctx.ecx = 12;
	// 0x1F938F: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1F9391: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9392: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1F9394: lea ecx, [edx+0xC0]
	ctx.ecx = ctx.edx + 0xC0u;
	// 0x1F939A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F939B: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x1F939E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F939F:
	// 0x1F939F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93A0: add edx, 0x15C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(348);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)348, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F93A6: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93A7: call 0x00201EC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201EC0(ctx, base);
	ctx.esp += 4;
	// 0x1F93AC: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F93B2: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F93B5: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93B7: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93B9: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93BA: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F93BF: ret
	return;
}

void rwaStreamSetPlayState(X86Context& ctx, uint8_t* base) {
	// 0x1F93C0: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F93C5: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93C7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93C8: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F93CD: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F93D1: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F93D5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93D6: add edx, 0x15C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(348);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)348, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F93DC: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93DD: call 0x00201F90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201F90(ctx, base);
	ctx.esp += 4;
	// 0x1F93E2: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F93E7: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F93EA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93EC: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93EE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F93EF: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F93F4: ret
	return;
}

void sub_1F9400(X86Context& ctx, uint8_t* base) {
	// 0x1F9400: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9404: mov eax, [eax+0x234]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x234u);
	// 0x1F940A: ret
	return;
}

void sub_1F9410(X86Context& ctx, uint8_t* base) {
	// 0x1F9410: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9415: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9417: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9418: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F941D: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9421: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F9424: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F9426: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F942A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F942B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F942C: lea ecx, [eax+0x154]
	ctx.ecx = ctx.eax + 0x154u;
	// 0x1F9432: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9433: add eax, 0x15C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(348);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)348, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9438: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9439: call 0x00201F20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201F20(ctx, base);
	ctx.esp += 4;
	// 0x1F943E: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9444: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9447: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9449: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F944B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F944C: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9451: ret
	return;
}

void sub_1F9460(X86Context& ctx, uint8_t* base) {
	// 0x1F9460: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9465: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9467: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9468: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F946D: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9471: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9475: lea ecx, [eax+0x154]
	ctx.ecx = ctx.eax + 0x154u;
	// 0x1F947B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F947C: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F947D: add eax, 0x15C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(348);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)348, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9482: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9483: call 0x00201F00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201F00(ctx, base);
	ctx.esp += 4;
	// 0x1F9488: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F948D: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9490: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9492: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9494: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9495: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F949A: ret
	return;
}

void sub_1F94A0(X86Context& ctx, uint8_t* base) {
	// 0x1F94A0: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F94A5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94A6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94A7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94A8: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94AA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94AB: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F94AD: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F94B2: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F94B6: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F94B9: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F94BA: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F94BE: mov ebx, [ecx+0x100]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x100u);
	// 0x1F94C4: jz 0x001F94DE
	if (ctx.flags.zf) goto loc_1F94DE;
	// 0x1F94C6: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F94C7: jz 0x001F94D0
	if (ctx.flags.zf) goto loc_1F94D0;
	// 0x1F94C9: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F94CA: jnz 0x001F94EF
	if (!ctx.flags.zf) goto loc_1F94EF;
	// 0x1F94CC: mov edi, [esi]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F94CE: jmp 0x001F94EF
	goto loc_1F94EF;
loc_1F94D0:
	// 0x1F94D0: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F94D2: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94D3: lea eax, [ebx+0x5C]
	ctx.eax = ctx.ebx + 0x5Cu;
	// 0x1F94D6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94D7: call 0x002025B0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_2025B0(ctx, base);
	ctx.esp += 4;
	// 0x1F94DC: jmp 0x001F94EA
	goto loc_1F94EA;
loc_1F94DE:
	// 0x1F94DE: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F94E0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94E1: lea edx, [ebx+0x5C]
	ctx.edx = ctx.ebx + 0x5Cu;
	// 0x1F94E4: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94E5: call 0x00202610
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_202610(ctx, base);
	ctx.esp += 4;
loc_1F94EA:
	// 0x1F94EA: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F94ED: mov edi, eax
	ctx.edi = ctx.eax;
loc_1F94EF:
	// 0x1F94EF: mov eax, [ebx+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x58u);
	// 0x1F94F2: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94F4: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94F5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F94F6: call 0x00202270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_202270(ctx, base);
	ctx.esp += 4;
	// 0x1F94FB: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F94FD: mov edx, [ecx+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x1F9500: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x1F9502: shl eax, 0x05
	{ auto _cnt = 0x5u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9505: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9508: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F950A: jz 0x001F95A5
	if (ctx.flags.zf) goto loc_1F95A5;
	// 0x1F9510: mov edx, [ecx+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x1F9513: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1F9515: jz 0x001F95A5
	if (ctx.flags.zf) goto loc_1F95A5;
	// 0x1F951B: mov edx, [eax+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F951E: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F9520: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x1F9523: mov edx, [ecx+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x1F9526: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1F9528: mov [esi+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.edx);
	// 0x1F952B: mov dword ptr [esi+0x04], 0x03
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 3);
	// 0x1F9532: mov eax, [ecx+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x1F9535: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x1F9538: test byte ptr [eax+0x18], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x18u) & 4, 8);
	// 0x1F953C: mov edi, 0x01
	ctx.edi = 1;
	// 0x1F9541: jnz 0x001F9547
	if (!ctx.flags.zf) goto loc_1F9547;
	// 0x1F9543: movzx edi, byte ptr [eax+0x0D]
	ctx.edi = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0xDu));
loc_1F9547:
	// 0x1F9547: mov edx, [ecx+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x1F954A: mov eax, [edx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x1F954D: imul eax, [esi+0x08]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x1F9551: movzx ebx, word ptr [edx+0x1A]
	ctx.ebx = (uint32_t)(X86_MEM_READ_u16(base, ctx.edx + 0x1Au));
	// 0x1F9555: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9557: div ebx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ebx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1F9559: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F955B: div edi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.edi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1F955D: mov edx, [esi+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1F9560: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1F9561: mov [esi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.eax);
	// 0x1F9564: jnz 0x001F9591
	if (!ctx.flags.zf) goto loc_1F9591;
	// 0x1F9566: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9568: mov [esp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.eax);
	// 0x1F956C: fild [esp+0x10]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)));
	// 0x1F9570: jnl 0x001F9578
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1F9578;
	// 0x1F9572: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1F9578:
	// 0x1F9578: mov ecx, [ecx+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x18u);
	// 0x1F957B: mov edx, [ecx+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x14u);
	// 0x1F957E: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1F9580: fild [edx]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.edx)));
	// 0x1F9582: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9584: jnl 0x001F958C
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1F958C;
	// 0x1F9586: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1F958C:
	// 0x1F958C: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1F958E: fstp [esi+0x08]
	X86_MEM_WRITE_F32(base, ctx.esi + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_1F9591:
	// 0x1F9591: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9597: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9599: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F959B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F959C: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F95A1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F95A2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F95A3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F95A4: ret
	return;
loc_1F95A5:
	// 0x1F95A5: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95A7: mov dword ptr [esi+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 0);
	// 0x1F95AE: mov dword ptr [esi+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, 0);
	// 0x1F95B5: mov dword ptr [esi+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, 0);
	// 0x1F95BC: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F95C2: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95C4: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95C5: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F95CA: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F95CB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F95CC: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F95CD: ret
	return;
}

void sub_1F95D0(X86Context& ctx, uint8_t* base) {
	// 0x1F95D0: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F95D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95D6: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95D8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95D9: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F95DE: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F95E2: mov eax, [ecx+0x100]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x100u);
	// 0x1F95E8: mov edx, [eax+0x58]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x58u);
	// 0x1F95EB: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95ED: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95EE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F95EF: call 0x00202270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_202270(ctx, base);
	ctx.esp += 4;
	// 0x1F95F4: mov edx, [esp+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F95F8: mov esi, [eax+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x1F95FB: mov ecx, [edx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1F95FE: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9601: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9603: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9604: jnb 0x001F964C
	if (!ctx.flags.cf) goto loc_1F964C;
	// 0x1F9606: mov eax, [eax+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x1F9609: lea ecx, [ecx+ecx*4]
	ctx.ecx = ctx.ecx + ctx.ecx * 4;
	// 0x1F960C: lea eax, [eax+ecx*8]
	ctx.eax = ctx.eax + ctx.ecx * 8;
	// 0x1F960F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9611: jz 0x001F964C
	if (ctx.flags.zf) goto loc_1F964C;
	// 0x1F9613: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x1F9616: test byte ptr [eax+0x18], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x18u) & 4, 8);
	// 0x1F961A: jz 0x001F9634
	if (ctx.flags.zf) goto loc_1F9634;
	// 0x1F961C: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9621: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9623: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
	// 0x1F9626: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F962C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F962D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F962E: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9633: ret
	return;
loc_1F9634:
	// 0x1F9634: movzx eax, byte ptr [eax+0x0D]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0xDu));
	// 0x1F9638: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F963A: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
	// 0x1F963D: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9643: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9645: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9646: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F964B: ret
	return;
loc_1F964C:
	// 0x1F964C: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F964E: mov dword ptr [edx+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, 0);
	// 0x1F9655: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F965B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F965D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F965E: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9663: ret
	return;
}

void sub_1F9670(X86Context& ctx, uint8_t* base) {
	// 0x1F9670: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9674: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9675: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9679: lea ecx, [eax+0x154]
	ctx.ecx = ctx.eax + 0x154u;
	// 0x1F967F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9680: add eax, 0xEC
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(236);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)236, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9685: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9686: call 0x00200CD0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_200CD0(ctx, base);
	ctx.esp += 4;
	// 0x1F968B: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F968E: ret
	return;
}

void sub_1F9690(X86Context& ctx, uint8_t* base) {
	// 0x1F9690: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9694: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9695: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9699: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F969A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F969B: call 0x001F9170
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9170(ctx, base);
	ctx.esp += 4;
	// 0x1F96A0: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F96A3: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F96A5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F96A6: ret
	return;
}

void sub_1F96B0(X86Context& ctx, uint8_t* base) {
	// 0x1F96B0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F96B4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96B5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F96B9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96BA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96BB: call 0x001F9220
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9220(ctx, base);
	ctx.esp += 4;
	// 0x1F96C0: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F96C3: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F96C5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F96C6: ret
	return;
}

void sub_1F96D0(X86Context& ctx, uint8_t* base) {
	// 0x1F96D0: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F96D6: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F96DA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96DB: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F96DD: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96DF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96E0: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F96E5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96E6: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F96EA: lea edx, [esi+0x15C]
	ctx.edx = ctx.esi + 0x15Cu;
	// 0x1F96F0: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F96F1: call 0x00201F80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaStreamContainerCommandSetLoopSegment(ctx, base);
	ctx.esp += 4;
	// 0x1F96F6: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F96FB: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F96FE: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9700: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9702: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9703: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9708: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F970A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F970B: ret
	return;
}

void sub_1F9710(X86Context& ctx, uint8_t* base) {
	// 0x1F9710: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9714: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9715: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9719: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F971A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F971B: call 0x001F9350
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9350(ctx, base);
	ctx.esp += 4;
	// 0x1F9720: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9723: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9725: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9726: ret
	return;
}

void sub_1F9730(X86Context& ctx, uint8_t* base) {
	// 0x1F9730: mov ecx, [0x0076411C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9736: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F973A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F973B: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F973D: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F973F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9740: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F9745: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9746: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F974A: lea edx, [esi+0x15C]
	ctx.edx = ctx.esi + 0x15Cu;
	// 0x1F9750: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9751: call 0x00201F90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201F90(ctx, base);
	ctx.esp += 4;
	// 0x1F9756: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F975B: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F975E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9760: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9762: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9763: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9768: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F976A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F976B: ret
	return;
}

void sub_1F9770(X86Context& ctx, uint8_t* base) {
	// 0x1F9770: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9774: mov ecx, [eax+0x234]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x234u);
	// 0x1F977A: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F977E: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F9780: ret
	return;
}

void sub_1F9790(X86Context& ctx, uint8_t* base) {
	// 0x1F9790: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9794: mov ecx, [eax+0x238]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x238u);
	// 0x1F979A: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F979E: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F97A0: ret
	return;
}

void sub_1F97B0(X86Context& ctx, uint8_t* base) {
	// 0x1F97B0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F97B4: mov ecx, [eax+0x23C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x23Cu);
	// 0x1F97BA: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F97BE: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F97C0: ret
	return;
}

void sub_1F97D0(X86Context& ctx, uint8_t* base) {
	// 0x1F97D0: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F97D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97D6: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97D8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97D9: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F97DE: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F97E2: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1F97E5: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F97E7: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F97EB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97EC: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97ED: lea eax, [esi+0x154]
	ctx.eax = ctx.esi + 0x154u;
	// 0x1F97F3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97F4: lea ecx, [esi+0x15C]
	ctx.ecx = ctx.esi + 0x15Cu;
	// 0x1F97FA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F97FB: call 0x00201F20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201F20(ctx, base);
	ctx.esp += 4;
	// 0x1F9800: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9806: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9809: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F980B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F980D: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F980E: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9813: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9815: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9816: ret
	return;
}

void sub_1F9820(X86Context& ctx, uint8_t* base) {
	// 0x1F9820: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9824: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F9826: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F982A: mov edx, [eax+edx*4+0x174]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + ctx.edx * 4 + 0x174u);
	// 0x1F9831: mov [ecx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.edx);
	// 0x1F9834: ret
	return;
}

void sub_1F9840(X86Context& ctx, uint8_t* base) {
	// 0x1F9840: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9844: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F984A: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F984C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F984D: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F984F: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9850: mov [esp+0x18], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.ecx);
	// 0x1F9854: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F9859: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F985D: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F9861: lea eax, [esi+0x154]
	ctx.eax = ctx.esi + 0x154u;
	// 0x1F9867: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9868: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9869: lea edx, [esi+0x15C]
	ctx.edx = ctx.esi + 0x15Cu;
	// 0x1F986F: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9870: call 0x00201F00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_201F00(ctx, base);
	ctx.esp += 4;
	// 0x1F9875: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F987A: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F987D: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F987F: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9881: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9882: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F9887: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9889: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F988A: ret
	return;
}

void sub_1F9890(X86Context& ctx, uint8_t* base) {
	// 0x1F9890: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1F9894: mov ecx, [eax+0x120]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x120u);
	// 0x1F989A: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F989E: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1F98A0: ret
	return;
}

void sub_1F98B0(X86Context& ctx, uint8_t* base) {
	// 0x1F98B0: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F98B5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98B6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98B7: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98B9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98BA: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1F98BF: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F98C3: mov eax, [esi+0x100]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x100u);
	// 0x1F98C9: mov ecx, [eax+0x58]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x58u);
	// 0x1F98CC: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98CE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98CF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98D0: call 0x00202270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_202270(ctx, base);
	ctx.esp += 4;
	// 0x1F98D5: mov edx, [0x0076411C]
	ctx.edx = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F98DB: mov edi, [eax+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1F98DE: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F98E1: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98E3: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98E5: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F98E6: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1F98EB: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1F98EF: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1F98F1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F98F2: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F98F4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F98F5: ret
	return;
}

void sub_1F9900(X86Context& ctx, uint8_t* base) {
	// 0x1F9900: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9904: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9905: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9909: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F990A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F990B: call 0x001F94A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F94A0(ctx, base);
	ctx.esp += 4;
	// 0x1F9910: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9913: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9915: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9916: ret
	return;
}

void sub_1F9920(X86Context& ctx, uint8_t* base) {
	// 0x1F9920: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9924: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9925: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9929: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F992A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F992B: call 0x001F95D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F95D0(ctx, base);
	ctx.esp += 4;
	// 0x1F9930: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9933: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9935: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9936: ret
	return;
}

void sub_1F9940(X86Context& ctx, uint8_t* base) {
	// 0x1F9940: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9944: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9945: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9949: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F994A: lea ecx, [esi+0x154]
	ctx.ecx = ctx.esi + 0x154u;
	// 0x1F9950: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9951: lea edx, [esi+0xEC]
	ctx.edx = ctx.esi + 0xECu;
	// 0x1F9957: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9958: call 0x00200CD0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_200CD0(ctx, base);
	ctx.esp += 4;
	// 0x1F995D: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9960: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9962: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9963: ret
	return;
}

void sub_1F9970(X86Context& ctx, uint8_t* base) {
	// 0x1F9970: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9971: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9973: push 0x36DBC8
	{ auto _pv = (uint32_t)(3595208); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9978: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9979: call 0x001F8550
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1F997E: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9980: mov dword ptr [esi+0x40], 0x24C
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, 588);
	// 0x1F9987: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F998C: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9991: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9994: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9996: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9998: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F999B: jz 0x001F99B5
	if (ctx.flags.zf) goto loc_1F99B5;
	// 0x1F999D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F999F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F99A4: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F99A9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F99AC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F99AE: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F99B0: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F99B3: jmp 0x001F99BA
	goto loc_1F99BA;
loc_1F99B5:
	// 0x1F99B5: mov eax, 0x01
	ctx.eax = 1;
loc_1F99BA:
	// 0x1F99BA: test eax, 0xFFFF0000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & -65536, 32);
	// 0x1F99BF: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F99C1: jz 0x001F9ABD
	if (ctx.flags.zf) goto loc_1F9ABD;
	// 0x1F99C7: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F99CC: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F99D1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F99D4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F99D6: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F99D8: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F99DB: jz 0x001F99F8
	if (ctx.flags.zf) goto loc_1F99F8;
	// 0x1F99DD: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F99DF: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F99E4: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F99E9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F99EC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F99EE: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F99F0: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F99F3: mov [esp], eax
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.eax);
	// 0x1F99F6: jmp 0x001F99FF
	goto loc_1F99FF;
loc_1F99F8:
	// 0x1F99F8: mov dword ptr [esp], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp, 1);
loc_1F99FF:
	// 0x1F99FF: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9A01: mov ch, [esp+0x03]
	X86_REG8H(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esp + 0x3u);
	// 0x1F9A05: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9A07: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1F9A09: jz 0x001F9A66
	if (ctx.flags.zf) goto loc_1F9A66;
	// 0x1F9A0B: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9A10: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9A15: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9A18: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9A1A: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9A1C: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F9A1F: jz 0x001F9A4C
	if (ctx.flags.zf) goto loc_1F9A4C;
	// 0x1F9A21: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9A23: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9A28: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9A2D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9A30: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9A32: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9A34: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F9A37: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9A3A: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9A41: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9A44: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9A47: jmp 0x001F9B81
	goto loc_1F9B81;
loc_1F9A4C:
	// 0x1F9A4C: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9A51: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9A54: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9A5B: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9A5E: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9A61: jmp 0x001F9B81
	goto loc_1F9B81;
loc_1F9A66:
	// 0x1F9A66: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9A6B: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9A70: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9A73: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9A75: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9A77: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F9A7A: jz 0x001F9AA5
	if (ctx.flags.zf) goto loc_1F9AA5;
	// 0x1F9A7C: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9A7E: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9A83: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9A88: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9A8B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9A8D: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9A8F: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F9A92: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9A95: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9A9C: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9A9D: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9AA0: jmp 0x001F9B81
	goto loc_1F9B81;
loc_1F9AA5:
	// 0x1F9AA5: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9AAA: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9AAD: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9AB4: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9AB5: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9AB8: jmp 0x001F9B81
	goto loc_1F9B81;
loc_1F9ABD:
	// 0x1F9ABD: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9AC2: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9AC7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9ACA: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9ACC: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9ACE: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F9AD1: jz 0x001F9AEB
	if (ctx.flags.zf) goto loc_1F9AEB;
	// 0x1F9AD3: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9AD5: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9ADA: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9ADF: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9AE2: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9AE4: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9AE6: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F9AE9: jmp 0x001F9AF0
	goto loc_1F9AF0;
loc_1F9AEB:
	// 0x1F9AEB: mov eax, 0x01
	ctx.eax = 1;
loc_1F9AF0:
	// 0x1F9AF0: test ah, 0xFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & -1, 8);
	// 0x1F9AF3: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9AF5: jz 0x001F9B46
	if (ctx.flags.zf) goto loc_1F9B46;
	// 0x1F9AF7: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9AFC: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9B01: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9B04: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9B06: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9B08: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F9B0B: jz 0x001F9B32
	if (ctx.flags.zf) goto loc_1F9B32;
	// 0x1F9B0D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9B0F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9B14: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9B19: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9B1C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9B1E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9B20: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F9B23: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9B26: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9B2D: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9B30: jmp 0x001F9B81
	goto loc_1F9B81;
loc_1F9B32:
	// 0x1F9B32: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9B37: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9B3A: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9B41: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9B44: jmp 0x001F9B81
	goto loc_1F9B81;
loc_1F9B46:
	// 0x1F9B46: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9B4B: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9B50: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9B53: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9B55: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9B57: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1F9B5A: jz 0x001F9B74
	if (ctx.flags.zf) goto loc_1F9B74;
	// 0x1F9B5C: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9B5E: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1F9B63: mov edx, 0x01
	ctx.edx = 1;
	// 0x1F9B68: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9B6B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1F9B6D: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1F9B6F: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1F9B72: jmp 0x001F9B79
	goto loc_1F9B79;
loc_1F9B74:
	// 0x1F9B74: mov eax, 0x01
	ctx.eax = 1;
loc_1F9B79:
	// 0x1F9B79: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1F9B80: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_1F9B81:
	// 0x1F9B81: mov edx, [esi+0x40]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1F9B84: shl eax, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9B87: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9B89: or edx, eax
	ctx.edx = ctx.edx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x1F9B8B: mov eax, 0x764128
	ctx.eax = 7749928;
	// 0x1F9B90: mov [esi+0x40], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.edx);
	// 0x1F9B93: mov dword ptr [esi+0x28], 0x1F90B0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 2068656);
	// 0x1F9B9A: mov dword ptr [esi+0x34], 0x1F90F0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, 2068720);
	// 0x1F9BA1: mov dword ptr [esi+0x30], 0x1F9130
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 2068784);
	// 0x1F9BA8: mov dword ptr [esi+0x3C], 0x1F9150
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, 2068816);
	// 0x1F9BAF: mov word ptr [esi+0x44], 0x0C
	X86_MEM_WRITE_u16(base, ctx.esi + 0x44u, 12);
	// 0x1F9BB5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9BB7: push 0x76411C
	{ auto _pv = (uint32_t)(7749916); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9BBC: mov [0x00764128], eax
	X86_MEM_WRITE_u32(base, 0x764128u, ctx.eax);
	// 0x1F9BC1: mov [0x0076412C], eax
	X86_MEM_WRITE_u32(base, 0x76412Cu, ctx.eax);
	// 0x1F9BC6: call 0x00204630
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSemaphoreCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F9BCB: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9BCE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9BD0: jz 0x001F9BFE
	if (ctx.flags.zf) goto loc_1F9BFE;
	// 0x1F9BD2: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9BD4: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9BD6: push 0x764130
	{ auto _pv = (uint32_t)(7749936); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9BDB: call 0x00204630
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSemaphoreCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F9BE0: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9BE3: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9BE5: jz 0x001F9BF3
	if (ctx.flags.zf) goto loc_1F9BF3;
	// 0x1F9BE7: mov dword ptr [0x00764120], 0x00
	X86_MEM_WRITE_u32(base, 0x764120u, 0);
	// 0x1F9BF1: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9BF2: ret
	return;
loc_1F9BF3:
	// 0x1F9BF3: mov eax, [0x0076411C]
	ctx.eax = X86_MEM_READ_u32(base, 0x76411Cu);
	// 0x1F9BF8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9BF9: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
loc_1F9BFE:
	// 0x1F9BFE: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9BFF: ret
	return;
}

void sub_1F9C00(X86Context& ctx, uint8_t* base) {
	// 0x1F9C00: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C01: push 0x3080F
	{ auto _pv = (uint32_t)(198671); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C06: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C08: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C0A: push 0x41B6E0
	{ auto _pv = (uint32_t)(4306656); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C0F: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C11: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C13: push 0x36EA28
	{ auto _pv = (uint32_t)(3598888); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C18: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C1A: call 0x001F8B10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8B10(ctx, base);
	ctx.esp += 4;
	// 0x1F9C1F: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9C22: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C23: call 0x001F8E20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F9C28: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F9C2A: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9C2D: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F9C2F: jnz 0x001F9C33
	if (!ctx.flags.zf) goto loc_1F9C33;
	// 0x1F9C31: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9C32: ret
	return;
loc_1F9C33:
	// 0x1F9C33: call 0x001F9970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9970(ctx, base);
	ctx.esp += 4;
	// 0x1F9C38: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9C3A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9C3B: ret
	return;
}

void RwaSPU2VoiceRegisterUsingInterface(X86Context& ctx, uint8_t* base) {
	// 0x1F9C40: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C41: push 0x3080F
	{ auto _pv = (uint32_t)(198671); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C46: push 0x41B6C0
	{ auto _pv = (uint32_t)(4306624); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C4B: push 0x41B6C8
	{ auto _pv = (uint32_t)(4306632); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C50: push 0x41B6E0
	{ auto _pv = (uint32_t)(4306656); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C55: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C57: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C59: push 0x36EA28
	{ auto _pv = (uint32_t)(3598888); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C5E: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C60: call 0x001F8B10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8B10(ctx, base);
	ctx.esp += 4;
	// 0x1F9C65: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9C68: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C69: call 0x001F8E20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F9C6E: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1F9C70: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9C73: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F9C75: jz 0x001F9CA0
	if (ctx.flags.zf) goto loc_1F9CA0;
	// 0x1F9C77: call 0x001F9970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9970(ctx, base);
	ctx.esp += 4;
	// 0x1F9C7C: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C7E: push 0x3C1490
	{ auto _pv = (uint32_t)(3937424); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C83: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C85: push 0x3C1400
	{ auto _pv = (uint32_t)(3937280); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C8A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C8B: call 0x001F8B70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8B70(ctx, base);
	ctx.esp += 4;
	// 0x1F9C90: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9C93: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9C95: jnz 0x001F9CA4
	if (!ctx.flags.zf) goto loc_1F9CA4;
	// 0x1F9C97: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9C98: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F9C9D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9CA0:
	// 0x1F9CA0: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9CA2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9CA3: ret
	return;
loc_1F9CA4:
	// 0x1F9CA4: push 0x36E290
	{ auto _pv = (uint32_t)(3596944); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CA9: call 0x001FD6C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD6C0(ctx, base);
	ctx.esp += 4;
	// 0x1F9CAE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CAF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CB0: call 0x001F8520
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8520(ctx, base);
	ctx.esp += 4;
	// 0x1F9CB5: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9CB8: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1F9CBA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9CBB: ret
	return;
}

void _rwaWaveDefOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1F9CC0: push 0x40805
	{ auto _pv = (uint32_t)(264197); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CC5: push 0x41B744
	{ auto _pv = (uint32_t)(4306756); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CCA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CCC: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CCE: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CD0: push 0x6C
	{ auto _pv = (uint32_t)(108); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9CD2: mov dword ptr [0x0041B768], 0x01
	X86_MEM_WRITE_u32(base, 0x41B768u, 1);
	// 0x1F9CDC: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1F9CE1: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9CE4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9CE6: jz 0x001F9CEE
	if (ctx.flags.zf) goto loc_1F9CEE;
	// 0x1F9CE8: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9CED: ret
	return;
loc_1F9CEE:
	// 0x1F9CEE: mov dword ptr [0x0041B768], 0x00
	X86_MEM_WRITE_u32(base, 0x41B768u, 0);
	// 0x1F9CF8: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9CFA: ret
	return;
}

void sub_1F9D00(X86Context& ctx, uint8_t* base) {
	// 0x1F9D00: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D01: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D02: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D03: call 0x001F64A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F64A0(ctx, base);
	ctx.esp += 4;
	// 0x1F9D08: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1F9D0A: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9D0C: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1F9D0E: mov [esp+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.edi);
	// 0x1F9D12: jbe 0x001F9D6D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1F9D6D;
	// 0x1F9D14: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D15: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_1F9D16:
	// 0x1F9D16: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D17: call 0x001F6470
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6470(ctx, base);
	ctx.esp += 4;
	// 0x1F9D1C: mov esi, [eax+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1F9D1F: lea ebx, [eax+0x0C]
	ctx.ebx = ctx.eax + 0xCu;
	// 0x1F9D22: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9D25: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9D27: jz 0x001F9D66
	if (ctx.flags.zf) goto loc_1F9D66;
	// 0x1F9D29: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_1F9D30:
	// 0x1F9D30: mov edi, [esi+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x1F9D33: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1F9D37: mov ecx, [edi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x1F9D3A: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1F9D3C: mov esi, [esi+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9D3F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D40: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D41: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9D46: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9D49: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9D4B: jnz 0x001F9D5E
	if (!ctx.flags.zf) goto loc_1F9D5E;
	// 0x1F9D4D: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1F9D51: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D52: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D53: call [esp+0x24]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1F9D57: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9D5A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9D5C: jz 0x001F9D62
	if (ctx.flags.zf) goto loc_1F9D62;
loc_1F9D5E:
	// 0x1F9D5E: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9D60: jnz 0x001F9D30
	if (!ctx.flags.zf) goto loc_1F9D30;
loc_1F9D62:
	// 0x1F9D62: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
loc_1F9D66:
	// 0x1F9D66: inc ebp
	{ uint32_t _d = ctx.ebp;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x1F9D67: cmp ebp, edi
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9D69: jb 0x001F9D16
	if (ctx.flags.cf) goto loc_1F9D16;
	// 0x1F9D6B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9D6C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1F9D6D:
	// 0x1F9D6D: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F9D71: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9D72: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9D73: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9D74: ret
	return;
}

void sub_1F9D80(X86Context& ctx, uint8_t* base) {
	// 0x1F9D80: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D81: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9D85: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9D88: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D89: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9D8D: mov ecx, [edi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x1F9D90: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D91: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9D92: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9D97: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9D9A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9D9C: jnz 0x001F9DCE
	if (!ctx.flags.zf) goto loc_1F9DCE;
	// 0x1F9D9E: mov edx, [edi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1F9DA0: cmp edx, [esi]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9DA2: jnz 0x001F9DCE
	if (!ctx.flags.zf) goto loc_1F9DCE;
	// 0x1F9DA4: mov al, [edi+0x0C]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0xCu);
	// 0x1F9DA7: cmp al, [esi+0x0C]
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1F9DAA: jnz 0x001F9DCE
	if (!ctx.flags.zf) goto loc_1F9DCE;
	// 0x1F9DAC: mov cl, [edi+0x0D]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi + 0xDu);
	// 0x1F9DAF: cmp cl, [esi+0x0D]
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0xDu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1F9DB2: jnz 0x001F9DCE
	if (!ctx.flags.zf) goto loc_1F9DCE;
	// 0x1F9DB4: movzx edx, byte ptr [edi+0x18]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + 0x18u));
	// 0x1F9DB8: movzx eax, byte ptr [esi+0x18]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x18u));
	// 0x1F9DBC: xor edx, eax
	ctx.edx = ctx.edx ^ ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32);
	// 0x1F9DBE: test edx, 0xFFFFFFFD
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & -3, 32);
	// 0x1F9DC4: jnz 0x001F9DCE
	if (!ctx.flags.zf) goto loc_1F9DCE;
	// 0x1F9DC6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9DC7: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9DCC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9DCD: ret
	return;
loc_1F9DCE:
	// 0x1F9DCE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9DCF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9DD1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9DD2: ret
	return;
}

void RwaWaveFormatGetFrameSize(X86Context& ctx, uint8_t* base) {
	// 0x1F9DE0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9DE1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9DE5: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9DE8: push 0x36DBE8
	{ auto _pv = (uint32_t)(3595240); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9DED: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9DEE: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9DF3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9DF6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9DF8: jnz 0x001F9E03
	if (!ctx.flags.zf) goto loc_1F9E03;
	// 0x1F9DFA: movzx eax, byte ptr [esi+0x0C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0xCu));
	// 0x1F9DFE: shr eax, 0x03
	{ auto _cnt = 0x3u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9E01: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9E02: ret
	return;
loc_1F9E03:
	// 0x1F9E03: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9E06: push 0x36DBD8
	{ auto _pv = (uint32_t)(3595224); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E0B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E0C: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9E11: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9E14: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E16: jnz 0x001F9E1F
	if (!ctx.flags.zf) goto loc_1F9E1F;
	// 0x1F9E18: mov eax, 0x10
	ctx.eax = 16;
	// 0x1F9E1D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9E1E: ret
	return;
loc_1F9E1F:
	// 0x1F9E1F: mov edx, [esi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9E22: push 0x36DBF8
	{ auto _pv = (uint32_t)(3595256); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E27: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E28: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9E2D: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9E30: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E32: jnz 0x001F9E3B
	if (!ctx.flags.zf) goto loc_1F9E3B;
	// 0x1F9E34: mov eax, 0x04
	ctx.eax = 4;
	// 0x1F9E39: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9E3A: ret
	return;
loc_1F9E3B:
	// 0x1F9E3B: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9E3E: push 0x36DC08
	{ auto _pv = (uint32_t)(3595272); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E43: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E44: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9E49: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9E4C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E4E: jnz 0x001F9E57
	if (!ctx.flags.zf) goto loc_1F9E57;
	// 0x1F9E50: mov eax, 0x08
	ctx.eax = 8;
	// 0x1F9E55: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9E56: ret
	return;
loc_1F9E57:
	// 0x1F9E57: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9E5A: push 0x36DC18
	{ auto _pv = (uint32_t)(3595288); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E5F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E60: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9E65: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9E68: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E6A: jz 0x001F9EC1
	if (ctx.flags.zf) goto loc_1F9EC1;
	// 0x1F9E6C: mov edx, [esi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9E6F: push 0x36DC78
	{ auto _pv = (uint32_t)(3595384); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E74: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E75: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9E7A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9E7D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E7F: jz 0x001F9EC1
	if (ctx.flags.zf) goto loc_1F9EC1;
	// 0x1F9E81: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1F9E84: push 0x36DC38
	{ auto _pv = (uint32_t)(3595320); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E89: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9E8A: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9E8F: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9E92: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E94: jnz 0x001F9EBD
	if (!ctx.flags.zf) goto loc_1F9EBD;
	// 0x1F9E96: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F9E99: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9E9B: jz 0x001F9EA1
	if (ctx.flags.zf) goto loc_1F9EA1;
	// 0x1F9E9D: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1F9E9F: jmp 0x001F9EA6
	goto loc_1F9EA6;
loc_1F9EA1:
	// 0x1F9EA1: mov eax, 0x1F400
	ctx.eax = 128000;
loc_1F9EA6:
	// 0x1F9EA6: mov esi, [esi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F9EA8: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1F9EAA: jnz 0x001F9EB1
	if (!ctx.flags.zf) goto loc_1F9EB1;
	// 0x1F9EAC: mov esi, 0xBB80
	ctx.esi = 48000;
loc_1F9EB1:
	// 0x1F9EB1: lea eax, [eax+eax*8]
	ctx.eax = ctx.eax + ctx.eax * 8;
	// 0x1F9EB4: shl eax, 0x04
	{ auto _cnt = 0x4u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1F9EB7: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9EB9: div esi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.esi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1F9EBB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9EBC: ret
	return;
loc_1F9EBD:
	// 0x1F9EBD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9EBF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9EC0: ret
	return;
loc_1F9EC1:
	// 0x1F9EC1: mov al, [esi+0x0D]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0xDu);
	// 0x1F9EC4: dec al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x1F9EC6: neg al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint8_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int8_t)0, (int8_t)_d, 8);
	  ctx.flags.cf = (_d != 0);
	  X86_REG8L(ctx.eax) = _res; }
	// 0x1F9EC8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9EC9: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9ECB: and eax, 0xFFFFFFE0
	ctx.eax = ctx.eax & -32;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F9ECE: add eax, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)36, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9ED1: ret
	return;
}

void sub_1F9EE0(X86Context& ctx, uint8_t* base) {
	// 0x1F9EE0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9EE1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9EE5: mov al, [esi+0x18]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x18u);
	// 0x1F9EE8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9EE9: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9EEB: test al, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 2, 8);
	// 0x1F9EED: jnz 0x001F9EFF
	if (!ctx.flags.zf) goto loc_1F9EFF;
	// 0x1F9EEF: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1F9EF2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9EF4: jz 0x001F9EFF
	if (ctx.flags.zf) goto loc_1F9EFF;
	// 0x1F9EF6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9EF7: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1F9EFC: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9EFF:
	// 0x1F9EFF: mov [esi+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.edi);
	// 0x1F9F02: mov [esi+0x14], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.edi);
	// 0x1F9F05: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9F06: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9F07: ret
	return;
}

void sub_1F9F10(X86Context& ctx, uint8_t* base) {
	// 0x1F9F10: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9F14: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F15: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9F19: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F1A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F1B: call 0x001FE4C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDAssignUUID(ctx, base);
	ctx.esp += 4;
	// 0x1F9F20: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9F23: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9F25: jnz 0x001F9F29
	if (!ctx.flags.zf) goto loc_1F9F29;
	// 0x1F9F27: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9F28: ret
	return;
loc_1F9F29:
	// 0x1F9F29: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1F9F2D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F2E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F2F: call 0x001FE480
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDAssignName(ctx, base);
	ctx.esp += 4;
	// 0x1F9F34: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9F37: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1F9F39: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1F9F3B: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1F9F3D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9F3E: ret
	return;
}

void sub_1F9F40(X86Context& ctx, uint8_t* base) {
	// 0x1F9F40: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F41: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1F9F45: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F47: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F48: call 0x001F6550
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6550(ctx, base);
	ctx.esp += 4;
	// 0x1F9F4D: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9F50: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9F52: jz 0x001F9F58
	if (ctx.flags.zf) goto loc_1F9F58;
	// 0x1F9F54: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9F56: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9F57: ret
	return;
loc_1F9F58:
	// 0x1F9F58: mov eax, [esi+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	// 0x1F9F5B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9F5D: jz 0x001F9F65
	if (ctx.flags.zf) goto loc_1F9F65;
	// 0x1F9F5F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F60: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x1F9F62: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9F65:
	// 0x1F9F65: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1F9F68: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9F6A: jz 0x001F9F75
	if (ctx.flags.zf) goto loc_1F9F75;
	// 0x1F9F6C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F6D: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1F9F72: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9F75:
	// 0x1F9F75: test byte ptr [esi+0x58], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x58u) & 1, 8);
	// 0x1F9F79: jz 0x001F9F87
	if (ctx.flags.zf) goto loc_1F9F87;
	// 0x1F9F7B: mov eax, [esi+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1F9F7E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F7F: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1F9F84: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9F87:
	// 0x1F9F87: mov ecx, [esi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1F9F8A: mov edx, [esi+0x50]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F9F8D: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1F9F8F: mov eax, [esi+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1F9F92: mov ecx, [esi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1F9F95: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9F96: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x1F9F99: call 0x001FE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDFreeData(ctx, base);
	ctx.esp += 4;
	// 0x1F9F9E: mov al, [esi+0x58]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x58u);
	// 0x1F9FA1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9FA4: test al, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 2, 8);
	// 0x1F9FA6: jz 0x001F9FB6
	if (ctx.flags.zf) goto loc_1F9FB6;
	// 0x1F9FA8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FA9: push 0x41B744
	{ auto _pv = (uint32_t)(4306756); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FAE: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1F9FB3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1F9FB6:
	// 0x1F9FB6: mov eax, 0x01
	ctx.eax = 1;
	// 0x1F9FBB: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FBC: ret
	return;
}

void sub_1F9FC0(X86Context& ctx, uint8_t* base) {
	// 0x1F9FC0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FC1: mov ebx, [esp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1F9FC5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FC6: add ebx, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)32, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x1F9FC9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FCA: mov esi, [ebx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x1F9FCC: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9FCE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FCF: jz 0x001F9FF2
	if (ctx.flags.zf) goto loc_1F9FF2;
	// 0x1F9FD1: mov ebp, [esp+0x1C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
loc_1F9FD5:
	// 0x1F9FD5: mov eax, [ebp]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x1F9FD8: mov ecx, [esi-0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi - 0x50u);
	// 0x1F9FDB: lea edi, [esi-0x50]
	ctx.edi = ctx.esi - 0x50u;
	// 0x1F9FDE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FDF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1F9FE0: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1F9FE5: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1F9FE8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1F9FEA: jz 0x001F9FF9
	if (ctx.flags.zf) goto loc_1F9FF9;
	// 0x1F9FEC: mov esi, [esi]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1F9FEE: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1F9FF0: jnz 0x001F9FD5
	if (!ctx.flags.zf) goto loc_1F9FD5;
loc_1F9FF2:
	// 0x1F9FF2: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FF3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FF4: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FF5: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1F9FF7: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FF8: ret
	return;
loc_1F9FF9:
	// 0x1F9FF9: mov [ebp+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x4u, ctx.edi);
	// 0x1F9FFC: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FFD: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FFE: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1F9FFF: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FA004: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA005: ret
	return;
}

void sub_1FA010(X86Context& ctx, uint8_t* base) {
	// 0x1FA010: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA014: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA016: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA018: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FA01C: jz 0x001FA038
	if (ctx.flags.zf) goto loc_1FA038;
	// 0x1FA01E: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x1FA020: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x1FA023: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x1FA026: mov [eax+0x0C], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0xCu, X86_REG8L(ctx.edx));
	// 0x1FA029: mov [eax+0x0D], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0xDu, X86_REG8L(ctx.edx));
	// 0x1FA02C: mov [eax+0x18], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x18u, X86_REG8L(ctx.edx));
	// 0x1FA02F: mov [eax+0x19], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x19u, X86_REG8L(ctx.edx));
	// 0x1FA032: mov [eax+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.edx);
	// 0x1FA035: mov [eax+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.edx);
loc_1FA038:
	// 0x1FA038: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FA03C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA03D: mov bl, [ecx+0x04]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.ecx + 0x4u);
	// 0x1FA040: mov [eax+0x0C], bl
	X86_MEM_WRITE_u8(base, ctx.eax + 0xCu, X86_REG8L(ctx.ebx));
	// 0x1FA043: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA044: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FA046: mov [eax+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.esi);
	// 0x1FA049: mov bl, [ecx+0x05]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.ecx + 0x5u);
	// 0x1FA04C: mov [eax+0x18], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x18u, X86_REG8L(ctx.edx));
	// 0x1FA04F: mov [eax+0x0D], bl
	X86_MEM_WRITE_u8(base, ctx.eax + 0xDu, X86_REG8L(ctx.ebx));
	// 0x1FA052: mov bl, [ecx+0x10]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.ecx + 0x10u);
	// 0x1FA055: mov dl, 0x01
	X86_REG8L(ctx.edx) = (uint8_t)(1);
	// 0x1FA057: test dl, bl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.ebx), 8);
	// 0x1FA059: jz 0x001FA05E
	if (ctx.flags.zf) goto loc_1FA05E;
	// 0x1FA05B: mov [eax+0x18], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x18u, X86_REG8L(ctx.edx));
loc_1FA05E:
	// 0x1FA05E: mov bl, [ecx+0x10]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.ecx + 0x10u);
	// 0x1FA061: mov dl, 0x04
	X86_REG8L(ctx.edx) = (uint8_t)(4);
	// 0x1FA063: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA064: test dl, bl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.edx) & X86_REG8L(ctx.ebx), 8);
	// 0x1FA066: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA067: jz 0x001FA06C
	if (ctx.flags.zf) goto loc_1FA06C;
	// 0x1FA069: or [eax+0x18], dl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x18u, X86_MEM_READ_u8(base, ctx.eax + 0x18u) | X86_REG8L(ctx.edx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x18u), 8);
loc_1FA06C:
	// 0x1FA06C: ret
	return;
}

void sub_1FA070(X86Context& ctx, uint8_t* base) {
	// 0x1FA070: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA071: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FA075: mov cl, [esi+0x05]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0x5u);
	// 0x1FA078: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA079: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FA07D: mov al, [edi+0x0D]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0xDu);
	// 0x1FA080: cmp al, cl
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_REG8L(ctx.ecx);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FA082: jnz 0x001FA0BE
	if (!ctx.flags.zf) goto loc_1FA0BE;
	// 0x1FA084: mov cl, [edi+0x0C]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.edi + 0xCu);
	// 0x1FA087: cmp cl, [esi+0x04]
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FA08A: jnz 0x001FA0BE
	if (!ctx.flags.zf) goto loc_1FA0BE;
	// 0x1FA08C: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FA08E: cmp eax, [esi+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA091: jb 0x001FA0BE
	if (ctx.flags.cf) goto loc_1FA0BE;
	// 0x1FA093: cmp eax, [esi+0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA096: jnbe 0x001FA0BE
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_1FA0BE;
	// 0x1FA098: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FA09A: mov eax, [edi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x1FA09D: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA09E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA09F: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA0A4: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA0A7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA0A9: jnz 0x001FA0BE
	if (!ctx.flags.zf) goto loc_1FA0BE;
	// 0x1FA0AB: mov cl, [esi+0x10]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0x10u);
	// 0x1FA0AE: xor cl, [edi+0x18]
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) ^ X86_MEM_READ_u8(base, ctx.edi + 0x18u);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x1FA0B1: test cl, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 1, 8);
	// 0x1FA0B4: jnz 0x001FA0BE
	if (!ctx.flags.zf) goto loc_1FA0BE;
	// 0x1FA0B6: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA0B7: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FA0BC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA0BD: ret
	return;
loc_1FA0BE:
	// 0x1FA0BE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA0BF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA0C1: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA0C2: ret
	return;
}

void sub_1FA0D0(X86Context& ctx, uint8_t* base) {
	// 0x1FA0D0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA0D1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FA0D5: test byte ptr [esi+0x58], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x58u) & 1, 8);
	// 0x1FA0D9: jz 0x001FA0EF
	if (ctx.flags.zf) goto loc_1FA0EF;
	// 0x1FA0DB: mov eax, [esi+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1FA0DE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA0E0: jz 0x001FA0EB
	if (ctx.flags.zf) goto loc_1FA0EB;
	// 0x1FA0E2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA0E3: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FA0E8: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FA0EB:
	// 0x1FA0EB: and dword ptr [esi+0x58], 0xFFFFFFFE
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, X86_MEM_READ_u32(base, ctx.esi + 0x58u) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x58u), 32);
loc_1FA0EF:
	// 0x1FA0EF: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA0F3: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FA0F7: mov [esi+0x38], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.eax);
	// 0x1FA0FA: mov [esi+0x34], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, ctx.ecx);
	// 0x1FA0FD: mov dword ptr [esi+0x3C], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, 0);
	// 0x1FA104: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA105: ret
	return;
}

void sub_1FA110(X86Context& ctx, uint8_t* base) {
	// 0x1FA110: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FA114: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FA117: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1FA119: mov eax, 0x1C
	ctx.eax = 28;
	// 0x1FA11E: jz 0x001FA125
	if (ctx.flags.zf) goto loc_1FA125;
	// 0x1FA120: mov eax, 0x2C
	ctx.eax = 44;
loc_1FA125:
	// 0x1FA125: mov edx, [ecx+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x10u);
	// 0x1FA128: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1FA12A: jz 0x001FA12F
	if (ctx.flags.zf) goto loc_1FA12F;
	// 0x1FA12C: add eax, [ecx+0x14]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x14u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x14u), 32);
	  ctx.eax = (uint32_t)_res; }
loc_1FA12F:
	// 0x1FA12F: ret
	return;
}

void rwaWaveDefIsTargetFormatSupported(X86Context& ctx, uint8_t* base) {
	// 0x1FA130: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FA134: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA135: mov ebp, [eax+0x34]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.eax + 0x34u);
	// 0x1FA138: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA13A: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1FA13C: jz 0x001FA1A8
	if (ctx.flags.zf) goto loc_1FA1A8;
	// 0x1FA13E: mov eax, [eax+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x38u);
	// 0x1FA141: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA142: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA144: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1FA146: mov [esp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.eax);
	// 0x1FA14A: jbe 0x001FA1AF
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FA1AF;
	// 0x1FA14C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA14D: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FA151: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_1FA152:
	// 0x1FA152: mov ecx, [esp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FA156: mov esi, [ecx+ebx*4]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + ctx.ebx * 4);
	// 0x1FA159: mov dl, [edi+0x0D]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.edi + 0xDu);
	// 0x1FA15C: cmp dl, [esi+0x05]
	{ uint8_t _d = X86_REG8L(ctx.edx); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0x5u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FA15F: jnz 0x001FA192
	if (!ctx.flags.zf) goto loc_1FA192;
	// 0x1FA161: mov al, [edi+0x0C]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0xCu);
	// 0x1FA164: cmp al, [esi+0x04]
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = X86_MEM_READ_u8(base, ctx.esi + 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FA167: jnz 0x001FA192
	if (!ctx.flags.zf) goto loc_1FA192;
	// 0x1FA169: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FA16B: cmp eax, [esi+0x08]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA16E: jb 0x001FA192
	if (ctx.flags.cf) goto loc_1FA192;
	// 0x1FA170: cmp eax, [esi+0x0C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA173: jnbe 0x001FA192
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_1FA192;
	// 0x1FA175: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FA177: mov edx, [edi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x1FA17A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA17B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA17C: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA181: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA184: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA186: jnz 0x001FA192
	if (!ctx.flags.zf) goto loc_1FA192;
	// 0x1FA188: mov al, [esi+0x10]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x10u);
	// 0x1FA18B: xor al, [edi+0x18]
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) ^ X86_MEM_READ_u8(base, ctx.edi + 0x18u);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x1FA18E: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1FA190: jz 0x001FA19E
	if (ctx.flags.zf) goto loc_1FA19E;
loc_1FA192:
	// 0x1FA192: inc ebx
	{ uint32_t _d = ctx.ebx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x1FA193: cmp ebx, ebp
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA195: jb 0x001FA152
	if (ctx.flags.cf) goto loc_1FA152;
	// 0x1FA197: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA198: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA199: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA19A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA19C: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA19D: ret
	return;
loc_1FA19E:
	// 0x1FA19E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA19F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1A0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1A1: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FA1A6: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1A7: ret
	return;
loc_1FA1A8:
	// 0x1FA1A8: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FA1AD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1AE: ret
	return;
loc_1FA1AF:
	// 0x1FA1AF: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1B0: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1FA1B2: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1B3: ret
	return;
}

void sub_1FA1C0(X86Context& ctx, uint8_t* base) {
	// 0x1FA1C0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA1C1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA1C2: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA1C6: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA1C8: jmp 0x001FA1D0
	goto loc_1FA1D0;
	// 0x1FA1CA: lea ebx, [ebx]
	ctx.ebx = ctx.ebx;
loc_1FA1D0:
	// 0x1FA1D0: mov eax, [esi*4+0x3C1584]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi * 4 + 0x3C1584u);
	// 0x1FA1D7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA1D8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA1D9: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA1DE: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA1E1: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA1E3: jz 0x001FA1F0
	if (ctx.flags.zf) goto loc_1FA1F0;
	// 0x1FA1E5: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA1E6: cmp esi, 0x09
	{ uint32_t _d = ctx.esi; uint32_t _s = 9;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA1E9: jb 0x001FA1D0
	if (ctx.flags.cf) goto loc_1FA1D0;
	// 0x1FA1EB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1EC: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA1EE: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1EF: ret
	return;
loc_1FA1F0:
	// 0x1FA1F0: mov eax, [esi*4+0x3C1584]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi * 4 + 0x3C1584u);
	// 0x1FA1F7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1F8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA1F9: ret
	return;
}

void sub_1FA200(X86Context& ctx, uint8_t* base) {
	// 0x1FA200: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FA204: mov eax, [eax*4+0x3C1584]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x3C1584u);
	// 0x1FA20B: ret
	return;
}

void RwaWaveFormatGetSamplesPerAudioFrame(X86Context& ctx, uint8_t* base) {
loc_1FA210:
	// 0x1FA210: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA213: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA214: mov ebx, [esp+0x24]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1FA218: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA21B: push 0x36DBE8
	{ auto _pv = (uint32_t)(3595240); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA220: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA221: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA226: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA229: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA22B: jz 0x001FA261
	if (ctx.flags.zf) goto loc_1FA261;
	// 0x1FA22D: mov ecx, [ebx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA230: push 0x36DBD8
	{ auto _pv = (uint32_t)(3595224); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA235: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA236: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA23B: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA23E: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA240: jnz 0x001FA24C
	if (!ctx.flags.zf) goto loc_1FA24C;
	// 0x1FA242: mov eax, 0x1C
	ctx.eax = 28;
	// 0x1FA247: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA248: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA24B: ret
	return;
loc_1FA24C:
	// 0x1FA24C: mov edx, [ebx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA24F: push 0x36DBF8
	{ auto _pv = (uint32_t)(3595256); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA254: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA255: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA25A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA25D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA25F: jnz 0x001FA26B
	if (!ctx.flags.zf) goto loc_1FA26B;
loc_1FA261:
	// 0x1FA261: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FA266: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA267: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA26A: ret
	return;
loc_1FA26B:
	// 0x1FA26B: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA26E: push 0x36DC68
	{ auto _pv = (uint32_t)(3595368); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA273: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA274: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA279: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA27C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA27E: jnz 0x001FA28A
	if (!ctx.flags.zf) goto loc_1FA28A;
	// 0x1FA280: mov eax, 0x600
	ctx.eax = 1536;
	// 0x1FA285: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA286: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA289: ret
	return;
loc_1FA28A:
	// 0x1FA28A: mov ecx, [ebx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA28D: push 0x36DC08
	{ auto _pv = (uint32_t)(3595272); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA292: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA293: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA298: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA29B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA29D: jnz 0x001FA2A9
	if (!ctx.flags.zf) goto loc_1FA2A9;
	// 0x1FA29F: mov eax, 0x0E
	ctx.eax = 14;
	// 0x1FA2A4: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA2A5: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA2A8: ret
	return;
loc_1FA2A9:
	// 0x1FA2A9: mov edx, [ebx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA2AC: push 0x36DC18
	{ auto _pv = (uint32_t)(3595288); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2B1: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2B2: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA2B7: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA2BA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA2BC: jz 0x001FA326
	if (ctx.flags.zf) goto loc_1FA326;
	// 0x1FA2BE: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA2C1: push 0x36DC78
	{ auto _pv = (uint32_t)(3595384); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2C6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2C7: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA2CC: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA2CF: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA2D1: jz 0x001FA326
	if (ctx.flags.zf) goto loc_1FA326;
	// 0x1FA2D3: mov ecx, [ebx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA2D6: push 0x36DC38
	{ auto _pv = (uint32_t)(3595320); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2DB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2DC: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA2E1: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA2E4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA2E6: jz 0x001FA31C
	if (ctx.flags.zf) goto loc_1FA31C;
	// 0x1FA2E8: mov edx, [ebx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA2EB: push 0x36DC48
	{ auto _pv = (uint32_t)(3595336); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2F0: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA2F1: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA2F6: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA2F9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA2FB: jz 0x001FA31C
	if (ctx.flags.zf) goto loc_1FA31C;
	// 0x1FA2FD: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA300: push 0x36DC58
	{ auto _pv = (uint32_t)(3595352); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA305: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA306: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA30B: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA30E: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FA310: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA312: and eax, 0x180
	ctx.eax = ctx.eax & 384;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FA317: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA318: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA31B: ret
	return;
loc_1FA31C:
	// 0x1FA31C: mov eax, 0x480
	ctx.eax = 1152;
	// 0x1FA321: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA322: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA325: ret
	return;
loc_1FA326:
	// 0x1FA326: mov cl, [ebx+0x0D]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebx + 0xDu);
	// 0x1FA329: mov al, 0x01
	X86_REG8L(ctx.eax) = (uint8_t)(1);
	// 0x1FA32B: cmp cl, al
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FA32D: jnz 0x001FA339
	if (!ctx.flags.zf) goto loc_1FA339;
	// 0x1FA32F: mov eax, 0x40
	ctx.eax = 64;
	// 0x1FA334: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA335: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA338: ret
	return;
loc_1FA339:
	// 0x1FA339: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA33A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA33B: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FA340: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x1FA342: lea edi, [esp+0x0C]
	ctx.edi = ctx.esp + 0xCu;
	// 0x1FA346: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FA348: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA349: mov [esp+0x1D], al
	X86_MEM_WRITE_u8(base, ctx.esp + 0x1Du, X86_REG8L(ctx.eax));
	// 0x1FA34D: call 0x001F9DE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveFormatGetFrameSize(ctx, base);
	ctx.esp += 4;
	// 0x1FA352: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x1FA356: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA357: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FA359: call 0x001F9DE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveFormatGetFrameSize(ctx, base);
	ctx.esp += 4;
	// 0x1FA35E: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA360: div esi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.esi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1FA362: lea edx, [esp+0x14]
	ctx.edx = ctx.esp + 0x14u;
	// 0x1FA366: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA367: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FA369: call 0x001FA210
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveFormatGetSamplesPerAudioFrame(ctx, base);
	ctx.esp += 4;
	// 0x1FA36E: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA371: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA373: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA374: div esi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.esi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1FA376: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA377: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA378: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA37B: ret
	return;
}

void sub_1FA380(X86Context& ctx, uint8_t* base) {
	// 0x1FA380: sub esp, 0x20
	{ uint32_t _d = ctx.esp; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA383: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA384: mov ebx, [esp+0x28]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1FA388: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA389: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA38A: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA38C: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x1FA390: lea eax, [esp+0x14]
	ctx.eax = ctx.esp + 0x14u;
	// 0x1FA394: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA395: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA396: mov [esp+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.eax);
	// 0x1FA39A: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA39F: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3A1: lea edx, [ebx+0x04]
	ctx.edx = ctx.ebx + 0x4u;
	// 0x1FA3A4: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3A5: lea eax, [esp+0x20]
	ctx.eax = ctx.esp + 0x20u;
	// 0x1FA3A9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3AA: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA3AF: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3B1: lea ecx, [ebx+0x08]
	ctx.ecx = ctx.ebx + 0x8u;
	// 0x1FA3B4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3B5: lea edx, [esp+0x2C]
	ctx.edx = ctx.esp + 0x2Cu;
	// 0x1FA3B9: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3BA: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA3BF: mov ecx, [esp+0x30]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1FA3C3: mov al, [ebx+0x0C]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + 0xCu);
	// 0x1FA3C6: mov [ecx], al
	X86_MEM_WRITE_u8(base, ctx.ecx, X86_REG8L(ctx.eax));
	// 0x1FA3C8: mov eax, [esp+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1FA3CC: mov dl, [ebx+0x0D]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ebx + 0xDu);
	// 0x1FA3CF: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA3D0: mov [esp+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.eax);
	// 0x1FA3D4: mov [eax], dl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.edx));
	// 0x1FA3D6: mov eax, [esp+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1FA3DA: mov cl, [ebx+0x0E]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebx + 0xEu);
	// 0x1FA3DD: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA3DE: mov [esp+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.eax);
	// 0x1FA3E2: mov [eax], cl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.ecx));
	// 0x1FA3E4: mov eax, [esp+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1FA3E8: mov dl, [ebx+0x0F]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.ebx + 0xFu);
	// 0x1FA3EB: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA3EC: mov [esp+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.eax);
	// 0x1FA3F0: mov [eax], dl
	X86_MEM_WRITE_u8(base, ctx.eax, X86_REG8L(ctx.edx));
	// 0x1FA3F2: inc [esp+0x30]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, (uint32_t)_res); }
	// 0x1FA3F6: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3F8: lea eax, [ebx+0x10]
	ctx.eax = ctx.ebx + 0x10u;
	// 0x1FA3FB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA3FC: lea ecx, [esp+0x38]
	ctx.ecx = ctx.esp + 0x38u;
	// 0x1FA400: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA401: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA406: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA408: lea edx, [ebx+0x14]
	ctx.edx = ctx.ebx + 0x14u;
	// 0x1FA40B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA40C: lea eax, [esp+0x44]
	ctx.eax = ctx.esp + 0x44u;
	// 0x1FA410: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA411: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA416: mov cl, [ebx+0x18]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebx + 0x18u);
	// 0x1FA419: mov edx, [esp+0x48]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x48u);
	// 0x1FA41D: mov [edx], cl
	X86_MEM_WRITE_u8(base, ctx.edx, X86_REG8L(ctx.ecx));
	// 0x1FA41F: add esp, 0x3C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(60);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)60, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA422: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x1FA424: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FA429: lea esi, [esp+0x10]
	ctx.esi = ctx.esp + 0x10u;
	// 0x1FA42D: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FA42F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA430: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA431: mov byte ptr [ebx+0x19], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x19u, 0);
	// 0x1FA435: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA436: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA439: ret
	return;
}

void sub_1FA440(X86Context& ctx, uint8_t* base) {
	// 0x1FA440: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA441: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA445: mov eax, [edi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x20u);
	// 0x1FA448: add edi, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)32, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1FA44B: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA44D: jz 0x001FA465
	if (ctx.flags.zf) goto loc_1FA465;
	// 0x1FA44F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_1FA450:
	// 0x1FA450: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1FA452: add eax, 0xFFFFFFB0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-80);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-80, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA455: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA456: call 0x001F9F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9F40(ctx, base);
	ctx.esp += 4;
	// 0x1FA45B: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA45E: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA460: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FA462: jnz 0x001FA450
	if (!ctx.flags.zf) goto loc_1FA450;
	// 0x1FA464: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FA465:
	// 0x1FA465: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA467: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA468: ret
	return;
}

void sub_1FA470(X86Context& ctx, uint8_t* base) {
	// 0x1FA470: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA471: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA475: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA476: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA478: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA47A: jnz 0x001FA4A2
	if (!ctx.flags.zf) goto loc_1FA4A2;
	// 0x1FA47C: push 0x30805
	{ auto _pv = (uint32_t)(198661); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA481: push 0x41B744
	{ auto _pv = (uint32_t)(4306756); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA486: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x1FA48B: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FA48D: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA490: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA492: jnz 0x001FA499
	if (!ctx.flags.zf) goto loc_1FA499;
	// 0x1FA494: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA495: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA497: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA498: ret
	return;
loc_1FA499:
	// 0x1FA499: mov dword ptr [esi+0x58], 0x02
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, 2);
	// 0x1FA4A0: jmp 0x001FA4A5
	goto loc_1FA4A5;
loc_1FA4A2:
	// 0x1FA4A2: mov [esi+0x58], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, ctx.edi);
loc_1FA4A5:
	// 0x1FA4A5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA4A6: call 0x001FE3D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDInitialize(ctx, base);
	ctx.esp += 4;
	// 0x1FA4AB: mov al, [esi+0x58]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x58u);
	// 0x1FA4AE: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA4B1: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1FA4B3: mov [esi+0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.edi);
	// 0x1FA4B6: mov [esi+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.edi);
	// 0x1FA4B9: mov [esi+0x14], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.edi);
	// 0x1FA4BC: mov [esi+0x1C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.edi);
	// 0x1FA4BF: mov [esi+0x20], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.edi);
	// 0x1FA4C2: mov [esi+0x24], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.edi);
	// 0x1FA4C5: mov [esi+0x18], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.edi);
	// 0x1FA4C8: mov [esi+0x30], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, ctx.edi);
	// 0x1FA4CB: mov [esi+0x44], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.edi);
	// 0x1FA4CE: mov dword ptr [esi+0x48], 0x08
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, 8);
	// 0x1FA4D5: mov [esi+0x4C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.edi);
	// 0x1FA4D8: jz 0x001FA4EE
	if (ctx.flags.zf) goto loc_1FA4EE;
	// 0x1FA4DA: mov eax, [esi+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1FA4DD: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA4DF: jz 0x001FA4EA
	if (ctx.flags.zf) goto loc_1FA4EA;
	// 0x1FA4E1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA4E2: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FA4E7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FA4EA:
	// 0x1FA4EA: and dword ptr [esi+0x58], 0xFFFFFFFE
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, X86_MEM_READ_u32(base, ctx.esi + 0x58u) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x58u), 32);
loc_1FA4EE:
	// 0x1FA4EE: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA4F2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA4F4: lea ecx, [esi+0x50]
	ctx.ecx = ctx.esi + 0x50u;
	// 0x1FA4F7: mov [esi+0x38], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.edi);
	// 0x1FA4FA: mov [esi+0x34], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, ctx.edi);
	// 0x1FA4FD: mov [esi+0x3C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.edi);
	// 0x1FA500: mov [esi+0x54], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x54u, ctx.edi);
	// 0x1FA503: mov [ecx], edi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edi);
	// 0x1FA505: jnz 0x001FA50C
	if (!ctx.flags.zf) goto loc_1FA50C;
	// 0x1FA507: mov eax, [0x00764134]
	ctx.eax = X86_MEM_READ_u32(base, 0x764134u);
loc_1FA50C:
	// 0x1FA50C: mov [esi+0x40], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.eax);
	// 0x1FA50F: mov edx, [eax+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	// 0x1FA512: add eax, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)32, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA515: mov [esi+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x54u, ctx.eax);
	// 0x1FA518: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1FA51A: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1FA51C: mov [edx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.ecx);
	// 0x1FA51F: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1FA521: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA522: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FA524: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA525: ret
	return;
}

void RwaWaveDefFindByUUID(X86Context& ctx, uint8_t* base) {
	// 0x1FA530: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA533: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA537: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA539: lea ecx, [esp+0x04]
	ctx.ecx = ctx.esp + 0x4u;
	// 0x1FA53D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA53E: push 0x1F9FC0
	{ auto _pv = (uint32_t)(2072512); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA543: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA545: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA547: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1FA54B: mov dword ptr [esp+0x18], 0x00
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, 0);
	// 0x1FA553: call 0x001F8750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8750(ctx, base);
	ctx.esp += 4;
	// 0x1FA558: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FA55C: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA55F: ret
	return;
}

void sub_1FA560(X86Context& ctx, uint8_t* base) {
	// 0x1FA560: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA561: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FA565: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA567: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA568: mov ebx, [esp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA56C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA56D: mov ebp, [esp+0x1C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FA571: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA572: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA573: jz 0x001FA6B9
	if (ctx.flags.zf) goto loc_1FA6B9;
	// 0x1FA579: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1FA57B: mov edi, [esp+0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FA57F: mov [esp+0x20], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.edi);
	// 0x1FA583: jz 0x001FA654
	if (ctx.flags.zf) goto loc_1FA654;
	// 0x1FA589: mov ecx, [ebx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA58C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA58E: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FA590: setnz al
	X86_REG8L(ctx.eax) = (!ctx.flags.zf) ? 1 : 0;
	// 0x1FA593: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA595: lea ecx, [esp+0x24]
	ctx.ecx = ctx.esp + 0x24u;
	// 0x1FA599: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA59A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA59B: mov [esp+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.eax);
	// 0x1FA59F: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA5A4: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5A6: lea edx, [esp+0x20]
	ctx.edx = ctx.esp + 0x20u;
	// 0x1FA5AA: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5AB: lea eax, [esp+0x34]
	ctx.eax = ctx.esp + 0x34u;
	// 0x1FA5AF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5B0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA5B5: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5B7: lea ecx, [ebx+0x08]
	ctx.ecx = ctx.ebx + 0x8u;
	// 0x1FA5BA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5BB: lea edx, [esp+0x40]
	ctx.edx = ctx.esp + 0x40u;
	// 0x1FA5BF: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5C0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA5C5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5C7: lea eax, [ebx+0x0C]
	ctx.eax = ctx.ebx + 0xCu;
	// 0x1FA5CA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5CB: lea ecx, [esp+0x4C]
	ctx.ecx = ctx.esp + 0x4Cu;
	// 0x1FA5CF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5D0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA5D5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5D7: lea edx, [ebx+0x0D]
	ctx.edx = ctx.ebx + 0xDu;
	// 0x1FA5DA: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5DB: lea eax, [esp+0x58]
	ctx.eax = ctx.esp + 0x58u;
	// 0x1FA5DF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5E0: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA5E5: mov ecx, [esp+0x5C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	// 0x1FA5E9: mov word ptr [ecx], 0x00
	X86_MEM_WRITE_u16(base, ctx.ecx, 0);
	// 0x1FA5EE: mov edx, [esp+0x5C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	// 0x1FA5F2: mov esi, 0x02
	ctx.esi = 2;
	// 0x1FA5F7: add edx, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.esi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FA5F9: mov [esp+0x5C], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x5Cu, ctx.edx);
	// 0x1FA5FD: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA5FF: lea edx, [ebx+0x10]
	ctx.edx = ctx.ebx + 0x10u;
	// 0x1FA602: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA603: lea eax, [esp+0x64]
	ctx.eax = ctx.esp + 0x64u;
	// 0x1FA607: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA608: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA60D: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA610: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA612: lea ecx, [ebx+0x14]
	ctx.ecx = ctx.ebx + 0x14u;
	// 0x1FA615: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA616: lea edx, [esp+0x28]
	ctx.edx = ctx.esp + 0x28u;
	// 0x1FA61A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA61B: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA620: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA622: lea eax, [ebx+0x18]
	ctx.eax = ctx.ebx + 0x18u;
	// 0x1FA625: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA626: lea ecx, [esp+0x34]
	ctx.ecx = ctx.esp + 0x34u;
	// 0x1FA62A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA62B: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA630: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA632: lea edx, [ebx+0x19]
	ctx.edx = ctx.ebx + 0x19u;
	// 0x1FA635: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA636: lea eax, [esp+0x40]
	ctx.eax = ctx.esp + 0x40u;
	// 0x1FA63A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA63B: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA640: mov ecx, [esp+0x44]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x1FA644: mov word ptr [ecx], 0x00
	X86_MEM_WRITE_u16(base, ctx.ecx, 0);
	// 0x1FA649: mov eax, [esp+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x1FA64D: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA650: add eax, esi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.esi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.esi, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA652: jmp 0x001FA664
	goto loc_1FA664;
loc_1FA654:
	// 0x1FA654: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FA659: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x1FA65B: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FA65D: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FA661: add eax, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)28, 32);
	  ctx.eax = (uint32_t)_res; }
loc_1FA664:
	// 0x1FA664: mov [esp+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.eax);
	// 0x1FA668: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA66B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA66D: jz 0x001FA689
	if (ctx.flags.zf) goto loc_1FA689;
	// 0x1FA66F: mov edx, [esp+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FA673: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA674: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA675: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA676: call 0x001FE3E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE3E0(ctx, base);
	ctx.esp += 4;
	// 0x1FA67B: mov eax, [esp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x1FA67F: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA682: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FA685: mov [esp+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.eax);
loc_1FA689:
	// 0x1FA689: mov esi, [ebx+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x1FA68C: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FA68E: jz 0x001FA7BE
	if (ctx.flags.zf) goto loc_1FA7BE;
	// 0x1FA694: mov ecx, [ebx+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x14u);
	// 0x1FA697: mov edi, [esp+0x20]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FA69B: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1FA69D: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FA6A0: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FA6A2: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FA6A4: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FA6A7: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x1FA6A9: mov al, [ebx+0x18]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + 0x18u);
	// 0x1FA6AC: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA6AD: or al, 0x02
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x1FA6AF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA6B0: mov [ebx+0x18], al
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x18u, X86_REG8L(ctx.eax));
	// 0x1FA6B3: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA6B4: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FA6B6: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA6B7: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA6B8: ret
	return;
loc_1FA6B9:
	// 0x1FA6B9: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1FA6BB: jz 0x001FA77A
	if (ctx.flags.zf) goto loc_1FA77A;
	// 0x1FA6C1: mov esi, [esp+0x1C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FA6C5: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6C7: lea ecx, [esp+0x24]
	ctx.ecx = ctx.esp + 0x24u;
	// 0x1FA6CB: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6CC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6CD: mov [esp+0x2C], ebx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x2Cu, ctx.ebx);
	// 0x1FA6D1: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA6D6: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6D8: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA6DB: lea edx, [esp+0x30]
	ctx.edx = ctx.esp + 0x30u;
	// 0x1FA6DF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6E0: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6E1: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA6E6: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6E8: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA6EB: lea eax, [esp+0x3C]
	ctx.eax = ctx.esp + 0x3Cu;
	// 0x1FA6EF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6F0: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6F1: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA6F6: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA6F8: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA6FB: lea ecx, [esp+0x48]
	ctx.ecx = ctx.esp + 0x48u;
	// 0x1FA6FF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA700: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA701: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA706: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA708: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA709: lea edx, [esp+0x54]
	ctx.edx = ctx.esp + 0x54u;
	// 0x1FA70D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA70E: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA70F: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA714: mov eax, [esp+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	// 0x1FA718: mov word ptr [eax], 0x00
	X86_MEM_WRITE_u16(base, ctx.eax, 0);
	// 0x1FA71D: mov ecx, [esp+0x5C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x5Cu);
	// 0x1FA721: add ecx, 0x02
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(2);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)2, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FA724: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA726: add esi, 0x03
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(3);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)3, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA729: mov [esp+0x60], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x60u, ctx.ecx);
	// 0x1FA72D: lea ecx, [esp+0x60]
	ctx.ecx = ctx.esp + 0x60u;
	// 0x1FA731: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA732: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA733: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA738: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA73B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA73D: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA740: lea edx, [esp+0x24]
	ctx.edx = ctx.esp + 0x24u;
	// 0x1FA744: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA745: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA746: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA74B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA74D: add esi, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)4, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA750: lea eax, [esp+0x30]
	ctx.eax = ctx.esp + 0x30u;
	// 0x1FA754: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA755: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA756: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA75B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA75D: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA75E: lea ecx, [esp+0x3C]
	ctx.ecx = ctx.esp + 0x3Cu;
	// 0x1FA762: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA763: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA764: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FA769: mov edx, [esp+0x44]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x1FA76D: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA770: mov word ptr [edx], 0x00
	X86_MEM_WRITE_u16(base, ctx.edx, 0);
	// 0x1FA775: add esi, 0x03
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(3);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)3, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FA778: jmp 0x001FA78C
	goto loc_1FA78C;
loc_1FA77A:
	// 0x1FA77A: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FA77E: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FA783: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FA785: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x1FA787: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FA789: lea esi, [eax+0x1C]
	ctx.esi = ctx.eax + 0x1Cu;
loc_1FA78C:
	// 0x1FA78C: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FA78F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA791: jz 0x001FA7B4
	if (ctx.flags.zf) goto loc_1FA7B4;
	// 0x1FA793: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA794: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA795: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA796: call 0x001FE3E0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE3E0(ctx, base);
	ctx.esp += 4;
	// 0x1FA79B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA79C: call 0x001FA1C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA1C0(ctx, base);
	ctx.esp += 4;
	// 0x1FA7A1: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA7A4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA7A6: mov [ebx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.eax);
	// 0x1FA7A9: jnz 0x001FA7B1
	if (!ctx.flags.zf) goto loc_1FA7B1;
	// 0x1FA7AB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7AC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7AD: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7AE: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7AF: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7B0: ret
	return;
loc_1FA7B1:
	// 0x1FA7B1: add esi, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)16, 32);
	  ctx.esi = (uint32_t)_res; }
loc_1FA7B4:
	// 0x1FA7B4: mov eax, [ebx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x1FA7B7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA7B9: jz 0x001FA7BE
	if (ctx.flags.zf) goto loc_1FA7BE;
	// 0x1FA7BB: mov [ebx+0x10], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x10u, ctx.esi);
loc_1FA7BE:
	// 0x1FA7BE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7BF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7C0: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7C1: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FA7C3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7C4: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA7C5: ret
	return;
}

void RwaWaveFormatGetSamples(X86Context& ctx, uint8_t* base) {
	// 0x1FA7D0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7D1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7D2: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FA7D6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7D7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7D8: call 0x001FA210
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveFormatGetSamplesPerAudioFrame(ctx, base);
	ctx.esp += 4;
	// 0x1FA7DD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7DE: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x1FA7E0: call 0x001F9DE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveFormatGetFrameSize(ctx, base);
	ctx.esp += 4;
	// 0x1FA7E5: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FA7E7: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FA7EA: push 0x36DC18
	{ auto _pv = (uint32_t)(3595288); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7EF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA7F0: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA7F5: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA7F8: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA7FA: jz 0x001FA811
	if (ctx.flags.zf) goto loc_1FA811;
	// 0x1FA7FC: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FA7FF: push 0x36DC78
	{ auto _pv = (uint32_t)(3595384); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA804: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA805: call 0x001FE270
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaUUIDCompare(ctx, base);
	ctx.esp += 4;
	// 0x1FA80A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA80D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA80F: jnz 0x001FA84A
	if (!ctx.flags.zf) goto loc_1FA84A;
loc_1FA811:
	// 0x1FA811: cmp byte ptr [esi+0x0D], 0x02
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.esi + 0xDu); uint8_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FA815: jnz 0x001FA84A
	if (!ctx.flags.zf) goto loc_1FA84A;
	// 0x1FA817: mov edx, [esp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FA81B: fild [esp+0x14]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)));
	// 0x1FA81F: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x1FA821: jnl 0x001FA829
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FA829;
	// 0x1FA823: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1FA829:
	// 0x1FA829: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FA82B: mov [esp+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.edi);
	// 0x1FA82F: fild [esp+0x10]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)));
	// 0x1FA833: jnl 0x001FA83B
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FA83B;
	// 0x1FA835: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1FA83B:
	// 0x1FA83B: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1FA83D: fmul [0x0036DC88]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x36DC88u));
	// 0x1FA843: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FA848: jmp 0x001FA855
	goto loc_1FA855;
loc_1FA84A:
	// 0x1FA84A: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FA84E: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA850: div edi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.edi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1FA852: imul eax, ebx
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)ctx.ebx;
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
loc_1FA855:
	// 0x1FA855: test byte ptr [esi+0x18], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x18u) & 4, 8);
	// 0x1FA859: mov ecx, 0x01
	ctx.ecx = 1;
	// 0x1FA85E: jnz 0x001FA864
	if (!ctx.flags.zf) goto loc_1FA864;
	// 0x1FA860: movzx ecx, byte ptr [esi+0x0D]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0xDu));
loc_1FA864:
	// 0x1FA864: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA865: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA867: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA868: div ecx
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.ecx;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x1FA86A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FA86B: ret
	return;
}

void _rwaWaveDefCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1FA870: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA872: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA874: push 0x1FA440
	{ auto _pv = (uint32_t)(2073664); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA879: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA87B: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA87D: call 0x001F8750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8750(ctx, base);
	ctx.esp += 4;
	// 0x1FA882: push 0x41B744
	{ auto _pv = (uint32_t)(4306756); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA887: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1FA88C: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA88F: mov dword ptr [0x0041B768], 0x00
	X86_MEM_WRITE_u32(base, 0x41B768u, 0);
	// 0x1FA899: ret
	return;
}

void _rwaWaveOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1FA8A0: push 0x40806
	{ auto _pv = (uint32_t)(264198); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8A5: push 0x41B76C
	{ auto _pv = (uint32_t)(4306796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8AA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8AC: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8AE: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8B0: push 0x5C
	{ auto _pv = (uint32_t)(92); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8B2: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FA8B7: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA8BA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA8BC: jz 0x001FA8C9
	if (ctx.flags.zf) goto loc_1FA8C9;
	// 0x1FA8BE: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FA8C3: mov [0x0041B790], eax
	X86_MEM_WRITE_u32(base, 0x41B790u, ctx.eax);
	// 0x1FA8C8: ret
	return;
loc_1FA8C9:
	// 0x1FA8C9: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA8CB: ret
	return;
}

void _rwaWaveCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1FA8D0: push 0x41B76C
	{ auto _pv = (uint32_t)(4306796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8D5: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1FA8DA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA8DD: mov dword ptr [0x0041B790], 0x00
	X86_MEM_WRITE_u32(base, 0x41B790u, 0);
	// 0x1FA8E7: ret
	return;
}

void sub_1FA8F0(X86Context& ctx, uint8_t* base) {
	// 0x1FA8F0: test byte ptr [esi+0x54], 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x54u) & 8, 8);
	// 0x1FA8F4: jz 0x001FA902
	if (ctx.flags.zf) goto loc_1FA902;
	// 0x1FA8F6: mov eax, [esi+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1FA8F9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA8FA: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FA8FF: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FA902:
	// 0x1FA902: mov eax, [esi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1FA905: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1FA907: jz 0x001FA92C
	if (ctx.flags.zf) goto loc_1FA92C;
	// 0x1FA909: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1FA90C: mov eax, [ecx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x4Cu);
	// 0x1FA90F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA911: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA912: jz 0x001FA91E
	if (ctx.flags.zf) goto loc_1FA91E;
	// 0x1FA914: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA915: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1FA91A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA91D: ret
	return;
loc_1FA91E:
	// 0x1FA91E: push 0x41B76C
	{ auto _pv = (uint32_t)(4306796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA923: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1FA928: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA92B: ret
	return;
loc_1FA92C:
	// 0x1FA92C: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x1FA92E: jnz 0x001FA937
	if (!ctx.flags.zf) goto loc_1FA937;
	// 0x1FA930: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA931: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FA936: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FA937:
	// 0x1FA937: ret
	return;
}

void rwaWaveSetTargetFormat(X86Context& ctx, uint8_t* base) {
	// 0x1FA940: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA943: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA944: mov ebp, [esp+0x24]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1FA948: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA949: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FA94B: cmp ebp, esi
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA94D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA94E: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FA950: mov eax, [ebx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0xCu);
	// 0x1FA953: jz 0x001FA973
	if (ctx.flags.zf) goto loc_1FA973;
	// 0x1FA955: cmp [ebp+0x04], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x4u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA958: jz 0x001FA973
	if (ctx.flags.zf) goto loc_1FA973;
	// 0x1FA95A: cmp [eax+0x34], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x34u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA95D: jbe 0x001FA973
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FA973;
	// 0x1FA95F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA960: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA961: call 0x001FA130
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDefIsTargetFormatSupported(ctx, base);
	ctx.esp += 4;
	// 0x1FA966: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA969: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA96B: jz 0x001FAA3F
	if (ctx.flags.zf) goto loc_1FAA3F;
	// 0x1FA971: jmp 0x001FA9B4
	goto loc_1FA9B4;
loc_1FA973:
	// 0x1FA973: mov ecx, [eax+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x38u);
	// 0x1FA976: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA978: jz 0x001FA984
	if (ctx.flags.zf) goto loc_1FA984;
	// 0x1FA97A: mov eax, [eax+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x3Cu);
	// 0x1FA97D: mov eax, [ecx+eax*4]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4);
	// 0x1FA980: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA982: jnz 0x001FA98C
	if (!ctx.flags.zf) goto loc_1FA98C;
loc_1FA984:
	// 0x1FA984: cmp ebp, esi
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FA986: jnz 0x001FA9B4
	if (!ctx.flags.zf) goto loc_1FA9B4;
	// 0x1FA988: mov ebp, edi
	ctx.ebp = ctx.edi;
	// 0x1FA98A: jmp 0x001FA9B4
	goto loc_1FA9B4;
loc_1FA98C:
	// 0x1FA98C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA98E: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x1FA992: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA993: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA994: call 0x001FA010
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA010(ctx, base);
	ctx.esp += 4;
	// 0x1FA999: mov edx, [edi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FA99B: mov eax, [edi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	// 0x1FA99E: mov ecx, [edi+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x14u);
	// 0x1FA9A1: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA9A4: mov [esp+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.edx);
	// 0x1FA9A8: mov [esp+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.eax);
	// 0x1FA9AC: mov [esp+0x20], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.ecx);
	// 0x1FA9B0: lea ebp, [esp+0x0C]
	ctx.ebp = ctx.esp + 0xCu;
loc_1FA9B4:
	// 0x1FA9B4: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA9B5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA9B6: call 0x001F9D80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9D80(ctx, base);
	ctx.esp += 4;
	// 0x1FA9BB: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FA9BE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FA9C0: jz 0x001FA9CE
	if (ctx.flags.zf) goto loc_1FA9CE;
	// 0x1FA9C2: mov edx, [edi+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	// 0x1FA9C5: mov [ebp+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x10u, ctx.edx);
	// 0x1FA9C8: mov eax, [edi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x14u);
	// 0x1FA9CB: mov [ebp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x14u, ctx.eax);
loc_1FA9CE:
	// 0x1FA9CE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA9CF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA9D0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FA9D1: call 0x00204B90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_204B90(ctx, base);
	ctx.esp += 4;
	// 0x1FA9D6: mov [ebp+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.eax);
	// 0x1FA9D9: lea edi, [ebx+0x2C]
	ctx.edi = ctx.ebx + 0x2Cu;
	// 0x1FA9DC: mov [edi], esi
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.esi);
	// 0x1FA9DE: mov [ebx+0x30], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x30u, ctx.esi);
	// 0x1FA9E1: mov [ebx+0x34], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x34u, ctx.esi);
	// 0x1FA9E4: mov [ebx+0x3C], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x3Cu, ctx.esi);
	// 0x1FA9E7: mov [ebx+0x40], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x40u, ctx.esi);
	// 0x1FA9EA: mov byte ptr [ebx+0x38], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x38u, 0);
	// 0x1FA9EE: mov byte ptr [ebx+0x39], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x39u, 0);
	// 0x1FA9F2: mov byte ptr [ebx+0x44], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x44u, 0);
	// 0x1FA9F6: mov byte ptr [ebx+0x45], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x45u, 0);
	// 0x1FA9FA: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FA9FF: mov esi, ebp
	ctx.esi = ctx.ebp;
	// 0x1FAA01: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FAA03: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1FAA06: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAA09: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAA0B: jz 0x001FAA3F
	if (ctx.flags.zf) goto loc_1FAA3F;
	// 0x1FAA0D: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FAA10: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAA12: jbe 0x001FAA3F
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FAA3F;
	// 0x1FAA14: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA19: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA1A: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1FAA1F: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAA22: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAA24: mov [ebx+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x3Cu, ctx.eax);
	// 0x1FAA27: jz 0x001FAA3F
	if (ctx.flags.zf) goto loc_1FAA3F;
	// 0x1FAA29: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FAA2C: mov esi, [ebp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1FAA2F: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FAA31: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FAA34: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FAA36: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FAA38: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x1FAA3A: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FAA3D: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
loc_1FAA3F:
	// 0x1FAA3F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAA40: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAA41: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAA42: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAA45: ret
	return;
}

void RwaWaveCreateLoadedWave(X86Context& ctx, uint8_t* base) {
	// 0x1FAA50: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAA53: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA54: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA55: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FAA59: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FAA5B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA5C: jnz 0x001FAA6D
	if (!ctx.flags.zf) goto loc_1FAA6D;
	// 0x1FAA5E: push 0x36EC04
	{ auto _pv = (uint32_t)(3599364); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA63: call 0x001FA530
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveDefFindByUUID(ctx, base);
	ctx.esp += 4;
	// 0x1FAA68: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAA6B: mov esi, eax
	ctx.esi = ctx.eax;
loc_1FAA6D:
	// 0x1FAA6D: mov edi, [esp+0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FAA71: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FAA73: jnz 0x001FAA96
	if (!ctx.flags.zf) goto loc_1FAA96;
	// 0x1FAA75: mov eax, [esi+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1FAA78: lea ecx, [esp+0x0C]
	ctx.ecx = ctx.esp + 0xCu;
	// 0x1FAA7C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA7D: push 0x1F5BE0
	{ auto _pv = (uint32_t)(2055136); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAA82: mov [esp+0x14], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edi);
	// 0x1FAA86: mov [esp+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.eax);
	// 0x1FAA8A: call 0x001F5C00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjEnum(ctx, base);
	ctx.esp += 4;
	// 0x1FAA8F: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FAA93: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAA96:
	// 0x1FAA96: mov eax, [esi+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x44u);
	// 0x1FAA99: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAA9B: mov ebx, [esp+0x2C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x1FAA9F: jz 0x001FAAC2
	if (ctx.flags.zf) goto loc_1FAAC2;
	// 0x1FAAA1: mov ecx, [ebx+0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x50u);
	// 0x1FAAA4: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FAAA6: jnz 0x001FAAC2
	if (!ctx.flags.zf) goto loc_1FAAC2;
	// 0x1FAAA8: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAAAD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAAAE: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1FAAB3: mov [ebx+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x50u, ctx.eax);
	// 0x1FAAB6: mov eax, [ebx+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x54u);
	// 0x1FAAB9: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAABC: or eax, 0x08
	ctx.eax = ctx.eax | 8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FAABF: mov [ebx+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x54u, ctx.eax);
loc_1FAAC2:
	// 0x1FAAC2: lea edx, [ebx+0x2C]
	ctx.edx = ctx.ebx + 0x2Cu;
	// 0x1FAAC5: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAAC6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAAC7: mov [ebx+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xCu, ctx.esi);
	// 0x1FAACA: mov [ebx+0x58], edi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x58u, ctx.edi);
	// 0x1FAACD: call 0x001FA130
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveDefIsTargetFormatSupported(ctx, base);
	ctx.esp += 4;
	// 0x1FAAD2: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAAD5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAAD7: jnz 0x001FAAE5
	if (!ctx.flags.zf) goto loc_1FAAE5;
	// 0x1FAAD9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAADA: lea eax, [ebx+0x10]
	ctx.eax = ctx.ebx + 0x10u;
	// 0x1FAADD: call 0x001FA940
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveSetTargetFormat(ctx, base);
	ctx.esp += 4;
	// 0x1FAAE2: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAAE5:
	// 0x1FAAE5: mov eax, [esp+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1FAAE9: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAAEB: jz 0x001FAAF7
	if (ctx.flags.zf) goto loc_1FAAF7;
	// 0x1FAAED: cmp byte ptr [ebx+0x39], 0x01
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ebx + 0x39u); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FAAF1: jnz 0x001FAAF7
	if (!ctx.flags.zf) goto loc_1FAAF7;
	// 0x1FAAF3: or dword ptr [ebx+0x54], 0x02
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x54u, X86_MEM_READ_u32(base, ctx.ebx + 0x54u) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebx + 0x54u), 32);
loc_1FAAF7:
	// 0x1FAAF7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAAF8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAAF9: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FAAFB: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAAFC: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAAFF: ret
	return;
}

void sub_1FAB00(X86Context& ctx, uint8_t* base) {
	// 0x1FAB00: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB01: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FAB05: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1FAB08: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1FAB0B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAB0D: jz 0x001FAB15
	if (ctx.flags.zf) goto loc_1FAB15;
	// 0x1FAB0F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB10: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x1FAB12: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAB15:
	// 0x1FAB15: lea ecx, [esi+0x10]
	ctx.ecx = ctx.esi + 0x10u;
	// 0x1FAB18: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB19: call 0x001F9EE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9EE0(ctx, base);
	ctx.esp += 4;
	// 0x1FAB1E: lea edx, [esi+0x2C]
	ctx.edx = ctx.esi + 0x2Cu;
	// 0x1FAB21: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB22: call 0x001F9EE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9EE0(ctx, base);
	ctx.esp += 4;
	// 0x1FAB27: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB28: call 0x001F6600
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F6600(ctx, base);
	ctx.esp += 4;
	// 0x1FAB2D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB2E: call 0x001FE500
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDFreeData(ctx, base);
	ctx.esp += 4;
	// 0x1FAB33: mov al, [esi+0x54]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x54u);
	// 0x1FAB36: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAB39: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x1FAB3B: jz 0x001FAB49
	if (ctx.flags.zf) goto loc_1FAB49;
	// 0x1FAB3D: mov eax, [esi+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1FAB40: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB41: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FAB46: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAB49:
	// 0x1FAB49: mov eax, [esi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1FAB4C: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1FAB4E: jz 0x001FAB75
	if (ctx.flags.zf) goto loc_1FAB75;
	// 0x1FAB50: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1FAB53: mov eax, [ecx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x4Cu);
	// 0x1FAB56: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAB58: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB59: jz 0x001FAB66
	if (ctx.flags.zf) goto loc_1FAB66;
	// 0x1FAB5B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB5C: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1FAB61: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAB64: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAB65: ret
	return;
loc_1FAB66:
	// 0x1FAB66: push 0x41B76C
	{ auto _pv = (uint32_t)(4306796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB6B: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1FAB70: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAB73: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAB74: ret
	return;
loc_1FAB75:
	// 0x1FAB75: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x1FAB77: jnz 0x001FAB82
	if (!ctx.flags.zf) goto loc_1FAB82;
	// 0x1FAB79: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAB7A: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FAB7F: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAB82:
	// 0x1FAB82: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAB83: ret
	return;
}

void sub_1FAB90(X86Context& ctx, uint8_t* base) {
	// 0x1FAB90: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FAB94: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAB96: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FAB9A: mov ecx, [eax+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x54u);
	// 0x1FAB9D: jz 0x001FABA6
	if (ctx.flags.zf) goto loc_1FABA6;
	// 0x1FAB9F: or ecx, 0x10
	ctx.ecx = ctx.ecx | 16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FABA2: mov [eax+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, ctx.ecx);
	// 0x1FABA5: ret
	return;
loc_1FABA6:
	// 0x1FABA6: and ecx, 0xFFFFFFEF
	ctx.ecx = ctx.ecx & -17;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FABA9: mov [eax+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, ctx.ecx);
	// 0x1FABAC: ret
	return;
}

void sub_1FABB0(X86Context& ctx, uint8_t* base) {
	// 0x1FABB0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FABB4: mov ecx, [eax+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x1FABB7: mov eax, [ecx+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x1FABBA: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FABBC: jnz 0x001FABBF
	if (!ctx.flags.zf) goto loc_1FABBF;
	// 0x1FABBE: ret
	return;
loc_1FABBF:
	// 0x1FABBF: jmp eax
	X86_JMP_INDIRECT(ctx, base, ctx.eax);
	return;
}

void sub_1FABD0(X86Context& ctx, uint8_t* base) {
	// 0x1FABD0: sub esp, 0x60
	{ uint32_t _d = ctx.esp; uint32_t _s = 96;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FABD3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FABD4: mov ebx, [esp+0x68]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x68u);
	// 0x1FABD8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FABD9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FABDA: lea eax, [esp+0x10]
	ctx.eax = ctx.esp + 0x10u;
	// 0x1FABDE: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FABDF: mov [esp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.eax);
	// 0x1FABE3: call 0x001FE320
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FE320(ctx, base);
	ctx.esp += 4;
	// 0x1FABE8: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FABEC: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x1FABEE: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FABF0: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x1FABF2: mov eax, [ecx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FABF5: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1FABF8: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1FABFB: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1FABFE: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FAC02: mov edx, [ebx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0xCu);
	// 0x1FAC05: add eax, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)12, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FAC08: mov [esp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.eax);
	// 0x1FAC0C: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x1FAC0E: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FAC12: add ecx, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)4, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FAC15: lea esi, [ebx+0x10]
	ctx.esi = ctx.ebx + 0x10u;
	// 0x1FAC18: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC19: mov [esp+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.ecx);
	// 0x1FAC1D: call 0x001FA380
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA380(ctx, base);
	ctx.esp += 4;
	// 0x1FAC22: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FAC26: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FAC2B: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FAC2D: add dword ptr [esp+0x14], 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x14u), (int32_t)28, 32);
	  X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, (uint32_t)_res); }
	// 0x1FAC32: lea esi, [ebx+0x2C]
	ctx.esi = ctx.ebx + 0x2Cu;
	// 0x1FAC35: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC36: call 0x001FA380
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA380(ctx, base);
	ctx.esp += 4;
	// 0x1FAC3B: mov edi, [esp+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FAC3F: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FAC44: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FAC46: add dword ptr [esp+0x18], 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x18u)) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.esp + 0x18u), (int32_t)28, 32);
	  X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, (uint32_t)_res); }
	// 0x1FAC4B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC4D: lea eax, [ebx+0x48]
	ctx.eax = ctx.ebx + 0x48u;
	// 0x1FAC50: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC51: lea ecx, [esp+0x20]
	ctx.ecx = ctx.esp + 0x20u;
	// 0x1FAC55: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC56: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FAC5B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC5D: lea edx, [ebx+0x4C]
	ctx.edx = ctx.ebx + 0x4Cu;
	// 0x1FAC60: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC61: lea eax, [esp+0x2C]
	ctx.eax = ctx.esp + 0x2Cu;
	// 0x1FAC65: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC66: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FAC6B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC6D: lea ecx, [ebx+0x50]
	ctx.ecx = ctx.ebx + 0x50u;
	// 0x1FAC70: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC71: lea edx, [esp+0x38]
	ctx.edx = ctx.esp + 0x38u;
	// 0x1FAC75: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC76: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FAC7B: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC7D: lea eax, [ebx+0x54]
	ctx.eax = ctx.ebx + 0x54u;
	// 0x1FAC80: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC81: lea ecx, [esp+0x44]
	ctx.ecx = ctx.esp + 0x44u;
	// 0x1FAC85: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAC86: call 0x001FFD80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaEndianCopy(ctx, base);
	ctx.esp += 4;
	// 0x1FAC8B: mov edx, [ebx+0x58]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x58u);
	// 0x1FAC8E: mov eax, [esp+0x48]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x48u);
	// 0x1FAC92: add esp, 0x3C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(60);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)60, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAC95: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x1FAC97: mov ecx, 0x17
	ctx.ecx = 23;
	// 0x1FAC9C: lea esi, [esp+0x10]
	ctx.esi = ctx.esp + 0x10u;
	// 0x1FACA0: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x1FACA2: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FACA4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FACA5: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FACA6: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FACA7: add esp, 0x60
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(96);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)96, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FACAA: ret
	return;
}

void sub_1FACB0(X86Context& ctx, uint8_t* base) {
	// 0x1FACB0: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FACB4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FACB6: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FACBA: mov ecx, [eax+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x54u);
	// 0x1FACBD: jz 0x001FACC9
	if (ctx.flags.zf) goto loc_1FACC9;
	// 0x1FACBF: or ecx, 0x80
	ctx.ecx = ctx.ecx | 128;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FACC5: mov [eax+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, ctx.ecx);
	// 0x1FACC8: ret
	return;
loc_1FACC9:
	// 0x1FACC9: and ecx, 0xFFFFFF7F
	ctx.ecx = ctx.ecx & -129;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FACCF: mov [eax+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, ctx.ecx);
	// 0x1FACD2: ret
	return;
}

void sub_1FACE0(X86Context& ctx, uint8_t* base) {
	// 0x1FACE0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FACE4: movzx eax, byte ptr [eax+0x54]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x54u));
	// 0x1FACE8: shr eax, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FACEB: ret
	return;
}

void sub_1FACF0(X86Context& ctx, uint8_t* base) {
	// 0x1FACF0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FACF1: mov ebx, [esp+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FACF5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FACF6: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FACF8: cmp ebx, ebp
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FACFA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FACFB: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FACFF: jz 0x001FAD0A
	if (ctx.flags.zf) goto loc_1FAD0A;
	// 0x1FAD01: mov dword ptr [ebx+0x54], 0x04
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x54u, 4);
	// 0x1FAD08: jmp 0x001FAD63
	goto loc_1FAD63;
loc_1FAD0A:
	// 0x1FAD0A: cmp [esi+0x44], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x44u); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FAD0D: jnz 0x001FAD1B
	if (!ctx.flags.zf) goto loc_1FAD1B;
	// 0x1FAD0F: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD14: push 0x41B76C
	{ auto _pv = (uint32_t)(4306796); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD19: jmp 0x001FAD4A
	goto loc_1FAD4A;
loc_1FAD1B:
	// 0x1FAD1B: cmp [esi+0x4C], ebp
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu); uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FAD1E: jnz 0x001FAD41
	if (!ctx.flags.zf) goto loc_1FAD41;
	// 0x1FAD20: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD25: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD26: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD28: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD2A: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD2C: push 0x5C
	{ auto _pv = (uint32_t)(92); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD2E: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FAD33: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAD36: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FAD38: mov [esi+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.eax);
	// 0x1FAD3B: jz 0x001FAE82
	if (ctx.flags.zf) goto loc_1FAE82;
loc_1FAD41:
	// 0x1FAD41: mov eax, [esi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1FAD44: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD49: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_1FAD4A:
	// 0x1FAD4A: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x1FAD4F: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAD52: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FAD54: jz 0x001FAE82
	if (ctx.flags.zf) goto loc_1FAE82;
	// 0x1FAD5A: mov dword ptr [eax+0x54], 0x01
	X86_MEM_WRITE_u32(base, ctx.eax + 0x54u, 1);
	// 0x1FAD61: mov ebx, eax
	ctx.ebx = ctx.eax;
loc_1FAD63:
	// 0x1FAD63: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD64: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAD65: call 0x001FE3D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaUniqueIDInitialize(ctx, base);
	ctx.esp += 4;
	// 0x1FAD6A: mov ecx, [esp+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FAD6E: lea edi, [ebx+0x10]
	ctx.edi = ctx.ebx + 0x10u;
	// 0x1FAD71: mov [ebx+0x4C], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4Cu, ctx.ebp);
	// 0x1FAD74: mov [ebx+0x48], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x48u, ctx.ebp);
	// 0x1FAD77: mov [edi], ebp
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ebp);
	// 0x1FAD79: mov [ebx+0x14], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x14u, ctx.ebp);
	// 0x1FAD7C: mov [ebx+0x18], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x18u, ctx.ebp);
	// 0x1FAD7F: mov [ebx+0x20], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x20u, ctx.ebp);
	// 0x1FAD82: mov [ebx+0x24], ebp
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x24u, ctx.ebp);
	// 0x1FAD85: mov ebp, [esp+0x20]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FAD89: mov [ebx+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xCu, ctx.esi);
	// 0x1FAD8C: mov [ebx+0x58], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x58u, ctx.ecx);
	// 0x1FAD8F: mov byte ptr [ebx+0x1C], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x1Cu, 0);
	// 0x1FAD93: mov byte ptr [ebx+0x1D], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x1Du, 0);
	// 0x1FAD97: mov byte ptr [ebx+0x28], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x28u, 0);
	// 0x1FAD9B: mov byte ptr [ebx+0x29], 0x00
	X86_MEM_WRITE_u8(base, ctx.ebx + 0x29u, 0);
	// 0x1FAD9F: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FADA4: mov esi, ebp
	ctx.esi = ctx.ebp;
	// 0x1FADA6: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FADA8: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1FADAB: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FADAE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FADB0: jz 0x001FADE8
	if (ctx.flags.zf) goto loc_1FADE8;
	// 0x1FADB2: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FADB5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FADB7: jbe 0x001FADE8
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FADE8;
	// 0x1FADB9: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FADBE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FADBF: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1FADC4: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FADC7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FADC9: mov [ebx+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x20u, ctx.eax);
	// 0x1FADCC: jz 0x001FAE65
	if (ctx.flags.zf) goto loc_1FAE65;
	// 0x1FADD2: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FADD5: mov esi, [ebp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1FADD8: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FADDA: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FADDD: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FADDF: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FADE1: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x1FADE3: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FADE6: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
loc_1FADE8:
	// 0x1FADE8: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FADEC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FADED: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1FADEF: call 0x001FA940
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaWaveSetTargetFormat(ctx, base);
	ctx.esp += 4;
	// 0x1FADF4: mov al, [ebx+0x39]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + 0x39u);
	// 0x1FADF7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FADFA: cmp al, 0x01
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FADFC: jnz 0x001FAE11
	if (!ctx.flags.zf) goto loc_1FAE11;
	// 0x1FADFE: mov ecx, [esp+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1FAE02: mov eax, [ebx+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x54u);
	// 0x1FAE05: neg ecx
	{ uint32_t _d = ctx.ecx;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.ecx = _res; }
	// 0x1FAE07: sbb ecx, ecx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FAE09: and ecx, 0x02
	ctx.ecx = ctx.ecx & 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FAE0C: or eax, ecx
	ctx.eax = ctx.eax | ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FAE0E: mov [ebx+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x54u, ctx.eax);
loc_1FAE11:
	// 0x1FAE11: mov edx, [ebx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0xCu);
	// 0x1FAE14: mov eax, [edx+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x44u);
	// 0x1FAE17: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAE19: jz 0x001FAE3E
	if (ctx.flags.zf) goto loc_1FAE3E;
	// 0x1FAE1B: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FAE1F: mov ecx, [eax+0x44]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x44u);
	// 0x1FAE22: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE27: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE28: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1FAE2D: mov [ebx+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x50u, ctx.eax);
	// 0x1FAE30: mov eax, [ebx+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x54u);
	// 0x1FAE33: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAE36: or eax, 0x08
	ctx.eax = ctx.eax | 8;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FAE39: mov [ebx+0x54], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x54u, ctx.eax);
	// 0x1FAE3C: jmp 0x001FAE45
	goto loc_1FAE45;
loc_1FAE3E:
	// 0x1FAE3E: mov dword ptr [ebx+0x50], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x50u, 0);
loc_1FAE45:
	// 0x1FAE45: mov edx, [ebx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0xCu);
	// 0x1FAE48: mov eax, [edx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x1FAE4B: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAE4D: jz 0x001FAE6C
	if (ctx.flags.zf) goto loc_1FAE6C;
	// 0x1FAE4F: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FAE53: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE54: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE55: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x1FAE57: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAE5A: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAE5C: jnz 0x001FAE6C
	if (!ctx.flags.zf) goto loc_1FAE6C;
	// 0x1FAE5E: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x1FAE60: call 0x001FA8F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA8F0(ctx, base);
	ctx.esp += 4;
loc_1FAE65:
	// 0x1FAE65: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE66: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE67: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE68: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FAE6A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE6B: ret
	return;
loc_1FAE6C:
	// 0x1FAE6C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE6D: call 0x001F65F0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F65F0(ctx, base);
	ctx.esp += 4;
	// 0x1FAE72: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE73: call 0x001F65B0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F65B0(ctx, base);
	ctx.esp += 4;
	// 0x1FAE78: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAE7B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE7C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE7D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE7E: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FAE80: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE81: ret
	return;
loc_1FAE82:
	// 0x1FAE82: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE83: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE84: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FAE86: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAE87: ret
	return;
}

void sub_1FAE90(X86Context& ctx, uint8_t* base) {
	// 0x1FAE90: sub esp, 0x1C
	{ uint32_t _d = ctx.esp; uint32_t _s = 28;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAE93: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE94: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAE95: mov ebp, [esp+0x28]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1FAE99: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x1FAE9C: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x1FAE9F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEA0: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEA1: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FAEA3: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAEA5: lea esi, [ebp+0x10]
	ctx.esi = ctx.ebp + 0x10u;
	// 0x1FAEA8: lea ebx, [ebp+0x2C]
	ctx.ebx = ctx.ebp + 0x2Cu;
	// 0x1FAEAB: mov [esp+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.eax);
	// 0x1FAEAF: jz 0x001FAF30
	if (ctx.flags.zf) goto loc_1FAF30;
	// 0x1FAEB1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEB2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEB3: call 0x001F9D80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9D80(ctx, base);
	ctx.esp += 4;
	// 0x1FAEB8: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAEBB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAEBD: jnz 0x001FAF3E
	if (!ctx.flags.zf) goto loc_1FAF3E;
	// 0x1FAEBF: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FAEC4: lea edi, [esp+0x10]
	ctx.edi = ctx.esp + 0x10u;
	// 0x1FAEC8: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FAECA: mov ecx, [esp+0x34]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x34u);
	// 0x1FAECE: mov edi, [esp+0x38]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
	// 0x1FAED2: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAED3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAED4: lea edx, [esp+0x18]
	ctx.edx = ctx.esp + 0x18u;
	// 0x1FAED8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAED9: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEDA: call 0x00204B60
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_204B60(ctx, base);
	ctx.esp += 4;
	// 0x1FAEDF: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEE0: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FAEE2: mov eax, [esp+0x50]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x50u);
	// 0x1FAEE6: lea ecx, [esp+0x24]
	ctx.ecx = ctx.esp + 0x24u;
	// 0x1FAEEA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEEB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEEC: mov [esp+0x34], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x34u, ctx.eax);
	// 0x1FAEF0: call 0x00204B90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_204B90(ctx, base);
	ctx.esp += 4;
	// 0x1FAEF5: push 0x30806
	{ auto _pv = (uint32_t)(198662); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEFA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAEFB: mov [esp+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x60u, ctx.eax);
	// 0x1FAEFF: call 0x001FED90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FED90(ctx, base);
	ctx.esp += 4;
	// 0x1FAF04: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FAF06: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAF09: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FAF0B: jz 0x001FAF30
	if (ctx.flags.zf) goto loc_1FAF30;
	// 0x1FAF0D: mov edx, [esp+0x38]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
	// 0x1FAF11: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF12: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF13: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF15: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF16: lea eax, [esp+0x20]
	ctx.eax = ctx.esp + 0x20u;
	// 0x1FAF1A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF1B: call 0x00204BB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_204BB0(ctx, base);
	ctx.esp += 4;
	// 0x1FAF20: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAF23: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAF25: jnz 0x001FAF3A
	if (!ctx.flags.zf) goto loc_1FAF3A;
	// 0x1FAF27: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF28: call 0x001FEE90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaFreeAligned(ctx, base);
	ctx.esp += 4;
	// 0x1FAF2D: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAF30:
	// 0x1FAF30: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF31: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF32: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF33: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FAF35: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF36: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAF39: ret
	return;
loc_1FAF3A:
	// 0x1FAF3A: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x1FAF3C: jmp 0x001FAF46
	goto loc_1FAF46;
loc_1FAF3E:
	// 0x1FAF3E: mov esi, [esp+0x34]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x34u);
	// 0x1FAF42: mov ecx, [esp+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
loc_1FAF46:
	// 0x1FAF46: mov eax, [esp+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1FAF4A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF4B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF4C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF4D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF4E: mov [0x0041B794], ebp
	X86_MEM_WRITE_u32(base, 0x41B794u, ctx.ebp);
	// 0x1FAF54: mov [0x0041B798], esi
	X86_MEM_WRITE_u32(base, 0x41B798u, ctx.esi);
	// 0x1FAF5A: call [esp+0x40]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FAF5E: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FAF60: mov ecx, [esi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1FAF63: or ecx, 0x10
	ctx.ecx = ctx.ecx | 16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FAF66: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAF69: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FAF6B: mov [esi+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x54u, ctx.ecx);
	// 0x1FAF6E: jz 0x001FAF89
	if (ctx.flags.zf) goto loc_1FAF89;
loc_1FAF70:
	// 0x1FAF70: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1FAF73: mov eax, [ecx+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x1Cu);
	// 0x1FAF76: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAF78: jz 0x001FAF80
	if (ctx.flags.zf) goto loc_1FAF80;
	// 0x1FAF7A: call eax
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.eax);
	ctx.esp += 4;
	// 0x1FAF7C: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAF7E: jnz 0x001FAF70
	if (!ctx.flags.zf) goto loc_1FAF70;
loc_1FAF80:
	// 0x1FAF80: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAF81: call 0x001FEE90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaFreeAligned(ctx, base);
	ctx.esp += 4;
	// 0x1FAF86: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FAF89:
	// 0x1FAF89: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF8A: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FAF8C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF8D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF8E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FAF8F: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAF92: ret
	return;
}

void sub_1FAFA0(X86Context& ctx, uint8_t* base) {
	// 0x1FAFA0: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FAFA4: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FAFA8: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FAFAC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFAD: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FAFB1: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFB2: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FAFB6: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFB7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFB8: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFB9: push 0x41B7B8
	{ auto _pv = (uint32_t)(4306872); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFBE: call 0x001F6050
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FAFC3: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAFC6: ret
	return;
}

void RwaVirtualVoiceUnregister(X86Context& ctx, uint8_t* base) {
	// 0x1FAFD0: mov eax, [0x0041B81C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B81Cu);
	// 0x1FAFD5: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAFD7: jz 0x001FAFED
	if (ctx.flags.zf) goto loc_1FAFED;
	// 0x1FAFD9: call 0x00207E40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVirtualVoiceInterfaceUnregister(ctx, base);
	ctx.esp += 4;
	// 0x1FAFDE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FAFE0: jnz 0x001FAFE3
	if (!ctx.flags.zf) goto loc_1FAFE3;
	// 0x1FAFE2: ret
	return;
loc_1FAFE3:
	// 0x1FAFE3: mov dword ptr [0x0041B81C], 0x00
	X86_MEM_WRITE_u32(base, 0x41B81Cu, 0);
loc_1FAFED:
	// 0x1FAFED: push 0x41B7B8
	{ auto _pv = (uint32_t)(4306872); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FAFF2: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1FAFF7: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FAFFA: ret
	return;
}

void RwaVirtualVoiceCreate(X86Context& ctx, uint8_t* base) {
	// 0x1FB000: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB001: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB002: mov ebp, [esp+0x0C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB006: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB007: lea esi, [ebp+0x28]
	ctx.esi = ctx.ebp + 0x28u;
	// 0x1FB00A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB00B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FB00D: mov ecx, 0x19
	ctx.ecx = 25;
	// 0x1FB012: mov edi, esi
	ctx.edi = ctx.esi;
	// 0x1FB014: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FB016: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FB018: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB019: mov [esi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebx);
	// 0x1FB01C: mov [esi], ebx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ebx);
	// 0x1FB01E: call 0x001FC030
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerRegisterVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FB023: mov eax, [esp+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FB027: mov cl, [eax]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax);
	// 0x1FB029: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB02C: mov al, 0x7F
	X86_REG8L(ctx.eax) = (uint8_t)(127);
	// 0x1FB02E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB02F: and cl, 0x18
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) & 24;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x1FB032: mov [esi+0x63], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x63u, X86_REG8L(ctx.ebx));
	// 0x1FB035: mov [esi+0x4C], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ebx);
	// 0x1FB038: mov [esi+0x44], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.ebx);
	// 0x1FB03B: mov [esi+0x48], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.ebx);
	// 0x1FB03E: mov [esi+0x5C], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x5Cu, X86_REG8L(ctx.eax));
	// 0x1FB041: mov [esi+0x5F], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x5Fu, X86_REG8L(ctx.eax));
	// 0x1FB044: mov [esi+0x60], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x60u, X86_REG8L(ctx.eax));
	// 0x1FB047: mov [esi+0x38], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.ebx);
	// 0x1FB04A: mov [esi+0x62], cl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_REG8L(ctx.ecx));
	// 0x1FB04D: mov dword ptr [esi+0x50], 0x46AC4400
	X86_MEM_WRITE_u32(base, ctx.esi + 0x50u, 1185694720);
	// 0x1FB054: mov byte ptr [esi+0x5D], 0xFF
	X86_MEM_WRITE_u8(base, ctx.esi + 0x5Du, -1);
	// 0x1FB058: mov dword ptr [esi+0x54], 0x3F800000
	X86_MEM_WRITE_u32(base, ctx.esi + 0x54u, 1065353216);
	// 0x1FB05F: mov dword ptr [esi+0x58], 0x461C4000
	X86_MEM_WRITE_u32(base, ctx.esi + 0x58u, 1176256512);
	// 0x1FB066: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB067: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1FB069: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB06A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB06B: ret
	return;
}

void RwaVirtualVoiceDestroy(X86Context& ctx, uint8_t* base) {
	// 0x1FB070: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB071: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB072: mov edi, [esp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB076: lea esi, [edi+0x28]
	ctx.esi = ctx.edi + 0x28u;
	// 0x1FB079: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB07B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB07C: call 0x001FC690
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerUpdateVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FB081: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FB083: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB086: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB088: jz 0x001FB099
	if (ctx.flags.zf) goto loc_1FB099;
	// 0x1FB08A: mov eax, [edi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x2Cu);
	// 0x1FB08D: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FB08F: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1FB091: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FB093: mov eax, [edi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x2Cu);
	// 0x1FB096: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
loc_1FB099:
	// 0x1FB099: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB09A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB09B: ret
	return;
}

void RwaVirtualVoiceStartExecute(X86Context& ctx, uint8_t* base) {
	// 0x1FB0A0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0A1: mov ebx, [esp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB0A5: mov al, [ebx+0x8A]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebx + 0x8Au);
	// 0x1FB0AB: test al, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 2, 8);
	// 0x1FB0AD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0AE: lea esi, [ebx+0x28]
	ctx.esi = ctx.ebx + 0x28u;
	// 0x1FB0B1: jz 0x001FB0E2
	if (ctx.flags.zf) goto loc_1FB0E2;
	// 0x1FB0B3: mov eax, [esi+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1FB0B6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB0B8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0B9: mov edi, 0x02
	ctx.edi = 2;
	// 0x1FB0BE: jz 0x001FB0D7
	if (ctx.flags.zf) goto loc_1FB0D7;
	// 0x1FB0C0: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0C2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0C3: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0C5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0C6: call 0x001FBBB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBBB0(ctx, base);
	ctx.esp += 4;
	// 0x1FB0CB: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB0CE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB0D0: jnz 0x001FB0D7
	if (!ctx.flags.zf) goto loc_1FB0D7;
	// 0x1FB0D2: mov edi, 0x01
	ctx.edi = 1;
loc_1FB0D7:
	// 0x1FB0D7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0D8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB0D9: call 0x001FC690
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerUpdateVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FB0DE: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB0E1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FB0E2:
	// 0x1FB0E2: and byte ptr [esi+0x62], 0xDF
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_MEM_READ_u8(base, ctx.esi + 0x62u) & -33);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x62u), 8);
	// 0x1FB0E6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB0E7: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FB0E9: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB0EA: ret
	return;
}

void RwaVirtualVoiceGetParams(X86Context& ctx, uint8_t* base) {
	// 0x1FB0F0: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB0F4: mov dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, 0);
	// 0x1FB0FA: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB0FE: ret
	return;
}

void sub_1FB100(X86Context& ctx, uint8_t* base) {
	// 0x1FB100: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB104: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB106: jz 0x001FB126
	if (ctx.flags.zf) goto loc_1FB126;
	// 0x1FB108: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB109: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB10D: lea eax, [esi+0x28]
	ctx.eax = ctx.esi + 0x28u;
	// 0x1FB110: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB112: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB113: call 0x001FC690
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerUpdateVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FB118: mov ecx, [0x0041B880]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FB11E: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB121: mov [esi+0x74], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x74u, ctx.ecx);
	// 0x1FB124: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB125: ret
	return;
loc_1FB126:
	// 0x1FB126: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB12A: add edx, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)40, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FB12D: mov dword ptr [esp+0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, 1);
	// 0x1FB135: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1FB139: jmp 0x001FC690
	RwaVoiceManagerUpdateVoice(ctx, base);
	return;
}

void sub_1FB140(X86Context& ctx, uint8_t* base) {
	// 0x1FB140: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB144: mov ecx, [eax+0x64]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x64u);
	// 0x1FB147: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FB149: jz 0x001FB152
	if (ctx.flags.zf) goto loc_1FB152;
	// 0x1FB14B: mov dword ptr [eax+0x64], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x64u, 0);
loc_1FB152:
	// 0x1FB152: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB156: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FB158: jz 0x001FB17E
	if (ctx.flags.zf) goto loc_1FB17E;
	// 0x1FB15A: test byte ptr [eax+0x8A], 0x20
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x8Au) & 32, 8);
	// 0x1FB161: mov [eax+0x64], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x64u, ctx.ecx);
	// 0x1FB164: jnz 0x001FB17E
	if (!ctx.flags.zf) goto loc_1FB17E;
	// 0x1FB166: mov ecx, [ecx+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x2Cu);
	// 0x1FB169: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FB16B: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FB16F: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FB173: jnl 0x001FB17B
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FB17B;
	// 0x1FB175: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1FB17B:
	// 0x1FB17B: fstp [eax+0x78]
	X86_MEM_WRITE_F32(base, ctx.eax + 0x78u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_1FB17E:
	// 0x1FB17E: mov ecx, [eax+0x60]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x60u);
	// 0x1FB181: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FB183: jz 0x001FB196
	if (ctx.flags.zf) goto loc_1FB196;
	// 0x1FB185: mov edx, [eax+0x64]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x64u);
	// 0x1FB188: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB189: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB18B: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB18D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB18E: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FB193: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB196:
	// 0x1FB196: ret
	return;
}

void sub_1FB1A0(X86Context& ctx, uint8_t* base) {
	// 0x1FB1A0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB1A4: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB1A8: mov [eax+0x68], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x68u, ctx.ecx);
	// 0x1FB1AB: mov eax, [eax+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x60u);
	// 0x1FB1AE: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB1B0: jz 0x001FB1C0
	if (ctx.flags.zf) goto loc_1FB1C0;
	// 0x1FB1B2: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB1B3: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB1B5: push 0x0E
	{ auto _pv = (uint32_t)(14); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB1B7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB1B8: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FB1BD: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB1C0:
	// 0x1FB1C0: ret
	return;
}

void sub_1FB1D0(X86Context& ctx, uint8_t* base) {
	// 0x1FB1D0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB1D4: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x1FB1D6: fmul [0x003B16C4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16C4u));
	// 0x1FB1DC: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FB1E1: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB1E5: mov [ecx+0x84], al
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x84u, X86_REG8L(ctx.eax));
	// 0x1FB1EB: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1FB1ED: ret
	return;
}

void sub_1FB1F0(X86Context& ctx, uint8_t* base) {
	// 0x1FB1F0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB1F4: movzx ecx, byte ptr [eax+0x84]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x84u));
	// 0x1FB1FB: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB1FF: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FB203: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FB207: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FB20D: fstp [edx]
	X86_MEM_WRITE_F32(base, ctx.edx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FB20F: ret
	return;
}

void sub_1FB210(X86Context& ctx, uint8_t* base) {
	// 0x1FB210: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB214: fld [eax]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.eax));
	// 0x1FB216: fmul [0x003B16C4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16C4u));
	// 0x1FB21C: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FB221: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB225: mov [ecx+0x87], al
	X86_MEM_WRITE_u8(base, ctx.ecx + 0x87u, X86_REG8L(ctx.eax));
	// 0x1FB22B: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1FB22D: ret
	return;
}

void sub_1FB230(X86Context& ctx, uint8_t* base) {
	// 0x1FB230: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB234: movzx ecx, byte ptr [eax+0x87]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x87u));
	// 0x1FB23B: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB23F: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FB243: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FB247: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FB24D: fstp [edx]
	X86_MEM_WRITE_F32(base, ctx.edx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FB24F: ret
	return;
}

void sub_1FB250(X86Context& ctx, uint8_t* base) {
	// 0x1FB250: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB254: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB255: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB259: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB25A: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FB25C: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1FB25E: lea eax, [esi+0x30]
	ctx.eax = ctx.esi + 0x30u;
	// 0x1FB261: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1FB263: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FB266: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x1FB269: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1FB26C: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x1FB26F: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB272: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB274: jz 0x001FB284
	if (ctx.flags.zf) goto loc_1FB284;
	// 0x1FB276: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB277: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB279: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB27B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB27C: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FB281: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB284:
	// 0x1FB284: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB285: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB287: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB288: ret
	return;
}

void sub_1FB290(X86Context& ctx, uint8_t* base) {
	// 0x1FB290: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB294: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB298: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB299: lea ecx, [eax+0x30]
	ctx.ecx = ctx.eax + 0x30u;
	// 0x1FB29C: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB29E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1FB2A0: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FB2A3: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1FB2A6: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1FB2A9: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1FB2AC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB2AD: ret
	return;
}

void sub_1FB2B0(X86Context& ctx, uint8_t* base) {
	// 0x1FB2B0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB2B4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2B5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB2B9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2BA: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FB2BC: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1FB2BE: lea eax, [esi+0x3C]
	ctx.eax = ctx.esi + 0x3Cu;
	// 0x1FB2C1: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1FB2C3: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FB2C6: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x1FB2C9: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1FB2CC: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x1FB2CF: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB2D2: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB2D4: jz 0x001FB2E4
	if (ctx.flags.zf) goto loc_1FB2E4;
	// 0x1FB2D6: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2D7: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2D9: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2DB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2DC: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FB2E1: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB2E4:
	// 0x1FB2E4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB2E5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB2E7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB2E8: ret
	return;
}

void sub_1FB2F0(X86Context& ctx, uint8_t* base) {
	// 0x1FB2F0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB2F4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2F5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB2F9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB2FA: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FB2FC: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1FB2FE: lea eax, [esi+0x48]
	ctx.eax = ctx.esi + 0x48u;
	// 0x1FB301: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1FB303: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FB306: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x1FB309: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1FB30C: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x1FB30F: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB312: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB314: jz 0x001FB324
	if (ctx.flags.zf) goto loc_1FB324;
	// 0x1FB316: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB317: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB319: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB31B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB31C: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FB321: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB324:
	// 0x1FB324: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB325: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB327: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB328: ret
	return;
}

void sub_1FB330(X86Context& ctx, uint8_t* base) {
	// 0x1FB330: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB334: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB335: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB339: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB33A: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FB33C: mov edi, [edx]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1FB33E: lea eax, [esi+0x54]
	ctx.eax = ctx.esi + 0x54u;
	// 0x1FB341: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x1FB343: mov edi, [edx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FB346: mov [eax+0x04], edi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edi);
	// 0x1FB349: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1FB34C: mov [eax+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.edx);
	// 0x1FB34F: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB352: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB354: jz 0x001FB364
	if (ctx.flags.zf) goto loc_1FB364;
	// 0x1FB356: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB357: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB359: push 0x03
	{ auto _pv = (uint32_t)(3); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB35B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB35C: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FB361: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB364:
	// 0x1FB364: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB365: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB367: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB368: ret
	return;
}

void sub_1FB370(X86Context& ctx, uint8_t* base) {
	// 0x1FB370: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB374: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB378: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB379: lea ecx, [eax+0x54]
	ctx.ecx = ctx.eax + 0x54u;
	// 0x1FB37C: mov esi, [ecx]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB37E: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1FB380: mov esi, [ecx+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FB383: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1FB386: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1FB389: mov [edx+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.ecx);
	// 0x1FB38C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB38D: ret
	return;
}

void sub_1FB390(X86Context& ctx, uint8_t* base) {
	// 0x1FB390: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB394: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB396: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB397: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB39B: mov [esi+0x7C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x7Cu, ctx.eax);
	// 0x1FB39E: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB3A1: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB3A3: jz 0x001FB3B5
	if (ctx.flags.zf) goto loc_1FB3B5;
	// 0x1FB3A5: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB3A7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3A8: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3AA: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3AC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3AD: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB3B2: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB3B5:
	// 0x1FB3B5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB3B7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB3B8: ret
	return;
}

void sub_1FB3C0(X86Context& ctx, uint8_t* base) {
	// 0x1FB3C0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB3C4: mov ecx, [eax+0x7C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x7Cu);
	// 0x1FB3C7: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB3CB: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1FB3CD: ret
	return;
}

void sub_1FB3D0(X86Context& ctx, uint8_t* base) {
	// 0x1FB3D0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB3D4: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB3D6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3D7: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB3DB: mov [esi+0x80], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x80u, ctx.eax);
	// 0x1FB3E1: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB3E4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB3E6: jz 0x001FB3F8
	if (ctx.flags.zf) goto loc_1FB3F8;
	// 0x1FB3E8: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB3EA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3EB: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3ED: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3EF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB3F0: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB3F5: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB3F8:
	// 0x1FB3F8: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB3FA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB3FB: ret
	return;
}

void sub_1FB400(X86Context& ctx, uint8_t* base) {
	// 0x1FB400: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB404: mov ecx, [eax+0x80]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x80u);
	// 0x1FB40A: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB40E: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1FB410: ret
	return;
}

void sub_1FB420(X86Context& ctx, uint8_t* base) {
	// 0x1FB420: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB424: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB426: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB427: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB42B: mov [esi+0x78], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x78u, ctx.eax);
	// 0x1FB42E: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB431: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB433: jz 0x001FB445
	if (ctx.flags.zf) goto loc_1FB445;
	// 0x1FB435: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB437: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB438: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB43A: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB43C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB43D: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB442: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB445:
	// 0x1FB445: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB447: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB448: ret
	return;
}

void sub_1FB450(X86Context& ctx, uint8_t* base) {
	// 0x1FB450: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB454: mov ecx, [eax+0x78]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x78u);
	// 0x1FB457: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB45B: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1FB45D: ret
	return;
}

void sub_1FB460(X86Context& ctx, uint8_t* base) {
	// 0x1FB460: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB461: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB462: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FB466: fld [edi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi));
	// 0x1FB468: fmul [0x003B16C4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16C4u));
	// 0x1FB46E: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FB473: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB477: mov [esi+0x85], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x85u, X86_REG8L(ctx.eax));
	// 0x1FB47D: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB480: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB482: jz 0x001FB494
	if (ctx.flags.zf) goto loc_1FB494;
	// 0x1FB484: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FB486: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB487: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB489: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB48B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB48C: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB491: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB494:
	// 0x1FB494: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB495: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB497: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB498: ret
	return;
}

void sub_1FB4A0(X86Context& ctx, uint8_t* base) {
	// 0x1FB4A0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB4A4: movzx ecx, byte ptr [eax+0x85]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x85u));
	// 0x1FB4AB: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB4AF: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FB4B3: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FB4B7: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FB4BD: fstp [edx]
	X86_MEM_WRITE_F32(base, ctx.edx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FB4BF: ret
	return;
}

void sub_1FB4C0(X86Context& ctx, uint8_t* base) {
	// 0x1FB4C0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB4C4: cmp dword ptr [eax], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FB4C7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB4C8: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB4CC: jz 0x001FB4E9
	if (ctx.flags.zf) goto loc_1FB4E9;
	// 0x1FB4CE: lea ecx, [esi+0x28]
	ctx.ecx = ctx.esi + 0x28u;
	// 0x1FB4D1: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB4D3: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB4D4: call 0x001FC690
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerUpdateVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FB4D9: mov edx, [0x0041B880]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FB4DF: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB4E2: mov [esi+0x74], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x74u, ctx.edx);
	// 0x1FB4E5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB4E7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB4E8: ret
	return;
loc_1FB4E9:
	// 0x1FB4E9: lea eax, [esi+0x28]
	ctx.eax = ctx.esi + 0x28u;
	// 0x1FB4EC: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB4EE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB4EF: call 0x001FC690
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerUpdateVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FB4F4: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB4F7: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB4F9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB4FA: ret
	return;
}

void sub_1FB500(X86Context& ctx, uint8_t* base) {
	// 0x1FB500: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB504: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB508: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FB50A: mov cl, [eax+0x8A]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x8Au);
	// 0x1FB510: shr ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FB512: and ecx, 0x01
	ctx.ecx = ctx.ecx & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FB515: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1FB517: ret
	return;
}

void sub_1FB520(X86Context& ctx, uint8_t* base) {
	// 0x1FB520: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB524: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB526: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB527: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB52B: mov [esi+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, ctx.eax);
	// 0x1FB52E: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB531: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB533: jz 0x001FB545
	if (ctx.flags.zf) goto loc_1FB545;
	// 0x1FB535: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB537: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB538: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB53A: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB53C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB53D: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB542: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB545:
	// 0x1FB545: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB547: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB548: ret
	return;
}

void sub_1FB550(X86Context& ctx, uint8_t* base) {
	// 0x1FB550: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB551: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB555: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB558: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB55A: jz 0x001FB581
	if (ctx.flags.zf) goto loc_1FB581;
	// 0x1FB55C: test byte ptr [esi+0x8A], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x8Au) & 2, 8);
	// 0x1FB563: jz 0x001FB581
	if (ctx.flags.zf) goto loc_1FB581;
	// 0x1FB565: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB567: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB569: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB56B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB56C: call 0x001FBBB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBBB0(ctx, base);
	ctx.esp += 4;
	// 0x1FB571: mov ecx, [esp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FB575: mov [esi+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, ctx.eax);
	// 0x1FB578: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB57B: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x1FB57D: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB57F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB580: ret
	return;
loc_1FB581:
	// 0x1FB581: mov eax, [esi+0x6C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x6Cu);
	// 0x1FB584: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FB588: mov [esi+0x6C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, ctx.eax);
	// 0x1FB58B: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x1FB58D: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB58F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB590: ret
	return;
}

void sub_1FB5A0(X86Context& ctx, uint8_t* base) {
	// 0x1FB5A0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB5A4: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB5A6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB5A7: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB5AB: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB5AD: mov al, [esi+0x8A]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x8Au);
	// 0x1FB5B3: jz 0x001FB5B9
	if (ctx.flags.zf) goto loc_1FB5B9;
	// 0x1FB5B5: or al, 0x04
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) | 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x1FB5B7: jmp 0x001FB5BB
	goto loc_1FB5BB;
loc_1FB5B9:
	// 0x1FB5B9: and al, 0xFB
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & -5;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
loc_1FB5BB:
	// 0x1FB5BB: mov [esi+0x8A], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x8Au, X86_REG8L(ctx.eax));
	// 0x1FB5C1: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB5C4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB5C6: jz 0x001FB5D8
	if (ctx.flags.zf) goto loc_1FB5D8;
	// 0x1FB5C8: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FB5CA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB5CB: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB5CD: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB5CF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB5D0: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB5D5: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB5D8:
	// 0x1FB5D8: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB5DA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB5DB: ret
	return;
}

void sub_1FB5E0(X86Context& ctx, uint8_t* base) {
	// 0x1FB5E0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB5E4: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB5E8: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FB5EA: mov cl, [eax+0x8A]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x8Au);
	// 0x1FB5F0: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FB5F3: and ecx, 0x01
	ctx.ecx = ctx.ecx & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FB5F6: mov [edx], ecx
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.ecx);
	// 0x1FB5F8: ret
	return;
}

void sub_1FB600(X86Context& ctx, uint8_t* base) {
	// 0x1FB600: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB604: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB605: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB609: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB60A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB60B: call 0x001FB140
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FB140(ctx, base);
	ctx.esp += 4;
	// 0x1FB610: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB613: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB615: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB616: ret
	return;
}

void sub_1FB620(X86Context& ctx, uint8_t* base) {
	// 0x1FB620: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB621: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB622: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FB626: fld [edi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi));
	// 0x1FB628: fmul [0x003B170C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B170Cu));
	// 0x1FB62E: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FB633: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB637: mov [esi+0x8B], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x8Bu, X86_REG8L(ctx.eax));
	// 0x1FB63D: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB640: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB642: jz 0x001FB654
	if (ctx.flags.zf) goto loc_1FB654;
	// 0x1FB644: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FB646: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB647: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB649: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB64B: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB64C: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB651: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB654:
	// 0x1FB654: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB655: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB657: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB658: ret
	return;
}

void sub_1FB660(X86Context& ctx, uint8_t* base) {
	// 0x1FB660: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB664: movsx ecx, byte ptr [eax+0x8B]
	ctx.ecx = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x8Bu)));
	// 0x1FB66B: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB66F: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FB673: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FB677: fmul [0x003B1700]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B1700u));
	// 0x1FB67D: fstp [edx]
	X86_MEM_WRITE_F32(base, ctx.edx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FB67F: ret
	return;
}

void sub_1FB680(X86Context& ctx, uint8_t* base) {
	// 0x1FB680: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB684: mov dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, 0);
	// 0x1FB68A: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB68E: ret
	return;
}

void sub_1FB690(X86Context& ctx, uint8_t* base) {
	// 0x1FB690: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB691: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB692: mov edi, [esp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FB696: fld [edi]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, ctx.edi));
	// 0x1FB698: fmul [0x003B16C4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16C4u));
	// 0x1FB69E: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FB6A3: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB6A7: mov [esi+0x86], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x86u, X86_REG8L(ctx.eax));
	// 0x1FB6AD: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB6B0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB6B2: jz 0x001FB6C4
	if (ctx.flags.zf) goto loc_1FB6C4;
	// 0x1FB6B4: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FB6B6: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB6B7: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB6B9: push 0x0D
	{ auto _pv = (uint32_t)(13); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB6BB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB6BC: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FB6C1: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB6C4:
	// 0x1FB6C4: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB6C5: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB6C7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB6C8: ret
	return;
}

void sub_1FB6D0(X86Context& ctx, uint8_t* base) {
	// 0x1FB6D0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FB6D4: movzx ecx, byte ptr [eax+0x86]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.eax + 0x86u));
	// 0x1FB6DB: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB6DF: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FB6E3: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FB6E7: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FB6ED: fstp [edx]
	X86_MEM_WRITE_F32(base, ctx.edx, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FB6EF: ret
	return;
}

void sub_1FB6F0(X86Context& ctx, uint8_t* base) {
	// 0x1FB6F0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FB6F4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB6F5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FB6F9: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FB6FC: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB6FE: mov [esi+0x68], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x68u, ctx.ecx);
	// 0x1FB701: jz 0x001FB711
	if (ctx.flags.zf) goto loc_1FB711;
	// 0x1FB703: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB704: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB706: push 0x0E
	{ auto _pv = (uint32_t)(14); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB708: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB709: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FB70E: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB711:
	// 0x1FB711: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB713: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB714: ret
	return;
}

void RwaVirtualVoiceRegisterCommon(X86Context& ctx, uint8_t* base) {
	// 0x1FB720: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB721: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB723: push 0x36DC8C
	{ auto _pv = (uint32_t)(3595404); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB728: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB729: call 0x001F8550
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1FB72E: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB730: mov dword ptr [esi+0x40], 0x64
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, 100);
	// 0x1FB737: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB73C: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB741: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB744: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB746: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB748: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB74B: jz 0x001FB765
	if (ctx.flags.zf) goto loc_1FB765;
	// 0x1FB74D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB74F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB754: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB759: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB75C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB75E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB760: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB763: jmp 0x001FB76A
	goto loc_1FB76A;
loc_1FB765:
	// 0x1FB765: mov eax, 0x01
	ctx.eax = 1;
loc_1FB76A:
	// 0x1FB76A: test eax, 0xFFFF0000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & -65536, 32);
	// 0x1FB76F: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB771: jz 0x001FB86D
	if (ctx.flags.zf) goto loc_1FB86D;
	// 0x1FB777: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB77C: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB781: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB784: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB786: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB788: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB78B: jz 0x001FB7A8
	if (ctx.flags.zf) goto loc_1FB7A8;
	// 0x1FB78D: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB78F: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB794: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB799: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB79C: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB79E: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB7A0: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB7A3: mov [esp], eax
	X86_MEM_WRITE_u32(base, ctx.esp, ctx.eax);
	// 0x1FB7A6: jmp 0x001FB7AF
	goto loc_1FB7AF;
loc_1FB7A8:
	// 0x1FB7A8: mov dword ptr [esp], 0x01
	X86_MEM_WRITE_u32(base, ctx.esp, 1);
loc_1FB7AF:
	// 0x1FB7AF: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FB7B1: mov ch, [esp+0x03]
	X86_REG8H(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esp + 0x3u);
	// 0x1FB7B5: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB7B7: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FB7B9: jz 0x001FB816
	if (ctx.flags.zf) goto loc_1FB816;
	// 0x1FB7BB: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB7C0: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB7C5: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB7C8: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB7CA: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB7CC: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB7CF: jz 0x001FB7FC
	if (ctx.flags.zf) goto loc_1FB7FC;
	// 0x1FB7D1: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB7D3: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB7D8: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB7DD: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB7E0: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB7E2: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB7E4: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB7E7: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB7EA: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB7F1: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB7F4: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB7F7: jmp 0x001FB931
	goto loc_1FB931;
loc_1FB7FC:
	// 0x1FB7FC: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FB801: sar eax, 0x18
	{ auto _cnt = 0x18u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB804: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB80B: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB80E: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB811: jmp 0x001FB931
	goto loc_1FB931;
loc_1FB816:
	// 0x1FB816: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB81B: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB820: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB823: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB825: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB827: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB82A: jz 0x001FB855
	if (ctx.flags.zf) goto loc_1FB855;
	// 0x1FB82C: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB82E: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB833: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB838: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB83B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB83D: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB83F: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB842: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB845: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB84C: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB84D: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB850: jmp 0x001FB931
	goto loc_1FB931;
loc_1FB855:
	// 0x1FB855: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FB85A: sar eax, 0x10
	{ auto _cnt = 0x10u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB85D: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB864: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB865: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB868: jmp 0x001FB931
	goto loc_1FB931;
loc_1FB86D:
	// 0x1FB86D: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB872: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB877: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB87A: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB87C: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB87E: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB881: jz 0x001FB89B
	if (ctx.flags.zf) goto loc_1FB89B;
	// 0x1FB883: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB885: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB88A: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB88F: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB892: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB894: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB896: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB899: jmp 0x001FB8A0
	goto loc_1FB8A0;
loc_1FB89B:
	// 0x1FB89B: mov eax, 0x01
	ctx.eax = 1;
loc_1FB8A0:
	// 0x1FB8A0: test ah, 0xFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & -1, 8);
	// 0x1FB8A3: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB8A5: jz 0x001FB8F6
	if (ctx.flags.zf) goto loc_1FB8F6;
	// 0x1FB8A7: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB8AC: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB8B1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB8B4: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB8B6: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB8B8: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB8BB: jz 0x001FB8E2
	if (ctx.flags.zf) goto loc_1FB8E2;
	// 0x1FB8BD: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB8BF: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB8C4: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB8C9: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB8CC: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB8CE: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB8D0: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB8D3: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB8D6: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB8DD: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB8E0: jmp 0x001FB931
	goto loc_1FB931;
loc_1FB8E2:
	// 0x1FB8E2: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FB8E7: sar eax, 0x08
	{ auto _cnt = 0x8u & 0x1F; if (_cnt) {
	  ctx.flags.cf = ((int32_t)ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)((int32_t)ctx.eax >> _cnt);
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB8EA: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB8F1: add eax, 0x07
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(7);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)7, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FB8F4: jmp 0x001FB931
	goto loc_1FB931;
loc_1FB8F6:
	// 0x1FB8F6: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB8FB: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB900: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB903: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB905: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB907: test dx, dx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.edx) & X86_REG16(ctx.edx), 16);
	// 0x1FB90A: jz 0x001FB924
	if (ctx.flags.zf) goto loc_1FB924;
	// 0x1FB90C: push 0x28
	{ auto _pv = (uint32_t)(40); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB90E: call 0x001FFF00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFindLSB(ctx, base);
	ctx.esp += 4;
	// 0x1FB913: mov edx, 0x01
	ctx.edx = 1;
	// 0x1FB918: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB91B: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FB91D: shl edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (32 - _cnt)) & 1;
	  ctx.edx = ctx.edx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x1FB91F: movzx eax, dx
	ctx.eax = (uint32_t)(X86_REG16(ctx.edx));
	// 0x1FB922: jmp 0x001FB929
	goto loc_1FB929;
loc_1FB924:
	// 0x1FB924: mov eax, 0x01
	ctx.eax = 1;
loc_1FB929:
	// 0x1FB929: movsx eax, byte ptr [eax+0x3C0848]
	ctx.eax = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.eax + 0x3C0848u)));
	// 0x1FB930: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
loc_1FB931:
	// 0x1FB931: mov ecx, [esi+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1FB934: shl eax, 0x1C
	{ auto _cnt = 0x1Cu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FB937: or ecx, eax
	ctx.ecx = ctx.ecx | ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FB939: mov [esi+0x40], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.ecx);
	// 0x1FB93C: mov dword ptr [esi+0x28], 0x1FB000
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 2076672);
	// 0x1FB943: mov dword ptr [esi+0x34], 0x1FB070
	X86_MEM_WRITE_u32(base, ctx.esi + 0x34u, 2076784);
	// 0x1FB94A: mov dword ptr [esi+0x2C], 0x1FB0A0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, 2076832);
	// 0x1FB951: mov dword ptr [esi+0x3C], 0x1FB0F0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, 2076912);
	// 0x1FB958: mov word ptr [esi+0x44], 0x04
	X86_MEM_WRITE_u16(base, ctx.esi + 0x44u, 4);
	// 0x1FB95E: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB95F: ret
	return;
}

void RwaVirtualVoiceRegisterUsingInterface(X86Context& ctx, uint8_t* base) {
	// 0x1FB960: mov eax, [0x00764134]
	ctx.eax = X86_MEM_READ_u32(base, 0x764134u);
	// 0x1FB965: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB966: push 0x30811
	{ auto _pv = (uint32_t)(198673); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB96B: push 0x41B814
	{ auto _pv = (uint32_t)(4306964); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB970: push 0x41B7A0
	{ auto _pv = (uint32_t)(4306848); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB975: push 0x41B7B8
	{ auto _pv = (uint32_t)(4306872); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB97A: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB97C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB97D: call 0x001F8E20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FB982: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FB984: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB987: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FB989: jz 0x001FB9BD
	if (ctx.flags.zf) goto loc_1FB9BD;
	// 0x1FB98B: call 0x001FB720
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVirtualVoiceRegisterCommon(ctx, base);
	ctx.esp += 4;
	// 0x1FB990: push 0x12
	{ auto _pv = (uint32_t)(18); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB992: push 0x3C1750
	{ auto _pv = (uint32_t)(3938128); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB997: push 0x11
	{ auto _pv = (uint32_t)(17); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB999: push 0x3C15B8
	{ auto _pv = (uint32_t)(3937720); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB99E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB99F: call 0x001F8B70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8B70(ctx, base);
	ctx.esp += 4;
	// 0x1FB9A4: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB9A7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB9A9: jz 0x001FB9B4
	if (ctx.flags.zf) goto loc_1FB9B4;
	// 0x1FB9AB: call 0x00207DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_207DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FB9B0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FB9B2: jnz 0x001FB9C1
	if (!ctx.flags.zf) goto loc_1FB9C1;
loc_1FB9B4:
	// 0x1FB9B4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9B5: call 0x001F8970
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDefDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1FB9BA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FB9BD:
	// 0x1FB9BD: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FB9BF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB9C0: ret
	return;
loc_1FB9C1:
	// 0x1FB9C1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9C2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9C3: call 0x001F8520
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F8520(ctx, base);
	ctx.esp += 4;
	// 0x1FB9C8: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FB9CB: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FB9CD: mov dword ptr [0x0041B81C], 0x01
	X86_MEM_WRITE_u32(base, 0x41B81Cu, 1);
	// 0x1FB9D7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FB9D8: ret
	return;
}

void _rwaObjHandleOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1FB9E0: push 0x4080C
	{ auto _pv = (uint32_t)(264204); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9E5: push 0x41B828
	{ auto _pv = (uint32_t)(4306984); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9EA: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9EC: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9EE: mov eax, 0x41B820
	ctx.eax = 4306976;
	// 0x1FB9F3: push 0x40
	{ auto _pv = (uint32_t)(64); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9F5: push 0x18
	{ auto _pv = (uint32_t)(24); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FB9F7: mov [0x0041B820], eax
	X86_MEM_WRITE_u32(base, 0x41B820u, ctx.eax);
	// 0x1FB9FC: mov [0x0041B824], eax
	X86_MEM_WRITE_u32(base, 0x41B824u, ctx.eax);
	// 0x1FBA01: call 0x001FEBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FBA06: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBA09: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBA0B: jnz 0x001FBA0E
	if (!ctx.flags.zf) goto loc_1FBA0E;
	// 0x1FBA0D: ret
	return;
loc_1FBA0E:
	// 0x1FBA0E: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FBA13: mov [0x0041B84C], eax
	X86_MEM_WRITE_u32(base, 0x41B84Cu, ctx.eax);
	// 0x1FBA18: ret
	return;
}

void RwaObjHandleRelease(X86Context& ctx, uint8_t* base) {
	// 0x1FBA20: sub esp, 0x10
	{ uint32_t _d = ctx.esp; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBA23: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBA24: mov ebx, [esp+0x1C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FBA28: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBA29: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBA2A: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBA2C: cmp ebx, edi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBA2E: mov [esp+0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.edi);
	// 0x1FBA32: mov [esp+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.edi);
	// 0x1FBA36: mov [esp+0x14], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edi);
	// 0x1FBA3A: mov [esp+0x18], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.edi);
	// 0x1FBA3E: jnz 0x001FBA44
	if (!ctx.flags.zf) goto loc_1FBA44;
	// 0x1FBA40: lea ebx, [esp+0x0C]
	ctx.ebx = ctx.esp + 0xCu;
loc_1FBA44:
	// 0x1FBA44: mov esi, [esp+0x20]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FBA48: mov eax, [esi+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x14u);
	// 0x1FBA4B: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBA4D: jbe 0x001FBA5A
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FBA5A;
	// 0x1FBA4F: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBA50: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBA51: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x1FBA54: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBA55: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBA56: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBA59: ret
	return;
loc_1FBA5A:
	// 0x1FBA5A: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FBA5D: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBA5F: jz 0x001FBA75
	if (ctx.flags.zf) goto loc_1FBA75;
	// 0x1FBA61: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBA62: call 0x001FD330
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceRemove(ctx, base);
	ctx.esp += 4;
	// 0x1FBA67: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBA6A: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBA6D: jnz 0x001FBA75
	if (!ctx.flags.zf) goto loc_1FBA75;
	// 0x1FBA6F: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FBA72: mov [ebx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0xCu, ctx.eax);
loc_1FBA75:
	// 0x1FBA75: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FBA77: mov edx, [ecx+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x20u);
	// 0x1FBA7A: cmp edx, edi
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBA7C: jz 0x001FBA8C
	if (ctx.flags.zf) goto loc_1FBA8C;
	// 0x1FBA7E: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FBA80: mov eax, [eax+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x40u);
	// 0x1FBA83: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBA88: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBA8A: jmp 0x001FBA8F
	goto loc_1FBA8F;
loc_1FBA8C:
	// 0x1FBA8C: lea eax, [ecx+0x28]
	ctx.eax = ctx.ecx + 0x28u;
loc_1FBA8F:
	// 0x1FBA8F: dec [eax]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x1FBA91: jnz 0x001FBAA9
	if (!ctx.flags.zf) goto loc_1FBAA9;
	// 0x1FBA93: test byte ptr [esi+0x10], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x10u) & 2, 8);
	// 0x1FBA97: jnz 0x001FBAA9
	if (!ctx.flags.zf) goto loc_1FBAA9;
	// 0x1FBA99: mov edx, [ebx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x1FBA9C: mov eax, [ebx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x1FBA9E: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBA9F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAA0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAA1: call 0x001F5F30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1FBAA6: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FBAA9:
	// 0x1FBAA9: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1FBAAC: mov edx, [esi+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x1FBAAF: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1FBAB1: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x1FBAB4: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x1FBAB7: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x1FBABA: test byte ptr [esi+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x10u) & 1, 8);
	// 0x1FBABE: jnz 0x001FBACE
	if (!ctx.flags.zf) goto loc_1FBACE;
	// 0x1FBAC0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAC1: push 0x41B828
	{ auto _pv = (uint32_t)(4306984); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAC6: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1FBACB: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FBACE:
	// 0x1FBACE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBACF: mov [ebx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x8u, ctx.esi);
	// 0x1FBAD2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBAD3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBAD4: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBAD7: ret
	return;
}

void RwaObjHandleSetParamData(X86Context& ctx, uint8_t* base) {
	// 0x1FBAE0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAE1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBAE5: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FBAE8: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FBAEB: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FBAEF: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FBAF1: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAF2: mov edi, [esp+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FBAF6: lea eax, [edx+eax*8]
	ctx.eax = ctx.edx + ctx.eax * 8;
	// 0x1FBAF9: movzx edx, word ptr [eax+0x04]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0x4u));
	// 0x1FBAFD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAFE: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBAFF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB00: call [eax]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FBB02: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBB05: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FBB07: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBB09: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBB0A: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBB0C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBB0D: ret
	return;
}

void sub_1FBB10(X86Context& ctx, uint8_t* base) {
	// 0x1FBB10: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBB14: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB15: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBB19: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FBB1C: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1FBB1F: lea eax, [ecx+edx*8]
	ctx.eax = ctx.ecx + ctx.edx * 8;
	// 0x1FBB22: movzx ecx, word ptr [eax+0x04]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0x4u));
	// 0x1FBB26: mov edx, [esp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FBB2A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB2B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB2C: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FBB2E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB2F: call [eax]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FBB31: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBB34: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FBB36: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBB38: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBB3A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBB3B: ret
	return;
}

void RwaObjHandleSetParamReal(X86Context& ctx, uint8_t* base) {
	// 0x1FBB40: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FBB44: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBB46: jnz 0x001FBB49
	if (!ctx.flags.zf) goto loc_1FBB49;
	// 0x1FBB48: ret
	return;
loc_1FBB49:
	// 0x1FBB49: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FBB4D: lea ecx, [esp+0x10]
	ctx.ecx = ctx.esp + 0x10u;
	// 0x1FBB51: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB52: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FBB56: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB57: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB58: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB59: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FBB5E: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBB61: ret
	return;
}

void RwaObjHandleSetParamPointer(X86Context& ctx, uint8_t* base) {
	// 0x1FBB70: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB71: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBB75: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FBB77: jnz 0x001FBB7D
	if (!ctx.flags.zf) goto loc_1FBB7D;
	// 0x1FBB79: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBB7B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBB7C: ret
	return;
loc_1FBB7D:
	// 0x1FBB7D: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FBB80: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FBB83: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FBB87: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FBB89: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB8A: mov edi, [esp+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FBB8E: lea eax, [edx+eax*8]
	ctx.eax = ctx.edx + ctx.eax * 8;
	// 0x1FBB91: movzx edx, word ptr [eax+0x04]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0x4u));
	// 0x1FBB95: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB96: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB97: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBB98: call [eax]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FBB9A: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBB9D: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FBB9F: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBBA1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBBA2: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBBA4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBBA5: ret
	return;
}

void sub_1FBBB0(X86Context& ctx, uint8_t* base) {
	// 0x1FBBB0: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FBBB4: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBBB8: lea eax, [esp+0x08]
	ctx.eax = ctx.esp + 0x8u;
	// 0x1FBBBC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBBBD: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBBC1: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBBC2: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBBC3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBBC4: call 0x001FBB10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBB10(ctx, base);
	ctx.esp += 4;
	// 0x1FBBC9: mov ecx, [esp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FBBCD: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBBD0: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FBBD2: jz 0x001FBBDD
	if (ctx.flags.zf) goto loc_1FBBDD;
	// 0x1FBBD4: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBBD6: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBBD8: setnz dl
	X86_REG8L(ctx.edx) = (!ctx.flags.zf) ? 1 : 0;
	// 0x1FBBDB: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_1FBBDD:
	// 0x1FBBDD: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBBE1: ret
	return;
}

void RwaObjHandleGetParamPointer(X86Context& ctx, uint8_t* base) {
	// 0x1FBBF0: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBBF4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBBF5: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBBF9: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FBBFC: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1FBBFF: lea eax, [ecx+edx*8]
	ctx.eax = ctx.ecx + ctx.edx * 8;
	// 0x1FBC02: movzx ecx, word ptr [eax+0x04]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.eax + 0x4u));
	// 0x1FBC06: lea edx, [esp+0x08]
	ctx.edx = ctx.esp + 0x8u;
	// 0x1FBC0A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC0B: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC0C: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FBC0E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC0F: call [eax]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FBC11: mov ecx, [esp+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FBC15: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBC18: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FBC1A: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBC1C: and eax, esi
	ctx.eax = ctx.eax & ctx.esi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBC1E: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FBC20: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBC21: jz 0x001FBC2C
	if (ctx.flags.zf) goto loc_1FBC2C;
	// 0x1FBC23: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBC25: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBC27: setnz dl
	X86_REG8L(ctx.edx) = (!ctx.flags.zf) ? 1 : 0;
	// 0x1FBC2A: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
loc_1FBC2C:
	// 0x1FBC2C: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FBC30: ret
	return;
}

void _rwaObjHandleCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1FBC40: mov eax, [0x0041B820]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B820u);
	// 0x1FBC45: cmp eax, 0x41B820
	{ uint32_t _d = ctx.eax; uint32_t _s = 4306976;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBC4A: jz 0x001FBC6A
	if (ctx.flags.zf) goto loc_1FBC6A;
	// 0x1FBC4C: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_1FBC50:
	// 0x1FBC50: add eax, 0xFFFFFFF8
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(-8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)-8, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBC53: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC55: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC56: call 0x001FBA20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleRelease(ctx, base);
	ctx.esp += 4;
	// 0x1FBC5B: mov eax, [0x0041B820]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B820u);
	// 0x1FBC60: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBC63: cmp eax, 0x41B820
	{ uint32_t _d = ctx.eax; uint32_t _s = 4306976;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBC68: jnz 0x001FBC50
	if (!ctx.flags.zf) goto loc_1FBC50;
loc_1FBC6A:
	// 0x1FBC6A: push 0x41B828
	{ auto _pv = (uint32_t)(4306984); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC6F: call 0x001FEB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListDestroy(ctx, base);
	ctx.esp += 4;
	// 0x1FBC74: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBC77: mov dword ptr [0x0041B84C], 0x00
	X86_MEM_WRITE_u32(base, 0x41B84Cu, 0);
	// 0x1FBC81: ret
	return;
}

void sub_1FBC90(X86Context& ctx, uint8_t* base) {
	// 0x1FBC90: sub esp, 0x18
	{ uint32_t _d = ctx.esp; uint32_t _s = 24;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBC93: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC94: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC95: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBC96: mov edi, [esp+0x30]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x30u);
	// 0x1FBC9A: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBC9C: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBC9E: jnz 0x001FBCC0
	if (!ctx.flags.zf) goto loc_1FBCC0;
	// 0x1FBCA0: mov [esp+0x1C], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.ebp);
	// 0x1FBCA4: mov [esp+0x18], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.ebp);
	// 0x1FBCA8: mov [esp+0x14], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.ebp);
	// 0x1FBCAC: mov [esp+0x10], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.ebp);
	// 0x1FBCB0: mov dword ptr [esp+0x0C], 0x02
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, 2);
	// 0x1FBCB8: mov [esp+0x20], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.ebp);
	// 0x1FBCBC: lea edi, [esp+0x0C]
	ctx.edi = ctx.esp + 0xCu;
loc_1FBCC0:
	// 0x1FBCC0: mov esi, [edi+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi + 0x14u);
	// 0x1FBCC3: cmp esi, ebp
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBCC5: jz 0x001FBCD0
	if (ctx.flags.zf) goto loc_1FBCD0;
	// 0x1FBCC7: mov dword ptr [esi+0x10], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, 1);
	// 0x1FBCCE: jmp 0x001FBCE7
	goto loc_1FBCE7;
loc_1FBCD0:
	// 0x1FBCD0: push 0x3080C
	{ auto _pv = (uint32_t)(198668); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBCD5: push 0x41B828
	{ auto _pv = (uint32_t)(4306984); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBCDA: call 0x001FE900
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListAlloc(ctx, base);
	ctx.esp += 4;
	// 0x1FBCDF: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FBCE1: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBCE4: mov [esi+0x10], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebp);
loc_1FBCE7:
	// 0x1FBCE7: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1FBCEA: mov ecx, [esp+0x28]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x28u);
	// 0x1FBCEE: or eax, 0x02
	ctx.eax = ctx.eax | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBCF1: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x1FBCF4: mov eax, [esp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x2Cu);
	// 0x1FBCF8: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBCFA: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x1FBCFC: mov [esi+0x04], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebp);
	// 0x1FBCFF: mov [esi+0x14], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.ebp);
	// 0x1FBD02: jnz 0x001FBD0F
	if (!ctx.flags.zf) goto loc_1FBD0F;
	// 0x1FBD04: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FBD06: mov edx, [eax+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4Cu);
	// 0x1FBD09: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1FBD0B: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBD0D: jz 0x001FBD47
	if (ctx.flags.zf) goto loc_1FBD47;
loc_1FBD0F:
	// 0x1FBD0F: mov edx, [edi+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x10u);
	// 0x1FBD12: mov ecx, [ecx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FBD14: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBD15: mov edx, [edi+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x1FBD18: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBD19: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBD1A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBD1B: call 0x001FD770
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD770(ctx, base);
	ctx.esp += 4;
	// 0x1FBD20: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBD23: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBD25: mov [esi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.eax);
	// 0x1FBD28: jnz 0x001FBD47
	if (!ctx.flags.zf) goto loc_1FBD47;
	// 0x1FBD2A: test byte ptr [esi+0x10], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x10u) & 1, 8);
	// 0x1FBD2E: jnz 0x001FBD3E
	if (!ctx.flags.zf) goto loc_1FBD3E;
	// 0x1FBD30: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBD31: push 0x41B828
	{ auto _pv = (uint32_t)(4306984); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBD36: call 0x001FEA30
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaFreeListFree(ctx, base);
	ctx.esp += 4;
	// 0x1FBD3B: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FBD3E:
	// 0x1FBD3E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBD3F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBD40: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBD42: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBD43: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBD46: ret
	return;
loc_1FBD47:
	// 0x1FBD47: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FBD49: mov ecx, [eax+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	// 0x1FBD4C: cmp ecx, ebp
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBD4E: jz 0x001FBD5E
	if (ctx.flags.zf) goto loc_1FBD5E;
	// 0x1FBD50: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1FBD52: mov eax, [edx+0x40]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x40u);
	// 0x1FBD55: and eax, 0xFFFFFFF
	ctx.eax = ctx.eax & 268435455;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FBD5A: add eax, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.ecx, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FBD5C: jmp 0x001FBD61
	goto loc_1FBD61;
loc_1FBD5E:
	// 0x1FBD5E: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
loc_1FBD61:
	// 0x1FBD61: inc [eax]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.eax, (uint32_t)_res); }
	// 0x1FBD63: lea eax, [esi+0x08]
	ctx.eax = ctx.esi + 0x8u;
	// 0x1FBD66: mov [esi+0x0C], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ebp);
	// 0x1FBD69: mov [eax], ebp
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ebp);
	// 0x1FBD6B: mov ecx, [0x0041B820]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B820u);
	// 0x1FBD71: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1FBD73: mov dword ptr [esi+0x0C], 0x41B820
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, 4306976);
	// 0x1FBD7A: mov edx, [0x0041B820]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B820u);
	// 0x1FBD80: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1FBD83: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBD84: mov [0x0041B820], eax
	X86_MEM_WRITE_u32(base, 0x41B820u, ctx.eax);
	// 0x1FBD89: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FBD8B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBD8C: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBD8D: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBD90: ret
	return;
}

void _rwaVoiceManagerOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1FBDA0: mov eax, 0x41B858
	ctx.eax = 4307032;
	// 0x1FBDA5: mov [0x0041B858], eax
	X86_MEM_WRITE_u32(base, 0x41B858u, ctx.eax);
	// 0x1FBDAA: mov [0x0041B85C], eax
	X86_MEM_WRITE_u32(base, 0x41B85Cu, ctx.eax);
	// 0x1FBDAF: mov eax, 0x41B850
	ctx.eax = 4307024;
	// 0x1FBDB4: mov dword ptr [0x0041B864], 0x01
	X86_MEM_WRITE_u32(base, 0x41B864u, 1);
	// 0x1FBDBE: mov [0x0041B850], eax
	X86_MEM_WRITE_u32(base, 0x41B850u, ctx.eax);
	// 0x1FBDC3: mov [0x0041B854], eax
	X86_MEM_WRITE_u32(base, 0x41B854u, ctx.eax);
	// 0x1FBDC8: call 0x001FB960
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVirtualVoiceRegisterUsingInterface(ctx, base);
	ctx.esp += 4;
	// 0x1FBDCD: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FBDD2: ret
	return;
}

void _rwaVoiceManagerCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1FBDE0: call 0x001FAFD0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVirtualVoiceUnregister(ctx, base);
	ctx.esp += 4;
	// 0x1FBDE5: mov dword ptr [0x0041B864], 0x00
	X86_MEM_WRITE_u32(base, 0x41B864u, 0);
	// 0x1FBDEF: ret
	return;
}

void rwaVoiceManagerUpdateTimeStamp(X86Context& ctx, uint8_t* base) {
	// 0x1FBDF0: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBDF1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBDF2: call 0x001FC930
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaTimerGetValue(ctx, base);
	ctx.esp += 4;
	// 0x1FBDF7: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FBDF9: call 0x001FC950
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaTimerGetFrequency(ctx, base);
	ctx.esp += 4;
	// 0x1FBDFE: mov edx, [0x0041B884]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B884u);
	// 0x1FBE04: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x1FBE06: sub ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FBE08: cmp esi, edx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBE0A: jnb 0x001FBE0D
	if (!ctx.flags.cf) goto loc_1FBE0D;
	// 0x1FBE0C: dec ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
loc_1FBE0D:
	// 0x1FBE0D: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x1FBE0F: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FBE13: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FBE17: jnl 0x001FBE1F
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FBE1F;
	// 0x1FBE19: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1FBE1F:
	// 0x1FBE1F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBE21: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1FBE25: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FBE29: jnl 0x001FBE31
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FBE31;
	// 0x1FBE2B: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1FBE31:
	// 0x1FBE31: fdivp st1, st0
	ctx.fp_stack[1] = X86_FPU_ROUND(ctx, ctx.fp_stack[1] / ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1FBE33: fmul [0x003B16CC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16CCu));
	// 0x1FBE39: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FBE3E: mov ecx, [0x0041B880]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FBE44: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FBE46: mov [0x0041B884], esi
	X86_MEM_WRITE_u32(base, 0x41B884u, ctx.esi);
	// 0x1FBE4C: mov [0x0041B880], ecx
	X86_MEM_WRITE_u32(base, 0x41B880u, ctx.ecx);
	// 0x1FBE52: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBE53: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBE54: ret
	return;
}

void sub_1FBE60(X86Context& ctx, uint8_t* base) {
	// 0x1FBE60: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FBE64: mov eax, [ecx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FBE66: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FBE6A: add edx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.eax, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FBE6C: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1FBE6E: ret
	return;
}

void sub_1FBE70(X86Context& ctx, uint8_t* base) {
	// 0x1FBE70: sub esp, 0x20
	{ uint32_t _d = ctx.esp; uint32_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBE73: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBE74: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBE75: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBE76: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBE77: push 0x36DEBC
	{ auto _pv = (uint32_t)(3595964); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBE7C: call 0x001FD6C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD6C0(ctx, base);
	ctx.esp += 4;
	// 0x1FBE81: push 0x36DCAC
	{ auto _pv = (uint32_t)(3595436); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBE86: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FBE88: call 0x001FD6C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD6C0(ctx, base);
	ctx.esp += 4;
	// 0x1FBE8D: movzx edx, word ptr [esi+0x14]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x14u));
	// 0x1FBE91: movzx ecx, word ptr [esi+0x16]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x16u));
	// 0x1FBE95: mov edi, [esp+0x44]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x1FBE99: add ecx, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.edx, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FBE9B: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x1FBE9D: movzx ebp, word ptr [ebx+0x14]
	ctx.ebp = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebx + 0x14u));
	// 0x1FBEA1: movzx edx, word ptr [ebx+0x16]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebx + 0x16u));
	// 0x1FBEA5: add edx, ebp
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ebp);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ebp, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FBEA7: lea edx, [edx*8+0x28]
	ctx.edx = ctx.edx * 8 + 0x28u;
	// 0x1FBEAE: lea ebp, [edi+edi*2+0x03]
	ctx.ebp = ctx.edi + ctx.edi * 2 + 0x3u;
	// 0x1FBEB2: lea edx, [edx+ebp*8]
	ctx.edx = ctx.edx + ctx.ebp * 8;
	// 0x1FBEB5: lea ecx, [ecx*8+0x1C]
	ctx.ecx = ctx.ecx * 8 + 0x1Cu;
	// 0x1FBEBC: lea eax, [edi*4]
	ctx.eax = ctx.edi * 4;
	// 0x1FBEC3: add edx, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ecx, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FBEC5: add edx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.eax, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FBEC7: push 0x3080E
	{ auto _pv = (uint32_t)(198670); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBECC: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBECD: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1FBED2: mov ebp, eax
	ctx.ebp = ctx.eax;
	// 0x1FBED4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBED6: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBED9: cmp ebp, eax
	{ uint32_t _d = ctx.ebp; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBEDB: jz 0x001FC017
	if (ctx.flags.zf) goto loc_1FC017;
	// 0x1FBEE1: mov [esp+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.eax);
	// 0x1FBEE5: mov [esp+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.eax);
	// 0x1FBEE9: lea edx, [esp+0x18]
	ctx.edx = ctx.esp + 0x18u;
	// 0x1FBEED: lea eax, [esp+0x3C]
	ctx.eax = ctx.esp + 0x3Cu;
	// 0x1FBEF1: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBEF2: mov [esp+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x2Cu, ctx.eax);
	// 0x1FBEF6: mov eax, [esp+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
	// 0x1FBEFA: lea ecx, [ebp+0x18]
	ctx.ecx = ctx.ebp + 0x18u;
	// 0x1FBEFD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBEFE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBEFF: mov dword ptr [esp+0x24], 0x02
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, 2);
	// 0x1FBF07: mov dword ptr [esp+0x30], 0x1FBE60
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, 2080352);
	// 0x1FBF0F: mov [esp+0x38], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x38u, ctx.ebp);
	// 0x1FBF13: mov [esp+0x48], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x48u, ctx.ecx);
	// 0x1FBF17: call 0x001FBC90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBC90(ctx, base);
	ctx.esp += 4;
	// 0x1FBF1C: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBF1F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBF21: mov [0x0041B86C], eax
	X86_MEM_WRITE_u32(base, 0x41B86Cu, ctx.eax);
	// 0x1FBF26: jnz 0x001FBF3B
	if (!ctx.flags.zf) goto loc_1FBF3B;
	// 0x1FBF28: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF29: call 0x001FEDC0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaHeapFree(ctx, base);
	ctx.esp += 4;
	// 0x1FBF2E: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBF31: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBF32: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBF33: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBF34: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBF36: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBF37: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBF3A: ret
	return;
loc_1FBF3B:
	// 0x1FBF3B: mov ecx, [esp+0x3C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1FBF3F: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FBF41: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FBF43: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FBF45: mov [0x0041B860], edx
	X86_MEM_WRITE_u32(base, 0x41B860u, ctx.edx);
	// 0x1FBF4B: lea ecx, [ecx+edi*4]
	ctx.ecx = ctx.ecx + ctx.edi * 4;
	// 0x1FBF4E: jbe 0x001FBF8D
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FBF8D;
	// 0x1FBF50: mov ebp, [esp+0x38]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
loc_1FBF54:
	// 0x1FBF54: mov edx, [ebp+esi*4]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + ctx.esi * 4);
	// 0x1FBF58: mov [esp+0x2C], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x2Cu, ctx.ecx);
	// 0x1FBF5C: add ecx, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)24, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FBF5F: mov [esp+0x3C], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x3Cu, ctx.ecx);
	// 0x1FBF63: lea ecx, [esp+0x18]
	ctx.ecx = ctx.esp + 0x18u;
	// 0x1FBF67: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF68: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF69: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF6A: call 0x001FBC90
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBC90(ctx, base);
	ctx.esp += 4;
	// 0x1FBF6F: mov edx, [0x0041B860]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B860u);
	// 0x1FBF75: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBF78: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FBF7A: mov [edx+esi*4], eax
	X86_MEM_WRITE_u32(base, ctx.edx + ctx.esi * 4, ctx.eax);
	// 0x1FBF7D: jz 0x001FBFDA
	if (ctx.flags.zf) goto loc_1FBFDA;
	// 0x1FBF7F: mov ecx, [esp+0x3C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1FBF83: inc esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FBF84: cmp esi, edi
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FBF86: jb 0x001FBF54
	if (ctx.flags.cf) goto loc_1FBF54;
	// 0x1FBF88: mov eax, [0x0041B86C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B86Cu);
loc_1FBF8D:
	// 0x1FBF8D: mov [esp+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edx);
	// 0x1FBF91: lea edx, [esp+0x10]
	ctx.edx = ctx.esp + 0x10u;
	// 0x1FBF95: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF96: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF98: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF9A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBF9B: mov dword ptr [0x0041B868], 0x01
	X86_MEM_WRITE_u32(base, 0x41B868u, 1);
	// 0x1FBFA5: mov [0x0041B874], edi
	X86_MEM_WRITE_u32(base, 0x41B874u, ctx.edi);
	// 0x1FBFAB: mov [esp+0x20], edi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.edi);
	// 0x1FBFAF: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FBFB4: mov eax, [0x0041B86C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B86Cu);
	// 0x1FBFB9: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBFBB: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBFBD: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBFBF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBFC0: call 0x001FBBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleGetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FBFC5: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBFC8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBFC9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBFCA: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBFCB: mov [0x0041B870], eax
	X86_MEM_WRITE_u32(base, 0x41B870u, ctx.eax);
	// 0x1FBFD0: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FBFD5: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FBFD6: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBFD9: ret
	return;
loc_1FBFDA:
	// 0x1FBFDA: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FBFDC: jz 0x001FBFFA
	if (ctx.flags.zf) goto loc_1FBFFA;
	// 0x1FBFDE: jmp 0x001FBFE6
	goto loc_1FBFE6;
loc_1FBFE0:
	// 0x1FBFE0: mov edx, [0x0041B860]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B860u);
loc_1FBFE6:
	// 0x1FBFE6: mov eax, [edx+esi*4-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + ctx.esi * 4 - 0x4u);
	// 0x1FBFEA: dec esi
	{ uint32_t _d = ctx.esi;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FBFEB: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBFED: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FBFEE: call 0x001FBA20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleRelease(ctx, base);
	ctx.esp += 4;
	// 0x1FBFF3: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FBFF6: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FBFF8: jnz 0x001FBFE0
	if (!ctx.flags.zf) goto loc_1FBFE0;
loc_1FBFFA:
	// 0x1FBFFA: mov ecx, [0x0041B86C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B86Cu);
	// 0x1FC000: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC002: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC003: call 0x001FBA20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleRelease(ctx, base);
	ctx.esp += 4;
	// 0x1FC008: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC00B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FC00D: mov [0x0041B874], eax
	X86_MEM_WRITE_u32(base, 0x41B874u, ctx.eax);
	// 0x1FC012: mov [0x0041B86C], eax
	X86_MEM_WRITE_u32(base, 0x41B86Cu, ctx.eax);
loc_1FC017:
	// 0x1FC017: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC018: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC019: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC01A: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FC01C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC01D: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC020: ret
	return;
}

void RwaVoiceManagerRegisterVoice(X86Context& ctx, uint8_t* base) {
	// 0x1FC030: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC034: add eax, 0x28
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(40);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)40, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC037: mov dword ptr [eax+0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 0);
	// 0x1FC03E: mov dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, 0);
	// 0x1FC044: mov ecx, [0x0041B858]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B858u);
	// 0x1FC04A: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1FC04C: mov dword ptr [eax+0x04], 0x41B858
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, 4307032);
	// 0x1FC053: mov edx, [0x0041B858]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B858u);
	// 0x1FC059: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1FC05C: mov [0x0041B858], eax
	X86_MEM_WRITE_u32(base, 0x41B858u, ctx.eax);
	// 0x1FC061: and byte ptr [eax+0x62], 0xFE
	X86_MEM_WRITE_u8(base, ctx.eax + 0x62u, X86_MEM_READ_u8(base, ctx.eax + 0x62u) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x62u), 8);
	// 0x1FC065: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FC06A: ret
	return;
}

void RwaVoiceManagerStopVoice(X86Context& ctx, uint8_t* base) {
	// 0x1FC070: test byte ptr [esi+0x62], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x62u) & 1, 8);
	// 0x1FC074: jz 0x001FC129
	if (ctx.flags.zf) goto loc_1FC129;
	// 0x1FC07A: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FC07D: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC07F: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1FC081: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC083: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FC086: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC087: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1FC08A: mov edi, [esi+0x38]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1FC08D: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FC08F: jz 0x001FC0D5
	if (ctx.flags.zf) goto loc_1FC0D5;
	// 0x1FC091: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC093: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC095: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC097: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC098: call 0x001FBBB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBBB0(ctx, base);
	ctx.esp += 4;
	// 0x1FC09D: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC0A0: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC0A2: jz 0x001FC0B3
	if (ctx.flags.zf) goto loc_1FC0B3;
	// 0x1FC0A4: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0A6: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0A8: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0AA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0AB: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC0B0: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FC0B3:
	// 0x1FC0B3: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0B5: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0B7: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0B9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0BA: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC0BF: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0C1: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0C3: push 0x0E
	{ auto _pv = (uint32_t)(14); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0C5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC0C6: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC0CB: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC0CE: mov dword ptr [esi+0x38], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, 0);
loc_1FC0D5:
	// 0x1FC0D5: mov ecx, [0x0041B858]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B858u);
	// 0x1FC0DB: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x1FC0DD: mov ecx, [0x0041B87C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B87Cu);
	// 0x1FC0E3: mov dword ptr [esi+0x04], 0x41B858
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 4307032);
	// 0x1FC0EA: mov edx, [0x0041B858]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B858u);
	// 0x1FC0F0: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1FC0F3: mov edx, [0x0041B878]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B878u);
	// 0x1FC0F9: mov [0x0041B858], esi
	X86_MEM_WRITE_u32(base, 0x41B858u, ctx.esi);
	// 0x1FC0FF: movzx eax, byte ptr [esi+0x61]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x61u));
	// 0x1FC103: sub ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FC105: mov al, [esi+0x62]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x62u);
	// 0x1FC108: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FC109: mov [0x0041B87C], ecx
	X86_MEM_WRITE_u32(base, 0x41B87Cu, ctx.ecx);
	// 0x1FC10F: mov ecx, [esi+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1FC112: and al, 0xFC
	X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) & -4;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8);
	// 0x1FC114: mov [0x0041B878], edx
	X86_MEM_WRITE_u32(base, 0x41B878u, ctx.edx);
	// 0x1FC11A: mov [esi+0x44], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.ecx);
	// 0x1FC11D: mov [esi+0x62], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_REG8L(ctx.eax));
	// 0x1FC120: mov byte ptr [esi+0x60], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0x60u, 0);
	// 0x1FC124: mov byte ptr [esi+0x61], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0x61u, 0);
	// 0x1FC128: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FC129:
	// 0x1FC129: ret
	return;
}

void RwaVoiceManagerReInsertVoice(X86Context& ctx, uint8_t* base) {
	// 0x1FC130: mov al, [esi+0x5D]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x5Du);
	// 0x1FC133: sub esp, 0x48
	{ uint32_t _d = ctx.esp; uint32_t _s = 72;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC136: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x1FC138: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC139: mov byte ptr [esi+0x60], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0x60u, 0);
	// 0x1FC13D: mov ebx, 0x01
	ctx.ebx = 1;
	// 0x1FC142: jbe 0x001FC251
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_1FC251;
	// 0x1FC148: mov eax, [esi+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x3Cu);
	// 0x1FC14B: test byte ptr [eax+0x54], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.eax + 0x54u) & 2, 8);
	// 0x1FC14F: jz 0x001FC285
	if (ctx.flags.zf) goto loc_1FC285;
	// 0x1FC155: lea ecx, [esi+0x08]
	ctx.ecx = ctx.esi + 0x8u;
	// 0x1FC158: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FC15A: mov eax, [ecx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FC15D: mov ecx, [ecx+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x1FC160: mov [esp+0x20], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.edx);
	// 0x1FC164: mov [esp+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.eax);
	// 0x1FC168: lea edx, [esi+0x14]
	ctx.edx = ctx.esi + 0x14u;
	// 0x1FC16B: mov eax, [edx]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx);
	// 0x1FC16D: mov [esp+0x28], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x28u, ctx.ecx);
	// 0x1FC171: mov ecx, [edx+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x1FC174: mov edx, [edx+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x1FC177: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC178: mov [esp+0x30], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.eax);
	// 0x1FC17C: mov eax, [esi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1FC17F: mov [esp+0x38], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x38u, ctx.edx);
	// 0x1FC183: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC185: mov [esp+0x38], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x38u, ctx.ecx);
	// 0x1FC189: mov ecx, [esi+0x58]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
	// 0x1FC18C: lea edx, [esp+0x14]
	ctx.edx = ctx.esp + 0x14u;
	// 0x1FC190: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC191: mov edx, [0x0041B870]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B870u);
	// 0x1FC197: mov [esp+0x50], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x50u, ctx.eax);
	// 0x1FC19B: lea eax, [esp+0x2C]
	ctx.eax = ctx.esp + 0x2Cu;
	// 0x1FC19F: mov [esp+0x54], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x54u, ctx.ecx);
	// 0x1FC1A3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC1A4: lea ecx, [esi-0xFA0]
	ctx.ecx = ctx.esi - 0xFA0u;
	// 0x1FC1AA: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC1AB: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC1AC: call 0x001F79B0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F79B0(ctx, base);
	ctx.esp += 4;
	// 0x1FC1B1: mov ecx, [esp+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x38u);
	// 0x1FC1B5: mov edx, [esp+0x3C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x3Cu);
	// 0x1FC1B9: lea eax, [esi+0x20]
	ctx.eax = ctx.esi + 0x20u;
	// 0x1FC1BC: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x1FC1BE: mov ecx, [esp+0x40]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x40u);
	// 0x1FC1C2: mov [eax+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.edx);
	// 0x1FC1C5: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x1FC1C8: mov eax, [esp+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x44u);
	// 0x1FC1CC: mov ecx, [esp+0x48]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x48u);
	// 0x1FC1D0: lea edx, [esi+0x2C]
	ctx.edx = ctx.esi + 0x2Cu;
	// 0x1FC1D3: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x1FC1D5: mov eax, [esp+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4Cu);
	// 0x1FC1D9: mov [edx+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.ecx);
	// 0x1FC1DC: movzx ecx, byte ptr [esi+0x5D]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x5Du));
	// 0x1FC1E0: mov [esp+0x1C], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.ecx);
	// 0x1FC1E4: mov [edx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.eax);
	// 0x1FC1E7: add esp, 0x18
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(24);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)24, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC1EA: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FC1EE: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC1F4: fmul [esp+0x0C]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esp + 0xCu));
	// 0x1FC1F8: fcom [0x003B16E0]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, 0x3B16E0u));
	// 0x1FC1FE: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1FC200: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1FC203: jnz 0x001FC24F
	if (!ctx.flags.zf) goto loc_1FC24F;
loc_1FC205:
	// 0x1FC205: movzx edx, byte ptr [esi+0x5F]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x5Fu));
	// 0x1FC209: movzx eax, byte ptr [esi+0x5C]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x5Cu));
	// 0x1FC20D: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1FC211: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FC215: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1FC219: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC21F: fld [0x003B168C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x1FC225: fsub st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] - ctx.fp_stack[1]);
	// 0x1FC227: fxch st2
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[2]; ctx.fp_stack[2] = _tmp; }
	// 0x1FC229: fmul [0x003B16C4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16C4u));
	// 0x1FC22F: fmulp st2, st0
	ctx.fp_stack[2] = X86_FPU_ROUND(ctx, ctx.fp_stack[2] * ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1FC231: fild [esp+0x04]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x4u)));
	// 0x1FC235: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC23B: fmul st0, st1
	ctx.fp_stack[0] = X86_FPU_ROUND(ctx, ctx.fp_stack[0] * ctx.fp_stack[1]);
	// 0x1FC23D: fmul [0x003B16C4]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16C4u));
	// 0x1FC243: faddp st2, st0
	ctx.fp_stack[2] = X86_FPU_ROUND(ctx, ctx.fp_stack[2] + ctx.fp_stack[0]);
	X86_FPU_POP(ctx);
	// 0x1FC245: fxch st1
	{ double _tmp = ctx.fp_stack[ctx.fp_top]; ctx.fp_stack[ctx.fp_top] = ctx.fp_stack[1]; ctx.fp_stack[1] = _tmp; }
	// 0x1FC247: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FC24C: mov [esi+0x60], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x60u, X86_REG8L(ctx.eax));
loc_1FC24F:
	// 0x1FC24F: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
loc_1FC251:
	// 0x1FC251: test [esi+0x62], bl
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x62u) & X86_REG8L(ctx.ebx), 8);
	// 0x1FC254: jz 0x001FC31C
	if (ctx.flags.zf) goto loc_1FC31C;
	// 0x1FC25A: movzx edx, byte ptr [esi+0x60]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x60u));
	// 0x1FC25E: mov [esp+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.edx);
	// 0x1FC262: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x1FC264: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC265: fild [esp+0x08]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x8u)));
	// 0x1FC269: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC26F: nop
loc_1FC270:
	// 0x1FC270: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FC272: cmp edx, 0x41B850
	{ uint32_t _d = ctx.edx; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC278: mov edi, [ecx+0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FC27B: jnz 0x001FC290
	if (!ctx.flags.zf) goto loc_1FC290;
	// 0x1FC27D: fld [0x003B1688]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B1688u));
	// 0x1FC283: jmp 0x001FC2A2
	goto loc_1FC2A2;
loc_1FC285:
	// 0x1FC285: fld [0x003B168C]
	X86_FPU_PUSH(ctx, (double)X86_MEM_READ_F32(base, 0x3B168Cu));
	// 0x1FC28B: jmp 0x001FC205
	goto loc_1FC205;
loc_1FC290:
	// 0x1FC290: movzx eax, byte ptr [edx+0x60]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.edx + 0x60u));
	// 0x1FC294: mov [esp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.eax);
	// 0x1FC298: fild [esp+0x0C]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)));
	// 0x1FC29C: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
loc_1FC2A2:
	// 0x1FC2A2: cmp edi, 0x41B850
	{ uint32_t _d = ctx.edi; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC2A8: jnz 0x001FC2B4
	if (!ctx.flags.zf) goto loc_1FC2B4;
	// 0x1FC2AA: mov dword ptr [esp+0x08], 0xBF800000
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, -1082130432);
	// 0x1FC2B2: jmp 0x001FC2CA
	goto loc_1FC2CA;
loc_1FC2B4:
	// 0x1FC2B4: movzx eax, byte ptr [edi+0x60]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.edi + 0x60u));
	// 0x1FC2B8: mov [esp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.eax);
	// 0x1FC2BC: fild [esp+0x0C]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0xCu)));
	// 0x1FC2C0: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC2C6: fstp [esp+0x08]
	X86_MEM_WRITE_F32(base, ctx.esp + 0x8u, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
loc_1FC2CA:
	// 0x1FC2CA: fld st1
	X86_FPU_PUSH(ctx, ctx.fp_stack[1]);
	// 0x1FC2CC: fcomp st1
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], ctx.fp_stack[1]);
	X86_FPU_POP(ctx);
	// 0x1FC2CE: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1FC2D0: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1FC2D2: test ah, 0x41
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 65, 8);
	// 0x1FC2D5: jnz 0x001FC2DB
	if (!ctx.flags.zf) goto loc_1FC2DB;
	// 0x1FC2D7: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x1FC2D9: jmp 0x001FC270
	goto loc_1FC270;
loc_1FC2DB:
	// 0x1FC2DB: fcom [esp+0x08]
	X86_FPU_COMPARE(ctx, ctx.fp_stack[ctx.fp_top], (double)X86_MEM_READ_F32(base, ctx.esp + 0x8u));
	// 0x1FC2DF: fnstsw ax
	X86_REG16(ctx.eax) = X86_FPU_STATUS(ctx);
	// 0x1FC2E1: test ah, 0x05
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 5, 8);
	// 0x1FC2E4: jp 0x001FC2EA
	if (ctx.flags.pf) goto loc_1FC2EA;
	// 0x1FC2E6: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x1FC2E8: jmp 0x001FC270
	goto loc_1FC270;
loc_1FC2EA:
	// 0x1FC2EA: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC2EC: fstp st0
	ctx.fp_stack[0] = ctx.fp_stack[ctx.fp_top];
	X86_FPU_POP(ctx);
	// 0x1FC2EE: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC2EF: jz 0x001FC38B
	if (ctx.flags.zf) goto loc_1FC38B;
	// 0x1FC2F5: mov edx, [esi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FC2F8: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC2FA: mov [edx], eax
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.eax);
	// 0x1FC2FC: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC2FE: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FC301: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1FC304: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FC307: mov [esi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edx);
	// 0x1FC30A: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x1FC30C: mov eax, [ecx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FC30F: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x1FC311: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1FC314: or [esi+0x62], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_MEM_READ_u8(base, ctx.esi + 0x62u) | X86_REG8L(ctx.ebx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x62u), 8);
	// 0x1FC317: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC318: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC31B: ret
	return;
loc_1FC31C:
	// 0x1FC31C: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FC31F: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC321: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1FC323: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC325: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FC328: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x1FC32B: mov eax, [0x0041B850]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B850u);
	// 0x1FC330: cmp eax, 0x41B850
	{ uint32_t _d = ctx.eax; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC335: jz 0x001FC357
	if (ctx.flags.zf) goto loc_1FC357;
	// 0x1FC337: mov cl, [esi+0x60]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0x60u);
	// 0x1FC33A: lea ebx, [ebx]
	ctx.ebx = ctx.ebx;
loc_1FC340:
	// 0x1FC340: cmp cl, [eax+0x60]
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = X86_MEM_READ_u8(base, ctx.eax + 0x60u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x1FC343: jb 0x001FC350
	if (ctx.flags.cf) goto loc_1FC350;
	// 0x1FC345: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1FC347: cmp eax, 0x41B850
	{ uint32_t _d = ctx.eax; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC34C: jnz 0x001FC340
	if (!ctx.flags.zf) goto loc_1FC340;
	// 0x1FC34E: jmp 0x001FC357
	goto loc_1FC357;
loc_1FC350:
	// 0x1FC350: cmp eax, 0x41B850
	{ uint32_t _d = ctx.eax; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC355: jnz 0x001FC37B
	if (!ctx.flags.zf) goto loc_1FC37B;
loc_1FC357:
	// 0x1FC357: mov edx, [0x0041B854]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B854u);
	// 0x1FC35D: mov [esi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.edx);
	// 0x1FC360: mov dword ptr [esi], 0x41B850
	X86_MEM_WRITE_u32(base, ctx.esi, 4307024);
	// 0x1FC366: mov eax, [0x0041B854]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B854u);
	// 0x1FC36B: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x1FC36D: mov [0x0041B854], esi
	X86_MEM_WRITE_u32(base, 0x41B854u, ctx.esi);
	// 0x1FC373: or [esi+0x62], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_MEM_READ_u8(base, ctx.esi + 0x62u) | X86_REG8L(ctx.ebx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x62u), 8);
	// 0x1FC376: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC377: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC37A: ret
	return;
loc_1FC37B:
	// 0x1FC37B: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FC37E: mov [esi+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ecx);
	// 0x1FC381: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x1FC383: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FC386: mov [edx], esi
	X86_MEM_WRITE_u32(base, ctx.edx, ctx.esi);
	// 0x1FC388: mov [eax+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.esi);
loc_1FC38B:
	// 0x1FC38B: or [esi+0x62], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_MEM_READ_u8(base, ctx.esi + 0x62u) | X86_REG8L(ctx.ebx));
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0x62u), 8);
	// 0x1FC38E: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC38F: add esp, 0x48
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(72);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)72, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC392: ret
	return;
}

void rwaVoiceManagerUpdate(X86Context& ctx, uint8_t* base) {
	// 0x1FC3A0: mov eax, [0x0041B86C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B86Cu);
	// 0x1FC3A5: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC3A8: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC3A9: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FC3AB: cmp eax, ebp
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC3AD: jz 0x001FC638
	if (ctx.flags.zf) goto loc_1FC638;
	// 0x1FC3B3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC3B4: mov esi, [0x0041B850]
	ctx.esi = X86_MEM_READ_u32(base, 0x41B850u);
	// 0x1FC3BA: cmp esi, 0x41B850
	{ uint32_t _d = ctx.esi; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC3C0: mov [esp+0x08], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x8u, ctx.ebp);
	// 0x1FC3C4: jz 0x001FC637
	if (ctx.flags.zf) goto loc_1FC637;
	// 0x1FC3CA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC3CB: jmp 0x001FC3D0
	goto loc_1FC3D0;
	// 0x1FC3CD: lea ecx, [ecx]
	ctx.ecx = ctx.ecx;
loc_1FC3D0:
	// 0x1FC3D0: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC3D2: mov ecx, [0x0041B87C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B87Cu);
	// 0x1FC3D8: mov edx, [0x0041B874]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B874u);
	// 0x1FC3DE: mov edi, [esi+0x38]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1FC3E1: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1FC3E5: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FC3E9: sub ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FC3EB: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC3ED: jnl 0x001FC4ED
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FC4ED;
	// 0x1FC3F3: mov al, [esi+0x62]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x62u);
	// 0x1FC3F6: test al, 0x10
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 16, 8);
	// 0x1FC3F8: jz 0x001FC401
	if (ctx.flags.zf) goto loc_1FC401;
	// 0x1FC3FA: call 0x001FC070
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerStopVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FC3FF: jmp 0x001FC455
	goto loc_1FC455;
loc_1FC401:
	// 0x1FC401: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC403: jz 0x001FC455
	if (ctx.flags.zf) goto loc_1FC455;
	// 0x1FC405: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x1FC407: jz 0x001FC411
	if (ctx.flags.zf) goto loc_1FC411;
	// 0x1FC409: mov edx, [esi+0x48]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x48u);
	// 0x1FC40C: mov [esi+0x44], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.edx);
	// 0x1FC40F: jmp 0x001FC422
	goto loc_1FC422;
loc_1FC411:
	// 0x1FC411: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC412: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC414: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC416: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC417: call 0x001FBBB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FBBB0(ctx, base);
	ctx.esp += 4;
	// 0x1FC41C: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC41F: mov [esi+0x44], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.eax);
loc_1FC422:
	// 0x1FC422: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC423: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC425: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC427: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC428: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC42D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC42E: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC430: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC432: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC433: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC438: mov eax, [esi+0x38]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	// 0x1FC43B: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC43C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC43E: push 0x0E
	{ auto _pv = (uint32_t)(14); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC440: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC441: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC446: mov ecx, [0x0041B880]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FC44C: add esp, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)48, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC44F: mov [esi+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ecx);
	// 0x1FC452: mov [esi+0x38], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.ebp);
loc_1FC455:
	// 0x1FC455: mov al, [esi+0x62]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x62u);
	// 0x1FC458: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x1FC45A: jz 0x001FC618
	if (ctx.flags.zf) goto loc_1FC618;
	// 0x1FC460: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x1FC462: jnz 0x001FC618
	if (!ctx.flags.zf) goto loc_1FC618;
	// 0x1FC468: mov eax, [esi+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x3Cu);
	// 0x1FC46B: mov edx, [eax+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x1FC46E: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC46F: add eax, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)16, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC472: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC473: call 0x001FA7D0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaWaveFormatGetSamples(ctx, base);
	ctx.esp += 4;
	// 0x1FC478: mov edx, [esi+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x4Cu);
	// 0x1FC47B: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FC47D: mov eax, [0x0041B880]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FC482: sub eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC484: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC487: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC489: mov [esp+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.eax);
	// 0x1FC48D: fild [esp+0x10]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x10u)));
	// 0x1FC491: jnl 0x001FC499
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FC499;
	// 0x1FC493: fadd [0x003B16A8]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] + (double)X86_MEM_READ_F32(base, 0x3B16A8u));
loc_1FC499:
	// 0x1FC499: fmul [esi+0x50]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, ctx.esi + 0x50u));
	// 0x1FC49C: fmul [0x003B16D0]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16D0u));
	// 0x1FC4A2: call 0x00244DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244DF0(ctx, base);
	ctx.esp += 4;
	// 0x1FC4A7: mov ecx, [esi+0x44]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x44u);
	// 0x1FC4AA: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FC4AC: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1FC4AE: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC4B0: mov [esi+0x44], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.ecx);
	// 0x1FC4B3: jb 0x001FC4DF
	if (ctx.flags.cf) goto loc_1FC4DF;
	// 0x1FC4B5: test byte ptr [esi+0x62], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x62u) & 4, 8);
	// 0x1FC4B9: jz 0x001FC4D7
	if (ctx.flags.zf) goto loc_1FC4D7;
	// 0x1FC4BB: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x1FC4BD: lea ecx, [ecx]
	ctx.ecx = ctx.ecx;
loc_1FC4C0:
	// 0x1FC4C0: sub eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC4C2: cmp eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC4C4: jnb 0x001FC4C0
	if (!ctx.flags.cf) goto loc_1FC4C0;
	// 0x1FC4C6: mov [esi+0x44], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.eax);
	// 0x1FC4C9: mov ecx, [0x0041B880]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FC4CF: mov [esi+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ecx);
	// 0x1FC4D2: jmp 0x001FC618
	goto loc_1FC618;
loc_1FC4D7:
	// 0x1FC4D7: call 0x001FC070
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerStopVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FC4DC: mov [esi+0x38], ebp
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.ebp);
loc_1FC4DF:
	// 0x1FC4DF: mov ecx, [0x0041B880]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B880u);
	// 0x1FC4E5: mov [esi+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ecx);
	// 0x1FC4E8: jmp 0x001FC618
	goto loc_1FC618;
loc_1FC4ED:
	// 0x1FC4ED: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC4EF: jnz 0x001FC618
	if (!ctx.flags.zf) goto loc_1FC618;
	// 0x1FC4F5: mov edx, [0x0041B86C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B86Cu);
	// 0x1FC4FB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC4FC: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC4FE: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC500: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC501: call 0x001FBBF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleGetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC506: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x1FC508: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC50B: cmp edi, ebp
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC50D: mov [esi+0x38], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.edi);
	// 0x1FC510: jz 0x001FC618
	if (ctx.flags.zf) goto loc_1FC618;
	// 0x1FC516: mov eax, [esi+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x3Cu);
	// 0x1FC519: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC51A: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC51C: push 0x0B
	{ auto _pv = (uint32_t)(11); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC51E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC51F: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC524: mov ecx, [esi+0x50]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x50u);
	// 0x1FC527: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC528: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC52A: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC52C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC52D: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC532: movzx edx, byte ptr [esi+0x5D]
	ctx.edx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x5Du));
	// 0x1FC536: mov [esp+0x30], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.edx);
	// 0x1FC53A: add esp, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)28, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC53D: fild [esp+0x14]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)));
	// 0x1FC541: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC547: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FC54A: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC54C: push 0x07
	{ auto _pv = (uint32_t)(7); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC54E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC54F: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC554: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FC556: mov al, [esi+0x62]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x62u);
	// 0x1FC559: shr eax, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FC55C: and eax, 0x01
	ctx.eax = ctx.eax & 1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x1FC55F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC560: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC562: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC564: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC565: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC56A: mov al, [esi+0x62]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x62u);
	// 0x1FC56D: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC570: test al, 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 8, 8);
	// 0x1FC572: jnz 0x001FC585
	if (!ctx.flags.zf) goto loc_1FC585;
	// 0x1FC574: mov ecx, [esi+0x44]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x44u);
	// 0x1FC577: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC578: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC57A: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC57C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC57D: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC582: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FC585:
	// 0x1FC585: movsx edx, byte ptr [esi+0x63]
	ctx.edx = (uint32_t)((int8_t)(X86_MEM_READ_u8(base, ctx.esi + 0x63u)));
	// 0x1FC589: mov [esp+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.edx);
	// 0x1FC58D: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC58E: fild [esp+0x14]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)));
	// 0x1FC592: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FC595: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC597: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC599: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC59A: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC59F: lea eax, [esi+0x08]
	ctx.eax = ctx.esi + 0x8u;
	// 0x1FC5A2: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5A3: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5A5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5A6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5A7: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FC5AC: lea ecx, [esi+0x14]
	ctx.ecx = ctx.esi + 0x14u;
	// 0x1FC5AF: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5B0: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5B2: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5B4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5B5: call 0x001FBAE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamData(ctx, base);
	ctx.esp += 4;
	// 0x1FC5BA: mov edx, [esi+0x54]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x54u);
	// 0x1FC5BD: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5BE: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5C0: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5C2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5C3: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC5C8: mov eax, [esi+0x58]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x58u);
	// 0x1FC5CB: add esp, 0x40
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(64);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)64, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC5CE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5CF: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5D1: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5D3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5D4: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC5D9: movzx ecx, byte ptr [esi+0x5E]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x5Eu));
	// 0x1FC5DD: mov [esp+0x20], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.ecx);
	// 0x1FC5E1: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC5E4: fild [esp+0x14]
	X86_FPU_PUSH(ctx, (double)(int32_t)(X86_MEM_READ_u32(base, ctx.esp + 0x14u)));
	// 0x1FC5E8: fmul [0x003B16AC]
	ctx.fp_stack[ctx.fp_top] = X86_FPU_ROUND(ctx, ctx.fp_stack[ctx.fp_top] * (double)X86_MEM_READ_F32(base, 0x3B16ACu));
	// 0x1FC5EE: fstp [esp]
	X86_MEM_WRITE_F32(base, ctx.esp, ctx.fp_stack[ctx.fp_top]);
	X86_FPU_POP(ctx);
	// 0x1FC5F1: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5F3: push 0x0D
	{ auto _pv = (uint32_t)(13); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5F5: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5F6: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC5FB: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5FD: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC5FF: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC601: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC602: call 0x001FBB40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamReal(ctx, base);
	ctx.esp += 4;
	// 0x1FC607: mov edx, [esi+0x40]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x40u);
	// 0x1FC60A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC60B: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC60D: push 0x0E
	{ auto _pv = (uint32_t)(14); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC60F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC610: call 0x001FBB70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjHandleSetParamPointer(ctx, base);
	ctx.esp += 4;
	// 0x1FC615: add esp, 0x30
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(48);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)48, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FC618:
	// 0x1FC618: movzx eax, byte ptr [esi+0x61]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi + 0x61u));
	// 0x1FC61C: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FC620: mov esi, [esp+0x14]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FC624: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FC626: cmp esi, 0x41B850
	{ uint32_t _d = ctx.esi; uint32_t _s = 4307024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FC62C: mov [esp+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0xCu, ctx.ecx);
	// 0x1FC630: jnz 0x001FC3D0
	if (!ctx.flags.zf) goto loc_1FC3D0;
	// 0x1FC636: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FC637:
	// 0x1FC637: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FC638:
	// 0x1FC638: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC639: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC63C: ret
	return;
}

void RwaVoiceManagerUpdateVoice(X86Context& ctx, uint8_t* base) {
	// 0x1FC690: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC694: sub eax, 0x00
	{ uint32_t _d = ctx.eax; uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC697: jz 0x001FC6BC
	if (ctx.flags.zf) goto loc_1FC6BC;
	// 0x1FC699: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC69A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC69B: jz 0x001FC6B1
	if (ctx.flags.zf) goto loc_1FC6B1;
	// 0x1FC69D: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC69E: jnz 0x001FC6AF
	if (!ctx.flags.zf) goto loc_1FC6AF;
	// 0x1FC6A0: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC6A4: test byte ptr [esi+0x62], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x62u) & 1, 8);
	// 0x1FC6A8: jz 0x001FC6AF
	if (ctx.flags.zf) goto loc_1FC6AF;
	// 0x1FC6AA: call 0x001FC130
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerReInsertVoice(ctx, base);
	ctx.esp += 4;
loc_1FC6AF:
	// 0x1FC6AF: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC6B0: ret
	return;
loc_1FC6B1:
	// 0x1FC6B1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC6B5: call 0x001FC070
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerStopVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FC6BA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC6BB: ret
	return;
loc_1FC6BC:
	// 0x1FC6BC: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC6C0: jmp 0x001FC640
	goto loc_1FC640;
	// ---- chunk at 0x1FC640 (size 0x41) ----
loc_1FC640:
	// 0x1FC640: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC641: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FC643: test byte ptr [esi+0x62], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0x62u) & 1, 8);
	// 0x1FC647: jz 0x001FC64E
	if (ctx.flags.zf) goto loc_1FC64E;
	// 0x1FC649: call 0x001FC070
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerStopVoice(ctx, base);
	ctx.esp += 4;
loc_1FC64E:
	// 0x1FC64E: call 0x001FC130
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaVoiceManagerReInsertVoice(ctx, base);
	ctx.esp += 4;
	// 0x1FC653: mov dl, [esi+0x62]
	X86_REG8L(ctx.edx) = X86_MEM_READ_u8(base, ctx.esi + 0x62u);
	// 0x1FC656: mov ecx, [0x0041B87C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B87Cu);
	// 0x1FC65C: mov eax, [0x0041B878]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B878u);
	// 0x1FC661: or dl, 0x02
	X86_REG8L(ctx.edx) = X86_REG8L(ctx.edx) | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.edx), 8);
	// 0x1FC664: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FC665: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC666: mov byte ptr [esi+0x61], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0x61u, 1);
	// 0x1FC66A: mov [esi+0x62], dl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x62u, X86_REG8L(ctx.edx));
	// 0x1FC66D: mov dword ptr [esi+0x48], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, 0);
	// 0x1FC674: mov [0x0041B87C], ecx
	X86_MEM_WRITE_u32(base, 0x41B87Cu, ctx.ecx);
	// 0x1FC67A: mov [0x0041B878], eax
	X86_MEM_WRITE_u32(base, 0x41B878u, ctx.eax);
	// 0x1FC67F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC680: ret
	return;
}

void sub_1FC6D0(X86Context& ctx, uint8_t* base) {
	// 0x1FC6D0: push 0x41B888
	{ auto _pv = (uint32_t)(4307080); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC6D5: call 0x001F9F40
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9F40(ctx, base);
	ctx.esp += 4;
	// 0x1FC6DA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC6DD: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FC6DF: sbb eax, eax
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s - (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FC6E1: neg eax
	{ uint32_t _d = ctx.eax;
	  uint32_t _res = 0 - _d;
	  X86_UPDATE_FLAGS_SUB(ctx, (uint64_t)_res, (int32_t)0, (int32_t)_d, 32);
	  ctx.flags.cf = (_d != 0);
	  ctx.eax = _res; }
	// 0x1FC6E3: ret
	return;
}

void sub_1FC6F0(X86Context& ctx, uint8_t* base) {
	// 0x1FC6F0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC6F1: mov ebx, [esp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC6F5: mov eax, [ebx+0x34]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x34u);
	// 0x1FC6F8: push 0x30807
	{ auto _pv = (uint32_t)(198663); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC6FD: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC6FE: mov dword ptr [ebx+0x50], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x50u, 0);
	// 0x1FC705: call 0x001FED80
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	rwaMalloc(ctx, base);
	ctx.esp += 4;
	// 0x1FC70A: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC70D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC70F: mov [ebx+0x4C], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4Cu, ctx.eax);
	// 0x1FC712: jnz 0x001FC716
	if (!ctx.flags.zf) goto loc_1FC716;
	// 0x1FC714: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC715: ret
	return;
loc_1FC716:
	// 0x1FC716: mov eax, [ebx+0x30]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x30u);
	// 0x1FC719: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC71B: jnz 0x001FC72E
	if (!ctx.flags.zf) goto loc_1FC72E;
	// 0x1FC71D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC71E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC71F: lea esi, [ebx+0x10]
	ctx.esi = ctx.ebx + 0x10u;
	// 0x1FC722: lea edi, [ebx+0x2C]
	ctx.edi = ctx.ebx + 0x2Cu;
	// 0x1FC725: mov ecx, 0x07
	ctx.ecx = 7;
	// 0x1FC72A: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FC72C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC72D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FC72E:
	// 0x1FC72E: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FC730: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC731: ret
	return;
}

void sub_1FC740(X86Context& ctx, uint8_t* base) {
	// 0x1FC740: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC744: mov eax, [eax+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4Cu);
	// 0x1FC747: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC749: jz 0x001FC754
	if (ctx.flags.zf) goto loc_1FC754;
	// 0x1FC74B: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1FC74F: jmp 0x001FEDC0
	RwaHeapFree(ctx, base);
	return;
loc_1FC754:
	// 0x1FC754: ret
	return;
}

void sub_1FC760(X86Context& ctx, uint8_t* base) {
	// 0x1FC760: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC764: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC768: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FC76C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC76D: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FC771: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC772: mov edi, [eax+0x4C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x4Cu);
	// 0x1FC775: add edi, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)ctx.edx, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1FC777: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FC779: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FC77C: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FC77E: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x1FC780: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FC783: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x1FC785: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC786: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC787: ret
	return;
}

void sub_1FC790(X86Context& ctx, uint8_t* base) {
	// 0x1FC790: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC794: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x1FC797: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC79B: mov edx, [esp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FC79F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7A0: mov esi, [eax+0x4C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x4Cu);
	// 0x1FC7A3: add esi, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.edx, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FC7A5: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FC7A7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7A8: mov edi, [esp+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FC7AC: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FC7AF: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FC7B1: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x1FC7B3: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FC7B6: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x1FC7B8: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC7B9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC7BA: ret
	return;
}

void sub_1FC7C0(X86Context& ctx, uint8_t* base) {
	// 0x1FC7C0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7C1: push 0x41B888
	{ auto _pv = (uint32_t)(4307080); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7C6: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7C8: call 0x001FA470
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FA470(ctx, base);
	ctx.esp += 4;
	// 0x1FC7CD: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x1FC7CF: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC7D2: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x1FC7D4: jnz 0x001FC7D8
	if (!ctx.flags.zf) goto loc_1FC7D8;
	// 0x1FC7D6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC7D7: ret
	return;
loc_1FC7D8:
	// 0x1FC7D8: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7DA: push 0x36DC9C
	{ auto _pv = (uint32_t)(3595420); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7DF: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC7E0: call 0x001F9F10
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1F9F10(ctx, base);
	ctx.esp += 4;
	// 0x1FC7E5: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC7E8: mov dword ptr [esi+0x0C], 0x1FC6F0
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, 2082544);
	// 0x1FC7EF: mov dword ptr [esi+0x10], 0x1FC740
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, 2082624);
	// 0x1FC7F6: mov dword ptr [esi+0x14], 0x1FC760
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, 2082656);
	// 0x1FC7FD: mov dword ptr [esi+0x18], 0x1FC790
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, 2082704);
	// 0x1FC804: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x1FC806: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC807: ret
	return;
}

void RwaVoice3DInterfaceRegister(X86Context& ctx, uint8_t* base) {
	// 0x1FC810: push 0x41B8E4
	{ auto _pv = (uint32_t)(4307172); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC815: call 0x001FD5A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FC81A: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC81D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC81F: jnz 0x001FC822
	if (!ctx.flags.zf) goto loc_1FC822;
	// 0x1FC821: ret
	return;
loc_1FC822:
	// 0x1FC822: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC824: push 0x36DCAC
	{ auto _pv = (uint32_t)(3595436); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC829: push 0x41B8E4
	{ auto _pv = (uint32_t)(4307172); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC82E: call 0x001F64C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1FC833: push 0x10
	{ auto _pv = (uint32_t)(16); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC835: push 0x3C1A30
	{ auto _pv = (uint32_t)(3938864); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC83A: push 0x0F
	{ auto _pv = (uint32_t)(15); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC83C: push 0x3C1900
	{ auto _pv = (uint32_t)(3938560); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC841: push 0x41B8E4
	{ auto _pv = (uint32_t)(4307172); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC846: call 0x001FD480
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefSetup(ctx, base);
	ctx.esp += 4;
	// 0x1FC84B: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC84E: mov eax, 0x41B8E4
	ctx.eax = 4307172;
	// 0x1FC853: ret
	return;
}

void sub_1FC860(X86Context& ctx, uint8_t* base) {
	// 0x1FC860: push 0x41B8E4
	{ auto _pv = (uint32_t)(4307172); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC865: call 0x001FD620
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD620(ctx, base);
	ctx.esp += 4;
	// 0x1FC86A: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC86D: ret
	return;
}

void RwaVoiceInterfaceRegister(X86Context& ctx, uint8_t* base) {
	// 0x1FC870: push 0x41B90C
	{ auto _pv = (uint32_t)(4307212); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC875: call 0x001FD5A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FC87A: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC87D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC87F: jnz 0x001FC882
	if (!ctx.flags.zf) goto loc_1FC882;
	// 0x1FC881: ret
	return;
loc_1FC882:
	// 0x1FC882: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC884: push 0x36DD7C
	{ auto _pv = (uint32_t)(3595644); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC889: push 0x41B90C
	{ auto _pv = (uint32_t)(4307212); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC88E: call 0x001F64C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1FC893: push 0x0A
	{ auto _pv = (uint32_t)(10); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC895: push 0x3C1C28
	{ auto _pv = (uint32_t)(3939368); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC89A: push 0x09
	{ auto _pv = (uint32_t)(9); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC89C: push 0x3C1B70
	{ auto _pv = (uint32_t)(3939184); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8A1: push 0x41B90C
	{ auto _pv = (uint32_t)(4307212); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8A6: call 0x001FD480
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefSetup(ctx, base);
	ctx.esp += 4;
	// 0x1FC8AB: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC8AE: mov eax, 0x41B90C
	ctx.eax = 4307212;
	// 0x1FC8B3: ret
	return;
}

void sub_1FC8C0(X86Context& ctx, uint8_t* base) {
	// 0x1FC8C0: push 0x41B90C
	{ auto _pv = (uint32_t)(4307212); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8C5: call 0x001FD620
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD620(ctx, base);
	ctx.esp += 4;
	// 0x1FC8CA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC8CD: ret
	return;
}

void RwaOutputInterfaceRegister(X86Context& ctx, uint8_t* base) {
	// 0x1FC8D0: push 0x41B934
	{ auto _pv = (uint32_t)(4307252); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8D5: call 0x001FD5A0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FC8DA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC8DD: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FC8DF: jnz 0x001FC8E2
	if (!ctx.flags.zf) goto loc_1FC8E2;
	// 0x1FC8E1: ret
	return;
loc_1FC8E2:
	// 0x1FC8E2: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8E4: push 0x36DEBC
	{ auto _pv = (uint32_t)(3595964); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8E9: push 0x41B934
	{ auto _pv = (uint32_t)(4307252); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8EE: call 0x001F64C0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefAssignID(ctx, base);
	ctx.esp += 4;
	// 0x1FC8F3: push 0x05
	{ auto _pv = (uint32_t)(5); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8F5: push 0x3C1D68
	{ auto _pv = (uint32_t)(3939688); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8FA: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC8FC: push 0x3C1CF0
	{ auto _pv = (uint32_t)(3939568); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC901: push 0x41B934
	{ auto _pv = (uint32_t)(4307252); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC906: call 0x001FD480
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaObjInterfaceDefSetup(ctx, base);
	ctx.esp += 4;
	// 0x1FC90B: add esp, 0x20
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(32);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)32, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC90E: mov eax, 0x41B934
	ctx.eax = 4307252;
	// 0x1FC913: ret
	return;
}

void sub_1FC920(X86Context& ctx, uint8_t* base) {
	// 0x1FC920: push 0x41B934
	{ auto _pv = (uint32_t)(4307252); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC925: call 0x001FD620
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FD620(ctx, base);
	ctx.esp += 4;
	// 0x1FC92A: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC92D: ret
	return;
}

void RwaTimerGetValue(X86Context& ctx, uint8_t* base) {
	// 0x1FC930: sub esp, 0x08
	{ uint32_t _d = ctx.esp; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC933: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC934: rdtsc
	{ uint64_t _tsc = X86_RDTSC();
	  ctx.eax = (uint32_t)_tsc; ctx.edx = (uint32_t)(_tsc >> 32); }
	// 0x1FC936: lea ebx, [esp+0x04]
	ctx.ebx = ctx.esp + 0x4u;
	// 0x1FC93A: mov [ebx], eax
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.eax);
	// 0x1FC93C: mov [ebx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.edx);
	// 0x1FC93F: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC943: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC944: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC947: ret
	return;
}

void RwaTimerGetFrequency(X86Context& ctx, uint8_t* base) {
	// 0x1FC950: mov eax, 0x2BB5C755
	ctx.eax = 733333333;
	// 0x1FC955: ret
	return;
}

void sub_1FC960(X86Context& ctx, uint8_t* base) {
	// 0x1FC960: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC961: rdtsc
	{ uint64_t _tsc = X86_RDTSC();
	  ctx.eax = (uint32_t)_tsc; ctx.edx = (uint32_t)(_tsc >> 32); }
	// 0x1FC963: lea ebx, [0x0041B960]
	ctx.ebx = 0x41B960u;
	// 0x1FC969: mov [ebx], eax
	X86_MEM_WRITE_u32(base, ctx.ebx, ctx.eax);
	// 0x1FC96B: mov [ebx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x4u, ctx.edx);
	// 0x1FC96E: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FC973: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC974: ret
	return;
}

void sub_1FC9A0(X86Context& ctx, uint8_t* base) {
	// 0x1FC9A0: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FC9A4: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FC9A8: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC9A9: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FC9AD: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC9AE: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FC9B2: mov [esi+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.eax);
	// 0x1FC9B5: mov [esi+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ecx);
	// 0x1FC9B8: mov dword ptr [esi+0x44], 0x03
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, 3);
	// 0x1FC9BF: mov [esi+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.edi);
	// 0x1FC9C2: mov dword ptr [esi+0x5C], 0x04
	X86_MEM_WRITE_u32(base, ctx.esi + 0x5Cu, 4);
	// 0x1FC9C9: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FC9CE: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FC9D0: mov ecx, [edx+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x1FC9D3: shr edi, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (_cnt - 1)) & 1;
	  ctx.edi = (uint32_t)(ctx.edi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x1FC9D6: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC9D8: shl edi, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edi >> (32 - _cnt)) & 1;
	  ctx.edi = ctx.edi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32); } }
	// 0x1FC9DB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC9DC: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FC9DD: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FC9E0: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FC9E3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC9E4: mov [esi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x60u, ctx.eax);
	// 0x1FC9E7: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FC9E8: ret
	return;
}

void sub_1FC9F0(X86Context& ctx, uint8_t* base) {
	// 0x1FC9F0: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FC9F4: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x1FC9F7: ret
	return;
}

void _rwaRwStreamCacheCloseModule(X86Context& ctx, uint8_t* base) {
	// 0x1FCA00: mov eax, [0x0041C18C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41C18Cu);
	// 0x1FCA05: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA07: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA08: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCA0D: mov ecx, [0x0041C18C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41C18Cu);
	// 0x1FCA13: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA14: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x1FCA19: mov edx, [0x0041B96C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCA1F: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA21: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA22: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCA27: mov eax, [0x0041B968]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B968u);
	// 0x1FCA2C: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA2E: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA2F: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCA34: mov ecx, [0x0041B96C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCA3A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA3B: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x1FCA40: mov edx, [0x0041B968]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B968u);
	// 0x1FCA46: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA47: call 0x001D19FD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	CloseHandle(ctx, base);
	ctx.esp += 4;
	// 0x1FCA4C: ret
	return;
}

void sub_1FCA50(X86Context& ctx, uint8_t* base) {
	// 0x1FCA50: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA51: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA52: mov ebx, [esp+0x14]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FCA56: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA57: mov ebp, [esp+0x1C]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FCA5B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA5C: mov [esp+0x20], ebp
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.ebp);
	// 0x1FCA60: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x1FCA62: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x1FCA64: add ebp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebp, (int32_t)4, 32);
	  ctx.ebp = (uint32_t)_res; }
	// 0x1FCA67: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FCA68: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA69: mov edi, [esp+0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FCA6D: mov [esp+0x10], esi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, ctx.esi);
	// 0x1FCA71: jz 0x001FCA7B
	if (ctx.flags.zf) goto loc_1FCA7B;
	// 0x1FCA73: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FCA74: jz 0x001FCADE
	if (ctx.flags.zf) goto loc_1FCADE;
	// 0x1FCA76: sub eax, 0x03
	{ uint32_t _d = ctx.eax; uint32_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FCA79: jnz 0x001FCAE1
	if (!ctx.flags.zf) goto loc_1FCAE1;
loc_1FCA7B:
	// 0x1FCA7B: mov edx, [0x0041C18C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41C18Cu);
	// 0x1FCA81: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA83: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCA84: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCA89: lea esp, [esp]
	ctx.esp = ctx.esp;
loc_1FCA90:
	// 0x1FCA90: cmp dword ptr [ebp+0x08], 0x04
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCA94: jnz 0x001FCB20
	if (!ctx.flags.zf) goto loc_1FCB20;
	// 0x1FCA9A: cmp esi, 0x04
	{ uint32_t _d = ctx.esi; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCA9D: mov dword ptr [ebp+0x08], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 3);
	// 0x1FCAA4: jz 0x001FCBAF
	if (ctx.flags.zf) goto loc_1FCBAF;
	// 0x1FCAAA: cmp edi, [ebp+0x2C]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.ebp + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCAAD: jnz 0x001FCBAF
	if (!ctx.flags.zf) goto loc_1FCBAF;
	// 0x1FCAB3: cmp dword ptr [ebp+0x30], 0x41B97C
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x30u); uint32_t _s = 4307324;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCABA: jnz 0x001FCB08
	if (!ctx.flags.zf) goto loc_1FCB08;
	// 0x1FCABC: mov ecx, [esp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x1FCAC0: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x1FCAC2: mov [0x0041C188], eax
	X86_MEM_WRITE_u32(base, 0x41C188u, ctx.eax);
	// 0x1FCAC7: mov [0x0041C17C], ebp
	X86_MEM_WRITE_u32(base, 0x41C17Cu, ctx.ebp);
	// 0x1FCACD: mov [0x0041C180], ecx
	X86_MEM_WRITE_u32(base, 0x41C180u, ctx.ecx);
	// 0x1FCAD3: mov edx, [ebp+0x28]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x28u);
	// 0x1FCAD6: mov [0x0041C184], edx
	X86_MEM_WRITE_u32(base, 0x41C184u, ctx.edx);
	// 0x1FCADC: jmp 0x001FCB25
	goto loc_1FCB25;
loc_1FCADE:
	// 0x1FCADE: mov [ebp+0x24], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x24u, ctx.edi);
loc_1FCAE1:
	// 0x1FCAE1: cmp dword ptr [ebp+0x08], 0x05
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0x8u); uint32_t _s = 5;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCAE5: jnz 0x001FCAF0
	if (!ctx.flags.zf) goto loc_1FCAF0;
	// 0x1FCAE7: mov dword ptr [ebp+0x08], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 3);
	// 0x1FCAEE: jmp 0x001FCA7B
	goto loc_1FCA7B;
loc_1FCAF0:
	// 0x1FCAF0: mov eax, [ebp+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x3Cu);
	// 0x1FCAF3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCAF4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCAF5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCAF6: mov ecx, [esp+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1FCAFA: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCAFB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCAFC: call [ebp+0x38]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ebp + 0x38u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCAFF: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCB02: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCB03: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCB04: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCB05: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCB06: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCB07: ret
	return;
loc_1FCB08:
	// 0x1FCB08: mov edx, [ebp+0x18]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x1FCB0B: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x1FCB0E: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FCB11: add edx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.edi, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FCB13: add ecx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.edi, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FCB15: sub eax, edi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FCB17: mov [ebp+0x18], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x18u, ctx.edx);
	// 0x1FCB1A: mov [ebp+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.ecx);
	// 0x1FCB1D: mov [ebp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x14u, ctx.eax);
loc_1FCB20:
	// 0x1FCB20: mov eax, [0x0041C188]
	ctx.eax = X86_MEM_READ_u32(base, 0x41C188u);
loc_1FCB25:
	// 0x1FCB25: mov ebx, [ebp+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x1FCB28: mov ecx, [0x0041C17C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41C17Cu);
	// 0x1FCB2E: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x1FCB30: shr esi, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x1FCB33: shl esi, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x1FCB36: cmp ecx, ebp
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.ebp;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCB38: jnz 0x001FCB9A
	if (!ctx.flags.zf) goto loc_1FCB9A;
	// 0x1FCB3A: mov ecx, [0x0041C184]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41C184u);
	// 0x1FCB40: cmp ecx, esi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCB42: jnz 0x001FCB9A
	if (!ctx.flags.zf) goto loc_1FCB9A;
	// 0x1FCB44: mov edx, ebx
	ctx.edx = ctx.ebx;
	// 0x1FCB46: sub edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FCB48: mov ecx, [ebp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FCB4B: sub eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FCB4D: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCB4F: jb 0x001FCB53
	if (ctx.flags.cf) goto loc_1FCB53;
	// 0x1FCB51: mov eax, ecx
	ctx.eax = ctx.ecx;
loc_1FCB53:
	// 0x1FCB53: mov edi, [ebp+0x18]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x1FCB56: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x1FCB58: lea esi, [edx+0x41B97C]
	ctx.esi = ctx.edx + 0x41B97Cu;
	// 0x1FCB5E: mov edx, ecx
	ctx.edx = ctx.ecx;
	// 0x1FCB60: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x1FCB63: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x1FCB65: mov ecx, edx
	ctx.ecx = ctx.edx;
	// 0x1FCB67: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x1FCB6A: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x1FCB6C: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x1FCB6F: mov edi, [ebp+0x14]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FCB72: mov ecx, [ebp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x1FCB75: add esi, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esi) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esi, (int32_t)ctx.eax, 32);
	  ctx.esi = (uint32_t)_res; }
	// 0x1FCB77: mov [ebp+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.esi);
	// 0x1FCB7A: add ebx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)ctx.eax, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x1FCB7C: sub edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x1FCB7E: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x1FCB80: add ecx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.eax, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x1FCB82: shr esi, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x1FCB85: mov [ebp+0x14], edi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x14u, ctx.edi);
	// 0x1FCB88: mov edi, [esp+0x1C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FCB8C: mov [ebp+0x18], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x18u, ctx.ecx);
	// 0x1FCB8F: shl esi, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (32 - _cnt)) & 1;
	  ctx.esi = ctx.esi << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x1FCB92: mov dword ptr [esp+0x10], 0x02
	X86_MEM_WRITE_u32(base, ctx.esp + 0x10u, 2);
loc_1FCB9A:
	// 0x1FCB9A: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FCB9D: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCB9F: cmp eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCBA1: jnz 0x001FCC53
	if (!ctx.flags.zf) goto loc_1FCC53;
	// 0x1FCBA7: mov ebx, [esp+0x20]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp + 0x20u);
	// 0x1FCBAB: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
loc_1FCBAF:
	// 0x1FCBAF: mov eax, [ebp+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x3Cu);
	// 0x1FCBB2: mov ecx, [ebp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x1FCBB5: mov edx, [ebp+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x1FCBB8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBB9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBBA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBBB: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBBC: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBBD: mov dword ptr [ebp+0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 1);
	// 0x1FCBC4: call [ebp+0x38]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.ebp + 0x38u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCBC7: mov eax, [0x0041B96C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCBCC: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCBCF: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBD1: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCBD2: xor ebp, ebp
	ctx.ebp = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCBD4: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCBD9: mov eax, [0x0041B970]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B970u);
	// 0x1FCBDE: cmp eax, 0x41B970
	{ uint32_t _d = ctx.eax; uint32_t _s = 4307312;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCBE3: jz 0x001FCC20
	if (ctx.flags.zf) goto loc_1FCC20;
	// 0x1FCBE5: mov ebp, [0x0041C17C]
	ctx.ebp = X86_MEM_READ_u32(base, 0x41C17Cu);
	// 0x1FCBEB: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1FCBED: jz 0x001FCBF9
	if (ctx.flags.zf) goto loc_1FCBF9;
	// 0x1FCBEF: cmp dword ptr [ebp], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCBF3: jz 0x001FCBF9
	if (ctx.flags.zf) goto loc_1FCBF9;
	// 0x1FCBF5: mov eax, ebp
	ctx.eax = ctx.ebp;
	// 0x1FCBF7: jmp 0x001FCBFB
	goto loc_1FCBFB;
loc_1FCBF9:
	// 0x1FCBF9: mov ebp, eax
	ctx.ebp = ctx.eax;
loc_1FCBFB:
	// 0x1FCBFB: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1FCBFD: mov ecx, [eax+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FCC00: mov [ecx], edx
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.edx);
	// 0x1FCC02: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x1FCC04: mov edx, [eax+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x1FCC07: mov [ecx+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.edx);
	// 0x1FCC0A: mov dword ptr [eax], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax, 0);
	// 0x1FCC10: mov eax, [ebp+0x34]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x34u);
	// 0x1FCC13: mov dword ptr [ebp+0x08], 0x03
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 3);
	// 0x1FCC1A: mov [esp+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.eax);
	// 0x1FCC1E: jmp 0x001FCC30
	goto loc_1FCC30;
loc_1FCC20:
	// 0x1FCC20: mov ecx, [0x0041B968]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B968u);
	// 0x1FCC26: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCC28: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCC2A: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCC2B: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
loc_1FCC30:
	// 0x1FCC30: mov edx, [0x0041B96C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCC36: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCC38: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCC3A: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCC3B: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1FCC40: test ebp, ebp
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebp & ctx.ebp, 32);
	// 0x1FCC42: mov [0x0041B978], ebp
	X86_MEM_WRITE_u32(base, 0x41B978u, ctx.ebp);
	// 0x1FCC48: jnz 0x001FCA90
	if (!ctx.flags.zf) goto loc_1FCA90;
	// 0x1FCC4E: jmp 0x001FCD26
	goto loc_1FCD26;
loc_1FCC53:
	// 0x1FCC53: mov ecx, [ebp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x1FCC56: test cl, 0x03
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.ecx) & 3, 8);
	// 0x1FCC59: jnz 0x001FCC8A
	if (!ctx.flags.zf) goto loc_1FCC8A;
	// 0x1FCC5B: cmp ebx, esi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCC5D: jnz 0x001FCC8A
	if (!ctx.flags.zf) goto loc_1FCC8A;
	// 0x1FCC5F: mov eax, [ebp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x1FCC62: cmp eax, 0x800
	{ uint32_t _d = ctx.eax; uint32_t _s = 2048;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCC67: jb 0x001FCC8A
	if (ctx.flags.cf) goto loc_1FCC8A;
	// 0x1FCC69: shr eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FCC6C: shl eax, 0x0B
	{ auto _cnt = 0xBu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x1FCC6F: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x1FCC71: mov [ebp+0x30], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x30u, ctx.ecx);
	// 0x1FCC74: cmp ebp, [0x0041C17C]
	{ uint32_t _d = ctx.ebp; uint32_t _s = X86_MEM_READ_u32(base, 0x41C17Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCC7A: jnz 0x001FCCAC
	if (!ctx.flags.zf) goto loc_1FCCAC;
	// 0x1FCC7C: mov [0x0041C17C], edx
	X86_MEM_WRITE_u32(base, 0x41C17Cu, ctx.edx);
	// 0x1FCC82: mov [0x0041C180], edx
	X86_MEM_WRITE_u32(base, 0x41C180u, ctx.edx);
	// 0x1FCC88: jmp 0x001FCCAC
	goto loc_1FCCAC;
loc_1FCC8A:
	// 0x1FCC8A: mov [0x0041C17C], edx
	X86_MEM_WRITE_u32(base, 0x41C17Cu, ctx.edx);
	// 0x1FCC90: mov [0x0041C180], edx
	X86_MEM_WRITE_u32(base, 0x41C180u, ctx.edx);
	// 0x1FCC96: mov dword ptr [0x0041C184], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, 0x41C184u, -1);
	// 0x1FCCA0: mov ebx, 0x800
	ctx.ebx = 2048;
	// 0x1FCCA5: mov dword ptr [ebp+0x30], 0x41B97C
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x30u, 4307324);
loc_1FCCAC:
	// 0x1FCCAC: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FCCB1: mov ecx, [ebp+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x1FCCB4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCCB5: call [eax+0x28]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCCB8: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCCBB: cmp eax, esi
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCCBD: jnz 0x001FCCFF
	if (!ctx.flags.zf) goto loc_1FCCFF;
	// 0x1FCCBF: mov [ebp+0x28], esi
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x28u, ctx.esi);
	// 0x1FCCC2: mov esi, [esp+0x24]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1FCCC6: mov dword ptr [ebp+0x08], 0x04
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 4);
	// 0x1FCCCD: mov [ebp+0x2C], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x2Cu, ctx.ebx);
	// 0x1FCCD0: mov dword ptr [esi+0x5C], 0x05
	X86_MEM_WRITE_u32(base, ctx.esi + 0x5Cu, 5);
	// 0x1FCCD7: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FCCDC: mov edx, [ebp+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x1FCCDF: mov ecx, [ebp+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x2Cu);
	// 0x1FCCE2: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCCE3: mov edx, [ebp+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x30u);
	// 0x1FCCE6: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCCE8: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCCE9: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCCEA: call [eax+0x0C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCCED: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCCF0: imul eax, [ebp+0x2C]
	{ int64_t _res = (int64_t)(int32_t)ctx.eax * (int64_t)(int32_t)X86_MEM_READ_u32(base, ctx.ebp + 0x2Cu);
	  ctx.eax = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x1FCCF4: mov [esi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x60u, ctx.eax);
	// 0x1FCCF7: mov eax, [ebp+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x2Cu);
	// 0x1FCCFA: mov [esi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x60u, ctx.eax);
	// 0x1FCCFD: jmp 0x001FCD26
	goto loc_1FCD26;
loc_1FCCFF:
	// 0x1FCCFF: mov edi, [esp+0x24]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x24u);
	// 0x1FCD03: mov dword ptr [ebp+0x08], 0x05
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, 5);
	// 0x1FCD0A: mov dword ptr [edi+0x5C], 0x04
	X86_MEM_WRITE_u32(base, ctx.edi + 0x5Cu, 4);
	// 0x1FCD11: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FCD16: mov ecx, [ebp+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x1Cu);
	// 0x1FCD19: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD1B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD1C: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD1D: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCD20: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCD23: mov [edi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x60u, ctx.eax);
loc_1FCD26:
	// 0x1FCD26: mov edx, [0x0041C18C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41C18Cu);
	// 0x1FCD2C: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD2E: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD30: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD31: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1FCD36: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD37: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD38: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD39: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD3A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD3B: ret
	return;
}

void sub_1FCD40(X86Context& ctx, uint8_t* base) {
	// 0x1FCD40: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD41: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FCD45: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD46: mov edi, [esi+0x5C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	// 0x1FCD49: cmp edi, 0x01
	{ uint32_t _d = ctx.edi; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCD4C: jz 0x001FCD80
	if (ctx.flags.zf) goto loc_1FCD80;
	// 0x1FCD4E: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x1FCD51: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FCD53: jz 0x001FCD88
	if (ctx.flags.zf) goto loc_1FCD88;
	// 0x1FCD55: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD57: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD58: call [0x0041B404]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B404u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCD5E: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCD61: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCD64: jnz 0x001FCD88
	if (!ctx.flags.zf) goto loc_1FCD88;
	// 0x1FCD66: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD67: mov [esi+0x5C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x5Cu, ctx.eax);
	// 0x1FCD6A: mov eax, [esi+0x60]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x60u);
	// 0x1FCD6D: mov ecx, [esi+0x20]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x1FCD70: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD71: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD72: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD73: mov ecx, 0x02
	ctx.ecx = 2;
	// 0x1FCD78: call 0x001FCA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCA50(ctx, base);
	ctx.esp += 4;
	// 0x1FCD7D: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FCD80:
	// 0x1FCD80: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD81: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FCD86: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD87: ret
	return;
loc_1FCD88:
	// 0x1FCD88: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD89: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCD8B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCD8C: ret
	return;
}

void _rwaRwStreamCacheOpenModule(X86Context& ctx, uint8_t* base) {
	// 0x1FCD90: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD91: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD93: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCD95: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD97: push 0x41C18C
	{ auto _pv = (uint32_t)(4309388); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCD9C: mov [0x0041C17C], esi
	X86_MEM_WRITE_u32(base, 0x41C17Cu, ctx.esi);
	// 0x1FCDA2: mov [0x0041C180], esi
	X86_MEM_WRITE_u32(base, 0x41C180u, ctx.esi);
	// 0x1FCDA8: mov dword ptr [0x0041C184], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, 0x41C184u, -1);
	// 0x1FCDB2: mov [0x0041C188], esi
	X86_MEM_WRITE_u32(base, 0x41C188u, ctx.esi);
	// 0x1FCDB8: call 0x00204630
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSemaphoreCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FCDBD: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCDBF: mov eax, 0x41B970
	ctx.eax = 4307312;
	// 0x1FCDC4: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCDC6: push 0x41B96C
	{ auto _pv = (uint32_t)(4307308); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCDCB: mov [0x0041B978], esi
	X86_MEM_WRITE_u32(base, 0x41B978u, ctx.esi);
	// 0x1FCDD1: mov [0x0041B970], eax
	X86_MEM_WRITE_u32(base, 0x41B970u, ctx.eax);
	// 0x1FCDD6: mov [0x0041B974], eax
	X86_MEM_WRITE_u32(base, 0x41B974u, ctx.eax);
	// 0x1FCDDB: call 0x00204630
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSemaphoreCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FCDE0: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCDE2: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCDE4: push 0x41B968
	{ auto _pv = (uint32_t)(4307304); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCDE9: call 0x00204630
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSemaphoreCreate(ctx, base);
	ctx.esp += 4;
	// 0x1FCDEE: add esp, 0x24
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(36);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)36, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCDF1: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FCDF6: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCDF7: ret
	return;
}

void sub_1FCE00(X86Context& ctx, uint8_t* base) {
	// 0x1FCE00: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE01: lea esi, [edi+0x04]
	ctx.esi = ctx.edi + 0x4u;
	// 0x1FCE04: mov dword ptr [esi+0x08], 0x03
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 3);
	// 0x1FCE0B: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FCE0D: mov edx, [ecx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x1FCE10: mov ecx, [esp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FCE14: mov [esi+0x1C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.edx);
	// 0x1FCE17: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FCE1B: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x1FCE1E: mov [esi+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.eax);
	// 0x1FCE21: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FCE25: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x1FCE28: mov [esi+0x38], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.ecx);
	// 0x1FCE2B: mov [esi+0x3C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.edx);
	// 0x1FCE2E: mov eax, [0x0041B96C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCE33: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE35: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE36: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCE3B: push 0x41B968
	{ auto _pv = (uint32_t)(4307304); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE40: call 0x00204650
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_204650(ctx, base);
	ctx.esp += 4;
	// 0x1FCE45: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCE48: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FCE4A: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE4C: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE4E: jz 0x001FCE79
	if (ctx.flags.zf) goto loc_1FCE79;
	// 0x1FCE50: mov ecx, [0x0041B96C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCE56: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE57: mov [0x0041B978], esi
	X86_MEM_WRITE_u32(base, 0x41B978u, ctx.esi);
	// 0x1FCE5D: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1FCE62: mov edx, [esi+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x1FCE65: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1FCE68: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE69: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE6B: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE6C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCE6D: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCE6F: call 0x001FCA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCA50(ctx, base);
	ctx.esp += 4;
	// 0x1FCE74: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCE77: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCE78: ret
	return;
loc_1FCE79:
	// 0x1FCE79: mov ecx, [0x0041B970]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B970u);
	// 0x1FCE7F: mov [esi], ecx
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.ecx);
	// 0x1FCE81: mov dword ptr [esi+0x04], 0x41B970
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, 4307312);
	// 0x1FCE88: mov edx, [0x0041B970]
	ctx.edx = X86_MEM_READ_u32(base, 0x41B970u);
	// 0x1FCE8E: mov [edx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.esi);
	// 0x1FCE91: mov [0x0041B970], esi
	X86_MEM_WRITE_u32(base, 0x41B970u, ctx.esi);
	// 0x1FCE97: mov dword ptr [esi+0x08], 0x02
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 2);
	// 0x1FCE9E: mov eax, [0x0041B96C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCEA3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEA4: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1FCEA9: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCEAA: ret
	return;
}

void sub_1FCEB0(X86Context& ctx, uint8_t* base) {
	// 0x1FCEB0: mov eax, [0x0041C18C]
	ctx.eax = X86_MEM_READ_u32(base, 0x41C18Cu);
	// 0x1FCEB5: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEB6: mov ebp, [esp+0x08]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FCEBA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEBB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEBC: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEBE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEBF: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCEC1: lea esi, [ebp+0x04]
	ctx.esi = ctx.ebp + 0x4u;
	// 0x1FCEC4: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCEC9: mov ecx, [0x0041B96C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCECF: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCED1: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCED2: call 0x001D1608
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	WaitForSingleObject(ctx, base);
	ctx.esp += 4;
	// 0x1FCED7: push 0x41B968
	{ auto _pv = (uint32_t)(4307304); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEDC: call 0x00204650
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_204650(ctx, base);
	ctx.esp += 4;
	// 0x1FCEE1: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCEE4: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FCEE6: jnz 0x001FCF2E
	if (!ctx.flags.zf) goto loc_1FCF2E;
	// 0x1FCEE8: cmp [0x0041B978], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41B978u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCEEE: jnz 0x001FCF10
	if (!ctx.flags.zf) goto loc_1FCF10;
	// 0x1FCEF0: mov edx, [esi+0x1C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1FCEF3: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCEF4: call [0x0041B408]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x41B408u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FCEFA: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCEFD: mov edi, 0x01
	ctx.edi = 1;
	// 0x1FCF02: mov dword ptr [esi+0x08], 0x03
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 3);
	// 0x1FCF09: mov dword ptr [esi+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, 0);
loc_1FCF10:
	// 0x1FCF10: cmp [0x0041C17C], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, 0x41C17Cu); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCF16: jnz 0x001FCF3D
	if (!ctx.flags.zf) goto loc_1FCF3D;
	// 0x1FCF18: mov dword ptr [0x0041C17C], 0x00
	X86_MEM_WRITE_u32(base, 0x41C17Cu, 0);
	// 0x1FCF22: mov dword ptr [0x0041C180], 0x00
	X86_MEM_WRITE_u32(base, 0x41C180u, 0);
	// 0x1FCF2C: jmp 0x001FCF3D
	goto loc_1FCF3D;
loc_1FCF2E:
	// 0x1FCF2E: mov eax, [0x0041B968]
	ctx.eax = X86_MEM_READ_u32(base, 0x41B968u);
	// 0x1FCF33: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF35: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF37: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF38: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
loc_1FCF3D:
	// 0x1FCF3D: mov eax, [esi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FCF3F: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x1FCF41: jz 0x001FCF5D
	if (ctx.flags.zf) goto loc_1FCF5D;
	// 0x1FCF43: mov ecx, [esi+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FCF46: mov [ecx], eax
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.eax);
	// 0x1FCF48: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FCF4A: mov eax, [esi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x4u);
	// 0x1FCF4D: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x1FCF50: mov dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, 0);
	// 0x1FCF56: mov dword ptr [esi+0x08], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 1);
loc_1FCF5D:
	// 0x1FCF5D: mov ecx, [0x0041B96C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41B96Cu);
	// 0x1FCF63: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF65: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF67: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF68: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1FCF6D: mov edx, [0x0041C18C]
	ctx.edx = X86_MEM_READ_u32(base, 0x41C18Cu);
	// 0x1FCF73: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF75: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF77: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF78: call 0x001D154C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	ReleaseSemaphore(ctx, base);
	ctx.esp += 4;
	// 0x1FCF7D: test edi, edi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edi, 32);
	// 0x1FCF7F: jz 0x001FCF97
	if (ctx.flags.zf) goto loc_1FCF97;
	// 0x1FCF81: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x1FCF84: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF85: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF87: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF89: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCF8A: mov ecx, 0x02
	ctx.ecx = 2;
	// 0x1FCF8F: call 0x001FCA50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCA50(ctx, base);
	ctx.esp += 4;
	// 0x1FCF94: add esp, 0x10
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(16);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)16, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FCF97:
	// 0x1FCF97: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCF98: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCF99: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCF9A: ret
	return;
}

void sub_1FCFA0(X86Context& ctx, uint8_t* base) {
	// 0x1FCFA0: jmp 0x001FCEB0
	sub_1FCEB0(ctx, base);
	return;
}

void sub_1FCFB0(X86Context& ctx, uint8_t* base) {
	// 0x1FCFB0: mov ecx, [esp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FCFB4: mov eax, [esp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FCFB8: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFB9: mov edi, [esp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FCFBD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFBE: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFBF: mov [edi+0x48], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x48u, ctx.eax);
	// 0x1FCFC2: mov eax, [esp+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FCFC6: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFC7: mov eax, [esp+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x1FCFCB: mov [edi+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4Cu, ctx.ecx);
	// 0x1FCFCE: mov dword ptr [edi+0x44], 0x03
	X86_MEM_WRITE_u32(base, ctx.edi + 0x44u, 3);
	// 0x1FCFD5: call 0x001FCE00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCE00(ctx, base);
	ctx.esp += 4;
	// 0x1FCFDA: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FCFDD: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FCFDE: ret
	return;
}

void sub_1FCFE0(X86Context& ctx, uint8_t* base) {
	// 0x1FCFE0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFE1: mov ebp, [esp+0x08]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FCFE5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFE6: xor esi, esi
	ctx.esi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FCFE8: cmp eax, 0x04
	{ uint32_t _d = ctx.eax; uint32_t _s = 4;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FCFEB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FCFEC: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x1FCFEE: jnz 0x001FD01C
	if (!ctx.flags.zf) goto loc_1FD01C;
	// 0x1FCFF0: mov eax, [edi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FCFF3: mov [edi+0x44], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x44u, ctx.esi);
	// 0x1FCFF6: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x1FCFF8: mov ecx, [edi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FCFFB: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1FCFFE: mov edx, [edi+0x54]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD001: mov [edx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.esi);
	// 0x1FD004: mov eax, [edi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4Cu);
	// 0x1FD007: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FD009: mov edx, [ecx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x1FD00C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD00D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD00E: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD010: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD011: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD012: call [edi+0x48]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edi + 0x48u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FD015: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD018: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD019: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD01A: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD01B: ret
	return;
loc_1FD01C:
	// 0x1FD01C: cmp [edi+0x58], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi + 0x58u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FD01F: jz 0x001FD03F
	if (ctx.flags.zf) goto loc_1FD03F;
	// 0x1FD021: mov eax, [edi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD024: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD025: push 0x1FD0E0
	{ auto _pv = (uint32_t)(2085088); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD02A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD02B: mov eax, 0x0C
	ctx.eax = 12;
	// 0x1FD030: mov [edi+0x58], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x58u, ctx.esi);
	// 0x1FD033: call 0x001FCE00
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCE00(ctx, base);
	ctx.esp += 4;
	// 0x1FD038: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD03B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD03C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD03D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD03E: ret
	return;
loc_1FD03F:
	// 0x1FD03F: mov ecx, [edi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD042: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FD044: cmp edx, [edi+0x50]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.edi + 0x50u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FD047: jnz 0x001FD064
	if (!ctx.flags.zf) goto loc_1FD064;
	// 0x1FD049: mov ecx, [edi+0x4C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x4Cu);
	// 0x1FD04C: mov edx, [edi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FD04E: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD04F: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD050: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD051: mov [edi+0x44], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x44u, ctx.esi);
	// 0x1FD054: mov eax, [edx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x1FD057: push 0x0C
	{ auto _pv = (uint32_t)(12); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD059: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD05A: call [edi+0x48]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edi + 0x48u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FD05D: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD060: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD061: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD062: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD063: ret
	return;
loc_1FD064:
	// 0x1FD064: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD065: mov dword ptr [edi+0x58], 0x01
	X86_MEM_WRITE_u32(base, ctx.edi + 0x58u, 1);
	// 0x1FD06C: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FD071: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FD073: mov edx, [ecx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x1FD076: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD077: call [eax+0x28]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FD07A: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x1FD07C: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD07F: cmp ebx, esi
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FD081: jnl 0x001FD0AD
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_1FD0AD;
	// 0x1FD083: mov eax, [edi+0x54]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD086: mov [eax], esi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.esi);
	// 0x1FD088: mov ecx, [edi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD08B: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x1FD08E: mov edx, [edi+0x54]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD091: mov [edx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.esi);
	// 0x1FD094: mov eax, [edi+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4Cu);
	// 0x1FD097: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FD099: mov edx, [ecx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x1FD09C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD09D: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD09E: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD0A0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD0A1: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD0A2: call [edi+0x48]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.edi + 0x48u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FD0A5: add esp, 0x14
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(20);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)20, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD0A8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0A9: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0AA: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0AB: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0AC: ret
	return;
loc_1FD0AD:
	// 0x1FD0AD: mov dword ptr [edi+0x5C], 0x04
	X86_MEM_WRITE_u32(base, ctx.edi + 0x5Cu, 4);
	// 0x1FD0B4: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FD0B9: mov ecx, [edi+0x54]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x54u);
	// 0x1FD0BC: mov edx, [ecx+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x1FD0BF: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x1FD0C1: add edx, ebx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ebx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ebx, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x1FD0C3: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD0C4: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD0C5: mov edx, [ecx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x1FD0C8: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD0C9: call [eax+0x20]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FD0CC: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD0CF: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0D0: mov [edi+0x60], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x60u, ctx.eax);
	// 0x1FD0D3: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0D4: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0D5: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD0D6: ret
	return;
}

void sub_1FD0E0(X86Context& ctx, uint8_t* base) {
	// 0x1FD0E0: mov ecx, [esp+0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x14u);
	// 0x1FD0E4: mov eax, [ecx+0x44]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x44u);
	// 0x1FD0E7: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FD0E8: jz 0x001FD10C
	if (ctx.flags.zf) goto loc_1FD10C;
	// 0x1FD0EA: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FD0EB: jz 0x001FD0FA
	if (ctx.flags.zf) goto loc_1FD0FA;
	// 0x1FD0ED: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FD0EE: jnz 0x001FD10B
	if (!ctx.flags.zf) goto loc_1FD10B;
	// 0x1FD0F0: mov eax, [ecx+0x4C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x4Cu);
	// 0x1FD0F3: mov [esp+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.eax);
	// 0x1FD0F7: jmp [ecx+0x48]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, ctx.ecx + 0x48u));
	return;
loc_1FD0FA:
	// 0x1FD0FA: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FD0FE: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FD102: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD103: call 0x001FCFE0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCFE0(ctx, base);
	ctx.esp += 4;
	// 0x1FD108: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FD10B:
	// 0x1FD10B: ret
	return;
loc_1FD10C:
	// 0x1FD10C: mov edx, [ecx]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx);
	// 0x1FD10E: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x1FD112: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
	// 0x1FD115: mov edx, [ecx+0x4C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0x4Cu);
	// 0x1FD118: mov [esp+0x14], edx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x14u, ctx.edx);
	// 0x1FD11C: mov [esp+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.eax);
	// 0x1FD120: jmp [ecx+0x48]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, ctx.ecx + 0x48u));
	return;
}

void sub_1FD130(X86Context& ctx, uint8_t* base) {
	// 0x1FD130: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x1FD134: mov ecx, [esp+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x1FD138: sub esp, 0x40
	{ uint32_t _d = ctx.esp; uint32_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD13B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD13C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD13D: mov edi, [esp+0x4C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x4Cu);
	// 0x1FD141: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FD143: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	// 0x1FD145: sub eax, 0x02
	{ uint32_t _d = ctx.eax; uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x1FD148: mov [edi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.ebx);
	// 0x1FD14B: mov [edi+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.ecx);
	// 0x1FD14E: jnz 0x001FD1C5
	if (!ctx.flags.zf) goto loc_1FD1C5;
	// 0x1FD150: mov edx, [esp+0x60]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x60u);
	// 0x1FD154: mov ecx, [esp+0x64]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x64u);
	// 0x1FD158: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD159: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD15A: mov esi, [esp+0x58]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x58u);
	// 0x1FD15E: mov eax, 0x01
	ctx.eax = 1;
	// 0x1FD163: mov [esi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.ebx);
	// 0x1FD166: mov [esi+0x04], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4u, ctx.ebx);
	// 0x1FD169: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x1FD16C: mov dword ptr [esi+0x3C], 0x1FD0E0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, 2085088);
	// 0x1FD173: mov [esi+0x40], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x40u, ctx.esi);
	// 0x1FD176: mov [esi+0x38], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.esi);
	// 0x1FD179: mov [esi+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebx);
	// 0x1FD17C: mov [esi+0x24], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.ebx);
	// 0x1FD17F: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x1FD181: mov [esi+0x48], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x48u, ctx.edx);
	// 0x1FD184: mov [esi+0x4C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x4Cu, ctx.ecx);
	// 0x1FD187: mov [esi+0x44], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x44u, ctx.eax);
	// 0x1FD18A: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FD18F: mov ebp, [esp+0x64]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp + 0x64u);
	// 0x1FD193: push 0x36DB98
	{ auto _pv = (uint32_t)(3595160); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD198: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD199: call [eax+0x04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x1FD19C: add esp, 0x08
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(8);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)8, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD19F: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FD1A1: mov [esi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.eax);
	// 0x1FD1A4: jnz 0x001FD1B9
	if (!ctx.flags.zf) goto loc_1FD1B9;
	// 0x1FD1A6: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD1A7: lea edx, [esp+0x14]
	ctx.edx = ctx.esp + 0x14u;
	// 0x1FD1AB: push 0x36DF7C
	{ auto _pv = (uint32_t)(3596156); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD1B0: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD1B1: call 0x00243215
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_sprintf(ctx, base);
	ctx.esp += 4;
	// 0x1FD1B6: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
loc_1FD1B9:
	// 0x1FD1B9: mov dword ptr [esi+0x5C], 0x02
	X86_MEM_WRITE_u32(base, ctx.esi + 0x5Cu, 2);
	// 0x1FD1C0: mov [esi+0x60], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x60u, ctx.ebx);
	// 0x1FD1C3: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD1C4: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_1FD1C5:
	// 0x1FD1C5: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x1FD1C7: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD1C8: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD1C9: add esp, 0x40
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(64);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)64, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD1CC: ret
	return;
}

void sub_1FD1D0(X86Context& ctx, uint8_t* base) {
	// 0x1FD1D0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD1D1: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x1FD1D5: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x1FD1D6: call 0x001FCEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1FCEB0(ctx, base);
	ctx.esp += 4;
	// 0x1FD1DB: mov ecx, [0x0041C17C]
	ctx.ecx = X86_MEM_READ_u32(base, 0x41C17Cu);
	// 0x1FD1E1: lea eax, [esi+0x04]
	ctx.eax = ctx.esi + 0x4u;
	// 0x1FD1E4: add esp, 0x04
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(4);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)4, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x1FD1E7: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FD1E9: jnz 0x001FD206
	if (!ctx.flags.zf) goto loc_1FD206;
	// 0x1FD1EB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x1FD1ED: mov [0x0041C17C], eax
	X86_MEM_WRITE_u32(base, 0x41C17Cu, ctx.eax);
	// 0x1FD1F2: mov [0x0041C180], eax
	X86_MEM_WRITE_u32(base, 0x41C180u, ctx.eax);
	// 0x1FD1F7: mov dword ptr [0x0041C184], 0xFFFFFFFF
	X86_MEM_WRITE_u32(base, 0x41C184u, -1);
	// 0x1FD201: mov [0x0041C188], eax
	X86_MEM_WRITE_u32(base, 0x41C188u, ctx.eax);
loc_1FD206:
	// 0x1FD206: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FD208: cmp dword ptr [ecx], 0x02
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx); uint32_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x1FD20B: jnz 0x001FD21F
	if (!ctx.flags.zf) goto loc_1FD21F;
	// 0x1FD20D: call 0x001DEEB0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	RwaSPU2RemoteIOPFopsReadToEE(ctx, base);
	ctx.esp += 4;
	// 0x1FD212: mov edx, [esi]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x1FD214: mov ecx, [edx+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x1FD217: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD218: mov [esp+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x4u, ctx.ecx);
	// 0x1FD21C: jmp [eax+0x08]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, ctx.eax + 0x8u));
	return;
loc_1FD21F:
	// 0x1FD21F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x1FD220: ret
	return;
}

