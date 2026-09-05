#include "x86_recomp_shared.h"

void sub_369E83(X86Context& ctx, uint8_t* base) {
	// 0x369E83: push 0x04
	{ auto _pv = (uint32_t)(4); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369E85: mov eax, 0x41D1E0
	ctx.eax = 4313568;
	// 0x369E8A: pop edx
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x369E8B: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_369E8D:
	// 0x369E8D: mov dword ptr [eax-0x08], 0x3710D4
	X86_MEM_WRITE_u32(base, ctx.eax - 0x8u, 3608788);
	// 0x369E94: mov [eax-0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax - 0x4u, ctx.ecx);
	// 0x369E97: mov [eax], cx
	X86_MEM_WRITE_u16(base, ctx.eax, X86_REG16(ctx.ecx));
	// 0x369E9A: mov [eax+0x02], cl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x2u, X86_REG8L(ctx.ecx));
	// 0x369E9D: mov [eax+0x03], cl
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3u, X86_REG8L(ctx.ecx));
	// 0x369EA0: mov [eax+0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x4u, ctx.ecx);
	// 0x369EA3: mov [eax+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, ctx.ecx);
	// 0x369EA6: mov [eax+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, ctx.ecx);
	// 0x369EA9: mov [eax+0x10], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.ecx);
	// 0x369EAC: add eax, 0x1C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(28);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)28, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x369EAF: dec edx
	{ uint32_t _d = ctx.edx;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x369EB0: jnz 0x00369E8D
	if (!ctx.flags.zf) goto loc_369E8D;
	// 0x369EB2: ret
	return;
}

void XReadMUMetaData(X86Context& ctx, uint8_t* base) {
	// 0x369EB3: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369EB4: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x369EB6: sub esp, 0x94
	{ uint32_t _d = ctx.esp; uint32_t _s = 148;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x369EBC: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369EBD: mov bl, [ebp+0x08]
	X86_REG8L(ctx.ebx) = X86_MEM_READ_u8(base, ctx.ebp + 0x8u);
	// 0x369EC0: add bl, 0x23
	{ uint64_t _res = (uint64_t)(uint8_t)(X86_REG8L(ctx.ebx)) + (uint64_t)(uint8_t)(35);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int8_t)X86_REG8L(ctx.ebx), (int8_t)35, 8);
	  X86_REG8L(ctx.ebx) = (uint8_t)_res; }
	// 0x369EC3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369EC4: shl bl, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8L(ctx.ebx) >> (8 - _cnt)) & 1;
	  X86_REG8L(ctx.ebx) = X86_REG8L(ctx.ebx) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ebx), 8); } }
	// 0x369EC6: add bl, [ebp+0x0C]
	{ uint64_t _res = (uint64_t)(uint8_t)(X86_REG8L(ctx.ebx)) + (uint64_t)(uint8_t)(X86_MEM_READ_u8(base, ctx.ebp + 0xCu));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int8_t)X86_REG8L(ctx.ebx), (int8_t)X86_MEM_READ_u8(base, ctx.ebp + 0xCu), 8);
	  X86_REG8L(ctx.ebx) = (uint8_t)_res; }
	// 0x369EC9: push 0x362CC4
	{ auto _pv = (uint32_t)(3550404); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369ECE: call [0x0036B880]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B880u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x369ED4: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x369ED6: mov cl, bl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ebx);
	// 0x369ED8: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x369EDA: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x369EDB: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x369EDD: sub ecx, 0x46
	{ uint32_t _d = ctx.ecx; uint32_t _s = 70;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x369EE0: shl eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (32 - _cnt)) & 1;
	  ctx.eax = ctx.eax << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x369EE2: test [0x0041A7D0], eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, 0x41A7D0u) & ctx.eax, 32);
	// 0x369EE8: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
	// 0x369EEB: jnz 0x00369F13
	if (!ctx.flags.zf) goto loc_369F13;
	// 0x369EED: lea eax, [ebp-0x94]
	ctx.eax = ctx.ebp - 0x94u;
	// 0x369EF3: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x369EF6: lea eax, [ebp-0x10]
	ctx.eax = ctx.ebp - 0x10u;
	// 0x369EF9: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369EFA: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369EFD: mov [ebp-0x10], bx
	X86_MEM_WRITE_u16(base, ctx.ebp - 0x10u, X86_REG16(ctx.ebx));
	// 0x369F01: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F04: mov word ptr [ebp-0x0E], 0x3E
	X86_MEM_WRITE_u16(base, ctx.ebp - 0xEu, 62);
	// 0x369F0A: call 0x0036A2A2
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A2A2(ctx, base);
	ctx.esp += 4;
	// 0x369F0F: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x369F11: jmp 0x00369F15
	goto loc_369F15;
loc_369F13:
	// 0x369F13: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_369F15:
	// 0x369F15: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369F17: jl 0x0036A006
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36A006;
	// 0x369F1D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F1E: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F21: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F24: call 0x0036A0F7
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A0F7(ctx, base);
	ctx.esp += 4;
	// 0x369F29: mov esi, [0x0036B9F0]
	ctx.esi = X86_MEM_READ_u32(base, 0x36B9F0u);
	// 0x369F2F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F30: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F31: push 0x18
	{ auto _pv = (uint32_t)(24); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F33: lea ecx, [ebp-0x54]
	ctx.ecx = ctx.ebp - 0x54u;
	// 0x369F36: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F37: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F38: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F39: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F3A: push 0x70000
	{ auto _pv = (uint32_t)(458752); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F3F: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x369F42: call esi
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.esi);
	ctx.esp += 4;
	// 0x369F44: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x369F46: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369F48: jl 0x00369FEF
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_369FEF;
	// 0x369F4E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F4F: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F50: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F52: lea eax, [ebp-0x3C]
	ctx.eax = ctx.ebp - 0x3Cu;
	// 0x369F55: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F56: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F57: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F58: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F5B: push 0x74004
	{ auto _pv = (uint32_t)(475140); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F60: call esi
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, ctx.esi);
	ctx.esp += 4;
	// 0x369F62: cmp [ebp-0x30], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x30u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369F65: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x369F67: mov esi, 0x1000
	ctx.esi = 4096;
	// 0x369F6C: jnle 0x00369F7A
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_369F7A;
	// 0x369F6E: jl 0x00369F75
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_369F75;
	// 0x369F70: cmp [ebp-0x34], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x34u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369F73: jnb 0x00369F7A
	if (!ctx.flags.cf) goto loc_369F7A;
loc_369F75:
	// 0x369F75: mov edi, 0xC000014F
	ctx.edi = -1073741489;
loc_369F7A:
	// 0x369F7A: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369F7C: jl 0x00369FEF
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_369FEF;
	// 0x369F7E: push 0x24830000
	{ auto _pv = (uint32_t)(612564992); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F83: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F84: call 0x001D2879
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemAlloc(ctx, base);
	ctx.esp += 4;
	// 0x369F89: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369F8B: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x369F8E: jz 0x00369FEA
	if (ctx.flags.zf) goto loc_369FEA;
	// 0x369F90: lea ecx, [ebp-0x1C]
	ctx.ecx = ctx.ebp - 0x1Cu;
	// 0x369F93: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F94: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F95: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F96: push [ebp-0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F99: mov [ebp-0x1C], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x1Cu, ctx.ebx);
	// 0x369F9C: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369F9E: mov [ebp-0x18], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x18u, ctx.ebx);
	// 0x369FA1: call [0x0036B9EC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9ECu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x369FA7: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x369FA9: cmp edi, ebx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369FAB: jl 0x00369FDB
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_369FDB;
	// 0x369FAD: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x369FB0: cmp dword ptr [eax], 0x58544146
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax); uint32_t _s = 1481916742;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x369FB6: jnz 0x00369FD6
	if (!ctx.flags.zf) goto loc_369FD6;
	// 0x369FB8: mov edx, [ebp+0x14]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x14u);
	// 0x369FBB: mov ecx, [ebp+0x18]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x18u);
	// 0x369FBE: mov edi, [ebp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x369FC1: lea esi, [eax+edx*1]
	ctx.esi = ctx.eax + ctx.edx;
	// 0x369FC4: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x369FC6: shr ecx, 0x02
	{ auto _cnt = 0x2u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (_cnt - 1)) & 1;
	  ctx.ecx = (uint32_t)(ctx.ecx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x369FC9: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x369FCB: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x369FCD: and ecx, 0x03
	ctx.ecx = ctx.ecx & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x369FD0: rep movsb
	while (ctx.ecx) {
		X86_MEM_WRITE_u8(base, ctx.edi, X86_MEM_READ_u8(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -1 : 1;
		ctx.edi += ctx.flags.df ? -1 : 1;
		ctx.ecx--;
	}
	// 0x369FD2: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x369FD4: jmp 0x00369FDB
	goto loc_369FDB;
loc_369FD6:
	// 0x369FD6: mov edi, 0xC000014F
	ctx.edi = -1073741489;
loc_369FDB:
	// 0x369FDB: push 0x24830000
	{ auto _pv = (uint32_t)(612564992); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369FE0: push [ebp-0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369FE3: call 0x001D2919
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	XMemFree(ctx, base);
	ctx.esp += 4;
	// 0x369FE8: jmp 0x00369FEF
	goto loc_369FEF;
loc_369FEA:
	// 0x369FEA: mov edi, 0xC000009A
	ctx.edi = -1073741670;
loc_369FEF:
	// 0x369FEF: mov eax, [ebp-0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x369FF2: test [0x0041A7D0], eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, 0x41A7D0u) & ctx.eax, 32);
	// 0x369FF8: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x369FF9: jnz 0x0036A006
	if (!ctx.flags.zf) goto loc_36A006;
	// 0x369FFB: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x369FFE: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A001: call 0x0036A235
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A235(ctx, base);
	ctx.esp += 4;
loc_36A006:
	// 0x36A006: push 0x362CC4
	{ auto _pv = (uint32_t)(3550404); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A00B: call [0x0036B87C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B87Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A011: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A012: call [0x0036B80C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B80Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A018: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A019: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A01A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A01B: ret 0x14
	ctx.esp += 20;
	return;
}

void sub_36A01E(X86Context& ctx, uint8_t* base) {
	// 0x36A01E: mov eax, [0x0041D5D0]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5D0u);
	// 0x36A023: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36A025: jz 0x0036A038
	if (ctx.flags.zf) goto loc_36A038;
	// 0x36A027: mov ecx, [eax+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x36A02A: mov [0x0041D5D0], ecx
	X86_MEM_WRITE_u32(base, 0x41D5D0u, ctx.ecx);
	// 0x36A030: and dword ptr [eax+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0xCu, X86_MEM_READ_u32(base, ctx.eax + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0xCu), 32);
	// 0x36A034: and dword ptr [eax+0x08], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x8u, X86_MEM_READ_u32(base, ctx.eax + 0x8u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x8u), 32);
loc_36A038:
	// 0x36A038: ret
	return;
}

void sub_36A039(X86Context& ctx, uint8_t* base) {
	// 0x36A039: mov edx, [esp+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x36A03D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A03E: push 0x58
	{ auto _pv = (uint32_t)(88); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A040: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A041: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A043: lea edi, [edx+0x10]
	ctx.edi = ctx.edx + 0x10u;
	// 0x36A046: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x36A048: mov dword ptr [edx+0x0C], 0x04
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, 4);
	// 0x36A04F: mov eax, [0x0041D5D0]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5D0u);
	// 0x36A054: mov [edx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.eax);
	// 0x36A057: mov [0x0041D5D0], edx
	X86_MEM_WRITE_u32(base, 0x41D5D0u, ctx.edx);
	// 0x36A05D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A05E: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_36A061(X86Context& ctx, uint8_t* base) {
	// 0x36A061: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A062: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A063: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A064: mov edi, [esp+0x10]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x36A068: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A06A: call 0x00364F61
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364F61(ctx, base);
	ctx.esp += 4;
	// 0x36A06F: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A071: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A073: cmp eax, 0x10
	{ uint32_t _d = ctx.eax; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A076: jb 0x0036A07C
	if (ctx.flags.cf) goto loc_36A07C;
	// 0x36A078: sub eax, 0x10
	{ uint32_t _d = ctx.eax; uint32_t _s = 16;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36A07B: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
loc_36A07C:
	// 0x36A07C: lea eax, [ecx+eax*2]
	ctx.eax = ctx.ecx + ctx.eax * 2;
	// 0x36A07F: mov ecx, [0x004205DC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x4205DCu);
	// 0x36A085: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A086: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x36A089: push 0x01
	{ auto _pv = (uint32_t)(1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A08B: lea esi, [ecx+eax*4]
	ctx.esi = ctx.ecx + ctx.eax * 4;
	// 0x36A08E: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A090: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A092: call 0x00364EEB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364EEB(ctx, base);
	ctx.esp += 4;
	// 0x36A097: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A099: jz 0x0036A0E5
	if (ctx.flags.zf) goto loc_36A0E5;
	// 0x36A09B: mov cl, [eax+0x02]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x2u);
	// 0x36A09E: mov [esi+0x05], cl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x5u, X86_REG8L(ctx.ecx));
	// 0x36A0A1: cmp word ptr [eax+0x04], 0x40
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.eax + 0x4u); uint16_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x36A0A6: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A0A8: jnz 0x0036A0E7
	if (!ctx.flags.zf) goto loc_36A0E7;
	// 0x36A0AA: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A0AB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A0AC: push 0x02
	{ auto _pv = (uint32_t)(2); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A0AE: call 0x00364EEB
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364EEB(ctx, base);
	ctx.esp += 4;
	// 0x36A0B3: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A0B5: jz 0x0036A0E5
	if (ctx.flags.zf) goto loc_36A0E5;
	// 0x36A0B7: mov cl, [eax+0x02]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.eax + 0x2u);
	// 0x36A0BA: mov [esi+0x06], cl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x6u, X86_REG8L(ctx.ecx));
	// 0x36A0BD: cmp word ptr [eax+0x04], 0x40
	{ uint16_t _d = X86_MEM_READ_u16(base, ctx.eax + 0x4u); uint16_t _s = 64;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int16_t)_d, (int16_t)_s, 16); }
	// 0x36A0C2: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A0C4: jnz 0x0036A0E7
	if (!ctx.flags.zf) goto loc_36A0E7;
	// 0x36A0C6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A0C7: call 0x00364DF0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364DF0(ctx, base);
	ctx.esp += 4;
	// 0x36A0CC: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A0CE: mov [esi], edi
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.edi);
	// 0x36A0D0: call 0x00364DFD
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364DFD(ctx, base);
	ctx.esp += 4;
	// 0x36A0D5: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A0D6: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A0D8: mov [esi+0x04], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4u, X86_REG8L(ctx.eax));
	// 0x36A0DB: call 0x00364E01
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364E01(ctx, base);
	ctx.esp += 4;
	// 0x36A0E0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A0E1: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36A0E3: jmp 0x0036A0EC
	goto loc_36A0EC;
loc_36A0E5:
	// 0x36A0E5: mov ecx, edi
	ctx.ecx = ctx.edi;
loc_36A0E7:
	// 0x36A0E7: push 0x80000400
	{ auto _pv = (uint32_t)(-2147482624); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_36A0EC:
	// 0x36A0EC: call 0x00365B46
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_365B46(ctx, base);
	ctx.esp += 4;
	// 0x36A0F1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A0F2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A0F3: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A0F4: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_36A0F7(X86Context& ctx, uint8_t* base) {
	// 0x36A0F7: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x36A0FB: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x36A0FF: lea eax, [eax+ecx*2]
	ctx.eax = ctx.eax + ctx.ecx * 2;
	// 0x36A102: mov ecx, [0x004205DC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x4205DCu);
	// 0x36A108: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x36A10B: mov eax, [ecx+eax*4+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + ctx.eax * 4 + 0x8u);
	// 0x36A10F: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36A111: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36A114(X86Context& ctx, uint8_t* base) {
	// 0x36A114: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A115: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x36A119: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36A11C: test eax, 0x40000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 262144, 32);
	// 0x36A121: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A122: mov edi, [esi+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36A125: jz 0x0036A142
	if (ctx.flags.zf) goto loc_36A142;
	// 0x36A127: mov edx, [esi+0x24]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x36A12A: and dword ptr [esi+0x24], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, X86_MEM_READ_u32(base, ctx.esi + 0x24u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x24u), 32);
	// 0x36A12E: mov byte ptr [esi+0x111], 0x43
	X86_MEM_WRITE_u8(base, ctx.esi + 0x111u, 67);
	// 0x36A135: mov [esi+0x120], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x120u, ctx.edx);
	// 0x36A13B: and eax, 0xFFFBFFFF
	ctx.eax = ctx.eax & -262145;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A140: jmp 0x0036A177
	goto loc_36A177;
loc_36A142:
	// 0x36A142: test eax, 0x20000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 131072, 32);
	// 0x36A147: jz 0x0036A164
	if (ctx.flags.zf) goto loc_36A164;
	// 0x36A149: mov edx, [esi+0x20]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x36A14C: and dword ptr [esi+0x20], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, X86_MEM_READ_u32(base, ctx.esi + 0x20u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x20u), 32);
	// 0x36A150: mov byte ptr [esi+0x111], 0x43
	X86_MEM_WRITE_u8(base, ctx.esi + 0x111u, 67);
	// 0x36A157: mov [esi+0x120], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x120u, ctx.edx);
	// 0x36A15D: and eax, 0xFFFDFFFF
	ctx.eax = ctx.eax & -131073;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A162: jmp 0x0036A177
	goto loc_36A177;
loc_36A164:
	// 0x36A164: test eax, 0x10000
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & 65536, 32);
	// 0x36A169: jz 0x0036A19D
	if (ctx.flags.zf) goto loc_36A19D;
	// 0x36A16B: mov byte ptr [esi+0x111], 0xC3
	X86_MEM_WRITE_u8(base, ctx.esi + 0x111u, -61);
	// 0x36A172: and eax, 0xFFFEFFFF
	ctx.eax = ctx.eax & -65537;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
loc_36A177:
	// 0x36A177: lea ecx, [esi+0x110]
	ctx.ecx = ctx.esi + 0x110u;
	// 0x36A17D: mov byte ptr [ecx], 0x1C
	X86_MEM_WRITE_u8(base, ctx.ecx, 28);
	// 0x36A180: mov dword ptr [esi+0x118], 0x36A114
	X86_MEM_WRITE_u32(base, ctx.esi + 0x118u, 3580180);
	// 0x36A18A: mov [esi+0x11C], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x11Cu, ctx.esi);
	// 0x36A190: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36A193: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A194: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36A196: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36A19B: jmp 0x0036A1E1
	goto loc_36A1E1;
loc_36A19D:
	// 0x36A19D: and eax, 0xFFF7FFFF
	ctx.eax = ctx.eax & -524289;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A1A2: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A1A3: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A1A5: test al, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 1, 8);
	// 0x36A1A7: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36A1AA: mov [esi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.ebx);
	// 0x36A1AD: jz 0x0036A1C5
	if (ctx.flags.zf) goto loc_36A1C5;
	// 0x36A1AF: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A1B0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A1B1: lea eax, [esi+0x12C]
	ctx.eax = ctx.esi + 0x12Cu;
	// 0x36A1B7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A1B8: mov [edi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.ebx);
	// 0x36A1BB: call [0x0036B8E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A1C1: and dword ptr [esi+0x0C], 0xFFFFFFFE
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
loc_36A1C5:
	// 0x36A1C5: test byte ptr [esi+0x0C], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 2, 8);
	// 0x36A1C9: jz 0x0036A1E0
	if (ctx.flags.zf) goto loc_36A1E0;
	// 0x36A1CB: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36A1CD: call 0x0036577A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36577A(ctx, base);
	ctx.esp += 4;
	// 0x36A1D2: mov [edi], ebx
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.ebx);
	// 0x36A1D4: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36A1D7: and eax, 0xFFFFFFFD
	ctx.eax = ctx.eax & -3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A1DA: or eax, 0x04
	ctx.eax = ctx.eax | 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A1DD: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
loc_36A1E0:
	// 0x36A1E0: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_36A1E1:
	// 0x36A1E1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A1E2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A1E3: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36A1E6(X86Context& ctx, uint8_t* base) {
	// 0x36A1E6: mov eax, [ecx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x36A1E9: mov edx, 0x80000
	ctx.edx = 524288;
	// 0x36A1EE: test edx, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.eax, 32);
	// 0x36A1F0: jnz 0x0036A1FF
	if (!ctx.flags.zf) goto loc_36A1FF;
	// 0x36A1F2: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A1F3: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A1F5: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A1F7: mov [ecx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, ctx.eax);
	// 0x36A1FA: call 0x0036A114
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A114(ctx, base);
	ctx.esp += 4;
loc_36A1FF:
	// 0x36A1FF: ret
	return;
}

void sub_36A200(X86Context& ctx, uint8_t* base) {
	// 0x36A200: mov ecx, [esp+0x04]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x36A204: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A205: call 0x00364DEC
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364DEC(ctx, base);
	ctx.esp += 4;
	// 0x36A20A: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x36A20C: mov ecx, [esi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36A20F: test ecx, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ecx & ctx.ecx, 32);
	// 0x36A211: jz 0x0036A227
	if (ctx.flags.zf) goto loc_36A227;
	// 0x36A213: mov eax, [ecx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x36A216: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x36A218: jnz 0x0036A227
	if (!ctx.flags.zf) goto loc_36A227;
	// 0x36A21A: or eax, 0x02
	ctx.eax = ctx.eax | 2;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A21D: mov [ecx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, ctx.eax);
	// 0x36A220: call 0x0036A1E6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A1E6(ctx, base);
	ctx.esp += 4;
	// 0x36A225: jmp 0x0036A231
	goto loc_36A231;
loc_36A227:
	// 0x36A227: mov ecx, [esi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi);
	// 0x36A229: call 0x0036577A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36577A(ctx, base);
	ctx.esp += 4;
	// 0x36A22E: and dword ptr [esi], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi, X86_MEM_READ_u32(base, ctx.esi) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi), 32);
loc_36A231:
	// 0x36A231: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A232: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_36A235(X86Context& ctx, uint8_t* base) {
	// 0x36A235: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A236: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A238: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A23B: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36A23E: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A23F: lea eax, [eax+ecx*2]
	ctx.eax = ctx.eax + ctx.ecx * 2;
	// 0x36A242: mov ecx, [0x004205DC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x4205DCu);
	// 0x36A248: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A249: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x36A24C: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A24D: lea edi, [ecx+eax*4]
	ctx.edi = ctx.ecx + ctx.eax * 4;
	// 0x36A250: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A256: mov esi, [edi+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x36A259: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A25B: cmp [esi+0x08], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x8u); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A25E: mov cl, al
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.eax);
	// 0x36A260: mov [ebp+0x0F], cl
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xFu, X86_REG8L(ctx.ecx));
	// 0x36A263: jz 0x0036A28C
	if (ctx.flags.zf) goto loc_36A28C;
	// 0x36A265: or dword ptr [esi+0x0C], 0x01
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x36A269: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36A26B: call 0x0036A1E6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A1E6(ctx, base);
	ctx.esp += 4;
	// 0x36A270: mov cl, [ebp+0x0F]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp + 0xFu);
	// 0x36A273: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A279: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A27A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A27B: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A27C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A27D: lea eax, [esi+0x12C]
	ctx.eax = ctx.esi + 0x12Cu;
	// 0x36A283: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A284: call [0x0036B8EC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8ECu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A28A: jmp 0x0036A295
	goto loc_36A295;
loc_36A28C:
	// 0x36A28C: mov [edi+0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.ebx);
	// 0x36A28F: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36A295:
	// 0x36A295: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A296: call 0x0036A039
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A039(ctx, base);
	ctx.esp += 4;
	// 0x36A29B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A29C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A29D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A29E: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A29F: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36A2A2(X86Context& ctx, uint8_t* base) {
	// 0x36A2A2: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2A3: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A2A5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2A6: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2A7: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A2AA: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36A2AD: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2AE: lea eax, [eax+ecx*2]
	ctx.eax = ctx.eax + ctx.ecx * 2;
	// 0x36A2B1: mov ecx, [0x004205DC]
	ctx.ecx = X86_MEM_READ_u32(base, 0x4205DCu);
	// 0x36A2B7: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2B8: lea eax, [eax+eax*2]
	ctx.eax = ctx.eax + ctx.eax * 2;
	// 0x36A2BB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2BC: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A2BE: mov [ebp-0x08], ebx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ebx);
	// 0x36A2C1: lea edi, [ecx+eax*4]
	ctx.edi = ctx.ecx + ctx.eax * 4;
	// 0x36A2C4: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A2CA: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x36A2CD: call 0x0036A01E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A01E(ctx, base);
	ctx.esp += 4;
	// 0x36A2D2: mov esi, eax
	ctx.esi = ctx.eax;
	// 0x36A2D4: cmp esi, ebx
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A2D6: jnz 0x0036A2DF
	if (!ctx.flags.zf) goto loc_36A2DF;
	// 0x36A2D8: mov esi, 0xC0000017
	ctx.esi = -1073741801;
	// 0x36A2DD: jmp 0x0036A2EE
	goto loc_36A2EE;
loc_36A2DF:
	// 0x36A2DF: cmp [edi], ebx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A2E1: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A2E2: jnz 0x0036A2FE
	if (!ctx.flags.zf) goto loc_36A2FE;
	// 0x36A2E4: call 0x0036A039
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A039(ctx, base);
	ctx.esp += 4;
	// 0x36A2E9: mov esi, 0xC000009D
	ctx.esi = -1073741667;
loc_36A2EE:
	// 0x36A2EE: mov cl, [ebp-0x01]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x36A2F1: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A2F7: mov eax, esi
	ctx.eax = ctx.esi;
	// 0x36A2F9: jmp 0x0036A44F
	goto loc_36A44F;
loc_36A2FE:
	// 0x36A2FE: push 0x36B021
	{ auto _pv = (uint32_t)(3584033); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A303: lea eax, [esi+0x98]
	ctx.eax = ctx.esi + 0x98u;
	// 0x36A309: mov [edi+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.esi);
	// 0x36A30C: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A30D: mov [esi+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, ctx.edi);
	// 0x36A310: call [0x0036B8F0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8F0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A316: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A317: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36A31A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A31B: call [0x0036B8DC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8DCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A321: and dword ptr [esi+0xC0], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, X86_MEM_READ_u32(base, ctx.esi + 0xC0u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xC0u), 32);
	// 0x36A328: mov [esi+0x130], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x130u, ctx.ebx);
	// 0x36A32E: lea eax, [esi+0x134]
	ctx.eax = ctx.esi + 0x134u;
	// 0x36A334: lea ebx, [esi+0xB8]
	ctx.ebx = ctx.esi + 0xB8u;
	// 0x36A33A: mov byte ptr [esi+0x12C], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0x12Cu, 0);
	// 0x36A341: mov byte ptr [esi+0x12E], 0x04
	X86_MEM_WRITE_u8(base, ctx.esi + 0x12Eu, 4);
	// 0x36A348: mov [esi+0x138], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x138u, ctx.eax);
	// 0x36A34E: mov [eax], eax
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.eax);
	// 0x36A350: mov byte ptr [ebx], 0x20
	X86_MEM_WRITE_u8(base, ctx.ebx, 32);
	// 0x36A353: mov byte ptr [esi+0xB9], 0x82
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, -126);
	// 0x36A35A: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36A35C: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A35D: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36A362: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36A364: jl 0x0036A404
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36A404;
	// 0x36A36A: or byte ptr [esi+0x0E], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0xEu, X86_MEM_READ_u8(base, ctx.esi + 0xEu) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xEu), 8);
	// 0x36A36E: and dword ptr [esi+0xC0], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, X86_MEM_READ_u32(base, ctx.esi + 0xC0u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xC0u), 32);
	// 0x36A375: mov byte ptr [ebx], 0x20
	X86_MEM_WRITE_u8(base, ctx.ebx, 32);
	// 0x36A378: mov byte ptr [esi+0xB9], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 2);
	// 0x36A37F: mov al, [edi+0x05]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0x5u);
	// 0x36A382: mov [esi+0xCD], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0xCDu, X86_REG8L(ctx.eax));
	// 0x36A388: mov byte ptr [esi+0xCE], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xCEu, 2);
	// 0x36A38F: mov byte ptr [esi+0xCF], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xCFu, 0);
	// 0x36A396: mov word ptr [esi+0xD4], 0x40
	X86_MEM_WRITE_u16(base, ctx.esi + 0xD4u, 64);
	// 0x36A39F: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36A3A1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A3A2: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36A3A7: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36A3A9: jl 0x0036A404
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36A404;
	// 0x36A3AB: mov eax, [esi+0xC8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xC8u);
	// 0x36A3B1: or byte ptr [esi+0x0E], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xEu, X86_MEM_READ_u8(base, ctx.esi + 0xEu) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xEu), 8);
	// 0x36A3B5: and dword ptr [esi+0xC0], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, X86_MEM_READ_u32(base, ctx.esi + 0xC0u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xC0u), 32);
	// 0x36A3BC: mov [esi+0x20], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x20u, ctx.eax);
	// 0x36A3BF: mov byte ptr [ebx], 0x20
	X86_MEM_WRITE_u8(base, ctx.ebx, 32);
	// 0x36A3C2: mov byte ptr [esi+0xB9], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 2);
	// 0x36A3C9: mov al, [edi+0x06]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0x6u);
	// 0x36A3CC: mov [esi+0xCD], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0xCDu, X86_REG8L(ctx.eax));
	// 0x36A3D2: mov byte ptr [esi+0xCE], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xCEu, 2);
	// 0x36A3D9: mov byte ptr [esi+0xCF], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xCFu, 0);
	// 0x36A3E0: mov word ptr [esi+0xD4], 0x40
	X86_MEM_WRITE_u16(base, ctx.esi + 0xD4u, 64);
	// 0x36A3E9: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36A3EB: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A3EC: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36A3F1: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36A3F3: jl 0x0036A404
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36A404;
	// 0x36A3F5: mov eax, [esi+0xC8]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xC8u);
	// 0x36A3FB: or byte ptr [esi+0x0E], 0x04
	X86_MEM_WRITE_u8(base, ctx.esi + 0xEu, X86_MEM_READ_u8(base, ctx.esi + 0xEu) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xEu), 8);
	// 0x36A3FF: mov [esi+0x24], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x24u, ctx.eax);
	// 0x36A402: jmp 0x0036A40D
	goto loc_36A40D;
loc_36A404:
	// 0x36A404: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A405: call 0x00364E79
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364E79(ctx, base);
	ctx.esp += 4;
	// 0x36A40A: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
loc_36A40D:
	// 0x36A40D: mov cl, [ebp-0x01]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x36A410: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A416: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x36A419: mov eax, 0xC0000000
	ctx.eax = -1073741824;
	// 0x36A41E: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36A420: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A422: jnz 0x0036A431
	if (!ctx.flags.zf) goto loc_36A431;
	// 0x36A424: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A427: push [ebp+0x08]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0x8u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A42A: call 0x0036A235
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A235(ctx, base);
	ctx.esp += 4;
	// 0x36A42F: jmp 0x0036A44C
	goto loc_36A44C;
loc_36A431:
	// 0x36A431: mov eax, [ebp+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x10u);
	// 0x36A434: mov word ptr [eax], 0x0C
	X86_MEM_WRITE_u16(base, ctx.eax, 12);
	// 0x36A439: push [esi+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A43C: push 0x36B784
	{ auto _pv = (uint32_t)(3585924); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A441: push [eax+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A444: call 0x00243215
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	_sprintf(ctx, base);
	ctx.esp += 4;
	// 0x36A449: add esp, 0x0C
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.esp) + (uint64_t)(uint32_t)(12);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.esp, (int32_t)12, 32);
	  ctx.esp = (uint32_t)_res; }
loc_36A44C:
	// 0x36A44C: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
loc_36A44F:
	// 0x36A44F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A450: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A451: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A452: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A453: ret 0x0C
	ctx.esp += 12;
	return;
}

void sub_36A456(X86Context& ctx, uint8_t* base) {
	// 0x36A456: mov eax, [0x0036B9F8]
	ctx.eax = X86_MEM_READ_u32(base, 0x36B9F8u);
	// 0x36A45B: mov [0x00362D2C], eax
	X86_MEM_WRITE_u32(base, 0x362D2Cu, ctx.eax);
	// 0x36A460: mov [0x00362D30], eax
	X86_MEM_WRITE_u32(base, 0x362D30u, ctx.eax);
	// 0x36A465: mov [0x00362D3C], eax
	X86_MEM_WRITE_u32(base, 0x362D3Cu, ctx.eax);
	// 0x36A46A: mov [0x00362D40], eax
	X86_MEM_WRITE_u32(base, 0x362D40u, ctx.eax);
	// 0x36A46F: mov [0x00362D44], eax
	X86_MEM_WRITE_u32(base, 0x362D44u, ctx.eax);
	// 0x36A474: mov [0x00362D48], eax
	X86_MEM_WRITE_u32(base, 0x362D48u, ctx.eax);
	// 0x36A479: mov [0x00362D4C], eax
	X86_MEM_WRITE_u32(base, 0x362D4Cu, ctx.eax);
	// 0x36A47E: mov [0x00362D50], eax
	X86_MEM_WRITE_u32(base, 0x362D50u, ctx.eax);
	// 0x36A483: mov [0x00362D5C], eax
	X86_MEM_WRITE_u32(base, 0x362D5Cu, ctx.eax);
	// 0x36A488: mov [0x00362D60], eax
	X86_MEM_WRITE_u32(base, 0x362D60u, ctx.eax);
	// 0x36A48D: ret
	return;
}

void sub_36A48E(X86Context& ctx, uint8_t* base) {
	// 0x36A48E: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A48F: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A491: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A492: mov al, [ebp+0x0B]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp + 0xBu);
	// 0x36A495: mov [ebp-0x04], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x4u, X86_REG8L(ctx.eax));
	// 0x36A498: mov al, [ebp+0x0A]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp + 0xAu);
	// 0x36A49B: mov [ebp-0x03], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x3u, X86_REG8L(ctx.eax));
	// 0x36A49E: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A4A1: mov [ebp-0x02], ah
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x2u, X86_REG8H(ctx.eax));
	// 0x36A4A4: mov [ebp-0x01], al
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.eax));
	// 0x36A4A7: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36A4AA: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A4AB: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_36A4AE(X86Context& ctx, uint8_t* base) {
	// 0x36A4AE: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4AF: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A4B1: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4B2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4B3: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4B4: mov edi, [ebp+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A4B7: mov esi, [edi+0x18]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi + 0x18u);
	// 0x36A4BA: mov ebx, 0x103
	ctx.ebx = 259;
	// 0x36A4BF: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A4C5: test byte ptr [esi+0x0C], 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 6, 8);
	// 0x36A4C9: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36A4CC: mov [ebp+0x0B], al
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xBu, X86_REG8L(ctx.eax));
	// 0x36A4CF: jz 0x0036A4E5
	if (ctx.flags.zf) goto loc_36A4E5;
	// 0x36A4D1: mov eax, 0xC000009D
	ctx.eax = -1073741667;
	// 0x36A4D6: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36A4D8: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x36A4DA: mov [ecx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.eax);
	// 0x36A4DD: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A4E3: jmp 0x0036A4F6
	goto loc_36A4F6;
loc_36A4E5:
	// 0x36A4E5: mov eax, [ecx+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x5Cu);
	// 0x36A4E8: or byte ptr [eax+0x03], 0x01
	X86_MEM_WRITE_u8(base, ctx.eax + 0x3u, X86_MEM_READ_u8(base, ctx.eax + 0x3u) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.eax + 0x3u), 8);
	// 0x36A4EC: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4EE: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4EF: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A4F0: call [0x0036B9FC]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9FCu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36A4F6:
	// 0x36A4F6: mov cl, [ebp+0x0B]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.ebp + 0xBu);
	// 0x36A4F9: call [0x0036B8B4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A4FF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A500: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A501: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x36A503: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A504: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A505: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36A508(X86Context& ctx, uint8_t* base) {
	// 0x36A508: mov eax, [esp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x36A50C: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A50D: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x36A511: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36A514: mov [ecx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.eax);
	// 0x36A517: mov ecx, 0xC0000000
	ctx.ecx = -1073741824;
	// 0x36A51C: and eax, ecx
	ctx.eax = ctx.eax & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A51E: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A520: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36A523: jnz 0x0036A52B
	if (!ctx.flags.zf) goto loc_36A52B;
	// 0x36A525: and dword ptr [eax+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, X86_MEM_READ_u32(base, ctx.eax + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x14u), 32);
	// 0x36A529: jmp 0x0036A531
	goto loc_36A531;
loc_36A52B:
	// 0x36A52B: mov ecx, [esi+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x36A52E: mov [eax+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, ctx.ecx);
loc_36A531:
	// 0x36A531: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36A534: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36A536: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A53C: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A53E: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A544: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A545: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36A548(X86Context& ctx, uint8_t* base) {
	// 0x36A548: mov eax, [0x0041D5D4]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5D4u);
	// 0x36A54D: cmp eax, 0x41D5D4
	{ uint32_t _d = ctx.eax; uint32_t _s = 4314580;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A552: jz 0x0036A563
	if (ctx.flags.zf) goto loc_36A563;
	// 0x36A554: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x36A557: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x36A55A: mov eax, [eax+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x36A55D: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A55F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A560: call [eax+0x30]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36A563:
	// 0x36A563: ret
	return;
}

void sub_36A564(X86Context& ctx, uint8_t* base) {
	// 0x36A564: mov eax, ecx
	ctx.eax = ctx.ecx;
	// 0x36A566: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A568: cmp [eax+0x04], edx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x4u); uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A56B: jbe 0x0036A58A
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_36A58A;
	// 0x36A56D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A56E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_36A56F:
	// 0x36A56F: mov edi, [eax]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36A571: add edi, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)ctx.edx, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x36A573: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A575: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A576: mov esi, 0x36B794
	ctx.esi = 3585940;
	// 0x36A57B: add edx, 0x1000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(4096);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)4096, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x36A581: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x36A583: cmp edx, [eax+0x04]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A586: jb 0x0036A56F
	if (ctx.flags.cf) goto loc_36A56F;
	// 0x36A588: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A589: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_36A58A:
	// 0x36A58A: ret
	return;
}

void sub_36A58B(X86Context& ctx, uint8_t* base) {
	// 0x36A58B: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x36A58F: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A592: jbe 0x0036A5A0
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_36A5A0;
	// 0x36A594: lea ecx, [eax-0x01]
	ctx.ecx = ctx.eax - 0x1u;
	// 0x36A597: test eax, ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.ecx, 32);
	// 0x36A599: jnz 0x0036A5A0
	if (!ctx.flags.zf) goto loc_36A5A0;
	// 0x36A59B: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A59D: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36A59E: jmp 0x0036A5A2
	goto loc_36A5A2;
loc_36A5A0:
	// 0x36A5A0: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_36A5A2:
	// 0x36A5A2: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_36A5A5(X86Context& ctx, uint8_t* base) {
	// 0x36A5A5: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A5A7: xor al, al
	X86_REG8L(ctx.eax) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36A5A9: inc ecx
	{ uint32_t _d = ctx.ecx;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.ecx = (uint32_t)_res; }
loc_36A5AA:
	// 0x36A5AA: test [esp+0x04], ecx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) X86_MEM_READ_u32(base, ctx.esp + 0x4u) & ctx.ecx, 32);
	// 0x36A5AE: jnz 0x0036A5B8
	if (!ctx.flags.zf) goto loc_36A5B8;
	// 0x36A5B0: inc al
	{ uint8_t _d = X86_REG8L(ctx.eax);
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.eax) = (uint8_t)_res; }
	// 0x36A5B2: shl ecx, 0x01
	{ auto _cnt = 0x1u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ecx >> (32 - _cnt)) & 1;
	  ctx.ecx = ctx.ecx << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32); } }
	// 0x36A5B4: cmp al, 0x20
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 32;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x36A5B6: jb 0x0036A5AA
	if (ctx.flags.cf) goto loc_36A5AA;
loc_36A5B8:
	// 0x36A5B8: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_36A5BB(X86Context& ctx, uint8_t* base) {
	// 0x36A5BB: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A5BC: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A5BE: sub esp, 0x14
	{ uint32_t _d = ctx.esp; uint32_t _s = 20;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x36A5C1: mov edx, [ebp+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36A5C4: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A5C5: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A5C8: mov ecx, [ebx+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A5CB: mov eax, [ecx+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x5Cu);
	// 0x36A5CE: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A5CF: mov [ebp-0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.eax);
	// 0x36A5D2: mov eax, 0xC0000000
	ctx.eax = -1073741824;
	// 0x36A5D7: mov esi, edx
	ctx.esi = ctx.edx;
	// 0x36A5D9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A5DA: mov edi, [ebx+0x28]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebx + 0x28u);
	// 0x36A5DD: and esi, eax
	ctx.esi = ctx.esi & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x36A5DF: cmp esi, eax
	{ uint32_t _d = ctx.esi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A5E1: mov [ebp-0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.edi);
	// 0x36A5E4: mov [ebp-0x04], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.ecx);
	// 0x36A5E7: jnz 0x0036A5F8
	if (!ctx.flags.zf) goto loc_36A5F8;
	// 0x36A5E9: and dword ptr [ecx+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, X86_MEM_READ_u32(base, ctx.ecx + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0x14u), 32);
	// 0x36A5ED: mov eax, [ebx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A5F0: mov [eax+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, ctx.edx);
	// 0x36A5F3: jmp 0x0036A76D
	goto loc_36A76D;
loc_36A5F8:
	// 0x36A5F8: mov ax, [edi+0x06]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi + 0x6u);
	// 0x36A5FC: push [edi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.edi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A5FE: mov [ebp+0x0A], ah
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xAu, X86_REG8H(ctx.eax));
	// 0x36A601: mov [ebp+0x0B], al
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xBu, X86_REG8L(ctx.eax));
	// 0x36A604: mov ax, [edi+0x04]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.edi + 0x4u);
	// 0x36A608: movzx ecx, word ptr [ebp+0x0A]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp + 0xAu));
	// 0x36A60C: mov [ebp+0x0E], ah
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xEu, X86_REG8H(ctx.eax));
	// 0x36A60F: mov [ebp+0x0F], al
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xFu, X86_REG8L(ctx.eax));
	// 0x36A612: movzx esi, word ptr [ebp+0x0E]
	ctx.esi = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp + 0xEu));
	// 0x36A616: imul esi, ecx
	{ int64_t _res = (int64_t)(int32_t)ctx.esi * (int64_t)(int32_t)ctx.ecx;
	  ctx.esi = (uint32_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int32_t)_res); }
	// 0x36A619: call 0x0036A48E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A48E(ctx, base);
	ctx.esp += 4;
	// 0x36A61E: movzx ecx, word ptr [ebp+0x0A]
	ctx.ecx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp + 0xAu));
	// 0x36A622: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36A623: mov [ebp+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, ctx.eax);
	// 0x36A626: mul ecx
	{ uint64_t _res = (uint64_t)ctx.eax * (uint64_t)ctx.ecx;
	  ctx.eax = (uint32_t)_res; ctx.edx = (uint32_t)(_res >> 32);
	  ctx.flags.cf = ctx.flags.of = (ctx.edx != 0); }
	// 0x36A628: test esi, esi
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.esi & ctx.esi, 32);
	// 0x36A62A: mov [ebp-0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x14u, ctx.eax);
	// 0x36A62D: mov [ebp-0x10], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x10u, ctx.edx);
	// 0x36A630: jnz 0x0036A637
	if (!ctx.flags.zf) goto loc_36A637;
	// 0x36A632: mov esi, 0x2000
	ctx.esi = 8192;
loc_36A637:
	// 0x36A637: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A638: call 0x0036A58B
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A58B(ctx, base);
	ctx.esp += 4;
	// 0x36A63D: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36A63F: jz 0x0036A78E
	if (ctx.flags.zf) goto loc_36A78E;
	// 0x36A645: movzx edx, word ptr [ebp+0x0A]
	ctx.edx = (uint32_t)(X86_MEM_READ_u16(base, ctx.ebp + 0xAu));
	// 0x36A649: cmp edx, 0x1000
	{ uint32_t _d = ctx.edx; uint32_t _s = 4096;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A64F: jnbe 0x0036A78E
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_36A78E;
	// 0x36A655: cmp esi, 0x4000
	{ uint32_t _d = ctx.esi; uint32_t _s = 16384;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A65B: jnbe 0x0036A78E
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_36A78E;
	// 0x36A661: test si, 0xFFF
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint16_t) X86_REG16(ctx.esi) & 4095, 16);
	// 0x36A666: jnz 0x0036A78E
	if (!ctx.flags.zf) goto loc_36A78E;
	// 0x36A66C: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A66E: cmp [ebp+0x0C], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A671: jz 0x0036A78E
	if (ctx.flags.zf) goto loc_36A78E;
	// 0x36A677: mov eax, [ebp-0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x10u);
	// 0x36A67A: cmp eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A67C: jb 0x0036A78E
	if (ctx.flags.cf) goto loc_36A78E;
	// 0x36A682: jnbe 0x0036A68D
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_36A68D;
	// 0x36A684: cmp [ebp-0x14], esi
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u); uint32_t _s = ctx.esi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A687: jb 0x0036A78E
	if (ctx.flags.cf) goto loc_36A78E;
loc_36A68D:
	// 0x36A68D: cmp eax, 0x01
	{ uint32_t _d = ctx.eax; uint32_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A690: jnbe 0x0036A78E
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_36A78E;
	// 0x36A696: jb 0x0036A6A2
	if (ctx.flags.cf) goto loc_36A6A2;
	// 0x36A698: cmp dword ptr [ebp-0x14], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x14u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A69C: jnbe 0x0036A78E
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_36A78E;
loc_36A6A2:
	// 0x36A6A2: mov ecx, [ebp-0x14]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x14u);
	// 0x36A6A5: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A6A6: mov [ebx+0x160], ecx
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x160u, ctx.ecx);
	// 0x36A6AC: mov [ebx+0x164], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x164u, ctx.eax);
	// 0x36A6B2: mov [ebx+0x168], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x168u, ctx.esi);
	// 0x36A6B8: call 0x0036A5A5
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A5A5(ctx, base);
	ctx.esp += 4;
	// 0x36A6BD: movzx eax, al
	ctx.eax = (uint32_t)(X86_REG8L(ctx.eax));
	// 0x36A6C0: mov [ebx+0x158], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x158u, ctx.eax);
	// 0x36A6C6: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A6C8: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A6C9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A6CA: push [ebp-0x10]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x10u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A6CD: mov dword ptr [ebx+0x148], 0x0C
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x148u, 12);
	// 0x36A6D7: push [ebp-0x14]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x14u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A6DA: lea edi, [ebx+0x140]
	ctx.edi = ctx.ebx + 0x140u;
	// 0x36A6E0: call 0x00244CA0
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244CA0(ctx, base);
	ctx.esp += 4;
	// 0x36A6E5: mov [edi], eax
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	// 0x36A6E7: mov eax, [ebp-0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x36A6EA: shr esi, 0x0C
	{ auto _cnt = 0xCu & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.esi >> (_cnt - 1)) & 1;
	  ctx.esi = (uint32_t)(ctx.esi) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32); } }
	// 0x36A6ED: mov [edi+0x04], edx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.edx);
	// 0x36A6F0: mov dword ptr [ebx+0x14C], 0x01
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x14Cu, 1);
	// 0x36A6FA: mov [ebx+0x150], esi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x150u, ctx.esi);
	// 0x36A700: mov dword ptr [ebx+0x154], 0x1000
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x154u, 4096);
	// 0x36A70A: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x36A70D: cmp eax, 0x70000
	{ uint32_t _d = ctx.eax; uint32_t _s = 458752;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A712: jz 0x0036A74C
	if (ctx.flags.zf) goto loc_36A74C;
	// 0x36A714: cmp eax, 0x74004
	{ uint32_t _d = ctx.eax; uint32_t _s = 475140;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A719: jnz 0x0036A76A
	if (!ctx.flags.zf) goto loc_36A76A;
	// 0x36A71B: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36A71E: mov edx, [eax+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	// 0x36A721: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A723: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A725: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A726: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x36A728: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x36A72A: mov eax, [ebx+0x160]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x160u);
	// 0x36A730: mov [edx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.eax);
	// 0x36A733: mov eax, [ebx+0x164]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x164u);
	// 0x36A739: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
	// 0x36A73C: mov byte ptr [edx+0x1A], 0x01
	X86_MEM_WRITE_u8(base, ctx.edx + 0x1Au, 1);
	// 0x36A740: mov eax, [ebx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A743: mov dword ptr [eax+0x14], 0x20
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, 32);
	// 0x36A74A: jmp 0x0036A763
	goto loc_36A763;
loc_36A74C:
	// 0x36A74C: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36A74F: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A751: mov esi, edi
	ctx.esi = ctx.edi;
	// 0x36A753: mov edi, [eax+0x30]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	// 0x36A756: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A757: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x36A759: mov eax, [ebx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A75C: mov dword ptr [eax+0x14], 0x18
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, 24);
loc_36A763:
	// 0x36A763: mov eax, [ebx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A766: and dword ptr [eax+0x10], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, X86_MEM_READ_u32(base, ctx.eax + 0x10u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x10u), 32);
loc_36A76A:
	// 0x36A76A: mov edi, [ebp-0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
loc_36A76D:
	// 0x36A76D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A76E: call [0x0036B928]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B928u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A774: mov ecx, [ebx+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A777: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36A779: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A77F: push [ebx]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebx)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A781: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A787: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A788: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A789: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A78A: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A78B: ret 0x08
	ctx.esp += 8;
	return;
loc_36A78E:
	// 0x36A78E: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36A791: and dword ptr [eax+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, X86_MEM_READ_u32(base, ctx.eax + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x14u), 32);
	// 0x36A795: mov eax, [ebx+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x10u);
	// 0x36A798: mov dword ptr [eax+0x10], 0xC000014F
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, -1073741489);
	// 0x36A79F: jmp 0x0036A76D
	goto loc_36A76D;
}

void sub_36A7A1(X86Context& ctx, uint8_t* base) {
	// 0x36A7A1: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A7A2: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A7A4: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A7A5: mov eax, [edx+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x5Cu);
	// 0x36A7A8: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A7A9: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A7AA: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36A7AC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A7AD: mov edi, [eax+0x08]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x36A7B0: mov byte ptr [esi+0x4F], 0x2F
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 47);
	// 0x36A7B4: mov ecx, [esi+0x158]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x158u);
	// 0x36A7BA: mov eax, [edi]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36A7BC: mov edx, [edi+0x04]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x36A7BF: call 0x00257470
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_257470(ctx, base);
	ctx.esp += 4;
	// 0x36A7C4: mov ecx, [esi+0x158]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x158u);
	// 0x36A7CA: mov ebx, [edi+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x36A7CD: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x36A7CF: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A7D1: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x36A7D4: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36A7D7: mov dword ptr [esi+0x30], 0x36A508
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3581192);
	// 0x36A7DE: shr ebx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)(ctx.ebx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x36A7E0: mov cx, [edi+0x0A]
	X86_REG16(ctx.ecx) = X86_MEM_READ_u16(base, ctx.edi + 0xAu);
	// 0x36A7E4: imul cx, cx, 0x64
	{ int64_t _res = (int64_t)(int16_t)X86_REG16(ctx.ecx) * (int64_t)(int16_t)100;
	  X86_REG16(ctx.ecx) = (uint16_t)_res;
	  ctx.flags.cf = ctx.flags.of = (_res != (int16_t)_res); }
	// 0x36A7E8: mov [esi+0x34], cx
	X86_MEM_WRITE_u16(base, ctx.esi + 0x34u, X86_REG16(ctx.ecx));
	// 0x36A7EC: lea ecx, [esi+0x4F]
	ctx.ecx = ctx.esi + 0x4Fu;
	// 0x36A7EF: mov [esi+0x37], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, X86_REG8L(ctx.eax));
	// 0x36A7F2: mov byte ptr [esi+0x36], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0x36u, 2);
	// 0x36A7F6: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x36A7F8: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36A7F9: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36A7FA: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36A7FB: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36A7FC: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A7FD: mov byte ptr [ecx], 0x2F
	X86_MEM_WRITE_u8(base, ctx.ecx, 47);
	// 0x36A800: call 0x0036A48E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A48E(ctx, base);
	ctx.esp += 4;
	// 0x36A805: mov [esi+0x51], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x51u, ctx.eax);
	// 0x36A808: mov [ebp-0x04], bh
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x4u, X86_REG8H(ctx.ebx));
	// 0x36A80B: mov [ebp-0x03], bl
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x3u, X86_REG8L(ctx.ebx));
	// 0x36A80E: mov ax, [ebp-0x04]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp - 0x4u);
	// 0x36A812: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36A814: mov [esi+0x56], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x56u, X86_REG16(ctx.eax));
	// 0x36A818: call 0x0036B743
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B743(ctx, base);
	ctx.esp += 4;
	// 0x36A81D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A81E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A81F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A820: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A821: ret
	return;
}

void sub_36A822(X86Context& ctx, uint8_t* base) {
	// 0x36A822: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A823: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A825: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x36A828: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A82B: mov ecx, [eax+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x2Cu);
	// 0x36A82E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A82F: mov edi, [eax+0x28]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	// 0x36A832: add ecx, edi
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ecx) + (uint64_t)(uint32_t)(ctx.edi);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ecx, (int32_t)ctx.edi, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x36A834: cmp edi, ecx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A836: mov [ebp-0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.ecx);
	// 0x36A839: jnb 0x0036A8E2
	if (!ctx.flags.cf) goto loc_36A8E2;
	// 0x36A83F: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x36A841: sub edx, 0x36B794
	{ uint32_t _d = ctx.edx; uint32_t _s = 3585940;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x36A847: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A848: mov [ebp-0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edx);
	// 0x36A84B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_36A84C:
	// 0x36A84C: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36A84E: cmp dword ptr [edi], 0x46313539
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edi); uint32_t _s = 1177630009;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A854: jnz 0x0036A8C6
	if (!ctx.flags.zf) goto loc_36A8C6;
loc_36A856:
	// 0x36A856: inc eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d + 1;
	  X86_UPDATE_FLAGS_INC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36A857: cmp eax, 0x08
	{ uint32_t _d = ctx.eax; uint32_t _s = 8;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A85A: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x36A85D: jz 0x0036A871
	if (ctx.flags.zf) goto loc_36A871;
	// 0x36A85F: mov esi, [edx+eax*4+0x36B794]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edx + ctx.eax * 4 + 0x36B794u);
	// 0x36A866: cmp esi, [eax*4+0x36B794]
	{ uint32_t _d = ctx.esi; uint32_t _s = X86_MEM_READ_u32(base, ctx.eax * 4 + 0x36B794u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A86D: jz 0x0036A856
	if (ctx.flags.zf) goto loc_36A856;
	// 0x36A86F: jmp 0x0036A8C6
	goto loc_36A8C6;
loc_36A871:
	// 0x36A871: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A872: call [0x0036B824]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B824u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A878: or esi, 0xFFFFFFFF
	ctx.esi = ctx.esi | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x36A87B: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A87F: mov ebx, eax
	ctx.ebx = ctx.eax;
	// 0x36A881: jl 0x0036A88A
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36A88A;
	// 0x36A883: mov dword ptr [ebp+0x0C], 0xC000003E
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, -1073741762);
loc_36A88A:
	// 0x36A88A: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x36A88C: and eax, 0x06
	ctx.eax = ctx.eax & 6;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A88F: cmp al, 0x02
	{ uint8_t _d = X86_REG8L(ctx.eax); uint8_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x36A891: jnz 0x0036A8A5
	if (!ctx.flags.zf) goto loc_36A8A5;
	// 0x36A893: mov esi, ebx
	ctx.esi = ctx.ebx;
	// 0x36A895: and esi, 0xFFFFFFFD
	ctx.esi = ctx.esi & -3;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x36A898: or esi, 0x04
	ctx.esi = ctx.esi | 4;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esi, 32);
	// 0x36A89B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A89C: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A89E: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A89F: call [0x0036B81C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B81Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36A8A5:
	// 0x36A8A5: dec [ebp-0x04]
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x36A8A8: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36A8AB: mov dword ptr [edi+eax*4], 0x4C494146
	X86_MEM_WRITE_u32(base, ctx.edi + ctx.eax * 4, 1279869254);
	// 0x36A8B2: jnz 0x0036A8A5
	if (!ctx.flags.zf) goto loc_36A8A5;
	// 0x36A8B4: cmp esi, 0xFFFFFFFF
	{ uint32_t _d = ctx.esi; uint32_t _s = -1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A8B7: jz 0x0036A8C3
	if (ctx.flags.zf) goto loc_36A8C3;
	// 0x36A8B9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8BA: push 0x20
	{ auto _pv = (uint32_t)(32); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8BC: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8BD: call [0x0036B81C]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B81Cu);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36A8C3:
	// 0x36A8C3: mov ecx, [ebp-0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
loc_36A8C6:
	// 0x36A8C6: mov edx, [ebp-0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x36A8C9: mov eax, 0x1000
	ctx.eax = 4096;
	// 0x36A8CE: add edi, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)ctx.eax, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x36A8D0: add edx, eax
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.eax, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x36A8D2: cmp edi, ecx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A8D4: mov [ebp-0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edx);
	// 0x36A8D7: jb 0x0036A84C
	if (ctx.flags.cf) goto loc_36A84C;
	// 0x36A8DD: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A8E0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A8E1: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_36A8E2:
	// 0x36A8E2: push [ebp+0x0C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebp + 0xCu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8E5: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8E6: call 0x0036A508
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A508(ctx, base);
	ctx.esp += 4;
	// 0x36A8EB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A8EC: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36A8ED: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36A8F0(X86Context& ctx, uint8_t* base) {
	// 0x36A8F0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8F1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36A8F3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8F4: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A8F5: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A8F8: mov ebx, [esi+0x0C]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36A8FB: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36A8FE: and ebx, 0xF0000000
	ctx.ebx = ctx.ebx & -268435456;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32);
	// 0x36A904: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A908: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A909: mov edi, [ecx+0x5C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ecx + 0x5Cu);
	// 0x36A90C: mov [ebp+0x08], ecx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.ecx);
	// 0x36A90F: jl 0x0036A9C6
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36A9C6;
	// 0x36A915: add ebx, 0x10000000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(268435456);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)268435456, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x36A91B: cmp ebx, 0x20000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 536870912;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A921: jnz 0x0036A92E
	if (!ctx.flags.zf) goto loc_36A92E;
	// 0x36A923: test byte ptr [esi+0x0F], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xFu) & 2, 8);
	// 0x36A927: jnz 0x0036A941
	if (!ctx.flags.zf) goto loc_36A941;
	// 0x36A929: mov ebx, 0x40000000
	ctx.ebx = 1073741824;
loc_36A92E:
	// 0x36A92E: cmp ebx, 0x40000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 1073741824;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A934: jnz 0x0036A941
	if (!ctx.flags.zf) goto loc_36A941;
	// 0x36A936: test byte ptr [esi+0x0F], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xFu) & 4, 8);
	// 0x36A93A: jnz 0x0036A941
	if (!ctx.flags.zf) goto loc_36A941;
loc_36A93C:
	// 0x36A93C: mov ebx, 0x60000000
	ctx.ebx = 1610612736;
loc_36A941:
	// 0x36A941: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36A944: mov edx, 0xFFFFFFF
	ctx.edx = 268435455;
	// 0x36A949: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A94B: or eax, ebx
	ctx.eax = ctx.eax | ctx.ebx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A94D: cmp ebx, 0x20000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 536870912;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A953: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36A956: jz 0x0036AA7F
	if (ctx.flags.zf) goto loc_36AA7F;
	// 0x36A95C: cmp ebx, 0x30000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 805306368;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A962: jz 0x0036AA53
	if (ctx.flags.zf) goto loc_36AA53;
	// 0x36A968: cmp ebx, 0x40000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 1073741824;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A96E: jz 0x0036AA33
	if (ctx.flags.zf) goto loc_36AA33;
	// 0x36A974: cmp ebx, 0x50000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 1342177280;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A97A: jz 0x0036AA01
	if (ctx.flags.zf) goto loc_36AA01;
	// 0x36A980: cmp ebx, 0x60000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 1610612736;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A986: jnz 0x0036AACF
	if (!ctx.flags.zf) goto loc_36AACF;
	// 0x36A98C: and eax, edx
	ctx.eax = ctx.eax & ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36A98E: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36A991: mov eax, [0x0041D5D4]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5D4u);
	// 0x36A996: mov edx, [eax]
	ctx.edx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36A998: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x36A99B: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x36A99D: mov [edx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x4u, ctx.eax);
	// 0x36A9A0: mov eax, [edi+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x4u);
	// 0x36A9A3: mov [ecx+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, ctx.eax);
	// 0x36A9A6: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36A9A9: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36A9AB: mov [ecx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.eax);
	// 0x36A9AE: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A9B4: call 0x0036A548
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A548(ctx, base);
	ctx.esp += 4;
	// 0x36A9B9: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36A9BB: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36A9C1: jmp 0x0036AACF
	goto loc_36AACF;
loc_36A9C6:
	// 0x36A9C6: cmp ebx, 0x20000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 536870912;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A9CC: jz 0x0036A9DA
	if (ctx.flags.zf) goto loc_36A9DA;
	// 0x36A9CE: cmp ebx, 0x40000000
	{ uint32_t _d = ctx.ebx; uint32_t _s = 1073741824;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A9D4: jnz 0x0036A93C
	if (!ctx.flags.zf) goto loc_36A93C;
loc_36A9DA:
	// 0x36A9DA: cmp dword ptr [ebp+0x0C], 0xC000003E
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = -1073741762;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36A9E1: jnz 0x0036A93C
	if (!ctx.flags.zf) goto loc_36A93C;
	// 0x36A9E7: lea ecx, [esi+0x28]
	ctx.ecx = ctx.esi + 0x28u;
	// 0x36A9EA: call 0x0036A564
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A564(ctx, base);
	ctx.esp += 4;
	// 0x36A9EF: and dword ptr [ebp+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, X86_MEM_READ_u32(base, ctx.ebp + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0xCu), 32);
	// 0x36A9F3: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36A9F6: add ebx, 0x10000000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.ebx) + (uint64_t)(uint32_t)(268435456);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.ebx, (int32_t)268435456, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x36A9FC: jmp 0x0036A941
	goto loc_36A941;
loc_36AA01:
	// 0x36AA01: and dword ptr [esi+0x38], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, X86_MEM_READ_u32(base, ctx.esi + 0x38u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x38u), 32);
	// 0x36AA05: mov byte ptr [esi+0x37], 0x06
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 6);
	// 0x36AA09: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x36AA0C: mov [esi+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.eax);
	// 0x36AA0F: mov byte ptr [esi+0x4F], 0x2A
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 42);
	// 0x36AA13: mov eax, [edi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x36AA16: sub eax, [esi+0x1C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AA19: add eax, [edi+0x04]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x4u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.edi + 0x4u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AA1C: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x36AA1F: mov eax, [esi+0x168]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36AA25: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36AA28: mov eax, [edi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x36AA2B: sub eax, [esi+0x1C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_36AA2E:
	// 0x36AA2E: add eax, [edi+0x04]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edi + 0x4u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.edi + 0x4u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AA31: jmp 0x0036AAA0
	goto loc_36AAA0;
loc_36AA33:
	// 0x36AA33: mov dword ptr [esi+0x28], 0x41D5DC
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 4314588);
	// 0x36AA3A: mov eax, [esi+0x168]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36AA40: sub eax, [esi+0x1C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AA43: mov byte ptr [esi+0x37], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 1);
	// 0x36AA47: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36AA4A: mov byte ptr [esi+0x4F], 0x28
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 40);
	// 0x36AA4E: mov eax, [edi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x36AA51: jmp 0x0036AA2E
	goto loc_36AA2E;
loc_36AA53:
	// 0x36AA53: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x36AA56: mov [esi+0x38], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.eax);
	// 0x36AA59: mov byte ptr [esi+0x37], 0x06
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 6);
	// 0x36AA5D: lea eax, [esi+0x168]
	ctx.eax = ctx.esi + 0x168u;
	// 0x36AA63: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36AA65: mov [esi+0x3C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.ecx);
	// 0x36AA68: mov ecx, [edi+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x36AA6B: mov [esi+0x28], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.ecx);
	// 0x36AA6E: mov eax, [eax]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36AA70: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36AA73: mov byte ptr [esi+0x4F], 0x2A
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 42);
	// 0x36AA77: mov eax, [edi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x36AA7A: sub eax, [esi+0x38]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AA7D: jmp 0x0036AAA0
	goto loc_36AAA0;
loc_36AA7F:
	// 0x36AA7F: mov dword ptr [esi+0x28], 0x41D5DC
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 4314588);
	// 0x36AA86: mov eax, [esi+0x168]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36AA8C: sub eax, [esi+0x18]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AA8F: mov byte ptr [esi+0x37], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 1);
	// 0x36AA93: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36AA96: mov byte ptr [esi+0x4F], 0x28
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 40);
	// 0x36AA9A: mov eax, [edi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0xCu);
	// 0x36AA9D: sub eax, [esi+0x2C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_36AAA0:
	// 0x36AAA0: lea edi, [esi+0x158]
	ctx.edi = ctx.esi + 0x158u;
	// 0x36AAA6: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36AAA8: shr eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x36AAAA: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AAAB: call 0x0036A48E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A48E(ctx, base);
	ctx.esp += 4;
	// 0x36AAB0: mov [esi+0x51], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x51u, ctx.eax);
	// 0x36AAB3: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36AAB5: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x36AAB8: shr eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x36AABA: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36AABC: mov [ebp+0x0E], ah
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xEu, X86_REG8H(ctx.eax));
	// 0x36AABF: mov [ebp+0x0F], al
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xFu, X86_REG8L(ctx.eax));
	// 0x36AAC2: mov ax, [ebp+0x0E]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp + 0xEu);
	// 0x36AAC6: mov [esi+0x56], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x56u, X86_REG16(ctx.eax));
	// 0x36AACA: call 0x0036B743
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B743(ctx, base);
	ctx.esp += 4;
loc_36AACF:
	// 0x36AACF: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AAD0: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AAD1: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AAD2: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AAD3: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36AAD6(X86Context& ctx, uint8_t* base) {
	// 0x36AAD6: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AAD7: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36AAD9: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AADA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AADB: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36AADE: mov ebx, [esi+0x10]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36AAE1: mov edx, [ebx+0x5C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebx + 0x5Cu);
	// 0x36AAE4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AAE5: mov edi, [esi+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36AAE8: and edi, 0xF0000000
	ctx.edi = ctx.edi & -268435456;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x36AAEE: cmp dword ptr [ebp+0x0C], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AAF2: mov [ebp+0x08], edx
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.edx);
	// 0x36AAF5: jl 0x0036AAFF
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36AAFF;
	// 0x36AAF7: add edi, 0x10000000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(268435456);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)268435456, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x36AAFD: jmp 0x0036AB34
	goto loc_36AB34;
loc_36AAFF:
	// 0x36AAFF: cmp edi, 0x20000000
	{ uint32_t _d = ctx.edi; uint32_t _s = 536870912;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB05: jz 0x0036AB0F
	if (ctx.flags.zf) goto loc_36AB0F;
	// 0x36AB07: cmp edi, 0x30000000
	{ uint32_t _d = ctx.edi; uint32_t _s = 805306368;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB0D: jnz 0x0036AB2F
	if (!ctx.flags.zf) goto loc_36AB2F;
loc_36AB0F:
	// 0x36AB0F: cmp dword ptr [ebp+0x0C], 0xC000003E
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp + 0xCu); uint32_t _s = -1073741762;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB16: jnz 0x0036AB2F
	if (!ctx.flags.zf) goto loc_36AB2F;
	// 0x36AB18: lea ecx, [esi+0x28]
	ctx.ecx = ctx.esi + 0x28u;
	// 0x36AB1B: call 0x0036A564
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A564(ctx, base);
	ctx.esp += 4;
	// 0x36AB20: and dword ptr [ebp+0x0C], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp + 0xCu, X86_MEM_READ_u32(base, ctx.ebp + 0xCu) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp + 0xCu), 32);
	// 0x36AB24: mov edx, [ebp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36AB27: add edi, 0x10000000
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(268435456);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)268435456, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x36AB2D: jmp 0x0036AB34
	goto loc_36AB34;
loc_36AB2F:
	// 0x36AB2F: mov edi, 0x50000000
	ctx.edi = 1342177280;
loc_36AB34:
	// 0x36AB34: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36AB37: mov ecx, 0xFFFFFFF
	ctx.ecx = 268435455;
	// 0x36AB3C: and eax, ecx
	ctx.eax = ctx.eax & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36AB3E: or eax, edi
	ctx.eax = ctx.eax | ctx.edi;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36AB40: cmp edi, 0x20000000
	{ uint32_t _d = ctx.edi; uint32_t _s = 536870912;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB46: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36AB49: jz 0x0036ABFB
	if (ctx.flags.zf) goto loc_36ABFB;
	// 0x36AB4F: cmp edi, 0x30000000
	{ uint32_t _d = ctx.edi; uint32_t _s = 805306368;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB55: jz 0x0036ABE2
	if (ctx.flags.zf) goto loc_36ABE2;
	// 0x36AB5B: cmp edi, 0x40000000
	{ uint32_t _d = ctx.edi; uint32_t _s = 1073741824;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB61: jz 0x0036ABAB
	if (ctx.flags.zf) goto loc_36ABAB;
	// 0x36AB63: cmp edi, 0x50000000
	{ uint32_t _d = ctx.edi; uint32_t _s = 1342177280;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AB69: jnz 0x0036AC4A
	if (!ctx.flags.zf) goto loc_36AC4A;
	// 0x36AB6F: and eax, ecx
	ctx.eax = ctx.eax & ctx.ecx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36AB71: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36AB74: mov eax, [0x0041D5D4]
	ctx.eax = X86_MEM_READ_u32(base, 0x41D5D4u);
	// 0x36AB79: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36AB7B: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x36AB7E: mov [eax], ecx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.ecx);
	// 0x36AB80: mov [ecx+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.eax);
	// 0x36AB83: mov eax, [edx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x4u);
	// 0x36AB86: mov [ebx+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x14u, ctx.eax);
	// 0x36AB89: mov eax, [ebp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36AB8C: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36AB8E: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x36AB90: mov [ebx+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x10u, ctx.eax);
	// 0x36AB93: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AB99: call 0x0036A548
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A548(ctx, base);
	ctx.esp += 4;
	// 0x36AB9E: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36ABA0: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36ABA6: jmp 0x0036AC4A
	goto loc_36AC4A;
loc_36ABAB:
	// 0x36ABAB: mov byte ptr [esi+0x4F], 0x2A
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 42);
	// 0x36ABAF: mov byte ptr [esi+0x37], 0x06
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 6);
	// 0x36ABB3: mov eax, [esi+0x168]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36ABB9: sub eax, [esi+0x18]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36ABBC: mov [esi+0x38], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x38u, ctx.eax);
	// 0x36ABBF: mov eax, [esi+0x168]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36ABC5: sub eax, [esi+0x1C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36ABC8: mov [esi+0x3C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x3Cu, ctx.eax);
	// 0x36ABCB: mov eax, [edx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0x8u);
	// 0x36ABCE: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x36ABD1: mov eax, [esi+0x168]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36ABD7: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36ABDA: mov eax, [edx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x36ABDD: sub eax, [esi+0x38]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x38u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36ABE0: jmp 0x0036AC1B
	goto loc_36AC1B;
loc_36ABE2:
	// 0x36ABE2: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x36ABE5: add eax, 0x41D5DC
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(4314588);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)4314588, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36ABEA: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x36ABED: mov eax, [esi+0x1C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x1Cu);
	// 0x36ABF0: mov [esi+0x2C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.eax);
	// 0x36ABF3: mov eax, [edx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x36ABF6: add eax, [edx+0x04]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.edx + 0x4u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.edx + 0x4u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36ABF9: jmp 0x0036AC1B
	goto loc_36AC1B;
loc_36ABFB:
	// 0x36ABFB: mov byte ptr [esi+0x37], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 1);
	// 0x36ABFF: mov byte ptr [esi+0x4F], 0x28
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 40);
	// 0x36AC03: mov dword ptr [esi+0x28], 0x41D5DC
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, 4314588);
	// 0x36AC0A: mov ecx, [esi+0x168]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36AC10: sub ecx, [esi+0x18]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x18u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x36AC13: mov [esi+0x2C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.ecx);
	// 0x36AC16: mov eax, [edx+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edx + 0xCu);
	// 0x36AC19: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
loc_36AC1B:
	// 0x36AC1B: lea edi, [esi+0x158]
	ctx.edi = ctx.esi + 0x158u;
	// 0x36AC21: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36AC23: shr eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x36AC25: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AC26: call 0x0036A48E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A48E(ctx, base);
	ctx.esp += 4;
	// 0x36AC2B: mov [esi+0x51], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x51u, ctx.eax);
	// 0x36AC2E: mov ecx, [edi]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi);
	// 0x36AC30: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x36AC33: shr eax, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.eax >> (_cnt - 1)) & 1;
	  ctx.eax = (uint32_t)(ctx.eax) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32); } }
	// 0x36AC35: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36AC37: mov [ebp+0x0E], ah
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xEu, X86_REG8H(ctx.eax));
	// 0x36AC3A: mov [ebp+0x0F], al
	X86_MEM_WRITE_u8(base, ctx.ebp + 0xFu, X86_REG8L(ctx.eax));
	// 0x36AC3D: mov ax, [ebp+0x0E]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp + 0xEu);
	// 0x36AC41: mov [esi+0x56], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x56u, X86_REG16(ctx.eax));
	// 0x36AC45: call 0x0036B743
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B743(ctx, base);
	ctx.esp += 4;
loc_36AC4A:
	// 0x36AC4A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AC4B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AC4C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AC4D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AC4E: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36AC51(X86Context& ctx, uint8_t* base) {
	// 0x36AC51: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AC52: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AC53: push 0x5F5F554D
	{ auto _pv = (uint32_t)(1600083277); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AC58: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AC5A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AC5B: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AC5C: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36AC5E: call [0x0036B924]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B924u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AC64: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36AC66: jnz 0x0036AC76
	if (!ctx.flags.zf) goto loc_36AC76;
	// 0x36AC68: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36AC6B: and dword ptr [eax+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, X86_MEM_READ_u32(base, ctx.eax + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x14u), 32);
	// 0x36AC6F: mov eax, 0xC000009A
	ctx.eax = -1073741670;
	// 0x36AC74: jmp 0x0036ACAB
	goto loc_36ACAB;
loc_36AC76:
	// 0x36AC76: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x36AC79: mov [esi+0x2C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.edi);
	// 0x36AC7C: lea ecx, [esi+0x4F]
	ctx.ecx = ctx.esi + 0x4Fu;
	// 0x36AC7F: mov dword ptr [esi+0x30], 0x36A5BB
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3581371);
	// 0x36AC86: mov word ptr [esi+0x34], 0x0A
	X86_MEM_WRITE_u16(base, ctx.esi + 0x34u, 10);
	// 0x36AC8C: mov byte ptr [esi+0x36], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0x36u, 2);
	// 0x36AC90: mov byte ptr [esi+0x37], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 1);
	// 0x36AC94: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36AC96: mov edi, ecx
	ctx.edi = ctx.ecx;
	// 0x36AC98: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AC99: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AC9A: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AC9B: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AC9C: mov byte ptr [ecx], 0x25
	X86_MEM_WRITE_u8(base, ctx.ecx, 37);
	// 0x36AC9F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36ACA1: call 0x0036B743
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B743(ctx, base);
	ctx.esp += 4;
	// 0x36ACA6: mov eax, 0x103
	ctx.eax = 259;
loc_36ACAB:
	// 0x36ACAB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36ACAC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36ACAD: ret
	return;
}

void sub_36ACAE(X86Context& ctx, uint8_t* base) {
	// 0x36ACAE: mov edx, [esp+0x08]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x36ACB2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36ACB3: mov esi, [esp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x36ACB7: and byte ptr [esi+0x0F], 0x0F
	X86_MEM_WRITE_u8(base, ctx.esi + 0xFu, X86_MEM_READ_u8(base, ctx.esi + 0xFu) & 15);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xFu), 8);
	// 0x36ACBB: mov ecx, [esi+0x10]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36ACBE: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36ACBF: mov eax, 0xC0000000
	ctx.eax = -1073741824;
	// 0x36ACC4: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x36ACC6: and edi, eax
	ctx.edi = ctx.edi & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x36ACC8: cmp edi, eax
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36ACCA: jnz 0x0036ACE5
	if (!ctx.flags.zf) goto loc_36ACE5;
	// 0x36ACCC: and dword ptr [ecx+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, X86_MEM_READ_u32(base, ctx.ecx + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ecx + 0x14u), 32);
	// 0x36ACD0: mov [ecx+0x10], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.edx);
	// 0x36ACD3: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36ACD5: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36ACDB: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36ACDD: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36ACE3: jmp 0x0036AD4B
	goto loc_36AD4B;
loc_36ACE5:
	// 0x36ACE5: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36ACE7: lea edi, [esi+0x4F]
	ctx.edi = ctx.esi + 0x4Fu;
	// 0x36ACEA: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36ACEB: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36ACEC: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36ACED: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36ACEE: mov word ptr [esi+0x34], 0x08
	X86_MEM_WRITE_u16(base, ctx.esi + 0x34u, 8);
	// 0x36ACF4: mov byte ptr [esi+0x36], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0x36u, 2);
	// 0x36ACF8: test byte ptr [esi+0x0F], 0x08
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xFu) & 8, 8);
	// 0x36ACFC: jz 0x0036AD07
	if (ctx.flags.zf) goto loc_36AD07;
	// 0x36ACFE: mov dword ptr [esi+0x30], 0x36AAD6
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3582678);
	// 0x36AD05: jmp 0x0036AD0E
	goto loc_36AD0E;
loc_36AD07:
	// 0x36AD07: mov dword ptr [esi+0x30], 0x36A8F0
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3582192);
loc_36AD0E:
	// 0x36AD0E: or byte ptr [esi+0x0F], 0x10
	X86_MEM_WRITE_u8(base, ctx.esi + 0xFu, X86_MEM_READ_u8(base, ctx.esi + 0xFu) | 16);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xFu), 8);
	// 0x36AD12: mov edi, [0x0041D5D4]
	ctx.edi = X86_MEM_READ_u32(base, 0x41D5D4u);
	// 0x36AD18: mov edx, 0x41D5D4
	ctx.edx = 4314580;
	// 0x36AD1D: cmp edi, edx
	{ uint32_t _d = ctx.edi; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AD1F: lea eax, [ecx+0x54]
	ctx.eax = ctx.ecx + 0x54u;
	// 0x36AD22: jnz 0x0036AD39
	if (!ctx.flags.zf) goto loc_36AD39;
	// 0x36AD24: mov [eax], edi
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edi);
	// 0x36AD26: mov [ecx+0x58], edx
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x58u, ctx.edx);
	// 0x36AD29: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD2B: mov [edi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.eax);
	// 0x36AD2E: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD2F: mov [0x0041D5D4], eax
	X86_MEM_WRITE_u32(base, 0x41D5D4u, ctx.eax);
	// 0x36AD34: call [esi+0x30]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AD37: jmp 0x0036AD4B
	goto loc_36AD4B;
loc_36AD39:
	// 0x36AD39: mov esi, [0x0041D5D8]
	ctx.esi = X86_MEM_READ_u32(base, 0x41D5D8u);
	// 0x36AD3F: mov [eax], edx
	X86_MEM_WRITE_u32(base, ctx.eax, ctx.edx);
	// 0x36AD41: mov [ecx+0x58], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x58u, ctx.esi);
	// 0x36AD44: mov [esi], eax
	X86_MEM_WRITE_u32(base, ctx.esi, ctx.eax);
	// 0x36AD46: mov [0x0041D5D8], eax
	X86_MEM_WRITE_u32(base, 0x41D5D8u, ctx.eax);
loc_36AD4B:
	// 0x36AD4B: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AD4C: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AD4D: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36AD50(X86Context& ctx, uint8_t* base) {
	// 0x36AD50: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD51: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36AD53: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD54: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36AD57: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD58: mov esi, [ebp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36AD5B: mov eax, [esi+0x5C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x5Cu);
	// 0x36AD5E: mov eax, [eax+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x36AD61: sub eax, 0x70000
	{ uint32_t _d = ctx.eax; uint32_t _s = 458752;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AD66: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD67: jz 0x0036ADD3
	if (ctx.flags.zf) goto loc_36ADD3;
	// 0x36AD69: sub eax, 0x14
	{ uint32_t _d = ctx.eax; uint32_t _s = 20;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AD6C: jz 0x0036ADC7
	if (ctx.flags.zf) goto loc_36ADC7;
	// 0x36AD6E: sub eax, 0x3FF0
	{ uint32_t _d = ctx.eax; uint32_t _s = 16368;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AD73: jz 0x0036AD83
	if (ctx.flags.zf) goto loc_36AD83;
	// 0x36AD75: and dword ptr [esi+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, X86_MEM_READ_u32(base, ctx.esi + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0x14u), 32);
	// 0x36AD79: mov eax, 0xC0000010
	ctx.eax = -1073741808;
	// 0x36AD7E: jmp 0x0036AE04
	goto loc_36AE04;
loc_36AD83:
	// 0x36AD83: mov edx, [esi+0x30]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	// 0x36AD86: push 0x08
	{ auto _pv = (uint32_t)(8); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AD88: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36AD8A: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AD8B: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x36AD8D: rep stosd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x36AD8F: mov eax, [ebx+0x160]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x160u);
	// 0x36AD95: or eax, [ebx+0x164]
	ctx.eax = ctx.eax | X86_MEM_READ_u32(base, ctx.ebx + 0x164u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36AD9B: jnz 0x0036ADA8
	if (!ctx.flags.zf) goto loc_36ADA8;
loc_36AD9D:
	// 0x36AD9D: mov edx, esi
	ctx.edx = ctx.esi;
	// 0x36AD9F: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x36ADA1: call 0x0036AC51
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36AC51(ctx, base);
	ctx.esp += 4;
	// 0x36ADA6: jmp 0x0036ADFD
	goto loc_36ADFD;
loc_36ADA8:
	// 0x36ADA8: mov eax, [ebx+0x160]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x160u);
	// 0x36ADAE: mov [edx+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x8u, ctx.eax);
	// 0x36ADB1: mov eax, [ebx+0x164]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x164u);
	// 0x36ADB7: mov [edx+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0xCu, ctx.eax);
	// 0x36ADBA: mov byte ptr [edx+0x1A], 0x01
	X86_MEM_WRITE_u8(base, ctx.edx + 0x1Au, 1);
	// 0x36ADBE: mov dword ptr [esi+0x14], 0x20
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, 32);
	// 0x36ADC5: jmp 0x0036ADFB
	goto loc_36ADFB;
loc_36ADC7:
	// 0x36ADC7: mov ecx, [ebp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36ADCA: mov edx, esi
	ctx.edx = ctx.esi;
	// 0x36ADCC: call 0x0036A7A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A7A1(ctx, base);
	ctx.esp += 4;
	// 0x36ADD1: jmp 0x0036AE19
	goto loc_36AE19;
loc_36ADD3:
	// 0x36ADD3: mov eax, [ebx+0x160]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x160u);
	// 0x36ADD9: or eax, [ebx+0x164]
	ctx.eax = ctx.eax | X86_MEM_READ_u32(base, ctx.ebx + 0x164u);
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36ADDF: mov edi, [esi+0x30]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	// 0x36ADE2: jz 0x0036AD9D
	if (ctx.flags.zf) goto loc_36AD9D;
	// 0x36ADE4: push 0x06
	{ auto _pv = (uint32_t)(6); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36ADE6: lea esi, [ebx+0x140]
	ctx.esi = ctx.ebx + 0x140u;
	// 0x36ADEC: pop ecx
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36ADED: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x36ADEF: mov ecx, [ebp+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36ADF2: mov dword ptr [ecx+0x14], 0x18
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, 24);
	// 0x36ADF9: mov esi, ecx
	ctx.esi = ctx.ecx;
loc_36ADFB:
	// 0x36ADFB: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
loc_36ADFD:
	// 0x36ADFD: cmp eax, 0x103
	{ uint32_t _d = ctx.eax; uint32_t _s = 259;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AE02: jz 0x0036AE19
	if (ctx.flags.zf) goto loc_36AE19;
loc_36AE04:
	// 0x36AE04: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36AE06: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36AE08: mov [esi+0x10], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.eax);
	// 0x36AE0B: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AE11: push [ebx]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ebx)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AE13: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36AE19:
	// 0x36AE19: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AE1A: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AE1B: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AE1C: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AE1D: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36AE20(X86Context& ctx, uint8_t* base) {
	// 0x36AE20: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AE21: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36AE23: sub esp, 0x0C
	{ uint32_t _d = ctx.esp; uint32_t _s = 12;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x36AE26: and dword ptr [ebp-0x04], 0x00
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, X86_MEM_READ_u32(base, ctx.ebp - 0x4u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.ebp - 0x4u), 32);
	// 0x36AE2A: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AE2B: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x36AE2D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AE2E: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36AE30: mov ecx, [eax+0x5C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x5Cu);
	// 0x36AE33: mov edx, [ecx+0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ecx + 0xCu);
	// 0x36AE36: mov ebx, [ecx+0x04]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x4u);
	// 0x36AE39: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AE3A: mov edi, 0xFFF
	ctx.edi = 4095;
	// 0x36AE3F: test edi, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.edx, 32);
	// 0x36AE41: mov [ebp-0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x8u, ctx.eax);
	// 0x36AE44: mov [ebp-0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, ctx.edx);
	// 0x36AE47: jnz 0x0036AE9C
	if (!ctx.flags.zf) goto loc_36AE9C;
	// 0x36AE49: test edi, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edi & ctx.ebx, 32);
	// 0x36AE4B: jnz 0x0036AE9C
	if (!ctx.flags.zf) goto loc_36AE9C;
	// 0x36AE4D: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36AE4F: mov edi, ebx
	ctx.edi = ctx.ebx;
	// 0x36AE51: add edi, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)ctx.edx, 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x36AE53: adc eax, [ecx+0x10]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x10u)) + (uint64_t)ctx.flags.cf;
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x10u), 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AE56: cmp eax, [esi+0x164]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x164u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AE5C: jnle 0x0036AE99
	if ((!ctx.flags.zf && ctx.flags.sf == ctx.flags.of)) goto loc_36AE99;
	// 0x36AE5E: jl 0x0036AE68
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36AE68;
	// 0x36AE60: cmp edi, [esi+0x160]
	{ uint32_t _d = ctx.edi; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x160u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AE66: jnbe 0x0036AE99
	if ((!ctx.flags.cf && !ctx.flags.zf)) goto loc_36AE99;
loc_36AE68:
	// 0x36AE68: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x36AE6A: jnz 0x0036AE74
	if (!ctx.flags.zf) goto loc_36AE74;
	// 0x36AE6C: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x36AE6F: and [eax+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, X86_MEM_READ_u32(base, ctx.eax + 0x10u) & ctx.ebx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x10u), 32);
	// 0x36AE72: jmp 0x0036AEA9
	goto loc_36AEA9;
loc_36AE74:
	// 0x36AE74: test byte ptr [ecx+0x02], 0x80
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.ecx + 0x2u) & -128, 8);
	// 0x36AE78: jz 0x0036AE85
	if (ctx.flags.zf) goto loc_36AE85;
	// 0x36AE7A: mov eax, [ecx+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ecx + 0x8u);
	// 0x36AE7D: mov [ebp-0x04], eax
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.eax);
	// 0x36AE80: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x36AE83: jmp 0x0036AE91
	goto loc_36AE91;
loc_36AE85:
	// 0x36AE85: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
	// 0x36AE88: mov edi, [eax+0x30]
	ctx.edi = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	// 0x36AE8B: add edi, [ecx+0x08]
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edi) + (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x8u));
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edi, (int32_t)X86_MEM_READ_u32(base, ctx.ecx + 0x8u), 32);
	  ctx.edi = (uint32_t)_res; }
	// 0x36AE8E: mov [ebp-0x04], edi
	X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, ctx.edi);
loc_36AE91:
	// 0x36AE91: mov edi, [ebp-0x04]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36AE94: mov [ecx+0x08], edi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.edi);
	// 0x36AE97: jmp 0x0036AEA3
	goto loc_36AEA3;
loc_36AE99:
	// 0x36AE99: mov eax, [ebp-0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x8u);
loc_36AE9C:
	// 0x36AE9C: mov dword ptr [eax+0x10], 0xC000000D
	X86_MEM_WRITE_u32(base, ctx.eax + 0x10u, -1073741811);
loc_36AEA3:
	// 0x36AEA3: cmp dword ptr [ebp-0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ebp - 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AEA7: jnz 0x0036AEC4
	if (!ctx.flags.zf) goto loc_36AEC4;
loc_36AEA9:
	// 0x36AEA9: and dword ptr [eax+0x14], 0x00
	X86_MEM_WRITE_u32(base, ctx.eax + 0x14u, X86_MEM_READ_u32(base, ctx.eax + 0x14u) & 0);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.eax + 0x14u), 32);
	// 0x36AEAD: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36AEAF: mov ecx, eax
	ctx.ecx = ctx.eax;
	// 0x36AEB1: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AEB7: push [esi]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AEB9: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AEBF: jmp 0x0036AFAB
	goto loc_36AFAB;
loc_36AEC4:
	// 0x36AEC4: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36AEC6: lea edi, [esi+0x4F]
	ctx.edi = ctx.esi + 0x4Fu;
	// 0x36AEC9: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AECA: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AECB: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AECC: stosd
	X86_MEM_WRITE_u32(base, ctx.edi, ctx.eax);
	ctx.edi += ctx.flags.df ? -4 : 4;
	// 0x36AECD: cmp byte ptr [ecx], 0x03
	{ uint8_t _d = X86_MEM_READ_u8(base, ctx.ecx); uint8_t _s = 3;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x36AED0: jnz 0x0036AF5D
	if (!ctx.flags.zf) goto loc_36AF5D;
	// 0x36AED6: mov edi, [esi+0x168]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x168u);
	// 0x36AEDC: mov eax, edx
	ctx.eax = ctx.edx;
	// 0x36AEDE: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36AEE0: div edi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.edi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x36AEE2: and byte ptr [esi+0x0F], 0xF1
	X86_MEM_WRITE_u8(base, ctx.esi + 0xFu, X86_MEM_READ_u8(base, ctx.esi + 0xFu) & -15);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xFu), 8);
	// 0x36AEE6: mov ecx, [esi+0x0C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36AEE9: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x36AEEB: jz 0x0036AF19
	if (ctx.flags.zf) goto loc_36AF19;
	// 0x36AEED: mov eax, edi
	ctx.eax = ctx.edi;
	// 0x36AEEF: sub eax, edx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AEF1: cmp eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36AEF3: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x36AEF6: jbe 0x0036AF08
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_36AF08;
	// 0x36AEF8: or ecx, 0x8000000
	ctx.ecx = ctx.ecx | 134217728;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36AEFE: sub eax, ebx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ebx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AF00: mov [esi+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ecx);
	// 0x36AF03: mov [esi+0x1C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.eax);
	// 0x36AF06: jmp 0x0036AF30
	goto loc_36AF30;
loc_36AF08:
	// 0x36AF08: add [ebp-0x0C], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0xCu)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0xCu), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0xCu, (uint32_t)_res); }
	// 0x36AF0B: add [ebp-0x04], eax
	{ uint64_t _res = (uint64_t)(uint32_t)(X86_MEM_READ_u32(base, ctx.ebp - 0x4u)) + (uint64_t)(uint32_t)(ctx.eax);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)X86_MEM_READ_u32(base, ctx.ebp - 0x4u), (int32_t)ctx.eax, 32);
	  X86_MEM_WRITE_u32(base, ctx.ebp - 0x4u, (uint32_t)_res); }
	// 0x36AF0E: sub ebx, eax
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x36AF10: or ecx, 0x2000000
	ctx.ecx = ctx.ecx | 33554432;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36AF16: mov [esi+0x0C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.ecx);
loc_36AF19:
	// 0x36AF19: xor edx, edx
	ctx.edx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36AF1B: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x36AF1D: div edi
	{ uint64_t _dividend = ((uint64_t)ctx.edx << 32) | ctx.eax;
	  uint32_t _divisor = ctx.edi;
	  ctx.eax = (uint32_t)(_dividend / _divisor);
	  ctx.edx = (uint32_t)(_dividend % _divisor); }
	// 0x36AF1F: test edx, edx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.edx, 32);
	// 0x36AF21: jz 0x0036AF2C
	if (ctx.flags.zf) goto loc_36AF2C;
	// 0x36AF23: sub ebx, edx
	{ uint32_t _d = ctx.ebx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ebx = (uint32_t)_res; }
	// 0x36AF25: or byte ptr [esi+0x0F], 0x04
	X86_MEM_WRITE_u8(base, ctx.esi + 0xFu, X86_MEM_READ_u8(base, ctx.esi + 0xFu) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xFu), 8);
	// 0x36AF29: mov [esi+0x1C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x1Cu, ctx.edx);
loc_36AF2C:
	// 0x36AF2C: test ebx, ebx
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.ebx & ctx.ebx, 32);
	// 0x36AF2E: jnz 0x0036AF3A
	if (!ctx.flags.zf) goto loc_36AF3A;
loc_36AF30:
	// 0x36AF30: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AF32: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AF33: call 0x0036ACAE
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36ACAE(ctx, base);
	ctx.esp += 4;
	// 0x36AF38: jmp 0x0036AFAB
	goto loc_36AFAB;
loc_36AF3A:
	// 0x36AF3A: test byte ptr [esi+0x0F], 0x0E
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xFu) & 14, 8);
	// 0x36AF3E: jz 0x0036AF49
	if (ctx.flags.zf) goto loc_36AF49;
	// 0x36AF40: mov dword ptr [esi+0x30], 0x36ACAE
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3583150);
	// 0x36AF47: jmp 0x0036AF50
	goto loc_36AF50;
loc_36AF49:
	// 0x36AF49: mov dword ptr [esi+0x30], 0x36A508
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3581192);
loc_36AF50:
	// 0x36AF50: mov edx, [ebp-0x0C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.ebp - 0xCu);
	// 0x36AF53: mov byte ptr [esi+0x37], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 2);
	// 0x36AF57: mov byte ptr [esi+0x4F], 0x2A
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 42);
	// 0x36AF5B: jmp 0x0036AF6C
	goto loc_36AF6C;
loc_36AF5D:
	// 0x36AF5D: mov dword ptr [esi+0x30], 0x36A822
	X86_MEM_WRITE_u32(base, ctx.esi + 0x30u, 3581986);
	// 0x36AF64: mov byte ptr [esi+0x37], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0x37u, 1);
	// 0x36AF68: mov byte ptr [esi+0x4F], 0x28
	X86_MEM_WRITE_u8(base, ctx.esi + 0x4Fu, 40);
loc_36AF6C:
	// 0x36AF6C: mov edi, [esi+0x158]
	ctx.edi = X86_MEM_READ_u32(base, ctx.esi + 0x158u);
	// 0x36AF72: mov eax, [ebp-0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp - 0x4u);
	// 0x36AF75: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36AF77: shr edx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.edx >> (_cnt - 1)) & 1;
	  ctx.edx = (uint32_t)(ctx.edx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edx, 32); } }
	// 0x36AF79: mov [esi+0x28], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x28u, ctx.eax);
	// 0x36AF7C: mov [esi+0x2C], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x2Cu, ctx.ebx);
	// 0x36AF7F: mov word ptr [esi+0x34], 0x08
	X86_MEM_WRITE_u16(base, ctx.esi + 0x34u, 8);
	// 0x36AF85: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AF86: mov byte ptr [esi+0x36], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0x36u, 2);
	// 0x36AF8A: call 0x0036A48E
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36A48E(ctx, base);
	ctx.esp += 4;
	// 0x36AF8F: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36AF91: shr ebx, cl
	{ auto _cnt = X86_REG8L(ctx.ecx) & 0x1F; if (_cnt) {
	  ctx.flags.cf = (ctx.ebx >> (_cnt - 1)) & 1;
	  ctx.ebx = (uint32_t)(ctx.ebx) >> _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ebx, 32); } }
	// 0x36AF93: mov [esi+0x51], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x51u, ctx.eax);
	// 0x36AF96: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36AF98: mov [ebp-0x02], bh
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x2u, X86_REG8H(ctx.ebx));
	// 0x36AF9B: mov [ebp-0x01], bl
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, X86_REG8L(ctx.ebx));
	// 0x36AF9E: mov ax, [ebp-0x02]
	X86_REG16(ctx.eax) = X86_MEM_READ_u16(base, ctx.ebp - 0x2u);
	// 0x36AFA2: mov [esi+0x56], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0x56u, X86_REG16(ctx.eax));
	// 0x36AFA6: call 0x0036B743
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B743(ctx, base);
	ctx.esp += 4;
loc_36AFAB:
	// 0x36AFAB: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AFAC: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AFAD: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AFAE: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36AFAF: ret
	return;
}

void sub_36AFB0(X86Context& ctx, uint8_t* base) {
	// 0x36AFB0: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AFB1: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36AFB3: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AFB4: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36AFB7: mov eax, [ebx+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x18u);
	// 0x36AFBA: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AFBB: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AFBC: mov edi, [ebp+0x0C]
	ctx.edi = X86_MEM_READ_u32(base, ctx.ebp + 0xCu);
	// 0x36AFBF: mov esi, [edi+0x5C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.edi + 0x5Cu);
	// 0x36AFC2: mov [ebp+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.ebp + 0x8u, ctx.eax);
	// 0x36AFC5: call [0x0036BA08]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA08u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AFCB: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x36AFCD: jz 0x0036AFE9
	if (ctx.flags.zf) goto loc_36AFE9;
	// 0x36AFCF: xor dl, dl
	X86_REG8L(ctx.edx) = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 8);
	// 0x36AFD1: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36AFD3: mov dword ptr [edi+0x10], 0xC0000240
	X86_MEM_WRITE_u32(base, ctx.edi + 0x10u, -1073741248);
	// 0x36AFDA: call [0x0036B9E8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B9E8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AFE0: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36AFE1: call [0x0036BA00]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA00u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36AFE7: jmp 0x0036B01A
	goto loc_36B01A;
loc_36AFE9:
	// 0x36AFE9: mov [esi+0x14], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.ebx);
	// 0x36AFEC: mov ebx, [ebp+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x36AFEF: mov [ebx+0x10], edi
	X86_MEM_WRITE_u32(base, ctx.ebx + 0x10u, ctx.edi);
	// 0x36AFF2: movzx eax, byte ptr [esi]
	ctx.eax = (uint32_t)(X86_MEM_READ_u8(base, ctx.esi));
	// 0x36AFF5: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AFF6: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AFF7: jz 0x0036B011
	if (ctx.flags.zf) goto loc_36B011;
	// 0x36AFF9: dec eax
	{ uint32_t _d = ctx.eax;
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int32_t)_d, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AFFA: jz 0x0036B00A
	if (ctx.flags.zf) goto loc_36B00A;
	// 0x36AFFC: sub eax, 0x07
	{ uint32_t _d = ctx.eax; uint32_t _s = 7;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36AFFF: jnz 0x0036B01A
	if (!ctx.flags.zf) goto loc_36B01A;
	// 0x36B001: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B002: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B003: call 0x0036AD50
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36AD50(ctx, base);
	ctx.esp += 4;
	// 0x36B008: jmp 0x0036B01A
	goto loc_36B01A;
loc_36B00A:
	// 0x36B00A: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B00B: call [0x0036BA04]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36BA04u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36B011:
	// 0x36B011: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x36B013: mov ecx, ebx
	ctx.ecx = ctx.ebx;
	// 0x36B015: call 0x0036AE20
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36AE20(ctx, base);
	ctx.esp += 4;
loc_36B01A:
	// 0x36B01A: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B01B: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B01C: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B01D: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B01E: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36B021(X86Context& ctx, uint8_t* base) {
	// 0x36B021: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B022: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x36B026: and byte ptr [esi+0x0D], 0xFE
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B02A: test byte ptr [esi+0x0D], 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xDu) & 2, 8);
	// 0x36B02E: jz 0x0036B041
	if (ctx.flags.zf) goto loc_36B041;
	// 0x36B030: lea eax, [esi+0xB8]
	ctx.eax = ctx.esi + 0xB8u;
	// 0x36B036: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B037: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B03A: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36B03C: call 0x00364DD9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364DD9(ctx, base);
	ctx.esp += 4;
loc_36B041:
	// 0x36B041: test byte ptr [esi+0x0D], 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xDu) & 4, 8);
	// 0x36B045: jz 0x0036B058
	if (ctx.flags.zf) goto loc_36B058;
	// 0x36B047: lea eax, [esi+0xE8]
	ctx.eax = ctx.esi + 0xE8u;
	// 0x36B04D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B04E: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B051: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36B053: call 0x00364DD9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364DD9(ctx, base);
	ctx.esp += 4;
loc_36B058:
	// 0x36B058: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B059: ret 0x10
	ctx.esp += 16;
	return;
}

void sub_36B05C(X86Context& ctx, uint8_t* base) {
	// 0x36B05C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B05D: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B05E: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36B060: test byte ptr [esi+0x0D], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xDu) & 1, 8);
	// 0x36B064: mov ebp, [esi+0x08]
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B067: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B068: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x36B06A: jz 0x0036B07A
	if (ctx.flags.zf) goto loc_36B07A;
	// 0x36B06C: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B06F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B070: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B076: and byte ptr [esi+0x0D], 0xFE
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
loc_36B07A:
	// 0x36B07A: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36B07D: test al, 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 6, 8);
	// 0x36B07F: jz 0x0036B08F
	if (ctx.flags.zf) goto loc_36B08F;
	// 0x36B081: push 0xC000009D
	{ auto _pv = (uint32_t)(-1073741667); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B086: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B087: call [esi+0x30]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B08A: jmp 0x0036B15E
	goto loc_36B15E;
loc_36B08F:
	// 0x36B08F: or eax, 0x1000
	ctx.eax = ctx.eax | 4096;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B094: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B095: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B098: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x36B09B: mov [esi+0x6C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, ctx.edi);
	// 0x36B09E: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x36B0A4: xor ebx, ebx
	ctx.ebx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36B0A6: mov byte ptr [edi], 0x18
	X86_MEM_WRITE_u8(base, ctx.edi, 24);
	// 0x36B0A9: mov byte ptr [esi+0xB9], 0x05
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 5);
	// 0x36B0B0: mov [esi+0xC0], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, ctx.ebx);
	// 0x36B0B6: mov [esi+0xC8], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.eax);
	// 0x36B0BC: mov dword ptr [esi+0xCC], 0x04
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, 4);
	// 0x36B0C6: mov ecx, [ebp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x36B0C9: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B0CA: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36B0CF: or byte ptr [esi+0x0D], 0x03
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) | 3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B0D3: lea edx, [esi+0x98]
	ctx.edx = ctx.esi + 0x98u;
	// 0x36B0D9: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B0DA: or ecx, 0xFFFFFFFF
	ctx.ecx = ctx.ecx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36B0DD: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B0DE: mov eax, 0xFFF0BDC0
	ctx.eax = -1000000;
	// 0x36B0E3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B0E4: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B0E7: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B0E8: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B0EE: mov byte ptr [edi], 0x30
	X86_MEM_WRITE_u8(base, ctx.edi, 48);
	// 0x36B0F1: mov byte ptr [esi+0xB9], 0x40
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 64);
	// 0x36B0F8: mov dword ptr [esi+0xC0], 0x36B543
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, 3585347);
	// 0x36B102: mov [esi+0xC4], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC4u, ctx.esi);
	// 0x36B108: mov [esi+0xC8], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.ebx);
	// 0x36B10E: mov [esi+0xD0], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xD0u, ctx.ebx);
	// 0x36B114: mov [esi+0xCC], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, ctx.ebx);
	// 0x36B11A: mov [esi+0xD4], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD4u, X86_REG8L(ctx.ebx));
	// 0x36B120: mov [esi+0xD5], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD5u, X86_REG8L(ctx.ebx));
	// 0x36B126: mov [esi+0xD6], bl
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD6u, X86_REG8L(ctx.ebx));
	// 0x36B12C: mov byte ptr [esi+0xE0], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xE0u, 2);
	// 0x36B133: mov byte ptr [esi+0xE1], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0xE1u, 1);
	// 0x36B13A: mov [esi+0xE2], bx
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE2u, X86_REG16(ctx.ebx));
	// 0x36B141: movzx ax, byte ptr [ebp+0x05]
	X86_REG16(ctx.eax) = (uint16_t)(X86_MEM_READ_u8(base, ctx.ebp + 0x5u));
	// 0x36B146: mov [esi+0xE4], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE4u, X86_REG16(ctx.eax));
	// 0x36B14D: mov [esi+0xE6], bx
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE6u, X86_REG16(ctx.ebx));
	// 0x36B154: mov ecx, [ebp]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebp);
	// 0x36B157: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B158: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36B15D: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_36B15E:
	// 0x36B15E: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B15F: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B160: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B161: ret
	return;
}

void sub_36B162(X86Context& ctx, uint8_t* base) {
	// 0x36B162: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B163: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x36B167: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B168: xor edi, edi
	ctx.edi = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36B16A: test byte ptr [esi+0x0D], 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xDu) & 1, 8);
	// 0x36B16E: jz 0x0036B17E
	if (ctx.flags.zf) goto loc_36B17E;
	// 0x36B170: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B173: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B174: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B17A: and byte ptr [esi+0x0D], 0xFE
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
loc_36B17E:
	// 0x36B17E: and byte ptr [esi+0x0D], 0xFD
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B182: mov eax, [esp+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x36B186: mov eax, [eax+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x36B189: test eax, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.eax & ctx.eax, 32);
	// 0x36B18B: jnl 0x0036B195
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_36B195;
	// 0x36B18D: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B18E: call 0x00364E79
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364E79(ctx, base);
	ctx.esp += 4;
	// 0x36B193: mov edi, eax
	ctx.edi = ctx.eax;
loc_36B195:
	// 0x36B195: cmp dword ptr [esi+0x5F], 0x53425355
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x5Fu); uint32_t _s = 1396855637;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B19C: mov eax, 0xC0000001
	ctx.eax = -1073741823;
	// 0x36B1A1: jz 0x0036B1A5
	if (ctx.flags.zf) goto loc_36B1A5;
	// 0x36B1A3: mov edi, eax
	ctx.edi = ctx.eax;
loc_36B1A5:
	// 0x36B1A5: mov ecx, [esi+0x63]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x63u);
	// 0x36B1A8: cmp ecx, [esi+0x44]
	{ uint32_t _d = ctx.ecx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x44u);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B1AB: jz 0x0036B1AF
	if (ctx.flags.zf) goto loc_36B1AF;
	// 0x36B1AD: mov edi, eax
	ctx.edi = ctx.eax;
loc_36B1AF:
	// 0x36B1AF: mov cl, [esi+0x6B]
	X86_REG8L(ctx.ecx) = X86_MEM_READ_u8(base, ctx.esi + 0x6Bu);
	// 0x36B1B2: cmp cl, 0x02
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 2;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x36B1B5: jnz 0x0036B1B9
	if (!ctx.flags.zf) goto loc_36B1B9;
	// 0x36B1B7: mov edi, eax
	ctx.edi = ctx.eax;
loc_36B1B9:
	// 0x36B1B9: cmp cl, 0x01
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x36B1BC: jnz 0x0036B1C3
	if (!ctx.flags.zf) goto loc_36B1C3;
	// 0x36B1BE: mov edi, 0xC000003E
	ctx.edi = -1073741762;
loc_36B1C3:
	// 0x36B1C3: mov eax, 0xC0000000
	ctx.eax = -1073741824;
	// 0x36B1C8: mov ecx, edi
	ctx.ecx = ctx.edi;
	// 0x36B1CA: and ecx, eax
	ctx.ecx = ctx.ecx & ctx.eax;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36B1CC: cmp ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B1CE: jnz 0x0036B1DB
	if (!ctx.flags.zf) goto loc_36B1DB;
	// 0x36B1D0: mov edx, edi
	ctx.edx = ctx.edi;
	// 0x36B1D2: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B1D4: call 0x0036B05C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B05C(ctx, base);
	ctx.esp += 4;
	// 0x36B1D9: jmp 0x0036B1E1
	goto loc_36B1E1;
loc_36B1DB:
	// 0x36B1DB: push 0x00
	{ auto _pv = (uint32_t)(0); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B1DD: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B1DE: call [esi+0x30]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
loc_36B1E1:
	// 0x36B1E1: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B1E2: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B1E3: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36B1E6(X86Context& ctx, uint8_t* base) {
	// 0x36B1E6: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B1E7: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36B1E9: mov eax, [esi+0x20]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x20u);
	// 0x36B1EC: mov [esi+0xC8], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.eax);
	// 0x36B1F2: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B1F3: lea eax, [esi+0x5F]
	ctx.eax = ctx.esi + 0x5Fu;
	// 0x36B1F6: mov [esi+0xD0], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xD0u, ctx.eax);
	// 0x36B1FC: movzx eax, word ptr [esi+0x34]
	ctx.eax = (uint32_t)(X86_MEM_READ_u16(base, ctx.esi + 0x34u));
	// 0x36B200: push 0xFFFFFFFF
	{ auto _pv = (uint32_t)(-1); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B202: cdq
	ctx.edx = ((int32_t)ctx.eax < 0) ? 0xFFFFFFFF : 0;
	// 0x36B203: push 0xFFFE7960
	{ auto _pv = (uint32_t)(-100000); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B208: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B209: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x36B20F: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B210: mov byte ptr [edi], 0x28
	X86_MEM_WRITE_u8(base, ctx.edi, 40);
	// 0x36B213: mov byte ptr [esi+0xB9], 0x41
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 65);
	// 0x36B21A: mov dword ptr [esi+0xC0], 0x36B162
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, 3584354);
	// 0x36B224: mov [esi+0xC4], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC4u, ctx.esi);
	// 0x36B22A: mov dword ptr [esi+0xCC], 0x0D
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, 13);
	// 0x36B234: mov byte ptr [esi+0xD4], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD4u, 2);
	// 0x36B23B: mov byte ptr [esi+0xD5], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD5u, 0);
	// 0x36B242: mov byte ptr [esi+0xD6], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD6u, 0);
	// 0x36B249: call 0x00244750
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_244750(ctx, base);
	ctx.esp += 4;
	// 0x36B24E: lea ecx, [esi+0x98]
	ctx.ecx = ctx.esi + 0x98u;
	// 0x36B254: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B255: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B256: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B257: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B25A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B25B: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B261: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B264: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36B266: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B267: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36B26C: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B26D: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B26E: ret
	return;
}

void sub_36B26F(X86Context& ctx, uint8_t* base) {
	// 0x36B26F: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B270: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x36B274: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36B277: mov edx, 0x800
	ctx.edx = 2048;
	// 0x36B27C: test edx, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.eax, 32);
	// 0x36B27E: jz 0x0036B2BE
	if (ctx.flags.zf) goto loc_36B2BE;
	// 0x36B280: and eax, 0xFFFFF7FF
	ctx.eax = ctx.eax & -2049;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B285: lea ecx, [esi+0xB8]
	ctx.ecx = ctx.esi + 0xB8u;
	// 0x36B28B: cmp [esp+0x08], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esp + 0x8u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B28F: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B292: jnz 0x0036B29C
	if (!ctx.flags.zf) goto loc_36B29C;
	// 0x36B294: mov ecx, [esi+0xEC]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xECu);
	// 0x36B29A: jmp 0x0036B2A2
	goto loc_36B2A2;
loc_36B29C:
	// 0x36B29C: mov ecx, [esi+0xBC]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0xBCu);
loc_36B2A2:
	// 0x36B2A2: and eax, 0xFFFFF9FF
	ctx.eax = ctx.eax & -1537;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B2A7: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B2A8: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B2AB: call 0x00364E79
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364E79(ctx, base);
	ctx.esp += 4;
	// 0x36B2B0: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x36B2B2: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B2B4: call 0x0036B05C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B05C(ctx, base);
	ctx.esp += 4;
	// 0x36B2B9: jmp 0x0036B368
	goto loc_36B368;
loc_36B2BE:
	// 0x36B2BE: mov ecx, [esp+0x08]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x8u);
	// 0x36B2C2: cmp dword ptr [ecx+0x04], 0x00
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.ecx + 0x4u); uint32_t _s = 0;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B2C6: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B2C7: jl 0x0036B312
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36B312;
	// 0x36B2C9: test al, 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 6, 8);
	// 0x36B2CB: jnz 0x0036B312
	if (!ctx.flags.zf) goto loc_36B312;
	// 0x36B2CD: mov edx, [esi+0x6C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esi + 0x6Cu);
	// 0x36B2D0: cmp edx, [esi+0x2C]
	{ uint32_t _d = ctx.edx; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B2D3: jnb 0x0036B2E1
	if (!ctx.flags.cf) goto loc_36B2E1;
	// 0x36B2D5: mov edx, esi
	ctx.edx = ctx.esi;
	// 0x36B2D7: call 0x0036B36C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B36C(ctx, base);
	ctx.esp += 4;
	// 0x36B2DC: jmp 0x0036B367
	goto loc_36B367;
loc_36B2E1:
	// 0x36B2E1: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x36B2E7: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B2E9: mov edx, 0x200
	ctx.edx = 512;
	// 0x36B2EE: jnz 0x0036B2FA
	if (!ctx.flags.zf) goto loc_36B2FA;
	// 0x36B2F0: and eax, 0xFFFFFDFF
	ctx.eax = ctx.eax & -513;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B2F5: test ah, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 4, 8);
	// 0x36B2F8: jmp 0x0036B301
	goto loc_36B301;
loc_36B2FA:
	// 0x36B2FA: and eax, 0xFFFFFBFF
	ctx.eax = ctx.eax & -1025;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B2FF: test edx, eax
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint32_t) ctx.edx & ctx.eax, 32);
loc_36B301:
	// 0x36B301: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B304: jnz 0x0036B367
	if (!ctx.flags.zf) goto loc_36B367;
	// 0x36B306: or [esi+0x0C], edx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, X86_MEM_READ_u32(base, ctx.esi + 0xCu) | ctx.edx);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u32(base, ctx.esi + 0xCu), 32);
	// 0x36B309: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B30B: call 0x0036B1E6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B1E6(ctx, base);
	ctx.esp += 4;
	// 0x36B310: jmp 0x0036B367
	goto loc_36B367;
loc_36B312:
	// 0x36B312: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x36B318: cmp ecx, edi
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edi;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B31A: jnz 0x0036B341
	if (!ctx.flags.zf) goto loc_36B341;
	// 0x36B31C: and eax, 0xFFFFFDFF
	ctx.eax = ctx.eax & -513;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B321: test ah, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 4, 8);
	// 0x36B324: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B327: jz 0x0036B356
	if (ctx.flags.zf) goto loc_36B356;
	// 0x36B329: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B32B: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B32E: lea eax, [esi+0xE8]
	ctx.eax = ctx.esi + 0xE8u;
	// 0x36B334: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_36B335:
	// 0x36B335: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B338: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36B33A: call 0x00364DD9
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364DD9(ctx, base);
	ctx.esp += 4;
	// 0x36B33F: jmp 0x0036B367
	goto loc_36B367;
loc_36B341:
	// 0x36B341: and eax, 0xFFFFFBFF
	ctx.eax = ctx.eax & -1025;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B346: test ah, 0x02
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 2, 8);
	// 0x36B349: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B34C: jz 0x0036B356
	if (ctx.flags.zf) goto loc_36B356;
	// 0x36B34E: or eax, edx
	ctx.eax = ctx.eax | ctx.edx;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B350: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B353: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B354: jmp 0x0036B335
	goto loc_36B335;
loc_36B356:
	// 0x36B356: push [ecx+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.ecx + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B359: call 0x00364E79
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364E79(ctx, base);
	ctx.esp += 4;
	// 0x36B35E: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x36B360: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B362: call 0x0036B05C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B05C(ctx, base);
	ctx.esp += 4;
loc_36B367:
	// 0x36B367: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
loc_36B368:
	// 0x36B368: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B369: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36B36C(X86Context& ctx, uint8_t* base) {
	// 0x36B36C: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B36D: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x36B36F: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B370: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B371: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B372: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B373: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x36B375: mov al, [edi+0x37]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.edi + 0x37u);
	// 0x36B378: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36B37A: mov cl, al
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.eax);
	// 0x36B37C: and cl, 0x03
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ecx) & 3;
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.ecx), 8);
	// 0x36B37F: cmp cl, 0x01
	{ uint8_t _d = X86_REG8L(ctx.ecx); uint8_t _s = 1;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int8_t)_d, (int8_t)_s, 8); }
	// 0x36B382: jnz 0x0036B38D
	if (!ctx.flags.zf) goto loc_36B38D;
	// 0x36B384: mov ebx, [edi+0x20]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.edi + 0x20u);
	// 0x36B387: mov byte ptr [ebp-0x01], 0x02
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, 2);
	// 0x36B38B: jmp 0x0036B394
	goto loc_36B394;
loc_36B38D:
	// 0x36B38D: mov ebx, [edi+0x24]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.edi + 0x24u);
	// 0x36B390: mov byte ptr [ebp-0x01], 0x01
	X86_MEM_WRITE_u8(base, ctx.ebp - 0x1u, 1);
loc_36B394:
	// 0x36B394: test al, 0x04
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 4, 8);
	// 0x36B396: mov edx, [edi+0x6C]
	ctx.edx = X86_MEM_READ_u32(base, ctx.edi + 0x6Cu);
	// 0x36B399: jz 0x0036B3C3
	if (ctx.flags.zf) goto loc_36B3C3;
	// 0x36B39B: mov ecx, [edi+0x38]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x38u);
	// 0x36B39E: cmp edx, ecx
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B3A0: jnb 0x0036B3AA
	if (!ctx.flags.cf) goto loc_36B3AA;
	// 0x36B3A2: lea eax, [edx+0x41D5DC]
	ctx.eax = ctx.edx + 0x41D5DCu;
	// 0x36B3A8: jmp 0x0036B3C8
	goto loc_36B3C8;
loc_36B3AA:
	// 0x36B3AA: mov eax, [edi+0x3C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x3Cu);
	// 0x36B3AD: cmp edx, eax
	{ uint32_t _d = ctx.edx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B3AF: jnb 0x0036B3B8
	if (!ctx.flags.cf) goto loc_36B3B8;
	// 0x36B3B1: mov eax, [edi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x28u);
	// 0x36B3B4: sub eax, ecx
	{ uint32_t _d = ctx.eax; uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x36B3B6: jmp 0x0036B3C6
	goto loc_36B3C6;
loc_36B3B8:
	// 0x36B3B8: sub ecx, eax
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.eax;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x36B3BA: lea eax, [ecx+edx*1+0x41D5DC]
	ctx.eax = ctx.ecx + ctx.edx + 0x41D5DCu;
	// 0x36B3C1: jmp 0x0036B3C8
	goto loc_36B3C8;
loc_36B3C3:
	// 0x36B3C3: mov eax, [edi+0x28]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x28u);
loc_36B3C6:
	// 0x36B3C6: add eax, edx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(ctx.edx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)ctx.edx, 32);
	  ctx.eax = (uint32_t)_res; }
loc_36B3C8:
	// 0x36B3C8: mov ecx, [edi+0x2C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.edi + 0x2Cu);
	// 0x36B3CB: sub ecx, edx
	{ uint32_t _d = ctx.ecx; uint32_t _s = ctx.edx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.ecx = (uint32_t)_res; }
	// 0x36B3CD: cmp ecx, 0x400
	{ uint32_t _d = ctx.ecx; uint32_t _s = 1024;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B3D3: jbe 0x0036B3DA
	if ((ctx.flags.cf || ctx.flags.zf)) goto loc_36B3DA;
	// 0x36B3D5: mov ecx, 0x400
	ctx.ecx = 1024;
loc_36B3DA:
	// 0x36B3DA: add edx, ecx
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.edx) + (uint64_t)(uint32_t)(ctx.ecx);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.edx, (int32_t)ctx.ecx, 32);
	  ctx.edx = (uint32_t)_res; }
	// 0x36B3DC: mov [edi+0x6C], edx
	X86_MEM_WRITE_u32(base, ctx.edi + 0x6Cu, ctx.edx);
	// 0x36B3DF: mov [esi+0x18], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0x18u, ctx.eax);
	// 0x36B3E2: mov al, [ebp-0x01]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.ebp - 0x1u);
	// 0x36B3E5: lea edx, [edi+0x98]
	ctx.edx = ctx.edi + 0x98u;
	// 0x36B3EB: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B3EC: mov [esi+0x14], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x14u, ctx.ecx);
	// 0x36B3EF: mov [esi+0x1C], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0x1Cu, X86_REG8L(ctx.eax));
	// 0x36B3F2: or ecx, 0xFFFFFFFF
	ctx.ecx = ctx.ecx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36B3F5: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B3F6: mov eax, 0xFFE91CA0
	ctx.eax = -1500000;
	// 0x36B3FB: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B3FC: lea eax, [edi+0x70]
	ctx.eax = ctx.edi + 0x70u;
	// 0x36B3FF: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B400: mov byte ptr [esi], 0x28
	X86_MEM_WRITE_u8(base, ctx.esi, 40);
	// 0x36B403: mov byte ptr [esi+0x01], 0x41
	X86_MEM_WRITE_u8(base, ctx.esi + 0x1u, 65);
	// 0x36B407: mov dword ptr [esi+0x08], 0x36B26F
	X86_MEM_WRITE_u32(base, ctx.esi + 0x8u, 3584623);
	// 0x36B40E: mov [esi+0x0C], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.edi);
	// 0x36B411: mov [esi+0x10], ebx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x10u, ctx.ebx);
	// 0x36B414: mov byte ptr [esi+0x1D], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0x1Du, 0);
	// 0x36B418: mov byte ptr [esi+0x1E], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0x1Eu, 0);
	// 0x36B41C: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B422: mov eax, [edi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.edi + 0x8u);
	// 0x36B425: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36B427: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B428: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36B42D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B42E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B42F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B430: leave
	ctx.esp = ctx.ebp;
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B431: ret
	return;
}

void sub_36B432(X86Context& ctx, uint8_t* base) {
	// 0x36B432: mov eax, [esp+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x4u);
	// 0x36B436: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36B438: cmp [eax+0x04], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.eax + 0x4u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B43B: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B43C: mov esi, [esp+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0xCu);
	// 0x36B440: jl 0x0036B481
	if ((ctx.flags.sf != ctx.flags.of)) goto loc_36B481;
	// 0x36B442: test byte ptr [esi+0x0C], 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 6, 8);
	// 0x36B446: jnz 0x0036B481
	if (!ctx.flags.zf) goto loc_36B481;
	// 0x36B448: cmp [esi+0x28], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.esi + 0x28u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B44B: jz 0x0036B478
	if (ctx.flags.zf) goto loc_36B478;
	// 0x36B44D: mov [esi+0x6C], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0x6Cu, ctx.ecx);
	// 0x36B450: lea ecx, [esi+0xB8]
	ctx.ecx = ctx.esi + 0xB8u;
	// 0x36B456: mov edx, esi
	ctx.edx = ctx.esi;
	// 0x36B458: call 0x0036B36C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B36C(ctx, base);
	ctx.esp += 4;
	// 0x36B45D: mov eax, [esi+0x6C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x6Cu);
	// 0x36B460: cmp eax, [esi+0x2C]
	{ uint32_t _d = ctx.eax; uint32_t _s = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B463: jnb 0x0036B496
	if (!ctx.flags.cf) goto loc_36B496;
	// 0x36B465: or byte ptr [esi+0x0D], 0x04
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) | 4);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B469: lea ecx, [esi+0xE8]
	ctx.ecx = ctx.esi + 0xE8u;
	// 0x36B46F: mov edx, esi
	ctx.edx = ctx.esi;
	// 0x36B471: call 0x0036B36C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B36C(ctx, base);
	ctx.esp += 4;
	// 0x36B476: jmp 0x0036B496
	goto loc_36B496;
loc_36B478:
	// 0x36B478: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B47A: call 0x0036B1E6
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B1E6(ctx, base);
	ctx.esp += 4;
	// 0x36B47F: jmp 0x0036B496
	goto loc_36B496;
loc_36B481:
	// 0x36B481: and byte ptr [esi+0x0D], 0xFD
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B485: push [eax+0x04]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.eax + 0x4u)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B488: call 0x00364E79
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_364E79(ctx, base);
	ctx.esp += 4;
	// 0x36B48D: mov edx, eax
	ctx.edx = ctx.eax;
	// 0x36B48F: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B491: call 0x0036B05C
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B05C(ctx, base);
	ctx.esp += 4;
loc_36B496:
	// 0x36B496: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B497: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36B49A(X86Context& ctx, uint8_t* base) {
	// 0x36B49A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B49B: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36B49D: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B49E: lea edi, [esi+0x40]
	ctx.edi = ctx.esi + 0x40u;
	// 0x36B4A1: mov dword ptr [edi], 0x43425355
	X86_MEM_WRITE_u32(base, ctx.edi, 1128420181);
	// 0x36B4A7: mov eax, [esi+0x10]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x10u);
	// 0x36B4AA: mov [edi+0x04], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x4u, ctx.eax);
	// 0x36B4AD: mov eax, [esi+0x2C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x2Cu);
	// 0x36B4B0: mov [edi+0x08], eax
	X86_MEM_WRITE_u32(base, ctx.edi + 0x8u, ctx.eax);
	// 0x36B4B3: mov al, [esi+0x37]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x37u);
	// 0x36B4B6: shl al, 0x07
	{ auto _cnt = 0x7u & 0x1F; if (_cnt) {
	  ctx.flags.cf = (X86_REG8L(ctx.eax) >> (8 - _cnt)) & 1;
	  X86_REG8L(ctx.eax) = X86_REG8L(ctx.eax) << _cnt;
	  X86_UPDATE_FLAGS_LOGIC(ctx, X86_REG8L(ctx.eax), 8); } }
	// 0x36B4B9: lea edx, [esi+0x98]
	ctx.edx = ctx.esi + 0x98u;
	// 0x36B4BF: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B4C0: mov [edi+0x0C], al
	X86_MEM_WRITE_u8(base, ctx.edi + 0xCu, X86_REG8L(ctx.eax));
	// 0x36B4C3: or ecx, 0xFFFFFFFF
	ctx.ecx = ctx.ecx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36B4C6: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B4C7: mov eax, 0xFFF3CB00
	ctx.eax = -800000;
	// 0x36B4CC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B4CD: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B4D0: mov byte ptr [edi+0x0D], 0x00
	X86_MEM_WRITE_u8(base, ctx.edi + 0xDu, 0);
	// 0x36B4D4: mov byte ptr [edi+0x0E], 0x0A
	X86_MEM_WRITE_u8(base, ctx.edi + 0xEu, 10);
	// 0x36B4D8: or byte ptr [esi+0x0D], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) | 1);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B4DC: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B4DD: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B4E3: mov ecx, [esi+0x24]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x36B4E6: or byte ptr [esi+0x0D], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B4EA: lea eax, [esi+0xB8]
	ctx.eax = ctx.esi + 0xB8u;
	// 0x36B4F0: mov byte ptr [eax], 0x28
	X86_MEM_WRITE_u8(base, ctx.eax, 40);
	// 0x36B4F3: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B4F4: mov eax, [esi+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B4F7: mov byte ptr [esi+0xB9], 0x41
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 65);
	// 0x36B4FE: mov dword ptr [esi+0xC0], 0x36B432
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, 3585074);
	// 0x36B508: mov [esi+0xC4], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC4u, ctx.esi);
	// 0x36B50E: mov [esi+0xC8], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.ecx);
	// 0x36B514: mov [esi+0xD0], edi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xD0u, ctx.edi);
	// 0x36B51A: mov dword ptr [esi+0xCC], 0x1F
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, 31);
	// 0x36B524: mov byte ptr [esi+0xD4], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD4u, 1);
	// 0x36B52B: mov byte ptr [esi+0xD5], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD5u, 0);
	// 0x36B532: mov byte ptr [esi+0xD6], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD6u, 0);
	// 0x36B539: mov ecx, [eax]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax);
	// 0x36B53B: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36B540: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B541: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B542: ret
	return;
}

void sub_36B543(X86Context& ctx, uint8_t* base) {
	// 0x36B543: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B544: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B545: mov esi, [esp+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x36B549: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36B54C: mov ebx, [esi+0x08]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esi + 0x8u);
	// 0x36B54F: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B550: mov edi, eax
	ctx.edi = ctx.eax;
	// 0x36B552: and eax, 0xFFFFFDFF
	ctx.eax = ctx.eax & -513;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B557: and edi, 0x7000
	ctx.edi = ctx.edi & 28672;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.edi, 32);
	// 0x36B55D: test ah, 0x01
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8H(ctx.eax) & 1, 8);
	// 0x36B560: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B563: jz 0x0036B573
	if (ctx.flags.zf) goto loc_36B573;
	// 0x36B565: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B568: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B569: call [0x0036B8E4]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E4u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B56F: and byte ptr [esi+0x0D], 0xFE
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) & -2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
loc_36B573:
	// 0x36B573: mov eax, [esi+0x0C]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0xCu);
	// 0x36B576: test al, 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & 6, 8);
	// 0x36B578: jz 0x0036B581
	if (ctx.flags.zf) goto loc_36B581;
loc_36B57A:
	// 0x36B57A: push 0xC000009D
	{ auto _pv = (uint32_t)(-1073741667); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B57F: jmp 0x0036B5E2
	goto loc_36B5E2;
loc_36B581:
	// 0x36B581: mov edx, [esp+0x10]
	ctx.edx = X86_MEM_READ_u32(base, ctx.esp + 0x10u);
	// 0x36B585: xor ecx, ecx
	ctx.ecx = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36B587: cmp [edx+0x04], ecx
	{ uint32_t _d = X86_MEM_READ_u32(base, ctx.edx + 0x4u); uint32_t _s = ctx.ecx;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B58A: jnl 0x0036B59D
	if ((ctx.flags.sf == ctx.flags.of)) goto loc_36B59D;
	// 0x36B58C: and eax, 0xFFFF8FFF
	ctx.eax = ctx.eax & -28673;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B591: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B594: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x36B596: call 0x00365968
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_365968(ctx, base);
	ctx.esp += 4;
	// 0x36B59B: jmp 0x0036B57A
	goto loc_36B57A;
loc_36B59D:
	// 0x36B59D: cmp edi, 0x1000
	{ uint32_t _d = ctx.edi; uint32_t _s = 4096;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B5A3: jz 0x0036B66C
	if (ctx.flags.zf) goto loc_36B66C;
	// 0x36B5A9: cmp edi, 0x2000
	{ uint32_t _d = ctx.edi; uint32_t _s = 8192;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B5AF: jz 0x0036B5EB
	if (ctx.flags.zf) goto loc_36B5EB;
	// 0x36B5B1: cmp edi, 0x4000
	{ uint32_t _d = ctx.edi; uint32_t _s = 16384;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32); }
	// 0x36B5B7: jnz 0x0036B73D
	if (!ctx.flags.zf) goto loc_36B73D;
	// 0x36B5BD: and eax, 0xFFFFBFFF
	ctx.eax = ctx.eax & -16385;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B5C2: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B5C5: mov al, [esi+0x36]
	X86_REG8L(ctx.eax) = X86_MEM_READ_u8(base, ctx.esi + 0x36u);
	// 0x36B5C8: mov cl, al
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.eax);
	// 0x36B5CA: dec cl
	{ uint8_t _d = X86_REG8L(ctx.ecx);
	  uint64_t _res = (uint64_t)_d - 1;
	  X86_UPDATE_FLAGS_DEC(ctx, _res, (int8_t)_d, 8);
	  X86_REG8L(ctx.ecx) = (uint8_t)_res; }
	// 0x36B5CC: test al, al
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_REG8L(ctx.eax) & X86_REG8L(ctx.eax), 8);
	// 0x36B5CE: mov [esi+0x36], cl
	X86_MEM_WRITE_u8(base, ctx.esi + 0x36u, X86_REG8L(ctx.ecx));
	// 0x36B5D1: jz 0x0036B5DF
	if (ctx.flags.zf) goto loc_36B5DF;
	// 0x36B5D3: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B5D5: call 0x0036B49A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B49A(ctx, base);
	ctx.esp += 4;
	// 0x36B5DA: jmp 0x0036B73D
	goto loc_36B73D;
loc_36B5DF:
	// 0x36B5DF: push [esi+0x6C]
	{ auto _pv = (uint32_t)(X86_MEM_READ_u32(base, ctx.esi + 0x6Cu)); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
loc_36B5E2:
	// 0x36B5E2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B5E3: call [esi+0x30]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B5E6: jmp 0x0036B73D
	goto loc_36B73D;
loc_36B5EB:
	// 0x36B5EB: and eax, 0xFFFFDFFF
	ctx.eax = ctx.eax & -8193;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B5F0: or eax, 0x4000
	ctx.eax = ctx.eax | 16384;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B5F5: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x36B5FB: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B5FE: mov byte ptr [edi], 0x30
	X86_MEM_WRITE_u8(base, ctx.edi, 48);
	// 0x36B601: mov byte ptr [esi+0xB9], 0x40
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 64);
	// 0x36B608: mov dword ptr [esi+0xC0], 0x36B543
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, 3585347);
	// 0x36B612: mov [esi+0xC4], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC4u, ctx.esi);
	// 0x36B618: mov [esi+0xC8], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.ecx);
	// 0x36B61E: mov [esi+0xD0], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xD0u, ctx.ecx);
	// 0x36B624: mov [esi+0xCC], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, ctx.ecx);
	// 0x36B62A: mov byte ptr [esi+0xD4], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD4u, 1);
	// 0x36B631: mov byte ptr [esi+0xD5], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD5u, 0);
	// 0x36B638: mov byte ptr [esi+0xD6], 0x00
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD6u, 0);
	// 0x36B63F: mov byte ptr [esi+0xE0], 0x21
	X86_MEM_WRITE_u8(base, ctx.esi + 0xE0u, 33);
	// 0x36B646: mov byte ptr [esi+0xE1], 0xFF
	X86_MEM_WRITE_u8(base, ctx.esi + 0xE1u, -1);
	// 0x36B64D: mov [esi+0xE2], cx
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE2u, X86_REG16(ctx.ecx));
	// 0x36B654: movzx ax, byte ptr [ebx+0x04]
	X86_REG16(ctx.eax) = (uint16_t)(X86_MEM_READ_u8(base, ctx.ebx + 0x4u));
	// 0x36B659: mov [esi+0xE4], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE4u, X86_REG16(ctx.eax));
	// 0x36B660: mov [esi+0xE6], cx
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE6u, X86_REG16(ctx.ecx));
	// 0x36B667: jmp 0x0036B712
	goto loc_36B712;
loc_36B66C:
	// 0x36B66C: and eax, 0xFFFFEFFF
	ctx.eax = ctx.eax & -4097;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B671: or eax, 0x2000
	ctx.eax = ctx.eax | 8192;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.eax, 32);
	// 0x36B676: mov [esi+0x0C], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCu, ctx.eax);
	// 0x36B679: mov eax, [esi+0x24]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esi + 0x24u);
	// 0x36B67C: lea edi, [esi+0xB8]
	ctx.edi = ctx.esi + 0xB8u;
	// 0x36B682: mov byte ptr [edi], 0x18
	X86_MEM_WRITE_u8(base, ctx.edi, 24);
	// 0x36B685: mov byte ptr [esi+0xB9], 0x05
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 5);
	// 0x36B68C: mov [esi+0xC0], ecx
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, ctx.ecx);
	// 0x36B692: mov [esi+0xC8], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.eax);
	// 0x36B698: mov dword ptr [esi+0xCC], 0x04
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, 4);
	// 0x36B6A2: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x36B6A4: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B6A5: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
	// 0x36B6AA: xor eax, eax
	ctx.eax = 0;
	X86_UPDATE_FLAGS_LOGIC(ctx, 0, 32);
	// 0x36B6AC: mov byte ptr [edi], 0x30
	X86_MEM_WRITE_u8(base, ctx.edi, 48);
	// 0x36B6AF: mov byte ptr [esi+0xB9], 0x40
	X86_MEM_WRITE_u8(base, ctx.esi + 0xB9u, 64);
	// 0x36B6B6: mov dword ptr [esi+0xC0], 0x36B543
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC0u, 3585347);
	// 0x36B6C0: mov [esi+0xC4], esi
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC4u, ctx.esi);
	// 0x36B6C6: mov [esi+0xC8], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xC8u, ctx.eax);
	// 0x36B6CC: mov [esi+0xD0], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xD0u, ctx.eax);
	// 0x36B6D2: mov [esi+0xCC], eax
	X86_MEM_WRITE_u32(base, ctx.esi + 0xCCu, ctx.eax);
	// 0x36B6D8: mov [esi+0xD4], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD4u, X86_REG8L(ctx.eax));
	// 0x36B6DE: mov [esi+0xD5], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD5u, X86_REG8L(ctx.eax));
	// 0x36B6E4: mov [esi+0xD6], al
	X86_MEM_WRITE_u8(base, ctx.esi + 0xD6u, X86_REG8L(ctx.eax));
	// 0x36B6EA: mov byte ptr [esi+0xE0], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xE0u, 2);
	// 0x36B6F1: mov byte ptr [esi+0xE1], 0x01
	X86_MEM_WRITE_u8(base, ctx.esi + 0xE1u, 1);
	// 0x36B6F8: mov [esi+0xE2], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE2u, X86_REG16(ctx.eax));
	// 0x36B6FF: movzx cx, byte ptr [ebx+0x06]
	X86_REG16(ctx.ecx) = (uint16_t)(X86_MEM_READ_u8(base, ctx.ebx + 0x6u));
	// 0x36B704: mov [esi+0xE4], cx
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE4u, X86_REG16(ctx.ecx));
	// 0x36B70B: mov [esi+0xE6], ax
	X86_MEM_WRITE_u16(base, ctx.esi + 0xE6u, X86_REG16(ctx.eax));
loc_36B712:
	// 0x36B712: or byte ptr [esi+0x0D], 0x03
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) | 3);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B716: lea edx, [esi+0x98]
	ctx.edx = ctx.esi + 0x98u;
	// 0x36B71C: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B71D: or ecx, 0xFFFFFFFF
	ctx.ecx = ctx.ecx | -1;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.ecx, 32);
	// 0x36B720: push ecx
	{ auto _pv = (uint32_t)(ctx.ecx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B721: mov eax, 0xFFF0BDC0
	ctx.eax = -1000000;
	// 0x36B726: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B727: lea eax, [esi+0x70]
	ctx.eax = ctx.esi + 0x70u;
	// 0x36B72A: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B72B: call [0x0036B8E0]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8E0u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B731: or byte ptr [esi+0x0D], 0x02
	X86_MEM_WRITE_u8(base, ctx.esi + 0xDu, X86_MEM_READ_u8(base, ctx.esi + 0xDu) | 2);
	X86_UPDATE_FLAGS_LOGIC(ctx, X86_MEM_READ_u8(base, ctx.esi + 0xDu), 8);
	// 0x36B735: mov ecx, [ebx]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx);
	// 0x36B737: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B738: call 0x003651A1
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_3651A1(ctx, base);
	ctx.esp += 4;
loc_36B73D:
	// 0x36B73D: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B73E: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B73F: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B740: ret 0x08
	ctx.esp += 8;
	return;
}

void sub_36B743(X86Context& ctx, uint8_t* base) {
	// 0x36B743: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B744: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B745: mov esi, ecx
	ctx.esi = ctx.ecx;
	// 0x36B747: call [0x0036B8B8]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, 0x36B8B8u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B74D: test byte ptr [esi+0x0C], 0x06
	X86_UPDATE_FLAGS_LOGIC(ctx, (uint8_t) X86_MEM_READ_u8(base, ctx.esi + 0xCu) & 6, 8);
	// 0x36B751: mov bl, al
	X86_REG8L(ctx.ebx) = X86_REG8L(ctx.eax);
	// 0x36B753: jz 0x0036B760
	if (ctx.flags.zf) goto loc_36B760;
	// 0x36B755: push 0xC000009D
	{ auto _pv = (uint32_t)(-1073741667); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B75A: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x36B75B: call [esi+0x30]
	{ uint32_t _tgt = X86_MEM_READ_u32(base, ctx.esi + 0x30u);
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	X86_CALL_INDIRECT(ctx, base, _tgt); }
	ctx.esp += 4;
	// 0x36B75E: jmp 0x0036B767
	goto loc_36B767;
loc_36B760:
	// 0x36B760: mov ecx, esi
	ctx.ecx = ctx.esi;
	// 0x36B762: call 0x0036B49A
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_36B49A(ctx, base);
	ctx.esp += 4;
loc_36B767:
	// 0x36B767: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B768: mov cl, bl
	X86_REG8L(ctx.ecx) = X86_REG8L(ctx.ebx);
	// 0x36B76A: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x36B76B: jmp [0x0036B8B4]
	X86_JMP_INDIRECT(ctx, base, X86_MEM_READ_u32(base, 0x36B8B4u));
	return;
}

